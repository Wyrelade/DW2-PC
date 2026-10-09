#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <SDL3/SDL.h>

#include "backend/psxgpu.h"
#include "backend/psxgpu_hd_int.h"
#include "backend/psxgpu_hw_spv.h"

/* GPU renderer for the HD surfaces (PG.10b), the DuckStation GPU_HW model on SDL_GPU (Vulkan,
 * SPIR-V from backend/shaders/). The queue of backend/psxgpu_hd.c is turned into triangles: each
 * surface is an RGBA8 render texture ((w + 2m) S x h S, alpha = mask bit), the fragment shader
 * shades every surface pixel by the PS1 rules with texels and CLUTs read from a copy of the 1x
 * VRAM (a storage buffer; rows changed since the last batch are uploaded first). Semi-
 * transparency by blend states: abr 0 constant 0.5 + 0.5, 1 add, 2 reverse subtract, 3 add (the
 * shader quarters the colour); a textured semi-transparent primitive is drawn twice (opaque texels
 * without blending, then semi-transparent texels blended), so each pixel is written once as on
 * the PS1. Positions: a surface pixel X samples coordinate X (as in the software HD rasterizer),
 * so vertices go to (p - origin) * S + 0.5 in framebuffer pixels. */

typedef struct {
    float x, y, w;
    float u, v;
    uint8_t r, g, b, a;
    uint32_t par[4];
} Vert;

typedef struct {
    PsxHdSurf *s;
    int pipe; /* 0 opaque, 1 + abr blended */
    SDL_Rect scissor;
    Uint32 first, count;
} Draw;

#define VRAM_BYTES (PSXGPU_VRAM_W * PSXGPU_VRAM_H * 2)
#define ROW_BYTES (PSXGPU_VRAM_W * 2)

enum { F_DITHER = 1, F_BLOCK = 2, F_CLAMP = 0x200, F_SETMASK = 0x100 };
#define F_PASS(p) ((uint32_t)(p) << 2)
#define F_ABR(a) ((uint32_t)(a) << 4)
#define F_KIND(k) ((uint32_t)(k) << 6)

static SDL_GPUDevice *dev;
static SDL_GPUGraphicsPipeline *pipes[5];
static SDL_GPUBuffer *vram_buf;
static SDL_GPUTransferBuffer *vram_tb;
static SDL_GPUBuffer *vbuf;
static SDL_GPUTransferBuffer *vtb;
static Uint32 vcap; /* bytes of vbuf / vtb */
static SDL_GPUTransferBuffer *read_tb;
static Uint32 read_cap;
static SDL_GPUFence *last_fence;
static SDL_GPUGraphicsPipeline *sharpen_pipe; /* PR.2b */
static SDL_GPUSampler *sharpen_sampler;
static int dirty_y0, dirty_y1 = PSXGPU_VRAM_H; /* VRAM rows to upload before the next batch */

static Vert *verts;
static int nverts, verts_cap;
static Draw *draws;
static int ndraws, draws_cap;

static SDL_GPUShader *make_shader(const uint32_t *code, size_t size, SDL_GPUShaderStage stage, int storage) {
    SDL_GPUShaderCreateInfo si;

    SDL_zero(si);
    si.code = (const Uint8 *)code;
    si.code_size = size;
    si.entrypoint = "main";
    si.format = SDL_GPU_SHADERFORMAT_SPIRV;
    si.stage = stage;
    si.num_storage_buffers = (Uint32)storage;
    si.num_uniform_buffers = 1;
    return SDL_CreateGPUShader(dev, &si);
}

