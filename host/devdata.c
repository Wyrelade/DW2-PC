#include "common.h"

#if DW2_DEV

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL3/SDL.h>

#include "host/devdata.h"
#include "host/host.h"

/* PD.7 / PD.3 dev overlay data (host/devdata.h), loaded once; the PD.4 edit checks read it on the
 * game thread too. The tables are read whole from dw2.pak through Host_PakReadFile (a stream of
 * its own, so the game thread's CD reads go on untouched) and decoded here; the game's loaders
 * (Digi_FindBaseData, Item_FindById, Skill_FindById, Cd_GetFileEntry) are not called and no game variable is read except the two
 * constant tables DevData_InitConst copies before the game thread starts. Record layouts:
 * PLAN.md PD Findings "PD.7 table formats". */

#define FILE_DIGIMNDT 0xC6C
#define FILE_ITEMDATA 0x45E
#define FILE_WAZADATA 0x25B
#define FILE_SYSTEXT 0x1FD
#define WORDS 67 /* Text_BuiltinStrings entries (text.c) */

/* game C constants (main/game.h, stag2000/stag2000.h; not included: their K&R declarations clash
 * with stdio here) */
extern u8 *Text_BuiltinStrings[];
extern u8 Stg20_DnaTypeIndexTbl[3][3];
extern u8 Stg20_DnaResultTbl[][3][8][8];

typedef struct {
    uint8_t *data;
    int size;
} File;

static int loaded;
static char words[WORDS][24];
static int words_ok;
static uint8_t dna_types[3][3];
static uint8_t dna_table[3][3][8][8];

static DevDigi *digis;
static int digi_count;
static short digi_at[DEVDATA_DIGI_IDS]; /* id -> index + 1 */
static DevItem *items;
static int item_count;
static short item_at[DEVDATA_ITEM_IDS];
static DevSkill *skills;
static int skill_count;
static short skill_at[DEVDATA_SKILL_IDS];
static char type_names[3][16], rank_names[4][16], spec_names[6][16];
static DevDest *dests;
static int dest_count;
static SDL_InitState load_state;
static SDL_AtomicInt ready, failed;

static uint32_t rd32(const File *f, int o) {
    const uint8_t *p = f->data + o;

    return (uint32_t)p[0] | (uint32_t)p[1] << 8 | (uint32_t)p[2] << 16 | (uint32_t)p[3] << 24;
}

static int rd16(const File *f, int o) {
    return (int16_t)(f->data[o] | f->data[o + 1] << 8);
}

/* glyph -> text (PLAN.md PD Findings: "Text encoding"); NULL = no plain form */
static const char *glyph(int c, char *tmp) {
    static const char *const punct[] = {
        "(O)", "(X)", "(Tri)", "(Sq)", "&", "II", "?", "!", "/", "(note)", "\xC2\xB7", "-", /* 3E..49 */
        "L1", "L2", "L3", "L4", "L5", NULL, NULL, NULL, NULL, ">",                            /* 4A..53 */
        ",", ".", "'", "\"", ";", ":", "%", "+", "=", "#",                                   /* 54..5D */
    };

    if (c < 10) {
        tmp[0] = (char)('0' + c);
    } else if (c < 0x24) {
        tmp[0] = (char)('A' + c - 0x0A);
    } else if (c < 0x3E) {
        tmp[0] = (char)('a' + c - 0x24);
    } else if (c <= 0x5D) {
        return punct[c - 0x3E];
    } else {
        return NULL;
    }
    tmp[1] = 0;
    return tmp;
}

typedef struct {
    char *out;
    int n, len;
} Out;

static void put(Out *o, const char *s) {
    while (*s != 0 && o->len + 1 < o->n) {
        o->out[o->len++] = *s++;
    }
    o->out[o->len] = 0;
}

static void putf(Out *o, const char *fmt, int v) {
    char b[32];

    snprintf(b, sizeof(b), fmt, v);
    put(o, b);
}

