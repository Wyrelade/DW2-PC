nonmatching func_8001E1D0, 0x5C

glabel func_8001E1D0
    /* E9D0 8001E1D0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* E9D4 8001E1D4 1000B0AF */  sw         $s0, 0x10($sp)
    /* E9D8 8001E1D8 21808000 */  addu       $s0, $a0, $zero
    /* E9DC 8001E1DC 1400BFAF */  sw         $ra, 0x14($sp)
    /* E9E0 8001E1E0 688E000C */  jal        Cd_GetFileEntry
    /* E9E4 8001E1E4 5E04043C */   lui       $a0, (0x45E0000 >> 16)
    /* E9E8 8001E1E8 21204000 */  addu       $a0, $v0, $zero
    /* E9EC 8001E1EC 82780008 */  j          .L8001E208
    /* E9F0 8001E1F0 21280000 */   addu      $a1, $zero, $zero
  .L8001E1F4:
    /* E9F4 8001E1F4 03140200 */  sra        $v0, $v0, 16
    /* E9F8 8001E1F8 08005010 */  beq        $v0, $s0, .L8001E21C
    /* E9FC 8001E1FC 2110A000 */   addu      $v0, $a1, $zero
    /* EA00 8001E200 10008424 */  addiu      $a0, $a0, 0x10
    /* EA04 8001E204 0100A524 */  addiu      $a1, $a1, 0x1
  .L8001E208:
    /* EA08 8001E208 00008284 */  lh         $v0, 0x0($a0)
    /* EA0C 8001E20C 00008394 */  lhu        $v1, 0x0($a0)
    /* EA10 8001E210 F8FF4014 */  bnez       $v0, .L8001E1F4
    /* EA14 8001E214 00140300 */   sll       $v0, $v1, 16
    /* EA18 8001E218 21100000 */  addu       $v0, $zero, $zero
  .L8001E21C:
    /* EA1C 8001E21C 1400BF8F */  lw         $ra, 0x14($sp)
    /* EA20 8001E220 1000B08F */  lw         $s0, 0x10($sp)
    /* EA24 8001E224 0800E003 */  jr         $ra
    /* EA28 8001E228 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8001E1D0
