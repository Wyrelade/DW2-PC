/*
 * void ExitCriticalSection(void);
 * syscall 2: enable interrupts
 * Hand-written assembly in the original build (restored source, see PLAN Phase 4b).
 */

glabel ExitCriticalSection
    addiu      $a0, $zero, 0x2
    syscall    0
    jr         $ra
     nop
endlabel ExitCriticalSection
