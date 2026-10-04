nonmatching GsGetLs, 0x2C8

glabel GsGetLs
    /* 1C594 8002BD94 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 1C598 8002BD98 1800B2AF */  sw         $s2, 0x18($sp)
    /* 1C59C 8002BD9C 2190A000 */  addu       $s2, $a1, $zero
    /* 1C5A0 8002BDA0 21388000 */  addu       $a3, $a0, $zero
    /* 1C5A4 8002BDA4 1400B1AF */  sw         $s1, 0x14($sp)
    /* 1C5A8 8002BDA8 21880000 */  addu       $s1, $zero, $zero
    /* 1C5AC 8002BDAC 64000524 */  addiu      $a1, $zero, 0x64
    /* 1C5B0 8002BDB0 0680063C */  lui        $a2, %hi(D_80061A68)
    /* 1C5B4 8002BDB4 681AC624 */  addiu      $a2, $a2, %lo(D_80061A68)
    /* 1C5B8 8002BDB8 64000824 */  addiu      $t0, $zero, 0x64
    /* 1C5BC 8002BDBC 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 1C5C0 8002BDC0 1000B0AF */  sw         $s0, 0x10($sp)
  .L8002BDC4:
    /* 1C5C4 8002BDC4 80101100 */  sll        $v0, $s1, 2
    /* 1C5C8 8002BDC8 21104600 */  addu       $v0, $v0, $a2
    /* 1C5CC 8002BDCC 000047AC */  sw         $a3, 0x0($v0)
    /* 1C5D0 8002BDD0 4800E48C */  lw         $a0, 0x48($a3)
    /* 1C5D4 8002BDD4 00000000 */  nop
    /* 1C5D8 8002BDD8 59008014 */  bnez       $a0, .L8002BF40
    /* 1C5DC 8002BDDC 00000000 */   nop
    /* 1C5E0 8002BDE0 0000E38C */  lw         $v1, 0x0($a3)
    /* 1C5E4 8002BDE4 0680023C */  lui        $v0, %hi(D_80061988)
    /* 1C5E8 8002BDE8 8819428C */  lw         $v0, %lo(D_80061988)($v0)
    /* 1C5EC 8002BDEC 00000000 */  nop
    /* 1C5F0 8002BDF0 03006210 */  beq        $v1, $v0, .L8002BE00
    /* 1C5F4 8002BDF4 00000000 */   nop
    /* 1C5F8 8002BDF8 25006014 */  bnez       $v1, .L8002BE90
    /* 1C5FC 8002BDFC 00000000 */   nop
  .L8002BE00:
    /* 1C600 8002BE00 0400E28C */  lw         $v0, 0x4($a3)
    /* 1C604 8002BE04 0800E38C */  lw         $v1, 0x8($a3)
    /* 1C608 8002BE08 0C00E48C */  lw         $a0, 0xC($a3)
    /* 1C60C 8002BE0C 1000E58C */  lw         $a1, 0x10($a3)
    /* 1C610 8002BE10 2400E2AC */  sw         $v0, 0x24($a3)
    /* 1C614 8002BE14 2800E3AC */  sw         $v1, 0x28($a3)
    /* 1C618 8002BE18 2C00E4AC */  sw         $a0, 0x2C($a3)
    /* 1C61C 8002BE1C 3000E5AC */  sw         $a1, 0x30($a3)
    /* 1C620 8002BE20 1400E28C */  lw         $v0, 0x14($a3)
    /* 1C624 8002BE24 1800E38C */  lw         $v1, 0x18($a3)
    /* 1C628 8002BE28 1C00E48C */  lw         $a0, 0x1C($a3)
    /* 1C62C 8002BE2C 2000E58C */  lw         $a1, 0x20($a3)
    /* 1C630 8002BE30 3400E2AC */  sw         $v0, 0x34($a3)
    /* 1C634 8002BE34 3800E3AC */  sw         $v1, 0x38($a3)
    /* 1C638 8002BE38 3C00E4AC */  sw         $a0, 0x3C($a3)
    /* 1C63C 8002BE3C 4000E5AC */  sw         $a1, 0x40($a3)
    /* 1C640 8002BE40 0680023C */  lui        $v0, %hi(D_80061988)
    /* 1C644 8002BE44 8819428C */  lw         $v0, %lo(D_80061988)($v0)
    /* 1C648 8002BE48 2400E38C */  lw         $v1, 0x24($a3)
    /* 1C64C 8002BE4C 2800E48C */  lw         $a0, 0x28($a3)
    /* 1C650 8002BE50 2C00E58C */  lw         $a1, 0x2C($a3)
    /* 1C654 8002BE54 3000E68C */  lw         $a2, 0x30($a3)
    /* 1C658 8002BE58 000043AE */  sw         $v1, 0x0($s2)
    /* 1C65C 8002BE5C 040044AE */  sw         $a0, 0x4($s2)
    /* 1C660 8002BE60 080045AE */  sw         $a1, 0x8($s2)
    /* 1C664 8002BE64 0C0046AE */  sw         $a2, 0xC($s2)
    /* 1C668 8002BE68 3400E38C */  lw         $v1, 0x34($a3)
    /* 1C66C 8002BE6C 3800E48C */  lw         $a0, 0x38($a3)
    /* 1C670 8002BE70 3C00E58C */  lw         $a1, 0x3C($a3)
    /* 1C674 8002BE74 4000E68C */  lw         $a2, 0x40($a3)
    /* 1C678 8002BE78 100043AE */  sw         $v1, 0x10($s2)
    /* 1C67C 8002BE7C 140044AE */  sw         $a0, 0x14($s2)
    /* 1C680 8002BE80 180045AE */  sw         $a1, 0x18($s2)
    /* 1C684 8002BE84 1C0046AE */  sw         $a2, 0x1C($s2)
    /* 1C688 8002BE88 ECAF0008 */  j          .L8002BFB0
    /* 1C68C 8002BE8C 0000E2AC */   sw        $v0, 0x0($a3)
  .L8002BE90:
    /* 1C690 8002BE90 1600A814 */  bne        $a1, $t0, .L8002BEEC
    /* 1C694 8002BE94 0100B124 */   addiu     $s1, $a1, 0x1
    /* 1C698 8002BE98 0680023C */  lui        $v0, %hi(D_80061A68)
    /* 1C69C 8002BE9C 681A428C */  lw         $v0, %lo(D_80061A68)($v0)
    /* 1C6A0 8002BEA0 00000000 */  nop
    /* 1C6A4 8002BEA4 2400438C */  lw         $v1, 0x24($v0)
    /* 1C6A8 8002BEA8 2800448C */  lw         $a0, 0x28($v0)
    /* 1C6AC 8002BEAC 2C00458C */  lw         $a1, 0x2C($v0)
    /* 1C6B0 8002BEB0 3000468C */  lw         $a2, 0x30($v0)
    /* 1C6B4 8002BEB4 000043AE */  sw         $v1, 0x0($s2)
    /* 1C6B8 8002BEB8 040044AE */  sw         $a0, 0x4($s2)
    /* 1C6BC 8002BEBC 080045AE */  sw         $a1, 0x8($s2)
    /* 1C6C0 8002BEC0 0C0046AE */  sw         $a2, 0xC($s2)
    /* 1C6C4 8002BEC4 3400438C */  lw         $v1, 0x34($v0)
    /* 1C6C8 8002BEC8 3800448C */  lw         $a0, 0x38($v0)
    /* 1C6CC 8002BECC 3C00458C */  lw         $a1, 0x3C($v0)
    /* 1C6D0 8002BED0 4000468C */  lw         $a2, 0x40($v0)
    /* 1C6D4 8002BED4 100043AE */  sw         $v1, 0x10($s2)
    /* 1C6D8 8002BED8 140044AE */  sw         $a0, 0x14($s2)
    /* 1C6DC 8002BEDC 180045AE */  sw         $a1, 0x18($s2)
    /* 1C6E0 8002BEE0 1C0046AE */  sw         $a2, 0x1C($s2)
    /* 1C6E4 8002BEE4 ECAF0008 */  j          .L8002BFB0
    /* 1C6E8 8002BEE8 21880000 */   addu      $s1, $zero, $zero
  .L8002BEEC:
    /* 1C6EC 8002BEEC 80101100 */  sll        $v0, $s1, 2
    /* 1C6F0 8002BEF0 21104600 */  addu       $v0, $v0, $a2
    /* 1C6F4 8002BEF4 0000428C */  lw         $v0, 0x0($v0)
    /* 1C6F8 8002BEF8 00000000 */  nop
    /* 1C6FC 8002BEFC 2400438C */  lw         $v1, 0x24($v0)
    /* 1C700 8002BF00 2800448C */  lw         $a0, 0x28($v0)
    /* 1C704 8002BF04 2C00458C */  lw         $a1, 0x2C($v0)
    /* 1C708 8002BF08 3000468C */  lw         $a2, 0x30($v0)
    /* 1C70C 8002BF0C 000043AE */  sw         $v1, 0x0($s2)
    /* 1C710 8002BF10 040044AE */  sw         $a0, 0x4($s2)
    /* 1C714 8002BF14 080045AE */  sw         $a1, 0x8($s2)
    /* 1C718 8002BF18 0C0046AE */  sw         $a2, 0xC($s2)
    /* 1C71C 8002BF1C 3400438C */  lw         $v1, 0x34($v0)
    /* 1C720 8002BF20 3800448C */  lw         $a0, 0x38($v0)
    /* 1C724 8002BF24 3C00458C */  lw         $a1, 0x3C($v0)
    /* 1C728 8002BF28 4000468C */  lw         $a2, 0x40($v0)
    /* 1C72C 8002BF2C 100043AE */  sw         $v1, 0x10($s2)
    /* 1C730 8002BF30 140044AE */  sw         $a0, 0x14($s2)
    /* 1C734 8002BF34 180045AE */  sw         $a1, 0x18($s2)
    /* 1C738 8002BF38 ECAF0008 */  j          .L8002BFB0
    /* 1C73C 8002BF3C 1C0046AE */   sw        $a2, 0x1C($s2)
  .L8002BF40:
    /* 1C740 8002BF40 0000E38C */  lw         $v1, 0x0($a3)
    /* 1C744 8002BF44 0680023C */  lui        $v0, %hi(D_80061988)
    /* 1C748 8002BF48 8819428C */  lw         $v0, %lo(D_80061988)($v0)
    /* 1C74C 8002BF4C 00000000 */  nop
    /* 1C750 8002BF50 12006214 */  bne        $v1, $v0, .L8002BF9C
    /* 1C754 8002BF54 00000000 */   nop
    /* 1C758 8002BF58 2400E28C */  lw         $v0, 0x24($a3)
    /* 1C75C 8002BF5C 2800E38C */  lw         $v1, 0x28($a3)
    /* 1C760 8002BF60 2C00E48C */  lw         $a0, 0x2C($a3)
    /* 1C764 8002BF64 3000E58C */  lw         $a1, 0x30($a3)
    /* 1C768 8002BF68 000042AE */  sw         $v0, 0x0($s2)
    /* 1C76C 8002BF6C 040043AE */  sw         $v1, 0x4($s2)
    /* 1C770 8002BF70 080044AE */  sw         $a0, 0x8($s2)
    /* 1C774 8002BF74 0C0045AE */  sw         $a1, 0xC($s2)
    /* 1C778 8002BF78 3400E28C */  lw         $v0, 0x34($a3)
    /* 1C77C 8002BF7C 3800E38C */  lw         $v1, 0x38($a3)
    /* 1C780 8002BF80 3C00E48C */  lw         $a0, 0x3C($a3)
    /* 1C784 8002BF84 4000E58C */  lw         $a1, 0x40($a3)
    /* 1C788 8002BF88 100042AE */  sw         $v0, 0x10($s2)
    /* 1C78C 8002BF8C 140043AE */  sw         $v1, 0x14($s2)
    /* 1C790 8002BF90 180044AE */  sw         $a0, 0x18($s2)
    /* 1C794 8002BF94 ECAF0008 */  j          .L8002BFB0
    /* 1C798 8002BF98 1C0045AE */   sw        $a1, 0x1C($s2)
  .L8002BF9C:
    /* 1C79C 8002BF9C 02006014 */  bnez       $v1, .L8002BFA8
    /* 1C7A0 8002BFA0 21388000 */   addu      $a3, $a0, $zero
    /* 1C7A4 8002BFA4 21282002 */  addu       $a1, $s1, $zero
  .L8002BFA8:
    /* 1C7A8 8002BFA8 71AF0008 */  j          .L8002BDC4
    /* 1C7AC 8002BFAC 01003126 */   addiu     $s1, $s1, 0x1
  .L8002BFB0:
    /* 1C7B0 8002BFB0 2000201A */  blez       $s1, .L8002C034
    /* 1C7B4 8002BFB4 80101100 */   sll       $v0, $s1, 2
    /* 1C7B8 8002BFB8 0680033C */  lui        $v1, %hi(D_80061A64)
    /* 1C7BC 8002BFBC 641A6324 */  addiu      $v1, $v1, %lo(D_80061A64)
    /* 1C7C0 8002BFC0 21804300 */  addu       $s0, $v0, $v1
  .L8002BFC4:
    /* 1C7C4 8002BFC4 0000058E */  lw         $a1, 0x0($s0)
    /* 1C7C8 8002BFC8 21204002 */  addu       $a0, $s2, $zero
    /* 1C7CC 8002BFCC 39B0000C */  jal        GsMulCoord3
    /* 1C7D0 8002BFD0 0400A524 */   addiu     $a1, $a1, 0x4
    /* 1C7D4 8002BFD4 0000028E */  lw         $v0, 0x0($s0)
    /* 1C7D8 8002BFD8 FFFF3126 */  addiu      $s1, $s1, -0x1
    /* 1C7DC 8002BFDC 0000438E */  lw         $v1, 0x0($s2)
    /* 1C7E0 8002BFE0 0400448E */  lw         $a0, 0x4($s2)
    /* 1C7E4 8002BFE4 0800458E */  lw         $a1, 0x8($s2)
    /* 1C7E8 8002BFE8 0C00468E */  lw         $a2, 0xC($s2)
    /* 1C7EC 8002BFEC 240043AC */  sw         $v1, 0x24($v0)
    /* 1C7F0 8002BFF0 280044AC */  sw         $a0, 0x28($v0)
    /* 1C7F4 8002BFF4 2C0045AC */  sw         $a1, 0x2C($v0)
    /* 1C7F8 8002BFF8 300046AC */  sw         $a2, 0x30($v0)
    /* 1C7FC 8002BFFC 1000438E */  lw         $v1, 0x10($s2)
    /* 1C800 8002C000 1400448E */  lw         $a0, 0x14($s2)
    /* 1C804 8002C004 1800458E */  lw         $a1, 0x18($s2)
    /* 1C808 8002C008 1C00468E */  lw         $a2, 0x1C($s2)
    /* 1C80C 8002C00C 340043AC */  sw         $v1, 0x34($v0)
    /* 1C810 8002C010 380044AC */  sw         $a0, 0x38($v0)
    /* 1C814 8002C014 3C0045AC */  sw         $a1, 0x3C($v0)
    /* 1C818 8002C018 400046AC */  sw         $a2, 0x40($v0)
    /* 1C81C 8002C01C 0000038E */  lw         $v1, 0x0($s0)
    /* 1C820 8002C020 0680023C */  lui        $v0, %hi(D_80061988)
    /* 1C824 8002C024 8819428C */  lw         $v0, %lo(D_80061988)($v0)
    /* 1C828 8002C028 FCFF1026 */  addiu      $s0, $s0, -0x4
    /* 1C82C 8002C02C E5FF201E */  bgtz       $s1, .L8002BFC4
    /* 1C830 8002C030 000062AC */   sw        $v0, 0x0($v1)
  .L8002C034:
    /* 1C834 8002C034 0680043C */  lui        $a0, %hi(GsWSMATRIX)
    /* 1C838 8002C038 081A8424 */  addiu      $a0, $a0, %lo(GsWSMATRIX)
    /* 1C83C 8002C03C 19B0000C */  jal        GsMulCoord2
    /* 1C840 8002C040 21284002 */   addu      $a1, $s2, $zero
    /* 1C844 8002C044 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 1C848 8002C048 1800B28F */  lw         $s2, 0x18($sp)
    /* 1C84C 8002C04C 1400B18F */  lw         $s1, 0x14($sp)
    /* 1C850 8002C050 1000B08F */  lw         $s0, 0x10($sp)
    /* 1C854 8002C054 0800E003 */  jr         $ra
    /* 1C858 8002C058 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel GsGetLs
    /* 1C85C 8002C05C 00000000 */  nop
    /* 1C860 8002C060 00000000 */  nop
