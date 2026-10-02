nonmatching MemCardWriteData, 0xB8

glabel MemCardWriteData
    /* 2F078 8003E878 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2F07C 8003E87C 0680073C */  lui        $a3, %hi(D_80062F94)
    /* 2F080 8003E880 942FE724 */  addiu      $a3, $a3, %lo(D_80062F94)
    /* 2F084 8003E884 1000BFAF */  sw         $ra, 0x10($sp)
    /* 2F088 8003E888 0000E28C */  lw         $v0, 0x0($a3)
    /* 2F08C 8003E88C 00000000 */  nop
    /* 2F090 8003E890 04004104 */  bgez       $v0, .L8003E8A4
    /* 2F094 8003E894 21408000 */   addu      $t0, $a0, $zero
    /* 2F098 8003E898 0180043C */  lui        $a0, %hi(D_80010C98)
    /* 2F09C 8003E89C 45FA0008 */  j          .L8003E914
    /* 2F0A0 8003E8A0 980C8424 */   addiu     $a0, $a0, %lo(D_80010C98)
  .L8003E8A4:
    /* 2F0A4 8003E8A4 ECFFE28C */  lw         $v0, -0x14($a3)
    /* 2F0A8 8003E8A8 00000000 */  nop
    /* 2F0AC 8003E8AC 04004018 */  blez       $v0, .L8003E8C0
    /* 2F0B0 8003E8B0 ECFFE324 */   addiu     $v1, $a3, -0x14
    /* 2F0B4 8003E8B4 0180043C */  lui        $a0, %hi(D_80010B74)
    /* 2F0B8 8003E8B8 45FA0008 */  j          .L8003E914
    /* 2F0BC 8003E8BC 740B8424 */   addiu     $a0, $a0, %lo(D_80010B74)
  .L8003E8C0:
    /* 2F0C0 8003E8C0 7F00C230 */  andi       $v0, $a2, 0x7F
    /* 2F0C4 8003E8C4 04004010 */  beqz       $v0, .L8003E8D8
    /* 2F0C8 8003E8C8 7F00A230 */   andi      $v0, $a1, 0x7F
    /* 2F0CC 8003E8CC 0180043C */  lui        $a0, %hi(D_80010CBC)
    /* 2F0D0 8003E8D0 45FA0008 */  j          .L8003E914
    /* 2F0D4 8003E8D4 BC0C8424 */   addiu     $a0, $a0, %lo(D_80010CBC)
  .L8003E8D8:
    /* 2F0D8 8003E8D8 0C004014 */  bnez       $v0, .L8003E90C
    /* 2F0DC 8003E8DC 06000224 */   addiu     $v0, $zero, 0x6
    /* 2F0E0 8003E8E0 0480043C */  lui        $a0, %hi(Card_WriteDataTask)
    /* 2F0E4 8003E8E4 30E98424 */  addiu      $a0, $a0, %lo(Card_WriteDataTask)
    /* 2F0E8 8003E8E8 ECFFE2AC */  sw         $v0, -0x14($a3)
    /* 2F0EC 8003E8EC 040060AC */  sw         $zero, 0x4($v1)
    /* 2F0F0 8003E8F0 080060AC */  sw         $zero, 0x8($v1)
    /* 2F0F4 8003E8F4 180065AC */  sw         $a1, 0x18($v1)
    /* 2F0F8 8003E8F8 200068AC */  sw         $t0, 0x20($v1)
    /* 2F0FC 8003E8FC 89FE000C */  jal        Card_PushTask
    /* 2F100 8003E900 1C0066AC */   sw        $a2, 0x1C($v1)
    /* 2F104 8003E904 48FA0008 */  j          .L8003E920
    /* 2F108 8003E908 01000224 */   addiu     $v0, $zero, 0x1
  .L8003E90C:
    /* 2F10C 8003E90C 0180043C */  lui        $a0, %hi(D_80010CE8)
    /* 2F110 8003E910 E80C8424 */  addiu      $a0, $a0, %lo(D_80010CE8)
  .L8003E914:
    /* 2F114 8003E914 05A8000C */  jal        printf
    /* 2F118 8003E918 00000000 */   nop
    /* 2F11C 8003E91C 21100000 */  addu       $v0, $zero, $zero
  .L8003E920:
    /* 2F120 8003E920 1000BF8F */  lw         $ra, 0x10($sp)
    /* 2F124 8003E924 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 2F128 8003E928 0800E003 */  jr         $ra
    /* 2F12C 8003E92C 00000000 */   nop
endlabel MemCardWriteData
