nonmatching Stg40_AiTryStep, 0x1C4

glabel Stg40_AiTryStep
    /* 8A8C 8006BDEC C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* 8A90 8006BDF0 3800B6AF */  sw         $s6, 0x38($sp)
    /* 8A94 8006BDF4 21B08000 */  addu       $s6, $a0, $zero
    /* 8A98 8006BDF8 3000B4AF */  sw         $s4, 0x30($sp)
    /* 8A9C 8006BDFC 21A00000 */  addu       $s4, $zero, $zero
    /* 8AA0 8006BE00 2800B2AF */  sw         $s2, 0x28($sp)
    /* 8AA4 8006BE04 1800D226 */  addiu      $s2, $s6, 0x18
    /* 8AA8 8006BE08 2400B1AF */  sw         $s1, 0x24($sp)
    /* 8AAC 8006BE0C 21888002 */  addu       $s1, $s4, $zero
    /* 8AB0 8006BE10 FFFF0624 */  addiu      $a2, $zero, -0x1
    /* 8AB4 8006BE14 1000A427 */  addiu      $a0, $sp, 0x10
    /* 8AB8 8006BE18 3C00BFAF */  sw         $ra, 0x3C($sp)
    /* 8ABC 8006BE1C 3400B5AF */  sw         $s5, 0x34($sp)
    /* 8AC0 8006BE20 2C00B3AF */  sw         $s3, 0x2C($sp)
    /* 8AC4 8006BE24 2000B0AF */  sw         $s0, 0x20($sp)
  .L8006BE28:
    /* 8AC8 8006BE28 020086A4 */  sh         $a2, 0x2($a0)
    /* 8ACC 8006BE2C 000086A4 */  sh         $a2, 0x0($a0)
    /* 8AD0 8006BE30 01003126 */  addiu      $s1, $s1, 0x1
    /* 8AD4 8006BE34 0300222A */  slti       $v0, $s1, 0x3
    /* 8AD8 8006BE38 FBFF4014 */  bnez       $v0, .L8006BE28
    /* 8ADC 8006BE3C 04008424 */   addiu     $a0, $a0, 0x4
    /* 8AE0 8006BE40 0500A22C */  sltiu      $v0, $a1, 0x5
    /* 8AE4 8006BE44 08004010 */  beqz       $v0, .L8006BE68
    /* 8AE8 8006BE48 0680023C */   lui       $v0, %hi(jtbl_800634E8)
    /* 8AEC 8006BE4C E8344224 */  addiu      $v0, $v0, %lo(jtbl_800634E8)
    /* 8AF0 8006BE50 80180500 */  sll        $v1, $a1, 2
    /* 8AF4 8006BE54 21186200 */  addu       $v1, $v1, $v0
    /* 8AF8 8006BE58 0000628C */  lw         $v0, 0x0($v1)
    /* 8AFC 8006BE5C 00000000 */  nop
    /* 8B00 8006BE60 08004000 */  jr         $v0
    /* 8B04 8006BE64 00000000 */   nop
  jlabel .L8006BE68
    /* 8B08 8006BE68 2120C002 */  addu       $a0, $s6, $zero
    /* 8B0C 8006BE6C 6AAE010C */  jal        Stg40_AiPathChase
    /* 8B10 8006BE70 1000A527 */   addiu     $a1, $sp, 0x10
    /* 8B14 8006BE74 B0AF0108 */  j          .L8006BEC0
    /* 8B18 8006BE78 21984000 */   addu      $s3, $v0, $zero
  jlabel .L8006BE7C
    /* 8B1C 8006BE7C 2120C002 */  addu       $a0, $s6, $zero
    /* 8B20 8006BE80 A6AD010C */  jal        Stg40_AiPathFlee
    /* 8B24 8006BE84 1000A527 */   addiu     $a1, $sp, 0x10
    /* 8B28 8006BE88 B0AF0108 */  j          .L8006BEC0
    /* 8B2C 8006BE8C 21984000 */   addu      $s3, $v0, $zero
  jlabel .L8006BE90
    /* 8B30 8006BE90 2120C002 */  addu       $a0, $s6, $zero
    /* 8B34 8006BE94 EFAE010C */  jal        Stg40_AiPathChaseInRoom
    /* 8B38 8006BE98 1000A527 */   addiu     $a1, $sp, 0x10
    /* 8B3C 8006BE9C B0AF0108 */  j          .L8006BEC0
    /* 8B40 8006BEA0 21984000 */   addu      $s3, $v0, $zero
  jlabel .L8006BEA4
    /* 8B44 8006BEA4 2120C002 */  addu       $a0, $s6, $zero
    /* 8B48 8006BEA8 32AE010C */  jal        Stg40_AiPathToTarget
    /* 8B4C 8006BEAC 1000A527 */   addiu     $a1, $sp, 0x10
    /* 8B50 8006BEB0 B0AF0108 */  j          .L8006BEC0
    /* 8B54 8006BEB4 21984000 */   addu      $s3, $v0, $zero
  .L8006BEB8:
    /* 8B58 8006BEB8 BEAF0108 */  j          .L8006BEF8
    /* 8B5C 8006BEBC 21A00002 */   addu      $s4, $s0, $zero
  .L8006BEC0:
    /* 8B60 8006BEC0 0D00601A */  blez       $s3, .L8006BEF8
    /* 8B64 8006BEC4 21880000 */   addu      $s1, $zero, $zero
    /* 8B68 8006BEC8 00401524 */  addiu      $s5, $zero, 0x4000
    /* 8B6C 8006BECC 1000B027 */  addiu      $s0, $sp, 0x10
  .L8006BED0:
    /* 8B70 8006BED0 00000486 */  lh         $a0, 0x0($s0)
    /* 8B74 8006BED4 02000586 */  lh         $a1, 0x2($s0)
    /* 8B78 8006BED8 F8C0010C */  jal        Stg40_GetCellFlags
    /* 8B7C 8006BEDC 00000000 */   nop
    /* 8B80 8006BEE0 20404230 */  andi       $v0, $v0, 0x4020
    /* 8B84 8006BEE4 F4FF5510 */  beq        $v0, $s5, .L8006BEB8
    /* 8B88 8006BEE8 01003126 */   addiu     $s1, $s1, 0x1
    /* 8B8C 8006BEEC 2A103302 */  slt        $v0, $s1, $s3
    /* 8B90 8006BEF0 F7FF4014 */  bnez       $v0, .L8006BED0
    /* 8B94 8006BEF4 04001026 */   addiu     $s0, $s0, 0x4
  .L8006BEF8:
    /* 8B98 8006BEF8 23008012 */  beqz       $s4, .L8006BF88
    /* 8B9C 8006BEFC 21100000 */   addu      $v0, $zero, $zero
    /* 8BA0 8006BF00 00008386 */  lh         $v1, 0x0($s4)
    /* 8BA4 8006BF04 00004486 */  lh         $a0, 0x0($s2)
    /* 8BA8 8006BF08 02008286 */  lh         $v0, 0x2($s4)
    /* 8BAC 8006BF0C 02004586 */  lh         $a1, 0x2($s2)
    /* 8BB0 8006BF10 23206400 */  subu       $a0, $v1, $a0
    /* 8BB4 8006BF14 24B9010C */  jal        Stg40_DeltaToOctant
    /* 8BB8 8006BF18 23284500 */   subu      $a1, $v0, $a1
    /* 8BBC 8006BF1C 00140200 */  sll        $v0, $v0, 16
    /* 8BC0 8006BF20 C3110200 */  sra        $v0, $v0, 7
    /* 8BC4 8006BF24 0E00C2A6 */  sh         $v0, 0xE($s6)
    /* 8BC8 8006BF28 00004296 */  lhu        $v0, 0x0($s2)
    /* 8BCC 8006BF2C 00000000 */  nop
    /* 8BD0 8006BF30 040042A6 */  sh         $v0, 0x4($s2)
    /* 8BD4 8006BF34 02004296 */  lhu        $v0, 0x2($s2)
    /* 8BD8 8006BF38 04004486 */  lh         $a0, 0x4($s2)
    /* 8BDC 8006BF3C 060042A6 */  sh         $v0, 0x6($s2)
    /* 8BE0 8006BF40 00008296 */  lhu        $v0, 0x0($s4)
    /* 8BE4 8006BF44 06004586 */  lh         $a1, 0x6($s2)
    /* 8BE8 8006BF48 000042A6 */  sh         $v0, 0x0($s2)
    /* 8BEC 8006BF4C 02008396 */  lhu        $v1, 0x2($s4)
    /* 8BF0 8006BF50 0C000224 */  addiu      $v0, $zero, 0xC
    /* 8BF4 8006BF54 0A0042A6 */  sh         $v0, 0xA($s2)
    /* 8BF8 8006BF58 080042A6 */  sh         $v0, 0x8($s2)
    /* 8BFC 8006BF5C 5DC2010C */  jal        Stg40_ClearCellOccupied
    /* 8C00 8006BF60 020043A6 */   sh        $v1, 0x2($s2)
    /* 8C04 8006BF64 00004486 */  lh         $a0, 0x0($s2)
    /* 8C08 8006BF68 02004586 */  lh         $a1, 0x2($s2)
    /* 8C0C 8006BF6C 3FC2010C */  jal        Stg40_SetCellOccupied
    /* 8C10 8006BF70 01000624 */   addiu     $a2, $zero, 0x1
    /* 8C14 8006BF74 01000224 */  addiu      $v0, $zero, 0x1
    /* 8C18 8006BF78 21184000 */  addu       $v1, $v0, $zero
    /* 8C1C 8006BF7C E2AF0108 */  j          .L8006BF88
    /* 8C20 8006BF80 1C0043A6 */   sh        $v1, 0x1C($s2)
  jlabel .L8006BF84
    /* 8C24 8006BF84 21100000 */  addu       $v0, $zero, $zero
  .L8006BF88:
    /* 8C28 8006BF88 3C00BF8F */  lw         $ra, 0x3C($sp)
    /* 8C2C 8006BF8C 3800B68F */  lw         $s6, 0x38($sp)
    /* 8C30 8006BF90 3400B58F */  lw         $s5, 0x34($sp)
    /* 8C34 8006BF94 3000B48F */  lw         $s4, 0x30($sp)
    /* 8C38 8006BF98 2C00B38F */  lw         $s3, 0x2C($sp)
    /* 8C3C 8006BF9C 2800B28F */  lw         $s2, 0x28($sp)
    /* 8C40 8006BFA0 2400B18F */  lw         $s1, 0x24($sp)
    /* 8C44 8006BFA4 2000B08F */  lw         $s0, 0x20($sp)
    /* 8C48 8006BFA8 0800E003 */  jr         $ra
    /* 8C4C 8006BFAC 4000BD27 */   addiu     $sp, $sp, 0x40
endlabel Stg40_AiTryStep
