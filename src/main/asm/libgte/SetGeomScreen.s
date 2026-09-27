/*
 * SetGeomScreen()
 * Hand-written assembly in the original build (restored source, see PLAN Phase 4b).
 */

glabel SetGeomScreen
    ctc2       $a0, $26
    jr         $ra
     nop
endlabel SetGeomScreen

    # alignment padding up to the next function
    nop
