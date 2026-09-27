/*
 * void HookEntryInt(s32 *env);
 * Hand-written assembly in the original build (restored source, see PLAN Phase 4b).
 */

glabel HookEntryInt
    addiu      $t2, $zero, 0xB0
    jr         $t2
     addiu      $t1, $zero, 0x19         # B0(0x19)
endlabel HookEntryInt

    # alignment padding up to the next function
    nop
