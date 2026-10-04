nonmatching Gpu_ResetPrimBuf, 0x28

glabel Gpu_ResetPrimBuf
    /* D188 8001C988 0680043C */  lui        $a0, %hi(Sys_State)
    /* D18C 8001C98C 70F78424 */  addiu      $a0, $a0, %lo(Sys_State)
    /* D190 8001C990 0480033C */  lui        $v1, %hi(Gpu_PrimBufs)
    /* D194 8001C994 2800828C */  lw         $v0, 0x28($a0)
    /* D198 8001C998 70166324 */  addiu      $v1, $v1, %lo(Gpu_PrimBufs)
    /* D19C 8001C99C 80100200 */  sll        $v0, $v0, 2
    /* D1A0 8001C9A0 21104300 */  addu       $v0, $v0, $v1
    /* D1A4 8001C9A4 0000428C */  lw         $v0, 0x0($v0)
    /* D1A8 8001C9A8 0800E003 */  jr         $ra
    /* D1AC 8001C9AC 2C0082AC */   sw        $v0, 0x2C($a0)
endlabel Gpu_ResetPrimBuf