/* PR.2b: the sharpen pipeline (full-screen triangle, the source texture through a sampler). */
static int init_sharpen(void) {
    SDL_GPUShaderCreateInfo si;
    SDL_GPUShader *vs, *fs;
    SDL_GPUColorTargetDescription ctd;
    SDL_GPUGraphicsPipelineCreateInfo pi;
    SDL_GPUSamplerCreateInfo smp;

    SDL_zero(si);
    si.code = (const Uint8 *)spv_sharpen_vert;
    si.code_size = sizeof(spv_sharpen_vert);
    si.entrypoint = "main";
    si.format = SDL_GPU_SHADERFORMAT_SPIRV;
    si.stage = SDL_GPU_SHADERSTAGE_VERTEX;
    vs = SDL_CreateGPUShader(dev, &si);
    si.code = (const Uint8 *)spv_sharpen_frag;
    si.code_size = sizeof(spv_sharpen_frag);
    si.stage = SDL_GPU_SHADERSTAGE_FRAGMENT;
    si.num_samplers = 1;
    si.num_uniform_buffers = 1;
    fs = SDL_CreateGPUShader(dev, &si);
    if (vs == NULL || fs == NULL) {
        printf("[gpu] GPU renderer: sharpen shaders failed: %s\n", SDL_GetError());
        return 0;
    }
    SDL_zero(ctd);
    ctd.format = SDL_GPU_TEXTUREFORMAT_R8G8B8A8_UNORM;
    SDL_zero(pi);
    pi.vertex_shader = vs;
    pi.fragment_shader = fs;
    pi.primitive_type = SDL_GPU_PRIMITIVETYPE_TRIANGLELIST;
    pi.rasterizer_state.fill_mode = SDL_GPU_FILLMODE_FILL;
    pi.rasterizer_state.cull_mode = SDL_GPU_CULLMODE_NONE;
    pi.target_info.color_target_descriptions = &ctd;
    pi.target_info.num_color_targets = 1;
    sharpen_pipe = SDL_CreateGPUGraphicsPipeline(dev, &pi);
    SDL_ReleaseGPUShader(dev, vs);
    SDL_ReleaseGPUShader(dev, fs);
    SDL_zero(smp);
    smp.min_filter = SDL_GPU_FILTER_NEAREST;
    smp.mag_filter = SDL_GPU_FILTER_NEAREST;
    smp.mipmap_mode = SDL_GPU_SAMPLERMIPMAPMODE_NEAREST;
    smp.address_mode_u = SDL_GPU_SAMPLERADDRESSMODE_CLAMP_TO_EDGE;
    smp.address_mode_v = SDL_GPU_SAMPLERADDRESSMODE_CLAMP_TO_EDGE;
    smp.address_mode_w = SDL_GPU_SAMPLERADDRESSMODE_CLAMP_TO_EDGE;
    sharpen_sampler = SDL_CreateGPUSampler(dev, &smp);
    if (sharpen_pipe == NULL || sharpen_sampler == NULL) {
        printf("[gpu] GPU renderer: sharpen pipeline failed: %s\n", SDL_GetError());
        return 0;
    }
    return 1;
}

int PsxHw_Init(void *device) {
    SDL_GPUShader *vs, *fs;
    SDL_GPUVertexBufferDescription vbd;
    SDL_GPUVertexAttribute va[4];
    SDL_GPUColorTargetDescription ctd;
    SDL_GPUGraphicsPipelineCreateInfo pi;
    SDL_GPUBufferCreateInfo bi;
    SDL_GPUTransferBufferCreateInfo ti;
    int i;

    dev = device;
    vs = make_shader(spv_hd_vert, sizeof(spv_hd_vert), SDL_GPU_SHADERSTAGE_VERTEX, 0);
    fs = make_shader(spv_hd_frag, sizeof(spv_hd_frag), SDL_GPU_SHADERSTAGE_FRAGMENT, 1);
    if (vs == NULL || fs == NULL) {
        printf("[gpu] GPU renderer: shaders failed: %s\n", SDL_GetError());
        dev = NULL;
        return 0;
    }
    SDL_zero(vbd);
    vbd.slot = 0;
    vbd.pitch = sizeof(Vert);
    vbd.input_rate = SDL_GPU_VERTEXINPUTRATE_VERTEX;
    SDL_zeroa(va);
    va[0].location = 0;
    va[0].format = SDL_GPU_VERTEXELEMENTFORMAT_FLOAT3;
    va[0].offset = 0;
    va[1].location = 1;
    va[1].format = SDL_GPU_VERTEXELEMENTFORMAT_FLOAT2;
    va[1].offset = 12;
    va[2].location = 2;
    va[2].format = SDL_GPU_VERTEXELEMENTFORMAT_UBYTE4_NORM;
    va[2].offset = 20;
    va[3].location = 3;
    va[3].format = SDL_GPU_VERTEXELEMENTFORMAT_UINT4;
    va[3].offset = 24;
    for (i = 0; i < 5; i++) {
        SDL_GPUColorTargetBlendState *b = &ctd.blend_state;

        SDL_zero(ctd);
        ctd.format = SDL_GPU_TEXTUREFORMAT_R8G8B8A8_UNORM;
        if (i > 0) {
            b->enable_blend = true;
            b->src_color_blendfactor = i == 1 ? SDL_GPU_BLENDFACTOR_CONSTANT_COLOR : SDL_GPU_BLENDFACTOR_ONE;
            b->dst_color_blendfactor = i == 1 ? SDL_GPU_BLENDFACTOR_CONSTANT_COLOR : SDL_GPU_BLENDFACTOR_ONE;
            b->color_blend_op = i == 3 ? SDL_GPU_BLENDOP_REVERSE_SUBTRACT : SDL_GPU_BLENDOP_ADD;
            b->src_alpha_blendfactor = SDL_GPU_BLENDFACTOR_ONE;
            b->dst_alpha_blendfactor = SDL_GPU_BLENDFACTOR_ZERO;
            b->alpha_blend_op = SDL_GPU_BLENDOP_ADD;
        }
        SDL_zero(pi);
        pi.vertex_shader = vs;
        pi.fragment_shader = fs;
        pi.vertex_input_state.vertex_buffer_descriptions = &vbd;
        pi.vertex_input_state.num_vertex_buffers = 1;
        pi.vertex_input_state.vertex_attributes = va;
        pi.vertex_input_state.num_vertex_attributes = 4;
        pi.primitive_type = SDL_GPU_PRIMITIVETYPE_TRIANGLELIST;
        pi.rasterizer_state.fill_mode = SDL_GPU_FILLMODE_FILL;
        pi.rasterizer_state.cull_mode = SDL_GPU_CULLMODE_NONE;
        pi.rasterizer_state.front_face = SDL_GPU_FRONTFACE_COUNTER_CLOCKWISE;
        pi.target_info.color_target_descriptions = &ctd;
        pi.target_info.num_color_targets = 1;
        pipes[i] = SDL_CreateGPUGraphicsPipeline(dev, &pi);
        if (pipes[i] == NULL) {
            printf("[gpu] GPU renderer: pipeline failed: %s\n", SDL_GetError());
            dev = NULL;
            return 0;
        }
    }
    SDL_ReleaseGPUShader(device, vs);
    SDL_ReleaseGPUShader(device, fs);
    SDL_zero(bi);
    bi.usage = SDL_GPU_BUFFERUSAGE_GRAPHICS_STORAGE_READ;
    bi.size = VRAM_BYTES;
    vram_buf = SDL_CreateGPUBuffer(dev, &bi);
    SDL_zero(ti);
    ti.usage = SDL_GPU_TRANSFERBUFFERUSAGE_UPLOAD;
    ti.size = VRAM_BYTES;
    vram_tb = SDL_CreateGPUTransferBuffer(dev, &ti);
    if (vram_buf == NULL || vram_tb == NULL) {
        printf("[gpu] GPU renderer: VRAM buffer failed: %s\n", SDL_GetError());
        dev = NULL;
        return 0;
    }
    if (!init_sharpen()) {
        dev = NULL;
        return 0;
    }
    dirty_y0 = 0;
    dirty_y1 = PSXGPU_VRAM_H;
    printf("[gpu] GPU renderer: SDL_GPU %s\n", SDL_GetGPUDeviceDriver(dev));
    return 1;
}

