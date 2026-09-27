/*
 * ApplyMatrixLV((ObjC0E4 *)obj, &obj->field_48, local);
 * Hand-written assembly in the original build (restored source, see PLAN Phase 4b).
 */

glabel ApplyMatrixLV
    lw         $t0, 0x0($a0)
    lw         $t1, 0x4($a0)
    lw         $t2, 0x8($a0)
    lw         $t3, 0xC($a0)
    lw         $t4, 0x10($a0)
    ctc2       $t0, $0
    ctc2       $t1, $1
    ctc2       $t2, $2
    ctc2       $t3, $3
    ctc2       $t4, $4
    lw         $t0, 0x0($a1)
    lw         $t1, 0x4($a1)
    lw         $t2, 0x8($a1)
    bgez       $t0, .L8002CFC8
     nop
    negu       $t0, $t0
    sra        $t3, $t0, 15
    negu       $t3, $t3
    andi       $t0, $t0, 0x7FFF
    b          .L8002CFD0
     negu       $t0, $t0
.L8002CFC8:
    sra        $t3, $t0, 15
    andi       $t0, $t0, 0x7FFF
.L8002CFD0:
    bgez       $t1, .L8002CFF0
     nop
    negu       $t1, $t1
    sra        $t4, $t1, 15
    negu       $t4, $t4
    andi       $t1, $t1, 0x7FFF
    b          .L8002CFF8
     negu       $t1, $t1
.L8002CFF0:
    sra        $t4, $t1, 15
    andi       $t1, $t1, 0x7FFF
.L8002CFF8:
    bgez       $t2, .L8002D018
     nop
    negu       $t2, $t2
    sra        $t5, $t2, 15
    negu       $t5, $t5
    andi       $t2, $t2, 0x7FFF
    b          .L8002D020
     negu       $t2, $t2
.L8002D018:
    sra        $t5, $t2, 15
    andi       $t2, $t2, 0x7FFF
.L8002D020:
    mtc2       $t3, $9
    mtc2       $t4, $10
    mtc2       $t5, $11
    nop
    mvmva      0, 0, 3, 3, 0
    mfc2       $t3, $25
    mfc2       $t4, $26
    mfc2       $t5, $27
    mtc2       $t0, $9
    mtc2       $t1, $10
    mtc2       $t2, $11
    nop
    mvmva      1, 0, 3, 3, 0
    bgez       $t3, .L8002D06C
     nop
    negu       $t3, $t3
    sll        $t3, $t3, 3
    b          .L8002D070
     negu       $t3, $t3
.L8002D06C:
    sll        $t3, $t3, 3
.L8002D070:
    bgez       $t4, .L8002D088
     nop
    negu       $t4, $t4
    sll        $t4, $t4, 3
    b          .L8002D08C
     negu       $t4, $t4
.L8002D088:
    sll        $t4, $t4, 3
.L8002D08C:
    bgez       $t5, .L8002D0A4
     nop
    negu       $t5, $t5
    sll        $t5, $t5, 3
    b          .L8002D0A8
     negu       $t5, $t5
.L8002D0A4:
    sll        $t5, $t5, 3
.L8002D0A8:
    mfc2       $t0, $25
    mfc2       $t1, $26
    mfc2       $t2, $27
    addu       $t0, $t0, $t3
    addu       $t1, $t1, $t4
    addu       $t2, $t2, $t5
    sw         $t0, 0x0($a2)
    sw         $t1, 0x4($a2)
    sw         $t2, 0x8($a2)
    jr         $ra
     addu       $v0, $a2, $zero
endlabel ApplyMatrixLV
