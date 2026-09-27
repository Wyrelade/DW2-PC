nonmatching Item_Use, 0x104

glabel Item_Use
    /* 2F78 80012778 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 2F7C 8001277C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 2F80 80012780 21888000 */  addu       $s1, $a0, $zero
    /* 2F84 80012784 2000B4AF */  sw         $s4, 0x20($sp)
    /* 2F88 80012788 21A0A000 */  addu       $s4, $a1, $zero
    /* 2F8C 8001278C 1800B2AF */  sw         $s2, 0x18($sp)
    /* 2F90 80012790 2190C000 */  addu       $s2, $a2, $zero
    /* 2F94 80012794 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 2F98 80012798 2198E000 */  addu       $s3, $a3, $zero
    /* 2F9C 8001279C 2400BFAF */  sw         $ra, 0x24($sp)
    /* 2FA0 800127A0 D747000C */  jal        Item_GetEffectRec
    /* 2FA4 800127A4 1000B0AF */   sw        $s0, 0x10($sp)
    /* 2FA8 800127A8 2B004010 */  beqz       $v0, .L80012858
    /* 2FAC 800127AC 21800000 */   addu      $s0, $zero, $zero
    /* 2FB0 800127B0 00004290 */  lbu        $v0, 0x0($v0)
    /* 2FB4 800127B4 00000000 */  nop
    /* 2FB8 800127B8 FFFF4324 */  addiu      $v1, $v0, -0x1
    /* 2FBC 800127BC 0500622C */  sltiu      $v0, $v1, 0x5
    /* 2FC0 800127C0 21004010 */  beqz       $v0, .L80012848
    /* 2FC4 800127C4 0180023C */   lui       $v0, %hi(jtbl_8001006C)
    /* 2FC8 800127C8 6C004224 */  addiu      $v0, $v0, %lo(jtbl_8001006C)
    /* 2FCC 800127CC 80180300 */  sll        $v1, $v1, 2
    /* 2FD0 800127D0 21186200 */  addu       $v1, $v1, $v0
    /* 2FD4 800127D4 0000628C */  lw         $v0, 0x0($v1)
    /* 2FD8 800127D8 00000000 */  nop
    /* 2FDC 800127DC 08004000 */  jr         $v0
    /* 2FE0 800127E0 00000000 */   nop
  jlabel .L800127E4
    /* 2FE4 800127E4 21202002 */  addu       $a0, $s1, $zero
    /* 2FE8 800127E8 21288002 */  addu       $a1, $s4, $zero
    /* 2FEC 800127EC 21304002 */  addu       $a2, $s2, $zero
    /* 2FF0 800127F0 1348000C */  jal        func_8001204C
    /* 2FF4 800127F4 21386002 */   addu      $a3, $s3, $zero
    /* 2FF8 800127F8 124A0008 */  j          .L80012848
    /* 2FFC 800127FC 21804000 */   addu      $s0, $v0, $zero
  jlabel .L80012800
    /* 3000 80012800 21202002 */  addu       $a0, $s1, $zero
    /* 3004 80012804 21288002 */  addu       $a1, $s4, $zero
    /* 3008 80012808 21304002 */  addu       $a2, $s2, $zero
    /* 300C 8001280C DB48000C */  jal        Item_ApplyToDigi
    /* 3010 80012810 21386002 */   addu      $a3, $s3, $zero
    /* 3014 80012814 124A0008 */  j          .L80012848
    /* 3018 80012818 21804000 */   addu      $s0, $v0, $zero
  jlabel .L8001281C
    /* 301C 8001281C 21202002 */  addu       $a0, $s1, $zero
    /* 3020 80012820 21288002 */  addu       $a1, $s4, $zero
    /* 3024 80012824 21304002 */  addu       $a2, $s2, $zero
    /* 3028 80012828 2449000C */  jal        Item_UseStatBoost
    /* 302C 8001282C 21386002 */   addu      $a3, $s3, $zero
    /* 3030 80012830 124A0008 */  j          .L80012848
    /* 3034 80012834 21804000 */   addu      $s0, $v0, $zero
  jlabel .L80012838
    /* 3038 80012838 21202002 */  addu       $a0, $s1, $zero
    /* 303C 8001283C 9049000C */  jal        Item_UseRecoverAll
    /* 3040 80012840 21288002 */   addu      $a1, $s4, $zero
    /* 3044 80012844 21804000 */  addu       $s0, $v0, $zero
  .L80012848:
    /* 3048 80012848 04000012 */  beqz       $s0, .L8001285C
    /* 304C 8001284C 21100002 */   addu      $v0, $s0, $zero
    /* 3050 80012850 FC89000C */  jal        Item_RemoveFromBag
    /* 3054 80012854 21208002 */   addu      $a0, $s4, $zero
  .L80012858:
    /* 3058 80012858 21100002 */  addu       $v0, $s0, $zero
  .L8001285C:
    /* 305C 8001285C 2400BF8F */  lw         $ra, 0x24($sp)
    /* 3060 80012860 2000B48F */  lw         $s4, 0x20($sp)
    /* 3064 80012864 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 3068 80012868 1800B28F */  lw         $s2, 0x18($sp)
    /* 306C 8001286C 1400B18F */  lw         $s1, 0x14($sp)
    /* 3070 80012870 1000B08F */  lw         $s0, 0x10($sp)
    /* 3074 80012874 0800E003 */  jr         $ra
    /* 3078 80012878 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel Item_Use
