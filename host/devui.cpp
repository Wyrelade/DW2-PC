/* PD.1 dev overlay (DW2_DEV only): Dear ImGui (host/imgui/, pinned in README.txt) with the SDL3
 * platform backend and the SDL_Renderer backend, on the renderer host/sdl.c presents with (the
 * SDL_GPU renderer or the default one: both paths, one backend). Main thread only. F2 toggles it.
 *
 * Every panel draws from a DevSnap copy (host/devsnap.c fills it on the game thread at its VBlank
 * wait while the overlay is open). Nothing here calls the game or writes game memory: the Save
 * tab's Edit controls (PD.4) queue DevEdit records that the game thread applies (host/devedit.c).
 * PR.2: the ImGui context, backends, frame and headless shots are host/ui.cpp's (shared with the F1
 * settings window); this file draws the overlay window in that frame. The font follows the display
 * scale and the window height (View tab). Names and the
 * Data tab come from the game tables in dw2.pak (host/devdata.c, PD.7). */

#include <SDL3/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "imgui.h"

#include "host/devdata.h"
#include "host/devedit.h"
#include "host/devsnap.h"
#include "host/devui.h"

namespace {

SDL_Window *g_window;
SDL_Renderer *g_renderer;
bool g_ready;
bool g_headless;
bool g_open_at_start;
int g_win_w, g_win_h;
float g_dpi = 1.0f;
float g_user_scale = 0.0f; /* 0 = automatic (window height) */
bool g_show_metrics;
char g_start_tab[16]; /* --devui-tab NAME[:SUB]: selected in the first frame */
char g_start_sub[24];
char g_scroll_to[16]; /* --devui-tab Save:Edit+Bag: the Save section opened and scrolled to (headless shots) */
int g_scroll_frames;

DevSnap g_snap;       /* the overlay's copy */
bool g_have_snap;
bool g_edit;          /* Save tab: Edit controls shown (PD.4) */
char g_edit_msg[96];  /* the last queue result */

/* rates from snapshot deltas, over about one second */
uint64_t g_rate_ns, g_rate_vb, g_rate_flips;
int32_t g_rate_frames;
double g_vb_hz, g_flip_hz, g_frame_hz;

/* symbols from the linker map next to the exe (task descriptor and callback names) */
struct Sym {
    uint64_t addr;
    char *name;
};
Sym *g_syms;
int g_sym_count;

int sym_cmp(const void *a, const void *b) {
    uint64_t x = ((const Sym *)a)->addr, y = ((const Sym *)b)->addr;
    return x < y ? -1 : x > y;
}

/* GNU ld map: symbol lines are "<spaces>0x<address><spaces><name>". */
void load_map(void) {
    const char *base = SDL_GetBasePath();
    char path[1024];
    char line[512];
    FILE *f;
    int cap = 0;

    snprintf(path, sizeof(path), "%sdw2.map", base != NULL ? base : "");
    f = fopen(path, "r");
    if (f == NULL) {
        printf("[devui] no %s: task names off\n", path);
        return;
    }
    while (fgets(line, sizeof(line), f) != NULL) {
        const char *p = line;
        char *end;
        unsigned long long addr;
        char name[256];

        while (*p == ' ') {
            p++;
        }
        if (p == line || p[0] != '0' || p[1] != 'x') {
            continue;
        }
        addr = strtoull(p, &end, 16);
        if (end == p || sscanf(end, " %255s", name) != 1 || addr == 0) {
            continue;
        }
        if (!((name[0] >= 'A' && name[0] <= 'Z') || (name[0] >= 'a' && name[0] <= 'z') || name[0] == '_')) {
            continue;
        }
        {
            char rest[8];

            if (sscanf(end, " %*s %7s", rest) == 1) {
                continue; /* "0x... 0x... file" lines have more fields */
            }
        }
        if (g_sym_count == cap) {
            Sym *n;

            cap = cap ? cap * 2 : 4096;
            n = (Sym *)realloc(g_syms, (size_t)cap * sizeof(Sym));
            if (n == NULL) {
                break;
            }
            g_syms = n;
        }
        g_syms[g_sym_count].addr = addr;
        g_syms[g_sym_count].name = SDL_strdup(name);
        g_sym_count++;
    }
    fclose(f);
    qsort(g_syms, (size_t)g_sym_count, sizeof(Sym), sym_cmp);
    printf("[devui] %d symbols from %s\n", g_sym_count, path);
}

const char *sym_name(uint64_t addr) {
    int lo = 0, hi = g_sym_count - 1;

    if (addr == 0) {
        return NULL;
    }
    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        if (g_syms[mid].addr == addr) {
            return g_syms[mid].name;
        }
        if (g_syms[mid].addr < addr) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return NULL;
}

const char *table_name(int table) {
    static const char *const names[8] = {
        "main", "STAG0000 debug menus", "STAG4000 dungeon", "STAG2000 city",
        "STAG1000 title / movies", "STAG3000 battle", "STAG1100 memory card / VS party", "STAG3500 VS battle",
    };
    return table >= 0 && table < 8 ? names[table] : "?";
}

/* host/host_sdl.h PAD_* order (Host_PadButtons); the game's PadState masks are byte-swapped */
const char *const k_pad_bits[16] = {
    "Select", "L3", "R3", "Start", "Up", "Right", "Down", "Left",
    "L2", "R2", "L1", "R1", "Triangle", "Circle", "Cross", "Square",
};

void pad_bits(const char *label, unsigned mask, bool game_order) {
    ImGui::Text("%-8s %04X", label, mask);
    for (int i = 0; i < 16; i++) {
        int bit = game_order ? (i ^ 8) : i;
        bool on = (mask >> bit) & 1;

        ImGui::SameLine();
        if (on) {
            ImGui::TextColored(ImVec4(0.4f, 1.0f, 0.4f, 1.0f), "%s", k_pad_bits[i]);
        } else {
            ImGui::TextDisabled("%s", k_pad_bits[i]);
        }
    }
}

/* game text (0xFF ends) as UTF-8, and the raw bytes in the tooltip */
void game_text(const char *label, const uint8_t *p, int n, const uint8_t *player = NULL) {
    char buf[128];
    char hex[3 * 32 + 1];
    int len = 0;

    while (len < n && p[len] != 0xFF) {
        len++;
    }
    DevData_Text(p, n, player, buf, (int)sizeof(buf));
    ImGui::Text("%s%s", label, buf);
    if (ImGui::IsItemHovered()) {
        hex[0] = 0;
        for (int i = 0; i < len && i < 32; i++) {
            snprintf(hex + i * 3, sizeof(hex) - (size_t)i * 3, "%02X ", p[i]);
        }
        ImGui::SetTooltip("game text: %s FF", hex);
    }
}

void play_time(int32_t vb, char *out, size_t n) {
    int64_t s = (int64_t)vb * 1001 / 60000;

    snprintf(out, n, "%d:%02d:%02d", (int)(s / 3600), (int)(s / 60 % 60), (int)(s % 60));
}

void update_rates(const DevSnap &s) {
    if (g_rate_ns == 0 || s.ns < g_rate_ns) {
        g_rate_ns = s.ns;
        g_rate_vb = s.vblanks;
        g_rate_flips = s.flips;
        g_rate_frames = s.frameCount;
        return;
    }
    if (s.ns - g_rate_ns >= 1000000000ull) {
        double dt = (s.ns - g_rate_ns) / 1e9;

        g_vb_hz = (s.vblanks - g_rate_vb) / dt;
        g_flip_hz = (s.flips - g_rate_flips) / dt;
        g_frame_hz = (s.frameCount - g_rate_frames) / dt;
        g_rate_ns = s.ns;
        g_rate_vb = s.vblanks;
        g_rate_flips = s.flips;
        g_rate_frames = s.frameCount;
    }
}

void panel_timing(const DevSnap &s) {
    ImGuiIO &io = ImGui::GetIO();
    float lo = 1e9f, hi = 0, sum = 0;
    int n = 0;

    ImGui::Text("Window present  %.1f Hz (%.2f ms)", io.Framerate, 1000.0f / (io.Framerate > 0 ? io.Framerate : 1));
    ImGui::Text("VBlank clock    %.3f Hz   (59.94 target)", g_vb_hz);
    ImGui::Text("Game frames     %.2f /s   flips %.2f /s", g_frame_hz, g_flip_hz);
    ImGui::Text("frameDelta %d   vsyncWait %d   drawPass %d", s.frameDelta, s.vsyncWait, s.drawPass);
    ImGui::Text("VBlanks %llu   flips %llu   frameCount %d", (unsigned long long)s.vblanks,
                (unsigned long long)s.flips, s.frameCount);
    ImGui::Text("Clock restarts  %u", s.restarts);
    for (int i = 0; i < DEVSNAP_FLIPS; i++) {
        float v = s.flipMs[i];

        if (v > 0) {
            lo = v < lo ? v : lo;
            hi = v > hi ? v : hi;
            sum += v;
            n++;
        }
    }
    if (n > 0) {
        char ov[64];

        snprintf(ov, sizeof(ov), "frame ms: avg %.2f  min %.2f  max %.2f", sum / n, lo, hi);
        ImGui::PlotLines("##flips", s.flipMs, DEVSNAP_FLIPS, 0, ov, 0.0f, hi > 50.0f ? hi * 1.1f : 50.0f,
                         ImVec2(-1, 80 * ImGui::GetStyle().FontScaleMain * g_dpi));
    } else {
        ImGui::TextDisabled("frame intervals: waiting for flips");
    }
    ImGui::Text("Snapshot #%llu, capture %.1f us on the game thread", (unsigned long long)s.seq, s.captureNs / 1000.0);
}

/* PD.4 edit controls, defined below the Data tab pickers */
void edit_log(void);
void edit_tamer(const DevSnap &s);
void edit_digi(const DevSnap &s, int slot);
void edit_add_digi(void);
void edit_beetle(const DevSnap &s);
void edit_part(const DevSnap &s, int slot);
void edit_bag_add(const DevSnap &s);
void edit_storage(const DevSnap &s);
void edit_flag(const DevSnap &s, int id);
void panel_warp(const DevSnap &s);
DevEdit edit_rec(int kind, int a = 0, int b = 0, int c = 0);
void push(const DevEdit &e);

void panel_game(const DevSnap &s) {
    ImGui::Text("Game mode   0x%03X  (%s, row %d)", s.gameMode, table_name(s.gameMode >> 8), s.gameMode & 0xFF);
    ImGui::Text("Next mode   0x%03X   prev 0x%03X   modeArg %d", s.nextGameMode, s.prevGameMode, s.modeArg);
    if (s.ovl >= 0) {
        ImGui::Text("Overlay     id %d  (%s)", s.ovl, table_name(s.ovl + 1));
    } else {
        ImGui::Text("Overlay     none");
    }
    ImGui::Separator();
    ImGui::Text("Rand_Index  %d (0x%03X)   Rand_Table value 0x%04X", s.randIndex, s.randIndex, s.randValue);
    ImGui::SeparatorText("Warp (PD.4)");
    if (!s.editsAllowed) {
        ImGui::TextDisabled("edits off (online mode)");
    } else if (!DevData_Ready()) {
        ImGui::TextDisabled("tables not loaded (dw2.pak)");
    } else {
        panel_warp(s);
        edit_log();
    }
}

void task_row(const DevSnap &s, int i, int depth) {
    const DevSnapTask &t = s.tasks[i];
    const char *dn = sym_name(t.desc);
    const char *un = sym_name(t.update);
    bool has_kids = false;
    char label[64];

    for (int k = 0; k < s.taskCount; k++) {
        if (s.tasks[k].parent == i) {
            has_kids = true;
            break;
        }
    }
    ImGui::TableNextRow();
    ImGui::TableNextColumn();
    snprintf(label, sizeof(label), "%s##%d", dn != NULL ? dn : (un != NULL ? un : "?"), i);
    ImGuiTreeNodeFlags fl = ImGuiTreeNodeFlags_SpanAllColumns | ImGuiTreeNodeFlags_DefaultOpen;
    if (!has_kids) {
        fl |= ImGuiTreeNodeFlags_Leaf | ImGuiTreeNodeFlags_NoTreePushOnOpen;
    }
    bool open = ImGui::TreeNodeEx(label, fl);
    if (ImGui::IsItemHovered()) {
        ImGui::SetTooltip("desc %s\nupdate %s\ndraw %s\nheader 0x%08X, Task_List[%d]", dn ? dn : "?", un ? un : "-",
                          sym_name(t.draw) ? sym_name(t.draw) : "-", t.addr, t.listIndex);
    }
    ImGui::TableNextColumn();
    ImGui::Text("0x%03X", t.id);
    ImGui::TableNextColumn();
    ImGui::Text("%d %d %d %d %d", t.state[0], t.state[1], t.state[2], t.state[3], t.state[4]);
    ImGui::TableNextColumn();
    ImGui::Text("0x%X", t.workSize);
    ImGui::TableNextColumn();
    if (t.workBytes) {
        ImGui::Text("0x%X", t.workBytes);
    } else {
        ImGui::TextDisabled("-");
    }
    ImGui::TableNextColumn();
    ImGui::Text("%d", t.childCount);
    if (open && has_kids) {
        if (depth < 32) {
            for (int k = 0; k < s.taskCount; k++) {
                if (s.tasks[k].parent == i) {
                    task_row(s, k, depth + 1);
                }
            }
        }
        ImGui::TreePop();
    }
}

void panel_tasks(const DevSnap &s) {
    int per_row[8] = { 0 };

    for (int i = 0; i < s.taskCount; i++) {
        int r = (s.tasks[i].id >> 8) & 0xFF;
        if (r < 8) {
            per_row[r]++;
        }
    }
    ImGui::Text("Live tasks %d (Task_List.count %d)", s.taskCount, s.taskListCount);
    for (int r = 0; r < 8; r++) {
        if (per_row[r]) {
            ImGui::BulletText("Task_DescTable[%d] %-32s %d", r, table_name(r), per_row[r]);
        }
    }
    if (g_sym_count == 0) {
        ImGui::TextDisabled("no dw2.map next to the exe: no names");
    }
    ImGuiTableFlags tf = ImGuiTableFlags_BordersV | ImGuiTableFlags_RowBg | ImGuiTableFlags_Resizable |
                         ImGuiTableFlags_ScrollY | ImGuiTableFlags_SizingFixedFit;
    if (ImGui::BeginTable("tasks", 6, tf, ImVec2(0, ImGui::GetContentRegionAvail().y))) {
        ImGui::TableSetupScrollFreeze(0, 1);
        ImGui::TableSetupColumn("task (descriptor)", ImGuiTableColumnFlags_WidthStretch);
        ImGui::TableSetupColumn("id", ImGuiTableColumnFlags_WidthFixed, ImGui::CalcTextSize("0x000").x);
        ImGui::TableSetupColumn("state 0..4", ImGuiTableColumnFlags_WidthFixed, ImGui::CalcTextSize("0 0 00 00 0").x);
        ImGui::TableSetupColumn("work", ImGuiTableColumnFlags_WidthFixed, ImGui::CalcTextSize("0x0000").x);
        ImGui::TableSetupColumn("heap", ImGuiTableColumnFlags_WidthFixed, ImGui::CalcTextSize("0x0000").x);
        ImGui::TableSetupColumn("kids", ImGuiTableColumnFlags_WidthFixed, ImGui::CalcTextSize("kids").x);
        ImGui::TableHeadersRow();
        for (int i = 0; i < s.taskCount; i++) {
            if (s.tasks[i].parent < 0) {
                task_row(s, i, 0);
            }
        }
        ImGui::EndTable();
    }
}

void panel_heap(const DevSnap &s) {
    float used = s.heapSize > 0 ? (float)s.heapUsed / (float)s.heapSize : 0.0f;
    char ov[64];

    snprintf(ov, sizeof(ov), "%d / %d KB used", s.heapUsed / 1024, s.heapSize / 1024);
    ImGui::ProgressBar(used, ImVec2(-1, 0), ov);
    ImGui::Text("Heap 0x%X bytes   used 0x%X   free 0x%X", s.heapSize, s.heapUsed, s.heapFree);
    ImGui::Text("Largest free block 0x%X   blocks %d (free %d)", s.heapLargest, s.heapBlocks, s.heapFreeBlocks);
    if (s.heapBad) {
        ImGui::TextColored(ImVec4(1, 0.4f, 0.4f, 1), "heap list walk stopped at a block outside the heap");
    }
    if (ImGui::BeginTable("tags", 3, ImGuiTableFlags_BordersInnerV | ImGuiTableFlags_RowBg | ImGuiTableFlags_SizingFixedFit)) {
        ImGui::TableSetupColumn("tag");
        ImGui::TableSetupColumn("blocks");
        ImGui::TableSetupColumn("bytes");
        ImGui::TableHeadersRow();
        for (int t = 0; t < DEVSNAP_TAGS; t++) {
            if (s.tagBlocks[t] == 0) {
                continue;
            }
            ImGui::TableNextRow();
            ImGui::TableNextColumn();
            if (t == 0) {
                ImGui::TextUnformatted("0 free");
            } else if (t == DEVSNAP_TAGS - 1) {
                ImGui::Text("%d and up", t);
            } else {
                ImGui::Text("%d", t);
            }
            ImGui::TableNextColumn();
            ImGui::Text("%d", s.tagBlocks[t]);
            ImGui::TableNextColumn();
            ImGui::Text("0x%X", s.tagBytes[t]);
        }
        ImGui::EndTable();
    }
}

void panel_input(const DevSnap &s) {
    for (int p = 0; p < 2; p++) {
        ImGui::SeparatorText(p == 0 ? "Port 0" : "Port 1");
        ImGui::Text("Pad_State[%d].connected %d", p, s.pad[p].connected);
        pad_bits("held", (unsigned)s.pad[p].held & 0xFFFF, true);
        pad_bits("pressed", (unsigned)s.pad[p].pressed & 0xFFFF, true);
        pad_bits("repeat", (unsigned)s.pad[p].repeat & 0xFFFF, true);
        pad_bits("host", s.hostButtons[p], false);
    }
}

const ImVec4 k_bad(1.0f, 0.4f, 0.4f, 1.0f);

/* "0x0A2 Greymon": the id always shown, the name next to it */
void id_name(int id, const char *name, int digits = 3) {
    ImGui::Text("0x%0*X", digits, id);
    ImGui::SameLine();
    ImGui::TextUnformatted(name);
}

void skill_list(const char *label, const uint8_t *ids, int n) {
    int shown = 0;

    for (int i = 0; i < n; i++) {
        if (ids[i] == 0) {
            continue;
        }
        if (shown == 0) {
            ImGui::TextUnformatted(label);
            ImGui::Indent();
        }
        const DevSkill *k = DevData_Skill(ids[i]);
        if (k != NULL) {
            ImGui::Text("0x%02X %-18s MP %3d  power %4d  %s", k->id, k->name, k->mp, k->power,
                        DevData_SpecialtyName(k->specialty));
            if (ImGui::IsItemHovered() && k->desc[0] != 0) {
                ImGui::SetTooltip("%s", k->desc);
            }
        } else {
            ImGui::Text("0x%02X ?", ids[i]);
        }
        shown++;
    }
    if (shown != 0) {
        ImGui::Unindent();
    } else {
        ImGui::Text("%s: none", label);
    }
}

void digi_detail(const DevSnap &s, int slot) {
    const DevSnapDigi &d = s.roster[slot];
    const DevDigi *b = DevData_Digi(d.digiId);
    char nick[64];

    DevData_Text(d.name, (int)sizeof(d.name), s.playerName, nick, (int)sizeof(nick));
    ImGui::SeparatorText("Digimon detail");
    ImGui::Text("Slot %d: \"%s\"   species 0x%02X %s%s", slot, nick, d.digiId, DevData_DigiName(d.digiId),
                d.isTransferred ? "   (transferred)" : "");
    if (b != NULL && b->hasBase) {
        ImGui::Text("%s / %s / %s   DNA group %d   DP %d", DevData_TypeName(b->type), DevData_RankName(b->rank),
                    DevData_SpecialtyName(b->specialty), b->dnaGroup, d.dp);
    }
    ImGui::Text("Level %d / %d   EXP %d   HP %d / %d   MP %d / %d", d.level, d.maxLevel, d.exp, d.hp, d.maxHp, d.mp,
                d.maxMp);
    ImGui::Text("Attack %d   Defense %d   Speed %d", d.attack, d.defense, d.speed);
    if (d.parent0 != 0 || d.parent1 != 0) {
        ImGui::Text("DNA parents 0x%02X %s + 0x%02X %s", d.parent0, DevData_DigiName(d.parent0), d.parent1,
                    DevData_DigiName(d.parent1));
    }
    skill_list("Skills", d.skills, (int)sizeof(d.skills));
    if (d.pendingSkill != 0) {
        ImGui::Text("Pending skill 0x%02X %s", d.pendingSkill, DevData_SkillName(d.pendingSkill));
    }
    skill_list("Learnable skills", d.learnable, (int)sizeof(d.learnable));
}

/* a Save section header; the --devui-tab scroll target opens and scrolls to it (headless: every
 * frame, the save loads long after the first one; with a window: the first 30 frames) */
bool section(const char *name, ImGuiTreeNodeFlags flags = 0) {
    bool target = g_scroll_frames > 0 && SDL_strncasecmp(name, g_scroll_to, SDL_strlen(g_scroll_to)) == 0;

    if (target) {
        ImGui::SetNextItemOpen(true, ImGuiCond_Always);
    }
    bool open = ImGui::CollapsingHeader(name, flags);
    if (target) {
        ImGui::SetScrollHereY(0.0f);
        if (!g_headless) {
            g_scroll_frames--;
        }
    }
    return open;
}

void panel_save(const DevSnap &s) {
    char t[32];
    static int flag_id = 0;
    static int sel_digi = 0;

    if (g_start_sub[0] != 0) {
        /* --devui-tab Save:Edit[+SECTION] (headless checks): edit mode, a section scrolled to */
        const char *plus = SDL_strchr(g_start_sub, '+');

        g_edit = SDL_strncasecmp(g_start_sub, "Edit", 4) == 0;
        if (plus != NULL) {
            SDL_strlcpy(g_scroll_to, plus + 1, sizeof(g_scroll_to));
            g_scroll_frames = 30;
        }
        g_start_sub[0] = 0;
    }
    ImGui::BeginDisabled(!s.editsAllowed || !DevData_Ready());
    ImGui::Checkbox("Edit", &g_edit);
    ImGui::EndDisabled();
    ImGui::SameLine();
    if (!s.editsAllowed) {
        ImGui::TextDisabled("edits off (online mode)");
        g_edit = false;
    } else {
        ImGui::TextDisabled("applied by the game thread at its next VBlank wait, logged as [devedit]");
    }
    if (g_edit) {
        edit_log();
    }
    play_time(s.playTime, t, sizeof(t));
    game_text("Tamer  ", s.playerName, (int)sizeof(s.playerName));
    ImGui::Text("Rank %d (title set %d)   Bits %d   Play time %s", s.rank, s.rankTitleSet, s.bits, t);
    if (g_edit) {
        edit_tamer(s);
    }
    if (!DevData_Ready()) {
        ImGui::TextDisabled("tables not loaded (dw2.pak): names show as ?");
    }
    if (section("Party", ImGuiTreeNodeFlags_DefaultOpen)) {
        if (ImGui::BeginTable("party", 7, ImGuiTableFlags_BordersInnerV | ImGuiTableFlags_RowBg | ImGuiTableFlags_SizingFixedFit)) {
            ImGui::TableSetupColumn("slot");
            ImGui::TableSetupColumn("Digimon (species / name)");
            ImGui::TableSetupColumn("state");
            ImGui::TableSetupColumn("level");
            ImGui::TableSetupColumn("HP");
            ImGui::TableSetupColumn("MP");
            ImGui::TableSetupColumn("exp");
            ImGui::TableHeadersRow();
            for (int i = 0; i < DEVSNAP_ROSTER; i++) {
                const DevSnapDigi &d = s.roster[i];
                char label[96], nick[48];

                if (i >= 3 && d.state == 0) {
                    continue;
                }
                if (i == 3) {
                    ImGui::TableNextRow(ImGuiTableRowFlags_None);
                    ImGui::TableNextColumn();
                    ImGui::TextDisabled("roster");
                }
                ImGui::TableNextRow();
                ImGui::TableNextColumn();
                ImGui::Text("%d%s", i, i < 3 ? " party" : "");
                ImGui::TableNextColumn();
                if (d.state == 0) {
                    ImGui::TextDisabled("empty");
                    continue;
                }
                DevData_Text(d.name, (int)sizeof(d.name), s.playerName, nick, (int)sizeof(nick));
                snprintf(label, sizeof(label), "0x%02X %s / %s##d%d", d.digiId, DevData_DigiName(d.digiId), nick, i);
                if (ImGui::Selectable(label, sel_digi == i, ImGuiSelectableFlags_SpanAllColumns)) {
                    sel_digi = i;
                }
                ImGui::TableNextColumn();
                ImGui::Text("%d", d.state);
                ImGui::TableNextColumn();
                ImGui::Text("%d / %d", d.level, d.maxLevel);
                ImGui::TableNextColumn();
                ImGui::Text("%d / %d", d.hp, d.maxHp);
                ImGui::TableNextColumn();
                ImGui::Text("%d / %d", d.mp, d.maxMp);
                ImGui::TableNextColumn();
                ImGui::Text("%d", d.exp);
            }
            ImGui::EndTable();
        }
        if (sel_digi >= 0 && sel_digi < DEVSNAP_ROSTER && s.roster[sel_digi].state != 0) {
            digi_detail(s, sel_digi);
            if (g_edit) {
                edit_digi(s, sel_digi);
            }
        } else {
            ImGui::TextDisabled("click a Digimon for its stats and skills");
        }
        if (g_edit) {
            edit_add_digi();
        }
    }
    if (section("Digi-Beetle", ImGuiTreeNodeFlags_DefaultOpen)) {
        game_text("Name   ", s.beetleName, (int)sizeof(s.beetleName), s.playerName);
        ImGui::Text("HP %d / %d   EP %d / %d", s.beetleHp, s.beetleMaxHp, s.beetleMp, s.beetleMaxMp);
        if (g_edit) {
            edit_beetle(s);
        }
        if (ImGui::BeginTable("parts", 3, ImGuiTableFlags_BordersInnerV | ImGuiTableFlags_RowBg | ImGuiTableFlags_SizingFixedFit)) {
            ImGui::TableSetupColumn("slot");
            ImGui::TableSetupColumn("part (item)");
            ImGui::TableSetupColumn("status");
            ImGui::TableHeadersRow();
            for (int i = 0; i < DEVSNAP_PARTS; i++) {
                if (s.partItems[i] == 0 && s.partBroken[i] == 0 && !g_edit) {
                    continue;
                }
                ImGui::TableNextRow();
                ImGui::TableNextColumn();
                ImGui::Text("%2d %s", i, DevData_SlotName(i));
                ImGui::TableNextColumn();
                if (g_edit) {
                    edit_part(s, i); /* item picker of the slot's category + broken box */
                    continue;
                }
                if (s.partItems[i] != 0) {
                    const DevItem *it = DevData_Item(s.partItems[i]);

                    id_name(s.partItems[i], DevData_ItemName(s.partItems[i]));
                    if (it != NULL && ImGui::IsItemHovered()) {
                        ImGui::SetTooltip("%s", it->desc);
                    }
                } else {
                    ImGui::TextDisabled("-");
                }
                ImGui::TableNextColumn();
                if (s.partBroken[i]) {
                    ImGui::TextColored(k_bad, "broken (%d)", s.partBroken[i]);
                } else {
                    ImGui::TextUnformatted("ok");
                }
            }
            ImGui::EndTable();
        }
    }
    if (section("Bag")) {
        int n = 0;

        if (g_edit) {
            edit_bag_add(s);
        }
        if (ImGui::BeginTable("bag", 2, ImGuiTableFlags_BordersInnerV | ImGuiTableFlags_RowBg | ImGuiTableFlags_SizingFixedFit)) {
            ImGui::TableSetupColumn("slot");
            ImGui::TableSetupColumn("item");
            ImGui::TableHeadersRow();
            for (int i = 0; i < DEVSNAP_BAG; i++) {
                if (s.bag[i] == 0) {
                    continue;
                }
                ImGui::TableNextRow();
                ImGui::TableNextColumn();
                ImGui::Text("%2d", i);
                ImGui::TableNextColumn();
                if (g_edit) {
                    ImGui::PushID(i);
                    if (ImGui::SmallButton("x")) {
                        push(edit_rec(DEVEDIT_BAG, i, 0, 0));
                    }
                    ImGui::PopID();
                    ImGui::SameLine();
                }
                id_name(s.bag[i], DevData_ItemName(s.bag[i]));
                n++;
            }
            ImGui::EndTable();
        }
        if (n == 0) {
            ImGui::TextDisabled("empty");
        }
    }
    if (section("Storage")) {
        int n = 0;

        if (g_edit) {
            edit_storage(s);
        }
        if (ImGui::BeginTable("storage", 2, ImGuiTableFlags_BordersInnerV | ImGuiTableFlags_RowBg | ImGuiTableFlags_SizingFixedFit)) {
            ImGui::TableSetupColumn("item");
            ImGui::TableSetupColumn("count");
            ImGui::TableHeadersRow();
            for (int i = 0; i < DEVSNAP_STORAGE; i++) {
                if (s.storage[i] == 0) {
                    continue;
                }
                ImGui::TableNextRow();
                ImGui::TableNextColumn();
                id_name(i, DevData_ItemName(i));
                ImGui::TableNextColumn();
                ImGui::Text("%d", s.storage[i]);
                n++;
            }
            ImGui::EndTable();
        }
        if (n == 0) {
            ImGui::TextDisabled("empty");
        }
    }
    if (section("Flags", ImGuiTreeNodeFlags_DefaultOpen)) {
        const char *what = "";
        int r;

        ImGui::Text("progress %d", s.progress);
        ImGui::SetNextItemWidth(ImGui::CalcTextSize("00000000").x + ImGui::GetFrameHeight() * 2);
        ImGui::InputInt("flag id (Flag_Test)", &flag_id);
        if (flag_id < 0) {
            flag_id = 0;
        }
        r = DevSnap_FlagTest(&s, flag_id, &what);
        if (r < 0) {
            ImGui::TextDisabled("%d: ? (%s)", flag_id, what);
        } else {
            ImGui::TextColored(r ? ImVec4(0.4f, 1, 0.4f, 1) : ImVec4(0.8f, 0.8f, 0.8f, 1), "%d: %s   (%s)", flag_id,
                               r ? "set" : "not set", what);
        }
        if (flag_id >= 0x7D0 && flag_id < 0xBB8) {
            ImGui::TextDisabled("item 0x%03X %s", flag_id - 0x7D0, DevData_ItemName(flag_id - 0x7D0));
        } else if (flag_id >= 0xBB8 && flag_id < 0xFA0) {
            ImGui::TextDisabled("Digimon 0x%03X %s", flag_id - 0xBB8, DevData_DigiName(flag_id - 0xBB8));
        }
        if (g_edit) {
            edit_flag(s, flag_id);
        }
    }
}

ImGuiTabItemFlags sub_flags(const char *name); /* --devui-tab Data:SUB */

/* PD.3 tables part / PD.7: the game's Digimon, item and skill tables from dw2.pak (host/devdata.c),
 * searchable, ids next to names. Static data only: no snapshot needed. */

const ImGuiTableFlags k_list_flags = ImGuiTableFlags_BordersV | ImGuiTableFlags_RowBg | ImGuiTableFlags_Resizable |
                                     ImGuiTableFlags_ScrollY | ImGuiTableFlags_ScrollX | ImGuiTableFlags_SizingFixedFit;

bool pass(const ImGuiTextFilter &f, int id, const char *name, const char *extra = "") {
    char key[320]; /* ids + name (40) + extra (160) */

    if (!f.IsActive()) {
        return true;
    }
    snprintf(key, sizeof(key), "%d 0x%X 0x%03X %s %s", id, id, id, name, extra);
    return f.PassFilter(key);
}

void search_box(ImGuiTextFilter &f, const char *hint) {
    ImGui::SetNextItemWidth(ImGui::CalcTextSize("0000000000000000000000000").x);
    f.Draw(hint);
}

/* list height: leave room for a detail block below */
float list_height(bool detail) {
    float avail = ImGui::GetContentRegionAvail().y;

    return detail ? avail * 0.55f : avail;
}

const char *body_letters(int mask, char *out) {
    out[0] = (mask & 1) ? 'S' : '-';
    out[1] = (mask & 2) ? 'T' : '-';
    out[2] = (mask & 4) ? 'A' : '-';
    out[3] = 0;
    return out;
}

void data_digimon(void) {
    static ImGuiTextFilter filt;
    static bool base_only = true;
    static int sel = -1;
    static ImVector<int> rows;
    const DevDigi *sd = DevData_Digi(sel);

    search_box(filt, "search (id, name, type, rank)##digi");
    ImGui::SameLine();
    ImGui::Checkbox("with DIGIMNDT data only", &base_only);
    rows.resize(0);
    for (int i = 0; i < DevData_DigiCount(); i++) {
        const DevDigi *d = DevData_DigiAt(i);
        char extra[64] = "";

        if (base_only && !d->hasBase) {
            continue;
        }
        if (d->hasBase) {
            snprintf(extra, sizeof(extra), "%s %s %s", DevData_TypeName(d->type), DevData_RankName(d->rank),
                     DevData_SpecialtyName(d->specialty));
        }
        if (pass(filt, d->id, d->name, extra)) {
            rows.push_back(i);
        }
    }
    ImGui::Text("%d of %d", rows.Size, DevData_DigiCount());
    if (ImGui::BeginTable("digis", 8, k_list_flags, ImVec2(0, list_height(sd != NULL)))) {
        ImGui::TableSetupScrollFreeze(2, 1);
        ImGui::TableSetupColumn("id");
        ImGui::TableSetupColumn("name");
        ImGui::TableSetupColumn("type");
        ImGui::TableSetupColumn("rank");
        ImGui::TableSetupColumn("specialty");
        ImGui::TableSetupColumn("DNA");
        ImGui::TableSetupColumn("growth HP MP At Df Sp");
        ImGui::TableSetupColumn("skill");
        ImGui::TableHeadersRow();
        ImGuiListClipper clip;
        clip.Begin(rows.Size);
        while (clip.Step()) {
            for (int r = clip.DisplayStart; r < clip.DisplayEnd; r++) {
                const DevDigi *d = DevData_DigiAt(rows[r]);
                char label[24];

                ImGui::TableNextRow();
                ImGui::TableNextColumn();
                snprintf(label, sizeof(label), "0x%03X##g%d", d->id, d->id);
                if (ImGui::Selectable(label, sel == d->id, ImGuiSelectableFlags_SpanAllColumns)) {
                    sel = d->id;
                }
                ImGui::TableNextColumn();
                ImGui::TextUnformatted(d->name);
                if (!d->hasBase) {
                    ImGui::TableNextColumn();
                    ImGui::TextDisabled("no DIGIMNDT record");
                    continue;
                }
                ImGui::TableNextColumn();
                ImGui::TextUnformatted(DevData_TypeName(d->type));
                ImGui::TableNextColumn();
                ImGui::TextUnformatted(DevData_RankName(d->rank));
                ImGui::TableNextColumn();
                ImGui::TextUnformatted(DevData_SpecialtyName(d->specialty));
                ImGui::TableNextColumn();
                ImGui::Text("%d", d->dnaGroup);
                ImGui::TableNextColumn();
                ImGui::Text("%d  %d  %d  %d  %d", d->growth[0], d->growth[1], d->growth[2], d->growth[3], d->growth[4]);
                ImGui::TableNextColumn();
                ImGui::Text("0x%02X %s", d->learnedSkill, DevData_SkillName(d->learnedSkill));
            }
        }
        ImGui::EndTable();
    }
    if (sd == NULL) {
        return;
    }
    ImGui::SeparatorText("Digimon");
    ImGui::Text("0x%03X %s   model file 0x%03X", sd->id, sd->name, sd->modelFile);
    if (!sd->hasBase) {
        ImGui::TextDisabled("no DIGIMNDT record (enemy / event form)");
        return;
    }
    ImGui::Text("%s / %s / %s   DNA group %d", DevData_TypeName(sd->type), DevData_RankName(sd->rank),
                DevData_SpecialtyName(sd->specialty), sd->dnaGroup);
    ImGui::Text("Growth class HP %d  MP %d  attack %d  defense %d  speed %d (stag3000 level up tables)", sd->growth[0],
                sd->growth[1], sd->growth[2], sd->growth[3], sd->growth[4]);
    {
        const DevSkill *k = DevData_Skill(sd->learnedSkill);

        ImGui::Text("Species skill 0x%02X %s", sd->learnedSkill, k != NULL ? k->name : "?");
        if (k != NULL) {
            ImGui::SameLine();
            ImGui::TextDisabled("MP %d  power %d  %s", k->mp, k->power, k->desc);
        }
    }
    if (sd->dpTargets[0] == 0) {
        ImGui::TextUnformatted("Digivolves: no (DP table empty)");
    } else {
        ImGui::TextUnformatted("Digivolves by DP (city lab):");
        ImGui::Indent();
        for (int i = 0; i < 4; i++) {
            int lo = sd->dpBounds[i];
            int hi = sd->dpBounds[i + 1];

            if (i > 0 && sd->dpBounds[i] == 0) {
                break;
            }
            if (hi == 0) {
                ImGui::Text("DP %2d and up  -> 0x%02X %s", lo, sd->dpTargets[i], DevData_DigiName(sd->dpTargets[i]));
                break;
            }
            ImGui::Text("DP %2d .. %2d   -> 0x%02X %s", lo, hi - 1, sd->dpTargets[i], DevData_DigiName(sd->dpTargets[i]));
        }
        ImGui::Unindent();
    }
}

void data_items(void) {
    static ImGuiTextFilter filt;
    static ImVector<int> rows;

    search_box(filt, "search (id, name, category, text)##item");
    rows.resize(0);
    for (int i = 0; i < DevData_ItemCount(); i++) {
        const DevItem *it = DevData_ItemAt(i);
        char extra[160];

        snprintf(extra, sizeof(extra), "%s %s", DevData_CategoryName(it->category), it->desc);
        if (pass(filt, it->id, it->name, extra)) {
            rows.push_back(i);
        }
    }
    ImGui::Text("%d of %d (ITEMDATA order)", rows.Size, DevData_ItemCount());
    if (ImGui::BeginTable("items", 7, k_list_flags, ImVec2(0, list_height(false)))) {
        ImGui::TableSetupScrollFreeze(2, 1);
        ImGui::TableSetupColumn("id");
        ImGui::TableSetupColumn("name");
        ImGui::TableSetupColumn("category");
        ImGui::TableSetupColumn("lv");
        ImGui::TableSetupColumn("price");
        ImGui::TableSetupColumn("body");
        ImGui::TableSetupColumn("text");
        ImGui::TableHeadersRow();
        ImGuiListClipper clip;
        clip.Begin(rows.Size);
        while (clip.Step()) {
            for (int r = clip.DisplayStart; r < clip.DisplayEnd; r++) {
                const DevItem *it = DevData_ItemAt(rows[r]);
                char b[4];

                ImGui::TableNextRow();
                ImGui::TableNextColumn();
                ImGui::Text("0x%03X", it->id);
                ImGui::TableNextColumn();
                ImGui::TextUnformatted(it->name);
                ImGui::TableNextColumn();
                ImGui::Text("%2d %s", it->category, DevData_CategoryName(it->category));
                ImGui::TableNextColumn();
                ImGui::Text("%d", it->level);
                ImGui::TableNextColumn();
                ImGui::Text("%d", it->price);
                ImGui::TableNextColumn();
                ImGui::TextUnformatted(body_letters(it->bodyMask, b));
                ImGui::TableNextColumn();
                ImGui::TextUnformatted(it->desc);
            }
        }
        ImGui::EndTable();
    }
}

void data_skills(void) {
    static ImGuiTextFilter filt;
    static ImVector<int> rows;

    search_box(filt, "search (id, name, specialty, text)##skill");
    rows.resize(0);
    for (int i = 0; i < DevData_SkillCount(); i++) {
        const DevSkill *k = DevData_SkillAt(i);
        char extra[160];

        snprintf(extra, sizeof(extra), "%s %s", DevData_SpecialtyName(k->specialty), k->desc);
        if (pass(filt, k->id, k->name, extra)) {
            rows.push_back(i);
        }
    }
    ImGui::Text("%d of %d", rows.Size, DevData_SkillCount());
    if (ImGui::BeginTable("skills", 9, k_list_flags, ImVec2(0, list_height(false)))) {
        ImGui::TableSetupScrollFreeze(2, 1);
        ImGui::TableSetupColumn("id");
        ImGui::TableSetupColumn("name");
        ImGui::TableSetupColumn("MP");
        ImGui::TableSetupColumn("power");
        ImGui::TableSetupColumn("specialty");
        ImGui::TableSetupColumn("rank");
        ImGui::TableSetupColumn("type");
        ImGui::TableSetupColumn("target");
        ImGui::TableSetupColumn("text");
        ImGui::TableHeadersRow();
        ImGuiListClipper clip;
        clip.Begin(rows.Size);
        while (clip.Step()) {
            for (int r = clip.DisplayStart; r < clip.DisplayEnd; r++) {
                const DevSkill *k = DevData_SkillAt(rows[r]);

                ImGui::TableNextRow();
                ImGui::TableNextColumn();
                ImGui::Text("0x%03X", k->id);
                ImGui::TableNextColumn();
                ImGui::TextUnformatted(k->name);
                ImGui::TableNextColumn();
                ImGui::Text("%d", k->mp);
                ImGui::TableNextColumn();
                ImGui::Text("%d", k->power);
                ImGui::TableNextColumn();
                ImGui::TextUnformatted(DevData_SpecialtyName(k->specialty));
                ImGui::TableNextColumn();
                ImGui::Text("%d", k->rank);
                ImGui::TableNextColumn();
                ImGui::Text("%d", k->type);
                ImGui::TableNextColumn();
                ImGui::Text("%d", k->target);
                ImGui::TableNextColumn();
                ImGui::TextUnformatted(k->desc);
            }
        }
        ImGui::EndTable();
    }
}

/* Digimon picker: a combo with its own search field, DIGIMNDT Digimon only */
void digi_combo(const char *label, int *id, ImGuiTextFilter &f, int max_id = 0x3FF) {
    char preview[48];

    snprintf(preview, sizeof(preview), "0x%03X %s", *id, DevData_DigiName(*id));
    ImGui::SetNextItemWidth(ImGui::CalcTextSize("0x000 MMMMMMMMMMMMMMMMMM").x);
    if (ImGui::BeginCombo(label, preview, ImGuiComboFlags_HeightLarge)) {
        if (ImGui::IsWindowAppearing()) {
            ImGui::SetKeyboardFocusHere();
        }
        f.Draw("##find");
        for (int i = 0; i < DevData_DigiCount(); i++) {
            const DevDigi *d = DevData_DigiAt(i);
            char item[48];

            if (!d->hasBase || d->id > max_id || !pass(f, d->id, d->name, DevData_RankName(d->rank))) {
                continue;
            }
            snprintf(item, sizeof(item), "0x%03X %s (%s)", d->id, d->name, DevData_RankName(d->rank));
            if (ImGui::Selectable(item, d->id == *id)) {
                *id = d->id;
            }
        }
        ImGui::EndCombo();
    }
}

/* ---- PD.4 state edit (host/devedit.h): the Save tab's Edit controls ----
 * Each control queues a DevEdit record; the game thread applies it at its next VBlank wait and
 * logs it ([devedit] line, the last ones shown under "Edit log"). Nothing here writes game memory.
 * Fields follow the game value until the user types into them. */

DevEdit edit_rec(int kind, int a, int b, int c) {
    DevEdit e;

    memset(&e, 0, sizeof(e));
    memset(e.text, 0xFF, sizeof(e.text));
    e.kind = kind;
    e.a = a;
    e.b = b;
    e.c = c;
    return e;
}

void push(const DevEdit &e) {
    if (DevEdit_Push(&e)) {
        snprintf(g_edit_msg, sizeof(g_edit_msg), "queued: %s %d %d %d", DevEdit_KindName(e.kind), e.a, e.b, e.c);
    } else {
        snprintf(g_edit_msg, sizeof(g_edit_msg), "not queued: queue full or edits off");
    }
}

/* an input that shows the game value until edited */
struct Field {
    int buf = 0, last = 0;
    bool init = false;

