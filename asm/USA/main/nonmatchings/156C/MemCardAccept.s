nonmatching MemCardAccept, 0x68

glabel MemCardAccept
    /* 2E934 8003E134 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2E938 8003E138 0680033C */  lui        $v1, %hi(D_80062F80)
    /* 2E93C 8003E13C 802F6324 */  addiu      $v1, $v1, %lo(D_80062F80)
    /* 2E940 8003E140 1000BFAF */  sw         $ra, 0x10($sp)
    /* 2E944 8003E144 0000628C */  lw         $v0, 0x0($v1)
    /* 2E948 8003E148 00000000 */  nop
    /* 2E94C 8003E14C 0B00401C */  bgtz       $v0, .L8003E17C
    /* 2E950 8003E150 21288000 */   addu      $a1, $a0, $zero
    /* 2E954 8003E154 0480043C */  lui        $a0, %hi(Card_AcceptTask)
    /* 2E958 8003E158 9CE18424 */  addiu      $a0, $a0, %lo(Card_AcceptTask)
    /* 2E95C 8003E15C 02000224 */  addiu      $v0, $zero, 0x2
    /* 2E960 8003E160 000062AC */  sw         $v0, 0x0($v1)
    /* 2E964 8003E164 040060AC */  sw         $zero, 0x4($v1)
    /* 2E968 8003E168 080060AC */  sw         $zero, 0x8($v1)
    /* 2E96C 8003E16C 89FE000C */  jal        Card_PushTask
    /* 2E970 8003E170 100065AC */   sw        $a1, 0x10($v1)
    /* 2E974 8003E174 63F80008 */  j          .L8003E18C
    /* 2E978 8003E178 01000224 */   addiu     $v0, $zero, 0x1
  .L8003E17C:
    /* 2E97C 8003E17C 0180043C */  lui        $a0, %hi(D_80010B74)
    /* 2E980 8003E180 05A8000C */  jal        printf
    /* 2E984 8003E184 740B8424 */   addiu     $a0, $a0, %lo(D_80010B74)
    /* 2E988 8003E188 21100000 */  addu       $v0, $zero, $zero
  .L8003E18C:
    /* 2E98C 8003E18C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 2E990 8003E190 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 2E994 8003E194 0800E003 */  jr         $ra
    /* 2E998 8003E198 00000000 */   nop
endlabel MemCardAccept
