nonmatching Stg30_CameraUpdate, 0x5AC

glabel Stg30_CameraUpdate
    /* D35C 800706BC 40FFBD27 */  addiu      $sp, $sp, -0xC0
    /* D360 800706C0 B400B1AF */  sw         $s1, 0xB4($sp)
    /* D364 800706C4 21888000 */  addu       $s1, $a0, $zero
    /* D368 800706C8 01000224 */  addiu      $v0, $zero, 0x1
    /* D36C 800706CC BC00BFAF */  sw         $ra, 0xBC($sp)
    /* D370 800706D0 B800B2AF */  sw         $s2, 0xB8($sp)
    /* D374 800706D4 B000B0AF */  sw         $s0, 0xB0($sp)
    /* D378 800706D8 1000238E */  lw         $v1, 0x10($s1)
    /* D37C 800706DC 2C00308E */  lw         $s0, 0x2C($s1)
    /* D380 800706E0 11006210 */  beq        $v1, $v0, .L80070728
    /* D384 800706E4 02006228 */   slti      $v0, $v1, 0x2
    /* D388 800706E8 59014010 */  beqz       $v0, .L80070C50
    /* D38C 800706EC 00000000 */   nop
    /* D390 800706F0 57016014 */  bnez       $v1, .L80070C50
    /* D394 800706F4 21200000 */   addu      $a0, $zero, $zero
    /* D398 800706F8 09AD000C */  jal        GsInitCoordinate2
    /* D39C 800706FC 1C000526 */   addiu     $a1, $s0, 0x1C
    /* D3A0 80070700 21202002 */  addu       $a0, $s1, $zero
    /* D3A4 80070704 E0B10224 */  addiu      $v0, $zero, -0x4E20
    /* D3A8 80070708 040002AE */  sw         $v0, 0x4($s0)
    /* D3AC 8007070C 2C010224 */  addiu      $v0, $zero, 0x12C
    /* D3B0 80070710 100002AE */  sw         $v0, 0x10($s0)
    /* D3B4 80070714 DC050224 */  addiu      $v0, $zero, 0x5DC
    /* D3B8 80070718 5145000C */  jal        Task_NextState0
    /* D3BC 8007071C 180002AE */   sw        $v0, 0x18($s0)
    /* D3C0 80070720 14C30108 */  j          .L80070C50
    /* D3C4 80070724 00000000 */   nop
  .L80070728:
    /* D3C8 80070728 1400238E */  lw         $v1, 0x14($s1)
    /* D3CC 8007072C 00000000 */  nop
    /* D3D0 80070730 1A00622C */  sltiu      $v0, $v1, 0x1A
    /* D3D4 80070734 08004010 */  beqz       $v0, .L80070758
    /* D3D8 80070738 0680023C */   lui       $v0, %hi(jtbl_8006380C)
    /* D3DC 8007073C 0C384224 */  addiu      $v0, $v0, %lo(jtbl_8006380C)
    /* D3E0 80070740 80180300 */  sll        $v1, $v1, 2
    /* D3E4 80070744 21186200 */  addu       $v1, $v1, $v0
    /* D3E8 80070748 0000628C */  lw         $v0, 0x0($v1)
    /* D3EC 8007074C 00000000 */  nop
    /* D3F0 80070750 08004000 */  jr         $v0
    /* D3F4 80070754 00000000 */   nop
  jlabel .L80070758
    /* D3F8 80070758 1800238E */  lw         $v1, 0x18($s1)
    /* D3FC 8007075C 00000000 */  nop
    /* D400 80070760 03006010 */  beqz       $v1, .L80070770
    /* D404 80070764 01000224 */   addiu     $v0, $zero, 0x1
    /* D408 80070768 14006210 */  beq        $v1, $v0, .L800707BC
    /* D40C 8007076C 1E000324 */   addiu     $v1, $zero, 0x1E
  .L80070770:
    /* D410 80070770 0400028E */  lw         $v0, 0x4($s0)
    /* D414 80070774 0800038E */  lw         $v1, 0x8($s0)
    /* D418 80070778 E9004224 */  addiu      $v0, $v0, 0xE9
    /* D41C 8007077C 040002AE */  sw         $v0, 0x4($s0)
    /* D420 80070780 7E000296 */  lhu        $v0, 0x7E($s0)
    /* D424 80070784 A2FE6324 */  addiu      $v1, $v1, -0x15E
    /* D428 80070788 080003AE */  sw         $v1, 0x8($s0)
    /* D42C 8007078C 44004224 */  addiu      $v0, $v0, 0x44
    /* D430 80070790 7E0002A6 */  sh         $v0, 0x7E($s0)
    /* D434 80070794 00140200 */  sll        $v0, $v0, 16
    /* D438 80070798 03140200 */  sra        $v0, $v0, 16
    /* D43C 8007079C 01104228 */  slti       $v0, $v0, 0x1001
    /* D440 800707A0 2B014014 */  bnez       $v0, .L80070C50
    /* D444 800707A4 00000000 */   nop
    /* D448 800707A8 7E0000A6 */  sh         $zero, 0x7E($s0)
    /* D44C 800707AC 6045000C */  jal        Task_NextState2
    /* D450 800707B0 21202002 */   addu      $a0, $s1, $zero
    /* D454 800707B4 14C30108 */  j          .L80070C50
    /* D458 800707B8 00000000 */   nop
  .L800707BC:
    /* D45C 800707BC 1000028E */  lw         $v0, 0x10($s0)
    /* D460 800707C0 00000000 */  nop
    /* D464 800707C4 DFFF4224 */  addiu      $v0, $v0, -0x21
    /* D468 800707C8 100002AE */  sw         $v0, 0x10($s0)
    /* D46C 800707CC 1C00228E */  lw         $v0, 0x1C($s1)
    /* D470 800707D0 00000000 */  nop
    /* D474 800707D4 01004224 */  addiu      $v0, $v0, 0x1
    /* D478 800707D8 1D014314 */  bne        $v0, $v1, .L80070C50
    /* D47C 800707DC 1C0022AE */   sw        $v0, 0x1C($s1)
    /* D480 800707E0 44FD0224 */  addiu      $v0, $zero, -0x2BC
    /* D484 800707E4 100002AE */  sw         $v0, 0x10($s0)
    /* D488 800707E8 5945000C */  jal        Task_NextState1
    /* D48C 800707EC 21202002 */   addu      $a0, $s1, $zero
    /* D490 800707F0 14C30108 */  j          .L80070C50
    /* D494 800707F4 00000000 */   nop
  jlabel .L800707F8
    /* D498 800707F8 21200002 */  addu       $a0, $s0, $zero
    /* D49C 800707FC 1000A527 */  addiu      $a1, $sp, 0x10
    /* D4A0 80070800 65E90224 */  addiu      $v0, $zero, -0x169B
    /* D4A4 80070804 1800A2AF */  sw         $v0, 0x18($sp)
    /* D4A8 80070808 9AAC0224 */  addiu      $v0, $zero, -0x5366
    /* D4AC 8007080C 1C00A2AF */  sw         $v0, 0x1C($sp)
    /* D4B0 80070810 44FD0224 */  addiu      $v0, $zero, -0x2BC
    /* D4B4 80070814 2400A0AF */  sw         $zero, 0x24($sp)
    /* D4B8 80070818 2800A0AF */  sw         $zero, 0x28($sp)
    /* D4BC 8007081C 1000A0AF */  sw         $zero, 0x10($sp)
    /* D4C0 80070820 1400A0AF */  sw         $zero, 0x14($sp)
    /* D4C4 80070824 62C1010C */  jal        Stg30_CamEaseToward
    /* D4C8 80070828 2000A2AF */   sw        $v0, 0x20($sp)
    /* D4CC 8007082C 14C30108 */  j          .L80070C50
    /* D4D0 80070830 00000000 */   nop
  jlabel .L80070834
    /* D4D4 80070834 0780033C */  lui        $v1, %hi(Stg30_Battle)
    /* D4D8 80070838 1400228E */  lw         $v0, 0x14($s1)
    /* D4DC 8007083C C03C6324 */  addiu      $v1, $v1, %lo(Stg30_Battle)
    /* D4E0 80070840 FEFF5124 */  addiu      $s1, $v0, -0x2
    /* D4E4 80070844 40901100 */  sll        $s2, $s1, 1
    /* D4E8 80070848 21105102 */  addu       $v0, $s2, $s1
    /* D4EC 8007084C C0100200 */  sll        $v0, $v0, 3
    /* D4F0 80070850 23105100 */  subu       $v0, $v0, $s1
    /* D4F4 80070854 80100200 */  sll        $v0, $v0, 2
    /* D4F8 80070858 21104300 */  addu       $v0, $v0, $v1
    /* D4FC 8007085C 19004490 */  lbu        $a0, 0x19($v0)
    /* D500 80070860 E779000C */  jal        func_8001E79C
    /* D504 80070864 00000000 */   nop
    /* D508 80070868 21204000 */  addu       $a0, $v0, $zero
    /* D50C 8007086C 00038228 */  slti       $v0, $a0, 0x300
    /* D510 80070870 02004014 */  bnez       $v0, .L8007087C
    /* D514 80070874 21180000 */   addu      $v1, $zero, $zero
    /* D518 80070878 00FD8324 */  addiu      $v1, $a0, -0x300
  .L8007087C:
    /* D51C 8007087C 21206000 */  addu       $a0, $v1, $zero
    /* D520 80070880 02008104 */  bgez       $a0, .L8007088C
    /* D524 80070884 21288000 */   addu      $a1, $a0, $zero
    /* D528 80070888 FF008524 */  addiu      $a1, $a0, 0xFF
  .L8007088C:
    /* D52C 8007088C 5555023C */  lui        $v0, (0x55555556 >> 16)
    /* D530 80070890 56554234 */  ori        $v0, $v0, (0x55555556 & 0xFFFF)
    /* D534 80070894 18002202 */  mult       $s1, $v0
    /* D538 80070898 C3271100 */  sra        $a0, $s1, 31
    /* D53C 8007089C 10300000 */  mfhi       $a2
    /* D540 800708A0 2320C400 */  subu       $a0, $a2, $a0
    /* D544 800708A4 40180400 */  sll        $v1, $a0, 1
    /* D548 800708A8 21186400 */  addu       $v1, $v1, $a0
    /* D54C 800708AC 23182302 */  subu       $v1, $s1, $v1
    /* D550 800708B0 80100300 */  sll        $v0, $v1, 2
    /* D554 800708B4 21104300 */  addu       $v0, $v0, $v1
    /* D558 800708B8 40120200 */  sll        $v0, $v0, 9
    /* D55C 800708BC 00F64224 */  addiu      $v0, $v0, -0xA00
    /* D560 800708C0 4400A2AF */  sw         $v0, 0x44($sp)
    /* D564 800708C4 80100400 */  sll        $v0, $a0, 2
    /* D568 800708C8 21104400 */  addu       $v0, $v0, $a0
    /* D56C 800708CC C0120200 */  sll        $v0, $v0, 11
    /* D570 800708D0 00EC4224 */  addiu      $v0, $v0, -0x1400
    /* D574 800708D4 4800A2AF */  sw         $v0, 0x48($sp)
    /* D578 800708D8 0780023C */  lui        $v0, %hi(Stg30_CloseUpRotY)
    /* D57C 800708DC 08344224 */  addiu      $v0, $v0, %lo(Stg30_CloseUpRotY)
    /* D580 800708E0 21104202 */  addu       $v0, $s2, $v0
    /* D584 800708E4 03220500 */  sra        $a0, $a1, 8
    /* D588 800708E8 00004384 */  lh         $v1, 0x0($v0)
    /* D58C 800708EC D0F30224 */  addiu      $v0, $zero, -0xC30
    /* D590 800708F0 3800A2AF */  sw         $v0, 0x38($sp)
    /* D594 800708F4 0780023C */  lui        $v0, %hi(Stg30_CloseUpVpz)
    /* D598 800708F8 14344224 */  addiu      $v0, $v0, %lo(Stg30_CloseUpVpz)
    /* D59C 800708FC 3400A0AF */  sw         $zero, 0x34($sp)
    /* D5A0 80070900 3000A3AF */  sw         $v1, 0x30($sp)
    /* D5A4 80070904 40180400 */  sll        $v1, $a0, 1
    /* D5A8 80070908 21106200 */  addu       $v0, $v1, $v0
    /* D5AC 8007090C 00004284 */  lh         $v0, 0x0($v0)
    /* D5B0 80070910 3000A527 */  addiu      $a1, $sp, 0x30
    /* D5B4 80070914 3C00A2AF */  sw         $v0, 0x3C($sp)
    /* D5B8 80070918 0780023C */  lui        $v0, %hi(Stg30_CloseUpVry)
    /* D5BC 8007091C 28344224 */  addiu      $v0, $v0, %lo(Stg30_CloseUpVry)
    /* D5C0 80070920 21186200 */  addu       $v1, $v1, $v0
    /* D5C4 80070924 00006284 */  lh         $v0, 0x0($v1)
    /* D5C8 80070928 21200002 */  addu       $a0, $s0, $zero
    /* D5CC 8007092C 62C1010C */  jal        Stg30_CamEaseToward
    /* D5D0 80070930 4000A2AF */   sw        $v0, 0x40($sp)
    /* D5D4 80070934 14C30108 */  j          .L80070C50
    /* D5D8 80070938 00000000 */   nop
  jlabel .L8007093C
    /* D5DC 8007093C 21200002 */  addu       $a0, $s0, $zero
    /* D5E0 80070940 5000A527 */  addiu      $a1, $sp, 0x50
    /* D5E4 80070944 00EC0224 */  addiu      $v0, $zero, -0x1400
    /* D5E8 80070948 6800A2AF */  sw         $v0, 0x68($sp)
    /* D5EC 8007094C 38020224 */  addiu      $v0, $zero, 0x238
    /* D5F0 80070950 5000A2AF */  sw         $v0, 0x50($sp)
    /* D5F4 80070954 E4F60224 */  addiu      $v0, $zero, -0x91C
    /* D5F8 80070958 5800A2AF */  sw         $v0, 0x58($sp)
    /* D5FC 8007095C FC330224 */  addiu      $v0, $zero, 0x33FC
    /* D600 80070960 5C00A2AF */  sw         $v0, 0x5C($sp)
    /* D604 80070964 94FC0224 */  addiu      $v0, $zero, -0x36C
    /* D608 80070968 6400A0AF */  sw         $zero, 0x64($sp)
    /* D60C 8007096C 5400A0AF */  sw         $zero, 0x54($sp)
    /* D610 80070970 62C1010C */  jal        Stg30_CamEaseToward
    /* D614 80070974 6000A2AF */   sw        $v0, 0x60($sp)
    /* D618 80070978 14C30108 */  j          .L80070C50
    /* D61C 8007097C 00000000 */   nop
  jlabel .L80070980
    /* D620 80070980 21200002 */  addu       $a0, $s0, $zero
    /* D624 80070984 7000A527 */  addiu      $a1, $sp, 0x70
    /* D628 80070988 00140224 */  addiu      $v0, $zero, 0x1400
    /* D62C 8007098C 8800A2AF */  sw         $v0, 0x88($sp)
    /* D630 80070990 C7050224 */  addiu      $v0, $zero, 0x5C7
    /* D634 80070994 7000A2AF */  sw         $v0, 0x70($sp)
    /* D638 80070998 E4F60224 */  addiu      $v0, $zero, -0x91C
    /* D63C 8007099C 7800A2AF */  sw         $v0, 0x78($sp)
    /* D640 800709A0 FC330224 */  addiu      $v0, $zero, 0x33FC
    /* D644 800709A4 7C00A2AF */  sw         $v0, 0x7C($sp)
    /* D648 800709A8 94FC0224 */  addiu      $v0, $zero, -0x36C
    /* D64C 800709AC 8400A0AF */  sw         $zero, 0x84($sp)
    /* D650 800709B0 7400A0AF */  sw         $zero, 0x74($sp)
    /* D654 800709B4 62C1010C */  jal        Stg30_CamEaseToward
    /* D658 800709B8 8000A2AF */   sw        $v0, 0x80($sp)
    /* D65C 800709BC 14C30108 */  j          .L80070C50
    /* D660 800709C0 00000000 */   nop
  jlabel .L800709C4
    /* D664 800709C4 00E20224 */  addiu      $v0, $zero, -0x1E00
    /* D668 800709C8 740002AE */  sw         $v0, 0x74($s0)
    /* D66C 800709CC C0E00224 */  addiu      $v0, $zero, -0x1F40
    /* D670 800709D0 040002AE */  sw         $v0, 0x4($s0)
    /* D674 800709D4 204E0224 */  addiu      $v0, $zero, 0x4E20
    /* D678 800709D8 6C0000AE */  sw         $zero, 0x6C($s0)
    /* D67C 800709DC 7E0000A6 */  sh         $zero, 0x7E($s0)
    /* D680 800709E0 000000AE */  sw         $zero, 0x0($s0)
    /* D684 800709E4 080002AE */  sw         $v0, 0x8($s0)
    /* D688 800709E8 0C0000AE */  sw         $zero, 0xC($s0)
    /* D68C 800709EC 13C30108 */  j          .L80070C4C
    /* D690 800709F0 100000AE */   sw        $zero, 0x10($s0)
  jlabel .L800709F4
    /* D694 800709F4 001E0224 */  addiu      $v0, $zero, 0x1E00
    /* D698 800709F8 740002AE */  sw         $v0, 0x74($s0)
    /* D69C 800709FC 00080224 */  addiu      $v0, $zero, 0x800
    /* D6A0 80070A00 7E0002A6 */  sh         $v0, 0x7E($s0)
    /* D6A4 80070A04 C0E00224 */  addiu      $v0, $zero, -0x1F40
    /* D6A8 80070A08 040002AE */  sw         $v0, 0x4($s0)
    /* D6AC 80070A0C 204E0224 */  addiu      $v0, $zero, 0x4E20
    /* D6B0 80070A10 6C0000AE */  sw         $zero, 0x6C($s0)
    /* D6B4 80070A14 000000AE */  sw         $zero, 0x0($s0)
    /* D6B8 80070A18 080002AE */  sw         $v0, 0x8($s0)
    /* D6BC 80070A1C 0C0000AE */  sw         $zero, 0xC($s0)
    /* D6C0 80070A20 13C30108 */  j          .L80070C4C
    /* D6C4 80070A24 100000AE */   sw        $zero, 0x10($s0)
  jlabel .L80070A28
    /* D6C8 80070A28 21200002 */  addu       $a0, $s0, $zero
    /* D6CC 80070A2C 9000A527 */  addiu      $a1, $sp, 0x90
    /* D6D0 80070A30 00FC0224 */  addiu      $v0, $zero, -0x400
    /* D6D4 80070A34 9000A2AF */  sw         $v0, 0x90($sp)
    /* D6D8 80070A38 05AF0224 */  addiu      $v0, $zero, -0x50FB
    /* D6DC 80070A3C 9800A2AF */  sw         $v0, 0x98($sp)
    /* D6E0 80070A40 3A910224 */  addiu      $v0, $zero, -0x6EC6
    /* D6E4 80070A44 9C00A2AF */  sw         $v0, 0x9C($sp)
    /* D6E8 80070A48 64FD0224 */  addiu      $v0, $zero, -0x29C
    /* D6EC 80070A4C A400A0AF */  sw         $zero, 0xA4($sp)
    /* D6F0 80070A50 A800A0AF */  sw         $zero, 0xA8($sp)
    /* D6F4 80070A54 9400A0AF */  sw         $zero, 0x94($sp)
    /* D6F8 80070A58 62C1010C */  jal        Stg30_CamEaseToward
    /* D6FC 80070A5C A000A2AF */   sw        $v0, 0xA0($sp)
    /* D700 80070A60 14C30108 */  j          .L80070C50
    /* D704 80070A64 00000000 */   nop
  jlabel .L80070A68
    /* D708 80070A68 1800238E */  lw         $v1, 0x18($s1)
    /* D70C 80070A6C 00000000 */  nop
    /* D710 80070A70 03006010 */  beqz       $v1, .L80070A80
    /* D714 80070A74 01000224 */   addiu     $v0, $zero, 0x1
    /* D718 80070A78 09006210 */  beq        $v1, $v0, .L80070AA0
    /* D71C 80070A7C ECFA0224 */   addiu     $v0, $zero, -0x514
  .L80070A80:
    /* D720 80070A80 448E000C */  jal        Rand_Next
    /* D724 80070A84 00000000 */   nop
    /* D728 80070A88 0780033C */  lui        $v1, %hi(Stg30_CamShotVariant)
    /* D72C 80070A8C 03004230 */  andi       $v0, $v0, 0x3
    /* D730 80070A90 A04062AC */  sw         $v0, %lo(Stg30_CamShotVariant)($v1)
    /* D734 80070A94 6045000C */  jal        Task_NextState2
    /* D738 80070A98 21202002 */   addu      $a0, $s1, $zero
    /* D73C 80070A9C ECFA0224 */  addiu      $v0, $zero, -0x514
  .L80070AA0:
    /* D740 80070AA0 040002AE */  sw         $v0, 0x4($s0)
    /* D744 80070AA4 E02E0224 */  addiu      $v0, $zero, 0x2EE0
    /* D748 80070AA8 080002AE */  sw         $v0, 0x8($s0)
    /* D74C 80070AAC 88FA0224 */  addiu      $v0, $zero, -0x578
    /* D750 80070AB0 100002AE */  sw         $v0, 0x10($s0)
    /* D754 80070AB4 AA000224 */  addiu      $v0, $zero, 0xAA
    /* D758 80070AB8 000000AE */  sw         $zero, 0x0($s0)
    /* D75C 80070ABC 0C0000AE */  sw         $zero, 0xC($s0)
    /* D760 80070AC0 140000AE */  sw         $zero, 0x14($s0)
    /* D764 80070AC4 7E0002A6 */  sh         $v0, 0x7E($s0)
    /* D768 80070AC8 1400238E */  lw         $v1, 0x14($s1)
    /* D76C 80070ACC 00EC0224 */  addiu      $v0, $zero, -0x1400
    /* D770 80070AD0 740002AE */  sw         $v0, 0x74($s0)
    /* D774 80070AD4 F6FF6324 */  addiu      $v1, $v1, -0xA
    /* D778 80070AD8 80100300 */  sll        $v0, $v1, 2
    /* D77C 80070ADC 21104300 */  addu       $v0, $v0, $v1
    /* D780 80070AE0 40120200 */  sll        $v0, $v0, 9
    /* D784 80070AE4 80F34224 */  addiu      $v0, $v0, -0xC80
    /* D788 80070AE8 6C0002AE */  sw         $v0, 0x6C($s0)
    /* D78C 80070AEC 0780023C */  lui        $v0, %hi(Stg30_CamShotVariant)
    /* D790 80070AF0 A040438C */  lw         $v1, %lo(Stg30_CamShotVariant)($v0)
    /* D794 80070AF4 01000224 */  addiu      $v0, $zero, 0x1
    /* D798 80070AF8 05006210 */  beq        $v1, $v0, .L80070B10
    /* D79C 80070AFC 02000224 */   addiu     $v0, $zero, 0x2
    /* D7A0 80070B00 08006210 */  beq        $v1, $v0, .L80070B24
    /* D7A4 80070B04 ECE60224 */   addiu     $v0, $zero, -0x1914
    /* D7A8 80070B08 D5C20108 */  j          .L80070B54
    /* D7AC 80070B0C 00000000 */   nop
  .L80070B10:
    /* D7B0 80070B10 38000224 */  addiu      $v0, $zero, 0x38
    /* D7B4 80070B14 7E0002A6 */  sh         $v0, 0x7E($s0)
    /* D7B8 80070B18 1400238E */  lw         $v1, 0x14($s1)
    /* D7BC 80070B1C CEC20108 */  j          .L80070B38
    /* D7C0 80070B20 BC340224 */   addiu     $v0, $zero, 0x34BC
  .L80070B24:
    /* D7C4 80070B24 040002AE */  sw         $v0, 0x4($s0)
    /* D7C8 80070B28 1400238E */  lw         $v1, 0x14($s1)
    /* D7CC 80070B2C 00F10224 */  addiu      $v0, $zero, -0xF00
    /* D7D0 80070B30 740002AE */  sw         $v0, 0x74($s0)
    /* D7D4 80070B34 BC340224 */  addiu      $v0, $zero, 0x34BC
  .L80070B38:
    /* D7D8 80070B38 080002AE */  sw         $v0, 0x8($s0)
    /* D7DC 80070B3C F6FF6324 */  addiu      $v1, $v1, -0xA
    /* D7E0 80070B40 80100300 */  sll        $v0, $v1, 2
    /* D7E4 80070B44 21104300 */  addu       $v0, $v0, $v1
    /* D7E8 80070B48 40120200 */  sll        $v0, $v0, 9
    /* D7EC 80070B4C 00F64224 */  addiu      $v0, $v0, -0xA00
    /* D7F0 80070B50 6C0002AE */  sw         $v0, 0x6C($s0)
  .L80070B54:
    /* D7F4 80070B54 1400228E */  lw         $v0, 0x14($s1)
    /* D7F8 80070B58 00000000 */  nop
    /* D7FC 80070B5C 0D004228 */  slti       $v0, $v0, 0xD
    /* D800 80070B60 3B004014 */  bnez       $v0, .L80070C50
    /* D804 80070B64 00080224 */   addiu     $v0, $zero, 0x800
    /* D808 80070B68 7E000396 */  lhu        $v1, 0x7E($s0)
    /* D80C 80070B6C 00000000 */  nop
    /* D810 80070B70 23104300 */  subu       $v0, $v0, $v1
    /* D814 80070B74 7E0002A6 */  sh         $v0, 0x7E($s0)
    /* D818 80070B78 6C00028E */  lw         $v0, 0x6C($s0)
    /* D81C 80070B7C 7400038E */  lw         $v1, 0x74($s0)
    /* D820 80070B80 00E24224 */  addiu      $v0, $v0, -0x1E00
    /* D824 80070B84 23180300 */  negu       $v1, $v1
    /* D828 80070B88 6C0002AE */  sw         $v0, 0x6C($s0)
    /* D82C 80070B8C 14C30108 */  j          .L80070C50
    /* D830 80070B90 740003AE */   sw        $v1, 0x74($s0)
  jlabel .L80070B94
    /* D834 80070B94 24FA0224 */  addiu      $v0, $zero, -0x5DC
    /* D838 80070B98 040002AE */  sw         $v0, 0x4($s0)
    /* D83C 80070B9C E02E0224 */  addiu      $v0, $zero, 0x2EE0
    /* D840 80070BA0 080002AE */  sw         $v0, 0x8($s0)
    /* D844 80070BA4 C0F90224 */  addiu      $v0, $zero, -0x640
    /* D848 80070BA8 000000AE */  sw         $zero, 0x0($s0)
    /* D84C 80070BAC 0C0000AE */  sw         $zero, 0xC($s0)
    /* D850 80070BB0 100002AE */  sw         $v0, 0x10($s0)
    /* D854 80070BB4 140000AE */  sw         $zero, 0x14($s0)
    /* D858 80070BB8 1400228E */  lw         $v0, 0x14($s1)
    /* D85C 80070BBC 00000000 */  nop
    /* D860 80070BC0 13004228 */  slti       $v0, $v0, 0x13
    /* D864 80070BC4 07004010 */  beqz       $v0, .L80070BE4
    /* D868 80070BC8 AA000224 */   addiu     $v0, $zero, 0xAA
    /* D86C 80070BCC 7E0002A6 */  sh         $v0, 0x7E($s0)
    /* D870 80070BD0 1400238E */  lw         $v1, 0x14($s1)
    /* D874 80070BD4 00EC0224 */  addiu      $v0, $zero, -0x1400
    /* D878 80070BD8 740002AE */  sw         $v0, 0x74($s0)
    /* D87C 80070BDC FFC20108 */  j          .L80070BFC
    /* D880 80070BE0 F0FF6324 */   addiu     $v1, $v1, -0x10
  .L80070BE4:
    /* D884 80070BE4 55070224 */  addiu      $v0, $zero, 0x755
    /* D888 80070BE8 7E0002A6 */  sh         $v0, 0x7E($s0)
    /* D88C 80070BEC 1400238E */  lw         $v1, 0x14($s1)
    /* D890 80070BF0 00140224 */  addiu      $v0, $zero, 0x1400
    /* D894 80070BF4 740002AE */  sw         $v0, 0x74($s0)
    /* D898 80070BF8 EDFF6324 */  addiu      $v1, $v1, -0x13
  .L80070BFC:
    /* D89C 80070BFC 80100300 */  sll        $v0, $v1, 2
    /* D8A0 80070C00 21104300 */  addu       $v0, $v0, $v1
    /* D8A4 80070C04 40120200 */  sll        $v0, $v0, 9
    /* D8A8 80070C08 00F64224 */  addiu      $v0, $v0, -0xA00
    /* D8AC 80070C0C 14C30108 */  j          .L80070C50
    /* D8B0 80070C10 6C0002AE */   sw        $v0, 0x6C($s0)
  jlabel .L80070C14
    /* D8B4 80070C14 00EC0224 */  addiu      $v0, $zero, -0x1400
    /* D8B8 80070C18 740002AE */  sw         $v0, 0x74($s0)
    /* D8BC 80070C1C 38020224 */  addiu      $v0, $zero, 0x238
    /* D8C0 80070C20 7E0002A6 */  sh         $v0, 0x7E($s0)
    /* D8C4 80070C24 78EC0224 */  addiu      $v0, $zero, -0x1388
    /* D8C8 80070C28 040002AE */  sw         $v0, 0x4($s0)
    /* D8CC 80070C2C 983A0224 */  addiu      $v0, $zero, 0x3A98
    /* D8D0 80070C30 080002AE */  sw         $v0, 0x8($s0)
    /* D8D4 80070C34 18FC0224 */  addiu      $v0, $zero, -0x3E8
    /* D8D8 80070C38 6C0000AE */  sw         $zero, 0x6C($s0)
    /* D8DC 80070C3C 700000AE */  sw         $zero, 0x70($s0)
    /* D8E0 80070C40 000000AE */  sw         $zero, 0x0($s0)
    /* D8E4 80070C44 0C0000AE */  sw         $zero, 0xC($s0)
    /* D8E8 80070C48 100002AE */  sw         $v0, 0x10($s0)
  .L80070C4C:
    /* D8EC 80070C4C 140000AE */  sw         $zero, 0x14($s0)
  .L80070C50:
    /* D8F0 80070C50 BC00BF8F */  lw         $ra, 0xBC($sp)
    /* D8F4 80070C54 B800B28F */  lw         $s2, 0xB8($sp)
    /* D8F8 80070C58 B400B18F */  lw         $s1, 0xB4($sp)
    /* D8FC 80070C5C B000B08F */  lw         $s0, 0xB0($sp)
    /* D900 80070C60 0800E003 */  jr         $ra
    /* D904 80070C64 C000BD27 */   addiu     $sp, $sp, 0xC0
endlabel Stg30_CameraUpdate
