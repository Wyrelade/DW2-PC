#include "common.h"
#include "stag3500/stag3500.h"
#include "stag3500/bg.h"
#include "stag3500/fightbg.h"
#include "stag3500/actionload.h"
#include "stag3500/stag3500_funcs.h"
#include "stag3500/vsmenu.h"
#include "stag3500/matchup.h"
#include "stag3500/battle.h"

void Stg35_PartsAlloc(Stg35PartsHandle *arg0) {
    Stg35PartsLayout *p = (Stg35PartsLayout *)Mem_Alloc(0x24, 2);

    arg0->load = p;
    Mem_Zero(p, 0x24);
    arg0->load->scaleY = 0x1000;
}

void Stg35_PartsFree(Stg35PartsHandle *arg0) {
    if (arg0->load != NULL) {
        Mem_Free(arg0->load);
        arg0->load = NULL;
    }
}

void Stg35_PartsSetFile(Stg35PartsHandle *arg0, s32 arg1) {
    arg0->load->fileId = arg1;
}

void Stg35_PartsDraw(Stg35PartsHandle *arg0) {
    Stg35PartsLayout *l = arg0->load;
    Stg35Part *p = (Stg35Part *)Cd_GetFileEntry(l->fileId);
    Stg35Part *q;
    Stg35Part *r;
    Stg35Slide *s;
    s32 f;
    s32 c;
    s16 t;
    s32 k;

    switch (l->mode) {
    case 1:
        l->scaleY += 0x200;
        f = l->scaleY >= 0x1000;
        q = p;
        if (q->fileId != 0) {
            r = q;
            do {
                r->unscaled = f;
                r->scaleY = l->scaleY;
                q++;
                r++;
            } while (q->fileId != 0);
        }
        if (f) {
            l->mode = 0;
        }
        break;
    case 2:
        l->scaleY -= 0x200;
        q = p;
        if (q->fileId != 0) {
            r = q;
            do {
                r->unscaled = 0;
                r->scaleY = l->scaleY;
                q++;
                r++;
            } while (q->fileId != 0);
        }
        if (l->scaleY == 0) {
            l->mode = 0;
        }
        break;
    }
    for (k = 0; k < 2; k++) {
        if (l->u.slide[k].active != 0) {
            q = p;
            if (q->fileId != 0) {
                r = q;
                do {
                    if (r->groupMask & l->u.slide[k].mask) {
                        if (l->u.slide[k].dir != 0) {
                            l->u.slide[k].accum += l->u.slide[k].speed;
                            r->x += (s16)l->u.slide[k].accum >> 8;
                            l->u.slide[k].accum = (u8)l->u.slide[k].accum;
                            c = l->u.slide[k].target > r->x;
                        } else {
                            l->u.slide[k].accum += l->u.slide[k].speed;
                            r->x -= (s16)l->u.slide[k].accum >> 8;
                            l->u.slide[k].accum = (u8)l->u.slide[k].accum;
                            c = r->x > l->u.slide[k].target;
                        }
                        t = l->u.slide[k].target;
                        if (!c) {
                            r->x = t;
                            l->u.slide[k].active = 0;
                        }
                    }
                    q++;
                    r++;
                } while (q->fileId != 0);
            }
        }
    }
    Gfx_DrawParts((s32)p);
}

void Stg35_PartsHideByMask(Stg35PartsHandle *arg0, s32 arg1) {
    Gfx_HidePartsByMask((GfxPartMaskView *)Cd_GetFileEntry(arg0->load->fileId), arg1);
}

void Stg35_PartsShowGroup(Stg35PartsHandle *arg0, s32 mask) {
    GfxPart *p = (GfxPart *)Cd_GetFileEntry(arg0->load->fileId);
    GfxPart *q = p;

    if (p->fileId != 0) {
        do {
            if (q->groupMask & mask) {
                q->visible = 1;
            }
            p++;
            q++;
        } while (p->fileId != 0);
    }
}

void Stg35_PartsHideGroup(Stg35PartsHandle *arg0, s32 mask) {
    GfxPart *p = (GfxPart *)Cd_GetFileEntry(arg0->load->fileId);
    GfxPart *q = p;

    if (p->fileId != 0) {
        do {
            if (q->groupMask & mask) {
                q->visible = 0;
            }
            p++;
            q++;
        } while (p->fileId != 0);
    }
}

void Stg35_PartsStartOpen(Stg35PartsHandle *arg0) {
    Stg35PartsLayout *l = arg0->load;
    l->mode = 1;
    l->scaleY = 0;
}

void Stg35_PartsStartScaleOut(Stg35PartsHandle *arg0) {
    Stg35PartsLayout *l = arg0->load;
    l->mode = 2;
    l->scaleY = 0x1000;
}

void Stg35_PartsSetPalette(Stg35PartsHandle *arg0, s32 mask, s32 v) {
    GfxPart *p = (GfxPart *)Cd_GetFileEntry(arg0->load->fileId);
    GfxPart *q = p;

    if (p->fileId != 0) {
        do {
            if (q->groupMask & mask) {
                q->palette = v;
            }
            p++;
            q++;
        } while (p->fileId != 0);
    }
}

void Stg35_PartsSetX(Stg35PartsHandle *arg0, s32 mask, s32 v) {
    GfxPart *p = (GfxPart *)Cd_GetFileEntry(arg0->load->fileId);
    GfxPart *q = p;

    if (p->fileId != 0) {
        do {
            if (q->groupMask & mask) {
                q->x = v;
            }
            p++;
            q++;
        } while (p->fileId != 0);
    }
}

void Stg35_PartsSetY(Stg35PartsHandle *arg0, s32 mask, s32 v) {
    GfxPart *p = (GfxPart *)Cd_GetFileEntry(arg0->load->fileId);
    GfxPart *q = p;

    if (p->fileId != 0) {
        do {
            if (q->groupMask & mask) {
                q->y = v;
            }
            p++;
            q++;
        } while (p->fileId != 0);
    }
}

void Stg35_PartsStartSlideX(Stg35PartsHandle *arg0, s32 idx, s32 mask, s32 v, s32 target, s32 speed) {
    Stg35PartsLayout *l = arg0->load;
    GfxPart *p = (GfxPart *)Cd_GetFileEntry(l->fileId);
    GfxPart *q;

    l->u.slide[idx].mask = mask;
    l->u.slide[idx].active = 1;
    l->u.slide[idx].target = target;
    if (speed < 0) {
        l->u.slide[idx].dir = 0;
        l->u.slide[idx].speed = -speed;
    } else {
        l->u.slide[idx].dir = 1;
        l->u.slide[idx].speed = speed;
    }
    if (p->fileId != 0) {
        q = p;
        do {
            if (q->groupMask & mask) {
                q->x = v;
            }
            p++;
            q++;
        } while (p->fileId != 0);
    }
}

void Stg35_PartsSetNumber(Stg35PartsHandle *arg0, s32 arg1, s32 arg2, s32 arg3) {
    Gfx_SetPartsNumber((GfxPart *)Cd_GetFileEntry(arg0->load->fileId), arg1, arg2, arg3);
}
