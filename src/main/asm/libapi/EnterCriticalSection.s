/*
 * s32 EnterCriticalSection(void);
 * syscall 1: disable interrupts
 * Hand-written assembly in the original build (restored source, see PLAN Phase 4b).
 */

glabel EnterCriticalSection
    addiu      $a0, $zero, 0x1
    syscall    0
    jr         $ra
     nop
endlabel EnterCriticalSection
