#version 450

/* HD surface pixels (backend/psxgpu_hw.c): the PS1 shading of backend/psxgpu_hd.c per surface
 * pixel. Textures and CLUTs are read from the 1x VRAM (a storage buffer, two 16-bit pixels per
 * word); the result is a 5-bit colour per channel (stored as 8 bits) with the mask bit in alpha.
 *
 * v_par.x texture: 0-1 mode (4 / 8 / 15 bit), 2 raw, 3 textured, 4-7 page x / 64, 8 page y / 256,
 *         9-14 CLUT x / 16, 15-23 CLUT y
 * v_par.y texture window: mask x / 8, mask y / 8, offset x / 8, offset y / 8 (5 bits each)
 * v_par.z flags: 0 dither, 1 sprite-like (sample at the 1x pixel), 2-3 pass (0 all, 1 opaque
 *         texels only, 2 semi-transparent texels / pixels only), 4-5 abr, 6-7 kind (0 primitive,
 *         1 fill: colour = 5-bit value << 3, 2 VRAM copy: uv = VRAM position), 8 set mask,
 *         9 clamp u to the limits
 * v_par.w u limits: min | max << 8 */

layout(location = 0) in vec2 v_uv;
layout(location = 1) noperspective in vec3 v_col;
layout(location = 2) flat in uvec4 v_par;

layout(location = 0) out vec4 o_col;

layout(std430, set = 2, binding = 0) readonly buffer Vram {
    uint px[];
} vram;

layout(set = 3, binding = 0) uniform Params {
    int scale;
} params;

const int dither_tbl[16] = int[16](-4, 0, -3, 1, 2, -2, 3, -1, -3, 1, -4, 0, 3, -1, 2, -2);

uint vram16(int x, int y) {
    uint i = uint((y & 511) * 1024 + (x & 1023));
    return (vram.px[i >> 1] >> ((i & 1u) * 16u)) & 0xFFFFu;
}

ivec3 to5(ivec3 c8, int d) {
    return clamp(c8 + d, 0, 255) >> 3;
}

vec4 out_col(ivec3 c5, bool mask) {
    return vec4(vec3((c5 << 3) | (c5 >> 2)) / 255.0, mask ? 1.0 : 0.0);
}

void main() {
    uint tex = v_par.x, win = v_par.y, fl = v_par.z;
    int S = params.scale;
    ivec2 P = ivec2(gl_FragCoord.xy);
    vec2 dx = dFdx(v_uv), dy = dFdy(v_uv);
    vec2 uv = v_uv;
    int kind = int((fl >> 6) & 3u);
    int pass = int((fl >> 2) & 3u);
    int abr = int((fl >> 4) & 3u);
    bool mask = (fl & 0x100u) != 0u;
    ivec3 col, c5;
    ivec2 iuv;

    if ((fl & 2u) != 0u) {
        /* sprite-like: the texel of the 1x pixel's first surface pixel */
        ivec2 m = P % S;
        uv -= dx * float(m.x) + dy * float(m.y);
    }
    iuv = ivec2(floor(uv + 1.0 / 512.0));
    if (kind == 2) {
        uint c = vram16(iuv.x, iuv.y);
        o_col = out_col(ivec3(c & 31u, (c >> 5) & 31u, (c >> 10) & 31u), (c & 0x8000u) != 0u);
        return;
    }
    col = clamp(ivec3(floor(v_col + 1.0 / 256.0)), 0, 255);
    if (kind == 1) {
        o_col = out_col(col >> 3, false);
        return;
    }
    int d = (fl & 1u) != 0u ? dither_tbl[((P.y / S) & 3) * 4 + ((P.x / S) & 3)] : 0;
    if ((tex & 8u) != 0u) {
        int u, v, tx, ty, cx, cy;
        uint t;
        int mx = int(win & 31u) * 8, my = int((win >> 5) & 31u) * 8;
        int ox = int((win >> 10) & 31u) * 8, oy = int((win >> 15) & 31u) * 8;

        if ((fl & 0x200u) != 0u) {
            iuv.x = clamp(iuv.x, int(v_par.w & 255u), int((v_par.w >> 8) & 255u));
        }
        u = ((iuv.x & ~mx) | (ox & mx)) & 255;
        v = ((iuv.y & ~my) | (oy & my)) & 255;
        tx = int((tex >> 4) & 15u) * 64;
        ty = int((tex >> 8) & 1u) * 256;
        cx = int((tex >> 9) & 63u) * 16;
        cy = int((tex >> 15) & 511u);
        switch (tex & 3u) {
        case 0u:
            t = vram16(cx + int((vram16(tx + (u >> 2), ty + v) >> ((u & 3) * 4)) & 15u), cy);
            break;
        case 1u:
            t = vram16(cx + int((vram16(tx + (u >> 1), ty + v) >> ((u & 1) * 8)) & 255u), cy);
            break;
        default:
            t = vram16(tx + u, ty + v);
            break;
        }
        if (t == 0u) {
            discard;
        }
        bool tsemi = (t & 0x8000u) != 0u;
        if ((pass == 1 && tsemi) || (pass == 2 && !tsemi)) {
            discard;
        }
        c5 = ivec3(t & 31u, (t >> 5) & 31u, (t >> 10) & 31u);
        if ((tex & 4u) == 0u) {
            c5 = to5((c5 * col) >> 4, d);
        }
        mask = mask || tsemi;
    } else {
        c5 = to5(col, d);
    }
    if (pass == 2 && abr == 3) {
        c5 >>= 2;
    }
    o_col = out_col(c5, mask);
}
