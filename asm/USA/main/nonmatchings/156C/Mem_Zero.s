nonmatching Mem_Zero, 0x5C

glabel Mem_Zero
    /* 1378C 80022F8C 0300A230 */  andi       $v0, $a1, 0x3
    /* 13790 80022F90 0B004010 */  beqz       $v0, .L80022FC0
    /* 13794 80022F94 00000000 */   nop
    /* 13798 80022F98 0700A018 */  blez       $a1, .L80022FB8
    /* 1379C 80022F9C 21180000 */   addu      $v1, $zero, $zero
    /* 137A0 80022FA0 21108300 */  addu       $v0, $a0, $v1
  .L80022FA4:
    /* 137A4 80022FA4 000040A0 */  sb         $zero, 0x0($v0)
    /* 137A8 80022FA8 01006324 */  addiu      $v1, $v1, 0x1
    /* 137AC 80022FAC 2A106500 */  slt        $v0, $v1, $a1
    /* 137B0 80022FB0 FCFF4014 */  bnez       $v0, .L80022FA4
    /* 137B4 80022FB4 21108300 */   addu      $v0, $a0, $v1
  .L80022FB8:
    /* 137B8 80022FB8 0800E003 */  jr         $ra
    /* 137BC 80022FBC 00000000 */   nop
  .L80022FC0:
    /* 137C0 80022FC0 83280500 */  sra        $a1, $a1, 2
    /* 137C4 80022FC4 FCFFA018 */  blez       $a1, .L80022FB8
    /* 137C8 80022FC8 21180000 */   addu      $v1, $zero, $zero
  .L80022FCC:
    /* 137CC 80022FCC 000080AC */  sw         $zero, 0x0($a0)
    /* 137D0 80022FD0 01006324 */  addiu      $v1, $v1, 0x1
    /* 137D4 80022FD4 2A106500 */  slt        $v0, $v1, $a1
    /* 137D8 80022FD8 FCFF4014 */  bnez       $v0, .L80022FCC
    /* 137DC 80022FDC 04008424 */   addiu     $a0, $a0, 0x4
    /* 137E0 80022FE0 0800E003 */  jr         $ra
    /* 137E4 80022FE4 00000000 */   nop
endlabel Mem_Zero
