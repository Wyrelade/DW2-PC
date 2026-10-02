#include "common.h"
#include "stag4000/stag4000.h"
#include "stag4000/stag4000_funcs.h"
#include "stag4000/stag4000_1DD4_funcs.h"
#include "stag4000/stag4000_8338_funcs.h"
#include "stag4000/stag4000_9364_funcs.h"
#include "stag4000/stag4000_A180_funcs.h"

void func_8006F62C(Stg40TileWork *a0, s32 x, s32 y) {
    if (func_800703E0(x, y) & 0x8000) {
        ((Stg40Cell *)D_8005071C->field_E58)[a0->field_766 * y + x].field_0 |= 0x2000;
        func_8006EB84(x, y, 1);
    }
}

void func_8006F6BC(Stg40TileWork *w) {
    s32 x = D_8005071C->field_1068->u0.pair.field_0;
    s32 y = D_8005071C->field_1068->u0.pair.field_2;
    s32 dx = w->field_76C - x;
    s32 dy = w->field_76E - y;

    if (dx == 0 && dy == 0) {
        return;
    }
    func_8006F3F4(w, x, y);
    if (dx > 0) {
        func_8006F62C(w, x - 1, y - 1);
        func_8006F62C(w, x - 1, y);
        func_8006F62C(w, x - 1, y + 1);
    }
    if (dx < 0) {
        func_8006F62C(w, x + 1, y - 1);
        func_8006F62C(w, x + 1, y);
        func_8006F62C(w, x + 1, y + 1);
    }
    if (dy > 0) {
        func_8006F62C(w, x - 1, y - 1);
        func_8006F62C(w, x, y - 1);
        func_8006F62C(w, x + 1, y - 1);
    }
    if (dy < 0) {
        func_8006F62C(w, x - 1, y + 1);
        func_8006F62C(w, x, y + 1);
        func_8006F62C(w, x + 1, y + 1);
    }
    func_8006F62C(w, x, y);
    w->field_76C = D_8005071C->field_1068->u0.pair.field_0;
    w->field_76E = D_8005071C->field_1068->u0.pair.field_2;
}

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000_C2CC", func_8006F86C);

void func_8006FC54(ActorWork *w) {
    Stg40TileWork *t = (Stg40TileWork *)w;
    Stg40Loc *loc;
    s32 i;

    for (i = 0; i < 2; i++) {
        if (i == D_80072B60->field_7E - 1) {
            t->field_762[i] = (t->field_762[i] + 0x20 < 0x100) ? (u16)t->field_762[i] + 0x20 : 0xFF;
        } else {
            t->field_762[i] = (t->field_762[i] - 0x20 >= 0) ? (u16)t->field_762[i] - 0x20 : 0;
        }
        if (t->field_762[i] != 0) {
            switch (i) {
            case 0:
                loc = D_8005071C->field_1068;
                func_8006F86C(t, 0x50, 0, loc->u0.pair.field_0, loc->u0.pair.field_2, 0x11, 0x11, 3, t->field_762[0]);
                break;
            case 1:
                func_8006F86C(t, 0, 0, 0x20, 0x18, 0x41, 0x31, 4, t->field_762[1]);
                break;
            }
        }
    }
}

void func_8006FDAC(void) {
}

void func_8006FDB4(Actor *a0) {
    Stg40TileWork *w = (Stg40TileWork *)a0->work;

    switch (a0->stateLevel0) {
    case 0:
    default:
        D_80072BB0 = (Stg40TileGrid *)w;
        func_8006F3B0(w);
        func_8006F290(w);
        func_8006ECD0(w);
        func_8006F18C(w);
        D_80072B60->field_7E = 0;
        Task_NextState0(a0);
        break;
    case 1:
        func_8006F6BC(w);
        func_8006F18C(w);
        func_8006F1C8((Stg40ImgWork *)w);
        break;
    case 2:
        break;
    }
}

