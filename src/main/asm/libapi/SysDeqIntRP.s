/*
 * void SysDeqIntRP(s32, u8 *);
 * Hand-written assembly in the original build (restored source, see PLAN Phase 4b).
 */

glabel SysDeqIntRP
    addiu      $t2, $zero, 0xC0
    jr         $t2
     addiu      $t1, $zero, 0x3          # C0(0x03)
endlabel SysDeqIntRP

    # alignment padding up to the next function
    nop
