#version 450

/* PR.2b contrast adaptive sharpening (the formula of AMD FidelityFX CAS, no scaling) of the rect
 * origin, size of the source texture into the target's top-left corner. Per channel: the 3x3
 * neighbourhood's minimum and maximum (cross plus corners) give how much room the pixel has
 * before it would clip; the sharpening weight shrinks where that room is small, so edges get
 * crisper without halos. Edges of the rect clamp. Alpha (the PS1 mask bit) is kept. The same
 * filter runs on the CPU for the software renderer (backend/sharpen.c). */

layout(location = 0) out vec4 o_col;

layout(set = 2, binding = 0) uniform sampler2D src;

layout(set = 3, binding = 0) uniform Params {
    ivec2 origin;
    ivec2 size;
    float sharpness; /* 0..1 */
} par;

vec4 tap(ivec2 p, int dx, int dy) {
    ivec2 q = clamp(p + ivec2(dx, dy), ivec2(0), par.size - 1);
    return texelFetch(src, par.origin + q, 0);
}

void main() {
    ivec2 p = ivec2(gl_FragCoord.xy);
    vec3 a = tap(p, -1, -1).rgb, b = tap(p, 0, -1).rgb, c = tap(p, 1, -1).rgb;
    vec3 d = tap(p, -1, 0).rgb;
    vec4 e4 = tap(p, 0, 0);
    vec3 e = e4.rgb, f = tap(p, 1, 0).rgb;
    vec3 g = tap(p, -1, 1).rgb, h = tap(p, 0, 1).rgb, i = tap(p, 1, 1).rgb;

    vec3 mn = min(min(min(d, e), min(f, b)), h);
    vec3 mn2 = min(mn, min(min(a, c), min(g, i)));
    vec3 mx = max(max(max(d, e), max(f, b)), h);
    vec3 mx2 = max(mx, max(max(a, c), max(g, i)));
    mn += mn2;
    mx += mx2;

    vec3 amp = sqrt(clamp(min(mn, 2.0 - mx) / max(mx, 1.0 / 512.0), 0.0, 1.0));
    vec3 w = amp * (-1.0 / mix(8.0, 5.0, par.sharpness));
    vec3 o = (e + w * (b + d + f + h)) / (1.0 + 4.0 * w);

    o_col = vec4(clamp(o, 0.0, 1.0), e4.a);
}
