/*
 * void ReturnFromException(void);
 * Hand-written assembly in the original build (restored source, see PLAN Phase 4b).
 */

glabel ReturnFromException
    addiu      $t2, $zero, 0xB0
    jr         $t2
     addiu      $t1, $zero, 0x17         # B0(0x17)
endlabel ReturnFromException

    # alignment padding up to the next function
    nop
