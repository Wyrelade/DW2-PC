#ifndef PSYQ_TYPES_H
#define PSYQ_TYPES_H

/* Psy-Q <sys/types.h> names. On the PS1 `long` is 32 bits; here every Psy-Q `long` is written
 * as int (and u_long as unsigned int) so the structs keep their PS1 layout in a 64-bit build
 * too. Prototypes keep the Psy-Q shape, only the width spelling differs. */
typedef unsigned char u_char;
typedef unsigned short u_short;
typedef unsigned int u_int;
typedef unsigned int u_long;

#endif /* PSYQ_TYPES_H */
