nonmatching Stg40_RevealAllEnts, 0x40

glabel Stg40_RevealAllEnts
    /* AF18 8006E278 0580023C */  lui        $v0, %hi(D_8005071C)
    /* AF1C 8006E27C 1C07428C */  lw         $v0, %lo(D_8005071C)($v0)
    /* AF20 8006E280 21280000 */  addu       $a1, $zero, $zero
    /* AF24 8006E284 18004424 */  addiu      $a0, $v0, 0x18
  .L8006E288:
    /* AF28 8006E288 0000838C */  lw         $v1, 0x0($a0)
    /* AF2C 8006E28C 00000000 */  nop
    /* AF30 8006E290 00806230 */  andi       $v0, $v1, 0x8000
    /* AF34 8006E294 02004010 */  beqz       $v0, .L8006E2A0
    /* AF38 8006E298 00506234 */   ori       $v0, $v1, 0x5000
    /* AF3C 8006E29C 000082AC */  sw         $v0, 0x0($a0)
  .L8006E2A0:
    /* AF40 8006E2A0 0100A524 */  addiu      $a1, $a1, 0x1
    /* AF44 8006E2A4 2900A228 */  slti       $v0, $a1, 0x29
    /* AF48 8006E2A8 F7FF4014 */  bnez       $v0, .L8006E288
    /* AF4C 8006E2AC 48008424 */   addiu     $a0, $a0, 0x48
    /* AF50 8006E2B0 0800E003 */  jr         $ra
    /* AF54 8006E2B4 00000000 */   nop
endlabel Stg40_RevealAllEnts
