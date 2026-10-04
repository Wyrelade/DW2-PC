nonmatching Stg20_CameraUpdate, 0x4C0

glabel Stg20_CameraUpdate
    /* C3D0 8006F730 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* C3D4 8006F734 1400B1AF */  sw         $s1, 0x14($sp)
    /* C3D8 8006F738 21888000 */  addu       $s1, $a0, $zero
    /* C3DC 8006F73C 01000224 */  addiu      $v0, $zero, 0x1
    /* C3E0 8006F740 1800BFAF */  sw         $ra, 0x18($sp)
    /* C3E4 8006F744 1000B0AF */  sw         $s0, 0x10($sp)
    /* C3E8 8006F748 1000248E */  lw         $a0, 0x10($s1)
    /* C3EC 8006F74C 2C00308E */  lw         $s0, 0x2C($s1)
    /* C3F0 8006F750 2B008210 */  beq        $a0, $v0, .L8006F800
    /* C3F4 8006F754 02008228 */   slti      $v0, $a0, 0x2
    /* C3F8 8006F758 20014010 */  beqz       $v0, .L8006FBDC
    /* C3FC 8006F75C 00000000 */   nop
    /* C400 8006F760 1E018014 */  bnez       $a0, .L8006FBDC
    /* C404 8006F764 21200000 */   addu      $a0, $zero, $zero
    /* C408 8006F768 09AD000C */  jal        GsInitCoordinate2
    /* C40C 8006F76C 20000526 */   addiu     $a1, $s0, 0x20
    /* C410 8006F770 0680023C */  lui        $v0, %hi(Sys_GameMode)
    /* C414 8006F774 88F7428C */  lw         $v0, %lo(Sys_GameMode)($v0)
    /* C418 8006F778 00000000 */  nop
    /* C41C 8006F77C 2F034228 */  slti       $v0, $v0, 0x32F
    /* C420 8006F780 0A004010 */  beqz       $v0, .L8006F7AC
    /* C424 8006F784 A0050224 */   addiu     $v0, $zero, 0x5A0
    /* C428 8006F788 700002AE */  sw         $v0, 0x70($s0)
    /* C42C 8006F78C 00A30224 */  addiu      $v0, $zero, -0x5D00
    /* C430 8006F790 040002AE */  sw         $v0, 0x4($s0)
    /* C434 8006F794 00A60224 */  addiu      $v0, $zero, -0x5A00
    /* C438 8006F798 000000AE */  sw         $zero, 0x0($s0)
    /* C43C 8006F79C 080002AE */  sw         $v0, 0x8($s0)
    /* C440 8006F7A0 0C0000AE */  sw         $zero, 0xC($s0)
    /* C444 8006F7A4 F5BD0108 */  j          .L8006F7D4
    /* C448 8006F7A8 100000AE */   sw        $zero, 0x10($s0)
  .L8006F7AC:
    /* C44C 8006F7AC DC050224 */  addiu      $v0, $zero, 0x5DC
    /* C450 8006F7B0 700002AE */  sw         $v0, 0x70($s0)
    /* C454 8006F7B4 60F00224 */  addiu      $v0, $zero, -0xFA0
    /* C458 8006F7B8 040002AE */  sw         $v0, 0x4($s0)
    /* C45C 8006F7BC 88CA0224 */  addiu      $v0, $zero, -0x3578
    /* C460 8006F7C0 080002AE */  sw         $v0, 0x8($s0)
    /* C464 8006F7C4 18FC0224 */  addiu      $v0, $zero, -0x3E8
    /* C468 8006F7C8 000000AE */  sw         $zero, 0x0($s0)
    /* C46C 8006F7CC 0C0000AE */  sw         $zero, 0xC($s0)
    /* C470 8006F7D0 100002AE */  sw         $v0, 0x10($s0)
  .L8006F7D4:
    /* C474 8006F7D4 140000AE */  sw         $zero, 0x14($s0)
    /* C478 8006F7D8 21202002 */  addu       $a0, $s1, $zero
    /* C47C 8006F7DC 20000226 */  addiu      $v0, $s0, 0x20
    /* C480 8006F7E0 180000AE */  sw         $zero, 0x18($s0)
    /* C484 8006F7E4 1C0002AE */  sw         $v0, 0x1C($s0)
    /* C488 8006F7E8 880000A6 */  sh         $zero, 0x88($s0)
    /* C48C 8006F7EC 860000A6 */  sh         $zero, 0x86($s0)
    /* C490 8006F7F0 5145000C */  jal        Task_NextState0
    /* C494 8006F7F4 840000A6 */   sh        $zero, 0x84($s0)
    /* C498 8006F7F8 F7BE0108 */  j          .L8006FBDC
    /* C49C 8006F7FC 00000000 */   nop
  .L8006F800:
    /* C4A0 8006F800 0680023C */  lui        $v0, %hi(Sys_GameMode)
    /* C4A4 8006F804 88F7428C */  lw         $v0, %lo(Sys_GameMode)($v0)
    /* C4A8 8006F808 00000000 */  nop
    /* C4AC 8006F80C 2F034228 */  slti       $v0, $v0, 0x32F
    /* C4B0 8006F810 F2004014 */  bnez       $v0, .L8006FBDC
    /* C4B4 8006F814 00000000 */   nop
    /* C4B8 8006F818 1400238E */  lw         $v1, 0x14($s1)
    /* C4BC 8006F81C 00000000 */  nop
    /* C4C0 8006F820 0B006410 */  beq        $v1, $a0, .L8006F850
    /* C4C4 8006F824 02006228 */   slti      $v0, $v1, 0x2
    /* C4C8 8006F828 04004014 */  bnez       $v0, .L8006F83C
    /* C4CC 8006F82C 60F00224 */   addiu     $v0, $zero, -0xFA0
    /* C4D0 8006F830 02000224 */  addiu      $v0, $zero, 0x2
    /* C4D4 8006F834 69006210 */  beq        $v1, $v0, .L8006F9DC
    /* C4D8 8006F838 60F00224 */   addiu     $v0, $zero, -0xFA0
  .L8006F83C:
    /* C4DC 8006F83C 040002AE */  sw         $v0, 0x4($s0)
    /* C4E0 8006F840 88CA0224 */  addiu      $v0, $zero, -0x3578
    /* C4E4 8006F844 080002AE */  sw         $v0, 0x8($s0)
    /* C4E8 8006F848 F7BE0108 */  j          .L8006FBDC
    /* C4EC 8006F84C 900000AE */   sw        $zero, 0x90($s0)
  .L8006F850:
    /* C4F0 8006F850 1800238E */  lw         $v1, 0x18($s1)
    /* C4F4 8006F854 00000000 */  nop
    /* C4F8 8006F858 0500622C */  sltiu      $v0, $v1, 0x5
    /* C4FC 8006F85C 08004010 */  beqz       $v0, .L8006F880
    /* C500 8006F860 0680023C */   lui       $v0, %hi(jtbl_800635E4)
    /* C504 8006F864 E4354224 */  addiu      $v0, $v0, %lo(jtbl_800635E4)
    /* C508 8006F868 80180300 */  sll        $v1, $v1, 2
    /* C50C 8006F86C 21186200 */  addu       $v1, $v1, $v0
    /* C510 8006F870 0000628C */  lw         $v0, 0x0($v1)
    /* C514 8006F874 00000000 */  nop
    /* C518 8006F878 08004000 */  jr         $v0
    /* C51C 8006F87C 00000000 */   nop
  jlabel .L8006F880
    /* C520 8006F880 0400038E */  lw         $v1, 0x4($s0)
    /* C524 8006F884 00000000 */  nop
    /* C528 8006F888 F1D86228 */  slti       $v0, $v1, -0x270F
    /* C52C 8006F88C 04004014 */  bnez       $v0, .L8006F8A0
    /* C530 8006F890 21202002 */   addu      $a0, $s1, $zero
    /* C534 8006F894 0CFE6224 */  addiu      $v0, $v1, -0x1F4
    /* C538 8006F898 6DBE0108 */  j          .L8006F9B4
    /* C53C 8006F89C 040002AE */   sw        $v0, 0x4($s0)
  .L8006F8A0:
    /* C540 8006F8A0 F0D80224 */  addiu      $v0, $zero, -0x2710
    /* C544 8006F8A4 6045000C */  jal        Task_NextState2
    /* C548 8006F8A8 040002AE */   sw        $v0, 0x4($s0)
    /* C54C 8006F8AC 7B000224 */  addiu      $v0, $zero, 0x7B
    /* C550 8006F8B0 8C0002AE */  sw         $v0, 0x8C($s0)
  jlabel .L8006F8B4
    /* C554 8006F8B4 9000028E */  lw         $v0, 0x90($s0)
    /* C558 8006F8B8 8C00038E */  lw         $v1, 0x8C($s0)
    /* C55C 8006F8BC 40084224 */  addiu      $v0, $v0, 0x840
    /* C560 8006F8C0 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* C564 8006F8C4 900002AE */  sw         $v0, 0x90($s0)
    /* C568 8006F8C8 3A006014 */  bnez       $v1, .L8006F9B4
    /* C56C 8006F8CC 8C0003AE */   sw        $v1, 0x8C($s0)
    /* C570 8006F8D0 6045000C */  jal        Task_NextState2
    /* C574 8006F8D4 21202002 */   addu      $a0, $s1, $zero
    /* C578 8006F8D8 0F000224 */  addiu      $v0, $zero, 0xF
    /* C57C 8006F8DC 8C0002AE */  sw         $v0, 0x8C($s0)
    /* C580 8006F8E0 4E71000C */  jal        Gfx_FadeOutToWhite
    /* C584 8006F8E4 14000424 */   addiu     $a0, $zero, 0x14
  jlabel .L8006F8E8
    /* C588 8006F8E8 9000028E */  lw         $v0, 0x90($s0)
    /* C58C 8006F8EC 0800038E */  lw         $v1, 0x8($s0)
    /* C590 8006F8F0 40084224 */  addiu      $v0, $v0, 0x840
    /* C594 8006F8F4 900002AE */  sw         $v0, 0x90($s0)
    /* C598 8006F8F8 0400028E */  lw         $v0, 0x4($s0)
    /* C59C 8006F8FC 90036324 */  addiu      $v1, $v1, 0x390
    /* C5A0 8006F900 080003AE */  sw         $v1, 0x8($s0)
    /* C5A4 8006F904 8C00038E */  lw         $v1, 0x8C($s0)
    /* C5A8 8006F908 9A024224 */  addiu      $v0, $v0, 0x29A
    /* C5AC 8006F90C FFFF6324 */  addiu      $v1, $v1, -0x1
    /* C5B0 8006F910 040002AE */  sw         $v0, 0x4($s0)
    /* C5B4 8006F914 27006014 */  bnez       $v1, .L8006F9B4
    /* C5B8 8006F918 8C0003AE */   sw        $v1, 0x8C($s0)
    /* C5BC 8006F91C 6045000C */  jal        Task_NextState2
    /* C5C0 8006F920 21202002 */   addu      $a0, $s1, $zero
    /* C5C4 8006F924 0F000224 */  addiu      $v0, $zero, 0xF
    /* C5C8 8006F928 8C0002AE */  sw         $v0, 0x8C($s0)
    /* C5CC 8006F92C 4371000C */  jal        Gfx_FadeInFromWhite
    /* C5D0 8006F930 14000424 */   addiu     $a0, $zero, 0x14
  jlabel .L8006F934
    /* C5D4 8006F934 9000028E */  lw         $v0, 0x90($s0)
    /* C5D8 8006F938 0800038E */  lw         $v1, 0x8($s0)
    /* C5DC 8006F93C 80EF4224 */  addiu      $v0, $v0, -0x1080
    /* C5E0 8006F940 900002AE */  sw         $v0, 0x90($s0)
    /* C5E4 8006F944 0400028E */  lw         $v0, 0x4($s0)
    /* C5E8 8006F948 70FC6324 */  addiu      $v1, $v1, -0x390
    /* C5EC 8006F94C 080003AE */  sw         $v1, 0x8($s0)
    /* C5F0 8006F950 8C00038E */  lw         $v1, 0x8C($s0)
    /* C5F4 8006F954 F6FE4224 */  addiu      $v0, $v0, -0x10A
    /* C5F8 8006F958 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* C5FC 8006F95C 040002AE */  sw         $v0, 0x4($s0)
    /* C600 8006F960 14006014 */  bnez       $v1, .L8006F9B4
    /* C604 8006F964 8C0003AE */   sw        $v1, 0x8C($s0)
    /* C608 8006F968 6045000C */  jal        Task_NextState2
    /* C60C 8006F96C 21202002 */   addu      $a0, $s1, $zero
    /* C610 8006F970 78000224 */  addiu      $v0, $zero, 0x78
    /* C614 8006F974 8C0002AE */  sw         $v0, 0x8C($s0)
  jlabel .L8006F978
    /* C618 8006F978 9000028E */  lw         $v0, 0x90($s0)
    /* C61C 8006F97C 00000000 */  nop
    /* C620 8006F980 03004018 */  blez       $v0, .L8006F990
    /* C624 8006F984 80EF4224 */   addiu     $v0, $v0, -0x1080
    /* C628 8006F988 65BE0108 */  j          .L8006F994
    /* C62C 8006F98C 900002AE */   sw        $v0, 0x90($s0)
  .L8006F990:
    /* C630 8006F990 900000AE */  sw         $zero, 0x90($s0)
  .L8006F994:
    /* C634 8006F994 8C00028E */  lw         $v0, 0x8C($s0)
    /* C638 8006F998 00000000 */  nop
    /* C63C 8006F99C FFFF4224 */  addiu      $v0, $v0, -0x1
    /* C640 8006F9A0 04004014 */  bnez       $v0, .L8006F9B4
    /* C644 8006F9A4 8C0002AE */   sw        $v0, 0x8C($s0)
    /* C648 8006F9A8 21202002 */  addu       $a0, $s1, $zero
    /* C64C 8006F9AC 7745000C */  jal        Task_SetState1
    /* C650 8006F9B0 21280000 */   addu      $a1, $zero, $zero
  .L8006F9B4:
    /* C654 8006F9B4 9000038E */  lw         $v1, 0x90($s0)
    /* C658 8006F9B8 00000000 */  nop
    /* C65C 8006F9BC 02006104 */  bgez       $v1, .L8006F9C8
    /* C660 8006F9C0 00000000 */   nop
    /* C664 8006F9C4 FF006324 */  addiu      $v1, $v1, 0xFF
  .L8006F9C8:
    /* C668 8006F9C8 86000296 */  lhu        $v0, 0x86($s0)
    /* C66C 8006F9CC 031A0300 */  sra        $v1, $v1, 8
    /* C670 8006F9D0 23104300 */  subu       $v0, $v0, $v1
    /* C674 8006F9D4 E9BE0108 */  j          .L8006FBA4
    /* C678 8006F9D8 860002A6 */   sh        $v0, 0x86($s0)
  .L8006F9DC:
    /* C67C 8006F9DC 1800238E */  lw         $v1, 0x18($s1)
    /* C680 8006F9E0 00000000 */  nop
    /* C684 8006F9E4 0500622C */  sltiu      $v0, $v1, 0x5
    /* C688 8006F9E8 08004010 */  beqz       $v0, .L8006FA0C
    /* C68C 8006F9EC 0680023C */   lui       $v0, %hi(jtbl_800635FC)
    /* C690 8006F9F0 FC354224 */  addiu      $v0, $v0, %lo(jtbl_800635FC)
    /* C694 8006F9F4 80180300 */  sll        $v1, $v1, 2
    /* C698 8006F9F8 21186200 */  addu       $v1, $v1, $v0
    /* C69C 8006F9FC 0000628C */  lw         $v0, 0x0($v1)
    /* C6A0 8006FA00 00000000 */  nop
    /* C6A4 8006FA04 08004000 */  jr         $v0
    /* C6A8 8006FA08 00000000 */   nop
  jlabel .L8006FA0C
    /* C6AC 8006FA0C 0400038E */  lw         $v1, 0x4($s0)
    /* C6B0 8006FA10 00000000 */  nop
    /* C6B4 8006FA14 F1D86228 */  slti       $v0, $v1, -0x270F
    /* C6B8 8006FA18 04004014 */  bnez       $v0, .L8006FA2C
    /* C6BC 8006FA1C 21202002 */   addu      $a0, $s1, $zero
    /* C6C0 8006FA20 0CFE6224 */  addiu      $v0, $v1, -0x1F4
    /* C6C4 8006FA24 CBBE0108 */  j          .L8006FB2C
    /* C6C8 8006FA28 040002AE */   sw        $v0, 0x4($s0)
  .L8006FA2C:
    /* C6CC 8006FA2C F0D80224 */  addiu      $v0, $zero, -0x2710
    /* C6D0 8006FA30 6045000C */  jal        Task_NextState2
    /* C6D4 8006FA34 040002AE */   sw        $v0, 0x4($s0)
    /* C6D8 8006FA38 7B000224 */  addiu      $v0, $zero, 0x7B
    /* C6DC 8006FA3C 8C0002AE */  sw         $v0, 0x8C($s0)
  jlabel .L8006FA40
    /* C6E0 8006FA40 9000028E */  lw         $v0, 0x90($s0)
    /* C6E4 8006FA44 8C00038E */  lw         $v1, 0x8C($s0)
    /* C6E8 8006FA48 40084224 */  addiu      $v0, $v0, 0x840
    /* C6EC 8006FA4C FFFF6324 */  addiu      $v1, $v1, -0x1
    /* C6F0 8006FA50 900002AE */  sw         $v0, 0x90($s0)
    /* C6F4 8006FA54 35006014 */  bnez       $v1, .L8006FB2C
    /* C6F8 8006FA58 8C0003AE */   sw        $v1, 0x8C($s0)
    /* C6FC 8006FA5C 6045000C */  jal        Task_NextState2
    /* C700 8006FA60 21202002 */   addu      $a0, $s1, $zero
    /* C704 8006FA64 0F000224 */  addiu      $v0, $zero, 0xF
    /* C708 8006FA68 8C0002AE */  sw         $v0, 0x8C($s0)
    /* C70C 8006FA6C 4E71000C */  jal        Gfx_FadeOutToWhite
    /* C710 8006FA70 14000424 */   addiu     $a0, $zero, 0x14
  jlabel .L8006FA74
    /* C714 8006FA74 9000028E */  lw         $v0, 0x90($s0)
    /* C718 8006FA78 0800038E */  lw         $v1, 0x8($s0)
    /* C71C 8006FA7C 40084224 */  addiu      $v0, $v0, 0x840
    /* C720 8006FA80 900002AE */  sw         $v0, 0x90($s0)
    /* C724 8006FA84 0400028E */  lw         $v0, 0x4($s0)
    /* C728 8006FA88 90036324 */  addiu      $v1, $v1, 0x390
    /* C72C 8006FA8C 080003AE */  sw         $v1, 0x8($s0)
    /* C730 8006FA90 8C00038E */  lw         $v1, 0x8C($s0)
    /* C734 8006FA94 9A024224 */  addiu      $v0, $v0, 0x29A
    /* C738 8006FA98 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* C73C 8006FA9C 040002AE */  sw         $v0, 0x4($s0)
    /* C740 8006FAA0 22006014 */  bnez       $v1, .L8006FB2C
    /* C744 8006FAA4 8C0003AE */   sw        $v1, 0x8C($s0)
    /* C748 8006FAA8 6045000C */  jal        Task_NextState2
    /* C74C 8006FAAC 21202002 */   addu      $a0, $s1, $zero
    /* C750 8006FAB0 0F000224 */  addiu      $v0, $zero, 0xF
    /* C754 8006FAB4 8C0002AE */  sw         $v0, 0x8C($s0)
    /* C758 8006FAB8 4371000C */  jal        Gfx_FadeInFromWhite
    /* C75C 8006FABC 14000424 */   addiu     $a0, $zero, 0x14
  jlabel .L8006FAC0
    /* C760 8006FAC0 9000028E */  lw         $v0, 0x90($s0)
    /* C764 8006FAC4 0800038E */  lw         $v1, 0x8($s0)
    /* C768 8006FAC8 C0F74224 */  addiu      $v0, $v0, -0x840
    /* C76C 8006FACC 900002AE */  sw         $v0, 0x90($s0)
    /* C770 8006FAD0 0400028E */  lw         $v0, 0x4($s0)
    /* C774 8006FAD4 70FC6324 */  addiu      $v1, $v1, -0x390
    /* C778 8006FAD8 080003AE */  sw         $v1, 0x8($s0)
    /* C77C 8006FADC 8C00038E */  lw         $v1, 0x8C($s0)
    /* C780 8006FAE0 F6FE4224 */  addiu      $v0, $v0, -0x10A
    /* C784 8006FAE4 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* C788 8006FAE8 040002AE */  sw         $v0, 0x4($s0)
    /* C78C 8006FAEC 0F006014 */  bnez       $v1, .L8006FB2C
    /* C790 8006FAF0 8C0003AE */   sw        $v1, 0x8C($s0)
    /* C794 8006FAF4 6045000C */  jal        Task_NextState2
    /* C798 8006FAF8 21202002 */   addu      $a0, $s1, $zero
    /* C79C 8006FAFC 78000224 */  addiu      $v0, $zero, 0x78
    /* C7A0 8006FB00 8C0002AE */  sw         $v0, 0x8C($s0)
  jlabel .L8006FB04
    /* C7A4 8006FB04 9000028E */  lw         $v0, 0x90($s0)
    /* C7A8 8006FB08 8C00038E */  lw         $v1, 0x8C($s0)
    /* C7AC 8006FB0C C0F74224 */  addiu      $v0, $v0, -0x840
    /* C7B0 8006FB10 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* C7B4 8006FB14 900002AE */  sw         $v0, 0x90($s0)
    /* C7B8 8006FB18 04006014 */  bnez       $v1, .L8006FB2C
    /* C7BC 8006FB1C 8C0003AE */   sw        $v1, 0x8C($s0)
    /* C7C0 8006FB20 21202002 */  addu       $a0, $s1, $zero
    /* C7C4 8006FB24 7745000C */  jal        Task_SetState1
    /* C7C8 8006FB28 21280000 */   addu      $a1, $zero, $zero
  .L8006FB2C:
    /* C7CC 8006FB2C 0A030424 */  addiu      $a0, $zero, 0x30A
    /* C7D0 8006FB30 FFFF0524 */  addiu      $a1, $zero, -0x1
    /* C7D4 8006FB34 4445000C */  jal        Task_FindFirst
    /* C7D8 8006FB38 21300000 */   addu      $a2, $zero, $zero
    /* C7DC 8006FB3C 0B004010 */  beqz       $v0, .L8006FB6C
    /* C7E0 8006FB40 0A030424 */   addiu     $a0, $zero, 0x30A
    /* C7E4 8006FB44 9000038E */  lw         $v1, 0x90($s0)
    /* C7E8 8006FB48 3800448C */  lw         $a0, 0x38($v0)
    /* C7EC 8006FB4C 02006104 */  bgez       $v1, .L8006FB58
    /* C7F0 8006FB50 00000000 */   nop
    /* C7F4 8006FB54 FF006324 */  addiu      $v1, $v1, 0xFF
  .L8006FB58:
    /* C7F8 8006FB58 42008294 */  lhu        $v0, 0x42($a0)
    /* C7FC 8006FB5C 031A0300 */  sra        $v1, $v1, 8
    /* C800 8006FB60 21104300 */  addu       $v0, $v0, $v1
    /* C804 8006FB64 420082A4 */  sh         $v0, 0x42($a0)
    /* C808 8006FB68 0A030424 */  addiu      $a0, $zero, 0x30A
  .L8006FB6C:
    /* C80C 8006FB6C FFFF0524 */  addiu      $a1, $zero, -0x1
    /* C810 8006FB70 4445000C */  jal        Task_FindFirst
    /* C814 8006FB74 01000624 */   addiu     $a2, $zero, 0x1
    /* C818 8006FB78 0A004010 */  beqz       $v0, .L8006FBA4
    /* C81C 8006FB7C 00000000 */   nop
    /* C820 8006FB80 9000038E */  lw         $v1, 0x90($s0)
    /* C824 8006FB84 3800448C */  lw         $a0, 0x38($v0)
    /* C828 8006FB88 02006104 */  bgez       $v1, .L8006FB94
    /* C82C 8006FB8C 00000000 */   nop
    /* C830 8006FB90 FF006324 */  addiu      $v1, $v1, 0xFF
  .L8006FB94:
    /* C834 8006FB94 42008294 */  lhu        $v0, 0x42($a0)
    /* C838 8006FB98 031A0300 */  sra        $v1, $v1, 8
    /* C83C 8006FB9C 23104300 */  subu       $v0, $v0, $v1
    /* C840 8006FBA0 420082A4 */  sh         $v0, 0x42($a0)
  .L8006FBA4:
    /* C844 8006FBA4 0780023C */  lui        $v0, %hi(Stg20_LabIsDna)
    /* C848 8006FBA8 EC09428C */  lw         $v0, %lo(Stg20_LabIsDna)($v0)
    /* C84C 8006FBAC 00000000 */  nop
    /* C850 8006FBB0 0A004014 */  bnez       $v0, .L8006FBDC
    /* C854 8006FBB4 07000424 */   addiu     $a0, $zero, 0x7
    /* C858 8006FBB8 FFFF0524 */  addiu      $a1, $zero, -0x1
    /* C85C 8006FBBC 4445000C */  jal        Task_FindFirst
    /* C860 8006FBC0 2130A000 */   addu      $a2, $a1, $zero
    /* C864 8006FBC4 05004010 */  beqz       $v0, .L8006FBDC
    /* C868 8006FBC8 00000000 */   nop
    /* C86C 8006FBCC 3800438C */  lw         $v1, 0x38($v0)
    /* C870 8006FBD0 86000296 */  lhu        $v0, 0x86($s0)
    /* C874 8006FBD4 00000000 */  nop
    /* C878 8006FBD8 420062A4 */  sh         $v0, 0x42($v1)
  .L8006FBDC:
    /* C87C 8006FBDC 1800BF8F */  lw         $ra, 0x18($sp)
    /* C880 8006FBE0 1400B18F */  lw         $s1, 0x14($sp)
    /* C884 8006FBE4 1000B08F */  lw         $s0, 0x10($sp)
    /* C888 8006FBE8 0800E003 */  jr         $ra
    /* C88C 8006FBEC 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Stg20_CameraUpdate
