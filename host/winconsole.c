/* Windows release builds are GUI programs (-mwindows, CMakeLists.txt): started from Explorer they
 * open only the game window, no console. Started from cmd or PowerShell they get no console
 * handles, so the log goes to the parent console here. A run with redirected output (pipe or
 * file, e.g. Git Bash or the headless checks) already has valid handles and keeps them. */

#ifdef _WIN32
#include <stdio.h>
#include <windows.h>

#include "host/host_sdl.h"

void Host_AttachParentConsole(void) {
    HANDLE h = GetStdHandle(STD_ERROR_HANDLE);

    if (h != NULL && h != INVALID_HANDLE_VALUE) {
        return;
    }
    if (!AttachConsole(ATTACH_PARENT_PROCESS)) {
        return;
    }
    freopen("CONOUT$", "w", stdout);
    freopen("CONOUT$", "w", stderr);
}
#endif
