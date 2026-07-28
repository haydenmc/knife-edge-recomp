#include "recomp.h"
#ifdef __cplusplus
extern "C" {
#endif
/* src/main/register_overlays.cpp - whole-section overlay tracking. */
extern void ke_overlay_dma(uint32_t rom, int32_t ram_addr, uint32_t size);
/* ultramodern/src/scheduling.cpp - pumps the external message queue and
   yields to any higher-priority ready thread; used by SPIN_YIELD_HOOKS. */
extern void yield_self_1ms(uint8_t* rdram);
#ifdef __cplusplus
}
#endif
#include "funcs.h"

RECOMP_FUNC void alAuxBusPull_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DFE20: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800DFE24: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x800DFE28: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800DFE2C: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800DFE30: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800DFE34: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800DFE38: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800DFE3C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800DFE40: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800DFE44: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800DFE48: lw          $v1, 0x1C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1C);
    // 0x800DFE4C: lui         $t6, 0x200
    ctx->r14 = S32(0X200 << 16);
    // 0x800DFE50: sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6 << 1);
    // 0x800DFE54: lui         $t7, 0x200
    ctx->r15 = S32(0X200 << 16);
    // 0x800DFE58: ori         $t6, $t6, 0x6C0
    ctx->r14 = ctx->r14 | 0X6C0;
    // 0x800DFE5C: ori         $t7, $t7, 0x800
    ctx->r15 = ctx->r15 | 0X800;
    // 0x800DFE60: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x800DFE64: sw          $v0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r2;
    // 0x800DFE68: sw          $t7, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r15;
    // 0x800DFE6C: sw          $v0, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r2;
    // 0x800DFE70: lw          $t8, 0x14($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X14);
    // 0x800DFE74: or          $s4, $a2, $zero
    ctx->r20 = ctx->r6 | 0;
    // 0x800DFE78: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x800DFE7C: or          $s6, $a3, $zero
    ctx->r22 = ctx->r7 | 0;
    // 0x800DFE80: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800DFE84: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800DFE88: blez        $t8, L_800DFECC
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800DFE8C: addiu       $s2, $t0, 0x10
        ctx->r18 = ADD32(ctx->r8, 0X10);
            goto L_800DFECC;
    }
    // 0x800DFE8C: addiu       $s2, $t0, 0x10
    ctx->r18 = ADD32(ctx->r8, 0X10);
    // 0x800DFE90: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
L_800DFE94:
    // 0x800DFE94: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800DFE98: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x800DFE9C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800DFEA0: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x800DFEA4: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x800DFEA8: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    // 0x800DFEAC: jalr        $t9
    // 0x800DFEB0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800DFEB0: nop

    after_0:
    // 0x800DFEB4: lw          $t1, 0x14($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X14);
    // 0x800DFEB8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800DFEBC: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800DFEC0: slt         $at, $s0, $t1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800DFEC4: bne         $at, $zero, L_800DFE94
    if (ctx->r1 != 0) {
        // 0x800DFEC8: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_800DFE94;
    }
    // 0x800DFEC8: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
L_800DFECC:
    // 0x800DFECC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800DFED0: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x800DFED4: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800DFED8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800DFEDC: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800DFEE0: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800DFEE4: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800DFEE8: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800DFEEC: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800DFEF0: jr          $ra
    // 0x800DFEF4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800DFEF4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800DFEF8: nop

    // 0x800DFEFC: nop

;}
RECOMP_FUNC void alSaveParam_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DFF00: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800DFF04: beq         $a1, $at, L_800DFF20
    if (ctx->r5 == ctx->r1) {
        // 0x800DFF08: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800DFF20;
    }
    // 0x800DFF08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800DFF0C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x800DFF10: beql        $a1, $at, L_800DFF2C
    if (ctx->r5 == ctx->r1) {
        // 0x800DFF14: sw          $a2, 0x14($a0)
        MEM_W(0X14, ctx->r4) = ctx->r6;
            goto L_800DFF2C;
    }
    goto skip_0;
    // 0x800DFF14: sw          $a2, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r6;
    skip_0:
    // 0x800DFF18: jr          $ra
    // 0x800DFF1C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800DFF1C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800DFF20:
    // 0x800DFF20: jr          $ra
    // 0x800DFF24: sw          $a2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r6;
    return;
    // 0x800DFF24: sw          $a2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r6;
    // 0x800DFF28: sw          $a2, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r6;
L_800DFF2C:
    // 0x800DFF2C: jr          $ra
    // 0x800DFF30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800DFF30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void alSavePull_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DFF34: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800DFF38: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800DFF3C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800DFF40: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x800DFF44: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x800DFF48: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800DFF4C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800DFF50: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x800DFF54: jalr        $t9
    // 0x800DFF58: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800DFF58: nop

    after_0:
    // 0x800DFF5C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800DFF60: lui         $v1, 0x800
    ctx->r3 = S32(0X800 << 16);
    // 0x800DFF64: lui         $t2, 0x440
    ctx->r10 = S32(0X440 << 16);
    // 0x800DFF68: sll         $t8, $a2, 1
    ctx->r24 = S32(ctx->r6 << 1);
    // 0x800DFF6C: sll         $t3, $a2, 2
    ctx->r11 = S32(ctx->r6 << 2);
    // 0x800DFF70: andi        $t0, $t8, 0xFFFF
    ctx->r8 = ctx->r24 & 0XFFFF;
    // 0x800DFF74: ori         $t2, $t2, 0x580
    ctx->r10 = ctx->r10 | 0X580;
    // 0x800DFF78: lui         $t1, 0xD00
    ctx->r9 = S32(0XD00 << 16);
    // 0x800DFF7C: andi        $t4, $t3, 0xFFFF
    ctx->r12 = ctx->r11 & 0XFFFF;
    // 0x800DFF80: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x800DFF84: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x800DFF88: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x800DFF8C: sw          $t1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r9;
    // 0x800DFF90: sw          $t2, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r10;
    // 0x800DFF94: sw          $t4, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r12;
    // 0x800DFF98: sw          $v1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r3;
    // 0x800DFF9C: sw          $t5, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r13;
    // 0x800DFFA0: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800DFFA4: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x800DFFA8: lw          $t7, 0x14($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14);
    // 0x800DFFAC: sw          $t7, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r15;
    // 0x800DFFB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800DFFB4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800DFFB8: jr          $ra
    // 0x800DFFBC: nop

    return;
    // 0x800DFFBC: nop

;}
RECOMP_FUNC void _Litob_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E14D0: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x800E14D4: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800E14D8: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // 0x800E14DC: addiu       $v1, $zero, 0x58
    ctx->r3 = ADD32(0, 0X58);
    // 0x800E14E0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800E14E4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800E14E8: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x800E14EC: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x800E14F0: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800E14F4: bne         $v1, $v0, L_800E1508
    if (ctx->r3 != ctx->r2) {
        // 0x800E14F8: sw          $a1, 0x94($sp)
        MEM_W(0X94, ctx->r29) = ctx->r5;
            goto L_800E1508;
    }
    // 0x800E14F8: sw          $a1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r5;
    // 0x800E14FC: lui         $s3, 0x800F
    ctx->r19 = S32(0X800F << 16);
    // 0x800E1500: b           L_800E1510
    // 0x800E1504: addiu       $s3, $s3, -0x2C6C
    ctx->r19 = ADD32(ctx->r19, -0X2C6C);
        goto L_800E1510;
    // 0x800E1504: addiu       $s3, $s3, -0x2C6C
    ctx->r19 = ADD32(ctx->r19, -0X2C6C);
L_800E1508:
    // 0x800E1508: lui         $s3, 0x800F
    ctx->r19 = S32(0X800F << 16);
    // 0x800E150C: addiu       $s3, $s3, -0x2C80
    ctx->r19 = ADD32(ctx->r19, -0X2C80);
L_800E1510:
    // 0x800E1510: addiu       $at, $zero, 0x6F
    ctx->r1 = ADD32(0, 0X6F);
    // 0x800E1514: bne         $v0, $at, L_800E1524
    if (ctx->r2 != ctx->r1) {
        // 0x800E1518: addiu       $s0, $zero, 0x18
        ctx->r16 = ADD32(0, 0X18);
            goto L_800E1524;
    }
    // 0x800E1518: addiu       $s0, $zero, 0x18
    ctx->r16 = ADD32(0, 0X18);
    // 0x800E151C: b           L_800E1544
    // 0x800E1520: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
        goto L_800E1544;
    // 0x800E1520: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
L_800E1524:
    // 0x800E1524: addiu       $at, $zero, 0x78
    ctx->r1 = ADD32(0, 0X78);
    // 0x800E1528: beq         $v0, $at, L_800E1540
    if (ctx->r2 == ctx->r1) {
        // 0x800E152C: addiu       $t0, $zero, 0x10
        ctx->r8 = ADD32(0, 0X10);
            goto L_800E1540;
    }
    // 0x800E152C: addiu       $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
    // 0x800E1530: beq         $v1, $v0, L_800E1540
    if (ctx->r3 == ctx->r2) {
        // 0x800E1534: nop
    
            goto L_800E1540;
    }
    // 0x800E1534: nop

    // 0x800E1538: b           L_800E1540
    // 0x800E153C: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
        goto L_800E1540;
    // 0x800E153C: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
L_800E1540:
    // 0x800E1540: or          $t1, $t0, $zero
    ctx->r9 = ctx->r8 | 0;
L_800E1544:
    // 0x800E1544: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x800E1548: lw          $t9, 0x4($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X4);
    // 0x800E154C: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x800E1550: sw          $t8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r24;
    // 0x800E1554: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x800E1558: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x800E155C: beq         $v0, $at, L_800E1570
    if (ctx->r2 == ctx->r1) {
        // 0x800E1560: sw          $t9, 0x64($sp)
        MEM_W(0X64, ctx->r29) = ctx->r25;
            goto L_800E1570;
    }
    // 0x800E1560: sw          $t9, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r25;
    // 0x800E1564: addiu       $at, $zero, 0x69
    ctx->r1 = ADD32(0, 0X69);
    // 0x800E1568: bnel        $v0, $at, L_800E15AC
    if (ctx->r2 != ctx->r1) {
        // 0x800E156C: lw          $t2, 0x60($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X60);
            goto L_800E15AC;
    }
    goto skip_0;
    // 0x800E156C: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    skip_0:
L_800E1570:
    // 0x800E1570: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x800E1574: bgtzl       $t4, L_800E15AC
    if (SIGNED(ctx->r12) > 0) {
        // 0x800E1578: lw          $t2, 0x60($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X60);
            goto L_800E15AC;
    }
    goto skip_1;
    // 0x800E1578: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    skip_1:
    // 0x800E157C: bltz        $t4, L_800E158C
    if (SIGNED(ctx->r12) < 0) {
        // 0x800E1580: lw          $t6, 0x60($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X60);
            goto L_800E158C;
    }
    // 0x800E1580: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x800E1584: b           L_800E15AC
    // 0x800E1588: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
        goto L_800E15AC;
    // 0x800E1588: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
L_800E158C:
    // 0x800E158C: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x800E1590: nor         $t8, $t6, $zero
    ctx->r24 = ~(ctx->r14 | 0);
    // 0x800E1594: sltiu       $at, $t7, 0x1
    ctx->r1 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800E1598: addu        $t8, $t8, $at
    ctx->r24 = ADD32(ctx->r24, ctx->r1);
    // 0x800E159C: negu        $t9, $t7
    ctx->r25 = SUB32(0, ctx->r15);
    // 0x800E15A0: sw          $t9, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r25;
    // 0x800E15A4: sw          $t8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r24;
    // 0x800E15A8: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
L_800E15AC:
    // 0x800E15AC: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x800E15B0: addiu       $t0, $zero, 0x17
    ctx->r8 = ADD32(0, 0X17);
    // 0x800E15B4: bne         $t2, $zero, L_800E15D0
    if (ctx->r10 != 0) {
        // 0x800E15B8: lw          $a0, 0x60($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X60);
            goto L_800E15D0;
    }
    // 0x800E15B8: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x800E15BC: bnel        $t3, $zero, L_800E15D4
    if (ctx->r11 != 0) {
        // 0x800E15C0: addiu       $s0, $zero, 0x17
        ctx->r16 = ADD32(0, 0X17);
            goto L_800E15D4;
    }
    goto skip_2;
    // 0x800E15C0: addiu       $s0, $zero, 0x17
    ctx->r16 = ADD32(0, 0X17);
    skip_2:
    // 0x800E15C4: lw          $t4, 0x24($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X24);
    // 0x800E15C8: beql        $t4, $zero, L_800E160C
    if (ctx->r12 == 0) {
        // 0x800E15CC: addiu       $s2, $sp, 0x78
        ctx->r18 = ADD32(ctx->r29, 0X78);
            goto L_800E160C;
    }
    goto skip_3;
    // 0x800E15CC: addiu       $s2, $sp, 0x78
    ctx->r18 = ADD32(ctx->r29, 0X78);
    skip_3:
L_800E15D0:
    // 0x800E15D0: addiu       $s0, $zero, 0x17
    ctx->r16 = ADD32(0, 0X17);
L_800E15D4:
    // 0x800E15D4: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x800E15D8: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
    // 0x800E15DC: sra         $a2, $t1, 31
    ctx->r6 = S32(SIGNED(ctx->r9) >> 31);
    // 0x800E15E0: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x800E15E4: jal         0x800DC3BC
    // 0x800E15E8: sw          $t1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r9;
    __ull_rem_recomp(rdram, ctx);
        goto after_0;
    // 0x800E15E8: sw          $t1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r9;
    after_0:
    // 0x800E15EC: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x800E15F0: addu        $t6, $v1, $s3
    ctx->r14 = ADD32(ctx->r3, ctx->r19);
    // 0x800E15F4: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x800E15F8: addiu       $s2, $sp, 0x78
    ctx->r18 = ADD32(ctx->r29, 0X78);
    // 0x800E15FC: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x800E1600: addu        $t8, $s2, $t0
    ctx->r24 = ADD32(ctx->r18, ctx->r8);
    // 0x800E1604: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
    // 0x800E1608: addiu       $s2, $sp, 0x78
    ctx->r18 = ADD32(ctx->r29, 0X78);
L_800E160C:
    // 0x800E160C: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x800E1610: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x800E1614: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
    // 0x800E1618: sra         $a2, $t1, 31
    ctx->r6 = S32(SIGNED(ctx->r9) >> 31);
    // 0x800E161C: jal         0x800DC3F8
    // 0x800E1620: sw          $t1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r9;
    __ull_div_recomp(rdram, ctx);
        goto after_1;
    // 0x800E1620: sw          $t1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r9;
    after_1:
    // 0x800E1624: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x800E1628: sw          $v1, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r3;
    // 0x800E162C: bltz        $v0, L_800E16DC
    if (SIGNED(ctx->r2) < 0) {
        // 0x800E1630: sw          $v0, 0x0($s1)
        MEM_W(0X0, ctx->r17) = ctx->r2;
            goto L_800E16DC;
    }
    // 0x800E1630: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x800E1634: bgtz        $v0, L_800E1644
    if (SIGNED(ctx->r2) > 0) {
        // 0x800E1638: nop
    
            goto L_800E1644;
    }
    // 0x800E1638: nop

    // 0x800E163C: beql        $v1, $zero, L_800E16E0
    if (ctx->r3 == 0) {
        // 0x800E1640: addiu       $t4, $zero, 0x18
        ctx->r12 = ADD32(0, 0X18);
            goto L_800E16E0;
    }
    goto skip_4;
    // 0x800E1640: addiu       $t4, $zero, 0x18
    ctx->r12 = ADD32(0, 0X18);
    skip_4:
L_800E1644:
    // 0x800E1644: blez        $s0, L_800E16DC
    if (SIGNED(ctx->r16) <= 0) {
        // 0x800E1648: sra         $t4, $t1, 31
        ctx->r12 = S32(SIGNED(ctx->r9) >> 31);
            goto L_800E16DC;
    }
    // 0x800E1648: sra         $t4, $t1, 31
    ctx->r12 = S32(SIGNED(ctx->r9) >> 31);
    // 0x800E164C: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x800E1650: lw          $t3, 0x4($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X4);
    // 0x800E1654: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x800E1658: sw          $t4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r12;
    // 0x800E165C: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
    // 0x800E1660: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    // 0x800E1664: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
L_800E1668:
    // 0x800E1668: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x800E166C: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x800E1670: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x800E1674: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x800E1678: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800E167C: jal         0x800E3B10
    // 0x800E1680: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    lldiv_recomp(rdram, ctx);
        goto after_2;
    // 0x800E1680: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_2:
    // 0x800E1684: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x800E1688: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x800E168C: addiu       $a0, $s0, -0x1
    ctx->r4 = ADD32(ctx->r16, -0X1);
    // 0x800E1690: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800E1694: sw          $t9, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r25;
    // 0x800E1698: lw          $t3, 0x5C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X5C);
    // 0x800E169C: addu        $t7, $s2, $a0
    ctx->r15 = ADD32(ctx->r18, ctx->r4);
    // 0x800E16A0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800E16A4: addu        $t5, $t3, $s3
    ctx->r13 = ADD32(ctx->r11, ctx->r19);
    // 0x800E16A8: lbu         $t6, 0x0($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X0);
    // 0x800E16AC: sb          $t6, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r14;
    // 0x800E16B0: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x800E16B4: lw          $t9, 0x4($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X4);
    // 0x800E16B8: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x800E16BC: bltz        $t8, L_800E16DC
    if (SIGNED(ctx->r24) < 0) {
        // 0x800E16C0: sw          $t9, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r25;
            goto L_800E16DC;
    }
    // 0x800E16C0: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x800E16C4: bgtz        $t8, L_800E16D4
    if (SIGNED(ctx->r24) > 0) {
        // 0x800E16C8: nop
    
            goto L_800E16D4;
    }
    // 0x800E16C8: nop

    // 0x800E16CC: beql        $t9, $zero, L_800E16E0
    if (ctx->r25 == 0) {
        // 0x800E16D0: addiu       $t4, $zero, 0x18
        ctx->r12 = ADD32(0, 0X18);
            goto L_800E16E0;
    }
    goto skip_5;
    // 0x800E16D0: addiu       $t4, $zero, 0x18
    ctx->r12 = ADD32(0, 0X18);
    skip_5:
L_800E16D4:
    // 0x800E16D4: bgtzl       $s0, L_800E1668
    if (SIGNED(ctx->r16) > 0) {
        // 0x800E16D8: lw          $t6, 0x38($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X38);
            goto L_800E1668;
    }
    goto skip_6;
    // 0x800E16D8: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    skip_6:
L_800E16DC:
    // 0x800E16DC: addiu       $t4, $zero, 0x18
    ctx->r12 = ADD32(0, 0X18);
L_800E16E0:
    // 0x800E16E0: subu        $a2, $t4, $s0
    ctx->r6 = SUB32(ctx->r12, ctx->r16);
    // 0x800E16E4: sw          $a2, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r6;
    // 0x800E16E8: lw          $a0, 0x8($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X8);
    // 0x800E16EC: jal         0x800DD750
    // 0x800E16F0: addu        $a1, $s2, $s0
    ctx->r5 = ADD32(ctx->r18, ctx->r16);
    memcpy_recomp(rdram, ctx);
        goto after_3;
    // 0x800E16F0: addu        $a1, $s2, $s0
    ctx->r5 = ADD32(ctx->r18, ctx->r16);
    after_3:
    // 0x800E16F4: lw          $a1, 0x14($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X14);
    // 0x800E16F8: lw          $a0, 0x24($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X24);
    // 0x800E16FC: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800E1700: beq         $at, $zero, L_800E170C
    if (ctx->r1 == 0) {
        // 0x800E1704: subu        $t5, $a0, $a1
        ctx->r13 = SUB32(ctx->r4, ctx->r5);
            goto L_800E170C;
    }
    // 0x800E1704: subu        $t5, $a0, $a1
    ctx->r13 = SUB32(ctx->r4, ctx->r5);
    // 0x800E1708: sw          $t5, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r13;
L_800E170C:
    // 0x800E170C: bgezl       $a0, L_800E1750
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800E1710: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_800E1750;
    }
    goto skip_7;
    // 0x800E1710: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_7:
    // 0x800E1714: lw          $t6, 0x30($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X30);
    // 0x800E1718: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x800E171C: andi        $t7, $t6, 0x14
    ctx->r15 = ctx->r14 & 0X14;
    // 0x800E1720: bnel        $t7, $at, L_800E1750
    if (ctx->r15 != ctx->r1) {
        // 0x800E1724: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_800E1750;
    }
    goto skip_8;
    // 0x800E1724: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_8:
    // 0x800E1728: lw          $t8, 0x28($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X28);
    // 0x800E172C: lw          $t9, 0xC($s1)
    ctx->r25 = MEM_W(ctx->r17, 0XC);
    // 0x800E1730: lw          $v0, 0x10($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X10);
    // 0x800E1734: subu        $t2, $t8, $t9
    ctx->r10 = SUB32(ctx->r24, ctx->r25);
    // 0x800E1738: subu        $t3, $t2, $v0
    ctx->r11 = SUB32(ctx->r10, ctx->r2);
    // 0x800E173C: subu        $s0, $t3, $a1
    ctx->r16 = SUB32(ctx->r11, ctx->r5);
    // 0x800E1740: blez        $s0, L_800E174C
    if (SIGNED(ctx->r16) <= 0) {
        // 0x800E1744: addu        $t4, $v0, $s0
        ctx->r12 = ADD32(ctx->r2, ctx->r16);
            goto L_800E174C;
    }
    // 0x800E1744: addu        $t4, $v0, $s0
    ctx->r12 = ADD32(ctx->r2, ctx->r16);
    // 0x800E1748: sw          $t4, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r12;
L_800E174C:
    // 0x800E174C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800E1750:
    // 0x800E1750: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800E1754: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800E1758: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x800E175C: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x800E1760: jr          $ra
    // 0x800E1764: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x800E1764: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    // 0x800E1768: nop

    // 0x800E176C: nop

;}
RECOMP_FUNC void func_800E1770(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E1770: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E1774: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800E1778: sll         $t6, $s2, 16
    ctx->r14 = S32(ctx->r18 << 16);
    // 0x800E177C: sra         $s2, $t6, 16
    ctx->r18 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800E1780: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800E1784: sll         $t8, $s3, 16
    ctx->r24 = S32(ctx->r19 << 16);
    // 0x800E1788: sra         $s3, $t8, 16
    ctx->r19 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800E178C: andi        $t6, $s4, 0xFF
    ctx->r14 = ctx->r20 & 0XFF;
    // 0x800E1790: sw          $s4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r20;
    // 0x800E1794: or          $s4, $t6, $zero
    ctx->r20 = ctx->r14 | 0;
    // 0x800E1798: bgtz        $s3, L_800E17AC
    if (SIGNED(ctx->r19) > 0) {
        // 0x800E179C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800E17AC;
    }
    // 0x800E179C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E17A0: lui         $s1, 0x800F
    ctx->r17 = S32(0X800F << 16);
    // 0x800E17A4: addiu       $s1, $s1, -0x1C70
    ctx->r17 = ADD32(ctx->r17, -0X1C70);
    // 0x800E17A8: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_800E17AC:
    // 0x800E17AC: addiu       $v0, $zero, 0x66
    ctx->r2 = ADD32(0, 0X66);
    // 0x800E17B0: beq         $v0, $s4, L_800E17E4
    if (ctx->r2 == ctx->r20) {
        // 0x800E17B4: or          $v1, $s4, $zero
        ctx->r3 = ctx->r20 | 0;
            goto L_800E17E4;
    }
    // 0x800E17B4: or          $v1, $s4, $zero
    ctx->r3 = ctx->r20 | 0;
    // 0x800E17B8: addiu       $a0, $zero, 0x67
    ctx->r4 = ADD32(0, 0X67);
    // 0x800E17BC: beq         $a0, $v1, L_800E17C8
    if (ctx->r4 == ctx->r3) {
        // 0x800E17C0: addiu       $at, $zero, 0x47
        ctx->r1 = ADD32(0, 0X47);
            goto L_800E17C8;
    }
    // 0x800E17C0: addiu       $at, $zero, 0x47
    ctx->r1 = ADD32(0, 0X47);
    // 0x800E17C4: bne         $v1, $at, L_800E1A20
    if (ctx->r3 != ctx->r1) {
        // 0x800E17C8: slti        $at, $s2, -0x4
        ctx->r1 = SIGNED(ctx->r18) < -0X4 ? 1 : 0;
            goto L_800E1A20;
    }
L_800E17C8:
    // 0x800E17C8: slti        $at, $s2, -0x4
    ctx->r1 = SIGNED(ctx->r18) < -0X4 ? 1 : 0;
    // 0x800E17CC: bne         $at, $zero, L_800E1A20
    if (ctx->r1 != 0) {
        // 0x800E17D0: nop
    
            goto L_800E1A20;
    }
    // 0x800E17D0: nop

    // 0x800E17D4: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    // 0x800E17D8: slt         $at, $s2, $t7
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800E17DC: beq         $at, $zero, L_800E1A20
    if (ctx->r1 == 0) {
        // 0x800E17E0: nop
    
            goto L_800E1A20;
    }
    // 0x800E17E0: nop

L_800E17E4:
    // 0x800E17E4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800E17E8: sll         $t8, $s2, 16
    ctx->r24 = S32(ctx->r18 << 16);
    // 0x800E17EC: beq         $v0, $v1, L_800E1828
    if (ctx->r2 == ctx->r3) {
        // 0x800E17F0: sra         $s2, $t8, 16
        ctx->r18 = S32(SIGNED(ctx->r24) >> 16);
            goto L_800E1828;
    }
    // 0x800E17F0: sra         $s2, $t8, 16
    ctx->r18 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800E17F4: lw          $t6, 0x30($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X30);
    // 0x800E17F8: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x800E17FC: andi        $t7, $t6, 0x8
    ctx->r15 = ctx->r14 & 0X8;
    // 0x800E1800: bne         $t7, $zero, L_800E1818
    if (ctx->r15 != 0) {
        // 0x800E1804: slt         $at, $s3, $v0
        ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_800E1818;
    }
    // 0x800E1804: slt         $at, $s3, $v0
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800E1808: beql        $at, $zero, L_800E181C
    if (ctx->r1 == 0) {
        // 0x800E180C: subu        $t8, $v0, $s2
        ctx->r24 = SUB32(ctx->r2, ctx->r18);
            goto L_800E181C;
    }
    goto skip_0;
    // 0x800E180C: subu        $t8, $v0, $s2
    ctx->r24 = SUB32(ctx->r2, ctx->r18);
    skip_0:
    // 0x800E1810: sw          $s3, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r19;
    // 0x800E1814: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
L_800E1818:
    // 0x800E1818: subu        $t8, $v0, $s2
    ctx->r24 = SUB32(ctx->r2, ctx->r18);
L_800E181C:
    // 0x800E181C: bgez        $t8, L_800E1828
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800E1820: sw          $t8, 0x24($s0)
        MEM_W(0X24, ctx->r16) = ctx->r24;
            goto L_800E1828;
    }
    // 0x800E1820: sw          $t8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r24;
    // 0x800E1824: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
L_800E1828:
    // 0x800E1828: bgtz        $s2, L_800E18F8
    if (SIGNED(ctx->r18) > 0) {
        // 0x800E182C: slt         $at, $s3, $s2
        ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r18) ? 1 : 0;
            goto L_800E18F8;
    }
    // 0x800E182C: slt         $at, $s3, $s2
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x800E1830: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x800E1834: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x800E1838: addiu       $t6, $zero, 0x30
    ctx->r14 = ADD32(0, 0X30);
    // 0x800E183C: negu        $v1, $s2
    ctx->r3 = SUB32(0, ctx->r18);
    // 0x800E1840: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800E1844: sb          $t6, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r14;
    // 0x800E1848: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x800E184C: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x800E1850: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800E1854: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800E1858: bgtz        $v0, L_800E1870
    if (SIGNED(ctx->r2) > 0) {
        // 0x800E185C: sw          $t8, 0x14($s0)
        MEM_W(0X14, ctx->r16) = ctx->r24;
            goto L_800E1870;
    }
    // 0x800E185C: sw          $t8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r24;
    // 0x800E1860: lw          $t6, 0x30($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X30);
    // 0x800E1864: andi        $t9, $t6, 0x8
    ctx->r25 = ctx->r14 & 0X8;
    // 0x800E1868: beql        $t9, $zero, L_800E1898
    if (ctx->r25 == 0) {
        // 0x800E186C: slt         $at, $v0, $v1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_800E1898;
    }
    goto skip_1;
    // 0x800E186C: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    skip_1:
L_800E1870:
    // 0x800E1870: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x800E1874: lw          $t6, 0x14($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X14);
    // 0x800E1878: addiu       $t7, $zero, 0x2E
    ctx->r15 = ADD32(0, 0X2E);
    // 0x800E187C: addu        $t9, $t8, $t6
    ctx->r25 = ADD32(ctx->r24, ctx->r14);
    // 0x800E1880: sb          $t7, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r15;
    // 0x800E1884: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x800E1888: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x800E188C: addiu       $t6, $t8, 0x1
    ctx->r14 = ADD32(ctx->r24, 0X1);
    // 0x800E1890: sw          $t6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r14;
    // 0x800E1894: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
L_800E1898:
    // 0x800E1898: beql        $at, $zero, L_800E18B4
    if (ctx->r1 == 0) {
        // 0x800E189C: addu        $t8, $v0, $s2
        ctx->r24 = ADD32(ctx->r2, ctx->r18);
            goto L_800E18B4;
    }
    goto skip_2;
    // 0x800E189C: addu        $t8, $v0, $s2
    ctx->r24 = ADD32(ctx->r2, ctx->r18);
    skip_2:
    // 0x800E18A0: negu        $s2, $v0
    ctx->r18 = SUB32(0, ctx->r2);
    // 0x800E18A4: sll         $t7, $s2, 16
    ctx->r15 = S32(ctx->r18 << 16);
    // 0x800E18A8: sra         $s2, $t7, 16
    ctx->r18 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800E18AC: negu        $v1, $s2
    ctx->r3 = SUB32(0, ctx->r18);
    // 0x800E18B0: addu        $t8, $v0, $s2
    ctx->r24 = ADD32(ctx->r2, ctx->r18);
L_800E18B4:
    // 0x800E18B4: slt         $at, $t8, $s3
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800E18B8: sw          $v1, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r3;
    // 0x800E18BC: beq         $at, $zero, L_800E18D0
    if (ctx->r1 == 0) {
        // 0x800E18C0: sw          $t8, 0x24($s0)
        MEM_W(0X24, ctx->r16) = ctx->r24;
            goto L_800E18D0;
    }
    // 0x800E18C0: sw          $t8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r24;
    // 0x800E18C4: sll         $s3, $t8, 16
    ctx->r19 = S32(ctx->r24 << 16);
    // 0x800E18C8: sra         $t6, $s3, 16
    ctx->r14 = S32(SIGNED(ctx->r19) >> 16);
    // 0x800E18CC: or          $s3, $t6, $zero
    ctx->r19 = ctx->r14 | 0;
L_800E18D0:
    // 0x800E18D0: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x800E18D4: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
    // 0x800E18D8: sw          $s3, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r19;
    // 0x800E18DC: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x800E18E0: jal         0x800DD750
    // 0x800E18E4: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    memcpy_recomp(rdram, ctx);
        goto after_0;
    // 0x800E18E4: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    after_0:
    // 0x800E18E8: lw          $t8, 0x24($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X24);
    // 0x800E18EC: subu        $t6, $t8, $s3
    ctx->r14 = SUB32(ctx->r24, ctx->r19);
    // 0x800E18F0: b           L_800E1C7C
    // 0x800E18F4: sw          $t6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r14;
        goto L_800E1C7C;
    // 0x800E18F4: sw          $t6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r14;
L_800E18F8:
    // 0x800E18F8: beq         $at, $zero, L_800E1970
    if (ctx->r1 == 0) {
        // 0x800E18FC: or          $a1, $s1, $zero
        ctx->r5 = ctx->r17 | 0;
            goto L_800E1970;
    }
    // 0x800E18FC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800E1900: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x800E1904: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
    // 0x800E1908: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800E190C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x800E1910: jal         0x800DD750
    // 0x800E1914: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    memcpy_recomp(rdram, ctx);
        goto after_1;
    // 0x800E1914: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    after_1:
    // 0x800E1918: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x800E191C: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x800E1920: subu        $t7, $s2, $s3
    ctx->r15 = SUB32(ctx->r18, ctx->r19);
    // 0x800E1924: addu        $t6, $t8, $s3
    ctx->r14 = ADD32(ctx->r24, ctx->r19);
    // 0x800E1928: sw          $t6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r14;
    // 0x800E192C: bgtz        $v0, L_800E1944
    if (SIGNED(ctx->r2) > 0) {
        // 0x800E1930: sw          $t7, 0x18($s0)
        MEM_W(0X18, ctx->r16) = ctx->r15;
            goto L_800E1944;
    }
    // 0x800E1930: sw          $t7, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r15;
    // 0x800E1934: lw          $t9, 0x30($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X30);
    // 0x800E1938: andi        $t8, $t9, 0x8
    ctx->r24 = ctx->r25 & 0X8;
    // 0x800E193C: beq         $t8, $zero, L_800E1968
    if (ctx->r24 == 0) {
        // 0x800E1940: nop
    
            goto L_800E1968;
    }
    // 0x800E1940: nop

L_800E1944:
    // 0x800E1944: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x800E1948: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
    // 0x800E194C: addiu       $t6, $zero, 0x2E
    ctx->r14 = ADD32(0, 0X2E);
    // 0x800E1950: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x800E1954: sb          $t6, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r14;
    // 0x800E1958: lw          $t7, 0x1C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1C);
    // 0x800E195C: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x800E1960: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x800E1964: sw          $t9, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r25;
L_800E1968:
    // 0x800E1968: b           L_800E1C7C
    // 0x800E196C: sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
        goto L_800E1C7C;
    // 0x800E196C: sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
L_800E1970:
    // 0x800E1970: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    // 0x800E1974: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x800E1978: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800E197C: jal         0x800DD750
    // 0x800E1980: addu        $a0, $t6, $t8
    ctx->r4 = ADD32(ctx->r14, ctx->r24);
    memcpy_recomp(rdram, ctx);
        goto after_2;
    // 0x800E1980: addu        $a0, $t6, $t8
    ctx->r4 = ADD32(ctx->r14, ctx->r24);
    after_2:
    // 0x800E1984: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x800E1988: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x800E198C: subu        $s3, $s3, $s2
    ctx->r19 = SUB32(ctx->r19, ctx->r18);
    // 0x800E1990: sll         $t6, $s3, 16
    ctx->r14 = S32(ctx->r19 << 16);
    // 0x800E1994: addu        $t9, $t7, $s2
    ctx->r25 = ADD32(ctx->r15, ctx->r18);
    // 0x800E1998: sw          $t9, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r25;
    // 0x800E199C: bgtz        $v0, L_800E19B4
    if (SIGNED(ctx->r2) > 0) {
        // 0x800E19A0: sra         $s3, $t6, 16
        ctx->r19 = S32(SIGNED(ctx->r14) >> 16);
            goto L_800E19B4;
    }
    // 0x800E19A0: sra         $s3, $t6, 16
    ctx->r19 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800E19A4: lw          $t7, 0x30($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X30);
    // 0x800E19A8: andi        $t9, $t7, 0x8
    ctx->r25 = ctx->r15 & 0X8;
    // 0x800E19AC: beql        $t9, $zero, L_800E19DC
    if (ctx->r25 == 0) {
        // 0x800E19B0: slt         $at, $v0, $s3
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
            goto L_800E19DC;
    }
    goto skip_3;
    // 0x800E19B0: slt         $at, $v0, $s3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
    skip_3:
L_800E19B4:
    // 0x800E19B4: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x800E19B8: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x800E19BC: addiu       $t6, $zero, 0x2E
    ctx->r14 = ADD32(0, 0X2E);
    // 0x800E19C0: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x800E19C4: sb          $t6, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r14;
    // 0x800E19C8: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x800E19CC: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x800E19D0: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x800E19D4: sw          $t7, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r15;
    // 0x800E19D8: slt         $at, $v0, $s3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
L_800E19DC:
    // 0x800E19DC: beq         $at, $zero, L_800E19F0
    if (ctx->r1 == 0) {
        // 0x800E19E0: addu        $a1, $s2, $s1
        ctx->r5 = ADD32(ctx->r18, ctx->r17);
            goto L_800E19F0;
    }
    // 0x800E19E0: addu        $a1, $s2, $s1
    ctx->r5 = ADD32(ctx->r18, ctx->r17);
    // 0x800E19E4: sll         $s3, $v0, 16
    ctx->r19 = S32(ctx->r2 << 16);
    // 0x800E19E8: sra         $t6, $s3, 16
    ctx->r14 = S32(SIGNED(ctx->r19) >> 16);
    // 0x800E19EC: or          $s3, $t6, $zero
    ctx->r19 = ctx->r14 | 0;
L_800E19F0:
    // 0x800E19F0: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x800E19F4: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x800E19F8: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x800E19FC: jal         0x800DD750
    // 0x800E1A00: addu        $a0, $t9, $t8
    ctx->r4 = ADD32(ctx->r25, ctx->r24);
    memcpy_recomp(rdram, ctx);
        goto after_3;
    // 0x800E1A00: addu        $a0, $t9, $t8
    ctx->r4 = ADD32(ctx->r25, ctx->r24);
    after_3:
    // 0x800E1A04: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x800E1A08: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x800E1A0C: addu        $t6, $t7, $s3
    ctx->r14 = ADD32(ctx->r15, ctx->r19);
    // 0x800E1A10: subu        $t8, $t9, $s3
    ctx->r24 = SUB32(ctx->r25, ctx->r19);
    // 0x800E1A14: sw          $t6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r14;
    // 0x800E1A18: b           L_800E1C7C
    // 0x800E1A1C: sw          $t8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r24;
        goto L_800E1C7C;
    // 0x800E1A1C: sw          $t8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r24;
L_800E1A20:
    // 0x800E1A20: beq         $a0, $v1, L_800E1A30
    if (ctx->r4 == ctx->r3) {
        // 0x800E1A24: addiu       $at, $zero, 0x47
        ctx->r1 = ADD32(0, 0X47);
            goto L_800E1A30;
    }
    // 0x800E1A24: addiu       $at, $zero, 0x47
    ctx->r1 = ADD32(0, 0X47);
    // 0x800E1A28: bnel        $v1, $at, L_800E1A70
    if (ctx->r3 != ctx->r1) {
        // 0x800E1A2C: lw          $t8, 0x8($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X8);
            goto L_800E1A70;
    }
    goto skip_4;
    // 0x800E1A2C: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    skip_4:
L_800E1A30:
    // 0x800E1A30: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x800E1A34: addiu       $s4, $zero, 0x45
    ctx->r20 = ADD32(0, 0X45);
    // 0x800E1A38: slt         $at, $s3, $v0
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800E1A3C: beql        $at, $zero, L_800E1A50
    if (ctx->r1 == 0) {
        // 0x800E1A40: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_800E1A50;
    }
    goto skip_5;
    // 0x800E1A40: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    skip_5:
    // 0x800E1A44: sw          $s3, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r19;
    // 0x800E1A48: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x800E1A4C: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
L_800E1A50:
    // 0x800E1A50: bgez        $t7, L_800E1A5C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800E1A54: sw          $t7, 0x24($s0)
        MEM_W(0X24, ctx->r16) = ctx->r15;
            goto L_800E1A5C;
    }
    // 0x800E1A54: sw          $t7, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r15;
    // 0x800E1A58: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
L_800E1A5C:
    // 0x800E1A5C: bne         $a0, $v1, L_800E1A6C
    if (ctx->r4 != ctx->r3) {
        // 0x800E1A60: nop
    
            goto L_800E1A6C;
    }
    // 0x800E1A60: nop

    // 0x800E1A64: b           L_800E1A6C
    // 0x800E1A68: addiu       $s4, $zero, 0x65
    ctx->r20 = ADD32(0, 0X65);
        goto L_800E1A6C;
    // 0x800E1A68: addiu       $s4, $zero, 0x65
    ctx->r20 = ADD32(0, 0X65);
L_800E1A6C:
    // 0x800E1A6C: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
L_800E1A70:
    // 0x800E1A70: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x800E1A74: lbu         $t9, 0x0($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X0);
    // 0x800E1A78: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800E1A7C: addu        $t6, $t8, $t7
    ctx->r14 = ADD32(ctx->r24, ctx->r15);
    // 0x800E1A80: sb          $t9, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r25;
    // 0x800E1A84: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x800E1A88: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x800E1A8C: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x800E1A90: bgtz        $v0, L_800E1AA8
    if (SIGNED(ctx->r2) > 0) {
        // 0x800E1A94: sw          $t7, 0x14($s0)
        MEM_W(0X14, ctx->r16) = ctx->r15;
            goto L_800E1AA8;
    }
    // 0x800E1A94: sw          $t7, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r15;
    // 0x800E1A98: lw          $t9, 0x30($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X30);
    // 0x800E1A9C: andi        $t6, $t9, 0x8
    ctx->r14 = ctx->r25 & 0X8;
    // 0x800E1AA0: beq         $t6, $zero, L_800E1ACC
    if (ctx->r14 == 0) {
        // 0x800E1AA4: nop
    
            goto L_800E1ACC;
    }
    // 0x800E1AA4: nop

L_800E1AA8:
    // 0x800E1AA8: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x800E1AAC: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
    // 0x800E1AB0: addiu       $t8, $zero, 0x2E
    ctx->r24 = ADD32(0, 0X2E);
    // 0x800E1AB4: addu        $t6, $t7, $t9
    ctx->r14 = ADD32(ctx->r15, ctx->r25);
    // 0x800E1AB8: sb          $t8, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r24;
    // 0x800E1ABC: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x800E1AC0: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x800E1AC4: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x800E1AC8: sw          $t9, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r25;
L_800E1ACC:
    // 0x800E1ACC: blezl       $v0, L_800E1B28
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800E1AD0: lw          $t6, 0x8($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X8);
            goto L_800E1B28;
    }
    goto skip_6;
    // 0x800E1AD0: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    skip_6:
    // 0x800E1AD4: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    // 0x800E1AD8: sll         $t8, $s3, 16
    ctx->r24 = S32(ctx->r19 << 16);
    // 0x800E1ADC: sra         $s3, $t8, 16
    ctx->r19 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800E1AE0: slt         $at, $v0, $s3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800E1AE4: beq         $at, $zero, L_800E1AF8
    if (ctx->r1 == 0) {
        // 0x800E1AE8: or          $a1, $s1, $zero
        ctx->r5 = ctx->r17 | 0;
            goto L_800E1AF8;
    }
    // 0x800E1AE8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800E1AEC: sll         $s3, $v0, 16
    ctx->r19 = S32(ctx->r2 << 16);
    // 0x800E1AF0: sra         $t7, $s3, 16
    ctx->r15 = S32(SIGNED(ctx->r19) >> 16);
    // 0x800E1AF4: or          $s3, $t7, $zero
    ctx->r19 = ctx->r15 | 0;
L_800E1AF8:
    // 0x800E1AF8: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x800E1AFC: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x800E1B00: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x800E1B04: jal         0x800DD750
    // 0x800E1B08: addu        $a0, $t9, $t8
    ctx->r4 = ADD32(ctx->r25, ctx->r24);
    memcpy_recomp(rdram, ctx);
        goto after_4;
    // 0x800E1B08: addu        $a0, $t9, $t8
    ctx->r4 = ADD32(ctx->r25, ctx->r24);
    after_4:
    // 0x800E1B0C: lw          $t6, 0x14($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X14);
    // 0x800E1B10: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x800E1B14: addu        $t7, $t6, $s3
    ctx->r15 = ADD32(ctx->r14, ctx->r19);
    // 0x800E1B18: subu        $t8, $t9, $s3
    ctx->r24 = SUB32(ctx->r25, ctx->r19);
    // 0x800E1B1C: sw          $t7, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r15;
    // 0x800E1B20: sw          $t8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r24;
    // 0x800E1B24: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
L_800E1B28:
    // 0x800E1B28: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x800E1B2C: addu        $s1, $t6, $t7
    ctx->r17 = ADD32(ctx->r14, ctx->r15);
    // 0x800E1B30: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800E1B34: bltz        $s2, L_800E1B4C
    if (SIGNED(ctx->r18) < 0) {
        // 0x800E1B38: sb          $s4, -0x1($s1)
        MEM_B(-0X1, ctx->r17) = ctx->r20;
            goto L_800E1B4C;
    }
    // 0x800E1B38: sb          $s4, -0x1($s1)
    MEM_B(-0X1, ctx->r17) = ctx->r20;
    // 0x800E1B3C: addiu       $t9, $zero, 0x2B
    ctx->r25 = ADD32(0, 0X2B);
    // 0x800E1B40: sb          $t9, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r25;
    // 0x800E1B44: b           L_800E1B68
    // 0x800E1B48: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_800E1B68;
    // 0x800E1B48: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800E1B4C:
    // 0x800E1B4C: negu        $s2, $s2
    ctx->r18 = SUB32(0, ctx->r18);
    // 0x800E1B50: sll         $t6, $s2, 16
    ctx->r14 = S32(ctx->r18 << 16);
    // 0x800E1B54: addiu       $t8, $zero, 0x2D
    ctx->r24 = ADD32(0, 0X2D);
    // 0x800E1B58: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800E1B5C: sb          $t8, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r24;
    // 0x800E1B60: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800E1B64: or          $s2, $t7, $zero
    ctx->r18 = ctx->r15 | 0;
L_800E1B68:
    // 0x800E1B68: slti        $at, $s2, 0x64
    ctx->r1 = SIGNED(ctx->r18) < 0X64 ? 1 : 0;
    // 0x800E1B6C: bnel        $at, $zero, L_800E1C18
    if (ctx->r1 != 0) {
        // 0x800E1B70: addiu       $v0, $zero, 0xA
        ctx->r2 = ADD32(0, 0XA);
            goto L_800E1C18;
    }
    goto skip_7;
    // 0x800E1B70: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    skip_7:
    // 0x800E1B74: slti        $at, $s2, 0x3E8
    ctx->r1 = SIGNED(ctx->r18) < 0X3E8 ? 1 : 0;
    // 0x800E1B78: bne         $at, $zero, L_800E1BC8
    if (ctx->r1 != 0) {
        // 0x800E1B7C: addiu       $v0, $zero, 0x3E8
        ctx->r2 = ADD32(0, 0X3E8);
            goto L_800E1BC8;
    }
    // 0x800E1B7C: addiu       $v0, $zero, 0x3E8
    ctx->r2 = ADD32(0, 0X3E8);
    // 0x800E1B80: div         $zero, $s2, $v0
    lo = S32(S64(S32(ctx->r18)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r18)) % S64(S32(ctx->r2)));
    // 0x800E1B84: bne         $v0, $zero, L_800E1B90
    if (ctx->r2 != 0) {
        // 0x800E1B88: nop
    
            goto L_800E1B90;
    }
    // 0x800E1B88: nop

    // 0x800E1B8C: break       7
    do_break(2148408204);
L_800E1B90:
    // 0x800E1B90: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800E1B94: bne         $v0, $at, L_800E1BA8
    if (ctx->r2 != ctx->r1) {
        // 0x800E1B98: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800E1BA8;
    }
    // 0x800E1B98: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800E1B9C: bne         $s2, $at, L_800E1BA8
    if (ctx->r18 != ctx->r1) {
        // 0x800E1BA0: nop
    
            goto L_800E1BA8;
    }
    // 0x800E1BA0: nop

    // 0x800E1BA4: break       6
    do_break(2148408228);
L_800E1BA8:
    // 0x800E1BA8: mfhi        $s2
    ctx->r18 = hi;
    // 0x800E1BAC: sll         $t6, $s2, 16
    ctx->r14 = S32(ctx->r18 << 16);
    // 0x800E1BB0: mflo        $t9
    ctx->r25 = lo;
    // 0x800E1BB4: addiu       $t8, $t9, 0x30
    ctx->r24 = ADD32(ctx->r25, 0X30);
    // 0x800E1BB8: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800E1BBC: or          $s2, $t7, $zero
    ctx->r18 = ctx->r15 | 0;
    // 0x800E1BC0: sb          $t8, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r24;
    // 0x800E1BC4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800E1BC8:
    // 0x800E1BC8: addiu       $v0, $zero, 0x64
    ctx->r2 = ADD32(0, 0X64);
    // 0x800E1BCC: div         $zero, $s2, $v0
    lo = S32(S64(S32(ctx->r18)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r18)) % S64(S32(ctx->r2)));
    // 0x800E1BD0: bne         $v0, $zero, L_800E1BDC
    if (ctx->r2 != 0) {
        // 0x800E1BD4: nop
    
            goto L_800E1BDC;
    }
    // 0x800E1BD4: nop

    // 0x800E1BD8: break       7
    do_break(2148408280);
L_800E1BDC:
    // 0x800E1BDC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800E1BE0: bne         $v0, $at, L_800E1BF4
    if (ctx->r2 != ctx->r1) {
        // 0x800E1BE4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800E1BF4;
    }
    // 0x800E1BE4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800E1BE8: bne         $s2, $at, L_800E1BF4
    if (ctx->r18 != ctx->r1) {
        // 0x800E1BEC: nop
    
            goto L_800E1BF4;
    }
    // 0x800E1BEC: nop

    // 0x800E1BF0: break       6
    do_break(2148408304);
L_800E1BF4:
    // 0x800E1BF4: mfhi        $s2
    ctx->r18 = hi;
    // 0x800E1BF8: sll         $t6, $s2, 16
    ctx->r14 = S32(ctx->r18 << 16);
    // 0x800E1BFC: mflo        $t9
    ctx->r25 = lo;
    // 0x800E1C00: addiu       $t8, $t9, 0x30
    ctx->r24 = ADD32(ctx->r25, 0X30);
    // 0x800E1C04: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800E1C08: or          $s2, $t7, $zero
    ctx->r18 = ctx->r15 | 0;
    // 0x800E1C0C: sb          $t8, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r24;
    // 0x800E1C10: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800E1C14: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_800E1C18:
    // 0x800E1C18: div         $zero, $s2, $v0
    lo = S32(S64(S32(ctx->r18)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r18)) % S64(S32(ctx->r2)));
    // 0x800E1C1C: bne         $v0, $zero, L_800E1C28
    if (ctx->r2 != 0) {
        // 0x800E1C20: nop
    
            goto L_800E1C28;
    }
    // 0x800E1C20: nop

    // 0x800E1C24: break       7
    do_break(2148408356);
L_800E1C28:
    // 0x800E1C28: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800E1C2C: bne         $v0, $at, L_800E1C40
    if (ctx->r2 != ctx->r1) {
        // 0x800E1C30: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800E1C40;
    }
    // 0x800E1C30: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800E1C34: bne         $s2, $at, L_800E1C40
    if (ctx->r18 != ctx->r1) {
        // 0x800E1C38: nop
    
            goto L_800E1C40;
    }
    // 0x800E1C38: nop

    // 0x800E1C3C: break       6
    do_break(2148408380);
L_800E1C40:
    // 0x800E1C40: mfhi        $s2
    ctx->r18 = hi;
    // 0x800E1C44: sll         $t6, $s2, 16
    ctx->r14 = S32(ctx->r18 << 16);
    // 0x800E1C48: mflo        $t9
    ctx->r25 = lo;
    // 0x800E1C4C: addiu       $t8, $t9, 0x30
    ctx->r24 = ADD32(ctx->r25, 0X30);
    // 0x800E1C50: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800E1C54: addiu       $t9, $t7, 0x30
    ctx->r25 = ADD32(ctx->r15, 0X30);
    // 0x800E1C58: sb          $t8, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r24;
    // 0x800E1C5C: sb          $t9, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r25;
    // 0x800E1C60: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x800E1C64: or          $s2, $t7, $zero
    ctx->r18 = ctx->r15 | 0;
    // 0x800E1C68: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x800E1C6C: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x800E1C70: subu        $t6, $s1, $t8
    ctx->r14 = SUB32(ctx->r17, ctx->r24);
    // 0x800E1C74: subu        $t9, $t6, $t7
    ctx->r25 = SUB32(ctx->r14, ctx->r15);
    // 0x800E1C78: sw          $t9, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r25;
L_800E1C7C:
    // 0x800E1C7C: lw          $t8, 0x30($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X30);
    // 0x800E1C80: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x800E1C84: andi        $t6, $t8, 0x14
    ctx->r14 = ctx->r24 & 0X14;
    // 0x800E1C88: bnel        $t6, $at, L_800E1CCC
    if (ctx->r14 != ctx->r1) {
        // 0x800E1C8C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800E1CCC;
    }
    goto skip_8;
    // 0x800E1C8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_8:
    // 0x800E1C90: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x800E1C94: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
    // 0x800E1C98: lw          $t6, 0x18($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X18);
    // 0x800E1C9C: lw          $v1, 0x28($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X28);
    // 0x800E1CA0: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x800E1CA4: lw          $t9, 0x1C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1C);
    // 0x800E1CA8: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x800E1CAC: lw          $t6, 0x20($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X20);
    // 0x800E1CB0: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x800E1CB4: addu        $v0, $t8, $t6
    ctx->r2 = ADD32(ctx->r24, ctx->r14);
    // 0x800E1CB8: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800E1CBC: beq         $at, $zero, L_800E1CC8
    if (ctx->r1 == 0) {
        // 0x800E1CC0: subu        $t7, $v1, $v0
        ctx->r15 = SUB32(ctx->r3, ctx->r2);
            goto L_800E1CC8;
    }
    // 0x800E1CC0: subu        $t7, $v1, $v0
    ctx->r15 = SUB32(ctx->r3, ctx->r2);
    // 0x800E1CC4: sw          $t7, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r15;
L_800E1CC8:
    // 0x800E1CC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800E1CCC:
    // 0x800E1CCC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E1CD0: jr          $ra
    // 0x800E1CD4: nop

    return;
    // 0x800E1CD4: nop

;}
RECOMP_FUNC void func_800E1CD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E1CD8: jr          $ra
    // 0x800E1CDC: nop

    return;
    // 0x800E1CDC: nop

;}
RECOMP_FUNC void _Ldtob_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E1CE0: addiu       $sp, $sp, -0xD0
    ctx->r29 = ADD32(ctx->r29, -0XD0);
    // 0x800E1CE4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800E1CE8: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x800E1CEC: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x800E1CF0: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x800E1CF4: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x800E1CF8: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x800E1CFC: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x800E1D00: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800E1D04: sw          $a0, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r4;
    // 0x800E1D08: sw          $a1, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r5;
    // 0x800E1D0C: lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X24);
    // 0x800E1D10: addiu       $s5, $sp, 0xB0
    ctx->r21 = ADD32(ctx->r29, 0XB0);
    // 0x800E1D14: ldc1        $f20, 0x0($a0)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r4, 0X0);
    // 0x800E1D18: bgez        $v0, L_800E1D28
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800E1D1C: addiu       $t7, $zero, 0x6
        ctx->r15 = ADD32(0, 0X6);
            goto L_800E1D28;
    }
    // 0x800E1D1C: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x800E1D20: b           L_800E1D54
    // 0x800E1D24: sw          $t7, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r15;
        goto L_800E1D54;
    // 0x800E1D24: sw          $t7, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r15;
L_800E1D28:
    // 0x800E1D28: bne         $v0, $zero, L_800E1D54
    if (ctx->r2 != 0) {
        // 0x800E1D2C: lbu         $t8, 0xD7($sp)
        ctx->r24 = MEM_BU(ctx->r29, 0XD7);
            goto L_800E1D54;
    }
    // 0x800E1D2C: lbu         $t8, 0xD7($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0XD7);
    // 0x800E1D30: addiu       $at, $zero, 0x67
    ctx->r1 = ADD32(0, 0X67);
    // 0x800E1D34: beq         $t8, $at, L_800E1D48
    if (ctx->r24 == ctx->r1) {
        // 0x800E1D38: sw          $t8, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r24;
            goto L_800E1D48;
    }
    // 0x800E1D38: sw          $t8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r24;
    // 0x800E1D3C: addiu       $at, $zero, 0x47
    ctx->r1 = ADD32(0, 0X47);
    // 0x800E1D40: bnel        $t8, $at, L_800E1D58
    if (ctx->r24 != ctx->r1) {
        // 0x800E1D44: lw          $t6, 0xD0($sp)
        ctx->r14 = MEM_W(ctx->r29, 0XD0);
            goto L_800E1D58;
    }
    goto skip_0;
    // 0x800E1D44: lw          $t6, 0xD0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XD0);
    skip_0:
L_800E1D48:
    // 0x800E1D48: lw          $t7, 0xD0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XD0);
    // 0x800E1D4C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800E1D50: sw          $t9, 0x24($t7)
    MEM_W(0X24, ctx->r15) = ctx->r25;
L_800E1D54:
    // 0x800E1D54: lw          $t6, 0xD0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XD0);
L_800E1D58:
    // 0x800E1D58: addiu       $at, $zero, 0x7FF
    ctx->r1 = ADD32(0, 0X7FF);
    // 0x800E1D5C: lhu         $a0, 0x0($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X0);
    // 0x800E1D60: andi        $v1, $a0, 0x7FF0
    ctx->r3 = ctx->r4 & 0X7FF0;
    // 0x800E1D64: sra         $t8, $v1, 4
    ctx->r24 = S32(SIGNED(ctx->r3) >> 4);
    // 0x800E1D68: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800E1D6C: sra         $v1, $t9, 16
    ctx->r3 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800E1D70: bne         $v1, $at, L_800E1DD4
    if (ctx->r3 != ctx->r1) {
        // 0x800E1D74: nop
    
            goto L_800E1DD4;
    }
    // 0x800E1D74: nop

    // 0x800E1D78: sh          $zero, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = 0;
    // 0x800E1D7C: lhu         $t8, 0x0($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X0);
    // 0x800E1D80: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x800E1D84: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    // 0x800E1D88: andi        $t9, $t8, 0xF
    ctx->r25 = ctx->r24 & 0XF;
    // 0x800E1D8C: bnel        $t9, $zero, L_800E1DB8
    if (ctx->r25 != 0) {
        // 0x800E1D90: sra         $t7, $v0, 16
        ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
            goto L_800E1DB8;
    }
    goto skip_1;
    // 0x800E1D90: sra         $t7, $v0, 16
    ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
    skip_1:
    // 0x800E1D94: lhu         $t7, 0x2($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X2);
    // 0x800E1D98: bnel        $t7, $zero, L_800E1DB8
    if (ctx->r15 != 0) {
        // 0x800E1D9C: sra         $t7, $v0, 16
        ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
            goto L_800E1DB8;
    }
    goto skip_2;
    // 0x800E1D9C: sra         $t7, $v0, 16
    ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
    skip_2:
    // 0x800E1DA0: lhu         $t8, 0x4($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X4);
    // 0x800E1DA4: bnel        $t8, $zero, L_800E1DB8
    if (ctx->r24 != 0) {
        // 0x800E1DA8: sra         $t7, $v0, 16
        ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
            goto L_800E1DB8;
    }
    goto skip_3;
    // 0x800E1DA8: sra         $t7, $v0, 16
    ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
    skip_3:
    // 0x800E1DAC: lhu         $t9, 0x6($t6)
    ctx->r25 = MEM_HU(ctx->r14, 0X6);
    // 0x800E1DB0: beq         $t9, $zero, L_800E1DC0
    if (ctx->r25 == 0) {
        // 0x800E1DB4: sra         $t7, $v0, 16
        ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
            goto L_800E1DC0;
    }
    // 0x800E1DB4: sra         $t7, $v0, 16
    ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
L_800E1DB8:
    // 0x800E1DB8: b           L_800E1E0C
    // 0x800E1DBC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
        goto L_800E1E0C;
    // 0x800E1DBC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_800E1DC0:
    // 0x800E1DC0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800E1DC4: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    // 0x800E1DC8: sra         $t7, $v0, 16
    ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800E1DCC: b           L_800E1E0C
    // 0x800E1DD0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
        goto L_800E1E0C;
    // 0x800E1DD0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_800E1DD4:
    // 0x800E1DD4: blez        $v1, L_800E1DF8
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800E1DD8: andi        $t8, $a0, 0x800F
        ctx->r24 = ctx->r4 & 0X800F;
            goto L_800E1DF8;
    }
    // 0x800E1DD8: andi        $t8, $a0, 0x800F
    ctx->r24 = ctx->r4 & 0X800F;
    // 0x800E1DDC: lw          $t9, 0xD0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD0);
    // 0x800E1DE0: ori         $t6, $t8, 0x3FF0
    ctx->r14 = ctx->r24 | 0X3FF0;
    // 0x800E1DE4: addiu       $t7, $v1, -0x3FE
    ctx->r15 = ADD32(ctx->r3, -0X3FE);
    // 0x800E1DE8: sh          $t6, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r14;
    // 0x800E1DEC: sh          $t7, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r15;
    // 0x800E1DF0: b           L_800E1E0C
    // 0x800E1DF4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800E1E0C;
    // 0x800E1DF4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800E1DF8:
    // 0x800E1DF8: bgez        $v1, L_800E1E08
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800E1DFC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800E1E08;
    }
    // 0x800E1DFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800E1E00: b           L_800E1E0C
    // 0x800E1E04: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_800E1E0C;
    // 0x800E1E04: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_800E1E08:
    // 0x800E1E08: sh          $zero, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = 0;
L_800E1E0C:
    // 0x800E1E0C: blez        $v0, L_800E1E58
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800E1E10: sll         $t8, $v0, 16
        ctx->r24 = S32(ctx->r2 << 16);
            goto L_800E1E58;
    }
    // 0x800E1E10: sll         $t8, $v0, 16
    ctx->r24 = S32(ctx->r2 << 16);
    // 0x800E1E14: sll         $t8, $v0, 16
    ctx->r24 = S32(ctx->r2 << 16);
    // 0x800E1E18: sra         $t6, $t8, 16
    ctx->r14 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800E1E1C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800E1E20: bne         $t6, $at, L_800E1E34
    if (ctx->r14 != ctx->r1) {
        // 0x800E1E24: lw          $t9, 0xD0($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XD0);
            goto L_800E1E34;
    }
    // 0x800E1E24: lw          $t9, 0xD0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD0);
    // 0x800E1E28: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x800E1E2C: b           L_800E1E3C
    // 0x800E1E30: addiu       $a1, $a1, -0x1C78
    ctx->r5 = ADD32(ctx->r5, -0X1C78);
        goto L_800E1E3C;
    // 0x800E1E30: addiu       $a1, $a1, -0x1C78
    ctx->r5 = ADD32(ctx->r5, -0X1C78);
L_800E1E34:
    // 0x800E1E34: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x800E1E38: addiu       $a1, $a1, -0x1C74
    ctx->r5 = ADD32(ctx->r5, -0X1C74);
L_800E1E3C:
    // 0x800E1E3C: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x800E1E40: sw          $t7, 0x14($t9)
    MEM_W(0X14, ctx->r25) = ctx->r15;
    // 0x800E1E44: lw          $a0, 0x8($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X8);
    // 0x800E1E48: jal         0x800DD750
    // 0x800E1E4C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    memcpy_recomp(rdram, ctx);
        goto after_0;
    // 0x800E1E4C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_0:
    // 0x800E1E50: b           L_800E2208
    // 0x800E1E54: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_800E2208;
    // 0x800E1E54: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_800E1E58:
    // 0x800E1E58: sra         $t6, $t8, 16
    ctx->r14 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800E1E5C: bne         $t6, $zero, L_800E1E6C
    if (ctx->r14 != 0) {
        // 0x800E1E60: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_800E1E6C;
    }
    // 0x800E1E60: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800E1E64: b           L_800E21F0
    // 0x800E1E68: sh          $zero, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = 0;
        goto L_800E21F0;
    // 0x800E1E68: sh          $zero, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = 0;
L_800E1E6C:
    // 0x800E1E6C: mtc1        $zero, $f3
    ctx->f_odd[(3 - 1) * 2] = 0;
    // 0x800E1E70: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800E1E74: lbu         $t7, 0xD7($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0XD7);
    // 0x800E1E78: lh          $t9, 0x9A($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X9A);
    // 0x800E1E7C: c.lt.d      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.d < ctx->f2.d;
    // 0x800E1E80: addiu       $at, $zero, 0x7597
    ctx->r1 = ADD32(0, 0X7597);
    // 0x800E1E84: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800E1E88: addiu       $s5, $sp, 0xB1
    ctx->r21 = ADD32(ctx->r29, 0XB1);
    // 0x800E1E8C: bc1f        L_800E1E98
    if (!c1cs) {
        // 0x800E1E90: sw          $t7, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r15;
            goto L_800E1E98;
    }
    // 0x800E1E90: sw          $t7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r15;
    // 0x800E1E94: neg.d       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.d); 
    ctx->f20.d = -ctx->f20.d;
L_800E1E98:
    // 0x800E1E98: multu       $t9, $at
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r1)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800E1E9C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x800E1EA0: ori         $at, $at, 0x86A0
    ctx->r1 = ctx->r1 | 0X86A0;
    // 0x800E1EA4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x800E1EA8: mflo        $t8
    ctx->r24 = lo;
    // 0x800E1EAC: nop

    // 0x800E1EB0: nop

    // 0x800E1EB4: div         $zero, $t8, $at
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r1)));
    // 0x800E1EB8: mflo        $t6
    ctx->r14 = lo;
    // 0x800E1EBC: addiu       $t7, $t6, -0x4
    ctx->r15 = ADD32(ctx->r14, -0X4);
    // 0x800E1EC0: sll         $t9, $t7, 16
    ctx->r25 = S32(ctx->r15 << 16);
    // 0x800E1EC4: sra         $t8, $t9, 16
    ctx->r24 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800E1EC8: bgez        $t8, L_800E1F30
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800E1ECC: sh          $t7, 0x9A($sp)
        MEM_H(0X9A, ctx->r29) = ctx->r15;
            goto L_800E1F30;
    }
    // 0x800E1ECC: sh          $t7, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r15;
    // 0x800E1ED0: sll         $t9, $t7, 16
    ctx->r25 = S32(ctx->r15 << 16);
    // 0x800E1ED4: sra         $t8, $t9, 16
    ctx->r24 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800E1ED8: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x800E1EDC: subu        $a0, $t6, $t8
    ctx->r4 = SUB32(ctx->r14, ctx->r24);
    // 0x800E1EE0: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800E1EE4: and         $v0, $a0, $at
    ctx->r2 = ctx->r4 & ctx->r1;
    // 0x800E1EE8: negu        $t9, $v0
    ctx->r25 = SUB32(0, ctx->r2);
    // 0x800E1EEC: blez        $v0, L_800E1FA0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800E1EF0: sh          $t9, 0x9A($sp)
        MEM_H(0X9A, ctx->r29) = ctx->r25;
            goto L_800E1FA0;
    }
    // 0x800E1EF0: sh          $t9, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r25;
    // 0x800E1EF4: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800E1EF8: addiu       $a0, $a0, -0x1CC0
    ctx->r4 = ADD32(ctx->r4, -0X1CC0);
L_800E1EFC:
    // 0x800E1EFC: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x800E1F00: beq         $t6, $zero, L_800E1F1C
    if (ctx->r14 == 0) {
        // 0x800E1F04: sra         $t9, $v0, 1
        ctx->r25 = S32(SIGNED(ctx->r2) >> 1);
            goto L_800E1F1C;
    }
    // 0x800E1F04: sra         $t9, $v0, 1
    ctx->r25 = S32(SIGNED(ctx->r2) >> 1);
    // 0x800E1F08: sll         $t8, $v1, 3
    ctx->r24 = S32(ctx->r3 << 3);
    // 0x800E1F0C: addu        $t7, $a0, $t8
    ctx->r15 = ADD32(ctx->r4, ctx->r24);
    // 0x800E1F10: ldc1        $f4, 0x0($t7)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r15, 0X0);
    // 0x800E1F14: mul.d       $f20, $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f4.d); 
    ctx->f20.d = MUL_D(ctx->f20.d, ctx->f4.d);
    // 0x800E1F18: nop

L_800E1F1C:
    // 0x800E1F1C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x800E1F20: bgtz        $t9, L_800E1EFC
    if (SIGNED(ctx->r25) > 0) {
        // 0x800E1F24: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800E1EFC;
    }
    // 0x800E1F24: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800E1F28: b           L_800E1FA4
    // 0x800E1F2C: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
        goto L_800E1FA4;
    // 0x800E1F2C: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
L_800E1F30:
    // 0x800E1F30: lh          $t6, 0x9A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X9A);
    // 0x800E1F34: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800E1F38: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800E1F3C: blez        $t6, L_800E1FA0
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800E1F40: andi        $t8, $t6, 0xFFFC
        ctx->r24 = ctx->r14 & 0XFFFC;
            goto L_800E1FA0;
    }
    // 0x800E1F40: andi        $t8, $t6, 0xFFFC
    ctx->r24 = ctx->r14 & 0XFFFC;
    // 0x800E1F44: sll         $v0, $t8, 16
    ctx->r2 = S32(ctx->r24 << 16);
    // 0x800E1F48: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800E1F4C: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x800E1F50: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800E1F54: sra         $t6, $t9, 16
    ctx->r14 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800E1F58: sra         $t7, $v0, 16
    ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800E1F5C: sh          $t8, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r24;
    // 0x800E1F60: blez        $t6, L_800E1F9C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800E1F64: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_800E1F9C;
    }
    // 0x800E1F64: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800E1F68: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800E1F6C: addiu       $a0, $a0, -0x1CC0
    ctx->r4 = ADD32(ctx->r4, -0X1CC0);
L_800E1F70:
    // 0x800E1F70: andi        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 & 0X1;
    // 0x800E1F74: beq         $t7, $zero, L_800E1F90
    if (ctx->r15 == 0) {
        // 0x800E1F78: sra         $t6, $v0, 1
        ctx->r14 = S32(SIGNED(ctx->r2) >> 1);
            goto L_800E1F90;
    }
    // 0x800E1F78: sra         $t6, $v0, 1
    ctx->r14 = S32(SIGNED(ctx->r2) >> 1);
    // 0x800E1F7C: sll         $t8, $v1, 3
    ctx->r24 = S32(ctx->r3 << 3);
    // 0x800E1F80: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x800E1F84: ldc1        $f6, 0x0($t9)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r25, 0X0);
    // 0x800E1F88: mul.d       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f0.d = MUL_D(ctx->f0.d, ctx->f6.d);
    // 0x800E1F8C: nop

L_800E1F90:
    // 0x800E1F90: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800E1F94: bgtz        $t6, L_800E1F70
    if (SIGNED(ctx->r14) > 0) {
        // 0x800E1F98: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800E1F70;
    }
    // 0x800E1F98: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_800E1F9C:
    // 0x800E1F9C: div.d       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f0.d); 
    ctx->f20.d = DIV_D(ctx->f20.d, ctx->f0.d);
L_800E1FA0:
    // 0x800E1FA0: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
L_800E1FA4:
    // 0x800E1FA4: addiu       $at, $zero, 0x66
    ctx->r1 = ADD32(0, 0X66);
    // 0x800E1FA8: lw          $t8, 0xD0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XD0);
    // 0x800E1FAC: bne         $t7, $at, L_800E1FC0
    if (ctx->r15 != ctx->r1) {
        // 0x800E1FB0: addiu       $t6, $zero, 0x30
        ctx->r14 = ADD32(0, 0X30);
            goto L_800E1FC0;
    }
    // 0x800E1FB0: addiu       $t6, $zero, 0x30
    ctx->r14 = ADD32(0, 0X30);
    // 0x800E1FB4: lh          $a1, 0x9A($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X9A);
    // 0x800E1FB8: b           L_800E1FC0
    // 0x800E1FBC: addiu       $a1, $a1, 0xA
    ctx->r5 = ADD32(ctx->r5, 0XA);
        goto L_800E1FC0;
    // 0x800E1FBC: addiu       $a1, $a1, 0xA
    ctx->r5 = ADD32(ctx->r5, 0XA);
L_800E1FC0:
    // 0x800E1FC0: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x800E1FC4: addu        $s4, $a1, $t9
    ctx->r20 = ADD32(ctx->r5, ctx->r25);
    // 0x800E1FC8: slti        $at, $s4, 0x14
    ctx->r1 = SIGNED(ctx->r20) < 0X14 ? 1 : 0;
    // 0x800E1FCC: bne         $at, $zero, L_800E1FD8
    if (ctx->r1 != 0) {
        // 0x800E1FD0: nop
    
            goto L_800E1FD8;
    }
    // 0x800E1FD0: nop

    // 0x800E1FD4: addiu       $s4, $zero, 0x13
    ctx->r20 = ADD32(0, 0X13);
L_800E1FD8:
    // 0x800E1FD8: blez        $s4, L_800E20A8
    if (SIGNED(ctx->r20) <= 0) {
        // 0x800E1FDC: sb          $t6, 0xB0($sp)
        MEM_B(0XB0, ctx->r29) = ctx->r14;
            goto L_800E20A8;
    }
    // 0x800E1FDC: sb          $t6, 0xB0($sp)
    MEM_B(0XB0, ctx->r29) = ctx->r14;
    // 0x800E1FE0: c.lt.d      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.d < ctx->f20.d;
    // 0x800E1FE4: addiu       $s3, $zero, 0x30
    ctx->r19 = ADD32(0, 0X30);
    // 0x800E1FE8: addiu       $s2, $sp, 0x74
    ctx->r18 = ADD32(ctx->r29, 0X74);
    // 0x800E1FEC: bc1fl       L_800E20AC
    if (!c1cs) {
        // 0x800E1FF0: lh          $t8, 0x9A($sp)
        ctx->r24 = MEM_H(ctx->r29, 0X9A);
            goto L_800E20AC;
    }
    goto skip_4;
    // 0x800E1FF0: lh          $t8, 0x9A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X9A);
    skip_4:
    // 0x800E1FF4: trunc.w.d   $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    ctx->f8.u32l = TRUNC_W_D(ctx->f20.d);
L_800E1FF8:
    // 0x800E1FF8: addiu       $s4, $s4, -0x8
    ctx->r20 = ADD32(ctx->r20, -0X8);
    // 0x800E1FFC: addiu       $s5, $s5, 0x8
    ctx->r21 = ADD32(ctx->r21, 0X8);
    // 0x800E2000: mfc1        $s1, $f8
    ctx->r17 = (int32_t)ctx->f8.u32l;
    // 0x800E2004: blez        $s4, L_800E2028
    if (SIGNED(ctx->r20) <= 0) {
        // 0x800E2008: nop
    
            goto L_800E2028;
    }
    // 0x800E2008: nop

    // 0x800E200C: mtc1        $s1, $f10
    ctx->f10.u32l = ctx->r17;
    // 0x800E2010: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800E2014: ldc1        $f8, -0x1C68($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X1C68);
    // 0x800E2018: cvt.d.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.d = CVT_D_W(ctx->f10.u32l);
    // 0x800E201C: sub.d       $f6, $f20, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f20.d - ctx->f4.d;
    // 0x800E2020: mul.d       $f20, $f6, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f20.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x800E2024: nop

L_800E2028:
    // 0x800E2028: blez        $s1, L_800E2070
    if (SIGNED(ctx->r17) <= 0) {
        // 0x800E202C: addiu       $s0, $zero, 0x8
        ctx->r16 = ADD32(0, 0X8);
            goto L_800E2070;
    }
    // 0x800E202C: addiu       $s0, $zero, 0x8
    ctx->r16 = ADD32(0, 0X8);
    // 0x800E2030: addiu       $s0, $zero, 0x7
    ctx->r16 = ADD32(0, 0X7);
    // 0x800E2034: bltz        $s0, L_800E2070
    if (SIGNED(ctx->r16) < 0) {
        // 0x800E2038: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800E2070;
    }
    // 0x800E2038: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_800E203C:
    // 0x800E203C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800E2040: jal         0x800E3C10
    // 0x800E2044: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    ldiv_recomp(rdram, ctx);
        goto after_1;
    // 0x800E2044: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_1:
    // 0x800E2048: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
    // 0x800E204C: addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
    // 0x800E2050: addiu       $t9, $t8, 0x30
    ctx->r25 = ADD32(ctx->r24, 0X30);
    // 0x800E2054: sb          $t9, 0x0($s5)
    MEM_B(0X0, ctx->r21) = ctx->r25;
    // 0x800E2058: lw          $s1, 0x74($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X74);
    // 0x800E205C: blezl       $s1, L_800E2074
    if (SIGNED(ctx->r17) <= 0) {
        // 0x800E2060: mtc1        $zero, $f3
        ctx->f_odd[(3 - 1) * 2] = 0;
            goto L_800E2074;
    }
    goto skip_5;
    // 0x800E2060: mtc1        $zero, $f3
    ctx->f_odd[(3 - 1) * 2] = 0;
    skip_5:
    // 0x800E2064: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x800E2068: bgezl       $s0, L_800E203C
    if (SIGNED(ctx->r16) >= 0) {
        // 0x800E206C: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800E203C;
    }
    goto skip_6;
    // 0x800E206C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_6:
L_800E2070:
    // 0x800E2070: mtc1        $zero, $f3
    ctx->f_odd[(3 - 1) * 2] = 0;
L_800E2074:
    // 0x800E2074: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800E2078: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x800E207C: bltz        $s0, L_800E2090
    if (SIGNED(ctx->r16) < 0) {
        // 0x800E2080: addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
            goto L_800E2090;
    }
L_800E2080:
    // 0x800E2080: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x800E2084: addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
    // 0x800E2088: bgez        $s0, L_800E2080
    if (SIGNED(ctx->r16) >= 0) {
        // 0x800E208C: sb          $s3, 0x0($s5)
        MEM_B(0X0, ctx->r21) = ctx->r19;
            goto L_800E2080;
    }
    // 0x800E208C: sb          $s3, 0x0($s5)
    MEM_B(0X0, ctx->r21) = ctx->r19;
L_800E2090:
    // 0x800E2090: blez        $s4, L_800E20A8
    if (SIGNED(ctx->r20) <= 0) {
        // 0x800E2094: addiu       $s5, $s5, 0x8
        ctx->r21 = ADD32(ctx->r21, 0X8);
            goto L_800E20A8;
    }
    // 0x800E2094: addiu       $s5, $s5, 0x8
    ctx->r21 = ADD32(ctx->r21, 0X8);
    // 0x800E2098: c.lt.d      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.d < ctx->f20.d;
    // 0x800E209C: nop

    // 0x800E20A0: bc1tl       L_800E1FF8
    if (c1cs) {
        // 0x800E20A4: trunc.w.d   $f8, $f20
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    ctx->f8.u32l = TRUNC_W_D(ctx->f20.d);
            goto L_800E1FF8;
    }
    goto skip_7;
    // 0x800E20A4: trunc.w.d   $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    ctx->f8.u32l = TRUNC_W_D(ctx->f20.d);
    skip_7:
L_800E20A8:
    // 0x800E20A8: lh          $t8, 0x9A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X9A);
L_800E20AC:
    // 0x800E20AC: lbu         $t6, 0xB1($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0XB1);
    // 0x800E20B0: addiu       $t7, $sp, 0xB0
    ctx->r15 = ADD32(ctx->r29, 0XB0);
    // 0x800E20B4: addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
    // 0x800E20B8: subu        $s4, $s5, $t7
    ctx->r20 = SUB32(ctx->r21, ctx->r15);
    // 0x800E20BC: addiu       $t9, $t8, 0x7
    ctx->r25 = ADD32(ctx->r24, 0X7);
    // 0x800E20C0: addiu       $s4, $s4, -0x1
    ctx->r20 = ADD32(ctx->r20, -0X1);
    // 0x800E20C4: sh          $t9, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r25;
    // 0x800E20C8: bne         $v0, $t6, L_800E20F0
    if (ctx->r2 != ctx->r14) {
        // 0x800E20CC: addiu       $s5, $sp, 0xB1
        ctx->r21 = ADD32(ctx->r29, 0XB1);
            goto L_800E20F0;
    }
    // 0x800E20CC: addiu       $s5, $sp, 0xB1
    ctx->r21 = ADD32(ctx->r29, 0XB1);
    // 0x800E20D0: lh          $t7, 0x9A($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X9A);
L_800E20D4:
    // 0x800E20D4: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x800E20D8: addiu       $s4, $s4, -0x1
    ctx->r20 = ADD32(ctx->r20, -0X1);
    // 0x800E20DC: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x800E20E0: sh          $t8, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r24;
    // 0x800E20E4: lbu         $t9, 0x0($s5)
    ctx->r25 = MEM_BU(ctx->r21, 0X0);
    // 0x800E20E8: beql        $v0, $t9, L_800E20D4
    if (ctx->r2 == ctx->r25) {
        // 0x800E20EC: lh          $t7, 0x9A($sp)
        ctx->r15 = MEM_H(ctx->r29, 0X9A);
            goto L_800E20D4;
    }
    goto skip_8;
    // 0x800E20EC: lh          $t7, 0x9A($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X9A);
    skip_8:
L_800E20F0:
    // 0x800E20F0: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x800E20F4: addiu       $at, $zero, 0x66
    ctx->r1 = ADD32(0, 0X66);
    // 0x800E20F8: lw          $t8, 0xD0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XD0);
    // 0x800E20FC: bne         $t6, $at, L_800E2110
    if (ctx->r14 != ctx->r1) {
        // 0x800E2100: lw          $t7, 0x48($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X48);
            goto L_800E2110;
    }
    // 0x800E2100: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x800E2104: lh          $a1, 0x9A($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X9A);
    // 0x800E2108: b           L_800E2130
    // 0x800E210C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
        goto L_800E2130;
    // 0x800E210C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_800E2110:
    // 0x800E2110: addiu       $at, $zero, 0x65
    ctx->r1 = ADD32(0, 0X65);
    // 0x800E2114: beq         $t7, $at, L_800E2124
    if (ctx->r15 == ctx->r1) {
        // 0x800E2118: addiu       $at, $zero, 0x45
        ctx->r1 = ADD32(0, 0X45);
            goto L_800E2124;
    }
    // 0x800E2118: addiu       $at, $zero, 0x45
    ctx->r1 = ADD32(0, 0X45);
    // 0x800E211C: bne         $t7, $at, L_800E212C
    if (ctx->r15 != ctx->r1) {
        // 0x800E2120: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800E212C;
    }
    // 0x800E2120: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800E2124:
    // 0x800E2124: b           L_800E212C
    // 0x800E2128: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800E212C;
    // 0x800E2128: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800E212C:
    // 0x800E212C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_800E2130:
    // 0x800E2130: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x800E2134: addu        $s3, $a1, $t9
    ctx->r19 = ADD32(ctx->r5, ctx->r25);
    // 0x800E2138: sll         $t6, $s3, 16
    ctx->r14 = S32(ctx->r19 << 16);
    // 0x800E213C: sra         $s3, $t6, 16
    ctx->r19 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800E2140: slt         $at, $s4, $s3
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800E2144: beq         $at, $zero, L_800E2158
    if (ctx->r1 == 0) {
        // 0x800E2148: nop
    
            goto L_800E2158;
    }
    // 0x800E2148: nop

    // 0x800E214C: sll         $s3, $s4, 16
    ctx->r19 = S32(ctx->r20 << 16);
    // 0x800E2150: sra         $t8, $s3, 16
    ctx->r24 = S32(SIGNED(ctx->r19) >> 16);
    // 0x800E2154: or          $s3, $t8, $zero
    ctx->r19 = ctx->r24 | 0;
L_800E2158:
    // 0x800E2158: blez        $s3, L_800E21F0
    if (SIGNED(ctx->r19) <= 0) {
        // 0x800E215C: slt         $at, $s3, $s4
        ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r20) ? 1 : 0;
            goto L_800E21F0;
    }
    // 0x800E215C: slt         $at, $s3, $s4
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x800E2160: beq         $at, $zero, L_800E2180
    if (ctx->r1 == 0) {
        // 0x800E2164: addu        $v0, $s3, $s5
        ctx->r2 = ADD32(ctx->r19, ctx->r21);
            goto L_800E2180;
    }
    // 0x800E2164: addu        $v0, $s3, $s5
    ctx->r2 = ADD32(ctx->r19, ctx->r21);
    // 0x800E2168: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x800E216C: slti        $at, $t9, 0x35
    ctx->r1 = SIGNED(ctx->r25) < 0X35 ? 1 : 0;
    // 0x800E2170: bnel        $at, $zero, L_800E2184
    if (ctx->r1 != 0) {
        // 0x800E2174: addiu       $a1, $zero, 0x30
        ctx->r5 = ADD32(0, 0X30);
            goto L_800E2184;
    }
    goto skip_9;
    // 0x800E2174: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    skip_9:
    // 0x800E2178: b           L_800E2188
    // 0x800E217C: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
        goto L_800E2188;
    // 0x800E217C: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
L_800E2180:
    // 0x800E2180: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
L_800E2184:
    // 0x800E2184: addu        $v0, $s3, $s5
    ctx->r2 = ADD32(ctx->r19, ctx->r21);
L_800E2188:
    // 0x800E2188: lbu         $t6, -0x1($v0)
    ctx->r14 = MEM_BU(ctx->r2, -0X1);
    // 0x800E218C: addiu       $v1, $s3, -0x1
    ctx->r3 = ADD32(ctx->r19, -0X1);
    // 0x800E2190: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800E2194: bne         $a1, $t6, L_800E21BC
    if (ctx->r5 != ctx->r14) {
        // 0x800E2198: addiu       $at, $zero, 0x39
        ctx->r1 = ADD32(0, 0X39);
            goto L_800E21BC;
    }
    // 0x800E2198: addiu       $at, $zero, 0x39
    ctx->r1 = ADD32(0, 0X39);
    // 0x800E219C: addu        $v0, $v1, $s5
    ctx->r2 = ADD32(ctx->r3, ctx->r21);
L_800E21A0:
    // 0x800E21A0: lbu         $t9, -0x1($v0)
    ctx->r25 = MEM_BU(ctx->r2, -0X1);
    // 0x800E21A4: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    // 0x800E21A8: sll         $t7, $s3, 16
    ctx->r15 = S32(ctx->r19 << 16);
    // 0x800E21AC: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800E21B0: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800E21B4: beq         $a0, $t9, L_800E21A0
    if (ctx->r4 == ctx->r25) {
        // 0x800E21B8: sra         $s3, $t7, 16
        ctx->r19 = S32(SIGNED(ctx->r15) >> 16);
            goto L_800E21A0;
    }
    // 0x800E21B8: sra         $s3, $t7, 16
    ctx->r19 = S32(SIGNED(ctx->r15) >> 16);
L_800E21BC:
    // 0x800E21BC: bne         $a0, $at, L_800E21D0
    if (ctx->r4 != ctx->r1) {
        // 0x800E21C0: addu        $v0, $s5, $v1
        ctx->r2 = ADD32(ctx->r21, ctx->r3);
            goto L_800E21D0;
    }
    // 0x800E21C0: addu        $v0, $s5, $v1
    ctx->r2 = ADD32(ctx->r21, ctx->r3);
    // 0x800E21C4: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x800E21C8: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800E21CC: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
L_800E21D0:
    // 0x800E21D0: bgez        $v1, L_800E21F0
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800E21D4: lh          $t6, 0x9A($sp)
        ctx->r14 = MEM_H(ctx->r29, 0X9A);
            goto L_800E21F0;
    }
    // 0x800E21D4: lh          $t6, 0x9A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X9A);
    // 0x800E21D8: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800E21DC: sll         $t8, $s3, 16
    ctx->r24 = S32(ctx->r19 << 16);
    // 0x800E21E0: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800E21E4: sh          $t7, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r15;
    // 0x800E21E8: sra         $s3, $t8, 16
    ctx->r19 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800E21EC: addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
L_800E21F0:
    // 0x800E21F0: lw          $s0, 0xD0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XD0);
    // 0x800E21F4: lbu         $s4, 0xD7($sp)
    ctx->r20 = MEM_BU(ctx->r29, 0XD7);
    // 0x800E21F8: or          $s1, $s5, $zero
    ctx->r17 = ctx->r21 | 0;
    // 0x800E21FC: jal         0x800E1770
    // 0x800E2200: lh          $s2, 0x9A($sp)
    ctx->r18 = MEM_H(ctx->r29, 0X9A);
    func_800E1770(rdram, ctx);
        goto after_2;
    // 0x800E2200: lh          $s2, 0x9A($sp)
    ctx->r18 = MEM_H(ctx->r29, 0X9A);
    after_2:
    // 0x800E2204: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_800E2208:
    // 0x800E2208: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800E220C: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x800E2210: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x800E2214: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x800E2218: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x800E221C: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x800E2220: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x800E2224: jr          $ra
    // 0x800E2228: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
    return;
    // 0x800E2228: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
    // 0x800E222C: nop

;}
RECOMP_FUNC void alFilterNew_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E2230: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x800E2234: sw          $a1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r5;
    // 0x800E2238: sw          $a2, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r6;
    // 0x800E223C: sh          $zero, 0xC($a0)
    MEM_H(0XC, ctx->r4) = 0;
    // 0x800E2240: sh          $zero, 0xE($a0)
    MEM_H(0XE, ctx->r4) = 0;
    // 0x800E2244: jr          $ra
    // 0x800E2248: sw          $a3, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r7;
    return;
    // 0x800E2248: sw          $a3, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r7;
    // 0x800E224C: nop

;}
RECOMP_FUNC void _doModFunc_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E2250: mtc1        $a1, $f6
    ctx->f6.u32l = ctx->r5;
    // 0x800E2254: lwc1        $f4, 0x10($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800E2258: lwc1        $f16, 0x14($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800E225C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800E2260: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800E2264: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800E2268: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x800E226C: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800E2270: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800E2274: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x800E2278: swc1        $f18, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f18.u32l;
    // 0x800E227C: lwc1        $f6, 0x14($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800E2280: cvt.d.s     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f0.d = CVT_D_S(ctx->f6.fl);
    // 0x800E2284: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800E2288: c.lt.d      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.d < ctx->f0.d;
    // 0x800E228C: nop

    // 0x800E2290: bc1fl       L_800E22B8
    if (!c1cs) {
        // 0x800E2294: cvt.s.d     $f18, $f0
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f18.fl = CVT_S_D(ctx->f0.d);
            goto L_800E22B8;
    }
    goto skip_0;
    // 0x800E2294: cvt.s.d     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f18.fl = CVT_S_D(ctx->f0.d);
    skip_0:
    // 0x800E2298: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800E229C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800E22A0: nop

    // 0x800E22A4: sub.d       $f16, $f0, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f0.d - ctx->f8.d;
    // 0x800E22A8: cvt.s.d     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f10.fl = CVT_S_D(ctx->f16.d);
    // 0x800E22AC: b           L_800E22BC
    // 0x800E22B0: swc1        $f10, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f10.u32l;
        goto L_800E22BC;
    // 0x800E22B0: swc1        $f10, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f10.u32l;
    // 0x800E22B4: cvt.s.d     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f18.fl = CVT_S_D(ctx->f0.d);
L_800E22B8:
    // 0x800E22B8: swc1        $f18, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f18.u32l;
L_800E22BC:
    // 0x800E22BC: lwc1        $f2, 0x14($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800E22C0: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800E22C4: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800E22C8: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x800E22CC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800E22D0: bc1fl       L_800E22E0
    if (!c1cs) {
        // 0x800E22D4: cvt.d.s     $f4, $f2
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
            goto L_800E22E0;
    }
    goto skip_1;
    // 0x800E22D4: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    skip_1:
    // 0x800E22D8: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x800E22DC: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
L_800E22E0:
    // 0x800E22E0: lwc1        $f10, 0x1C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x800E22E4: sub.d       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f4.d - ctx->f8.d;
    // 0x800E22E8: cvt.s.d     $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f2.fl = CVT_S_D(ctx->f16.d);
    // 0x800E22EC: mul.s       $f0, $f10, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800E22F0: jr          $ra
    // 0x800E22F4: nop

    return;
    // 0x800E22F4: nop

;}
RECOMP_FUNC void _filterBuffer_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E22F8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800E22FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E2300: andi        $v0, $a1, 0xFFFF
    ctx->r2 = ctx->r5 & 0XFFFF;
    // 0x800E2304: sll         $t8, $a2, 1
    ctx->r24 = S32(ctx->r6 << 1);
    // 0x800E2308: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x800E230C: sll         $t7, $v0, 16
    ctx->r15 = S32(ctx->r2 << 16);
    // 0x800E2310: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x800E2314: lui         $t2, 0xB00
    ctx->r10 = S32(0XB00 << 16);
    // 0x800E2318: or          $t6, $v0, $at
    ctx->r14 = ctx->r2 | ctx->r1;
    // 0x800E231C: or          $t1, $t7, $t9
    ctx->r9 = ctx->r15 | ctx->r25;
    // 0x800E2320: ori         $t2, $t2, 0x20
    ctx->r10 = ctx->r10 | 0X20;
    // 0x800E2324: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x800E2328: sw          $t1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r9;
    // 0x800E232C: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x800E2330: sw          $t2, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r10;
    // 0x800E2334: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x800E2338: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800E233C: jal         0x800D70A0
    // 0x800E2340: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_0;
    // 0x800E2340: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_0:
    // 0x800E2344: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x800E2348: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800E234C: lui         $at, 0xE00
    ctx->r1 = S32(0XE00 << 16);
    // 0x800E2350: addiu       $v1, $a3, 0x10
    ctx->r3 = ADD32(ctx->r7, 0X10);
    // 0x800E2354: addiu       $t3, $v1, 0x8
    ctx->r11 = ADD32(ctx->r3, 0X8);
    // 0x800E2358: sw          $v0, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r2;
    // 0x800E235C: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x800E2360: lw          $t4, 0x2C($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X2C);
    // 0x800E2364: lh          $t7, 0x2($t0)
    ctx->r15 = MEM_H(ctx->r8, 0X2);
    // 0x800E2368: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x800E236C: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x800E2370: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x800E2374: andi        $t9, $t7, 0xFFFF
    ctx->r25 = ctx->r15 & 0XFFFF;
    // 0x800E2378: or          $t1, $t8, $t9
    ctx->r9 = ctx->r24 | ctx->r25;
    // 0x800E237C: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x800E2380: lw          $a0, 0x28($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X28);
    // 0x800E2384: jal         0x800D70A0
    // 0x800E2388: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_1;
    // 0x800E2388: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_1:
    // 0x800E238C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800E2390: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800E2394: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x800E2398: sw          $zero, 0x2C($t0)
    MEM_W(0X2C, ctx->r8) = 0;
    // 0x800E239C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E23A0: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x800E23A4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800E23A8: jr          $ra
    // 0x800E23AC: nop

    return;
    // 0x800E23AC: nop

;}
RECOMP_FUNC void _saveBuffer_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E23B0: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800E23B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800E23B8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800E23BC: lw          $v1, 0x1C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1C);
    // 0x800E23C0: lw          $v0, 0x14($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14);
    // 0x800E23C4: lw          $t0, 0x70($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X70);
    // 0x800E23C8: sll         $t6, $v1, 1
    ctx->r14 = S32(ctx->r3 << 1);
    // 0x800E23CC: sltu        $at, $a1, $v0
    ctx->r1 = ctx->r5 < ctx->r2 ? 1 : 0;
    // 0x800E23D0: or          $t2, $a0, $zero
    ctx->r10 = ctx->r4 | 0;
    // 0x800E23D4: or          $t5, $a2, $zero
    ctx->r13 = ctx->r6 | 0;
    // 0x800E23D8: or          $t3, $a3, $zero
    ctx->r11 = ctx->r7 | 0;
    // 0x800E23DC: beq         $at, $zero, L_800E23E8
    if (ctx->r1 == 0) {
        // 0x800E23E0: addu        $t1, $v0, $t6
        ctx->r9 = ADD32(ctx->r2, ctx->r14);
            goto L_800E23E8;
    }
    // 0x800E23E0: addu        $t1, $v0, $t6
    ctx->r9 = ADD32(ctx->r2, ctx->r14);
    // 0x800E23E4: addu        $a1, $a1, $t6
    ctx->r5 = ADD32(ctx->r5, ctx->r14);
L_800E23E8:
    // 0x800E23E8: sll         $a2, $t3, 1
    ctx->r6 = S32(ctx->r11 << 1);
    // 0x800E23EC: addu        $a3, $a2, $a1
    ctx->r7 = ADD32(ctx->r6, ctx->r5);
    // 0x800E23F0: sltu        $at, $t1, $a3
    ctx->r1 = ctx->r9 < ctx->r7 ? 1 : 0;
    // 0x800E23F4: beq         $at, $zero, L_800E24E8
    if (ctx->r1 == 0) {
        // 0x800E23F8: addiu       $s0, $t0, 0x8
        ctx->r16 = ADD32(ctx->r8, 0X8);
            goto L_800E24E8;
    }
    // 0x800E23F8: addiu       $s0, $t0, 0x8
    ctx->r16 = ADD32(ctx->r8, 0X8);
    // 0x800E23FC: subu        $t3, $t1, $a1
    ctx->r11 = SUB32(ctx->r9, ctx->r5);
    // 0x800E2400: sra         $t8, $t3, 1
    ctx->r24 = S32(SIGNED(ctx->r11) >> 1);
    // 0x800E2404: lui         $t7, 0x800
    ctx->r15 = S32(0X800 << 16);
    // 0x800E2408: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x800E240C: sll         $t3, $t8, 1
    ctx->r11 = S32(ctx->r24 << 1);
    // 0x800E2410: andi        $t8, $t3, 0xFFFF
    ctx->r24 = ctx->r11 & 0XFFFF;
    // 0x800E2414: sll         $t7, $t5, 16
    ctx->r15 = S32(ctx->r13 << 16);
    // 0x800E2418: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x800E241C: addiu       $s0, $t0, 0x8
    ctx->r16 = ADD32(ctx->r8, 0X8);
    // 0x800E2420: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x800E2424: or          $t4, $s0, $zero
    ctx->r12 = ctx->r16 | 0;
    // 0x800E2428: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x800E242C: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x800E2430: sw          $t5, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r13;
    // 0x800E2434: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
    // 0x800E2438: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x800E243C: sw          $t2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r10;
    // 0x800E2440: sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
    // 0x800E2444: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x800E2448: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x800E244C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800E2450: jal         0x800D70A0
    // 0x800E2454: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_0;
    // 0x800E2454: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x800E2458: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x800E245C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800E2460: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x800E2464: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x800E2468: lw          $t5, 0x68($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X68);
    // 0x800E246C: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x800E2470: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800E2474: lui         $t7, 0x800
    ctx->r15 = S32(0X800 << 16);
    // 0x800E2478: sw          $v0, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r2;
    // 0x800E247C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800E2480: subu        $t7, $a3, $t1
    ctx->r15 = SUB32(ctx->r7, ctx->r9);
    // 0x800E2484: addu        $t9, $t3, $t5
    ctx->r25 = ADD32(ctx->r11, ctx->r13);
    // 0x800E2488: sll         $t6, $t9, 16
    ctx->r14 = S32(ctx->r25 << 16);
    // 0x800E248C: sra         $t8, $t7, 1
    ctx->r24 = S32(SIGNED(ctx->r15) >> 1);
    // 0x800E2490: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800E2494: andi        $t7, $t9, 0xFFFF
    ctx->r15 = ctx->r25 & 0XFFFF;
    // 0x800E2498: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x800E249C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800E24A0: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800E24A4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800E24A8: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x800E24AC: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x800E24B0: lw          $a0, 0x14($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X14);
    // 0x800E24B4: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800E24B8: jal         0x800D70A0
    // 0x800E24BC: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_1;
    // 0x800E24BC: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    after_1:
    // 0x800E24C0: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x800E24C4: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x800E24C8: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800E24CC: lui         $t6, 0x800
    ctx->r14 = S32(0X800 << 16);
    // 0x800E24D0: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x800E24D4: andi        $t7, $a2, 0xFFFF
    ctx->r15 = ctx->r6 & 0XFFFF;
    // 0x800E24D8: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x800E24DC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800E24E0: b           L_800E2524
    // 0x800E24E4: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
        goto L_800E2524;
    // 0x800E24E4: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_800E24E8:
    // 0x800E24E8: lui         $t8, 0x800
    ctx->r24 = S32(0X800 << 16);
    // 0x800E24EC: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x800E24F0: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x800E24F4: andi        $t7, $a2, 0xFFFF
    ctx->r15 = ctx->r6 & 0XFFFF;
    // 0x800E24F8: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x800E24FC: sw          $t8, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r24;
    // 0x800E2500: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800E2504: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x800E2508: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800E250C: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    // 0x800E2510: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800E2514: jal         0x800D70A0
    // 0x800E2518: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_2;
    // 0x800E2518: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_2:
    // 0x800E251C: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x800E2520: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_800E2524:
    // 0x800E2524: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800E2528: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800E252C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800E2530: jr          $ra
    // 0x800E2534: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x800E2534: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void _loadBuffer_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E2538: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800E253C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800E2540: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800E2544: lw          $v1, 0x1C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1C);
    // 0x800E2548: lw          $v0, 0x14($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14);
    // 0x800E254C: lw          $t0, 0x70($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X70);
    // 0x800E2550: sll         $t6, $v1, 1
    ctx->r14 = S32(ctx->r3 << 1);
    // 0x800E2554: sltu        $at, $a1, $v0
    ctx->r1 = ctx->r5 < ctx->r2 ? 1 : 0;
    // 0x800E2558: or          $t2, $a0, $zero
    ctx->r10 = ctx->r4 | 0;
    // 0x800E255C: or          $t5, $a2, $zero
    ctx->r13 = ctx->r6 | 0;
    // 0x800E2560: or          $t3, $a3, $zero
    ctx->r11 = ctx->r7 | 0;
    // 0x800E2564: beq         $at, $zero, L_800E2570
    if (ctx->r1 == 0) {
        // 0x800E2568: addu        $t1, $v0, $t6
        ctx->r9 = ADD32(ctx->r2, ctx->r14);
            goto L_800E2570;
    }
    // 0x800E2568: addu        $t1, $v0, $t6
    ctx->r9 = ADD32(ctx->r2, ctx->r14);
    // 0x800E256C: addu        $a1, $a1, $t6
    ctx->r5 = ADD32(ctx->r5, ctx->r14);
L_800E2570:
    // 0x800E2570: sll         $a2, $t3, 1
    ctx->r6 = S32(ctx->r11 << 1);
    // 0x800E2574: addu        $a3, $a2, $a1
    ctx->r7 = ADD32(ctx->r6, ctx->r5);
    // 0x800E2578: sltu        $at, $t1, $a3
    ctx->r1 = ctx->r9 < ctx->r7 ? 1 : 0;
    // 0x800E257C: beq         $at, $zero, L_800E265C
    if (ctx->r1 == 0) {
        // 0x800E2580: addiu       $s0, $t0, 0x8
        ctx->r16 = ADD32(ctx->r8, 0X8);
            goto L_800E265C;
    }
    // 0x800E2580: addiu       $s0, $t0, 0x8
    ctx->r16 = ADD32(ctx->r8, 0X8);
    // 0x800E2584: andi        $t7, $t5, 0xFFFF
    ctx->r15 = ctx->r13 & 0XFFFF;
    // 0x800E2588: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x800E258C: subu        $t3, $t1, $a1
    ctx->r11 = SUB32(ctx->r9, ctx->r5);
    // 0x800E2590: sra         $t9, $t3, 1
    ctx->r25 = S32(SIGNED(ctx->r11) >> 1);
    // 0x800E2594: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x800E2598: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x800E259C: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x800E25A0: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x800E25A4: addiu       $s0, $t0, 0x8
    ctx->r16 = ADD32(ctx->r8, 0X8);
    // 0x800E25A8: sw          $t7, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r15;
    // 0x800E25AC: or          $t4, $s0, $zero
    ctx->r12 = ctx->r16 | 0;
    // 0x800E25B0: lui         $t8, 0x400
    ctx->r24 = S32(0X400 << 16);
    // 0x800E25B4: sw          $t8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r24;
    // 0x800E25B8: sw          $t5, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r13;
    // 0x800E25BC: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
    // 0x800E25C0: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x800E25C4: sw          $t2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r10;
    // 0x800E25C8: sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
    // 0x800E25CC: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x800E25D0: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x800E25D4: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800E25D8: jal         0x800D70A0
    // 0x800E25DC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_0;
    // 0x800E25DC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x800E25E0: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x800E25E4: lw          $t5, 0x68($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X68);
    // 0x800E25E8: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800E25EC: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x800E25F0: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x800E25F4: addu        $t9, $t3, $t5
    ctx->r25 = ADD32(ctx->r11, ctx->r13);
    // 0x800E25F8: andi        $t6, $t9, 0xFFFF
    ctx->r14 = ctx->r25 & 0XFFFF;
    // 0x800E25FC: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x800E2600: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x800E2604: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x800E2608: subu        $t8, $a3, $t1
    ctx->r24 = SUB32(ctx->r7, ctx->r9);
    // 0x800E260C: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x800E2610: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800E2614: sw          $v0, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r2;
    // 0x800E2618: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800E261C: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x800E2620: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x800E2624: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800E2628: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x800E262C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800E2630: lui         $t8, 0x400
    ctx->r24 = S32(0X400 << 16);
    // 0x800E2634: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x800E2638: lw          $a0, 0x14($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X14);
    // 0x800E263C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800E2640: jal         0x800D70A0
    // 0x800E2644: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_1;
    // 0x800E2644: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    after_1:
    // 0x800E2648: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x800E264C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x800E2650: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x800E2654: b           L_800E26A0
    // 0x800E2658: andi        $a3, $a2, 0xFFFF
    ctx->r7 = ctx->r6 & 0XFFFF;
        goto L_800E26A0;
    // 0x800E2658: andi        $a3, $a2, 0xFFFF
    ctx->r7 = ctx->r6 & 0XFFFF;
L_800E265C:
    // 0x800E265C: andi        $t9, $t5, 0xFFFF
    ctx->r25 = ctx->r13 & 0XFFFF;
    // 0x800E2660: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x800E2664: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x800E2668: andi        $a3, $a2, 0xFFFF
    ctx->r7 = ctx->r6 & 0XFFFF;
    // 0x800E266C: sw          $a3, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r7;
    // 0x800E2670: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x800E2674: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800E2678: lui         $t7, 0x400
    ctx->r15 = S32(0X400 << 16);
    // 0x800E267C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800E2680: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x800E2684: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x800E2688: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800E268C: jal         0x800D70A0
    // 0x800E2690: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_2;
    // 0x800E2690: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_2:
    // 0x800E2694: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x800E2698: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800E269C: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_800E26A0:
    // 0x800E26A0: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800E26A4: lui         $t8, 0x800
    ctx->r24 = S32(0X800 << 16);
    // 0x800E26A8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800E26AC: sw          $a3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r7;
    // 0x800E26B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800E26B4: addiu       $v0, $s0, 0x8
    ctx->r2 = ADD32(ctx->r16, 0X8);
    // 0x800E26B8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800E26BC: jr          $ra
    // 0x800E26C0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x800E26C0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void _loadOutputBuffer_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E26C4: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800E26C8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800E26CC: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800E26D0: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800E26D4: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x800E26D8: lw          $t6, 0x24($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X24);
    // 0x800E26DC: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800E26E0: or          $s1, $a3, $zero
    ctx->r17 = ctx->r7 | 0;
    // 0x800E26E4: beq         $t6, $zero, L_800E28A0
    if (ctx->r14 == 0) {
        // 0x800E26E8: or          $t2, $a0, $zero
        ctx->r10 = ctx->r4 | 0;
            goto L_800E28A0;
    }
    // 0x800E26E8: or          $t2, $a0, $zero
    ctx->r10 = ctx->r4 | 0;
    // 0x800E26EC: lw          $t7, 0x4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X4);
    // 0x800E26F0: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x800E26F4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800E26F8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x800E26FC: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x800E2700: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
    // 0x800E2704: jal         0x800E2250
    // 0x800E2708: sw          $t2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r10;
    _doModFunc_recomp(rdram, ctx);
        goto after_0;
    // 0x800E2708: sw          $t2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r10;
    after_0:
    // 0x800E270C: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x800E2710: lui         $at, 0x4700
    ctx->r1 = S32(0X4700 << 16);
    // 0x800E2714: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800E2718: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x800E271C: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800E2720: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800E2724: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800E2728: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800E272C: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x800E2730: addiu       $a2, $zero, 0x280
    ctx->r6 = ADD32(0, 0X280);
    // 0x800E2734: div.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800E2738: mul.s       $f16, $f10, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x800E273C: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800E2740: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x800E2744: nop

    // 0x800E2748: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x800E274C: nop

    // 0x800E2750: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800E2754: div.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f14.fl);
    // 0x800E2758: mtc1        $s1, $f8
    ctx->f8.u32l = ctx->r17;
    // 0x800E275C: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x800E2760: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800E2764: sub.d       $f18, $f4, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f4.d - ctx->f16.d;
    // 0x800E2768: cvt.s.d     $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f2.fl = CVT_S_D(ctx->f18.d);
    // 0x800E276C: mul.s       $f4, $f2, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x800E2770: swc1        $f2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f2.u32l;
    // 0x800E2774: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x800E2778: lwc1        $f6, 0x20($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X20);
    // 0x800E277C: add.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800E2780: trunc.w.s   $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    ctx->f16.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x800E2784: mfc1        $t1, $f16
    ctx->r9 = (int32_t)ctx->f16.u32l;
    // 0x800E2788: nop

    // 0x800E278C: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x800E2790: nop

    // 0x800E2794: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800E2798: sub.s       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f12.fl - ctx->f8.fl;
    // 0x800E279C: swc1        $f10, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f10.u32l;
    // 0x800E27A0: lw          $t9, 0x18($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X18);
    // 0x800E27A4: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x800E27A8: lw          $t7, 0x18($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X18);
    // 0x800E27AC: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x800E27B0: subu        $t4, $t8, $t9
    ctx->r12 = SUB32(ctx->r24, ctx->r25);
    // 0x800E27B4: negu        $t5, $t4
    ctx->r13 = SUB32(0, ctx->r12);
    // 0x800E27B8: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x800E27BC: addu        $t0, $t7, $t6
    ctx->r8 = ADD32(ctx->r15, ctx->r14);
    // 0x800E27C0: andi        $v1, $t0, 0x7
    ctx->r3 = ctx->r8 & 0X7;
    // 0x800E27C4: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x800E27C8: sra         $t8, $v1, 1
    ctx->r24 = S32(SIGNED(ctx->r3) >> 1);
    // 0x800E27CC: sll         $t3, $t8, 1
    ctx->r11 = S32(ctx->r24 << 1);
    // 0x800E27D0: subu        $a1, $t0, $t3
    ctx->r5 = SUB32(ctx->r8, ctx->r11);
    // 0x800E27D4: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x800E27D8: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x800E27DC: addu        $a3, $t1, $t8
    ctx->r7 = ADD32(ctx->r9, ctx->r24);
    // 0x800E27E0: jal         0x800E2538
    // 0x800E27E4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    _loadBuffer_recomp(rdram, ctx);
        goto after_1;
    // 0x800E27E4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_1:
    // 0x800E27E8: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x800E27EC: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x800E27F0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800E27F4: addiu       $t4, $t3, 0x280
    ctx->r12 = ADD32(ctx->r11, 0X280);
    // 0x800E27F8: andi        $t5, $t4, 0xFFFF
    ctx->r13 = ctx->r12 & 0XFFFF;
    // 0x800E27FC: or          $t7, $t5, $at
    ctx->r15 = ctx->r13 | ctx->r1;
    // 0x800E2800: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800E2804: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x800E2808: sll         $t4, $s1, 1
    ctx->r12 = S32(ctx->r17 << 1);
    // 0x800E280C: andi        $t5, $t4, 0xFFFF
    ctx->r13 = ctx->r12 & 0XFFFF;
    // 0x800E2810: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800E2814: or          $t7, $t9, $t5
    ctx->r15 = ctx->r25 | ctx->r13;
    // 0x800E2818: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800E281C: lui         $at, 0x4700
    ctx->r1 = S32(0X4700 << 16);
    // 0x800E2820: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800E2824: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800E2828: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x800E282C: lw          $t5, 0x24($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X24);
    // 0x800E2830: mul.s       $f16, $f6, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800E2834: lui         $at, 0x500
    ctx->r1 = S32(0X500 << 16);
    // 0x800E2838: lw          $t7, 0x24($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X24);
    // 0x800E283C: addiu       $v1, $v0, 0x10
    ctx->r3 = ADD32(ctx->r2, 0X10);
    // 0x800E2840: andi        $t6, $t7, 0xFF
    ctx->r14 = ctx->r15 & 0XFF;
    // 0x800E2844: sll         $t8, $t6, 16
    ctx->r24 = S32(ctx->r14 << 16);
    // 0x800E2848: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800E284C: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    // 0x800E2850: nop

    // 0x800E2854: andi        $t9, $t4, 0xFFFF
    ctx->r25 = ctx->r12 & 0XFFFF;
    // 0x800E2858: or          $t4, $t8, $at
    ctx->r12 = ctx->r24 | ctx->r1;
    // 0x800E285C: or          $t5, $t4, $t9
    ctx->r13 = ctx->r12 | ctx->r25;
    // 0x800E2860: sw          $t5, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r13;
    // 0x800E2864: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    // 0x800E2868: lw          $a0, 0x14($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X14);
    // 0x800E286C: jal         0x800D70A0
    // 0x800E2870: sw          $v1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r3;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_2;
    // 0x800E2870: sw          $v1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r3;
    after_2:
    // 0x800E2874: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800E2878: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800E287C: lw          $v1, 0x5C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X5C);
    // 0x800E2880: sw          $v0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r2;
    // 0x800E2884: lw          $t8, 0x24($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X24);
    // 0x800E2888: sw          $zero, 0x24($t8)
    MEM_W(0X24, ctx->r24) = 0;
    // 0x800E288C: lw          $t4, 0x18($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X18);
    // 0x800E2890: addu        $t9, $t4, $t1
    ctx->r25 = ADD32(ctx->r12, ctx->r9);
    // 0x800E2894: subu        $t5, $t9, $s1
    ctx->r13 = SUB32(ctx->r25, ctx->r17);
    // 0x800E2898: b           L_800E28D0
    // 0x800E289C: sw          $t5, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r13;
        goto L_800E28D0;
    // 0x800E289C: sw          $t5, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r13;
L_800E28A0:
    // 0x800E28A0: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x800E28A4: lw          $t7, 0x18($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X18);
    // 0x800E28A8: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x800E28AC: negu        $t8, $t6
    ctx->r24 = SUB32(0, ctx->r14);
    // 0x800E28B0: sll         $t4, $t8, 1
    ctx->r12 = S32(ctx->r24 << 1);
    // 0x800E28B4: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x800E28B8: lw          $a2, 0x68($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X68);
    // 0x800E28BC: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x800E28C0: addu        $a1, $t7, $t4
    ctx->r5 = ADD32(ctx->r15, ctx->r12);
    // 0x800E28C4: jal         0x800E2538
    // 0x800E28C8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    _loadBuffer_recomp(rdram, ctx);
        goto after_3;
    // 0x800E28C8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_3:
    // 0x800E28CC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800E28D0:
    // 0x800E28D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800E28D4: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800E28D8: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800E28DC: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x800E28E0: jr          $ra
    // 0x800E28E4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800E28E4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void alFxParamHdl_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E28E8: addiu       $v1, $a1, -0x2
    ctx->r3 = ADD32(ctx->r5, -0X2);
    // 0x800E28EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E28F0: andi        $t6, $v1, 0x7
    ctx->r14 = ctx->r3 & 0X7;
    // 0x800E28F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E28F8: sltiu       $at, $t6, 0x8
    ctx->r1 = ctx->r14 < 0X8 ? 1 : 0;
    // 0x800E28FC: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800E2900: beq         $at, $zero, L_800E2B30
    if (ctx->r1 == 0) {
        // 0x800E2904: lw          $t0, 0x0($a2)
        ctx->r8 = MEM_W(ctx->r6, 0X0);
            goto L_800E2B30;
    }
    // 0x800E2904: lw          $t0, 0x0($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X0);
    // 0x800E2908: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800E290C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800E2910: addu        $at, $at, $t6
    gpr jr_addend_800E2918 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800E2914: lw          $t6, -0x1C60($at)
    ctx->r14 = ADD32(ctx->r1, -0X1C60);
    // 0x800E2918: jr          $t6
    // 0x800E291C: nop

    switch (jr_addend_800E2918 >> 2) {
        case 0: goto L_800E2920; break;
        case 1: goto L_800E2954; break;
        case 2: goto L_800E29B4; break;
        case 3: goto L_800E2988; break;
        case 4: goto L_800E29E0; break;
        case 5: goto L_800E2A0C; break;
        case 6: goto L_800E2A74; break;
        case 7: goto L_800E2AEC; break;
        default: switch_error(__func__, 0x800E2918, 0x800EE3A0);
    }
    // 0x800E291C: nop

L_800E2920:
    // 0x800E2920: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x800E2924: and         $t7, $t0, $at
    ctx->r15 = ctx->r8 & ctx->r1;
    // 0x800E2928: lw          $t8, 0x20($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X20);
    // 0x800E292C: bgez        $v1, L_800E293C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800E2930: sra         $t9, $v1, 3
        ctx->r25 = S32(SIGNED(ctx->r3) >> 3);
            goto L_800E293C;
    }
    // 0x800E2930: sra         $t9, $v1, 3
    ctx->r25 = S32(SIGNED(ctx->r3) >> 3);
    // 0x800E2934: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x800E2938: sra         $t9, $at, 3
    ctx->r25 = S32(SIGNED(ctx->r1) >> 3);
L_800E293C:
    // 0x800E293C: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x800E2940: addu        $t1, $t1, $t9
    ctx->r9 = ADD32(ctx->r9, ctx->r25);
    // 0x800E2944: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x800E2948: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x800E294C: b           L_800E2B30
    // 0x800E2950: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
        goto L_800E2B30;
    // 0x800E2950: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
L_800E2954:
    // 0x800E2954: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x800E2958: and         $t3, $t0, $at
    ctx->r11 = ctx->r8 & ctx->r1;
    // 0x800E295C: lw          $t4, 0x20($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X20);
    // 0x800E2960: bgez        $v1, L_800E2970
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800E2964: sra         $t5, $v1, 3
        ctx->r13 = S32(SIGNED(ctx->r3) >> 3);
            goto L_800E2970;
    }
    // 0x800E2964: sra         $t5, $v1, 3
    ctx->r13 = S32(SIGNED(ctx->r3) >> 3);
    // 0x800E2968: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x800E296C: sra         $t5, $at, 3
    ctx->r13 = S32(SIGNED(ctx->r1) >> 3);
L_800E2970:
    // 0x800E2970: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800E2974: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x800E2978: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800E297C: addu        $t9, $t4, $t6
    ctx->r25 = ADD32(ctx->r12, ctx->r14);
    // 0x800E2980: b           L_800E2B30
    // 0x800E2984: sw          $t3, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r11;
        goto L_800E2B30;
    // 0x800E2984: sw          $t3, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r11;
L_800E2988:
    // 0x800E2988: lw          $t8, 0x20($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X20);
    // 0x800E298C: bgez        $v1, L_800E299C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800E2990: sra         $t1, $v1, 3
        ctx->r9 = S32(SIGNED(ctx->r3) >> 3);
            goto L_800E299C;
    }
    // 0x800E2990: sra         $t1, $v1, 3
    ctx->r9 = S32(SIGNED(ctx->r3) >> 3);
    // 0x800E2994: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x800E2998: sra         $t1, $at, 3
    ctx->r9 = S32(SIGNED(ctx->r1) >> 3);
L_800E299C:
    // 0x800E299C: sll         $t7, $t1, 2
    ctx->r15 = S32(ctx->r9 << 2);
    // 0x800E29A0: addu        $t7, $t7, $t1
    ctx->r15 = ADD32(ctx->r15, ctx->r9);
    // 0x800E29A4: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800E29A8: addu        $t2, $t8, $t7
    ctx->r10 = ADD32(ctx->r24, ctx->r15);
    // 0x800E29AC: b           L_800E2B30
    // 0x800E29B0: sh          $t0, 0x8($t2)
    MEM_H(0X8, ctx->r10) = ctx->r8;
        goto L_800E2B30;
    // 0x800E29B0: sh          $t0, 0x8($t2)
    MEM_H(0X8, ctx->r10) = ctx->r8;
L_800E29B4:
    // 0x800E29B4: lw          $t5, 0x20($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X20);
    // 0x800E29B8: bgez        $v1, L_800E29C8
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800E29BC: sra         $t4, $v1, 3
        ctx->r12 = S32(SIGNED(ctx->r3) >> 3);
            goto L_800E29C8;
    }
    // 0x800E29BC: sra         $t4, $v1, 3
    ctx->r12 = S32(SIGNED(ctx->r3) >> 3);
    // 0x800E29C0: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x800E29C4: sra         $t4, $at, 3
    ctx->r12 = S32(SIGNED(ctx->r1) >> 3);
L_800E29C8:
    // 0x800E29C8: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x800E29CC: addu        $t6, $t6, $t4
    ctx->r14 = ADD32(ctx->r14, ctx->r12);
    // 0x800E29D0: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800E29D4: addu        $t3, $t5, $t6
    ctx->r11 = ADD32(ctx->r13, ctx->r14);
    // 0x800E29D8: b           L_800E2B30
    // 0x800E29DC: sh          $t0, 0xA($t3)
    MEM_H(0XA, ctx->r11) = ctx->r8;
        goto L_800E2B30;
    // 0x800E29DC: sh          $t0, 0xA($t3)
    MEM_H(0XA, ctx->r11) = ctx->r8;
L_800E29E0:
    // 0x800E29E0: lw          $t9, 0x20($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X20);
    // 0x800E29E4: bgez        $v1, L_800E29F4
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800E29E8: sra         $t1, $v1, 3
        ctx->r9 = S32(SIGNED(ctx->r3) >> 3);
            goto L_800E29F4;
    }
    // 0x800E29E8: sra         $t1, $v1, 3
    ctx->r9 = S32(SIGNED(ctx->r3) >> 3);
    // 0x800E29EC: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x800E29F0: sra         $t1, $at, 3
    ctx->r9 = S32(SIGNED(ctx->r1) >> 3);
L_800E29F4:
    // 0x800E29F4: sll         $t8, $t1, 2
    ctx->r24 = S32(ctx->r9 << 2);
    // 0x800E29F8: addu        $t8, $t8, $t1
    ctx->r24 = ADD32(ctx->r24, ctx->r9);
    // 0x800E29FC: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x800E2A00: addu        $t7, $t9, $t8
    ctx->r15 = ADD32(ctx->r25, ctx->r24);
    // 0x800E2A04: b           L_800E2B30
    // 0x800E2A08: sh          $t0, 0xC($t7)
    MEM_H(0XC, ctx->r15) = ctx->r8;
        goto L_800E2B30;
    // 0x800E2A08: sh          $t0, 0xC($t7)
    MEM_H(0XC, ctx->r15) = ctx->r8;
L_800E2A0C:
    // 0x800E2A0C: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x800E2A10: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x800E2A14: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800E2A18: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800E2A1C: lui         $t2, 0x800F
    ctx->r10 = S32(0X800F << 16);
    // 0x800E2A20: lw          $t2, -0x3210($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X3210);
    // 0x800E2A24: lw          $t5, 0x20($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X20);
    // 0x800E2A28: lw          $t4, 0x44($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X44);
    // 0x800E2A2C: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800E2A30: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x800E2A34: nop

    // 0x800E2A38: cvt.d.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.d = CVT_D_W(ctx->f18.u32l);
    // 0x800E2A3C: cvt.d.s     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f0.d = CVT_D_S(ctx->f10.fl);
    // 0x800E2A40: add.d       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f16.d = ctx->f0.d + ctx->f0.d;
    // 0x800E2A44: div.d       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f16.d, ctx->f4.d);
    // 0x800E2A48: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x800E2A4C: bgez        $v1, L_800E2A5C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800E2A50: sra         $t6, $v1, 3
        ctx->r14 = S32(SIGNED(ctx->r3) >> 3);
            goto L_800E2A5C;
    }
    // 0x800E2A50: sra         $t6, $v1, 3
    ctx->r14 = S32(SIGNED(ctx->r3) >> 3);
    // 0x800E2A54: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x800E2A58: sra         $t6, $at, 3
    ctx->r14 = S32(SIGNED(ctx->r1) >> 3);
L_800E2A5C:
    // 0x800E2A5C: sll         $t3, $t6, 2
    ctx->r11 = S32(ctx->r14 << 2);
    // 0x800E2A60: addu        $t3, $t3, $t6
    ctx->r11 = ADD32(ctx->r11, ctx->r14);
    // 0x800E2A64: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x800E2A68: addu        $t1, $t5, $t3
    ctx->r9 = ADD32(ctx->r13, ctx->r11);
    // 0x800E2A6C: b           L_800E2B30
    // 0x800E2A70: swc1        $f8, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->f8.u32l;
        goto L_800E2B30;
    // 0x800E2A70: swc1        $f8, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->f8.u32l;
L_800E2A74:
    // 0x800E2A74: lw          $t9, 0x20($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X20);
    // 0x800E2A78: bgez        $v1, L_800E2A88
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800E2A7C: sra         $t8, $v1, 3
        ctx->r24 = S32(SIGNED(ctx->r3) >> 3);
            goto L_800E2A88;
    }
    // 0x800E2A7C: sra         $t8, $v1, 3
    ctx->r24 = S32(SIGNED(ctx->r3) >> 3);
    // 0x800E2A80: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x800E2A84: sra         $t8, $at, 3
    ctx->r24 = S32(SIGNED(ctx->r1) >> 3);
L_800E2A88:
    // 0x800E2A88: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x800E2A8C: addu        $t7, $t7, $t8
    ctx->r15 = ADD32(ctx->r15, ctx->r24);
    // 0x800E2A90: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800E2A94: addu        $v0, $t9, $t7
    ctx->r2 = ADD32(ctx->r25, ctx->r15);
    // 0x800E2A98: lw          $t2, 0x4($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X4);
    // 0x800E2A9C: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x800E2AA0: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x800E2AA4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800E2AA8: subu        $t6, $t2, $t4
    ctx->r14 = SUB32(ctx->r10, ctx->r12);
    // 0x800E2AAC: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x800E2AB0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800E2AB4: bgez        $t6, L_800E2ACC
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800E2AB8: cvt.d.w     $f18, $f10
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.d = CVT_D_W(ctx->f10.u32l);
            goto L_800E2ACC;
    }
    // 0x800E2AB8: cvt.d.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.d = CVT_D_W(ctx->f10.u32l);
    // 0x800E2ABC: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800E2AC0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800E2AC4: nop

    // 0x800E2AC8: add.d       $f18, $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f18.d + ctx->f16.d;
L_800E2ACC:
    // 0x800E2ACC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800E2AD0: ldc1        $f10, -0x1C40($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X1C40);
    // 0x800E2AD4: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800E2AD8: div.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = DIV_D(ctx->f8.d, ctx->f10.d);
    // 0x800E2ADC: mul.d       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f16.d);
    // 0x800E2AE0: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x800E2AE4: b           L_800E2B30
    // 0x800E2AE8: swc1        $f6, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f6.u32l;
        goto L_800E2B30;
    // 0x800E2AE8: swc1        $f6, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f6.u32l;
L_800E2AEC:
    // 0x800E2AEC: bgez        $v1, L_800E2AFC
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800E2AF0: sra         $v0, $v1, 3
        ctx->r2 = S32(SIGNED(ctx->r3) >> 3);
            goto L_800E2AFC;
    }
    // 0x800E2AF0: sra         $v0, $v1, 3
    ctx->r2 = S32(SIGNED(ctx->r3) >> 3);
    // 0x800E2AF4: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x800E2AF8: sra         $v0, $at, 3
    ctx->r2 = S32(SIGNED(ctx->r1) >> 3);
L_800E2AFC:
    // 0x800E2AFC: lw          $t3, 0x20($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X20);
    // 0x800E2B00: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x800E2B04: addu        $t5, $t5, $v0
    ctx->r13 = ADD32(ctx->r13, ctx->r2);
    // 0x800E2B08: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x800E2B0C: addu        $t1, $t3, $t5
    ctx->r9 = ADD32(ctx->r11, ctx->r13);
    // 0x800E2B10: lw          $a1, 0x20($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X20);
    // 0x800E2B14: beql        $a1, $zero, L_800E2B34
    if (ctx->r5 == 0) {
        // 0x800E2B18: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800E2B34;
    }
    goto skip_0;
    // 0x800E2B18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800E2B1C: sh          $t0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r8;
    // 0x800E2B20: lw          $t8, 0x20($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X20);
    // 0x800E2B24: addu        $t9, $t8, $t5
    ctx->r25 = ADD32(ctx->r24, ctx->r13);
    // 0x800E2B28: jal         0x800DDC70
    // 0x800E2B2C: lw          $a0, 0x20($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X20);
    init_lpfilter_recomp(rdram, ctx);
        goto after_0;
    // 0x800E2B2C: lw          $a0, 0x20($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X20);
    after_0:
L_800E2B30:
    // 0x800E2B30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800E2B34:
    // 0x800E2B34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E2B38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800E2B3C: jr          $ra
    // 0x800E2B40: nop

    return;
    // 0x800E2B40: nop

;}
RECOMP_FUNC void alFxParam_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E2B44: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800E2B48: bne         $a1, $at, L_800E2B54
    if (ctx->r5 != ctx->r1) {
        // 0x800E2B4C: nop
    
            goto L_800E2B54;
    }
    // 0x800E2B4C: nop

    // 0x800E2B50: sw          $a2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r6;
L_800E2B54:
    // 0x800E2B54: jr          $ra
    // 0x800E2B58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800E2B58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void alFxPull_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E2B5C: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x800E2B60: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800E2B64: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800E2B68: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800E2B6C: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x800E2B70: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x800E2B74: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800E2B78: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800E2B7C: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800E2B80: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800E2B84: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800E2B88: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800E2B8C: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x800E2B90: lw          $t6, 0xB8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB8);
    // 0x800E2B94: sw          $zero, 0x80($sp)
    MEM_W(0X80, ctx->r29) = 0;
    // 0x800E2B98: or          $s6, $a2, $zero
    ctx->r22 = ctx->r6 | 0;
    // 0x800E2B9C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800E2BA0: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x800E2BA4: jalr        $t9
    // 0x800E2BA8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800E2BA8: nop

    after_0:
    // 0x800E2BAC: sll         $s1, $s6, 1
    ctx->r17 = S32(ctx->r22 << 1);
    // 0x800E2BB0: lui         $t8, 0xC00
    ctx->r24 = S32(0XC00 << 16);
    // 0x800E2BB4: lui         $t2, 0x6C0
    ctx->r10 = S32(0X6C0 << 16);
    // 0x800E2BB8: lui         $t3, 0xC00
    ctx->r11 = S32(0XC00 << 16);
    // 0x800E2BBC: lui         $t4, 0x800
    ctx->r12 = S32(0X800 << 16);
    // 0x800E2BC0: andi        $t1, $s1, 0xFFFF
    ctx->r9 = ctx->r17 & 0XFFFF;
    // 0x800E2BC4: lui         $t7, 0x800
    ctx->r15 = S32(0X800 << 16);
    // 0x800E2BC8: ori         $t2, $t2, 0x6C0
    ctx->r10 = ctx->r10 | 0X6C0;
    // 0x800E2BCC: ori         $t8, $t8, 0xDA83
    ctx->r24 = ctx->r24 | 0XDA83;
    // 0x800E2BD0: ori         $t4, $t4, 0x6C0
    ctx->r12 = ctx->r12 | 0X6C0;
    // 0x800E2BD4: ori         $t3, $t3, 0x5A82
    ctx->r11 = ctx->r11 | 0X5A82;
    // 0x800E2BD8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800E2BDC: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x800E2BE0: sw          $t8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r24;
    // 0x800E2BE4: sw          $t2, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r10;
    // 0x800E2BE8: sw          $t3, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r11;
    // 0x800E2BEC: sw          $t4, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r12;
    // 0x800E2BF0: lw          $a1, 0x18($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X18);
    // 0x800E2BF4: addiu       $t5, $v0, 0x18
    ctx->r13 = ADD32(ctx->r2, 0X18);
    // 0x800E2BF8: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x800E2BFC: addiu       $s2, $zero, 0x140
    ctx->r18 = ADD32(0, 0X140);
    // 0x800E2C00: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800E2C04: sw          $t1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r9;
    // 0x800E2C08: sw          $s1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r17;
    // 0x800E2C0C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800E2C10: addiu       $a2, $zero, 0x6C0
    ctx->r6 = ADD32(0, 0X6C0);
    // 0x800E2C14: jal         0x800E23B0
    // 0x800E2C18: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    _saveBuffer_recomp(rdram, ctx);
        goto after_1;
    // 0x800E2C18: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    after_1:
    // 0x800E2C1C: lw          $v1, 0x80($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X80);
    // 0x800E2C20: lui         $t6, 0x200
    ctx->r14 = S32(0X200 << 16);
    // 0x800E2C24: ori         $t6, $t6, 0x800
    ctx->r14 = ctx->r14 | 0X800;
    // 0x800E2C28: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800E2C2C: sw          $s1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r17;
    // 0x800E2C30: lbu         $t9, 0x24($s3)
    ctx->r25 = MEM_BU(ctx->r19, 0X24);
    // 0x800E2C34: addiu       $s0, $v0, 0x8
    ctx->r16 = ADD32(ctx->r2, 0X8);
    // 0x800E2C38: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x800E2C3C: blezl       $t9, L_800E2E1C
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800E2C40: lw          $v1, 0x1C($s3)
        ctx->r3 = MEM_W(ctx->r19, 0X1C);
            goto L_800E2E1C;
    }
    goto skip_0;
    // 0x800E2C40: lw          $v1, 0x1C($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X1C);
    skip_0:
    // 0x800E2C44: lw          $v0, 0x18($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X18);
L_800E2C48:
    // 0x800E2C48: lw          $t7, 0x20($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X20);
    // 0x800E2C4C: sll         $t8, $s7, 2
    ctx->r24 = S32(ctx->r23 << 2);
    // 0x800E2C50: addu        $t8, $t8, $s7
    ctx->r24 = ADD32(ctx->r24, ctx->r23);
    // 0x800E2C54: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x800E2C58: addu        $s1, $t7, $t8
    ctx->r17 = ADD32(ctx->r15, ctx->r24);
    // 0x800E2C5C: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x800E2C60: lw          $t5, 0x4($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X4);
    // 0x800E2C64: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800E2C68: negu        $t3, $t2
    ctx->r11 = SUB32(0, ctx->r10);
    // 0x800E2C6C: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x800E2C70: negu        $t6, $t5
    ctx->r14 = SUB32(0, ctx->r13);
    // 0x800E2C74: addu        $s4, $v0, $t4
    ctx->r20 = ADD32(ctx->r2, ctx->r12);
    // 0x800E2C78: sll         $t9, $t6, 1
    ctx->r25 = S32(ctx->r14 << 1);
    // 0x800E2C7C: bne         $s4, $v1, L_800E2CA4
    if (ctx->r20 != ctx->r3) {
        // 0x800E2C80: addu        $fp, $v0, $t9
        ctx->r30 = ADD32(ctx->r2, ctx->r25);
            goto L_800E2CA4;
    }
    // 0x800E2C80: addu        $fp, $v0, $t9
    ctx->r30 = ADD32(ctx->r2, ctx->r25);
    // 0x800E2C84: or          $t7, $s2, $zero
    ctx->r15 = ctx->r18 | 0;
    // 0x800E2C88: sll         $s2, $s5, 16
    ctx->r18 = S32(ctx->r21 << 16);
    // 0x800E2C8C: sll         $s5, $t7, 16
    ctx->r21 = S32(ctx->r15 << 16);
    // 0x800E2C90: sra         $t2, $s5, 16
    ctx->r10 = S32(SIGNED(ctx->r21) >> 16);
    // 0x800E2C94: sra         $t8, $s2, 16
    ctx->r24 = S32(SIGNED(ctx->r18) >> 16);
    // 0x800E2C98: or          $s2, $t8, $zero
    ctx->r18 = ctx->r24 | 0;
    // 0x800E2C9C: b           L_800E2CBC
    // 0x800E2CA0: or          $s5, $t2, $zero
    ctx->r21 = ctx->r10 | 0;
        goto L_800E2CBC;
    // 0x800E2CA0: or          $s5, $t2, $zero
    ctx->r21 = ctx->r10 | 0;
L_800E2CA4:
    // 0x800E2CA4: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x800E2CA8: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x800E2CAC: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    // 0x800E2CB0: jal         0x800E2538
    // 0x800E2CB4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    _loadBuffer_recomp(rdram, ctx);
        goto after_2;
    // 0x800E2CB4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_2:
    // 0x800E2CB8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_800E2CBC:
    // 0x800E2CBC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800E2CC0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800E2CC4: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800E2CC8: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    // 0x800E2CCC: jal         0x800E26C4
    // 0x800E2CD0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    _loadOutputBuffer_recomp(rdram, ctx);
        goto after_3;
    // 0x800E2CD0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_3:
    // 0x800E2CD4: lh          $a0, 0x8($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X8);
    // 0x800E2CD8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800E2CDC: lui         $at, 0xC00
    ctx->r1 = S32(0XC00 << 16);
    // 0x800E2CE0: beq         $a0, $zero, L_800E2D34
    if (ctx->r4 == 0) {
        // 0x800E2CE4: andi        $t4, $a0, 0xFFFF
        ctx->r12 = ctx->r4 & 0XFFFF;
            goto L_800E2D34;
    }
    // 0x800E2CE4: andi        $t4, $a0, 0xFFFF
    ctx->r12 = ctx->r4 & 0XFFFF;
    // 0x800E2CE8: sll         $t9, $s5, 16
    ctx->r25 = S32(ctx->r21 << 16);
    // 0x800E2CEC: andi        $t7, $s2, 0xFFFF
    ctx->r15 = ctx->r18 & 0XFFFF;
    // 0x800E2CF0: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x800E2CF4: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x800E2CF8: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800E2CFC: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800E2D00: lw          $t2, 0x24($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X24);
    // 0x800E2D04: addiu       $s0, $v0, 0x8
    ctx->r16 = ADD32(ctx->r2, 0X8);
    // 0x800E2D08: bnel        $t2, $zero, L_800E2D38
    if (ctx->r10 != 0) {
        // 0x800E2D0C: lh          $v1, 0xA($s1)
        ctx->r3 = MEM_H(ctx->r17, 0XA);
            goto L_800E2D38;
    }
    goto skip_1;
    // 0x800E2D0C: lh          $v1, 0xA($s1)
    ctx->r3 = MEM_H(ctx->r17, 0XA);
    skip_1:
    // 0x800E2D10: lw          $t3, 0x20($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X20);
    // 0x800E2D14: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800E2D18: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    // 0x800E2D1C: bne         $t3, $zero, L_800E2D34
    if (ctx->r11 != 0) {
        // 0x800E2D20: or          $a2, $s2, $zero
        ctx->r6 = ctx->r18 | 0;
            goto L_800E2D34;
    }
    // 0x800E2D20: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800E2D24: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    // 0x800E2D28: jal         0x800E23B0
    // 0x800E2D2C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    _saveBuffer_recomp(rdram, ctx);
        goto after_4;
    // 0x800E2D2C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_4:
    // 0x800E2D30: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_800E2D34:
    // 0x800E2D34: lh          $v1, 0xA($s1)
    ctx->r3 = MEM_H(ctx->r17, 0XA);
L_800E2D38:
    // 0x800E2D38: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800E2D3C: lui         $at, 0xC00
    ctx->r1 = S32(0XC00 << 16);
    // 0x800E2D40: beq         $v1, $zero, L_800E2D80
    if (ctx->r3 == 0) {
        // 0x800E2D44: andi        $t5, $v1, 0xFFFF
        ctx->r13 = ctx->r3 & 0XFFFF;
            goto L_800E2D80;
    }
    // 0x800E2D44: andi        $t5, $v1, 0xFFFF
    ctx->r13 = ctx->r3 & 0XFFFF;
    // 0x800E2D48: sll         $t7, $s2, 16
    ctx->r15 = S32(ctx->r18 << 16);
    // 0x800E2D4C: andi        $t8, $s5, 0xFFFF
    ctx->r24 = ctx->r21 & 0XFFFF;
    // 0x800E2D50: or          $t2, $t7, $t8
    ctx->r10 = ctx->r15 | ctx->r24;
    // 0x800E2D54: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x800E2D58: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800E2D5C: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x800E2D60: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800E2D64: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800E2D68: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800E2D6C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x800E2D70: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x800E2D74: jal         0x800E23B0
    // 0x800E2D78: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    _saveBuffer_recomp(rdram, ctx);
        goto after_5;
    // 0x800E2D78: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    after_5:
    // 0x800E2D7C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_800E2D80:
    // 0x800E2D80: lw          $a0, 0x20($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X20);
    // 0x800E2D84: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800E2D88: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x800E2D8C: beql        $a0, $zero, L_800E2DA4
    if (ctx->r4 == 0) {
        // 0x800E2D90: lw          $t3, 0x24($s1)
        ctx->r11 = MEM_W(ctx->r17, 0X24);
            goto L_800E2DA4;
    }
    goto skip_2;
    // 0x800E2D90: lw          $t3, 0x24($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X24);
    skip_2:
    // 0x800E2D94: jal         0x800E22F8
    // 0x800E2D98: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    _filterBuffer_recomp(rdram, ctx);
        goto after_6;
    // 0x800E2D98: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_6:
    // 0x800E2D9C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800E2DA0: lw          $t3, 0x24($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X24);
L_800E2DA4:
    // 0x800E2DA4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800E2DA8: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    // 0x800E2DAC: bne         $t3, $zero, L_800E2DC4
    if (ctx->r11 != 0) {
        // 0x800E2DB0: or          $a2, $s2, $zero
        ctx->r6 = ctx->r18 | 0;
            goto L_800E2DC4;
    }
    // 0x800E2DB0: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800E2DB4: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    // 0x800E2DB8: jal         0x800E23B0
    // 0x800E2DBC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    _saveBuffer_recomp(rdram, ctx);
        goto after_7;
    // 0x800E2DBC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_7:
    // 0x800E2DC0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_800E2DC4:
    // 0x800E2DC4: lh          $v1, 0xC($s1)
    ctx->r3 = MEM_H(ctx->r17, 0XC);
    // 0x800E2DC8: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x800E2DCC: sll         $t4, $s7, 16
    ctx->r12 = S32(ctx->r23 << 16);
    // 0x800E2DD0: beq         $v1, $zero, L_800E2DFC
    if (ctx->r3 == 0) {
        // 0x800E2DD4: sra         $s7, $t4, 16
        ctx->r23 = S32(SIGNED(ctx->r12) >> 16);
            goto L_800E2DFC;
    }
    // 0x800E2DD4: sra         $s7, $t4, 16
    ctx->r23 = S32(SIGNED(ctx->r12) >> 16);
    // 0x800E2DD8: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800E2DDC: andi        $t5, $v1, 0xFFFF
    ctx->r13 = ctx->r3 & 0XFFFF;
    // 0x800E2DE0: lui         $at, 0xC00
    ctx->r1 = S32(0XC00 << 16);
    // 0x800E2DE4: sll         $t7, $s2, 16
    ctx->r15 = S32(ctx->r18 << 16);
    // 0x800E2DE8: ori         $t8, $t7, 0x800
    ctx->r24 = ctx->r15 | 0X800;
    // 0x800E2DEC: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x800E2DF0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800E2DF4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800E2DF8: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_800E2DFC:
    // 0x800E2DFC: lbu         $t6, 0x24($s3)
    ctx->r14 = MEM_BU(ctx->r19, 0X24);
    // 0x800E2E00: lw          $t2, 0x4($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X4);
    // 0x800E2E04: lw          $v0, 0x18($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X18);
    // 0x800E2E08: slt         $at, $s7, $t6
    ctx->r1 = SIGNED(ctx->r23) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800E2E0C: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x800E2E10: bne         $at, $zero, L_800E2C48
    if (ctx->r1 != 0) {
        // 0x800E2E14: addu        $v1, $v0, $t3
        ctx->r3 = ADD32(ctx->r2, ctx->r11);
            goto L_800E2C48;
    }
    // 0x800E2E14: addu        $v1, $v0, $t3
    ctx->r3 = ADD32(ctx->r2, ctx->r11);
    // 0x800E2E18: lw          $v1, 0x1C($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X1C);
L_800E2E1C:
    // 0x800E2E1C: lw          $t9, 0x18($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X18);
    // 0x800E2E20: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x800E2E24: lw          $t3, 0x14($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X14);
    // 0x800E2E28: sll         $t2, $v1, 1
    ctx->r10 = S32(ctx->r3 << 1);
    // 0x800E2E2C: addu        $t8, $t9, $t7
    ctx->r24 = ADD32(ctx->r25, ctx->r15);
    // 0x800E2E30: addu        $t4, $t3, $t2
    ctx->r12 = ADD32(ctx->r11, ctx->r10);
    // 0x800E2E34: sltu        $at, $t4, $t8
    ctx->r1 = ctx->r12 < ctx->r24 ? 1 : 0;
    // 0x800E2E38: beq         $at, $zero, L_800E2E48
    if (ctx->r1 == 0) {
        // 0x800E2E3C: sw          $t8, 0x18($s3)
        MEM_W(0X18, ctx->r19) = ctx->r24;
            goto L_800E2E48;
    }
    // 0x800E2E3C: sw          $t8, 0x18($s3)
    MEM_W(0X18, ctx->r19) = ctx->r24;
    // 0x800E2E40: subu        $t5, $t8, $t2
    ctx->r13 = SUB32(ctx->r24, ctx->r10);
    // 0x800E2E44: sw          $t5, 0x18($s3)
    MEM_W(0X18, ctx->r19) = ctx->r13;
L_800E2E48:
    // 0x800E2E48: lui         $t6, 0xA00
    ctx->r14 = S32(0XA00 << 16);
    // 0x800E2E4C: ori         $t6, $t6, 0x800
    ctx->r14 = ctx->r14 | 0X800;
    // 0x800E2E50: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800E2E54: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800E2E58: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x800E2E5C: lui         $at, 0x6C0
    ctx->r1 = S32(0X6C0 << 16);
    // 0x800E2E60: addiu       $v0, $s0, 0x8
    ctx->r2 = ADD32(ctx->r16, 0X8);
    // 0x800E2E64: or          $t7, $t9, $at
    ctx->r15 = ctx->r25 | ctx->r1;
    // 0x800E2E68: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x800E2E6C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800E2E70: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x800E2E74: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x800E2E78: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800E2E7C: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800E2E80: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800E2E84: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800E2E88: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800E2E8C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800E2E90: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800E2E94: jr          $ra
    // 0x800E2E98: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x800E2E98: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    // 0x800E2E9C: nop

;}
RECOMP_FUNC void alCopy_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E2EA0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800E2EA4: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x800E2EA8: blez        $a2, L_800E2F0C
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800E2EAC: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_800E2F0C;
    }
    // 0x800E2EAC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800E2EB0: andi        $a1, $a2, 0x3
    ctx->r5 = ctx->r6 & 0X3;
    // 0x800E2EB4: beq         $a1, $zero, L_800E2EDC
    if (ctx->r5 == 0) {
        // 0x800E2EB8: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_800E2EDC;
    }
    // 0x800E2EB8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
L_800E2EBC:
    // 0x800E2EBC: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x800E2EC0: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800E2EC4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800E2EC8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800E2ECC: bne         $a0, $a3, L_800E2EBC
    if (ctx->r4 != ctx->r7) {
        // 0x800E2ED0: sb          $t6, -0x1($v1)
        MEM_B(-0X1, ctx->r3) = ctx->r14;
            goto L_800E2EBC;
    }
    // 0x800E2ED0: sb          $t6, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r14;
    // 0x800E2ED4: beq         $a3, $a2, L_800E2F0C
    if (ctx->r7 == ctx->r6) {
        // 0x800E2ED8: nop
    
            goto L_800E2F0C;
    }
    // 0x800E2ED8: nop

L_800E2EDC:
    // 0x800E2EDC: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x800E2EE0: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x800E2EE4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800E2EE8: sb          $t7, -0x4($v1)
    MEM_B(-0X4, ctx->r3) = ctx->r15;
    // 0x800E2EEC: lbu         $t8, 0x1($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1);
    // 0x800E2EF0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800E2EF4: sb          $t8, -0x3($v1)
    MEM_B(-0X3, ctx->r3) = ctx->r24;
    // 0x800E2EF8: lbu         $t9, -0x2($v0)
    ctx->r25 = MEM_BU(ctx->r2, -0X2);
    // 0x800E2EFC: sb          $t9, -0x2($v1)
    MEM_B(-0X2, ctx->r3) = ctx->r25;
    // 0x800E2F00: lbu         $t0, -0x1($v0)
    ctx->r8 = MEM_BU(ctx->r2, -0X1);
    // 0x800E2F04: bne         $a3, $a2, L_800E2EDC
    if (ctx->r7 != ctx->r6) {
        // 0x800E2F08: sb          $t0, -0x1($v1)
        MEM_B(-0X1, ctx->r3) = ctx->r8;
            goto L_800E2EDC;
    }
    // 0x800E2F08: sb          $t0, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r8;
L_800E2F0C:
    // 0x800E2F0C: jr          $ra
    // 0x800E2F10: nop

    return;
    // 0x800E2F10: nop

    // 0x800E2F14: nop

    // 0x800E2F18: nop

    // 0x800E2F1C: nop

;}
RECOMP_FUNC void lldiv_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E3B10: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800E3B14: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800E3B18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E3B1C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800E3B20: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x800E3B24: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800E3B28: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x800E3B2C: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x800E3B30: jal         0x800DC49C
    // 0x800E3B34: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    __ll_div_recomp(rdram, ctx);
        goto after_0;
    // 0x800E3B34: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    after_0:
    // 0x800E3B38: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800E3B3C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x800E3B40: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800E3B44: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x800E3B48: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800E3B4C: jal         0x800DC4F8
    // 0x800E3B50: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    __ll_mul_recomp(rdram, ctx);
        goto after_1;
    // 0x800E3B50: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    after_1:
    // 0x800E3B54: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800E3B58: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x800E3B5C: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800E3B60: subu        $t8, $t6, $v0
    ctx->r24 = SUB32(ctx->r14, ctx->r2);
    // 0x800E3B64: sltu        $at, $t7, $v1
    ctx->r1 = ctx->r15 < ctx->r3 ? 1 : 0;
    // 0x800E3B68: subu        $t8, $t8, $at
    ctx->r24 = SUB32(ctx->r24, ctx->r1);
    // 0x800E3B6C: subu        $t9, $t7, $v1
    ctx->r25 = SUB32(ctx->r15, ctx->r3);
    // 0x800E3B70: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x800E3B74: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x800E3B78: bgtz        $t0, L_800E3BD8
    if (SIGNED(ctx->r8) > 0) {
        // 0x800E3B7C: lw          $t1, 0x24($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X24);
            goto L_800E3BD8;
    }
    // 0x800E3B7C: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800E3B80: bltz        $t0, L_800E3B90
    if (SIGNED(ctx->r8) < 0) {
        // 0x800E3B84: nop
    
            goto L_800E3B90;
    }
    // 0x800E3B84: nop

    // 0x800E3B88: b           L_800E3BDC
    // 0x800E3B8C: addiu       $t0, $sp, 0x20
    ctx->r8 = ADD32(ctx->r29, 0X20);
        goto L_800E3BDC;
    // 0x800E3B8C: addiu       $t0, $sp, 0x20
    ctx->r8 = ADD32(ctx->r29, 0X20);
L_800E3B90:
    // 0x800E3B90: bltzl       $t8, L_800E3BDC
    if (SIGNED(ctx->r24) < 0) {
        // 0x800E3B94: addiu       $t0, $sp, 0x20
        ctx->r8 = ADD32(ctx->r29, 0X20);
            goto L_800E3BDC;
    }
    goto skip_0;
    // 0x800E3B94: addiu       $t0, $sp, 0x20
    ctx->r8 = ADD32(ctx->r29, 0X20);
    skip_0:
    // 0x800E3B98: bgtz        $t8, L_800E3BA8
    if (SIGNED(ctx->r24) > 0) {
        // 0x800E3B9C: addiu       $t3, $t1, 0x1
        ctx->r11 = ADD32(ctx->r9, 0X1);
            goto L_800E3BA8;
    }
    // 0x800E3B9C: addiu       $t3, $t1, 0x1
    ctx->r11 = ADD32(ctx->r9, 0X1);
    // 0x800E3BA0: beql        $t9, $zero, L_800E3BDC
    if (ctx->r25 == 0) {
        // 0x800E3BA4: addiu       $t0, $sp, 0x20
        ctx->r8 = ADD32(ctx->r29, 0X20);
            goto L_800E3BDC;
    }
    goto skip_1;
    // 0x800E3BA4: addiu       $t0, $sp, 0x20
    ctx->r8 = ADD32(ctx->r29, 0X20);
    skip_1:
L_800E3BA8:
    // 0x800E3BA8: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x800E3BAC: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x800E3BB0: sltiu       $at, $t3, 0x1
    ctx->r1 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x800E3BB4: addu        $t2, $t0, $at
    ctx->r10 = ADD32(ctx->r8, ctx->r1);
    // 0x800E3BB8: subu        $t6, $t8, $t4
    ctx->r14 = SUB32(ctx->r24, ctx->r12);
    // 0x800E3BBC: sltu        $at, $t9, $t5
    ctx->r1 = ctx->r25 < ctx->r13 ? 1 : 0;
    // 0x800E3BC0: subu        $t6, $t6, $at
    ctx->r14 = SUB32(ctx->r14, ctx->r1);
    // 0x800E3BC4: subu        $t7, $t9, $t5
    ctx->r15 = SUB32(ctx->r25, ctx->r13);
    // 0x800E3BC8: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x800E3BCC: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x800E3BD0: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x800E3BD4: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
L_800E3BD8:
    // 0x800E3BD8: addiu       $t0, $sp, 0x20
    ctx->r8 = ADD32(ctx->r29, 0X20);
L_800E3BDC:
    // 0x800E3BDC: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x800E3BE0: lw          $at, 0x0($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X0);
    // 0x800E3BE4: sw          $at, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r1;
    // 0x800E3BE8: lw          $t3, 0x4($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X4);
    // 0x800E3BEC: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x800E3BF0: lw          $at, 0x8($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X8);
    // 0x800E3BF4: sw          $at, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r1;
    // 0x800E3BF8: lw          $t3, 0xC($t0)
    ctx->r11 = MEM_W(ctx->r8, 0XC);
    // 0x800E3BFC: sw          $t3, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r11;
    // 0x800E3C00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E3C04: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800E3C08: jr          $ra
    // 0x800E3C0C: nop

    return;
    // 0x800E3C0C: nop

;}
RECOMP_FUNC void ldiv_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E3C10: div         $zero, $a1, $a2
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r6)));
    // 0x800E3C14: mflo        $v0
    ctx->r2 = lo;
    // 0x800E3C18: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800E3C1C: bne         $a2, $zero, L_800E3C28
    if (ctx->r6 != 0) {
        // 0x800E3C20: nop
    
            goto L_800E3C28;
    }
    // 0x800E3C20: nop

    // 0x800E3C24: break       7
    do_break(2148416548);
L_800E3C28:
    // 0x800E3C28: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800E3C2C: bne         $a2, $at, L_800E3C40
    if (ctx->r6 != ctx->r1) {
        // 0x800E3C30: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800E3C40;
    }
    // 0x800E3C30: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800E3C34: bne         $a1, $at, L_800E3C40
    if (ctx->r5 != ctx->r1) {
        // 0x800E3C38: nop
    
            goto L_800E3C40;
    }
    // 0x800E3C38: nop

    // 0x800E3C3C: break       6
    do_break(2148416572);
L_800E3C40:
    // 0x800E3C40: multu       $a2, $v0
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800E3C44: sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
    // 0x800E3C48: addiu       $t7, $sp, 0x0
    ctx->r15 = ADD32(ctx->r29, 0X0);
    // 0x800E3C4C: mflo        $t6
    ctx->r14 = lo;
    // 0x800E3C50: subu        $v1, $a1, $t6
    ctx->r3 = SUB32(ctx->r5, ctx->r14);
    // 0x800E3C54: bgez        $v0, L_800E3C78
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800E3C58: sw          $v1, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r3;
            goto L_800E3C78;
    }
    // 0x800E3C58: sw          $v1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r3;
    // 0x800E3C5C: sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
    // 0x800E3C60: blez        $v1, L_800E3C78
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800E3C64: sw          $v1, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r3;
            goto L_800E3C78;
    }
    // 0x800E3C64: sw          $v1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r3;
    // 0x800E3C68: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800E3C6C: subu        $v1, $v1, $a2
    ctx->r3 = SUB32(ctx->r3, ctx->r6);
    // 0x800E3C70: sw          $v1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r3;
    // 0x800E3C74: sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
L_800E3C78:
    // 0x800E3C78: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x800E3C7C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800E3C80: sw          $at, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r1;
    // 0x800E3C84: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x800E3C88: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x800E3C8C: jr          $ra
    // 0x800E3C90: sw          $t0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r8;
    return;
    // 0x800E3C90: sw          $t0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r8;
    // 0x800E3C94: nop

    // 0x800E3C98: nop

    // 0x800E3C9C: nop

;}
RECOMP_FUNC void __osSumcalc_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E3CA0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800E3CA4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800E3CA8: blez        $a1, L_800E3D04
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800E3CAC: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_800E3D04;
    }
    // 0x800E3CAC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800E3CB0: andi        $a3, $a1, 0x3
    ctx->r7 = ctx->r5 & 0X3;
    // 0x800E3CB4: beq         $a3, $zero, L_800E3CD8
    if (ctx->r7 == 0) {
        // 0x800E3CB8: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_800E3CD8;
    }
    // 0x800E3CB8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
L_800E3CBC:
    // 0x800E3CBC: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x800E3CC0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800E3CC4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800E3CC8: bne         $a0, $a2, L_800E3CBC
    if (ctx->r4 != ctx->r6) {
        // 0x800E3CCC: addu        $v1, $v1, $t6
        ctx->r3 = ADD32(ctx->r3, ctx->r14);
            goto L_800E3CBC;
    }
    // 0x800E3CCC: addu        $v1, $v1, $t6
    ctx->r3 = ADD32(ctx->r3, ctx->r14);
    // 0x800E3CD0: beql        $a2, $a1, L_800E3D08
    if (ctx->r6 == ctx->r5) {
        // 0x800E3CD4: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800E3D08;
    }
    goto skip_0;
    // 0x800E3CD4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_0:
L_800E3CD8:
    // 0x800E3CD8: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x800E3CDC: lbu         $t8, 0x1($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1);
    // 0x800E3CE0: lbu         $t9, 0x2($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X2);
    // 0x800E3CE4: addu        $v1, $v1, $t7
    ctx->r3 = ADD32(ctx->r3, ctx->r15);
    // 0x800E3CE8: lbu         $t0, 0x3($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X3);
    // 0x800E3CEC: addu        $v1, $v1, $t8
    ctx->r3 = ADD32(ctx->r3, ctx->r24);
    // 0x800E3CF0: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x800E3CF4: addu        $v1, $v1, $t9
    ctx->r3 = ADD32(ctx->r3, ctx->r25);
    // 0x800E3CF8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800E3CFC: bne         $a2, $a1, L_800E3CD8
    if (ctx->r6 != ctx->r5) {
        // 0x800E3D00: addu        $v1, $v1, $t0
        ctx->r3 = ADD32(ctx->r3, ctx->r8);
            goto L_800E3CD8;
    }
    // 0x800E3D00: addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
L_800E3D04:
    // 0x800E3D04: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800E3D08:
    // 0x800E3D08: andi        $t1, $v0, 0xFFFF
    ctx->r9 = ctx->r2 & 0XFFFF;
    // 0x800E3D0C: jr          $ra
    // 0x800E3D10: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    return;
    // 0x800E3D10: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
;}
RECOMP_FUNC void __osIdCheckSum_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E3D14: sh          $zero, 0x0($a2)
    MEM_H(0X0, ctx->r6) = 0;
    // 0x800E3D18: sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
    // 0x800E3D1C: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x800E3D20: addiu       $a3, $a0, 0x4
    ctx->r7 = ADD32(ctx->r4, 0X4);
    // 0x800E3D24: addiu       $t1, $a3, 0x2
    ctx->r9 = ADD32(ctx->r7, 0X2);
    // 0x800E3D28: addu        $t8, $zero, $v0
    ctx->r24 = ADD32(0, ctx->r2);
    // 0x800E3D2C: sh          $t8, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r24;
    // 0x800E3D30: lhu         $t9, 0x0($a2)
    ctx->r25 = MEM_HU(ctx->r6, 0X0);
    // 0x800E3D34: nor         $t5, $v0, $zero
    ctx->r13 = ~(ctx->r2 | 0);
    // 0x800E3D38: addiu       $t2, $a3, 0x4
    ctx->r10 = ADD32(ctx->r7, 0X4);
    // 0x800E3D3C: addu        $t6, $t9, $t5
    ctx->r14 = ADD32(ctx->r25, ctx->r13);
    // 0x800E3D40: sh          $t6, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r14;
    // 0x800E3D44: lhu         $t7, 0x0($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X0);
    // 0x800E3D48: lhu         $v0, 0x2($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X2);
    // 0x800E3D4C: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    // 0x800E3D50: addiu       $t3, $a3, 0x6
    ctx->r11 = ADD32(ctx->r7, 0X6);
    // 0x800E3D54: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800E3D58: sh          $t8, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r24;
    // 0x800E3D5C: lhu         $t9, 0x0($a2)
    ctx->r25 = MEM_HU(ctx->r6, 0X0);
    // 0x800E3D60: nor         $t5, $v0, $zero
    ctx->r13 = ~(ctx->r2 | 0);
    // 0x800E3D64: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // 0x800E3D68: addu        $t6, $t9, $t5
    ctx->r14 = ADD32(ctx->r25, ctx->r13);
    // 0x800E3D6C: sh          $t6, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r14;
L_800E3D70:
    // 0x800E3D70: lhu         $v0, 0x0($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X0);
    // 0x800E3D74: lhu         $t7, 0x0($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X0);
    // 0x800E3D78: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800E3D7C: nor         $t5, $v0, $zero
    ctx->r13 = ~(ctx->r2 | 0);
    // 0x800E3D80: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800E3D84: sh          $t8, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r24;
    // 0x800E3D88: lhu         $t9, 0x0($a2)
    ctx->r25 = MEM_HU(ctx->r6, 0X0);
    // 0x800E3D8C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x800E3D90: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800E3D94: addu        $t6, $t9, $t5
    ctx->r14 = ADD32(ctx->r25, ctx->r13);
    // 0x800E3D98: sh          $t6, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r14;
    // 0x800E3D9C: lhu         $t7, 0x0($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X0);
    // 0x800E3DA0: lhu         $v0, -0x8($t1)
    ctx->r2 = MEM_HU(ctx->r9, -0X8);
    // 0x800E3DA4: addiu       $t2, $t2, 0x8
    ctx->r10 = ADD32(ctx->r10, 0X8);
    // 0x800E3DA8: addiu       $t3, $t3, 0x8
    ctx->r11 = ADD32(ctx->r11, 0X8);
    // 0x800E3DAC: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800E3DB0: sh          $t8, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r24;
    // 0x800E3DB4: lhu         $t9, 0x0($a2)
    ctx->r25 = MEM_HU(ctx->r6, 0X0);
    // 0x800E3DB8: nor         $t5, $v0, $zero
    ctx->r13 = ~(ctx->r2 | 0);
    // 0x800E3DBC: addu        $t6, $t9, $t5
    ctx->r14 = ADD32(ctx->r25, ctx->r13);
    // 0x800E3DC0: sh          $t6, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r14;
    // 0x800E3DC4: lhu         $t7, 0x0($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X0);
    // 0x800E3DC8: lhu         $v0, -0x8($t2)
    ctx->r2 = MEM_HU(ctx->r10, -0X8);
    // 0x800E3DCC: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800E3DD0: sh          $t8, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r24;
    // 0x800E3DD4: lhu         $t9, 0x0($a2)
    ctx->r25 = MEM_HU(ctx->r6, 0X0);
    // 0x800E3DD8: nor         $t5, $v0, $zero
    ctx->r13 = ~(ctx->r2 | 0);
    // 0x800E3DDC: addu        $t6, $t9, $t5
    ctx->r14 = ADD32(ctx->r25, ctx->r13);
    // 0x800E3DE0: sh          $t6, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r14;
    // 0x800E3DE4: lhu         $t7, 0x0($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X0);
    // 0x800E3DE8: lhu         $v0, -0x8($t3)
    ctx->r2 = MEM_HU(ctx->r11, -0X8);
    // 0x800E3DEC: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800E3DF0: sh          $t8, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r24;
    // 0x800E3DF4: lhu         $t9, 0x0($a2)
    ctx->r25 = MEM_HU(ctx->r6, 0X0);
    // 0x800E3DF8: nor         $t5, $v0, $zero
    ctx->r13 = ~(ctx->r2 | 0);
    // 0x800E3DFC: addu        $t6, $t9, $t5
    ctx->r14 = ADD32(ctx->r25, ctx->r13);
    // 0x800E3E00: bne         $v1, $a0, L_800E3D70
    if (ctx->r3 != ctx->r4) {
        // 0x800E3E04: sh          $t6, 0x0($a2)
        MEM_H(0X0, ctx->r6) = ctx->r14;
            goto L_800E3D70;
    }
    // 0x800E3E04: sh          $t6, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r14;
    // 0x800E3E08: jr          $ra
    // 0x800E3E0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800E3E0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void _bcmp_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E4820: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    // 0x800E4824: bne         $at, $zero, L_800E4904
    if (ctx->r1 != 0) {
        // 0x800E4828: xor         $v0, $a0, $a1
        ctx->r2 = ctx->r4 ^ ctx->r5;
            goto L_800E4904;
    }
    // 0x800E4828: xor         $v0, $a0, $a1
    ctx->r2 = ctx->r4 ^ ctx->r5;
    // 0x800E482C: andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // 0x800E4830: bne         $v0, $zero, L_800E4898
    if (ctx->r2 != 0) {
        // 0x800E4834: negu        $t8, $a0
        ctx->r24 = SUB32(0, ctx->r4);
            goto L_800E4898;
    }
    // 0x800E4834: negu        $t8, $a0
    ctx->r24 = SUB32(0, ctx->r4);
    // 0x800E4838: andi        $t8, $t8, 0x3
    ctx->r24 = ctx->r24 & 0X3;
    // 0x800E483C: beq         $t8, $zero, L_800E485C
    if (ctx->r24 == 0) {
        // 0x800E4840: subu        $a2, $a2, $t8
        ctx->r6 = SUB32(ctx->r6, ctx->r24);
            goto L_800E485C;
    }
    // 0x800E4840: subu        $a2, $a2, $t8
    ctx->r6 = SUB32(ctx->r6, ctx->r24);
    // 0x800E4844: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800E4848: lwl         $v0, 0x0($a0)
    ctx->r2 = do_lwl(rdram, ctx->r2, ctx->r4, 0X0);
    // 0x800E484C: lwl         $v1, 0x0($a1)
    ctx->r3 = do_lwl(rdram, ctx->r3, ctx->r5, 0X0);
    // 0x800E4850: addu        $a0, $a0, $t8
    ctx->r4 = ADD32(ctx->r4, ctx->r24);
    // 0x800E4854: addu        $a1, $a1, $t8
    ctx->r5 = ADD32(ctx->r5, ctx->r24);
    // 0x800E4858: bne         $v0, $v1, L_800E4934
    if (ctx->r2 != ctx->r3) {
        // 0x800E485C: addiu       $at, $zero, -0x4
        ctx->r1 = ADD32(0, -0X4);
            goto L_800E4934;
    }
L_800E485C:
    // 0x800E485C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800E4860: and         $a3, $a2, $at
    ctx->r7 = ctx->r6 & ctx->r1;
    // 0x800E4864: beq         $a3, $zero, L_800E4904
    if (ctx->r7 == 0) {
        // 0x800E4868: subu        $a2, $a2, $a3
        ctx->r6 = SUB32(ctx->r6, ctx->r7);
            goto L_800E4904;
    }
    // 0x800E4868: subu        $a2, $a2, $a3
    ctx->r6 = SUB32(ctx->r6, ctx->r7);
    // 0x800E486C: addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
    // 0x800E4870: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
L_800E4874:
    // 0x800E4874: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x800E4878: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800E487C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800E4880: bne         $v0, $v1, L_800E4934
    if (ctx->r2 != ctx->r3) {
        // 0x800E4884: nop
    
            goto L_800E4934;
    }
    // 0x800E4884: nop

    // 0x800E4888: bnel        $a0, $a3, L_800E4874
    if (ctx->r4 != ctx->r7) {
        // 0x800E488C: lw          $v0, 0x0($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X0);
            goto L_800E4874;
    }
    goto skip_0;
    // 0x800E488C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    skip_0:
    // 0x800E4890: b           L_800E4904
    // 0x800E4894: nop

        goto L_800E4904;
    // 0x800E4894: nop

L_800E4898:
    // 0x800E4898: negu        $a3, $a1
    ctx->r7 = SUB32(0, ctx->r5);
    // 0x800E489C: andi        $a3, $a3, 0x3
    ctx->r7 = ctx->r7 & 0X3;
    // 0x800E48A0: beq         $a3, $zero, L_800E48CC
    if (ctx->r7 == 0) {
        // 0x800E48A4: subu        $a2, $a2, $a3
        ctx->r6 = SUB32(ctx->r6, ctx->r7);
            goto L_800E48CC;
    }
    // 0x800E48A4: subu        $a2, $a2, $a3
    ctx->r6 = SUB32(ctx->r6, ctx->r7);
    // 0x800E48A8: addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
    // 0x800E48AC: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
L_800E48B0:
    // 0x800E48B0: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x800E48B4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800E48B8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800E48BC: bne         $v0, $v1, L_800E4934
    if (ctx->r2 != ctx->r3) {
        // 0x800E48C0: nop
    
            goto L_800E4934;
    }
    // 0x800E48C0: nop

    // 0x800E48C4: bnel        $a0, $a3, L_800E48B0
    if (ctx->r4 != ctx->r7) {
        // 0x800E48C8: lbu         $v0, 0x0($a0)
        ctx->r2 = MEM_BU(ctx->r4, 0X0);
            goto L_800E48B0;
    }
    goto skip_1;
    // 0x800E48C8: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    skip_1:
L_800E48CC:
    // 0x800E48CC: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800E48D0: and         $a3, $a2, $at
    ctx->r7 = ctx->r6 & ctx->r1;
    // 0x800E48D4: beq         $a3, $zero, L_800E4904
    if (ctx->r7 == 0) {
        // 0x800E48D8: subu        $a2, $a2, $a3
        ctx->r6 = SUB32(ctx->r6, ctx->r7);
            goto L_800E4904;
    }
    // 0x800E48D8: subu        $a2, $a2, $a3
    ctx->r6 = SUB32(ctx->r6, ctx->r7);
    // 0x800E48DC: addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
    // 0x800E48E0: lwl         $v0, 0x0($a0)
    ctx->r2 = do_lwl(rdram, ctx->r2, ctx->r4, 0X0);
L_800E48E4:
    // 0x800E48E4: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x800E48E8: lwr         $v0, 0x3($a0)
    ctx->r2 = do_lwr(rdram, ctx->r2, ctx->r4, 0X3);
    // 0x800E48EC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800E48F0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800E48F4: bne         $v0, $v1, L_800E4934
    if (ctx->r2 != ctx->r3) {
        // 0x800E48F8: nop
    
            goto L_800E4934;
    }
    // 0x800E48F8: nop

    // 0x800E48FC: bnel        $a0, $a3, L_800E48E4
    if (ctx->r4 != ctx->r7) {
        // 0x800E4900: lwl         $v0, 0x0($a0)
        ctx->r2 = do_lwl(rdram, ctx->r2, ctx->r4, 0X0);
            goto L_800E48E4;
    }
    goto skip_2;
    // 0x800E4900: lwl         $v0, 0x0($a0)
    ctx->r2 = do_lwl(rdram, ctx->r2, ctx->r4, 0X0);
    skip_2:
L_800E4904:
    // 0x800E4904: blez        $a2, L_800E492C
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800E4908: addu        $a3, $a2, $a0
        ctx->r7 = ADD32(ctx->r6, ctx->r4);
            goto L_800E492C;
    }
    // 0x800E4908: addu        $a3, $a2, $a0
    ctx->r7 = ADD32(ctx->r6, ctx->r4);
    // 0x800E490C: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
L_800E4910:
    // 0x800E4910: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x800E4914: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800E4918: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800E491C: bne         $v0, $v1, L_800E4934
    if (ctx->r2 != ctx->r3) {
        // 0x800E4920: nop
    
            goto L_800E4934;
    }
    // 0x800E4920: nop

    // 0x800E4924: bnel        $a0, $a3, L_800E4910
    if (ctx->r4 != ctx->r7) {
        // 0x800E4928: lbu         $v0, 0x0($a0)
        ctx->r2 = MEM_BU(ctx->r4, 0X0);
            goto L_800E4910;
    }
    goto skip_3;
    // 0x800E4928: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    skip_3:
L_800E492C:
    // 0x800E492C: jr          $ra
    // 0x800E4930: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800E4930: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800E4934:
    // 0x800E4934: jr          $ra
    // 0x800E4938: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800E4938: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800E493C: nop

;}
RECOMP_FUNC void func_800E4940(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E4940: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800E4944: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800E4948: swc1        $f12, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f12.u32l;
    // 0x800E494C: c.eq.s      $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl == ctx->f16.fl;
    // 0x800E4950: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E4954: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800E4958: bc1fl       L_800E497C
    if (!c1cs) {
        // 0x800E495C: c.eq.s      $f14, $f16
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl == ctx->f16.fl;
            goto L_800E497C;
    }
    goto skip_0;
    // 0x800E495C: c.eq.s      $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl == ctx->f16.fl;
    skip_0:
    // 0x800E4960: c.eq.s      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.fl == ctx->f16.fl;
    // 0x800E4964: nop

    // 0x800E4968: bc1fl       L_800E497C
    if (!c1cs) {
        // 0x800E496C: c.eq.s      $f14, $f16
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl == ctx->f16.fl;
            goto L_800E497C;
    }
    goto skip_1;
    // 0x800E496C: c.eq.s      $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl == ctx->f16.fl;
    skip_1:
    // 0x800E4970: b           L_800E4BC4
    // 0x800E4974: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
        goto L_800E4BC4;
    // 0x800E4974: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
    // 0x800E4978: c.eq.s      $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl == ctx->f16.fl;
L_800E497C:
    // 0x800E497C: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800E4980: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800E4984: bc1fl       L_800E49B4
    if (!c1cs) {
        // 0x800E4988: div.s       $f12, $f8, $f14
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = DIV_S(ctx->f8.fl, ctx->f14.fl);
            goto L_800E49B4;
    }
    goto skip_2;
    // 0x800E4988: div.s       $f12, $f8, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = DIV_S(ctx->f8.fl, ctx->f14.fl);
    skip_2:
    // 0x800E498C: c.lt.s      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.fl < ctx->f6.fl;
    // 0x800E4990: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800E4994: bc1f        L_800E49A8
    if (!c1cs) {
        // 0x800E4998: nop
    
            goto L_800E49A8;
    }
    // 0x800E4998: nop

    // 0x800E499C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800E49A0: b           L_800E4BC4
    // 0x800E49A4: lwc1        $f0, -0x1C30($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X1C30);
        goto L_800E4BC4;
    // 0x800E49A4: lwc1        $f0, -0x1C30($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X1C30);
L_800E49A8:
    // 0x800E49A8: b           L_800E4BC4
    // 0x800E49AC: lwc1        $f0, -0x1C2C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X1C2C);
        goto L_800E4BC4;
    // 0x800E49AC: lwc1        $f0, -0x1C2C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X1C2C);
    // 0x800E49B0: div.s       $f12, $f8, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = DIV_S(ctx->f8.fl, ctx->f14.fl);
L_800E49B4:
    // 0x800E49B4: swc1        $f14, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f14.u32l;
    // 0x800E49B8: jal         0x800E4D20
    // 0x800E49BC: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    fabsf_recomp(rdram, ctx);
        goto after_0;
    // 0x800E49BC: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x800E49C0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800E49C4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800E49C8: addiu       $t6, $zero, 0xC4
    ctx->r14 = ADD32(0, 0XC4);
    // 0x800E49CC: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x800E49D0: c.le.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl <= ctx->f14.fl;
    // 0x800E49D4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800E49D8: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800E49DC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800E49E0: bc1f        L_800E49F0
    if (!c1cs) {
        // 0x800E49E4: cvt.s.w     $f18, $f10
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
            goto L_800E49F0;
    }
    // 0x800E49E4: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800E49E8: b           L_800E49F4
    // 0x800E49EC: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
        goto L_800E49F4;
    // 0x800E49EC: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
L_800E49F0:
    // 0x800E49F0: div.s       $f2, $f14, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = DIV_S(ctx->f14.fl, ctx->f12.fl);
L_800E49F4:
    // 0x800E49F4: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x800E49F8: addiu       $t7, $zero, 0x1D
    ctx->r15 = ADD32(0, 0X1D);
    // 0x800E49FC: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800E4A00: addiu       $t8, $zero, 0xA9
    ctx->r24 = ADD32(0, 0XA9);
    // 0x800E4A04: addiu       $t9, $zero, 0x1B
    ctx->r25 = ADD32(0, 0X1B);
    // 0x800E4A08: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x800E4A0C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800E4A10: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800E4A14: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800E4A18: addiu       $a2, $zero, 0x19
    ctx->r6 = ADD32(0, 0X19);
    // 0x800E4A1C: addiu       $a3, $zero, 0x17
    ctx->r7 = ADD32(0, 0X17);
    // 0x800E4A20: addiu       $t0, $zero, 0x15
    ctx->r8 = ADD32(0, 0X15);
    // 0x800E4A24: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800E4A28: addiu       $t1, $zero, 0x13
    ctx->r9 = ADD32(0, 0X13);
    // 0x800E4A2C: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800E4A30: div.s       $f0, $f6, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f18.fl);
    // 0x800E4A34: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x800E4A38: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800E4A3C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800E4A40: mul.s       $f6, $f10, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800E4A44: add.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800E4A48: div.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
L_800E4A4C:
    // 0x800E4A4C: multu       $v0, $v0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800E4A50: mtc1        $a2, $f8
    ctx->f8.u32l = ctx->r6;
    // 0x800E4A54: addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
    // 0x800E4A58: addiu       $a0, $v0, -0x2
    ctx->r4 = ADD32(ctx->r2, -0X2);
    // 0x800E4A5C: addiu       $a1, $v0, -0x3
    ctx->r5 = ADD32(ctx->r2, -0X3);
    // 0x800E4A60: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x800E4A64: addiu       $a2, $a2, -0x8
    ctx->r6 = ADD32(ctx->r6, -0X8);
    // 0x800E4A68: mflo        $t2
    ctx->r10 = lo;
    // 0x800E4A6C: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x800E4A70: nop

    // 0x800E4A74: multu       $v1, $v1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800E4A78: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800E4A7C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800E4A80: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x800E4A84: mflo        $t3
    ctx->r11 = lo;
    // 0x800E4A88: add.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x800E4A8C: nop

    // 0x800E4A90: multu       $a0, $a0
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800E4A94: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800E4A98: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x800E4A9C: nop

    // 0x800E4AA0: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800E4AA4: mflo        $t4
    ctx->r12 = lo;
    // 0x800E4AA8: div.s       $f0, $f6, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f18.fl);
    // 0x800E4AAC: mtc1        $a3, $f18
    ctx->f18.u32l = ctx->r7;
    // 0x800E4AB0: multu       $a1, $a1
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800E4AB4: addiu       $a3, $a3, -0x8
    ctx->r7 = ADD32(ctx->r7, -0X8);
    // 0x800E4AB8: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800E4ABC: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800E4AC0: mflo        $t5
    ctx->r13 = lo;
    // 0x800E4AC4: mul.s       $f6, $f10, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800E4AC8: add.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800E4ACC: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x800E4AD0: nop

    // 0x800E4AD4: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800E4AD8: div.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800E4ADC: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x800E4AE0: addiu       $t0, $t0, -0x8
    ctx->r8 = ADD32(ctx->r8, -0X8);
    // 0x800E4AE4: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x800E4AE8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800E4AEC: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800E4AF0: add.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x800E4AF4: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x800E4AF8: nop

    // 0x800E4AFC: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800E4B00: div.s       $f0, $f6, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f18.fl);
    // 0x800E4B04: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x800E4B08: addiu       $t1, $t1, -0x8
    ctx->r9 = ADD32(ctx->r9, -0X8);
    // 0x800E4B0C: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800E4B10: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800E4B14: mul.s       $f6, $f10, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800E4B18: add.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800E4B1C: bne         $v0, $zero, L_800E4A4C
    if (ctx->r2 != 0) {
        // 0x800E4B20: div.s       $f0, $f6, $f8
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
            goto L_800E4A4C;
    }
    // 0x800E4B20: div.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800E4B24: c.lt.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl < ctx->f12.fl;
    // 0x800E4B28: add.s       $f10, $f14, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f14.fl + ctx->f0.fl;
    // 0x800E4B2C: bc1f        L_800E4B44
    if (!c1cs) {
        // 0x800E4B30: div.s       $f2, $f2, $f10
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f10.fl);
            goto L_800E4B44;
    }
    // 0x800E4B30: div.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f10.fl);
    // 0x800E4B34: ldc1        $f18, -0x1C28($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X1C28);
    // 0x800E4B38: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x800E4B3C: sub.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f18.d - ctx->f4.d;
    // 0x800E4B40: cvt.s.d     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f2.fl = CVT_S_D(ctx->f6.d);
L_800E4B44:
    // 0x800E4B44: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x800E4B48: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800E4B4C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800E4B50: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800E4B54: c.lt.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl < ctx->f8.fl;
    // 0x800E4B58: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800E4B5C: bc1fl       L_800E4B78
    if (!c1cs) {
        // 0x800E4B60: c.lt.s      $f16, $f6
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.fl < ctx->f6.fl;
            goto L_800E4B78;
    }
    goto skip_3;
    // 0x800E4B60: c.lt.s      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.fl < ctx->f6.fl;
    skip_3:
    // 0x800E4B64: ldc1        $f10, -0x1C20($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X1C20);
    // 0x800E4B68: cvt.d.s     $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f18.d = CVT_D_S(ctx->f2.fl);
    // 0x800E4B6C: sub.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f10.d - ctx->f18.d;
    // 0x800E4B70: cvt.s.d     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f2.fl = CVT_S_D(ctx->f4.d);
    // 0x800E4B74: c.lt.s      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.fl < ctx->f6.fl;
L_800E4B78:
    // 0x800E4B78: nop

    // 0x800E4B7C: bc1fl       L_800E4B90
    if (!c1cs) {
        // 0x800E4B80: c.lt.s      $f16, $f8
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.fl < ctx->f8.fl;
            goto L_800E4B90;
    }
    goto skip_4;
    // 0x800E4B80: c.lt.s      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.fl < ctx->f8.fl;
    skip_4:
    // 0x800E4B84: b           L_800E4BC4
    // 0x800E4B88: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_800E4BC4;
    // 0x800E4B88: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x800E4B8C: c.lt.s      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.fl < ctx->f8.fl;
L_800E4B90:
    // 0x800E4B90: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800E4B94: bc1f        L_800E4BB4
    if (!c1cs) {
        // 0x800E4B98: nop
    
            goto L_800E4BB4;
    }
    // 0x800E4B98: nop

    // 0x800E4B9C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800E4BA0: ldc1        $f18, -0x1C18($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X1C18);
    // 0x800E4BA4: cvt.d.s     $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.d = CVT_D_S(ctx->f2.fl);
    // 0x800E4BA8: add.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f10.d + ctx->f18.d;
    // 0x800E4BAC: b           L_800E4BC4
    // 0x800E4BB0: cvt.s.d     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f0.fl = CVT_S_D(ctx->f4.d);
        goto L_800E4BC4;
    // 0x800E4BB0: cvt.s.d     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f0.fl = CVT_S_D(ctx->f4.d);
L_800E4BB4:
    // 0x800E4BB4: ldc1        $f8, -0x1C10($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X1C10);
    // 0x800E4BB8: cvt.d.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.d = CVT_D_S(ctx->f2.fl);
    // 0x800E4BBC: sub.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d - ctx->f8.d;
    // 0x800E4BC0: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
L_800E4BC4:
    // 0x800E4BC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E4BC8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800E4BCC: jr          $ra
    // 0x800E4BD0: nop

    return;
    // 0x800E4BD0: nop

    // 0x800E4BD4: nop

    // 0x800E4BD8: nop

    // 0x800E4BDC: nop

;}
RECOMP_FUNC void func_800E4BE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E4BE0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800E4BE4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800E4BE8: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x800E4BEC: jal         0x800E4D20
    // 0x800E4BF0: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
    fabsf_recomp(rdram, ctx);
        goto after_0;
    // 0x800E4BF0: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
    after_0:
    // 0x800E4BF4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800E4BF8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800E4BFC: nop

    // 0x800E4C00: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800E4C04: nop

    // 0x800E4C08: bc1f        L_800E4C1C
    if (!c1cs) {
        // 0x800E4C0C: nop
    
            goto L_800E4C1C;
    }
    // 0x800E4C0C: nop

    // 0x800E4C10: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800E4C14: b           L_800E4C80
    // 0x800E4C18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800E4C80;
    // 0x800E4C18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800E4C1C:
    // 0x800E4C1C: mul.s       $f4, $f20, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x800E4C20: jal         0x800D68E0
    // 0x800E4C24: sub.s       $f12, $f2, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x800E4C24: sub.s       $f12, $f2, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f4.fl;
    after_1:
    // 0x800E4C28: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800E4C2C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x800E4C30: c.eq.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl == ctx->f12.fl;
    // 0x800E4C34: nop

    // 0x800E4C38: bc1tl       L_800E4C64
    if (c1cs) {
        // 0x800E4C3C: c.lt.s      $f12, $f20
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f12.fl < ctx->f20.fl;
            goto L_800E4C64;
    }
    goto skip_0;
    // 0x800E4C3C: c.lt.s      $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f12.fl < ctx->f20.fl;
    skip_0:
    // 0x800E4C40: cvt.d.s     $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f12.d = CVT_D_S(ctx->f20.fl);
    // 0x800E4C44: jal         0x800E4F60
    // 0x800E4C48: cvt.d.s     $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.d = CVT_D_S(ctx->f0.fl);
    func_800E4F60(rdram, ctx);
        goto after_2;
    // 0x800E4C48: cvt.d.s     $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.d = CVT_D_S(ctx->f0.fl);
    after_2:
    // 0x800E4C4C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800E4C50: ldc1        $f6, -0x1C00($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X1C00);
    // 0x800E4C54: sub.d       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = ctx->f6.d - ctx->f0.d;
    // 0x800E4C58: b           L_800E4C7C
    // 0x800E4C5C: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
        goto L_800E4C7C;
    // 0x800E4C5C: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
    // 0x800E4C60: c.lt.s      $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f12.fl < ctx->f20.fl;
L_800E4C64:
    // 0x800E4C64: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800E4C68: bc1f        L_800E4C78
    if (!c1cs) {
        // 0x800E4C6C: nop
    
            goto L_800E4C78;
    }
    // 0x800E4C6C: nop

    // 0x800E4C70: b           L_800E4C7C
    // 0x800E4C74: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
        goto L_800E4C7C;
    // 0x800E4C74: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_800E4C78:
    // 0x800E4C78: lwc1        $f0, -0x1BF8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X1BF8);
L_800E4C7C:
    // 0x800E4C7C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800E4C80:
    // 0x800E4C80: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x800E4C84: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800E4C88: jr          $ra
    // 0x800E4C8C: nop

    return;
    // 0x800E4C8C: nop

;}
RECOMP_FUNC void func_800E4C90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E4C90: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x800E4C94: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800E4C98: beql        $v0, $zero, L_800E4CBC
    if (ctx->r2 == 0) {
        // 0x800E4C9C: sb          $zero, 0x0($v1)
        MEM_B(0X0, ctx->r3) = 0;
            goto L_800E4CBC;
    }
    goto skip_0;
    // 0x800E4C9C: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    skip_0:
    // 0x800E4CA0: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
L_800E4CA4:
    // 0x800E4CA4: lbu         $v0, 0x1($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X1);
    // 0x800E4CA8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800E4CAC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800E4CB0: bnel        $v0, $zero, L_800E4CA4
    if (ctx->r2 != 0) {
        // 0x800E4CB4: sb          $v0, 0x0($v1)
        MEM_B(0X0, ctx->r3) = ctx->r2;
            goto L_800E4CA4;
    }
    goto skip_1;
    // 0x800E4CB4: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    skip_1:
    // 0x800E4CB8: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
L_800E4CBC:
    // 0x800E4CBC: jr          $ra
    // 0x800E4CC0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x800E4CC0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800E4CC4: nop

    // 0x800E4CC8: nop

    // 0x800E4CCC: nop

;}
RECOMP_FUNC void osViExtendVStart_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E4CD0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800E4CD4: jr          $ra
    // 0x800E4CD8: sw          $a0, -0x5420($at)
    MEM_W(-0X5420, ctx->r1) = ctx->r4;
    return;
    // 0x800E4CD8: sw          $a0, -0x5420($at)
    MEM_W(-0X5420, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void func_800E4CDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E4CDC: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800E4CE0: addiu       $v1, $v1, -0x5420
    ctx->r3 = ADD32(ctx->r3, -0X5420);
    // 0x800E4CE4: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800E4CE8: addiu       $at, $zero, 0x4E6D
    ctx->r1 = ADD32(0, 0X4E6D);
    // 0x800E4CEC: multu       $t6, $at
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r1)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800E4CF0: mflo        $t7
    ctx->r15 = lo;
    // 0x800E4CF4: addiu       $t9, $t7, 0x3039
    ctx->r25 = ADD32(ctx->r15, 0X3039);
    // 0x800E4CF8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800E4CFC: srl         $v0, $t9, 16
    ctx->r2 = S32(U32(ctx->r25) >> 16);
    // 0x800E4D00: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800E4D04: jr          $ra
    // 0x800E4D08: andi        $v0, $v0, 0x7FFF
    ctx->r2 = ctx->r2 & 0X7FFF;
    return;
    // 0x800E4D08: andi        $v0, $v0, 0x7FFF
    ctx->r2 = ctx->r2 & 0X7FFF;
    // 0x800E4D0C: nop

;}
RECOMP_FUNC void fabs_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E4D10: jr          $ra
    // 0x800E4D14: abs.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.d); 
    ctx->f0.d = fabs(ctx->f12.d);
    return;
    // 0x800E4D14: abs.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.d); 
    ctx->f0.d = fabs(ctx->f12.d);
    // 0x800E4D18: nop

    // 0x800E4D1C: nop

;}
RECOMP_FUNC void fabsf_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E4D20: jr          $ra
    // 0x800E4D24: abs.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = fabsf(ctx->f12.fl);
    return;
    // 0x800E4D24: abs.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = fabsf(ctx->f12.fl);
    // 0x800E4D28: nop

    // 0x800E4D2C: nop

;}
RECOMP_FUNC void func_800E4D30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E4D30: bgez        $a0, L_800E4D40
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800E4D34: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_800E4D40;
    }
    // 0x800E4D34: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800E4D38: jr          $ra
    // 0x800E4D3C: negu        $v0, $a0
    ctx->r2 = SUB32(0, ctx->r4);
    return;
    // 0x800E4D3C: negu        $v0, $a0
    ctx->r2 = SUB32(0, ctx->r4);
L_800E4D40:
    // 0x800E4D40: jr          $ra
    // 0x800E4D44: nop

    return;
    // 0x800E4D44: nop

    // 0x800E4D48: nop

    // 0x800E4D4C: nop

;}
RECOMP_FUNC void func_800E4D50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E4D50: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800E4D54: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800E4D58: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x800E4D5C: jal         0x800E4D20
    // 0x800E4D60: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
    fabsf_recomp(rdram, ctx);
        goto after_0;
    // 0x800E4D60: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
    after_0:
    // 0x800E4D64: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800E4D68: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800E4D6C: nop

    // 0x800E4D70: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800E4D74: nop

    // 0x800E4D78: bc1f        L_800E4D8C
    if (!c1cs) {
        // 0x800E4D7C: nop
    
            goto L_800E4D8C;
    }
    // 0x800E4D7C: nop

    // 0x800E4D80: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800E4D84: b           L_800E4DE0
    // 0x800E4D88: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_800E4DE0;
    // 0x800E4D88: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_800E4D8C:
    // 0x800E4D8C: mul.s       $f4, $f20, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x800E4D90: jal         0x800D68E0
    // 0x800E4D94: sub.s       $f12, $f2, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x800E4D94: sub.s       $f12, $f2, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f4.fl;
    after_1:
    // 0x800E4D98: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800E4D9C: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x800E4DA0: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x800E4DA4: nop

    // 0x800E4DA8: bc1tl       L_800E4DC4
    if (c1cs) {
        // 0x800E4DAC: c.lt.s      $f2, $f20
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl < ctx->f20.fl;
            goto L_800E4DC4;
    }
    goto skip_0;
    // 0x800E4DAC: c.lt.s      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl < ctx->f20.fl;
    skip_0:
    // 0x800E4DB0: jal         0x800E4940
    // 0x800E4DB4: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_800E4940(rdram, ctx);
        goto after_2;
    // 0x800E4DB4: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_2:
    // 0x800E4DB8: b           L_800E4DE4
    // 0x800E4DBC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800E4DE4;
    // 0x800E4DBC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800E4DC0: c.lt.s      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl < ctx->f20.fl;
L_800E4DC4:
    // 0x800E4DC4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800E4DC8: bc1f        L_800E4DDC
    if (!c1cs) {
        // 0x800E4DCC: nop
    
            goto L_800E4DDC;
    }
    // 0x800E4DCC: nop

    // 0x800E4DD0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800E4DD4: b           L_800E4DE0
    // 0x800E4DD8: lwc1        $f0, -0x1BF0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X1BF0);
        goto L_800E4DE0;
    // 0x800E4DD8: lwc1        $f0, -0x1BF0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X1BF0);
L_800E4DDC:
    // 0x800E4DDC: lwc1        $f0, -0x1BEC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X1BEC);
L_800E4DE0:
    // 0x800E4DE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800E4DE4:
    // 0x800E4DE4: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x800E4DE8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800E4DEC: jr          $ra
    // 0x800E4DF0: nop

    return;
    // 0x800E4DF0: nop

    // 0x800E4DF4: nop

    // 0x800E4DF8: nop

    // 0x800E4DFC: nop

;}
RECOMP_FUNC void func_800E4E00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E4E00: trunc.w.s   $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    ctx->f4.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x800E4E04: cvt.d.s     $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f10.d = CVT_D_S(ctx->f12.fl);
    // 0x800E4E08: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x800E4E0C: nop

    // 0x800E4E10: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x800E4E14: nop

    // 0x800E4E18: cvt.d.w     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.d = CVT_D_W(ctx->f6.u32l);
    // 0x800E4E1C: cvt.s.d     $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); 
    ctx->f8.fl = CVT_S_D(ctx->f2.d);
    // 0x800E4E20: sub.d       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f2.d); 
    ctx->f16.d = ctx->f10.d - ctx->f2.d;
    // 0x800E4E24: swc1        $f8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
    // 0x800E4E28: jr          $ra
    // 0x800E4E2C: cvt.s.d     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f0.fl = CVT_S_D(ctx->f16.d);
    return;
    // 0x800E4E2C: cvt.s.d     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f0.fl = CVT_S_D(ctx->f16.d);
;}
RECOMP_FUNC void func_800E4E30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E4E30: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800E4E34: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800E4E38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E4E3C: c.le.s      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.fl <= ctx->f12.fl;
    // 0x800E4E40: lui         $at, 0xBFE0
    ctx->r1 = S32(0XBFE0 << 16);
    // 0x800E4E44: bc1fl       L_800E4E64
    if (!c1cs) {
        // 0x800E4E48: mtc1        $at, $f3
        ctx->f_odd[(3 - 1) * 2] = ctx->r1;
            goto L_800E4E64;
    }
    goto skip_0;
    // 0x800E4E48: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    skip_0:
    // 0x800E4E4C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800E4E50: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x800E4E54: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800E4E58: b           L_800E4E6C
    // 0x800E4E5C: nop

        goto L_800E4E6C;
    // 0x800E4E5C: nop

    // 0x800E4E60: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
L_800E4E64:
    // 0x800E4E64: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800E4E68: nop

L_800E4E6C:
    // 0x800E4E6C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800E4E70: ldc1        $f14, -0x1BE0($at)
    CHECK_FR(ctx, 14);
    ctx->f14.u64 = LD(ctx->r1, -0X1BE0);
    // 0x800E4E74: cvt.d.s     $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.d = CVT_D_S(ctx->f12.fl);
    // 0x800E4E78: div.d       $f4, $f0, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f14.d); 
    ctx->f4.d = DIV_D(ctx->f0.d, ctx->f14.d);
    // 0x800E4E7C: add.d       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f2.d + ctx->f4.d;
    // 0x800E4E80: trunc.w.d   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_D(ctx->f6.d);
    // 0x800E4E84: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x800E4E88: nop

    // 0x800E4E8C: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800E4E90: nop

    // 0x800E4E94: cvt.d.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.d = CVT_D_W(ctx->f10.u32l);
    // 0x800E4E98: mul.d       $f4, $f18, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f14.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f14.d);
    // 0x800E4E9C: sub.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f0.d - ctx->f4.d;
    // 0x800E4EA0: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    // 0x800E4EA4: c.eq.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl == ctx->f16.fl;
    // 0x800E4EA8: nop

    // 0x800E4EAC: bc1f        L_800E4EBC
    if (!c1cs) {
        // 0x800E4EB0: nop
    
            goto L_800E4EBC;
    }
    // 0x800E4EB0: nop

    // 0x800E4EB4: b           L_800E4EF8
    // 0x800E4EB8: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
        goto L_800E4EF8;
    // 0x800E4EB8: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
L_800E4EBC:
    // 0x800E4EBC: jal         0x800D68F0
    // 0x800E4EC0: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    sinf_recomp(rdram, ctx);
        goto after_0;
    // 0x800E4EC0: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x800E4EC4: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800E4EC8: jal         0x800D6AB0
    // 0x800E4ECC: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    __cosf_recomp(rdram, ctx);
        goto after_1;
    // 0x800E4ECC: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x800E4ED0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800E4ED4: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x800E4ED8: lwc1        $f8, 0x18($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800E4EDC: c.eq.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl == ctx->f16.fl;
    // 0x800E4EE0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800E4EE4: bc1t        L_800E4EF4
    if (c1cs) {
        // 0x800E4EE8: nop
    
            goto L_800E4EF4;
    }
    // 0x800E4EE8: nop

    // 0x800E4EEC: b           L_800E4EF8
    // 0x800E4EF0: div.s       $f0, $f8, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
        goto L_800E4EF8;
    // 0x800E4EF0: div.s       $f0, $f8, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
L_800E4EF4:
    // 0x800E4EF4: lwc1        $f0, -0x1BD8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X1BD8);
L_800E4EF8:
    // 0x800E4EF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E4EFC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800E4F00: jr          $ra
    // 0x800E4F04: nop

    return;
    // 0x800E4F04: nop

    // 0x800E4F08: nop

    // 0x800E4F0C: nop

;}
RECOMP_FUNC void func_800E4F10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E4F10: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x800E4F14: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800E4F18: beql        $t6, $zero, L_800E4F34
    if (ctx->r14 == 0) {
        // 0x800E4F1C: lbu         $v0, 0x0($a1)
        ctx->r2 = MEM_BU(ctx->r5, 0X0);
            goto L_800E4F34;
    }
    goto skip_0;
    // 0x800E4F1C: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    skip_0:
    // 0x800E4F20: lbu         $t7, 0x1($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X1);
L_800E4F24:
    // 0x800E4F24: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800E4F28: bnel        $t7, $zero, L_800E4F24
    if (ctx->r15 != 0) {
        // 0x800E4F2C: lbu         $t7, 0x1($v1)
        ctx->r15 = MEM_BU(ctx->r3, 0X1);
            goto L_800E4F24;
    }
    goto skip_1;
    // 0x800E4F2C: lbu         $t7, 0x1($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X1);
    skip_1:
    // 0x800E4F30: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
L_800E4F34:
    // 0x800E4F34: beql        $v0, $zero, L_800E4F58
    if (ctx->r2 == 0) {
        // 0x800E4F38: sb          $zero, 0x0($v1)
        MEM_B(0X0, ctx->r3) = 0;
            goto L_800E4F58;
    }
    goto skip_2;
    // 0x800E4F38: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    skip_2:
    // 0x800E4F3C: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
L_800E4F40:
    // 0x800E4F40: lbu         $v0, 0x1($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X1);
    // 0x800E4F44: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800E4F48: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800E4F4C: bnel        $v0, $zero, L_800E4F40
    if (ctx->r2 != 0) {
        // 0x800E4F50: sb          $v0, 0x0($v1)
        MEM_B(0X0, ctx->r3) = ctx->r2;
            goto L_800E4F40;
    }
    goto skip_3;
    // 0x800E4F50: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    skip_3:
    // 0x800E4F54: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
L_800E4F58:
    // 0x800E4F58: jr          $ra
    // 0x800E4F5C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x800E4F5C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
;}
RECOMP_FUNC void func_800E4F60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E4F60: mtc1        $zero, $f17
    ctx->f_odd[(17 - 1) * 2] = 0;
    // 0x800E4F64: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800E4F68: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800E4F6C: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x800E4F70: c.eq.d      $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.d == ctx->f16.d;
    // 0x800E4F74: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x800E4F78: mov.d       $f20, $f14
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    ctx->f20.d = ctx->f14.d;
    // 0x800E4F7C: mov.d       $f22, $f12
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    ctx->f22.d = ctx->f12.d;
    // 0x800E4F80: bc1f        L_800E4FA8
    if (!c1cs) {
        // 0x800E4F84: sw          $ra, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r31;
            goto L_800E4FA8;
    }
    // 0x800E4F84: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800E4F88: c.eq.d      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.d == ctx->f16.d;
    // 0x800E4F8C: nop

    // 0x800E4F90: bc1fl       L_800E4FAC
    if (!c1cs) {
        // 0x800E4F94: c.eq.d      $f20, $f16
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f20.d == ctx->f16.d;
            goto L_800E4FAC;
    }
    goto skip_0;
    // 0x800E4F94: c.eq.d      $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f20.d == ctx->f16.d;
    skip_0:
    // 0x800E4F98: mtc1        $zero, $f1
    ctx->f_odd[(1 - 1) * 2] = 0;
    // 0x800E4F9C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800E4FA0: b           L_800E51D4
    // 0x800E4FA4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800E51D4;
    // 0x800E4FA4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800E4FA8:
    // 0x800E4FA8: c.eq.d      $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f20.d == ctx->f16.d;
L_800E4FAC:
    // 0x800E4FAC: nop

    // 0x800E4FB0: bc1fl       L_800E4FE0
    if (!c1cs) {
        // 0x800E4FB4: div.d       $f12, $f22, $f20
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.d); NAN_CHECK(ctx->f20.d); 
    ctx->f12.d = DIV_D(ctx->f22.d, ctx->f20.d);
            goto L_800E4FE0;
    }
    goto skip_1;
    // 0x800E4FB4: div.d       $f12, $f22, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.d); NAN_CHECK(ctx->f20.d); 
    ctx->f12.d = DIV_D(ctx->f22.d, ctx->f20.d);
    skip_1:
    // 0x800E4FB8: c.lt.d      $f16, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f16.d < ctx->f22.d;
    // 0x800E4FBC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800E4FC0: bc1f        L_800E4FD4
    if (!c1cs) {
        // 0x800E4FC4: nop
    
            goto L_800E4FD4;
    }
    // 0x800E4FC4: nop

    // 0x800E4FC8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800E4FCC: b           L_800E51D0
    // 0x800E4FD0: ldc1        $f0, -0x1BD0($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X1BD0);
        goto L_800E51D0;
    // 0x800E4FD0: ldc1        $f0, -0x1BD0($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X1BD0);
L_800E4FD4:
    // 0x800E4FD4: b           L_800E51D0
    // 0x800E4FD8: ldc1        $f0, -0x1BC8($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X1BC8);
        goto L_800E51D0;
    // 0x800E4FD8: ldc1        $f0, -0x1BC8($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X1BC8);
    // 0x800E4FDC: div.d       $f12, $f22, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.d); NAN_CHECK(ctx->f20.d); 
    ctx->f12.d = DIV_D(ctx->f22.d, ctx->f20.d);
L_800E4FE0:
    // 0x800E4FE0: jal         0x800E4D10
    // 0x800E4FE4: sdc1        $f12, 0x28($sp)
    CHECK_FR(ctx, 12);
    SD(ctx->f12.u64, 0X28, ctx->r29);
    fabs_recomp(rdram, ctx);
        goto after_0;
    // 0x800E4FE4: sdc1        $f12, 0x28($sp)
    CHECK_FR(ctx, 12);
    SD(ctx->f12.u64, 0X28, ctx->r29);
    after_0:
    // 0x800E4FE8: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800E4FEC: mtc1        $at, $f15
    ctx->f_odd[(15 - 1) * 2] = ctx->r1;
    // 0x800E4FF0: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800E4FF4: addiu       $t6, $zero, 0xC4
    ctx->r14 = ADD32(0, 0XC4);
    // 0x800E4FF8: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800E4FFC: c.le.d      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.d <= ctx->f14.d;
    // 0x800E5000: mtc1        $zero, $f17
    ctx->f_odd[(17 - 1) * 2] = 0;
    // 0x800E5004: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800E5008: ldc1        $f12, 0x28($sp)
    CHECK_FR(ctx, 12);
    ctx->f12.u64 = LD(ctx->r29, 0X28);
    // 0x800E500C: bc1f        L_800E501C
    if (!c1cs) {
        // 0x800E5010: cvt.d.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
            goto L_800E501C;
    }
    // 0x800E5010: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x800E5014: b           L_800E5020
    // 0x800E5018: mov.d       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.d = ctx->f12.d;
        goto L_800E5020;
    // 0x800E5018: mov.d       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.d = ctx->f12.d;
L_800E501C:
    // 0x800E501C: div.d       $f2, $f14, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f12.d); 
    ctx->f2.d = DIV_D(ctx->f14.d, ctx->f12.d);
L_800E5020:
    // 0x800E5020: mul.d       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f2.d);
    // 0x800E5024: addiu       $t7, $zero, 0x1D
    ctx->r15 = ADD32(0, 0X1D);
    // 0x800E5028: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x800E502C: addiu       $t8, $zero, 0xA9
    ctx->r24 = ADD32(0, 0XA9);
    // 0x800E5030: addiu       $t9, $zero, 0x1B
    ctx->r25 = ADD32(0, 0X1B);
    // 0x800E5034: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x800E5038: addiu       $a2, $zero, 0x19
    ctx->r6 = ADD32(0, 0X19);
    // 0x800E503C: cvt.d.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.d = CVT_D_W(ctx->f18.u32l);
    // 0x800E5040: mul.d       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f2.d);
    // 0x800E5044: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x800E5048: addiu       $a3, $zero, 0x17
    ctx->r7 = ADD32(0, 0X17);
    // 0x800E504C: addiu       $t0, $zero, 0x15
    ctx->r8 = ADD32(0, 0X15);
    // 0x800E5050: addiu       $t1, $zero, 0x13
    ctx->r9 = ADD32(0, 0X13);
    // 0x800E5054: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800E5058: add.d       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = ctx->f4.d + ctx->f16.d;
    // 0x800E505C: cvt.d.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.d = CVT_D_W(ctx->f8.u32l);
    // 0x800E5060: div.d       $f0, $f10, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f0.d = DIV_D(ctx->f10.d, ctx->f6.d);
    // 0x800E5064: mul.d       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f2.d);
    // 0x800E5068: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x800E506C: nop

    // 0x800E5070: cvt.d.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.d = CVT_D_W(ctx->f6.u32l);
    // 0x800E5074: mul.d       $f10, $f4, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f2.d);
    // 0x800E5078: add.d       $f18, $f8, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = ctx->f8.d + ctx->f0.d;
    // 0x800E507C: div.d       $f0, $f10, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f0.d = DIV_D(ctx->f10.d, ctx->f18.d);
L_800E5080:
    // 0x800E5080: multu       $v0, $v0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800E5084: mtc1        $a2, $f18
    ctx->f18.u32l = ctx->r6;
    // 0x800E5088: addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
    // 0x800E508C: addiu       $a0, $v0, -0x2
    ctx->r4 = ADD32(ctx->r2, -0X2);
    // 0x800E5090: addiu       $a1, $v0, -0x3
    ctx->r5 = ADD32(ctx->r2, -0X3);
    // 0x800E5094: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x800E5098: addiu       $a2, $a2, -0x8
    ctx->r6 = ADD32(ctx->r6, -0X8);
    // 0x800E509C: mflo        $t2
    ctx->r10 = lo;
    // 0x800E50A0: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x800E50A4: nop

    // 0x800E50A8: multu       $v1, $v1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800E50AC: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x800E50B0: cvt.d.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.d = CVT_D_W(ctx->f18.u32l);
    // 0x800E50B4: mul.d       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f2.d);
    // 0x800E50B8: mflo        $t3
    ctx->r11 = lo;
    // 0x800E50BC: add.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = ctx->f4.d + ctx->f0.d;
    // 0x800E50C0: nop

    // 0x800E50C4: multu       $a0, $a0
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800E50C8: mul.d       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f2.d);
    // 0x800E50CC: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x800E50D0: nop

    // 0x800E50D4: cvt.d.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.d = CVT_D_W(ctx->f8.u32l);
    // 0x800E50D8: mflo        $t4
    ctx->r12 = lo;
    // 0x800E50DC: div.d       $f0, $f10, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f0.d = DIV_D(ctx->f10.d, ctx->f6.d);
    // 0x800E50E0: mul.d       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f2.d);
    // 0x800E50E4: mtc1        $a3, $f6
    ctx->f6.u32l = ctx->r7;
    // 0x800E50E8: multu       $a1, $a1
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800E50EC: addiu       $a3, $a3, -0x8
    ctx->r7 = ADD32(ctx->r7, -0X8);
    // 0x800E50F0: cvt.d.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.d = CVT_D_W(ctx->f6.u32l);
    // 0x800E50F4: mul.d       $f10, $f4, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f2.d);
    // 0x800E50F8: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x800E50FC: mflo        $t5
    ctx->r13 = lo;
    // 0x800E5100: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x800E5104: add.d       $f18, $f8, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = ctx->f8.d + ctx->f0.d;
    // 0x800E5108: mul.d       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f2.d);
    // 0x800E510C: div.d       $f0, $f10, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f0.d = DIV_D(ctx->f10.d, ctx->f18.d);
    // 0x800E5110: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x800E5114: addiu       $t0, $t0, -0x8
    ctx->r8 = ADD32(ctx->r8, -0X8);
    // 0x800E5118: mul.d       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f2.d);
    // 0x800E511C: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x800E5120: cvt.d.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.d = CVT_D_W(ctx->f18.u32l);
    // 0x800E5124: cvt.d.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.d = CVT_D_W(ctx->f8.u32l);
    // 0x800E5128: add.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = ctx->f4.d + ctx->f0.d;
    // 0x800E512C: mul.d       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f2.d);
    // 0x800E5130: div.d       $f0, $f10, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f0.d = DIV_D(ctx->f10.d, ctx->f6.d);
    // 0x800E5134: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x800E5138: addiu       $t1, $t1, -0x8
    ctx->r9 = ADD32(ctx->r9, -0X8);
    // 0x800E513C: mul.d       $f10, $f4, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f2.d);
    // 0x800E5140: cvt.d.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.d = CVT_D_W(ctx->f6.u32l);
    // 0x800E5144: add.d       $f18, $f8, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = ctx->f8.d + ctx->f0.d;
    // 0x800E5148: bne         $v0, $zero, L_800E5080
    if (ctx->r2 != 0) {
        // 0x800E514C: div.d       $f0, $f10, $f18
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f0.d = DIV_D(ctx->f10.d, ctx->f18.d);
            goto L_800E5080;
    }
    // 0x800E514C: div.d       $f0, $f10, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f0.d = DIV_D(ctx->f10.d, ctx->f18.d);
    // 0x800E5150: c.lt.d      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.d < ctx->f12.d;
    // 0x800E5154: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800E5158: add.d       $f4, $f14, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f14.d + ctx->f0.d;
    // 0x800E515C: bc1f        L_800E516C
    if (!c1cs) {
        // 0x800E5160: div.d       $f2, $f2, $f4
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f2.d = DIV_D(ctx->f2.d, ctx->f4.d);
            goto L_800E516C;
    }
    // 0x800E5160: div.d       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f2.d = DIV_D(ctx->f2.d, ctx->f4.d);
    // 0x800E5164: ldc1        $f6, -0x1BC0($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X1BC0);
    // 0x800E5168: sub.d       $f2, $f6, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f2.d = ctx->f6.d - ctx->f2.d;
L_800E516C:
    // 0x800E516C: lui         $at, 0xBFF0
    ctx->r1 = S32(0XBFF0 << 16);
    // 0x800E5170: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800E5174: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800E5178: c.lt.d      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.d < ctx->f8.d;
    // 0x800E517C: nop

    // 0x800E5180: bc1fl       L_800E5194
    if (!c1cs) {
        // 0x800E5184: c.lt.d      $f16, $f20
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f16.d < ctx->f20.d;
            goto L_800E5194;
    }
    goto skip_2;
    // 0x800E5184: c.lt.d      $f16, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f16.d < ctx->f20.d;
    skip_2:
    // 0x800E5188: ldc1        $f10, -0x1BB8($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X1BB8);
    // 0x800E518C: sub.d       $f2, $f10, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f2.d); 
    ctx->f2.d = ctx->f10.d - ctx->f2.d;
    // 0x800E5190: c.lt.d      $f16, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f16.d < ctx->f20.d;
L_800E5194:
    // 0x800E5194: nop

    // 0x800E5198: bc1fl       L_800E51AC
    if (!c1cs) {
        // 0x800E519C: c.lt.d      $f16, $f22
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f16.d < ctx->f22.d;
            goto L_800E51AC;
    }
    goto skip_3;
    // 0x800E519C: c.lt.d      $f16, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f16.d < ctx->f22.d;
    skip_3:
    // 0x800E51A0: b           L_800E51D0
    // 0x800E51A4: mov.d       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
        goto L_800E51D0;
    // 0x800E51A4: mov.d       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
    // 0x800E51A8: c.lt.d      $f16, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f16.d < ctx->f22.d;
L_800E51AC:
    // 0x800E51AC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800E51B0: bc1f        L_800E51C8
    if (!c1cs) {
        // 0x800E51B4: nop
    
            goto L_800E51C8;
    }
    // 0x800E51B4: nop

    // 0x800E51B8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800E51BC: ldc1        $f18, -0x1BB0($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X1BB0);
    // 0x800E51C0: b           L_800E51D0
    // 0x800E51C4: add.d       $f0, $f2, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f18.d); 
    ctx->f0.d = ctx->f2.d + ctx->f18.d;
        goto L_800E51D0;
    // 0x800E51C4: add.d       $f0, $f2, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f18.d); 
    ctx->f0.d = ctx->f2.d + ctx->f18.d;
L_800E51C8:
    // 0x800E51C8: ldc1        $f4, -0x1BA8($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X1BA8);
    // 0x800E51CC: sub.d       $f0, $f2, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f0.d = ctx->f2.d - ctx->f4.d;
L_800E51D0:
    // 0x800E51D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800E51D4:
    // 0x800E51D4: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x800E51D8: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x800E51DC: jr          $ra
    // 0x800E51E0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800E51E0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x800E51E4: nop

    // 0x800E51E8: nop

    // 0x800E51EC: nop

;}
RECOMP_FUNC void func_8016D6F0_02FC30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016D6F0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016D6F4: lwc1        $f18, 0x3948($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X3948);
    // 0x8016D6F8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8016D6FC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8016D700: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8016D704: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8016D708: sub.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x8016D70C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8016D710: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8016D714: sub.s       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f18.fl;
    // 0x8016D718: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8016D71C: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x8016D720: addiu       $t8, $t8, 0x3918
    ctx->r24 = ADD32(ctx->r24, 0X3918);
    // 0x8016D724: mul.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8016D728: sub.s       $f16, $f18, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x8016D72C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8016D730: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8016D734: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8016D738: addiu       $t9, $t9, 0x3918
    ctx->r25 = ADD32(ctx->r25, 0X3918);
    // 0x8016D73C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8016D740: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8016D744: addiu       $t0, $t0, 0x3918
    ctx->r8 = ADD32(ctx->r8, 0X3918);
    // 0x8016D748: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8016D74C: addiu       $t1, $t1, 0x3918
    ctx->r9 = ADD32(ctx->r9, 0X3918);
    // 0x8016D750: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8016D754: addiu       $t2, $t2, 0x3918
    ctx->r10 = ADD32(ctx->r10, 0X3918);
    // 0x8016D758: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8016D75C: div.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f10.fl, ctx->f6.fl);
    // 0x8016D760: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8016D764: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8016D768: addiu       $t3, $t3, 0x3918
    ctx->r11 = ADD32(ctx->r11, 0X3918);
    // 0x8016D76C: add.s       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x8016D770: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8016D774: addiu       $t4, $t4, 0x3918
    ctx->r12 = ADD32(ctx->r12, 0X3918);
    // 0x8016D778: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8016D77C: mul.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x8016D780: addiu       $t5, $t5, 0x3918
    ctx->r13 = ADD32(ctx->r13, 0X3918);
    // 0x8016D784: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8016D788: addiu       $t6, $t6, 0x3918
    ctx->r14 = ADD32(ctx->r14, 0X3918);
    // 0x8016D78C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8016D790: addiu       $t7, $t7, 0x3918
    ctx->r15 = ADD32(ctx->r15, 0X3918);
    // 0x8016D794: mul.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8016D798: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x8016D79C: swc1        $f8, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f8.u32l;
    // 0x8016D7A0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8016D7A4: nop

    // 0x8016D7A8: div.s       $f10, $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8016D7AC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8016D7B0: nop

    // 0x8016D7B4: sub.s       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x8016D7B8: mul.s       $f8, $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x8016D7BC: nop

    // 0x8016D7C0: mul.s       $f8, $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8016D7C4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8016D7C8: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x8016D7CC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8016D7D0: div.s       $f8, $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = DIV_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8016D7D4: mul.s       $f16, $f6, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x8016D7D8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8016D7DC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016D7E0: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x8016D7E4: swc1        $f8, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->f8.u32l;
    // 0x8016D7E8: lwc1        $f4, 0x0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X0);
    // 0x8016D7EC: div.s       $f16, $f6, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = DIV_S(ctx->f6.fl, ctx->f18.fl);
    // 0x8016D7F0: swc1        $f16, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f16.u32l;
    // 0x8016D7F4: lwc1        $f6, 0x0($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X0);
    // 0x8016D7F8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8016D7FC: addiu       $t8, $t8, 0x3918
    ctx->r24 = ADD32(ctx->r24, 0X3918);
    // 0x8016D800: mul.s       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8016D804: lwc1        $f6, 0x4($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X4);
    // 0x8016D808: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8016D80C: addiu       $t9, $t9, 0x3918
    ctx->r25 = ADD32(ctx->r25, 0X3918);
    // 0x8016D810: mul.s       $f6, $f10, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x8016D814: add.s       $f18, $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8016D818: lwc1        $f6, 0x8($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X8);
    // 0x8016D81C: mul.s       $f6, $f8, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8016D820: add.s       $f18, $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8016D824: lwc1        $f6, 0xC($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0XC);
    // 0x8016D828: mul.s       $f6, $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x8016D82C: add.s       $f6, $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x8016D830: swc1        $f6, 0x394C($at)
    MEM_W(0X394C, ctx->r1) = ctx->f6.u32l;
    // 0x8016D834: lwc1        $f18, 0x10($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X10);
    // 0x8016D838: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016D83C: mul.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x8016D840: lwc1        $f18, 0x14($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X14);
    // 0x8016D844: mul.s       $f18, $f10, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8016D848: add.s       $f6, $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x8016D84C: lwc1        $f18, 0x18($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X18);
    // 0x8016D850: mul.s       $f18, $f8, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x8016D854: add.s       $f6, $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x8016D858: lwc1        $f18, 0x1C($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X1C);
    // 0x8016D85C: mul.s       $f18, $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x8016D860: add.s       $f18, $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8016D864: swc1        $f18, 0x3950($at)
    MEM_W(0X3950, ctx->r1) = ctx->f18.u32l;
    // 0x8016D868: lwc1        $f6, 0x20($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X20);
    // 0x8016D86C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016D870: mul.s       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8016D874: lwc1        $f4, 0x24($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X24);
    // 0x8016D878: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8016D87C: lwc1        $f4, 0x28($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X28);
    // 0x8016D880: add.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8016D884: mul.s       $f18, $f8, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8016D888: lwc1        $f8, 0x2C($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X2C);
    // 0x8016D88C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8016D890: mul.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8016D894: add.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8016D898: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8016D89C: jr          $ra
    // 0x8016D8A0: swc1        $f10, 0x3954($at)
    MEM_W(0X3954, ctx->r1) = ctx->f10.u32l;
    return;
    // 0x8016D8A0: swc1        $f10, 0x3954($at)
    MEM_W(0X3954, ctx->r1) = ctx->f10.u32l;
;}
RECOMP_FUNC void func_8016D8A4_02FC30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016D8A4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016D8A8: sw          $zero, -0x2C04($at)
    MEM_W(-0X2C04, ctx->r1) = 0;
    // 0x8016D8AC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016D8B0: sh          $zero, -0x2C08($at)
    MEM_H(-0X2C08, ctx->r1) = 0;
    // 0x8016D8B4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8016D8B8: lw          $t6, -0x2BB8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2BB8);
    // 0x8016D8BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8016D8C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016D8C4: lwc1        $f4, 0x4($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X4);
    // 0x8016D8C8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8016D8CC: addiu       $t7, $t7, -0x4198
    ctx->r15 = ADD32(ctx->r15, -0X4198);
    // 0x8016D8D0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8016D8D4: swc1        $f4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f4.u32l;
    // 0x8016D8D8: lw          $t8, -0x2BB8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2BB8);
    // 0x8016D8DC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8016D8E0: addiu       $t9, $t9, -0x4198
    ctx->r25 = ADD32(ctx->r25, -0X4198);
    // 0x8016D8E4: lwc1        $f6, 0x8($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X8);
    // 0x8016D8E8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8016D8EC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8016D8F0: swc1        $f6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f6.u32l;
    // 0x8016D8F4: lw          $t0, -0x2BB8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2BB8);
    // 0x8016D8F8: addiu       $t1, $t1, -0x4198
    ctx->r9 = ADD32(ctx->r9, -0X4198);
    // 0x8016D8FC: lwc1        $f8, 0xC($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0XC);
    // 0x8016D900: jal         0x8016E6AC
    // 0x8016D904: swc1        $f8, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f8.u32l;
    func_8016E6AC_02FC30(rdram, ctx);
        goto after_0;
    // 0x8016D904: swc1        $f8, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f8.u32l;
    after_0:
    // 0x8016D908: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8016D90C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016D910: sw          $t2, -0x2BEC($at)
    MEM_W(-0X2BEC, ctx->r1) = ctx->r10;
    // 0x8016D914: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016D918: sw          $zero, -0x2BE4($at)
    MEM_W(-0X2BE4, ctx->r1) = 0;
    // 0x8016D91C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8016D920: lw          $t3, -0x2BB0($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2BB0);
    // 0x8016D924: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016D928: lwc1        $f10, 0x4($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X4);
    // 0x8016D92C: swc1        $f10, -0x2BD0($at)
    MEM_W(-0X2BD0, ctx->r1) = ctx->f10.u32l;
    // 0x8016D930: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8016D934: lwc1        $f16, 0x2670($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X2670);
    // 0x8016D938: mul.s       $f12, $f16, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x8016D93C: jal         0x800D68F0
    // 0x8016D940: nop

    sinf_recomp(rdram, ctx);
        goto after_1;
    // 0x8016D940: nop

    after_1:
    // 0x8016D944: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8016D948: addiu       $t4, $t4, -0x4198
    ctx->r12 = ADD32(ctx->r12, -0X4198);
    // 0x8016D94C: swc1        $f0, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->f0.u32l;
    // 0x8016D950: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8016D954: lwc1        $f18, 0x2674($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X2674);
    // 0x8016D958: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016D95C: lwc1        $f4, -0x2BD0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2BD0);
    // 0x8016D960: mul.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8016D964: jal         0x800D6AB0
    // 0x8016D968: nop

    __cosf_recomp(rdram, ctx);
        goto after_2;
    // 0x8016D968: nop

    after_2:
    // 0x8016D96C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8016D970: addiu       $t5, $t5, -0x4198
    ctx->r13 = ADD32(ctx->r13, -0X4198);
    // 0x8016D974: jal         0x8016E71C
    // 0x8016D978: swc1        $f0, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = ctx->f0.u32l;
    func_8016E71C_02FC30(rdram, ctx);
        goto after_3;
    // 0x8016D978: swc1        $f0, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = ctx->f0.u32l;
    after_3:
    // 0x8016D97C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016D980: sw          $zero, -0x2BF8($at)
    MEM_W(-0X2BF8, ctx->r1) = 0;
    // 0x8016D984: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8016D988: lw          $t6, -0x2BB4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2BB4);
    // 0x8016D98C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8016D990: addiu       $t7, $t7, -0x4198
    ctx->r15 = ADD32(ctx->r15, -0X4198);
    // 0x8016D994: lwc1        $f6, 0x4($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X4);
    // 0x8016D998: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8016D99C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8016D9A0: swc1        $f6, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f6.u32l;
    // 0x8016D9A4: lw          $t8, -0x2BB4($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2BB4);
    // 0x8016D9A8: addiu       $t9, $t9, -0x4198
    ctx->r25 = ADD32(ctx->r25, -0X4198);
    // 0x8016D9AC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8016D9B0: lwc1        $f8, 0x8($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X8);
    // 0x8016D9B4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8016D9B8: addiu       $t1, $t1, -0x4198
    ctx->r9 = ADD32(ctx->r9, -0X4198);
    // 0x8016D9BC: swc1        $f8, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->f8.u32l;
    // 0x8016D9C0: lw          $t0, -0x2BB4($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2BB4);
    // 0x8016D9C4: lwc1        $f16, 0xC($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0XC);
    // 0x8016D9C8: jal         0x8016E7EC
    // 0x8016D9CC: swc1        $f16, 0x14($t1)
    MEM_W(0X14, ctx->r9) = ctx->f16.u32l;
    func_8016E7EC_02FC30(rdram, ctx);
        goto after_4;
    // 0x8016D9CC: swc1        $f16, 0x14($t1)
    MEM_W(0X14, ctx->r9) = ctx->f16.u32l;
    after_4:
    // 0x8016D9D0: jal         0x800C3FD0
    // 0x8016D9D4: nop

    func_800C3FD0(rdram, ctx);
        goto after_5;
    // 0x8016D9D4: nop

    after_5:
    // 0x8016D9D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016D9DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8016D9E0: jr          $ra
    // 0x8016D9E4: nop

    return;
    // 0x8016D9E4: nop

;}
RECOMP_FUNC void func_8016D9E8_02FC30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016D9E8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8016D9EC: lhu         $t6, -0x2C08($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X2C08);
    // 0x8016D9F0: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x8016D9F4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8016D9F8: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x8016D9FC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8016DA00: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8016DA04: beq         $t7, $at, L_8016DED0
    if (ctx->r15 == ctx->r1) {
        // 0x8016DA08: sdc1        $f20, 0x18($sp)
        CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
            goto L_8016DED0;
    }
    // 0x8016DA08: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8016DA0C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8016DA10: lw          $t9, -0x2C04($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2C04);
    // 0x8016DA14: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8016DA18: lw          $t8, -0x2BB8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2BB8);
    // 0x8016DA1C: sll         $t0, $t9, 4
    ctx->r8 = S32(ctx->r25 << 4);
    // 0x8016DA20: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8016DA24: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8016DA28: lwc1        $f4, 0x4($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X4);
    // 0x8016DA2C: addiu       $t2, $t2, 0x3918
    ctx->r10 = ADD32(ctx->r10, 0X3918);
    // 0x8016DA30: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8016DA34: swc1        $f4, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->f4.u32l;
    // 0x8016DA38: lw          $t4, -0x2C04($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2C04);
    // 0x8016DA3C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8016DA40: lw          $t3, -0x2BB8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2BB8);
    // 0x8016DA44: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x8016DA48: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8016DA4C: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x8016DA50: lwc1        $f6, 0x8($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X8);
    // 0x8016DA54: addiu       $t7, $t7, 0x3918
    ctx->r15 = ADD32(ctx->r15, 0X3918);
    // 0x8016DA58: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8016DA5C: swc1        $f6, 0x14($t7)
    MEM_W(0X14, ctx->r15) = ctx->f6.u32l;
    // 0x8016DA60: lw          $t8, -0x2C04($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2C04);
    // 0x8016DA64: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8016DA68: lw          $t9, -0x2BB8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2BB8);
    // 0x8016DA6C: sll         $t0, $t8, 4
    ctx->r8 = S32(ctx->r24 << 4);
    // 0x8016DA70: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8016DA74: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8016DA78: lwc1        $f8, 0xC($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0XC);
    // 0x8016DA7C: addiu       $t2, $t2, 0x3918
    ctx->r10 = ADD32(ctx->r10, 0X3918);
    // 0x8016DA80: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8016DA84: swc1        $f8, 0x24($t2)
    MEM_W(0X24, ctx->r10) = ctx->f8.u32l;
    // 0x8016DA88: lw          $t4, -0x2C04($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2C04);
    // 0x8016DA8C: bne         $t4, $zero, L_8016DB08
    if (ctx->r12 != 0) {
        // 0x8016DA90: nop
    
            goto L_8016DB08;
    }
    // 0x8016DA90: nop

    // 0x8016DA94: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8016DA98: lw          $t3, -0x2BB8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2BB8);
    // 0x8016DA9C: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x8016DAA0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8016DAA4: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x8016DAA8: lwc1        $f10, 0x4($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X4);
    // 0x8016DAAC: addiu       $t7, $t7, 0x3918
    ctx->r15 = ADD32(ctx->r15, 0X3918);
    // 0x8016DAB0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8016DAB4: swc1        $f10, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f10.u32l;
    // 0x8016DAB8: lw          $t9, -0x2C04($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2C04);
    // 0x8016DABC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8016DAC0: lw          $t8, -0x2BB8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2BB8);
    // 0x8016DAC4: sll         $t0, $t9, 4
    ctx->r8 = S32(ctx->r25 << 4);
    // 0x8016DAC8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8016DACC: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8016DAD0: lwc1        $f16, 0x8($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X8);
    // 0x8016DAD4: addiu       $t2, $t2, 0x3918
    ctx->r10 = ADD32(ctx->r10, 0X3918);
    // 0x8016DAD8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8016DADC: swc1        $f16, 0x10($t2)
    MEM_W(0X10, ctx->r10) = ctx->f16.u32l;
    // 0x8016DAE0: lw          $t3, -0x2C04($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2C04);
    // 0x8016DAE4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8016DAE8: lw          $t4, -0x2BB8($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2BB8);
    // 0x8016DAEC: sll         $t5, $t3, 4
    ctx->r13 = S32(ctx->r11 << 4);
    // 0x8016DAF0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8016DAF4: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x8016DAF8: lwc1        $f18, 0xC($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0XC);
    // 0x8016DAFC: addiu       $t7, $t7, 0x3918
    ctx->r15 = ADD32(ctx->r15, 0X3918);
    // 0x8016DB00: b           L_8016DB80
    // 0x8016DB04: swc1        $f18, 0x20($t7)
    MEM_W(0X20, ctx->r15) = ctx->f18.u32l;
        goto L_8016DB80;
    // 0x8016DB04: swc1        $f18, 0x20($t7)
    MEM_W(0X20, ctx->r15) = ctx->f18.u32l;
L_8016DB08:
    // 0x8016DB08: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8016DB0C: lw          $t8, -0x2C04($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2C04);
    // 0x8016DB10: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8016DB14: lw          $t9, -0x2BB8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2BB8);
    // 0x8016DB18: sll         $t0, $t8, 4
    ctx->r8 = S32(ctx->r24 << 4);
    // 0x8016DB1C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8016DB20: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8016DB24: lwc1        $f4, -0xC($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, -0XC);
    // 0x8016DB28: addiu       $t2, $t2, 0x3918
    ctx->r10 = ADD32(ctx->r10, 0X3918);
    // 0x8016DB2C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8016DB30: swc1        $f4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f4.u32l;
    // 0x8016DB34: lw          $t4, -0x2C04($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2C04);
    // 0x8016DB38: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8016DB3C: lw          $t3, -0x2BB8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2BB8);
    // 0x8016DB40: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x8016DB44: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8016DB48: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x8016DB4C: lwc1        $f6, -0x8($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, -0X8);
    // 0x8016DB50: addiu       $t7, $t7, 0x3918
    ctx->r15 = ADD32(ctx->r15, 0X3918);
    // 0x8016DB54: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8016DB58: swc1        $f6, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->f6.u32l;
    // 0x8016DB5C: lw          $t9, -0x2C04($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2C04);
    // 0x8016DB60: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8016DB64: lw          $t8, -0x2BB8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2BB8);
    // 0x8016DB68: sll         $t0, $t9, 4
    ctx->r8 = S32(ctx->r25 << 4);
    // 0x8016DB6C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8016DB70: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8016DB74: lwc1        $f8, -0x4($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, -0X4);
    // 0x8016DB78: addiu       $t2, $t2, 0x3918
    ctx->r10 = ADD32(ctx->r10, 0X3918);
    // 0x8016DB7C: swc1        $f8, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->f8.u32l;
L_8016DB80:
    // 0x8016DB80: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8016DB84: lw          $t3, -0x2C04($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2C04);
    // 0x8016DB88: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8016DB8C: lw          $t4, -0x2BB8($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2BB8);
    // 0x8016DB90: sll         $t5, $t3, 4
    ctx->r13 = S32(ctx->r11 << 4);
    // 0x8016DB94: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8016DB98: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x8016DB9C: lhu         $t7, 0x10($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X10);
    // 0x8016DBA0: bne         $t7, $at, L_8016DC84
    if (ctx->r15 != ctx->r1) {
        // 0x8016DBA4: nop
    
            goto L_8016DC84;
    }
    // 0x8016DBA4: nop

    // 0x8016DBA8: lwc1        $f10, 0x4($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X4);
    // 0x8016DBAC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8016DBB0: addiu       $t9, $t9, 0x3918
    ctx->r25 = ADD32(ctx->r25, 0X3918);
    // 0x8016DBB4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8016DBB8: swc1        $f10, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f10.u32l;
    // 0x8016DBBC: lw          $t0, -0x2C04($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2C04);
    // 0x8016DBC0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8016DBC4: lw          $t8, -0x2BB8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2BB8);
    // 0x8016DBC8: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x8016DBCC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8016DBD0: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x8016DBD4: lwc1        $f16, 0x8($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X8);
    // 0x8016DBD8: addiu       $t3, $t3, 0x3918
    ctx->r11 = ADD32(ctx->r11, 0X3918);
    // 0x8016DBDC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8016DBE0: swc1        $f16, 0x18($t3)
    MEM_W(0X18, ctx->r11) = ctx->f16.u32l;
    // 0x8016DBE4: lw          $t5, -0x2C04($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2C04);
    // 0x8016DBE8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8016DBEC: lw          $t4, -0x2BB8($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2BB8);
    // 0x8016DBF0: sll         $t7, $t5, 4
    ctx->r15 = S32(ctx->r13 << 4);
    // 0x8016DBF4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8016DBF8: addu        $t6, $t4, $t7
    ctx->r14 = ADD32(ctx->r12, ctx->r15);
    // 0x8016DBFC: lwc1        $f18, 0xC($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0XC);
    // 0x8016DC00: addiu       $t9, $t9, 0x3918
    ctx->r25 = ADD32(ctx->r25, 0X3918);
    // 0x8016DC04: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8016DC08: swc1        $f18, 0x28($t9)
    MEM_W(0X28, ctx->r25) = ctx->f18.u32l;
    // 0x8016DC0C: lw          $t8, -0x2C04($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2C04);
    // 0x8016DC10: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8016DC14: lw          $t0, -0x2BB8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2BB8);
    // 0x8016DC18: sll         $t1, $t8, 4
    ctx->r9 = S32(ctx->r24 << 4);
    // 0x8016DC1C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8016DC20: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8016DC24: lwc1        $f4, 0x4($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X4);
    // 0x8016DC28: addiu       $t3, $t3, 0x3918
    ctx->r11 = ADD32(ctx->r11, 0X3918);
    // 0x8016DC2C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8016DC30: swc1        $f4, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f4.u32l;
    // 0x8016DC34: lw          $t4, -0x2C04($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2C04);
    // 0x8016DC38: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8016DC3C: lw          $t5, -0x2BB8($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2BB8);
    // 0x8016DC40: sll         $t7, $t4, 4
    ctx->r15 = S32(ctx->r12 << 4);
    // 0x8016DC44: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8016DC48: addu        $t6, $t5, $t7
    ctx->r14 = ADD32(ctx->r13, ctx->r15);
    // 0x8016DC4C: lwc1        $f6, 0x8($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X8);
    // 0x8016DC50: addiu       $t9, $t9, 0x3918
    ctx->r25 = ADD32(ctx->r25, 0X3918);
    // 0x8016DC54: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8016DC58: swc1        $f6, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->f6.u32l;
    // 0x8016DC5C: lw          $t0, -0x2C04($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2C04);
    // 0x8016DC60: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8016DC64: lw          $t8, -0x2BB8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2BB8);
    // 0x8016DC68: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x8016DC6C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8016DC70: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x8016DC74: lwc1        $f8, 0xC($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0XC);
    // 0x8016DC78: addiu       $t3, $t3, 0x3918
    ctx->r11 = ADD32(ctx->r11, 0X3918);
    // 0x8016DC7C: b           L_8016DE00
    // 0x8016DC80: swc1        $f8, 0x2C($t3)
    MEM_W(0X2C, ctx->r11) = ctx->f8.u32l;
        goto L_8016DE00;
    // 0x8016DC80: swc1        $f8, 0x2C($t3)
    MEM_W(0X2C, ctx->r11) = ctx->f8.u32l;
L_8016DC84:
    // 0x8016DC84: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8016DC88: lw          $t5, -0x2C04($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2C04);
    // 0x8016DC8C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8016DC90: lw          $t4, -0x2BB8($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2BB8);
    // 0x8016DC94: sll         $t7, $t5, 4
    ctx->r15 = S32(ctx->r13 << 4);
    // 0x8016DC98: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8016DC9C: addu        $t6, $t4, $t7
    ctx->r14 = ADD32(ctx->r12, ctx->r15);
    // 0x8016DCA0: lwc1        $f10, 0x14($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X14);
    // 0x8016DCA4: addiu       $t9, $t9, 0x3918
    ctx->r25 = ADD32(ctx->r25, 0X3918);
    // 0x8016DCA8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8016DCAC: swc1        $f10, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f10.u32l;
    // 0x8016DCB0: lw          $t8, -0x2C04($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2C04);
    // 0x8016DCB4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8016DCB8: lw          $t0, -0x2BB8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2BB8);
    // 0x8016DCBC: sll         $t1, $t8, 4
    ctx->r9 = S32(ctx->r24 << 4);
    // 0x8016DCC0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8016DCC4: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8016DCC8: lwc1        $f16, 0x18($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X18);
    // 0x8016DCCC: addiu       $t3, $t3, 0x3918
    ctx->r11 = ADD32(ctx->r11, 0X3918);
    // 0x8016DCD0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8016DCD4: swc1        $f16, 0x18($t3)
    MEM_W(0X18, ctx->r11) = ctx->f16.u32l;
    // 0x8016DCD8: lw          $t4, -0x2C04($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2C04);
    // 0x8016DCDC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8016DCE0: lw          $t5, -0x2BB8($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2BB8);
    // 0x8016DCE4: sll         $t7, $t4, 4
    ctx->r15 = S32(ctx->r12 << 4);
    // 0x8016DCE8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8016DCEC: addu        $t6, $t5, $t7
    ctx->r14 = ADD32(ctx->r13, ctx->r15);
    // 0x8016DCF0: lwc1        $f18, 0x1C($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X1C);
    // 0x8016DCF4: addiu       $t9, $t9, 0x3918
    ctx->r25 = ADD32(ctx->r25, 0X3918);
    // 0x8016DCF8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8016DCFC: swc1        $f18, 0x28($t9)
    MEM_W(0X28, ctx->r25) = ctx->f18.u32l;
    // 0x8016DD00: lw          $t0, -0x2C04($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2C04);
    // 0x8016DD04: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8016DD08: lw          $t8, -0x2BB8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2BB8);
    // 0x8016DD0C: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x8016DD10: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8016DD14: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x8016DD18: lhu         $t3, 0x20($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X20);
    // 0x8016DD1C: bne         $t3, $at, L_8016DD88
    if (ctx->r11 != ctx->r1) {
        // 0x8016DD20: nop
    
            goto L_8016DD88;
    }
    // 0x8016DD20: nop

    // 0x8016DD24: lwc1        $f4, 0x14($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X14);
    // 0x8016DD28: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8016DD2C: addiu       $t4, $t4, 0x3918
    ctx->r12 = ADD32(ctx->r12, 0X3918);
    // 0x8016DD30: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8016DD34: swc1        $f4, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->f4.u32l;
    // 0x8016DD38: lw          $t7, -0x2C04($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2C04);
    // 0x8016DD3C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8016DD40: lw          $t5, -0x2BB8($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2BB8);
    // 0x8016DD44: sll         $t6, $t7, 4
    ctx->r14 = S32(ctx->r15 << 4);
    // 0x8016DD48: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8016DD4C: addu        $t9, $t5, $t6
    ctx->r25 = ADD32(ctx->r13, ctx->r14);
    // 0x8016DD50: lwc1        $f6, 0x18($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X18);
    // 0x8016DD54: addiu       $t0, $t0, 0x3918
    ctx->r8 = ADD32(ctx->r8, 0X3918);
    // 0x8016DD58: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8016DD5C: swc1        $f6, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->f6.u32l;
    // 0x8016DD60: lw          $t1, -0x2C04($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2C04);
    // 0x8016DD64: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8016DD68: lw          $t8, -0x2BB8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2BB8);
    // 0x8016DD6C: sll         $t3, $t1, 4
    ctx->r11 = S32(ctx->r9 << 4);
    // 0x8016DD70: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8016DD74: addu        $t2, $t8, $t3
    ctx->r10 = ADD32(ctx->r24, ctx->r11);
    // 0x8016DD78: lwc1        $f8, 0x1C($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X1C);
    // 0x8016DD7C: addiu       $t4, $t4, 0x3918
    ctx->r12 = ADD32(ctx->r12, 0X3918);
    // 0x8016DD80: b           L_8016DE00
    // 0x8016DD84: swc1        $f8, 0x2C($t4)
    MEM_W(0X2C, ctx->r12) = ctx->f8.u32l;
        goto L_8016DE00;
    // 0x8016DD84: swc1        $f8, 0x2C($t4)
    MEM_W(0X2C, ctx->r12) = ctx->f8.u32l;
L_8016DD88:
    // 0x8016DD88: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8016DD8C: lw          $t5, -0x2C04($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2C04);
    // 0x8016DD90: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8016DD94: lw          $t7, -0x2BB8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2BB8);
    // 0x8016DD98: sll         $t6, $t5, 4
    ctx->r14 = S32(ctx->r13 << 4);
    // 0x8016DD9C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8016DDA0: addu        $t9, $t7, $t6
    ctx->r25 = ADD32(ctx->r15, ctx->r14);
    // 0x8016DDA4: lwc1        $f10, 0x24($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X24);
    // 0x8016DDA8: addiu       $t0, $t0, 0x3918
    ctx->r8 = ADD32(ctx->r8, 0X3918);
    // 0x8016DDAC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8016DDB0: swc1        $f10, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->f10.u32l;
    // 0x8016DDB4: lw          $t8, -0x2C04($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2C04);
    // 0x8016DDB8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8016DDBC: lw          $t1, -0x2BB8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2BB8);
    // 0x8016DDC0: sll         $t3, $t8, 4
    ctx->r11 = S32(ctx->r24 << 4);
    // 0x8016DDC4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8016DDC8: addu        $t2, $t1, $t3
    ctx->r10 = ADD32(ctx->r9, ctx->r11);
    // 0x8016DDCC: lwc1        $f16, 0x28($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X28);
    // 0x8016DDD0: addiu       $t4, $t4, 0x3918
    ctx->r12 = ADD32(ctx->r12, 0X3918);
    // 0x8016DDD4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8016DDD8: swc1        $f16, 0x1C($t4)
    MEM_W(0X1C, ctx->r12) = ctx->f16.u32l;
    // 0x8016DDDC: lw          $t7, -0x2C04($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2C04);
    // 0x8016DDE0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8016DDE4: lw          $t5, -0x2BB8($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2BB8);
    // 0x8016DDE8: sll         $t6, $t7, 4
    ctx->r14 = S32(ctx->r15 << 4);
    // 0x8016DDEC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8016DDF0: addu        $t9, $t5, $t6
    ctx->r25 = ADD32(ctx->r13, ctx->r14);
    // 0x8016DDF4: lwc1        $f18, 0x2C($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X2C);
    // 0x8016DDF8: addiu       $t0, $t0, 0x3918
    ctx->r8 = ADD32(ctx->r8, 0X3918);
    // 0x8016DDFC: swc1        $f18, 0x2C($t0)
    MEM_W(0X2C, ctx->r8) = ctx->f18.u32l;
L_8016DE00:
    // 0x8016DE00: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8016DE04: lw          $t8, -0x2BFC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2BFC);
    // 0x8016DE08: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8016DE0C: bgez        $t8, L_8016DE24
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8016DE10: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8016DE24;
    }
    // 0x8016DE10: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8016DE14: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8016DE18: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8016DE1C: nop

    // 0x8016DE20: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8016DE24:
    // 0x8016DE24: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8016DE28: lw          $t1, -0x2C00($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2C00);
    // 0x8016DE2C: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x8016DE30: bgez        $t1, L_8016DE48
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8016DE34: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_8016DE48;
    }
    // 0x8016DE34: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8016DE38: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8016DE3C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8016DE40: nop

    // 0x8016DE44: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_8016DE48:
    // 0x8016DE48: div.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = DIV_S(ctx->f6.fl, ctx->f16.fl);
    // 0x8016DE4C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016DE50: jal         0x8016D6F0
    // 0x8016DE54: swc1        $f4, 0x3948($at)
    MEM_W(0X3948, ctx->r1) = ctx->f4.u32l;
    func_8016D6F0_02FC30(rdram, ctx);
        goto after_0;
    // 0x8016DE54: swc1        $f4, 0x3948($at)
    MEM_W(0X3948, ctx->r1) = ctx->f4.u32l;
    after_0:
    // 0x8016DE58: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016DE5C: lwc1        $f8, 0x394C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X394C);
    // 0x8016DE60: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8016DE64: addiu       $t3, $t3, -0x4198
    ctx->r11 = ADD32(ctx->r11, -0X4198);
    // 0x8016DE68: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016DE6C: swc1        $f8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f8.u32l;
    // 0x8016DE70: lwc1        $f10, 0x3950($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X3950);
    // 0x8016DE74: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8016DE78: addiu       $t2, $t2, -0x4198
    ctx->r10 = ADD32(ctx->r10, -0X4198);
    // 0x8016DE7C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016DE80: swc1        $f10, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->f10.u32l;
    // 0x8016DE84: lwc1        $f18, 0x3954($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X3954);
    // 0x8016DE88: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8016DE8C: addiu       $t4, $t4, -0x4198
    ctx->r12 = ADD32(ctx->r12, -0X4198);
    // 0x8016DE90: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8016DE94: swc1        $f18, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->f18.u32l;
    // 0x8016DE98: lw          $t7, -0x2BFC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2BFC);
    // 0x8016DE9C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016DEA0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8016DEA4: addiu       $t5, $t7, 0x1
    ctx->r13 = ADD32(ctx->r15, 0X1);
    // 0x8016DEA8: sw          $t5, -0x2BFC($at)
    MEM_W(-0X2BFC, ctx->r1) = ctx->r13;
    // 0x8016DEAC: lw          $t6, -0x2C00($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2C00);
    // 0x8016DEB0: bne         $t5, $t6, L_8016DED0
    if (ctx->r13 != ctx->r14) {
        // 0x8016DEB4: nop
    
            goto L_8016DED0;
    }
    // 0x8016DEB4: nop

    // 0x8016DEB8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8016DEBC: lw          $t9, -0x2C04($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2C04);
    // 0x8016DEC0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016DEC4: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8016DEC8: jal         0x8016E6AC
    // 0x8016DECC: sw          $t0, -0x2C04($at)
    MEM_W(-0X2C04, ctx->r1) = ctx->r8;
    func_8016E6AC_02FC30(rdram, ctx);
        goto after_1;
    // 0x8016DECC: sw          $t0, -0x2C04($at)
    MEM_W(-0X2C04, ctx->r1) = ctx->r8;
    after_1:
L_8016DED0:
    // 0x8016DED0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8016DED4: lhu         $t8, -0x2C08($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X2C08);
    // 0x8016DED8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8016DEDC: andi        $t1, $t8, 0x2
    ctx->r9 = ctx->r24 & 0X2;
    // 0x8016DEE0: beq         $t1, $at, L_8016E3AC
    if (ctx->r9 == ctx->r1) {
        // 0x8016DEE4: nop
    
            goto L_8016E3AC;
    }
    // 0x8016DEE4: nop

    // 0x8016DEE8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8016DEEC: lw          $t2, -0x2BF8($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2BF8);
    // 0x8016DEF0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8016DEF4: lw          $t3, -0x2BB4($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2BB4);
    // 0x8016DEF8: sll         $t4, $t2, 4
    ctx->r12 = S32(ctx->r10 << 4);
    // 0x8016DEFC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8016DF00: addu        $t7, $t3, $t4
    ctx->r15 = ADD32(ctx->r11, ctx->r12);
    // 0x8016DF04: lwc1        $f6, 0x4($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X4);
    // 0x8016DF08: addiu       $t5, $t5, 0x3918
    ctx->r13 = ADD32(ctx->r13, 0X3918);
    // 0x8016DF0C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8016DF10: swc1        $f6, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->f6.u32l;
    // 0x8016DF14: lw          $t9, -0x2BF8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2BF8);
    // 0x8016DF18: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8016DF1C: lw          $t6, -0x2BB4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2BB4);
    // 0x8016DF20: sll         $t0, $t9, 4
    ctx->r8 = S32(ctx->r25 << 4);
    // 0x8016DF24: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8016DF28: addu        $t8, $t6, $t0
    ctx->r24 = ADD32(ctx->r14, ctx->r8);
    // 0x8016DF2C: lwc1        $f16, 0x8($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X8);
    // 0x8016DF30: addiu       $t1, $t1, 0x3918
    ctx->r9 = ADD32(ctx->r9, 0X3918);
    // 0x8016DF34: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8016DF38: swc1        $f16, 0x14($t1)
    MEM_W(0X14, ctx->r9) = ctx->f16.u32l;
    // 0x8016DF3C: lw          $t3, -0x2BF8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2BF8);
    // 0x8016DF40: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8016DF44: lw          $t2, -0x2BB4($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2BB4);
    // 0x8016DF48: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x8016DF4C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8016DF50: addu        $t7, $t2, $t4
    ctx->r15 = ADD32(ctx->r10, ctx->r12);
    // 0x8016DF54: lwc1        $f4, 0xC($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0XC);
    // 0x8016DF58: addiu       $t5, $t5, 0x3918
    ctx->r13 = ADD32(ctx->r13, 0X3918);
    // 0x8016DF5C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8016DF60: swc1        $f4, 0x24($t5)
    MEM_W(0X24, ctx->r13) = ctx->f4.u32l;
    // 0x8016DF64: lw          $t9, -0x2BF8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2BF8);
    // 0x8016DF68: bne         $t9, $zero, L_8016DFE4
    if (ctx->r25 != 0) {
        // 0x8016DF6C: nop
    
            goto L_8016DFE4;
    }
    // 0x8016DF6C: nop

    // 0x8016DF70: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8016DF74: lw          $t6, -0x2BB4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2BB4);
    // 0x8016DF78: sll         $t0, $t9, 4
    ctx->r8 = S32(ctx->r25 << 4);
    // 0x8016DF7C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8016DF80: addu        $t8, $t6, $t0
    ctx->r24 = ADD32(ctx->r14, ctx->r8);
    // 0x8016DF84: lwc1        $f8, 0x4($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X4);
    // 0x8016DF88: addiu       $t1, $t1, 0x3918
    ctx->r9 = ADD32(ctx->r9, 0X3918);
    // 0x8016DF8C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8016DF90: swc1        $f8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f8.u32l;
    // 0x8016DF94: lw          $t2, -0x2BF8($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2BF8);
    // 0x8016DF98: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8016DF9C: lw          $t3, -0x2BB4($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2BB4);
    // 0x8016DFA0: sll         $t4, $t2, 4
    ctx->r12 = S32(ctx->r10 << 4);
    // 0x8016DFA4: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8016DFA8: addu        $t7, $t3, $t4
    ctx->r15 = ADD32(ctx->r11, ctx->r12);
    // 0x8016DFAC: lwc1        $f10, 0x8($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X8);
    // 0x8016DFB0: addiu       $t5, $t5, 0x3918
    ctx->r13 = ADD32(ctx->r13, 0X3918);
    // 0x8016DFB4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8016DFB8: swc1        $f10, 0x10($t5)
    MEM_W(0X10, ctx->r13) = ctx->f10.u32l;
    // 0x8016DFBC: lw          $t6, -0x2BF8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2BF8);
    // 0x8016DFC0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8016DFC4: lw          $t9, -0x2BB4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2BB4);
    // 0x8016DFC8: sll         $t0, $t6, 4
    ctx->r8 = S32(ctx->r14 << 4);
    // 0x8016DFCC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8016DFD0: addu        $t8, $t9, $t0
    ctx->r24 = ADD32(ctx->r25, ctx->r8);
    // 0x8016DFD4: lwc1        $f18, 0xC($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0XC);
    // 0x8016DFD8: addiu       $t1, $t1, 0x3918
    ctx->r9 = ADD32(ctx->r9, 0X3918);
    // 0x8016DFDC: b           L_8016E05C
    // 0x8016DFE0: swc1        $f18, 0x20($t1)
    MEM_W(0X20, ctx->r9) = ctx->f18.u32l;
        goto L_8016E05C;
    // 0x8016DFE0: swc1        $f18, 0x20($t1)
    MEM_W(0X20, ctx->r9) = ctx->f18.u32l;
L_8016DFE4:
    // 0x8016DFE4: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8016DFE8: lw          $t3, -0x2BF8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2BF8);
    // 0x8016DFEC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8016DFF0: lw          $t2, -0x2BB4($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2BB4);
    // 0x8016DFF4: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x8016DFF8: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8016DFFC: addu        $t7, $t2, $t4
    ctx->r15 = ADD32(ctx->r10, ctx->r12);
    // 0x8016E000: lwc1        $f6, -0xC($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, -0XC);
    // 0x8016E004: addiu       $t5, $t5, 0x3918
    ctx->r13 = ADD32(ctx->r13, 0X3918);
    // 0x8016E008: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8016E00C: swc1        $f6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f6.u32l;
    // 0x8016E010: lw          $t9, -0x2BF8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2BF8);
    // 0x8016E014: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8016E018: lw          $t6, -0x2BB4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2BB4);
    // 0x8016E01C: sll         $t0, $t9, 4
    ctx->r8 = S32(ctx->r25 << 4);
    // 0x8016E020: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8016E024: addu        $t8, $t6, $t0
    ctx->r24 = ADD32(ctx->r14, ctx->r8);
    // 0x8016E028: lwc1        $f16, -0x8($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, -0X8);
    // 0x8016E02C: addiu       $t1, $t1, 0x3918
    ctx->r9 = ADD32(ctx->r9, 0X3918);
    // 0x8016E030: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8016E034: swc1        $f16, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->f16.u32l;
    // 0x8016E038: lw          $t2, -0x2BF8($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2BF8);
    // 0x8016E03C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8016E040: lw          $t3, -0x2BB4($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2BB4);
    // 0x8016E044: sll         $t4, $t2, 4
    ctx->r12 = S32(ctx->r10 << 4);
    // 0x8016E048: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8016E04C: addu        $t7, $t3, $t4
    ctx->r15 = ADD32(ctx->r11, ctx->r12);
    // 0x8016E050: lwc1        $f4, -0x4($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, -0X4);
    // 0x8016E054: addiu       $t5, $t5, 0x3918
    ctx->r13 = ADD32(ctx->r13, 0X3918);
    // 0x8016E058: swc1        $f4, 0x20($t5)
    MEM_W(0X20, ctx->r13) = ctx->f4.u32l;
L_8016E05C:
    // 0x8016E05C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8016E060: lw          $t6, -0x2BF8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2BF8);
    // 0x8016E064: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8016E068: lw          $t9, -0x2BB4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2BB4);
    // 0x8016E06C: sll         $t0, $t6, 4
    ctx->r8 = S32(ctx->r14 << 4);
    // 0x8016E070: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8016E074: addu        $t8, $t9, $t0
    ctx->r24 = ADD32(ctx->r25, ctx->r8);
    // 0x8016E078: lhu         $t1, 0x10($t8)
    ctx->r9 = MEM_HU(ctx->r24, 0X10);
    // 0x8016E07C: bne         $t1, $at, L_8016E160
    if (ctx->r9 != ctx->r1) {
        // 0x8016E080: nop
    
            goto L_8016E160;
    }
    // 0x8016E080: nop

    // 0x8016E084: lwc1        $f8, 0x4($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X4);
    // 0x8016E088: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8016E08C: addiu       $t2, $t2, 0x3918
    ctx->r10 = ADD32(ctx->r10, 0X3918);
    // 0x8016E090: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8016E094: swc1        $f8, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->f8.u32l;
    // 0x8016E098: lw          $t4, -0x2BF8($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2BF8);
    // 0x8016E09C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8016E0A0: lw          $t3, -0x2BB4($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2BB4);
    // 0x8016E0A4: sll         $t7, $t4, 4
    ctx->r15 = S32(ctx->r12 << 4);
    // 0x8016E0A8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8016E0AC: addu        $t5, $t3, $t7
    ctx->r13 = ADD32(ctx->r11, ctx->r15);
    // 0x8016E0B0: lwc1        $f10, 0x8($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X8);
    // 0x8016E0B4: addiu       $t6, $t6, 0x3918
    ctx->r14 = ADD32(ctx->r14, 0X3918);
    // 0x8016E0B8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8016E0BC: swc1        $f10, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->f10.u32l;
    // 0x8016E0C0: lw          $t0, -0x2BF8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2BF8);
    // 0x8016E0C4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8016E0C8: lw          $t9, -0x2BB4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2BB4);
    // 0x8016E0CC: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x8016E0D0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8016E0D4: addu        $t8, $t9, $t1
    ctx->r24 = ADD32(ctx->r25, ctx->r9);
    // 0x8016E0D8: lwc1        $f18, 0xC($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0XC);
    // 0x8016E0DC: addiu       $t2, $t2, 0x3918
    ctx->r10 = ADD32(ctx->r10, 0X3918);
    // 0x8016E0E0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8016E0E4: swc1        $f18, 0x28($t2)
    MEM_W(0X28, ctx->r10) = ctx->f18.u32l;
    // 0x8016E0E8: lw          $t3, -0x2BF8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2BF8);
    // 0x8016E0EC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8016E0F0: lw          $t4, -0x2BB4($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2BB4);
    // 0x8016E0F4: sll         $t7, $t3, 4
    ctx->r15 = S32(ctx->r11 << 4);
    // 0x8016E0F8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8016E0FC: addu        $t5, $t4, $t7
    ctx->r13 = ADD32(ctx->r12, ctx->r15);
    // 0x8016E100: lwc1        $f6, 0x4($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X4);
    // 0x8016E104: addiu       $t6, $t6, 0x3918
    ctx->r14 = ADD32(ctx->r14, 0X3918);
    // 0x8016E108: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8016E10C: swc1        $f6, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f6.u32l;
    // 0x8016E110: lw          $t9, -0x2BF8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2BF8);
    // 0x8016E114: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8016E118: lw          $t0, -0x2BB4($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2BB4);
    // 0x8016E11C: sll         $t1, $t9, 4
    ctx->r9 = S32(ctx->r25 << 4);
    // 0x8016E120: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8016E124: addu        $t8, $t0, $t1
    ctx->r24 = ADD32(ctx->r8, ctx->r9);
    // 0x8016E128: lwc1        $f16, 0x8($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X8);
    // 0x8016E12C: addiu       $t2, $t2, 0x3918
    ctx->r10 = ADD32(ctx->r10, 0X3918);
    // 0x8016E130: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8016E134: swc1        $f16, 0x1C($t2)
    MEM_W(0X1C, ctx->r10) = ctx->f16.u32l;
    // 0x8016E138: lw          $t4, -0x2BF8($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2BF8);
    // 0x8016E13C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8016E140: lw          $t3, -0x2BB4($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2BB4);
    // 0x8016E144: sll         $t7, $t4, 4
    ctx->r15 = S32(ctx->r12 << 4);
    // 0x8016E148: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8016E14C: addu        $t5, $t3, $t7
    ctx->r13 = ADD32(ctx->r11, ctx->r15);
    // 0x8016E150: lwc1        $f4, 0xC($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0XC);
    // 0x8016E154: addiu       $t6, $t6, 0x3918
    ctx->r14 = ADD32(ctx->r14, 0X3918);
    // 0x8016E158: b           L_8016E2DC
    // 0x8016E15C: swc1        $f4, 0x2C($t6)
    MEM_W(0X2C, ctx->r14) = ctx->f4.u32l;
        goto L_8016E2DC;
    // 0x8016E15C: swc1        $f4, 0x2C($t6)
    MEM_W(0X2C, ctx->r14) = ctx->f4.u32l;
L_8016E160:
    // 0x8016E160: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8016E164: lw          $t0, -0x2BF8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2BF8);
    // 0x8016E168: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8016E16C: lw          $t9, -0x2BB4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2BB4);
    // 0x8016E170: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x8016E174: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8016E178: addu        $t8, $t9, $t1
    ctx->r24 = ADD32(ctx->r25, ctx->r9);
    // 0x8016E17C: lwc1        $f8, 0x14($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X14);
    // 0x8016E180: addiu       $t2, $t2, 0x3918
    ctx->r10 = ADD32(ctx->r10, 0X3918);
    // 0x8016E184: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8016E188: swc1        $f8, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->f8.u32l;
    // 0x8016E18C: lw          $t3, -0x2BF8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2BF8);
    // 0x8016E190: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8016E194: lw          $t4, -0x2BB4($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2BB4);
    // 0x8016E198: sll         $t7, $t3, 4
    ctx->r15 = S32(ctx->r11 << 4);
    // 0x8016E19C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8016E1A0: addu        $t5, $t4, $t7
    ctx->r13 = ADD32(ctx->r12, ctx->r15);
    // 0x8016E1A4: lwc1        $f10, 0x18($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X18);
    // 0x8016E1A8: addiu       $t6, $t6, 0x3918
    ctx->r14 = ADD32(ctx->r14, 0X3918);
    // 0x8016E1AC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8016E1B0: swc1        $f10, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->f10.u32l;
    // 0x8016E1B4: lw          $t9, -0x2BF8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2BF8);
    // 0x8016E1B8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8016E1BC: lw          $t0, -0x2BB4($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2BB4);
    // 0x8016E1C0: sll         $t1, $t9, 4
    ctx->r9 = S32(ctx->r25 << 4);
    // 0x8016E1C4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8016E1C8: addu        $t8, $t0, $t1
    ctx->r24 = ADD32(ctx->r8, ctx->r9);
    // 0x8016E1CC: lwc1        $f18, 0x1C($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X1C);
    // 0x8016E1D0: addiu       $t2, $t2, 0x3918
    ctx->r10 = ADD32(ctx->r10, 0X3918);
    // 0x8016E1D4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8016E1D8: swc1        $f18, 0x28($t2)
    MEM_W(0X28, ctx->r10) = ctx->f18.u32l;
    // 0x8016E1DC: lw          $t4, -0x2BF8($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2BF8);
    // 0x8016E1E0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8016E1E4: lw          $t3, -0x2BB4($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2BB4);
    // 0x8016E1E8: sll         $t7, $t4, 4
    ctx->r15 = S32(ctx->r12 << 4);
    // 0x8016E1EC: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8016E1F0: addu        $t5, $t3, $t7
    ctx->r13 = ADD32(ctx->r11, ctx->r15);
    // 0x8016E1F4: lhu         $t6, 0x20($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X20);
    // 0x8016E1F8: bne         $t6, $at, L_8016E264
    if (ctx->r14 != ctx->r1) {
        // 0x8016E1FC: nop
    
            goto L_8016E264;
    }
    // 0x8016E1FC: nop

    // 0x8016E200: lwc1        $f6, 0x14($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X14);
    // 0x8016E204: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8016E208: addiu       $t9, $t9, 0x3918
    ctx->r25 = ADD32(ctx->r25, 0X3918);
    // 0x8016E20C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8016E210: swc1        $f6, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f6.u32l;
    // 0x8016E214: lw          $t1, -0x2BF8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2BF8);
    // 0x8016E218: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8016E21C: lw          $t0, -0x2BB4($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2BB4);
    // 0x8016E220: sll         $t8, $t1, 4
    ctx->r24 = S32(ctx->r9 << 4);
    // 0x8016E224: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8016E228: addu        $t2, $t0, $t8
    ctx->r10 = ADD32(ctx->r8, ctx->r24);
    // 0x8016E22C: lwc1        $f16, 0x18($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X18);
    // 0x8016E230: addiu       $t4, $t4, 0x3918
    ctx->r12 = ADD32(ctx->r12, 0X3918);
    // 0x8016E234: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8016E238: swc1        $f16, 0x1C($t4)
    MEM_W(0X1C, ctx->r12) = ctx->f16.u32l;
    // 0x8016E23C: lw          $t7, -0x2BF8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2BF8);
    // 0x8016E240: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8016E244: lw          $t3, -0x2BB4($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2BB4);
    // 0x8016E248: sll         $t6, $t7, 4
    ctx->r14 = S32(ctx->r15 << 4);
    // 0x8016E24C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8016E250: addu        $t5, $t3, $t6
    ctx->r13 = ADD32(ctx->r11, ctx->r14);
    // 0x8016E254: lwc1        $f4, 0x1C($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X1C);
    // 0x8016E258: addiu       $t9, $t9, 0x3918
    ctx->r25 = ADD32(ctx->r25, 0X3918);
    // 0x8016E25C: b           L_8016E2DC
    // 0x8016E260: swc1        $f4, 0x2C($t9)
    MEM_W(0X2C, ctx->r25) = ctx->f4.u32l;
        goto L_8016E2DC;
    // 0x8016E260: swc1        $f4, 0x2C($t9)
    MEM_W(0X2C, ctx->r25) = ctx->f4.u32l;
L_8016E264:
    // 0x8016E264: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8016E268: lw          $t0, -0x2BF8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2BF8);
    // 0x8016E26C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8016E270: lw          $t1, -0x2BB4($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2BB4);
    // 0x8016E274: sll         $t8, $t0, 4
    ctx->r24 = S32(ctx->r8 << 4);
    // 0x8016E278: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8016E27C: addu        $t2, $t1, $t8
    ctx->r10 = ADD32(ctx->r9, ctx->r24);
    // 0x8016E280: lwc1        $f8, 0x24($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X24);
    // 0x8016E284: addiu       $t4, $t4, 0x3918
    ctx->r12 = ADD32(ctx->r12, 0X3918);
    // 0x8016E288: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8016E28C: swc1        $f8, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->f8.u32l;
    // 0x8016E290: lw          $t3, -0x2BF8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2BF8);
    // 0x8016E294: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8016E298: lw          $t7, -0x2BB4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2BB4);
    // 0x8016E29C: sll         $t6, $t3, 4
    ctx->r14 = S32(ctx->r11 << 4);
    // 0x8016E2A0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8016E2A4: addu        $t5, $t7, $t6
    ctx->r13 = ADD32(ctx->r15, ctx->r14);
    // 0x8016E2A8: lwc1        $f10, 0x28($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X28);
    // 0x8016E2AC: addiu       $t9, $t9, 0x3918
    ctx->r25 = ADD32(ctx->r25, 0X3918);
    // 0x8016E2B0: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8016E2B4: swc1        $f10, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->f10.u32l;
    // 0x8016E2B8: lw          $t1, -0x2BF8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2BF8);
    // 0x8016E2BC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8016E2C0: lw          $t0, -0x2BB4($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2BB4);
    // 0x8016E2C4: sll         $t8, $t1, 4
    ctx->r24 = S32(ctx->r9 << 4);
    // 0x8016E2C8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8016E2CC: addu        $t2, $t0, $t8
    ctx->r10 = ADD32(ctx->r8, ctx->r24);
    // 0x8016E2D0: lwc1        $f18, 0x2C($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X2C);
    // 0x8016E2D4: addiu       $t4, $t4, 0x3918
    ctx->r12 = ADD32(ctx->r12, 0X3918);
    // 0x8016E2D8: swc1        $f18, 0x2C($t4)
    MEM_W(0X2C, ctx->r12) = ctx->f18.u32l;
L_8016E2DC:
    // 0x8016E2DC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8016E2E0: lw          $t3, -0x2BF0($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2BF0);
    // 0x8016E2E4: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x8016E2E8: bgez        $t3, L_8016E300
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8016E2EC: cvt.s.w     $f16, $f6
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
            goto L_8016E300;
    }
    // 0x8016E2EC: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8016E2F0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8016E2F4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8016E2F8: nop

    // 0x8016E2FC: add.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f4.fl;
L_8016E300:
    // 0x8016E300: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8016E304: lw          $t7, -0x2BF4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2BF4);
    // 0x8016E308: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x8016E30C: bgez        $t7, L_8016E324
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8016E310: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_8016E324;
    }
    // 0x8016E310: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8016E314: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8016E318: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8016E31C: nop

    // 0x8016E320: add.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f18.fl;
L_8016E324:
    // 0x8016E324: div.s       $f6, $f16, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = DIV_S(ctx->f16.fl, ctx->f10.fl);
    // 0x8016E328: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016E32C: jal         0x8016D6F0
    // 0x8016E330: swc1        $f6, 0x3948($at)
    MEM_W(0X3948, ctx->r1) = ctx->f6.u32l;
    func_8016D6F0_02FC30(rdram, ctx);
        goto after_2;
    // 0x8016E330: swc1        $f6, 0x3948($at)
    MEM_W(0X3948, ctx->r1) = ctx->f6.u32l;
    after_2:
    // 0x8016E334: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016E338: lwc1        $f4, 0x394C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X394C);
    // 0x8016E33C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8016E340: addiu       $t6, $t6, -0x4198
    ctx->r14 = ADD32(ctx->r14, -0X4198);
    // 0x8016E344: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016E348: swc1        $f4, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f4.u32l;
    // 0x8016E34C: lwc1        $f8, 0x3950($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X3950);
    // 0x8016E350: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8016E354: addiu       $t5, $t5, -0x4198
    ctx->r13 = ADD32(ctx->r13, -0X4198);
    // 0x8016E358: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016E35C: swc1        $f8, 0x10($t5)
    MEM_W(0X10, ctx->r13) = ctx->f8.u32l;
    // 0x8016E360: lwc1        $f18, 0x3954($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X3954);
    // 0x8016E364: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8016E368: addiu       $t9, $t9, -0x4198
    ctx->r25 = ADD32(ctx->r25, -0X4198);
    // 0x8016E36C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8016E370: swc1        $f18, 0x14($t9)
    MEM_W(0X14, ctx->r25) = ctx->f18.u32l;
    // 0x8016E374: lw          $t1, -0x2BF0($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2BF0);
    // 0x8016E378: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016E37C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8016E380: addiu       $t0, $t1, 0x1
    ctx->r8 = ADD32(ctx->r9, 0X1);
    // 0x8016E384: sw          $t0, -0x2BF0($at)
    MEM_W(-0X2BF0, ctx->r1) = ctx->r8;
    // 0x8016E388: lw          $t8, -0x2BF4($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2BF4);
    // 0x8016E38C: bne         $t0, $t8, L_8016E3AC
    if (ctx->r8 != ctx->r24) {
        // 0x8016E390: nop
    
            goto L_8016E3AC;
    }
    // 0x8016E390: nop

    // 0x8016E394: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8016E398: lw          $t2, -0x2BF8($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2BF8);
    // 0x8016E39C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016E3A0: addiu       $t4, $t2, 0x1
    ctx->r12 = ADD32(ctx->r10, 0X1);
    // 0x8016E3A4: jal         0x8016E7EC
    // 0x8016E3A8: sw          $t4, -0x2BF8($at)
    MEM_W(-0X2BF8, ctx->r1) = ctx->r12;
    func_8016E7EC_02FC30(rdram, ctx);
        goto after_3;
    // 0x8016E3A8: sw          $t4, -0x2BF8($at)
    MEM_W(-0X2BF8, ctx->r1) = ctx->r12;
    after_3:
L_8016E3AC:
    // 0x8016E3AC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8016E3B0: lhu         $t3, -0x2C08($t3)
    ctx->r11 = MEM_HU(ctx->r11, -0X2C08);
    // 0x8016E3B4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8016E3B8: andi        $t7, $t3, 0x4
    ctx->r15 = ctx->r11 & 0X4;
    // 0x8016E3BC: beq         $t7, $at, L_8016E690
    if (ctx->r15 == ctx->r1) {
        // 0x8016E3C0: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8016E690;
    }
    // 0x8016E3C0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016E3C4: lwc1        $f16, -0x2BD0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2BD0);
    // 0x8016E3C8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016E3CC: lwc1        $f10, -0x2BD4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2BD4);
    // 0x8016E3D0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016E3D4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8016E3D8: add.s       $f6, $f16, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x8016E3DC: addiu       $t6, $t6, -0x4198
    ctx->r14 = ADD32(ctx->r14, -0X4198);
    // 0x8016E3E0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8016E3E4: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x8016E3E8: swc1        $f6, -0x2BD0($at)
    MEM_W(-0X2BD0, ctx->r1) = ctx->f6.u32l;
    // 0x8016E3EC: lwc1        $f8, 0x0($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X0);
    // 0x8016E3F0: lwc1        $f4, 0xC($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0XC);
    // 0x8016E3F4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8016E3F8: addiu       $t9, $t9, -0x4198
    ctx->r25 = ADD32(ctx->r25, -0X4198);
    // 0x8016E3FC: sub.s       $f18, $f4, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x8016E400: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8016E404: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x8016E408: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8016E40C: swc1        $f18, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f18.u32l;
    // 0x8016E410: lwc1        $f10, 0x4($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X4);
    // 0x8016E414: lwc1        $f16, 0x10($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X10);
    // 0x8016E418: addiu       $t0, $t0, -0x4198
    ctx->r8 = ADD32(ctx->r8, -0X4198);
    // 0x8016E41C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8016E420: sub.s       $f6, $f16, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x8016E424: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x8016E428: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8016E42C: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x8016E430: swc1        $f6, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->f6.u32l;
    // 0x8016E434: lwc1        $f8, 0x8($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X8);
    // 0x8016E438: lwc1        $f4, 0x14($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X14);
    // 0x8016E43C: sub.s       $f18, $f4, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x8016E440: swc1        $f18, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f18.u32l;
    // 0x8016E444: lwc1        $f14, 0x8($t2)
    ctx->f14.u32l = MEM_W(ctx->r10, 0X8);
    // 0x8016E448: jal         0x800E4940
    // 0x8016E44C: lwc1        $f12, 0x0($t2)
    ctx->f12.u32l = MEM_W(ctx->r10, 0X0);
    func_800E4940(rdram, ctx);
        goto after_4;
    // 0x8016E44C: lwc1        $f12, 0x0($t2)
    ctx->f12.u32l = MEM_W(ctx->r10, 0X0);
    after_4:
    // 0x8016E450: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8016E454: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8016E458: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8016E45C: lwc1        $f6, 0x2678($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X2678);
    // 0x8016E460: mul.s       $f10, $f0, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8016E464: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8016E468: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x8016E46C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8016E470: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8016E474: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x8016E478: addiu       $a0, $sp, 0x78
    ctx->r4 = ADD32(ctx->r29, 0X78);
    // 0x8016E47C: div.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f6.fl);
    // 0x8016E480: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8016E484: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8016E488: swc1        $f4, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->f4.u32l;
    // 0x8016E48C: lw          $a1, 0xC($t3)
    ctx->r5 = MEM_W(ctx->r11, 0XC);
    // 0x8016E490: jal         0x800D7120
    // 0x8016E494: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    guAlignF_recomp(rdram, ctx);
        goto after_5;
    // 0x8016E494: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_5:
    // 0x8016E498: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8016E49C: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x8016E4A0: lwc1        $f18, 0x0($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0X0);
    // 0x8016E4A4: lwc1        $f10, 0x4($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X4);
    // 0x8016E4A8: lwc1        $f8, 0x8($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X8);
    // 0x8016E4AC: mul.s       $f16, $f18, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x8016E4B0: nop

    // 0x8016E4B4: mul.s       $f6, $f10, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x8016E4B8: add.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x8016E4BC: mul.s       $f18, $f8, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x8016E4C0: jal         0x800D68E0
    // 0x8016E4C4: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_6;
    // 0x8016E4C4: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    after_6:
    // 0x8016E4C8: addiu       $t6, $sp, 0x78
    ctx->r14 = ADD32(ctx->r29, 0X78);
    // 0x8016E4CC: lwc1        $f10, 0x20($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X20);
    // 0x8016E4D0: lwc1        $f6, 0x24($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X24);
    // 0x8016E4D4: lwc1        $f4, 0x28($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X28);
    // 0x8016E4D8: mul.s       $f16, $f10, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x8016E4DC: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x8016E4E0: mul.s       $f8, $f6, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x8016E4E4: add.s       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x8016E4E8: mul.s       $f10, $f4, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x8016E4EC: jal         0x800D68E0
    // 0x8016E4F0: add.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f18.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_7;
    // 0x8016E4F0: add.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f18.fl;
    after_7:
    // 0x8016E4F4: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8016E4F8: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x8016E4FC: addiu       $t9, $sp, 0x78
    ctx->r25 = ADD32(ctx->r29, 0X78);
    // 0x8016E500: lwc1        $f16, 0x20($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X20);
    // 0x8016E504: lwc1        $f6, 0x0($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X0);
    // 0x8016E508: lwc1        $f10, 0x24($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X24);
    // 0x8016E50C: lwc1        $f4, 0x4($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X4);
    // 0x8016E510: mul.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x8016E514: lwc1        $f16, 0x8($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0X8);
    // 0x8016E518: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8016E51C: mul.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8016E520: lwc1        $f4, 0x28($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X28);
    // 0x8016E524: mul.s       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x8016E528: add.s       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x8016E52C: mul.s       $f18, $f20, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = MUL_S(ctx->f20.fl, ctx->f22.fl);
    // 0x8016E530: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8016E534: jal         0x800E4BE0
    // 0x8016E538: div.s       $f12, $f8, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = DIV_S(ctx->f8.fl, ctx->f18.fl);
    func_800E4BE0(rdram, ctx);
        goto after_8;
    // 0x8016E538: div.s       $f12, $f8, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = DIV_S(ctx->f8.fl, ctx->f18.fl);
    after_8:
    // 0x8016E53C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8016E540: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8016E544: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8016E548: lwc1        $f6, 0x267C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X267C);
    // 0x8016E54C: mul.s       $f4, $f0, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8016E550: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8016E554: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x8016E558: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8016E55C: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x8016E560: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8016E564: div.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8016E568: swc1        $f10, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->f10.u32l;
    // 0x8016E56C: lwc1        $f8, 0x4($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X4);
    // 0x8016E570: c.lt.s      $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.fl < ctx->f8.fl;
    // 0x8016E574: nop

    // 0x8016E578: bc1f        L_8016E590
    if (!c1cs) {
        // 0x8016E57C: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_8016E590;
    }
    // 0x8016E57C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8016E580: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8016E584: lwc1        $f16, 0x10($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X10);
    // 0x8016E588: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x8016E58C: swc1        $f6, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->f6.u32l;
L_8016E590:
    // 0x8016E590: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8016E594: addiu       $t2, $sp, 0x78
    ctx->r10 = ADD32(ctx->r29, 0X78);
    // 0x8016E598: lwc1        $f10, 0x8($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X8);
    // 0x8016E59C: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x8016E5A0: lw          $a1, 0x10($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X10);
    // 0x8016E5A4: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x8016E5A8: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x8016E5AC: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x8016E5B0: jal         0x800D7120
    // 0x8016E5B4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    guAlignF_recomp(rdram, ctx);
        goto after_9;
    // 0x8016E5B4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_9:
    // 0x8016E5B8: addiu       $t4, $sp, 0x78
    ctx->r12 = ADD32(ctx->r29, 0X78);
    // 0x8016E5BC: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x8016E5C0: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    // 0x8016E5C4: jal         0x800D6F30
    // 0x8016E5C8: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    guMtxCatF_recomp(rdram, ctx);
        goto after_10;
    // 0x8016E5C8: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_10:
    // 0x8016E5CC: addiu       $t3, $sp, 0x78
    ctx->r11 = ADD32(ctx->r29, 0X78);
    // 0x8016E5D0: lwc1        $f8, 0x28($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X28);
    // 0x8016E5D4: lw          $a2, 0x20($t3)
    ctx->r6 = MEM_W(ctx->r11, 0X20);
    // 0x8016E5D8: lw          $a3, 0x24($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X24);
    // 0x8016E5DC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8016E5E0: lw          $a1, -0x2BD0($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X2BD0);
    // 0x8016E5E4: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x8016E5E8: jal         0x800D7120
    // 0x8016E5EC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    guAlignF_recomp(rdram, ctx);
        goto after_11;
    // 0x8016E5EC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_11:
    // 0x8016E5F0: addiu       $t7, $sp, 0x78
    ctx->r15 = ADD32(ctx->r29, 0X78);
    // 0x8016E5F4: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x8016E5F8: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x8016E5FC: jal         0x800D6F30
    // 0x8016E600: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    guMtxCatF_recomp(rdram, ctx);
        goto after_12;
    // 0x8016E600: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_12:
    // 0x8016E604: addiu       $t6, $sp, 0x78
    ctx->r14 = ADD32(ctx->r29, 0X78);
    // 0x8016E608: lwc1        $f18, 0x10($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X10);
    // 0x8016E60C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8016E610: addiu       $t5, $t5, -0x4198
    ctx->r13 = ADD32(ctx->r13, -0X4198);
    // 0x8016E614: addiu       $t9, $sp, 0x78
    ctx->r25 = ADD32(ctx->r29, 0X78);
    // 0x8016E618: swc1        $f18, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f18.u32l;
    // 0x8016E61C: lwc1        $f16, 0x14($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X14);
    // 0x8016E620: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8016E624: addiu       $t1, $t1, -0x4198
    ctx->r9 = ADD32(ctx->r9, -0X4198);
    // 0x8016E628: addiu       $t0, $sp, 0x78
    ctx->r8 = ADD32(ctx->r29, 0X78);
    // 0x8016E62C: swc1        $f16, 0x1C($t1)
    MEM_W(0X1C, ctx->r9) = ctx->f16.u32l;
    // 0x8016E630: lwc1        $f4, 0x18($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X18);
    // 0x8016E634: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8016E638: addiu       $t8, $t8, -0x4198
    ctx->r24 = ADD32(ctx->r24, -0X4198);
    // 0x8016E63C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8016E640: swc1        $f4, 0x20($t8)
    MEM_W(0X20, ctx->r24) = ctx->f4.u32l;
    // 0x8016E644: lw          $t2, -0x2BE4($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2BE4);
    // 0x8016E648: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016E64C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8016E650: addiu       $t4, $t2, 0x1
    ctx->r12 = ADD32(ctx->r10, 0X1);
    // 0x8016E654: sw          $t4, -0x2BE4($at)
    MEM_W(-0X2BE4, ctx->r1) = ctx->r12;
    // 0x8016E658: lw          $t7, -0x2BEC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2BEC);
    // 0x8016E65C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8016E660: lw          $t3, -0x2BB0($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2BB0);
    // 0x8016E664: sll         $t6, $t7, 3
    ctx->r14 = S32(ctx->r15 << 3);
    // 0x8016E668: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8016E66C: addu        $t5, $t3, $t6
    ctx->r13 = ADD32(ctx->r11, ctx->r14);
    // 0x8016E670: lhu         $t9, 0x0($t5)
    ctx->r25 = MEM_HU(ctx->r13, 0X0);
    // 0x8016E674: lw          $t1, -0x2E34($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2E34);
    // 0x8016E678: bne         $t9, $t1, L_8016E690
    if (ctx->r25 != ctx->r9) {
        // 0x8016E67C: nop
    
            goto L_8016E690;
    }
    // 0x8016E67C: nop

    // 0x8016E680: addiu       $t0, $t7, 0x1
    ctx->r8 = ADD32(ctx->r15, 0X1);
    // 0x8016E684: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016E688: jal         0x8016E71C
    // 0x8016E68C: sw          $t0, -0x2BEC($at)
    MEM_W(-0X2BEC, ctx->r1) = ctx->r8;
    func_8016E71C_02FC30(rdram, ctx);
        goto after_13;
    // 0x8016E68C: sw          $t0, -0x2BEC($at)
    MEM_W(-0X2BEC, ctx->r1) = ctx->r8;
    after_13:
L_8016E690:
    // 0x8016E690: jal         0x800C3FD0
    // 0x8016E694: nop

    func_800C3FD0(rdram, ctx);
        goto after_14;
    // 0x8016E694: nop

    after_14:
    // 0x8016E698: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8016E69C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8016E6A0: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8016E6A4: jr          $ra
    // 0x8016E6A8: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    return;
    // 0x8016E6A8: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
;}
RECOMP_FUNC void func_8016E6AC_02FC30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016E6AC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8016E6B0: lw          $t7, -0x2C04($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2C04);
    // 0x8016E6B4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8016E6B8: lw          $t6, -0x2BB8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2BB8);
    // 0x8016E6BC: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x8016E6C0: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8016E6C4: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8016E6C8: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x8016E6CC: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8016E6D0: sh          $t0, 0x6($sp)
    MEM_H(0X6, ctx->r29) = ctx->r8;
    // 0x8016E6D4: lhu         $t1, 0x10($t9)
    ctx->r9 = MEM_HU(ctx->r25, 0X10);
    // 0x8016E6D8: bne         $t1, $at, L_8016E6F8
    if (ctx->r9 != ctx->r1) {
        // 0x8016E6DC: sh          $t1, 0x4($sp)
        MEM_H(0X4, ctx->r29) = ctx->r9;
            goto L_8016E6F8;
    }
    // 0x8016E6DC: sh          $t1, 0x4($sp)
    MEM_H(0X4, ctx->r29) = ctx->r9;
    // 0x8016E6E0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8016E6E4: lhu         $t2, -0x2C08($t2)
    ctx->r10 = MEM_HU(ctx->r10, -0X2C08);
    // 0x8016E6E8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016E6EC: ori         $t3, $t2, 0x1
    ctx->r11 = ctx->r10 | 0X1;
    // 0x8016E6F0: b           L_8016E714
    // 0x8016E6F4: sh          $t3, -0x2C08($at)
    MEM_H(-0X2C08, ctx->r1) = ctx->r11;
        goto L_8016E714;
    // 0x8016E6F4: sh          $t3, -0x2C08($at)
    MEM_H(-0X2C08, ctx->r1) = ctx->r11;
L_8016E6F8:
    // 0x8016E6F8: lhu         $t4, 0x4($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X4);
    // 0x8016E6FC: lhu         $t5, 0x6($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X6);
    // 0x8016E700: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016E704: subu        $t7, $t4, $t5
    ctx->r15 = SUB32(ctx->r12, ctx->r13);
    // 0x8016E708: sw          $t7, -0x2C00($at)
    MEM_W(-0X2C00, ctx->r1) = ctx->r15;
    // 0x8016E70C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016E710: sw          $zero, -0x2BFC($at)
    MEM_W(-0X2BFC, ctx->r1) = 0;
L_8016E714:
    // 0x8016E714: jr          $ra
    // 0x8016E718: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8016E718: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8016E71C_02FC30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016E71C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8016E720: lw          $t7, -0x2BEC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2BEC);
    // 0x8016E724: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8016E728: lw          $t6, -0x2BB0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2BB0);
    // 0x8016E72C: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8016E730: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016E734: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8016E738: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x8016E73C: sw          $t0, -0x2BE8($at)
    MEM_W(-0X2BE8, ctx->r1) = ctx->r8;
    // 0x8016E740: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8016E744: bne         $t0, $at, L_8016E764
    if (ctx->r8 != ctx->r1) {
        // 0x8016E748: nop
    
            goto L_8016E764;
    }
    // 0x8016E748: nop

    // 0x8016E74C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8016E750: lhu         $t1, -0x2C08($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X2C08);
    // 0x8016E754: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016E758: ori         $t2, $t1, 0x4
    ctx->r10 = ctx->r9 | 0X4;
    // 0x8016E75C: jr          $ra
    // 0x8016E760: sh          $t2, -0x2C08($at)
    MEM_H(-0X2C08, ctx->r1) = ctx->r10;
    return;
    // 0x8016E760: sh          $t2, -0x2C08($at)
    MEM_H(-0X2C08, ctx->r1) = ctx->r10;
L_8016E764:
    // 0x8016E764: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8016E768: lw          $t4, -0x2BEC($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2BEC);
    // 0x8016E76C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8016E770: lw          $t3, -0x2BB0($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2BB0);
    // 0x8016E774: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8016E778: lw          $t6, -0x2BE8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2BE8);
    // 0x8016E77C: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x8016E780: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016E784: addu        $t7, $t3, $t5
    ctx->r15 = ADD32(ctx->r11, ctx->r13);
    // 0x8016E788: lwc1        $f4, 0x4($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X4);
    // 0x8016E78C: lwc1        $f6, -0x2BD0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2BD0);
    // 0x8016E790: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x8016E794: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8016E798: bgez        $t6, L_8016E7B0
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8016E79C: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_8016E7B0;
    }
    // 0x8016E79C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8016E7A0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8016E7A4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8016E7A8: nop

    // 0x8016E7AC: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_8016E7B0:
    // 0x8016E7B0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8016E7B4: lw          $t8, -0x2E34($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2E34);
    // 0x8016E7B8: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8016E7BC: bgez        $t8, L_8016E7D4
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8016E7C0: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8016E7D4;
    }
    // 0x8016E7C0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8016E7C4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8016E7C8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8016E7CC: nop

    // 0x8016E7D0: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
L_8016E7D4:
    // 0x8016E7D4: sub.s       $f18, $f16, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x8016E7D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016E7DC: div.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f8.fl, ctx->f18.fl);
    // 0x8016E7E0: swc1        $f4, -0x2BD4($at)
    MEM_W(-0X2BD4, ctx->r1) = ctx->f4.u32l;
    // 0x8016E7E4: jr          $ra
    // 0x8016E7E8: nop

    return;
    // 0x8016E7E8: nop

;}
RECOMP_FUNC void func_8016E7EC_02FC30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016E7EC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8016E7F0: lw          $t7, -0x2BF8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2BF8);
    // 0x8016E7F4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8016E7F8: lw          $t6, -0x2BB4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2BB4);
    // 0x8016E7FC: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x8016E800: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8016E804: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8016E808: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x8016E80C: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8016E810: sh          $t0, 0x6($sp)
    MEM_H(0X6, ctx->r29) = ctx->r8;
    // 0x8016E814: lhu         $t1, 0x10($t9)
    ctx->r9 = MEM_HU(ctx->r25, 0X10);
    // 0x8016E818: bne         $t1, $at, L_8016E838
    if (ctx->r9 != ctx->r1) {
        // 0x8016E81C: sh          $t1, 0x4($sp)
        MEM_H(0X4, ctx->r29) = ctx->r9;
            goto L_8016E838;
    }
    // 0x8016E81C: sh          $t1, 0x4($sp)
    MEM_H(0X4, ctx->r29) = ctx->r9;
    // 0x8016E820: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8016E824: lhu         $t2, -0x2C08($t2)
    ctx->r10 = MEM_HU(ctx->r10, -0X2C08);
    // 0x8016E828: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016E82C: ori         $t3, $t2, 0x2
    ctx->r11 = ctx->r10 | 0X2;
    // 0x8016E830: b           L_8016E854
    // 0x8016E834: sh          $t3, -0x2C08($at)
    MEM_H(-0X2C08, ctx->r1) = ctx->r11;
        goto L_8016E854;
    // 0x8016E834: sh          $t3, -0x2C08($at)
    MEM_H(-0X2C08, ctx->r1) = ctx->r11;
L_8016E838:
    // 0x8016E838: lhu         $t4, 0x4($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X4);
    // 0x8016E83C: lhu         $t5, 0x6($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X6);
    // 0x8016E840: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016E844: subu        $t7, $t4, $t5
    ctx->r15 = SUB32(ctx->r12, ctx->r13);
    // 0x8016E848: sw          $t7, -0x2BF4($at)
    MEM_W(-0X2BF4, ctx->r1) = ctx->r15;
    // 0x8016E84C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016E850: sw          $zero, -0x2BF0($at)
    MEM_W(-0X2BF0, ctx->r1) = 0;
L_8016E854:
    // 0x8016E854: jr          $ra
    // 0x8016E858: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8016E858: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8016E85C_02FC30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016E85C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8016E860: sh          $zero, 0x6($sp)
    MEM_H(0X6, ctx->r29) = 0;
L_8016E864:
    // 0x8016E864: lhu         $t6, 0x6($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X6);
    // 0x8016E868: lhu         $t8, 0x6($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X6);
    // 0x8016E86C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016E870: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8016E874: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8016E878: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8016E87C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8016E880: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8016E884: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8016E888: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8016E88C: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8016E890: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8016E894: andi        $t0, $t9, 0xFFFF
    ctx->r8 = ctx->r25 & 0XFFFF;
    // 0x8016E898: sh          $zero, -0x2A28($at)
    MEM_H(-0X2A28, ctx->r1) = 0;
    // 0x8016E89C: slti        $at, $t0, 0x30
    ctx->r1 = SIGNED(ctx->r8) < 0X30 ? 1 : 0;
    // 0x8016E8A0: bne         $at, $zero, L_8016E864
    if (ctx->r1 != 0) {
        // 0x8016E8A4: sh          $t9, 0x6($sp)
        MEM_H(0X6, ctx->r29) = ctx->r25;
            goto L_8016E864;
    }
    // 0x8016E8A4: sh          $t9, 0x6($sp)
    MEM_H(0X6, ctx->r29) = ctx->r25;
    // 0x8016E8A8: jr          $ra
    // 0x8016E8AC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8016E8AC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8016E8B0_02FC30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016E8B0: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8016E8B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8016E8B8: sh          $zero, 0x62($sp)
    MEM_H(0X62, ctx->r29) = 0;
L_8016E8BC:
    // 0x8016E8BC: lhu         $t6, 0x62($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X62);
    // 0x8016E8C0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8016E8C4: addiu       $t8, $t8, -0x2A28
    ctx->r24 = ADD32(ctx->r24, -0X2A28);
    // 0x8016E8C8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8016E8CC: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8016E8D0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8016E8D4: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8016E8D8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8016E8DC: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8016E8E0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8016E8E4: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8016E8E8: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x8016E8EC: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8016E8F0: andi        $t1, $t0, 0x8000
    ctx->r9 = ctx->r8 & 0X8000;
    // 0x8016E8F4: bne         $t1, $at, L_8016F654
    if (ctx->r9 != ctx->r1) {
        // 0x8016E8F8: nop
    
            goto L_8016F654;
    }
    // 0x8016E8F8: nop

    // 0x8016E8FC: andi        $t2, $t0, 0x1
    ctx->r10 = ctx->r8 & 0X1;
    // 0x8016E900: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8016E904: beq         $t2, $at, L_8016F304
    if (ctx->r10 == ctx->r1) {
        // 0x8016E908: nop
    
            goto L_8016F304;
    }
    // 0x8016E908: nop

    // 0x8016E90C: lw          $t4, 0x34($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X34);
    // 0x8016E910: lw          $t3, 0x50($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X50);
    // 0x8016E914: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8016E918: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x8016E91C: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x8016E920: lwc1        $f4, 0x4($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X4);
    // 0x8016E924: addiu       $t7, $t7, 0x3918
    ctx->r15 = ADD32(ctx->r15, 0X3918);
    // 0x8016E928: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8016E92C: swc1        $f4, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f4.u32l;
    // 0x8016E930: lhu         $t8, 0x62($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X62);
    // 0x8016E934: addiu       $t0, $t0, -0x2A28
    ctx->r8 = ADD32(ctx->r8, -0X2A28);
    // 0x8016E938: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8016E93C: sll         $t1, $t8, 2
    ctx->r9 = S32(ctx->r24 << 2);
    // 0x8016E940: addu        $t1, $t1, $t8
    ctx->r9 = ADD32(ctx->r9, ctx->r24);
    // 0x8016E944: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8016E948: subu        $t1, $t1, $t8
    ctx->r9 = SUB32(ctx->r9, ctx->r24);
    // 0x8016E94C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8016E950: addu        $t1, $t1, $t8
    ctx->r9 = ADD32(ctx->r9, ctx->r24);
    // 0x8016E954: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8016E958: addu        $t2, $t1, $t0
    ctx->r10 = ADD32(ctx->r9, ctx->r8);
    // 0x8016E95C: lw          $t4, 0x34($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X34);
    // 0x8016E960: lw          $t9, 0x50($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X50);
    // 0x8016E964: addiu       $t6, $t6, 0x3918
    ctx->r14 = ADD32(ctx->r14, 0X3918);
    // 0x8016E968: sll         $t3, $t4, 4
    ctx->r11 = S32(ctx->r12 << 4);
    // 0x8016E96C: addu        $t5, $t9, $t3
    ctx->r13 = ADD32(ctx->r25, ctx->r11);
    // 0x8016E970: lwc1        $f6, 0x8($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X8);
    // 0x8016E974: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8016E978: addiu       $t1, $t1, -0x2A28
    ctx->r9 = ADD32(ctx->r9, -0X2A28);
    // 0x8016E97C: swc1        $f6, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->f6.u32l;
    // 0x8016E980: lhu         $t7, 0x62($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X62);
    // 0x8016E984: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8016E988: addiu       $t5, $t5, 0x3918
    ctx->r13 = ADD32(ctx->r13, 0X3918);
    // 0x8016E98C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8016E990: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8016E994: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8016E998: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8016E99C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8016E9A0: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8016E9A4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8016E9A8: addu        $t0, $t8, $t1
    ctx->r8 = ADD32(ctx->r24, ctx->r9);
    // 0x8016E9AC: lw          $t4, 0x34($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X34);
    // 0x8016E9B0: lw          $t2, 0x50($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X50);
    // 0x8016E9B4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8016E9B8: sll         $t9, $t4, 4
    ctx->r25 = S32(ctx->r12 << 4);
    // 0x8016E9BC: addu        $t3, $t2, $t9
    ctx->r11 = ADD32(ctx->r10, ctx->r25);
    // 0x8016E9C0: lwc1        $f8, 0xC($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0XC);
    // 0x8016E9C4: addiu       $t8, $t8, -0x2A28
    ctx->r24 = ADD32(ctx->r24, -0X2A28);
    // 0x8016E9C8: swc1        $f8, 0x24($t5)
    MEM_W(0X24, ctx->r13) = ctx->f8.u32l;
    // 0x8016E9CC: lhu         $t6, 0x62($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X62);
    // 0x8016E9D0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8016E9D4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8016E9D8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8016E9DC: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8016E9E0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8016E9E4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8016E9E8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8016E9EC: addu        $t1, $t7, $t8
    ctx->r9 = ADD32(ctx->r15, ctx->r24);
    // 0x8016E9F0: lw          $t0, 0x34($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X34);
    // 0x8016E9F4: bne         $t0, $zero, L_8016EAB4
    if (ctx->r8 != 0) {
        // 0x8016E9F8: nop
    
            goto L_8016EAB4;
    }
    // 0x8016E9F8: nop

    // 0x8016E9FC: lw          $t4, 0x50($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X50);
    // 0x8016EA00: sll         $t2, $t0, 4
    ctx->r10 = S32(ctx->r8 << 4);
    // 0x8016EA04: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8016EA08: addu        $t9, $t4, $t2
    ctx->r25 = ADD32(ctx->r12, ctx->r10);
    // 0x8016EA0C: lwc1        $f10, 0x4($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X4);
    // 0x8016EA10: addiu       $t3, $t3, 0x3918
    ctx->r11 = ADD32(ctx->r11, 0X3918);
    // 0x8016EA14: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8016EA18: swc1        $f10, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f10.u32l;
    // 0x8016EA1C: lhu         $t5, 0x62($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X62);
    // 0x8016EA20: addiu       $t7, $t7, -0x2A28
    ctx->r15 = ADD32(ctx->r15, -0X2A28);
    // 0x8016EA24: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8016EA28: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8016EA2C: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8016EA30: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8016EA34: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x8016EA38: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8016EA3C: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8016EA40: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8016EA44: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8016EA48: lw          $t0, 0x34($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X34);
    // 0x8016EA4C: lw          $t1, 0x50($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X50);
    // 0x8016EA50: addiu       $t9, $t9, 0x3918
    ctx->r25 = ADD32(ctx->r25, 0X3918);
    // 0x8016EA54: sll         $t4, $t0, 4
    ctx->r12 = S32(ctx->r8 << 4);
    // 0x8016EA58: addu        $t2, $t1, $t4
    ctx->r10 = ADD32(ctx->r9, ctx->r12);
    // 0x8016EA5C: lwc1        $f16, 0x8($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X8);
    // 0x8016EA60: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8016EA64: addiu       $t6, $t6, -0x2A28
    ctx->r14 = ADD32(ctx->r14, -0X2A28);
    // 0x8016EA68: swc1        $f16, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->f16.u32l;
    // 0x8016EA6C: lhu         $t3, 0x62($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X62);
    // 0x8016EA70: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8016EA74: addiu       $t2, $t2, 0x3918
    ctx->r10 = ADD32(ctx->r10, 0X3918);
    // 0x8016EA78: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x8016EA7C: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x8016EA80: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8016EA84: subu        $t5, $t5, $t3
    ctx->r13 = SUB32(ctx->r13, ctx->r11);
    // 0x8016EA88: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8016EA8C: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x8016EA90: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8016EA94: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x8016EA98: lw          $t0, 0x34($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X34);
    // 0x8016EA9C: lw          $t8, 0x50($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X50);
    // 0x8016EAA0: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x8016EAA4: addu        $t4, $t8, $t1
    ctx->r12 = ADD32(ctx->r24, ctx->r9);
    // 0x8016EAA8: lwc1        $f18, 0xC($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0XC);
    // 0x8016EAAC: b           L_8016EB98
    // 0x8016EAB0: swc1        $f18, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->f18.u32l;
        goto L_8016EB98;
    // 0x8016EAB0: swc1        $f18, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->f18.u32l;
L_8016EAB4:
    // 0x8016EAB4: lhu         $t9, 0x62($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X62);
    // 0x8016EAB8: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8016EABC: addiu       $t5, $t5, -0x2A28
    ctx->r13 = ADD32(ctx->r13, -0X2A28);
    // 0x8016EAC0: sll         $t3, $t9, 2
    ctx->r11 = S32(ctx->r25 << 2);
    // 0x8016EAC4: addu        $t3, $t3, $t9
    ctx->r11 = ADD32(ctx->r11, ctx->r25);
    // 0x8016EAC8: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8016EACC: subu        $t3, $t3, $t9
    ctx->r11 = SUB32(ctx->r11, ctx->r25);
    // 0x8016EAD0: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8016EAD4: addu        $t3, $t3, $t9
    ctx->r11 = ADD32(ctx->r11, ctx->r25);
    // 0x8016EAD8: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8016EADC: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x8016EAE0: lw          $t0, 0x34($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X34);
    // 0x8016EAE4: lw          $t7, 0x50($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X50);
    // 0x8016EAE8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8016EAEC: sll         $t8, $t0, 4
    ctx->r24 = S32(ctx->r8 << 4);
    // 0x8016EAF0: addu        $t1, $t7, $t8
    ctx->r9 = ADD32(ctx->r15, ctx->r24);
    // 0x8016EAF4: lwc1        $f4, -0xC($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, -0XC);
    // 0x8016EAF8: addiu       $t4, $t4, 0x3918
    ctx->r12 = ADD32(ctx->r12, 0X3918);
    // 0x8016EAFC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8016EB00: swc1        $f4, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f4.u32l;
    // 0x8016EB04: lhu         $t2, 0x62($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X62);
    // 0x8016EB08: addiu       $t3, $t3, -0x2A28
    ctx->r11 = ADD32(ctx->r11, -0X2A28);
    // 0x8016EB0C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8016EB10: sll         $t9, $t2, 2
    ctx->r25 = S32(ctx->r10 << 2);
    // 0x8016EB14: addu        $t9, $t9, $t2
    ctx->r25 = ADD32(ctx->r25, ctx->r10);
    // 0x8016EB18: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8016EB1C: subu        $t9, $t9, $t2
    ctx->r25 = SUB32(ctx->r25, ctx->r10);
    // 0x8016EB20: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8016EB24: addu        $t9, $t9, $t2
    ctx->r25 = ADD32(ctx->r25, ctx->r10);
    // 0x8016EB28: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8016EB2C: addu        $t5, $t9, $t3
    ctx->r13 = ADD32(ctx->r25, ctx->r11);
    // 0x8016EB30: lw          $t0, 0x34($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X34);
    // 0x8016EB34: lw          $t6, 0x50($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X50);
    // 0x8016EB38: addiu       $t1, $t1, 0x3918
    ctx->r9 = ADD32(ctx->r9, 0X3918);
    // 0x8016EB3C: sll         $t7, $t0, 4
    ctx->r15 = S32(ctx->r8 << 4);
    // 0x8016EB40: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8016EB44: lwc1        $f6, -0x8($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, -0X8);
    // 0x8016EB48: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8016EB4C: addiu       $t9, $t9, -0x2A28
    ctx->r25 = ADD32(ctx->r25, -0X2A28);
    // 0x8016EB50: swc1        $f6, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->f6.u32l;
    // 0x8016EB54: lhu         $t4, 0x62($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X62);
    // 0x8016EB58: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8016EB5C: addiu       $t8, $t8, 0x3918
    ctx->r24 = ADD32(ctx->r24, 0X3918);
    // 0x8016EB60: sll         $t2, $t4, 2
    ctx->r10 = S32(ctx->r12 << 2);
    // 0x8016EB64: addu        $t2, $t2, $t4
    ctx->r10 = ADD32(ctx->r10, ctx->r12);
    // 0x8016EB68: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8016EB6C: subu        $t2, $t2, $t4
    ctx->r10 = SUB32(ctx->r10, ctx->r12);
    // 0x8016EB70: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8016EB74: addu        $t2, $t2, $t4
    ctx->r10 = ADD32(ctx->r10, ctx->r12);
    // 0x8016EB78: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8016EB7C: addu        $t3, $t2, $t9
    ctx->r11 = ADD32(ctx->r10, ctx->r25);
    // 0x8016EB80: lw          $t0, 0x34($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X34);
    // 0x8016EB84: lw          $t5, 0x50($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X50);
    // 0x8016EB88: sll         $t6, $t0, 4
    ctx->r14 = S32(ctx->r8 << 4);
    // 0x8016EB8C: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x8016EB90: lwc1        $f8, -0x4($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, -0X4);
    // 0x8016EB94: swc1        $f8, 0x20($t8)
    MEM_W(0X20, ctx->r24) = ctx->f8.u32l;
L_8016EB98:
    // 0x8016EB98: lhu         $t1, 0x62($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X62);
    // 0x8016EB9C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8016EBA0: addiu       $t2, $t2, -0x2A28
    ctx->r10 = ADD32(ctx->r10, -0X2A28);
    // 0x8016EBA4: sll         $t4, $t1, 2
    ctx->r12 = S32(ctx->r9 << 2);
    // 0x8016EBA8: addu        $t4, $t4, $t1
    ctx->r12 = ADD32(ctx->r12, ctx->r9);
    // 0x8016EBAC: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8016EBB0: subu        $t4, $t4, $t1
    ctx->r12 = SUB32(ctx->r12, ctx->r9);
    // 0x8016EBB4: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8016EBB8: addu        $t4, $t4, $t1
    ctx->r12 = ADD32(ctx->r12, ctx->r9);
    // 0x8016EBBC: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8016EBC0: addu        $t9, $t4, $t2
    ctx->r25 = ADD32(ctx->r12, ctx->r10);
    // 0x8016EBC4: lw          $t0, 0x34($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X34);
    // 0x8016EBC8: lw          $t3, 0x50($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X50);
    // 0x8016EBCC: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8016EBD0: sll         $t5, $t0, 4
    ctx->r13 = S32(ctx->r8 << 4);
    // 0x8016EBD4: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x8016EBD8: lhu         $t7, 0x10($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X10);
    // 0x8016EBDC: bne         $t7, $at, L_8016ED74
    if (ctx->r15 != ctx->r1) {
        // 0x8016EBE0: nop
    
            goto L_8016ED74;
    }
    // 0x8016EBE0: nop

    // 0x8016EBE4: lwc1        $f10, 0x4($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X4);
    // 0x8016EBE8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8016EBEC: addiu       $t8, $t8, 0x3918
    ctx->r24 = ADD32(ctx->r24, 0X3918);
    // 0x8016EBF0: swc1        $f10, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f10.u32l;
    // 0x8016EBF4: lhu         $t1, 0x62($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X62);
    // 0x8016EBF8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8016EBFC: addiu       $t2, $t2, -0x2A28
    ctx->r10 = ADD32(ctx->r10, -0X2A28);
    // 0x8016EC00: sll         $t4, $t1, 2
    ctx->r12 = S32(ctx->r9 << 2);
    // 0x8016EC04: addu        $t4, $t4, $t1
    ctx->r12 = ADD32(ctx->r12, ctx->r9);
    // 0x8016EC08: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8016EC0C: subu        $t4, $t4, $t1
    ctx->r12 = SUB32(ctx->r12, ctx->r9);
    // 0x8016EC10: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8016EC14: addu        $t4, $t4, $t1
    ctx->r12 = ADD32(ctx->r12, ctx->r9);
    // 0x8016EC18: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8016EC1C: addu        $t9, $t4, $t2
    ctx->r25 = ADD32(ctx->r12, ctx->r10);
    // 0x8016EC20: lw          $t3, 0x34($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X34);
    // 0x8016EC24: lw          $t0, 0x50($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X50);
    // 0x8016EC28: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8016EC2C: sll         $t5, $t3, 4
    ctx->r13 = S32(ctx->r11 << 4);
    // 0x8016EC30: addu        $t7, $t0, $t5
    ctx->r15 = ADD32(ctx->r8, ctx->r13);
    // 0x8016EC34: lwc1        $f16, 0x8($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X8);
    // 0x8016EC38: addiu       $t6, $t6, 0x3918
    ctx->r14 = ADD32(ctx->r14, 0X3918);
    // 0x8016EC3C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8016EC40: swc1        $f16, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->f16.u32l;
    // 0x8016EC44: lhu         $t8, 0x62($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X62);
    // 0x8016EC48: addiu       $t4, $t4, -0x2A28
    ctx->r12 = ADD32(ctx->r12, -0X2A28);
    // 0x8016EC4C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8016EC50: sll         $t1, $t8, 2
    ctx->r9 = S32(ctx->r24 << 2);
    // 0x8016EC54: addu        $t1, $t1, $t8
    ctx->r9 = ADD32(ctx->r9, ctx->r24);
    // 0x8016EC58: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8016EC5C: subu        $t1, $t1, $t8
    ctx->r9 = SUB32(ctx->r9, ctx->r24);
    // 0x8016EC60: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8016EC64: addu        $t1, $t1, $t8
    ctx->r9 = ADD32(ctx->r9, ctx->r24);
    // 0x8016EC68: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8016EC6C: addu        $t2, $t1, $t4
    ctx->r10 = ADD32(ctx->r9, ctx->r12);
    // 0x8016EC70: lw          $t3, 0x34($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X34);
    // 0x8016EC74: lw          $t9, 0x50($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X50);
    // 0x8016EC78: addiu       $t7, $t7, 0x3918
    ctx->r15 = ADD32(ctx->r15, 0X3918);
    // 0x8016EC7C: sll         $t0, $t3, 4
    ctx->r8 = S32(ctx->r11 << 4);
    // 0x8016EC80: addu        $t5, $t9, $t0
    ctx->r13 = ADD32(ctx->r25, ctx->r8);
    // 0x8016EC84: lwc1        $f18, 0xC($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0XC);
    // 0x8016EC88: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8016EC8C: addiu       $t1, $t1, -0x2A28
    ctx->r9 = ADD32(ctx->r9, -0X2A28);
    // 0x8016EC90: swc1        $f18, 0x28($t7)
    MEM_W(0X28, ctx->r15) = ctx->f18.u32l;
    // 0x8016EC94: lhu         $t6, 0x62($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X62);
    // 0x8016EC98: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8016EC9C: addiu       $t5, $t5, 0x3918
    ctx->r13 = ADD32(ctx->r13, 0X3918);
    // 0x8016ECA0: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x8016ECA4: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x8016ECA8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8016ECAC: subu        $t8, $t8, $t6
    ctx->r24 = SUB32(ctx->r24, ctx->r14);
    // 0x8016ECB0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8016ECB4: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x8016ECB8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8016ECBC: addu        $t4, $t8, $t1
    ctx->r12 = ADD32(ctx->r24, ctx->r9);
    // 0x8016ECC0: lw          $t3, 0x34($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X34);
    // 0x8016ECC4: lw          $t2, 0x50($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X50);
    // 0x8016ECC8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8016ECCC: sll         $t9, $t3, 4
    ctx->r25 = S32(ctx->r11 << 4);
    // 0x8016ECD0: addu        $t0, $t2, $t9
    ctx->r8 = ADD32(ctx->r10, ctx->r25);
    // 0x8016ECD4: lwc1        $f4, 0x4($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X4);
    // 0x8016ECD8: addiu       $t8, $t8, -0x2A28
    ctx->r24 = ADD32(ctx->r24, -0X2A28);
    // 0x8016ECDC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8016ECE0: swc1        $f4, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f4.u32l;
    // 0x8016ECE4: lhu         $t7, 0x62($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X62);
    // 0x8016ECE8: addiu       $t0, $t0, 0x3918
    ctx->r8 = ADD32(ctx->r8, 0X3918);
    // 0x8016ECEC: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x8016ECF0: addu        $t6, $t6, $t7
    ctx->r14 = ADD32(ctx->r14, ctx->r15);
    // 0x8016ECF4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8016ECF8: subu        $t6, $t6, $t7
    ctx->r14 = SUB32(ctx->r14, ctx->r15);
    // 0x8016ECFC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8016ED00: addu        $t6, $t6, $t7
    ctx->r14 = ADD32(ctx->r14, ctx->r15);
    // 0x8016ED04: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8016ED08: addu        $t1, $t6, $t8
    ctx->r9 = ADD32(ctx->r14, ctx->r24);
    // 0x8016ED0C: lw          $t3, 0x34($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X34);
    // 0x8016ED10: lw          $t4, 0x50($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X50);
    // 0x8016ED14: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8016ED18: sll         $t2, $t3, 4
    ctx->r10 = S32(ctx->r11 << 4);
    // 0x8016ED1C: addu        $t9, $t4, $t2
    ctx->r25 = ADD32(ctx->r12, ctx->r10);
    // 0x8016ED20: lwc1        $f6, 0x8($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X8);
    // 0x8016ED24: addiu       $t6, $t6, -0x2A28
    ctx->r14 = ADD32(ctx->r14, -0X2A28);
    // 0x8016ED28: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8016ED2C: swc1        $f6, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->f6.u32l;
    // 0x8016ED30: lhu         $t5, 0x62($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X62);
    // 0x8016ED34: addiu       $t9, $t9, 0x3918
    ctx->r25 = ADD32(ctx->r25, 0X3918);
    // 0x8016ED38: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x8016ED3C: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x8016ED40: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8016ED44: subu        $t7, $t7, $t5
    ctx->r15 = SUB32(ctx->r15, ctx->r13);
    // 0x8016ED48: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8016ED4C: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x8016ED50: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8016ED54: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x8016ED58: lw          $t3, 0x34($t8)
    ctx->r11 = MEM_W(ctx->r24, 0X34);
    // 0x8016ED5C: lw          $t1, 0x50($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X50);
    // 0x8016ED60: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x8016ED64: addu        $t2, $t1, $t4
    ctx->r10 = ADD32(ctx->r9, ctx->r12);
    // 0x8016ED68: lwc1        $f8, 0xC($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0XC);
    // 0x8016ED6C: b           L_8016F034
    // 0x8016ED70: swc1        $f8, 0x2C($t9)
    MEM_W(0X2C, ctx->r25) = ctx->f8.u32l;
        goto L_8016F034;
    // 0x8016ED70: swc1        $f8, 0x2C($t9)
    MEM_W(0X2C, ctx->r25) = ctx->f8.u32l;
L_8016ED74:
    // 0x8016ED74: lhu         $t0, 0x62($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X62);
    // 0x8016ED78: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8016ED7C: addiu       $t7, $t7, -0x2A28
    ctx->r15 = ADD32(ctx->r15, -0X2A28);
    // 0x8016ED80: sll         $t5, $t0, 2
    ctx->r13 = S32(ctx->r8 << 2);
    // 0x8016ED84: addu        $t5, $t5, $t0
    ctx->r13 = ADD32(ctx->r13, ctx->r8);
    // 0x8016ED88: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8016ED8C: subu        $t5, $t5, $t0
    ctx->r13 = SUB32(ctx->r13, ctx->r8);
    // 0x8016ED90: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8016ED94: addu        $t5, $t5, $t0
    ctx->r13 = ADD32(ctx->r13, ctx->r8);
    // 0x8016ED98: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8016ED9C: addu        $t6, $t5, $t7
    ctx->r14 = ADD32(ctx->r13, ctx->r15);
    // 0x8016EDA0: lw          $t3, 0x34($t6)
    ctx->r11 = MEM_W(ctx->r14, 0X34);
    // 0x8016EDA4: lw          $t8, 0x50($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X50);
    // 0x8016EDA8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8016EDAC: sll         $t1, $t3, 4
    ctx->r9 = S32(ctx->r11 << 4);
    // 0x8016EDB0: addu        $t4, $t8, $t1
    ctx->r12 = ADD32(ctx->r24, ctx->r9);
    // 0x8016EDB4: lwc1        $f10, 0x14($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X14);
    // 0x8016EDB8: addiu       $t2, $t2, 0x3918
    ctx->r10 = ADD32(ctx->r10, 0X3918);
    // 0x8016EDBC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8016EDC0: swc1        $f10, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->f10.u32l;
    // 0x8016EDC4: lhu         $t9, 0x62($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X62);
    // 0x8016EDC8: addiu       $t5, $t5, -0x2A28
    ctx->r13 = ADD32(ctx->r13, -0X2A28);
    // 0x8016EDCC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8016EDD0: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8016EDD4: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8016EDD8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8016EDDC: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x8016EDE0: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8016EDE4: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8016EDE8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8016EDEC: addu        $t7, $t0, $t5
    ctx->r15 = ADD32(ctx->r8, ctx->r13);
    // 0x8016EDF0: lw          $t3, 0x34($t7)
    ctx->r11 = MEM_W(ctx->r15, 0X34);
    // 0x8016EDF4: lw          $t6, 0x50($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X50);
    // 0x8016EDF8: addiu       $t4, $t4, 0x3918
    ctx->r12 = ADD32(ctx->r12, 0X3918);
    // 0x8016EDFC: sll         $t8, $t3, 4
    ctx->r24 = S32(ctx->r11 << 4);
    // 0x8016EE00: addu        $t1, $t6, $t8
    ctx->r9 = ADD32(ctx->r14, ctx->r24);
    // 0x8016EE04: lwc1        $f16, 0x18($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X18);
    // 0x8016EE08: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8016EE0C: addiu       $t0, $t0, -0x2A28
    ctx->r8 = ADD32(ctx->r8, -0X2A28);
    // 0x8016EE10: swc1        $f16, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->f16.u32l;
    // 0x8016EE14: lhu         $t2, 0x62($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X62);
    // 0x8016EE18: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8016EE1C: addiu       $t1, $t1, 0x3918
    ctx->r9 = ADD32(ctx->r9, 0X3918);
    // 0x8016EE20: sll         $t9, $t2, 2
    ctx->r25 = S32(ctx->r10 << 2);
    // 0x8016EE24: addu        $t9, $t9, $t2
    ctx->r25 = ADD32(ctx->r25, ctx->r10);
    // 0x8016EE28: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8016EE2C: subu        $t9, $t9, $t2
    ctx->r25 = SUB32(ctx->r25, ctx->r10);
    // 0x8016EE30: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8016EE34: addu        $t9, $t9, $t2
    ctx->r25 = ADD32(ctx->r25, ctx->r10);
    // 0x8016EE38: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8016EE3C: addu        $t5, $t9, $t0
    ctx->r13 = ADD32(ctx->r25, ctx->r8);
    // 0x8016EE40: lw          $t3, 0x34($t5)
    ctx->r11 = MEM_W(ctx->r13, 0X34);
    // 0x8016EE44: lw          $t7, 0x50($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X50);
    // 0x8016EE48: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8016EE4C: sll         $t6, $t3, 4
    ctx->r14 = S32(ctx->r11 << 4);
    // 0x8016EE50: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x8016EE54: lwc1        $f18, 0x1C($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X1C);
    // 0x8016EE58: addiu       $t9, $t9, -0x2A28
    ctx->r25 = ADD32(ctx->r25, -0X2A28);
    // 0x8016EE5C: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8016EE60: swc1        $f18, 0x28($t1)
    MEM_W(0X28, ctx->r9) = ctx->f18.u32l;
    // 0x8016EE64: lhu         $t4, 0x62($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X62);
    // 0x8016EE68: sll         $t2, $t4, 2
    ctx->r10 = S32(ctx->r12 << 2);
    // 0x8016EE6C: addu        $t2, $t2, $t4
    ctx->r10 = ADD32(ctx->r10, ctx->r12);
    // 0x8016EE70: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8016EE74: subu        $t2, $t2, $t4
    ctx->r10 = SUB32(ctx->r10, ctx->r12);
    // 0x8016EE78: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8016EE7C: addu        $t2, $t2, $t4
    ctx->r10 = ADD32(ctx->r10, ctx->r12);
    // 0x8016EE80: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8016EE84: addu        $t0, $t2, $t9
    ctx->r8 = ADD32(ctx->r10, ctx->r25);
    // 0x8016EE88: lw          $t3, 0x34($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X34);
    // 0x8016EE8C: lw          $t5, 0x50($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X50);
    // 0x8016EE90: sll         $t7, $t3, 4
    ctx->r15 = S32(ctx->r11 << 4);
    // 0x8016EE94: addu        $t6, $t5, $t7
    ctx->r14 = ADD32(ctx->r13, ctx->r15);
    // 0x8016EE98: lhu         $t8, 0x20($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X20);
    // 0x8016EE9C: bne         $t8, $at, L_8016EF50
    if (ctx->r24 != ctx->r1) {
        // 0x8016EEA0: nop
    
            goto L_8016EF50;
    }
    // 0x8016EEA0: nop

    // 0x8016EEA4: lwc1        $f4, 0x14($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X14);
    // 0x8016EEA8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8016EEAC: addiu       $t1, $t1, 0x3918
    ctx->r9 = ADD32(ctx->r9, 0X3918);
    // 0x8016EEB0: swc1        $f4, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f4.u32l;
    // 0x8016EEB4: lhu         $t4, 0x62($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X62);
    // 0x8016EEB8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8016EEBC: addiu       $t9, $t9, -0x2A28
    ctx->r25 = ADD32(ctx->r25, -0X2A28);
    // 0x8016EEC0: sll         $t2, $t4, 2
    ctx->r10 = S32(ctx->r12 << 2);
    // 0x8016EEC4: addu        $t2, $t2, $t4
    ctx->r10 = ADD32(ctx->r10, ctx->r12);
    // 0x8016EEC8: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8016EECC: subu        $t2, $t2, $t4
    ctx->r10 = SUB32(ctx->r10, ctx->r12);
    // 0x8016EED0: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8016EED4: addu        $t2, $t2, $t4
    ctx->r10 = ADD32(ctx->r10, ctx->r12);
    // 0x8016EED8: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8016EEDC: addu        $t0, $t2, $t9
    ctx->r8 = ADD32(ctx->r10, ctx->r25);
    // 0x8016EEE0: lw          $t5, 0x34($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X34);
    // 0x8016EEE4: lw          $t3, 0x50($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X50);
    // 0x8016EEE8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8016EEEC: sll         $t7, $t5, 4
    ctx->r15 = S32(ctx->r13 << 4);
    // 0x8016EEF0: addu        $t8, $t3, $t7
    ctx->r24 = ADD32(ctx->r11, ctx->r15);
    // 0x8016EEF4: lwc1        $f6, 0x18($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X18);
    // 0x8016EEF8: addiu       $t6, $t6, 0x3918
    ctx->r14 = ADD32(ctx->r14, 0X3918);
    // 0x8016EEFC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8016EF00: swc1        $f6, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = ctx->f6.u32l;
    // 0x8016EF04: lhu         $t1, 0x62($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X62);
    // 0x8016EF08: addiu       $t2, $t2, -0x2A28
    ctx->r10 = ADD32(ctx->r10, -0X2A28);
    // 0x8016EF0C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8016EF10: sll         $t4, $t1, 2
    ctx->r12 = S32(ctx->r9 << 2);
    // 0x8016EF14: addu        $t4, $t4, $t1
    ctx->r12 = ADD32(ctx->r12, ctx->r9);
    // 0x8016EF18: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8016EF1C: subu        $t4, $t4, $t1
    ctx->r12 = SUB32(ctx->r12, ctx->r9);
    // 0x8016EF20: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8016EF24: addu        $t4, $t4, $t1
    ctx->r12 = ADD32(ctx->r12, ctx->r9);
    // 0x8016EF28: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8016EF2C: addu        $t9, $t4, $t2
    ctx->r25 = ADD32(ctx->r12, ctx->r10);
    // 0x8016EF30: lw          $t5, 0x34($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X34);
    // 0x8016EF34: lw          $t0, 0x50($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X50);
    // 0x8016EF38: addiu       $t8, $t8, 0x3918
    ctx->r24 = ADD32(ctx->r24, 0X3918);
    // 0x8016EF3C: sll         $t3, $t5, 4
    ctx->r11 = S32(ctx->r13 << 4);
    // 0x8016EF40: addu        $t7, $t0, $t3
    ctx->r15 = ADD32(ctx->r8, ctx->r11);
    // 0x8016EF44: lwc1        $f8, 0x1C($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X1C);
    // 0x8016EF48: b           L_8016F034
    // 0x8016EF4C: swc1        $f8, 0x2C($t8)
    MEM_W(0X2C, ctx->r24) = ctx->f8.u32l;
        goto L_8016F034;
    // 0x8016EF4C: swc1        $f8, 0x2C($t8)
    MEM_W(0X2C, ctx->r24) = ctx->f8.u32l;
L_8016EF50:
    // 0x8016EF50: lhu         $t6, 0x62($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X62);
    // 0x8016EF54: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8016EF58: addiu       $t4, $t4, -0x2A28
    ctx->r12 = ADD32(ctx->r12, -0X2A28);
    // 0x8016EF5C: sll         $t1, $t6, 2
    ctx->r9 = S32(ctx->r14 << 2);
    // 0x8016EF60: addu        $t1, $t1, $t6
    ctx->r9 = ADD32(ctx->r9, ctx->r14);
    // 0x8016EF64: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8016EF68: subu        $t1, $t1, $t6
    ctx->r9 = SUB32(ctx->r9, ctx->r14);
    // 0x8016EF6C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8016EF70: addu        $t1, $t1, $t6
    ctx->r9 = ADD32(ctx->r9, ctx->r14);
    // 0x8016EF74: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8016EF78: addu        $t2, $t1, $t4
    ctx->r10 = ADD32(ctx->r9, ctx->r12);
    // 0x8016EF7C: lw          $t5, 0x34($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X34);
    // 0x8016EF80: lw          $t9, 0x50($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X50);
    // 0x8016EF84: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8016EF88: sll         $t0, $t5, 4
    ctx->r8 = S32(ctx->r13 << 4);
    // 0x8016EF8C: addu        $t3, $t9, $t0
    ctx->r11 = ADD32(ctx->r25, ctx->r8);
    // 0x8016EF90: lwc1        $f10, 0x24($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X24);
    // 0x8016EF94: addiu       $t7, $t7, 0x3918
    ctx->r15 = ADD32(ctx->r15, 0X3918);
    // 0x8016EF98: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8016EF9C: swc1        $f10, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f10.u32l;
    // 0x8016EFA0: lhu         $t8, 0x62($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X62);
    // 0x8016EFA4: addiu       $t1, $t1, -0x2A28
    ctx->r9 = ADD32(ctx->r9, -0X2A28);
    // 0x8016EFA8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8016EFAC: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x8016EFB0: addu        $t6, $t6, $t8
    ctx->r14 = ADD32(ctx->r14, ctx->r24);
    // 0x8016EFB4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8016EFB8: subu        $t6, $t6, $t8
    ctx->r14 = SUB32(ctx->r14, ctx->r24);
    // 0x8016EFBC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8016EFC0: addu        $t6, $t6, $t8
    ctx->r14 = ADD32(ctx->r14, ctx->r24);
    // 0x8016EFC4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8016EFC8: addu        $t4, $t6, $t1
    ctx->r12 = ADD32(ctx->r14, ctx->r9);
    // 0x8016EFCC: lw          $t5, 0x34($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X34);
    // 0x8016EFD0: lw          $t2, 0x50($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X50);
    // 0x8016EFD4: addiu       $t3, $t3, 0x3918
    ctx->r11 = ADD32(ctx->r11, 0X3918);
    // 0x8016EFD8: sll         $t9, $t5, 4
    ctx->r25 = S32(ctx->r13 << 4);
    // 0x8016EFDC: addu        $t0, $t2, $t9
    ctx->r8 = ADD32(ctx->r10, ctx->r25);
    // 0x8016EFE0: lwc1        $f16, 0x28($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X28);
    // 0x8016EFE4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8016EFE8: addiu       $t6, $t6, -0x2A28
    ctx->r14 = ADD32(ctx->r14, -0X2A28);
    // 0x8016EFEC: swc1        $f16, 0x1C($t3)
    MEM_W(0X1C, ctx->r11) = ctx->f16.u32l;
    // 0x8016EFF0: lhu         $t7, 0x62($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X62);
    // 0x8016EFF4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8016EFF8: addiu       $t0, $t0, 0x3918
    ctx->r8 = ADD32(ctx->r8, 0X3918);
    // 0x8016EFFC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8016F000: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8016F004: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8016F008: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8016F00C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8016F010: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8016F014: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8016F018: addu        $t1, $t8, $t6
    ctx->r9 = ADD32(ctx->r24, ctx->r14);
    // 0x8016F01C: lw          $t5, 0x34($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X34);
    // 0x8016F020: lw          $t4, 0x50($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X50);
    // 0x8016F024: sll         $t2, $t5, 4
    ctx->r10 = S32(ctx->r13 << 4);
    // 0x8016F028: addu        $t9, $t4, $t2
    ctx->r25 = ADD32(ctx->r12, ctx->r10);
    // 0x8016F02C: lwc1        $f18, 0x2C($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X2C);
    // 0x8016F030: swc1        $f18, 0x2C($t0)
    MEM_W(0X2C, ctx->r8) = ctx->f18.u32l;
L_8016F034:
    // 0x8016F034: lhu         $t3, 0x62($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X62);
    // 0x8016F038: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8016F03C: addiu       $t8, $t8, -0x2A28
    ctx->r24 = ADD32(ctx->r24, -0X2A28);
    // 0x8016F040: sll         $t7, $t3, 2
    ctx->r15 = S32(ctx->r11 << 2);
    // 0x8016F044: addu        $t7, $t7, $t3
    ctx->r15 = ADD32(ctx->r15, ctx->r11);
    // 0x8016F048: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8016F04C: subu        $t7, $t7, $t3
    ctx->r15 = SUB32(ctx->r15, ctx->r11);
    // 0x8016F050: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8016F054: addu        $t7, $t7, $t3
    ctx->r15 = ADD32(ctx->r15, ctx->r11);
    // 0x8016F058: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8016F05C: addu        $t6, $t7, $t8
    ctx->r14 = ADD32(ctx->r15, ctx->r24);
    // 0x8016F060: lhu         $t1, 0x0($t6)
    ctx->r9 = MEM_HU(ctx->r14, 0X0);
    // 0x8016F064: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8016F068: andi        $t5, $t1, 0x8
    ctx->r13 = ctx->r9 & 0X8;
    // 0x8016F06C: beq         $t5, $at, L_8016F164
    if (ctx->r13 == ctx->r1) {
        // 0x8016F070: nop
    
            goto L_8016F164;
    }
    // 0x8016F070: nop

    // 0x8016F074: lw          $t4, 0x3C($t6)
    ctx->r12 = MEM_W(ctx->r14, 0X3C);
    // 0x8016F078: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x8016F07C: bgez        $t4, L_8016F094
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8016F080: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8016F094;
    }
    // 0x8016F080: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8016F084: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8016F088: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8016F08C: nop

    // 0x8016F090: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8016F094:
    // 0x8016F094: lw          $t2, 0x38($t6)
    ctx->r10 = MEM_W(ctx->r14, 0X38);
    // 0x8016F098: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x8016F09C: bgez        $t2, L_8016F0B4
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8016F0A0: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_8016F0B4;
    }
    // 0x8016F0A0: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8016F0A4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8016F0A8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8016F0AC: nop

    // 0x8016F0B0: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_8016F0B4:
    // 0x8016F0B4: div.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = DIV_S(ctx->f6.fl, ctx->f16.fl);
    // 0x8016F0B8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016F0BC: jal         0x8016D6F0
    // 0x8016F0C0: swc1        $f4, 0x3948($at)
    MEM_W(0X3948, ctx->r1) = ctx->f4.u32l;
    func_8016D6F0_02FC30(rdram, ctx);
        goto after_0;
    // 0x8016F0C0: swc1        $f4, 0x3948($at)
    MEM_W(0X3948, ctx->r1) = ctx->f4.u32l;
    after_0:
    // 0x8016F0C4: lhu         $t9, 0x62($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X62);
    // 0x8016F0C8: lhu         $t3, 0x62($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X62);
    // 0x8016F0CC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016F0D0: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8016F0D4: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8016F0D8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8016F0DC: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x8016F0E0: lwc1        $f8, 0x394C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X394C);
    // 0x8016F0E4: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8016F0E8: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8016F0EC: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8016F0F0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016F0F4: sll         $t7, $t3, 2
    ctx->r15 = S32(ctx->r11 << 2);
    // 0x8016F0F8: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x8016F0FC: addu        $t7, $t7, $t3
    ctx->r15 = ADD32(ctx->r15, ctx->r11);
    // 0x8016F100: lhu         $t8, 0x62($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X62);
    // 0x8016F104: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8016F108: swc1        $f8, -0x29C8($at)
    MEM_W(-0X29C8, ctx->r1) = ctx->f8.u32l;
    // 0x8016F10C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016F110: subu        $t7, $t7, $t3
    ctx->r15 = SUB32(ctx->r15, ctx->r11);
    // 0x8016F114: lwc1        $f10, 0x3950($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X3950);
    // 0x8016F118: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8016F11C: addu        $t7, $t7, $t3
    ctx->r15 = ADD32(ctx->r15, ctx->r11);
    // 0x8016F120: sll         $t1, $t8, 2
    ctx->r9 = S32(ctx->r24 << 2);
    // 0x8016F124: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8016F128: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016F12C: addu        $t1, $t1, $t8
    ctx->r9 = ADD32(ctx->r9, ctx->r24);
    // 0x8016F130: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8016F134: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8016F138: subu        $t1, $t1, $t8
    ctx->r9 = SUB32(ctx->r9, ctx->r24);
    // 0x8016F13C: swc1        $f10, -0x29C4($at)
    MEM_W(-0X29C4, ctx->r1) = ctx->f10.u32l;
    // 0x8016F140: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016F144: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8016F148: lwc1        $f18, 0x3954($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X3954);
    // 0x8016F14C: addu        $t1, $t1, $t8
    ctx->r9 = ADD32(ctx->r9, ctx->r24);
    // 0x8016F150: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8016F154: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016F158: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8016F15C: b           L_8016F27C
    // 0x8016F160: swc1        $f18, -0x29C0($at)
    MEM_W(-0X29C0, ctx->r1) = ctx->f18.u32l;
        goto L_8016F27C;
    // 0x8016F160: swc1        $f18, -0x29C0($at)
    MEM_W(-0X29C0, ctx->r1) = ctx->f18.u32l;
L_8016F164:
    // 0x8016F164: lhu         $t5, 0x62($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X62);
    // 0x8016F168: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8016F16C: addiu       $t6, $t6, -0x2A28
    ctx->r14 = ADD32(ctx->r14, -0X2A28);
    // 0x8016F170: sll         $t4, $t5, 2
    ctx->r12 = S32(ctx->r13 << 2);
    // 0x8016F174: addu        $t4, $t4, $t5
    ctx->r12 = ADD32(ctx->r12, ctx->r13);
    // 0x8016F178: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8016F17C: subu        $t4, $t4, $t5
    ctx->r12 = SUB32(ctx->r12, ctx->r13);
    // 0x8016F180: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8016F184: addu        $t4, $t4, $t5
    ctx->r12 = ADD32(ctx->r12, ctx->r13);
    // 0x8016F188: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8016F18C: addu        $t2, $t4, $t6
    ctx->r10 = ADD32(ctx->r12, ctx->r14);
    // 0x8016F190: lw          $t9, 0x3C($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X3C);
    // 0x8016F194: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x8016F198: bgez        $t9, L_8016F1B0
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8016F19C: cvt.s.w     $f16, $f6
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
            goto L_8016F1B0;
    }
    // 0x8016F19C: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8016F1A0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8016F1A4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8016F1A8: nop

    // 0x8016F1AC: add.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f4.fl;
L_8016F1B0:
    // 0x8016F1B0: lw          $t0, 0x38($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X38);
    // 0x8016F1B4: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x8016F1B8: bgez        $t0, L_8016F1D0
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8016F1BC: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_8016F1D0;
    }
    // 0x8016F1BC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8016F1C0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8016F1C4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8016F1C8: nop

    // 0x8016F1CC: add.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f18.fl;
L_8016F1D0:
    // 0x8016F1D0: div.s       $f6, $f16, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = DIV_S(ctx->f16.fl, ctx->f10.fl);
    // 0x8016F1D4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016F1D8: jal         0x8016D6F0
    // 0x8016F1DC: swc1        $f6, 0x3948($at)
    MEM_W(0X3948, ctx->r1) = ctx->f6.u32l;
    func_8016D6F0_02FC30(rdram, ctx);
        goto after_1;
    // 0x8016F1DC: swc1        $f6, 0x3948($at)
    MEM_W(0X3948, ctx->r1) = ctx->f6.u32l;
    after_1:
    // 0x8016F1E0: lhu         $t3, 0x62($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X62);
    // 0x8016F1E4: lhu         $t8, 0x62($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X62);
    // 0x8016F1E8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016F1EC: sll         $t7, $t3, 2
    ctx->r15 = S32(ctx->r11 << 2);
    // 0x8016F1F0: addu        $t7, $t7, $t3
    ctx->r15 = ADD32(ctx->r15, ctx->r11);
    // 0x8016F1F4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8016F1F8: subu        $t7, $t7, $t3
    ctx->r15 = SUB32(ctx->r15, ctx->r11);
    // 0x8016F1FC: lwc1        $f4, 0x394C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X394C);
    // 0x8016F200: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8016F204: addu        $t7, $t7, $t3
    ctx->r15 = ADD32(ctx->r15, ctx->r11);
    // 0x8016F208: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8016F20C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016F210: sll         $t1, $t8, 2
    ctx->r9 = S32(ctx->r24 << 2);
    // 0x8016F214: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8016F218: addu        $t1, $t1, $t8
    ctx->r9 = ADD32(ctx->r9, ctx->r24);
    // 0x8016F21C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8016F220: swc1        $f4, -0x29BC($at)
    MEM_W(-0X29BC, ctx->r1) = ctx->f4.u32l;
    // 0x8016F224: lhu         $t5, 0x62($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X62);
    // 0x8016F228: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016F22C: subu        $t1, $t1, $t8
    ctx->r9 = SUB32(ctx->r9, ctx->r24);
    // 0x8016F230: lwc1        $f8, 0x3950($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X3950);
    // 0x8016F234: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8016F238: addu        $t1, $t1, $t8
    ctx->r9 = ADD32(ctx->r9, ctx->r24);
    // 0x8016F23C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8016F240: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016F244: sll         $t4, $t5, 2
    ctx->r12 = S32(ctx->r13 << 2);
    // 0x8016F248: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8016F24C: addu        $t4, $t4, $t5
    ctx->r12 = ADD32(ctx->r12, ctx->r13);
    // 0x8016F250: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8016F254: swc1        $f8, -0x29B8($at)
    MEM_W(-0X29B8, ctx->r1) = ctx->f8.u32l;
    // 0x8016F258: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016F25C: subu        $t4, $t4, $t5
    ctx->r12 = SUB32(ctx->r12, ctx->r13);
    // 0x8016F260: lwc1        $f18, 0x3954($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X3954);
    // 0x8016F264: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8016F268: addu        $t4, $t4, $t5
    ctx->r12 = ADD32(ctx->r12, ctx->r13);
    // 0x8016F26C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8016F270: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016F274: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x8016F278: swc1        $f18, -0x29B4($at)
    MEM_W(-0X29B4, ctx->r1) = ctx->f18.u32l;
L_8016F27C:
    // 0x8016F27C: lhu         $t6, 0x62($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X62);
    // 0x8016F280: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8016F284: addiu       $t2, $t2, -0x2A28
    ctx->r10 = ADD32(ctx->r10, -0X2A28);
    // 0x8016F288: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x8016F28C: addu        $t9, $t9, $t6
    ctx->r25 = ADD32(ctx->r25, ctx->r14);
    // 0x8016F290: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8016F294: subu        $t9, $t9, $t6
    ctx->r25 = SUB32(ctx->r25, ctx->r14);
    // 0x8016F298: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8016F29C: addu        $t9, $t9, $t6
    ctx->r25 = ADD32(ctx->r25, ctx->r14);
    // 0x8016F2A0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8016F2A4: addu        $t0, $t9, $t2
    ctx->r8 = ADD32(ctx->r25, ctx->r10);
    // 0x8016F2A8: lw          $t3, 0x3C($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X3C);
    // 0x8016F2AC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8016F2B0: addiu       $t5, $t5, -0x2A28
    ctx->r13 = ADD32(ctx->r13, -0X2A28);
    // 0x8016F2B4: addiu       $t7, $t3, 0x1
    ctx->r15 = ADD32(ctx->r11, 0X1);
    // 0x8016F2B8: sw          $t7, 0x3C($t0)
    MEM_W(0X3C, ctx->r8) = ctx->r15;
    // 0x8016F2BC: lhu         $t8, 0x62($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X62);
    // 0x8016F2C0: sll         $t1, $t8, 2
    ctx->r9 = S32(ctx->r24 << 2);
    // 0x8016F2C4: addu        $t1, $t1, $t8
    ctx->r9 = ADD32(ctx->r9, ctx->r24);
    // 0x8016F2C8: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8016F2CC: subu        $t1, $t1, $t8
    ctx->r9 = SUB32(ctx->r9, ctx->r24);
    // 0x8016F2D0: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8016F2D4: addu        $t1, $t1, $t8
    ctx->r9 = ADD32(ctx->r9, ctx->r24);
    // 0x8016F2D8: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8016F2DC: addu        $t4, $t1, $t5
    ctx->r12 = ADD32(ctx->r9, ctx->r13);
    // 0x8016F2E0: lw          $t6, 0x38($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X38);
    // 0x8016F2E4: lw          $t9, 0x3C($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X3C);
    // 0x8016F2E8: bne         $t6, $t9, L_8016F304
    if (ctx->r14 != ctx->r25) {
        // 0x8016F2EC: nop
    
            goto L_8016F304;
    }
    // 0x8016F2EC: nop

    // 0x8016F2F0: lw          $t2, 0x34($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X34);
    // 0x8016F2F4: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8016F2F8: sw          $t3, 0x34($t4)
    MEM_W(0X34, ctx->r12) = ctx->r11;
    // 0x8016F2FC: jal         0x8016F67C
    // 0x8016F300: lhu         $a0, 0x62($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X62);
    func_8016F67C_02FC30(rdram, ctx);
        goto after_2;
    // 0x8016F300: lhu         $a0, 0x62($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X62);
    after_2:
L_8016F304:
    // 0x8016F304: jal         0x801705CC
    // 0x8016F308: lhu         $a0, 0x62($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X62);
    func_801705CC_02FC30(rdram, ctx);
        goto after_3;
    // 0x8016F308: lhu         $a0, 0x62($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X62);
    after_3:
    // 0x8016F30C: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8016F310: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8016F314: nop

    // 0x8016F318: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8016F31C: nop

    // 0x8016F320: bc1f        L_8016F364
    if (!c1cs) {
        // 0x8016F324: nop
    
            goto L_8016F364;
    }
    // 0x8016F324: nop

    // 0x8016F328: lhu         $t7, 0x62($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X62);
    // 0x8016F32C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8016F330: addiu       $t8, $t8, -0x2A28
    ctx->r24 = ADD32(ctx->r24, -0X2A28);
    // 0x8016F334: sll         $t0, $t7, 2
    ctx->r8 = S32(ctx->r15 << 2);
    // 0x8016F338: addu        $t0, $t0, $t7
    ctx->r8 = ADD32(ctx->r8, ctx->r15);
    // 0x8016F33C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8016F340: subu        $t0, $t0, $t7
    ctx->r8 = SUB32(ctx->r8, ctx->r15);
    // 0x8016F344: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8016F348: addu        $t0, $t0, $t7
    ctx->r8 = ADD32(ctx->r8, ctx->r15);
    // 0x8016F34C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8016F350: addu        $t1, $t0, $t8
    ctx->r9 = ADD32(ctx->r8, ctx->r24);
    // 0x8016F354: lhu         $t5, 0x0($t1)
    ctx->r13 = MEM_HU(ctx->r9, 0X0);
    // 0x8016F358: ori         $t6, $t5, 0x800
    ctx->r14 = ctx->r13 | 0X800;
    // 0x8016F35C: b           L_8016F3A0
    // 0x8016F360: sh          $t6, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r14;
        goto L_8016F3A0;
    // 0x8016F360: sh          $t6, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r14;
L_8016F364:
    // 0x8016F364: lhu         $t9, 0x62($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X62);
    // 0x8016F368: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8016F36C: addiu       $t3, $t3, -0x2A28
    ctx->r11 = ADD32(ctx->r11, -0X2A28);
    // 0x8016F370: sll         $t2, $t9, 2
    ctx->r10 = S32(ctx->r25 << 2);
    // 0x8016F374: addu        $t2, $t2, $t9
    ctx->r10 = ADD32(ctx->r10, ctx->r25);
    // 0x8016F378: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8016F37C: subu        $t2, $t2, $t9
    ctx->r10 = SUB32(ctx->r10, ctx->r25);
    // 0x8016F380: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8016F384: addu        $t2, $t2, $t9
    ctx->r10 = ADD32(ctx->r10, ctx->r25);
    // 0x8016F388: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8016F38C: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8016F390: lhu         $t7, 0x0($t4)
    ctx->r15 = MEM_HU(ctx->r12, 0X0);
    // 0x8016F394: addiu       $at, $zero, -0x801
    ctx->r1 = ADD32(0, -0X801);
    // 0x8016F398: and         $t0, $t7, $at
    ctx->r8 = ctx->r15 & ctx->r1;
    // 0x8016F39C: sh          $t0, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r8;
L_8016F3A0:
    // 0x8016F3A0: lhu         $t8, 0x62($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X62);
    // 0x8016F3A4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8016F3A8: addiu       $t6, $t6, -0x2A28
    ctx->r14 = ADD32(ctx->r14, -0X2A28);
    // 0x8016F3AC: sll         $t5, $t8, 2
    ctx->r13 = S32(ctx->r24 << 2);
    // 0x8016F3B0: addu        $t5, $t5, $t8
    ctx->r13 = ADD32(ctx->r13, ctx->r24);
    // 0x8016F3B4: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8016F3B8: subu        $t5, $t5, $t8
    ctx->r13 = SUB32(ctx->r13, ctx->r24);
    // 0x8016F3BC: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8016F3C0: addu        $t5, $t5, $t8
    ctx->r13 = ADD32(ctx->r13, ctx->r24);
    // 0x8016F3C4: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8016F3C8: addu        $t1, $t5, $t6
    ctx->r9 = ADD32(ctx->r13, ctx->r14);
    // 0x8016F3CC: lhu         $t9, 0x0($t1)
    ctx->r25 = MEM_HU(ctx->r9, 0X0);
    // 0x8016F3D0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8016F3D4: andi        $t2, $t9, 0x2
    ctx->r10 = ctx->r25 & 0X2;
    // 0x8016F3D8: beq         $t2, $at, L_8016F578
    if (ctx->r10 == ctx->r1) {
        // 0x8016F3DC: nop
    
            goto L_8016F578;
    }
    // 0x8016F3DC: nop

    // 0x8016F3E0: andi        $t3, $t9, 0x8
    ctx->r11 = ctx->r25 & 0X8;
    // 0x8016F3E4: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8016F3E8: beq         $t3, $at, L_8016F454
    if (ctx->r11 == ctx->r1) {
        // 0x8016F3EC: nop
    
            goto L_8016F454;
    }
    // 0x8016F3EC: nop

    // 0x8016F3F0: lwc1        $f10, 0x84($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X84);
    // 0x8016F3F4: lw          $a1, 0x78($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X78);
    // 0x8016F3F8: lw          $a2, 0x7C($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X7C);
    // 0x8016F3FC: lw          $a3, 0x80($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X80);
    // 0x8016F400: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x8016F404: jal         0x800D7120
    // 0x8016F408: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    guAlignF_recomp(rdram, ctx);
        goto after_4;
    // 0x8016F408: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_4:
    // 0x8016F40C: lhu         $t7, 0x62($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X62);
    // 0x8016F410: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8016F414: addiu       $t8, $t8, -0x2A28
    ctx->r24 = ADD32(ctx->r24, -0X2A28);
    // 0x8016F418: sll         $t0, $t7, 2
    ctx->r8 = S32(ctx->r15 << 2);
    // 0x8016F41C: addu        $t0, $t0, $t7
    ctx->r8 = ADD32(ctx->r8, ctx->r15);
    // 0x8016F420: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8016F424: subu        $t0, $t0, $t7
    ctx->r8 = SUB32(ctx->r8, ctx->r15);
    // 0x8016F428: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8016F42C: addu        $t0, $t0, $t7
    ctx->r8 = ADD32(ctx->r8, ctx->r15);
    // 0x8016F430: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8016F434: addiu       $t4, $t0, 0xA4
    ctx->r12 = ADD32(ctx->r8, 0XA4);
    // 0x8016F438: addiu       $t5, $t0, 0xA4
    ctx->r13 = ADD32(ctx->r8, 0XA4);
    // 0x8016F43C: addu        $a2, $t5, $t8
    ctx->r6 = ADD32(ctx->r13, ctx->r24);
    // 0x8016F440: addu        $a0, $t4, $t8
    ctx->r4 = ADD32(ctx->r12, ctx->r24);
    // 0x8016F444: jal         0x800D6F30
    // 0x8016F448: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    guMtxCatF_recomp(rdram, ctx);
        goto after_5;
    // 0x8016F448: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_5:
    // 0x8016F44C: b           L_8016F4DC
    // 0x8016F450: nop

        goto L_8016F4DC;
    // 0x8016F450: nop

L_8016F454:
    // 0x8016F454: lhu         $t6, 0x62($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X62);
    // 0x8016F458: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8016F45C: addiu       $t9, $t9, -0x2A28
    ctx->r25 = ADD32(ctx->r25, -0X2A28);
    // 0x8016F460: sll         $t2, $t6, 2
    ctx->r10 = S32(ctx->r14 << 2);
    // 0x8016F464: addu        $t2, $t2, $t6
    ctx->r10 = ADD32(ctx->r10, ctx->r14);
    // 0x8016F468: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8016F46C: subu        $t2, $t2, $t6
    ctx->r10 = SUB32(ctx->r10, ctx->r14);
    // 0x8016F470: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8016F474: addu        $t2, $t2, $t6
    ctx->r10 = ADD32(ctx->r10, ctx->r14);
    // 0x8016F478: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8016F47C: addu        $t3, $t2, $t9
    ctx->r11 = ADD32(ctx->r10, ctx->r25);
    // 0x8016F480: lwc1        $f6, 0x84($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X84);
    // 0x8016F484: lw          $a1, 0x78($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X78);
    // 0x8016F488: lw          $a2, 0x7C($t3)
    ctx->r6 = MEM_W(ctx->r11, 0X7C);
    // 0x8016F48C: lw          $a3, 0x80($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X80);
    // 0x8016F490: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x8016F494: jal         0x800D7120
    // 0x8016F498: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    guAlignF_recomp(rdram, ctx);
        goto after_6;
    // 0x8016F498: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_6:
    // 0x8016F49C: lhu         $t1, 0x62($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X62);
    // 0x8016F4A0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8016F4A4: addiu       $t0, $t0, -0x2A28
    ctx->r8 = ADD32(ctx->r8, -0X2A28);
    // 0x8016F4A8: sll         $t7, $t1, 2
    ctx->r15 = S32(ctx->r9 << 2);
    // 0x8016F4AC: addu        $t7, $t7, $t1
    ctx->r15 = ADD32(ctx->r15, ctx->r9);
    // 0x8016F4B0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8016F4B4: subu        $t7, $t7, $t1
    ctx->r15 = SUB32(ctx->r15, ctx->r9);
    // 0x8016F4B8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8016F4BC: addu        $t7, $t7, $t1
    ctx->r15 = ADD32(ctx->r15, ctx->r9);
    // 0x8016F4C0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8016F4C4: addiu       $t4, $t7, 0xE4
    ctx->r12 = ADD32(ctx->r15, 0XE4);
    // 0x8016F4C8: addiu       $t5, $t7, 0xE4
    ctx->r13 = ADD32(ctx->r15, 0XE4);
    // 0x8016F4CC: addu        $a2, $t5, $t0
    ctx->r6 = ADD32(ctx->r13, ctx->r8);
    // 0x8016F4D0: addu        $a0, $t4, $t0
    ctx->r4 = ADD32(ctx->r12, ctx->r8);
    // 0x8016F4D4: jal         0x800D6F30
    // 0x8016F4D8: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    guMtxCatF_recomp(rdram, ctx);
        goto after_7;
    // 0x8016F4D8: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_7:
L_8016F4DC:
    // 0x8016F4DC: lhu         $t8, 0x62($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X62);
    // 0x8016F4E0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8016F4E4: addiu       $t2, $t2, -0x2A28
    ctx->r10 = ADD32(ctx->r10, -0X2A28);
    // 0x8016F4E8: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x8016F4EC: addu        $t6, $t6, $t8
    ctx->r14 = ADD32(ctx->r14, ctx->r24);
    // 0x8016F4F0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8016F4F4: subu        $t6, $t6, $t8
    ctx->r14 = SUB32(ctx->r14, ctx->r24);
    // 0x8016F4F8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8016F4FC: addu        $t6, $t6, $t8
    ctx->r14 = ADD32(ctx->r14, ctx->r24);
    // 0x8016F500: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8016F504: addu        $t9, $t6, $t2
    ctx->r25 = ADD32(ctx->r14, ctx->r10);
    // 0x8016F508: lw          $t3, 0x48($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X48);
    // 0x8016F50C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8016F510: addiu       $t5, $t5, -0x2A28
    ctx->r13 = ADD32(ctx->r13, -0X2A28);
    // 0x8016F514: addiu       $t1, $t3, 0x1
    ctx->r9 = ADD32(ctx->r11, 0X1);
    // 0x8016F518: sw          $t1, 0x48($t9)
    MEM_W(0X48, ctx->r25) = ctx->r9;
    // 0x8016F51C: lhu         $t4, 0x62($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X62);
    // 0x8016F520: sll         $t7, $t4, 2
    ctx->r15 = S32(ctx->r12 << 2);
    // 0x8016F524: addu        $t7, $t7, $t4
    ctx->r15 = ADD32(ctx->r15, ctx->r12);
    // 0x8016F528: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8016F52C: subu        $t7, $t7, $t4
    ctx->r15 = SUB32(ctx->r15, ctx->r12);
    // 0x8016F530: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8016F534: addu        $t7, $t7, $t4
    ctx->r15 = ADD32(ctx->r15, ctx->r12);
    // 0x8016F538: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8016F53C: addu        $t0, $t7, $t5
    ctx->r8 = ADD32(ctx->r15, ctx->r13);
    // 0x8016F540: lw          $t6, 0x40($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X40);
    // 0x8016F544: lw          $t8, 0x54($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X54);
    // 0x8016F548: lw          $t9, 0x24($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X24);
    // 0x8016F54C: sll         $t2, $t6, 2
    ctx->r10 = S32(ctx->r14 << 2);
    // 0x8016F550: addu        $t2, $t2, $t6
    ctx->r10 = ADD32(ctx->r10, ctx->r14);
    // 0x8016F554: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8016F558: addu        $t3, $t8, $t2
    ctx->r11 = ADD32(ctx->r24, ctx->r10);
    // 0x8016F55C: lhu         $t1, 0x0($t3)
    ctx->r9 = MEM_HU(ctx->r11, 0X0);
    // 0x8016F560: bne         $t1, $t9, L_8016F578
    if (ctx->r9 != ctx->r25) {
        // 0x8016F564: nop
    
            goto L_8016F578;
    }
    // 0x8016F564: nop

    // 0x8016F568: addiu       $t4, $t6, 0x1
    ctx->r12 = ADD32(ctx->r14, 0X1);
    // 0x8016F56C: sw          $t4, 0x40($t0)
    MEM_W(0X40, ctx->r8) = ctx->r12;
    // 0x8016F570: jal         0x8016F7F8
    // 0x8016F574: lhu         $a0, 0x62($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X62);
    func_8016F7F8_02FC30(rdram, ctx);
        goto after_8;
    // 0x8016F574: lhu         $a0, 0x62($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X62);
    after_8:
L_8016F578:
    // 0x8016F578: lhu         $t7, 0x62($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X62);
    // 0x8016F57C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8016F580: addiu       $t8, $t8, -0x2A28
    ctx->r24 = ADD32(ctx->r24, -0X2A28);
    // 0x8016F584: sll         $t5, $t7, 2
    ctx->r13 = S32(ctx->r15 << 2);
    // 0x8016F588: addu        $t5, $t5, $t7
    ctx->r13 = ADD32(ctx->r13, ctx->r15);
    // 0x8016F58C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8016F590: subu        $t5, $t5, $t7
    ctx->r13 = SUB32(ctx->r13, ctx->r15);
    // 0x8016F594: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8016F598: addu        $t5, $t5, $t7
    ctx->r13 = ADD32(ctx->r13, ctx->r15);
    // 0x8016F59C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8016F5A0: addu        $t2, $t5, $t8
    ctx->r10 = ADD32(ctx->r13, ctx->r24);
    // 0x8016F5A4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8016F5A8: lw          $t1, -0x2E34($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2E34);
    // 0x8016F5AC: lw          $t3, 0x18($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X18);
    // 0x8016F5B0: sltu        $at, $t1, $t3
    ctx->r1 = ctx->r9 < ctx->r11 ? 1 : 0;
    // 0x8016F5B4: bne         $at, $zero, L_8016F5D0
    if (ctx->r1 != 0) {
        // 0x8016F5B8: nop
    
            goto L_8016F5D0;
    }
    // 0x8016F5B8: nop

    // 0x8016F5BC: lhu         $t9, 0x0($t2)
    ctx->r25 = MEM_HU(ctx->r10, 0X0);
    // 0x8016F5C0: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8016F5C4: ori         $at, $at, 0x7FFF
    ctx->r1 = ctx->r1 | 0X7FFF;
    // 0x8016F5C8: and         $t6, $t9, $at
    ctx->r14 = ctx->r25 & ctx->r1;
    // 0x8016F5CC: sh          $t6, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r14;
L_8016F5D0:
    // 0x8016F5D0: lhu         $t4, 0x62($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X62);
    // 0x8016F5D4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8016F5D8: addiu       $t7, $t7, -0x2A28
    ctx->r15 = ADD32(ctx->r15, -0X2A28);
    // 0x8016F5DC: sll         $t0, $t4, 2
    ctx->r8 = S32(ctx->r12 << 2);
    // 0x8016F5E0: addu        $t0, $t0, $t4
    ctx->r8 = ADD32(ctx->r8, ctx->r12);
    // 0x8016F5E4: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8016F5E8: subu        $t0, $t0, $t4
    ctx->r8 = SUB32(ctx->r8, ctx->r12);
    // 0x8016F5EC: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8016F5F0: addu        $t0, $t0, $t4
    ctx->r8 = ADD32(ctx->r8, ctx->r12);
    // 0x8016F5F4: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8016F5F8: addu        $t5, $t0, $t7
    ctx->r13 = ADD32(ctx->r8, ctx->r15);
    // 0x8016F5FC: lhu         $t8, 0x0($t5)
    ctx->r24 = MEM_HU(ctx->r13, 0X0);
    // 0x8016F600: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8016F604: andi        $t3, $t8, 0x8
    ctx->r11 = ctx->r24 & 0X8;
    // 0x8016F608: bne         $t3, $at, L_8016F61C
    if (ctx->r11 != ctx->r1) {
        // 0x8016F60C: nop
    
            goto L_8016F61C;
    }
    // 0x8016F60C: nop

    // 0x8016F610: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x8016F614: jal         0x801703AC
    // 0x8016F618: lw          $a1, 0x14($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X14);
    func_801703AC_02FC30(rdram, ctx);
        goto after_9;
    // 0x8016F618: lw          $a1, 0x14($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X14);
    after_9:
L_8016F61C:
    // 0x8016F61C: lhu         $t1, 0x62($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X62);
    // 0x8016F620: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8016F624: addiu       $t6, $t6, -0x2A28
    ctx->r14 = ADD32(ctx->r14, -0X2A28);
    // 0x8016F628: sll         $t9, $t1, 2
    ctx->r25 = S32(ctx->r9 << 2);
    // 0x8016F62C: addu        $t9, $t9, $t1
    ctx->r25 = ADD32(ctx->r25, ctx->r9);
    // 0x8016F630: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8016F634: subu        $t9, $t9, $t1
    ctx->r25 = SUB32(ctx->r25, ctx->r9);
    // 0x8016F638: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8016F63C: addu        $t9, $t9, $t1
    ctx->r25 = ADD32(ctx->r25, ctx->r9);
    // 0x8016F640: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8016F644: addu        $t2, $t9, $t6
    ctx->r10 = ADD32(ctx->r25, ctx->r14);
    // 0x8016F648: lw          $t0, 0x24($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X24);
    // 0x8016F64C: addiu       $t7, $t0, 0x1
    ctx->r15 = ADD32(ctx->r8, 0X1);
    // 0x8016F650: sw          $t7, 0x24($t2)
    MEM_W(0X24, ctx->r10) = ctx->r15;
L_8016F654:
    // 0x8016F654: lhu         $t8, 0x62($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X62);
    // 0x8016F658: addiu       $t3, $t8, 0x1
    ctx->r11 = ADD32(ctx->r24, 0X1);
    // 0x8016F65C: andi        $t4, $t3, 0xFFFF
    ctx->r12 = ctx->r11 & 0XFFFF;
    // 0x8016F660: slti        $at, $t4, 0x30
    ctx->r1 = SIGNED(ctx->r12) < 0X30 ? 1 : 0;
    // 0x8016F664: bne         $at, $zero, L_8016E8BC
    if (ctx->r1 != 0) {
        // 0x8016F668: sh          $t3, 0x62($sp)
        MEM_H(0X62, ctx->r29) = ctx->r11;
            goto L_8016E8BC;
    }
    // 0x8016F668: sh          $t3, 0x62($sp)
    MEM_H(0X62, ctx->r29) = ctx->r11;
    // 0x8016F66C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8016F670: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x8016F674: jr          $ra
    // 0x8016F678: nop

    return;
    // 0x8016F678: nop

;}
RECOMP_FUNC void func_8016F67C_02FC30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016F67C: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x8016F680: sll         $t0, $a0, 2
    ctx->r8 = S32(ctx->r4 << 2);
    // 0x8016F684: addu        $t0, $t0, $a0
    ctx->r8 = ADD32(ctx->r8, ctx->r4);
    // 0x8016F688: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8016F68C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8016F690: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8016F694: subu        $t0, $t0, $a0
    ctx->r8 = SUB32(ctx->r8, ctx->r4);
    // 0x8016F698: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8016F69C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8016F6A0: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x8016F6A4: addu        $t0, $t0, $a0
    ctx->r8 = ADD32(ctx->r8, ctx->r4);
    // 0x8016F6A8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8016F6AC: addiu       $t7, $t7, -0x2A28
    ctx->r15 = ADD32(ctx->r15, -0X2A28);
    // 0x8016F6B0: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8016F6B4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8016F6B8: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8016F6BC: addu        $t1, $t0, $t7
    ctx->r9 = ADD32(ctx->r8, ctx->r15);
    // 0x8016F6C0: lw          $t2, 0x34($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X34);
    // 0x8016F6C4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8016F6C8: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8016F6CC: lw          $t9, 0x50($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X50);
    // 0x8016F6D0: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x8016F6D4: addu        $t1, $t1, $a0
    ctx->r9 = ADD32(ctx->r9, ctx->r4);
    // 0x8016F6D8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8016F6DC: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8016F6E0: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8016F6E4: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x8016F6E8: subu        $t1, $t1, $a0
    ctx->r9 = SUB32(ctx->r9, ctx->r4);
    // 0x8016F6EC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8016F6F0: addu        $t4, $t9, $t3
    ctx->r12 = ADD32(ctx->r25, ctx->r11);
    // 0x8016F6F4: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x8016F6F8: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x8016F6FC: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8016F700: addu        $t1, $t1, $a0
    ctx->r9 = ADD32(ctx->r9, ctx->r4);
    // 0x8016F704: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8016F708: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8016F70C: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8016F710: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8016F714: addu        $t2, $t1, $t7
    ctx->r10 = ADD32(ctx->r9, ctx->r15);
    // 0x8016F718: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8016F71C: sh          $t5, 0x6($sp)
    MEM_H(0X6, ctx->r29) = ctx->r13;
    // 0x8016F720: lw          $t9, 0x34($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X34);
    // 0x8016F724: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8016F728: lw          $t0, 0x50($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X50);
    // 0x8016F72C: sll         $t3, $t9, 4
    ctx->r11 = S32(ctx->r25 << 4);
    // 0x8016F730: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8016F734: addu        $t4, $t0, $t3
    ctx->r12 = ADD32(ctx->r8, ctx->r11);
    // 0x8016F738: lhu         $t5, 0x10($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X10);
    // 0x8016F73C: bne         $t5, $at, L_8016F794
    if (ctx->r13 != ctx->r1) {
        // 0x8016F740: sh          $t5, 0x4($sp)
        MEM_H(0X4, ctx->r29) = ctx->r13;
            goto L_8016F794;
    }
    // 0x8016F740: sh          $t5, 0x4($sp)
    MEM_H(0X4, ctx->r29) = ctx->r13;
    // 0x8016F744: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8016F748: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8016F74C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8016F750: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x8016F754: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8016F758: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x8016F75C: addu        $t9, $t9, $a0
    ctx->r25 = ADD32(ctx->r25, ctx->r4);
    // 0x8016F760: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8016F764: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8016F768: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8016F76C: subu        $t9, $t9, $a0
    ctx->r25 = SUB32(ctx->r25, ctx->r4);
    // 0x8016F770: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8016F774: lhu         $t1, 0x0($t8)
    ctx->r9 = MEM_HU(ctx->r24, 0X0);
    // 0x8016F778: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8016F77C: addu        $t9, $t9, $a0
    ctx->r25 = ADD32(ctx->r25, ctx->r4);
    // 0x8016F780: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8016F784: addu        $t0, $t9, $t7
    ctx->r8 = ADD32(ctx->r25, ctx->r15);
    // 0x8016F788: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x8016F78C: b           L_8016F7F0
    // 0x8016F790: sh          $t2, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r10;
        goto L_8016F7F0;
    // 0x8016F790: sh          $t2, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r10;
L_8016F794:
    // 0x8016F794: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8016F798: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8016F79C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8016F7A0: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x8016F7A4: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x8016F7A8: lhu         $t3, 0x4($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X4);
    // 0x8016F7AC: lhu         $t4, 0x6($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X6);
    // 0x8016F7B0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8016F7B4: addu        $t8, $t8, $a0
    ctx->r24 = ADD32(ctx->r24, ctx->r4);
    // 0x8016F7B8: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8016F7BC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8016F7C0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8016F7C4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016F7C8: subu        $t8, $t8, $a0
    ctx->r24 = SUB32(ctx->r24, ctx->r4);
    // 0x8016F7CC: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8016F7D0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8016F7D4: subu        $t5, $t3, $t4
    ctx->r13 = SUB32(ctx->r11, ctx->r12);
    // 0x8016F7D8: sw          $t5, -0x29F0($at)
    MEM_W(-0X29F0, ctx->r1) = ctx->r13;
    // 0x8016F7DC: addu        $t8, $t8, $a0
    ctx->r24 = ADD32(ctx->r24, ctx->r4);
    // 0x8016F7E0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8016F7E4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016F7E8: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8016F7EC: sw          $zero, -0x29EC($at)
    MEM_W(-0X29EC, ctx->r1) = 0;
L_8016F7F0:
    // 0x8016F7F0: jr          $ra
    // 0x8016F7F4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8016F7F4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8016F7F8_02FC30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016F7F8: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x8016F7FC: sll         $t0, $a0, 2
    ctx->r8 = S32(ctx->r4 << 2);
    // 0x8016F800: addu        $t0, $t0, $a0
    ctx->r8 = ADD32(ctx->r8, ctx->r4);
    // 0x8016F804: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8016F808: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8016F80C: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8016F810: subu        $t0, $t0, $a0
    ctx->r8 = SUB32(ctx->r8, ctx->r4);
    // 0x8016F814: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8016F818: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8016F81C: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x8016F820: addu        $t0, $t0, $a0
    ctx->r8 = ADD32(ctx->r8, ctx->r4);
    // 0x8016F824: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8016F828: addiu       $t7, $t7, -0x2A28
    ctx->r15 = ADD32(ctx->r15, -0X2A28);
    // 0x8016F82C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8016F830: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8016F834: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8016F838: addu        $t1, $t0, $t7
    ctx->r9 = ADD32(ctx->r8, ctx->r15);
    // 0x8016F83C: lw          $t2, 0x40($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X40);
    // 0x8016F840: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8016F844: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8016F848: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8016F84C: lw          $t9, 0x54($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X54);
    // 0x8016F850: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8016F854: sll         $t0, $a0, 2
    ctx->r8 = S32(ctx->r4 << 2);
    // 0x8016F858: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8016F85C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8016F860: addu        $t0, $t0, $a0
    ctx->r8 = ADD32(ctx->r8, ctx->r4);
    // 0x8016F864: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8016F868: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8016F86C: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x8016F870: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8016F874: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8016F878: subu        $t0, $t0, $a0
    ctx->r8 = SUB32(ctx->r8, ctx->r4);
    // 0x8016F87C: addu        $t4, $t9, $t3
    ctx->r12 = ADD32(ctx->r25, ctx->r11);
    // 0x8016F880: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x8016F884: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8016F888: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8016F88C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8016F890: addu        $t0, $t0, $a0
    ctx->r8 = ADD32(ctx->r8, ctx->r4);
    // 0x8016F894: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8016F898: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8016F89C: addiu       $t1, $t1, -0x2A28
    ctx->r9 = ADD32(ctx->r9, -0X2A28);
    // 0x8016F8A0: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8016F8A4: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8016F8A8: sw          $t5, 0x44($t8)
    MEM_W(0X44, ctx->r24) = ctx->r13;
    // 0x8016F8AC: lw          $t9, 0x44($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X44);
    // 0x8016F8B0: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8016F8B4: bne         $t9, $at, L_8016F90C
    if (ctx->r25 != ctx->r1) {
        // 0x8016F8B8: nop
    
            goto L_8016F90C;
    }
    // 0x8016F8B8: nop

    // 0x8016F8BC: sll         $t3, $a0, 2
    ctx->r11 = S32(ctx->r4 << 2);
    // 0x8016F8C0: addu        $t3, $t3, $a0
    ctx->r11 = ADD32(ctx->r11, ctx->r4);
    // 0x8016F8C4: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8016F8C8: subu        $t3, $t3, $a0
    ctx->r11 = SUB32(ctx->r11, ctx->r4);
    // 0x8016F8CC: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8016F8D0: sll         $t5, $a0, 2
    ctx->r13 = S32(ctx->r4 << 2);
    // 0x8016F8D4: addu        $t5, $t5, $a0
    ctx->r13 = ADD32(ctx->r13, ctx->r4);
    // 0x8016F8D8: addu        $t3, $t3, $a0
    ctx->r11 = ADD32(ctx->r11, ctx->r4);
    // 0x8016F8DC: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8016F8E0: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8016F8E4: subu        $t5, $t5, $a0
    ctx->r13 = SUB32(ctx->r13, ctx->r4);
    // 0x8016F8E8: addu        $t4, $t3, $t1
    ctx->r12 = ADD32(ctx->r11, ctx->r9);
    // 0x8016F8EC: lhu         $t6, 0x0($t4)
    ctx->r14 = MEM_HU(ctx->r12, 0X0);
    // 0x8016F8F0: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8016F8F4: addu        $t5, $t5, $a0
    ctx->r13 = ADD32(ctx->r13, ctx->r4);
    // 0x8016F8F8: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8016F8FC: addu        $t8, $t5, $t1
    ctx->r24 = ADD32(ctx->r13, ctx->r9);
    // 0x8016F900: ori         $t7, $t6, 0x2
    ctx->r15 = ctx->r14 | 0X2;
    // 0x8016F904: jr          $ra
    // 0x8016F908: sh          $t7, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r15;
    return;
    // 0x8016F908: sh          $t7, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r15;
L_8016F90C:
    // 0x8016F90C: sll         $t0, $a0, 2
    ctx->r8 = S32(ctx->r4 << 2);
    // 0x8016F910: sll         $t4, $a0, 2
    ctx->r12 = S32(ctx->r4 << 2);
    // 0x8016F914: addu        $t4, $t4, $a0
    ctx->r12 = ADD32(ctx->r12, ctx->r4);
    // 0x8016F918: addu        $t0, $t0, $a0
    ctx->r8 = ADD32(ctx->r8, ctx->r4);
    // 0x8016F91C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8016F920: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8016F924: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x8016F928: addu        $t8, $t8, $a0
    ctx->r24 = ADD32(ctx->r24, ctx->r4);
    // 0x8016F92C: subu        $t4, $t4, $a0
    ctx->r12 = SUB32(ctx->r12, ctx->r4);
    // 0x8016F930: subu        $t0, $t0, $a0
    ctx->r8 = SUB32(ctx->r8, ctx->r4);
    // 0x8016F934: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8016F938: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8016F93C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8016F940: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8016F944: addiu       $t2, $t2, -0x2A28
    ctx->r10 = ADD32(ctx->r10, -0X2A28);
    // 0x8016F948: subu        $t8, $t8, $a0
    ctx->r24 = SUB32(ctx->r24, ctx->r4);
    // 0x8016F94C: addu        $t4, $t4, $a0
    ctx->r12 = ADD32(ctx->r12, ctx->r4);
    // 0x8016F950: addu        $t0, $t0, $a0
    ctx->r8 = ADD32(ctx->r8, ctx->r4);
    // 0x8016F954: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8016F958: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8016F95C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8016F960: addu        $t8, $t8, $a0
    ctx->r24 = ADD32(ctx->r24, ctx->r4);
    // 0x8016F964: addu        $t6, $t4, $t2
    ctx->r14 = ADD32(ctx->r12, ctx->r10);
    // 0x8016F968: addu        $t9, $t0, $t2
    ctx->r25 = ADD32(ctx->r8, ctx->r10);
    // 0x8016F96C: lw          $t5, 0x40($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X40);
    // 0x8016F970: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8016F974: lw          $t3, 0x54($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X54);
    // 0x8016F978: addu        $t0, $t8, $t2
    ctx->r8 = ADD32(ctx->r24, ctx->r10);
    // 0x8016F97C: lw          $t9, 0x44($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X44);
    // 0x8016F980: sll         $t1, $t5, 2
    ctx->r9 = S32(ctx->r13 << 2);
    // 0x8016F984: addu        $t1, $t1, $t5
    ctx->r9 = ADD32(ctx->r9, ctx->r13);
    // 0x8016F988: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x8016F98C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8016F990: addu        $t7, $t3, $t1
    ctx->r15 = ADD32(ctx->r11, ctx->r9);
    // 0x8016F994: lwc1        $f4, 0x4($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X4);
    // 0x8016F998: bgez        $t9, L_8016F9B0
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8016F99C: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_8016F9B0;
    }
    // 0x8016F99C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8016F9A0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8016F9A4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8016F9A8: nop

    // 0x8016F9AC: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_8016F9B0:
    // 0x8016F9B0: sll         $t4, $a0, 2
    ctx->r12 = S32(ctx->r4 << 2);
    // 0x8016F9B4: addu        $t4, $t4, $a0
    ctx->r12 = ADD32(ctx->r12, ctx->r4);
    // 0x8016F9B8: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8016F9BC: subu        $t4, $t4, $a0
    ctx->r12 = SUB32(ctx->r12, ctx->r4);
    // 0x8016F9C0: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8016F9C4: addu        $t4, $t4, $a0
    ctx->r12 = ADD32(ctx->r12, ctx->r4);
    // 0x8016F9C8: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8016F9CC: addu        $t6, $t4, $t2
    ctx->r14 = ADD32(ctx->r12, ctx->r10);
    // 0x8016F9D0: lw          $t5, 0x24($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X24);
    // 0x8016F9D4: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x8016F9D8: bgez        $t5, L_8016F9F0
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8016F9DC: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_8016F9F0;
    }
    // 0x8016F9DC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8016F9E0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8016F9E4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8016F9E8: nop

    // 0x8016F9EC: add.s       $f18, $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f6.fl;
L_8016F9F0:
    // 0x8016F9F0: sub.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x8016F9F4: sll         $t3, $a0, 2
    ctx->r11 = S32(ctx->r4 << 2);
    // 0x8016F9F8: addu        $t3, $t3, $a0
    ctx->r11 = ADD32(ctx->r11, ctx->r4);
    // 0x8016F9FC: sll         $t4, $a0, 2
    ctx->r12 = S32(ctx->r4 << 2);
    // 0x8016FA00: div.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8016FA04: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8016FA08: addu        $t4, $t4, $a0
    ctx->r12 = ADD32(ctx->r12, ctx->r4);
    // 0x8016FA0C: subu        $t3, $t3, $a0
    ctx->r11 = SUB32(ctx->r11, ctx->r4);
    // 0x8016FA10: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8016FA14: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8016FA18: subu        $t4, $t4, $a0
    ctx->r12 = SUB32(ctx->r12, ctx->r4);
    // 0x8016FA1C: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x8016FA20: addu        $t3, $t3, $a0
    ctx->r11 = ADD32(ctx->r11, ctx->r4);
    // 0x8016FA24: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x8016FA28: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8016FA2C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8016FA30: addu        $t4, $t4, $a0
    ctx->r12 = ADD32(ctx->r12, ctx->r4);
    // 0x8016FA34: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8016FA38: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8016FA3C: addu        $t1, $t3, $t2
    ctx->r9 = ADD32(ctx->r11, ctx->r10);
    // 0x8016FA40: addiu       $t8, $t8, -0x2A28
    ctx->r24 = ADD32(ctx->r24, -0X2A28);
    // 0x8016FA44: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x8016FA48: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8016FA4C: addu        $t6, $t4, $t8
    ctx->r14 = ADD32(ctx->r12, ctx->r24);
    // 0x8016FA50: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8016FA54: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x8016FA58: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8016FA5C: swc1        $f16, 0x78($t1)
    MEM_W(0X78, ctx->r9) = ctx->f16.u32l;
    // 0x8016FA60: lw          $t5, 0x40($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X40);
    // 0x8016FA64: addu        $t0, $t7, $t8
    ctx->r8 = ADD32(ctx->r15, ctx->r24);
    // 0x8016FA68: lw          $t9, 0x54($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X54);
    // 0x8016FA6C: sll         $t3, $t5, 2
    ctx->r11 = S32(ctx->r13 << 2);
    // 0x8016FA70: addu        $t3, $t3, $t5
    ctx->r11 = ADD32(ctx->r11, ctx->r13);
    // 0x8016FA74: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8016FA78: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x8016FA7C: addu        $t2, $t9, $t3
    ctx->r10 = ADD32(ctx->r25, ctx->r11);
    // 0x8016FA80: addu        $t1, $t1, $a0
    ctx->r9 = ADD32(ctx->r9, ctx->r4);
    // 0x8016FA84: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x8016FA88: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8016FA8C: addu        $t9, $t9, $a0
    ctx->r25 = ADD32(ctx->r25, ctx->r4);
    // 0x8016FA90: subu        $t1, $t1, $a0
    ctx->r9 = SUB32(ctx->r9, ctx->r4);
    // 0x8016FA94: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8016FA98: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8016FA9C: subu        $t9, $t9, $a0
    ctx->r25 = SUB32(ctx->r25, ctx->r4);
    // 0x8016FAA0: sll         $t0, $a0, 2
    ctx->r8 = S32(ctx->r4 << 2);
    // 0x8016FAA4: lwc1        $f6, 0x8($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X8);
    // 0x8016FAA8: addu        $t1, $t1, $a0
    ctx->r9 = ADD32(ctx->r9, ctx->r4);
    // 0x8016FAAC: addu        $t0, $t0, $a0
    ctx->r8 = ADD32(ctx->r8, ctx->r4);
    // 0x8016FAB0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8016FAB4: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8016FAB8: addu        $t9, $t9, $a0
    ctx->r25 = ADD32(ctx->r25, ctx->r4);
    // 0x8016FABC: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8016FAC0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8016FAC4: addu        $t7, $t1, $t8
    ctx->r15 = ADD32(ctx->r9, ctx->r24);
    // 0x8016FAC8: addiu       $t4, $t4, -0x2A28
    ctx->r12 = ADD32(ctx->r12, -0X2A28);
    // 0x8016FACC: subu        $t0, $t0, $a0
    ctx->r8 = SUB32(ctx->r8, ctx->r4);
    // 0x8016FAD0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8016FAD4: addu        $t3, $t9, $t4
    ctx->r11 = ADD32(ctx->r25, ctx->r12);
    // 0x8016FAD8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8016FADC: swc1        $f6, 0x7C($t7)
    MEM_W(0X7C, ctx->r15) = ctx->f6.u32l;
    // 0x8016FAE0: lw          $t2, 0x40($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X40);
    // 0x8016FAE4: addu        $t0, $t0, $a0
    ctx->r8 = ADD32(ctx->r8, ctx->r4);
    // 0x8016FAE8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8016FAEC: addu        $t6, $t0, $t4
    ctx->r14 = ADD32(ctx->r8, ctx->r12);
    // 0x8016FAF0: lw          $t5, 0x54($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X54);
    // 0x8016FAF4: sll         $t1, $t2, 2
    ctx->r9 = S32(ctx->r10 << 2);
    // 0x8016FAF8: addu        $t1, $t1, $t2
    ctx->r9 = ADD32(ctx->r9, ctx->r10);
    // 0x8016FAFC: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8016FB00: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x8016FB04: addu        $t8, $t5, $t1
    ctx->r24 = ADD32(ctx->r13, ctx->r9);
    // 0x8016FB08: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x8016FB0C: sll         $t5, $a0, 2
    ctx->r13 = S32(ctx->r4 << 2);
    // 0x8016FB10: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8016FB14: addu        $t5, $t5, $a0
    ctx->r13 = ADD32(ctx->r13, ctx->r4);
    // 0x8016FB18: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x8016FB1C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8016FB20: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8016FB24: subu        $t5, $t5, $a0
    ctx->r13 = SUB32(ctx->r13, ctx->r4);
    // 0x8016FB28: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8016FB2C: lwc1        $f8, 0xC($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0XC);
    // 0x8016FB30: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x8016FB34: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8016FB38: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8016FB3C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8016FB40: addu        $t5, $t5, $a0
    ctx->r13 = ADD32(ctx->r13, ctx->r4);
    // 0x8016FB44: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8016FB48: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8016FB4C: addu        $t0, $t7, $t4
    ctx->r8 = ADD32(ctx->r15, ctx->r12);
    // 0x8016FB50: addiu       $t9, $t9, -0x2A28
    ctx->r25 = ADD32(ctx->r25, -0X2A28);
    // 0x8016FB54: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x8016FB58: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8016FB5C: addu        $t1, $t5, $t9
    ctx->r9 = ADD32(ctx->r13, ctx->r25);
    // 0x8016FB60: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8016FB64: swc1        $f8, 0x80($t0)
    MEM_W(0X80, ctx->r8) = ctx->f8.u32l;
    // 0x8016FB68: lw          $t8, 0x40($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X40);
    // 0x8016FB6C: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8016FB70: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8016FB74: addu        $t3, $t6, $t9
    ctx->r11 = ADD32(ctx->r14, ctx->r25);
    // 0x8016FB78: sll         $t0, $a0, 2
    ctx->r8 = S32(ctx->r4 << 2);
    // 0x8016FB7C: lw          $t2, 0x54($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X54);
    // 0x8016FB80: addu        $t0, $t0, $a0
    ctx->r8 = ADD32(ctx->r8, ctx->r4);
    // 0x8016FB84: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x8016FB88: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8016FB8C: addu        $t7, $t7, $t8
    ctx->r15 = ADD32(ctx->r15, ctx->r24);
    // 0x8016FB90: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8016FB94: subu        $t0, $t0, $a0
    ctx->r8 = SUB32(ctx->r8, ctx->r4);
    // 0x8016FB98: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8016FB9C: addu        $t4, $t2, $t7
    ctx->r12 = ADD32(ctx->r10, ctx->r15);
    // 0x8016FBA0: lwc1        $f18, 0x10($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X10);
    // 0x8016FBA4: addu        $t0, $t0, $a0
    ctx->r8 = ADD32(ctx->r8, ctx->r4);
    // 0x8016FBA8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8016FBAC: addu        $t6, $t0, $t9
    ctx->r14 = ADD32(ctx->r8, ctx->r25);
    // 0x8016FBB0: swc1        $f18, 0x84($t6)
    MEM_W(0X84, ctx->r14) = ctx->f18.u32l;
    // 0x8016FBB4: jr          $ra
    // 0x8016FBB8: nop

    return;
    // 0x8016FBB8: nop

;}
RECOMP_FUNC void func_8016FBBC_02FC30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016FBBC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8016FBC0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
L_8016FBC4:
    // 0x8016FBC4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8016FBC8: lw          $t6, -0x2D8C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2D8C);
    // 0x8016FBCC: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x8016FBD0: beq         $t7, $zero, L_8017039C
    if (ctx->r15 == 0) {
        // 0x8016FBD4: nop
    
            goto L_8017039C;
    }
    // 0x8016FBD4: nop

    // 0x8016FBD8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8016FBDC: lw          $t8, -0x2D8C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2D8C);
    // 0x8016FBE0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8016FBE4: lw          $t0, -0x2E34($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2E34);
    // 0x8016FBE8: lhu         $t9, 0x2($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X2);
    // 0x8016FBEC: bne         $t9, $t0, L_8017039C
    if (ctx->r25 != ctx->r8) {
        // 0x8016FBF0: nop
    
            goto L_8017039C;
    }
    // 0x8016FBF0: nop

    // 0x8016FBF4: lhu         $t1, 0x6($t8)
    ctx->r9 = MEM_HU(ctx->r24, 0X6);
    // 0x8016FBF8: sh          $zero, 0x26($sp)
    MEM_H(0X26, ctx->r29) = 0;
    // 0x8016FBFC: sh          $t1, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r9;
L_8016FC00:
    // 0x8016FC00: lhu         $t2, 0x26($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X26);
    // 0x8016FC04: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8016FC08: addiu       $t4, $t4, -0x2A28
    ctx->r12 = ADD32(ctx->r12, -0X2A28);
    // 0x8016FC0C: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8016FC10: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8016FC14: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8016FC18: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x8016FC1C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8016FC20: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8016FC24: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8016FC28: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8016FC2C: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x8016FC30: andi        $t7, $t6, 0x8000
    ctx->r15 = ctx->r14 & 0X8000;
    // 0x8016FC34: beq         $t7, $zero, L_8016FC50
    if (ctx->r15 == 0) {
        // 0x8016FC38: nop
    
            goto L_8016FC50;
    }
    // 0x8016FC38: nop

    // 0x8016FC3C: lw          $t9, 0x4($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X4);
    // 0x8016FC40: lhu         $t0, 0x24($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X24);
    // 0x8016FC44: bne         $t9, $t0, L_8016FC50
    if (ctx->r25 != ctx->r8) {
        // 0x8016FC48: nop
    
            goto L_8016FC50;
    }
    // 0x8016FC48: nop

    // 0x8016FC4C: sh          $zero, 0x24($sp)
    MEM_H(0X24, ctx->r29) = 0;
L_8016FC50:
    // 0x8016FC50: lhu         $t8, 0x26($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X26);
    // 0x8016FC54: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8016FC58: sll         $t1, $t8, 2
    ctx->r9 = S32(ctx->r24 << 2);
    // 0x8016FC5C: addu        $t1, $t1, $t8
    ctx->r9 = ADD32(ctx->r9, ctx->r24);
    // 0x8016FC60: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8016FC64: subu        $t1, $t1, $t8
    ctx->r9 = SUB32(ctx->r9, ctx->r24);
    // 0x8016FC68: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8016FC6C: addu        $t1, $t1, $t8
    ctx->r9 = ADD32(ctx->r9, ctx->r24);
    // 0x8016FC70: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8016FC74: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8016FC78: lhu         $t2, -0x2A28($t2)
    ctx->r10 = MEM_HU(ctx->r10, -0X2A28);
    // 0x8016FC7C: andi        $t3, $t2, 0x8000
    ctx->r11 = ctx->r10 & 0X8000;
    // 0x8016FC80: bne         $t3, $zero, L_8016FC94
    if (ctx->r11 != 0) {
        // 0x8016FC84: nop
    
            goto L_8016FC94;
    }
    // 0x8016FC84: nop

    // 0x8016FC88: lhu         $t4, 0x24($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X24);
    // 0x8016FC8C: beq         $t4, $zero, L_8016FCAC
    if (ctx->r12 == 0) {
        // 0x8016FC90: nop
    
            goto L_8016FCAC;
    }
    // 0x8016FC90: nop

L_8016FC94:
    // 0x8016FC94: lhu         $t6, 0x26($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X26);
    // 0x8016FC98: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8016FC9C: andi        $t5, $t7, 0xFFFF
    ctx->r13 = ctx->r15 & 0XFFFF;
    // 0x8016FCA0: slti        $at, $t5, 0x30
    ctx->r1 = SIGNED(ctx->r13) < 0X30 ? 1 : 0;
    // 0x8016FCA4: bne         $at, $zero, L_8016FC00
    if (ctx->r1 != 0) {
        // 0x8016FCA8: sh          $t7, 0x26($sp)
        MEM_H(0X26, ctx->r29) = ctx->r15;
            goto L_8016FC00;
    }
    // 0x8016FCA8: sh          $t7, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r15;
L_8016FCAC:
    // 0x8016FCAC: lhu         $t8, 0x26($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X26);
    // 0x8016FCB0: lhu         $t3, 0x26($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X26);
    // 0x8016FCB4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8016FCB8: sll         $t1, $t8, 2
    ctx->r9 = S32(ctx->r24 << 2);
    // 0x8016FCBC: addu        $t1, $t1, $t8
    ctx->r9 = ADD32(ctx->r9, ctx->r24);
    // 0x8016FCC0: lw          $t9, -0x2D8C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2D8C);
    // 0x8016FCC4: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8016FCC8: subu        $t1, $t1, $t8
    ctx->r9 = SUB32(ctx->r9, ctx->r24);
    // 0x8016FCCC: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8016FCD0: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8016FCD4: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8016FCD8: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x8016FCDC: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8016FCE0: addu        $t1, $t1, $t8
    ctx->r9 = ADD32(ctx->r9, ctx->r24);
    // 0x8016FCE4: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8016FCE8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016FCEC: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x8016FCF0: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8016FCF4: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8016FCF8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8016FCFC: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8016FD00: sw          $t0, -0x2A24($at)
    MEM_W(-0X2A24, ctx->r1) = ctx->r8;
    // 0x8016FD04: lw          $t6, -0x2D8C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2D8C);
    // 0x8016FD08: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016FD0C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8016FD10: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x8016FD14: ori         $t2, $zero, 0x8000
    ctx->r10 = 0 | 0X8000;
    // 0x8016FD18: sh          $t2, -0x2A28($at)
    MEM_H(-0X2A28, ctx->r1) = ctx->r10;
    // 0x8016FD1C: lhu         $t7, 0x6($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X6);
    // 0x8016FD20: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8016FD24: sh          $t7, 0x6($t6)
    MEM_H(0X6, ctx->r14) = ctx->r15;
    // 0x8016FD28: lw          $t5, -0x2D8C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2D8C);
    // 0x8016FD2C: lhu         $t9, 0x6($t5)
    ctx->r25 = MEM_HU(ctx->r13, 0X6);
    // 0x8016FD30: beq         $t9, $zero, L_8016FD70
    if (ctx->r25 == 0) {
        // 0x8016FD34: nop
    
            goto L_8016FD70;
    }
    // 0x8016FD34: nop

    // 0x8016FD38: lhu         $t8, 0x26($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X26);
    // 0x8016FD3C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8016FD40: addiu       $t1, $t1, -0x2A28
    ctx->r9 = ADD32(ctx->r9, -0X2A28);
    // 0x8016FD44: sll         $t0, $t8, 2
    ctx->r8 = S32(ctx->r24 << 2);
    // 0x8016FD48: addu        $t0, $t0, $t8
    ctx->r8 = ADD32(ctx->r8, ctx->r24);
    // 0x8016FD4C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8016FD50: subu        $t0, $t0, $t8
    ctx->r8 = SUB32(ctx->r8, ctx->r24);
    // 0x8016FD54: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8016FD58: addu        $t0, $t0, $t8
    ctx->r8 = ADD32(ctx->r8, ctx->r24);
    // 0x8016FD5C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8016FD60: addu        $t3, $t0, $t1
    ctx->r11 = ADD32(ctx->r8, ctx->r9);
    // 0x8016FD64: lhu         $t2, 0x0($t3)
    ctx->r10 = MEM_HU(ctx->r11, 0X0);
    // 0x8016FD68: ori         $t4, $t2, 0x8
    ctx->r12 = ctx->r10 | 0X8;
    // 0x8016FD6C: sh          $t4, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r12;
L_8016FD70:
    // 0x8016FD70: lhu         $t7, 0x26($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X26);
    // 0x8016FD74: lhu         $t8, 0x26($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X26);
    // 0x8016FD78: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8016FD7C: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x8016FD80: addu        $t6, $t6, $t7
    ctx->r14 = ADD32(ctx->r14, ctx->r15);
    // 0x8016FD84: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8016FD88: subu        $t6, $t6, $t7
    ctx->r14 = SUB32(ctx->r14, ctx->r15);
    // 0x8016FD8C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8016FD90: sll         $t0, $t8, 2
    ctx->r8 = S32(ctx->r24 << 2);
    // 0x8016FD94: addu        $t6, $t6, $t7
    ctx->r14 = ADD32(ctx->r14, ctx->r15);
    // 0x8016FD98: addu        $t0, $t0, $t8
    ctx->r8 = ADD32(ctx->r8, ctx->r24);
    // 0x8016FD9C: lw          $t5, -0x2D8C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2D8C);
    // 0x8016FDA0: lhu         $t4, 0x26($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X26);
    // 0x8016FDA4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8016FDA8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016FDAC: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8016FDB0: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8016FDB4: subu        $t0, $t0, $t8
    ctx->r8 = SUB32(ctx->r8, ctx->r24);
    // 0x8016FDB8: sw          $zero, -0x2A04($at)
    MEM_W(-0X2A04, ctx->r1) = 0;
    // 0x8016FDBC: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8016FDC0: lhu         $t7, 0x26($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X26);
    // 0x8016FDC4: lhu         $t9, 0x4($t5)
    ctx->r25 = MEM_HU(ctx->r13, 0X4);
    // 0x8016FDC8: addu        $t0, $t0, $t8
    ctx->r8 = ADD32(ctx->r8, ctx->r24);
    // 0x8016FDCC: sll         $t3, $t4, 2
    ctx->r11 = S32(ctx->r12 << 2);
    // 0x8016FDD0: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8016FDD4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016FDD8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8016FDDC: addu        $t3, $t3, $t4
    ctx->r11 = ADD32(ctx->r11, ctx->r12);
    // 0x8016FDE0: lw          $t1, -0x2D8C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2D8C);
    // 0x8016FDE4: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x8016FDE8: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8016FDEC: lhu         $t5, 0x26($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X26);
    // 0x8016FDF0: subu        $t3, $t3, $t4
    ctx->r11 = SUB32(ctx->r11, ctx->r12);
    // 0x8016FDF4: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x8016FDF8: sw          $t9, -0x2A10($at)
    MEM_W(-0X2A10, ctx->r1) = ctx->r25;
    // 0x8016FDFC: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8016FE00: addu        $t6, $t6, $t7
    ctx->r14 = ADD32(ctx->r14, ctx->r15);
    // 0x8016FE04: lhu         $t2, 0x6($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X6);
    // 0x8016FE08: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8016FE0C: addu        $t3, $t3, $t4
    ctx->r11 = ADD32(ctx->r11, ctx->r12);
    // 0x8016FE10: lhu         $t9, 0x26($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X26);
    // 0x8016FE14: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8016FE18: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016FE1C: subu        $t6, $t6, $t7
    ctx->r14 = SUB32(ctx->r14, ctx->r15);
    // 0x8016FE20: sll         $t8, $t5, 2
    ctx->r24 = S32(ctx->r13 << 2);
    // 0x8016FE24: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x8016FE28: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8016FE2C: addu        $t8, $t8, $t5
    ctx->r24 = ADD32(ctx->r24, ctx->r13);
    // 0x8016FE30: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8016FE34: addu        $t6, $t6, $t7
    ctx->r14 = ADD32(ctx->r14, ctx->r15);
    // 0x8016FE38: sw          $t2, -0x2A20($at)
    MEM_W(-0X2A20, ctx->r1) = ctx->r10;
    // 0x8016FE3C: lhu         $t1, 0x26($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X26);
    // 0x8016FE40: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016FE44: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8016FE48: subu        $t8, $t8, $t5
    ctx->r24 = SUB32(ctx->r24, ctx->r13);
    // 0x8016FE4C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8016FE50: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8016FE54: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8016FE58: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8016FE5C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8016FE60: sw          $t7, -0x2A14($at)
    MEM_W(-0X2A14, ctx->r1) = ctx->r15;
    // 0x8016FE64: addu        $t8, $t8, $t5
    ctx->r24 = ADD32(ctx->r24, ctx->r13);
    // 0x8016FE68: lhu         $t3, 0x26($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X26);
    // 0x8016FE6C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8016FE70: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016FE74: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x8016FE78: sll         $t4, $t1, 2
    ctx->r12 = S32(ctx->r9 << 2);
    // 0x8016FE7C: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8016FE80: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8016FE84: addu        $t4, $t4, $t1
    ctx->r12 = ADD32(ctx->r12, ctx->r9);
    // 0x8016FE88: sw          $zero, -0x29F4($at)
    MEM_W(-0X29F4, ctx->r1) = 0;
    // 0x8016FE8C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8016FE90: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8016FE94: lhu         $t6, 0x26($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X26);
    // 0x8016FE98: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8016FE9C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016FEA0: subu        $t4, $t4, $t1
    ctx->r12 = SUB32(ctx->r12, ctx->r9);
    // 0x8016FEA4: sll         $t7, $t3, 2
    ctx->r15 = S32(ctx->r11 << 2);
    // 0x8016FEA8: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x8016FEAC: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8016FEB0: addu        $t7, $t7, $t3
    ctx->r15 = ADD32(ctx->r15, ctx->r11);
    // 0x8016FEB4: lhu         $t8, 0x26($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X26);
    // 0x8016FEB8: sw          $zero, -0x29F0($at)
    MEM_W(-0X29F0, ctx->r1) = 0;
    // 0x8016FEBC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8016FEC0: addu        $t4, $t4, $t1
    ctx->r12 = ADD32(ctx->r12, ctx->r9);
    // 0x8016FEC4: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8016FEC8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016FECC: subu        $t7, $t7, $t3
    ctx->r15 = SUB32(ctx->r15, ctx->r11);
    // 0x8016FED0: sll         $t5, $t6, 2
    ctx->r13 = S32(ctx->r14 << 2);
    // 0x8016FED4: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x8016FED8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8016FEDC: addu        $t5, $t5, $t6
    ctx->r13 = ADD32(ctx->r13, ctx->r14);
    // 0x8016FEE0: sw          $zero, -0x29EC($at)
    MEM_W(-0X29EC, ctx->r1) = 0;
    // 0x8016FEE4: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8016FEE8: addu        $t7, $t7, $t3
    ctx->r15 = ADD32(ctx->r15, ctx->r11);
    // 0x8016FEEC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8016FEF0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8016FEF4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016FEF8: subu        $t5, $t5, $t6
    ctx->r13 = SUB32(ctx->r13, ctx->r14);
    // 0x8016FEFC: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8016FF00: lhu         $t4, 0x26($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X26);
    // 0x8016FF04: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8016FF08: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8016FF0C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8016FF10: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8016FF14: sw          $t2, -0x29E8($at)
    MEM_W(-0X29E8, ctx->r1) = ctx->r10;
    // 0x8016FF18: addu        $t5, $t5, $t6
    ctx->r13 = ADD32(ctx->r13, ctx->r14);
    // 0x8016FF1C: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8016FF20: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8016FF24: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016FF28: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8016FF2C: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x8016FF30: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8016FF34: sll         $t3, $t4, 2
    ctx->r11 = S32(ctx->r12 << 2);
    // 0x8016FF38: lhu         $t6, 0x26($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X26);
    // 0x8016FF3C: sw          $zero, -0x29E4($at)
    MEM_W(-0X29E4, ctx->r1) = 0;
    // 0x8016FF40: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8016FF44: addu        $t3, $t3, $t4
    ctx->r11 = ADD32(ctx->r11, ctx->r12);
    // 0x8016FF48: lw          $t0, -0x2D8C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2D8C);
    // 0x8016FF4C: lhu         $t8, 0x26($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X26);
    // 0x8016FF50: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016FF54: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8016FF58: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8016FF5C: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8016FF60: subu        $t3, $t3, $t4
    ctx->r11 = SUB32(ctx->r11, ctx->r12);
    // 0x8016FF64: sw          $zero, -0x29E0($at)
    MEM_W(-0X29E0, ctx->r1) = 0;
    // 0x8016FF68: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8016FF6C: sll         $t5, $t6, 2
    ctx->r13 = S32(ctx->r14 << 2);
    // 0x8016FF70: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x8016FF74: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8016FF78: addu        $t3, $t3, $t4
    ctx->r11 = ADD32(ctx->r11, ctx->r12);
    // 0x8016FF7C: addu        $t5, $t5, $t6
    ctx->r13 = ADD32(ctx->r13, ctx->r14);
    // 0x8016FF80: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8016FF84: lw          $t2, -0x2D8C($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2D8C);
    // 0x8016FF88: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8016FF8C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016FF90: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8016FF94: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8016FF98: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x8016FF9C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8016FFA0: subu        $t5, $t5, $t6
    ctx->r13 = SUB32(ctx->r13, ctx->r14);
    // 0x8016FFA4: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8016FFA8: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8016FFAC: sw          $t1, -0x29D8($at)
    MEM_W(-0X29D8, ctx->r1) = ctx->r9;
    // 0x8016FFB0: lw          $t7, 0xC($t2)
    ctx->r15 = MEM_W(ctx->r10, 0XC);
    // 0x8016FFB4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8016FFB8: addu        $t5, $t5, $t6
    ctx->r13 = ADD32(ctx->r13, ctx->r14);
    // 0x8016FFBC: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8016FFC0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016FFC4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8016FFC8: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8016FFCC: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x8016FFD0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8016FFD4: addiu       $t0, $t0, -0x2A28
    ctx->r8 = ADD32(ctx->r8, -0X2A28);
    // 0x8016FFD8: addu        $t4, $t9, $t0
    ctx->r12 = ADD32(ctx->r25, ctx->r8);
    // 0x8016FFDC: sw          $t7, -0x29D4($at)
    MEM_W(-0X29D4, ctx->r1) = ctx->r15;
    // 0x8016FFE0: lw          $t1, 0x50($t4)
    ctx->r9 = MEM_W(ctx->r12, 0X50);
    // 0x8016FFE4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8016FFE8: addiu       $t6, $t6, -0x2A28
    ctx->r14 = ADD32(ctx->r14, -0X2A28);
    // 0x8016FFEC: lwc1        $f4, 0x4($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X4);
    // 0x8016FFF0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8016FFF4: addiu       $t0, $t0, -0x2A28
    ctx->r8 = ADD32(ctx->r8, -0X2A28);
    // 0x8016FFF8: swc1        $f4, 0x60($t4)
    MEM_W(0X60, ctx->r12) = ctx->f4.u32l;
    // 0x8016FFFC: lhu         $t3, 0x26($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X26);
    // 0x80170000: sll         $t2, $t3, 2
    ctx->r10 = S32(ctx->r11 << 2);
    // 0x80170004: addu        $t2, $t2, $t3
    ctx->r10 = ADD32(ctx->r10, ctx->r11);
    // 0x80170008: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8017000C: subu        $t2, $t2, $t3
    ctx->r10 = SUB32(ctx->r10, ctx->r11);
    // 0x80170010: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80170014: addu        $t2, $t2, $t3
    ctx->r10 = ADD32(ctx->r10, ctx->r11);
    // 0x80170018: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8017001C: addu        $t7, $t2, $t6
    ctx->r15 = ADD32(ctx->r10, ctx->r14);
    // 0x80170020: lw          $t5, 0x50($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X50);
    // 0x80170024: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80170028: addiu       $t6, $t6, -0x2A28
    ctx->r14 = ADD32(ctx->r14, -0X2A28);
    // 0x8017002C: lwc1        $f6, 0x8($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X8);
    // 0x80170030: swc1        $f6, 0x64($t7)
    MEM_W(0X64, ctx->r15) = ctx->f6.u32l;
    // 0x80170034: lhu         $t8, 0x26($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X26);
    // 0x80170038: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8017003C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80170040: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80170044: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80170048: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8017004C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80170050: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80170054: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80170058: lw          $t4, 0x50($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X50);
    // 0x8017005C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80170060: addiu       $t9, $t9, -0x2A28
    ctx->r25 = ADD32(ctx->r25, -0X2A28);
    // 0x80170064: lwc1        $f8, 0xC($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0XC);
    // 0x80170068: swc1        $f8, 0x68($t1)
    MEM_W(0X68, ctx->r9) = ctx->f8.u32l;
    // 0x8017006C: lhu         $t3, 0x26($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X26);
    // 0x80170070: sll         $t2, $t3, 2
    ctx->r10 = S32(ctx->r11 << 2);
    // 0x80170074: addu        $t2, $t2, $t3
    ctx->r10 = ADD32(ctx->r10, ctx->r11);
    // 0x80170078: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8017007C: subu        $t2, $t2, $t3
    ctx->r10 = SUB32(ctx->r10, ctx->r11);
    // 0x80170080: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80170084: addu        $t2, $t2, $t3
    ctx->r10 = ADD32(ctx->r10, ctx->r11);
    // 0x80170088: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8017008C: addu        $t5, $t2, $t6
    ctx->r13 = ADD32(ctx->r10, ctx->r14);
    // 0x80170090: lwc1        $f10, 0x60($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X60);
    // 0x80170094: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80170098: addiu       $t3, $t3, -0x2A28
    ctx->r11 = ADD32(ctx->r11, -0X2A28);
    // 0x8017009C: swc1        $f10, 0x6C($t5)
    MEM_W(0X6C, ctx->r13) = ctx->f10.u32l;
    // 0x801700A0: lhu         $t7, 0x26($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X26);
    // 0x801700A4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x801700A8: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x801700AC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x801700B0: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x801700B4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x801700B8: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x801700BC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x801700C0: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x801700C4: lwc1        $f16, 0x64($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X64);
    // 0x801700C8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801700CC: addiu       $t7, $t7, -0x2A28
    ctx->r15 = ADD32(ctx->r15, -0X2A28);
    // 0x801700D0: swc1        $f16, 0x70($t0)
    MEM_W(0X70, ctx->r8) = ctx->f16.u32l;
    // 0x801700D4: lhu         $t4, 0x26($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X26);
    // 0x801700D8: sll         $t1, $t4, 2
    ctx->r9 = S32(ctx->r12 << 2);
    // 0x801700DC: addu        $t1, $t1, $t4
    ctx->r9 = ADD32(ctx->r9, ctx->r12);
    // 0x801700E0: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x801700E4: subu        $t1, $t1, $t4
    ctx->r9 = SUB32(ctx->r9, ctx->r12);
    // 0x801700E8: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x801700EC: addu        $t1, $t1, $t4
    ctx->r9 = ADD32(ctx->r9, ctx->r12);
    // 0x801700F0: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x801700F4: addu        $t2, $t1, $t3
    ctx->r10 = ADD32(ctx->r9, ctx->r11);
    // 0x801700F8: lwc1        $f18, 0x68($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X68);
    // 0x801700FC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80170100: addiu       $t1, $t1, -0x2A28
    ctx->r9 = ADD32(ctx->r9, -0X2A28);
    // 0x80170104: swc1        $f18, 0x74($t2)
    MEM_W(0X74, ctx->r10) = ctx->f18.u32l;
    // 0x80170108: lhu         $t6, 0x26($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X26);
    // 0x8017010C: sll         $t5, $t6, 2
    ctx->r13 = S32(ctx->r14 << 2);
    // 0x80170110: addu        $t5, $t5, $t6
    ctx->r13 = ADD32(ctx->r13, ctx->r14);
    // 0x80170114: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80170118: subu        $t5, $t5, $t6
    ctx->r13 = SUB32(ctx->r13, ctx->r14);
    // 0x8017011C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80170120: addu        $t5, $t5, $t6
    ctx->r13 = ADD32(ctx->r13, ctx->r14);
    // 0x80170124: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80170128: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x8017012C: lw          $t9, 0x54($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X54);
    // 0x80170130: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80170134: addiu       $t7, $t7, -0x2A28
    ctx->r15 = ADD32(ctx->r15, -0X2A28);
    // 0x80170138: lwc1        $f4, 0x4($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X4);
    // 0x8017013C: swc1        $f4, 0x78($t8)
    MEM_W(0X78, ctx->r24) = ctx->f4.u32l;
    // 0x80170140: lhu         $t0, 0x26($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X26);
    // 0x80170144: sll         $t4, $t0, 2
    ctx->r12 = S32(ctx->r8 << 2);
    // 0x80170148: addu        $t4, $t4, $t0
    ctx->r12 = ADD32(ctx->r12, ctx->r8);
    // 0x8017014C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80170150: subu        $t4, $t4, $t0
    ctx->r12 = SUB32(ctx->r12, ctx->r8);
    // 0x80170154: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80170158: addu        $t4, $t4, $t0
    ctx->r12 = ADD32(ctx->r12, ctx->r8);
    // 0x8017015C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80170160: addu        $t3, $t4, $t1
    ctx->r11 = ADD32(ctx->r12, ctx->r9);
    // 0x80170164: lw          $t2, 0x54($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X54);
    // 0x80170168: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017016C: addiu       $t1, $t1, -0x2A28
    ctx->r9 = ADD32(ctx->r9, -0X2A28);
    // 0x80170170: lwc1        $f6, 0x8($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X8);
    // 0x80170174: swc1        $f6, 0x7C($t3)
    MEM_W(0X7C, ctx->r11) = ctx->f6.u32l;
    // 0x80170178: lhu         $t6, 0x26($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X26);
    // 0x8017017C: sll         $t5, $t6, 2
    ctx->r13 = S32(ctx->r14 << 2);
    // 0x80170180: addu        $t5, $t5, $t6
    ctx->r13 = ADD32(ctx->r13, ctx->r14);
    // 0x80170184: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80170188: subu        $t5, $t5, $t6
    ctx->r13 = SUB32(ctx->r13, ctx->r14);
    // 0x8017018C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80170190: addu        $t5, $t5, $t6
    ctx->r13 = ADD32(ctx->r13, ctx->r14);
    // 0x80170194: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80170198: addu        $t9, $t5, $t7
    ctx->r25 = ADD32(ctx->r13, ctx->r15);
    // 0x8017019C: lw          $t8, 0x54($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X54);
    // 0x801701A0: lwc1        $f8, 0xC($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0XC);
    // 0x801701A4: swc1        $f8, 0x80($t9)
    MEM_W(0X80, ctx->r25) = ctx->f8.u32l;
    // 0x801701A8: lhu         $t0, 0x26($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X26);
    // 0x801701AC: sll         $t4, $t0, 2
    ctx->r12 = S32(ctx->r8 << 2);
    // 0x801701B0: addu        $t4, $t4, $t0
    ctx->r12 = ADD32(ctx->r12, ctx->r8);
    // 0x801701B4: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x801701B8: subu        $t4, $t4, $t0
    ctx->r12 = SUB32(ctx->r12, ctx->r8);
    // 0x801701BC: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x801701C0: addu        $t4, $t4, $t0
    ctx->r12 = ADD32(ctx->r12, ctx->r8);
    // 0x801701C4: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x801701C8: addu        $t2, $t4, $t1
    ctx->r10 = ADD32(ctx->r12, ctx->r9);
    // 0x801701CC: lw          $t3, 0x54($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X54);
    // 0x801701D0: lwc1        $f10, 0x10($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X10);
    // 0x801701D4: swc1        $f10, 0x84($t2)
    MEM_W(0X84, ctx->r10) = ctx->f10.u32l;
    // 0x801701D8: lhu         $t6, 0x26($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X26);
    // 0x801701DC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x801701E0: addiu       $t8, $t8, -0x2A28
    ctx->r24 = ADD32(ctx->r24, -0X2A28);
    // 0x801701E4: sll         $t5, $t6, 2
    ctx->r13 = S32(ctx->r14 << 2);
    // 0x801701E8: addu        $t5, $t5, $t6
    ctx->r13 = ADD32(ctx->r13, ctx->r14);
    // 0x801701EC: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x801701F0: subu        $t5, $t5, $t6
    ctx->r13 = SUB32(ctx->r13, ctx->r14);
    // 0x801701F4: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x801701F8: addu        $t5, $t5, $t6
    ctx->r13 = ADD32(ctx->r13, ctx->r14);
    // 0x801701FC: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80170200: addu        $t9, $t5, $t8
    ctx->r25 = ADD32(ctx->r13, ctx->r24);
    // 0x80170204: lwc1        $f16, 0x84($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X84);
    // 0x80170208: lw          $a1, 0x78($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X78);
    // 0x8017020C: lw          $a2, 0x7C($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X7C);
    // 0x80170210: lw          $a3, 0x80($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X80);
    // 0x80170214: addiu       $t7, $t5, 0xA4
    ctx->r15 = ADD32(ctx->r13, 0XA4);
    // 0x80170218: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x8017021C: jal         0x800D7120
    // 0x80170220: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    guAlignF_recomp(rdram, ctx);
        goto after_0;
    // 0x80170220: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_0:
    // 0x80170224: lhu         $t0, 0x26($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X26);
    // 0x80170228: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017022C: addiu       $t3, $t3, -0x2A28
    ctx->r11 = ADD32(ctx->r11, -0X2A28);
    // 0x80170230: sll         $t4, $t0, 2
    ctx->r12 = S32(ctx->r8 << 2);
    // 0x80170234: addu        $t4, $t4, $t0
    ctx->r12 = ADD32(ctx->r12, ctx->r8);
    // 0x80170238: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8017023C: subu        $t4, $t4, $t0
    ctx->r12 = SUB32(ctx->r12, ctx->r8);
    // 0x80170240: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80170244: addu        $t4, $t4, $t0
    ctx->r12 = ADD32(ctx->r12, ctx->r8);
    // 0x80170248: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8017024C: addu        $t2, $t4, $t3
    ctx->r10 = ADD32(ctx->r12, ctx->r11);
    // 0x80170250: lwc1        $f18, 0x84($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X84);
    // 0x80170254: lw          $a1, 0x78($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X78);
    // 0x80170258: lw          $a2, 0x7C($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X7C);
    // 0x8017025C: lw          $a3, 0x80($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X80);
    // 0x80170260: addiu       $t1, $t4, 0xE4
    ctx->r9 = ADD32(ctx->r12, 0XE4);
    // 0x80170264: addu        $a0, $t1, $t3
    ctx->r4 = ADD32(ctx->r9, ctx->r11);
    // 0x80170268: jal         0x800D7120
    // 0x8017026C: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    guAlignF_recomp(rdram, ctx);
        goto after_1;
    // 0x8017026C: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_1:
    // 0x80170270: lhu         $t6, 0x26($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X26);
    // 0x80170274: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80170278: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8017027C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80170280: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80170284: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80170288: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8017028C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80170290: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80170294: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80170298: addu        $t5, $t5, $t7
    ctx->r13 = ADD32(ctx->r13, ctx->r15);
    // 0x8017029C: lhu         $t5, -0x2A28($t5)
    ctx->r13 = MEM_HU(ctx->r13, -0X2A28);
    // 0x801702A0: andi        $t8, $t5, 0x8
    ctx->r24 = ctx->r13 & 0X8;
    // 0x801702A4: bne         $t8, $at, L_80170374
    if (ctx->r24 != ctx->r1) {
        // 0x801702A8: nop
    
            goto L_80170374;
    }
    // 0x801702A8: nop

    // 0x801702AC: sh          $zero, 0x24($sp)
    MEM_H(0X24, ctx->r29) = 0;
L_801702B0:
    // 0x801702B0: lhu         $t9, 0x24($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X24);
    // 0x801702B4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x801702B8: addiu       $t1, $t1, -0x2A28
    ctx->r9 = ADD32(ctx->r9, -0X2A28);
    // 0x801702BC: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x801702C0: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x801702C4: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x801702C8: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x801702CC: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x801702D0: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x801702D4: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x801702D8: addu        $t4, $t0, $t1
    ctx->r12 = ADD32(ctx->r8, ctx->r9);
    // 0x801702DC: lhu         $t3, 0x0($t4)
    ctx->r11 = MEM_HU(ctx->r12, 0X0);
    // 0x801702E0: andi        $t2, $t3, 0x8000
    ctx->r10 = ctx->r11 & 0X8000;
    // 0x801702E4: beq         $t2, $zero, L_80170328
    if (ctx->r10 == 0) {
        // 0x801702E8: nop
    
            goto L_80170328;
    }
    // 0x801702E8: nop

    // 0x801702EC: lhu         $t6, 0x26($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X26);
    // 0x801702F0: lw          $t0, 0x4($t4)
    ctx->r8 = MEM_W(ctx->r12, 0X4);
    // 0x801702F4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801702F8: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x801702FC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80170300: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80170304: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80170308: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8017030C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80170310: addu        $t5, $t7, $t1
    ctx->r13 = ADD32(ctx->r15, ctx->r9);
    // 0x80170314: lw          $t8, 0x8($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X8);
    // 0x80170318: bne         $t8, $t0, L_80170328
    if (ctx->r24 != ctx->r8) {
        // 0x8017031C: nop
    
            goto L_80170328;
    }
    // 0x8017031C: nop

    // 0x80170320: b           L_80170340
    // 0x80170324: sw          $t9, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->r25;
        goto L_80170340;
    // 0x80170324: sw          $t9, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->r25;
L_80170328:
    // 0x80170328: lhu         $t3, 0x24($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X24);
    // 0x8017032C: addiu       $t2, $t3, 0x1
    ctx->r10 = ADD32(ctx->r11, 0X1);
    // 0x80170330: andi        $t6, $t2, 0xFFFF
    ctx->r14 = ctx->r10 & 0XFFFF;
    // 0x80170334: slti        $at, $t6, 0x30
    ctx->r1 = SIGNED(ctx->r14) < 0X30 ? 1 : 0;
    // 0x80170338: bne         $at, $zero, L_801702B0
    if (ctx->r1 != 0) {
        // 0x8017033C: sh          $t2, 0x24($sp)
        MEM_H(0X24, ctx->r29) = ctx->r10;
            goto L_801702B0;
    }
    // 0x8017033C: sh          $t2, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r10;
L_80170340:
    // 0x80170340: lhu         $t7, 0x26($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X26);
    // 0x80170344: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80170348: sll         $t1, $t7, 2
    ctx->r9 = S32(ctx->r15 << 2);
    // 0x8017034C: addu        $t1, $t1, $t7
    ctx->r9 = ADD32(ctx->r9, ctx->r15);
    // 0x80170350: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80170354: subu        $t1, $t1, $t7
    ctx->r9 = SUB32(ctx->r9, ctx->r15);
    // 0x80170358: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8017035C: addu        $t1, $t1, $t7
    ctx->r9 = ADD32(ctx->r9, ctx->r15);
    // 0x80170360: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80170364: addu        $a1, $a1, $t1
    ctx->r5 = ADD32(ctx->r5, ctx->r9);
    // 0x80170368: lw          $a1, -0x2A14($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X2A14);
    // 0x8017036C: jal         0x801703AC
    // 0x80170370: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    func_801703AC_02FC30(rdram, ctx);
        goto after_2;
    // 0x80170370: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_2:
L_80170374:
    // 0x80170374: jal         0x8016F67C
    // 0x80170378: lhu         $a0, 0x26($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X26);
    func_8016F67C_02FC30(rdram, ctx);
        goto after_3;
    // 0x80170378: lhu         $a0, 0x26($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X26);
    after_3:
    // 0x8017037C: jal         0x8016F7F8
    // 0x80170380: lhu         $a0, 0x26($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X26);
    func_8016F7F8_02FC30(rdram, ctx);
        goto after_4;
    // 0x80170380: lhu         $a0, 0x26($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X26);
    after_4:
    // 0x80170384: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80170388: lw          $t4, -0x2D8C($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2D8C);
    // 0x8017038C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80170390: addiu       $t8, $t4, 0x10
    ctx->r24 = ADD32(ctx->r12, 0X10);
    // 0x80170394: b           L_8016FBC4
    // 0x80170398: sw          $t8, -0x2D8C($at)
    MEM_W(-0X2D8C, ctx->r1) = ctx->r24;
        goto L_8016FBC4;
    // 0x80170398: sw          $t8, -0x2D8C($at)
    MEM_W(-0X2D8C, ctx->r1) = ctx->r24;
L_8017039C:
    // 0x8017039C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801703A0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801703A4: jr          $ra
    // 0x801703A8: nop

    return;
    // 0x801703A8: nop

;}
RECOMP_FUNC void func_801703AC_02FC30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801703AC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801703B0: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x801703B4: lhu         $t0, 0x3A($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X3A);
    // 0x801703B8: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x801703BC: lhu         $t6, 0x3E($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X3E);
    // 0x801703C0: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x801703C4: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x801703C8: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x801703CC: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x801703D0: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x801703D4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801703D8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801703DC: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x801703E0: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x801703E4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801703E8: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x801703EC: addiu       $t9, $t9, -0x2A28
    ctx->r25 = ADD32(ctx->r25, -0X2A28);
    // 0x801703F0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801703F4: addu        $t2, $t1, $t9
    ctx->r10 = ADD32(ctx->r9, ctx->r25);
    // 0x801703F8: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x801703FC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80170400: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80170404: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80170408: lw          $a1, 0x6C($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X6C);
    // 0x8017040C: lw          $a2, 0x70($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X70);
    // 0x80170410: lw          $a3, 0x74($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X74);
    // 0x80170414: addiu       $t8, $t7, 0xA4
    ctx->r24 = ADD32(ctx->r15, 0XA4);
    // 0x80170418: addiu       $t3, $sp, 0x34
    ctx->r11 = ADD32(ctx->r29, 0X34);
    // 0x8017041C: addiu       $t4, $sp, 0x30
    ctx->r12 = ADD32(ctx->r29, 0X30);
    // 0x80170420: addiu       $t5, $sp, 0x2C
    ctx->r13 = ADD32(ctx->r29, 0X2C);
    // 0x80170424: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x80170428: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8017042C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80170430: jal         0x800D6E90
    // 0x80170434: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    guMtxXFMF_recomp(rdram, ctx);
        goto after_0;
    // 0x80170434: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x80170438: lhu         $t6, 0x3E($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X3E);
    // 0x8017043C: lhu         $t1, 0x3A($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X3A);
    // 0x80170440: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80170444: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80170448: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8017044C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80170450: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80170454: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80170458: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8017045C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80170460: addiu       $t8, $t8, -0x2A28
    ctx->r24 = ADD32(ctx->r24, -0X2A28);
    // 0x80170464: addu        $t0, $t7, $t8
    ctx->r8 = ADD32(ctx->r15, ctx->r24);
    // 0x80170468: sll         $t9, $t1, 2
    ctx->r25 = S32(ctx->r9 << 2);
    // 0x8017046C: lwc1        $f4, 0x60($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X60);
    // 0x80170470: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80170474: addu        $t9, $t9, $t1
    ctx->r25 = ADD32(ctx->r25, ctx->r9);
    // 0x80170478: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8017047C: subu        $t9, $t9, $t1
    ctx->r25 = SUB32(ctx->r25, ctx->r9);
    // 0x80170480: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80170484: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80170488: addu        $t9, $t9, $t1
    ctx->r25 = ADD32(ctx->r25, ctx->r9);
    // 0x8017048C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80170490: addu        $t2, $t9, $t8
    ctx->r10 = ADD32(ctx->r25, ctx->r24);
    // 0x80170494: swc1        $f8, 0x60($t2)
    MEM_W(0X60, ctx->r10) = ctx->f8.u32l;
    // 0x80170498: lhu         $t3, 0x3E($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X3E);
    // 0x8017049C: lhu         $t7, 0x3A($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X3A);
    // 0x801704A0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x801704A4: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x801704A8: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x801704AC: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x801704B0: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x801704B4: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x801704B8: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x801704BC: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x801704C0: addiu       $t5, $t5, -0x2A28
    ctx->r13 = ADD32(ctx->r13, -0X2A28);
    // 0x801704C4: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x801704C8: sll         $t0, $t7, 2
    ctx->r8 = S32(ctx->r15 << 2);
    // 0x801704CC: lwc1        $f10, 0x64($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X64);
    // 0x801704D0: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801704D4: addu        $t0, $t0, $t7
    ctx->r8 = ADD32(ctx->r8, ctx->r15);
    // 0x801704D8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x801704DC: subu        $t0, $t0, $t7
    ctx->r8 = SUB32(ctx->r8, ctx->r15);
    // 0x801704E0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801704E4: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x801704E8: addu        $t0, $t0, $t7
    ctx->r8 = ADD32(ctx->r8, ctx->r15);
    // 0x801704EC: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x801704F0: addu        $t1, $t0, $t5
    ctx->r9 = ADD32(ctx->r8, ctx->r13);
    // 0x801704F4: swc1        $f18, 0x64($t1)
    MEM_W(0X64, ctx->r9) = ctx->f18.u32l;
    // 0x801704F8: lhu         $t9, 0x3E($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X3E);
    // 0x801704FC: lhu         $t4, 0x3A($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X3A);
    // 0x80170500: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80170504: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80170508: addu        $t8, $t8, $t9
    ctx->r24 = ADD32(ctx->r24, ctx->r25);
    // 0x8017050C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80170510: subu        $t8, $t8, $t9
    ctx->r24 = SUB32(ctx->r24, ctx->r25);
    // 0x80170514: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80170518: addu        $t8, $t8, $t9
    ctx->r24 = ADD32(ctx->r24, ctx->r25);
    // 0x8017051C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80170520: addiu       $t2, $t2, -0x2A28
    ctx->r10 = ADD32(ctx->r10, -0X2A28);
    // 0x80170524: addu        $t3, $t8, $t2
    ctx->r11 = ADD32(ctx->r24, ctx->r10);
    // 0x80170528: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x8017052C: lwc1        $f4, 0x68($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X68);
    // 0x80170530: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80170534: addu        $t6, $t6, $t4
    ctx->r14 = ADD32(ctx->r14, ctx->r12);
    // 0x80170538: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8017053C: subu        $t6, $t6, $t4
    ctx->r14 = SUB32(ctx->r14, ctx->r12);
    // 0x80170540: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80170544: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80170548: addu        $t6, $t6, $t4
    ctx->r14 = ADD32(ctx->r14, ctx->r12);
    // 0x8017054C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80170550: addu        $t7, $t6, $t2
    ctx->r15 = ADD32(ctx->r14, ctx->r10);
    // 0x80170554: swc1        $f8, 0x68($t7)
    MEM_W(0X68, ctx->r15) = ctx->f8.u32l;
    // 0x80170558: lhu         $t0, 0x3A($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X3A);
    // 0x8017055C: lhu         $t8, 0x3E($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X3E);
    // 0x80170560: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80170564: sll         $t5, $t0, 2
    ctx->r13 = S32(ctx->r8 << 2);
    // 0x80170568: addu        $t5, $t5, $t0
    ctx->r13 = ADD32(ctx->r13, ctx->r8);
    // 0x8017056C: sll         $t3, $t8, 2
    ctx->r11 = S32(ctx->r24 << 2);
    // 0x80170570: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80170574: addu        $t3, $t3, $t8
    ctx->r11 = ADD32(ctx->r11, ctx->r24);
    // 0x80170578: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8017057C: subu        $t5, $t5, $t0
    ctx->r13 = SUB32(ctx->r13, ctx->r8);
    // 0x80170580: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80170584: subu        $t3, $t3, $t8
    ctx->r11 = SUB32(ctx->r11, ctx->r24);
    // 0x80170588: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8017058C: addu        $t5, $t5, $t0
    ctx->r13 = ADD32(ctx->r13, ctx->r8);
    // 0x80170590: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80170594: addu        $t3, $t3, $t8
    ctx->r11 = ADD32(ctx->r11, ctx->r24);
    // 0x80170598: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8017059C: addiu       $t9, $t9, -0x2A28
    ctx->r25 = ADD32(ctx->r25, -0X2A28);
    // 0x801705A0: addiu       $t4, $t3, 0xA4
    ctx->r12 = ADD32(ctx->r11, 0XA4);
    // 0x801705A4: addiu       $t1, $t5, 0xE4
    ctx->r9 = ADD32(ctx->r13, 0XE4);
    // 0x801705A8: addiu       $t6, $t5, 0xA4
    ctx->r14 = ADD32(ctx->r13, 0XA4);
    // 0x801705AC: addu        $a2, $t6, $t9
    ctx->r6 = ADD32(ctx->r14, ctx->r25);
    // 0x801705B0: addu        $a0, $t1, $t9
    ctx->r4 = ADD32(ctx->r9, ctx->r25);
    // 0x801705B4: jal         0x800D6F30
    // 0x801705B8: addu        $a1, $t4, $t9
    ctx->r5 = ADD32(ctx->r12, ctx->r25);
    guMtxCatF_recomp(rdram, ctx);
        goto after_1;
    // 0x801705B8: addu        $a1, $t4, $t9
    ctx->r5 = ADD32(ctx->r12, ctx->r25);
    after_1:
    // 0x801705BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801705C0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x801705C4: jr          $ra
    // 0x801705C8: nop

    return;
    // 0x801705C8: nop

;}
RECOMP_FUNC void func_801705CC_02FC30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801705CC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801705D0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x801705D4: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x801705D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801705DC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x801705E0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801705E4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x801705E8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801705EC: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x801705F0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801705F4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x801705F8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801705FC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80170600: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x80170604: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80170608: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8017060C: addiu       $t8, $t8, -0x4198
    ctx->r24 = ADD32(ctx->r24, -0X4198);
    // 0x80170610: lwc1        $f6, 0x0($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X0);
    // 0x80170614: lwc1        $f4, -0x29C8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X29C8);
    // 0x80170618: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017061C: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x80170620: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80170624: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80170628: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017062C: addiu       $t2, $t2, -0x4198
    ctx->r10 = ADD32(ctx->r10, -0X4198);
    // 0x80170630: swc1        $f8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f8.u32l;
    // 0x80170634: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80170638: lwc1        $f16, 0x4($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X4);
    // 0x8017063C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80170640: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80170644: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80170648: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8017064C: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x80170650: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80170654: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80170658: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8017065C: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80170660: lwc1        $f10, -0x29C4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X29C4);
    // 0x80170664: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x80170668: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017066C: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80170670: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80170674: addiu       $t6, $t6, -0x4198
    ctx->r14 = ADD32(ctx->r14, -0X4198);
    // 0x80170678: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017067C: swc1        $f18, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->f18.u32l;
    // 0x80170680: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80170684: lwc1        $f6, 0x8($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X8);
    // 0x80170688: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x8017068C: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80170690: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x80170694: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80170698: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x8017069C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x801706A0: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x801706A4: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x801706A8: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x801706AC: lwc1        $f4, -0x29C0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X29C0);
    // 0x801706B0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x801706B4: addiu       $t8, $t8, -0x4198
    ctx->r24 = ADD32(ctx->r24, -0X4198);
    // 0x801706B8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801706BC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801706C0: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x801706C4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x801706C8: swc1        $f8, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->f8.u32l;
    // 0x801706CC: lwc1        $f16, 0x0($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X0);
    // 0x801706D0: lwc1        $f10, 0xC($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0XC);
    // 0x801706D4: addiu       $t0, $t0, -0x4198
    ctx->r8 = ADD32(ctx->r8, -0X4198);
    // 0x801706D8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x801706DC: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x801706E0: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x801706E4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x801706E8: addiu       $t2, $t2, -0x4198
    ctx->r10 = ADD32(ctx->r10, -0X4198);
    // 0x801706EC: swc1        $f18, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f18.u32l;
    // 0x801706F0: lwc1        $f6, 0x4($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X4);
    // 0x801706F4: lwc1        $f4, 0x10($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X10);
    // 0x801706F8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x801706FC: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x80170700: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80170704: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80170708: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x8017070C: swc1        $f8, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->f8.u32l;
    // 0x80170710: lwc1        $f16, 0x8($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X8);
    // 0x80170714: lwc1        $f10, 0x14($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X14);
    // 0x80170718: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8017071C: swc1        $f18, 0x14($t3)
    MEM_W(0X14, ctx->r11) = ctx->f18.u32l;
    // 0x80170720: lwc1        $f4, 0x0($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X0);
    // 0x80170724: lwc1        $f8, 0x4($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X4);
    // 0x80170728: lwc1        $f18, 0x8($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X8);
    // 0x8017072C: mul.s       $f6, $f4, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x80170730: nop

    // 0x80170734: mul.s       $f10, $f8, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x80170738: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8017073C: mul.s       $f4, $f18, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x80170740: jal         0x800D68E0
    // 0x80170744: add.s       $f12, $f4, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f16.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x80170744: add.s       $f12, $f4, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f16.fl;
    after_0:
    // 0x80170748: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017074C: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x80170750: lwc1        $f8, 0xC($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0XC);
    // 0x80170754: lwc1        $f10, 0x10($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X10);
    // 0x80170758: lwc1        $f16, 0x14($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0X14);
    // 0x8017075C: mul.s       $f6, $f8, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x80170760: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x80170764: mul.s       $f18, $f10, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x80170768: add.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x8017076C: mul.s       $f8, $f16, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x80170770: jal         0x800D68E0
    // 0x80170774: add.s       $f12, $f8, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x80170774: add.s       $f12, $f8, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f4.fl;
    after_1:
    // 0x80170778: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017077C: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x80170780: lwc1        $f10, 0x0($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X0);
    // 0x80170784: lwc1        $f6, 0xC($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0XC);
    // 0x80170788: lwc1        $f16, 0x4($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X4);
    // 0x8017078C: lwc1        $f8, 0x10($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X10);
    // 0x80170790: mul.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80170794: lwc1        $f6, 0x8($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X8);
    // 0x80170798: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8017079C: mul.s       $f4, $f16, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x801707A0: lwc1        $f16, 0x14($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X14);
    // 0x801707A4: mul.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x801707A8: add.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801707AC: mul.s       $f4, $f20, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f22.fl);
    // 0x801707B0: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x801707B4: jal         0x800E4BE0
    // 0x801707B8: div.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    func_800E4BE0(rdram, ctx);
        goto after_2;
    // 0x801707B8: div.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    after_2:
    // 0x801707BC: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x801707C0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801707C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801707C8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801707CC: mul.s       $f16, $f0, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x801707D0: lwc1        $f10, 0x2680($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X2680);
    // 0x801707D4: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x801707D8: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x801707DC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801707E0: jr          $ra
    // 0x801707E4: div.s       $f0, $f16, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = DIV_S(ctx->f16.fl, ctx->f10.fl);
    return;
    // 0x801707E4: div.s       $f0, $f16, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = DIV_S(ctx->f16.fl, ctx->f10.fl);
;}
RECOMP_FUNC void func_801707E8_02FC30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801707E8: addiu       $sp, $sp, -0xE8
    ctx->r29 = ADD32(ctx->r29, -0XE8);
    // 0x801707EC: lbu         $t6, 0xFB($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0XFB);
    // 0x801707F0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801707F4: sw          $a0, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r4;
    // 0x801707F8: sw          $a1, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r5;
    // 0x801707FC: sw          $a2, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->r6;
    // 0x80170800: sw          $a3, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r7;
    // 0x80170804: beq         $t6, $zero, L_80170E8C
    if (ctx->r14 == 0) {
        // 0x80170808: sw          $s0, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r16;
            goto L_80170E8C;
    }
    // 0x80170808: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x8017080C: lbu         $s0, 0xEB($sp)
    ctx->r16 = MEM_BU(ctx->r29, 0XEB);
    // 0x80170810: addiu       $at, $zero, 0x5B
    ctx->r1 = ADD32(0, 0X5B);
    // 0x80170814: beq         $s0, $at, L_8017082C
    if (ctx->r16 == ctx->r1) {
        // 0x80170818: addiu       $at, $zero, 0x5F
        ctx->r1 = ADD32(0, 0X5F);
            goto L_8017082C;
    }
    // 0x80170818: addiu       $at, $zero, 0x5F
    ctx->r1 = ADD32(0, 0X5F);
    // 0x8017081C: bne         $s0, $at, L_80170838
    if (ctx->r16 != ctx->r1) {
        // 0x80170820: nop
    
            goto L_80170838;
    }
    // 0x80170820: nop

    // 0x80170824: b           L_801708A0
    // 0x80170828: sw          $zero, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = 0;
        goto L_801708A0;
    // 0x80170828: sw          $zero, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = 0;
L_8017082C:
    // 0x8017082C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80170830: b           L_801708A0
    // 0x80170834: sw          $t7, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r15;
        goto L_801708A0;
    // 0x80170834: sw          $t7, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r15;
L_80170838:
    // 0x80170838: lbu         $t8, 0xEB($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0XEB);
    // 0x8017083C: slti        $at, $t8, 0x30
    ctx->r1 = SIGNED(ctx->r24) < 0X30 ? 1 : 0;
    // 0x80170840: bne         $at, $zero, L_8017085C
    if (ctx->r1 != 0) {
        // 0x80170844: slti        $at, $t8, 0x3A
        ctx->r1 = SIGNED(ctx->r24) < 0X3A ? 1 : 0;
            goto L_8017085C;
    }
    // 0x80170844: slti        $at, $t8, 0x3A
    ctx->r1 = SIGNED(ctx->r24) < 0X3A ? 1 : 0;
    // 0x80170848: beq         $at, $zero, L_8017085C
    if (ctx->r1 == 0) {
        // 0x8017084C: nop
    
            goto L_8017085C;
    }
    // 0x8017084C: nop

    // 0x80170850: addiu       $t9, $t8, -0x2E
    ctx->r25 = ADD32(ctx->r24, -0X2E);
    // 0x80170854: b           L_801708A0
    // 0x80170858: sw          $t9, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r25;
        goto L_801708A0;
    // 0x80170858: sw          $t9, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r25;
L_8017085C:
    // 0x8017085C: lbu         $t0, 0xEB($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0XEB);
    // 0x80170860: slti        $at, $t0, 0x41
    ctx->r1 = SIGNED(ctx->r8) < 0X41 ? 1 : 0;
    // 0x80170864: bne         $at, $zero, L_80170880
    if (ctx->r1 != 0) {
        // 0x80170868: slti        $at, $t0, 0x5B
        ctx->r1 = SIGNED(ctx->r8) < 0X5B ? 1 : 0;
            goto L_80170880;
    }
    // 0x80170868: slti        $at, $t0, 0x5B
    ctx->r1 = SIGNED(ctx->r8) < 0X5B ? 1 : 0;
    // 0x8017086C: beq         $at, $zero, L_80170880
    if (ctx->r1 == 0) {
        // 0x80170870: nop
    
            goto L_80170880;
    }
    // 0x80170870: nop

    // 0x80170874: addiu       $t1, $t0, -0x35
    ctx->r9 = ADD32(ctx->r8, -0X35);
    // 0x80170878: b           L_801708A0
    // 0x8017087C: sw          $t1, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r9;
        goto L_801708A0;
    // 0x8017087C: sw          $t1, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r9;
L_80170880:
    // 0x80170880: lbu         $t2, 0xEB($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0XEB);
    // 0x80170884: slti        $at, $t2, 0x61
    ctx->r1 = SIGNED(ctx->r10) < 0X61 ? 1 : 0;
    // 0x80170888: bne         $at, $zero, L_80170E8C
    if (ctx->r1 != 0) {
        // 0x8017088C: slti        $at, $t2, 0x7B
        ctx->r1 = SIGNED(ctx->r10) < 0X7B ? 1 : 0;
            goto L_80170E8C;
    }
    // 0x8017088C: slti        $at, $t2, 0x7B
    ctx->r1 = SIGNED(ctx->r10) < 0X7B ? 1 : 0;
    // 0x80170890: beq         $at, $zero, L_80170E8C
    if (ctx->r1 == 0) {
        // 0x80170894: nop
    
            goto L_80170E8C;
    }
    // 0x80170894: nop

    // 0x80170898: addiu       $t3, $t2, -0x55
    ctx->r11 = ADD32(ctx->r10, -0X55);
    // 0x8017089C: sw          $t3, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r11;
L_801708A0:
    // 0x801708A0: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x801708A4: lhu         $s0, -0x4530($s0)
    ctx->r16 = MEM_HU(ctx->r16, -0X4530);
    // 0x801708A8: andi        $t4, $s0, 0xC000
    ctx->r12 = ctx->r16 & 0XC000;
    // 0x801708AC: or          $s0, $t4, $zero
    ctx->r16 = ctx->r12 | 0;
    // 0x801708B0: beq         $s0, $zero, L_801708D8
    if (ctx->r16 == 0) {
        // 0x801708B4: addiu       $at, $zero, 0x4000
        ctx->r1 = ADD32(0, 0X4000);
            goto L_801708D8;
    }
    // 0x801708B4: addiu       $at, $zero, 0x4000
    ctx->r1 = ADD32(0, 0X4000);
    // 0x801708B8: beq         $s0, $at, L_80170B10
    if (ctx->r16 == ctx->r1) {
        // 0x801708BC: ori         $at, $zero, 0x8000
        ctx->r1 = 0 | 0X8000;
            goto L_80170B10;
    }
    // 0x801708BC: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x801708C0: beq         $s0, $at, L_801709F4
    if (ctx->r16 == ctx->r1) {
        // 0x801708C4: ori         $at, $zero, 0xC000
        ctx->r1 = 0 | 0XC000;
            goto L_801709F4;
    }
    // 0x801708C4: ori         $at, $zero, 0xC000
    ctx->r1 = 0 | 0XC000;
    // 0x801708C8: beq         $s0, $at, L_80170C2C
    if (ctx->r16 == ctx->r1) {
        // 0x801708CC: nop
    
            goto L_80170C2C;
    }
    // 0x801708CC: nop

    // 0x801708D0: b           L_80170C2C
    // 0x801708D4: nop

        goto L_80170C2C;
    // 0x801708D4: nop

L_801708D8:
    // 0x801708D8: lui         $t5, 0x8011
    ctx->r13 = S32(0X8011 << 16);
    // 0x801708DC: lw          $t5, -0x4514($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4514);
    // 0x801708E0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x801708E4: lui         $t7, 0xDE00
    ctx->r15 = S32(0XDE00 << 16);
    // 0x801708E8: sw          $t5, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r13;
    // 0x801708EC: lw          $t8, 0xA0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA0);
    // 0x801708F0: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x801708F4: sw          $t6, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r14;
    // 0x801708F8: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x801708FC: lw          $t0, 0xA0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA0);
    // 0x80170900: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x80170904: addiu       $t9, $t9, -0x5260
    ctx->r25 = ADD32(ctx->r25, -0X5260);
    // 0x80170908: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x8017090C: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x80170910: lw          $t1, -0x4514($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4514);
    // 0x80170914: lui         $t3, 0xE700
    ctx->r11 = S32(0XE700 << 16);
    // 0x80170918: sw          $t1, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r9;
    // 0x8017091C: lw          $t4, 0x9C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X9C);
    // 0x80170920: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x80170924: sw          $t2, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r10;
    // 0x80170928: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x8017092C: lw          $t5, 0x9C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X9C);
    // 0x80170930: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80170934: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
    // 0x80170938: lbu         $t6, 0xFB($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0XFB);
    // 0x8017093C: beq         $t6, $at, L_80170980
    if (ctx->r14 == ctx->r1) {
        // 0x80170940: nop
    
            goto L_80170980;
    }
    // 0x80170940: nop

    // 0x80170944: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x80170948: lw          $t7, -0x4514($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4514);
    // 0x8017094C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80170950: lui         $t9, 0xE200
    ctx->r25 = S32(0XE200 << 16);
    // 0x80170954: sw          $t7, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r15;
    // 0x80170958: lw          $t0, 0x98($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X98);
    // 0x8017095C: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x80170960: sw          $t8, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r24;
    // 0x80170964: ori         $t9, $t9, 0x1C
    ctx->r25 = ctx->r25 | 0X1C;
    // 0x80170968: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x8017096C: lw          $t2, 0x98($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X98);
    // 0x80170970: lui         $t1, 0x40
    ctx->r9 = S32(0X40 << 16);
    // 0x80170974: ori         $t1, $t1, 0x49F8
    ctx->r9 = ctx->r9 | 0X49F8;
    // 0x80170978: b           L_801709B8
    // 0x8017097C: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
        goto L_801709B8;
    // 0x8017097C: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
L_80170980:
    // 0x80170980: lui         $t3, 0x8011
    ctx->r11 = S32(0X8011 << 16);
    // 0x80170984: lw          $t3, -0x4514($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4514);
    // 0x80170988: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8017098C: lui         $t5, 0xE200
    ctx->r13 = S32(0XE200 << 16);
    // 0x80170990: sw          $t3, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r11;
    // 0x80170994: lw          $t6, 0x94($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X94);
    // 0x80170998: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x8017099C: sw          $t4, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r12;
    // 0x801709A0: ori         $t5, $t5, 0x1C
    ctx->r13 = ctx->r13 | 0X1C;
    // 0x801709A4: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x801709A8: lw          $t8, 0x94($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X94);
    // 0x801709AC: lui         $t7, 0x44
    ctx->r15 = S32(0X44 << 16);
    // 0x801709B0: ori         $t7, $t7, 0x2078
    ctx->r15 = ctx->r15 | 0X2078;
    // 0x801709B4: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
L_801709B8:
    // 0x801709B8: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x801709BC: lw          $t9, -0x4514($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4514);
    // 0x801709C0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x801709C4: lui         $t1, 0xFCFF
    ctx->r9 = S32(0XFCFF << 16);
    // 0x801709C8: sw          $t9, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r25;
    // 0x801709CC: lw          $t2, 0x90($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X90);
    // 0x801709D0: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x801709D4: sw          $t0, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r8;
    // 0x801709D8: ori         $t1, $t1, 0xFFFF
    ctx->r9 = ctx->r9 | 0XFFFF;
    // 0x801709DC: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x801709E0: lw          $t4, 0x90($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X90);
    // 0x801709E4: lui         $t3, 0xFFFD
    ctx->r11 = S32(0XFFFD << 16);
    // 0x801709E8: ori         $t3, $t3, 0xF6FB
    ctx->r11 = ctx->r11 | 0XF6FB;
    // 0x801709EC: b           L_80170D70
    // 0x801709F0: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
        goto L_80170D70;
    // 0x801709F0: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
L_801709F4:
    // 0x801709F4: lui         $t5, 0x8011
    ctx->r13 = S32(0X8011 << 16);
    // 0x801709F8: lw          $t5, -0x4514($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4514);
    // 0x801709FC: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80170A00: lui         $t7, 0xDE00
    ctx->r15 = S32(0XDE00 << 16);
    // 0x80170A04: sw          $t5, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r13;
    // 0x80170A08: lw          $t8, 0x8C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8C);
    // 0x80170A0C: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x80170A10: sw          $t6, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r14;
    // 0x80170A14: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80170A18: lw          $t0, 0x8C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X8C);
    // 0x80170A1C: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x80170A20: addiu       $t9, $t9, -0x51D0
    ctx->r25 = ADD32(ctx->r25, -0X51D0);
    // 0x80170A24: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x80170A28: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x80170A2C: lw          $t1, -0x4514($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4514);
    // 0x80170A30: lui         $t3, 0xE700
    ctx->r11 = S32(0XE700 << 16);
    // 0x80170A34: sw          $t1, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r9;
    // 0x80170A38: lw          $t4, 0x88($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X88);
    // 0x80170A3C: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x80170A40: sw          $t2, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r10;
    // 0x80170A44: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x80170A48: lw          $t5, 0x88($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X88);
    // 0x80170A4C: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80170A50: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
    // 0x80170A54: lbu         $t6, 0xFB($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0XFB);
    // 0x80170A58: beq         $t6, $at, L_80170A9C
    if (ctx->r14 == ctx->r1) {
        // 0x80170A5C: nop
    
            goto L_80170A9C;
    }
    // 0x80170A5C: nop

    // 0x80170A60: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x80170A64: lw          $t7, -0x4514($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4514);
    // 0x80170A68: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80170A6C: lui         $t9, 0xE200
    ctx->r25 = S32(0XE200 << 16);
    // 0x80170A70: sw          $t7, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r15;
    // 0x80170A74: lw          $t0, 0x84($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X84);
    // 0x80170A78: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x80170A7C: sw          $t8, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r24;
    // 0x80170A80: ori         $t9, $t9, 0x1C
    ctx->r25 = ctx->r25 | 0X1C;
    // 0x80170A84: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80170A88: lw          $t2, 0x84($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X84);
    // 0x80170A8C: lui         $t1, 0x40
    ctx->r9 = S32(0X40 << 16);
    // 0x80170A90: ori         $t1, $t1, 0x49F8
    ctx->r9 = ctx->r9 | 0X49F8;
    // 0x80170A94: b           L_80170AD4
    // 0x80170A98: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
        goto L_80170AD4;
    // 0x80170A98: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
L_80170A9C:
    // 0x80170A9C: lui         $t3, 0x8011
    ctx->r11 = S32(0X8011 << 16);
    // 0x80170AA0: lw          $t3, -0x4514($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4514);
    // 0x80170AA4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80170AA8: lui         $t5, 0xE200
    ctx->r13 = S32(0XE200 << 16);
    // 0x80170AAC: sw          $t3, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r11;
    // 0x80170AB0: lw          $t6, 0x80($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X80);
    // 0x80170AB4: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x80170AB8: sw          $t4, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r12;
    // 0x80170ABC: ori         $t5, $t5, 0x1C
    ctx->r13 = ctx->r13 | 0X1C;
    // 0x80170AC0: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x80170AC4: lw          $t8, 0x80($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X80);
    // 0x80170AC8: lui         $t7, 0x44
    ctx->r15 = S32(0X44 << 16);
    // 0x80170ACC: ori         $t7, $t7, 0x2078
    ctx->r15 = ctx->r15 | 0X2078;
    // 0x80170AD0: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
L_80170AD4:
    // 0x80170AD4: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x80170AD8: lw          $t9, -0x4514($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4514);
    // 0x80170ADC: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80170AE0: lui         $t1, 0xFC32
    ctx->r9 = S32(0XFC32 << 16);
    // 0x80170AE4: sw          $t9, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r25;
    // 0x80170AE8: lw          $t2, 0x7C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X7C);
    // 0x80170AEC: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x80170AF0: sw          $t0, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r8;
    // 0x80170AF4: ori         $t1, $t1, 0x4664
    ctx->r9 = ctx->r9 | 0X4664;
    // 0x80170AF8: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x80170AFC: lw          $t4, 0x7C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X7C);
    // 0x80170B00: lui         $t3, 0xFF8F
    ctx->r11 = S32(0XFF8F << 16);
    // 0x80170B04: ori         $t3, $t3, 0xFFFF
    ctx->r11 = ctx->r11 | 0XFFFF;
    // 0x80170B08: b           L_80170D70
    // 0x80170B0C: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
        goto L_80170D70;
    // 0x80170B0C: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
L_80170B10:
    // 0x80170B10: lui         $t5, 0x8011
    ctx->r13 = S32(0X8011 << 16);
    // 0x80170B14: lw          $t5, -0x4514($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4514);
    // 0x80170B18: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80170B1C: lui         $t7, 0xDE00
    ctx->r15 = S32(0XDE00 << 16);
    // 0x80170B20: sw          $t5, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r13;
    // 0x80170B24: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
    // 0x80170B28: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x80170B2C: sw          $t6, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r14;
    // 0x80170B30: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80170B34: lw          $t0, 0x78($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X78);
    // 0x80170B38: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x80170B3C: addiu       $t9, $t9, -0x5218
    ctx->r25 = ADD32(ctx->r25, -0X5218);
    // 0x80170B40: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x80170B44: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x80170B48: lw          $t1, -0x4514($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4514);
    // 0x80170B4C: lui         $t3, 0xE700
    ctx->r11 = S32(0XE700 << 16);
    // 0x80170B50: sw          $t1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r9;
    // 0x80170B54: lw          $t4, 0x74($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X74);
    // 0x80170B58: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x80170B5C: sw          $t2, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r10;
    // 0x80170B60: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x80170B64: lw          $t5, 0x74($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X74);
    // 0x80170B68: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80170B6C: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
    // 0x80170B70: lbu         $t6, 0xFB($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0XFB);
    // 0x80170B74: beq         $t6, $at, L_80170BB8
    if (ctx->r14 == ctx->r1) {
        // 0x80170B78: nop
    
            goto L_80170BB8;
    }
    // 0x80170B78: nop

    // 0x80170B7C: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x80170B80: lw          $t7, -0x4514($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4514);
    // 0x80170B84: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80170B88: lui         $t9, 0xE200
    ctx->r25 = S32(0XE200 << 16);
    // 0x80170B8C: sw          $t7, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r15;
    // 0x80170B90: lw          $t0, 0x70($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X70);
    // 0x80170B94: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x80170B98: sw          $t8, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r24;
    // 0x80170B9C: ori         $t9, $t9, 0x1C
    ctx->r25 = ctx->r25 | 0X1C;
    // 0x80170BA0: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80170BA4: lw          $t2, 0x70($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X70);
    // 0x80170BA8: lui         $t1, 0xC810
    ctx->r9 = S32(0XC810 << 16);
    // 0x80170BAC: ori         $t1, $t1, 0x49F8
    ctx->r9 = ctx->r9 | 0X49F8;
    // 0x80170BB0: b           L_80170BF0
    // 0x80170BB4: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
        goto L_80170BF0;
    // 0x80170BB4: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
L_80170BB8:
    // 0x80170BB8: lui         $t3, 0x8011
    ctx->r11 = S32(0X8011 << 16);
    // 0x80170BBC: lw          $t3, -0x4514($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4514);
    // 0x80170BC0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80170BC4: lui         $t5, 0xE200
    ctx->r13 = S32(0XE200 << 16);
    // 0x80170BC8: sw          $t3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r11;
    // 0x80170BCC: lw          $t6, 0x6C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X6C);
    // 0x80170BD0: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x80170BD4: sw          $t4, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r12;
    // 0x80170BD8: ori         $t5, $t5, 0x1C
    ctx->r13 = ctx->r13 | 0X1C;
    // 0x80170BDC: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x80170BE0: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
    // 0x80170BE4: lui         $t7, 0xC811
    ctx->r15 = S32(0XC811 << 16);
    // 0x80170BE8: ori         $t7, $t7, 0x2078
    ctx->r15 = ctx->r15 | 0X2078;
    // 0x80170BEC: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
L_80170BF0:
    // 0x80170BF0: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x80170BF4: lw          $t9, -0x4514($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4514);
    // 0x80170BF8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80170BFC: lui         $t1, 0xFC32
    ctx->r9 = S32(0XFC32 << 16);
    // 0x80170C00: sw          $t9, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r25;
    // 0x80170C04: lw          $t2, 0x68($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X68);
    // 0x80170C08: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x80170C0C: sw          $t0, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r8;
    // 0x80170C10: ori         $t1, $t1, 0x7FFF
    ctx->r9 = ctx->r9 | 0X7FFF;
    // 0x80170C14: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x80170C18: lw          $t4, 0x68($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X68);
    // 0x80170C1C: lui         $t3, 0xFF0F
    ctx->r11 = S32(0XFF0F << 16);
    // 0x80170C20: ori         $t3, $t3, 0xFC3F
    ctx->r11 = ctx->r11 | 0XFC3F;
    // 0x80170C24: b           L_80170D70
    // 0x80170C28: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
        goto L_80170D70;
    // 0x80170C28: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
L_80170C2C:
    // 0x80170C2C: lui         $t5, 0x8011
    ctx->r13 = S32(0X8011 << 16);
    // 0x80170C30: lw          $t5, -0x4514($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4514);
    // 0x80170C34: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80170C38: lui         $t7, 0xDE00
    ctx->r15 = S32(0XDE00 << 16);
    // 0x80170C3C: sw          $t5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r13;
    // 0x80170C40: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
    // 0x80170C44: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x80170C48: sw          $t6, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r14;
    // 0x80170C4C: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80170C50: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x80170C54: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x80170C58: addiu       $t9, $t9, -0x5188
    ctx->r25 = ADD32(ctx->r25, -0X5188);
    // 0x80170C5C: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x80170C60: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x80170C64: lw          $t1, -0x4514($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4514);
    // 0x80170C68: lui         $t3, 0xE700
    ctx->r11 = S32(0XE700 << 16);
    // 0x80170C6C: sw          $t1, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r9;
    // 0x80170C70: lw          $t4, 0x60($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X60);
    // 0x80170C74: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x80170C78: sw          $t2, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r10;
    // 0x80170C7C: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x80170C80: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
    // 0x80170C84: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80170C88: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
    // 0x80170C8C: lbu         $t6, 0xFB($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0XFB);
    // 0x80170C90: beq         $t6, $at, L_80170D08
    if (ctx->r14 == ctx->r1) {
        // 0x80170C94: nop
    
            goto L_80170D08;
    }
    // 0x80170C94: nop

    // 0x80170C98: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x80170C9C: lw          $t7, -0x4514($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4514);
    // 0x80170CA0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80170CA4: lui         $t9, 0xE200
    ctx->r25 = S32(0XE200 << 16);
    // 0x80170CA8: sw          $t7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r15;
    // 0x80170CAC: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x80170CB0: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x80170CB4: sw          $t8, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r24;
    // 0x80170CB8: ori         $t9, $t9, 0x1C
    ctx->r25 = ctx->r25 | 0X1C;
    // 0x80170CBC: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80170CC0: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x80170CC4: lui         $t1, 0xC810
    ctx->r9 = S32(0XC810 << 16);
    // 0x80170CC8: ori         $t1, $t1, 0x49F8
    ctx->r9 = ctx->r9 | 0X49F8;
    // 0x80170CCC: lui         $t3, 0x8011
    ctx->r11 = S32(0X8011 << 16);
    // 0x80170CD0: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x80170CD4: lw          $t3, -0x4514($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4514);
    // 0x80170CD8: lui         $t5, 0xFC32
    ctx->r13 = S32(0XFC32 << 16);
    // 0x80170CDC: ori         $t5, $t5, 0x7E04
    ctx->r13 = ctx->r13 | 0X7E04;
    // 0x80170CE0: sw          $t3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r11;
    // 0x80170CE4: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x80170CE8: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x80170CEC: sw          $t4, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r12;
    // 0x80170CF0: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x80170CF4: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x80170CF8: lui         $t7, 0xFF0F
    ctx->r15 = S32(0XFF0F << 16);
    // 0x80170CFC: ori         $t7, $t7, 0xFDFF
    ctx->r15 = ctx->r15 | 0XFDFF;
    // 0x80170D00: b           L_80170D70
    // 0x80170D04: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
        goto L_80170D70;
    // 0x80170D04: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
L_80170D08:
    // 0x80170D08: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x80170D0C: lw          $t9, -0x4514($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4514);
    // 0x80170D10: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80170D14: lui         $t1, 0xE200
    ctx->r9 = S32(0XE200 << 16);
    // 0x80170D18: sw          $t9, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r25;
    // 0x80170D1C: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x80170D20: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x80170D24: sw          $t0, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r8;
    // 0x80170D28: ori         $t1, $t1, 0x1C
    ctx->r9 = ctx->r9 | 0X1C;
    // 0x80170D2C: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x80170D30: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x80170D34: lui         $t3, 0xC811
    ctx->r11 = S32(0XC811 << 16);
    // 0x80170D38: ori         $t3, $t3, 0x2078
    ctx->r11 = ctx->r11 | 0X2078;
    // 0x80170D3C: lui         $t5, 0x8011
    ctx->r13 = S32(0X8011 << 16);
    // 0x80170D40: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    // 0x80170D44: lw          $t5, -0x4514($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4514);
    // 0x80170D48: lui         $t7, 0xFC32
    ctx->r15 = S32(0XFC32 << 16);
    // 0x80170D4C: ori         $t7, $t7, 0x7FFF
    ctx->r15 = ctx->r15 | 0X7FFF;
    // 0x80170D50: sw          $t5, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r13;
    // 0x80170D54: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x80170D58: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x80170D5C: sw          $t6, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r14;
    // 0x80170D60: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80170D64: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x80170D68: addiu       $t9, $zero, -0x9C8
    ctx->r25 = ADD32(0, -0X9C8);
    // 0x80170D6C: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
L_80170D70:
    // 0x80170D70: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x80170D74: lw          $t1, -0x4514($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4514);
    // 0x80170D78: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80170D7C: lui         $t3, 0xE700
    ctx->r11 = S32(0XE700 << 16);
    // 0x80170D80: sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
    // 0x80170D84: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x80170D88: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x80170D8C: sw          $t2, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r10;
    // 0x80170D90: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x80170D94: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x80170D98: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x80170D9C: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x80170DA0: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
    // 0x80170DA4: lw          $t6, -0x4514($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4514);
    // 0x80170DA8: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80170DAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80170DB0: sw          $t6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r14;
    // 0x80170DB4: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x80170DB8: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x80170DBC: sw          $t7, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r15;
    // 0x80170DC0: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80170DC4: lbu         $t0, 0xEF($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0XEF);
    // 0x80170DC8: lbu         $t3, 0xF3($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0XF3);
    // 0x80170DCC: lbu         $t7, 0xF7($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0XF7);
    // 0x80170DD0: andi        $t1, $t0, 0xFF
    ctx->r9 = ctx->r8 & 0XFF;
    // 0x80170DD4: sll         $t2, $t1, 24
    ctx->r10 = S32(ctx->r9 << 24);
    // 0x80170DD8: andi        $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 & 0XFF;
    // 0x80170DDC: lbu         $t1, 0xFB($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0XFB);
    // 0x80170DE0: sll         $t5, $t4, 16
    ctx->r13 = S32(ctx->r12 << 16);
    // 0x80170DE4: or          $t6, $t2, $t5
    ctx->r14 = ctx->r10 | ctx->r13;
    // 0x80170DE8: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x80170DEC: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x80170DF0: sll         $t9, $t8, 8
    ctx->r25 = S32(ctx->r24 << 8);
    // 0x80170DF4: or          $t0, $t6, $t9
    ctx->r8 = ctx->r14 | ctx->r25;
    // 0x80170DF8: andi        $t3, $t1, 0xFF
    ctx->r11 = ctx->r9 & 0XFF;
    // 0x80170DFC: or          $t4, $t0, $t3
    ctx->r12 = ctx->r8 | ctx->r11;
    // 0x80170E00: lui         $t5, 0x8011
    ctx->r13 = S32(0X8011 << 16);
    // 0x80170E04: sw          $t4, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r12;
    // 0x80170E08: lw          $t5, -0x4514($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4514);
    // 0x80170E0C: lui         $t8, 0xD700
    ctx->r24 = S32(0XD700 << 16);
    // 0x80170E10: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80170E14: sw          $t5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r13;
    // 0x80170E18: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x80170E1C: addiu       $t7, $t5, 0x8
    ctx->r15 = ADD32(ctx->r13, 0X8);
    // 0x80170E20: sw          $t7, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r15;
    // 0x80170E24: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x80170E28: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x80170E2C: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80170E30: sw          $t9, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r25;
    // 0x80170E34: lwc1        $f4, 0x108($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X108);
    // 0x80170E38: lw          $t0, 0xE4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XE4);
    // 0x80170E3C: lwc1        $f18, 0x11C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X11C);
    // 0x80170E40: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80170E44: lwc1        $f4, 0x120($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X120);
    // 0x80170E48: lwc1        $f16, 0x118($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X118);
    // 0x80170E4C: lwc1        $f10, 0x114($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X114);
    // 0x80170E50: lwc1        $f8, 0x110($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X110);
    // 0x80170E54: lwc1        $f6, 0x10C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X10C);
    // 0x80170E58: sll         $t3, $t0, 2
    ctx->r11 = S32(ctx->r8 << 2);
    // 0x80170E5C: addu        $a0, $a0, $t3
    ctx->r4 = ADD32(ctx->r4, ctx->r11);
    // 0x80170E60: lw          $a0, 0x2530($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2530);
    // 0x80170E64: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x80170E68: lw          $a3, 0x104($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X104);
    // 0x80170E6C: lw          $a2, 0x100($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X100);
    // 0x80170E70: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    // 0x80170E74: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x80170E78: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x80170E7C: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x80170E80: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x80170E84: jal         0x800C58E8
    // 0x80170E88: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_800C58E8(rdram, ctx);
        goto after_0;
    // 0x80170E88: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_0:
L_80170E8C:
    // 0x80170E8C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80170E90: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80170E94: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
    // 0x80170E98: jr          $ra
    // 0x80170E9C: nop

    return;
    // 0x80170E9C: nop

;}
RECOMP_FUNC void func_80170EA0_02FC30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80170EA0: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x80170EA4: lbu         $t6, 0xB3($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0XB3);
    // 0x80170EA8: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80170EAC: sw          $a0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r4;
    // 0x80170EB0: sw          $a1, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r5;
    // 0x80170EB4: sw          $a2, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r6;
    // 0x80170EB8: sw          $a3, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r7;
    // 0x80170EBC: beq         $t6, $zero, L_80171508
    if (ctx->r14 == 0) {
        // 0x80170EC0: sw          $s0, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r16;
            goto L_80171508;
    }
    // 0x80170EC0: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80170EC4: lbu         $t7, 0xA3($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0XA3);
    // 0x80170EC8: addiu       $at, $zero, 0x5F
    ctx->r1 = ADD32(0, 0X5F);
    // 0x80170ECC: bne         $t7, $at, L_80170EDC
    if (ctx->r15 != ctx->r1) {
        // 0x80170ED0: nop
    
            goto L_80170EDC;
    }
    // 0x80170ED0: nop

    // 0x80170ED4: b           L_80170F44
    // 0x80170ED8: sw          $zero, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = 0;
        goto L_80170F44;
    // 0x80170ED8: sw          $zero, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = 0;
L_80170EDC:
    // 0x80170EDC: lbu         $t8, 0xA3($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0XA3);
    // 0x80170EE0: slti        $at, $t8, 0x30
    ctx->r1 = SIGNED(ctx->r24) < 0X30 ? 1 : 0;
    // 0x80170EE4: bne         $at, $zero, L_80170F00
    if (ctx->r1 != 0) {
        // 0x80170EE8: slti        $at, $t8, 0x3A
        ctx->r1 = SIGNED(ctx->r24) < 0X3A ? 1 : 0;
            goto L_80170F00;
    }
    // 0x80170EE8: slti        $at, $t8, 0x3A
    ctx->r1 = SIGNED(ctx->r24) < 0X3A ? 1 : 0;
    // 0x80170EEC: beq         $at, $zero, L_80170F00
    if (ctx->r1 == 0) {
        // 0x80170EF0: nop
    
            goto L_80170F00;
    }
    // 0x80170EF0: nop

    // 0x80170EF4: addiu       $t9, $t8, -0x2E
    ctx->r25 = ADD32(ctx->r24, -0X2E);
    // 0x80170EF8: b           L_80170F44
    // 0x80170EFC: sw          $t9, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r25;
        goto L_80170F44;
    // 0x80170EFC: sw          $t9, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r25;
L_80170F00:
    // 0x80170F00: lbu         $t0, 0xA3($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0XA3);
    // 0x80170F04: slti        $at, $t0, 0x41
    ctx->r1 = SIGNED(ctx->r8) < 0X41 ? 1 : 0;
    // 0x80170F08: bne         $at, $zero, L_80170F24
    if (ctx->r1 != 0) {
        // 0x80170F0C: slti        $at, $t0, 0x5B
        ctx->r1 = SIGNED(ctx->r8) < 0X5B ? 1 : 0;
            goto L_80170F24;
    }
    // 0x80170F0C: slti        $at, $t0, 0x5B
    ctx->r1 = SIGNED(ctx->r8) < 0X5B ? 1 : 0;
    // 0x80170F10: beq         $at, $zero, L_80170F24
    if (ctx->r1 == 0) {
        // 0x80170F14: nop
    
            goto L_80170F24;
    }
    // 0x80170F14: nop

    // 0x80170F18: addiu       $t1, $t0, -0x35
    ctx->r9 = ADD32(ctx->r8, -0X35);
    // 0x80170F1C: b           L_80170F44
    // 0x80170F20: sw          $t1, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r9;
        goto L_80170F44;
    // 0x80170F20: sw          $t1, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r9;
L_80170F24:
    // 0x80170F24: lbu         $t2, 0xA3($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0XA3);
    // 0x80170F28: slti        $at, $t2, 0x61
    ctx->r1 = SIGNED(ctx->r10) < 0X61 ? 1 : 0;
    // 0x80170F2C: bne         $at, $zero, L_80171508
    if (ctx->r1 != 0) {
        // 0x80170F30: slti        $at, $t2, 0x7B
        ctx->r1 = SIGNED(ctx->r10) < 0X7B ? 1 : 0;
            goto L_80171508;
    }
    // 0x80170F30: slti        $at, $t2, 0x7B
    ctx->r1 = SIGNED(ctx->r10) < 0X7B ? 1 : 0;
    // 0x80170F34: beq         $at, $zero, L_80171508
    if (ctx->r1 == 0) {
        // 0x80170F38: nop
    
            goto L_80171508;
    }
    // 0x80170F38: nop

    // 0x80170F3C: addiu       $t3, $t2, -0x55
    ctx->r11 = ADD32(ctx->r10, -0X55);
    // 0x80170F40: sw          $t3, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r11;
L_80170F44:
    // 0x80170F44: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x80170F48: lhu         $s0, -0x4530($s0)
    ctx->r16 = MEM_HU(ctx->r16, -0X4530);
    // 0x80170F4C: andi        $t4, $s0, 0xC000
    ctx->r12 = ctx->r16 & 0XC000;
    // 0x80170F50: or          $s0, $t4, $zero
    ctx->r16 = ctx->r12 | 0;
    // 0x80170F54: beq         $s0, $zero, L_80170F74
    if (ctx->r16 == 0) {
        // 0x80170F58: addiu       $at, $zero, 0x4000
        ctx->r1 = ADD32(0, 0X4000);
            goto L_80170F74;
    }
    // 0x80170F58: addiu       $at, $zero, 0x4000
    ctx->r1 = ADD32(0, 0X4000);
    // 0x80170F5C: beq         $s0, $at, L_801711AC
    if (ctx->r16 == ctx->r1) {
        // 0x80170F60: ori         $at, $zero, 0x8000
        ctx->r1 = 0 | 0X8000;
            goto L_801711AC;
    }
    // 0x80170F60: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80170F64: beq         $s0, $at, L_80171090
    if (ctx->r16 == ctx->r1) {
        // 0x80170F68: nop
    
            goto L_80171090;
    }
    // 0x80170F68: nop

    // 0x80170F6C: b           L_801712C4
    // 0x80170F70: nop

        goto L_801712C4;
    // 0x80170F70: nop

L_80170F74:
    // 0x80170F74: lui         $t5, 0x8011
    ctx->r13 = S32(0X8011 << 16);
    // 0x80170F78: lw          $t5, -0x4514($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4514);
    // 0x80170F7C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80170F80: lui         $t7, 0xDE00
    ctx->r15 = S32(0XDE00 << 16);
    // 0x80170F84: sw          $t5, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r13;
    // 0x80170F88: lw          $t8, 0x98($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X98);
    // 0x80170F8C: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x80170F90: sw          $t6, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r14;
    // 0x80170F94: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80170F98: lw          $t0, 0x98($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X98);
    // 0x80170F9C: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x80170FA0: addiu       $t9, $t9, -0x5260
    ctx->r25 = ADD32(ctx->r25, -0X5260);
    // 0x80170FA4: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x80170FA8: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x80170FAC: lw          $t1, -0x4514($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4514);
    // 0x80170FB0: lui         $t3, 0xE700
    ctx->r11 = S32(0XE700 << 16);
    // 0x80170FB4: sw          $t1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r9;
    // 0x80170FB8: lw          $t4, 0x94($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X94);
    // 0x80170FBC: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x80170FC0: sw          $t2, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r10;
    // 0x80170FC4: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x80170FC8: lw          $t5, 0x94($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X94);
    // 0x80170FCC: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80170FD0: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
    // 0x80170FD4: lbu         $t6, 0xB3($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0XB3);
    // 0x80170FD8: beq         $t6, $at, L_8017101C
    if (ctx->r14 == ctx->r1) {
        // 0x80170FDC: nop
    
            goto L_8017101C;
    }
    // 0x80170FDC: nop

    // 0x80170FE0: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x80170FE4: lw          $t7, -0x4514($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4514);
    // 0x80170FE8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80170FEC: lui         $t9, 0xE200
    ctx->r25 = S32(0XE200 << 16);
    // 0x80170FF0: sw          $t7, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r15;
    // 0x80170FF4: lw          $t0, 0x90($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X90);
    // 0x80170FF8: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x80170FFC: sw          $t8, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r24;
    // 0x80171000: ori         $t9, $t9, 0x1C
    ctx->r25 = ctx->r25 | 0X1C;
    // 0x80171004: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80171008: lw          $t2, 0x90($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X90);
    // 0x8017100C: lui         $t1, 0x40
    ctx->r9 = S32(0X40 << 16);
    // 0x80171010: ori         $t1, $t1, 0x49F8
    ctx->r9 = ctx->r9 | 0X49F8;
    // 0x80171014: b           L_80171054
    // 0x80171018: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
        goto L_80171054;
    // 0x80171018: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
L_8017101C:
    // 0x8017101C: lui         $t3, 0x8011
    ctx->r11 = S32(0X8011 << 16);
    // 0x80171020: lw          $t3, -0x4514($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4514);
    // 0x80171024: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80171028: lui         $t5, 0xE200
    ctx->r13 = S32(0XE200 << 16);
    // 0x8017102C: sw          $t3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r11;
    // 0x80171030: lw          $t6, 0x8C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8C);
    // 0x80171034: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x80171038: sw          $t4, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r12;
    // 0x8017103C: ori         $t5, $t5, 0x1C
    ctx->r13 = ctx->r13 | 0X1C;
    // 0x80171040: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x80171044: lw          $t8, 0x8C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8C);
    // 0x80171048: lui         $t7, 0x44
    ctx->r15 = S32(0X44 << 16);
    // 0x8017104C: ori         $t7, $t7, 0x2078
    ctx->r15 = ctx->r15 | 0X2078;
    // 0x80171050: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
L_80171054:
    // 0x80171054: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x80171058: lw          $t9, -0x4514($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4514);
    // 0x8017105C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80171060: lui         $t1, 0xFCFF
    ctx->r9 = S32(0XFCFF << 16);
    // 0x80171064: sw          $t9, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r25;
    // 0x80171068: lw          $t2, 0x88($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X88);
    // 0x8017106C: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x80171070: sw          $t0, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r8;
    // 0x80171074: ori         $t1, $t1, 0xFFFF
    ctx->r9 = ctx->r9 | 0XFFFF;
    // 0x80171078: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x8017107C: lw          $t4, 0x88($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X88);
    // 0x80171080: lui         $t3, 0xFFFD
    ctx->r11 = S32(0XFFFD << 16);
    // 0x80171084: ori         $t3, $t3, 0xF6FB
    ctx->r11 = ctx->r11 | 0XF6FB;
    // 0x80171088: b           L_801713D8
    // 0x8017108C: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
        goto L_801713D8;
    // 0x8017108C: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
L_80171090:
    // 0x80171090: lui         $t5, 0x8011
    ctx->r13 = S32(0X8011 << 16);
    // 0x80171094: lw          $t5, -0x4514($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4514);
    // 0x80171098: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8017109C: lui         $t7, 0xDE00
    ctx->r15 = S32(0XDE00 << 16);
    // 0x801710A0: sw          $t5, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r13;
    // 0x801710A4: lw          $t8, 0x84($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X84);
    // 0x801710A8: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x801710AC: sw          $t6, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r14;
    // 0x801710B0: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x801710B4: lw          $t0, 0x84($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X84);
    // 0x801710B8: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x801710BC: addiu       $t9, $t9, -0x51D0
    ctx->r25 = ADD32(ctx->r25, -0X51D0);
    // 0x801710C0: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x801710C4: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x801710C8: lw          $t1, -0x4514($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4514);
    // 0x801710CC: lui         $t3, 0xE700
    ctx->r11 = S32(0XE700 << 16);
    // 0x801710D0: sw          $t1, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r9;
    // 0x801710D4: lw          $t4, 0x80($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X80);
    // 0x801710D8: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x801710DC: sw          $t2, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r10;
    // 0x801710E0: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x801710E4: lw          $t5, 0x80($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X80);
    // 0x801710E8: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x801710EC: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
    // 0x801710F0: lbu         $t6, 0xB3($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0XB3);
    // 0x801710F4: beq         $t6, $at, L_80171138
    if (ctx->r14 == ctx->r1) {
        // 0x801710F8: nop
    
            goto L_80171138;
    }
    // 0x801710F8: nop

    // 0x801710FC: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x80171100: lw          $t7, -0x4514($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4514);
    // 0x80171104: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80171108: lui         $t9, 0xE200
    ctx->r25 = S32(0XE200 << 16);
    // 0x8017110C: sw          $t7, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r15;
    // 0x80171110: lw          $t0, 0x7C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X7C);
    // 0x80171114: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x80171118: sw          $t8, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r24;
    // 0x8017111C: ori         $t9, $t9, 0x1C
    ctx->r25 = ctx->r25 | 0X1C;
    // 0x80171120: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80171124: lw          $t2, 0x7C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X7C);
    // 0x80171128: lui         $t1, 0x40
    ctx->r9 = S32(0X40 << 16);
    // 0x8017112C: ori         $t1, $t1, 0x49F8
    ctx->r9 = ctx->r9 | 0X49F8;
    // 0x80171130: b           L_80171170
    // 0x80171134: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
        goto L_80171170;
    // 0x80171134: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
L_80171138:
    // 0x80171138: lui         $t3, 0x8011
    ctx->r11 = S32(0X8011 << 16);
    // 0x8017113C: lw          $t3, -0x4514($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4514);
    // 0x80171140: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80171144: lui         $t5, 0xE200
    ctx->r13 = S32(0XE200 << 16);
    // 0x80171148: sw          $t3, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r11;
    // 0x8017114C: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
    // 0x80171150: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x80171154: sw          $t4, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r12;
    // 0x80171158: ori         $t5, $t5, 0x1C
    ctx->r13 = ctx->r13 | 0X1C;
    // 0x8017115C: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x80171160: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
    // 0x80171164: lui         $t7, 0x44
    ctx->r15 = S32(0X44 << 16);
    // 0x80171168: ori         $t7, $t7, 0x2078
    ctx->r15 = ctx->r15 | 0X2078;
    // 0x8017116C: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
L_80171170:
    // 0x80171170: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x80171174: lw          $t9, -0x4514($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4514);
    // 0x80171178: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8017117C: lui         $t1, 0xFC32
    ctx->r9 = S32(0XFC32 << 16);
    // 0x80171180: sw          $t9, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r25;
    // 0x80171184: lw          $t2, 0x74($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X74);
    // 0x80171188: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x8017118C: sw          $t0, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r8;
    // 0x80171190: ori         $t1, $t1, 0x3864
    ctx->r9 = ctx->r9 | 0X3864;
    // 0x80171194: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x80171198: lw          $t4, 0x74($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X74);
    // 0x8017119C: lui         $t3, 0xFF73
    ctx->r11 = S32(0XFF73 << 16);
    // 0x801711A0: ori         $t3, $t3, 0xFFFF
    ctx->r11 = ctx->r11 | 0XFFFF;
    // 0x801711A4: b           L_801713D8
    // 0x801711A8: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
        goto L_801713D8;
    // 0x801711A8: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
L_801711AC:
    // 0x801711AC: lui         $t5, 0x8011
    ctx->r13 = S32(0X8011 << 16);
    // 0x801711B0: lw          $t5, -0x4514($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4514);
    // 0x801711B4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x801711B8: lui         $t7, 0xDE00
    ctx->r15 = S32(0XDE00 << 16);
    // 0x801711BC: sw          $t5, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r13;
    // 0x801711C0: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
    // 0x801711C4: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x801711C8: sw          $t6, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r14;
    // 0x801711CC: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x801711D0: lw          $t0, 0x70($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X70);
    // 0x801711D4: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x801711D8: addiu       $t9, $t9, -0x5218
    ctx->r25 = ADD32(ctx->r25, -0X5218);
    // 0x801711DC: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x801711E0: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x801711E4: lw          $t1, -0x4514($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4514);
    // 0x801711E8: lui         $t3, 0xE700
    ctx->r11 = S32(0XE700 << 16);
    // 0x801711EC: sw          $t1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r9;
    // 0x801711F0: lw          $t4, 0x6C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X6C);
    // 0x801711F4: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x801711F8: sw          $t2, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r10;
    // 0x801711FC: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x80171200: lw          $t5, 0x6C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X6C);
    // 0x80171204: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80171208: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
    // 0x8017120C: lbu         $t6, 0xB3($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0XB3);
    // 0x80171210: beq         $t6, $at, L_80171254
    if (ctx->r14 == ctx->r1) {
        // 0x80171214: nop
    
            goto L_80171254;
    }
    // 0x80171214: nop

    // 0x80171218: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x8017121C: lw          $t7, -0x4514($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4514);
    // 0x80171220: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80171224: lui         $t9, 0xE200
    ctx->r25 = S32(0XE200 << 16);
    // 0x80171228: sw          $t7, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r15;
    // 0x8017122C: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
    // 0x80171230: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x80171234: sw          $t8, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r24;
    // 0x80171238: ori         $t9, $t9, 0x1C
    ctx->r25 = ctx->r25 | 0X1C;
    // 0x8017123C: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80171240: lw          $t2, 0x68($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X68);
    // 0x80171244: lui         $t1, 0xC810
    ctx->r9 = S32(0XC810 << 16);
    // 0x80171248: ori         $t1, $t1, 0x49F8
    ctx->r9 = ctx->r9 | 0X49F8;
    // 0x8017124C: b           L_8017128C
    // 0x80171250: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
        goto L_8017128C;
    // 0x80171250: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
L_80171254:
    // 0x80171254: lui         $t3, 0x8011
    ctx->r11 = S32(0X8011 << 16);
    // 0x80171258: lw          $t3, -0x4514($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4514);
    // 0x8017125C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80171260: lui         $t5, 0xE200
    ctx->r13 = S32(0XE200 << 16);
    // 0x80171264: sw          $t3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r11;
    // 0x80171268: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
    // 0x8017126C: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x80171270: sw          $t4, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r12;
    // 0x80171274: ori         $t5, $t5, 0x1C
    ctx->r13 = ctx->r13 | 0X1C;
    // 0x80171278: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x8017127C: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
    // 0x80171280: lui         $t7, 0xC811
    ctx->r15 = S32(0XC811 << 16);
    // 0x80171284: ori         $t7, $t7, 0x2078
    ctx->r15 = ctx->r15 | 0X2078;
    // 0x80171288: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
L_8017128C:
    // 0x8017128C: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x80171290: lw          $t9, -0x4514($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4514);
    // 0x80171294: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80171298: lui         $t1, 0xFC32
    ctx->r9 = S32(0XFC32 << 16);
    // 0x8017129C: sw          $t9, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r25;
    // 0x801712A0: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x801712A4: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x801712A8: sw          $t0, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r8;
    // 0x801712AC: ori         $t1, $t1, 0x39FF
    ctx->r9 = ctx->r9 | 0X39FF;
    // 0x801712B0: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x801712B4: lw          $t4, 0x60($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X60);
    // 0x801712B8: addiu       $t3, $zero, -0x1C8
    ctx->r11 = ADD32(0, -0X1C8);
    // 0x801712BC: b           L_801713D8
    // 0x801712C0: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
        goto L_801713D8;
    // 0x801712C0: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
L_801712C4:
    // 0x801712C4: lui         $t5, 0x8011
    ctx->r13 = S32(0X8011 << 16);
    // 0x801712C8: lw          $t5, -0x4514($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4514);
    // 0x801712CC: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x801712D0: lui         $t7, 0xDE00
    ctx->r15 = S32(0XDE00 << 16);
    // 0x801712D4: sw          $t5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r13;
    // 0x801712D8: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x801712DC: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x801712E0: sw          $t6, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r14;
    // 0x801712E4: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x801712E8: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x801712EC: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x801712F0: addiu       $t9, $t9, -0x5188
    ctx->r25 = ADD32(ctx->r25, -0X5188);
    // 0x801712F4: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x801712F8: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x801712FC: lw          $t1, -0x4514($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4514);
    // 0x80171300: lui         $t3, 0xE700
    ctx->r11 = S32(0XE700 << 16);
    // 0x80171304: sw          $t1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r9;
    // 0x80171308: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x8017130C: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x80171310: sw          $t2, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r10;
    // 0x80171314: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x80171318: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    // 0x8017131C: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80171320: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
    // 0x80171324: lbu         $t6, 0xB3($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0XB3);
    // 0x80171328: beq         $t6, $at, L_8017136C
    if (ctx->r14 == ctx->r1) {
        // 0x8017132C: nop
    
            goto L_8017136C;
    }
    // 0x8017132C: nop

    // 0x80171330: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x80171334: lw          $t7, -0x4514($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4514);
    // 0x80171338: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8017133C: lui         $t9, 0xE200
    ctx->r25 = S32(0XE200 << 16);
    // 0x80171340: sw          $t7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r15;
    // 0x80171344: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x80171348: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8017134C: sw          $t8, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r24;
    // 0x80171350: ori         $t9, $t9, 0x1C
    ctx->r25 = ctx->r25 | 0X1C;
    // 0x80171354: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80171358: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x8017135C: lui         $t1, 0xC810
    ctx->r9 = S32(0XC810 << 16);
    // 0x80171360: ori         $t1, $t1, 0x49F8
    ctx->r9 = ctx->r9 | 0X49F8;
    // 0x80171364: b           L_801713A4
    // 0x80171368: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
        goto L_801713A4;
    // 0x80171368: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
L_8017136C:
    // 0x8017136C: lui         $t3, 0x8011
    ctx->r11 = S32(0X8011 << 16);
    // 0x80171370: lw          $t3, -0x4514($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4514);
    // 0x80171374: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80171378: lui         $t5, 0xE200
    ctx->r13 = S32(0XE200 << 16);
    // 0x8017137C: sw          $t3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r11;
    // 0x80171380: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x80171384: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x80171388: sw          $t4, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r12;
    // 0x8017138C: ori         $t5, $t5, 0x1C
    ctx->r13 = ctx->r13 | 0X1C;
    // 0x80171390: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x80171394: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x80171398: lui         $t7, 0xC811
    ctx->r15 = S32(0XC811 << 16);
    // 0x8017139C: ori         $t7, $t7, 0x2078
    ctx->r15 = ctx->r15 | 0X2078;
    // 0x801713A0: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
L_801713A4:
    // 0x801713A4: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x801713A8: lw          $t9, -0x4514($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4514);
    // 0x801713AC: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x801713B0: lui         $t1, 0xFC32
    ctx->r9 = S32(0XFC32 << 16);
    // 0x801713B4: sw          $t9, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r25;
    // 0x801713B8: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x801713BC: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x801713C0: sw          $t0, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r8;
    // 0x801713C4: ori         $t1, $t1, 0x39FF
    ctx->r9 = ctx->r9 | 0X39FF;
    // 0x801713C8: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x801713CC: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x801713D0: addiu       $t3, $zero, -0x1C8
    ctx->r11 = ADD32(0, -0X1C8);
    // 0x801713D4: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
L_801713D8:
    // 0x801713D8: lui         $t5, 0x8011
    ctx->r13 = S32(0X8011 << 16);
    // 0x801713DC: lw          $t5, -0x4514($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4514);
    // 0x801713E0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x801713E4: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x801713E8: sw          $t5, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r13;
    // 0x801713EC: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x801713F0: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x801713F4: sw          $t6, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r14;
    // 0x801713F8: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x801713FC: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x80171400: lui         $t0, 0x8011
    ctx->r8 = S32(0X8011 << 16);
    // 0x80171404: lui         $t2, 0xFA00
    ctx->r10 = S32(0XFA00 << 16);
    // 0x80171408: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x8017140C: lw          $t0, -0x4514($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X4514);
    // 0x80171410: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    // 0x80171414: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x80171418: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x8017141C: sw          $t1, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r9;
    // 0x80171420: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x80171424: lbu         $t4, 0xA7($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0XA7);
    // 0x80171428: lbu         $t7, 0xAB($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0XAB);
    // 0x8017142C: lbu         $t1, 0xAF($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0XAF);
    // 0x80171430: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x80171434: sll         $t6, $t5, 24
    ctx->r14 = S32(ctx->r13 << 24);
    // 0x80171438: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x8017143C: lbu         $t5, 0xB3($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0XB3);
    // 0x80171440: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x80171444: or          $t0, $t6, $t9
    ctx->r8 = ctx->r14 | ctx->r25;
    // 0x80171448: andi        $t2, $t1, 0xFF
    ctx->r10 = ctx->r9 & 0XFF;
    // 0x8017144C: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x80171450: sll         $t3, $t2, 8
    ctx->r11 = S32(ctx->r10 << 8);
    // 0x80171454: or          $t4, $t0, $t3
    ctx->r12 = ctx->r8 | ctx->r11;
    // 0x80171458: andi        $t7, $t5, 0xFF
    ctx->r15 = ctx->r13 & 0XFF;
    // 0x8017145C: or          $t8, $t4, $t7
    ctx->r24 = ctx->r12 | ctx->r15;
    // 0x80171460: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x80171464: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80171468: lw          $t9, -0x4514($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4514);
    // 0x8017146C: lui         $t2, 0xD700
    ctx->r10 = S32(0XD700 << 16);
    // 0x80171470: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80171474: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    // 0x80171478: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x8017147C: addiu       $t1, $t9, 0x8
    ctx->r9 = ADD32(ctx->r25, 0X8);
    // 0x80171480: sw          $t1, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r9;
    // 0x80171484: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x80171488: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x8017148C: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80171490: sw          $t3, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r11;
    // 0x80171494: lwc1        $f16, 0xD8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x80171498: lwc1        $f10, 0xD4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x8017149C: lwc1        $f8, 0xD0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XD0);
    // 0x801714A0: lwc1        $f6, 0xCC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x801714A4: lwc1        $f4, 0xC8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x801714A8: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x801714AC: lw          $a3, 0xC4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC4);
    // 0x801714B0: lw          $a2, 0xC0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XC0);
    // 0x801714B4: lwc1        $f14, 0xBC($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x801714B8: lwc1        $f12, 0xB8($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x801714BC: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x801714C0: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x801714C4: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x801714C8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x801714CC: jal         0x800C4A04
    // 0x801714D0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800C4A04(rdram, ctx);
        goto after_0;
    // 0x801714D0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x801714D4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801714D8: addiu       $t7, $t7, -0x3F68
    ctx->r15 = ADD32(ctx->r15, -0X3F68);
    // 0x801714DC: addiu       $a0, $t7, 0xC0
    ctx->r4 = ADD32(ctx->r15, 0XC0);
    // 0x801714E0: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x801714E4: jal         0x800D6F30
    // 0x801714E8: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    guMtxCatF_recomp(rdram, ctx);
        goto after_1;
    // 0x801714E8: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    after_1:
    // 0x801714EC: lw          $t8, 0x9C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X9C);
    // 0x801714F0: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x801714F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801714F8: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x801714FC: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x80171500: jal         0x800C5E40
    // 0x80171504: lw          $a0, 0x2530($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2530);
    func_800C5E40(rdram, ctx);
        goto after_2;
    // 0x80171504: lw          $a0, 0x2530($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2530);
    after_2:
L_80171508:
    // 0x80171508: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8017150C: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80171510: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    // 0x80171514: jr          $ra
    // 0x80171518: nop

    return;
    // 0x80171518: nop

;}
