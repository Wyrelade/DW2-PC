nonmatching func_8001BC24, 0x1E4

glabel func_8001BC24
    /* C424 8001BC24 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* C428 8001BC28 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* C42C 8001BC2C 21988000 */  addu       $s3, $a0, $zero
    /* C430 8001BC30 1000B0AF */  sw         $s0, 0x10($sp)
    /* C434 8001BC34 2180A000 */  addu       $s0, $a1, $zero
    /* C438 8001BC38 09000424 */  addiu      $a0, $zero, 0x9
    /* C43C 8001BC3C FFFF0524 */  addiu      $a1, $zero, -0x1
    /* C440 8001BC40 2130A000 */  addu       $a2, $a1, $zero
    /* C444 8001BC44 2000BFAF */  sw         $ra, 0x20($sp)
    /* C448 8001BC48 1800B2AF */  sw         $s2, 0x18($sp)
    /* C44C 8001BC4C 4445000C */  jal        Task_FindFirst
    /* C450 8001BC50 1400B1AF */   sw        $s1, 0x14($sp)
    /* C454 8001BC54 65004010 */  beqz       $v0, .L8001BDEC
    /* C458 8001BC58 21880000 */   addu      $s1, $zero, $zero
    /* C45C 8001BC5C 2C00528C */  lw         $s2, 0x2C($v0)
    /* C460 8001BC60 E26E000C */  jal        Text_Close
    /* C464 8001BC64 21206002 */   addu      $a0, $s3, $zero
    /* C468 8001BC68 21184002 */  addu       $v1, $s2, $zero
  .L8001BC6C:
    /* C46C 8001BC6C 00006290 */  lbu        $v0, 0x0($v1)
    /* C470 8001BC70 00000000 */  nop
    /* C474 8001BC74 05004010 */  beqz       $v0, .L8001BC8C
    /* C478 8001BC78 00000000 */   nop
    /* C47C 8001BC7C 01003126 */  addiu      $s1, $s1, 0x1
    /* C480 8001BC80 3200222A */  slti       $v0, $s1, 0x32
    /* C484 8001BC84 F9FF4014 */  bnez       $v0, .L8001BC6C
    /* C488 8001BC88 34006324 */   addiu     $v1, $v1, 0x34
  .L8001BC8C:
    /* C48C 8001BC8C 0C00028E */  lw         $v0, 0xC($s0)
    /* C490 8001BC90 00000000 */  nop
    /* C494 8001BC94 07004014 */  bnez       $v0, .L8001BCB4
    /* C498 8001BC98 00000000 */   nop
    /* C49C 8001BC9C 0000028E */  lw         $v0, 0x0($s0)
    /* C4A0 8001BCA0 00000000 */  nop
    /* C4A4 8001BCA4 02004014 */  bnez       $v0, .L8001BCB0
    /* C4A8 8001BCA8 09000224 */   addiu     $v0, $zero, 0x9
    /* C4AC 8001BCAC 07000224 */  addiu      $v0, $zero, 0x7
  .L8001BCB0:
    /* C4B0 8001BCB0 0C0002AE */  sw         $v0, 0xC($s0)
  .L8001BCB4:
    /* C4B4 8001BCB4 1000028E */  lw         $v0, 0x10($s0)
    /* C4B8 8001BCB8 00000000 */  nop
    /* C4BC 8001BCBC 08004014 */  bnez       $v0, .L8001BCE0
    /* C4C0 8001BCC0 40181100 */   sll       $v1, $s1, 1
    /* C4C4 8001BCC4 0000028E */  lw         $v0, 0x0($s0)
    /* C4C8 8001BCC8 00000000 */  nop
    /* C4CC 8001BCCC 02004014 */  bnez       $v0, .L8001BCD8
    /* C4D0 8001BCD0 0F000224 */   addiu     $v0, $zero, 0xF
    /* C4D4 8001BCD4 0A000224 */  addiu      $v0, $zero, 0xA
  .L8001BCD8:
    /* C4D8 8001BCD8 100002AE */  sw         $v0, 0x10($s0)
    /* C4DC 8001BCDC 40181100 */  sll        $v1, $s1, 1
  .L8001BCE0:
    /* C4E0 8001BCE0 21187100 */  addu       $v1, $v1, $s1
    /* C4E4 8001BCE4 80180300 */  sll        $v1, $v1, 2
    /* C4E8 8001BCE8 21187100 */  addu       $v1, $v1, $s1
    /* C4EC 8001BCEC 80180300 */  sll        $v1, $v1, 2
    /* C4F0 8001BCF0 21184302 */  addu       $v1, $s2, $v1
    /* C4F4 8001BCF4 01000224 */  addiu      $v0, $zero, 0x1
    /* C4F8 8001BCF8 000062A0 */  sb         $v0, 0x0($v1)
    /* C4FC 8001BCFC 00000292 */  lbu        $v0, 0x0($s0)
    /* C500 8001BD00 00000000 */  nop
    /* C504 8001BD04 010062A0 */  sb         $v0, 0x1($v1)
    /* C508 8001BD08 04000292 */  lbu        $v0, 0x4($s0)
    /* C50C 8001BD0C 00000000 */  nop
    /* C510 8001BD10 020062A0 */  sb         $v0, 0x2($v1)
    /* C514 8001BD14 1400028E */  lw         $v0, 0x14($s0)
    /* C518 8001BD18 00000000 */  nop
    /* C51C 8001BD1C 080062AC */  sw         $v0, 0x8($v1)
    /* C520 8001BD20 08000296 */  lhu        $v0, 0x8($s0)
    /* C524 8001BD24 00000000 */  nop
    /* C528 8001BD28 60FF4224 */  addiu      $v0, $v0, -0xA0
    /* C52C 8001BD2C 1C0062A4 */  sh         $v0, 0x1C($v1)
    /* C530 8001BD30 0A000296 */  lhu        $v0, 0xA($s0)
    /* C534 8001BD34 00000000 */  nop
    /* C538 8001BD38 88FF4224 */  addiu      $v0, $v0, -0x78
    /* C53C 8001BD3C 1E0062A4 */  sh         $v0, 0x1E($v1)
    /* C540 8001BD40 0C000292 */  lbu        $v0, 0xC($s0)
    /* C544 8001BD44 00000000 */  nop
    /* C548 8001BD48 030062A0 */  sb         $v0, 0x3($v1)
    /* C54C 8001BD4C 10000292 */  lbu        $v0, 0x10($s0)
    /* C550 8001BD50 00000000 */  nop
    /* C554 8001BD54 040062A0 */  sb         $v0, 0x4($v1)
    /* C558 8001BD58 18000296 */  lhu        $v0, 0x18($s0)
    /* C55C 8001BD5C 00000000 */  nop
    /* C560 8001BD60 060062A4 */  sh         $v0, 0x6($v1)
    /* C564 8001BD64 1C00028E */  lw         $v0, 0x1C($s0)
    /* C568 8001BD68 00000000 */  nop
    /* C56C 8001BD6C 0C0062AC */  sw         $v0, 0xC($v1)
    /* C570 8001BD70 2000028E */  lw         $v0, 0x20($s0)
    /* C574 8001BD74 00000000 */  nop
    /* C578 8001BD78 100062AC */  sw         $v0, 0x10($v1)
    /* C57C 8001BD7C 2400028E */  lw         $v0, 0x24($s0)
    /* C580 8001BD80 00000000 */  nop
    /* C584 8001BD84 140062AC */  sw         $v0, 0x14($v1)
    /* C588 8001BD88 2800028E */  lw         $v0, 0x28($s0)
    /* C58C 8001BD8C 00000000 */  nop
    /* C590 8001BD90 180062AC */  sw         $v0, 0x18($v1)
    /* C594 8001BD94 04000292 */  lbu        $v0, 0x4($s0)
    /* C598 8001BD98 00000000 */  nop
    /* C59C 8001BD9C 200062A0 */  sb         $v0, 0x20($v1)
    /* C5A0 8001BDA0 18000292 */  lbu        $v0, 0x18($s0)
    /* C5A4 8001BDA4 220060A0 */  sb         $zero, 0x22($v1)
    /* C5A8 8001BDA8 230060A0 */  sb         $zero, 0x23($v1)
    /* C5AC 8001BDAC 240060A0 */  sb         $zero, 0x24($v1)
    /* C5B0 8001BDB0 250060A0 */  sb         $zero, 0x25($v1)
    /* C5B4 8001BDB4 210062A0 */  sb         $v0, 0x21($v1)
    /* C5B8 8001BDB8 270060A0 */  sb         $zero, 0x27($v1)
    /* C5BC 8001BDBC 260060A0 */  sb         $zero, 0x26($v1)
    /* C5C0 8001BDC0 280060A0 */  sb         $zero, 0x28($v1)
    /* C5C4 8001BDC4 290060A0 */  sb         $zero, 0x29($v1)
    /* C5C8 8001BDC8 2A0060A0 */  sb         $zero, 0x2A($v1)
    /* C5CC 8001BDCC 2B0060A0 */  sb         $zero, 0x2B($v1)
    /* C5D0 8001BDD0 2C0060A0 */  sb         $zero, 0x2C($v1)
    /* C5D4 8001BDD4 2D0060A0 */  sb         $zero, 0x2D($v1)
    /* C5D8 8001BDD8 2E0060A0 */  sb         $zero, 0x2E($v1)
    /* C5DC 8001BDDC 2F0060A0 */  sb         $zero, 0x2F($v1)
    /* C5E0 8001BDE0 300060A0 */  sb         $zero, 0x30($v1)
    /* C5E4 8001BDE4 310060A0 */  sb         $zero, 0x31($v1)
    /* C5E8 8001BDE8 000071AE */  sw         $s1, 0x0($s3)
  .L8001BDEC:
    /* C5EC 8001BDEC 2000BF8F */  lw         $ra, 0x20($sp)
    /* C5F0 8001BDF0 1C00B38F */  lw         $s3, 0x1C($sp)
    /* C5F4 8001BDF4 1800B28F */  lw         $s2, 0x18($sp)
    /* C5F8 8001BDF8 1400B18F */  lw         $s1, 0x14($sp)
    /* C5FC 8001BDFC 1000B08F */  lw         $s0, 0x10($sp)
    /* C600 8001BE00 0800E003 */  jr         $ra
    /* C604 8001BE04 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8001BC24
