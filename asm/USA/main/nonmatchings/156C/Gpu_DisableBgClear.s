nonmatching Gpu_DisableBgClear, 0x14

glabel Gpu_DisableBgClear
    /* C9CC 8001C1CC 0680023C */  lui        $v0, %hi(Sys_State)
    /* C9D0 8001C1D0 70F74224 */  addiu      $v0, $v0, %lo(Sys_State)
    /* C9D4 8001C1D4 480040A0 */  sb         $zero, 0x48($v0)
    /* C9D8 8001C1D8 0800E003 */  jr         $ra
    /* C9DC 8001C1DC A40040A0 */   sb        $zero, 0xA4($v0)
endlabel Gpu_DisableBgClear