void PsxHw_Shutdown(void) {
    int i;

    if (dev == NULL) {
        return;
    }
    if (last_fence != NULL) {
        SDL_WaitForGPUFences(dev, true, &last_fence, 1);
        SDL_ReleaseGPUFence(dev, last_fence);
        last_fence = NULL;
    }
    for (i = 0; i < 5; i++) {
        SDL_ReleaseGPUGraphicsPipeline(dev, pipes[i]);
    }
    SDL_ReleaseGPUGraphicsPipeline(dev, sharpen_pipe);
    SDL_ReleaseGPUSampler(dev, sharpen_sampler);
    sharpen_pipe = NULL;
    sharpen_sampler = NULL;
    SDL_ReleaseGPUBuffer(dev, vram_buf);
    SDL_ReleaseGPUTransferBuffer(dev, vram_tb);
    if (vbuf != NULL) {
        SDL_ReleaseGPUBuffer(dev, vbuf);
        SDL_ReleaseGPUTransferBuffer(dev, vtb);
    }
    if (read_tb != NULL) {
        SDL_ReleaseGPUTransferBuffer(dev, read_tb);
    }
    vbuf = NULL;
    vtb = NULL;
    vcap = 0;
    read_tb = NULL;
    read_cap = 0;
    dev = NULL;
}

int PsxHw_Active(void) {
    return dev != NULL;
}

void *PsxHw_Create(int w, int h) {
    SDL_GPUTextureCreateInfo tci;

    if (dev == NULL) {
        return NULL;
    }
    SDL_zero(tci);
    tci.type = SDL_GPU_TEXTURETYPE_2D;
    tci.format = SDL_GPU_TEXTUREFORMAT_R8G8B8A8_UNORM;
    tci.usage = SDL_GPU_TEXTUREUSAGE_COLOR_TARGET | SDL_GPU_TEXTUREUSAGE_SAMPLER;
    tci.width = (Uint32)w;
    tci.height = (Uint32)h;
    tci.layer_count_or_depth = 1;
    tci.num_levels = 1;
    return SDL_CreateGPUTexture(dev, &tci);
}

void PsxHw_Release(void *tex) {
    if (dev != NULL) {
        SDL_ReleaseGPUTexture(dev, tex);
    }
}

void PsxHw_MarkDirty(int y, int h) {
    int y1 = y + h;

    if (h <= 0) {
        return;
    }
    if (y < 0 || y1 > PSXGPU_VRAM_H) {
        y = 0;
        y1 = PSXGPU_VRAM_H;
    }
    if (dirty_y0 >= dirty_y1) {
        dirty_y0 = y;
        dirty_y1 = y1;
    } else {
        dirty_y0 = y < dirty_y0 ? y : dirty_y0;
        dirty_y1 = y1 > dirty_y1 ? y1 : dirty_y1;
    }
}

/* ---- queue to triangles ---- */

