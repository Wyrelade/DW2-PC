nonmatching Digi_GetExpToNextLevel, 0x1D4

glabel Digi_GetExpToNextLevel
    /* F184 8001E984 2A288500 */  slt        $a1, $a0, $a1
    /* F188 8001E988 0300A014 */  bnez       $a1, .L8001E998
    /* F18C 8001E98C F505023C */   lui       $v0, (0x5F5E0FF >> 16)
    /* F190 8001E990 0800E003 */  jr         $ra
    /* F194 8001E994 FFE04234 */   ori       $v0, $v0, (0x5F5E0FF & 0xFFFF)
  .L8001E998:
    /* F198 8001E998 3E008228 */  slti       $v0, $a0, 0x3E
    /* F19C 8001E99C 06004014 */  bnez       $v0, .L8001E9B8
    /* F1A0 8001E9A0 C3FF8724 */   addiu     $a3, $a0, -0x3D
    /* F1A4 8001E9A4 0C00033C */  lui        $v1, (0xC9CAC >> 16)
    /* F1A8 8001E9A8 AC9C6334 */  ori        $v1, $v1, (0xC9CAC & 0xFFFF)
    /* F1AC 8001E9AC 00140700 */  sll        $v0, $a3, 16
    /* F1B0 8001E9B0 CE7A0008 */  j          .L8001EB38
    /* F1B4 8001E9B4 23104700 */   subu      $v0, $v0, $a3
  .L8001E9B8:
    /* F1B8 8001E9B8 1F008228 */  slti       $v0, $a0, 0x1F
    /* F1BC 8001E9BC 17004014 */  bnez       $v0, .L8001EA1C
    /* F1C0 8001E9C0 15008228 */   slti      $v0, $a0, 0x15
    /* F1C4 8001E9C4 E2FF8724 */  addiu      $a3, $a0, -0x1E
    /* F1C8 8001E9C8 1800E700 */  mult       $a3, $a3
    /* F1CC 8001E9CC 12180000 */  mflo       $v1
    /* F1D0 8001E9D0 00000000 */  nop
    /* F1D4 8001E9D4 00000000 */  nop
    /* F1D8 8001E9D8 18006700 */  mult       $v1, $a3
    /* F1DC 8001E9DC 12200000 */  mflo       $a0
    /* F1E0 8001E9E0 80100400 */  sll        $v0, $a0, 2
    /* F1E4 8001E9E4 21104400 */  addu       $v0, $v0, $a0
    /* F1E8 8001E9E8 00210300 */  sll        $a0, $v1, 4
    /* F1EC 8001E9EC 23208300 */  subu       $a0, $a0, $v1
    /* F1F0 8001E9F0 21208200 */  addu       $a0, $a0, $v0
    /* F1F4 8001E9F4 C0100700 */  sll        $v0, $a3, 3
    /* F1F8 8001E9F8 21104700 */  addu       $v0, $v0, $a3
    /* F1FC 8001E9FC 00110200 */  sll        $v0, $v0, 4
    /* F200 8001EA00 23104700 */  subu       $v0, $v0, $a3
    /* F204 8001EA04 C0100200 */  sll        $v0, $v0, 3
    /* F208 8001EA08 21104700 */  addu       $v0, $v0, $a3
    /* F20C 8001EA0C 21104400 */  addu       $v0, $v0, $a0
    /* F210 8001EA10 80100200 */  sll        $v0, $v0, 2
    /* F214 8001EA14 CF7A0008 */  j          .L8001EB3C
    /* F218 8001EA18 68794324 */   addiu     $v1, $v0, 0x7968
  .L8001EA1C:
    /* F21C 8001EA1C 18004014 */  bnez       $v0, .L8001EA80
    /* F220 8001EA20 0B008228 */   slti      $v0, $a0, 0xB
    /* F224 8001EA24 ECFF8724 */  addiu      $a3, $a0, -0x14
    /* F228 8001EA28 1800E700 */  mult       $a3, $a3
    /* F22C 8001EA2C 12200000 */  mflo       $a0
    /* F230 8001EA30 00000000 */  nop
    /* F234 8001EA34 00000000 */  nop
    /* F238 8001EA38 18008700 */  mult       $a0, $a3
    /* F23C 8001EA3C 12180000 */  mflo       $v1
    /* F240 8001EA40 80100300 */  sll        $v0, $v1, 2
    /* F244 8001EA44 21104300 */  addu       $v0, $v0, $v1
    /* F248 8001EA48 00190400 */  sll        $v1, $a0, 4
    /* F24C 8001EA4C 23186400 */  subu       $v1, $v1, $a0
    /* F250 8001EA50 21186200 */  addu       $v1, $v1, $v0
    /* F254 8001EA54 40180300 */  sll        $v1, $v1, 1
    /* F258 8001EA58 80100700 */  sll        $v0, $a3, 2
    /* F25C 8001EA5C 21104700 */  addu       $v0, $v0, $a3
    /* F260 8001EA60 80100200 */  sll        $v0, $v0, 2
    /* F264 8001EA64 23104700 */  subu       $v0, $v0, $a3
    /* F268 8001EA68 00110200 */  sll        $v0, $v0, 4
    /* F26C 8001EA6C 21104700 */  addu       $v0, $v0, $a3
    /* F270 8001EA70 80100200 */  sll        $v0, $v0, 2
    /* F274 8001EA74 21186200 */  addu       $v1, $v1, $v0
    /* F278 8001EA78 CF7A0008 */  j          .L8001EB3C
    /* F27C 8001EA7C F8166324 */   addiu     $v1, $v1, 0x16F8
  .L8001EA80:
    /* F280 8001EA80 1E004014 */  bnez       $v0, .L8001EAFC
    /* F284 8001EA84 21388000 */   addu      $a3, $a0, $zero
    /* F288 8001EA88 F6FF8724 */  addiu      $a3, $a0, -0xA
    /* F28C 8001EA8C 1800E700 */  mult       $a3, $a3
    /* F290 8001EA90 12200000 */  mflo       $a0
    /* F294 8001EA94 00000000 */  nop
    /* F298 8001EA98 00000000 */  nop
    /* F29C 8001EA9C 18008700 */  mult       $a0, $a3
    /* F2A0 8001EAA0 5555053C */  lui        $a1, (0x55555556 >> 16)
    /* F2A4 8001EAA4 5655A534 */  ori        $a1, $a1, (0x55555556 & 0xFFFF)
    /* F2A8 8001EAA8 12100000 */  mflo       $v0
    /* F2AC 8001EAAC 80180200 */  sll        $v1, $v0, 2
    /* F2B0 8001EAB0 21186200 */  addu       $v1, $v1, $v0
    /* F2B4 8001EAB4 40180300 */  sll        $v1, $v1, 1
    /* F2B8 8001EAB8 18006500 */  mult       $v1, $a1
    /* F2BC 8001EABC C31F0300 */  sra        $v1, $v1, 31
    /* F2C0 8001EAC0 80100400 */  sll        $v0, $a0, 2
    /* F2C4 8001EAC4 21104400 */  addu       $v0, $v0, $a0
    /* F2C8 8001EAC8 40100200 */  sll        $v0, $v0, 1
    /* F2CC 8001EACC 10480000 */  mfhi       $t1
    /* F2D0 8001EAD0 23182301 */  subu       $v1, $t1, $v1
    /* F2D4 8001EAD4 21186200 */  addu       $v1, $v1, $v0
    /* F2D8 8001EAD8 C0100700 */  sll        $v0, $a3, 3
    /* F2DC 8001EADC 23104700 */  subu       $v0, $v0, $a3
    /* F2E0 8001EAE0 80100200 */  sll        $v0, $v0, 2
    /* F2E4 8001EAE4 23104700 */  subu       $v0, $v0, $a3
    /* F2E8 8001EAE8 80100200 */  sll        $v0, $v0, 2
    /* F2EC 8001EAEC 23104700 */  subu       $v0, $v0, $a3
    /* F2F0 8001EAF0 21186200 */  addu       $v1, $v1, $v0
    /* F2F4 8001EAF4 CF7A0008 */  j          .L8001EB3C
    /* F2F8 8001EAF8 E0016324 */   addiu     $v1, $v1, 0x1E0
  .L8001EAFC:
    /* F2FC 8001EAFC 1800E700 */  mult       $a3, $a3
    /* F300 8001EB00 12200000 */  mflo       $a0
    /* F304 8001EB04 00000000 */  nop
    /* F308 8001EB08 00000000 */  nop
    /* F30C 8001EB0C 18008700 */  mult       $a0, $a3
    /* F310 8001EB10 12180000 */  mflo       $v1
    /* F314 8001EB14 5555023C */  lui        $v0, (0x55555556 >> 16)
    /* F318 8001EB18 56554234 */  ori        $v0, $v0, (0x55555556 & 0xFFFF)
    /* F31C 8001EB1C 18006200 */  mult       $v1, $v0
    /* F320 8001EB20 C31F0300 */  sra        $v1, $v1, 31
    /* F324 8001EB24 80100700 */  sll        $v0, $a3, 2
    /* F328 8001EB28 21104700 */  addu       $v0, $v0, $a3
    /* F32C 8001EB2C 10480000 */  mfhi       $t1
    /* F330 8001EB30 23182301 */  subu       $v1, $t1, $v1
    /* F334 8001EB34 21186400 */  addu       $v1, $v1, $a0
  .L8001EB38:
    /* F338 8001EB38 21186200 */  addu       $v1, $v1, $v0
  .L8001EB3C:
    /* F33C 8001EB3C 2A106600 */  slt        $v0, $v1, $a2
    /* F340 8001EB40 03004010 */  beqz       $v0, .L8001EB50
    /* F344 8001EB44 23106600 */   subu      $v0, $v1, $a2
    /* F348 8001EB48 0800E003 */  jr         $ra
    /* F34C 8001EB4C 21100000 */   addu      $v0, $zero, $zero
  .L8001EB50:
    /* F350 8001EB50 0800E003 */  jr         $ra
    /* F354 8001EB54 00000000 */   nop
endlabel Digi_GetExpToNextLevel
