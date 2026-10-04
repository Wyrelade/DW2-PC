nonmatching Stg40_FindEntByDigiId, 0x6C

glabel Stg40_FindEntByDigiId
    /* EBF0 80071F50 0580023C */  lui        $v0, %hi(Dung_StatePtr)
    /* EBF4 80071F54 1C07428C */  lw         $v0, %lo(Dung_StatePtr)($v0)
    /* EBF8 80071F58 21300000 */  addu       $a2, $zero, $zero
    /* EBFC 80071F5C 18004324 */  addiu      $v1, $v0, 0x18
  .L80071F60:
    /* EC00 80071F60 0000658C */  lw         $a1, 0x0($v1)
    /* EC04 80071F64 00000000 */  nop
    /* EC08 80071F68 0080A230 */  andi       $v0, $a1, 0x8000
    /* EC0C 80071F6C 0D004010 */  beqz       $v0, .L80071FA4
    /* EC10 80071F70 00000000 */   nop
    /* EC14 80071F74 07008010 */  beqz       $a0, .L80071F94
    /* EC18 80071F78 0100A230 */   andi      $v0, $a1, 0x1
    /* EC1C 80071F7C 04006284 */  lh         $v0, 0x4($v1)
    /* EC20 80071F80 00000000 */  nop
    /* EC24 80071F84 05008210 */  beq        $a0, $v0, .L80071F9C
    /* EC28 80071F88 00000000 */   nop
    /* EC2C 80071F8C 05008014 */  bnez       $a0, .L80071FA4
    /* EC30 80071F90 0100A230 */   andi      $v0, $a1, 0x1
  .L80071F94:
    /* EC34 80071F94 04004010 */  beqz       $v0, .L80071FA8
    /* EC38 80071F98 0100C624 */   addiu     $a2, $a2, 0x1
  .L80071F9C:
    /* EC3C 80071F9C 0800E003 */  jr         $ra
    /* EC40 80071FA0 21106000 */   addu      $v0, $v1, $zero
  .L80071FA4:
    /* EC44 80071FA4 0100C624 */  addiu      $a2, $a2, 0x1
  .L80071FA8:
    /* EC48 80071FA8 2900C228 */  slti       $v0, $a2, 0x29
    /* EC4C 80071FAC ECFF4014 */  bnez       $v0, .L80071F60
    /* EC50 80071FB0 48006324 */   addiu     $v1, $v1, 0x48
    /* EC54 80071FB4 0800E003 */  jr         $ra
    /* EC58 80071FB8 21100000 */   addu      $v0, $zero, $zero
endlabel Stg40_FindEntByDigiId
