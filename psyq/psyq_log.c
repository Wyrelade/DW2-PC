#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "psyq_log.h"

unsigned int Psyq_CallCount;
static unsigned int first_calls;
static int log_all = -1;

void Psyq_Log(int *seen, const char *func, const char *fmt, ...) {
    va_list ap;

    Psyq_CallCount++;
    if (log_all < 0) {
        const char *e = getenv("DW2_PSYQ_LOG");
        log_all = e != NULL && strcmp(e, "all") == 0;
    }
    if (*seen && !log_all) {
        return;
    }
    if (!*seen) {
        first_calls++;
    }
    printf("[psyq] %s #%u (call %u) %s(", *seen ? "call " : "first", first_calls, Psyq_CallCount, func);
    *seen = 1;
    va_start(ap, fmt);
    vprintf(fmt, ap);
    va_end(ap);
    printf(")\n");
    fflush(stdout);
}
