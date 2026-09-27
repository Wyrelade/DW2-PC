nonmatching func_8006ED88, 0x2E4

glabel func_8006ED88
    /* BA28 8006ED88 0580023C */  lui        $v0, %hi(D_8005071C)
    /* BA2C 8006ED8C 1C07438C */  lw         $v1, %lo(D_8005071C)($v0)
    /* BA30 8006ED90 00000000 */  nop
    /* BA34 8006ED94 540E628C */  lw         $v0, 0xE54($v1)
    /* BA38 8006ED98 21408000 */  addu       $t0, $a0, $zero
    /* BA3C 8006ED9C 00004484 */  lh         $a0, 0x0($v0)
    /* BA40 8006EDA0 02004284 */  lh         $v0, 0x2($v0)
    /* BA44 8006EDA4 00000000 */  nop
    /* BA48 8006EDA8 18008200 */  mult       $a0, $v0
    /* BA4C 8006EDAC 7C0E6624 */  addiu      $a2, $v1, 0xE7C
    /* BA50 8006EDB0 580E638C */  lw         $v1, 0xE58($v1)
    /* BA54 8006EDB4 12200000 */  mflo       $a0
    /* BA58 8006EDB8 02008104 */  bgez       $a0, .L8006EDC4
    /* BA5C 8006EDBC 00000000 */   nop
    /* BA60 8006EDC0 07008424 */  addiu      $a0, $a0, 0x7
  .L8006EDC4:
    /* BA64 8006EDC4 C3200400 */  sra        $a0, $a0, 3
    /* BA68 8006EDC8 A6008018 */  blez       $a0, .L8006F064
    /* BA6C 8006EDCC 21380000 */   addu      $a3, $zero, $zero
  .L8006EDD0:
    /* BA70 8006EDD0 3F000015 */  bnez       $t0, .L8006EED0
    /* BA74 8006EDD4 00000000 */   nop
    /* BA78 8006EDD8 0000C0A0 */  sb         $zero, 0x0($a2)
    /* BA7C 8006EDDC 00006294 */  lhu        $v0, 0x0($v1)
    /* BA80 8006EDE0 04006324 */  addiu      $v1, $v1, 0x4
    /* BA84 8006EDE4 42130200 */  srl        $v0, $v0, 13
    /* BA88 8006EDE8 01004230 */  andi       $v0, $v0, 0x1
    /* BA8C 8006EDEC 0000C2A0 */  sb         $v0, 0x0($a2)
    /* BA90 8006EDF0 00006294 */  lhu        $v0, 0x0($v1)
    /* BA94 8006EDF4 0000C590 */  lbu        $a1, 0x0($a2)
    /* BA98 8006EDF8 00204230 */  andi       $v0, $v0, 0x2000
    /* BA9C 8006EDFC 02004010 */  beqz       $v0, .L8006EE08
    /* BAA0 8006EE00 00000000 */   nop
    /* BAA4 8006EE04 0200A534 */  ori        $a1, $a1, 0x2
  .L8006EE08:
    /* BAA8 8006EE08 04006324 */  addiu      $v1, $v1, 0x4
    /* BAAC 8006EE0C 0000C5A0 */  sb         $a1, 0x0($a2)
    /* BAB0 8006EE10 00006294 */  lhu        $v0, 0x0($v1)
    /* BAB4 8006EE14 00000000 */  nop
    /* BAB8 8006EE18 00204230 */  andi       $v0, $v0, 0x2000
    /* BABC 8006EE1C 02004010 */  beqz       $v0, .L8006EE28
    /* BAC0 8006EE20 FF00A530 */   andi      $a1, $a1, 0xFF
    /* BAC4 8006EE24 0400A534 */  ori        $a1, $a1, 0x4
  .L8006EE28:
    /* BAC8 8006EE28 04006324 */  addiu      $v1, $v1, 0x4
    /* BACC 8006EE2C 0000C5A0 */  sb         $a1, 0x0($a2)
    /* BAD0 8006EE30 00006294 */  lhu        $v0, 0x0($v1)
    /* BAD4 8006EE34 00000000 */  nop
    /* BAD8 8006EE38 00204230 */  andi       $v0, $v0, 0x2000
    /* BADC 8006EE3C 02004010 */  beqz       $v0, .L8006EE48
    /* BAE0 8006EE40 FF00A530 */   andi      $a1, $a1, 0xFF
    /* BAE4 8006EE44 0800A534 */  ori        $a1, $a1, 0x8
  .L8006EE48:
    /* BAE8 8006EE48 04006324 */  addiu      $v1, $v1, 0x4
    /* BAEC 8006EE4C 0000C5A0 */  sb         $a1, 0x0($a2)
    /* BAF0 8006EE50 00006294 */  lhu        $v0, 0x0($v1)
    /* BAF4 8006EE54 00000000 */  nop
    /* BAF8 8006EE58 00204230 */  andi       $v0, $v0, 0x2000
    /* BAFC 8006EE5C 02004010 */  beqz       $v0, .L8006EE68
    /* BB00 8006EE60 FF00A530 */   andi      $a1, $a1, 0xFF
    /* BB04 8006EE64 1000A534 */  ori        $a1, $a1, 0x10
  .L8006EE68:
    /* BB08 8006EE68 04006324 */  addiu      $v1, $v1, 0x4
    /* BB0C 8006EE6C 0000C5A0 */  sb         $a1, 0x0($a2)
    /* BB10 8006EE70 00006294 */  lhu        $v0, 0x0($v1)
    /* BB14 8006EE74 00000000 */  nop
    /* BB18 8006EE78 00204230 */  andi       $v0, $v0, 0x2000
    /* BB1C 8006EE7C 02004010 */  beqz       $v0, .L8006EE88
    /* BB20 8006EE80 FF00A530 */   andi      $a1, $a1, 0xFF
    /* BB24 8006EE84 2000A534 */  ori        $a1, $a1, 0x20
  .L8006EE88:
    /* BB28 8006EE88 04006324 */  addiu      $v1, $v1, 0x4
    /* BB2C 8006EE8C 0000C5A0 */  sb         $a1, 0x0($a2)
    /* BB30 8006EE90 00006294 */  lhu        $v0, 0x0($v1)
    /* BB34 8006EE94 00000000 */  nop
    /* BB38 8006EE98 00204230 */  andi       $v0, $v0, 0x2000
    /* BB3C 8006EE9C 02004010 */  beqz       $v0, .L8006EEA8
    /* BB40 8006EEA0 FF00A530 */   andi      $a1, $a1, 0xFF
    /* BB44 8006EEA4 4000A534 */  ori        $a1, $a1, 0x40
  .L8006EEA8:
    /* BB48 8006EEA8 04006324 */  addiu      $v1, $v1, 0x4
    /* BB4C 8006EEAC 0000C5A0 */  sb         $a1, 0x0($a2)
    /* BB50 8006EEB0 00006294 */  lhu        $v0, 0x0($v1)
    /* BB54 8006EEB4 00000000 */  nop
    /* BB58 8006EEB8 00204230 */  andi       $v0, $v0, 0x2000
    /* BB5C 8006EEBC 02004010 */  beqz       $v0, .L8006EEC8
    /* BB60 8006EEC0 FF00A530 */   andi      $a1, $a1, 0xFF
    /* BB64 8006EEC4 8000A534 */  ori        $a1, $a1, 0x80
  .L8006EEC8:
    /* BB68 8006EEC8 14BC0108 */  j          .L8006F050
    /* BB6C 8006EECC 0000C5A0 */   sb        $a1, 0x0($a2)
  .L8006EED0:
    /* BB70 8006EED0 0000C290 */  lbu        $v0, 0x0($a2)
    /* BB74 8006EED4 00000000 */  nop
    /* BB78 8006EED8 01004230 */  andi       $v0, $v0, 0x1
    /* BB7C 8006EEDC 04004010 */  beqz       $v0, .L8006EEF0
    /* BB80 8006EEE0 00000000 */   nop
    /* BB84 8006EEE4 00006294 */  lhu        $v0, 0x0($v1)
    /* BB88 8006EEE8 BFBB0108 */  j          .L8006EEFC
    /* BB8C 8006EEEC 00204234 */   ori       $v0, $v0, 0x2000
  .L8006EEF0:
    /* BB90 8006EEF0 00006294 */  lhu        $v0, 0x0($v1)
    /* BB94 8006EEF4 00000000 */  nop
    /* BB98 8006EEF8 FFDF4230 */  andi       $v0, $v0, 0xDFFF
  .L8006EEFC:
    /* BB9C 8006EEFC 000062A4 */  sh         $v0, 0x0($v1)
    /* BBA0 8006EF00 0000C290 */  lbu        $v0, 0x0($a2)
    /* BBA4 8006EF04 00000000 */  nop
    /* BBA8 8006EF08 02004230 */  andi       $v0, $v0, 0x2
    /* BBAC 8006EF0C 04004010 */  beqz       $v0, .L8006EF20
    /* BBB0 8006EF10 04006324 */   addiu     $v1, $v1, 0x4
    /* BBB4 8006EF14 00006294 */  lhu        $v0, 0x0($v1)
    /* BBB8 8006EF18 CBBB0108 */  j          .L8006EF2C
    /* BBBC 8006EF1C 00204234 */   ori       $v0, $v0, 0x2000
  .L8006EF20:
    /* BBC0 8006EF20 00006294 */  lhu        $v0, 0x0($v1)
    /* BBC4 8006EF24 00000000 */  nop
    /* BBC8 8006EF28 FFDF4230 */  andi       $v0, $v0, 0xDFFF
  .L8006EF2C:
    /* BBCC 8006EF2C 000062A4 */  sh         $v0, 0x0($v1)
    /* BBD0 8006EF30 0000C290 */  lbu        $v0, 0x0($a2)
    /* BBD4 8006EF34 00000000 */  nop
    /* BBD8 8006EF38 04004230 */  andi       $v0, $v0, 0x4
    /* BBDC 8006EF3C 04004010 */  beqz       $v0, .L8006EF50
    /* BBE0 8006EF40 04006324 */   addiu     $v1, $v1, 0x4
    /* BBE4 8006EF44 00006294 */  lhu        $v0, 0x0($v1)
    /* BBE8 8006EF48 D7BB0108 */  j          .L8006EF5C
    /* BBEC 8006EF4C 00204234 */   ori       $v0, $v0, 0x2000
  .L8006EF50:
    /* BBF0 8006EF50 00006294 */  lhu        $v0, 0x0($v1)
    /* BBF4 8006EF54 00000000 */  nop
    /* BBF8 8006EF58 FFDF4230 */  andi       $v0, $v0, 0xDFFF
  .L8006EF5C:
    /* BBFC 8006EF5C 000062A4 */  sh         $v0, 0x0($v1)
    /* BC00 8006EF60 0000C290 */  lbu        $v0, 0x0($a2)
    /* BC04 8006EF64 00000000 */  nop
    /* BC08 8006EF68 08004230 */  andi       $v0, $v0, 0x8
    /* BC0C 8006EF6C 04004010 */  beqz       $v0, .L8006EF80
    /* BC10 8006EF70 04006324 */   addiu     $v1, $v1, 0x4
    /* BC14 8006EF74 00006294 */  lhu        $v0, 0x0($v1)
    /* BC18 8006EF78 E3BB0108 */  j          .L8006EF8C
    /* BC1C 8006EF7C 00204234 */   ori       $v0, $v0, 0x2000
  .L8006EF80:
    /* BC20 8006EF80 00006294 */  lhu        $v0, 0x0($v1)
    /* BC24 8006EF84 00000000 */  nop
    /* BC28 8006EF88 FFDF4230 */  andi       $v0, $v0, 0xDFFF
  .L8006EF8C:
    /* BC2C 8006EF8C 000062A4 */  sh         $v0, 0x0($v1)
    /* BC30 8006EF90 0000C290 */  lbu        $v0, 0x0($a2)
    /* BC34 8006EF94 00000000 */  nop
    /* BC38 8006EF98 10004230 */  andi       $v0, $v0, 0x10
    /* BC3C 8006EF9C 04004010 */  beqz       $v0, .L8006EFB0
    /* BC40 8006EFA0 04006324 */   addiu     $v1, $v1, 0x4
    /* BC44 8006EFA4 00006294 */  lhu        $v0, 0x0($v1)
    /* BC48 8006EFA8 EFBB0108 */  j          .L8006EFBC
    /* BC4C 8006EFAC 00204234 */   ori       $v0, $v0, 0x2000
  .L8006EFB0:
    /* BC50 8006EFB0 00006294 */  lhu        $v0, 0x0($v1)
    /* BC54 8006EFB4 00000000 */  nop
    /* BC58 8006EFB8 FFDF4230 */  andi       $v0, $v0, 0xDFFF
  .L8006EFBC:
    /* BC5C 8006EFBC 000062A4 */  sh         $v0, 0x0($v1)
    /* BC60 8006EFC0 0000C290 */  lbu        $v0, 0x0($a2)
    /* BC64 8006EFC4 00000000 */  nop
    /* BC68 8006EFC8 20004230 */  andi       $v0, $v0, 0x20
    /* BC6C 8006EFCC 04004010 */  beqz       $v0, .L8006EFE0
    /* BC70 8006EFD0 04006324 */   addiu     $v1, $v1, 0x4
    /* BC74 8006EFD4 00006294 */  lhu        $v0, 0x0($v1)
    /* BC78 8006EFD8 FBBB0108 */  j          .L8006EFEC
    /* BC7C 8006EFDC 00204234 */   ori       $v0, $v0, 0x2000
  .L8006EFE0:
    /* BC80 8006EFE0 00006294 */  lhu        $v0, 0x0($v1)
    /* BC84 8006EFE4 00000000 */  nop
    /* BC88 8006EFE8 FFDF4230 */  andi       $v0, $v0, 0xDFFF
  .L8006EFEC:
    /* BC8C 8006EFEC 000062A4 */  sh         $v0, 0x0($v1)
    /* BC90 8006EFF0 0000C290 */  lbu        $v0, 0x0($a2)
    /* BC94 8006EFF4 00000000 */  nop
    /* BC98 8006EFF8 40004230 */  andi       $v0, $v0, 0x40
    /* BC9C 8006EFFC 04004010 */  beqz       $v0, .L8006F010
    /* BCA0 8006F000 04006324 */   addiu     $v1, $v1, 0x4
    /* BCA4 8006F004 00006294 */  lhu        $v0, 0x0($v1)
    /* BCA8 8006F008 07BC0108 */  j          .L8006F01C
    /* BCAC 8006F00C 00204234 */   ori       $v0, $v0, 0x2000
  .L8006F010:
    /* BCB0 8006F010 00006294 */  lhu        $v0, 0x0($v1)
    /* BCB4 8006F014 00000000 */  nop
    /* BCB8 8006F018 FFDF4230 */  andi       $v0, $v0, 0xDFFF
  .L8006F01C:
    /* BCBC 8006F01C 000062A4 */  sh         $v0, 0x0($v1)
    /* BCC0 8006F020 0000C290 */  lbu        $v0, 0x0($a2)
    /* BCC4 8006F024 00000000 */  nop
    /* BCC8 8006F028 80004230 */  andi       $v0, $v0, 0x80
    /* BCCC 8006F02C 04004010 */  beqz       $v0, .L8006F040
    /* BCD0 8006F030 04006324 */   addiu     $v1, $v1, 0x4
    /* BCD4 8006F034 00006294 */  lhu        $v0, 0x0($v1)
    /* BCD8 8006F038 13BC0108 */  j          .L8006F04C
    /* BCDC 8006F03C 00204234 */   ori       $v0, $v0, 0x2000
  .L8006F040:
    /* BCE0 8006F040 00006294 */  lhu        $v0, 0x0($v1)
    /* BCE4 8006F044 00000000 */  nop
    /* BCE8 8006F048 FFDF4230 */  andi       $v0, $v0, 0xDFFF
  .L8006F04C:
    /* BCEC 8006F04C 000062A4 */  sh         $v0, 0x0($v1)
  .L8006F050:
    /* BCF0 8006F050 04006324 */  addiu      $v1, $v1, 0x4
    /* BCF4 8006F054 0100E724 */  addiu      $a3, $a3, 0x1
    /* BCF8 8006F058 2A10E400 */  slt        $v0, $a3, $a0
    /* BCFC 8006F05C 5CFF4014 */  bnez       $v0, .L8006EDD0
    /* BD00 8006F060 0100C624 */   addiu     $a2, $a2, 0x1
  .L8006F064:
    /* BD04 8006F064 0800E003 */  jr         $ra
    /* BD08 8006F068 00000000 */   nop
endlabel func_8006ED88
