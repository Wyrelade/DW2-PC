#include "common.h"
#include "stag1100/stag1100.h"
#include "stag1100/stag1100_funcs.h"
#include "stag1100/bg.h"
#include "stag1100/modemenu.h"
#include "stag1100/cardmenu.h"
#include "stag1100/card.h"

/* Memory card icon frames (TIM files). */
INCLUDE_BIN(Stg11_CardIconTim1, "assets/stag1100/card_icon1.tim");
INCLUDE_BIN(Stg11_CardIconTim2, "assets/stag1100/card_icon2.tim");
INCLUDE_BIN(Stg11_CardIconTim3, "assets/stag1100/card_icon3.tim");
DATA_LABEL(Stg11_CardIconImage, Stg11_CardIconTim1, 0x14);
DATA_LABEL(Stg11_CardIcon2, Stg11_CardIconTim2, 0x40);
DATA_LABEL(Stg11_CardIcon3, Stg11_CardIconTim3, 0x40);

TaskDesc Stg11_CardTaskDesc = {
    (TaskInitFn)Stg11_CardTaskInit, Stg11_CardTaskUpdate, Stg11_CardTaskDestroy, (TaskFn)Stg11_CardTaskDraw,
    0x22044, 0,
};
/* Task_DescTable[6]: task ids 0x600-0x606. */
TaskDesc *Stg11_TaskDescs[] = {
    &Stg11_RootDesc, &Stg11_CardTaskDesc, &Stg11_BgDesc, &Stg11_ModeMenuDesc,
    &Stg11_CardMenuDesc, &Stg11_VsPartyDesc, &Stg11_ModeMenuDesc,
};
/* Unreferenced. */
u8 D_800684A4[4] = "AAA\\";
Actor *Stg11_CardTask;
Stg11SaveWork *Stg11_CardWork;

/* Memory card title: "Digimon World 2" in Shift-JIS full-width letters. */
const u8 Stg11_CardTitle[32] = "\x82\x63\x82\x89\x82\x87\x82\x89\x82\x8D\x82\x8F\x82\x8E"
                               "\x82\x76\x82\x8F\x82\x92\x82\x8C\x82\x84\x82\x51";
void Stg11_CardInitHeader(void) {
    Stg11SaveWork *w = (Stg11SaveWork *)Stg11_CardTask->work;
    struct Stg11CardBlock *h = &w->u34.s;
    struct Stg11CardBlock *h2 = h;
    u8 *data = w->u34.s.data;

    h->magic[0] = 'S';
    h->magic[1] = 'C';
    h->iconFlag = 0x13;
    h->blocks = 2;
    Stg11_CardSetTitle(Stg11_CardTitle);
    memset(h->reserved, 0, 0x1C);
    h->clut = Stg11_CardIconImage.clut;
    h->icons[0] = Stg11_CardIconImage.icon;
    h2->icons[1] = Stg11_CardIcon2;
    h2->icons[2] = Stg11_CardIcon3;
    memset(data, 0, 0x3DFC);
    h->version = 0x102;
}

u8 *Stg11_CardGetDataBuf(void) {
    return ((Stg11SaveWork *)Stg11_CardTask->work)->u34.s.data;
}

u8 *Stg11_CardGetTransferBuf(void) {
    return ((Stg11SaveWork *)Stg11_CardTask->work)->transferBuf;
}

void Stg11_CardSetTitle(const u8 *arg0) {
    s32 i = 0;
    u8 *d = ((Stg11SaveWork *)Stg11_CardTask->work)->u34.s.title;
    u8 c;

    memset(d, i, 0x40);
loop:
    c = *arg0++;
    if (c == 0) {
        return;
    }
    *d++ = c;
    *d++ = *arg0++;
    if (++i < 0x20) {
        goto loop;
    }
}

void Stg11_CardStartOp(u8 arg0, s32 arg1) {
    Stg11SaveWork *w = (Stg11SaveWork *)Stg11_CardTask->work;
    Task_SetState1(Stg11_CardTask, arg0);
    w->port = arg1;
    w->portResult[arg1][0] = -1;
    w->result = -1;
    w->progressTotal = -1;
    w->opStarted = 0;
}

s32 Stg11_CardGetResult(void) {
    return ((Stg11SaveWork *)Stg11_CardTask->work)->result;
}

