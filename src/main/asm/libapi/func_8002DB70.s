/*
 * func_8002DB70()
 * exception entry register save
 * Hand-written assembly in the original build (restored source, see PLAN Phase 4b).
 */

glabel func_8002DB70
    sw         $at, 0x4($k0)
    sw         $v0, 0x8($k0)
    sw         $v1, 0xC($k0)
    sw         $ra, 0x7C($k0)
    mfc0       $v1, $14
    nop
     alabel     D_8002DB88
    sw         $at, 0x4($k0)
    sw         $v0, 0x8($k0)
    mfc0       $v0, $13
    sw         $v1, 0xC($k0)
    mfc0       $v1, $14
    sw         $ra, 0x7C($k0)
endlabel func_8002DB70

    # alignment padding up to the next function
    alabel D_8002DBA0
    nop
