nonmatching func_8001E7E4, 0xEC

glabel func_8001E7E4
    /* EFE4 8001E7E4 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* EFE8 8001E7E8 1000B0AF */  sw         $s0, 0x10($sp)
    /* EFEC 8001E7EC 21808000 */  addu       $s0, $a0, $zero
    /* EFF0 8001E7F0 1800B2AF */  sw         $s2, 0x18($sp)
    /* EFF4 8001E7F4 2190A000 */  addu       $s2, $a1, $zero
    /* EFF8 8001E7F8 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* EFFC 8001E7FC 9F79000C */  jal        Digi_GetDataFileId
    /* F000 8001E800 1400B1AF */   sw        $s1, 0x14($sp)
    /* F004 8001E804 00140200 */  sll        $v0, $v0, 16
    /* F008 8001E808 688E000C */  jal        Cd_GetFileEntry
    /* F00C 8001E80C 01004434 */   ori       $a0, $v0, 0x1
    /* F010 8001E810 21200002 */  addu       $a0, $s0, $zero
    /* F014 8001E814 AA79000C */  jal        Digi_FindDataById
    /* F018 8001E818 21884000 */   addu      $s1, $v0, $zero
    /* F01C 8001E81C 22004384 */  lh         $v1, 0x22($v0)
    /* F020 8001E820 21200002 */  addu       $a0, $s0, $zero
    /* F024 8001E824 40100300 */  sll        $v0, $v1, 1
    /* F028 8001E828 21104300 */  addu       $v0, $v0, $v1
    /* F02C 8001E82C 40100200 */  sll        $v0, $v0, 1
    /* F030 8001E830 21105100 */  addu       $v0, $v0, $s1
    /* F034 8001E834 03004688 */  lwl        $a2, 0x3($v0)
    /* F038 8001E838 00004698 */  lwr        $a2, 0x0($v0)
    /* F03C 8001E83C 04004784 */  lh         $a3, 0x4($v0)
    /* F040 8001E840 030046AA */  swl        $a2, 0x3($s2)
    /* F044 8001E844 000046BA */  swr        $a2, 0x0($s2)
    /* F048 8001E848 AA79000C */  jal        Digi_FindDataById
    /* F04C 8001E84C 040047A6 */   sh        $a3, 0x4($s2)
    /* F050 8001E850 24004384 */  lh         $v1, 0x24($v0)
    /* F054 8001E854 00000000 */  nop
    /* F058 8001E858 40100300 */  sll        $v0, $v1, 1
    /* F05C 8001E85C 21104300 */  addu       $v0, $v0, $v1
    /* F060 8001E860 40100200 */  sll        $v0, $v0, 1
    /* F064 8001E864 21105100 */  addu       $v0, $v0, $s1
    /* F068 8001E868 03004688 */  lwl        $a2, 0x3($v0)
    /* F06C 8001E86C 00004698 */  lwr        $a2, 0x0($v0)
    /* F070 8001E870 04004784 */  lh         $a3, 0x4($v0)
    /* F074 8001E874 090046AA */  swl        $a2, 0x9($s2)
    /* F078 8001E878 060046BA */  swr        $a2, 0x6($s2)
    /* F07C 8001E87C 0A0047A6 */  sh         $a3, 0xA($s2)
    /* F080 8001E880 AA79000C */  jal        Digi_FindDataById
    /* F084 8001E884 21200002 */   addu      $a0, $s0, $zero
    /* F088 8001E888 26004384 */  lh         $v1, 0x26($v0)
    /* F08C 8001E88C 00000000 */  nop
    /* F090 8001E890 40100300 */  sll        $v0, $v1, 1
    /* F094 8001E894 21104300 */  addu       $v0, $v0, $v1
    /* F098 8001E898 40100200 */  sll        $v0, $v0, 1
    /* F09C 8001E89C 21105100 */  addu       $v0, $v0, $s1
    /* F0A0 8001E8A0 03004688 */  lwl        $a2, 0x3($v0)
    /* F0A4 8001E8A4 00004698 */  lwr        $a2, 0x0($v0)
    /* F0A8 8001E8A8 04004784 */  lh         $a3, 0x4($v0)
    /* F0AC 8001E8AC 0F0046AA */  swl        $a2, 0xF($s2)
    /* F0B0 8001E8B0 0C0046BA */  swr        $a2, 0xC($s2)
    /* F0B4 8001E8B4 100047A6 */  sh         $a3, 0x10($s2)
    /* F0B8 8001E8B8 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* F0BC 8001E8BC 1800B28F */  lw         $s2, 0x18($sp)
    /* F0C0 8001E8C0 1400B18F */  lw         $s1, 0x14($sp)
    /* F0C4 8001E8C4 1000B08F */  lw         $s0, 0x10($sp)
    /* F0C8 8001E8C8 0800E003 */  jr         $ra
    /* F0CC 8001E8CC 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8001E7E4
