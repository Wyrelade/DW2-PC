nonmatching func_80067C74, 0x1D4

glabel func_80067C74
    /* 4914 80067C74 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 4918 80067C78 2400B3AF */  sw         $s3, 0x24($sp)
    /* 491C 80067C7C 21988000 */  addu       $s3, $a0, $zero
    /* 4920 80067C80 70000424 */  addiu      $a0, $zero, 0x70
    /* 4924 80067C84 2800BFAF */  sw         $ra, 0x28($sp)
    /* 4928 80067C88 2000B2AF */  sw         $s2, 0x20($sp)
    /* 492C 80067C8C 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 4930 80067C90 1800B0AF */  sw         $s0, 0x18($sp)
    /* 4934 80067C94 0800628E */  lw         $v0, 0x8($s3)
    /* 4938 80067C98 2C00708E */  lw         $s0, 0x2C($s3)
    /* 493C 80067C9C 80100200 */  sll        $v0, $v0, 2
    /* 4940 80067CA0 21100202 */  addu       $v0, $s0, $v0
    /* 4944 80067CA4 5400468C */  lw         $a2, 0x54($v0)
    /* 4948 80067CA8 E296010C */  jal        func_80065B88
    /* 494C 80067CAC 00600524 */   addiu     $a1, $zero, 0x6000
    /* 4950 80067CB0 0800638E */  lw         $v1, 0x8($s3)
    /* 4954 80067CB4 00000000 */  nop
    /* 4958 80067CB8 03006014 */  bnez       $v1, .L80067CC8
    /* 495C 80067CBC 21904000 */   addu      $s2, $v0, $zero
    /* 4960 80067CC0 339F0108 */  j          .L80067CCC
    /* 4964 80067CC4 28001126 */   addiu     $s1, $s0, 0x28
  .L80067CC8:
    /* 4968 80067CC8 2C001126 */  addiu      $s1, $s0, 0x2C
  .L80067CCC:
    /* 496C 80067CCC 0800628E */  lw         $v0, 0x8($s3)
    /* 4970 80067CD0 00000000 */  nop
    /* 4974 80067CD4 09004014 */  bnez       $v0, .L80067CFC
    /* 4978 80067CD8 21202002 */   addu      $a0, $s1, $zero
    /* 497C 80067CDC CF96010C */  jal        func_80065B3C
    /* 4980 80067CE0 21284002 */   addu      $a1, $s2, $zero
    /* 4984 80067CE4 21202002 */  addu       $a0, $s1, $zero
    /* 4988 80067CE8 EAFF0524 */  addiu      $a1, $zero, -0x16
    /* 498C 80067CEC D596010C */  jal        func_80065B54
    /* 4990 80067CF0 2328B200 */   subu      $a1, $a1, $s2
    /* 4994 80067CF4 429F0108 */  j          .L80067D08
    /* 4998 80067CF8 70000224 */   addiu     $v0, $zero, 0x70
  .L80067CFC:
    /* 499C 80067CFC CF96010C */  jal        func_80065B3C
    /* 49A0 80067D00 21284002 */   addu      $a1, $s2, $zero
    /* 49A4 80067D04 70000224 */  addiu      $v0, $zero, 0x70
  .L80067D08:
    /* 49A8 80067D08 18004216 */  bne        $s2, $v0, .L80067D6C
    /* 49AC 80067D0C 21202002 */   addu      $a0, $s1, $zero
    /* 49B0 80067D10 21280000 */  addu       $a1, $zero, $zero
    /* 49B4 80067D14 A4000624 */  addiu      $a2, $zero, 0xA4
    /* 49B8 80067D18 19000724 */  addiu      $a3, $zero, 0x19
    /* 49BC 80067D1C 02001024 */  addiu      $s0, $zero, 0x2
    /* 49C0 80067D20 C796010C */  jal        func_80065B1C
    /* 49C4 80067D24 1000B0AF */   sw        $s0, 0x10($sp)
    /* 49C8 80067D28 21202002 */  addu       $a0, $s1, $zero
    /* 49CC 80067D2C 01000524 */  addiu      $a1, $zero, 0x1
    /* 49D0 80067D30 A4000624 */  addiu      $a2, $zero, 0xA4
    /* 49D4 80067D34 19000724 */  addiu      $a3, $zero, 0x19
    /* 49D8 80067D38 C796010C */  jal        func_80065B1C
    /* 49DC 80067D3C 1000B0AF */   sw        $s0, 0x10($sp)
    /* 49E0 80067D40 21202002 */  addu       $a0, $s1, $zero
    /* 49E4 80067D44 21280002 */  addu       $a1, $s0, $zero
    /* 49E8 80067D48 A4000624 */  addiu      $a2, $zero, 0xA4
    /* 49EC 80067D4C 19000724 */  addiu      $a3, $zero, 0x19
    /* 49F0 80067D50 C796010C */  jal        func_80065B1C
    /* 49F4 80067D54 1000B0AF */   sw        $s0, 0x10($sp)
    /* 49F8 80067D58 21202002 */  addu       $a0, $s1, $zero
    /* 49FC 80067D5C 03000524 */  addiu      $a1, $zero, 0x3
    /* 4A00 80067D60 A4000624 */  addiu      $a2, $zero, 0xA4
    /* 4A04 80067D64 899F0108 */  j          .L80067E24
    /* 4A08 80067D68 19000724 */   addiu     $a3, $zero, 0x19
  .L80067D6C:
    /* 4A0C 80067D6C 0800628E */  lw         $v0, 0x8($s3)
    /* 4A10 80067D70 00000000 */  nop
    /* 4A14 80067D74 16004014 */  bnez       $v0, .L80067DD0
    /* 4A18 80067D78 FA000624 */   addiu     $a2, $zero, 0xFA
    /* 4A1C 80067D7C 21202002 */  addu       $a0, $s1, $zero
    /* 4A20 80067D80 21280000 */  addu       $a1, $zero, $zero
    /* 4A24 80067D84 2138A000 */  addu       $a3, $a1, $zero
    /* 4A28 80067D88 C796010C */  jal        func_80065B1C
    /* 4A2C 80067D8C 1000A0AF */   sw        $zero, 0x10($sp)
    /* 4A30 80067D90 21202002 */  addu       $a0, $s1, $zero
    /* 4A34 80067D94 01000524 */  addiu      $a1, $zero, 0x1
    /* 4A38 80067D98 21300000 */  addu       $a2, $zero, $zero
    /* 4A3C 80067D9C 2138C000 */  addu       $a3, $a2, $zero
    /* 4A40 80067DA0 FC001024 */  addiu      $s0, $zero, 0xFC
    /* 4A44 80067DA4 C796010C */  jal        func_80065B1C
    /* 4A48 80067DA8 1000B0AF */   sw        $s0, 0x10($sp)
    /* 4A4C 80067DAC 21202002 */  addu       $a0, $s1, $zero
    /* 4A50 80067DB0 02000524 */  addiu      $a1, $zero, 0x2
    /* 4A54 80067DB4 FA000624 */  addiu      $a2, $zero, 0xFA
    /* 4A58 80067DB8 21380000 */  addu       $a3, $zero, $zero
    /* 4A5C 80067DBC C796010C */  jal        func_80065B1C
    /* 4A60 80067DC0 1000A0AF */   sw        $zero, 0x10($sp)
    /* 4A64 80067DC4 21202002 */  addu       $a0, $s1, $zero
    /* 4A68 80067DC8 879F0108 */  j          .L80067E1C
    /* 4A6C 80067DCC 03000524 */   addiu     $a1, $zero, 0x3
  .L80067DD0:
    /* 4A70 80067DD0 01000524 */  addiu      $a1, $zero, 0x1
    /* 4A74 80067DD4 21380000 */  addu       $a3, $zero, $zero
    /* 4A78 80067DD8 C796010C */  jal        func_80065B1C
    /* 4A7C 80067DDC 1000A0AF */   sw        $zero, 0x10($sp)
    /* 4A80 80067DE0 21202002 */  addu       $a0, $s1, $zero
    /* 4A84 80067DE4 21280000 */  addu       $a1, $zero, $zero
    /* 4A88 80067DE8 2130A000 */  addu       $a2, $a1, $zero
    /* 4A8C 80067DEC 2138A000 */  addu       $a3, $a1, $zero
    /* 4A90 80067DF0 FC001024 */  addiu      $s0, $zero, 0xFC
    /* 4A94 80067DF4 C796010C */  jal        func_80065B1C
    /* 4A98 80067DF8 1000B0AF */   sw        $s0, 0x10($sp)
    /* 4A9C 80067DFC 21202002 */  addu       $a0, $s1, $zero
    /* 4AA0 80067E00 03000524 */  addiu      $a1, $zero, 0x3
    /* 4AA4 80067E04 FA000624 */  addiu      $a2, $zero, 0xFA
    /* 4AA8 80067E08 21380000 */  addu       $a3, $zero, $zero
    /* 4AAC 80067E0C C796010C */  jal        func_80065B1C
    /* 4AB0 80067E10 1000A0AF */   sw        $zero, 0x10($sp)
    /* 4AB4 80067E14 21202002 */  addu       $a0, $s1, $zero
    /* 4AB8 80067E18 02000524 */  addiu      $a1, $zero, 0x2
  .L80067E1C:
    /* 4ABC 80067E1C 21300000 */  addu       $a2, $zero, $zero
    /* 4AC0 80067E20 2138C000 */  addu       $a3, $a2, $zero
  .L80067E24:
    /* 4AC4 80067E24 C796010C */  jal        func_80065B1C
    /* 4AC8 80067E28 1000B0AF */   sw        $s0, 0x10($sp)
    /* 4ACC 80067E2C 2800BF8F */  lw         $ra, 0x28($sp)
    /* 4AD0 80067E30 2400B38F */  lw         $s3, 0x24($sp)
    /* 4AD4 80067E34 2000B28F */  lw         $s2, 0x20($sp)
    /* 4AD8 80067E38 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 4ADC 80067E3C 1800B08F */  lw         $s0, 0x18($sp)
    /* 4AE0 80067E40 0800E003 */  jr         $ra
    /* 4AE4 80067E44 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_80067C74
