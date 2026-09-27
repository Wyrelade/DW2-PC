/*
 * s32 _card_read(s32, s32, u8 *);
 * Hand-written assembly in the original build (restored source, see PLAN Phase 4b).
 */

glabel _card_read
    addiu      $t2, $zero, 0xB0
    jr         $t2
     addiu      $t1, $zero, 0x4F         # B0(0x4F)
    nop
    nop
    lb         $a0, 0xE84($zero)
    nop
    lb         $a0, 0xFB8($zero)
    lb         $a0, 0xFE0($zero)
    lb         $a0, 0xD94($zero)
    lb         $a0, 0x16B4($zero)
    lb         $a0, -0x7228($zero)
    nop
    lb         $a0, 0x154C($zero)
    lb         $a0, 0xE20($zero)
    lb         $a0, 0xE9C($zero)
    lb         $a0, 0xEB4($zero)
    lb         $a0, 0xECC($zero)
    lb         $a0, 0xEE4($zero)
    lb         $a0, 0xF04($zero)
    lb         $a0, 0xF4C($zero)
    lb         $a0, 0xF80($zero)
    lb         $a0, 0xFA0($zero)
    lb         $a0, 0xF80($zero)
    lb         $a0, 0xF80($zero)
    lb         $a0, 0xF80($zero)
    lb         $a0, 0xE50($zero)
     alabel     D_80040D50
    lb         $a0, 0xCF4($zero)
    lb         $a2, -0x7098($zero)
    lb         $a3, 0x290C($zero)
    lb         $a3, 0x3F8($zero)
    lb         $a2, 0x5248($zero)
    lb         $a3, 0x3370($zero)
    lb         $a2, -0x7B78($zero)
    lb         $a2, -0x5A38($zero)
endlabel _card_read
