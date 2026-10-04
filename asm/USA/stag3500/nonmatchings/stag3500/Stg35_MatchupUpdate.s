nonmatching Stg35_MatchupUpdate, 0x430

glabel Stg35_MatchupUpdate
    /* 1360 800646C0 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 1364 800646C4 3000B6AF */  sw         $s6, 0x30($sp)
    /* 1368 800646C8 21B08000 */  addu       $s6, $a0, $zero
    /* 136C 800646CC 01000424 */  addiu      $a0, $zero, 0x1
    /* 1370 800646D0 3400BFAF */  sw         $ra, 0x34($sp)
    /* 1374 800646D4 2C00B5AF */  sw         $s5, 0x2C($sp)
    /* 1378 800646D8 2800B4AF */  sw         $s4, 0x28($sp)
    /* 137C 800646DC 2400B3AF */  sw         $s3, 0x24($sp)
    /* 1380 800646E0 2000B2AF */  sw         $s2, 0x20($sp)
    /* 1384 800646E4 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 1388 800646E8 1800B0AF */  sw         $s0, 0x18($sp)
    /* 138C 800646EC 2C00D58E */  lw         $s5, 0x2C($s6)
    /* 1390 800646F0 1000C38E */  lw         $v1, 0x10($s6)
    /* 1394 800646F4 3400D08E */  lw         $s0, 0x34($s6)
    /* 1398 800646F8 31006410 */  beq        $v1, $a0, .L800647C0
    /* 139C 800646FC 02006228 */   slti      $v0, $v1, 0x2
    /* 13A0 80064700 05004010 */  beqz       $v0, .L80064718
    /* 13A4 80064704 00000000 */   nop
    /* 13A8 80064708 08006010 */  beqz       $v1, .L8006472C
    /* 13AC 8006470C 0300043C */   lui       $a0, (0x32000 >> 16)
    /* 13B0 80064710 B2920108 */  j          .L80064AC8
    /* 13B4 80064714 00000000 */   nop
  .L80064718:
    /* 13B8 80064718 02000224 */  addiu      $v0, $zero, 0x2
    /* 13BC 8006471C D9006210 */  beq        $v1, $v0, .L80064A84
    /* 13C0 80064720 00000000 */   nop
    /* 13C4 80064724 B2920108 */  j          .L80064AC8
    /* 13C8 80064728 00000000 */   nop
  .L8006472C:
    /* 13CC 8006472C 6C72000C */  jal        Gpu_AllocPacketBufs
    /* 13D0 80064730 00208434 */   ori       $a0, $a0, (0x32000 & 0xFFFF)
    /* 13D4 80064734 5C8E000C */  jal        Sys_SetFrameRate30
    /* 13D8 80064738 2188A002 */   addu      $s1, $s5, $zero
    /* 13DC 8006473C 40010424 */  addiu      $a0, $zero, 0x140
    /* 13E0 80064740 E0010524 */  addiu      $a1, $zero, 0x1E0
    /* 13E4 80064744 02000624 */  addiu      $a2, $zero, 0x2
    /* 13E8 80064748 7870000C */  jal        Gpu_InitDoubleBuffer
    /* 13EC 8006474C 21380000 */   addu      $a3, $zero, $zero
    /* 13F0 80064750 21200000 */  addu       $a0, $zero, $zero
    /* 13F4 80064754 21288000 */  addu       $a1, $a0, $zero
    /* 13F8 80064758 6570000C */  jal        Gpu_SetBgClearColor
    /* 13FC 8006475C 21308000 */   addu      $a2, $a0, $zero
    /* 1400 80064760 4170000C */  jal        Gpu_ClearScreens
    /* 1404 80064764 00000000 */   nop
    /* 1408 80064768 3271000C */  jal        Gfx_FadeInFromBlack
    /* 140C 8006476C 40000424 */   addiu     $a0, $zero, 0x40
    /* 1410 80064770 09000424 */  addiu      $a0, $zero, 0x9
    /* 1414 80064774 21280002 */  addu       $a1, $s0, $zero
    /* 1418 80064778 1F44000C */  jal        Task_Create
    /* 141C 8006477C 21300000 */   addu      $a2, $zero, $zero
    /* 1420 80064780 21800000 */  addu       $s0, $zero, $zero
  .L80064784:
    /* 1424 80064784 4898010C */  jal        Stg35_PartsAlloc
    /* 1428 80064788 21202002 */   addu      $a0, $s1, $zero
    /* 142C 8006478C 01001026 */  addiu      $s0, $s0, 0x1
    /* 1430 80064790 FCFF001A */  blez       $s0, .L80064784
    /* 1434 80064794 04003126 */   addiu     $s1, $s1, 0x4
    /* 1438 80064798 21800000 */  addu       $s0, $zero, $zero
    /* 143C 8006479C 04001124 */  addiu      $s1, $zero, 0x4
  .L800647A0:
    /* 1440 800647A0 B495010C */  jal        Stg35_TextAlloc
    /* 1444 800647A4 2120B102 */   addu      $a0, $s5, $s1
    /* 1448 800647A8 01001026 */  addiu      $s0, $s0, 0x1
    /* 144C 800647AC 0E00022A */  slti       $v0, $s0, 0xE
    /* 1450 800647B0 FBFF4014 */  bnez       $v0, .L800647A0
    /* 1454 800647B4 04003126 */   addiu     $s1, $s1, 0x4
    /* 1458 800647B8 9D920108 */  j          .L80064A74
    /* 145C 800647BC 00000000 */   nop
  .L800647C0:
    /* 1460 800647C0 1400C28E */  lw         $v0, 0x14($s6)
    /* 1464 800647C4 00000000 */  nop
    /* 1468 800647C8 03004010 */  beqz       $v0, .L800647D8
    /* 146C 800647CC 00000000 */   nop
    /* 1470 800647D0 9F004410 */  beq        $v0, $a0, .L80064A50
    /* 1474 800647D4 0680023C */   lui       $v0, %hi(Pad_State)
  .L800647D8:
    /* 1478 800647D8 1800C38E */  lw         $v1, 0x18($s6)
    /* 147C 800647DC 00000000 */  nop
    /* 1480 800647E0 1E006410 */  beq        $v1, $a0, .L8006485C
    /* 1484 800647E4 02006228 */   slti      $v0, $v1, 0x2
    /* 1488 800647E8 03004014 */  bnez       $v0, .L800647F8
    /* 148C 800647EC 02000224 */   addiu     $v0, $zero, 0x2
    /* 1490 800647F0 84006210 */  beq        $v1, $v0, .L80064A04
    /* 1494 800647F4 21300000 */   addu      $a2, $zero, $zero
  .L800647F8:
    /* 1498 800647F8 2120A002 */  addu       $a0, $s5, $zero
    /* 149C 800647FC 3F0D053C */  lui        $a1, (0xD3F0002 >> 16)
    /* 14A0 80064800 6998010C */  jal        Stg35_PartsSetFile
    /* 14A4 80064804 0200A534 */   ori       $a1, $a1, (0xD3F0002 & 0xFFFF)
    /* 14A8 80064808 2120A002 */  addu       $a0, $s5, $zero
    /* 14AC 8006480C 21280000 */  addu       $a1, $zero, $zero
    /* 14B0 80064810 02000624 */  addiu      $a2, $zero, 0x2
    /* 14B4 80064814 40010724 */  addiu      $a3, $zero, 0x140
    /* 14B8 80064818 00EC0224 */  addiu      $v0, $zero, -0x1400
    /* 14BC 8006481C 1000A0AF */  sw         $zero, 0x10($sp)
    /* 14C0 80064820 A599010C */  jal        Stg35_PartsStartSlideX
    /* 14C4 80064824 1400A2AF */   sw        $v0, 0x14($sp)
    /* 14C8 80064828 2120A002 */  addu       $a0, $s5, $zero
    /* 14CC 8006482C 01000524 */  addiu      $a1, $zero, 0x1
    /* 14D0 80064830 04000624 */  addiu      $a2, $zero, 0x4
    /* 14D4 80064834 C0FE0724 */  addiu      $a3, $zero, -0x140
    /* 14D8 80064838 00140224 */  addiu      $v0, $zero, 0x1400
    /* 14DC 8006483C 1000A0AF */  sw         $zero, 0x10($sp)
    /* 14E0 80064840 A599010C */  jal        Stg35_PartsStartSlideX
    /* 14E4 80064844 1400A2AF */   sw        $v0, 0x14($sp)
    /* 14E8 80064848 2120A002 */  addu       $a0, $s5, $zero
    /* 14EC 8006484C F398010C */  jal        Stg35_PartsHideByMask
    /* 14F0 80064850 18000524 */   addiu     $a1, $zero, 0x18
    /* 14F4 80064854 6045000C */  jal        Task_NextState2
    /* 14F8 80064858 2120C002 */   addu      $a0, $s6, $zero
  .L8006485C:
    /* 14FC 8006485C 1C00C28E */  lw         $v0, 0x1C($s6)
    /* 1500 80064860 14000324 */  addiu      $v1, $zero, 0x14
    /* 1504 80064864 01004224 */  addiu      $v0, $v0, 0x1
    /* 1508 80064868 5E004314 */  bne        $v0, $v1, .L800649E4
    /* 150C 8006486C 1C00C2AE */   sw        $v0, 0x1C($s6)
    /* 1510 80064870 01010424 */  addiu      $a0, $zero, 0x101
    /* 1514 80064874 A369000C */  jal        Snd_PlayById
    /* 1518 80064878 01000524 */   addiu     $a1, $zero, 0x1
    /* 151C 8006487C 2120A002 */  addu       $a0, $s5, $zero
    /* 1520 80064880 F398010C */  jal        Stg35_PartsHideByMask
    /* 1524 80064884 10000524 */   addiu     $a1, $zero, 0x10
    /* 1528 80064888 21A00000 */  addu       $s4, $zero, $zero
    /* 152C 8006488C 0780023C */  lui        $v0, %hi(Stg35_MatchupLabelMsgs)
    /* 1530 80064890 F4A45324 */  addiu      $s3, $v0, %lo(Stg35_MatchupLabelMsgs)
    /* 1534 80064894 0780023C */  lui        $v0, %hi(Stg35_MatchupLabelPos)
    /* 1538 80064898 DCA45124 */  addiu      $s1, $v0, %lo(Stg35_MatchupLabelPos)
    /* 153C 8006489C 04001224 */  addiu      $s2, $zero, 0x4
    /* 1540 800648A0 2180B202 */  addu       $s0, $s5, $s2
  .L800648A4:
    /* 1544 800648A4 21200002 */  addu       $a0, $s0, $zero
    /* 1548 800648A8 01000524 */  addiu      $a1, $zero, 0x1
    /* 154C 800648AC 00002686 */  lh         $a2, 0x0($s1)
    /* 1550 800648B0 02002786 */  lh         $a3, 0x2($s1)
    /* 1554 800648B4 04003126 */  addiu      $s1, $s1, 0x4
    /* 1558 800648B8 04005226 */  addiu      $s2, $s2, 0x4
    /* 155C 800648BC D895010C */  jal        Stg35_TextSetLayout
    /* 1560 800648C0 21A08502 */   addu      $s4, $s4, $a1
    /* 1564 800648C4 21200002 */  addu       $a0, $s0, $zero
    /* 1568 800648C8 00006586 */  lh         $a1, 0x0($s3)
    /* 156C 800648CC EE95010C */  jal        Stg35_TextSetSysMsg
    /* 1570 800648D0 02007326 */   addiu     $s3, $s3, 0x2
    /* 1574 800648D4 0996010C */  jal        Stg35_TextOpen
    /* 1578 800648D8 21200002 */   addu      $a0, $s0, $zero
    /* 157C 800648DC 0600822A */  slti       $v0, $s4, 0x6
    /* 1580 800648E0 F0FF4014 */  bnez       $v0, .L800648A4
    /* 1584 800648E4 2180B202 */   addu      $s0, $s5, $s2
    /* 1588 800648E8 21880000 */  addu       $s1, $zero, $zero
    /* 158C 800648EC 0780023C */  lui        $v0, %hi(Stg35_MatchupPartyPos)
    /* 1590 800648F0 00A55424 */  addiu      $s4, $v0, %lo(Stg35_MatchupPartyPos)
    /* 1594 800648F4 0680023C */  lui        $v0, %hi(Save_GameState)
    /* 1598 800648F8 20E65324 */  addiu      $s3, $v0, %lo(Save_GameState)
    /* 159C 800648FC 1C001224 */  addiu      $s2, $zero, 0x1C
    /* 15A0 80064900 5555023C */  lui        $v0, (0x55555556 >> 16)
  .L80064904:
    /* 15A4 80064904 56554234 */  ori        $v0, $v0, (0x55555556 & 0xFFFF)
    /* 15A8 80064908 18002202 */  mult       $s1, $v0
    /* 15AC 8006490C 2180B202 */  addu       $s0, $s5, $s2
    /* 15B0 80064910 21200002 */  addu       $a0, $s0, $zero
    /* 15B4 80064914 01000524 */  addiu      $a1, $zero, 0x1
    /* 15B8 80064918 04005226 */  addiu      $s2, $s2, 0x4
    /* 15BC 8006491C C3171100 */  sra        $v0, $s1, 31
    /* 15C0 80064920 10400000 */  mfhi       $t0
    /* 15C4 80064924 23100201 */  subu       $v0, $t0, $v0
    /* 15C8 80064928 0418A200 */  sllv       $v1, $v0, $a1
    /* 15CC 8006492C 21186200 */  addu       $v1, $v1, $v0
    /* 15D0 80064930 23182302 */  subu       $v1, $s1, $v1
    /* 15D4 80064934 21882502 */  addu       $s1, $s1, $a1
    /* 15D8 80064938 80100200 */  sll        $v0, $v0, 2
    /* 15DC 8006493C 21105400 */  addu       $v0, $v0, $s4
    /* 15E0 80064940 0438A300 */  sllv       $a3, $v1, $a1
    /* 15E4 80064944 2138E300 */  addu       $a3, $a3, $v1
    /* 15E8 80064948 00004684 */  lh         $a2, 0x0($v0)
    /* 15EC 8006494C 02004284 */  lh         $v0, 0x2($v0)
    /* 15F0 80064950 80380700 */  sll        $a3, $a3, 2
    /* 15F4 80064954 D895010C */  jal        Stg35_TextSetLayout
    /* 15F8 80064958 21384700 */   addu      $a3, $v0, $a3
    /* 15FC 8006495C E5006492 */  lbu        $a0, 0xE5($s3)
    /* 1600 80064960 D679000C */  jal        Digi_GetDefaultName
    /* 1604 80064964 5C007326 */   addiu     $s3, $s3, 0x5C
    /* 1608 80064968 21200002 */  addu       $a0, $s0, $zero
    /* 160C 8006496C E895010C */  jal        Stg35_TextSetString
    /* 1610 80064970 21284000 */   addu      $a1, $v0, $zero
    /* 1614 80064974 0996010C */  jal        Stg35_TextOpen
    /* 1618 80064978 21200002 */   addu      $a0, $s0, $zero
    /* 161C 8006497C 0600222A */  slti       $v0, $s1, 0x6
    /* 1620 80064980 E0FF4014 */  bnez       $v0, .L80064904
    /* 1624 80064984 5555023C */   lui       $v0, (0x55555556 >> 16)
    /* 1628 80064988 21A00000 */  addu       $s4, $zero, $zero
    /* 162C 8006498C 0680023C */  lui        $v0, %hi(D_8005E978)
    /* 1630 80064990 78E95324 */  addiu      $s3, $v0, %lo(D_8005E978)
    /* 1634 80064994 0780023C */  lui        $v0, %hi(Stg35_MatchupTamerPos)
    /* 1638 80064998 08A55124 */  addiu      $s1, $v0, %lo(Stg35_MatchupTamerPos)
    /* 163C 8006499C 34001224 */  addiu      $s2, $zero, 0x34
  .L800649A0:
    /* 1640 800649A0 2180B202 */  addu       $s0, $s5, $s2
    /* 1644 800649A4 21200002 */  addu       $a0, $s0, $zero
    /* 1648 800649A8 01000524 */  addiu      $a1, $zero, 0x1
    /* 164C 800649AC 00002686 */  lh         $a2, 0x0($s1)
    /* 1650 800649B0 02002786 */  lh         $a3, 0x2($s1)
    /* 1654 800649B4 04003126 */  addiu      $s1, $s1, 0x4
    /* 1658 800649B8 04005226 */  addiu      $s2, $s2, 0x4
    /* 165C 800649BC D895010C */  jal        Stg35_TextSetLayout
    /* 1660 800649C0 21A08502 */   addu      $s4, $s4, $a1
    /* 1664 800649C4 21200002 */  addu       $a0, $s0, $zero
    /* 1668 800649C8 E895010C */  jal        Stg35_TextSetString
    /* 166C 800649CC 21286002 */   addu      $a1, $s3, $zero
    /* 1670 800649D0 0996010C */  jal        Stg35_TextOpen
    /* 1674 800649D4 21200002 */   addu      $a0, $s0, $zero
    /* 1678 800649D8 0200822A */  slti       $v0, $s4, 0x2
    /* 167C 800649DC F0FF4014 */  bnez       $v0, .L800649A0
    /* 1680 800649E0 5C007326 */   addiu     $s3, $s3, 0x5C
  .L800649E4:
    /* 1684 800649E4 1C00C38E */  lw         $v1, 0x1C($s6)
    /* 1688 800649E8 1E000224 */  addiu      $v0, $zero, 0x1E
    /* 168C 800649EC 36006214 */  bne        $v1, $v0, .L80064AC8
    /* 1690 800649F0 00000000 */   nop
    /* 1694 800649F4 6045000C */  jal        Task_NextState2
    /* 1698 800649F8 2120C002 */   addu      $a0, $s6, $zero
    /* 169C 800649FC B2920108 */  j          .L80064AC8
    /* 16A0 80064A00 00000000 */   nop
  .L80064A04:
    /* 16A4 80064A04 2800C48E */  lw         $a0, 0x28($s6)
    /* 16A8 80064A08 06000524 */  addiu      $a1, $zero, 0x6
    /* 16AC 80064A0C FB88000C */  jal        Math_CycleRange
    /* 16B0 80064A10 07000724 */   addiu     $a3, $zero, 0x7
    /* 16B4 80064A14 2120A002 */  addu       $a0, $s5, $zero
    /* 16B8 80064A18 21280000 */  addu       $a1, $zero, $zero
    /* 16BC 80064A1C F398010C */  jal        Stg35_PartsHideByMask
    /* 16C0 80064A20 21804000 */   addu      $s0, $v0, $zero
    /* 16C4 80064A24 2120A002 */  addu       $a0, $s5, $zero
    /* 16C8 80064A28 10000524 */  addiu      $a1, $zero, 0x10
    /* 16CC 80064A2C 4899010C */  jal        Stg35_PartsSetPalette
    /* 16D0 80064A30 21300002 */   addu      $a2, $s0, $zero
    /* 16D4 80064A34 07000224 */  addiu      $v0, $zero, 0x7
    /* 16D8 80064A38 23000216 */  bne        $s0, $v0, .L80064AC8
    /* 16DC 80064A3C 00000000 */   nop
    /* 16E0 80064A40 5945000C */  jal        Task_NextState1
    /* 16E4 80064A44 2120C002 */   addu      $a0, $s6, $zero
    /* 16E8 80064A48 B2920108 */  j          .L80064AC8
    /* 16EC 80064A4C 00000000 */   nop
  .L80064A50:
    /* 16F0 80064A50 F0F64324 */  addiu      $v1, $v0, %lo(Pad_State)
    /* 16F4 80064A54 1400628C */  lw         $v0, 0x14($v1)
    /* 16F8 80064A58 00000000 */  nop
    /* 16FC 80064A5C 0500401C */  bgtz       $v0, .L80064A74
    /* 1700 80064A60 00000000 */   nop
    /* 1704 80064A64 5400628C */  lw         $v0, 0x54($v1)
    /* 1708 80064A68 00000000 */  nop
    /* 170C 80064A6C 16004018 */  blez       $v0, .L80064AC8
    /* 1710 80064A70 00000000 */   nop
  .L80064A74:
    /* 1714 80064A74 5145000C */  jal        Task_NextState0
    /* 1718 80064A78 2120C002 */   addu      $a0, $s6, $zero
    /* 171C 80064A7C B2920108 */  j          .L80064AC8
    /* 1720 80064A80 00000000 */   nop
  .L80064A84:
    /* 1724 80064A84 1800C28E */  lw         $v0, 0x18($s6)
    /* 1728 80064A88 00000000 */  nop
    /* 172C 80064A8C 03004010 */  beqz       $v0, .L80064A9C
    /* 1730 80064A90 00000000 */   nop
    /* 1734 80064A94 06004410 */  beq        $v0, $a0, .L80064AB0
    /* 1738 80064A98 0680023C */   lui       $v0, %hi(Sys_State)
  .L80064A9C:
    /* 173C 80064A9C 3C71000C */  jal        Gfx_FadeOutToBlack
    /* 1740 80064AA0 10000424 */   addiu     $a0, $zero, 0x10
    /* 1744 80064AA4 6045000C */  jal        Task_NextState2
    /* 1748 80064AA8 2120C002 */   addu      $a0, $s6, $zero
    /* 174C 80064AAC 0680023C */  lui        $v0, %hi(Sys_State)
  .L80064AB0:
    /* 1750 80064AB0 70F74424 */  addiu      $a0, $v0, %lo(Sys_State)
    /* 1754 80064AB4 1000838C */  lw         $v1, 0x10($a0)
    /* 1758 80064AB8 FF000224 */  addiu      $v0, $zero, 0xFF
    /* 175C 80064ABC 02006214 */  bne        $v1, $v0, .L80064AC8
    /* 1760 80064AC0 03070224 */   addiu     $v0, $zero, 0x703
    /* 1764 80064AC4 1C0082AC */  sw         $v0, 0x1C($a0)
  .L80064AC8:
    /* 1768 80064AC8 3400BF8F */  lw         $ra, 0x34($sp)
    /* 176C 80064ACC 3000B68F */  lw         $s6, 0x30($sp)
    /* 1770 80064AD0 2C00B58F */  lw         $s5, 0x2C($sp)
    /* 1774 80064AD4 2800B48F */  lw         $s4, 0x28($sp)
    /* 1778 80064AD8 2400B38F */  lw         $s3, 0x24($sp)
    /* 177C 80064ADC 2000B28F */  lw         $s2, 0x20($sp)
    /* 1780 80064AE0 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 1784 80064AE4 1800B08F */  lw         $s0, 0x18($sp)
    /* 1788 80064AE8 0800E003 */  jr         $ra
    /* 178C 80064AEC 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel Stg35_MatchupUpdate
