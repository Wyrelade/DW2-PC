#ifndef COMMON_H
#define COMMON_H

#include "include_asm.h"

#ifdef DW2_NATIVE
/* Native build: the real Psy-Q prototypes and types (psyq/). */
#include "psyq/psyq.h"
#include "host/host.h"
#endif

typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;
typedef float f32;
typedef double f64;

typedef unsigned char undefined;
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

#ifndef NULL
#define NULL ((void *)0)
#endif

/* Pointer width (native build, P1.12). The retail code keeps pointers in 32-bit ints (task slots,
 * file words) and types one object's field as a pointer in one view and as an int in another.
 * Every native build keeps all game addresses below 2 GB, so a 32-bit int gives a pointer back;
 * what a 64-bit build must keep is one layout for all views of an object:
 *   sptr / uptr      an int field holding a pointer where another view of that object has a
 *                    pointer: s32 / u32 on the PS1 and in the 32-bit build, pointer-sized in 64-bit.
 *   PTR32(T)         a pointer field where the rest of the code keeps a 32-bit int (task slots
 *                    written by Task_Create): T * except in 64-bit, where it is a u32 read with
 *                    P32(T, x) and written with P32_SET(x).
 *   NATIVE_OFS(T, f, n)  a pad that ends at field f of the real object T: n on the PS1, offsetof
 *                    natively; PTRW(n32, n64) where T is not defined yet (checked with
 *                    NATIVE_ASSERT after T).
 *   NATIVE_SIZE(T, n)  the size of T: n on the PS1 (literal sizes of Mem_Alloc / Mem_Zero). */
#ifdef DW2_NATIVE
#include <stddef.h>
#include <stdint.h>
typedef intptr_t sptr;
typedef uintptr_t uptr;
#if UINTPTR_MAX > 0xFFFFFFFFu
#define DW2_PTR64 1
#define PTR32(T) u32
#define P32(T, x) ((T *)(uptr)(x))
#define P32_SET(x) ((u32)(uptr)(x))
#endif
#define NATIVE_OFS(T, f, n) offsetof(T, f)
#define NATIVE_SIZE(T, n) sizeof(T)
#define NATIVE_ASSERT(c) _Static_assert(c, #c);
#else
typedef s32 sptr;
typedef u32 uptr;
#define NATIVE_OFS(T, f, n) (n)
#define NATIVE_SIZE(T, n) (n)
#define NATIVE_ASSERT(c)
#endif
/* PTRW(n32, n64): a size or offset that differs only by the pointer width. */
#ifdef DW2_PTR64
#define PTRW(n32, n64) (n64)
#else
#define PTRW(n32, n64) (n32)
#endif
#ifndef DW2_PTR64
#define PTR32(T) T *
#define P32(T, x) ((T *)(x))
#define P32_SET(x) (x)
#endif

#endif /* COMMON_H */
