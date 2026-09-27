/*
 * void SysEnqIntRP(s32, u8 *);
 * Hand-written assembly in the original build (restored source, see PLAN Phase 4b).
 */

glabel SysEnqIntRP
    addiu      $t2, $zero, 0xC0
    jr         $t2
     addiu      $t1, $zero, 0x2          # C0(0x02)
endlabel SysEnqIntRP

    # alignment padding up to the next function
    nop