    void follow(int cur) {
        if (!init || last != cur) {
            buf = cur;
            last = cur;
            init = true;
        }
    }
};

bool int_input(const char *label, int *v, int chars = 8) {
    ImGui::SetNextItemWidth(ImGui::CalcTextSize("0").x * (float)chars + ImGui::GetFrameHeight() * 2);
    return ImGui::InputInt(label, v);
}

/* InputInt + Set: true when Set is pressed */
bool int_set(const char *label, Field &f, int cur, int chars = 8) {
    f.follow(cur);
    ImGui::PushID(label);
    int_input(label, &f.buf, chars);
    ImGui::SameLine();
    bool r = ImGui::SmallButton("Set");
    ImGui::PopID();
    return r;
}

/* item picker; category < 0 = any item, max_id caps the id (storage: 0xFF). *id 0 = none. */
bool item_combo(const char *label, int *id, ImGuiTextFilter &f, int category, bool none, int max_id = 0x1FF) {
    char preview[48];
    bool picked = false;

    if (*id != 0) {
        snprintf(preview, sizeof(preview), "0x%03X %s", *id, DevData_ItemName(*id));
    } else {
        snprintf(preview, sizeof(preview), "- none -");
    }
    ImGui::SetNextItemWidth(ImGui::CalcTextSize("0x000 MMMMMMMMMMMMMM").x);
    if (ImGui::BeginCombo(label, preview, ImGuiComboFlags_HeightLarge)) {
        if (ImGui::IsWindowAppearing()) {
            ImGui::SetKeyboardFocusHere();
        }
        f.Draw("##find");
        if (none && ImGui::Selectable("- none -", *id == 0)) {
            *id = 0;
            picked = true;
        }
        for (int i = 0; i < DevData_ItemCount(); i++) {
            const DevItem *it = DevData_ItemAt(i);
            char item[64];

            if ((category >= 0 && it->category != category) || it->id > max_id ||
                !pass(f, it->id, it->name, DevData_CategoryName(it->category))) {
                continue;
            }
            snprintf(item, sizeof(item), "0x%03X %s (%s)", it->id, it->name, DevData_CategoryName(it->category));
            if (ImGui::Selectable(item, it->id == *id)) {
                *id = it->id;
                picked = true;
            }
        }
        ImGui::EndCombo();
    }
    return picked;
}

bool skill_combo(const char *label, int *id, ImGuiTextFilter &f) {
    char preview[48];
    bool picked = false;

    snprintf(preview, sizeof(preview), *id ? "0x%02X %s" : "- none -", *id, DevData_SkillName(*id));
    ImGui::SetNextItemWidth(ImGui::CalcTextSize("0x00 MMMMMMMMMMMMMMMM").x);
    if (ImGui::BeginCombo(label, preview, ImGuiComboFlags_HeightLarge)) {
        if (ImGui::IsWindowAppearing()) {
            ImGui::SetKeyboardFocusHere();
        }
        f.Draw("##find");
        if (ImGui::Selectable("- none -", *id == 0)) {
            *id = 0;
            picked = true;
        }
        for (int i = 0; i < DevData_SkillCount(); i++) {
            const DevSkill *k = DevData_SkillAt(i);
            char item[64];

            if (k->id > 0xFF || !pass(f, k->id, k->name, DevData_SpecialtyName(k->specialty))) {
                continue;
            }
            snprintf(item, sizeof(item), "0x%02X %s (MP %d)", k->id, k->name, k->mp);
            if (ImGui::Selectable(item, k->id == *id)) {
                *id = k->id;
                picked = true;
            }
        }
        ImGui::EndCombo();
    }
    return picked;
}

void edit_log(void) {
    char lines[8][DEVEDIT_RESULT_LEN];
    int n = DevEdit_Results(lines, 8);

    if (g_edit_msg[0] != 0) {
        ImGui::TextDisabled("%s", g_edit_msg);
    }
    if (n > 0 && ImGui::TreeNode("Edit log (newest first)")) {
        for (int i = 0; i < n; i++) {
            const char *l = lines[i];

            if (strstr(l, "refused") != NULL) {
                ImGui::TextColored(k_bad, "%s", l);
            } else {
                ImGui::TextUnformatted(l);
            }
        }
        ImGui::TreePop();
    }
}

void edit_tamer(const DevSnap &s) {
    static Field bits, rank, progress;

    if (int_set("bits", bits, s.bits, 9)) {
        push(edit_rec(DEVEDIT_BITS, bits.buf));
    }
    ImGui::SameLine();
    if (int_set("rank", rank, s.rank, 4)) {
        push(edit_rec(DEVEDIT_RANK, rank.buf));
    }
    ImGui::SameLine();
    if (int_set("progress", progress, s.progress, 4)) {
        push(edit_rec(DEVEDIT_PROGRESS, progress.buf));
    }
}

void edit_digi(const DevSnap &s, int slot) {
    static int shown_slot = -1;
    static Field fields[DEVDIGI_FIELDS];
    static ImGuiTextFilter fsp, fsk[12];
    static char nick[16];
    static char nick_err[64];
    const DevSnapDigi &d = s.roster[slot];
    int cur[DEVDIGI_FIELDS] = { d.digiId, d.level, d.maxLevel, d.exp, d.dp, d.hp, d.maxHp, d.mp, d.maxMp,
                                d.attack, d.defense, d.speed };

    if (shown_slot != slot) {
        shown_slot = slot;
        for (Field &f : fields) {
            f.init = false;
        }
        nick[0] = 0;
        nick_err[0] = 0;
    }
    ImGui::SeparatorText("Edit Digimon");
    if (slot < 3 && (s.gameMode >> 8 == 5 || s.gameMode >> 8 == 7)) {
        ImGui::TextColored(k_bad, "party slot in battle: edits are refused (the battle copies the party back)");
    }
    fields[DEVDIGI_SPECIES].follow(d.digiId);
    digi_combo("species##edit", &fields[DEVDIGI_SPECIES].buf, fsp, 0xFF);
    ImGui::SameLine();
    if (ImGui::SmallButton("Set species")) {
        push(edit_rec(DEVEDIT_DIGI, slot, DEVDIGI_SPECIES, fields[DEVDIGI_SPECIES].buf));
    }
    if (ImGui::BeginTable("digiedit", 4, ImGuiTableFlags_SizingFixedFit)) {
        for (int f = DEVDIGI_LEVEL; f < DEVDIGI_FIELDS; f++) {
            fields[f].follow(cur[f]);
            ImGui::TableNextColumn();
            ImGui::PushID(f);
            int_input(DevEdit_DigiFieldName(f), &fields[f].buf, f == DEVDIGI_EXP ? 9 : 5);
            ImGui::PopID();
        }
        ImGui::EndTable();
    }
    if (ImGui::SmallButton("Apply changed fields")) {
        /* level first: it also sets exp, an exp typed in comes after it */
        for (int f = DEVDIGI_LEVEL; f < DEVDIGI_FIELDS; f++) {
            if (fields[f].buf != cur[f]) {
                push(edit_rec(DEVEDIT_DIGI, slot, f, fields[f].buf));
            }
        }
    }
    ImGui::SameLine();
    ImGui::TextDisabled("level also sets exp (a fresh Digimon at that level)");
    ImGui::SetNextItemWidth(ImGui::CalcTextSize("MMMMMMMMMMMMMM").x);
    ImGui::InputText("nickname (A-Z a-z 0-9 space & ? ! / - , . ' \" ; : % + = #)", nick, sizeof(nick));
    ImGui::SameLine();
    if (ImGui::SmallButton("Set name")) {
        DevEdit e = edit_rec(DEVEDIT_NAME, slot);

        if (DevEdit_EncodeText(nick, e.text, (int)sizeof(e.text)) > 0) {
            push(e);
            nick_err[0] = 0;
        } else {
            snprintf(nick_err, sizeof(nick_err), "1..13 characters the game font has");
        }
    }
    if (nick_err[0] != 0) {
        ImGui::TextColored(k_bad, "%s", nick_err);
    }
    if (ImGui::TreeNode("Skills (pick to set)")) {
        for (int k = 0; k < 12; k++) {
            int id = d.skills[k];
            char label[16];

            snprintf(label, sizeof(label), "%2d##sk%d", k, k);
            if (skill_combo(label, &id, fsk[k])) {
                push(edit_rec(DEVEDIT_SKILL, slot, k, id));
            }
            if (k % 2 == 0) {
                ImGui::SameLine();
            }
        }
        ImGui::TreePop();
    }
}

void edit_add_digi(void) {
    static ImGuiTextFilter f;
    static int species = 0x29, level = 10;

    ImGui::SeparatorText("Add Digimon (to the Digimon server)");
    digi_combo("##addsp", &species, f, 0xFF);
    ImGui::SameLine();
    int_input("level##add", &level, 3);
    ImGui::SameLine();
    if (ImGui::SmallButton("Add")) {
        DevEdit e = edit_rec(DEVEDIT_ADD_DIGI, species, level, level < 28 ? level + 10 : level + 2);
        static const int16_t stats[5] = { 100, 50, 30, 30, 30 };

        memcpy(e.v, stats, sizeof(e.v));
        e.d = -1; /* the species' own skill */
        push(e);
    }
    ImGui::TextDisabled("stats HP 100 MP 50 A / D / S 30, max level +10 (edit them after)");
}

void edit_beetle(const DevSnap &s) {
    static Field f[4];
    const int cur[4] = { s.beetleHp, s.beetleMaxHp, s.beetleMp, s.beetleMaxMp };
    static const char *const names[4] = { "HP", "max HP", "EP", "max EP" };

    for (int i = 0; i < 4; i++) {
        if (int_set(names[i], f[i], cur[i], 6)) {
            push(edit_rec(DEVEDIT_BEETLE, i, f[i].buf));
        }
        if (i != 3) {
            ImGui::SameLine();
        }
    }
}

/* one part row: item picker of the slot's category, broken checkbox */
void edit_part(const DevSnap &s, int slot) {
    static ImGuiTextFilter f[DEVSNAP_PARTS];
    int id = s.partItems[slot];
    bool broken = s.partBroken[slot] != 0;
    char label[16];

    snprintf(label, sizeof(label), "##part%d", slot);
    if (item_combo(label, &id, f[slot], slot == 0 ? 19 : slot - 1, true)) {
        push(edit_rec(DEVEDIT_PART, slot, id));
    }
    ImGui::TableNextColumn();
    ImGui::BeginDisabled(s.partItems[slot] == 0);
    snprintf(label, sizeof(label), "broken##b%d", slot);
    if (ImGui::Checkbox(label, &broken)) {
        push(edit_rec(DEVEDIT_BROKEN, slot, broken ? 1 : 0));
    }
    ImGui::EndDisabled();
}

void edit_bag_add(const DevSnap &s) {
    static ImGuiTextFilter f;
    static int id = 0x78;

    item_combo("##bagadd", &id, f, -1, false);
    ImGui::SameLine();
    if (ImGui::SmallButton("Add to bag")) {
        push(edit_rec(DEVEDIT_BAG_ADD, id));
    }
    ImGui::SameLine();
    ImGui::TextDisabled("bag size %d (tool box part)", s.bagCapacity);
}

void edit_storage(const DevSnap &s) {
    static ImGuiTextFilter f;
    static int id = 0x78;
    static Field count;
    static int shown = -1;

    if (shown != id) {
        shown = id;
        count.init = false;
    }
    item_combo("##storage", &id, f, -1, false, 0xFF);
    ImGui::SameLine();
    if (int_set("count##st", count, s.storage[id & 0xFF], 4)) {
        push(edit_rec(DEVEDIT_STORAGE, id, count.buf));
    }
}

void edit_flag(const DevSnap &s, int id) {
    if (id < 1000) {
        if (ImGui::SmallButton("Set flag")) {
            push(edit_rec(DEVEDIT_FLAG, id, 1));
        }
        ImGui::SameLine();
        if (ImGui::SmallButton("Clear flag")) {
            push(edit_rec(DEVEDIT_FLAG, id, 0));
        }
    } else if (id < 1600) {
        ImGui::TextDisabled("ids 1000..1599 follow progress (%d): set it in the Tamer line", s.progress);
    } else if (id < 3000) {
        ImGui::TextDisabled("ids 1600..2999 test the bag / storage: edit those");
    } else if (id < 4000) {
        ImGui::TextDisabled("ids 3000..3999 test the roster: add or change a Digimon");
    } else {
        ImGui::TextDisabled("ids 4000 up: city scripts' one-shot actions, not editable");
    }
}

void panel_warp(const DevSnap &s) {
    static ImGuiTextFilter f;
    static int sel = -1;
    static Field floor;
    const DevDest *d = DevData_DestAt(sel);
    bool city = s.gameMode >> 8 == 3;

    ImGui::Text("Now: game mode 0x%03X, arg %d (%s)", s.gameMode, s.modeArg,
                s.gameMode >> 8 == 2 ? DevData_DestName(0x200, s.dungeonIdx) : DevData_DestName(s.gameMode, s.modeArg));
    if (s.canWarp) {
        ImGui::TextColored(ImVec4(0.4f, 1, 0.4f, 1), "warp possible");
    } else {
        ImGui::TextColored(k_bad, "no warp now: %s", s.warpWhy != NULL ? s.warpWhy : "?");
    }
    char preview[64];
    if (d != NULL) {
        snprintf(preview, sizeof(preview), "0x%03X / %d %s", d->mode, d->arg, d->name);
    } else {
        snprintf(preview, sizeof(preview), "pick a destination");
    }
    ImGui::SetNextItemWidth(ImGui::CalcTextSize("0x000 / 00 MMMMMMMMMMMMMMMMMMMMMMMM").x);
    if (ImGui::BeginCombo("##dest", preview, ImGuiComboFlags_HeightLarge)) {
        if (ImGui::IsWindowAppearing()) {
            ImGui::SetKeyboardFocusHere();
        }
        f.Draw("##find");
        for (int i = 0; i < DevData_DestCount(); i++) {
            const DevDest *x = DevData_DestAt(i);
            char item[80];

            if (!pass(f, x->mode, x->name, x->mode == 0x200 ? "domain" : "city")) {
                continue;
            }
            snprintf(item, sizeof(item), "0x%03X / %2d %s%s", x->mode, x->arg, x->name, x->named ? "" : " (map exit)");
            if (ImGui::Selectable(item, i == sel)) {
                sel = i;
            }
        }
        ImGui::EndCombo();
    }
    ImGui::SameLine();
    bool domain_from_city_only = d != NULL && d->mode == 0x200 && !city;
    ImGui::BeginDisabled(d == NULL || !s.canWarp || domain_from_city_only);
    if (ImGui::SmallButton("Warp")) {
        push(edit_rec(DEVEDIT_WARP, d->mode, d->arg));
    }
    ImGui::EndDisabled();
    if (domain_from_city_only) {
        ImGui::TextDisabled("domains are entered from the city only");
    }
    if (s.gameMode >> 8 == 2) {
        ImGui::Text("%s, floor %d (%dF) of %d", DevData_DestName(0x200, s.dungeonIdx), s.floor, s.floor + 1,
                    s.floorCount);
        ImGui::BeginDisabled(!s.canFloor);
        if (int_set("floor (0 = 1F)", floor, s.floor, 3)) {
            push(edit_rec(DEVEDIT_FLOOR, floor.buf));
        }
        ImGui::EndDisabled();
        if (!s.canFloor) {
            ImGui::TextDisabled("%s", s.floorWhy != NULL ? s.floorWhy : "");
        }
    }
    ImGui::TextDisabled("a cut, no fade out; the new scene fades in. Battles, title, card and VS screens: no warp.");
}

void data_dna(void) {
    static ImGuiTextFilter fa, fb, filt;
    static int a = 5, b = 0;
    static ImVector<int> rows;
    const DevDigi *da = DevData_Digi(a);
    int level = 0, r;

    ImGui::TextWrapped("DNA digivolution (stag2000 dna.c Stg20_GetDnaResult): result by type pair, the lower rank "
                       "and both DNA groups. Champions and up only.");
    digi_combo("parent A", &a, fa);
    if (b == 0) {
        b = a;
    }
    digi_combo("parent B", &b, fb);
    r = DevData_DnaResult(a, b, &level);
    if (r != 0) {
        ImGui::Text("Result 0x%03X %s, starts at level %d", r, DevData_DigiName(r), level);
    } else {
        ImGui::TextDisabled("no result (a Rookie parent, DNA group 8 boss form, or no DIGIMNDT data)");
    }
    if (da == NULL) {
        return;
    }
    ImGui::SeparatorText("All partners of parent A");
    search_box(filt, "search partner or result##dna");
    rows.resize(0);
    for (int i = 0; i < DevData_DigiCount(); i++) {
        const DevDigi *d = DevData_DigiAt(i);
        int lv, res;

        if (!d->hasBase || d->rank == 0) {
            continue;
        }
        res = DevData_DnaResult(a, d->id, &lv);
        if (pass(filt, d->id, d->name, DevData_DigiName(res))) {
            rows.push_back(i);
        }
    }
    if (ImGui::BeginTable("dna", 3, k_list_flags, ImVec2(0, list_height(false)))) {
        ImGui::TableSetupScrollFreeze(0, 1);
        ImGui::TableSetupColumn("partner");
        ImGui::TableSetupColumn("result");
        ImGui::TableSetupColumn("level");
        ImGui::TableHeadersRow();
        ImGuiListClipper clip;
        clip.Begin(rows.Size);
        while (clip.Step()) {
            for (int k = clip.DisplayStart; k < clip.DisplayEnd; k++) {
                const DevDigi *d = DevData_DigiAt(rows[k]);
                int lv, res = DevData_DnaResult(a, d->id, &lv);

                ImGui::TableNextRow();
                ImGui::TableNextColumn();
                ImGui::Text("0x%03X %s (%s)", d->id, d->name, DevData_RankName(d->rank));
                ImGui::TableNextColumn();
                if (res != 0) {
                    ImGui::Text("0x%03X %s", res, DevData_DigiName(res));
                    ImGui::TableNextColumn();
                    ImGui::Text("%d", lv);
                } else {
                    ImGui::TextDisabled("-");
                }
            }
        }
        ImGui::EndTable();
    }
}

void panel_data(void) {
    if (!DevData_Ready()) {
        ImGui::TextDisabled("tables not loaded: dw2.pak not open yet or a file did not parse (see the log)");
        return;
    }
    if (ImGui::BeginTabBar("data")) {
        if (ImGui::BeginTabItem("Digimon", NULL, sub_flags("Digimon"))) {
            data_digimon();
            ImGui::EndTabItem();
        }
        if (ImGui::BeginTabItem("Items", NULL, sub_flags("Items"))) {
            data_items();
            ImGui::EndTabItem();
        }
        if (ImGui::BeginTabItem("Skills", NULL, sub_flags("Skills"))) {
            data_skills();
            ImGui::EndTabItem();
        }
        if (ImGui::BeginTabItem("DNA", NULL, sub_flags("DNA"))) {
            data_dna();
            ImGui::EndTabItem();
        }
        ImGui::EndTabBar();
        g_start_sub[0] = 0; /* used once the tables are there */
    }
}

void panel_view(void) {
    ImGuiStyle &st = ImGui::GetStyle();
    int w = 0, h = 0, pw = 0, ph = 0;

    SDL_GetWindowSize(g_window, &w, &h);
    SDL_GetWindowSizeInPixels(g_window, &pw, &ph);
    ImGui::Text("Window %dx%d (%dx%d pixels), display scale %.2f", w, h, pw, ph, g_dpi);
    ImGui::Text("Font scale %.2f (%s)", st.FontScaleMain, g_user_scale > 0 ? "set" : "automatic: window height");
    ImGui::SliderFloat("##scale", &g_user_scale, 0.0f, 4.0f, g_user_scale > 0 ? "%.2f" : "automatic");
    ImGui::Checkbox("ImGui metrics window", &g_show_metrics);
    ImGui::TextDisabled("Dear ImGui %s, renderer %s", IMGUI_VERSION, SDL_GetRendererName(g_renderer));
}

ImGuiTabItemFlags tab_flags(const char *name) {
    return g_start_tab[0] != 0 && SDL_strcasecmp(g_start_tab, name) == 0 ? ImGuiTabItemFlags_SetSelected : 0;
}

ImGuiTabItemFlags sub_flags(const char *name) {
    return g_start_sub[0] != 0 && SDL_strcasecmp(g_start_sub, name) == 0 ? ImGuiTabItemFlags_SetSelected : 0;
}

void draw_overlay(void) {
    ImGuiIO &io = ImGui::GetIO();
    ImGuiStyle &st = ImGui::GetStyle();
    float auto_scale = io.DisplaySize.y / 900.0f;
    static ImVec2 last_pos(-1, -1), last_size(0, 0);

    auto_scale = auto_scale < 1.0f ? 1.0f : (float)(int)(auto_scale * 4 + 0.5f) / 4;
    st.FontScaleMain = g_user_scale > 0 ? g_user_scale : auto_scale;

    /* keep the window on screen when the game window shrinks */
    ImVec2 ds = io.DisplaySize;
    ImGui::SetNextWindowSizeConstraints(ImVec2(ds.x < 200 ? ds.x : 200, ds.y < 120 ? ds.y : 120), ds);
    if (last_size.x > 0 && (last_pos.x + 40 > ds.x || last_pos.y + 20 > ds.y || last_pos.x < 0 || last_pos.y < 0)) {
        float x = ds.x - last_size.x, y = ds.y - last_size.y;
        ImGui::SetNextWindowPos(ImVec2(x < 0 ? 0 : x, y < 0 ? 0 : y), ImGuiCond_Always);
    } else {
        ImGui::SetNextWindowPos(ImVec2(ds.x * 0.02f, ds.y * 0.03f), ImGuiCond_FirstUseEver);
    }
    float want_w = 560.0f * st.FontScaleMain * g_dpi;
    want_w = ds.x * 0.48f > want_w ? ds.x * 0.48f : want_w;
    ImGui::SetNextWindowSize(ImVec2(want_w < ds.x * 0.96f ? want_w : ds.x * 0.96f, ds.y * 0.85f), ImGuiCond_FirstUseEver);
    ImGui::SetNextWindowBgAlpha(0.88f);
    if (ImGui::Begin("DW2 dev (F2)")) {
        if (!g_have_snap) {
            ImGui::TextDisabled("waiting for the first snapshot from the game thread");
        } else if (ImGui::BeginTabBar("tabs")) {
            if (ImGui::BeginTabItem("Timing", NULL, tab_flags("Timing"))) {
                panel_timing(g_snap);
                ImGui::EndTabItem();
            }
            if (ImGui::BeginTabItem("Game", NULL, tab_flags("Game"))) {
                panel_game(g_snap);
                ImGui::EndTabItem();
            }
            if (ImGui::BeginTabItem("Tasks", NULL, tab_flags("Tasks"))) {
                panel_tasks(g_snap);
                ImGui::EndTabItem();
            }
            if (ImGui::BeginTabItem("Heap", NULL, tab_flags("Heap"))) {
                panel_heap(g_snap);
                ImGui::EndTabItem();
            }
            if (ImGui::BeginTabItem("Input", NULL, tab_flags("Input"))) {
                panel_input(g_snap);
                ImGui::EndTabItem();
            }
            if (ImGui::BeginTabItem("Save", NULL, tab_flags("Save"))) {
                panel_save(g_snap);
                ImGui::EndTabItem();
            }
            if (ImGui::BeginTabItem("Data", NULL, tab_flags("Data"))) {
                panel_data();
                ImGui::EndTabItem();
            }
            if (ImGui::BeginTabItem("View", NULL, tab_flags("View"))) {
                panel_view();
                ImGui::EndTabItem();
            }
            ImGui::EndTabBar();
            g_start_tab[0] = 0;
        }
    }
    last_pos = ImGui::GetWindowPos();
    last_size = ImGui::GetWindowSize();
    ImGui::End();
    if (g_show_metrics) {
        ImGui::ShowMetricsWindow(&g_show_metrics);
    }
}

} // namespace

