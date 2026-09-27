nonmatching PadInitDirect, 0xB0

glabel PadInitDirect
    /* 14E54 80024654 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 14E58 80024658 1000B0AF */  sw         $s0, 0x10($sp)
    /* 14E5C 8002465C 21808000 */  addu       $s0, $a0, $zero
    /* 14E60 80024660 1400B1AF */  sw         $s1, 0x14($sp)
    /* 14E64 80024664 1800BFAF */  sw         $ra, 0x18($sp)
    /* 14E68 80024668 0580013C */  lui        $at, %hi(D_80048E50)
    /* 14E6C 8002466C 508E20AC */  sw         $zero, %lo(D_80048E50)($at)
    /* 14E70 80024670 0580013C */  lui        $at, %hi(D_80048E64)
    /* 14E74 80024674 648E20AC */  sw         $zero, %lo(D_80048E64)($at)
    /* 14E78 80024678 C191000C */  jal        Pad_InitDriverHooks
    /* 14E7C 8002467C 2188A000 */   addu      $s1, $a1, $zero
    /* 14E80 80024680 21380000 */  addu       $a3, $zero, $zero
    /* 14E84 80024684 0580023C */  lui        $v0, %hi(D_80048E4C)
    /* 14E88 80024688 4C8E428C */  lw         $v0, %lo(D_80048E4C)($v0)
    /* 14E8C 8002468C FF000824 */  addiu      $t0, $zero, 0xFF
    /* 14E90 80024690 21304000 */  addu       $a2, $v0, $zero
    /* 14E94 80024694 3000C524 */  addiu      $a1, $a2, 0x30
    /* 14E98 80024698 3000D0AC */  sw         $s0, 0x30($a2)
    /* 14E9C 8002469C 2001D1AC */  sw         $s1, 0x120($a2)
  .L800246A0:
    /* 14EA0 800246A0 0000A28C */  lw         $v0, 0x0($a1)
    /* 14EA4 800246A4 5D00C424 */  addiu      $a0, $a2, 0x5D
    /* 14EA8 800246A8 DCFFA0AC */  sw         $zero, -0x24($a1)
    /* 14EAC 800246AC E0FFA6AC */  sw         $a2, -0x20($a1)
    /* 14EB0 800246B0 000048A0 */  sb         $t0, 0x0($v0)
    /* 14EB4 800246B4 0000A28C */  lw         $v0, 0x0($a1)
    /* 14EB8 800246B8 05000324 */  addiu      $v1, $zero, 0x5
    /* 14EBC 800246BC 010040A0 */  sb         $zero, 0x1($v0)
  .L800246C0:
    /* 14EC0 800246C0 000088A0 */  sb         $t0, 0x0($a0)
    /* 14EC4 800246C4 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 14EC8 800246C8 FDFF6104 */  bgez       $v1, .L800246C0
    /* 14ECC 800246CC 01008424 */   addiu     $a0, $a0, 0x1
    /* 14ED0 800246D0 0100E724 */  addiu      $a3, $a3, 0x1
    /* 14ED4 800246D4 F000A524 */  addiu      $a1, $a1, 0xF0
    /* 14ED8 800246D8 0200E228 */  slti       $v0, $a3, 0x2
    /* 14EDC 800246DC F0FF4014 */  bnez       $v0, .L800246A0
    /* 14EE0 800246E0 F000C624 */   addiu     $a2, $a2, 0xF0
    /* 14EE4 800246E4 01000224 */  addiu      $v0, $zero, 0x1
    /* 14EE8 800246E8 0580013C */  lui        $at, %hi(D_80048E50)
    /* 14EEC 800246EC 508E22AC */  sw         $v0, %lo(D_80048E50)($at)
    /* 14EF0 800246F0 1800BF8F */  lw         $ra, 0x18($sp)
    /* 14EF4 800246F4 1400B18F */  lw         $s1, 0x14($sp)
    /* 14EF8 800246F8 1000B08F */  lw         $s0, 0x10($sp)
    /* 14EFC 800246FC 0800E003 */  jr         $ra
    /* 14F00 80024700 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel PadInitDirect
