nonmatching SpuSetKey, 0x1BC

glabel SpuSetKey
    /* 2CD54 8003C554 FF00023C */  lui        $v0, (0xFFFFFF >> 16)
    /* 2CD58 8003C558 FFFF4234 */  ori        $v0, $v0, (0xFFFFFF & 0xFFFF)
    /* 2CD5C 8003C55C 2428A200 */  and        $a1, $a1, $v0
    /* 2CD60 8003C560 35008010 */  beqz       $a0, .L8003C638
    /* 2CD64 8003C564 02340500 */   srl       $a2, $a1, 16
    /* 2CD68 8003C568 01000224 */  addiu      $v0, $zero, 0x1
    /* 2CD6C 8003C56C 66008214 */  bne        $a0, $v0, .L8003C708
    /* 2CD70 8003C570 00000000 */   nop
    /* 2CD74 8003C574 0580023C */  lui        $v0, %hi(D_8004FE14)
    /* 2CD78 8003C578 14FE428C */  lw         $v0, %lo(D_8004FE14)($v0)
    /* 2CD7C 8003C57C 00000000 */  nop
    /* 2CD80 8003C580 01004230 */  andi       $v0, $v0, 0x1
    /* 2CD84 8003C584 24004010 */  beqz       $v0, .L8003C618
    /* 2CD88 8003C588 00000000 */   nop
    /* 2CD8C 8003C58C 0680043C */  lui        $a0, %hi(D_80062EE8)
    /* 2CD90 8003C590 E82E8424 */  addiu      $a0, $a0, %lo(D_80062EE8)
    /* 2CD94 8003C594 000085A4 */  sh         $a1, 0x0($a0)
    /* 2CD98 8003C598 020086A4 */  sh         $a2, 0x2($a0)
    /* 2CD9C 8003C59C 0580023C */  lui        $v0, %hi(D_8004FDE0)
    /* 2CDA0 8003C5A0 E0FD428C */  lw         $v0, %lo(D_8004FDE0)($v0)
    /* 2CDA4 8003C5A4 00000000 */  nop
    /* 2CDA8 8003C5A8 01004234 */  ori        $v0, $v0, 0x1
    /* 2CDAC 8003C5AC 0580013C */  lui        $at, %hi(D_8004FDE0)
    /* 2CDB0 8003C5B0 E0FD22AC */  sw         $v0, %lo(D_8004FDE0)($at)
    /* 2CDB4 8003C5B4 0580023C */  lui        $v0, %hi(D_8004FDDC)
    /* 2CDB8 8003C5B8 DCFD428C */  lw         $v0, %lo(D_8004FDDC)($v0)
    /* 2CDBC 8003C5BC 00000000 */  nop
    /* 2CDC0 8003C5C0 25104500 */  or         $v0, $v0, $a1
    /* 2CDC4 8003C5C4 0580013C */  lui        $at, %hi(D_8004FDDC)
    /* 2CDC8 8003C5C8 DCFD22AC */  sw         $v0, %lo(D_8004FDDC)($at)
    /* 2CDCC 8003C5CC 04008294 */  lhu        $v0, 0x4($a0)
    /* 2CDD0 8003C5D0 00000000 */  nop
    /* 2CDD4 8003C5D4 24104500 */  and        $v0, $v0, $a1
    /* 2CDD8 8003C5D8 05004010 */  beqz       $v0, .L8003C5F0
    /* 2CDDC 8003C5DC 00000000 */   nop
    /* 2CDE0 8003C5E0 04008294 */  lhu        $v0, 0x4($a0)
    /* 2CDE4 8003C5E4 27180500 */  nor        $v1, $zero, $a1
    /* 2CDE8 8003C5E8 24104300 */  and        $v0, $v0, $v1
    /* 2CDEC 8003C5EC 040082A4 */  sh         $v0, 0x4($a0)
  .L8003C5F0:
    /* 2CDF0 8003C5F0 06008294 */  lhu        $v0, 0x6($a0)
    /* 2CDF4 8003C5F4 00000000 */  nop
    /* 2CDF8 8003C5F8 24104600 */  and        $v0, $v0, $a2
    /* 2CDFC 8003C5FC 42004010 */  beqz       $v0, .L8003C708
    /* 2CE00 8003C600 00000000 */   nop
    /* 2CE04 8003C604 06008294 */  lhu        $v0, 0x6($a0)
    /* 2CE08 8003C608 27180600 */  nor        $v1, $zero, $a2
    /* 2CE0C 8003C60C 24104300 */  and        $v0, $v0, $v1
    /* 2CE10 8003C610 C2F10008 */  j          .L8003C708
    /* 2CE14 8003C614 060082A4 */   sh        $v0, 0x6($a0)
  .L8003C618:
    /* 2CE18 8003C618 0580023C */  lui        $v0, %hi(D_8004FDB4)
    /* 2CE1C 8003C61C B4FD428C */  lw         $v0, %lo(D_8004FDB4)($v0)
    /* 2CE20 8003C620 0580033C */  lui        $v1, %hi(D_8004FE28)
    /* 2CE24 8003C624 28FE638C */  lw         $v1, %lo(D_8004FE28)($v1)
    /* 2CE28 8003C628 25104500 */  or         $v0, $v0, $a1
    /* 2CE2C 8003C62C 880165A4 */  sh         $a1, 0x188($v1)
    /* 2CE30 8003C630 C0F10008 */  j          .L8003C700
    /* 2CE34 8003C634 8A0166A4 */   sh        $a2, 0x18A($v1)
  .L8003C638:
    /* 2CE38 8003C638 0580023C */  lui        $v0, %hi(D_8004FE14)
    /* 2CE3C 8003C63C 14FE428C */  lw         $v0, %lo(D_8004FE14)($v0)
    /* 2CE40 8003C640 00000000 */  nop
    /* 2CE44 8003C644 01004230 */  andi       $v0, $v0, 0x1
    /* 2CE48 8003C648 24004010 */  beqz       $v0, .L8003C6DC
    /* 2CE4C 8003C64C 00000000 */   nop
    /* 2CE50 8003C650 0680043C */  lui        $a0, %hi(D_80062EE8)
    /* 2CE54 8003C654 E82E8424 */  addiu      $a0, $a0, %lo(D_80062EE8)
    /* 2CE58 8003C658 040085A4 */  sh         $a1, 0x4($a0)
    /* 2CE5C 8003C65C 060086A4 */  sh         $a2, 0x6($a0)
    /* 2CE60 8003C660 0580023C */  lui        $v0, %hi(D_8004FDE0)
    /* 2CE64 8003C664 E0FD428C */  lw         $v0, %lo(D_8004FDE0)($v0)
    /* 2CE68 8003C668 00000000 */  nop
    /* 2CE6C 8003C66C 01004234 */  ori        $v0, $v0, 0x1
    /* 2CE70 8003C670 0580013C */  lui        $at, %hi(D_8004FDE0)
    /* 2CE74 8003C674 E0FD22AC */  sw         $v0, %lo(D_8004FDE0)($at)
    /* 2CE78 8003C678 0580023C */  lui        $v0, %hi(D_8004FDDC)
    /* 2CE7C 8003C67C DCFD428C */  lw         $v0, %lo(D_8004FDDC)($v0)
    /* 2CE80 8003C680 27180500 */  nor        $v1, $zero, $a1
    /* 2CE84 8003C684 24104300 */  and        $v0, $v0, $v1
    /* 2CE88 8003C688 0580013C */  lui        $at, %hi(D_8004FDDC)
    /* 2CE8C 8003C68C DCFD22AC */  sw         $v0, %lo(D_8004FDDC)($at)
    /* 2CE90 8003C690 00008294 */  lhu        $v0, 0x0($a0)
    /* 2CE94 8003C694 00000000 */  nop
    /* 2CE98 8003C698 24104500 */  and        $v0, $v0, $a1
    /* 2CE9C 8003C69C 05004010 */  beqz       $v0, .L8003C6B4
    /* 2CEA0 8003C6A0 00000000 */   nop
    /* 2CEA4 8003C6A4 00008294 */  lhu        $v0, 0x0($a0)
    /* 2CEA8 8003C6A8 00000000 */  nop
    /* 2CEAC 8003C6AC 24104300 */  and        $v0, $v0, $v1
    /* 2CEB0 8003C6B0 000082A4 */  sh         $v0, 0x0($a0)
  .L8003C6B4:
    /* 2CEB4 8003C6B4 02008294 */  lhu        $v0, 0x2($a0)
    /* 2CEB8 8003C6B8 00000000 */  nop
    /* 2CEBC 8003C6BC 24104600 */  and        $v0, $v0, $a2
    /* 2CEC0 8003C6C0 11004010 */  beqz       $v0, .L8003C708
    /* 2CEC4 8003C6C4 00000000 */   nop
    /* 2CEC8 8003C6C8 02008294 */  lhu        $v0, 0x2($a0)
    /* 2CECC 8003C6CC 27180600 */  nor        $v1, $zero, $a2
    /* 2CED0 8003C6D0 24104300 */  and        $v0, $v0, $v1
    /* 2CED4 8003C6D4 C2F10008 */  j          .L8003C708
    /* 2CED8 8003C6D8 020082A4 */   sh        $v0, 0x2($a0)
  .L8003C6DC:
    /* 2CEDC 8003C6DC 0580023C */  lui        $v0, %hi(D_8004FE28)
    /* 2CEE0 8003C6E0 28FE428C */  lw         $v0, %lo(D_8004FE28)($v0)
    /* 2CEE4 8003C6E4 00000000 */  nop
    /* 2CEE8 8003C6E8 8C0145A4 */  sh         $a1, 0x18C($v0)
    /* 2CEEC 8003C6EC 8E0146A4 */  sh         $a2, 0x18E($v0)
    /* 2CEF0 8003C6F0 0580023C */  lui        $v0, %hi(D_8004FDB4)
    /* 2CEF4 8003C6F4 B4FD428C */  lw         $v0, %lo(D_8004FDB4)($v0)
    /* 2CEF8 8003C6F8 27180500 */  nor        $v1, $zero, $a1
    /* 2CEFC 8003C6FC 24104300 */  and        $v0, $v0, $v1
  .L8003C700:
    /* 2CF00 8003C700 0580013C */  lui        $at, %hi(D_8004FDB4)
    /* 2CF04 8003C704 B4FD22AC */  sw         $v0, %lo(D_8004FDB4)($at)
  .L8003C708:
    /* 2CF08 8003C708 0800E003 */  jr         $ra
    /* 2CF0C 8003C70C 00000000 */   nop
endlabel SpuSetKey
    /* 2CF10 8003C710 00000000 */  nop