void func_8006FE5C(Actor *a0) {
    func_8006F38C((Stg40ImgWork *)a0->work);
    Task_DefaultDestroy(a0);
}

void func_8006FE90(Actor *a0) {
    ActorWork *w = a0->work;

    if (func_80022518(0x12) <= 0) {
        D_80072B60->field_7E = 0;
    }
    func_8006FC54(w);
}

void func_8006FED4(void) {
    Stg40E34 *d = D_8005071C->field_E54;

    D_8005071C->field_E58 = (ActorWork *)Mem_Alloc(d->field_0 * (d->field_2 << 2), 2);
}

void func_8006FF28(void) {
    Mem_Free(D_8005071C->field_E58);
}

u16 func_8006FF54(u16 *pal, u32 *bits, s32 x, s32 y) {
    s32 w = D_8005071C->field_E54->field_0 / 8;

    return pal[(bits[w * y + x / 8] >> ((x % 8) * 4)) & 0xF];
}

INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000_C2CC", func_8006FFCC);

u16 func_800703E0(s32 x, s32 y) {
    Stg40Blk5071C *b = D_8005071C;
    Stg40E34 *d = b->field_E54;
    Stg40Cell *cells = (Stg40Cell *)b->field_E58;
    s32 w = d->field_0;
    s32 h = d->field_2;
    u16 r = 0;

    if (x >= 0 && y >= 0 && x < w && y < h) {
        r = cells[w * y + x].field_0;
    }
    return r;
}

Stg40Cell *func_80070438(s32 x, s32 y) {
    Stg40Blk5071C *b = D_8005071C;
    Stg40E34 *d = b->field_E54;
    s32 w = d->field_0;
    s32 h = d->field_2;
    Stg40Cell *r = NULL;

    if (x >= 0 && y >= 0 && x < w && y < h) {
        r = &((Stg40Cell *)b->field_E58)[w * y + x];
    }
    return r;
}

void func_80070490(s32 buf, s32 p1, s32 x, s32 y, s32 fill)
{
    Stg40Cell *grid = (Stg40Cell *)D_8005071C->field_E58;
    s32 width = D_8005071C->field_E54->field_0;
    s32 maxRun = 0;
    s32 count;
    s32 k;
    s32 nx;
    s32 ny;
    s32 r;

    if (!(func_800703E0(x, y) & 0x4000)) {
        return;
    }
    count = 1;
    ((Stg40FillPt *)buf)[0].x = x;
    ((Stg40FillPt *)buf)[0].y = y;
    grid[width * y + x].field_0 |= fill;
    do {
        if (maxRun < count) {
            maxRun = count;
        }
        count--;
        x = ((Stg40FillPt *)buf)[count].x;
        y = ((Stg40FillPt *)buf)[count].y;
        for (k = 0; k < 4; k++) {
            nx = D_800729C0[k * 2] + x;
            ny = D_800729C0[k * 2 + 1] + y;
            r = func_800703E0(nx, ny);
            if ((r & (fill | 0x8000)) != 0x8000) {
                continue;
            }
            if (p1 != 0) {
                grid[width * ny + nx].field_0 |= fill;
            }
            if (!(r & 0x4000)) {
                continue;
            }
            grid[width * ny + nx].field_0 |= fill;
            ((Stg40FillPt *)buf)[count].x = nx;
            ((Stg40FillPt *)buf)[count].y = ny;
            count++;
        }
    } while (count != 0);
}

s32 func_800706C8(void) {
    Stg40Blk5071C *b = D_8005071C;
    Stg40Cell *c = (Stg40Cell *)b->field_E58;
    s32 h = b->field_E54->field_2;
    s32 w = b->field_E54->field_0;
    s32 x;
    s32 y;

    for (y = 0; y < h; y++) {
        for (x = 0; x < w; x++, c++) {
            if ((c->field_0 & 0x4000) && c->field_2 == 0xFF) {
                return y * w + x;
            }
        }
    }
    return -1;
}

