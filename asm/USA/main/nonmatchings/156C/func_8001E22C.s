nonmatching func_8001E22C, 0x60

glabel func_8001E22C
    /* EA2C 8001E22C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* EA30 8001E230 1000B0AF */  sw         $s0, 0x10($sp)
    /* EA34 8001E234 21808000 */  addu       $s0, $a0, $zero
    /* EA38 8001E238 1400BFAF */  sw         $ra, 0x14($sp)
    /* EA3C 8001E23C 688E000C */  jal        Cd_GetFileEntry
    /* EA40 8001E240 5E04043C */   lui       $a0, (0x45E0000 >> 16)
    /* EA44 8001E244 21204000 */  addu       $a0, $v0, $zero
    /* EA48 8001E248 0900001A */  blez       $s0, .L8001E270
    /* EA4C 8001E24C 21180000 */   addu      $v1, $zero, $zero
  .L8001E250:
    /* EA50 8001E250 00008284 */  lh         $v0, 0x0($a0)
    /* EA54 8001E254 00000000 */  nop
    /* EA58 8001E258 05004010 */  beqz       $v0, .L8001E270
    /* EA5C 8001E25C 00000000 */   nop
    /* EA60 8001E260 01006324 */  addiu      $v1, $v1, 0x1
    /* EA64 8001E264 2A107000 */  slt        $v0, $v1, $s0
    /* EA68 8001E268 F9FF4014 */  bnez       $v0, .L8001E250
    /* EA6C 8001E26C 10008424 */   addiu     $a0, $a0, 0x10
  .L8001E270:
    /* EA70 8001E270 02007014 */  bne        $v1, $s0, .L8001E27C
    /* EA74 8001E274 21100000 */   addu      $v0, $zero, $zero
    /* EA78 8001E278 00008284 */  lh         $v0, 0x0($a0)
  .L8001E27C:
    /* EA7C 8001E27C 1400BF8F */  lw         $ra, 0x14($sp)
    /* EA80 8001E280 1000B08F */  lw         $s0, 0x10($sp)
    /* EA84 8001E284 0800E003 */  jr         $ra
    /* EA88 8001E288 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8001E22C
