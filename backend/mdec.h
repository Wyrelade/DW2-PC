#ifndef BACKEND_MDEC_H
#define BACKEND_MDEC_H

#include <stdint.h>

/* PS1 movie decoding (PR.4): the STR frame bitstream to MDEC run-length codes (what Psy-Q's
 * DecDCTvlc2 does on the CPU) and the MDEC itself (run-length codes -> dequantise -> IDCT ->
 * YCbCr to RGB, 16x16 macroblocks). After psx-spx; the quantisation table is the Psy-Q default
 * one DecDCTReset loads. Decoding is instant (no MDEC timing). */

/* bs: one STR frame (8-byte header: run-length size in words, 0x3800, quantiser scale, version;
 * then the bitstream). Writes out[0] = 0x3800nnnn (nnnn = words that follow) and the run-length
 * halfwords, at most out_words words. Returns the words written, or -1 (unknown version, broken
 * stream or no room); then out holds an empty stream. Bitstream versions 1 and 2. */
int Mdec_Vlc(const uint8_t *bs, uint32_t *out, int out_words);

/* DecDCTin: the next output reads macroblocks from this run-length stream (out of Mdec_Vlc).
 * rgb24: 24-bit output, else 15-bit with bit 15 = stp. */
void Mdec_Start(const uint32_t *in, int rgb24, int stp);

/* DecDCTout: `words` words of pixels into out, whole macroblocks in stream order (24-bit: 192
 * words each, 15-bit: 128); each macroblock is 16 rows of 16 pixels. Past the end of the stream
 * the rest is black. */
void Mdec_Out(uint32_t *out, int words);

#endif /* BACKEND_MDEC_H */
