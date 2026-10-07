#include <stdio.h>
#include <string.h>

#include "libmcrd.h"
#include "psyq_log.h"
#include "psyq_vblank.h"
#include "host/host.h"

/* Psy-Q libmcrd on raw PS1 memory card images (P1.9). Each port holds one 128 KB card image
 * (host/card.c: card1.mcd / card2.mcd); this file is the BIOS card file system on it and the
 * libmcrd call model the game expects (stag1100 card.c):
 * - Card layout (psx-spx "Memory Card Data Format"): 16 blocks of 8 KB, 64 frames of 128 bytes
 *   each. Block 0 is the header block: frame 0 "MC", frames 1..15 the directory (one entry per
 *   data block 1..15: 0x51 first block of a file, 0x52 middle, 0x53 last, 0xA0..0xA3 free or
 *   deleted; file size at 4, next block at 8 (block - 1, 0xFFFF = end), name at 0x0A, XOR check
 *   byte at 0x7F), frames 16..35 the broken sector list.
 * - Sync calls (MemCardOpen, MemCardCreateFile, MemCardFormat) return their McErr* result.
 * - Async calls (MemCardExist, MemCardAccept, MemCardReadFile, MemCardWriteFile) return 1 when
 *   registered (0 while another one runs); MemCardSync(1, &cmd, &result) then returns 0 while it
 *   runs, 1 once with McFunc* + McErr* when it is done, -1 when nothing is registered. The work
 *   finishes on VBlanks like the PS1 card driver: one 128-byte sector per VBlank for reads and
 *   writes (about 7.7 KB/s), 16 for Accept (the directory frames), 1 for Exist. A finished write
 *   saves the card image file at once.
 * - Cards stay inserted: Exist / Accept never report McErrNewCard. A missing card file is
 *   created formatted on first use (user decision 2026-10-07). A file of the wrong size is an
 *   invalid card (McErrCardInvalid). */

#define CARD_SIZE 0x20000
#define BLOCK_SIZE 0x2000
#define FRAME_SIZE 0x80
#define NAME_LEN 21

typedef struct {
    unsigned char img[CARD_SIZE];
    int state; /* 0 not loaded yet, 1 usable, -1 invalid file */
} Card;

static Card cards_[2];
static int started_;
static int open_; /* a file is open (MemCardOpen until MemCardClose) */

/* The async operation in flight. */
static struct {
    int busy, done;
    int cmd, result;
    int vblanks;
    /* work done at completion */
    int port, write, ofs, bytes, entry;
    unsigned char *buf;
} op_;

static unsigned char *frame(Card *c, int n) { return c->img + n * FRAME_SIZE; }

static void set_check(unsigned char *f) {
    unsigned char x = 0;
    int i;
    for (i = 0; i < FRAME_SIZE - 1; i++) x ^= f[i];
    f[FRAME_SIZE - 1] = x;
}

static void format_card(Card *c) {
    int i;
    memset(c->img, 0, CARD_SIZE);
    frame(c, 0)[0] = 'M';
    frame(c, 0)[1] = 'C';
    set_check(frame(c, 0));
    for (i = 1; i < 16; i++) {
        unsigned char *f = frame(c, i);
        f[0] = 0xA0;
        f[8] = f[9] = 0xFF;
        set_check(f);
    }
    for (i = 16; i < 36; i++) {
        unsigned char *f = frame(c, i);
        memset(f, 0xFF, 4);
        f[8] = f[9] = 0xFF;
        set_check(f);
    }
    memset(frame(c, 36), 0xFF, (63 - 36) * FRAME_SIZE);
    memcpy(frame(c, 63), frame(c, 0), FRAME_SIZE);
}

static int port_of(int chan) { return (chan >> 4) & 1; }

