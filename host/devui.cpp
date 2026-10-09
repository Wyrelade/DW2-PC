/* PD.1 dev overlay (DW2_DEV only): Dear ImGui (host/imgui/, pinned in README.txt) with the SDL3
 * platform backend and the SDL_Renderer backend, on the renderer host/sdl.c presents with (the
 * SDL_GPU renderer or the default one: both paths, one backend). Main thread only. F2 toggles it.
 *
 * Read only: every panel draws from a DevSnap copy (host/devsnap.c fills it on the game thread at
 * its VBlank wait while the overlay is open). Nothing here calls the game or writes game memory.
 * ImGui draws in window pixels over the picture: the renderer's logical presentation (320 or 427 x
 * 240, letterboxed) is switched off around it, so the overlay keeps its size at any window size
 * and in 16:9; the font follows the display scale and the window height (View tab). Names and the
 * Data tab come from the game tables in dw2.pak (host/devdata.c, PD.7). */

#include <SDL3/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "imgui.h"
#include "backends/imgui_impl_sdl3.h"
#include "backends/imgui_impl_sdlrenderer3.h"

#include "host/devdata.h"
#include "host/devsnap.h"
#include "host/devui.h"

extern "C" int Host_WritePng(const char *path, const uint32_t *pixels, int w, int h);

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
char g_start_sub[16];

DevSnap g_snap;       /* the overlay's copy */
bool g_have_snap;

/* rates from snapshot deltas, over about one second */
uint64_t g_rate_ns, g_rate_vb, g_rate_flips;
int32_t g_rate_frames;
double g_vb_hz, g_flip_hz, g_frame_hz;

/* --devui headless shots: requested on the game side, written at the next render */
SDL_AtomicInt g_shot_pending;
char g_shot_path[1024];

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

