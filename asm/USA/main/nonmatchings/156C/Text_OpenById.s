nonmatching Text_OpenById, 0x70

glabel Text_OpenById
    /* C7C8 8001BFC8 B0FFBD27 */  addiu      $sp, $sp, -0x50
    /* C7CC 8001BFCC 4400B1AF */  sw         $s1, 0x44($sp)
    /* C7D0 8001BFD0 21888000 */  addu       $s1, $a0, $zero
    /* C7D4 8001BFD4 FD01043C */  lui        $a0, (0x1FD0000 >> 16)
    /* C7D8 8001BFD8 2120A400 */  addu       $a0, $a1, $a0
    /* C7DC 8001BFDC 4000B0AF */  sw         $s0, 0x40($sp)
    /* C7E0 8001BFE0 2180C000 */  addu       $s0, $a2, $zero
    /* C7E4 8001BFE4 4800BFAF */  sw         $ra, 0x48($sp)
    /* C7E8 8001BFE8 688E000C */  jal        Cd_GetFileEntry
    /* C7EC 8001BFEC 5C00A7AF */   sw        $a3, 0x5C($sp)
    /* C7F0 8001BFF0 2400A2AF */  sw         $v0, 0x24($sp)
    /* C7F4 8001BFF4 1000A0AF */  sw         $zero, 0x10($sp)
    /* C7F8 8001BFF8 1400B0AF */  sw         $s0, 0x14($sp)
    /* C7FC 8001BFFC 5C00A297 */  lhu        $v0, 0x5C($sp)
    /* C800 8001C000 21202002 */  addu       $a0, $s1, $zero
    /* C804 8001C004 1800A2A7 */  sh         $v0, 0x18($sp)
    /* C808 8001C008 5E00A297 */  lhu        $v0, 0x5E($sp)
    /* C80C 8001C00C 1000A527 */  addiu      $a1, $sp, 0x10
    /* C810 8001C010 1C00A0AF */  sw         $zero, 0x1C($sp)
    /* C814 8001C014 2000A0AF */  sw         $zero, 0x20($sp)
    /* C818 8001C018 2800A0AF */  sw         $zero, 0x28($sp)
    /* C81C 8001C01C 096F000C */  jal        Text_Open
    /* C820 8001C020 1A00A2A7 */   sh        $v0, 0x1A($sp)
    /* C824 8001C024 4800BF8F */  lw         $ra, 0x48($sp)
    /* C828 8001C028 4400B18F */  lw         $s1, 0x44($sp)
    /* C82C 8001C02C 4000B08F */  lw         $s0, 0x40($sp)
    /* C830 8001C030 0800E003 */  jr         $ra
    /* C834 8001C034 5000BD27 */   addiu     $sp, $sp, 0x50
endlabel Text_OpenById
