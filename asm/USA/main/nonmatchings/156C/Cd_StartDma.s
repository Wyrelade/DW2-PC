nonmatching Cd_StartDma, 0x1A8

glabel Cd_StartDma
    /* 1F40C 8002EC0C D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 1F410 8002EC10 1800B0AF */  sw         $s0, 0x18($sp)
    /* 1F414 8002EC14 21808000 */  addu       $s0, $a0, $zero
    /* 1F418 8002EC18 2000B2AF */  sw         $s2, 0x20($sp)
    /* 1F41C 8002EC1C 2190A000 */  addu       $s2, $a1, $zero
    /* 1F420 8002EC20 2400B3AF */  sw         $s3, 0x24($sp)
    /* 1F424 8002EC24 2198C000 */  addu       $s3, $a2, $zero
    /* 1F428 8002EC28 2800B4AF */  sw         $s4, 0x28($sp)
    /* 1F42C 8002EC2C 21A0E000 */  addu       $s4, $a3, $zero
    /* 1F430 8002EC30 21200000 */  addu       $a0, $zero, $zero
    /* 1F434 8002EC34 00291000 */  sll        $a1, $s0, 4
    /* 1F438 8002EC38 0001033C */  lui        $v1, (0x1000000 >> 16)
    /* 1F43C 8002EC3C 2C00BFAF */  sw         $ra, 0x2C($sp)
    /* 1F440 8002EC40 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 1F444 8002EC44 801F023C */  lui        $v0, (0x1F801088 >> 16)
    /* 1F448 8002EC48 21104500 */  addu       $v0, $v0, $a1
    /* 1F44C 8002EC4C 8810428C */  lw         $v0, (0x1F801088 & 0xFFFF)($v0)
    /* 1F450 8002EC50 4400B193 */  lbu        $s1, 0x44($sp)
    /* 1F454 8002EC54 24104300 */  and        $v0, $v0, $v1
    /* 1F458 8002EC58 0A004010 */  beqz       $v0, .L8002EC84
    /* 1F45C 8002EC5C 0100063C */   lui       $a2, (0x10000 >> 16)
  .L8002EC60:
    /* 1F460 8002EC60 12008610 */  beq        $a0, $a2, .L8002ECAC
    /* 1F464 8002EC64 00000000 */   nop
    /* 1F468 8002EC68 801F023C */  lui        $v0, (0x1F801088 >> 16)
    /* 1F46C 8002EC6C 21104500 */  addu       $v0, $v0, $a1
    /* 1F470 8002EC70 8810428C */  lw         $v0, (0x1F801088 & 0xFFFF)($v0)
    /* 1F474 8002EC74 00000000 */  nop
    /* 1F478 8002EC78 24104300 */  and        $v0, $v0, $v1
    /* 1F47C 8002EC7C F8FF4014 */  bnez       $v0, .L8002EC60
    /* 1F480 8002EC80 01008424 */   addiu     $a0, $a0, 0x1
  .L8002EC84:
    /* 1F484 8002EC84 01000224 */  addiu      $v0, $zero, 0x1
  .L8002EC88:
    /* 1F488 8002EC88 10002216 */  bne        $s1, $v0, .L8002ECCC
    /* 1F48C 8002EC8C 00000000 */   nop
    /* 1F490 8002EC90 0580033C */  lui        $v1, %hi(D_8004E68C)
    /* 1F494 8002EC94 8CE6638C */  lw         $v1, %lo(D_8004E68C)($v1)
    /* 1F498 8002EC98 00000000 */  nop
    /* 1F49C 8002EC9C 02006490 */  lbu        $a0, 0x2($v1)
    /* 1F4A0 8002ECA0 04100202 */  sllv       $v0, $v0, $s0
    /* 1F4A4 8002ECA4 39BB0008 */  j          .L8002ECE4
    /* 1F4A8 8002ECA8 25108200 */   or        $v0, $a0, $v0
  .L8002ECAC:
    /* 1F4AC 8002ECAC 801F013C */  lui        $at, (0x1F801088 >> 16)
    /* 1F4B0 8002ECB0 21082500 */  addu       $at, $at, $a1
    /* 1F4B4 8002ECB4 8810258C */  lw         $a1, (0x1F801088 & 0xFFFF)($at)
    /* 1F4B8 8002ECB8 0180043C */  lui        $a0, %hi(D_800106F4)
    /* 1F4BC 8002ECBC 05A8000C */  jal        printf
    /* 1F4C0 8002ECC0 F4068424 */   addiu     $a0, $a0, %lo(D_800106F4)
    /* 1F4C4 8002ECC4 22BB0008 */  j          .L8002EC88
    /* 1F4C8 8002ECC8 01000224 */   addiu     $v0, $zero, 0x1
  .L8002ECCC:
    /* 1F4CC 8002ECCC 0580033C */  lui        $v1, %hi(D_8004E68C)
    /* 1F4D0 8002ECD0 8CE6638C */  lw         $v1, %lo(D_8004E68C)($v1)
    /* 1F4D4 8002ECD4 04100202 */  sllv       $v0, $v0, $s0
    /* 1F4D8 8002ECD8 02006490 */  lbu        $a0, 0x2($v1)
    /* 1F4DC 8002ECDC 27100200 */  nor        $v0, $zero, $v0
    /* 1F4E0 8002ECE0 24108200 */  and        $v0, $a0, $v0
  .L8002ECE4:
    /* 1F4E4 8002ECE4 020062A0 */  sb         $v0, 0x2($v1)
    /* 1F4E8 8002ECE8 0580023C */  lui        $v0, %hi(D_8004E68C)
    /* 1F4EC 8002ECEC 8CE6428C */  lw         $v0, %lo(D_8004E68C)($v0)
    /* 1F4F0 8002ECF0 00000000 */  nop
    /* 1F4F4 8002ECF4 0000428C */  lw         $v0, 0x0($v0)
    /* 1F4F8 8002ECF8 00000000 */  nop
    /* 1F4FC 8002ECFC 1000A2AF */  sw         $v0, 0x10($sp)
    /* 1F500 8002ED00 80301000 */  sll        $a2, $s0, 2
    /* 1F504 8002ED04 0300C624 */  addiu      $a2, $a2, 0x3
    /* 1F508 8002ED08 01000324 */  addiu      $v1, $zero, 0x1
    /* 1F50C 8002ED0C 0418C300 */  sllv       $v1, $v1, $a2
    /* 1F510 8002ED10 801F053C */  lui        $a1, (0x1F801080 >> 16)
    /* 1F514 8002ED14 8010A534 */  ori        $a1, $a1, (0x1F801080 & 0xFFFF)
    /* 1F518 8002ED18 00111000 */  sll        $v0, $s0, 4
    /* 1F51C 8002ED1C 21284500 */  addu       $a1, $v0, $a1
    /* 1F520 8002ED20 0580043C */  lui        $a0, %hi(D_8004E688)
    /* 1F524 8002ED24 88E6848C */  lw         $a0, %lo(D_8004E688)($a0)
    /* 1F528 8002ED28 00141300 */  sll        $v0, $s3, 16
    /* 1F52C 8002ED2C 0000868C */  lw         $a2, 0x0($a0)
    /* 1F530 8002ED30 25105400 */  or         $v0, $v0, $s4
    /* 1F534 8002ED34 2530C300 */  or         $a2, $a2, $v1
    /* 1F538 8002ED38 000086AC */  sw         $a2, 0x0($a0)
    /* 1F53C 8002ED3C 0000B2AC */  sw         $s2, 0x0($a1)
    /* 1F540 8002ED40 0400A524 */  addiu      $a1, $a1, 0x4
    /* 1F544 8002ED44 0000A2AC */  sw         $v0, 0x0($a1)
    /* 1F548 8002ED48 0580033C */  lui        $v1, %hi(D_8004E670)
    /* 1F54C 8002ED4C 70E6638C */  lw         $v1, %lo(D_8004E670)($v1)
    /* 1F550 8002ED50 00000000 */  nop
    /* 1F554 8002ED54 00006290 */  lbu        $v0, 0x0($v1)
    /* 1F558 8002ED58 00000000 */  nop
    /* 1F55C 8002ED5C 40004230 */  andi       $v0, $v0, 0x40
    /* 1F560 8002ED60 06004014 */  bnez       $v0, .L8002ED7C
    /* 1F564 8002ED64 0400A524 */   addiu     $a1, $a1, 0x4
  .L8002ED68:
    /* 1F568 8002ED68 00006290 */  lbu        $v0, 0x0($v1)
    /* 1F56C 8002ED6C 00000000 */  nop
    /* 1F570 8002ED70 40004230 */  andi       $v0, $v0, 0x40
    /* 1F574 8002ED74 FCFF4010 */  beqz       $v0, .L8002ED68
    /* 1F578 8002ED78 00000000 */   nop
  .L8002ED7C:
    /* 1F57C 8002ED7C 4000A28F */  lw         $v0, 0x40($sp)
    /* 1F580 8002ED80 00000000 */  nop
    /* 1F584 8002ED84 0000A2AC */  sw         $v0, 0x0($a1)
    /* 1F588 8002ED88 0000A28C */  lw         $v0, 0x0($a1)
    /* 1F58C 8002ED8C 00000000 */  nop
    /* 1F590 8002ED90 1000A2AF */  sw         $v0, 0x10($sp)
    /* 1F594 8002ED94 2C00BF8F */  lw         $ra, 0x2C($sp)
    /* 1F598 8002ED98 2800B48F */  lw         $s4, 0x28($sp)
    /* 1F59C 8002ED9C 2400B38F */  lw         $s3, 0x24($sp)
    /* 1F5A0 8002EDA0 2000B28F */  lw         $s2, 0x20($sp)
    /* 1F5A4 8002EDA4 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 1F5A8 8002EDA8 1800B08F */  lw         $s0, 0x18($sp)
    /* 1F5AC 8002EDAC 0800E003 */  jr         $ra
    /* 1F5B0 8002EDB0 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel Cd_StartDma
