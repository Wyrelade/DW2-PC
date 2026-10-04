nonmatching Stg00_LineupDraw, 0x60

glabel Stg00_LineupDraw
    /* 32B8 80066618 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 32BC 8006661C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 32C0 80066620 21808000 */  addu       $s0, $a0, $zero
    /* 32C4 80066624 8901043C */  lui        $a0, (0x1890000 >> 16)
    /* 32C8 80066628 1800BFAF */  sw         $ra, 0x18($sp)
    /* 32CC 8006662C 688E000C */  jal        Cd_GetFileEntry
    /* 32D0 80066630 1400B1AF */   sw        $s1, 0x14($sp)
    /* 32D4 80066634 21884000 */  addu       $s1, $v0, $zero
    /* 32D8 80066638 2C00028E */  lw         $v0, 0x2C($s0)
    /* 32DC 8006663C 0780033C */  lui        $v1, %hi(Stg00_LineupWinMasks)
    /* 32E0 80066640 0C00428C */  lw         $v0, 0xC($v0)
    /* 32E4 80066644 848E6324 */  addiu      $v1, $v1, %lo(Stg00_LineupWinMasks)
    /* 32E8 80066648 80100200 */  sll        $v0, $v0, 2
    /* 32EC 8006664C 21104300 */  addu       $v0, $v0, $v1
    /* 32F0 80066650 0000458C */  lw         $a1, 0x0($v0)
    /* 32F4 80066654 4175000C */  jal        Gfx_HidePartsByMask
    /* 32F8 80066658 21202002 */   addu      $a0, $s1, $zero
    /* 32FC 8006665C 2176000C */  jal        Gfx_DrawParts
    /* 3300 80066660 21202002 */   addu      $a0, $s1, $zero
    /* 3304 80066664 1800BF8F */  lw         $ra, 0x18($sp)
    /* 3308 80066668 1400B18F */  lw         $s1, 0x14($sp)
    /* 330C 8006666C 1000B08F */  lw         $s0, 0x10($sp)
    /* 3310 80066670 0800E003 */  jr         $ra
    /* 3314 80066674 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Stg00_LineupDraw
