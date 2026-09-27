nonmatching func_8001C800, 0x18

glabel func_8001C800
    /* D000 8001C800 0580023C */  lui        $v0, %hi(Gpu_OtBufs)
    /* D004 8001C804 F84C4224 */  addiu      $v0, $v0, %lo(Gpu_OtBufs)
    /* D008 8001C808 00800334 */  ori        $v1, $zero, 0x8000
    /* D00C 8001C80C 21104300 */  addu       $v0, $v0, $v1
    /* D010 8001C810 0800E003 */  jr         $ra
    /* D014 8001C814 600044AC */   sw        $a0, 0x60($v0)
endlabel func_8001C800