static void emit(PsxHdSurf *s, int pipe, const SDL_Rect *sc, const Vert *v, int n) {
    Draw *d = ndraws > 0 ? &draws[ndraws - 1] : NULL;

    if (nverts + n > verts_cap) {
        int cap = verts_cap ? verts_cap * 2 : 1 << 16;
        Vert *nv;
        while (cap < nverts + n) {
            cap *= 2;
        }
        nv = realloc(verts, (size_t)cap * sizeof(Vert));
        if (nv == NULL) {
            return;
        }
        verts = nv;
        verts_cap = cap;
    }
    if (d == NULL || d->s != s || d->pipe != pipe || d->scissor.x != sc->x || d->scissor.y != sc->y ||
        d->scissor.w != sc->w || d->scissor.h != sc->h) {
        if (ndraws == draws_cap) {
            int cap = draws_cap ? draws_cap * 2 : 1024;
            Draw *nd = realloc(draws, (size_t)cap * sizeof(Draw));
            if (nd == NULL) {
                return;
            }
            draws = nd;
            draws_cap = cap;
        }
        d = &draws[ndraws++];
        d->s = s;
        d->pipe = pipe;
        d->scissor = *sc;
        d->first = (Uint32)nverts;
        d->count = 0;
    }
    memcpy(&verts[nverts], v, (size_t)n * sizeof(Vert));
    nverts += n;
    d->count += (Uint32)n;
}

/* Emits n vertices once, or twice for a textured semi-transparent primitive (opaque texels, then
 * semi-transparent texels blended). */
static void emit_prim(const PsxHdCmd *c, Vert *v, int n, int textured) {
    SDL_Rect sc;
    int x0, y0, x1, y1, i;

    PsxHd_CmdClip(c, &x0, &y0, &x1, &y1);
    if (x0 > x1 || y0 > y1) {
        return;
    }
    sc.x = x0;
    sc.y = y0;
    sc.w = x1 - x0 + 1;
    sc.h = y1 - y0 + 1;
    if (!c->semi) {
        emit(c->s, 0, &sc, v, n);
        return;
    }
    if (textured) {
        for (i = 0; i < n; i++) {
            v[i].par[2] |= F_PASS(1);
        }
        emit(c->s, 0, &sc, v, n);
        for (i = 0; i < n; i++) {
            v[i].par[2] ^= F_PASS(1) ^ F_PASS(2);
        }
    } else {
        for (i = 0; i < n; i++) {
            v[i].par[2] |= F_PASS(2);
        }
    }
    emit(c->s, 1 + c->abr, &sc, v, n);
}

static uint32_t tex_bits(const PsxTex *t) {
    return (uint32_t)t->mode | (t->raw ? 4u : 0u) | 8u | (uint32_t)(t->tx / 64) << 4 | (uint32_t)(t->ty / 256) << 8 |
           (uint32_t)(t->cx / 16) << 9 | (uint32_t)t->cy << 15;
}

static uint32_t win_bits(const PsxGpuState *st) {
    return (uint32_t)(st->tw_mask_x / 8) | (uint32_t)(st->tw_mask_y / 8) << 5 | (uint32_t)(st->tw_off_x / 8) << 10 |
           (uint32_t)(st->tw_off_y / 8) << 15;
}

static void set_par(Vert *v, int n, uint32_t tex, uint32_t win, uint32_t fl, uint32_t lim) {
    int i;

    for (i = 0; i < n; i++) {
        v[i].par[0] = tex;
        v[i].par[1] = win;
        v[i].par[2] = fl;
        v[i].par[3] = lim;
    }
}

