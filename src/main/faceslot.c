#include "common.h"
#include "main/game.h"
#include "main/task.h"

/* Task callbacks the descriptors below name (defined further down). */
void Gfx_TexSlotTaskInit(Actor *arg0);
void Gfx_TexSlotTaskKill(Actor *arg0);
/* Image ids Gfx_FindOrLoadImageSlot keeps in the face texture slots, -1 ends the list. */
s16 Gfx_FaceImageIds[] = {
    0x003, 0x014, 0x01F, 0x02D, 0x02E, 0x030, 0x075, 0x07C, 0x095, 0x096, 0x097, 0x0D9,
    0x0F7, 0x0F9, 0x0FA, 0x0FB, 0x0FE, 0x194, 0x195, 0x196, 0x197, 0x198, 0x199, 0x19E,
    0x19F, 0x1A2, 0x1A3, 0x1A4, 0x1A5, 0x1A6, 0x1A7, 0x1A8, 0x1A9, 0x1AA, 0x1AB, 0x1AC,
    0x1AD, 0x1AE, 0x1AF, 0x1B0, 0x1B1, 0x1B2, 0x1B3, 0x1B4, 0x1B5, 0x1B6, 0x1B7, 0x1B8,
    0x1BC, 0x1BD, 0x1C2, 0x1F4, 0x212, 0x192, 0x191, 0x190, -1,
};
TaskDesc D_80040E20 = { 0, Gfx_TexSlotTaskInit, Gfx_TexSlotTaskKill, 0, 0x94, 0 };

void Gfx_TexSlotTaskInit(Actor *arg0) {
    ActorWork *w = arg0->work;
    if (arg0->stateLevel0 == 0) {
        w->field_0 = Gfx_ReserveTexSlot();
        Task_NextState0(arg0);
    }
}

void Gfx_TexSlotTaskKill(Actor *arg0) {
    Gfx_ReleaseTexSlot(arg0->work->field_0);
    Task_DefaultDestroy(arg0);
}

void Gfx_FindOrLoadImageSlot(s32 id, GfxImageInfo *out, GfxVramPos *pos, GfxVramPos *clut) {
    GfxImageCache *t;
    s32 i;
    s32 k;
    s32 *p;
    RECT r;
    RECT r2;

    t = (GfxImageCache *)Task_FindFirst(10, -1, -1)->work;
    for (i = 0; i < 18; i++) {
        if (t->slot[i].id == id) {
            goto found;
        }
    }
    for (i = 0; i < 18; i++) {
        if (t->slot[i].id == 0) {
            goto load;
        }
    }
    {
        s32 m = 0;
        s32 bi = 0;
        for (i = 0; i < 18; i++) {
            if (m < t->slot[i].t) {
                m = t->slot[i].t;
                bi = i;
            }
        }
        i = bi;
    }
load:
    for (k = 0; Gfx_FaceImageIds[k] != -1; k++) {
        if (Gfx_FaceImageIds[k] == id) {
            break;
        }
    }
    p = (s32 *)Cd_GetFileEntry(k + 0x3250000);
    p++;
    if (*p++ & 8) {
        r.x = t->sheet->vramX + i / 16 * 16;
        r.y = t->sheet->vramY + 0xF0;
        r.y += i % 16;
        r.w = 16;
        r.h = 1;
        LoadImage(&r, ((TimBlkData *)p)->data);
    }
    p = (s32 *)((u8 *)p + *p);
    r2.x = t->sheet->vramX + i % 3 * 10;
    r2.y = t->sheet->vramY + i / 3 * 40;
    r2.w = ((TimBlkData *)p)->w;
    r2.h = ((TimBlkData *)p)->h;
    LoadImage(&r2, ((TimBlkData *)p)->data);
    t->slot[i].id = Gfx_FaceImageIds[k];
found:
    t->slot[i].t = Sys_State.vsyncWait;
    *out = *t->sheet;
    pos->x = i % 3 * 40;
    pos->y = i / 3 * 40;
    clut->x = i / 16 * 16;
    clut->y = i % 16 + 0xF0;
}
