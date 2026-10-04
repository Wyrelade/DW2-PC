nonmatching Gpu_SetBgClearColor, 0x38

glabel Gpu_SetBgClearColor
    /* C994 8001C194 21380000 */  addu       $a3, $zero, $zero
    /* C998 8001C198 01000824 */  addiu      $t0, $zero, 0x1
    /* C99C 8001C19C 0680023C */  lui        $v0, %hi(Sys_State)
    /* C9A0 8001C1A0 70F74324 */  addiu      $v1, $v0, %lo(Sys_State)
  .L8001C1A4:
    /* C9A4 8001C1A4 480068A0 */  sb         $t0, 0x48($v1)
    /* C9A8 8001C1A8 490064A0 */  sb         $a0, 0x49($v1)
    /* C9AC 8001C1AC 4A0065A0 */  sb         $a1, 0x4A($v1)
    /* C9B0 8001C1B0 4B0066A0 */  sb         $a2, 0x4B($v1)
    /* C9B4 8001C1B4 0100E724 */  addiu      $a3, $a3, 0x1
    /* C9B8 8001C1B8 0200E228 */  slti       $v0, $a3, 0x2
    /* C9BC 8001C1BC F9FF4014 */  bnez       $v0, .L8001C1A4
    /* C9C0 8001C1C0 5C006324 */   addiu     $v1, $v1, 0x5C
    /* C9C4 8001C1C4 0800E003 */  jr         $ra
    /* C9C8 8001C1C8 00000000 */   nop
endlabel Gpu_SetBgClearColor