static void decode(Out *o, const uint8_t *s, int max, const uint8_t *player, int depth) {
    char tmp[4];
    int i;

    for (i = 0; i < max && s[i] != 0xFF; i++) {
        int c = s[i];
        const char *g;

        if (c < 0xEF) {
            g = glyph(c, tmp);
            if (g != NULL) {
                put(o, g);
            } else {
                putf(o, "{%02X}", c);
            }
            continue;
        }
        switch (c) {
        case 0xFE: /* new line */
        case 0xFD: /* space */
        case 0xFC: /* new page */
            put(o, " ");
            break;
        case 0xFB: /* wait for X */
            break;
        case 0xEF: /* glyph 0xF0 + k */
            if (i + 1 < max) {
                putf(o, "{%02X}", 0xF0 + s[++i]);
            }
            break;
        case 0xF1: /* Digimon / item name by 3 digit bytes */
        case 0xF2:
            if (i + 3 < max) {
                int id = s[i + 1] * 100 + s[i + 2] * 10 + s[i + 3];

                put(o, c == 0xF1 ? DevData_DigiName(id) : DevData_ItemName(id));
                i += 3;
            }
            break;
        case 0xF0: /* substitution */
            if (i + 1 < max) {
                int k = s[++i];

                if (k == 0) {
                    if (player != NULL && depth == 0) {
                        decode(o, player, 0x10, NULL, depth + 1);
                    } else {
                        put(o, "<tamer>");
                    }
                } else if (k == 5) {
                    put(o, "<beetle>");
                } else if (k < 5) {
                    putf(o, "<arg%d>", k);
                } else if (k - 6 < WORDS && words_ok) {
                    put(o, words[k - 6]);
                } else {
                    putf(o, "{F0 %02X}", k);
                }
            }
            break;
        case 0xF8: /* choice, one argument byte */
        case 0xFA: /* window, one argument byte */
            i++;
            break;
        default: /* box, portrait and script commands */
            putf(o, "{%02X}", c);
            break;
        }
    }
}

char *DevData_Text(const uint8_t *src, int max, const uint8_t *playerName, char *out, int n) {
    Out o = { out, n, 0 };

    if (n <= 0) {
        return out;
    }
    out[0] = 0;
    if (src != NULL) {
        decode(&o, src, max, playerName, 0);
    }
    return out;
}

/* text at file offset `off`, bounded by the file */
static void file_text(const File *f, uint32_t off, char *out, int n) {
    out[0] = 0;
    if (off < (uint32_t)f->size) {
        DevData_Text(f->data + off, f->size - (int)off, NULL, out, n);
    }
}

/* game text bytes up to 0xFF, cut to n - 1 glyphs (0xFF always ends) */
static void raw_text(const File *f, uint32_t off, uint8_t *out, int n) {
    int i;

    memset(out, 0xFF, (size_t)n);
    for (i = 0; i < n - 1 && off + (uint32_t)i < (uint32_t)f->size && f->data[off + i] != 0xFF; i++) {
        out[i] = f->data[off + i];
    }
}

void DevData_InitConst(void) {
    int i;

    /* text.c dictionary (F0 k, k >= 6): game C data, never written */
    for (i = 0; i < WORDS; i++) {
        Out o = { words[i], (int)sizeof(words[i]), 0 };

        words[i][0] = 0;
        decode(&o, Text_BuiltinStrings[i], 32, NULL, 1);
    }
    words_ok = 1;
    /* stag2000 dna.c tables: overlay data, copied before Ovl_Load can restore it under us */
    memcpy(dna_types, Stg20_DnaTypeIndexTbl, sizeof(dna_types));
    memcpy(dna_table, Stg20_DnaResultTbl, sizeof(dna_table));
}

static int read_file(int id, File *f) {
    f->data = (uint8_t *)Host_PakReadFile(id, &f->size);
    if (f->data == NULL || f->size < 16) {
        printf("[devdata] file 0x%03X: cannot read from the pack\n", id);
        free(f->data);
        f->data = NULL;
        return 0;
    }
    return 1;
}

/* MODELDT names (0xCB9 / 0xCBA / 0xCBB): DigiData records of 0x28 from word 0 */
static void load_names(const File *f) {
    uint32_t p = rd32(f, 0);

    for (; p + 0x28 <= (uint32_t)f->size; p += 0x28) {
        int id = (int)(rd32(f, (int)p + 4) >> 1) & 0x7FFF;
        DevDigi *d;

        if (id == 0) {
            break;
        }
        if (id >= DEVDATA_DIGI_IDS || digi_at[id] != 0) {
            continue;
        }
        d = &digis[digi_count++];
        memset(d, 0, sizeof(*d));
        d->id = (int16_t)id;
        d->modelFile = (int16_t)rd16(f, (int)p + 6);
        file_text(f, rd32(f, (int)p), d->name, (int)sizeof(d->name));
        raw_text(f, rd32(f, (int)p), d->rawName, (int)sizeof(d->rawName));
        digi_at[id] = (short)digi_count;
    }
}

