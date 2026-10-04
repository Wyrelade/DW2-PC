nonmatching Stg35_CameraUpdate, 0x5D8

glabel Stg35_CameraUpdate
    /* 669C 800699FC 40FFBD27 */  addiu      $sp, $sp, -0xC0
    /* 66A0 80069A00 B400B1AF */  sw         $s1, 0xB4($sp)
    /* 66A4 80069A04 21888000 */  addu       $s1, $a0, $zero
    /* 66A8 80069A08 01000224 */  addiu      $v0, $zero, 0x1
    /* 66AC 80069A0C BC00BFAF */  sw         $ra, 0xBC($sp)
    /* 66B0 80069A10 B800B2AF */  sw         $s2, 0xB8($sp)
    /* 66B4 80069A14 B000B0AF */  sw         $s0, 0xB0($sp)
    /* 66B8 80069A18 1000238E */  lw         $v1, 0x10($s1)
    /* 66BC 80069A1C 2C00308E */  lw         $s0, 0x2C($s1)
    /* 66C0 80069A20 11006210 */  beq        $v1, $v0, .L80069A68
    /* 66C4 80069A24 02006228 */   slti      $v0, $v1, 0x2
    /* 66C8 80069A28 64014010 */  beqz       $v0, .L80069FBC
    /* 66CC 80069A2C 00000000 */   nop
    /* 66D0 80069A30 62016014 */  bnez       $v1, .L80069FBC
    /* 66D4 80069A34 21200000 */   addu      $a0, $zero, $zero
    /* 66D8 80069A38 09AD000C */  jal        GsInitCoordinate2
    /* 66DC 80069A3C 1C000526 */   addiu     $a1, $s0, 0x1C
    /* 66E0 80069A40 21202002 */  addu       $a0, $s1, $zero
    /* 66E4 80069A44 E0B10224 */  addiu      $v0, $zero, -0x4E20
    /* 66E8 80069A48 040002AE */  sw         $v0, 0x4($s0)
    /* 66EC 80069A4C 2C010224 */  addiu      $v0, $zero, 0x12C
    /* 66F0 80069A50 100002AE */  sw         $v0, 0x10($s0)
    /* 66F4 80069A54 DC050224 */  addiu      $v0, $zero, 0x5DC
    /* 66F8 80069A58 5145000C */  jal        Task_NextState0
    /* 66FC 80069A5C 180002AE */   sw        $v0, 0x18($s0)
    /* 6700 80069A60 EFA70108 */  j          .L80069FBC
    /* 6704 80069A64 00000000 */   nop
  .L80069A68:
    /* 6708 80069A68 1400238E */  lw         $v1, 0x14($s1)
    /* 670C 80069A6C 00000000 */  nop
    /* 6710 80069A70 1B00622C */  sltiu      $v0, $v1, 0x1B
    /* 6714 80069A74 08004010 */  beqz       $v0, .L80069A98
    /* 6718 80069A78 0680023C */   lui       $v0, %hi(jtbl_80063490)
    /* 671C 80069A7C 90344224 */  addiu      $v0, $v0, %lo(jtbl_80063490)
    /* 6720 80069A80 80180300 */  sll        $v1, $v1, 2
    /* 6724 80069A84 21186200 */  addu       $v1, $v1, $v0
    /* 6728 80069A88 0000628C */  lw         $v0, 0x0($v1)
    /* 672C 80069A8C 00000000 */  nop
    /* 6730 80069A90 08004000 */  jr         $v0
    /* 6734 80069A94 00000000 */   nop
  jlabel .L80069A98
    /* 6738 80069A98 1800238E */  lw         $v1, 0x18($s1)
    /* 673C 80069A9C 00000000 */  nop
    /* 6740 80069AA0 03006010 */  beqz       $v1, .L80069AB0
    /* 6744 80069AA4 01000224 */   addiu     $v0, $zero, 0x1
    /* 6748 80069AA8 14006210 */  beq        $v1, $v0, .L80069AFC
    /* 674C 80069AAC 1E000324 */   addiu     $v1, $zero, 0x1E
  .L80069AB0:
    /* 6750 80069AB0 0400028E */  lw         $v0, 0x4($s0)
    /* 6754 80069AB4 0800038E */  lw         $v1, 0x8($s0)
    /* 6758 80069AB8 E9004224 */  addiu      $v0, $v0, 0xE9
    /* 675C 80069ABC 040002AE */  sw         $v0, 0x4($s0)
    /* 6760 80069AC0 7E000296 */  lhu        $v0, 0x7E($s0)
    /* 6764 80069AC4 A2FE6324 */  addiu      $v1, $v1, -0x15E
    /* 6768 80069AC8 080003AE */  sw         $v1, 0x8($s0)
    /* 676C 80069ACC 44004224 */  addiu      $v0, $v0, 0x44
    /* 6770 80069AD0 7E0002A6 */  sh         $v0, 0x7E($s0)
    /* 6774 80069AD4 00140200 */  sll        $v0, $v0, 16
    /* 6778 80069AD8 03140200 */  sra        $v0, $v0, 16
    /* 677C 80069ADC 01104228 */  slti       $v0, $v0, 0x1001
    /* 6780 80069AE0 36014014 */  bnez       $v0, .L80069FBC
    /* 6784 80069AE4 00000000 */   nop
    /* 6788 80069AE8 7E0000A6 */  sh         $zero, 0x7E($s0)
    /* 678C 80069AEC 6045000C */  jal        Task_NextState2
    /* 6790 80069AF0 21202002 */   addu      $a0, $s1, $zero
    /* 6794 80069AF4 EFA70108 */  j          .L80069FBC
    /* 6798 80069AF8 00000000 */   nop
  .L80069AFC:
    /* 679C 80069AFC 1000028E */  lw         $v0, 0x10($s0)
    /* 67A0 80069B00 00000000 */  nop
    /* 67A4 80069B04 DFFF4224 */  addiu      $v0, $v0, -0x21
    /* 67A8 80069B08 100002AE */  sw         $v0, 0x10($s0)
    /* 67AC 80069B0C 1C00228E */  lw         $v0, 0x1C($s1)
    /* 67B0 80069B10 00000000 */  nop
    /* 67B4 80069B14 01004224 */  addiu      $v0, $v0, 0x1
    /* 67B8 80069B18 28014314 */  bne        $v0, $v1, .L80069FBC
    /* 67BC 80069B1C 1C0022AE */   sw        $v0, 0x1C($s1)
    /* 67C0 80069B20 44FD0224 */  addiu      $v0, $zero, -0x2BC
    /* 67C4 80069B24 100002AE */  sw         $v0, 0x10($s0)
    /* 67C8 80069B28 5945000C */  jal        Task_NextState1
    /* 67CC 80069B2C 21202002 */   addu      $a0, $s1, $zero
    /* 67D0 80069B30 EFA70108 */  j          .L80069FBC
    /* 67D4 80069B34 00000000 */   nop
  jlabel .L80069B38
    /* 67D8 80069B38 21200002 */  addu       $a0, $s0, $zero
    /* 67DC 80069B3C 1000A527 */  addiu      $a1, $sp, 0x10
    /* 67E0 80069B40 65E90224 */  addiu      $v0, $zero, -0x169B
    /* 67E4 80069B44 1800A2AF */  sw         $v0, 0x18($sp)
    /* 67E8 80069B48 9AAC0224 */  addiu      $v0, $zero, -0x5366
    /* 67EC 80069B4C 1C00A2AF */  sw         $v0, 0x1C($sp)
    /* 67F0 80069B50 44FD0224 */  addiu      $v0, $zero, -0x2BC
    /* 67F4 80069B54 2400A0AF */  sw         $zero, 0x24($sp)
    /* 67F8 80069B58 2800A0AF */  sw         $zero, 0x28($sp)
    /* 67FC 80069B5C 1000A0AF */  sw         $zero, 0x10($sp)
    /* 6800 80069B60 1400A0AF */  sw         $zero, 0x14($sp)
    /* 6804 80069B64 32A6010C */  jal        Stg35_CamEaseToward
    /* 6808 80069B68 2000A2AF */   sw        $v0, 0x20($sp)
    /* 680C 80069B6C EFA70108 */  j          .L80069FBC
    /* 6810 80069B70 00000000 */   nop
  jlabel .L80069B74
    /* 6814 80069B74 0780033C */  lui        $v1, %hi(Stg35_Battle)
    /* 6818 80069B78 1400228E */  lw         $v0, 0x14($s1)
    /* 681C 80069B7C 88AA6324 */  addiu      $v1, $v1, %lo(Stg35_Battle)
    /* 6820 80069B80 FEFF5124 */  addiu      $s1, $v0, -0x2
    /* 6824 80069B84 40901100 */  sll        $s2, $s1, 1
    /* 6828 80069B88 21105102 */  addu       $v0, $s2, $s1
    /* 682C 80069B8C C0100200 */  sll        $v0, $v0, 3
    /* 6830 80069B90 23105100 */  subu       $v0, $v0, $s1
    /* 6834 80069B94 80100200 */  sll        $v0, $v0, 2
    /* 6838 80069B98 21104300 */  addu       $v0, $v0, $v1
    /* 683C 80069B9C 11004490 */  lbu        $a0, 0x11($v0)
    /* 6840 80069BA0 E779000C */  jal        func_8001E79C
    /* 6844 80069BA4 00000000 */   nop
    /* 6848 80069BA8 21204000 */  addu       $a0, $v0, $zero
    /* 684C 80069BAC 00038228 */  slti       $v0, $a0, 0x300
    /* 6850 80069BB0 02004014 */  bnez       $v0, .L80069BBC
    /* 6854 80069BB4 21180000 */   addu      $v1, $zero, $zero
    /* 6858 80069BB8 00FD8324 */  addiu      $v1, $a0, -0x300
  .L80069BBC:
    /* 685C 80069BBC 21206000 */  addu       $a0, $v1, $zero
    /* 6860 80069BC0 02008104 */  bgez       $a0, .L80069BCC
    /* 6864 80069BC4 21288000 */   addu      $a1, $a0, $zero
    /* 6868 80069BC8 FF008524 */  addiu      $a1, $a0, 0xFF
  .L80069BCC:
    /* 686C 80069BCC 5555023C */  lui        $v0, (0x55555556 >> 16)
    /* 6870 80069BD0 56554234 */  ori        $v0, $v0, (0x55555556 & 0xFFFF)
    /* 6874 80069BD4 18002202 */  mult       $s1, $v0
    /* 6878 80069BD8 C3271100 */  sra        $a0, $s1, 31
    /* 687C 80069BDC 10300000 */  mfhi       $a2
    /* 6880 80069BE0 2320C400 */  subu       $a0, $a2, $a0
    /* 6884 80069BE4 40180400 */  sll        $v1, $a0, 1
    /* 6888 80069BE8 21186400 */  addu       $v1, $v1, $a0
    /* 688C 80069BEC 23182302 */  subu       $v1, $s1, $v1
    /* 6890 80069BF0 80100300 */  sll        $v0, $v1, 2
    /* 6894 80069BF4 21104300 */  addu       $v0, $v0, $v1
    /* 6898 80069BF8 40120200 */  sll        $v0, $v0, 9
    /* 689C 80069BFC 00F64224 */  addiu      $v0, $v0, -0xA00
    /* 68A0 80069C00 4400A2AF */  sw         $v0, 0x44($sp)
    /* 68A4 80069C04 80100400 */  sll        $v0, $a0, 2
    /* 68A8 80069C08 21104400 */  addu       $v0, $v0, $a0
    /* 68AC 80069C0C C0120200 */  sll        $v0, $v0, 11
    /* 68B0 80069C10 00EC4224 */  addiu      $v0, $v0, -0x1400
    /* 68B4 80069C14 4800A2AF */  sw         $v0, 0x48($sp)
    /* 68B8 80069C18 0780023C */  lui        $v0, %hi(Stg35_CloseUpRotY)
    /* 68BC 80069C1C 90A64224 */  addiu      $v0, $v0, %lo(Stg35_CloseUpRotY)
    /* 68C0 80069C20 21104202 */  addu       $v0, $s2, $v0
    /* 68C4 80069C24 03220500 */  sra        $a0, $a1, 8
    /* 68C8 80069C28 00004384 */  lh         $v1, 0x0($v0)
    /* 68CC 80069C2C D0F30224 */  addiu      $v0, $zero, -0xC30
    /* 68D0 80069C30 3800A2AF */  sw         $v0, 0x38($sp)
    /* 68D4 80069C34 0780023C */  lui        $v0, %hi(Stg35_CloseUpVpz)
    /* 68D8 80069C38 9CA64224 */  addiu      $v0, $v0, %lo(Stg35_CloseUpVpz)
    /* 68DC 80069C3C 3400A0AF */  sw         $zero, 0x34($sp)
    /* 68E0 80069C40 3000A3AF */  sw         $v1, 0x30($sp)
    /* 68E4 80069C44 40180400 */  sll        $v1, $a0, 1
    /* 68E8 80069C48 21106200 */  addu       $v0, $v1, $v0
    /* 68EC 80069C4C 00004284 */  lh         $v0, 0x0($v0)
    /* 68F0 80069C50 3000A527 */  addiu      $a1, $sp, 0x30
    /* 68F4 80069C54 3C00A2AF */  sw         $v0, 0x3C($sp)
    /* 68F8 80069C58 0780023C */  lui        $v0, %hi(Stg35_CloseUpVry)
    /* 68FC 80069C5C B0A64224 */  addiu      $v0, $v0, %lo(Stg35_CloseUpVry)
    /* 6900 80069C60 21186200 */  addu       $v1, $v1, $v0
    /* 6904 80069C64 00006284 */  lh         $v0, 0x0($v1)
    /* 6908 80069C68 21200002 */  addu       $a0, $s0, $zero
    /* 690C 80069C6C 32A6010C */  jal        Stg35_CamEaseToward
    /* 6910 80069C70 4000A2AF */   sw        $v0, 0x40($sp)
    /* 6914 80069C74 EFA70108 */  j          .L80069FBC
    /* 6918 80069C78 00000000 */   nop
  jlabel .L80069C7C
    /* 691C 80069C7C 21200002 */  addu       $a0, $s0, $zero
    /* 6920 80069C80 5000A527 */  addiu      $a1, $sp, 0x50
    /* 6924 80069C84 00EC0224 */  addiu      $v0, $zero, -0x1400
    /* 6928 80069C88 6800A2AF */  sw         $v0, 0x68($sp)
    /* 692C 80069C8C 38020224 */  addiu      $v0, $zero, 0x238
    /* 6930 80069C90 5000A2AF */  sw         $v0, 0x50($sp)
    /* 6934 80069C94 E4F60224 */  addiu      $v0, $zero, -0x91C
    /* 6938 80069C98 5800A2AF */  sw         $v0, 0x58($sp)
    /* 693C 80069C9C FC330224 */  addiu      $v0, $zero, 0x33FC
    /* 6940 80069CA0 5C00A2AF */  sw         $v0, 0x5C($sp)
    /* 6944 80069CA4 94FC0224 */  addiu      $v0, $zero, -0x36C
    /* 6948 80069CA8 6400A0AF */  sw         $zero, 0x64($sp)
    /* 694C 80069CAC 5400A0AF */  sw         $zero, 0x54($sp)
    /* 6950 80069CB0 32A6010C */  jal        Stg35_CamEaseToward
    /* 6954 80069CB4 6000A2AF */   sw        $v0, 0x60($sp)
    /* 6958 80069CB8 EFA70108 */  j          .L80069FBC
    /* 695C 80069CBC 00000000 */   nop
  jlabel .L80069CC0
    /* 6960 80069CC0 21200002 */  addu       $a0, $s0, $zero
    /* 6964 80069CC4 7000A527 */  addiu      $a1, $sp, 0x70
    /* 6968 80069CC8 00140224 */  addiu      $v0, $zero, 0x1400
    /* 696C 80069CCC 8800A2AF */  sw         $v0, 0x88($sp)
    /* 6970 80069CD0 C7050224 */  addiu      $v0, $zero, 0x5C7
    /* 6974 80069CD4 7000A2AF */  sw         $v0, 0x70($sp)
    /* 6978 80069CD8 E4F60224 */  addiu      $v0, $zero, -0x91C
    /* 697C 80069CDC 7800A2AF */  sw         $v0, 0x78($sp)
    /* 6980 80069CE0 FC330224 */  addiu      $v0, $zero, 0x33FC
    /* 6984 80069CE4 7C00A2AF */  sw         $v0, 0x7C($sp)
    /* 6988 80069CE8 94FC0224 */  addiu      $v0, $zero, -0x36C
    /* 698C 80069CEC 8400A0AF */  sw         $zero, 0x84($sp)
    /* 6990 80069CF0 7400A0AF */  sw         $zero, 0x74($sp)
    /* 6994 80069CF4 32A6010C */  jal        Stg35_CamEaseToward
    /* 6998 80069CF8 8000A2AF */   sw        $v0, 0x80($sp)
    /* 699C 80069CFC EFA70108 */  j          .L80069FBC
    /* 69A0 80069D00 00000000 */   nop
  jlabel .L80069D04
    /* 69A4 80069D04 00E20224 */  addiu      $v0, $zero, -0x1E00
    /* 69A8 80069D08 740002AE */  sw         $v0, 0x74($s0)
    /* 69AC 80069D0C C0E00224 */  addiu      $v0, $zero, -0x1F40
    /* 69B0 80069D10 040002AE */  sw         $v0, 0x4($s0)
    /* 69B4 80069D14 204E0224 */  addiu      $v0, $zero, 0x4E20
    /* 69B8 80069D18 6C0000AE */  sw         $zero, 0x6C($s0)
    /* 69BC 80069D1C 7E0000A6 */  sh         $zero, 0x7E($s0)
    /* 69C0 80069D20 000000AE */  sw         $zero, 0x0($s0)
    /* 69C4 80069D24 080002AE */  sw         $v0, 0x8($s0)
    /* 69C8 80069D28 0C0000AE */  sw         $zero, 0xC($s0)
    /* 69CC 80069D2C EEA70108 */  j          .L80069FB8
    /* 69D0 80069D30 100000AE */   sw        $zero, 0x10($s0)
  jlabel .L80069D34
    /* 69D4 80069D34 001E0224 */  addiu      $v0, $zero, 0x1E00
    /* 69D8 80069D38 740002AE */  sw         $v0, 0x74($s0)
    /* 69DC 80069D3C 00080224 */  addiu      $v0, $zero, 0x800
    /* 69E0 80069D40 7E0002A6 */  sh         $v0, 0x7E($s0)
    /* 69E4 80069D44 C0E00224 */  addiu      $v0, $zero, -0x1F40
    /* 69E8 80069D48 040002AE */  sw         $v0, 0x4($s0)
    /* 69EC 80069D4C 204E0224 */  addiu      $v0, $zero, 0x4E20
    /* 69F0 80069D50 6C0000AE */  sw         $zero, 0x6C($s0)
    /* 69F4 80069D54 000000AE */  sw         $zero, 0x0($s0)
    /* 69F8 80069D58 080002AE */  sw         $v0, 0x8($s0)
    /* 69FC 80069D5C 0C0000AE */  sw         $zero, 0xC($s0)
    /* 6A00 80069D60 EEA70108 */  j          .L80069FB8
    /* 6A04 80069D64 100000AE */   sw        $zero, 0x10($s0)
  jlabel .L80069D68
    /* 6A08 80069D68 21200002 */  addu       $a0, $s0, $zero
    /* 6A0C 80069D6C 9000A527 */  addiu      $a1, $sp, 0x90
    /* 6A10 80069D70 00FC0224 */  addiu      $v0, $zero, -0x400
    /* 6A14 80069D74 9000A2AF */  sw         $v0, 0x90($sp)
    /* 6A18 80069D78 05AF0224 */  addiu      $v0, $zero, -0x50FB
    /* 6A1C 80069D7C 9800A2AF */  sw         $v0, 0x98($sp)
    /* 6A20 80069D80 3A910224 */  addiu      $v0, $zero, -0x6EC6
    /* 6A24 80069D84 9C00A2AF */  sw         $v0, 0x9C($sp)
    /* 6A28 80069D88 64FD0224 */  addiu      $v0, $zero, -0x29C
    /* 6A2C 80069D8C A400A0AF */  sw         $zero, 0xA4($sp)
    /* 6A30 80069D90 A800A0AF */  sw         $zero, 0xA8($sp)
    /* 6A34 80069D94 9400A0AF */  sw         $zero, 0x94($sp)
    /* 6A38 80069D98 32A6010C */  jal        Stg35_CamEaseToward
    /* 6A3C 80069D9C A000A2AF */   sw        $v0, 0xA0($sp)
    /* 6A40 80069DA0 EFA70108 */  j          .L80069FBC
    /* 6A44 80069DA4 00000000 */   nop
  jlabel .L80069DA8
    /* 6A48 80069DA8 1800238E */  lw         $v1, 0x18($s1)
    /* 6A4C 80069DAC 00000000 */  nop
    /* 6A50 80069DB0 03006010 */  beqz       $v1, .L80069DC0
    /* 6A54 80069DB4 01000224 */   addiu     $v0, $zero, 0x1
    /* 6A58 80069DB8 09006210 */  beq        $v1, $v0, .L80069DE0
    /* 6A5C 80069DBC ECFA0224 */   addiu     $v0, $zero, -0x514
  .L80069DC0:
    /* 6A60 80069DC0 448E000C */  jal        Rand_Next
    /* 6A64 80069DC4 00000000 */   nop
    /* 6A68 80069DC8 0780033C */  lui        $v1, %hi(Stg35_CamShotVariant)
    /* 6A6C 80069DCC 03004230 */  andi       $v0, $v0, 0x3
    /* 6A70 80069DD0 70AF62AC */  sw         $v0, %lo(Stg35_CamShotVariant)($v1)
    /* 6A74 80069DD4 6045000C */  jal        Task_NextState2
    /* 6A78 80069DD8 21202002 */   addu      $a0, $s1, $zero
    /* 6A7C 80069DDC ECFA0224 */  addiu      $v0, $zero, -0x514
  .L80069DE0:
    /* 6A80 80069DE0 040002AE */  sw         $v0, 0x4($s0)
    /* 6A84 80069DE4 E02E0224 */  addiu      $v0, $zero, 0x2EE0
    /* 6A88 80069DE8 080002AE */  sw         $v0, 0x8($s0)
    /* 6A8C 80069DEC 88FA0224 */  addiu      $v0, $zero, -0x578
    /* 6A90 80069DF0 100002AE */  sw         $v0, 0x10($s0)
    /* 6A94 80069DF4 AA000224 */  addiu      $v0, $zero, 0xAA
    /* 6A98 80069DF8 000000AE */  sw         $zero, 0x0($s0)
    /* 6A9C 80069DFC 0C0000AE */  sw         $zero, 0xC($s0)
    /* 6AA0 80069E00 140000AE */  sw         $zero, 0x14($s0)
    /* 6AA4 80069E04 7E0002A6 */  sh         $v0, 0x7E($s0)
    /* 6AA8 80069E08 1400238E */  lw         $v1, 0x14($s1)
    /* 6AAC 80069E0C 00EC0224 */  addiu      $v0, $zero, -0x1400
    /* 6AB0 80069E10 740002AE */  sw         $v0, 0x74($s0)
    /* 6AB4 80069E14 F6FF6324 */  addiu      $v1, $v1, -0xA
    /* 6AB8 80069E18 80100300 */  sll        $v0, $v1, 2
    /* 6ABC 80069E1C 21104300 */  addu       $v0, $v0, $v1
    /* 6AC0 80069E20 40120200 */  sll        $v0, $v0, 9
    /* 6AC4 80069E24 80F34224 */  addiu      $v0, $v0, -0xC80
    /* 6AC8 80069E28 6C0002AE */  sw         $v0, 0x6C($s0)
    /* 6ACC 80069E2C 0780023C */  lui        $v0, %hi(Stg35_CamShotVariant)
    /* 6AD0 80069E30 70AF438C */  lw         $v1, %lo(Stg35_CamShotVariant)($v0)
    /* 6AD4 80069E34 01000224 */  addiu      $v0, $zero, 0x1
    /* 6AD8 80069E38 05006210 */  beq        $v1, $v0, .L80069E50
    /* 6ADC 80069E3C 02000224 */   addiu     $v0, $zero, 0x2
    /* 6AE0 80069E40 08006210 */  beq        $v1, $v0, .L80069E64
    /* 6AE4 80069E44 ECE60224 */   addiu     $v0, $zero, -0x1914
    /* 6AE8 80069E48 A5A70108 */  j          .L80069E94
    /* 6AEC 80069E4C 00000000 */   nop
  .L80069E50:
    /* 6AF0 80069E50 38000224 */  addiu      $v0, $zero, 0x38
    /* 6AF4 80069E54 7E0002A6 */  sh         $v0, 0x7E($s0)
    /* 6AF8 80069E58 1400238E */  lw         $v1, 0x14($s1)
    /* 6AFC 80069E5C 9EA70108 */  j          .L80069E78
    /* 6B00 80069E60 BC340224 */   addiu     $v0, $zero, 0x34BC
  .L80069E64:
    /* 6B04 80069E64 040002AE */  sw         $v0, 0x4($s0)
    /* 6B08 80069E68 1400238E */  lw         $v1, 0x14($s1)
    /* 6B0C 80069E6C 00F10224 */  addiu      $v0, $zero, -0xF00
    /* 6B10 80069E70 740002AE */  sw         $v0, 0x74($s0)
    /* 6B14 80069E74 BC340224 */  addiu      $v0, $zero, 0x34BC
  .L80069E78:
    /* 6B18 80069E78 080002AE */  sw         $v0, 0x8($s0)
    /* 6B1C 80069E7C F6FF6324 */  addiu      $v1, $v1, -0xA
    /* 6B20 80069E80 80100300 */  sll        $v0, $v1, 2
    /* 6B24 80069E84 21104300 */  addu       $v0, $v0, $v1
    /* 6B28 80069E88 40120200 */  sll        $v0, $v0, 9
    /* 6B2C 80069E8C 00F64224 */  addiu      $v0, $v0, -0xA00
    /* 6B30 80069E90 6C0002AE */  sw         $v0, 0x6C($s0)
  .L80069E94:
    /* 6B34 80069E94 1400228E */  lw         $v0, 0x14($s1)
    /* 6B38 80069E98 00000000 */  nop
    /* 6B3C 80069E9C 0D004228 */  slti       $v0, $v0, 0xD
    /* 6B40 80069EA0 46004014 */  bnez       $v0, .L80069FBC
    /* 6B44 80069EA4 00080224 */   addiu     $v0, $zero, 0x800
    /* 6B48 80069EA8 7E000396 */  lhu        $v1, 0x7E($s0)
    /* 6B4C 80069EAC 00000000 */  nop
    /* 6B50 80069EB0 23104300 */  subu       $v0, $v0, $v1
    /* 6B54 80069EB4 7E0002A6 */  sh         $v0, 0x7E($s0)
    /* 6B58 80069EB8 6C00028E */  lw         $v0, 0x6C($s0)
    /* 6B5C 80069EBC 7400038E */  lw         $v1, 0x74($s0)
    /* 6B60 80069EC0 00E24224 */  addiu      $v0, $v0, -0x1E00
    /* 6B64 80069EC4 23180300 */  negu       $v1, $v1
    /* 6B68 80069EC8 6C0002AE */  sw         $v0, 0x6C($s0)
    /* 6B6C 80069ECC EFA70108 */  j          .L80069FBC
    /* 6B70 80069ED0 740003AE */   sw        $v1, 0x74($s0)
  jlabel .L80069ED4
    /* 6B74 80069ED4 24FA0224 */  addiu      $v0, $zero, -0x5DC
    /* 6B78 80069ED8 040002AE */  sw         $v0, 0x4($s0)
    /* 6B7C 80069EDC E02E0224 */  addiu      $v0, $zero, 0x2EE0
    /* 6B80 80069EE0 080002AE */  sw         $v0, 0x8($s0)
    /* 6B84 80069EE4 C0F90224 */  addiu      $v0, $zero, -0x640
    /* 6B88 80069EE8 000000AE */  sw         $zero, 0x0($s0)
    /* 6B8C 80069EEC 0C0000AE */  sw         $zero, 0xC($s0)
    /* 6B90 80069EF0 100002AE */  sw         $v0, 0x10($s0)
    /* 6B94 80069EF4 140000AE */  sw         $zero, 0x14($s0)
    /* 6B98 80069EF8 1400228E */  lw         $v0, 0x14($s1)
    /* 6B9C 80069EFC 00000000 */  nop
    /* 6BA0 80069F00 13004228 */  slti       $v0, $v0, 0x13
    /* 6BA4 80069F04 07004010 */  beqz       $v0, .L80069F24
    /* 6BA8 80069F08 AA000224 */   addiu     $v0, $zero, 0xAA
    /* 6BAC 80069F0C 7E0002A6 */  sh         $v0, 0x7E($s0)
    /* 6BB0 80069F10 1400238E */  lw         $v1, 0x14($s1)
    /* 6BB4 80069F14 00EC0224 */  addiu      $v0, $zero, -0x1400
    /* 6BB8 80069F18 740002AE */  sw         $v0, 0x74($s0)
    /* 6BBC 80069F1C CFA70108 */  j          .L80069F3C
    /* 6BC0 80069F20 F0FF6324 */   addiu     $v1, $v1, -0x10
  .L80069F24:
    /* 6BC4 80069F24 55070224 */  addiu      $v0, $zero, 0x755
    /* 6BC8 80069F28 7E0002A6 */  sh         $v0, 0x7E($s0)
    /* 6BCC 80069F2C 1400238E */  lw         $v1, 0x14($s1)
    /* 6BD0 80069F30 00140224 */  addiu      $v0, $zero, 0x1400
    /* 6BD4 80069F34 740002AE */  sw         $v0, 0x74($s0)
    /* 6BD8 80069F38 EDFF6324 */  addiu      $v1, $v1, -0x13
  .L80069F3C:
    /* 6BDC 80069F3C 80100300 */  sll        $v0, $v1, 2
    /* 6BE0 80069F40 21104300 */  addu       $v0, $v0, $v1
    /* 6BE4 80069F44 40120200 */  sll        $v0, $v0, 9
    /* 6BE8 80069F48 00F64224 */  addiu      $v0, $v0, -0xA00
    /* 6BEC 80069F4C EFA70108 */  j          .L80069FBC
    /* 6BF0 80069F50 6C0002AE */   sw        $v0, 0x6C($s0)
  jlabel .L80069F54
    /* 6BF4 80069F54 00EC0224 */  addiu      $v0, $zero, -0x1400
    /* 6BF8 80069F58 740002AE */  sw         $v0, 0x74($s0)
    /* 6BFC 80069F5C 78EC0224 */  addiu      $v0, $zero, -0x1388
    /* 6C00 80069F60 040002AE */  sw         $v0, 0x4($s0)
    /* 6C04 80069F64 983A0224 */  addiu      $v0, $zero, 0x3A98
    /* 6C08 80069F68 080002AE */  sw         $v0, 0x8($s0)
    /* 6C0C 80069F6C 18FC0224 */  addiu      $v0, $zero, -0x3E8
    /* 6C10 80069F70 6C0000AE */  sw         $zero, 0x6C($s0)
    /* 6C14 80069F74 700000AE */  sw         $zero, 0x70($s0)
    /* 6C18 80069F78 EBA70108 */  j          .L80069FAC
    /* 6C1C 80069F7C 7E0000A6 */   sh        $zero, 0x7E($s0)
  jlabel .L80069F80
    /* 6C20 80069F80 00140224 */  addiu      $v0, $zero, 0x1400
    /* 6C24 80069F84 740002AE */  sw         $v0, 0x74($s0)
    /* 6C28 80069F88 00080224 */  addiu      $v0, $zero, 0x800
    /* 6C2C 80069F8C 7E0002A6 */  sh         $v0, 0x7E($s0)
    /* 6C30 80069F90 78EC0224 */  addiu      $v0, $zero, -0x1388
    /* 6C34 80069F94 040002AE */  sw         $v0, 0x4($s0)
    /* 6C38 80069F98 983A0224 */  addiu      $v0, $zero, 0x3A98
    /* 6C3C 80069F9C 080002AE */  sw         $v0, 0x8($s0)
    /* 6C40 80069FA0 18FC0224 */  addiu      $v0, $zero, -0x3E8
    /* 6C44 80069FA4 6C0000AE */  sw         $zero, 0x6C($s0)
    /* 6C48 80069FA8 700000AE */  sw         $zero, 0x70($s0)
  .L80069FAC:
    /* 6C4C 80069FAC 000000AE */  sw         $zero, 0x0($s0)
    /* 6C50 80069FB0 0C0000AE */  sw         $zero, 0xC($s0)
    /* 6C54 80069FB4 100002AE */  sw         $v0, 0x10($s0)
  .L80069FB8:
    /* 6C58 80069FB8 140000AE */  sw         $zero, 0x14($s0)
  .L80069FBC:
    /* 6C5C 80069FBC BC00BF8F */  lw         $ra, 0xBC($sp)
    /* 6C60 80069FC0 B800B28F */  lw         $s2, 0xB8($sp)
    /* 6C64 80069FC4 B400B18F */  lw         $s1, 0xB4($sp)
    /* 6C68 80069FC8 B000B08F */  lw         $s0, 0xB0($sp)
    /* 6C6C 80069FCC 0800E003 */  jr         $ra
    /* 6C70 80069FD0 C000BD27 */   addiu     $sp, $sp, 0xC0
endlabel Stg35_CameraUpdate