/* The card on `port`, loaded (or created formatted) on first use; NULL for an invalid file. */
static Card *card(int port) {
    Card *c = &cards_[port];
    if (c->state == 0) {
        int r = Host_CardLoad(port, c->img, CARD_SIZE);
        if (r > 0) {
            c->state = 1;
        } else if (r == 0) {
            format_card(c);
            c->state = 1;
            printf("[card] port %d: new formatted card\n", port + 1);
            Host_CardStore(port, c->img, CARD_SIZE);
        } else {
            c->state = -1;
        }
    }
    return c->state > 0 ? c : NULL;
}

static int formatted(Card *c) { return c->img[0] == 'M' && c->img[1] == 'C'; }

static unsigned int rd32(const unsigned char *p) { return p[0] | p[1] << 8 | p[2] << 16 | (unsigned int)p[3] << 24; }

/* Directory entry (1..15) of the file `name`, or 0. */
static int find_file(Card *c, const char *name) {
    int i;
    for (i = 1; i < 16; i++) {
        unsigned char *f = frame(c, i);
        if (f[0] == 0x51 && strncmp((const char *)f + 0x0A, name, NAME_LEN) == 0) return i;
    }
    return 0;
}

/* Checks for a card file operation: McErrNone or the error. */
static int card_status(int chan, Card **out) {
    Card *c = card(port_of(chan));
    *out = c;
    if (c == NULL) return McErrCardInvalid;
    if (!formatted(c)) return McErrNotFormat;
    return McErrNone;
}

static int start(int cmd, int result, int vblanks) {
    if (op_.busy || op_.done) return 0;
    op_.busy = 1;
    op_.cmd = cmd;
    op_.result = result;
    op_.vblanks = vblanks < 1 ? 1 : vblanks;
    op_.buf = NULL;
    return 1;
}

/* Read or write `bytes` at `ofs` of the file at directory entry `entry`, following its block
 * chain. */
static void transfer(Card *c, int entry, unsigned char *buf, int ofs, int bytes, int write) {
    int e = entry, pos = 0;
    while (e >= 1 && e < 16 && bytes > 0) {
        unsigned char *data = c->img + e * BLOCK_SIZE;
        int next = frame(c, e)[8] | frame(c, e)[9] << 8;
        if (ofs < pos + BLOCK_SIZE) {
            int from = ofs - pos;
            int n = BLOCK_SIZE - from;
            if (n > bytes) n = bytes;
            if (write) memcpy(data + from, buf, (size_t)n);
            else memcpy(buf, data + from, (size_t)n);
            buf += n;
            ofs += n;
            bytes -= n;
        }
        pos += BLOCK_SIZE;
        e = next == 0xFFFF ? 0 : next + 1;
    }
}

static void finish(void) {
    op_.busy = 0;
    op_.done = 1;
    if (op_.buf != NULL && op_.result == McErrNone) {
        Card *c = &cards_[op_.port];
        transfer(c, op_.entry, op_.buf, op_.ofs, op_.bytes, op_.write);
        if (op_.write && !Host_CardStore(op_.port, c->img, CARD_SIZE)) op_.result = McErrCardInvalid;
    }
}

void Psyq_CardVBlank(void) {
    if (started_ && op_.busy && --op_.vblanks <= 0) finish();
}

void MemCardInit(int val) {
    PSYQ_LOG("%d", val);
    memset(&op_, 0, sizeof(op_));
}

void MemCardStart(void) {
    PSYQ_LOG("");
    started_ = 1;
}

int MemCardExist(int chan) {
    Card *c = card(port_of(chan));
    return start(McFuncExist, c != NULL ? McErrNone : McErrCardInvalid, 1);
}

int MemCardAccept(int chan) {
    Card *c;
    return start(McFuncAccept, card_status(chan, &c), 16);
}

int MemCardOpen(int chan, char *file, int flag) {
    Card *c;
    int st = card_status(chan, &c);
    (void)flag;
    if (st != McErrNone) return st;
    if (!find_file(c, file)) return McErrFileNotExist;
    open_ = 1;
    return McErrNone;
}

void MemCardClose(void) { open_ = 0; }

/* Decomp name of MemCardClose (stag1100 card.c). */
void Card_CloseFile(void) { MemCardClose(); }

