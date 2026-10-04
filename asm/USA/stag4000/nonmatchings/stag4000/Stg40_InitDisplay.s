nonmatching Stg40_InitDisplay, 0x90

glabel Stg40_InitDisplay
    /* 3F8 80063758 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 3FC 8006375C 1400BFAF */  sw         $ra, 0x14($sp)
    /* 400 80063760 5C8E000C */  jal        Sys_SetFrameRate30
    /* 404 80063764 1000B0AF */   sw        $s0, 0x10($sp)
    /* 408 80063768 40010424 */  addiu      $a0, $zero, 0x140
    /* 40C 8006376C F0000524 */  addiu      $a1, $zero, 0xF0
    /* 410 80063770 21300000 */  addu       $a2, $zero, $zero
    /* 414 80063774 7870000C */  jal        Gpu_InitDoubleBuffer
    /* 418 80063778 2138C000 */   addu      $a3, $a2, $zero
    /* 41C 8006377C 21200000 */  addu       $a0, $zero, $zero
    /* 420 80063780 21288000 */  addu       $a1, $a0, $zero
    /* 424 80063784 6570000C */  jal        Gpu_SetBgClearColor
    /* 428 80063788 21308000 */   addu      $a2, $a0, $zero
    /* 42C 8006378C 4170000C */  jal        Gpu_ClearScreens
    /* 430 80063790 00000000 */   nop
    /* 434 80063794 3271000C */  jal        Gfx_FadeInFromBlack
    /* 438 80063798 20000424 */   addiu     $a0, $zero, 0x20
    /* 43C 8006379C 0100043C */  lui        $a0, (0x19000 >> 16)
    /* 440 800637A0 6C72000C */  jal        Gpu_AllocPacketBufs
    /* 444 800637A4 00908434 */   ori       $a0, $a0, (0x19000 & 0xFFFF)
    /* 448 800637A8 200E043C */  lui        $a0, (0xE200001 >> 16)
    /* 44C 800637AC 688E000C */  jal        Cd_GetFileEntry
    /* 450 800637B0 01008434 */   ori       $a0, $a0, (0xE200001 & 0xFFFF)
    /* 454 800637B4 200E043C */  lui        $a0, (0xE200002 >> 16)
    /* 458 800637B8 02008434 */  ori        $a0, $a0, (0xE200002 & 0xFFFF)
    /* 45C 800637BC 688E000C */  jal        Cd_GetFileEntry
    /* 460 800637C0 21804000 */   addu      $s0, $v0, $zero
    /* 464 800637C4 0000458C */  lw         $a1, 0x0($v0)
    /* 468 800637C8 0400468C */  lw         $a2, 0x4($v0)
    /* 46C 800637CC 0800478C */  lw         $a3, 0x8($v0)
    /* 470 800637D0 FF9D010C */  jal        Stg40_SetLights
    /* 474 800637D4 21200002 */   addu      $a0, $s0, $zero
    /* 478 800637D8 1400BF8F */  lw         $ra, 0x14($sp)
    /* 47C 800637DC 1000B08F */  lw         $s0, 0x10($sp)
    /* 480 800637E0 0800E003 */  jr         $ra
    /* 484 800637E4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Stg40_InitDisplay
