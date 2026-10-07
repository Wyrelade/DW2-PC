#ifndef PSYQ_TYPES_H
#define PSYQ_TYPES_H

/* Psy-Q <sys/types.h> names. On the PS1 `long` is 32 bits; here every Psy-Q `long` is written
 * as int (and u_long as unsigned int) so the structs keep their PS1 layout in a 64-bit build
 * too. Prototypes keep the Psy-Q shape, only the width spelling differs.
 *
 * glibc's <sys/types.h> has its own u_long (unsigned long, 64-bit on Linux): it is included first
 * and the Psy-Q u_long becomes psyq_u_long under the same name from here on. u_char, u_short and
 * u_int are the same types in both. */
#ifndef _WIN32
#include <sys/types.h>
#define u_long psyq_u_long
#endif
typedef unsigned char u_char;
typedef unsigned short u_short;
typedef unsigned int u_int;
typedef unsigned int u_long;

#endif /* PSYQ_TYPES_H */
