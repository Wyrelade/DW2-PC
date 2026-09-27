/* Handwritten function */
nonmatching func_80064D50, 0x30

glabel func_80064D50
    /* 19F0 80064D50 0680083C */  lui        $t0, %hi(D_800653A8)
    /* 19F4 80064D54 A8530825 */  addiu      $t0, $t0, %lo(D_800653A8)
    /* 19F8 80064D58 FFFF8120 */  addi       $at, $a0, -0x1 /* handwritten instruction */
    /* 19FC 80064D5C 04002018 */  blez       $at, .L80064D70
    /* 1A00 80064D60 0000028D */   lw        $v0, 0x0($t0)
    /* 1A04 80064D64 40080400 */  sll        $at, $a0, 1
    /* 1A08 80064D68 0800E003 */  jr         $ra
    /* 1A0C 80064D6C 000001AD */   sw        $at, 0x0($t0)
  .L80064D70:
    /* 1A10 80064D70 FF00013C */  lui        $at, (0xFFFFFF >> 16)
    /* 1A14 80064D74 FFFF2134 */  ori        $at, $at, (0xFFFFFF & 0xFFFF)
    /* 1A18 80064D78 0800E003 */  jr         $ra
    /* 1A1C 80064D7C 000001AD */   sw        $at, 0x0($t0)
endlabel func_80064D50
