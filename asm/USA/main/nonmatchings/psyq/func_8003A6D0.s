nonmatching func_8003A6D0, 0xA8

glabel func_8003A6D0
    /* 2AED0 8003A6D0 0580023C */  lui        $v0, %hi(D_8004FE28)
    /* 2AED4 8003A6D4 28FE428C */  lw         $v0, %lo(D_8004FE28)($v0)
    /* 2AED8 8003A6D8 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 2AEDC 8003A6DC 1400B1AF */  sw         $s1, 0x14($sp)
    /* 2AEE0 8003A6E0 21888000 */  addu       $s1, $a0, $zero
    /* 2AEE4 8003A6E4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2AEE8 8003A6E8 1800BFAF */  sw         $ra, 0x18($sp)
    /* 2AEEC 8003A6EC A60145A4 */  sh         $a1, 0x1A6($v0)
    /* 2AEF0 8003A6F0 2BEB000C */  jal        _spu_Fw1ts
    /* 2AEF4 8003A6F4 2180C000 */   addu      $s0, $a2, $zero
    /* 2AEF8 8003A6F8 0580033C */  lui        $v1, %hi(D_8004FE28)
    /* 2AEFC 8003A6FC 28FE638C */  lw         $v1, %lo(D_8004FE28)($v1)
    /* 2AF00 8003A700 00000000 */  nop
    /* 2AF04 8003A704 AA016294 */  lhu        $v0, 0x1AA($v1)
    /* 2AF08 8003A708 00000000 */  nop
    /* 2AF0C 8003A70C 30004234 */  ori        $v0, $v0, 0x30
    /* 2AF10 8003A710 AA0162A4 */  sh         $v0, 0x1AA($v1)
    /* 2AF14 8003A714 2BEB000C */  jal        _spu_Fw1ts
    /* 2AF18 8003A718 00841000 */   sll       $s0, $s0, 16
    /* 2AF1C 8003A71C 21EB000C */  jal        _spu_FsetDelayR
    /* 2AF20 8003A720 00000000 */   nop
    /* 2AF24 8003A724 0001043C */  lui        $a0, (0x1000200 >> 16)
    /* 2AF28 8003A728 00028434 */  ori        $a0, $a0, (0x1000200 & 0xFFFF)
    /* 2AF2C 8003A72C 0580023C */  lui        $v0, %hi(D_8004FE2C)
    /* 2AF30 8003A730 2CFE428C */  lw         $v0, %lo(D_8004FE2C)($v0)
    /* 2AF34 8003A734 00000000 */  nop
    /* 2AF38 8003A738 000051AC */  sw         $s1, 0x0($v0)
    /* 2AF3C 8003A73C 0580023C */  lui        $v0, %hi(D_8004FE30)
    /* 2AF40 8003A740 30FE428C */  lw         $v0, %lo(D_8004FE30)($v0)
    /* 2AF44 8003A744 10001036 */  ori        $s0, $s0, 0x10
    /* 2AF48 8003A748 000050AC */  sw         $s0, 0x0($v0)
    /* 2AF4C 8003A74C 0580033C */  lui        $v1, %hi(D_8004FE34)
    /* 2AF50 8003A750 34FE638C */  lw         $v1, %lo(D_8004FE34)($v1)
    /* 2AF54 8003A754 01000224 */  addiu      $v0, $zero, 0x1
    /* 2AF58 8003A758 0580013C */  lui        $at, %hi(D_8004FE78)
    /* 2AF5C 8003A75C 78FE22AC */  sw         $v0, %lo(D_8004FE78)($at)
    /* 2AF60 8003A760 000064AC */  sw         $a0, 0x0($v1)
    /* 2AF64 8003A764 1800BF8F */  lw         $ra, 0x18($sp)
    /* 2AF68 8003A768 1400B18F */  lw         $s1, 0x14($sp)
    /* 2AF6C 8003A76C 1000B08F */  lw         $s0, 0x10($sp)
    /* 2AF70 8003A770 0800E003 */  jr         $ra
    /* 2AF74 8003A774 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8003A6D0
