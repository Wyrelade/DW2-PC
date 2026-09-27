/*
 * s32 StartCARD(void);
 * Hand-written assembly in the original build (restored source, see PLAN Phase 4b).
 */

glabel StartCARD
    addiu      $t2, $zero, 0xB0
    jr         $t2
     addiu      $t1, $zero, 0x4B         # B0(0x4B)
endlabel StartCARD

    # alignment padding up to the next function
    nop
