nonmatching Cd_FindCachedFile, 0x38

glabel Cd_FindCachedFile
    /* 14278 80023A78 0680023C */  lui        $v0, %hi(D_8005F8C8)
    /* 1427C 80023A7C C8F84324 */  addiu      $v1, $v0, %lo(D_8005F8C8)
    /* 14280 80023A80 21280000 */  addu       $a1, $zero, $zero
  .L80023A84:
    /* 14284 80023A84 0400628C */  lw         $v0, 0x4($v1)
    /* 14288 80023A88 00000000 */  nop
    /* 1428C 80023A8C 03004414 */  bne        $v0, $a0, .L80023A9C
    /* 14290 80023A90 0100A524 */   addiu     $a1, $a1, 0x1
    /* 14294 80023A94 0800E003 */  jr         $ra
    /* 14298 80023A98 21106000 */   addu      $v0, $v1, $zero
  .L80023A9C:
    /* 1429C 80023A9C 5000A228 */  slti       $v0, $a1, 0x50
    /* 142A0 80023AA0 F8FF4014 */  bnez       $v0, .L80023A84
    /* 142A4 80023AA4 10006324 */   addiu     $v1, $v1, 0x10
    /* 142A8 80023AA8 0800E003 */  jr         $ra
    /* 142AC 80023AAC 21100000 */   addu      $v0, $zero, $zero
endlabel Cd_FindCachedFile
