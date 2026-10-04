nonmatching Stg10_StrNextVlc, 0x88

glabel Stg10_StrNextVlc
    /* DB0 80064110 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* DB4 80064114 1800B2AF */  sw         $s2, 0x18($sp)
    /* DB8 80064118 21908000 */  addu       $s2, $a0, $zero
    /* DBC 8006411C 1400B1AF */  sw         $s1, 0x14($sp)
    /* DC0 80064120 D0071124 */  addiu      $s1, $zero, 0x7D0
    /* DC4 80064124 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* DC8 80064128 1000B0AF */  sw         $s0, 0x10($sp)
  .L8006412C:
    /* DCC 8006412C 0390010C */  jal        Stg10_StrNext
    /* DD0 80064130 21204002 */   addu      $a0, $s2, $zero
    /* DD4 80064134 21804000 */  addu       $s0, $v0, $zero
    /* DD8 80064138 0E000012 */  beqz       $s0, .L80064174
    /* DDC 8006413C 0680033C */   lui       $v1, %hi(Stg10_VlcTable)
    /* DE0 80064140 0800428E */  lw         $v0, 0x8($s2)
    /* DE4 80064144 4062668C */  lw         $a2, %lo(Stg10_VlcTable)($v1)
    /* DE8 80064148 0100422C */  sltiu      $v0, $v0, 0x1
    /* DEC 8006414C 080042AE */  sw         $v0, 0x8($s2)
    /* DF0 80064150 80100200 */  sll        $v0, $v0, 2
    /* DF4 80064154 21104202 */  addu       $v0, $s2, $v0
    /* DF8 80064158 0000458C */  lw         $a1, 0x0($v0)
    /* DFC 8006415C 6093010C */  jal        DecDCTvlc2
    /* E00 80064160 21200002 */   addu      $a0, $s0, $zero
    /* E04 80064164 3DB8000C */  jal        StFreeRing
    /* E08 80064168 21200002 */   addu      $a0, $s0, $zero
    /* E0C 8006416C 60900108 */  j          .L80064180
    /* E10 80064170 21100000 */   addu      $v0, $zero, $zero
  .L80064174:
    /* E14 80064174 FFFF3126 */  addiu      $s1, $s1, -0x1
    /* E18 80064178 ECFF2016 */  bnez       $s1, .L8006412C
    /* E1C 8006417C FFFF0224 */   addiu     $v0, $zero, -0x1
  .L80064180:
    /* E20 80064180 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* E24 80064184 1800B28F */  lw         $s2, 0x18($sp)
    /* E28 80064188 1400B18F */  lw         $s1, 0x14($sp)
    /* E2C 8006418C 1000B08F */  lw         $s0, 0x10($sp)
    /* E30 80064190 0800E003 */  jr         $ra
    /* E34 80064194 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Stg10_StrNextVlc
