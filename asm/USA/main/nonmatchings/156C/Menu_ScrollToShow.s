nonmatching Menu_ScrollToShow, 0x40

glabel Menu_ScrollToShow
    /* 4230 80013A30 0000878C */  lw         $a3, 0x0($a0)
    /* 4234 80013A34 FFFFC224 */  addiu      $v0, $a2, -0x1
    /* 4238 80013A38 2318A700 */  subu       $v1, $a1, $a3
    /* 423C 80013A3C 2A104300 */  slt        $v0, $v0, $v1
    /* 4240 80013A40 04004010 */  beqz       $v0, .L80013A54
    /* 4244 80013A44 0100A224 */   addiu     $v0, $a1, 0x1
    /* 4248 80013A48 23104600 */  subu       $v0, $v0, $a2
    /* 424C 80013A4C 994E0008 */  j          .L80013A64
    /* 4250 80013A50 000082AC */   sw        $v0, 0x0($a0)
  .L80013A54:
    /* 4254 80013A54 2A10A700 */  slt        $v0, $a1, $a3
    /* 4258 80013A58 02004010 */  beqz       $v0, .L80013A64
    /* 425C 80013A5C 00000000 */   nop
    /* 4260 80013A60 000085AC */  sw         $a1, 0x0($a0)
  .L80013A64:
    /* 4264 80013A64 0000828C */  lw         $v0, 0x0($a0)
    /* 4268 80013A68 0800E003 */  jr         $ra
    /* 426C 80013A6C 23104700 */   subu      $v0, $v0, $a3
endlabel Menu_ScrollToShow
