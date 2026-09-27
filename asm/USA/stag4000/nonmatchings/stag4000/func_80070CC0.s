nonmatching func_80070CC0, 0xB4

glabel func_80070CC0
    /* D960 80070CC0 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* D964 80070CC4 1400B1AF */  sw         $s1, 0x14($sp)
    /* D968 80070CC8 21888000 */  addu       $s1, $a0, $zero
    /* D96C 80070CCC 1800BFAF */  sw         $ra, 0x18($sp)
    /* D970 80070CD0 828E000C */  jal        Cd_GetFileOrNull
    /* D974 80070CD4 1000B0AF */   sw        $s0, 0x10($sp)
    /* D978 80070CD8 21804000 */  addu       $s0, $v0, $zero
    /* D97C 80070CDC B8C3010C */  jal        func_80070EE0
    /* D980 80070CE0 21200002 */   addu      $a0, $s0, $zero
    /* D984 80070CE4 0780023C */  lui        $v0, %hi(D_80072B60)
    /* D988 80070CE8 0580033C */  lui        $v1, %hi(D_8005071C)
    /* D98C 80070CEC 602B448C */  lw         $a0, %lo(D_80072B60)($v0)
    /* D990 80070CF0 1C07628C */  lw         $v0, %lo(D_8005071C)($v1)
    /* D994 80070CF4 1C0091AC */  sw         $s1, 0x1C($a0)
    /* D998 80070CF8 0C0090AC */  sw         $s0, 0xC($a0)
    /* D99C 80070CFC 03004290 */  lbu        $v0, 0x3($v0)
    /* D9A0 80070D00 00000000 */  nop
    /* D9A4 80070D04 80100200 */  sll        $v0, $v0, 2
    /* D9A8 80070D08 21105000 */  addu       $v0, $v0, $s0
    /* D9AC 80070D0C 0000428C */  lw         $v0, 0x0($v0)
    /* D9B0 80070D10 21280002 */  addu       $a1, $s0, $zero
    /* D9B4 80070D14 180080A4 */  sh         $zero, 0x18($a0)
    /* D9B8 80070D18 100082AC */  sw         $v0, 0x10($a0)
    /* D9BC 80070D1C 0000A28C */  lw         $v0, 0x0($a1)
    /* D9C0 80070D20 00000000 */  nop
    /* D9C4 80070D24 0E004010 */  beqz       $v0, .L80070D60
    /* D9C8 80070D28 00000000 */   nop
    /* D9CC 80070D2C 21188000 */  addu       $v1, $a0, $zero
    /* D9D0 80070D30 2120A000 */  addu       $a0, $a1, $zero
  .L80070D34:
    /* D9D4 80070D34 18006294 */  lhu        $v0, 0x18($v1)
    /* D9D8 80070D38 00000000 */  nop
    /* D9DC 80070D3C 01004224 */  addiu      $v0, $v0, 0x1
    /* D9E0 80070D40 180062A4 */  sh         $v0, 0x18($v1)
    /* D9E4 80070D44 00140200 */  sll        $v0, $v0, 16
    /* D9E8 80070D48 83130200 */  sra        $v0, $v0, 14
    /* D9EC 80070D4C 21104400 */  addu       $v0, $v0, $a0
    /* D9F0 80070D50 0000428C */  lw         $v0, 0x0($v0)
    /* D9F4 80070D54 00000000 */  nop
    /* D9F8 80070D58 F6FF4014 */  bnez       $v0, .L80070D34
    /* D9FC 80070D5C 00000000 */   nop
  .L80070D60:
    /* DA00 80070D60 1800BF8F */  lw         $ra, 0x18($sp)
    /* DA04 80070D64 1400B18F */  lw         $s1, 0x14($sp)
    /* DA08 80070D68 1000B08F */  lw         $s0, 0x10($sp)
    /* DA0C 80070D6C 0800E003 */  jr         $ra
    /* DA10 80070D70 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80070CC0