void func_80070754(void) {
    Stg40Blk5071C *b = D_8005071C;
    s32 n = b->field_E54->field_0 * b->field_E54->field_2;
    u8 v = D_80072B60->field_0;
    Stg40Cell *c = (Stg40Cell *)b->field_E58;
    s32 i;

    for (i = 0; i < n; i++, c++) {
        if (c->field_0 & 0x2000) {
            c->field_2 = v;
            c->field_0 &= ~0x2000;
        }
    }
}

void func_800707D0(void) {
    s32 w = D_8005071C->field_E54->field_0;
    s32 buf = Mem_Alloc(0x3FF8, 2);
    s32 i;

    D_80072B60->field_0 = 0;
    while ((D_80072BB8 = i = func_800706C8()) != -1) {
        func_80070490(buf, 0, i % w, i / w, 0x2000);
        func_80070754();
        D_80072B60->field_0++;
    }
    Mem_Free((ActorWork *)buf);
}

Stg40Cell *func_800708A4(s32 x, s32 y) {
    Stg40Blk5071C *b = D_8005071C;
    Stg40E34 *d = b->field_E54;
    s32 w = d->field_0;
    s32 h = d->field_2;
    Stg40Cell *r = NULL;

    if (x >= 0 && y >= 0 && x < w && y < h) {
        r = &((Stg40Cell *)b->field_E58)[w * y + x];
    }
    return r;
}

void func_800708FC(s32 x, s32 y, s32 flag) {
    Stg40Blk5071C *b = D_8005071C;
    Stg40E34 *d = b->field_E54;
    s32 w = d->field_0;
    s32 h = d->field_2;
    Stg40Cell *c;

    if (x >= 0 && y >= 0 && x < w && y < h) {
        c = (Stg40Cell *)b->field_E58;
        c[w * y + x].field_0 |= flag == 0 ? 0x40 : 0x60;
    }
}

void func_80070974(s32 x, s32 y) {
    Stg40Blk5071C *b = D_8005071C;
    Stg40E34 *d = b->field_E54;
    s32 w = d->field_0;
    s32 h = d->field_2;
    Stg40Cell *c;

    if (x >= 0 && y >= 0 && x < w && y < h) {
        c = (Stg40Cell *)b->field_E58;
        c[w * y + x].field_0 &= ~0x60;
    }
}

void func_800709DC(void) {
    Stg40Rec3 *r = D_8005071C->field_D08;
    Stg40Cell *c;
    s32 i;

    for (i = 0; i < D_8005071C->field_14; r++, i++) {
        c = func_800708A4(r->field_0, r->field_1);
        c->field_0 &= 0xFFF0;
        c->field_0 |= r->field_2 + 7;
    }
}

void func_80070A7C(void) {
    Stg40FFC *p = &D_8005071C->field_FFC;
    s16 *q = p->field_0;
    s32 i;

    p->field_18 = 10;
    p->field_16 = 0;
    p->field_1A = 0;
    for (i = 0; i < p->field_18; i++) {
        *q++ = -1;
    }
    *q = -2;
}

s16 *func_80070AD0(s16 v) {
    Stg40FFC *f = &D_8005071C->field_FFC;
    s16 *p = f->field_0;

    while (*p != -2) {
        if (*p == v) {
            return p;
        }
        p++;
    }
    return NULL;
}

void func_80070B2C(s32 v) {
    Stg40FFC *f = &D_8005071C->field_FFC;

    if (func_80070AD0(v) == NULL && f->field_16 < f->field_18) {
        f->field_0[f->field_16] = v;
        f->field_16++;
    }
}

