nonmatching rcos, 0xA0

glabel rcos
    /* 1D3C4 8002CBC4 02008104 */  bgez       $a0, .L8002CBD0
    /* 1D3C8 8002CBC8 00000000 */   nop
    /* 1D3CC 8002CBCC 23200400 */  negu       $a0, $a0
  .L8002CBD0:
    /* 1D3D0 8002CBD0 FF0F8430 */  andi       $a0, $a0, 0xFFF
    /* 1D3D4 8002CBD4 01088228 */  slti       $v0, $a0, 0x801
    /* 1D3D8 8002CBD8 10004010 */  beqz       $v0, .L8002CC1C
    /* 1D3DC 8002CBDC 01048228 */   slti      $v0, $a0, 0x401
    /* 1D3E0 8002CBE0 08004010 */  beqz       $v0, .L8002CC04
    /* 1D3E4 8002CBE4 00040224 */   addiu     $v0, $zero, 0x400
    /* 1D3E8 8002CBE8 23104400 */  subu       $v0, $v0, $a0
    /* 1D3EC 8002CBEC 40100200 */  sll        $v0, $v0, 1
    /* 1D3F0 8002CBF0 0580013C */  lui        $at, %hi(D_80049110)
    /* 1D3F4 8002CBF4 21082200 */  addu       $at, $at, $v0
    /* 1D3F8 8002CBF8 10912284 */  lh         $v0, %lo(D_80049110)($at)
    /* 1D3FC 8002CBFC 17B30008 */  j          .L8002CC5C
    /* 1D400 8002CC00 00000000 */   nop
  .L8002CC04:
    /* 1D404 8002CC04 40100400 */  sll        $v0, $a0, 1
    /* 1D408 8002CC08 0580013C */  lui        $at, %hi(D_80048910)
    /* 1D40C 8002CC0C 21082200 */  addu       $at, $at, $v0
    /* 1D410 8002CC10 10892284 */  lh         $v0, %lo(D_80048910)($at)
    /* 1D414 8002CC14 17B30008 */  j          .L8002CC5C
    /* 1D418 8002CC18 23100200 */   negu      $v0, $v0
  .L8002CC1C:
    /* 1D41C 8002CC1C 010C8228 */  slti       $v0, $a0, 0xC01
    /* 1D420 8002CC20 07004014 */  bnez       $v0, .L8002CC40
    /* 1D424 8002CC24 000C0224 */   addiu     $v0, $zero, 0xC00
    /* 1D428 8002CC28 40100400 */  sll        $v0, $a0, 1
    /* 1D42C 8002CC2C 0480013C */  lui        $at, %hi(D_80047910)
    /* 1D430 8002CC30 21082200 */  addu       $at, $at, $v0
    /* 1D434 8002CC34 10792284 */  lh         $v0, %lo(D_80047910)($at)
    /* 1D438 8002CC38 17B30008 */  j          .L8002CC5C
    /* 1D43C 8002CC3C 00000000 */   nop
  .L8002CC40:
    /* 1D440 8002CC40 23104400 */  subu       $v0, $v0, $a0
    /* 1D444 8002CC44 40100200 */  sll        $v0, $v0, 1
    /* 1D448 8002CC48 0580013C */  lui        $at, %hi(D_80049110)
    /* 1D44C 8002CC4C 21082200 */  addu       $at, $at, $v0
    /* 1D450 8002CC50 10912284 */  lh         $v0, %lo(D_80049110)($at)
    /* 1D454 8002CC54 00000000 */  nop
    /* 1D458 8002CC58 23100200 */  negu       $v0, $v0
  .L8002CC5C:
    /* 1D45C 8002CC5C 0800E003 */  jr         $ra
    /* 1D460 8002CC60 00000000 */   nop
endlabel rcos
