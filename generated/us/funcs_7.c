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

RECOMP_FUNC void _collectPVoices_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D8FA8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800D8FAC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800D8FB0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800D8FB4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800D8FB8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800D8FBC: lw          $s0, 0x14($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X14);
    // 0x800D8FC0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800D8FC4: addiu       $s2, $a0, 0x4
    ctx->r18 = ADD32(ctx->r4, 0X4);
    // 0x800D8FC8: beql        $s0, $zero, L_800D8FF4
    if (ctx->r16 == 0) {
        // 0x800D8FCC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800D8FF4;
    }
    goto skip_0;
    // 0x800D8FCC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
L_800D8FD0:
    // 0x800D8FD0: jal         0x800D8840
    // 0x800D8FD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    alUnlink_recomp(rdram, ctx);
        goto after_0;
    // 0x800D8FD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800D8FD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D8FDC: jal         0x800D8870
    // 0x800D8FE0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    alLink_recomp(rdram, ctx);
        goto after_1;
    // 0x800D8FE0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_1:
    // 0x800D8FE4: lw          $s0, 0x14($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X14);
    // 0x800D8FE8: bne         $s0, $zero, L_800D8FD0
    if (ctx->r16 != 0) {
        // 0x800D8FEC: nop
    
            goto L_800D8FD0;
    }
    // 0x800D8FEC: nop

    // 0x800D8FF0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800D8FF4:
    // 0x800D8FF4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800D8FF8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800D8FFC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800D9000: jr          $ra
    // 0x800D9004: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800D9004: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void __freeParam_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D9008: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x800D900C: lw          $v0, -0x3210($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X3210);
    // 0x800D9010: lw          $t6, 0x2C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X2C);
    // 0x800D9014: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800D9018: jr          $ra
    // 0x800D901C: sw          $a0, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r4;
    return;
    // 0x800D901C: sw          $a0, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r4;
;}
RECOMP_FUNC void __allocParam_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D9020: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x800D9024: lw          $v0, -0x3210($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X3210);
    // 0x800D9028: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800D902C: lw          $a0, 0x2C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X2C);
    // 0x800D9030: beq         $a0, $zero, L_800D9048
    if (ctx->r4 == 0) {
        // 0x800D9034: nop
    
            goto L_800D9048;
    }
    // 0x800D9034: nop

    // 0x800D9038: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800D903C: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800D9040: sw          $t6, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r14;
    // 0x800D9044: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
L_800D9048:
    // 0x800D9048: jr          $ra
    // 0x800D904C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800D904C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void __dummy_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D9050: jr          $ra
    // 0x800D9054: nop

    return;
    // 0x800D9054: nop

;}
RECOMP_FUNC void alAudioFrame_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D9058: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x800D905C: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x800D9060: lui         $s1, 0x800F
    ctx->r17 = S32(0X800F << 16);
    // 0x800D9064: lw          $s1, -0x3210($s1)
    ctx->r17 = MEM_W(ctx->r17, -0X3210);
    // 0x800D9068: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x800D906C: sw          $s7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r23;
    // 0x800D9070: sw          $s6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r22;
    // 0x800D9074: sw          $s5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r21;
    // 0x800D9078: sw          $s4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r20;
    // 0x800D907C: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x800D9080: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x800D9084: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x800D9088: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x800D908C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800D9090: sw          $a0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r4;
    // 0x800D9094: sw          $a1, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r5;
    // 0x800D9098: sh          $zero, 0xAA($sp)
    MEM_H(0XAA, ctx->r29) = 0;
    // 0x800D909C: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x800D90A0: or          $s3, $a3, $zero
    ctx->r19 = ctx->r7 | 0;
    // 0x800D90A4: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x800D90A8: bne         $t7, $zero, L_800D90BC
    if (ctx->r15 != 0) {
        // 0x800D90AC: or          $s5, $a2, $zero
        ctx->r21 = ctx->r6 | 0;
            goto L_800D90BC;
    }
    // 0x800D90AC: or          $s5, $a2, $zero
    ctx->r21 = ctx->r6 | 0;
    // 0x800D90B0: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x800D90B4: b           L_800D92BC
    // 0x800D90B8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_800D92BC;
    // 0x800D90B8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_800D90BC:
    // 0x800D90BC: sw          $zero, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = 0;
    // 0x800D90C0: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800D90C4: lui         $v1, 0x7FFF
    ctx->r3 = S32(0X7FFF << 16);
    // 0x800D90C8: ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // 0x800D90CC: beq         $v0, $zero, L_800D9108
    if (ctx->r2 == 0) {
        // 0x800D90D0: addiu       $s2, $zero, -0x10
        ctx->r18 = ADD32(0, -0X10);
            goto L_800D9108;
    }
    // 0x800D90D0: addiu       $s2, $zero, -0x10
    ctx->r18 = ADD32(0, -0X10);
    // 0x800D90D4: lw          $a0, 0x20($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X20);
    // 0x800D90D8: lw          $t9, 0x10($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X10);
L_800D90DC:
    // 0x800D90DC: subu        $t0, $t9, $a0
    ctx->r8 = SUB32(ctx->r25, ctx->r4);
    // 0x800D90E0: slt         $at, $t0, $v1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800D90E4: beql        $at, $zero, L_800D9100
    if (ctx->r1 == 0) {
        // 0x800D90E8: lw          $v0, 0x0($v0)
        ctx->r2 = MEM_W(ctx->r2, 0X0);
            goto L_800D9100;
    }
    goto skip_0;
    // 0x800D90E8: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    skip_0:
    // 0x800D90EC: sw          $v0, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r2;
    // 0x800D90F0: lw          $t1, 0x10($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X10);
    // 0x800D90F4: lw          $a0, 0x20($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X20);
    // 0x800D90F8: subu        $v1, $t1, $a0
    ctx->r3 = SUB32(ctx->r9, ctx->r4);
    // 0x800D90FC: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
L_800D9100:
    // 0x800D9100: bnel        $v0, $zero, L_800D90DC
    if (ctx->r2 != 0) {
        // 0x800D9104: lw          $t9, 0x10($v0)
        ctx->r25 = MEM_W(ctx->r2, 0X10);
            goto L_800D90DC;
    }
    goto skip_1;
    // 0x800D9104: lw          $t9, 0x10($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X10);
    skip_1:
L_800D9108:
    // 0x800D9108: lw          $t2, 0xB4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XB4);
    // 0x800D910C: lw          $a0, 0x20($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X20);
    // 0x800D9110: lw          $v0, 0x10($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X10);
    // 0x800D9114: subu        $t3, $v0, $a0
    ctx->r11 = SUB32(ctx->r2, ctx->r4);
    // 0x800D9118: slt         $at, $t3, $s3
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800D911C: beq         $at, $zero, L_800D9200
    if (ctx->r1 == 0) {
        // 0x800D9120: sw          $v0, 0x1C($s1)
        MEM_W(0X1C, ctx->r17) = ctx->r2;
            goto L_800D9200;
    }
    // 0x800D9120: sw          $v0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r2;
    // 0x800D9124: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800D9128: mtc1        $at, $f23
    ctx->f_odd[(23 - 1) * 2] = ctx->r1;
    // 0x800D912C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D9130: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x800D9134: ldc1        $f20, -0x1F88($at)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r1, -0X1F88);
L_800D9138:
    // 0x800D9138: lw          $t4, 0x1C($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X1C);
    // 0x800D913C: lui         $s0, 0x7FFF
    ctx->r16 = S32(0X7FFF << 16);
    // 0x800D9140: ori         $s0, $s0, 0xFFFF
    ctx->r16 = ctx->r16 | 0XFFFF;
    // 0x800D9144: and         $t5, $t4, $s2
    ctx->r13 = ctx->r12 & ctx->r18;
    // 0x800D9148: sw          $t5, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r13;
    // 0x800D914C: lw          $a0, 0xB4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB4);
    // 0x800D9150: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800D9154: jalr        $t9
    // 0x800D9158: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800D9158: nop

    after_0:
    // 0x800D915C: lw          $t8, 0x44($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X44);
    // 0x800D9160: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800D9164: lw          $t0, 0xB4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB4);
    // 0x800D9168: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x800D916C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800D9170: lw          $t1, 0x10($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X10);
    // 0x800D9174: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800D9178: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800D917C: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x800D9180: div.d       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f20.d); 
    ctx->f4.d = DIV_D(ctx->f18.d, ctx->f20.d);
    // 0x800D9184: add.d       $f8, $f4, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f22.d); 
    ctx->f8.d = ctx->f4.d + ctx->f22.d;
    // 0x800D9188: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
    // 0x800D918C: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800D9190: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x800D9194: nop

    // 0x800D9198: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x800D919C: sw          $t2, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r10;
    // 0x800D91A0: sw          $zero, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = 0;
    // 0x800D91A4: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800D91A8: beql        $v1, $zero, L_800D91E8
    if (ctx->r3 == 0) {
        // 0x800D91AC: lw          $t7, 0xB4($sp)
        ctx->r15 = MEM_W(ctx->r29, 0XB4);
            goto L_800D91E8;
    }
    goto skip_2;
    // 0x800D91AC: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
    skip_2:
    // 0x800D91B0: lw          $a0, 0x20($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X20);
    // 0x800D91B4: lw          $t3, 0x10($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X10);
L_800D91B8:
    // 0x800D91B8: subu        $t4, $t3, $a0
    ctx->r12 = SUB32(ctx->r11, ctx->r4);
    // 0x800D91BC: slt         $at, $t4, $s0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x800D91C0: beql        $at, $zero, L_800D91DC
    if (ctx->r1 == 0) {
        // 0x800D91C4: lw          $v1, 0x0($v1)
        ctx->r3 = MEM_W(ctx->r3, 0X0);
            goto L_800D91DC;
    }
    goto skip_3;
    // 0x800D91C4: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    skip_3:
    // 0x800D91C8: sw          $v1, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r3;
    // 0x800D91CC: lw          $t5, 0x10($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X10);
    // 0x800D91D0: lw          $a0, 0x20($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X20);
    // 0x800D91D4: subu        $s0, $t5, $a0
    ctx->r16 = SUB32(ctx->r13, ctx->r4);
    // 0x800D91D8: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
L_800D91DC:
    // 0x800D91DC: bnel        $v1, $zero, L_800D91B8
    if (ctx->r3 != 0) {
        // 0x800D91E0: lw          $t3, 0x10($v1)
        ctx->r11 = MEM_W(ctx->r3, 0X10);
            goto L_800D91B8;
    }
    goto skip_4;
    // 0x800D91E0: lw          $t3, 0x10($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X10);
    skip_4:
    // 0x800D91E4: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
L_800D91E8:
    // 0x800D91E8: lw          $a0, 0x20($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X20);
    // 0x800D91EC: lw          $v0, 0x10($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X10);
    // 0x800D91F0: subu        $t9, $v0, $a0
    ctx->r25 = SUB32(ctx->r2, ctx->r4);
    // 0x800D91F4: slt         $at, $t9, $s3
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800D91F8: bne         $at, $zero, L_800D9138
    if (ctx->r1 != 0) {
        // 0x800D91FC: sw          $v0, 0x1C($s1)
        MEM_W(0X1C, ctx->r17) = ctx->r2;
            goto L_800D9138;
    }
    // 0x800D91FC: sw          $v0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r2;
L_800D9200:
    // 0x800D9200: lw          $t8, 0x1C($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X1C);
    // 0x800D9204: addiu       $s2, $zero, -0x10
    ctx->r18 = ADD32(0, -0X10);
    // 0x800D9208: addiu       $s7, $sp, 0xAA
    ctx->r23 = ADD32(ctx->r29, 0XAA);
    // 0x800D920C: and         $t6, $t8, $s2
    ctx->r14 = ctx->r24 & ctx->r18;
    // 0x800D9210: blez        $s3, L_800D929C
    if (SIGNED(ctx->r19) <= 0) {
        // 0x800D9214: sw          $t6, 0x1C($s1)
        MEM_W(0X1C, ctx->r17) = ctx->r14;
            goto L_800D929C;
    }
    // 0x800D9214: sw          $t6, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r14;
    // 0x800D9218: lui         $s6, 0x700
    ctx->r22 = S32(0X700 << 16);
L_800D921C:
    // 0x800D921C: lw          $v0, 0x48($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X48);
    // 0x800D9220: or          $s0, $s3, $zero
    ctx->r16 = ctx->r19 | 0;
    // 0x800D9224: slt         $at, $v0, $s3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800D9228: beq         $at, $zero, L_800D9238
    if (ctx->r1 == 0) {
        // 0x800D922C: nop
    
            goto L_800D9238;
    }
    // 0x800D922C: nop

    // 0x800D9230: b           L_800D9238
    // 0x800D9234: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_800D9238;
    // 0x800D9234: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_800D9238:
    // 0x800D9238: sw          $s6, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r22;
    // 0x800D923C: sw          $zero, 0x4($s4)
    MEM_W(0X4, ctx->r20) = 0;
    // 0x800D9240: lw          $s2, 0x38($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X38);
    // 0x800D9244: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x800D9248: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x800D924C: lw          $t9, 0x8($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X8);
    // 0x800D9250: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800D9254: jalr        $t9
    // 0x800D9258: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800D9258: nop

    after_1:
    // 0x800D925C: lw          $a3, 0x20($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X20);
    // 0x800D9260: addiu       $t1, $s4, 0x8
    ctx->r9 = ADD32(ctx->r20, 0X8);
    // 0x800D9264: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800D9268: lw          $t9, 0x4($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X4);
    // 0x800D926C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800D9270: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x800D9274: jalr        $t9
    // 0x800D9278: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x800D9278: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_2:
    // 0x800D927C: lw          $t3, 0x20($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X20);
    // 0x800D9280: subu        $s3, $s3, $s0
    ctx->r19 = SUB32(ctx->r19, ctx->r16);
    // 0x800D9284: sll         $t0, $s0, 2
    ctx->r8 = S32(ctx->r16 << 2);
    // 0x800D9288: addu        $t4, $t3, $s0
    ctx->r12 = ADD32(ctx->r11, ctx->r16);
    // 0x800D928C: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x800D9290: addu        $s5, $s5, $t0
    ctx->r21 = ADD32(ctx->r21, ctx->r8);
    // 0x800D9294: bgtz        $s3, L_800D921C
    if (SIGNED(ctx->r19) > 0) {
        // 0x800D9298: sw          $t4, 0x20($s1)
        MEM_W(0X20, ctx->r17) = ctx->r12;
            goto L_800D921C;
    }
    // 0x800D9298: sw          $t4, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->r12;
L_800D929C:
    // 0x800D929C: lw          $t5, 0xB8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB8);
    // 0x800D92A0: lw          $t6, 0xBC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XBC);
    // 0x800D92A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800D92A8: subu        $t7, $s4, $t5
    ctx->r15 = SUB32(ctx->r20, ctx->r13);
    // 0x800D92AC: sra         $t8, $t7, 3
    ctx->r24 = S32(SIGNED(ctx->r15) >> 3);
    // 0x800D92B0: jal         0x800D8FA8
    // 0x800D92B4: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    _collectPVoices_recomp(rdram, ctx);
        goto after_3;
    // 0x800D92B4: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    after_3:
    // 0x800D92B8: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
L_800D92BC:
    // 0x800D92BC: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x800D92C0: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800D92C4: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x800D92C8: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x800D92CC: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x800D92D0: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x800D92D4: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x800D92D8: lw          $s4, 0x3C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X3C);
    // 0x800D92DC: lw          $s5, 0x40($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X40);
    // 0x800D92E0: lw          $s6, 0x44($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X44);
    // 0x800D92E4: lw          $s7, 0x48($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X48);
    // 0x800D92E8: jr          $ra
    // 0x800D92EC: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    return;
    // 0x800D92EC: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
;}
RECOMP_FUNC void alSynNew_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D92F0: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x800D92F4: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800D92F8: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x800D92FC: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x800D9300: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800D9304: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800D9308: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800D930C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800D9310: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800D9314: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800D9318: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800D931C: lw          $s7, 0x14($a1)
    ctx->r23 = MEM_W(ctx->r5, 0X14);
    // 0x800D9320: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x800D9324: lw          $t6, 0x4($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X4);
    // 0x800D9328: sw          $zero, 0x20($a0)
    MEM_W(0X20, ctx->r4) = 0;
    // 0x800D932C: sw          $zero, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = 0;
    // 0x800D9330: sw          $t6, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->r14;
    // 0x800D9334: lw          $t7, 0x18($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X18);
    // 0x800D9338: addiu       $t8, $zero, 0xA0
    ctx->r24 = ADD32(0, 0XA0);
    // 0x800D933C: sw          $t8, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->r24;
    // 0x800D9340: sw          $t7, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->r15;
    // 0x800D9344: lw          $t9, 0x10($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X10);
    // 0x800D9348: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x800D934C: or          $fp, $a1, $zero
    ctx->r30 = ctx->r5 | 0;
    // 0x800D9350: addiu       $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
    // 0x800D9354: sw          $t9, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r25;
    // 0x800D9358: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800D935C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800D9360: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800D9364: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800D9368: jal         0x800D8AE0
    // 0x800D936C: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    alHeapDBAlloc_recomp(rdram, ctx);
        goto after_0;
    // 0x800D936C: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_0:
    // 0x800D9370: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x800D9374: jal         0x800DD9B0
    // 0x800D9378: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    alSaveNew_recomp(rdram, ctx);
        goto after_1;
    // 0x800D9378: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x800D937C: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x800D9380: addiu       $t2, $zero, 0x4C
    ctx->r10 = ADD32(0, 0X4C);
    // 0x800D9384: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800D9388: sw          $t1, 0x38($s6)
    MEM_W(0X38, ctx->r22) = ctx->r9;
    // 0x800D938C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800D9390: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800D9394: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    // 0x800D9398: jal         0x800D8AE0
    // 0x800D939C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc_recomp(rdram, ctx);
        goto after_2;
    // 0x800D939C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x800D93A0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800D93A4: sw          $v0, 0x34($s6)
    MEM_W(0X34, ctx->r22) = ctx->r2;
    // 0x800D93A8: sw          $t3, 0x40($s6)
    MEM_W(0X40, ctx->r22) = ctx->r11;
    // 0x800D93AC: lw          $a3, 0x4($fp)
    ctx->r7 = MEM_W(ctx->r30, 0X4);
    // 0x800D93B0: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x800D93B4: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800D93B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800D93BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800D93C0: jal         0x800D8AE0
    // 0x800D93C4: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    alHeapDBAlloc_recomp(rdram, ctx);
        goto after_3;
    // 0x800D93C4: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_3:
    // 0x800D93C8: lw          $a0, 0x34($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X34);
    // 0x800D93CC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800D93D0: jal         0x800DDA48
    // 0x800D93D4: lw          $a2, 0x4($fp)
    ctx->r6 = MEM_W(ctx->r30, 0X4);
    alAuxBusNew_recomp(rdram, ctx);
        goto after_4;
    // 0x800D93D4: lw          $a2, 0x4($fp)
    ctx->r6 = MEM_W(ctx->r30, 0X4);
    after_4:
    // 0x800D93D8: addiu       $t5, $zero, 0x20
    ctx->r13 = ADD32(0, 0X20);
    // 0x800D93DC: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800D93E0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800D93E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800D93E8: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    // 0x800D93EC: jal         0x800D8AE0
    // 0x800D93F0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc_recomp(rdram, ctx);
        goto after_5;
    // 0x800D93F0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_5:
    // 0x800D93F4: sw          $v0, 0x30($s6)
    MEM_W(0X30, ctx->r22) = ctx->r2;
    // 0x800D93F8: lw          $a3, 0x4($fp)
    ctx->r7 = MEM_W(ctx->r30, 0X4);
    // 0x800D93FC: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x800D9400: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800D9404: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800D9408: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800D940C: jal         0x800D8AE0
    // 0x800D9410: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    alHeapDBAlloc_recomp(rdram, ctx);
        goto after_6;
    // 0x800D9410: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_6:
    // 0x800D9414: lw          $a0, 0x30($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X30);
    // 0x800D9418: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800D941C: jal         0x800DD9F4
    // 0x800D9420: lw          $a2, 0x4($fp)
    ctx->r6 = MEM_W(ctx->r30, 0X4);
    alMainBusNew_recomp(rdram, ctx);
        goto after_7;
    // 0x800D9420: lw          $a2, 0x4($fp)
    ctx->r6 = MEM_W(ctx->r30, 0X4);
    after_7:
    // 0x800D9424: lbu         $t7, 0x1C($fp)
    ctx->r15 = MEM_BU(ctx->r30, 0X1C);
    // 0x800D9428: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800D942C: or          $a2, $fp, $zero
    ctx->r6 = ctx->r30 | 0;
    // 0x800D9430: beq         $t7, $zero, L_800D944C
    if (ctx->r15 == 0) {
        // 0x800D9434: addiu       $a1, $zero, 0x2
        ctx->r5 = ADD32(0, 0X2);
            goto L_800D944C;
    }
    // 0x800D9434: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800D9438: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800D943C: jal         0x800DE150
    // 0x800D9440: or          $a3, $s7, $zero
    ctx->r7 = ctx->r23 | 0;
    alSynAllocFX_recomp(rdram, ctx);
        goto after_8;
    // 0x800D9440: or          $a3, $s7, $zero
    ctx->r7 = ctx->r23 | 0;
    after_8:
    // 0x800D9444: b           L_800D945C
    // 0x800D9448: sw          $zero, 0x4($s6)
    MEM_W(0X4, ctx->r22) = 0;
        goto L_800D945C;
    // 0x800D9448: sw          $zero, 0x4($s6)
    MEM_W(0X4, ctx->r22) = 0;
L_800D944C:
    // 0x800D944C: lw          $a0, 0x30($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X30);
    // 0x800D9450: jal         0x800DE1F0
    // 0x800D9454: lw          $a2, 0x34($s6)
    ctx->r6 = MEM_W(ctx->r22, 0X34);
    alAuxBusParam_recomp(rdram, ctx);
        goto after_9;
    // 0x800D9454: lw          $a2, 0x34($s6)
    ctx->r6 = MEM_W(ctx->r22, 0X34);
    after_9:
    // 0x800D9458: sw          $zero, 0x4($s6)
    MEM_W(0X4, ctx->r22) = 0;
L_800D945C:
    // 0x800D945C: sw          $zero, 0x8($s6)
    MEM_W(0X8, ctx->r22) = 0;
    // 0x800D9460: sw          $zero, 0x14($s6)
    MEM_W(0X14, ctx->r22) = 0;
    // 0x800D9464: sw          $zero, 0x18($s6)
    MEM_W(0X18, ctx->r22) = 0;
    // 0x800D9468: sw          $zero, 0xC($s6)
    MEM_W(0XC, ctx->r22) = 0;
    // 0x800D946C: sw          $zero, 0x10($s6)
    MEM_W(0X10, ctx->r22) = 0;
    // 0x800D9470: lw          $a3, 0x4($fp)
    ctx->r7 = MEM_W(ctx->r30, 0X4);
    // 0x800D9474: addiu       $t8, $zero, 0xDC
    ctx->r24 = ADD32(0, 0XDC);
    // 0x800D9478: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800D947C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800D9480: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800D9484: jal         0x800D8AE0
    // 0x800D9488: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    alHeapDBAlloc_recomp(rdram, ctx);
        goto after_10;
    // 0x800D9488: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_10:
    // 0x800D948C: lw          $t9, 0x4($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X4);
    // 0x800D9490: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800D9494: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800D9498: blez        $t9, L_800D9558
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800D949C: addiu       $a1, $s6, 0x4
        ctx->r5 = ADD32(ctx->r22, 0X4);
            goto L_800D9558;
    }
    // 0x800D949C: addiu       $a1, $s6, 0x4
    ctx->r5 = ADD32(ctx->r22, 0X4);
    // 0x800D94A0: addiu       $s1, $v0, 0x8C
    ctx->r17 = ADD32(ctx->r2, 0X8C);
    // 0x800D94A4: addiu       $s2, $v0, 0x58
    ctx->r18 = ADD32(ctx->r2, 0X58);
    // 0x800D94A8: addiu       $s3, $v0, 0x10
    ctx->r19 = ADD32(ctx->r2, 0X10);
    // 0x800D94AC: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
L_800D94B0:
    // 0x800D94B0: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x800D94B4: or          $s5, $s0, $zero
    ctx->r21 = ctx->r16 | 0;
    // 0x800D94B8: jal         0x800D8870
    // 0x800D94BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    alLink_recomp(rdram, ctx);
        goto after_11;
    // 0x800D94BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x800D94C0: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
    // 0x800D94C4: lw          $a1, 0x24($s6)
    ctx->r5 = MEM_W(ctx->r22, 0X24);
    // 0x800D94C8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800D94CC: jal         0x800DDB24
    // 0x800D94D0: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    alLoadNew_recomp(rdram, ctx);
        goto after_12;
    // 0x800D94D0: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_12:
    // 0x800D94D4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800D94D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800D94DC: jal         0x800DE340
    // 0x800D94E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    alLoadParam_recomp(rdram, ctx);
        goto after_13;
    // 0x800D94E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_13:
    // 0x800D94E4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800D94E8: jal         0x800DDA9C
    // 0x800D94EC: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    alResampleNew_recomp(rdram, ctx);
        goto after_14;
    // 0x800D94EC: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    after_14:
    // 0x800D94F0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800D94F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800D94F8: jal         0x800DEE90
    // 0x800D94FC: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    alResampleParam_recomp(rdram, ctx);
        goto after_15;
    // 0x800D94FC: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_15:
    // 0x800D9500: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800D9504: jal         0x800DDBCC
    // 0x800D9508: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    alEnvmixerNew_recomp(rdram, ctx);
        goto after_16;
    // 0x800D9508: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    after_16:
    // 0x800D950C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800D9510: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800D9514: jal         0x800DF2A4
    // 0x800D9518: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    alEnvmixerParam_recomp(rdram, ctx);
        goto after_17;
    // 0x800D9518: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_17:
    // 0x800D951C: lw          $a0, 0x34($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X34);
    // 0x800D9520: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800D9524: jal         0x800DFDF0
    // 0x800D9528: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_800DFDF0(rdram, ctx);
        goto after_18;
    // 0x800D9528: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_18:
    // 0x800D952C: addiu       $t0, $s5, 0x8C
    ctx->r8 = ADD32(ctx->r21, 0X8C);
    // 0x800D9530: sw          $t0, 0xC($s5)
    MEM_W(0XC, ctx->r21) = ctx->r8;
    // 0x800D9534: lw          $t1, 0x4($fp)
    ctx->r9 = MEM_W(ctx->r30, 0X4);
    // 0x800D9538: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800D953C: addiu       $s0, $s0, 0xDC
    ctx->r16 = ADD32(ctx->r16, 0XDC);
    // 0x800D9540: slt         $at, $s4, $t1
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800D9544: addiu       $s1, $s1, 0xDC
    ctx->r17 = ADD32(ctx->r17, 0XDC);
    // 0x800D9548: addiu       $s2, $s2, 0xDC
    ctx->r18 = ADD32(ctx->r18, 0XDC);
    // 0x800D954C: bne         $at, $zero, L_800D94B0
    if (ctx->r1 != 0) {
        // 0x800D9550: addiu       $s3, $s3, 0xDC
        ctx->r19 = ADD32(ctx->r19, 0XDC);
            goto L_800D94B0;
    }
    // 0x800D9550: addiu       $s3, $s3, 0xDC
    ctx->r19 = ADD32(ctx->r19, 0XDC);
    // 0x800D9554: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
L_800D9558:
    // 0x800D9558: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x800D955C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800D9560: jal         0x800DFF00
    // 0x800D9564: lw          $a2, 0x30($s6)
    ctx->r6 = MEM_W(ctx->r22, 0X30);
    alSaveParam_recomp(rdram, ctx);
        goto after_19;
    // 0x800D9564: lw          $a2, 0x30($s6)
    ctx->r6 = MEM_W(ctx->r22, 0X30);
    after_19:
    // 0x800D9568: lw          $a3, 0x8($fp)
    ctx->r7 = MEM_W(ctx->r30, 0X8);
    // 0x800D956C: addiu       $t2, $zero, 0x1C
    ctx->r10 = ADD32(0, 0X1C);
    // 0x800D9570: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800D9574: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800D9578: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800D957C: jal         0x800D8AE0
    // 0x800D9580: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    alHeapDBAlloc_recomp(rdram, ctx);
        goto after_20;
    // 0x800D9580: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_20:
    // 0x800D9584: sw          $zero, 0x2C($s6)
    MEM_W(0X2C, ctx->r22) = 0;
    // 0x800D9588: lw          $t3, 0x8($fp)
    ctx->r11 = MEM_W(ctx->r30, 0X8);
    // 0x800D958C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800D9590: blezl       $t3, L_800D95C0
    if (SIGNED(ctx->r11) <= 0) {
        // 0x800D9594: sw          $s7, 0x28($s6)
        MEM_W(0X28, ctx->r22) = ctx->r23;
            goto L_800D95C0;
    }
    goto skip_0;
    // 0x800D9594: sw          $s7, 0x28($s6)
    MEM_W(0X28, ctx->r22) = ctx->r23;
    skip_0:
    // 0x800D9598: lw          $t4, 0x2C($s6)
    ctx->r12 = MEM_W(ctx->r22, 0X2C);
L_800D959C:
    // 0x800D959C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800D95A0: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x800D95A4: sw          $v1, 0x2C($s6)
    MEM_W(0X2C, ctx->r22) = ctx->r3;
    // 0x800D95A8: lw          $t5, 0x8($fp)
    ctx->r13 = MEM_W(ctx->r30, 0X8);
    // 0x800D95AC: addiu       $v1, $v1, 0x1C
    ctx->r3 = ADD32(ctx->r3, 0X1C);
    // 0x800D95B0: slt         $at, $s4, $t5
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800D95B4: bnel        $at, $zero, L_800D959C
    if (ctx->r1 != 0) {
        // 0x800D95B8: lw          $t4, 0x2C($s6)
        ctx->r12 = MEM_W(ctx->r22, 0X2C);
            goto L_800D959C;
    }
    goto skip_1;
    // 0x800D95B8: lw          $t4, 0x2C($s6)
    ctx->r12 = MEM_W(ctx->r22, 0X2C);
    skip_1:
    // 0x800D95BC: sw          $s7, 0x28($s6)
    MEM_W(0X28, ctx->r22) = ctx->r23;
L_800D95C0:
    // 0x800D95C0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800D95C4: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x800D95C8: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x800D95CC: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800D95D0: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800D95D4: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800D95D8: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800D95DC: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800D95E0: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800D95E4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800D95E8: jr          $ra
    // 0x800D95EC: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x800D95EC: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void alSynAddPlayer_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D97E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D97E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D97E8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800D97EC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x800D97F0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800D97F4: jal         0x800D9740
    // 0x800D97F8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x800D97F8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800D97FC: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800D9800: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800D9804: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800D9808: lw          $t6, 0x20($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X20);
    // 0x800D980C: sw          $t6, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r14;
    // 0x800D9810: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x800D9814: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x800D9818: jal         0x800D9740
    // 0x800D981C: sw          $a1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r5;
    osSetIntMask_recomp(rdram, ctx);
        goto after_1;
    // 0x800D981C: sw          $a1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r5;
    after_1:
    // 0x800D9820: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D9824: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D9828: jr          $ra
    // 0x800D982C: nop

    return;
    // 0x800D982C: nop

;}
RECOMP_FUNC void _allocatePVoice_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D9830: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800D9834: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D9838: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800D983C: lw          $a3, 0x14($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X14);
    // 0x800D9840: sll         $t6, $a2, 16
    ctx->r14 = S32(ctx->r6 << 16);
    // 0x800D9844: sra         $a2, $t6, 16
    ctx->r6 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800D9848: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x800D984C: beq         $a3, $zero, L_800D9884
    if (ctx->r7 == 0) {
        // 0x800D9850: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800D9884;
    }
    // 0x800D9850: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800D9854: sw          $a3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r7;
    // 0x800D9858: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x800D985C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800D9860: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x800D9864: jal         0x800D8840
    // 0x800D9868: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    alUnlink_recomp(rdram, ctx);
        goto after_0;
    // 0x800D9868: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_0:
    // 0x800D986C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800D9870: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800D9874: jal         0x800D8870
    // 0x800D9878: addiu       $a1, $t0, 0xC
    ctx->r5 = ADD32(ctx->r8, 0XC);
    alLink_recomp(rdram, ctx);
        goto after_1;
    // 0x800D9878: addiu       $a1, $t0, 0xC
    ctx->r5 = ADD32(ctx->r8, 0XC);
    after_1:
    // 0x800D987C: b           L_800D9904
    // 0x800D9880: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
        goto L_800D9904;
    // 0x800D9880: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
L_800D9884:
    // 0x800D9884: lw          $a3, 0x4($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X4);
    // 0x800D9888: beq         $a3, $zero, L_800D98BC
    if (ctx->r7 == 0) {
        // 0x800D988C: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_800D98BC;
    }
    // 0x800D988C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800D9890: sw          $a3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r7;
    // 0x800D9894: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x800D9898: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800D989C: jal         0x800D8840
    // 0x800D98A0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    alUnlink_recomp(rdram, ctx);
        goto after_2;
    // 0x800D98A0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_2:
    // 0x800D98A4: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800D98A8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800D98AC: jal         0x800D8870
    // 0x800D98B0: addiu       $a1, $t0, 0xC
    ctx->r5 = ADD32(ctx->r8, 0XC);
    alLink_recomp(rdram, ctx);
        goto after_3;
    // 0x800D98B0: addiu       $a1, $t0, 0xC
    ctx->r5 = ADD32(ctx->r8, 0XC);
    after_3:
    // 0x800D98B4: b           L_800D9904
    // 0x800D98B8: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
        goto L_800D9904;
    // 0x800D98B8: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
L_800D98BC:
    // 0x800D98BC: lw          $a3, 0xC($t0)
    ctx->r7 = MEM_W(ctx->r8, 0XC);
    // 0x800D98C0: beql        $a3, $zero, L_800D9908
    if (ctx->r7 == 0) {
        // 0x800D98C4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D9908;
    }
    goto skip_0;
    // 0x800D98C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800D98C8: lw          $t8, 0x8($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X8);
L_800D98CC:
    // 0x800D98CC: lh          $t9, 0x16($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X16);
    // 0x800D98D0: slt         $at, $a2, $t9
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800D98D4: bnel        $at, $zero, L_800D98FC
    if (ctx->r1 != 0) {
        // 0x800D98D8: lw          $a3, 0x0($a3)
        ctx->r7 = MEM_W(ctx->r7, 0X0);
            goto L_800D98FC;
    }
    goto skip_1;
    // 0x800D98D8: lw          $a3, 0x0($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X0);
    skip_1:
    // 0x800D98DC: lw          $t1, 0xD8($a3)
    ctx->r9 = MEM_W(ctx->r7, 0XD8);
    // 0x800D98E0: bnel        $t1, $zero, L_800D98FC
    if (ctx->r9 != 0) {
        // 0x800D98E4: lw          $a3, 0x0($a3)
        ctx->r7 = MEM_W(ctx->r7, 0X0);
            goto L_800D98FC;
    }
    goto skip_2;
    // 0x800D98E4: lw          $a3, 0x0($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X0);
    skip_2:
    // 0x800D98E8: sw          $a3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r7;
    // 0x800D98EC: lw          $t2, 0x8($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X8);
    // 0x800D98F0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800D98F4: lh          $a2, 0x16($t2)
    ctx->r6 = MEM_H(ctx->r10, 0X16);
    // 0x800D98F8: lw          $a3, 0x0($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X0);
L_800D98FC:
    // 0x800D98FC: bnel        $a3, $zero, L_800D98CC
    if (ctx->r7 != 0) {
        // 0x800D9900: lw          $t8, 0x8($a3)
        ctx->r24 = MEM_W(ctx->r7, 0X8);
            goto L_800D98CC;
    }
    goto skip_3;
    // 0x800D9900: lw          $t8, 0x8($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X8);
    skip_3:
L_800D9904:
    // 0x800D9904: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D9908:
    // 0x800D9908: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800D990C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800D9910: jr          $ra
    // 0x800D9914: nop

    return;
    // 0x800D9914: nop

;}
RECOMP_FUNC void alSynAllocVoice_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D9918: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800D991C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D9920: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800D9924: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800D9928: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x800D992C: lh          $t6, 0x0($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X0);
    // 0x800D9930: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800D9934: sh          $t6, 0x16($a1)
    MEM_H(0X16, ctx->r5) = ctx->r14;
    // 0x800D9938: lbu         $t7, 0x4($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X4);
    // 0x800D993C: sw          $zero, 0xC($a1)
    MEM_W(0XC, ctx->r5) = 0;
    // 0x800D9940: sh          $t7, 0x1A($a1)
    MEM_H(0X1A, ctx->r5) = ctx->r15;
    // 0x800D9944: lh          $t8, 0x2($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X2);
    // 0x800D9948: sh          $zero, 0x14($a1)
    MEM_H(0X14, ctx->r5) = 0;
    // 0x800D994C: sw          $zero, 0x8($a1)
    MEM_W(0X8, ctx->r5) = 0;
    // 0x800D9950: sh          $t8, 0x18($a1)
    MEM_H(0X18, ctx->r5) = ctx->r24;
    // 0x800D9954: lh          $a2, 0x0($a2)
    ctx->r6 = MEM_H(ctx->r6, 0X0);
    // 0x800D9958: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800D995C: jal         0x800D9830
    // 0x800D9960: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    _allocatePVoice_recomp(rdram, ctx);
        goto after_0;
    // 0x800D9960: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x800D9964: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x800D9968: beql        $t9, $zero, L_800D9A40
    if (ctx->r25 == 0) {
        // 0x800D996C: lw          $v0, 0x2C($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X2C);
            goto L_800D9A40;
    }
    goto skip_0;
    // 0x800D996C: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x800D9970: beq         $v0, $zero, L_800D9A24
    if (ctx->r2 == 0) {
        // 0x800D9974: lw          $a0, 0xC($t9)
        ctx->r4 = MEM_W(ctx->r25, 0XC);
            goto L_800D9A24;
    }
    // 0x800D9974: lw          $a0, 0xC($t9)
    ctx->r4 = MEM_W(ctx->r25, 0XC);
    // 0x800D9978: addiu       $t0, $zero, 0x200
    ctx->r8 = ADD32(0, 0X200);
    // 0x800D997C: sw          $t0, 0xD8($t9)
    MEM_W(0XD8, ctx->r25) = ctx->r8;
    // 0x800D9980: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800D9984: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x800D9988: sw          $zero, 0x8($t2)
    MEM_W(0X8, ctx->r10) = 0;
    // 0x800D998C: jal         0x800D9020
    // 0x800D9990: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    __allocParam_recomp(rdram, ctx);
        goto after_1;
    // 0x800D9990: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_1:
    // 0x800D9994: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x800D9998: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800D999C: addiu       $t5, $zero, 0xB
    ctx->r13 = ADD32(0, 0XB);
    // 0x800D99A0: lw          $t4, 0x1C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X1C);
    // 0x800D99A4: sh          $t5, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r13;
    // 0x800D99A8: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x800D99AC: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x800D99B0: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800D99B4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800D99B8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800D99BC: lw          $t7, 0xD8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XD8);
    // 0x800D99C0: addiu       $t8, $t7, -0x40
    ctx->r24 = ADD32(ctx->r15, -0X40);
    // 0x800D99C4: sw          $t8, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r24;
    // 0x800D99C8: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800D99CC: jalr        $t9
    // 0x800D99D0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x800D99D0: nop

    after_2:
    // 0x800D99D4: jal         0x800D9020
    // 0x800D99D8: nop

    __allocParam_recomp(rdram, ctx);
        goto after_3;
    // 0x800D99D8: nop

    after_3:
    // 0x800D99DC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800D99E0: beq         $v0, $zero, L_800D9A2C
    if (ctx->r2 == 0) {
        // 0x800D99E4: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800D9A2C;
    }
    // 0x800D99E4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800D99E8: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x800D99EC: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x800D99F0: addiu       $t5, $zero, 0xF
    ctx->r13 = ADD32(0, 0XF);
    // 0x800D99F4: lw          $t1, 0x1C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X1C);
    // 0x800D99F8: lw          $t3, 0xD8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XD8);
    // 0x800D99FC: sh          $t5, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r13;
    // 0x800D9A00: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800D9A04: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x800D9A08: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x800D9A0C: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800D9A10: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800D9A14: jalr        $t9
    // 0x800D9A18: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x800D9A18: nop

    after_4:
    // 0x800D9A1C: b           L_800D9A30
    // 0x800D9A20: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
        goto L_800D9A30;
    // 0x800D9A20: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
L_800D9A24:
    // 0x800D9A24: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800D9A28: sw          $zero, 0xD8($t6)
    MEM_W(0XD8, ctx->r14) = 0;
L_800D9A2C:
    // 0x800D9A2C: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
L_800D9A30:
    // 0x800D9A30: sw          $s0, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r16;
    // 0x800D9A34: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800D9A38: sw          $t8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r24;
    // 0x800D9A3C: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
L_800D9A40:
    // 0x800D9A40: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800D9A44: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800D9A48: sltu        $t0, $zero, $v0
    ctx->r8 = 0 < ctx->r2 ? 1 : 0;
    // 0x800D9A4C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x800D9A50: jr          $ra
    // 0x800D9A54: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800D9A54: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800D9A58: nop

    // 0x800D9A5C: nop

;}
RECOMP_FUNC void alSynStopVoice_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D9A60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D9A64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D9A68: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800D9A6C: lw          $t6, 0x8($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X8);
    // 0x800D9A70: beql        $t6, $zero, L_800D9ACC
    if (ctx->r14 == 0) {
        // 0x800D9A74: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D9ACC;
    }
    goto skip_0;
    // 0x800D9A74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800D9A78: jal         0x800D9020
    // 0x800D9A7C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    __allocParam_recomp(rdram, ctx);
        goto after_0;
    // 0x800D9A7C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800D9A80: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x800D9A84: beq         $v0, $zero, L_800D9AC8
    if (ctx->r2 == 0) {
        // 0x800D9A88: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800D9AC8;
    }
    // 0x800D9A88: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800D9A8C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800D9A90: lw          $t9, 0x8($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X8);
    // 0x800D9A94: addiu       $t2, $zero, 0xF
    ctx->r10 = ADD32(0, 0XF);
    // 0x800D9A98: lw          $t8, 0x1C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1C);
    // 0x800D9A9C: lw          $t0, 0xD8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XD8);
    // 0x800D9AA0: sh          $t2, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r10;
    // 0x800D9AA4: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800D9AA8: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x800D9AAC: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x800D9AB0: lw          $t3, 0x8($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X8);
    // 0x800D9AB4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800D9AB8: lw          $a0, 0xC($t3)
    ctx->r4 = MEM_W(ctx->r11, 0XC);
    // 0x800D9ABC: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800D9AC0: jalr        $t9
    // 0x800D9AC4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800D9AC4: nop

    after_1:
L_800D9AC8:
    // 0x800D9AC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D9ACC:
    // 0x800D9ACC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D9AD0: jr          $ra
    // 0x800D9AD4: nop

    return;
    // 0x800D9AD4: nop

    // 0x800D9AD8: nop

    // 0x800D9ADC: nop

;}
RECOMP_FUNC void alSynSetVol_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D9AE0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800D9AE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D9AE8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800D9AEC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800D9AF0: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800D9AF4: lw          $t7, 0x8($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X8);
    // 0x800D9AF8: beql        $t7, $zero, L_800D9B70
    if (ctx->r15 == 0) {
        // 0x800D9AFC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D9B70;
    }
    goto skip_0;
    // 0x800D9AFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800D9B00: jal         0x800D9020
    // 0x800D9B04: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    __allocParam_recomp(rdram, ctx);
        goto after_0;
    // 0x800D9B04: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x800D9B08: beq         $v0, $zero, L_800D9B6C
    if (ctx->r2 == 0) {
        // 0x800D9B0C: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_800D9B6C;
    }
    // 0x800D9B0C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800D9B10: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800D9B14: lw          $t8, 0x1C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X1C);
    // 0x800D9B18: addiu       $t3, $zero, 0xB
    ctx->r11 = ADD32(0, 0XB);
    // 0x800D9B1C: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x800D9B20: lw          $t1, 0xD8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XD8);
    // 0x800D9B24: sh          $t3, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r11;
    // 0x800D9B28: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x800D9B2C: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x800D9B30: lh          $t4, 0x2A($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X2A);
    // 0x800D9B34: sw          $t4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r12;
    // 0x800D9B38: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800D9B3C: jal         0x800D8F18
    // 0x800D9B40: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    _timeToSamples_recomp(rdram, ctx);
        goto after_1;
    // 0x800D9B40: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x800D9B44: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x800D9B48: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800D9B4C: sw          $v0, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->r2;
    // 0x800D9B50: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x800D9B54: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800D9B58: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x800D9B5C: lw          $a0, 0xC($t6)
    ctx->r4 = MEM_W(ctx->r14, 0XC);
    // 0x800D9B60: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800D9B64: jalr        $t9
    // 0x800D9B68: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x800D9B68: nop

    after_2:
L_800D9B6C:
    // 0x800D9B6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D9B70:
    // 0x800D9B70: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800D9B74: jr          $ra
    // 0x800D9B78: nop

    return;
    // 0x800D9B78: nop

    // 0x800D9B7C: nop

;}
RECOMP_FUNC void alSynSetFXMix_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D9B80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D9B84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D9B88: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800D9B8C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800D9B90: lw          $t6, 0x8($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X8);
    // 0x800D9B94: beql        $t6, $zero, L_800D9C08
    if (ctx->r14 == 0) {
        // 0x800D9B98: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D9C08;
    }
    goto skip_0;
    // 0x800D9B98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800D9B9C: jal         0x800D9020
    // 0x800D9BA0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    __allocParam_recomp(rdram, ctx);
        goto after_0;
    // 0x800D9BA0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800D9BA4: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x800D9BA8: beq         $v0, $zero, L_800D9C04
    if (ctx->r2 == 0) {
        // 0x800D9BAC: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800D9C04;
    }
    // 0x800D9BAC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800D9BB0: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800D9BB4: lw          $t9, 0x8($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X8);
    // 0x800D9BB8: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
    // 0x800D9BBC: lw          $t8, 0x1C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1C);
    // 0x800D9BC0: lw          $t0, 0xD8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XD8);
    // 0x800D9BC4: sh          $t2, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r10;
    // 0x800D9BC8: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x800D9BCC: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x800D9BD0: lbu         $v1, 0x23($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X23);
    // 0x800D9BD4: bgez        $v1, L_800D9BE4
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800D9BD8: negu        $t3, $v1
        ctx->r11 = SUB32(0, ctx->r3);
            goto L_800D9BE4;
    }
    // 0x800D9BD8: negu        $t3, $v1
    ctx->r11 = SUB32(0, ctx->r3);
    // 0x800D9BDC: b           L_800D9BE8
    // 0x800D9BE0: sw          $t3, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r11;
        goto L_800D9BE8;
    // 0x800D9BE0: sw          $t3, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r11;
L_800D9BE4:
    // 0x800D9BE4: sw          $v1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r3;
L_800D9BE8:
    // 0x800D9BE8: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x800D9BEC: lw          $t4, 0x8($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X8);
    // 0x800D9BF0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800D9BF4: lw          $a0, 0xC($t4)
    ctx->r4 = MEM_W(ctx->r12, 0XC);
    // 0x800D9BF8: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800D9BFC: jalr        $t9
    // 0x800D9C00: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800D9C00: nop

    after_1:
L_800D9C04:
    // 0x800D9C04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D9C08:
    // 0x800D9C08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D9C0C: jr          $ra
    // 0x800D9C10: nop

    return;
    // 0x800D9C10: nop

    // 0x800D9C14: nop

    // 0x800D9C18: nop

    // 0x800D9C1C: nop

;}
RECOMP_FUNC void alSynStartVoice_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D9C20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D9C24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D9C28: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800D9C2C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800D9C30: lw          $t6, 0x8($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X8);
    // 0x800D9C34: beql        $t6, $zero, L_800D9CA0
    if (ctx->r14 == 0) {
        // 0x800D9C38: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D9CA0;
    }
    goto skip_0;
    // 0x800D9C38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800D9C3C: jal         0x800D9020
    // 0x800D9C40: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    __allocParam_recomp(rdram, ctx);
        goto after_0;
    // 0x800D9C40: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800D9C44: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x800D9C48: beq         $v0, $zero, L_800D9C9C
    if (ctx->r2 == 0) {
        // 0x800D9C4C: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800D9C9C;
    }
    // 0x800D9C4C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800D9C50: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800D9C54: lw          $t9, 0x8($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X8);
    // 0x800D9C58: addiu       $t2, $zero, 0xE
    ctx->r10 = ADD32(0, 0XE);
    // 0x800D9C5C: lw          $t8, 0x1C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1C);
    // 0x800D9C60: lw          $t0, 0xD8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XD8);
    // 0x800D9C64: sh          $t2, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r10;
    // 0x800D9C68: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800D9C6C: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x800D9C70: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x800D9C74: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x800D9C78: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800D9C7C: sw          $t3, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r11;
    // 0x800D9C80: lh          $t4, 0x1A($a3)
    ctx->r12 = MEM_H(ctx->r7, 0X1A);
    // 0x800D9C84: sh          $t4, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r12;
    // 0x800D9C88: lw          $t5, 0x8($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X8);
    // 0x800D9C8C: lw          $a0, 0xC($t5)
    ctx->r4 = MEM_W(ctx->r13, 0XC);
    // 0x800D9C90: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800D9C94: jalr        $t9
    // 0x800D9C98: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800D9C98: nop

    after_1:
L_800D9C9C:
    // 0x800D9C9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D9CA0:
    // 0x800D9CA0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D9CA4: jr          $ra
    // 0x800D9CA8: nop

    return;
    // 0x800D9CA8: nop

    // 0x800D9CAC: nop

;}
RECOMP_FUNC void alSynSetPan_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D9CB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D9CB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D9CB8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800D9CBC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800D9CC0: lw          $t6, 0x8($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X8);
    // 0x800D9CC4: beql        $t6, $zero, L_800D9D28
    if (ctx->r14 == 0) {
        // 0x800D9CC8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D9D28;
    }
    goto skip_0;
    // 0x800D9CC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800D9CCC: jal         0x800D9020
    // 0x800D9CD0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    __allocParam_recomp(rdram, ctx);
        goto after_0;
    // 0x800D9CD0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800D9CD4: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x800D9CD8: beq         $v0, $zero, L_800D9D24
    if (ctx->r2 == 0) {
        // 0x800D9CDC: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800D9D24;
    }
    // 0x800D9CDC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800D9CE0: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800D9CE4: lw          $t9, 0x8($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X8);
    // 0x800D9CE8: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x800D9CEC: lw          $t8, 0x1C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1C);
    // 0x800D9CF0: lw          $t0, 0xD8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XD8);
    // 0x800D9CF4: sh          $t2, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r10;
    // 0x800D9CF8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800D9CFC: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x800D9D00: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x800D9D04: lbu         $t3, 0x23($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X23);
    // 0x800D9D08: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800D9D0C: sw          $t3, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r11;
    // 0x800D9D10: lw          $t4, 0x8($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X8);
    // 0x800D9D14: lw          $a0, 0xC($t4)
    ctx->r4 = MEM_W(ctx->r12, 0XC);
    // 0x800D9D18: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800D9D1C: jalr        $t9
    // 0x800D9D20: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800D9D20: nop

    after_1:
L_800D9D24:
    // 0x800D9D24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D9D28:
    // 0x800D9D28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D9D2C: jr          $ra
    // 0x800D9D30: nop

    return;
    // 0x800D9D30: nop

    // 0x800D9D34: nop

    // 0x800D9D38: nop

    // 0x800D9D3C: nop

;}
RECOMP_FUNC void alSynSetPitch_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D9D40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D9D44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D9D48: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800D9D4C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800D9D50: lw          $t6, 0x8($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X8);
    // 0x800D9D54: beql        $t6, $zero, L_800D9DB8
    if (ctx->r14 == 0) {
        // 0x800D9D58: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D9DB8;
    }
    goto skip_0;
    // 0x800D9D58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800D9D5C: jal         0x800D9020
    // 0x800D9D60: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    __allocParam_recomp(rdram, ctx);
        goto after_0;
    // 0x800D9D60: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800D9D64: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x800D9D68: beq         $v0, $zero, L_800D9DB4
    if (ctx->r2 == 0) {
        // 0x800D9D6C: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800D9DB4;
    }
    // 0x800D9D6C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800D9D70: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800D9D74: lw          $t9, 0x8($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X8);
    // 0x800D9D78: addiu       $t2, $zero, 0x7
    ctx->r10 = ADD32(0, 0X7);
    // 0x800D9D7C: lw          $t8, 0x1C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1C);
    // 0x800D9D80: lw          $t0, 0xD8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XD8);
    // 0x800D9D84: sh          $t2, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r10;
    // 0x800D9D88: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800D9D8C: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x800D9D90: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x800D9D94: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800D9D98: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800D9D9C: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
    // 0x800D9DA0: lw          $t3, 0x8($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X8);
    // 0x800D9DA4: lw          $a0, 0xC($t3)
    ctx->r4 = MEM_W(ctx->r11, 0XC);
    // 0x800D9DA8: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800D9DAC: jalr        $t9
    // 0x800D9DB0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800D9DB0: nop

    after_1:
L_800D9DB4:
    // 0x800D9DB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D9DB8:
    // 0x800D9DB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D9DBC: jr          $ra
    // 0x800D9DC0: nop

    return;
    // 0x800D9DC0: nop

    // 0x800D9DC4: nop

    // 0x800D9DC8: nop

    // 0x800D9DCC: nop

;}
RECOMP_FUNC void _bcopy_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D9E70: beq         $a2, $zero, L_800D9EDC
    if (ctx->r6 == 0) {
        // 0x800D9E74: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_800D9EDC;
    }
    // 0x800D9E74: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800D9E78: beq         $a0, $a1, L_800D9EDC
    if (ctx->r4 == ctx->r5) {
        // 0x800D9E7C: slt         $at, $a1, $a0
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_800D9EDC;
    }
    // 0x800D9E7C: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800D9E80: bnel        $at, $zero, L_800D9EA4
    if (ctx->r1 != 0) {
        // 0x800D9E84: slti        $at, $a2, 0x10
        ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
            goto L_800D9EA4;
    }
    goto skip_0;
    // 0x800D9E84: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    skip_0:
    // 0x800D9E88: add         $v0, $a0, $a2
    ctx->r2 = ADD32(ctx->r4, ctx->r6);
    // 0x800D9E8C: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800D9E90: beql        $at, $zero, L_800D9EA4
    if (ctx->r1 == 0) {
        // 0x800D9E94: slti        $at, $a2, 0x10
        ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
            goto L_800D9EA4;
    }
    goto skip_1;
    // 0x800D9E94: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    skip_1:
    // 0x800D9E98: b           L_800DA008
    // 0x800D9E9C: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
        goto L_800DA008;
    // 0x800D9E9C: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    // 0x800D9EA0: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
L_800D9EA4:
    // 0x800D9EA4: bne         $at, $zero, L_800D9EBC
    if (ctx->r1 != 0) {
        // 0x800D9EA8: nop
    
            goto L_800D9EBC;
    }
    // 0x800D9EA8: nop

    // 0x800D9EAC: andi        $v0, $a0, 0x3
    ctx->r2 = ctx->r4 & 0X3;
    // 0x800D9EB0: andi        $v1, $a1, 0x3
    ctx->r3 = ctx->r5 & 0X3;
    // 0x800D9EB4: beq         $v0, $v1, L_800D9EE4
    if (ctx->r2 == ctx->r3) {
        // 0x800D9EB8: nop
    
            goto L_800D9EE4;
    }
    // 0x800D9EB8: nop

L_800D9EBC:
    // 0x800D9EBC: beq         $a2, $zero, L_800D9EDC
    if (ctx->r6 == 0) {
        // 0x800D9EC0: nop
    
            goto L_800D9EDC;
    }
    // 0x800D9EC0: nop

    // 0x800D9EC4: addu        $v1, $a0, $a2
    ctx->r3 = ADD32(ctx->r4, ctx->r6);
L_800D9EC8:
    // 0x800D9EC8: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x800D9ECC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800D9ED0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800D9ED4: bne         $a0, $v1, L_800D9EC8
    if (ctx->r4 != ctx->r3) {
        // 0x800D9ED8: sb          $v0, -0x1($a1)
        MEM_B(-0X1, ctx->r5) = ctx->r2;
            goto L_800D9EC8;
    }
    // 0x800D9ED8: sb          $v0, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r2;
L_800D9EDC:
    // 0x800D9EDC: jr          $ra
    // 0x800D9EE0: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    return;
    // 0x800D9EE0: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_800D9EE4:
    // 0x800D9EE4: beq         $v0, $zero, L_800D9F48
    if (ctx->r2 == 0) {
        // 0x800D9EE8: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800D9F48;
    }
    // 0x800D9EE8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800D9EEC: beq         $v0, $at, L_800D9F2C
    if (ctx->r2 == ctx->r1) {
        // 0x800D9EF0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800D9F2C;
    }
    // 0x800D9EF0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800D9EF4: beql        $v0, $at, L_800D9F18
    if (ctx->r2 == ctx->r1) {
        // 0x800D9EF8: lh          $v0, 0x0($a0)
        ctx->r2 = MEM_H(ctx->r4, 0X0);
            goto L_800D9F18;
    }
    goto skip_2;
    // 0x800D9EF8: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    skip_2:
    // 0x800D9EFC: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x800D9F00: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800D9F04: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800D9F08: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x800D9F0C: b           L_800D9F48
    // 0x800D9F10: sb          $v0, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r2;
        goto L_800D9F48;
    // 0x800D9F10: sb          $v0, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r2;
    // 0x800D9F14: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
L_800D9F18:
    // 0x800D9F18: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x800D9F1C: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x800D9F20: addiu       $a2, $a2, -0x2
    ctx->r6 = ADD32(ctx->r6, -0X2);
    // 0x800D9F24: b           L_800D9F48
    // 0x800D9F28: sh          $v0, -0x2($a1)
    MEM_H(-0X2, ctx->r5) = ctx->r2;
        goto L_800D9F48;
    // 0x800D9F28: sh          $v0, -0x2($a1)
    MEM_H(-0X2, ctx->r5) = ctx->r2;
L_800D9F2C:
    // 0x800D9F2C: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x800D9F30: lh          $v1, 0x1($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X1);
    // 0x800D9F34: addiu       $a0, $a0, 0x3
    ctx->r4 = ADD32(ctx->r4, 0X3);
    // 0x800D9F38: addiu       $a1, $a1, 0x3
    ctx->r5 = ADD32(ctx->r5, 0X3);
    // 0x800D9F3C: addiu       $a2, $a2, -0x3
    ctx->r6 = ADD32(ctx->r6, -0X3);
    // 0x800D9F40: sb          $v0, -0x3($a1)
    MEM_B(-0X3, ctx->r5) = ctx->r2;
    // 0x800D9F44: sh          $v1, -0x2($a1)
    MEM_H(-0X2, ctx->r5) = ctx->r3;
L_800D9F48:
    // 0x800D9F48: slti        $at, $a2, 0x20
    ctx->r1 = SIGNED(ctx->r6) < 0X20 ? 1 : 0;
    // 0x800D9F4C: bnel        $at, $zero, L_800D9FA8
    if (ctx->r1 != 0) {
        // 0x800D9F50: slti        $at, $a2, 0x10
        ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
            goto L_800D9FA8;
    }
    goto skip_3;
    // 0x800D9F50: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    skip_3:
    // 0x800D9F54: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800D9F58: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
    // 0x800D9F5C: lw          $t0, 0x8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X8);
    // 0x800D9F60: lw          $t1, 0xC($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XC);
    // 0x800D9F64: lw          $t2, 0x10($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X10);
    // 0x800D9F68: lw          $t3, 0x14($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14);
    // 0x800D9F6C: lw          $t4, 0x18($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X18);
    // 0x800D9F70: lw          $t5, 0x1C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X1C);
    // 0x800D9F74: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x800D9F78: addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    // 0x800D9F7C: addiu       $a2, $a2, -0x20
    ctx->r6 = ADD32(ctx->r6, -0X20);
    // 0x800D9F80: sw          $v0, -0x20($a1)
    MEM_W(-0X20, ctx->r5) = ctx->r2;
    // 0x800D9F84: sw          $v1, -0x1C($a1)
    MEM_W(-0X1C, ctx->r5) = ctx->r3;
    // 0x800D9F88: sw          $t0, -0x18($a1)
    MEM_W(-0X18, ctx->r5) = ctx->r8;
    // 0x800D9F8C: sw          $t1, -0x14($a1)
    MEM_W(-0X14, ctx->r5) = ctx->r9;
    // 0x800D9F90: sw          $t2, -0x10($a1)
    MEM_W(-0X10, ctx->r5) = ctx->r10;
    // 0x800D9F94: sw          $t3, -0xC($a1)
    MEM_W(-0XC, ctx->r5) = ctx->r11;
    // 0x800D9F98: sw          $t4, -0x8($a1)
    MEM_W(-0X8, ctx->r5) = ctx->r12;
    // 0x800D9F9C: b           L_800D9F48
    // 0x800D9FA0: sw          $t5, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r13;
        goto L_800D9F48;
    // 0x800D9FA0: sw          $t5, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r13;
L_800D9FA4:
    // 0x800D9FA4: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
L_800D9FA8:
    // 0x800D9FA8: bnel        $at, $zero, L_800D9FE4
    if (ctx->r1 != 0) {
        // 0x800D9FAC: slti        $at, $a2, 0x4
        ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
            goto L_800D9FE4;
    }
    goto skip_4;
    // 0x800D9FAC: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
    skip_4:
    // 0x800D9FB0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800D9FB4: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
    // 0x800D9FB8: lw          $t0, 0x8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X8);
    // 0x800D9FBC: lw          $t1, 0xC($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XC);
    // 0x800D9FC0: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x800D9FC4: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x800D9FC8: addiu       $a2, $a2, -0x10
    ctx->r6 = ADD32(ctx->r6, -0X10);
    // 0x800D9FCC: sw          $v0, -0x10($a1)
    MEM_W(-0X10, ctx->r5) = ctx->r2;
    // 0x800D9FD0: sw          $v1, -0xC($a1)
    MEM_W(-0XC, ctx->r5) = ctx->r3;
    // 0x800D9FD4: sw          $t0, -0x8($a1)
    MEM_W(-0X8, ctx->r5) = ctx->r8;
    // 0x800D9FD8: b           L_800D9FA4
    // 0x800D9FDC: sw          $t1, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r9;
        goto L_800D9FA4;
    // 0x800D9FDC: sw          $t1, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r9;
L_800D9FE0:
    // 0x800D9FE0: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
L_800D9FE4:
    // 0x800D9FE4: bne         $at, $zero, L_800D9EBC
    if (ctx->r1 != 0) {
        // 0x800D9FE8: nop
    
            goto L_800D9EBC;
    }
    // 0x800D9FE8: nop

    // 0x800D9FEC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800D9FF0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800D9FF4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800D9FF8: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
    // 0x800D9FFC: b           L_800D9FE0
    // 0x800DA000: sw          $v0, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r2;
        goto L_800D9FE0;
    // 0x800DA000: sw          $v0, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r2;
    // 0x800DA004: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
L_800DA008:
    // 0x800DA008: add         $a0, $a0, $a2
    ctx->r4 = ADD32(ctx->r4, ctx->r6);
    // 0x800DA00C: bne         $at, $zero, L_800DA024
    if (ctx->r1 != 0) {
        // 0x800DA010: add         $a1, $a1, $a2
        ctx->r5 = ADD32(ctx->r5, ctx->r6);
            goto L_800DA024;
    }
    // 0x800DA010: add         $a1, $a1, $a2
    ctx->r5 = ADD32(ctx->r5, ctx->r6);
    // 0x800DA014: andi        $v0, $a0, 0x3
    ctx->r2 = ctx->r4 & 0X3;
    // 0x800DA018: andi        $v1, $a1, 0x3
    ctx->r3 = ctx->r5 & 0X3;
    // 0x800DA01C: beq         $v0, $v1, L_800DA054
    if (ctx->r2 == ctx->r3) {
        // 0x800DA020: nop
    
            goto L_800DA054;
    }
    // 0x800DA020: nop

L_800DA024:
    // 0x800DA024: beq         $a2, $zero, L_800D9EDC
    if (ctx->r6 == 0) {
        // 0x800DA028: nop
    
            goto L_800D9EDC;
    }
    // 0x800DA028: nop

    // 0x800DA02C: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x800DA030: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x800DA034: subu        $v1, $a0, $a2
    ctx->r3 = SUB32(ctx->r4, ctx->r6);
L_800DA038:
    // 0x800DA038: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x800DA03C: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x800DA040: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x800DA044: bne         $a0, $v1, L_800DA038
    if (ctx->r4 != ctx->r3) {
        // 0x800DA048: sb          $v0, 0x1($a1)
        MEM_B(0X1, ctx->r5) = ctx->r2;
            goto L_800DA038;
    }
    // 0x800DA048: sb          $v0, 0x1($a1)
    MEM_B(0X1, ctx->r5) = ctx->r2;
    // 0x800DA04C: jr          $ra
    // 0x800DA050: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    return;
    // 0x800DA050: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_800DA054:
    // 0x800DA054: beq         $v0, $zero, L_800DA0B8
    if (ctx->r2 == 0) {
        // 0x800DA058: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800DA0B8;
    }
    // 0x800DA058: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800DA05C: beq         $v0, $at, L_800DA09C
    if (ctx->r2 == ctx->r1) {
        // 0x800DA060: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800DA09C;
    }
    // 0x800DA060: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800DA064: beql        $v0, $at, L_800DA088
    if (ctx->r2 == ctx->r1) {
        // 0x800DA068: lh          $v0, -0x2($a0)
        ctx->r2 = MEM_H(ctx->r4, -0X2);
            goto L_800DA088;
    }
    goto skip_5;
    // 0x800DA068: lh          $v0, -0x2($a0)
    ctx->r2 = MEM_H(ctx->r4, -0X2);
    skip_5:
    // 0x800DA06C: lb          $v0, -0x1($a0)
    ctx->r2 = MEM_B(ctx->r4, -0X1);
    // 0x800DA070: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x800DA074: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x800DA078: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x800DA07C: b           L_800DA0B8
    // 0x800DA080: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
        goto L_800DA0B8;
    // 0x800DA080: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    // 0x800DA084: lh          $v0, -0x2($a0)
    ctx->r2 = MEM_H(ctx->r4, -0X2);
L_800DA088:
    // 0x800DA088: addiu       $a0, $a0, -0x2
    ctx->r4 = ADD32(ctx->r4, -0X2);
    // 0x800DA08C: addiu       $a1, $a1, -0x2
    ctx->r5 = ADD32(ctx->r5, -0X2);
    // 0x800DA090: addiu       $a2, $a2, -0x2
    ctx->r6 = ADD32(ctx->r6, -0X2);
    // 0x800DA094: b           L_800DA0B8
    // 0x800DA098: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
        goto L_800DA0B8;
    // 0x800DA098: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
L_800DA09C:
    // 0x800DA09C: lb          $v0, -0x1($a0)
    ctx->r2 = MEM_B(ctx->r4, -0X1);
    // 0x800DA0A0: lh          $v1, -0x3($a0)
    ctx->r3 = MEM_H(ctx->r4, -0X3);
    // 0x800DA0A4: addiu       $a0, $a0, -0x3
    ctx->r4 = ADD32(ctx->r4, -0X3);
    // 0x800DA0A8: addiu       $a1, $a1, -0x3
    ctx->r5 = ADD32(ctx->r5, -0X3);
    // 0x800DA0AC: addiu       $a2, $a2, -0x3
    ctx->r6 = ADD32(ctx->r6, -0X3);
    // 0x800DA0B0: sb          $v0, 0x2($a1)
    MEM_B(0X2, ctx->r5) = ctx->r2;
    // 0x800DA0B4: sh          $v1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r3;
L_800DA0B8:
    // 0x800DA0B8: slti        $at, $a2, 0x20
    ctx->r1 = SIGNED(ctx->r6) < 0X20 ? 1 : 0;
    // 0x800DA0BC: bnel        $at, $zero, L_800DA118
    if (ctx->r1 != 0) {
        // 0x800DA0C0: slti        $at, $a2, 0x10
        ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
            goto L_800DA118;
    }
    goto skip_6;
    // 0x800DA0C0: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    skip_6:
    // 0x800DA0C4: lw          $v0, -0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, -0X4);
    // 0x800DA0C8: lw          $v1, -0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, -0X8);
    // 0x800DA0CC: lw          $t0, -0xC($a0)
    ctx->r8 = MEM_W(ctx->r4, -0XC);
    // 0x800DA0D0: lw          $t1, -0x10($a0)
    ctx->r9 = MEM_W(ctx->r4, -0X10);
    // 0x800DA0D4: lw          $t2, -0x14($a0)
    ctx->r10 = MEM_W(ctx->r4, -0X14);
    // 0x800DA0D8: lw          $t3, -0x18($a0)
    ctx->r11 = MEM_W(ctx->r4, -0X18);
    // 0x800DA0DC: lw          $t4, -0x1C($a0)
    ctx->r12 = MEM_W(ctx->r4, -0X1C);
    // 0x800DA0E0: lw          $t5, -0x20($a0)
    ctx->r13 = MEM_W(ctx->r4, -0X20);
    // 0x800DA0E4: addiu       $a0, $a0, -0x20
    ctx->r4 = ADD32(ctx->r4, -0X20);
    // 0x800DA0E8: addiu       $a1, $a1, -0x20
    ctx->r5 = ADD32(ctx->r5, -0X20);
    // 0x800DA0EC: addiu       $a2, $a2, -0x20
    ctx->r6 = ADD32(ctx->r6, -0X20);
    // 0x800DA0F0: sw          $v0, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->r2;
    // 0x800DA0F4: sw          $v1, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r3;
    // 0x800DA0F8: sw          $t0, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r8;
    // 0x800DA0FC: sw          $t1, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r9;
    // 0x800DA100: sw          $t2, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r10;
    // 0x800DA104: sw          $t3, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r11;
    // 0x800DA108: sw          $t4, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r12;
    // 0x800DA10C: b           L_800DA0B8
    // 0x800DA110: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
        goto L_800DA0B8;
    // 0x800DA110: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
L_800DA114:
    // 0x800DA114: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
L_800DA118:
    // 0x800DA118: bnel        $at, $zero, L_800DA154
    if (ctx->r1 != 0) {
        // 0x800DA11C: slti        $at, $a2, 0x4
        ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
            goto L_800DA154;
    }
    goto skip_7;
    // 0x800DA11C: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
    skip_7:
    // 0x800DA120: lw          $v0, -0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, -0X4);
    // 0x800DA124: lw          $v1, -0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, -0X8);
    // 0x800DA128: lw          $t0, -0xC($a0)
    ctx->r8 = MEM_W(ctx->r4, -0XC);
    // 0x800DA12C: lw          $t1, -0x10($a0)
    ctx->r9 = MEM_W(ctx->r4, -0X10);
    // 0x800DA130: addiu       $a0, $a0, -0x10
    ctx->r4 = ADD32(ctx->r4, -0X10);
    // 0x800DA134: addiu       $a1, $a1, -0x10
    ctx->r5 = ADD32(ctx->r5, -0X10);
    // 0x800DA138: addiu       $a2, $a2, -0x10
    ctx->r6 = ADD32(ctx->r6, -0X10);
    // 0x800DA13C: sw          $v0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r2;
    // 0x800DA140: sw          $v1, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r3;
    // 0x800DA144: sw          $t0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r8;
    // 0x800DA148: b           L_800DA114
    // 0x800DA14C: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
        goto L_800DA114;
    // 0x800DA14C: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
L_800DA150:
    // 0x800DA150: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
L_800DA154:
    // 0x800DA154: bne         $at, $zero, L_800DA024
    if (ctx->r1 != 0) {
        // 0x800DA158: nop
    
            goto L_800DA024;
    }
    // 0x800DA158: nop

    // 0x800DA15C: lw          $v0, -0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, -0X4);
    // 0x800DA160: addiu       $a0, $a0, -0x4
    ctx->r4 = ADD32(ctx->r4, -0X4);
    // 0x800DA164: addiu       $a1, $a1, -0x4
    ctx->r5 = ADD32(ctx->r5, -0X4);
    // 0x800DA168: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
    // 0x800DA16C: b           L_800DA150
    // 0x800DA170: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
        goto L_800DA150;
    // 0x800DA170: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x800DA174: nop

    // 0x800DA178: nop

    // 0x800DA17C: nop

;}
RECOMP_FUNC void func_800DA800(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DA800: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800DA804: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x800DA808: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DA80C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800DA810: addiu       $t6, $t6, -0x5960
    ctx->r14 = ADD32(ctx->r14, -0X5960);
    // 0x800DA814: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x800DA818: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x800DA81C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800DA820: jal         0x800D9E70
    // 0x800DA824: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    _bcopy_recomp(rdram, ctx);
        goto after_0;
    // 0x800DA824: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_0:
    // 0x800DA828: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800DA82C: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x800DA830: beq         $t8, $zero, L_800DA848
    if (ctx->r24 == 0) {
        // 0x800DA834: nop
    
            goto L_800DA848;
    }
    // 0x800DA834: nop

    // 0x800DA838: jal         0x800D70A0
    // 0x800DA83C: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_1;
    // 0x800DA83C: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_1:
    // 0x800DA840: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800DA844: sw          $v0, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->r2;
L_800DA848:
    // 0x800DA848: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800DA84C: lw          $t1, 0x18($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X18);
    // 0x800DA850: beq         $t1, $zero, L_800DA868
    if (ctx->r9 == 0) {
        // 0x800DA854: nop
    
            goto L_800DA868;
    }
    // 0x800DA854: nop

    // 0x800DA858: jal         0x800D70A0
    // 0x800DA85C: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_2;
    // 0x800DA85C: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    after_2:
    // 0x800DA860: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x800DA864: sw          $v0, 0x18($t2)
    MEM_W(0X18, ctx->r10) = ctx->r2;
L_800DA868:
    // 0x800DA868: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800DA86C: lw          $t4, 0x20($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X20);
    // 0x800DA870: beq         $t4, $zero, L_800DA888
    if (ctx->r12 == 0) {
        // 0x800DA874: nop
    
            goto L_800DA888;
    }
    // 0x800DA874: nop

    // 0x800DA878: jal         0x800D70A0
    // 0x800DA87C: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_3;
    // 0x800DA87C: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    after_3:
    // 0x800DA880: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800DA884: sw          $v0, 0x20($t5)
    MEM_W(0X20, ctx->r13) = ctx->r2;
L_800DA888:
    // 0x800DA888: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800DA88C: lw          $t7, 0x28($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X28);
    // 0x800DA890: beq         $t7, $zero, L_800DA8A8
    if (ctx->r15 == 0) {
        // 0x800DA894: nop
    
            goto L_800DA8A8;
    }
    // 0x800DA894: nop

    // 0x800DA898: jal         0x800D70A0
    // 0x800DA89C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_4;
    // 0x800DA89C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_4:
    // 0x800DA8A0: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800DA8A4: sw          $v0, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r2;
L_800DA8A8:
    // 0x800DA8A8: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800DA8AC: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x800DA8B0: beq         $t0, $zero, L_800DA8C8
    if (ctx->r8 == 0) {
        // 0x800DA8B4: nop
    
            goto L_800DA8C8;
    }
    // 0x800DA8B4: nop

    // 0x800DA8B8: jal         0x800D70A0
    // 0x800DA8BC: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_5;
    // 0x800DA8BC: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_5:
    // 0x800DA8C0: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800DA8C4: sw          $v0, 0x2C($t1)
    MEM_W(0X2C, ctx->r9) = ctx->r2;
L_800DA8C8:
    // 0x800DA8C8: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x800DA8CC: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x800DA8D0: beq         $t3, $zero, L_800DA8E8
    if (ctx->r11 == 0) {
        // 0x800DA8D4: nop
    
            goto L_800DA8E8;
    }
    // 0x800DA8D4: nop

    // 0x800DA8D8: jal         0x800D70A0
    // 0x800DA8DC: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_6;
    // 0x800DA8DC: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    after_6:
    // 0x800DA8E0: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800DA8E4: sw          $v0, 0x30($t4)
    MEM_W(0X30, ctx->r12) = ctx->r2;
L_800DA8E8:
    // 0x800DA8E8: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800DA8EC: lw          $t6, 0x38($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X38);
    // 0x800DA8F0: beq         $t6, $zero, L_800DA908
    if (ctx->r14 == 0) {
        // 0x800DA8F4: nop
    
            goto L_800DA908;
    }
    // 0x800DA8F4: nop

    // 0x800DA8F8: jal         0x800D70A0
    // 0x800DA8FC: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_7;
    // 0x800DA8FC: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_7:
    // 0x800DA900: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800DA904: sw          $v0, 0x38($t7)
    MEM_W(0X38, ctx->r15) = ctx->r2;
L_800DA908:
    // 0x800DA908: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DA90C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x800DA910: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800DA914: jr          $ra
    // 0x800DA918: nop

    return;
    // 0x800DA918: nop

;}
RECOMP_FUNC void guNormalize_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DB7A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DB7A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DB7A8: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800DB7AC: lwc1        $f14, 0x0($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800DB7B0: lwc1        $f0, 0x0($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800DB7B4: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800DB7B8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800DB7BC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800DB7C0: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800DB7C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800DB7C8: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800DB7CC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800DB7D0: jal         0x800D68E0
    // 0x800DB7D4: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x800DB7D4: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    after_0:
    // 0x800DB7D8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800DB7DC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800DB7E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800DB7E4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800DB7E8: div.s       $f2, $f16, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800DB7EC: lwc1        $f18, 0x0($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800DB7F0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800DB7F4: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x800DB7F8: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x800DB7FC: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800DB800: mul.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800DB804: swc1        $f10, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f10.u32l;
    // 0x800DB808: lwc1        $f8, 0x0($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800DB80C: mul.s       $f16, $f8, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800DB810: swc1        $f16, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f16.u32l;
    // 0x800DB814: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DB818: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DB81C: jr          $ra
    // 0x800DB820: nop

    return;
    // 0x800DB820: nop

    // 0x800DB824: nop

    // 0x800DB828: nop

    // 0x800DB82C: nop

;}
RECOMP_FUNC void func_800DC460(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DC460: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800DC464: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800DC468: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x800DC46C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x800DC470: ld          $t7, 0x8($sp)
    ctx->r15 = LD(ctx->r29, 0X8);
    // 0x800DC474: ld          $t6, 0x0($sp)
    ctx->r14 = LD(ctx->r29, 0X0);
    // 0x800DC478: ddivu       $zero, $t6, $t7
    DDIVU(U64(ctx->r14), U64(ctx->r15), &lo, &hi);
    // 0x800DC47C: bne         $t7, $zero, L_800DC488
    if (ctx->r15 != 0) {
        // 0x800DC480: nop
    
            goto L_800DC488;
    }
    // 0x800DC480: nop

    // 0x800DC484: break       7
    do_break(2148385924);
L_800DC488:
    // 0x800DC488: mfhi        $v0
    ctx->r2 = hi;
    // 0x800DC48C: dsll32      $v1, $v0, 0
    ctx->r3 = ctx->r2 << (0 + 32);
    // 0x800DC490: dsra32      $v1, $v1, 0
    ctx->r3 = SIGNED(ctx->r3) >> (0 + 32);
    // 0x800DC494: jr          $ra
    // 0x800DC498: dsra32      $v0, $v0, 0
    ctx->r2 = SIGNED(ctx->r2) >> (0 + 32);
    return;
    // 0x800DC498: dsra32      $v0, $v0, 0
    ctx->r2 = SIGNED(ctx->r2) >> (0 + 32);
;}
RECOMP_FUNC void func_800DCA90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DCA90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DCA94: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x800DCA98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DCA9C: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x800DCAA0: slti        $at, $t6, 0x26
    ctx->r1 = SIGNED(ctx->r14) < 0X26 ? 1 : 0;
    // 0x800DCAA4: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x800DCAA8: sw          $zero, 0xC($s0)
    MEM_W(0XC, ctx->r16) = 0;
    // 0x800DCAAC: sw          $zero, 0x10($s0)
    MEM_W(0X10, ctx->r16) = 0;
    // 0x800DCAB0: sw          $zero, 0x14($s0)
    MEM_W(0X14, ctx->r16) = 0;
    // 0x800DCAB4: sw          $zero, 0x18($s0)
    MEM_W(0X18, ctx->r16) = 0;
    // 0x800DCAB8: sw          $zero, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = 0;
    // 0x800DCABC: sw          $zero, 0x20($s0)
    MEM_W(0X20, ctx->r16) = 0;
    // 0x800DCAC0: bne         $at, $zero, L_800DCAEC
    if (ctx->r1 != 0) {
        // 0x800DCAC4: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_800DCAEC;
    }
    // 0x800DCAC4: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x800DCAC8: addiu       $t7, $t6, -0x45
    ctx->r15 = ADD32(ctx->r14, -0X45);
    // 0x800DCACC: sltiu       $at, $t7, 0x34
    ctx->r1 = ctx->r15 < 0X34 ? 1 : 0;
    // 0x800DCAD0: beq         $at, $zero, L_800DD0D8
    if (ctx->r1 == 0) {
        // 0x800DCAD4: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_800DD0D8;
    }
    // 0x800DCAD4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800DCAD8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800DCADC: addu        $at, $at, $t7
    gpr jr_addend_800DCAE4 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800DCAE0: lw          $t7, -0x1E7C($at)
    ctx->r15 = ADD32(ctx->r1, -0X1E7C);
    // 0x800DCAE4: jr          $t7
    // 0x800DCAE8: nop

    switch (jr_addend_800DCAE4 >> 2) {
        case 0: goto L_800DCDF8; break;
        case 1: goto L_800DD0D8; break;
        case 2: goto L_800DCDF8; break;
        case 3: goto L_800DD0D8; break;
        case 4: goto L_800DD0D8; break;
        case 5: goto L_800DD0D8; break;
        case 6: goto L_800DD0D8; break;
        case 7: goto L_800DD0D8; break;
        case 8: goto L_800DD0D8; break;
        case 9: goto L_800DD0D8; break;
        case 10: goto L_800DD0D8; break;
        case 11: goto L_800DD0D8; break;
        case 12: goto L_800DD0D8; break;
        case 13: goto L_800DD0D8; break;
        case 14: goto L_800DD0D8; break;
        case 15: goto L_800DD0D8; break;
        case 16: goto L_800DD0D8; break;
        case 17: goto L_800DD0D8; break;
        case 18: goto L_800DD0D8; break;
        case 19: goto L_800DCCA8; break;
        case 20: goto L_800DD0D8; break;
        case 21: goto L_800DD0D8; break;
        case 22: goto L_800DD0D8; break;
        case 23: goto L_800DD0D8; break;
        case 24: goto L_800DD0D8; break;
        case 25: goto L_800DD0D8; break;
        case 26: goto L_800DD0D8; break;
        case 27: goto L_800DD0D8; break;
        case 28: goto L_800DD0D8; break;
        case 29: goto L_800DD0D8; break;
        case 30: goto L_800DCB00; break;
        case 31: goto L_800DCB38; break;
        case 32: goto L_800DCDF8; break;
        case 33: goto L_800DCDF8; break;
        case 34: goto L_800DCDF8; break;
        case 35: goto L_800DD0D8; break;
        case 36: goto L_800DCB38; break;
        case 37: goto L_800DD0D8; break;
        case 38: goto L_800DD0D8; break;
        case 39: goto L_800DD0D8; break;
        case 40: goto L_800DD0D8; break;
        case 41: goto L_800DCF5C; break;
        case 42: goto L_800DCCA8; break;
        case 43: goto L_800DD02C; break;
        case 44: goto L_800DD0D8; break;
        case 45: goto L_800DD0D8; break;
        case 46: goto L_800DD074; break;
        case 47: goto L_800DD0D8; break;
        case 48: goto L_800DCCA8; break;
        case 49: goto L_800DD0D8; break;
        case 50: goto L_800DD0D8; break;
        case 51: goto L_800DCCA8; break;
        default: switch_error(__func__, 0x800DCAE4, 0x800EE184);
    }
    // 0x800DCAE8: nop

L_800DCAEC:
    // 0x800DCAEC: addiu       $at, $zero, 0x25
    ctx->r1 = ADD32(0, 0X25);
    // 0x800DCAF0: beql        $v1, $at, L_800DD0BC
    if (ctx->r3 == ctx->r1) {
        // 0x800DCAF4: lw          $t8, 0xC($s0)
        ctx->r24 = MEM_W(ctx->r16, 0XC);
            goto L_800DD0BC;
    }
    goto skip_0;
    // 0x800DCAF4: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    skip_0:
    // 0x800DCAF8: b           L_800DD0DC
    // 0x800DCAFC: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
        goto L_800DD0DC;
    // 0x800DCAFC: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
L_800DCB00:
    // 0x800DCB00: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800DCB04: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800DCB08: addiu       $t9, $t8, 0x3
    ctx->r25 = ADD32(ctx->r24, 0X3);
    // 0x800DCB0C: and         $t6, $t9, $at
    ctx->r14 = ctx->r25 & ctx->r1;
    // 0x800DCB10: addiu       $t7, $t6, 0x4
    ctx->r15 = ADD32(ctx->r14, 0X4);
    // 0x800DCB14: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x800DCB18: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x800DCB1C: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x800DCB20: addu        $t7, $a3, $t6
    ctx->r15 = ADD32(ctx->r7, ctx->r14);
    // 0x800DCB24: sb          $t9, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r25;
    // 0x800DCB28: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x800DCB2C: addiu       $t6, $t8, 0x1
    ctx->r14 = ADD32(ctx->r24, 0X1);
    // 0x800DCB30: b           L_800DD0F0
    // 0x800DCB34: sw          $t6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r14;
        goto L_800DD0F0;
    // 0x800DCB34: sw          $t6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r14;
L_800DCB38:
    // 0x800DCB38: lbu         $v0, 0x34($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X34);
    // 0x800DCB3C: addiu       $at, $zero, 0x6C
    ctx->r1 = ADD32(0, 0X6C);
    // 0x800DCB40: bnel        $v0, $at, L_800DCB78
    if (ctx->r2 != ctx->r1) {
        // 0x800DCB44: addiu       $at, $zero, 0x4C
        ctx->r1 = ADD32(0, 0X4C);
            goto L_800DCB78;
    }
    goto skip_1;
    // 0x800DCB44: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
    skip_1:
    // 0x800DCB48: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800DCB4C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800DCB50: addiu       $t7, $t9, 0x3
    ctx->r15 = ADD32(ctx->r25, 0X3);
    // 0x800DCB54: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x800DCB58: addiu       $t6, $t8, 0x4
    ctx->r14 = ADD32(ctx->r24, 0X4);
    // 0x800DCB5C: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x800DCB60: lw          $t7, -0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X4);
    // 0x800DCB64: sra         $t8, $t7, 31
    ctx->r24 = S32(SIGNED(ctx->r15) >> 31);
    // 0x800DCB68: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800DCB6C: b           L_800DCBD4
    // 0x800DCB70: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
        goto L_800DCBD4;
    // 0x800DCB70: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
    // 0x800DCB74: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
L_800DCB78:
    // 0x800DCB78: bnel        $v0, $at, L_800DCBB0
    if (ctx->r2 != ctx->r1) {
        // 0x800DCB7C: lw          $t7, 0x0($a2)
        ctx->r15 = MEM_W(ctx->r6, 0X0);
            goto L_800DCBB0;
    }
    goto skip_2;
    // 0x800DCB7C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    skip_2:
    // 0x800DCB80: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800DCB84: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x800DCB88: addiu       $t7, $t6, 0x7
    ctx->r15 = ADD32(ctx->r14, 0X7);
    // 0x800DCB8C: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x800DCB90: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x800DCB94: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800DCB98: lw          $t8, -0x8($t9)
    ctx->r24 = MEM_W(ctx->r25, -0X8);
    // 0x800DCB9C: lw          $t9, -0x4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4);
    // 0x800DCBA0: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800DCBA4: b           L_800DCBD4
    // 0x800DCBA8: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
        goto L_800DCBD4;
    // 0x800DCBA8: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x800DCBAC: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
L_800DCBB0:
    // 0x800DCBB0: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800DCBB4: addiu       $t6, $t7, 0x3
    ctx->r14 = ADD32(ctx->r15, 0X3);
    // 0x800DCBB8: and         $t8, $t6, $at
    ctx->r24 = ctx->r14 & ctx->r1;
    // 0x800DCBBC: addiu       $t9, $t8, 0x4
    ctx->r25 = ADD32(ctx->r24, 0X4);
    // 0x800DCBC0: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800DCBC4: lw          $t6, -0x4($t9)
    ctx->r14 = MEM_W(ctx->r25, -0X4);
    // 0x800DCBC8: sra         $t8, $t6, 31
    ctx->r24 = S32(SIGNED(ctx->r14) >> 31);
    // 0x800DCBCC: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800DCBD0: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
L_800DCBD4:
    // 0x800DCBD4: lbu         $t7, 0x34($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X34);
    // 0x800DCBD8: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x800DCBDC: bnel        $t7, $at, L_800DCC00
    if (ctx->r15 != ctx->r1) {
        // 0x800DCBE0: lw          $t6, 0x0($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X0);
            goto L_800DCC00;
    }
    goto skip_3;
    // 0x800DCBE0: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    skip_3:
    // 0x800DCBE4: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x800DCBE8: sll         $t9, $t7, 16
    ctx->r25 = S32(ctx->r15 << 16);
    // 0x800DCBEC: sra         $t6, $t9, 16
    ctx->r14 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800DCBF0: sra         $t8, $t6, 31
    ctx->r24 = S32(SIGNED(ctx->r14) >> 31);
    // 0x800DCBF4: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800DCBF8: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
    // 0x800DCBFC: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
L_800DCC00:
    // 0x800DCC00: bgtzl       $t6, L_800DCC3C
    if (SIGNED(ctx->r14) > 0) {
        // 0x800DCC04: lw          $v0, 0x30($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X30);
            goto L_800DCC3C;
    }
    goto skip_4;
    // 0x800DCC04: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
    skip_4:
    // 0x800DCC08: bltzl       $t6, L_800DCC1C
    if (SIGNED(ctx->r14) < 0) {
        // 0x800DCC0C: lw          $t9, 0xC($s0)
        ctx->r25 = MEM_W(ctx->r16, 0XC);
            goto L_800DCC1C;
    }
    goto skip_5;
    // 0x800DCC0C: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    skip_5:
    // 0x800DCC10: b           L_800DCC3C
    // 0x800DCC14: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
        goto L_800DCC3C;
    // 0x800DCC14: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
    // 0x800DCC18: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
L_800DCC1C:
    // 0x800DCC1C: addiu       $t8, $zero, 0x2D
    ctx->r24 = ADD32(0, 0X2D);
    // 0x800DCC20: addu        $t6, $a3, $t9
    ctx->r14 = ADD32(ctx->r7, ctx->r25);
    // 0x800DCC24: sb          $t8, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r24;
    // 0x800DCC28: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x800DCC2C: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x800DCC30: b           L_800DCC8C
    // 0x800DCC34: sw          $t9, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r25;
        goto L_800DCC8C;
    // 0x800DCC34: sw          $t9, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r25;
    // 0x800DCC38: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
L_800DCC3C:
    // 0x800DCC3C: andi        $t8, $v0, 0x2
    ctx->r24 = ctx->r2 & 0X2;
    // 0x800DCC40: beq         $t8, $zero, L_800DCC68
    if (ctx->r24 == 0) {
        // 0x800DCC44: andi        $t6, $v0, 0x1
        ctx->r14 = ctx->r2 & 0X1;
            goto L_800DCC68;
    }
    // 0x800DCC44: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x800DCC48: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x800DCC4C: addiu       $t6, $zero, 0x2B
    ctx->r14 = ADD32(0, 0X2B);
    // 0x800DCC50: addu        $t9, $a3, $t7
    ctx->r25 = ADD32(ctx->r7, ctx->r15);
    // 0x800DCC54: sb          $t6, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r14;
    // 0x800DCC58: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x800DCC5C: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x800DCC60: b           L_800DCC8C
    // 0x800DCC64: sw          $t7, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r15;
        goto L_800DCC8C;
    // 0x800DCC64: sw          $t7, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r15;
L_800DCC68:
    // 0x800DCC68: beql        $t6, $zero, L_800DCC90
    if (ctx->r14 == 0) {
        // 0x800DCC6C: lw          $t9, 0xC($s0)
        ctx->r25 = MEM_W(ctx->r16, 0XC);
            goto L_800DCC90;
    }
    goto skip_6;
    // 0x800DCC6C: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    skip_6:
    // 0x800DCC70: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x800DCC74: addiu       $t9, $zero, 0x20
    ctx->r25 = ADD32(0, 0X20);
    // 0x800DCC78: addu        $t7, $a3, $t8
    ctx->r15 = ADD32(ctx->r7, ctx->r24);
    // 0x800DCC7C: sb          $t9, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r25;
    // 0x800DCC80: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x800DCC84: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x800DCC88: sw          $t8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r24;
L_800DCC8C:
    // 0x800DCC8C: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
L_800DCC90:
    // 0x800DCC90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800DCC94: addu        $t7, $t9, $a3
    ctx->r15 = ADD32(ctx->r25, ctx->r7);
    // 0x800DCC98: jal         0x800E14D0
    // 0x800DCC9C: sw          $t7, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r15;
    _Litob_recomp(rdram, ctx);
        goto after_0;
    // 0x800DCC9C: sw          $t7, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r15;
    after_0:
    // 0x800DCCA0: b           L_800DD0F4
    // 0x800DCCA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800DD0F4;
    // 0x800DCCA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800DCCA8:
    // 0x800DCCA8: lbu         $v0, 0x34($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X34);
    // 0x800DCCAC: addiu       $at, $zero, 0x6C
    ctx->r1 = ADD32(0, 0X6C);
    // 0x800DCCB0: bnel        $v0, $at, L_800DCCE8
    if (ctx->r2 != ctx->r1) {
        // 0x800DCCB4: addiu       $at, $zero, 0x4C
        ctx->r1 = ADD32(0, 0X4C);
            goto L_800DCCE8;
    }
    goto skip_7;
    // 0x800DCCB4: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
    skip_7:
    // 0x800DCCB8: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800DCCBC: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800DCCC0: addiu       $t8, $t6, 0x3
    ctx->r24 = ADD32(ctx->r14, 0X3);
    // 0x800DCCC4: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x800DCCC8: addiu       $t7, $t9, 0x4
    ctx->r15 = ADD32(ctx->r25, 0X4);
    // 0x800DCCCC: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x800DCCD0: lw          $t8, -0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X4);
    // 0x800DCCD4: sra         $t6, $t8, 31
    ctx->r14 = S32(SIGNED(ctx->r24) >> 31);
    // 0x800DCCD8: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800DCCDC: b           L_800DCD44
    // 0x800DCCE0: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
        goto L_800DCD44;
    // 0x800DCCE0: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
    // 0x800DCCE4: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
L_800DCCE8:
    // 0x800DCCE8: bnel        $v0, $at, L_800DCD20
    if (ctx->r2 != ctx->r1) {
        // 0x800DCCEC: lw          $t6, 0x0($a2)
        ctx->r14 = MEM_W(ctx->r6, 0X0);
            goto L_800DCD20;
    }
    goto skip_8;
    // 0x800DCCEC: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    skip_8:
    // 0x800DCCF0: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800DCCF4: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x800DCCF8: addiu       $t8, $t9, 0x7
    ctx->r24 = ADD32(ctx->r25, 0X7);
    // 0x800DCCFC: and         $t6, $t8, $at
    ctx->r14 = ctx->r24 & ctx->r1;
    // 0x800DCD00: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800DCD04: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x800DCD08: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x800DCD0C: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x800DCD10: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x800DCD14: b           L_800DCD44
    // 0x800DCD18: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
        goto L_800DCD44;
    // 0x800DCD18: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800DCD1C: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
L_800DCD20:
    // 0x800DCD20: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800DCD24: addiu       $t7, $t6, 0x3
    ctx->r15 = ADD32(ctx->r14, 0X3);
    // 0x800DCD28: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x800DCD2C: addiu       $t9, $t8, 0x4
    ctx->r25 = ADD32(ctx->r24, 0X4);
    // 0x800DCD30: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800DCD34: lw          $t7, -0x4($t9)
    ctx->r15 = MEM_W(ctx->r25, -0X4);
    // 0x800DCD38: sra         $t8, $t7, 31
    ctx->r24 = S32(SIGNED(ctx->r15) >> 31);
    // 0x800DCD3C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800DCD40: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
L_800DCD44:
    // 0x800DCD44: lbu         $v0, 0x34($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X34);
    // 0x800DCD48: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x800DCD4C: bne         $v0, $at, L_800DCD6C
    if (ctx->r2 != ctx->r1) {
        // 0x800DCD50: nop
    
            goto L_800DCD6C;
    }
    // 0x800DCD50: nop

    // 0x800DCD54: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x800DCD58: addiu       $t6, $zero, 0x0
    ctx->r14 = ADD32(0, 0X0);
    // 0x800DCD5C: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800DCD60: andi        $t9, $t7, 0xFFFF
    ctx->r25 = ctx->r15 & 0XFFFF;
    // 0x800DCD64: b           L_800DCD84
    // 0x800DCD68: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
        goto L_800DCD84;
    // 0x800DCD68: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
L_800DCD6C:
    // 0x800DCD6C: bnel        $v0, $zero, L_800DCD88
    if (ctx->r2 != 0) {
        // 0x800DCD70: lw          $t7, 0x30($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X30);
            goto L_800DCD88;
    }
    goto skip_9;
    // 0x800DCD70: lw          $t7, 0x30($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X30);
    skip_9:
    // 0x800DCD74: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x800DCD78: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x800DCD7C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800DCD80: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
L_800DCD84:
    // 0x800DCD84: lw          $t7, 0x30($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X30);
L_800DCD88:
    // 0x800DCD88: andi        $t6, $t7, 0x8
    ctx->r14 = ctx->r15 & 0X8;
    // 0x800DCD8C: beql        $t6, $zero, L_800DCDE0
    if (ctx->r14 == 0) {
        // 0x800DCD90: lw          $t8, 0xC($s0)
        ctx->r24 = MEM_W(ctx->r16, 0XC);
            goto L_800DCDE0;
    }
    goto skip_10;
    // 0x800DCD90: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    skip_10:
    // 0x800DCD94: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    // 0x800DCD98: addiu       $t8, $zero, 0x30
    ctx->r24 = ADD32(0, 0X30);
    // 0x800DCD9C: addiu       $at, $zero, 0x78
    ctx->r1 = ADD32(0, 0X78);
    // 0x800DCDA0: addu        $t7, $a3, $t9
    ctx->r15 = ADD32(ctx->r7, ctx->r25);
    // 0x800DCDA4: sb          $t8, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r24;
    // 0x800DCDA8: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x800DCDAC: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x800DCDB0: beq         $v1, $at, L_800DCDC4
    if (ctx->r3 == ctx->r1) {
        // 0x800DCDB4: sw          $t9, 0xC($s0)
        MEM_W(0XC, ctx->r16) = ctx->r25;
            goto L_800DCDC4;
    }
    // 0x800DCDB4: sw          $t9, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r25;
    // 0x800DCDB8: addiu       $at, $zero, 0x58
    ctx->r1 = ADD32(0, 0X58);
    // 0x800DCDBC: bnel        $v1, $at, L_800DCDE0
    if (ctx->r3 != ctx->r1) {
        // 0x800DCDC0: lw          $t8, 0xC($s0)
        ctx->r24 = MEM_W(ctx->r16, 0XC);
            goto L_800DCDE0;
    }
    goto skip_11;
    // 0x800DCDC0: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    skip_11:
L_800DCDC4:
    // 0x800DCDC4: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x800DCDC8: addu        $t7, $a3, $t8
    ctx->r15 = ADD32(ctx->r7, ctx->r24);
    // 0x800DCDCC: sb          $a1, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r5;
    // 0x800DCDD0: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x800DCDD4: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x800DCDD8: sw          $t9, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r25;
    // 0x800DCDDC: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
L_800DCDE0:
    // 0x800DCDE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800DCDE4: addu        $t7, $t8, $a3
    ctx->r15 = ADD32(ctx->r24, ctx->r7);
    // 0x800DCDE8: jal         0x800E14D0
    // 0x800DCDEC: sw          $t7, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r15;
    _Litob_recomp(rdram, ctx);
        goto after_1;
    // 0x800DCDEC: sw          $t7, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r15;
    after_1:
    // 0x800DCDF0: b           L_800DD0F4
    // 0x800DCDF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800DD0F4;
    // 0x800DCDF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800DCDF8:
    // 0x800DCDF8: lbu         $t6, 0x34($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X34);
    // 0x800DCDFC: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
    // 0x800DCE00: bnel        $t6, $at, L_800DCE68
    if (ctx->r14 != ctx->r1) {
        // 0x800DCE04: lw          $v0, 0x0($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X0);
            goto L_800DCE68;
    }
    goto skip_12;
    // 0x800DCE04: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    skip_12:
    // 0x800DCE08: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x800DCE0C: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x800DCE10: beq         $t9, $zero, L_800DCE28
    if (ctx->r25 == 0) {
        // 0x800DCE14: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800DCE28;
    }
    // 0x800DCE14: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800DCE18: addiu       $t8, $v1, 0x7
    ctx->r24 = ADD32(ctx->r3, 0X7);
    // 0x800DCE1C: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x800DCE20: b           L_800DCE58
    // 0x800DCE24: addiu       $v0, $t8, -0x16
    ctx->r2 = ADD32(ctx->r24, -0X16);
        goto L_800DCE58;
    // 0x800DCE24: addiu       $v0, $t8, -0x16
    ctx->r2 = ADD32(ctx->r24, -0X16);
L_800DCE28:
    // 0x800DCE28: andi        $t7, $v1, 0x2
    ctx->r15 = ctx->r3 & 0X2;
    // 0x800DCE2C: beq         $t7, $zero, L_800DCE44
    if (ctx->r15 == 0) {
        // 0x800DCE30: addiu       $t9, $v0, 0x7
        ctx->r25 = ADD32(ctx->r2, 0X7);
            goto L_800DCE44;
    }
    // 0x800DCE30: addiu       $t9, $v0, 0x7
    ctx->r25 = ADD32(ctx->r2, 0X7);
    // 0x800DCE34: addiu       $t6, $v1, 0xA
    ctx->r14 = ADD32(ctx->r3, 0XA);
    // 0x800DCE38: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x800DCE3C: b           L_800DCE54
    // 0x800DCE40: addiu       $a0, $t6, -0x28
    ctx->r4 = ADD32(ctx->r14, -0X28);
        goto L_800DCE54;
    // 0x800DCE40: addiu       $a0, $t6, -0x28
    ctx->r4 = ADD32(ctx->r14, -0X28);
L_800DCE44:
    // 0x800DCE44: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x800DCE48: and         $t8, $t9, $at
    ctx->r24 = ctx->r25 & ctx->r1;
    // 0x800DCE4C: addiu       $a0, $t8, 0x8
    ctx->r4 = ADD32(ctx->r24, 0X8);
    // 0x800DCE50: sw          $a0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r4;
L_800DCE54:
    // 0x800DCE54: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_800DCE58:
    // 0x800DCE58: ldc1        $f4, -0x8($v0)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r2, -0X8);
    // 0x800DCE5C: b           L_800DCEBC
    // 0x800DCE60: sdc1        $f4, 0x0($s0)
    CHECK_FR(ctx, 4);
    SD(ctx->f4.u64, 0X0, ctx->r16);
        goto L_800DCEBC;
    // 0x800DCE60: sdc1        $f4, 0x0($s0)
    CHECK_FR(ctx, 4);
    SD(ctx->f4.u64, 0X0, ctx->r16);
    // 0x800DCE64: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
L_800DCE68:
    // 0x800DCE68: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x800DCE6C: beq         $t6, $zero, L_800DCE84
    if (ctx->r14 == 0) {
        // 0x800DCE70: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800DCE84;
    }
    // 0x800DCE70: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800DCE74: addiu       $t9, $v1, 0x7
    ctx->r25 = ADD32(ctx->r3, 0X7);
    // 0x800DCE78: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800DCE7C: b           L_800DCEB4
    // 0x800DCE80: addiu       $v0, $t9, -0x16
    ctx->r2 = ADD32(ctx->r25, -0X16);
        goto L_800DCEB4;
    // 0x800DCE80: addiu       $v0, $t9, -0x16
    ctx->r2 = ADD32(ctx->r25, -0X16);
L_800DCE84:
    // 0x800DCE84: andi        $t8, $v1, 0x2
    ctx->r24 = ctx->r3 & 0X2;
    // 0x800DCE88: beq         $t8, $zero, L_800DCEA0
    if (ctx->r24 == 0) {
        // 0x800DCE8C: addiu       $t6, $v0, 0x7
        ctx->r14 = ADD32(ctx->r2, 0X7);
            goto L_800DCEA0;
    }
    // 0x800DCE8C: addiu       $t6, $v0, 0x7
    ctx->r14 = ADD32(ctx->r2, 0X7);
    // 0x800DCE90: addiu       $t7, $v1, 0xA
    ctx->r15 = ADD32(ctx->r3, 0XA);
    // 0x800DCE94: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x800DCE98: b           L_800DCEB0
    // 0x800DCE9C: addiu       $a0, $t7, -0x28
    ctx->r4 = ADD32(ctx->r15, -0X28);
        goto L_800DCEB0;
    // 0x800DCE9C: addiu       $a0, $t7, -0x28
    ctx->r4 = ADD32(ctx->r15, -0X28);
L_800DCEA0:
    // 0x800DCEA0: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x800DCEA4: and         $t9, $t6, $at
    ctx->r25 = ctx->r14 & ctx->r1;
    // 0x800DCEA8: addiu       $a0, $t9, 0x8
    ctx->r4 = ADD32(ctx->r25, 0X8);
    // 0x800DCEAC: sw          $a0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r4;
L_800DCEB0:
    // 0x800DCEB0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_800DCEB4:
    // 0x800DCEB4: ldc1        $f6, -0x8($v0)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r2, -0X8);
    // 0x800DCEB8: sdc1        $f6, 0x0($s0)
    CHECK_FR(ctx, 6);
    SD(ctx->f6.u64, 0X0, ctx->r16);
L_800DCEBC:
    // 0x800DCEBC: lhu         $t7, 0x0($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X0);
    // 0x800DCEC0: andi        $t6, $t7, 0x8000
    ctx->r14 = ctx->r15 & 0X8000;
    // 0x800DCEC4: beql        $t6, $zero, L_800DCEF0
    if (ctx->r14 == 0) {
        // 0x800DCEC8: lw          $v0, 0x30($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X30);
            goto L_800DCEF0;
    }
    goto skip_13;
    // 0x800DCEC8: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
    skip_13:
    // 0x800DCECC: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x800DCED0: addiu       $t9, $zero, 0x2D
    ctx->r25 = ADD32(0, 0X2D);
    // 0x800DCED4: addu        $t7, $a3, $t8
    ctx->r15 = ADD32(ctx->r7, ctx->r24);
    // 0x800DCED8: sb          $t9, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r25;
    // 0x800DCEDC: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x800DCEE0: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x800DCEE4: b           L_800DCF40
    // 0x800DCEE8: sw          $t8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r24;
        goto L_800DCF40;
    // 0x800DCEE8: sw          $t8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r24;
    // 0x800DCEEC: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
L_800DCEF0:
    // 0x800DCEF0: andi        $t9, $v0, 0x2
    ctx->r25 = ctx->r2 & 0X2;
    // 0x800DCEF4: beq         $t9, $zero, L_800DCF1C
    if (ctx->r25 == 0) {
        // 0x800DCEF8: andi        $t7, $v0, 0x1
        ctx->r15 = ctx->r2 & 0X1;
            goto L_800DCF1C;
    }
    // 0x800DCEF8: andi        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 & 0X1;
    // 0x800DCEFC: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x800DCF00: addiu       $t7, $zero, 0x2B
    ctx->r15 = ADD32(0, 0X2B);
    // 0x800DCF04: addu        $t8, $a3, $t6
    ctx->r24 = ADD32(ctx->r7, ctx->r14);
    // 0x800DCF08: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
    // 0x800DCF0C: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    // 0x800DCF10: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x800DCF14: b           L_800DCF40
    // 0x800DCF18: sw          $t6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r14;
        goto L_800DCF40;
    // 0x800DCF18: sw          $t6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r14;
L_800DCF1C:
    // 0x800DCF1C: beql        $t7, $zero, L_800DCF44
    if (ctx->r15 == 0) {
        // 0x800DCF20: lw          $t8, 0xC($s0)
        ctx->r24 = MEM_W(ctx->r16, 0XC);
            goto L_800DCF44;
    }
    goto skip_14;
    // 0x800DCF20: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    skip_14:
    // 0x800DCF24: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    // 0x800DCF28: addiu       $t8, $zero, 0x20
    ctx->r24 = ADD32(0, 0X20);
    // 0x800DCF2C: addu        $t6, $a3, $t9
    ctx->r14 = ADD32(ctx->r7, ctx->r25);
    // 0x800DCF30: sb          $t8, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r24;
    // 0x800DCF34: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x800DCF38: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x800DCF3C: sw          $t9, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r25;
L_800DCF40:
    // 0x800DCF40: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
L_800DCF44:
    // 0x800DCF44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800DCF48: addu        $t6, $t8, $a3
    ctx->r14 = ADD32(ctx->r24, ctx->r7);
    // 0x800DCF4C: jal         0x800E1CE0
    // 0x800DCF50: sw          $t6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r14;
    _Ldtob_recomp(rdram, ctx);
        goto after_2;
    // 0x800DCF50: sw          $t6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r14;
    after_2:
    // 0x800DCF54: b           L_800DD0F4
    // 0x800DCF58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800DD0F4;
    // 0x800DCF58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800DCF5C:
    // 0x800DCF5C: lbu         $v0, 0x34($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X34);
    // 0x800DCF60: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x800DCF64: bnel        $v0, $at, L_800DCF98
    if (ctx->r2 != ctx->r1) {
        // 0x800DCF68: addiu       $at, $zero, 0x6C
        ctx->r1 = ADD32(0, 0X6C);
            goto L_800DCF98;
    }
    goto skip_15;
    // 0x800DCF68: addiu       $at, $zero, 0x6C
    ctx->r1 = ADD32(0, 0X6C);
    skip_15:
    // 0x800DCF6C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x800DCF70: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800DCF74: addiu       $t9, $t7, 0x3
    ctx->r25 = ADD32(ctx->r15, 0X3);
    // 0x800DCF78: and         $t8, $t9, $at
    ctx->r24 = ctx->r25 & ctx->r1;
    // 0x800DCF7C: addiu       $t6, $t8, 0x4
    ctx->r14 = ADD32(ctx->r24, 0X4);
    // 0x800DCF80: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x800DCF84: lw          $t9, -0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, -0X4);
    // 0x800DCF88: lw          $t7, 0x2C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X2C);
    // 0x800DCF8C: b           L_800DD0F0
    // 0x800DCF90: sh          $t7, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r15;
        goto L_800DD0F0;
    // 0x800DCF90: sh          $t7, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r15;
    // 0x800DCF94: addiu       $at, $zero, 0x6C
    ctx->r1 = ADD32(0, 0X6C);
L_800DCF98:
    // 0x800DCF98: bnel        $v0, $at, L_800DCFCC
    if (ctx->r2 != ctx->r1) {
        // 0x800DCF9C: addiu       $at, $zero, 0x4C
        ctx->r1 = ADD32(0, 0X4C);
            goto L_800DCFCC;
    }
    goto skip_16;
    // 0x800DCF9C: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
    skip_16:
    // 0x800DCFA0: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800DCFA4: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800DCFA8: addiu       $t6, $t8, 0x3
    ctx->r14 = ADD32(ctx->r24, 0X3);
    // 0x800DCFAC: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x800DCFB0: addiu       $t9, $t7, 0x4
    ctx->r25 = ADD32(ctx->r15, 0X4);
    // 0x800DCFB4: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800DCFB8: lw          $t6, -0x4($t9)
    ctx->r14 = MEM_W(ctx->r25, -0X4);
    // 0x800DCFBC: lw          $t8, 0x2C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X2C);
    // 0x800DCFC0: b           L_800DD0F0
    // 0x800DCFC4: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
        goto L_800DD0F0;
    // 0x800DCFC4: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x800DCFC8: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
L_800DCFCC:
    // 0x800DCFCC: bnel        $v0, $at, L_800DD008
    if (ctx->r2 != ctx->r1) {
        // 0x800DCFD0: lw          $t7, 0x0($a2)
        ctx->r15 = MEM_W(ctx->r6, 0X0);
            goto L_800DD008;
    }
    goto skip_17;
    // 0x800DCFD0: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    skip_17:
    // 0x800DCFD4: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x800DCFD8: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800DCFDC: addiu       $t9, $t7, 0x3
    ctx->r25 = ADD32(ctx->r15, 0X3);
    // 0x800DCFE0: and         $t8, $t9, $at
    ctx->r24 = ctx->r25 & ctx->r1;
    // 0x800DCFE4: addiu       $t6, $t8, 0x4
    ctx->r14 = ADD32(ctx->r24, 0X4);
    // 0x800DCFE8: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x800DCFEC: lw          $t6, -0x4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4);
    // 0x800DCFF0: lw          $t7, 0x2C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X2C);
    // 0x800DCFF4: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x800DCFF8: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x800DCFFC: b           L_800DD0F0
    // 0x800DD000: sw          $t7, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r15;
        goto L_800DD0F0;
    // 0x800DD000: sw          $t7, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r15;
    // 0x800DD004: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
L_800DD008:
    // 0x800DD008: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800DD00C: addiu       $t8, $t7, 0x3
    ctx->r24 = ADD32(ctx->r15, 0X3);
    // 0x800DD010: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x800DD014: addiu       $t6, $t9, 0x4
    ctx->r14 = ADD32(ctx->r25, 0X4);
    // 0x800DD018: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x800DD01C: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x800DD020: lw          $t7, 0x2C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X2C);
    // 0x800DD024: b           L_800DD0F0
    // 0x800DD028: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
        goto L_800DD0F0;
    // 0x800DD028: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
L_800DD02C:
    // 0x800DD02C: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800DD030: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800DD034: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800DD038: addiu       $t6, $t9, 0x3
    ctx->r14 = ADD32(ctx->r25, 0X3);
    // 0x800DD03C: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x800DD040: addiu       $t8, $t7, 0x4
    ctx->r24 = ADD32(ctx->r15, 0X4);
    // 0x800DD044: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x800DD048: lw          $t6, -0x4($t8)
    ctx->r14 = MEM_W(ctx->r24, -0X4);
    // 0x800DD04C: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x800DD050: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    // 0x800DD054: sra         $t8, $t6, 31
    ctx->r24 = S32(SIGNED(ctx->r14) >> 31);
    // 0x800DD058: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
    // 0x800DD05C: addu        $t6, $t7, $a3
    ctx->r14 = ADD32(ctx->r15, ctx->r7);
    // 0x800DD060: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800DD064: jal         0x800E14D0
    // 0x800DD068: sw          $t6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r14;
    _Litob_recomp(rdram, ctx);
        goto after_3;
    // 0x800DD068: sw          $t6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r14;
    after_3:
    // 0x800DD06C: b           L_800DD0F4
    // 0x800DD070: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800DD0F4;
    // 0x800DD070: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800DD074:
    // 0x800DD074: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800DD078: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800DD07C: addiu       $t9, $t8, 0x3
    ctx->r25 = ADD32(ctx->r24, 0X3);
    // 0x800DD080: and         $t7, $t9, $at
    ctx->r15 = ctx->r25 & ctx->r1;
    // 0x800DD084: addiu       $t6, $t7, 0x4
    ctx->r14 = ADD32(ctx->r15, 0X4);
    // 0x800DD088: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x800DD08C: lw          $a0, -0x4($t6)
    ctx->r4 = MEM_W(ctx->r14, -0X4);
    // 0x800DD090: jal         0x800DD77C
    // 0x800DD094: sw          $a0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r4;
    strlen_recomp(rdram, ctx);
        goto after_4;
    // 0x800DD094: sw          $a0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r4;
    after_4:
    // 0x800DD098: lw          $v1, 0x24($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X24);
    // 0x800DD09C: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // 0x800DD0A0: bltz        $v1, L_800DD0F0
    if (SIGNED(ctx->r3) < 0) {
        // 0x800DD0A4: slt         $at, $v1, $v0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_800DD0F0;
    }
    // 0x800DD0A4: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800DD0A8: beql        $at, $zero, L_800DD0F4
    if (ctx->r1 == 0) {
        // 0x800DD0AC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800DD0F4;
    }
    goto skip_18;
    // 0x800DD0AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_18:
    // 0x800DD0B0: b           L_800DD0F0
    // 0x800DD0B4: sw          $v1, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r3;
        goto L_800DD0F0;
    // 0x800DD0B4: sw          $v1, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r3;
    // 0x800DD0B8: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
L_800DD0BC:
    // 0x800DD0BC: addiu       $t6, $zero, 0x25
    ctx->r14 = ADD32(0, 0X25);
    // 0x800DD0C0: addu        $t9, $a3, $t8
    ctx->r25 = ADD32(ctx->r7, ctx->r24);
    // 0x800DD0C4: sb          $t6, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r14;
    // 0x800DD0C8: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x800DD0CC: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800DD0D0: b           L_800DD0F0
    // 0x800DD0D4: sw          $t8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r24;
        goto L_800DD0F0;
    // 0x800DD0D4: sw          $t8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r24;
L_800DD0D8:
    // 0x800DD0D8: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
L_800DD0DC:
    // 0x800DD0DC: addu        $t9, $a3, $t6
    ctx->r25 = ADD32(ctx->r7, ctx->r14);
    // 0x800DD0E0: sb          $a1, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r5;
    // 0x800DD0E4: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x800DD0E8: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800DD0EC: sw          $t8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r24;
L_800DD0F0:
    // 0x800DD0F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800DD0F4:
    // 0x800DD0F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DD0F8: jr          $ra
    // 0x800DD0FC: nop

    return;
    // 0x800DD0FC: nop

;}
RECOMP_FUNC void _Printf_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DD100: addiu       $sp, $sp, -0xD8
    ctx->r29 = ADD32(ctx->r29, -0XD8);
    // 0x800DD104: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800DD108: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800DD10C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800DD110: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800DD114: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800DD118: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800DD11C: sw          $a3, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r7;
    // 0x800DD120: lui         $s5, 0x800F
    ctx->r21 = S32(0X800F << 16);
    // 0x800DD124: lui         $s6, 0x800F
    ctx->r22 = S32(0X800F << 16);
    // 0x800DD128: lui         $s7, 0x800F
    ctx->r23 = S32(0X800F << 16);
    // 0x800DD12C: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x800DD130: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x800DD134: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x800DD138: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800DD13C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800DD140: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800DD144: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800DD148: sw          $a2, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r6;
    // 0x800DD14C: sw          $zero, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = 0;
    // 0x800DD150: addiu       $s7, $s7, -0x30C0
    ctx->r23 = ADD32(ctx->r23, -0X30C0);
    // 0x800DD154: addiu       $s6, $s6, -0x1E9C
    ctx->r22 = ADD32(ctx->r22, -0X1E9C);
    // 0x800DD158: addiu       $s5, $s5, -0x309C
    ctx->r21 = ADD32(ctx->r21, -0X309C);
    // 0x800DD15C: addiu       $fp, $zero, 0xA
    ctx->r30 = ADD32(0, 0XA);
L_800DD160:
    // 0x800DD160: lbu         $v0, 0x0($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X0);
    // 0x800DD164: or          $s2, $a3, $zero
    ctx->r18 = ctx->r7 | 0;
    // 0x800DD168: addiu       $v1, $zero, 0x25
    ctx->r3 = ADD32(0, 0X25);
    // 0x800DD16C: beq         $v0, $zero, L_800DD194
    if (ctx->r2 == 0) {
        // 0x800DD170: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800DD194;
    }
    // 0x800DD170: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800DD174: beql        $v1, $v0, L_800DD198
    if (ctx->r3 == ctx->r2) {
        // 0x800DD178: subu        $v0, $s2, $a3
        ctx->r2 = SUB32(ctx->r18, ctx->r7);
            goto L_800DD198;
    }
    goto skip_0;
    // 0x800DD178: subu        $v0, $s2, $a3
    ctx->r2 = SUB32(ctx->r18, ctx->r7);
    skip_0:
    // 0x800DD17C: lbu         $v0, 0x1($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X1);
L_800DD180:
    // 0x800DD180: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800DD184: beq         $v0, $zero, L_800DD194
    if (ctx->r2 == 0) {
        // 0x800DD188: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800DD194;
    }
    // 0x800DD188: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800DD18C: bnel        $v1, $v0, L_800DD180
    if (ctx->r3 != ctx->r2) {
        // 0x800DD190: lbu         $v0, 0x1($s2)
        ctx->r2 = MEM_BU(ctx->r18, 0X1);
            goto L_800DD180;
    }
    goto skip_1;
    // 0x800DD190: lbu         $v0, 0x1($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X1);
    skip_1:
L_800DD194:
    // 0x800DD194: subu        $v0, $s2, $a3
    ctx->r2 = SUB32(ctx->r18, ctx->r7);
L_800DD198:
    // 0x800DD198: blez        $v0, L_800DD1D0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800DD19C: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_800DD1D0;
    }
    // 0x800DD19C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800DD1A0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x800DD1A4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800DD1A8: jalr        $s4
    // 0x800DD1AC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_0;
    // 0x800DD1AC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_0:
    // 0x800DD1B0: beq         $v0, $zero, L_800DD1C8
    if (ctx->r2 == 0) {
        // 0x800DD1B4: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_800DD1C8;
    }
    // 0x800DD1B4: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800DD1B8: lw          $t6, 0xCC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XCC);
    // 0x800DD1BC: addu        $t7, $t6, $s1
    ctx->r15 = ADD32(ctx->r14, ctx->r17);
    // 0x800DD1C0: b           L_800DD1D0
    // 0x800DD1C4: sw          $t7, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r15;
        goto L_800DD1D0;
    // 0x800DD1C4: sw          $t7, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r15;
L_800DD1C8:
    // 0x800DD1C8: b           L_800DD718
    // 0x800DD1CC: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
        goto L_800DD718;
    // 0x800DD1CC: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_800DD1D0:
    // 0x800DD1D0: bne         $s0, $zero, L_800DD1E0
    if (ctx->r16 != 0) {
        // 0x800DD1D4: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_800DD1E0;
    }
    // 0x800DD1D4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800DD1D8: b           L_800DD718
    // 0x800DD1DC: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
        goto L_800DD718;
    // 0x800DD1DC: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_800DD1E0:
    // 0x800DD1E0: sw          $zero, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = 0;
    // 0x800DD1E4: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    // 0x800DD1E8: jal         0x800DD7A4
    // 0x800DD1EC: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    strchr_recomp(rdram, ctx);
        goto after_1;
    // 0x800DD1EC: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_1:
    // 0x800DD1F0: beq         $v0, $zero, L_800DD230
    if (ctx->r2 == 0) {
        // 0x800DD1F4: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800DD230;
    }
    // 0x800DD1F4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_800DD1F8:
    // 0x800DD1F8: subu        $t9, $s0, $s6
    ctx->r25 = SUB32(ctx->r16, ctx->r22);
    // 0x800DD1FC: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x800DD200: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x800DD204: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800DD208: lw          $t7, -0x1E94($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X1E94);
    // 0x800DD20C: lw          $t8, 0xD0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XD0);
    // 0x800DD210: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800DD214: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800DD218: or          $t9, $t8, $t7
    ctx->r25 = ctx->r24 | ctx->r15;
    // 0x800DD21C: sw          $t9, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r25;
    // 0x800DD220: jal         0x800DD7A4
    // 0x800DD224: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    strchr_recomp(rdram, ctx);
        goto after_2;
    // 0x800DD224: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    after_2:
    // 0x800DD228: bne         $v0, $zero, L_800DD1F8
    if (ctx->r2 != 0) {
        // 0x800DD22C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800DD1F8;
    }
    // 0x800DD22C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_800DD230:
    // 0x800DD230: lbu         $t6, 0x0($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X0);
    // 0x800DD234: addiu       $v0, $zero, 0x2A
    ctx->r2 = ADD32(0, 0X2A);
    // 0x800DD238: lw          $t8, 0xE4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XE4);
    // 0x800DD23C: bne         $v0, $t6, L_800DD284
    if (ctx->r2 != ctx->r14) {
        // 0x800DD240: lui         $a0, 0x800F
        ctx->r4 = S32(0X800F << 16);
            goto L_800DD284;
    }
    // 0x800DD240: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800DD244: addiu       $t7, $t8, 0x3
    ctx->r15 = ADD32(ctx->r24, 0X3);
    // 0x800DD248: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800DD24C: and         $t9, $t7, $at
    ctx->r25 = ctx->r15 & ctx->r1;
    // 0x800DD250: addiu       $t6, $t9, 0x4
    ctx->r14 = ADD32(ctx->r25, 0X4);
    // 0x800DD254: sw          $t6, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r14;
    // 0x800DD258: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x800DD25C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800DD260: bgez        $t8, L_800DD27C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800DD264: sw          $t8, 0xC8($sp)
        MEM_W(0XC8, ctx->r29) = ctx->r24;
            goto L_800DD27C;
    }
    // 0x800DD264: sw          $t8, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r24;
    // 0x800DD268: lw          $t6, 0xD0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XD0);
    // 0x800DD26C: negu        $t7, $t8
    ctx->r15 = SUB32(0, ctx->r24);
    // 0x800DD270: sw          $t7, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r15;
    // 0x800DD274: ori         $t9, $t6, 0x4
    ctx->r25 = ctx->r14 | 0X4;
    // 0x800DD278: sw          $t9, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r25;
L_800DD27C:
    // 0x800DD27C: b           L_800DD2E0
    // 0x800DD280: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
        goto L_800DD2E0;
    // 0x800DD280: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
L_800DD284:
    // 0x800DD284: sw          $zero, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = 0;
    // 0x800DD288: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    // 0x800DD28C: slti        $at, $a1, 0x30
    ctx->r1 = SIGNED(ctx->r5) < 0X30 ? 1 : 0;
    // 0x800DD290: bne         $at, $zero, L_800DD2E0
    if (ctx->r1 != 0) {
        // 0x800DD294: slti        $at, $a1, 0x3A
        ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
            goto L_800DD2E0;
    }
    // 0x800DD294: slti        $at, $a1, 0x3A
    ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
    // 0x800DD298: beql        $at, $zero, L_800DD2E4
    if (ctx->r1 == 0) {
        // 0x800DD29C: addiu       $at, $zero, 0x2E
        ctx->r1 = ADD32(0, 0X2E);
            goto L_800DD2E4;
    }
    goto skip_2;
    // 0x800DD29C: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    skip_2:
    // 0x800DD2A0: lw          $t8, 0xC8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC8);
L_800DD2A4:
    // 0x800DD2A4: slti        $at, $t8, 0x3E7
    ctx->r1 = SIGNED(ctx->r24) < 0X3E7 ? 1 : 0;
    // 0x800DD2A8: beql        $at, $zero, L_800DD2C8
    if (ctx->r1 == 0) {
        // 0x800DD2AC: lbu         $a1, 0x1($s2)
        ctx->r5 = MEM_BU(ctx->r18, 0X1);
            goto L_800DD2C8;
    }
    goto skip_3;
    // 0x800DD2AC: lbu         $a1, 0x1($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X1);
    skip_3:
    // 0x800DD2B0: multu       $t8, $fp
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800DD2B4: mflo        $t7
    ctx->r15 = lo;
    // 0x800DD2B8: addu        $t6, $a1, $t7
    ctx->r14 = ADD32(ctx->r5, ctx->r15);
    // 0x800DD2BC: addiu       $t9, $t6, -0x30
    ctx->r25 = ADD32(ctx->r14, -0X30);
    // 0x800DD2C0: sw          $t9, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r25;
    // 0x800DD2C4: lbu         $a1, 0x1($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X1);
L_800DD2C8:
    // 0x800DD2C8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800DD2CC: slti        $at, $a1, 0x30
    ctx->r1 = SIGNED(ctx->r5) < 0X30 ? 1 : 0;
    // 0x800DD2D0: bne         $at, $zero, L_800DD2E0
    if (ctx->r1 != 0) {
        // 0x800DD2D4: slti        $at, $a1, 0x3A
        ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
            goto L_800DD2E0;
    }
    // 0x800DD2D4: slti        $at, $a1, 0x3A
    ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
    // 0x800DD2D8: bnel        $at, $zero, L_800DD2A4
    if (ctx->r1 != 0) {
        // 0x800DD2DC: lw          $t8, 0xC8($sp)
        ctx->r24 = MEM_W(ctx->r29, 0XC8);
            goto L_800DD2A4;
    }
    goto skip_4;
    // 0x800DD2DC: lw          $t8, 0xC8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC8);
    skip_4:
L_800DD2E0:
    // 0x800DD2E0: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
L_800DD2E4:
    // 0x800DD2E4: beq         $a1, $at, L_800DD2F8
    if (ctx->r5 == ctx->r1) {
        // 0x800DD2E8: addiu       $t8, $zero, -0x1
        ctx->r24 = ADD32(0, -0X1);
            goto L_800DD2F8;
    }
    // 0x800DD2E8: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800DD2EC: sw          $t8, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r24;
    // 0x800DD2F0: b           L_800DD38C
    // 0x800DD2F4: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
        goto L_800DD38C;
    // 0x800DD2F4: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
L_800DD2F8:
    // 0x800DD2F8: lbu         $t7, 0x1($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X1);
    // 0x800DD2FC: lw          $t6, 0xE4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XE4);
    // 0x800DD300: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800DD304: bne         $v0, $t7, L_800DD330
    if (ctx->r2 != ctx->r15) {
        // 0x800DD308: addiu       $t9, $t6, 0x3
        ctx->r25 = ADD32(ctx->r14, 0X3);
            goto L_800DD330;
    }
    // 0x800DD308: addiu       $t9, $t6, 0x3
    ctx->r25 = ADD32(ctx->r14, 0X3);
    // 0x800DD30C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800DD310: and         $t8, $t9, $at
    ctx->r24 = ctx->r25 & ctx->r1;
    // 0x800DD314: addiu       $t7, $t8, 0x4
    ctx->r15 = ADD32(ctx->r24, 0X4);
    // 0x800DD318: sw          $t7, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r15;
    // 0x800DD31C: lw          $t6, 0x0($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X0);
    // 0x800DD320: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800DD324: sw          $t6, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r14;
    // 0x800DD328: b           L_800DD38C
    // 0x800DD32C: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
        goto L_800DD38C;
    // 0x800DD32C: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
L_800DD330:
    // 0x800DD330: sw          $zero, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = 0;
    // 0x800DD334: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    // 0x800DD338: slti        $at, $a1, 0x30
    ctx->r1 = SIGNED(ctx->r5) < 0X30 ? 1 : 0;
    // 0x800DD33C: bne         $at, $zero, L_800DD38C
    if (ctx->r1 != 0) {
        // 0x800DD340: slti        $at, $a1, 0x3A
        ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
            goto L_800DD38C;
    }
    // 0x800DD340: slti        $at, $a1, 0x3A
    ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
    // 0x800DD344: beq         $at, $zero, L_800DD38C
    if (ctx->r1 == 0) {
        // 0x800DD348: nop
    
            goto L_800DD38C;
    }
    // 0x800DD348: nop

    // 0x800DD34C: lw          $t9, 0xC4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC4);
L_800DD350:
    // 0x800DD350: slti        $at, $t9, 0x3E7
    ctx->r1 = SIGNED(ctx->r25) < 0X3E7 ? 1 : 0;
    // 0x800DD354: beql        $at, $zero, L_800DD374
    if (ctx->r1 == 0) {
        // 0x800DD358: lbu         $a1, 0x1($s2)
        ctx->r5 = MEM_BU(ctx->r18, 0X1);
            goto L_800DD374;
    }
    goto skip_5;
    // 0x800DD358: lbu         $a1, 0x1($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X1);
    skip_5:
    // 0x800DD35C: multu       $t9, $fp
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800DD360: mflo        $t7
    ctx->r15 = lo;
    // 0x800DD364: addu        $t8, $a1, $t7
    ctx->r24 = ADD32(ctx->r5, ctx->r15);
    // 0x800DD368: addiu       $t6, $t8, -0x30
    ctx->r14 = ADD32(ctx->r24, -0X30);
    // 0x800DD36C: sw          $t6, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r14;
    // 0x800DD370: lbu         $a1, 0x1($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X1);
L_800DD374:
    // 0x800DD374: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800DD378: slti        $at, $a1, 0x30
    ctx->r1 = SIGNED(ctx->r5) < 0X30 ? 1 : 0;
    // 0x800DD37C: bne         $at, $zero, L_800DD38C
    if (ctx->r1 != 0) {
        // 0x800DD380: slti        $at, $a1, 0x3A
        ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
            goto L_800DD38C;
    }
    // 0x800DD380: slti        $at, $a1, 0x3A
    ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
    // 0x800DD384: bnel        $at, $zero, L_800DD350
    if (ctx->r1 != 0) {
        // 0x800DD388: lw          $t9, 0xC4($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XC4);
            goto L_800DD350;
    }
    goto skip_6;
    // 0x800DD388: lw          $t9, 0xC4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC4);
    skip_6:
L_800DD38C:
    // 0x800DD38C: jal         0x800DD7A4
    // 0x800DD390: addiu       $a0, $a0, -0x1EA0
    ctx->r4 = ADD32(ctx->r4, -0X1EA0);
    strchr_recomp(rdram, ctx);
        goto after_3;
    // 0x800DD390: addiu       $a0, $a0, -0x1EA0
    ctx->r4 = ADD32(ctx->r4, -0X1EA0);
    after_3:
    // 0x800DD394: beq         $v0, $zero, L_800DD3AC
    if (ctx->r2 == 0) {
        // 0x800DD398: addiu       $s0, $sp, 0xA0
        ctx->r16 = ADD32(ctx->r29, 0XA0);
            goto L_800DD3AC;
    }
    // 0x800DD398: addiu       $s0, $sp, 0xA0
    ctx->r16 = ADD32(ctx->r29, 0XA0);
    // 0x800DD39C: lbu         $t9, 0x0($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0X0);
    // 0x800DD3A0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800DD3A4: b           L_800DD3B0
    // 0x800DD3A8: sb          $t9, 0xD4($sp)
    MEM_B(0XD4, ctx->r29) = ctx->r25;
        goto L_800DD3B0;
    // 0x800DD3A8: sb          $t9, 0xD4($sp)
    MEM_B(0XD4, ctx->r29) = ctx->r25;
L_800DD3AC:
    // 0x800DD3AC: sb          $zero, 0xD4($sp)
    MEM_B(0XD4, ctx->r29) = 0;
L_800DD3B0:
    // 0x800DD3B0: lbu         $t7, 0xD4($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0XD4);
    // 0x800DD3B4: addiu       $v0, $zero, 0x6C
    ctx->r2 = ADD32(0, 0X6C);
    // 0x800DD3B8: addiu       $a2, $sp, 0xE4
    ctx->r6 = ADD32(ctx->r29, 0XE4);
    // 0x800DD3BC: bne         $v0, $t7, L_800DD3DC
    if (ctx->r2 != ctx->r15) {
        // 0x800DD3C0: addiu       $a3, $sp, 0x74
        ctx->r7 = ADD32(ctx->r29, 0X74);
            goto L_800DD3DC;
    }
    // 0x800DD3C0: addiu       $a3, $sp, 0x74
    ctx->r7 = ADD32(ctx->r29, 0X74);
    // 0x800DD3C4: lbu         $t8, 0x0($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X0);
    // 0x800DD3C8: addiu       $t6, $zero, 0x4C
    ctx->r14 = ADD32(0, 0X4C);
    // 0x800DD3CC: bne         $v0, $t8, L_800DD3DC
    if (ctx->r2 != ctx->r24) {
        // 0x800DD3D0: nop
    
            goto L_800DD3DC;
    }
    // 0x800DD3D0: nop

    // 0x800DD3D4: sb          $t6, 0xD4($sp)
    MEM_B(0XD4, ctx->r29) = ctx->r14;
    // 0x800DD3D8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_800DD3DC:
    // 0x800DD3DC: jal         0x800DCA90
    // 0x800DD3E0: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    func_800DCA90(rdram, ctx);
        goto after_4;
    // 0x800DD3E0: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    after_4:
    // 0x800DD3E4: lw          $t9, 0xC8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC8);
    // 0x800DD3E8: lw          $t7, 0xAC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XAC);
    // 0x800DD3EC: lw          $t6, 0xB0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB0);
    // 0x800DD3F0: subu        $t8, $t9, $t7
    ctx->r24 = SUB32(ctx->r25, ctx->r15);
    // 0x800DD3F4: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
    // 0x800DD3F8: subu        $t9, $t8, $t6
    ctx->r25 = SUB32(ctx->r24, ctx->r14);
    // 0x800DD3FC: lw          $t6, 0xB8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB8);
    // 0x800DD400: subu        $t8, $t9, $t7
    ctx->r24 = SUB32(ctx->r25, ctx->r15);
    // 0x800DD404: lw          $t7, 0xBC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XBC);
    // 0x800DD408: subu        $t9, $t8, $t6
    ctx->r25 = SUB32(ctx->r24, ctx->r14);
    // 0x800DD40C: lw          $t6, 0xC0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC0);
    // 0x800DD410: subu        $t8, $t9, $t7
    ctx->r24 = SUB32(ctx->r25, ctx->r15);
    // 0x800DD414: lw          $t7, 0xD0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XD0);
    // 0x800DD418: subu        $t9, $t8, $t6
    ctx->r25 = SUB32(ctx->r24, ctx->r14);
    // 0x800DD41C: sw          $t9, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r25;
    // 0x800DD420: andi        $t8, $t7, 0x4
    ctx->r24 = ctx->r15 & 0X4;
    // 0x800DD424: bne         $t8, $zero, L_800DD490
    if (ctx->r24 != 0) {
        // 0x800DD428: slt         $t6, $zero, $t9
        ctx->r14 = SIGNED(0) < SIGNED(ctx->r25) ? 1 : 0;
            goto L_800DD490;
    }
    // 0x800DD428: slt         $t6, $zero, $t9
    ctx->r14 = SIGNED(0) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800DD42C: beql        $t6, $zero, L_800DD494
    if (ctx->r14 == 0) {
        // 0x800DD430: lw          $t9, 0xAC($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XAC);
            goto L_800DD494;
    }
    goto skip_7;
    // 0x800DD430: lw          $t9, 0xAC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XAC);
    skip_7:
    // 0x800DD434: beq         $t6, $zero, L_800DD490
    if (ctx->r14 == 0) {
        // 0x800DD438: or          $s1, $t9, $zero
        ctx->r17 = ctx->r25 | 0;
            goto L_800DD490;
    }
    // 0x800DD438: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x800DD43C: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
L_800DD440:
    // 0x800DD440: bne         $at, $zero, L_800DD450
    if (ctx->r1 != 0) {
        // 0x800DD444: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_800DD450;
    }
    // 0x800DD444: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x800DD448: b           L_800DD450
    // 0x800DD44C: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
        goto L_800DD450;
    // 0x800DD44C: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
L_800DD450:
    // 0x800DD450: blez        $s0, L_800DD484
    if (SIGNED(ctx->r16) <= 0) {
        // 0x800DD454: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_800DD484;
    }
    // 0x800DD454: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800DD458: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x800DD45C: jalr        $s4
    // 0x800DD460: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_5;
    // 0x800DD460: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_5:
    // 0x800DD464: beq         $v0, $zero, L_800DD47C
    if (ctx->r2 == 0) {
        // 0x800DD468: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_800DD47C;
    }
    // 0x800DD468: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800DD46C: lw          $t7, 0xCC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XCC);
    // 0x800DD470: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x800DD474: b           L_800DD484
    // 0x800DD478: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
        goto L_800DD484;
    // 0x800DD478: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
L_800DD47C:
    // 0x800DD47C: b           L_800DD718
    // 0x800DD480: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
        goto L_800DD718;
    // 0x800DD480: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_800DD484:
    // 0x800DD484: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x800DD488: bgtzl       $s1, L_800DD440
    if (SIGNED(ctx->r17) > 0) {
        // 0x800DD48C: sltiu       $at, $s1, 0x21
        ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
            goto L_800DD440;
    }
    goto skip_8;
    // 0x800DD48C: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
    skip_8:
L_800DD490:
    // 0x800DD490: lw          $t9, 0xAC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XAC);
L_800DD494:
    // 0x800DD494: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800DD498: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    // 0x800DD49C: blezl       $t9, L_800DD4D4
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800DD4A0: lw          $t9, 0xB0($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XB0);
            goto L_800DD4D4;
    }
    goto skip_9;
    // 0x800DD4A0: lw          $t9, 0xB0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB0);
    skip_9:
    // 0x800DD4A4: jalr        $s4
    // 0x800DD4A8: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_6;
    // 0x800DD4A8: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    after_6:
    // 0x800DD4AC: beq         $v0, $zero, L_800DD4C8
    if (ctx->r2 == 0) {
        // 0x800DD4B0: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_800DD4C8;
    }
    // 0x800DD4B0: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800DD4B4: lw          $t6, 0xCC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XCC);
    // 0x800DD4B8: lw          $t7, 0xAC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XAC);
    // 0x800DD4BC: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800DD4C0: b           L_800DD4D0
    // 0x800DD4C4: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
        goto L_800DD4D0;
    // 0x800DD4C4: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
L_800DD4C8:
    // 0x800DD4C8: b           L_800DD718
    // 0x800DD4CC: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
        goto L_800DD718;
    // 0x800DD4CC: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_800DD4D0:
    // 0x800DD4D0: lw          $t9, 0xB0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB0);
L_800DD4D4:
    // 0x800DD4D4: slt         $t6, $zero, $t9
    ctx->r14 = SIGNED(0) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800DD4D8: beql        $t6, $zero, L_800DD540
    if (ctx->r14 == 0) {
        // 0x800DD4DC: lw          $t9, 0xB4($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XB4);
            goto L_800DD540;
    }
    goto skip_10;
    // 0x800DD4DC: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
    skip_10:
    // 0x800DD4E0: beq         $t6, $zero, L_800DD53C
    if (ctx->r14 == 0) {
        // 0x800DD4E4: or          $s1, $t9, $zero
        ctx->r17 = ctx->r25 | 0;
            goto L_800DD53C;
    }
    // 0x800DD4E4: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x800DD4E8: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
L_800DD4EC:
    // 0x800DD4EC: bne         $at, $zero, L_800DD4FC
    if (ctx->r1 != 0) {
        // 0x800DD4F0: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_800DD4FC;
    }
    // 0x800DD4F0: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x800DD4F4: b           L_800DD4FC
    // 0x800DD4F8: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
        goto L_800DD4FC;
    // 0x800DD4F8: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
L_800DD4FC:
    // 0x800DD4FC: blez        $s0, L_800DD530
    if (SIGNED(ctx->r16) <= 0) {
        // 0x800DD500: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_800DD530;
    }
    // 0x800DD500: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800DD504: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800DD508: jalr        $s4
    // 0x800DD50C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_7;
    // 0x800DD50C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_7:
    // 0x800DD510: beq         $v0, $zero, L_800DD528
    if (ctx->r2 == 0) {
        // 0x800DD514: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_800DD528;
    }
    // 0x800DD514: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800DD518: lw          $t7, 0xCC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XCC);
    // 0x800DD51C: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x800DD520: b           L_800DD530
    // 0x800DD524: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
        goto L_800DD530;
    // 0x800DD524: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
L_800DD528:
    // 0x800DD528: b           L_800DD718
    // 0x800DD52C: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
        goto L_800DD718;
    // 0x800DD52C: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_800DD530:
    // 0x800DD530: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x800DD534: bgtzl       $s1, L_800DD4EC
    if (SIGNED(ctx->r17) > 0) {
        // 0x800DD538: sltiu       $at, $s1, 0x21
        ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
            goto L_800DD4EC;
    }
    goto skip_11;
    // 0x800DD538: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
    skip_11:
L_800DD53C:
    // 0x800DD53C: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
L_800DD540:
    // 0x800DD540: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800DD544: lw          $a1, 0xA8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA8);
    // 0x800DD548: blezl       $t9, L_800DD580
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800DD54C: lw          $t9, 0xB8($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XB8);
            goto L_800DD580;
    }
    goto skip_12;
    // 0x800DD54C: lw          $t9, 0xB8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB8);
    skip_12:
    // 0x800DD550: jalr        $s4
    // 0x800DD554: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_8;
    // 0x800DD554: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    after_8:
    // 0x800DD558: beq         $v0, $zero, L_800DD574
    if (ctx->r2 == 0) {
        // 0x800DD55C: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_800DD574;
    }
    // 0x800DD55C: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800DD560: lw          $t6, 0xCC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XCC);
    // 0x800DD564: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
    // 0x800DD568: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800DD56C: b           L_800DD57C
    // 0x800DD570: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
        goto L_800DD57C;
    // 0x800DD570: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
L_800DD574:
    // 0x800DD574: b           L_800DD718
    // 0x800DD578: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
        goto L_800DD718;
    // 0x800DD578: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_800DD57C:
    // 0x800DD57C: lw          $t9, 0xB8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB8);
L_800DD580:
    // 0x800DD580: slt         $t6, $zero, $t9
    ctx->r14 = SIGNED(0) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800DD584: beql        $t6, $zero, L_800DD5EC
    if (ctx->r14 == 0) {
        // 0x800DD588: lw          $t9, 0xBC($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XBC);
            goto L_800DD5EC;
    }
    goto skip_13;
    // 0x800DD588: lw          $t9, 0xBC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XBC);
    skip_13:
    // 0x800DD58C: beq         $t6, $zero, L_800DD5E8
    if (ctx->r14 == 0) {
        // 0x800DD590: or          $s1, $t9, $zero
        ctx->r17 = ctx->r25 | 0;
            goto L_800DD5E8;
    }
    // 0x800DD590: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x800DD594: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
L_800DD598:
    // 0x800DD598: bne         $at, $zero, L_800DD5A8
    if (ctx->r1 != 0) {
        // 0x800DD59C: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_800DD5A8;
    }
    // 0x800DD59C: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x800DD5A0: b           L_800DD5A8
    // 0x800DD5A4: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
        goto L_800DD5A8;
    // 0x800DD5A4: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
L_800DD5A8:
    // 0x800DD5A8: blez        $s0, L_800DD5DC
    if (SIGNED(ctx->r16) <= 0) {
        // 0x800DD5AC: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_800DD5DC;
    }
    // 0x800DD5AC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800DD5B0: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800DD5B4: jalr        $s4
    // 0x800DD5B8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_9;
    // 0x800DD5B8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_9:
    // 0x800DD5BC: beq         $v0, $zero, L_800DD5D4
    if (ctx->r2 == 0) {
        // 0x800DD5C0: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_800DD5D4;
    }
    // 0x800DD5C0: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800DD5C4: lw          $t7, 0xCC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XCC);
    // 0x800DD5C8: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x800DD5CC: b           L_800DD5DC
    // 0x800DD5D0: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
        goto L_800DD5DC;
    // 0x800DD5D0: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
L_800DD5D4:
    // 0x800DD5D4: b           L_800DD718
    // 0x800DD5D8: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
        goto L_800DD718;
    // 0x800DD5D8: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_800DD5DC:
    // 0x800DD5DC: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x800DD5E0: bgtzl       $s1, L_800DD598
    if (SIGNED(ctx->r17) > 0) {
        // 0x800DD5E4: sltiu       $at, $s1, 0x21
        ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
            goto L_800DD598;
    }
    goto skip_14;
    // 0x800DD5E4: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
    skip_14:
L_800DD5E8:
    // 0x800DD5E8: lw          $t9, 0xBC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XBC);
L_800DD5EC:
    // 0x800DD5EC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800DD5F0: lw          $t6, 0xA8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA8);
    // 0x800DD5F4: blez        $t9, L_800DD62C
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800DD5F8: lw          $t7, 0xB4($sp)
        ctx->r15 = MEM_W(ctx->r29, 0XB4);
            goto L_800DD62C;
    }
    // 0x800DD5F8: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
    // 0x800DD5FC: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    // 0x800DD600: jalr        $s4
    // 0x800DD604: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_10;
    // 0x800DD604: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    after_10:
    // 0x800DD608: beq         $v0, $zero, L_800DD624
    if (ctx->r2 == 0) {
        // 0x800DD60C: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_800DD624;
    }
    // 0x800DD60C: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800DD610: lw          $t8, 0xCC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XCC);
    // 0x800DD614: lw          $t6, 0xBC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XBC);
    // 0x800DD618: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x800DD61C: b           L_800DD62C
    // 0x800DD620: sw          $t7, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r15;
        goto L_800DD62C;
    // 0x800DD620: sw          $t7, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r15;
L_800DD624:
    // 0x800DD624: b           L_800DD718
    // 0x800DD628: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
        goto L_800DD718;
    // 0x800DD628: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_800DD62C:
    // 0x800DD62C: lw          $t9, 0xC0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC0);
    // 0x800DD630: slt         $t8, $zero, $t9
    ctx->r24 = SIGNED(0) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800DD634: beql        $t8, $zero, L_800DD69C
    if (ctx->r24 == 0) {
        // 0x800DD638: lw          $t9, 0xD0($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XD0);
            goto L_800DD69C;
    }
    goto skip_15;
    // 0x800DD638: lw          $t9, 0xD0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD0);
    skip_15:
    // 0x800DD63C: beq         $t8, $zero, L_800DD698
    if (ctx->r24 == 0) {
        // 0x800DD640: or          $s1, $t9, $zero
        ctx->r17 = ctx->r25 | 0;
            goto L_800DD698;
    }
    // 0x800DD640: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x800DD644: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
L_800DD648:
    // 0x800DD648: bne         $at, $zero, L_800DD658
    if (ctx->r1 != 0) {
        // 0x800DD64C: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_800DD658;
    }
    // 0x800DD64C: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x800DD650: b           L_800DD658
    // 0x800DD654: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
        goto L_800DD658;
    // 0x800DD654: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
L_800DD658:
    // 0x800DD658: blez        $s0, L_800DD68C
    if (SIGNED(ctx->r16) <= 0) {
        // 0x800DD65C: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_800DD68C;
    }
    // 0x800DD65C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800DD660: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800DD664: jalr        $s4
    // 0x800DD668: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_11;
    // 0x800DD668: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_11:
    // 0x800DD66C: beq         $v0, $zero, L_800DD684
    if (ctx->r2 == 0) {
        // 0x800DD670: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_800DD684;
    }
    // 0x800DD670: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800DD674: lw          $t6, 0xCC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XCC);
    // 0x800DD678: addu        $t7, $t6, $s0
    ctx->r15 = ADD32(ctx->r14, ctx->r16);
    // 0x800DD67C: b           L_800DD68C
    // 0x800DD680: sw          $t7, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r15;
        goto L_800DD68C;
    // 0x800DD680: sw          $t7, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r15;
L_800DD684:
    // 0x800DD684: b           L_800DD718
    // 0x800DD688: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
        goto L_800DD718;
    // 0x800DD688: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_800DD68C:
    // 0x800DD68C: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x800DD690: bgtzl       $s1, L_800DD648
    if (SIGNED(ctx->r17) > 0) {
        // 0x800DD694: sltiu       $at, $s1, 0x21
        ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
            goto L_800DD648;
    }
    goto skip_16;
    // 0x800DD694: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
    skip_16:
L_800DD698:
    // 0x800DD698: lw          $t9, 0xD0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD0);
L_800DD69C:
    // 0x800DD69C: lw          $t6, 0xC8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC8);
    // 0x800DD6A0: andi        $t8, $t9, 0x4
    ctx->r24 = ctx->r25 & 0X4;
    // 0x800DD6A4: beq         $t8, $zero, L_800DD710
    if (ctx->r24 == 0) {
        // 0x800DD6A8: slt         $t7, $zero, $t6
        ctx->r15 = SIGNED(0) < SIGNED(ctx->r14) ? 1 : 0;
            goto L_800DD710;
    }
    // 0x800DD6A8: slt         $t7, $zero, $t6
    ctx->r15 = SIGNED(0) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800DD6AC: beq         $t7, $zero, L_800DD710
    if (ctx->r15 == 0) {
        // 0x800DD6B0: nop
    
            goto L_800DD710;
    }
    // 0x800DD6B0: nop

    // 0x800DD6B4: beq         $t7, $zero, L_800DD710
    if (ctx->r15 == 0) {
        // 0x800DD6B8: or          $s1, $t6, $zero
        ctx->r17 = ctx->r14 | 0;
            goto L_800DD710;
    }
    // 0x800DD6B8: or          $s1, $t6, $zero
    ctx->r17 = ctx->r14 | 0;
    // 0x800DD6BC: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
L_800DD6C0:
    // 0x800DD6C0: bne         $at, $zero, L_800DD6D0
    if (ctx->r1 != 0) {
        // 0x800DD6C4: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_800DD6D0;
    }
    // 0x800DD6C4: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x800DD6C8: b           L_800DD6D0
    // 0x800DD6CC: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
        goto L_800DD6D0;
    // 0x800DD6CC: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
L_800DD6D0:
    // 0x800DD6D0: blez        $s0, L_800DD704
    if (SIGNED(ctx->r16) <= 0) {
        // 0x800DD6D4: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_800DD704;
    }
    // 0x800DD6D4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800DD6D8: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x800DD6DC: jalr        $s4
    // 0x800DD6E0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_12;
    // 0x800DD6E0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_12:
    // 0x800DD6E4: beq         $v0, $zero, L_800DD6FC
    if (ctx->r2 == 0) {
        // 0x800DD6E8: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_800DD6FC;
    }
    // 0x800DD6E8: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800DD6EC: lw          $t9, 0xCC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XCC);
    // 0x800DD6F0: addu        $t8, $t9, $s0
    ctx->r24 = ADD32(ctx->r25, ctx->r16);
    // 0x800DD6F4: b           L_800DD704
    // 0x800DD6F8: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
        goto L_800DD704;
    // 0x800DD6F8: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
L_800DD6FC:
    // 0x800DD6FC: b           L_800DD718
    // 0x800DD700: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
        goto L_800DD718;
    // 0x800DD700: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_800DD704:
    // 0x800DD704: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x800DD708: bgtzl       $s1, L_800DD6C0
    if (SIGNED(ctx->r17) > 0) {
        // 0x800DD70C: sltiu       $at, $s1, 0x21
        ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
            goto L_800DD6C0;
    }
    goto skip_17;
    // 0x800DD70C: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
    skip_17:
L_800DD710:
    // 0x800DD710: b           L_800DD160
    // 0x800DD714: addiu       $a3, $s2, 0x1
    ctx->r7 = ADD32(ctx->r18, 0X1);
        goto L_800DD160;
    // 0x800DD714: addiu       $a3, $s2, 0x1
    ctx->r7 = ADD32(ctx->r18, 0X1);
L_800DD718:
    // 0x800DD718: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800DD71C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800DD720: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800DD724: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800DD728: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800DD72C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800DD730: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800DD734: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800DD738: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x800DD73C: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x800DD740: jr          $ra
    // 0x800DD744: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
    return;
    // 0x800DD744: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
    // 0x800DD748: nop

    // 0x800DD74C: nop

;}
RECOMP_FUNC void memcpy_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DD750: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800DD754: beq         $a2, $zero, L_800DD774
    if (ctx->r6 == 0) {
        // 0x800DD758: or          $v1, $a1, $zero
        ctx->r3 = ctx->r5 | 0;
            goto L_800DD774;
    }
    // 0x800DD758: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
L_800DD75C:
    // 0x800DD75C: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    // 0x800DD760: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x800DD764: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800DD768: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800DD76C: bne         $a2, $zero, L_800DD75C
    if (ctx->r6 != 0) {
        // 0x800DD770: sb          $t6, -0x1($v0)
        MEM_B(-0X1, ctx->r2) = ctx->r14;
            goto L_800DD75C;
    }
    // 0x800DD770: sb          $t6, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = ctx->r14;
L_800DD774:
    // 0x800DD774: jr          $ra
    // 0x800DD778: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x800DD778: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
;}
RECOMP_FUNC void strlen_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DD77C: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x800DD780: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800DD784: beq         $t6, $zero, L_800DD79C
    if (ctx->r14 == 0) {
        // 0x800DD788: nop
    
            goto L_800DD79C;
    }
    // 0x800DD788: nop

    // 0x800DD78C: lbu         $t7, 0x1($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X1);
L_800DD790:
    // 0x800DD790: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800DD794: bnel        $t7, $zero, L_800DD790
    if (ctx->r15 != 0) {
        // 0x800DD798: lbu         $t7, 0x1($v1)
        ctx->r15 = MEM_BU(ctx->r3, 0X1);
            goto L_800DD790;
    }
    goto skip_0;
    // 0x800DD798: lbu         $t7, 0x1($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X1);
    skip_0:
L_800DD79C:
    // 0x800DD79C: jr          $ra
    // 0x800DD7A0: subu        $v0, $v1, $a0
    ctx->r2 = SUB32(ctx->r3, ctx->r4);
    return;
    // 0x800DD7A0: subu        $v0, $v1, $a0
    ctx->r2 = SUB32(ctx->r3, ctx->r4);
;}
RECOMP_FUNC void strchr_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DD7A4: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x800DD7A8: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x800DD7AC: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // 0x800DD7B0: beql        $t6, $v1, L_800DD7DC
    if (ctx->r14 == ctx->r3) {
        // 0x800DD7B4: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_800DD7DC;
    }
    goto skip_0;
    // 0x800DD7B4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    skip_0:
L_800DD7B8:
    // 0x800DD7B8: bnel        $v1, $zero, L_800DD7CC
    if (ctx->r3 != 0) {
        // 0x800DD7BC: lbu         $v1, 0x1($a0)
        ctx->r3 = MEM_BU(ctx->r4, 0X1);
            goto L_800DD7CC;
    }
    goto skip_1;
    // 0x800DD7BC: lbu         $v1, 0x1($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X1);
    skip_1:
    // 0x800DD7C0: jr          $ra
    // 0x800DD7C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800DD7C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800DD7C8: lbu         $v1, 0x1($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X1);
L_800DD7CC:
    // 0x800DD7CC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800DD7D0: bne         $v0, $v1, L_800DD7B8
    if (ctx->r2 != ctx->r3) {
        // 0x800DD7D4: nop
    
            goto L_800DD7B8;
    }
    // 0x800DD7D4: nop

    // 0x800DD7D8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_800DD7DC:
    // 0x800DD7DC: jr          $ra
    // 0x800DD7E0: nop

    return;
    // 0x800DD7E0: nop

    // 0x800DD7E4: nop

    // 0x800DD7E8: nop

    // 0x800DD7EC: nop

;}
RECOMP_FUNC void alSynDelete_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DD7F0: jr          $ra
    // 0x800DD7F4: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    return;
    // 0x800DD7F4: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x800DD7F8: nop

    // 0x800DD7FC: nop

;}
RECOMP_FUNC void alSaveNew_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DD9B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DD9B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DD9B8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800DD9BC: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800DD9C0: addiu       $a2, $a2, -0x100
    ctx->r6 = ADD32(ctx->r6, -0X100);
    // 0x800DD9C4: addiu       $a1, $a1, -0xCC
    ctx->r5 = ADD32(ctx->r5, -0XCC);
    // 0x800DD9C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800DD9CC: jal         0x800E2230
    // 0x800DD9D0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    alFilterNew_recomp(rdram, ctx);
        goto after_0;
    // 0x800DD9D0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_0:
    // 0x800DD9D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800DD9D8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800DD9DC: sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
    // 0x800DD9E0: sw          $t6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r14;
    // 0x800DD9E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DD9E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DD9EC: jr          $ra
    // 0x800DD9F0: nop

    return;
    // 0x800DD9F0: nop

;}
RECOMP_FUNC void alMainBusNew_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DD9F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DD9F8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800DD9FC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800DDA00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DDA04: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800DDA08: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800DDA0C: addiu       $a1, $a1, -0x1DE0
    ctx->r5 = ADD32(ctx->r5, -0X1DE0);
    // 0x800DDA10: addiu       $a2, $a2, -0x1E10
    ctx->r6 = ADD32(ctx->r6, -0X1E10);
    // 0x800DDA14: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800DDA18: jal         0x800E2230
    // 0x800DDA1C: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    alFilterNew_recomp(rdram, ctx);
        goto after_0;
    // 0x800DDA1C: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    after_0:
    // 0x800DDA20: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800DDA24: sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
    // 0x800DDA28: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800DDA2C: sw          $t6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r14;
    // 0x800DDA30: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800DDA34: sw          $t7, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r15;
    // 0x800DDA38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DDA3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DDA40: jr          $ra
    // 0x800DDA44: nop

    return;
    // 0x800DDA44: nop

;}
RECOMP_FUNC void alAuxBusNew_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DDA48: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DDA4C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800DDA50: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800DDA54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DDA58: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800DDA5C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800DDA60: addiu       $a1, $a1, -0x1E0
    ctx->r5 = ADD32(ctx->r5, -0X1E0);
    // 0x800DDA64: addiu       $a2, $a2, -0x210
    ctx->r6 = ADD32(ctx->r6, -0X210);
    // 0x800DDA68: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800DDA6C: jal         0x800E2230
    // 0x800DDA70: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    alFilterNew_recomp(rdram, ctx);
        goto after_0;
    // 0x800DDA70: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    after_0:
    // 0x800DDA74: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800DDA78: sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
    // 0x800DDA7C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800DDA80: sw          $t6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r14;
    // 0x800DDA84: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800DDA88: sw          $t7, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r15;
    // 0x800DDA8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DDA90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DDA94: jr          $ra
    // 0x800DDA98: nop

    return;
    // 0x800DDA98: nop

;}
RECOMP_FUNC void alResampleNew_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DDA9C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800DDAA0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800DDAA4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800DDAA8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800DDAAC: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800DDAB0: addiu       $a2, $a2, -0x1170
    ctx->r6 = ADD32(ctx->r6, -0X1170);
    // 0x800DDAB4: addiu       $a1, $a1, -0x1084
    ctx->r5 = ADD32(ctx->r5, -0X1084);
    // 0x800DDAB8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800DDABC: jal         0x800E2230
    // 0x800DDAC0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alFilterNew_recomp(rdram, ctx);
        goto after_0;
    // 0x800DDAC0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x800DDAC4: addiu       $t6, $zero, 0x20
    ctx->r14 = ADD32(0, 0X20);
    // 0x800DDAC8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800DDACC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800DDAD0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800DDAD4: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x800DDAD8: jal         0x800D8AE0
    // 0x800DDADC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc_recomp(rdram, ctx);
        goto after_1;
    // 0x800DDADC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x800DDAE0: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800DDAE4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800DDAE8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800DDAEC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800DDAF0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800DDAF4: sw          $v0, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r2;
    // 0x800DDAF8: sw          $t7, 0x24($t0)
    MEM_W(0X24, ctx->r8) = ctx->r15;
    // 0x800DDAFC: sw          $zero, 0x30($t0)
    MEM_W(0X30, ctx->r8) = 0;
    // 0x800DDB00: sw          $zero, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = 0;
    // 0x800DDB04: sw          $zero, 0x28($t0)
    MEM_W(0X28, ctx->r8) = 0;
    // 0x800DDB08: sw          $zero, 0x2C($t0)
    MEM_W(0X2C, ctx->r8) = 0;
    // 0x800DDB0C: swc1        $f4, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->f4.u32l;
    // 0x800DDB10: swc1        $f6, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->f6.u32l;
    // 0x800DDB14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800DDB18: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800DDB1C: jr          $ra
    // 0x800DDB20: nop

    return;
    // 0x800DDB20: nop

;}
RECOMP_FUNC void alLoadNew_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DDB24: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800DDB28: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800DDB2C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800DDB30: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800DDB34: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800DDB38: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800DDB3C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800DDB40: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800DDB44: addiu       $a1, $a1, -0x1614
    ctx->r5 = ADD32(ctx->r5, -0X1614);
    // 0x800DDB48: addiu       $a2, $a2, -0x1CC0
    ctx->r6 = ADD32(ctx->r6, -0X1CC0);
    // 0x800DDB4C: jal         0x800E2230
    // 0x800DDB50: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    alFilterNew_recomp(rdram, ctx);
        goto after_0;
    // 0x800DDB50: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x800DDB54: addiu       $t6, $zero, 0x20
    ctx->r14 = ADD32(0, 0X20);
    // 0x800DDB58: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800DDB5C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800DDB60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800DDB64: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x800DDB68: jal         0x800D8AE0
    // 0x800DDB6C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc_recomp(rdram, ctx);
        goto after_1;
    // 0x800DDB6C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x800DDB70: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // 0x800DDB74: addiu       $t7, $zero, 0x20
    ctx->r15 = ADD32(0, 0X20);
    // 0x800DDB78: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800DDB7C: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x800DDB80: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800DDB84: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800DDB88: jal         0x800D8AE0
    // 0x800DDB8C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc_recomp(rdram, ctx);
        goto after_2;
    // 0x800DDB8C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x800DDB90: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    // 0x800DDB94: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x800DDB98: addiu       $a0, $s0, 0x34
    ctx->r4 = ADD32(ctx->r16, 0X34);
    // 0x800DDB9C: jalr        $t9
    // 0x800DDBA0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x800DDBA0: nop

    after_3:
    // 0x800DDBA4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800DDBA8: sw          $v0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r2;
    // 0x800DDBAC: sw          $zero, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = 0;
    // 0x800DDBB0: sw          $t8, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r24;
    // 0x800DDBB4: sw          $zero, 0x44($s0)
    MEM_W(0X44, ctx->r16) = 0;
    // 0x800DDBB8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800DDBBC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800DDBC0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800DDBC4: jr          $ra
    // 0x800DDBC8: nop

    return;
    // 0x800DDBC8: nop

;}
RECOMP_FUNC void alEnvmixerNew_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DDBCC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800DDBD0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800DDBD4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800DDBD8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800DDBDC: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800DDBE0: addiu       $a2, $a2, -0xD5C
    ctx->r6 = ADD32(ctx->r6, -0XD5C);
    // 0x800DDBE4: addiu       $a1, $a1, -0x764
    ctx->r5 = ADD32(ctx->r5, -0X764);
    // 0x800DDBE8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800DDBEC: jal         0x800E2230
    // 0x800DDBF0: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    alFilterNew_recomp(rdram, ctx);
        goto after_0;
    // 0x800DDBF0: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_0:
    // 0x800DDBF4: addiu       $t6, $zero, 0x50
    ctx->r14 = ADD32(0, 0X50);
    // 0x800DDBF8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800DDBFC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800DDC00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800DDC04: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x800DDC08: jal         0x800D8AE0
    // 0x800DDC0C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc_recomp(rdram, ctx);
        goto after_1;
    // 0x800DDC0C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x800DDC10: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800DDC14: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800DDC18: sw          $v0, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r2;
    // 0x800DDC1C: sw          $v1, 0x38($t0)
    MEM_W(0X38, ctx->r8) = ctx->r3;
    // 0x800DDC20: sw          $zero, 0x48($t0)
    MEM_W(0X48, ctx->r8) = 0;
    // 0x800DDC24: sh          $v1, 0x1A($t0)
    MEM_H(0X1A, ctx->r8) = ctx->r3;
    // 0x800DDC28: sh          $v1, 0x28($t0)
    MEM_H(0X28, ctx->r8) = ctx->r3;
    // 0x800DDC2C: sh          $v1, 0x2E($t0)
    MEM_H(0X2E, ctx->r8) = ctx->r3;
    // 0x800DDC30: sh          $v1, 0x1C($t0)
    MEM_H(0X1C, ctx->r8) = ctx->r3;
    // 0x800DDC34: sh          $v1, 0x1E($t0)
    MEM_H(0X1E, ctx->r8) = ctx->r3;
    // 0x800DDC38: sh          $zero, 0x20($t0)
    MEM_H(0X20, ctx->r8) = 0;
    // 0x800DDC3C: sh          $zero, 0x22($t0)
    MEM_H(0X22, ctx->r8) = 0;
    // 0x800DDC40: sh          $v1, 0x26($t0)
    MEM_H(0X26, ctx->r8) = ctx->r3;
    // 0x800DDC44: sh          $zero, 0x24($t0)
    MEM_H(0X24, ctx->r8) = 0;
    // 0x800DDC48: sw          $zero, 0x30($t0)
    MEM_W(0X30, ctx->r8) = 0;
    // 0x800DDC4C: sw          $zero, 0x34($t0)
    MEM_W(0X34, ctx->r8) = 0;
    // 0x800DDC50: sh          $zero, 0x18($t0)
    MEM_H(0X18, ctx->r8) = 0;
    // 0x800DDC54: sw          $zero, 0x3C($t0)
    MEM_W(0X3C, ctx->r8) = 0;
    // 0x800DDC58: sw          $zero, 0x40($t0)
    MEM_W(0X40, ctx->r8) = 0;
    // 0x800DDC5C: sw          $zero, 0x44($t0)
    MEM_W(0X44, ctx->r8) = 0;
    // 0x800DDC60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800DDC64: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800DDC68: jr          $ra
    // 0x800DDC6C: nop

    return;
    // 0x800DDC6C: nop

;}
RECOMP_FUNC void init_lpfilter_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DDC70: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    // 0x800DDC74: addiu       $t9, $zero, 0x4000
    ctx->r25 = ADD32(0, 0X4000);
    // 0x800DDC78: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800DDC7C: sll         $t6, $v0, 14
    ctx->r14 = S32(ctx->r2 << 14);
    // 0x800DDC80: sra         $v1, $t6, 15
    ctx->r3 = S32(SIGNED(ctx->r14) >> 15);
    // 0x800DDC84: sll         $t7, $v1, 16
    ctx->r15 = S32(ctx->r3 << 16);
    // 0x800DDC88: sra         $v1, $t7, 16
    ctx->r3 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800DDC8C: subu        $t0, $t9, $v1
    ctx->r8 = SUB32(ctx->r25, ctx->r3);
    // 0x800DDC90: sh          $t0, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r8;
    // 0x800DDC94: sw          $t1, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r9;
    // 0x800DDC98: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800DDC9C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
L_800DDCA0:
    // 0x800DDCA0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800DDCA4: slti        $at, $a1, 0x8
    ctx->r1 = SIGNED(ctx->r5) < 0X8 ? 1 : 0;
    // 0x800DDCA8: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x800DDCAC: bne         $at, $zero, L_800DDCA0
    if (ctx->r1 != 0) {
        // 0x800DDCB0: sh          $zero, 0x6($a2)
        MEM_H(0X6, ctx->r6) = 0;
            goto L_800DDCA0;
    }
    // 0x800DDCB0: sh          $zero, 0x6($a2)
    MEM_H(0X6, ctx->r6) = 0;
    // 0x800DDCB4: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x800DDCB8: lui         $at, 0x40D0
    ctx->r1 = S32(0X40D0 << 16);
    // 0x800DDCBC: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x800DDCC0: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x800DDCC4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800DDCC8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800DDCCC: slti        $at, $a1, 0x10
    ctx->r1 = SIGNED(ctx->r5) < 0X10 ? 1 : 0;
    // 0x800DDCD0: sh          $v1, 0x8($a2)
    MEM_H(0X8, ctx->r6) = ctx->r3;
    // 0x800DDCD4: div.d       $f2, $f6, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f12.d); 
    ctx->f2.d = DIV_D(ctx->f6.d, ctx->f12.d);
    // 0x800DDCD8: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x800DDCDC: beq         $at, $zero, L_800DDD08
    if (ctx->r1 == 0) {
        // 0x800DDCE0: mov.d       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
            goto L_800DDD08;
    }
    // 0x800DDCE0: mov.d       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
L_800DDCE4:
    // 0x800DDCE4: mul.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = MUL_D(ctx->f0.d, ctx->f2.d);
    // 0x800DDCE8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800DDCEC: slti        $at, $a1, 0x10
    ctx->r1 = SIGNED(ctx->r5) < 0X10 ? 1 : 0;
    // 0x800DDCF0: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x800DDCF4: mul.d       $f8, $f0, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = MUL_D(ctx->f0.d, ctx->f12.d);
    // 0x800DDCF8: trunc.w.d   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_D(ctx->f8.d);
    // 0x800DDCFC: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x800DDD00: bne         $at, $zero, L_800DDCE4
    if (ctx->r1 != 0) {
        // 0x800DDD04: sh          $t3, 0x6($a2)
        MEM_H(0X6, ctx->r6) = ctx->r11;
            goto L_800DDCE4;
    }
    // 0x800DDD04: sh          $t3, 0x6($a2)
    MEM_H(0X6, ctx->r6) = ctx->r11;
L_800DDD08:
    // 0x800DDD08: jr          $ra
    // 0x800DDD0C: nop

    return;
    // 0x800DDD0C: nop

;}
RECOMP_FUNC void alFxNew_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DDD10: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800DDD14: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x800DDD18: or          $s6, $a2, $zero
    ctx->r22 = ctx->r6 | 0;
    // 0x800DDD1C: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x800DDD20: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x800DDD24: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x800DDD28: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800DDD2C: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x800DDD30: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x800DDD34: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x800DDD38: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x800DDD3C: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x800DDD40: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x800DDD44: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x800DDD48: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x800DDD4C: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x800DDD50: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x800DDD54: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x800DDD58: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x800DDD5C: addiu       $a2, $a2, 0x2B44
    ctx->r6 = ADD32(ctx->r6, 0X2B44);
    // 0x800DDD60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800DDD64: jal         0x800E2230
    // 0x800DDD68: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    alFilterNew_recomp(rdram, ctx);
        goto after_0;
    // 0x800DDD68: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_0:
    // 0x800DDD6C: lw          $v0, 0x6C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X6C);
    // 0x800DDD70: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800DDD74: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800DDD78: addiu       $t6, $t6, 0x2B5C
    ctx->r14 = ADD32(ctx->r14, 0X2B5C);
    // 0x800DDD7C: addiu       $t7, $t7, 0x28E8
    ctx->r15 = ADD32(ctx->r15, 0X28E8);
    // 0x800DDD80: sw          $t6, 0x4($s5)
    MEM_W(0X4, ctx->r21) = ctx->r14;
    // 0x800DDD84: sw          $t7, 0x28($s5)
    MEM_W(0X28, ctx->r21) = ctx->r15;
    // 0x800DDD88: lbu         $t8, 0x1C($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1C);
    // 0x800DDD8C: lui         $s3, 0x800F
    ctx->r19 = S32(0X800F << 16);
    // 0x800DDD90: addiu       $s3, $s3, -0x2F08
    ctx->r19 = ADD32(ctx->r19, -0X2F08);
    // 0x800DDD94: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800DDD98: sltiu       $at, $t9, 0x6
    ctx->r1 = ctx->r25 < 0X6 ? 1 : 0;
    // 0x800DDD9C: beq         $at, $zero, L_800DDDFC
    if (ctx->r1 == 0) {
        // 0x800DDDA0: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_800DDDFC;
    }
    // 0x800DDDA0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800DDDA4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800DDDA8: addu        $at, $at, $t9
    gpr jr_addend_800DDDB0 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800DDDAC: lw          $t9, -0x1DA0($at)
    ctx->r25 = ADD32(ctx->r1, -0X1DA0);
    // 0x800DDDB0: jr          $t9
    // 0x800DDDB4: nop

    switch (jr_addend_800DDDB0 >> 2) {
        case 0: goto L_800DDDB8; break;
        case 1: goto L_800DDDC4; break;
        case 2: goto L_800DDDDC; break;
        case 3: goto L_800DDDE8; break;
        case 4: goto L_800DDDD0; break;
        case 5: goto L_800DDDF4; break;
        default: switch_error(__func__, 0x800DDDB0, 0x800EE260);
    }
    // 0x800DDDB4: nop

L_800DDDB8:
    // 0x800DDDB8: lui         $s3, 0x800F
    ctx->r19 = S32(0X800F << 16);
    // 0x800DDDBC: b           L_800DDDFC
    // 0x800DDDC0: addiu       $s3, $s3, -0x3070
    ctx->r19 = ADD32(ctx->r19, -0X3070);
        goto L_800DDDFC;
    // 0x800DDDC0: addiu       $s3, $s3, -0x3070
    ctx->r19 = ADD32(ctx->r19, -0X3070);
L_800DDDC4:
    // 0x800DDDC4: lui         $s3, 0x800F
    ctx->r19 = S32(0X800F << 16);
    // 0x800DDDC8: b           L_800DDDFC
    // 0x800DDDCC: addiu       $s3, $s3, -0x3008
    ctx->r19 = ADD32(ctx->r19, -0X3008);
        goto L_800DDDFC;
    // 0x800DDDCC: addiu       $s3, $s3, -0x3008
    ctx->r19 = ADD32(ctx->r19, -0X3008);
L_800DDDD0:
    // 0x800DDDD0: lui         $s3, 0x800F
    ctx->r19 = S32(0X800F << 16);
    // 0x800DDDD4: b           L_800DDDFC
    // 0x800DDDD8: addiu       $s3, $s3, -0x2F80
    ctx->r19 = ADD32(ctx->r19, -0X2F80);
        goto L_800DDDFC;
    // 0x800DDDD8: addiu       $s3, $s3, -0x2F80
    ctx->r19 = ADD32(ctx->r19, -0X2F80);
L_800DDDDC:
    // 0x800DDDDC: lui         $s3, 0x800F
    ctx->r19 = S32(0X800F << 16);
    // 0x800DDDE0: b           L_800DDDFC
    // 0x800DDDE4: addiu       $s3, $s3, -0x2F58
    ctx->r19 = ADD32(ctx->r19, -0X2F58);
        goto L_800DDDFC;
    // 0x800DDDE4: addiu       $s3, $s3, -0x2F58
    ctx->r19 = ADD32(ctx->r19, -0X2F58);
L_800DDDE8:
    // 0x800DDDE8: lui         $s3, 0x800F
    ctx->r19 = S32(0X800F << 16);
    // 0x800DDDEC: b           L_800DDDFC
    // 0x800DDDF0: addiu       $s3, $s3, -0x2F30
    ctx->r19 = ADD32(ctx->r19, -0X2F30);
        goto L_800DDDFC;
    // 0x800DDDF0: addiu       $s3, $s3, -0x2F30
    ctx->r19 = ADD32(ctx->r19, -0X2F30);
L_800DDDF4:
    // 0x800DDDF4: b           L_800DDDFC
    // 0x800DDDF8: lw          $s3, 0x20($v0)
    ctx->r19 = MEM_W(ctx->r2, 0X20);
        goto L_800DDDFC;
    // 0x800DDDF8: lw          $s3, 0x20($v0)
    ctx->r19 = MEM_W(ctx->r2, 0X20);
L_800DDDFC:
    // 0x800DDDFC: lw          $t0, 0x0($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X0);
    // 0x800DDE00: addiu       $t2, $zero, 0x28
    ctx->r10 = ADD32(0, 0X28);
    // 0x800DDE04: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
    // 0x800DDE08: sb          $t0, 0x24($s5)
    MEM_B(0X24, ctx->r21) = ctx->r8;
    // 0x800DDE0C: lw          $t1, 0x4($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X4);
    // 0x800DDE10: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800DDE14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800DDE18: sw          $t1, 0x1C($s5)
    MEM_W(0X1C, ctx->r21) = ctx->r9;
    // 0x800DDE1C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800DDE20: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x800DDE24: jal         0x800D8AE0
    // 0x800DDE28: andi        $a3, $t0, 0xFF
    ctx->r7 = ctx->r8 & 0XFF;
    alHeapDBAlloc_recomp(rdram, ctx);
        goto after_1;
    // 0x800DDE28: andi        $a3, $t0, 0xFF
    ctx->r7 = ctx->r8 & 0XFF;
    after_1:
    // 0x800DDE2C: sw          $v0, 0x20($s5)
    MEM_W(0X20, ctx->r21) = ctx->r2;
    // 0x800DDE30: lw          $a3, 0x1C($s5)
    ctx->r7 = MEM_W(ctx->r21, 0X1C);
    // 0x800DDE34: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x800DDE38: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800DDE3C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800DDE40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800DDE44: jal         0x800D8AE0
    // 0x800DDE48: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    alHeapDBAlloc_recomp(rdram, ctx);
        goto after_2;
    // 0x800DDE48: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_2:
    // 0x800DDE4C: lw          $t4, 0x1C($s5)
    ctx->r12 = MEM_W(ctx->r21, 0X1C);
    // 0x800DDE50: sw          $v0, 0x14($s5)
    MEM_W(0X14, ctx->r21) = ctx->r2;
    // 0x800DDE54: sw          $v0, 0x18($s5)
    MEM_W(0X18, ctx->r21) = ctx->r2;
    // 0x800DDE58: beq         $t4, $zero, L_800DDE8C
    if (ctx->r12 == 0) {
        // 0x800DDE5C: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800DDE8C;
    }
    // 0x800DDE5C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800DDE60: lw          $t5, 0x14($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X14);
L_800DDE64:
    // 0x800DDE64: sll         $t6, $v1, 1
    ctx->r14 = S32(ctx->r3 << 1);
    // 0x800DDE68: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800DDE6C: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x800DDE70: sh          $zero, 0x0($t7)
    MEM_H(0X0, ctx->r15) = 0;
    // 0x800DDE74: lw          $t9, 0x1C($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X1C);
    // 0x800DDE78: andi        $t8, $v1, 0xFFFF
    ctx->r24 = ctx->r3 & 0XFFFF;
    // 0x800DDE7C: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x800DDE80: sltu        $at, $t8, $t9
    ctx->r1 = ctx->r24 < ctx->r25 ? 1 : 0;
    // 0x800DDE84: bnel        $at, $zero, L_800DDE64
    if (ctx->r1 != 0) {
        // 0x800DDE88: lw          $t5, 0x14($s5)
        ctx->r13 = MEM_W(ctx->r21, 0X14);
            goto L_800DDE64;
    }
    goto skip_0;
    // 0x800DDE88: lw          $t5, 0x14($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X14);
    skip_0:
L_800DDE8C:
    // 0x800DDE8C: lbu         $t0, 0x24($s5)
    ctx->r8 = MEM_BU(ctx->r21, 0X24);
    // 0x800DDE90: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800DDE94: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800DDE98: blez        $t0, L_800DE10C
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800DDE9C: addiu       $fp, $zero, 0x1
        ctx->r30 = ADD32(0, 0X1);
            goto L_800DE10C;
    }
    // 0x800DDE9C: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x800DDEA0: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x800DDEA4: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x800DDEA8: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x800DDEAC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800DDEB0: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x800DDEB4: ldc1        $f20, -0x1D88($at)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r1, -0X1D88);
    // 0x800DDEB8: addiu       $s7, $zero, 0x28
    ctx->r23 = ADD32(0, 0X28);
L_800DDEBC:
    // 0x800DDEBC: multu       $s4, $s7
    result = U64(U32(ctx->r20)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800DDEC0: sll         $t3, $s1, 2
    ctx->r11 = S32(ctx->r17 << 2);
    // 0x800DDEC4: lw          $t1, 0x20($s5)
    ctx->r9 = MEM_W(ctx->r21, 0X20);
    // 0x800DDEC8: addu        $t4, $s3, $t3
    ctx->r12 = ADD32(ctx->r19, ctx->r11);
    // 0x800DDECC: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x800DDED0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800DDED4: andi        $t6, $s1, 0xFFFF
    ctx->r14 = ctx->r17 & 0XFFFF;
    // 0x800DDED8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800DDEDC: addu        $t8, $s3, $t7
    ctx->r24 = ADD32(ctx->r19, ctx->r15);
    // 0x800DDEE0: addiu       $s1, $t6, 0x1
    ctx->r17 = ADD32(ctx->r14, 0X1);
    // 0x800DDEE4: mflo        $t2
    ctx->r10 = lo;
    // 0x800DDEE8: addu        $s0, $t1, $t2
    ctx->r16 = ADD32(ctx->r9, ctx->r10);
    // 0x800DDEEC: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x800DDEF0: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x800DDEF4: andi        $t0, $s1, 0xFFFF
    ctx->r8 = ctx->r17 & 0XFFFF;
    // 0x800DDEF8: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x800DDEFC: addu        $t2, $s3, $t1
    ctx->r10 = ADD32(ctx->r19, ctx->r9);
    // 0x800DDF00: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x800DDF04: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x800DDF08: addiu       $s1, $t0, 0x1
    ctx->r17 = ADD32(ctx->r8, 0X1);
    // 0x800DDF0C: andi        $t4, $s1, 0xFFFF
    ctx->r12 = ctx->r17 & 0XFFFF;
    // 0x800DDF10: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800DDF14: addu        $t6, $s3, $t5
    ctx->r14 = ADD32(ctx->r19, ctx->r13);
    // 0x800DDF18: sh          $t3, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r11;
    // 0x800DDF1C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800DDF20: addiu       $s1, $t4, 0x1
    ctx->r17 = ADD32(ctx->r12, 0X1);
    // 0x800DDF24: andi        $t8, $s1, 0xFFFF
    ctx->r24 = ctx->r17 & 0XFFFF;
    // 0x800DDF28: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800DDF2C: addu        $t0, $s3, $t9
    ctx->r8 = ADD32(ctx->r19, ctx->r25);
    // 0x800DDF30: sh          $t7, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r15;
    // 0x800DDF34: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x800DDF38: addiu       $s1, $t8, 0x1
    ctx->r17 = ADD32(ctx->r24, 0X1);
    // 0x800DDF3C: andi        $t2, $s1, 0xFFFF
    ctx->r10 = ctx->r17 & 0XFFFF;
    // 0x800DDF40: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800DDF44: addu        $t4, $s3, $t3
    ctx->r12 = ADD32(ctx->r19, ctx->r11);
    // 0x800DDF48: sh          $t1, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r9;
    // 0x800DDF4C: lw          $v0, 0x0($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X0);
    // 0x800DDF50: or          $s1, $t2, $zero
    ctx->r17 = ctx->r10 | 0;
    // 0x800DDF54: or          $t0, $s1, $zero
    ctx->r8 = ctx->r17 | 0;
    // 0x800DDF58: beq         $v0, $zero, L_800DE05C
    if (ctx->r2 == 0) {
        // 0x800DDF5C: addiu       $s1, $t0, 0x2
        ctx->r17 = ADD32(ctx->r8, 0X2);
            goto L_800DE05C;
    }
    // 0x800DDF5C: addiu       $s1, $t0, 0x2
    ctx->r17 = ADD32(ctx->r8, 0X2);
    // 0x800DDF60: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800DDF64: lw          $t5, 0x6C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X6C);
    // 0x800DDF68: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x800DDF6C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800DDF70: lw          $t6, 0x18($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X18);
    // 0x800DDF74: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x800DDF78: addiu       $s1, $t2, 0x1
    ctx->r17 = ADD32(ctx->r10, 0X1);
    // 0x800DDF7C: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x800DDF80: andi        $t7, $s1, 0xFFFF
    ctx->r15 = ctx->r17 & 0XFFFF;
    // 0x800DDF84: div.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f22.fl);
    // 0x800DDF88: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x800DDF8C: or          $s1, $t7, $zero
    ctx->r17 = ctx->r15 | 0;
    // 0x800DDF90: sll         $t1, $s1, 2
    ctx->r9 = S32(ctx->r17 << 2);
    // 0x800DDF94: cvt.d.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.d = CVT_D_W(ctx->f16.u32l);
    // 0x800DDF98: addu        $t2, $s3, $t1
    ctx->r10 = ADD32(ctx->r19, ctx->r9);
    // 0x800DDF9C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800DDFA0: cvt.d.s     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f0.d = CVT_D_S(ctx->f8.fl);
    // 0x800DDFA4: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x800DDFA8: add.d       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = ctx->f0.d + ctx->f0.d;
    // 0x800DDFAC: cvt.d.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.d = CVT_D_W(ctx->f8.u32l);
    // 0x800DDFB0: div.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = DIV_D(ctx->f10.d, ctx->f18.d);
    // 0x800DDFB4: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x800DDFB8: bgez        $t0, L_800DDFD0
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800DDFBC: swc1        $f6, 0x10($s0)
        MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
            goto L_800DDFD0;
    }
    // 0x800DDFBC: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
    // 0x800DDFC0: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800DDFC4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800DDFC8: nop

    // 0x800DDFCC: add.d       $f16, $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f16.d + ctx->f10.d;
L_800DDFD0:
    // 0x800DDFD0: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x800DDFD4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800DDFD8: andi        $t4, $s1, 0xFFFF
    ctx->r12 = ctx->r17 & 0XFFFF;
    // 0x800DDFDC: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x800DDFE0: swc1        $f24, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f24.u32l;
    // 0x800DDFE4: sw          $zero, 0x18($s0)
    MEM_W(0X18, ctx->r16) = 0;
    // 0x800DDFE8: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800DDFEC: addiu       $t5, $zero, 0x34
    ctx->r13 = ADD32(0, 0X34);
    // 0x800DDFF0: or          $s1, $t4, $zero
    ctx->r17 = ctx->r12 | 0;
    // 0x800DDFF4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800DDFF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800DDFFC: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x800DE000: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800DE004: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    // 0x800DE008: div.d       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f20.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f20.d);
    // 0x800DE00C: mul.d       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x800DE010: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x800DE014: swc1        $f18, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f18.u32l;
    // 0x800DE018: jal         0x800D8AE0
    // 0x800DE01C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    alHeapDBAlloc_recomp(rdram, ctx);
        goto after_3;
    // 0x800DE01C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_3:
    // 0x800DE020: sw          $v0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r2;
    // 0x800DE024: addiu       $t6, $zero, 0x20
    ctx->r14 = ADD32(0, 0X20);
    // 0x800DE028: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800DE02C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800DE030: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800DE034: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x800DE038: jal         0x800D8AE0
    // 0x800DE03C: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    alHeapDBAlloc_recomp(rdram, ctx);
        goto after_4;
    // 0x800DE03C: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    after_4:
    // 0x800DE040: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    // 0x800DE044: sw          $v0, 0x14($t7)
    MEM_W(0X14, ctx->r15) = ctx->r2;
    // 0x800DE048: lw          $t8, 0x24($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X24);
    // 0x800DE04C: swc1        $f26, 0x20($t8)
    MEM_W(0X20, ctx->r24) = ctx->f26.u32l;
    // 0x800DE050: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x800DE054: b           L_800DE068
    // 0x800DE058: sw          $fp, 0x24($t9)
    MEM_W(0X24, ctx->r25) = ctx->r30;
        goto L_800DE068;
    // 0x800DE058: sw          $fp, 0x24($t9)
    MEM_W(0X24, ctx->r25) = ctx->r30;
L_800DE05C:
    // 0x800DE05C: andi        $t1, $s1, 0xFFFF
    ctx->r9 = ctx->r17 & 0XFFFF;
    // 0x800DE060: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
    // 0x800DE064: or          $s1, $t1, $zero
    ctx->r17 = ctx->r9 | 0;
L_800DE068:
    // 0x800DE068: sll         $t2, $s1, 2
    ctx->r10 = S32(ctx->r17 << 2);
    // 0x800DE06C: addu        $s2, $s3, $t2
    ctx->r18 = ADD32(ctx->r19, ctx->r10);
    // 0x800DE070: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x800DE074: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800DE078: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800DE07C: beq         $t3, $zero, L_800DE0E4
    if (ctx->r11 == 0) {
        // 0x800DE080: or          $a2, $s6, $zero
        ctx->r6 = ctx->r22 | 0;
            goto L_800DE0E4;
    }
    // 0x800DE080: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x800DE084: addiu       $t4, $zero, 0x30
    ctx->r12 = ADD32(0, 0X30);
    // 0x800DE088: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800DE08C: jal         0x800D8AE0
    // 0x800DE090: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    alHeapDBAlloc_recomp(rdram, ctx);
        goto after_5;
    // 0x800DE090: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    after_5:
    // 0x800DE094: sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
    // 0x800DE098: addiu       $t5, $zero, 0x8
    ctx->r13 = ADD32(0, 0X8);
    // 0x800DE09C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800DE0A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800DE0A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800DE0A8: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x800DE0AC: jal         0x800D8AE0
    // 0x800DE0B0: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    alHeapDBAlloc_recomp(rdram, ctx);
        goto after_6;
    // 0x800DE0B0: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    after_6:
    // 0x800DE0B4: lw          $t6, 0x20($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X20);
    // 0x800DE0B8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800DE0BC: andi        $t9, $s1, 0xFFFF
    ctx->r25 = ctx->r17 & 0XFFFF;
    // 0x800DE0C0: sw          $v0, 0x28($t6)
    MEM_W(0X28, ctx->r14) = ctx->r2;
    // 0x800DE0C4: lw          $t8, 0x20($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X20);
    // 0x800DE0C8: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x800DE0CC: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x800DE0D0: sh          $t7, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r15;
    // 0x800DE0D4: jal         0x800DDC70
    // 0x800DE0D8: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    init_lpfilter_recomp(rdram, ctx);
        goto after_7;
    // 0x800DE0D8: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    after_7:
    // 0x800DE0DC: b           L_800DE0F8
    // 0x800DE0E0: lbu         $t2, 0x24($s5)
    ctx->r10 = MEM_BU(ctx->r21, 0X24);
        goto L_800DE0F8;
    // 0x800DE0E0: lbu         $t2, 0x24($s5)
    ctx->r10 = MEM_BU(ctx->r21, 0X24);
L_800DE0E4:
    // 0x800DE0E4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800DE0E8: andi        $t0, $s1, 0xFFFF
    ctx->r8 = ctx->r17 & 0XFFFF;
    // 0x800DE0EC: sw          $zero, 0x20($s0)
    MEM_W(0X20, ctx->r16) = 0;
    // 0x800DE0F0: or          $s1, $t0, $zero
    ctx->r17 = ctx->r8 | 0;
    // 0x800DE0F4: lbu         $t2, 0x24($s5)
    ctx->r10 = MEM_BU(ctx->r21, 0X24);
L_800DE0F8:
    // 0x800DE0F8: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800DE0FC: andi        $t1, $s4, 0xFFFF
    ctx->r9 = ctx->r20 & 0XFFFF;
    // 0x800DE100: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800DE104: bne         $at, $zero, L_800DDEBC
    if (ctx->r1 != 0) {
        // 0x800DE108: or          $s4, $t1, $zero
        ctx->r20 = ctx->r9 | 0;
            goto L_800DDEBC;
    }
    // 0x800DE108: or          $s4, $t1, $zero
    ctx->r20 = ctx->r9 | 0;
L_800DE10C:
    // 0x800DE10C: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x800DE110: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x800DE114: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x800DE118: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x800DE11C: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x800DE120: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x800DE124: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x800DE128: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x800DE12C: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x800DE130: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x800DE134: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x800DE138: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x800DE13C: lw          $s7, 0x5C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X5C);
    // 0x800DE140: lw          $fp, 0x60($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X60);
    // 0x800DE144: jr          $ra
    // 0x800DE148: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x800DE148: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x800DE14C: nop

;}
RECOMP_FUNC void alSynAllocFX_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DE150: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800DE154: sll         $t0, $a1, 16
    ctx->r8 = S32(ctx->r5 << 16);
    // 0x800DE158: sra         $t6, $t0, 16
    ctx->r14 = S32(SIGNED(ctx->r8) >> 16);
    // 0x800DE15C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800DE160: sll         $s1, $t6, 2
    ctx->r17 = S32(ctx->r14 << 2);
    // 0x800DE164: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800DE168: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800DE16C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800DE170: addu        $s1, $s1, $t6
    ctx->r17 = ADD32(ctx->r17, ctx->r14);
    // 0x800DE174: lw          $t7, 0x34($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X34);
    // 0x800DE178: sll         $s1, $s1, 2
    ctx->r17 = S32(ctx->r17 << 2);
    // 0x800DE17C: subu        $s1, $s1, $t6
    ctx->r17 = SUB32(ctx->r17, ctx->r14);
    // 0x800DE180: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800DE184: sll         $s1, $s1, 2
    ctx->r17 = S32(ctx->r17 << 2);
    // 0x800DE188: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x800DE18C: addu        $a0, $t7, $s1
    ctx->r4 = ADD32(ctx->r15, ctx->r17);
    // 0x800DE190: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x800DE194: jal         0x800DDD10
    // 0x800DE198: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    alFxNew_recomp(rdram, ctx);
        goto after_0;
    // 0x800DE198: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    after_0:
    // 0x800DE19C: lw          $t8, 0x34($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X34);
    // 0x800DE1A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800DE1A4: addu        $a2, $t8, $s1
    ctx->r6 = ADD32(ctx->r24, ctx->r17);
    // 0x800DE1A8: jal         0x800E2B44
    // 0x800DE1AC: addiu       $a0, $a2, 0x20
    ctx->r4 = ADD32(ctx->r6, 0X20);
    alFxParam_recomp(rdram, ctx);
        goto after_1;
    // 0x800DE1AC: addiu       $a0, $a2, 0x20
    ctx->r4 = ADD32(ctx->r6, 0X20);
    after_1:
    // 0x800DE1B0: lw          $t9, 0x34($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X34);
    // 0x800DE1B4: lw          $a0, 0x30($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X30);
    // 0x800DE1B8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800DE1BC: addu        $a2, $t9, $s1
    ctx->r6 = ADD32(ctx->r25, ctx->r17);
    // 0x800DE1C0: jal         0x800DE1F0
    // 0x800DE1C4: addiu       $a2, $a2, 0x20
    ctx->r6 = ADD32(ctx->r6, 0X20);
    alAuxBusParam_recomp(rdram, ctx);
        goto after_2;
    // 0x800DE1C4: addiu       $a2, $a2, 0x20
    ctx->r6 = ADD32(ctx->r6, 0X20);
    after_2:
    // 0x800DE1C8: lw          $t2, 0x34($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X34);
    // 0x800DE1CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800DE1D0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800DE1D4: addu        $v0, $t2, $s1
    ctx->r2 = ADD32(ctx->r10, ctx->r17);
    // 0x800DE1D8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800DE1DC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800DE1E0: jr          $ra
    // 0x800DE1E4: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    return;
    // 0x800DE1E4: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x800DE1E8: nop

    // 0x800DE1EC: nop

;}
RECOMP_FUNC void alAuxBusParam_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DE1F0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800DE1F4: bne         $a1, $at, L_800DE218
    if (ctx->r5 != ctx->r1) {
        // 0x800DE1F8: lw          $v0, 0x1C($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X1C);
            goto L_800DE218;
    }
    // 0x800DE1F8: lw          $v0, 0x1C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1C);
    // 0x800DE1FC: lw          $t6, 0x14($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X14);
    // 0x800DE200: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800DE204: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x800DE208: sw          $a2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r6;
    // 0x800DE20C: lw          $t9, 0x14($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X14);
    // 0x800DE210: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800DE214: sw          $t0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r8;
L_800DE218:
    // 0x800DE218: jr          $ra
    // 0x800DE21C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800DE21C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void alMainBusPull_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DE220: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800DE224: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x800DE228: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800DE22C: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x800DE230: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x800DE234: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800DE238: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800DE23C: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800DE240: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800DE244: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800DE248: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800DE24C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800DE250: lw          $v1, 0x1C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1C);
    // 0x800DE254: lui         $t6, 0x200
    ctx->r14 = S32(0X200 << 16);
    // 0x800DE258: sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6 << 1);
    // 0x800DE25C: lui         $t7, 0x200
    ctx->r15 = S32(0X200 << 16);
    // 0x800DE260: ori         $t6, $t6, 0x440
    ctx->r14 = ctx->r14 | 0X440;
    // 0x800DE264: ori         $t7, $t7, 0x580
    ctx->r15 = ctx->r15 | 0X580;
    // 0x800DE268: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x800DE26C: sw          $v0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r2;
    // 0x800DE270: sw          $t7, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r15;
    // 0x800DE274: sw          $v0, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r2;
    // 0x800DE278: lw          $t8, 0x14($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X14);
    // 0x800DE27C: or          $s5, $a2, $zero
    ctx->r21 = ctx->r6 | 0;
    // 0x800DE280: or          $s7, $a1, $zero
    ctx->r23 = ctx->r5 | 0;
    // 0x800DE284: or          $fp, $a3, $zero
    ctx->r30 = ctx->r7 | 0;
    // 0x800DE288: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x800DE28C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800DE290: blez        $t8, L_800DE30C
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800DE294: addiu       $s3, $t0, 0x10
        ctx->r19 = ADD32(ctx->r8, 0X10);
            goto L_800DE30C;
    }
    // 0x800DE294: addiu       $s3, $t0, 0x10
    ctx->r19 = ADD32(ctx->r8, 0X10);
    // 0x800DE298: lui         $s2, 0xC00
    ctx->r18 = S32(0XC00 << 16);
    // 0x800DE29C: ori         $s2, $s2, 0x7FFF
    ctx->r18 = ctx->r18 | 0X7FFF;
    // 0x800DE2A0: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
    // 0x800DE2A4: andi        $s6, $v0, 0xFFFF
    ctx->r22 = ctx->r2 & 0XFFFF;
L_800DE2A8:
    // 0x800DE2A8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800DE2AC: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x800DE2B0: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x800DE2B4: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x800DE2B8: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x800DE2BC: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    // 0x800DE2C0: jalr        $t9
    // 0x800DE2C4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800DE2C4: nop

    after_0:
    // 0x800DE2C8: lui         $t2, 0x6C0
    ctx->r10 = S32(0X6C0 << 16);
    // 0x800DE2CC: lui         $t3, 0x800
    ctx->r11 = S32(0X800 << 16);
    // 0x800DE2D0: lui         $t1, 0x800
    ctx->r9 = S32(0X800 << 16);
    // 0x800DE2D4: ori         $t2, $t2, 0x440
    ctx->r10 = ctx->r10 | 0X440;
    // 0x800DE2D8: ori         $t3, $t3, 0x580
    ctx->r11 = ctx->r11 | 0X580;
    // 0x800DE2DC: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x800DE2E0: sw          $s6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r22;
    // 0x800DE2E4: sw          $t2, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r10;
    // 0x800DE2E8: sw          $s2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r18;
    // 0x800DE2EC: sw          $t3, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r11;
    // 0x800DE2F0: sw          $s2, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r18;
    // 0x800DE2F4: lw          $t4, 0x14($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X14);
    // 0x800DE2F8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800DE2FC: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800DE300: slt         $at, $s0, $t4
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800DE304: bne         $at, $zero, L_800DE2A8
    if (ctx->r1 != 0) {
        // 0x800DE308: addiu       $s3, $v0, 0x18
        ctx->r19 = ADD32(ctx->r2, 0X18);
            goto L_800DE2A8;
    }
    // 0x800DE308: addiu       $s3, $v0, 0x18
    ctx->r19 = ADD32(ctx->r2, 0X18);
L_800DE30C:
    // 0x800DE30C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800DE310: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x800DE314: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800DE318: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800DE31C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800DE320: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800DE324: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800DE328: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800DE32C: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800DE330: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x800DE334: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x800DE338: jr          $ra
    // 0x800DE33C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800DE33C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void alLoadParam_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DE340: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DE344: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800DE348: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DE34C: beq         $a1, $at, L_800DE4A4
    if (ctx->r5 == ctx->r1) {
        // 0x800DE350: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_800DE4A4;
    }
    // 0x800DE350: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800DE354: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800DE358: bnel        $a1, $at, L_800DE508
    if (ctx->r5 != ctx->r1) {
        // 0x800DE35C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800DE508;
    }
    goto skip_0;
    // 0x800DE35C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800DE360: sw          $a2, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r6;
    // 0x800DE364: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800DE368: sw          $zero, 0x38($a0)
    MEM_W(0X38, ctx->r4) = 0;
    // 0x800DE36C: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800DE370: sw          $t6, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->r14;
    // 0x800DE374: lbu         $v0, 0x8($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X8);
    // 0x800DE378: beql        $v0, $zero, L_800DE398
    if (ctx->r2 == 0) {
        // 0x800DE37C: lw          $v0, 0x28($a3)
        ctx->r2 = MEM_W(ctx->r7, 0X28);
            goto L_800DE398;
    }
    goto skip_1;
    // 0x800DE37C: lw          $v0, 0x28($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X28);
    skip_1:
    // 0x800DE380: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800DE384: beq         $v0, $a0, L_800DE458
    if (ctx->r2 == ctx->r4) {
        // 0x800DE388: lui         $t0, 0x800E
        ctx->r8 = S32(0X800E << 16);
            goto L_800DE458;
    }
    // 0x800DE388: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800DE38C: b           L_800DE508
    // 0x800DE390: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800DE508;
    // 0x800DE390: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DE394: lw          $v0, 0x28($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X28);
L_800DE398:
    // 0x800DE398: addiu       $t7, $t7, -0x1614
    ctx->r15 = ADD32(ctx->r15, -0X1614);
    // 0x800DE39C: sw          $t7, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r15;
    // 0x800DE3A0: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x800DE3A4: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x800DE3A8: div         $zero, $t8, $a1
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r5)));
    // 0x800DE3AC: mflo        $t9
    ctx->r25 = lo;
    // 0x800DE3B0: bne         $a1, $zero, L_800DE3BC
    if (ctx->r5 != 0) {
        // 0x800DE3B4: nop
    
            goto L_800DE3BC;
    }
    // 0x800DE3B4: nop

    // 0x800DE3B8: break       7
    do_break(2148393912);
L_800DE3BC:
    // 0x800DE3BC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800DE3C0: bne         $a1, $at, L_800DE3D4
    if (ctx->r5 != ctx->r1) {
        // 0x800DE3C4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800DE3D4;
    }
    // 0x800DE3C4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800DE3C8: bne         $t8, $at, L_800DE3D4
    if (ctx->r24 != ctx->r1) {
        // 0x800DE3CC: nop
    
            goto L_800DE3D4;
    }
    // 0x800DE3CC: nop

    // 0x800DE3D0: break       6
    do_break(2148393936);
L_800DE3D4:
    // 0x800DE3D4: multu       $t9, $a1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800DE3D8: mflo        $t0
    ctx->r8 = lo;
    // 0x800DE3DC: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x800DE3E0: lw          $v0, 0x28($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X28);
    // 0x800DE3E4: lw          $a0, 0x10($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X10);
    // 0x800DE3E8: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x800DE3EC: lw          $t3, 0x4($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X4);
    // 0x800DE3F0: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x800DE3F4: multu       $t2, $t3
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800DE3F8: mflo        $t4
    ctx->r12 = lo;
    // 0x800DE3FC: sw          $t4, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = ctx->r12;
    // 0x800DE400: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x800DE404: beql        $v1, $zero, L_800DE44C
    if (ctx->r3 == 0) {
        // 0x800DE408: sw          $zero, 0x24($a3)
        MEM_W(0X24, ctx->r7) = 0;
            goto L_800DE44C;
    }
    goto skip_2;
    // 0x800DE408: sw          $zero, 0x24($a3)
    MEM_W(0X24, ctx->r7) = 0;
    skip_2:
    // 0x800DE40C: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800DE410: lw          $a1, 0x18($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X18);
    // 0x800DE414: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x800DE418: sw          $t5, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r13;
    // 0x800DE41C: lw          $t6, 0xC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XC);
    // 0x800DE420: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x800DE424: sw          $t7, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->r15;
    // 0x800DE428: lw          $t8, 0xC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XC);
    // 0x800DE42C: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x800DE430: sw          $t9, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r25;
    // 0x800DE434: lw          $a0, 0xC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XC);
    // 0x800DE438: jal         0x800E2EA0
    // 0x800DE43C: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    alCopy_recomp(rdram, ctx);
        goto after_0;
    // 0x800DE43C: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_0:
    // 0x800DE440: b           L_800DE508
    // 0x800DE444: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800DE508;
    // 0x800DE444: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DE448: sw          $zero, 0x24($a3)
    MEM_W(0X24, ctx->r7) = 0;
L_800DE44C:
    // 0x800DE44C: sw          $zero, 0x20($a3)
    MEM_W(0X20, ctx->r7) = 0;
    // 0x800DE450: b           L_800DE504
    // 0x800DE454: sw          $zero, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = 0;
        goto L_800DE504;
    // 0x800DE454: sw          $zero, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = 0;
L_800DE458:
    // 0x800DE458: lw          $v0, 0x28($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X28);
    // 0x800DE45C: addiu       $t0, $t0, -0x1AEC
    ctx->r8 = ADD32(ctx->r8, -0X1AEC);
    // 0x800DE460: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    // 0x800DE464: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x800DE468: beql        $v1, $zero, L_800DE498
    if (ctx->r3 == 0) {
        // 0x800DE46C: sw          $zero, 0x24($a3)
        MEM_W(0X24, ctx->r7) = 0;
            goto L_800DE498;
    }
    goto skip_3;
    // 0x800DE46C: sw          $zero, 0x24($a3)
    MEM_W(0X24, ctx->r7) = 0;
    skip_3:
    // 0x800DE470: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x800DE474: sw          $t1, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r9;
    // 0x800DE478: lw          $t2, 0xC($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XC);
    // 0x800DE47C: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x800DE480: sw          $t3, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->r11;
    // 0x800DE484: lw          $t4, 0xC($v0)
    ctx->r12 = MEM_W(ctx->r2, 0XC);
    // 0x800DE488: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x800DE48C: b           L_800DE504
    // 0x800DE490: sw          $t5, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r13;
        goto L_800DE504;
    // 0x800DE490: sw          $t5, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r13;
    // 0x800DE494: sw          $zero, 0x24($a3)
    MEM_W(0X24, ctx->r7) = 0;
L_800DE498:
    // 0x800DE498: sw          $zero, 0x20($a3)
    MEM_W(0X20, ctx->r7) = 0;
    // 0x800DE49C: b           L_800DE504
    // 0x800DE4A0: sw          $zero, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = 0;
        goto L_800DE504;
    // 0x800DE4A0: sw          $zero, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = 0;
L_800DE4A4:
    // 0x800DE4A4: lw          $v0, 0x28($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X28);
    // 0x800DE4A8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800DE4AC: sw          $zero, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = 0;
    // 0x800DE4B0: sw          $a0, 0x40($a3)
    MEM_W(0X40, ctx->r7) = ctx->r4;
    // 0x800DE4B4: beq         $v0, $zero, L_800DE504
    if (ctx->r2 == 0) {
        // 0x800DE4B8: sw          $zero, 0x38($a3)
        MEM_W(0X38, ctx->r7) = 0;
            goto L_800DE504;
    }
    // 0x800DE4B8: sw          $zero, 0x38($a3)
    MEM_W(0X38, ctx->r7) = 0;
    // 0x800DE4BC: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800DE4C0: sw          $t6, 0x44($a3)
    MEM_W(0X44, ctx->r7) = ctx->r14;
    // 0x800DE4C4: lbu         $v1, 0x8($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X8);
    // 0x800DE4C8: bne         $v1, $zero, L_800DE4E8
    if (ctx->r3 != 0) {
        // 0x800DE4CC: nop
    
            goto L_800DE4E8;
    }
    // 0x800DE4CC: nop

    // 0x800DE4D0: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x800DE4D4: beql        $v1, $zero, L_800DE508
    if (ctx->r3 == 0) {
        // 0x800DE4D8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800DE508;
    }
    goto skip_4;
    // 0x800DE4D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x800DE4DC: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    // 0x800DE4E0: b           L_800DE504
    // 0x800DE4E4: sw          $t7, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r15;
        goto L_800DE504;
    // 0x800DE4E4: sw          $t7, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r15;
L_800DE4E8:
    // 0x800DE4E8: bnel        $a0, $v1, L_800DE508
    if (ctx->r4 != ctx->r3) {
        // 0x800DE4EC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800DE508;
    }
    goto skip_5;
    // 0x800DE4EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_5:
    // 0x800DE4F0: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x800DE4F4: beql        $v1, $zero, L_800DE508
    if (ctx->r3 == 0) {
        // 0x800DE4F8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800DE508;
    }
    goto skip_6;
    // 0x800DE4F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_6:
    // 0x800DE4FC: lw          $t8, 0x8($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X8);
    // 0x800DE500: sw          $t8, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r24;
L_800DE504:
    // 0x800DE504: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800DE508:
    // 0x800DE508: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DE50C: jr          $ra
    // 0x800DE510: nop

    return;
    // 0x800DE510: nop

;}
RECOMP_FUNC void alRaw16Pull_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DE514: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800DE518: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x800DE51C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800DE520: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800DE524: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800DE528: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x800DE52C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800DE530: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800DE534: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800DE538: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x800DE53C: or          $t2, $a1, $zero
    ctx->r10 = ctx->r5 | 0;
    // 0x800DE540: bne         $a2, $zero, L_800DE550
    if (ctx->r6 != 0) {
        // 0x800DE544: or          $t1, $t0, $zero
        ctx->r9 = ctx->r8 | 0;
            goto L_800DE550;
    }
    // 0x800DE544: or          $t1, $t0, $zero
    ctx->r9 = ctx->r8 | 0;
    // 0x800DE548: b           L_800DE8A4
    // 0x800DE54C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
        goto L_800DE8A4;
    // 0x800DE54C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_800DE550:
    // 0x800DE550: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
    // 0x800DE554: lw          $v1, 0x20($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X20);
    // 0x800DE558: addu        $t6, $v0, $s3
    ctx->r14 = ADD32(ctx->r2, ctx->r19);
    // 0x800DE55C: sltu        $at, $v1, $t6
    ctx->r1 = ctx->r3 < ctx->r14 ? 1 : 0;
    // 0x800DE560: beql        $at, $zero, L_800DE774
    if (ctx->r1 == 0) {
        // 0x800DE564: lw          $v0, 0x28($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X28);
            goto L_800DE774;
    }
    goto skip_0;
    // 0x800DE564: lw          $v0, 0x28($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X28);
    skip_0:
    // 0x800DE568: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    // 0x800DE56C: subu        $s2, $v1, $v0
    ctx->r18 = SUB32(ctx->r3, ctx->r2);
    // 0x800DE570: beql        $t7, $zero, L_800DE774
    if (ctx->r15 == 0) {
        // 0x800DE574: lw          $v0, 0x28($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X28);
            goto L_800DE774;
    }
    goto skip_1;
    // 0x800DE574: lw          $v0, 0x28($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X28);
    skip_1:
    // 0x800DE578: blez        $s2, L_800DE5F4
    if (SIGNED(ctx->r18) <= 0) {
        // 0x800DE57C: sll         $s1, $s2, 1
        ctx->r17 = S32(ctx->r18 << 1);
            goto L_800DE5F4;
    }
    // 0x800DE57C: sll         $s1, $s2, 1
    ctx->r17 = S32(ctx->r18 << 1);
    // 0x800DE580: lw          $a0, 0x44($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X44);
    // 0x800DE584: lw          $a2, 0x34($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X34);
    // 0x800DE588: sw          $t2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r10;
    // 0x800DE58C: lw          $t9, 0x30($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X30);
    // 0x800DE590: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800DE594: jalr        $t9
    // 0x800DE598: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800DE598: nop

    after_0:
    // 0x800DE59C: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x800DE5A0: andi        $a2, $v0, 0x7
    ctx->r6 = ctx->r2 & 0X7;
    // 0x800DE5A4: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x800DE5A8: lh          $t8, 0x0($t2)
    ctx->r24 = MEM_H(ctx->r10, 0X0);
    // 0x800DE5AC: addu        $a3, $s1, $a2
    ctx->r7 = ADD32(ctx->r17, ctx->r6);
    // 0x800DE5B0: andi        $t5, $a3, 0x7
    ctx->r13 = ctx->r7 & 0X7;
    // 0x800DE5B4: subu        $t6, $a3, $t5
    ctx->r14 = SUB32(ctx->r7, ctx->r13);
    // 0x800DE5B8: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x800DE5BC: andi        $t3, $t8, 0xFFFF
    ctx->r11 = ctx->r24 & 0XFFFF;
    // 0x800DE5C0: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x800DE5C4: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800DE5C8: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x800DE5CC: andi        $t9, $t7, 0xFFFF
    ctx->r25 = ctx->r15 & 0XFFFF;
    // 0x800DE5D0: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x800DE5D4: subu        $t3, $v0, $a2
    ctx->r11 = SUB32(ctx->r2, ctx->r6);
    // 0x800DE5D8: lui         $t8, 0x400
    ctx->r24 = S32(0X400 << 16);
    // 0x800DE5DC: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x800DE5E0: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x800DE5E4: sw          $t3, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r11;
    // 0x800DE5E8: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800DE5EC: b           L_800DE5F8
    // 0x800DE5F0: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
        goto L_800DE5F8;
    // 0x800DE5F0: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
L_800DE5F4:
    // 0x800DE5F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_800DE5F8:
    // 0x800DE5F8: lh          $t4, 0x0($t2)
    ctx->r12 = MEM_H(ctx->r10, 0X0);
    // 0x800DE5FC: slt         $at, $s2, $s3
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800DE600: addu        $t5, $t4, $a2
    ctx->r13 = ADD32(ctx->r12, ctx->r6);
    // 0x800DE604: sh          $t5, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r13;
    // 0x800DE608: lw          $t6, 0x28($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X28);
    // 0x800DE60C: lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C);
    // 0x800DE610: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800DE614: sll         $t9, $v0, 1
    ctx->r25 = S32(ctx->r2 << 1);
    // 0x800DE618: sw          $v0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r2;
    // 0x800DE61C: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x800DE620: sw          $t8, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r24;
    // 0x800DE624: beq         $at, $zero, L_800DE74C
    if (ctx->r1 == 0) {
        // 0x800DE628: lh          $t0, 0x0($t2)
        ctx->r8 = MEM_H(ctx->r10, 0X0);
            goto L_800DE74C;
    }
    // 0x800DE628: lh          $t0, 0x0($t2)
    ctx->r8 = MEM_H(ctx->r10, 0X0);
    // 0x800DE62C: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
L_800DE630:
    // 0x800DE630: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800DE634: addu        $t0, $t0, $s1
    ctx->r8 = ADD32(ctx->r8, ctx->r17);
    // 0x800DE638: beq         $v0, $at, L_800DE64C
    if (ctx->r2 == ctx->r1) {
        // 0x800DE63C: subu        $s3, $s3, $s2
        ctx->r19 = SUB32(ctx->r19, ctx->r18);
            goto L_800DE64C;
    }
    // 0x800DE63C: subu        $s3, $s3, $s2
    ctx->r19 = SUB32(ctx->r19, ctx->r18);
    // 0x800DE640: beq         $v0, $zero, L_800DE64C
    if (ctx->r2 == 0) {
        // 0x800DE644: addiu       $t3, $v0, -0x1
        ctx->r11 = ADD32(ctx->r2, -0X1);
            goto L_800DE64C;
    }
    // 0x800DE644: addiu       $t3, $v0, -0x1
    ctx->r11 = ADD32(ctx->r2, -0X1);
    // 0x800DE648: sw          $t3, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r11;
L_800DE64C:
    // 0x800DE64C: lw          $t4, 0x20($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X20);
    // 0x800DE650: lw          $t5, 0x1C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X1C);
    // 0x800DE654: subu        $v0, $t4, $t5
    ctx->r2 = SUB32(ctx->r12, ctx->r13);
    // 0x800DE658: sltu        $at, $s3, $v0
    ctx->r1 = ctx->r19 < ctx->r2 ? 1 : 0;
    // 0x800DE65C: beq         $at, $zero, L_800DE66C
    if (ctx->r1 == 0) {
        // 0x800DE660: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_800DE66C;
    }
    // 0x800DE660: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x800DE664: b           L_800DE66C
    // 0x800DE668: or          $s2, $s3, $zero
    ctx->r18 = ctx->r19 | 0;
        goto L_800DE66C;
    // 0x800DE668: or          $s2, $s3, $zero
    ctx->r18 = ctx->r19 | 0;
L_800DE66C:
    // 0x800DE66C: lw          $a0, 0x44($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X44);
    // 0x800DE670: lw          $a2, 0x34($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X34);
    // 0x800DE674: sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
    // 0x800DE678: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x800DE67C: lw          $t9, 0x30($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X30);
    // 0x800DE680: sll         $s1, $s2, 1
    ctx->r17 = S32(ctx->r18 << 1);
    // 0x800DE684: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800DE688: jalr        $t9
    // 0x800DE68C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800DE68C: nop

    after_1:
    // 0x800DE690: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800DE694: andi        $a1, $v0, 0x7
    ctx->r5 = ctx->r2 & 0X7;
    // 0x800DE698: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x800DE69C: andi        $v1, $t0, 0x7
    ctx->r3 = ctx->r8 & 0X7;
    // 0x800DE6A0: beq         $v1, $zero, L_800DE6B4
    if (ctx->r3 == 0) {
        // 0x800DE6A4: addu        $a3, $s1, $a1
        ctx->r7 = ADD32(ctx->r17, ctx->r5);
            goto L_800DE6B4;
    }
    // 0x800DE6A4: addu        $a3, $s1, $a1
    ctx->r7 = ADD32(ctx->r17, ctx->r5);
    // 0x800DE6A8: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x800DE6AC: b           L_800DE6B8
    // 0x800DE6B0: subu        $a2, $t6, $v1
    ctx->r6 = SUB32(ctx->r14, ctx->r3);
        goto L_800DE6B8;
    // 0x800DE6B0: subu        $a2, $t6, $v1
    ctx->r6 = SUB32(ctx->r14, ctx->r3);
L_800DE6B4:
    // 0x800DE6B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_800DE6B8:
    // 0x800DE6B8: addu        $t7, $t0, $a2
    ctx->r15 = ADD32(ctx->r8, ctx->r6);
    // 0x800DE6BC: andi        $t4, $a3, 0x7
    ctx->r12 = ctx->r7 & 0X7;
    // 0x800DE6C0: subu        $t5, $a3, $t4
    ctx->r13 = SUB32(ctx->r7, ctx->r12);
    // 0x800DE6C4: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x800DE6C8: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x800DE6CC: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x800DE6D0: or          $t3, $t8, $at
    ctx->r11 = ctx->r24 | ctx->r1;
    // 0x800DE6D4: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800DE6D8: addiu       $t9, $t5, 0x8
    ctx->r25 = ADD32(ctx->r13, 0X8);
    // 0x800DE6DC: andi        $t6, $t9, 0xFFFF
    ctx->r14 = ctx->r25 & 0XFFFF;
    // 0x800DE6E0: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x800DE6E4: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x800DE6E8: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x800DE6EC: subu        $t8, $v0, $a1
    ctx->r24 = SUB32(ctx->r2, ctx->r5);
    // 0x800DE6F0: lui         $t7, 0x400
    ctx->r15 = S32(0X400 << 16);
    // 0x800DE6F4: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800DE6F8: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x800DE6FC: bne         $a1, $zero, L_800DE708
    if (ctx->r5 != 0) {
        // 0x800DE700: addiu       $t1, $t1, 0x8
        ctx->r9 = ADD32(ctx->r9, 0X8);
            goto L_800DE708;
    }
    // 0x800DE700: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800DE704: beq         $a2, $zero, L_800DE740
    if (ctx->r6 == 0) {
        // 0x800DE708: addu        $t3, $t0, $a1
        ctx->r11 = ADD32(ctx->r8, ctx->r5);
            goto L_800DE740;
    }
L_800DE708:
    // 0x800DE708: addu        $t3, $t0, $a1
    ctx->r11 = ADD32(ctx->r8, ctx->r5);
    // 0x800DE70C: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800DE710: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800DE714: addu        $t4, $t3, $a2
    ctx->r12 = ADD32(ctx->r11, ctx->r6);
    // 0x800DE718: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x800DE71C: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800DE720: lui         $at, 0xA00
    ctx->r1 = S32(0XA00 << 16);
    // 0x800DE724: sll         $t7, $t0, 16
    ctx->r15 = S32(ctx->r8 << 16);
    // 0x800DE728: andi        $t8, $s1, 0xFFFF
    ctx->r24 = ctx->r17 & 0XFFFF;
    // 0x800DE72C: or          $t3, $t7, $t8
    ctx->r11 = ctx->r15 | ctx->r24;
    // 0x800DE730: or          $t9, $t5, $at
    ctx->r25 = ctx->r13 | ctx->r1;
    // 0x800DE734: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800DE738: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x800DE73C: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
L_800DE740:
    // 0x800DE740: slt         $at, $s2, $s3
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800DE744: bnel        $at, $zero, L_800DE630
    if (ctx->r1 != 0) {
        // 0x800DE748: lw          $v0, 0x24($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X24);
            goto L_800DE630;
    }
    goto skip_2;
    // 0x800DE748: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    skip_2:
L_800DE74C:
    // 0x800DE74C: lw          $t4, 0x38($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X38);
    // 0x800DE750: lw          $t9, 0x44($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X44);
    // 0x800DE754: sll         $t6, $s3, 1
    ctx->r14 = S32(ctx->r19 << 1);
    // 0x800DE758: addu        $t5, $t4, $s3
    ctx->r13 = ADD32(ctx->r12, ctx->r19);
    // 0x800DE75C: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x800DE760: sw          $t5, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r13;
    // 0x800DE764: sw          $t7, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r15;
    // 0x800DE768: b           L_800DE8A4
    // 0x800DE76C: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
        goto L_800DE8A4;
    // 0x800DE76C: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800DE770: lw          $v0, 0x28($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X28);
L_800DE774:
    // 0x800DE774: lw          $a0, 0x44($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X44);
    // 0x800DE778: sll         $s1, $s3, 1
    ctx->r17 = S32(ctx->r19 << 1);
    // 0x800DE77C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800DE780: lw          $t4, 0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X4);
    // 0x800DE784: addu        $v1, $a0, $s1
    ctx->r3 = ADD32(ctx->r4, ctx->r17);
    // 0x800DE788: subu        $t3, $v1, $t8
    ctx->r11 = SUB32(ctx->r3, ctx->r24);
    // 0x800DE78C: subu        $s2, $t3, $t4
    ctx->r18 = SUB32(ctx->r11, ctx->r12);
    // 0x800DE790: bgezl       $s2, L_800DE7A0
    if (SIGNED(ctx->r18) >= 0) {
        // 0x800DE794: slt         $at, $s1, $s2
        ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r18) ? 1 : 0;
            goto L_800DE7A0;
    }
    goto skip_3;
    // 0x800DE794: slt         $at, $s1, $s2
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r18) ? 1 : 0;
    skip_3:
    // 0x800DE798: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800DE79C: slt         $at, $s1, $s2
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r18) ? 1 : 0;
L_800DE7A0:
    // 0x800DE7A0: beql        $at, $zero, L_800DE7B0
    if (ctx->r1 == 0) {
        // 0x800DE7A4: slt         $at, $s2, $s1
        ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r17) ? 1 : 0;
            goto L_800DE7B0;
    }
    goto skip_4;
    // 0x800DE7A4: slt         $at, $s2, $s1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r17) ? 1 : 0;
    skip_4:
    // 0x800DE7A8: or          $s2, $s1, $zero
    ctx->r18 = ctx->r17 | 0;
    // 0x800DE7AC: slt         $at, $s2, $s1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r17) ? 1 : 0;
L_800DE7B0:
    // 0x800DE7B0: beql        $at, $zero, L_800DE864
    if (ctx->r1 == 0) {
        // 0x800DE7B4: sw          $v1, 0x44($s0)
        MEM_W(0X44, ctx->r16) = ctx->r3;
            goto L_800DE864;
    }
    goto skip_5;
    // 0x800DE7B4: sw          $v1, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r3;
    skip_5:
    // 0x800DE7B8: blez        $s3, L_800DE838
    if (SIGNED(ctx->r19) <= 0) {
        // 0x800DE7BC: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_800DE838;
    }
    // 0x800DE7BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800DE7C0: lw          $a2, 0x34($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X34);
    // 0x800DE7C4: subu        $a1, $s1, $s2
    ctx->r5 = SUB32(ctx->r17, ctx->r18);
    // 0x800DE7C8: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
    // 0x800DE7CC: sw          $t2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r10;
    // 0x800DE7D0: lw          $t9, 0x30($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X30);
    // 0x800DE7D4: jalr        $t9
    // 0x800DE7D8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x800DE7D8: nop

    after_2:
    // 0x800DE7DC: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x800DE7E0: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    // 0x800DE7E4: andi        $a2, $v0, 0x7
    ctx->r6 = ctx->r2 & 0X7;
    // 0x800DE7E8: lh          $t5, 0x0($t2)
    ctx->r13 = MEM_H(ctx->r10, 0X0);
    // 0x800DE7EC: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x800DE7F0: addu        $a3, $a3, $a2
    ctx->r7 = ADD32(ctx->r7, ctx->r6);
    // 0x800DE7F4: andi        $t8, $a3, 0x7
    ctx->r24 = ctx->r7 & 0X7;
    // 0x800DE7F8: subu        $t3, $a3, $t8
    ctx->r11 = SUB32(ctx->r7, ctx->r24);
    // 0x800DE7FC: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x800DE800: andi        $t6, $t5, 0xFFFF
    ctx->r14 = ctx->r13 & 0XFFFF;
    // 0x800DE804: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x800DE808: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x800DE80C: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x800DE810: andi        $t9, $t4, 0xFFFF
    ctx->r25 = ctx->r12 & 0XFFFF;
    // 0x800DE814: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x800DE818: subu        $t6, $v0, $a2
    ctx->r14 = SUB32(ctx->r2, ctx->r6);
    // 0x800DE81C: lui         $t5, 0x400
    ctx->r13 = S32(0X400 << 16);
    // 0x800DE820: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x800DE824: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x800DE828: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x800DE82C: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x800DE830: b           L_800DE838
    // 0x800DE834: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
        goto L_800DE838;
    // 0x800DE834: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
L_800DE838:
    // 0x800DE838: lh          $t7, 0x0($t2)
    ctx->r15 = MEM_H(ctx->r10, 0X0);
    // 0x800DE83C: addu        $t8, $t7, $a2
    ctx->r24 = ADD32(ctx->r15, ctx->r6);
    // 0x800DE840: sh          $t8, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r24;
    // 0x800DE844: lw          $t3, 0x38($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X38);
    // 0x800DE848: lw          $t9, 0x44($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X44);
    // 0x800DE84C: addu        $t4, $t3, $s3
    ctx->r12 = ADD32(ctx->r11, ctx->r19);
    // 0x800DE850: addu        $t5, $t9, $s1
    ctx->r13 = ADD32(ctx->r25, ctx->r17);
    // 0x800DE854: sw          $t4, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r12;
    // 0x800DE858: b           L_800DE864
    // 0x800DE85C: sw          $t5, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r13;
        goto L_800DE864;
    // 0x800DE85C: sw          $t5, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r13;
    // 0x800DE860: sw          $v1, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r3;
L_800DE864:
    // 0x800DE864: beq         $s2, $zero, L_800DE8A0
    if (ctx->r18 == 0) {
        // 0x800DE868: subu        $v1, $s1, $s2
        ctx->r3 = SUB32(ctx->r17, ctx->r18);
            goto L_800DE8A0;
    }
    // 0x800DE868: subu        $v1, $s1, $s2
    ctx->r3 = SUB32(ctx->r17, ctx->r18);
    // 0x800DE86C: bgez        $v1, L_800DE878
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800DE870: or          $v0, $t1, $zero
        ctx->r2 = ctx->r9 | 0;
            goto L_800DE878;
    }
    // 0x800DE870: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800DE874: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800DE878:
    // 0x800DE878: lh          $t6, 0x0($t2)
    ctx->r14 = MEM_H(ctx->r10, 0X0);
    // 0x800DE87C: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800DE880: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800DE884: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x800DE888: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x800DE88C: lui         $at, 0x200
    ctx->r1 = S32(0X200 << 16);
    // 0x800DE890: or          $t3, $t8, $at
    ctx->r11 = ctx->r24 | ctx->r1;
    // 0x800DE894: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x800DE898: sw          $s2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r18;
    // 0x800DE89C: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
L_800DE8A0:
    // 0x800DE8A0: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
L_800DE8A4:
    // 0x800DE8A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800DE8A8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800DE8AC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800DE8B0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800DE8B4: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800DE8B8: jr          $ra
    // 0x800DE8BC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800DE8BC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_800DE8C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DE8C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DE8C4: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800DE8C8: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800DE8CC: sll         $t6, $s3, 16
    ctx->r14 = S32(ctx->r19 << 16);
    // 0x800DE8D0: sll         $t8, $s5, 16
    ctx->r24 = S32(ctx->r21 << 16);
    // 0x800DE8D4: sra         $s5, $t8, 16
    ctx->r21 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800DE8D8: sra         $s3, $t6, 16
    ctx->r19 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800DE8DC: blez        $s1, L_800DE948
    if (SIGNED(ctx->r17) <= 0) {
        // 0x800DE8E0: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800DE948;
    }
    // 0x800DE8E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DE8E4: lw          $t9, 0x30($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X30);
    // 0x800DE8E8: lw          $a0, 0x44($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X44);
    // 0x800DE8EC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800DE8F0: jalr        $t9
    // 0x800DE8F4: lw          $a2, 0x34($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X34);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800DE8F4: lw          $a2, 0x34($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X34);
    after_0:
    // 0x800DE8F8: andi        $a2, $v0, 0x7
    ctx->r6 = ctx->r2 & 0X7;
    // 0x800DE8FC: addu        $s1, $s1, $a2
    ctx->r17 = ADD32(ctx->r17, ctx->r6);
    // 0x800DE900: andi        $t6, $s3, 0xFFFF
    ctx->r14 = ctx->r19 & 0XFFFF;
    // 0x800DE904: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x800DE908: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x800DE90C: andi        $t8, $s1, 0x7
    ctx->r24 = ctx->r17 & 0X7;
    // 0x800DE910: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800DE914: subu        $t9, $s1, $t8
    ctx->r25 = SUB32(ctx->r17, ctx->r24);
    // 0x800DE918: addiu       $t6, $t9, 0x8
    ctx->r14 = ADD32(ctx->r25, 0X8);
    // 0x800DE91C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800DE920: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800DE924: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x800DE928: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800DE92C: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x800DE930: subu        $t9, $v0, $a2
    ctx->r25 = SUB32(ctx->r2, ctx->r6);
    // 0x800DE934: lui         $t8, 0x400
    ctx->r24 = S32(0X400 << 16);
    // 0x800DE938: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x800DE93C: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x800DE940: b           L_800DE94C
    // 0x800DE944: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
        goto L_800DE94C;
    // 0x800DE944: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_800DE948:
    // 0x800DE948: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_800DE94C:
    // 0x800DE94C: andi        $t6, $s4, 0x2
    ctx->r14 = ctx->r20 & 0X2;
    // 0x800DE950: beq         $t6, $zero, L_800DE978
    if (ctx->r14 == 0) {
        // 0x800DE954: or          $v0, $s0, $zero
        ctx->r2 = ctx->r16 | 0;
            goto L_800DE978;
    }
    // 0x800DE954: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800DE958: lui         $t7, 0xF00
    ctx->r15 = S32(0XF00 << 16);
    // 0x800DE95C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800DE960: lw          $t8, 0x18($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X18);
    // 0x800DE964: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x800DE968: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800DE96C: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x800DE970: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800DE974: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_800DE978:
    // 0x800DE978: addu        $t6, $s3, $a2
    ctx->r14 = ADD32(ctx->r19, ctx->r6);
    // 0x800DE97C: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x800DE980: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x800DE984: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x800DE988: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800DE98C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800DE990: sll         $t7, $s6, 1
    ctx->r15 = S32(ctx->r22 << 1);
    // 0x800DE994: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x800DE998: sll         $t6, $s5, 16
    ctx->r14 = S32(ctx->r21 << 16);
    // 0x800DE99C: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x800DE9A0: andi        $t7, $s4, 0xFF
    ctx->r15 = ctx->r20 & 0XFF;
    // 0x800DE9A4: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800DE9A8: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x800DE9AC: lui         $at, 0x100
    ctx->r1 = S32(0X100 << 16);
    // 0x800DE9B0: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x800DE9B4: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x800DE9B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800DE9BC: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800DE9C0: lw          $t9, 0x14($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X14);
    // 0x800DE9C4: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x800DE9C8: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800DE9CC: and         $t7, $t9, $at
    ctx->r15 = ctx->r25 & ctx->r1;
    // 0x800DE9D0: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x800DE9D4: sw          $zero, 0x40($s2)
    MEM_W(0X40, ctx->r18) = 0;
    // 0x800DE9D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DE9DC: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800DE9E0: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800DE9E4: jr          $ra
    // 0x800DE9E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800DE9E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void alAdpcmPull_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DE9EC: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x800DE9F0: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x800DE9F4: sw          $a3, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r7;
    // 0x800DE9F8: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800DE9FC: or          $s7, $a0, $zero
    ctx->r23 = ctx->r4 | 0;
    // 0x800DEA00: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x800DEA04: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x800DEA08: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x800DEA0C: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x800DEA10: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x800DEA14: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x800DEA18: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x800DEA1C: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x800DEA20: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800DEA24: sw          $a1, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r5;
    // 0x800DEA28: or          $t0, $a2, $zero
    ctx->r8 = ctx->r6 | 0;
    // 0x800DEA2C: bne         $a2, $zero, L_800DEA3C
    if (ctx->r6 != 0) {
        // 0x800DEA30: or          $t5, $zero, $zero
        ctx->r13 = 0 | 0;
            goto L_800DEA3C;
    }
    // 0x800DEA30: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x800DEA34: b           L_800DEE5C
    // 0x800DEA38: lw          $v0, 0xC0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XC0);
        goto L_800DEE5C;
    // 0x800DEA38: lw          $v0, 0xC0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XC0);
L_800DEA3C:
    // 0x800DEA3C: lw          $t6, 0x2C($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X2C);
    // 0x800DEA40: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800DEA44: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800DEA48: lw          $a1, 0xC0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC0);
    // 0x800DEA4C: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x800DEA50: lui         $at, 0xB00
    ctx->r1 = S32(0XB00 << 16);
    // 0x800DEA54: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x800DEA58: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x800DEA5C: lw          $t9, 0x28($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X28);
    // 0x800DEA60: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x800DEA64: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800DEA68: lw          $t6, 0x10($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X10);
    // 0x800DEA6C: addiu       $t2, $a1, 0x8
    ctx->r10 = ADD32(ctx->r5, 0X8);
    // 0x800DEA70: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800DEA74: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800DEA78: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x800DEA7C: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    // 0x800DEA80: lw          $v1, 0x38($s7)
    ctx->r3 = MEM_W(ctx->r23, 0X38);
    // 0x800DEA84: lw          $a0, 0x20($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X20);
    // 0x800DEA88: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    // 0x800DEA8C: addu        $t9, $v1, $t0
    ctx->r25 = ADD32(ctx->r3, ctx->r8);
    // 0x800DEA90: sltu        $t1, $a0, $t9
    ctx->r9 = ctx->r4 < ctx->r25 ? 1 : 0;
    // 0x800DEA94: beq         $t1, $zero, L_800DEAA8
    if (ctx->r9 == 0) {
        // 0x800DEA98: addiu       $t7, $zero, 0x10
        ctx->r15 = ADD32(0, 0X10);
            goto L_800DEAA8;
    }
    // 0x800DEA98: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x800DEA9C: lw          $t1, 0x24($s7)
    ctx->r9 = MEM_W(ctx->r23, 0X24);
    // 0x800DEAA0: sltu        $t6, $zero, $t1
    ctx->r14 = 0 < ctx->r9 ? 1 : 0;
    // 0x800DEAA4: or          $t1, $t6, $zero
    ctx->r9 = ctx->r14 | 0;
L_800DEAA8:
    // 0x800DEAA8: beq         $t1, $zero, L_800DEAB8
    if (ctx->r9 == 0) {
        // 0x800DEAAC: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_800DEAB8;
    }
    // 0x800DEAAC: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x800DEAB0: b           L_800DEAB8
    // 0x800DEAB4: subu        $a1, $a0, $v1
    ctx->r5 = SUB32(ctx->r4, ctx->r3);
        goto L_800DEAB8;
    // 0x800DEAB4: subu        $a1, $a0, $v1
    ctx->r5 = SUB32(ctx->r4, ctx->r3);
L_800DEAB8:
    // 0x800DEAB8: lw          $v1, 0x3C($s7)
    ctx->r3 = MEM_W(ctx->r23, 0X3C);
    // 0x800DEABC: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
    // 0x800DEAC0: or          $s2, $s7, $zero
    ctx->r18 = ctx->r23 | 0;
    // 0x800DEAC4: beq         $v1, $zero, L_800DEAD4
    if (ctx->r3 == 0) {
        // 0x800DEAC8: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_800DEAD4;
    }
    // 0x800DEAC8: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800DEACC: b           L_800DEAD4
    // 0x800DEAD0: subu        $a2, $t7, $v1
    ctx->r6 = SUB32(ctx->r15, ctx->r3);
        goto L_800DEAD4;
    // 0x800DEAD0: subu        $a2, $t7, $v1
    ctx->r6 = SUB32(ctx->r15, ctx->r3);
L_800DEAD4:
    // 0x800DEAD4: subu        $a0, $a1, $a2
    ctx->r4 = SUB32(ctx->r5, ctx->r6);
    // 0x800DEAD8: bgez        $a0, L_800DEAE4
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800DEADC: nop
    
            goto L_800DEAE4;
    }
    // 0x800DEADC: nop

    // 0x800DEAE0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800DEAE4:
    // 0x800DEAE4: beq         $t1, $zero, L_800DECEC
    if (ctx->r9 == 0) {
        // 0x800DEAE8: addiu       $fp, $a0, 0xF
        ctx->r30 = ADD32(ctx->r4, 0XF);
            goto L_800DECEC;
    }
    // 0x800DEAE8: addiu       $fp, $a0, 0xF
    ctx->r30 = ADD32(ctx->r4, 0XF);
    // 0x800DEAEC: addiu       $fp, $a0, 0xF
    ctx->r30 = ADD32(ctx->r4, 0XF);
    // 0x800DEAF0: sra         $t8, $fp, 4
    ctx->r24 = S32(SIGNED(ctx->r30) >> 4);
    // 0x800DEAF4: lh          $s5, 0x0($a3)
    ctx->r21 = MEM_H(ctx->r7, 0X0);
    // 0x800DEAF8: lw          $s4, 0x40($s7)
    ctx->r20 = MEM_W(ctx->r23, 0X40);
    // 0x800DEAFC: sll         $t1, $t8, 3
    ctx->r9 = S32(ctx->r24 << 3);
    // 0x800DEB00: addu        $t1, $t1, $t8
    ctx->r9 = ADD32(ctx->r9, ctx->r24);
    // 0x800DEB04: or          $s1, $t1, $zero
    ctx->r17 = ctx->r9 | 0;
    // 0x800DEB08: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x800DEB0C: sw          $t0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r8;
    // 0x800DEB10: sw          $a3, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r7;
    // 0x800DEB14: sw          $a1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r5;
    // 0x800DEB18: or          $fp, $t8, $zero
    ctx->r30 = ctx->r24 | 0;
    // 0x800DEB1C: jal         0x800DE8C0
    // 0x800DEB20: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    func_800DE8C0(rdram, ctx);
        goto after_0;
    // 0x800DEB20: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    after_0:
    // 0x800DEB24: lw          $v1, 0x3C($s7)
    ctx->r3 = MEM_W(ctx->r23, 0X3C);
    // 0x800DEB28: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    // 0x800DEB2C: lw          $a3, 0xB4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB4);
    // 0x800DEB30: lw          $t0, 0xB8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB8);
    // 0x800DEB34: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x800DEB38: beq         $v1, $zero, L_800DEB54
    if (ctx->r3 == 0) {
        // 0x800DEB3C: or          $t2, $v0, $zero
        ctx->r10 = ctx->r2 | 0;
            goto L_800DEB54;
    }
    // 0x800DEB3C: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
    // 0x800DEB40: lh          $t9, 0x0($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X0);
    // 0x800DEB44: sll         $t6, $v1, 1
    ctx->r14 = S32(ctx->r3 << 1);
    // 0x800DEB48: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x800DEB4C: b           L_800DEB60
    // 0x800DEB50: sh          $t7, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r15;
        goto L_800DEB60;
    // 0x800DEB50: sh          $t7, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r15;
L_800DEB54:
    // 0x800DEB54: lh          $t8, 0x0($a3)
    ctx->r24 = MEM_H(ctx->r7, 0X0);
    // 0x800DEB58: addiu       $t9, $t8, 0x20
    ctx->r25 = ADD32(ctx->r24, 0X20);
    // 0x800DEB5C: sh          $t9, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r25;
L_800DEB60:
    // 0x800DEB60: lw          $v0, 0x1C($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X1C);
    // 0x800DEB64: lw          $t7, 0x28($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X28);
    // 0x800DEB68: slt         $at, $a1, $t0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800DEB6C: andi        $t6, $v0, 0xF
    ctx->r14 = ctx->r2 & 0XF;
    // 0x800DEB70: sw          $t6, 0x3C($s7)
    MEM_W(0X3C, ctx->r23) = ctx->r14;
    // 0x800DEB74: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x800DEB78: srl         $t9, $v0, 4
    ctx->r25 = S32(U32(ctx->r2) >> 4);
    // 0x800DEB7C: sll         $t6, $t9, 3
    ctx->r14 = S32(ctx->r25 << 3);
    // 0x800DEB80: addu        $t6, $t6, $t9
    ctx->r14 = ADD32(ctx->r14, ctx->r25);
    // 0x800DEB84: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x800DEB88: addiu       $t9, $t7, 0x9
    ctx->r25 = ADD32(ctx->r15, 0X9);
    // 0x800DEB8C: sw          $t9, 0x44($s7)
    MEM_W(0X44, ctx->r23) = ctx->r25;
    // 0x800DEB90: sw          $v0, 0x38($s7)
    MEM_W(0X38, ctx->r23) = ctx->r2;
    // 0x800DEB94: beq         $at, $zero, L_800DECBC
    if (ctx->r1 == 0) {
        // 0x800DEB98: lh          $a2, 0x0($a3)
        ctx->r6 = MEM_H(ctx->r7, 0X0);
            goto L_800DECBC;
    }
    // 0x800DEB98: lh          $a2, 0x0($a3)
    ctx->r6 = MEM_H(ctx->r7, 0X0);
    // 0x800DEB9C: sll         $v1, $a1, 1
    ctx->r3 = S32(ctx->r5 << 1);
L_800DEBA0:
    // 0x800DEBA0: addiu       $t8, $fp, 0x1
    ctx->r24 = ADD32(ctx->r30, 0X1);
    // 0x800DEBA4: sll         $t6, $t8, 5
    ctx->r14 = S32(ctx->r24 << 5);
    // 0x800DEBA8: lw          $v0, 0x24($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X24);
    // 0x800DEBAC: addu        $a3, $t6, $a2
    ctx->r7 = ADD32(ctx->r14, ctx->r6);
    // 0x800DEBB0: addiu       $at, $zero, -0x20
    ctx->r1 = ADD32(0, -0X20);
    // 0x800DEBB4: and         $t7, $a3, $at
    ctx->r15 = ctx->r7 & ctx->r1;
    // 0x800DEBB8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800DEBBC: subu        $t0, $t0, $a1
    ctx->r8 = SUB32(ctx->r8, ctx->r5);
    // 0x800DEBC0: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
    // 0x800DEBC4: beq         $v0, $at, L_800DEBD8
    if (ctx->r2 == ctx->r1) {
        // 0x800DEBC8: addu        $a2, $a2, $v1
        ctx->r6 = ADD32(ctx->r6, ctx->r3);
            goto L_800DEBD8;
    }
    // 0x800DEBC8: addu        $a2, $a2, $v1
    ctx->r6 = ADD32(ctx->r6, ctx->r3);
    // 0x800DEBCC: beq         $v0, $zero, L_800DEBD8
    if (ctx->r2 == 0) {
        // 0x800DEBD0: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_800DEBD8;
    }
    // 0x800DEBD0: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x800DEBD4: sw          $t9, 0x24($s7)
    MEM_W(0X24, ctx->r23) = ctx->r25;
L_800DEBD8:
    // 0x800DEBD8: lw          $t8, 0x20($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X20);
    // 0x800DEBDC: lw          $t6, 0x1C($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X1C);
    // 0x800DEBE0: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
    // 0x800DEBE4: or          $s2, $s7, $zero
    ctx->r18 = ctx->r23 | 0;
    // 0x800DEBE8: subu        $v0, $t8, $t6
    ctx->r2 = SUB32(ctx->r24, ctx->r14);
    // 0x800DEBEC: sltu        $at, $t0, $v0
    ctx->r1 = ctx->r8 < ctx->r2 ? 1 : 0;
    // 0x800DEBF0: beq         $at, $zero, L_800DEC00
    if (ctx->r1 == 0) {
        // 0x800DEBF4: sll         $s5, $a3, 16
        ctx->r21 = S32(ctx->r7 << 16);
            goto L_800DEC00;
    }
    // 0x800DEBF4: sll         $s5, $a3, 16
    ctx->r21 = S32(ctx->r7 << 16);
    // 0x800DEBF8: b           L_800DEC04
    // 0x800DEBFC: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
        goto L_800DEC04;
    // 0x800DEBFC: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
L_800DEC00:
    // 0x800DEC00: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_800DEC04:
    // 0x800DEC04: lw          $t7, 0x3C($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X3C);
    // 0x800DEC08: sra         $t8, $s5, 16
    ctx->r24 = S32(SIGNED(ctx->r21) >> 16);
    // 0x800DEC0C: or          $s5, $t8, $zero
    ctx->r21 = ctx->r24 | 0;
    // 0x800DEC10: addu        $a0, $a1, $t7
    ctx->r4 = ADD32(ctx->r5, ctx->r15);
    // 0x800DEC14: addiu       $a0, $a0, -0x10
    ctx->r4 = ADD32(ctx->r4, -0X10);
    // 0x800DEC18: bgez        $a0, L_800DEC24
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800DEC1C: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_800DEC24;
    }
    // 0x800DEC1C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800DEC20: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800DEC24:
    // 0x800DEC24: lw          $s4, 0x40($s7)
    ctx->r20 = MEM_W(ctx->r23, 0X40);
    // 0x800DEC28: addiu       $fp, $a0, 0xF
    ctx->r30 = ADD32(ctx->r4, 0XF);
    // 0x800DEC2C: sra         $t9, $fp, 4
    ctx->r25 = S32(SIGNED(ctx->r30) >> 4);
    // 0x800DEC30: sll         $t1, $t9, 3
    ctx->r9 = S32(ctx->r25 << 3);
    // 0x800DEC34: addu        $t1, $t1, $t9
    ctx->r9 = ADD32(ctx->r9, ctx->r25);
    // 0x800DEC38: ori         $t6, $s4, 0x2
    ctx->r14 = ctx->r20 | 0X2;
    // 0x800DEC3C: or          $s4, $t6, $zero
    ctx->r20 = ctx->r14 | 0;
    // 0x800DEC40: or          $s1, $t1, $zero
    ctx->r17 = ctx->r9 | 0;
    // 0x800DEC44: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x800DEC48: or          $fp, $t9, $zero
    ctx->r30 = ctx->r25 | 0;
    // 0x800DEC4C: sw          $t0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r8;
    // 0x800DEC50: sw          $a3, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r7;
    // 0x800DEC54: sw          $a2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r6;
    // 0x800DEC58: sw          $a1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r5;
    // 0x800DEC5C: jal         0x800DE8C0
    // 0x800DEC60: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    func_800DE8C0(rdram, ctx);
        goto after_1;
    // 0x800DEC60: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    after_1:
    // 0x800DEC64: lw          $t7, 0x3C($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X3C);
    // 0x800DEC68: lw          $a3, 0x88($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X88);
    // 0x800DEC6C: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800DEC70: sll         $t9, $t7, 1
    ctx->r25 = S32(ctx->r15 << 1);
    // 0x800DEC74: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800DEC78: addu        $t8, $t9, $a3
    ctx->r24 = ADD32(ctx->r25, ctx->r7);
    // 0x800DEC7C: and         $t6, $t8, $at
    ctx->r14 = ctx->r24 & ctx->r1;
    // 0x800DEC80: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    // 0x800DEC84: lui         $at, 0xA00
    ctx->r1 = S32(0XA00 << 16);
    // 0x800DEC88: lw          $a2, 0x80($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X80);
    // 0x800DEC8C: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x800DEC90: lw          $t0, 0xB8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB8);
    // 0x800DEC94: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x800DEC98: sll         $v1, $a1, 1
    ctx->r3 = S32(ctx->r5 << 1);
    // 0x800DEC9C: andi        $t6, $v1, 0xFFFF
    ctx->r14 = ctx->r3 & 0XFFFF;
    // 0x800DECA0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800DECA4: sll         $t8, $a2, 16
    ctx->r24 = S32(ctx->r6 << 16);
    // 0x800DECA8: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x800DECAC: slt         $at, $a1, $t0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800DECB0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800DECB4: bne         $at, $zero, L_800DEBA0
    if (ctx->r1 != 0) {
        // 0x800DECB8: addiu       $t2, $v0, 0x8
        ctx->r10 = ADD32(ctx->r2, 0X8);
            goto L_800DEBA0;
    }
    // 0x800DECB8: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
L_800DECBC:
    // 0x800DECBC: lw          $t9, 0x3C($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X3C);
    // 0x800DECC0: lw          $t7, 0x38($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X38);
    // 0x800DECC4: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x800DECC8: addu        $t8, $t9, $t0
    ctx->r24 = ADD32(ctx->r25, ctx->r8);
    // 0x800DECCC: andi        $t6, $t8, 0xF
    ctx->r14 = ctx->r24 & 0XF;
    // 0x800DECD0: lw          $t8, 0x44($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X44);
    // 0x800DECD4: sw          $t6, 0x3C($s7)
    MEM_W(0X3C, ctx->r23) = ctx->r14;
    // 0x800DECD8: addu        $t9, $t7, $t0
    ctx->r25 = ADD32(ctx->r15, ctx->r8);
    // 0x800DECDC: addu        $t6, $t8, $t1
    ctx->r14 = ADD32(ctx->r24, ctx->r9);
    // 0x800DECE0: sw          $t9, 0x38($s7)
    MEM_W(0X38, ctx->r23) = ctx->r25;
    // 0x800DECE4: b           L_800DEE5C
    // 0x800DECE8: sw          $t6, 0x44($s7)
    MEM_W(0X44, ctx->r23) = ctx->r14;
        goto L_800DEE5C;
    // 0x800DECE8: sw          $t6, 0x44($s7)
    MEM_W(0X44, ctx->r23) = ctx->r14;
L_800DECEC:
    // 0x800DECEC: lw          $v0, 0x28($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X28);
    // 0x800DECF0: sra         $t7, $fp, 4
    ctx->r15 = S32(SIGNED(ctx->r30) >> 4);
    // 0x800DECF4: lw          $t9, 0x44($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X44);
    // 0x800DECF8: sll         $t1, $t7, 3
    ctx->r9 = S32(ctx->r15 << 3);
    // 0x800DECFC: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800DED00: addu        $t1, $t1, $t7
    ctx->r9 = ADD32(ctx->r9, ctx->r15);
    // 0x800DED04: or          $fp, $t7, $zero
    ctx->r30 = ctx->r15 | 0;
    // 0x800DED08: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x800DED0C: addu        $t3, $t9, $t1
    ctx->r11 = ADD32(ctx->r25, ctx->r9);
    // 0x800DED10: subu        $t6, $t3, $t8
    ctx->r14 = SUB32(ctx->r11, ctx->r24);
    // 0x800DED14: subu        $v1, $t6, $t7
    ctx->r3 = SUB32(ctx->r14, ctx->r15);
    // 0x800DED18: bgez        $v1, L_800DED24
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800DED1C: sll         $a1, $fp, 4
        ctx->r5 = S32(ctx->r30 << 4);
            goto L_800DED24;
    }
    // 0x800DED1C: sll         $a1, $fp, 4
    ctx->r5 = S32(ctx->r30 << 4);
    // 0x800DED20: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800DED24:
    // 0x800DED24: div         $zero, $v1, $at
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r1)));
    // 0x800DED28: mflo        $v0
    ctx->r2 = lo;
    // 0x800DED2C: sll         $a0, $v0, 4
    ctx->r4 = S32(ctx->r2 << 4);
    // 0x800DED30: addu        $t4, $a1, $a2
    ctx->r12 = ADD32(ctx->r5, ctx->r6);
    // 0x800DED34: slt         $at, $t4, $a0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800DED38: beq         $at, $zero, L_800DED44
    if (ctx->r1 == 0) {
        // 0x800DED3C: or          $s0, $t2, $zero
        ctx->r16 = ctx->r10 | 0;
            goto L_800DED44;
    }
    // 0x800DED3C: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
    // 0x800DED40: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
L_800DED44:
    // 0x800DED44: andi        $t8, $a0, 0xF
    ctx->r24 = ctx->r4 & 0XF;
    // 0x800DED48: subu        $t6, $a0, $t8
    ctx->r14 = SUB32(ctx->r4, ctx->r24);
    // 0x800DED4C: slt         $at, $t6, $t0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800DED50: beq         $at, $zero, L_800DEE00
    if (ctx->r1 == 0) {
        // 0x800DED54: subu        $a2, $t1, $v1
        ctx->r6 = SUB32(ctx->r9, ctx->r3);
            goto L_800DEE00;
    }
    // 0x800DED54: subu        $a2, $t1, $v1
    ctx->r6 = SUB32(ctx->r9, ctx->r3);
    // 0x800DED58: lh          $s5, 0x0($a3)
    ctx->r21 = MEM_H(ctx->r7, 0X0);
    // 0x800DED5C: lw          $s4, 0x40($s7)
    ctx->r20 = MEM_W(ctx->r23, 0X40);
    // 0x800DED60: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800DED64: sw          $t5, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r13;
    // 0x800DED68: sw          $t4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r12;
    // 0x800DED6C: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x800DED70: sw          $t0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r8;
    // 0x800DED74: sw          $a3, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r7;
    // 0x800DED78: sw          $a0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r4;
    // 0x800DED7C: or          $s2, $s7, $zero
    ctx->r18 = ctx->r23 | 0;
    // 0x800DED80: subu        $s6, $a1, $a0
    ctx->r22 = SUB32(ctx->r5, ctx->r4);
    // 0x800DED84: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x800DED88: jal         0x800DE8C0
    // 0x800DED8C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    func_800DE8C0(rdram, ctx);
        goto after_2;
    // 0x800DED8C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    after_2:
    // 0x800DED90: lw          $v1, 0x3C($s7)
    ctx->r3 = MEM_W(ctx->r23, 0X3C);
    // 0x800DED94: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    // 0x800DED98: lw          $a3, 0xB4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB4);
    // 0x800DED9C: lw          $t0, 0xB8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB8);
    // 0x800DEDA0: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x800DEDA4: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x800DEDA8: lw          $t5, 0x7C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X7C);
    // 0x800DEDAC: beq         $v1, $zero, L_800DEDC8
    if (ctx->r3 == 0) {
        // 0x800DEDB0: or          $t2, $v0, $zero
        ctx->r10 = ctx->r2 | 0;
            goto L_800DEDC8;
    }
    // 0x800DEDB0: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
    // 0x800DEDB4: lh          $t7, 0x0($a3)
    ctx->r15 = MEM_H(ctx->r7, 0X0);
    // 0x800DEDB8: sll         $t9, $v1, 1
    ctx->r25 = S32(ctx->r3 << 1);
    // 0x800DEDBC: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x800DEDC0: b           L_800DEDD4
    // 0x800DEDC4: sh          $t8, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r24;
        goto L_800DEDD4;
    // 0x800DEDC4: sh          $t8, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r24;
L_800DEDC8:
    // 0x800DEDC8: lh          $t6, 0x0($a3)
    ctx->r14 = MEM_H(ctx->r7, 0X0);
    // 0x800DEDCC: addiu       $t7, $t6, 0x20
    ctx->r15 = ADD32(ctx->r14, 0X20);
    // 0x800DEDD0: sh          $t7, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r15;
L_800DEDD4:
    // 0x800DEDD4: lw          $t9, 0x3C($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X3C);
    // 0x800DEDD8: lw          $t7, 0x38($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X38);
    // 0x800DEDDC: addu        $t8, $t9, $t0
    ctx->r24 = ADD32(ctx->r25, ctx->r8);
    // 0x800DEDE0: andi        $t6, $t8, 0xF
    ctx->r14 = ctx->r24 & 0XF;
    // 0x800DEDE4: lw          $t8, 0x44($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X44);
    // 0x800DEDE8: sw          $t6, 0x3C($s7)
    MEM_W(0X3C, ctx->r23) = ctx->r14;
    // 0x800DEDEC: addu        $t9, $t7, $t0
    ctx->r25 = ADD32(ctx->r15, ctx->r8);
    // 0x800DEDF0: addu        $t6, $t8, $t1
    ctx->r14 = ADD32(ctx->r24, ctx->r9);
    // 0x800DEDF4: sw          $t9, 0x38($s7)
    MEM_W(0X38, ctx->r23) = ctx->r25;
    // 0x800DEDF8: b           L_800DEE08
    // 0x800DEDFC: sw          $t6, 0x44($s7)
    MEM_W(0X44, ctx->r23) = ctx->r14;
        goto L_800DEE08;
    // 0x800DEDFC: sw          $t6, 0x44($s7)
    MEM_W(0X44, ctx->r23) = ctx->r14;
L_800DEE00:
    // 0x800DEE00: sw          $zero, 0x3C($s7)
    MEM_W(0X3C, ctx->r23) = 0;
    // 0x800DEE04: sw          $t3, 0x44($s7)
    MEM_W(0X44, ctx->r23) = ctx->r11;
L_800DEE08:
    // 0x800DEE08: beq         $a0, $zero, L_800DEE58
    if (ctx->r4 == 0) {
        // 0x800DEE0C: or          $v0, $t2, $zero
        ctx->r2 = ctx->r10 | 0;
            goto L_800DEE58;
    }
    // 0x800DEE0C: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x800DEE10: beq         $t5, $zero, L_800DEE28
    if (ctx->r13 == 0) {
        // 0x800DEE14: sw          $zero, 0x3C($s7)
        MEM_W(0X3C, ctx->r23) = 0;
            goto L_800DEE28;
    }
    // 0x800DEE14: sw          $zero, 0x3C($s7)
    MEM_W(0X3C, ctx->r23) = 0;
    // 0x800DEE18: subu        $v1, $t4, $a0
    ctx->r3 = SUB32(ctx->r12, ctx->r4);
    // 0x800DEE1C: sll         $t7, $v1, 1
    ctx->r15 = S32(ctx->r3 << 1);
    // 0x800DEE20: b           L_800DEE2C
    // 0x800DEE24: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
        goto L_800DEE2C;
    // 0x800DEE24: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
L_800DEE28:
    // 0x800DEE28: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800DEE2C:
    // 0x800DEE2C: lh          $t9, 0x0($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X0);
    // 0x800DEE30: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800DEE34: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800DEE38: addu        $t8, $t9, $v1
    ctx->r24 = ADD32(ctx->r25, ctx->r3);
    // 0x800DEE3C: and         $t6, $t8, $at
    ctx->r14 = ctx->r24 & ctx->r1;
    // 0x800DEE40: lui         $at, 0x200
    ctx->r1 = S32(0X200 << 16);
    // 0x800DEE44: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x800DEE48: sll         $t9, $a0, 1
    ctx->r25 = S32(ctx->r4 << 1);
    // 0x800DEE4C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800DEE50: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800DEE54: addiu       $t2, $t2, 0x8
    ctx->r10 = ADD32(ctx->r10, 0X8);
L_800DEE58:
    // 0x800DEE58: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
L_800DEE5C:
    // 0x800DEE5C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x800DEE60: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800DEE64: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x800DEE68: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x800DEE6C: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x800DEE70: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x800DEE74: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x800DEE78: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x800DEE7C: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x800DEE80: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x800DEE84: jr          $ra
    // 0x800DEE88: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x800DEE88: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    // 0x800DEE8C: nop

;}
RECOMP_FUNC void alResampleParam_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DEE90: addiu       $t6, $a1, -0x1
    ctx->r14 = ADD32(ctx->r5, -0X1);
    // 0x800DEE94: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800DEE98: sltiu       $at, $t6, 0x9
    ctx->r1 = ctx->r14 < 0X9 ? 1 : 0;
    // 0x800DEE9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DEEA0: beq         $at, $zero, L_800DEF50
    if (ctx->r1 == 0) {
        // 0x800DEEA4: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_800DEF50;
    }
    // 0x800DEEA4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800DEEA8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800DEEAC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800DEEB0: addu        $at, $at, $t6
    gpr jr_addend_800DEEB8 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800DEEB4: lw          $t6, -0x1D80($at)
    ctx->r14 = ADD32(ctx->r1, -0X1D80);
    // 0x800DEEB8: jr          $t6
    // 0x800DEEBC: nop

    switch (jr_addend_800DEEB8 >> 2) {
        case 0: goto L_800DEEC0; break;
        case 1: goto L_800DEF50; break;
        case 2: goto L_800DEF50; break;
        case 3: goto L_800DEEC8; break;
        case 4: goto L_800DEF50; break;
        case 5: goto L_800DEF50; break;
        case 6: goto L_800DEF34; break;
        case 7: goto L_800DEF44; break;
        case 8: goto L_800DEF04; break;
        default: switch_error(__func__, 0x800DEEB8, 0x800EE280);
    }
    // 0x800DEEBC: nop

L_800DEEC0:
    // 0x800DEEC0: b           L_800DEF68
    // 0x800DEEC4: sw          $a2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r6;
        goto L_800DEF68;
    // 0x800DEEC4: sw          $a2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r6;
L_800DEEC8:
    // 0x800DEEC8: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x800DEECC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800DEED0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800DEED4: sw          $t7, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r15;
    // 0x800DEED8: sw          $zero, 0x30($a3)
    MEM_W(0X30, ctx->r7) = 0;
    // 0x800DEEDC: sw          $zero, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = 0;
    // 0x800DEEE0: beq         $a0, $zero, L_800DEF68
    if (ctx->r4 == 0) {
        // 0x800DEEE4: swc1        $f4, 0x20($a3)
        MEM_W(0X20, ctx->r7) = ctx->f4.u32l;
            goto L_800DEF68;
    }
    // 0x800DEEE4: swc1        $f4, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->f4.u32l;
    // 0x800DEEE8: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800DEEEC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800DEEF0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800DEEF4: jalr        $t9
    // 0x800DEEF8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800DEEF8: nop

    after_0:
    // 0x800DEEFC: b           L_800DEF6C
    // 0x800DEF00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800DEF6C;
    // 0x800DEF00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800DEF04:
    // 0x800DEF04: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x800DEF08: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800DEF0C: sw          $t8, 0x30($a3)
    MEM_W(0X30, ctx->r7) = ctx->r24;
    // 0x800DEF10: beql        $a0, $zero, L_800DEF6C
    if (ctx->r4 == 0) {
        // 0x800DEF14: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800DEF6C;
    }
    goto skip_0;
    // 0x800DEF14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800DEF18: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800DEF1C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x800DEF20: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800DEF24: jalr        $t9
    // 0x800DEF28: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800DEF28: nop

    after_1:
    // 0x800DEF2C: b           L_800DEF6C
    // 0x800DEF30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800DEF6C;
    // 0x800DEF30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800DEF34:
    // 0x800DEF34: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x800DEF38: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800DEF3C: b           L_800DEF68
    // 0x800DEF40: swc1        $f6, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->f6.u32l;
        goto L_800DEF68;
    // 0x800DEF40: swc1        $f6, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->f6.u32l;
L_800DEF44:
    // 0x800DEF44: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800DEF48: b           L_800DEF68
    // 0x800DEF4C: sw          $t0, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r8;
        goto L_800DEF68;
    // 0x800DEF4C: sw          $t0, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r8;
L_800DEF50:
    // 0x800DEF50: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x800DEF54: beql        $a0, $zero, L_800DEF6C
    if (ctx->r4 == 0) {
        // 0x800DEF58: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800DEF6C;
    }
    goto skip_1;
    // 0x800DEF58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800DEF5C: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800DEF60: jalr        $t9
    // 0x800DEF64: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x800DEF64: nop

    after_2:
L_800DEF68:
    // 0x800DEF68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800DEF6C:
    // 0x800DEF6C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800DEF70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800DEF74: jr          $ra
    // 0x800DEF78: nop

    return;
    // 0x800DEF78: nop

;}
RECOMP_FUNC void alResamplePull_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DEF7C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800DEF80: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800DEF84: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x800DEF88: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x800DEF8C: addiu       $t6, $zero, 0x140
    ctx->r14 = ADD32(0, 0X140);
    // 0x800DEF90: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x800DEF94: or          $t2, $a2, $zero
    ctx->r10 = ctx->r6 | 0;
    // 0x800DEF98: bne         $a2, $zero, L_800DEFA8
    if (ctx->r6 != 0) {
        // 0x800DEF9C: sh          $t6, 0x46($sp)
        MEM_H(0X46, ctx->r29) = ctx->r14;
            goto L_800DEFA8;
    }
    // 0x800DEF9C: sh          $t6, 0x46($sp)
    MEM_H(0X46, ctx->r29) = ctx->r14;
    // 0x800DEFA0: b           L_800DF174
    // 0x800DEFA4: lw          $v0, 0x60($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X60);
        goto L_800DF174;
    // 0x800DEFA4: lw          $v0, 0x60($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X60);
L_800DEFA8:
    // 0x800DEFA8: lw          $t7, 0x1C($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X1C);
    // 0x800DEFAC: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x800DEFB0: beql        $t7, $zero, L_800DF01C
    if (ctx->r15 == 0) {
        // 0x800DEFB4: lwc1        $f2, 0x18($t0)
        ctx->f2.u32l = MEM_W(ctx->r8, 0X18);
            goto L_800DF01C;
    }
    goto skip_0;
    // 0x800DEFB4: lwc1        $f2, 0x18($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0X18);
    skip_0:
    // 0x800DEFB8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800DEFBC: sw          $t2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r10;
    // 0x800DEFC0: lw          $t9, 0x4($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X4);
    // 0x800DEFC4: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x800DEFC8: addiu       $a1, $sp, 0x46
    ctx->r5 = ADD32(ctx->r29, 0X46);
    // 0x800DEFCC: jalr        $t9
    // 0x800DEFD0: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800DEFD0: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    after_0:
    // 0x800DEFD4: lh          $t3, 0x46($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X46);
    // 0x800DEFD8: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800DEFDC: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800DEFE0: and         $t4, $t3, $at
    ctx->r12 = ctx->r11 & ctx->r1;
    // 0x800DEFE4: lui         $at, 0xA00
    ctx->r1 = S32(0XA00 << 16);
    // 0x800DEFE8: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x800DEFEC: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x800DEFF0: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800DEFF4: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x800DEFF8: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x800DEFFC: andi        $t4, $t3, 0xFFFF
    ctx->r12 = ctx->r11 & 0XFFFF;
    // 0x800DF000: lh          $t8, 0x0($t6)
    ctx->r24 = MEM_H(ctx->r14, 0X0);
    // 0x800DF004: addiu       $a1, $v0, 0x8
    ctx->r5 = ADD32(ctx->r2, 0X8);
    // 0x800DF008: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800DF00C: or          $t5, $t9, $t4
    ctx->r13 = ctx->r25 | ctx->r12;
    // 0x800DF010: b           L_800DF170
    // 0x800DF014: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
        goto L_800DF170;
    // 0x800DF014: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x800DF018: lwc1        $f2, 0x18($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0X18);
L_800DF01C:
    // 0x800DF01C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800DF020: ldc1        $f4, -0x1D58($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X1D58);
    // 0x800DF024: cvt.d.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.d = CVT_D_S(ctx->f2.fl);
    // 0x800DF028: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800DF02C: c.lt.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d < ctx->f6.d;
    // 0x800DF030: nop

    // 0x800DF034: bc1fl       L_800DF04C
    if (!c1cs) {
        // 0x800DF038: lui         $at, 0x4700
        ctx->r1 = S32(0X4700 << 16);
            goto L_800DF04C;
    }
    goto skip_1;
    // 0x800DF038: lui         $at, 0x4700
    ctx->r1 = S32(0X4700 << 16);
    skip_1:
    // 0x800DF03C: lwc1        $f8, -0x1D50($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1D50);
    // 0x800DF040: swc1        $f8, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->f8.u32l;
    // 0x800DF044: lwc1        $f2, 0x18($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0X18);
    // 0x800DF048: lui         $at, 0x4700
    ctx->r1 = S32(0X4700 << 16);
L_800DF04C:
    // 0x800DF04C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800DF050: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x800DF054: addiu       $a1, $sp, 0x46
    ctx->r5 = ADD32(ctx->r29, 0X46);
    // 0x800DF058: mul.s       $f10, $f2, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x800DF05C: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800DF060: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x800DF064: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x800DF068: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x800DF06C: nop

    // 0x800DF070: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800DF074: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800DF078: swc1        $f4, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->f4.u32l;
    // 0x800DF07C: lwc1        $f6, 0x18($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X18);
    // 0x800DF080: div.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f12.fl);
    // 0x800DF084: lwc1        $f6, 0x20($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X20);
    // 0x800DF088: swc1        $f8, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->f8.u32l;
    // 0x800DF08C: lwc1        $f10, 0x18($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X18);
    // 0x800DF090: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800DF094: add.s       $f0, $f6, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800DF098: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800DF09C: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x800DF0A0: nop

    // 0x800DF0A4: mtc1        $a2, $f16
    ctx->f16.u32l = ctx->r6;
    // 0x800DF0A8: nop

    // 0x800DF0AC: cvt.s.w     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800DF0B0: sub.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x800DF0B4: swc1        $f18, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->f18.u32l;
    // 0x800DF0B8: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
    // 0x800DF0BC: sw          $t2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r10;
    // 0x800DF0C0: sw          $t0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r8;
    // 0x800DF0C4: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800DF0C8: lw          $t9, 0x4($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X4);
    // 0x800DF0CC: jalr        $t9
    // 0x800DF0D0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800DF0D0: nop

    after_1:
    // 0x800DF0D4: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x800DF0D8: lh          $t5, 0x46($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X46);
    // 0x800DF0DC: lui         $at, 0x4700
    ctx->r1 = S32(0X4700 << 16);
    // 0x800DF0E0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800DF0E4: lwc1        $f6, 0x18($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X18);
    // 0x800DF0E8: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x800DF0EC: andi        $t6, $t5, 0xFFFF
    ctx->r14 = ctx->r13 & 0XFFFF;
    // 0x800DF0F0: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x800DF0F4: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x800DF0F8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800DF0FC: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x800DF100: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800DF104: sll         $t5, $t2, 1
    ctx->r13 = S32(ctx->r10 << 1);
    // 0x800DF108: lh          $t9, 0x0($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X0);
    // 0x800DF10C: andi        $t6, $t5, 0xFFFF
    ctx->r14 = ctx->r13 & 0XFFFF;
    // 0x800DF110: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800DF114: sll         $t4, $t9, 16
    ctx->r12 = S32(ctx->r25 << 16);
    // 0x800DF118: or          $t7, $t4, $t6
    ctx->r15 = ctx->r12 | ctx->r14;
    // 0x800DF11C: trunc.w.s   $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800DF120: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800DF124: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x800DF128: lw          $t3, 0x24($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X24);
    // 0x800DF12C: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x800DF130: lui         $at, 0x500
    ctx->r1 = S32(0X500 << 16);
    // 0x800DF134: andi        $t9, $t3, 0xFF
    ctx->r25 = ctx->r11 & 0XFF;
    // 0x800DF138: sll         $t5, $t9, 16
    ctx->r13 = S32(ctx->r25 << 16);
    // 0x800DF13C: or          $t4, $t5, $at
    ctx->r12 = ctx->r13 | ctx->r1;
    // 0x800DF140: andi        $t6, $v1, 0xFFFF
    ctx->r14 = ctx->r3 & 0XFFFF;
    // 0x800DF144: or          $t7, $t4, $t6
    ctx->r15 = ctx->r12 | ctx->r14;
    // 0x800DF148: sw          $t7, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r15;
    // 0x800DF14C: addiu       $a1, $v0, 0x10
    ctx->r5 = ADD32(ctx->r2, 0X10);
    // 0x800DF150: lw          $a0, 0x14($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X14);
    // 0x800DF154: jal         0x800D70A0
    // 0x800DF158: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_2;
    // 0x800DF158: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
    after_2:
    // 0x800DF15C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800DF160: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x800DF164: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x800DF168: sw          $v0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r2;
    // 0x800DF16C: sw          $zero, 0x24($t0)
    MEM_W(0X24, ctx->r8) = 0;
L_800DF170:
    // 0x800DF170: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_800DF174:
    // 0x800DF174: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800DF178: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x800DF17C: jr          $ra
    // 0x800DF180: nop

    return;
    // 0x800DF180: nop

    // 0x800DF184: nop

    // 0x800DF188: nop

    // 0x800DF18C: nop

;}
RECOMP_FUNC void _ldexpf_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DF190: beq         $a2, $zero, L_800DF1B0
    if (ctx->r6 == 0) {
        // 0x800DF194: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_800DF1B0;
    }
    // 0x800DF194: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800DF198: sllv        $t7, $t6, $a2
    ctx->r15 = S32(ctx->r14 << (ctx->r6 & 31));
    // 0x800DF19C: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800DF1A0: nop

    // 0x800DF1A4: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x800DF1A8: mul.d       $f12, $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f6.d); 
    ctx->f12.d = MUL_D(ctx->f12.d, ctx->f6.d);
    // 0x800DF1AC: nop

L_800DF1B0:
    // 0x800DF1B0: jr          $ra
    // 0x800DF1B4: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
    return;
    // 0x800DF1B4: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
;}
RECOMP_FUNC void _frexpf_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DF1B8: mtc1        $zero, $f3
    ctx->f_odd[(3 - 1) * 2] = 0;
    // 0x800DF1BC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800DF1C0: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x800DF1C4: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800DF1C8: c.eq.d      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.d == ctx->f2.d;
    // 0x800DF1CC: nop

    // 0x800DF1D0: bc1fl       L_800DF1E4
    if (!c1cs) {
        // 0x800DF1D4: c.lt.d      $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.d < ctx->f12.d;
            goto L_800DF1E4;
    }
    goto skip_0;
    // 0x800DF1D4: c.lt.d      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.d < ctx->f12.d;
    skip_0:
    // 0x800DF1D8: jr          $ra
    // 0x800DF1DC: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
    return;
    // 0x800DF1DC: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
    // 0x800DF1E0: c.lt.d      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.d < ctx->f12.d;
L_800DF1E4:
    // 0x800DF1E4: mtc1        $at, $f15
    ctx->f_odd[(15 - 1) * 2] = ctx->r1;
    // 0x800DF1E8: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800DF1EC: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800DF1F0: bc1fl       L_800DF204
    if (!c1cs) {
        // 0x800DF1F4: neg.d       $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.d); 
    ctx->f0.d = -ctx->f12.d;
            goto L_800DF204;
    }
    goto skip_1;
    // 0x800DF1F4: neg.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.d); 
    ctx->f0.d = -ctx->f12.d;
    skip_1:
    // 0x800DF1F8: b           L_800DF204
    // 0x800DF1FC: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
        goto L_800DF204;
    // 0x800DF1FC: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
    // 0x800DF200: neg.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.d); 
    ctx->f0.d = -ctx->f12.d;
L_800DF204:
    // 0x800DF204: c.le.d      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.d <= ctx->f0.d;
    // 0x800DF208: nop

    // 0x800DF20C: bc1fl       L_800DF244
    if (!c1cs) {
        // 0x800DF210: lui         $at, 0x3FE0
        ctx->r1 = S32(0X3FE0 << 16);
            goto L_800DF244;
    }
    goto skip_2;
    // 0x800DF210: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    skip_2:
    // 0x800DF214: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800DF218: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800DF21C: nop

L_800DF220:
    // 0x800DF220: mul.d       $f0, $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f16.d); 
    ctx->f0.d = MUL_D(ctx->f0.d, ctx->f16.d);
    // 0x800DF224: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800DF228: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800DF22C: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x800DF230: c.le.d      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.d <= ctx->f0.d;
    // 0x800DF234: nop

    // 0x800DF238: bc1t        L_800DF220
    if (c1cs) {
        // 0x800DF23C: nop
    
            goto L_800DF220;
    }
    // 0x800DF23C: nop

    // 0x800DF240: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
L_800DF244:
    // 0x800DF244: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800DF248: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800DF24C: nop

    // 0x800DF250: c.lt.d      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.d < ctx->f16.d;
    // 0x800DF254: nop

    // 0x800DF258: bc1fl       L_800DF280
    if (!c1cs) {
        // 0x800DF25C: c.lt.d      $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.d < ctx->f12.d;
            goto L_800DF280;
    }
    goto skip_3;
    // 0x800DF25C: c.lt.d      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.d < ctx->f12.d;
    skip_3:
    // 0x800DF260: add.d       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = ctx->f0.d + ctx->f0.d;
L_800DF264:
    // 0x800DF264: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800DF268: c.lt.d      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.d < ctx->f16.d;
    // 0x800DF26C: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800DF270: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800DF274: bc1tl       L_800DF264
    if (c1cs) {
        // 0x800DF278: add.d       $f0, $f0, $f0
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = ctx->f0.d + ctx->f0.d;
            goto L_800DF264;
    }
    goto skip_4;
    // 0x800DF278: add.d       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = ctx->f0.d + ctx->f0.d;
    skip_4:
    // 0x800DF27C: c.lt.d      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.d < ctx->f12.d;
L_800DF280:
    // 0x800DF280: nop

    // 0x800DF284: bc1fl       L_800DF298
    if (!c1cs) {
        // 0x800DF288: neg.d       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = -ctx->f0.d;
            goto L_800DF298;
    }
    goto skip_5;
    // 0x800DF288: neg.d       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = -ctx->f0.d;
    skip_5:
    // 0x800DF28C: b           L_800DF298
    // 0x800DF290: mov.d       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.d = ctx->f0.d;
        goto L_800DF298;
    // 0x800DF290: mov.d       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.d = ctx->f0.d;
    // 0x800DF294: neg.d       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = -ctx->f0.d;
L_800DF298:
    // 0x800DF298: mov.d       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.d = ctx->f2.d;
    // 0x800DF29C: jr          $ra
    // 0x800DF2A0: nop

    return;
    // 0x800DF2A0: nop

;}
RECOMP_FUNC void alEnvmixerParam_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DF2A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DF2A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800DF2AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DF2B0: beq         $a1, $v0, L_800DF350
    if (ctx->r5 == ctx->r2) {
        // 0x800DF2B4: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_800DF350;
    }
    // 0x800DF2B4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800DF2B8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800DF2BC: beq         $a1, $at, L_800DF2DC
    if (ctx->r5 == ctx->r1) {
        // 0x800DF2C0: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_800DF2DC;
    }
    // 0x800DF2C0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800DF2C4: beq         $a1, $at, L_800DF2FC
    if (ctx->r5 == ctx->r1) {
        // 0x800DF2C8: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_800DF2FC;
    }
    // 0x800DF2C8: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x800DF2CC: beql        $a1, $at, L_800DF32C
    if (ctx->r5 == ctx->r1) {
        // 0x800DF2D0: lw          $a0, 0x0($a3)
        ctx->r4 = MEM_W(ctx->r7, 0X0);
            goto L_800DF32C;
    }
    goto skip_0;
    // 0x800DF2D0: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    skip_0:
    // 0x800DF2D4: b           L_800DF35C
    // 0x800DF2D8: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
        goto L_800DF35C;
    // 0x800DF2D8: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
L_800DF2DC:
    // 0x800DF2DC: lw          $v0, 0x40($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X40);
    // 0x800DF2E0: beql        $v0, $zero, L_800DF2F4
    if (ctx->r2 == 0) {
        // 0x800DF2E4: sw          $a2, 0x3C($a3)
        MEM_W(0X3C, ctx->r7) = ctx->r6;
            goto L_800DF2F4;
    }
    goto skip_1;
    // 0x800DF2E4: sw          $a2, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->r6;
    skip_1:
    // 0x800DF2E8: b           L_800DF2F4
    // 0x800DF2EC: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
        goto L_800DF2F4;
    // 0x800DF2EC: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
    // 0x800DF2F0: sw          $a2, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->r6;
L_800DF2F4:
    // 0x800DF2F4: b           L_800DF370
    // 0x800DF2F8: sw          $a2, 0x40($a3)
    MEM_W(0X40, ctx->r7) = ctx->r6;
        goto L_800DF370;
    // 0x800DF2F8: sw          $a2, 0x40($a3)
    MEM_W(0X40, ctx->r7) = ctx->r6;
L_800DF2FC:
    // 0x800DF2FC: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x800DF300: sw          $v0, 0x38($a3)
    MEM_W(0X38, ctx->r7) = ctx->r2;
    // 0x800DF304: sw          $zero, 0x48($a3)
    MEM_W(0X48, ctx->r7) = 0;
    // 0x800DF308: beq         $a0, $zero, L_800DF370
    if (ctx->r4 == 0) {
        // 0x800DF30C: sh          $v0, 0x1A($a3)
        MEM_H(0X1A, ctx->r7) = ctx->r2;
            goto L_800DF370;
    }
    // 0x800DF30C: sh          $v0, 0x1A($a3)
    MEM_H(0X1A, ctx->r7) = ctx->r2;
    // 0x800DF310: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800DF314: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800DF318: jalr        $t9
    // 0x800DF31C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800DF31C: nop

    after_0:
    // 0x800DF320: b           L_800DF374
    // 0x800DF324: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800DF374;
    // 0x800DF324: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DF328: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
L_800DF32C:
    // 0x800DF32C: sw          $v0, 0x48($a3)
    MEM_W(0X48, ctx->r7) = ctx->r2;
    // 0x800DF330: beql        $a0, $zero, L_800DF374
    if (ctx->r4 == 0) {
        // 0x800DF334: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800DF374;
    }
    goto skip_2;
    // 0x800DF334: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x800DF338: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800DF33C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x800DF340: jalr        $t9
    // 0x800DF344: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800DF344: nop

    after_1:
    // 0x800DF348: b           L_800DF374
    // 0x800DF34C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800DF374;
    // 0x800DF34C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800DF350:
    // 0x800DF350: b           L_800DF370
    // 0x800DF354: sw          $a2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r6;
        goto L_800DF370;
    // 0x800DF354: sw          $a2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r6;
    // 0x800DF358: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
L_800DF35C:
    // 0x800DF35C: beql        $a0, $zero, L_800DF374
    if (ctx->r4 == 0) {
        // 0x800DF360: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800DF374;
    }
    goto skip_3;
    // 0x800DF360: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x800DF364: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800DF368: jalr        $t9
    // 0x800DF36C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x800DF36C: nop

    after_2:
L_800DF370:
    // 0x800DF370: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800DF374:
    // 0x800DF374: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DF378: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800DF37C: jr          $ra
    // 0x800DF380: nop

    return;
    // 0x800DF380: nop

;}
RECOMP_FUNC void func_800DF384(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DF384: addiu       $sp, $sp, -0xE8
    ctx->r29 = ADD32(ctx->r29, -0XE8);
    // 0x800DF388: bne         $a0, $zero, L_800DF3B8
    if (ctx->r4 != 0) {
        // 0x800DF38C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800DF3B8;
    }
    // 0x800DF38C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DF390: c.le.d      $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f16.d <= ctx->f14.d;
    // 0x800DF394: ori         $t6, $zero, 0xFFFF
    ctx->r14 = 0 | 0XFFFF;
    // 0x800DF398: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800DF39C: bc1f        L_800DF3B0
    if (!c1cs) {
        // 0x800DF3A0: nop
    
            goto L_800DF3B0;
    }
    // 0x800DF3A0: nop

    // 0x800DF3A4: sh          $t6, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r14;
    // 0x800DF3A8: b           L_800DF544
    // 0x800DF3AC: addiu       $v0, $zero, 0x7FFF
    ctx->r2 = ADD32(0, 0X7FFF);
        goto L_800DF544;
    // 0x800DF3AC: addiu       $v0, $zero, 0x7FFF
    ctx->r2 = ADD32(0, 0X7FFF);
L_800DF3B0:
    // 0x800DF3B0: b           L_800DF544
    // 0x800DF3B4: sh          $zero, 0x0($s1)
    MEM_H(0X0, ctx->r17) = 0;
        goto L_800DF544;
    // 0x800DF3B4: sh          $zero, 0x0($s1)
    MEM_H(0X0, ctx->r17) = 0;
L_800DF3B8:
    // 0x800DF3B8: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800DF3BC: mtc1        $at, $f23
    ctx->f_odd[(23 - 1) * 2] = ctx->r1;
    // 0x800DF3C0: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x800DF3C4: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x800DF3C8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800DF3CC: c.lt.d      $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f14.d < ctx->f22.d;
    // 0x800DF3D0: addiu       $s2, $sp, 0x68
    ctx->r18 = ADD32(ctx->r29, 0X68);
    // 0x800DF3D4: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x800DF3D8: addiu       $t7, $t7, -0x2DE0
    ctx->r15 = ADD32(ctx->r15, -0X2DE0);
    // 0x800DF3DC: bc1f        L_800DF3E8
    if (!c1cs) {
        // 0x800DF3E0: or          $t6, $s2, $zero
        ctx->r14 = ctx->r18 | 0;
            goto L_800DF3E8;
    }
    // 0x800DF3E0: or          $t6, $s2, $zero
    ctx->r14 = ctx->r18 | 0;
    // 0x800DF3E4: mov.d       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.d = ctx->f22.d;
L_800DF3E8:
    // 0x800DF3E8: c.le.d      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.d <= ctx->f4.d;
    // 0x800DF3EC: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800DF3F0: addiu       $t9, $t7, 0x3C
    ctx->r25 = ADD32(ctx->r15, 0X3C);
    // 0x800DF3F4: bc1f        L_800DF408
    if (!c1cs) {
        // 0x800DF3F8: nop
    
            goto L_800DF408;
    }
    // 0x800DF3F8: nop

    // 0x800DF3FC: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800DF400: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800DF404: nop

L_800DF408:
    // 0x800DF408: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x800DF40C: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x800DF410: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x800DF414: sw          $at, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r1;
    // 0x800DF418: lw          $at, -0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, -0X8);
    // 0x800DF41C: sw          $at, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r1;
    // 0x800DF420: lw          $at, -0x4($t7)
    ctx->r1 = MEM_W(ctx->r15, -0X4);
    // 0x800DF424: bne         $t7, $t9, L_800DF408
    if (ctx->r15 != ctx->r25) {
        // 0x800DF428: sw          $at, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r1;
            goto L_800DF408;
    }
    // 0x800DF428: sw          $at, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r1;
    // 0x800DF42C: mtc1        $a0, $f8
    ctx->f8.u32l = ctx->r4;
    // 0x800DF430: lui         $t8, 0x4000
    ctx->r24 = S32(0X4000 << 16);
    // 0x800DF434: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x800DF438: cvt.d.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.d = CVT_D_W(ctx->f8.u32l);
    // 0x800DF43C: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x800DF440: addiu       $a2, $sp, 0xB0
    ctx->r6 = ADD32(ctx->r29, 0XB0);
    // 0x800DF444: cvt.d.w     $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    ctx->f20.d = CVT_D_W(ctx->f6.u32l);
    // 0x800DF448: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x800DF44C: div.d       $f4, $f22, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f22.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = DIV_D(ctx->f22.d, ctx->f10.d);
    // 0x800DF450: div.d       $f12, $f14, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f16.d); 
    ctx->f12.d = DIV_D(ctx->f14.d, ctx->f16.d);
    // 0x800DF454: mul.d       $f2, $f4, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f20.d); 
    ctx->f2.d = MUL_D(ctx->f4.d, ctx->f20.d);
    // 0x800DF458: trunc.w.d   $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    ctx->f6.u32l = TRUNC_W_D(ctx->f2.d);
    // 0x800DF45C: mfc1        $s0, $f6
    ctx->r16 = (int32_t)ctx->f6.u32l;
    // 0x800DF460: jal         0x800DF1B8
    // 0x800DF464: nop

    _frexpf_recomp(rdram, ctx);
        goto after_0;
    // 0x800DF464: nop

    after_0:
    // 0x800DF468: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x800DF46C: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800DF470: lw          $t6, 0xB0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB0);
    // 0x800DF474: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800DF478: cvt.d.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.d = CVT_D_W(ctx->f8.u32l);
    // 0x800DF47C: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x800DF480: mul.d       $f2, $f0, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f10.d); 
    ctx->f2.d = MUL_D(ctx->f0.d, ctx->f10.d);
    // 0x800DF484: cvt.d.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.d = CVT_D_W(ctx->f8.u32l);
    // 0x800DF488: ldc1        $f8, -0x1D40($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X1D40);
    // 0x800DF48C: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800DF490: trunc.w.d   $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    ctx->f4.u32l = TRUNC_W_D(ctx->f2.d);
    // 0x800DF494: mov.d       $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    ctx->f2.d = ctx->f22.d;
    // 0x800DF498: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x800DF49C: nop

    // 0x800DF4A0: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x800DF4A4: addu        $t7, $s2, $t9
    ctx->r15 = ADD32(ctx->r18, ctx->r25);
    // 0x800DF4A8: ldc1        $f6, -0x40($t7)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r15, -0X40);
    // 0x800DF4AC: add.d       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f6.d + ctx->f10.d;
    // 0x800DF4B0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800DF4B4: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800DF4B8: mul.d       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f12.d = MUL_D(ctx->f4.d, ctx->f8.d);
    // 0x800DF4BC: nop

    // 0x800DF4C0: mul.d       $f14, $f6, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f20.d); 
    ctx->f14.d = MUL_D(ctx->f6.d, ctx->f20.d);
    // 0x800DF4C4: div.d       $f12, $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f14.d); 
    ctx->f12.d = DIV_D(ctx->f12.d, ctx->f14.d);
    // 0x800DF4C8: beq         $s0, $zero, L_800DF4F0
    if (ctx->r16 == 0) {
        // 0x800DF4CC: add.d       $f0, $f22, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f22.d); NAN_CHECK(ctx->f12.d); 
    ctx->f0.d = ctx->f22.d + ctx->f12.d;
            goto L_800DF4F0;
    }
    // 0x800DF4CC: add.d       $f0, $f22, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f22.d); NAN_CHECK(ctx->f12.d); 
    ctx->f0.d = ctx->f22.d + ctx->f12.d;
L_800DF4D0:
    // 0x800DF4D0: andi        $t8, $s0, 0x1
    ctx->r24 = ctx->r16 & 0X1;
    // 0x800DF4D4: beq         $t8, $zero, L_800DF4E4
    if (ctx->r24 == 0) {
        // 0x800DF4D8: sra         $t9, $s0, 1
        ctx->r25 = S32(SIGNED(ctx->r16) >> 1);
            goto L_800DF4E4;
    }
    // 0x800DF4D8: sra         $t9, $s0, 1
    ctx->r25 = S32(SIGNED(ctx->r16) >> 1);
    // 0x800DF4DC: mul.d       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f0.d); 
    ctx->f2.d = MUL_D(ctx->f2.d, ctx->f0.d);
    // 0x800DF4E0: nop

L_800DF4E4:
    // 0x800DF4E4: mul.d       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = MUL_D(ctx->f0.d, ctx->f0.d);
    // 0x800DF4E8: bne         $t9, $zero, L_800DF4D0
    if (ctx->r25 != 0) {
        // 0x800DF4EC: or          $s0, $t9, $zero
        ctx->r16 = ctx->r25 | 0;
            goto L_800DF4D0;
    }
    // 0x800DF4EC: or          $s0, $t9, $zero
    ctx->r16 = ctx->r25 | 0;
L_800DF4F0:
    // 0x800DF4F0: mul.d       $f0, $f2, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = MUL_D(ctx->f2.d, ctx->f2.d);
    // 0x800DF4F4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800DF4F8: mul.d       $f12, $f0, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f12.d = MUL_D(ctx->f0.d, ctx->f0.d);
    // 0x800DF4FC: nop

    // 0x800DF500: mul.d       $f2, $f12, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f12.d); 
    ctx->f2.d = MUL_D(ctx->f12.d, ctx->f12.d);
    // 0x800DF504: trunc.w.d   $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    ctx->f10.u32l = TRUNC_W_D(ctx->f2.d);
    // 0x800DF508: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x800DF50C: nop

    // 0x800DF510: sll         $t6, $v1, 16
    ctx->r14 = S32(ctx->r3 << 16);
    // 0x800DF514: sra         $v0, $t6, 16
    ctx->r2 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800DF518: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800DF51C: nop

    // 0x800DF520: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800DF524: ldc1        $f4, -0x1D38($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X1D38);
    // 0x800DF528: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x800DF52C: sub.d       $f10, $f2, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f2.d - ctx->f6.d;
    // 0x800DF530: mul.d       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = MUL_D(ctx->f10.d, ctx->f4.d);
    // 0x800DF534: trunc.w.d   $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = TRUNC_W_D(ctx->f8.d);
    // 0x800DF538: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x800DF53C: nop

    // 0x800DF540: sh          $t7, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r15;
L_800DF544:
    // 0x800DF544: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DF548: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
    // 0x800DF54C: jr          $ra
    // 0x800DF550: nop

    return;
    // 0x800DF550: nop

;}
RECOMP_FUNC void func_800DF554(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DF554: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800DF558: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800DF55C: lw          $t6, 0x48($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X48);
    // 0x800DF560: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800DF564: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x800DF568: bne         $t6, $at, L_800DF578
    if (ctx->r14 != ctx->r1) {
        // 0x800DF56C: nop
    
            goto L_800DF578;
    }
    // 0x800DF56C: nop

    // 0x800DF570: bnel        $s5, $zero, L_800DF584
    if (ctx->r21 != 0) {
        // 0x800DF574: sw          $t0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r8;
            goto L_800DF584;
    }
    goto skip_0;
    // 0x800DF574: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    skip_0:
L_800DF578:
    // 0x800DF578: b           L_800DF7DC
    // 0x800DF57C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
        goto L_800DF7DC;
    // 0x800DF57C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x800DF580: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
L_800DF584:
    // 0x800DF584: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x800DF588: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x800DF58C: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x800DF590: jalr        $t9
    // 0x800DF594: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800DF594: nop

    after_0:
    // 0x800DF598: lh          $t7, 0x0($s6)
    ctx->r15 = MEM_H(ctx->r22, 0X0);
    // 0x800DF59C: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x800DF5A0: sll         $s7, $s5, 1
    ctx->r23 = S32(ctx->r21 << 1);
    // 0x800DF5A4: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x800DF5A8: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x800DF5AC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800DF5B0: lh          $t9, 0x0($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X0);
    // 0x800DF5B4: lui         $at, 0x808
    ctx->r1 = S32(0X808 << 16);
    // 0x800DF5B8: addiu       $s4, $v0, 0x10
    ctx->r20 = ADD32(ctx->r2, 0X10);
    // 0x800DF5BC: addiu       $t8, $t9, 0x440
    ctx->r24 = ADD32(ctx->r25, 0X440);
    // 0x800DF5C0: sll         $t6, $t8, 16
    ctx->r14 = S32(ctx->r24 << 16);
    // 0x800DF5C4: andi        $t9, $s7, 0xFFFF
    ctx->r25 = ctx->r23 & 0XFFFF;
    // 0x800DF5C8: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x800DF5CC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800DF5D0: lh          $t8, 0x0($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X0);
    // 0x800DF5D4: addiu       $t6, $t8, 0x580
    ctx->r14 = ADD32(ctx->r24, 0X580);
    // 0x800DF5D8: andi        $t9, $t6, 0xFFFF
    ctx->r25 = ctx->r14 & 0XFFFF;
    // 0x800DF5DC: or          $t7, $t9, $at
    ctx->r15 = ctx->r25 | ctx->r1;
    // 0x800DF5E0: sw          $t7, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r15;
    // 0x800DF5E4: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
    // 0x800DF5E8: or          $s0, $s4, $zero
    ctx->r16 = ctx->r20 | 0;
    // 0x800DF5EC: addiu       $t8, $v1, 0x800
    ctx->r24 = ADD32(ctx->r3, 0X800);
    // 0x800DF5F0: andi        $t6, $t8, 0xFFFF
    ctx->r14 = ctx->r24 & 0XFFFF;
    // 0x800DF5F4: addiu       $t7, $v1, 0x6C0
    ctx->r15 = ADD32(ctx->r3, 0X6C0);
    // 0x800DF5F8: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x800DF5FC: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x800DF600: sw          $t9, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r25;
    // 0x800DF604: lw          $t7, 0x38($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X38);
    // 0x800DF608: lui         $t9, 0x800F
    ctx->r25 = S32(0X800F << 16);
    // 0x800DF60C: beql        $t7, $zero, L_800DF7AC
    if (ctx->r15 == 0) {
        // 0x800DF610: lui         $t7, 0x308
        ctx->r15 = S32(0X308 << 16);
            goto L_800DF7AC;
    }
    goto skip_1;
    // 0x800DF610: lui         $t7, 0x308
    ctx->r15 = S32(0X308 << 16);
    skip_1:
    // 0x800DF614: lh          $t6, 0x18($s3)
    ctx->r14 = MEM_H(ctx->r19, 0X18);
    // 0x800DF618: sw          $zero, 0x38($s3)
    MEM_W(0X38, ctx->r19) = 0;
    // 0x800DF61C: lh          $t7, 0x1A($s3)
    ctx->r15 = MEM_H(ctx->r19, 0X1A);
    // 0x800DF620: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x800DF624: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800DF628: lh          $t9, -0x2EE0($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X2EE0);
    // 0x800DF62C: lw          $a0, 0x34($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X34);
    // 0x800DF630: addiu       $s1, $s3, 0x24
    ctx->r17 = ADD32(ctx->r19, 0X24);
    // 0x800DF634: multu       $t9, $t7
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800DF638: lh          $t9, 0x1C($s3)
    ctx->r25 = MEM_H(ctx->r19, 0X1C);
    // 0x800DF63C: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x800DF640: nop

    // 0x800DF644: cvt.d.w     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.d = CVT_D_W(ctx->f4.u32l);
    // 0x800DF648: mflo        $t6
    ctx->r14 = lo;
    // 0x800DF64C: sra         $t8, $t6, 15
    ctx->r24 = S32(SIGNED(ctx->r14) >> 15);
    // 0x800DF650: sh          $t8, 0x28($s3)
    MEM_H(0X28, ctx->r19) = ctx->r24;
    // 0x800DF654: lh          $t7, 0x28($s3)
    ctx->r15 = MEM_H(ctx->r19, 0X28);
    // 0x800DF658: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x800DF65C: jal         0x800DF384
    // 0x800DF660: cvt.d.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.d = CVT_D_W(ctx->f6.u32l);
    func_800DF384(rdram, ctx);
        goto after_1;
    // 0x800DF660: cvt.d.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.d = CVT_D_W(ctx->f6.u32l);
    after_1:
    // 0x800DF664: lh          $t6, 0x18($s3)
    ctx->r14 = MEM_H(ctx->r19, 0X18);
    // 0x800DF668: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x800DF66C: sh          $v0, 0x26($s3)
    MEM_H(0X26, ctx->r19) = ctx->r2;
    // 0x800DF670: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x800DF674: negu        $t9, $t8
    ctx->r25 = SUB32(0, ctx->r24);
    // 0x800DF678: addu        $t7, $t7, $t9
    ctx->r15 = ADD32(ctx->r15, ctx->r25);
    // 0x800DF67C: lh          $t7, -0x2DE2($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X2DE2);
    // 0x800DF680: lh          $t6, 0x1A($s3)
    ctx->r14 = MEM_H(ctx->r19, 0X1A);
    // 0x800DF684: lw          $a0, 0x34($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X34);
    // 0x800DF688: addiu       $s1, $s3, 0x2A
    ctx->r17 = ADD32(ctx->r19, 0X2A);
    // 0x800DF68C: multu       $t7, $t6
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800DF690: lh          $t7, 0x1E($s3)
    ctx->r15 = MEM_H(ctx->r19, 0X1E);
    // 0x800DF694: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800DF698: nop

    // 0x800DF69C: cvt.d.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.d = CVT_D_W(ctx->f8.u32l);
    // 0x800DF6A0: mflo        $t8
    ctx->r24 = lo;
    // 0x800DF6A4: sra         $t9, $t8, 15
    ctx->r25 = S32(SIGNED(ctx->r24) >> 15);
    // 0x800DF6A8: sh          $t9, 0x2E($s3)
    MEM_H(0X2E, ctx->r19) = ctx->r25;
    // 0x800DF6AC: lh          $t6, 0x2E($s3)
    ctx->r14 = MEM_H(ctx->r19, 0X2E);
    // 0x800DF6B0: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x800DF6B4: jal         0x800DF384
    // 0x800DF6B8: cvt.d.w     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.d = CVT_D_W(ctx->f10.u32l);
    func_800DF384(rdram, ctx);
        goto after_2;
    // 0x800DF6B8: cvt.d.w     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.d = CVT_D_W(ctx->f10.u32l);
    after_2:
    // 0x800DF6BC: lh          $t8, 0x1C($s3)
    ctx->r24 = MEM_H(ctx->r19, 0X1C);
    // 0x800DF6C0: sh          $v0, 0x2C($s3)
    MEM_H(0X2C, ctx->r19) = ctx->r2;
    // 0x800DF6C4: or          $v1, $s4, $zero
    ctx->r3 = ctx->r20 | 0;
    // 0x800DF6C8: lui         $at, 0x906
    ctx->r1 = S32(0X906 << 16);
    // 0x800DF6CC: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x800DF6D0: or          $t7, $t9, $at
    ctx->r15 = ctx->r25 | ctx->r1;
    // 0x800DF6D4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800DF6D8: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800DF6DC: lh          $t6, 0x1E($s3)
    ctx->r14 = MEM_H(ctx->r19, 0X1E);
    // 0x800DF6E0: addiu       $s4, $s4, 0x8
    ctx->r20 = ADD32(ctx->r20, 0X8);
    // 0x800DF6E4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800DF6E8: lui         $at, 0x904
    ctx->r1 = S32(0X904 << 16);
    // 0x800DF6EC: andi        $t8, $t6, 0xFFFF
    ctx->r24 = ctx->r14 & 0XFFFF;
    // 0x800DF6F0: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x800DF6F4: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800DF6F8: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x800DF6FC: lh          $t7, 0x28($s3)
    ctx->r15 = MEM_H(ctx->r19, 0X28);
    // 0x800DF700: addiu       $s4, $s4, 0x8
    ctx->r20 = ADD32(ctx->r20, 0X8);
    // 0x800DF704: lui         $at, 0x902
    ctx->r1 = S32(0X902 << 16);
    // 0x800DF708: andi        $t6, $t7, 0xFFFF
    ctx->r14 = ctx->r15 & 0XFFFF;
    // 0x800DF70C: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x800DF710: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x800DF714: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x800DF718: lh          $t7, 0x26($s3)
    ctx->r15 = MEM_H(ctx->r19, 0X26);
    // 0x800DF71C: lhu         $t9, 0x24($s3)
    ctx->r25 = MEM_HU(ctx->r19, 0X24);
    // 0x800DF720: addiu       $s4, $s4, 0x8
    ctx->r20 = ADD32(ctx->r20, 0X8);
    // 0x800DF724: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x800DF728: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x800DF72C: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x800DF730: lh          $t8, 0x2E($s3)
    ctx->r24 = MEM_H(ctx->r19, 0X2E);
    // 0x800DF734: lui         $at, 0x900
    ctx->r1 = S32(0X900 << 16);
    // 0x800DF738: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x800DF73C: andi        $t6, $t8, 0xFFFF
    ctx->r14 = ctx->r24 & 0XFFFF;
    // 0x800DF740: or          $t9, $t6, $at
    ctx->r25 = ctx->r14 | ctx->r1;
    // 0x800DF744: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800DF748: lh          $t8, 0x2C($s3)
    ctx->r24 = MEM_H(ctx->r19, 0X2C);
    // 0x800DF74C: lhu         $t7, 0x2A($s3)
    ctx->r15 = MEM_HU(ctx->r19, 0X2A);
    // 0x800DF750: addiu       $s4, $s4, 0x8
    ctx->r20 = ADD32(ctx->r20, 0X8);
    // 0x800DF754: sll         $t6, $t8, 16
    ctx->r14 = S32(ctx->r24 << 16);
    // 0x800DF758: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x800DF75C: sw          $t8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r24;
    // 0x800DF760: lh          $t9, 0x20($s3)
    ctx->r25 = MEM_H(ctx->r19, 0X20);
    // 0x800DF764: lui         $at, 0x908
    ctx->r1 = S32(0X908 << 16);
    // 0x800DF768: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
    // 0x800DF76C: andi        $t6, $t9, 0xFFFF
    ctx->r14 = ctx->r25 & 0XFFFF;
    // 0x800DF770: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x800DF774: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800DF778: lh          $t8, 0x22($s3)
    ctx->r24 = MEM_H(ctx->r19, 0X22);
    // 0x800DF77C: addiu       $s4, $s4, 0x8
    ctx->r20 = ADD32(ctx->r20, 0X8);
    // 0x800DF780: or          $s0, $s4, $zero
    ctx->r16 = ctx->r20 | 0;
    // 0x800DF784: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x800DF788: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800DF78C: lui         $t6, 0x309
    ctx->r14 = S32(0X309 << 16);
    // 0x800DF790: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800DF794: lw          $a0, 0x14($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X14);
    // 0x800DF798: jal         0x800D70A0
    // 0x800DF79C: addiu       $s4, $s4, 0x8
    ctx->r20 = ADD32(ctx->r20, 0X8);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_3;
    // 0x800DF79C: addiu       $s4, $s4, 0x8
    ctx->r20 = ADD32(ctx->r20, 0X8);
    after_3:
    // 0x800DF7A0: b           L_800DF7C0
    // 0x800DF7A4: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
        goto L_800DF7C0;
    // 0x800DF7A4: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x800DF7A8: lui         $t7, 0x308
    ctx->r15 = S32(0X308 << 16);
L_800DF7AC:
    // 0x800DF7AC: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800DF7B0: lw          $a0, 0x14($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X14);
    // 0x800DF7B4: jal         0x800D70A0
    // 0x800DF7B8: addiu       $s4, $s4, 0x8
    ctx->r20 = ADD32(ctx->r20, 0X8);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_4;
    // 0x800DF7B8: addiu       $s4, $s4, 0x8
    ctx->r20 = ADD32(ctx->r20, 0X8);
    after_4:
    // 0x800DF7BC: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
L_800DF7C0:
    // 0x800DF7C0: lh          $t8, 0x0($s6)
    ctx->r24 = MEM_H(ctx->r22, 0X0);
    // 0x800DF7C4: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
    // 0x800DF7C8: addu        $t9, $t8, $s7
    ctx->r25 = ADD32(ctx->r24, ctx->r23);
    // 0x800DF7CC: sh          $t9, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r25;
    // 0x800DF7D0: lw          $t6, 0x30($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X30);
    // 0x800DF7D4: addu        $t7, $t6, $s5
    ctx->r15 = ADD32(ctx->r14, ctx->r21);
    // 0x800DF7D8: sw          $t7, 0x30($s3)
    MEM_W(0X30, ctx->r19) = ctx->r15;
L_800DF7DC:
    // 0x800DF7DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800DF7E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800DF7E4: jr          $ra
    // 0x800DF7E8: nop

    return;
    // 0x800DF7E8: nop

;}
RECOMP_FUNC void func_800DF7EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DF7EC: sw          $a1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r5;
    // 0x800DF7F0: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x800DF7F4: sw          $a2, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r6;
    // 0x800DF7F8: andi        $t8, $a2, 0xFFFF
    ctx->r24 = ctx->r6 & 0XFFFF;
    // 0x800DF7FC: sra         $t9, $a0, 3
    ctx->r25 = S32(SIGNED(ctx->r4) >> 3);
    // 0x800DF800: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x800DF804: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800DF808: bne         $t9, $zero, L_800DF818
    if (ctx->r25 != 0) {
        // 0x800DF80C: or          $a0, $t9, $zero
        ctx->r4 = ctx->r25 | 0;
            goto L_800DF818;
    }
    // 0x800DF80C: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x800DF810: jr          $ra
    // 0x800DF814: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    return;
    // 0x800DF814: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_800DF818:
    // 0x800DF818: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x800DF81C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800DF820: mtc1        $a2, $f8
    ctx->f8.u32l = ctx->r6;
    // 0x800DF824: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800DF828: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800DF82C: bgez        $a2, L_800DF844
    if (SIGNED(ctx->r6) >= 0) {
        // 0x800DF830: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_800DF844;
    }
    // 0x800DF830: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800DF834: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800DF838: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800DF83C: nop

    // 0x800DF840: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
L_800DF844:
    // 0x800DF844: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x800DF848: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800DF84C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800DF850: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800DF854: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800DF858: addiu       $v1, $zero, 0x20
    ctx->r3 = ADD32(0, 0X20);
    // 0x800DF85C: div.s       $f0, $f8, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f8.fl, ctx->f4.fl);
    // 0x800DF860: andi        $t7, $a0, 0x1
    ctx->r15 = ctx->r4 & 0X1;
L_800DF864:
    // 0x800DF864: beq         $t7, $zero, L_800DF874
    if (ctx->r15 == 0) {
        // 0x800DF868: sra         $t8, $a0, 1
        ctx->r24 = S32(SIGNED(ctx->r4) >> 1);
            goto L_800DF874;
    }
    // 0x800DF868: sra         $t8, $a0, 1
    ctx->r24 = S32(SIGNED(ctx->r4) >> 1);
    // 0x800DF86C: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800DF870: nop

L_800DF874:
    // 0x800DF874: beq         $t8, $zero, L_800DF88C
    if (ctx->r24 == 0) {
        // 0x800DF878: or          $a0, $t8, $zero
        ctx->r4 = ctx->r24 | 0;
            goto L_800DF88C;
    }
    // 0x800DF878: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x800DF87C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800DF880: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800DF884: bnel        $v0, $v1, L_800DF864
    if (ctx->r2 != ctx->r3) {
        // 0x800DF888: andi        $t7, $a0, 0x1
        ctx->r15 = ctx->r4 & 0X1;
            goto L_800DF864;
    }
    goto skip_0;
    // 0x800DF888: andi        $t7, $a0, 0x1
    ctx->r15 = ctx->r4 & 0X1;
    skip_0:
L_800DF88C:
    // 0x800DF88C: mul.s       $f0, $f12, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x800DF890: nop

    // 0x800DF894: jr          $ra
    // 0x800DF898: nop

    return;
    // 0x800DF898: nop

;}
RECOMP_FUNC void alEnvmixerPull_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DF89C: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x800DF8A0: lw          $t6, 0xB8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB8);
    // 0x800DF8A4: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x800DF8A8: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x800DF8AC: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x800DF8B0: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x800DF8B4: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x800DF8B8: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x800DF8BC: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x800DF8C0: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x800DF8C4: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x800DF8C8: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x800DF8CC: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x800DF8D0: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x800DF8D4: sw          $a1, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r5;
    // 0x800DF8D8: sw          $a2, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r6;
    // 0x800DF8DC: sw          $a3, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r7;
    // 0x800DF8E0: sw          $a0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r4;
    // 0x800DF8E4: sw          $a3, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r7;
    // 0x800DF8E8: sh          $zero, 0x8E($sp)
    MEM_H(0X8E, ctx->r29) = 0;
    // 0x800DF8EC: sh          $zero, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = 0;
    // 0x800DF8F0: sw          $t6, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r14;
    // 0x800DF8F4: lw          $t8, 0x3C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X3C);
    // 0x800DF8F8: or          $fp, $a0, $zero
    ctx->r30 = ctx->r4 | 0;
    // 0x800DF8FC: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x800DF900: beql        $t8, $zero, L_800DFD74
    if (ctx->r24 == 0) {
        // 0x800DF904: or          $s3, $fp, $zero
        ctx->r19 = ctx->r30 | 0;
            goto L_800DFD74;
    }
    goto skip_0;
    // 0x800DF904: or          $s3, $fp, $zero
    ctx->r19 = ctx->r30 | 0;
    skip_0:
    // 0x800DF908: lw          $v1, 0x3C($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X3C);
L_800DF90C:
    // 0x800DF90C: lw          $v0, 0x94($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X94);
    // 0x800DF910: lw          $t8, 0xB0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB0);
    // 0x800DF914: lw          $t9, 0x4($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X4);
    // 0x800DF918: subu        $t7, $t9, $v0
    ctx->r15 = SUB32(ctx->r25, ctx->r2);
    // 0x800DF91C: slt         $at, $t8, $t7
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800DF920: sw          $t7, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r15;
    // 0x800DF924: bne         $at, $zero, L_800DFD70
    if (ctx->r1 != 0) {
        // 0x800DF928: sw          $t9, 0x94($sp)
        MEM_W(0X94, ctx->r29) = ctx->r25;
            goto L_800DFD70;
    }
    // 0x800DF928: sw          $t9, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r25;
    // 0x800DF92C: lhu         $t9, 0x8($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X8);
    // 0x800DF930: sltiu       $at, $t9, 0x11
    ctx->r1 = ctx->r25 < 0X11 ? 1 : 0;
    // 0x800DF934: beq         $at, $zero, L_800DFCE8
    if (ctx->r1 == 0) {
        // 0x800DF938: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_800DFCE8;
    }
    // 0x800DF938: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800DF93C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800DF940: addu        $at, $at, $t9
    gpr jr_addend_800DF948 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800DF944: lw          $t9, -0x1D30($at)
    ctx->r25 = ADD32(ctx->r1, -0X1D30);
    // 0x800DF948: jr          $t9
    // 0x800DF94C: nop

    switch (jr_addend_800DF948 >> 2) {
        case 0: goto L_800DFCC8; break;
        case 1: goto L_800DFCE8; break;
        case 2: goto L_800DFCE8; break;
        case 3: goto L_800DFCE8; break;
        case 4: goto L_800DFCE8; break;
        case 5: goto L_800DFCE8; break;
        case 6: goto L_800DFCE8; break;
        case 7: goto L_800DFCE8; break;
        case 8: goto L_800DFCE8; break;
        case 9: goto L_800DFCE8; break;
        case 10: goto L_800DFCE8; break;
        case 11: goto L_800DFA90; break;
        case 12: goto L_800DFA90; break;
        case 13: goto L_800DF950; break;
        case 14: goto L_800DFC34; break;
        case 15: goto L_800DFC88; break;
        case 16: goto L_800DFA90; break;
        default: switch_error(__func__, 0x800DF948, 0x800EE2D0);
    }
    // 0x800DF94C: nop

L_800DF950:
    // 0x800DF950: lh          $t6, 0xA($v1)
    ctx->r14 = MEM_H(ctx->r3, 0XA);
    // 0x800DF954: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
    // 0x800DF958: beql        $t6, $zero, L_800DF978
    if (ctx->r14 == 0) {
        // 0x800DF95C: lw          $t9, 0x8($fp)
        ctx->r25 = MEM_W(ctx->r30, 0X8);
            goto L_800DF978;
    }
    goto skip_1;
    // 0x800DF95C: lw          $t9, 0x8($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X8);
    skip_1:
    // 0x800DF960: lw          $t9, 0x8($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X8);
    // 0x800DF964: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x800DF968: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x800DF96C: jalr        $t9
    // 0x800DF970: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800DF970: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800DF974: lw          $t9, 0x8($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X8);
L_800DF978:
    // 0x800DF978: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x800DF97C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x800DF980: jalr        $t9
    // 0x800DF984: lw          $a2, 0x18($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X18);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800DF984: lw          $a2, 0x18($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X18);
    after_1:
    // 0x800DF988: lw          $t9, 0x8($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X8);
    // 0x800DF98C: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x800DF990: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x800DF994: jalr        $t9
    // 0x800DF998: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x800DF998: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x800DF99C: sw          $s1, 0x38($fp)
    MEM_W(0X38, ctx->r30) = ctx->r17;
    // 0x800DF9A0: sw          $zero, 0x30($fp)
    MEM_W(0X30, ctx->r30) = 0;
    // 0x800DF9A4: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x800DF9A8: sw          $t8, 0x34($fp)
    MEM_W(0X34, ctx->r30) = ctx->r24;
    // 0x800DF9AC: lh          $v1, 0x10($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X10);
    // 0x800DF9B0: multu       $v1, $v1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800DF9B4: mflo        $a0
    ctx->r4 = lo;
    // 0x800DF9B8: sra         $t7, $a0, 15
    ctx->r15 = S32(SIGNED(ctx->r4) >> 15);
    // 0x800DF9BC: sh          $t7, 0x1A($fp)
    MEM_H(0X1A, ctx->r30) = ctx->r15;
    // 0x800DF9C0: lbu         $t6, 0x12($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X12);
    // 0x800DF9C4: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x800DF9C8: sh          $t6, 0x18($fp)
    MEM_H(0X18, ctx->r30) = ctx->r14;
    // 0x800DF9CC: lbu         $t9, 0x13($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X13);
    // 0x800DF9D0: sll         $t8, $t9, 1
    ctx->r24 = S32(ctx->r25 << 1);
    // 0x800DF9D4: addu        $t7, $t7, $t8
    ctx->r15 = ADD32(ctx->r15, ctx->r24);
    // 0x800DF9D8: lh          $t7, -0x2EE0($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X2EE0);
    // 0x800DF9DC: sh          $t7, 0x20($fp)
    MEM_H(0X20, ctx->r30) = ctx->r15;
    // 0x800DF9E0: lbu         $t6, 0x13($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X13);
    // 0x800DF9E4: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x800DF9E8: sll         $t9, $t6, 1
    ctx->r25 = S32(ctx->r14 << 1);
    // 0x800DF9EC: negu        $t8, $t9
    ctx->r24 = SUB32(0, ctx->r25);
    // 0x800DF9F0: addu        $t7, $t7, $t8
    ctx->r15 = ADD32(ctx->r15, ctx->r24);
    // 0x800DF9F4: lh          $t7, -0x2DE2($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X2DE2);
    // 0x800DF9F8: sh          $t7, 0x22($fp)
    MEM_H(0X22, ctx->r30) = ctx->r15;
    // 0x800DF9FC: lw          $t6, 0x14($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X14);
    // 0x800DFA00: beql        $t6, $zero, L_800DFA18
    if (ctx->r14 == 0) {
        // 0x800DFA04: lh          $v0, 0x18($fp)
        ctx->r2 = MEM_H(ctx->r30, 0X18);
            goto L_800DFA18;
    }
    goto skip_2;
    // 0x800DFA04: lh          $v0, 0x18($fp)
    ctx->r2 = MEM_H(ctx->r30, 0X18);
    skip_2:
    // 0x800DFA08: sh          $s1, 0x1C($fp)
    MEM_H(0X1C, ctx->r30) = ctx->r17;
    // 0x800DFA0C: b           L_800DFA5C
    // 0x800DFA10: sh          $s1, 0x1E($fp)
    MEM_H(0X1E, ctx->r30) = ctx->r17;
        goto L_800DFA5C;
    // 0x800DFA10: sh          $s1, 0x1E($fp)
    MEM_H(0X1E, ctx->r30) = ctx->r17;
    // 0x800DFA14: lh          $v0, 0x18($fp)
    ctx->r2 = MEM_H(ctx->r30, 0X18);
L_800DFA18:
    // 0x800DFA18: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x800DFA1C: lh          $v1, 0x1A($fp)
    ctx->r3 = MEM_H(ctx->r30, 0X1A);
    // 0x800DFA20: sll         $t9, $v0, 1
    ctx->r25 = S32(ctx->r2 << 1);
    // 0x800DFA24: addu        $t8, $t8, $t9
    ctx->r24 = ADD32(ctx->r24, ctx->r25);
    // 0x800DFA28: lh          $t8, -0x2EE0($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X2EE0);
    // 0x800DFA2C: negu        $t9, $t9
    ctx->r25 = SUB32(0, ctx->r25);
    // 0x800DFA30: multu       $t8, $v1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800DFA34: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x800DFA38: addu        $t8, $t8, $t9
    ctx->r24 = ADD32(ctx->r24, ctx->r25);
    // 0x800DFA3C: mflo        $t7
    ctx->r15 = lo;
    // 0x800DFA40: sra         $t6, $t7, 15
    ctx->r14 = S32(SIGNED(ctx->r15) >> 15);
    // 0x800DFA44: sh          $t6, 0x1C($fp)
    MEM_H(0X1C, ctx->r30) = ctx->r14;
    // 0x800DFA48: lh          $t8, -0x2DE2($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X2DE2);
    // 0x800DFA4C: multu       $t8, $v1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800DFA50: mflo        $t7
    ctx->r15 = lo;
    // 0x800DFA54: sra         $t6, $t7, 15
    ctx->r14 = S32(SIGNED(ctx->r15) >> 15);
    // 0x800DFA58: sh          $t6, 0x1E($fp)
    MEM_H(0X1E, ctx->r30) = ctx->r14;
L_800DFA5C:
    // 0x800DFA5C: lw          $t9, 0x0($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X0);
    // 0x800DFA60: beql        $t9, $zero, L_800DFD28
    if (ctx->r25 == 0) {
        // 0x800DFA64: lw          $t8, 0x60($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X60);
            goto L_800DFD28;
    }
    goto skip_3;
    // 0x800DFA64: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    skip_3:
    // 0x800DFA68: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800DFA6C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x800DFA70: swc1        $f4, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f4.u32l;
    // 0x800DFA74: lw          $a0, 0x0($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X0);
    // 0x800DFA78: lw          $a2, 0x74($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X74);
    // 0x800DFA7C: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800DFA80: jalr        $t9
    // 0x800DFA84: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x800DFA84: nop

    after_3:
    // 0x800DFA88: b           L_800DFD28
    // 0x800DFA8C: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
        goto L_800DFD28;
    // 0x800DFA8C: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
L_800DFA90:
    // 0x800DFA90: or          $s3, $fp, $zero
    ctx->r19 = ctx->r30 | 0;
    // 0x800DFA94: addiu       $s6, $sp, 0x9E
    ctx->r22 = ADD32(ctx->r29, 0X9E);
    // 0x800DFA98: addiu       $s0, $sp, 0x8E
    ctx->r16 = ADD32(ctx->r29, 0X8E);
    // 0x800DFA9C: lw          $s5, 0x60($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X60);
    // 0x800DFAA0: lw          $a3, 0xB4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB4);
    // 0x800DFAA4: jal         0x800DF554
    // 0x800DFAA8: lw          $t0, 0xA4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA4);
    func_800DF554(rdram, ctx);
        goto after_4;
    // 0x800DFAA8: lw          $t0, 0xA4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA4);
    after_4:
    // 0x800DFAAC: sw          $v0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r2;
    // 0x800DFAB0: lw          $a0, 0x34($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X34);
    // 0x800DFAB4: lw          $a3, 0x30($fp)
    ctx->r7 = MEM_W(ctx->r30, 0X30);
    // 0x800DFAB8: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x800DFABC: slt         $at, $a3, $a0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800DFAC0: bnel        $at, $zero, L_800DFB2C
    if (ctx->r1 != 0) {
        // 0x800DFAC4: lh          $t6, 0x1C($fp)
        ctx->r14 = MEM_H(ctx->r30, 0X1C);
            goto L_800DFB2C;
    }
    goto skip_4;
    // 0x800DFAC4: lh          $t6, 0x1C($fp)
    ctx->r14 = MEM_H(ctx->r30, 0X1C);
    skip_4:
    // 0x800DFAC8: lh          $v0, 0x18($fp)
    ctx->r2 = MEM_H(ctx->r30, 0X18);
    // 0x800DFACC: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x800DFAD0: lh          $v1, 0x1A($fp)
    ctx->r3 = MEM_H(ctx->r30, 0X1A);
    // 0x800DFAD4: sll         $t8, $v0, 1
    ctx->r24 = S32(ctx->r2 << 1);
    // 0x800DFAD8: addu        $t7, $t7, $t8
    ctx->r15 = ADD32(ctx->r15, ctx->r24);
    // 0x800DFADC: lh          $t7, -0x2EE0($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X2EE0);
    // 0x800DFAE0: negu        $t8, $t8
    ctx->r24 = SUB32(0, ctx->r24);
    // 0x800DFAE4: multu       $t7, $v1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800DFAE8: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x800DFAEC: addu        $t7, $t7, $t8
    ctx->r15 = ADD32(ctx->r15, ctx->r24);
    // 0x800DFAF0: mflo        $t6
    ctx->r14 = lo;
    // 0x800DFAF4: sra         $t9, $t6, 15
    ctx->r25 = S32(SIGNED(ctx->r14) >> 15);
    // 0x800DFAF8: sh          $t9, 0x28($fp)
    MEM_H(0X28, ctx->r30) = ctx->r25;
    // 0x800DFAFC: lh          $t7, -0x2DE2($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X2DE2);
    // 0x800DFB00: lh          $t8, 0x28($fp)
    ctx->r24 = MEM_H(ctx->r30, 0X28);
    // 0x800DFB04: sw          $a0, 0x30($fp)
    MEM_W(0X30, ctx->r30) = ctx->r4;
    // 0x800DFB08: multu       $t7, $v1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800DFB0C: sh          $t8, 0x1C($fp)
    MEM_H(0X1C, ctx->r30) = ctx->r24;
    // 0x800DFB10: mflo        $t6
    ctx->r14 = lo;
    // 0x800DFB14: sra         $t9, $t6, 15
    ctx->r25 = S32(SIGNED(ctx->r14) >> 15);
    // 0x800DFB18: sh          $t9, 0x2E($fp)
    MEM_H(0X2E, ctx->r30) = ctx->r25;
    // 0x800DFB1C: lh          $t7, 0x2E($fp)
    ctx->r15 = MEM_H(ctx->r30, 0X2E);
    // 0x800DFB20: b           L_800DFB7C
    // 0x800DFB24: sh          $t7, 0x1E($fp)
    MEM_H(0X1E, ctx->r30) = ctx->r15;
        goto L_800DFB7C;
    // 0x800DFB24: sh          $t7, 0x1E($fp)
    MEM_H(0X1E, ctx->r30) = ctx->r15;
    // 0x800DFB28: lh          $t6, 0x1C($fp)
    ctx->r14 = MEM_H(ctx->r30, 0X1C);
L_800DFB2C:
    // 0x800DFB2C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800DFB30: lh          $a1, 0x26($fp)
    ctx->r5 = MEM_H(ctx->r30, 0X26);
    // 0x800DFB34: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x800DFB38: lhu         $a2, 0x24($fp)
    ctx->r6 = MEM_HU(ctx->r30, 0X24);
    // 0x800DFB3C: jal         0x800DF7EC
    // 0x800DFB40: cvt.s.w     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
    func_800DF7EC(rdram, ctx);
        goto after_5;
    // 0x800DFB40: cvt.s.w     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
    after_5:
    // 0x800DFB44: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800DFB48: lh          $t7, 0x1E($fp)
    ctx->r15 = MEM_H(ctx->r30, 0X1E);
    // 0x800DFB4C: lw          $a0, 0x30($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X30);
    // 0x800DFB50: lh          $a1, 0x2C($fp)
    ctx->r5 = MEM_H(ctx->r30, 0X2C);
    // 0x800DFB54: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x800DFB58: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800DFB5C: lhu         $a2, 0x2A($fp)
    ctx->r6 = MEM_HU(ctx->r30, 0X2A);
    // 0x800DFB60: sh          $t8, 0x1C($fp)
    MEM_H(0X1C, ctx->r30) = ctx->r24;
    // 0x800DFB64: jal         0x800DF7EC
    // 0x800DFB68: cvt.s.w     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = CVT_S_W(ctx->f10.u32l);
    func_800DF7EC(rdram, ctx);
        goto after_6;
    // 0x800DFB68: cvt.s.w     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = CVT_S_W(ctx->f10.u32l);
    after_6:
    // 0x800DFB6C: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800DFB70: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x800DFB74: nop

    // 0x800DFB78: sh          $t9, 0x1E($fp)
    MEM_H(0X1E, ctx->r30) = ctx->r25;
L_800DFB7C:
    // 0x800DFB7C: lh          $t8, 0x1C($fp)
    ctx->r24 = MEM_H(ctx->r30, 0X1C);
    // 0x800DFB80: bnel        $t8, $zero, L_800DFB90
    if (ctx->r24 != 0) {
        // 0x800DFB84: lh          $t7, 0x1E($fp)
        ctx->r15 = MEM_H(ctx->r30, 0X1E);
            goto L_800DFB90;
    }
    goto skip_5;
    // 0x800DFB84: lh          $t7, 0x1E($fp)
    ctx->r15 = MEM_H(ctx->r30, 0X1E);
    skip_5:
    // 0x800DFB88: sh          $s1, 0x1C($fp)
    MEM_H(0X1C, ctx->r30) = ctx->r17;
    // 0x800DFB8C: lh          $t7, 0x1E($fp)
    ctx->r15 = MEM_H(ctx->r30, 0X1E);
L_800DFB90:
    // 0x800DFB90: bnel        $t7, $zero, L_800DFBA0
    if (ctx->r15 != 0) {
        // 0x800DFB94: lw          $v1, 0x3C($fp)
        ctx->r3 = MEM_W(ctx->r30, 0X3C);
            goto L_800DFBA0;
    }
    goto skip_6;
    // 0x800DFB94: lw          $v1, 0x3C($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X3C);
    skip_6:
    // 0x800DFB98: sh          $s1, 0x1E($fp)
    MEM_H(0X1E, ctx->r30) = ctx->r17;
    // 0x800DFB9C: lw          $v1, 0x3C($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X3C);
L_800DFBA0:
    // 0x800DFBA0: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x800DFBA4: lh          $a0, 0x8($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X8);
    // 0x800DFBA8: bnel        $a0, $at, L_800DFBC0
    if (ctx->r4 != ctx->r1) {
        // 0x800DFBAC: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_800DFBC0;
    }
    goto skip_7;
    // 0x800DFBAC: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    skip_7:
    // 0x800DFBB0: lw          $t6, 0xC($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XC);
    // 0x800DFBB4: sh          $t6, 0x18($fp)
    MEM_H(0X18, ctx->r30) = ctx->r14;
    // 0x800DFBB8: lh          $a0, 0x8($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X8);
    // 0x800DFBBC: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
L_800DFBC0:
    // 0x800DFBC0: bnel        $a0, $at, L_800DFBF0
    if (ctx->r4 != ctx->r1) {
        // 0x800DFBC4: addiu       $at, $zero, 0x10
        ctx->r1 = ADD32(0, 0X10);
            goto L_800DFBF0;
    }
    goto skip_8;
    // 0x800DFBC4: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    skip_8:
    // 0x800DFBC8: sw          $zero, 0x30($fp)
    MEM_W(0X30, ctx->r30) = 0;
    // 0x800DFBCC: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x800DFBD0: multu       $v0, $v0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800DFBD4: mflo        $v0
    ctx->r2 = lo;
    // 0x800DFBD8: sra         $t9, $v0, 15
    ctx->r25 = S32(SIGNED(ctx->r2) >> 15);
    // 0x800DFBDC: sh          $t9, 0x1A($fp)
    MEM_H(0X1A, ctx->r30) = ctx->r25;
    // 0x800DFBE0: lw          $t8, 0x10($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X10);
    // 0x800DFBE4: sw          $t8, 0x34($fp)
    MEM_W(0X34, ctx->r30) = ctx->r24;
    // 0x800DFBE8: lh          $a0, 0x8($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X8);
    // 0x800DFBEC: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
L_800DFBF0:
    // 0x800DFBF0: bne         $a0, $at, L_800DFC2C
    if (ctx->r4 != ctx->r1) {
        // 0x800DFBF4: nop
    
            goto L_800DFC2C;
    }
    // 0x800DFBF4: nop

    // 0x800DFBF8: lw          $t7, 0xC($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XC);
    // 0x800DFBFC: lui         $t9, 0x800F
    ctx->r25 = S32(0X800F << 16);
    // 0x800DFC00: sll         $t6, $t7, 1
    ctx->r14 = S32(ctx->r15 << 1);
    // 0x800DFC04: addu        $t9, $t9, $t6
    ctx->r25 = ADD32(ctx->r25, ctx->r14);
    // 0x800DFC08: lh          $t9, -0x2EE0($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X2EE0);
    // 0x800DFC0C: sh          $t9, 0x20($fp)
    MEM_H(0X20, ctx->r30) = ctx->r25;
    // 0x800DFC10: lw          $t8, 0xC($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XC);
    // 0x800DFC14: lui         $t9, 0x800F
    ctx->r25 = S32(0X800F << 16);
    // 0x800DFC18: sll         $t7, $t8, 1
    ctx->r15 = S32(ctx->r24 << 1);
    // 0x800DFC1C: negu        $t6, $t7
    ctx->r14 = SUB32(0, ctx->r15);
    // 0x800DFC20: addu        $t9, $t9, $t6
    ctx->r25 = ADD32(ctx->r25, ctx->r14);
    // 0x800DFC24: lh          $t9, -0x2DE2($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X2DE2);
    // 0x800DFC28: sh          $t9, 0x22($fp)
    MEM_H(0X22, ctx->r30) = ctx->r25;
L_800DFC2C:
    // 0x800DFC2C: b           L_800DFD24
    // 0x800DFC30: sw          $s1, 0x38($fp)
    MEM_W(0X38, ctx->r30) = ctx->r17;
        goto L_800DFD24;
    // 0x800DFC30: sw          $s1, 0x38($fp)
    MEM_W(0X38, ctx->r30) = ctx->r17;
L_800DFC34:
    // 0x800DFC34: lh          $t8, 0xA($v1)
    ctx->r24 = MEM_H(ctx->r3, 0XA);
    // 0x800DFC38: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
    // 0x800DFC3C: beql        $t8, $zero, L_800DFC5C
    if (ctx->r24 == 0) {
        // 0x800DFC40: lw          $t9, 0x8($fp)
        ctx->r25 = MEM_W(ctx->r30, 0X8);
            goto L_800DFC5C;
    }
    goto skip_9;
    // 0x800DFC40: lw          $t9, 0x8($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X8);
    skip_9:
    // 0x800DFC44: lw          $t9, 0x8($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X8);
    // 0x800DFC48: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x800DFC4C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x800DFC50: jalr        $t9
    // 0x800DFC54: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_7;
    // 0x800DFC54: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x800DFC58: lw          $t9, 0x8($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X8);
L_800DFC5C:
    // 0x800DFC5C: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x800DFC60: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x800DFC64: jalr        $t9
    // 0x800DFC68: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_8;
    // 0x800DFC68: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    after_8:
    // 0x800DFC6C: lw          $t9, 0x8($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X8);
    // 0x800DFC70: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x800DFC74: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x800DFC78: jalr        $t9
    // 0x800DFC7C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_9;
    // 0x800DFC7C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_9:
    // 0x800DFC80: b           L_800DFD28
    // 0x800DFC84: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
        goto L_800DFD28;
    // 0x800DFC84: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
L_800DFC88:
    // 0x800DFC88: or          $s3, $fp, $zero
    ctx->r19 = ctx->r30 | 0;
    // 0x800DFC8C: addiu       $s6, $sp, 0x9E
    ctx->r22 = ADD32(ctx->r29, 0X9E);
    // 0x800DFC90: addiu       $s0, $sp, 0x8E
    ctx->r16 = ADD32(ctx->r29, 0X8E);
    // 0x800DFC94: lw          $s5, 0x60($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X60);
    // 0x800DFC98: lw          $a3, 0xB4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB4);
    // 0x800DFC9C: jal         0x800DF554
    // 0x800DFCA0: lw          $t0, 0xA4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA4);
    func_800DF554(rdram, ctx);
        goto after_10;
    // 0x800DFCA0: lw          $t0, 0xA4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA4);
    after_10:
    // 0x800DFCA4: sw          $v0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r2;
    // 0x800DFCA8: lw          $t9, 0x8($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X8);
    // 0x800DFCAC: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x800DFCB0: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x800DFCB4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800DFCB8: jalr        $t9
    // 0x800DFCBC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_11;
    // 0x800DFCBC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_11:
    // 0x800DFCC0: b           L_800DFD28
    // 0x800DFCC4: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
        goto L_800DFD28;
    // 0x800DFCC4: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
L_800DFCC8:
    // 0x800DFCC8: lw          $t7, 0xC($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XC);
    // 0x800DFCCC: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800DFCD0: lw          $a0, -0x3210($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3210);
    // 0x800DFCD4: sw          $zero, 0xD8($t7)
    MEM_W(0XD8, ctx->r15) = 0;
    // 0x800DFCD8: jal         0x800D8F70
    // 0x800DFCDC: lw          $a1, 0xC($v1)
    ctx->r5 = MEM_W(ctx->r3, 0XC);
    _freePVoice_recomp(rdram, ctx);
        goto after_12;
    // 0x800DFCDC: lw          $a1, 0xC($v1)
    ctx->r5 = MEM_W(ctx->r3, 0XC);
    after_12:
    // 0x800DFCE0: b           L_800DFD28
    // 0x800DFCE4: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
        goto L_800DFD28;
    // 0x800DFCE4: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
L_800DFCE8:
    // 0x800DFCE8: or          $s3, $fp, $zero
    ctx->r19 = ctx->r30 | 0;
    // 0x800DFCEC: addiu       $s6, $sp, 0x9E
    ctx->r22 = ADD32(ctx->r29, 0X9E);
    // 0x800DFCF0: addiu       $s0, $sp, 0x8E
    ctx->r16 = ADD32(ctx->r29, 0X8E);
    // 0x800DFCF4: lw          $s5, 0x60($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X60);
    // 0x800DFCF8: lw          $a3, 0xB4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB4);
    // 0x800DFCFC: jal         0x800DF554
    // 0x800DFD00: lw          $t0, 0xA4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA4);
    func_800DF554(rdram, ctx);
        goto after_13;
    // 0x800DFD00: lw          $t0, 0xA4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA4);
    after_13:
    // 0x800DFD04: sw          $v0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r2;
    // 0x800DFD08: lw          $t9, 0x8($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X8);
    // 0x800DFD0C: lw          $v1, 0x3C($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X3C);
    // 0x800DFD10: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x800DFD14: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x800DFD18: lh          $a1, 0x8($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X8);
    // 0x800DFD1C: jalr        $t9
    // 0x800DFD20: lw          $a2, 0xC($v1)
    ctx->r6 = MEM_W(ctx->r3, 0XC);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_14;
    // 0x800DFD20: lw          $a2, 0xC($v1)
    ctx->r6 = MEM_W(ctx->r3, 0XC);
    after_14:
L_800DFD24:
    // 0x800DFD24: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
L_800DFD28:
    // 0x800DFD28: lh          $t6, 0x8E($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X8E);
    // 0x800DFD2C: sll         $t7, $t8, 1
    ctx->r15 = S32(ctx->r24 << 1);
    // 0x800DFD30: addu        $t9, $t6, $t7
    ctx->r25 = ADD32(ctx->r14, ctx->r15);
    // 0x800DFD34: lw          $t6, 0xB0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB0);
    // 0x800DFD38: sh          $t9, 0x8E($sp)
    MEM_H(0X8E, ctx->r29) = ctx->r25;
    // 0x800DFD3C: subu        $t7, $t6, $t8
    ctx->r15 = SUB32(ctx->r14, ctx->r24);
    // 0x800DFD40: sw          $t7, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r15;
    // 0x800DFD44: lw          $a0, 0x3C($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X3C);
    // 0x800DFD48: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x800DFD4C: bne         $t9, $zero, L_800DFD58
    if (ctx->r25 != 0) {
        // 0x800DFD50: sw          $t9, 0x3C($fp)
        MEM_W(0X3C, ctx->r30) = ctx->r25;
            goto L_800DFD58;
    }
    // 0x800DFD50: sw          $t9, 0x3C($fp)
    MEM_W(0X3C, ctx->r30) = ctx->r25;
    // 0x800DFD54: sw          $zero, 0x40($fp)
    MEM_W(0X40, ctx->r30) = 0;
L_800DFD58:
    // 0x800DFD58: jal         0x800D9008
    // 0x800DFD5C: nop

    __freeParam_recomp(rdram, ctx);
        goto after_15;
    // 0x800DFD5C: nop

    after_15:
    // 0x800DFD60: lw          $t8, 0xA0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA0);
    // 0x800DFD64: lw          $t7, 0x3C($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X3C);
    // 0x800DFD68: bnel        $t7, $zero, L_800DF90C
    if (ctx->r15 != 0) {
        // 0x800DFD6C: lw          $v1, 0x3C($fp)
        ctx->r3 = MEM_W(ctx->r30, 0X3C);
            goto L_800DF90C;
    }
    goto skip_10;
    // 0x800DFD6C: lw          $v1, 0x3C($fp)
    ctx->r3 = MEM_W(ctx->r30, 0X3C);
    skip_10:
L_800DFD70:
    // 0x800DFD70: or          $s3, $fp, $zero
    ctx->r19 = ctx->r30 | 0;
L_800DFD74:
    // 0x800DFD74: addiu       $s6, $sp, 0x9E
    ctx->r22 = ADD32(ctx->r29, 0X9E);
    // 0x800DFD78: addiu       $s0, $sp, 0x8E
    ctx->r16 = ADD32(ctx->r29, 0X8E);
    // 0x800DFD7C: lw          $s5, 0xB0($sp)
    ctx->r21 = MEM_W(ctx->r29, 0XB0);
    // 0x800DFD80: lw          $a3, 0xB4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB4);
    // 0x800DFD84: jal         0x800DF554
    // 0x800DFD88: lw          $t0, 0xA4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA4);
    func_800DF554(rdram, ctx);
        goto after_16;
    // 0x800DFD88: lw          $t0, 0xA4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA4);
    after_16:
    // 0x800DFD8C: sw          $v0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r2;
    // 0x800DFD90: lw          $t9, 0x30($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X30);
    // 0x800DFD94: lw          $a0, 0x34($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X34);
    // 0x800DFD98: slt         $at, $a0, $t9
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800DFD9C: beql        $at, $zero, L_800DFDAC
    if (ctx->r1 == 0) {
        // 0x800DFDA0: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_800DFDAC;
    }
    goto skip_11;
    // 0x800DFDA0: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_11:
    // 0x800DFDA4: sw          $a0, 0x30($fp)
    MEM_W(0X30, ctx->r30) = ctx->r4;
    // 0x800DFDA8: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_800DFDAC:
    // 0x800DFDAC: lw          $v0, 0xA4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XA4);
    // 0x800DFDB0: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x800DFDB4: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x800DFDB8: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x800DFDBC: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x800DFDC0: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x800DFDC4: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x800DFDC8: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x800DFDCC: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x800DFDD0: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x800DFDD4: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x800DFDD8: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x800DFDDC: jr          $ra
    // 0x800DFDE0: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x800DFDE0: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    // 0x800DFDE4: nop

    // 0x800DFDE8: nop

    // 0x800DFDEC: nop

;}
RECOMP_FUNC void func_800DFDF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DFDF0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800DFDF4: bne         $a1, $at, L_800DFE18
    if (ctx->r5 != ctx->r1) {
        // 0x800DFDF8: lw          $v0, 0x1C($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X1C);
            goto L_800DFE18;
    }
    // 0x800DFDF8: lw          $v0, 0x1C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1C);
    // 0x800DFDFC: lw          $t6, 0x14($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X14);
    // 0x800DFE00: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800DFE04: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x800DFE08: sw          $a2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r6;
    // 0x800DFE0C: lw          $t9, 0x14($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X14);
    // 0x800DFE10: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800DFE14: sw          $t0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r8;
L_800DFE18:
    // 0x800DFE18: jr          $ra
    // 0x800DFE1C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800DFE1C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