void func_80070BA4(s16 v) {
    Stg40FFC *f = &D_8005071C->field_FFC;
    s16 *p = func_80070AD0(v);
    s16 *q;

    if (p != NULL) {
        for (q = p + 1; *q != -2;) {
            *p++ = *q++;
        }
        *p = -1;
        f->field_16--;
        if (f->field_0[f->field_1A] == -1) {
            f->field_1A = 0;
        }
    }
}

s16 func_80070C48(void) {
    Stg40FFC *p = &D_8005071C->field_FFC;

    p->field_1A = (p->field_1A + 1 < p->field_16) ? p->field_1A + 1 : 0;
    return p->field_0[p->field_1A];
}

s16 func_80070C94(void) {
    Stg40FFC *p = &D_8005071C->field_FFC;

    return p->field_0[p->field_1A];
}

void func_80070CC0(s32 id) {
    s32 *p;

    p = (s32 *)Cd_GetFileOrNull(id);
    func_80070EE0(p);
    D_80072B60->field_1C = id;
    D_80072B60->field_C = p;
    D_80072B60->field_10 = p[D_8005071C->field_3];
    D_80072B60->field_18 = 0;
    while (D_80072B60->field_C[D_80072B60->field_18] != 0) {
        D_80072B60->field_18++;
    }
}

void func_80070D74(void) {
    s32 i;

    D_8005071C->field_4 = func_800711C4(8);
    for (i = 7; i >= 0; i--) {
        D_8005071C->field_E5C[i] = 0;
    }
}

void func_80070DC0(void) {
    Stg40B60 *b = D_80072B60;
    Stg40Blk5071C *g = D_8005071C;
    Stg40Map *m = (Stg40Map *)b->field_10;
    u8 *src;
    u8 *dst;

    b->field_14 = m->field_8[g->field_4];
    g->field_E54->field_A = m->field_28;
    g->field_E54->field_4 = 1;
    g->field_E54->field_C = m->field_2E;
    src = m->field_0;
    dst = D_8005071C->field_E54->field_E;
    memset(dst, 0xFF, 16);
    D_8005071C->field_E54->field_D = 0;
    while (*src != 0xFF) {
        *dst = *src;
        D_8005071C->field_E54->field_D++;
        src++;
        dst++;
    }
}

void func_80070EC0(u32 *p, u32 n) {
    if (*p < n) {
        *p += n;
    }
}

s32 func_80070EE0(s32 *p) {
    u32 *tbl = (u32 *)p;
    u32 base = (u32)p;
    s32 n = 0;
    s32 i;
    Stg40MapRel *m;
    Stg40MapRoomRel *r;
    u32 *q;

    while (*tbl != 0) {
        if (*tbl < base) {
            *tbl += base;
            m = (Stg40MapRel *)*tbl;
            m->field_0 += base;
            for (i = 0; i < 8; i++) {
                q = &m->field_8[i];
                *q += base;
                r = (Stg40MapRoomRel *)*q;
                func_80070EC0(&r->field_0[0], base);
                func_80070EC0(&r->field_0[1], base);
                func_80070EC0(&r->field_0[2], base);
                func_80070EC0(&r->field_0[3], base);
                func_80070EC0(&r->field_0[4], base);
            }
        }
        tbl++;
        n++;
    }
    return n;
}

s32 func_80070FEC(Stg40Pick *out, Stg40Rec3 *e, u8 key) {
    s32 r = -1;
    s32 n = 0;

    for (; e->field_0 != 0xFF; e++) {
        if (e->field_2 == key) {
            out->field_0 = e->field_0;
            out->field_2 = e->field_1;
            n++;
            out++;
        }
    }
    if (n != 0) {
        r = func_800711C4(n);
    }
    return r;
}

