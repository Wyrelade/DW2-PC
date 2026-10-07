#include "gte_native.h"
#include "psyq_log.h"

/* gte.h macros (psyq/gte_native.h), P1.1 stubs: log the first use, no GTE state. Stores leave
 * their target alone. P1.5 replaces these with the C fixed-point GTE. */

void GteC_ldv0(const void *r0) { PSYQ_LOG("%p", r0); }
void GteC_ldv0u(const void *r0) { PSYQ_LOG("%p", r0); }
void GteC_ldlv0(const void *r0) { PSYQ_LOG("%p", r0); }
void GteC_ldclmv(const void *r0) { PSYQ_LOG("%p", r0); }
void GteC_ldsxy3(int r0, int r1, int r2) { PSYQ_LOG("0x%X, 0x%X, 0x%X", r0, r1, r2); }
void GteC_SetRotMatrix(const void *r0) { PSYQ_LOG("%p", r0); }
void GteC_SetTransMatrix(const void *r0) { PSYQ_LOG("%p", r0); }
void GteC_SetLightMatrix(const void *r0) { PSYQ_LOG("%p", r0); }
void GteC_rtps(void) { PSYQ_LOG(""); }
void GteC_rtir(void) { PSYQ_LOG(""); }
void GteC_rtv0tr(void) { PSYQ_LOG(""); }
void GteC_ncs(void) { PSYQ_LOG(""); }
void GteC_nclip(void) { PSYQ_LOG(""); }
void GteC_stflg(void *r0) { PSYQ_LOG("%p", r0); }
void GteC_stsxy(void *r0) { PSYQ_LOG("%p", r0); }
void GteC_stszotz(void *r0) { PSYQ_LOG("%p", r0); }
void GteC_strgb(void *r0) { PSYQ_LOG("%p", r0); }
void GteC_stclmv(void *r0) { PSYQ_LOG("%p", r0); }
void GteC_stlvnl(void *r0) { PSYQ_LOG("%p", r0); }
void GteC_stopz(void *r0) { PSYQ_LOG("%p", r0); }
