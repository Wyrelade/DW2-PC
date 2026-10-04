nonmatching Stg30_PrepareAction, 0x64

glabel Stg30_PrepareAction
    /* 97C8 8006CB28 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 97CC 8006CB2C 0780033C */  lui        $v1, %hi(Stg30_Battle)
    /* 97D0 8006CB30 C03C6324 */  addiu      $v1, $v1, %lo(Stg30_Battle)
    /* 97D4 8006CB34 00110400 */  sll        $v0, $a0, 4
    /* 97D8 8006CB38 21104300 */  addu       $v0, $v0, $v1
    /* 97DC 8006CB3C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 97E0 8006CB40 AC02438C */  lw         $v1, 0x2AC($v0)
    /* 97E4 8006CB44 00000000 */  nop
    /* 97E8 8006CB48 05006018 */  blez       $v1, .L8006CB60
    /* 97EC 8006CB4C 05006228 */   slti      $v0, $v1, 0x5
    /* 97F0 8006CB50 03004014 */  bnez       $v0, .L8006CB60
    /* 97F4 8006CB54 05000224 */   addiu     $v0, $zero, 0x5
    /* 97F8 8006CB58 05006210 */  beq        $v1, $v0, .L8006CB70
    /* 97FC 8006CB5C 00000000 */   nop
  .L8006CB60:
    /* 9800 8006CB60 F6AE010C */  jal        Stg30_BuildSkillScript
    /* 9804 8006CB64 00000000 */   nop
    /* 9808 8006CB68 DFB20108 */  j          .L8006CB7C
    /* 980C 8006CB6C 01000224 */   addiu     $v0, $zero, 0x1
  .L8006CB70:
    /* 9810 8006CB70 8FB2010C */  jal        Stg30_BuildGuardScript
    /* 9814 8006CB74 00000000 */   nop
    /* 9818 8006CB78 01000224 */  addiu      $v0, $zero, 0x1
  .L8006CB7C:
    /* 981C 8006CB7C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 9820 8006CB80 00000000 */  nop
    /* 9824 8006CB84 0800E003 */  jr         $ra
    /* 9828 8006CB88 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Stg30_PrepareAction
