nonmatching Stg40_AutomapInitDims, 0x44

glabel Stg40_AutomapInitDims
    /* C050 8006F3B0 0580023C */  lui        $v0, %hi(D_8005071C)
    /* C054 8006F3B4 1C07438C */  lw         $v1, %lo(D_8005071C)($v0)
    /* C058 8006F3B8 00000000 */  nop
    /* C05C 8006F3BC 540E628C */  lw         $v0, 0xE54($v1)
    /* C060 8006F3C0 00000000 */  nop
    /* C064 8006F3C4 00004294 */  lhu        $v0, 0x0($v0)
    /* C068 8006F3C8 00000000 */  nop
    /* C06C 8006F3CC 660782A4 */  sh         $v0, 0x766($a0)
    /* C070 8006F3D0 540E628C */  lw         $v0, 0xE54($v1)
    /* C074 8006F3D4 66078384 */  lh         $v1, 0x766($a0)
    /* C078 8006F3D8 02004294 */  lhu        $v0, 0x2($v0)
    /* C07C 8006F3DC 02006104 */  bgez       $v1, .L8006F3E8
    /* C080 8006F3E0 680782A4 */   sh        $v0, 0x768($a0)
    /* C084 8006F3E4 07006324 */  addiu      $v1, $v1, 0x7
  .L8006F3E8:
    /* C088 8006F3E8 C3100300 */  sra        $v0, $v1, 3
    /* C08C 8006F3EC 0800E003 */  jr         $ra
    /* C090 8006F3F0 6A0782A4 */   sh        $v0, 0x76A($a0)
endlabel Stg40_AutomapInitDims
