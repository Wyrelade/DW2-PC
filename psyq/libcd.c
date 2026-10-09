#include <stdio.h>
#include <string.h>

#include "host/host.h"
#include "libcd.h"
#include "psyq_log.h"

/* libcd stubs (P1.1). CdIntToPos / CdPosToInt are real (BCD conversion). CdControlF drives the
 * read protocol main/cdread.c expects, with no disc behind it: every command completes, ReadN
 * delivers one DataReady per sector until Pause, CdGetSector hands out a 2340-byte sector (mode
 * 0xA0) whose header holds the sector's MSF and whose data is zero. The callbacks run after the
 * outermost CdControlF has done its work (a small event queue), so a whole file read finishes
 * inside the CdControlF(Setloc) that Cd_ReadFileAsync ends with; the game's Cd_PollRead spins
 * never wait. P1.3: the sector data comes from dw2.pak (Host_PakSector: LBA -> file -> pack
 * offset); the header MSF and mode stay synthesized from the LBA. Each read logs one line
 * ("[cd] file 0x...") when it ends. */

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
static int log_file = -2;   /* file of the read in progress (-2 none, -1 no file at the LBA) */
static int log_lba, log_count;
static int st_lba = -1;     /* Setloc of the STR stream (CdControl before CdRead2) */
static int st_end = -1;     /* frame number StGetNext reports (-1: not computed yet) */

static int bcd(int v) {
    return (v / 10) * 16 + v % 10;
}

static int unbcd(int v) {
    return (v >> 4) * 10 + (v & 0xF);
}

static void enqueue(u_char ev) {
    queue[q_tail++ & 15] = ev;
}

/* One line per read: the file, its first sector and how many sectors were delivered. */
static void log_read_end(void) {
    if (log_file == -1) {
        printf("[cd] lba %d: %d sectors outside every file (zeros)\n", log_lba, log_count);
    } else if (log_file >= 0) {
        printf("[cd] file 0x%03X: %d sectors from lba %d\n", log_file, log_count, log_lba);
    }
    log_file = -2;
}

