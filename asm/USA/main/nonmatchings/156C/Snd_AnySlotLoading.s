nonmatching Snd_AnySlotLoading, 0x40

glabel Snd_AnySlotLoading
    /* AB00 8001A300 21280000 */  addu       $a1, $zero, $zero
    /* AB04 8001A304 2120A000 */  addu       $a0, $a1, $zero
    /* AB08 8001A308 0580023C */  lui        $v0, %hi(Snd_Slots)
    /* AB0C 8001A30C 484C4324 */  addiu      $v1, $v0, %lo(Snd_Slots)
  .L8001A310:
    /* AB10 8001A310 0400628C */  lw         $v0, 0x4($v1)
    /* AB14 8001A314 00000000 */  nop
    /* AB18 8001A318 02004010 */  beqz       $v0, .L8001A324
    /* AB1C 8001A31C 00000000 */   nop
    /* AB20 8001A320 01000524 */  addiu      $a1, $zero, 0x1
  .L8001A324:
    /* AB24 8001A324 0400A014 */  bnez       $a1, .L8001A338
    /* AB28 8001A328 01008424 */   addiu     $a0, $a0, 0x1
    /* AB2C 8001A32C 03008228 */  slti       $v0, $a0, 0x3
    /* AB30 8001A330 F7FF4014 */  bnez       $v0, .L8001A310
    /* AB34 8001A334 2C006324 */   addiu     $v1, $v1, 0x2C
  .L8001A338:
    /* AB38 8001A338 0800E003 */  jr         $ra
    /* AB3C 8001A33C 2110A000 */   addu      $v0, $a1, $zero
endlabel Snd_AnySlotLoading
