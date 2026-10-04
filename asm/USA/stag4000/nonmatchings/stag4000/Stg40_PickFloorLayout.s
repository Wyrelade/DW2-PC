nonmatching Stg40_PickFloorLayout, 0x4C

glabel Stg40_PickFloorLayout
    /* DA14 80070D74 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* DA18 80070D78 1000BFAF */  sw         $ra, 0x10($sp)
    /* DA1C 80070D7C 71C4010C */  jal        Stg40_RandInt
    /* DA20 80070D80 08000424 */   addiu     $a0, $zero, 0x8
    /* DA24 80070D84 0580033C */  lui        $v1, %hi(Dung_StatePtr)
    /* DA28 80070D88 1C07648C */  lw         $a0, %lo(Dung_StatePtr)($v1)
    /* DA2C 80070D8C 00000000 */  nop
    /* DA30 80070D90 040082A0 */  sb         $v0, 0x4($a0)
    /* DA34 80070D94 1C07628C */  lw         $v0, %lo(Dung_StatePtr)($v1)
    /* DA38 80070D98 07000324 */  addiu      $v1, $zero, 0x7
    /* DA3C 80070D9C 1C004224 */  addiu      $v0, $v0, 0x1C
  .L80070DA0:
    /* DA40 80070DA0 5C0E40AC */  sw         $zero, 0xE5C($v0)
    /* DA44 80070DA4 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* DA48 80070DA8 FDFF6104 */  bgez       $v1, .L80070DA0
    /* DA4C 80070DAC FCFF4224 */   addiu     $v0, $v0, -0x4
    /* DA50 80070DB0 1000BF8F */  lw         $ra, 0x10($sp)
    /* DA54 80070DB4 00000000 */  nop
    /* DA58 80070DB8 0800E003 */  jr         $ra
    /* DA5C 80070DBC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Stg40_PickFloorLayout
