nonmatching func_8003A054, 0xE8

glabel func_8003A054
    /* 2A854 8003A054 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2A858 8003A058 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2A85C 8003A05C 1400BFAF */  sw         $ra, 0x14($sp)
    /* 2A860 8003A060 35C3000C */  jal        ResetCallback
    /* 2A864 8003A064 21808000 */   addu      $s0, $a0, $zero
    /* 2A868 8003A068 75E8000C */  jal        _spu_init
    /* 2A86C 8003A06C 21200002 */   addu      $a0, $s0, $zero
    /* 2A870 8003A070 08000016 */  bnez       $s0, .L8003A094
    /* 2A874 8003A074 00C00434 */   ori       $a0, $zero, 0xC000
    /* 2A878 8003A078 17000324 */  addiu      $v1, $zero, 0x17
    /* 2A87C 8003A07C 0580023C */  lui        $v0, %hi(D_8004FE12)
    /* 2A880 8003A080 12FE4224 */  addiu      $v0, $v0, %lo(D_8004FE12)
  .L8003A084:
    /* 2A884 8003A084 000044A4 */  sh         $a0, 0x0($v0)
    /* 2A888 8003A088 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 2A88C 8003A08C FDFF6104 */  bgez       $v1, .L8003A084
    /* 2A890 8003A090 FEFF4224 */   addiu     $v0, $v0, -0x2
  .L8003A094:
    /* 2A894 8003A094 4FE8000C */  jal        SpuStart
    /* 2A898 8003A098 00000000 */   nop
    /* 2A89C 8003A09C D1000424 */  addiu      $a0, $zero, 0xD1
    /* 2A8A0 8003A0A0 0580023C */  lui        $v0, %hi(D_8004FDCC)
    /* 2A8A4 8003A0A4 CCFD4224 */  addiu      $v0, $v0, %lo(D_8004FDCC)
    /* 2A8A8 8003A0A8 0580053C */  lui        $a1, %hi(D_800503B8)
    /* 2A8AC 8003A0AC B803A58C */  lw         $a1, %lo(D_800503B8)($a1)
    /* 2A8B0 8003A0B0 0580013C */  lui        $at, %hi(D_8004FDBC)
    /* 2A8B4 8003A0B4 BCFD20AC */  sw         $zero, %lo(D_8004FDBC)($at)
    /* 2A8B8 8003A0B8 0580013C */  lui        $at, %hi(D_8004FDC0)
    /* 2A8BC 8003A0BC C0FD20AC */  sw         $zero, %lo(D_8004FDC0)($at)
    /* 2A8C0 8003A0C0 000040AC */  sw         $zero, 0x0($v0)
    /* 2A8C4 8003A0C4 040040A4 */  sh         $zero, 0x4($v0)
    /* 2A8C8 8003A0C8 060040A4 */  sh         $zero, 0x6($v0)
    /* 2A8CC 8003A0CC 080040AC */  sw         $zero, 0x8($v0)
    /* 2A8D0 8003A0D0 0C0040AC */  sw         $zero, 0xC($v0)
    /* 2A8D4 8003A0D4 0580013C */  lui        $at, %hi(D_8004FDC4)
    /* 2A8D8 8003A0D8 C4FD25AC */  sw         $a1, %lo(D_8004FDC4)($at)
    /* 2A8DC 8003A0DC B8EA000C */  jal        _spu_FsetRXX
    /* 2A8E0 8003A0E0 21300000 */   addu      $a2, $zero, $zero
    /* 2A8E4 8003A0E4 0580013C */  lui        $at, %hi(D_8004FE88)
    /* 2A8E8 8003A0E8 88FE20AC */  sw         $zero, %lo(D_8004FE88)($at)
    /* 2A8EC 8003A0EC 0580013C */  lui        $at, %hi(D_8004FE8C)
    /* 2A8F0 8003A0F0 8CFE20AC */  sw         $zero, %lo(D_8004FE8C)($at)
    /* 2A8F4 8003A0F4 0580013C */  lui        $at, %hi(Spu_MemList)
    /* 2A8F8 8003A0F8 90FE20AC */  sw         $zero, %lo(Spu_MemList)($at)
    /* 2A8FC 8003A0FC 0580013C */  lui        $at, %hi(D_8004FDB8)
    /* 2A900 8003A100 B8FD20AC */  sw         $zero, %lo(D_8004FDB8)($at)
    /* 2A904 8003A104 0580013C */  lui        $at, %hi(D_8004FE44)
    /* 2A908 8003A108 44FE20AC */  sw         $zero, %lo(D_8004FE44)($at)
    /* 2A90C 8003A10C 0580013C */  lui        $at, %hi(D_8004FDB4)
    /* 2A910 8003A110 B4FD20AC */  sw         $zero, %lo(D_8004FDB4)($at)
    /* 2A914 8003A114 0580013C */  lui        $at, %hi(D_8004FDE0)
    /* 2A918 8003A118 E0FD20AC */  sw         $zero, %lo(D_8004FDE0)($at)
    /* 2A91C 8003A11C 0580013C */  lui        $at, %hi(D_8004FDDC)
    /* 2A920 8003A120 DCFD20AC */  sw         $zero, %lo(D_8004FDDC)($at)
    /* 2A924 8003A124 0580013C */  lui        $at, %hi(D_8004FE14)
    /* 2A928 8003A128 14FE20AC */  sw         $zero, %lo(D_8004FE14)($at)
    /* 2A92C 8003A12C 1400BF8F */  lw         $ra, 0x14($sp)
    /* 2A930 8003A130 1000B08F */  lw         $s0, 0x10($sp)
    /* 2A934 8003A134 0800E003 */  jr         $ra
    /* 2A938 8003A138 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8003A054
