nonmatching Anim_SetModelAnim, 0xA4

glabel Anim_SetModelAnim
    /* F9A8 8001F1A8 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* F9AC 8001F1AC 1800B2AF */  sw         $s2, 0x18($sp)
    /* F9B0 8001F1B0 2190A000 */  addu       $s2, $a1, $zero
    /* F9B4 8001F1B4 1000B0AF */  sw         $s0, 0x10($sp)
    /* F9B8 8001F1B8 0A001024 */  addiu      $s0, $zero, 0xA
    /* F9BC 8001F1BC 6666053C */  lui        $a1, (0x66666667 >> 16)
    /* F9C0 8001F1C0 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* F9C4 8001F1C4 1400B1AF */  sw         $s1, 0x14($sp)
    /* F9C8 8001F1C8 3C00918C */  lw         $s1, 0x3C($a0)
    /* F9CC 8001F1CC 6766A534 */  ori        $a1, $a1, (0x66666667 & 0xFFFF)
    /* F9D0 8001F1D0 540032AE */  sw         $s2, 0x54($s1)
    /* F9D4 8001F1D4 580020AE */  sw         $zero, 0x58($s1)
    /* F9D8 8001F1D8 500020AE */  sw         $zero, 0x50($s1)
    /* F9DC 8001F1DC 2A105002 */  slt        $v0, $s2, $s0
  .L8001F1E0:
    /* F9E0 8001F1E0 0D004010 */  beqz       $v0, .L8001F218
    /* F9E4 8001F1E4 18000502 */   mult      $s0, $a1
    /* F9E8 8001F1E8 C3171000 */  sra        $v0, $s0, 31
    /* F9EC 8001F1EC 0C00848C */  lw         $a0, 0xC($a0)
    /* F9F0 8001F1F0 10180000 */  mfhi       $v1
    /* F9F4 8001F1F4 83280300 */  sra        $a1, $v1, 2
    /* F9F8 8001F1F8 2328A200 */  subu       $a1, $a1, $v0
    /* F9FC 8001F1FC CA79000C */  jal        func_8001E728
    /* FA00 8001F200 FFFFA524 */   addiu     $a1, $a1, -0x1
    /* FA04 8001F204 480022AE */  sw         $v0, 0x48($s1)
    /* FA08 8001F208 F6FF0226 */  addiu      $v0, $s0, -0xA
    /* FA0C 8001F20C 23104202 */  subu       $v0, $s2, $v0
    /* FA10 8001F210 8A7C0008 */  j          .L8001F228
    /* FA14 8001F214 4C0022AE */   sw        $v0, 0x4C($s1)
  .L8001F218:
    /* FA18 8001F218 0A001026 */  addiu      $s0, $s0, 0xA
    /* FA1C 8001F21C 6F00022A */  slti       $v0, $s0, 0x6F
    /* FA20 8001F220 EFFF4014 */  bnez       $v0, .L8001F1E0
    /* FA24 8001F224 2A105002 */   slt       $v0, $s2, $s0
  .L8001F228:
    /* FA28 8001F228 01000224 */  addiu      $v0, $zero, 0x1
    /* FA2C 8001F22C 5C0022AE */  sw         $v0, 0x5C($s1)
    /* FA30 8001F230 600020AE */  sw         $zero, 0x60($s1)
    /* FA34 8001F234 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* FA38 8001F238 1800B28F */  lw         $s2, 0x18($sp)
    /* FA3C 8001F23C 1400B18F */  lw         $s1, 0x14($sp)
    /* FA40 8001F240 1000B08F */  lw         $s0, 0x10($sp)
    /* FA44 8001F244 0800E003 */  jr         $ra
    /* FA48 8001F248 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Anim_SetModelAnim
