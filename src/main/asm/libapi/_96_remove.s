/*
 * void _96_remove(void);
 * Hand-written assembly in the original build (restored source, see PLAN Phase 4b).
 */

glabel _96_remove
    addiu      $t2, $zero, 0xA0
    jr         $t2
     addiu      $t1, $zero, 0x72         # A0(0x72)
endlabel _96_remove

    # alignment padding up to the next function
    nop
    nop
    nop
