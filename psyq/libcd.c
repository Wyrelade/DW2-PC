#include <string.h>

#include "libcd.h"
#include "psyq_log.h"

/* libcd stubs (P1.1). CdIntToPos / CdPosToInt are real (BCD conversion). CdControlF drives the
 * read protocol main/cdread.c expects, with no disc behind it: every command completes, ReadN
 * delivers one DataReady per sector until Pause, CdGetSector hands out a 2340-byte sector (mode
 * 0xA0) whose header holds the sector's MSF and whose data is zero. The callbacks run after the
 * outermost CdControlF has done its work (a small event queue), so a whole file read finishes
 * inside the CdControlF(Setloc) that Cd_ReadFileAsync ends with; the game's Cd_PollRead spins
 * never wait. P1.3 puts the disc sectors behind the same protocol. */

u_long StCdIntrFlag;

static CdlCB sync_cb;
static CdlCB ready_cb;

static int cur_lba;         /* sector the next DataReady delivers */
static int reading;         /* ReadN until Pause */
static int depth;           /* nesting of CdControlF (callbacks issue commands) */
static u_char queue[16];    /* pending sync callback events */
static int q_head, q_tail;
static u_char sector[2340]; /* MSF + mode, subheader, 2048 data bytes, (EDC/ECC not used) */
static int sector_pos;

static int bcd(int v) {
    return (v / 10) * 16 + v % 10;
}

static int unbcd(int v) {
    return (v >> 4) * 10 + (v & 0xF);
}

static void enqueue(u_char ev) {
    queue[q_tail++ & 15] = ev;
}

static void load_sector(int lba) {
    int i = lba + 150;

    memset(sector, 0, sizeof(sector));
    sector[0] = (u_char)bcd(i / (60 * 75));
    sector[1] = (u_char)bcd(i / 75 % 60);
    sector[2] = (u_char)bcd(i % 75);
    sector[3] = 2; /* mode 2 */
    sector_pos = 0;
}

/* Runs queued command completions, then one DataReady per sector while reading. */
static void run_events(void) {
    u_char result[8] = { 0 };

    for (;;) {
        if (q_head != q_tail) {
            u_char ev = queue[q_head++ & 15];
            if (sync_cb != 0) {
                sync_cb(ev, result);
            }
        } else if (reading && ready_cb != 0) {
            load_sector(cur_lba);
            ready_cb(CdlDataReady, result);
            cur_lba++;
        } else {
            break;
        }
    }
}

int CdInit(void) {
    PSYQ_LOG("");
    return 1;
}

int CdSetDebug(int level) {
    PSYQ_LOG("%d", level);
    return 0;
}

int CdPosToInt(CdlLOC *p) {
    PSYQ_LOG("%p", (void *)p);
    return (unbcd(p->minute) * 60 + unbcd(p->second)) * 75 + unbcd(p->sector) - 150;
}

CdlLOC *CdIntToPos(int i, CdlLOC *p) {
    PSYQ_LOG("%d, %p", i, (void *)p);
    i += 150;
    p->minute = (u_char)bcd(i / (60 * 75));
    p->second = (u_char)bcd(i / 75 % 60);
    p->sector = (u_char)bcd(i % 75);
    return p;
}

int CdLastCom(void) {
    PSYQ_LOG("");
    return 0;
}

int CdSync(int mode, u_char *result) {
    PSYQ_LOG("%d, %p", mode, (void *)result);
    return CdlComplete;
}

CdlCB CdSyncCallback(CdlCB func) {
    CdlCB old = sync_cb;

    PSYQ_LOG("%p", (void *)func);
    sync_cb = func;
    return old;
}

CdlCB CdReadyCallback(CdlCB func) {
    CdlCB old = ready_cb;

    PSYQ_LOG("%p", (void *)func);
    ready_cb = func;
    return old;
}

int CdControl(u_char com, u_char *param, u_char *result) {
    PSYQ_LOG("0x%02X, %p, %p", com, (void *)param, (void *)result);
    return 1;
}

int CdControlF(u_char com, u_char *param) {
    PSYQ_LOG("0x%02X, %p", com, (void *)param);
    switch (com) {
    case CdlSetloc:
        cur_lba = (unbcd(param[0]) * 60 + unbcd(param[1])) * 75 + unbcd(param[2]) - 150;
        break;
    case CdlReadN:
    case CdlReadS:
        reading = 1;
        break;
    case CdlPause:
        reading = 0;
        break;
    }
    enqueue(CdlComplete);
    if (depth == 0) {
        depth++;
        run_events();
        depth--;
    }
    return 1;
}

int CdControlB(u_char com, u_char *param, u_char *result) {
    PSYQ_LOG("0x%02X, %p, %p", com, (void *)param, (void *)result);
    return 1;
}

int CdGetSector(void *madr, int size) {
    u_char *d = madr;
    int n = size * 4;

    PSYQ_LOG("%p, %d", madr, size);
    while (n-- > 0) {
        *d++ = sector_pos < (int)sizeof(sector) ? sector[sector_pos] : 0;
        sector_pos++;
    }
    return 1;
}

int CdRead2(int mode) {
    PSYQ_LOG("0x%X", mode);
    return 1;
}

void StSetRing(u_long *ring_addr, u_long ring_size) {
    PSYQ_LOG("%p, %u", (void *)ring_addr, ring_size);
}

void StUnSetRing(void) {
    PSYQ_LOG("");
}

void StSetStream(u_long mode, u_long start_frame, u_long end_frame, void (*func1)(), void (*func2)()) {
    PSYQ_LOG("0x%X, %u, 0x%X, %p, %p", mode, start_frame, end_frame, (void *)func1, (void *)func2);
}

u_long StFreeRing(u_long *base) {
    PSYQ_LOG("%p", (void *)base);
    return 0;
}

u_long StGetNext(u_long **addr, u_long **header) {
    PSYQ_LOG("%p, %p", (void *)addr, (void *)header);
    return 1; /* no frame ready */
}

void StCdInterrupt(void) {
    PSYQ_LOG("");
}
