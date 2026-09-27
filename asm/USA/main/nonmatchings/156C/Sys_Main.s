nonmatching Sys_Main, 0x394

glabel Sys_Main
    /* 13D50 80023550 A0FFBD27 */  addiu      $sp, $sp, -0x60
    /* 13D54 80023554 5C00BFAF */  sw         $ra, 0x5C($sp)
    /* 13D58 80023558 5800B4AF */  sw         $s4, 0x58($sp)
    /* 13D5C 8002355C 5400B3AF */  sw         $s3, 0x54($sp)
    /* 13D60 80023560 5000B2AF */  sw         $s2, 0x50($sp)
    /* 13D64 80023564 4C00B1AF */  sw         $s1, 0x4C($sp)
    /* 13D68 80023568 5D43000C */  jal        func_80010D74
    /* 13D6C 8002356C 4800B0AF */   sw        $s0, 0x48($sp)
    /* 13D70 80023570 35C3000C */  jal        ResetCallback
    /* 13D74 80023574 0680103C */   lui       $s0, %hi(D_8005F7A0)
    /* 13D78 80023578 ADC2000C */  jal        VSync
    /* 13D7C 8002357C 21200000 */   addu      $a0, $zero, $zero
    /* 13D80 80023580 FA9C000C */  jal        SetDispMask
    /* 13D84 80023584 21200000 */   addu      $a0, $zero, $zero
    /* 13D88 80023588 419C000C */  jal        ResetGraph
    /* 13D8C 8002358C 21200000 */   addu      $a0, $zero, $zero
    /* 13D90 80023590 0280043C */  lui        $a0, %hi(Sys_VSyncHandler)
    /* 13D94 80023594 59C3000C */  jal        VSyncCallback
    /* 13D98 80023598 84348424 */   addiu     $a0, $a0, %lo(Sys_VSyncHandler)
    /* 13D9C 8002359C 1800A427 */  addiu      $a0, $sp, 0x18
    /* 13DA0 800235A0 21280000 */  addu       $a1, $zero, $zero
    /* 13DA4 800235A4 2130A000 */  addu       $a2, $a1, $zero
    /* 13DA8 800235A8 2138A000 */  addu       $a3, $a1, $zero
    /* 13DAC 800235AC 80020224 */  addiu      $v0, $zero, 0x280
    /* 13DB0 800235B0 1C00A2A7 */  sh         $v0, 0x1C($sp)
    /* 13DB4 800235B4 FF010224 */  addiu      $v0, $zero, 0x1FF
    /* 13DB8 800235B8 1800A0A7 */  sh         $zero, 0x18($sp)
    /* 13DBC 800235BC 1A00A0A7 */  sh         $zero, 0x1A($sp)
    /* 13DC0 800235C0 819D000C */  jal        ClearImage
    /* 13DC4 800235C4 1E00A2A7 */   sh        $v0, 0x1E($sp)
    /* 13DC8 800235C8 209D000C */  jal        DrawSync
    /* 13DCC 800235CC 21200000 */   addu      $a0, $zero, $zero
    /* 13DD0 800235D0 40010424 */  addiu      $a0, $zero, 0x140
    /* 13DD4 800235D4 F0000524 */  addiu      $a1, $zero, 0xF0
    /* 13DD8 800235D8 01000624 */  addiu      $a2, $zero, 0x1
    /* 13DDC 800235DC 2138C000 */  addu       $a3, $a2, $zero
    /* 13DE0 800235E0 15AB000C */  jal        func_8002AC54
    /* 13DE4 800235E4 1000A0AF */   sw        $zero, 0x10($sp)
    /* 13DE8 800235E8 31AD000C */  jal        func_8002B4C4
    /* 13DEC 800235EC A0F71026 */   addiu     $s0, $s0, %lo(D_8005F7A0)
    /* 13DF0 800235F0 45CA000C */  jal        SsInit
    /* 13DF4 800235F4 00000000 */   nop
    /* 13DF8 800235F8 97B3000C */  jal        func_8002CE5C
    /* 13DFC 800235FC 00000000 */   nop
    /* 13E00 80023600 40010424 */  addiu      $a0, $zero, 0x140
    /* 13E04 80023604 80020524 */  addiu      $a1, $zero, 0x280
    /* 13E08 80023608 01000624 */  addiu      $a2, $zero, 0x1
    /* 13E0C 8002360C 7870000C */  jal        Gpu_InitDoubleBuffer
    /* 13E10 80023610 21380000 */   addu      $a3, $zero, $zero
    /* 13E14 80023614 B99E000C */  jal        PutDrawEnv
    /* 13E18 80023618 21200002 */   addu      $a0, $s0, $zero
    /* 13E1C 8002361C 2C9F000C */  jal        PutDispEnv
    /* 13E20 80023620 B8000426 */   addiu     $a0, $s0, 0xB8
    /* 13E24 80023624 ADC2000C */  jal        VSync
    /* 13E28 80023628 21200000 */   addu      $a0, $zero, $zero
    /* 13E2C 8002362C 0180043C */  lui        $a0, %hi(D_80010000)
    /* 13E30 80023630 0000848C */  lw         $a0, %lo(D_80010000)($a0)
    /* 13E34 80023634 2000A527 */  addiu      $a1, $sp, 0x20
    /* 13E38 80023638 F5AE000C */  jal        GsGetTimInfo
    /* 13E3C 8002363C 04008424 */   addiu     $a0, $a0, 0x4
    /* 13E40 80023640 ADC2000C */  jal        VSync
    /* 13E44 80023644 21200000 */   addu      $a0, $zero, $zero
    /* 13E48 80023648 2C00A58F */  lw         $a1, 0x2C($sp)
    /* 13E4C 8002364C 38008427 */  addiu      $a0, $gp, %gp_rel(D_80050730)
    /* 13E50 80023650 CB9D000C */  jal        LoadImage
    /* 13E54 80023654 00000000 */   nop
    /* 13E58 80023658 209D000C */  jal        DrawSync
    /* 13E5C 8002365C 21200000 */   addu      $a0, $zero, $zero
    /* 13E60 80023660 ADC2000C */  jal        VSync
    /* 13E64 80023664 21200000 */   addu      $a0, $zero, $zero
    /* 13E68 80023668 FA9C000C */  jal        SetDispMask
    /* 13E6C 8002366C 01000424 */   addiu     $a0, $zero, 0x1
    /* 13E70 80023670 01B7000C */  jal        CdInit
    /* 13E74 80023674 00000000 */   nop
    /* 13E78 80023678 2DC1000C */  jal        CdSetDebug
    /* 13E7C 8002367C 21200000 */   addu      $a0, $zero, $zero
    /* 13E80 80023680 9E9C000C */  jal        SetGraphDebug
    /* 13E84 80023684 21200000 */   addu      $a0, $zero, $zero
    /* 13E88 80023688 1F80053C */  lui        $a1, (0x801FF000 >> 16)
    /* 13E8C 8002368C 0580043C */  lui        $a0, %hi(D_800506F8)
    /* 13E90 80023690 F806848C */  lw         $a0, %lo(D_800506F8)($a0)
    /* 13E94 80023694 00F0A534 */  ori        $a1, $a1, (0x801FF000 & 0xFFFF)
    /* 13E98 80023698 988B000C */  jal        Mem_InitHeap
    /* 13E9C 8002369C 2328A400 */   subu      $a1, $a1, $a0
    /* 13EA0 800236A0 8E8E000C */  jal        Cd_ClearFileCache
    /* 13EA4 800236A4 00000000 */   nop
    /* 13EA8 800236A8 D769000C */  jal        Snd_Init
    /* 13EAC 800236AC 00000000 */   nop
    /* 13EB0 800236B0 D0FF00AE */  sw         $zero, -0x30($s0)
    /* 13EB4 800236B4 D0FF1026 */  addiu      $s0, $s0, -0x30
    /* 13EB8 800236B8 01000224 */  addiu      $v0, $zero, 0x1
    /* 13EBC 800236BC 040000AE */  sw         $zero, 0x4($s0)
    /* 13EC0 800236C0 4D72000C */  jal        Gpu_FreePrimBufs
    /* 13EC4 800236C4 280002AE */   sw        $v0, 0x28($s0)
    /* 13EC8 800236C8 0072000C */  jal        func_8001C800
    /* 13ECC 800236CC 21200000 */   addu      $a0, $zero, $zero
    /* 13ED0 800236D0 D871000C */  jal        Gpu_SetLayerOtPtrs
    /* 13ED4 800236D4 00000000 */   nop
    /* 13ED8 800236D8 398E000C */  jal        Rand_Seed
    /* 13EDC 800236DC 21200000 */   addu      $a0, $zero, $zero
    /* 13EE0 800236E0 29F5000C */  jal        func_8003D4A4
    /* 13EE4 800236E4 21200000 */   addu      $a0, $zero, $zero
    /* 13EE8 800236E8 40F7000C */  jal        MemCardStart
    /* 13EEC 800236EC 00000000 */   nop
    /* 13EF0 800236F0 2B8C000C */  jal        Pad_Init
    /* 13EF4 800236F4 00000000 */   nop
    /* 13EF8 800236F8 80000224 */  addiu      $v0, $zero, 0x80
    /* 13EFC 800236FC 4000A2A3 */  sb         $v0, 0x40($sp)
  .L80023700:
    /* 13F00 80023700 0E000424 */  addiu      $a0, $zero, 0xE
    /* 13F04 80023704 4000A527 */  addiu      $a1, $sp, 0x40
    /* 13F08 80023708 55C1000C */  jal        CdControl
    /* 13F0C 8002370C 21300000 */   addu      $a2, $zero, $zero
    /* 13F10 80023710 FBFF4010 */  beqz       $v0, .L80023700
    /* 13F14 80023714 00000000 */   nop
    /* 13F18 80023718 ADC2000C */  jal        VSync
    /* 13F1C 8002371C 03000424 */   addiu     $a0, $zero, 0x3
    /* 13F20 80023720 09000424 */  addiu      $a0, $zero, 0x9
    /* 13F24 80023724 21280000 */  addu       $a1, $zero, $zero
    /* 13F28 80023728 F1C1000C */  jal        CdControlB
    /* 13F2C 8002372C 2130A000 */   addu      $a2, $a1, $zero
    /* 13F30 80023730 6444000C */  jal        Task_ClearList
    /* 13F34 80023734 0680113C */   lui       $s1, %hi(D_8005F770)
    /* 13F38 80023738 8F72000C */  jal        Gfx_InitTexSlots
    /* 13F3C 8002373C 70F73026 */   addiu     $s0, $s1, %lo(D_8005F770)
    /* 13F40 80023740 0672000C */  jal        Gpu_ClearOt
    /* 13F44 80023744 21200000 */   addu      $a0, $zero, $zero
    /* 13F48 80023748 0672000C */  jal        Gpu_ClearOt
    /* 13F4C 8002374C 01000424 */   addiu     $a0, $zero, 0x1
    /* 13F50 80023750 01000224 */  addiu      $v0, $zero, 0x1
    /* 13F54 80023754 70F722AE */  sw         $v0, %lo(D_8005F770)($s1)
    /* 13F58 80023758 02040224 */  addiu      $v0, $zero, 0x402
    /* 13F5C 8002375C 180002AE */  sw         $v0, 0x18($s0)
    /* 13F60 80023760 1C0002AE */  sw         $v0, 0x1C($s0)
    /* 13F64 80023764 240000AE */  sw         $zero, 0x24($s0)
    /* 13F68 80023768 1A89000C */  jal        func_80022468
    /* 13F6C 8002376C 0C0000AE */   sw        $zero, 0xC($s0)
    /* 13F70 80023770 21A02002 */  addu       $s4, $s1, $zero
    /* 13F74 80023774 21880002 */  addu       $s1, $s0, $zero
    /* 13F78 80023778 0580023C */  lui        $v0, %hi(D_8005071C)
    /* 13F7C 8002377C 1C07428C */  lw         $v0, %lo(D_8005071C)($v0)
    /* 13F80 80023780 01001324 */  addiu      $s3, $zero, 0x1
    /* 13F84 80023784 5B71000C */  jal        Gfx_FadeSetBlack
    /* 13F88 80023788 000040A0 */   sb        $zero, 0x0($v0)
    /* 13F8C 8002378C 6171000C */  jal        Gfx_DrawFade
    /* 13F90 80023790 00000000 */   nop
    /* 13F94 80023794 0680023C */  lui        $v0, %hi(D_8005E620)
    /* 13F98 80023798 20E65224 */  addiu      $s2, $v0, %lo(D_8005E620)
    /* 13F9C 8002379C 4400A0AF */  sw         $zero, 0x44($sp)
  .L800237A0:
    /* 13FA0 800237A0 4400A28F */  lw         $v0, 0x44($sp)
    /* 13FA4 800237A4 00000000 */  nop
    /* 13FA8 800237A8 1A004014 */  bnez       $v0, .L80023814
    /* 13FAC 800237AC 00000000 */   nop
    /* 13FB0 800237B0 6444000C */  jal        Task_ClearList
    /* 13FB4 800237B4 21800000 */   addu      $s0, $zero, $zero
    /* 13FB8 800237B8 4D72000C */  jal        Gpu_FreePrimBufs
    /* 13FBC 800237BC 00000000 */   nop
    /* 13FC0 800237C0 7B8B000C */  jal        Mem_FreeTag
    /* 13FC4 800237C4 02000424 */   addiu     $a0, $zero, 0x2
    /* 13FC8 800237C8 0672000C */  jal        Gpu_ClearOt
    /* 13FCC 800237CC 21200000 */   addu      $a0, $zero, $zero
    /* 13FD0 800237D0 0672000C */  jal        Gpu_ClearOt
    /* 13FD4 800237D4 01000424 */   addiu     $a0, $zero, 0x1
    /* 13FD8 800237D8 1800228E */  lw         $v0, 0x18($s1)
    /* 13FDC 800237DC 1C00238E */  lw         $v1, 0x1C($s1)
    /* 13FE0 800237E0 1C0020AE */  sw         $zero, 0x1C($s1)
    /* 13FE4 800237E4 200022AE */  sw         $v0, 0x20($s1)
    /* 13FE8 800237E8 180023AE */  sw         $v1, 0x18($s1)
  .L800237EC:
    /* 13FEC 800237EC 21200002 */  addu       $a0, $s0, $zero
    /* 13FF0 800237F0 7188000C */  jal        Flag_Set
    /* 13FF4 800237F4 21280000 */   addu      $a1, $zero, $zero
    /* 13FF8 800237F8 01001026 */  addiu      $s0, $s0, 0x1
    /* 13FFC 800237FC 1100022A */  slti       $v0, $s0, 0x11
    /* 14000 80023800 FAFF4014 */  bnez       $v0, .L800237EC
    /* 14004 80023804 01000424 */   addiu     $a0, $zero, 0x1
    /* 14008 80023808 4400A527 */  addiu      $a1, $sp, 0x44
    /* 1400C 8002380C 1F44000C */  jal        Task_Create
    /* 14010 80023810 21300000 */   addu      $a2, $zero, $zero
  .L80023814:
    /* 14014 80023814 6171000C */  jal        Gfx_DrawFade
    /* 14018 80023818 00000000 */   nop
    /* 1401C 8002381C 4400A48F */  lw         $a0, 0x44($sp)
    /* 14020 80023820 A943000C */  jal        Task_TryRun
    /* 14024 80023824 140020AE */   sw        $zero, 0x14($s1)
    /* 14028 80023828 21204000 */  addu       $a0, $v0, $zero
    /* 1402C 8002382C 4400A4AF */  sw         $a0, 0x44($sp)
    /* 14030 80023830 A943000C */  jal        Task_TryRun
    /* 14034 80023834 140033AE */   sw        $s3, 0x14($s1)
    /* 14038 80023838 2800248E */  lw         $a0, 0x28($s1)
    /* 1403C 8002383C 2672000C */  jal        Gpu_SkipEmptyOtEntries
    /* 14040 80023840 4400A2AF */   sw        $v0, 0x44($sp)
    /* 14044 80023844 209D000C */  jal        DrawSync
    /* 14048 80023848 21200000 */   addu      $a0, $zero, $zero
    /* 1404C 8002384C 940093AF */  sw         $s3, %gp_rel(D_8005078C)($gp)
  .L80023850:
    /* 14050 80023850 9400828F */  lw         $v0, %gp_rel(D_8005078C)($gp)
    /* 14054 80023854 00000000 */  nop
    /* 14058 80023858 FDFF4014 */  bnez       $v0, .L80023850
    /* 1405C 8002385C 00000000 */   nop
    /* 14060 80023860 6272000C */  jal        Gpu_ResetPrimBuf
    /* 14064 80023864 00000000 */   nop
    /* 14068 80023868 D871000C */  jal        Gpu_SetLayerOtPtrs
    /* 1406C 8002386C 00000000 */   nop
    /* 14070 80023870 2800248E */  lw         $a0, 0x28($s1)
    /* 14074 80023874 0672000C */  jal        Gpu_ClearOt
    /* 14078 80023878 00000000 */   nop
    /* 1407C 8002387C ADC2000C */  jal        VSync
    /* 14080 80023880 FFFF0424 */   addiu     $a0, $zero, -0x1
    /* 14084 80023884 4000838F */  lw         $v1, %gp_rel(D_80050738)($gp)
    /* 14088 80023888 0400448E */  lw         $a0, 0x4($s2)
    /* 1408C 8002388C 400082AF */  sw         $v0, %gp_rel(D_80050738)($gp)
    /* 14090 80023890 23104300 */  subu       $v0, $v0, $v1
    /* 14094 80023894 21208200 */  addu       $a0, $a0, $v0
    /* 14098 80023898 080022AE */  sw         $v0, 0x8($s1)
    /* 1409C 8002389C 07004228 */  slti       $v0, $v0, 0x7
    /* 140A0 800238A0 03004014 */  bnez       $v0, .L800238B0
    /* 140A4 800238A4 040044AE */   sw        $a0, 0x4($s2)
    /* 140A8 800238A8 06000224 */  addiu      $v0, $zero, 0x6
    /* 140AC 800238AC 080022AE */  sw         $v0, 0x8($s1)
  .L800238B0:
    /* 140B0 800238B0 70F7828E */  lw         $v0, %lo(D_8005F770)($s4)
    /* 140B4 800238B4 00000000 */  nop
    /* 140B8 800238B8 01004224 */  addiu      $v0, $v0, 0x1
    /* 140BC 800238BC A78C000C */  jal        Pad_Update
    /* 140C0 800238C0 70F782AE */   sw        $v0, %lo(D_8005F770)($s4)
    /* 140C4 800238C4 3D8E000C */  jal        Rand_Step
    /* 140C8 800238C8 00000000 */   nop
    /* 140CC 800238CC 1D8F000C */  jal        Cd_ServiceQueue
    /* 140D0 800238D0 00000000 */   nop
    /* 140D4 800238D4 0768000C */  jal        Snd_ServiceSlotLoads
    /* 140D8 800238D8 00000000 */   nop
    /* 140DC 800238DC E88D0008 */  j          .L800237A0
    /* 140E0 800238E0 00000000 */   nop
endlabel Sys_Main