static int file_op(int cmd, int chan, char *file, u_long *adrs, int ofs, int bytes, int write) {
    Card *c;
    int st = card_status(chan, &c);
    int e = 0;
    if (st == McErrNone) {
        e = find_file(c, file);
        if (e == 0) st = McErrFileNotExist;
        else if (ofs < 0 || bytes < 0 || (unsigned int)(ofs + bytes) > rd32(frame(c, e) + 4)) {
            printf("[card] %s %s: offset 0x%X + 0x%X past the file\n", write ? "write" : "read", file, ofs, bytes);
            st = McErrFileNotExist;
        }
    }
    if (!start(cmd, st, (bytes + FRAME_SIZE - 1) / FRAME_SIZE)) return 0;
    if (st == McErrNone) {
        op_.port = port_of(chan);
        op_.write = write;
        op_.ofs = ofs;
        op_.bytes = bytes;
        op_.entry = e;
        op_.buf = (unsigned char *)adrs;
        printf("[card] port %d: %s %s, 0x%X bytes at 0x%X\n", op_.port + 1, write ? "write" : "read", file,
               bytes, ofs);
    }
    return 1;
}

int MemCardReadFile(int chan, char *file, u_long *adrs, int ofs, int bytes) {
    return file_op(McFuncReadFile, chan, file, adrs, ofs, bytes, 0);
}

int MemCardWriteFile(int chan, char *file, u_long *adrs, int ofs, int bytes) {
    return file_op(McFuncWriteFile, chan, file, adrs, ofs, bytes, 1);
}

int MemCardSync(int mode, int *cmds, int *rslt) {
    if (!op_.busy && !op_.done) return -1;
    if (op_.busy) {
        if (mode != 0) return 0;
        finish(); /* mode 0 waits: finish now (the game only polls with mode 1) */
    }
    op_.done = 0;
    if (cmds != NULL) *cmds = op_.cmd;
    if (rslt != NULL) *rslt = op_.result;
    return 1;
}

int MemCardCreateFile(int chan, char *file, int blocks) {
    Card *c;
    int st = card_status(chan, &c);
    int i, n = 0, prev = 0;
    if (st != McErrNone) return st;
    if (find_file(c, file)) return McErrAlreadyExist;
    for (i = 1; i < 16; i++) n += (frame(c, i)[0] & 0xF0) == 0xA0;
    if (blocks < 1 || n < blocks) return McErrBlockFull;
    n = 0;
    for (i = 1; i < 16 && n < blocks; i++) {
        unsigned char *f = frame(c, i);
        if ((f[0] & 0xF0) != 0xA0) continue;
        memset(f, 0, FRAME_SIZE);
        if (n == 0) {
            unsigned int size = (unsigned int)blocks * BLOCK_SIZE;
            f[0] = 0x51;
            f[4] = (unsigned char)size;
            f[5] = (unsigned char)(size >> 8);
            f[6] = (unsigned char)(size >> 16);
            strncpy((char *)f + 0x0A, file, NAME_LEN - 1);
        } else {
            unsigned char *p = frame(c, prev);
            f[0] = n == blocks - 1 ? 0x53 : 0x52;
            p[8] = (unsigned char)(i - 1);
            p[9] = 0;
            set_check(p);
        }
        f[8] = f[9] = 0xFF;
        set_check(f);
        prev = i;
        n++;
    }
    printf("[card] port %d: created %s (%d blocks)\n", port_of(chan) + 1, file, blocks);
    return Host_CardStore(port_of(chan), c->img, CARD_SIZE) ? McErrNone : McErrCardInvalid;
}

int MemCardFormat(int chan) {
    Card *c = card(port_of(chan));
    if (c == NULL) return McErrCardInvalid;
    format_card(c);
    printf("[card] port %d: formatted\n", port_of(chan) + 1);
    return Host_CardStore(port_of(chan), c->img, CARD_SIZE) ? McErrNone : McErrCardInvalid;
}
