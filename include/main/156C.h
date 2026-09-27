#ifndef MAIN_156C_H
#define MAIN_156C_H

#include "common.h"

/* Two halfwords copied as one 4-byte value (lwl/lwr). */
typedef struct {
    /* 0x0 */ s16 field_0;
    /* 0x2 */ s16 field_2;
} Pair54;

/* The struct reached through Actor.work (offset 0x2C). Field names are by byte
 * offset until the layout is understood; pads keep the known fields aligned.
 * Extend as more accessors are matched. */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 field_8;
    /* 0x0C */ s32 field_C;
    u8 _pad10[0x04];
    /* 0x14 */ u16 field_14;
    u8 _pad16[0x02];
    /* 0x18 */ s32 field_18;
    u8 _pad1C[0x08];
    /* 0x24 */ s32 field_24;
    /* 0x28 */ s32 field_28;
    /* 0x2C */ s16 field_2C;
    /* 0x2E */ s16 field_2E;
    /* 0x30 */ s16 field_30;
    u8 _pad32[0x06];
    /* 0x38 */ s16 field_38;
    u8 _pad3A[0x02];
    /* 0x3C */ s16 field_3C;
    u8 _pad3E[0x02];
    /* 0x40 */ s32 field_40;
    u8 _pad44[0x10];
    /* 0x54 */ Pair54 field_54;
    /* 0x58 */ s16 field_58;
    u8 _pad5A[0x0A];
    /* 0x64 */ s16 field_64;
    u8 _pad66[0x02];
    /* 0x68 */ s32 field_68;
    /* 0x6C */ s16 field_6C;
    /* 0x6E */ s16 field_6E;
    /* 0x70 */ s16 field_70;
    u8 _pad72[0x16];
    /* 0x88 */ s32 field_88;
    /* 0x8C */ s16 field_8C;
    u8 _pad8E[0x0A];
    /* 0x98 */ s16 field_98;
    u8 _pad9A[0x02];
    /* 0x9C */ s32 field_9C;
    u8 _padA0[0x04];
    /* 0xA4 */ s16 field_A4;
} ActorWork;

/* Global struct D_80041564; only field_0 and field_8 are known so far. */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 field_8;
} Obj80041564;

/* Global object pointer D_80048F08 with method pointers at 0x38 / 0x3C. */
typedef struct {
    u8 _pad00[0x08];
    /* 0x08 */ s32 (*fn_8)(s32, s32, s32, s32);
    /* 0x0C */ s32 field_C;
    /* 0x10 */ void (*fn_10)(s32);
    /* 0x14 */ void (*fn_14)(u8 *, s32);
    /* 0x18 */ void (*field_18)(u32 *);
    /* 0x1C */ s32 (*field_1C)(s32, s32);
    /* 0x20 */ void (*field_20)(s32, s32);
    u8 _pad24[0x08];
    /* 0x2C */ void (*fn_2C)(s32 *, s32);
    u8 _pad30[0x04];
    /* 0x34 */ s32 (*fn_34)(s32);
    /* 0x38 */ s32 (*fn)(void);
    /* 0x3C */ void (*fn_3C)(void *);
} Obj48F08;

/* Record returned by the func_80023AE8 lookup; cleared by func_80023BB0. */
typedef struct {
    /* 0x00 */ u16 field_0;
    /* 0x02 */ u16 field_2;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 field_8;
    /* 0x0C */ s32 field_C;
} Ent23AE8;

Ent23AE8 *func_80023AE8();

/* Entry returned by the func_8001E4CC table lookup (0x2C stride). */
typedef struct {
    /* 0x00 */ s16 field_0;
    /* 0x02 */ s16 field_2;
    /* 0x04 */ u8 field_4;
    u8 _pad05[0x0F];
    /* 0x14 */ s32 field_14[6];
} EntE4CC;

/* Global struct D_8005D560; field_0 is an id, 4/8 hold results, field_C walks the
 * func_800239A0 entry table and field_10 holds the entry func_8001E390 picked. */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 field_8;
    /* 0x0C */ EntE4CC *field_C;
    /* 0x10 */ EntE4CC field_10;
} S5D560;

/* Record cleared by func_800230DC. */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 field_8;
    /* 0x0C */ s32 field_C;
    /* 0x10 */ s32 field_10;
    /* 0x14 */ u8 field_14;
    /* 0x15 */ u8 field_15;
} Rec230DC;

/* Global struct D_80050938 populated by func_80011510. */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 field_8;
    /* 0x0C */ s32 field_C;
} Blk50938;

/* Element of the D_8005CD60 array (stride 0x20), indexed by func_8001CA28 and
   initialized by func_8001CA3C. */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 field_8;
    /* 0x0C */ s32 field_C;
    /* 0x10 */ s16 field_10;
    u8 _pad12[2];
    /* 0x14 */ s32 field_14;
    /* 0x18 */ s32 field_18;
    /* 0x1C */ s32 field_1C;
} Elem20;

/* A 0x1C-byte (7 word) block copied wholesale into ActorWork by func_80024310. */
typedef struct {
    s32 words[7];
} Block1C;

/* A 12-byte element in the array at offset 0x6C of the buffer that Ctx38.buf
 * points to; func_80020EE8 zeroes one. */
typedef struct {
    /* 0x0 */ s32 field_0;
    /* 0x4 */ s32 field_4;
    /* 0x8 */ s32 field_8;
} Elem12;

/* The buffer reached through Ctx38.buf (offset 0x38): an Elem12 array at 0x6C. */
typedef struct {
    u8 _pad00[0x6C];
    /* 0x6C */ Elem12 elems[1];
} Buf38;

/* Container whose field at 0x38 points to a Buf38. Distinct from Actor (whose
 * 0x38 is a byte), so kept as its own type. */
typedef struct {
    u8 _pad00[0x38];
    /* 0x38 */ Buf38 *buf;
} Ctx38;

/* View of Actor.work used by func_800176D8: a s16 counter at 0x19E indexing a
 * s16 array at 0x1A0, plus a stride-8 element array reached at offset 0x6C. */
typedef struct {
    u8 _pad0[0x02];
    /* 0x2 */ u8 field_2;
    u8 _pad3[0x05];
} WorkElem8; /* size 0x8 */

typedef struct {
    u8 _pad00[0x19E];
    /* 0x19E */ s16 field_19E;
    /* 0x1A0 */ s16 field_1A0[16];
} Work176D8;

/* A 0x20 block copied verbatim from the const table D_80043714. */
typedef struct {
    /* 0x0 */ s16 m[3][3];
} Mat12; /* size 0x12 */

/* A matrix block (rotation + translation). */
typedef struct {
    /* 0x00 */ Mat12 m;
    u8 _pad12[0x02];
    /* 0x14 */ s32 t[3];
} Blk20;

/* 0x18-byte part key: rotation plus a short translation. */
typedef struct {
    /* 0x00 */ Mat12 m;
    /* 0x12 */ s16 t[3];
} Rec18; /* size 0x20 */

/* Stride-0x84 destination element func_8001F5E8 fills; the copied block lands
 * at offset 0x60. */
typedef struct {
    u8 _pad00[0x34];
    /* 0x34 */ s32 field_34;
    u8 _pad38[0x04];
    /* 0x3C */ s32 field_3C;
    u8 _pad40[0x20];
    /* 0x60 */ Blk20 field_60;
    /* 0x80 */ s32 field_80;
} DstElem; /* size 0x84 */

/* Object reached through Actor at 0x38 (overlaps the u8 field_38); func_8001EC10
 * writes three words at 0x30/0x34/0x38. */
typedef struct {
    u8 _pad00[0x30];
    /* 0x30 */ s32 field_30;
    /* 0x34 */ s32 field_34;
    /* 0x38 */ s32 field_38;
} ObjEC10;

/* Three-word vector copied field-to-field by value in func_80020920. */
typedef struct {
    /* 0x0 */ s32 x;
    /* 0x4 */ s32 y;
    /* 0x8 */ s32 z;
} Vec3;

/* Larger object reached through Actor at 0x38 (same slot as ObjEC10, used by
 * func_80020920): two Vec3s at 0x20/0x30 plus scalar state at 0x40..0x60. */
typedef struct {
    u8 _pad00[0x20];
    /* 0x20 */ Vec3 field_20;
    u8 _pad2C[0x04];
    /* 0x30 */ Vec3 field_30;
    u8 _pad3C[0x04];
    /* 0x40 */ s32 field_40;
    u8 _pad44[0x04];
    /* 0x48 */ s32 field_48;
    /* 0x4C */ s32 field_4C;
    /* 0x50 */ s32 field_50;
    u8 _pad54[0x04];
    /* 0x58 */ s32 field_58;
    /* 0x5C */ s32 field_5C;
    /* 0x60 */ s32 field_60;
} Obj209;

/* The struct reached through Actor at offset 0x3C. Only the fields written by
 * func_8001F24C / func_8001F5E8 are known so far: field_8 is a signed count and
 * field_78 an array of DstElem. */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ struct Mdl1FDBC *field_4;
    /* 0x08 */ s32 field_8;
    /* 0x0C */ s16 **field_C;
    /* 0x10 */ s16 **field_10;
    /* 0x14 */ struct Sec1FDBC20 **field_14;
    /* 0x18 */ s32 *field_18;
    /* 0x1C */ s32 *field_1C;
    /* 0x20 */ s32 field_20;
    /* 0x24 */ s32 field_24;
    /* 0x28 */ s32 field_28;
    /* 0x2C */ s32 field_2C;
    /* 0x30 */ s32 field_30;
    u8 _pad34[0x08];
    /* 0x3C */ s32 field_3C;
    u8 _pad40[0x04];
    /* 0x44 */ struct Pos1F9AC *field_44;
    /* 0x48 */ s32 field_48;
    /* 0x4C */ s32 field_4C;
    /* 0x50 */ s32 *field_50;
    /* 0x54 */ s32 field_54;
    /* 0x58 */ s32 field_58;
    /* 0x5C */ s32 field_5C;
    /* 0x60 */ s32 field_60;
    /* 0x64 */ s32 *field_64;
    /* 0x68 */ s32 *field_68;
    /* 0x6C */ s32 *field_6C;
    /* 0x70 */ s32 *field_70;
    /* 0x74 */ s32 *field_74;
    /* 0x78 */ DstElem *field_78;
} Sub3C;

/* Sub-object reached through the Act125C container at 0x3C; func_8001125C frees
   the four owned pointers at 0x6C..0x78. */
typedef struct {
    u8 _pad00[0x6C];
    /* 0x6C */ ActorWork *field_6C;
    /* 0x70 */ ActorWork *field_70;
    /* 0x74 */ ActorWork *field_74;
    /* 0x78 */ ActorWork *field_78;
} Obj125C;

/* Container torn down by func_8001125C: a func_80010ED4 array at 0x34 with count
   at 0x30, plus owned pointers freed via func_80022D84. */
typedef struct {
    u8 _pad00[0x2C];
    /* 0x2C */ ActorWork *field_2C;
    /* 0x30 */ s32 field_30;
    /* 0x34 */ s32 *field_34;
    /* 0x38 */ ActorWork *field_38;
    /* 0x3C */ Obj125C *field_3C;
} Act125C;

/* Two of these live in Actor at 0x48 (stride 0x5C). func_8001C194 stamps the
 * four-byte header of each; field_0 is the pair earlier read as Actor.field_48
 * (element 0) and Actor.field_A4 (element 1). */
typedef struct {
    /* 0x0 */ u8 field_0;
    /* 0x1 */ u8 field_1;
    /* 0x2 */ u8 field_2;
    /* 0x3 */ u8 field_3;
    u8 _pad04[0x58];
} ActorSub5C; /* size 0x5C */

/* arg0 of the 0x2C accessor family: a container holding a pointer to its
 * ActorWork at offset 0x2C. */
typedef struct {
    /* 0x00 */ s32 field_0;
    u8 _pad04[0x04];
    /* 0x08 */ s32 field_8;
    /* 0x0C */ s32 field_C;
    /* 0x10 */ s32 field_10;
    /* 0x14 */ s32 field_14;
    /* 0x18 */ s32 field_18;
    /* 0x1C */ s32 field_1C;
    /* 0x20 */ s32 field_20;
    /* 0x24 */ u8 field_24;
    u8 _pad25[0x03];
    /* 0x28 */ s32 field_28;
    /* 0x2C */ ActorWork *work;
    /* 0x30 */ s32 field_30;
    /* 0x34 read as a word by func_8001A958, or as the two bytes 0x36/0x37 elsewhere. */
    union {
        /* 0x34 */ s32 field_34;
        struct {
            u8 _b34[0x02];
            /* 0x36 */ u8 field_36;
            /* 0x37 */ u8 field_37;
        } b;
    } u34;
    /* 0x38 read as a byte (field_38) or as an ObjEC10* (ptr38) by func_8001EC10. */
    union {
        /* 0x38 */ u8 field_38;
        ObjEC10 *ptr38;
    } u38;
    /* 0x3C */ Sub3C *field_3C;
    u8 _pad40[0x06];
    /* 0x46 */ u8 field_46;
    /* 0x47 */ u8 field_47;
    /* 0x48 */ ActorSub5C field_48[2];
    u8 _pad100[0x10];
    /* 0x110 */ u16 field_110;
    u8 _pad112[0x02];
    /* 0x114 */ u16 field_114;
    u8 _pad116[0x02];
    /* 0x118 */ s32 field_118[8];
    /* 0x138 */ s32 *field_138[8];
} Actor;

/* Entry returned by the func_8001D8C4 table lookup (0x12 stride); accessed
 * fields only. */
typedef struct {
    /* 0x00 */ s16 field_0;
    /* 0x02 */ u8 field_2;
    /* 0x03 */ u8 field_3;
    union {
        /* 0x04 */ u8 field_4;
        /* 0x04 */ u16 field_4h;
    } u4;
    union {
        /* 0x06 */ u8 field_6;
        /* 0x06 */ u16 field_6h;
    } u6;
    /* 0x08 */ u8 field_8[5];
    /* 0x0D */ u8 field_D[4];
    u8 _pad11;
} EntD8C4;

/* Record returned by func_8001DB18; func_8001DB68 unpacks it. field_0 is read as
   a word (nibble fields at bits 8-11 / 12-15) and as an s16 at 0x2; field_4 as a
   byte at 0x4, an s16 at 0x6, and a word (nibbles at bits 8-11 / 12-15). */
typedef struct {
    union {
        /* 0x00 */ s32 field_0;
        struct { u8 _b[2]; s16 field_2; } h;
    } u0;
    union {
        /* 0x04 */ u32 field_4;
        u8 field_4b;
        struct { u8 _b[2]; s16 field_6; } h;
    } u4;
    /* 0x08 */ u16 field_8;
    u8 _pad0A[0x8];
    /* 0x12 */ u8 field_12;
    u8 _pad13[0xB];
} Ent1DB18;

/* Stride-0x1E view of the Ent1DB18 array that func_8001DB68 walks (the record's
   s32 unions force C to size Ent1DB18 as 0x20, but the on-disc stride is 0x1E, so
   the copy loop indexes this 2-aligned row instead). */
