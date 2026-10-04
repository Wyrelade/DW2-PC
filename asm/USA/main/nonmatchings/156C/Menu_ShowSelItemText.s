nonmatching Menu_ShowSelItemText, 0xE0

glabel Menu_ShowSelItemText
    /* 70F0 800168F0 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 70F4 800168F4 1400B1AF */  sw         $s1, 0x14($sp)
    /* 70F8 800168F8 2188A000 */  addu       $s1, $a1, $zero
    /* 70FC 800168FC 54002426 */  addiu      $a0, $s1, 0x54
    /* 7100 80016900 58002526 */  addiu      $a1, $s1, 0x58
    /* 7104 80016904 2000BFAF */  sw         $ra, 0x20($sp)
    /* 7108 80016908 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 710C 8001690C 1800B2AF */  sw         $s2, 0x18($sp)
    /* 7110 80016910 9C4E000C */  jal        Menu_GridIndexColMajor
    /* 7114 80016914 1000B0AF */   sw        $s0, 0x10($sp)
    /* 7118 80016918 40003226 */  addiu      $s2, $s1, 0x40
    /* 711C 8001691C 21204002 */  addu       $a0, $s2, $zero
    /* 7120 80016920 E26E000C */  jal        Text_Close
    /* 7124 80016924 21804000 */   addu      $s0, $v0, $zero
    /* 7128 80016928 44003326 */  addiu      $s3, $s1, 0x44
    /* 712C 8001692C E26E000C */  jal        Text_Close
    /* 7130 80016930 21206002 */   addu      $a0, $s3, $zero
    /* 7134 80016934 40101000 */  sll        $v0, $s0, 1
    /* 7138 80016938 21105000 */  addu       $v0, $v0, $s0
    /* 713C 8001693C 40100200 */  sll        $v0, $v0, 1
    /* 7140 80016940 21102202 */  addu       $v0, $s1, $v0
    /* 7144 80016944 72005094 */  lhu        $s0, 0x72($v0)
    /* 7148 80016948 00000000 */  nop
    /* 714C 8001694C 19000012 */  beqz       $s0, .L800169B4
    /* 7150 80016950 05000224 */   addiu     $v0, $zero, 0x5
    /* 7154 80016954 64002386 */  lh         $v1, 0x64($s1)
    /* 7158 80016958 00000000 */  nop
    /* 715C 8001695C 0B006210 */  beq        $v1, $v0, .L8001698C
    /* 7160 80016960 00000000 */   nop
    /* 7164 80016964 1278000C */  jal        Item_GetNameText
    /* 7168 80016968 21200002 */   addu      $a0, $s0, $zero
    /* 716C 8001696C 21204002 */  addu       $a0, $s2, $zero
    /* 7170 80016970 21284000 */  addu       $a1, $v0, $zero
    /* 7174 80016974 21300000 */  addu       $a2, $zero, $zero
    /* 7178 80016978 12008797 */  lhu        $a3, %gp_rel(D_8005070A)($gp)
    /* 717C 8001697C 10008297 */  lhu        $v0, %gp_rel(Menu_ItemNamePos)($gp)
    /* 7180 80016980 003C0700 */  sll        $a3, $a3, 16
    /* 7184 80016984 3E4D000C */  jal        Text_OpenPacked
    /* 7188 80016988 25384700 */   or        $a3, $v0, $a3
  .L8001698C:
    /* 718C 8001698C 2178000C */  jal        Item_GetDescText
    /* 7190 80016990 21200002 */   addu      $a0, $s0, $zero
    /* 7194 80016994 21206002 */  addu       $a0, $s3, $zero
    /* 7198 80016998 21284000 */  addu       $a1, $v0, $zero
    /* 719C 8001699C 80000624 */  addiu      $a2, $zero, 0x80
    /* 71A0 800169A0 0E008797 */  lhu        $a3, %gp_rel(D_80050706)($gp)
    /* 71A4 800169A4 0C008297 */  lhu        $v0, %gp_rel(Menu_ItemMsgPos)($gp)
    /* 71A8 800169A8 003C0700 */  sll        $a3, $a3, 16
    /* 71AC 800169AC 3E4D000C */  jal        Text_OpenPacked
    /* 71B0 800169B0 25384700 */   or        $a3, $v0, $a3
  .L800169B4:
    /* 71B4 800169B4 2000BF8F */  lw         $ra, 0x20($sp)
    /* 71B8 800169B8 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 71BC 800169BC 1800B28F */  lw         $s2, 0x18($sp)
    /* 71C0 800169C0 1400B18F */  lw         $s1, 0x14($sp)
    /* 71C4 800169C4 1000B08F */  lw         $s0, 0x10($sp)
    /* 71C8 800169C8 0800E003 */  jr         $ra
    /* 71CC 800169CC 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel Menu_ShowSelItemText
