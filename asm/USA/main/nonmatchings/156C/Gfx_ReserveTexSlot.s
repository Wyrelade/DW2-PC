nonmatching Gfx_ReserveTexSlot, 0xD8

glabel Gfx_ReserveTexSlot
    /* D5A8 8001CDA8 FFFF0724 */  addiu      $a3, $zero, -0x1
    /* D5AC 8001CDAC 21180000 */  addu       $v1, $zero, $zero
    /* D5B0 8001CDB0 0680023C */  lui        $v0, %hi(Gfx_TexSlots)
    /* D5B4 8001CDB4 60CD4624 */  addiu      $a2, $v0, %lo(Gfx_TexSlots)
    /* D5B8 8001CDB8 21286000 */  addu       $a1, $v1, $zero
    /* D5BC 8001CDBC FEFF0824 */  addiu      $t0, $zero, -0x2
  .L8001CDC0:
    /* D5C0 8001CDC0 0000C28C */  lw         $v0, 0x0($a2)
    /* D5C4 8001CDC4 00000000 */  nop
    /* D5C8 8001CDC8 0C004810 */  beq        $v0, $t0, .L8001CDFC
    /* D5CC 8001CDCC 00000000 */   nop
    /* D5D0 8001CDD0 03004014 */  bnez       $v0, .L8001CDE0
    /* D5D4 8001CDD4 00000000 */   nop
    /* D5D8 8001CDD8 83730008 */  j          .L8001CE0C
    /* D5DC 8001CDDC 2118A000 */   addu      $v1, $a1, $zero
  .L8001CDE0:
    /* D5E0 8001CDE0 0400C48C */  lw         $a0, 0x4($a2)
    /* D5E4 8001CDE4 00000000 */  nop
    /* D5E8 8001CDE8 2B108700 */  sltu       $v0, $a0, $a3
    /* D5EC 8001CDEC 03004010 */  beqz       $v0, .L8001CDFC
    /* D5F0 8001CDF0 00000000 */   nop
    /* D5F4 8001CDF4 21388000 */  addu       $a3, $a0, $zero
    /* D5F8 8001CDF8 2118A000 */  addu       $v1, $a1, $zero
  .L8001CDFC:
    /* D5FC 8001CDFC 0100A524 */  addiu      $a1, $a1, 0x1
    /* D600 8001CE00 1800A228 */  slti       $v0, $a1, 0x18
    /* D604 8001CE04 EEFF4014 */  bnez       $v0, .L8001CDC0
    /* D608 8001CE08 2000C624 */   addiu     $a2, $a2, 0x20
  .L8001CE0C:
    /* D60C 8001CE0C 40190300 */  sll        $v1, $v1, 5
    /* D610 8001CE10 0680023C */  lui        $v0, %hi(Gfx_TexSlots)
    /* D614 8001CE14 60CD4224 */  addiu      $v0, $v0, %lo(Gfx_TexSlots)
    /* D618 8001CE18 21306200 */  addu       $a2, $v1, $v0
    /* D61C 8001CE1C FEFF0224 */  addiu      $v0, $zero, -0x2
    /* D620 8001CE20 0000C2AC */  sw         $v0, 0x0($a2)
    /* D624 8001CE24 0680023C */  lui        $v0, %hi(Sys_State)
    /* D628 8001CE28 70F7438C */  lw         $v1, %lo(Sys_State)($v0)
    /* D62C 8001CE2C 1400C28C */  lw         $v0, 0x14($a2)
    /* D630 8001CE30 1C00C48C */  lw         $a0, 0x1C($a2)
    /* D634 8001CE34 0800C0AC */  sw         $zero, 0x8($a2)
    /* D638 8001CE38 02004230 */  andi       $v0, $v0, 0x2
    /* D63C 8001CE3C 0100422C */  sltiu      $v0, $v0, 0x1
    /* D640 8001CE40 C0110200 */  sll        $v0, $v0, 7
    /* D644 8001CE44 00018430 */  andi       $a0, $a0, 0x100
    /* D648 8001CE48 0400C3AC */  sw         $v1, 0x4($a2)
    /* D64C 8001CE4C 1800C38C */  lw         $v1, 0x18($a2)
    /* D650 8001CE50 03210400 */  sra        $a0, $a0, 4
    /* D654 8001CE54 0C00C2AC */  sw         $v0, 0xC($a2)
    /* D658 8001CE58 1C00C294 */  lhu        $v0, 0x1C($a2)
    /* D65C 8001CE5C FF036330 */  andi       $v1, $v1, 0x3FF
    /* D660 8001CE60 83190300 */  sra        $v1, $v1, 6
    /* D664 8001CE64 25208300 */  or         $a0, $a0, $v1
    /* D668 8001CE68 00024230 */  andi       $v0, $v0, 0x200
    /* D66C 8001CE6C 80100200 */  sll        $v0, $v0, 2
    /* D670 8001CE70 25208200 */  or         $a0, $a0, $v0
    /* D674 8001CE74 2110C000 */  addu       $v0, $a2, $zero
    /* D678 8001CE78 0800E003 */  jr         $ra
    /* D67C 8001CE7C 1000C4A4 */   sh        $a0, 0x10($a2)
endlabel Gfx_ReserveTexSlot
