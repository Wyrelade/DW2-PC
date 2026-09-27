nonmatching func_8006E2B8, 0x78

glabel func_8006E2B8
    /* AF58 8006E2B8 18008384 */  lh         $v1, 0x18($a0)
    /* AF5C 8006E2BC 1800A284 */  lh         $v0, 0x18($a1)
    /* AF60 8006E2C0 18008694 */  lhu        $a2, 0x18($a0)
    /* AF64 8006E2C4 23186200 */  subu       $v1, $v1, $v0
    /* AF68 8006E2C8 1800A294 */  lhu        $v0, 0x18($a1)
    /* AF6C 8006E2CC 03006004 */  bltz       $v1, .L8006E2DC
    /* AF70 8006E2D0 00000000 */   nop
    /* AF74 8006E2D4 B8B80108 */  j          .L8006E2E0
    /* AF78 8006E2D8 2330C200 */   subu      $a2, $a2, $v0
  .L8006E2DC:
    /* AF7C 8006E2DC 23304600 */  subu       $a2, $v0, $a2
  .L8006E2E0:
    /* AF80 8006E2E0 1A008284 */  lh         $v0, 0x1A($a0)
    /* AF84 8006E2E4 1A00A384 */  lh         $v1, 0x1A($a1)
    /* AF88 8006E2E8 1A008494 */  lhu        $a0, 0x1A($a0)
    /* AF8C 8006E2EC 1A00A594 */  lhu        $a1, 0x1A($a1)
    /* AF90 8006E2F0 23104300 */  subu       $v0, $v0, $v1
    /* AF94 8006E2F4 03004004 */  bltz       $v0, .L8006E304
    /* AF98 8006E2F8 00000000 */   nop
    /* AF9C 8006E2FC C2B80108 */  j          .L8006E308
    /* AFA0 8006E300 23208500 */   subu      $a0, $a0, $a1
  .L8006E304:
    /* AFA4 8006E304 2320A400 */  subu       $a0, $a1, $a0
  .L8006E308:
    /* AFA8 8006E308 00140600 */  sll        $v0, $a2, 16
    /* AFAC 8006E30C 03140200 */  sra        $v0, $v0, 16
    /* AFB0 8006E310 02004228 */  slti       $v0, $v0, 0x2
    /* AFB4 8006E314 04004010 */  beqz       $v0, .L8006E328
    /* AFB8 8006E318 21180000 */   addu      $v1, $zero, $zero
    /* AFBC 8006E31C 00140400 */  sll        $v0, $a0, 16
    /* AFC0 8006E320 03140200 */  sra        $v0, $v0, 16
    /* AFC4 8006E324 02004328 */  slti       $v1, $v0, 0x2
  .L8006E328:
    /* AFC8 8006E328 0800E003 */  jr         $ra
    /* AFCC 8006E32C 21106000 */   addu      $v0, $v1, $zero
endlabel func_8006E2B8
