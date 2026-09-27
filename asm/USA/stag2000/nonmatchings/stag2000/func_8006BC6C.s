nonmatching func_8006BC6C, 0x164

glabel func_8006BC6C
    /* 890C 8006BC6C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 8910 8006BC70 1400B1AF */  sw         $s1, 0x14($sp)
    /* 8914 8006BC74 21888000 */  addu       $s1, $a0, $zero
    /* 8918 8006BC78 01000224 */  addiu      $v0, $zero, 0x1
    /* 891C 8006BC7C 1800BFAF */  sw         $ra, 0x18($sp)
    /* 8920 8006BC80 1000B0AF */  sw         $s0, 0x10($sp)
    /* 8924 8006BC84 1000268E */  lw         $a2, 0x10($s1)
    /* 8928 8006BC88 2C00308E */  lw         $s0, 0x2C($s1)
    /* 892C 8006BC8C 2200C210 */  beq        $a2, $v0, .L8006BD18
    /* 8930 8006BC90 0200C228 */   slti      $v0, $a2, 0x2
    /* 8934 8006BC94 49004010 */  beqz       $v0, .L8006BDBC
    /* 8938 8006BC98 00000000 */   nop
    /* 893C 8006BC9C 4700C014 */  bnez       $a2, .L8006BDBC
    /* 8940 8006BCA0 21200002 */   addu      $a0, $s0, $zero
    /* 8944 8006BCA4 2270000C */  jal        Mem_FillWordsNeg1
    /* 8948 8006BCA8 02000524 */   addiu     $a1, $zero, 0x2
    /* 894C 8006BCAC 21200002 */  addu       $a0, $s0, $zero
    /* 8950 8006BCB0 2B010524 */  addiu      $a1, $zero, 0x12B
    /* 8954 8006BCB4 21300000 */  addu       $a2, $zero, $zero
    /* 8958 8006BCB8 0680033C */  lui        $v1, %hi(D_8006358C)
    /* 895C 8006BCBC 8C356224 */  addiu      $v0, $v1, %lo(D_8006358C)
    /* 8960 8006BCC0 02004794 */  lhu        $a3, 0x2($v0)
    /* 8964 8006BCC4 8C356294 */  lhu        $v0, %lo(D_8006358C)($v1)
    /* 8968 8006BCC8 003C0700 */  sll        $a3, $a3, 16
    /* 896C 8006BCCC F26F000C */  jal        Text_OpenById
    /* 8970 8006BCD0 25384700 */   or        $a3, $v0, $a3
    /* 8974 8006BCD4 04000426 */  addiu      $a0, $s0, 0x4
    /* 8978 8006BCD8 2C010524 */  addiu      $a1, $zero, 0x12C
    /* 897C 8006BCDC 21300000 */  addu       $a2, $zero, $zero
    /* 8980 8006BCE0 0680033C */  lui        $v1, %hi(D_80063590)
    /* 8984 8006BCE4 90356224 */  addiu      $v0, $v1, %lo(D_80063590)
    /* 8988 8006BCE8 02004794 */  lhu        $a3, 0x2($v0)
    /* 898C 8006BCEC 90356294 */  lhu        $v0, %lo(D_80063590)($v1)
    /* 8990 8006BCF0 003C0700 */  sll        $a3, $a3, 16
    /* 8994 8006BCF4 F26F000C */  jal        Text_OpenById
    /* 8998 8006BCF8 25384700 */   or        $a3, $v0, $a3
    /* 899C 8006BCFC 5145000C */  jal        Task_NextState0
    /* 89A0 8006BD00 21202002 */   addu      $a0, $s1, $zero
    /* 89A4 8006BD04 6FAF0108 */  j          .L8006BDBC
    /* 89A8 8006BD08 00000000 */   nop
  .L8006BD0C:
    /* 89AC 8006BD0C B8FFE6AC */  sw         $a2, -0x48($a3)
    /* 89B0 8006BD10 6AAF0108 */  j          .L8006BDA8
    /* 89B4 8006BD14 0B000424 */   addiu     $a0, $zero, 0xB
  .L8006BD18:
    /* 89B8 8006BD18 0780053C */  lui        $a1, %hi(D_80070A00)
    /* 89BC 8006BD1C 000AA724 */  addiu      $a3, $a1, %lo(D_80070A00)
    /* 89C0 8006BD20 0680023C */  lui        $v0, %hi(D_8005F6F0)
    /* 89C4 8006BD24 F0F6438C */  lw         $v1, %lo(D_8005F6F0)($v0)
    /* 89C8 8006BD28 00000000 */  nop
    /* 89CC 8006BD2C 07006018 */  blez       $v1, .L8006BD4C
    /* 89D0 8006BD30 F0F64424 */   addiu     $a0, $v0, %lo(D_8005F6F0)
    /* 89D4 8006BD34 000AA28C */  lw         $v0, %lo(D_80070A00)($a1)
    /* 89D8 8006BD38 00000000 */  nop
    /* 89DC 8006BD3C 1F004014 */  bnez       $v0, .L8006BDBC
    /* 89E0 8006BD40 00000000 */   nop
    /* 89E4 8006BD44 5CAF0108 */  j          .L8006BD70
    /* 89E8 8006BD48 000AA6AC */   sw        $a2, %lo(D_80070A00)($a1)
  .L8006BD4C:
    /* 89EC 8006BD4C 0400828C */  lw         $v0, 0x4($a0)
    /* 89F0 8006BD50 00000000 */  nop
    /* 89F4 8006BD54 0B004018 */  blez       $v0, .L8006BD84
    /* 89F8 8006BD58 00000000 */   nop
    /* 89FC 8006BD5C 000AA28C */  lw         $v0, %lo(D_80070A00)($a1)
    /* 8A00 8006BD60 00000000 */  nop
    /* 8A04 8006BD64 15004010 */  beqz       $v0, .L8006BDBC
    /* 8A08 8006BD68 FFFF4224 */   addiu     $v0, $v0, -0x1
    /* 8A0C 8006BD6C 000AA2AC */  sw         $v0, %lo(D_80070A00)($a1)
  .L8006BD70:
    /* 8A10 8006BD70 0C000424 */  addiu      $a0, $zero, 0xC
    /* 8A14 8006BD74 A369000C */  jal        Snd_PlayById
    /* 8A18 8006BD78 21280000 */   addu      $a1, $zero, $zero
    /* 8A1C 8006BD7C 6FAF0108 */  j          .L8006BDBC
    /* 8A20 8006BD80 00000000 */   nop
  .L8006BD84:
    /* 8A24 8006BD84 1C00828C */  lw         $v0, 0x1C($a0)
    /* 8A28 8006BD88 00000000 */  nop
    /* 8A2C 8006BD8C DFFF401C */  bgtz       $v0, .L8006BD0C
    /* 8A30 8006BD90 00000000 */   nop
    /* 8A34 8006BD94 1400828C */  lw         $v0, 0x14($a0)
    /* 8A38 8006BD98 00000000 */  nop
    /* 8A3C 8006BD9C 07004018 */  blez       $v0, .L8006BDBC
    /* 8A40 8006BDA0 0A000424 */   addiu     $a0, $zero, 0xA
    /* 8A44 8006BDA4 B8FFE0AC */  sw         $zero, -0x48($a3)
  .L8006BDA8:
    /* 8A48 8006BDA8 A369000C */  jal        Snd_PlayById
    /* 8A4C 8006BDAC 21280000 */   addu      $a1, $zero, $zero
    /* 8A50 8006BDB0 21202002 */  addu       $a0, $s1, $zero
    /* 8A54 8006BDB4 7045000C */  jal        Task_SetState0
    /* 8A58 8006BDB8 03000524 */   addiu     $a1, $zero, 0x3
  .L8006BDBC:
    /* 8A5C 8006BDBC 1800BF8F */  lw         $ra, 0x18($sp)
    /* 8A60 8006BDC0 1400B18F */  lw         $s1, 0x14($sp)
    /* 8A64 8006BDC4 1000B08F */  lw         $s0, 0x10($sp)
    /* 8A68 8006BDC8 0800E003 */  jr         $ra
    /* 8A6C 8006BDCC 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8006BC6C
