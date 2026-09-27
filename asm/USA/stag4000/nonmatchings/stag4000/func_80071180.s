nonmatching func_80071180, 0x44

glabel func_80071180
    /* DE20 80071180 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* DE24 80071184 1000BFAF */  sw         $ra, 0x10($sp)
    /* DE28 80071188 448E000C */  jal        Rand_Next
    /* DE2C 8007118C 00000000 */   nop
    /* DE30 80071190 FF0F4230 */  andi       $v0, $v0, 0xFFF
    /* DE34 80071194 40180200 */  sll        $v1, $v0, 1
    /* DE38 80071198 21186200 */  addu       $v1, $v1, $v0
    /* DE3C 8007119C C0180300 */  sll        $v1, $v1, 3
    /* DE40 800711A0 21186200 */  addu       $v1, $v1, $v0
    /* DE44 800711A4 80100300 */  sll        $v0, $v1, 2
    /* DE48 800711A8 02004104 */  bgez       $v0, .L800711B4
    /* DE4C 800711AC 00000000 */   nop
    /* DE50 800711B0 FF0F4224 */  addiu      $v0, $v0, 0xFFF
  .L800711B4:
    /* DE54 800711B4 1000BF8F */  lw         $ra, 0x10($sp)
    /* DE58 800711B8 02130200 */  srl        $v0, $v0, 12
    /* DE5C 800711BC 0800E003 */  jr         $ra
    /* DE60 800711C0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80071180
