nonmatching Stg10_StrSetDefDecEnv, 0x88

glabel Stg10_StrSetDefDecEnv
    /* B50 80063EB0 0680023C */  lui        $v0, %hi(Stg10_VlcBuf0)
    /* B54 80063EB4 0680033C */  lui        $v1, %hi(Stg10_VlcBuf1)
    /* B58 80063EB8 0680093C */  lui        $t1, %hi(D_8005F770)
    /* B5C 80063EBC EC61428C */  lw         $v0, %lo(Stg10_VlcBuf0)($v0)
    /* B60 80063EC0 F061638C */  lw         $v1, %lo(Stg10_VlcBuf1)($v1)
    /* B64 80063EC4 70F72925 */  addiu      $t1, $t1, %lo(D_8005F770)
    /* B68 80063EC8 000082AC */  sw         $v0, 0x0($a0)
    /* B6C 80063ECC 0680023C */  lui        $v0, %hi(Stg10_ImgBuf0)
    /* B70 80063ED0 040083AC */  sw         $v1, 0x4($a0)
    /* B74 80063ED4 0680033C */  lui        $v1, %hi(Stg10_ImgBuf1)
    /* B78 80063ED8 F461488C */  lw         $t0, %lo(Stg10_ImgBuf0)($v0)
    /* B7C 80063EDC 2800228D */  lw         $v0, 0x28($t1)
    /* B80 80063EE0 F861638C */  lw         $v1, %lo(Stg10_ImgBuf1)($v1)
    /* B84 80063EE4 01004238 */  xori       $v0, $v0, 0x1
    /* B88 80063EE8 0C0088AC */  sw         $t0, 0xC($a0)
    /* B8C 80063EEC 100083AC */  sw         $v1, 0x10($a0)
    /* B90 80063EF0 080082AC */  sw         $v0, 0x8($a0)
    /* B94 80063EF4 1000A38F */  lw         $v1, 0x10($sp)
    /* B98 80063EF8 2800228D */  lw         $v0, 0x28($t1)
    /* B9C 80063EFC 180085A4 */  sh         $a1, 0x18($a0)
    /* BA0 80063F00 1A0086A4 */  sh         $a2, 0x1A($a0)
    /* BA4 80063F04 200087A4 */  sh         $a3, 0x20($a0)
    /* BA8 80063F08 01004238 */  xori       $v0, $v0, 0x1
    /* BAC 80063F0C 220083A4 */  sh         $v1, 0x22($a0)
    /* BB0 80063F10 140082AC */  sw         $v0, 0x14($a0)
    /* BB4 80063F14 2800238D */  lw         $v1, 0x28($t1)
    /* BB8 80063F18 18000224 */  addiu      $v0, $zero, 0x18
    /* BBC 80063F1C 2C0085A4 */  sh         $a1, 0x2C($a0)
    /* BC0 80063F20 2E0086A4 */  sh         $a2, 0x2E($a0)
    /* BC4 80063F24 300082A4 */  sh         $v0, 0x30($a0)
    /* BC8 80063F28 340080AC */  sw         $zero, 0x34($a0)
    /* BCC 80063F2C 01006338 */  xori       $v1, $v1, 0x1
    /* BD0 80063F30 0800E003 */  jr         $ra
    /* BD4 80063F34 280083AC */   sw        $v1, 0x28($a0)
endlabel Stg10_StrSetDefDecEnv
