nonmatching func_8006ED5C, 0x2C

glabel func_8006ED5C
    /* B9FC 8006ED5C 0580023C */  lui        $v0, %hi(D_8005071C)
    /* BA00 8006ED60 1C07428C */  lw         $v0, %lo(D_8005071C)($v0)
    /* BA04 8006ED64 7F010324 */  addiu      $v1, $zero, 0x17F
    /* BA08 8006ED68 7C0E4224 */  addiu      $v0, $v0, 0xE7C
  .L8006ED6C:
    /* BA0C 8006ED6C FFFF6324 */  addiu      $v1, $v1, -0x1
    /* BA10 8006ED70 000040A0 */  sb         $zero, 0x0($v0)
    /* BA14 8006ED74 FDFF6104 */  bgez       $v1, .L8006ED6C
    /* BA18 8006ED78 01004224 */   addiu     $v0, $v0, 0x1
    /* BA1C 8006ED7C 0780023C */  lui        $v0, %hi(D_80072944)
    /* BA20 8006ED80 0800E003 */  jr         $ra
    /* BA24 8006ED84 442940AC */   sw        $zero, %lo(D_80072944)($v0)
endlabel func_8006ED5C
