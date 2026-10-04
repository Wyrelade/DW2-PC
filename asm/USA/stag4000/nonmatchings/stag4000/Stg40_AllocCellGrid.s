nonmatching Stg40_AllocCellGrid, 0x54

glabel Stg40_AllocCellGrid
    /* CB74 8006FED4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* CB78 8006FED8 1000B0AF */  sw         $s0, 0x10($sp)
    /* CB7C 8006FEDC 0580103C */  lui        $s0, %hi(Dung_StatePtr)
    /* CB80 8006FEE0 1C07028E */  lw         $v0, %lo(Dung_StatePtr)($s0)
    /* CB84 8006FEE4 1400BFAF */  sw         $ra, 0x14($sp)
    /* CB88 8006FEE8 540E428C */  lw         $v0, 0xE54($v0)
    /* CB8C 8006FEEC 00000000 */  nop
    /* CB90 8006FEF0 02004484 */  lh         $a0, 0x2($v0)
    /* CB94 8006FEF4 00004284 */  lh         $v0, 0x0($v0)
    /* CB98 8006FEF8 80200400 */  sll        $a0, $a0, 2
    /* CB9C 8006FEFC 18004400 */  mult       $v0, $a0
    /* CBA0 8006FF00 12200000 */  mflo       $a0
    /* CBA4 8006FF04 CF8B000C */  jal        Mem_Alloc
    /* CBA8 8006FF08 02000524 */   addiu     $a1, $zero, 0x2
    /* CBAC 8006FF0C 1C07038E */  lw         $v1, %lo(Dung_StatePtr)($s0)
    /* CBB0 8006FF10 00000000 */  nop
    /* CBB4 8006FF14 580E62AC */  sw         $v0, 0xE58($v1)
    /* CBB8 8006FF18 1400BF8F */  lw         $ra, 0x14($sp)
    /* CBBC 8006FF1C 1000B08F */  lw         $s0, 0x10($sp)
    /* CBC0 8006FF20 0800E003 */  jr         $ra
    /* CBC4 8006FF24 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Stg40_AllocCellGrid
