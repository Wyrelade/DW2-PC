nonmatching Stg40_BeginTransition, 0x34C

glabel Stg40_BeginTransition
    /* BA0 80063F00 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* BA4 80063F04 2800B2AF */  sw         $s2, 0x28($sp)
    /* BA8 80063F08 21908000 */  addu       $s2, $a0, $zero
    /* BAC 80063F0C 2400B1AF */  sw         $s1, 0x24($sp)
    /* BB0 80063F10 0580113C */  lui        $s1, %hi(Dung_StatePtr)
    /* BB4 80063F14 1C07248E */  lw         $a0, %lo(Dung_StatePtr)($s1)
    /* BB8 80063F18 2C00BFAF */  sw         $ra, 0x2C($sp)
    /* BBC 80063F1C 2000B0AF */  sw         $s0, 0x20($sp)
    /* BC0 80063F20 01008290 */  lbu        $v0, 0x1($a0)
    /* BC4 80063F24 2C00508E */  lw         $s0, 0x2C($s2)
    /* BC8 80063F28 03004014 */  bnez       $v0, .L80063F38
    /* BCC 80063F2C 02000224 */   addiu     $v0, $zero, 0x2
    /* BD0 80063F30 8D900108 */  j          .L80064234
    /* BD4 80063F34 21100000 */   addu      $v0, $zero, $zero
  .L80063F38:
    /* BD8 80063F38 01008390 */  lbu        $v1, 0x1($a0)
    /* BDC 80063F3C 00000000 */  nop
    /* BE0 80063F40 6F006210 */  beq        $v1, $v0, .L80064100
    /* BE4 80063F44 03006228 */   slti      $v0, $v1, 0x3
    /* BE8 80063F48 03004014 */  bnez       $v0, .L80063F58
    /* BEC 80063F4C 05006228 */   slti      $v0, $v1, 0x5
    /* BF0 80063F50 7D004014 */  bnez       $v0, .L80064148
    /* BF4 80063F54 00000000 */   nop
  .L80063F58:
    /* BF8 80063F58 200E043C */  lui        $a0, (0xE200003 >> 16)
    /* BFC 80063F5C 688E000C */  jal        Cd_GetFileEntry
    /* C00 80063F60 03008434 */   ori       $a0, $a0, (0xE200003 & 0xFFFF)
    /* C04 80063F64 6AC8010C */  jal        Stg40_CamLoadScript
    /* C08 80063F68 21204000 */   addu      $a0, $v0, $zero
    /* C0C 80063F6C 1C07238E */  lw         $v1, %lo(Dung_StatePtr)($s1)
    /* C10 80063F70 01000224 */  addiu      $v0, $zero, 0x1
    /* C14 80063F74 020062A0 */  sb         $v0, 0x2($v1)
    /* C18 80063F78 1C07238E */  lw         $v1, %lo(Dung_StatePtr)($s1)
    /* C1C 80063F7C 00050224 */  addiu      $v0, $zero, 0x500
    /* C20 80063F80 000002AE */  sw         $v0, 0x0($s0)
    /* C24 80063F84 1810708C */  lw         $s0, 0x1018($v1)
    /* C28 80063F88 0680023C */  lui        $v0, %hi(Stg40_FloorSpecialtyByCell)
    /* C2C 80063F8C 84334924 */  addiu      $t1, $v0, %lo(Stg40_FloorSpecialtyByCell)
    /* C30 80063F90 03002689 */  lwl        $a2, 0x3($t1)
    /* C34 80063F94 00002699 */  lwr        $a2, 0x0($t1)
    /* C38 80063F98 07002789 */  lwl        $a3, 0x7($t1)
    /* C3C 80063F9C 04002799 */  lwr        $a3, 0x4($t1)
    /* C40 80063FA0 0B002889 */  lwl        $t0, 0xB($t1)
    /* C44 80063FA4 08002899 */  lwr        $t0, 0x8($t1)
    /* C48 80063FA8 1300A6AB */  swl        $a2, 0x13($sp)
    /* C4C 80063FAC 1000A6BB */  swr        $a2, 0x10($sp)
    /* C50 80063FB0 1700A7AB */  swl        $a3, 0x17($sp)
    /* C54 80063FB4 1400A7BB */  swr        $a3, 0x14($sp)
    /* C58 80063FB8 1B00A8AB */  swl        $t0, 0x1B($sp)
    /* C5C 80063FBC 1800A8BB */  swr        $t0, 0x18($sp)
    /* C60 80063FC0 0C002681 */  lb         $a2, 0xC($t1)
    /* C64 80063FC4 00000000 */  nop
    /* C68 80063FC8 1C00A6A3 */  sb         $a2, 0x1C($sp)
    /* C6C 80063FCC 18000486 */  lh         $a0, 0x18($s0)
    /* C70 80063FD0 1A000586 */  lh         $a1, 0x1A($s0)
    /* C74 80063FD4 F8C0010C */  jal        Stg40_GetCellFlags
    /* C78 80063FD8 00000000 */   nop
    /* C7C 80063FDC 1000A327 */  addiu      $v1, $sp, 0x10
    /* C80 80063FE0 0F004230 */  andi       $v0, $v0, 0xF
    /* C84 80063FE4 21186200 */  addu       $v1, $v1, $v0
    /* C88 80063FE8 1C07248E */  lw         $a0, %lo(Dung_StatePtr)($s1)
    /* C8C 80063FEC 00006290 */  lbu        $v0, 0x0($v1)
    /* C90 80063FF0 00000000 */  nop
    /* C94 80063FF4 3D1082A0 */  sb         $v0, 0x103D($a0)
    /* C98 80063FF8 1000028E */  lw         $v0, 0x10($s0)
    /* C9C 80063FFC 1C07248E */  lw         $a0, %lo(Dung_StatePtr)($s1)
    /* CA0 80064000 0E004294 */  lhu        $v0, 0xE($v0)
    /* CA4 80064004 00000000 */  nop
    /* CA8 80064008 3E1082A4 */  sh         $v0, 0x103E($a0)
    /* CAC 8006400C 1000038E */  lw         $v1, 0x10($s0)
    /* CB0 80064010 00000000 */  nop
    /* CB4 80064014 0C006284 */  lh         $v0, 0xC($v1)
    /* CB8 80064018 0E006384 */  lh         $v1, 0xE($v1)
    /* CBC 8006401C 00000000 */  nop
    /* CC0 80064020 1A004300 */  div        $zero, $v0, $v1
    /* CC4 80064024 12100000 */  mflo       $v0
    /* CC8 80064028 00000000 */  nop
    /* CCC 8006402C 21184000 */  addu       $v1, $v0, $zero
    /* CD0 80064030 401082A4 */  sh         $v0, 0x1040($a0)
    /* CD4 80064034 00140200 */  sll        $v0, $v0, 16
    /* CD8 80064038 03140200 */  sra        $v0, $v0, 16
    /* CDC 8006403C 04004228 */  slti       $v0, $v0, 0x4
    /* CE0 80064040 02004014 */  bnez       $v0, .L8006404C
    /* CE4 80064044 00000000 */   nop
    /* CE8 80064048 03000324 */  addiu      $v1, $zero, 0x3
  .L8006404C:
    /* CEC 8006404C 401083A4 */  sh         $v1, 0x1040($a0)
    /* CF0 80064050 1000028E */  lw         $v0, 0x10($s0)
    /* CF4 80064054 00000000 */  nop
    /* CF8 80064058 00004384 */  lh         $v1, 0x0($v0)
    /* CFC 8006405C 0680023C */  lui        $v0, %hi(D_8005F794)
    /* D00 80064060 94F743AC */  sw         $v1, %lo(D_8005F794)($v0)
    /* D04 80064064 1000028E */  lw         $v0, 0x10($s0)
    /* D08 80064068 00000000 */  nop
    /* D0C 8006406C 02004290 */  lbu        $v0, 0x2($v0)
    /* D10 80064070 00000000 */  nop
    /* D14 80064074 13004010 */  beqz       $v0, .L800640C4
    /* D18 80064078 00020424 */   addiu     $a0, $zero, 0x200
    /* D1C 8006407C 9E87000C */  jal        Flag_Test
    /* D20 80064080 88000424 */   addiu     $a0, $zero, 0x88
    /* D24 80064084 09004010 */  beqz       $v0, .L800640AC
    /* D28 80064088 0580023C */   lui       $v0, %hi(Dung_StatePtr)
    /* D2C 8006408C 1C07228E */  lw         $v0, %lo(Dung_StatePtr)($s1)
    /* D30 80064090 00000000 */  nop
    /* D34 80064094 4C104384 */  lh         $v1, 0x104C($v0)
    /* D38 80064098 00010224 */  addiu      $v0, $zero, 0x100
    /* D3C 8006409C 03006214 */  bne        $v1, $v0, .L800640AC
    /* D40 800640A0 0580023C */   lui       $v0, %hi(Dung_StatePtr)
    /* D44 800640A4 31900108 */  j          .L800640C4
    /* D48 800640A8 01010424 */   addiu     $a0, $zero, 0x101
  .L800640AC:
    /* D4C 800640AC 1C07428C */  lw         $v0, %lo(Dung_StatePtr)($v0)
    /* D50 800640B0 00000000 */  nop
    /* D54 800640B4 4C104484 */  lh         $a0, 0x104C($v0)
    /* D58 800640B8 4E104584 */  lh         $a1, 0x104E($v0)
    /* D5C 800640BC 32900108 */  j          .L800640C8
    /* D60 800640C0 00000000 */   nop
  .L800640C4:
    /* D64 800640C4 01000524 */  addiu      $a1, $zero, 0x1
  .L800640C8:
    /* D68 800640C8 A369000C */  jal        Snd_PlayById
    /* D6C 800640CC 01001024 */   addiu     $s0, $zero, 0x1
    /* D70 800640D0 06020424 */  addiu      $a0, $zero, 0x206
    /* D74 800640D4 A369000C */  jal        Snd_PlayById
    /* D78 800640D8 21280000 */   addu      $a1, $zero, $zero
    /* D7C 800640DC 21204002 */  addu       $a0, $s2, $zero
    /* D80 800640E0 7745000C */  jal        Task_SetState1
    /* D84 800640E4 03000524 */   addiu     $a1, $zero, 0x3
    /* D88 800640E8 3C71000C */  jal        Gfx_FadeOutToBlack
    /* D8C 800640EC 08000424 */   addiu     $a0, $zero, 0x8
    /* D90 800640F0 FD8E000C */  jal        Cd_QueueFile
    /* D94 800640F4 93010424 */   addiu     $a0, $zero, 0x193
    /* D98 800640F8 8D900108 */  j          .L80064234
    /* D9C 800640FC 21100002 */   addu      $v0, $s0, $zero
  .L80064100:
    /* DA0 80064100 200E043C */  lui        $a0, (0xE200004 >> 16)
    /* DA4 80064104 688E000C */  jal        Cd_GetFileEntry
    /* DA8 80064108 04008434 */   ori       $a0, $a0, (0xE200004 & 0xFFFF)
    /* DAC 8006410C 6AC8010C */  jal        Stg40_CamLoadScript
    /* DB0 80064110 21204000 */   addu      $a0, $v0, $zero
    /* DB4 80064114 21204002 */  addu       $a0, $s2, $zero
    /* DB8 80064118 0680023C */  lui        $v0, %hi(Sys_GameMode)
    /* DBC 8006411C 88F7428C */  lw         $v0, %lo(Sys_GameMode)($v0)
    /* DC0 80064120 03000524 */  addiu      $a1, $zero, 0x3
    /* DC4 80064124 7745000C */  jal        Task_SetState1
    /* DC8 80064128 000002AE */   sw        $v0, 0x0($s0)
    /* DCC 8006412C 1C07238E */  lw         $v1, %lo(Dung_StatePtr)($s1)
    /* DD0 80064130 00000000 */  nop
    /* DD4 80064134 03006290 */  lbu        $v0, 0x3($v1)
    /* DD8 80064138 01001024 */  addiu      $s0, $zero, 0x1
    /* DDC 8006413C 21105000 */  addu       $v0, $v0, $s0
    /* DE0 80064140 8C900108 */  j          .L80064230
    /* DE4 80064144 030062A0 */   sb        $v0, 0x3($v1)
  .L80064148:
    /* DE8 80064148 06008290 */  lbu        $v0, 0x6($a0)
    /* DEC 8006414C 00000000 */  nop
    /* DF0 80064150 0B004014 */  bnez       $v0, .L80064180
    /* DF4 80064154 04000524 */   addiu     $a1, $zero, 0x4
    /* DF8 80064158 01030224 */  addiu      $v0, $zero, 0x301
    /* DFC 8006415C 000002AE */  sw         $v0, 0x0($s0)
    /* E00 80064160 0680023C */  lui        $v0, %hi(Sys_State)
    /* E04 80064164 07008390 */  lbu        $v1, 0x7($a0)
    /* E08 80064168 00000000 */  nop
    /* E0C 8006416C 02006010 */  beqz       $v1, .L80064178
    /* E10 80064170 70F74224 */   addiu     $v0, $v0, %lo(Sys_State)
    /* E14 80064174 03000524 */  addiu      $a1, $zero, 0x3
  .L80064178:
    /* E18 80064178 79900108 */  j          .L800641E4
    /* E1C 8006417C 240045AC */   sw        $a1, 0x24($v0)
  .L80064180:
    /* E20 80064180 9E87000C */  jal        Flag_Test
    /* E24 80064184 81000424 */   addiu     $a0, $zero, 0x81
    /* E28 80064188 0C004014 */  bnez       $v0, .L800641BC
    /* E2C 8006418C 03000424 */   addiu     $a0, $zero, 0x3
    /* E30 80064190 04000424 */  addiu      $a0, $zero, 0x4
    /* E34 80064194 01030224 */  addiu      $v0, $zero, 0x301
    /* E38 80064198 000002AE */  sw         $v0, 0x0($s0)
    /* E3C 8006419C 1C07228E */  lw         $v0, %lo(Dung_StatePtr)($s1)
    /* E40 800641A0 0680033C */  lui        $v1, %hi(Sys_State)
    /* E44 800641A4 07004290 */  lbu        $v0, 0x7($v0)
    /* E48 800641A8 00000000 */  nop
    /* E4C 800641AC 0C004010 */  beqz       $v0, .L800641E0
    /* E50 800641B0 70F76324 */   addiu     $v1, $v1, %lo(Sys_State)
    /* E54 800641B4 78900108 */  j          .L800641E0
    /* E58 800641B8 03000424 */   addiu     $a0, $zero, 0x3
  .L800641BC:
    /* E5C 800641BC 21030224 */  addiu      $v0, $zero, 0x321
    /* E60 800641C0 000002AE */  sw         $v0, 0x0($s0)
    /* E64 800641C4 1C07228E */  lw         $v0, %lo(Dung_StatePtr)($s1)
    /* E68 800641C8 0680033C */  lui        $v1, %hi(Sys_State)
    /* E6C 800641CC 07004290 */  lbu        $v0, 0x7($v0)
    /* E70 800641D0 00000000 */  nop
    /* E74 800641D4 02004010 */  beqz       $v0, .L800641E0
    /* E78 800641D8 70F76324 */   addiu     $v1, $v1, %lo(Sys_State)
    /* E7C 800641DC 02000424 */  addiu      $a0, $zero, 0x2
  .L800641E0:
    /* E80 800641E0 240064AC */  sw         $a0, 0x24($v1)
  .L800641E4:
    /* E84 800641E4 0580023C */  lui        $v0, %hi(Dung_StatePtr)
    /* E88 800641E8 1C07428C */  lw         $v0, %lo(Dung_StatePtr)($v0)
    /* E8C 800641EC 00000000 */  nop
    /* E90 800641F0 07004290 */  lbu        $v0, 0x7($v0)
    /* E94 800641F4 00000000 */  nop
    /* E98 800641F8 04004010 */  beqz       $v0, .L8006420C
    /* E9C 800641FC 00000000 */   nop
    /* EA0 80064200 200E043C */  lui        $a0, (0xE200009 >> 16)
    /* EA4 80064204 85900108 */  j          .L80064214
    /* EA8 80064208 09008434 */   ori       $a0, $a0, (0xE200009 & 0xFFFF)
  .L8006420C:
    /* EAC 8006420C 200E043C */  lui        $a0, (0xE200004 >> 16)
    /* EB0 80064210 04008434 */  ori        $a0, $a0, (0xE200004 & 0xFFFF)
  .L80064214:
    /* EB4 80064214 688E000C */  jal        Cd_GetFileEntry
    /* EB8 80064218 01001024 */   addiu     $s0, $zero, 0x1
    /* EBC 8006421C 6AC8010C */  jal        Stg40_CamLoadScript
    /* EC0 80064220 21204000 */   addu      $a0, $v0, $zero
    /* EC4 80064224 21204002 */  addu       $a0, $s2, $zero
    /* EC8 80064228 7745000C */  jal        Task_SetState1
    /* ECC 8006422C 03000524 */   addiu     $a1, $zero, 0x3
  .L80064230:
    /* ED0 80064230 21100002 */  addu       $v0, $s0, $zero
  .L80064234:
    /* ED4 80064234 2C00BF8F */  lw         $ra, 0x2C($sp)
    /* ED8 80064238 2800B28F */  lw         $s2, 0x28($sp)
    /* EDC 8006423C 2400B18F */  lw         $s1, 0x24($sp)
    /* EE0 80064240 2000B08F */  lw         $s0, 0x20($sp)
    /* EE4 80064244 0800E003 */  jr         $ra
    /* EE8 80064248 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel Stg40_BeginTransition