static void tri(const PsxHdCmd *c, int scale) {
    const PsxGpuState *st = &c->st;
    const PsxTex *t = c->textured ? &c->tex : NULL;
    PsxHdSurf *s = c->s;
    float ox = (float)(s->x - s->m), oy = (float)s->y, S = (float)scale;
    const PsxVtx *p = c->v;
    int persp = t != NULL && c->precise && p[0].pz > 0 && p[1].pz > 0 && p[2].pz > 0;
    int block = 0;
    uint32_t fl = 0, lim = 0;
    Vert v[3];
    int i;

    if (t != NULL && !c->precise) {
        /* no cross terms in the mapping (du / dy = dv / dx = 0): sprite-like, read at the 1x pixel */
        int64_t dudy = (int64_t)p[0].u * (p[2].x - p[1].x) + (int64_t)p[1].u * (p[0].x - p[2].x) +
                       (int64_t)p[2].u * (p[1].x - p[0].x);
        int64_t dvdx = (int64_t)p[0].v * (p[2].y - p[1].y) + (int64_t)p[1].v * (p[0].y - p[2].y) +
                       (int64_t)p[2].v * (p[1].y - p[0].y);
        block = dudy == 0 && dvdx == 0;
    }
    if (st->dither && (c->gouraud || (t != NULL && !t->raw))) {
        fl |= F_DITHER;
    }
    if (block) {
        int umin = p[0].u < p[1].u ? p[0].u : p[1].u, umax = p[0].u > p[1].u ? p[0].u : p[1].u;
        umin = p[2].u < umin ? p[2].u : umin;
        umax = p[2].u > umax ? p[2].u : umax;
        fl |= F_BLOCK | F_CLAMP;
        lim = (uint32_t)umin | (uint32_t)umax << 8;
    }
    if (st->set_mask) {
        fl |= F_SETMASK;
    }
    for (i = 0; i < 3; i++) {
        const PsxVtx *q = c->gouraud ? &p[i] : &p[0];
        if (c->precise) {
            v[i].x = (p[i].px - ox) * S + 0.5f;
            v[i].y = (p[i].py - oy) * S + 0.5f;
        } else {
            v[i].x = ((float)p[i].x - ox) * S + 0.5f;
            v[i].y = ((float)p[i].y - oy) * S + 0.5f;
        }
        v[i].w = persp ? p[i].pz : 1.0f;
        v[i].u = (float)p[i].u;
        v[i].v = (float)p[i].v;
        v[i].r = (uint8_t)q->r;
        v[i].g = (uint8_t)q->g;
        v[i].b = (uint8_t)q->b;
        v[i].a = 0;
    }
    set_par(v, 3, t != NULL ? tex_bits(t) : 0, win_bits(st), fl, lim);
    emit_prim(c, v, 3, t != NULL);
}

/* Two triangles of the quad a b c d (a b on one side, c d on the other). */
static void quad(Vert *o, const Vert *a, const Vert *b, const Vert *c, const Vert *d) {
    o[0] = *a;
    o[1] = *b;
    o[2] = *c;
    o[3] = *b;
    o[4] = *c;
    o[5] = *d;
}

static void corner(Vert *v, float x, float y, float u, float t, int r, int g, int b) {
    memset(v, 0, sizeof(*v));
    v->x = x;
    v->y = y;
    v->w = 1.0f;
    v->u = u;
    v->v = t;
    v->r = (uint8_t)r;
    v->g = (uint8_t)g;
    v->b = (uint8_t)b;
}

static void rect(const PsxHdCmd *c, int scale) {
    const PsxGpuState *st = &c->st;
    const PsxTex *t = c->textured ? &c->tex : NULL;
    PsxHdSurf *s = c->s;
    float x0 = (float)((c->x0 - (s->x - s->m)) * scale), y0 = (float)((c->y0 - s->y) * scale);
    float x1 = x0 + (float)(c->w * scale), y1 = y0 + (float)(c->h * scale);
    /* the texel of 1x column xx is u0 + xx (u0 - xx flipped: the left edge one texel up) */
    float ul = st->flip_x ? (float)(c->u0 + 1) : (float)c->u0;
    float ur = st->flip_x ? (float)(c->u0 + 1 - c->w) : (float)(c->u0 + c->w);
    float vt = st->flip_y ? (float)(c->v0 + 1) : (float)c->v0;
    float vb = st->flip_y ? (float)(c->v0 + 1 - c->h) : (float)(c->v0 + c->h);
    Vert k[4], v[6];

    corner(&k[0], x0, y0, ul, vt, c->r, c->g, c->b);
    corner(&k[1], x1, y0, ur, vt, c->r, c->g, c->b);
    corner(&k[2], x0, y1, ul, vb, c->r, c->g, c->b);
    corner(&k[3], x1, y1, ur, vb, c->r, c->g, c->b);
    quad(v, &k[0], &k[1], &k[2], &k[3]);
    set_par(v, 6, t != NULL ? tex_bits(t) : 0, win_bits(st), F_BLOCK | (st->set_mask ? F_SETMASK : 0), 0);
    emit_prim(c, v, 6, t != NULL);
}

/* A line S pixels thick: a parallelogram from the first end pixel's block to the last one's
 * along the major axis, S wide across it (backend/psxgpu_hd.c draw_line). */
