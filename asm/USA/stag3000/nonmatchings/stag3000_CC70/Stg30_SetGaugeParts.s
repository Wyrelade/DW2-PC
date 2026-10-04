nonmatching Stg30_SetGaugeParts, 0x148

glabel Stg30_SetGaugeParts
    /* DCE4 80071044 0B00C010 */  beqz       $a2, .L80071074
    /* DCE8 80071048 E0FFBD27 */   addiu     $sp, $sp, -0x20
    /* DCEC 8007104C 80100600 */  sll        $v0, $a2, 2
    /* DCF0 80071050 21104600 */  addu       $v0, $v0, $a2
    /* DCF4 80071054 C0100200 */  sll        $v0, $v0, 3
    /* DCF8 80071058 1A004700 */  div        $zero, $v0, $a3
    /* DCFC 8007105C 12380000 */  mflo       $a3
    /* DD00 80071060 00000000 */  nop
    /* DD04 80071064 0500E014 */  bnez       $a3, .L8007107C
    /* DD08 80071068 40100500 */   sll       $v0, $a1, 1
    /* DD0C 8007106C 1FC40108 */  j          .L8007107C
    /* DD10 80071070 01000724 */   addiu     $a3, $zero, 0x1
  .L80071074:
    /* DD14 80071074 21380000 */  addu       $a3, $zero, $zero
    /* DD18 80071078 40100500 */  sll        $v0, $a1, 1
  .L8007107C:
    /* DD1C 8007107C 1400A2AF */  sw         $v0, 0x14($sp)
    /* DD20 80071080 80100500 */  sll        $v0, $a1, 2
    /* DD24 80071084 1800A2AF */  sw         $v0, 0x18($sp)
    /* DD28 80071088 C0100500 */  sll        $v0, $a1, 3
    /* DD2C 8007108C 1C00A2AF */  sw         $v0, 0x1C($sp)
    /* DD30 80071090 0A00E228 */  slti       $v0, $a3, 0xA
    /* DD34 80071094 07004010 */  beqz       $v0, .L800710B4
    /* DD38 80071098 1000A5AF */   sw        $a1, 0x10($sp)
    /* DD3C 8007109C 0A000224 */  addiu      $v0, $zero, 0xA
    /* DD40 800710A0 23184700 */  subu       $v1, $v0, $a3
    /* DD44 800710A4 0000A3AF */  sw         $v1, 0x0($sp)
    /* DD48 800710A8 0400A2AF */  sw         $v0, 0x4($sp)
    /* DD4C 800710AC 44C40108 */  j          .L80071110
    /* DD50 800710B0 0800A2AF */   sw        $v0, 0x8($sp)
  .L800710B4:
    /* DD54 800710B4 1400E228 */  slti       $v0, $a3, 0x14
    /* DD58 800710B8 07004010 */  beqz       $v0, .L800710D8
    /* DD5C 800710BC 14000224 */   addiu     $v0, $zero, 0x14
    /* DD60 800710C0 23104700 */  subu       $v0, $v0, $a3
    /* DD64 800710C4 0400A2AF */  sw         $v0, 0x4($sp)
    /* DD68 800710C8 0A000224 */  addiu      $v0, $zero, 0xA
    /* DD6C 800710CC 0000A0AF */  sw         $zero, 0x0($sp)
    /* DD70 800710D0 44C40108 */  j          .L80071110
    /* DD74 800710D4 0800A2AF */   sw        $v0, 0x8($sp)
  .L800710D8:
    /* DD78 800710D8 1E00E228 */  slti       $v0, $a3, 0x1E
    /* DD7C 800710DC 07004010 */  beqz       $v0, .L800710FC
    /* DD80 800710E0 1E000224 */   addiu     $v0, $zero, 0x1E
    /* DD84 800710E4 23104700 */  subu       $v0, $v0, $a3
    /* DD88 800710E8 0800A2AF */  sw         $v0, 0x8($sp)
    /* DD8C 800710EC 0A000224 */  addiu      $v0, $zero, 0xA
    /* DD90 800710F0 0000A0AF */  sw         $zero, 0x0($sp)
    /* DD94 800710F4 44C40108 */  j          .L80071110
    /* DD98 800710F8 0400A0AF */   sw        $zero, 0x4($sp)
  .L800710FC:
    /* DD9C 800710FC 28000224 */  addiu      $v0, $zero, 0x28
    /* DDA0 80071100 23104700 */  subu       $v0, $v0, $a3
    /* DDA4 80071104 0000A0AF */  sw         $zero, 0x0($sp)
    /* DDA8 80071108 0400A0AF */  sw         $zero, 0x4($sp)
    /* DDAC 8007110C 0800A0AF */  sw         $zero, 0x8($sp)
  .L80071110:
    /* DDB0 80071110 0C00A2AF */  sw         $v0, 0xC($sp)
    /* DDB4 80071114 0000828C */  lw         $v0, 0x0($a0)
    /* DDB8 80071118 00000000 */  nop
    /* DDBC 8007111C 19004010 */  beqz       $v0, .L80071184
    /* DDC0 80071120 00000000 */   nop
    /* DDC4 80071124 1000A927 */  addiu      $t1, $sp, 0x10
    /* DDC8 80071128 03000824 */  addiu      $t0, $zero, 0x3
    /* DDCC 8007112C 0C008624 */  addiu      $a2, $a0, 0xC
  .L80071130:
    /* DDD0 80071130 21180000 */  addu       $v1, $zero, $zero
    /* DDD4 80071134 1000C78C */  lw         $a3, 0x10($a2)
    /* DDD8 80071138 21282001 */  addu       $a1, $t1, $zero
  .L8007113C:
    /* DDDC 8007113C 0000A28C */  lw         $v0, 0x0($a1)
    /* DDE0 80071140 00000000 */  nop
    /* DDE4 80071144 0600E214 */  bne        $a3, $v0, .L80071160
    /* DDE8 80071148 23100301 */   subu      $v0, $t0, $v1
    /* DDEC 8007114C 80100200 */  sll        $v0, $v0, 2
    /* DDF0 80071150 2110A203 */  addu       $v0, $sp, $v0
    /* DDF4 80071154 00004290 */  lbu        $v0, 0x0($v0)
    /* DDF8 80071158 00000000 */  nop
    /* DDFC 8007115C 0000C2A0 */  sb         $v0, 0x0($a2)
  .L80071160:
    /* DE00 80071160 01006324 */  addiu      $v1, $v1, 0x1
    /* DE04 80071164 04006228 */  slti       $v0, $v1, 0x4
    /* DE08 80071168 F4FF4014 */  bnez       $v0, .L8007113C
    /* DE0C 8007116C 0400A524 */   addiu     $a1, $a1, 0x4
    /* DE10 80071170 28008424 */  addiu      $a0, $a0, 0x28
    /* DE14 80071174 0000828C */  lw         $v0, 0x0($a0)
    /* DE18 80071178 00000000 */  nop
    /* DE1C 8007117C ECFF4014 */  bnez       $v0, .L80071130
    /* DE20 80071180 2800C624 */   addiu     $a2, $a2, 0x28
  .L80071184:
    /* DE24 80071184 0800E003 */  jr         $ra
    /* DE28 80071188 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Stg30_SetGaugeParts
