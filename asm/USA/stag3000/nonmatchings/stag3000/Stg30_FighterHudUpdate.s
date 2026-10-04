nonmatching Stg30_FighterHudUpdate, 0x280

glabel Stg30_FighterHudUpdate
    /* DA2C 80070D8C B8FFBD27 */  addiu      $sp, $sp, -0x48
    /* DA30 80070D90 4000B0AF */  sw         $s0, 0x40($sp)
    /* DA34 80070D94 21808000 */  addu       $s0, $a0, $zero
    /* DA38 80070D98 01000524 */  addiu      $a1, $zero, 0x1
    /* DA3C 80070D9C 4400BFAF */  sw         $ra, 0x44($sp)
    /* DA40 80070DA0 1000038E */  lw         $v1, 0x10($s0)
    /* DA44 80070DA4 2C00048E */  lw         $a0, 0x2C($s0)
    /* DA48 80070DA8 14006510 */  beq        $v1, $a1, .L80070DFC
    /* DA4C 80070DAC 02006228 */   slti      $v0, $v1, 0x2
    /* DA50 80070DB0 05004010 */  beqz       $v0, .L80070DC8
    /* DA54 80070DB4 00000000 */   nop
    /* DA58 80070DB8 08006010 */  beqz       $v1, .L80070DDC
    /* DA5C 80070DBC 0C000224 */   addiu     $v0, $zero, 0xC
    /* DA60 80070DC0 FFC30108 */  j          .L80070FFC
    /* DA64 80070DC4 00000000 */   nop
  .L80070DC8:
    /* DA68 80070DC8 02000224 */  addiu      $v0, $zero, 0x2
    /* DA6C 80070DCC 74006210 */  beq        $v1, $v0, .L80070FA0
    /* DA70 80070DD0 00000000 */   nop
    /* DA74 80070DD4 FFC30108 */  j          .L80070FFC
    /* DA78 80070DD8 00000000 */   nop
  .L80070DDC:
    /* DA7C 80070DDC 080082AC */  sw         $v0, 0x8($a0)
    /* DA80 80070DE0 21208200 */  addu       $a0, $a0, $v0
    /* DA84 80070DE4 2270000C */  jal        Mem_FillWordsNeg1
    /* DA88 80070DE8 02000524 */   addiu     $a1, $zero, 0x2
    /* DA8C 80070DEC 5145000C */  jal        Task_NextState0
    /* DA90 80070DF0 21200002 */   addu      $a0, $s0, $zero
    /* DA94 80070DF4 FFC30108 */  j          .L80070FFC
    /* DA98 80070DF8 00000000 */   nop
  .L80070DFC:
    /* DA9C 80070DFC 1400038E */  lw         $v1, 0x14($s0)
    /* DAA0 80070E00 00000000 */  nop
    /* DAA4 80070E04 1B006510 */  beq        $v1, $a1, .L80070E74
    /* DAA8 80070E08 02006228 */   slti      $v0, $v1, 0x2
    /* DAAC 80070E0C 03004014 */  bnez       $v0, .L80070E1C
    /* DAB0 80070E10 02000224 */   addiu     $v0, $zero, 0x2
    /* DAB4 80070E14 3A006210 */  beq        $v1, $v0, .L80070F00
    /* DAB8 80070E18 0780033C */   lui       $v1, %hi(Stg30_Battle)
  .L80070E1C:
    /* DABC 80070E1C 0780033C */  lui        $v1, %hi(D_80073454)
    /* DAC0 80070E20 0800028E */  lw         $v0, 0x8($s0)
    /* DAC4 80070E24 54346324 */  addiu      $v1, $v1, %lo(D_80073454)
    /* DAC8 80070E28 80100200 */  sll        $v0, $v0, 2
    /* DACC 80070E2C 21104300 */  addu       $v0, $v0, $v1
    /* DAD0 80070E30 2400038E */  lw         $v1, 0x24($s0)
    /* DAD4 80070E34 0000428C */  lw         $v0, 0x0($v0)
    /* DAD8 80070E38 00000000 */  nop
    /* DADC 80070E3C 2A104300 */  slt        $v0, $v0, $v1
    /* DAE0 80070E40 06004010 */  beqz       $v0, .L80070E5C
    /* DAE4 80070E44 00100324 */   addiu     $v1, $zero, 0x1000
    /* DAE8 80070E48 04008284 */  lh         $v0, 0x4($a0)
    /* DAEC 80070E4C 04008594 */  lhu        $a1, 0x4($a0)
    /* DAF0 80070E50 27004310 */  beq        $v0, $v1, .L80070EF0
    /* DAF4 80070E54 0001A224 */   addiu     $v0, $a1, 0x100
    /* DAF8 80070E58 040082A4 */  sh         $v0, 0x4($a0)
  .L80070E5C:
    /* DAFC 80070E5C 04008384 */  lh         $v1, 0x4($a0)
    /* DB00 80070E60 00100224 */  addiu      $v0, $zero, 0x1000
    /* DB04 80070E64 22006210 */  beq        $v1, $v0, .L80070EF0
    /* DB08 80070E68 00000000 */   nop
    /* DB0C 80070E6C FFC30108 */  j          .L80070FFC
    /* DB10 80070E70 00000000 */   nop
  .L80070E74:
    /* DB14 80070E74 0800038E */  lw         $v1, 0x8($s0)
    /* DB18 80070E78 1000A0AF */  sw         $zero, 0x10($sp)
    /* DB1C 80070E7C 1400A0AF */  sw         $zero, 0x14($sp)
    /* DB20 80070E80 40100300 */  sll        $v0, $v1, 1
    /* DB24 80070E84 21104300 */  addu       $v0, $v0, $v1
    /* DB28 80070E88 C0100200 */  sll        $v0, $v0, 3
    /* DB2C 80070E8C 23104300 */  subu       $v0, $v0, $v1
    /* DB30 80070E90 80100200 */  sll        $v0, $v0, 2
    /* DB34 80070E94 0780033C */  lui        $v1, %hi(D_80073D24)
    /* DB38 80070E98 243D6324 */  addiu      $v1, $v1, %lo(D_80073D24)
    /* DB3C 80070E9C 21104300 */  addu       $v0, $v0, $v1
    /* DB40 80070EA0 0780033C */  lui        $v1, %hi(D_8007346C)
    /* DB44 80070EA4 2400A2AF */  sw         $v0, 0x24($sp)
    /* DB48 80070EA8 0800028E */  lw         $v0, 0x8($s0)
    /* DB4C 80070EAC 6C346324 */  addiu      $v1, $v1, %lo(D_8007346C)
    /* DB50 80070EB0 80100200 */  sll        $v0, $v0, 2
    /* DB54 80070EB4 21104300 */  addu       $v0, $v0, $v1
    /* DB58 80070EB8 00004294 */  lhu        $v0, 0x0($v0)
    /* DB5C 80070EBC 0C008424 */  addiu      $a0, $a0, 0xC
    /* DB60 80070EC0 1800A2A7 */  sh         $v0, 0x18($sp)
    /* DB64 80070EC4 0800028E */  lw         $v0, 0x8($s0)
    /* DB68 80070EC8 1000A527 */  addiu      $a1, $sp, 0x10
    /* DB6C 80070ECC 80100200 */  sll        $v0, $v0, 2
    /* DB70 80070ED0 21104300 */  addu       $v0, $v0, $v1
    /* DB74 80070ED4 02004394 */  lhu        $v1, 0x2($v0)
    /* DB78 80070ED8 08000224 */  addiu      $v0, $zero, 0x8
    /* DB7C 80070EDC 2800A2AF */  sw         $v0, 0x28($sp)
    /* DB80 80070EE0 1C00A0AF */  sw         $zero, 0x1C($sp)
    /* DB84 80070EE4 2000A0AF */  sw         $zero, 0x20($sp)
    /* DB88 80070EE8 096F000C */  jal        Text_Open
    /* DB8C 80070EEC 1A00A3A7 */   sh        $v1, 0x1A($sp)
  .L80070EF0:
    /* DB90 80070EF0 5945000C */  jal        Task_NextState1
    /* DB94 80070EF4 21200002 */   addu      $a0, $s0, $zero
    /* DB98 80070EF8 FFC30108 */  j          .L80070FFC
    /* DB9C 80070EFC 00000000 */   nop
  .L80070F00:
    /* DBA0 80070F00 0800078E */  lw         $a3, 0x8($s0)
    /* DBA4 80070F04 C03C6324 */  addiu      $v1, $v1, %lo(Stg30_Battle)
    /* DBA8 80070F08 00110700 */  sll        $v0, $a3, 4
    /* DBAC 80070F0C 21104300 */  addu       $v0, $v0, $v1
    /* DBB0 80070F10 AC02438C */  lw         $v1, 0x2AC($v0)
    /* DBB4 80070F14 00000000 */  nop
    /* DBB8 80070F18 18006010 */  beqz       $v1, .L80070F7C
    /* DBBC 80070F1C 0C000224 */   addiu     $v0, $zero, 0xC
    /* DBC0 80070F20 0800828C */  lw         $v0, 0x8($a0)
    /* DBC4 80070F24 00000000 */  nop
    /* DBC8 80070F28 03004010 */  beqz       $v0, .L80070F38
    /* DBCC 80070F2C FCFF4224 */   addiu     $v0, $v0, -0x4
    /* DBD0 80070F30 FFC30108 */  j          .L80070FFC
    /* DBD4 80070F34 080082AC */   sw        $v0, 0x8($a0)
  .L80070F38:
    /* DBD8 80070F38 10008424 */  addiu      $a0, $a0, 0x10
    /* DBDC 80070F3C 21300000 */  addu       $a2, $zero, $zero
    /* DBE0 80070F40 0780023C */  lui        $v0, %hi(Stg30_OrderLabelMsgs)
    /* DBE4 80070F44 84344224 */  addiu      $v0, $v0, %lo(Stg30_OrderLabelMsgs)
    /* DBE8 80070F48 21106200 */  addu       $v0, $v1, $v0
    /* DBEC 80070F4C 0780033C */  lui        $v1, %hi(D_8007348C)
    /* DBF0 80070F50 8C346324 */  addiu      $v1, $v1, %lo(D_8007348C)
    /* DBF4 80070F54 FFFF4590 */  lbu        $a1, -0x1($v0)
    /* DBF8 80070F58 80100700 */  sll        $v0, $a3, 2
    /* DBFC 80070F5C 21104300 */  addu       $v0, $v0, $v1
    /* DC00 80070F60 02004794 */  lhu        $a3, 0x2($v0)
    /* DC04 80070F64 00004294 */  lhu        $v0, 0x0($v0)
    /* DC08 80070F68 003C0700 */  sll        $a3, $a3, 16
    /* DC0C 80070F6C F26F000C */  jal        Text_OpenById
    /* DC10 80070F70 25384700 */   or        $a3, $v0, $a3
    /* DC14 80070F74 FFC30108 */  j          .L80070FFC
    /* DC18 80070F78 00000000 */   nop
  .L80070F7C:
    /* DC1C 80070F7C 0800838C */  lw         $v1, 0x8($a0)
    /* DC20 80070F80 00000000 */  nop
    /* DC24 80070F84 1D006210 */  beq        $v1, $v0, .L80070FFC
    /* DC28 80070F88 04006224 */   addiu     $v0, $v1, 0x4
    /* DC2C 80070F8C 080082AC */  sw         $v0, 0x8($a0)
    /* DC30 80070F90 E26E000C */  jal        Text_Close
    /* DC34 80070F94 10008424 */   addiu     $a0, $a0, 0x10
    /* DC38 80070F98 FFC30108 */  j          .L80070FFC
    /* DC3C 80070F9C 00000000 */   nop
  .L80070FA0:
    /* DC40 80070FA0 1400028E */  lw         $v0, 0x14($s0)
    /* DC44 80070FA4 00000000 */  nop
    /* DC48 80070FA8 03004010 */  beqz       $v0, .L80070FB8
    /* DC4C 80070FAC 00000000 */   nop
    /* DC50 80070FB0 0E004510 */  beq        $v0, $a1, .L80070FEC
    /* DC54 80070FB4 00000000 */   nop
  .L80070FB8:
    /* DC58 80070FB8 1800028E */  lw         $v0, 0x18($s0)
    /* DC5C 80070FBC 00000000 */  nop
    /* DC60 80070FC0 03004010 */  beqz       $v0, .L80070FD0
    /* DC64 80070FC4 00000000 */   nop
    /* DC68 80070FC8 0C004510 */  beq        $v0, $a1, .L80070FFC
    /* DC6C 80070FCC 00000000 */   nop
  .L80070FD0:
    /* DC70 80070FD0 0C008424 */  addiu      $a0, $a0, 0xC
    /* DC74 80070FD4 2C70000C */  jal        Text_CloseArray
    /* DC78 80070FD8 02000524 */   addiu     $a1, $zero, 0x2
    /* DC7C 80070FDC 6045000C */  jal        Task_NextState2
    /* DC80 80070FE0 21200002 */   addu      $a0, $s0, $zero
    /* DC84 80070FE4 FFC30108 */  j          .L80070FFC
    /* DC88 80070FE8 00000000 */   nop
  .L80070FEC:
    /* DC8C 80070FEC 21200002 */  addu       $a0, $s0, $zero
    /* DC90 80070FF0 01000524 */  addiu      $a1, $zero, 0x1
    /* DC94 80070FF4 7D45000C */  jal        Task_SetState01
    /* DC98 80070FF8 2130A000 */   addu      $a2, $a1, $zero
  .L80070FFC:
    /* DC9C 80070FFC 4400BF8F */  lw         $ra, 0x44($sp)
    /* DCA0 80071000 4000B08F */  lw         $s0, 0x40($sp)
    /* DCA4 80071004 0800E003 */  jr         $ra
    /* DCA8 80071008 4800BD27 */   addiu     $sp, $sp, 0x48
endlabel Stg30_FighterHudUpdate