static int digi_cmp(const void *a, const void *b) {
    return ((const DevDigi *)a)->id - ((const DevDigi *)b)->id;
}

static int load_digis(void) {
    static const int name_files[3] = { 0xCB9, 0xCBB, 0xCBA };
    File base;
    int i, n = 0;

    digis = (DevDigi *)calloc(DEVDATA_DIGI_IDS, sizeof(DevDigi));
    if (digis == NULL) {
        return 0;
    }
    for (i = 0; i < 3; i++) {
        File f;

        if (!read_file(name_files[i], &f)) {
            return 0;
        }
        load_names(&f);
        free(f.data);
    }
    qsort(digis, (size_t)digi_count, sizeof(DevDigi), digi_cmp);
    memset(digi_at, 0, sizeof(digi_at));
    for (i = 0; i < digi_count; i++) {
        digi_at[digis[i].id] = (short)(i + 1);
    }
    /* DIGIMNDT: DigiBaseData records of 0x12 from offset 0 */
    if (!read_file(FILE_DIGIMNDT, &base)) {
        return 0;
    }
    for (int p = 0; p + 0x12 <= base.size; p += 0x12) {
        const uint8_t *r = base.data + p;
        int id = rd16(&base, p);
        int a = r[4] | r[5] << 8, g = r[6] | r[7] << 8;
        DevDigi *d;

        if (id == 0) {
            break;
        }
        if (id < 0 || id >= DEVDATA_DIGI_IDS || digi_at[id] == 0) {
            printf("[devdata] DIGIMNDT id 0x%X has no name record\n", id);
            continue;
        }
        d = &digis[digi_at[id] - 1];
        d->hasBase = 1;
        d->learnedSkill = r[2];
        d->dnaGroup = r[3];
        d->type = (uint8_t)(a & 0xF);
        d->rank = (uint8_t)(a >> 4 & 0xF);
        d->specialty = (uint8_t)(a >> 8 & 0xF);
        d->growth[0] = (uint8_t)(a >> 12);
        d->growth[1] = (uint8_t)(g & 0xF);
        d->growth[2] = (uint8_t)(g >> 4 & 0xF);
        d->growth[3] = (uint8_t)(g >> 8 & 0xF);
        d->growth[4] = (uint8_t)(g >> 12);
        memcpy(d->dpBounds, r + 8, 5);
        memcpy(d->dpTargets, r + 0xD, 4);
        n++;
    }
    free(base.data);
    printf("[devdata] %d Digimon names, %d with DIGIMNDT data\n", digi_count, n);
    return 1;
}

static int load_items(void) {
    File f;
    uint32_t p;

    if (!read_file(FILE_ITEMDATA, &f)) {
        return 0;
    }
    items = (DevItem *)calloc(DEVDATA_ITEM_IDS, sizeof(DevItem));
    if (items == NULL) {
        free(f.data);
        return 0;
    }
    for (p = rd32(&f, 0); p + 0x10 <= (uint32_t)f.size && item_count < DEVDATA_ITEM_IDS; p += 0x10) {
        int id = rd16(&f, (int)p);
        uint32_t w0 = rd32(&f, (int)p), w1 = rd32(&f, (int)p + 4);
        DevItem *it;

        if (id == 0) {
            break;
        }
        if (id < 0 || id >= DEVDATA_ITEM_IDS || item_at[id] != 0) {
            continue;
        }
        it = &items[item_count++];
        it->id = (int16_t)id;
        it->category = (uint8_t)(w0 >> 16);
        it->level = (uint8_t)(w0 >> 24 & 0xF);
        it->useKind = (uint8_t)(w0 >> 30);
        it->price = (int32_t)(w1 & 0xFFFFFF);
        it->bodyMask = (uint8_t)(w1 >> 24);
        file_text(&f, rd32(&f, (int)p + 8), it->name, (int)sizeof(it->name));
        file_text(&f, rd32(&f, (int)p + 12), it->desc, (int)sizeof(it->desc));
        item_at[id] = (short)item_count;
    }
    free(f.data);
    printf("[devdata] %d items\n", item_count);
    return 1;
}

