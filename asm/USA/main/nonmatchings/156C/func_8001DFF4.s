nonmatching func_8001DFF4, 0x54

glabel func_8001DFF4
    /* E7F4 8001DFF4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* E7F8 8001DFF8 1000B0AF */  sw         $s0, 0x10($sp)
    /* E7FC 8001DFFC 21808000 */  addu       $s0, $a0, $zero
    /* E800 8001E000 1400BFAF */  sw         $ra, 0x14($sp)
    /* E804 8001E004 688E000C */  jal        Cd_GetFileEntry
    /* E808 8001E008 5E04043C */   lui       $a0, (0x45E0000 >> 16)
    /* E80C 8001E00C 09780008 */  j          .L8001E024
    /* E810 8001E010 21204000 */   addu      $a0, $v0, $zero
  .L8001E014:
    /* E814 8001E014 03140200 */  sra        $v0, $v0, 16
    /* E818 8001E018 07005010 */  beq        $v0, $s0, .L8001E038
    /* E81C 8001E01C 21108000 */   addu      $v0, $a0, $zero
    /* E820 8001E020 10008424 */  addiu      $a0, $a0, 0x10
  .L8001E024:
    /* E824 8001E024 00008284 */  lh         $v0, 0x0($a0)
    /* E828 8001E028 00008394 */  lhu        $v1, 0x0($a0)
    /* E82C 8001E02C F9FF4014 */  bnez       $v0, .L8001E014
    /* E830 8001E030 00140300 */   sll       $v0, $v1, 16
    /* E834 8001E034 21100000 */  addu       $v0, $zero, $zero
  .L8001E038:
    /* E838 8001E038 1400BF8F */  lw         $ra, 0x14($sp)
    /* E83C 8001E03C 1000B08F */  lw         $s0, 0x10($sp)
    /* E840 8001E040 0800E003 */  jr         $ra
    /* E844 8001E044 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8001DFF4
