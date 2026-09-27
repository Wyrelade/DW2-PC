nonmatching Cd_ClearFileCache, 0x40

glabel Cd_ClearFileCache
    /* 14238 80023A38 0680023C */  lui        $v0, %hi(D_8005F8C8)
    /* 1423C 80023A3C C8F84424 */  addiu      $a0, $v0, %lo(D_8005F8C8)
    /* 14240 80023A40 21280000 */  addu       $a1, $zero, $zero
    /* 14244 80023A44 08008324 */  addiu      $v1, $a0, 0x8
  .L80023A48:
    /* 14248 80023A48 0100A524 */  addiu      $a1, $a1, 0x1
    /* 1424C 80023A4C FCFF60AC */  sw         $zero, -0x4($v1)
    /* 14250 80023A50 040060AC */  sw         $zero, 0x4($v1)
    /* 14254 80023A54 000080A4 */  sh         $zero, 0x0($a0)
    /* 14258 80023A58 FAFF60A4 */  sh         $zero, -0x6($v1)
    /* 1425C 80023A5C 000060AC */  sw         $zero, 0x0($v1)
    /* 14260 80023A60 10006324 */  addiu      $v1, $v1, 0x10
    /* 14264 80023A64 5000A228 */  slti       $v0, $a1, 0x50
    /* 14268 80023A68 F7FF4014 */  bnez       $v0, .L80023A48
    /* 1426C 80023A6C 10008424 */   addiu     $a0, $a0, 0x10
    /* 14270 80023A70 0800E003 */  jr         $ra
    /* 14274 80023A74 00000000 */   nop
endlabel Cd_ClearFileCache
