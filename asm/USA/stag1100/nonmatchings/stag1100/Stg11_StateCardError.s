nonmatching Stg11_StateCardError, 0x164

glabel Stg11_StateCardError
    /* 17A0 80064B00 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 17A4 80064B04 1800B2AF */  sw         $s2, 0x18($sp)
    /* 17A8 80064B08 21908000 */  addu       $s2, $a0, $zero
    /* 17AC 80064B0C 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 17B0 80064B10 1400B1AF */  sw         $s1, 0x14($sp)
    /* 17B4 80064B14 1000B0AF */  sw         $s0, 0x10($sp)
    /* 17B8 80064B18 1800438E */  lw         $v1, 0x18($s2)
    /* 17BC 80064B1C 00000000 */  nop
    /* 17C0 80064B20 06006010 */  beqz       $v1, .L80064B3C
    /* 17C4 80064B24 2188A000 */   addu      $s1, $a1, $zero
    /* 17C8 80064B28 01000224 */  addiu      $v0, $zero, 0x1
    /* 17CC 80064B2C 34006210 */  beq        $v1, $v0, .L80064C00
    /* 17D0 80064B30 21204002 */   addu      $a0, $s2, $zero
    /* 17D4 80064B34 11930108 */  j          .L80064C44
    /* 17D8 80064B38 00000000 */   nop
  .L80064B3C:
    /* 17DC 80064B3C 069E010C */  jal        Stg11_CardGetResult
    /* 17E0 80064B40 21800000 */   addu      $s0, $zero, $zero
    /* 17E4 80064B44 FFFF4324 */  addiu      $v1, $v0, -0x1
    /* 17E8 80064B48 0B00622C */  sltiu      $v0, $v1, 0xB
    /* 17EC 80064B4C 1F004010 */  beqz       $v0, .L80064BCC
    /* 17F0 80064B50 0680023C */   lui       $v0, %hi(jtbl_80063360)
    /* 17F4 80064B54 60334224 */  addiu      $v0, $v0, %lo(jtbl_80063360)
    /* 17F8 80064B58 80180300 */  sll        $v1, $v1, 2
    /* 17FC 80064B5C 21186200 */  addu       $v1, $v1, $v0
    /* 1800 80064B60 0000628C */  lw         $v0, 0x0($v1)
    /* 1804 80064B64 00000000 */  nop
    /* 1808 80064B68 08004000 */  jr         $v0
    /* 180C 80064B6C 00000000 */   nop
  jlabel .L80064B70
    /* 1810 80064B70 7A002286 */  lh         $v0, 0x7A($s1)
    /* 1814 80064B74 00000000 */  nop
    /* 1818 80064B78 14004014 */  bnez       $v0, .L80064BCC
    /* 181C 80064B7C 6E011024 */   addiu     $s0, $zero, 0x16E
    /* 1820 80064B80 F3920108 */  j          .L80064BCC
    /* 1824 80064B84 6D011024 */   addiu     $s0, $zero, 0x16D
  jlabel .L80064B88
    /* 1828 80064B88 F3920108 */  j          .L80064BCC
    /* 182C 80064B8C 83011024 */   addiu     $s0, $zero, 0x183
  jlabel .L80064B90
    /* 1830 80064B90 F3920108 */  j          .L80064BCC
    /* 1834 80064B94 82011024 */   addiu     $s0, $zero, 0x182
  jlabel .L80064B98
    /* 1838 80064B98 F3920108 */  j          .L80064BCC
    /* 183C 80064B9C 71011024 */   addiu     $s0, $zero, 0x171
  jlabel .L80064BA0
    /* 1840 80064BA0 F3920108 */  j          .L80064BCC
    /* 1844 80064BA4 94011024 */   addiu     $s0, $zero, 0x194
  jlabel .L80064BA8
    /* 1848 80064BA8 F3920108 */  j          .L80064BCC
    /* 184C 80064BAC 6F011024 */   addiu     $s0, $zero, 0x16F
  jlabel .L80064BB0
    /* 1850 80064BB0 F3920108 */  j          .L80064BCC
    /* 1854 80064BB4 6E011024 */   addiu     $s0, $zero, 0x16E
  jlabel .L80064BB8
    /* 1858 80064BB8 80002286 */  lh         $v0, 0x80($s1)
    /* 185C 80064BBC 00000000 */  nop
    /* 1860 80064BC0 02004010 */  beqz       $v0, .L80064BCC
    /* 1864 80064BC4 86011024 */   addiu     $s0, $zero, 0x186
    /* 1868 80064BC8 B1011024 */  addiu      $s0, $zero, 0x1B1
  jlabel .L80064BCC
    /* 186C 80064BCC 21202002 */  addu       $a0, $s1, $zero
    /* 1870 80064BD0 3992010C */  jal        Stg11_SetStatusMsg
    /* 1874 80064BD4 21280002 */   addu      $a1, $s0, $zero
    /* 1878 80064BD8 21204002 */  addu       $a0, $s2, $zero
    /* 187C 80064BDC 2D92010C */  jal        Stg11_CloseSlotText
    /* 1880 80064BE0 21282002 */   addu      $a1, $s1, $zero
    /* 1884 80064BE4 84002586 */  lh         $a1, 0x84($s1)
    /* 1888 80064BE8 EB9D010C */  jal        Stg11_CardStartOp
    /* 188C 80064BEC 04000424 */   addiu     $a0, $zero, 0x4
    /* 1890 80064BF0 6045000C */  jal        Task_NextState2
    /* 1894 80064BF4 21204002 */   addu      $a0, $s2, $zero
    /* 1898 80064BF8 11930108 */  j          .L80064C44
    /* 189C 80064BFC 21204002 */   addu      $a0, $s2, $zero
  .L80064C00:
    /* 18A0 80064C00 0680023C */  lui        $v0, %hi(D_8005F6F0)
    /* 18A4 80064C04 7E002386 */  lh         $v1, 0x7E($s1)
    /* 18A8 80064C08 F0F64224 */  addiu      $v0, $v0, %lo(D_8005F6F0)
    /* 18AC 80064C0C 80190300 */  sll        $v1, $v1, 6
    /* 18B0 80064C10 21186200 */  addu       $v1, $v1, $v0
    /* 18B4 80064C14 1C00628C */  lw         $v0, 0x1C($v1)
    /* 18B8 80064C18 00000000 */  nop
    /* 18BC 80064C1C 08004018 */  blez       $v0, .L80064C40
    /* 18C0 80064C20 0B000424 */   addiu     $a0, $zero, 0xB
    /* 18C4 80064C24 A369000C */  jal        Snd_PlayById
    /* 18C8 80064C28 21280000 */   addu      $a1, $zero, $zero
    /* 18CC 80064C2C 21204002 */  addu       $a0, $s2, $zero
    /* 18D0 80064C30 7045000C */  jal        Task_SetState0
    /* 18D4 80064C34 02000524 */   addiu     $a1, $zero, 0x2
    /* 18D8 80064C38 13930108 */  j          .L80064C4C
    /* 18DC 80064C3C 00000000 */   nop
  .L80064C40:
    /* 18E0 80064C40 21204002 */  addu       $a0, $s2, $zero
  .L80064C44:
    /* 18E4 80064C44 7E92010C */  jal        Stg11_WatchCardRemoved
    /* 18E8 80064C48 21282002 */   addu      $a1, $s1, $zero
  .L80064C4C:
    /* 18EC 80064C4C 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 18F0 80064C50 1800B28F */  lw         $s2, 0x18($sp)
    /* 18F4 80064C54 1400B18F */  lw         $s1, 0x14($sp)
    /* 18F8 80064C58 1000B08F */  lw         $s0, 0x10($sp)
    /* 18FC 80064C5C 0800E003 */  jr         $ra
    /* 1900 80064C60 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Stg11_StateCardError
