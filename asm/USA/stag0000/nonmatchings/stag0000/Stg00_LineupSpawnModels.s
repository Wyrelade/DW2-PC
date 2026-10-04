nonmatching Stg00_LineupSpawnModels, 0xDC

glabel Stg00_LineupSpawnModels
    /* 2DD0 80066130 C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* 2DD4 80066134 2800B0AF */  sw         $s0, 0x28($sp)
    /* 2DD8 80066138 21800000 */  addu       $s0, $zero, $zero
    /* 2DDC 8006613C 0780023C */  lui        $v0, %hi(Stg00_LineupLayouts)
    /* 2DE0 80066140 3400B3AF */  sw         $s3, 0x34($sp)
    /* 2DE4 80066144 188E5324 */  addiu      $s3, $v0, %lo(Stg00_LineupLayouts)
    /* 2DE8 80066148 3800BFAF */  sw         $ra, 0x38($sp)
    /* 2DEC 8006614C 3000B2AF */  sw         $s2, 0x30($sp)
    /* 2DF0 80066150 2C00B1AF */  sw         $s1, 0x2C($sp)
    /* 2DF4 80066154 2C00928C */  lw         $s2, 0x2C($a0)
    /* 2DF8 80066158 3400918C */  lw         $s1, 0x34($a0)
  .L8006615C:
    /* 2DFC 8006615C B543000C */  jal        Task_Destroy
    /* 2E00 80066160 21202002 */   addu      $a0, $s1, $zero
    /* 2E04 80066164 80301000 */  sll        $a2, $s0, 2
    /* 2E08 80066168 5406428E */  lw         $v0, 0x654($s2)
    /* 2E0C 8006616C 05010424 */  addiu      $a0, $zero, 0x105
    /* 2E10 80066170 21100202 */  addu       $v0, $s0, $v0
    /* 2E14 80066174 80100200 */  sll        $v0, $v0, 2
    /* 2E18 80066178 21104202 */  addu       $v0, $s2, $v0
    /* 2E1C 8006617C 3003438C */  lw         $v1, 0x330($v0)
    /* 2E20 80066180 00040224 */  addiu      $v0, $zero, 0x400
    /* 2E24 80066184 2000A2AF */  sw         $v0, 0x20($sp)
    /* 2E28 80066188 1000A3AF */  sw         $v1, 0x10($sp)
    /* 2E2C 8006618C 5806438E */  lw         $v1, 0x658($s2)
    /* 2E30 80066190 21282002 */  addu       $a1, $s1, $zero
    /* 2E34 80066194 C0100300 */  sll        $v0, $v1, 3
    /* 2E38 80066198 21104300 */  addu       $v0, $v0, $v1
    /* 2E3C 8006619C 80100200 */  sll        $v0, $v0, 2
    /* 2E40 800661A0 2110C200 */  addu       $v0, $a2, $v0
    /* 2E44 800661A4 21105300 */  addu       $v0, $v0, $s3
    /* 2E48 800661A8 00004284 */  lh         $v0, 0x0($v0)
    /* 2E4C 800661AC 04003126 */  addiu      $s1, $s1, 0x4
    /* 2E50 800661B0 1800A0AF */  sw         $zero, 0x18($sp)
    /* 2E54 800661B4 1400A2AF */  sw         $v0, 0x14($sp)
    /* 2E58 800661B8 5806438E */  lw         $v1, 0x658($s2)
    /* 2E5C 800661BC 01001026 */  addiu      $s0, $s0, 0x1
    /* 2E60 800661C0 C0100300 */  sll        $v0, $v1, 3
    /* 2E64 800661C4 21104300 */  addu       $v0, $v0, $v1
    /* 2E68 800661C8 80100200 */  sll        $v0, $v0, 2
    /* 2E6C 800661CC 2130C200 */  addu       $a2, $a2, $v0
    /* 2E70 800661D0 2130D300 */  addu       $a2, $a2, $s3
    /* 2E74 800661D4 0200C284 */  lh         $v0, 0x2($a2)
    /* 2E78 800661D8 1000A627 */  addiu      $a2, $sp, 0x10
    /* 2E7C 800661DC 1F44000C */  jal        Task_Create
    /* 2E80 800661E0 1C00A2AF */   sw        $v0, 0x1C($sp)
    /* 2E84 800661E4 0900022A */  slti       $v0, $s0, 0x9
    /* 2E88 800661E8 DCFF4014 */  bnez       $v0, .L8006615C
    /* 2E8C 800661EC 00000000 */   nop
    /* 2E90 800661F0 3800BF8F */  lw         $ra, 0x38($sp)
    /* 2E94 800661F4 3400B38F */  lw         $s3, 0x34($sp)
    /* 2E98 800661F8 3000B28F */  lw         $s2, 0x30($sp)
    /* 2E9C 800661FC 2C00B18F */  lw         $s1, 0x2C($sp)
    /* 2EA0 80066200 2800B08F */  lw         $s0, 0x28($sp)
    /* 2EA4 80066204 0800E003 */  jr         $ra
    /* 2EA8 80066208 4000BD27 */   addiu     $sp, $sp, 0x40
endlabel Stg00_LineupSpawnModels
