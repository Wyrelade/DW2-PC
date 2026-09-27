nonmatching func_8001BE08, 0x6C

glabel func_8001BE08
    /* C608 8001BE08 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* C60C 8001BE0C 1000B0AF */  sw         $s0, 0x10($sp)
    /* C610 8001BE10 21808000 */  addu       $s0, $a0, $zero
    /* C614 8001BE14 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* C618 8001BE18 03000216 */  bne        $s0, $v0, .L8001BE28
    /* C61C 8001BE1C 1400BFAF */   sw        $ra, 0x14($sp)
    /* C620 8001BE20 996F0008 */  j          .L8001BE64
    /* C624 8001BE24 01000224 */   addiu     $v0, $zero, 0x1
  .L8001BE28:
    /* C628 8001BE28 09000424 */  addiu      $a0, $zero, 0x9
    /* C62C 8001BE2C FFFF0524 */  addiu      $a1, $zero, -0x1
    /* C630 8001BE30 4445000C */  jal        Task_FindFirst
    /* C634 8001BE34 2130A000 */   addu      $a2, $a1, $zero
    /* C638 8001BE38 21184000 */  addu       $v1, $v0, $zero
    /* C63C 8001BE3C 09006010 */  beqz       $v1, .L8001BE64
    /* C640 8001BE40 21100000 */   addu      $v0, $zero, $zero
    /* C644 8001BE44 40101000 */  sll        $v0, $s0, 1
    /* C648 8001BE48 21105000 */  addu       $v0, $v0, $s0
    /* C64C 8001BE4C 80100200 */  sll        $v0, $v0, 2
    /* C650 8001BE50 21105000 */  addu       $v0, $v0, $s0
    /* C654 8001BE54 2C00638C */  lw         $v1, 0x2C($v1)
    /* C658 8001BE58 80100200 */  sll        $v0, $v0, 2
    /* C65C 8001BE5C 21186200 */  addu       $v1, $v1, $v0
    /* C660 8001BE60 23006290 */  lbu        $v0, 0x23($v1)
  .L8001BE64:
    /* C664 8001BE64 1400BF8F */  lw         $ra, 0x14($sp)
    /* C668 8001BE68 1000B08F */  lw         $s0, 0x10($sp)
    /* C66C 8001BE6C 0800E003 */  jr         $ra
    /* C670 8001BE70 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8001BE08