typedef struct {
    u8 _pad00[0x08];
    /* 0x08 */ u16 field_8;
    /* 0x0A */ u16 field_A;
    /* 0x0C */ u16 field_C;
    u8 _pad0E[0x4];
    /* 0x12 */ u8 field_12;
    /* 0x13 */ u8 field_13;
    /* 0x14 */ u16 field_14;
    /* 0x16 */ u8 field_16;
    /* 0x17 */ u8 field_17;
    /* 0x18 */ u8 field_18;
    /* 0x19 */ u8 field_19;
    u8 _pad1A[0x4];
} Row1DB18; /* 0x1E */

/* Record func_8001DB68 fills from an Ent1DB18. */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 field_8;
    /* 0x0C */ s32 field_C;
    /* 0x10 */ s32 field_10;
    /* 0x14 */ s32 field_14;
    /* 0x18 */ s32 field_18;
    /* 0x1C */ u16 field_1C[3];
    /* 0x22 */ u16 field_22[3];
} Out1DB68;

Ent1DB18 *func_8001DB18();


/* Entry returned by the func_8001E6A8 table lookup (0x28 stride). */
typedef struct {
    /* 0x00 */ s32 field_0;
    union {
        /* 0x04 */ u32 field_4;
        struct {
            u8 _b4[2];
            /* 0x06 */ s16 field_6;
        } h4;
    } u4;
    /* 0x08 */ s16 field8[11];
    /* 0x1E */ s16 field_1E;
    /* 0x20 */ s16 field_20;
    /* 0x22 */ s16 field_22;
    /* 0x24 */ s16 field_24;
    /* 0x26 */ s16 field_26;
} EntE6A8;

/* Packed record returned by the func_8001ED40 lookup. Several 32-bit words hold
 * bitfields read at multiple widths, so overlapping offsets use unions. */
typedef struct {
    union {
        /* 0x00 */ u32 field_0;
        /* 0x00 */ s16 id;
        struct {
            u8 _b0[2];
            /* 0x02 */ u16 field_2;
        } h0;
        struct {
            u8 _b0[3];
            /* 0x03 */ u8 field_3;
        } b0;
    } u0;
    /* 0x04 */ u8 field_4;
    /* 0x05 */ u8 field_5;
    /* 0x06 */ s16 field_6;
    /* 0x08 */ s16 field_8;
    u8 _pad0A[0x02];
    /* 0x0C */ s32 field_C;
    union {
        /* 0x10 */ u32 field_10;
        /* 0x10 */ u8 field_10b;
    } u10;
    /* 0x14 */ u32 field_14;
    /* 0x18 */ u32 field_18;
    /* 0x1C */ u32 field_1C;
    /* 0x20 */ u32 field_20;
    /* 0x24 */ u32 field_24;
    /* 0x28 */ u32 field_28;
    /* 0x2C */ s16 field_2C[4][3]; /* -> size 0x44 (table stride) */
} EntED40;

/* Record returned by the func_8001DFF4 lookup; two 32-bit words read at both
 * word and byte widths. */
typedef struct {
    union {
        /* 0x00 */ u32 field_0;
        /* 0x00 */ s16 field_0h;
        struct {
            u8 _b0[2];
            /* 0x02 */ u8 field_2;
            /* 0x03 */ u8 field_3;
        } b0;
    } u0;
    union {
        /* 0x04 */ u32 field_4;
        struct {
            u8 _b4[3];
            /* 0x07 */ u8 field_7;
        } b4;
    } u4;
    /* 0x08 */ s32 field_8;
    /* 0x0C */ s32 field_C;
} EntDFF4;

EntD8C4 *func_8001D8C4();
EntE4CC *func_8001E4CC();
EntE6A8 *func_8001E6A8();

/* 6-byte record copied wholesale by func_8001E7E4 from a stride-6 table (base is
 * the func_800239A0 lookup, index is EntE6A8.field_22/24/26). 2-byte alignment
 * makes the copy an unaligned lwl/lwr word plus an lh half. */
typedef struct {
    /* 0x0 */ s16 data[3];
} Row6;
EntED40 *func_8001ED40();
EntDFF4 *func_8001DFF4();

/* Base record returned by the func_800239A0 lookup. Stride 0x28 when indexed. */
typedef struct {
    u8 _pad00[0x04];
    /* 0x04 */ u32 field_4;
    u8 _pad08[0x20];
} EntA0;

EntA0 *func_800239A0();
s32 func_80023A08();
s32 func_8001EE34();

/* Record returned by the func_80023A78 lookup. */
typedef struct {
    /* 0x00 */ s16 field_0;
    /* 0x02 */ s16 field_2;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 field_8;
    /* 0x0C */ s32 field_C;
} Ent23A78;

Ent23A78 *func_80023A78();

/* 3-entry table at D_80054C48, stride 0x2C, searched by func_8001A300. */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s16 field_8;
    /* 0x0A */ s16 field_A;
    /* 0x0C */ s16 field_C[0xA];
    /* 0x20 */ s32 field_20;
    /* 0x24 */ s32 field_24;
    /* 0x28 */ s32 *field_28;
} Ent54C48; /* 0x2C */

/* Args to func_8002828C: a record it stamps (field_3/field_4/field_8) and a
   two-halfword source read for the func_80028884 call. */
typedef struct {
    u8 _pad0[3];
    /* 0x03 */ u8 field_3;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 field_8;
} Obj8228C;

typedef struct {
    /* 0x00 */ s16 field_0;
    /* 0x02 */ s16 field_2;
    /* 0x04 */ u16 field_4;
    /* 0x06 */ u16 field_6;
} Pt8228C;

/* Integer stack: [0] is the count, entries follow. func_8001A8F4 pushes,
   func_8001A920 pops. */
typedef struct {
    /* 0x00 */ s32 count;
    /* 0x04 */ s32 data[1];
} Stack54CD0;

/* Global struct D_80048DB8: field_0 is a small state (func_80024220), field_4 a
   countdown and field_8 an advancing buffer pointer (func_8002405C; note the
   symbol D_80048DBC aliases field_4), field_1C a counter compared/bumped by
   func_80023FFC. */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 field_8;
    /* 0x0C */ u8 field_C;
    u8 _padD[0x3];
    /* 0x10 */ s32 field_10;
    /* 0x14 */ s32 field_14;
    /* 0x18 */ s32 field_18;
    /* 0x1C */ s32 field_1C;
} Obj48DB8;

/* Source record read by func_80013470 to fill an Arg1BC24. */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 field_8;
    /* 0x0C */ u16 field_C;
    /* 0x0E */ u16 field_E;
    /* 0x10 */ u8 field_10;
    /* 0x11 */ u8 field_11;
} Src13470;

/* A pair of 16-bit values passed by value in one register (func_800134F8). */
typedef struct {
    /* 0x0 */ u16 lo;
    /* 0x2 */ u16 hi;
} Halves;

/* 0x2C-byte parameter block built on the stack and passed to func_8001BC24
   (only the leading fields are written; the tail is left uninitialized). */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s16 field_8;
    /* 0x0A */ s16 field_A;
    /* 0x0C */ s32 field_C;
    /* 0x10 */ s32 field_10;
    /* 0x14 */ s32 field_14;
    /* 0x18 */ s32 field_18;
    /* 0x1C */ s32 field_1C;
    /* 0x20 */ s32 field_20;
    u8 _pad24[0x8];
} Arg1BC24;

/* Read view of the Arg1BC24 block used by func_8001BC24: same layout, but the
   0x8/0xA halfwords are read unsigned and 0x24/0x28 are read as words. */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ u16 field_8;
    /* 0x0A */ u16 field_A;
    /* 0x0C */ s32 field_C;
    /* 0x10 */ s32 field_10;
    /* 0x14 */ s32 field_14;
    /* 0x18 */ s32 field_18;
    /* 0x1C */ s32 field_1C;
    /* 0x20 */ s32 field_20;
    /* 0x24 */ s32 field_24;
    /* 0x28 */ s32 field_28;
} SrcBC24;

/* Stride-0x34 record built by func_8001BC24 into the func_80011510 array. */
typedef struct {
    /* 0x00 */ u8 field_0;
    /* 0x01 */ u8 field_1;
    /* 0x02 */ u8 field_2;
    /* 0x03 */ u8 field_3;
    /* 0x04 */ u8 field_4;
    u8 _pad5;
    /* 0x06 */ s16 field_6;
    /* 0x08 */ s32 field_8;
    /* 0x0C */ s32 field_C;
    /* 0x10 */ s32 field_10;
    /* 0x14 */ s32 field_14;
    /* 0x18 */ s32 field_18;
    /* 0x1C */ s16 field_1C;
    /* 0x1E */ s16 field_1E;
    /* 0x20 */ u8 field_20;
    /* 0x21 */ u8 field_21;
    /* 0x22 */ u8 field_22;
    /* 0x23 */ u8 field_23;
    /* 0x24 */ u8 field_24;
    /* 0x25 */ u8 field_25;
    /* 0x26 */ u8 field_26;
    /* 0x27 */ u8 field_27;
    /* 0x28 */ u8 field_28;
    /* 0x29 */ u8 field_29;
    /* 0x2A */ u8 field_2A;
    /* 0x2B */ u8 field_2B;
    /* 0x2C */ u8 field_2C;
    /* 0x2D */ u8 field_2D;
    /* 0x2E */ u8 field_2E;
    /* 0x2F */ u8 field_2F;
    /* 0x30 */ u8 field_30;
    /* 0x31 */ u8 field_31;
    u8 _pad32[2];
} Rec34;

/* Returned by func_80011440/func_80011510: the stride-0x34 record array at 0x2C. */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 field_8;
    u8 _pad0C[0x20];
    /* 0x2C */ Rec34 *field_2C;
    u8 _pad30[4];
    /* 0x34 */ Actor **field_34;
} Ent11440;

/* 0x10-stride record; D_800416CC array, per-slot init by func_8001F90C. */
typedef struct {
    /* 0x00 */ s32 x;
    /* 0x04 */ s32 y;
    /* 0x08 */ s32 z;
    /* 0x0C */ u8 r;
    /* 0x0D */ u8 g;
    /* 0x0E */ u8 b;
    u8 _pad0F;
} Blk16;

/* 0xC-stride record returned by the func_8001E5E8 getter (base is the
   func_800239A0((D_8005D560.field_0<<16)|1) lookup, index is EntE4CC.field_4). */
typedef struct {
    u8 data[0xC];
} Blk12;

/* 0x18-stride record; the func_8001E298 getter family returns &base[index] where
   base is the func_800239A0((D_8005D560.field_0<<16)|2) lookup result. */
typedef struct {
    u8 data[0x18];
} Blk18;

/* Argument to the func_8001E298 getter family: a byte index lives at one of several
   offsets (0x5/0x6/0xC) and selects a Blk18. */
typedef struct {
    u8 _pad0[5];
    /* 0x5 */ u8 field_5;
    /* 0x6 */ u8 field_6;
    u8 _pad7[5];
    /* 0xC */ u8 field_C;
} ArgE298;

/* Per-channel bucket built by func_800194C8: a count at +0, then a count-indexed
   array of s16 slots. Stride 0x1A; four channels live at Actor194C8.records. */
typedef struct {
    /* 0x00 */ s16 count;
    /* 0x02 */ s16 arr[12];
} Rec1A;

/* s16 held in a 4-byte stride slot (Actor194C8.slot54). */
typedef struct {
    /* 0x00 */ s16 v;
    /* 0x02 */ s16 field_2;
} Slot4;

/* View of the Actor block touched by func_800194C8. */
typedef struct {
    /* 0x00 */ s32 field_0[18];
    /* 0x48 */ s32 field_48;
    /* 0x4C */ s32 field_4C;
    /* 0x50 */ s32 field_50;
    /* 0x54 */ Slot4 slot54[4];
    /* 0x64 */ Blk12 block64[4]; /* the channel count is re-stored at +2 */
    /* 0x94 */ s32 field_94[4];
    u8 _padA4[0x4];
    /* 0xA8 */ s32 field_A8;
    /* 0xAC */ Rec1A records[4];
    /* 0x114 */ s32 field_114;
    /* 0x118 */ u8 *field_118;
    /* 0x11C */ u8 field_11C[8];
} Actor194C8;

/* Destination record for func_80033B24's bitfield unpack (all s16 fields). */
typedef struct {
    /* 0x00 */ s16 field_0;
    /* 0x02 */ s16 field_2;
    /* 0x04 */ s16 field_4;
    /* 0x06 */ s16 field_6;
    /* 0x08 */ s16 field_8;
    /* 0x0A */ s16 field_A;
    /* 0x0C */ s16 field_C;
    /* 0x0E */ s16 field_E;
    /* 0x10 */ s16 field_10;
} Out33B24;

/* Fixed-stride block indexed by func_8001C818 (element size 0x4030). */
typedef struct {
    /* 0x0000 */ s32 field_0[0x100C];
} Blk54CF8;

/* Element of the D_8005E620.elems[] array (stride 0x5C); only the leading
   status byte is touched by func_80022118. */
typedef struct {
    /* 0x00 */ u8 field_0;
    /* 0x01 */ u8 field_1;
    u8 _pad02[0xB];
    /* 0x0D */ u8 field_D;
    u8 _pad0E[0x1];
    /* 0x0F */ u8 field_F;
    /* 0x10 */ s32 field_10;
    /* 0x14 */ u16 field_14;
    /* 0x16 */ u16 field_16;
    /* 0x18 */ u16 field_18;
    /* 0x1A */ u16 field_1A;
    /* 0x1C */ s16 field_1C;
    /* 0x1E */ u16 field_1E;
    /* 0x20 */ s16 field_20;
    /* 0x22 */ u8 field_22;
    /* 0x23 */ u8 field_23;
    /* 0x24 */ u8 field_24;
    /* 0x25 */ u8 field_25[0x27];
    /* 0x4C */ u8 field_4C[14];
    u8 _pad5A[0x2];
} ElmE620; /* size 0x5C */

/* Global at D_8005E620: a 0xE4-byte header followed by an array of 0x24
   ElmE620 slots (func_80022118 scans and updates their status bytes). */
typedef struct {
    u8 _pad00[0x04];
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 field_8;
    u8 _pad0C[0x08];
    /* 0x14 */ u8 field_14;
    /* 0x15 */ u8 field_15;
    /* 0x16 */ u8 field_16;
    /* 0x17 */ u8 field_17;
    u8 _pad18[0xB9];
    /* 0xD1 */ u8 field_D1;
    /* 0xD2 */ u8 field_D2;
    /* 0xD3 */ u8 field_D3;
    /* 0xD4 */ u8 field_D4;
    u8 _padD5[0x0F];
    /* 0xE4 */ ElmE620 elems[0x24];
} EntE620;

/* Table cleared by func_80011190: a count word followed by 100 entries. */
typedef struct {
    /* 0x00 */ s32 count;
    /* 0x04 */ s32 entries[100];
} List50798;

/* Doubly-linked node reached at (arg0 - 0xC) by func_80022D84; field_0 is the
   sibling pointer, field_4 links to a neighbour whose field_0 points back. */
typedef struct Node22D84 {
    /* 0x00 */ struct Node22D84 *field_0;
    /* 0x04 */ struct Node22D84 *field_4;
    /* 0x08 */ s32 field_8;
} Node22D84;

