/*
 * FlushCache()
 * Hand-written assembly in the original build (restored source, see PLAN Phase 4b).
 */

glabel FlushCache
    addiu      $t2, $zero, 0xA0
    jr         $t2
     addiu      $t1, $zero, 0x44         # A0(0x44)
endlabel FlushCache

    # alignment padding up to the next function
    nop