extern "C" {

void DevUi_SetTab(const char *name) {
    const char *sub = SDL_strchr(name, ':');

    SDL_strlcpy(g_start_tab, name, sizeof(g_start_tab));
    g_start_sub[0] = 0;
    if (sub != NULL) {
        g_start_tab[sub - name < (int)sizeof(g_start_tab) ? sub - name : sizeof(g_start_tab) - 1] = 0;
        SDL_strlcpy(g_start_sub, sub + 1, sizeof(g_start_sub));
    }
}

void DevUi_SetOpenAtStart(int on) {
    g_open_at_start = on != 0;
}

int DevUi_Headless(void) {
    return g_open_at_start && g_headless;
}

void DevUi_SetWindowSize(int w, int h) {
    g_win_w = w;
    g_win_h = h;
}

void DevUi_WindowSize(int *w, int *h) {
    if (g_win_w > 0 && g_win_h > 0) {
        *w = g_win_w;
        *h = g_win_h;
    }
}

void DevUi_Init(SDL_Window *window, SDL_Renderer *renderer, int headless) {
    g_window = window;
    g_renderer = renderer;
    g_headless = headless != 0;
    DevSnap_Init();
    /* the ImGui context, style and backends are host/ui.cpp's (PR.2) */
    g_dpi = SDL_GetDisplayContentScale(SDL_GetDisplayForWindow(window));
    if (!(g_dpi > 0.5f && g_dpi < 8.0f)) {
        g_dpi = 1.0f;
    }
    load_map();
    DevData_InitConst(); /* before the game thread runs */
    g_ready = true;
    if (g_open_at_start) {
        DevSnap_SetOpen(1);
    }
    printf("[devui] dev overlay ready (F2)%s\n", g_open_at_start ? ", open" : "");
    fflush(stdout);
}

int DevUi_IsOpen(void) {
    return g_ready && DevSnap_Open();
}

int DevUi_WantsKeyboard(void) {
    return DevUi_IsOpen() && ImGui::GetIO().WantCaptureKeyboard;
}

int DevUi_Event(const SDL_Event *e) {
    if (!g_ready) {
        return 0;
    }
    if (e->type == SDL_EVENT_KEY_DOWN && e->key.scancode == SDL_SCANCODE_F2) {
        if (!e->key.repeat) {
            DevSnap_SetOpen(!DevSnap_Open());
            printf("[devui] overlay %s (F2)\n", DevSnap_Open() ? "open" : "closed");
            fflush(stdout);
        }
        return 1;
    }
    return 0;
}

void DevUi_Draw(void) {
    DevData_Load(); /* once, when the pack is open: the tables for the names */
    if (DevSnap_Get(&g_snap)) {
        g_have_snap = true;
        update_rates(g_snap);
    }
    draw_overlay();
}

void DevUi_Shutdown(void) {
    if (!g_ready) {
        return;
    }
    g_ready = false;
    DevSnap_SetOpen(0);
}

} // extern "C"