/* arg0 of func_8002C0E4: three s32 accumulators at 0x14/0x18/0x1C. */
typedef struct {
    u8 _pad00[0x14];
    /* 0x14 */ s32 field_14;
    /* 0x18 */ s32 field_18;
    /* 0x1C */ s32 field_1C;
} ObjC0E4;

/* arg1 of func_8002C0E4: a GTE-style MATRIX. func_8002C774 fills m[3][3] (a Z
 * rotation scaled to 0x1000) + the field_14/18/1C translation; &field_14 is
 * handed to func_8002CF74. */
typedef struct {
    /* 0x00 */ s16 m[3][3];
    /* 0x14 */ s32 field_14;
    /* 0x18 */ s32 field_18;
    /* 0x1C */ s32 field_1C;
} ArgC0E4;

/* Accumulate-and-clamp record used by func_80020CE8: field_0 += field_4, then
 * clamped against field_8. */
typedef struct {
    /* 0x0 */ s32 field_0;
    /* 0x4 */ s32 field_4;
    /* 0x8 */ s32 field_8;
} Obj20CE8;

/* Buffer allocated into a container's field_38 by func_80020C40 (0x90 bytes via
 * func_80022F3C); only the fields it stamps are known. */
typedef struct {
    u8 _pad00[0x30];
    /* 0x30 */ s32 field_30;
    /* 0x34 */ s32 field_34;
    /* 0x38 */ s32 field_38;
    u8 _pad3C[0x06];
    /* 0x42 */ s16 field_42;
    u8 _pad44[0x04];
    /* 0x48 */ s32 field_48[3];
    u8 _pad54[0x04];
    /* 0x58 */ s32 field_58;
    /* 0x5C */ s32 field_5C;
    /* 0x60 */ s32 field_60;
    u8 _pad64[0x08];
    /* 0x6C */ Obj20CE8 field_6C[3];
} AllocC40;

/* Container whose field_38 holds an AllocC40* (func_80020C40's arg0). */
typedef struct {
    u8 _pad00[0x38];
    /* 0x38 */ AllocC40 *field_38;
} ContC40;

/* Buffer allocated + registered by func_800111D4 (in the D_80050798 list) and
 * populated by func_800113B8; only the pointer/count fields it writes are known. */
typedef struct {
    /* 0x00 */ u32 field_0;
    u8 _pad04[0x20];
    /* 0x24 */ s32 field_24;
    u8 _pad28[0x04];
    /* 0x2C */ s32 field_2C;
    /* 0x30 */ s32 field_30;
    /* 0x34 */ s32 field_34;
} Buf111D4;

/* Object type descriptor from the D_80040D50[id >> 8][id & 0xFF] table
   (func_8001107C): optional init callback and the two buffer sizes. */
typedef struct {
    /* 0x00 */ void (*init)(Buf111D4 *, s32);
    u8 _pad04[0x0C];
    /* 0x10 */ s32 field_10;
    /* 0x14 */ s32 field_14;
} ObjDesc;

/* 5-byte slot descriptor walked by func_80024A1C (Obj25FBC field_4). */
typedef struct {
    u8 _pad0[2];
    /* 0x02 */ u8 field_2;
    /* 0x03 */ u8 field_3;
    u8 _pad4;
} Slot24A1C;

/* Argument to func_80025FBC (byte/half fields deep in a large record). */
typedef struct Obj25FBC {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ Slot24A1C *field_4;
    /* 0x08 */ s32 field_8;
    /* 0x0C */ struct Obj25FBC *field_C;
    /* 0x10 */ void *field_10;
    /* 0x14 */ void (*field_14)(void *);
    /* 0x18 */ s32 (*field_18)(void *);
    u8 _pad1C[0xC];
    /* 0x28 */ u8 *field_28;
    /* 0x2C */ u8 *field_2C;
    /* 0x30 */ u8 *field_30;
    /* 0x34 */ u8 field_34;
    /* 0x35 */ u8 field_35;
    /* 0x36 */ u8 field_36;
    /* 0x37 */ u8 field_37;
    /* 0x38 */ u8 field_38;
    /* 0x39 */ u8 field_39;
    u8 _pad3A[0x2];
    /* 0x3C */ volatile u8 *field_3C;
    /* 0x40 */ u8 *field_40;
    /* 0x44 */ volatile u8 field_44;
    /* 0x45 */ u8 field_45;
    /* 0x46 */ u8 field_46;
    /* 0x47 */ u8 field_47;
    u8 _pad48[0x1];
    /* 0x49 */ u8 field_49;
    /* 0x4A */ u8 field_4A;
    u8 _pad4B[0x1];
    /* 0x4C */ s32 field_4C;
    /* 0x50 */ u8 field_50;
    u8 _pad51[0x6];
    /* 0x57 */ u8 field_57[6];
    /* 0x5D */ u8 field_5D[6];
    /* 0x63 */ u8 field_63[0x80];
    /* 0xE3 */ u8 field_E3;
    /* 0xE4 */ u8 field_E4;
    u8 _padE5[0x1];
    /* 0xE6 */ u16 field_E6;
    /* 0xE8 */ u8 field_E8;
    /* 0xE9 */ u8 field_E9;
    /* 0xEA */ u8 field_EA;
    /* 0xEB */ u8 field_EB;
    /* 0xEC */ u16 field_EC;
    /* 0xEE */ u16 field_EE;
} Obj25FBC;

/* Stride-0x28 array element written by func_8001D550: a flag byte at 0xE plus
 * two words at 0x10/0x14; field_0 is the loop guard (zero terminates). */
typedef struct {
    /* 0x00 */ s32 field_0;
    u8 _pad04[0xE - 0x4];
    /* 0x0E */ s8 field_E;
    u8 _pad0F[0x1];
    /* 0x10 */ s32 field_10;
    /* 0x14 */ s32 field_14;
    u8 _pad18[0x28 - 0x18];
} Ent1D550;

/* func_8002329C source record (stride 0x18): field_0/field_4 feed func_80023270
 * bit tests, field_10 is copied out, field_C is cleared on the disabled path. */
typedef struct {
    /* 0x0 */ s32 field_0;
    /* 0x4 */ s32 field_4;
    u8 _pad8[0x4];
    /* 0xC */ s32 field_C;
    /* 0x10 */ s32 field_10;
    u8 _pad14[0x4];
} Elm678; /* size 0x18 */

/* func_8002329C destination record (stride 0x40): 14 word slots filled from
 * func_80023270, three s16 copies at 0x38/0x3A/0x3C, and a flag at 0x3E. */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 field_8;
    /* 0x0C */ s32 field_C;
    /* 0x10 */ s32 field_10;
    /* 0x14 */ s32 field_14;
    /* 0x18 */ s32 field_18;
    /* 0x1C */ s32 field_1C;
    /* 0x20 */ s32 field_20;
    /* 0x24 */ s32 field_24;
    /* 0x28 */ s32 field_28;
    /* 0x2C */ s32 field_2C;
    /* 0x30 */ s32 field_30;
    /* 0x34 */ s32 field_34;
    /* 0x38 */ s16 field_38;
    /* 0x3A */ s16 field_3A;
    /* 0x3C */ s16 field_3C;
    /* 0x3E */ s16 field_3E;
} Elm6F0; /* size 0x40 */

/* func_8002329C control record (stride 0x22): field_0 is an enable flag, the
 * high nibble of field_1 selects the active mode. */
typedef struct {
    /* 0x0 */ u8 field_0;
    /* 0x1 */ u8 field_1;
    u8 _pad2[0x20];
} Elm6A8; /* size 0x22 */

/* Command block D_80062C18 handed to func_8003B994: field_0 is the command
 * id, the remaining fields are its arguments. */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s16 field_8;
    /* 0x0A */ s16 field_A;
    /* 0x0C */ s32 field_C;
    /* 0x10 */ s32 field_10;
} Cmd62C18; /* size 0x14 */

s32 func_8003B994(Cmd62C18 *cmd);

/* By-value argument block of the func_80032954 handler table entries
 * (void handler(s16, s16, s16, HandlerArg)). It starts in $a3 and continues on
 * the caller's stack, so the callee homes $a3 to keep it contiguous. Only the
 * fields matched so far are named. */
typedef struct {
    /* 0x00 */ u8 field_0;
    /* 0x01 */ u8 field_1;
    u8 _pad02[0x04];
    /* 0x06 */ u8 field_6;
    /* 0x07 */ u8 field_7;
    u8 _pad08[0x01];
    /* 0x09 */ u8 field_9;
    /* 0x0A */ u8 field_A;
    u8 _pad0B[0x05];
    /* 0x10 */ u16 field_10;
    /* 0x12 */ u16 field_12;
    u8 _pad14[0x10];
    /* 0x24 */ s32 field_24;
} HandlerArg;

/* Element of the per-slot arrays D_80061C50[slot] (stride 0xB0), indexed
 * D_80061C50[a0][a1] by the func_80032954 handler table and func_800354F4. */
typedef struct {
    u8 *field_0;        /* 0x00 */
    u8 *volatile field_4; /* 0x04 */
    s32 field_8;        /* 0x08 */
    u8 *volatile field_C; /* 0x0C */
    s32 field_10;       /* 0x10 */
    u8  field_14;       /* 0x14 */
    u8  field_15;       /* 0x15 */
    u8  field_16;       /* 0x16 */
    u8  field_17;       /* 0x17 */
    u8  field_18;       /* 0x18 */
    u8  field_19;       /* 0x19 */
    u8  field_1A;       /* 0x1A */
    u8  field_1B;       /* 0x1B */
    u8  field_1C;       /* 0x1C */
    u8  field_1D;       /* 0x1D */
    u8  field_1E;       /* 0x1E */
    u8  field_1F;       /* 0x1F */
    u8  field_20;       /* 0x20 */
    u8  field_21;       /* 0x21 */
    s8  field_22;       /* 0x22 */
    u8  field_23;       /* 0x23 */
    u8  field_24;       /* 0x24 */
    u8  field_25;       /* 0x25 */
    s8  field_26;       /* 0x26 */
    u8  field_27[0x10]; /* 0x27 */
    u8  field_37[0x10]; /* 0x37 */
    u8  _p47[0x1];      /* 0x47 */
    s16 field_48;       /* 0x48 */
    s16 field_4A;       /* 0x4A */
    s16 field_4C;       /* 0x4C */
    s16 field_4E;       /* 0x4E */
    s16 field_50;       /* 0x50 */
    s16 field_52;       /* 0x52 */
    s16 field_54;       /* 0x54 */
    s16 field_56;       /* 0x56 */
    u16 field_58;       /* 0x58 */
    u16 field_5A;       /* 0x5A */
    s16 field_5C;       /* 0x5C */
    s16 field_5E;       /* 0x5E */
    s16 field_60[0x10]; /* 0x60 */
    s16 field_80;       /* 0x80 */
    u8  _p82[0x2];      /* 0x82 */
    s32 field_84;       /* 0x84 */
    s32 field_88;       /* 0x88 */
    s32 field_8C;       /* 0x8C */
    s32 field_90;       /* 0x90 */
    s32 field_94;       /* 0x94 */
    s32 field_98;       /* 0x98 */
    s32 field_9C;       /* 0x9C */
    s32 field_A0;       /* 0xA0 */
    s32 field_A4;       /* 0xA4 */
    s32 field_A8;       /* 0xA8 */
    s32 field_AC;       /* 0xAC -> size 0xB0 */
} Elm354F4;

/* Bit-flag block pointed to by D_8004FC68; D_8004FC70[] holds the masks
 * func_80035458 / func_80035488 set and clear in field_4. */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
} Flags4FC68;

/* Callback table reached through D_8004FB80; the func_80030CD4..80030DF8
 * wrappers forward their arguments to one slot each. */
typedef struct {
    /* 0x00 */ void (*fn_0)();
    /* 0x04 */ void (*fn_4)();
    /* 0x08 */ void (*fn_8)();
    /* 0x0C */ void (*fn_C)();
    /* 0x10 */ void (*fn_10)();
    /* 0x14 */ void (*fn_14)();
    /* 0x18 */ void (*fn_18)();
} Vt4FB80;

/* Status block polled through D_80048E90 (func_80025C90 spins on bit 1 of
 * field_4). */
typedef struct {
    /* 0x00 */ volatile u8 field_0;
    u8 _pad01[0x3];
    /* 0x04 */ volatile u16 field_4;
    u8 _pad06[0x2];
    /* 0x08 */ u16 field_8;
    /* 0x0A */ u16 field_A;
    u8 _pad0C[0x2];
    /* 0x0E */ u16 field_E;
} Stat48E90;

/* Object reached through D_80050768; func_800143CC clears field_35C. */
typedef struct {
    /* 0x000 */ u32 field_0;
    /* 0x004 */ u32 field_4;
    u8 _pad008[0x100];
    /* 0x108 */ s16 field_108;
    /* 0x10A */ s16 field_10A;
    u8 _pad10C[0x4];
    /* 0x110 */ u8 *field_110;
    /* 0x114 */ u8 *field_114[3];
    /* 0x120 */ s16 field_120;
    /* 0x122 */ s16 field_122;
    /* 0x124 */ s16 field_124;
    /* 0x126 */ s16 field_126;
    /* 0x128 */ s32 field_128;
    u8 _pad12C[0x230];
    /* 0x35C */ s16 field_35C;
    /* 0x35E */ s16 field_35E;
    /* 0x360 */ s16 field_360;
} Obj50768;

/* Record initialised by func_8002AAB4 (four halfwords from the arguments, the
 * rest cleared). */
typedef struct {
    /* 0x00 */ s16 field_0;
    /* 0x02 */ s16 field_2;
    /* 0x04 */ s16 field_4;
    /* 0x06 */ s16 field_6;
    /* 0x08 */ s16 field_8;
    /* 0x0A */ s16 field_A;
    /* 0x0C */ s16 field_C;
    /* 0x0E */ s16 field_E;
    /* 0x10 */ u8 field_10;
    /* 0x11 */ u8 field_11;
    /* 0x12 */ u8 field_12;
    /* 0x13 */ u8 field_13;
} Rec2AAB4;

/* Element of D_800624E8[] (stride 0x38); func_800382D4 clears a slot. */
typedef struct {
    /* 0x00 */ s16 field_0;
    /* 0x02 */ u16 field_2;
    /* 0x04 */ s16 field_4;
    /* 0x06 */ u16 field_6;
    /* 0x08 */ s16 field_8;
    /* 0x0A */ u8 field_A;
    u8 _pad0B;
    /* 0x0C */ s16 field_C;
    /* 0x0E */ s16 field_E;
    /* 0x10 */ s16 field_10;
    /* 0x12 */ s16 field_12;
    /* 0x14 */ s16 field_14;
    /* 0x16 */ s16 field_16;
    /* 0x18 */ s16 field_18;
    /* 0x1A */ s16 field_1A;
    u8 _pad1C[0x1];
    /* 0x1D */ s8 field_1D;
    /* 0x1E */ s16 field_1E;
    /* 0x20 */ s16 field_20;
    /* 0x22 */ s16 field_22;
    /* 0x24 */ s16 field_24;
    /* 0x26 */ s16 field_26;
    u8 _pad28[0x2];
    /* 0x2A */ s16 field_2A;
    /* 0x2C */ s16 field_2C;
    /* 0x2E */ s16 field_2E;
    /* 0x30 */ s16 field_30;
    /* 0x32 */ s16 field_32;
    u8 _pad34[0x2];
    /* 0x36 */ s16 field_36;
} Elm624E8; /* size 0x38 */

