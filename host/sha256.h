#ifndef HOST_SHA256_H
#define HOST_SHA256_H

#include <stddef.h>
#include <stdint.h>

/* SHA-256 (FIPS 180-4), for the dw2.pak integrity check (host/pak.c). */

typedef struct {
    uint32_t state[8];
    uint64_t length; /* bytes hashed so far */
    uint8_t block[64];
    size_t used;     /* bytes in block */
} Sha256;

void Sha256_Init(Sha256 *s);
void Sha256_Update(Sha256 *s, const void *data, size_t size);
void Sha256_Final(Sha256 *s, uint8_t digest[32]);

#endif /* HOST_SHA256_H */
