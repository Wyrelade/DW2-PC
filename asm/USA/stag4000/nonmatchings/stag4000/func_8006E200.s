nonmatching func_8006E200, 0x78

glabel func_8006E200
    /* AEA0 8006E200 21380000 */  addu       $a3, $zero, $zero
    /* AEA4 8006E204 2130E000 */  addu       $a2, $a3, $zero
    /* AEA8 8006E208 00240400 */  sll        $a0, $a0, 16
    /* AEAC 8006E20C 03240400 */  sra        $a0, $a0, 16
    /* AEB0 8006E210 0580023C */  lui        $v0, %hi(D_8005071C)
    /* AEB4 8006E214 1C07428C */  lw         $v0, %lo(D_8005071C)($v0)
    /* AEB8 8006E218 002C0500 */  sll        $a1, $a1, 16
    /* AEBC 8006E21C 032C0500 */  sra        $a1, $a1, 16
    /* AEC0 8006E220 18004324 */  addiu      $v1, $v0, 0x18
  .L8006E224:
    /* AEC4 8006E224 18006284 */  lh         $v0, 0x18($v1)
    /* AEC8 8006E228 00000000 */  nop
    /* AECC 8006E22C 0C004414 */  bne        $v0, $a0, .L8006E260
    /* AED0 8006E230 00000000 */   nop
    /* AED4 8006E234 1A006284 */  lh         $v0, 0x1A($v1)
    /* AED8 8006E238 00000000 */  nop
    /* AEDC 8006E23C 08004514 */  bne        $v0, $a1, .L8006E260
    /* AEE0 8006E240 00000000 */   nop
    /* AEE4 8006E244 0000628C */  lw         $v0, 0x0($v1)
    /* AEE8 8006E248 00000000 */  nop
    /* AEEC 8006E24C 00804230 */  andi       $v0, $v0, 0x8000
    /* AEF0 8006E250 04004010 */  beqz       $v0, .L8006E264
    /* AEF4 8006E254 0100C624 */   addiu     $a2, $a2, 0x1
    /* AEF8 8006E258 9CB80108 */  j          .L8006E270
    /* AEFC 8006E25C 21386000 */   addu      $a3, $v1, $zero
  .L8006E260:
    /* AF00 8006E260 0100C624 */  addiu      $a2, $a2, 0x1
  .L8006E264:
    /* AF04 8006E264 2900C228 */  slti       $v0, $a2, 0x29
    /* AF08 8006E268 EEFF4014 */  bnez       $v0, .L8006E224
    /* AF0C 8006E26C 48006324 */   addiu     $v1, $v1, 0x48
  .L8006E270:
    /* AF10 8006E270 0800E003 */  jr         $ra
    /* AF14 8006E274 2110E000 */   addu      $v0, $a3, $zero
endlabel func_8006E200