void Stg11_CardSetFileName(const u8 *arg0, u8 arg1) {
    Stg11SaveWork *w = (Stg11SaveWork *)Stg11_CardTask->work;
    strcpy(w->fileName, arg0);
    w->isTransferFile = arg1;
}

s32 Stg11_CardGetProgress(s32 arg0) {
    Stg11SaveWork *w = (Stg11SaveWork *)Stg11_CardTask->work;
    s32 d = w->progressTotal;
    s32 r;

    if (d != 0) {
        if (d < 0) {
            r = 0;
        } else {
            r = arg0 * w->progressDone / d;
        }
    } else {
        r = arg0;
    }
    return r;
}

s32 Stg11_CardChecksum(Stg11SaveWork *arg0) {
    u16 *p = arg0->u34.sum;
    u16 sum = 0;
    s32 n = 0x1FFF;

    while (1) {
        if (--n == -1) {
            break;
        }
        sum ^= *p++;
        if (--n == -1) {
            break;
        }
        sum += *p++;
    }
    return sum;
}

s32 Stg11_CardFileOp(Stg11SaveWork *arg0, s32 arg1, s32 arg2) {
    s32 r = -1;
    s32 chan = (arg2 != 0) << 4;
    s32 cmd;
    s32 st;

    if (MemCardSync(1, &cmd, &st) == -1) {
        switch (arg1) {
        case 6:
            st = MemCardCreateFile(chan, (s32)Stg11_CardWork->fileName, 2);
            switch (st) {
            case 1:
                r = 0;
                break;
            case 4:
                r = -1;
                if (++arg0->retryCount >= 5) {
                    r = 1;
                }
                break;
            default:
                r = -1;
                if (++arg0->retryCount >= 5) {
                    r = 6;
                }
                break;
            case 7:
                r = 8;
                break;
            case 0:
            case 6:
                r = 9;
                break;
            }
            break;
        case 7:
            st = MemCardOpen(chan, (s32)Stg11_CardWork->fileName, 1);
            switch (st) {
            case 0:
                r = 9;
                Card_CloseFile();
                break;
            case 1:
                r = 0;
                break;
            case 2:
                r = -1;
                if (++arg0->retryCount >= 5) {
                    r = 0xB;
                }
                break;
            case 4:
                r = -1;
                if (++arg0->retryCount >= 5) {
                    r = 1;
                }
                break;
            case 3:
            case 5:
            default:
                r = 0xA;
                break;
            }
            break;
        case 8:
            st = MemCardFormat(chan);
            switch (st) {
            case 2:
            default:
                if (++arg0->retryCount >= 5) {
                    r = 7;
                }
                break;
            case 1:
                r = 0;
                break;
            case 0:
                r = 0x10;
                break;
            }
            break;
        }
    }
    return r;
}

