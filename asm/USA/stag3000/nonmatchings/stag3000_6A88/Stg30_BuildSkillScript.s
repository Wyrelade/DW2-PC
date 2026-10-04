nonmatching Stg30_BuildSkillScript, 0xE64

glabel Stg30_BuildSkillScript
    /* 8878 8006BBD8 78FFBD27 */  addiu      $sp, $sp, -0x88
    /* 887C 8006BBDC 6C00B3AF */  sw         $s3, 0x6C($sp)
    /* 8880 8006BBE0 21988000 */  addu       $s3, $a0, $zero
    /* 8884 8006BBE4 7C00B7AF */  sw         $s7, 0x7C($sp)
    /* 8888 8006BBE8 01001724 */  addiu      $s7, $zero, 0x1
    /* 888C 8006BBEC 0780023C */  lui        $v0, %hi(Stg30_BattleScript)
    /* 8890 8006BBF0 6000B0AF */  sw         $s0, 0x60($sp)
    /* 8894 8006BBF4 90385024 */  addiu      $s0, $v0, %lo(Stg30_BattleScript)
    /* 8898 8006BBF8 6400B1AF */  sw         $s1, 0x64($sp)
    /* 889C 8006BBFC 00891300 */  sll        $s1, $s3, 4
    /* 88A0 8006BC00 0780023C */  lui        $v0, %hi(D_80073F6C)
    /* 88A4 8006BC04 6C3F4224 */  addiu      $v0, $v0, %lo(D_80073F6C)
    /* 88A8 8006BC08 8000BEAF */  sw         $fp, 0x80($sp)
    /* 88AC 8006BC0C 21F02202 */  addu       $fp, $s1, $v0
    /* 88B0 8006BC10 8400BFAF */  sw         $ra, 0x84($sp)
    /* 88B4 8006BC14 7800B6AF */  sw         $s6, 0x78($sp)
    /* 88B8 8006BC18 7400B5AF */  sw         $s5, 0x74($sp)
    /* 88BC 8006BC1C 7000B4AF */  sw         $s4, 0x70($sp)
    /* 88C0 8006BC20 6800B2AF */  sw         $s2, 0x68($sp)
    /* 88C4 8006BC24 0600D697 */  lhu        $s6, 0x6($fp)
    /* 88C8 8006BC28 54FD5224 */  addiu      $s2, $v0, -0x2AC
    /* 88CC 8006BC2C B40357A6 */  sh         $s7, 0x3B4($s2)
    /* 88D0 8006BC30 00241600 */  sll        $a0, $s6, 16
    /* 88D4 8006BC34 087C000C */  jal        func_8001F020
    /* 88D8 8006BC38 03240400 */   sra       $a0, $a0, 16
    /* 88DC 8006BC3C 21184000 */  addu       $v1, $v0, $zero
    /* 88E0 8006BC40 01006230 */  andi       $v0, $v1, 0x1
    /* 88E4 8006BC44 02004010 */  beqz       $v0, .L8006BC50
    /* 88E8 8006BC48 21103202 */   addu      $v0, $s1, $s2
    /* 88EC 8006BC4C BA0257A0 */  sb         $s7, 0x2BA($v0)
  .L8006BC50:
    /* 88F0 8006BC50 02006230 */  andi       $v0, $v1, 0x2
    /* 88F4 8006BC54 02004010 */  beqz       $v0, .L8006BC60
    /* 88F8 8006BC58 21103202 */   addu      $v0, $s1, $s2
    /* 88FC 8006BC5C BB0257A0 */  sb         $s7, 0x2BB($v0)
  .L8006BC60:
    /* 8900 8006BC60 40006230 */  andi       $v0, $v1, 0x40
    /* 8904 8006BC64 0E004010 */  beqz       $v0, .L8006BCA0
    /* 8908 8006BC68 40101300 */   sll       $v0, $s3, 1
    /* 890C 8006BC6C 21105300 */  addu       $v0, $v0, $s3
    /* 8910 8006BC70 C0100200 */  sll        $v0, $v0, 3
    /* 8914 8006BC74 23105300 */  subu       $v0, $v0, $s3
    /* 8918 8006BC78 80100200 */  sll        $v0, $v0, 2
    /* 891C 8006BC7C 21105200 */  addu       $v0, $v0, $s2
    /* 8920 8006BC80 36004394 */  lhu        $v1, 0x36($v0)
    /* 8924 8006BC84 00000000 */  nop
    /* 8928 8006BC88 001C0300 */  sll        $v1, $v1, 16
    /* 892C 8006BC8C 03240300 */  sra        $a0, $v1, 16
    /* 8930 8006BC90 C21F0300 */  srl        $v1, $v1, 31
    /* 8934 8006BC94 21208300 */  addu       $a0, $a0, $v1
    /* 8938 8006BC98 43200400 */  sra        $a0, $a0, 1
    /* 893C 8006BC9C 360044A4 */  sh         $a0, 0x36($v0)
  .L8006BCA0:
    /* 8940 8006BCA0 21880000 */  addu       $s1, $zero, $zero
    /* 8944 8006BCA4 FFFF0724 */  addiu      $a3, $zero, -0x1
    /* 8948 8006BCA8 5000A627 */  addiu      $a2, $sp, 0x50
    /* 894C 8006BCAC 4000A527 */  addiu      $a1, $sp, 0x40
    /* 8950 8006BCB0 1800A427 */  addiu      $a0, $sp, 0x18
    /* 8954 8006BCB4 2800A327 */  addiu      $v1, $sp, 0x28
  .L8006BCB8:
    /* 8958 8006BCB8 000060AC */  sw         $zero, 0x0($v1)
    /* 895C 8006BCBC 000087A4 */  sh         $a3, 0x0($a0)
    /* 8960 8006BCC0 02008424 */  addiu      $a0, $a0, 0x2
    /* 8964 8006BCC4 04006324 */  addiu      $v1, $v1, 0x4
    /* 8968 8006BCC8 0800C297 */  lhu        $v0, 0x8($fp)
    /* 896C 8006BCCC 01003126 */  addiu      $s1, $s1, 0x1
    /* 8970 8006BCD0 0000A2A4 */  sh         $v0, 0x0($a1)
    /* 8974 8006BCD4 0000C0A4 */  sh         $zero, 0x0($a2)
    /* 8978 8006BCD8 0200C624 */  addiu      $a2, $a2, 0x2
    /* 897C 8006BCDC 0600222A */  slti       $v0, $s1, 0x6
    /* 8980 8006BCE0 F5FF4014 */  bnez       $v0, .L8006BCB8
    /* 8984 8006BCE4 0200A524 */   addiu     $a1, $a1, 0x2
    /* 8988 8006BCE8 0400C387 */  lh         $v1, 0x4($fp)
    /* 898C 8006BCEC 08000224 */  addiu      $v0, $zero, 0x8
    /* 8990 8006BCF0 61006210 */  beq        $v1, $v0, .L8006BE78
    /* 8994 8006BCF4 21A00000 */   addu      $s4, $zero, $zero
    /* 8998 8006BCF8 09006228 */  slti       $v0, $v1, 0x9
    /* 899C 8006BCFC 05004010 */  beqz       $v0, .L8006BD14
    /* 89A0 8006BD00 07000224 */   addiu     $v0, $zero, 0x7
    /* 89A4 8006BD04 2C006210 */  beq        $v1, $v0, .L8006BDB8
    /* 89A8 8006BD08 00141600 */   sll       $v0, $s6, 16
    /* 89AC 8006BD0C 49AF0108 */  j          .L8006BD24
    /* 89B0 8006BD10 038C0200 */   sra       $s1, $v0, 16
  .L8006BD14:
    /* 89B4 8006BD14 09000224 */  addiu      $v0, $zero, 0x9
    /* 89B8 8006BD18 89006210 */  beq        $v1, $v0, .L8006BF40
    /* 89BC 8006BD1C 00141600 */   sll       $v0, $s6, 16
    /* 89C0 8006BD20 038C0200 */  sra        $s1, $v0, 16
  .L8006BD24:
    /* 89C4 8006BD24 117C000C */  jal        func_8001F044
    /* 89C8 8006BD28 21202002 */   addu      $a0, $s1, $zero
    /* 89CC 8006BD2C 08004230 */  andi       $v0, $v0, 0x8
    /* 89D0 8006BD30 07004010 */  beqz       $v0, .L8006BD50
    /* 89D4 8006BD34 00000000 */   nop
    /* 89D8 8006BD38 0400C287 */  lh         $v0, 0x4($fp)
    /* 89DC 8006BD3C 0400C397 */  lhu        $v1, 0x4($fp)
    /* 89E0 8006BD40 AE006212 */  beq        $s3, $v0, .L8006BFFC
    /* 89E4 8006BD44 00000000 */   nop
    /* 89E8 8006BD48 6CAF0108 */  j          .L8006BDB0
    /* 89EC 8006BD4C 1800A3A7 */   sh        $v1, 0x18($sp)
  .L8006BD50:
    /* 89F0 8006BD50 257C000C */  jal        Skill_GetCureFlags
    /* 89F4 8006BD54 21202002 */   addu      $a0, $s1, $zero
    /* 89F8 8006BD58 0200033C */  lui        $v1, (0x20000 >> 16)
    /* 89FC 8006BD5C 24104300 */  and        $v0, $v0, $v1
    /* 8A00 8006BD60 05004010 */  beqz       $v0, .L8006BD78
    /* 8A04 8006BD64 00000000 */   nop
    /* 8A08 8006BD68 0400C297 */  lhu        $v0, 0x4($fp)
    /* 8A0C 8006BD6C 01001424 */  addiu      $s4, $zero, 0x1
    /* 8A10 8006BD70 FFAF0108 */  j          .L8006BFFC
    /* 8A14 8006BD74 1800A2A7 */   sh        $v0, 0x18($sp)
  .L8006BD78:
    /* 8A18 8006BD78 0780043C */  lui        $a0, %hi(Stg30_Battle)
    /* 8A1C 8006BD7C 0400C387 */  lh         $v1, 0x4($fp)
    /* 8A20 8006BD80 C03C8424 */  addiu      $a0, $a0, %lo(Stg30_Battle)
    /* 8A24 8006BD84 40100300 */  sll        $v0, $v1, 1
    /* 8A28 8006BD88 21104300 */  addu       $v0, $v0, $v1
    /* 8A2C 8006BD8C C0100200 */  sll        $v0, $v0, 3
    /* 8A30 8006BD90 23104300 */  subu       $v0, $v0, $v1
    /* 8A34 8006BD94 80100200 */  sll        $v0, $v0, 2
    /* 8A38 8006BD98 21104400 */  addu       $v0, $v0, $a0
    /* 8A3C 8006BD9C 2E004284 */  lh         $v0, 0x2E($v0)
    /* 8A40 8006BDA0 0400C397 */  lhu        $v1, 0x4($fp)
    /* 8A44 8006BDA4 95004010 */  beqz       $v0, .L8006BFFC
    /* 8A48 8006BDA8 00000000 */   nop
    /* 8A4C 8006BDAC 1800A3A7 */  sh         $v1, 0x18($sp)
  .L8006BDB0:
    /* 8A50 8006BDB0 FFAF0108 */  j          .L8006BFFC
    /* 8A54 8006BDB4 01001424 */   addiu     $s4, $zero, 0x1
  .L8006BDB8:
    /* 8A58 8006BDB8 4000A387 */  lh         $v1, 0x40($sp)
    /* 8A5C 8006BDBC 00000000 */  nop
    /* 8A60 8006BDC0 06006004 */  bltz       $v1, .L8006BDDC
    /* 8A64 8006BDC4 03006228 */   slti      $v0, $v1, 0x3
    /* 8A68 8006BDC8 05004014 */  bnez       $v0, .L8006BDE0
    /* 8A6C 8006BDCC 21880000 */   addu      $s1, $zero, $zero
    /* 8A70 8006BDD0 03000224 */  addiu      $v0, $zero, 0x3
    /* 8A74 8006BDD4 13006210 */  beq        $v1, $v0, .L8006BE24
    /* 8A78 8006BDD8 21302002 */   addu      $a2, $s1, $zero
  .L8006BDDC:
    /* 8A7C 8006BDDC 21880000 */  addu       $s1, $zero, $zero
  .L8006BDE0:
    /* 8A80 8006BDE0 21302002 */  addu       $a2, $s1, $zero
    /* 8A84 8006BDE4 0780023C */  lui        $v0, %hi(Stg30_Battle)
    /* 8A88 8006BDE8 C03C4424 */  addiu      $a0, $v0, %lo(Stg30_Battle)
    /* 8A8C 8006BDEC 1800A327 */  addiu      $v1, $sp, 0x18
  .L8006BDF0:
    /* 8A90 8006BDF0 2E008284 */  lh         $v0, 0x2E($a0)
    /* 8A94 8006BDF4 00000000 */  nop
    /* 8A98 8006BDF8 04004010 */  beqz       $v0, .L8006BE0C
    /* 8A9C 8006BDFC 00000000 */   nop
    /* 8AA0 8006BE00 000071A4 */  sh         $s1, 0x0($v1)
    /* 8AA4 8006BE04 02006324 */  addiu      $v1, $v1, 0x2
    /* 8AA8 8006BE08 0100C624 */  addiu      $a2, $a2, 0x1
  .L8006BE0C:
    /* 8AAC 8006BE0C 01003126 */  addiu      $s1, $s1, 0x1
    /* 8AB0 8006BE10 0300222A */  slti       $v0, $s1, 0x3
    /* 8AB4 8006BE14 F6FF4014 */  bnez       $v0, .L8006BDF0
    /* 8AB8 8006BE18 5C008424 */   addiu     $a0, $a0, 0x5C
    /* 8ABC 8006BE1C 9CAF0108 */  j          .L8006BE70
    /* 8AC0 8006BE20 21A0C000 */   addu      $s4, $a2, $zero
  .L8006BE24:
    /* 8AC4 8006BE24 0780023C */  lui        $v0, %hi(Stg30_Battle)
    /* 8AC8 8006BE28 C03C4324 */  addiu      $v1, $v0, %lo(Stg30_Battle)
    /* 8ACC 8006BE2C 1800A427 */  addiu      $a0, $sp, 0x18
  .L8006BE30:
    /* 8AD0 8006BE30 19006290 */  lbu        $v0, 0x19($v1)
    /* 8AD4 8006BE34 00000000 */  nop
    /* 8AD8 8006BE38 08004010 */  beqz       $v0, .L8006BE5C
    /* 8ADC 8006BE3C 00000000 */   nop
    /* 8AE0 8006BE40 2E006284 */  lh         $v0, 0x2E($v1)
    /* 8AE4 8006BE44 00000000 */  nop
    /* 8AE8 8006BE48 04004014 */  bnez       $v0, .L8006BE5C
    /* 8AEC 8006BE4C 00000000 */   nop
    /* 8AF0 8006BE50 000091A4 */  sh         $s1, 0x0($a0)
    /* 8AF4 8006BE54 02008424 */  addiu      $a0, $a0, 0x2
    /* 8AF8 8006BE58 0100C624 */  addiu      $a2, $a2, 0x1
  .L8006BE5C:
    /* 8AFC 8006BE5C 01003126 */  addiu      $s1, $s1, 0x1
    /* 8B00 8006BE60 0300222A */  slti       $v0, $s1, 0x3
    /* 8B04 8006BE64 F2FF4014 */  bnez       $v0, .L8006BE30
    /* 8B08 8006BE68 5C006324 */   addiu     $v1, $v1, 0x5C
    /* 8B0C 8006BE6C 21A0C000 */  addu       $s4, $a2, $zero
  .L8006BE70:
    /* 8B10 8006BE70 FFAF0108 */  j          .L8006BFFC
    /* 8B14 8006BE74 21B80000 */   addu      $s7, $zero, $zero
  .L8006BE78:
    /* 8B18 8006BE78 4000A387 */  lh         $v1, 0x40($sp)
    /* 8B1C 8006BE7C 00000000 */  nop
    /* 8B20 8006BE80 06006004 */  bltz       $v1, .L8006BE9C
    /* 8B24 8006BE84 03006228 */   slti      $v0, $v1, 0x3
    /* 8B28 8006BE88 05004014 */  bnez       $v0, .L8006BEA0
    /* 8B2C 8006BE8C 21300000 */   addu      $a2, $zero, $zero
    /* 8B30 8006BE90 03000224 */  addiu      $v0, $zero, 0x3
    /* 8B34 8006BE94 14006210 */  beq        $v1, $v0, .L8006BEE8
    /* 8B38 8006BE98 03001124 */   addiu     $s1, $zero, 0x3
  .L8006BE9C:
    /* 8B3C 8006BE9C 21300000 */  addu       $a2, $zero, $zero
  .L8006BEA0:
    /* 8B40 8006BEA0 03001124 */  addiu      $s1, $zero, 0x3
    /* 8B44 8006BEA4 0780023C */  lui        $v0, %hi(Stg30_Battle)
    /* 8B48 8006BEA8 C03C4224 */  addiu      $v0, $v0, %lo(Stg30_Battle)
    /* 8B4C 8006BEAC 14014424 */  addiu      $a0, $v0, 0x114
    /* 8B50 8006BEB0 1800A327 */  addiu      $v1, $sp, 0x18
  .L8006BEB4:
    /* 8B54 8006BEB4 2E008284 */  lh         $v0, 0x2E($a0)
    /* 8B58 8006BEB8 00000000 */  nop
    /* 8B5C 8006BEBC 04004010 */  beqz       $v0, .L8006BED0
    /* 8B60 8006BEC0 00000000 */   nop
    /* 8B64 8006BEC4 000071A4 */  sh         $s1, 0x0($v1)
    /* 8B68 8006BEC8 02006324 */  addiu      $v1, $v1, 0x2
    /* 8B6C 8006BECC 0100C624 */  addiu      $a2, $a2, 0x1
  .L8006BED0:
    /* 8B70 8006BED0 01003126 */  addiu      $s1, $s1, 0x1
    /* 8B74 8006BED4 0600222A */  slti       $v0, $s1, 0x6
    /* 8B78 8006BED8 F6FF4014 */  bnez       $v0, .L8006BEB4
    /* 8B7C 8006BEDC 5C008424 */   addiu     $a0, $a0, 0x5C
    /* 8B80 8006BEE0 CEAF0108 */  j          .L8006BF38
    /* 8B84 8006BEE4 21A0C000 */   addu      $s4, $a2, $zero
  .L8006BEE8:
    /* 8B88 8006BEE8 0780023C */  lui        $v0, %hi(Stg30_Battle)
    /* 8B8C 8006BEEC C03C4224 */  addiu      $v0, $v0, %lo(Stg30_Battle)
    /* 8B90 8006BEF0 14014324 */  addiu      $v1, $v0, 0x114
    /* 8B94 8006BEF4 1800A427 */  addiu      $a0, $sp, 0x18
  .L8006BEF8:
    /* 8B98 8006BEF8 19006290 */  lbu        $v0, 0x19($v1)
    /* 8B9C 8006BEFC 00000000 */  nop
    /* 8BA0 8006BF00 08004010 */  beqz       $v0, .L8006BF24
    /* 8BA4 8006BF04 00000000 */   nop
    /* 8BA8 8006BF08 2E006284 */  lh         $v0, 0x2E($v1)
    /* 8BAC 8006BF0C 00000000 */  nop
    /* 8BB0 8006BF10 04004014 */  bnez       $v0, .L8006BF24
    /* 8BB4 8006BF14 00000000 */   nop
    /* 8BB8 8006BF18 000091A4 */  sh         $s1, 0x0($a0)
    /* 8BBC 8006BF1C 02008424 */  addiu      $a0, $a0, 0x2
    /* 8BC0 8006BF20 0100C624 */  addiu      $a2, $a2, 0x1
  .L8006BF24:
    /* 8BC4 8006BF24 01003126 */  addiu      $s1, $s1, 0x1
    /* 8BC8 8006BF28 0600222A */  slti       $v0, $s1, 0x6
    /* 8BCC 8006BF2C F2FF4014 */  bnez       $v0, .L8006BEF8
    /* 8BD0 8006BF30 5C006324 */   addiu     $v1, $v1, 0x5C
    /* 8BD4 8006BF34 21A0C000 */  addu       $s4, $a2, $zero
  .L8006BF38:
    /* 8BD8 8006BF38 FFAF0108 */  j          .L8006BFFC
    /* 8BDC 8006BF3C 01001724 */   addiu     $s7, $zero, 0x1
  .L8006BF40:
    /* 8BE0 8006BF40 4000A387 */  lh         $v1, 0x40($sp)
    /* 8BE4 8006BF44 00000000 */  nop
    /* 8BE8 8006BF48 06006004 */  bltz       $v1, .L8006BF64
    /* 8BEC 8006BF4C 03006228 */   slti      $v0, $v1, 0x3
    /* 8BF0 8006BF50 05004014 */  bnez       $v0, .L8006BF68
    /* 8BF4 8006BF54 21300000 */   addu      $a2, $zero, $zero
    /* 8BF8 8006BF58 03000224 */  addiu      $v0, $zero, 0x3
    /* 8BFC 8006BF5C 13006210 */  beq        $v1, $v0, .L8006BFAC
    /* 8C00 8006BF60 2188C000 */   addu      $s1, $a2, $zero
  .L8006BF64:
    /* 8C04 8006BF64 21300000 */  addu       $a2, $zero, $zero
  .L8006BF68:
    /* 8C08 8006BF68 2188C000 */  addu       $s1, $a2, $zero
    /* 8C0C 8006BF6C 0780023C */  lui        $v0, %hi(Stg30_Battle)
    /* 8C10 8006BF70 C03C4424 */  addiu      $a0, $v0, %lo(Stg30_Battle)
    /* 8C14 8006BF74 1800A327 */  addiu      $v1, $sp, 0x18
  .L8006BF78:
    /* 8C18 8006BF78 2E008284 */  lh         $v0, 0x2E($a0)
    /* 8C1C 8006BF7C 00000000 */  nop
    /* 8C20 8006BF80 04004010 */  beqz       $v0, .L8006BF94
    /* 8C24 8006BF84 00000000 */   nop
    /* 8C28 8006BF88 000071A4 */  sh         $s1, 0x0($v1)
    /* 8C2C 8006BF8C 02006324 */  addiu      $v1, $v1, 0x2
    /* 8C30 8006BF90 0100C624 */  addiu      $a2, $a2, 0x1
  .L8006BF94:
    /* 8C34 8006BF94 01003126 */  addiu      $s1, $s1, 0x1
    /* 8C38 8006BF98 0600222A */  slti       $v0, $s1, 0x6
    /* 8C3C 8006BF9C F6FF4014 */  bnez       $v0, .L8006BF78
    /* 8C40 8006BFA0 5C008424 */   addiu     $a0, $a0, 0x5C
    /* 8C44 8006BFA4 FEAF0108 */  j          .L8006BFF8
    /* 8C48 8006BFA8 21A0C000 */   addu      $s4, $a2, $zero
  .L8006BFAC:
    /* 8C4C 8006BFAC 0780023C */  lui        $v0, %hi(Stg30_Battle)
    /* 8C50 8006BFB0 C03C4324 */  addiu      $v1, $v0, %lo(Stg30_Battle)
    /* 8C54 8006BFB4 1800A427 */  addiu      $a0, $sp, 0x18
  .L8006BFB8:
    /* 8C58 8006BFB8 19006290 */  lbu        $v0, 0x19($v1)
    /* 8C5C 8006BFBC 00000000 */  nop
    /* 8C60 8006BFC0 08004010 */  beqz       $v0, .L8006BFE4
    /* 8C64 8006BFC4 00000000 */   nop
    /* 8C68 8006BFC8 2E006284 */  lh         $v0, 0x2E($v1)
    /* 8C6C 8006BFCC 00000000 */  nop
    /* 8C70 8006BFD0 04004014 */  bnez       $v0, .L8006BFE4
    /* 8C74 8006BFD4 00000000 */   nop
    /* 8C78 8006BFD8 000091A4 */  sh         $s1, 0x0($a0)
    /* 8C7C 8006BFDC 02008424 */  addiu      $a0, $a0, 0x2
    /* 8C80 8006BFE0 0100C624 */  addiu      $a2, $a2, 0x1
  .L8006BFE4:
    /* 8C84 8006BFE4 01003126 */  addiu      $s1, $s1, 0x1
    /* 8C88 8006BFE8 0600222A */  slti       $v0, $s1, 0x6
    /* 8C8C 8006BFEC F2FF4014 */  bnez       $v0, .L8006BFB8
    /* 8C90 8006BFF0 5C006324 */   addiu     $v1, $v1, 0x5C
    /* 8C94 8006BFF4 21A0C000 */  addu       $s4, $a2, $zero
  .L8006BFF8:
    /* 8C98 8006BFF8 02001724 */  addiu      $s7, $zero, 0x2
  .L8006BFFC:
    /* 8C9C 8006BFFC 0E008012 */  beqz       $s4, .L8006C038
    /* 8CA0 8006C000 0780023C */   lui       $v0, %hi(D_80074074)
    /* 8CA4 8006C004 0800C287 */  lh         $v0, 0x8($fp)
    /* 8CA8 8006C008 00000000 */  nop
    /* 8CAC 8006C00C 0C004014 */  bnez       $v0, .L8006C040
    /* 8CB0 8006C010 0780023C */   lui       $v0, %hi(Stg30_Battle)
    /* 8CB4 8006C014 21206002 */  addu       $a0, $s3, $zero
    /* 8CB8 8006C018 1800A527 */  addiu      $a1, $sp, 0x18
    /* 8CBC 8006C01C 21308002 */  addu       $a2, $s4, $zero
    /* 8CC0 8006C020 003C1600 */  sll        $a3, $s6, 16
    /* 8CC4 8006C024 54AE010C */  jal        Stg30_SkillHitCheck
    /* 8CC8 8006C028 033C0700 */   sra       $a3, $a3, 16
    /* 8CCC 8006C02C 04004014 */  bnez       $v0, .L8006C040
    /* 8CD0 8006C030 0780023C */   lui       $v0, %hi(Stg30_Battle)
    /* 8CD4 8006C034 0780023C */  lui        $v0, %hi(D_80074074)
  .L8006C038:
    /* 8CD8 8006C038 744040A4 */  sh         $zero, %lo(D_80074074)($v0)
    /* 8CDC 8006C03C 0780023C */  lui        $v0, %hi(Stg30_Battle)
  .L8006C040:
    /* 8CE0 8006C040 C03C5224 */  addiu      $s2, $v0, %lo(Stg30_Battle)
    /* 8CE4 8006C044 B4034286 */  lh         $v0, 0x3B4($s2)
    /* 8CE8 8006C048 00000000 */  nop
    /* 8CEC 8006C04C 95014010 */  beqz       $v0, .L8006C6A4
    /* 8CF0 8006C050 03000224 */   addiu     $v0, $zero, 0x3
    /* 8CF4 8006C054 0000C38F */  lw         $v1, 0x0($fp)
    /* 8CF8 8006C058 00000000 */  nop
    /* 8CFC 8006C05C 70006214 */  bne        $v1, $v0, .L8006C220
    /* 8D00 8006C060 00141600 */   sll       $v0, $s6, 16
    /* 8D04 8006C064 00241600 */  sll        $a0, $s6, 16
    /* 8D08 8006C068 607C000C */  jal        func_8001F180
    /* 8D0C 8006C06C 03240400 */   sra       $a0, $a0, 16
    /* 8D10 8006C070 21884000 */  addu       $s1, $v0, $zero
    /* 8D14 8006C074 01002232 */  andi       $v0, $s1, 0x1
    /* 8D18 8006C078 0F004010 */  beqz       $v0, .L8006C0B8
    /* 8D1C 8006C07C 04002232 */   andi      $v0, $s1, 0x4
    /* 8D20 8006C080 DC03428E */  lw         $v0, 0x3DC($s2)
    /* 8D24 8006C084 00000000 */  nop
    /* 8D28 8006C088 03004010 */  beqz       $v0, .L8006C098
    /* 8D2C 8006C08C 0300622A */   slti      $v0, $s3, 0x3
    /* 8D30 8006C090 09004014 */  bnez       $v0, .L8006C0B8
    /* 8D34 8006C094 04002232 */   andi      $v0, $s1, 0x4
  .L8006C098:
    /* 8D38 8006C098 448E000C */  jal        Rand_Next
    /* 8D3C 8006C09C 00000000 */   nop
    /* 8D40 8006C0A0 07004230 */  andi       $v0, $v0, 0x7
    /* 8D44 8006C0A4 04004010 */  beqz       $v0, .L8006C0B8
    /* 8D48 8006C0A8 04002232 */   andi      $v0, $s1, 0x4
    /* 8D4C 8006C0AC 6DB9010C */  jal        Stg30_TurnOrderRemove
    /* 8D50 8006C0B0 01000424 */   addiu     $a0, $zero, 0x1
    /* 8D54 8006C0B4 04002232 */  andi       $v0, $s1, 0x4
  .L8006C0B8:
    /* 8D58 8006C0B8 1D004010 */  beqz       $v0, .L8006C130
    /* 8D5C 8006C0BC 08002232 */   andi      $v0, $s1, 0x8
    /* 8D60 8006C0C0 9DB9010C */  jal        Stg30_TurnOrderGet
    /* 8D64 8006C0C4 01000424 */   addiu     $a0, $zero, 0x1
    /* 8D68 8006C0C8 21204000 */  addu       $a0, $v0, $zero
    /* 8D6C 8006C0CC FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 8D70 8006C0D0 16008210 */  beq        $a0, $v0, .L8006C12C
    /* 8D74 8006C0D4 0780033C */   lui       $v1, %hi(Stg30_Battle)
    /* 8D78 8006C0D8 C03C6324 */  addiu      $v1, $v1, %lo(Stg30_Battle)
    /* 8D7C 8006C0DC 40100400 */  sll        $v0, $a0, 1
    /* 8D80 8006C0E0 21104400 */  addu       $v0, $v0, $a0
    /* 8D84 8006C0E4 C0100200 */  sll        $v0, $v0, 3
    /* 8D88 8006C0E8 23104400 */  subu       $v0, $v0, $a0
    /* 8D8C 8006C0EC 80100200 */  sll        $v0, $v0, 2
    /* 8D90 8006C0F0 21204300 */  addu       $a0, $v0, $v1
    /* 8D94 8006C0F4 34008384 */  lh         $v1, 0x34($a0)
    /* 8D98 8006C0F8 00000000 */  nop
    /* 8D9C 8006C0FC 80100300 */  sll        $v0, $v1, 2
    /* 8DA0 8006C100 21104300 */  addu       $v0, $v0, $v1
    /* 8DA4 8006C104 80100200 */  sll        $v0, $v0, 2
    /* 8DA8 8006C108 23104300 */  subu       $v0, $v0, $v1
    /* 8DAC 8006C10C 40100200 */  sll        $v0, $v0, 1
    /* 8DB0 8006C110 02004104 */  bgez       $v0, .L8006C11C
    /* 8DB4 8006C114 00000000 */   nop
    /* 8DB8 8006C118 7F004224 */  addiu      $v0, $v0, 0x7F
  .L8006C11C:
    /* 8DBC 8006C11C C3110200 */  sra        $v0, $v0, 7
    /* 8DC0 8006C120 340082A4 */  sh         $v0, 0x34($a0)
    /* 8DC4 8006C124 11010224 */  addiu      $v0, $zero, 0x111
    /* 8DC8 8006C128 5000A2A7 */  sh         $v0, 0x50($sp)
  .L8006C12C:
    /* 8DCC 8006C12C 08002232 */  andi       $v0, $s1, 0x8
  .L8006C130:
    /* 8DD0 8006C130 1E004010 */  beqz       $v0, .L8006C1AC
    /* 8DD4 8006C134 10002232 */   andi      $v0, $s1, 0x10
    /* 8DD8 8006C138 9DB9010C */  jal        Stg30_TurnOrderGet
    /* 8DDC 8006C13C 01000424 */   addiu     $a0, $zero, 0x1
    /* 8DE0 8006C140 21204000 */  addu       $a0, $v0, $zero
    /* 8DE4 8006C144 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 8DE8 8006C148 17008210 */  beq        $a0, $v0, .L8006C1A8
    /* 8DEC 8006C14C 0780033C */   lui       $v1, %hi(Stg30_Battle)
    /* 8DF0 8006C150 C03C6324 */  addiu      $v1, $v1, %lo(Stg30_Battle)
    /* 8DF4 8006C154 40100400 */  sll        $v0, $a0, 1
    /* 8DF8 8006C158 21104400 */  addu       $v0, $v0, $a0
    /* 8DFC 8006C15C C0100200 */  sll        $v0, $v0, 3
    /* 8E00 8006C160 23104400 */  subu       $v0, $v0, $a0
    /* 8E04 8006C164 80100200 */  sll        $v0, $v0, 2
    /* 8E08 8006C168 21204300 */  addu       $a0, $v0, $v1
    /* 8E0C 8006C16C 34008384 */  lh         $v1, 0x34($a0)
    /* 8E10 8006C170 00000000 */  nop
    /* 8E14 8006C174 80100300 */  sll        $v0, $v1, 2
    /* 8E18 8006C178 21104300 */  addu       $v0, $v0, $v1
    /* 8E1C 8006C17C 80100200 */  sll        $v0, $v0, 2
    /* 8E20 8006C180 23104300 */  subu       $v0, $v0, $v1
    /* 8E24 8006C184 80100200 */  sll        $v0, $v0, 2
    /* 8E28 8006C188 21104300 */  addu       $v0, $v0, $v1
    /* 8E2C 8006C18C 02004104 */  bgez       $v0, .L8006C198
    /* 8E30 8006C190 00000000 */   nop
    /* 8E34 8006C194 7F004224 */  addiu      $v0, $v0, 0x7F
  .L8006C198:
    /* 8E38 8006C198 C3110200 */  sra        $v0, $v0, 7
    /* 8E3C 8006C19C 340082A4 */  sh         $v0, 0x34($a0)
    /* 8E40 8006C1A0 11010224 */  addiu      $v0, $zero, 0x111
    /* 8E44 8006C1A4 5000A2A7 */  sh         $v0, 0x50($sp)
  .L8006C1A8:
    /* 8E48 8006C1A8 10002232 */  andi       $v0, $s1, 0x10
  .L8006C1AC:
    /* 8E4C 8006C1AC 0C004010 */  beqz       $v0, .L8006C1E0
    /* 8E50 8006C1B0 40002232 */   andi      $v0, $s1, 0x40
    /* 8E54 8006C1B4 9DB9010C */  jal        Stg30_TurnOrderGet
    /* 8E58 8006C1B8 01000424 */   addiu     $a0, $zero, 0x1
    /* 8E5C 8006C1BC 21184000 */  addu       $v1, $v0, $zero
    /* 8E60 8006C1C0 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 8E64 8006C1C4 05006210 */  beq        $v1, $v0, .L8006C1DC
    /* 8E68 8006C1C8 0780023C */   lui       $v0, %hi(Stg30_Battle)
    /* 8E6C 8006C1CC C03C4224 */  addiu      $v0, $v0, %lo(Stg30_Battle)
    /* 8E70 8006C1D0 21106200 */  addu       $v0, $v1, $v0
    /* 8E74 8006C1D4 10000324 */  addiu      $v1, $zero, 0x10
    /* 8E78 8006C1D8 4F0343A0 */  sb         $v1, 0x34F($v0)
  .L8006C1DC:
    /* 8E7C 8006C1DC 40002232 */  andi       $v0, $s1, 0x40
  .L8006C1E0:
    /* 8E80 8006C1E0 0F004010 */  beqz       $v0, .L8006C220
    /* 8E84 8006C1E4 00141600 */   sll       $v0, $s6, 16
    /* 8E88 8006C1E8 9DB9010C */  jal        Stg30_TurnOrderGet
    /* 8E8C 8006C1EC 01000424 */   addiu     $a0, $zero, 0x1
    /* 8E90 8006C1F0 21884000 */  addu       $s1, $v0, $zero
    /* 8E94 8006C1F4 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 8E98 8006C1F8 09002212 */  beq        $s1, $v0, .L8006C220
    /* 8E9C 8006C1FC 00141600 */   sll       $v0, $s6, 16
    /* 8EA0 8006C200 6DB9010C */  jal        Stg30_TurnOrderRemove
    /* 8EA4 8006C204 01000424 */   addiu     $a0, $zero, 0x1
    /* 8EA8 8006C208 8DB9010C */  jal        Stg30_TurnOrderFreeIndex
    /* 8EAC 8006C20C 00000000 */   nop
    /* 8EB0 8006C210 21204000 */  addu       $a0, $v0, $zero
    /* 8EB4 8006C214 57B9010C */  jal        Stg30_TurnOrderInsert
    /* 8EB8 8006C218 21282002 */   addu      $a1, $s1, $zero
    /* 8EBC 8006C21C 00141600 */  sll        $v0, $s6, 16
  .L8006C220:
    /* 8EC0 8006C220 031C0200 */  sra        $v1, $v0, 16
    /* 8EC4 8006C224 F1000224 */  addiu      $v0, $zero, 0xF1
    /* 8EC8 8006C228 03006210 */  beq        $v1, $v0, .L8006C238
    /* 8ECC 8006C22C F4000224 */   addiu     $v0, $zero, 0xF4
    /* 8ED0 8006C230 04006214 */  bne        $v1, $v0, .L8006C244
    /* 8ED4 8006C234 DD000224 */   addiu     $v0, $zero, 0xDD
  .L8006C238:
    /* 8ED8 8006C238 0780033C */  lui        $v1, %hi(D_80074070)
    /* 8EDC 8006C23C 94B00108 */  j          .L8006C250
    /* 8EE0 8006C240 1E010224 */   addiu     $v0, $zero, 0x11E
  .L8006C244:
    /* 8EE4 8006C244 03006214 */  bne        $v1, $v0, .L8006C254
    /* 8EE8 8006C248 0780033C */   lui       $v1, %hi(D_80074070)
    /* 8EEC 8006C24C 02020224 */  addiu      $v0, $zero, 0x202
  .L8006C250:
    /* 8EF0 8006C250 704062A4 */  sh         $v0, %lo(D_80074070)($v1)
  .L8006C254:
    /* 8EF4 8006C254 1500801A */  blez       $s4, .L8006C2AC
    /* 8EF8 8006C258 21880000 */   addu      $s1, $zero, $zero
    /* 8EFC 8006C25C 00AC1600 */  sll        $s5, $s6, 16
    /* 8F00 8006C260 1800B227 */  addiu      $s2, $sp, 0x18
    /* 8F04 8006C264 21206002 */  addu       $a0, $s3, $zero
  .L8006C268:
    /* 8F08 8006C268 03341500 */  sra        $a2, $s5, 16
    /* 8F0C 8006C26C 40181100 */  sll        $v1, $s1, 1
    /* 8F10 8006C270 4000A727 */  addiu      $a3, $sp, 0x40
    /* 8F14 8006C274 2138E300 */  addu       $a3, $a3, $v1
    /* 8F18 8006C278 00004586 */  lh         $a1, 0x0($s2)
    /* 8F1C 8006C27C 02005226 */  addiu      $s2, $s2, 0x2
    /* 8F20 8006C280 5000A227 */  addiu      $v0, $sp, 0x50
    /* 8F24 8006C284 21104300 */  addu       $v0, $v0, $v1
    /* 8F28 8006C288 AAAA010C */  jal        Stg30_ApplySkillDamage
    /* 8F2C 8006C28C 1000A2AF */   sw        $v0, 0x10($sp)
    /* 8F30 8006C290 80181100 */  sll        $v1, $s1, 2
    /* 8F34 8006C294 01003126 */  addiu      $s1, $s1, 0x1
    /* 8F38 8006C298 2118A303 */  addu       $v1, $sp, $v1
    /* 8F3C 8006C29C 280062AC */  sw         $v0, 0x28($v1)
    /* 8F40 8006C2A0 2A103402 */  slt        $v0, $s1, $s4
    /* 8F44 8006C2A4 F0FF4014 */  bnez       $v0, .L8006C268
    /* 8F48 8006C2A8 21206002 */   addu      $a0, $s3, $zero
  .L8006C2AC:
    /* 8F4C 8006C2AC 02000224 */  addiu      $v0, $zero, 0x2
    /* 8F50 8006C2B0 000002A6 */  sh         $v0, 0x0($s0)
    /* 8F54 8006C2B4 02001026 */  addiu      $s0, $s0, 0x2
    /* 8F58 8006C2B8 0A006226 */  addiu      $v0, $s3, 0xA
    /* 8F5C 8006C2BC 000002A6 */  sh         $v0, 0x0($s0)
    /* 8F60 8006C2C0 02001026 */  addiu      $s0, $s0, 0x2
    /* 8F64 8006C2C4 03000224 */  addiu      $v0, $zero, 0x3
    /* 8F68 8006C2C8 000002A6 */  sh         $v0, 0x0($s0)
    /* 8F6C 8006C2CC 02001026 */  addiu      $s0, $s0, 0x2
    /* 8F70 8006C2D0 000013A6 */  sh         $s3, 0x0($s0)
    /* 8F74 8006C2D4 02001026 */  addiu      $s0, $s0, 0x2
    /* 8F78 8006C2D8 15000224 */  addiu      $v0, $zero, 0x15
    /* 8F7C 8006C2DC 000002A6 */  sh         $v0, 0x0($s0)
    /* 8F80 8006C2E0 02001026 */  addiu      $s0, $s0, 0x2
    /* 8F84 8006C2E4 0E000224 */  addiu      $v0, $zero, 0xE
    /* 8F88 8006C2E8 000002A6 */  sh         $v0, 0x0($s0)
    /* 8F8C 8006C2EC 0780023C */  lui        $v0, %hi(Stg30_Battle)
    /* 8F90 8006C2F0 C03C4424 */  addiu      $a0, $v0, %lo(Stg30_Battle)
    /* 8F94 8006C2F4 00191300 */  sll        $v1, $s3, 4
    /* 8F98 8006C2F8 21186400 */  addu       $v1, $v1, $a0
    /* 8F9C 8006C2FC AC026294 */  lhu        $v0, 0x2AC($v1)
    /* 8FA0 8006C300 02001026 */  addiu      $s0, $s0, 0x2
    /* 8FA4 8006C304 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 8FA8 8006C308 000002A6 */  sh         $v0, 0x0($s0)
    /* 8FAC 8006C30C 02001026 */  addiu      $s0, $s0, 0x2
    /* 8FB0 8006C310 01000224 */  addiu      $v0, $zero, 0x1
    /* 8FB4 8006C314 000002A6 */  sh         $v0, 0x0($s0)
    /* 8FB8 8006C318 BB026290 */  lbu        $v0, 0x2BB($v1)
    /* 8FBC 8006C31C 00000000 */  nop
    /* 8FC0 8006C320 32004014 */  bnez       $v0, .L8006C3EC
    /* 8FC4 8006C324 02001026 */   addiu     $s0, $s0, 0x2
    /* 8FC8 8006C328 D003838C */  lw         $v1, 0x3D0($a0)
    /* 8FCC 8006C32C FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 8FD0 8006C330 2F006214 */  bne        $v1, $v0, .L8006C3F0
    /* 8FD4 8006C334 16000224 */   addiu     $v0, $zero, 0x16
    /* 8FD8 8006C338 0000C38F */  lw         $v1, 0x0($fp)
    /* 8FDC 8006C33C 02000224 */  addiu      $v0, $zero, 0x2
    /* 8FE0 8006C340 2A006210 */  beq        $v1, $v0, .L8006C3EC
    /* 8FE4 8006C344 0300622A */   slti      $v0, $s3, 0x3
    /* 8FE8 8006C348 14004014 */  bnez       $v0, .L8006C39C
    /* 8FEC 8006C34C 03000324 */   addiu     $v1, $zero, 0x3
    /* 8FF0 8006C350 AC02828C */  lw         $v0, 0x2AC($a0)
    /* 8FF4 8006C354 00000000 */  nop
    /* 8FF8 8006C358 09004310 */  beq        $v0, $v1, .L8006C380
    /* 8FFC 8006C35C 00000000 */   nop
    /* 9000 8006C360 BC02828C */  lw         $v0, 0x2BC($a0)
    /* 9004 8006C364 00000000 */  nop
    /* 9008 8006C368 05004310 */  beq        $v0, $v1, .L8006C380
    /* 900C 8006C36C 00000000 */   nop
    /* 9010 8006C370 CC02828C */  lw         $v0, 0x2CC($a0)
    /* 9014 8006C374 00000000 */  nop
    /* 9018 8006C378 1C004314 */  bne        $v0, $v1, .L8006C3EC
    /* 901C 8006C37C 00000000 */   nop
  .L8006C380:
    /* 9020 8006C380 000000A6 */  sh         $zero, 0x0($s0)
    /* 9024 8006C384 02001026 */  addiu      $s0, $s0, 0x2
    /* 9028 8006C388 3C000224 */  addiu      $v0, $zero, 0x3C
    /* 902C 8006C38C 000002A6 */  sh         $v0, 0x0($s0)
    /* 9030 8006C390 02001026 */  addiu      $s0, $s0, 0x2
    /* 9034 8006C394 F9B00108 */  j          .L8006C3E4
    /* 9038 8006C398 13000224 */   addiu     $v0, $zero, 0x13
  .L8006C39C:
    /* 903C 8006C39C DC02828C */  lw         $v0, 0x2DC($a0)
    /* 9040 8006C3A0 00000000 */  nop
    /* 9044 8006C3A4 09004310 */  beq        $v0, $v1, .L8006C3CC
    /* 9048 8006C3A8 00000000 */   nop
    /* 904C 8006C3AC EC02828C */  lw         $v0, 0x2EC($a0)
    /* 9050 8006C3B0 00000000 */  nop
    /* 9054 8006C3B4 05004310 */  beq        $v0, $v1, .L8006C3CC
    /* 9058 8006C3B8 00000000 */   nop
    /* 905C 8006C3BC FC02828C */  lw         $v0, 0x2FC($a0)
    /* 9060 8006C3C0 00000000 */  nop
    /* 9064 8006C3C4 0A004314 */  bne        $v0, $v1, .L8006C3F0
    /* 9068 8006C3C8 16000224 */   addiu     $v0, $zero, 0x16
  .L8006C3CC:
    /* 906C 8006C3CC 000000A6 */  sh         $zero, 0x0($s0)
    /* 9070 8006C3D0 02001026 */  addiu      $s0, $s0, 0x2
    /* 9074 8006C3D4 3C000224 */  addiu      $v0, $zero, 0x3C
    /* 9078 8006C3D8 000002A6 */  sh         $v0, 0x0($s0)
    /* 907C 8006C3DC 02001026 */  addiu      $s0, $s0, 0x2
    /* 9080 8006C3E0 14000224 */  addiu      $v0, $zero, 0x14
  .L8006C3E4:
    /* 9084 8006C3E4 000002A6 */  sh         $v0, 0x0($s0)
    /* 9088 8006C3E8 02001026 */  addiu      $s0, $s0, 0x2
  .L8006C3EC:
    /* 908C 8006C3EC 16000224 */  addiu      $v0, $zero, 0x16
  .L8006C3F0:
    /* 9090 8006C3F0 000002A6 */  sh         $v0, 0x0($s0)
    /* 9094 8006C3F4 02001026 */  addiu      $s0, $s0, 0x2
    /* 9098 8006C3F8 0F000224 */  addiu      $v0, $zero, 0xF
    /* 909C 8006C3FC 000002A6 */  sh         $v0, 0x0($s0)
    /* 90A0 8006C400 02001026 */  addiu      $s0, $s0, 0x2
    /* 90A4 8006C404 000016A6 */  sh         $s6, 0x0($s0)
    /* 90A8 8006C408 02001026 */  addiu      $s0, $s0, 0x2
    /* 90AC 8006C40C 17000224 */  addiu      $v0, $zero, 0x17
    /* 90B0 8006C410 000002A6 */  sh         $v0, 0x0($s0)
    /* 90B4 8006C414 02001026 */  addiu      $s0, $s0, 0x2
    /* 90B8 8006C418 000016A6 */  sh         $s6, 0x0($s0)
    /* 90BC 8006C41C 02001026 */  addiu      $s0, $s0, 0x2
    /* 90C0 8006C420 000014A6 */  sh         $s4, 0x0($s0)
    /* 90C4 8006C424 02001026 */  addiu      $s0, $s0, 0x2
    /* 90C8 8006C428 09000224 */  addiu      $v0, $zero, 0x9
    /* 90CC 8006C42C 000002A6 */  sh         $v0, 0x0($s0)
    /* 90D0 8006C430 02001026 */  addiu      $s0, $s0, 0x2
    /* 90D4 8006C434 000013A6 */  sh         $s3, 0x0($s0)
    /* 90D8 8006C438 02001026 */  addiu      $s0, $s0, 0x2
    /* 90DC 8006C43C 000016A6 */  sh         $s6, 0x0($s0)
    /* 90E0 8006C440 02001026 */  addiu      $s0, $s0, 0x2
    /* 90E4 8006C444 000000A6 */  sh         $zero, 0x0($s0)
    /* 90E8 8006C448 02001026 */  addiu      $s0, $s0, 0x2
    /* 90EC 8006C44C 96000224 */  addiu      $v0, $zero, 0x96
    /* 90F0 8006C450 000002A6 */  sh         $v0, 0x0($s0)
    /* 90F4 8006C454 02001026 */  addiu      $s0, $s0, 0x2
    /* 90F8 8006C458 07000224 */  addiu      $v0, $zero, 0x7
    /* 90FC 8006C45C 000002A6 */  sh         $v0, 0x0($s0)
    /* 9100 8006C460 02001026 */  addiu      $s0, $s0, 0x2
    /* 9104 8006C464 000013A6 */  sh         $s3, 0x0($s0)
    /* 9108 8006C468 02001026 */  addiu      $s0, $s0, 0x2
    /* 910C 8006C46C 8200801A */  blez       $s4, .L8006C678
    /* 9110 8006C470 21880000 */   addu      $s1, $zero, $zero
    /* 9114 8006C474 0680023C */  lui        $v0, %hi(jtbl_80063568)
    /* 9118 8006C478 68354A24 */  addiu      $t2, $v0, %lo(jtbl_80063568)
    /* 911C 8006C47C 0780023C */  lui        $v0, %hi(Stg30_Battle)
    /* 9120 8006C480 C03C4924 */  addiu      $t1, $v0, %lo(Stg30_Battle)
    /* 9124 8006C484 1800A627 */  addiu      $a2, $sp, 0x18
    /* 9128 8006C488 4000A727 */  addiu      $a3, $sp, 0x40
    /* 912C 8006C48C 21402002 */  addu       $t0, $s1, $zero
  .L8006C490:
    /* 9130 8006C490 02000224 */  addiu      $v0, $zero, 0x2
    /* 9134 8006C494 000002A6 */  sh         $v0, 0x0($s0)
    /* 9138 8006C498 02001026 */  addiu      $s0, $s0, 0x2
    /* 913C 8006C49C 0000C294 */  lhu        $v0, 0x0($a2)
    /* 9140 8006C4A0 0C000324 */  addiu      $v1, $zero, 0xC
    /* 9144 8006C4A4 10004224 */  addiu      $v0, $v0, 0x10
    /* 9148 8006C4A8 000002A6 */  sh         $v0, 0x0($s0)
    /* 914C 8006C4AC 02001026 */  addiu      $s0, $s0, 0x2
    /* 9150 8006C4B0 03000224 */  addiu      $v0, $zero, 0x3
    /* 9154 8006C4B4 000002A6 */  sh         $v0, 0x0($s0)
    /* 9158 8006C4B8 0000C294 */  lhu        $v0, 0x0($a2)
    /* 915C 8006C4BC 02001026 */  addiu      $s0, $s0, 0x2
    /* 9160 8006C4C0 000002A6 */  sh         $v0, 0x0($s0)
    /* 9164 8006C4C4 02001026 */  addiu      $s0, $s0, 0x2
    /* 9168 8006C4C8 000000A6 */  sh         $zero, 0x0($s0)
    /* 916C 8006C4CC 02001026 */  addiu      $s0, $s0, 0x2
    /* 9170 8006C4D0 21100002 */  addu       $v0, $s0, $zero
    /* 9174 8006C4D4 02002016 */  bnez       $s1, .L8006C4E0
    /* 9178 8006C4D8 02001026 */   addiu     $s0, $s0, 0x2
    /* 917C 8006C4DC 1E000324 */  addiu      $v1, $zero, 0x1E
  .L8006C4E0:
    /* 9180 8006C4E0 000043A4 */  sh         $v1, 0x0($v0)
    /* 9184 8006C4E4 10000224 */  addiu      $v0, $zero, 0x10
    /* 9188 8006C4E8 000002A6 */  sh         $v0, 0x0($s0)
    /* 918C 8006C4EC 80101100 */  sll        $v0, $s1, 2
    /* 9190 8006C4F0 2110A203 */  addu       $v0, $sp, $v0
    /* 9194 8006C4F4 28004294 */  lhu        $v0, 0x28($v0)
    /* 9198 8006C4F8 02001026 */  addiu      $s0, $s0, 0x2
    /* 919C 8006C4FC 000002A6 */  sh         $v0, 0x0($s0)
    /* 91A0 8006C500 02001026 */  addiu      $s0, $s0, 0x2
    /* 91A4 8006C504 21200002 */  addu       $a0, $s0, $zero
    /* 91A8 8006C508 0000E284 */  lh         $v0, 0x0($a3)
    /* 91AC 8006C50C 0000E394 */  lhu        $v1, 0x0($a3)
    /* 91B0 8006C510 03004228 */  slti       $v0, $v0, 0x3
    /* 91B4 8006C514 03004010 */  beqz       $v0, .L8006C524
    /* 91B8 8006C518 02001026 */   addiu     $s0, $s0, 0x2
    /* 91BC 8006C51C 4AB10108 */  j          .L8006C528
    /* 91C0 8006C520 01006224 */   addiu     $v0, $v1, 0x1
  .L8006C524:
    /* 91C4 8006C524 08000224 */  addiu      $v0, $zero, 0x8
  .L8006C528:
    /* 91C8 8006C528 000082A4 */  sh         $v0, 0x0($a0)
    /* 91CC 8006C52C 2110A803 */  addu       $v0, $sp, $t0
    /* 91D0 8006C530 50004294 */  lhu        $v0, 0x50($v0)
    /* 91D4 8006C534 00000000 */  nop
    /* 91D8 8006C538 000002A6 */  sh         $v0, 0x0($s0)
    /* 91DC 8006C53C 0000E384 */  lh         $v1, 0x0($a3)
    /* 91E0 8006C540 00000000 */  nop
    /* 91E4 8006C544 0500622C */  sltiu      $v0, $v1, 0x5
    /* 91E8 8006C548 24004010 */  beqz       $v0, .L8006C5DC
    /* 91EC 8006C54C 02001026 */   addiu     $s0, $s0, 0x2
    /* 91F0 8006C550 80100300 */  sll        $v0, $v1, 2
    /* 91F4 8006C554 21104A00 */  addu       $v0, $v0, $t2
    /* 91F8 8006C558 0000428C */  lw         $v0, 0x0($v0)
    /* 91FC 8006C55C 00000000 */  nop
    /* 9200 8006C560 08004000 */  jr         $v0
    /* 9204 8006C564 00000000 */   nop
  jlabel .L8006C568
    /* 9208 8006C568 0000C384 */  lh         $v1, 0x0($a2)
    /* 920C 8006C56C 00000000 */  nop
    /* 9210 8006C570 40100300 */  sll        $v0, $v1, 1
    /* 9214 8006C574 21104300 */  addu       $v0, $v0, $v1
    /* 9218 8006C578 C0100200 */  sll        $v0, $v0, 3
    /* 921C 8006C57C 23104300 */  subu       $v0, $v0, $v1
    /* 9220 8006C580 80100200 */  sll        $v0, $v0, 2
    /* 9224 8006C584 21104900 */  addu       $v0, $v0, $t1
    /* 9228 8006C588 2E004284 */  lh         $v0, 0x2E($v0)
    /* 922C 8006C58C 00000000 */  nop
    /* 9230 8006C590 0B004010 */  beqz       $v0, .L8006C5C0
    /* 9234 8006C594 21280002 */   addu      $a1, $s0, $zero
    /* 9238 8006C598 02001026 */  addiu      $s0, $s0, 0x2
    /* 923C 8006C59C 00110300 */  sll        $v0, $v1, 4
    /* 9240 8006C5A0 21104900 */  addu       $v0, $v0, $t1
    /* 9244 8006C5A4 AC02438C */  lw         $v1, 0x2AC($v0)
    /* 9248 8006C5A8 05000224 */  addiu      $v0, $zero, 0x5
    /* 924C 8006C5AC 02006210 */  beq        $v1, $v0, .L8006C5B8
    /* 9250 8006C5B0 0A000424 */   addiu     $a0, $zero, 0xA
    /* 9254 8006C5B4 0B000424 */  addiu      $a0, $zero, 0xB
  .L8006C5B8:
    /* 9258 8006C5B8 77B10108 */  j          .L8006C5DC
    /* 925C 8006C5BC 0000A4A4 */   sh        $a0, 0x0($a1)
  .L8006C5C0:
    /* 9260 8006C5C0 75B10108 */  j          .L8006C5D4
    /* 9264 8006C5C4 0C000224 */   addiu     $v0, $zero, 0xC
  jlabel .L8006C5C8
    /* 9268 8006C5C8 75B10108 */  j          .L8006C5D4
    /* 926C 8006C5CC 08000224 */   addiu     $v0, $zero, 0x8
  jlabel .L8006C5D0
    /* 9270 8006C5D0 0D000224 */  addiu      $v0, $zero, 0xD
  .L8006C5D4:
    /* 9274 8006C5D4 000002A6 */  sh         $v0, 0x0($s0)
    /* 9278 8006C5D8 02001026 */  addiu      $s0, $s0, 0x2
  .L8006C5DC:
    /* 927C 8006C5DC 0000C294 */  lhu        $v0, 0x0($a2)
    /* 9280 8006C5E0 00000000 */  nop
    /* 9284 8006C5E4 000002A6 */  sh         $v0, 0x0($s0)
    /* 9288 8006C5E8 02001026 */  addiu      $s0, $s0, 0x2
    /* 928C 8006C5EC 000016A6 */  sh         $s6, 0x0($s0)
    /* 9290 8006C5F0 01000224 */  addiu      $v0, $zero, 0x1
    /* 9294 8006C5F4 15008216 */  bne        $s4, $v0, .L8006C64C
    /* 9298 8006C5F8 02001026 */   addiu     $s0, $s0, 0x2
    /* 929C 8006C5FC 0000E284 */  lh         $v0, 0x0($a3)
    /* 92A0 8006C600 00000000 */  nop
    /* 92A4 8006C604 0A004014 */  bnez       $v0, .L8006C630
    /* 92A8 8006C608 00000000 */   nop
    /* 92AC 8006C60C 000014A6 */  sh         $s4, 0x0($s0)
    /* 92B0 8006C610 0000C294 */  lhu        $v0, 0x0($a2)
    /* 92B4 8006C614 02001026 */  addiu      $s0, $s0, 0x2
    /* 92B8 8006C618 000002A6 */  sh         $v0, 0x0($s0)
    /* 92BC 8006C61C 02001026 */  addiu      $s0, $s0, 0x2
    /* 92C0 8006C620 000000A6 */  sh         $zero, 0x0($s0)
    /* 92C4 8006C624 02001026 */  addiu      $s0, $s0, 0x2
    /* 92C8 8006C628 96B10108 */  j          .L8006C658
    /* 92CC 8006C62C 1E000224 */   addiu     $v0, $zero, 0x1E
  .L8006C630:
    /* 92D0 8006C630 0B004004 */  bltz       $v0, .L8006C660
    /* 92D4 8006C634 05004228 */   slti      $v0, $v0, 0x5
    /* 92D8 8006C638 09004010 */  beqz       $v0, .L8006C660
    /* 92DC 8006C63C 78000224 */   addiu     $v0, $zero, 0x78
    /* 92E0 8006C640 000000A6 */  sh         $zero, 0x0($s0)
    /* 92E4 8006C644 96B10108 */  j          .L8006C658
    /* 92E8 8006C648 02001026 */   addiu     $s0, $s0, 0x2
  .L8006C64C:
    /* 92EC 8006C64C 000000A6 */  sh         $zero, 0x0($s0)
    /* 92F0 8006C650 02001026 */  addiu      $s0, $s0, 0x2
    /* 92F4 8006C654 3C000224 */  addiu      $v0, $zero, 0x3C
  .L8006C658:
    /* 92F8 8006C658 000002A6 */  sh         $v0, 0x0($s0)
    /* 92FC 8006C65C 02001026 */  addiu      $s0, $s0, 0x2
  .L8006C660:
    /* 9300 8006C660 0200C624 */  addiu      $a2, $a2, 0x2
    /* 9304 8006C664 0200E724 */  addiu      $a3, $a3, 0x2
    /* 9308 8006C668 01003126 */  addiu      $s1, $s1, 0x1
    /* 930C 8006C66C 2A103402 */  slt        $v0, $s1, $s4
    /* 9310 8006C670 87FF4014 */  bnez       $v0, .L8006C490
    /* 9314 8006C674 02000825 */   addiu     $t0, $t0, 0x2
  .L8006C678:
    /* 9318 8006C678 01000224 */  addiu      $v0, $zero, 0x1
    /* 931C 8006C67C 20008212 */  beq        $s4, $v0, .L8006C700
    /* 9320 8006C680 02000224 */   addiu     $v0, $zero, 0x2
    /* 9324 8006C684 000002A6 */  sh         $v0, 0x0($s0)
    /* 9328 8006C688 02001026 */  addiu      $s0, $s0, 0x2
    /* 932C 8006C68C 1600E226 */  addiu      $v0, $s7, 0x16
    /* 9330 8006C690 000002A6 */  sh         $v0, 0x0($s0)
    /* 9334 8006C694 02001026 */  addiu      $s0, $s0, 0x2
    /* 9338 8006C698 0400E226 */  addiu      $v0, $s7, 0x4
    /* 933C 8006C69C BAB10108 */  j          .L8006C6E8
    /* 9340 8006C6A0 000002A6 */   sh        $v0, 0x0($s0)
  .L8006C6A4:
    /* 9344 8006C6A4 02000224 */  addiu      $v0, $zero, 0x2
    /* 9348 8006C6A8 000002A6 */  sh         $v0, 0x0($s0)
    /* 934C 8006C6AC 02001026 */  addiu      $s0, $s0, 0x2
    /* 9350 8006C6B0 0A006226 */  addiu      $v0, $s3, 0xA
    /* 9354 8006C6B4 000002A6 */  sh         $v0, 0x0($s0)
    /* 9358 8006C6B8 02001026 */  addiu      $s0, $s0, 0x2
    /* 935C 8006C6BC 03000224 */  addiu      $v0, $zero, 0x3
    /* 9360 8006C6C0 000002A6 */  sh         $v0, 0x0($s0)
    /* 9364 8006C6C4 02001026 */  addiu      $s0, $s0, 0x2
    /* 9368 8006C6C8 000013A6 */  sh         $s3, 0x0($s0)
    /* 936C 8006C6CC 02001026 */  addiu      $s0, $s0, 0x2
    /* 9370 8006C6D0 0E000224 */  addiu      $v0, $zero, 0xE
    /* 9374 8006C6D4 000002A6 */  sh         $v0, 0x0($s0)
    /* 9378 8006C6D8 02001026 */  addiu      $s0, $s0, 0x2
    /* 937C 8006C6DC 000000A6 */  sh         $zero, 0x0($s0)
    /* 9380 8006C6E0 02001026 */  addiu      $s0, $s0, 0x2
    /* 9384 8006C6E4 000000A6 */  sh         $zero, 0x0($s0)
  .L8006C6E8:
    /* 9388 8006C6E8 02001026 */  addiu      $s0, $s0, 0x2
    /* 938C 8006C6EC 000000A6 */  sh         $zero, 0x0($s0)
    /* 9390 8006C6F0 02001026 */  addiu      $s0, $s0, 0x2
    /* 9394 8006C6F4 B4000224 */  addiu      $v0, $zero, 0xB4
    /* 9398 8006C6F8 000002A6 */  sh         $v0, 0x0($s0)
    /* 939C 8006C6FC 02001026 */  addiu      $s0, $s0, 0x2
  .L8006C700:
    /* 93A0 8006C700 18000224 */  addiu      $v0, $zero, 0x18
    /* 93A4 8006C704 000002A6 */  sh         $v0, 0x0($s0)
    /* 93A8 8006C708 0780023C */  lui        $v0, %hi(Stg30_Battle)
    /* 93AC 8006C70C C03C4324 */  addiu      $v1, $v0, %lo(Stg30_Battle)
    /* 93B0 8006C710 B4036284 */  lh         $v0, 0x3B4($v1)
    /* 93B4 8006C714 00000000 */  nop
    /* 93B8 8006C718 BC004010 */  beqz       $v0, .L8006CA0C
    /* 93BC 8006C71C 21880000 */   addu      $s1, $zero, $zero
    /* 93C0 8006C720 FFFF0824 */  addiu      $t0, $zero, -0x1
    /* 93C4 8006C724 2800A627 */  addiu      $a2, $sp, 0x28
    /* 93C8 8006C728 21386000 */  addu       $a3, $v1, $zero
    /* 93CC 8006C72C 2128E000 */  addu       $a1, $a3, $zero
    /* 93D0 8006C730 1800A427 */  addiu      $a0, $sp, 0x18
  .L8006C734:
    /* 93D4 8006C734 00008284 */  lh         $v0, 0x0($a0)
    /* 93D8 8006C738 00000000 */  nop
    /* 93DC 8006C73C 05004810 */  beq        $v0, $t0, .L8006C754
    /* 93E0 8006C740 B803A2AC */   sw        $v0, 0x3B8($a1)
    /* 93E4 8006C744 00110200 */  sll        $v0, $v0, 4
    /* 93E8 8006C748 0000C394 */  lhu        $v1, 0x0($a2)
    /* 93EC 8006C74C 21104700 */  addu       $v0, $v0, $a3
    /* 93F0 8006C750 B80243A4 */  sh         $v1, 0x2B8($v0)
  .L8006C754:
    /* 93F4 8006C754 0400C624 */  addiu      $a2, $a2, 0x4
    /* 93F8 8006C758 0400A524 */  addiu      $a1, $a1, 0x4
    /* 93FC 8006C75C 01003126 */  addiu      $s1, $s1, 0x1
    /* 9400 8006C760 0600222A */  slti       $v0, $s1, 0x6
    /* 9404 8006C764 F3FF4014 */  bnez       $v0, .L8006C734
    /* 9408 8006C768 02008424 */   addiu     $a0, $a0, 0x2
    /* 940C 8006C76C 00141600 */  sll        $v0, $s6, 16
    /* 9410 8006C770 03840200 */  sra        $s0, $v0, 16
    /* 9414 8006C774 A07B000C */  jal        Skill_GetMpCost
    /* 9418 8006C778 21200002 */   addu      $a0, $s0, $zero
    /* 941C 8006C77C 21884000 */  addu       $s1, $v0, $zero
    /* 9420 8006C780 0000C38F */  lw         $v1, 0x0($fp)
    /* 9424 8006C784 02000224 */  addiu      $v0, $zero, 0x2
    /* 9428 8006C788 11006214 */  bne        $v1, $v0, .L8006C7D0
    /* 942C 8006C78C 40101300 */   sll       $v0, $s3, 1
    /* 9430 8006C790 397C000C */  jal        func_8001F0E4
    /* 9434 8006C794 21200002 */   addu      $a0, $s0, $zero
    /* 9438 8006C798 00104230 */  andi       $v0, $v0, 0x1000
    /* 943C 8006C79C 0B004010 */  beqz       $v0, .L8006C7CC
    /* 9440 8006C7A0 00000000 */   nop
    /* 9444 8006C7A4 1800A287 */  lh         $v0, 0x18($sp)
    /* 9448 8006C7A8 00000000 */  nop
    /* 944C 8006C7AC 40180200 */  sll        $v1, $v0, 1
    /* 9450 8006C7B0 21186200 */  addu       $v1, $v1, $v0
    /* 9454 8006C7B4 C0180300 */  sll        $v1, $v1, 3
    /* 9458 8006C7B8 23186200 */  subu       $v1, $v1, $v0
    /* 945C 8006C7BC 80180300 */  sll        $v1, $v1, 2
    /* 9460 8006C7C0 0780023C */  lui        $v0, %hi(D_80073CF2)
    /* 9464 8006C7C4 FAB10108 */  j          .L8006C7E8
    /* 9468 8006C7C8 F23C4224 */   addiu     $v0, $v0, %lo(D_80073CF2)
  .L8006C7CC:
    /* 946C 8006C7CC 40101300 */  sll        $v0, $s3, 1
  .L8006C7D0:
    /* 9470 8006C7D0 21105300 */  addu       $v0, $v0, $s3
    /* 9474 8006C7D4 C0100200 */  sll        $v0, $v0, 3
    /* 9478 8006C7D8 23105300 */  subu       $v0, $v0, $s3
    /* 947C 8006C7DC 80100200 */  sll        $v0, $v0, 2
    /* 9480 8006C7E0 0780033C */  lui        $v1, %hi(D_80073CF2)
    /* 9484 8006C7E4 F23C6324 */  addiu      $v1, $v1, %lo(D_80073CF2)
  .L8006C7E8:
    /* 9488 8006C7E8 21184300 */  addu       $v1, $v0, $v1
    /* 948C 8006C7EC 00006294 */  lhu        $v0, 0x0($v1)
    /* 9490 8006C7F0 00000000 */  nop
    /* 9494 8006C7F4 23105100 */  subu       $v0, $v0, $s1
    /* 9498 8006C7F8 000062A4 */  sh         $v0, 0x0($v1)
    /* 949C 8006C7FC 00140200 */  sll        $v0, $v0, 16
    /* 94A0 8006C800 02004104 */  bgez       $v0, .L8006C80C
    /* 94A4 8006C804 00141600 */   sll       $v0, $s6, 16
    /* 94A8 8006C808 000060A4 */  sh         $zero, 0x0($v1)
  .L8006C80C:
    /* 94AC 8006C80C 031C0200 */  sra        $v1, $v0, 16
    /* 94B0 8006C810 4D000224 */  addiu      $v0, $zero, 0x4D
    /* 94B4 8006C814 03006210 */  beq        $v1, $v0, .L8006C824
    /* 94B8 8006C818 FB000224 */   addiu     $v0, $zero, 0xFB
    /* 94BC 8006C81C 1C006214 */  bne        $v1, $v0, .L8006C890
    /* 94C0 8006C820 00141600 */   sll       $v0, $s6, 16
  .L8006C824:
    /* 94C4 8006C824 0780023C */  lui        $v0, %hi(Stg30_Battle)
    /* 94C8 8006C828 1800A387 */  lh         $v1, 0x18($sp)
    /* 94CC 8006C82C C03C4424 */  addiu      $a0, $v0, %lo(Stg30_Battle)
    /* 94D0 8006C830 40100300 */  sll        $v0, $v1, 1
    /* 94D4 8006C834 21104300 */  addu       $v0, $v0, $v1
    /* 94D8 8006C838 C0100200 */  sll        $v0, $v0, 3
    /* 94DC 8006C83C 23104300 */  subu       $v0, $v0, $v1
    /* 94E0 8006C840 80100200 */  sll        $v0, $v0, 2
    /* 94E4 8006C844 21104400 */  addu       $v0, $v0, $a0
    /* 94E8 8006C848 2E004284 */  lh         $v0, 0x2E($v0)
    /* 94EC 8006C84C 00000000 */  nop
    /* 94F0 8006C850 0F004014 */  bnez       $v0, .L8006C890
    /* 94F4 8006C854 00141600 */   sll       $v0, $s6, 16
    /* 94F8 8006C858 00111300 */  sll        $v0, $s3, 4
    /* 94FC 8006C85C 21804400 */  addu       $s0, $v0, $a0
    /* 9500 8006C860 FB000224 */  addiu      $v0, $zero, 0xFB
    /* 9504 8006C864 B20202A6 */  sh         $v0, 0x2B2($s0)
    /* 9508 8006C868 0300622A */  slti       $v0, $s3, 0x3
    /* 950C 8006C86C 03004010 */  beqz       $v0, .L8006C87C
    /* 9510 8006C870 4D000424 */   addiu     $a0, $zero, 0x4D
    /* 9514 8006C874 20B20108 */  j          .L8006C880
    /* 9518 8006C878 01000524 */   addiu     $a1, $zero, 0x1
  .L8006C87C:
    /* 951C 8006C87C 07000524 */  addiu      $a1, $zero, 0x7
  .L8006C880:
    /* 9520 8006C880 A9A4010C */  jal        Stg30_PickTarget
    /* 9524 8006C884 21306002 */   addu      $a2, $s3, $zero
    /* 9528 8006C888 76B20108 */  j          .L8006C9D8
    /* 952C 8006C88C B00202A6 */   sh        $v0, 0x2B0($s0)
  .L8006C890:
    /* 9530 8006C890 03140200 */  sra        $v0, $v0, 16
    /* 9534 8006C894 68000324 */  addiu      $v1, $zero, 0x68
    /* 9538 8006C898 1B004314 */  bne        $v0, $v1, .L8006C908
    /* 953C 8006C89C 00141600 */   sll       $v0, $s6, 16
    /* 9540 8006C8A0 A07B000C */  jal        Skill_GetMpCost
    /* 9544 8006C8A4 21206000 */   addu      $a0, $v1, $zero
    /* 9548 8006C8A8 0780033C */  lui        $v1, %hi(Stg30_Battle)
    /* 954C 8006C8AC C03C7024 */  addiu      $s0, $v1, %lo(Stg30_Battle)
    /* 9550 8006C8B0 40181300 */  sll        $v1, $s3, 1
    /* 9554 8006C8B4 21187300 */  addu       $v1, $v1, $s3
    /* 9558 8006C8B8 C0180300 */  sll        $v1, $v1, 3
    /* 955C 8006C8BC 23187300 */  subu       $v1, $v1, $s3
    /* 9560 8006C8C0 80180300 */  sll        $v1, $v1, 2
    /* 9564 8006C8C4 21187000 */  addu       $v1, $v1, $s0
    /* 9568 8006C8C8 32006384 */  lh         $v1, 0x32($v1)
    /* 956C 8006C8CC 00000000 */  nop
    /* 9570 8006C8D0 2A186200 */  slt        $v1, $v1, $v0
    /* 9574 8006C8D4 0C006014 */  bnez       $v1, .L8006C908
    /* 9578 8006C8D8 00141600 */   sll       $v0, $s6, 16
    /* 957C 8006C8DC 0300622A */  slti       $v0, $s3, 0x3
    /* 9580 8006C8E0 03004010 */  beqz       $v0, .L8006C8F0
    /* 9584 8006C8E4 4D000424 */   addiu     $a0, $zero, 0x4D
    /* 9588 8006C8E8 3DB20108 */  j          .L8006C8F4
    /* 958C 8006C8EC 01000524 */   addiu     $a1, $zero, 0x1
  .L8006C8F0:
    /* 9590 8006C8F0 07000524 */  addiu      $a1, $zero, 0x7
  .L8006C8F4:
    /* 9594 8006C8F4 A9A4010C */  jal        Stg30_PickTarget
    /* 9598 8006C8F8 21306002 */   addu      $a2, $s3, $zero
    /* 959C 8006C8FC 00191300 */  sll        $v1, $s3, 4
    /* 95A0 8006C900 75B20108 */  j          .L8006C9D4
    /* 95A4 8006C904 21187000 */   addu      $v1, $v1, $s0
  .L8006C908:
    /* 95A8 8006C908 03140200 */  sra        $v0, $v0, 16
    /* 95AC 8006C90C DC000324 */  addiu      $v1, $zero, 0xDC
    /* 95B0 8006C910 3E004314 */  bne        $v0, $v1, .L8006CA0C
    /* 95B4 8006C914 0780103C */   lui       $s0, %hi(D_80073278)
    /* 95B8 8006C918 7832028E */  lw         $v0, %lo(D_80073278)($s0)
    /* 95BC 8006C91C 00000000 */  nop
    /* 95C0 8006C920 12004014 */  bnez       $v0, .L8006C96C
    /* 95C4 8006C924 FFFF4224 */   addiu     $v0, $v0, -0x1
    /* 95C8 8006C928 448E000C */  jal        Rand_Next
    /* 95CC 8006C92C 00000000 */   nop
    /* 95D0 8006C930 FFFF4230 */  andi       $v0, $v0, 0xFFFF
    /* 95D4 8006C934 AAAA033C */  lui        $v1, (0xAAAAAAAB >> 16)
    /* 95D8 8006C938 ABAA6334 */  ori        $v1, $v1, (0xAAAAAAAB & 0xFFFF)
    /* 95DC 8006C93C 19004300 */  multu      $v0, $v1
    /* 95E0 8006C940 10580000 */  mfhi       $t3
    /* 95E4 8006C944 42200B00 */  srl        $a0, $t3, 1
    /* 95E8 8006C948 40180400 */  sll        $v1, $a0, 1
    /* 95EC 8006C94C 21186400 */  addu       $v1, $v1, $a0
    /* 95F0 8006C950 23104300 */  subu       $v0, $v0, $v1
    /* 95F4 8006C954 FFFF4230 */  andi       $v0, $v0, 0xFFFF
    /* 95F8 8006C958 01004224 */  addiu      $v0, $v0, 0x1
    /* 95FC 8006C95C 783202AE */  sw         $v0, %lo(D_80073278)($s0)
    /* 9600 8006C960 7832028E */  lw         $v0, %lo(D_80073278)($s0)
    /* 9604 8006C964 00000000 */  nop
    /* 9608 8006C968 FFFF4224 */  addiu      $v0, $v0, -0x1
  .L8006C96C:
    /* 960C 8006C96C 27004010 */  beqz       $v0, .L8006CA0C
    /* 9610 8006C970 783202AE */   sw        $v0, %lo(D_80073278)($s0)
    /* 9614 8006C974 A07B000C */  jal        Skill_GetMpCost
    /* 9618 8006C978 DC000424 */   addiu     $a0, $zero, 0xDC
    /* 961C 8006C97C 0780033C */  lui        $v1, %hi(Stg30_Battle)
    /* 9620 8006C980 C03C7124 */  addiu      $s1, $v1, %lo(Stg30_Battle)
    /* 9624 8006C984 40181300 */  sll        $v1, $s3, 1
    /* 9628 8006C988 21187300 */  addu       $v1, $v1, $s3
    /* 962C 8006C98C C0180300 */  sll        $v1, $v1, 3
    /* 9630 8006C990 23187300 */  subu       $v1, $v1, $s3
    /* 9634 8006C994 80180300 */  sll        $v1, $v1, 2
    /* 9638 8006C998 21187100 */  addu       $v1, $v1, $s1
    /* 963C 8006C99C 32006384 */  lh         $v1, 0x32($v1)
    /* 9640 8006C9A0 00000000 */  nop
    /* 9644 8006C9A4 2A186200 */  slt        $v1, $v1, $v0
    /* 9648 8006C9A8 17006014 */  bnez       $v1, .L8006CA08
    /* 964C 8006C9AC 0300622A */   slti      $v0, $s3, 0x3
    /* 9650 8006C9B0 03004010 */  beqz       $v0, .L8006C9C0
    /* 9654 8006C9B4 4D000424 */   addiu     $a0, $zero, 0x4D
    /* 9658 8006C9B8 71B20108 */  j          .L8006C9C4
    /* 965C 8006C9BC 01000524 */   addiu     $a1, $zero, 0x1
  .L8006C9C0:
    /* 9660 8006C9C0 07000524 */  addiu      $a1, $zero, 0x7
  .L8006C9C4:
    /* 9664 8006C9C4 A9A4010C */  jal        Stg30_PickTarget
    /* 9668 8006C9C8 21306002 */   addu      $a2, $s3, $zero
    /* 966C 8006C9CC 00191300 */  sll        $v1, $s3, 4
    /* 9670 8006C9D0 21187100 */  addu       $v1, $v1, $s1
  .L8006C9D4:
    /* 9674 8006C9D4 B00262A4 */  sh         $v0, 0x2B0($v1)
  .L8006C9D8:
    /* 9678 8006C9D8 0780023C */  lui        $v0, %hi(Stg30_Battle)
    /* 967C 8006C9DC C03C4224 */  addiu      $v0, $v0, %lo(Stg30_Battle)
    /* 9680 8006C9E0 00191300 */  sll        $v1, $s3, 4
    /* 9684 8006C9E4 21186200 */  addu       $v1, $v1, $v0
    /* 9688 8006C9E8 B0026284 */  lh         $v0, 0x2B0($v1)
    /* 968C 8006C9EC 00000000 */  nop
    /* 9690 8006C9F0 06005310 */  beq        $v0, $s3, .L8006CA0C
    /* 9694 8006C9F4 01000424 */   addiu     $a0, $zero, 0x1
    /* 9698 8006C9F8 57B9010C */  jal        Stg30_TurnOrderInsert
    /* 969C 8006C9FC 21286002 */   addu      $a1, $s3, $zero
    /* 96A0 8006CA00 83B20108 */  j          .L8006CA0C
    /* 96A4 8006CA04 00000000 */   nop
  .L8006CA08:
    /* 96A8 8006CA08 783200AE */  sw         $zero, %lo(D_80073278)($s0)
  .L8006CA0C:
    /* 96AC 8006CA0C 8400BF8F */  lw         $ra, 0x84($sp)
    /* 96B0 8006CA10 8000BE8F */  lw         $fp, 0x80($sp)
    /* 96B4 8006CA14 7C00B78F */  lw         $s7, 0x7C($sp)
    /* 96B8 8006CA18 7800B68F */  lw         $s6, 0x78($sp)
    /* 96BC 8006CA1C 7400B58F */  lw         $s5, 0x74($sp)
    /* 96C0 8006CA20 7000B48F */  lw         $s4, 0x70($sp)
    /* 96C4 8006CA24 6C00B38F */  lw         $s3, 0x6C($sp)
    /* 96C8 8006CA28 6800B28F */  lw         $s2, 0x68($sp)
    /* 96CC 8006CA2C 6400B18F */  lw         $s1, 0x64($sp)
    /* 96D0 8006CA30 6000B08F */  lw         $s0, 0x60($sp)
    /* 96D4 8006CA34 0800E003 */  jr         $ra
    /* 96D8 8006CA38 8800BD27 */   addiu     $sp, $sp, 0x88
endlabel Stg30_BuildSkillScript
