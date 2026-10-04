nonmatching Stg40_MapPosToWorld, 0x58

glabel Stg40_MapPosToWorld
    /* 2898 80065BF8 0780023C */  lui        $v0, %hi(Stg40_RootState)
    /* 289C 80065BFC 602B438C */  lw         $v1, %lo(Stg40_RootState)($v0)
    /* 28A0 80065C00 00000000 */  nop
    /* 28A4 80065C04 3000628C */  lw         $v0, 0x30($v1)
    /* 28A8 80065C08 00000000 */  nop
    /* 28AC 80065C0C 2328A200 */  subu       $a1, $a1, $v0
    /* 28B0 80065C10 C0120500 */  sll        $v0, $a1, 11
    /* 28B4 80065C14 02004104 */  bgez       $v0, .L80065C20
    /* 28B8 80065C18 00000000 */   nop
    /* 28BC 80065C1C 3F004224 */  addiu      $v0, $v0, 0x3F
  .L80065C20:
    /* 28C0 80065C20 83110200 */  sra        $v0, $v0, 6
    /* 28C4 80065C24 23100200 */  negu       $v0, $v0
    /* 28C8 80065C28 0400E2A4 */  sh         $v0, 0x4($a3)
    /* 28CC 80065C2C 2C00638C */  lw         $v1, 0x2C($v1)
    /* 28D0 80065C30 23100600 */  negu       $v0, $a2
    /* 28D4 80065C34 0200E2A4 */  sh         $v0, 0x2($a3)
    /* 28D8 80065C38 23188300 */  subu       $v1, $a0, $v1
    /* 28DC 80065C3C 80100300 */  sll        $v0, $v1, 2
    /* 28E0 80065C40 21104300 */  addu       $v0, $v0, $v1
    /* 28E4 80065C44 C0100200 */  sll        $v0, $v0, 3
    /* 28E8 80065C48 0800E003 */  jr         $ra
    /* 28EC 80065C4C 0000E2A4 */   sh        $v0, 0x0($a3)
endlabel Stg40_MapPosToWorld