static void load_sector(int lba) {
    int i = lba + 150;
    int id;

    sector[0] = (u_char)bcd(i / (60 * 75));
    sector[1] = (u_char)bcd(i / 75 % 60);
    sector[2] = (u_char)bcd(i % 75);
    sector[3] = 2; /* mode 2 */
    id = Host_PakSector(lba, sector + 4);
    sector_pos = 0;
    if (log_file == -2) {
        log_file = id;
        log_lba = lba;
        log_count = 0;
    }
    log_count++;
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
    if (com == CdlSetloc && param != 0) {
        st_lba = (unbcd(param[0]) * 60 + unbcd(param[1])) * 75 + unbcd(param[2]) - 150;
    }
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
        log_read_end();
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

/* STR streaming (PR.4). CdRead2 after CdControl(Setloc) starts the stream on that file (2x speed,
 * mode 0x80). StGetNext delivers the next whole video frame once the CD would have read its last
 * chunk: 150 sectors per second from the start, on the VBlank clock (VBlanks * 150 * 1001 /
 * 60000). It copies each video chunk's 2016 data bytes into the ring (StSetRing memory, the frame
 * at its start; the game frees it before asking again) and keeps the first chunk's 32-byte STR
 * header for *header. XA audio sectors are skipped (PR.5). While the next frame is not in yet one
 * host VBlank passes (the PS1 keeps taking VBlank interrupts while the game polls), then 1 = no
 * frame; the game's loop asks again. So a movie runs at 15 fps (10 sectors a frame).
 *
 * Headless runs without --movies keep the P1.10 stub: no stream is read; StGetNext hands out one
 * frame whose header frame number lies past the end of the movie (file sectors / 10, the game's
 * own end test is sectors / 10 - 10) with width and height 0, so stag1000's movie task ends on
 * its first frame and the next game mode starts (classic baselines unchanged). */

#define STR_CHUNK 2016 /* video data bytes per sector after the 32-byte STR header */

static u_long *st_ring;
static int st_ring_bytes;
static int st_on;               /* a stream is running */
static int st_file, st_secs;    /* its file and size in sectors */
static int st_pos;              /* next sector to read, from the stream start */
static int st_frames;           /* frames delivered */
static unsigned long long st_t0; /* VBlank count at CdRead2 */
static u_long st_header[8];

int CdRead2(int mode) {
    PSYQ_LOG("0x%X", mode);
    if (Host_MoviesOn() && st_ring != 0) {
        st_file = Host_PakFileAt(st_lba, &st_secs);
        st_on = st_file >= 0;
        st_pos = 0;
        st_frames = 0;
        st_t0 = Host_VBlankCount();
        printf("[movie] file 0x%03X (%d sectors, lba %d): playing\n", st_file, st_secs, st_lba);
    }
    return 1;
}

void StSetRing(u_long *ring_addr, u_long ring_size) {
    PSYQ_LOG("%p, %u", (void *)ring_addr, ring_size);
    st_ring = ring_addr;
    st_ring_bytes = (int)ring_size * 2048;
    st_end = -1;
}

void StUnSetRing(void) {
    PSYQ_LOG("");
    if (st_on) {
        printf("[movie] file 0x%03X stopped after %d frames, %llu VBlanks\n", st_file, st_frames,
               Host_VBlankCount() - st_t0);
    }
    st_ring = 0;
    st_on = 0;
    st_end = -1;
}

void StSetStream(u_long mode, u_long start_frame, u_long end_frame, void (*func1)(), void (*func2)()) {
    PSYQ_LOG("0x%X, %u, 0x%X, %p, %p", mode, start_frame, end_frame, (void *)func1, (void *)func2);
}

u_long StFreeRing(u_long *base) {
    PSYQ_LOG("%p", (void *)base);
    return 0;
}

/* The next frame from the stream into the ring: 0 when one is complete, 1 when the CD has not
 * read that far yet, 2 at the end of the file. */
static int stream_frame(void) {
    unsigned long long due = (Host_VBlankCount() - st_t0) * 150 * 1001 / 60000;
    static u_char body[2336];

    while (st_pos < st_secs && (unsigned long long)st_pos < due) {
        const u_char *d = body + 8;
        int cn, cc;

        Host_PakSector(st_lba + st_pos++, body);
        if (body[2] & 0x04) {
            continue; /* XA audio sector (PR.5) */
        }
        if (d[0] != 0x60 || d[1] != 0x01 || d[2] != 0x01 || d[3] != 0x80) {
            continue; /* not an STR video sector */
        }
        cn = d[4] | d[5] << 8;
        cc = d[6] | d[7] << 8;
        if ((cn + 1) * STR_CHUNK > st_ring_bytes) {
            continue;
        }
        memcpy((u_char *)st_ring + cn * STR_CHUNK, d + 32, STR_CHUNK);
        if (cn == 0) {
            memcpy(st_header, d, sizeof(st_header));
        }
        if (cn == cc - 1) {
            st_frames++;
            return 0;
        }
    }
    return st_pos >= st_secs ? 2 : 1;
}

u_long StGetNext(u_long **addr, u_long **header) {
    /* STR sector header: 0x0160 0x8001, sector number / count, frame number (word 2), frame
     * size, width / height (word 4). */
    static u_long frame_header[8];
    static u_long frame_data[64];

    PSYQ_LOG("%p, %p", (void *)addr, (void *)header);
    if (st_on) {
        switch (stream_frame()) {
        case 0:
            *addr = st_ring;
            *header = st_header;
            return 0;
        case 1:
            Host_VBlank();
            return 1;
        default:
            /* past the file end: a frame number past the end, so the game stops the movie */
            st_header[2] = 0x7FFFFFFF;
            *addr = st_ring;
            *header = st_header;
            return 0;
        }
    }
    if (st_end < 0) {
        int sectors;
        int id = Host_PakFileAt(st_lba, &sectors);

        st_end = sectors / 10 + 1;
        printf("[movie] stub: file 0x%03X (%d sectors, lba %d), StGetNext reports frame %d (past the end), "
               "no decode\n", id, sectors, st_lba, st_end);
    }
    memset(frame_header, 0, sizeof(frame_header));
    frame_header[0] = 0x80010160;
    frame_header[2] = (u_long)st_end;
    *addr = frame_data;
    *header = frame_header;
    return 0;
}

void StCdInterrupt(void) {
    PSYQ_LOG("");
}
