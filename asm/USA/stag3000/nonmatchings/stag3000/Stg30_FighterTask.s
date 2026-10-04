nonmatching Stg30_FighterTask, 0x5E0

glabel Stg30_FighterTask
    /* BBF0 8006EF50 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* BBF4 8006EF54 2000B2AF */  sw         $s2, 0x20($sp)
    /* BBF8 8006EF58 21908000 */  addu       $s2, $a0, $zero
    /* BBFC 8006EF5C 1800B0AF */  sw         $s0, 0x18($sp)
    /* BC00 8006EF60 01001024 */  addiu      $s0, $zero, 0x1
    /* BC04 8006EF64 2400BFAF */  sw         $ra, 0x24($sp)
    /* BC08 8006EF68 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* BC0C 8006EF6C 2C00518E */  lw         $s1, 0x2C($s2)
    /* BC10 8006EF70 1000438E */  lw         $v1, 0x10($s2)
    /* BC14 8006EF74 3C00468E */  lw         $a2, 0x3C($s2)
    /* BC18 8006EF78 31017010 */  beq        $v1, $s0, .L8006F440
    /* BC1C 8006EF7C 02006228 */   slti      $v0, $v1, 0x2
    /* BC20 8006EF80 05004010 */  beqz       $v0, .L8006EF98
    /* BC24 8006EF84 02000224 */   addiu     $v0, $zero, 0x2
    /* BC28 8006EF88 07006010 */  beqz       $v1, .L8006EFA8
    /* BC2C 8006EF8C 21204002 */   addu      $a0, $s2, $zero
    /* BC30 8006EF90 10BD0108 */  j          .L8006F440
    /* BC34 8006EF94 00000000 */   nop
  .L8006EF98:
    /* BC38 8006EF98 2F006210 */  beq        $v1, $v0, .L8006F058
    /* BC3C 8006EF9C 00000000 */   nop
    /* BC40 8006EFA0 10BD0108 */  j          .L8006F440
    /* BC44 8006EFA4 00000000 */   nop
  .L8006EFA8:
    /* BC48 8006EFA8 10002696 */  lhu        $a2, 0x10($s1)
    /* BC4C 8006EFAC 1083000C */  jal        Actor_InitTransform
    /* BC50 8006EFB0 04002526 */   addiu     $a1, $s1, 0x4
    /* BC54 8006EFB4 1400258E */  lw         $a1, 0x14($s1)
    /* BC58 8006EFB8 6F7F000C */  jal        Gfx_AttachModel
    /* BC5C 8006EFBC 21204002 */   addu      $a0, $s2, $zero
    /* BC60 8006EFC0 21204002 */  addu       $a0, $s2, $zero
    /* BC64 8006EFC4 21280000 */  addu       $a1, $zero, $zero
    /* BC68 8006EFC8 03000324 */  addiu      $v1, $zero, 0x3
    /* BC6C 8006EFCC 3C0043AC */  sw         $v1, 0x3C($v0)
    /* BC70 8006EFD0 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* BC74 8006EFD4 14BA010C */  jal        Stg30_FighterSetAnim
    /* BC78 8006EFD8 340022AE */   sw        $v0, 0x34($s1)
    /* BC7C 8006EFDC 06000424 */  addiu      $a0, $zero, 0x6
    /* BC80 8006EFE0 1000B2AF */  sw         $s2, 0x10($sp)
    /* BC84 8006EFE4 3400458E */  lw         $a1, 0x34($s2)
    /* BC88 8006EFE8 1000A627 */  addiu      $a2, $sp, 0x10
    /* BC8C 8006EFEC 1F44000C */  jal        Task_Create
    /* BC90 8006EFF0 1000A524 */   addiu     $a1, $a1, 0x10
    /* BC94 8006EFF4 01050424 */  addiu      $a0, $zero, 0x501
    /* BC98 8006EFF8 3400458E */  lw         $a1, 0x34($s2)
    /* BC9C 8006EFFC 1400A627 */  addiu      $a2, $sp, 0x14
    /* BCA0 8006F000 1F44000C */  jal        Task_Create
    /* BCA4 8006F004 1400B2AF */   sw        $s2, 0x14($sp)
    /* BCA8 8006F008 3C00438E */  lw         $v1, 0x3C($s2)
    /* BCAC 8006F00C 80000224 */  addiu      $v0, $zero, 0x80
    /* BCB0 8006F010 180030AE */  sw         $s0, 0x18($s1)
    /* BCB4 8006F014 1C0020AE */  sw         $zero, 0x1C($s1)
    /* BCB8 8006F018 3A0062A0 */  sb         $v0, 0x3A($v1)
    /* BCBC 8006F01C 390062A0 */  sb         $v0, 0x39($v1)
    /* BCC0 8006F020 380062A0 */  sb         $v0, 0x38($v1)
    /* BCC4 8006F024 3800228E */  lw         $v0, 0x38($s1)
    /* BCC8 8006F028 220020A2 */  sb         $zero, 0x22($s1)
    /* BCCC 8006F02C 210020A2 */  sb         $zero, 0x21($s1)
    /* BCD0 8006F030 200020A2 */  sb         $zero, 0x20($s1)
    /* BCD4 8006F034 04004010 */  beqz       $v0, .L8006F048
    /* BCD8 8006F038 280030AE */   sw        $s0, 0x28($s1)
    /* BCDC 8006F03C 21204002 */  addu       $a0, $s2, $zero
    /* BCE0 8006F040 14BA010C */  jal        Stg30_FighterSetAnim
    /* BCE4 8006F044 64000524 */   addiu     $a1, $zero, 0x64
  .L8006F048:
    /* BCE8 8006F048 5145000C */  jal        Task_NextState0
    /* BCEC 8006F04C 21204002 */   addu      $a0, $s2, $zero
    /* BCF0 8006F050 10BD0108 */  j          .L8006F440
    /* BCF4 8006F054 00000000 */   nop
  .L8006F058:
    /* BCF8 8006F058 1400438E */  lw         $v1, 0x14($s2)
    /* BCFC 8006F05C 00000000 */  nop
    /* BD00 8006F060 0E00622C */  sltiu      $v0, $v1, 0xE
    /* BD04 8006F064 08004010 */  beqz       $v0, .L8006F088
    /* BD08 8006F068 0680023C */   lui       $v0, %hi(jtbl_8006379C)
    /* BD0C 8006F06C 9C374224 */  addiu      $v0, $v0, %lo(jtbl_8006379C)
    /* BD10 8006F070 80180300 */  sll        $v1, $v1, 2
    /* BD14 8006F074 21186200 */  addu       $v1, $v1, $v0
    /* BD18 8006F078 0000628C */  lw         $v0, 0x0($v1)
    /* BD1C 8006F07C 00000000 */  nop
    /* BD20 8006F080 08004000 */  jr         $v0
    /* BD24 8006F084 00000000 */   nop
  jlabel .L8006F088
    /* BD28 8006F088 21204002 */  addu       $a0, $s2, $zero
    /* BD2C 8006F08C 14BA010C */  jal        Stg30_FighterSetAnim
    /* BD30 8006F090 21280000 */   addu      $a1, $zero, $zero
    /* BD34 8006F094 21204002 */  addu       $a0, $s2, $zero
    /* BD38 8006F098 0EBD0108 */  j          .L8006F438
    /* BD3C 8006F09C 01000524 */   addiu     $a1, $zero, 0x1
  jlabel .L8006F0A0
    /* BD40 8006F0A0 1800438E */  lw         $v1, 0x18($s2)
    /* BD44 8006F0A4 00000000 */  nop
    /* BD48 8006F0A8 03006010 */  beqz       $v1, .L8006F0B8
    /* BD4C 8006F0AC 01000224 */   addiu     $v0, $zero, 0x1
    /* BD50 8006F0B0 0A006210 */  beq        $v1, $v0, .L8006F0DC
    /* BD54 8006F0B4 00000000 */   nop
  .L8006F0B8:
    /* BD58 8006F0B8 2000428E */  lw         $v0, 0x20($s2)
    /* BD5C 8006F0BC 21204002 */  addu       $a0, $s2, $zero
    /* BD60 8006F0C0 C9BA010C */  jal        Stg30_SpawnSkillHitFx
    /* BD64 8006F0C4 2C0022AE */   sw        $v0, 0x2C($s1)
    /* BD68 8006F0C8 21204002 */  addu       $a0, $s2, $zero
    /* BD6C 8006F0CC 6045000C */  jal        Task_NextState2
    /* BD70 8006F0D0 280040AE */   sw        $zero, 0x28($s2)
    /* BD74 8006F0D4 10BD0108 */  j          .L8006F440
    /* BD78 8006F0D8 00000000 */   nop
  .L8006F0DC:
    /* BD7C 8006F0DC 2800428E */  lw         $v0, 0x28($s2)
    /* BD80 8006F0E0 00000000 */  nop
    /* BD84 8006F0E4 78004228 */  slti       $v0, $v0, 0x78
    /* BD88 8006F0E8 D5004014 */  bnez       $v0, .L8006F440
    /* BD8C 8006F0EC 21204002 */   addu      $a0, $s2, $zero
    /* BD90 8006F0F0 0EBD0108 */  j          .L8006F438
    /* BD94 8006F0F4 01000524 */   addiu     $a1, $zero, 0x1
  jlabel .L8006F0F8
    /* BD98 8006F0F8 1800438E */  lw         $v1, 0x18($s2)
    /* BD9C 8006F0FC 00000000 */  nop
    /* BDA0 8006F100 03006010 */  beqz       $v1, .L8006F110
    /* BDA4 8006F104 01000224 */   addiu     $v0, $zero, 0x1
    /* BDA8 8006F108 48006210 */  beq        $v1, $v0, .L8006F22C
    /* BDAC 8006F10C 00000000 */   nop
  .L8006F110:
    /* BDB0 8006F110 21204002 */  addu       $a0, $s2, $zero
    /* BDB4 8006F114 85BC0108 */  j          .L8006F214
    /* BDB8 8006F118 5A000524 */   addiu     $a1, $zero, 0x5A
  jlabel .L8006F11C
    /* BDBC 8006F11C 1800438E */  lw         $v1, 0x18($s2)
    /* BDC0 8006F120 00000000 */  nop
    /* BDC4 8006F124 03006010 */  beqz       $v1, .L8006F134
    /* BDC8 8006F128 01000224 */   addiu     $v0, $zero, 0x1
    /* BDCC 8006F12C 3F006210 */  beq        $v1, $v0, .L8006F22C
    /* BDD0 8006F130 00000000 */   nop
  .L8006F134:
    /* BDD4 8006F134 2000428E */  lw         $v0, 0x20($s2)
    /* BDD8 8006F138 21204002 */  addu       $a0, $s2, $zero
    /* BDDC 8006F13C C9BA010C */  jal        Stg30_SpawnSkillHitFx
    /* BDE0 8006F140 2C0022AE */   sw        $v0, 0x2C($s1)
    /* BDE4 8006F144 3400228E */  lw         $v0, 0x34($s1)
    /* BDE8 8006F148 00000000 */  nop
    /* BDEC 8006F14C 03004014 */  bnez       $v0, .L8006F15C
    /* BDF0 8006F150 21204002 */   addu      $a0, $s2, $zero
    /* BDF4 8006F154 0EBD0108 */  j          .L8006F438
    /* BDF8 8006F158 01000524 */   addiu     $a1, $zero, 0x1
  .L8006F15C:
    /* BDFC 8006F15C 85BC0108 */  j          .L8006F214
    /* BE00 8006F160 5A000524 */   addiu     $a1, $zero, 0x5A
  jlabel .L8006F164
    /* BE04 8006F164 2000448E */  lw         $a0, 0x20($s2)
    /* BE08 8006F168 847B000C */  jal        Skill_GetCastAnim
    /* BE0C 8006F16C 2C0024AE */   sw        $a0, 0x2C($s1)
    /* BE10 8006F170 21204002 */  addu       $a0, $s2, $zero
    /* BE14 8006F174 21804000 */  addu       $s0, $v0, $zero
    /* BE18 8006F178 5EBA010C */  jal        Stg30_SpawnSkillCastFx
    /* BE1C 8006F17C 21280002 */   addu      $a1, $s0, $zero
    /* BE20 8006F180 01000224 */  addiu      $v0, $zero, 0x1
    /* BE24 8006F184 08000212 */  beq        $s0, $v0, .L8006F1A8
    /* BE28 8006F188 0200022A */   slti      $v0, $s0, 0x2
    /* BE2C 8006F18C 04004014 */  bnez       $v0, .L8006F1A0
    /* BE30 8006F190 21204002 */   addu      $a0, $s2, $zero
    /* BE34 8006F194 02000224 */  addiu      $v0, $zero, 0x2
    /* BE38 8006F198 06000212 */  beq        $s0, $v0, .L8006F1B4
    /* BE3C 8006F19C 00000000 */   nop
  .L8006F1A0:
    /* BE40 8006F1A0 6EBC0108 */  j          .L8006F1B8
    /* BE44 8006F1A4 32000524 */   addiu     $a1, $zero, 0x32
  .L8006F1A8:
    /* BE48 8006F1A8 21204002 */  addu       $a0, $s2, $zero
    /* BE4C 8006F1AC 6EBC0108 */  j          .L8006F1B8
    /* BE50 8006F1B0 3C000524 */   addiu     $a1, $zero, 0x3C
  .L8006F1B4:
    /* BE54 8006F1B4 46000524 */  addiu      $a1, $zero, 0x46
  .L8006F1B8:
    /* BE58 8006F1B8 14BA010C */  jal        Stg30_FighterSetAnim
    /* BE5C 8006F1BC 00000000 */   nop
    /* BE60 8006F1C0 21204002 */  addu       $a0, $s2, $zero
    /* BE64 8006F1C4 0EBD0108 */  j          .L8006F438
    /* BE68 8006F1C8 01000524 */   addiu     $a1, $zero, 0x1
  jlabel .L8006F1CC
    /* BE6C 8006F1CC 21204002 */  addu       $a0, $s2, $zero
    /* BE70 8006F1D0 14BA010C */  jal        Stg30_FighterSetAnim
    /* BE74 8006F1D4 50000524 */   addiu     $a1, $zero, 0x50
    /* BE78 8006F1D8 21204002 */  addu       $a0, $s2, $zero
    /* BE7C 8006F1DC 0EBD0108 */  j          .L8006F438
    /* BE80 8006F1E0 01000524 */   addiu     $a1, $zero, 0x1
  jlabel .L8006F1E4
    /* BE84 8006F1E4 1800438E */  lw         $v1, 0x18($s2)
    /* BE88 8006F1E8 00000000 */  nop
    /* BE8C 8006F1EC 03006010 */  beqz       $v1, .L8006F1FC
    /* BE90 8006F1F0 01000224 */   addiu     $v0, $zero, 0x1
    /* BE94 8006F1F4 0D006210 */  beq        $v1, $v0, .L8006F22C
    /* BE98 8006F1F8 00000000 */   nop
  .L8006F1FC:
    /* BE9C 8006F1FC 2000428E */  lw         $v0, 0x20($s2)
    /* BEA0 8006F200 21204002 */  addu       $a0, $s2, $zero
    /* BEA4 8006F204 C9BA010C */  jal        Stg30_SpawnSkillHitFx
    /* BEA8 8006F208 2C0022AE */   sw        $v0, 0x2C($s1)
    /* BEAC 8006F20C 21204002 */  addu       $a0, $s2, $zero
    /* BEB0 8006F210 0A000524 */  addiu      $a1, $zero, 0xA
  .L8006F214:
    /* BEB4 8006F214 14BA010C */  jal        Stg30_FighterSetAnim
    /* BEB8 8006F218 00000000 */   nop
    /* BEBC 8006F21C 6045000C */  jal        Task_NextState2
    /* BEC0 8006F220 21204002 */   addu      $a0, $s2, $zero
    /* BEC4 8006F224 10BD0108 */  j          .L8006F440
    /* BEC8 8006F228 00000000 */   nop
  .L8006F22C:
    /* BECC 8006F22C 3C00428E */  lw         $v0, 0x3C($s2)
    /* BED0 8006F230 00000000 */  nop
    /* BED4 8006F234 6000428C */  lw         $v0, 0x60($v0)
    /* BED8 8006F238 00000000 */  nop
    /* BEDC 8006F23C 80004104 */  bgez       $v0, .L8006F440
    /* BEE0 8006F240 21204002 */   addu      $a0, $s2, $zero
    /* BEE4 8006F244 7745000C */  jal        Task_SetState1
    /* BEE8 8006F248 21280000 */   addu      $a1, $zero, $zero
    /* BEEC 8006F24C 10BD0108 */  j          .L8006F440
    /* BEF0 8006F250 00000000 */   nop
  jlabel .L8006F254
    /* BEF4 8006F254 1800438E */  lw         $v1, 0x18($s2)
    /* BEF8 8006F258 00000000 */  nop
    /* BEFC 8006F25C 03006010 */  beqz       $v1, .L8006F26C
    /* BF00 8006F260 01000224 */   addiu     $v0, $zero, 0x1
    /* BF04 8006F264 07006210 */  beq        $v1, $v0, .L8006F284
    /* BF08 8006F268 00000000 */   nop
  .L8006F26C:
    /* BF0C 8006F26C 2000428E */  lw         $v0, 0x20($s2)
    /* BF10 8006F270 21204002 */  addu       $a0, $s2, $zero
    /* BF14 8006F274 C9BA010C */  jal        Stg30_SpawnSkillHitFx
    /* BF18 8006F278 2C0022AE */   sw        $v0, 0x2C($s1)
    /* BF1C 8006F27C 6045000C */  jal        Task_NextState2
    /* BF20 8006F280 21204002 */   addu      $a0, $s2, $zero
  .L8006F284:
    /* BF24 8006F284 1400458E */  lw         $a1, 0x14($s2)
    /* BF28 8006F288 21204002 */  addu       $a0, $s2, $zero
    /* BF2C 8006F28C 25BB010C */  jal        Stg30_HitReactUpdate
    /* BF30 8006F290 FCFFA524 */   addiu     $a1, $a1, -0x4
    /* BF34 8006F294 10BD0108 */  j          .L8006F440
    /* BF38 8006F298 00000000 */   nop
  jlabel .L8006F29C
    /* BF3C 8006F29C 2000428E */  lw         $v0, 0x20($s2)
    /* BF40 8006F2A0 21204002 */  addu       $a0, $s2, $zero
    /* BF44 8006F2A4 C9BA010C */  jal        Stg30_SpawnSkillHitFx
    /* BF48 8006F2A8 2C0022AE */   sw        $v0, 0x2C($s1)
    /* BF4C 8006F2AC 3C00428E */  lw         $v0, 0x3C($s2)
    /* BF50 8006F2B0 00000000 */  nop
    /* BF54 8006F2B4 5400428C */  lw         $v0, 0x54($v0)
    /* BF58 8006F2B8 00000000 */  nop
    /* BF5C 8006F2BC 03004010 */  beqz       $v0, .L8006F2CC
    /* BF60 8006F2C0 21204002 */   addu      $a0, $s2, $zero
    /* BF64 8006F2C4 14BA010C */  jal        Stg30_FighterSetAnim
    /* BF68 8006F2C8 21280000 */   addu      $a1, $zero, $zero
  .L8006F2CC:
    /* BF6C 8006F2CC 21204002 */  addu       $a0, $s2, $zero
    /* BF70 8006F2D0 0EBD0108 */  j          .L8006F438
    /* BF74 8006F2D4 01000524 */   addiu     $a1, $zero, 0x1
  jlabel .L8006F2D8
    /* BF78 8006F2D8 01000224 */  addiu      $v0, $zero, 0x1
    /* BF7C 8006F2DC 180022AE */  sw         $v0, 0x18($s1)
    /* BF80 8006F2E0 1C0022AE */  sw         $v0, 0x1C($s1)
    /* BF84 8006F2E4 3800C390 */  lbu        $v1, 0x38($a2)
    /* BF88 8006F2E8 3400C2A4 */  sh         $v0, 0x34($a2)
    /* BF8C 8006F2EC 20000224 */  addiu      $v0, $zero, 0x20
    /* BF90 8006F2F0 3600C2A4 */  sh         $v0, 0x36($a2)
    /* BF94 8006F2F4 0900622C */  sltiu      $v0, $v1, 0x9
    /* BF98 8006F2F8 03004014 */  bnez       $v0, .L8006F308
    /* BF9C 8006F2FC F8FF6224 */   addiu     $v0, $v1, -0x8
    /* BFA0 8006F300 C3BC0108 */  j          .L8006F30C
    /* BFA4 8006F304 3800C2A0 */   sb        $v0, 0x38($a2)
  .L8006F308:
    /* BFA8 8006F308 3800C0A0 */  sb         $zero, 0x38($a2)
  .L8006F30C:
    /* BFAC 8006F30C 3800C290 */  lbu        $v0, 0x38($a2)
    /* BFB0 8006F310 00000000 */  nop
    /* BFB4 8006F314 3A00C2A0 */  sb         $v0, 0x3A($a2)
    /* BFB8 8006F318 3900C2A0 */  sb         $v0, 0x39($a2)
    /* BFBC 8006F31C 21002392 */  lbu        $v1, 0x21($s1)
    /* BFC0 8006F320 00000000 */  nop
    /* BFC4 8006F324 EF00622C */  sltiu      $v0, $v1, 0xEF
    /* BFC8 8006F328 02004014 */  bnez       $v0, .L8006F334
    /* BFCC 8006F32C 10006224 */   addiu     $v0, $v1, 0x10
    /* BFD0 8006F330 FF000224 */  addiu      $v0, $zero, 0xFF
  .L8006F334:
    /* BFD4 8006F334 210022A2 */  sb         $v0, 0x21($s1)
    /* BFD8 8006F338 3800C290 */  lbu        $v0, 0x38($a2)
    /* BFDC 8006F33C 00000000 */  nop
    /* BFE0 8006F340 3F004014 */  bnez       $v0, .L8006F440
    /* BFE4 8006F344 FF000224 */   addiu     $v0, $zero, 0xFF
    /* BFE8 8006F348 21002392 */  lbu        $v1, 0x21($s1)
    /* BFEC 8006F34C 00000000 */  nop
    /* BFF0 8006F350 3B006214 */  bne        $v1, $v0, .L8006F440
    /* BFF4 8006F354 21204002 */   addu      $a0, $s2, $zero
    /* BFF8 8006F358 01000524 */  addiu      $a1, $zero, 0x1
    /* BFFC 8006F35C 3400C0A4 */  sh         $zero, 0x34($a2)
    /* C000 8006F360 3600C0A4 */  sh         $zero, 0x36($a2)
    /* C004 8006F364 0EBD0108 */  j          .L8006F438
    /* C008 8006F368 180020AE */   sw        $zero, 0x18($s1)
  jlabel .L8006F36C
    /* C00C 8006F36C 01000224 */  addiu      $v0, $zero, 0x1
    /* C010 8006F370 180022AE */  sw         $v0, 0x18($s1)
    /* C014 8006F374 1C0022AE */  sw         $v0, 0x1C($s1)
    /* C018 8006F378 3800C390 */  lbu        $v1, 0x38($a2)
    /* C01C 8006F37C 3400C2A4 */  sh         $v0, 0x34($a2)
    /* C020 8006F380 20000224 */  addiu      $v0, $zero, 0x20
    /* C024 8006F384 3600C2A4 */  sh         $v0, 0x36($a2)
    /* C028 8006F388 7800622C */  sltiu      $v0, $v1, 0x78
    /* C02C 8006F38C 02004014 */  bnez       $v0, .L8006F398
    /* C030 8006F390 08006224 */   addiu     $v0, $v1, 0x8
    /* C034 8006F394 80000224 */  addiu      $v0, $zero, 0x80
  .L8006F398:
    /* C038 8006F398 3800C2A0 */  sb         $v0, 0x38($a2)
    /* C03C 8006F39C 3800C290 */  lbu        $v0, 0x38($a2)
    /* C040 8006F3A0 00000000 */  nop
    /* C044 8006F3A4 3A00C2A0 */  sb         $v0, 0x3A($a2)
    /* C048 8006F3A8 3900C2A0 */  sb         $v0, 0x39($a2)
    /* C04C 8006F3AC 21002392 */  lbu        $v1, 0x21($s1)
    /* C050 8006F3B0 00000000 */  nop
    /* C054 8006F3B4 1100622C */  sltiu      $v0, $v1, 0x11
    /* C058 8006F3B8 03004014 */  bnez       $v0, .L8006F3C8
    /* C05C 8006F3BC F0FF6224 */   addiu     $v0, $v1, -0x10
    /* C060 8006F3C0 F3BC0108 */  j          .L8006F3CC
    /* C064 8006F3C4 210022A2 */   sb        $v0, 0x21($s1)
  .L8006F3C8:
    /* C068 8006F3C8 210020A2 */  sb         $zero, 0x21($s1)
  .L8006F3CC:
    /* C06C 8006F3CC 3800C390 */  lbu        $v1, 0x38($a2)
    /* C070 8006F3D0 80000224 */  addiu      $v0, $zero, 0x80
    /* C074 8006F3D4 1A006214 */  bne        $v1, $v0, .L8006F440
    /* C078 8006F3D8 00000000 */   nop
    /* C07C 8006F3DC 21002292 */  lbu        $v0, 0x21($s1)
    /* C080 8006F3E0 00000000 */  nop
    /* C084 8006F3E4 16004014 */  bnez       $v0, .L8006F440
    /* C088 8006F3E8 21204002 */   addu      $a0, $s2, $zero
    /* C08C 8006F3EC 01000524 */  addiu      $a1, $zero, 0x1
    /* C090 8006F3F0 3400C0A4 */  sh         $zero, 0x34($a2)
    /* C094 8006F3F4 3600C0A4 */  sh         $zero, 0x36($a2)
    /* C098 8006F3F8 0EBD0108 */  j          .L8006F438
    /* C09C 8006F3FC 1C0020AE */   sw        $zero, 0x1C($s1)
  jlabel .L8006F400
    /* C0A0 8006F400 10BD0108 */  j          .L8006F440
    /* C0A4 8006F404 280020AE */   sw        $zero, 0x28($s1)
  jlabel .L8006F408
    /* C0A8 8006F408 21204002 */  addu       $a0, $s2, $zero
    /* C0AC 8006F40C 01000524 */  addiu      $a1, $zero, 0x1
    /* C0B0 8006F410 80000224 */  addiu      $v0, $zero, 0x80
    /* C0B4 8006F414 3A00C2A0 */  sb         $v0, 0x3A($a2)
    /* C0B8 8006F418 3900C2A0 */  sb         $v0, 0x39($a2)
    /* C0BC 8006F41C 3800C2A0 */  sb         $v0, 0x38($a2)
    /* C0C0 8006F420 2110A000 */  addu       $v0, $a1, $zero
    /* C0C4 8006F424 3400C0A4 */  sh         $zero, 0x34($a2)
    /* C0C8 8006F428 3600C0A4 */  sh         $zero, 0x36($a2)
    /* C0CC 8006F42C 180022AE */  sw         $v0, 0x18($s1)
    /* C0D0 8006F430 1C0020AE */  sw         $zero, 0x1C($s1)
    /* C0D4 8006F434 280022AE */  sw         $v0, 0x28($s1)
  .L8006F438:
    /* C0D8 8006F438 7045000C */  jal        Task_SetState0
    /* C0DC 8006F43C 00000000 */   nop
  .L8006F440:
    /* C0E0 8006F440 2800228E */  lw         $v0, 0x28($s1)
    /* C0E4 8006F444 00000000 */  nop
    /* C0E8 8006F448 02004014 */  bnez       $v0, .L8006F454
    /* C0EC 8006F44C 05000224 */   addiu     $v0, $zero, 0x5
    /* C0F0 8006F450 04000224 */  addiu      $v0, $zero, 0x4
  .L8006F454:
    /* C0F4 8006F454 300042AE */  sw         $v0, 0x30($s2)
    /* C0F8 8006F458 0780023C */  lui        $v0, %hi(D_80074094)
    /* C0FC 8006F45C 2400238E */  lw         $v1, 0x24($s1)
    /* C100 8006F460 9440428C */  lw         $v0, %lo(D_80074094)($v0)
    /* C104 8006F464 00000000 */  nop
    /* C108 8006F468 1A006210 */  beq        $v1, $v0, .L8006F4D4
    /* C10C 8006F46C 00000000 */   nop
    /* C110 8006F470 3400448E */  lw         $a0, 0x34($s2)
    /* C114 8006F474 0B004010 */  beqz       $v0, .L8006F4A4
    /* C118 8006F478 02000224 */   addiu     $v0, $zero, 0x2
    /* C11C 8006F47C 0000848C */  lw         $a0, 0x0($a0)
    /* C120 8006F480 00000000 */  nop
    /* C124 8006F484 1000838C */  lw         $v1, 0x10($a0)
    /* C128 8006F488 00000000 */  nop
    /* C12C 8006F48C 0E006214 */  bne        $v1, $v0, .L8006F4C8
    /* C130 8006F490 0780023C */   lui       $v0, %hi(D_80074094)
    /* C134 8006F494 7745000C */  jal        Task_SetState1
    /* C138 8006F498 01000524 */   addiu     $a1, $zero, 0x1
    /* C13C 8006F49C 32BD0108 */  j          .L8006F4C8
    /* C140 8006F4A0 0780023C */   lui       $v0, %hi(D_80074094)
  .L8006F4A4:
    /* C144 8006F4A4 0000848C */  lw         $a0, 0x0($a0)
    /* C148 8006F4A8 00000000 */  nop
    /* C14C 8006F4AC 1000838C */  lw         $v1, 0x10($a0)
    /* C150 8006F4B0 01000224 */  addiu      $v0, $zero, 0x1
    /* C154 8006F4B4 04006214 */  bne        $v1, $v0, .L8006F4C8
    /* C158 8006F4B8 0780023C */   lui       $v0, %hi(D_80074094)
    /* C15C 8006F4BC 7045000C */  jal        Task_SetState0
    /* C160 8006F4C0 02000524 */   addiu     $a1, $zero, 0x2
    /* C164 8006F4C4 0780023C */  lui        $v0, %hi(D_80074094)
  .L8006F4C8:
    /* C168 8006F4C8 9440428C */  lw         $v0, %lo(D_80074094)($v0)
    /* C16C 8006F4CC 00000000 */  nop
    /* C170 8006F4D0 240022AE */  sw         $v0, 0x24($s1)
  .L8006F4D4:
    /* C174 8006F4D4 3000238E */  lw         $v1, 0x30($s1)
    /* C178 8006F4D8 00000000 */  nop
    /* C17C 8006F4DC 0E006010 */  beqz       $v1, .L8006F518
    /* C180 8006F4E0 FFFF6324 */   addiu     $v1, $v1, -0x1
    /* C184 8006F4E4 01000224 */  addiu      $v0, $zero, 0x1
    /* C188 8006F4E8 0B006214 */  bne        $v1, $v0, .L8006F518
    /* C18C 8006F4EC 300023AE */   sw        $v1, 0x30($s1)
    /* C190 8006F4F0 3800428E */  lw         $v0, 0x38($s2)
    /* C194 8006F4F4 0400238E */  lw         $v1, 0x4($s1)
    /* C198 8006F4F8 21204002 */  addu       $a0, $s2, $zero
    /* C19C 8006F4FC 300043AC */  sw         $v1, 0x30($v0)
    /* C1A0 8006F500 0C00238E */  lw         $v1, 0xC($s1)
    /* C1A4 8006F504 02000524 */  addiu      $a1, $zero, 0x2
    /* C1A8 8006F508 500040AC */  sw         $zero, 0x50($v0)
    /* C1AC 8006F50C 480040AC */  sw         $zero, 0x48($v0)
    /* C1B0 8006F510 BA83000C */  jal        Actor_StopAxisMotion
    /* C1B4 8006F514 380043AC */   sw        $v1, 0x38($v0)
  .L8006F518:
    /* C1B8 8006F518 2400BF8F */  lw         $ra, 0x24($sp)
    /* C1BC 8006F51C 2000B28F */  lw         $s2, 0x20($sp)
    /* C1C0 8006F520 1C00B18F */  lw         $s1, 0x1C($sp)
    /* C1C4 8006F524 1800B08F */  lw         $s0, 0x18($sp)
    /* C1C8 8006F528 0800E003 */  jr         $ra
    /* C1CC 8006F52C 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel Stg30_FighterTask
