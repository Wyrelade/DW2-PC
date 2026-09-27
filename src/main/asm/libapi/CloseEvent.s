/*
 * CloseEvent(D_80063060);
 * Hand-written assembly in the original build (restored source, see PLAN Phase 4b).
 */

glabel CloseEvent
    addiu      $t2, $zero, 0xB0
    jr         $t2
     addiu      $t1, $zero, 0x9          # B0(0x09)
endlabel CloseEvent

    # alignment padding up to the next function
    nop
