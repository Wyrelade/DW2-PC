#ifndef PSYQ_LOG_H
#define PSYQ_LOG_H

/* Stub call log. Each Psy-Q entry point logs its first call (with the arguments) in call order;
 * DW2_PSYQ_LOG=all in the environment logs every call. */

void Psyq_Log(int *seen, const char *func, const char *fmt, ...);
/* Calls of all stubs so far (first calls and repeats). */
extern unsigned int Psyq_CallCount;

#define PSYQ_LOG(...)                                \
    do {                                             \
        static int psyq_seen_;                       \
        Psyq_Log(&psyq_seen_, __func__, __VA_ARGS__); \
    } while (0)

#endif /* PSYQ_LOG_H */
