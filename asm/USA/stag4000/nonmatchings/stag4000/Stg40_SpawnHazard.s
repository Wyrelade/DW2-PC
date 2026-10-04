nonmatching Stg40_SpawnHazard, 0x274

glabel Stg40_SpawnHazard
    /* A808 8006DB68 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* A80C 8006DB6C 3000B2AF */  sw         $s2, 0x30($sp)
    /* A810 8006DB70 21908000 */  addu       $s2, $a0, $zero
    /* A814 8006DB74 2800B0AF */  sw         $s0, 0x28($sp)
    /* A818 8006DB78 2180A000 */  addu       $s0, $a1, $zero
    /* A81C 8006DB7C 21100002 */  addu       $v0, $s0, $zero
    /* A820 8006DB80 2148C000 */  addu       $t1, $a2, $zero
    /* A824 8006DB84 3400BFAF */  sw         $ra, 0x34($sp)
    /* A828 8006DB88 02000016 */  bnez       $s0, .L8006DB94
    /* A82C 8006DB8C 2C00B1AF */   sw        $s1, 0x2C($sp)
    /* A830 8006DB90 01000224 */  addiu      $v0, $zero, 0x1
  .L8006DB94:
    /* A834 8006DB94 21804000 */  addu       $s0, $v0, $zero
    /* A838 8006DB98 0900422E */  sltiu      $v0, $s2, 0x9
    /* A83C 8006DB9C 08004010 */  beqz       $v0, .L8006DBC0
    /* A840 8006DBA0 0680023C */   lui       $v0, %hi(jtbl_80063640)
    /* A844 8006DBA4 40364224 */  addiu      $v0, $v0, %lo(jtbl_80063640)
    /* A848 8006DBA8 80181200 */  sll        $v1, $s2, 2
    /* A84C 8006DBAC 21186200 */  addu       $v1, $v1, $v0
    /* A850 8006DBB0 0000628C */  lw         $v0, 0x0($v1)
    /* A854 8006DBB4 00000000 */  nop
    /* A858 8006DBB8 08004000 */  jr         $v0
    /* A85C 8006DBBC 00000000 */   nop
  jlabel .L8006DBC0
    /* A860 8006DBC0 71B70108 */  j          .L8006DDC4
    /* A864 8006DBC4 21100000 */   addu      $v0, $zero, $zero
  jlabel .L8006DBC8
    /* A868 8006DBC8 05000324 */  addiu      $v1, $zero, 0x5
    /* A86C 8006DBCC 2A100302 */  slt        $v0, $s0, $v1
    /* A870 8006DBD0 02004010 */  beqz       $v0, .L8006DBDC
    /* A874 8006DBD4 00000000 */   nop
    /* A878 8006DBD8 21180002 */  addu       $v1, $s0, $zero
  .L8006DBDC:
    /* A87C 8006DBDC 21806000 */  addu       $s0, $v1, $zero
    /* A880 8006DBE0 5A026624 */  addiu      $a2, $v1, 0x25A
    /* A884 8006DBE4 06000424 */  addiu      $a0, $zero, 0x6
    /* A888 8006DBE8 45B70108 */  j          .L8006DD14
    /* A88C 8006DBEC FFFF0826 */   addiu     $t0, $s0, -0x1
  jlabel .L8006DBF0
    /* A890 8006DBF0 05000324 */  addiu      $v1, $zero, 0x5
    /* A894 8006DBF4 2A100302 */  slt        $v0, $s0, $v1
    /* A898 8006DBF8 02004010 */  beqz       $v0, .L8006DC04
    /* A89C 8006DBFC 00000000 */   nop
    /* A8A0 8006DC00 21180002 */  addu       $v1, $s0, $zero
  .L8006DC04:
    /* A8A4 8006DC04 21806000 */  addu       $s0, $v1, $zero
    /* A8A8 8006DC08 5F026624 */  addiu      $a2, $v1, 0x25F
    /* A8AC 8006DC0C 07000424 */  addiu      $a0, $zero, 0x7
    /* A8B0 8006DC10 45B70108 */  j          .L8006DD14
    /* A8B4 8006DC14 04000826 */   addiu     $t0, $s0, 0x4
  jlabel .L8006DC18
    /* A8B8 8006DC18 05000324 */  addiu      $v1, $zero, 0x5
    /* A8BC 8006DC1C 2A100302 */  slt        $v0, $s0, $v1
    /* A8C0 8006DC20 02004010 */  beqz       $v0, .L8006DC2C
    /* A8C4 8006DC24 00000000 */   nop
    /* A8C8 8006DC28 21180002 */  addu       $v1, $s0, $zero
  .L8006DC2C:
    /* A8CC 8006DC2C 21806000 */  addu       $s0, $v1, $zero
    /* A8D0 8006DC30 70026624 */  addiu      $a2, $v1, 0x270
    /* A8D4 8006DC34 08000424 */  addiu      $a0, $zero, 0x8
    /* A8D8 8006DC38 45B70108 */  j          .L8006DD14
    /* A8DC 8006DC3C 09000826 */   addiu     $t0, $s0, 0x9
  jlabel .L8006DC40
    /* A8E0 8006DC40 0680023C */  lui        $v0, %hi(Stg40_BugModelIds)
    /* A8E4 8006DC44 2C364D24 */  addiu      $t5, $v0, %lo(Stg40_BugModelIds)
    /* A8E8 8006DC48 0000AA8D */  lw         $t2, 0x0($t5)
    /* A8EC 8006DC4C 0400AB8D */  lw         $t3, 0x4($t5)
    /* A8F0 8006DC50 0800AC8D */  lw         $t4, 0x8($t5)
    /* A8F4 8006DC54 1800AAAF */  sw         $t2, 0x18($sp)
    /* A8F8 8006DC58 1C00ABAF */  sw         $t3, 0x1C($sp)
    /* A8FC 8006DC5C 2000ACAF */  sw         $t4, 0x20($sp)
    /* A900 8006DC60 0C00AA8D */  lw         $t2, 0xC($t5)
    /* A904 8006DC64 00000000 */  nop
    /* A908 8006DC68 2400AAAF */  sw         $t2, 0x24($sp)
    /* A90C 8006DC6C 03000324 */  addiu      $v1, $zero, 0x3
    /* A910 8006DC70 2A100302 */  slt        $v0, $s0, $v1
    /* A914 8006DC74 02004010 */  beqz       $v0, .L8006DC80
    /* A918 8006DC78 1800A527 */   addiu     $a1, $sp, 0x18
    /* A91C 8006DC7C 21180002 */  addu       $v1, $s0, $zero
  .L8006DC80:
    /* A920 8006DC80 21806000 */  addu       $s0, $v1, $zero
    /* A924 8006DC84 04004426 */  addiu      $a0, $s2, 0x4
    /* A928 8006DC88 FBFF4226 */  addiu      $v0, $s2, -0x5
    /* A92C 8006DC8C 80100200 */  sll        $v0, $v0, 2
    /* A930 8006DC90 2110A200 */  addu       $v0, $a1, $v0
    /* A934 8006DC94 0000428C */  lw         $v0, 0x0($v0)
    /* A938 8006DC98 05000326 */  addiu      $v1, $s0, 0x5
    /* A93C 8006DC9C 21408300 */  addu       $t0, $a0, $v1
    /* A940 8006DCA0 21105000 */  addu       $v0, $v0, $s0
    /* A944 8006DCA4 45B70108 */  j          .L8006DD14
    /* A948 8006DCA8 FFFF4624 */   addiu     $a2, $v0, -0x1
  jlabel .L8006DCAC
    /* A94C 8006DCAC 05000424 */  addiu      $a0, $zero, 0x5
    /* A950 8006DCB0 2A100402 */  slt        $v0, $s0, $a0
    /* A954 8006DCB4 02004010 */  beqz       $v0, .L8006DCC0
    /* A958 8006DCB8 0580083C */   lui       $t0, %hi(Dung_StatePtr)
    /* A95C 8006DCBC 21200002 */  addu       $a0, $s0, $zero
  .L8006DCC0:
    /* A960 8006DCC0 1C07058D */  lw         $a1, %lo(Dung_StatePtr)($t0)
    /* A964 8006DCC4 00000000 */  nop
    /* A968 8006DCC8 1400A384 */  lh         $v1, 0x14($a1)
    /* A96C 8006DCCC 00000000 */  nop
    /* A970 8006DCD0 64006228 */  slti       $v0, $v1, 0x64
    /* A974 8006DCD4 28004010 */  beqz       $v0, .L8006DD78
    /* A978 8006DCD8 21808000 */   addu      $s0, $a0, $zero
    /* A97C 8006DCDC 40100300 */  sll        $v0, $v1, 1
    /* A980 8006DCE0 21104300 */  addu       $v0, $v0, $v1
    /* A984 8006DCE4 080D4224 */  addiu      $v0, $v0, 0xD08
    /* A988 8006DCE8 2110A200 */  addu       $v0, $a1, $v0
    /* A98C 8006DCEC 000049A0 */  sb         $t1, 0x0($v0)
    /* A990 8006DCF0 010047A0 */  sb         $a3, 0x1($v0)
    /* A994 8006DCF4 020050A0 */  sb         $s0, 0x2($v0)
    /* A998 8006DCF8 1C07048D */  lw         $a0, %lo(Dung_StatePtr)($t0)
    /* A99C 8006DCFC 00000000 */  nop
    /* A9A0 8006DD00 14008394 */  lhu        $v1, 0x14($a0)
    /* A9A4 8006DD04 21100000 */  addu       $v0, $zero, $zero
    /* A9A8 8006DD08 01006324 */  addiu      $v1, $v1, 0x1
    /* A9AC 8006DD0C 71B70108 */  j          .L8006DDC4
    /* A9B0 8006DD10 140083A4 */   sh        $v1, 0x14($a0)
  .L8006DD14:
    /* A9B4 8006DD14 0780023C */  lui        $v0, %hi(Stg40_RootState)
    /* A9B8 8006DD18 602B458C */  lw         $a1, %lo(Stg40_RootState)($v0)
    /* A9BC 8006DD1C 00000000 */  nop
    /* A9C0 8006DD20 8801A38C */  lw         $v1, 0x188($a1)
    /* A9C4 8006DD24 00000000 */  nop
    /* A9C8 8006DD28 24100301 */  and        $v0, $t0, $v1
    /* A9CC 8006DD2C 0B004014 */  bnez       $v0, .L8006DD5C
    /* A9D0 8006DD30 0580113C */   lui       $s1, %hi(Dung_StatePtr)
    /* A9D4 8006DD34 8C01A284 */  lh         $v0, 0x18C($a1)
    /* A9D8 8006DD38 00000000 */  nop
    /* A9DC 8006DD3C 0C004228 */  slti       $v0, $v0, 0xC
    /* A9E0 8006DD40 0D004010 */  beqz       $v0, .L8006DD78
    /* A9E4 8006DD44 25186800 */   or        $v1, $v1, $t0
    /* A9E8 8006DD48 8C01A294 */  lhu        $v0, 0x18C($a1)
    /* A9EC 8006DD4C 8801A3AC */  sw         $v1, 0x188($a1)
    /* A9F0 8006DD50 01004224 */  addiu      $v0, $v0, 0x1
    /* A9F4 8006DD54 8C01A2A4 */  sh         $v0, 0x18C($a1)
    /* A9F8 8006DD58 0580113C */  lui        $s1, %hi(Dung_StatePtr)
  .L8006DD5C:
    /* A9FC 8006DD5C 1C07228E */  lw         $v0, %lo(Dung_StatePtr)($s1)
    /* AA00 8006DD60 00000000 */  nop
    /* AA04 8006DD64 12004284 */  lh         $v0, 0x12($v0)
    /* AA08 8006DD68 00000000 */  nop
    /* AA0C 8006DD6C 10004228 */  slti       $v0, $v0, 0x10
    /* AA10 8006DD70 03004014 */  bnez       $v0, .L8006DD80
    /* AA14 8006DD74 00140900 */   sll       $v0, $t1, 16
  .L8006DD78:
    /* AA18 8006DD78 71B70108 */  j          .L8006DDC4
    /* AA1C 8006DD7C FFFF0224 */   addiu     $v0, $zero, -0x1
  .L8006DD80:
    /* AA20 8006DD80 03140200 */  sra        $v0, $v0, 16
    /* AA24 8006DD84 1000A2AF */  sw         $v0, 0x10($sp)
    /* AA28 8006DD88 00140700 */  sll        $v0, $a3, 16
    /* AA2C 8006DD8C 03140200 */  sra        $v0, $v0, 16
    /* AA30 8006DD90 21284002 */  addu       $a1, $s2, $zero
    /* AA34 8006DD94 21380000 */  addu       $a3, $zero, $zero
    /* AA38 8006DD98 38B5010C */  jal        Stg40_AddEntity
    /* AA3C 8006DD9C 1400A2AF */   sw        $v0, 0x14($sp)
    /* AA40 8006DDA0 1C07248E */  lw         $a0, %lo(Dung_StatePtr)($s1)
    /* AA44 8006DDA4 00000000 */  nop
    /* AA48 8006DDA8 12008384 */  lh         $v1, 0x12($a0)
    /* AA4C 8006DDAC 21100000 */  addu       $v0, $zero, $zero
    /* AA50 8006DDB0 40180300 */  sll        $v1, $v1, 1
    /* AA54 8006DDB4 E60C6324 */  addiu      $v1, $v1, 0xCE6
    /* AA58 8006DDB8 21208300 */  addu       $a0, $a0, $v1
    /* AA5C 8006DDBC 000092A0 */  sb         $s2, 0x0($a0)
    /* AA60 8006DDC0 010090A0 */  sb         $s0, 0x1($a0)
  .L8006DDC4:
    /* AA64 8006DDC4 3400BF8F */  lw         $ra, 0x34($sp)
    /* AA68 8006DDC8 3000B28F */  lw         $s2, 0x30($sp)
    /* AA6C 8006DDCC 2C00B18F */  lw         $s1, 0x2C($sp)
    /* AA70 8006DDD0 2800B08F */  lw         $s0, 0x28($sp)
    /* AA74 8006DDD4 0800E003 */  jr         $ra
    /* AA78 8006DDD8 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel Stg40_SpawnHazard
