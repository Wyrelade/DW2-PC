nonmatching Snd_SetSlotContent, 0x98

glabel Snd_SetSlotContent
    /* ADF4 8001A5F4 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* ADF8 8001A5F8 1400B1AF */  sw         $s1, 0x14($sp)
    /* ADFC 8001A5FC 21888000 */  addu       $s1, $a0, $zero
    /* AE00 8001A600 0580023C */  lui        $v0, %hi(D_80054C48)
    /* AE04 8001A604 484C4224 */  addiu      $v0, $v0, %lo(D_80054C48)
    /* AE08 8001A608 40181100 */  sll        $v1, $s1, 1
    /* AE0C 8001A60C 21187100 */  addu       $v1, $v1, $s1
    /* AE10 8001A610 80180300 */  sll        $v1, $v1, 2
    /* AE14 8001A614 23187100 */  subu       $v1, $v1, $s1
    /* AE18 8001A618 80180300 */  sll        $v1, $v1, 2
    /* AE1C 8001A61C 1000B0AF */  sw         $s0, 0x10($sp)
    /* AE20 8001A620 21806200 */  addu       $s0, $v1, $v0
    /* AE24 8001A624 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* AE28 8001A628 1800B2AF */  sw         $s2, 0x18($sp)
    /* AE2C 8001A62C 0000028E */  lw         $v0, 0x0($s0)
    /* AE30 8001A630 2190A000 */  addu       $s2, $a1, $zero
    /* AE34 8001A634 0F005210 */  beq        $v0, $s2, .L8001A674
    /* AE38 8001A638 00000000 */   nop
    /* AE3C 8001A63C 2A69000C */  jal        Snd_UnloadSlot
    /* AE40 8001A640 00000000 */   nop
    /* AE44 8001A644 2000848F */  lw         $a0, %gp_rel(Snd_CurrentId)($gp)
    /* AE48 8001A648 01000224 */  addiu      $v0, $zero, 0x1
    /* AE4C 8001A64C 040002AE */  sw         $v0, 0x4($s0)
    /* AE50 8001A650 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* AE54 8001A654 07008210 */  beq        $a0, $v0, .L8001A674
    /* AE58 8001A658 000012AE */   sw        $s2, 0x0($s0)
    /* AE5C 8001A65C 000F8230 */  andi       $v0, $a0, 0xF00
    /* AE60 8001A660 03120200 */  sra        $v0, $v0, 8
    /* AE64 8001A664 03002216 */  bne        $s1, $v0, .L8001A674
    /* AE68 8001A668 00000000 */   nop
    /* AE6C 8001A66C 0469000C */  jal        Snd_StopById
    /* AE70 8001A670 00000000 */   nop
  .L8001A674:
    /* AE74 8001A674 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* AE78 8001A678 1800B28F */  lw         $s2, 0x18($sp)
    /* AE7C 8001A67C 1400B18F */  lw         $s1, 0x14($sp)
    /* AE80 8001A680 1000B08F */  lw         $s0, 0x10($sp)
    /* AE84 8001A684 0800E003 */  jr         $ra
    /* AE88 8001A688 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Snd_SetSlotContent