/* Hook pair at D_8004FC50; func_800352E4 calls the optional fn_4, then fn_0. */
typedef struct {
    /* 0x00 */ void (*fn_0)(void);
    /* 0x04 */ void (*fn_4)(void);
} Hooks4FC50;

/* Object passed to the D_80048E30 callback by func_800266D0; field_3C points at
 * a status byte cleared after the call. */
typedef struct {
    u8 _pad00[0xC];
    /* 0x0C */ struct Slot267F0 *field_C;
    /* 0x10 */ void *field_10;
    u8 _pad14[0x1C];
    /* 0x30 */ u8 *field_30;
    u8 _pad34[0x3];
    /* 0x37 */ u8 field_37;
    /* 0x38 */ u8 field_38;
    /* 0x39 */ u8 field_39;
    u8 _pad3A[0x2];
    /* 0x3C */ u8 *field_3C;
    /* 0x40 */ u8 *field_40;
    /* 0x44 */ u8 field_44;
    /* 0x45 */ u8 field_45;
} Ent266D0;

/* Block reached through D_8005071C; func_80011F04 compacts the 12 slot bytes at
 * 0xBA9 (nonzero entries moved to the front, the rest cleared). */
typedef struct {
    /* 0x000 */ u8 field_0;
    u8 _pad001[0xBA4];
    /* 0xBA5 */ u8 field_BA5[3];
    /* 0xBA8 */ u8 field_BA8;
    /* 0xBA9 */ u8 field_BA9[12];
} Blk5071C;

/* Sound state block at D_80062D18 (splat splits it into small byte symbols);
 * func_80037BD0 indexes the D_80062D08 table with field_7 * 16 + field_C. */
typedef struct {
    /* 0x00 */ s8 field_0;
    /* 0x01 */ s8 field_1;
    /* 0x02 */ s8 field_2;
    /* 0x03 */ s8 field_3;
    /* 0x04 */ s8 field_4;
    /* 0x05 */ u8 field_5;
    /* 0x06 */ s8 field_6;
    /* 0x07 */ s8 field_7;
    u8 _pad8[0x2];
    /* 0x0A */ s8 field_A;
    /* 0x0B */ u8 field_B;
    /* 0x0C */ u8 field_C;
    /* 0x0D */ s8 field_D;
    /* 0x0E */ u8 field_E;
    /* 0x0F */ u8 field_F;
    /* 0x10 */ u8 field_10;
    /* 0x11 */ u8 field_11;
    /* 0x12 */ u8 field_12;
    u8 _pad13[0x1];
    /* 0x14 */ s16 field_14;
    /* 0x16 */ s16 field_16;
    /* 0x18 */ s16 field_18;
} Snd62D18;

/* 0x20-byte record in the table D_80062D08 points at. */
typedef struct {
    /* 0x00 */ u8 field_0;
    /* 0x01 */ u8 field_1;
    /* 0x02 */ u8 field_2;
    /* 0x03 */ u8 field_3;
    /* 0x04 */ u8 field_4;
    /* 0x05 */ u8 field_5;
    /* 0x06 */ u8 field_6;
    /* 0x07 */ u8 field_7;
    /* 0x08 */ u8 field_8;
    /* 0x09 */ u8 field_9;
    /* 0x0A */ u8 field_A;
    /* 0x0B */ u8 field_B;
    /* 0x0C */ u8 field_C;
    /* 0x0D */ u8 field_D;
    u8 _padE[0x2];
    /* 0x10 */ u16 field_10;
    /* 0x12 */ u16 field_12;
    /* 0x14 */ u16 field_14;
    /* 0x16 */ u16 field_16;
    u8 _pad18[0x8];
} Rec62D08;


/* Two-word state func_8001291C copies into the head of an ActorWork. */
typedef struct {
    /* 0x0 */ s32 field_0;
    /* 0x4 */ s32 field_4;
} Pair1291C;

/* func_8002AB54 builds a GPU move-image packet (PsyQ SetDrawMove shape):
 * Rect2AB54 is the 16-bit source rectangle, DrMove2AB54 the tagged packet. */
typedef struct {
    /* 0x0 */ s16 x;
    /* 0x2 */ s16 y;
    /* 0x4 */ s16 w;
    /* 0x6 */ s16 h;
} Rect2AB54;
typedef struct {
    /* 0x00 */ u8 _pad00[3];
    /* 0x03 */ u8 len;
    /* 0x04 */ u32 code[5];
} DrMove2AB54;

/* Status words behind D_80048E8C; func_80025144 checks bit 0 of both. */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
} Regs48E8C;

/* State block at D_80062F80 armed by func_8003E134 (field_0 = 2, arg in
 * field_10) before it pushes func_8003E19C as a state handler. */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 field_8;
    /* 0x0C */ s32 field_C;
    /* 0x10 */ s32 field_10;
    /* 0x14 */ s32 field_14;
    /* 0x18 */ s32 field_18;
    /* 0x1C */ s32 field_1C;
    /* 0x20 */ s32 field_20;
    /* 0x24 */ u8 field_24[0x20];
    /* 0x44 */ s32 field_44;
    /* 0x48 */ s32 field_48[2];
    /* 0x50 */ s32 field_50[2];
} State62F80;

/* Stack command block passed to func_8003D124 (built by func_80034F64 /
 * 80035024 / 800356D4): field_0 is a command/flag word. */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s16 field_4;
    /* 0x06 */ s16 field_6;
    /* 0x08 */ s16 field_8;
    /* 0x0A */ s16 field_A;
    u8 _pad0C[0x04];
    /* 0x10 */ s16 field_10;
    /* 0x12 */ s16 field_12;
    /* 0x14 */ s32 field_14;
    /* 0x18 */ s32 field_18;
    /* 0x1C */ s16 field_1C;
    /* 0x1E */ s16 field_1E;
    /* 0x20 */ s32 field_20;
    /* 0x24 */ s32 field_24;
} Cmd3D124;
void func_8003D124(Cmd3D124 *);

/* Record handed to func_80027A18: a count byte at 0x3 and the data it counts
 * from 0x4 (passed to D_80048F08->fn_14). */
typedef struct {
    u8 _pad00[0x03];
    /* 0x03 */ u8 field_3;
    /* 0x04 */ u8 field_4[1];
} Ent27A18;

/* Two-word header func_8003AD44 fills and publishes through D_8004FE90. */
typedef struct {
    /* 0x0 */ u32 field_0;
    /* 0x4 */ s32 field_4;
} Hdr3AD44;

/* (id, arg) pair; func_80022388 walks six of them, -1 id = unused slot. */
typedef struct {
    /* 0x0 */ s16 field_0;
    /* 0x2 */ s16 field_2;
} Pair22388;

/* State blocks reset by func_8002ADE4. */
typedef struct {
    /* 0x0 */ s16 field_0;
    /* 0x2 */ u8 field_2;
    /* 0x3 */ u8 field_3;
    /* 0x4 */ u8 field_4;
} St6191C;

typedef struct {
    /* 0x0 */ s16 field_0;
    /* 0x2 */ s16 field_2;
    u8 _pad04[0x08];
    /* 0xC */ u8 field_C;
    /* 0xD */ u8 field_D;
} St6196C;

/* Object whose handle array (count at 0x30, array at 0x34) func_80010E38
 * walks through func_80010F24. */
typedef struct {
    u8 _pad00[0x30];
    /* 0x30 */ s32 field_30;
    /* 0x34 */ s32 *field_34;
} Obj10E38;

/* 16-byte slot record in the D_80062CFC array. */
typedef struct {
    /* 0x0 */ u8 field_0;
    /* 0x1 */ u8 field_1;
    /* 0x2 */ u8 field_2;
    /* 0x3 */ u8 field_3;
    /* 0x4 */ u8 field_4;
    u8 _pad05[0x1];
    /* 0x6 */ u16 field_6;
    /* 0x8 */ u8 field_8;
    u8 _pad09[0x03];
    /* 0xC */ u16 field_C;
    /* 0xE */ u16 field_E;
} Ent62CFC;

/* s16 pair at D_80061900 filled by func_8002B4C4 and handed to func_8002B1A4. */
typedef struct {
    /* 0x0 */ s16 field_0;
    /* 0x2 */ s16 field_2;
} Pair61900;

/* 16-bit rectangle func_800288A0 packs into a texture-window command. */
typedef struct {
    /* 0x0 */ s16 x;
    /* 0x2 */ s16 y;
    /* 0x4 */ s16 w;
    /* 0x6 */ s16 h;
} Rect288A0;

/* Grid menu: cursor at 0x54, dimensions at 0x58, 6-byte cells from 0x72
   (cell index = func_80013A70(cursor, dims)). */
typedef struct {
    /* 0x00 */ u16 field_0;
    u8 _pad02[0x04];
} GridCell;

typedef struct {
    u8 _pad00[0x54];
    /* 0x54 */ s16 field_54[2];
    /* 0x58 */ s16 field_58[2];
    u8 _pad5C[0x16];
    /* 0x72 */ GridCell field_72[16];
} GridMenu;

/* GPU drawing environment (libgpu DRAWENV layout, 0x1C head); filled by
   func_8002A9F4. */
typedef struct {
    /* 0x00 */ s16 clip_x;
    /* 0x02 */ s16 clip_y;
    /* 0x04 */ s16 clip_w;
    /* 0x06 */ s16 clip_h;
    /* 0x08 */ s16 ofs[2];
    /* 0x0C */ s16 tw_x;
    /* 0x0E */ s16 tw_y;
    /* 0x10 */ s16 tw_w;
    /* 0x12 */ s16 tw_h;
    /* 0x14 */ u16 tpage;
    /* 0x16 */ u8 dtd;
    /* 0x17 */ u8 dfe;
    /* 0x18 */ u8 isbg;
    /* 0x19 */ u8 r0;
    /* 0x1A */ u8 g0;
    /* 0x1B */ u8 b0;
    /* 0x1C */ u32 dr_env[16];
} DrawEnv;

/* Zero-terminated list entry walked by func_80013558: low 12 bits of `key` pick
   the 0x1FD resource, bits 12-15 are mode flags; `h` is forwarded by value. */
typedef struct {
    /* 0x0 */ s32 key;
    /* 0x4 */ Halves h;
} Key13558;

/* 6-byte map cell record in the func_800166FC grid (field_0 = item id). */
typedef struct {
    /* 0x0 */ u16 field_0;
    u8 _pad2[0x2];
    /* 0x4 */ u16 field_4;
} Cell166FC;

/* Map object walked by func_800166FC: cursor (0x54) and size (0x58) s16 pairs
 * index the cell grid at 0x72. */
typedef struct {
    u8 _pad00[0x40];
    /* 0x40 */ s32 field_40;
    /* 0x44 */ u8 field_44[0x10];
    /* 0x54 */ s16 field_54[2];
    /* 0x58 */ s16 field_58[2];
    u8 _pad5C[0x8];
    /* 0x64 */ s16 field_64;
    /* 0x66 */ s16 field_66;
    u8 _pad68[0xA];
    /* 0x72 */ Cell166FC field_72[1];
} Obj166FC;

/* Global D_8004EAF8: one-shot stream state opened by func_800312F8. */
typedef struct {
    /* 0x00 */ u16 field_0;
    /* 0x02 */ u16 field_2;
    /* 0x04 */ s32 field_4[11];
    /* 0x30 */ u16 field_30;
    /* 0x32 */ u16 field_32;
    /* 0x34 */ s32 field_34;
    /* 0x38 */ s32 field_38[12];
    /* 0x68 */ s32 stack[0x3EC];
    /* 0x1018 */ s32 stack_top[0x14];
} Obj4EAF8;

/* Work block (Actor.work) of the actor state machine func_800116CC:
 * field_8 = step counter, field_C = pose id, field_10 = delay, field_14 = sub. */
typedef struct {
    u8 _pad00[0x8];
    /* 0x08 */ s32 field_8;
    /* 0x0C */ s32 field_C;
    /* 0x10 */ s32 field_10;
    /* 0x14 */ s32 field_14;
} Wk116CC;

/* Three status bytes at D_8004E9A4 reset by func_8002FCF4 (field_0 = 2,
 * field_1/field_2 cleared). */
typedef struct {
    /* 0x00 */ u8 field_0;
    /* 0x01 */ u8 field_1;
    /* 0x02 */ u8 field_2;
    /* 0x03 */ u8 field_3[6];
} Cd4E9A4;

/* Word pair at *D_80048DF0: func_80024544 writes -2 to 0x0 and sets bit 0 of 0x4. */
typedef struct {
    /* 0x0 */ volatile s32 field_0;
    /* 0x4 */ volatile s32 field_4;
} Reg48DF0;

/* Two-word state D_80060058, cleared by func_80024544. */
typedef struct {
    /* 0x0 */ s32 field_0;
    /* 0x4 */ s32 field_4;
} State60058;

/* One selectable entry of the Work174F8 menu (8 bytes). */
typedef struct {
    /* 0x0 */ u8 field_0;
    u8 _pad1[0x1];
    /* 0x2 */ u8 field_2;
    u8 _pad3[0x1];
    /* 0x4 */ s32 field_4;
} Sel174F8;

/* Actor work block while func_800174F8's menu is active: cursor pos/size
 * pairs at 0x50/0x54 and the entry table at 0x6C. */
typedef struct {
    u8 _pad00[0x40];
    /* 0x40 */ u8 field_40[0x10];
    /* 0x50 */ s16 field_50[2];
    /* 0x54 */ s16 field_54[2];
    u8 _pad58[0x0A];
    /* 0x62 */ s16 field_62;
    u8 _pad64[0x08];
    /* 0x6C */ Sel174F8 field_6C[38];
    /* 0x19C */ s16 field_19C;
    /* 0x19E */ s16 field_19E;
    /* 0x1A0 */ s16 field_1A0[1];
} Work174F8;

/* 0x10-byte state block at D_8004FDCC cleared by func_8003A054. */
typedef struct {
    /* 0x0 */ s32 field_0;
    /* 0x4 */ s16 field_4;
    /* 0x6 */ s16 field_6;
    /* 0x8 */ s32 field_8;
    /* 0xC */ s32 field_C;
} Blk4FDCC;

/* 0x38-byte record in the table at D_800624F8 (field_0 = id, matched by
 * func_800391B4). */
typedef struct {
    /* 0x00 */ s16 field_0;
    u8 _pad2[0x36];
} Rec624F8;

/* 0x28-byte model part record; lists end at field_0 == 0 (func_8001373C, func_800137B8). */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s16 field_4;
    /* 0x06 */ s16 field_6;
    u8 _pad8[4];
    /* 0x0C */ u8 field_C;
    /* 0x0D */ u8 field_D;
    u8 _padE[0x1];
    /* 0x0F */ u8 field_F;
    u8 _pad10[0xC];
    /* 0x1C */ s32 field_1C;
    u8 _pad20[8];
} Part28;

/* Static GPU packets at D_80048F9C; the VRAM-to-VRAM move packet (tag, GP0
 * 0x80 command, source xy, destination xy, size) starts at 0xC. */
