nonmatching Stg40_LoadEventTiles, 0xC0

glabel Stg40_LoadEventTiles
    /* B2AC 8006E60C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* B2B0 8006E610 1400B1AF */  sw         $s1, 0x14($sp)
    /* B2B4 8006E614 0780113C */  lui        $s1, %hi(D_80072B60)
    /* B2B8 8006E618 602B228E */  lw         $v0, %lo(D_80072B60)($s1)
    /* B2BC 8006E61C 1800BFAF */  sw         $ra, 0x18($sp)
    /* B2C0 8006E620 1000B0AF */  sw         $s0, 0x10($sp)
    /* B2C4 8006E624 24008010 */  beqz       $a0, .L8006E6B8
    /* B2C8 8006E628 6C0140AC */   sw        $zero, 0x16C($v0)
    /* B2CC 8006E62C A378000C */  jal        Flag_SetTableFile
    /* B2D0 8006E630 00000000 */   nop
    /* B2D4 8006E634 2079000C */  jal        Flag_FirstPassingEntry
    /* B2D8 8006E638 00000000 */   nop
    /* B2DC 8006E63C ABB90108 */  j          .L8006E6AC
    /* B2E0 8006E640 21804000 */   addu      $s0, $v0, $zero
  .L8006E644:
    /* B2E4 8006E644 7A79000C */  jal        Flag_GetEntryPosList
    /* B2E8 8006E648 21200002 */   addu      $a0, $s0, $zero
    /* B2EC 8006E64C 602B258E */  lw         $a1, %lo(D_80072B60)($s1)
    /* B2F0 8006E650 00004390 */  lbu        $v1, 0x0($v0)
    /* B2F4 8006E654 6C01A48C */  lw         $a0, 0x16C($a1)
    /* B2F8 8006E658 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* B2FC 8006E65C C0200400 */  sll        $a0, $a0, 3
    /* B300 8006E660 2120A400 */  addu       $a0, $a1, $a0
    /* B304 8006E664 440183A4 */  sh         $v1, 0x144($a0)
    /* B308 8006E668 6C01A38C */  lw         $v1, 0x16C($a1)
    /* B30C 8006E66C 01004290 */  lbu        $v0, 0x1($v0)
    /* B310 8006E670 C0180300 */  sll        $v1, $v1, 3
    /* B314 8006E674 2118A300 */  addu       $v1, $a1, $v1
    /* B318 8006E678 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* B31C 8006E67C 460162A4 */  sh         $v0, 0x146($v1)
    /* B320 8006E680 6C01A28C */  lw         $v0, 0x16C($a1)
    /* B324 8006E684 00000000 */  nop
    /* B328 8006E688 C0100200 */  sll        $v0, $v0, 3
    /* B32C 8006E68C 2110A200 */  addu       $v0, $a1, $v0
    /* B330 8006E690 480150AC */  sw         $s0, 0x148($v0)
    /* B334 8006E694 6C01A28C */  lw         $v0, 0x16C($a1)
    /* B338 8006E698 00000000 */  nop
    /* B33C 8006E69C 01004224 */  addiu      $v0, $v0, 0x1
    /* B340 8006E6A0 E478000C */  jal        Flag_NextPassingEntry
    /* B344 8006E6A4 6C01A2AC */   sw        $v0, 0x16C($a1)
    /* B348 8006E6A8 21804000 */  addu       $s0, $v0, $zero
  .L8006E6AC:
    /* B34C 8006E6AC FFFF0224 */  addiu      $v0, $zero, -0x1
    /* B350 8006E6B0 E4FF0216 */  bne        $s0, $v0, .L8006E644
    /* B354 8006E6B4 00000000 */   nop
  .L8006E6B8:
    /* B358 8006E6B8 1800BF8F */  lw         $ra, 0x18($sp)
    /* B35C 8006E6BC 1400B18F */  lw         $s1, 0x14($sp)
    /* B360 8006E6C0 1000B08F */  lw         $s0, 0x10($sp)
    /* B364 8006E6C4 0800E003 */  jr         $ra
    /* B368 8006E6C8 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Stg40_LoadEventTiles