void func_8007107C(void) {
    Stg40Pick buf[20];
    Stg40Rec3 *list = D_80072B60->field_14->field_4;
    s32 r;

    r = func_80070FEC(buf, list, 0);
    D_80072B60->field_20.field_0 = buf[r].field_0;
    D_80072B60->field_20.field_2 = buf[r].field_2;
    r = func_80070FEC(buf, list, 1);
    D_80072B60->field_24.field_2 = -1;
    D_80072B60->field_24.field_0 = -1;
    if (r != -1) {
        D_80072B60->field_24.field_0 = buf[r].field_0;
        D_80072B60->field_24.field_2 = buf[r].field_2;
    }
    r = func_80070FEC(buf, list, 2);
    D_80072B60->field_28.field_2 = -1;
    D_80072B60->field_28.field_0 = -1;
    if (r != -1) {
        D_80072B60->field_28.field_0 = buf[r].field_0;
        D_80072B60->field_28.field_2 = buf[r].field_2;
    }
}

s32 func_80071180(void) {
    return (Rand_Next() & 0xFFF) * 100 / 4096;
}

s32 func_800711C4(s32 n) {
    return (Rand_Next() & 0xFFF) * n / 4096;
}

s32 func_80071204(s32 i) {
    s32 r = func_8006E858(7);
    r = r < 0 ? 0 : r;
    return D_800729F8[r][i];
}

s32 func_80071258(s32 i) {
    return func_80071180() < D_80072A1C[i];
}

s32 func_80071294(void) {
    s32 r = D_80072A30[func_80071180() / 4];

    if (r >= 4 && r < 16) {
        if (func_8006E820(D_800729E0[r - 4]) <= 0) {
            r = 16;
        }
    }
    return r;
}

void func_80071310(s32 a0, s32 a1) {
    s32 base = 0x1FD0011;

    if (a0 == 0) {
        base = 0x1FD0047;
    }
    switch (a1) {
    case 0:
        func_80067610(1, base, (s32)D_80050720->field_D1, (s32)func_8006755C(0, D_80072B60->field_58));
        break;
    case 1:
        func_80067610(1, base + 1, (s32)func_8006755C(0, D_80072B60->field_58), 0);
        break;
    case 2:
    case 3:
        func_80067610(1, base + a1, 0, 0);
        break;
    case 16:
        func_80067610(1, base + 5, 0, 0);
        break;
    default:
        {
            s32 k = D_800729E0[a1 - 4];
            func_80067610(1, base + 4, Item_GetNameText(D_80050720->slotItems[k]), 0);
        }
        break;
    }
}

void func_8007142C(s32 a0, s32 a1) {
    s32 i;
    s32 k;
    DigiRosterEntry *r;
    Stg40Blk5071C *g;

    switch (a0) {
    case 0:
        D_80072B60->field_58 = a1 * 400;
        func_8006E8F4(D_80072B60->field_58);
        break;
    case 1:
        D_80072B60->field_58 = a1 * 10;
        func_8006EA84(3);
        for (i = 0; i < D_80072B60->field_140; i++) {
            r = &D_80050720->elems[D_80072B60->field_128[i]];
            r->hp = ((s16)r->hp - D_80072B60->field_58 > 0) ? (u16)r->hp - (u16)D_80072B60->field_58 : 1;
        }
        break;
    case 2:
        D_8005071C->field_BA0 = (D_8005071C->field_BA0 | 2) & ~0x80;
        D_8005071C->field_BA4 = func_800711C4(4) + 1;
        break;
    case 3:
        g = D_8005071C;
        g->field_BB5 = 0;
        g->field_BA0 = (g->field_BA0 | 1) & ~0x40;
        break;
    default:
        k = D_800729E0[a0 - 4];
        D_80050720->slotStatus[k] = 1;
        break;
    case 16:
        break;
    }
}

s32 func_800715DC(void) {
    s32 r = func_8006E820();

    if (r > 0) {
        r = 1;
    }
    return r;
}

