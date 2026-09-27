nonmatching Gfx_DrawFade, 0x1DC

glabel Gfx_DrawFade
    /* CD84 8001C584 0680023C */  lui        $v0, %hi(D_8005F770)
    /* CD88 8001C588 70F74324 */  addiu      $v1, $v0, %lo(D_8005F770)
    /* CD8C 8001C58C 2C00628C */  lw         $v0, 0x2C($v1)
    /* CD90 8001C590 00000000 */  nop
    /* CD94 8001C594 70004010 */  beqz       $v0, .L8001C758
    /* CD98 8001C598 0480053C */   lui       $a1, %hi(Gfx_FadeState)
    /* CD9C 8001C59C 6415A824 */  addiu      $t0, $a1, %lo(Gfx_FadeState)
    /* CDA0 8001C5A0 01000724 */  addiu      $a3, $zero, 0x1
    /* CDA4 8001C5A4 02000A24 */  addiu      $t2, $zero, 0x2
    /* CDA8 8001C5A8 03000924 */  addiu      $t1, $zero, 0x3
    /* CDAC 8001C5AC 21206000 */  addu       $a0, $v1, $zero
    /* CDB0 8001C5B0 FF000624 */  addiu      $a2, $zero, 0xFF
  .L8001C5B4:
    /* CDB4 8001C5B4 6415A38C */  lw         $v1, %lo(Gfx_FadeState)($a1)
    /* CDB8 8001C5B8 00000000 */  nop
    /* CDBC 8001C5BC 09006710 */  beq        $v1, $a3, .L8001C5E4
    /* CDC0 8001C5C0 02006228 */   slti      $v0, $v1, 0x2
    /* CDC4 8001C5C4 05004014 */  bnez       $v0, .L8001C5DC
    /* CDC8 8001C5C8 00000000 */   nop
    /* CDCC 8001C5CC 07006A10 */  beq        $v1, $t2, .L8001C5EC
    /* CDD0 8001C5D0 00000000 */   nop
    /* CDD4 8001C5D4 0E006910 */  beq        $v1, $t1, .L8001C610
    /* CDD8 8001C5D8 00000000 */   nop
  .L8001C5DC:
    /* CDDC 8001C5DC 0800E003 */  jr         $ra
    /* CDE0 8001C5E0 100080AC */   sw        $zero, 0x10($a0)
  .L8001C5E4:
    /* CDE4 8001C5E4 8F710008 */  j          .L8001C63C
    /* CDE8 8001C5E8 100086AC */   sw        $a2, 0x10($a0)
  .L8001C5EC:
    /* CDEC 8001C5EC 1000838C */  lw         $v1, 0x10($a0)
    /* CDF0 8001C5F0 0400028D */  lw         $v0, 0x4($t0)
    /* CDF4 8001C5F4 00000000 */  nop
    /* CDF8 8001C5F8 23186200 */  subu       $v1, $v1, $v0
    /* CDFC 8001C5FC 1400601C */  bgtz       $v1, .L8001C650
    /* CE00 8001C600 100083AC */   sw        $v1, 0x10($a0)
    /* CE04 8001C604 100080AC */  sw         $zero, 0x10($a0)
    /* CE08 8001C608 6D710008 */  j          .L8001C5B4
    /* CE0C 8001C60C 6415A0AC */   sw        $zero, %lo(Gfx_FadeState)($a1)
  .L8001C610:
    /* CE10 8001C610 1000828C */  lw         $v0, 0x10($a0)
    /* CE14 8001C614 0400038D */  lw         $v1, 0x4($t0)
    /* CE18 8001C618 00000000 */  nop
    /* CE1C 8001C61C 21104300 */  addu       $v0, $v0, $v1
    /* CE20 8001C620 100082AC */  sw         $v0, 0x10($a0)
    /* CE24 8001C624 FF004228 */  slti       $v0, $v0, 0xFF
    /* CE28 8001C628 05004014 */  bnez       $v0, .L8001C640
    /* CE2C 8001C62C 0680023C */   lui       $v0, %hi(D_8005F780)
    /* CE30 8001C630 100086AC */  sw         $a2, 0x10($a0)
    /* CE34 8001C634 6D710008 */  j          .L8001C5B4
    /* CE38 8001C638 6415A7AC */   sw        $a3, %lo(Gfx_FadeState)($a1)
  .L8001C63C:
    /* CE3C 8001C63C 0680023C */  lui        $v0, %hi(D_8005F780)
  .L8001C640:
    /* CE40 8001C640 80F7428C */  lw         $v0, %lo(D_8005F780)($v0)
    /* CE44 8001C644 00000000 */  nop
    /* CE48 8001C648 43004010 */  beqz       $v0, .L8001C758
    /* CE4C 8001C64C 00000000 */   nop
  .L8001C650:
    /* CE50 8001C650 0680023C */  lui        $v0, %hi(D_8005F770)
    /* CE54 8001C654 70F74A24 */  addiu      $t2, $v0, %lo(D_8005F770)
    /* CE58 8001C658 05000224 */  addiu      $v0, $zero, 0x5
    /* CE5C 8001C65C 2C00448D */  lw         $a0, 0x2C($t2)
    /* CE60 8001C660 3801478D */  lw         $a3, 0x138($t2)
    /* CE64 8001C664 FF00063C */  lui        $a2, (0xFFFFFF >> 16)
    /* CE68 8001C668 030082A0 */  sb         $v0, 0x3($a0)
    /* CE6C 8001C66C 2A000224 */  addiu      $v0, $zero, 0x2A
    /* CE70 8001C670 070082A0 */  sb         $v0, 0x7($a0)
    /* CE74 8001C674 10004291 */  lbu        $v0, 0x10($t2)
    /* CE78 8001C678 FFFFC634 */  ori        $a2, $a2, (0xFFFFFF & 0xFFFF)
    /* CE7C 8001C67C 050082A0 */  sb         $v0, 0x5($a0)
    /* CE80 8001C680 060082A0 */  sb         $v0, 0x6($a0)
    /* CE84 8001C684 040082A0 */  sb         $v0, 0x4($a0)
    /* CE88 8001C688 10014395 */  lhu        $v1, 0x110($t2)
    /* CE8C 8001C68C 00FF093C */  lui        $t1, (0xFF000000 >> 16)
    /* CE90 8001C690 23100300 */  negu       $v0, $v1
    /* CE94 8001C694 100082A4 */  sh         $v0, 0x10($a0)
    /* CE98 8001C698 080082A4 */  sh         $v0, 0x8($a0)
    /* CE9C 8001C69C 140083A4 */  sh         $v1, 0x14($a0)
    /* CEA0 8001C6A0 0C0083A4 */  sh         $v1, 0xC($a0)
    /* CEA4 8001C6A4 14014395 */  lhu        $v1, 0x114($t2)
    /* CEA8 8001C6A8 02000824 */  addiu      $t0, $zero, 0x2
    /* CEAC 8001C6AC 23100300 */  negu       $v0, $v1
    /* CEB0 8001C6B0 160083A4 */  sh         $v1, 0x16($a0)
    /* CEB4 8001C6B4 120083A4 */  sh         $v1, 0x12($a0)
    /* CEB8 8001C6B8 0000838C */  lw         $v1, 0x0($a0)
    /* CEBC 8001C6BC 21288000 */  addu       $a1, $a0, $zero
    /* CEC0 8001C6C0 0E0082A4 */  sh         $v0, 0xE($a0)
    /* CEC4 8001C6C4 0A0082A4 */  sh         $v0, 0xA($a0)
    /* CEC8 8001C6C8 0000E28C */  lw         $v0, 0x0($a3)
    /* CECC 8001C6CC 24186900 */  and        $v1, $v1, $t1
    /* CED0 8001C6D0 24104600 */  and        $v0, $v0, $a2
    /* CED4 8001C6D4 25186200 */  or         $v1, $v1, $v0
    /* CED8 8001C6D8 000083AC */  sw         $v1, 0x0($a0)
    /* CEDC 8001C6DC 0000E28C */  lw         $v0, 0x0($a3)
    /* CEE0 8001C6E0 24188600 */  and        $v1, $a0, $a2
    /* CEE4 8001C6E4 24104900 */  and        $v0, $v0, $t1
    /* CEE8 8001C6E8 25104300 */  or         $v0, $v0, $v1
    /* CEEC 8001C6EC 0000E2AC */  sw         $v0, 0x0($a3)
    /* CEF0 8001C6F0 0480023C */  lui        $v0, %hi(D_8004156C)
    /* CEF4 8001C6F4 6C15428C */  lw         $v0, %lo(D_8004156C)($v0)
    /* CEF8 8001C6F8 00000000 */  nop
    /* CEFC 8001C6FC 02004010 */  beqz       $v0, .L8001C708
    /* CF00 8001C700 18008424 */   addiu     $a0, $a0, 0x18
    /* CF04 8001C704 01000824 */  addiu      $t0, $zero, 0x1
  .L8001C708:
    /* CF08 8001C708 00E1033C */  lui        $v1, (0xE1000400 >> 16)
    /* CF0C 8001C70C 00046334 */  ori        $v1, $v1, (0xE1000400 & 0xFFFF)
    /* CF10 8001C710 01000224 */  addiu      $v0, $zero, 0x1
    /* CF14 8001C714 030082A0 */  sb         $v0, 0x3($a0)
    /* CF18 8001C718 40110800 */  sll        $v0, $t0, 5
    /* CF1C 8001C71C 25104300 */  or         $v0, $v0, $v1
    /* CF20 8001C720 040082AC */  sw         $v0, 0x4($a0)
    /* CF24 8001C724 1800A38C */  lw         $v1, 0x18($a1)
    /* CF28 8001C728 0000E28C */  lw         $v0, 0x0($a3)
    /* CF2C 8001C72C 24186900 */  and        $v1, $v1, $t1
    /* CF30 8001C730 24104600 */  and        $v0, $v0, $a2
    /* CF34 8001C734 25186200 */  or         $v1, $v1, $v0
    /* CF38 8001C738 1800A3AC */  sw         $v1, 0x18($a1)
    /* CF3C 8001C73C 24188600 */  and        $v1, $a0, $a2
    /* CF40 8001C740 0000E28C */  lw         $v0, 0x0($a3)
    /* CF44 8001C744 2000A424 */  addiu      $a0, $a1, 0x20
    /* CF48 8001C748 24104900 */  and        $v0, $v0, $t1
    /* CF4C 8001C74C 25104300 */  or         $v0, $v0, $v1
    /* CF50 8001C750 0000E2AC */  sw         $v0, 0x0($a3)
    /* CF54 8001C754 2C0044AD */  sw         $a0, 0x2C($t2)
  .L8001C758:
    /* CF58 8001C758 0800E003 */  jr         $ra
    /* CF5C 8001C75C 00000000 */   nop
endlabel Gfx_DrawFade