void panel_save(const DevSnap &s) {
    char t[32];
    static int flag_id = 0;
    static int sel_digi = 0;

    play_time(s.playTime, t, sizeof(t));
    game_text("Tamer  ", s.playerName, (int)sizeof(s.playerName));
    ImGui::Text("Rank %d (title set %d)   Bits %d   Play time %s", s.rank, s.rankTitleSet, s.bits, t);
    if (!DevData_Ready()) {
        ImGui::TextDisabled("tables not loaded (dw2.pak): names show as ?");
    }
    if (ImGui::CollapsingHeader("Party", ImGuiTreeNodeFlags_DefaultOpen)) {
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
        } else {
            ImGui::TextDisabled("click a Digimon for its stats and skills");
        }
    }
    if (ImGui::CollapsingHeader("Digi-Beetle", ImGuiTreeNodeFlags_DefaultOpen)) {
        game_text("Name   ", s.beetleName, (int)sizeof(s.beetleName), s.playerName);
        ImGui::Text("HP %d / %d   EP %d / %d", s.beetleHp, s.beetleMaxHp, s.beetleMp, s.beetleMaxMp);
        if (ImGui::BeginTable("parts", 3, ImGuiTableFlags_BordersInnerV | ImGuiTableFlags_RowBg | ImGuiTableFlags_SizingFixedFit)) {
            ImGui::TableSetupColumn("slot");
            ImGui::TableSetupColumn("part (item)");
            ImGui::TableSetupColumn("status");
            ImGui::TableHeadersRow();
            for (int i = 0; i < DEVSNAP_PARTS; i++) {
                if (s.partItems[i] == 0 && s.partBroken[i] == 0) {
                    continue;
                }
                ImGui::TableNextRow();
                ImGui::TableNextColumn();
                ImGui::Text("%2d %s", i, DevData_SlotName(i));
                ImGui::TableNextColumn();
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
    if (ImGui::CollapsingHeader("Bag")) {
        int n = 0;

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
                id_name(s.bag[i], DevData_ItemName(s.bag[i]));
                n++;
            }
            ImGui::EndTable();
        }
        if (n == 0) {
            ImGui::TextDisabled("empty");
        }
    }
    if (ImGui::CollapsingHeader("Storage")) {
        int n = 0;

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
    if (ImGui::CollapsingHeader("Flags", ImGuiTreeNodeFlags_DefaultOpen)) {
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
void digi_combo(const char *label, int *id, ImGuiTextFilter &f) {
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

            if (!d->hasBase || !pass(f, d->id, d->name, DevData_RankName(d->rank))) {
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

void write_shot(void) {
    SDL_Surface *s = SDL_RenderReadPixels(g_renderer, NULL);
    SDL_Surface *c;

    if (s == NULL) {
        printf("[devui] shot: read failed (%s)\n", SDL_GetError());
        return;
    }
    c = SDL_ConvertSurface(s, SDL_PIXELFORMAT_XRGB8888);
    SDL_DestroySurface(s);
    if (c == NULL) {
        return;
    }
    /* rows into one block (pitch may be padded) */
    uint32_t *px = (uint32_t *)malloc((size_t)c->w * c->h * 4);
    if (px != NULL) {
        for (int y = 0; y < c->h; y++) {
            memcpy(px + (size_t)y * c->w, (const uint8_t *)c->pixels + (size_t)y * c->pitch, (size_t)c->w * 4);
        }
        if (Host_WritePng(g_shot_path, px, c->w, c->h)) {
            printf("[shot] %s (%dx%d)\n", g_shot_path, c->w, c->h);
        } else {
            printf("[shot] cannot write %s\n", g_shot_path);
        }
        free(px);
    }
    SDL_DestroySurface(c);
    fflush(stdout);
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
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    io.IniFilename = NULL; /* no imgui.ini in the working folder */
    io.LogFilename = NULL;
    ImGui::StyleColorsDark();
    g_dpi = SDL_GetDisplayContentScale(SDL_GetDisplayForWindow(window));
    if (!(g_dpi > 0.5f && g_dpi < 8.0f)) {
        g_dpi = 1.0f;
    }
    ImGui::GetStyle().ScaleAllSizes(g_dpi);
    ImGui::GetStyle().FontScaleDpi = g_dpi;
    if (!ImGui_ImplSDL3_InitForSDLRenderer(window, renderer) || !ImGui_ImplSDLRenderer3_Init(renderer)) {
        printf("[devui] ImGui backend init failed: overlay off\n");
        return;
    }
    load_map();
    DevData_InitConst(); /* before the game thread runs */
    g_ready = true;
    if (g_open_at_start) {
        DevSnap_SetOpen(1);
    }
    printf("[devui] Dear ImGui %s ready (F2), display scale %.2f%s\n", IMGUI_VERSION, g_dpi,
           g_open_at_start ? ", open" : "");
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
    if (!DevSnap_Open()) {
        return 0;
    }
    ImGui_ImplSDL3_ProcessEvent(e);
    if ((e->type == SDL_EVENT_KEY_DOWN || e->type == SDL_EVENT_KEY_UP || e->type == SDL_EVENT_TEXT_INPUT) &&
        ImGui::GetIO().WantCaptureKeyboard) {
        return 1;
    }
    return 0;
}

void DevUi_Render(void) {
    int lw, lh;
    SDL_RendererLogicalPresentation mode;

    if (!DevUi_IsOpen()) {
        return;
    }
    DevData_Load(); /* once, when the pack is open: the tables for the names */
    if (DevSnap_Get(&g_snap)) {
        g_have_snap = true;
        update_rates(g_snap);
    }
    ImGui_ImplSDLRenderer3_NewFrame();
    ImGui_ImplSDL3_NewFrame();
    ImGui::NewFrame();
    draw_overlay();
    ImGui::Render();
    /* window pixels for ImGui: the logical presentation off around it */
    SDL_GetRenderLogicalPresentation(g_renderer, &lw, &lh, &mode);
    SDL_SetRenderLogicalPresentation(g_renderer, 0, 0, SDL_LOGICAL_PRESENTATION_DISABLED);
    ImGui_ImplSDLRenderer3_RenderDrawData(ImGui::GetDrawData(), g_renderer);
    if (SDL_GetAtomicInt(&g_shot_pending)) {
        write_shot();
        SDL_SetAtomicInt(&g_shot_pending, 0);
    }
    SDL_SetRenderLogicalPresentation(g_renderer, lw, lh, mode);
}

void DevUi_Shot(const char *dir, const char *tag) {
    if (!DevUi_Headless() || SDL_GetAtomicInt(&g_shot_pending)) {
        return;
    }
    snprintf(g_shot_path, sizeof(g_shot_path), "%s/%s_devui.png", dir, tag);
    SDL_SetAtomicInt(&g_shot_pending, 1);
}

void DevUi_Shutdown(void) {
    if (!g_ready) {
        return;
    }
    g_ready = false;
    DevSnap_SetOpen(0);
    ImGui_ImplSDLRenderer3_Shutdown();
    ImGui_ImplSDL3_Shutdown();
    ImGui::DestroyContext();
}

} // extern "C"