s32 Stg11_CardAsyncOp(Stg11SaveWork *arg0, s32 arg1, s32 arg2) {
    s32 r = -1;
    s32 chan = (arg2 != 0) << 4;
    s32 cmd;
    s32 st;
    s32 sum;

    switch (MemCardSync(1, &cmd, &st)) {
    default:
        if (arg0->progressDone < arg0->progressTotal) {
            arg0->progressDone++;
        }
        break;
    case -1:
        arg0->progressTotal = 1;
        arg0->progressDone = 0;
        arg0->opStarted = 1;
        switch (arg1) {
        case 1:
            MemCardExist(chan);
            break;
        case 2:
            arg0->progressTotal = 0x26;
            MemCardAccept(chan);
            break;
        case 3:
            arg0->progressTotal = 0x83;
            arg0->u34.s.checksum = Stg11_CardChecksum(arg0);
            MemCardWriteFile(chan, (s32)arg0->fileName, (s32)&arg0->u34, 0, 0x4000);
            break;
        case 4:
            if (arg0->isTransferFile == 0) {
                arg0->progressTotal = 0x81;
                MemCardReadFile(chan, (s32)arg0->fileName, (s32)&arg0->u34, 0, 0x4000);
            } else {
                arg0->progressTotal = 0x3C8;
                MemCardReadFile(chan, (s32)arg0->fileName, (s32)arg0->transferBuf, 0, 0x1E000);
            }
            break;
        }
        break;
    case 1:
        if (arg0->opStarted == 0) {
            return -1;
        }
        arg0->progressDone = arg0->progressTotal;
        switch (arg1) {
        case 1:
            if (cmd == arg1) {
                switch (st) {
                case 0:
                case 3:
                    r = 2;
                    break;
                case 1:
                case 2:
                    r = 0;
                    break;
                }
            }
            break;
        case 2:
            if (cmd == arg1) {
                switch (st) {
                case 0:
                case 3:
                    r = 2;
                    break;
                case 1:
                    r = 0;
                    break;
                case 2:
                default:
                    r = -1;
                    if (++arg0->retryCount >= 5) {
                        r = 0xB;
                    }
                    break;
                case 4:
                    r = -1;
                    if (++arg0->retryCount >= 5) {
                        r = 1;
                    }
                    break;
                }
            }
            break;
        case 3:
            if (cmd == 4) {
                switch (st) {
                case 0:
                    r = 0xC;
                    break;
                case 1:
                    r = 0;
                    break;
                case 2:
                case 4:
                default:
                    r = -1;
                    if (++arg0->retryCount >= 5) {
                        r = 5;
                    }
                    break;
                case 3:
                    r = 0xF;
                    break;
                case 5:
                    r = 0xA;
                    break;
                }
            }
            break;
        case 4:
            if (cmd == 3) {
                switch (st) {
                case 0:
                    r = 0xD;
                    if (arg0->isTransferFile == 0) {
                        sum = arg0->u34.s.checksum;
                        if (sum == Stg11_CardChecksum(arg0) && arg0->u34.s.version == 0x102) {
                            r = 0xD;
                        } else {
                            r = 0xE;
                        }
                    }
                    break;
                case 1:
                    r = 0;
                    break;
                case 5:
                    r = 0xA;
                    break;
                case 2:
                case 4:
                default:
                    r = -1;
                    if (++arg0->retryCount >= 5) {
                        r = 4;
                    }
                    break;
                case 3:
                    r = 0xF;
                    break;
                }
            }
            break;
        }
        break;
    }
    return r;
}

void Stg11_CardRunOp(Actor *arg0, s32 arg1) {
    Stg11SaveWork *w = (Stg11SaveWork *)arg0->work;
    s32 *p;

    switch (arg0->stateLevel2) {
    case 1:
        break;
    case 0:
    default:
        w->portResult[w->port][0] = -1;
        w->retryCount = 0;
        Task_SetState2(arg0, 10);
        break;
    case 10:
        p = &w->portResult[w->port][0];
        if (arg1 < 5) {
            *p = Stg11_CardAsyncOp(w, arg1, w->port);
        } else {
            *p = Stg11_CardFileOp(w, arg1, w->port);
        }
        if (*p != -1) {
            Task_SetState2(arg0, 1);
        }
        break;
    }
    w->result = w->portResult[w->port][0];
}

void Stg11_CardTaskInit(void) {
}

void Stg11_CardTaskUpdate(Actor *arg0) {
    Stg11SaveWork *w = (Stg11SaveWork *)arg0->work;

    switch (arg0->stateLevel0) {
    case 0:
    default:
        Stg11_CardTask = arg0;
        Stg11_CardWork = (Stg11SaveWork *)arg0->work;
        Task_NextState0(arg0);
        break;
    case 1:
        switch (arg0->stateLevel1) {
        case 4:
            Stg11_CardRunOp(arg0, 2);
            break;
        case 2:
            Stg11_CardRunOp(arg0, 1);
            break;
        case 7:
            Stg11_CardRunOp(arg0, 6);
            break;
        case 5:
            Stg11_CardRunOp(arg0, 7);
            break;
        case 6:
            Stg11_CardRunOp(arg0, 8);
            break;
        case 8:
            Stg11_CardRunOp(arg0, 3);
            break;
        case 9:
            Stg11_CardRunOp(arg0, 4);
            break;
        case 0:
        case 1:
        case 3:
            break;
        }
        break;
    case 2:
        break;
    }
    w->curOp = arg0->stateLevel1;
}

void Stg11_CardTaskDestroy(Actor *arg0) {
    Task_DefaultDestroy(arg0);
}

void Stg11_CardTaskDraw(void) {
}
