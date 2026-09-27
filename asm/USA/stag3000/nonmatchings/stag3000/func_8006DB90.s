nonmatching func_8006DB90, 0x72C

glabel func_8006DB90
    /* A830 8006DB90 88FFBD27 */  addiu      $sp, $sp, -0x78
    /* A834 8006DB94 0780023C */  lui        $v0, %hi(D_80073FCC)
    /* A838 8006DB98 6C00B5AF */  sw         $s5, 0x6C($sp)
    /* A83C 8006DB9C CC3F5524 */  addiu      $s5, $v0, %lo(D_80073FCC)
    /* A840 8006DBA0 6800B4AF */  sw         $s4, 0x68($sp)
    /* A844 8006DBA4 01001424 */  addiu      $s4, $zero, 0x1
    /* A848 8006DBA8 0780023C */  lui        $v0, %hi(D_80073890)
    /* A84C 8006DBAC 5800B0AF */  sw         $s0, 0x58($sp)
    /* A850 8006DBB0 90385024 */  addiu      $s0, $v0, %lo(D_80073890)
    /* A854 8006DBB4 5C00B1AF */  sw         $s1, 0x5C($sp)
    /* A858 8006DBB8 21880000 */  addu       $s1, $zero, $zero
    /* A85C 8006DBBC 6400B3AF */  sw         $s3, 0x64($sp)
    /* A860 8006DBC0 F4FCB326 */  addiu      $s3, $s5, -0x30C
    /* A864 8006DBC4 0680023C */  lui        $v0, %hi(D_8005E620)
    /* A868 8006DBC8 6000B2AF */  sw         $s2, 0x60($sp)
    /* A86C 8006DBCC 20E65224 */  addiu      $s2, $v0, %lo(D_8005E620)
    /* A870 8006DBD0 7400BFAF */  sw         $ra, 0x74($sp)
    /* A874 8006DBD4 7000B6AF */  sw         $s6, 0x70($sp)
    /* A878 8006DBD8 0600B696 */  lhu        $s6, 0x6($s5)
  .L8006DBDC:
    /* A87C 8006DBDC 078A000C */  jal        Item_GetBagCapacity
    /* A880 8006DBE0 00000000 */   nop
    /* A884 8006DBE4 2A102202 */  slt        $v0, $s1, $v0
    /* A888 8006DBE8 0E004010 */  beqz       $v0, .L8006DC24
    /* A88C 8006DBEC 00000000 */   nop
    /* A890 8006DBF0 66004396 */  lhu        $v1, 0x66($s2)
    /* A894 8006DBF4 AC03628E */  lw         $v0, 0x3AC($s3)
    /* A898 8006DBF8 00000000 */  nop
    /* A89C 8006DBFC 04006210 */  beq        $v1, $v0, .L8006DC10
    /* A8A0 8006DC00 40201100 */   sll       $a0, $s1, 1
    /* A8A4 8006DC04 02005226 */  addiu      $s2, $s2, 0x2
    /* A8A8 8006DC08 F7B60108 */  j          .L8006DBDC
    /* A8AC 8006DC0C 01003126 */   addiu     $s1, $s1, 0x1
  .L8006DC10:
    /* A8B0 8006DC10 0680023C */  lui        $v0, %hi(D_8005E620)
    /* A8B4 8006DC14 20E64224 */  addiu      $v0, $v0, %lo(D_8005E620)
    /* A8B8 8006DC18 21108200 */  addu       $v0, $a0, $v0
    /* A8BC 8006DC1C AB89000C */  jal        Item_SortList
    /* A8C0 8006DC20 660040A4 */   sh        $zero, 0x66($v0)
  .L8006DC24:
    /* A8C4 8006DC24 21880000 */  addu       $s1, $zero, $zero
    /* A8C8 8006DC28 FFFF0724 */  addiu      $a3, $zero, -0x1
    /* A8CC 8006DC2C 4800A627 */  addiu      $a2, $sp, 0x48
    /* A8D0 8006DC30 3800A527 */  addiu      $a1, $sp, 0x38
    /* A8D4 8006DC34 1000A427 */  addiu      $a0, $sp, 0x10
    /* A8D8 8006DC38 2000A327 */  addiu      $v1, $sp, 0x20
  .L8006DC3C:
    /* A8DC 8006DC3C 000060AC */  sw         $zero, 0x0($v1)
    /* A8E0 8006DC40 000087A4 */  sh         $a3, 0x0($a0)
    /* A8E4 8006DC44 02008424 */  addiu      $a0, $a0, 0x2
    /* A8E8 8006DC48 04006324 */  addiu      $v1, $v1, 0x4
    /* A8EC 8006DC4C 0800A296 */  lhu        $v0, 0x8($s5)
    /* A8F0 8006DC50 01003126 */  addiu      $s1, $s1, 0x1
    /* A8F4 8006DC54 0000A2A4 */  sh         $v0, 0x0($a1)
    /* A8F8 8006DC58 0000C0A4 */  sh         $zero, 0x0($a2)
    /* A8FC 8006DC5C 0200C624 */  addiu      $a2, $a2, 0x2
    /* A900 8006DC60 0600222A */  slti       $v0, $s1, 0x6
    /* A904 8006DC64 F5FF4014 */  bnez       $v0, .L8006DC3C
    /* A908 8006DC68 0200A524 */   addiu     $a1, $a1, 0x2
    /* A90C 8006DC6C 0400A386 */  lh         $v1, 0x4($s5)
    /* A910 8006DC70 08000224 */  addiu      $v0, $zero, 0x8
    /* A914 8006DC74 3E006210 */  beq        $v1, $v0, .L8006DD70
    /* A918 8006DC78 09006228 */   slti      $v0, $v1, 0x9
    /* A91C 8006DC7C 05004010 */  beqz       $v0, .L8006DC94
    /* A920 8006DC80 07000224 */   addiu     $v0, $zero, 0x7
    /* A924 8006DC84 0A006210 */  beq        $v1, $v0, .L8006DCB0
    /* A928 8006DC88 00000000 */   nop
    /* A92C 8006DC8C 28B70108 */  j          .L8006DCA0
    /* A930 8006DC90 00000000 */   nop
  .L8006DC94:
    /* A934 8006DC94 09000224 */  addiu      $v0, $zero, 0x9
    /* A938 8006DC98 67006210 */  beq        $v1, $v0, .L8006DE38
    /* A93C 8006DC9C 00000000 */   nop
  .L8006DCA0:
    /* A940 8006DCA0 0400A296 */  lhu        $v0, 0x4($s5)
    /* A944 8006DCA4 01001324 */  addiu      $s3, $zero, 0x1
    /* A948 8006DCA8 BDB70108 */  j          .L8006DEF4
    /* A94C 8006DCAC 1000A2A7 */   sh        $v0, 0x10($sp)
  .L8006DCB0:
    /* A950 8006DCB0 3800A387 */  lh         $v1, 0x38($sp)
    /* A954 8006DCB4 00000000 */  nop
    /* A958 8006DCB8 06006004 */  bltz       $v1, .L8006DCD4
    /* A95C 8006DCBC 03006228 */   slti      $v0, $v1, 0x3
    /* A960 8006DCC0 05004014 */  bnez       $v0, .L8006DCD8
    /* A964 8006DCC4 21880000 */   addu      $s1, $zero, $zero
    /* A968 8006DCC8 03000224 */  addiu      $v0, $zero, 0x3
    /* A96C 8006DCCC 13006210 */  beq        $v1, $v0, .L8006DD1C
    /* A970 8006DCD0 21202002 */   addu      $a0, $s1, $zero
  .L8006DCD4:
    /* A974 8006DCD4 21880000 */  addu       $s1, $zero, $zero
  .L8006DCD8:
    /* A978 8006DCD8 21202002 */  addu       $a0, $s1, $zero
    /* A97C 8006DCDC 0780023C */  lui        $v0, %hi(D_80073CC0)
    /* A980 8006DCE0 C03C4524 */  addiu      $a1, $v0, %lo(D_80073CC0)
    /* A984 8006DCE4 1000A327 */  addiu      $v1, $sp, 0x10
  .L8006DCE8:
    /* A988 8006DCE8 2E00A284 */  lh         $v0, 0x2E($a1)
    /* A98C 8006DCEC 00000000 */  nop
    /* A990 8006DCF0 04004010 */  beqz       $v0, .L8006DD04
    /* A994 8006DCF4 00000000 */   nop
    /* A998 8006DCF8 000071A4 */  sh         $s1, 0x0($v1)
    /* A99C 8006DCFC 02006324 */  addiu      $v1, $v1, 0x2
    /* A9A0 8006DD00 01008424 */  addiu      $a0, $a0, 0x1
  .L8006DD04:
    /* A9A4 8006DD04 01003126 */  addiu      $s1, $s1, 0x1
    /* A9A8 8006DD08 0300222A */  slti       $v0, $s1, 0x3
    /* A9AC 8006DD0C F6FF4014 */  bnez       $v0, .L8006DCE8
    /* A9B0 8006DD10 5C00A524 */   addiu     $a1, $a1, 0x5C
    /* A9B4 8006DD14 5AB70108 */  j          .L8006DD68
    /* A9B8 8006DD18 21988000 */   addu      $s3, $a0, $zero
  .L8006DD1C:
    /* A9BC 8006DD1C 0780023C */  lui        $v0, %hi(D_80073CC0)
    /* A9C0 8006DD20 C03C4324 */  addiu      $v1, $v0, %lo(D_80073CC0)
    /* A9C4 8006DD24 1000A527 */  addiu      $a1, $sp, 0x10
  .L8006DD28:
    /* A9C8 8006DD28 19006290 */  lbu        $v0, 0x19($v1)
    /* A9CC 8006DD2C 00000000 */  nop
    /* A9D0 8006DD30 08004010 */  beqz       $v0, .L8006DD54
    /* A9D4 8006DD34 00000000 */   nop
    /* A9D8 8006DD38 2E006284 */  lh         $v0, 0x2E($v1)
    /* A9DC 8006DD3C 00000000 */  nop
    /* A9E0 8006DD40 04004014 */  bnez       $v0, .L8006DD54
    /* A9E4 8006DD44 00000000 */   nop
    /* A9E8 8006DD48 0000B1A4 */  sh         $s1, 0x0($a1)
    /* A9EC 8006DD4C 0200A524 */  addiu      $a1, $a1, 0x2
    /* A9F0 8006DD50 01008424 */  addiu      $a0, $a0, 0x1
  .L8006DD54:
    /* A9F4 8006DD54 01003126 */  addiu      $s1, $s1, 0x1
    /* A9F8 8006DD58 0300222A */  slti       $v0, $s1, 0x3
    /* A9FC 8006DD5C F2FF4014 */  bnez       $v0, .L8006DD28
    /* AA00 8006DD60 5C006324 */   addiu     $v1, $v1, 0x5C
    /* AA04 8006DD64 21988000 */  addu       $s3, $a0, $zero
  .L8006DD68:
    /* AA08 8006DD68 BDB70108 */  j          .L8006DEF4
    /* AA0C 8006DD6C 21A00000 */   addu      $s4, $zero, $zero
  .L8006DD70:
    /* AA10 8006DD70 3800A387 */  lh         $v1, 0x38($sp)
    /* AA14 8006DD74 00000000 */  nop
    /* AA18 8006DD78 06006004 */  bltz       $v1, .L8006DD94
    /* AA1C 8006DD7C 03006228 */   slti      $v0, $v1, 0x3
    /* AA20 8006DD80 05004014 */  bnez       $v0, .L8006DD98
    /* AA24 8006DD84 21200000 */   addu      $a0, $zero, $zero
    /* AA28 8006DD88 03000224 */  addiu      $v0, $zero, 0x3
    /* AA2C 8006DD8C 14006210 */  beq        $v1, $v0, .L8006DDE0
    /* AA30 8006DD90 03001124 */   addiu     $s1, $zero, 0x3
  .L8006DD94:
    /* AA34 8006DD94 21200000 */  addu       $a0, $zero, $zero
  .L8006DD98:
    /* AA38 8006DD98 03001124 */  addiu      $s1, $zero, 0x3
    /* AA3C 8006DD9C 0780023C */  lui        $v0, %hi(D_80073CC0)
    /* AA40 8006DDA0 C03C4224 */  addiu      $v0, $v0, %lo(D_80073CC0)
    /* AA44 8006DDA4 14014524 */  addiu      $a1, $v0, 0x114
    /* AA48 8006DDA8 1000A327 */  addiu      $v1, $sp, 0x10
  .L8006DDAC:
    /* AA4C 8006DDAC 2E00A284 */  lh         $v0, 0x2E($a1)
    /* AA50 8006DDB0 00000000 */  nop
    /* AA54 8006DDB4 04004010 */  beqz       $v0, .L8006DDC8
    /* AA58 8006DDB8 00000000 */   nop
    /* AA5C 8006DDBC 000071A4 */  sh         $s1, 0x0($v1)
    /* AA60 8006DDC0 02006324 */  addiu      $v1, $v1, 0x2
    /* AA64 8006DDC4 01008424 */  addiu      $a0, $a0, 0x1
  .L8006DDC8:
    /* AA68 8006DDC8 01003126 */  addiu      $s1, $s1, 0x1
    /* AA6C 8006DDCC 0600222A */  slti       $v0, $s1, 0x6
    /* AA70 8006DDD0 F6FF4014 */  bnez       $v0, .L8006DDAC
    /* AA74 8006DDD4 5C00A524 */   addiu     $a1, $a1, 0x5C
    /* AA78 8006DDD8 8CB70108 */  j          .L8006DE30
    /* AA7C 8006DDDC 21988000 */   addu      $s3, $a0, $zero
  .L8006DDE0:
    /* AA80 8006DDE0 0780023C */  lui        $v0, %hi(D_80073CC0)
    /* AA84 8006DDE4 C03C4224 */  addiu      $v0, $v0, %lo(D_80073CC0)
    /* AA88 8006DDE8 14014324 */  addiu      $v1, $v0, 0x114
    /* AA8C 8006DDEC 1000A527 */  addiu      $a1, $sp, 0x10
  .L8006DDF0:
    /* AA90 8006DDF0 19006290 */  lbu        $v0, 0x19($v1)
    /* AA94 8006DDF4 00000000 */  nop
    /* AA98 8006DDF8 08004010 */  beqz       $v0, .L8006DE1C
    /* AA9C 8006DDFC 00000000 */   nop
    /* AAA0 8006DE00 2E006284 */  lh         $v0, 0x2E($v1)
    /* AAA4 8006DE04 00000000 */  nop
    /* AAA8 8006DE08 04004014 */  bnez       $v0, .L8006DE1C
    /* AAAC 8006DE0C 00000000 */   nop
    /* AAB0 8006DE10 0000B1A4 */  sh         $s1, 0x0($a1)
    /* AAB4 8006DE14 0200A524 */  addiu      $a1, $a1, 0x2
    /* AAB8 8006DE18 01008424 */  addiu      $a0, $a0, 0x1
  .L8006DE1C:
    /* AABC 8006DE1C 01003126 */  addiu      $s1, $s1, 0x1
    /* AAC0 8006DE20 0600222A */  slti       $v0, $s1, 0x6
    /* AAC4 8006DE24 F2FF4014 */  bnez       $v0, .L8006DDF0
    /* AAC8 8006DE28 5C006324 */   addiu     $v1, $v1, 0x5C
    /* AACC 8006DE2C 21988000 */  addu       $s3, $a0, $zero
  .L8006DE30:
    /* AAD0 8006DE30 BDB70108 */  j          .L8006DEF4
    /* AAD4 8006DE34 01001424 */   addiu     $s4, $zero, 0x1
  .L8006DE38:
    /* AAD8 8006DE38 3800A387 */  lh         $v1, 0x38($sp)
    /* AADC 8006DE3C 00000000 */  nop
    /* AAE0 8006DE40 06006004 */  bltz       $v1, .L8006DE5C
    /* AAE4 8006DE44 03006228 */   slti      $v0, $v1, 0x3
    /* AAE8 8006DE48 05004014 */  bnez       $v0, .L8006DE60
    /* AAEC 8006DE4C 21200000 */   addu      $a0, $zero, $zero
    /* AAF0 8006DE50 03000224 */  addiu      $v0, $zero, 0x3
    /* AAF4 8006DE54 13006210 */  beq        $v1, $v0, .L8006DEA4
    /* AAF8 8006DE58 21888000 */   addu      $s1, $a0, $zero
  .L8006DE5C:
    /* AAFC 8006DE5C 21200000 */  addu       $a0, $zero, $zero
  .L8006DE60:
    /* AB00 8006DE60 21888000 */  addu       $s1, $a0, $zero
    /* AB04 8006DE64 0780023C */  lui        $v0, %hi(D_80073CC0)
    /* AB08 8006DE68 C03C4524 */  addiu      $a1, $v0, %lo(D_80073CC0)
    /* AB0C 8006DE6C 1000A327 */  addiu      $v1, $sp, 0x10
  .L8006DE70:
    /* AB10 8006DE70 2E00A284 */  lh         $v0, 0x2E($a1)
    /* AB14 8006DE74 00000000 */  nop
    /* AB18 8006DE78 04004010 */  beqz       $v0, .L8006DE8C
    /* AB1C 8006DE7C 00000000 */   nop
    /* AB20 8006DE80 000071A4 */  sh         $s1, 0x0($v1)
    /* AB24 8006DE84 02006324 */  addiu      $v1, $v1, 0x2
    /* AB28 8006DE88 01008424 */  addiu      $a0, $a0, 0x1
  .L8006DE8C:
    /* AB2C 8006DE8C 01003126 */  addiu      $s1, $s1, 0x1
    /* AB30 8006DE90 0600222A */  slti       $v0, $s1, 0x6
    /* AB34 8006DE94 F6FF4014 */  bnez       $v0, .L8006DE70
    /* AB38 8006DE98 5C00A524 */   addiu     $a1, $a1, 0x5C
    /* AB3C 8006DE9C BCB70108 */  j          .L8006DEF0
    /* AB40 8006DEA0 21988000 */   addu      $s3, $a0, $zero
  .L8006DEA4:
    /* AB44 8006DEA4 0780023C */  lui        $v0, %hi(D_80073CC0)
    /* AB48 8006DEA8 C03C4324 */  addiu      $v1, $v0, %lo(D_80073CC0)
    /* AB4C 8006DEAC 1000A527 */  addiu      $a1, $sp, 0x10
  .L8006DEB0:
    /* AB50 8006DEB0 19006290 */  lbu        $v0, 0x19($v1)
    /* AB54 8006DEB4 00000000 */  nop
    /* AB58 8006DEB8 08004010 */  beqz       $v0, .L8006DEDC
    /* AB5C 8006DEBC 00000000 */   nop
    /* AB60 8006DEC0 2E006284 */  lh         $v0, 0x2E($v1)
    /* AB64 8006DEC4 00000000 */  nop
    /* AB68 8006DEC8 04004014 */  bnez       $v0, .L8006DEDC
    /* AB6C 8006DECC 00000000 */   nop
    /* AB70 8006DED0 0000B1A4 */  sh         $s1, 0x0($a1)
    /* AB74 8006DED4 0200A524 */  addiu      $a1, $a1, 0x2
    /* AB78 8006DED8 01008424 */  addiu      $a0, $a0, 0x1
  .L8006DEDC:
    /* AB7C 8006DEDC 01003126 */  addiu      $s1, $s1, 0x1
    /* AB80 8006DEE0 0600222A */  slti       $v0, $s1, 0x6
    /* AB84 8006DEE4 F2FF4014 */  bnez       $v0, .L8006DEB0
    /* AB88 8006DEE8 5C006324 */   addiu     $v1, $v1, 0x5C
    /* AB8C 8006DEEC 21988000 */  addu       $s3, $a0, $zero
  .L8006DEF0:
    /* AB90 8006DEF0 02001424 */  addiu      $s4, $zero, 0x2
  .L8006DEF4:
    /* AB94 8006DEF4 1500601A */  blez       $s3, .L8006DF4C
    /* AB98 8006DEF8 21880000 */   addu      $s1, $zero, $zero
    /* AB9C 8006DEFC 3800B227 */  addiu      $s2, $sp, 0x38
    /* ABA0 8006DF00 21304002 */  addu       $a2, $s2, $zero
  .L8006DF04:
    /* ABA4 8006DF04 40381100 */  sll        $a3, $s1, 1
    /* ABA8 8006DF08 2118A703 */  addu       $v1, $sp, $a3
    /* ABAC 8006DF0C 002C1600 */  sll        $a1, $s6, 16
    /* ABB0 8006DF10 0800A296 */  lhu        $v0, 0x8($s5)
    /* ABB4 8006DF14 032C0500 */  sra        $a1, $a1, 16
    /* ABB8 8006DF18 000042A6 */  sh         $v0, 0x0($s2)
    /* ABBC 8006DF1C 02005226 */  addiu      $s2, $s2, 0x2
    /* ABC0 8006DF20 4800A227 */  addiu      $v0, $sp, 0x48
    /* ABC4 8006DF24 10006484 */  lh         $a0, 0x10($v1)
    /* ABC8 8006DF28 36B5010C */  jal        func_8006D4D8
    /* ABCC 8006DF2C 21384700 */   addu      $a3, $v0, $a3
    /* ABD0 8006DF30 80181100 */  sll        $v1, $s1, 2
    /* ABD4 8006DF34 01003126 */  addiu      $s1, $s1, 0x1
    /* ABD8 8006DF38 2118A303 */  addu       $v1, $sp, $v1
    /* ABDC 8006DF3C 200062AC */  sw         $v0, 0x20($v1)
    /* ABE0 8006DF40 2A103302 */  slt        $v0, $s1, $s3
    /* ABE4 8006DF44 EFFF4014 */  bnez       $v0, .L8006DF04
    /* ABE8 8006DF48 21304002 */   addu      $a2, $s2, $zero
  .L8006DF4C:
    /* ABEC 8006DF4C 02000224 */  addiu      $v0, $zero, 0x2
    /* ABF0 8006DF50 000002A6 */  sh         $v0, 0x0($s0)
    /* ABF4 8006DF54 02001026 */  addiu      $s0, $s0, 0x2
    /* ABF8 8006DF58 1000A297 */  lhu        $v0, 0x10($sp)
    /* ABFC 8006DF5C 21880000 */  addu       $s1, $zero, $zero
    /* AC00 8006DF60 0A004224 */  addiu      $v0, $v0, 0xA
    /* AC04 8006DF64 000002A6 */  sh         $v0, 0x0($s0)
    /* AC08 8006DF68 02001026 */  addiu      $s0, $s0, 0x2
    /* AC0C 8006DF6C 03000224 */  addiu      $v0, $zero, 0x3
    /* AC10 8006DF70 000002A6 */  sh         $v0, 0x0($s0)
    /* AC14 8006DF74 1000A297 */  lhu        $v0, 0x10($sp)
    /* AC18 8006DF78 02001026 */  addiu      $s0, $s0, 0x2
    /* AC1C 8006DF7C 000002A6 */  sh         $v0, 0x0($s0)
    /* AC20 8006DF80 02001026 */  addiu      $s0, $s0, 0x2
    /* AC24 8006DF84 09000224 */  addiu      $v0, $zero, 0x9
    /* AC28 8006DF88 000002A6 */  sh         $v0, 0x0($s0)
    /* AC2C 8006DF8C 02001026 */  addiu      $s0, $s0, 0x2
    /* AC30 8006DF90 06000224 */  addiu      $v0, $zero, 0x6
    /* AC34 8006DF94 000002A6 */  sh         $v0, 0x0($s0)
    /* AC38 8006DF98 02001026 */  addiu      $s0, $s0, 0x2
    /* AC3C 8006DF9C 000016A6 */  sh         $s6, 0x0($s0)
    /* AC40 8006DFA0 02001026 */  addiu      $s0, $s0, 0x2
    /* AC44 8006DFA4 15000224 */  addiu      $v0, $zero, 0x15
    /* AC48 8006DFA8 000002A6 */  sh         $v0, 0x0($s0)
    /* AC4C 8006DFAC 02001026 */  addiu      $s0, $s0, 0x2
    /* AC50 8006DFB0 16000224 */  addiu      $v0, $zero, 0x16
    /* AC54 8006DFB4 000002A6 */  sh         $v0, 0x0($s0)
    /* AC58 8006DFB8 02001026 */  addiu      $s0, $s0, 0x2
    /* AC5C 8006DFBC 11000224 */  addiu      $v0, $zero, 0x11
    /* AC60 8006DFC0 000002A6 */  sh         $v0, 0x0($s0)
    /* AC64 8006DFC4 0780023C */  lui        $v0, %hi(D_80073CC0)
    /* AC68 8006DFC8 C03C4324 */  addiu      $v1, $v0, %lo(D_80073CC0)
    /* AC6C 8006DFCC B2036294 */  lhu        $v0, 0x3B2($v1)
    /* AC70 8006DFD0 02001026 */  addiu      $s0, $s0, 0x2
    /* AC74 8006DFD4 000002A6 */  sh         $v0, 0x0($s0)
    /* AC78 8006DFD8 02001026 */  addiu      $s0, $s0, 0x2
    /* AC7C 8006DFDC 12000224 */  addiu      $v0, $zero, 0x12
    /* AC80 8006DFE0 000002A6 */  sh         $v0, 0x0($s0)
    /* AC84 8006DFE4 02001026 */  addiu      $s0, $s0, 0x2
    /* AC88 8006DFE8 17000224 */  addiu      $v0, $zero, 0x17
    /* AC8C 8006DFEC 000002A6 */  sh         $v0, 0x0($s0)
    /* AC90 8006DFF0 02001026 */  addiu      $s0, $s0, 0x2
    /* AC94 8006DFF4 000016A6 */  sh         $s6, 0x0($s0)
    /* AC98 8006DFF8 02001026 */  addiu      $s0, $s0, 0x2
    /* AC9C 8006DFFC 000013A6 */  sh         $s3, 0x0($s0)
    /* ACA0 8006E000 02001026 */  addiu      $s0, $s0, 0x2
    /* ACA4 8006E004 000000A6 */  sh         $zero, 0x0($s0)
    /* ACA8 8006E008 02001026 */  addiu      $s0, $s0, 0x2
    /* ACAC 8006E00C 96000224 */  addiu      $v0, $zero, 0x96
    /* ACB0 8006E010 000002A6 */  sh         $v0, 0x0($s0)
    /* ACB4 8006E014 8200601A */  blez       $s3, .L8006E220
    /* ACB8 8006E018 02001026 */   addiu     $s0, $s0, 0x2
    /* ACBC 8006E01C 0680023C */  lui        $v0, %hi(jtbl_80063770)
    /* ACC0 8006E020 70374A24 */  addiu      $t2, $v0, %lo(jtbl_80063770)
    /* ACC4 8006E024 21486000 */  addu       $t1, $v1, $zero
    /* ACC8 8006E028 1000A627 */  addiu      $a2, $sp, 0x10
    /* ACCC 8006E02C 3800A727 */  addiu      $a3, $sp, 0x38
    /* ACD0 8006E030 21402002 */  addu       $t0, $s1, $zero
  .L8006E034:
    /* ACD4 8006E034 02000224 */  addiu      $v0, $zero, 0x2
    /* ACD8 8006E038 000002A6 */  sh         $v0, 0x0($s0)
    /* ACDC 8006E03C 02001026 */  addiu      $s0, $s0, 0x2
    /* ACE0 8006E040 0000C294 */  lhu        $v0, 0x0($a2)
    /* ACE4 8006E044 0C000324 */  addiu      $v1, $zero, 0xC
    /* ACE8 8006E048 10004224 */  addiu      $v0, $v0, 0x10
    /* ACEC 8006E04C 000002A6 */  sh         $v0, 0x0($s0)
    /* ACF0 8006E050 02001026 */  addiu      $s0, $s0, 0x2
    /* ACF4 8006E054 03000224 */  addiu      $v0, $zero, 0x3
    /* ACF8 8006E058 000002A6 */  sh         $v0, 0x0($s0)
    /* ACFC 8006E05C 0000C294 */  lhu        $v0, 0x0($a2)
    /* AD00 8006E060 02001026 */  addiu      $s0, $s0, 0x2
    /* AD04 8006E064 000002A6 */  sh         $v0, 0x0($s0)
    /* AD08 8006E068 02001026 */  addiu      $s0, $s0, 0x2
    /* AD0C 8006E06C 000000A6 */  sh         $zero, 0x0($s0)
    /* AD10 8006E070 02001026 */  addiu      $s0, $s0, 0x2
    /* AD14 8006E074 21100002 */  addu       $v0, $s0, $zero
    /* AD18 8006E078 02002016 */  bnez       $s1, .L8006E084
    /* AD1C 8006E07C 02001026 */   addiu     $s0, $s0, 0x2
    /* AD20 8006E080 1E000324 */  addiu      $v1, $zero, 0x1E
  .L8006E084:
    /* AD24 8006E084 000043A4 */  sh         $v1, 0x0($v0)
    /* AD28 8006E088 10000224 */  addiu      $v0, $zero, 0x10
    /* AD2C 8006E08C 000002A6 */  sh         $v0, 0x0($s0)
    /* AD30 8006E090 80101100 */  sll        $v0, $s1, 2
    /* AD34 8006E094 2110A203 */  addu       $v0, $sp, $v0
    /* AD38 8006E098 20004294 */  lhu        $v0, 0x20($v0)
    /* AD3C 8006E09C 02001026 */  addiu      $s0, $s0, 0x2
    /* AD40 8006E0A0 000002A6 */  sh         $v0, 0x0($s0)
    /* AD44 8006E0A4 02001026 */  addiu      $s0, $s0, 0x2
    /* AD48 8006E0A8 21180002 */  addu       $v1, $s0, $zero
    /* AD4C 8006E0AC 0000E284 */  lh         $v0, 0x0($a3)
    /* AD50 8006E0B0 00000000 */  nop
    /* AD54 8006E0B4 03004228 */  slti       $v0, $v0, 0x3
    /* AD58 8006E0B8 04004010 */  beqz       $v0, .L8006E0CC
    /* AD5C 8006E0BC 02001026 */   addiu     $s0, $s0, 0x2
    /* AD60 8006E0C0 0800A296 */  lhu        $v0, 0x8($s5)
    /* AD64 8006E0C4 34B80108 */  j          .L8006E0D0
    /* AD68 8006E0C8 01004224 */   addiu     $v0, $v0, 0x1
  .L8006E0CC:
    /* AD6C 8006E0CC 08000224 */  addiu      $v0, $zero, 0x8
  .L8006E0D0:
    /* AD70 8006E0D0 000062A4 */  sh         $v0, 0x0($v1)
    /* AD74 8006E0D4 2110A803 */  addu       $v0, $sp, $t0
    /* AD78 8006E0D8 48004294 */  lhu        $v0, 0x48($v0)
    /* AD7C 8006E0DC 00000000 */  nop
    /* AD80 8006E0E0 000002A6 */  sh         $v0, 0x0($s0)
    /* AD84 8006E0E4 0000E384 */  lh         $v1, 0x0($a3)
    /* AD88 8006E0E8 00000000 */  nop
    /* AD8C 8006E0EC 0500622C */  sltiu      $v0, $v1, 0x5
    /* AD90 8006E0F0 24004010 */  beqz       $v0, .L8006E184
    /* AD94 8006E0F4 02001026 */   addiu     $s0, $s0, 0x2
    /* AD98 8006E0F8 80100300 */  sll        $v0, $v1, 2
    /* AD9C 8006E0FC 21104A00 */  addu       $v0, $v0, $t2
    /* ADA0 8006E100 0000428C */  lw         $v0, 0x0($v0)
    /* ADA4 8006E104 00000000 */  nop
    /* ADA8 8006E108 08004000 */  jr         $v0
    /* ADAC 8006E10C 00000000 */   nop
  jlabel .L8006E110
    /* ADB0 8006E110 0000C384 */  lh         $v1, 0x0($a2)
    /* ADB4 8006E114 00000000 */  nop
    /* ADB8 8006E118 40100300 */  sll        $v0, $v1, 1
    /* ADBC 8006E11C 21104300 */  addu       $v0, $v0, $v1
    /* ADC0 8006E120 C0100200 */  sll        $v0, $v0, 3
    /* ADC4 8006E124 23104300 */  subu       $v0, $v0, $v1
    /* ADC8 8006E128 80100200 */  sll        $v0, $v0, 2
    /* ADCC 8006E12C 21104900 */  addu       $v0, $v0, $t1
    /* ADD0 8006E130 2E004284 */  lh         $v0, 0x2E($v0)
    /* ADD4 8006E134 00000000 */  nop
    /* ADD8 8006E138 0B004010 */  beqz       $v0, .L8006E168
    /* ADDC 8006E13C 21280002 */   addu      $a1, $s0, $zero
    /* ADE0 8006E140 02001026 */  addiu      $s0, $s0, 0x2
    /* ADE4 8006E144 00110300 */  sll        $v0, $v1, 4
    /* ADE8 8006E148 21104900 */  addu       $v0, $v0, $t1
    /* ADEC 8006E14C AC02438C */  lw         $v1, 0x2AC($v0)
    /* ADF0 8006E150 05000224 */  addiu      $v0, $zero, 0x5
    /* ADF4 8006E154 02006210 */  beq        $v1, $v0, .L8006E160
    /* ADF8 8006E158 0A000424 */   addiu     $a0, $zero, 0xA
    /* ADFC 8006E15C 0B000424 */  addiu      $a0, $zero, 0xB
  .L8006E160:
    /* AE00 8006E160 61B80108 */  j          .L8006E184
    /* AE04 8006E164 0000A4A4 */   sh        $a0, 0x0($a1)
  .L8006E168:
    /* AE08 8006E168 5FB80108 */  j          .L8006E17C
    /* AE0C 8006E16C 0C000224 */   addiu     $v0, $zero, 0xC
  jlabel .L8006E170
    /* AE10 8006E170 5FB80108 */  j          .L8006E17C
    /* AE14 8006E174 08000224 */   addiu     $v0, $zero, 0x8
  jlabel .L8006E178
    /* AE18 8006E178 0D000224 */  addiu      $v0, $zero, 0xD
  .L8006E17C:
    /* AE1C 8006E17C 000002A6 */  sh         $v0, 0x0($s0)
    /* AE20 8006E180 02001026 */  addiu      $s0, $s0, 0x2
  .L8006E184:
    /* AE24 8006E184 0000C294 */  lhu        $v0, 0x0($a2)
    /* AE28 8006E188 00000000 */  nop
    /* AE2C 8006E18C 000002A6 */  sh         $v0, 0x0($s0)
    /* AE30 8006E190 02001026 */  addiu      $s0, $s0, 0x2
    /* AE34 8006E194 000016A6 */  sh         $s6, 0x0($s0)
    /* AE38 8006E198 01000224 */  addiu      $v0, $zero, 0x1
    /* AE3C 8006E19C 15006216 */  bne        $s3, $v0, .L8006E1F4
    /* AE40 8006E1A0 02001026 */   addiu     $s0, $s0, 0x2
    /* AE44 8006E1A4 0000E284 */  lh         $v0, 0x0($a3)
    /* AE48 8006E1A8 00000000 */  nop
    /* AE4C 8006E1AC 0A004014 */  bnez       $v0, .L8006E1D8
    /* AE50 8006E1B0 00000000 */   nop
    /* AE54 8006E1B4 000013A6 */  sh         $s3, 0x0($s0)
    /* AE58 8006E1B8 0000C294 */  lhu        $v0, 0x0($a2)
    /* AE5C 8006E1BC 02001026 */  addiu      $s0, $s0, 0x2
    /* AE60 8006E1C0 000002A6 */  sh         $v0, 0x0($s0)
    /* AE64 8006E1C4 02001026 */  addiu      $s0, $s0, 0x2
    /* AE68 8006E1C8 000000A6 */  sh         $zero, 0x0($s0)
    /* AE6C 8006E1CC 02001026 */  addiu      $s0, $s0, 0x2
    /* AE70 8006E1D0 80B80108 */  j          .L8006E200
    /* AE74 8006E1D4 1E000224 */   addiu     $v0, $zero, 0x1E
  .L8006E1D8:
    /* AE78 8006E1D8 0B004004 */  bltz       $v0, .L8006E208
    /* AE7C 8006E1DC 05004228 */   slti      $v0, $v0, 0x5
    /* AE80 8006E1E0 09004010 */  beqz       $v0, .L8006E208
    /* AE84 8006E1E4 78000224 */   addiu     $v0, $zero, 0x78
    /* AE88 8006E1E8 000000A6 */  sh         $zero, 0x0($s0)
    /* AE8C 8006E1EC 80B80108 */  j          .L8006E200
    /* AE90 8006E1F0 02001026 */   addiu     $s0, $s0, 0x2
  .L8006E1F4:
    /* AE94 8006E1F4 000000A6 */  sh         $zero, 0x0($s0)
    /* AE98 8006E1F8 02001026 */  addiu      $s0, $s0, 0x2
    /* AE9C 8006E1FC 3C000224 */  addiu      $v0, $zero, 0x3C
  .L8006E200:
    /* AEA0 8006E200 000002A6 */  sh         $v0, 0x0($s0)
    /* AEA4 8006E204 02001026 */  addiu      $s0, $s0, 0x2
  .L8006E208:
    /* AEA8 8006E208 0200C624 */  addiu      $a2, $a2, 0x2
    /* AEAC 8006E20C 0200E724 */  addiu      $a3, $a3, 0x2
    /* AEB0 8006E210 01003126 */  addiu      $s1, $s1, 0x1
    /* AEB4 8006E214 2A103302 */  slt        $v0, $s1, $s3
    /* AEB8 8006E218 86FF4014 */  bnez       $v0, .L8006E034
    /* AEBC 8006E21C 02000825 */   addiu     $t0, $t0, 0x2
  .L8006E220:
    /* AEC0 8006E220 01000224 */  addiu      $v0, $zero, 0x1
    /* AEC4 8006E224 0E006212 */  beq        $s3, $v0, .L8006E260
    /* AEC8 8006E228 02000224 */   addiu     $v0, $zero, 0x2
    /* AECC 8006E22C 000002A6 */  sh         $v0, 0x0($s0)
    /* AED0 8006E230 02001026 */  addiu      $s0, $s0, 0x2
    /* AED4 8006E234 16008226 */  addiu      $v0, $s4, 0x16
    /* AED8 8006E238 000002A6 */  sh         $v0, 0x0($s0)
    /* AEDC 8006E23C 02001026 */  addiu      $s0, $s0, 0x2
    /* AEE0 8006E240 04008226 */  addiu      $v0, $s4, 0x4
    /* AEE4 8006E244 000002A6 */  sh         $v0, 0x0($s0)
    /* AEE8 8006E248 02001026 */  addiu      $s0, $s0, 0x2
    /* AEEC 8006E24C 000000A6 */  sh         $zero, 0x0($s0)
    /* AEF0 8006E250 02001026 */  addiu      $s0, $s0, 0x2
    /* AEF4 8006E254 B4000224 */  addiu      $v0, $zero, 0xB4
    /* AEF8 8006E258 000002A6 */  sh         $v0, 0x0($s0)
    /* AEFC 8006E25C 02001026 */  addiu      $s0, $s0, 0x2
  .L8006E260:
    /* AF00 8006E260 18000224 */  addiu      $v0, $zero, 0x18
    /* AF04 8006E264 000002A6 */  sh         $v0, 0x0($s0)
    /* AF08 8006E268 21880000 */  addu       $s1, $zero, $zero
    /* AF0C 8006E26C 1000A427 */  addiu      $a0, $sp, 0x10
    /* AF10 8006E270 0780023C */  lui        $v0, %hi(D_80073CC0)
    /* AF14 8006E274 C03C4324 */  addiu      $v1, $v0, %lo(D_80073CC0)
  .L8006E278:
    /* AF18 8006E278 00008284 */  lh         $v0, 0x0($a0)
    /* AF1C 8006E27C 02008424 */  addiu      $a0, $a0, 0x2
    /* AF20 8006E280 01003126 */  addiu      $s1, $s1, 0x1
    /* AF24 8006E284 B80362AC */  sw         $v0, 0x3B8($v1)
    /* AF28 8006E288 0600222A */  slti       $v0, $s1, 0x6
    /* AF2C 8006E28C FAFF4014 */  bnez       $v0, .L8006E278
    /* AF30 8006E290 04006324 */   addiu     $v1, $v1, 0x4
    /* AF34 8006E294 7400BF8F */  lw         $ra, 0x74($sp)
    /* AF38 8006E298 7000B68F */  lw         $s6, 0x70($sp)
    /* AF3C 8006E29C 6C00B58F */  lw         $s5, 0x6C($sp)
    /* AF40 8006E2A0 6800B48F */  lw         $s4, 0x68($sp)
    /* AF44 8006E2A4 6400B38F */  lw         $s3, 0x64($sp)
    /* AF48 8006E2A8 6000B28F */  lw         $s2, 0x60($sp)
    /* AF4C 8006E2AC 5C00B18F */  lw         $s1, 0x5C($sp)
    /* AF50 8006E2B0 5800B08F */  lw         $s0, 0x58($sp)
    /* AF54 8006E2B4 0800E003 */  jr         $ra
    /* AF58 8006E2B8 7800BD27 */   addiu     $sp, $sp, 0x78
endlabel func_8006DB90
