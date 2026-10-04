nonmatching Digi_GetModelListCount, 0x4C

glabel Digi_GetModelListCount
    /* F138 8001E938 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* F13C 8001E93C 1000BFAF */  sw         $ra, 0x10($sp)
    /* F140 8001E940 688E000C */  jal        Cd_GetFileEntry
    /* F144 8001E944 F801043C */   lui       $a0, (0x1F80000 >> 16)
    /* F148 8001E948 21184000 */  addu       $v1, $v0, $zero
    /* F14C 8001E94C 0400628C */  lw         $v0, 0x4($v1)
    /* F150 8001E950 587A0008 */  j          .L8001E960
    /* F154 8001E954 21200000 */   addu      $a0, $zero, $zero
  .L8001E958:
    /* F158 8001E958 0400628C */  lw         $v0, 0x4($v1)
    /* F15C 8001E95C 01008424 */  addiu      $a0, $a0, 0x1
  .L8001E960:
    /* F160 8001E960 42100200 */  srl        $v0, $v0, 1
    /* F164 8001E964 FF7F4230 */  andi       $v0, $v0, 0x7FFF
    /* F168 8001E968 FBFF4014 */  bnez       $v0, .L8001E958
    /* F16C 8001E96C 28006324 */   addiu     $v1, $v1, 0x28
    /* F170 8001E970 D8FF6324 */  addiu      $v1, $v1, -0x28
    /* F174 8001E974 1000BF8F */  lw         $ra, 0x10($sp)
    /* F178 8001E978 21108000 */  addu       $v0, $a0, $zero
    /* F17C 8001E97C 0800E003 */  jr         $ra
    /* F180 8001E980 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Digi_GetModelListCount
