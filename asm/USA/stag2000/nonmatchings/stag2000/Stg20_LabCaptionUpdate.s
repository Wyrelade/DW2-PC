nonmatching Stg20_LabCaptionUpdate, 0x108

glabel Stg20_LabCaptionUpdate
    /* 5B50 80068EB0 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 5B54 80068EB4 1800B2AF */  sw         $s2, 0x18($sp)
    /* 5B58 80068EB8 21908000 */  addu       $s2, $a0, $zero
    /* 5B5C 80068EBC 01000224 */  addiu      $v0, $zero, 0x1
    /* 5B60 80068EC0 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 5B64 80068EC4 1400B1AF */  sw         $s1, 0x14($sp)
    /* 5B68 80068EC8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 5B6C 80068ECC 1000438E */  lw         $v1, 0x10($s2)
    /* 5B70 80068ED0 2C00518E */  lw         $s1, 0x2C($s2)
    /* 5B74 80068ED4 32006210 */  beq        $v1, $v0, .L80068FA0
    /* 5B78 80068ED8 02006228 */   slti      $v0, $v1, 0x2
    /* 5B7C 80068EDC 05004010 */  beqz       $v0, .L80068EF4
    /* 5B80 80068EE0 00000000 */   nop
    /* 5B84 80068EE4 08006010 */  beqz       $v1, .L80068F08
    /* 5B88 80068EE8 21202002 */   addu      $a0, $s1, $zero
    /* 5B8C 80068EEC E8A30108 */  j          .L80068FA0
    /* 5B90 80068EF0 00000000 */   nop
  .L80068EF4:
    /* 5B94 80068EF4 02000224 */  addiu      $v0, $zero, 0x2
    /* 5B98 80068EF8 25006210 */  beq        $v1, $v0, .L80068F90
    /* 5B9C 80068EFC 21202002 */   addu      $a0, $s1, $zero
    /* 5BA0 80068F00 E8A30108 */  j          .L80068FA0
    /* 5BA4 80068F04 00000000 */   nop
  .L80068F08:
    /* 5BA8 80068F08 2270000C */  jal        Mem_FillWordsNeg1
    /* 5BAC 80068F0C 02000524 */   addiu     $a1, $zero, 0x2
    /* 5BB0 80068F10 0780023C */  lui        $v0, %hi(D_800709D0)
    /* 5BB4 80068F14 D009428C */  lw         $v0, %lo(D_800709D0)($v0)
    /* 5BB8 80068F18 00000000 */  nop
    /* 5BBC 80068F1C 09004014 */  bnez       $v0, .L80068F44
    /* 5BC0 80068F20 03010524 */   addiu     $a1, $zero, 0x103
    /* 5BC4 80068F24 21202002 */  addu       $a0, $s1, $zero
    /* 5BC8 80068F28 02010524 */  addiu      $a1, $zero, 0x102
    /* 5BCC 80068F2C 0780033C */  lui        $v1, %hi(D_8007001C)
    /* 5BD0 80068F30 1C006224 */  addiu      $v0, $v1, %lo(D_8007001C)
    /* 5BD4 80068F34 02004794 */  lhu        $a3, 0x2($v0)
    /* 5BD8 80068F38 1C006294 */  lhu        $v0, %lo(D_8007001C)($v1)
    /* 5BDC 80068F3C DFA30108 */  j          .L80068F7C
    /* 5BE0 80068F40 21300000 */   addu      $a2, $zero, $zero
  .L80068F44:
    /* 5BE4 80068F44 21202002 */  addu       $a0, $s1, $zero
    /* 5BE8 80068F48 21300000 */  addu       $a2, $zero, $zero
    /* 5BEC 80068F4C 0780103C */  lui        $s0, %hi(D_8007001C)
    /* 5BF0 80068F50 1C001026 */  addiu      $s0, $s0, %lo(D_8007001C)
    /* 5BF4 80068F54 06000796 */  lhu        $a3, 0x6($s0)
    /* 5BF8 80068F58 04000296 */  lhu        $v0, 0x4($s0)
    /* 5BFC 80068F5C 003C0700 */  sll        $a3, $a3, 16
    /* 5C00 80068F60 F26F000C */  jal        Text_OpenById
    /* 5C04 80068F64 25384700 */   or        $a3, $v0, $a3
    /* 5C08 80068F68 04002426 */  addiu      $a0, $s1, 0x4
    /* 5C0C 80068F6C 04010524 */  addiu      $a1, $zero, 0x104
    /* 5C10 80068F70 21300000 */  addu       $a2, $zero, $zero
    /* 5C14 80068F74 0A000796 */  lhu        $a3, 0xA($s0)
    /* 5C18 80068F78 08000296 */  lhu        $v0, 0x8($s0)
  .L80068F7C:
    /* 5C1C 80068F7C 003C0700 */  sll        $a3, $a3, 16
    /* 5C20 80068F80 F26F000C */  jal        Text_OpenById
    /* 5C24 80068F84 25384700 */   or        $a3, $v0, $a3
    /* 5C28 80068F88 E6A30108 */  j          .L80068F98
    /* 5C2C 80068F8C 00000000 */   nop
  .L80068F90:
    /* 5C30 80068F90 2C70000C */  jal        Text_CloseArray
    /* 5C34 80068F94 02000524 */   addiu     $a1, $zero, 0x2
  .L80068F98:
    /* 5C38 80068F98 5145000C */  jal        Task_NextState0
    /* 5C3C 80068F9C 21204002 */   addu      $a0, $s2, $zero
  .L80068FA0:
    /* 5C40 80068FA0 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 5C44 80068FA4 1800B28F */  lw         $s2, 0x18($sp)
    /* 5C48 80068FA8 1400B18F */  lw         $s1, 0x14($sp)
    /* 5C4C 80068FAC 1000B08F */  lw         $s0, 0x10($sp)
    /* 5C50 80068FB0 0800E003 */  jr         $ra
    /* 5C54 80068FB4 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Stg20_LabCaptionUpdate
