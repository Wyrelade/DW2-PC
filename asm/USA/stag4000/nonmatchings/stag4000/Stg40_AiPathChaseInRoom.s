nonmatching Stg40_AiPathChaseInRoom, 0x230

glabel Stg40_AiPathChaseInRoom
    /* 885C 8006BBBC C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* 8860 8006BBC0 2150A000 */  addu       $t2, $a1, $zero
    /* 8864 8006BBC4 0780023C */  lui        $v0, %hi(D_80072B60)
    /* 8868 8006BBC8 3000B4AF */  sw         $s4, 0x30($sp)
    /* 886C 8006BBCC 21A00000 */  addu       $s4, $zero, $zero
    /* 8870 8006BBD0 602B428C */  lw         $v0, %lo(D_80072B60)($v0)
    /* 8874 8006BBD4 18008724 */  addiu      $a3, $a0, 0x18
    /* 8878 8006BBD8 3800BFAF */  sw         $ra, 0x38($sp)
    /* 887C 8006BBDC 3400B5AF */  sw         $s5, 0x34($sp)
    /* 8880 8006BBE0 2C00B3AF */  sw         $s3, 0x2C($sp)
    /* 8884 8006BBE4 2800B2AF */  sw         $s2, 0x28($sp)
    /* 8888 8006BBE8 2400B1AF */  sw         $s1, 0x24($sp)
    /* 888C 8006BBEC 2000B0AF */  sw         $s0, 0x20($sp)
    /* 8890 8006BBF0 0400438C */  lw         $v1, 0x4($v0)
    /* 8894 8006BBF4 18008694 */  lhu        $a2, 0x18($a0)
    /* 8898 8006BBF8 18006294 */  lhu        $v0, 0x18($v1)
    /* 889C 8006BBFC 1A006594 */  lhu        $a1, 0x1A($v1)
    /* 88A0 8006BC00 0200E394 */  lhu        $v1, 0x2($a3)
    /* 88A4 8006BC04 23104600 */  subu       $v0, $v0, $a2
    /* 88A8 8006BC08 2328A300 */  subu       $a1, $a1, $v1
    /* 88AC 8006BC0C 00140200 */  sll        $v0, $v0, 16
    /* 88B0 8006BC10 1000838C */  lw         $v1, 0x10($a0)
    /* 88B4 8006BC14 03240200 */  sra        $a0, $v0, 16
    /* 88B8 8006BC18 04006990 */  lbu        $t1, 0x4($v1)
    /* 88BC 8006BC1C 43008010 */  beqz       $a0, .L8006BD2C
    /* 88C0 8006BC20 2140A000 */   addu      $t0, $a1, $zero
    /* 88C4 8006BC24 00140500 */  sll        $v0, $a1, 16
    /* 88C8 8006BC28 031C0200 */  sra        $v1, $v0, 16
    /* 88CC 8006BC2C 37006010 */  beqz       $v1, .L8006BD0C
    /* 88D0 8006BC30 00000000 */   nop
    /* 88D4 8006BC34 02008104 */  bgez       $a0, .L8006BC40
    /* 88D8 8006BC38 21108000 */   addu      $v0, $a0, $zero
    /* 88DC 8006BC3C 23100200 */  negu       $v0, $v0
  .L8006BC40:
    /* 88E0 8006BC40 02006104 */  bgez       $v1, .L8006BC4C
    /* 88E4 8006BC44 00000000 */   nop
    /* 88E8 8006BC48 23180300 */  negu       $v1, $v1
  .L8006BC4C:
    /* 88EC 8006BC4C 2A104300 */  slt        $v0, $v0, $v1
    /* 88F0 8006BC50 18004014 */  bnez       $v0, .L8006BCB4
    /* 88F4 8006BC54 00000000 */   nop
    /* 88F8 8006BC58 02008104 */  bgez       $a0, .L8006BC64
    /* 88FC 8006BC5C 0100C224 */   addiu     $v0, $a2, 0x1
    /* 8900 8006BC60 FFFFC224 */  addiu      $v0, $a2, -0x1
  .L8006BC64:
    /* 8904 8006BC64 1000A2A7 */  sh         $v0, 0x10($sp)
    /* 8908 8006BC68 0200E294 */  lhu        $v0, 0x2($a3)
    /* 890C 8006BC6C 00000000 */  nop
    /* 8910 8006BC70 1200A2A7 */  sh         $v0, 0x12($sp)
    /* 8914 8006BC74 0000E294 */  lhu        $v0, 0x0($a3)
    /* 8918 8006BC78 00000000 */  nop
    /* 891C 8006BC7C 1400A2A7 */  sh         $v0, 0x14($sp)
    /* 8920 8006BC80 00140800 */  sll        $v0, $t0, 16
    /* 8924 8006BC84 06004104 */  bgez       $v0, .L8006BCA0
    /* 8928 8006BC88 00000000 */   nop
    /* 892C 8006BC8C 0200E294 */  lhu        $v0, 0x2($a3)
    /* 8930 8006BC90 00000000 */  nop
    /* 8934 8006BC94 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 8938 8006BC98 41AF0108 */  j          .L8006BD04
    /* 893C 8006BC9C 1600A2A7 */   sh        $v0, 0x16($sp)
  .L8006BCA0:
    /* 8940 8006BCA0 0200E294 */  lhu        $v0, 0x2($a3)
    /* 8944 8006BCA4 00000000 */  nop
    /* 8948 8006BCA8 01004224 */  addiu      $v0, $v0, 0x1
    /* 894C 8006BCAC 41AF0108 */  j          .L8006BD04
    /* 8950 8006BCB0 1600A2A7 */   sh        $v0, 0x16($sp)
  .L8006BCB4:
    /* 8954 8006BCB4 02008104 */  bgez       $a0, .L8006BCC0
    /* 8958 8006BCB8 0100C224 */   addiu     $v0, $a2, 0x1
    /* 895C 8006BCBC FFFFC224 */  addiu      $v0, $a2, -0x1
  .L8006BCC0:
    /* 8960 8006BCC0 1400A2A7 */  sh         $v0, 0x14($sp)
    /* 8964 8006BCC4 0200E294 */  lhu        $v0, 0x2($a3)
    /* 8968 8006BCC8 00000000 */  nop
    /* 896C 8006BCCC 1600A2A7 */  sh         $v0, 0x16($sp)
    /* 8970 8006BCD0 0000E294 */  lhu        $v0, 0x0($a3)
    /* 8974 8006BCD4 00000000 */  nop
    /* 8978 8006BCD8 1000A2A7 */  sh         $v0, 0x10($sp)
    /* 897C 8006BCDC 00140800 */  sll        $v0, $t0, 16
    /* 8980 8006BCE0 04004104 */  bgez       $v0, .L8006BCF4
    /* 8984 8006BCE4 00000000 */   nop
    /* 8988 8006BCE8 0200E294 */  lhu        $v0, 0x2($a3)
    /* 898C 8006BCEC 40AF0108 */  j          .L8006BD00
    /* 8990 8006BCF0 FFFF4224 */   addiu     $v0, $v0, -0x1
  .L8006BCF4:
    /* 8994 8006BCF4 0200E294 */  lhu        $v0, 0x2($a3)
    /* 8998 8006BCF8 00000000 */  nop
    /* 899C 8006BCFC 01004224 */  addiu      $v0, $v0, 0x1
  .L8006BD00:
    /* 89A0 8006BD00 1200A2A7 */  sh         $v0, 0x12($sp)
  .L8006BD04:
    /* 89A4 8006BD04 59AF0108 */  j          .L8006BD64
    /* 89A8 8006BD08 02001424 */   addiu     $s4, $zero, 0x2
  .L8006BD0C:
    /* 89AC 8006BD0C 02008104 */  bgez       $a0, .L8006BD18
    /* 89B0 8006BD10 0100C224 */   addiu     $v0, $a2, 0x1
    /* 89B4 8006BD14 FFFFC224 */  addiu      $v0, $a2, -0x1
  .L8006BD18:
    /* 89B8 8006BD18 1000A2A7 */  sh         $v0, 0x10($sp)
    /* 89BC 8006BD1C 0200E294 */  lhu        $v0, 0x2($a3)
    /* 89C0 8006BD20 01001424 */  addiu      $s4, $zero, 0x1
    /* 89C4 8006BD24 59AF0108 */  j          .L8006BD64
    /* 89C8 8006BD28 1200A2A7 */   sh        $v0, 0x12($sp)
  .L8006BD2C:
    /* 89CC 8006BD2C 00140500 */  sll        $v0, $a1, 16
    /* 89D0 8006BD30 03140200 */  sra        $v0, $v0, 16
    /* 89D4 8006BD34 0C004010 */  beqz       $v0, .L8006BD68
    /* 89D8 8006BD38 21900000 */   addu      $s2, $zero, $zero
    /* 89DC 8006BD3C 04004104 */  bgez       $v0, .L8006BD50
    /* 89E0 8006BD40 1000A6A7 */   sh        $a2, 0x10($sp)
    /* 89E4 8006BD44 0200E294 */  lhu        $v0, 0x2($a3)
    /* 89E8 8006BD48 57AF0108 */  j          .L8006BD5C
    /* 89EC 8006BD4C FFFF4224 */   addiu     $v0, $v0, -0x1
  .L8006BD50:
    /* 89F0 8006BD50 0200E294 */  lhu        $v0, 0x2($a3)
    /* 89F4 8006BD54 00000000 */  nop
    /* 89F8 8006BD58 01004224 */  addiu      $v0, $v0, 0x1
  .L8006BD5C:
    /* 89FC 8006BD5C 1200A2A7 */  sh         $v0, 0x12($sp)
    /* 8A00 8006BD60 01001424 */  addiu      $s4, $zero, 0x1
  .L8006BD64:
    /* 8A04 8006BD64 21900000 */  addu       $s2, $zero, $zero
  .L8006BD68:
    /* 8A08 8006BD68 16008012 */  beqz       $s4, .L8006BDC4
    /* 8A0C 8006BD6C 21984002 */   addu      $s3, $s2, $zero
    /* 8A10 8006BD70 21A82001 */  addu       $s5, $t1, $zero
    /* 8A14 8006BD74 1000B027 */  addiu      $s0, $sp, 0x10
    /* 8A18 8006BD78 21884001 */  addu       $s1, $t2, $zero
  .L8006BD7C:
    /* 8A1C 8006BD7C 00000486 */  lh         $a0, 0x0($s0)
    /* 8A20 8006BD80 02000586 */  lh         $a1, 0x2($s0)
    /* 8A24 8006BD84 F8C0010C */  jal        Stg40_GetCellFlags
    /* 8A28 8006BD88 00000000 */   nop
    /* 8A2C 8006BD8C 0F004230 */  andi       $v0, $v0, 0xF
    /* 8A30 8006BD90 0800A216 */  bne        $s5, $v0, .L8006BDB4
    /* 8A34 8006BD94 00000000 */   nop
    /* 8A38 8006BD98 00000296 */  lhu        $v0, 0x0($s0)
    /* 8A3C 8006BD9C 00000000 */  nop
    /* 8A40 8006BDA0 000022A6 */  sh         $v0, 0x0($s1)
    /* 8A44 8006BDA4 02000296 */  lhu        $v0, 0x2($s0)
    /* 8A48 8006BDA8 01007326 */  addiu      $s3, $s3, 0x1
    /* 8A4C 8006BDAC 020022A6 */  sh         $v0, 0x2($s1)
    /* 8A50 8006BDB0 04003126 */  addiu      $s1, $s1, 0x4
  .L8006BDB4:
    /* 8A54 8006BDB4 01005226 */  addiu      $s2, $s2, 0x1
    /* 8A58 8006BDB8 2A105402 */  slt        $v0, $s2, $s4
    /* 8A5C 8006BDBC EFFF4014 */  bnez       $v0, .L8006BD7C
    /* 8A60 8006BDC0 04001026 */   addiu     $s0, $s0, 0x4
  .L8006BDC4:
    /* 8A64 8006BDC4 21106002 */  addu       $v0, $s3, $zero
    /* 8A68 8006BDC8 3800BF8F */  lw         $ra, 0x38($sp)
    /* 8A6C 8006BDCC 3400B58F */  lw         $s5, 0x34($sp)
    /* 8A70 8006BDD0 3000B48F */  lw         $s4, 0x30($sp)
    /* 8A74 8006BDD4 2C00B38F */  lw         $s3, 0x2C($sp)
    /* 8A78 8006BDD8 2800B28F */  lw         $s2, 0x28($sp)
    /* 8A7C 8006BDDC 2400B18F */  lw         $s1, 0x24($sp)
    /* 8A80 8006BDE0 2000B08F */  lw         $s0, 0x20($sp)
    /* 8A84 8006BDE4 0800E003 */  jr         $ra
    /* 8A88 8006BDE8 4000BD27 */   addiu     $sp, $sp, 0x40
endlabel Stg40_AiPathChaseInRoom
