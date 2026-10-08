#version 450

/* HD surface primitives (backend/psxgpu_hw.c). Position in surface pixels (top-left origin) with
 * w = the precise depth for perspective-correct texture coordinates (1 = affine). Colour is
 * interpolated without perspective, as on the PS1. */

layout(location = 0) in vec3 a_pos;
layout(location = 1) in vec2 a_uv;
layout(location = 2) in vec4 a_col;
layout(location = 3) in uvec4 a_par;

layout(set = 1, binding = 0) uniform Target {
    vec2 size;
} target;

layout(location = 0) out vec2 v_uv;
layout(location = 1) noperspective out vec3 v_col;
layout(location = 2) flat out uvec4 v_par;

void main() {
    float w = a_pos.z;
    vec2 ndc = vec2(a_pos.x / target.size.x * 2.0 - 1.0, 1.0 - a_pos.y / target.size.y * 2.0);

    gl_Position = vec4(ndc * w, 0.0, w);
    v_uv = a_uv;
    v_col = a_col.rgb * 255.0;
    v_par = a_par;
}