static int load_skills(void) {
    File f;
    uint32_t p;

    if (!read_file(FILE_WAZADATA, &f)) {
        return 0;
    }
    skills = (DevSkill *)calloc(DEVDATA_SKILL_IDS, sizeof(DevSkill));
    if (skills == NULL) {
        free(f.data);
        return 0;
    }
    for (p = rd32(&f, 0); p + 0x44 <= (uint32_t)f.size && skill_count < DEVDATA_SKILL_IDS; p += 0x44) {
        int id = rd16(&f, (int)p);
        uint32_t w0 = rd32(&f, (int)p);
        DevSkill *k;

        if (id == 0) {
            break;
        }
        if (id < 0 || id >= DEVDATA_SKILL_IDS || skill_at[id] != 0) {
            continue;
        }
        k = &skills[skill_count++];
        k->id = (int16_t)id;
        k->castAnim = (uint8_t)(w0 >> 16 & 3);
        k->type = (uint8_t)(w0 >> 18 & 3);
        k->target = (uint8_t)(w0 >> 20 & 0xF);
        k->specialty = (uint8_t)(w0 >> 24 & 0xF);
        k->rank = (uint8_t)(w0 >> 28);
        k->mp = f.data[p + 4];
        k->power = (int16_t)rd16(&f, (int)p + 8);
        file_text(&f, rd32(&f, (int)p + 0x24), k->name, (int)sizeof(k->name));
        file_text(&f, rd32(&f, (int)p + 0x28), k->desc, (int)sizeof(k->desc));
        skill_at[id] = (short)skill_count;
    }
    free(f.data);
    printf("[devdata] %d skills\n", skill_count);
    return 1;
}

static int load_labels(void) {
    File f;
    int i;

    if (!read_file(FILE_SYSTEXT, &f)) {
        return 0;
    }
    /* entries 0xC3 + type, 0xC6 + rank, 0xCA + specialty (digistatus.c) */
    if (f.size > 0xD0 * 4) {
        for (i = 0; i < 3; i++) {
            file_text(&f, rd32(&f, (0xC3 + i) * 4), type_names[i], (int)sizeof(type_names[i]));
        }
        for (i = 0; i < 4; i++) {
            file_text(&f, rd32(&f, (0xC6 + i) * 4), rank_names[i], (int)sizeof(rank_names[i]));
        }
        for (i = 0; i < 6; i++) {
            file_text(&f, rd32(&f, (0xCA + i) * 4), spec_names[i], (int)sizeof(spec_names[i]));
        }
    }
    free(f.data);
    return 1;
}

#define FILE_AREASEL 0xD29 /* area select records, entry gameMode - 0x32A (Stg20_GetMapDest) */
#define FILE_MAPS 0x309    /* city map headers, entry area - 0x301 (Stg20_GetMapInfo) */
#define AREASEL_TABLES 5   /* modes 0x32A..0x32E (stag2000.c: below 0x32F is area select) */
#define CITY_AREAS 40      /* 0x301..0x328 have map exits */
#define DESTS 512

static void add_dest(int mode, int arg, int named, const char *name) {
    int i;

    for (i = 0; i < dest_count; i++) {
        if (dests[i].mode == mode && dests[i].arg == arg) {
            return;
        }
    }
    if (dest_count < DESTS) {
        dests[dest_count].mode = (int16_t)mode;
        dests[dest_count].arg = (uint8_t)arg;
        dests[dest_count].named = (uint8_t)named;
        snprintf(dests[dest_count].name, sizeof(dests[dest_count].name), "%s", name);
        dest_count++;
    }
}

static int dest_cmp(const void *a, const void *b) {
    const DevDest *x = (const DevDest *)a, *y = (const DevDest *)b;

    return x->mode != y->mode ? x->mode - y->mode : x->arg - y->arg;
}

/* the name an area select record gives a mode (any arg), or NULL */
static const char *area_name(int mode) {
    int i;

    for (i = 0; i < dest_count; i++) {
        if (dests[i].named && dests[i].mode == mode) {
            return dests[i].name;
        }
    }
    return NULL;
}

/* PD.4 warp destinations (PLAN.md PD Findings "PD.4 warp"): the area select records with their
 * names, then every map exit's target (mode, start record) that no record names. */
