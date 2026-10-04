nonmatching Stg40_GetRegionCells, 0xB4

glabel Stg40_GetRegionCells
    /* AB90 8006DEF0 21480000 */  addu       $t1, $zero, $zero
    /* AB94 8006DEF4 0580023C */  lui        $v0, %hi(Dung_StatePtr)
    /* AB98 8006DEF8 1C07428C */  lw         $v0, %lo(Dung_StatePtr)($v0)
    /* AB9C 8006DEFC 00000000 */  nop
    /* ABA0 8006DF00 540E438C */  lw         $v1, 0xE54($v0)
    /* ABA4 8006DF04 580E4E8C */  lw         $t6, 0xE58($v0)
    /* ABA8 8006DF08 02006D84 */  lh         $t5, 0x2($v1)
    /* ABAC 8006DF0C 00006A84 */  lh         $t2, 0x0($v1)
    /* ABB0 8006DF10 2200A019 */  blez       $t5, .L8006DF9C
    /* ABB4 8006DF14 21402001 */   addu      $t0, $t1, $zero
    /* ABB8 8006DF18 21582001 */  addu       $t3, $t1, $zero
  .L8006DF1C:
    /* ABBC 8006DF1C 1B004019 */  blez       $t2, .L8006DF8C
    /* ABC0 8006DF20 21300000 */   addu      $a2, $zero, $zero
    /* ABC4 8006DF24 21606001 */  addu       $t4, $t3, $zero
    /* ABC8 8006DF28 40100800 */  sll        $v0, $t0, 1
    /* ABCC 8006DF2C 21384400 */  addu       $a3, $v0, $a0
    /* ABD0 8006DF30 21108601 */  addu       $v0, $t4, $a2
  .L8006DF34:
    /* ABD4 8006DF34 80100200 */  sll        $v0, $v0, 2
    /* ABD8 8006DF38 2118C201 */  addu       $v1, $t6, $v0
    /* ABDC 8006DF3C 02006290 */  lbu        $v0, 0x2($v1)
    /* ABE0 8006DF40 00000000 */  nop
    /* ABE4 8006DF44 0D004514 */  bne        $v0, $a1, .L8006DF7C
    /* ABE8 8006DF48 00000000 */   nop
    /* ABEC 8006DF4C 00006394 */  lhu        $v1, 0x0($v1)
    /* ABF0 8006DF50 00000000 */  nop
    /* ABF4 8006DF54 40006230 */  andi       $v0, $v1, 0x40
    /* ABF8 8006DF58 08004014 */  bnez       $v0, .L8006DF7C
    /* ABFC 8006DF5C 0F006230 */   andi      $v0, $v1, 0xF
    /* AC00 8006DF60 0800422C */  sltiu      $v0, $v0, 0x8
    /* AC04 8006DF64 05004010 */  beqz       $v0, .L8006DF7C
    /* AC08 8006DF68 00000000 */   nop
    /* AC0C 8006DF6C 0000E6A0 */  sb         $a2, 0x0($a3)
    /* AC10 8006DF70 0100E9A0 */  sb         $t1, 0x1($a3)
    /* AC14 8006DF74 0200E724 */  addiu      $a3, $a3, 0x2
    /* AC18 8006DF78 01000825 */  addiu      $t0, $t0, 0x1
  .L8006DF7C:
    /* AC1C 8006DF7C 0100C624 */  addiu      $a2, $a2, 0x1
    /* AC20 8006DF80 2A10CA00 */  slt        $v0, $a2, $t2
    /* AC24 8006DF84 EBFF4014 */  bnez       $v0, .L8006DF34
    /* AC28 8006DF88 21108601 */   addu      $v0, $t4, $a2
  .L8006DF8C:
    /* AC2C 8006DF8C 01002925 */  addiu      $t1, $t1, 0x1
    /* AC30 8006DF90 2A102D01 */  slt        $v0, $t1, $t5
    /* AC34 8006DF94 E1FF4014 */  bnez       $v0, .L8006DF1C
    /* AC38 8006DF98 21586A01 */   addu      $t3, $t3, $t2
  .L8006DF9C:
    /* AC3C 8006DF9C 0800E003 */  jr         $ra
    /* AC40 8006DFA0 21100001 */   addu      $v0, $t0, $zero
endlabel Stg40_GetRegionCells
