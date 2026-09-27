/*
 * void ResetEntryInt();
 * Hand-written assembly in the original build (restored source, see PLAN Phase 4b).
 */

glabel ResetEntryInt
    addiu      $t2, $zero, 0xB0
    jr         $t2
     addiu      $t1, $zero, 0x18         # B0(0x18)
endlabel ResetEntryInt

    # alignment padding up to the next function
    nop
