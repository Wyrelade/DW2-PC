nonmatching Stg20_UpgradeListRefresh, 0x100

glabel Stg20_UpgradeListRefresh
    /* B9C4 8006ED24 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* B9C8 8006ED28 2400BFAF */  sw         $ra, 0x24($sp)
    /* B9CC 8006ED2C 2000B4AF */  sw         $s4, 0x20($sp)
    /* B9D0 8006ED30 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* B9D4 8006ED34 1800B2AF */  sw         $s2, 0x18($sp)
    /* B9D8 8006ED38 1400B1AF */  sw         $s1, 0x14($sp)
    /* B9DC 8006ED3C 1000B0AF */  sw         $s0, 0x10($sp)
    /* B9E0 8006ED40 2C00918C */  lw         $s1, 0x2C($a0)
    /* B9E4 8006ED44 00000000 */  nop
    /* B9E8 8006ED48 3400228E */  lw         $v0, 0x34($s1)
    /* B9EC 8006ED4C 00000000 */  nop
    /* B9F0 8006ED50 2C004010 */  beqz       $v0, .L8006EE04
    /* B9F4 8006ED54 21980000 */   addu      $s3, $zero, $zero
    /* B9F8 8006ED58 340020AE */  sw         $zero, 0x34($s1)
    /* B9FC 8006ED5C 0780023C */  lui        $v0, %hi(D_800706A4)
    /* BA00 8006ED60 A4065424 */  addiu      $s4, $v0, %lo(D_800706A4)
    /* BA04 8006ED64 10001024 */  addiu      $s0, $zero, 0x10
    /* BA08 8006ED68 38001224 */  addiu      $s2, $zero, 0x38
    /* BA0C 8006ED6C 21203002 */  addu       $a0, $s1, $s0
  .L8006ED70:
    /* BA10 8006ED70 21283202 */  addu       $a1, $s1, $s2
    /* BA14 8006ED74 21300000 */  addu       $a2, $zero, $zero
    /* BA18 8006ED78 21101402 */  addu       $v0, $s0, $s4
    /* BA1C 8006ED7C 04001026 */  addiu      $s0, $s0, 0x4
    /* BA20 8006ED80 20005226 */  addiu      $s2, $s2, 0x20
    /* BA24 8006ED84 01007326 */  addiu      $s3, $s3, 0x1
    /* BA28 8006ED88 02004794 */  lhu        $a3, 0x2($v0)
    /* BA2C 8006ED8C 00004294 */  lhu        $v0, 0x0($v0)
    /* BA30 8006ED90 003C0700 */  sll        $a3, $a3, 16
    /* BA34 8006ED94 3E4D000C */  jal        Text_OpenPacked
    /* BA38 8006ED98 25384700 */   or        $a3, $v0, $a3
    /* BA3C 8006ED9C 0600622A */  slti       $v0, $s3, 0x6
    /* BA40 8006EDA0 F3FF4014 */  bnez       $v0, .L8006ED70
    /* BA44 8006EDA4 21203002 */   addu      $a0, $s1, $s0
    /* BA48 8006EDA8 28003026 */  addiu      $s0, $s1, 0x28
    /* BA4C 8006EDAC E26E000C */  jal        Text_Close
    /* BA50 8006EDB0 21200002 */   addu      $a0, $s0, $zero
    /* BA54 8006EDB4 3000228E */  lw         $v0, 0x30($s1)
    /* BA58 8006EDB8 00000000 */  nop
    /* BA5C 8006EDBC 40110200 */  sll        $v0, $v0, 5
    /* BA60 8006EDC0 21102202 */  addu       $v0, $s1, $v0
    /* BA64 8006EDC4 5400448C */  lw         $a0, 0x54($v0)
    /* BA68 8006EDC8 00000000 */  nop
    /* BA6C 8006EDCC 0D008010 */  beqz       $a0, .L8006EE04
    /* BA70 8006EDD0 00000000 */   nop
    /* BA74 8006EDD4 2178000C */  jal        Item_GetDescText
    /* BA78 8006EDD8 00000000 */   nop
    /* BA7C 8006EDDC 21200002 */  addu       $a0, $s0, $zero
    /* BA80 8006EDE0 21284000 */  addu       $a1, $v0, $zero
    /* BA84 8006EDE4 21300000 */  addu       $a2, $zero, $zero
    /* BA88 8006EDE8 0780023C */  lui        $v0, %hi(D_800706A4)
    /* BA8C 8006EDEC A4064224 */  addiu      $v0, $v0, %lo(D_800706A4)
    /* BA90 8006EDF0 2A004794 */  lhu        $a3, 0x2A($v0)
    /* BA94 8006EDF4 28004294 */  lhu        $v0, 0x28($v0)
    /* BA98 8006EDF8 003C0700 */  sll        $a3, $a3, 16
    /* BA9C 8006EDFC 3E4D000C */  jal        Text_OpenPacked
    /* BAA0 8006EE00 25384700 */   or        $a3, $v0, $a3
  .L8006EE04:
    /* BAA4 8006EE04 2400BF8F */  lw         $ra, 0x24($sp)
    /* BAA8 8006EE08 2000B48F */  lw         $s4, 0x20($sp)
    /* BAAC 8006EE0C 1C00B38F */  lw         $s3, 0x1C($sp)
    /* BAB0 8006EE10 1800B28F */  lw         $s2, 0x18($sp)
    /* BAB4 8006EE14 1400B18F */  lw         $s1, 0x14($sp)
    /* BAB8 8006EE18 1000B08F */  lw         $s0, 0x10($sp)
    /* BABC 8006EE1C 0800E003 */  jr         $ra
    /* BAC0 8006EE20 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel Stg20_UpgradeListRefresh
