nonmatching func_8003F760, 0x100

glabel func_8003F760
    /* 2FF60 8003F760 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 2FF64 8003F764 1800B2AF */  sw         $s2, 0x18($sp)
    /* 2FF68 8003F768 21908000 */  addu       $s2, $a0, $zero
    /* 2FF6C 8003F76C 2000B4AF */  sw         $s4, 0x20($sp)
    /* 2FF70 8003F770 21A0A000 */  addu       $s4, $a1, $zero
    /* 2FF74 8003F774 2800BFAF */  sw         $ra, 0x28($sp)
    /* 2FF78 8003F778 2400B5AF */  sw         $s5, 0x24($sp)
    /* 2FF7C 8003F77C 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 2FF80 8003F780 1400B1AF */  sw         $s1, 0x14($sp)
    /* 2FF84 8003F784 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2FF88 8003F788 0000428E */  lw         $v0, 0x0($s2)
    /* 2FF8C 8003F78C 00000000 */  nop
    /* 2FF90 8003F790 03004014 */  bnez       $v0, .L8003F7A0
    /* 2FF94 8003F794 21A8C000 */   addu      $s5, $a2, $zero
    /* 2FF98 8003F798 01000224 */  addiu      $v0, $zero, 0x1
    /* 2FF9C 8003F79C 000042AE */  sw         $v0, 0x0($s2)
  .L8003F7A0:
    /* 2FFA0 8003F7A0 5401038C */  lw         $v1, 0x154($zero)
    /* 2FFA4 8003F7A4 CCCC023C */  lui        $v0, (0xCCCCCCCD >> 16)
    /* 2FFA8 8003F7A8 CDCC4234 */  ori        $v0, $v0, (0xCCCCCCCD & 0xFFFF)
    /* 2FFAC 8003F7AC 19006200 */  multu      $v1, $v0
    /* 2FFB0 8003F7B0 5001108C */  lw         $s0, 0x150($zero)
    /* 2FFB4 8003F7B4 0680133C */  lui        $s3, %hi(D_80062FE0)
    /* 2FFB8 8003F7B8 E02F738E */  lw         $s3, %lo(D_80062FE0)($s3)
    /* 2FFBC 8003F7BC 10380000 */  mfhi       $a3
    /* 2FFC0 8003F7C0 82190700 */  srl        $v1, $a3, 6
    /* 2FFC4 8003F7C4 80100300 */  sll        $v0, $v1, 2
    /* 2FFC8 8003F7C8 21104300 */  addu       $v0, $v0, $v1
    /* 2FFCC 8003F7CC 00110200 */  sll        $v0, $v0, 4
    /* 2FFD0 8003F7D0 21180202 */  addu       $v1, $s0, $v0
    /* 2FFD4 8003F7D4 2B100302 */  sltu       $v0, $s0, $v1
    /* 2FFD8 8003F7D8 12004010 */  beqz       $v0, .L8003F824
    /* 2FFDC 8003F7DC 21204002 */   addu      $a0, $s2, $zero
    /* 2FFE0 8003F7E0 21886000 */  addu       $s1, $v1, $zero
  .L8003F7E4:
    /* 2FFE4 8003F7E4 0000048E */  lw         $a0, 0x0($s0)
    /* 2FFE8 8003F7E8 00000000 */  nop
    /* 2FFEC 8003F7EC 08008010 */  beqz       $a0, .L8003F810
    /* 2FFF0 8003F7F0 00000000 */   nop
    /* 2FFF4 8003F7F4 0680053C */  lui        $a1, %hi(D_80062FE8)
    /* 2FFF8 8003F7F8 49FE000C */  jal        strcmp
    /* 2FFFC 8003F7FC E82FA524 */   addiu     $a1, $a1, %lo(D_80062FE8)
    /* 30000 8003F800 03004014 */  bnez       $v0, .L8003F810
    /* 30004 8003F804 00000000 */   nop
    /* 30008 8003F808 08FE0008 */  j          .L8003F820
    /* 3000C 8003F80C 340013AE */   sw        $s3, 0x34($s0)
  .L8003F810:
    /* 30010 8003F810 50001026 */  addiu      $s0, $s0, 0x50
    /* 30014 8003F814 2B101102 */  sltu       $v0, $s0, $s1
    /* 30018 8003F818 F2FF4014 */  bnez       $v0, .L8003F7E4
    /* 3001C 8003F81C 00000000 */   nop
  .L8003F820:
    /* 30020 8003F820 21204002 */  addu       $a0, $s2, $zero
  .L8003F824:
    /* 30024 8003F824 21288002 */  addu       $a1, $s4, $zero
    /* 30028 8003F828 0680023C */  lui        $v0, %hi(D_80062FE0)
    /* 3002C 8003F82C E02F428C */  lw         $v0, %lo(D_80062FE0)($v0)
    /* 30030 8003F830 00000000 */  nop
    /* 30034 8003F834 09F84000 */  jalr       $v0
    /* 30038 8003F838 2130A002 */   addu      $a2, $s5, $zero
    /* 3003C 8003F83C 2800BF8F */  lw         $ra, 0x28($sp)
    /* 30040 8003F840 2400B58F */  lw         $s5, 0x24($sp)
    /* 30044 8003F844 2000B48F */  lw         $s4, 0x20($sp)
    /* 30048 8003F848 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 3004C 8003F84C 1800B28F */  lw         $s2, 0x18($sp)
    /* 30050 8003F850 1400B18F */  lw         $s1, 0x14($sp)
    /* 30054 8003F854 1000B08F */  lw         $s0, 0x10($sp)
    /* 30058 8003F858 0800E003 */  jr         $ra
    /* 3005C 8003F85C 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_8003F760
    /* 30060 8003F860 00000000 */  nop
