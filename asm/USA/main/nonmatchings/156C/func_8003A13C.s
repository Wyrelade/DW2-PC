nonmatching func_8003A13C, 0x70

glabel func_8003A13C
    /* 2A93C 8003A13C 0580023C */  lui        $v0, %hi(D_8004FE18)
    /* 2A940 8003A140 18FE428C */  lw         $v0, %lo(D_8004FE18)($v0)
    /* 2A944 8003A144 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2A948 8003A148 14004014 */  bnez       $v0, .L8003A19C
    /* 2A94C 8003A14C 1000BFAF */   sw        $ra, 0x10($sp)
    /* 2A950 8003A150 01000224 */  addiu      $v0, $zero, 0x1
    /* 2A954 8003A154 0580013C */  lui        $at, %hi(D_8004FE18)
    /* 2A958 8003A158 F19B000C */  jal        EnterCriticalSection
    /* 2A95C 8003A15C 18FE22AC */   sw        $v0, %lo(D_8004FE18)($at)
    /* 2A960 8003A160 0480043C */  lui        $a0, %hi(func_8003A614)
    /* 2A964 8003A164 45EB000C */  jal        _SpuDataCallback
    /* 2A968 8003A168 14A68424 */   addiu     $a0, $a0, %lo(func_8003A614)
    /* 2A96C 8003A16C 00F0043C */  lui        $a0, (0xF0000009 >> 16)
    /* 2A970 8003A170 09008434 */  ori        $a0, $a0, (0xF0000009 & 0xFFFF)
    /* 2A974 8003A174 20000524 */  addiu      $a1, $zero, 0x20
    /* 2A978 8003A178 00200624 */  addiu      $a2, $zero, 0x2000
    /* 2A97C 8003A17C 6DE8000C */  jal        OpenEvent
    /* 2A980 8003A180 21380000 */   addu      $a3, $zero, $zero
    /* 2A984 8003A184 21204000 */  addu       $a0, $v0, $zero
    /* 2A988 8003A188 0580013C */  lui        $at, %hi(D_8004FDB0)
    /* 2A98C 8003A18C 71E8000C */  jal        EnableEvent
    /* 2A990 8003A190 B0FD24AC */   sw        $a0, %lo(D_8004FDB0)($at)
    /* 2A994 8003A194 F59B000C */  jal        ExitCriticalSection
    /* 2A998 8003A198 00000000 */   nop
  .L8003A19C:
    /* 2A99C 8003A19C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 2A9A0 8003A1A0 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 2A9A4 8003A1A4 0800E003 */  jr         $ra
    /* 2A9A8 8003A1A8 00000000 */   nop
endlabel func_8003A13C
    /* 2A9AC 8003A1AC 00000000 */  nop
    /* 2A9B0 8003A1B0 00000000 */  nop