typedef struct {
    /* 0x00 */ u16 field_0[3][2];
    /* 0x0C */ u32 move[5];
} Pkt48F9C;

/* Register block reached through the pointer at D_800506BC. */
typedef struct {
    u8 _pad0[0xA];
    /* 0xA */ s16 field_A;
} Reg506BC;

/* GPU display environment (libgpu DISPENV layout) at D_80061968, set up by
   func_8002ACC8 and applied by func_80027CB0. */
typedef struct {
    /* 0x00 */ Rect2AB54 disp;
    /* 0x08 */ Rect2AB54 screen;
    /* 0x10 */ u8 isinter;
    /* 0x11 */ u8 isrgb24;
    /* 0x12 */ u8 pad0;
    /* 0x13 */ u8 pad1;
} DispEnv;

/* 16-byte GPU fill-rectangle packets at D_800618D0, one per display buffer
 * (libgpu BLK_FILL shape): tag, r g b code, x0 y0 w h. */
typedef struct {
    /* 0x0 */ u8 tag[3];
    /* 0x3 */ u8 len;
    /* 0x4 */ u8 r;
    /* 0x5 */ u8 g;
    /* 0x6 */ u8 b;
    /* 0x7 */ u8 code;
    /* 0x8 */ u16 x0;
    /* 0xA */ u16 y0;
    /* 0xC */ u16 w;
    /* 0xE */ u16 h;
} BlkFill618D0;

/* Per-buffer draw context handed to func_8002B06C; the ot pointer sits at 0x10. */
typedef struct {
    u8 _pad00[0x10];
    /* 0x10 */ u32 *ot;
} Db2B06C;

/* 8-byte copy of an Ent62CFC head filled by func_80036054. */
typedef struct {
    /* 0x0 */ u8 field_0;
    /* 0x1 */ u8 field_1;
    /* 0x2 */ u8 field_2;
    /* 0x3 */ u8 field_3;
    /* 0x4 */ u8 field_4;
    u8 _pad05[0x1];
    /* 0x6 */ u16 field_6;
} SlotHead8;

/* State block at D_8005CCF8; field_60 selects the row of the slot tables
 * read by func_8001C760. */
typedef struct {
    u8 _pad0[0x60];
    /* 0x60 */ s32 field_60;
} Mode5CCF8;

/* 0x1C-byte parameter block copied from D_80040F64 into Wk18BF8.field_CC. */
typedef struct {
    s32 w[7];
} Prm1C;

/* View of Actor.work set up by func_80018BF8 (fields 0x7C..0x14C). */
typedef struct {
    u8 _pad00[0x7C];
    /* 0x7C */ s16 field_7C;
    u8 _pad7E[0x6];
    /* 0x84 */ u8 *field_84;
    u8 _pad88[0x28];
    /* 0xB0 */ s32 field_B0[3];
    /* 0xBC */ u16 field_BC;
    u8 _padBE[0x2];
    /* 0xC0 */ s32 field_C0;
    /* 0xC4 */ s32 field_C4;
    /* 0xC8 */ s32 field_C8;
    /* 0xCC */ Prm1C field_CC;
    /* 0xE8 */ s32 field_E8;
    u8 _padEC[0x4C];
    /* 0x138 */ s16 field_138;
    u8 _pad13A[0x6];
    /* 0x140 */ s16 field_140;
    /* 0x142 */ s16 field_142;
    /* 0x144 */ s16 field_144;
    u8 _pad146[0x2];
    /* 0x148 */ s32 field_148;
    /* 0x14C */ s32 field_14C;
} Wk18BF8;

/* Per-channel hook table D_80061CD0[ch][16] run by func_80033424. */
typedef void (*Hook33424)(s16, s16, u8);

/* DR_ENV packet built by func_800282CC: tag word (length byte at 3) then
   up to 15 GPU command words, addressed as one word array. */
typedef union {
    /* 0x00 */ u32 w[16];
    struct {
        u8 _pad0[3];
        /* 0x03 */ u8 len;
    } h;
} DrEnv282CC;

/* Clip rect copied as two words into the DR_ENV fill command. */
typedef union {
    struct {
        s16 x;
        s16 y;
        s16 w;
        s16 h;
    } r;
    u32 w[2];
} Rect282CC;

/* One 6-byte icon grid cell: item id, count, sound/effect arg. */
typedef struct {
    /* 0x0 */ u16 field_0;
    /* 0x2 */ s16 field_2;
    /* 0x4 */ s16 field_4;
} Cell16198;

/* Grid size pair plus the rest of the 12-byte layout record copied from resource 0x5130017. */
typedef struct {
    /* 0x0 */ s16 field_0[2];
    /* 0x4 */ s16 field_4[4];
} Box16198;

/* Icon grid page: 16 sprite slots, item count/page at 0x6C/0x6E, 6-byte
   cells from 0x72 (id, count) and 4-byte count text buffers at 0x702. */
typedef struct {
    /* 0x000 */ s32 field_0[16];
    /* 0x040 */ s32 field_40;
    /* 0x044 */ s32 field_44;
    u8 _pad48[0x4];
    /* 0x04C */ s32 field_4C;
    u8 _pad50[0x4];
    /* 0x054 */ s16 field_54[2];
    /* 0x058 */ Box16198 field_58;
    /* 0x064 */ s16 field_64;
    /* 0x066 */ s16 field_66;
    /* 0x068 */ s32 field_68;
    /* 0x06C */ s16 field_6C;
    /* 0x06E */ s16 field_6E;
    /* 0x070 */ s16 field_70;
    /* 0x072 */ Cell16198 field_72[280];
    /* 0x702 */ u8 field_702[16][4];
} Obj16198;

/* Src13470 view with the position pair stored as one Halves. */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ u8 *field_8;
    /* 0x0C */ Halves field_C;
    /* 0x10 */ u8 field_10;
    /* 0x11 */ u8 field_11;
} Src16198;

/* 0x64-stride zero-terminated table (func_80023A08(0xC6F)) searched by
 * func_8001DB18 for the record whose leading id byte matches. */
typedef struct {
    /* 0x00 */ u8 field_0;
    u8 _pad01[0x63];
} Rec1DB18;

/* Status word pair behind the D_800506C0 pointer (func_8003D850). */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
} Flags506C0;

/* Record listed in Wk14CBC.field_A0 (func_80014CBC). */
typedef struct {
    u8 _pad00[0x0D];
    /* 0x0D */ u8 field_D;
    u8 _pad0E[0x06];
    /* 0x14 */ s16 field_14;
    /* 0x16 */ s16 field_16;
    /* 0x18 */ s16 field_18;
    /* 0x1A */ s16 field_1A;
    u8 _pad1C[0x30];
    /* 0x4C */ u8 field_4C[14];
} Rec14CBC;

/* Three sprite slots cleared together by func_80014984. */
typedef struct {
    /* 0x0 */ s32 a;
    /* 0x4 */ s32 b;
    /* 0x8 */ s32 c;
} Trip14984;

/* Actor work block read by func_80014CBC. */
typedef struct {
    /* 0x00 */ s32 field_0[7];
    /* 0x1C */ Trip14984 field_1C[3];
    /* 0x40 */ s32 field_40[6];
    /* 0x58 */ s32 field_58[4];
    u8 _pad68[0x08];
    /* 0x70 */ s32 field_70;
    /* 0x74 */ s32 field_74[11];
    /* 0xA0 */ Rec14CBC *field_A0[3];
    /* 0xAC */ s16 field_AC;
} Wk14CBC;

/* Object behind the D_80050720 pointer (func_80014CBC). */
typedef struct {
    /* 0x00 */ u8 field_0;
    u8 _pad01[0x07];
    /* 0x08 */ s32 field_8;
    u8 _pad0C[0x05];
    /* 0x11 */ u8 field_11;
    /* 0x12 */ u8 field_12;
    u8 _pad13[0x01];
    /* 0x14 */ u8 field_14[0x10];
    /* 0x24 */ s16 field_24;
    /* 0x26 */ s16 field_26;
    /* 0x28 */ s16 field_28;
    /* 0x2A */ s16 field_2A;
    /* 0x2C */ u16 field_2C[4];
    /* 0x34 */ u16 field_34;
    u8 _pad36[0x1C];
    /* 0x52 */ u8 field_52[0x14];
    /* 0x66 */ u16 field_66[0x30];
    u8 _padC6[0x0B];
    /* 0xD1 */ u8 field_D1[0x13];
    /* 0xE4 */ ElmE620 elems[0x24];
    /* 0xDD4 */ u16 field_DD4[0x100];
} Obj50720;

/* Record behind Ent17D84.field_4: an id byte at 0x01, a name at 0x4C. */
typedef struct {
    u8 _pad00[0x01];
    /* 0x01 */ u8 field_1;
    u8 _pad02[0x4A];
    /* 0x4C */ u8 field_4C[4];
} Sub17D84;

/* 8-byte row of the list page func_80017D84 draws. */
typedef struct {
    /* 0x00 */ u8 field_0;
    /* 0x01 */ u8 field_1;
    u8 _pad02[0x02];
    /* 0x04 */ Sub17D84 *field_4;
} Ent17D84;

/* List page: 16 sprite slots, first visible row at 0x68, rows from 0x6C. */
typedef struct {
    /* 0x00 */ s32 field_0[16];
    u8 _pad40[0x28];
    /* 0x68 */ s16 field_68;
    u8 _pad6A[0x02];
    /* 0x6C */ Ent17D84 field_6C[1];
} Obj17D84;

/* 12-byte record in the func_80019BF4 work view (s16 at +2 compared against field_94). */
typedef struct {
    /* 0x0 */ s16 field_0;
    /* 0x2 */ s16 field_2;
    u8 _pad4[0x8];
} Rec19BF4;

/* 0x1A-byte record in the func_80019BF4 work view; only the leading s16 is read. */
typedef struct {
    /* 0x00 */ s16 field_0;
    u8 _pad2[0x18];
} Slot19BF4;

/* View of Actor.work used by func_80019BF4 (four slots indexed by field_114). */
typedef struct {
    u8 _pad00[0x54];
    /* 0x54 */ Pair54 field_54[4];
    /* 0x64 */ Rec19BF4 field_64[4];
    /* 0x94 */ s32 field_94[4];
    u8 _padA4[0x4];
    /* 0xA8 */ s32 field_A8;
    /* 0xAC */ Slot19BF4 field_AC[4];
    /* 0x114 */ s32 field_114;
} Wk19BF4;

/* One 0x1E-byte row of the func_8001DB18 table as func_8001DDA8 reads it
   (rows start 8 bytes into the table; field_12 is a 4x3 byte matrix). */
typedef struct {
    /* 0x00 */ u16 field_0;
    /* 0x02 */ u16 field_2;
    /* 0x04 */ u16 field_4;
    /* 0x06 */ s16 field_6;
    /* 0x08 */ u16 field_8;
    /* 0x0A */ u8 field_A;
    /* 0x0B */ u8 field_B;
    /* 0x0C */ u16 field_C;
    /* 0x0E */ u8 field_E;
    /* 0x0F */ u8 field_F;
    /* 0x10 */ u8 field_10;
    /* 0x11 */ u8 field_11;
    /* 0x12 */ u8 field_12[4][3];
} Row1DDA8; /* 0x1E */

typedef struct {
    u8 _pad00[0x8];
    /* 0x08 */ Row1DDA8 rows[1];
} Tbl1DDA8;

/* Second output record of func_8001DDA8. */
typedef struct {
    /* 0x00 */ u16 field_0;
    /* 0x02 */ u8 field_2;
    /* 0x03 */ u8 field_3;
    /* 0x04 */ u8 field_4;
    /* 0x05 */ u8 field_5[4];
    /* 0x09 */ u8 field_9[4];
    /* 0x0D */ u8 field_D[4];
} Out1DDA8;

/* func_8001CE9C: sprite-list record (arg0), its 0x10-stride part list, the
 * D_8005CD60 texture slot view and the SPRT + DR_TPAGE packets it emits. */
typedef struct {
    /* 0x0 */ u8 r;
    /* 0x1 */ u8 g;
    /* 0x2 */ u8 b;
    /* 0x3 */ u8 code;
} Col1CE9C;

typedef struct {
    /* 0x0 */ s32 field_0;
    /* 0x4 */ u16 field_4;
    /* 0x6 */ u16 field_6;
    /* 0x8 */ Col1CE9C field_8;
    /* 0xC */ u8 field_C;
    /* 0xD */ u8 field_D;
    u8 _padE[2];
    /* 0x10 */ s32 field_10;
    /* 0x14 */ s32 field_14;
} Obj1CE9C;

typedef struct {
    /* 0x0 */ u8 field_0;
    /* 0x1 */ u8 field_1;
    /* 0x2 */ u16 field_2;
    /* 0x4 */ u16 field_4;
    /* 0x6 */ u8 field_6;
    /* 0x7 */ u8 field_7;
    /* 0x8 */ u8 field_8;
    /* 0x9 */ u8 field_9;
    /* 0xA */ u8 field_A;
    /* 0xB */ u8 field_B;
    /* 0xC */ u8 field_C;
    u8 _padD[3];
} Ent1CE9C;

typedef struct {
    u8 _pad0[8];
    /* 0x08 */ s32 field_8;
    /* 0x0C */ u8 field_C;
    u8 _padD[3];
    /* 0x10 */ u16 field_10;
    u8 _pad12[2];
    /* 0x14 */ u16 field_14;
    u8 _pad16[2];
    /* 0x18 */ s32 field_18;
    /* 0x1C */ u16 field_1C;
} Tex1CE9C;

typedef struct {
    u32 addr : 24;
    u32 len : 8;
} Tag1CE9C;

typedef struct {
    /* 0x00 */ Tag1CE9C tag;
    /* 0x04 */ Col1CE9C c;
    /* 0x08 */ s16 x0;
    /* 0x0A */ s16 y0;
    /* 0x0C */ u8 u0;
    /* 0x0D */ u8 v0;
    /* 0x0E */ u16 clut;
    /* 0x10 */ s16 w;
    /* 0x12 */ s16 h;
} Sprt1CE9C;

typedef struct {
    /* 0x0 */ Tag1CE9C tag;
    /* 0x4 */ u32 code;
} Tpage1CE9C;

typedef union {
    Sprt1CE9C s;
    Tpage1CE9C t;
} Pkt1CE9C;

/* Rectangle func_80028E84 clips and sends as two command words. */
typedef union {
    struct {
        s16 x;
        s16 y;
        s16 w;
        s16 h;
    } r;
    s32 w[2];
} Rect28E84;

/* Primitive tag: next-pointer (24 bits) + word count (8 bits), PsyQ P_TAG shape. */
typedef struct {
    u32 addr : 24;
    u32 len : 8;
} Tag1F668;

/* Byte colour + GPU code, copied as a 4-byte unaligned struct. */
typedef struct {
    u8 r;
    u8 g;
    u8 b;
    u8 code;
} Col1F668;

typedef struct {
    s16 x;
    s16 y;
} XY1F668;

/* Flat quad packet (PsyQ POLY_F4 shape). */
typedef struct {
    /* 0x00 */ Tag1F668 tag;
    /* 0x04 */ Col1F668 c;
    /* 0x08 */ XY1F668 xy[4];
} PolyF4_1F668; /* size 0x18 */

