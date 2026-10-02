#include "common.h"
#include "stag1000/stag1000.h"

void func_800650D0(u8 *dst) {
    u8 *src;
    u8 *p;
    s32 back;
    s32 c; u8 b;
    s32 i;

    back = 0;
    src = D_800653D8;
    p = dst;
    do {
        b = *src++; c = b;
        if (b < 0xF0) {
            if (back != 0) {
                for (; c >= 0; c--) {
                    *p = *(p - back);
                    p++;
                }
            } else {
                for (; c >= 0; c--) {
                    *p++ = *src++;
                }
            }
        } else {
            back = 0;
            if (c != 0xF0) {
                back = ((c << 8) | *src++) - 0xF0FF;
            }
        }
    } while (back != 0xF00);
    for (i = 4; i < 0x8800; i++) {
        ((u16 *)dst)[i] ^= ((u16 *)dst)[i - 4];
    }
}
