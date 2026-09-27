/*
 * read()
 * Hand-written assembly in the original build (restored source, see PLAN Phase 4b).
 */

glabel read
    addiu      $t2, $zero, 0xB0
    jr         $t2
     addiu      $t1, $zero, 0x34         # B0(0x34)
endlabel read

    # alignment padding up to the next function
    nop