static void line(const PsxHdCmd *c, int scale) {
    const PsxGpuState *st = &c->st;
    PsxHdSurf *s = c->s;
    const PsxVtx *a = &c->v[0], *b = &c->v[1];
    int dx = b->x - a->x, dy = b->y - a->y;
    int xmajor = (dx < 0 ? -dx : dx) >= (dy < 0 ? -dy : dy);
    float S = (float)scale;
    float ax, ay, bx, by;
    const PsxVtx *ca, *cb;
    Vert k[4], v[6];

    if ((xmajor && dx < 0) || (!xmajor && dy < 0)) {
        const PsxVtx *tmp = a;
        a = b;
        b = tmp;
    }
    ca = a;
    cb = c->gouraud ? b : &c->v[0];
    if (!c->gouraud) {
        ca = &c->v[0];
    }
    ax = (float)(a->x - (s->x - s->m)) * S;
    ay = (float)(a->y - s->y) * S;
    bx = (float)(b->x - (s->x - s->m)) * S;
    by = (float)(b->y - s->y) * S;
    if (xmajor) {
        corner(&k[0], ax, ay, 0, 0, ca->r, ca->g, ca->b);
        corner(&k[1], ax, ay + S, 0, 0, ca->r, ca->g, ca->b);
        corner(&k[2], bx + S, by, 0, 0, cb->r, cb->g, cb->b);
        corner(&k[3], bx + S, by + S, 0, 0, cb->r, cb->g, cb->b);
    } else {
        corner(&k[0], ax, ay, 0, 0, ca->r, ca->g, ca->b);
        corner(&k[1], ax + S, ay, 0, 0, ca->r, ca->g, ca->b);
        corner(&k[2], bx, by + S, 0, 0, cb->r, cb->g, cb->b);
        corner(&k[3], bx + S, by + S, 0, 0, cb->r, cb->g, cb->b);
    }
    quad(v, &k[0], &k[1], &k[2], &k[3]);
    set_par(v, 6, 0, 0, (st->dither && c->gouraud ? F_DITHER : 0) | (st->set_mask ? F_SETMASK : 0), 0);
    emit_prim(c, v, 6, 0);
}

/* Fill (kind 1, colour in VRAM format) or VRAM copy (kind 2) of the surface pixel rect x0, y0,
 * w, h; the copy reads VRAM from u0, v0. */
static void transfer(const PsxHdCmd *c, int scale) {
    PsxHdSurf *s = c->s;
    float x0 = (float)c->x0, y0 = (float)c->y0, x1 = x0 + (float)c->w, y1 = y0 + (float)c->h;
    int r = (c->r & 31) << 3, g = ((c->r >> 5) & 31) << 3, b = ((c->r >> 10) & 31) << 3;
    float u0 = (float)c->u0, v0 = (float)c->v0;
    float u1 = u0 + (float)c->w / (float)scale, v1 = v0 + (float)c->h / (float)scale;
    SDL_Rect sc;
    Vert k[4], v[6];

    sc.x = 0;
    sc.y = 0;
    sc.w = (s->w + 2 * s->m) * scale;
    sc.h = s->h * scale;
    corner(&k[0], x0, y0, u0, v0, r, g, b);
    corner(&k[1], x1, y0, u1, v0, r, g, b);
    corner(&k[2], x0, y1, u0, v1, r, g, b);
    corner(&k[3], x1, y1, u1, v1, r, g, b);
    quad(v, &k[0], &k[1], &k[2], &k[3]);
    set_par(v, 6, 0, 0, F_KIND(c->type == PSXHD_FILL ? 1 : 2) | F_BLOCK, 0);
    emit(s, 0, &sc, v, 6);
}

/* ---- batch ---- */

/* PG.10 b3: submits cmd, then waits for the previous submission (normally done long ago). The
 * wait lets SDL_GPU recycle finished command buffers and cycled transfer buffers; without it they
 * piled up whenever the SDL renderer did not present (headless runs, a window held by a drag):
 * about 115 MB per second at 2x. */
static void submit(SDL_GPUCommandBuffer *cmd) {
    SDL_GPUFence *fence = SDL_SubmitGPUCommandBufferAndAcquireFence(cmd);

    if (last_fence != NULL) {
        SDL_WaitForGPUFences(dev, true, &last_fence, 1);
        SDL_ReleaseGPUFence(dev, last_fence);
    }
    last_fence = fence;
}

static int upload(SDL_GPUCopyPass *copy) {
    if (dirty_y0 < dirty_y1) {
        Uint8 *m = SDL_MapGPUTransferBuffer(dev, vram_tb, true);
        SDL_GPUTransferBufferLocation src;
        SDL_GPUBufferRegion dst;

        if (m == NULL) {
            return 0;
        }
        memcpy(m + (size_t)dirty_y0 * ROW_BYTES, PsxGpu_Vram[dirty_y0], (size_t)(dirty_y1 - dirty_y0) * ROW_BYTES);
        SDL_UnmapGPUTransferBuffer(dev, vram_tb);
        src.transfer_buffer = vram_tb;
        src.offset = (Uint32)dirty_y0 * ROW_BYTES;
        dst.buffer = vram_buf;
        dst.offset = (Uint32)dirty_y0 * ROW_BYTES;
        dst.size = (Uint32)(dirty_y1 - dirty_y0) * ROW_BYTES;
        SDL_UploadToGPUBuffer(copy, &src, &dst, false);
        dirty_y0 = dirty_y1 = 0;
    }
    if (nverts > 0) {
        Uint32 bytes = (Uint32)nverts * sizeof(Vert);
        SDL_GPUTransferBufferLocation src;
        SDL_GPUBufferRegion dst;
        void *m;

        if (bytes > vcap) {
            SDL_GPUBufferCreateInfo bi;
            SDL_GPUTransferBufferCreateInfo ti;
            Uint32 cap = vcap ? vcap : 1u << 20;

            while (cap < bytes) {
                cap *= 2;
            }
            if (vbuf != NULL) {
                SDL_ReleaseGPUBuffer(dev, vbuf);
                SDL_ReleaseGPUTransferBuffer(dev, vtb);
            }
            SDL_zero(bi);
            bi.usage = SDL_GPU_BUFFERUSAGE_VERTEX;
            bi.size = cap;
            vbuf = SDL_CreateGPUBuffer(dev, &bi);
            SDL_zero(ti);
            ti.usage = SDL_GPU_TRANSFERBUFFERUSAGE_UPLOAD;
            ti.size = cap;
            vtb = SDL_CreateGPUTransferBuffer(dev, &ti);
            vcap = cap;
            if (vbuf == NULL || vtb == NULL) {
                printf("[gpu] GPU renderer: vertex buffer failed: %s\n", SDL_GetError());
                vcap = 0;
                return 0;
            }
        }
        m = SDL_MapGPUTransferBuffer(dev, vtb, true);
        if (m == NULL) {
            return 0;
        }
        memcpy(m, verts, bytes);
        SDL_UnmapGPUTransferBuffer(dev, vtb);
        src.transfer_buffer = vtb;
        src.offset = 0;
        dst.buffer = vbuf;
        dst.offset = 0;
        dst.size = bytes;
        SDL_UploadToGPUBuffer(copy, &src, &dst, true);
    }
    return 1;
}

