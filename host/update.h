#ifndef HOST_UPDATE_H
#define HOST_UPDATE_H

/* PR.30 update check (host/update.c): at start, a background thread asks GitHub for the newest
 * DW2-PC release and compares its tag with DW2_VERSION, before the pack check and the window.
 * Nothing is downloaded or installed: a newer version asks "Update found" (open the download page
 * and quit, or play), then shows a line on the title and in F1 with a button to the page.
 * Off with the "update_check" setting (F1 Game tab) or --no-update-check; never in headless runs
 * unless --update-check asks for it. */

#ifdef __cplusplus
extern "C" {
#endif

/* The version of this program, the release tag without "v". Bump it with each release. */
#define DW2_VERSION "0.1.5"
#define DW2_RELEASES_URL "https://github.com/Wyrelade/DW2-PC/releases/latest"

/* main(), after Settings_Load: starts the check thread when wanted. force = --update-check. */
void Update_Start(int no_window, int force);
/* main(), right after Update_Start, before the pack check and the window: waits up to 3 s for
 * the answer; with a newer release a message box offers Update now / Download page / Not now.
 * Update now installs the release next to the program and starts it (argv: this run's arguments).
 * 1 = quit (the new program runs, or the download page is open). */
int Update_AskAtStart(int no_window, int argc, char **argv);
/* --update-auto: with a newer release, update without asking (also headless; tests). */
void Update_SetAuto(void);
/* --no-update-check (this run only). */
void Update_Disable(void);
/* --update-as VERSION (dev builds): compare as if this program were VERSION. */
void Update_SetLocalVersion(const char *version);

/* The version the check compares with: DW2_VERSION, or the --update-as one. */
const char *Update_LocalVersion(void);
/* Any thread: the newer release tag ("v0.1.4"), or NULL (none found, not checked yet, failed). */
const char *Update_NewerTag(void);
/* Any thread: a short state line for F1 ("Up to date", "Checking...", "Could not check"). */
const char *Update_StatusText(void);

#ifdef __cplusplus
}
#endif

#endif /* HOST_UPDATE_H */
