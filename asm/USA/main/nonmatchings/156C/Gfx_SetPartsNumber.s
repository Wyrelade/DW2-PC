nonmatching Gfx_SetPartsNumber, 0x100

glabel Gfx_SetPartsNumber
    /* DDB4 8001D5B4 F8FFBD27 */  addiu      $sp, $sp, -0x8
    /* DDB8 8001D5B8 21488000 */  addu       $t1, $a0, $zero
    /* DDBC 8001D5BC 2118E000 */  addu       $v1, $a3, $zero
    /* DDC0 8001D5C0 21500000 */  addu       $t2, $zero, $zero
    /* DDC4 8001D5C4 0300C104 */  bgez       $a2, .L8001D5D4
    /* DDC8 8001D5C8 21584001 */   addu      $t3, $t2, $zero
    /* DDCC 8001D5CC 01000B24 */  addiu      $t3, $zero, 0x1
    /* DDD0 8001D5D0 23300600 */  negu       $a2, $a2
  .L8001D5D4:
    /* DDD4 8001D5D4 21386000 */  addu       $a3, $v1, $zero
    /* DDD8 8001D5D8 1200C010 */  beqz       $a2, .L8001D624
    /* DDDC 8001D5DC FFFFC824 */   addiu     $t0, $a2, -0x1
    /* DDE0 8001D5E0 66660C3C */  lui        $t4, (0x66666667 >> 16)
    /* DDE4 8001D5E4 67668C35 */  ori        $t4, $t4, (0x66666667 & 0xFFFF)
    /* DDE8 8001D5E8 FFFF0D24 */  addiu      $t5, $zero, -0x1
  .L8001D5EC:
    /* DDEC 8001D5EC 1800EC00 */  mult       $a3, $t4
    /* DDF0 8001D5F0 2120A803 */  addu       $a0, $sp, $t0
    /* DDF4 8001D5F4 FFFF0825 */  addiu      $t0, $t0, -0x1
    /* DDF8 8001D5F8 C3170700 */  sra        $v0, $a3, 31
    /* DDFC 8001D5FC 10700000 */  mfhi       $t6
    /* DE00 8001D600 83180E00 */  sra        $v1, $t6, 2
    /* DE04 8001D604 23186200 */  subu       $v1, $v1, $v0
    /* DE08 8001D608 80100300 */  sll        $v0, $v1, 2
    /* DE0C 8001D60C 21104300 */  addu       $v0, $v0, $v1
    /* DE10 8001D610 40100200 */  sll        $v0, $v0, 1
    /* DE14 8001D614 2310E200 */  subu       $v0, $a3, $v0
    /* DE18 8001D618 000082A0 */  sb         $v0, 0x0($a0)
    /* DE1C 8001D61C F3FF0D15 */  bne        $t0, $t5, .L8001D5EC
    /* DE20 8001D620 21386000 */   addu      $a3, $v1, $zero
  .L8001D624:
    /* DE24 8001D624 0000228D */  lw         $v0, 0x0($t1)
    /* DE28 8001D628 00000000 */  nop
    /* DE2C 8001D62C 1F004010 */  beqz       $v0, .L8001D6AC
    /* DE30 8001D630 00000000 */   nop
    /* DE34 8001D634 01000824 */  addiu      $t0, $zero, 0x1
    /* DE38 8001D638 FFFFC624 */  addiu      $a2, $a2, -0x1
    /* DE3C 8001D63C FF000724 */  addiu      $a3, $zero, 0xFF
    /* DE40 8001D640 0D002325 */  addiu      $v1, $t1, 0xD
    /* DE44 8001D644 21205D01 */  addu       $a0, $t2, $sp
  .L8001D648:
    /* DE48 8001D648 0F00628C */  lw         $v0, 0xF($v1)
    /* DE4C 8001D64C 00000000 */  nop
    /* DE50 8001D650 24104500 */  and        $v0, $v0, $a1
    /* DE54 8001D654 10004010 */  beqz       $v0, .L8001D698
    /* DE58 8001D658 00000000 */   nop
    /* DE5C 8001D65C 07006811 */  beq        $t3, $t0, .L8001D67C
    /* DE60 8001D660 00000000 */   nop
    /* DE64 8001D664 05004611 */  beq        $t2, $a2, .L8001D67C
    /* DE68 8001D668 00000000 */   nop
    /* DE6C 8001D66C 00008290 */  lbu        $v0, 0x0($a0)
    /* DE70 8001D670 00000000 */  nop
    /* DE74 8001D674 05004010 */  beqz       $v0, .L8001D68C
    /* DE78 8001D678 00000000 */   nop
  .L8001D67C:
    /* DE7C 8001D67C 00008290 */  lbu        $v0, 0x0($a0)
    /* DE80 8001D680 01000B24 */  addiu      $t3, $zero, 0x1
    /* DE84 8001D684 A4750008 */  j          .L8001D690
    /* DE88 8001D688 000062A0 */   sb        $v0, 0x0($v1)
  .L8001D68C:
    /* DE8C 8001D68C 000067A0 */  sb         $a3, 0x0($v1)
  .L8001D690:
    /* DE90 8001D690 01008424 */  addiu      $a0, $a0, 0x1
    /* DE94 8001D694 01004A25 */  addiu      $t2, $t2, 0x1
  .L8001D698:
    /* DE98 8001D698 28002925 */  addiu      $t1, $t1, 0x28
    /* DE9C 8001D69C 0000228D */  lw         $v0, 0x0($t1)
    /* DEA0 8001D6A0 00000000 */  nop
    /* DEA4 8001D6A4 E8FF4014 */  bnez       $v0, .L8001D648
    /* DEA8 8001D6A8 28006324 */   addiu     $v1, $v1, 0x28
  .L8001D6AC:
    /* DEAC 8001D6AC 0800E003 */  jr         $ra
    /* DEB0 8001D6B0 0800BD27 */   addiu     $sp, $sp, 0x8
endlabel Gfx_SetPartsNumber
