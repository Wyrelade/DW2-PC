nonmatching Stg40_AutomapRevealAll, 0xD4

glabel Stg40_AutomapRevealAll
    /* BD34 8006F094 0580043C */  lui        $a0, %hi(D_8005071C)
    /* BD38 8006F098 1C07828C */  lw         $v0, %lo(D_8005071C)($a0)
    /* BD3C 8006F09C D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* BD40 8006F0A0 1400B1AF */  sw         $s1, 0x14($sp)
    /* BD44 8006F0A4 2000BFAF */  sw         $ra, 0x20($sp)
    /* BD48 8006F0A8 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* BD4C 8006F0AC 1800B2AF */  sw         $s2, 0x18($sp)
    /* BD50 8006F0B0 1000B0AF */  sw         $s0, 0x10($sp)
    /* BD54 8006F0B4 540E428C */  lw         $v0, 0xE54($v0)
    /* BD58 8006F0B8 0780033C */  lui        $v1, %hi(Stg40_AutomapWork)
    /* BD5C 8006F0BC 02004284 */  lh         $v0, 0x2($v0)
    /* BD60 8006F0C0 B02B738C */  lw         $s3, %lo(Stg40_AutomapWork)($v1)
    /* BD64 8006F0C4 21004018 */  blez       $v0, .L8006F14C
    /* BD68 8006F0C8 21880000 */   addu      $s1, $zero, $zero
  .L8006F0CC:
    /* BD6C 8006F0CC 1C07828C */  lw         $v0, %lo(D_8005071C)($a0)
    /* BD70 8006F0D0 00000000 */  nop
    /* BD74 8006F0D4 540E428C */  lw         $v0, 0xE54($v0)
    /* BD78 8006F0D8 00000000 */  nop
    /* BD7C 8006F0DC 00004284 */  lh         $v0, 0x0($v0)
    /* BD80 8006F0E0 00000000 */  nop
    /* BD84 8006F0E4 0F004018 */  blez       $v0, .L8006F124
    /* BD88 8006F0E8 21800000 */   addu      $s0, $zero, $zero
    /* BD8C 8006F0EC 0580123C */  lui        $s2, %hi(D_8005071C)
    /* BD90 8006F0F0 21206002 */  addu       $a0, $s3, $zero
  .L8006F0F4:
    /* BD94 8006F0F4 21280002 */  addu       $a1, $s0, $zero
    /* BD98 8006F0F8 8BBD010C */  jal        Stg40_RevealCell
    /* BD9C 8006F0FC 21302002 */   addu      $a2, $s1, $zero
    /* BDA0 8006F100 1C07428E */  lw         $v0, %lo(D_8005071C)($s2)
    /* BDA4 8006F104 00000000 */  nop
    /* BDA8 8006F108 540E428C */  lw         $v0, 0xE54($v0)
    /* BDAC 8006F10C 00000000 */  nop
    /* BDB0 8006F110 00004284 */  lh         $v0, 0x0($v0)
    /* BDB4 8006F114 01001026 */  addiu      $s0, $s0, 0x1
    /* BDB8 8006F118 2A100202 */  slt        $v0, $s0, $v0
    /* BDBC 8006F11C F5FF4014 */  bnez       $v0, .L8006F0F4
    /* BDC0 8006F120 21206002 */   addu      $a0, $s3, $zero
  .L8006F124:
    /* BDC4 8006F124 0580043C */  lui        $a0, %hi(D_8005071C)
    /* BDC8 8006F128 1C07828C */  lw         $v0, %lo(D_8005071C)($a0)
    /* BDCC 8006F12C 00000000 */  nop
    /* BDD0 8006F130 540E428C */  lw         $v0, 0xE54($v0)
    /* BDD4 8006F134 00000000 */  nop
    /* BDD8 8006F138 02004284 */  lh         $v0, 0x2($v0)
    /* BDDC 8006F13C 01003126 */  addiu      $s1, $s1, 0x1
    /* BDE0 8006F140 2A102202 */  slt        $v0, $s1, $v0
    /* BDE4 8006F144 E1FF4014 */  bnez       $v0, .L8006F0CC
    /* BDE8 8006F148 00000000 */   nop
  .L8006F14C:
    /* BDEC 8006F14C 2000BF8F */  lw         $ra, 0x20($sp)
    /* BDF0 8006F150 1C00B38F */  lw         $s3, 0x1C($sp)
    /* BDF4 8006F154 1800B28F */  lw         $s2, 0x18($sp)
    /* BDF8 8006F158 1400B18F */  lw         $s1, 0x14($sp)
    /* BDFC 8006F15C 1000B08F */  lw         $s0, 0x10($sp)
    /* BE00 8006F160 0800E003 */  jr         $ra
    /* BE04 8006F164 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel Stg40_AutomapRevealAll