static int load_dests(void) {
    File f, m;
    int t, i, k, named;

    dests = (DevDest *)calloc(DESTS, sizeof(DevDest));
    if (dests == NULL || !read_file(FILE_AREASEL, &f)) {
        return 0;
    }
    if (!read_file(FILE_MAPS, &m)) {
        free(f.data);
        return 0;
    }
    /* Stg20PickRec, 0x18 bytes: +0 s16 flag id (-1 ends), +4 text, +0x10 s16 mode, +0x12 u8 arg */
    for (t = 0; t < AREASEL_TABLES; t++) {
        uint32_t o = rd32(&f, t * 4);

        for (i = 0; i < 64 && o + (uint32_t)(i + 1) * 0x18 <= (uint32_t)f.size; i++) {
            uint32_t r = o + (uint32_t)i * 0x18;
            char name[40];

            if (rd16(&f, (int)r) == -1) {
                break;
            }
            file_text(&f, rd32(&f, (int)r + 4), name, (int)sizeof(name));
            add_dest(rd16(&f, (int)r + 0x10), f.data[r + 0x12], 1, name);
        }
    }
    named = dest_count;
    /* Stg20MapFile +0xC: exits of 4 bytes x, y, mode - 0x300, arg; x 0 ends */
    for (k = 0; k < CITY_AREAS; k++) {
        uint32_t h = rd32(&m, k * 4), e;

        if (h + 0x24 > (uint32_t)m.size) {
            continue;
        }
        for (e = rd32(&m, (int)h + 0xC); e != 0 && e + 4 <= (uint32_t)m.size && m.data[e] != 0; e += 4) {
            int mode = m.data[e + 2] + 0x300, arg = m.data[e + 3];
            const char *an = area_name(mode);
            char name[64];

            if (mode >= 0x32A && mode <= 0x32E) {
                snprintf(name, sizeof(name), "area select 0x%03X, cursor %d", mode, arg);
            } else if (an != NULL) {
                snprintf(name, sizeof(name), "%s, start %d", an, arg);
            } else {
                snprintf(name, sizeof(name), "area 0x%03X, start %d", mode, arg);
            }
            add_dest(mode, arg, 0, name);
        }
    }
    qsort(dests, (size_t)dest_count, sizeof(DevDest), dest_cmp);
    free(f.data);
    free(m.data);
    printf("[devdata] %d warp destinations (%d named, %d from map exits)\n", dest_count, named, dest_count - named);
    return 1;
}

int DevData_Load(void) {
    if (SDL_GetAtomicInt(&ready) || SDL_GetAtomicInt(&failed)) {
        return SDL_GetAtomicInt(&ready);
    }
    if (!SDL_ShouldInit(&load_state)) {
        return SDL_GetAtomicInt(&ready); /* the other thread loaded (or tried) meanwhile */
    }
    {
        int size;
        void *probe = Host_PakReadFile(FILE_SYSTEXT, &size);

        if (probe == NULL) {
            SDL_SetInitialized(&load_state, false);
            return 0; /* pack not open yet */
        }
        free(probe);
    }
    if (!load_labels() || !load_digis() || !load_items() || !load_skills() || !load_dests()) {
        printf("[devdata] tables not loaded: names off\n");
        SDL_SetAtomicInt(&failed, 1);
        SDL_SetInitialized(&load_state, false);
        return 0;
    }
    loaded = 1;
    SDL_SetAtomicInt(&ready, 1); /* after the tables: a thread that sees it sees them */
    SDL_SetInitialized(&load_state, true);
    fflush(stdout);
    return 1;
}

int DevData_Ready(void) {
    return SDL_GetAtomicInt(&ready);
}

int DevData_DestCount(void) {
    return SDL_GetAtomicInt(&ready) ? dest_count : 0;
}

const DevDest *DevData_DestAt(int i) {
    return i >= 0 && i < DevData_DestCount() ? &dests[i] : NULL;
}

static const DevDest *find_dest(int mode, int arg) {
    int i;

    for (i = 0; i < DevData_DestCount(); i++) {
        if (dests[i].mode == mode && dests[i].arg == arg) {
            return &dests[i];
        }
    }
    return NULL;
}

int DevData_IsDest(int mode, int arg) {
    return find_dest(mode, arg) != NULL;
}

const char *DevData_DestName(int mode, int arg) {
    const DevDest *d = find_dest(mode, arg);

    return d != NULL ? d->name : "?";
}

int DevData_DigiCount(void) {
    return loaded ? digi_count : 0;
}

const DevDigi *DevData_DigiAt(int i) {
    return loaded && i >= 0 && i < digi_count ? &digis[i] : NULL;
}

