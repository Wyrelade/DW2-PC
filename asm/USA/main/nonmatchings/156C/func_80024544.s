nonmatching func_80024544, 0xCC

glabel func_80024544
    /* 14D44 80024544 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 14D48 80024548 1400BFAF */  sw         $ra, 0x14($sp)
    /* 14D4C 8002454C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 14D50 80024550 0580013C */  lui        $at, %hi(D_80048E50)
    /* 14D54 80024554 F19B000C */  jal        EnterCriticalSection
    /* 14D58 80024558 508E20AC */   sw        $zero, %lo(D_80048E50)($at)
    /* 14D5C 8002455C 02000424 */  addiu      $a0, $zero, 0x2
    /* 14D60 80024560 0580103C */  lui        $s0, %hi(D_80048E78)
    /* 14D64 80024564 788E1026 */  addiu      $s0, $s0, %lo(D_80048E78)
    /* 14D68 80024568 FD9B000C */  jal        SysDeqIntRP
    /* 14D6C 8002456C 21280002 */   addu      $a1, $s0, $zero
    /* 14D70 80024570 02000424 */  addiu      $a0, $zero, 0x2
    /* 14D74 80024574 F99B000C */  jal        SysEnqIntRP
    /* 14D78 80024578 21280002 */   addu      $a1, $s0, $zero
    /* 14D7C 8002457C 03000424 */  addiu      $a0, $zero, 0x3
    /* 14D80 80024580 0580033C */  lui        $v1, %hi(D_80048DF0)
    /* 14D84 80024584 F08D638C */  lw         $v1, %lo(D_80048DF0)($v1)
    /* 14D88 80024588 FEFF0224 */  addiu      $v0, $zero, -0x2
    /* 14D8C 8002458C 000062AC */  sw         $v0, 0x0($v1)
    /* 14D90 80024590 0400628C */  lw         $v0, 0x4($v1)
    /* 14D94 80024594 21280000 */  addu       $a1, $zero, $zero
    /* 14D98 80024598 01004234 */  ori        $v0, $v0, 0x1
    /* 14D9C 8002459C 019C000C */  jal        ChangeClearRCnt
    /* 14DA0 800245A0 040062AC */   sw        $v0, 0x4($v1)
    /* 14DA4 800245A4 F59B000C */  jal        ExitCriticalSection
    /* 14DA8 800245A8 00000000 */   nop
    /* 14DAC 800245AC 0580043C */  lui        $a0, %hi(D_80048E4C)
    /* 14DB0 800245B0 4C8E848C */  lw         $a0, %lo(D_80048E4C)($a0)
    /* 14DB4 800245B4 0580023C */  lui        $v0, %hi(D_80048E1C)
    /* 14DB8 800245B8 1C8E428C */  lw         $v0, %lo(D_80048E1C)($v0)
    /* 14DBC 800245BC 00000000 */  nop
    /* 14DC0 800245C0 09F84000 */  jalr       $v0
    /* 14DC4 800245C4 00000000 */   nop
    /* 14DC8 800245C8 0580043C */  lui        $a0, %hi(D_80048E4C)
    /* 14DCC 800245CC 4C8E848C */  lw         $a0, %lo(D_80048E4C)($a0)
    /* 14DD0 800245D0 0580023C */  lui        $v0, %hi(D_80048E1C)
    /* 14DD4 800245D4 1C8E428C */  lw         $v0, %lo(D_80048E1C)($v0)
    /* 14DD8 800245D8 00000000 */  nop
    /* 14DDC 800245DC 09F84000 */  jalr       $v0
    /* 14DE0 800245E0 F0008424 */   addiu     $a0, $a0, 0xF0
    /* 14DE4 800245E4 0680023C */  lui        $v0, %hi(D_80060058)
    /* 14DE8 800245E8 58004224 */  addiu      $v0, $v0, %lo(D_80060058)
    /* 14DEC 800245EC 040040AC */  sw         $zero, 0x4($v0)
    /* 14DF0 800245F0 000040AC */  sw         $zero, 0x0($v0)
    /* 14DF4 800245F4 01000224 */  addiu      $v0, $zero, 0x1
    /* 14DF8 800245F8 0580013C */  lui        $at, %hi(D_80048E50)
    /* 14DFC 800245FC 508E22AC */  sw         $v0, %lo(D_80048E50)($at)
    /* 14E00 80024600 1400BF8F */  lw         $ra, 0x14($sp)
    /* 14E04 80024604 1000B08F */  lw         $s0, 0x10($sp)
    /* 14E08 80024608 0800E003 */  jr         $ra
    /* 14E0C 8002460C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80024544
