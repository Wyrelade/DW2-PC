nonmatching func_8003F46C, 0xAC

glabel func_8003F46C
    /* 2FC6C 8003F46C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2FC70 8003F470 1000BFAF */  sw         $ra, 0x10($sp)
    /* 2FC74 8003F474 C3FE000C */  jal        Card_IsTaskStackEmpty
    /* 2FC78 8003F478 00000000 */   nop
    /* 2FC7C 8003F47C 18004014 */  bnez       $v0, .L8003F4E0
    /* 2FC80 8003F480 00000000 */   nop
    /* 2FC84 8003F484 A8FE000C */  jal        Card_RunTopTask
    /* 2FC88 8003F488 00000000 */   nop
    /* 2FC8C 8003F48C C3FE000C */  jal        Card_IsTaskStackEmpty
    /* 2FC90 8003F490 00000000 */   nop
    /* 2FC94 8003F494 12004010 */  beqz       $v0, .L8003F4E0
    /* 2FC98 8003F498 01000224 */   addiu     $v0, $zero, 0x1
    /* 2FC9C 8003F49C 0680033C */  lui        $v1, %hi(D_80062F80)
    /* 2FCA0 8003F4A0 802F6324 */  addiu      $v1, $v1, %lo(D_80062F80)
    /* 2FCA4 8003F4A4 080062AC */  sw         $v0, 0x8($v1)
    /* 2FCA8 8003F4A8 0000628C */  lw         $v0, 0x0($v1)
    /* 2FCAC 8003F4AC 0680053C */  lui        $a1, %hi(D_80062F70)
    /* 2FCB0 8003F4B0 702FA524 */  addiu      $a1, $a1, %lo(D_80062F70)
    /* 2FCB4 8003F4B4 0000A2AC */  sw         $v0, 0x0($a1)
    /* 2FCB8 8003F4B8 0400628C */  lw         $v0, 0x4($v1)
    /* 2FCBC 8003F4BC 4400668C */  lw         $a2, 0x44($v1)
    /* 2FCC0 8003F4C0 0400A2AC */  sw         $v0, 0x4($a1)
    /* 2FCC4 8003F4C4 000060AC */  sw         $zero, 0x0($v1)
    /* 2FCC8 8003F4C8 0500C010 */  beqz       $a2, .L8003F4E0
    /* 2FCCC 8003F4CC 040060AC */   sw        $zero, 0x4($v1)
    /* 2FCD0 8003F4D0 0000A48C */  lw         $a0, 0x0($a1)
    /* 2FCD4 8003F4D4 0400A58C */  lw         $a1, 0x4($a1)
    /* 2FCD8 8003F4D8 09F8C000 */  jalr       $a2
    /* 2FCDC 8003F4DC 00000000 */   nop
  .L8003F4E0:
    /* 2FCE0 8003F4E0 0680023C */  lui        $v0, %hi(D_80062F80)
    /* 2FCE4 8003F4E4 802F4224 */  addiu      $v0, $v0, %lo(D_80062F80)
    /* 2FCE8 8003F4E8 5000438C */  lw         $v1, 0x50($v0)
    /* 2FCEC 8003F4EC 00000000 */  nop
    /* 2FCF0 8003F4F0 01006324 */  addiu      $v1, $v1, 0x1
    /* 2FCF4 8003F4F4 500043AC */  sw         $v1, 0x50($v0)
    /* 2FCF8 8003F4F8 5400438C */  lw         $v1, 0x54($v0)
    /* 2FCFC 8003F4FC 00000000 */  nop
    /* 2FD00 8003F500 01006324 */  addiu      $v1, $v1, 0x1
    /* 2FD04 8003F504 540043AC */  sw         $v1, 0x54($v0)
    /* 2FD08 8003F508 1000BF8F */  lw         $ra, 0x10($sp)
    /* 2FD0C 8003F50C 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 2FD10 8003F510 0800E003 */  jr         $ra
    /* 2FD14 8003F514 00000000 */   nop
endlabel func_8003F46C
