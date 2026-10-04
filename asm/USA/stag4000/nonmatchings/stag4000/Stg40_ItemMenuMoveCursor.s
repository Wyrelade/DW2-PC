nonmatching Stg40_ItemMenuMoveCursor, 0xC0

glabel Stg40_ItemMenuMoveCursor
    /* 7B14 8006AE74 0780023C */  lui        $v0, %hi(Stg40_RootState)
    /* 7B18 8006AE78 0680033C */  lui        $v1, %hi(Pad_Repeat)
    /* 7B1C 8006AE7C 2CF76394 */  lhu        $v1, %lo(Pad_Repeat)($v1)
    /* 7B20 8006AE80 602B448C */  lw         $a0, %lo(Stg40_RootState)($v0)
    /* 7B24 8006AE84 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 7B28 8006AE88 1000BFAF */  sw         $ra, 0x10($sp)
    /* 7B2C 8006AE8C 00106330 */  andi       $v1, $v1, 0x1000
    /* 7B30 8006AE90 E2008590 */  lbu        $a1, 0xE2($a0)
    /* 7B34 8006AE94 05006010 */  beqz       $v1, .L8006AEAC
    /* 7B38 8006AE98 0680023C */   lui       $v0, %hi(Pad_Repeat)
    /* 7B3C 8006AE9C 0200A010 */  beqz       $a1, .L8006AEA8
    /* 7B40 8006AEA0 FFFFA224 */   addiu     $v0, $a1, -0x1
    /* 7B44 8006AEA4 E20082A0 */  sb         $v0, 0xE2($a0)
  .L8006AEA8:
    /* 7B48 8006AEA8 0680023C */  lui        $v0, %hi(Pad_Repeat)
  .L8006AEAC:
    /* 7B4C 8006AEAC 2CF74294 */  lhu        $v0, %lo(Pad_Repeat)($v0)
    /* 7B50 8006AEB0 00000000 */  nop
    /* 7B54 8006AEB4 00404230 */  andi       $v0, $v0, 0x4000
    /* 7B58 8006AEB8 0A004010 */  beqz       $v0, .L8006AEE4
    /* 7B5C 8006AEBC 0780023C */   lui       $v0, %hi(Stg40_RootState)
    /* 7B60 8006AEC0 602B448C */  lw         $a0, %lo(Stg40_RootState)($v0)
    /* 7B64 8006AEC4 00000000 */  nop
    /* 7B68 8006AEC8 E2008390 */  lbu        $v1, 0xE2($a0)
    /* 7B6C 8006AECC E1008290 */  lbu        $v0, 0xE1($a0)
    /* 7B70 8006AED0 01006324 */  addiu      $v1, $v1, 0x1
    /* 7B74 8006AED4 2A106200 */  slt        $v0, $v1, $v0
    /* 7B78 8006AED8 03004010 */  beqz       $v0, .L8006AEE8
    /* 7B7C 8006AEDC 0780023C */   lui       $v0, %hi(Stg40_RootState)
    /* 7B80 8006AEE0 E20083A0 */  sb         $v1, 0xE2($a0)
  .L8006AEE4:
    /* 7B84 8006AEE4 0780023C */  lui        $v0, %hi(Stg40_RootState)
  .L8006AEE8:
    /* 7B88 8006AEE8 602B438C */  lw         $v1, %lo(Stg40_RootState)($v0)
    /* 7B8C 8006AEEC 00000000 */  nop
    /* 7B90 8006AEF0 E2006290 */  lbu        $v0, 0xE2($v1)
    /* 7B94 8006AEF4 00000000 */  nop
    /* 7B98 8006AEF8 0A00A210 */  beq        $a1, $v0, .L8006AF24
    /* 7B9C 8006AEFC 00000000 */   nop
    /* 7BA0 8006AF00 E4006290 */  lbu        $v0, 0xE4($v1)
    /* 7BA4 8006AF04 00000000 */  nop
    /* 7BA8 8006AF08 02004010 */  beqz       $v0, .L8006AF14
    /* 7BAC 8006AF0C 0C000424 */   addiu     $a0, $zero, 0xC
    /* 7BB0 8006AF10 0D000424 */  addiu      $a0, $zero, 0xD
  .L8006AF14:
    /* 7BB4 8006AF14 A369000C */  jal        Snd_PlayById
    /* 7BB8 8006AF18 21280000 */   addu      $a1, $zero, $zero
    /* 7BBC 8006AF1C 44AB010C */  jal        Stg40_ItemMenuRefresh
    /* 7BC0 8006AF20 00000000 */   nop
  .L8006AF24:
    /* 7BC4 8006AF24 1000BF8F */  lw         $ra, 0x10($sp)
    /* 7BC8 8006AF28 00000000 */  nop
    /* 7BCC 8006AF2C 0800E003 */  jr         $ra
    /* 7BD0 8006AF30 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Stg40_ItemMenuMoveCursor
