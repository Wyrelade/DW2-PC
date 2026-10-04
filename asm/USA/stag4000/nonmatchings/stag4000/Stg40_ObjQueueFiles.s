nonmatching Stg40_ObjQueueFiles, 0x8C

glabel Stg40_ObjQueueFiles
    /* B404 8006E764 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* B408 8006E768 1000B0AF */  sw         $s0, 0x10($sp)
    /* B40C 8006E76C 21808000 */  addu       $s0, $a0, $zero
    /* B410 8006E770 2120A000 */  addu       $a0, $a1, $zero
    /* B414 8006E774 1800BFAF */  sw         $ra, 0x18($sp)
    /* B418 8006E778 1400B1AF */  sw         $s1, 0x14($sp)
    /* B41C 8006E77C 34000286 */  lh         $v0, 0x34($s0)
    /* B420 8006E780 00000000 */  nop
    /* B424 8006E784 03004014 */  bnez       $v0, .L8006E794
    /* B428 8006E788 2188C000 */   addu      $s1, $a2, $zero
    /* B42C 8006E78C F7B90108 */  j          .L8006E7DC
    /* B430 8006E790 280000A2 */   sb        $zero, 0x28($s0)
  .L8006E794:
    /* B434 8006E794 28000292 */  lbu        $v0, 0x28($s0)
    /* B438 8006E798 00000000 */  nop
    /* B43C 8006E79C 0B004014 */  bnez       $v0, .L8006E7CC
    /* B440 8006E7A0 00000000 */   nop
    /* B444 8006E7A4 03008010 */  beqz       $a0, .L8006E7B4
    /* B448 8006E7A8 00000000 */   nop
    /* B44C 8006E7AC FD8E000C */  jal        Cd_QueueFile
    /* B450 8006E7B0 00000000 */   nop
  .L8006E7B4:
    /* B454 8006E7B4 04002012 */  beqz       $s1, .L8006E7C8
    /* B458 8006E7B8 10000224 */   addiu     $v0, $zero, 0x10
    /* B45C 8006E7BC FD8E000C */  jal        Cd_QueueFile
    /* B460 8006E7C0 21202002 */   addu      $a0, $s1, $zero
    /* B464 8006E7C4 10000224 */  addiu      $v0, $zero, 0x10
  .L8006E7C8:
    /* B468 8006E7C8 280002A2 */  sb         $v0, 0x28($s0)
  .L8006E7CC:
    /* B46C 8006E7CC 28000292 */  lbu        $v0, 0x28($s0)
    /* B470 8006E7D0 00000000 */  nop
    /* B474 8006E7D4 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* B478 8006E7D8 280002A2 */  sb         $v0, 0x28($s0)
  .L8006E7DC:
    /* B47C 8006E7DC 1800BF8F */  lw         $ra, 0x18($sp)
    /* B480 8006E7E0 1400B18F */  lw         $s1, 0x14($sp)
    /* B484 8006E7E4 1000B08F */  lw         $s0, 0x10($sp)
    /* B488 8006E7E8 0800E003 */  jr         $ra
    /* B48C 8006E7EC 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Stg40_ObjQueueFiles