const DevDigi *DevData_Digi(int id) {
    return loaded && id >= 0 && id < DEVDATA_DIGI_IDS && digi_at[id] != 0 ? &digis[digi_at[id] - 1] : NULL;
}

int DevData_ItemCount(void) {
    return loaded ? item_count : 0;
}

const DevItem *DevData_ItemAt(int i) {
    return loaded && i >= 0 && i < item_count ? &items[i] : NULL;
}

const DevItem *DevData_Item(int id) {
    return loaded && id >= 0 && id < DEVDATA_ITEM_IDS && item_at[id] != 0 ? &items[item_at[id] - 1] : NULL;
}

int DevData_SkillCount(void) {
    return loaded ? skill_count : 0;
}

const DevSkill *DevData_SkillAt(int i) {
    return loaded && i >= 0 && i < skill_count ? &skills[i] : NULL;
}

const DevSkill *DevData_Skill(int id) {
    return loaded && id >= 0 && id < DEVDATA_SKILL_IDS && skill_at[id] != 0 ? &skills[skill_at[id] - 1] : NULL;
}

const char *DevData_DigiName(int id) {
    const DevDigi *d = DevData_Digi(id);

    return d != NULL ? d->name : "?";
}

const char *DevData_ItemName(int id) {
    const DevItem *it = DevData_Item(id);

    return it != NULL ? it->name : "?";
}

const char *DevData_SkillName(int id) {
    const DevSkill *k = DevData_Skill(id);

    return k != NULL ? k->name : "?";
}

const char *DevData_TypeName(int type) {
    return loaded && type >= 0 && type < 3 ? type_names[type] : "?";
}

const char *DevData_RankName(int rank) {
    return loaded && rank >= 0 && rank < 4 ? rank_names[rank] : "?";
}

const char *DevData_SpecialtyName(int specialty) {
    if (specialty == 6) {
        return "random"; /* Skill_GetSpecialty: 6 = Rand_Next() % 5 */
    }
    return loaded && specialty >= 0 && specialty < 6 ? spec_names[specialty] : "?";
}

const char *DevData_SlotName(int slot) {
    static const char *const names[19] = {
        "body", "engine", "memory", "battery", "tool box", "tires", "arm", "hand", "gun", "Z cannon",
        "R cannon", "missile gun", "bug zapper", "mine sweeper", "bug sweeper", "DM transfer",
        "auto pilot", "radar", "map radar",
    };
    return slot >= 0 && slot < 19 ? names[slot] : "?";
}

const char *DevData_CategoryName(int category) {
    /* 0..18: part for slot category + 1, 19 body; the rest by what the items do (ITEMDATA descs) */
    static const char *const uses[] = {
        "HP / MP disk", "beetle repair", "EP pack", "Mag missile", "bug zap", "Z-Bomb", "RayBomb",
        "gift", "chip", "driver", "ROM", "key item", "Drill missile", "Wave missile", "gift DATA",
        "gift VAC", "gift VIRUS", "EP bug zap", "Return bug zap", "Memory bug zap", "Super bug zap",
    };
    if (category == 19) {
        return "part: body";
    }
    if (category >= 0 && category < 19) {
        static char buf[19][24];

        if (buf[category][0] == 0) {
            snprintf(buf[category], sizeof(buf[category]), "part: %s", DevData_SlotName(category + 1));
        }
        return buf[category];
    }
    if (category >= 20 && category < 20 + (int)(sizeof(uses) / sizeof(uses[0]))) {
        return uses[category - 20];
    }
    return "?";
}

int DevData_DnaResult(int a, int b, int *level) {
    const DevDigi *da = DevData_Digi(a), *db = DevData_Digi(b);
    const DevDigi *r;
    int m, id;

    *level = 0;
    if (da == NULL || db == NULL || !da->hasBase || !db->hasBase || da->type > 2 || db->type > 2 ||
        da->dnaGroup > 7 || db->dnaGroup > 7) {
        return 0;
    }
    m = (da->rank < db->rank ? da->rank : db->rank) - 1;
    if (m < 0 || m > 2) {
        return 0;
    }
    id = dna_table[dna_types[da->type][db->type]][m][da->dnaGroup][db->dnaGroup];
    r = DevData_Digi(id);
    if (r != NULL && r->hasBase) {
        *level = r->rank * 10 + 1;
    }
    return id;
}

#endif /* DW2_DEV */
