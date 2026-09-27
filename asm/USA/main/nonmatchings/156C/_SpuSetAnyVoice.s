nonmatching _SpuSetAnyVoice, 0x2BC

glabel _SpuSetAnyVoice
    /* 2BC24 8003B424 21488000 */  addu       $t1, $a0, $zero
    /* 2BC28 8003B428 0580023C */  lui        $v0, %hi(D_8004FE14)
    /* 2BC2C 8003B42C 14FE428C */  lw         $v0, %lo(D_8004FE14)($v0)
    /* 2BC30 8003B430 00000000 */  nop
    /* 2BC34 8003B434 01004230 */  andi       $v0, $v0, 0x1
    /* 2BC38 8003B438 0680043C */  lui        $a0, %hi(D_80062D60)
    /* 2BC3C 8003B43C 602D8424 */  addiu      $a0, $a0, %lo(D_80062D60)
    /* 2BC40 8003B440 03004014 */  bnez       $v0, .L8003B450
    /* 2BC44 8003B444 2140A000 */   addu      $t0, $a1, $zero
    /* 2BC48 8003B448 0580043C */  lui        $a0, %hi(D_8004FE28)
    /* 2BC4C 8003B44C 28FE848C */  lw         $a0, %lo(D_8004FE28)($a0)
  .L8003B450:
    /* 2BC50 8003B450 40100700 */  sll        $v0, $a3, 1
    /* 2BC54 8003B454 21104400 */  addu       $v0, $v0, $a0
    /* 2BC58 8003B458 00004394 */  lhu        $v1, 0x0($v0)
    /* 2BC5C 8003B45C 40100600 */  sll        $v0, $a2, 1
    /* 2BC60 8003B460 21104400 */  addu       $v0, $v0, $a0
    /* 2BC64 8003B464 00004294 */  lhu        $v0, 0x0($v0)
    /* 2BC68 8003B468 FF006330 */  andi       $v1, $v1, 0xFF
    /* 2BC6C 8003B46C 001C0300 */  sll        $v1, $v1, 16
    /* 2BC70 8003B470 01000B24 */  addiu      $t3, $zero, 0x1
    /* 2BC74 8003B474 0C002B11 */  beq        $t1, $t3, .L8003B4A8
    /* 2BC78 8003B478 25504300 */   or        $t2, $v0, $v1
    /* 2BC7C 8003B47C 02002229 */  slti       $v0, $t1, 0x2
    /* 2BC80 8003B480 05004010 */  beqz       $v0, .L8003B498
    /* 2BC84 8003B484 08000224 */   addiu     $v0, $zero, 0x8
    /* 2BC88 8003B488 36002011 */  beqz       $t1, .L8003B564
    /* 2BC8C 8003B48C FF00023C */   lui       $v0, (0xFFFFFF >> 16)
    /* 2BC90 8003B490 B6ED0008 */  j          .L8003B6D8
    /* 2BC94 8003B494 FFFF4234 */   ori       $v0, $v0, (0xFFFFFF & 0xFFFF)
  .L8003B498:
    /* 2BC98 8003B498 67002211 */  beq        $t1, $v0, .L8003B638
    /* 2BC9C 8003B49C FF00023C */   lui       $v0, (0xFFFFFF >> 16)
    /* 2BCA0 8003B4A0 B6ED0008 */  j          .L8003B6D8
    /* 2BCA4 8003B4A4 FFFF4234 */   ori       $v0, $v0, (0xFFFFFF & 0xFFFF)
  .L8003B4A8:
    /* 2BCA8 8003B4A8 0580023C */  lui        $v0, %hi(D_8004FE14)
    /* 2BCAC 8003B4AC 14FE428C */  lw         $v0, %lo(D_8004FE14)($v0)
    /* 2BCB0 8003B4B0 00000000 */  nop
    /* 2BCB4 8003B4B4 01004230 */  andi       $v0, $v0, 0x1
    /* 2BCB8 8003B4B8 18004010 */  beqz       $v0, .L8003B51C
    /* 2BCBC 8003B4BC 40180600 */   sll       $v1, $a2, 1
    /* 2BCC0 8003B4C0 0680053C */  lui        $a1, %hi(D_80062D60)
    /* 2BCC4 8003B4C4 602DA524 */  addiu      $a1, $a1, %lo(D_80062D60)
    /* 2BCC8 8003B4C8 21186500 */  addu       $v1, $v1, $a1
    /* 2BCCC 8003B4CC 40200700 */  sll        $a0, $a3, 1
    /* 2BCD0 8003B4D0 00006294 */  lhu        $v0, 0x0($v1)
    /* 2BCD4 8003B4D4 21208500 */  addu       $a0, $a0, $a1
    /* 2BCD8 8003B4D8 25104800 */  or         $v0, $v0, $t0
    /* 2BCDC 8003B4DC 000062A4 */  sh         $v0, 0x0($v1)
    /* 2BCE0 8003B4E0 02140800 */  srl        $v0, $t0, 16
    /* 2BCE4 8003B4E4 00008394 */  lhu        $v1, 0x0($a0)
    /* 2BCE8 8003B4E8 FF004230 */  andi       $v0, $v0, 0xFF
    /* 2BCEC 8003B4EC 25186200 */  or         $v1, $v1, $v0
    /* 2BCF0 8003B4F0 3AFFC224 */  addiu      $v0, $a2, -0xC6
    /* 2BCF4 8003B4F4 43100200 */  sra        $v0, $v0, 1
    /* 2BCF8 8003B4F8 000083A4 */  sh         $v1, 0x0($a0)
    /* 2BCFC 8003B4FC 0580033C */  lui        $v1, %hi(D_8004FDE0)
    /* 2BD00 8003B500 E0FD638C */  lw         $v1, %lo(D_8004FDE0)($v1)
    /* 2BD04 8003B504 04104B00 */  sllv       $v0, $t3, $v0
    /* 2BD08 8003B508 25186200 */  or         $v1, $v1, $v0
    /* 2BD0C 8003B50C 0580013C */  lui        $at, %hi(D_8004FDE0)
    /* 2BD10 8003B510 E0FD23AC */  sw         $v1, %lo(D_8004FDE0)($at)
    /* 2BD14 8003B514 55ED0008 */  j          .L8003B554
    /* 2BD18 8003B518 FF00023C */   lui       $v0, (0xFFFFFF >> 16)
  .L8003B51C:
    /* 2BD1C 8003B51C 0580053C */  lui        $a1, %hi(D_8004FE28)
    /* 2BD20 8003B520 28FEA58C */  lw         $a1, %lo(D_8004FE28)($a1)
    /* 2BD24 8003B524 40200700 */  sll        $a0, $a3, 1
    /* 2BD28 8003B528 21186500 */  addu       $v1, $v1, $a1
    /* 2BD2C 8003B52C 00006294 */  lhu        $v0, 0x0($v1)
    /* 2BD30 8003B530 21208500 */  addu       $a0, $a0, $a1
    /* 2BD34 8003B534 25104800 */  or         $v0, $v0, $t0
    /* 2BD38 8003B538 000062A4 */  sh         $v0, 0x0($v1)
    /* 2BD3C 8003B53C 02140800 */  srl        $v0, $t0, 16
    /* 2BD40 8003B540 00008394 */  lhu        $v1, 0x0($a0)
    /* 2BD44 8003B544 FF004230 */  andi       $v0, $v0, 0xFF
    /* 2BD48 8003B548 25186200 */  or         $v1, $v1, $v0
    /* 2BD4C 8003B54C 000083A4 */  sh         $v1, 0x0($a0)
    /* 2BD50 8003B550 FF00023C */  lui        $v0, (0xFFFFFF >> 16)
  .L8003B554:
    /* 2BD54 8003B554 FFFF4234 */  ori        $v0, $v0, (0xFFFFFF & 0xFFFF)
    /* 2BD58 8003B558 24100201 */  and        $v0, $t0, $v0
    /* 2BD5C 8003B55C B4ED0008 */  j          .L8003B6D0
    /* 2BD60 8003B560 25504201 */   or        $t2, $t2, $v0
  .L8003B564:
    /* 2BD64 8003B564 0580023C */  lui        $v0, %hi(D_8004FE14)
    /* 2BD68 8003B568 14FE428C */  lw         $v0, %lo(D_8004FE14)($v0)
    /* 2BD6C 8003B56C 00000000 */  nop
    /* 2BD70 8003B570 01004230 */  andi       $v0, $v0, 0x1
    /* 2BD74 8003B574 1A004010 */  beqz       $v0, .L8003B5E0
    /* 2BD78 8003B578 40180600 */   sll       $v1, $a2, 1
    /* 2BD7C 8003B57C 0680053C */  lui        $a1, %hi(D_80062D60)
    /* 2BD80 8003B580 602DA524 */  addiu      $a1, $a1, %lo(D_80062D60)
    /* 2BD84 8003B584 21186500 */  addu       $v1, $v1, $a1
    /* 2BD88 8003B588 00006294 */  lhu        $v0, 0x0($v1)
    /* 2BD8C 8003B58C 27200800 */  nor        $a0, $zero, $t0
    /* 2BD90 8003B590 24104400 */  and        $v0, $v0, $a0
    /* 2BD94 8003B594 40200700 */  sll        $a0, $a3, 1
    /* 2BD98 8003B598 21208500 */  addu       $a0, $a0, $a1
    /* 2BD9C 8003B59C 000062A4 */  sh         $v0, 0x0($v1)
    /* 2BDA0 8003B5A0 02140800 */  srl        $v0, $t0, 16
    /* 2BDA4 8003B5A4 FF004230 */  andi       $v0, $v0, 0xFF
    /* 2BDA8 8003B5A8 00008394 */  lhu        $v1, 0x0($a0)
    /* 2BDAC 8003B5AC 27100200 */  nor        $v0, $zero, $v0
    /* 2BDB0 8003B5B0 24186200 */  and        $v1, $v1, $v0
    /* 2BDB4 8003B5B4 3AFFC224 */  addiu      $v0, $a2, -0xC6
    /* 2BDB8 8003B5B8 43100200 */  sra        $v0, $v0, 1
    /* 2BDBC 8003B5BC 000083A4 */  sh         $v1, 0x0($a0)
    /* 2BDC0 8003B5C0 0580033C */  lui        $v1, %hi(D_8004FDE0)
    /* 2BDC4 8003B5C4 E0FD638C */  lw         $v1, %lo(D_8004FDE0)($v1)
    /* 2BDC8 8003B5C8 04104B00 */  sllv       $v0, $t3, $v0
    /* 2BDCC 8003B5CC 25186200 */  or         $v1, $v1, $v0
    /* 2BDD0 8003B5D0 0580013C */  lui        $at, %hi(D_8004FDE0)
    /* 2BDD4 8003B5D4 E0FD23AC */  sw         $v1, %lo(D_8004FDE0)($at)
    /* 2BDD8 8003B5D8 89ED0008 */  j          .L8003B624
    /* 2BDDC 8003B5DC FF00023C */   lui       $v0, (0xFFFFFF >> 16)
  .L8003B5E0:
    /* 2BDE0 8003B5E0 0580053C */  lui        $a1, %hi(D_8004FE28)
    /* 2BDE4 8003B5E4 28FEA58C */  lw         $a1, %lo(D_8004FE28)($a1)
    /* 2BDE8 8003B5E8 00000000 */  nop
    /* 2BDEC 8003B5EC 21186500 */  addu       $v1, $v1, $a1
    /* 2BDF0 8003B5F0 00006294 */  lhu        $v0, 0x0($v1)
    /* 2BDF4 8003B5F4 27200800 */  nor        $a0, $zero, $t0
    /* 2BDF8 8003B5F8 24104400 */  and        $v0, $v0, $a0
    /* 2BDFC 8003B5FC 40200700 */  sll        $a0, $a3, 1
    /* 2BE00 8003B600 21208500 */  addu       $a0, $a0, $a1
    /* 2BE04 8003B604 000062A4 */  sh         $v0, 0x0($v1)
    /* 2BE08 8003B608 02140800 */  srl        $v0, $t0, 16
    /* 2BE0C 8003B60C FF004230 */  andi       $v0, $v0, 0xFF
    /* 2BE10 8003B610 00008394 */  lhu        $v1, 0x0($a0)
    /* 2BE14 8003B614 27100200 */  nor        $v0, $zero, $v0
    /* 2BE18 8003B618 24186200 */  and        $v1, $v1, $v0
    /* 2BE1C 8003B61C 000083A4 */  sh         $v1, 0x0($a0)
    /* 2BE20 8003B620 FF00023C */  lui        $v0, (0xFFFFFF >> 16)
  .L8003B624:
    /* 2BE24 8003B624 FFFF4234 */  ori        $v0, $v0, (0xFFFFFF & 0xFFFF)
    /* 2BE28 8003B628 24100201 */  and        $v0, $t0, $v0
    /* 2BE2C 8003B62C 27100200 */  nor        $v0, $zero, $v0
    /* 2BE30 8003B630 B4ED0008 */  j          .L8003B6D0
    /* 2BE34 8003B634 24504201 */   and       $t2, $t2, $v0
  .L8003B638:
    /* 2BE38 8003B638 0580023C */  lui        $v0, %hi(D_8004FE14)
    /* 2BE3C 8003B63C 14FE428C */  lw         $v0, %lo(D_8004FE14)($v0)
    /* 2BE40 8003B640 00000000 */  nop
    /* 2BE44 8003B644 01004230 */  andi       $v0, $v0, 0x1
    /* 2BE48 8003B648 14004010 */  beqz       $v0, .L8003B69C
    /* 2BE4C 8003B64C 40180700 */   sll       $v1, $a3, 1
    /* 2BE50 8003B650 0680043C */  lui        $a0, %hi(D_80062D60)
    /* 2BE54 8003B654 602D8424 */  addiu      $a0, $a0, %lo(D_80062D60)
    /* 2BE58 8003B658 40100600 */  sll        $v0, $a2, 1
    /* 2BE5C 8003B65C 21104400 */  addu       $v0, $v0, $a0
    /* 2BE60 8003B660 21186400 */  addu       $v1, $v1, $a0
    /* 2BE64 8003B664 000048A4 */  sh         $t0, 0x0($v0)
    /* 2BE68 8003B668 02140800 */  srl        $v0, $t0, 16
    /* 2BE6C 8003B66C FF004230 */  andi       $v0, $v0, 0xFF
    /* 2BE70 8003B670 000062A4 */  sh         $v0, 0x0($v1)
    /* 2BE74 8003B674 3AFFC224 */  addiu      $v0, $a2, -0xC6
    /* 2BE78 8003B678 43100200 */  sra        $v0, $v0, 1
    /* 2BE7C 8003B67C 0580033C */  lui        $v1, %hi(D_8004FDE0)
    /* 2BE80 8003B680 E0FD638C */  lw         $v1, %lo(D_8004FDE0)($v1)
    /* 2BE84 8003B684 04104B00 */  sllv       $v0, $t3, $v0
    /* 2BE88 8003B688 25186200 */  or         $v1, $v1, $v0
    /* 2BE8C 8003B68C 0580013C */  lui        $at, %hi(D_8004FDE0)
    /* 2BE90 8003B690 E0FD23AC */  sw         $v1, %lo(D_8004FDE0)($at)
    /* 2BE94 8003B694 B2ED0008 */  j          .L8003B6C8
    /* 2BE98 8003B698 FF00023C */   lui       $v0, (0xFFFFFF >> 16)
  .L8003B69C:
    /* 2BE9C 8003B69C 40100600 */  sll        $v0, $a2, 1
    /* 2BEA0 8003B6A0 0580043C */  lui        $a0, %hi(D_8004FE28)
    /* 2BEA4 8003B6A4 28FE848C */  lw         $a0, %lo(D_8004FE28)($a0)
    /* 2BEA8 8003B6A8 00000000 */  nop
    /* 2BEAC 8003B6AC 21104400 */  addu       $v0, $v0, $a0
    /* 2BEB0 8003B6B0 21186400 */  addu       $v1, $v1, $a0
    /* 2BEB4 8003B6B4 000048A4 */  sh         $t0, 0x0($v0)
    /* 2BEB8 8003B6B8 02140800 */  srl        $v0, $t0, 16
    /* 2BEBC 8003B6BC FF004230 */  andi       $v0, $v0, 0xFF
    /* 2BEC0 8003B6C0 000062A4 */  sh         $v0, 0x0($v1)
    /* 2BEC4 8003B6C4 FF00023C */  lui        $v0, (0xFFFFFF >> 16)
  .L8003B6C8:
    /* 2BEC8 8003B6C8 FFFF4234 */  ori        $v0, $v0, (0xFFFFFF & 0xFFFF)
    /* 2BECC 8003B6CC 24500201 */  and        $t2, $t0, $v0
  .L8003B6D0:
    /* 2BED0 8003B6D0 FF00023C */  lui        $v0, (0xFFFFFF >> 16)
    /* 2BED4 8003B6D4 FFFF4234 */  ori        $v0, $v0, (0xFFFFFF & 0xFFFF)
  .L8003B6D8:
    /* 2BED8 8003B6D8 0800E003 */  jr         $ra
    /* 2BEDC 8003B6DC 24104201 */   and       $v0, $t2, $v0
endlabel _SpuSetAnyVoice
    /* 2BEE0 8003B6E0 00000000 */  nop