s32 func_80071608(void) {
    u8 buf[16];
    s32 n = 0;
    s32 r = -1;
    u32 i;

    for (i = 0; i < 12; i++) {
        if (func_80022518(D_80072A4C[i]) > 0) {
            buf[n++] = D_80072A4C[i];
        }
    }
    if (n != 0) {
        r = func_80071180() / (100 / n);
        r = buf[r > n - 1 ? n - 1 : r];
    }
    return r;
}

INCLUDE_RODATA("asm/USA/stag4000/rodata", D_80063728);
INCLUDE_RODATA("asm/USA/stag4000/rodata", D_80063738);
INCLUDE_RODATA("asm/USA/stag4000/rodata", D_80063748);
INCLUDE_ASM("asm/USA/stag4000/nonmatchings/stag4000_C2CC", func_800716EC);

void func_80071DB4(void) {
    Stg40Ent48 *e = D_8005071C->field_18;
    s32 a;
    s32 b;
    s32 i;
    s32 v;

    a = func_8006E858(13);
    a = a < 0 ? 0 : a;
    b = func_8006E858(14);
    b = b < 0 ? 0 : b;
    for (i = 0; i < D_8005071C->field_C; e++, i++) {
        if (e->field_0 & 0x8000) {
            switch (e->field_8) {
            case 6:
            case 8:
                v = D_80072A58[e->field_10[1] - 1 + a * 5];
                if (func_80071180() < v) {
                    e->field_0 |= 0x1000;
                }
                break;
            case 9:
            case 10:
            case 11:
            case 12:
                v = D_80072A78[e->field_10[1] - 1 + b * 3];
                if (func_80071180() < v) {
                    e->field_0 |= 0x1000;
                }
                break;
            }
        }
    }
}

Stg40Ent48 *func_80071F50(s32 id) {
    Stg40Ent48 *e;
    s32 i;

    for (i = 0, e = D_8005071C->field_18; i < 41; i++, e++) {
        if (e->field_0 & 0x8000) {
            if ((id != 0 && id == e->field_4) || (id == 0 && (e->field_0 & 1))) {
                return e;
            }
        }
    }
    return NULL;
}

void func_80071FBC(s32 *arg) {
    Stg40Ent48 *e;
    Actor *t;
    s32 st;

    st = -1;
    D_80072B60->field_178 = *arg++;
    D_80072B60->field_17C.field_0 = arg[0] - 1;
    D_80072B60->field_17C.field_2 = arg[1] - 1;
    D_80072B60->field_180 = 0;
    D_80072B60->field_184 = NULL;
    e = func_80071F50(D_80072B60->field_178);
    if (e != NULL) {
        t = e->field_14;
        D_80072B60->field_180 = 1;
        switch (D_80072B60->field_17C.field_0) {
        default:
            st = 5;
            break;
        case 0x62:
            if (D_80072B60->field_17C.field_2 == -1) {
                st = 4;
                D_80072B60->field_184 = t;
            } else {
                st = 6;
                D_80072B60->field_180 = 0;
            }
            break;
        case 0x61:
            e->field_E = (D_80072B60->field_17C.field_2 << 12) / 360;
            D_80072B60->field_180 = 0;
            break;
        case 0x60:
            e->field_0 |= 0x200;
            D_80072B60->field_180 = 0;
            break;
        }
        if (st != -1) {
            Task_SetState1(t, (u8)st);
        }
    }
}

void func_800720EC(void) {
    D_80072B60->field_180 = 0;
}

s16 func_800720FC(void) {
    return D_80072B60->field_180;
}

s32 func_80072114(void) {
    return D_80072BC0->stateLevel1;
}

void func_8007212C(Stg40Blk20 *blk, s32 a1, s32 a2, s32 a3) {
    Actor *t = D_80072BC0;
    Stg40BC0Work *w = (Stg40BC0Work *)t->work;

    w->field_88 = *blk;
    w->field_A8 = a1;
    w->field_AC = a2;
    w->field_B0 = a3;
    Task_SetState1(t, 1);
}

