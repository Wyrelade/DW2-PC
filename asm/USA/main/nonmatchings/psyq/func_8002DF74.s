nonmatching func_8002DF74, 0x8C

glabel func_8002DF74
    /* 1E774 8002DF74 0680023C */  lui        $v0, %hi(D_80061B20)
    /* 1E778 8002DF78 201B428C */  lw         $v0, %lo(D_80061B20)($v0)
    /* 1E77C 8002DF7C 0680033C */  lui        $v1, %hi(D_80061B38)
    /* 1E780 8002DF80 381B638C */  lw         $v1, %lo(D_80061B38)($v1)
    /* 1E784 8002DF84 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1E788 8002DF88 1000BFAF */  sw         $ra, 0x10($sp)
    /* 1E78C 8002DF8C 40110200 */  sll        $v0, $v0, 5
    /* 1E790 8002DF90 21186200 */  addu       $v1, $v1, $v0
    /* 1E794 8002DF94 02000224 */  addiu      $v0, $zero, 0x2
    /* 1E798 8002DF98 000062A4 */  sh         $v0, 0x0($v1)
    /* 1E79C 8002DF9C 0680063C */  lui        $a2, %hi(D_80061B40)
    /* 1E7A0 8002DFA0 401BC624 */  addiu      $a2, $a2, %lo(D_80061B40)
    /* 1E7A4 8002DFA4 1F006288 */  lwl        $v0, 0x1F($v1)
    /* 1E7A8 8002DFA8 1C006298 */  lwr        $v0, 0x1C($v1)
    /* 1E7AC 8002DFAC 00000000 */  nop
    /* 1E7B0 8002DFB0 0300C2A8 */  swl        $v0, 0x3($a2)
    /* 1E7B4 8002DFB4 0000C2B8 */  swr        $v0, 0x0($a2)
    /* 1E7B8 8002DFB8 0800628C */  lw         $v0, 0x8($v1)
    /* 1E7BC 8002DFBC 0680033C */  lui        $v1, %hi(D_80061B1C)
    /* 1E7C0 8002DFC0 1C1B638C */  lw         $v1, %lo(D_80061B1C)($v1)
    /* 1E7C4 8002DFC4 0680043C */  lui        $a0, %hi(D_80061B50)
    /* 1E7C8 8002DFC8 501B848C */  lw         $a0, %lo(D_80061B50)($a0)
    /* 1E7CC 8002DFCC 0680013C */  lui        $at, %hi(D_80061B44)
    /* 1E7D0 8002DFD0 441B22AC */  sw         $v0, %lo(D_80061B44)($at)
    /* 1E7D4 8002DFD4 0680013C */  lui        $at, %hi(D_80061B20)
    /* 1E7D8 8002DFD8 03008010 */  beqz       $a0, .L8002DFE8
    /* 1E7DC 8002DFDC 201B23AC */   sw        $v1, %lo(D_80061B20)($at)
    /* 1E7E0 8002DFE0 09F88000 */  jalr       $a0
    /* 1E7E4 8002DFE4 00000000 */   nop
  .L8002DFE8:
    /* 1E7E8 8002DFE8 0680013C */  lui        $at, %hi(D_80061B14)
    /* 1E7EC 8002DFEC 141B20AC */  sw         $zero, %lo(D_80061B14)($at)
    /* 1E7F0 8002DFF0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1E7F4 8002DFF4 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 1E7F8 8002DFF8 0800E003 */  jr         $ra
    /* 1E7FC 8002DFFC 00000000 */   nop
endlabel func_8002DF74