/* Draw-mode packet (PsyQ DR_MODE shape). */
typedef struct {
    /* 0x00 */ Tag1F668 tag;
    /* 0x04 */ u32 code[2];
} DrMode1F668; /* size 0xC */

/* Model-space vertex (PsyQ SVECTOR shape). */
typedef struct {
    s16 vx;
    s16 vy;
    s16 vz;
    s16 pad;
} SVec1F668; /* size 0x8 */

/* 3x3 rotation + translation (PsyQ MATRIX shape). */
typedef struct {
    s16 m[3][3];
    s32 t[3];
} Mat1F668; /* size 0x20 */

/* Coordinate system func_8002B424 initialises (PsyQ GsCOORDINATE2 shape). */
typedef struct Coord1F668 {
    /* 0x00 */ s32 flg;
    /* 0x04 */ Mat1F668 coord;
    /* 0x24 */ Mat1F668 workm;
    /* 0x44 */ s32 param;
    /* 0x48 */ struct Coord1F668 *super;
    /* 0x4C */ struct Coord1F668 *sub;
} Coord1F668; /* size 0x50 */

/* Actor work view used by func_800141D4 (part list animation). */
typedef struct {
    u8 _pad00[0x20];
    /* 0x20 */ s32 field_20;
    /* 0x24 */ s16 field_24;
    u8 _pad26[0xE];
    /* 0x34 */ s32 field_34;
} Work141D4;


/* 12-byte heap block header (func_80022E60): prev, next, in-use flag. */
typedef struct Blk22E60 {
    /* 0x0 */ struct Blk22E60 *field_0;
    /* 0x4 */ struct Blk22E60 *field_4;
    /* 0x8 */ s32 field_8;
} Blk22E60;

/* 6-byte rank table at D_80050724, indexed by ElmE620.field_0 (func_80022AE4). */
typedef struct {
    u8 b[6];
} Tbl50724;

/* View of D_8005F770 as the frame/display state (func_80023484, func_80023550). */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 field_8;
    /* 0x0C */ s32 field_C;
    u8 _pad10[0x04];
    /* 0x14 */ s32 field_14;
    /* 0x18 */ s32 field_18;
    /* 0x1C */ s32 field_1C;
    /* 0x20 */ s32 field_20;
    /* 0x24 */ s32 field_24;
    /* 0x28 */ s32 field_28;
    u8 _pad2C[0x04];
    /* 0x30 */ DrawEnv draw[2];
    /* 0xE8 */ DispEnv disp[2];
    /* 0x110 */ s32 field_110;
    /* 0x114 */ s32 field_114;
} Db5F770;
/* Load header filled by func_8002BBD4 (func_80023550 reads field_C). */
typedef struct {
    s32 field_0;
    s32 field_4;
    s32 field_8;
    /* 0x0C */ s32 field_C;
    s32 field_10[4];
} Hdr23550;
/* Clear rectangle for func_80027604. */
typedef struct {
    s16 x;
    s16 y;
    s16 w;
    s16 h;
} Rect23550;

/* Menu work block behind Actor.work for the item-use menu (func_80014EA4..func_80015914). */
typedef struct {
    /* 0x00 */ s32 field_0[20];
    /* 0x50 */ s32 field_50;
    /* 0x54 */ s32 field_54;
    /* 0x58 */ s32 field_58;
    /* 0x5C */ s32 field_5C;
    u8 _pad60[0x10];
    /* 0x70 */ s32 field_70;
    u8 _pad74[0x14];
    /* 0x88 */ s16 field_88[2];
    /* 0x8C */ s16 field_8C[2];
    u8 _pad90[0x8];
    /* 0x98 */ s16 field_98;
    u8 _pad9A[0x2];
    /* 0x9C */ s32 field_9C;
} Wk14EA4;

/* 12-byte menu layout record (func_800239A0(0x5130010)) copied over Wk14EA4 0x8C..0x97. */
typedef struct {
    s16 field_0[6];
} Layout8C;

/* Ordering-table entry (PsyQ P_TAG shape): 24-bit next address + length. */
typedef struct {
    u32 addr : 24;
    u32 len : 8;
} OTag;

/* Title/main menu work block behind Actor.work (func_80013C04). */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 field_8;
    /* 0x0C */ s32 field_C;
    /* 0x10 */ s32 field_10;
    /* 0x14 */ s32 field_14;
    /* 0x18 */ s32 field_18;
    u8 _pad1C[0x4];
    /* 0x20 */ s16 field_20[2];
    /* 0x24 */ s16 field_24[2];
    u8 _pad28[0xA];
    /* 0x32 */ s16 field_32;
    /* 0x34 */ s32 field_34;
} Wk13C04;

typedef struct {
    /* 0x00 */ u8 field_0;
    /* 0x01 */ u8 field_1;
    /* 0x02 */ s16 field_2;
} Rec12490;

typedef struct {
    u8 _pad00[0xE];
    /* 0x0E */ u8 field_E;
    u8 _pad0F;
    /* 0x10 */ s32 field_10;
    /* 0x14 */ s16 field_14;
    /* 0x16 */ s16 field_16;
    /* 0x18 */ s16 field_18;
    /* 0x1A */ s16 field_1A;
    /* 0x1C */ s16 field_1C;
    /* 0x1E */ s16 field_1E;
    /* 0x20 */ s16 field_20;
} Dg12490;

/* Icon sheet layout (0x20 bytes) copied out by func_80011BEC; 0x18/0x1C are the
 * VRAM base of the icon page. */
typedef struct {
    u8 _pad00[0xC];
    /* 0x0C */ s32 field_C;
    /* 0x10 */ s32 field_10;
    u8 _pad14[0x4];
    /* 0x18 */ s32 field_18;
    /* 0x1C */ s32 field_1C;
} Tex11BEC;

/* One cached icon slot: resource id and last-use stamp. */
typedef struct {
    /* 0x0 */ s32 id;
    /* 0x4 */ s32 t;
} Slot11BEC;

/* Icon cache (work of the type-10 actor): layout plus 18 VRAM slots. */
typedef struct {
    /* 0x00 */ Tex11BEC *field_0;
    /* 0x04 */ Slot11BEC slot[18];
} Tbl11BEC;

/* TIM block: byte length, VRAM rectangle, pixel data. */
typedef struct {
    /* 0x0 */ s32 bnum;
    /* 0x4 */ s16 x;
    /* 0x6 */ s16 y;
    /* 0x8 */ s16 w;
    /* 0xA */ s16 h;
    /* 0xC */ u32 data[1];
} TimBlk11BEC;

/* s16 coordinate pair written back by func_80011BEC. */
typedef struct {
    /* 0x0 */ s16 x;
    /* 0x2 */ s16 y;
} Pt11BEC;

void func_80011BEC(s32 id, Tex11BEC *out, Pt11BEC *pos, Pt11BEC *clut);

/* Sound-bank record in the D_80041194 pointer table (high halves of field_0 /
 * field_4 are resource ids, field_8 is a zero-ended list). */
typedef struct {
    /* 0x00 */ u32 field_0;
    /* 0x04 */ u32 field_4;
    /* 0x08 */ s32 field_8[1];
} Rec41194;

/* One 32-bit TIM header word read as two halves. */
typedef struct {
    u16 lo;
    u16 hi;
} TimHalves;
/* TIM info filled by func_8002BBD4: pixel rect/data then CLUT rect/data. */
typedef struct {
    /* 0x00 */ u32 mode;
    /* 0x04 */ Rect23550 prect;
    /* 0x0C */ u32 *paddr;
    /* 0x10 */ Rect23550 crect;
    /* 0x18 */ u32 *caddr;
} TimInfo2BBD4;


/* Section header inside a func_8001FDBC model: a count then 20-byte entries. */
typedef struct {
    /* 0x00 */ s32 v[5];
} Ent1FDBC20;

typedef struct Sec1FDBC20 {
    /* 0x00 */ s32 n;
    /* 0x04 */ Ent1FDBC20 e[1];
} Sec1FDBC20;

typedef struct {
    /* 0x00 */ s32 v[4];
} Ent1FDBC16;

typedef struct {
    /* 0x00 */ s32 n;
    /* 0x04 */ Ent1FDBC16 e[1];
} Sec1FDBC16;

/* Model file func_8001FDBC binds: field_4 is set once the offset tables are
 * relocated; field_C starts three count-long offset tables (then a fourth). */
typedef struct Mdl1FDBC {
    u8 _pad00[0x04];
    /* 0x04 */ s32 field_4;
    /* 0x08 */ s32 field_8;
    /* 0x0C */ s32 field_C[1];
} Mdl1FDBC;

/* VRAM rectangle func_80028C48 uploads: four halfwords, sent to the GPU as two words. */
typedef union {
    struct {
        /* 0x0 */ s16 x;
        /* 0x2 */ s16 y;
        /* 0x4 */ s16 w;
        /* 0x6 */ s16 h;
    } r;
    /* 0x0 */ s32 word[2];
} Rect28C48;


/* func_8001D104: POLY_FT4 packet (four 8-byte x/y/u/v/clut-or-tpage vertices)
 * and the SVECTOR/DVECTOR pair it feeds func_8002D444. */
typedef struct {
    /* 0x0 */ u16 x;
    /* 0x2 */ u16 y;
    /* 0x4 */ u8 u;
    /* 0x5 */ u8 v;
    /* 0x6 */ u16 extra;
} Vtx1D104;

typedef struct {
    /* 0x00 */ Tag1CE9C tag;
    /* 0x04 */ Col1CE9C c;
    /* 0x08 */ Vtx1D104 v[4];
} Poly1D104;

typedef struct {
    s16 vx;
    s16 vy;
    s16 vz;
    s16 pad;
} SVec1D104;

typedef struct {
    s16 vx;
    s16 vy;
} DVec1D104;


/* func_80014400: 12-byte window rect record copied into Wk14400.blk. */
typedef struct {
    s16 field_0[6];
} Blk14400;

/* func_80014400 view of Actor.work: cursor/dims pairs at 0x28/0x2C (the dims
 * pair heads the 12-byte block), selection state at 0x38..0x40. */
typedef struct {
    u8 _pad00[0x04];
    /* 0x04 */ u8 field_4[0x24];
    /* 0x28 */ s16 field_28[2];
    union {
        /* 0x2C */ s16 field_2C[2];
        Blk14400 blk;
    } u2C;
    /* 0x38 */ s16 field_38;
    /* 0x3A */ s16 field_3A;
    /* 0x3C */ s16 field_3C;
    u8 _pad3E[0x02];
    /* 0x40 */ s32 field_40;
} Wk14400;


/* func_80018D78: 12-byte window rect record (same shape as Blk14400). */
typedef struct {
    s16 field_0[6];
} Blk18D78;

/* Partner record reached through Wk18D78.field_84 (D_80050768->field_110). */
typedef struct {
    u8 _pad00[0x1];
    /* 0x01 */ u8 field_1;
    u8 _pad02[0x45];
    /* 0x47 */ u8 field_47[2];
    u8 _pad49[0x3];
    /* 0x4C */ u8 field_4C[4];
} Rec18D78;

/* func_80018D78 view of Actor.work (fields 0x50..0x14C). */
typedef struct {
    u8 _pad00[0x50];
    /* 0x50 */ s32 field_50;
    /* 0x54 */ s32 field_54;
    u8 _pad58[0x18];
    /* 0x70 */ Blk18D78 blk;
    u8 _pad7C[0x4];
    /* 0x80 */ s32 field_80;
    /* 0x84 */ Rec18D78 *field_84;
    /* 0x88 */ u8 *field_88;
    /* 0x8C */ void *field_8C;
    /* 0x90 */ void *field_90;
    /* 0x94 */ void *field_94;
    /* 0x98 */ u8 *field_98[3];
    u8 _padA4[0x24];
    /* 0xC8 */ s32 field_C8;
    u8 _padCC[0x6C];
    /* 0x138 */ s16 field_138[2];
    u8 _pad13C[0x4];
    /* 0x140 */ s16 field_140[2];
    u8 _pad144[0x8];
    /* 0x14C */ s32 field_14C;
} Wk18D78;

/* One list row of the func_800179EC page (8 bytes). */
typedef struct {
    /* 0x0 */ u8 field_0;
    /* 0x1 */ u8 field_1;
    /* 0x2 */ u8 field_2;
    u8 _pad3;
    /* 0x4 */ void *field_4;
} Row179EC;

/* Work block of the list page built by func_800179EC. */
typedef struct {
    u8 _pad00[0x52];
    /* 0x052 */ s16 field_52;
    /* 0x054 */ s16 field_54;
    /* 0x056 */ s16 field_56;
    u8 _pad58[0x8];
    /* 0x060 */ s16 field_60;
    u8 _pad62[0xA];
    /* 0x06C */ Row179EC rows[0x26];
    /* 0x19C */ s16 field_19C;
    /* 0x19E */ s16 field_19E;
    /* 0x1A0 */ s16 field_1A0;
    /* 0x1A2 */ s16 field_1A2;
    /* 0x1A4 */ s16 field_1A4;
    /* 0x1A6 */ s16 field_1A6;
} Wk179EC;


/* Sound master block reached through D_80062D04 (field_18 = master volume). */
typedef struct {
    u8 _pad00[0x12];
    /* 0x12 */ u16 field_12;
    u8 _pad14[0x4];
    /* 0x18 */ u8 field_18;
} Snd62D04;


/* libspu reverb register image (0x44 bytes): func_8003B994 copies a preset
 * from D_800503E8[] and patches it, func_8003BE74 writes it out. */
typedef struct {
    /* 0x00 */ u32 field_0;
    /* 0x04 */ u16 field_4;
    /* 0x06 */ u16 field_6;
    /* 0x08 */ u16 field_8;
    /* 0x0A */ u16 field_A;
    /* 0x0C */ u16 field_C;
    /* 0x0E */ u16 field_E;
    /* 0x10 */ u16 field_10;
    /* 0x12 */ u16 field_12;
    /* 0x14 */ u16 field_14;
    /* 0x16 */ u16 field_16;
    /* 0x18 */ u16 field_18;
    /* 0x1A */ u16 field_1A;
    /* 0x1C */ u16 field_1C;
    /* 0x1E */ u16 field_1E;
    /* 0x20 */ u16 field_20;
    /* 0x22 */ u16 field_22;
    /* 0x24 */ u16 field_24;
    /* 0x26 */ u16 field_26;
    /* 0x28 */ u16 field_28;
    /* 0x2A */ u16 field_2A;
    /* 0x2C */ u16 field_2C;
    /* 0x2E */ u16 field_2E;
    /* 0x30 */ u16 field_30;
    /* 0x32 */ u16 field_32;
    /* 0x34 */ u16 field_34;
    /* 0x36 */ u16 field_36;
    /* 0x38 */ u16 field_38;
    /* 0x3A */ u16 field_3A;
    /* 0x3C */ u16 field_3C;
    /* 0x3E */ u16 field_3E;
    /* 0x40 */ u16 field_40;
    /* 0x42 */ u16 field_42;
} Rev3B994; /* size 0x44 */


/* Work block of the page func_800188BC redraws (same page as Wk179EC: rows at
 * 0x6C, mode at 0x60, flag at 0x1A6); field_50 is the (col, row) cursor pair. */