void PsxHw_Flush(const PsxHdCmd *q, int n, int scale) {
    static int warned;
    SDL_GPUCommandBuffer *cmd;
    SDL_GPUCopyPass *copy;
    SDL_GPURenderPass *pass = NULL;
    PsxHdSurf *cur = NULL;
    int curpipe = -1, i;

    if (dev == NULL) {
        return;
    }
    nverts = 0;
    ndraws = 0;
    for (i = 0; i < n; i++) {
        const PsxHdCmd *c = &q[i];

        if (c->st.check_mask && !warned) {
            warned = 1;
            printf("[gpu] GPU renderer: mask check not supported (logged once)\n");
        }
        switch (c->type) {
        case PSXHD_TRI:
            tri(c, scale);
            break;
        case PSXHD_RECT:
            rect(c, scale);
            break;
        case PSXHD_LINE:
            line(c, scale);
            break;
        default:
            transfer(c, scale);
            break;
        }
    }
    cmd = SDL_AcquireGPUCommandBuffer(dev);
    if (cmd == NULL) {
        printf("[gpu] GPU renderer: no command buffer: %s\n", SDL_GetError());
        return;
    }
    copy = SDL_BeginGPUCopyPass(cmd);
    if (!upload(copy)) {
        ndraws = 0;
    }
    SDL_EndGPUCopyPass(copy);
    for (i = 0; i < ndraws; i++) {
        const Draw *d = &draws[i];

        if (d->s != cur) {
            SDL_GPUColorTargetInfo ct;
            SDL_GPUBufferBinding vb;
            SDL_FColor half = { 0.5f, 0.5f, 0.5f, 0.5f };
            float size[2];
            int sc = scale;

            if (pass != NULL) {
                SDL_EndGPURenderPass(pass);
            }
            cur = d->s;
            SDL_zero(ct);
            ct.texture = cur->tex;
            ct.load_op = SDL_GPU_LOADOP_LOAD;
            ct.store_op = SDL_GPU_STOREOP_STORE;
            pass = SDL_BeginGPURenderPass(cmd, &ct, 1, NULL);
            vb.buffer = vbuf;
            vb.offset = 0;
            SDL_BindGPUVertexBuffers(pass, 0, &vb, 1);
            SDL_BindGPUFragmentStorageBuffers(pass, 0, &vram_buf, 1);
            SDL_SetGPUBlendConstants(pass, half);
            size[0] = (float)((cur->w + 2 * cur->m) * scale);
            size[1] = (float)(cur->h * scale);
            SDL_PushGPUVertexUniformData(cmd, 0, size, sizeof(size));
            SDL_PushGPUFragmentUniformData(cmd, 0, &sc, sizeof(sc));
            curpipe = -1;
        }
        if (d->pipe != curpipe) {
            curpipe = d->pipe;
            SDL_BindGPUGraphicsPipeline(pass, pipes[curpipe]);
        }
        SDL_SetGPUScissor(pass, &d->scissor);
        SDL_DrawGPUPrimitives(pass, d->count, 1, d->first, 0);
    }
    if (pass != NULL) {
        SDL_EndGPURenderPass(pass);
    }
    submit(cmd);
}

