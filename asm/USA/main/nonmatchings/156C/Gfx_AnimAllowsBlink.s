nonmatching Gfx_AnimAllowsBlink, 0x3C

glabel Gfx_AnimAllowsBlink
    /* 10170 8001F970 64000224 */  addiu      $v0, $zero, 0x64
    /* 10174 8001F974 05008210 */  beq        $a0, $v0, .L8001F98C
    /* 10178 8001F978 0A000224 */   addiu     $v0, $zero, 0xA
    /* 1017C 8001F97C 03008210 */  beq        $a0, $v0, .L8001F98C
    /* 10180 8001F980 14000224 */   addiu     $v0, $zero, 0x14
    /* 10184 8001F984 03008214 */  bne        $a0, $v0, .L8001F994
    /* 10188 8001F988 15000224 */   addiu     $v0, $zero, 0x15
  .L8001F98C:
    /* 1018C 8001F98C 0800E003 */  jr         $ra
    /* 10190 8001F990 21100000 */   addu      $v0, $zero, $zero
  .L8001F994:
    /* 10194 8001F994 03008210 */  beq        $a0, $v0, .L8001F9A4
    /* 10198 8001F998 16008238 */   xori      $v0, $a0, 0x16
    /* 1019C 8001F99C 0800E003 */  jr         $ra
    /* 101A0 8001F9A0 2B100200 */   sltu      $v0, $zero, $v0
  .L8001F9A4:
    /* 101A4 8001F9A4 0800E003 */  jr         $ra
    /* 101A8 8001F9A8 21100000 */   addu      $v0, $zero, $zero
endlabel Gfx_AnimAllowsBlink
