nonmatching Stg35_HudSyncHp, 0x64

glabel Stg35_HudSyncHp
    /* 5898 80068BF8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 589C 80068BFC 1000BFAF */  sw         $ra, 0x10($sp)
    /* 58A0 80068C00 08070424 */  addiu      $a0, $zero, 0x708
    /* 58A4 80068C04 FFFF0524 */  addiu      $a1, $zero, -0x1
    /* 58A8 80068C08 4445000C */  jal        Task_FindFirst
    /* 58AC 80068C0C 2130A000 */   addu      $a2, $a1, $zero
    /* 58B0 80068C10 21184000 */  addu       $v1, $v0, $zero
    /* 58B4 80068C14 0D006010 */  beqz       $v1, .L80068C4C
    /* 58B8 80068C18 0780023C */   lui       $v0, %hi(Stg35_Battle)
    /* 58BC 80068C1C 21280000 */  addu       $a1, $zero, $zero
    /* 58C0 80068C20 88AA4424 */  addiu      $a0, $v0, %lo(Stg35_Battle)
    /* 58C4 80068C24 2C00638C */  lw         $v1, 0x2C($v1)
  .L80068C28:
    /* 58C8 80068C28 26008284 */  lh         $v0, 0x26($a0)
    /* 58CC 80068C2C 0100A524 */  addiu      $a1, $a1, 0x1
    /* 58D0 80068C30 800062AC */  sw         $v0, 0x80($v1)
    /* 58D4 80068C34 24008284 */  lh         $v0, 0x24($a0)
    /* 58D8 80068C38 5C008424 */  addiu      $a0, $a0, 0x5C
    /* 58DC 80068C3C 880062AC */  sw         $v0, 0x88($v1)
    /* 58E0 80068C40 0600A228 */  slti       $v0, $a1, 0x6
    /* 58E4 80068C44 F8FF4014 */  bnez       $v0, .L80068C28
    /* 58E8 80068C48 0C006324 */   addiu     $v1, $v1, 0xC
  .L80068C4C:
    /* 58EC 80068C4C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 58F0 80068C50 00000000 */  nop
    /* 58F4 80068C54 0800E003 */  jr         $ra
    /* 58F8 80068C58 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Stg35_HudSyncHp