void PsxHw_Copy(void *src, int x, int y, int w, int h, void *dst) {
    SDL_GPUCommandBuffer *cmd;
    SDL_GPUCopyPass *copy;
    SDL_GPUTextureLocation from, to;

    if (dev == NULL || src == NULL || dst == NULL) {
        return;
    }
    cmd = SDL_AcquireGPUCommandBuffer(dev);
    if (cmd == NULL) {
        return;
    }
    copy = SDL_BeginGPUCopyPass(cmd);
    SDL_zero(from);
    from.texture = src;
    from.x = (Uint32)x;
    from.y = (Uint32)y;
    SDL_zero(to);
    to.texture = dst;
    SDL_CopyGPUTextureToTexture(copy, &from, &to, (Uint32)w, (Uint32)h, 1, false);
    SDL_EndGPUCopyPass(copy);
    submit(cmd);
}

/* PR.2b: the rect x, y, w, h of src sharpened (strength 1..100) into the top-left corner of dst. */
void PsxHw_Sharpen(void *src, int x, int y, int w, int h, void *dst, int strength) {
    SDL_GPUCommandBuffer *cmd;
    SDL_GPURenderPass *pass;
    SDL_GPUColorTargetInfo ct;
    SDL_GPUTextureSamplerBinding tsb;
    SDL_GPUViewport vp;
    SDL_Rect sc = { 0, 0, w, h };
    struct {
        int32_t origin[2], size[2];
        float sharpness, pad[3];
    } par = { { x, y }, { w, h }, strength / 100.0f, { 0, 0, 0 } };

    if (dev == NULL || src == NULL || dst == NULL) {
        return;
    }
    cmd = SDL_AcquireGPUCommandBuffer(dev);
    if (cmd == NULL) {
        return;
    }
    SDL_zero(ct);
    ct.texture = dst;
    ct.load_op = SDL_GPU_LOADOP_LOAD;
    ct.store_op = SDL_GPU_STOREOP_STORE;
    pass = SDL_BeginGPURenderPass(cmd, &ct, 1, NULL);
    vp.x = 0;
    vp.y = 0;
    vp.w = (float)w;
    vp.h = (float)h;
    vp.min_depth = 0;
    vp.max_depth = 1;
    SDL_SetGPUViewport(pass, &vp);
    SDL_SetGPUScissor(pass, &sc);
    SDL_BindGPUGraphicsPipeline(pass, sharpen_pipe);
    tsb.texture = src;
    tsb.sampler = sharpen_sampler;
    SDL_BindGPUFragmentSamplers(pass, 0, &tsb, 1);
    SDL_PushGPUFragmentUniformData(cmd, 0, &par, sizeof(par));
    SDL_DrawGPUPrimitives(pass, 3, 1, 0, 0);
    SDL_EndGPURenderPass(pass);
    submit(cmd);
}

int PsxHw_Read(void *tex, int x, int y, int w, int h, uint32_t *out) {
    Uint32 bytes = (Uint32)w * (Uint32)h * 4;
    SDL_GPUCommandBuffer *cmd;
    SDL_GPUCopyPass *copy;
    SDL_GPUTextureRegion src;
    SDL_GPUTextureTransferInfo dst;
    SDL_GPUFence *fence;
    const Uint8 *m;
    int i;

    if (dev == NULL || tex == NULL) {
        return 0;
    }
    if (bytes > read_cap) {
        SDL_GPUTransferBufferCreateInfo ti;

        if (read_tb != NULL) {
            SDL_ReleaseGPUTransferBuffer(dev, read_tb);
        }
        SDL_zero(ti);
        ti.usage = SDL_GPU_TRANSFERBUFFERUSAGE_DOWNLOAD;
        ti.size = bytes;
        read_tb = SDL_CreateGPUTransferBuffer(dev, &ti);
        read_cap = read_tb != NULL ? bytes : 0;
        if (read_tb == NULL) {
            return 0;
        }
    }
    cmd = SDL_AcquireGPUCommandBuffer(dev);
    if (cmd == NULL) {
        return 0;
    }
    copy = SDL_BeginGPUCopyPass(cmd);
    SDL_zero(src);
    src.texture = tex;
    src.x = (Uint32)x;
    src.y = (Uint32)y;
    src.w = (Uint32)w;
    src.h = (Uint32)h;
    src.d = 1;
    SDL_zero(dst);
    dst.transfer_buffer = read_tb;
    dst.pixels_per_row = (Uint32)w;
    dst.rows_per_layer = (Uint32)h;
    SDL_DownloadFromGPUTexture(copy, &src, &dst);
    SDL_EndGPUCopyPass(copy);
    fence = SDL_SubmitGPUCommandBufferAndAcquireFence(cmd);
    if (fence == NULL) {
        return 0;
    }
    SDL_WaitForGPUFences(dev, true, &fence, 1);
    SDL_ReleaseGPUFence(dev, fence);
    m = SDL_MapGPUTransferBuffer(dev, read_tb, false);
    if (m == NULL) {
        return 0;
    }
    for (i = 0; i < w * h; i++) {
        out[i] = (uint32_t)m[i * 4] << 16 | (uint32_t)m[i * 4 + 1] << 8 | m[i * 4 + 2];
    }
    SDL_UnmapGPUTransferBuffer(dev, read_tb);
    return 1;
}
