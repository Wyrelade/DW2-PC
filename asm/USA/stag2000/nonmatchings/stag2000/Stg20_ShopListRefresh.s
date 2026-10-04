nonmatching Stg20_ShopListRefresh, 0x29C

glabel Stg20_ShopListRefresh
    /* 955C 8006C8BC A0FFBD27 */  addiu      $sp, $sp, -0x60
    /* 9560 8006C8C0 5800BFAF */  sw         $ra, 0x58($sp)
    /* 9564 8006C8C4 5400B5AF */  sw         $s5, 0x54($sp)
    /* 9568 8006C8C8 5000B4AF */  sw         $s4, 0x50($sp)
    /* 956C 8006C8CC 4C00B3AF */  sw         $s3, 0x4C($sp)
    /* 9570 8006C8D0 4800B2AF */  sw         $s2, 0x48($sp)
    /* 9574 8006C8D4 4400B1AF */  sw         $s1, 0x44($sp)
    /* 9578 8006C8D8 4000B0AF */  sw         $s0, 0x40($sp)
    /* 957C 8006C8DC 2C00928C */  lw         $s2, 0x2C($a0)
    /* 9580 8006C8E0 00000000 */  nop
    /* 9584 8006C8E4 3C00428E */  lw         $v0, 0x3C($s2)
    /* 9588 8006C8E8 00000000 */  nop
    /* 958C 8006C8EC 91004010 */  beqz       $v0, .L8006CB34
    /* 9590 8006C8F0 00000000 */   nop
    /* 9594 8006C8F4 4400438E */  lw         $v1, 0x44($s2)
    /* 9598 8006C8F8 4C00448E */  lw         $a0, 0x4C($s2)
    /* 959C 8006C8FC 00000000 */  nop
    /* 95A0 8006C900 2A108300 */  slt        $v0, $a0, $v1
    /* 95A4 8006C904 03004010 */  beqz       $v0, .L8006C914
    /* 95A8 8006C908 C0A80300 */   sll       $s5, $v1, 3
    /* 95AC 8006C90C 21188000 */  addu       $v1, $a0, $zero
    /* 95B0 8006C910 C0A80300 */  sll        $s5, $v1, 3
  .L8006C914:
    /* 95B4 8006C914 21800000 */  addu       $s0, $zero, $zero
    /* 95B8 8006C918 1C001124 */  addiu      $s1, $zero, 0x1C
    /* 95BC 8006C91C 21000224 */  addiu      $v0, $zero, 0x21
    /* 95C0 8006C920 440043AE */  sw         $v1, 0x44($s2)
    /* 95C4 8006C924 1000A0AF */  sw         $zero, 0x10($sp)
    /* 95C8 8006C928 1400A0AF */  sw         $zero, 0x14($sp)
    /* 95CC 8006C92C 1800A2A7 */  sh         $v0, 0x18($sp)
    /* 95D0 8006C930 1C00A0AF */  sw         $zero, 0x1C($sp)
    /* 95D4 8006C934 2000A0AF */  sw         $zero, 0x20($sp)
    /* 95D8 8006C938 2800A0AF */  sw         $zero, 0x28($sp)
  .L8006C93C:
    /* 95DC 8006C93C E26E000C */  jal        Text_Close
    /* 95E0 8006C940 21205102 */   addu      $a0, $s2, $s1
    /* 95E4 8006C944 01001026 */  addiu      $s0, $s0, 0x1
    /* 95E8 8006C948 0800022A */  slti       $v0, $s0, 0x8
    /* 95EC 8006C94C FBFF4014 */  bnez       $v0, .L8006C93C
    /* 95F0 8006C950 04003126 */   addiu     $s1, $s1, 0x4
    /* 95F4 8006C954 21800000 */  addu       $s0, $zero, $zero
    /* 95F8 8006C958 0780023C */  lui        $v0, %hi(Stg20_ShopItems)
    /* 95FC 8006C95C 080A5424 */  addiu      $s4, $v0, %lo(Stg20_ShopItems)
    /* 9600 8006C960 1C001324 */  addiu      $s3, $zero, 0x1C
    /* 9604 8006C964 30001124 */  addiu      $s1, $zero, 0x30
  .L8006C968:
    /* 9608 8006C968 21181502 */  addu       $v1, $s0, $s5
    /* 960C 8006C96C 40300300 */  sll        $a2, $v1, 1
    /* 9610 8006C970 2110D400 */  addu       $v0, $a2, $s4
    /* 9614 8006C974 00004284 */  lh         $v0, 0x0($v0)
    /* 9618 8006C978 00000000 */  nop
    /* 961C 8006C97C 13004010 */  beqz       $v0, .L8006C9CC
    /* 9620 8006C980 21205302 */   addu      $a0, $s2, $s3
    /* 9624 8006C984 1000A527 */  addiu      $a1, $sp, 0x10
    /* 9628 8006C988 2110C300 */  addu       $v0, $a2, $v1
    /* 962C 8006C98C C0100200 */  sll        $v0, $v0, 3
    /* 9630 8006C990 21104300 */  addu       $v0, $v0, $v1
    /* 9634 8006C994 64008326 */  addiu      $v1, $s4, 0x64
    /* 9638 8006C998 21104300 */  addu       $v0, $v0, $v1
    /* 963C 8006C99C 2400A2AF */  sw         $v0, 0x24($sp)
    /* 9640 8006C9A0 09000224 */  addiu      $v0, $zero, 0x9
    /* 9644 8006C9A4 1A00B1A7 */  sh         $s1, 0x1A($sp)
    /* 9648 8006C9A8 500042A2 */  sb         $v0, 0x50($s2)
    /* 964C 8006C9AC FF000224 */  addiu      $v0, $zero, 0xFF
    /* 9650 8006C9B0 096F000C */  jal        Text_Open
    /* 9654 8006C9B4 510042A2 */   sb        $v0, 0x51($s2)
    /* 9658 8006C9B8 04007326 */  addiu      $s3, $s3, 0x4
    /* 965C 8006C9BC 01001026 */  addiu      $s0, $s0, 0x1
    /* 9660 8006C9C0 0800022A */  slti       $v0, $s0, 0x8
    /* 9664 8006C9C4 E8FF4014 */  bnez       $v0, .L8006C968
    /* 9668 8006C9C8 0C003126 */   addiu     $s1, $s1, 0xC
  .L8006C9CC:
    /* 966C 8006C9CC 10005126 */  addiu      $s1, $s2, 0x10
    /* 9670 8006C9D0 4400438E */  lw         $v1, 0x44($s2)
    /* 9674 8006C9D4 4000428E */  lw         $v0, 0x40($s2)
    /* 9678 8006C9D8 C0180300 */  sll        $v1, $v1, 3
    /* 967C 8006C9DC 21104300 */  addu       $v0, $v0, $v1
    /* 9680 8006C9E0 40100200 */  sll        $v0, $v0, 1
    /* 9684 8006C9E4 21105400 */  addu       $v0, $v0, $s4
    /* 9688 8006C9E8 00005084 */  lh         $s0, 0x0($v0)
    /* 968C 8006C9EC E26E000C */  jal        Text_Close
    /* 9690 8006C9F0 21202002 */   addu      $a0, $s1, $zero
    /* 9694 8006C9F4 11000012 */  beqz       $s0, .L8006CA3C
    /* 9698 8006C9F8 0780023C */   lui       $v0, %hi(Stg20_ShopSellMode)
    /* 969C 8006C9FC 2178000C */  jal        Item_GetDescText
    /* 96A0 8006CA00 21200002 */   addu      $a0, $s0, $zero
    /* 96A4 8006CA04 21202002 */  addu       $a0, $s1, $zero
    /* 96A8 8006CA08 1000A527 */  addiu      $a1, $sp, 0x10
    /* 96AC 8006CA0C 2400A2AF */  sw         $v0, 0x24($sp)
    /* 96B0 8006CA10 13000224 */  addiu      $v0, $zero, 0x13
    /* 96B4 8006CA14 1800A2A7 */  sh         $v0, 0x18($sp)
    /* 96B8 8006CA18 A2000224 */  addiu      $v0, $zero, 0xA2
    /* 96BC 8006CA1C 1000A0AF */  sw         $zero, 0x10($sp)
    /* 96C0 8006CA20 1400A0AF */  sw         $zero, 0x14($sp)
    /* 96C4 8006CA24 1A00A2A7 */  sh         $v0, 0x1A($sp)
    /* 96C8 8006CA28 1C00A0AF */  sw         $zero, 0x1C($sp)
    /* 96CC 8006CA2C 2000A0AF */  sw         $zero, 0x20($sp)
    /* 96D0 8006CA30 096F000C */  jal        Text_Open
    /* 96D4 8006CA34 2800A0AF */   sw        $zero, 0x28($sp)
    /* 96D8 8006CA38 0780023C */  lui        $v0, %hi(Stg20_ShopSellMode)
  .L8006CA3C:
    /* 96DC 8006CA3C 040A428C */  lw         $v0, %lo(Stg20_ShopSellMode)($v0)
    /* 96E0 8006CA40 00000000 */  nop
    /* 96E4 8006CA44 08004014 */  bnez       $v0, .L8006CA68
    /* 96E8 8006CA48 00000000 */   nop
    /* 96EC 8006CA4C 05000012 */  beqz       $s0, .L8006CA64
    /* 96F0 8006CA50 00000000 */   nop
    /* 96F4 8006CA54 EEB0010C */  jal        Stg20_CountOwnedItem
    /* 96F8 8006CA58 21200002 */   addu      $a0, $s0, $zero
    /* 96FC 8006CA5C 9AB20108 */  j          .L8006CA68
    /* 9700 8006CA60 580042AE */   sw        $v0, 0x58($s2)
  .L8006CA64:
    /* 9704 8006CA64 580040AE */  sw         $zero, 0x58($s2)
  .L8006CA68:
    /* 9708 8006CA68 14005026 */  addiu      $s0, $s2, 0x14
    /* 970C 8006CA6C E26E000C */  jal        Text_Close
    /* 9710 8006CA70 21200002 */   addu      $a0, $s0, $zero
    /* 9714 8006CA74 5C00428E */  lw         $v0, 0x5C($s2)
    /* 9718 8006CA78 00000000 */  nop
    /* 971C 8006CA7C 13004010 */  beqz       $v0, .L8006CACC
    /* 9720 8006CA80 FD01043C */   lui       $a0, (0x1FD0000 >> 16)
    /* 9724 8006CA84 688E000C */  jal        Cd_GetFileEntry
    /* 9728 8006CA88 21204400 */   addu      $a0, $v0, $a0
    /* 972C 8006CA8C 21200002 */  addu       $a0, $s0, $zero
    /* 9730 8006CA90 1000A527 */  addiu      $a1, $sp, 0x10
    /* 9734 8006CA94 2400A2AF */  sw         $v0, 0x24($sp)
    /* 9738 8006CA98 0780023C */  lui        $v0, %hi(D_800704E4)
    /* 973C 8006CA9C E4044224 */  addiu      $v0, $v0, %lo(D_800704E4)
    /* 9740 8006CAA0 10004394 */  lhu        $v1, 0x10($v0)
    /* 9744 8006CAA4 12004694 */  lhu        $a2, 0x12($v0)
    /* 9748 8006CAA8 01000224 */  addiu      $v0, $zero, 0x1
    /* 974C 8006CAAC 1000A2AF */  sw         $v0, 0x10($sp)
    /* 9750 8006CAB0 1400A0AF */  sw         $zero, 0x14($sp)
    /* 9754 8006CAB4 1C00A0AF */  sw         $zero, 0x1C($sp)
    /* 9758 8006CAB8 2000A0AF */  sw         $zero, 0x20($sp)
    /* 975C 8006CABC 2800A0AF */  sw         $zero, 0x28($sp)
    /* 9760 8006CAC0 1800A3A7 */  sh         $v1, 0x18($sp)
    /* 9764 8006CAC4 096F000C */  jal        Text_Open
    /* 9768 8006CAC8 1A00A6A7 */   sh        $a2, 0x1A($sp)
  .L8006CACC:
    /* 976C 8006CACC 18005026 */  addiu      $s0, $s2, 0x18
    /* 9770 8006CAD0 E26E000C */  jal        Text_Close
    /* 9774 8006CAD4 21200002 */   addu      $a0, $s0, $zero
    /* 9778 8006CAD8 6000428E */  lw         $v0, 0x60($s2)
    /* 977C 8006CADC 00000000 */  nop
    /* 9780 8006CAE0 13004010 */  beqz       $v0, .L8006CB30
    /* 9784 8006CAE4 FD01043C */   lui       $a0, (0x1FD0000 >> 16)
    /* 9788 8006CAE8 688E000C */  jal        Cd_GetFileEntry
    /* 978C 8006CAEC 21204400 */   addu      $a0, $v0, $a0
    /* 9790 8006CAF0 21200002 */  addu       $a0, $s0, $zero
    /* 9794 8006CAF4 1000A527 */  addiu      $a1, $sp, 0x10
    /* 9798 8006CAF8 2400A2AF */  sw         $v0, 0x24($sp)
    /* 979C 8006CAFC 0780023C */  lui        $v0, %hi(D_800704E4)
    /* 97A0 8006CB00 E4044224 */  addiu      $v0, $v0, %lo(D_800704E4)
    /* 97A4 8006CB04 14004394 */  lhu        $v1, 0x14($v0)
    /* 97A8 8006CB08 16004694 */  lhu        $a2, 0x16($v0)
    /* 97AC 8006CB0C 01000224 */  addiu      $v0, $zero, 0x1
    /* 97B0 8006CB10 1000A2AF */  sw         $v0, 0x10($sp)
    /* 97B4 8006CB14 1400A0AF */  sw         $zero, 0x14($sp)
    /* 97B8 8006CB18 1C00A0AF */  sw         $zero, 0x1C($sp)
    /* 97BC 8006CB1C 2000A0AF */  sw         $zero, 0x20($sp)
    /* 97C0 8006CB20 2800A0AF */  sw         $zero, 0x28($sp)
    /* 97C4 8006CB24 1800A3A7 */  sh         $v1, 0x18($sp)
    /* 97C8 8006CB28 096F000C */  jal        Text_Open
    /* 97CC 8006CB2C 1A00A6A7 */   sh        $a2, 0x1A($sp)
  .L8006CB30:
    /* 97D0 8006CB30 3C0040AE */  sw         $zero, 0x3C($s2)
  .L8006CB34:
    /* 97D4 8006CB34 5800BF8F */  lw         $ra, 0x58($sp)
    /* 97D8 8006CB38 5400B58F */  lw         $s5, 0x54($sp)
    /* 97DC 8006CB3C 5000B48F */  lw         $s4, 0x50($sp)
    /* 97E0 8006CB40 4C00B38F */  lw         $s3, 0x4C($sp)
    /* 97E4 8006CB44 4800B28F */  lw         $s2, 0x48($sp)
    /* 97E8 8006CB48 4400B18F */  lw         $s1, 0x44($sp)
    /* 97EC 8006CB4C 4000B08F */  lw         $s0, 0x40($sp)
    /* 97F0 8006CB50 0800E003 */  jr         $ra
    /* 97F4 8006CB54 6000BD27 */   addiu     $sp, $sp, 0x60
endlabel Stg20_ShopListRefresh