typedef struct {
    /* 0x0 */ u8 field_0;
    /* 0x1 */ u8 field_1;
    /* 0x2 */ u8 field_2;
    u8 _pad3;
    /* 0x4 */ void *field_4;
} Row188BC;

typedef struct {
    u8 _pad00[0x50];
    /* 0x050 */ Pair54 field_50;
    /* 0x054 */ s16 field_54;
    /* 0x056 */ s16 field_56;
    u8 _pad58[0x8];
    /* 0x060 */ u16 field_60;
    u8 _pad62[0x2];
    /* 0x064 */ s32 field_64;
    /* 0x068 */ s16 field_68;
    /* 0x06A */ s16 field_6A;
    /* 0x06C */ Row188BC rows[0x26];
    u8 _pad19C[0xA];
    /* 0x1A6 */ s16 field_1A6;
} Wk188BC;

/* Record a func_800188BC row points at; four stat halfwords at 0x14. */
typedef struct {
    u8 _pad00[0x14];
    /* 0x14 */ s16 field_14;
    /* 0x16 */ s16 field_16;
    /* 0x18 */ s16 field_18;
    /* 0x1A */ s16 field_1A;
} Part188BC;


/* SPU voice attribute block (libspu SpuVoiceAttr layout) func_80036C54 fills
 * and hands to func_8003C904. */
typedef struct {
    /* 0x00 */ u32 voice;
    /* 0x04 */ u32 mask;
    /* 0x08 */ s16 vol_l;
    /* 0x0A */ s16 vol_r;
    /* 0x0C */ s16 volmode_l;
    /* 0x0E */ s16 volmode_r;
    /* 0x10 */ s16 volx_l;
    /* 0x12 */ s16 volx_r;
    /* 0x14 */ u16 pitch;
    /* 0x16 */ u16 note;
    /* 0x18 */ u16 sample_note;
    /* 0x1A */ s16 envx;
    /* 0x1C */ u32 addr;
    /* 0x20 */ u32 loop_addr;
    /* 0x24 */ s32 a_mode;
    /* 0x28 */ s32 s_mode;
    /* 0x2C */ s32 r_mode;
    /* 0x30 */ u16 ar;
    /* 0x32 */ u16 dr;
    /* 0x34 */ u16 sr;
    /* 0x36 */ u16 rr;
    /* 0x38 */ u16 sl;
    /* 0x3A */ u16 adsr1;
    /* 0x3C */ u16 adsr2;
    u8 _pad3E[0x2];
} VAttr36C54; /* size 0x40 */

/* One DMA channel register block (MADR, BCR, CHCR) at D_8004FBF4[ch]. */
typedef struct {
    /* 0x0 */ u32 madr;
    /* 0x4 */ u32 bcr;
    /* 0x8 */ u32 chcr;
    u8 _padC[0x4];
} Dma4FBF4;


/* Horizontal display range pair per video standard and width class,
 * D_80048FE4[pad0][k] (func_80027CB0). */
typedef struct {
    /* 0x0 */ u16 lo;
    /* 0x2 */ u16 hi;
} Rng48FE4;

/* Graphics-debug state at D_80048F10 (func_80027278 / func_80027388): debug
 * type 0x0, level 0x2, reverse 0x3, and the saved word at 0xC. */
typedef struct {
    /* 0x00 */ u8 field_0;
    /* 0x01 */ u8 field_1;
    /* 0x02 */ u8 field_2;
    /* 0x03 */ u8 field_3;
    /* 0x04 */ s16 field_4;
    /* 0x06 */ s16 field_6;
    /* 0x08 */ s32 field_8;
    /* 0x0C */ s32 field_C;
    /* 0x10 */ u8 field_10[0x5C];
    /* 0x6C */ volatile DispEnv field_6C; /* cached display environment */
} Gpu48F10;


/* SPU voice shadow at D_80062A28: per-voice dirty flags, then 0x10-byte
 * register images (volume L/R at 0x0/0x2, pitch at 0x4). */
typedef struct {
    /* 0x0 */ u16 vol_l;
    /* 0x2 */ u16 vol_r;
    /* 0x4 */ u16 pitch;
    u8 _pad6[0xA];
} VReg62A48; /* size 0x10 */

typedef struct {
    /* 0x00 */ u8 flags[0x20];
    /* 0x20 */ VReg62A48 regs[24];
} Snd62A28;

/* 0x28-stride zero-terminated list func_8001D504 walks (func_80014870 passes it
 * the func_800239A0 lookups); field_F is set to 0 or 1 from field_1C & mask. */
typedef struct {
    /* 0x00 */ s32 field_0;
    u8 _pad04[0xB];
    /* 0x0F */ u8 field_F;
    u8 _pad10[0xC];
    /* 0x1C */ s32 field_1C;
    u8 _pad20[0x8];
} Obj1D504;


/* Variable-size entry list returned by func_80023A08 for func_80019E50: ends
 * at field_0 == -1, field_C is the byte size of the entry. */
typedef struct {
    /* 0x00 */ s32 field_0;
    u8 _pad4[8];
    /* 0x0C */ s32 field_C;
    /* 0x10 */ s32 field_10;
} Ent19E50;


/* func_8001C104 reads two 0x14-stride display areas out of D_8005F770 at 0xE8
 * (a Rect2AB54 at the head of each). */
typedef struct {
    /* 0x00 */ Rect2AB54 rect;
    u8 _pad8[0xC];
} Area1C104;

typedef struct {
    u8 _pad0[0xE8];
    /* 0xE8 */ Area1C104 area[2];
} View1C104;


/* BIOS device control block (0x50 bytes), table at 0x150 / byte size at 0x154, scanned by func_8003F760. */
typedef struct {
    /* 0x00 */ s8 *field_0;
    u8 _pad04[0x30];
    /* 0x34 */ void (*field_34)(s32 *, s32, s32);
    u8 _pad38[0x18];
} Dcb3F760;


/* file-local view over D_8005E620 for func_80021DC8 */
typedef struct {
    u8 _p[0x1004];
    /* 0x1004 */ u8 a[0x20];
    /* 0x1024 */ u8 b[0x8];
    /* 0x102C */ u8 c[0x8];
    /* 0x1034 */ u8 d[0x10];
} V1004_21DC8;
extern s32 D_8005F664;


/* 4-byte unaligned tag and the 0x20-byte records at D_80061B38 (func_8002DF74). */
typedef struct {
    u8 b[4];
} B4_2DF74;
typedef struct {
    /* 0x00 */ s16 field_0;
    u8 _pad02[0x4];
    /* 0x06 */ u16 field_6;
    /* 0x08 */ s32 field_8;
    u8 _pad0C[0x10];
    /* 0x1C */ B4_2DF74 field_1C;
} Rec2DF74;
extern s32 D_80061B40;
extern s32 D_80061B44;
typedef struct { s32 v; } W1_2DF74;
typedef struct { void (*f)(void); } F1_2DF74;
typedef struct { B4_2DF74 tag; s32 val; } T40_2DF74;


/* 0xF0-byte slots at Ent266D0.field_C; func_800267F0 hands slots 2 and 3 to the D_80048E30 callback. */
typedef struct Slot267F0 {
    /* 0x00 */ Ent266D0 e;
    u8 _pad48[0xA0];
    /* 0xE8 */ u8 field_E8;
    u8 _padE9[0x7];
} Slot267F0; /* size 0xF0 */


/* Stat-regen config returned by func_80011F5C, read by func_80012640. */
typedef struct {
    /* 0x00 */ u8 field_0;
    /* 0x01 */ u8 field_1;
    /* 0x02 */ s16 field_2;
} Cfg12640;


/* By-value struct arg spanning a3 + stack (0x28 bytes); only three fields
   are touched here. func_80036164/func_80036594 receive its address. */
typedef struct {
    u8 pad0[0x10];
    /* 0x10 */ u16 field_10;
    /* 0x12 */ u16 field_12;
    u8 pad1[0x24 - 0x14];
    /* 0x24 */ u8 field_24;
    u8 pad2[0x28 - 0x25];
} Arg33;

/* One text-command handler slot in the dialogue op table. */
typedef void (*TextOp)();

void func_800348D4(s32 a0, s32 a1, s32 a2, s32 a3);
void func_800349B4(s16 arg0, s16 arg1, s16 arg2);
void func_80034704(s16 a0, s16 a1);
void func_80034424(s16 a0, s16 a1);
void func_800344D4(s16 a0, s16 a1, s32 a2);
void func_80032C54(s16 arg0, s16 arg1, s16 arg2);
void func_80033054(s16 a0, s16 a1, u8 a2);
void func_80033124(s16 a0, s16 a1, s32 a2);
void func_800331F4(s16 a0, s16 a1, s32 a2);
void func_800332E4(s16 a0, s16 a1, u8 a2);
void func_80033424(s16 a0, s16 a1, u8 a2);
void func_80033524();
void func_80033664(s16 arg0, s16 arg1, s16 arg2);
void func_800336D4(s16 arg0, s16 arg1, s16 arg2);
void func_80033394(s16 a0, s16 a1, u8 a2);
void func_80033744(s16 a0, s16 a1);
void func_80032CD4(s16 a0, s16 a1, s16 a2);
void func_80033804(s16 a0, s16 a1, s16 a2, HandlerArg arg);
void func_80033894(s16 a0, s16 a1, s16 a2, HandlerArg arg);
void func_80033954(s16 a0, s16 a1, s16 a2, HandlerArg d);
void func_800339E4(s16 a0, s16 a1, s16 a2, HandlerArg d);
void func_80033A74(s16 a0, s16 a1, s16 a2, Arg33 d);
void func_80033C24(s16 a0, s16 a1, s16 a2, Arg33 d);
void func_80033CE4(s16 a0, s16 a1, s16 a2, HandlerArg d);
void func_80033D94(s16 a0, s16 a1, s16 a2, Arg33 d);
void func_80033E44(s16 a0, s16 a1, s16 a2, Arg33 d);
void func_80033EF4(s16 a0, s16 a1, s16 a2, Arg33 d);
void func_80033FB4(s16 a0, s16 a1, s16 a2, Arg33 d);
void func_80034064(s16 a0, s16 a1, s16 a2, Arg33 d);
void func_80034114(s16 a0, s16 a1, s16 a2, HandlerArg d);
void func_800341F4(s16 a0, s16 a1, s16 a2, HandlerArg d);
void func_80034294(s16 a0, s16 a1, s16 a2, HandlerArg arg);
void func_80034334(s16 arg0, s16 arg1, s16 arg2, HandlerArg arg);
void func_80034364(s16 arg0, s16 arg1, s16 arg2, HandlerArg arg);
void func_80034394(s16 arg0, s16 arg1, s16 arg2, HandlerArg arg);
void func_800343C4(s16 arg0, s16 arg1, s16 arg2, HandlerArg arg);
void func_800343F4(s16 arg0, s16 arg1, s16 arg2, HandlerArg arg);


/* func_8003F518: 6-byte text template (byte aligned) copied into the output
 * before the two hex-ish digit bytes 2 and 3 are patched in. */
typedef struct {
    u8 b[6];
} Str3F518;


static inline u32 gpu_draw_mode(u32 base, u32 dither, s32 tpage) {
    return (base | (dither << 10)) | (tpage & 0x7FF);
}

/* 0x20-byte slot of the table D_80061B38 points at (word view of Rec2DF74, set by func_8002DBD4). */
typedef struct {
    /* 0x00 */ s32 field_0;
    u8 _pad4[0x1C];
} Slot2E1A4;

/* Stream sector ring (func_8002DBD4 sets base D_80061B38 and count D_80061B3C):
   `count` 0x20-byte slot headers, then `count` 0x7E0-byte sector payloads. */
typedef struct {
    /* 0x00 */ u16 status;
    u8 _pad02[0x1E];
} Slot2E1E4;
typedef struct {
    /* 0x000 */ u8 data[0x7E0];
} Sect2E1E4;
extern s32 D_80061B2C;


/* func_8002D704 (PsyQ TransposeMatrix shape): the 3x3 s16 matrix viewed as
 * packed word pairs, so the transpose moves whole words then patches halves. */
typedef union {
    s32 w;
    s16 h;
} Half2D704;

typedef struct {
    /* 0x00 */ Half2D704 f0;
    /* 0x04 */ Half2D704 f4;
    /* 0x08 */ Half2D704 f8;
    /* 0x0C */ Half2D704 fC;
    /* 0x10 */ s16 f10;
} Obj2D704;

/* TIM file block header (CLUT or pixel block): byte length incl. this header,
   then the VRAM rectangle; the block's data follows. */
typedef struct {
    /* 0x0 */ u32 bnum;
    /* 0x4 */ Rect2AB54 rect;
} TimBlk;


/* libsnd VabHdr (0x20) and ProgAtr (0x10) as parsed by func_80039B54. */
typedef struct {
    /* 0x00 */ s32 form;
    /* 0x04 */ s32 ver;
    /* 0x08 */ s32 id;
    /* 0x0C */ u32 fsize;
    /* 0x10 */ u16 reserved0;
    /* 0x12 */ u16 ps;
    /* 0x14 */ u16 ts;
    /* 0x16 */ u16 vs;
    /* 0x18 */ u8 mvol;
    /* 0x19 */ u8 pan;
    /* 0x1A */ u8 attr1;
    /* 0x1B */ u8 attr2;
    /* 0x1C */ u32 reserved1;
} VabHdr39B54;

typedef struct {
    /* 0x00 */ u8 tones;
    u8 _pad01[0x7];
    /* 0x08 */ s32 reserved1;
    /* 0x0C */ u16 vagLo;
    /* 0x0E */ u16 vagHi;
} Prog39B54;

/* func_800153F4 view of an actor work block: four hud slot words at 0x60 (overlaps ActorWork fields 0x64..0x6C). */
typedef struct {
    u8 _pad00[0x60];
    /* 0x60 */ s32 slot[4];
} HudSlots153F4;

/* 4-byte record returned (as s32 *) by the func_80011F5C id lookup. */
typedef struct {
    /* 0x00 */ u8 field_0;
    /* 0x01 */ u8 field_1;
    /* 0x02 */ s16 field_2;
} Rec11F5C;

/* Object stepped by func_8001236C: two value/limit s16 pairs at 0x14..0x1A. */
typedef struct {
    u8 _pad00[0x1];
    /* 0x01 */ u8 field_1;
    u8 _pad02[0x12];
    /* 0x14 */ s16 field_14;
    /* 0x16 */ s16 field_16;
    /* 0x18 */ s16 field_18;
    /* 0x1A */ s16 field_1A;
} Obj1236C;

typedef struct { s32 x[8]; s32 y[8]; } XY2CC64;

/* func_80017F6C view of an actor work block: mode at 0x60, s16 flag at 0x6A, parity at 0x1A6. */
typedef struct {
    u8 _pad00[0x60];
    /* 0x60 */ s16 mode;
    u8 _pad62[0x08];
    /* 0x6A */ s16 flag6A;
    u8 _pad6C[0x13A];
    /* 0x1A6 */ s16 parity;
} ModeWork17F6C;

/* GPU command queue entry at D_800600B0 (stride 0x60, 64 entries). */
typedef struct {
    /* 0x00 */ void (*func)(s32 *, s32);
    /* 0x04 */ s32 *ptr;
    /* 0x08 */ s32 x;
    /* 0x0C */ s32 param[21];
} Que291FC; /* size 0x60 */