void func_800721A8(Stg40Cmd *src) {
    Stg40BC0Work *w = (Stg40BC0Work *)D_80072BC0->work;
    s32 i;

    w->field_B4 = w->field_BC;
    w->field_B8 = 0;
    for (i = 0; src->field_0 != 0; i++, src++) {
        w->field_BC[i] = *src;
        w->field_B8++;
    }
}

void func_80072250(Actor *a0) {
    Stg40BC0Work *w = (Stg40BC0Work *)a0->work;
    Stg40Cmd *c;

    if (w->field_B8 != 0) {
        c = w->field_B4;
        func_8007212C(&c->field_C, c->field_0, c->field_4, c->field_8);
        w->field_B8--;
        w->field_B4++;
    }
}

void func_800722B8(Actor *task) {
    Stg40BC0Work *w = (Stg40BC0Work *)task->work;
    s32 dx;
    s32 x0;
    s32 y0;
    s32 z0;

    if (task->stateLevel2 >= w->field_A8) {
        do {
            w->field_0.words[0] = w->field_88.words[4];
            w->field_0.words[1] = w->field_88.words[5];
            w->field_0.words[2] = w->field_88.words[6];
            w->field_7C[1] = (u16)w->field_AC;
            if (w->field_B8 != 0) {
                func_80072250(task);
            } else {
                Task_SetState1(task, 0);
            }
        } while (0);
        return;
    }
    x0 = w->field_88.words[0];
    dx = (x0 - w->field_88.words[4]) / w->field_A8;
    y0 = w->field_88.words[1];
    z0 = w->field_88.words[2];
    w->field_0.words[0] = x0 - dx * task->stateLevel2;
    w->field_0.words[1] = y0 - ((y0 - w->field_88.words[5]) / w->field_A8) * task->stateLevel2;
    w->field_0.words[2] = z0 - ((z0 - w->field_88.words[6]) / w->field_A8) * task->stateLevel2;
    w->field_84 = 1;
    w->field_7C[1] = (u16)w->field_AC + (w->field_B0 / w->field_A8) * (w->field_A8 - task->stateLevel2);
    task->stateLevel2 = task->stateLevel2 + 1;
}

void func_80072418(Actor *a0, Block1C *a1) {
    Stg40BC0Work *w = (Stg40BC0Work *)a0->work;

    D_80072BC0 = a0;
    w->field_0 = *a1;
    w->field_B4 = 0;
    w->field_B8 = 0;
}

void func_80072468(Actor *a0) {
    Stg40BC0Work *w = (Stg40BC0Work *)a0->work;
    Stg40RView v;

    switch (a0->stateLevel0) {
    case 0:
    default:
        GsInitCoordinate2(0, &w->field_1C);
        w->field_84 = 1;
        Task_NextState0(a0);
        break;
    case 1:
        switch (a0->stateLevel1) {
        case 0:
        default:
            if (w->field_B8 != 0) {
                func_80072250(a0);
            }
            break;
        case 1:
            func_800722B8(a0);
            break;
        }
        w->field_84 = 0;
        RotMatrixYXZ(w->field_7C, &w->field_1C.coord);
        w->field_1C.coord.t[0] = w->field_6C;
        w->field_1C.coord.t[1] = w->field_70;
        w->field_1C.coord.t[2] = w->field_74;
        w->field_1C.flg = 0;
        v.field_0[0] = w->field_0.words[0];
        v.field_0[1] = w->field_0.words[1];
        v.field_0[2] = w->field_0.words[2];
        v.field_0[3] = w->field_0.words[3];
        v.field_0[4] = w->field_0.words[4];
        v.field_0[5] = w->field_0.words[5];
        v.field_18 = 0;
        v.field_1C = &w->field_1C;
        GsSetProjection(w->field_0.words[6]);
        GsSetRefView2(&v);
        break;
    case 2:
        break;
    }
}

void func_800725A8(void) {
}
