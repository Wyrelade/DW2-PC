nonmatching func_8001EB58, 0xA8

glabel func_8001EB58
    /* F358 8001EB58 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* F35C 8001EB5C 1000B0AF */  sw         $s0, 0x10($sp)
    /* F360 8001EB60 21808000 */  addu       $s0, $a0, $zero
    /* F364 8001EB64 C3271000 */  sra        $a0, $s0, 31
    /* F368 8001EB68 23100402 */  subu       $v0, $s0, $a0
    /* F36C 8001EB6C 43180200 */  sra        $v1, $v0, 1
    /* F370 8001EB70 0600022A */  slti       $v0, $s0, 0x6
    /* F374 8001EB74 08004010 */  beqz       $v0, .L8001EB98
    /* F378 8001EB78 1400BFAF */   sw        $ra, 0x14($sp)
    /* F37C 8001EB7C 5555023C */  lui        $v0, (0x55555556 >> 16)
    /* F380 8001EB80 56554234 */  ori        $v0, $v0, (0x55555556 & 0xFFFF)
    /* F384 8001EB84 18000202 */  mult       $s0, $v0
    /* F388 8001EB88 10280000 */  mfhi       $a1
    /* F38C 8001EB8C 2310A400 */  subu       $v0, $a1, $a0
    /* F390 8001EB90 FC7A0008 */  j          .L8001EBF0
    /* F394 8001EB94 0D004224 */   addiu     $v0, $v0, 0xD
  .L8001EB98:
    /* F398 8001EB98 1200022A */  slti       $v0, $s0, 0x12
    /* F39C 8001EB9C 14004014 */  bnez       $v0, .L8001EBF0
    /* F3A0 8001EBA0 0E006224 */   addiu     $v0, $v1, 0xE
    /* F3A4 8001EBA4 1C00022A */  slti       $v0, $s0, 0x1C
    /* F3A8 8001EBA8 10004014 */  bnez       $v0, .L8001EBEC
    /* F3AC 8001EBAC 00000000 */   nop
    /* F3B0 8001EBB0 448E000C */  jal        Rand_Next
    /* F3B4 8001EBB4 00000000 */   nop
    /* F3B8 8001EBB8 FFFF4230 */  andi       $v0, $v0, 0xFFFF
    /* F3BC 8001EBBC AAAA033C */  lui        $v1, (0xAAAAAAAB >> 16)
    /* F3C0 8001EBC0 ABAA6334 */  ori        $v1, $v1, (0xAAAAAAAB & 0xFFFF)
    /* F3C4 8001EBC4 19004300 */  multu      $v0, $v1
    /* F3C8 8001EBC8 10280000 */  mfhi       $a1
    /* F3CC 8001EBCC 42200500 */  srl        $a0, $a1, 1
    /* F3D0 8001EBD0 40180400 */  sll        $v1, $a0, 1
    /* F3D4 8001EBD4 21186400 */  addu       $v1, $v1, $a0
    /* F3D8 8001EBD8 23104300 */  subu       $v0, $v0, $v1
    /* F3DC 8001EBDC FFFF4230 */  andi       $v0, $v0, 0xFFFF
    /* F3E0 8001EBE0 02004224 */  addiu      $v0, $v0, 0x2
    /* F3E4 8001EBE4 FC7A0008 */  j          .L8001EBF0
    /* F3E8 8001EBE8 21100202 */   addu      $v0, $s0, $v0
  .L8001EBEC:
    /* F3EC 8001EBEC 11006224 */  addiu      $v0, $v1, 0x11
  .L8001EBF0:
    /* F3F0 8001EBF0 1400BF8F */  lw         $ra, 0x14($sp)
    /* F3F4 8001EBF4 1000B08F */  lw         $s0, 0x10($sp)
    /* F3F8 8001EBF8 0800E003 */  jr         $ra
    /* F3FC 8001EBFC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8001EB58