/* Stream state block at D_8004FC48 (mode, busy flag, two hooks, three flag bytes), read by func_80035074. */
typedef struct {
    /* 0x00 */ s32 mode;
    /* 0x04 */ s32 flag;
    /* 0x08 */ void (*fn_0)(void);
    /* 0x0C */ void (*fn_4)(void);
    /* 0x10 */ s8 b0;
    /* 0x11 */ s8 b1;
    /* 0x12 */ s8 b2;
} Cd4FC48;

/* Screen fade packet func_8001C584 writes at D_8005F770.work: a flat
 * semi-transparent quad (POLY_F4 layout) followed by a draw-mode word pair. */
typedef struct {
    /* 0x00 */ Tag1CE9C t;
    /* 0x04 */ u32 mode;
} Fade1C584Mode;

typedef struct {
    /* 0x00 */ Tag1CE9C t;
    /* 0x04 */ u8 r;
    /* 0x05 */ u8 g;
    /* 0x06 */ u8 b;
    /* 0x07 */ u8 code;
    /* 0x08 */ s16 x0;
    /* 0x0A */ s16 y0;
    /* 0x0C */ s16 x1;
    /* 0x0E */ s16 y1;
    /* 0x10 */ s16 x2;
    /* 0x12 */ s16 y2;
    /* 0x14 */ s16 x3;
    /* 0x16 */ s16 y3;
    /* 0x18 */ Fade1C584Mode m;
} Fade1C584;


/* func_8002EC0C: DMA control byte view (the byte at +2 holds one enable bit
 * per channel; the word is read back to flush the write). */
typedef union {
    s32 w;
    u8 b[4];
} Reg2EC0C;


s32 func_80038A90(s16 a0, s16 a1, s16 a2, s32 a3);


/* func_8001F9AC: 10-byte fixed part (field_1C list of Sub3C, 0xFF/0xFE ended),
 * 0x2A-byte animated part that follows a 0xFE marker, the position block at
 * Sub3C 0x44 and the D_8005F770 fields it reads. */
typedef struct {
    /* 0x0 */ u8 field_0;
    /* 0x1 */ u8 field_1;
    /* 0x2 */ u8 field_2;
    /* 0x3 */ u8 field_3;
    /* 0x4 */ u8 uv[6];
} Part1F9AC;

typedef struct {
    /* 0x0 */ u8 field_0;
    /* 0x1 */ u8 field_1;
    /* 0x2 */ u8 field_2;
    /* 0x3 */ u8 field_3;
    /* 0x4 */ u8 field_4;
    /* 0x5 */ u8 field_5;
    /* 0x6 */ u8 field_6;
    /* 0x7 */ u8 field_7;
    /* 0x8 */ u8 field_8;
    /* 0x9 */ u8 field_9;
    /* 0xA */ u8 uv[32];
} Anim1F9AC;

typedef struct Pos1F9AC {
    u8 _pad00[0x18];
    /* 0x18 */ s32 field_18;
    /* 0x1C */ s32 field_1C;
} Pos1F9AC;

typedef struct {
    u8 _pad00[0x8];
    /* 0x008 */ s32 field_8;
    u8 _pad0C[0x2C - 0xC];
    /* 0x02C */ DrMove2AB54 *field_2C;
    u8 _pad30[0x150 - 0x30];
    /* 0x150 */ unsigned int *field_150;
} Wk1F9AC;


/* func_80026170 5-byte directory entry (field_4 table). */
typedef struct {
    /* 0x0 */ u8 field_0;
    /* 0x1 */ u8 field_1;
    /* 0x2 */ u8 field_2;
    /* 0x3 */ u8 field_3;
    /* 0x4 */ u8 field_4;
} Ent26170;

/* func_80026170 stride-8 block record (field_8 table): length byte + data pointer. */
typedef struct {
    /* 0x0 */ u8 field_0;
    u8 _pad1[0x3];
    /* 0x4 */ u8 *field_4;
} Blk26170;

/* func_80026170 view of Obj25FBC: the three table pointers typed for the record parser. */
typedef struct {
    /* 0x00 */ u16 *field_0;
    /* 0x04 */ Ent26170 *field_4;
    /* 0x08 */ Blk26170 *field_8;
    u8 _pad0C[0x30];
    /* 0x3C */ volatile u8 *field_3C;
    u8 _pad40[0x6];
    /* 0x46 */ u8 field_46;
    /* 0x47 */ u8 field_47;
    /* 0x48 */ u8 field_48;
    /* 0x49 */ u8 field_49;
    u8 _pad4A[0x99];
    /* 0xE3 */ u8 field_E3;
    u8 _padE4[0x5];
    /* 0xE9 */ u8 field_E9;
    /* 0xEA */ u8 field_EA;
    /* 0xEB */ u8 field_EB;
    u8 _padEC[0x2];
    /* 0xEE */ u16 field_EE;
} Obj26170;

typedef struct {
    /* 0x00 */ s32 field_0[10];
} Ent3EF1C;


/* CD command tables at 0x8004E80C: per-command result flag, then parameter byte count; read by func_8002F860. */
typedef struct {
    /* 0x000 */ s32 field_0[64];
    /* 0x100 */ s32 field_100[64];
} CdTbl4E80C;


/* GTE color / light matrix (func_8002BA80 reads, func_8002BA1C sets the color one). */
typedef Mat1F668 S32;

/* Latched copy of State62F80.field_0/4 handed to its field_44 callback. */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
} Pair62F70;

/* Pending voice attribute values at D_80062A48 (stride 0x10). */
typedef struct {
    /* 0x00 */ u16 field_0;
    /* 0x02 */ u16 field_2;
    /* 0x04 */ u16 field_4;
    /* 0x06 */ u16 field_6;
    /* 0x08 */ u16 field_8;
    /* 0x0A */ u16 field_A;
    u8 _pad0C[0x4];
} Rec62A48;

/* One u16 field of a 16-byte record, for per-field stride pointers. */
typedef struct {
    u16 v;
    u8 _pad02[0xE];
} Stride16;

/* 0x28-stride part record in resource 0x3120002 (zero field_0 ends the list). */
typedef struct {
    /* 0x00 */ s32 field_0;
    u8 _pad04[0x8];
    /* 0x0C */ u8 field_C;
    u8 _pad0D[0x1];
    /* 0x0E */ u8 field_E;
    /* 0x0F */ u8 field_F;
    /* 0x10 */ s32 field_10;
    u8 _pad14[0x8];
    /* 0x1C */ s32 field_1C;
    u8 _pad20[0x8];
} Part11854;

/* libgpu primitive tag: next-packet address and word count. */
typedef struct {
    u32 addr : 24;
    u32 len : 8;
} PTag11854;

/* Textured quad packet (libgpu POLY_FT4 layout). */
typedef struct {
    /* 0x00 */ PTag11854 tag;
    /* 0x04 */ union {
        Halves rgb;
        struct {
            u8 r0;
            u8 g0;
            u8 b0;
            u8 code;
        } b;
    } c;
    /* 0x08 */ s16 x0;
    /* 0x0A */ s16 y0;
    /* 0x0C */ u8 u0;
    /* 0x0D */ u8 v0;
    /* 0x0E */ u16 clut;
    /* 0x10 */ s16 x1;
    /* 0x12 */ s16 y1;
    /* 0x14 */ u8 u1;
    /* 0x15 */ u8 v1;
    /* 0x16 */ u16 tpage;
    /* 0x18 */ s16 x2;
    /* 0x1A */ s16 y2;
    /* 0x1C */ u8 u2;
    /* 0x1D */ u8 v2;
    /* 0x1E */ u16 pad1;
    /* 0x20 */ s16 x3;
    /* 0x22 */ s16 y3;
    /* 0x24 */ u8 u3;
    /* 0x25 */ u8 v3;
    /* 0x26 */ u16 pad2;
} Ft4_11854;

/* memory card directory frame entry (0x20) written by func_800401E4 */
typedef struct {
    /* 0x00 */ s32 field_0;
    /* 0x04 */ s32 field_4;
    /* 0x08 */ u16 field_8;
    /* 0x0A */ s8 field_A[0x16];
} McDir401E4;

/* byte-aligned views used for the frame copies in func_800401E4 */
typedef struct { u8 b[0x20]; } McBlk20;
typedef struct { u8 b[0x4]; } McBlk4;

typedef struct {
    /* 0x0 */ u8 b[4];
} Hdr2E2C4;

/* 0x20-byte stream sector header (StHEADER-like) in the D_80061B38 ring. */
typedef struct {
    /* 0x00 */ volatile u16 field_0;
    /* 0x02 */ u16 field_2;
    /* 0x04 */ u16 field_4;
    /* 0x06 */ u16 field_6;
    /* 0x08 */ u16 field_8;
    u8 _pad0A[0x12];
    /* 0x1C */ Hdr2E2C4 field_1C;
} Sect2E2C4;

typedef struct {
    /* 0x0 */ u16 field_0;
    /* 0x2 */ u16 stat;
    /* 0x4 */ u16 intr;
} Res2E2C4;

#define VA_ARG(ap, T) (((T *)((ap) += sizeof(T)))[-1])

extern Mat1F668 D_800619C8;

/* Primitive tag: next-pointer (24 bits) + word count (8 bits), PsyQ P_TAG shape. */
typedef struct {
    u32 addr : 24;
    u32 len : 8;
} Tag21ABC;

/* Byte colour + GPU code, copied as a 4-byte unaligned struct. */
typedef struct {
    u8 r;
    u8 g;
    u8 b;
    u8 code;
} Col21ABC;

/* Four-point poly line packet (code 0x4E) closed by the 0x55555555 terminator. */
typedef struct {
    /* 0x00 */ Tag21ABC tag;
    /* 0x04 */ Col21ABC c;
    /* 0x08 */ s32 xy[4];
    /* 0x18 */ s32 end;
} LineF4_21ABC; /* size 0x1C */

/* Two-point line packet (code 0x42). */
typedef struct {
    /* 0x00 */ Tag21ABC tag;
    /* 0x04 */ Col21ABC c;
    /* 0x08 */ s32 xy[2];
} LineF2_21ABC; /* size 0x10 */

/* One-word draw-mode packet. */
typedef struct {
    /* 0x00 */ Tag21ABC tag;
    /* 0x04 */ u32 code;
} Tpage21ABC; /* size 0x8 */

/* Quad record func_80021ABC walks: four vertex indices, stride 0x14. */
typedef struct {
    /* 0x00 */ u8 v[4];
    u8 _pad04[0x10];
} Quad21ABC; /* size 0x14 */

/* Model view func_80021ABC reads: OT slot at 0x3C, projected xy / z tables at 0x6C / 0x70. */
typedef struct {
    u8 _pad00[0x3C];
    /* 0x3C */ s32 field_3C;
    u8 _pad40[0x2C];
    /* 0x6C */ s32 *field_6C;
    /* 0x70 */ s32 *field_70;
} Obj21ABC;


/* Triangle record func_800218CC walks: three vertex indices, stride 0x10. */
typedef struct {
    /* 0x00 */ u8 v[3];
    u8 _pad03[0xD];
} Tri218CC; /* size 0x10 */

/* 0x5C-byte record swapped between the menu slots and D_80050768->field_128 (func_80017214). */
typedef struct {
    /* 0x00 */ u8 field_0;
    u8 _pad1[0x3];
    s32 _pad4[0x16];
} Rec17214;
/* Non-small views of D_80050768 / D_8005F704 for func_80017214. */
typedef struct {
    Obj50768 *p;
    s32 _r[3];
} View50768;
typedef struct {
    s32 n;
    s32 _r[3];
} View5F704;


/* Actor work block of the func_80018048 menu (list page like Obj17D84). */
typedef struct {
    /* 0x000 */ s32 field_0[16];
    /* 0x040 */ s32 field_40;
    /* 0x044 */ s32 field_44;
    /* 0x048 */ s32 field_48;
    u8 _pad4C[0x4];
    /* 0x050 */ s16 field_50[2];
    /* 0x054 */ Box16198 field_54;
    /* 0x060 */ s16 field_60;
    /* 0x062 */ s16 field_62;
    /* 0x064 */ s32 field_64;
    /* 0x068 */ s16 field_68;
    /* 0x06A */ s16 field_6A;
    u8 _pad6C[0x132];
    /* 0x19E */ s16 field_19E;
    u8 _pad1A0[0x6];
    /* 0x1A6 */ s16 field_1A6;
} Wk18048;

/* frame stamp bumped once per frame; a coordinate's cached world matrix is valid while its flg equals it */
typedef struct {
    /* 0x0 */ s32 stamp;
} Stamp61988;


/* func_8001A9C8 (text renderer): the actor work block is 50 Rec34 text boxes
 * followed by three counters; D_8005F770 viewed through the fields it reads. */
typedef struct {
    /* 0x000 */ Rec34 rec[50];
    /* 0xA28 */ s32 field_A28;
    /* 0xA2C */ void *field_A2C;
    /* 0xA30 */ s32 field_A30;
} Wk1A9C8;

typedef struct {
    u8 _pad0[8];
    /* 0x08 */ s32 field_8;
    u8 _padC[0xC];
    /* 0x18 */ s32 field_18;
    /* 0x1C */ s32 field_1C;
    u8 _pad20[4];
    /* 0x24 */ s32 field_24;
    u8 _pad28[4];
    /* 0x2C */ s32 field_2C;
    u8 _pad30[0xE0];
    /* 0x110 */ s32 field_110;
    /* 0x114 */ s32 field_114;
    u8 _pad118[0x20];
    /* 0x138 */ u32 *field_138[8];
} Gl1A9C8;

typedef struct {
    u8 r;
    u8 g;
    u8 b;
    u8 code;
} Col1A9C8;

/* POLY_FT4 packet; the colour word is copied with lwl/lwr. */
typedef struct {
    /* 0x00 */ union {
        u32 word;
        struct {
            u8 addr[3];
            u8 len;
        } b;
    } tag;
    /* 0x04 */ Col1A9C8 c;
    /* 0x08 */ u16 x0;
    /* 0x0A */ u16 y0;
    /* 0x0C */ u8 u0;
    /* 0x0D */ u8 v0;
    /* 0x0E */ u16 clut;
    /* 0x10 */ u16 x1;
    /* 0x12 */ u16 y1;
    /* 0x14 */ u8 u1;
    /* 0x15 */ u8 v1;
    /* 0x16 */ u16 tpage;
    /* 0x18 */ u16 x2;
    /* 0x1A */ u16 y2;
    /* 0x1C */ u8 u2;
    /* 0x1D */ u8 v2;
    u16 _pad1E;
    /* 0x20 */ u16 x3;
    /* 0x22 */ u16 y3;
    /* 0x24 */ u8 u3;
    /* 0x25 */ u8 v3;
    u16 _pad26;
} Ft4_1A9C8;

typedef struct {
    u8 _pad0[0x42];
    /* 0x42 */ s16 field_42;
} Sub6A8C0;

typedef struct {
    u8 _pad0[0x38];
    /* 0x38 */ Sub6A8C0 *field_38;
} Obj6A8C0;

#endif /* MAIN_156C_H */
