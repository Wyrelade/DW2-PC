#version 450

/* PR.2b sharpen pass (backend/psxgpu_hw.c PsxHw_Sharpen): one triangle covering the target,
 * drawn without a vertex buffer. */

void main() {
    vec2 p = vec2(float((gl_VertexIndex << 1) & 2), float(gl_VertexIndex & 2));

    gl_Position = vec4(p * 2.0 - 1.0, 0.0, 1.0);
}
