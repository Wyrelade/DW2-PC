nonmatching func_8006F1C8, 0xC8

glabel func_8006F1C8
    /* BE68 8006F1C8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* BE6C 8006F1CC 21488000 */  addu       $t1, $a0, $zero
    /* BE70 8006F1D0 0F000324 */  addiu      $v1, $zero, 0xF
    /* BE74 8006F1D4 1000BFAF */  sw         $ra, 0x10($sp)
    /* BE78 8006F1D8 5C07228D */  lw         $v0, 0x75C($t1)
    /* BE7C 8006F1DC 00800724 */  addiu      $a3, $zero, -0x8000
    /* BE80 8006F1E0 01004224 */  addiu      $v0, $v0, 0x1
    /* BE84 8006F1E4 5C0722AD */  sw         $v0, 0x75C($t1)
    /* BE88 8006F1E8 0F004230 */  andi       $v0, $v0, 0xF
    /* BE8C 8006F1EC 43100200 */  sra        $v0, $v0, 1
    /* BE90 8006F1F0 23186200 */  subu       $v1, $v1, $v0
    /* BE94 8006F1F4 1F006530 */  andi       $a1, $v1, 0x1F
    /* BE98 8006F1F8 80320500 */  sll        $a2, $a1, 10
    /* BE9C 8006F1FC 40210500 */  sll        $a0, $a1, 5
    /* BEA0 8006F200 00808834 */  ori        $t0, $a0, 0x8000
    /* BEA4 8006F204 2510C800 */  or         $v0, $a2, $t0
    /* BEA8 8006F208 1C0022A5 */  sh         $v0, 0x1C($t1)
    /* BEAC 8006F20C 2510A700 */  or         $v0, $a1, $a3
    /* BEB0 8006F210 25208700 */  or         $a0, $a0, $a3
    /* BEB4 8006F214 25208500 */  or         $a0, $a0, $a1
    /* BEB8 8006F218 1A0022A5 */  sh         $v0, 0x1A($t1)
    /* BEBC 8006F21C C2170300 */  srl        $v0, $v1, 31
    /* BEC0 8006F220 21186200 */  addu       $v1, $v1, $v0
    /* BEC4 8006F224 43180300 */  sra        $v1, $v1, 1
    /* BEC8 8006F228 1F006330 */  andi       $v1, $v1, 0x1F
    /* BECC 8006F22C 40110300 */  sll        $v0, $v1, 5
    /* BED0 8006F230 25104700 */  or         $v0, $v0, $a3
    /* BED4 8006F234 2530C200 */  or         $a2, $a2, $v0
    /* BED8 8006F238 2530C300 */  or         $a2, $a2, $v1
    /* BEDC 8006F23C 0680023C */  lui        $v0, %hi(D_8005F724)
    /* BEE0 8006F240 180024A5 */  sh         $a0, 0x18($t1)
    /* BEE4 8006F244 160028A5 */  sh         $t0, 0x16($t1)
    /* BEE8 8006F248 140026A5 */  sh         $a2, 0x14($t1)
    /* BEEC 8006F24C 24F7428C */  lw         $v0, %lo(D_8005F724)($v0)
    /* BEF0 8006F250 00000000 */  nop
    /* BEF4 8006F254 04004010 */  beqz       $v0, .L8006F268
    /* BEF8 8006F258 4AA90234 */   ori       $v0, $zero, 0xA94A
    /* BEFC 8006F25C 200022A5 */  sh         $v0, 0x20($t1)
    /* BF00 8006F260 9DBC0108 */  j          .L8006F274
    /* BF04 8006F264 18E30234 */   ori       $v0, $zero, 0xE318
  .L8006F268:
    /* BF08 8006F268 00800234 */  ori        $v0, $zero, 0x8000
    /* BF0C 8006F26C 200022A5 */  sh         $v0, 0x20($t1)
    /* BF10 8006F270 4AA90234 */  ori        $v0, $zero, 0xA94A
  .L8006F274:
    /* BF14 8006F274 220022A5 */  sh         $v0, 0x22($t1)
    /* BF18 8006F278 5ABC010C */  jal        func_8006F168
    /* BF1C 8006F27C 21202001 */   addu      $a0, $t1, $zero
    /* BF20 8006F280 1000BF8F */  lw         $ra, 0x10($sp)
    /* BF24 8006F284 00000000 */  nop
    /* BF28 8006F288 0800E003 */  jr         $ra
    /* BF2C 8006F28C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8006F1C8
