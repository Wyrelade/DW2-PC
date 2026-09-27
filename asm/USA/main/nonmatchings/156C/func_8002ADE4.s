nonmatching func_8002ADE4, 0x68

glabel func_8002ADE4
    /* 1B5E4 8002ADE4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1B5E8 8002ADE8 0680023C */  lui        $v0, %hi(D_8006191C)
    /* 1B5EC 8002ADEC 1C194224 */  addiu      $v0, $v0, %lo(D_8006191C)
    /* 1B5F0 8002ADF0 2800A897 */  lhu        $t0, 0x28($sp)
    /* 1B5F4 8002ADF4 0680033C */  lui        $v1, %hi(D_8006196C)
    /* 1B5F8 8002ADF8 6C196324 */  addiu      $v1, $v1, %lo(D_8006196C)
    /* 1B5FC 8002ADFC 1000BFAF */  sw         $ra, 0x10($sp)
    /* 1B600 8002AE00 000040A4 */  sh         $zero, 0x0($v0)
    /* 1B604 8002AE04 020047A0 */  sb         $a3, 0x2($v0)
    /* 1B608 8002AE08 030040A0 */  sb         $zero, 0x3($v0)
    /* 1B60C 8002AE0C 040040A0 */  sb         $zero, 0x4($v0)
    /* 1B610 8002AE10 0100C230 */  andi       $v0, $a2, 0x1
    /* 1B614 8002AE14 0400C630 */  andi       $a2, $a2, 0x4
    /* 1B618 8002AE18 000064A4 */  sh         $a0, 0x0($v1)
    /* 1B61C 8002AE1C FFFF8430 */  andi       $a0, $a0, 0xFFFF
    /* 1B620 8002AE20 020065A4 */  sh         $a1, 0x2($v1)
    /* 1B624 8002AE24 FFFFA530 */  andi       $a1, $a1, 0xFFFF
    /* 1B628 8002AE28 0C0062A0 */  sb         $v0, 0xC($v1)
    /* 1B62C 8002AE2C 0680013C */  lui        $at, %hi(D_8006198E)
    /* 1B630 8002AE30 8E1926A4 */  sh         $a2, %lo(D_8006198E)($at)
    /* 1B634 8002AE34 93AB000C */  jal        func_8002AE4C
    /* 1B638 8002AE38 0D0068A0 */   sb        $t0, 0xD($v1)
    /* 1B63C 8002AE3C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1B640 8002AE40 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 1B644 8002AE44 0800E003 */  jr         $ra
    /* 1B648 8002AE48 00000000 */   nop
endlabel func_8002ADE4
