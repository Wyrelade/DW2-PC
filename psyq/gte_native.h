#ifndef PSYQ_GTE_NATIVE_H
#define PSYQ_GTE_NATIVE_H

/* Native build: the 20 gte.h macros (main/model.c) as C calls into psyq/gte.c, on the C GTE
 * model (psyq/gte_core.h) that libgte shares. */

void GteC_ldv0(const void *r0);
void GteC_ldv0u(const void *r0);
void GteC_ldlv0(const void *r0);
void GteC_ldclmv(const void *r0);
void GteC_ldsxy3(int r0, int r1, int r2);
void GteC_SetRotMatrix(const void *r0);
void GteC_SetTransMatrix(const void *r0);
void GteC_SetLightMatrix(const void *r0);
void GteC_rtps(void);
void GteC_rtir(void);
void GteC_rtv0tr(void);
void GteC_ncs(void);
void GteC_nclip(void);
void GteC_stflg(void *r0);
void GteC_stsxy(void *r0);
void GteC_stszotz(void *r0);
void GteC_strgb(void *r0);
void GteC_stclmv(void *r0);
void GteC_stlvnl(void *r0);
void GteC_stopz(void *r0);

#define gte_ldv0(r0) GteC_ldv0((const void *)(r0))
#define gte_ldv0u(r0) GteC_ldv0u((const void *)(r0))
#define gte_ldlv0(r0) GteC_ldlv0((const void *)(r0))
#define gte_ldclmv(r0) GteC_ldclmv((const void *)(r0))
#define gte_ldsxy3(r0, r1, r2) GteC_ldsxy3((int)(r0), (int)(r1), (int)(r2))
#define gte_SetRotMatrix(r0) GteC_SetRotMatrix((const void *)(r0))
#define gte_SetTransMatrix(r0) GteC_SetTransMatrix((const void *)(r0))
#define gte_SetLightMatrix(r0) GteC_SetLightMatrix((const void *)(r0))
#define gte_rtps() GteC_rtps()
#define gte_rtir() GteC_rtir()
#define gte_rtv0tr() GteC_rtv0tr()
#define gte_ncs() GteC_ncs()
#define gte_nclip() GteC_nclip()
#define gte_stflg(r0) GteC_stflg((void *)(r0))
#define gte_stsxy(r0) GteC_stsxy((void *)(r0))
#define gte_stszotz(r0) GteC_stszotz((void *)(r0))
#define gte_strgb(r0) GteC_strgb((void *)(r0))
#define gte_stclmv(r0) GteC_stclmv((void *)(r0))
#define gte_stlvnl(r0) GteC_stlvnl((void *)(r0))
#define gte_stopz(r0) GteC_stopz((void *)(r0))

#endif /* PSYQ_GTE_NATIVE_H */
