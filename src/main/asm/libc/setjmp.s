/*
 * s32 setjmp(s32 *env);
 * libc setjmp
 * Hand-written assembly in the original build (restored source, see PLAN Phase 4b).
 */

glabel setjmp
    sw         $ra, 0x0($a0)
    sw         $gp, 0x2C($a0)
    sw         $sp, 0x4($a0)
    sw         $fp, 0x8($a0)
    sw         $s0, 0xC($a0)
    sw         $s1, 0x10($a0)
    sw         $s2, 0x14($a0)
    sw         $s3, 0x18($a0)
    sw         $s4, 0x1C($a0)
    sw         $s5, 0x20($a0)
    sw         $s6, 0x24($a0)
    sw         $s7, 0x28($a0)
    addu       $v0, $zero, $zero
    jr         $ra
     nop
endlabel setjmp
