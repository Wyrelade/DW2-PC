nonmatching Stg20_PartsUpgradeUpdate, 0x434

glabel Stg20_PartsUpgradeUpdate
    /* BAC4 8006EE24 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* BAC8 8006EE28 1800B2AF */  sw         $s2, 0x18($sp)
    /* BACC 8006EE2C 21908000 */  addu       $s2, $a0, $zero
    /* BAD0 8006EE30 2000B4AF */  sw         $s4, 0x20($sp)
    /* BAD4 8006EE34 01001424 */  addiu      $s4, $zero, 0x1
    /* BAD8 8006EE38 2400BFAF */  sw         $ra, 0x24($sp)
    /* BADC 8006EE3C 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* BAE0 8006EE40 1400B1AF */  sw         $s1, 0x14($sp)
    /* BAE4 8006EE44 1000B0AF */  sw         $s0, 0x10($sp)
    /* BAE8 8006EE48 2C00518E */  lw         $s1, 0x2C($s2)
    /* BAEC 8006EE4C 1000508E */  lw         $s0, 0x10($s2)
    /* BAF0 8006EE50 3400538E */  lw         $s3, 0x34($s2)
    /* BAF4 8006EE54 48001412 */  beq        $s0, $s4, .L8006EF78
    /* BAF8 8006EE58 0200022A */   slti      $v0, $s0, 0x2
    /* BAFC 8006EE5C F6004010 */  beqz       $v0, .L8006F238
    /* BB00 8006EE60 00000000 */   nop
    /* BB04 8006EE64 F4000016 */  bnez       $s0, .L8006F238
    /* BB08 8006EE68 21202002 */   addu      $a0, $s1, $zero
    /* BB0C 8006EE6C 2270000C */  jal        Mem_FillWordsNeg1
    /* BB10 8006EE70 0C000524 */   addiu     $a1, $zero, 0xC
    /* BB14 8006EE74 21202002 */  addu       $a0, $s1, $zero
    /* BB18 8006EE78 7A010524 */  addiu      $a1, $zero, 0x17A
    /* BB1C 8006EE7C 04000624 */  addiu      $a2, $zero, 0x4
    /* BB20 8006EE80 0780023C */  lui        $v0, %hi(Stg20_UpgradeTextPos)
    /* BB24 8006EE84 A4065024 */  addiu      $s0, $v0, %lo(Stg20_UpgradeTextPos)
    /* BB28 8006EE88 02000796 */  lhu        $a3, 0x2($s0)
    /* BB2C 8006EE8C A4064294 */  lhu        $v0, %lo(Stg20_UpgradeTextPos)($v0)
    /* BB30 8006EE90 003C0700 */  sll        $a3, $a3, 16
    /* BB34 8006EE94 F26F000C */  jal        Text_OpenById
    /* BB38 8006EE98 25384700 */   or        $a3, $v0, $a3
    /* BB3C 8006EE9C 04002426 */  addiu      $a0, $s1, 0x4
    /* BB40 8006EEA0 7B010524 */  addiu      $a1, $zero, 0x17B
    /* BB44 8006EEA4 04000624 */  addiu      $a2, $zero, 0x4
    /* BB48 8006EEA8 06000796 */  lhu        $a3, 0x6($s0)
    /* BB4C 8006EEAC 04000296 */  lhu        $v0, 0x4($s0)
    /* BB50 8006EEB0 003C0700 */  sll        $a3, $a3, 16
    /* BB54 8006EEB4 F26F000C */  jal        Text_OpenById
    /* BB58 8006EEB8 25384700 */   or        $a3, $v0, $a3
    /* BB5C 8006EEBC 08002426 */  addiu      $a0, $s1, 0x8
    /* BB60 8006EEC0 DE000524 */  addiu      $a1, $zero, 0xDE
    /* BB64 8006EEC4 21300000 */  addu       $a2, $zero, $zero
    /* BB68 8006EEC8 0A000796 */  lhu        $a3, 0xA($s0)
    /* BB6C 8006EECC 08000296 */  lhu        $v0, 0x8($s0)
    /* BB70 8006EED0 003C0700 */  sll        $a3, $a3, 16
    /* BB74 8006EED4 F26F000C */  jal        Text_OpenById
    /* BB78 8006EED8 25384700 */   or        $a3, $v0, $a3
    /* BB7C 8006EEDC 0C002426 */  addiu      $a0, $s1, 0xC
    /* BB80 8006EEE0 0680053C */  lui        $a1, %hi(D_8005E6F1)
    /* BB84 8006EEE4 F1E6A524 */  addiu      $a1, $a1, %lo(D_8005E6F1)
    /* BB88 8006EEE8 21300000 */  addu       $a2, $zero, $zero
    /* BB8C 8006EEEC 0E000796 */  lhu        $a3, 0xE($s0)
    /* BB90 8006EEF0 0C000296 */  lhu        $v0, 0xC($s0)
    /* BB94 8006EEF4 003C0700 */  sll        $a3, $a3, 16
    /* BB98 8006EEF8 3E4D000C */  jal        Text_OpenPacked
    /* BB9C 8006EEFC 25384700 */   or        $a3, $v0, $a3
    /* BBA0 8006EF00 0D030424 */  addiu      $a0, $zero, 0x30D
    /* BBA4 8006EF04 21286002 */  addu       $a1, $s3, $zero
    /* BBA8 8006EF08 1F44000C */  jal        Task_Create
    /* BBAC 8006EF0C 21300000 */   addu      $a2, $zero, $zero
    /* BBB0 8006EF10 A4BA010C */  jal        Stg20_BuildUpgradeList
    /* BBB4 8006EF14 21204002 */   addu      $a0, $s2, $zero
    /* BBB8 8006EF18 21204002 */  addu       $a0, $s2, $zero
    /* BBBC 8006EF1C 7C010224 */  addiu      $v0, $zero, 0x17C
    /* BBC0 8006EF20 340034AE */  sw         $s4, 0x34($s1)
    /* BBC4 8006EF24 5145000C */  jal        Task_NextState0
    /* BBC8 8006EF28 FC0022AE */   sw        $v0, 0xFC($s1)
    /* BBCC 8006EF2C 8EBC0108 */  j          .L8006F238
    /* BBD0 8006EF30 00000000 */   nop
  .L8006EF34:
    /* BBD4 8006EF34 0B000424 */  addiu      $a0, $zero, 0xB
    /* BBD8 8006EF38 A369000C */  jal        Snd_PlayById
    /* BBDC 8006EF3C 21280000 */   addu      $a1, $zero, $zero
    /* BBE0 8006EF40 21204002 */  addu       $a0, $s2, $zero
    /* BBE4 8006EF44 7045000C */  jal        Task_SetState0
    /* BBE8 8006EF48 03000524 */   addiu     $a1, $zero, 0x3
    /* BBEC 8006EF4C 1CBC0108 */  j          .L8006F070
    /* BBF0 8006EF50 00000000 */   nop
  .L8006EF54:
    /* BBF4 8006EF54 D8BB0108 */  j          .L8006EF60
    /* BBF8 8006EF58 7D010224 */   addiu     $v0, $zero, 0x17D
  .L8006EF5C:
    /* BBFC 8006EF5C 39010224 */  addiu      $v0, $zero, 0x139
  .L8006EF60:
    /* BC00 8006EF60 FC0022AE */  sw         $v0, 0xFC($s1)
    /* BC04 8006EF64 10000424 */  addiu      $a0, $zero, 0x10
    /* BC08 8006EF68 A369000C */  jal        Snd_PlayById
    /* BC0C 8006EF6C 21280000 */   addu      $a1, $zero, $zero
    /* BC10 8006EF70 1CBC0108 */  j          .L8006F070
    /* BC14 8006EF74 00000000 */   nop
  .L8006EF78:
    /* BC18 8006EF78 1400428E */  lw         $v0, 0x14($s2)
    /* BC1C 8006EF7C 00000000 */  nop
    /* BC20 8006EF80 03004010 */  beqz       $v0, .L8006EF90
    /* BC24 8006EF84 00000000 */   nop
    /* BC28 8006EF88 3D005010 */  beq        $v0, $s0, .L8006F080
    /* BC2C 8006EF8C 00000000 */   nop
  .L8006EF90:
    /* BC30 8006EF90 0680023C */  lui        $v0, %hi(Pad_State)
    /* BC34 8006EF94 F0F64424 */  addiu      $a0, $v0, %lo(Pad_State)
    /* BC38 8006EF98 3C008394 */  lhu        $v1, 0x3C($a0)
    /* BC3C 8006EF9C 00000000 */  nop
    /* BC40 8006EFA0 00106230 */  andi       $v0, $v1, 0x1000
    /* BC44 8006EFA4 07004010 */  beqz       $v0, .L8006EFC4
    /* BC48 8006EFA8 00406230 */   andi      $v0, $v1, 0x4000
    /* BC4C 8006EFAC 3000228E */  lw         $v0, 0x30($s1)
    /* BC50 8006EFB0 00000000 */  nop
    /* BC54 8006EFB4 0D004010 */  beqz       $v0, .L8006EFEC
    /* BC58 8006EFB8 FFFF4224 */   addiu     $v0, $v0, -0x1
    /* BC5C 8006EFBC F8BB0108 */  j          .L8006EFE0
    /* BC60 8006EFC0 300022AE */   sw        $v0, 0x30($s1)
  .L8006EFC4:
    /* BC64 8006EFC4 0D004010 */  beqz       $v0, .L8006EFFC
    /* BC68 8006EFC8 05000224 */   addiu     $v0, $zero, 0x5
    /* BC6C 8006EFCC 3000238E */  lw         $v1, 0x30($s1)
    /* BC70 8006EFD0 00000000 */  nop
    /* BC74 8006EFD4 05006210 */  beq        $v1, $v0, .L8006EFEC
    /* BC78 8006EFD8 01006224 */   addiu     $v0, $v1, 0x1
    /* BC7C 8006EFDC 300022AE */  sw         $v0, 0x30($s1)
  .L8006EFE0:
    /* BC80 8006EFE0 0D000424 */  addiu      $a0, $zero, 0xD
    /* BC84 8006EFE4 A369000C */  jal        Snd_PlayById
    /* BC88 8006EFE8 21280000 */   addu      $a1, $zero, $zero
  .L8006EFEC:
    /* BC8C 8006EFEC 7C010224 */  addiu      $v0, $zero, 0x17C
    /* BC90 8006EFF0 340030AE */  sw         $s0, 0x34($s1)
    /* BC94 8006EFF4 1CBC0108 */  j          .L8006F070
    /* BC98 8006EFF8 FC0022AE */   sw        $v0, 0xFC($s1)
  .L8006EFFC:
    /* BC9C 8006EFFC 1C00828C */  lw         $v0, 0x1C($a0)
    /* BCA0 8006F000 00000000 */  nop
    /* BCA4 8006F004 CBFF401C */  bgtz       $v0, .L8006EF34
    /* BCA8 8006F008 00000000 */   nop
    /* BCAC 8006F00C 1400828C */  lw         $v0, 0x14($a0)
    /* BCB0 8006F010 00000000 */  nop
    /* BCB4 8006F014 16004018 */  blez       $v0, .L8006F070
    /* BCB8 8006F018 00000000 */   nop
    /* BCBC 8006F01C 3000228E */  lw         $v0, 0x30($s1)
    /* BCC0 8006F020 00000000 */  nop
    /* BCC4 8006F024 40110200 */  sll        $v0, $v0, 5
    /* BCC8 8006F028 21182202 */  addu       $v1, $s1, $v0
    /* BCCC 8006F02C 5400628C */  lw         $v0, 0x54($v1)
    /* BCD0 8006F030 00000000 */  nop
    /* BCD4 8006F034 0E004010 */  beqz       $v0, .L8006F070
    /* BCD8 8006F038 00000000 */   nop
    /* BCDC 8006F03C 5000638C */  lw         $v1, 0x50($v1)
    /* BCE0 8006F040 00000000 */  nop
    /* BCE4 8006F044 C3FF6010 */  beqz       $v1, .L8006EF54
    /* BCE8 8006F048 0680023C */   lui       $v0, %hi(D_8005E628)
    /* BCEC 8006F04C 28E6428C */  lw         $v0, %lo(D_8005E628)($v0)
    /* BCF0 8006F050 00000000 */  nop
    /* BCF4 8006F054 2A104300 */  slt        $v0, $v0, $v1
    /* BCF8 8006F058 C0FF4014 */  bnez       $v0, .L8006EF5C
    /* BCFC 8006F05C 0E000424 */   addiu     $a0, $zero, 0xE
    /* BD00 8006F060 A369000C */  jal        Snd_PlayById
    /* BD04 8006F064 21280000 */   addu      $a1, $zero, $zero
    /* BD08 8006F068 5945000C */  jal        Task_NextState1
    /* BD0C 8006F06C 21204002 */   addu      $a0, $s2, $zero
  .L8006F070:
    /* BD10 8006F070 49BB010C */  jal        Stg20_UpgradeListRefresh
    /* BD14 8006F074 21204002 */   addu      $a0, $s2, $zero
    /* BD18 8006F078 7ABC0108 */  j          .L8006F1E8
    /* BD1C 8006F07C 00000000 */   nop
  .L8006F080:
    /* BD20 8006F080 1800508E */  lw         $s0, 0x18($s2)
    /* BD24 8006F084 00000000 */  nop
    /* BD28 8006F088 16000212 */  beq        $s0, $v0, .L8006F0E4
    /* BD2C 8006F08C 0200022A */   slti      $v0, $s0, 0x2
    /* BD30 8006F090 03004014 */  bnez       $v0, .L8006F0A0
    /* BD34 8006F094 02000224 */   addiu     $v0, $zero, 0x2
    /* BD38 8006F098 4C000212 */  beq        $s0, $v0, .L8006F1CC
    /* BD3C 8006F09C 0680023C */   lui       $v0, %hi(Pad_Cross)
  .L8006F0A0:
    /* BD40 8006F0A0 3000228E */  lw         $v0, 0x30($s1)
    /* BD44 8006F0A4 00000000 */  nop
    /* BD48 8006F0A8 40110200 */  sll        $v0, $v0, 5
    /* BD4C 8006F0AC 21102202 */  addu       $v0, $s1, $v0
    /* BD50 8006F0B0 5400448C */  lw         $a0, 0x54($v0)
    /* BD54 8006F0B4 1278000C */  jal        Item_GetNameText
    /* BD58 8006F0B8 01008424 */   addiu     $a0, $a0, 0x1
    /* BD5C 8006F0BC 10000424 */  addiu      $a0, $zero, 0x10
    /* BD60 8006F0C0 21280000 */  addu       $a1, $zero, $zero
    /* BD64 8006F0C4 000122AE */  sw         $v0, 0x100($s1)
    /* BD68 8006F0C8 7E010224 */  addiu      $v0, $zero, 0x17E
    /* BD6C 8006F0CC 7188000C */  jal        Flag_Set
    /* BD70 8006F0D0 FC0022AE */   sw        $v0, 0xFC($s1)
    /* BD74 8006F0D4 6045000C */  jal        Task_NextState2
    /* BD78 8006F0D8 21204002 */   addu      $a0, $s2, $zero
    /* BD7C 8006F0DC 7ABC0108 */  j          .L8006F1E8
    /* BD80 8006F0E0 00000000 */   nop
  .L8006F0E4:
    /* BD84 8006F0E4 9E87000C */  jal        Flag_Test
    /* BD88 8006F0E8 10000424 */   addiu     $a0, $zero, 0x10
    /* BD8C 8006F0EC 05004010 */  beqz       $v0, .L8006F104
    /* BD90 8006F0F0 0680023C */   lui       $v0, %hi(Pad_Triangle)
    /* BD94 8006F0F4 9E87000C */  jal        Flag_Test
    /* BD98 8006F0F8 11000424 */   addiu     $a0, $zero, 0x11
    /* BD9C 8006F0FC 11004010 */  beqz       $v0, .L8006F144
    /* BDA0 8006F100 0680023C */   lui       $v0, %hi(Pad_Triangle)
  .L8006F104:
    /* BDA4 8006F104 0CF7428C */  lw         $v0, %lo(Pad_Triangle)($v0)
    /* BDA8 8006F108 00000000 */  nop
    /* BDAC 8006F10C 0500401C */  bgtz       $v0, .L8006F124
    /* BDB0 8006F110 0B000424 */   addiu     $a0, $zero, 0xB
    /* BDB4 8006F114 9E87000C */  jal        Flag_Test
    /* BDB8 8006F118 10000424 */   addiu     $a0, $zero, 0x10
    /* BDBC 8006F11C 32004010 */  beqz       $v0, .L8006F1E8
    /* BDC0 8006F120 0B000424 */   addiu     $a0, $zero, 0xB
  .L8006F124:
    /* BDC4 8006F124 A369000C */  jal        Snd_PlayById
    /* BDC8 8006F128 21280000 */   addu      $a1, $zero, $zero
    /* BDCC 8006F12C 21204002 */  addu       $a0, $s2, $zero
    /* BDD0 8006F130 21280000 */  addu       $a1, $zero, $zero
    /* BDD4 8006F134 7C010224 */  addiu      $v0, $zero, 0x17C
    /* BDD8 8006F138 340030AE */  sw         $s0, 0x34($s1)
    /* BDDC 8006F13C 78BC0108 */  j          .L8006F1E0
    /* BDE0 8006F140 FC0022AE */   sw        $v0, 0xFC($s1)
  .L8006F144:
    /* BDE4 8006F144 14000424 */  addiu      $a0, $zero, 0x14
    /* BDE8 8006F148 A369000C */  jal        Snd_PlayById
    /* BDEC 8006F14C 21280000 */   addu      $a1, $zero, $zero
    /* BDF0 8006F150 0680043C */  lui        $a0, %hi(Save_GameState)
    /* BDF4 8006F154 20E68424 */  addiu      $a0, $a0, %lo(Save_GameState)
    /* BDF8 8006F158 3000238E */  lw         $v1, 0x30($s1)
    /* BDFC 8006F15C 0800828C */  lw         $v0, 0x8($a0)
    /* BE00 8006F160 40190300 */  sll        $v1, $v1, 5
    /* BE04 8006F164 21182302 */  addu       $v1, $s1, $v1
    /* BE08 8006F168 5000638C */  lw         $v1, 0x50($v1)
    /* BE0C 8006F16C 00000000 */  nop
    /* BE10 8006F170 23104300 */  subu       $v0, $v0, $v1
    /* BE14 8006F174 0780033C */  lui        $v1, %hi(Stg20_UpgradeSlots)
    /* BE18 8006F178 080082AC */  sw         $v0, 0x8($a0)
    /* BE1C 8006F17C 3000228E */  lw         $v0, 0x30($s1)
    /* BE20 8006F180 D4066324 */  addiu      $v1, $v1, %lo(Stg20_UpgradeSlots)
    /* BE24 8006F184 80100200 */  sll        $v0, $v0, 2
    /* BE28 8006F188 21104300 */  addu       $v0, $v0, $v1
    /* BE2C 8006F18C 0000438C */  lw         $v1, 0x0($v0)
    /* BE30 8006F190 00000000 */  nop
    /* BE34 8006F194 40180300 */  sll        $v1, $v1, 1
    /* BE38 8006F198 21186400 */  addu       $v1, $v1, $a0
    /* BE3C 8006F19C 2C006294 */  lhu        $v0, 0x2C($v1)
    /* BE40 8006F1A0 21204002 */  addu       $a0, $s2, $zero
    /* BE44 8006F1A4 01004224 */  addiu      $v0, $v0, 0x1
    /* BE48 8006F1A8 A4BA010C */  jal        Stg20_BuildUpgradeList
    /* BE4C 8006F1AC 2C0062A4 */   sh        $v0, 0x2C($v1)
    /* BE50 8006F1B0 21204002 */  addu       $a0, $s2, $zero
    /* BE54 8006F1B4 7F010224 */  addiu      $v0, $zero, 0x17F
    /* BE58 8006F1B8 340030AE */  sw         $s0, 0x34($s1)
    /* BE5C 8006F1BC 6045000C */  jal        Task_NextState2
    /* BE60 8006F1C0 FC0022AE */   sw        $v0, 0xFC($s1)
    /* BE64 8006F1C4 7ABC0108 */  j          .L8006F1E8
    /* BE68 8006F1C8 00000000 */   nop
  .L8006F1CC:
    /* BE6C 8006F1CC 04F7428C */  lw         $v0, %lo(Pad_Cross)($v0)
    /* BE70 8006F1D0 00000000 */  nop
    /* BE74 8006F1D4 04004018 */  blez       $v0, .L8006F1E8
    /* BE78 8006F1D8 21204002 */   addu      $a0, $s2, $zero
    /* BE7C 8006F1DC 21280000 */  addu       $a1, $zero, $zero
  .L8006F1E0:
    /* BE80 8006F1E0 7745000C */  jal        Task_SetState1
    /* BE84 8006F1E4 00000000 */   nop
  .L8006F1E8:
    /* BE88 8006F1E8 FC00238E */  lw         $v1, 0xFC($s1)
    /* BE8C 8006F1EC F800228E */  lw         $v0, 0xF8($s1)
    /* BE90 8006F1F0 00000000 */  nop
    /* BE94 8006F1F4 10006210 */  beq        $v1, $v0, .L8006F238
    /* BE98 8006F1F8 2C003026 */   addiu     $s0, $s1, 0x2C
    /* BE9C 8006F1FC 21200002 */  addu       $a0, $s0, $zero
    /* BEA0 8006F200 E26E000C */  jal        Text_Close
    /* BEA4 8006F204 F80023AE */   sw        $v1, 0xF8($s1)
    /* BEA8 8006F208 FC00258E */  lw         $a1, 0xFC($s1)
    /* BEAC 8006F20C 00000000 */  nop
    /* BEB0 8006F210 0900A010 */  beqz       $a1, .L8006F238
    /* BEB4 8006F214 21200002 */   addu      $a0, $s0, $zero
    /* BEB8 8006F218 0780023C */  lui        $v0, %hi(Stg20_UpgradeTextPos)
    /* BEBC 8006F21C A4064224 */  addiu      $v0, $v0, %lo(Stg20_UpgradeTextPos)
    /* BEC0 8006F220 0001278E */  lw         $a3, 0x100($s1)
    /* BEC4 8006F224 2E004694 */  lhu        $a2, 0x2E($v0)
    /* BEC8 8006F228 2C004294 */  lhu        $v0, 0x2C($v0)
    /* BECC 8006F22C 00340600 */  sll        $a2, $a2, 16
    /* BED0 8006F230 B0B4010C */  jal        Stg20_OpenMsgOrDesc
    /* BED4 8006F234 25304600 */   or        $a2, $v0, $a2
  .L8006F238:
    /* BED8 8006F238 2400BF8F */  lw         $ra, 0x24($sp)
    /* BEDC 8006F23C 2000B48F */  lw         $s4, 0x20($sp)
    /* BEE0 8006F240 1C00B38F */  lw         $s3, 0x1C($sp)
    /* BEE4 8006F244 1800B28F */  lw         $s2, 0x18($sp)
    /* BEE8 8006F248 1400B18F */  lw         $s1, 0x14($sp)
    /* BEEC 8006F24C 1000B08F */  lw         $s0, 0x10($sp)
    /* BEF0 8006F250 0800E003 */  jr         $ra
    /* BEF4 8006F254 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel Stg20_PartsUpgradeUpdate
