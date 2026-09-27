nonmatching Gfx_InitTexSlots, 0x64

glabel Gfx_InitTexSlots
    /* D23C 8001CA3C 21200000 */  addu       $a0, $zero, $zero
    /* D240 8001CA40 E0030524 */  addiu      $a1, $zero, 0x3E0
    /* D244 8001CA44 0680023C */  lui        $v0, %hi(Gfx_TexSlots)
    /* D248 8001CA48 60CD4324 */  addiu      $v1, $v0, %lo(Gfx_TexSlots)
  .L8001CA4C:
    /* D24C 8001CA4C C2170400 */  srl        $v0, $a0, 31
    /* D250 8001CA50 21108200 */  addu       $v0, $a0, $v0
    /* D254 8001CA54 43100200 */  sra        $v0, $v0, 1
    /* D258 8001CA58 40110200 */  sll        $v0, $v0, 5
    /* D25C 8001CA5C 2310A200 */  subu       $v0, $a1, $v0
    /* D260 8001CA60 180062AC */  sw         $v0, 0x18($v1)
    /* D264 8001CA64 01008230 */  andi       $v0, $a0, 0x1
    /* D268 8001CA68 00120200 */  sll        $v0, $v0, 8
    /* D26C 8001CA6C 140064AC */  sw         $a0, 0x14($v1)
    /* D270 8001CA70 1C0062AC */  sw         $v0, 0x1C($v1)
    /* D274 8001CA74 000060AC */  sw         $zero, 0x0($v1)
    /* D278 8001CA78 040060AC */  sw         $zero, 0x4($v1)
    /* D27C 8001CA7C 080060AC */  sw         $zero, 0x8($v1)
    /* D280 8001CA80 0C0060AC */  sw         $zero, 0xC($v1)
    /* D284 8001CA84 100060A4 */  sh         $zero, 0x10($v1)
    /* D288 8001CA88 01008424 */  addiu      $a0, $a0, 0x1
    /* D28C 8001CA8C 40008228 */  slti       $v0, $a0, 0x40
    /* D290 8001CA90 EEFF4014 */  bnez       $v0, .L8001CA4C
    /* D294 8001CA94 20006324 */   addiu     $v1, $v1, 0x20
    /* D298 8001CA98 0800E003 */  jr         $ra
    /* D29C 8001CA9C 00000000 */   nop
endlabel Gfx_InitTexSlots
