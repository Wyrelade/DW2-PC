nonmatching Stg40_ReadFloorBits, 0x78

glabel Stg40_ReadFloorBits
    /* CBF4 8006FF54 0580023C */  lui        $v0, %hi(D_8005071C)
    /* CBF8 8006FF58 1C07428C */  lw         $v0, %lo(D_8005071C)($v0)
    /* CBFC 8006FF5C 00000000 */  nop
    /* CC00 8006FF60 540E428C */  lw         $v0, 0xE54($v0)
    /* CC04 8006FF64 00000000 */  nop
    /* CC08 8006FF68 00004284 */  lh         $v0, 0x0($v0)
    /* CC0C 8006FF6C 00000000 */  nop
    /* CC10 8006FF70 02004104 */  bgez       $v0, .L8006FF7C
    /* CC14 8006FF74 2140C000 */   addu      $t0, $a2, $zero
    /* CC18 8006FF78 07004224 */  addiu      $v0, $v0, 0x7
  .L8006FF7C:
    /* CC1C 8006FF7C C3100200 */  sra        $v0, $v0, 3
    /* CC20 8006FF80 0200C104 */  bgez       $a2, .L8006FF8C
    /* CC24 8006FF84 18004700 */   mult      $v0, $a3
    /* CC28 8006FF88 0700C824 */  addiu      $t0, $a2, 0x7
  .L8006FF8C:
    /* CC2C 8006FF8C C3100800 */  sra        $v0, $t0, 3
    /* CC30 8006FF90 12480000 */  mflo       $t1
    /* CC34 8006FF94 21182201 */  addu       $v1, $t1, $v0
    /* CC38 8006FF98 80180300 */  sll        $v1, $v1, 2
    /* CC3C 8006FF9C 21186500 */  addu       $v1, $v1, $a1
    /* CC40 8006FFA0 C0100200 */  sll        $v0, $v0, 3
    /* CC44 8006FFA4 2310C200 */  subu       $v0, $a2, $v0
    /* CC48 8006FFA8 0000638C */  lw         $v1, 0x0($v1)
    /* CC4C 8006FFAC 80100200 */  sll        $v0, $v0, 2
    /* CC50 8006FFB0 06184300 */  srlv       $v1, $v1, $v0
    /* CC54 8006FFB4 0F006330 */  andi       $v1, $v1, 0xF
    /* CC58 8006FFB8 40180300 */  sll        $v1, $v1, 1
    /* CC5C 8006FFBC 21186400 */  addu       $v1, $v1, $a0
    /* CC60 8006FFC0 00006294 */  lhu        $v0, 0x0($v1)
    /* CC64 8006FFC4 0800E003 */  jr         $ra
    /* CC68 8006FFC8 00000000 */   nop
endlabel Stg40_ReadFloorBits
