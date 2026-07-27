#include "recomp.h"
extern void load_overlays(uint32_t rom, int32_t ram_addr, uint32_t size);
extern void unload_overlays(int32_t ram_addr, uint32_t size);
#include "funcs.h"

RECOMP_FUNC void func_80175E00_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80175E00: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80175E04: lw          $t6, -0x2A3C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2A3C);
    // 0x80175E08: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80175E0C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80175E10: beq         $t6, $zero, L_80175FA0
    if (ctx->r14 == 0) {
        // 0x80175E14: nop
    
            goto L_80175FA0;
    }
    // 0x80175E14: nop

    // 0x80175E18: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80175E1C: lw          $t7, -0x2A40($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2A40);
    // 0x80175E20: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80175E24: beq         $t8, $zero, L_80175E40
    if (ctx->r24 == 0) {
        // 0x80175E28: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80175E40;
    }
    // 0x80175E28: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80175E2C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80175E30: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80175E34: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x80175E38: b           L_80175E54
    // 0x80175E3C: swc1        $f4, 0x14($t9)
    MEM_W(0X14, ctx->r25) = ctx->f4.u32l;
        goto L_80175E54;
    // 0x80175E3C: swc1        $f4, 0x14($t9)
    MEM_W(0X14, ctx->r25) = ctx->f4.u32l;
L_80175E40:
    // 0x80175E40: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80175E44: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80175E48: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80175E4C: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x80175E50: swc1        $f6, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->f6.u32l;
L_80175E54:
    // 0x80175E54: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80175E58: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80175E5C: addiu       $t2, $t2, -0x4198
    ctx->r10 = ADD32(ctx->r10, -0X4198);
    // 0x80175E60: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x80175E64: lwc1        $f8, 0x14($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X14);
    // 0x80175E68: lwc1        $f10, 0x30($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X30);
    // 0x80175E6C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80175E70: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80175E74: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80175E78: addiu       $t4, $t4, -0x4198
    ctx->r12 = ADD32(ctx->r12, -0X4198);
    // 0x80175E7C: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x80175E80: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80175E84: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80175E88: addiu       $t6, $t6, -0x4198
    ctx->r14 = ADD32(ctx->r14, -0X4198);
    // 0x80175E8C: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x80175E90: swc1        $f16, 0x28($t1)
    MEM_W(0X28, ctx->r9) = ctx->f16.u32l;
    // 0x80175E94: lwc1        $f4, 0x34($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X34);
    // 0x80175E98: lwc1        $f18, 0x14($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X14);
    // 0x80175E9C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80175EA0: addiu       $t7, $t7, -0x4198
    ctx->r15 = ADD32(ctx->r15, -0X4198);
    // 0x80175EA4: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80175EA8: lui         $at, 0xBF00
    ctx->r1 = S32(0XBF00 << 16);
    // 0x80175EAC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80175EB0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80175EB4: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x80175EB8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80175EBC: addiu       $t9, $t9, -0x4198
    ctx->r25 = ADD32(ctx->r25, -0X4198);
    // 0x80175EC0: swc1        $f6, 0x2C($t3)
    MEM_W(0X2C, ctx->r11) = ctx->f6.u32l;
    // 0x80175EC4: lwc1        $f10, 0x38($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X38);
    // 0x80175EC8: lwc1        $f8, 0x14($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X14);
    // 0x80175ECC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80175ED0: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x80175ED4: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80175ED8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80175EDC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80175EE0: addiu       $t2, $t2, -0x4198
    ctx->r10 = ADD32(ctx->r10, -0X4198);
    // 0x80175EE4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80175EE8: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x80175EEC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80175EF0: swc1        $f16, 0x30($t5)
    MEM_W(0X30, ctx->r13) = ctx->f16.u32l;
    // 0x80175EF4: lwc1        $f18, 0x40($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0X40);
    // 0x80175EF8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80175EFC: addiu       $t4, $t4, -0x4198
    ctx->r12 = ADD32(ctx->r12, -0X4198);
    // 0x80175F00: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80175F04: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80175F08: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x80175F0C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80175F10: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80175F14: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80175F18: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80175F1C: swc1        $f6, 0x3C($t8)
    MEM_W(0X3C, ctx->r24) = ctx->f6.u32l;
    // 0x80175F20: lwc1        $f8, 0x44($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X44);
    // 0x80175F24: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80175F28: swc1        $f16, 0x40($t0)
    MEM_W(0X40, ctx->r8) = ctx->f16.u32l;
    // 0x80175F2C: lwc1        $f18, 0x48($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X48);
    // 0x80175F30: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80175F34: swc1        $f6, 0x44($t1)
    MEM_W(0X44, ctx->r9) = ctx->f6.u32l;
    // 0x80175F38: lwc1        $f10, 0x28($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X28);
    // 0x80175F3C: lwc1        $f8, 0x0($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X0);
    // 0x80175F40: lwc1        $f18, 0x3C($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X3C);
    // 0x80175F44: lw          $a0, -0x2A3C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2A3C);
    // 0x80175F48: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80175F4C: lw          $a3, -0x2A30($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X2A30);
    // 0x80175F50: lw          $a2, -0x2A34($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X2A34);
    // 0x80175F54: lw          $a1, -0x2A38($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X2A38);
    // 0x80175F58: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80175F5C: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80175F60: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80175F64: lwc1        $f8, 0x2C($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X2C);
    // 0x80175F68: lwc1        $f6, 0x4($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X4);
    // 0x80175F6C: lwc1        $f18, 0x40($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X40);
    // 0x80175F70: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80175F74: add.s       $f16, $f18, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x80175F78: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x80175F7C: lwc1        $f6, 0x30($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X30);
    // 0x80175F80: lwc1        $f4, 0x8($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X8);
    // 0x80175F84: lwc1        $f18, 0x44($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X44);
    // 0x80175F88: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80175F8C: add.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x80175F90: jal         0x8018F2F8
    // 0x80175F94: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    func_8018F2F8_1501A0(rdram, ctx);
        goto after_0;
    // 0x80175F94: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    after_0:
    // 0x80175F98: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80175F9C: sw          $zero, -0x2A3C($at)
    MEM_W(-0X2A3C, ctx->r1) = 0;
L_80175FA0:
    // 0x80175FA0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80175FA4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80175FA8: jr          $ra
    // 0x80175FAC: nop

    return;
    // 0x80175FAC: nop

;}
RECOMP_FUNC void func_80175FB0_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80175FB0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80175FB4: lw          $t6, -0x2E3C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2E3C);
    // 0x80175FB8: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80175FBC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80175FC0: beq         $t6, $zero, L_80176850
    if (ctx->r14 == 0) {
        // 0x80175FC4: sw          $zero, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = 0;
            goto L_80176850;
    }
    // 0x80175FC4: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
L_80175FC8:
    // 0x80175FC8: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
L_80175FCC:
    // 0x80175FCC: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x80175FD0: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x80175FD4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80175FD8: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80175FDC: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x80175FE0: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80175FE4: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x80175FE8: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x80175FEC: sll         $t8, $t8, 5
    ctx->r24 = S32(ctx->r24 << 5);
    // 0x80175FF0: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x80175FF4: addiu       $t2, $t2, 0x3518
    ctx->r10 = ADD32(ctx->r10, 0X3518);
    // 0x80175FF8: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80175FFC: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80176000: beq         $t4, $zero, L_8017681C
    if (ctx->r12 == 0) {
        // 0x80176004: nop
    
            goto L_8017681C;
    }
    // 0x80176004: nop

    // 0x80176008: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017600C: lw          $t5, -0x2E44($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2E44);
    // 0x80176010: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80176014: addu        $t9, $t8, $t0
    ctx->r25 = ADD32(ctx->r24, ctx->r8);
    // 0x80176018: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8017601C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80176020: lw          $t7, -0x26E4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X26E4);
    // 0x80176024: addu        $t1, $t9, $t2
    ctx->r9 = ADD32(ctx->r25, ctx->r10);
    // 0x80176028: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017602C: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
    // 0x80176030: lw          $t3, 0x4($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X4);
    // 0x80176034: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80176038: lwc1        $f6, -0x4AC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X4AC);
    // 0x8017603C: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80176040: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x80176044: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80176048: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x8017604C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80176050: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x80176054: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80176058: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8017605C: lw          $t5, -0x2A24($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2A24);
    // 0x80176060: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80176064: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x80176068: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8017606C: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80176070: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80176074: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x80176078: lwc1        $f4, -0x8($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, -0X8);
    // 0x8017607C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80176080: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80176084: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80176088: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017608C: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x80176090: swc1        $f8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f8.u32l;
    // 0x80176094: lw          $t9, -0x2E3C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2E3C);
    // 0x80176098: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x8017609C: sll         $t2, $t9, 2
    ctx->r10 = S32(ctx->r25 << 2);
    // 0x801760A0: addu        $t3, $t2, $t1
    ctx->r11 = ADD32(ctx->r10, ctx->r9);
    // 0x801760A4: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x801760A8: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x801760AC: lwc1        $f10, -0x273C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X273C);
    // 0x801760B0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x801760B4: swc1        $f10, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->f10.u32l;
    // 0x801760B8: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x801760BC: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x801760C0: sll         $t0, $t8, 3
    ctx->r8 = S32(ctx->r24 << 3);
    // 0x801760C4: sll         $t6, $t7, 3
    ctx->r14 = S32(ctx->r15 << 3);
    // 0x801760C8: subu        $t0, $t0, $t8
    ctx->r8 = SUB32(ctx->r8, ctx->r24);
    // 0x801760CC: subu        $t6, $t6, $t7
    ctx->r14 = SUB32(ctx->r14, ctx->r15);
    // 0x801760D0: sll         $t6, $t6, 5
    ctx->r14 = S32(ctx->r14 << 5);
    // 0x801760D4: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x801760D8: addu        $t9, $t6, $t0
    ctx->r25 = ADD32(ctx->r14, ctx->r8);
    // 0x801760DC: addu        $t2, $t2, $t9
    ctx->r10 = ADD32(ctx->r10, ctx->r25);
    // 0x801760E0: lw          $t2, 0x3520($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X3520);
    // 0x801760E4: bne         $t2, $zero, L_801762D0
    if (ctx->r10 != 0) {
        // 0x801760E8: nop
    
            goto L_801762D0;
    }
    // 0x801760E8: nop

    // 0x801760EC: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x801760F0: lw          $t1, -0x4514($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4514);
    // 0x801760F4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x801760F8: lui         $t4, 0xFA00
    ctx->r12 = S32(0XFA00 << 16);
    // 0x801760FC: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    // 0x80176100: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x80176104: addiu       $t3, $t1, 0x8
    ctx->r11 = ADD32(ctx->r9, 0X8);
    // 0x80176108: sw          $t3, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r11;
    // 0x8017610C: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x80176110: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x80176114: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80176118: addiu       $t6, $t6, -0x26EC
    ctx->r14 = ADD32(ctx->r14, -0X26EC);
    // 0x8017611C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80176120: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80176124: addu        $t0, $t8, $t6
    ctx->r8 = ADD32(ctx->r24, ctx->r14);
    // 0x80176128: lbu         $t3, 0x1($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X1);
    // 0x8017612C: lbu         $t9, 0x0($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X0);
    // 0x80176130: lbu         $t8, 0x2($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0X2);
    // 0x80176134: andi        $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 & 0XFF;
    // 0x80176138: sll         $t5, $t4, 16
    ctx->r13 = S32(ctx->r12 << 16);
    // 0x8017613C: andi        $t2, $t9, 0xFF
    ctx->r10 = ctx->r25 & 0XFF;
    // 0x80176140: sll         $t1, $t2, 24
    ctx->r9 = S32(ctx->r10 << 24);
    // 0x80176144: andi        $t6, $t8, 0xFF
    ctx->r14 = ctx->r24 & 0XFF;
    // 0x80176148: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x8017614C: sll         $t9, $t6, 8
    ctx->r25 = S32(ctx->r14 << 8);
    // 0x80176150: or          $t7, $t1, $t5
    ctx->r15 = ctx->r9 | ctx->r13;
    // 0x80176154: or          $t2, $t9, $t7
    ctx->r10 = ctx->r25 | ctx->r15;
    // 0x80176158: ori         $t3, $t2, 0xFA
    ctx->r11 = ctx->r10 | 0XFA;
    // 0x8017615C: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    // 0x80176160: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x80176164: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x80176168: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017616C: sll         $t6, $t8, 3
    ctx->r14 = S32(ctx->r24 << 3);
    // 0x80176170: sll         $t0, $t1, 3
    ctx->r8 = S32(ctx->r9 << 3);
    // 0x80176174: subu        $t6, $t6, $t8
    ctx->r14 = SUB32(ctx->r14, ctx->r24);
    // 0x80176178: subu        $t0, $t0, $t1
    ctx->r8 = SUB32(ctx->r8, ctx->r9);
    // 0x8017617C: sll         $t0, $t0, 5
    ctx->r8 = S32(ctx->r8 << 5);
    // 0x80176180: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80176184: addu        $t9, $t0, $t6
    ctx->r25 = ADD32(ctx->r8, ctx->r14);
    // 0x80176188: addiu       $t7, $t7, 0x3518
    ctx->r15 = ADD32(ctx->r15, 0X3518);
    // 0x8017618C: addu        $t2, $t9, $t7
    ctx->r10 = ADD32(ctx->r25, ctx->r15);
    // 0x80176190: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x80176194: addu        $t8, $t0, $t6
    ctx->r24 = ADD32(ctx->r8, ctx->r14);
    // 0x80176198: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8017619C: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x801761A0: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x801761A4: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x801761A8: sll         $t5, $t1, 2
    ctx->r13 = S32(ctx->r9 << 2);
    // 0x801761AC: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x801761B0: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x801761B4: addu        $a0, $a0, $t5
    ctx->r4 = ADD32(ctx->r4, ctx->r13);
    // 0x801761B8: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x801761BC: lw          $t2, 0x4($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X4);
    // 0x801761C0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x801761C4: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x801761C8: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x801761CC: addiu       $t5, $t5, -0x2A28
    ctx->r13 = ADD32(ctx->r13, -0X2A28);
    // 0x801761D0: addu        $t1, $t4, $t5
    ctx->r9 = ADD32(ctx->r12, ctx->r13);
    // 0x801761D4: lw          $a2, 0x60($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X60);
    // 0x801761D8: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x801761DC: addu        $t1, $t0, $t6
    ctx->r9 = ADD32(ctx->r8, ctx->r14);
    // 0x801761E0: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x801761E4: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x801761E8: addu        $t8, $t1, $t7
    ctx->r24 = ADD32(ctx->r9, ctx->r15);
    // 0x801761EC: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x801761F0: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x801761F4: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x801761F8: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x801761FC: sll         $t2, $t9, 2
    ctx->r10 = S32(ctx->r25 << 2);
    // 0x80176200: addu        $t2, $t2, $t9
    ctx->r10 = ADD32(ctx->r10, ctx->r25);
    // 0x80176204: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80176208: subu        $t2, $t2, $t9
    ctx->r10 = SUB32(ctx->r10, ctx->r25);
    // 0x8017620C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80176210: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80176214: addu        $t2, $t2, $t9
    ctx->r10 = ADD32(ctx->r10, ctx->r25);
    // 0x80176218: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8017621C: addu        $t4, $t3, $t5
    ctx->r12 = ADD32(ctx->r11, ctx->r13);
    // 0x80176220: addu        $t3, $t2, $t5
    ctx->r11 = ADD32(ctx->r10, ctx->r13);
    // 0x80176224: lwc1        $f16, 0x68($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X68);
    // 0x80176228: lw          $a3, 0x64($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X64);
    // 0x8017622C: addu        $t4, $t0, $t6
    ctx->r12 = ADD32(ctx->r8, ctx->r14);
    // 0x80176230: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80176234: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x80176238: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x8017623C: addu        $t1, $t4, $t7
    ctx->r9 = ADD32(ctx->r12, ctx->r15);
    // 0x80176240: lwc1        $f18, 0x14($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X14);
    // 0x80176244: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    // 0x80176248: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017624C: addu        $t9, $t0, $t6
    ctx->r25 = ADD32(ctx->r8, ctx->r14);
    // 0x80176250: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80176254: addu        $t2, $t9, $t7
    ctx->r10 = ADD32(ctx->r25, ctx->r15);
    // 0x80176258: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x8017625C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80176260: addu        $t3, $t0, $t6
    ctx->r11 = ADD32(ctx->r8, ctx->r14);
    // 0x80176264: addu        $t4, $t3, $t7
    ctx->r12 = ADD32(ctx->r11, ctx->r15);
    // 0x80176268: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x8017626C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x80176270: lwc1        $f10, 0x0($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X0);
    // 0x80176274: lwc1        $f8, 0x14($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X14);
    // 0x80176278: addu        $t8, $t0, $t6
    ctx->r24 = ADD32(ctx->r8, ctx->r14);
    // 0x8017627C: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x80176280: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80176284: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80176288: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017628C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80176290: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x80176294: lw          $a0, -0x275C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X275C);
    // 0x80176298: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8017629C: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x801762A0: lwc1        $f4, 0x0($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X0);
    // 0x801762A4: lwc1        $f18, 0x14($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X14);
    // 0x801762A8: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x801762AC: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x801762B0: lwc1        $f8, 0x14($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X14);
    // 0x801762B4: lwc1        $f18, 0x4($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X4);
    // 0x801762B8: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x801762BC: sub.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x801762C0: jal         0x800C6144
    // 0x801762C4: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    func_800C6144(rdram, ctx);
        goto after_0;
    // 0x801762C4: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x801762C8: b           L_801764AC
    // 0x801762CC: nop

        goto L_801764AC;
    // 0x801762CC: nop

L_801762D0:
    // 0x801762D0: lui         $t5, 0x8011
    ctx->r13 = S32(0X8011 << 16);
    // 0x801762D4: lw          $t5, -0x4514($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4514);
    // 0x801762D8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x801762DC: lui         $t4, 0xFA00
    ctx->r12 = S32(0XFA00 << 16);
    // 0x801762E0: sw          $t5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r13;
    // 0x801762E4: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x801762E8: addiu       $t3, $t5, 0x8
    ctx->r11 = ADD32(ctx->r13, 0X8);
    // 0x801762EC: sw          $t3, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r11;
    // 0x801762F0: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x801762F4: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x801762F8: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x801762FC: addiu       $t8, $t8, -0x26EC
    ctx->r24 = ADD32(ctx->r24, -0X26EC);
    // 0x80176300: sll         $t6, $t0, 2
    ctx->r14 = S32(ctx->r8 << 2);
    // 0x80176304: subu        $t6, $t6, $t0
    ctx->r14 = SUB32(ctx->r14, ctx->r8);
    // 0x80176308: addu        $t7, $t6, $t8
    ctx->r15 = ADD32(ctx->r14, ctx->r24);
    // 0x8017630C: lbu         $t3, 0x1($t7)
    ctx->r11 = MEM_BU(ctx->r15, 0X1);
    // 0x80176310: lbu         $t9, 0x0($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X0);
    // 0x80176314: lbu         $t6, 0x2($t7)
    ctx->r14 = MEM_BU(ctx->r15, 0X2);
    // 0x80176318: andi        $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 & 0XFF;
    // 0x8017631C: sll         $t1, $t4, 16
    ctx->r9 = S32(ctx->r12 << 16);
    // 0x80176320: andi        $t2, $t9, 0xFF
    ctx->r10 = ctx->r25 & 0XFF;
    // 0x80176324: sll         $t5, $t2, 24
    ctx->r13 = S32(ctx->r10 << 24);
    // 0x80176328: andi        $t8, $t6, 0xFF
    ctx->r24 = ctx->r14 & 0XFF;
    // 0x8017632C: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x80176330: sll         $t9, $t8, 8
    ctx->r25 = S32(ctx->r24 << 8);
    // 0x80176334: or          $t0, $t5, $t1
    ctx->r8 = ctx->r13 | ctx->r9;
    // 0x80176338: or          $t2, $t9, $t0
    ctx->r10 = ctx->r25 | ctx->r8;
    // 0x8017633C: ori         $t3, $t2, 0x96
    ctx->r11 = ctx->r10 | 0X96;
    // 0x80176340: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    // 0x80176344: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x80176348: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x8017634C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80176350: sll         $t8, $t6, 3
    ctx->r24 = S32(ctx->r14 << 3);
    // 0x80176354: sll         $t7, $t5, 3
    ctx->r15 = S32(ctx->r13 << 3);
    // 0x80176358: subu        $t8, $t8, $t6
    ctx->r24 = SUB32(ctx->r24, ctx->r14);
    // 0x8017635C: subu        $t7, $t7, $t5
    ctx->r15 = SUB32(ctx->r15, ctx->r13);
    // 0x80176360: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x80176364: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80176368: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8017636C: addiu       $t0, $t0, 0x3518
    ctx->r8 = ADD32(ctx->r8, 0X3518);
    // 0x80176370: addu        $t2, $t9, $t0
    ctx->r10 = ADD32(ctx->r25, ctx->r8);
    // 0x80176374: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x80176378: addu        $t6, $t7, $t8
    ctx->r14 = ADD32(ctx->r15, ctx->r24);
    // 0x8017637C: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80176380: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80176384: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x80176388: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8017638C: sll         $t1, $t5, 2
    ctx->r9 = S32(ctx->r13 << 2);
    // 0x80176390: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x80176394: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80176398: addu        $a0, $a0, $t1
    ctx->r4 = ADD32(ctx->r4, ctx->r9);
    // 0x8017639C: addu        $t9, $t6, $t0
    ctx->r25 = ADD32(ctx->r14, ctx->r8);
    // 0x801763A0: lw          $t2, 0x4($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X4);
    // 0x801763A4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x801763A8: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x801763AC: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x801763B0: addiu       $t1, $t1, -0x2A28
    ctx->r9 = ADD32(ctx->r9, -0X2A28);
    // 0x801763B4: addu        $t5, $t4, $t1
    ctx->r13 = ADD32(ctx->r12, ctx->r9);
    // 0x801763B8: lw          $a2, 0x60($t5)
    ctx->r6 = MEM_W(ctx->r13, 0X60);
    // 0x801763BC: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x801763C0: addu        $t5, $t7, $t8
    ctx->r13 = ADD32(ctx->r15, ctx->r24);
    // 0x801763C4: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x801763C8: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x801763CC: addu        $t6, $t5, $t0
    ctx->r14 = ADD32(ctx->r13, ctx->r8);
    // 0x801763D0: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x801763D4: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x801763D8: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x801763DC: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x801763E0: sll         $t2, $t9, 2
    ctx->r10 = S32(ctx->r25 << 2);
    // 0x801763E4: addu        $t2, $t2, $t9
    ctx->r10 = ADD32(ctx->r10, ctx->r25);
    // 0x801763E8: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x801763EC: subu        $t2, $t2, $t9
    ctx->r10 = SUB32(ctx->r10, ctx->r25);
    // 0x801763F0: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x801763F4: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x801763F8: addu        $t2, $t2, $t9
    ctx->r10 = ADD32(ctx->r10, ctx->r25);
    // 0x801763FC: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80176400: addu        $t4, $t3, $t1
    ctx->r12 = ADD32(ctx->r11, ctx->r9);
    // 0x80176404: addu        $t3, $t2, $t1
    ctx->r11 = ADD32(ctx->r10, ctx->r9);
    // 0x80176408: lwc1        $f6, 0x68($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X68);
    // 0x8017640C: lw          $a3, 0x64($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X64);
    // 0x80176410: addu        $t4, $t7, $t8
    ctx->r12 = ADD32(ctx->r15, ctx->r24);
    // 0x80176414: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80176418: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x8017641C: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x80176420: addu        $t5, $t4, $t0
    ctx->r13 = ADD32(ctx->r12, ctx->r8);
    // 0x80176424: lwc1        $f8, 0x14($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X14);
    // 0x80176428: lwc1        $f10, 0x0($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X0);
    // 0x8017642C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80176430: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80176434: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80176438: addu        $t2, $t9, $t0
    ctx->r10 = ADD32(ctx->r25, ctx->r8);
    // 0x8017643C: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x80176440: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80176444: addu        $t3, $t7, $t8
    ctx->r11 = ADD32(ctx->r15, ctx->r24);
    // 0x80176448: addu        $t4, $t3, $t0
    ctx->r12 = ADD32(ctx->r11, ctx->r8);
    // 0x8017644C: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x80176450: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x80176454: lwc1        $f4, 0x0($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X0);
    // 0x80176458: lwc1        $f16, 0x14($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X14);
    // 0x8017645C: addu        $t6, $t7, $t8
    ctx->r14 = ADD32(ctx->r15, ctx->r24);
    // 0x80176460: addu        $t9, $t6, $t0
    ctx->r25 = ADD32(ctx->r14, ctx->r8);
    // 0x80176464: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x80176468: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8017646C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80176470: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80176474: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x80176478: lw          $a0, -0x274C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X274C);
    // 0x8017647C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80176480: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x80176484: lwc1        $f10, 0x0($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X0);
    // 0x80176488: lwc1        $f8, 0x14($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X14);
    // 0x8017648C: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80176490: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    // 0x80176494: lwc1        $f16, 0x14($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X14);
    // 0x80176498: lwc1        $f8, 0x4($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X4);
    // 0x8017649C: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x801764A0: sub.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x801764A4: jal         0x800C6144
    // 0x801764A8: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    func_800C6144(rdram, ctx);
        goto after_1;
    // 0x801764A8: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    after_1:
L_801764AC:
    // 0x801764AC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x801764B0: lw          $t1, -0x2E3C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2E3C);
    // 0x801764B4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801764B8: bne         $t1, $at, L_80176664
    if (ctx->r9 != ctx->r1) {
        // 0x801764BC: nop
    
            goto L_80176664;
    }
    // 0x801764BC: nop

    // 0x801764C0: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x801764C4: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x801764C8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801764CC: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x801764D0: sll         $t7, $t5, 3
    ctx->r15 = S32(ctx->r13 << 3);
    // 0x801764D4: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x801764D8: subu        $t7, $t7, $t5
    ctx->r15 = SUB32(ctx->r15, ctx->r13);
    // 0x801764DC: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x801764E0: sll         $t4, $t4, 5
    ctx->r12 = S32(ctx->r12 << 5);
    // 0x801764E4: addu        $t8, $t4, $t7
    ctx->r24 = ADD32(ctx->r12, ctx->r15);
    // 0x801764E8: addu        $t6, $t6, $t8
    ctx->r14 = ADD32(ctx->r14, ctx->r24);
    // 0x801764EC: lw          $t6, 0x3524($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3524);
    // 0x801764F0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801764F4: bne         $t6, $at, L_80176664
    if (ctx->r14 != ctx->r1) {
        // 0x801764F8: nop
    
            goto L_80176664;
    }
    // 0x801764F8: nop

    // 0x801764FC: lui         $t0, 0x8011
    ctx->r8 = S32(0X8011 << 16);
    // 0x80176500: lw          $t0, -0x4514($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X4514);
    // 0x80176504: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80176508: lui         $t2, 0xFA00
    ctx->r10 = S32(0XFA00 << 16);
    // 0x8017650C: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x80176510: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80176514: addiu       $t9, $t0, 0x8
    ctx->r25 = ADD32(ctx->r8, 0X8);
    // 0x80176518: sw          $t9, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r25;
    // 0x8017651C: sw          $t2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r10;
    // 0x80176520: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x80176524: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x80176528: addiu       $t4, $t4, -0x26EC
    ctx->r12 = ADD32(ctx->r12, -0X26EC);
    // 0x8017652C: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x80176530: subu        $t5, $t5, $t3
    ctx->r13 = SUB32(ctx->r13, ctx->r11);
    // 0x80176534: addu        $t7, $t5, $t4
    ctx->r15 = ADD32(ctx->r13, ctx->r12);
    // 0x80176538: lbu         $t9, 0x1($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X1);
    // 0x8017653C: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x80176540: lbu         $t5, 0x2($t7)
    ctx->r13 = MEM_BU(ctx->r15, 0X2);
    // 0x80176544: andi        $t2, $t9, 0xFF
    ctx->r10 = ctx->r25 & 0XFF;
    // 0x80176548: sll         $t1, $t2, 16
    ctx->r9 = S32(ctx->r10 << 16);
    // 0x8017654C: andi        $t6, $t8, 0xFF
    ctx->r14 = ctx->r24 & 0XFF;
    // 0x80176550: sll         $t0, $t6, 24
    ctx->r8 = S32(ctx->r14 << 24);
    // 0x80176554: andi        $t4, $t5, 0xFF
    ctx->r12 = ctx->r13 & 0XFF;
    // 0x80176558: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x8017655C: sll         $t8, $t4, 8
    ctx->r24 = S32(ctx->r12 << 8);
    // 0x80176560: or          $t3, $t0, $t1
    ctx->r11 = ctx->r8 | ctx->r9;
    // 0x80176564: or          $t6, $t8, $t3
    ctx->r14 = ctx->r24 | ctx->r11;
    // 0x80176568: ori         $t9, $t6, 0x96
    ctx->r25 = ctx->r14 | 0X96;
    // 0x8017656C: sw          $t9, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r25;
    // 0x80176570: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x80176574: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x80176578: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8017657C: sll         $t7, $t0, 3
    ctx->r15 = S32(ctx->r8 << 3);
    // 0x80176580: sll         $t4, $t5, 3
    ctx->r12 = S32(ctx->r13 << 3);
    // 0x80176584: subu        $t7, $t7, $t0
    ctx->r15 = SUB32(ctx->r15, ctx->r8);
    // 0x80176588: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8017658C: subu        $t4, $t4, $t5
    ctx->r12 = SUB32(ctx->r12, ctx->r13);
    // 0x80176590: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x80176594: addu        $a0, $a0, $t1
    ctx->r4 = ADD32(ctx->r4, ctx->r9);
    // 0x80176598: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x8017659C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x801765A0: addiu       $t3, $t3, 0x3518
    ctx->r11 = ADD32(ctx->r11, 0X3518);
    // 0x801765A4: addu        $t1, $t7, $t4
    ctx->r9 = ADD32(ctx->r15, ctx->r12);
    // 0x801765A8: addu        $t0, $t1, $t3
    ctx->r8 = ADD32(ctx->r9, ctx->r11);
    // 0x801765AC: addu        $t8, $t7, $t4
    ctx->r24 = ADD32(ctx->r15, ctx->r12);
    // 0x801765B0: lwc1        $f18, 0x28($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X28);
    // 0x801765B4: addu        $t6, $t8, $t3
    ctx->r14 = ADD32(ctx->r24, ctx->r11);
    // 0x801765B8: addu        $t9, $t7, $t4
    ctx->r25 = ADD32(ctx->r15, ctx->r12);
    // 0x801765BC: addu        $t2, $t9, $t3
    ctx->r10 = ADD32(ctx->r25, ctx->r11);
    // 0x801765C0: lw          $a2, 0x18($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X18);
    // 0x801765C4: lw          $a3, 0x20($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X20);
    // 0x801765C8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801765CC: addu        $t5, $t7, $t4
    ctx->r13 = ADD32(ctx->r15, ctx->r12);
    // 0x801765D0: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x801765D4: addu        $t8, $t5, $t3
    ctx->r24 = ADD32(ctx->r13, ctx->r11);
    // 0x801765D8: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x801765DC: lwc1        $f4, 0x0($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X0);
    // 0x801765E0: lwc1        $f16, 0x30($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X30);
    // 0x801765E4: addu        $t9, $t7, $t4
    ctx->r25 = ADD32(ctx->r15, ctx->r12);
    // 0x801765E8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x801765EC: mul.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x801765F0: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x801765F4: addu        $t2, $t9, $t3
    ctx->r10 = ADD32(ctx->r25, ctx->r11);
    // 0x801765F8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x801765FC: addu        $t0, $t7, $t4
    ctx->r8 = ADD32(ctx->r15, ctx->r12);
    // 0x80176600: addu        $t5, $t0, $t3
    ctx->r13 = ADD32(ctx->r8, ctx->r11);
    // 0x80176604: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x80176608: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x8017660C: lwc1        $f10, 0x0($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X0);
    // 0x80176610: lwc1        $f6, 0x30($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X30);
    // 0x80176614: addu        $t6, $t7, $t4
    ctx->r14 = ADD32(ctx->r15, ctx->r12);
    // 0x80176618: addu        $t9, $t6, $t3
    ctx->r25 = ADD32(ctx->r14, ctx->r11);
    // 0x8017661C: mul.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80176620: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80176624: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80176628: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017662C: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x80176630: lw          $a0, -0x275C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X275C);
    // 0x80176634: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80176638: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    // 0x8017663C: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    // 0x80176640: lwc1        $f16, 0x30($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0X30);
    // 0x80176644: mul.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x80176648: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x8017664C: lwc1        $f6, 0x30($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X30);
    // 0x80176650: lwc1        $f16, 0x4($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X4);
    // 0x80176654: mul.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80176658: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8017665C: jal         0x800C6144
    // 0x80176660: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    func_800C6144(rdram, ctx);
        goto after_2;
    // 0x80176660: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    after_2:
L_80176664:
    // 0x80176664: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80176668: lw          $t1, -0x2E3C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2E3C);
    // 0x8017666C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80176670: bne         $t1, $at, L_8017681C
    if (ctx->r9 != ctx->r1) {
        // 0x80176674: nop
    
            goto L_8017681C;
    }
    // 0x80176674: nop

    // 0x80176678: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x8017667C: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x80176680: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80176684: sll         $t5, $t0, 3
    ctx->r13 = S32(ctx->r8 << 3);
    // 0x80176688: sll         $t7, $t8, 3
    ctx->r15 = S32(ctx->r24 << 3);
    // 0x8017668C: subu        $t5, $t5, $t0
    ctx->r13 = SUB32(ctx->r13, ctx->r8);
    // 0x80176690: subu        $t7, $t7, $t8
    ctx->r15 = SUB32(ctx->r15, ctx->r24);
    // 0x80176694: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80176698: sll         $t5, $t5, 5
    ctx->r13 = S32(ctx->r13 << 5);
    // 0x8017669C: addu        $t4, $t5, $t7
    ctx->r12 = ADD32(ctx->r13, ctx->r15);
    // 0x801766A0: addu        $t6, $t6, $t4
    ctx->r14 = ADD32(ctx->r14, ctx->r12);
    // 0x801766A4: lw          $t6, 0x3528($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3528);
    // 0x801766A8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801766AC: bne         $t6, $at, L_8017681C
    if (ctx->r14 != ctx->r1) {
        // 0x801766B0: nop
    
            goto L_8017681C;
    }
    // 0x801766B0: nop

    // 0x801766B4: lui         $t3, 0x8011
    ctx->r11 = S32(0X8011 << 16);
    // 0x801766B8: lw          $t3, -0x4514($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4514);
    // 0x801766BC: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x801766C0: lui         $t2, 0xFA00
    ctx->r10 = S32(0XFA00 << 16);
    // 0x801766C4: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    // 0x801766C8: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x801766CC: addiu       $t9, $t3, 0x8
    ctx->r25 = ADD32(ctx->r11, 0X8);
    // 0x801766D0: sw          $t9, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r25;
    // 0x801766D4: sw          $t2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r10;
    // 0x801766D8: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x801766DC: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x801766E0: addiu       $t5, $t5, -0x26EC
    ctx->r13 = ADD32(ctx->r13, -0X26EC);
    // 0x801766E4: sll         $t8, $t0, 2
    ctx->r24 = S32(ctx->r8 << 2);
    // 0x801766E8: subu        $t8, $t8, $t0
    ctx->r24 = SUB32(ctx->r24, ctx->r8);
    // 0x801766EC: addu        $t7, $t8, $t5
    ctx->r15 = ADD32(ctx->r24, ctx->r13);
    // 0x801766F0: lbu         $t9, 0x1($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X1);
    // 0x801766F4: lbu         $t4, 0x0($t7)
    ctx->r12 = MEM_BU(ctx->r15, 0X0);
    // 0x801766F8: lbu         $t8, 0x2($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X2);
    // 0x801766FC: andi        $t2, $t9, 0xFF
    ctx->r10 = ctx->r25 & 0XFF;
    // 0x80176700: sll         $t1, $t2, 16
    ctx->r9 = S32(ctx->r10 << 16);
    // 0x80176704: andi        $t6, $t4, 0xFF
    ctx->r14 = ctx->r12 & 0XFF;
    // 0x80176708: sll         $t3, $t6, 24
    ctx->r11 = S32(ctx->r14 << 24);
    // 0x8017670C: andi        $t5, $t8, 0xFF
    ctx->r13 = ctx->r24 & 0XFF;
    // 0x80176710: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x80176714: sll         $t4, $t5, 8
    ctx->r12 = S32(ctx->r13 << 8);
    // 0x80176718: or          $t0, $t3, $t1
    ctx->r8 = ctx->r11 | ctx->r9;
    // 0x8017671C: or          $t6, $t4, $t0
    ctx->r14 = ctx->r12 | ctx->r8;
    // 0x80176720: ori         $t9, $t6, 0x32
    ctx->r25 = ctx->r14 | 0X32;
    // 0x80176724: sw          $t9, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r25;
    // 0x80176728: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x8017672C: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x80176730: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80176734: sll         $t7, $t3, 3
    ctx->r15 = S32(ctx->r11 << 3);
    // 0x80176738: sll         $t5, $t8, 3
    ctx->r13 = S32(ctx->r24 << 3);
    // 0x8017673C: subu        $t7, $t7, $t3
    ctx->r15 = SUB32(ctx->r15, ctx->r11);
    // 0x80176740: sll         $t1, $t3, 2
    ctx->r9 = S32(ctx->r11 << 2);
    // 0x80176744: subu        $t5, $t5, $t8
    ctx->r13 = SUB32(ctx->r13, ctx->r24);
    // 0x80176748: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8017674C: addu        $a0, $a0, $t1
    ctx->r4 = ADD32(ctx->r4, ctx->r9);
    // 0x80176750: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x80176754: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80176758: addiu       $t0, $t0, 0x3518
    ctx->r8 = ADD32(ctx->r8, 0X3518);
    // 0x8017675C: addu        $t1, $t7, $t5
    ctx->r9 = ADD32(ctx->r15, ctx->r13);
    // 0x80176760: addu        $t3, $t1, $t0
    ctx->r11 = ADD32(ctx->r9, ctx->r8);
    // 0x80176764: addu        $t4, $t7, $t5
    ctx->r12 = ADD32(ctx->r15, ctx->r13);
    // 0x80176768: lwc1        $f8, 0x2C($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X2C);
    // 0x8017676C: addu        $t6, $t4, $t0
    ctx->r14 = ADD32(ctx->r12, ctx->r8);
    // 0x80176770: addu        $t9, $t7, $t5
    ctx->r25 = ADD32(ctx->r15, ctx->r13);
    // 0x80176774: addu        $t2, $t9, $t0
    ctx->r10 = ADD32(ctx->r25, ctx->r8);
    // 0x80176778: lw          $a2, 0x1C($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X1C);
    // 0x8017677C: lw          $a3, 0x24($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X24);
    // 0x80176780: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80176784: addu        $t8, $t7, $t5
    ctx->r24 = ADD32(ctx->r15, ctx->r13);
    // 0x80176788: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x8017678C: addu        $t4, $t8, $t0
    ctx->r12 = ADD32(ctx->r24, ctx->r8);
    // 0x80176790: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x80176794: lwc1        $f10, 0x0($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X0);
    // 0x80176798: lwc1        $f6, 0x34($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X34);
    // 0x8017679C: addu        $t9, $t7, $t5
    ctx->r25 = ADD32(ctx->r15, ctx->r13);
    // 0x801767A0: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x801767A4: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x801767A8: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x801767AC: addu        $t2, $t9, $t0
    ctx->r10 = ADD32(ctx->r25, ctx->r8);
    // 0x801767B0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x801767B4: addu        $t3, $t7, $t5
    ctx->r11 = ADD32(ctx->r15, ctx->r13);
    // 0x801767B8: addu        $t8, $t3, $t0
    ctx->r24 = ADD32(ctx->r11, ctx->r8);
    // 0x801767BC: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x801767C0: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x801767C4: lwc1        $f4, 0x0($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X0);
    // 0x801767C8: lwc1        $f18, 0x34($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X34);
    // 0x801767CC: addu        $t6, $t7, $t5
    ctx->r14 = ADD32(ctx->r15, ctx->r13);
    // 0x801767D0: addu        $t9, $t6, $t0
    ctx->r25 = ADD32(ctx->r14, ctx->r8);
    // 0x801767D4: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x801767D8: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x801767DC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801767E0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x801767E4: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x801767E8: lw          $a0, -0x275C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X275C);
    // 0x801767EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801767F0: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x801767F4: lwc1        $f10, 0x0($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X0);
    // 0x801767F8: lwc1        $f6, 0x34($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X34);
    // 0x801767FC: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80176800: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    // 0x80176804: lwc1        $f18, 0x34($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X34);
    // 0x80176808: lwc1        $f6, 0x4($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X4);
    // 0x8017680C: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80176810: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80176814: jal         0x800C6144
    // 0x80176818: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    func_800C6144(rdram, ctx);
        goto after_3;
    // 0x80176818: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    after_3:
L_8017681C:
    // 0x8017681C: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x80176820: addiu       $t3, $t1, 0x1
    ctx->r11 = ADD32(ctx->r9, 0X1);
    // 0x80176824: sltiu       $at, $t3, 0x4
    ctx->r1 = ctx->r11 < 0X4 ? 1 : 0;
    // 0x80176828: bne         $at, $zero, L_80175FCC
    if (ctx->r1 != 0) {
        // 0x8017682C: sw          $t3, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r11;
            goto L_80175FCC;
    }
    // 0x8017682C: sw          $t3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r11;
    // 0x80176830: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x80176834: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80176838: lw          $t7, -0x2E3C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2E3C);
    // 0x8017683C: addiu       $t4, $t8, 0x1
    ctx->r12 = ADD32(ctx->r24, 0X1);
    // 0x80176840: sw          $t4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r12;
    // 0x80176844: sltu        $at, $t4, $t7
    ctx->r1 = ctx->r12 < ctx->r15 ? 1 : 0;
    // 0x80176848: bne         $at, $zero, L_80175FC8
    if (ctx->r1 != 0) {
        // 0x8017684C: nop
    
            goto L_80175FC8;
    }
    // 0x8017684C: nop

L_80176850:
    // 0x80176850: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80176854: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80176858: jr          $ra
    // 0x8017685C: nop

    return;
    // 0x8017685C: nop

;}
RECOMP_FUNC void func_80176860_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80176860: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80176864: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80176868: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8017686C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80176870: addiu       $t6, $t6, -0x2E18
    ctx->r14 = ADD32(ctx->r14, -0X2E18);
    // 0x80176874: lw          $t7, 0x7C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X7C);
    // 0x80176878: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8017687C: beq         $t7, $at, L_80176E2C
    if (ctx->r15 == ctx->r1) {
        // 0x80176880: nop
    
            goto L_80176E2C;
    }
    // 0x80176880: nop

    // 0x80176884: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80176888: lw          $s0, -0x2E48($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X2E48);
    // 0x8017688C: beq         $s0, $zero, L_801768AC
    if (ctx->r16 == 0) {
        // 0x80176890: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_801768AC;
    }
    // 0x80176890: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80176894: beq         $s0, $at, L_80176958
    if (ctx->r16 == ctx->r1) {
        // 0x80176898: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80176958;
    }
    // 0x80176898: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8017689C: beq         $s0, $at, L_80176B58
    if (ctx->r16 == ctx->r1) {
        // 0x801768A0: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80176B58;
    }
    // 0x801768A0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801768A4: bne         $s0, $at, L_80176E2C
    if (ctx->r16 != ctx->r1) {
        // 0x801768A8: nop
    
            goto L_80176E2C;
    }
    // 0x801768A8: nop

L_801768AC:
    // 0x801768AC: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
L_801768B0:
    // 0x801768B0: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x801768B4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801768B8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801768BC: sll         $a1, $t8, 2
    ctx->r5 = S32(ctx->r24 << 2);
    // 0x801768C0: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x801768C4: subu        $a1, $a1, $t8
    ctx->r5 = SUB32(ctx->r5, ctx->r24);
    // 0x801768C8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x801768CC: addu        $a0, $a0, $t9
    ctx->r4 = ADD32(ctx->r4, ctx->r25);
    // 0x801768D0: sll         $a1, $a1, 4
    ctx->r5 = S32(ctx->r5 << 4);
    // 0x801768D4: addiu       $t0, $zero, 0x82
    ctx->r8 = ADD32(0, 0X82);
    // 0x801768D8: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x801768DC: addiu       $a1, $a1, 0x30
    ctx->r5 = ADD32(ctx->r5, 0X30);
    // 0x801768E0: lw          $a0, -0xEE8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0XEE8);
    // 0x801768E4: addiu       $a2, $zero, 0x8C
    ctx->r6 = ADD32(0, 0X8C);
    // 0x801768E8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801768EC: jal         0x800C6C6C
    // 0x801768F0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_0;
    // 0x801768F0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x801768F4: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x801768F8: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x801768FC: sltiu       $at, $t2, 0x5
    ctx->r1 = ctx->r10 < 0X5 ? 1 : 0;
    // 0x80176900: bne         $at, $zero, L_801768B0
    if (ctx->r1 != 0) {
        // 0x80176904: sw          $t2, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r10;
            goto L_801768B0;
    }
    // 0x80176904: sw          $t2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r10;
    // 0x80176908: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017690C: addiu       $t3, $t3, 0x39A0
    ctx->r11 = ADD32(ctx->r11, 0X39A0);
    // 0x80176910: lw          $a1, 0x8($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X8);
    // 0x80176914: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80176918: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017691C: sll         $t4, $a1, 2
    ctx->r12 = S32(ctx->r5 << 2);
    // 0x80176920: subu        $t4, $t4, $a1
    ctx->r12 = SUB32(ctx->r12, ctx->r5);
    // 0x80176924: sll         $t4, $t4, 4
    ctx->r12 = S32(ctx->r12 << 4);
    // 0x80176928: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    // 0x8017692C: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80176930: addiu       $t5, $zero, 0x82
    ctx->r13 = ADD32(0, 0X82);
    // 0x80176934: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80176938: addiu       $a0, $a0, 0xED4
    ctx->r4 = ADD32(ctx->r4, 0XED4);
    // 0x8017693C: addiu       $a1, $a1, 0x30
    ctx->r5 = ADD32(ctx->r5, 0X30);
    // 0x80176940: addiu       $a2, $zero, 0x8C
    ctx->r6 = ADD32(0, 0X8C);
    // 0x80176944: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80176948: jal         0x800C6C6C
    // 0x8017694C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_1;
    // 0x8017694C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x80176950: b           L_80176E2C
    // 0x80176954: nop

        goto L_80176E2C;
    // 0x80176954: nop

L_80176958:
    // 0x80176958: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
L_8017695C:
    // 0x8017695C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80176960: addiu       $t7, $t7, 0x3B00
    ctx->r15 = ADD32(ctx->r15, 0X3B00);
    // 0x80176964: addiu       $t6, $zero, 0xC8
    ctx->r14 = ADD32(0, 0XC8);
    // 0x80176968: sb          $t6, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r14;
    // 0x8017696C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80176970: lw          $t9, -0x2E3C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2E3C);
    // 0x80176974: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x80176978: beq         $t9, $zero, L_801769F8
    if (ctx->r25 == 0) {
        // 0x8017697C: nop
    
            goto L_801769F8;
    }
    // 0x8017697C: nop

L_80176980:
    // 0x80176980: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80176984: addiu       $t8, $t8, -0x2E18
    ctx->r24 = ADD32(ctx->r24, -0X2E18);
    // 0x80176988: lw          $t0, 0x7C($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X7C);
    // 0x8017698C: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80176990: beq         $t0, $t1, L_801769D8
    if (ctx->r8 == ctx->r9) {
        // 0x80176994: nop
    
            goto L_801769D8;
    }
    // 0x80176994: nop

    // 0x80176998: sll         $t2, $t1, 5
    ctx->r10 = S32(ctx->r9 << 5);
    // 0x8017699C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x801769A0: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x801769A4: lw          $t3, 0x39A8($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X39A8);
    // 0x801769A8: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x801769AC: bne         $t3, $t4, L_801769D8
    if (ctx->r11 != ctx->r12) {
        // 0x801769B0: nop
    
            goto L_801769D8;
    }
    // 0x801769B0: nop

    // 0x801769B4: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x801769B8: addiu       $t5, $t5, 0x3B00
    ctx->r13 = ADD32(ctx->r13, 0X3B00);
    // 0x801769BC: lbu         $t6, 0x0($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X0);
    // 0x801769C0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x801769C4: div         $zero, $t6, $at
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r1)));
    // 0x801769C8: mflo        $t7
    ctx->r15 = lo;
    // 0x801769CC: sb          $t7, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r15;
    // 0x801769D0: b           L_801769F8
    // 0x801769D4: nop

        goto L_801769F8;
    // 0x801769D4: nop

L_801769D8:
    // 0x801769D8: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x801769DC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x801769E0: lw          $t0, -0x2E3C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2E3C);
    // 0x801769E4: addiu       $t8, $t9, 0x1
    ctx->r24 = ADD32(ctx->r25, 0X1);
    // 0x801769E8: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x801769EC: sltu        $at, $t8, $t0
    ctx->r1 = ctx->r24 < ctx->r8 ? 1 : 0;
    // 0x801769F0: bne         $at, $zero, L_80176980
    if (ctx->r1 != 0) {
        // 0x801769F4: nop
    
            goto L_80176980;
    }
    // 0x801769F4: nop

L_801769F8:
    // 0x801769F8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x801769FC: addiu       $t3, $t3, -0x2E18
    ctx->r11 = ADD32(ctx->r11, -0X2E18);
    // 0x80176A00: lw          $t4, 0x7C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X7C);
    // 0x80176A04: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80176A08: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80176A0C: sll         $t6, $t4, 1
    ctx->r14 = S32(ctx->r12 << 1);
    // 0x80176A10: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80176A14: addiu       $t5, $t5, -0x26C8
    ctx->r13 = ADD32(ctx->r13, -0X26C8);
    // 0x80176A18: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80176A1C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80176A20: addu        $t9, $t7, $t5
    ctx->r25 = ADD32(ctx->r15, ctx->r13);
    // 0x80176A24: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80176A28: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80176A2C: addu        $a0, $a0, $t2
    ctx->r4 = ADD32(ctx->r4, ctx->r10);
    // 0x80176A30: sll         $t0, $t1, 2
    ctx->r8 = S32(ctx->r9 << 2);
    // 0x80176A34: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x80176A38: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80176A3C: lw          $a2, 0x4($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X4);
    // 0x80176A40: subu        $t0, $t0, $t1
    ctx->r8 = SUB32(ctx->r8, ctx->r9);
    // 0x80176A44: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80176A48: addiu       $t2, $t2, 0x3B00
    ctx->r10 = ADD32(ctx->r10, 0X3B00);
    // 0x80176A4C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x80176A50: lbu         $t3, 0x0($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X0);
    // 0x80176A54: addu        $t0, $t0, $t1
    ctx->r8 = ADD32(ctx->r8, ctx->r9);
    // 0x80176A58: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x80176A5C: lw          $a0, -0xEE8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0XEE8);
    // 0x80176A60: lui         $a3, 0x3F40
    ctx->r7 = S32(0X3F40 << 16);
    // 0x80176A64: addu        $a1, $t8, $t0
    ctx->r5 = ADD32(ctx->r24, ctx->r8);
    // 0x80176A68: jal         0x800C6C6C
    // 0x80176A6C: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    func_800C6C6C(rdram, ctx);
        goto after_2;
    // 0x80176A6C: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    after_2:
    // 0x80176A70: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80176A74: addiu       $t6, $t4, 0x1
    ctx->r14 = ADD32(ctx->r12, 0X1);
    // 0x80176A78: sltiu       $at, $t6, 0x5
    ctx->r1 = ctx->r14 < 0X5 ? 1 : 0;
    // 0x80176A7C: bne         $at, $zero, L_8017695C
    if (ctx->r1 != 0) {
        // 0x80176A80: sw          $t6, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r14;
            goto L_8017695C;
    }
    // 0x80176A80: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x80176A84: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80176A88: lw          $t7, -0x2E3C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2E3C);
    // 0x80176A8C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80176A90: beq         $t7, $zero, L_80176E2C
    if (ctx->r15 == 0) {
        // 0x80176A94: nop
    
            goto L_80176E2C;
    }
    // 0x80176A94: nop

L_80176A98:
    // 0x80176A98: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x80176A9C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80176AA0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80176AA4: sll         $t8, $t5, 5
    ctx->r24 = S32(ctx->r13 << 5);
    // 0x80176AA8: addu        $t0, $t0, $t8
    ctx->r8 = ADD32(ctx->r8, ctx->r24);
    // 0x80176AAC: lw          $t0, 0x39A8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X39A8);
    // 0x80176AB0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80176AB4: addiu       $t2, $t2, -0x2E18
    ctx->r10 = ADD32(ctx->r10, -0X2E18);
    // 0x80176AB8: sll         $t9, $t0, 2
    ctx->r25 = S32(ctx->r8 << 2);
    // 0x80176ABC: subu        $t9, $t9, $t0
    ctx->r25 = SUB32(ctx->r25, ctx->r8);
    // 0x80176AC0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80176AC4: lw          $t3, 0x7C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X7C);
    // 0x80176AC8: addiu       $t8, $t8, -0x2E18
    ctx->r24 = ADD32(ctx->r24, -0X2E18);
    // 0x80176ACC: addu        $t9, $t9, $t0
    ctx->r25 = ADD32(ctx->r25, ctx->r8);
    // 0x80176AD0: lw          $t0, 0x7C($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X7C);
    // 0x80176AD4: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80176AD8: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80176ADC: sll         $t1, $t5, 2
    ctx->r9 = S32(ctx->r13 << 2);
    // 0x80176AE0: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x80176AE4: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x80176AE8: addu        $a0, $a0, $t1
    ctx->r4 = ADD32(ctx->r4, ctx->r9);
    // 0x80176AEC: addiu       $t7, $t7, -0x26C8
    ctx->r15 = ADD32(ctx->r15, -0X26C8);
    // 0x80176AF0: sll         $t2, $t0, 1
    ctx->r10 = S32(ctx->r8 << 1);
    // 0x80176AF4: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80176AF8: addu        $t1, $t6, $t7
    ctx->r9 = ADD32(ctx->r14, ctx->r15);
    // 0x80176AFC: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80176B00: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80176B04: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x80176B08: addu        $t4, $t3, $t7
    ctx->r12 = ADD32(ctx->r11, ctx->r15);
    // 0x80176B0C: lw          $a2, 0x4($t4)
    ctx->r6 = MEM_W(ctx->r12, 0X4);
    // 0x80176B10: addiu       $t6, $zero, 0xC8
    ctx->r14 = ADD32(0, 0XC8);
    // 0x80176B14: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x80176B18: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80176B1C: lw          $a0, -0xEF8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0XEF8);
    // 0x80176B20: lui         $a3, 0x3F40
    ctx->r7 = S32(0X3F40 << 16);
    // 0x80176B24: addu        $a1, $t9, $t5
    ctx->r5 = ADD32(ctx->r25, ctx->r13);
    // 0x80176B28: jal         0x800C6C6C
    // 0x80176B2C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_3;
    // 0x80176B2C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_3:
    // 0x80176B30: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80176B34: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80176B38: lw          $t5, -0x2E3C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2E3C);
    // 0x80176B3C: addiu       $t9, $t1, 0x1
    ctx->r25 = ADD32(ctx->r9, 0X1);
    // 0x80176B40: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x80176B44: sltu        $at, $t9, $t5
    ctx->r1 = ctx->r25 < ctx->r13 ? 1 : 0;
    // 0x80176B48: bne         $at, $zero, L_80176A98
    if (ctx->r1 != 0) {
        // 0x80176B4C: nop
    
            goto L_80176A98;
    }
    // 0x80176B4C: nop

    // 0x80176B50: b           L_80176E2C
    // 0x80176B54: nop

        goto L_80176E2C;
    // 0x80176B54: nop

L_80176B58:
    // 0x80176B58: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80176B5C: addiu       $t8, $t8, -0x2E18
    ctx->r24 = ADD32(ctx->r24, -0X2E18);
    // 0x80176B60: lw          $t0, 0x7C($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X7C);
    // 0x80176B64: beq         $t0, $zero, L_80176B74
    if (ctx->r8 == 0) {
        // 0x80176B68: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80176B74;
    }
    // 0x80176B68: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80176B6C: bne         $t0, $at, L_80176CD4
    if (ctx->r8 != ctx->r1) {
        // 0x80176B70: nop
    
            goto L_80176CD4;
    }
    // 0x80176B70: nop

L_80176B74:
    // 0x80176B74: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
L_80176B78:
    // 0x80176B78: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80176B7C: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80176B80: addiu       $t2, $t2, -0x2E18
    ctx->r10 = ADD32(ctx->r10, -0X2E18);
    // 0x80176B84: lw          $t3, 0x48($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X48);
    // 0x80176B88: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80176B8C: sllv        $t6, $t4, $t7
    ctx->r14 = S32(ctx->r12 << (ctx->r15 & 31));
    // 0x80176B90: and         $t1, $t3, $t6
    ctx->r9 = ctx->r11 & ctx->r14;
    // 0x80176B94: beq         $t1, $zero, L_80176BB0
    if (ctx->r9 == 0) {
        // 0x80176B98: nop
    
            goto L_80176BB0;
    }
    // 0x80176B98: nop

    // 0x80176B9C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80176BA0: addiu       $t5, $t5, 0x3B00
    ctx->r13 = ADD32(ctx->r13, 0X3B00);
    // 0x80176BA4: addiu       $t9, $zero, 0xC8
    ctx->r25 = ADD32(0, 0XC8);
    // 0x80176BA8: b           L_80176BC0
    // 0x80176BAC: sb          $t9, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r25;
        goto L_80176BC0;
    // 0x80176BAC: sb          $t9, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r25;
L_80176BB0:
    // 0x80176BB0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80176BB4: addiu       $t0, $t0, 0x3B00
    ctx->r8 = ADD32(ctx->r8, 0X3B00);
    // 0x80176BB8: addiu       $t8, $zero, 0x28
    ctx->r24 = ADD32(0, 0X28);
    // 0x80176BBC: sb          $t8, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r24;
L_80176BC0:
    // 0x80176BC0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80176BC4: addiu       $t7, $t7, -0x2E18
    ctx->r15 = ADD32(ctx->r15, -0X2E18);
    // 0x80176BC8: lw          $t3, 0x7C($t7)
    ctx->r11 = MEM_W(ctx->r15, 0X7C);
    // 0x80176BCC: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x80176BD0: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80176BD4: sll         $t6, $t3, 1
    ctx->r14 = S32(ctx->r11 << 1);
    // 0x80176BD8: sll         $t1, $t6, 2
    ctx->r9 = S32(ctx->r14 << 2);
    // 0x80176BDC: addiu       $t9, $t9, -0x26C8
    ctx->r25 = ADD32(ctx->r25, -0X26C8);
    // 0x80176BE0: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80176BE4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80176BE8: addu        $t5, $t1, $t9
    ctx->r13 = ADD32(ctx->r9, ctx->r25);
    // 0x80176BEC: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80176BF0: sll         $t4, $t2, 2
    ctx->r12 = S32(ctx->r10 << 2);
    // 0x80176BF4: addu        $a0, $a0, $t4
    ctx->r4 = ADD32(ctx->r4, ctx->r12);
    // 0x80176BF8: sll         $t0, $t2, 2
    ctx->r8 = S32(ctx->r10 << 2);
    // 0x80176BFC: lw          $t8, 0x0($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X0);
    // 0x80176C00: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80176C04: lw          $a2, 0x4($t5)
    ctx->r6 = MEM_W(ctx->r13, 0X4);
    // 0x80176C08: subu        $t0, $t0, $t2
    ctx->r8 = SUB32(ctx->r8, ctx->r10);
    // 0x80176C0C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80176C10: addiu       $t4, $t4, 0x3B00
    ctx->r12 = ADD32(ctx->r12, 0X3B00);
    // 0x80176C14: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x80176C18: lbu         $t7, 0x0($t4)
    ctx->r15 = MEM_BU(ctx->r12, 0X0);
    // 0x80176C1C: addu        $t0, $t0, $t2
    ctx->r8 = ADD32(ctx->r8, ctx->r10);
    // 0x80176C20: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x80176C24: lw          $a0, -0xEE8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0XEE8);
    // 0x80176C28: lui         $a3, 0x3F40
    ctx->r7 = S32(0X3F40 << 16);
    // 0x80176C2C: addu        $a1, $t8, $t0
    ctx->r5 = ADD32(ctx->r24, ctx->r8);
    // 0x80176C30: jal         0x800C6C6C
    // 0x80176C34: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    func_800C6C6C(rdram, ctx);
        goto after_4;
    // 0x80176C34: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_4:
    // 0x80176C38: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x80176C3C: addiu       $t6, $t3, 0x1
    ctx->r14 = ADD32(ctx->r11, 0X1);
    // 0x80176C40: sltiu       $at, $t6, 0x5
    ctx->r1 = ctx->r14 < 0X5 ? 1 : 0;
    // 0x80176C44: bne         $at, $zero, L_80176B78
    if (ctx->r1 != 0) {
        // 0x80176C48: sw          $t6, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r14;
            goto L_80176B78;
    }
    // 0x80176C48: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x80176C4C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80176C50: addiu       $t1, $t1, 0x39A0
    ctx->r9 = ADD32(ctx->r9, 0X39A0);
    // 0x80176C54: lw          $t9, 0x8($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X8);
    // 0x80176C58: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80176C5C: beq         $t9, $at, L_80176E2C
    if (ctx->r25 == ctx->r1) {
        // 0x80176C60: nop
    
            goto L_80176E2C;
    }
    // 0x80176C60: nop

    // 0x80176C64: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80176C68: addiu       $t8, $t8, -0x2E18
    ctx->r24 = ADD32(ctx->r24, -0X2E18);
    // 0x80176C6C: lw          $t0, 0x7C($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X7C);
    // 0x80176C70: sll         $t2, $t9, 2
    ctx->r10 = S32(ctx->r25 << 2);
    // 0x80176C74: subu        $t2, $t2, $t9
    ctx->r10 = SUB32(ctx->r10, ctx->r25);
    // 0x80176C78: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80176C7C: sll         $t5, $t0, 1
    ctx->r13 = S32(ctx->r8 << 1);
    // 0x80176C80: sll         $t4, $t5, 2
    ctx->r12 = S32(ctx->r13 << 2);
    // 0x80176C84: addiu       $t7, $t7, -0x26C8
    ctx->r15 = ADD32(ctx->r15, -0X26C8);
    // 0x80176C88: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80176C8C: addu        $t2, $t2, $t9
    ctx->r10 = ADD32(ctx->r10, ctx->r25);
    // 0x80176C90: addu        $t3, $t4, $t7
    ctx->r11 = ADD32(ctx->r12, ctx->r15);
    // 0x80176C94: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80176C98: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80176C9C: lw          $t6, 0x0($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X0);
    // 0x80176CA0: addu        $t1, $t4, $t7
    ctx->r9 = ADD32(ctx->r12, ctx->r15);
    // 0x80176CA4: lw          $a2, 0x4($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X4);
    // 0x80176CA8: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x80176CAC: addiu       $t9, $zero, 0xC8
    ctx->r25 = ADD32(0, 0XC8);
    // 0x80176CB0: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80176CB4: addiu       $a0, $a0, 0xED4
    ctx->r4 = ADD32(ctx->r4, 0XED4);
    // 0x80176CB8: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80176CBC: lui         $a3, 0x3F40
    ctx->r7 = S32(0X3F40 << 16);
    // 0x80176CC0: addu        $a1, $t2, $t6
    ctx->r5 = ADD32(ctx->r10, ctx->r14);
    // 0x80176CC4: jal         0x800C6C6C
    // 0x80176CC8: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_5;
    // 0x80176CC8: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_5:
    // 0x80176CCC: b           L_80176E2C
    // 0x80176CD0: nop

        goto L_80176E2C;
    // 0x80176CD0: nop

L_80176CD4:
    // 0x80176CD4: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
L_80176CD8:
    // 0x80176CD8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80176CDC: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x80176CE0: addiu       $t8, $t8, -0x2E18
    ctx->r24 = ADD32(ctx->r24, -0X2E18);
    // 0x80176CE4: lw          $t0, 0x4C($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X4C);
    // 0x80176CE8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80176CEC: sllv        $t2, $t3, $t5
    ctx->r10 = S32(ctx->r11 << (ctx->r13 & 31));
    // 0x80176CF0: and         $t6, $t0, $t2
    ctx->r14 = ctx->r8 & ctx->r10;
    // 0x80176CF4: beq         $t6, $zero, L_80176D10
    if (ctx->r14 == 0) {
        // 0x80176CF8: nop
    
            goto L_80176D10;
    }
    // 0x80176CF8: nop

    // 0x80176CFC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80176D00: addiu       $t7, $t7, 0x3B00
    ctx->r15 = ADD32(ctx->r15, 0X3B00);
    // 0x80176D04: addiu       $t4, $zero, 0xC8
    ctx->r12 = ADD32(0, 0XC8);
    // 0x80176D08: b           L_80176D20
    // 0x80176D0C: sb          $t4, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r12;
        goto L_80176D20;
    // 0x80176D0C: sb          $t4, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r12;
L_80176D10:
    // 0x80176D10: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80176D14: addiu       $t9, $t9, 0x3B00
    ctx->r25 = ADD32(ctx->r25, 0X3B00);
    // 0x80176D18: addiu       $t1, $zero, 0x28
    ctx->r9 = ADD32(0, 0X28);
    // 0x80176D1C: sb          $t1, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r9;
L_80176D20:
    // 0x80176D20: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80176D24: addiu       $t5, $t5, -0x2E18
    ctx->r13 = ADD32(ctx->r13, -0X2E18);
    // 0x80176D28: lw          $t0, 0x7C($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X7C);
    // 0x80176D2C: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x80176D30: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x80176D34: sll         $t2, $t0, 1
    ctx->r10 = S32(ctx->r8 << 1);
    // 0x80176D38: sll         $t6, $t2, 2
    ctx->r14 = S32(ctx->r10 << 2);
    // 0x80176D3C: addiu       $t4, $t4, -0x26C8
    ctx->r12 = ADD32(ctx->r12, -0X26C8);
    // 0x80176D40: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80176D44: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80176D48: addu        $t7, $t6, $t4
    ctx->r15 = ADD32(ctx->r14, ctx->r12);
    // 0x80176D4C: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80176D50: sll         $t3, $t8, 2
    ctx->r11 = S32(ctx->r24 << 2);
    // 0x80176D54: addu        $a0, $a0, $t3
    ctx->r4 = ADD32(ctx->r4, ctx->r11);
    // 0x80176D58: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80176D5C: lw          $t1, 0x0($t7)
    ctx->r9 = MEM_W(ctx->r15, 0X0);
    // 0x80176D60: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80176D64: lw          $a2, 0x4($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X4);
    // 0x80176D68: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80176D6C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80176D70: addiu       $t3, $t3, 0x3B00
    ctx->r11 = ADD32(ctx->r11, 0X3B00);
    // 0x80176D74: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80176D78: lbu         $t5, 0x0($t3)
    ctx->r13 = MEM_BU(ctx->r11, 0X0);
    // 0x80176D7C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80176D80: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x80176D84: lw          $a0, -0xEE8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0XEE8);
    // 0x80176D88: lui         $a3, 0x3F40
    ctx->r7 = S32(0X3F40 << 16);
    // 0x80176D8C: addu        $a1, $t1, $t9
    ctx->r5 = ADD32(ctx->r9, ctx->r25);
    // 0x80176D90: jal         0x800C6C6C
    // 0x80176D94: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    func_800C6C6C(rdram, ctx);
        goto after_6;
    // 0x80176D94: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    after_6:
    // 0x80176D98: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80176D9C: addiu       $t2, $t0, 0x1
    ctx->r10 = ADD32(ctx->r8, 0X1);
    // 0x80176DA0: sltiu       $at, $t2, 0x5
    ctx->r1 = ctx->r10 < 0X5 ? 1 : 0;
    // 0x80176DA4: bne         $at, $zero, L_80176CD8
    if (ctx->r1 != 0) {
        // 0x80176DA8: sw          $t2, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r10;
            goto L_80176CD8;
    }
    // 0x80176DA8: sw          $t2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r10;
    // 0x80176DAC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80176DB0: addiu       $t6, $t6, 0x39A0
    ctx->r14 = ADD32(ctx->r14, 0X39A0);
    // 0x80176DB4: lw          $t4, 0x28($t6)
    ctx->r12 = MEM_W(ctx->r14, 0X28);
    // 0x80176DB8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80176DBC: beq         $t4, $at, L_80176E2C
    if (ctx->r12 == ctx->r1) {
        // 0x80176DC0: nop
    
            goto L_80176E2C;
    }
    // 0x80176DC0: nop

    // 0x80176DC4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80176DC8: addiu       $t1, $t1, -0x2E18
    ctx->r9 = ADD32(ctx->r9, -0X2E18);
    // 0x80176DCC: lw          $t9, 0x7C($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X7C);
    // 0x80176DD0: sll         $t8, $t4, 2
    ctx->r24 = S32(ctx->r12 << 2);
    // 0x80176DD4: subu        $t8, $t8, $t4
    ctx->r24 = SUB32(ctx->r24, ctx->r12);
    // 0x80176DD8: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80176DDC: sll         $t7, $t9, 1
    ctx->r15 = S32(ctx->r25 << 1);
    // 0x80176DE0: sll         $t3, $t7, 2
    ctx->r11 = S32(ctx->r15 << 2);
    // 0x80176DE4: addiu       $t5, $t5, -0x26C8
    ctx->r13 = ADD32(ctx->r13, -0X26C8);
    // 0x80176DE8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80176DEC: addu        $t8, $t8, $t4
    ctx->r24 = ADD32(ctx->r24, ctx->r12);
    // 0x80176DF0: addu        $t0, $t3, $t5
    ctx->r8 = ADD32(ctx->r11, ctx->r13);
    // 0x80176DF4: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80176DF8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80176DFC: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x80176E00: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x80176E04: lw          $a2, 0x4($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X4);
    // 0x80176E08: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x80176E0C: addiu       $t4, $zero, 0xC8
    ctx->r12 = ADD32(0, 0XC8);
    // 0x80176E10: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80176E14: addiu       $a0, $a0, 0xF48
    ctx->r4 = ADD32(ctx->r4, 0XF48);
    // 0x80176E18: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80176E1C: lui         $a3, 0x3F40
    ctx->r7 = S32(0X3F40 << 16);
    // 0x80176E20: addu        $a1, $t8, $t2
    ctx->r5 = ADD32(ctx->r24, ctx->r10);
    // 0x80176E24: jal         0x800C6C6C
    // 0x80176E28: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_7;
    // 0x80176E28: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_7:
L_80176E2C:
    // 0x80176E2C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80176E30: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80176E34: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80176E38: jr          $ra
    // 0x80176E3C: nop

    return;
    // 0x80176E3C: nop

;}
RECOMP_FUNC void func_80176E40_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80176E40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80176E44: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80176E48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80176E4C: addiu       $t6, $t6, -0x2E28
    ctx->r14 = ADD32(ctx->r14, -0X2E28);
    // 0x80176E50: lbu         $t7, 0xC($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0XC);
    // 0x80176E54: andi        $t8, $t7, 0x4
    ctx->r24 = ctx->r15 & 0X4;
    // 0x80176E58: beq         $t8, $zero, L_80176E98
    if (ctx->r24 == 0) {
        // 0x80176E5C: nop
    
            goto L_80176E98;
    }
    // 0x80176E5C: nop

    // 0x80176E60: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80176E64: addiu       $t9, $t9, -0x2E18
    ctx->r25 = ADD32(ctx->r25, -0X2E18);
    // 0x80176E68: lw          $t0, 0x34($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X34);
    // 0x80176E6C: sltiu       $at, $t0, 0x5
    ctx->r1 = ctx->r8 < 0X5 ? 1 : 0;
    // 0x80176E70: beq         $at, $zero, L_80176E84
    if (ctx->r1 == 0) {
        // 0x80176E74: nop
    
            goto L_80176E84;
    }
    // 0x80176E74: nop

    // 0x80176E78: andi        $t1, $t7, 0xFB
    ctx->r9 = ctx->r15 & 0XFB;
    // 0x80176E7C: b           L_80176E98
    // 0x80176E80: sb          $t1, 0xC($t6)
    MEM_B(0XC, ctx->r14) = ctx->r9;
        goto L_80176E98;
    // 0x80176E80: sb          $t1, 0xC($t6)
    MEM_B(0XC, ctx->r14) = ctx->r9;
L_80176E84:
    // 0x80176E84: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80176E88: addiu       $t2, $t2, -0x2E18
    ctx->r10 = ADD32(ctx->r10, -0X2E18);
    // 0x80176E8C: lw          $t3, 0x34($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X34);
    // 0x80176E90: addiu       $t4, $t3, -0x5
    ctx->r12 = ADD32(ctx->r11, -0X5);
    // 0x80176E94: sw          $t4, 0x34($t2)
    MEM_W(0X34, ctx->r10) = ctx->r12;
L_80176E98:
    // 0x80176E98: jal         0x80177068
    // 0x80176E9C: nop

    func_80177068_1501A0(rdram, ctx);
        goto after_0;
    // 0x80176E9C: nop

    after_0:
    // 0x80176EA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80176EA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80176EA8: jr          $ra
    // 0x80176EAC: nop

    return;
    // 0x80176EAC: nop

;}
RECOMP_FUNC void func_80176EB0_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80176EB0: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80176EB4: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_80176EB8:
    // 0x80176EB8: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x80176EBC: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x80176EC0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80176EC4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80176EC8: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x80176ECC: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80176ED0: addiu       $t0, $t0, 0x3898
    ctx->r8 = ADD32(ctx->r8, 0X3898);
    // 0x80176ED4: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x80176ED8: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80176EDC: sw          $zero, 0x38D8($at)
    MEM_W(0X38D8, ctx->r1) = 0;
    // 0x80176EE0: lw          $t2, 0x40($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X40);
    // 0x80176EE4: sw          $t2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r10;
    // 0x80176EE8: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x80176EEC: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80176EF0: sltiu       $at, $t4, 0x4
    ctx->r1 = ctx->r12 < 0X4 ? 1 : 0;
    // 0x80176EF4: bne         $at, $zero, L_80176EB8
    if (ctx->r1 != 0) {
        // 0x80176EF8: sw          $t4, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r12;
            goto L_80176EB8;
    }
    // 0x80176EF8: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x80176EFC: jr          $ra
    // 0x80176F00: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80176F00: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80176F04_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80176F04: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80176F08: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_80176F0C:
    // 0x80176F0C: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x80176F10: sll         $t6, $a0, 6
    ctx->r14 = S32(ctx->r4 << 6);
    // 0x80176F14: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80176F18: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x80176F1C: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80176F20: addiu       $t0, $t0, 0x3898
    ctx->r8 = ADD32(ctx->r8, 0X3898);
    // 0x80176F24: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80176F28: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x80176F2C: bne         $t2, $zero, L_8017704C
    if (ctx->r10 != 0) {
        // 0x80176F30: nop
    
            goto L_8017704C;
    }
    // 0x80176F30: nop

    // 0x80176F34: sll         $t3, $a0, 6
    ctx->r11 = S32(ctx->r4 << 6);
    // 0x80176F38: addu        $t4, $t3, $t8
    ctx->r12 = ADD32(ctx->r11, ctx->r24);
    // 0x80176F3C: addu        $t5, $t4, $t0
    ctx->r13 = ADD32(ctx->r12, ctx->r8);
    // 0x80176F40: sw          $a1, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r5;
    // 0x80176F44: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x80176F48: sll         $t6, $a0, 6
    ctx->r14 = S32(ctx->r4 << 6);
    // 0x80176F4C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80176F50: sll         $t1, $t9, 4
    ctx->r9 = S32(ctx->r25 << 4);
    // 0x80176F54: addu        $t2, $t6, $t1
    ctx->r10 = ADD32(ctx->r14, ctx->r9);
    // 0x80176F58: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x80176F5C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80176F60: sw          $t7, 0x389C($at)
    MEM_W(0X389C, ctx->r1) = ctx->r15;
    // 0x80176F64: slti        $at, $a2, 0x28
    ctx->r1 = SIGNED(ctx->r6) < 0X28 ? 1 : 0;
    // 0x80176F68: beq         $at, $zero, L_80176F74
    if (ctx->r1 == 0) {
        // 0x80176F6C: nop
    
            goto L_80176F74;
    }
    // 0x80176F6C: nop

    // 0x80176F70: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
L_80176F74:
    // 0x80176F74: slti        $at, $a2, 0x119
    ctx->r1 = SIGNED(ctx->r6) < 0X119 ? 1 : 0;
    // 0x80176F78: bne         $at, $zero, L_80176F84
    if (ctx->r1 != 0) {
        // 0x80176F7C: nop
    
            goto L_80176F84;
    }
    // 0x80176F7C: nop

    // 0x80176F80: addiu       $a2, $zero, 0x118
    ctx->r6 = ADD32(0, 0X118);
L_80176F84:
    // 0x80176F84: slti        $at, $a3, 0x1E
    ctx->r1 = SIGNED(ctx->r7) < 0X1E ? 1 : 0;
    // 0x80176F88: beq         $at, $zero, L_80176F94
    if (ctx->r1 == 0) {
        // 0x80176F8C: nop
    
            goto L_80176F94;
    }
    // 0x80176F8C: nop

    // 0x80176F90: addiu       $a3, $zero, 0x1E
    ctx->r7 = ADD32(0, 0X1E);
L_80176F94:
    // 0x80176F94: slti        $at, $a3, 0xD3
    ctx->r1 = SIGNED(ctx->r7) < 0XD3 ? 1 : 0;
    // 0x80176F98: bne         $at, $zero, L_80176FA4
    if (ctx->r1 != 0) {
        // 0x80176F9C: nop
    
            goto L_80176FA4;
    }
    // 0x80176F9C: nop

    // 0x80176FA0: addiu       $a3, $zero, 0xD2
    ctx->r7 = ADD32(0, 0XD2);
L_80176FA4:
    // 0x80176FA4: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x80176FA8: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x80176FAC: sll         $t3, $a0, 6
    ctx->r11 = S32(ctx->r4 << 6);
    // 0x80176FB0: sll         $t4, $t8, 4
    ctx->r12 = S32(ctx->r24 << 4);
    // 0x80176FB4: addu        $t0, $t3, $t4
    ctx->r8 = ADD32(ctx->r11, ctx->r12);
    // 0x80176FB8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80176FBC: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80176FC0: sw          $a2, 0x38A0($at)
    MEM_W(0X38A0, ctx->r1) = ctx->r6;
    // 0x80176FC4: sll         $t5, $a0, 6
    ctx->r13 = S32(ctx->r4 << 6);
    // 0x80176FC8: sll         $t6, $t9, 4
    ctx->r14 = S32(ctx->r25 << 4);
    // 0x80176FCC: addu        $t1, $t5, $t6
    ctx->r9 = ADD32(ctx->r13, ctx->r14);
    // 0x80176FD0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80176FD4: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80176FD8: sw          $a3, 0x38A4($at)
    MEM_W(0X38A4, ctx->r1) = ctx->r7;
    // 0x80176FDC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80176FE0: bne         $a1, $at, L_80177060
    if (ctx->r5 != ctx->r1) {
        // 0x80176FE4: nop
    
            goto L_80177060;
    }
    // 0x80176FE4: nop

    // 0x80176FE8: sw          $zero, 0x0($sp)
    MEM_W(0X0, ctx->r29) = 0;
L_80176FEC:
    // 0x80176FEC: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x80176FF0: lw          $t2, 0x0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X0);
    // 0x80176FF4: beq         $t7, $t2, L_80177030
    if (ctx->r15 == ctx->r10) {
        // 0x80176FF8: nop
    
            goto L_80177030;
    }
    // 0x80176FF8: nop

    // 0x80176FFC: sll         $t8, $a0, 6
    ctx->r24 = S32(ctx->r4 << 6);
    // 0x80177000: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x80177004: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80177008: addiu       $t0, $t0, 0x3898
    ctx->r8 = ADD32(ctx->r8, 0X3898);
    // 0x8017700C: addu        $t4, $t8, $t3
    ctx->r12 = ADD32(ctx->r24, ctx->r11);
    // 0x80177010: addu        $t9, $t4, $t0
    ctx->r25 = ADD32(ctx->r12, ctx->r8);
    // 0x80177014: lw          $t5, 0x0($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X0);
    // 0x80177018: bne         $t5, $a1, L_80177030
    if (ctx->r13 != ctx->r5) {
        // 0x8017701C: nop
    
            goto L_80177030;
    }
    // 0x8017701C: nop

    // 0x80177020: sll         $t6, $a0, 6
    ctx->r14 = S32(ctx->r4 << 6);
    // 0x80177024: addu        $t1, $t6, $t3
    ctx->r9 = ADD32(ctx->r14, ctx->r11);
    // 0x80177028: addu        $t7, $t1, $t0
    ctx->r15 = ADD32(ctx->r9, ctx->r8);
    // 0x8017702C: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
L_80177030:
    // 0x80177030: lw          $t2, 0x0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X0);
    // 0x80177034: addiu       $t8, $t2, 0x1
    ctx->r24 = ADD32(ctx->r10, 0X1);
    // 0x80177038: sltiu       $at, $t8, 0x4
    ctx->r1 = ctx->r24 < 0X4 ? 1 : 0;
    // 0x8017703C: bne         $at, $zero, L_80176FEC
    if (ctx->r1 != 0) {
        // 0x80177040: sw          $t8, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r24;
            goto L_80176FEC;
    }
    // 0x80177040: sw          $t8, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r24;
    // 0x80177044: b           L_80177060
    // 0x80177048: nop

        goto L_80177060;
    // 0x80177048: nop

L_8017704C:
    // 0x8017704C: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x80177050: addiu       $t9, $t4, 0x1
    ctx->r25 = ADD32(ctx->r12, 0X1);
    // 0x80177054: sltiu       $at, $t9, 0x4
    ctx->r1 = ctx->r25 < 0X4 ? 1 : 0;
    // 0x80177058: bne         $at, $zero, L_80176F0C
    if (ctx->r1 != 0) {
        // 0x8017705C: sw          $t9, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r25;
            goto L_80176F0C;
    }
    // 0x8017705C: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
L_80177060:
    // 0x80177060: jr          $ra
    // 0x80177064: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80177064: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80177068_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80177068: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8017706C: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_80177070:
    // 0x80177070: sw          $zero, 0x0($sp)
    MEM_W(0X0, ctx->r29) = 0;
L_80177074:
    // 0x80177074: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x80177078: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x8017707C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80177080: sll         $t7, $t6, 6
    ctx->r15 = S32(ctx->r14 << 6);
    // 0x80177084: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x80177088: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8017708C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80177090: lw          $t1, 0x3898($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X3898);
    // 0x80177094: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x80177098: sltiu       $at, $t2, 0x5
    ctx->r1 = ctx->r10 < 0X5 ? 1 : 0;
    // 0x8017709C: beq         $at, $zero, L_80177348
    if (ctx->r1 == 0) {
        // 0x801770A0: nop
    
            goto L_80177348;
    }
    // 0x801770A0: nop

    // 0x801770A4: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x801770A8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801770AC: addu        $at, $at, $t2
    gpr jr_addend_801770B4 = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x801770B0: lw          $t2, -0x4A8($at)
    ctx->r10 = ADD32(ctx->r1, -0X4A8);
    // 0x801770B4: jr          $t2
    // 0x801770B8: nop

    switch (jr_addend_801770B4 >> 2) {
        case 0: goto L_801770BC; break;
        case 1: goto L_80177130; break;
        case 2: goto L_801771A4; break;
        case 3: goto L_80177218; break;
        case 4: goto L_8017728C; break;
        default: switch_error(__func__, 0x801770B4, 0x8019FB58);
    }
    // 0x801770B8: nop

L_801770BC:
    // 0x801770BC: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x801770C0: lw          $t5, 0x0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X0);
    // 0x801770C4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801770C8: sll         $t4, $t3, 6
    ctx->r12 = S32(ctx->r11 << 6);
    // 0x801770CC: sll         $t6, $t5, 4
    ctx->r14 = S32(ctx->r13 << 4);
    // 0x801770D0: addu        $t8, $t4, $t6
    ctx->r24 = ADD32(ctx->r12, ctx->r14);
    // 0x801770D4: addiu       $t7, $t7, 0x3898
    ctx->r15 = ADD32(ctx->r15, 0X3898);
    // 0x801770D8: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x801770DC: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x801770E0: addu        $t2, $t4, $t6
    ctx->r10 = ADD32(ctx->r12, ctx->r14);
    // 0x801770E4: addu        $t3, $t2, $t7
    ctx->r11 = ADD32(ctx->r10, ctx->r15);
    // 0x801770E8: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x801770EC: sw          $t1, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r9;
    // 0x801770F0: lw          $t9, 0x0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X0);
    // 0x801770F4: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x801770F8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801770FC: sll         $t0, $t9, 4
    ctx->r8 = S32(ctx->r25 << 4);
    // 0x80177100: sll         $t8, $t5, 6
    ctx->r24 = S32(ctx->r13 << 6);
    // 0x80177104: addu        $t4, $t8, $t0
    ctx->r12 = ADD32(ctx->r24, ctx->r8);
    // 0x80177108: addiu       $t6, $t6, 0x3898
    ctx->r14 = ADD32(ctx->r14, 0X3898);
    // 0x8017710C: addu        $t2, $t4, $t6
    ctx->r10 = ADD32(ctx->r12, ctx->r14);
    // 0x80177110: lw          $t7, 0x4($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X4);
    // 0x80177114: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80177118: bne         $t7, $at, L_80177348
    if (ctx->r15 != ctx->r1) {
        // 0x8017711C: nop
    
            goto L_80177348;
    }
    // 0x8017711C: nop

    // 0x80177120: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x80177124: addu        $t3, $t1, $t6
    ctx->r11 = ADD32(ctx->r9, ctx->r14);
    // 0x80177128: b           L_80177348
    // 0x8017712C: sw          $zero, 0x0($t3)
    MEM_W(0X0, ctx->r11) = 0;
        goto L_80177348;
    // 0x8017712C: sw          $zero, 0x0($t3)
    MEM_W(0X0, ctx->r11) = 0;
L_80177130:
    // 0x80177130: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x80177134: lw          $t4, 0x0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X0);
    // 0x80177138: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017713C: sll         $t9, $t5, 6
    ctx->r25 = S32(ctx->r13 << 6);
    // 0x80177140: sll         $t2, $t4, 4
    ctx->r10 = S32(ctx->r12 << 4);
    // 0x80177144: addu        $t7, $t9, $t2
    ctx->r15 = ADD32(ctx->r25, ctx->r10);
    // 0x80177148: addiu       $t8, $t8, 0x3898
    ctx->r24 = ADD32(ctx->r24, 0X3898);
    // 0x8017714C: addu        $t0, $t7, $t8
    ctx->r8 = ADD32(ctx->r15, ctx->r24);
    // 0x80177150: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x80177154: addu        $t3, $t9, $t2
    ctx->r11 = ADD32(ctx->r25, ctx->r10);
    // 0x80177158: addu        $t5, $t3, $t8
    ctx->r13 = ADD32(ctx->r11, ctx->r24);
    // 0x8017715C: addiu       $t6, $t1, 0x1
    ctx->r14 = ADD32(ctx->r9, 0X1);
    // 0x80177160: sw          $t6, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r14;
    // 0x80177164: lw          $t0, 0x0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X0);
    // 0x80177168: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x8017716C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80177170: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x80177174: sll         $t7, $t4, 6
    ctx->r15 = S32(ctx->r12 << 6);
    // 0x80177178: addu        $t9, $t7, $t1
    ctx->r25 = ADD32(ctx->r15, ctx->r9);
    // 0x8017717C: addiu       $t2, $t2, 0x3898
    ctx->r10 = ADD32(ctx->r10, 0X3898);
    // 0x80177180: addu        $t3, $t9, $t2
    ctx->r11 = ADD32(ctx->r25, ctx->r10);
    // 0x80177184: lw          $t8, 0x4($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X4);
    // 0x80177188: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8017718C: bne         $t8, $at, L_80177348
    if (ctx->r24 != ctx->r1) {
        // 0x80177190: nop
    
            goto L_80177348;
    }
    // 0x80177190: nop

    // 0x80177194: addu        $t6, $t7, $t1
    ctx->r14 = ADD32(ctx->r15, ctx->r9);
    // 0x80177198: addu        $t5, $t6, $t2
    ctx->r13 = ADD32(ctx->r14, ctx->r10);
    // 0x8017719C: b           L_80177348
    // 0x801771A0: sw          $zero, 0x0($t5)
    MEM_W(0X0, ctx->r13) = 0;
        goto L_80177348;
    // 0x801771A0: sw          $zero, 0x0($t5)
    MEM_W(0X0, ctx->r13) = 0;
L_801771A4:
    // 0x801771A4: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x801771A8: lw          $t9, 0x0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X0);
    // 0x801771AC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801771B0: sll         $t0, $t4, 6
    ctx->r8 = S32(ctx->r12 << 6);
    // 0x801771B4: sll         $t3, $t9, 4
    ctx->r11 = S32(ctx->r25 << 4);
    // 0x801771B8: addu        $t8, $t0, $t3
    ctx->r24 = ADD32(ctx->r8, ctx->r11);
    // 0x801771BC: addiu       $t7, $t7, 0x3898
    ctx->r15 = ADD32(ctx->r15, 0X3898);
    // 0x801771C0: addu        $t1, $t8, $t7
    ctx->r9 = ADD32(ctx->r24, ctx->r15);
    // 0x801771C4: lw          $t6, 0x4($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X4);
    // 0x801771C8: addu        $t5, $t0, $t3
    ctx->r13 = ADD32(ctx->r8, ctx->r11);
    // 0x801771CC: addu        $t4, $t5, $t7
    ctx->r12 = ADD32(ctx->r13, ctx->r15);
    // 0x801771D0: addiu       $t2, $t6, 0x1
    ctx->r10 = ADD32(ctx->r14, 0X1);
    // 0x801771D4: sw          $t2, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r10;
    // 0x801771D8: lw          $t1, 0x0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X0);
    // 0x801771DC: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x801771E0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x801771E4: sll         $t6, $t1, 4
    ctx->r14 = S32(ctx->r9 << 4);
    // 0x801771E8: sll         $t8, $t9, 6
    ctx->r24 = S32(ctx->r25 << 6);
    // 0x801771EC: addu        $t0, $t8, $t6
    ctx->r8 = ADD32(ctx->r24, ctx->r14);
    // 0x801771F0: addiu       $t3, $t3, 0x3898
    ctx->r11 = ADD32(ctx->r11, 0X3898);
    // 0x801771F4: addu        $t5, $t0, $t3
    ctx->r13 = ADD32(ctx->r8, ctx->r11);
    // 0x801771F8: lw          $t7, 0x4($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X4);
    // 0x801771FC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80177200: bne         $t7, $at, L_80177348
    if (ctx->r15 != ctx->r1) {
        // 0x80177204: nop
    
            goto L_80177348;
    }
    // 0x80177204: nop

    // 0x80177208: addu        $t2, $t8, $t6
    ctx->r10 = ADD32(ctx->r24, ctx->r14);
    // 0x8017720C: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80177210: b           L_80177348
    // 0x80177214: sw          $zero, 0x0($t4)
    MEM_W(0X0, ctx->r12) = 0;
        goto L_80177348;
    // 0x80177214: sw          $zero, 0x0($t4)
    MEM_W(0X0, ctx->r12) = 0;
L_80177218:
    // 0x80177218: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x8017721C: lw          $t0, 0x0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X0);
    // 0x80177220: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80177224: sll         $t1, $t9, 6
    ctx->r9 = S32(ctx->r25 << 6);
    // 0x80177228: sll         $t5, $t0, 4
    ctx->r13 = S32(ctx->r8 << 4);
    // 0x8017722C: addu        $t7, $t1, $t5
    ctx->r15 = ADD32(ctx->r9, ctx->r13);
    // 0x80177230: addiu       $t8, $t8, 0x3898
    ctx->r24 = ADD32(ctx->r24, 0X3898);
    // 0x80177234: addu        $t6, $t7, $t8
    ctx->r14 = ADD32(ctx->r15, ctx->r24);
    // 0x80177238: lw          $t2, 0x4($t6)
    ctx->r10 = MEM_W(ctx->r14, 0X4);
    // 0x8017723C: addu        $t4, $t1, $t5
    ctx->r12 = ADD32(ctx->r9, ctx->r13);
    // 0x80177240: addu        $t9, $t4, $t8
    ctx->r25 = ADD32(ctx->r12, ctx->r24);
    // 0x80177244: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80177248: sw          $t3, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r11;
    // 0x8017724C: lw          $t6, 0x0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X0);
    // 0x80177250: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x80177254: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80177258: sll         $t2, $t6, 4
    ctx->r10 = S32(ctx->r14 << 4);
    // 0x8017725C: sll         $t7, $t0, 6
    ctx->r15 = S32(ctx->r8 << 6);
    // 0x80177260: addu        $t1, $t7, $t2
    ctx->r9 = ADD32(ctx->r15, ctx->r10);
    // 0x80177264: addiu       $t5, $t5, 0x3898
    ctx->r13 = ADD32(ctx->r13, 0X3898);
    // 0x80177268: addu        $t4, $t1, $t5
    ctx->r12 = ADD32(ctx->r9, ctx->r13);
    // 0x8017726C: lw          $t8, 0x4($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X4);
    // 0x80177270: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80177274: bne         $t8, $at, L_80177348
    if (ctx->r24 != ctx->r1) {
        // 0x80177278: nop
    
            goto L_80177348;
    }
    // 0x80177278: nop

    // 0x8017727C: addu        $t3, $t7, $t2
    ctx->r11 = ADD32(ctx->r15, ctx->r10);
    // 0x80177280: addu        $t9, $t3, $t5
    ctx->r25 = ADD32(ctx->r11, ctx->r13);
    // 0x80177284: b           L_80177348
    // 0x80177288: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
        goto L_80177348;
    // 0x80177288: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
L_8017728C:
    // 0x8017728C: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x80177290: lw          $t1, 0x0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X0);
    // 0x80177294: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80177298: sll         $t6, $t0, 6
    ctx->r14 = S32(ctx->r8 << 6);
    // 0x8017729C: sll         $t4, $t1, 4
    ctx->r12 = S32(ctx->r9 << 4);
    // 0x801772A0: addu        $t8, $t6, $t4
    ctx->r24 = ADD32(ctx->r14, ctx->r12);
    // 0x801772A4: addiu       $t7, $t7, 0x3898
    ctx->r15 = ADD32(ctx->r15, 0X3898);
    // 0x801772A8: addu        $t2, $t8, $t7
    ctx->r10 = ADD32(ctx->r24, ctx->r15);
    // 0x801772AC: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x801772B0: addu        $t9, $t6, $t4
    ctx->r25 = ADD32(ctx->r14, ctx->r12);
    // 0x801772B4: addu        $t0, $t9, $t7
    ctx->r8 = ADD32(ctx->r25, ctx->r15);
    // 0x801772B8: addiu       $t5, $t3, 0x1
    ctx->r13 = ADD32(ctx->r11, 0X1);
    // 0x801772BC: sw          $t5, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r13;
    // 0x801772C0: lw          $t2, 0x0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X0);
    // 0x801772C4: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x801772C8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x801772CC: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x801772D0: sll         $t8, $t1, 6
    ctx->r24 = S32(ctx->r9 << 6);
    // 0x801772D4: addu        $t6, $t8, $t3
    ctx->r14 = ADD32(ctx->r24, ctx->r11);
    // 0x801772D8: addiu       $t4, $t4, 0x3898
    ctx->r12 = ADD32(ctx->r12, 0X3898);
    // 0x801772DC: addu        $t9, $t6, $t4
    ctx->r25 = ADD32(ctx->r14, ctx->r12);
    // 0x801772E0: lw          $t7, 0x4($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X4);
    // 0x801772E4: sltiu       $at, $t7, 0x30
    ctx->r1 = ctx->r15 < 0X30 ? 1 : 0;
    // 0x801772E8: bne         $at, $zero, L_8017730C
    if (ctx->r1 != 0) {
        // 0x801772EC: nop
    
            goto L_8017730C;
    }
    // 0x801772EC: nop

    // 0x801772F0: addu        $t5, $t8, $t3
    ctx->r13 = ADD32(ctx->r24, ctx->r11);
    // 0x801772F4: addu        $t0, $t5, $t4
    ctx->r8 = ADD32(ctx->r13, ctx->r12);
    // 0x801772F8: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x801772FC: addu        $t6, $t8, $t3
    ctx->r14 = ADD32(ctx->r24, ctx->r11);
    // 0x80177300: addu        $t9, $t6, $t4
    ctx->r25 = ADD32(ctx->r14, ctx->r12);
    // 0x80177304: addiu       $t2, $t1, 0x1E
    ctx->r10 = ADD32(ctx->r9, 0X1E);
    // 0x80177308: sw          $t2, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->r10;
L_8017730C:
    // 0x8017730C: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x80177310: lw          $t0, 0x0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X0);
    // 0x80177314: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80177318: sll         $t5, $t7, 6
    ctx->r13 = S32(ctx->r15 << 6);
    // 0x8017731C: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x80177320: addu        $t8, $t5, $t1
    ctx->r24 = ADD32(ctx->r13, ctx->r9);
    // 0x80177324: addiu       $t3, $t3, 0x3898
    ctx->r11 = ADD32(ctx->r11, 0X3898);
    // 0x80177328: addu        $t6, $t8, $t3
    ctx->r14 = ADD32(ctx->r24, ctx->r11);
    // 0x8017732C: lw          $t4, 0x4($t6)
    ctx->r12 = MEM_W(ctx->r14, 0X4);
    // 0x80177330: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
    // 0x80177334: bne         $t4, $at, L_80177348
    if (ctx->r12 != ctx->r1) {
        // 0x80177338: nop
    
            goto L_80177348;
    }
    // 0x80177338: nop

    // 0x8017733C: addu        $t2, $t5, $t1
    ctx->r10 = ADD32(ctx->r13, ctx->r9);
    // 0x80177340: addu        $t9, $t2, $t3
    ctx->r25 = ADD32(ctx->r10, ctx->r11);
    // 0x80177344: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
L_80177348:
    // 0x80177348: lw          $t7, 0x0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X0);
    // 0x8017734C: addiu       $t0, $t7, 0x1
    ctx->r8 = ADD32(ctx->r15, 0X1);
    // 0x80177350: sltiu       $at, $t0, 0x4
    ctx->r1 = ctx->r8 < 0X4 ? 1 : 0;
    // 0x80177354: bne         $at, $zero, L_80177074
    if (ctx->r1 != 0) {
        // 0x80177358: sw          $t0, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r8;
            goto L_80177074;
    }
    // 0x80177358: sw          $t0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r8;
    // 0x8017735C: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x80177360: addiu       $t6, $t8, 0x1
    ctx->r14 = ADD32(ctx->r24, 0X1);
    // 0x80177364: sltiu       $at, $t6, 0x2
    ctx->r1 = ctx->r14 < 0X2 ? 1 : 0;
    // 0x80177368: bne         $at, $zero, L_80177070
    if (ctx->r1 != 0) {
        // 0x8017736C: sw          $t6, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r14;
            goto L_80177070;
    }
    // 0x8017736C: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x80177370: jr          $ra
    // 0x80177374: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80177374: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80177378_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80177378: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8017737C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80177380: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_80177384:
    // 0x80177384: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
L_80177388:
    // 0x80177388: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8017738C: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80177390: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80177394: sll         $t7, $t6, 6
    ctx->r15 = S32(ctx->r14 << 6);
    // 0x80177398: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x8017739C: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x801773A0: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x801773A4: lw          $t1, 0x3898($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X3898);
    // 0x801773A8: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x801773AC: sltiu       $at, $t2, 0x5
    ctx->r1 = ctx->r10 < 0X5 ? 1 : 0;
    // 0x801773B0: beq         $at, $zero, L_80177BBC
    if (ctx->r1 == 0) {
        // 0x801773B4: nop
    
            goto L_80177BBC;
    }
    // 0x801773B4: nop

    // 0x801773B8: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x801773BC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801773C0: addu        $at, $at, $t2
    gpr jr_addend_801773C8 = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x801773C4: lw          $t2, -0x494($at)
    ctx->r10 = ADD32(ctx->r1, -0X494);
    // 0x801773C8: jr          $t2
    // 0x801773CC: nop

    switch (jr_addend_801773C8 >> 2) {
        case 0: goto L_801773D0; break;
        case 1: goto L_8017751C; break;
        case 2: goto L_80177708; break;
        case 3: goto L_801778F4; break;
        case 4: goto L_80177A40; break;
        default: switch_error(__func__, 0x801773C8, 0x8019FB6C);
    }
    // 0x801773CC: nop

L_801773D0:
    // 0x801773D0: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x801773D4: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x801773D8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x801773DC: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x801773E0: sll         $t7, $t3, 6
    ctx->r15 = S32(ctx->r11 << 6);
    // 0x801773E4: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x801773E8: sll         $t9, $t5, 4
    ctx->r25 = S32(ctx->r13 << 4);
    // 0x801773EC: addiu       $t1, $t1, 0x3898
    ctx->r9 = ADD32(ctx->r9, 0X3898);
    // 0x801773F0: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x801773F4: addu        $t4, $t7, $t9
    ctx->r12 = ADD32(ctx->r15, ctx->r25);
    // 0x801773F8: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x801773FC: addu        $t6, $t4, $t1
    ctx->r14 = ADD32(ctx->r12, ctx->r9);
    // 0x80177400: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80177404: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80177408: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017740C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80177410: lw          $a1, 0x8($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X8);
    // 0x80177414: lw          $a2, 0xC($t6)
    ctx->r6 = MEM_W(ctx->r14, 0XC);
    // 0x80177418: addu        $a0, $a0, $t8
    ctx->r4 = ADD32(ctx->r4, ctx->r24);
    // 0x8017741C: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80177420: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80177424: lw          $a0, -0x26A8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X26A8);
    // 0x80177428: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8017742C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80177430: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x80177434: jal         0x800C6C6C
    // 0x80177438: addiu       $a2, $a2, -0x10
    ctx->r6 = ADD32(ctx->r6, -0X10);
    func_800C6C6C(rdram, ctx);
        goto after_0;
    // 0x80177438: addiu       $a2, $a2, -0x10
    ctx->r6 = ADD32(ctx->r6, -0X10);
    after_0:
    // 0x8017743C: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80177440: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80177444: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80177448: sll         $t5, $t3, 6
    ctx->r13 = S32(ctx->r11 << 6);
    // 0x8017744C: sll         $t2, $t0, 4
    ctx->r10 = S32(ctx->r8 << 4);
    // 0x80177450: addu        $t7, $t5, $t2
    ctx->r15 = ADD32(ctx->r13, ctx->r10);
    // 0x80177454: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x80177458: lw          $t9, 0x389C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X389C);
    // 0x8017745C: bne         $t9, $zero, L_80177BBC
    if (ctx->r25 != 0) {
        // 0x80177460: nop
    
            goto L_80177BBC;
    }
    // 0x80177460: nop

    // 0x80177464: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80177468: lw          $t4, -0x2E48($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2E48);
    // 0x8017746C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80177470: beq         $t4, $at, L_801774A8
    if (ctx->r12 == ctx->r1) {
        // 0x80177474: lui         $at, 0x41F0
        ctx->r1 = S32(0X41F0 << 16);
            goto L_801774A8;
    }
    // 0x80177474: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80177478: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017747C: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80177480: addiu       $t1, $zero, 0x64
    ctx->r9 = ADD32(0, 0X64);
    // 0x80177484: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80177488: addiu       $a0, $a0, 0xD94
    ctx->r4 = ADD32(ctx->r4, 0XD94);
    // 0x8017748C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80177490: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80177494: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    // 0x80177498: jal         0x800C6C6C
    // 0x8017749C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_1;
    // 0x8017749C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x801774A0: b           L_80177BBC
    // 0x801774A4: nop

        goto L_80177BBC;
    // 0x801774A4: nop

L_801774A8:
    // 0x801774A8: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x801774AC: bne         $t6, $zero, L_801774DC
    if (ctx->r14 != 0) {
        // 0x801774B0: lui         $at, 0x41F0
        ctx->r1 = S32(0X41F0 << 16);
            goto L_801774DC;
    }
    // 0x801774B0: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801774B4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801774B8: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x801774BC: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x801774C0: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x801774C4: addiu       $a0, $a0, 0xD94
    ctx->r4 = ADD32(ctx->r4, 0XD94);
    // 0x801774C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801774CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801774D0: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x801774D4: jal         0x800C6C6C
    // 0x801774D8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_2;
    // 0x801774D8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_2:
L_801774DC:
    // 0x801774DC: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x801774E0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801774E4: bne         $t3, $at, L_80177BBC
    if (ctx->r11 != ctx->r1) {
        // 0x801774E8: lui         $at, 0x41F0
        ctx->r1 = S32(0X41F0 << 16);
            goto L_80177BBC;
    }
    // 0x801774E8: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801774EC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801774F0: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x801774F4: addiu       $t0, $zero, 0x64
    ctx->r8 = ADD32(0, 0X64);
    // 0x801774F8: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x801774FC: addiu       $a0, $a0, 0xDD8
    ctx->r4 = ADD32(ctx->r4, 0XDD8);
    // 0x80177500: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x80177504: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80177508: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x8017750C: jal         0x800C6C6C
    // 0x80177510: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_3;
    // 0x80177510: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_3:
    // 0x80177514: b           L_80177BBC
    // 0x80177518: nop

        goto L_80177BBC;
    // 0x80177518: nop

L_8017751C:
    // 0x8017751C: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80177520: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80177524: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80177528: sll         $t1, $t5, 6
    ctx->r9 = S32(ctx->r13 << 6);
    // 0x8017752C: sll         $t6, $t7, 4
    ctx->r14 = S32(ctx->r15 << 4);
    // 0x80177530: addu        $t8, $t1, $t6
    ctx->r24 = ADD32(ctx->r9, ctx->r14);
    // 0x80177534: addiu       $t3, $t3, 0x3898
    ctx->r11 = ADD32(ctx->r11, 0X3898);
    // 0x80177538: sll         $t2, $t5, 2
    ctx->r10 = S32(ctx->r13 << 2);
    // 0x8017753C: addu        $t0, $t8, $t3
    ctx->r8 = ADD32(ctx->r24, ctx->r11);
    // 0x80177540: addu        $t9, $t2, $t7
    ctx->r25 = ADD32(ctx->r10, ctx->r15);
    // 0x80177544: lw          $t2, 0x4($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X4);
    // 0x80177548: sll         $t4, $t9, 2
    ctx->r12 = S32(ctx->r25 << 2);
    // 0x8017754C: subu        $t4, $t4, $t9
    ctx->r12 = SUB32(ctx->r12, ctx->r25);
    // 0x80177550: addu        $t9, $t2, $t4
    ctx->r25 = ADD32(ctx->r10, ctx->r12);
    // 0x80177554: addu        $t2, $t1, $t6
    ctx->r10 = ADD32(ctx->r9, ctx->r14);
    // 0x80177558: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8017755C: sll         $t5, $t9, 2
    ctx->r13 = S32(ctx->r25 << 2);
    // 0x80177560: lw          $t9, 0x4($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X4);
    // 0x80177564: addu        $t7, $t1, $t6
    ctx->r15 = ADD32(ctx->r9, ctx->r14);
    // 0x80177568: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8017756C: addu        $a0, $a0, $t5
    ctx->r4 = ADD32(ctx->r4, ctx->r13);
    // 0x80177570: addu        $t8, $t7, $t3
    ctx->r24 = ADD32(ctx->r15, ctx->r11);
    // 0x80177574: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80177578: sll         $t5, $t9, 2
    ctx->r13 = S32(ctx->r25 << 2);
    // 0x8017757C: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x80177580: lw          $t7, -0x259C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X259C);
    // 0x80177584: lw          $t0, 0x8($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X8);
    // 0x80177588: addu        $t9, $t1, $t6
    ctx->r25 = ADD32(ctx->r9, ctx->r14);
    // 0x8017758C: addu        $t5, $t9, $t3
    ctx->r13 = ADD32(ctx->r25, ctx->r11);
    // 0x80177590: subu        $a1, $t0, $t7
    ctx->r5 = SUB32(ctx->r8, ctx->r15);
    // 0x80177594: lw          $t0, 0x4($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X4);
    // 0x80177598: addu        $t8, $t1, $t6
    ctx->r24 = ADD32(ctx->r9, ctx->r14);
    // 0x8017759C: addu        $t2, $t8, $t3
    ctx->r10 = ADD32(ctx->r24, ctx->r11);
    // 0x801775A0: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x801775A4: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x801775A8: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x801775AC: lw          $t8, -0x259C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X259C);
    // 0x801775B0: lw          $t4, 0xC($t2)
    ctx->r12 = MEM_W(ctx->r10, 0XC);
    // 0x801775B4: addu        $t7, $t1, $t6
    ctx->r15 = ADD32(ctx->r9, ctx->r14);
    // 0x801775B8: addu        $t2, $t1, $t6
    ctx->r10 = ADD32(ctx->r9, ctx->r14);
    // 0x801775BC: subu        $a2, $t4, $t8
    ctx->r6 = SUB32(ctx->r12, ctx->r24);
    // 0x801775C0: addu        $t4, $t7, $t3
    ctx->r12 = ADD32(ctx->r15, ctx->r11);
    // 0x801775C4: lw          $t8, 0x4($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X4);
    // 0x801775C8: addu        $t9, $t2, $t3
    ctx->r25 = ADD32(ctx->r10, ctx->r11);
    // 0x801775CC: lw          $t5, 0x4($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X4);
    // 0x801775D0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801775D4: sll         $t2, $t8, 2
    ctx->r10 = S32(ctx->r24 << 2);
    // 0x801775D8: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x801775DC: lwc1        $f16, -0x25A8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X25A8);
    // 0x801775E0: sll         $t0, $t5, 2
    ctx->r8 = S32(ctx->r13 << 2);
    // 0x801775E4: addu        $t9, $t1, $t6
    ctx->r25 = ADD32(ctx->r9, ctx->r14);
    // 0x801775E8: lui         $a3, 0x801A
    ctx->r7 = S32(0X801A << 16);
    // 0x801775EC: addu        $a3, $a3, $t0
    ctx->r7 = ADD32(ctx->r7, ctx->r8);
    // 0x801775F0: addu        $t5, $t9, $t3
    ctx->r13 = ADD32(ctx->r25, ctx->r11);
    // 0x801775F4: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x801775F8: lw          $t0, 0x4($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X4);
    // 0x801775FC: addiu       $t4, $zero, 0xC8
    ctx->r12 = ADD32(0, 0XC8);
    // 0x80177600: lw          $a3, -0x25A8($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X25A8);
    // 0x80177604: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x80177608: subu        $t7, $t7, $t0
    ctx->r15 = SUB32(ctx->r15, ctx->r8);
    // 0x8017760C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80177610: addu        $t7, $t7, $t0
    ctx->r15 = ADD32(ctx->r15, ctx->r8);
    // 0x80177614: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x80177618: subu        $t8, $t4, $t7
    ctx->r24 = SUB32(ctx->r12, ctx->r15);
    // 0x8017761C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80177620: jal         0x800C6C6C
    // 0x80177624: lw          $a0, -0x2688($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2688);
    func_800C6C6C(rdram, ctx);
        goto after_4;
    // 0x80177624: lw          $a0, -0x2688($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2688);
    after_4:
    // 0x80177628: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x8017762C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80177630: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80177634: sll         $t1, $t2, 6
    ctx->r9 = S32(ctx->r10 << 6);
    // 0x80177638: sll         $t9, $t6, 4
    ctx->r25 = S32(ctx->r14 << 4);
    // 0x8017763C: addu        $t3, $t1, $t9
    ctx->r11 = ADD32(ctx->r9, ctx->r25);
    // 0x80177640: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x80177644: lw          $t5, 0x389C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X389C);
    // 0x80177648: bne         $t5, $zero, L_80177BBC
    if (ctx->r13 != 0) {
        // 0x8017764C: nop
    
            goto L_80177BBC;
    }
    // 0x8017764C: nop

    // 0x80177650: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80177654: lw          $t0, -0x2E48($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2E48);
    // 0x80177658: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8017765C: beq         $t0, $at, L_80177694
    if (ctx->r8 == ctx->r1) {
        // 0x80177660: lui         $at, 0x41F0
        ctx->r1 = S32(0X41F0 << 16);
            goto L_80177694;
    }
    // 0x80177660: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80177664: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80177668: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8017766C: addiu       $t4, $zero, 0x64
    ctx->r12 = ADD32(0, 0X64);
    // 0x80177670: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80177674: addiu       $a0, $a0, 0xD94
    ctx->r4 = ADD32(ctx->r4, 0XD94);
    // 0x80177678: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8017767C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80177680: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    // 0x80177684: jal         0x800C6C6C
    // 0x80177688: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_5;
    // 0x80177688: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_5:
    // 0x8017768C: b           L_80177BBC
    // 0x80177690: nop

        goto L_80177BBC;
    // 0x80177690: nop

L_80177694:
    // 0x80177694: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80177698: bne         $t7, $zero, L_801776C8
    if (ctx->r15 != 0) {
        // 0x8017769C: lui         $at, 0x41F0
        ctx->r1 = S32(0X41F0 << 16);
            goto L_801776C8;
    }
    // 0x8017769C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801776A0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801776A4: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x801776A8: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x801776AC: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x801776B0: addiu       $a0, $a0, 0xD94
    ctx->r4 = ADD32(ctx->r4, 0XD94);
    // 0x801776B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801776B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801776BC: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x801776C0: jal         0x800C6C6C
    // 0x801776C4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_6;
    // 0x801776C4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_6:
L_801776C8:
    // 0x801776C8: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x801776CC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801776D0: bne         $t2, $at, L_80177BBC
    if (ctx->r10 != ctx->r1) {
        // 0x801776D4: lui         $at, 0x41F0
        ctx->r1 = S32(0X41F0 << 16);
            goto L_80177BBC;
    }
    // 0x801776D4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801776D8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801776DC: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x801776E0: addiu       $t6, $zero, 0x64
    ctx->r14 = ADD32(0, 0X64);
    // 0x801776E4: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x801776E8: addiu       $a0, $a0, 0xDD8
    ctx->r4 = ADD32(ctx->r4, 0XDD8);
    // 0x801776EC: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x801776F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801776F4: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x801776F8: jal         0x800C6C6C
    // 0x801776FC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_7;
    // 0x801776FC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_7:
    // 0x80177700: b           L_80177BBC
    // 0x80177704: nop

        goto L_80177BBC;
    // 0x80177704: nop

L_80177708:
    // 0x80177708: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8017770C: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80177710: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80177714: sll         $t4, $t1, 6
    ctx->r12 = S32(ctx->r9 << 6);
    // 0x80177718: sll         $t7, $t3, 4
    ctx->r15 = S32(ctx->r11 << 4);
    // 0x8017771C: addu        $t8, $t4, $t7
    ctx->r24 = ADD32(ctx->r12, ctx->r15);
    // 0x80177720: addiu       $t2, $t2, 0x3898
    ctx->r10 = ADD32(ctx->r10, 0X3898);
    // 0x80177724: sll         $t9, $t1, 2
    ctx->r25 = S32(ctx->r9 << 2);
    // 0x80177728: addu        $t6, $t8, $t2
    ctx->r14 = ADD32(ctx->r24, ctx->r10);
    // 0x8017772C: addu        $t5, $t9, $t3
    ctx->r13 = ADD32(ctx->r25, ctx->r11);
    // 0x80177730: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x80177734: sll         $t0, $t5, 2
    ctx->r8 = S32(ctx->r13 << 2);
    // 0x80177738: subu        $t0, $t0, $t5
    ctx->r8 = SUB32(ctx->r8, ctx->r13);
    // 0x8017773C: addu        $t5, $t9, $t0
    ctx->r13 = ADD32(ctx->r25, ctx->r8);
    // 0x80177740: addu        $t9, $t4, $t7
    ctx->r25 = ADD32(ctx->r12, ctx->r15);
    // 0x80177744: addu        $t0, $t9, $t2
    ctx->r8 = ADD32(ctx->r25, ctx->r10);
    // 0x80177748: sll         $t1, $t5, 2
    ctx->r9 = S32(ctx->r13 << 2);
    // 0x8017774C: lw          $t5, 0x4($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X4);
    // 0x80177750: addu        $t3, $t4, $t7
    ctx->r11 = ADD32(ctx->r12, ctx->r15);
    // 0x80177754: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80177758: addu        $a0, $a0, $t1
    ctx->r4 = ADD32(ctx->r4, ctx->r9);
    // 0x8017775C: addu        $t8, $t3, $t2
    ctx->r24 = ADD32(ctx->r11, ctx->r10);
    // 0x80177760: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80177764: sll         $t1, $t5, 2
    ctx->r9 = S32(ctx->r13 << 2);
    // 0x80177768: addu        $t3, $t3, $t1
    ctx->r11 = ADD32(ctx->r11, ctx->r9);
    // 0x8017776C: lw          $t3, -0x2578($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2578);
    // 0x80177770: lw          $t6, 0x8($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X8);
    // 0x80177774: addu        $t5, $t4, $t7
    ctx->r13 = ADD32(ctx->r12, ctx->r15);
    // 0x80177778: addu        $t1, $t5, $t2
    ctx->r9 = ADD32(ctx->r13, ctx->r10);
    // 0x8017777C: subu        $a1, $t6, $t3
    ctx->r5 = SUB32(ctx->r14, ctx->r11);
    // 0x80177780: lw          $t6, 0x4($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X4);
    // 0x80177784: addu        $t8, $t4, $t7
    ctx->r24 = ADD32(ctx->r12, ctx->r15);
    // 0x80177788: addu        $t9, $t8, $t2
    ctx->r25 = ADD32(ctx->r24, ctx->r10);
    // 0x8017778C: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80177790: sll         $t3, $t6, 2
    ctx->r11 = S32(ctx->r14 << 2);
    // 0x80177794: addu        $t8, $t8, $t3
    ctx->r24 = ADD32(ctx->r24, ctx->r11);
    // 0x80177798: lw          $t8, -0x256C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X256C);
    // 0x8017779C: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x801777A0: addu        $t3, $t4, $t7
    ctx->r11 = ADD32(ctx->r12, ctx->r15);
    // 0x801777A4: addu        $t9, $t4, $t7
    ctx->r25 = ADD32(ctx->r12, ctx->r15);
    // 0x801777A8: subu        $a2, $t0, $t8
    ctx->r6 = SUB32(ctx->r8, ctx->r24);
    // 0x801777AC: addu        $t0, $t3, $t2
    ctx->r8 = ADD32(ctx->r11, ctx->r10);
    // 0x801777B0: lw          $t8, 0x4($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X4);
    // 0x801777B4: addu        $t5, $t9, $t2
    ctx->r13 = ADD32(ctx->r25, ctx->r10);
    // 0x801777B8: lw          $t1, 0x4($t5)
    ctx->r9 = MEM_W(ctx->r13, 0X4);
    // 0x801777BC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801777C0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x801777C4: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x801777C8: lwc1        $f8, -0x2584($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2584);
    // 0x801777CC: sll         $t6, $t1, 2
    ctx->r14 = S32(ctx->r9 << 2);
    // 0x801777D0: addu        $t5, $t4, $t7
    ctx->r13 = ADD32(ctx->r12, ctx->r15);
    // 0x801777D4: lui         $a3, 0x801A
    ctx->r7 = S32(0X801A << 16);
    // 0x801777D8: addu        $a3, $a3, $t6
    ctx->r7 = ADD32(ctx->r7, ctx->r14);
    // 0x801777DC: addu        $t1, $t5, $t2
    ctx->r9 = ADD32(ctx->r13, ctx->r10);
    // 0x801777E0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x801777E4: lw          $t6, 0x4($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X4);
    // 0x801777E8: addiu       $t0, $zero, 0xC8
    ctx->r8 = ADD32(0, 0XC8);
    // 0x801777EC: lw          $a3, -0x2590($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X2590);
    // 0x801777F0: sll         $t3, $t6, 2
    ctx->r11 = S32(ctx->r14 << 2);
    // 0x801777F4: subu        $t3, $t3, $t6
    ctx->r11 = SUB32(ctx->r11, ctx->r14);
    // 0x801777F8: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x801777FC: addu        $t3, $t3, $t6
    ctx->r11 = ADD32(ctx->r11, ctx->r14);
    // 0x80177800: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x80177804: subu        $t8, $t0, $t3
    ctx->r24 = SUB32(ctx->r8, ctx->r11);
    // 0x80177808: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8017780C: jal         0x800C6C6C
    // 0x80177810: lw          $a0, -0x2688($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2688);
    func_800C6C6C(rdram, ctx);
        goto after_8;
    // 0x80177810: lw          $a0, -0x2688($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2688);
    after_8:
    // 0x80177814: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80177818: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8017781C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80177820: sll         $t4, $t9, 6
    ctx->r12 = S32(ctx->r25 << 6);
    // 0x80177824: sll         $t5, $t7, 4
    ctx->r13 = S32(ctx->r15 << 4);
    // 0x80177828: addu        $t2, $t4, $t5
    ctx->r10 = ADD32(ctx->r12, ctx->r13);
    // 0x8017782C: addu        $t1, $t1, $t2
    ctx->r9 = ADD32(ctx->r9, ctx->r10);
    // 0x80177830: lw          $t1, 0x389C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X389C);
    // 0x80177834: bne         $t1, $zero, L_80177BBC
    if (ctx->r9 != 0) {
        // 0x80177838: nop
    
            goto L_80177BBC;
    }
    // 0x80177838: nop

    // 0x8017783C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80177840: lw          $t6, -0x2E48($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2E48);
    // 0x80177844: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80177848: beq         $t6, $at, L_80177880
    if (ctx->r14 == ctx->r1) {
        // 0x8017784C: lui         $at, 0x41F0
        ctx->r1 = S32(0X41F0 << 16);
            goto L_80177880;
    }
    // 0x8017784C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80177850: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80177854: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80177858: addiu       $t0, $zero, 0x64
    ctx->r8 = ADD32(0, 0X64);
    // 0x8017785C: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80177860: addiu       $a0, $a0, 0xD94
    ctx->r4 = ADD32(ctx->r4, 0XD94);
    // 0x80177864: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80177868: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8017786C: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    // 0x80177870: jal         0x800C6C6C
    // 0x80177874: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_9;
    // 0x80177874: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_9:
    // 0x80177878: b           L_80177BBC
    // 0x8017787C: nop

        goto L_80177BBC;
    // 0x8017787C: nop

L_80177880:
    // 0x80177880: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80177884: bne         $t3, $zero, L_801778B4
    if (ctx->r11 != 0) {
        // 0x80177888: lui         $at, 0x41F0
        ctx->r1 = S32(0X41F0 << 16);
            goto L_801778B4;
    }
    // 0x80177888: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8017788C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80177890: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80177894: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x80177898: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8017789C: addiu       $a0, $a0, 0xD94
    ctx->r4 = ADD32(ctx->r4, 0XD94);
    // 0x801778A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801778A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801778A8: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x801778AC: jal         0x800C6C6C
    // 0x801778B0: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_10;
    // 0x801778B0: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_10:
L_801778B4:
    // 0x801778B4: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x801778B8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801778BC: bne         $t9, $at, L_80177BBC
    if (ctx->r25 != ctx->r1) {
        // 0x801778C0: lui         $at, 0x41F0
        ctx->r1 = S32(0X41F0 << 16);
            goto L_80177BBC;
    }
    // 0x801778C0: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801778C4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801778C8: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x801778CC: addiu       $t7, $zero, 0x64
    ctx->r15 = ADD32(0, 0X64);
    // 0x801778D0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801778D4: addiu       $a0, $a0, 0xDD8
    ctx->r4 = ADD32(ctx->r4, 0XDD8);
    // 0x801778D8: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x801778DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801778E0: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x801778E4: jal         0x800C6C6C
    // 0x801778E8: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_11;
    // 0x801778E8: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_11:
    // 0x801778EC: b           L_80177BBC
    // 0x801778F0: nop

        goto L_80177BBC;
    // 0x801778F0: nop

L_801778F4:
    // 0x801778F4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x801778F8: lw          $t4, -0x2E48($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2E48);
    // 0x801778FC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80177900: beq         $t4, $at, L_8017796C
    if (ctx->r12 == ctx->r1) {
        // 0x80177904: nop
    
            goto L_8017796C;
    }
    // 0x80177904: nop

    // 0x80177908: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x8017790C: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80177910: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80177914: sll         $t2, $t5, 6
    ctx->r10 = S32(ctx->r13 << 6);
    // 0x80177918: sll         $t6, $t1, 4
    ctx->r14 = S32(ctx->r9 << 4);
    // 0x8017791C: addu        $t0, $t2, $t6
    ctx->r8 = ADD32(ctx->r10, ctx->r14);
    // 0x80177920: addu        $t3, $t3, $t0
    ctx->r11 = ADD32(ctx->r11, ctx->r8);
    // 0x80177924: lw          $t3, 0x389C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X389C);
    // 0x80177928: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8017792C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80177930: sll         $t8, $t3, 2
    ctx->r24 = S32(ctx->r11 << 2);
    // 0x80177934: addu        $t8, $t8, $t3
    ctx->r24 = ADD32(ctx->r24, ctx->r11);
    // 0x80177938: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x8017793C: addiu       $t9, $zero, 0x64
    ctx->r25 = ADD32(0, 0X64);
    // 0x80177940: subu        $t7, $t9, $t8
    ctx->r15 = SUB32(ctx->r25, ctx->r24);
    // 0x80177944: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80177948: addiu       $a0, $a0, 0xD94
    ctx->r4 = ADD32(ctx->r4, 0XD94);
    // 0x8017794C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80177950: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80177954: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80177958: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    // 0x8017795C: jal         0x800C6C6C
    // 0x80177960: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_12;
    // 0x80177960: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_12:
    // 0x80177964: b           L_80177BBC
    // 0x80177968: nop

        goto L_80177BBC;
    // 0x80177968: nop

L_8017796C:
    // 0x8017796C: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80177970: bne         $t4, $zero, L_801779D0
    if (ctx->r12 != 0) {
        // 0x80177974: nop
    
            goto L_801779D0;
    }
    // 0x80177974: nop

    // 0x80177978: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8017797C: sll         $t5, $t4, 6
    ctx->r13 = S32(ctx->r12 << 6);
    // 0x80177980: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80177984: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x80177988: addu        $t6, $t5, $t2
    ctx->r14 = ADD32(ctx->r13, ctx->r10);
    // 0x8017798C: addu        $t0, $t0, $t6
    ctx->r8 = ADD32(ctx->r8, ctx->r14);
    // 0x80177990: lw          $t0, 0x389C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X389C);
    // 0x80177994: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80177998: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017799C: sll         $t3, $t0, 2
    ctx->r11 = S32(ctx->r8 << 2);
    // 0x801779A0: addu        $t3, $t3, $t0
    ctx->r11 = ADD32(ctx->r11, ctx->r8);
    // 0x801779A4: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x801779A8: addiu       $t9, $zero, 0x64
    ctx->r25 = ADD32(0, 0X64);
    // 0x801779AC: subu        $t8, $t9, $t3
    ctx->r24 = SUB32(ctx->r25, ctx->r11);
    // 0x801779B0: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x801779B4: addiu       $a0, $a0, 0xD94
    ctx->r4 = ADD32(ctx->r4, 0XD94);
    // 0x801779B8: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x801779BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801779C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801779C4: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x801779C8: jal         0x800C6C6C
    // 0x801779CC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_13;
    // 0x801779CC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_13:
L_801779D0:
    // 0x801779D0: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x801779D4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801779D8: bne         $t7, $at, L_80177BBC
    if (ctx->r15 != ctx->r1) {
        // 0x801779DC: nop
    
            goto L_80177BBC;
    }
    // 0x801779DC: nop

    // 0x801779E0: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x801779E4: sll         $t4, $t7, 6
    ctx->r12 = S32(ctx->r15 << 6);
    // 0x801779E8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801779EC: sll         $t5, $t1, 4
    ctx->r13 = S32(ctx->r9 << 4);
    // 0x801779F0: addu        $t2, $t4, $t5
    ctx->r10 = ADD32(ctx->r12, ctx->r13);
    // 0x801779F4: addu        $t6, $t6, $t2
    ctx->r14 = ADD32(ctx->r14, ctx->r10);
    // 0x801779F8: lw          $t6, 0x389C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X389C);
    // 0x801779FC: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80177A00: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80177A04: sll         $t0, $t6, 2
    ctx->r8 = S32(ctx->r14 << 2);
    // 0x80177A08: addu        $t0, $t0, $t6
    ctx->r8 = ADD32(ctx->r8, ctx->r14);
    // 0x80177A0C: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x80177A10: addiu       $t9, $zero, 0x64
    ctx->r25 = ADD32(0, 0X64);
    // 0x80177A14: subu        $t3, $t9, $t0
    ctx->r11 = SUB32(ctx->r25, ctx->r8);
    // 0x80177A18: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80177A1C: addiu       $a0, $a0, 0xDD8
    ctx->r4 = ADD32(ctx->r4, 0XDD8);
    // 0x80177A20: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80177A24: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x80177A28: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80177A2C: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x80177A30: jal         0x800C6C6C
    // 0x80177A34: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_14;
    // 0x80177A34: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_14:
    // 0x80177A38: b           L_80177BBC
    // 0x80177A3C: nop

        goto L_80177BBC;
    // 0x80177A3C: nop

L_80177A40:
    // 0x80177A40: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80177A44: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80177A48: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80177A4C: sll         $t7, $t8, 6
    ctx->r15 = S32(ctx->r24 << 6);
    // 0x80177A50: sll         $t4, $t1, 4
    ctx->r12 = S32(ctx->r9 << 4);
    // 0x80177A54: addu        $t5, $t7, $t4
    ctx->r13 = ADD32(ctx->r15, ctx->r12);
    // 0x80177A58: addiu       $t2, $t2, 0x3898
    ctx->r10 = ADD32(ctx->r10, 0X3898);
    // 0x80177A5C: addu        $t6, $t5, $t2
    ctx->r14 = ADD32(ctx->r13, ctx->r10);
    // 0x80177A60: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x80177A64: sltiu       $at, $t9, 0x8
    ctx->r1 = ctx->r25 < 0X8 ? 1 : 0;
    // 0x80177A68: beq         $at, $zero, L_80177B48
    if (ctx->r1 == 0) {
        // 0x80177A6C: nop
    
            goto L_80177B48;
    }
    // 0x80177A6C: nop

    // 0x80177A70: addu        $t6, $t7, $t4
    ctx->r14 = ADD32(ctx->r15, ctx->r12);
    // 0x80177A74: addu        $t9, $t6, $t2
    ctx->r25 = ADD32(ctx->r14, ctx->r10);
    // 0x80177A78: sll         $t0, $t8, 2
    ctx->r8 = S32(ctx->r24 << 2);
    // 0x80177A7C: lw          $t8, 0x4($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X4);
    // 0x80177A80: addu        $t3, $t0, $t1
    ctx->r11 = ADD32(ctx->r8, ctx->r9);
    // 0x80177A84: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x80177A88: addu        $t6, $t7, $t4
    ctx->r14 = ADD32(ctx->r15, ctx->r12);
    // 0x80177A8C: srl         $t0, $t8, 1
    ctx->r8 = S32(U32(ctx->r24) >> 1);
    // 0x80177A90: addu        $t1, $t0, $t5
    ctx->r9 = ADD32(ctx->r8, ctx->r13);
    // 0x80177A94: addu        $t9, $t6, $t2
    ctx->r25 = ADD32(ctx->r14, ctx->r10);
    // 0x80177A98: lw          $t8, 0x4($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X4);
    // 0x80177A9C: sll         $t3, $t1, 2
    ctx->r11 = S32(ctx->r9 << 2);
    // 0x80177AA0: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80177AA4: addu        $a0, $a0, $t3
    ctx->r4 = ADD32(ctx->r4, ctx->r11);
    // 0x80177AA8: addu        $t1, $t7, $t4
    ctx->r9 = ADD32(ctx->r15, ctx->r12);
    // 0x80177AAC: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80177AB0: sll         $t0, $t8, 2
    ctx->r8 = S32(ctx->r24 << 2);
    // 0x80177AB4: addu        $t5, $t5, $t0
    ctx->r13 = ADD32(ctx->r13, ctx->r8);
    // 0x80177AB8: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80177ABC: addu        $t9, $t7, $t4
    ctx->r25 = ADD32(ctx->r15, ctx->r12);
    // 0x80177AC0: lw          $t6, 0x8($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X8);
    // 0x80177AC4: lw          $t5, -0x2540($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2540);
    // 0x80177AC8: addu        $t8, $t9, $t2
    ctx->r24 = ADD32(ctx->r25, ctx->r10);
    // 0x80177ACC: lw          $t0, 0x4($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X4);
    // 0x80177AD0: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    // 0x80177AD4: addu        $t5, $t7, $t4
    ctx->r13 = ADD32(ctx->r15, ctx->r12);
    // 0x80177AD8: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80177ADC: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80177AE0: addu        $t3, $t3, $t1
    ctx->r11 = ADD32(ctx->r11, ctx->r9);
    // 0x80177AE4: addu        $t6, $t5, $t2
    ctx->r14 = ADD32(ctx->r13, ctx->r10);
    // 0x80177AE8: lw          $t9, 0xC($t6)
    ctx->r25 = MEM_W(ctx->r14, 0XC);
    // 0x80177AEC: lw          $t3, -0x2540($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2540);
    // 0x80177AF0: addu        $t6, $t7, $t4
    ctx->r14 = ADD32(ctx->r15, ctx->r12);
    // 0x80177AF4: addu        $t8, $t7, $t4
    ctx->r24 = ADD32(ctx->r15, ctx->r12);
    // 0x80177AF8: addu        $a2, $t3, $t9
    ctx->r6 = ADD32(ctx->r11, ctx->r25);
    // 0x80177AFC: addu        $t3, $t6, $t2
    ctx->r11 = ADD32(ctx->r14, ctx->r10);
    // 0x80177B00: lw          $t9, 0x4($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X4);
    // 0x80177B04: addu        $t0, $t8, $t2
    ctx->r8 = ADD32(ctx->r24, ctx->r10);
    // 0x80177B08: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x80177B0C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80177B10: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80177B14: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80177B18: lwc1        $f10, -0x2560($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2560);
    // 0x80177B1C: lui         $a3, 0x801A
    ctx->r7 = S32(0X801A << 16);
    // 0x80177B20: sll         $t5, $t1, 2
    ctx->r13 = S32(ctx->r9 << 2);
    // 0x80177B24: addu        $a3, $a3, $t5
    ctx->r7 = ADD32(ctx->r7, ctx->r13);
    // 0x80177B28: addiu       $t0, $zero, 0xC8
    ctx->r8 = ADD32(0, 0XC8);
    // 0x80177B2C: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80177B30: lw          $a3, -0x2560($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X2560);
    // 0x80177B34: lw          $a0, -0x2628($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2628);
    // 0x80177B38: jal         0x800C6C6C
    // 0x80177B3C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_15;
    // 0x80177B3C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_15:
    // 0x80177B40: b           L_80177BBC
    // 0x80177B44: nop

        goto L_80177BBC;
    // 0x80177B44: nop

L_80177B48:
    // 0x80177B48: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80177B4C: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80177B50: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80177B54: sll         $t5, $t1, 2
    ctx->r13 = S32(ctx->r9 << 2);
    // 0x80177B58: addu        $t4, $t5, $t7
    ctx->r12 = ADD32(ctx->r13, ctx->r15);
    // 0x80177B5C: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x80177B60: sll         $t2, $t6, 2
    ctx->r10 = S32(ctx->r14 << 2);
    // 0x80177B64: sll         $t3, $t1, 6
    ctx->r11 = S32(ctx->r9 << 6);
    // 0x80177B68: addiu       $t0, $t0, 0x3898
    ctx->r8 = ADD32(ctx->r8, 0X3898);
    // 0x80177B6C: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80177B70: sll         $t4, $t7, 4
    ctx->r12 = S32(ctx->r15 << 4);
    // 0x80177B74: sll         $t9, $t7, 4
    ctx->r25 = S32(ctx->r15 << 4);
    // 0x80177B78: addu        $t8, $t3, $t9
    ctx->r24 = ADD32(ctx->r11, ctx->r25);
    // 0x80177B7C: addu        $t6, $t3, $t4
    ctx->r14 = ADD32(ctx->r11, ctx->r12);
    // 0x80177B80: addu        $a0, $a0, $t2
    ctx->r4 = ADD32(ctx->r4, ctx->r10);
    // 0x80177B84: addu        $t2, $t6, $t0
    ctx->r10 = ADD32(ctx->r14, ctx->r8);
    // 0x80177B88: addu        $t5, $t8, $t0
    ctx->r13 = ADD32(ctx->r24, ctx->r8);
    // 0x80177B8C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80177B90: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80177B94: lw          $a1, 0x8($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X8);
    // 0x80177B98: lw          $a2, 0xC($t2)
    ctx->r6 = MEM_W(ctx->r10, 0XC);
    // 0x80177B9C: addiu       $t1, $zero, 0xC8
    ctx->r9 = ADD32(0, 0XC8);
    // 0x80177BA0: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80177BA4: lw          $a0, -0x261C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X261C);
    // 0x80177BA8: lui         $a3, 0x4080
    ctx->r7 = S32(0X4080 << 16);
    // 0x80177BAC: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x80177BB0: addiu       $a1, $a1, -0x60
    ctx->r5 = ADD32(ctx->r5, -0X60);
    // 0x80177BB4: jal         0x800C6C6C
    // 0x80177BB8: addiu       $a2, $a2, -0x60
    ctx->r6 = ADD32(ctx->r6, -0X60);
    func_800C6C6C(rdram, ctx);
        goto after_16;
    // 0x80177BB8: addiu       $a2, $a2, -0x60
    ctx->r6 = ADD32(ctx->r6, -0X60);
    after_16:
L_80177BBC:
    // 0x80177BBC: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80177BC0: addiu       $t8, $t9, 0x1
    ctx->r24 = ADD32(ctx->r25, 0X1);
    // 0x80177BC4: sltiu       $at, $t8, 0x4
    ctx->r1 = ctx->r24 < 0X4 ? 1 : 0;
    // 0x80177BC8: bne         $at, $zero, L_80177388
    if (ctx->r1 != 0) {
        // 0x80177BCC: sw          $t8, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r24;
            goto L_80177388;
    }
    // 0x80177BCC: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x80177BD0: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80177BD4: addiu       $t7, $t5, 0x1
    ctx->r15 = ADD32(ctx->r13, 0X1);
    // 0x80177BD8: sltiu       $at, $t7, 0x2
    ctx->r1 = ctx->r15 < 0X2 ? 1 : 0;
    // 0x80177BDC: bne         $at, $zero, L_80177384
    if (ctx->r1 != 0) {
        // 0x80177BE0: sw          $t7, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r15;
            goto L_80177384;
    }
    // 0x80177BE0: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x80177BE4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80177BE8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80177BEC: jr          $ra
    // 0x80177BF0: nop

    return;
    // 0x80177BF0: nop

;}
RECOMP_FUNC void func_80177BF4_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80177BF4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80177BF8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80177BFC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80177C00: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80177C04: addiu       $t6, $t6, -0x2E28
    ctx->r14 = ADD32(ctx->r14, -0X2E28);
    // 0x80177C08: lbu         $t7, 0xC($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0XC);
    // 0x80177C0C: andi        $t8, $t7, 0x10
    ctx->r24 = ctx->r15 & 0X10;
    // 0x80177C10: bne         $t8, $zero, L_80177F24
    if (ctx->r24 != 0) {
        // 0x80177C14: nop
    
            goto L_80177F24;
    }
    // 0x80177C14: nop

    // 0x80177C18: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80177C1C: lw          $t9, -0x2E48($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2E48);
    // 0x80177C20: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80177C24: beq         $t9, $at, L_80177CA0
    if (ctx->r25 == ctx->r1) {
        // 0x80177C28: nop
    
            goto L_80177CA0;
    }
    // 0x80177C28: nop

    // 0x80177C2C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80177C30: addiu       $t0, $t0, -0x2BA8
    ctx->r8 = ADD32(ctx->r8, -0X2BA8);
    // 0x80177C34: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x80177C38: bne         $t1, $zero, L_80177F24
    if (ctx->r9 != 0) {
        // 0x80177C3C: nop
    
            goto L_80177F24;
    }
    // 0x80177C3C: nop

    // 0x80177C40: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80177C44: addiu       $t2, $t2, -0x2E18
    ctx->r10 = ADD32(ctx->r10, -0X2E18);
    // 0x80177C48: jal         0x80177F38
    // 0x80177C4C: lw          $a0, 0x70($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X70);
    func_80177F38_1501A0(rdram, ctx);
        goto after_0;
    // 0x80177C4C: lw          $a0, 0x70($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X70);
    after_0:
    // 0x80177C50: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80177C54: addiu       $t3, $t3, -0x2E18
    ctx->r11 = ADD32(ctx->r11, -0X2E18);
    // 0x80177C58: lw          $s0, 0x70($t3)
    ctx->r16 = MEM_W(ctx->r11, 0X70);
    // 0x80177C5C: lw          $t5, 0x70($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X70);
    // 0x80177C60: xori        $t4, $s0, 0x28
    ctx->r12 = ctx->r16 ^ 0X28;
    // 0x80177C64: sltiu       $t4, $t4, 0x1
    ctx->r12 = ctx->r12 < 0X1 ? 1 : 0;
    // 0x80177C68: or          $s0, $t4, $zero
    ctx->r16 = ctx->r12 | 0;
    // 0x80177C6C: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80177C70: beq         $s0, $zero, L_80177F24
    if (ctx->r16 == 0) {
        // 0x80177C74: sw          $t6, 0x70($t3)
        MEM_W(0X70, ctx->r11) = ctx->r14;
            goto L_80177F24;
    }
    // 0x80177C74: sw          $t6, 0x70($t3)
    MEM_W(0X70, ctx->r11) = ctx->r14;
    // 0x80177C78: jal         0x801794CC
    // 0x80177C7C: nop

    func_801794CC_1501A0(rdram, ctx);
        goto after_1;
    // 0x80177C7C: nop

    after_1:
    // 0x80177C80: jal         0x8016DCD4
    // 0x80177C84: nop

    func_8016DCD4_1501A0(rdram, ctx);
        goto after_2;
    // 0x80177C84: nop

    after_2:
    // 0x80177C88: jal         0x800C992C
    // 0x80177C8C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800C992C(rdram, ctx);
        goto after_3;
    // 0x80177C8C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x80177C90: jal         0x800D1680
    // 0x80177C94: nop

    func_800D1680(rdram, ctx);
        goto after_4;
    // 0x80177C94: nop

    after_4:
    // 0x80177C98: b           L_80177F24
    // 0x80177C9C: nop

        goto L_80177F24;
    // 0x80177C9C: nop

L_80177CA0:
    // 0x80177CA0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80177CA4: addiu       $t7, $t7, -0x2E28
    ctx->r15 = ADD32(ctx->r15, -0X2E28);
    // 0x80177CA8: lbu         $t8, 0xC($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0XC);
    // 0x80177CAC: addiu       $at, $zero, 0x60
    ctx->r1 = ADD32(0, 0X60);
    // 0x80177CB0: andi        $t9, $t8, 0x60
    ctx->r25 = ctx->r24 & 0X60;
    // 0x80177CB4: bne         $t9, $at, L_80177D1C
    if (ctx->r25 != ctx->r1) {
        // 0x80177CB8: nop
    
            goto L_80177D1C;
    }
    // 0x80177CB8: nop

    // 0x80177CBC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80177CC0: addiu       $t0, $t0, -0x2E18
    ctx->r8 = ADD32(ctx->r8, -0X2E18);
    // 0x80177CC4: jal         0x80177F38
    // 0x80177CC8: lw          $a0, 0x78($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X78);
    func_80177F38_1501A0(rdram, ctx);
        goto after_5;
    // 0x80177CC8: lw          $a0, 0x78($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X78);
    after_5:
    // 0x80177CCC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80177CD0: addiu       $t1, $t1, -0x2E18
    ctx->r9 = ADD32(ctx->r9, -0X2E18);
    // 0x80177CD4: lw          $s0, 0x78($t1)
    ctx->r16 = MEM_W(ctx->r9, 0X78);
    // 0x80177CD8: lw          $t4, 0x78($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X78);
    // 0x80177CDC: xori        $t2, $s0, 0x46
    ctx->r10 = ctx->r16 ^ 0X46;
    // 0x80177CE0: sltiu       $t2, $t2, 0x1
    ctx->r10 = ctx->r10 < 0X1 ? 1 : 0;
    // 0x80177CE4: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
    // 0x80177CE8: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80177CEC: beq         $s0, $zero, L_80177F24
    if (ctx->r16 == 0) {
        // 0x80177CF0: sw          $t5, 0x78($t1)
        MEM_W(0X78, ctx->r9) = ctx->r13;
            goto L_80177F24;
    }
    // 0x80177CF0: sw          $t5, 0x78($t1)
    MEM_W(0X78, ctx->r9) = ctx->r13;
    // 0x80177CF4: jal         0x801794CC
    // 0x80177CF8: nop

    func_801794CC_1501A0(rdram, ctx);
        goto after_6;
    // 0x80177CF8: nop

    after_6:
    // 0x80177CFC: jal         0x8016DCD4
    // 0x80177D00: nop

    func_8016DCD4_1501A0(rdram, ctx);
        goto after_7;
    // 0x80177D00: nop

    after_7:
    // 0x80177D04: jal         0x800C992C
    // 0x80177D08: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800C992C(rdram, ctx);
        goto after_8;
    // 0x80177D08: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_8:
    // 0x80177D0C: jal         0x800D1680
    // 0x80177D10: nop

    func_800D1680(rdram, ctx);
        goto after_9;
    // 0x80177D10: nop

    after_9:
    // 0x80177D14: b           L_80177F24
    // 0x80177D18: nop

        goto L_80177F24;
    // 0x80177D18: nop

L_80177D1C:
    // 0x80177D1C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80177D20: addiu       $t6, $t6, -0x2BA8
    ctx->r14 = ADD32(ctx->r14, -0X2BA8);
    // 0x80177D24: lw          $t3, 0xC($t6)
    ctx->r11 = MEM_W(ctx->r14, 0XC);
    // 0x80177D28: bne         $t3, $zero, L_80177E20
    if (ctx->r11 != 0) {
        // 0x80177D2C: nop
    
            goto L_80177E20;
    }
    // 0x80177D2C: nop

    // 0x80177D30: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80177D34: addiu       $t7, $t7, -0x2E28
    ctx->r15 = ADD32(ctx->r15, -0X2E28);
    // 0x80177D38: lbu         $t8, 0xC($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0XC);
    // 0x80177D3C: andi        $t9, $t8, 0x40
    ctx->r25 = ctx->r24 & 0X40;
    // 0x80177D40: beq         $t9, $zero, L_80177D54
    if (ctx->r25 == 0) {
        // 0x80177D44: nop
    
            goto L_80177D54;
    }
    // 0x80177D44: nop

    // 0x80177D48: ori         $t0, $t8, 0x20
    ctx->r8 = ctx->r24 | 0X20;
    // 0x80177D4C: b           L_80177F24
    // 0x80177D50: sb          $t0, 0xC($t7)
    MEM_B(0XC, ctx->r15) = ctx->r8;
        goto L_80177F24;
    // 0x80177D50: sb          $t0, 0xC($t7)
    MEM_B(0XC, ctx->r15) = ctx->r8;
L_80177D54:
    // 0x80177D54: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80177D58: addiu       $t2, $t2, -0x2E28
    ctx->r10 = ADD32(ctx->r10, -0X2E28);
    // 0x80177D5C: lbu         $t4, 0xC($t2)
    ctx->r12 = MEM_BU(ctx->r10, 0XC);
    // 0x80177D60: andi        $t5, $t4, 0x20
    ctx->r13 = ctx->r12 & 0X20;
    // 0x80177D64: bne         $t5, $zero, L_80177DE4
    if (ctx->r13 != 0) {
        // 0x80177D68: lui         $at, 0x41F0
        ctx->r1 = S32(0X41F0 << 16);
            goto L_80177DE4;
    }
    // 0x80177D68: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80177D6C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80177D70: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80177D74: addiu       $t1, $t1, -0x2E18
    ctx->r9 = ADD32(ctx->r9, -0X2E18);
    // 0x80177D78: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80177D7C: lw          $t6, 0x70($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X70);
    // 0x80177D80: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80177D84: addiu       $a0, $a0, 0xE1C
    ctx->r4 = ADD32(ctx->r4, 0XE1C);
    // 0x80177D88: sll         $t3, $t6, 2
    ctx->r11 = S32(ctx->r14 << 2);
    // 0x80177D8C: subu        $t3, $t3, $t6
    ctx->r11 = SUB32(ctx->r11, ctx->r14);
    // 0x80177D90: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80177D94: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80177D98: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80177D9C: jal         0x800C6C6C
    // 0x80177DA0: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    func_800C6C6C(rdram, ctx);
        goto after_10;
    // 0x80177DA0: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    after_10:
    // 0x80177DA4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80177DA8: addiu       $t9, $t9, -0x2E18
    ctx->r25 = ADD32(ctx->r25, -0X2E18);
    // 0x80177DAC: lw          $s0, 0x70($t9)
    ctx->r16 = MEM_W(ctx->r25, 0X70);
    // 0x80177DB0: lw          $t0, 0x70($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X70);
    // 0x80177DB4: xori        $t8, $s0, 0x28
    ctx->r24 = ctx->r16 ^ 0X28;
    // 0x80177DB8: sltiu       $t8, $t8, 0x1
    ctx->r24 = ctx->r24 < 0X1 ? 1 : 0;
    // 0x80177DBC: or          $s0, $t8, $zero
    ctx->r16 = ctx->r24 | 0;
    // 0x80177DC0: addiu       $t7, $t0, 0x1
    ctx->r15 = ADD32(ctx->r8, 0X1);
    // 0x80177DC4: beq         $s0, $zero, L_80177E20
    if (ctx->r16 == 0) {
        // 0x80177DC8: sw          $t7, 0x70($t9)
        MEM_W(0X70, ctx->r25) = ctx->r15;
            goto L_80177E20;
    }
    // 0x80177DC8: sw          $t7, 0x70($t9)
    MEM_W(0X70, ctx->r25) = ctx->r15;
    // 0x80177DCC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80177DD0: addiu       $t2, $t2, -0x2E28
    ctx->r10 = ADD32(ctx->r10, -0X2E28);
    // 0x80177DD4: lbu         $t4, 0xC($t2)
    ctx->r12 = MEM_BU(ctx->r10, 0XC);
    // 0x80177DD8: ori         $t5, $t4, 0x20
    ctx->r13 = ctx->r12 | 0X20;
    // 0x80177DDC: b           L_80177E20
    // 0x80177DE0: sb          $t5, 0xC($t2)
    MEM_B(0XC, ctx->r10) = ctx->r13;
        goto L_80177E20;
    // 0x80177DE0: sb          $t5, 0xC($t2)
    MEM_B(0XC, ctx->r10) = ctx->r13;
L_80177DE4:
    // 0x80177DE4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80177DE8: lhu         $t1, -0x2BA8($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X2BA8);
    // 0x80177DEC: andi        $t6, $t1, 0x4000
    ctx->r14 = ctx->r9 & 0X4000;
    // 0x80177DF0: bne         $t6, $zero, L_80177E20
    if (ctx->r14 != 0) {
        // 0x80177DF4: lui         $at, 0x41F0
        ctx->r1 = S32(0X41F0 << 16);
            goto L_80177E20;
    }
    // 0x80177DF4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80177DF8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80177DFC: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80177E00: addiu       $t3, $zero, 0x80
    ctx->r11 = ADD32(0, 0X80);
    // 0x80177E04: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80177E08: addiu       $a0, $a0, 0xE1C
    ctx->r4 = ADD32(ctx->r4, 0XE1C);
    // 0x80177E0C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80177E10: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80177E14: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x80177E18: jal         0x800C6C6C
    // 0x80177E1C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_11;
    // 0x80177E1C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_11:
L_80177E20:
    // 0x80177E20: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80177E24: addiu       $t8, $t8, -0x2BA8
    ctx->r24 = ADD32(ctx->r24, -0X2BA8);
    // 0x80177E28: lw          $t0, 0x10($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X10);
    // 0x80177E2C: bne         $t0, $zero, L_80177F24
    if (ctx->r8 != 0) {
        // 0x80177E30: nop
    
            goto L_80177F24;
    }
    // 0x80177E30: nop

    // 0x80177E34: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80177E38: addiu       $t7, $t7, -0x2E28
    ctx->r15 = ADD32(ctx->r15, -0X2E28);
    // 0x80177E3C: lbu         $t9, 0xC($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0XC);
    // 0x80177E40: andi        $t4, $t9, 0x20
    ctx->r12 = ctx->r25 & 0X20;
    // 0x80177E44: beq         $t4, $zero, L_80177E58
    if (ctx->r12 == 0) {
        // 0x80177E48: nop
    
            goto L_80177E58;
    }
    // 0x80177E48: nop

    // 0x80177E4C: ori         $t5, $t9, 0x40
    ctx->r13 = ctx->r25 | 0X40;
    // 0x80177E50: b           L_80177F24
    // 0x80177E54: sb          $t5, 0xC($t7)
    MEM_B(0XC, ctx->r15) = ctx->r13;
        goto L_80177F24;
    // 0x80177E54: sb          $t5, 0xC($t7)
    MEM_B(0XC, ctx->r15) = ctx->r13;
L_80177E58:
    // 0x80177E58: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80177E5C: addiu       $t2, $t2, -0x2E28
    ctx->r10 = ADD32(ctx->r10, -0X2E28);
    // 0x80177E60: lbu         $t1, 0xC($t2)
    ctx->r9 = MEM_BU(ctx->r10, 0XC);
    // 0x80177E64: andi        $t6, $t1, 0x40
    ctx->r14 = ctx->r9 & 0X40;
    // 0x80177E68: bne         $t6, $zero, L_80177EE8
    if (ctx->r14 != 0) {
        // 0x80177E6C: lui         $at, 0x41F0
        ctx->r1 = S32(0X41F0 << 16);
            goto L_80177EE8;
    }
    // 0x80177E6C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80177E70: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80177E74: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80177E78: addiu       $t3, $t3, -0x2E18
    ctx->r11 = ADD32(ctx->r11, -0X2E18);
    // 0x80177E7C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x80177E80: lw          $t8, 0x74($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X74);
    // 0x80177E84: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80177E88: addiu       $a0, $a0, 0xE60
    ctx->r4 = ADD32(ctx->r4, 0XE60);
    // 0x80177E8C: sll         $t0, $t8, 2
    ctx->r8 = S32(ctx->r24 << 2);
    // 0x80177E90: subu        $t0, $t0, $t8
    ctx->r8 = SUB32(ctx->r8, ctx->r24);
    // 0x80177E94: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80177E98: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x80177E9C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80177EA0: jal         0x800C6C6C
    // 0x80177EA4: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    func_800C6C6C(rdram, ctx);
        goto after_12;
    // 0x80177EA4: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    after_12:
    // 0x80177EA8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80177EAC: addiu       $t4, $t4, -0x2E18
    ctx->r12 = ADD32(ctx->r12, -0X2E18);
    // 0x80177EB0: lw          $s0, 0x74($t4)
    ctx->r16 = MEM_W(ctx->r12, 0X74);
    // 0x80177EB4: lw          $t5, 0x74($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X74);
    // 0x80177EB8: xori        $t9, $s0, 0x28
    ctx->r25 = ctx->r16 ^ 0X28;
    // 0x80177EBC: sltiu       $t9, $t9, 0x1
    ctx->r25 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80177EC0: or          $s0, $t9, $zero
    ctx->r16 = ctx->r25 | 0;
    // 0x80177EC4: addiu       $t7, $t5, 0x1
    ctx->r15 = ADD32(ctx->r13, 0X1);
    // 0x80177EC8: beq         $s0, $zero, L_80177F24
    if (ctx->r16 == 0) {
        // 0x80177ECC: sw          $t7, 0x74($t4)
        MEM_W(0X74, ctx->r12) = ctx->r15;
            goto L_80177F24;
    }
    // 0x80177ECC: sw          $t7, 0x74($t4)
    MEM_W(0X74, ctx->r12) = ctx->r15;
    // 0x80177ED0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80177ED4: addiu       $t2, $t2, -0x2E28
    ctx->r10 = ADD32(ctx->r10, -0X2E28);
    // 0x80177ED8: lbu         $t1, 0xC($t2)
    ctx->r9 = MEM_BU(ctx->r10, 0XC);
    // 0x80177EDC: ori         $t6, $t1, 0x40
    ctx->r14 = ctx->r9 | 0X40;
    // 0x80177EE0: b           L_80177F24
    // 0x80177EE4: sb          $t6, 0xC($t2)
    MEM_B(0XC, ctx->r10) = ctx->r14;
        goto L_80177F24;
    // 0x80177EE4: sb          $t6, 0xC($t2)
    MEM_B(0XC, ctx->r10) = ctx->r14;
L_80177EE8:
    // 0x80177EE8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80177EEC: lhu         $t3, -0x2BA8($t3)
    ctx->r11 = MEM_HU(ctx->r11, -0X2BA8);
    // 0x80177EF0: andi        $t8, $t3, 0x4000
    ctx->r24 = ctx->r11 & 0X4000;
    // 0x80177EF4: bne         $t8, $zero, L_80177F24
    if (ctx->r24 != 0) {
        // 0x80177EF8: lui         $at, 0x41F0
        ctx->r1 = S32(0X41F0 << 16);
            goto L_80177F24;
    }
    // 0x80177EF8: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80177EFC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80177F00: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80177F04: addiu       $t0, $zero, 0x80
    ctx->r8 = ADD32(0, 0X80);
    // 0x80177F08: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80177F0C: addiu       $a0, $a0, 0xE60
    ctx->r4 = ADD32(ctx->r4, 0XE60);
    // 0x80177F10: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x80177F14: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80177F18: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x80177F1C: jal         0x800C6C6C
    // 0x80177F20: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_13;
    // 0x80177F20: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_13:
L_80177F24:
    // 0x80177F24: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80177F28: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80177F2C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80177F30: jr          $ra
    // 0x80177F34: nop

    return;
    // 0x80177F34: nop

;}
RECOMP_FUNC void func_80177F38_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80177F38: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80177F3C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80177F40: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80177F44: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80177F48: addiu       $t6, $t6, -0x4198
    ctx->r14 = ADD32(ctx->r14, -0X4198);
    // 0x80177F4C: lwc1        $f4, 0x4($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X4);
    // 0x80177F50: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80177F54: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x80177F58: swc1        $f4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f4.u32l;
    // 0x80177F5C: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80177F60: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x80177F64: beq         $t9, $zero, L_80177F8C
    if (ctx->r25 == 0) {
        // 0x80177F68: nop
    
            goto L_80177F8C;
    }
    // 0x80177F68: nop

    // 0x80177F6C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80177F70: addiu       $t0, $t0, -0x4198
    ctx->r8 = ADD32(ctx->r8, -0X4198);
    // 0x80177F74: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80177F78: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80177F7C: lwc1        $f6, 0x4($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X4);
    // 0x80177F80: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80177F84: b           L_80177FA8
    // 0x80177F88: swc1        $f10, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f10.u32l;
        goto L_80177FA8;
    // 0x80177F88: swc1        $f10, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f10.u32l;
L_80177F8C:
    // 0x80177F8C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80177F90: addiu       $t1, $t1, -0x4198
    ctx->r9 = ADD32(ctx->r9, -0X4198);
    // 0x80177F94: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80177F98: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80177F9C: lwc1        $f16, 0x4($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X4);
    // 0x80177FA0: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80177FA4: swc1        $f4, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->f4.u32l;
L_80177FA8:
    // 0x80177FA8: jal         0x800C3FD0
    // 0x80177FAC: nop

    func_800C3FD0(rdram, ctx);
        goto after_0;
    // 0x80177FAC: nop

    after_0:
    // 0x80177FB0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80177FB4: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x80177FB8: lwc1        $f6, 0x0($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X0);
    // 0x80177FBC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80177FC0: addiu       $t3, $t3, -0x4198
    ctx->r11 = ADD32(ctx->r11, -0X4198);
    // 0x80177FC4: swc1        $f6, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->f6.u32l;
    // 0x80177FC8: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80177FCC: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x80177FD0: beq         $t5, $zero, L_80178008
    if (ctx->r13 == 0) {
        // 0x80177FD4: lui         $at, 0x4020
        ctx->r1 = S32(0X4020 << 16);
            goto L_80178008;
    }
    // 0x80177FD4: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x80177FD8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80177FDC: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80177FE0: addiu       $t6, $zero, 0x50
    ctx->r14 = ADD32(0, 0X50);
    // 0x80177FE4: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80177FE8: addiu       $a0, $a0, 0x2774
    ctx->r4 = ADD32(ctx->r4, 0X2774);
    // 0x80177FEC: addiu       $a1, $zero, -0x3
    ctx->r5 = ADD32(0, -0X3);
    // 0x80177FF0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80177FF4: lui         $a3, 0x4020
    ctx->r7 = S32(0X4020 << 16);
    // 0x80177FF8: jal         0x800C6C6C
    // 0x80177FFC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_1;
    // 0x80177FFC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x80178000: b           L_80178034
    // 0x80178004: nop

        goto L_80178034;
    // 0x80178004: nop

L_80178008:
    // 0x80178008: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x8017800C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80178010: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80178014: addiu       $t7, $zero, 0x50
    ctx->r15 = ADD32(0, 0X50);
    // 0x80178018: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8017801C: addiu       $a0, $a0, 0x2774
    ctx->r4 = ADD32(ctx->r4, 0X2774);
    // 0x80178020: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80178024: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80178028: lui         $a3, 0x4020
    ctx->r7 = S32(0X4020 << 16);
    // 0x8017802C: jal         0x800C6C6C
    // 0x80178030: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_2;
    // 0x80178030: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_2:
L_80178034:
    // 0x80178034: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80178038: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017803C: jr          $ra
    // 0x80178040: nop

    return;
    // 0x80178040: nop

;}
RECOMP_FUNC void func_80178044_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80178044: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80178048: lw          $t6, -0x2E48($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2E48);
    // 0x8017804C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80178050: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80178054: bne         $t6, $at, L_80178308
    if (ctx->r14 != ctx->r1) {
        // 0x80178058: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80178308;
    }
    // 0x80178058: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017805C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80178060: addiu       $t7, $t7, -0x2E28
    ctx->r15 = ADD32(ctx->r15, -0X2E28);
    // 0x80178064: lbu         $t8, 0xA($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0XA);
    // 0x80178068: andi        $t9, $t8, 0x2
    ctx->r25 = ctx->r24 & 0X2;
    // 0x8017806C: beq         $t9, $zero, L_80178088
    if (ctx->r25 == 0) {
        // 0x80178070: nop
    
            goto L_80178088;
    }
    // 0x80178070: nop

    // 0x80178074: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80178078: addiu       $t0, $t0, -0x2E18
    ctx->r8 = ADD32(ctx->r8, -0X2E18);
    // 0x8017807C: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x80178080: beq         $t1, $zero, L_80178308
    if (ctx->r9 == 0) {
        // 0x80178084: nop
    
            goto L_80178308;
    }
    // 0x80178084: nop

L_80178088:
    // 0x80178088: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017808C: addiu       $t2, $t2, -0x2E28
    ctx->r10 = ADD32(ctx->r10, -0X2E28);
    // 0x80178090: lbu         $t3, 0xA($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0XA);
    // 0x80178094: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x80178098: bne         $t4, $zero, L_80178308
    if (ctx->r12 != 0) {
        // 0x8017809C: nop
    
            goto L_80178308;
    }
    // 0x8017809C: nop

    // 0x801780A0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x801780A4: lhu         $t5, -0x2BA8($t5)
    ctx->r13 = MEM_HU(ctx->r13, -0X2BA8);
    // 0x801780A8: andi        $t6, $t5, 0x4000
    ctx->r14 = ctx->r13 & 0X4000;
    // 0x801780AC: bne         $t6, $zero, L_80178308
    if (ctx->r14 != 0) {
        // 0x801780B0: nop
    
            goto L_80178308;
    }
    // 0x801780B0: nop

    // 0x801780B4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801780B8: addiu       $t7, $t7, -0x2E28
    ctx->r15 = ADD32(ctx->r15, -0X2E28);
    // 0x801780BC: lbu         $t8, 0xC($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0XC);
    // 0x801780C0: addiu       $at, $zero, 0x60
    ctx->r1 = ADD32(0, 0X60);
    // 0x801780C4: andi        $t9, $t8, 0x60
    ctx->r25 = ctx->r24 & 0X60;
    // 0x801780C8: beq         $t9, $at, L_80178308
    if (ctx->r25 == ctx->r1) {
        // 0x801780CC: nop
    
            goto L_80178308;
    }
    // 0x801780CC: nop

    // 0x801780D0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x801780D4: addiu       $t0, $t0, -0x2E28
    ctx->r8 = ADD32(ctx->r8, -0X2E28);
    // 0x801780D8: lbu         $t1, 0xC($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0XC);
    // 0x801780DC: andi        $t2, $t1, 0x20
    ctx->r10 = ctx->r9 & 0X20;
    // 0x801780E0: beq         $t2, $zero, L_801781EC
    if (ctx->r10 == 0) {
        // 0x801780E4: nop
    
            goto L_801781EC;
    }
    // 0x801780E4: nop

    // 0x801780E8: jal         0x800C7AD0
    // 0x801780EC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800C7AD0(rdram, ctx);
        goto after_0;
    // 0x801780EC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x801780F0: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x801780F4: jal         0x800C7A60
    // 0x801780F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C7A60(rdram, ctx);
        goto after_1;
    // 0x801780F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x801780FC: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80178100: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x80178104: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80178108: mtc1        $at, $f15
    ctx->f_odd[(15 - 1) * 2] = ctx->r1;
    // 0x8017810C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80178110: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80178114: jal         0x800C7A88
    // 0x80178118: nop

    func_800C7A88(rdram, ctx);
        goto after_2;
    // 0x80178118: nop

    after_2:
    // 0x8017811C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80178120: addiu       $t3, $t3, -0x2E18
    ctx->r11 = ADD32(ctx->r11, -0X2E18);
    // 0x80178124: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x80178128: andi        $t5, $t4, 0x10
    ctx->r13 = ctx->r12 & 0X10;
    // 0x8017812C: beq         $t5, $zero, L_8017815C
    if (ctx->r13 == 0) {
        // 0x80178130: nop
    
            goto L_8017815C;
    }
    // 0x80178130: nop

    // 0x80178134: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    // 0x80178138: jal         0x800C7A74
    // 0x8017813C: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    func_800C7A74(rdram, ctx);
        goto after_3;
    // 0x8017813C: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    after_3:
    // 0x80178140: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80178144: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80178148: addiu       $a1, $a1, -0xD18
    ctx->r5 = ADD32(ctx->r5, -0XD18);
    // 0x8017814C: jal         0x800D87E4
    // 0x80178150: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_4;
    // 0x80178150: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_4:
    // 0x80178154: b           L_8017817C
    // 0x80178158: nop

        goto L_8017817C;
    // 0x80178158: nop

L_8017815C:
    // 0x8017815C: addiu       $a0, $zero, 0x3E
    ctx->r4 = ADD32(0, 0X3E);
    // 0x80178160: jal         0x800C7A74
    // 0x80178164: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    func_800C7A74(rdram, ctx);
        goto after_5;
    // 0x80178164: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    after_5:
    // 0x80178168: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017816C: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80178170: addiu       $a1, $a1, -0xD00
    ctx->r5 = ADD32(ctx->r5, -0XD00);
    // 0x80178174: jal         0x800D87E4
    // 0x80178178: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_6;
    // 0x80178178: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_6:
L_8017817C:
    // 0x8017817C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80178180: addiu       $t6, $t6, -0x2E18
    ctx->r14 = ADD32(ctx->r14, -0X2E18);
    // 0x80178184: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80178188: lui         $a3, 0x801A
    ctx->r7 = S32(0X801A << 16);
    // 0x8017818C: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80178190: andi        $t8, $t7, 0xF
    ctx->r24 = ctx->r15 & 0XF;
    // 0x80178194: addu        $a3, $a3, $t8
    ctx->r7 = ADD32(ctx->r7, ctx->r24);
    // 0x80178198: lbu         $a3, -0x2520($a3)
    ctx->r7 = MEM_BU(ctx->r7, -0X2520);
    // 0x8017819C: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    // 0x801781A0: jal         0x800C7A9C
    // 0x801781A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800C7A9C(rdram, ctx);
        goto after_7;
    // 0x801781A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x801781A8: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x801781AC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x801781B0: addiu       $a1, $a1, 0x3B40
    ctx->r5 = ADD32(ctx->r5, 0X3B40);
    // 0x801781B4: jal         0x800C767C
    // 0x801781B8: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    func_800C767C(rdram, ctx);
        goto after_8;
    // 0x801781B8: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    after_8:
    // 0x801781BC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801781C0: addiu       $t9, $t9, -0x41E0
    ctx->r25 = ADD32(ctx->r25, -0X41E0);
    // 0x801781C4: lhu         $t0, 0x2($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X2);
    // 0x801781C8: andi        $t1, $t0, 0xB000
    ctx->r9 = ctx->r8 & 0XB000;
    // 0x801781CC: bne         $t1, $zero, L_801781E4
    if (ctx->r9 != 0) {
        // 0x801781D0: nop
    
            goto L_801781E4;
    }
    // 0x801781D0: nop

    // 0x801781D4: lhu         $t2, 0x16($t9)
    ctx->r10 = MEM_HU(ctx->r25, 0X16);
    // 0x801781D8: andi        $t3, $t2, 0xB000
    ctx->r11 = ctx->r10 & 0XB000;
    // 0x801781DC: beq         $t3, $zero, L_801781EC
    if (ctx->r11 == 0) {
        // 0x801781E0: nop
    
            goto L_801781EC;
    }
    // 0x801781E0: nop

L_801781E4:
    // 0x801781E4: jal         0x80178318
    // 0x801781E8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80178318_1501A0(rdram, ctx);
        goto after_9;
    // 0x801781E8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_9:
L_801781EC:
    // 0x801781EC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x801781F0: addiu       $t4, $t4, -0x2E28
    ctx->r12 = ADD32(ctx->r12, -0X2E28);
    // 0x801781F4: lbu         $t5, 0xC($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0XC);
    // 0x801781F8: andi        $t6, $t5, 0x40
    ctx->r14 = ctx->r13 & 0X40;
    // 0x801781FC: beq         $t6, $zero, L_80178308
    if (ctx->r14 == 0) {
        // 0x80178200: nop
    
            goto L_80178308;
    }
    // 0x80178200: nop

    // 0x80178204: jal         0x800C7AD0
    // 0x80178208: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800C7AD0(rdram, ctx);
        goto after_10;
    // 0x80178208: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_10:
    // 0x8017820C: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x80178210: jal         0x800C7A60
    // 0x80178214: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C7A60(rdram, ctx);
        goto after_11;
    // 0x80178214: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x80178218: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8017821C: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x80178220: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80178224: mtc1        $at, $f15
    ctx->f_odd[(15 - 1) * 2] = ctx->r1;
    // 0x80178228: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8017822C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80178230: jal         0x800C7A88
    // 0x80178234: nop

    func_800C7A88(rdram, ctx);
        goto after_12;
    // 0x80178234: nop

    after_12:
    // 0x80178238: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017823C: addiu       $t7, $t7, -0x2E18
    ctx->r15 = ADD32(ctx->r15, -0X2E18);
    // 0x80178240: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80178244: andi        $t0, $t8, 0x10
    ctx->r8 = ctx->r24 & 0X10;
    // 0x80178248: beq         $t0, $zero, L_80178278
    if (ctx->r8 == 0) {
        // 0x8017824C: nop
    
            goto L_80178278;
    }
    // 0x8017824C: nop

    // 0x80178250: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    // 0x80178254: jal         0x800C7A74
    // 0x80178258: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    func_800C7A74(rdram, ctx);
        goto after_13;
    // 0x80178258: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    after_13:
    // 0x8017825C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80178260: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80178264: addiu       $a1, $a1, -0xCF4
    ctx->r5 = ADD32(ctx->r5, -0XCF4);
    // 0x80178268: jal         0x800D87E4
    // 0x8017826C: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_14;
    // 0x8017826C: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_14:
    // 0x80178270: b           L_80178298
    // 0x80178274: nop

        goto L_80178298;
    // 0x80178274: nop

L_80178278:
    // 0x80178278: addiu       $a0, $zero, 0xDE
    ctx->r4 = ADD32(0, 0XDE);
    // 0x8017827C: jal         0x800C7A74
    // 0x80178280: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    func_800C7A74(rdram, ctx);
        goto after_15;
    // 0x80178280: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    after_15:
    // 0x80178284: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80178288: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x8017828C: addiu       $a1, $a1, -0xCDC
    ctx->r5 = ADD32(ctx->r5, -0XCDC);
    // 0x80178290: jal         0x800D87E4
    // 0x80178294: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_16;
    // 0x80178294: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_16:
L_80178298:
    // 0x80178298: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017829C: addiu       $t1, $t1, -0x2E18
    ctx->r9 = ADD32(ctx->r9, -0X2E18);
    // 0x801782A0: lw          $t9, 0x4($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X4);
    // 0x801782A4: lui         $a3, 0x801A
    ctx->r7 = S32(0X801A << 16);
    // 0x801782A8: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x801782AC: andi        $t2, $t9, 0xF
    ctx->r10 = ctx->r25 & 0XF;
    // 0x801782B0: addu        $a3, $a3, $t2
    ctx->r7 = ADD32(ctx->r7, ctx->r10);
    // 0x801782B4: lbu         $a3, -0x2520($a3)
    ctx->r7 = MEM_BU(ctx->r7, -0X2520);
    // 0x801782B8: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    // 0x801782BC: jal         0x800C7A9C
    // 0x801782C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800C7A9C(rdram, ctx);
        goto after_17;
    // 0x801782C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_17:
    // 0x801782C4: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x801782C8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x801782CC: addiu       $a1, $a1, 0x3B40
    ctx->r5 = ADD32(ctx->r5, 0X3B40);
    // 0x801782D0: jal         0x800C767C
    // 0x801782D4: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    func_800C767C(rdram, ctx);
        goto after_18;
    // 0x801782D4: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    after_18:
    // 0x801782D8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x801782DC: addiu       $t3, $t3, -0x41E0
    ctx->r11 = ADD32(ctx->r11, -0X41E0);
    // 0x801782E0: lhu         $t4, 0xC($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0XC);
    // 0x801782E4: andi        $t5, $t4, 0xB000
    ctx->r13 = ctx->r12 & 0XB000;
    // 0x801782E8: bne         $t5, $zero, L_80178300
    if (ctx->r13 != 0) {
        // 0x801782EC: nop
    
            goto L_80178300;
    }
    // 0x801782EC: nop

    // 0x801782F0: lhu         $t6, 0x20($t3)
    ctx->r14 = MEM_HU(ctx->r11, 0X20);
    // 0x801782F4: andi        $t7, $t6, 0xB000
    ctx->r15 = ctx->r14 & 0XB000;
    // 0x801782F8: beq         $t7, $zero, L_80178308
    if (ctx->r15 == 0) {
        // 0x801782FC: nop
    
            goto L_80178308;
    }
    // 0x801782FC: nop

L_80178300:
    // 0x80178300: jal         0x80178318
    // 0x80178304: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80178318_1501A0(rdram, ctx);
        goto after_19;
    // 0x80178304: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_19:
L_80178308:
    // 0x80178308: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017830C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80178310: jr          $ra
    // 0x80178314: nop

    return;
    // 0x80178314: nop

;}
RECOMP_FUNC void func_80178318_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80178318: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017831C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80178320: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80178324: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80178328: bne         $t6, $zero, L_80178398
    if (ctx->r14 != 0) {
        // 0x8017832C: nop
    
            goto L_80178398;
    }
    // 0x8017832C: nop

    // 0x80178330: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80178334: addiu       $t7, $t7, -0x2E28
    ctx->r15 = ADD32(ctx->r15, -0X2E28);
    // 0x80178338: lbu         $t8, 0xC($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0XC);
    // 0x8017833C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80178340: addiu       $t1, $t1, -0x2BA8
    ctx->r9 = ADD32(ctx->r9, -0X2BA8);
    // 0x80178344: andi        $t9, $t8, 0xDF
    ctx->r25 = ctx->r24 & 0XDF;
    // 0x80178348: sb          $t9, 0xC($t7)
    MEM_B(0XC, ctx->r15) = ctx->r25;
    // 0x8017834C: addiu       $t0, $zero, 0x32
    ctx->r8 = ADD32(0, 0X32);
    // 0x80178350: sw          $t0, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r8;
    // 0x80178354: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80178358: jal         0x80193424
    // 0x8017835C: addiu       $a1, $zero, 0x3E8
    ctx->r5 = ADD32(0, 0X3E8);
    func_80193424_1501A0(rdram, ctx);
        goto after_0;
    // 0x8017835C: addiu       $a1, $zero, 0x3E8
    ctx->r5 = ADD32(0, 0X3E8);
    after_0:
    // 0x80178360: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80178364: addiu       $t2, $t2, -0x2E28
    ctx->r10 = ADD32(ctx->r10, -0X2E28);
    // 0x80178368: lbu         $t3, 0xA($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0XA);
    // 0x8017836C: lui         $t5, 0x66
    ctx->r13 = S32(0X66 << 16);
    // 0x80178370: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80178374: ori         $t4, $t3, 0x2
    ctx->r12 = ctx->r11 | 0X2;
    // 0x80178378: sb          $t4, 0xA($t2)
    MEM_B(0XA, ctx->r10) = ctx->r12;
    // 0x8017837C: addiu       $t6, $t6, -0x2E18
    ctx->r14 = ADD32(ctx->r14, -0X2E18);
    // 0x80178380: ori         $t5, $t5, 0x5
    ctx->r13 = ctx->r13 | 0X5;
    // 0x80178384: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80178388: addiu       $t8, $t8, -0x2E18
    ctx->r24 = ADD32(ctx->r24, -0X2E18);
    // 0x8017838C: sw          $t5, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r13;
    // 0x80178390: b           L_801783FC
    // 0x80178394: sw          $zero, 0xC($t8)
    MEM_W(0XC, ctx->r24) = 0;
        goto L_801783FC;
    // 0x80178394: sw          $zero, 0xC($t8)
    MEM_W(0XC, ctx->r24) = 0;
L_80178398:
    // 0x80178398: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017839C: addiu       $t9, $t9, -0x2E28
    ctx->r25 = ADD32(ctx->r25, -0X2E28);
    // 0x801783A0: lbu         $t7, 0xC($t9)
    ctx->r15 = MEM_BU(ctx->r25, 0XC);
    // 0x801783A4: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x801783A8: addiu       $t3, $t3, -0x2BA8
    ctx->r11 = ADD32(ctx->r11, -0X2BA8);
    // 0x801783AC: andi        $t0, $t7, 0xBF
    ctx->r8 = ctx->r15 & 0XBF;
    // 0x801783B0: sb          $t0, 0xC($t9)
    MEM_B(0XC, ctx->r25) = ctx->r8;
    // 0x801783B4: addiu       $t1, $zero, 0x32
    ctx->r9 = ADD32(0, 0X32);
    // 0x801783B8: sw          $t1, 0x10($t3)
    MEM_W(0X10, ctx->r11) = ctx->r9;
    // 0x801783BC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801783C0: jal         0x80193424
    // 0x801783C4: addiu       $a1, $zero, 0x3E8
    ctx->r5 = ADD32(0, 0X3E8);
    func_80193424_1501A0(rdram, ctx);
        goto after_1;
    // 0x801783C4: addiu       $a1, $zero, 0x3E8
    ctx->r5 = ADD32(0, 0X3E8);
    after_1:
    // 0x801783C8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x801783CC: addiu       $t4, $t4, -0x2E28
    ctx->r12 = ADD32(ctx->r12, -0X2E28);
    // 0x801783D0: lbu         $t2, 0xA($t4)
    ctx->r10 = MEM_BU(ctx->r12, 0XA);
    // 0x801783D4: lui         $t6, 0x65
    ctx->r14 = S32(0X65 << 16);
    // 0x801783D8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x801783DC: ori         $t5, $t2, 0x2
    ctx->r13 = ctx->r10 | 0X2;
    // 0x801783E0: sb          $t5, 0xA($t4)
    MEM_B(0XA, ctx->r12) = ctx->r13;
    // 0x801783E4: addiu       $t8, $t8, -0x2E18
    ctx->r24 = ADD32(ctx->r24, -0X2E18);
    // 0x801783E8: ori         $t6, $t6, 0x5
    ctx->r14 = ctx->r14 | 0X5;
    // 0x801783EC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801783F0: addiu       $t7, $t7, -0x2E18
    ctx->r15 = ADD32(ctx->r15, -0X2E18);
    // 0x801783F4: sw          $t6, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r14;
    // 0x801783F8: sw          $zero, 0xC($t7)
    MEM_W(0XC, ctx->r15) = 0;
L_801783FC:
    // 0x801783FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80178400: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80178404: jr          $ra
    // 0x80178408: nop

    return;
    // 0x80178408: nop

;}
RECOMP_FUNC void func_8017840C_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017840C: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80178410: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80178414: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80178418: swc1        $f12, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f12.u32l;
    // 0x8017841C: addiu       $t6, $t6, -0x2BA8
    ctx->r14 = ADD32(ctx->r14, -0X2BA8);
    // 0x80178420: lwc1        $f4, 0x138($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X138);
    // 0x80178424: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80178428: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017842C: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x80178430: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80178434: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x80178438: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017843C: swc1        $f4, 0x50($t7)
    MEM_W(0X50, ctx->r15) = ctx->f4.u32l;
    // 0x80178440: addiu       $t9, $t9, -0x2BA8
    ctx->r25 = ADD32(ctx->r25, -0X2BA8);
    // 0x80178444: swc1        $f6, 0x54($t8)
    MEM_W(0X54, ctx->r24) = ctx->f6.u32l;
    // 0x80178448: lwc1        $f8, 0x140($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X140);
    // 0x8017844C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80178450: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x80178454: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80178458: jal         0x800D6D20
    // 0x8017845C: swc1        $f8, 0x58($t0)
    MEM_W(0X58, ctx->r8) = ctx->f8.u32l;
    guMtxIdentF_recomp(rdram, ctx);
        goto after_0;
    // 0x8017845C: swc1        $f8, 0x58($t0)
    MEM_W(0X58, ctx->r8) = ctx->f8.u32l;
    after_0:
    // 0x80178460: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80178464: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x80178468: lwc1        $f10, 0x50($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X50);
    // 0x8017846C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80178470: nop

    // 0x80178474: c.eq.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl == ctx->f16.fl;
    // 0x80178478: nop

    // 0x8017847C: bc1f        L_801784BC
    if (!c1cs) {
        // 0x80178480: nop
    
            goto L_801784BC;
    }
    // 0x80178480: nop

    // 0x80178484: lwc1        $f18, 0x54($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X54);
    // 0x80178488: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017848C: nop

    // 0x80178490: c.eq.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl == ctx->f4.fl;
    // 0x80178494: nop

    // 0x80178498: bc1f        L_801784BC
    if (!c1cs) {
        // 0x8017849C: nop
    
            goto L_801784BC;
    }
    // 0x8017849C: nop

    // 0x801784A0: lwc1        $f6, 0x58($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X58);
    // 0x801784A4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801784A8: nop

    // 0x801784AC: c.eq.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl == ctx->f8.fl;
    // 0x801784B0: nop

    // 0x801784B4: bc1t        L_80178748
    if (c1cs) {
        // 0x801784B8: nop
    
            goto L_80178748;
    }
    // 0x801784B8: nop

L_801784BC:
    // 0x801784BC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x801784C0: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x801784C4: lwc1        $f10, 0x50($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X50);
    // 0x801784C8: lwc1        $f18, 0x54($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X54);
    // 0x801784CC: lwc1        $f8, 0x58($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X58);
    // 0x801784D0: mul.s       $f16, $f10, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x801784D4: nop

    // 0x801784D8: mul.s       $f4, $f18, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x801784DC: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x801784E0: mul.s       $f10, $f8, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x801784E4: jal         0x800D68E0
    // 0x801784E8: add.s       $f12, $f10, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x801784E8: add.s       $f12, $f10, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f6.fl;
    after_1:
    // 0x801784EC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801784F0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801784F4: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x801784F8: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x801784FC: div.s       $f16, $f18, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80178500: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80178504: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x80178508: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017850C: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x80178510: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80178514: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x80178518: addiu       $t7, $t6, 0x5C
    ctx->r15 = ADD32(ctx->r14, 0X5C);
    // 0x8017851C: addiu       $t8, $t6, 0x60
    ctx->r24 = ADD32(ctx->r14, 0X60);
    // 0x80178520: addiu       $t9, $t6, 0x64
    ctx->r25 = ADD32(ctx->r14, 0X64);
    // 0x80178524: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80178528: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8017852C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80178530: swc1        $f16, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f16.u32l;
    // 0x80178534: lwc1        $f4, 0x50($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X50);
    // 0x80178538: mul.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x8017853C: swc1        $f8, 0x50($t3)
    MEM_W(0X50, ctx->r11) = ctx->f8.u32l;
    // 0x80178540: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80178544: lwc1        $f10, 0x54($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X54);
    // 0x80178548: mul.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x8017854C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80178550: swc1        $f18, 0x54($t4)
    MEM_W(0X54, ctx->r12) = ctx->f18.u32l;
    // 0x80178554: lwc1        $f4, 0x58($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X58);
    // 0x80178558: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8017855C: mul.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x80178560: swc1        $f8, 0x58($t5)
    MEM_W(0X58, ctx->r13) = ctx->f8.u32l;
    // 0x80178564: lw          $a3, 0x50($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X50);
    // 0x80178568: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8017856C: lwc1        $f6, 0x58($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X58);
    // 0x80178570: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x80178574: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x80178578: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x8017857C: jal         0x800C46D4
    // 0x80178580: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_800C46D4(rdram, ctx);
        goto after_2;
    // 0x80178580: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x80178584: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80178588: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x8017858C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80178590: swc1        $f0, 0x80($t0)
    MEM_W(0X80, ctx->r8) = ctx->f0.u32l;
    // 0x80178594: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x80178598: lwc1        $f18, 0x5C($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X5C);
    // 0x8017859C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801785A0: nop

    // 0x801785A4: c.eq.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl == ctx->f4.fl;
    // 0x801785A8: nop

    // 0x801785AC: bc1f        L_801785EC
    if (!c1cs) {
        // 0x801785B0: nop
    
            goto L_801785EC;
    }
    // 0x801785B0: nop

    // 0x801785B4: lwc1        $f16, 0x60($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X60);
    // 0x801785B8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801785BC: nop

    // 0x801785C0: c.eq.s      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.fl == ctx->f8.fl;
    // 0x801785C4: nop

    // 0x801785C8: bc1f        L_801785EC
    if (!c1cs) {
        // 0x801785CC: nop
    
            goto L_801785EC;
    }
    // 0x801785CC: nop

    // 0x801785D0: lwc1        $f10, 0x64($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X64);
    // 0x801785D4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801785D8: nop

    // 0x801785DC: c.eq.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl == ctx->f6.fl;
    // 0x801785E0: nop

    // 0x801785E4: bc1t        L_80178618
    if (c1cs) {
        // 0x801785E8: nop
    
            goto L_80178618;
    }
    // 0x801785E8: nop

L_801785EC:
    // 0x801785EC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x801785F0: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x801785F4: lwc1        $f18, 0x64($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X64);
    // 0x801785F8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x801785FC: addiu       $a0, $a0, -0x2BA8
    ctx->r4 = ADD32(ctx->r4, -0X2BA8);
    // 0x80178600: lw          $a1, 0x80($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X80);
    // 0x80178604: lw          $a2, 0x5C($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X5C);
    // 0x80178608: lw          $a3, 0x60($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X60);
    // 0x8017860C: addiu       $a0, $a0, 0xA0
    ctx->r4 = ADD32(ctx->r4, 0XA0);
    // 0x80178610: jal         0x800D7120
    // 0x80178614: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    guAlignF_recomp(rdram, ctx);
        goto after_3;
    // 0x80178614: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_3:
L_80178618:
    // 0x80178618: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017861C: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x80178620: lwc1        $f4, 0x50($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X50);
    // 0x80178624: lwc1        $f16, 0x58($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X58);
    // 0x80178628: lwc1        $f8, 0x54($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X54);
    // 0x8017862C: addiu       $t4, $t3, 0x68
    ctx->r12 = ADD32(ctx->r11, 0X68);
    // 0x80178630: addiu       $t5, $t3, 0x6C
    ctx->r13 = ADD32(ctx->r11, 0X6C);
    // 0x80178634: addiu       $t7, $t3, 0x70
    ctx->r15 = ADD32(ctx->r11, 0X70);
    // 0x80178638: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8017863C: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x80178640: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80178644: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x80178648: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x8017864C: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x80178650: mov.s       $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = ctx->f4.fl;
    // 0x80178654: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x80178658: jal         0x800C46D4
    // 0x8017865C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800C46D4(rdram, ctx);
        goto after_4;
    // 0x8017865C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_4:
    // 0x80178660: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80178664: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x80178668: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017866C: swc1        $f0, 0x84($t8)
    MEM_W(0X84, ctx->r24) = ctx->f0.u32l;
    // 0x80178670: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x80178674: lwc1        $f10, 0x68($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X68);
    // 0x80178678: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8017867C: nop

    // 0x80178680: c.eq.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl == ctx->f6.fl;
    // 0x80178684: nop

    // 0x80178688: bc1f        L_801786C8
    if (!c1cs) {
        // 0x8017868C: nop
    
            goto L_801786C8;
    }
    // 0x8017868C: nop

    // 0x80178690: lwc1        $f18, 0x6C($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X6C);
    // 0x80178694: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80178698: nop

    // 0x8017869C: c.eq.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl == ctx->f4.fl;
    // 0x801786A0: nop

    // 0x801786A4: bc1f        L_801786C8
    if (!c1cs) {
        // 0x801786A8: nop
    
            goto L_801786C8;
    }
    // 0x801786A8: nop

    // 0x801786AC: lwc1        $f8, 0x70($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X70);
    // 0x801786B0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801786B4: nop

    // 0x801786B8: c.eq.s      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.fl == ctx->f16.fl;
    // 0x801786BC: nop

    // 0x801786C0: bc1t        L_801786EC
    if (c1cs) {
        // 0x801786C4: nop
    
            goto L_801786EC;
    }
    // 0x801786C4: nop

L_801786C8:
    // 0x801786C8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801786CC: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x801786D0: lwc1        $f10, 0x70($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X70);
    // 0x801786D4: lw          $a1, 0x84($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X84);
    // 0x801786D8: lw          $a2, 0x68($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X68);
    // 0x801786DC: lw          $a3, 0x6C($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X6C);
    // 0x801786E0: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x801786E4: jal         0x800D7120
    // 0x801786E8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    guAlignF_recomp(rdram, ctx);
        goto after_5;
    // 0x801786E8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_5:
L_801786EC:
    // 0x801786EC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x801786F0: addiu       $t0, $t0, -0x2BA8
    ctx->r8 = ADD32(ctx->r8, -0X2BA8);
    // 0x801786F4: addiu       $t1, $t0, 0xA0
    ctx->r9 = ADD32(ctx->r8, 0XA0);
    // 0x801786F8: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x801786FC: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    // 0x80178700: jal         0x800D6F30
    // 0x80178704: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    guMtxCatF_recomp(rdram, ctx);
        goto after_6;
    // 0x80178704: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_6:
    // 0x80178708: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017870C: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x80178710: lwc1        $f6, 0x58($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X58);
    // 0x80178714: lw          $a2, 0x50($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X50);
    // 0x80178718: lw          $a3, 0x54($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X54);
    // 0x8017871C: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80178720: lw          $a1, 0x78($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X78);
    // 0x80178724: jal         0x800D7120
    // 0x80178728: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    guAlignF_recomp(rdram, ctx);
        goto after_7;
    // 0x80178728: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_7:
    // 0x8017872C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80178730: addiu       $t4, $t4, -0x2BA8
    ctx->r12 = ADD32(ctx->r12, -0X2BA8);
    // 0x80178734: addiu       $t5, $t4, 0xA0
    ctx->r13 = ADD32(ctx->r12, 0XA0);
    // 0x80178738: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x8017873C: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
    // 0x80178740: jal         0x800D6F30
    // 0x80178744: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    guMtxCatF_recomp(rdram, ctx);
        goto after_8;
    // 0x80178744: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_8:
L_80178748:
    // 0x80178748: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8017874C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x80178750: jr          $ra
    // 0x80178754: nop

    return;
    // 0x80178754: nop

;}
RECOMP_FUNC void func_80178758_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80178758: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8017875C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80178760: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80178764: swc1        $f12, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f12.u32l;
    // 0x80178768: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x8017876C: jal         0x800E4CDC
    // 0x80178770: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    func_800E4CDC(rdram, ctx);
        goto after_0;
    // 0x80178770: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    after_0:
    // 0x80178774: addiu       $at, $zero, 0xFFF
    ctx->r1 = ADD32(0, 0XFFF);
    // 0x80178778: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x8017877C: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80178780: mflo        $t7
    ctx->r15 = lo;
    // 0x80178784: andi        $t8, $t7, 0x7
    ctx->r24 = ctx->r15 & 0X7;
    // 0x80178788: beq         $t9, $zero, L_80178B74
    if (ctx->r25 == 0) {
        // 0x8017878C: sw          $t8, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r24;
            goto L_80178B74;
    }
    // 0x8017878C: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
L_80178790:
    // 0x80178790: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80178794: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80178798: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8017879C: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x801787A0: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x801787A4: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x801787A8: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x801787AC: lwc1        $f4, -0x2510($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2510);
    // 0x801787B0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x801787B4: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x801787B8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801787BC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801787C0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801787C4: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x801787C8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x801787CC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x801787D0: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x801787D4: swc1        $f8, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f8.u32l;
    // 0x801787D8: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x801787DC: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x801787E0: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x801787E4: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x801787E8: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x801787EC: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x801787F0: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x801787F4: lwc1        $f10, -0x250C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X250C);
    // 0x801787F8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801787FC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80178800: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80178804: addiu       $a0, $a0, -0x2BA8
    ctx->r4 = ADD32(ctx->r4, -0X2BA8);
    // 0x80178808: addiu       $t5, $t2, 0xD0
    ctx->r13 = ADD32(ctx->r10, 0XD0);
    // 0x8017880C: addiu       $t4, $t2, 0xCC
    ctx->r12 = ADD32(ctx->r10, 0XCC);
    // 0x80178810: addiu       $t3, $t2, 0xC8
    ctx->r11 = ADD32(ctx->r10, 0XC8);
    // 0x80178814: addiu       $a0, $a0, 0xA0
    ctx->r4 = ADD32(ctx->r4, 0XA0);
    // 0x80178818: swc1        $f18, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->f18.u32l;
    // 0x8017881C: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x80178820: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80178824: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80178828: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8017882C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80178830: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80178834: lwc1        $f4, -0x2508($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2508);
    // 0x80178838: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8017883C: swc1        $f8, 0x14($t1)
    MEM_W(0X14, ctx->r9) = ctx->f8.u32l;
    // 0x80178840: lw          $a3, 0x14($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X14);
    // 0x80178844: lw          $a2, 0x10($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X10);
    // 0x80178848: lw          $a1, 0xC($t2)
    ctx->r5 = MEM_W(ctx->r10, 0XC);
    // 0x8017884C: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x80178850: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80178854: jal         0x800D6E90
    // 0x80178858: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    guMtxXFMF_recomp(rdram, ctx);
        goto after_1;
    // 0x80178858: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_1:
    // 0x8017885C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80178860: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x80178864: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80178868: lwc1        $f16, -0x2B24($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2B24);
    // 0x8017886C: lwc1        $f10, 0xC8($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0XC8);
    // 0x80178870: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80178874: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x80178878: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8017887C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80178880: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80178884: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x80178888: swc1        $f18, 0xC8($t6)
    MEM_W(0XC8, ctx->r14) = ctx->f18.u32l;
    // 0x8017888C: lwc1        $f4, 0xCC($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0XCC);
    // 0x80178890: lwc1        $f6, -0x2B20($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2B20);
    // 0x80178894: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80178898: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8017889C: swc1        $f8, 0xCC($t7)
    MEM_W(0XCC, ctx->r15) = ctx->f8.u32l;
    // 0x801788A0: lwc1        $f10, 0xD0($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0XD0);
    // 0x801788A4: lwc1        $f16, -0x2B1C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2B1C);
    // 0x801788A8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801788AC: jal         0x80199214
    // 0x801788B0: swc1        $f18, 0xD0($t8)
    MEM_W(0XD0, ctx->r24) = ctx->f18.u32l;
    func_80199214_1501A0(rdram, ctx);
        goto after_2;
    // 0x801788B0: swc1        $f18, 0xD0($t8)
    MEM_W(0XD0, ctx->r24) = ctx->f18.u32l;
    after_2:
    // 0x801788B4: beq         $v0, $zero, L_80178918
    if (ctx->r2 == 0) {
        // 0x801788B8: nop
    
            goto L_80178918;
    }
    // 0x801788B8: nop

    // 0x801788BC: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x801788C0: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x801788C4: addiu       $t1, $t1, -0x2BA8
    ctx->r9 = ADD32(ctx->r9, -0X2BA8);
    // 0x801788C8: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x801788CC: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x801788D0: lw          $t3, 0x104($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X104);
    // 0x801788D4: bne         $t3, $t0, L_801788E4
    if (ctx->r11 != ctx->r8) {
        // 0x801788D8: nop
    
            goto L_801788E4;
    }
    // 0x801788D8: nop

    // 0x801788DC: addiu       $t4, $t0, 0x1
    ctx->r12 = ADD32(ctx->r8, 0X1);
    // 0x801788E0: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
L_801788E4:
    // 0x801788E4: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x801788E8: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x801788EC: andi        $t5, $t2, 0x7
    ctx->r13 = ctx->r10 & 0X7;
    // 0x801788F0: bne         $t5, $at, L_80178B68
    if (ctx->r13 != ctx->r1) {
        // 0x801788F4: sw          $t5, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r13;
            goto L_80178B68;
    }
    // 0x801788F4: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
    // 0x801788F8: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x801788FC: beq         $t6, $zero, L_8017890C
    if (ctx->r14 == 0) {
        // 0x80178900: nop
    
            goto L_8017890C;
    }
    // 0x80178900: nop

    // 0x80178904: b           L_80178B68
    // 0x80178908: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
        goto L_80178B68;
    // 0x80178908: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
L_8017890C:
    // 0x8017890C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80178910: b           L_80178B68
    // 0x80178914: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
        goto L_80178B68;
    // 0x80178914: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
L_80178918:
    // 0x80178918: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017891C: addiu       $t8, $t8, -0x2BA8
    ctx->r24 = ADD32(ctx->r24, -0X2BA8);
    // 0x80178920: lw          $t9, 0x104($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X104);
    // 0x80178924: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80178928: bne         $t9, $t1, L_80178968
    if (ctx->r25 != ctx->r9) {
        // 0x8017892C: nop
    
            goto L_80178968;
    }
    // 0x8017892C: nop

    // 0x80178930: addiu       $t3, $t1, 0x1
    ctx->r11 = ADD32(ctx->r9, 0X1);
    // 0x80178934: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    // 0x80178938: andi        $t0, $t3, 0x7
    ctx->r8 = ctx->r11 & 0X7;
    // 0x8017893C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80178940: bne         $t0, $at, L_80178B68
    if (ctx->r8 != ctx->r1) {
        // 0x80178944: sw          $t0, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r8;
            goto L_80178B68;
    }
    // 0x80178944: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x80178948: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x8017894C: beq         $t4, $zero, L_8017895C
    if (ctx->r12 == 0) {
        // 0x80178950: nop
    
            goto L_8017895C;
    }
    // 0x80178950: nop

    // 0x80178954: b           L_80178B68
    // 0x80178958: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
        goto L_80178B68;
    // 0x80178958: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
L_8017895C:
    // 0x8017895C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80178960: b           L_80178B68
    // 0x80178964: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
        goto L_80178B68;
    // 0x80178964: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
L_80178968:
    // 0x80178968: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x8017896C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80178970: addiu       $t6, $t6, -0x2BA8
    ctx->r14 = ADD32(ctx->r14, -0X2BA8);
    // 0x80178974: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80178978: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x8017897C: sw          $t5, 0x104($t6)
    MEM_W(0X104, ctx->r14) = ctx->r13;
    // 0x80178980: lwc1        $f4, 0xC8($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0XC8);
    // 0x80178984: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80178988: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x8017898C: swc1        $f4, 0x28($t7)
    MEM_W(0X28, ctx->r15) = ctx->f4.u32l;
    // 0x80178990: lwc1        $f6, 0xCC($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0XCC);
    // 0x80178994: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80178998: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x8017899C: swc1        $f6, 0x2C($t8)
    MEM_W(0X2C, ctx->r24) = ctx->f6.u32l;
    // 0x801789A0: lwc1        $f8, 0xD0($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0XD0);
    // 0x801789A4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801789A8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x801789AC: swc1        $f8, 0x30($t9)
    MEM_W(0X30, ctx->r25) = ctx->f8.u32l;
    // 0x801789B0: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x801789B4: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x801789B8: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x801789BC: sll         $t3, $t1, 2
    ctx->r11 = S32(ctx->r9 << 2);
    // 0x801789C0: subu        $t3, $t3, $t1
    ctx->r11 = SUB32(ctx->r11, ctx->r9);
    // 0x801789C4: sll         $t0, $t3, 2
    ctx->r8 = S32(ctx->r11 << 2);
    // 0x801789C8: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x801789CC: lwc1        $f10, -0x2510($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2510);
    // 0x801789D0: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x801789D4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801789D8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801789DC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801789E0: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x801789E4: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x801789E8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x801789EC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x801789F0: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x801789F4: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x801789F8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x801789FC: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80178A00: addiu       $a0, $a0, -0x2BA8
    ctx->r4 = ADD32(ctx->r4, -0X2BA8);
    // 0x80178A04: addiu       $a0, $a0, 0xA0
    ctx->r4 = ADD32(ctx->r4, 0XA0);
    // 0x80178A08: swc1        $f6, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->f6.u32l;
    // 0x80178A0C: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x80178A10: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80178A14: addiu       $t4, $t0, 0xC8
    ctx->r12 = ADD32(ctx->r8, 0XC8);
    // 0x80178A18: sll         $t5, $t2, 2
    ctx->r13 = S32(ctx->r10 << 2);
    // 0x80178A1C: subu        $t5, $t5, $t2
    ctx->r13 = SUB32(ctx->r13, ctx->r10);
    // 0x80178A20: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80178A24: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80178A28: lwc1        $f8, -0x250C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X250C);
    // 0x80178A2C: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80178A30: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80178A34: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80178A38: addiu       $t5, $t0, 0xD0
    ctx->r13 = ADD32(ctx->r8, 0XD0);
    // 0x80178A3C: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80178A40: addiu       $t2, $t0, 0xCC
    ctx->r10 = ADD32(ctx->r8, 0XCC);
    // 0x80178A44: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80178A48: swc1        $f4, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->f4.u32l;
    // 0x80178A4C: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x80178A50: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80178A54: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80178A58: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80178A5C: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x80178A60: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80178A64: lwc1        $f6, -0x2508($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2508);
    // 0x80178A68: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80178A6C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80178A70: nop

    // 0x80178A74: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80178A78: nop

    // 0x80178A7C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80178A80: swc1        $f18, 0x14($t3)
    MEM_W(0X14, ctx->r11) = ctx->f18.u32l;
    // 0x80178A84: lw          $a3, 0x14($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X14);
    // 0x80178A88: lw          $a2, 0x10($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X10);
    // 0x80178A8C: lw          $a1, 0xC($t0)
    ctx->r5 = MEM_W(ctx->r8, 0XC);
    // 0x80178A90: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x80178A94: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80178A98: jal         0x800D6E90
    // 0x80178A9C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    guMtxXFMF_recomp(rdram, ctx);
        goto after_3;
    // 0x80178A9C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_3:
    // 0x80178AA0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80178AA4: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x80178AA8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80178AAC: lwc1        $f6, -0x2B24($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2B24);
    // 0x80178AB0: lwc1        $f4, 0xC8($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0XC8);
    // 0x80178AB4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80178AB8: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x80178ABC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80178AC0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80178AC4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80178AC8: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x80178ACC: swc1        $f8, 0xC8($t6)
    MEM_W(0XC8, ctx->r14) = ctx->f8.u32l;
    // 0x80178AD0: lwc1        $f10, 0xCC($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0XCC);
    // 0x80178AD4: lwc1        $f16, -0x2B20($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2B20);
    // 0x80178AD8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80178ADC: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80178AE0: swc1        $f18, 0xCC($t7)
    MEM_W(0XCC, ctx->r15) = ctx->f18.u32l;
    // 0x80178AE4: lwc1        $f4, 0xD0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0XD0);
    // 0x80178AE8: lwc1        $f6, -0x2B1C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2B1C);
    // 0x80178AEC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80178AF0: jal         0x80199214
    // 0x80178AF4: swc1        $f8, 0xD0($t8)
    MEM_W(0XD0, ctx->r24) = ctx->f8.u32l;
    func_80199214_1501A0(rdram, ctx);
        goto after_4;
    // 0x80178AF4: swc1        $f8, 0xD0($t8)
    MEM_W(0XD0, ctx->r24) = ctx->f8.u32l;
    after_4:
    // 0x80178AF8: beq         $v0, $zero, L_80178B34
    if (ctx->r2 == 0) {
        // 0x80178AFC: nop
    
            goto L_80178B34;
    }
    // 0x80178AFC: nop

    // 0x80178B00: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80178B04: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x80178B08: lwc1        $f10, 0x28($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X28);
    // 0x80178B0C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80178B10: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x80178B14: swc1        $f10, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f10.u32l;
    // 0x80178B18: lwc1        $f16, 0x2C($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X2C);
    // 0x80178B1C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80178B20: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x80178B24: swc1        $f16, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->f16.u32l;
    // 0x80178B28: lwc1        $f18, 0x30($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X30);
    // 0x80178B2C: b           L_80178B64
    // 0x80178B30: swc1        $f18, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f18.u32l;
        goto L_80178B64;
    // 0x80178B30: swc1        $f18, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f18.u32l;
L_80178B34:
    // 0x80178B34: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80178B38: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x80178B3C: lwc1        $f4, 0xC8($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0XC8);
    // 0x80178B40: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80178B44: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x80178B48: swc1        $f4, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f4.u32l;
    // 0x80178B4C: lwc1        $f6, 0xCC($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0XCC);
    // 0x80178B50: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80178B54: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x80178B58: swc1        $f6, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->f6.u32l;
    // 0x80178B5C: lwc1        $f8, 0xD0($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0XD0);
    // 0x80178B60: swc1        $f8, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f8.u32l;
L_80178B64:
    // 0x80178B64: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
L_80178B68:
    // 0x80178B68: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x80178B6C: bne         $t5, $zero, L_80178790
    if (ctx->r13 != 0) {
        // 0x80178B70: nop
    
            goto L_80178790;
    }
    // 0x80178B70: nop

L_80178B74:
    // 0x80178B74: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80178B78: beq         $t6, $zero, L_80178C10
    if (ctx->r14 == 0) {
        // 0x80178B7C: nop
    
            goto L_80178C10;
    }
    // 0x80178B7C: nop

    // 0x80178B80: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80178B84: addiu       $t7, $t7, -0x2510
    ctx->r15 = ADD32(ctx->r15, -0X2510);
    // 0x80178B88: lwc1        $f10, 0x60($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X60);
    // 0x80178B8C: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80178B90: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80178B94: addiu       $t8, $t8, -0x4198
    ctx->r24 = ADD32(ctx->r24, -0X4198);
    // 0x80178B98: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80178B9C: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    // 0x80178BA0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80178BA4: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x80178BA8: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80178BAC: addiu       $t1, $t1, -0x2510
    ctx->r9 = ADD32(ctx->r9, -0X2510);
    // 0x80178BB0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80178BB4: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80178BB8: addiu       $t3, $t3, -0x4198
    ctx->r11 = ADD32(ctx->r11, -0X4198);
    // 0x80178BBC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80178BC0: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x80178BC4: swc1        $f6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f6.u32l;
    // 0x80178BC8: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80178BCC: lwc1        $f8, 0x64($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X64);
    // 0x80178BD0: lwc1        $f18, 0x4($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X4);
    // 0x80178BD4: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80178BD8: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80178BDC: addiu       $t2, $t2, -0x2510
    ctx->r10 = ADD32(ctx->r10, -0X2510);
    // 0x80178BE0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80178BE4: addiu       $t0, $t0, -0x4198
    ctx->r8 = ADD32(ctx->r8, -0X4198);
    // 0x80178BE8: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80178BEC: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x80178BF0: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80178BF4: swc1        $f4, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->f4.u32l;
    // 0x80178BF8: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80178BFC: lwc1        $f6, 0x68($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X68);
    // 0x80178C00: lwc1        $f16, 0x8($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X8);
    // 0x80178C04: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80178C08: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80178C0C: swc1        $f18, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->f18.u32l;
L_80178C10:
    // 0x80178C10: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80178C14: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x80178C18: lwc1        $f4, 0x0($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X0);
    // 0x80178C1C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80178C20: addiu       $t7, $t7, -0x4198
    ctx->r15 = ADD32(ctx->r15, -0X4198);
    // 0x80178C24: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80178C28: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x80178C2C: swc1        $f4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f4.u32l;
    // 0x80178C30: lwc1        $f6, 0x4($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X4);
    // 0x80178C34: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80178C38: addiu       $t9, $t9, -0x4198
    ctx->r25 = ADD32(ctx->r25, -0X4198);
    // 0x80178C3C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80178C40: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x80178C44: swc1        $f6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f6.u32l;
    // 0x80178C48: lwc1        $f8, 0x8($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X8);
    // 0x80178C4C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80178C50: addiu       $t3, $t3, -0x4198
    ctx->r11 = ADD32(ctx->r11, -0X4198);
    // 0x80178C54: swc1        $f8, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f8.u32l;
    // 0x80178C58: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80178C5C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80178C60: jr          $ra
    // 0x80178C64: nop

    return;
    // 0x80178C64: nop

;}
RECOMP_FUNC void func_80178C68_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80178C68: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80178C6C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80178C70: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80178C74: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80178C78: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80178C7C: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80178C80: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80178C84: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80178C88: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80178C8C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80178C90: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x80178C94: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80178C98: lw          $a3, 0x0($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X0);
    // 0x80178C9C: lw          $a2, 0x0($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X0);
    // 0x80178CA0: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    // 0x80178CA4: addiu       $a0, $a0, -0x2BA8
    ctx->r4 = ADD32(ctx->r4, -0X2BA8);
    // 0x80178CA8: addiu       $t0, $t9, 0xC8
    ctx->r8 = ADD32(ctx->r25, 0XC8);
    // 0x80178CAC: addiu       $t1, $t9, 0xCC
    ctx->r9 = ADD32(ctx->r25, 0XCC);
    // 0x80178CB0: addiu       $t2, $t9, 0xD0
    ctx->r10 = ADD32(ctx->r25, 0XD0);
    // 0x80178CB4: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x80178CB8: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80178CBC: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80178CC0: jal         0x800D6E90
    // 0x80178CC4: addiu       $a0, $a0, 0xA0
    ctx->r4 = ADD32(ctx->r4, 0XA0);
    guMtxXFMF_recomp(rdram, ctx);
        goto after_0;
    // 0x80178CC4: addiu       $a0, $a0, 0xA0
    ctx->r4 = ADD32(ctx->r4, 0XA0);
    after_0:
    // 0x80178CC8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80178CCC: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x80178CD0: lwc1        $f4, 0xC8($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0XC8);
    // 0x80178CD4: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80178CD8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80178CDC: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x80178CE0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80178CE4: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80178CE8: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x80178CEC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80178CF0: swc1        $f8, 0xC8($t3)
    MEM_W(0XC8, ctx->r11) = ctx->f8.u32l;
    // 0x80178CF4: lwc1        $f10, 0xCC($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0XCC);
    // 0x80178CF8: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80178CFC: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x80178D00: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80178D04: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80178D08: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x80178D0C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80178D10: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x80178D14: swc1        $f18, 0xCC($t4)
    MEM_W(0XCC, ctx->r12) = ctx->f18.u32l;
    // 0x80178D18: lwc1        $f4, 0xD0($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0XD0);
    // 0x80178D1C: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80178D20: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80178D24: swc1        $f8, 0xD0($t5)
    MEM_W(0XD0, ctx->r13) = ctx->f8.u32l;
    // 0x80178D28: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80178D2C: lwc1        $f10, 0xC8($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0XC8);
    // 0x80178D30: swc1        $f10, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f10.u32l;
    // 0x80178D34: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80178D38: lwc1        $f16, 0xCC($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0XCC);
    // 0x80178D3C: swc1        $f16, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f16.u32l;
    // 0x80178D40: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80178D44: lwc1        $f18, 0xD0($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0XD0);
    // 0x80178D48: jal         0x80199214
    // 0x80178D4C: swc1        $f18, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f18.u32l;
    func_80199214_1501A0(rdram, ctx);
        goto after_1;
    // 0x80178D4C: swc1        $f18, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f18.u32l;
    after_1:
    // 0x80178D50: beq         $v0, $zero, L_80178D78
    if (ctx->r2 == 0) {
        // 0x80178D54: nop
    
            goto L_80178D78;
    }
    // 0x80178D54: nop

    // 0x80178D58: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80178D5C: addiu       $t2, $t2, 0x3B00
    ctx->r10 = ADD32(ctx->r10, 0X3B00);
    // 0x80178D60: lbu         $t3, 0x0($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X0);
    // 0x80178D64: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80178D68: addiu       $t4, $t4, -0x2BA8
    ctx->r12 = ADD32(ctx->r12, -0X2BA8);
    // 0x80178D6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80178D70: b           L_80178D94
    // 0x80178D74: sw          $t3, 0xF8($t4)
    MEM_W(0XF8, ctx->r12) = ctx->r11;
        goto L_80178D94;
    // 0x80178D74: sw          $t3, 0xF8($t4)
    MEM_W(0XF8, ctx->r12) = ctx->r11;
L_80178D78:
    // 0x80178D78: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80178D7C: addiu       $t5, $t5, 0x3B00
    ctx->r13 = ADD32(ctx->r13, 0X3B00);
    // 0x80178D80: lbu         $t6, 0x0($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X0);
    // 0x80178D84: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80178D88: addiu       $t7, $t7, -0x2BA8
    ctx->r15 = ADD32(ctx->r15, -0X2BA8);
    // 0x80178D8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80178D90: sw          $t6, 0xF8($t7)
    MEM_W(0XF8, ctx->r15) = ctx->r14;
L_80178D94:
    // 0x80178D94: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80178D98: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80178D9C: jr          $ra
    // 0x80178DA0: nop

    return;
    // 0x80178DA0: nop

;}
RECOMP_FUNC void func_80178DA4_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80178DA4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80178DA8: lwc1        $f4, -0x2B24($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2B24);
    // 0x80178DAC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80178DB0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80178DB4: lwc1        $f6, -0x2B20($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2B20);
    // 0x80178DB8: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x80178DBC: lwc1        $f18, 0x50($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80178DC0: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    // 0x80178DC4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80178DC8: swc1        $f14, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f14.u32l;
    // 0x80178DCC: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80178DD0: c.lt.s      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.fl < ctx->f18.fl;
    // 0x80178DD4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80178DD8: add.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80178DDC: lwc1        $f8, -0x2B1C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2B1C);
    // 0x80178DE0: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x80178DE4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80178DE8: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x80178DEC: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    // 0x80178DF0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80178DF4: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80178DF8: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    // 0x80178DFC: bc1f        L_80178E0C
    if (!c1cs) {
        // 0x80178E00: swc1        $f8, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
            goto L_80178E0C;
    }
    // 0x80178E00: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x80178E04: b           L_80178E10
    // 0x80178E08: neg.s       $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f20.fl = -ctx->f18.fl;
        goto L_80178E10;
    // 0x80178E08: neg.s       $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f20.fl = -ctx->f18.fl;
L_80178E0C:
    // 0x80178E0C: lwc1        $f20, 0x50($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X50);
L_80178E10:
    // 0x80178E10: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80178E14: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80178E18: lwc1        $f16, 0x54($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80178E1C: add.s       $f4, $f8, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f20.fl;
    // 0x80178E20: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80178E24: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80178E28: add.s       $f6, $f10, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80178E2C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80178E30: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80178E34: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x80178E38: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    // 0x80178E3C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x80178E40: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80178E44: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x80178E48: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80178E4C: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    // 0x80178E50: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x80178E54: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    // 0x80178E58: swc1        $f8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f8.u32l;
    // 0x80178E5C: jal         0x80178C68
    // 0x80178E60: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    func_80178C68_1501A0(rdram, ctx);
        goto after_0;
    // 0x80178E60: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    after_0:
    // 0x80178E64: beq         $v0, $zero, L_80178E78
    if (ctx->r2 == 0) {
        // 0x80178E68: nop
    
            goto L_80178E78;
    }
    // 0x80178E68: nop

    // 0x80178E6C: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80178E70: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x80178E74: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
L_80178E78:
    // 0x80178E78: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80178E7C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80178E80: lui         $at, 0xC040
    ctx->r1 = S32(0XC040 << 16);
    // 0x80178E84: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80178E88: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80178E8C: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80178E90: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80178E94: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x80178E98: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80178E9C: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    // 0x80178EA0: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x80178EA4: swc1        $f18, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f18.u32l;
    // 0x80178EA8: swc1        $f16, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f16.u32l;
    // 0x80178EAC: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    // 0x80178EB0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80178EB4: jal         0x80178C68
    // 0x80178EB8: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    func_80178C68_1501A0(rdram, ctx);
        goto after_1;
    // 0x80178EB8: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80178EBC: beq         $v0, $zero, L_80178ED0
    if (ctx->r2 == 0) {
        // 0x80178EC0: nop
    
            goto L_80178ED0;
    }
    // 0x80178EC0: nop

    // 0x80178EC4: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80178EC8: ori         $t9, $t8, 0x2
    ctx->r25 = ctx->r24 | 0X2;
    // 0x80178ECC: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
L_80178ED0:
    // 0x80178ED0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80178ED4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80178ED8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80178EDC: lwc1        $f16, -0x480($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X480);
    // 0x80178EE0: lui         $at, 0xC108
    ctx->r1 = S32(0XC108 << 16);
    // 0x80178EE4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80178EE8: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80178EEC: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80178EF0: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x80178EF4: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80178EF8: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    // 0x80178EFC: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x80178F00: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    // 0x80178F04: swc1        $f16, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f16.u32l;
    // 0x80178F08: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    // 0x80178F0C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x80178F10: jal         0x80178C68
    // 0x80178F14: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    func_80178C68_1501A0(rdram, ctx);
        goto after_2;
    // 0x80178F14: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_2:
    // 0x80178F18: beq         $v0, $zero, L_80178F2C
    if (ctx->r2 == 0) {
        // 0x80178F1C: nop
    
            goto L_80178F2C;
    }
    // 0x80178F1C: nop

    // 0x80178F20: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80178F24: ori         $t1, $t0, 0x4
    ctx->r9 = ctx->r8 | 0X4;
    // 0x80178F28: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
L_80178F2C:
    // 0x80178F2C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80178F30: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80178F34: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80178F38: lwc1        $f6, -0x47C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X47C);
    // 0x80178F3C: lui         $at, 0xC108
    ctx->r1 = S32(0XC108 << 16);
    // 0x80178F40: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80178F44: lwc1        $f18, 0x34($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80178F48: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80178F4C: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x80178F50: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80178F54: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    // 0x80178F58: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x80178F5C: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
    // 0x80178F60: swc1        $f6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f6.u32l;
    // 0x80178F64: swc1        $f16, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f16.u32l;
    // 0x80178F68: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x80178F6C: jal         0x80178C68
    // 0x80178F70: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    func_80178C68_1501A0(rdram, ctx);
        goto after_3;
    // 0x80178F70: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_3:
    // 0x80178F74: beq         $v0, $zero, L_80178F88
    if (ctx->r2 == 0) {
        // 0x80178F78: nop
    
            goto L_80178F88;
    }
    // 0x80178F78: nop

    // 0x80178F7C: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80178F80: ori         $t3, $t2, 0x5
    ctx->r11 = ctx->r10 | 0X5;
    // 0x80178F84: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
L_80178F88:
    // 0x80178F88: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80178F8C: addiu       $t4, $t4, -0x4198
    ctx->r12 = ADD32(ctx->r12, -0X4198);
    // 0x80178F90: lwc1        $f4, 0x0($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X0);
    // 0x80178F94: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80178F98: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80178F9C: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x80178FA0: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80178FA4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80178FA8: addiu       $t6, $t6, -0x4198
    ctx->r14 = ADD32(ctx->r14, -0X4198);
    // 0x80178FAC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80178FB0: swc1        $f6, 0xB8($t5)
    MEM_W(0XB8, ctx->r13) = ctx->f6.u32l;
    // 0x80178FB4: lwc1        $f18, 0x4($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X4);
    // 0x80178FB8: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80178FBC: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x80178FC0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80178FC4: sub.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80178FC8: addiu       $t8, $t8, -0x4198
    ctx->r24 = ADD32(ctx->r24, -0X4198);
    // 0x80178FCC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80178FD0: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x80178FD4: swc1        $f8, 0xBC($t7)
    MEM_W(0XBC, ctx->r15) = ctx->f8.u32l;
    // 0x80178FD8: lwc1        $f4, 0x8($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X8);
    // 0x80178FDC: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80178FE0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80178FE4: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x80178FE8: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80178FEC: swc1        $f6, 0xC0($t9)
    MEM_W(0XC0, ctx->r25) = ctx->f6.u32l;
    // 0x80178FF0: lwc1        $f16, 0xB8($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0XB8);
    // 0x80178FF4: lwc1        $f8, 0xBC($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0XBC);
    // 0x80178FF8: lwc1        $f6, 0xC0($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0XC0);
    // 0x80178FFC: mul.s       $f18, $f16, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x80179000: nop

    // 0x80179004: mul.s       $f10, $f8, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x80179008: add.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x8017900C: mul.s       $f16, $f6, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x80179010: jal         0x800D68E0
    // 0x80179014: add.s       $f12, $f16, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_4;
    // 0x80179014: add.s       $f12, $f16, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f4.fl;
    after_4:
    // 0x80179018: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017901C: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x80179020: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80179024: swc1        $f0, 0xC4($t1)
    MEM_W(0XC4, ctx->r9) = ctx->f0.u32l;
    // 0x80179028: addiu       $t2, $t2, -0x2BA8
    ctx->r10 = ADD32(ctx->r10, -0X2BA8);
    // 0x8017902C: lw          $t3, 0xE8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XE8);
    // 0x80179030: sltiu       $at, $t3, 0x12D
    ctx->r1 = ctx->r11 < 0X12D ? 1 : 0;
    // 0x80179034: bne         $at, $zero, L_80179048
    if (ctx->r1 != 0) {
        // 0x80179038: nop
    
            goto L_80179048;
    }
    // 0x80179038: nop

    // 0x8017903C: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80179040: ori         $t5, $t4, 0x6
    ctx->r13 = ctx->r12 | 0X6;
    // 0x80179044: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
L_80179048:
    // 0x80179048: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8017904C: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x80179050: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80179054: jr          $ra
    // 0x80179058: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80179058: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_8017905C_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017905C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80179060: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80179064: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80179068: addiu       $t6, $t6, -0x2BA8
    ctx->r14 = ADD32(ctx->r14, -0X2BA8);
    // 0x8017906C: jal         0x800D6AB0
    // 0x80179070: lwc1        $f12, 0x144($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X144);
    __cosf_recomp(rdram, ctx);
        goto after_0;
    // 0x80179070: lwc1        $f12, 0x144($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X144);
    after_0:
    // 0x80179074: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80179078: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017907C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80179080: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80179084: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80179088: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017908C: addiu       $t7, $t7, -0x2BA8
    ctx->r15 = ADD32(ctx->r15, -0X2BA8);
    // 0x80179090: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80179094: addiu       $t8, $t8, -0x2BA8
    ctx->r24 = ADD32(ctx->r24, -0X2BA8);
    // 0x80179098: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8017909C: swc1        $f10, 0x134($t7)
    MEM_W(0X134, ctx->r15) = ctx->f10.u32l;
    // 0x801790A0: lw          $t9, 0xF4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XF4);
    // 0x801790A4: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x801790A8: bgez        $t9, L_801790C0
    if (SIGNED(ctx->r25) >= 0) {
        // 0x801790AC: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_801790C0;
    }
    // 0x801790AC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x801790B0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801790B4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801790B8: nop

    // 0x801790BC: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_801790C0:
    // 0x801790C0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801790C4: lwc1        $f6, -0x478($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X478);
    // 0x801790C8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x801790CC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801790D0: mul.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x801790D4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x801790D8: addiu       $t0, $t0, -0x2BA8
    ctx->r8 = ADD32(ctx->r8, -0X2BA8);
    // 0x801790DC: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x801790E0: swc1        $f16, 0x144($t8)
    MEM_W(0X144, ctx->r24) = ctx->f16.u32l;
    // 0x801790E4: lw          $t1, 0xF4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XF4);
    // 0x801790E8: addiu       $t2, $t1, 0xD
    ctx->r10 = ADD32(ctx->r9, 0XD);
    // 0x801790EC: sw          $t2, 0xF4($t0)
    MEM_W(0XF4, ctx->r8) = ctx->r10;
    // 0x801790F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801790F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801790F8: jr          $ra
    // 0x801790FC: nop

    return;
    // 0x801790FC: nop

;}
RECOMP_FUNC void func_80179100_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80179100: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80179104: lwc1        $f4, -0x2B24($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2B24);
    // 0x80179108: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8017910C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80179110: lwc1        $f6, -0x2B20($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2B20);
    // 0x80179114: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80179118: lwc1        $f8, -0x2B1C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2B1C);
    // 0x8017911C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80179120: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80179124: swc1        $f12, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f12.u32l;
    // 0x80179128: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8017912C: addiu       $t6, $t6, -0x2BA8
    ctx->r14 = ADD32(ctx->r14, -0X2BA8);
    // 0x80179130: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x80179134: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    // 0x80179138: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x8017913C: lwc1        $f10, 0x12C($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X12C);
    // 0x80179140: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x80179144: lwc1        $f16, 0x134($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X134);
    // 0x80179148: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x8017914C: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x80179150: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
L_80179154:
    // 0x80179154: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80179158: addiu       $t7, $t7, -0x2BA8
    ctx->r15 = ADD32(ctx->r15, -0X2BA8);
    // 0x8017915C: jal         0x8017840C
    // 0x80179160: lwc1        $f12, 0x134($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X134);
    func_8017840C_1501A0(rdram, ctx);
        goto after_0;
    // 0x80179160: lwc1        $f12, 0x134($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X134);
    after_0:
    // 0x80179164: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80179168: addiu       $t8, $t8, -0x2BA8
    ctx->r24 = ADD32(ctx->r24, -0X2BA8);
    // 0x8017916C: lwc1        $f14, 0x128($t8)
    ctx->f14.u32l = MEM_W(ctx->r24, 0X128);
    // 0x80179170: lw          $a2, 0x12C($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X12C);
    // 0x80179174: lw          $a3, 0x130($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X130);
    // 0x80179178: jal         0x80178DA4
    // 0x8017917C: lwc1        $f12, 0x40($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X40);
    func_80178DA4_1501A0(rdram, ctx);
        goto after_1;
    // 0x8017917C: lwc1        $f12, 0x40($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X40);
    after_1:
    // 0x80179180: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80179184: addiu       $t9, $t9, 0x3C00
    ctx->r25 = ADD32(ctx->r25, 0X3C00);
    // 0x80179188: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017918C: sw          $v0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r2;
    // 0x80179190: addiu       $t0, $t0, 0x3C00
    ctx->r8 = ADD32(ctx->r8, 0X3C00);
    // 0x80179194: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80179198: andi        $t2, $t1, 0x3
    ctx->r10 = ctx->r9 & 0X3;
    // 0x8017919C: beq         $t2, $zero, L_801791B0
    if (ctx->r10 == 0) {
        // 0x801791A0: nop
    
            goto L_801791B0;
    }
    // 0x801791A0: nop

    // 0x801791A4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801791A8: b           L_80179250
    // 0x801791AC: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
        goto L_80179250;
    // 0x801791AC: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
L_801791B0:
    // 0x801791B0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x801791B4: addiu       $t4, $t4, -0x2BA8
    ctx->r12 = ADD32(ctx->r12, -0X2BA8);
    // 0x801791B8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801791BC: lwc1        $f18, -0x2B24($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2B24);
    // 0x801791C0: lwc1        $f4, 0x128($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X128);
    // 0x801791C4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801791C8: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801791CC: swc1        $f6, -0x2B24($at)
    MEM_W(-0X2B24, ctx->r1) = ctx->f6.u32l;
    // 0x801791D0: lwc1        $f8, 0x12C($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X12C);
    // 0x801791D4: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x801791D8: nop

    // 0x801791DC: bc1f        L_801791EC
    if (!c1cs) {
        // 0x801791E0: nop
    
            goto L_801791EC;
    }
    // 0x801791E0: nop

    // 0x801791E4: b           L_801791F8
    // 0x801791E8: neg.s       $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = -ctx->f8.fl;
        goto L_801791F8;
    // 0x801791E8: neg.s       $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = -ctx->f8.fl;
L_801791EC:
    // 0x801791EC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x801791F0: addiu       $t5, $t5, -0x2BA8
    ctx->r13 = ADD32(ctx->r13, -0X2BA8);
    // 0x801791F4: lwc1        $f20, 0x12C($t5)
    ctx->f20.u32l = MEM_W(ctx->r13, 0X12C);
L_801791F8:
    // 0x801791F8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801791FC: lwc1        $f16, -0x2B20($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2B20);
    // 0x80179200: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80179204: addiu       $t6, $t6, -0x2BA8
    ctx->r14 = ADD32(ctx->r14, -0X2BA8);
    // 0x80179208: add.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f20.fl;
    // 0x8017920C: swc1        $f18, -0x2B20($at)
    MEM_W(-0X2B20, ctx->r1) = ctx->f18.u32l;
    // 0x80179210: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80179214: lwc1        $f4, -0x2B1C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2B1C);
    // 0x80179218: lwc1        $f6, 0x130($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X130);
    // 0x8017921C: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80179220: swc1        $f10, -0x2B1C($at)
    MEM_W(-0X2B1C, ctx->r1) = ctx->f10.u32l;
    // 0x80179224: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80179228: lwc1        $f16, -0x474($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X474);
    // 0x8017922C: lwc1        $f8, 0x12C($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X12C);
    // 0x80179230: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80179234: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80179238: swc1        $f4, 0x12C($t6)
    MEM_W(0X12C, ctx->r14) = ctx->f4.u32l;
    // 0x8017923C: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80179240: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80179244: slti        $at, $t8, 0x46
    ctx->r1 = SIGNED(ctx->r24) < 0X46 ? 1 : 0;
    // 0x80179248: bne         $at, $zero, L_80179154
    if (ctx->r1 != 0) {
        // 0x8017924C: sw          $t8, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r24;
            goto L_80179154;
    }
    // 0x8017924C: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
L_80179250:
    // 0x80179250: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x80179254: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80179258: addiu       $t1, $t1, -0x2BA8
    ctx->r9 = ADD32(ctx->r9, -0X2BA8);
    // 0x8017925C: bgez        $t9, L_8017926C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80179260: sra         $t0, $t9, 1
        ctx->r8 = S32(SIGNED(ctx->r25) >> 1);
            goto L_8017926C;
    }
    // 0x80179260: sra         $t0, $t9, 1
    ctx->r8 = S32(SIGNED(ctx->r25) >> 1);
    // 0x80179264: addiu       $at, $t9, 0x1
    ctx->r1 = ADD32(ctx->r25, 0X1);
    // 0x80179268: sra         $t0, $at, 1
    ctx->r8 = S32(SIGNED(ctx->r1) >> 1);
L_8017926C:
    // 0x8017926C: sw          $t0, 0xEC($t1)
    MEM_W(0XEC, ctx->r9) = ctx->r8;
    // 0x80179270: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80179274: beq         $t2, $zero, L_801792C0
    if (ctx->r10 == 0) {
        // 0x80179278: nop
    
            goto L_801792C0;
    }
    // 0x80179278: nop

    // 0x8017927C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80179280: addiu       $t3, $t3, -0x2BA8
    ctx->r11 = ADD32(ctx->r11, -0X2BA8);
    // 0x80179284: lw          $t4, 0xEC($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XEC);
    // 0x80179288: sltiu       $at, $t4, 0x6
    ctx->r1 = ctx->r12 < 0X6 ? 1 : 0;
    // 0x8017928C: beq         $at, $zero, L_8017929C
    if (ctx->r1 == 0) {
        // 0x80179290: nop
    
            goto L_8017929C;
    }
    // 0x80179290: nop

    // 0x80179294: b           L_801792D0
    // 0x80179298: sw          $zero, 0x108($t3)
    MEM_W(0X108, ctx->r11) = 0;
        goto L_801792D0;
    // 0x80179298: sw          $zero, 0x108($t3)
    MEM_W(0X108, ctx->r11) = 0;
L_8017929C:
    // 0x8017929C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x801792A0: addiu       $t5, $t5, -0x2BA8
    ctx->r13 = ADD32(ctx->r13, -0X2BA8);
    // 0x801792A4: lw          $t6, 0xEC($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XEC);
    // 0x801792A8: sltiu       $at, $t6, 0x33
    ctx->r1 = ctx->r14 < 0X33 ? 1 : 0;
    // 0x801792AC: beq         $at, $zero, L_801792D0
    if (ctx->r1 == 0) {
        // 0x801792B0: nop
    
            goto L_801792D0;
    }
    // 0x801792B0: nop

    // 0x801792B4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801792B8: b           L_801792D0
    // 0x801792BC: sw          $t7, 0x108($t5)
    MEM_W(0X108, ctx->r13) = ctx->r15;
        goto L_801792D0;
    // 0x801792BC: sw          $t7, 0x108($t5)
    MEM_W(0X108, ctx->r13) = ctx->r15;
L_801792C0:
    // 0x801792C0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801792C4: addiu       $t9, $t9, -0x2BA8
    ctx->r25 = ADD32(ctx->r25, -0X2BA8);
    // 0x801792C8: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x801792CC: sw          $t8, 0x108($t9)
    MEM_W(0X108, ctx->r25) = ctx->r24;
L_801792D0:
    // 0x801792D0: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801792D4: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801792D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801792DC: swc1        $f6, -0x2B24($at)
    MEM_W(-0X2B24, ctx->r1) = ctx->f6.u32l;
    // 0x801792E0: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801792E4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801792E8: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801792EC: swc1        $f10, -0x2B20($at)
    MEM_W(-0X2B20, ctx->r1) = ctx->f10.u32l;
    // 0x801792F0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801792F4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x801792F8: addiu       $t0, $t0, -0x2BA8
    ctx->r8 = ADD32(ctx->r8, -0X2BA8);
    // 0x801792FC: swc1        $f16, -0x2B1C($at)
    MEM_W(-0X2B1C, ctx->r1) = ctx->f16.u32l;
    // 0x80179300: swc1        $f8, 0x12C($t0)
    MEM_W(0X12C, ctx->r8) = ctx->f8.u32l;
    // 0x80179304: lwc1        $f18, 0x24($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80179308: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017930C: addiu       $t1, $t1, -0x2BA8
    ctx->r9 = ADD32(ctx->r9, -0X2BA8);
    // 0x80179310: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80179314: addiu       $t2, $t2, -0x2BA8
    ctx->r10 = ADD32(ctx->r10, -0X2BA8);
    // 0x80179318: swc1        $f18, 0x134($t1)
    MEM_W(0X134, ctx->r9) = ctx->f18.u32l;
    // 0x8017931C: jal         0x8017840C
    // 0x80179320: lwc1        $f12, 0x134($t2)
    ctx->f12.u32l = MEM_W(ctx->r10, 0X134);
    func_8017840C_1501A0(rdram, ctx);
        goto after_2;
    // 0x80179320: lwc1        $f12, 0x134($t2)
    ctx->f12.u32l = MEM_W(ctx->r10, 0X134);
    after_2:
    // 0x80179324: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80179328: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8017932C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80179330: jr          $ra
    // 0x80179334: nop

    return;
    // 0x80179334: nop

;}
RECOMP_FUNC void func_80179338_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80179338: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017933C: lwc1        $f4, -0x2B24($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2B24);
    // 0x80179340: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80179344: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80179348: lwc1        $f6, -0x2B20($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2B20);
    // 0x8017934C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80179350: lwc1        $f8, -0x2B1C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2B1C);
    // 0x80179354: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80179358: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8017935C: swc1        $f12, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f12.u32l;
    // 0x80179360: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80179364: addiu       $t6, $t6, -0x2BA8
    ctx->r14 = ADD32(ctx->r14, -0X2BA8);
    // 0x80179368: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x8017936C: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    // 0x80179370: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x80179374: lwc1        $f10, 0x12C($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X12C);
    // 0x80179378: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    // 0x8017937C: lwc1        $f16, 0x134($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X134);
    // 0x80179380: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x80179384: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    // 0x80179388: lw          $t7, 0xEC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XEC);
    // 0x8017938C: srl         $t8, $t7, 1
    ctx->r24 = S32(U32(ctx->r15) >> 1);
    // 0x80179390: beq         $t8, $zero, L_8017945C
    if (ctx->r24 == 0) {
        // 0x80179394: nop
    
            goto L_8017945C;
    }
    // 0x80179394: nop

L_80179398:
    // 0x80179398: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017939C: addiu       $t9, $t9, -0x2BA8
    ctx->r25 = ADD32(ctx->r25, -0X2BA8);
    // 0x801793A0: jal         0x8017840C
    // 0x801793A4: lwc1        $f12, 0x134($t9)
    ctx->f12.u32l = MEM_W(ctx->r25, 0X134);
    func_8017840C_1501A0(rdram, ctx);
        goto after_0;
    // 0x801793A4: lwc1        $f12, 0x134($t9)
    ctx->f12.u32l = MEM_W(ctx->r25, 0X134);
    after_0:
    // 0x801793A8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x801793AC: addiu       $t0, $t0, -0x2BA8
    ctx->r8 = ADD32(ctx->r8, -0X2BA8);
    // 0x801793B0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801793B4: lwc1        $f18, -0x2B24($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2B24);
    // 0x801793B8: lwc1        $f4, 0x128($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X128);
    // 0x801793BC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801793C0: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801793C4: swc1        $f6, -0x2B24($at)
    MEM_W(-0X2B24, ctx->r1) = ctx->f6.u32l;
    // 0x801793C8: lwc1        $f8, 0x12C($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X12C);
    // 0x801793CC: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x801793D0: nop

    // 0x801793D4: bc1f        L_801793E4
    if (!c1cs) {
        // 0x801793D8: nop
    
            goto L_801793E4;
    }
    // 0x801793D8: nop

    // 0x801793DC: b           L_801793F0
    // 0x801793E0: neg.s       $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = -ctx->f8.fl;
        goto L_801793F0;
    // 0x801793E0: neg.s       $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = -ctx->f8.fl;
L_801793E4:
    // 0x801793E4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x801793E8: addiu       $t1, $t1, -0x2BA8
    ctx->r9 = ADD32(ctx->r9, -0X2BA8);
    // 0x801793EC: lwc1        $f20, 0x12C($t1)
    ctx->f20.u32l = MEM_W(ctx->r9, 0X12C);
L_801793F0:
    // 0x801793F0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801793F4: lwc1        $f16, -0x2B20($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2B20);
    // 0x801793F8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x801793FC: addiu       $t2, $t2, -0x2BA8
    ctx->r10 = ADD32(ctx->r10, -0X2BA8);
    // 0x80179400: add.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f20.fl;
    // 0x80179404: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80179408: addiu       $t5, $t5, -0x2BA8
    ctx->r13 = ADD32(ctx->r13, -0X2BA8);
    // 0x8017940C: swc1        $f18, -0x2B20($at)
    MEM_W(-0X2B20, ctx->r1) = ctx->f18.u32l;
    // 0x80179410: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80179414: lwc1        $f4, -0x2B1C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2B1C);
    // 0x80179418: lwc1        $f6, 0x130($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X130);
    // 0x8017941C: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80179420: swc1        $f10, -0x2B1C($at)
    MEM_W(-0X2B1C, ctx->r1) = ctx->f10.u32l;
    // 0x80179424: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80179428: lwc1        $f16, -0x470($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X470);
    // 0x8017942C: lwc1        $f8, 0x12C($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X12C);
    // 0x80179430: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80179434: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80179438: swc1        $f4, 0x12C($t2)
    MEM_W(0X12C, ctx->r10) = ctx->f4.u32l;
    // 0x8017943C: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x80179440: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80179444: sw          $t4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r12;
    // 0x80179448: lw          $t6, 0xEC($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XEC);
    // 0x8017944C: srl         $t7, $t6, 1
    ctx->r15 = S32(U32(ctx->r14) >> 1);
    // 0x80179450: sltu        $at, $t4, $t7
    ctx->r1 = ctx->r12 < ctx->r15 ? 1 : 0;
    // 0x80179454: bne         $at, $zero, L_80179398
    if (ctx->r1 != 0) {
        // 0x80179458: nop
    
            goto L_80179398;
    }
    // 0x80179458: nop

L_8017945C:
    // 0x8017945C: jal         0x80178758
    // 0x80179460: lwc1        $f12, 0x40($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X40);
    func_80178758_1501A0(rdram, ctx);
        goto after_1;
    // 0x80179460: lwc1        $f12, 0x40($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X40);
    after_1:
    // 0x80179464: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80179468: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8017946C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80179470: swc1        $f6, -0x2B24($at)
    MEM_W(-0X2B24, ctx->r1) = ctx->f6.u32l;
    // 0x80179474: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80179478: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017947C: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80179480: swc1        $f10, -0x2B20($at)
    MEM_W(-0X2B20, ctx->r1) = ctx->f10.u32l;
    // 0x80179484: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80179488: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017948C: addiu       $t8, $t8, -0x2BA8
    ctx->r24 = ADD32(ctx->r24, -0X2BA8);
    // 0x80179490: swc1        $f16, -0x2B1C($at)
    MEM_W(-0X2B1C, ctx->r1) = ctx->f16.u32l;
    // 0x80179494: swc1        $f8, 0x12C($t8)
    MEM_W(0X12C, ctx->r24) = ctx->f8.u32l;
    // 0x80179498: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8017949C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801794A0: addiu       $t9, $t9, -0x2BA8
    ctx->r25 = ADD32(ctx->r25, -0X2BA8);
    // 0x801794A4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x801794A8: addiu       $t0, $t0, -0x2BA8
    ctx->r8 = ADD32(ctx->r8, -0X2BA8);
    // 0x801794AC: swc1        $f18, 0x134($t9)
    MEM_W(0X134, ctx->r25) = ctx->f18.u32l;
    // 0x801794B0: jal         0x8017840C
    // 0x801794B4: lwc1        $f12, 0x134($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0X134);
    func_8017840C_1501A0(rdram, ctx);
        goto after_2;
    // 0x801794B4: lwc1        $f12, 0x134($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0X134);
    after_2:
    // 0x801794B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801794BC: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x801794C0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x801794C4: jr          $ra
    // 0x801794C8: nop

    return;
    // 0x801794C8: nop

;}
RECOMP_FUNC void func_801794CC_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801794CC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801794D0: lwc1        $f4, -0x2E30($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x801794D4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801794D8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801794DC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801794E0: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x801794E4: addiu       $t6, $t6, -0x2E28
    ctx->r14 = ADD32(ctx->r14, -0X2E28);
    // 0x801794E8: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x801794EC: lbu         $t7, 0xC($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0XC);
    // 0x801794F0: ori         $t8, $t7, 0x10
    ctx->r24 = ctx->r15 | 0X10;
    // 0x801794F4: jal         0x80189E60
    // 0x801794F8: sb          $t8, 0xC($t6)
    MEM_B(0XC, ctx->r14) = ctx->r24;
    func_80189E60_1501A0(rdram, ctx);
        goto after_0;
    // 0x801794F8: sb          $t8, 0xC($t6)
    MEM_B(0XC, ctx->r14) = ctx->r24;
    after_0:
    // 0x801794FC: jal         0x8018616C
    // 0x80179500: nop

    func_8018616C_1501A0(rdram, ctx);
        goto after_1;
    // 0x80179500: nop

    after_1:
    // 0x80179504: jal         0x800CB6F8
    // 0x80179508: nop

    func_800CB6F8(rdram, ctx);
        goto after_2;
    // 0x80179508: nop

    after_2:
    // 0x8017950C: jal         0x80176EB0
    // 0x80179510: nop

    func_80176EB0_1501A0(rdram, ctx);
        goto after_3;
    // 0x80179510: nop

    after_3:
    // 0x80179514: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80179518: addiu       $t9, $t9, -0x4198
    ctx->r25 = ADD32(ctx->r25, -0X4198);
    // 0x8017951C: lwc1        $f6, 0x0($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X0);
    // 0x80179520: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80179524: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80179528: swc1        $f6, -0x2B24($at)
    MEM_W(-0X2B24, ctx->r1) = ctx->f6.u32l;
    // 0x8017952C: lwc1        $f8, 0x4($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X4);
    // 0x80179530: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80179534: addiu       $t0, $t0, -0x2BA8
    ctx->r8 = ADD32(ctx->r8, -0X2BA8);
    // 0x80179538: swc1        $f8, -0x2B20($at)
    MEM_W(-0X2B20, ctx->r1) = ctx->f8.u32l;
    // 0x8017953C: lwc1        $f10, 0x8($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X8);
    // 0x80179540: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80179544: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80179548: swc1        $f10, -0x2B1C($at)
    MEM_W(-0X2B1C, ctx->r1) = ctx->f10.u32l;
    // 0x8017954C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80179550: lwc1        $f16, -0x2BCC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2BCC);
    // 0x80179554: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80179558: addiu       $t1, $t1, -0x2BA8
    ctx->r9 = ADD32(ctx->r9, -0X2BA8);
    // 0x8017955C: swc1        $f16, 0x150($t0)
    MEM_W(0X150, ctx->r8) = ctx->f16.u32l;
    // 0x80179560: lwc1        $f18, -0x2BC8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2BC8);
    // 0x80179564: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80179568: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017956C: swc1        $f18, 0x154($t1)
    MEM_W(0X154, ctx->r9) = ctx->f18.u32l;
    // 0x80179570: lwc1        $f4, -0x2BC4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2BC4);
    // 0x80179574: addiu       $t2, $t2, -0x2BA8
    ctx->r10 = ADD32(ctx->r10, -0X2BA8);
    // 0x80179578: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017957C: swc1        $f4, 0x158($t2)
    MEM_W(0X158, ctx->r10) = ctx->f4.u32l;
    // 0x80179580: lwc1        $f6, -0x2BCC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2BCC);
    // 0x80179584: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80179588: lwc1        $f10, -0x2BC8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2BC8);
    // 0x8017958C: mul.s       $f8, $f6, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x80179590: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80179594: lwc1        $f4, -0x2BC4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2BC4);
    // 0x80179598: mul.s       $f16, $f10, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x8017959C: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x801795A0: mul.s       $f6, $f4, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x801795A4: jal         0x800D68E0
    // 0x801795A8: add.s       $f12, $f18, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_4;
    // 0x801795A8: add.s       $f12, $f18, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f6.fl;
    after_4:
    // 0x801795AC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x801795B0: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x801795B4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x801795B8: swc1        $f0, 0x10($t3)
    MEM_W(0X10, ctx->r11) = ctx->f0.u32l;
    // 0x801795BC: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x801795C0: lwc1        $f10, 0x10($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X10);
    // 0x801795C4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801795C8: nop

    // 0x801795CC: c.eq.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl == ctx->f8.fl;
    // 0x801795D0: nop

    // 0x801795D4: bc1f        L_801795F0
    if (!c1cs) {
        // 0x801795D8: lui         $at, 0x801A
        ctx->r1 = S32(0X801A << 16);
            goto L_801795F0;
    }
    // 0x801795D8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801795DC: lwc1        $f4, -0x46C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X46C);
    // 0x801795E0: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801795E4: mul.s       $f18, $f16, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x801795E8: b           L_80179654
    // 0x801795EC: swc1        $f18, 0x14($t4)
    MEM_W(0X14, ctx->r12) = ctx->f18.u32l;
        goto L_80179654;
    // 0x801795EC: swc1        $f18, 0x14($t4)
    MEM_W(0X14, ctx->r12) = ctx->f18.u32l;
L_801795F0:
    // 0x801795F0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x801795F4: addiu       $t5, $t5, -0x2BA8
    ctx->r13 = ADD32(ctx->r13, -0X2BA8);
    // 0x801795F8: lw          $t7, 0x10C($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X10C);
    // 0x801795FC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80179600: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x80179604: ori         $t8, $t7, 0x8
    ctx->r24 = ctx->r15 | 0X8;
    // 0x80179608: sw          $t8, 0x10C($t5)
    MEM_W(0X10C, ctx->r13) = ctx->r24;
    // 0x8017960C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80179610: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80179614: lwc1        $f6, 0x10($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X10);
    // 0x80179618: c.le.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl <= ctx->f6.fl;
    // 0x8017961C: nop

    // 0x80179620: bc1f        L_8017963C
    if (!c1cs) {
        // 0x80179624: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_8017963C;
    }
    // 0x80179624: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80179628: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8017962C: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80179630: mul.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80179634: b           L_80179654
    // 0x80179638: swc1        $f4, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->f4.u32l;
        goto L_80179654;
    // 0x80179638: swc1        $f4, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->f4.u32l;
L_8017963C:
    // 0x8017963C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80179640: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x80179644: lwc1        $f18, 0x10($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X10);
    // 0x80179648: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8017964C: mul.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x80179650: swc1        $f10, 0x14($t9)
    MEM_W(0X14, ctx->r25) = ctx->f10.u32l;
L_80179654:
    // 0x80179654: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80179658: addiu       $t0, $t0, -0x4198
    ctx->r8 = ADD32(ctx->r8, -0X4198);
    // 0x8017965C: lwc1        $f8, 0xC($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0XC);
    // 0x80179660: lwc1        $f16, 0x0($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80179664: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80179668: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x8017966C: sub.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x80179670: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80179674: addiu       $t2, $t2, -0x4198
    ctx->r10 = ADD32(ctx->r10, -0X4198);
    // 0x80179678: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017967C: swc1        $f4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f4.u32l;
    // 0x80179680: lwc1        $f6, 0x4($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X4);
    // 0x80179684: lwc1        $f18, 0x10($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X10);
    // 0x80179688: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x8017968C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80179690: sub.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x80179694: addiu       $t4, $t4, -0x4198
    ctx->r12 = ADD32(ctx->r12, -0X4198);
    // 0x80179698: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017969C: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x801796A0: swc1        $f10, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->f10.u32l;
    // 0x801796A4: lwc1        $f16, 0x8($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X8);
    // 0x801796A8: lwc1        $f8, 0x14($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X14);
    // 0x801796AC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x801796B0: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x801796B4: sub.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x801796B8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801796BC: swc1        $f4, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->f4.u32l;
    // 0x801796C0: lwc1        $f18, 0x0($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X0);
    // 0x801796C4: c.eq.s      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.fl == ctx->f6.fl;
    // 0x801796C8: nop

    // 0x801796CC: bc1f        L_8017970C
    if (!c1cs) {
        // 0x801796D0: nop
    
            goto L_8017970C;
    }
    // 0x801796D0: nop

    // 0x801796D4: lwc1        $f10, 0x4($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X4);
    // 0x801796D8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801796DC: nop

    // 0x801796E0: c.eq.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl == ctx->f8.fl;
    // 0x801796E4: nop

    // 0x801796E8: bc1f        L_8017970C
    if (!c1cs) {
        // 0x801796EC: nop
    
            goto L_8017970C;
    }
    // 0x801796EC: nop

    // 0x801796F0: lwc1        $f16, 0x8($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X8);
    // 0x801796F4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801796F8: nop

    // 0x801796FC: c.eq.s      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.fl == ctx->f4.fl;
    // 0x80179700: nop

    // 0x80179704: bc1t        L_80179798
    if (c1cs) {
        // 0x80179708: nop
    
            goto L_80179798;
    }
    // 0x80179708: nop

L_8017970C:
    // 0x8017970C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80179710: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x80179714: lwc1        $f18, 0x0($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X0);
    // 0x80179718: lwc1        $f10, 0x4($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X4);
    // 0x8017971C: lwc1        $f4, 0x8($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X8);
    // 0x80179720: mul.s       $f6, $f18, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x80179724: nop

    // 0x80179728: mul.s       $f8, $f10, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x8017972C: add.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80179730: mul.s       $f18, $f4, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x80179734: jal         0x800D68E0
    // 0x80179738: add.s       $f12, $f18, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f16.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_5;
    // 0x80179738: add.s       $f12, $f18, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f16.fl;
    after_5:
    // 0x8017973C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80179740: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x80179744: lwc1        $f10, 0x14($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X14);
    // 0x80179748: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017974C: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x80179750: div.s       $f6, $f10, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80179754: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80179758: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x8017975C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80179760: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x80179764: swc1        $f6, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f6.u32l;
    // 0x80179768: lwc1        $f8, 0x0($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X0);
    // 0x8017976C: lwc1        $f4, 0xC($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0XC);
    // 0x80179770: mul.s       $f18, $f8, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x80179774: swc1        $f18, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f18.u32l;
    // 0x80179778: lwc1        $f16, 0x4($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X4);
    // 0x8017977C: lwc1        $f10, 0xC($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0XC);
    // 0x80179780: mul.s       $f6, $f16, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x80179784: swc1        $f6, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f6.u32l;
    // 0x80179788: lwc1        $f8, 0x8($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X8);
    // 0x8017978C: lwc1        $f4, 0xC($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0XC);
    // 0x80179790: mul.s       $f18, $f8, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x80179794: swc1        $f18, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f18.u32l;
L_80179798:
    // 0x80179798: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017979C: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x801797A0: lwc1        $f16, 0x0($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X0);
    // 0x801797A4: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x801797A8: addiu       $t3, $t3, -0x2BA8
    ctx->r11 = ADD32(ctx->r11, -0X2BA8);
    // 0x801797AC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x801797B0: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x801797B4: swc1        $f16, 0x128($t3)
    MEM_W(0X128, ctx->r11) = ctx->f16.u32l;
    // 0x801797B8: lwc1        $f10, 0x4($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X4);
    // 0x801797BC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801797C0: nop

    // 0x801797C4: c.lt.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl < ctx->f6.fl;
    // 0x801797C8: nop

    // 0x801797CC: bc1f        L_801797E8
    if (!c1cs) {
        // 0x801797D0: nop
    
            goto L_801797E8;
    }
    // 0x801797D0: nop

    // 0x801797D4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801797D8: neg.s       $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = -ctx->f10.fl;
    // 0x801797DC: addiu       $t7, $t7, -0x2BA8
    ctx->r15 = ADD32(ctx->r15, -0X2BA8);
    // 0x801797E0: b           L_80179800
    // 0x801797E4: swc1        $f8, 0x12C($t7)
    MEM_W(0X12C, ctx->r15) = ctx->f8.u32l;
        goto L_80179800;
    // 0x801797E4: swc1        $f8, 0x12C($t7)
    MEM_W(0X12C, ctx->r15) = ctx->f8.u32l;
L_801797E8:
    // 0x801797E8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x801797EC: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x801797F0: lwc1        $f4, 0x4($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X4);
    // 0x801797F4: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x801797F8: addiu       $t5, $t5, -0x2BA8
    ctx->r13 = ADD32(ctx->r13, -0X2BA8);
    // 0x801797FC: swc1        $f4, 0x12C($t5)
    MEM_W(0X12C, ctx->r13) = ctx->f4.u32l;
L_80179800:
    // 0x80179800: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80179804: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x80179808: lwc1        $f18, 0x8($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X8);
    // 0x8017980C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80179810: addiu       $t9, $t9, -0x2BA8
    ctx->r25 = ADD32(ctx->r25, -0X2BA8);
    // 0x80179814: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80179818: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x8017981C: swc1        $f18, 0x130($t9)
    MEM_W(0X130, ctx->r25) = ctx->f18.u32l;
    // 0x80179820: lwc1        $f16, 0x0($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80179824: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80179828: addiu       $t1, $t1, -0x2BA8
    ctx->r9 = ADD32(ctx->r9, -0X2BA8);
    // 0x8017982C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80179830: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x80179834: swc1        $f16, 0x138($t1)
    MEM_W(0X138, ctx->r9) = ctx->f16.u32l;
    // 0x80179838: lwc1        $f6, 0x4($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X4);
    // 0x8017983C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80179840: nop

    // 0x80179844: c.lt.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl < ctx->f6.fl;
    // 0x80179848: nop

    // 0x8017984C: bc1f        L_80179868
    if (!c1cs) {
        // 0x80179850: nop
    
            goto L_80179868;
    }
    // 0x80179850: nop

    // 0x80179854: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80179858: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x8017985C: addiu       $t3, $t3, -0x2BA8
    ctx->r11 = ADD32(ctx->r11, -0X2BA8);
    // 0x80179860: b           L_80179880
    // 0x80179864: swc1        $f8, 0x13C($t3)
    MEM_W(0X13C, ctx->r11) = ctx->f8.u32l;
        goto L_80179880;
    // 0x80179864: swc1        $f8, 0x13C($t3)
    MEM_W(0X13C, ctx->r11) = ctx->f8.u32l;
L_80179868:
    // 0x80179868: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017986C: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x80179870: lwc1        $f4, 0x4($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X4);
    // 0x80179874: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80179878: addiu       $t7, $t7, -0x2BA8
    ctx->r15 = ADD32(ctx->r15, -0X2BA8);
    // 0x8017987C: swc1        $f4, 0x13C($t7)
    MEM_W(0X13C, ctx->r15) = ctx->f4.u32l;
L_80179880:
    // 0x80179880: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80179884: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x80179888: lwc1        $f18, 0x8($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X8);
    // 0x8017988C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80179890: addiu       $t5, $t5, -0x2BA8
    ctx->r13 = ADD32(ctx->r13, -0X2BA8);
    // 0x80179894: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80179898: swc1        $f18, 0x140($t5)
    MEM_W(0X140, ctx->r13) = ctx->f18.u32l;
    // 0x8017989C: addiu       $t6, $t6, -0x2BA8
    ctx->r14 = ADD32(ctx->r14, -0X2BA8);
    // 0x801798A0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801798A4: lwc1        $f10, -0x468($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X468);
    // 0x801798A8: lwc1        $f16, 0x12C($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X12C);
    // 0x801798AC: c.lt.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl < ctx->f10.fl;
    // 0x801798B0: nop

    // 0x801798B4: bc1f        L_801798C4
    if (!c1cs) {
        // 0x801798B8: lui         $at, 0x801A
        ctx->r1 = S32(0X801A << 16);
            goto L_801798C4;
    }
    // 0x801798B8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801798BC: lwc1        $f6, -0x464($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X464);
    // 0x801798C0: swc1        $f6, 0x12C($t6)
    MEM_W(0X12C, ctx->r14) = ctx->f6.u32l;
L_801798C4:
    // 0x801798C4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801798C8: addiu       $t9, $t9, -0x2BA8
    ctx->r25 = ADD32(ctx->r25, -0X2BA8);
    // 0x801798CC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x801798D0: sw          $zero, 0xE8($t9)
    MEM_W(0XE8, ctx->r25) = 0;
    // 0x801798D4: addiu       $t0, $t0, -0x2BA8
    ctx->r8 = ADD32(ctx->r8, -0X2BA8);
    // 0x801798D8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x801798DC: sw          $zero, 0xF4($t0)
    MEM_W(0XF4, ctx->r8) = 0;
    // 0x801798E0: addiu       $t1, $t1, -0x2BA8
    ctx->r9 = ADD32(ctx->r9, -0X2BA8);
    // 0x801798E4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x801798E8: sw          $zero, 0xFC($t1)
    MEM_W(0XFC, ctx->r9) = 0;
    // 0x801798EC: addiu       $t2, $t2, -0x2BA8
    ctx->r10 = ADD32(ctx->r10, -0X2BA8);
    // 0x801798F0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x801798F4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801798F8: sw          $zero, 0x100($t2)
    MEM_W(0X100, ctx->r10) = 0;
    // 0x801798FC: addiu       $t3, $t3, -0x2BA8
    ctx->r11 = ADD32(ctx->r11, -0X2BA8);
    // 0x80179900: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80179904: sw          $zero, 0x10C($t3)
    MEM_W(0X10C, ctx->r11) = 0;
    // 0x80179908: addiu       $t7, $t7, -0x2BA8
    ctx->r15 = ADD32(ctx->r15, -0X2BA8);
    // 0x8017990C: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80179910: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80179914: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80179918: sw          $t4, 0x104($t7)
    MEM_W(0X104, ctx->r15) = ctx->r12;
    // 0x8017991C: addiu       $t8, $t8, -0x2BA8
    ctx->r24 = ADD32(ctx->r24, -0X2BA8);
    // 0x80179920: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80179924: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80179928: addiu       $t5, $t5, -0x2BA8
    ctx->r13 = ADD32(ctx->r13, -0X2BA8);
    // 0x8017992C: addiu       $a0, $a0, -0x2BA8
    ctx->r4 = ADD32(ctx->r4, -0X2BA8);
    // 0x80179930: swc1        $f8, 0x134($t8)
    MEM_W(0X134, ctx->r24) = ctx->f8.u32l;
    // 0x80179934: addiu       $a0, $a0, 0xA0
    ctx->r4 = ADD32(ctx->r4, 0XA0);
    // 0x80179938: jal         0x800D6D20
    // 0x8017993C: swc1        $f4, 0x144($t5)
    MEM_W(0X144, ctx->r13) = ctx->f4.u32l;
    guMtxIdentF_recomp(rdram, ctx);
        goto after_6;
    // 0x8017993C: swc1        $f4, 0x144($t5)
    MEM_W(0X144, ctx->r13) = ctx->f4.u32l;
    after_6:
    // 0x80179940: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80179944: addiu       $t6, $t6, -0x2BA8
    ctx->r14 = ADD32(ctx->r14, -0X2BA8);
    // 0x80179948: jal         0x8017840C
    // 0x8017994C: lwc1        $f12, 0x134($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X134);
    func_8017840C_1501A0(rdram, ctx);
        goto after_7;
    // 0x8017994C: lwc1        $f12, 0x134($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X134);
    after_7:
    // 0x80179950: jal         0x80178758
    // 0x80179954: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    func_80178758_1501A0(rdram, ctx);
        goto after_8;
    // 0x80179954: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    after_8:
    // 0x80179958: jal         0x80179100
    // 0x8017995C: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    func_80179100_1501A0(rdram, ctx);
        goto after_9;
    // 0x8017995C: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    after_9:
    // 0x80179960: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80179964: addiu       $t9, $t9, -0x2BA8
    ctx->r25 = ADD32(ctx->r25, -0X2BA8);
    // 0x80179968: lw          $t0, 0xEC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XEC);
    // 0x8017996C: sltiu       $at, $t0, 0x5
    ctx->r1 = ctx->r8 < 0X5 ? 1 : 0;
    // 0x80179970: beq         $at, $zero, L_80179A80
    if (ctx->r1 == 0) {
        // 0x80179974: nop
    
            goto L_80179A80;
    }
    // 0x80179974: nop

L_80179978:
    // 0x80179978: jal         0x80179100
    // 0x8017997C: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    func_80179100_1501A0(rdram, ctx);
        goto after_10;
    // 0x8017997C: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    after_10:
    // 0x80179980: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80179984: addiu       $t1, $t1, -0x2BA8
    ctx->r9 = ADD32(ctx->r9, -0X2BA8);
    // 0x80179988: lwc1        $f18, 0x12C($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X12C);
    // 0x8017998C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80179990: nop

    // 0x80179994: c.lt.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl < ctx->f16.fl;
    // 0x80179998: nop

    // 0x8017999C: bc1f        L_801799AC
    if (!c1cs) {
        // 0x801799A0: nop
    
            goto L_801799AC;
    }
    // 0x801799A0: nop

    // 0x801799A4: b           L_801799B8
    // 0x801799A8: neg.s       $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f20.fl = -ctx->f18.fl;
        goto L_801799B8;
    // 0x801799A8: neg.s       $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f20.fl = -ctx->f18.fl;
L_801799AC:
    // 0x801799AC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x801799B0: addiu       $t2, $t2, -0x2BA8
    ctx->r10 = ADD32(ctx->r10, -0X2BA8);
    // 0x801799B4: lwc1        $f20, 0x12C($t2)
    ctx->f20.u32l = MEM_W(ctx->r10, 0X12C);
L_801799B8:
    // 0x801799B8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801799BC: lwc1        $f10, -0x2B20($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2B20);
    // 0x801799C0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x801799C4: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x801799C8: add.s       $f6, $f10, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f20.fl;
    // 0x801799CC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x801799D0: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x801799D4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801799D8: swc1        $f6, -0x2B20($at)
    MEM_W(-0X2B20, ctx->r1) = ctx->f6.u32l;
    // 0x801799DC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801799E0: lwc1        $f8, -0x2B24($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2B24);
    // 0x801799E4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801799E8: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x801799EC: swc1        $f8, 0xC8($t3)
    MEM_W(0XC8, ctx->r11) = ctx->f8.u32l;
    // 0x801799F0: lwc1        $f4, -0x2B20($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2B20);
    // 0x801799F4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801799F8: swc1        $f4, 0xCC($t4)
    MEM_W(0XCC, ctx->r12) = ctx->f4.u32l;
    // 0x801799FC: lwc1        $f16, -0x2B1C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2B1C);
    // 0x80179A00: jal         0x80199214
    // 0x80179A04: swc1        $f16, 0xD0($t7)
    MEM_W(0XD0, ctx->r15) = ctx->f16.u32l;
    func_80199214_1501A0(rdram, ctx);
        goto after_11;
    // 0x80179A04: swc1        $f16, 0xD0($t7)
    MEM_W(0XD0, ctx->r15) = ctx->f16.u32l;
    after_11:
    // 0x80179A08: beq         $v0, $zero, L_80179A68
    if (ctx->r2 == 0) {
        // 0x80179A0C: nop
    
            goto L_80179A68;
    }
    // 0x80179A0C: nop

    // 0x80179A10: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80179A14: addiu       $t8, $t8, -0x2BA8
    ctx->r24 = ADD32(ctx->r24, -0X2BA8);
    // 0x80179A18: lwc1        $f18, 0x12C($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X12C);
    // 0x80179A1C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80179A20: nop

    // 0x80179A24: c.lt.s      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.fl < ctx->f10.fl;
    // 0x80179A28: nop

    // 0x80179A2C: bc1f        L_80179A3C
    if (!c1cs) {
        // 0x80179A30: nop
    
            goto L_80179A3C;
    }
    // 0x80179A30: nop

    // 0x80179A34: b           L_80179A48
    // 0x80179A38: neg.s       $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f20.fl = -ctx->f18.fl;
        goto L_80179A48;
    // 0x80179A38: neg.s       $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f20.fl = -ctx->f18.fl;
L_80179A3C:
    // 0x80179A3C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80179A40: addiu       $t5, $t5, -0x2BA8
    ctx->r13 = ADD32(ctx->r13, -0X2BA8);
    // 0x80179A44: lwc1        $f20, 0x12C($t5)
    ctx->f20.u32l = MEM_W(ctx->r13, 0X12C);
L_80179A48:
    // 0x80179A48: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80179A4C: lwc1        $f6, -0x2B20($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2B20);
    // 0x80179A50: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80179A54: sub.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f20.fl;
    // 0x80179A58: jal         0x80179100
    // 0x80179A5C: swc1        $f8, -0x2B20($at)
    MEM_W(-0X2B20, ctx->r1) = ctx->f8.u32l;
    func_80179100_1501A0(rdram, ctx);
        goto after_12;
    // 0x80179A5C: swc1        $f8, -0x2B20($at)
    MEM_W(-0X2B20, ctx->r1) = ctx->f8.u32l;
    after_12:
    // 0x80179A60: b           L_80179A80
    // 0x80179A64: nop

        goto L_80179A80;
    // 0x80179A64: nop

L_80179A68:
    // 0x80179A68: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80179A6C: addiu       $t6, $t6, -0x2BA8
    ctx->r14 = ADD32(ctx->r14, -0X2BA8);
    // 0x80179A70: lw          $t9, 0xEC($t6)
    ctx->r25 = MEM_W(ctx->r14, 0XEC);
    // 0x80179A74: sltiu       $at, $t9, 0x5
    ctx->r1 = ctx->r25 < 0X5 ? 1 : 0;
    // 0x80179A78: bne         $at, $zero, L_80179978
    if (ctx->r1 != 0) {
        // 0x80179A7C: nop
    
            goto L_80179978;
    }
    // 0x80179A7C: nop

L_80179A80:
    // 0x80179A80: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80179A84: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80179A88: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80179A8C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80179A90: addiu       $t0, $t0, -0x4198
    ctx->r8 = ADD32(ctx->r8, -0X4198);
    // 0x80179A94: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80179A98: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80179A9C: addiu       $t1, $t1, -0x4198
    ctx->r9 = ADD32(ctx->r9, -0X4198);
    // 0x80179AA0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80179AA4: swc1        $f4, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->f4.u32l;
    // 0x80179AA8: addiu       $t2, $t2, -0x4198
    ctx->r10 = ADD32(ctx->r10, -0X4198);
    // 0x80179AAC: swc1        $f16, 0x1C($t1)
    MEM_W(0X1C, ctx->r9) = ctx->f16.u32l;
    // 0x80179AB0: jal         0x800C3FD0
    // 0x80179AB4: swc1        $f10, 0x18($t2)
    MEM_W(0X18, ctx->r10) = ctx->f10.u32l;
    func_800C3FD0(rdram, ctx);
        goto after_13;
    // 0x80179AB4: swc1        $f10, 0x18($t2)
    MEM_W(0X18, ctx->r10) = ctx->f10.u32l;
    after_13:
    // 0x80179AB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80179ABC: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80179AC0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80179AC4: jr          $ra
    // 0x80179AC8: nop

    return;
    // 0x80179AC8: nop

;}
RECOMP_FUNC void func_80179ACC_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80179ACC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80179AD0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80179AD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80179AD8: addiu       $t6, $t6, -0x2BA8
    ctx->r14 = ADD32(ctx->r14, -0X2BA8);
    // 0x80179ADC: lw          $t7, 0x10C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10C);
    // 0x80179AE0: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80179AE4: bne         $t8, $zero, L_80179B14
    if (ctx->r24 != 0) {
        // 0x80179AE8: nop
    
            goto L_80179B14;
    }
    // 0x80179AE8: nop

    // 0x80179AEC: jal         0x800C32CC
    // 0x80179AF0: nop

    func_800C32CC(rdram, ctx);
        goto after_0;
    // 0x80179AF0: nop

    after_0:
    // 0x80179AF4: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80179AF8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80179AFC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80179B00: sw          $t9, -0x2E4C($at)
    MEM_W(-0X2E4C, ctx->r1) = ctx->r25;
    // 0x80179B04: addiu       $t0, $t0, -0x2BA8
    ctx->r8 = ADD32(ctx->r8, -0X2BA8);
    // 0x80179B08: lw          $t1, 0x10C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X10C);
    // 0x80179B0C: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80179B10: sw          $t2, 0x10C($t0)
    MEM_W(0X10C, ctx->r8) = ctx->r10;
L_80179B14:
    // 0x80179B14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80179B18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80179B1C: jr          $ra
    // 0x80179B20: nop

    return;
    // 0x80179B20: nop

;}
RECOMP_FUNC void func_80179B24_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80179B24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80179B28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80179B2C: jal         0x80179ACC
    // 0x80179B30: nop

    func_80179ACC_1501A0(rdram, ctx);
        goto after_0;
    // 0x80179B30: nop

    after_0:
    // 0x80179B34: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80179B38: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80179B3C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80179B40: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80179B44: addiu       $t6, $t6, -0x2BA8
    ctx->r14 = ADD32(ctx->r14, -0X2BA8);
    // 0x80179B48: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80179B4C: addiu       $t7, $t7, -0x2BA8
    ctx->r15 = ADD32(ctx->r15, -0X2BA8);
    // 0x80179B50: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80179B54: swc1        $f4, 0x128($t6)
    MEM_W(0X128, ctx->r14) = ctx->f4.u32l;
    // 0x80179B58: addiu       $t8, $t8, -0x2BA8
    ctx->r24 = ADD32(ctx->r24, -0X2BA8);
    // 0x80179B5C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80179B60: swc1        $f6, 0x12C($t7)
    MEM_W(0X12C, ctx->r15) = ctx->f6.u32l;
    // 0x80179B64: addiu       $t0, $t0, -0x2BA8
    ctx->r8 = ADD32(ctx->r8, -0X2BA8);
    // 0x80179B68: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x80179B6C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80179B70: swc1        $f8, 0x130($t8)
    MEM_W(0X130, ctx->r24) = ctx->f8.u32l;
    // 0x80179B74: sw          $t9, 0xFC($t0)
    MEM_W(0XFC, ctx->r8) = ctx->r25;
    // 0x80179B78: addiu       $t1, $t1, -0x2BA8
    ctx->r9 = ADD32(ctx->r9, -0X2BA8);
    // 0x80179B7C: sw          $zero, 0x100($t1)
    MEM_W(0X100, ctx->r9) = 0;
    // 0x80179B80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80179B84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80179B88: jr          $ra
    // 0x80179B8C: nop

    return;
    // 0x80179B8C: nop

;}
RECOMP_FUNC void func_80179B90_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80179B90: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80179B94: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80179B98: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    // 0x80179B9C: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80179BA0: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80179BA4: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80179BA8: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80179BAC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80179BB0: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80179BB4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80179BB8: mul.s       $f16, $f10, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80179BBC: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x80179BC0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80179BC4: mul.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x80179BC8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80179BCC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80179BD0: addiu       $a0, $a0, -0x2BA8
    ctx->r4 = ADD32(ctx->r4, -0X2BA8);
    // 0x80179BD4: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80179BD8: addiu       $t7, $t6, 0xC8
    ctx->r15 = ADD32(ctx->r14, 0XC8);
    // 0x80179BDC: addiu       $t8, $t6, 0xCC
    ctx->r24 = ADD32(ctx->r14, 0XCC);
    // 0x80179BE0: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x80179BE4: addiu       $t9, $t6, 0xD0
    ctx->r25 = ADD32(ctx->r14, 0XD0);
    // 0x80179BE8: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80179BEC: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80179BF0: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80179BF4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80179BF8: jal         0x800D6E90
    // 0x80179BFC: addiu       $a0, $a0, 0xA0
    ctx->r4 = ADD32(ctx->r4, 0XA0);
    guMtxXFMF_recomp(rdram, ctx);
        goto after_0;
    // 0x80179BFC: addiu       $a0, $a0, 0xA0
    ctx->r4 = ADD32(ctx->r4, 0XA0);
    after_0:
    // 0x80179C00: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80179C04: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x80179C08: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80179C0C: lwc1        $f10, -0x2B24($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2B24);
    // 0x80179C10: lwc1        $f8, 0xC8($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0XC8);
    // 0x80179C14: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80179C18: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x80179C1C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80179C20: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80179C24: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80179C28: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x80179C2C: swc1        $f16, 0xC8($t0)
    MEM_W(0XC8, ctx->r8) = ctx->f16.u32l;
    // 0x80179C30: lwc1        $f18, 0xCC($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0XCC);
    // 0x80179C34: lwc1        $f6, -0x2B20($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2B20);
    // 0x80179C38: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80179C3C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80179C40: add.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80179C44: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x80179C48: swc1        $f4, 0xCC($t1)
    MEM_W(0XCC, ctx->r9) = ctx->f4.u32l;
    // 0x80179C4C: lwc1        $f8, 0xD0($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0XD0);
    // 0x80179C50: lwc1        $f10, -0x2B1C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2B1C);
    // 0x80179C54: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80179C58: swc1        $f16, 0xD0($t2)
    MEM_W(0XD0, ctx->r10) = ctx->f16.u32l;
    // 0x80179C5C: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80179C60: lwc1        $f18, 0xCC($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0XCC);
    // 0x80179C64: lw          $a3, 0xD0($t3)
    ctx->r7 = MEM_W(ctx->r11, 0XD0);
    // 0x80179C68: lw          $a1, 0xC8($t3)
    ctx->r5 = MEM_W(ctx->r11, 0XC8);
    // 0x80179C6C: add.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80179C70: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80179C74: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80179C78: jal         0x8018AB30
    // 0x80179C7C: nop

    func_8018AB30_1501A0(rdram, ctx);
        goto after_1;
    // 0x80179C7C: nop

    after_1:
    // 0x80179C80: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80179C84: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80179C88: jr          $ra
    // 0x80179C8C: nop

    return;
    // 0x80179C8C: nop

;}
RECOMP_FUNC void func_80179C90_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80179C90: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80179C94: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80179C98: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80179C9C: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    // 0x80179CA0: addiu       $t6, $t6, -0x2BA8
    ctx->r14 = ADD32(ctx->r14, -0X2BA8);
    // 0x80179CA4: lw          $t7, 0x10C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10C);
    // 0x80179CA8: andi        $t8, $t7, 0x10
    ctx->r24 = ctx->r15 & 0X10;
    // 0x80179CAC: bne         $t8, $zero, L_80179E2C
    if (ctx->r24 != 0) {
        // 0x80179CB0: nop
    
            goto L_80179E2C;
    }
    // 0x80179CB0: nop

    // 0x80179CB4: jal         0x800E4CDC
    // 0x80179CB8: nop

    func_800E4CDC(rdram, ctx);
        goto after_0;
    // 0x80179CB8: nop

    after_0:
    // 0x80179CBC: addiu       $at, $zero, 0xFFF
    ctx->r1 = ADD32(0, 0XFFF);
    // 0x80179CC0: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x80179CC4: mflo        $t9
    ctx->r25 = lo;
    // 0x80179CC8: andi        $t0, $t9, 0x7
    ctx->r8 = ctx->r25 & 0X7;
    // 0x80179CCC: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x80179CD0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80179CD4: lwc1        $f8, -0x460($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X460);
    // 0x80179CD8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80179CDC: lwc1        $f16, 0x20($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80179CE0: lui         $at, 0xC090
    ctx->r1 = S32(0XC090 << 16);
    // 0x80179CE4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80179CE8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80179CEC: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x80179CF0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80179CF4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80179CF8: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x80179CFC: lui         $a3, 0x3F4C
    ctx->r7 = S32(0X3F4C << 16);
    // 0x80179D00: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80179D04: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    // 0x80179D08: lui         $a2, 0x4020
    ctx->r6 = S32(0X4020 << 16);
    // 0x80179D0C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80179D10: swc1        $f18, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f18.u32l;
    // 0x80179D14: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80179D18: lwc1        $f6, 0x0($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X0);
    // 0x80179D1C: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80179D20: jal         0x80179B90
    // 0x80179D24: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_80179B90_1501A0(rdram, ctx);
        goto after_1;
    // 0x80179D24: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x80179D28: lui         $at, 0xC090
    ctx->r1 = S32(0XC090 << 16);
    // 0x80179D2C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80179D30: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80179D34: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x80179D38: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x80179D3C: lwc1        $f10, 0x0($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X0);
    // 0x80179D40: lui         $a3, 0x3F4C
    ctx->r7 = S32(0X3F4C << 16);
    // 0x80179D44: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80179D48: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80179D4C: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    // 0x80179D50: lui         $a2, 0xC020
    ctx->r6 = S32(0XC020 << 16);
    // 0x80179D54: jal         0x80179B90
    // 0x80179D58: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    func_80179B90_1501A0(rdram, ctx);
        goto after_2;
    // 0x80179D58: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_2:
    // 0x80179D5C: lui         $at, 0xC110
    ctx->r1 = S32(0XC110 << 16);
    // 0x80179D60: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80179D64: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80179D68: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x80179D6C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x80179D70: lwc1        $f18, 0x0($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X0);
    // 0x80179D74: lui         $a3, 0xBF66
    ctx->r7 = S32(0XBF66 << 16);
    // 0x80179D78: ori         $a3, $a3, 0x6666
    ctx->r7 = ctx->r7 | 0X6666;
    // 0x80179D7C: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80179D80: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    // 0x80179D84: lui         $a2, 0x40B0
    ctx->r6 = S32(0X40B0 << 16);
    // 0x80179D88: jal         0x80179B90
    // 0x80179D8C: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    func_80179B90_1501A0(rdram, ctx);
        goto after_3;
    // 0x80179D8C: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_3:
    // 0x80179D90: lui         $at, 0xC110
    ctx->r1 = S32(0XC110 << 16);
    // 0x80179D94: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80179D98: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80179D9C: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x80179DA0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80179DA4: lwc1        $f6, 0x0($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X0);
    // 0x80179DA8: lui         $a3, 0xBF66
    ctx->r7 = S32(0XBF66 << 16);
    // 0x80179DAC: ori         $a3, $a3, 0x6666
    ctx->r7 = ctx->r7 | 0X6666;
    // 0x80179DB0: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80179DB4: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    // 0x80179DB8: lui         $a2, 0xC0B0
    ctx->r6 = S32(0XC0B0 << 16);
    // 0x80179DBC: jal         0x80179B90
    // 0x80179DC0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_80179B90_1501A0(rdram, ctx);
        goto after_4;
    // 0x80179DC0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_4:
    // 0x80179DC4: lui         $at, 0xC118
    ctx->r1 = S32(0XC118 << 16);
    // 0x80179DC8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80179DCC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80179DD0: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x80179DD4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x80179DD8: lwc1        $f10, 0x0($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X0);
    // 0x80179DDC: lui         $a3, 0x3F4C
    ctx->r7 = S32(0X3F4C << 16);
    // 0x80179DE0: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80179DE4: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80179DE8: addiu       $a1, $zero, 0x2B
    ctx->r5 = ADD32(0, 0X2B);
    // 0x80179DEC: lui         $a2, 0x4020
    ctx->r6 = S32(0X4020 << 16);
    // 0x80179DF0: jal         0x80179B90
    // 0x80179DF4: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    func_80179B90_1501A0(rdram, ctx);
        goto after_5;
    // 0x80179DF4: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_5:
    // 0x80179DF8: lui         $at, 0xC118
    ctx->r1 = S32(0XC118 << 16);
    // 0x80179DFC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80179E00: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80179E04: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x80179E08: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x80179E0C: lwc1        $f18, 0x0($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0X0);
    // 0x80179E10: lui         $a3, 0x3F4C
    ctx->r7 = S32(0X3F4C << 16);
    // 0x80179E14: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80179E18: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80179E1C: addiu       $a1, $zero, 0x2B
    ctx->r5 = ADD32(0, 0X2B);
    // 0x80179E20: lui         $a2, 0xC020
    ctx->r6 = S32(0XC020 << 16);
    // 0x80179E24: jal         0x80179B90
    // 0x80179E28: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    func_80179B90_1501A0(rdram, ctx);
        goto after_6;
    // 0x80179E28: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_6:
L_80179E2C:
    // 0x80179E2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80179E30: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80179E34: jr          $ra
    // 0x80179E38: nop

    return;
    // 0x80179E38: nop

;}
RECOMP_FUNC void func_80179E3C_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80179E3C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80179E40: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80179E44: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80179E48: swc1        $f12, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f12.u32l;
    // 0x80179E4C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80179E50: addiu       $t6, $t6, -0x2BA8
    ctx->r14 = ADD32(ctx->r14, -0X2BA8);
    // 0x80179E54: lw          $t7, 0x100($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X100);
    // 0x80179E58: andi        $t8, $t7, 0x2
    ctx->r24 = ctx->r15 & 0X2;
    // 0x80179E5C: beq         $t8, $zero, L_80179E6C
    if (ctx->r24 == 0) {
        // 0x80179E60: nop
    
            goto L_80179E6C;
    }
    // 0x80179E60: nop

    // 0x80179E64: jal         0x80179C90
    // 0x80179E68: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    func_80179C90_1501A0(rdram, ctx);
        goto after_0;
    // 0x80179E68: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    after_0:
L_80179E6C:
    // 0x80179E6C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80179E70: addiu       $t9, $t9, -0x2BA8
    ctx->r25 = ADD32(ctx->r25, -0X2BA8);
    // 0x80179E74: lw          $t0, 0x10C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X10C);
    // 0x80179E78: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x80179E7C: bne         $t1, $zero, L_8017A018
    if (ctx->r9 != 0) {
        // 0x80179E80: nop
    
            goto L_8017A018;
    }
    // 0x80179E80: nop

    // 0x80179E84: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80179E88: addiu       $t2, $t2, -0x2BA8
    ctx->r10 = ADD32(ctx->r10, -0X2BA8);
    // 0x80179E8C: lw          $t3, 0x10C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X10C);
    // 0x80179E90: andi        $t4, $t3, 0x4
    ctx->r12 = ctx->r11 & 0X4;
    // 0x80179E94: bne         $t4, $zero, L_8017A018
    if (ctx->r12 != 0) {
        // 0x80179E98: nop
    
            goto L_8017A018;
    }
    // 0x80179E98: nop

    // 0x80179E9C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80179EA0: addiu       $t5, $t5, -0x2BA8
    ctx->r13 = ADD32(ctx->r13, -0X2BA8);
    // 0x80179EA4: lw          $t6, 0x100($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X100);
    // 0x80179EA8: andi        $t7, $t6, 0xF
    ctx->r15 = ctx->r14 & 0XF;
    // 0x80179EAC: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80179EB0: bgez        $t7, L_80179EC8
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80179EB4: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80179EC8;
    }
    // 0x80179EB4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80179EB8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80179EBC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80179EC0: nop

    // 0x80179EC4: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80179EC8:
    // 0x80179EC8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80179ECC: lwc1        $f10, -0x45C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X45C);
    // 0x80179ED0: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80179ED4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80179ED8: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80179EDC: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x80179EE0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80179EE4: addiu       $t9, $t9, -0x2BA8
    ctx->r25 = ADD32(ctx->r25, -0X2BA8);
    // 0x80179EE8: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80179EEC: swc1        $f4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f4.u32l;
    // 0x80179EF0: lw          $s0, 0x100($t9)
    ctx->r16 = MEM_W(ctx->r25, 0X100);
    // 0x80179EF4: andi        $t0, $s0, 0x7
    ctx->r8 = ctx->r16 & 0X7;
    // 0x80179EF8: or          $s0, $t0, $zero
    ctx->r16 = ctx->r8 | 0;
    // 0x80179EFC: beq         $s0, $zero, L_80179F24
    if (ctx->r16 == 0) {
        // 0x80179F00: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80179F24;
    }
    // 0x80179F00: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80179F04: beq         $s0, $at, L_80179F60
    if (ctx->r16 == ctx->r1) {
        // 0x80179F08: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80179F60;
    }
    // 0x80179F08: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80179F0C: beq         $s0, $at, L_80179F9C
    if (ctx->r16 == ctx->r1) {
        // 0x80179F10: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_80179F9C;
    }
    // 0x80179F10: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80179F14: beq         $s0, $at, L_80179FD4
    if (ctx->r16 == ctx->r1) {
        // 0x80179F18: nop
    
            goto L_80179FD4;
    }
    // 0x80179F18: nop

    // 0x80179F1C: b           L_8017A018
    // 0x80179F20: nop

        goto L_8017A018;
    // 0x80179F20: nop

L_80179F24:
    // 0x80179F24: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x80179F28: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80179F2C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80179F30: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x80179F34: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x80179F38: lwc1        $f6, 0x0($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X0);
    // 0x80179F3C: lui         $a3, 0x3F4C
    ctx->r7 = S32(0X3F4C << 16);
    // 0x80179F40: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80179F44: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80179F48: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x80179F4C: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    // 0x80179F50: jal         0x80179B90
    // 0x80179F54: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_80179B90_1501A0(rdram, ctx);
        goto after_1;
    // 0x80179F54: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x80179F58: b           L_8017A018
    // 0x80179F5C: nop

        goto L_8017A018;
    // 0x80179F5C: nop

L_80179F60:
    // 0x80179F60: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x80179F64: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80179F68: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80179F6C: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x80179F70: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80179F74: lwc1        $f16, 0x0($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X0);
    // 0x80179F78: lui         $a3, 0x3F4C
    ctx->r7 = S32(0X3F4C << 16);
    // 0x80179F7C: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80179F80: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80179F84: addiu       $a1, $zero, 0x29
    ctx->r5 = ADD32(0, 0X29);
    // 0x80179F88: lui         $a2, 0xC000
    ctx->r6 = S32(0XC000 << 16);
    // 0x80179F8C: jal         0x80179B90
    // 0x80179F90: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    func_80179B90_1501A0(rdram, ctx);
        goto after_2;
    // 0x80179F90: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    after_2:
    // 0x80179F94: b           L_8017A018
    // 0x80179F98: nop

        goto L_8017A018;
    // 0x80179F98: nop

L_80179F9C:
    // 0x80179F9C: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x80179FA0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80179FA4: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80179FA8: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x80179FAC: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x80179FB0: lwc1        $f4, 0x0($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X0);
    // 0x80179FB4: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80179FB8: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x80179FBC: lui         $a2, 0x40B0
    ctx->r6 = S32(0X40B0 << 16);
    // 0x80179FC0: lui         $a3, 0x3FC0
    ctx->r7 = S32(0X3FC0 << 16);
    // 0x80179FC4: jal         0x80179B90
    // 0x80179FC8: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    func_80179B90_1501A0(rdram, ctx);
        goto after_3;
    // 0x80179FC8: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x80179FCC: b           L_8017A018
    // 0x80179FD0: nop

        goto L_8017A018;
    // 0x80179FD0: nop

L_80179FD4:
    // 0x80179FD4: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x80179FD8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80179FDC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80179FE0: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x80179FE4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x80179FE8: lwc1        $f6, 0x0($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X0);
    // 0x80179FEC: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80179FF0: addiu       $a1, $zero, 0x29
    ctx->r5 = ADD32(0, 0X29);
    // 0x80179FF4: lui         $a2, 0xC0B0
    ctx->r6 = S32(0XC0B0 << 16);
    // 0x80179FF8: lui         $a3, 0x3FC0
    ctx->r7 = S32(0X3FC0 << 16);
    // 0x80179FFC: jal         0x80179B90
    // 0x8017A000: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_80179B90_1501A0(rdram, ctx);
        goto after_4;
    // 0x8017A000: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_4:
    // 0x8017A004: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017A008: addiu       $t5, $t5, -0x2BA8
    ctx->r13 = ADD32(ctx->r13, -0X2BA8);
    // 0x8017A00C: lw          $t6, 0x10C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X10C);
    // 0x8017A010: ori         $t7, $t6, 0x4
    ctx->r15 = ctx->r14 | 0X4;
    // 0x8017A014: sw          $t7, 0x10C($t5)
    MEM_W(0X10C, ctx->r13) = ctx->r15;
L_8017A018:
    // 0x8017A018: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8017A01C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8017A020: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8017A024: jr          $ra
    // 0x8017A028: nop

    return;
    // 0x8017A028: nop

;}
RECOMP_FUNC void func_8017A02C_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017A02C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017A030: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017A034: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017A038: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    // 0x8017A03C: addiu       $t6, $t6, -0x2BA8
    ctx->r14 = ADD32(ctx->r14, -0X2BA8);
    // 0x8017A040: lw          $t7, 0x10C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10C);
    // 0x8017A044: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x8017A048: bne         $t8, $zero, L_8017A214
    if (ctx->r24 != 0) {
        // 0x8017A04C: nop
    
            goto L_8017A214;
    }
    // 0x8017A04C: nop

    // 0x8017A050: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017A054: addiu       $t9, $t9, -0x2BA8
    ctx->r25 = ADD32(ctx->r25, -0X2BA8);
    // 0x8017A058: lw          $t0, 0x100($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X100);
    // 0x8017A05C: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x8017A060: bgez        $t0, L_8017A078
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8017A064: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8017A078;
    }
    // 0x8017A064: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8017A068: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8017A06C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8017A070: nop

    // 0x8017A074: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8017A078:
    // 0x8017A078: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8017A07C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017A080: lwc1        $f18, 0x20($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8017A084: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017A088: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8017A08C: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x8017A090: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8017A094: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017A098: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x8017A09C: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8017A0A0: swc1        $f4, 0x34($t1)
    MEM_W(0X34, ctx->r9) = ctx->f4.u32l;
    // 0x8017A0A4: lwc1        $f8, -0x458($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X458);
    // 0x8017A0A8: swc1        $f8, 0x54($t2)
    MEM_W(0X54, ctx->r10) = ctx->f8.u32l;
    // 0x8017A0AC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_8017A0B0:
    // 0x8017A0B0: jal         0x800E4CDC
    // 0x8017A0B4: nop

    func_800E4CDC(rdram, ctx);
        goto after_0;
    // 0x8017A0B4: nop

    after_0:
    // 0x8017A0B8: andi        $t3, $v0, 0x3
    ctx->r11 = ctx->r2 & 0X3;
    // 0x8017A0BC: bne         $t3, $zero, L_8017A200
    if (ctx->r11 != 0) {
        // 0x8017A0C0: nop
    
            goto L_8017A200;
    }
    // 0x8017A0C0: nop

    // 0x8017A0C4: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8017A0C8: lui         $at, 0x41B4
    ctx->r1 = S32(0X41B4 << 16);
    // 0x8017A0CC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8017A0D0: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x8017A0D4: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017A0D8: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x8017A0DC: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8017A0E0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017A0E4: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x8017A0E8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8017A0EC: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8017A0F0: swc1        $f18, 0x28($t5)
    MEM_W(0X28, ctx->r13) = ctx->f18.u32l;
    // 0x8017A0F4: lwc1        $f8, -0x454($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X454);
    // 0x8017A0F8: lwc1        $f4, 0x28($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X28);
    // 0x8017A0FC: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8017A100: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017A104: mul.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8017A108: jal         0x800D6AB0
    // 0x8017A10C: div.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    __cosf_recomp(rdram, ctx);
        goto after_1;
    // 0x8017A10C: div.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    after_1:
    // 0x8017A110: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017A114: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x8017A118: swc1        $f0, 0x2C($t7)
    MEM_W(0X2C, ctx->r15) = ctx->f0.u32l;
    // 0x8017A11C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017A120: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x8017A124: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8017A128: lwc1        $f18, -0x450($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X450);
    // 0x8017A12C: lwc1        $f16, 0x28($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X28);
    // 0x8017A130: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8017A134: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8017A138: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8017A13C: jal         0x800D68F0
    // 0x8017A140: div.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    sinf_recomp(rdram, ctx);
        goto after_2;
    // 0x8017A140: div.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    after_2:
    // 0x8017A144: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017A148: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x8017A14C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017A150: swc1        $f0, 0x30($t9)
    MEM_W(0X30, ctx->r25) = ctx->f0.u32l;
    // 0x8017A154: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x8017A158: lwc1        $f6, 0x34($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X34);
    // 0x8017A15C: lwc1        $f10, 0x2C($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X2C);
    // 0x8017A160: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017A164: lwc1        $f18, -0x2B24($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2B24);
    // 0x8017A168: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8017A16C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017A170: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x8017A174: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017A178: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017A17C: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x8017A180: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017A184: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8017A188: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x8017A18C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017A190: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x8017A194: swc1        $f4, 0x50($t0)
    MEM_W(0X50, ctx->r8) = ctx->f4.u32l;
    // 0x8017A198: lwc1        $f6, 0x30($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X30);
    // 0x8017A19C: lwc1        $f8, 0x34($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X34);
    // 0x8017A1A0: lwc1        $f16, -0x2B1C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2B1C);
    // 0x8017A1A4: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8017A1A8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8017A1AC: swc1        $f18, 0x58($t1)
    MEM_W(0X58, ctx->r9) = ctx->f18.u32l;
    // 0x8017A1B0: lwc1        $f4, 0x50($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X50);
    // 0x8017A1B4: swc1        $f4, 0xC8($t2)
    MEM_W(0XC8, ctx->r10) = ctx->f4.u32l;
    // 0x8017A1B8: lwc1        $f8, 0x54($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X54);
    // 0x8017A1BC: swc1        $f8, 0xCC($t3)
    MEM_W(0XCC, ctx->r11) = ctx->f8.u32l;
    // 0x8017A1C0: lwc1        $f6, 0x58($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X58);
    // 0x8017A1C4: jal         0x80199214
    // 0x8017A1C8: swc1        $f6, 0xD0($t4)
    MEM_W(0XD0, ctx->r12) = ctx->f6.u32l;
    func_80199214_1501A0(rdram, ctx);
        goto after_3;
    // 0x8017A1C8: swc1        $f6, 0xD0($t4)
    MEM_W(0XD0, ctx->r12) = ctx->f6.u32l;
    after_3:
    // 0x8017A1CC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017A1D0: addiu       $t5, $t5, 0x3B00
    ctx->r13 = ADD32(ctx->r13, 0X3B00);
    // 0x8017A1D4: lbu         $t6, 0x0($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X0);
    // 0x8017A1D8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8017A1DC: bne         $t6, $at, L_8017A200
    if (ctx->r14 != ctx->r1) {
        // 0x8017A1E0: nop
    
            goto L_8017A200;
    }
    // 0x8017A1E0: nop

    // 0x8017A1E4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017A1E8: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x8017A1EC: lw          $a1, 0x50($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X50);
    // 0x8017A1F0: lw          $a2, 0x54($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X54);
    // 0x8017A1F4: lw          $a3, 0x58($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X58);
    // 0x8017A1F8: jal         0x8018AB30
    // 0x8017A1FC: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    func_8018AB30_1501A0(rdram, ctx);
        goto after_4;
    // 0x8017A1FC: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_4:
L_8017A200:
    // 0x8017A200: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8017A204: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8017A208: slti        $at, $t9, 0x10
    ctx->r1 = SIGNED(ctx->r25) < 0X10 ? 1 : 0;
    // 0x8017A20C: bne         $at, $zero, L_8017A0B0
    if (ctx->r1 != 0) {
        // 0x8017A210: sw          $t9, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r25;
            goto L_8017A0B0;
    }
    // 0x8017A210: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
L_8017A214:
    // 0x8017A214: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017A218: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017A21C: jr          $ra
    // 0x8017A220: nop

    return;
    // 0x8017A220: nop

;}
RECOMP_FUNC void func_8017A224_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017A224: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017A228: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017A22C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017A230: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    // 0x8017A234: addiu       $t6, $t6, -0x2BA8
    ctx->r14 = ADD32(ctx->r14, -0X2BA8);
    // 0x8017A238: lw          $t7, 0x10C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10C);
    // 0x8017A23C: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x8017A240: bne         $t8, $zero, L_8017A438
    if (ctx->r24 != 0) {
        // 0x8017A244: nop
    
            goto L_8017A438;
    }
    // 0x8017A244: nop

    // 0x8017A248: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017A24C: addiu       $t9, $t9, -0x2BA8
    ctx->r25 = ADD32(ctx->r25, -0X2BA8);
    // 0x8017A250: lw          $t0, 0x100($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X100);
    // 0x8017A254: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x8017A258: bgez        $t0, L_8017A270
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8017A25C: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8017A270;
    }
    // 0x8017A25C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8017A260: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8017A264: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8017A268: nop

    // 0x8017A26C: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8017A270:
    // 0x8017A270: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8017A274: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017A278: lwc1        $f18, 0x20($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8017A27C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017A280: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8017A284: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x8017A288: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017A28C: addiu       $t2, $t2, -0x2BA8
    ctx->r10 = ADD32(ctx->r10, -0X2BA8);
    // 0x8017A290: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8017A294: swc1        $f4, 0x34($t1)
    MEM_W(0X34, ctx->r9) = ctx->f4.u32l;
    // 0x8017A298: lw          $t3, 0x100($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X100);
    // 0x8017A29C: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x8017A2A0: bgez        $t3, L_8017A2B8
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8017A2A4: cvt.s.w     $f6, $f8
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
            goto L_8017A2B8;
    }
    // 0x8017A2A4: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8017A2A8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8017A2AC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017A2B0: nop

    // 0x8017A2B4: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
L_8017A2B8:
    // 0x8017A2B8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8017A2BC: lwc1        $f16, -0x44C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X44C);
    // 0x8017A2C0: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8017A2C4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017A2C8: mul.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x8017A2CC: lwc1        $f10, -0x2B20($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2B20);
    // 0x8017A2D0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017A2D4: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x8017A2D8: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8017A2DC: sub.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x8017A2E0: swc1        $f6, 0x54($t4)
    MEM_W(0X54, ctx->r12) = ctx->f6.u32l;
    // 0x8017A2E4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_8017A2E8:
    // 0x8017A2E8: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x8017A2EC: lui         $at, 0x41B4
    ctx->r1 = S32(0X41B4 << 16);
    // 0x8017A2F0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017A2F4: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x8017A2F8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017A2FC: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x8017A300: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8017A304: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017A308: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x8017A30C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8017A310: mul.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8017A314: swc1        $f10, 0x28($t6)
    MEM_W(0X28, ctx->r14) = ctx->f10.u32l;
    // 0x8017A318: lwc1        $f6, -0x448($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X448);
    // 0x8017A31C: lwc1        $f8, 0x28($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X28);
    // 0x8017A320: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8017A324: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8017A328: mul.s       $f16, $f8, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8017A32C: jal         0x800D6AB0
    // 0x8017A330: div.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    __cosf_recomp(rdram, ctx);
        goto after_0;
    // 0x8017A330: div.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    after_0:
    // 0x8017A334: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017A338: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x8017A33C: swc1        $f0, 0x2C($t8)
    MEM_W(0X2C, ctx->r24) = ctx->f0.u32l;
    // 0x8017A340: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017A344: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x8017A348: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8017A34C: lwc1        $f10, -0x444($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X444);
    // 0x8017A350: lwc1        $f4, 0x28($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X28);
    // 0x8017A354: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8017A358: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017A35C: mul.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8017A360: jal         0x800D68F0
    // 0x8017A364: div.s       $f12, $f8, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = DIV_S(ctx->f8.fl, ctx->f6.fl);
    sinf_recomp(rdram, ctx);
        goto after_1;
    // 0x8017A364: div.s       $f12, $f8, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = DIV_S(ctx->f8.fl, ctx->f6.fl);
    after_1:
    // 0x8017A368: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017A36C: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x8017A370: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017A374: swc1        $f0, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->f0.u32l;
    // 0x8017A378: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x8017A37C: lwc1        $f16, 0x34($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X34);
    // 0x8017A380: lwc1        $f18, 0x2C($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X2C);
    // 0x8017A384: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017A388: lwc1        $f10, -0x2B24($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2B24);
    // 0x8017A38C: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8017A390: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017A394: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x8017A398: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017A39C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017A3A0: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x8017A3A4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017A3A8: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8017A3AC: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x8017A3B0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017A3B4: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x8017A3B8: swc1        $f8, 0x50($t1)
    MEM_W(0X50, ctx->r9) = ctx->f8.u32l;
    // 0x8017A3BC: lwc1        $f16, 0x30($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X30);
    // 0x8017A3C0: lwc1        $f6, 0x34($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X34);
    // 0x8017A3C4: lwc1        $f4, -0x2B1C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2B1C);
    // 0x8017A3C8: mul.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x8017A3CC: add.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8017A3D0: swc1        $f10, 0x58($t2)
    MEM_W(0X58, ctx->r10) = ctx->f10.u32l;
    // 0x8017A3D4: lwc1        $f8, 0x50($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X50);
    // 0x8017A3D8: swc1        $f8, 0xC8($t3)
    MEM_W(0XC8, ctx->r11) = ctx->f8.u32l;
    // 0x8017A3DC: lwc1        $f6, 0x54($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X54);
    // 0x8017A3E0: swc1        $f6, 0xCC($t4)
    MEM_W(0XCC, ctx->r12) = ctx->f6.u32l;
    // 0x8017A3E4: lwc1        $f16, 0x58($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0X58);
    // 0x8017A3E8: jal         0x80199214
    // 0x8017A3EC: swc1        $f16, 0xD0($t5)
    MEM_W(0XD0, ctx->r13) = ctx->f16.u32l;
    func_80199214_1501A0(rdram, ctx);
        goto after_2;
    // 0x8017A3EC: swc1        $f16, 0xD0($t5)
    MEM_W(0XD0, ctx->r13) = ctx->f16.u32l;
    after_2:
    // 0x8017A3F0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017A3F4: addiu       $t6, $t6, 0x3B00
    ctx->r14 = ADD32(ctx->r14, 0X3B00);
    // 0x8017A3F8: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x8017A3FC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8017A400: bne         $t7, $at, L_8017A424
    if (ctx->r15 != ctx->r1) {
        // 0x8017A404: nop
    
            goto L_8017A424;
    }
    // 0x8017A404: nop

    // 0x8017A408: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017A40C: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x8017A410: lw          $a1, 0x50($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X50);
    // 0x8017A414: lw          $a2, 0x54($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X54);
    // 0x8017A418: lw          $a3, 0x58($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X58);
    // 0x8017A41C: jal         0x8018AB30
    // 0x8017A420: addiu       $a0, $zero, 0x2F
    ctx->r4 = ADD32(0, 0X2F);
    func_8018AB30_1501A0(rdram, ctx);
        goto after_3;
    // 0x8017A420: addiu       $a0, $zero, 0x2F
    ctx->r4 = ADD32(0, 0X2F);
    after_3:
L_8017A424:
    // 0x8017A424: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8017A428: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8017A42C: slti        $at, $t0, 0x10
    ctx->r1 = SIGNED(ctx->r8) < 0X10 ? 1 : 0;
    // 0x8017A430: bne         $at, $zero, L_8017A2E8
    if (ctx->r1 != 0) {
        // 0x8017A434: sw          $t0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r8;
            goto L_8017A2E8;
    }
    // 0x8017A434: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
L_8017A438:
    // 0x8017A438: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017A43C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017A440: jr          $ra
    // 0x8017A444: nop

    return;
    // 0x8017A444: nop

;}
RECOMP_FUNC void func_8017A448_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017A448: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017A44C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017A450: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017A454: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8017A458: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    // 0x8017A45C: addiu       $t6, $t6, -0x2BA8
    ctx->r14 = ADD32(ctx->r14, -0X2BA8);
    // 0x8017A460: lw          $t7, 0x10C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10C);
    // 0x8017A464: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x8017A468: bne         $t8, $zero, L_8017A6A4
    if (ctx->r24 != 0) {
        // 0x8017A46C: nop
    
            goto L_8017A6A4;
    }
    // 0x8017A46C: nop

    // 0x8017A470: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8017A474: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8017A478: bgez        $t9, L_8017A490
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8017A47C: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8017A490;
    }
    // 0x8017A47C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8017A480: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8017A484: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8017A488: nop

    // 0x8017A48C: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8017A490:
    // 0x8017A490: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8017A494: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017A498: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x8017A49C: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8017A4A0: swc1        $f16, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->f16.u32l;
    // 0x8017A4A4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_8017A4A8:
    // 0x8017A4A8: jal         0x800E4CDC
    // 0x8017A4AC: nop

    func_800E4CDC(rdram, ctx);
        goto after_0;
    // 0x8017A4AC: nop

    after_0:
    // 0x8017A4B0: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017A4B4: addiu       $t1, $t1, 0x3C00
    ctx->r9 = ADD32(ctx->r9, 0X3C00);
    // 0x8017A4B8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017A4BC: sw          $v0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r2;
    // 0x8017A4C0: addiu       $t2, $t2, 0x3C00
    ctx->r10 = ADD32(ctx->r10, 0X3C00);
    // 0x8017A4C4: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8017A4C8: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x8017A4CC: bgez        $t3, L_8017A4E4
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8017A4D0: cvt.s.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
            goto L_8017A4E4;
    }
    // 0x8017A4D0: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8017A4D4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8017A4D8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8017A4DC: nop

    // 0x8017A4E0: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
L_8017A4E4:
    // 0x8017A4E4: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x8017A4E8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017A4EC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8017A4F0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8017A4F4: div.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8017A4F8: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8017A4FC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017A500: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x8017A504: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017A508: addiu       $t5, $t5, 0x3C00
    ctx->r13 = ADD32(ctx->r13, 0X3C00);
    // 0x8017A50C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8017A510: nop

    // 0x8017A514: mul.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x8017A518: swc1        $f4, 0x5C($t4)
    MEM_W(0X5C, ctx->r12) = ctx->f4.u32l;
    // 0x8017A51C: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8017A520: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x8017A524: beq         $t7, $zero, L_8017A548
    if (ctx->r15 == 0) {
        // 0x8017A528: nop
    
            goto L_8017A548;
    }
    // 0x8017A528: nop

    // 0x8017A52C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017A530: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x8017A534: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8017A538: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017A53C: lwc1        $f6, 0x5C($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X5C);
    // 0x8017A540: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8017A544: swc1        $f16, 0x5C($t8)
    MEM_W(0X5C, ctx->r24) = ctx->f16.u32l;
L_8017A548:
    // 0x8017A548: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8017A54C: lui         $at, 0x4210
    ctx->r1 = S32(0X4210 << 16);
    // 0x8017A550: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017A554: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x8017A558: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017A55C: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x8017A560: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8017A564: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017A568: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x8017A56C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8017A570: mul.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8017A574: swc1        $f6, 0x28($t0)
    MEM_W(0X28, ctx->r8) = ctx->f6.u32l;
    // 0x8017A578: lwc1        $f16, -0x440($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X440);
    // 0x8017A57C: lwc1        $f10, 0x28($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X28);
    // 0x8017A580: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8017A584: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8017A588: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8017A58C: jal         0x800D6AB0
    // 0x8017A590: div.s       $f12, $f18, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = DIV_S(ctx->f18.fl, ctx->f8.fl);
    __cosf_recomp(rdram, ctx);
        goto after_1;
    // 0x8017A590: div.s       $f12, $f18, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = DIV_S(ctx->f18.fl, ctx->f8.fl);
    after_1:
    // 0x8017A594: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017A598: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x8017A59C: swc1        $f0, 0x2C($t2)
    MEM_W(0X2C, ctx->r10) = ctx->f0.u32l;
    // 0x8017A5A0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017A5A4: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x8017A5A8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8017A5AC: lwc1        $f6, -0x43C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X43C);
    // 0x8017A5B0: lwc1        $f4, 0x28($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X28);
    // 0x8017A5B4: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8017A5B8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8017A5BC: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8017A5C0: jal         0x800D68F0
    // 0x8017A5C4: div.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    sinf_recomp(rdram, ctx);
        goto after_2;
    // 0x8017A5C4: div.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    after_2:
    // 0x8017A5C8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017A5CC: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x8017A5D0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017A5D4: swc1        $f0, 0x30($t4)
    MEM_W(0X30, ctx->r12) = ctx->f0.u32l;
    // 0x8017A5D8: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x8017A5DC: lwc1        $f18, 0x34($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X34);
    // 0x8017A5E0: lwc1        $f8, 0x2C($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X2C);
    // 0x8017A5E4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017A5E8: lwc1        $f6, -0x2B24($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2B24);
    // 0x8017A5EC: mul.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x8017A5F0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017A5F4: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x8017A5F8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017A5FC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017A600: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x8017A604: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017A608: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8017A60C: addiu       $t8, $t8, 0x3C00
    ctx->r24 = ADD32(ctx->r24, 0X3C00);
    // 0x8017A610: swc1        $f10, 0x50($t5)
    MEM_W(0X50, ctx->r13) = ctx->f10.u32l;
    // 0x8017A614: lwc1        $f18, -0x2B20($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2B20);
    // 0x8017A618: lwc1        $f16, 0x5C($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X5C);
    // 0x8017A61C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017A620: add.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8017A624: swc1        $f8, 0x54($t6)
    MEM_W(0X54, ctx->r14) = ctx->f8.u32l;
    // 0x8017A628: lwc1        $f6, 0x30($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X30);
    // 0x8017A62C: lwc1        $f4, 0x34($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X34);
    // 0x8017A630: lwc1        $f16, -0x2B1C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2B1C);
    // 0x8017A634: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8017A638: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8017A63C: swc1        $f18, 0x58($t7)
    MEM_W(0X58, ctx->r15) = ctx->f18.u32l;
    // 0x8017A640: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8017A644: andi        $t0, $t9, 0x2
    ctx->r8 = ctx->r25 & 0X2;
    // 0x8017A648: beq         $t0, $zero, L_8017A674
    if (ctx->r8 == 0) {
        // 0x8017A64C: nop
    
            goto L_8017A674;
    }
    // 0x8017A64C: nop

    // 0x8017A650: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017A654: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x8017A658: lw          $a1, 0x50($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X50);
    // 0x8017A65C: lw          $a2, 0x54($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X54);
    // 0x8017A660: lw          $a3, 0x58($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X58);
    // 0x8017A664: jal         0x8018AB30
    // 0x8017A668: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    func_8018AB30_1501A0(rdram, ctx);
        goto after_3;
    // 0x8017A668: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    after_3:
    // 0x8017A66C: b           L_8017A690
    // 0x8017A670: nop

        goto L_8017A690;
    // 0x8017A670: nop

L_8017A674:
    // 0x8017A674: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017A678: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x8017A67C: lw          $a1, 0x50($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X50);
    // 0x8017A680: lw          $a2, 0x54($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X54);
    // 0x8017A684: lw          $a3, 0x58($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X58);
    // 0x8017A688: jal         0x8018AB30
    // 0x8017A68C: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    func_8018AB30_1501A0(rdram, ctx);
        goto after_4;
    // 0x8017A68C: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    after_4:
L_8017A690:
    // 0x8017A690: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x8017A694: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8017A698: slti        $at, $t4, 0xA
    ctx->r1 = SIGNED(ctx->r12) < 0XA ? 1 : 0;
    // 0x8017A69C: bne         $at, $zero, L_8017A4A8
    if (ctx->r1 != 0) {
        // 0x8017A6A0: sw          $t4, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r12;
            goto L_8017A4A8;
    }
    // 0x8017A6A0: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
L_8017A6A4:
    // 0x8017A6A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017A6A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017A6AC: jr          $ra
    // 0x8017A6B0: nop

    return;
    // 0x8017A6B0: nop

;}
RECOMP_FUNC void func_8017A6B4_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017A6B4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017A6B8: addiu       $t6, $t6, -0x2BA8
    ctx->r14 = ADD32(ctx->r14, -0X2BA8);
    // 0x8017A6BC: lw          $t7, 0x10C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10C);
    // 0x8017A6C0: ori         $t8, $t7, 0x10
    ctx->r24 = ctx->r15 | 0X10;
    // 0x8017A6C4: jr          $ra
    // 0x8017A6C8: sw          $t8, 0x10C($t6)
    MEM_W(0X10C, ctx->r14) = ctx->r24;
    return;
    // 0x8017A6C8: sw          $t8, 0x10C($t6)
    MEM_W(0X10C, ctx->r14) = ctx->r24;
;}
RECOMP_FUNC void func_8017A6CC_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017A6CC: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8017A6D0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017A6D4: lwc1        $f4, -0x2E30($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x8017A6D8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017A6DC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8017A6E0: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8017A6E4: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x8017A6E8: addiu       $t6, $t6, -0x2BA8
    ctx->r14 = ADD32(ctx->r14, -0X2BA8);
    // 0x8017A6EC: swc1        $f4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f4.u32l;
    // 0x8017A6F0: lw          $s0, 0xFC($t6)
    ctx->r16 = MEM_W(ctx->r14, 0XFC);
    // 0x8017A6F4: beq         $s0, $zero, L_8017A714
    if (ctx->r16 == 0) {
        // 0x8017A6F8: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8017A714;
    }
    // 0x8017A6F8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8017A6FC: beq         $s0, $at, L_8017AC7C
    if (ctx->r16 == ctx->r1) {
        // 0x8017A700: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_8017AC7C;
    }
    // 0x8017A700: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8017A704: beq         $s0, $at, L_8017ADA4
    if (ctx->r16 == ctx->r1) {
        // 0x8017A708: nop
    
            goto L_8017ADA4;
    }
    // 0x8017A708: nop

    // 0x8017A70C: b           L_8017ADB4
    // 0x8017A710: nop

        goto L_8017ADB4;
    // 0x8017A710: nop

L_8017A714:
    // 0x8017A714: jal         0x8017905C
    // 0x8017A718: nop

    func_8017905C_1501A0(rdram, ctx);
        goto after_0;
    // 0x8017A718: nop

    after_0:
    // 0x8017A71C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017A720: addiu       $t7, $t7, -0x2BA8
    ctx->r15 = ADD32(ctx->r15, -0X2BA8);
    // 0x8017A724: jal         0x8017840C
    // 0x8017A728: lwc1        $f12, 0x134($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X134);
    func_8017840C_1501A0(rdram, ctx);
        goto after_1;
    // 0x8017A728: lwc1        $f12, 0x134($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X134);
    after_1:
    // 0x8017A72C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017A730: addiu       $t8, $t8, -0x2BA8
    ctx->r24 = ADD32(ctx->r24, -0X2BA8);
    // 0x8017A734: lwc1        $f14, 0x128($t8)
    ctx->f14.u32l = MEM_W(ctx->r24, 0X128);
    // 0x8017A738: lw          $a2, 0x12C($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X12C);
    // 0x8017A73C: lw          $a3, 0x130($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X130);
    // 0x8017A740: jal         0x80178DA4
    // 0x8017A744: lwc1        $f12, 0x54($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X54);
    func_80178DA4_1501A0(rdram, ctx);
        goto after_2;
    // 0x8017A744: lwc1        $f12, 0x54($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X54);
    after_2:
    // 0x8017A748: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017A74C: addiu       $t9, $t9, -0x2BA8
    ctx->r25 = ADD32(ctx->r25, -0X2BA8);
    // 0x8017A750: sw          $v0, 0xF0($t9)
    MEM_W(0XF0, ctx->r25) = ctx->r2;
    // 0x8017A754: jal         0x80179E3C
    // 0x8017A758: lwc1        $f12, 0x54($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X54);
    func_80179E3C_1501A0(rdram, ctx);
        goto after_3;
    // 0x8017A758: lwc1        $f12, 0x54($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X54);
    after_3:
    // 0x8017A75C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017A760: addiu       $t0, $t0, -0x2BA8
    ctx->r8 = ADD32(ctx->r8, -0X2BA8);
    // 0x8017A764: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017A768: lwc1        $f6, -0x2B24($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2B24);
    // 0x8017A76C: lwc1        $f8, 0x128($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X128);
    // 0x8017A770: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8017A774: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8017A778: swc1        $f10, -0x2B24($at)
    MEM_W(-0X2B24, ctx->r1) = ctx->f10.u32l;
    // 0x8017A77C: lwc1        $f16, 0x12C($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X12C);
    // 0x8017A780: c.lt.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl < ctx->f16.fl;
    // 0x8017A784: nop

    // 0x8017A788: bc1f        L_8017A798
    if (!c1cs) {
        // 0x8017A78C: nop
    
            goto L_8017A798;
    }
    // 0x8017A78C: nop

    // 0x8017A790: b           L_8017A7A4
    // 0x8017A794: neg.s       $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = -ctx->f16.fl;
        goto L_8017A7A4;
    // 0x8017A794: neg.s       $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = -ctx->f16.fl;
L_8017A798:
    // 0x8017A798: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017A79C: addiu       $t1, $t1, -0x2BA8
    ctx->r9 = ADD32(ctx->r9, -0X2BA8);
    // 0x8017A7A0: lwc1        $f20, 0x12C($t1)
    ctx->f20.u32l = MEM_W(ctx->r9, 0X12C);
L_8017A7A4:
    // 0x8017A7A4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017A7A8: lwc1        $f4, -0x2B20($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2B20);
    // 0x8017A7AC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017A7B0: addiu       $t2, $t2, -0x2BA8
    ctx->r10 = ADD32(ctx->r10, -0X2BA8);
    // 0x8017A7B4: add.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x8017A7B8: swc1        $f6, -0x2B20($at)
    MEM_W(-0X2B20, ctx->r1) = ctx->f6.u32l;
    // 0x8017A7BC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017A7C0: lwc1        $f8, -0x2B1C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2B1C);
    // 0x8017A7C4: lwc1        $f10, 0x130($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X130);
    // 0x8017A7C8: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8017A7CC: swc1        $f18, -0x2B1C($at)
    MEM_W(-0X2B1C, ctx->r1) = ctx->f18.u32l;
    // 0x8017A7D0: lw          $t3, 0xF0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XF0);
    // 0x8017A7D4: beq         $t3, $zero, L_8017A800
    if (ctx->r11 == 0) {
        // 0x8017A7D8: nop
    
            goto L_8017A800;
    }
    // 0x8017A7D8: nop

    // 0x8017A7DC: andi        $t4, $t3, 0x3
    ctx->r12 = ctx->r11 & 0X3;
    // 0x8017A7E0: beq         $t4, $zero, L_8017AC54
    if (ctx->r12 == 0) {
        // 0x8017A7E4: nop
    
            goto L_8017AC54;
    }
    // 0x8017A7E4: nop

    // 0x8017A7E8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8017A7EC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017A7F0: sw          $t5, 0xFC($t2)
    MEM_W(0XFC, ctx->r10) = ctx->r13;
    // 0x8017A7F4: addiu       $t6, $t6, -0x2BA8
    ctx->r14 = ADD32(ctx->r14, -0X2BA8);
    // 0x8017A7F8: b           L_8017AC54
    // 0x8017A7FC: sw          $zero, 0x100($t6)
    MEM_W(0X100, ctx->r14) = 0;
        goto L_8017AC54;
    // 0x8017A7FC: sw          $zero, 0x100($t6)
    MEM_W(0X100, ctx->r14) = 0;
L_8017A800:
    // 0x8017A800: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017A804: addiu       $t7, $t7, -0x2BA8
    ctx->r15 = ADD32(ctx->r15, -0X2BA8);
    // 0x8017A808: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8017A80C: lwc1        $f4, -0x438($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X438);
    // 0x8017A810: lwc1        $f16, 0x12C($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X12C);
    // 0x8017A814: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017A818: addiu       $t8, $t8, -0x2BA8
    ctx->r24 = ADD32(ctx->r24, -0X2BA8);
    // 0x8017A81C: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x8017A820: add.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x8017A824: swc1        $f8, 0x12C($t7)
    MEM_W(0X12C, ctx->r15) = ctx->f8.u32l;
    // 0x8017A828: lw          $s0, 0x108($t8)
    ctx->r16 = MEM_W(ctx->r24, 0X108);
    // 0x8017A82C: beq         $s0, $zero, L_8017ABFC
    if (ctx->r16 == 0) {
        // 0x8017A830: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8017ABFC;
    }
    // 0x8017A830: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8017A834: beq         $s0, $at, L_8017A84C
    if (ctx->r16 == ctx->r1) {
        // 0x8017A838: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8017A84C;
    }
    // 0x8017A838: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8017A83C: beq         $s0, $at, L_8017AB38
    if (ctx->r16 == ctx->r1) {
        // 0x8017A840: nop
    
            goto L_8017AB38;
    }
    // 0x8017A840: nop

    // 0x8017A844: b           L_8017ABFC
    // 0x8017A848: nop

        goto L_8017ABFC;
    // 0x8017A848: nop

L_8017A84C:
    // 0x8017A84C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017A850: addiu       $t9, $t9, -0x2BA8
    ctx->r25 = ADD32(ctx->r25, -0X2BA8);
    // 0x8017A854: lw          $t0, 0xEC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XEC);
    // 0x8017A858: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017A85C: addiu       $t3, $t3, 0x3C00
    ctx->r11 = ADD32(ctx->r11, 0X3C00);
    // 0x8017A860: srl         $t1, $t0, 1
    ctx->r9 = S32(U32(ctx->r8) >> 1);
    // 0x8017A864: sw          $t1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r9;
    // 0x8017A868: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017A86C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017A870: addiu       $t2, $t2, 0x3C00
    ctx->r10 = ADD32(ctx->r10, 0X3C00);
    // 0x8017A874: addiu       $t4, $t4, -0x2BA8
    ctx->r12 = ADD32(ctx->r12, -0X2BA8);
    // 0x8017A878: lw          $t5, 0x100($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X100);
    // 0x8017A87C: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x8017A880: bne         $t5, $t6, L_8017A890
    if (ctx->r13 != ctx->r14) {
        // 0x8017A884: nop
    
            goto L_8017A890;
    }
    // 0x8017A884: nop

    // 0x8017A888: jal         0x80179338
    // 0x8017A88C: lwc1        $f12, 0x54($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X54);
    func_80179338_1501A0(rdram, ctx);
        goto after_4;
    // 0x8017A88C: lwc1        $f12, 0x54($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X54);
    after_4:
L_8017A890:
    // 0x8017A890: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017A894: addiu       $t7, $t7, -0x2BA8
    ctx->r15 = ADD32(ctx->r15, -0X2BA8);
    // 0x8017A898: lw          $s0, 0x104($t7)
    ctx->r16 = MEM_W(ctx->r15, 0X104);
    // 0x8017A89C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8017A8A0: beq         $s0, $at, L_8017A8C0
    if (ctx->r16 == ctx->r1) {
        // 0x8017A8A4: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8017A8C0;
    }
    // 0x8017A8A4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8017A8A8: beq         $s0, $at, L_8017A8C0
    if (ctx->r16 == ctx->r1) {
        // 0x8017A8AC: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_8017A8C0;
    }
    // 0x8017A8AC: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8017A8B0: beq         $s0, $at, L_8017A8C0
    if (ctx->r16 == ctx->r1) {
        // 0x8017A8B4: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_8017A8C0;
    }
    // 0x8017A8B4: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8017A8B8: bne         $s0, $at, L_8017A9C0
    if (ctx->r16 != ctx->r1) {
        // 0x8017A8BC: nop
    
            goto L_8017A9C0;
    }
    // 0x8017A8BC: nop

L_8017A8C0:
    // 0x8017A8C0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017A8C4: addiu       $t8, $t8, -0x2BA8
    ctx->r24 = ADD32(ctx->r24, -0X2BA8);
    // 0x8017A8C8: lw          $t9, 0xEC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XEC);
    // 0x8017A8CC: sltiu       $at, $t9, 0x23
    ctx->r1 = ctx->r25 < 0X23 ? 1 : 0;
    // 0x8017A8D0: beq         $at, $zero, L_8017AABC
    if (ctx->r1 == 0) {
        // 0x8017A8D4: nop
    
            goto L_8017AABC;
    }
    // 0x8017A8D4: nop

    // 0x8017A8D8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017A8DC: addiu       $t0, $t0, -0x2BA8
    ctx->r8 = ADD32(ctx->r8, -0X2BA8);
    // 0x8017A8E0: lw          $t1, 0xEC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XEC);
    // 0x8017A8E4: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017A8E8: addiu       $t3, $t3, 0x3C00
    ctx->r11 = ADD32(ctx->r11, 0X3C00);
    // 0x8017A8EC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017A8F0: addiu       $t5, $t5, -0x2BA8
    ctx->r13 = ADD32(ctx->r13, -0X2BA8);
    // 0x8017A8F4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017A8F8: sw          $t1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r9;
    // 0x8017A8FC: lw          $t6, 0xEC($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XEC);
    // 0x8017A900: addiu       $t4, $t4, 0x3C00
    ctx->r12 = ADD32(ctx->r12, 0X3C00);
    // 0x8017A904: lw          $t2, 0x0($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X0);
    // 0x8017A908: srl         $t7, $t6, 1
    ctx->r15 = S32(U32(ctx->r14) >> 1);
    // 0x8017A90C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017A910: addu        $t8, $t2, $t7
    ctx->r24 = ADD32(ctx->r10, ctx->r15);
    // 0x8017A914: sw          $t8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r24;
    // 0x8017A918: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017A91C: addiu       $t9, $t9, 0x3C00
    ctx->r25 = ADD32(ctx->r25, 0X3C00);
    // 0x8017A920: addiu       $t1, $t1, -0x2BA8
    ctx->r9 = ADD32(ctx->r9, -0X2BA8);
    // 0x8017A924: lw          $t3, 0x100($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X100);
    // 0x8017A928: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8017A92C: sltu        $at, $t3, $t0
    ctx->r1 = ctx->r11 < ctx->r8 ? 1 : 0;
    // 0x8017A930: bne         $at, $zero, L_8017AABC
    if (ctx->r1 != 0) {
        // 0x8017A934: nop
    
            goto L_8017AABC;
    }
    // 0x8017A934: nop

    // 0x8017A938: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017A93C: addiu       $t5, $t5, -0x4198
    ctx->r13 = ADD32(ctx->r13, -0X4198);
    // 0x8017A940: lwc1        $f10, 0x0($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X0);
    // 0x8017A944: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017A948: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x8017A94C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017A950: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017A954: swc1        $f10, 0xC8($t6)
    MEM_W(0XC8, ctx->r14) = ctx->f10.u32l;
    // 0x8017A958: addiu       $t7, $t7, -0x4198
    ctx->r15 = ADD32(ctx->r15, -0X4198);
    // 0x8017A95C: addiu       $t2, $t2, -0x2BA8
    ctx->r10 = ADD32(ctx->r10, -0X2BA8);
    // 0x8017A960: lwc1        $f18, 0x12C($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X12C);
    // 0x8017A964: lwc1        $f4, 0x4($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X4);
    // 0x8017A968: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017A96C: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x8017A970: add.s       $f16, $f18, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8017A974: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017A978: addiu       $t4, $t4, -0x4198
    ctx->r12 = ADD32(ctx->r12, -0X4198);
    // 0x8017A97C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017A980: swc1        $f16, 0xCC($t8)
    MEM_W(0XCC, ctx->r24) = ctx->f16.u32l;
    // 0x8017A984: lwc1        $f6, 0x8($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X8);
    // 0x8017A988: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x8017A98C: jal         0x80199214
    // 0x8017A990: swc1        $f6, 0xD0($t9)
    MEM_W(0XD0, ctx->r25) = ctx->f6.u32l;
    func_80199214_1501A0(rdram, ctx);
        goto after_5;
    // 0x8017A990: swc1        $f6, 0xD0($t9)
    MEM_W(0XD0, ctx->r25) = ctx->f6.u32l;
    after_5:
    // 0x8017A994: bne         $v0, $zero, L_8017AABC
    if (ctx->r2 != 0) {
        // 0x8017A998: nop
    
            goto L_8017AABC;
    }
    // 0x8017A998: nop

    // 0x8017A99C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017A9A0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017A9A4: addiu       $t0, $t0, -0x2BA8
    ctx->r8 = ADD32(ctx->r8, -0X2BA8);
    // 0x8017A9A8: addiu       $t1, $t1, -0x4198
    ctx->r9 = ADD32(ctx->r9, -0X4198);
    // 0x8017A9AC: lwc1        $f8, 0x4($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X4);
    // 0x8017A9B0: lwc1        $f10, 0x12C($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X12C);
    // 0x8017A9B4: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8017A9B8: b           L_8017AABC
    // 0x8017A9BC: swc1        $f18, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->f18.u32l;
        goto L_8017AABC;
    // 0x8017A9BC: swc1        $f18, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->f18.u32l;
L_8017A9C0:
    // 0x8017A9C0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017A9C4: addiu       $t3, $t3, -0x2BA8
    ctx->r11 = ADD32(ctx->r11, -0X2BA8);
    // 0x8017A9C8: lw          $t5, 0xEC($t3)
    ctx->r13 = MEM_W(ctx->r11, 0XEC);
    // 0x8017A9CC: sltiu       $at, $t5, 0x23
    ctx->r1 = ctx->r13 < 0X23 ? 1 : 0;
    // 0x8017A9D0: beq         $at, $zero, L_8017AABC
    if (ctx->r1 == 0) {
        // 0x8017A9D4: nop
    
            goto L_8017AABC;
    }
    // 0x8017A9D4: nop

    // 0x8017A9D8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017A9DC: addiu       $t6, $t6, -0x2BA8
    ctx->r14 = ADD32(ctx->r14, -0X2BA8);
    // 0x8017A9E0: lw          $t2, 0xEC($t6)
    ctx->r10 = MEM_W(ctx->r14, 0XEC);
    // 0x8017A9E4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017A9E8: addiu       $t7, $t7, 0x3C00
    ctx->r15 = ADD32(ctx->r15, 0X3C00);
    // 0x8017A9EC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017A9F0: addiu       $t9, $t9, -0x2BA8
    ctx->r25 = ADD32(ctx->r25, -0X2BA8);
    // 0x8017A9F4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017A9F8: sw          $t2, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r10;
    // 0x8017A9FC: lw          $t0, 0xEC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XEC);
    // 0x8017AA00: addiu       $t8, $t8, 0x3C00
    ctx->r24 = ADD32(ctx->r24, 0X3C00);
    // 0x8017AA04: lw          $t4, 0x0($t8)
    ctx->r12 = MEM_W(ctx->r24, 0X0);
    // 0x8017AA08: srl         $t1, $t0, 1
    ctx->r9 = S32(U32(ctx->r8) >> 1);
    // 0x8017AA0C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017AA10: addu        $t3, $t4, $t1
    ctx->r11 = ADD32(ctx->r12, ctx->r9);
    // 0x8017AA14: sw          $t3, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r11;
    // 0x8017AA18: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017AA1C: addiu       $t5, $t5, 0x3C00
    ctx->r13 = ADD32(ctx->r13, 0X3C00);
    // 0x8017AA20: addiu       $t2, $t2, -0x2BA8
    ctx->r10 = ADD32(ctx->r10, -0X2BA8);
    // 0x8017AA24: lw          $t7, 0x100($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X100);
    // 0x8017AA28: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8017AA2C: sltu        $at, $t7, $t6
    ctx->r1 = ctx->r15 < ctx->r14 ? 1 : 0;
    // 0x8017AA30: bne         $at, $zero, L_8017AABC
    if (ctx->r1 != 0) {
        // 0x8017AA34: nop
    
            goto L_8017AABC;
    }
    // 0x8017AA34: nop

    // 0x8017AA38: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017AA3C: addiu       $t9, $t9, -0x4198
    ctx->r25 = ADD32(ctx->r25, -0X4198);
    // 0x8017AA40: lwc1        $f4, 0x0($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X0);
    // 0x8017AA44: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017AA48: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x8017AA4C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017AA50: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017AA54: swc1        $f4, 0xC8($t0)
    MEM_W(0XC8, ctx->r8) = ctx->f4.u32l;
    // 0x8017AA58: addiu       $t1, $t1, -0x2BA8
    ctx->r9 = ADD32(ctx->r9, -0X2BA8);
    // 0x8017AA5C: addiu       $t4, $t4, -0x4198
    ctx->r12 = ADD32(ctx->r12, -0X4198);
    // 0x8017AA60: lwc1        $f16, 0x4($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X4);
    // 0x8017AA64: lwc1        $f6, 0x12C($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X12C);
    // 0x8017AA68: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017AA6C: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x8017AA70: sub.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x8017AA74: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017AA78: addiu       $t8, $t8, -0x4198
    ctx->r24 = ADD32(ctx->r24, -0X4198);
    // 0x8017AA7C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017AA80: swc1        $f8, 0xCC($t3)
    MEM_W(0XCC, ctx->r11) = ctx->f8.u32l;
    // 0x8017AA84: lwc1        $f10, 0x8($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X8);
    // 0x8017AA88: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x8017AA8C: jal         0x80199214
    // 0x8017AA90: swc1        $f10, 0xD0($t5)
    MEM_W(0XD0, ctx->r13) = ctx->f10.u32l;
    func_80199214_1501A0(rdram, ctx);
        goto after_6;
    // 0x8017AA90: swc1        $f10, 0xD0($t5)
    MEM_W(0XD0, ctx->r13) = ctx->f10.u32l;
    after_6:
    // 0x8017AA94: bne         $v0, $zero, L_8017AABC
    if (ctx->r2 != 0) {
        // 0x8017AA98: nop
    
            goto L_8017AABC;
    }
    // 0x8017AA98: nop

    // 0x8017AA9C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017AAA0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017AAA4: addiu       $t6, $t6, -0x2BA8
    ctx->r14 = ADD32(ctx->r14, -0X2BA8);
    // 0x8017AAA8: addiu       $t2, $t2, -0x4198
    ctx->r10 = ADD32(ctx->r10, -0X4198);
    // 0x8017AAAC: lwc1        $f18, 0x4($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X4);
    // 0x8017AAB0: lwc1        $f4, 0x12C($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X12C);
    // 0x8017AAB4: sub.s       $f16, $f18, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8017AAB8: swc1        $f16, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->f16.u32l;
L_8017AABC:
    // 0x8017AABC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017AAC0: addiu       $t7, $t7, -0x2BA8
    ctx->r15 = ADD32(ctx->r15, -0X2BA8);
    // 0x8017AAC4: lw          $t9, 0x10C($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10C);
    // 0x8017AAC8: andi        $t0, $t9, 0x2
    ctx->r8 = ctx->r25 & 0X2;
    // 0x8017AACC: beq         $t0, $zero, L_8017ABFC
    if (ctx->r8 == 0) {
        // 0x8017AAD0: nop
    
            goto L_8017ABFC;
    }
    // 0x8017AAD0: nop

    // 0x8017AAD4: lw          $t4, 0xEC($t7)
    ctx->r12 = MEM_W(ctx->r15, 0XEC);
    // 0x8017AAD8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017AADC: addiu       $t1, $t1, 0x3C00
    ctx->r9 = ADD32(ctx->r9, 0X3C00);
    // 0x8017AAE0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017AAE4: addiu       $t5, $t5, -0x2BA8
    ctx->r13 = ADD32(ctx->r13, -0X2BA8);
    // 0x8017AAE8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017AAEC: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x8017AAF0: lw          $t6, 0xEC($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XEC);
    // 0x8017AAF4: addiu       $t3, $t3, 0x3C00
    ctx->r11 = ADD32(ctx->r11, 0X3C00);
    // 0x8017AAF8: lw          $t8, 0x0($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X0);
    // 0x8017AAFC: srl         $t2, $t6, 1
    ctx->r10 = S32(U32(ctx->r14) >> 1);
    // 0x8017AB00: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017AB04: addu        $t9, $t8, $t2
    ctx->r25 = ADD32(ctx->r24, ctx->r10);
    // 0x8017AB08: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x8017AB0C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017AB10: addiu       $t0, $t0, -0x2BA8
    ctx->r8 = ADD32(ctx->r8, -0X2BA8);
    // 0x8017AB14: addiu       $t4, $t4, 0x3C00
    ctx->r12 = ADD32(ctx->r12, 0X3C00);
    // 0x8017AB18: lw          $t1, 0x0($t4)
    ctx->r9 = MEM_W(ctx->r12, 0X0);
    // 0x8017AB1C: lw          $t7, 0x100($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X100);
    // 0x8017AB20: bne         $t7, $t1, L_8017ABFC
    if (ctx->r15 != ctx->r9) {
        // 0x8017AB24: nop
    
            goto L_8017ABFC;
    }
    // 0x8017AB24: nop

    // 0x8017AB28: jal         0x80179ACC
    // 0x8017AB2C: nop

    func_80179ACC_1501A0(rdram, ctx);
        goto after_7;
    // 0x8017AB2C: nop

    after_7:
    // 0x8017AB30: b           L_8017ABFC
    // 0x8017AB34: nop

        goto L_8017ABFC;
    // 0x8017AB34: nop

L_8017AB38:
    // 0x8017AB38: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017AB3C: addiu       $t5, $t5, -0x2BA8
    ctx->r13 = ADD32(ctx->r13, -0X2BA8);
    // 0x8017AB40: lw          $t6, 0xEC($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XEC);
    // 0x8017AB44: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017AB48: addiu       $t2, $t2, 0x3C00
    ctx->r10 = ADD32(ctx->r10, 0X3C00);
    // 0x8017AB4C: srl         $t8, $t6, 1
    ctx->r24 = S32(U32(ctx->r14) >> 1);
    // 0x8017AB50: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
    // 0x8017AB54: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017AB58: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017AB5C: addiu       $t0, $t0, 0x3C00
    ctx->r8 = ADD32(ctx->r8, 0X3C00);
    // 0x8017AB60: addiu       $t9, $t9, -0x2BA8
    ctx->r25 = ADD32(ctx->r25, -0X2BA8);
    // 0x8017AB64: lw          $t3, 0x100($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X100);
    // 0x8017AB68: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x8017AB6C: bne         $t3, $t4, L_8017AB84
    if (ctx->r11 != ctx->r12) {
        // 0x8017AB70: nop
    
            goto L_8017AB84;
    }
    // 0x8017AB70: nop

    // 0x8017AB74: jal         0x80179338
    // 0x8017AB78: lwc1        $f12, 0x54($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X54);
    func_80179338_1501A0(rdram, ctx);
        goto after_8;
    // 0x8017AB78: lwc1        $f12, 0x54($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X54);
    after_8:
    // 0x8017AB7C: b           L_8017ABFC
    // 0x8017AB80: nop

        goto L_8017ABFC;
    // 0x8017AB80: nop

L_8017AB84:
    // 0x8017AB84: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017AB88: addiu       $t7, $t7, -0x2BA8
    ctx->r15 = ADD32(ctx->r15, -0X2BA8);
    // 0x8017AB8C: lw          $t1, 0xEC($t7)
    ctx->r9 = MEM_W(ctx->r15, 0XEC);
    // 0x8017AB90: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017AB94: addiu       $t5, $t5, 0x3C00
    ctx->r13 = ADD32(ctx->r13, 0X3C00);
    // 0x8017AB98: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017AB9C: addiu       $t2, $t2, -0x2BA8
    ctx->r10 = ADD32(ctx->r10, -0X2BA8);
    // 0x8017ABA0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017ABA4: sw          $t1, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r9;
    // 0x8017ABA8: lw          $t9, 0xEC($t2)
    ctx->r25 = MEM_W(ctx->r10, 0XEC);
    // 0x8017ABAC: addiu       $t6, $t6, 0x3C00
    ctx->r14 = ADD32(ctx->r14, 0X3C00);
    // 0x8017ABB0: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8017ABB4: srl         $t0, $t9, 1
    ctx->r8 = S32(U32(ctx->r25) >> 1);
    // 0x8017ABB8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017ABBC: addu        $t3, $t8, $t0
    ctx->r11 = ADD32(ctx->r24, ctx->r8);
    // 0x8017ABC0: sw          $t3, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r11;
    // 0x8017ABC4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017ABC8: addiu       $t4, $t4, -0x2BA8
    ctx->r12 = ADD32(ctx->r12, -0X2BA8);
    // 0x8017ABCC: addiu       $t1, $t1, 0x3C00
    ctx->r9 = ADD32(ctx->r9, 0X3C00);
    // 0x8017ABD0: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x8017ABD4: lw          $t7, 0x100($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X100);
    // 0x8017ABD8: bne         $t7, $t5, L_8017ABFC
    if (ctx->r15 != ctx->r13) {
        // 0x8017ABDC: nop
    
            goto L_8017ABFC;
    }
    // 0x8017ABDC: nop

    // 0x8017ABE0: jal         0x8017A6B4
    // 0x8017ABE4: nop

    func_8017A6B4_1501A0(rdram, ctx);
        goto after_9;
    // 0x8017ABE4: nop

    after_9:
    // 0x8017ABE8: lwc1        $f12, 0x54($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8017ABEC: jal         0x8017A448
    // 0x8017ABF0: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_8017A448_1501A0(rdram, ctx);
        goto after_10;
    // 0x8017ABF0: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_10:
    // 0x8017ABF4: jal         0x80179ACC
    // 0x8017ABF8: nop

    func_80179ACC_1501A0(rdram, ctx);
        goto after_11;
    // 0x8017ABF8: nop

    after_11:
L_8017ABFC:
    // 0x8017ABFC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017AC00: addiu       $t2, $t2, -0x4198
    ctx->r10 = ADD32(ctx->r10, -0X4198);
    // 0x8017AC04: lwc1        $f6, 0x0($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X0);
    // 0x8017AC08: lwc1        $f8, 0xC($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0XC);
    // 0x8017AC0C: c.eq.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl == ctx->f8.fl;
    // 0x8017AC10: nop

    // 0x8017AC14: bc1f        L_8017AC54
    if (!c1cs) {
        // 0x8017AC18: nop
    
            goto L_8017AC54;
    }
    // 0x8017AC18: nop

    // 0x8017AC1C: lwc1        $f10, 0x4($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X4);
    // 0x8017AC20: lwc1        $f18, 0x10($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X10);
    // 0x8017AC24: c.eq.s      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.fl == ctx->f18.fl;
    // 0x8017AC28: nop

    // 0x8017AC2C: bc1f        L_8017AC54
    if (!c1cs) {
        // 0x8017AC30: nop
    
            goto L_8017AC54;
    }
    // 0x8017AC30: nop

    // 0x8017AC34: lwc1        $f4, 0x8($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X8);
    // 0x8017AC38: lwc1        $f16, 0x14($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X14);
    // 0x8017AC3C: c.eq.s      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.fl == ctx->f16.fl;
    // 0x8017AC40: nop

    // 0x8017AC44: bc1f        L_8017AC54
    if (!c1cs) {
        // 0x8017AC48: nop
    
            goto L_8017AC54;
    }
    // 0x8017AC48: nop

    // 0x8017AC4C: jal         0x80178758
    // 0x8017AC50: lwc1        $f12, 0x54($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X54);
    func_80178758_1501A0(rdram, ctx);
        goto after_12;
    // 0x8017AC50: lwc1        $f12, 0x54($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X54);
    after_12:
L_8017AC54:
    // 0x8017AC54: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017AC58: addiu       $t9, $t9, -0x2BA8
    ctx->r25 = ADD32(ctx->r25, -0X2BA8);
    // 0x8017AC5C: lw          $t8, 0x100($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X100);
    // 0x8017AC60: sltiu       $at, $t8, 0x46
    ctx->r1 = ctx->r24 < 0X46 ? 1 : 0;
    // 0x8017AC64: bne         $at, $zero, L_8017ADB4
    if (ctx->r1 != 0) {
        // 0x8017AC68: nop
    
            goto L_8017ADB4;
    }
    // 0x8017AC68: nop

    // 0x8017AC6C: jal         0x80179B24
    // 0x8017AC70: nop

    func_80179B24_1501A0(rdram, ctx);
        goto after_13;
    // 0x8017AC70: nop

    after_13:
    // 0x8017AC74: b           L_8017ADB4
    // 0x8017AC78: nop

        goto L_8017ADB4;
    // 0x8017AC78: nop

L_8017AC7C:
    // 0x8017AC7C: jal         0x800E4CDC
    // 0x8017AC80: nop

    func_800E4CDC(rdram, ctx);
        goto after_14;
    // 0x8017AC80: nop

    after_14:
    // 0x8017AC84: addiu       $at, $zero, 0xFFF
    ctx->r1 = ADD32(0, 0XFFF);
    // 0x8017AC88: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x8017AC8C: mflo        $t0
    ctx->r8 = lo;
    // 0x8017AC90: andi        $t3, $t0, 0x7
    ctx->r11 = ctx->r8 & 0X7;
    // 0x8017AC94: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x8017AC98: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8017AC9C: lwc1        $f10, -0x434($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X434);
    // 0x8017ACA0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8017ACA4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017ACA8: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x8017ACAC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017ACB0: addiu       $t4, $t4, -0x2BA8
    ctx->r12 = ADD32(ctx->r12, -0X2BA8);
    // 0x8017ACB4: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8017ACB8: swc1        $f18, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f18.u32l;
    // 0x8017ACBC: lw          $s0, 0xF8($t4)
    ctx->r16 = MEM_W(ctx->r12, 0XF8);
    // 0x8017ACC0: beq         $s0, $zero, L_8017AD28
    if (ctx->r16 == 0) {
        // 0x8017ACC4: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8017AD28;
    }
    // 0x8017ACC4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8017ACC8: beq         $s0, $at, L_8017ACE0
    if (ctx->r16 == ctx->r1) {
        // 0x8017ACCC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8017ACE0;
    }
    // 0x8017ACCC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8017ACD0: beq         $s0, $at, L_8017AD08
    if (ctx->r16 == ctx->r1) {
        // 0x8017ACD4: nop
    
            goto L_8017AD08;
    }
    // 0x8017ACD4: nop

    // 0x8017ACD8: b           L_8017AD28
    // 0x8017ACDC: nop

        goto L_8017AD28;
    // 0x8017ACDC: nop

L_8017ACE0:
    // 0x8017ACE0: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017ACE4: addiu       $t1, $t1, -0x2BA8
    ctx->r9 = ADD32(ctx->r9, -0X2BA8);
    // 0x8017ACE8: lw          $t7, 0x100($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X100);
    // 0x8017ACEC: andi        $t5, $t7, 0x1
    ctx->r13 = ctx->r15 & 0X1;
    // 0x8017ACF0: bne         $t5, $zero, L_8017AD74
    if (ctx->r13 != 0) {
        // 0x8017ACF4: nop
    
            goto L_8017AD74;
    }
    // 0x8017ACF4: nop

    // 0x8017ACF8: jal         0x8017A224
    // 0x8017ACFC: lwc1        $f12, 0x54($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X54);
    func_8017A224_1501A0(rdram, ctx);
        goto after_15;
    // 0x8017ACFC: lwc1        $f12, 0x54($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X54);
    after_15:
    // 0x8017AD00: b           L_8017AD74
    // 0x8017AD04: nop

        goto L_8017AD74;
    // 0x8017AD04: nop

L_8017AD08:
    // 0x8017AD08: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017AD0C: addiu       $t2, $t2, -0x2BA8
    ctx->r10 = ADD32(ctx->r10, -0X2BA8);
    // 0x8017AD10: lw          $t9, 0x100($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X100);
    // 0x8017AD14: andi        $t8, $t9, 0x1
    ctx->r24 = ctx->r25 & 0X1;
    // 0x8017AD18: bne         $t8, $zero, L_8017AD74
    if (ctx->r24 != 0) {
        // 0x8017AD1C: nop
    
            goto L_8017AD74;
    }
    // 0x8017AD1C: nop

    // 0x8017AD20: jal         0x8017A02C
    // 0x8017AD24: lwc1        $f12, 0x54($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X54);
    func_8017A02C_1501A0(rdram, ctx);
        goto after_16;
    // 0x8017AD24: lwc1        $f12, 0x54($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X54);
    after_16:
L_8017AD28:
    // 0x8017AD28: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017AD2C: addiu       $t0, $t0, -0x2BA8
    ctx->r8 = ADD32(ctx->r8, -0X2BA8);
    // 0x8017AD30: lw          $t3, 0x100($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X100);
    // 0x8017AD34: sltiu       $at, $t3, 0x6
    ctx->r1 = ctx->r11 < 0X6 ? 1 : 0;
    // 0x8017AD38: bne         $at, $zero, L_8017AD48
    if (ctx->r1 != 0) {
        // 0x8017AD3C: nop
    
            goto L_8017AD48;
    }
    // 0x8017AD3C: nop

    // 0x8017AD40: jal         0x8017A6B4
    // 0x8017AD44: nop

    func_8017A6B4_1501A0(rdram, ctx);
        goto after_17;
    // 0x8017AD44: nop

    after_17:
L_8017AD48:
    // 0x8017AD48: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017AD4C: addiu       $t6, $t6, -0x2BA8
    ctx->r14 = ADD32(ctx->r14, -0X2BA8);
    // 0x8017AD50: lw          $t4, 0x100($t6)
    ctx->r12 = MEM_W(ctx->r14, 0X100);
    // 0x8017AD54: andi        $t1, $t4, 0x3
    ctx->r9 = ctx->r12 & 0X3;
    // 0x8017AD58: bne         $t1, $zero, L_8017AD74
    if (ctx->r9 != 0) {
        // 0x8017AD5C: nop
    
            goto L_8017AD74;
    }
    // 0x8017AD5C: nop

    // 0x8017AD60: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017AD64: addiu       $t7, $t7, -0x2BA8
    ctx->r15 = ADD32(ctx->r15, -0X2BA8);
    // 0x8017AD68: lw          $a1, 0x100($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X100);
    // 0x8017AD6C: jal         0x8017A448
    // 0x8017AD70: lwc1        $f12, 0x54($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X54);
    func_8017A448_1501A0(rdram, ctx);
        goto after_18;
    // 0x8017AD70: lwc1        $f12, 0x54($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X54);
    after_18:
L_8017AD74:
    // 0x8017AD74: jal         0x80179C90
    // 0x8017AD78: lwc1        $f12, 0x54($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X54);
    func_80179C90_1501A0(rdram, ctx);
        goto after_19;
    // 0x8017AD78: lwc1        $f12, 0x54($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X54);
    after_19:
    // 0x8017AD7C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017AD80: addiu       $t5, $t5, -0x2BA8
    ctx->r13 = ADD32(ctx->r13, -0X2BA8);
    // 0x8017AD84: lw          $t2, 0x100($t5)
    ctx->r10 = MEM_W(ctx->r13, 0X100);
    // 0x8017AD88: sltiu       $at, $t2, 0x14
    ctx->r1 = ctx->r10 < 0X14 ? 1 : 0;
    // 0x8017AD8C: bne         $at, $zero, L_8017ADB4
    if (ctx->r1 != 0) {
        // 0x8017AD90: nop
    
            goto L_8017ADB4;
    }
    // 0x8017AD90: nop

    // 0x8017AD94: jal         0x80179B24
    // 0x8017AD98: nop

    func_80179B24_1501A0(rdram, ctx);
        goto after_20;
    // 0x8017AD98: nop

    after_20:
    // 0x8017AD9C: b           L_8017ADB4
    // 0x8017ADA0: nop

        goto L_8017ADB4;
    // 0x8017ADA0: nop

L_8017ADA4:
    // 0x8017ADA4: jal         0x80179ACC
    // 0x8017ADA8: nop

    func_80179ACC_1501A0(rdram, ctx);
        goto after_21;
    // 0x8017ADA8: nop

    after_21:
    // 0x8017ADAC: jal         0x80179C90
    // 0x8017ADB0: lwc1        $f12, 0x54($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X54);
    func_80179C90_1501A0(rdram, ctx);
        goto after_22;
    // 0x8017ADB0: lwc1        $f12, 0x54($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X54);
    after_22:
L_8017ADB4:
    // 0x8017ADB4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017ADB8: addiu       $t9, $t9, -0x2BA8
    ctx->r25 = ADD32(ctx->r25, -0X2BA8);
    // 0x8017ADBC: lw          $t8, 0x100($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X100);
    // 0x8017ADC0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017ADC4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017ADC8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8017ADCC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017ADD0: addiu       $t0, $t8, 0x1
    ctx->r8 = ADD32(ctx->r24, 0X1);
    // 0x8017ADD4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8017ADD8: sw          $t0, 0x100($t9)
    MEM_W(0X100, ctx->r25) = ctx->r8;
    // 0x8017ADDC: addiu       $t3, $t3, -0x4198
    ctx->r11 = ADD32(ctx->r11, -0X4198);
    // 0x8017ADE0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017ADE4: addiu       $t6, $t6, -0x4198
    ctx->r14 = ADD32(ctx->r14, -0X4198);
    // 0x8017ADE8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017ADEC: swc1        $f4, 0x18($t3)
    MEM_W(0X18, ctx->r11) = ctx->f4.u32l;
    // 0x8017ADF0: addiu       $t4, $t4, -0x4198
    ctx->r12 = ADD32(ctx->r12, -0X4198);
    // 0x8017ADF4: swc1        $f16, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = ctx->f16.u32l;
    // 0x8017ADF8: lui         $at, 0xC0A0
    ctx->r1 = S32(0XC0A0 << 16);
    // 0x8017ADFC: swc1        $f6, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->f6.u32l;
    // 0x8017AE00: lwc1        $f10, 0x54($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8017AE04: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8017AE08: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017AE0C: addiu       $t1, $t1, -0x4198
    ctx->r9 = ADD32(ctx->r9, -0X4198);
    // 0x8017AE10: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8017AE14: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017AE18: addiu       $a0, $a0, -0x2BA8
    ctx->r4 = ADD32(ctx->r4, -0X2BA8);
    // 0x8017AE1C: addiu       $t7, $t1, 0xC
    ctx->r15 = ADD32(ctx->r9, 0XC);
    // 0x8017AE20: addiu       $t5, $t1, 0x10
    ctx->r13 = ADD32(ctx->r9, 0X10);
    // 0x8017AE24: addiu       $t2, $t1, 0x14
    ctx->r10 = ADD32(ctx->r9, 0X14);
    // 0x8017AE28: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x8017AE2C: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x8017AE30: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8017AE34: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8017AE38: addiu       $a0, $a0, 0xA0
    ctx->r4 = ADD32(ctx->r4, 0XA0);
    // 0x8017AE3C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8017AE40: jal         0x800D6E90
    // 0x8017AE44: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    guMtxXFMF_recomp(rdram, ctx);
        goto after_23;
    // 0x8017AE44: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_23:
    // 0x8017AE48: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017AE4C: addiu       $t8, $t8, -0x4198
    ctx->r24 = ADD32(ctx->r24, -0X4198);
    // 0x8017AE50: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017AE54: lwc1        $f16, -0x2B24($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2B24);
    // 0x8017AE58: lwc1        $f4, 0xC($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0XC);
    // 0x8017AE5C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017AE60: addiu       $t0, $t0, -0x4198
    ctx->r8 = ADD32(ctx->r8, -0X4198);
    // 0x8017AE64: add.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x8017AE68: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017AE6C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017AE70: addiu       $t9, $t9, -0x4198
    ctx->r25 = ADD32(ctx->r25, -0X4198);
    // 0x8017AE74: swc1        $f6, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f6.u32l;
    // 0x8017AE78: lwc1        $f8, 0x10($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X10);
    // 0x8017AE7C: lwc1        $f10, -0x2B20($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2B20);
    // 0x8017AE80: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017AE84: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8017AE88: swc1        $f18, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->f18.u32l;
    // 0x8017AE8C: lwc1        $f4, 0x14($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X14);
    // 0x8017AE90: lwc1        $f16, -0x2B1C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2B1C);
    // 0x8017AE94: add.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x8017AE98: jal         0x800C3FD0
    // 0x8017AE9C: swc1        $f6, 0x14($t9)
    MEM_W(0X14, ctx->r25) = ctx->f6.u32l;
    func_800C3FD0(rdram, ctx);
        goto after_24;
    // 0x8017AE9C: swc1        $f6, 0x14($t9)
    MEM_W(0X14, ctx->r25) = ctx->f6.u32l;
    after_24:
    // 0x8017AEA0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8017AEA4: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x8017AEA8: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8017AEAC: jr          $ra
    // 0x8017AEB0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8017AEB0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_8017AEB4_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017AEB4: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8017AEB8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8017AEBC: sh          $zero, 0x6E($sp)
    MEM_H(0X6E, ctx->r29) = 0;
L_8017AEC0:
    // 0x8017AEC0: lhu         $t6, 0x6E($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X6E);
    // 0x8017AEC4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017AEC8: addiu       $t8, $t8, -0x2A28
    ctx->r24 = ADD32(ctx->r24, -0X2A28);
    // 0x8017AECC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8017AED0: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8017AED4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017AED8: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8017AEDC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017AEE0: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8017AEE4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017AEE8: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8017AEEC: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x8017AEF0: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8017AEF4: andi        $t1, $t0, 0x8000
    ctx->r9 = ctx->r8 & 0X8000;
    // 0x8017AEF8: bne         $t1, $at, L_8017BCB8
    if (ctx->r9 != ctx->r1) {
        // 0x8017AEFC: nop
    
            goto L_8017BCB8;
    }
    // 0x8017AEFC: nop

    // 0x8017AF00: andi        $t2, $t0, 0x1
    ctx->r10 = ctx->r8 & 0X1;
    // 0x8017AF04: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8017AF08: beq         $t2, $at, L_8017BAA0
    if (ctx->r10 == ctx->r1) {
        // 0x8017AF0C: nop
    
            goto L_8017BAA0;
    }
    // 0x8017AF0C: nop

    // 0x8017AF10: lw          $t4, 0x34($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X34);
    // 0x8017AF14: lw          $t3, 0x50($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X50);
    // 0x8017AF18: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017AF1C: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x8017AF20: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x8017AF24: lwc1        $f4, 0x4($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X4);
    // 0x8017AF28: addiu       $t7, $t7, 0x3918
    ctx->r15 = ADD32(ctx->r15, 0X3918);
    // 0x8017AF2C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017AF30: swc1        $f4, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f4.u32l;
    // 0x8017AF34: lhu         $t8, 0x6E($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X6E);
    // 0x8017AF38: addiu       $t0, $t0, -0x2A28
    ctx->r8 = ADD32(ctx->r8, -0X2A28);
    // 0x8017AF3C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017AF40: sll         $t1, $t8, 2
    ctx->r9 = S32(ctx->r24 << 2);
    // 0x8017AF44: addu        $t1, $t1, $t8
    ctx->r9 = ADD32(ctx->r9, ctx->r24);
    // 0x8017AF48: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8017AF4C: subu        $t1, $t1, $t8
    ctx->r9 = SUB32(ctx->r9, ctx->r24);
    // 0x8017AF50: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8017AF54: addu        $t1, $t1, $t8
    ctx->r9 = ADD32(ctx->r9, ctx->r24);
    // 0x8017AF58: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8017AF5C: addu        $t2, $t1, $t0
    ctx->r10 = ADD32(ctx->r9, ctx->r8);
    // 0x8017AF60: lw          $t4, 0x34($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X34);
    // 0x8017AF64: lw          $t9, 0x50($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X50);
    // 0x8017AF68: addiu       $t6, $t6, 0x3918
    ctx->r14 = ADD32(ctx->r14, 0X3918);
    // 0x8017AF6C: sll         $t3, $t4, 4
    ctx->r11 = S32(ctx->r12 << 4);
    // 0x8017AF70: addu        $t5, $t9, $t3
    ctx->r13 = ADD32(ctx->r25, ctx->r11);
    // 0x8017AF74: lwc1        $f6, 0x8($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X8);
    // 0x8017AF78: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017AF7C: addiu       $t1, $t1, -0x2A28
    ctx->r9 = ADD32(ctx->r9, -0X2A28);
    // 0x8017AF80: swc1        $f6, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->f6.u32l;
    // 0x8017AF84: lhu         $t7, 0x6E($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X6E);
    // 0x8017AF88: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017AF8C: addiu       $t5, $t5, 0x3918
    ctx->r13 = ADD32(ctx->r13, 0X3918);
    // 0x8017AF90: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8017AF94: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8017AF98: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8017AF9C: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8017AFA0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8017AFA4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8017AFA8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8017AFAC: addu        $t0, $t8, $t1
    ctx->r8 = ADD32(ctx->r24, ctx->r9);
    // 0x8017AFB0: lw          $t4, 0x34($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X34);
    // 0x8017AFB4: lw          $t2, 0x50($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X50);
    // 0x8017AFB8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017AFBC: sll         $t9, $t4, 4
    ctx->r25 = S32(ctx->r12 << 4);
    // 0x8017AFC0: addu        $t3, $t2, $t9
    ctx->r11 = ADD32(ctx->r10, ctx->r25);
    // 0x8017AFC4: lwc1        $f8, 0xC($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0XC);
    // 0x8017AFC8: addiu       $t8, $t8, -0x2A28
    ctx->r24 = ADD32(ctx->r24, -0X2A28);
    // 0x8017AFCC: swc1        $f8, 0x24($t5)
    MEM_W(0X24, ctx->r13) = ctx->f8.u32l;
    // 0x8017AFD0: lhu         $t6, 0x6E($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X6E);
    // 0x8017AFD4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8017AFD8: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8017AFDC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017AFE0: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8017AFE4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017AFE8: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8017AFEC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017AFF0: addu        $t1, $t7, $t8
    ctx->r9 = ADD32(ctx->r15, ctx->r24);
    // 0x8017AFF4: lw          $t0, 0x34($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X34);
    // 0x8017AFF8: bne         $t0, $zero, L_8017B0B8
    if (ctx->r8 != 0) {
        // 0x8017AFFC: nop
    
            goto L_8017B0B8;
    }
    // 0x8017AFFC: nop

    // 0x8017B000: lw          $t4, 0x50($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X50);
    // 0x8017B004: sll         $t2, $t0, 4
    ctx->r10 = S32(ctx->r8 << 4);
    // 0x8017B008: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017B00C: addu        $t9, $t4, $t2
    ctx->r25 = ADD32(ctx->r12, ctx->r10);
    // 0x8017B010: lwc1        $f10, 0x4($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X4);
    // 0x8017B014: addiu       $t3, $t3, 0x3918
    ctx->r11 = ADD32(ctx->r11, 0X3918);
    // 0x8017B018: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017B01C: swc1        $f10, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f10.u32l;
    // 0x8017B020: lhu         $t5, 0x6E($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X6E);
    // 0x8017B024: addiu       $t7, $t7, -0x2A28
    ctx->r15 = ADD32(ctx->r15, -0X2A28);
    // 0x8017B028: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017B02C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8017B030: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8017B034: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8017B038: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x8017B03C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8017B040: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8017B044: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8017B048: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8017B04C: lw          $t0, 0x34($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X34);
    // 0x8017B050: lw          $t1, 0x50($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X50);
    // 0x8017B054: addiu       $t9, $t9, 0x3918
    ctx->r25 = ADD32(ctx->r25, 0X3918);
    // 0x8017B058: sll         $t4, $t0, 4
    ctx->r12 = S32(ctx->r8 << 4);
    // 0x8017B05C: addu        $t2, $t1, $t4
    ctx->r10 = ADD32(ctx->r9, ctx->r12);
    // 0x8017B060: lwc1        $f16, 0x8($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X8);
    // 0x8017B064: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017B068: addiu       $t6, $t6, -0x2A28
    ctx->r14 = ADD32(ctx->r14, -0X2A28);
    // 0x8017B06C: swc1        $f16, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->f16.u32l;
    // 0x8017B070: lhu         $t3, 0x6E($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X6E);
    // 0x8017B074: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017B078: addiu       $t2, $t2, 0x3918
    ctx->r10 = ADD32(ctx->r10, 0X3918);
    // 0x8017B07C: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x8017B080: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x8017B084: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8017B088: subu        $t5, $t5, $t3
    ctx->r13 = SUB32(ctx->r13, ctx->r11);
    // 0x8017B08C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8017B090: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x8017B094: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8017B098: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x8017B09C: lw          $t0, 0x34($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X34);
    // 0x8017B0A0: lw          $t8, 0x50($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X50);
    // 0x8017B0A4: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x8017B0A8: addu        $t4, $t8, $t1
    ctx->r12 = ADD32(ctx->r24, ctx->r9);
    // 0x8017B0AC: lwc1        $f18, 0xC($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0XC);
    // 0x8017B0B0: b           L_8017B19C
    // 0x8017B0B4: swc1        $f18, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->f18.u32l;
        goto L_8017B19C;
    // 0x8017B0B4: swc1        $f18, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->f18.u32l;
L_8017B0B8:
    // 0x8017B0B8: lhu         $t9, 0x6E($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X6E);
    // 0x8017B0BC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017B0C0: addiu       $t5, $t5, -0x2A28
    ctx->r13 = ADD32(ctx->r13, -0X2A28);
    // 0x8017B0C4: sll         $t3, $t9, 2
    ctx->r11 = S32(ctx->r25 << 2);
    // 0x8017B0C8: addu        $t3, $t3, $t9
    ctx->r11 = ADD32(ctx->r11, ctx->r25);
    // 0x8017B0CC: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8017B0D0: subu        $t3, $t3, $t9
    ctx->r11 = SUB32(ctx->r11, ctx->r25);
    // 0x8017B0D4: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8017B0D8: addu        $t3, $t3, $t9
    ctx->r11 = ADD32(ctx->r11, ctx->r25);
    // 0x8017B0DC: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8017B0E0: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x8017B0E4: lw          $t0, 0x34($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X34);
    // 0x8017B0E8: lw          $t7, 0x50($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X50);
    // 0x8017B0EC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017B0F0: sll         $t8, $t0, 4
    ctx->r24 = S32(ctx->r8 << 4);
    // 0x8017B0F4: addu        $t1, $t7, $t8
    ctx->r9 = ADD32(ctx->r15, ctx->r24);
    // 0x8017B0F8: lwc1        $f4, -0xC($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, -0XC);
    // 0x8017B0FC: addiu       $t4, $t4, 0x3918
    ctx->r12 = ADD32(ctx->r12, 0X3918);
    // 0x8017B100: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017B104: swc1        $f4, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f4.u32l;
    // 0x8017B108: lhu         $t2, 0x6E($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X6E);
    // 0x8017B10C: addiu       $t3, $t3, -0x2A28
    ctx->r11 = ADD32(ctx->r11, -0X2A28);
    // 0x8017B110: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017B114: sll         $t9, $t2, 2
    ctx->r25 = S32(ctx->r10 << 2);
    // 0x8017B118: addu        $t9, $t9, $t2
    ctx->r25 = ADD32(ctx->r25, ctx->r10);
    // 0x8017B11C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8017B120: subu        $t9, $t9, $t2
    ctx->r25 = SUB32(ctx->r25, ctx->r10);
    // 0x8017B124: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8017B128: addu        $t9, $t9, $t2
    ctx->r25 = ADD32(ctx->r25, ctx->r10);
    // 0x8017B12C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8017B130: addu        $t5, $t9, $t3
    ctx->r13 = ADD32(ctx->r25, ctx->r11);
    // 0x8017B134: lw          $t0, 0x34($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X34);
    // 0x8017B138: lw          $t6, 0x50($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X50);
    // 0x8017B13C: addiu       $t1, $t1, 0x3918
    ctx->r9 = ADD32(ctx->r9, 0X3918);
    // 0x8017B140: sll         $t7, $t0, 4
    ctx->r15 = S32(ctx->r8 << 4);
    // 0x8017B144: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8017B148: lwc1        $f6, -0x8($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, -0X8);
    // 0x8017B14C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017B150: addiu       $t9, $t9, -0x2A28
    ctx->r25 = ADD32(ctx->r25, -0X2A28);
    // 0x8017B154: swc1        $f6, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->f6.u32l;
    // 0x8017B158: lhu         $t4, 0x6E($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X6E);
    // 0x8017B15C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017B160: addiu       $t8, $t8, 0x3918
    ctx->r24 = ADD32(ctx->r24, 0X3918);
    // 0x8017B164: sll         $t2, $t4, 2
    ctx->r10 = S32(ctx->r12 << 2);
    // 0x8017B168: addu        $t2, $t2, $t4
    ctx->r10 = ADD32(ctx->r10, ctx->r12);
    // 0x8017B16C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8017B170: subu        $t2, $t2, $t4
    ctx->r10 = SUB32(ctx->r10, ctx->r12);
    // 0x8017B174: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8017B178: addu        $t2, $t2, $t4
    ctx->r10 = ADD32(ctx->r10, ctx->r12);
    // 0x8017B17C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8017B180: addu        $t3, $t2, $t9
    ctx->r11 = ADD32(ctx->r10, ctx->r25);
    // 0x8017B184: lw          $t0, 0x34($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X34);
    // 0x8017B188: lw          $t5, 0x50($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X50);
    // 0x8017B18C: sll         $t6, $t0, 4
    ctx->r14 = S32(ctx->r8 << 4);
    // 0x8017B190: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x8017B194: lwc1        $f8, -0x4($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, -0X4);
    // 0x8017B198: swc1        $f8, 0x20($t8)
    MEM_W(0X20, ctx->r24) = ctx->f8.u32l;
L_8017B19C:
    // 0x8017B19C: lhu         $t1, 0x6E($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X6E);
    // 0x8017B1A0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017B1A4: addiu       $t2, $t2, -0x2A28
    ctx->r10 = ADD32(ctx->r10, -0X2A28);
    // 0x8017B1A8: sll         $t4, $t1, 2
    ctx->r12 = S32(ctx->r9 << 2);
    // 0x8017B1AC: addu        $t4, $t4, $t1
    ctx->r12 = ADD32(ctx->r12, ctx->r9);
    // 0x8017B1B0: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8017B1B4: subu        $t4, $t4, $t1
    ctx->r12 = SUB32(ctx->r12, ctx->r9);
    // 0x8017B1B8: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8017B1BC: addu        $t4, $t4, $t1
    ctx->r12 = ADD32(ctx->r12, ctx->r9);
    // 0x8017B1C0: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8017B1C4: addu        $t9, $t4, $t2
    ctx->r25 = ADD32(ctx->r12, ctx->r10);
    // 0x8017B1C8: lw          $t0, 0x34($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X34);
    // 0x8017B1CC: lw          $t3, 0x50($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X50);
    // 0x8017B1D0: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8017B1D4: sll         $t5, $t0, 4
    ctx->r13 = S32(ctx->r8 << 4);
    // 0x8017B1D8: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x8017B1DC: lhu         $t7, 0x10($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X10);
    // 0x8017B1E0: bne         $t7, $at, L_8017B378
    if (ctx->r15 != ctx->r1) {
        // 0x8017B1E4: nop
    
            goto L_8017B378;
    }
    // 0x8017B1E4: nop

    // 0x8017B1E8: lwc1        $f10, 0x4($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X4);
    // 0x8017B1EC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017B1F0: addiu       $t8, $t8, 0x3918
    ctx->r24 = ADD32(ctx->r24, 0X3918);
    // 0x8017B1F4: swc1        $f10, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f10.u32l;
    // 0x8017B1F8: lhu         $t1, 0x6E($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X6E);
    // 0x8017B1FC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017B200: addiu       $t2, $t2, -0x2A28
    ctx->r10 = ADD32(ctx->r10, -0X2A28);
    // 0x8017B204: sll         $t4, $t1, 2
    ctx->r12 = S32(ctx->r9 << 2);
    // 0x8017B208: addu        $t4, $t4, $t1
    ctx->r12 = ADD32(ctx->r12, ctx->r9);
    // 0x8017B20C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8017B210: subu        $t4, $t4, $t1
    ctx->r12 = SUB32(ctx->r12, ctx->r9);
    // 0x8017B214: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8017B218: addu        $t4, $t4, $t1
    ctx->r12 = ADD32(ctx->r12, ctx->r9);
    // 0x8017B21C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8017B220: addu        $t9, $t4, $t2
    ctx->r25 = ADD32(ctx->r12, ctx->r10);
    // 0x8017B224: lw          $t3, 0x34($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X34);
    // 0x8017B228: lw          $t0, 0x50($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X50);
    // 0x8017B22C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017B230: sll         $t5, $t3, 4
    ctx->r13 = S32(ctx->r11 << 4);
    // 0x8017B234: addu        $t7, $t0, $t5
    ctx->r15 = ADD32(ctx->r8, ctx->r13);
    // 0x8017B238: lwc1        $f16, 0x8($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X8);
    // 0x8017B23C: addiu       $t6, $t6, 0x3918
    ctx->r14 = ADD32(ctx->r14, 0X3918);
    // 0x8017B240: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017B244: swc1        $f16, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->f16.u32l;
    // 0x8017B248: lhu         $t8, 0x6E($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X6E);
    // 0x8017B24C: addiu       $t4, $t4, -0x2A28
    ctx->r12 = ADD32(ctx->r12, -0X2A28);
    // 0x8017B250: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017B254: sll         $t1, $t8, 2
    ctx->r9 = S32(ctx->r24 << 2);
    // 0x8017B258: addu        $t1, $t1, $t8
    ctx->r9 = ADD32(ctx->r9, ctx->r24);
    // 0x8017B25C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8017B260: subu        $t1, $t1, $t8
    ctx->r9 = SUB32(ctx->r9, ctx->r24);
    // 0x8017B264: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8017B268: addu        $t1, $t1, $t8
    ctx->r9 = ADD32(ctx->r9, ctx->r24);
    // 0x8017B26C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8017B270: addu        $t2, $t1, $t4
    ctx->r10 = ADD32(ctx->r9, ctx->r12);
    // 0x8017B274: lw          $t3, 0x34($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X34);
    // 0x8017B278: lw          $t9, 0x50($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X50);
    // 0x8017B27C: addiu       $t7, $t7, 0x3918
    ctx->r15 = ADD32(ctx->r15, 0X3918);
    // 0x8017B280: sll         $t0, $t3, 4
    ctx->r8 = S32(ctx->r11 << 4);
    // 0x8017B284: addu        $t5, $t9, $t0
    ctx->r13 = ADD32(ctx->r25, ctx->r8);
    // 0x8017B288: lwc1        $f18, 0xC($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0XC);
    // 0x8017B28C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017B290: addiu       $t1, $t1, -0x2A28
    ctx->r9 = ADD32(ctx->r9, -0X2A28);
    // 0x8017B294: swc1        $f18, 0x28($t7)
    MEM_W(0X28, ctx->r15) = ctx->f18.u32l;
    // 0x8017B298: lhu         $t6, 0x6E($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X6E);
    // 0x8017B29C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017B2A0: addiu       $t5, $t5, 0x3918
    ctx->r13 = ADD32(ctx->r13, 0X3918);
    // 0x8017B2A4: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x8017B2A8: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x8017B2AC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8017B2B0: subu        $t8, $t8, $t6
    ctx->r24 = SUB32(ctx->r24, ctx->r14);
    // 0x8017B2B4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8017B2B8: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x8017B2BC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8017B2C0: addu        $t4, $t8, $t1
    ctx->r12 = ADD32(ctx->r24, ctx->r9);
    // 0x8017B2C4: lw          $t3, 0x34($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X34);
    // 0x8017B2C8: lw          $t2, 0x50($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X50);
    // 0x8017B2CC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017B2D0: sll         $t9, $t3, 4
    ctx->r25 = S32(ctx->r11 << 4);
    // 0x8017B2D4: addu        $t0, $t2, $t9
    ctx->r8 = ADD32(ctx->r10, ctx->r25);
    // 0x8017B2D8: lwc1        $f4, 0x4($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X4);
    // 0x8017B2DC: addiu       $t8, $t8, -0x2A28
    ctx->r24 = ADD32(ctx->r24, -0X2A28);
    // 0x8017B2E0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017B2E4: swc1        $f4, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f4.u32l;
    // 0x8017B2E8: lhu         $t7, 0x6E($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X6E);
    // 0x8017B2EC: addiu       $t0, $t0, 0x3918
    ctx->r8 = ADD32(ctx->r8, 0X3918);
    // 0x8017B2F0: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x8017B2F4: addu        $t6, $t6, $t7
    ctx->r14 = ADD32(ctx->r14, ctx->r15);
    // 0x8017B2F8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8017B2FC: subu        $t6, $t6, $t7
    ctx->r14 = SUB32(ctx->r14, ctx->r15);
    // 0x8017B300: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8017B304: addu        $t6, $t6, $t7
    ctx->r14 = ADD32(ctx->r14, ctx->r15);
    // 0x8017B308: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8017B30C: addu        $t1, $t6, $t8
    ctx->r9 = ADD32(ctx->r14, ctx->r24);
    // 0x8017B310: lw          $t3, 0x34($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X34);
    // 0x8017B314: lw          $t4, 0x50($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X50);
    // 0x8017B318: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017B31C: sll         $t2, $t3, 4
    ctx->r10 = S32(ctx->r11 << 4);
    // 0x8017B320: addu        $t9, $t4, $t2
    ctx->r25 = ADD32(ctx->r12, ctx->r10);
    // 0x8017B324: lwc1        $f6, 0x8($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X8);
    // 0x8017B328: addiu       $t6, $t6, -0x2A28
    ctx->r14 = ADD32(ctx->r14, -0X2A28);
    // 0x8017B32C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017B330: swc1        $f6, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->f6.u32l;
    // 0x8017B334: lhu         $t5, 0x6E($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X6E);
    // 0x8017B338: addiu       $t9, $t9, 0x3918
    ctx->r25 = ADD32(ctx->r25, 0X3918);
    // 0x8017B33C: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x8017B340: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x8017B344: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017B348: subu        $t7, $t7, $t5
    ctx->r15 = SUB32(ctx->r15, ctx->r13);
    // 0x8017B34C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017B350: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x8017B354: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017B358: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x8017B35C: lw          $t3, 0x34($t8)
    ctx->r11 = MEM_W(ctx->r24, 0X34);
    // 0x8017B360: lw          $t1, 0x50($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X50);
    // 0x8017B364: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x8017B368: addu        $t2, $t1, $t4
    ctx->r10 = ADD32(ctx->r9, ctx->r12);
    // 0x8017B36C: lwc1        $f8, 0xC($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0XC);
    // 0x8017B370: b           L_8017B638
    // 0x8017B374: swc1        $f8, 0x2C($t9)
    MEM_W(0X2C, ctx->r25) = ctx->f8.u32l;
        goto L_8017B638;
    // 0x8017B374: swc1        $f8, 0x2C($t9)
    MEM_W(0X2C, ctx->r25) = ctx->f8.u32l;
L_8017B378:
    // 0x8017B378: lhu         $t0, 0x6E($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X6E);
    // 0x8017B37C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017B380: addiu       $t7, $t7, -0x2A28
    ctx->r15 = ADD32(ctx->r15, -0X2A28);
    // 0x8017B384: sll         $t5, $t0, 2
    ctx->r13 = S32(ctx->r8 << 2);
    // 0x8017B388: addu        $t5, $t5, $t0
    ctx->r13 = ADD32(ctx->r13, ctx->r8);
    // 0x8017B38C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8017B390: subu        $t5, $t5, $t0
    ctx->r13 = SUB32(ctx->r13, ctx->r8);
    // 0x8017B394: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8017B398: addu        $t5, $t5, $t0
    ctx->r13 = ADD32(ctx->r13, ctx->r8);
    // 0x8017B39C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8017B3A0: addu        $t6, $t5, $t7
    ctx->r14 = ADD32(ctx->r13, ctx->r15);
    // 0x8017B3A4: lw          $t3, 0x34($t6)
    ctx->r11 = MEM_W(ctx->r14, 0X34);
    // 0x8017B3A8: lw          $t8, 0x50($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X50);
    // 0x8017B3AC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017B3B0: sll         $t1, $t3, 4
    ctx->r9 = S32(ctx->r11 << 4);
    // 0x8017B3B4: addu        $t4, $t8, $t1
    ctx->r12 = ADD32(ctx->r24, ctx->r9);
    // 0x8017B3B8: lwc1        $f10, 0x14($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X14);
    // 0x8017B3BC: addiu       $t2, $t2, 0x3918
    ctx->r10 = ADD32(ctx->r10, 0X3918);
    // 0x8017B3C0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017B3C4: swc1        $f10, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->f10.u32l;
    // 0x8017B3C8: lhu         $t9, 0x6E($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X6E);
    // 0x8017B3CC: addiu       $t5, $t5, -0x2A28
    ctx->r13 = ADD32(ctx->r13, -0X2A28);
    // 0x8017B3D0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017B3D4: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8017B3D8: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8017B3DC: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8017B3E0: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x8017B3E4: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8017B3E8: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8017B3EC: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8017B3F0: addu        $t7, $t0, $t5
    ctx->r15 = ADD32(ctx->r8, ctx->r13);
    // 0x8017B3F4: lw          $t3, 0x34($t7)
    ctx->r11 = MEM_W(ctx->r15, 0X34);
    // 0x8017B3F8: lw          $t6, 0x50($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X50);
    // 0x8017B3FC: addiu       $t4, $t4, 0x3918
    ctx->r12 = ADD32(ctx->r12, 0X3918);
    // 0x8017B400: sll         $t8, $t3, 4
    ctx->r24 = S32(ctx->r11 << 4);
    // 0x8017B404: addu        $t1, $t6, $t8
    ctx->r9 = ADD32(ctx->r14, ctx->r24);
    // 0x8017B408: lwc1        $f16, 0x18($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X18);
    // 0x8017B40C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017B410: addiu       $t0, $t0, -0x2A28
    ctx->r8 = ADD32(ctx->r8, -0X2A28);
    // 0x8017B414: swc1        $f16, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->f16.u32l;
    // 0x8017B418: lhu         $t2, 0x6E($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X6E);
    // 0x8017B41C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017B420: addiu       $t1, $t1, 0x3918
    ctx->r9 = ADD32(ctx->r9, 0X3918);
    // 0x8017B424: sll         $t9, $t2, 2
    ctx->r25 = S32(ctx->r10 << 2);
    // 0x8017B428: addu        $t9, $t9, $t2
    ctx->r25 = ADD32(ctx->r25, ctx->r10);
    // 0x8017B42C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8017B430: subu        $t9, $t9, $t2
    ctx->r25 = SUB32(ctx->r25, ctx->r10);
    // 0x8017B434: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8017B438: addu        $t9, $t9, $t2
    ctx->r25 = ADD32(ctx->r25, ctx->r10);
    // 0x8017B43C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8017B440: addu        $t5, $t9, $t0
    ctx->r13 = ADD32(ctx->r25, ctx->r8);
    // 0x8017B444: lw          $t3, 0x34($t5)
    ctx->r11 = MEM_W(ctx->r13, 0X34);
    // 0x8017B448: lw          $t7, 0x50($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X50);
    // 0x8017B44C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017B450: sll         $t6, $t3, 4
    ctx->r14 = S32(ctx->r11 << 4);
    // 0x8017B454: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x8017B458: lwc1        $f18, 0x1C($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X1C);
    // 0x8017B45C: addiu       $t9, $t9, -0x2A28
    ctx->r25 = ADD32(ctx->r25, -0X2A28);
    // 0x8017B460: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8017B464: swc1        $f18, 0x28($t1)
    MEM_W(0X28, ctx->r9) = ctx->f18.u32l;
    // 0x8017B468: lhu         $t4, 0x6E($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X6E);
    // 0x8017B46C: sll         $t2, $t4, 2
    ctx->r10 = S32(ctx->r12 << 2);
    // 0x8017B470: addu        $t2, $t2, $t4
    ctx->r10 = ADD32(ctx->r10, ctx->r12);
    // 0x8017B474: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8017B478: subu        $t2, $t2, $t4
    ctx->r10 = SUB32(ctx->r10, ctx->r12);
    // 0x8017B47C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8017B480: addu        $t2, $t2, $t4
    ctx->r10 = ADD32(ctx->r10, ctx->r12);
    // 0x8017B484: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8017B488: addu        $t0, $t2, $t9
    ctx->r8 = ADD32(ctx->r10, ctx->r25);
    // 0x8017B48C: lw          $t3, 0x34($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X34);
    // 0x8017B490: lw          $t5, 0x50($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X50);
    // 0x8017B494: sll         $t7, $t3, 4
    ctx->r15 = S32(ctx->r11 << 4);
    // 0x8017B498: addu        $t6, $t5, $t7
    ctx->r14 = ADD32(ctx->r13, ctx->r15);
    // 0x8017B49C: lhu         $t8, 0x20($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X20);
    // 0x8017B4A0: bne         $t8, $at, L_8017B554
    if (ctx->r24 != ctx->r1) {
        // 0x8017B4A4: nop
    
            goto L_8017B554;
    }
    // 0x8017B4A4: nop

    // 0x8017B4A8: lwc1        $f4, 0x14($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X14);
    // 0x8017B4AC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017B4B0: addiu       $t1, $t1, 0x3918
    ctx->r9 = ADD32(ctx->r9, 0X3918);
    // 0x8017B4B4: swc1        $f4, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f4.u32l;
    // 0x8017B4B8: lhu         $t4, 0x6E($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X6E);
    // 0x8017B4BC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017B4C0: addiu       $t9, $t9, -0x2A28
    ctx->r25 = ADD32(ctx->r25, -0X2A28);
    // 0x8017B4C4: sll         $t2, $t4, 2
    ctx->r10 = S32(ctx->r12 << 2);
    // 0x8017B4C8: addu        $t2, $t2, $t4
    ctx->r10 = ADD32(ctx->r10, ctx->r12);
    // 0x8017B4CC: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8017B4D0: subu        $t2, $t2, $t4
    ctx->r10 = SUB32(ctx->r10, ctx->r12);
    // 0x8017B4D4: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8017B4D8: addu        $t2, $t2, $t4
    ctx->r10 = ADD32(ctx->r10, ctx->r12);
    // 0x8017B4DC: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8017B4E0: addu        $t0, $t2, $t9
    ctx->r8 = ADD32(ctx->r10, ctx->r25);
    // 0x8017B4E4: lw          $t5, 0x34($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X34);
    // 0x8017B4E8: lw          $t3, 0x50($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X50);
    // 0x8017B4EC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017B4F0: sll         $t7, $t5, 4
    ctx->r15 = S32(ctx->r13 << 4);
    // 0x8017B4F4: addu        $t8, $t3, $t7
    ctx->r24 = ADD32(ctx->r11, ctx->r15);
    // 0x8017B4F8: lwc1        $f6, 0x18($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X18);
    // 0x8017B4FC: addiu       $t6, $t6, 0x3918
    ctx->r14 = ADD32(ctx->r14, 0X3918);
    // 0x8017B500: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017B504: swc1        $f6, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = ctx->f6.u32l;
    // 0x8017B508: lhu         $t1, 0x6E($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X6E);
    // 0x8017B50C: addiu       $t2, $t2, -0x2A28
    ctx->r10 = ADD32(ctx->r10, -0X2A28);
    // 0x8017B510: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017B514: sll         $t4, $t1, 2
    ctx->r12 = S32(ctx->r9 << 2);
    // 0x8017B518: addu        $t4, $t4, $t1
    ctx->r12 = ADD32(ctx->r12, ctx->r9);
    // 0x8017B51C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8017B520: subu        $t4, $t4, $t1
    ctx->r12 = SUB32(ctx->r12, ctx->r9);
    // 0x8017B524: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8017B528: addu        $t4, $t4, $t1
    ctx->r12 = ADD32(ctx->r12, ctx->r9);
    // 0x8017B52C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8017B530: addu        $t9, $t4, $t2
    ctx->r25 = ADD32(ctx->r12, ctx->r10);
    // 0x8017B534: lw          $t5, 0x34($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X34);
    // 0x8017B538: lw          $t0, 0x50($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X50);
    // 0x8017B53C: addiu       $t8, $t8, 0x3918
    ctx->r24 = ADD32(ctx->r24, 0X3918);
    // 0x8017B540: sll         $t3, $t5, 4
    ctx->r11 = S32(ctx->r13 << 4);
    // 0x8017B544: addu        $t7, $t0, $t3
    ctx->r15 = ADD32(ctx->r8, ctx->r11);
    // 0x8017B548: lwc1        $f8, 0x1C($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X1C);
    // 0x8017B54C: b           L_8017B638
    // 0x8017B550: swc1        $f8, 0x2C($t8)
    MEM_W(0X2C, ctx->r24) = ctx->f8.u32l;
        goto L_8017B638;
    // 0x8017B550: swc1        $f8, 0x2C($t8)
    MEM_W(0X2C, ctx->r24) = ctx->f8.u32l;
L_8017B554:
    // 0x8017B554: lhu         $t6, 0x6E($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X6E);
    // 0x8017B558: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017B55C: addiu       $t4, $t4, -0x2A28
    ctx->r12 = ADD32(ctx->r12, -0X2A28);
    // 0x8017B560: sll         $t1, $t6, 2
    ctx->r9 = S32(ctx->r14 << 2);
    // 0x8017B564: addu        $t1, $t1, $t6
    ctx->r9 = ADD32(ctx->r9, ctx->r14);
    // 0x8017B568: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8017B56C: subu        $t1, $t1, $t6
    ctx->r9 = SUB32(ctx->r9, ctx->r14);
    // 0x8017B570: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8017B574: addu        $t1, $t1, $t6
    ctx->r9 = ADD32(ctx->r9, ctx->r14);
    // 0x8017B578: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8017B57C: addu        $t2, $t1, $t4
    ctx->r10 = ADD32(ctx->r9, ctx->r12);
    // 0x8017B580: lw          $t5, 0x34($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X34);
    // 0x8017B584: lw          $t9, 0x50($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X50);
    // 0x8017B588: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017B58C: sll         $t0, $t5, 4
    ctx->r8 = S32(ctx->r13 << 4);
    // 0x8017B590: addu        $t3, $t9, $t0
    ctx->r11 = ADD32(ctx->r25, ctx->r8);
    // 0x8017B594: lwc1        $f10, 0x24($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X24);
    // 0x8017B598: addiu       $t7, $t7, 0x3918
    ctx->r15 = ADD32(ctx->r15, 0X3918);
    // 0x8017B59C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017B5A0: swc1        $f10, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f10.u32l;
    // 0x8017B5A4: lhu         $t8, 0x6E($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X6E);
    // 0x8017B5A8: addiu       $t1, $t1, -0x2A28
    ctx->r9 = ADD32(ctx->r9, -0X2A28);
    // 0x8017B5AC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017B5B0: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x8017B5B4: addu        $t6, $t6, $t8
    ctx->r14 = ADD32(ctx->r14, ctx->r24);
    // 0x8017B5B8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8017B5BC: subu        $t6, $t6, $t8
    ctx->r14 = SUB32(ctx->r14, ctx->r24);
    // 0x8017B5C0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8017B5C4: addu        $t6, $t6, $t8
    ctx->r14 = ADD32(ctx->r14, ctx->r24);
    // 0x8017B5C8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8017B5CC: addu        $t4, $t6, $t1
    ctx->r12 = ADD32(ctx->r14, ctx->r9);
    // 0x8017B5D0: lw          $t5, 0x34($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X34);
    // 0x8017B5D4: lw          $t2, 0x50($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X50);
    // 0x8017B5D8: addiu       $t3, $t3, 0x3918
    ctx->r11 = ADD32(ctx->r11, 0X3918);
    // 0x8017B5DC: sll         $t9, $t5, 4
    ctx->r25 = S32(ctx->r13 << 4);
    // 0x8017B5E0: addu        $t0, $t2, $t9
    ctx->r8 = ADD32(ctx->r10, ctx->r25);
    // 0x8017B5E4: lwc1        $f16, 0x28($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X28);
    // 0x8017B5E8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017B5EC: addiu       $t6, $t6, -0x2A28
    ctx->r14 = ADD32(ctx->r14, -0X2A28);
    // 0x8017B5F0: swc1        $f16, 0x1C($t3)
    MEM_W(0X1C, ctx->r11) = ctx->f16.u32l;
    // 0x8017B5F4: lhu         $t7, 0x6E($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X6E);
    // 0x8017B5F8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017B5FC: addiu       $t0, $t0, 0x3918
    ctx->r8 = ADD32(ctx->r8, 0X3918);
    // 0x8017B600: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8017B604: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8017B608: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8017B60C: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8017B610: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8017B614: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8017B618: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8017B61C: addu        $t1, $t8, $t6
    ctx->r9 = ADD32(ctx->r24, ctx->r14);
    // 0x8017B620: lw          $t5, 0x34($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X34);
    // 0x8017B624: lw          $t4, 0x50($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X50);
    // 0x8017B628: sll         $t2, $t5, 4
    ctx->r10 = S32(ctx->r13 << 4);
    // 0x8017B62C: addu        $t9, $t4, $t2
    ctx->r25 = ADD32(ctx->r12, ctx->r10);
    // 0x8017B630: lwc1        $f18, 0x2C($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X2C);
    // 0x8017B634: swc1        $f18, 0x2C($t0)
    MEM_W(0X2C, ctx->r8) = ctx->f18.u32l;
L_8017B638:
    // 0x8017B638: lhu         $t3, 0x6E($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X6E);
    // 0x8017B63C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017B640: addiu       $t8, $t8, -0x2A28
    ctx->r24 = ADD32(ctx->r24, -0X2A28);
    // 0x8017B644: sll         $t7, $t3, 2
    ctx->r15 = S32(ctx->r11 << 2);
    // 0x8017B648: addu        $t7, $t7, $t3
    ctx->r15 = ADD32(ctx->r15, ctx->r11);
    // 0x8017B64C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017B650: subu        $t7, $t7, $t3
    ctx->r15 = SUB32(ctx->r15, ctx->r11);
    // 0x8017B654: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017B658: addu        $t7, $t7, $t3
    ctx->r15 = ADD32(ctx->r15, ctx->r11);
    // 0x8017B65C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017B660: addu        $t6, $t7, $t8
    ctx->r14 = ADD32(ctx->r15, ctx->r24);
    // 0x8017B664: lhu         $t1, 0x0($t6)
    ctx->r9 = MEM_HU(ctx->r14, 0X0);
    // 0x8017B668: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8017B66C: andi        $t5, $t1, 0x8
    ctx->r13 = ctx->r9 & 0X8;
    // 0x8017B670: beq         $t5, $at, L_8017B834
    if (ctx->r13 == ctx->r1) {
        // 0x8017B674: nop
    
            goto L_8017B834;
    }
    // 0x8017B674: nop

    // 0x8017B678: lwc1        $f4, 0x60($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X60);
    // 0x8017B67C: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x8017B680: lwc1        $f6, 0x64($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X64);
    // 0x8017B684: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    // 0x8017B688: lwc1        $f8, 0x68($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X68);
    // 0x8017B68C: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x8017B690: lw          $t4, 0x3C($t6)
    ctx->r12 = MEM_W(ctx->r14, 0X3C);
    // 0x8017B694: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x8017B698: bgez        $t4, L_8017B6B0
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8017B69C: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_8017B6B0;
    }
    // 0x8017B69C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8017B6A0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8017B6A4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8017B6A8: nop

    // 0x8017B6AC: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_8017B6B0:
    // 0x8017B6B0: lw          $t2, 0x38($t6)
    ctx->r10 = MEM_W(ctx->r14, 0X38);
    // 0x8017B6B4: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x8017B6B8: bgez        $t2, L_8017B6D0
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8017B6BC: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8017B6D0;
    }
    // 0x8017B6BC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8017B6C0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8017B6C4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8017B6C8: nop

    // 0x8017B6CC: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8017B6D0:
    // 0x8017B6D0: div.s       $f10, $f16, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = DIV_S(ctx->f16.fl, ctx->f6.fl);
    // 0x8017B6D4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017B6D8: jal         0x8019BE2C
    // 0x8017B6DC: swc1        $f10, 0x3948($at)
    MEM_W(0X3948, ctx->r1) = ctx->f10.u32l;
    func_8019BE2C_1501A0(rdram, ctx);
        goto after_0;
    // 0x8017B6DC: swc1        $f10, 0x3948($at)
    MEM_W(0X3948, ctx->r1) = ctx->f10.u32l;
    after_0:
    // 0x8017B6E0: lhu         $t9, 0x6E($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X6E);
    // 0x8017B6E4: lhu         $t3, 0x6E($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X6E);
    // 0x8017B6E8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017B6EC: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8017B6F0: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8017B6F4: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8017B6F8: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x8017B6FC: lwc1        $f18, 0x394C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X394C);
    // 0x8017B700: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8017B704: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8017B708: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8017B70C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017B710: sll         $t7, $t3, 2
    ctx->r15 = S32(ctx->r11 << 2);
    // 0x8017B714: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x8017B718: addu        $t7, $t7, $t3
    ctx->r15 = ADD32(ctx->r15, ctx->r11);
    // 0x8017B71C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017B720: swc1        $f18, -0x29C8($at)
    MEM_W(-0X29C8, ctx->r1) = ctx->f18.u32l;
    // 0x8017B724: lhu         $t8, 0x6E($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X6E);
    // 0x8017B728: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017B72C: subu        $t7, $t7, $t3
    ctx->r15 = SUB32(ctx->r15, ctx->r11);
    // 0x8017B730: lwc1        $f4, 0x3950($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X3950);
    // 0x8017B734: lhu         $t5, 0x6E($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X6E);
    // 0x8017B738: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017B73C: addu        $t7, $t7, $t3
    ctx->r15 = ADD32(ctx->r15, ctx->r11);
    // 0x8017B740: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017B744: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017B748: sll         $t1, $t8, 2
    ctx->r9 = S32(ctx->r24 << 2);
    // 0x8017B74C: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8017B750: addu        $t1, $t1, $t8
    ctx->r9 = ADD32(ctx->r9, ctx->r24);
    // 0x8017B754: sll         $t4, $t5, 2
    ctx->r12 = S32(ctx->r13 << 2);
    // 0x8017B758: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8017B75C: swc1        $f4, -0x29C4($at)
    MEM_W(-0X29C4, ctx->r1) = ctx->f4.u32l;
    // 0x8017B760: addu        $t4, $t4, $t5
    ctx->r12 = ADD32(ctx->r12, ctx->r13);
    // 0x8017B764: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017B768: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8017B76C: subu        $t1, $t1, $t8
    ctx->r9 = SUB32(ctx->r9, ctx->r24);
    // 0x8017B770: lwc1        $f8, 0x3954($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X3954);
    // 0x8017B774: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8017B778: subu        $t4, $t4, $t5
    ctx->r12 = SUB32(ctx->r12, ctx->r13);
    // 0x8017B77C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8017B780: addu        $t1, $t1, $t8
    ctx->r9 = ADD32(ctx->r9, ctx->r24);
    // 0x8017B784: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8017B788: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017B78C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017B790: addu        $t4, $t4, $t5
    ctx->r12 = ADD32(ctx->r12, ctx->r13);
    // 0x8017B794: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8017B798: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8017B79C: addiu       $t6, $t6, -0x2A28
    ctx->r14 = ADD32(ctx->r14, -0X2A28);
    // 0x8017B7A0: addu        $t2, $t4, $t6
    ctx->r10 = ADD32(ctx->r12, ctx->r14);
    // 0x8017B7A4: swc1        $f8, -0x29C0($at)
    MEM_W(-0X29C0, ctx->r1) = ctx->f8.u32l;
    // 0x8017B7A8: lwc1        $f16, 0x60($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X60);
    // 0x8017B7AC: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8017B7B0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017B7B4: addiu       $t3, $t3, -0x2A28
    ctx->r11 = ADD32(ctx->r11, -0X2A28);
    // 0x8017B7B8: sub.s       $f10, $f16, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x8017B7BC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017B7C0: addiu       $t5, $t5, -0x2A28
    ctx->r13 = ADD32(ctx->r13, -0X2A28);
    // 0x8017B7C4: swc1        $f10, 0x88($t2)
    MEM_W(0X88, ctx->r10) = ctx->f10.u32l;
    // 0x8017B7C8: lhu         $t9, 0x6E($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X6E);
    // 0x8017B7CC: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8017B7D0: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8017B7D4: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8017B7D8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8017B7DC: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x8017B7E0: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8017B7E4: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8017B7E8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8017B7EC: addu        $t7, $t0, $t3
    ctx->r15 = ADD32(ctx->r8, ctx->r11);
    // 0x8017B7F0: lwc1        $f18, 0x64($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0X64);
    // 0x8017B7F4: sub.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8017B7F8: swc1        $f8, 0x8C($t7)
    MEM_W(0X8C, ctx->r15) = ctx->f8.u32l;
    // 0x8017B7FC: lhu         $t8, 0x6E($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X6E);
    // 0x8017B800: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8017B804: sll         $t1, $t8, 2
    ctx->r9 = S32(ctx->r24 << 2);
    // 0x8017B808: addu        $t1, $t1, $t8
    ctx->r9 = ADD32(ctx->r9, ctx->r24);
    // 0x8017B80C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8017B810: subu        $t1, $t1, $t8
    ctx->r9 = SUB32(ctx->r9, ctx->r24);
    // 0x8017B814: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8017B818: addu        $t1, $t1, $t8
    ctx->r9 = ADD32(ctx->r9, ctx->r24);
    // 0x8017B81C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8017B820: addu        $t4, $t1, $t5
    ctx->r12 = ADD32(ctx->r9, ctx->r13);
    // 0x8017B824: lwc1        $f16, 0x68($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X68);
    // 0x8017B828: sub.s       $f10, $f16, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x8017B82C: b           L_8017BA18
    // 0x8017B830: swc1        $f10, 0x90($t4)
    MEM_W(0X90, ctx->r12) = ctx->f10.u32l;
        goto L_8017BA18;
    // 0x8017B830: swc1        $f10, 0x90($t4)
    MEM_W(0X90, ctx->r12) = ctx->f10.u32l;
L_8017B834:
    // 0x8017B834: lhu         $t6, 0x6E($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X6E);
    // 0x8017B838: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017B83C: addiu       $t9, $t9, -0x2A28
    ctx->r25 = ADD32(ctx->r25, -0X2A28);
    // 0x8017B840: sll         $t2, $t6, 2
    ctx->r10 = S32(ctx->r14 << 2);
    // 0x8017B844: addu        $t2, $t2, $t6
    ctx->r10 = ADD32(ctx->r10, ctx->r14);
    // 0x8017B848: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8017B84C: subu        $t2, $t2, $t6
    ctx->r10 = SUB32(ctx->r10, ctx->r14);
    // 0x8017B850: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8017B854: addu        $t2, $t2, $t6
    ctx->r10 = ADD32(ctx->r10, ctx->r14);
    // 0x8017B858: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8017B85C: addu        $t0, $t2, $t9
    ctx->r8 = ADD32(ctx->r10, ctx->r25);
    // 0x8017B860: lwc1        $f18, 0x6C($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X6C);
    // 0x8017B864: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    // 0x8017B868: lwc1        $f4, 0x70($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X70);
    // 0x8017B86C: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x8017B870: lwc1        $f8, 0x74($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X74);
    // 0x8017B874: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x8017B878: lw          $t3, 0x3C($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X3C);
    // 0x8017B87C: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x8017B880: bgez        $t3, L_8017B898
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8017B884: cvt.s.w     $f6, $f16
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.fl = CVT_S_W(ctx->f16.u32l);
            goto L_8017B898;
    }
    // 0x8017B884: cvt.s.w     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8017B888: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8017B88C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017B890: nop

    // 0x8017B894: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
L_8017B898:
    // 0x8017B898: lw          $t7, 0x38($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X38);
    // 0x8017B89C: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x8017B8A0: bgez        $t7, L_8017B8B8
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8017B8A4: cvt.s.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
            goto L_8017B8B8;
    }
    // 0x8017B8A4: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8017B8A8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8017B8AC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8017B8B0: nop

    // 0x8017B8B4: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
L_8017B8B8:
    // 0x8017B8B8: div.s       $f16, $f6, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = DIV_S(ctx->f6.fl, ctx->f4.fl);
    // 0x8017B8BC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017B8C0: jal         0x8019BE2C
    // 0x8017B8C4: swc1        $f16, 0x3948($at)
    MEM_W(0X3948, ctx->r1) = ctx->f16.u32l;
    func_8019BE2C_1501A0(rdram, ctx);
        goto after_1;
    // 0x8017B8C4: swc1        $f16, 0x3948($at)
    MEM_W(0X3948, ctx->r1) = ctx->f16.u32l;
    after_1:
    // 0x8017B8C8: lhu         $t8, 0x6E($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X6E);
    // 0x8017B8CC: lhu         $t5, 0x6E($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X6E);
    // 0x8017B8D0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017B8D4: sll         $t1, $t8, 2
    ctx->r9 = S32(ctx->r24 << 2);
    // 0x8017B8D8: addu        $t1, $t1, $t8
    ctx->r9 = ADD32(ctx->r9, ctx->r24);
    // 0x8017B8DC: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8017B8E0: subu        $t1, $t1, $t8
    ctx->r9 = SUB32(ctx->r9, ctx->r24);
    // 0x8017B8E4: lwc1        $f10, 0x394C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X394C);
    // 0x8017B8E8: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8017B8EC: addu        $t1, $t1, $t8
    ctx->r9 = ADD32(ctx->r9, ctx->r24);
    // 0x8017B8F0: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8017B8F4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017B8F8: sll         $t4, $t5, 2
    ctx->r12 = S32(ctx->r13 << 2);
    // 0x8017B8FC: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8017B900: addu        $t4, $t4, $t5
    ctx->r12 = ADD32(ctx->r12, ctx->r13);
    // 0x8017B904: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8017B908: swc1        $f10, -0x29BC($at)
    MEM_W(-0X29BC, ctx->r1) = ctx->f10.u32l;
    // 0x8017B90C: lhu         $t6, 0x6E($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X6E);
    // 0x8017B910: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017B914: subu        $t4, $t4, $t5
    ctx->r12 = SUB32(ctx->r12, ctx->r13);
    // 0x8017B918: lwc1        $f18, 0x3950($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X3950);
    // 0x8017B91C: lhu         $t9, 0x6E($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X6E);
    // 0x8017B920: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8017B924: addu        $t4, $t4, $t5
    ctx->r12 = ADD32(ctx->r12, ctx->r13);
    // 0x8017B928: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8017B92C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017B930: sll         $t2, $t6, 2
    ctx->r10 = S32(ctx->r14 << 2);
    // 0x8017B934: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x8017B938: addu        $t2, $t2, $t6
    ctx->r10 = ADD32(ctx->r10, ctx->r14);
    // 0x8017B93C: sll         $t3, $t9, 2
    ctx->r11 = S32(ctx->r25 << 2);
    // 0x8017B940: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8017B944: swc1        $f18, -0x29B8($at)
    MEM_W(-0X29B8, ctx->r1) = ctx->f18.u32l;
    // 0x8017B948: addu        $t3, $t3, $t9
    ctx->r11 = ADD32(ctx->r11, ctx->r25);
    // 0x8017B94C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017B950: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8017B954: subu        $t2, $t2, $t6
    ctx->r10 = SUB32(ctx->r10, ctx->r14);
    // 0x8017B958: lwc1        $f8, 0x3954($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X3954);
    // 0x8017B95C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8017B960: subu        $t3, $t3, $t9
    ctx->r11 = SUB32(ctx->r11, ctx->r25);
    // 0x8017B964: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8017B968: addu        $t2, $t2, $t6
    ctx->r10 = ADD32(ctx->r10, ctx->r14);
    // 0x8017B96C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8017B970: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017B974: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017B978: addu        $t3, $t3, $t9
    ctx->r11 = ADD32(ctx->r11, ctx->r25);
    // 0x8017B97C: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x8017B980: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8017B984: addiu       $t0, $t0, -0x2A28
    ctx->r8 = ADD32(ctx->r8, -0X2A28);
    // 0x8017B988: addu        $t7, $t3, $t0
    ctx->r15 = ADD32(ctx->r11, ctx->r8);
    // 0x8017B98C: swc1        $f8, -0x29B4($at)
    MEM_W(-0X29B4, ctx->r1) = ctx->f8.u32l;
    // 0x8017B990: lwc1        $f6, 0x6C($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X6C);
    // 0x8017B994: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8017B998: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017B99C: addiu       $t5, $t5, -0x2A28
    ctx->r13 = ADD32(ctx->r13, -0X2A28);
    // 0x8017B9A0: sub.s       $f16, $f6, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x8017B9A4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017B9A8: addiu       $t9, $t9, -0x2A28
    ctx->r25 = ADD32(ctx->r25, -0X2A28);
    // 0x8017B9AC: swc1        $f16, 0x88($t7)
    MEM_W(0X88, ctx->r15) = ctx->f16.u32l;
    // 0x8017B9B0: lhu         $t8, 0x6E($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X6E);
    // 0x8017B9B4: lwc1        $f18, 0x24($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8017B9B8: sll         $t1, $t8, 2
    ctx->r9 = S32(ctx->r24 << 2);
    // 0x8017B9BC: addu        $t1, $t1, $t8
    ctx->r9 = ADD32(ctx->r9, ctx->r24);
    // 0x8017B9C0: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8017B9C4: subu        $t1, $t1, $t8
    ctx->r9 = SUB32(ctx->r9, ctx->r24);
    // 0x8017B9C8: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8017B9CC: addu        $t1, $t1, $t8
    ctx->r9 = ADD32(ctx->r9, ctx->r24);
    // 0x8017B9D0: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8017B9D4: addu        $t4, $t1, $t5
    ctx->r12 = ADD32(ctx->r9, ctx->r13);
    // 0x8017B9D8: lwc1        $f10, 0x70($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X70);
    // 0x8017B9DC: sub.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x8017B9E0: swc1        $f8, 0x8C($t4)
    MEM_W(0X8C, ctx->r12) = ctx->f8.u32l;
    // 0x8017B9E4: lhu         $t6, 0x6E($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X6E);
    // 0x8017B9E8: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8017B9EC: sll         $t2, $t6, 2
    ctx->r10 = S32(ctx->r14 << 2);
    // 0x8017B9F0: addu        $t2, $t2, $t6
    ctx->r10 = ADD32(ctx->r10, ctx->r14);
    // 0x8017B9F4: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8017B9F8: subu        $t2, $t2, $t6
    ctx->r10 = SUB32(ctx->r10, ctx->r14);
    // 0x8017B9FC: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8017BA00: addu        $t2, $t2, $t6
    ctx->r10 = ADD32(ctx->r10, ctx->r14);
    // 0x8017BA04: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8017BA08: addu        $t3, $t2, $t9
    ctx->r11 = ADD32(ctx->r10, ctx->r25);
    // 0x8017BA0C: lwc1        $f6, 0x74($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X74);
    // 0x8017BA10: sub.s       $f16, $f6, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x8017BA14: swc1        $f16, 0x90($t3)
    MEM_W(0X90, ctx->r11) = ctx->f16.u32l;
L_8017BA18:
    // 0x8017BA18: lhu         $t0, 0x6E($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X6E);
    // 0x8017BA1C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017BA20: addiu       $t8, $t8, -0x2A28
    ctx->r24 = ADD32(ctx->r24, -0X2A28);
    // 0x8017BA24: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x8017BA28: addu        $t7, $t7, $t0
    ctx->r15 = ADD32(ctx->r15, ctx->r8);
    // 0x8017BA2C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017BA30: subu        $t7, $t7, $t0
    ctx->r15 = SUB32(ctx->r15, ctx->r8);
    // 0x8017BA34: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017BA38: addu        $t7, $t7, $t0
    ctx->r15 = ADD32(ctx->r15, ctx->r8);
    // 0x8017BA3C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017BA40: addu        $t1, $t7, $t8
    ctx->r9 = ADD32(ctx->r15, ctx->r24);
    // 0x8017BA44: lw          $t5, 0x3C($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X3C);
    // 0x8017BA48: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017BA4C: addiu       $t9, $t9, -0x2A28
    ctx->r25 = ADD32(ctx->r25, -0X2A28);
    // 0x8017BA50: addiu       $t4, $t5, 0x1
    ctx->r12 = ADD32(ctx->r13, 0X1);
    // 0x8017BA54: sw          $t4, 0x3C($t1)
    MEM_W(0X3C, ctx->r9) = ctx->r12;
    // 0x8017BA58: lhu         $t6, 0x6E($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X6E);
    // 0x8017BA5C: sll         $t2, $t6, 2
    ctx->r10 = S32(ctx->r14 << 2);
    // 0x8017BA60: addu        $t2, $t2, $t6
    ctx->r10 = ADD32(ctx->r10, ctx->r14);
    // 0x8017BA64: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8017BA68: subu        $t2, $t2, $t6
    ctx->r10 = SUB32(ctx->r10, ctx->r14);
    // 0x8017BA6C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8017BA70: addu        $t2, $t2, $t6
    ctx->r10 = ADD32(ctx->r10, ctx->r14);
    // 0x8017BA74: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8017BA78: addu        $t3, $t2, $t9
    ctx->r11 = ADD32(ctx->r10, ctx->r25);
    // 0x8017BA7C: lw          $t0, 0x38($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X38);
    // 0x8017BA80: lw          $t7, 0x3C($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X3C);
    // 0x8017BA84: bne         $t0, $t7, L_8017BAA0
    if (ctx->r8 != ctx->r15) {
        // 0x8017BA88: nop
    
            goto L_8017BAA0;
    }
    // 0x8017BA88: nop

    // 0x8017BA8C: lw          $t8, 0x34($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X34);
    // 0x8017BA90: addiu       $t5, $t8, 0x1
    ctx->r13 = ADD32(ctx->r24, 0X1);
    // 0x8017BA94: sw          $t5, 0x34($t3)
    MEM_W(0X34, ctx->r11) = ctx->r13;
    // 0x8017BA98: jal         0x8017BCE0
    // 0x8017BA9C: lhu         $a0, 0x6E($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X6E);
    func_8017BCE0_1501A0(rdram, ctx);
        goto after_2;
    // 0x8017BA9C: lhu         $a0, 0x6E($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X6E);
    after_2:
L_8017BAA0:
    // 0x8017BAA0: lhu         $t4, 0x6E($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X6E);
    // 0x8017BAA4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017BAA8: addiu       $t6, $t6, -0x2A28
    ctx->r14 = ADD32(ctx->r14, -0X2A28);
    // 0x8017BAAC: sll         $t1, $t4, 2
    ctx->r9 = S32(ctx->r12 << 2);
    // 0x8017BAB0: addu        $t1, $t1, $t4
    ctx->r9 = ADD32(ctx->r9, ctx->r12);
    // 0x8017BAB4: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8017BAB8: subu        $t1, $t1, $t4
    ctx->r9 = SUB32(ctx->r9, ctx->r12);
    // 0x8017BABC: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8017BAC0: addu        $t1, $t1, $t4
    ctx->r9 = ADD32(ctx->r9, ctx->r12);
    // 0x8017BAC4: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8017BAC8: addu        $t2, $t1, $t6
    ctx->r10 = ADD32(ctx->r9, ctx->r14);
    // 0x8017BACC: lhu         $t9, 0x0($t2)
    ctx->r25 = MEM_HU(ctx->r10, 0X0);
    // 0x8017BAD0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8017BAD4: andi        $t0, $t9, 0x2
    ctx->r8 = ctx->r25 & 0X2;
    // 0x8017BAD8: beq         $t0, $at, L_8017BC78
    if (ctx->r8 == ctx->r1) {
        // 0x8017BADC: nop
    
            goto L_8017BC78;
    }
    // 0x8017BADC: nop

    // 0x8017BAE0: andi        $t7, $t9, 0x8
    ctx->r15 = ctx->r25 & 0X8;
    // 0x8017BAE4: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8017BAE8: beq         $t7, $at, L_8017BB54
    if (ctx->r15 == ctx->r1) {
        // 0x8017BAEC: nop
    
            goto L_8017BB54;
    }
    // 0x8017BAEC: nop

    // 0x8017BAF0: lwc1        $f10, 0x84($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X84);
    // 0x8017BAF4: lw          $a1, 0x78($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X78);
    // 0x8017BAF8: lw          $a2, 0x7C($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X7C);
    // 0x8017BAFC: lw          $a3, 0x80($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X80);
    // 0x8017BB00: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x8017BB04: jal         0x800D7120
    // 0x8017BB08: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    guAlignF_recomp(rdram, ctx);
        goto after_3;
    // 0x8017BB08: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_3:
    // 0x8017BB0C: lhu         $t8, 0x6E($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X6E);
    // 0x8017BB10: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017BB14: addiu       $t4, $t4, -0x2A28
    ctx->r12 = ADD32(ctx->r12, -0X2A28);
    // 0x8017BB18: sll         $t5, $t8, 2
    ctx->r13 = S32(ctx->r24 << 2);
    // 0x8017BB1C: addu        $t5, $t5, $t8
    ctx->r13 = ADD32(ctx->r13, ctx->r24);
    // 0x8017BB20: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8017BB24: subu        $t5, $t5, $t8
    ctx->r13 = SUB32(ctx->r13, ctx->r24);
    // 0x8017BB28: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8017BB2C: addu        $t5, $t5, $t8
    ctx->r13 = ADD32(ctx->r13, ctx->r24);
    // 0x8017BB30: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8017BB34: addiu       $t3, $t5, 0xA4
    ctx->r11 = ADD32(ctx->r13, 0XA4);
    // 0x8017BB38: addiu       $t1, $t5, 0xA4
    ctx->r9 = ADD32(ctx->r13, 0XA4);
    // 0x8017BB3C: addu        $a2, $t1, $t4
    ctx->r6 = ADD32(ctx->r9, ctx->r12);
    // 0x8017BB40: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    // 0x8017BB44: jal         0x800D6F30
    // 0x8017BB48: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    guMtxCatF_recomp(rdram, ctx);
        goto after_4;
    // 0x8017BB48: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_4:
    // 0x8017BB4C: b           L_8017BBDC
    // 0x8017BB50: nop

        goto L_8017BBDC;
    // 0x8017BB50: nop

L_8017BB54:
    // 0x8017BB54: lhu         $t6, 0x6E($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X6E);
    // 0x8017BB58: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017BB5C: addiu       $t9, $t9, -0x2A28
    ctx->r25 = ADD32(ctx->r25, -0X2A28);
    // 0x8017BB60: sll         $t0, $t6, 2
    ctx->r8 = S32(ctx->r14 << 2);
    // 0x8017BB64: addu        $t0, $t0, $t6
    ctx->r8 = ADD32(ctx->r8, ctx->r14);
    // 0x8017BB68: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8017BB6C: subu        $t0, $t0, $t6
    ctx->r8 = SUB32(ctx->r8, ctx->r14);
    // 0x8017BB70: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8017BB74: addu        $t0, $t0, $t6
    ctx->r8 = ADD32(ctx->r8, ctx->r14);
    // 0x8017BB78: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8017BB7C: addu        $t7, $t0, $t9
    ctx->r15 = ADD32(ctx->r8, ctx->r25);
    // 0x8017BB80: lwc1        $f18, 0x84($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0X84);
    // 0x8017BB84: lw          $a1, 0x78($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X78);
    // 0x8017BB88: lw          $a2, 0x7C($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X7C);
    // 0x8017BB8C: lw          $a3, 0x80($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X80);
    // 0x8017BB90: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x8017BB94: jal         0x800D7120
    // 0x8017BB98: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    guAlignF_recomp(rdram, ctx);
        goto after_5;
    // 0x8017BB98: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_5:
    // 0x8017BB9C: lhu         $t2, 0x6E($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X6E);
    // 0x8017BBA0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017BBA4: addiu       $t5, $t5, -0x2A28
    ctx->r13 = ADD32(ctx->r13, -0X2A28);
    // 0x8017BBA8: sll         $t8, $t2, 2
    ctx->r24 = S32(ctx->r10 << 2);
    // 0x8017BBAC: addu        $t8, $t8, $t2
    ctx->r24 = ADD32(ctx->r24, ctx->r10);
    // 0x8017BBB0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8017BBB4: subu        $t8, $t8, $t2
    ctx->r24 = SUB32(ctx->r24, ctx->r10);
    // 0x8017BBB8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8017BBBC: addu        $t8, $t8, $t2
    ctx->r24 = ADD32(ctx->r24, ctx->r10);
    // 0x8017BBC0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8017BBC4: addiu       $t3, $t8, 0xE4
    ctx->r11 = ADD32(ctx->r24, 0XE4);
    // 0x8017BBC8: addiu       $t1, $t8, 0xE4
    ctx->r9 = ADD32(ctx->r24, 0XE4);
    // 0x8017BBCC: addu        $a2, $t1, $t5
    ctx->r6 = ADD32(ctx->r9, ctx->r13);
    // 0x8017BBD0: addu        $a0, $t3, $t5
    ctx->r4 = ADD32(ctx->r11, ctx->r13);
    // 0x8017BBD4: jal         0x800D6F30
    // 0x8017BBD8: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    guMtxCatF_recomp(rdram, ctx);
        goto after_6;
    // 0x8017BBD8: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_6:
L_8017BBDC:
    // 0x8017BBDC: lhu         $t4, 0x6E($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X6E);
    // 0x8017BBE0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017BBE4: addiu       $t0, $t0, -0x2A28
    ctx->r8 = ADD32(ctx->r8, -0X2A28);
    // 0x8017BBE8: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x8017BBEC: addu        $t6, $t6, $t4
    ctx->r14 = ADD32(ctx->r14, ctx->r12);
    // 0x8017BBF0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8017BBF4: subu        $t6, $t6, $t4
    ctx->r14 = SUB32(ctx->r14, ctx->r12);
    // 0x8017BBF8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8017BBFC: addu        $t6, $t6, $t4
    ctx->r14 = ADD32(ctx->r14, ctx->r12);
    // 0x8017BC00: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8017BC04: addu        $t9, $t6, $t0
    ctx->r25 = ADD32(ctx->r14, ctx->r8);
    // 0x8017BC08: lw          $t7, 0x48($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X48);
    // 0x8017BC0C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017BC10: addiu       $t1, $t1, -0x2A28
    ctx->r9 = ADD32(ctx->r9, -0X2A28);
    // 0x8017BC14: addiu       $t2, $t7, 0x1
    ctx->r10 = ADD32(ctx->r15, 0X1);
    // 0x8017BC18: sw          $t2, 0x48($t9)
    MEM_W(0X48, ctx->r25) = ctx->r10;
    // 0x8017BC1C: lhu         $t3, 0x6E($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X6E);
    // 0x8017BC20: sll         $t8, $t3, 2
    ctx->r24 = S32(ctx->r11 << 2);
    // 0x8017BC24: addu        $t8, $t8, $t3
    ctx->r24 = ADD32(ctx->r24, ctx->r11);
    // 0x8017BC28: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8017BC2C: subu        $t8, $t8, $t3
    ctx->r24 = SUB32(ctx->r24, ctx->r11);
    // 0x8017BC30: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8017BC34: addu        $t8, $t8, $t3
    ctx->r24 = ADD32(ctx->r24, ctx->r11);
    // 0x8017BC38: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8017BC3C: addu        $t5, $t8, $t1
    ctx->r13 = ADD32(ctx->r24, ctx->r9);
    // 0x8017BC40: lw          $t6, 0x40($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X40);
    // 0x8017BC44: lw          $t4, 0x54($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X54);
    // 0x8017BC48: lw          $t9, 0x24($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X24);
    // 0x8017BC4C: sll         $t0, $t6, 2
    ctx->r8 = S32(ctx->r14 << 2);
    // 0x8017BC50: addu        $t0, $t0, $t6
    ctx->r8 = ADD32(ctx->r8, ctx->r14);
    // 0x8017BC54: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8017BC58: addu        $t7, $t4, $t0
    ctx->r15 = ADD32(ctx->r12, ctx->r8);
    // 0x8017BC5C: lhu         $t2, 0x0($t7)
    ctx->r10 = MEM_HU(ctx->r15, 0X0);
    // 0x8017BC60: bne         $t2, $t9, L_8017BC78
    if (ctx->r10 != ctx->r25) {
        // 0x8017BC64: nop
    
            goto L_8017BC78;
    }
    // 0x8017BC64: nop

    // 0x8017BC68: addiu       $t3, $t6, 0x1
    ctx->r11 = ADD32(ctx->r14, 0X1);
    // 0x8017BC6C: sw          $t3, 0x40($t5)
    MEM_W(0X40, ctx->r13) = ctx->r11;
    // 0x8017BC70: jal         0x8017BE5C
    // 0x8017BC74: lhu         $a0, 0x6E($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X6E);
    func_8017BE5C_1501A0(rdram, ctx);
        goto after_7;
    // 0x8017BC74: lhu         $a0, 0x6E($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X6E);
    after_7:
L_8017BC78:
    // 0x8017BC78: jal         0x80180F9C
    // 0x8017BC7C: lhu         $a0, 0x6E($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X6E);
    func_80180F9C_1501A0(rdram, ctx);
        goto after_8;
    // 0x8017BC7C: lhu         $a0, 0x6E($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X6E);
    after_8:
    // 0x8017BC80: lhu         $t8, 0x6E($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X6E);
    // 0x8017BC84: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017BC88: addiu       $t4, $t4, -0x2A28
    ctx->r12 = ADD32(ctx->r12, -0X2A28);
    // 0x8017BC8C: sll         $t1, $t8, 2
    ctx->r9 = S32(ctx->r24 << 2);
    // 0x8017BC90: addu        $t1, $t1, $t8
    ctx->r9 = ADD32(ctx->r9, ctx->r24);
    // 0x8017BC94: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8017BC98: subu        $t1, $t1, $t8
    ctx->r9 = SUB32(ctx->r9, ctx->r24);
    // 0x8017BC9C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8017BCA0: addu        $t1, $t1, $t8
    ctx->r9 = ADD32(ctx->r9, ctx->r24);
    // 0x8017BCA4: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8017BCA8: addu        $t0, $t1, $t4
    ctx->r8 = ADD32(ctx->r9, ctx->r12);
    // 0x8017BCAC: lw          $t7, 0x24($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X24);
    // 0x8017BCB0: addiu       $t2, $t7, 0x1
    ctx->r10 = ADD32(ctx->r15, 0X1);
    // 0x8017BCB4: sw          $t2, 0x24($t0)
    MEM_W(0X24, ctx->r8) = ctx->r10;
L_8017BCB8:
    // 0x8017BCB8: lhu         $t9, 0x6E($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X6E);
    // 0x8017BCBC: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x8017BCC0: andi        $t3, $t6, 0xFFFF
    ctx->r11 = ctx->r14 & 0XFFFF;
    // 0x8017BCC4: slti        $at, $t3, 0x30
    ctx->r1 = SIGNED(ctx->r11) < 0X30 ? 1 : 0;
    // 0x8017BCC8: bne         $at, $zero, L_8017AEC0
    if (ctx->r1 != 0) {
        // 0x8017BCCC: sh          $t6, 0x6E($sp)
        MEM_H(0X6E, ctx->r29) = ctx->r14;
            goto L_8017AEC0;
    }
    // 0x8017BCCC: sh          $t6, 0x6E($sp)
    MEM_H(0X6E, ctx->r29) = ctx->r14;
    // 0x8017BCD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8017BCD4: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x8017BCD8: jr          $ra
    // 0x8017BCDC: nop

    return;
    // 0x8017BCDC: nop

;}
RECOMP_FUNC void func_8017BCE0_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017BCE0: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x8017BCE4: sll         $t0, $a0, 2
    ctx->r8 = S32(ctx->r4 << 2);
    // 0x8017BCE8: addu        $t0, $t0, $a0
    ctx->r8 = ADD32(ctx->r8, ctx->r4);
    // 0x8017BCEC: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8017BCF0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8017BCF4: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8017BCF8: subu        $t0, $t0, $a0
    ctx->r8 = SUB32(ctx->r8, ctx->r4);
    // 0x8017BCFC: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8017BD00: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8017BD04: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x8017BD08: addu        $t0, $t0, $a0
    ctx->r8 = ADD32(ctx->r8, ctx->r4);
    // 0x8017BD0C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017BD10: addiu       $t7, $t7, -0x2A28
    ctx->r15 = ADD32(ctx->r15, -0X2A28);
    // 0x8017BD14: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8017BD18: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8017BD1C: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8017BD20: addu        $t1, $t0, $t7
    ctx->r9 = ADD32(ctx->r8, ctx->r15);
    // 0x8017BD24: lw          $t2, 0x34($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X34);
    // 0x8017BD28: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8017BD2C: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8017BD30: lw          $t9, 0x50($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X50);
    // 0x8017BD34: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x8017BD38: addu        $t1, $t1, $a0
    ctx->r9 = ADD32(ctx->r9, ctx->r4);
    // 0x8017BD3C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8017BD40: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8017BD44: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8017BD48: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x8017BD4C: subu        $t1, $t1, $a0
    ctx->r9 = SUB32(ctx->r9, ctx->r4);
    // 0x8017BD50: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8017BD54: addu        $t4, $t9, $t3
    ctx->r12 = ADD32(ctx->r25, ctx->r11);
    // 0x8017BD58: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x8017BD5C: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x8017BD60: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8017BD64: addu        $t1, $t1, $a0
    ctx->r9 = ADD32(ctx->r9, ctx->r4);
    // 0x8017BD68: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8017BD6C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8017BD70: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8017BD74: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8017BD78: addu        $t2, $t1, $t7
    ctx->r10 = ADD32(ctx->r9, ctx->r15);
    // 0x8017BD7C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8017BD80: sh          $t5, 0x6($sp)
    MEM_H(0X6, ctx->r29) = ctx->r13;
    // 0x8017BD84: lw          $t9, 0x34($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X34);
    // 0x8017BD88: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8017BD8C: lw          $t0, 0x50($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X50);
    // 0x8017BD90: sll         $t3, $t9, 4
    ctx->r11 = S32(ctx->r25 << 4);
    // 0x8017BD94: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8017BD98: addu        $t4, $t0, $t3
    ctx->r12 = ADD32(ctx->r8, ctx->r11);
    // 0x8017BD9C: lhu         $t5, 0x10($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X10);
    // 0x8017BDA0: bne         $t5, $at, L_8017BDF8
    if (ctx->r13 != ctx->r1) {
        // 0x8017BDA4: sh          $t5, 0x4($sp)
        MEM_H(0X4, ctx->r29) = ctx->r13;
            goto L_8017BDF8;
    }
    // 0x8017BDA4: sh          $t5, 0x4($sp)
    MEM_H(0X4, ctx->r29) = ctx->r13;
    // 0x8017BDA8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8017BDAC: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8017BDB0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8017BDB4: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x8017BDB8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8017BDBC: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x8017BDC0: addu        $t9, $t9, $a0
    ctx->r25 = ADD32(ctx->r25, ctx->r4);
    // 0x8017BDC4: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8017BDC8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8017BDCC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8017BDD0: subu        $t9, $t9, $a0
    ctx->r25 = SUB32(ctx->r25, ctx->r4);
    // 0x8017BDD4: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8017BDD8: lhu         $t1, 0x0($t8)
    ctx->r9 = MEM_HU(ctx->r24, 0X0);
    // 0x8017BDDC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8017BDE0: addu        $t9, $t9, $a0
    ctx->r25 = ADD32(ctx->r25, ctx->r4);
    // 0x8017BDE4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8017BDE8: addu        $t0, $t9, $t7
    ctx->r8 = ADD32(ctx->r25, ctx->r15);
    // 0x8017BDEC: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x8017BDF0: b           L_8017BE54
    // 0x8017BDF4: sh          $t2, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r10;
        goto L_8017BE54;
    // 0x8017BDF4: sh          $t2, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r10;
L_8017BDF8:
    // 0x8017BDF8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8017BDFC: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8017BE00: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8017BE04: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x8017BE08: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x8017BE0C: lhu         $t3, 0x4($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X4);
    // 0x8017BE10: lhu         $t4, 0x6($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X6);
    // 0x8017BE14: addu        $t8, $t8, $a0
    ctx->r24 = ADD32(ctx->r24, ctx->r4);
    // 0x8017BE18: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8017BE1C: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8017BE20: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8017BE24: subu        $t8, $t8, $a0
    ctx->r24 = SUB32(ctx->r24, ctx->r4);
    // 0x8017BE28: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8017BE2C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017BE30: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8017BE34: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8017BE38: subu        $t5, $t3, $t4
    ctx->r13 = SUB32(ctx->r11, ctx->r12);
    // 0x8017BE3C: sw          $t5, -0x29F0($at)
    MEM_W(-0X29F0, ctx->r1) = ctx->r13;
    // 0x8017BE40: addu        $t8, $t8, $a0
    ctx->r24 = ADD32(ctx->r24, ctx->r4);
    // 0x8017BE44: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8017BE48: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017BE4C: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8017BE50: sw          $zero, -0x29EC($at)
    MEM_W(-0X29EC, ctx->r1) = 0;
L_8017BE54:
    // 0x8017BE54: jr          $ra
    // 0x8017BE58: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8017BE58: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8017BE5C_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017BE5C: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x8017BE60: sll         $t0, $a0, 2
    ctx->r8 = S32(ctx->r4 << 2);
    // 0x8017BE64: addu        $t0, $t0, $a0
    ctx->r8 = ADD32(ctx->r8, ctx->r4);
    // 0x8017BE68: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8017BE6C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8017BE70: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8017BE74: subu        $t0, $t0, $a0
    ctx->r8 = SUB32(ctx->r8, ctx->r4);
    // 0x8017BE78: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8017BE7C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8017BE80: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x8017BE84: addu        $t0, $t0, $a0
    ctx->r8 = ADD32(ctx->r8, ctx->r4);
    // 0x8017BE88: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017BE8C: addiu       $t7, $t7, -0x2A28
    ctx->r15 = ADD32(ctx->r15, -0X2A28);
    // 0x8017BE90: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8017BE94: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8017BE98: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8017BE9C: addu        $t1, $t0, $t7
    ctx->r9 = ADD32(ctx->r8, ctx->r15);
    // 0x8017BEA0: lw          $t2, 0x40($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X40);
    // 0x8017BEA4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8017BEA8: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8017BEAC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8017BEB0: lw          $t9, 0x54($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X54);
    // 0x8017BEB4: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8017BEB8: sll         $t0, $a0, 2
    ctx->r8 = S32(ctx->r4 << 2);
    // 0x8017BEBC: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8017BEC0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8017BEC4: addu        $t0, $t0, $a0
    ctx->r8 = ADD32(ctx->r8, ctx->r4);
    // 0x8017BEC8: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8017BECC: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8017BED0: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x8017BED4: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8017BED8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8017BEDC: subu        $t0, $t0, $a0
    ctx->r8 = SUB32(ctx->r8, ctx->r4);
    // 0x8017BEE0: addu        $t4, $t9, $t3
    ctx->r12 = ADD32(ctx->r25, ctx->r11);
    // 0x8017BEE4: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x8017BEE8: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8017BEEC: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8017BEF0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8017BEF4: addu        $t0, $t0, $a0
    ctx->r8 = ADD32(ctx->r8, ctx->r4);
    // 0x8017BEF8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017BEFC: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8017BF00: addiu       $t1, $t1, -0x2A28
    ctx->r9 = ADD32(ctx->r9, -0X2A28);
    // 0x8017BF04: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8017BF08: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8017BF0C: sw          $t5, 0x44($t8)
    MEM_W(0X44, ctx->r24) = ctx->r13;
    // 0x8017BF10: lw          $t9, 0x44($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X44);
    // 0x8017BF14: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8017BF18: bne         $t9, $at, L_8017BF70
    if (ctx->r25 != ctx->r1) {
        // 0x8017BF1C: nop
    
            goto L_8017BF70;
    }
    // 0x8017BF1C: nop

    // 0x8017BF20: sll         $t3, $a0, 2
    ctx->r11 = S32(ctx->r4 << 2);
    // 0x8017BF24: addu        $t3, $t3, $a0
    ctx->r11 = ADD32(ctx->r11, ctx->r4);
    // 0x8017BF28: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8017BF2C: subu        $t3, $t3, $a0
    ctx->r11 = SUB32(ctx->r11, ctx->r4);
    // 0x8017BF30: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8017BF34: sll         $t5, $a0, 2
    ctx->r13 = S32(ctx->r4 << 2);
    // 0x8017BF38: addu        $t5, $t5, $a0
    ctx->r13 = ADD32(ctx->r13, ctx->r4);
    // 0x8017BF3C: addu        $t3, $t3, $a0
    ctx->r11 = ADD32(ctx->r11, ctx->r4);
    // 0x8017BF40: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8017BF44: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8017BF48: subu        $t5, $t5, $a0
    ctx->r13 = SUB32(ctx->r13, ctx->r4);
    // 0x8017BF4C: addu        $t4, $t3, $t1
    ctx->r12 = ADD32(ctx->r11, ctx->r9);
    // 0x8017BF50: lhu         $t6, 0x0($t4)
    ctx->r14 = MEM_HU(ctx->r12, 0X0);
    // 0x8017BF54: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8017BF58: addu        $t5, $t5, $a0
    ctx->r13 = ADD32(ctx->r13, ctx->r4);
    // 0x8017BF5C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8017BF60: addu        $t8, $t5, $t1
    ctx->r24 = ADD32(ctx->r13, ctx->r9);
    // 0x8017BF64: ori         $t7, $t6, 0x2
    ctx->r15 = ctx->r14 | 0X2;
    // 0x8017BF68: jr          $ra
    // 0x8017BF6C: sh          $t7, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r15;
    return;
    // 0x8017BF6C: sh          $t7, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r15;
L_8017BF70:
    // 0x8017BF70: sll         $t0, $a0, 2
    ctx->r8 = S32(ctx->r4 << 2);
    // 0x8017BF74: sll         $t4, $a0, 2
    ctx->r12 = S32(ctx->r4 << 2);
    // 0x8017BF78: addu        $t4, $t4, $a0
    ctx->r12 = ADD32(ctx->r12, ctx->r4);
    // 0x8017BF7C: addu        $t0, $t0, $a0
    ctx->r8 = ADD32(ctx->r8, ctx->r4);
    // 0x8017BF80: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8017BF84: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8017BF88: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x8017BF8C: addu        $t8, $t8, $a0
    ctx->r24 = ADD32(ctx->r24, ctx->r4);
    // 0x8017BF90: subu        $t4, $t4, $a0
    ctx->r12 = SUB32(ctx->r12, ctx->r4);
    // 0x8017BF94: subu        $t0, $t0, $a0
    ctx->r8 = SUB32(ctx->r8, ctx->r4);
    // 0x8017BF98: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8017BF9C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8017BFA0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8017BFA4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017BFA8: addiu       $t2, $t2, -0x2A28
    ctx->r10 = ADD32(ctx->r10, -0X2A28);
    // 0x8017BFAC: subu        $t8, $t8, $a0
    ctx->r24 = SUB32(ctx->r24, ctx->r4);
    // 0x8017BFB0: addu        $t4, $t4, $a0
    ctx->r12 = ADD32(ctx->r12, ctx->r4);
    // 0x8017BFB4: addu        $t0, $t0, $a0
    ctx->r8 = ADD32(ctx->r8, ctx->r4);
    // 0x8017BFB8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8017BFBC: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8017BFC0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8017BFC4: addu        $t8, $t8, $a0
    ctx->r24 = ADD32(ctx->r24, ctx->r4);
    // 0x8017BFC8: addu        $t6, $t4, $t2
    ctx->r14 = ADD32(ctx->r12, ctx->r10);
    // 0x8017BFCC: addu        $t9, $t0, $t2
    ctx->r25 = ADD32(ctx->r8, ctx->r10);
    // 0x8017BFD0: lw          $t5, 0x40($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X40);
    // 0x8017BFD4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8017BFD8: lw          $t3, 0x54($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X54);
    // 0x8017BFDC: addu        $t0, $t8, $t2
    ctx->r8 = ADD32(ctx->r24, ctx->r10);
    // 0x8017BFE0: lw          $t9, 0x44($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X44);
    // 0x8017BFE4: sll         $t1, $t5, 2
    ctx->r9 = S32(ctx->r13 << 2);
    // 0x8017BFE8: addu        $t1, $t1, $t5
    ctx->r9 = ADD32(ctx->r9, ctx->r13);
    // 0x8017BFEC: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x8017BFF0: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8017BFF4: addu        $t7, $t3, $t1
    ctx->r15 = ADD32(ctx->r11, ctx->r9);
    // 0x8017BFF8: lwc1        $f4, 0x4($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X4);
    // 0x8017BFFC: bgez        $t9, L_8017C014
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8017C000: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_8017C014;
    }
    // 0x8017C000: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8017C004: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8017C008: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017C00C: nop

    // 0x8017C010: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_8017C014:
    // 0x8017C014: sll         $t4, $a0, 2
    ctx->r12 = S32(ctx->r4 << 2);
    // 0x8017C018: addu        $t4, $t4, $a0
    ctx->r12 = ADD32(ctx->r12, ctx->r4);
    // 0x8017C01C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8017C020: subu        $t4, $t4, $a0
    ctx->r12 = SUB32(ctx->r12, ctx->r4);
    // 0x8017C024: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8017C028: addu        $t4, $t4, $a0
    ctx->r12 = ADD32(ctx->r12, ctx->r4);
    // 0x8017C02C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8017C030: addu        $t6, $t4, $t2
    ctx->r14 = ADD32(ctx->r12, ctx->r10);
    // 0x8017C034: lw          $t5, 0x24($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X24);
    // 0x8017C038: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x8017C03C: bgez        $t5, L_8017C054
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8017C040: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_8017C054;
    }
    // 0x8017C040: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8017C044: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8017C048: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017C04C: nop

    // 0x8017C050: add.s       $f18, $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f6.fl;
L_8017C054:
    // 0x8017C054: sub.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x8017C058: sll         $t3, $a0, 2
    ctx->r11 = S32(ctx->r4 << 2);
    // 0x8017C05C: addu        $t3, $t3, $a0
    ctx->r11 = ADD32(ctx->r11, ctx->r4);
    // 0x8017C060: sll         $t4, $a0, 2
    ctx->r12 = S32(ctx->r4 << 2);
    // 0x8017C064: div.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8017C068: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8017C06C: addu        $t4, $t4, $a0
    ctx->r12 = ADD32(ctx->r12, ctx->r4);
    // 0x8017C070: subu        $t3, $t3, $a0
    ctx->r11 = SUB32(ctx->r11, ctx->r4);
    // 0x8017C074: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8017C078: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8017C07C: subu        $t4, $t4, $a0
    ctx->r12 = SUB32(ctx->r12, ctx->r4);
    // 0x8017C080: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x8017C084: addu        $t3, $t3, $a0
    ctx->r11 = ADD32(ctx->r11, ctx->r4);
    // 0x8017C088: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x8017C08C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8017C090: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8017C094: addu        $t4, $t4, $a0
    ctx->r12 = ADD32(ctx->r12, ctx->r4);
    // 0x8017C098: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017C09C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017C0A0: addu        $t1, $t3, $t2
    ctx->r9 = ADD32(ctx->r11, ctx->r10);
    // 0x8017C0A4: addiu       $t8, $t8, -0x2A28
    ctx->r24 = ADD32(ctx->r24, -0X2A28);
    // 0x8017C0A8: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x8017C0AC: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8017C0B0: addu        $t6, $t4, $t8
    ctx->r14 = ADD32(ctx->r12, ctx->r24);
    // 0x8017C0B4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017C0B8: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x8017C0BC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017C0C0: swc1        $f16, 0x78($t1)
    MEM_W(0X78, ctx->r9) = ctx->f16.u32l;
    // 0x8017C0C4: lw          $t5, 0x40($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X40);
    // 0x8017C0C8: addu        $t0, $t7, $t8
    ctx->r8 = ADD32(ctx->r15, ctx->r24);
    // 0x8017C0CC: lw          $t9, 0x54($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X54);
    // 0x8017C0D0: sll         $t3, $t5, 2
    ctx->r11 = S32(ctx->r13 << 2);
    // 0x8017C0D4: addu        $t3, $t3, $t5
    ctx->r11 = ADD32(ctx->r11, ctx->r13);
    // 0x8017C0D8: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8017C0DC: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x8017C0E0: addu        $t2, $t9, $t3
    ctx->r10 = ADD32(ctx->r25, ctx->r11);
    // 0x8017C0E4: addu        $t1, $t1, $a0
    ctx->r9 = ADD32(ctx->r9, ctx->r4);
    // 0x8017C0E8: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x8017C0EC: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8017C0F0: addu        $t9, $t9, $a0
    ctx->r25 = ADD32(ctx->r25, ctx->r4);
    // 0x8017C0F4: subu        $t1, $t1, $a0
    ctx->r9 = SUB32(ctx->r9, ctx->r4);
    // 0x8017C0F8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8017C0FC: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8017C100: subu        $t9, $t9, $a0
    ctx->r25 = SUB32(ctx->r25, ctx->r4);
    // 0x8017C104: sll         $t0, $a0, 2
    ctx->r8 = S32(ctx->r4 << 2);
    // 0x8017C108: lwc1        $f6, 0x8($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X8);
    // 0x8017C10C: addu        $t1, $t1, $a0
    ctx->r9 = ADD32(ctx->r9, ctx->r4);
    // 0x8017C110: addu        $t0, $t0, $a0
    ctx->r8 = ADD32(ctx->r8, ctx->r4);
    // 0x8017C114: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8017C118: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8017C11C: addu        $t9, $t9, $a0
    ctx->r25 = ADD32(ctx->r25, ctx->r4);
    // 0x8017C120: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8017C124: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017C128: addu        $t7, $t1, $t8
    ctx->r15 = ADD32(ctx->r9, ctx->r24);
    // 0x8017C12C: addiu       $t4, $t4, -0x2A28
    ctx->r12 = ADD32(ctx->r12, -0X2A28);
    // 0x8017C130: subu        $t0, $t0, $a0
    ctx->r8 = SUB32(ctx->r8, ctx->r4);
    // 0x8017C134: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8017C138: addu        $t3, $t9, $t4
    ctx->r11 = ADD32(ctx->r25, ctx->r12);
    // 0x8017C13C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8017C140: swc1        $f6, 0x7C($t7)
    MEM_W(0X7C, ctx->r15) = ctx->f6.u32l;
    // 0x8017C144: lw          $t2, 0x40($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X40);
    // 0x8017C148: addu        $t0, $t0, $a0
    ctx->r8 = ADD32(ctx->r8, ctx->r4);
    // 0x8017C14C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8017C150: addu        $t6, $t0, $t4
    ctx->r14 = ADD32(ctx->r8, ctx->r12);
    // 0x8017C154: lw          $t5, 0x54($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X54);
    // 0x8017C158: sll         $t1, $t2, 2
    ctx->r9 = S32(ctx->r10 << 2);
    // 0x8017C15C: addu        $t1, $t1, $t2
    ctx->r9 = ADD32(ctx->r9, ctx->r10);
    // 0x8017C160: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8017C164: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x8017C168: addu        $t8, $t5, $t1
    ctx->r24 = ADD32(ctx->r13, ctx->r9);
    // 0x8017C16C: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x8017C170: sll         $t5, $a0, 2
    ctx->r13 = S32(ctx->r4 << 2);
    // 0x8017C174: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017C178: addu        $t5, $t5, $a0
    ctx->r13 = ADD32(ctx->r13, ctx->r4);
    // 0x8017C17C: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x8017C180: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8017C184: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017C188: subu        $t5, $t5, $a0
    ctx->r13 = SUB32(ctx->r13, ctx->r4);
    // 0x8017C18C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8017C190: lwc1        $f8, 0xC($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0XC);
    // 0x8017C194: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x8017C198: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8017C19C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8017C1A0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017C1A4: addu        $t5, $t5, $a0
    ctx->r13 = ADD32(ctx->r13, ctx->r4);
    // 0x8017C1A8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8017C1AC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017C1B0: addu        $t0, $t7, $t4
    ctx->r8 = ADD32(ctx->r15, ctx->r12);
    // 0x8017C1B4: addiu       $t9, $t9, -0x2A28
    ctx->r25 = ADD32(ctx->r25, -0X2A28);
    // 0x8017C1B8: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x8017C1BC: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8017C1C0: addu        $t1, $t5, $t9
    ctx->r9 = ADD32(ctx->r13, ctx->r25);
    // 0x8017C1C4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8017C1C8: swc1        $f8, 0x80($t0)
    MEM_W(0X80, ctx->r8) = ctx->f8.u32l;
    // 0x8017C1CC: lw          $t8, 0x40($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X40);
    // 0x8017C1D0: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8017C1D4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8017C1D8: addu        $t3, $t6, $t9
    ctx->r11 = ADD32(ctx->r14, ctx->r25);
    // 0x8017C1DC: sll         $t0, $a0, 2
    ctx->r8 = S32(ctx->r4 << 2);
    // 0x8017C1E0: lw          $t2, 0x54($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X54);
    // 0x8017C1E4: addu        $t0, $t0, $a0
    ctx->r8 = ADD32(ctx->r8, ctx->r4);
    // 0x8017C1E8: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x8017C1EC: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8017C1F0: addu        $t7, $t7, $t8
    ctx->r15 = ADD32(ctx->r15, ctx->r24);
    // 0x8017C1F4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017C1F8: subu        $t0, $t0, $a0
    ctx->r8 = SUB32(ctx->r8, ctx->r4);
    // 0x8017C1FC: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8017C200: addu        $t4, $t2, $t7
    ctx->r12 = ADD32(ctx->r10, ctx->r15);
    // 0x8017C204: lwc1        $f18, 0x10($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X10);
    // 0x8017C208: addu        $t0, $t0, $a0
    ctx->r8 = ADD32(ctx->r8, ctx->r4);
    // 0x8017C20C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8017C210: addu        $t6, $t0, $t9
    ctx->r14 = ADD32(ctx->r8, ctx->r25);
    // 0x8017C214: swc1        $f18, 0x84($t6)
    MEM_W(0X84, ctx->r14) = ctx->f18.u32l;
    // 0x8017C218: jr          $ra
    // 0x8017C21C: nop

    return;
    // 0x8017C21C: nop

;}
RECOMP_FUNC void func_8017C220_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017C220: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8017C224: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8017C228: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8017C22C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017C230: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8017C234: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8017C238: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8017C23C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017C240: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8017C244: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017C248: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8017C24C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017C250: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8017C254: lw          $t8, -0x2A24($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2A24);
    // 0x8017C258: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8017C25C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8017C260: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8017C264: sltiu       $at, $t9, 0xA
    ctx->r1 = ctx->r25 < 0XA ? 1 : 0;
    // 0x8017C268: beq         $at, $zero, L_8017CCD0
    if (ctx->r1 == 0) {
        // 0x8017C26C: nop
    
            goto L_8017CCD0;
    }
    // 0x8017C26C: nop

    // 0x8017C270: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8017C274: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8017C278: addu        $at, $at, $t9
    gpr jr_addend_8017C280 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8017C27C: lw          $t9, -0x430($at)
    ctx->r25 = ADD32(ctx->r1, -0X430);
    // 0x8017C280: jr          $t9
    // 0x8017C284: nop

    switch (jr_addend_8017C280 >> 2) {
        case 0: goto L_8017C288; break;
        case 1: goto L_8017C62C; break;
        case 2: goto L_8017CCD0; break;
        case 3: goto L_8017C8B0; break;
        case 4: goto L_8017C8B0; break;
        case 5: goto L_8017C8B0; break;
        case 6: goto L_8017C8B0; break;
        case 7: goto L_8017C8B0; break;
        case 8: goto L_8017CCD0; break;
        case 9: goto L_8017CBB0; break;
        default: switch_error(__func__, 0x8017C280, 0x8019FBD0);
    }
    // 0x8017C284: nop

L_8017C288:
    // 0x8017C288: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8017C28C: lw          $s0, -0x2E48($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X2E48);
    // 0x8017C290: beq         $s0, $zero, L_8017C2B0
    if (ctx->r16 == 0) {
        // 0x8017C294: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8017C2B0;
    }
    // 0x8017C294: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8017C298: beq         $s0, $at, L_8017C37C
    if (ctx->r16 == ctx->r1) {
        // 0x8017C29C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8017C37C;
    }
    // 0x8017C29C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8017C2A0: beq         $s0, $at, L_8017C450
    if (ctx->r16 == ctx->r1) {
        // 0x8017C2A4: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8017C450;
    }
    // 0x8017C2A4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8017C2A8: bne         $s0, $at, L_8017CCD0
    if (ctx->r16 != ctx->r1) {
        // 0x8017C2AC: nop
    
            goto L_8017CCD0;
    }
    // 0x8017C2AC: nop

L_8017C2B0:
    // 0x8017C2B0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017C2B4: addiu       $t0, $t0, -0x2BA8
    ctx->r8 = ADD32(ctx->r8, -0X2BA8);
    // 0x8017C2B8: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x8017C2BC: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x8017C2C0: bne         $t1, $at, L_8017C308
    if (ctx->r9 != ctx->r1) {
        // 0x8017C2C4: nop
    
            goto L_8017C308;
    }
    // 0x8017C2C4: nop

    // 0x8017C2C8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8017C2CC: jal         0x80193424
    // 0x8017C2D0: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    func_80193424_1501A0(rdram, ctx);
        goto after_0;
    // 0x8017C2D0: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    after_0:
    // 0x8017C2D4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017C2D8: addiu       $t2, $t2, -0x2E28
    ctx->r10 = ADD32(ctx->r10, -0X2E28);
    // 0x8017C2DC: lbu         $t3, 0xA($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0XA);
    // 0x8017C2E0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017C2E4: addiu       $t6, $t6, -0x2E18
    ctx->r14 = ADD32(ctx->r14, -0X2E18);
    // 0x8017C2E8: ori         $t4, $t3, 0x2
    ctx->r12 = ctx->r11 | 0X2;
    // 0x8017C2EC: sb          $t4, 0xA($t2)
    MEM_B(0XA, ctx->r10) = ctx->r12;
    // 0x8017C2F0: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x8017C2F4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017C2F8: addiu       $t7, $t7, -0x2E18
    ctx->r15 = ADD32(ctx->r15, -0X2E18);
    // 0x8017C2FC: sw          $t5, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r13;
    // 0x8017C300: b           L_8017CCD0
    // 0x8017C304: sw          $zero, 0xC($t7)
    MEM_W(0XC, ctx->r15) = 0;
        goto L_8017CCD0;
    // 0x8017C304: sw          $zero, 0xC($t7)
    MEM_W(0XC, ctx->r15) = 0;
L_8017C308:
    // 0x8017C308: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017C30C: addiu       $t8, $t8, -0x2BA8
    ctx->r24 = ADD32(ctx->r24, -0X2BA8);
    // 0x8017C310: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x8017C314: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017C318: addiu       $t1, $t1, -0x2BA8
    ctx->r9 = ADD32(ctx->r9, -0X2BA8);
    // 0x8017C31C: addiu       $t0, $t9, 0x14
    ctx->r8 = ADD32(ctx->r25, 0X14);
    // 0x8017C320: sw          $t0, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->r8;
    // 0x8017C324: lw          $t3, 0xC($t1)
    ctx->r11 = MEM_W(ctx->r9, 0XC);
    // 0x8017C328: sltiu       $at, $t3, 0x65
    ctx->r1 = ctx->r11 < 0X65 ? 1 : 0;
    // 0x8017C32C: bne         $at, $zero, L_8017C33C
    if (ctx->r1 != 0) {
        // 0x8017C330: nop
    
            goto L_8017C33C;
    }
    // 0x8017C330: nop

    // 0x8017C334: addiu       $t4, $zero, 0x64
    ctx->r12 = ADD32(0, 0X64);
    // 0x8017C338: sw          $t4, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r12;
L_8017C33C:
    // 0x8017C33C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017C340: addiu       $t2, $t2, -0x2E28
    ctx->r10 = ADD32(ctx->r10, -0X2E28);
    // 0x8017C344: lbu         $t5, 0xA($t2)
    ctx->r13 = MEM_BU(ctx->r10, 0XA);
    // 0x8017C348: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017C34C: addiu       $t9, $t9, -0x2E18
    ctx->r25 = ADD32(ctx->r25, -0X2E18);
    // 0x8017C350: ori         $t6, $t5, 0x2
    ctx->r14 = ctx->r13 | 0X2;
    // 0x8017C354: sb          $t6, 0xA($t2)
    MEM_B(0XA, ctx->r10) = ctx->r14;
    // 0x8017C358: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8017C35C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017C360: addiu       $t0, $t0, -0x2E18
    ctx->r8 = ADD32(ctx->r8, -0X2E18);
    // 0x8017C364: sw          $t7, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r15;
    // 0x8017C368: sw          $zero, 0xC($t0)
    MEM_W(0XC, ctx->r8) = 0;
    // 0x8017C36C: jal         0x800C8544
    // 0x8017C370: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    func_800C8544(rdram, ctx);
        goto after_1;
    // 0x8017C370: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    after_1:
    // 0x8017C374: b           L_8017CCD0
    // 0x8017C378: nop

        goto L_8017CCD0;
    // 0x8017C378: nop

L_8017C37C:
    // 0x8017C37C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017C380: addiu       $t8, $t8, -0x2BA8
    ctx->r24 = ADD32(ctx->r24, -0X2BA8);
    // 0x8017C384: lw          $t3, 0xC($t8)
    ctx->r11 = MEM_W(ctx->r24, 0XC);
    // 0x8017C388: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x8017C38C: bne         $t3, $at, L_8017C3D8
    if (ctx->r11 != ctx->r1) {
        // 0x8017C390: nop
    
            goto L_8017C3D8;
    }
    // 0x8017C390: nop

    // 0x8017C394: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8017C398: jal         0x80193424
    // 0x8017C39C: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    func_80193424_1501A0(rdram, ctx);
        goto after_2;
    // 0x8017C39C: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    after_2:
    // 0x8017C3A0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017C3A4: addiu       $t4, $t4, -0x2E28
    ctx->r12 = ADD32(ctx->r12, -0X2E28);
    // 0x8017C3A8: lbu         $t1, 0xA($t4)
    ctx->r9 = MEM_BU(ctx->r12, 0XA);
    // 0x8017C3AC: lui         $t6, 0x64
    ctx->r14 = S32(0X64 << 16);
    // 0x8017C3B0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017C3B4: ori         $t5, $t1, 0x2
    ctx->r13 = ctx->r9 | 0X2;
    // 0x8017C3B8: sb          $t5, 0xA($t4)
    MEM_B(0XA, ctx->r12) = ctx->r13;
    // 0x8017C3BC: addiu       $t2, $t2, -0x2E18
    ctx->r10 = ADD32(ctx->r10, -0X2E18);
    // 0x8017C3C0: ori         $t6, $t6, 0x4
    ctx->r14 = ctx->r14 | 0X4;
    // 0x8017C3C4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017C3C8: addiu       $t7, $t7, -0x2E18
    ctx->r15 = ADD32(ctx->r15, -0X2E18);
    // 0x8017C3CC: sw          $t6, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r14;
    // 0x8017C3D0: b           L_8017CCD0
    // 0x8017C3D4: sw          $zero, 0xC($t7)
    MEM_W(0XC, ctx->r15) = 0;
        goto L_8017CCD0;
    // 0x8017C3D4: sw          $zero, 0xC($t7)
    MEM_W(0XC, ctx->r15) = 0;
L_8017C3D8:
    // 0x8017C3D8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017C3DC: addiu       $t9, $t9, -0x2BA8
    ctx->r25 = ADD32(ctx->r25, -0X2BA8);
    // 0x8017C3E0: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x8017C3E4: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017C3E8: addiu       $t3, $t3, -0x2BA8
    ctx->r11 = ADD32(ctx->r11, -0X2BA8);
    // 0x8017C3EC: addiu       $t8, $t0, 0x14
    ctx->r24 = ADD32(ctx->r8, 0X14);
    // 0x8017C3F0: sw          $t8, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->r24;
    // 0x8017C3F4: lw          $t1, 0xC($t3)
    ctx->r9 = MEM_W(ctx->r11, 0XC);
    // 0x8017C3F8: sltiu       $at, $t1, 0x65
    ctx->r1 = ctx->r9 < 0X65 ? 1 : 0;
    // 0x8017C3FC: bne         $at, $zero, L_8017C40C
    if (ctx->r1 != 0) {
        // 0x8017C400: nop
    
            goto L_8017C40C;
    }
    // 0x8017C400: nop

    // 0x8017C404: addiu       $t5, $zero, 0x64
    ctx->r13 = ADD32(0, 0X64);
    // 0x8017C408: sw          $t5, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->r13;
L_8017C40C:
    // 0x8017C40C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017C410: addiu       $t4, $t4, -0x2E28
    ctx->r12 = ADD32(ctx->r12, -0X2E28);
    // 0x8017C414: lbu         $t6, 0xA($t4)
    ctx->r14 = MEM_BU(ctx->r12, 0XA);
    // 0x8017C418: lui         $t7, 0x64
    ctx->r15 = S32(0X64 << 16);
    // 0x8017C41C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017C420: ori         $t2, $t6, 0x2
    ctx->r10 = ctx->r14 | 0X2;
    // 0x8017C424: sb          $t2, 0xA($t4)
    MEM_B(0XA, ctx->r12) = ctx->r10;
    // 0x8017C428: addiu       $t0, $t0, -0x2E18
    ctx->r8 = ADD32(ctx->r8, -0X2E18);
    // 0x8017C42C: ori         $t7, $t7, 0x1
    ctx->r15 = ctx->r15 | 0X1;
    // 0x8017C430: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017C434: addiu       $t8, $t8, -0x2E18
    ctx->r24 = ADD32(ctx->r24, -0X2E18);
    // 0x8017C438: sw          $t7, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r15;
    // 0x8017C43C: sw          $zero, 0xC($t8)
    MEM_W(0XC, ctx->r24) = 0;
    // 0x8017C440: jal         0x800C8544
    // 0x8017C444: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    func_800C8544(rdram, ctx);
        goto after_3;
    // 0x8017C444: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    after_3:
    // 0x8017C448: b           L_8017CCD0
    // 0x8017C44C: nop

        goto L_8017CCD0;
    // 0x8017C44C: nop

L_8017C450:
    // 0x8017C450: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x8017C454: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017C458: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x8017C45C: subu        $t1, $t1, $t9
    ctx->r9 = SUB32(ctx->r9, ctx->r25);
    // 0x8017C460: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8017C464: addu        $t1, $t1, $t9
    ctx->r9 = ADD32(ctx->r9, ctx->r25);
    // 0x8017C468: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x8017C46C: addu        $t5, $t5, $t1
    ctx->r13 = ADD32(ctx->r13, ctx->r9);
    // 0x8017C470: lw          $t5, 0xFA0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XFA0);
    // 0x8017C474: beq         $t5, $zero, L_8017C484
    if (ctx->r13 == 0) {
        // 0x8017C478: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8017C484;
    }
    // 0x8017C478: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8017C47C: bne         $t5, $at, L_8017C558
    if (ctx->r13 != ctx->r1) {
        // 0x8017C480: nop
    
            goto L_8017C558;
    }
    // 0x8017C480: nop

L_8017C484:
    // 0x8017C484: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017C488: addiu       $t3, $t3, -0x2BA8
    ctx->r11 = ADD32(ctx->r11, -0X2BA8);
    // 0x8017C48C: lw          $t6, 0xC($t3)
    ctx->r14 = MEM_W(ctx->r11, 0XC);
    // 0x8017C490: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x8017C494: bne         $t6, $at, L_8017C4E0
    if (ctx->r14 != ctx->r1) {
        // 0x8017C498: nop
    
            goto L_8017C4E0;
    }
    // 0x8017C498: nop

    // 0x8017C49C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8017C4A0: jal         0x80193424
    // 0x8017C4A4: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    func_80193424_1501A0(rdram, ctx);
        goto after_4;
    // 0x8017C4A4: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    after_4:
    // 0x8017C4A8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017C4AC: addiu       $t2, $t2, -0x2E28
    ctx->r10 = ADD32(ctx->r10, -0X2E28);
    // 0x8017C4B0: lbu         $t4, 0xA($t2)
    ctx->r12 = MEM_BU(ctx->r10, 0XA);
    // 0x8017C4B4: lui         $t0, 0x65
    ctx->r8 = S32(0X65 << 16);
    // 0x8017C4B8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017C4BC: ori         $t7, $t4, 0x2
    ctx->r15 = ctx->r12 | 0X2;
    // 0x8017C4C0: sb          $t7, 0xA($t2)
    MEM_B(0XA, ctx->r10) = ctx->r15;
    // 0x8017C4C4: addiu       $t8, $t8, -0x2E18
    ctx->r24 = ADD32(ctx->r24, -0X2E18);
    // 0x8017C4C8: ori         $t0, $t0, 0x4
    ctx->r8 = ctx->r8 | 0X4;
    // 0x8017C4CC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017C4D0: addiu       $t9, $t9, -0x2E18
    ctx->r25 = ADD32(ctx->r25, -0X2E18);
    // 0x8017C4D4: sw          $t0, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r8;
    // 0x8017C4D8: b           L_8017CCD0
    // 0x8017C4DC: sw          $zero, 0xC($t9)
    MEM_W(0XC, ctx->r25) = 0;
        goto L_8017CCD0;
    // 0x8017C4DC: sw          $zero, 0xC($t9)
    MEM_W(0XC, ctx->r25) = 0;
L_8017C4E0:
    // 0x8017C4E0: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017C4E4: addiu       $t1, $t1, -0x2BA8
    ctx->r9 = ADD32(ctx->r9, -0X2BA8);
    // 0x8017C4E8: lw          $t5, 0xC($t1)
    ctx->r13 = MEM_W(ctx->r9, 0XC);
    // 0x8017C4EC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017C4F0: addiu       $t6, $t6, -0x2BA8
    ctx->r14 = ADD32(ctx->r14, -0X2BA8);
    // 0x8017C4F4: addiu       $t3, $t5, 0x14
    ctx->r11 = ADD32(ctx->r13, 0X14);
    // 0x8017C4F8: sw          $t3, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r11;
    // 0x8017C4FC: lw          $t4, 0xC($t6)
    ctx->r12 = MEM_W(ctx->r14, 0XC);
    // 0x8017C500: sltiu       $at, $t4, 0x65
    ctx->r1 = ctx->r12 < 0X65 ? 1 : 0;
    // 0x8017C504: bne         $at, $zero, L_8017C514
    if (ctx->r1 != 0) {
        // 0x8017C508: nop
    
            goto L_8017C514;
    }
    // 0x8017C508: nop

    // 0x8017C50C: addiu       $t7, $zero, 0x64
    ctx->r15 = ADD32(0, 0X64);
    // 0x8017C510: sw          $t7, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r15;
L_8017C514:
    // 0x8017C514: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017C518: addiu       $t2, $t2, -0x2E28
    ctx->r10 = ADD32(ctx->r10, -0X2E28);
    // 0x8017C51C: lbu         $t0, 0xA($t2)
    ctx->r8 = MEM_BU(ctx->r10, 0XA);
    // 0x8017C520: lui         $t9, 0x65
    ctx->r25 = S32(0X65 << 16);
    // 0x8017C524: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017C528: ori         $t8, $t0, 0x2
    ctx->r24 = ctx->r8 | 0X2;
    // 0x8017C52C: sb          $t8, 0xA($t2)
    MEM_B(0XA, ctx->r10) = ctx->r24;
    // 0x8017C530: addiu       $t5, $t5, -0x2E18
    ctx->r13 = ADD32(ctx->r13, -0X2E18);
    // 0x8017C534: ori         $t9, $t9, 0x1
    ctx->r25 = ctx->r25 | 0X1;
    // 0x8017C538: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017C53C: addiu       $t3, $t3, -0x2E18
    ctx->r11 = ADD32(ctx->r11, -0X2E18);
    // 0x8017C540: sw          $t9, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r25;
    // 0x8017C544: sw          $zero, 0xC($t3)
    MEM_W(0XC, ctx->r11) = 0;
    // 0x8017C548: jal         0x800C8544
    // 0x8017C54C: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    func_800C8544(rdram, ctx);
        goto after_5;
    // 0x8017C54C: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    after_5:
    // 0x8017C550: b           L_8017CCD0
    // 0x8017C554: nop

        goto L_8017CCD0;
    // 0x8017C554: nop

L_8017C558:
    // 0x8017C558: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017C55C: addiu       $t1, $t1, -0x2BA8
    ctx->r9 = ADD32(ctx->r9, -0X2BA8);
    // 0x8017C560: lw          $t4, 0x10($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X10);
    // 0x8017C564: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x8017C568: bne         $t4, $at, L_8017C5B4
    if (ctx->r12 != ctx->r1) {
        // 0x8017C56C: nop
    
            goto L_8017C5B4;
    }
    // 0x8017C56C: nop

    // 0x8017C570: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8017C574: jal         0x80193424
    // 0x8017C578: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    func_80193424_1501A0(rdram, ctx);
        goto after_6;
    // 0x8017C578: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    after_6:
    // 0x8017C57C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017C580: addiu       $t7, $t7, -0x2E28
    ctx->r15 = ADD32(ctx->r15, -0X2E28);
    // 0x8017C584: lbu         $t6, 0xA($t7)
    ctx->r14 = MEM_BU(ctx->r15, 0XA);
    // 0x8017C588: lui         $t8, 0x66
    ctx->r24 = S32(0X66 << 16);
    // 0x8017C58C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017C590: ori         $t0, $t6, 0x2
    ctx->r8 = ctx->r14 | 0X2;
    // 0x8017C594: sb          $t0, 0xA($t7)
    MEM_B(0XA, ctx->r15) = ctx->r8;
    // 0x8017C598: addiu       $t2, $t2, -0x2E18
    ctx->r10 = ADD32(ctx->r10, -0X2E18);
    // 0x8017C59C: ori         $t8, $t8, 0x4
    ctx->r24 = ctx->r24 | 0X4;
    // 0x8017C5A0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017C5A4: addiu       $t9, $t9, -0x2E18
    ctx->r25 = ADD32(ctx->r25, -0X2E18);
    // 0x8017C5A8: sw          $t8, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r24;
    // 0x8017C5AC: b           L_8017CCD0
    // 0x8017C5B0: sw          $zero, 0xC($t9)
    MEM_W(0XC, ctx->r25) = 0;
        goto L_8017CCD0;
    // 0x8017C5B0: sw          $zero, 0xC($t9)
    MEM_W(0XC, ctx->r25) = 0;
L_8017C5B4:
    // 0x8017C5B4: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017C5B8: addiu       $t5, $t5, -0x2BA8
    ctx->r13 = ADD32(ctx->r13, -0X2BA8);
    // 0x8017C5BC: lw          $t3, 0x10($t5)
    ctx->r11 = MEM_W(ctx->r13, 0X10);
    // 0x8017C5C0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017C5C4: addiu       $t4, $t4, -0x2BA8
    ctx->r12 = ADD32(ctx->r12, -0X2BA8);
    // 0x8017C5C8: addiu       $t1, $t3, 0x14
    ctx->r9 = ADD32(ctx->r11, 0X14);
    // 0x8017C5CC: sw          $t1, 0x10($t5)
    MEM_W(0X10, ctx->r13) = ctx->r9;
    // 0x8017C5D0: lw          $t6, 0x10($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X10);
    // 0x8017C5D4: sltiu       $at, $t6, 0x65
    ctx->r1 = ctx->r14 < 0X65 ? 1 : 0;
    // 0x8017C5D8: bne         $at, $zero, L_8017C5E8
    if (ctx->r1 != 0) {
        // 0x8017C5DC: nop
    
            goto L_8017C5E8;
    }
    // 0x8017C5DC: nop

    // 0x8017C5E0: addiu       $t0, $zero, 0x64
    ctx->r8 = ADD32(0, 0X64);
    // 0x8017C5E4: sw          $t0, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->r8;
L_8017C5E8:
    // 0x8017C5E8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017C5EC: addiu       $t7, $t7, -0x2E28
    ctx->r15 = ADD32(ctx->r15, -0X2E28);
    // 0x8017C5F0: lbu         $t8, 0xA($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0XA);
    // 0x8017C5F4: lui         $t9, 0x66
    ctx->r25 = S32(0X66 << 16);
    // 0x8017C5F8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017C5FC: ori         $t2, $t8, 0x2
    ctx->r10 = ctx->r24 | 0X2;
    // 0x8017C600: sb          $t2, 0xA($t7)
    MEM_B(0XA, ctx->r15) = ctx->r10;
    // 0x8017C604: addiu       $t3, $t3, -0x2E18
    ctx->r11 = ADD32(ctx->r11, -0X2E18);
    // 0x8017C608: ori         $t9, $t9, 0x1
    ctx->r25 = ctx->r25 | 0X1;
    // 0x8017C60C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017C610: addiu       $t1, $t1, -0x2E18
    ctx->r9 = ADD32(ctx->r9, -0X2E18);
    // 0x8017C614: sw          $t9, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r25;
    // 0x8017C618: sw          $zero, 0xC($t1)
    MEM_W(0XC, ctx->r9) = 0;
    // 0x8017C61C: jal         0x800C8544
    // 0x8017C620: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    func_800C8544(rdram, ctx);
        goto after_7;
    // 0x8017C620: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    after_7:
    // 0x8017C624: b           L_8017CCD0
    // 0x8017C628: nop

        goto L_8017CCD0;
    // 0x8017C628: nop

L_8017C62C:
    // 0x8017C62C: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x8017C630: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017C634: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017C638: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8017C63C: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x8017C640: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8017C644: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8017C648: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8017C64C: addu        $t0, $t0, $t6
    ctx->r8 = ADD32(ctx->r8, ctx->r14);
    // 0x8017C650: lw          $t0, 0xFA0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XFA0);
    // 0x8017C654: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8017C658: sll         $t4, $t0, 5
    ctx->r12 = S32(ctx->r8 << 5);
    // 0x8017C65C: addu        $t8, $t8, $t4
    ctx->r24 = ADD32(ctx->r24, ctx->r12);
    // 0x8017C660: lw          $t8, 0x39B0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X39B0);
    // 0x8017C664: bne         $t8, $at, L_8017C7D4
    if (ctx->r24 != ctx->r1) {
        // 0x8017C668: nop
    
            goto L_8017C7D4;
    }
    // 0x8017C668: nop

    // 0x8017C66C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8017C670: lw          $s0, -0x2E48($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X2E48);
    // 0x8017C674: beq         $s0, $zero, L_8017C694
    if (ctx->r16 == 0) {
        // 0x8017C678: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8017C694;
    }
    // 0x8017C678: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8017C67C: beq         $s0, $at, L_8017C6D4
    if (ctx->r16 == ctx->r1) {
        // 0x8017C680: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8017C6D4;
    }
    // 0x8017C680: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8017C684: beq         $s0, $at, L_8017C718
    if (ctx->r16 == ctx->r1) {
        // 0x8017C688: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8017C718;
    }
    // 0x8017C688: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8017C68C: bne         $s0, $at, L_8017C7D4
    if (ctx->r16 != ctx->r1) {
        // 0x8017C690: nop
    
            goto L_8017C7D4;
    }
    // 0x8017C690: nop

L_8017C694:
    // 0x8017C694: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8017C698: jal         0x80193424
    // 0x8017C69C: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    func_80193424_1501A0(rdram, ctx);
        goto after_8;
    // 0x8017C69C: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    after_8:
    // 0x8017C6A0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017C6A4: addiu       $t2, $t2, -0x2E28
    ctx->r10 = ADD32(ctx->r10, -0X2E28);
    // 0x8017C6A8: lbu         $t7, 0xA($t2)
    ctx->r15 = MEM_BU(ctx->r10, 0XA);
    // 0x8017C6AC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017C6B0: addiu       $t1, $t1, -0x2E18
    ctx->r9 = ADD32(ctx->r9, -0X2E18);
    // 0x8017C6B4: ori         $t9, $t7, 0x2
    ctx->r25 = ctx->r15 | 0X2;
    // 0x8017C6B8: sb          $t9, 0xA($t2)
    MEM_B(0XA, ctx->r10) = ctx->r25;
    // 0x8017C6BC: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x8017C6C0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017C6C4: addiu       $t5, $t5, -0x2E18
    ctx->r13 = ADD32(ctx->r13, -0X2E18);
    // 0x8017C6C8: sw          $t3, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r11;
    // 0x8017C6CC: b           L_8017CCD0
    // 0x8017C6D0: sw          $zero, 0xC($t5)
    MEM_W(0XC, ctx->r13) = 0;
        goto L_8017CCD0;
    // 0x8017C6D0: sw          $zero, 0xC($t5)
    MEM_W(0XC, ctx->r13) = 0;
L_8017C6D4:
    // 0x8017C6D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8017C6D8: jal         0x80193424
    // 0x8017C6DC: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    func_80193424_1501A0(rdram, ctx);
        goto after_9;
    // 0x8017C6DC: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    after_9:
    // 0x8017C6E0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017C6E4: addiu       $t6, $t6, -0x2E28
    ctx->r14 = ADD32(ctx->r14, -0X2E28);
    // 0x8017C6E8: lbu         $t0, 0xA($t6)
    ctx->r8 = MEM_BU(ctx->r14, 0XA);
    // 0x8017C6EC: lui         $t8, 0x64
    ctx->r24 = S32(0X64 << 16);
    // 0x8017C6F0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017C6F4: ori         $t4, $t0, 0x2
    ctx->r12 = ctx->r8 | 0X2;
    // 0x8017C6F8: sb          $t4, 0xA($t6)
    MEM_B(0XA, ctx->r14) = ctx->r12;
    // 0x8017C6FC: addiu       $t7, $t7, -0x2E18
    ctx->r15 = ADD32(ctx->r15, -0X2E18);
    // 0x8017C700: ori         $t8, $t8, 0x4
    ctx->r24 = ctx->r24 | 0X4;
    // 0x8017C704: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017C708: addiu       $t9, $t9, -0x2E18
    ctx->r25 = ADD32(ctx->r25, -0X2E18);
    // 0x8017C70C: sw          $t8, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r24;
    // 0x8017C710: b           L_8017CCD0
    // 0x8017C714: sw          $zero, 0xC($t9)
    MEM_W(0XC, ctx->r25) = 0;
        goto L_8017CCD0;
    // 0x8017C714: sw          $zero, 0xC($t9)
    MEM_W(0XC, ctx->r25) = 0;
L_8017C718:
    // 0x8017C718: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x8017C71C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017C720: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8017C724: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x8017C728: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8017C72C: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8017C730: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x8017C734: addu        $t1, $t1, $t3
    ctx->r9 = ADD32(ctx->r9, ctx->r11);
    // 0x8017C738: lw          $t1, 0xFA0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XFA0);
    // 0x8017C73C: beq         $t1, $zero, L_8017C74C
    if (ctx->r9 == 0) {
        // 0x8017C740: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8017C74C;
    }
    // 0x8017C740: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8017C744: bne         $t1, $at, L_8017C790
    if (ctx->r9 != ctx->r1) {
        // 0x8017C748: nop
    
            goto L_8017C790;
    }
    // 0x8017C748: nop

L_8017C74C:
    // 0x8017C74C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8017C750: jal         0x80193424
    // 0x8017C754: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    func_80193424_1501A0(rdram, ctx);
        goto after_10;
    // 0x8017C754: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    after_10:
    // 0x8017C758: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017C75C: addiu       $t5, $t5, -0x2E28
    ctx->r13 = ADD32(ctx->r13, -0X2E28);
    // 0x8017C760: lbu         $t0, 0xA($t5)
    ctx->r8 = MEM_BU(ctx->r13, 0XA);
    // 0x8017C764: lui         $t6, 0x65
    ctx->r14 = S32(0X65 << 16);
    // 0x8017C768: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017C76C: ori         $t4, $t0, 0x2
    ctx->r12 = ctx->r8 | 0X2;
    // 0x8017C770: sb          $t4, 0xA($t5)
    MEM_B(0XA, ctx->r13) = ctx->r12;
    // 0x8017C774: addiu       $t8, $t8, -0x2E18
    ctx->r24 = ADD32(ctx->r24, -0X2E18);
    // 0x8017C778: ori         $t6, $t6, 0x4
    ctx->r14 = ctx->r14 | 0X4;
    // 0x8017C77C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017C780: addiu       $t7, $t7, -0x2E18
    ctx->r15 = ADD32(ctx->r15, -0X2E18);
    // 0x8017C784: sw          $t6, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r14;
    // 0x8017C788: b           L_8017CCD0
    // 0x8017C78C: sw          $zero, 0xC($t7)
    MEM_W(0XC, ctx->r15) = 0;
        goto L_8017CCD0;
    // 0x8017C78C: sw          $zero, 0xC($t7)
    MEM_W(0XC, ctx->r15) = 0;
L_8017C790:
    // 0x8017C790: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8017C794: jal         0x80193424
    // 0x8017C798: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    func_80193424_1501A0(rdram, ctx);
        goto after_11;
    // 0x8017C798: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    after_11:
    // 0x8017C79C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017C7A0: addiu       $t9, $t9, -0x2E28
    ctx->r25 = ADD32(ctx->r25, -0X2E28);
    // 0x8017C7A4: lbu         $t2, 0xA($t9)
    ctx->r10 = MEM_BU(ctx->r25, 0XA);
    // 0x8017C7A8: lui         $t1, 0x66
    ctx->r9 = S32(0X66 << 16);
    // 0x8017C7AC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017C7B0: ori         $t3, $t2, 0x2
    ctx->r11 = ctx->r10 | 0X2;
    // 0x8017C7B4: sb          $t3, 0xA($t9)
    MEM_B(0XA, ctx->r25) = ctx->r11;
    // 0x8017C7B8: addiu       $t0, $t0, -0x2E18
    ctx->r8 = ADD32(ctx->r8, -0X2E18);
    // 0x8017C7BC: ori         $t1, $t1, 0x4
    ctx->r9 = ctx->r9 | 0X4;
    // 0x8017C7C0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017C7C4: addiu       $t4, $t4, -0x2E18
    ctx->r12 = ADD32(ctx->r12, -0X2E18);
    // 0x8017C7C8: sw          $t1, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r9;
    // 0x8017C7CC: b           L_8017CCD0
    // 0x8017C7D0: sw          $zero, 0xC($t4)
    MEM_W(0XC, ctx->r12) = 0;
        goto L_8017CCD0;
    // 0x8017C7D0: sw          $zero, 0xC($t4)
    MEM_W(0XC, ctx->r12) = 0;
L_8017C7D4:
    // 0x8017C7D4: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x8017C7D8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017C7DC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017C7E0: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8017C7E4: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x8017C7E8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8017C7EC: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8017C7F0: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8017C7F4: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x8017C7F8: lw          $t8, 0xFA0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XFA0);
    // 0x8017C7FC: addiu       $t2, $t2, 0x39A0
    ctx->r10 = ADD32(ctx->r10, 0X39A0);
    // 0x8017C800: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017C804: sll         $t7, $t8, 5
    ctx->r15 = S32(ctx->r24 << 5);
    // 0x8017C808: addu        $t3, $t7, $t2
    ctx->r11 = ADD32(ctx->r15, ctx->r10);
    // 0x8017C80C: lw          $t9, 0x10($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X10);
    // 0x8017C810: addiu       $t0, $t0, -0x2E28
    ctx->r8 = ADD32(ctx->r8, -0X2E28);
    // 0x8017C814: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017C818: addiu       $t1, $t9, 0x1
    ctx->r9 = ADD32(ctx->r25, 0X1);
    // 0x8017C81C: sw          $t1, 0x10($t3)
    MEM_W(0X10, ctx->r11) = ctx->r9;
    // 0x8017C820: lbu         $t4, 0xA($t0)
    ctx->r12 = MEM_BU(ctx->r8, 0XA);
    // 0x8017C824: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017C828: addiu       $t1, $t1, -0x2E18
    ctx->r9 = ADD32(ctx->r9, -0X2E18);
    // 0x8017C82C: ori         $t5, $t4, 0x2
    ctx->r13 = ctx->r12 | 0X2;
    // 0x8017C830: sb          $t5, 0xA($t0)
    MEM_B(0XA, ctx->r8) = ctx->r13;
    // 0x8017C834: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8017C838: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017C83C: addiu       $t3, $t3, -0x2E18
    ctx->r11 = ADD32(ctx->r11, -0X2E18);
    // 0x8017C840: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x8017C844: subu        $t8, $t8, $t6
    ctx->r24 = SUB32(ctx->r24, ctx->r14);
    // 0x8017C848: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8017C84C: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x8017C850: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8017C854: addu        $t7, $t7, $t8
    ctx->r15 = ADD32(ctx->r15, ctx->r24);
    // 0x8017C858: lw          $t7, 0xFA0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XFA0);
    // 0x8017C85C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017C860: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017C864: sll         $t2, $t7, 16
    ctx->r10 = S32(ctx->r15 << 16);
    // 0x8017C868: ori         $t9, $t2, 0x2
    ctx->r25 = ctx->r10 | 0X2;
    // 0x8017C86C: sw          $t9, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r25;
    // 0x8017C870: sw          $zero, 0xC($t3)
    MEM_W(0XC, ctx->r11) = 0;
    // 0x8017C874: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x8017C878: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    // 0x8017C87C: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8017C880: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x8017C884: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8017C888: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8017C88C: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8017C890: addu        $t0, $t0, $t5
    ctx->r8 = ADD32(ctx->r8, ctx->r13);
    // 0x8017C894: lw          $t0, 0xFA0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XFA0);
    // 0x8017C898: sll         $t6, $t0, 2
    ctx->r14 = S32(ctx->r8 << 2);
    // 0x8017C89C: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8017C8A0: jal         0x800C8544
    // 0x8017C8A4: sw          $zero, -0x2B7C($at)
    MEM_W(-0X2B7C, ctx->r1) = 0;
    func_800C8544(rdram, ctx);
        goto after_12;
    // 0x8017C8A4: sw          $zero, -0x2B7C($at)
    MEM_W(-0X2B7C, ctx->r1) = 0;
    after_12:
    // 0x8017C8A8: b           L_8017CCD0
    // 0x8017C8AC: nop

        goto L_8017CCD0;
    // 0x8017C8AC: nop

L_8017C8B0:
    // 0x8017C8B0: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x8017C8B4: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x8017C8B8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017C8BC: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x8017C8C0: addu        $t7, $t7, $t8
    ctx->r15 = ADD32(ctx->r15, ctx->r24);
    // 0x8017C8C4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017C8C8: subu        $t7, $t7, $t8
    ctx->r15 = SUB32(ctx->r15, ctx->r24);
    // 0x8017C8CC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017C8D0: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8017C8D4: addu        $t7, $t7, $t8
    ctx->r15 = ADD32(ctx->r15, ctx->r24);
    // 0x8017C8D8: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x8017C8DC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017C8E0: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8017C8E4: addu        $t2, $t2, $t7
    ctx->r10 = ADD32(ctx->r10, ctx->r15);
    // 0x8017C8E8: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8017C8EC: lw          $t2, -0x2A24($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2A24);
    // 0x8017C8F0: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8017C8F4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017C8F8: addu        $t0, $t0, $t5
    ctx->r8 = ADD32(ctx->r8, ctx->r13);
    // 0x8017C8FC: lw          $t0, 0xFA0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XFA0);
    // 0x8017C900: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8017C904: addiu       $t9, $t2, -0x4
    ctx->r25 = ADD32(ctx->r10, -0X4);
    // 0x8017C908: sllv        $t3, $t1, $t9
    ctx->r11 = S32(ctx->r9 << (ctx->r25 & 31));
    // 0x8017C90C: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x8017C910: beq         $t0, $zero, L_8017C924
    if (ctx->r8 == 0) {
        // 0x8017C914: sw          $t3, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r11;
            goto L_8017C924;
    }
    // 0x8017C914: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x8017C918: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8017C91C: bne         $t0, $at, L_8017CA64
    if (ctx->r8 != ctx->r1) {
        // 0x8017C920: nop
    
            goto L_8017CA64;
    }
    // 0x8017C920: nop

L_8017C924:
    // 0x8017C924: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017C928: addiu       $t6, $t6, -0x2E18
    ctx->r14 = ADD32(ctx->r14, -0X2E18);
    // 0x8017C92C: lw          $t8, 0x48($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X48);
    // 0x8017C930: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8017C934: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017C938: addiu       $t1, $t1, -0x2E18
    ctx->r9 = ADD32(ctx->r9, -0X2E18);
    // 0x8017C93C: or          $t2, $t8, $t7
    ctx->r10 = ctx->r24 | ctx->r15;
    // 0x8017C940: sw          $t2, 0x48($t6)
    MEM_W(0X48, ctx->r14) = ctx->r10;
    // 0x8017C944: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8017C948: lw          $t9, 0x4C($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X4C);
    // 0x8017C94C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8017C950: xor         $t4, $t3, $at
    ctx->r12 = ctx->r11 ^ ctx->r1;
    // 0x8017C954: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017C958: and         $t5, $t9, $t4
    ctx->r13 = ctx->r25 & ctx->r12;
    // 0x8017C95C: sw          $t5, 0x4C($t1)
    MEM_W(0X4C, ctx->r9) = ctx->r13;
    // 0x8017C960: addiu       $t0, $t0, 0x39A0
    ctx->r8 = ADD32(ctx->r8, 0X39A0);
    // 0x8017C964: lw          $t8, 0x8($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X8);
    // 0x8017C968: bne         $t8, $at, L_8017C988
    if (ctx->r24 != ctx->r1) {
        // 0x8017C96C: nop
    
            goto L_8017C988;
    }
    // 0x8017C96C: nop

    // 0x8017C970: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8017C974: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017C978: addiu       $t2, $t2, 0x39A0
    ctx->r10 = ADD32(ctx->r10, 0X39A0);
    // 0x8017C97C: sw          $t7, 0x48($t0)
    MEM_W(0X48, ctx->r8) = ctx->r15;
    // 0x8017C980: lw          $t6, 0x48($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X48);
    // 0x8017C984: sw          $t6, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r14;
L_8017C988:
    // 0x8017C988: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017C98C: addiu       $t3, $t3, 0x39A0
    ctx->r11 = ADD32(ctx->r11, 0X39A0);
    // 0x8017C990: lw          $t9, 0x28($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X28);
    // 0x8017C994: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x8017C998: bne         $t9, $t4, L_8017CA24
    if (ctx->r25 != ctx->r12) {
        // 0x8017C99C: nop
    
            goto L_8017CA24;
    }
    // 0x8017C99C: nop

    // 0x8017C9A0: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_8017C9A4:
    // 0x8017C9A4: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017C9A8: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8017C9AC: addiu       $t5, $t5, -0x2E18
    ctx->r13 = ADD32(ctx->r13, -0X2E18);
    // 0x8017C9B0: lw          $t1, 0x4C($t5)
    ctx->r9 = MEM_W(ctx->r13, 0X4C);
    // 0x8017C9B4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8017C9B8: sllv        $t0, $t7, $t8
    ctx->r8 = S32(ctx->r15 << (ctx->r24 & 31));
    // 0x8017C9BC: and         $t6, $t1, $t0
    ctx->r14 = ctx->r9 & ctx->r8;
    // 0x8017C9C0: bne         $t6, $zero, L_8017C9DC
    if (ctx->r14 != 0) {
        // 0x8017C9C4: nop
    
            goto L_8017C9DC;
    }
    // 0x8017C9C4: nop

    // 0x8017C9C8: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8017C9CC: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8017C9D0: sltiu       $at, $t3, 0x5
    ctx->r1 = ctx->r11 < 0X5 ? 1 : 0;
    // 0x8017C9D4: bne         $at, $zero, L_8017C9A4
    if (ctx->r1 != 0) {
        // 0x8017C9D8: sw          $t3, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r11;
            goto L_8017C9A4;
    }
    // 0x8017C9D8: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
L_8017C9DC:
    // 0x8017C9DC: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8017C9E0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8017C9E4: bne         $t9, $at, L_8017C9F4
    if (ctx->r25 != ctx->r1) {
        // 0x8017C9E8: nop
    
            goto L_8017C9F4;
    }
    // 0x8017C9E8: nop

    // 0x8017C9EC: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x8017C9F0: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
L_8017C9F4:
    // 0x8017C9F4: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8017C9F8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017C9FC: addiu       $t7, $t7, 0x39A0
    ctx->r15 = ADD32(ctx->r15, 0X39A0);
    // 0x8017CA00: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017CA04: addiu       $t8, $t8, 0x39A0
    ctx->r24 = ADD32(ctx->r24, 0X39A0);
    // 0x8017CA08: sw          $t5, 0x68($t7)
    MEM_W(0X68, ctx->r15) = ctx->r13;
    // 0x8017CA0C: lw          $t1, 0x68($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X68);
    // 0x8017CA10: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8017CA14: jal         0x80173864
    // 0x8017CA18: sw          $t1, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r9;
    func_80173864_1501A0(rdram, ctx);
        goto after_13;
    // 0x8017CA18: sw          $t1, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r9;
    after_13:
    // 0x8017CA1C: jal         0x80173864
    // 0x8017CA20: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_80173864_1501A0(rdram, ctx);
        goto after_14;
    // 0x8017CA20: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_14:
L_8017CA24:
    // 0x8017CA24: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017CA28: addiu       $t0, $t0, -0x2E28
    ctx->r8 = ADD32(ctx->r8, -0X2E28);
    // 0x8017CA2C: lbu         $t6, 0xA($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0XA);
    // 0x8017CA30: lui         $at, 0x65
    ctx->r1 = S32(0X65 << 16);
    // 0x8017CA34: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017CA38: ori         $t2, $t6, 0x2
    ctx->r10 = ctx->r14 | 0X2;
    // 0x8017CA3C: sb          $t2, 0xA($t0)
    MEM_B(0XA, ctx->r8) = ctx->r10;
    // 0x8017CA40: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8017CA44: addiu       $t5, $t5, -0x2E18
    ctx->r13 = ADD32(ctx->r13, -0X2E18);
    // 0x8017CA48: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017CA4C: addiu       $t9, $t3, 0xA
    ctx->r25 = ADD32(ctx->r11, 0XA);
    // 0x8017CA50: or          $t4, $t9, $at
    ctx->r12 = ctx->r25 | ctx->r1;
    // 0x8017CA54: sw          $t4, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r12;
    // 0x8017CA58: addiu       $t7, $t7, -0x2E18
    ctx->r15 = ADD32(ctx->r15, -0X2E18);
    // 0x8017CA5C: b           L_8017CBA0
    // 0x8017CA60: sw          $zero, 0xC($t7)
    MEM_W(0XC, ctx->r15) = 0;
        goto L_8017CBA0;
    // 0x8017CA60: sw          $zero, 0xC($t7)
    MEM_W(0XC, ctx->r15) = 0;
L_8017CA64:
    // 0x8017CA64: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017CA68: addiu       $t1, $t1, -0x2E18
    ctx->r9 = ADD32(ctx->r9, -0X2E18);
    // 0x8017CA6C: lw          $t8, 0x4C($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X4C);
    // 0x8017CA70: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8017CA74: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017CA78: addiu       $t0, $t0, -0x2E18
    ctx->r8 = ADD32(ctx->r8, -0X2E18);
    // 0x8017CA7C: or          $t2, $t8, $t6
    ctx->r10 = ctx->r24 | ctx->r14;
    // 0x8017CA80: sw          $t2, 0x4C($t1)
    MEM_W(0X4C, ctx->r9) = ctx->r10;
    // 0x8017CA84: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8017CA88: lw          $t3, 0x48($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X48);
    // 0x8017CA8C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8017CA90: xor         $t4, $t9, $at
    ctx->r12 = ctx->r25 ^ ctx->r1;
    // 0x8017CA94: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017CA98: and         $t5, $t3, $t4
    ctx->r13 = ctx->r11 & ctx->r12;
    // 0x8017CA9C: sw          $t5, 0x48($t0)
    MEM_W(0X48, ctx->r8) = ctx->r13;
    // 0x8017CAA0: addiu       $t7, $t7, 0x39A0
    ctx->r15 = ADD32(ctx->r15, 0X39A0);
    // 0x8017CAA4: lw          $t8, 0x28($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X28);
    // 0x8017CAA8: bne         $t8, $at, L_8017CAC8
    if (ctx->r24 != ctx->r1) {
        // 0x8017CAAC: nop
    
            goto L_8017CAC8;
    }
    // 0x8017CAAC: nop

    // 0x8017CAB0: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8017CAB4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017CAB8: addiu       $t2, $t2, 0x39A0
    ctx->r10 = ADD32(ctx->r10, 0X39A0);
    // 0x8017CABC: sw          $t6, 0x68($t7)
    MEM_W(0X68, ctx->r15) = ctx->r14;
    // 0x8017CAC0: lw          $t1, 0x68($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X68);
    // 0x8017CAC4: sw          $t1, 0x28($t2)
    MEM_W(0X28, ctx->r10) = ctx->r9;
L_8017CAC8:
    // 0x8017CAC8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017CACC: addiu       $t9, $t9, 0x39A0
    ctx->r25 = ADD32(ctx->r25, 0X39A0);
    // 0x8017CAD0: lw          $t3, 0x8($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X8);
    // 0x8017CAD4: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x8017CAD8: bne         $t3, $t4, L_8017CB64
    if (ctx->r11 != ctx->r12) {
        // 0x8017CADC: nop
    
            goto L_8017CB64;
    }
    // 0x8017CADC: nop

    // 0x8017CAE0: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_8017CAE4:
    // 0x8017CAE4: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017CAE8: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8017CAEC: addiu       $t5, $t5, -0x2E18
    ctx->r13 = ADD32(ctx->r13, -0X2E18);
    // 0x8017CAF0: lw          $t0, 0x48($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X48);
    // 0x8017CAF4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8017CAF8: sllv        $t7, $t6, $t8
    ctx->r15 = S32(ctx->r14 << (ctx->r24 & 31));
    // 0x8017CAFC: and         $t1, $t0, $t7
    ctx->r9 = ctx->r8 & ctx->r15;
    // 0x8017CB00: bne         $t1, $zero, L_8017CB1C
    if (ctx->r9 != 0) {
        // 0x8017CB04: nop
    
            goto L_8017CB1C;
    }
    // 0x8017CB04: nop

    // 0x8017CB08: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8017CB0C: addiu       $t9, $t2, 0x1
    ctx->r25 = ADD32(ctx->r10, 0X1);
    // 0x8017CB10: sltiu       $at, $t9, 0x5
    ctx->r1 = ctx->r25 < 0X5 ? 1 : 0;
    // 0x8017CB14: bne         $at, $zero, L_8017CAE4
    if (ctx->r1 != 0) {
        // 0x8017CB18: sw          $t9, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r25;
            goto L_8017CAE4;
    }
    // 0x8017CB18: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
L_8017CB1C:
    // 0x8017CB1C: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x8017CB20: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8017CB24: bne         $t3, $at, L_8017CB34
    if (ctx->r11 != ctx->r1) {
        // 0x8017CB28: nop
    
            goto L_8017CB34;
    }
    // 0x8017CB28: nop

    // 0x8017CB2C: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x8017CB30: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
L_8017CB34:
    // 0x8017CB34: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8017CB38: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017CB3C: addiu       $t6, $t6, 0x39A0
    ctx->r14 = ADD32(ctx->r14, 0X39A0);
    // 0x8017CB40: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017CB44: addiu       $t8, $t8, 0x39A0
    ctx->r24 = ADD32(ctx->r24, 0X39A0);
    // 0x8017CB48: sw          $t5, 0x48($t6)
    MEM_W(0X48, ctx->r14) = ctx->r13;
    // 0x8017CB4C: lw          $t0, 0x48($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X48);
    // 0x8017CB50: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8017CB54: jal         0x80173864
    // 0x8017CB58: sw          $t0, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r8;
    func_80173864_1501A0(rdram, ctx);
        goto after_15;
    // 0x8017CB58: sw          $t0, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r8;
    after_15:
    // 0x8017CB5C: jal         0x80173864
    // 0x8017CB60: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_80173864_1501A0(rdram, ctx);
        goto after_16;
    // 0x8017CB60: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_16:
L_8017CB64:
    // 0x8017CB64: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017CB68: addiu       $t7, $t7, -0x2E28
    ctx->r15 = ADD32(ctx->r15, -0X2E28);
    // 0x8017CB6C: lbu         $t1, 0xA($t7)
    ctx->r9 = MEM_BU(ctx->r15, 0XA);
    // 0x8017CB70: lui         $at, 0x66
    ctx->r1 = S32(0X66 << 16);
    // 0x8017CB74: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017CB78: ori         $t2, $t1, 0x2
    ctx->r10 = ctx->r9 | 0X2;
    // 0x8017CB7C: sb          $t2, 0xA($t7)
    MEM_B(0XA, ctx->r15) = ctx->r10;
    // 0x8017CB80: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8017CB84: addiu       $t5, $t5, -0x2E18
    ctx->r13 = ADD32(ctx->r13, -0X2E18);
    // 0x8017CB88: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017CB8C: addiu       $t3, $t9, 0xA
    ctx->r11 = ADD32(ctx->r25, 0XA);
    // 0x8017CB90: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x8017CB94: sw          $t4, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r12;
    // 0x8017CB98: addiu       $t6, $t6, -0x2E18
    ctx->r14 = ADD32(ctx->r14, -0X2E18);
    // 0x8017CB9C: sw          $zero, 0xC($t6)
    MEM_W(0XC, ctx->r14) = 0;
L_8017CBA0:
    // 0x8017CBA0: jal         0x800C8544
    // 0x8017CBA4: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    func_800C8544(rdram, ctx);
        goto after_17;
    // 0x8017CBA4: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    after_17:
    // 0x8017CBA8: b           L_8017CCD0
    // 0x8017CBAC: nop

        goto L_8017CCD0;
    // 0x8017CBAC: nop

L_8017CBB0:
    // 0x8017CBB0: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8017CBB4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017CBB8: sll         $t8, $t0, 2
    ctx->r24 = S32(ctx->r8 << 2);
    // 0x8017CBBC: subu        $t8, $t8, $t0
    ctx->r24 = SUB32(ctx->r24, ctx->r8);
    // 0x8017CBC0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8017CBC4: addu        $t8, $t8, $t0
    ctx->r24 = ADD32(ctx->r24, ctx->r8);
    // 0x8017CBC8: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8017CBCC: addu        $t1, $t1, $t8
    ctx->r9 = ADD32(ctx->r9, ctx->r24);
    // 0x8017CBD0: lw          $t1, 0xFA0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XFA0);
    // 0x8017CBD4: beq         $t1, $zero, L_8017CBE4
    if (ctx->r9 == 0) {
        // 0x8017CBD8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8017CBE4;
    }
    // 0x8017CBD8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8017CBDC: bne         $t1, $at, L_8017CC58
    if (ctx->r9 != ctx->r1) {
        // 0x8017CBE0: nop
    
            goto L_8017CC58;
    }
    // 0x8017CBE0: nop

L_8017CBE4:
    // 0x8017CBE4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017CBE8: addiu       $t2, $t2, -0x2E18
    ctx->r10 = ADD32(ctx->r10, -0X2E18);
    // 0x8017CBEC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017CBF0: addiu       $t9, $t9, 0x39A0
    ctx->r25 = ADD32(ctx->r25, 0X39A0);
    // 0x8017CBF4: sw          $zero, 0x48($t2)
    MEM_W(0X48, ctx->r10) = 0;
    // 0x8017CBF8: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8017CBFC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017CC00: addiu       $t3, $t3, 0x39A0
    ctx->r11 = ADD32(ctx->r11, 0X39A0);
    // 0x8017CC04: sw          $t7, 0x48($t9)
    MEM_W(0X48, ctx->r25) = ctx->r15;
    // 0x8017CC08: lw          $t4, 0x48($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X48);
    // 0x8017CC0C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8017CC10: jal         0x80173864
    // 0x8017CC14: sw          $t4, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r12;
    func_80173864_1501A0(rdram, ctx);
        goto after_18;
    // 0x8017CC14: sw          $t4, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r12;
    after_18:
    // 0x8017CC18: jal         0x80173864
    // 0x8017CC1C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_80173864_1501A0(rdram, ctx);
        goto after_19;
    // 0x8017CC1C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_19:
    // 0x8017CC20: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017CC24: addiu       $t5, $t5, -0x2E28
    ctx->r13 = ADD32(ctx->r13, -0X2E28);
    // 0x8017CC28: lbu         $t6, 0xA($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0XA);
    // 0x8017CC2C: lui         $t8, 0x65
    ctx->r24 = S32(0X65 << 16);
    // 0x8017CC30: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017CC34: ori         $t0, $t6, 0x2
    ctx->r8 = ctx->r14 | 0X2;
    // 0x8017CC38: sb          $t0, 0xA($t5)
    MEM_B(0XA, ctx->r13) = ctx->r8;
    // 0x8017CC3C: addiu       $t1, $t1, -0x2E18
    ctx->r9 = ADD32(ctx->r9, -0X2E18);
    // 0x8017CC40: ori         $t8, $t8, 0x14
    ctx->r24 = ctx->r24 | 0X14;
    // 0x8017CC44: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017CC48: addiu       $t2, $t2, -0x2E18
    ctx->r10 = ADD32(ctx->r10, -0X2E18);
    // 0x8017CC4C: sw          $t8, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r24;
    // 0x8017CC50: b           L_8017CCC8
    // 0x8017CC54: sw          $zero, 0xC($t2)
    MEM_W(0XC, ctx->r10) = 0;
        goto L_8017CCC8;
    // 0x8017CC54: sw          $zero, 0xC($t2)
    MEM_W(0XC, ctx->r10) = 0;
L_8017CC58:
    // 0x8017CC58: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017CC5C: addiu       $t7, $t7, -0x2E18
    ctx->r15 = ADD32(ctx->r15, -0X2E18);
    // 0x8017CC60: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017CC64: addiu       $t4, $t4, 0x39A0
    ctx->r12 = ADD32(ctx->r12, 0X39A0);
    // 0x8017CC68: sw          $zero, 0x4C($t7)
    MEM_W(0X4C, ctx->r15) = 0;
    // 0x8017CC6C: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8017CC70: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017CC74: addiu       $t3, $t3, 0x39A0
    ctx->r11 = ADD32(ctx->r11, 0X39A0);
    // 0x8017CC78: sw          $t9, 0x68($t4)
    MEM_W(0X68, ctx->r12) = ctx->r25;
    // 0x8017CC7C: lw          $t6, 0x68($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X68);
    // 0x8017CC80: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8017CC84: jal         0x80173864
    // 0x8017CC88: sw          $t6, 0x28($t3)
    MEM_W(0X28, ctx->r11) = ctx->r14;
    func_80173864_1501A0(rdram, ctx);
        goto after_20;
    // 0x8017CC88: sw          $t6, 0x28($t3)
    MEM_W(0X28, ctx->r11) = ctx->r14;
    after_20:
    // 0x8017CC8C: jal         0x80173864
    // 0x8017CC90: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_80173864_1501A0(rdram, ctx);
        goto after_21;
    // 0x8017CC90: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_21:
    // 0x8017CC94: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017CC98: addiu       $t0, $t0, -0x2E28
    ctx->r8 = ADD32(ctx->r8, -0X2E28);
    // 0x8017CC9C: lbu         $t5, 0xA($t0)
    ctx->r13 = MEM_BU(ctx->r8, 0XA);
    // 0x8017CCA0: lui         $t1, 0x66
    ctx->r9 = S32(0X66 << 16);
    // 0x8017CCA4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017CCA8: ori         $t8, $t5, 0x2
    ctx->r24 = ctx->r13 | 0X2;
    // 0x8017CCAC: sb          $t8, 0xA($t0)
    MEM_B(0XA, ctx->r8) = ctx->r24;
    // 0x8017CCB0: addiu       $t2, $t2, -0x2E18
    ctx->r10 = ADD32(ctx->r10, -0X2E18);
    // 0x8017CCB4: ori         $t1, $t1, 0x14
    ctx->r9 = ctx->r9 | 0X14;
    // 0x8017CCB8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017CCBC: addiu       $t7, $t7, -0x2E18
    ctx->r15 = ADD32(ctx->r15, -0X2E18);
    // 0x8017CCC0: sw          $t1, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r9;
    // 0x8017CCC4: sw          $zero, 0xC($t7)
    MEM_W(0XC, ctx->r15) = 0;
L_8017CCC8:
    // 0x8017CCC8: jal         0x800C8544
    // 0x8017CCCC: addiu       $a0, $zero, 0x76
    ctx->r4 = ADD32(0, 0X76);
    func_800C8544(rdram, ctx);
        goto after_22;
    // 0x8017CCCC: addiu       $a0, $zero, 0x76
    ctx->r4 = ADD32(0, 0X76);
    after_22:
L_8017CCD0:
    // 0x8017CCD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8017CCD4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8017CCD8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8017CCDC: jr          $ra
    // 0x8017CCE0: nop

    return;
    // 0x8017CCE0: nop

;}
RECOMP_FUNC void func_8017CCE4_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017CCE4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017CCE8: lw          $t6, -0x2E44($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2E44);
    // 0x8017CCEC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017CCF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017CCF4: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8017CCF8: sltiu       $at, $t7, 0x6
    ctx->r1 = ctx->r15 < 0X6 ? 1 : 0;
    // 0x8017CCFC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8017CD00: beq         $at, $zero, L_8017CD84
    if (ctx->r1 == 0) {
        // 0x8017CD04: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_8017CD84;
    }
    // 0x8017CD04: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8017CD08: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017CD0C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8017CD10: addu        $at, $at, $t7
    gpr jr_addend_8017CD18 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8017CD14: lw          $t7, -0x408($at)
    ctx->r15 = ADD32(ctx->r1, -0X408);
    // 0x8017CD18: jr          $t7
    // 0x8017CD1C: nop

    switch (jr_addend_8017CD18 >> 2) {
        case 0: goto L_8017CD20; break;
        case 1: goto L_8017CD34; break;
        case 2: goto L_8017CD48; break;
        case 3: goto L_8017CD5C; break;
        case 4: goto L_8017CD6C; break;
        case 5: goto L_8017CD7C; break;
        default: switch_error(__func__, 0x8017CD18, 0x8019FBF8);
    }
    // 0x8017CD1C: nop

L_8017CD20:
    // 0x8017CD20: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8017CD24: jal         0x801D6178
    // 0x8017CD28: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_801D6178_1B66F0(rdram, ctx);
        goto after_0;
    // 0x8017CD28: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_0:
    // 0x8017CD2C: b           L_8017CD84
    // 0x8017CD30: nop

        goto L_8017CD84;
    // 0x8017CD30: nop

L_8017CD34:
    // 0x8017CD34: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8017CD38: jal         0x801D597C
    // 0x8017CD3C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_801D597C_255660(rdram, ctx);
        goto after_1;
    // 0x8017CD3C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x8017CD40: b           L_8017CD84
    // 0x8017CD44: nop

        goto L_8017CD84;
    // 0x8017CD44: nop

L_8017CD48:
    // 0x8017CD48: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8017CD4C: jal         0x801D4344
    // 0x8017CD50: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_801D4344_34B590(rdram, ctx);
        goto after_2;
    // 0x8017CD50: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x8017CD54: b           L_8017CD84
    // 0x8017CD58: nop

        goto L_8017CD84;
    // 0x8017CD58: nop

L_8017CD5C:
    // 0x8017CD5C: jal         0x801D3CB4
    // 0x8017CD60: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_801D3CB4_3EFDD0(rdram, ctx);
        goto after_3;
    // 0x8017CD60: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x8017CD64: b           L_8017CD84
    // 0x8017CD68: nop

        goto L_8017CD84;
    // 0x8017CD68: nop

L_8017CD6C:
    // 0x8017CD6C: jal         0x801D3360
    // 0x8017CD70: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_801D3360_497140(rdram, ctx);
        goto after_4;
    // 0x8017CD70: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_4:
    // 0x8017CD74: b           L_8017CD84
    // 0x8017CD78: nop

        goto L_8017CD84;
    // 0x8017CD78: nop

L_8017CD7C:
    // 0x8017CD7C: jal         0x801D3D9C
    // 0x8017CD80: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_801D3D9C_4DC6D0(rdram, ctx);
        goto after_5;
    // 0x8017CD80: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_5:
L_8017CD84:
    // 0x8017CD84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017CD88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017CD8C: jr          $ra
    // 0x8017CD90: nop

    return;
    // 0x8017CD90: nop

;}
RECOMP_FUNC void func_8017CD94_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017CD94: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8017CD98: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017CD9C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8017CDA0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8017CDA4: addiu       $t6, $t6, -0x2E28
    ctx->r14 = ADD32(ctx->r14, -0X2E28);
    // 0x8017CDA8: lbu         $t7, 0xA($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0XA);
    // 0x8017CDAC: andi        $t8, $t7, 0x4
    ctx->r24 = ctx->r15 & 0X4;
    // 0x8017CDB0: beq         $t8, $zero, L_8017D80C
    if (ctx->r24 == 0) {
        // 0x8017CDB4: nop
    
            goto L_8017D80C;
    }
    // 0x8017CDB4: nop

    // 0x8017CDB8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017CDBC: addiu       $t9, $t9, -0x2E18
    ctx->r25 = ADD32(ctx->r25, -0X2E18);
    // 0x8017CDC0: lw          $s0, 0x30($t9)
    ctx->r16 = MEM_W(ctx->r25, 0X30);
    // 0x8017CDC4: lui         $at, 0xFF00
    ctx->r1 = S32(0XFF00 << 16);
    // 0x8017CDC8: and         $t0, $s0, $at
    ctx->r8 = ctx->r16 & ctx->r1;
    // 0x8017CDCC: or          $s0, $t0, $zero
    ctx->r16 = ctx->r8 | 0;
    // 0x8017CDD0: beq         $s0, $zero, L_8017CDF8
    if (ctx->r16 == 0) {
        // 0x8017CDD4: lui         $at, 0x100
        ctx->r1 = S32(0X100 << 16);
            goto L_8017CDF8;
    }
    // 0x8017CDD4: lui         $at, 0x100
    ctx->r1 = S32(0X100 << 16);
    // 0x8017CDD8: beq         $s0, $at, L_8017CFBC
    if (ctx->r16 == ctx->r1) {
        // 0x8017CDDC: lui         $at, 0x200
        ctx->r1 = S32(0X200 << 16);
            goto L_8017CFBC;
    }
    // 0x8017CDDC: lui         $at, 0x200
    ctx->r1 = S32(0X200 << 16);
    // 0x8017CDE0: beq         $s0, $at, L_8017D200
    if (ctx->r16 == ctx->r1) {
        // 0x8017CDE4: lui         $at, 0x300
        ctx->r1 = S32(0X300 << 16);
            goto L_8017D200;
    }
    // 0x8017CDE4: lui         $at, 0x300
    ctx->r1 = S32(0X300 << 16);
    // 0x8017CDE8: beq         $s0, $at, L_8017D47C
    if (ctx->r16 == ctx->r1) {
        // 0x8017CDEC: nop
    
            goto L_8017D47C;
    }
    // 0x8017CDEC: nop

    // 0x8017CDF0: b           L_8017D80C
    // 0x8017CDF4: nop

        goto L_8017D80C;
    // 0x8017CDF4: nop

L_8017CDF8:
    // 0x8017CDF8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017CDFC: addiu       $t1, $t1, -0x2E18
    ctx->r9 = ADD32(ctx->r9, -0X2E18);
    // 0x8017CE00: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x8017CE04: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8017CE08: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8017CE0C: and         $t3, $t2, $at
    ctx->r11 = ctx->r10 & ctx->r1;
    // 0x8017CE10: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x8017CE14: addiu       $t5, $zero, 0x20
    ctx->r13 = ADD32(0, 0X20);
    // 0x8017CE18: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017CE1C: addiu       $t7, $t7, 0x3D00
    ctx->r15 = ADD32(ctx->r15, 0X3D00);
    // 0x8017CE20: subu        $t6, $t5, $t4
    ctx->r14 = SUB32(ctx->r13, ctx->r12);
    // 0x8017CE24: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017CE28: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8017CE2C: addiu       $t8, $t8, -0x2E18
    ctx->r24 = ADD32(ctx->r24, -0X2E18);
    // 0x8017CE30: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x8017CE34: lui         $at, 0xFF00
    ctx->r1 = S32(0XFF00 << 16);
    // 0x8017CE38: and         $t0, $t9, $at
    ctx->r8 = ctx->r25 & ctx->r1;
    // 0x8017CE3C: bne         $t0, $zero, L_8017CE88
    if (ctx->r8 != 0) {
        // 0x8017CE40: nop
    
            goto L_8017CE88;
    }
    // 0x8017CE40: nop

    // 0x8017CE44: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017CE48: addiu       $t1, $t1, 0x3D00
    ctx->r9 = ADD32(ctx->r9, 0X3D00);
    // 0x8017CE4C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017CE50: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017CE54: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8017CE58: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8017CE5C: addiu       $t3, $zero, 0x19
    ctx->r11 = ADD32(0, 0X19);
    // 0x8017CE60: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x8017CE64: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8017CE68: addiu       $a0, $a0, 0x40A8
    ctx->r4 = ADD32(ctx->r4, 0X40A8);
    // 0x8017CE6C: addiu       $a1, $zero, 0x90
    ctx->r5 = ADD32(0, 0X90);
    // 0x8017CE70: lui         $a3, 0x3E00
    ctx->r7 = S32(0X3E00 << 16);
    // 0x8017CE74: subu        $a2, $t3, $t2
    ctx->r6 = SUB32(ctx->r11, ctx->r10);
    // 0x8017CE78: jal         0x800C6C6C
    // 0x8017CE7C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_0;
    // 0x8017CE7C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8017CE80: b           L_8017CF00
    // 0x8017CE84: nop

        goto L_8017CF00;
    // 0x8017CE84: nop

L_8017CE88:
    // 0x8017CE88: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017CE8C: addiu       $t4, $t4, 0x3D00
    ctx->r12 = ADD32(ctx->r12, 0X3D00);
    // 0x8017CE90: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8017CE94: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017CE98: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x8017CE9C: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8017CEA0: addiu       $t7, $zero, 0x17
    ctx->r15 = ADD32(0, 0X17);
    // 0x8017CEA4: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8017CEA8: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8017CEAC: addiu       $a0, $a0, 0x40A8
    ctx->r4 = ADD32(ctx->r4, 0X40A8);
    // 0x8017CEB0: addiu       $a1, $zero, 0x90
    ctx->r5 = ADD32(0, 0X90);
    // 0x8017CEB4: lui         $a3, 0x3E00
    ctx->r7 = S32(0X3E00 << 16);
    // 0x8017CEB8: subu        $a2, $t7, $t6
    ctx->r6 = SUB32(ctx->r15, ctx->r14);
    // 0x8017CEBC: jal         0x800C6C6C
    // 0x8017CEC0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_1;
    // 0x8017CEC0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x8017CEC4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017CEC8: addiu       $t9, $t9, 0x3D00
    ctx->r25 = ADD32(ctx->r25, 0X3D00);
    // 0x8017CECC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8017CED0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8017CED4: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8017CED8: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8017CEDC: addiu       $t1, $zero, 0x20
    ctx->r9 = ADD32(0, 0X20);
    // 0x8017CEE0: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x8017CEE4: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x8017CEE8: addiu       $a0, $a0, 0x40EC
    ctx->r4 = ADD32(ctx->r4, 0X40EC);
    // 0x8017CEEC: addiu       $a1, $zero, 0x90
    ctx->r5 = ADD32(0, 0X90);
    // 0x8017CEF0: lui         $a3, 0x3E00
    ctx->r7 = S32(0X3E00 << 16);
    // 0x8017CEF4: subu        $a2, $t1, $t0
    ctx->r6 = SUB32(ctx->r9, ctx->r8);
    // 0x8017CEF8: jal         0x800C6C6C
    // 0x8017CEFC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_2;
    // 0x8017CEFC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_2:
L_8017CF00:
    // 0x8017CF00: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017CF04: addiu       $t2, $t2, 0x3D00
    ctx->r10 = ADD32(ctx->r10, 0X3D00);
    // 0x8017CF08: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017CF0C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017CF10: lw          $t5, 0x0($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X0);
    // 0x8017CF14: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8017CF18: addiu       $t4, $zero, 0x15
    ctx->r12 = ADD32(0, 0X15);
    // 0x8017CF1C: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8017CF20: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8017CF24: addiu       $a0, $a0, 0x4248
    ctx->r4 = ADD32(ctx->r4, 0X4248);
    // 0x8017CF28: addiu       $a1, $zero, 0x90
    ctx->r5 = ADD32(0, 0X90);
    // 0x8017CF2C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8017CF30: subu        $a2, $t4, $t5
    ctx->r6 = SUB32(ctx->r12, ctx->r13);
    // 0x8017CF34: jal         0x800C6C6C
    // 0x8017CF38: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_3;
    // 0x8017CF38: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_3:
    // 0x8017CF3C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017CF40: addiu       $t6, $t6, 0x3D00
    ctx->r14 = ADD32(ctx->r14, 0X3D00);
    // 0x8017CF44: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017CF48: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8017CF4C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8017CF50: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8017CF54: addiu       $t9, $zero, 0x15
    ctx->r25 = ADD32(0, 0X15);
    // 0x8017CF58: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x8017CF5C: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8017CF60: addiu       $a0, $a0, 0x42BC
    ctx->r4 = ADD32(ctx->r4, 0X42BC);
    // 0x8017CF64: addiu       $a1, $zero, 0xA4
    ctx->r5 = ADD32(0, 0XA4);
    // 0x8017CF68: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8017CF6C: subu        $a2, $t9, $t8
    ctx->r6 = SUB32(ctx->r25, ctx->r24);
    // 0x8017CF70: jal         0x800C6C6C
    // 0x8017CF74: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_4;
    // 0x8017CF74: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_4:
    // 0x8017CF78: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017CF7C: addiu       $t0, $t0, -0x2E18
    ctx->r8 = ADD32(ctx->r8, -0X2E18);
    // 0x8017CF80: lw          $t3, 0x30($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X30);
    // 0x8017CF84: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017CF88: addiu       $t4, $t4, -0x2E18
    ctx->r12 = ADD32(ctx->r12, -0X2E18);
    // 0x8017CF8C: addiu       $t2, $t3, 0x1
    ctx->r10 = ADD32(ctx->r11, 0X1);
    // 0x8017CF90: sw          $t2, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->r10;
    // 0x8017CF94: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x8017CF98: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8017CF9C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8017CFA0: and         $t7, $t5, $at
    ctx->r15 = ctx->r13 & ctx->r1;
    // 0x8017CFA4: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x8017CFA8: bne         $t7, $at, L_8017D80C
    if (ctx->r15 != ctx->r1) {
        // 0x8017CFAC: nop
    
            goto L_8017D80C;
    }
    // 0x8017CFAC: nop

    // 0x8017CFB0: lui         $t6, 0x100
    ctx->r14 = S32(0X100 << 16);
    // 0x8017CFB4: b           L_8017D80C
    // 0x8017CFB8: sw          $t6, 0x30($t4)
    MEM_W(0X30, ctx->r12) = ctx->r14;
        goto L_8017D80C;
    // 0x8017CFB8: sw          $t6, 0x30($t4)
    MEM_W(0X30, ctx->r12) = ctx->r14;
L_8017CFBC:
    // 0x8017CFBC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017CFC0: addiu       $t9, $t9, -0x2E18
    ctx->r25 = ADD32(ctx->r25, -0X2E18);
    // 0x8017CFC4: lw          $t8, 0x30($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X30);
    // 0x8017CFC8: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8017CFCC: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8017CFD0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017CFD4: and         $t1, $t8, $at
    ctx->r9 = ctx->r24 & ctx->r1;
    // 0x8017CFD8: sll         $t3, $t1, 4
    ctx->r11 = S32(ctx->r9 << 4);
    // 0x8017CFDC: addiu       $t2, $t2, 0x3D00
    ctx->r10 = ADD32(ctx->r10, 0X3D00);
    // 0x8017CFE0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017CFE4: sw          $t3, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r11;
    // 0x8017CFE8: addiu       $t0, $t0, -0x2E18
    ctx->r8 = ADD32(ctx->r8, -0X2E18);
    // 0x8017CFEC: lw          $t5, 0x30($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X30);
    // 0x8017CFF0: and         $t7, $t5, $at
    ctx->r15 = ctx->r13 & ctx->r1;
    // 0x8017CFF4: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x8017CFF8: bgez        $t7, L_8017D010
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8017CFFC: cvt.s.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
            goto L_8017D010;
    }
    // 0x8017CFFC: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8017D000: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8017D004: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017D008: nop

    // 0x8017D00C: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_8017D010:
    // 0x8017D010: lui         $at, 0x3E00
    ctx->r1 = S32(0X3E00 << 16);
    // 0x8017D014: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8017D018: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017D01C: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x8017D020: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8017D024: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017D028: addiu       $t4, $t4, -0x2E18
    ctx->r12 = ADD32(ctx->r12, -0X2E18);
    // 0x8017D02C: lui         $at, 0xFF00
    ctx->r1 = S32(0XFF00 << 16);
    // 0x8017D030: swc1        $f10, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f10.u32l;
    // 0x8017D034: lw          $t9, 0x2C($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X2C);
    // 0x8017D038: and         $t8, $t9, $at
    ctx->r24 = ctx->r25 & ctx->r1;
    // 0x8017D03C: bne         $t8, $zero, L_8017D0A0
    if (ctx->r24 != 0) {
        // 0x8017D040: nop
    
            goto L_8017D0A0;
    }
    // 0x8017D040: nop

    // 0x8017D044: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017D048: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x8017D04C: lui         $at, 0x3E00
    ctx->r1 = S32(0X3E00 << 16);
    // 0x8017D050: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8017D054: lwc1        $f16, 0x0($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8017D058: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017D05C: addiu       $t1, $t1, 0x3D00
    ctx->r9 = ADD32(ctx->r9, 0X3D00);
    // 0x8017D060: add.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8017D064: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017D068: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017D06C: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x8017D070: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x8017D074: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8017D078: addiu       $t2, $zero, 0x90
    ctx->r10 = ADD32(0, 0X90);
    // 0x8017D07C: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x8017D080: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8017D084: addiu       $a0, $a0, 0x40A8
    ctx->r4 = ADD32(ctx->r4, 0X40A8);
    // 0x8017D088: addiu       $a2, $zero, 0x19
    ctx->r6 = ADD32(0, 0X19);
    // 0x8017D08C: subu        $a1, $t2, $t3
    ctx->r5 = SUB32(ctx->r10, ctx->r11);
    // 0x8017D090: jal         0x800C6C6C
    // 0x8017D094: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_5;
    // 0x8017D094: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_5:
    // 0x8017D098: b           L_8017D148
    // 0x8017D09C: nop

        goto L_8017D148;
    // 0x8017D09C: nop

L_8017D0A0:
    // 0x8017D0A0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017D0A4: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x8017D0A8: lui         $at, 0x3E00
    ctx->r1 = S32(0X3E00 << 16);
    // 0x8017D0AC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017D0B0: lwc1        $f8, 0x0($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X0);
    // 0x8017D0B4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017D0B8: addiu       $t7, $t7, 0x3D00
    ctx->r15 = ADD32(ctx->r15, 0X3D00);
    // 0x8017D0BC: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8017D0C0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8017D0C4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8017D0C8: lw          $t6, 0x0($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X0);
    // 0x8017D0CC: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x8017D0D0: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8017D0D4: addiu       $t4, $zero, 0x90
    ctx->r12 = ADD32(0, 0X90);
    // 0x8017D0D8: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8017D0DC: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8017D0E0: addiu       $a0, $a0, 0x40A8
    ctx->r4 = ADD32(ctx->r4, 0X40A8);
    // 0x8017D0E4: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
    // 0x8017D0E8: subu        $a1, $t4, $t6
    ctx->r5 = SUB32(ctx->r12, ctx->r14);
    // 0x8017D0EC: jal         0x800C6C6C
    // 0x8017D0F0: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_6;
    // 0x8017D0F0: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_6:
    // 0x8017D0F4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017D0F8: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x8017D0FC: lui         $at, 0x3E00
    ctx->r1 = S32(0X3E00 << 16);
    // 0x8017D100: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017D104: lwc1        $f6, 0x0($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8017D108: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017D10C: addiu       $t1, $t1, 0x3D00
    ctx->r9 = ADD32(ctx->r9, 0X3D00);
    // 0x8017D110: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8017D114: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8017D118: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017D11C: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8017D120: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x8017D124: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8017D128: addiu       $t3, $zero, 0x90
    ctx->r11 = ADD32(0, 0X90);
    // 0x8017D12C: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x8017D130: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8017D134: addiu       $a0, $a0, 0x40EC
    ctx->r4 = ADD32(ctx->r4, 0X40EC);
    // 0x8017D138: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x8017D13C: subu        $a1, $t3, $t2
    ctx->r5 = SUB32(ctx->r11, ctx->r10);
    // 0x8017D140: jal         0x800C6C6C
    // 0x8017D144: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_7;
    // 0x8017D144: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_7:
L_8017D148:
    // 0x8017D148: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017D14C: addiu       $t7, $t7, 0x3D00
    ctx->r15 = ADD32(ctx->r15, 0X3D00);
    // 0x8017D150: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017D154: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8017D158: lw          $t4, 0x0($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X0);
    // 0x8017D15C: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8017D160: addiu       $t6, $zero, 0x90
    ctx->r14 = ADD32(0, 0X90);
    // 0x8017D164: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8017D168: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8017D16C: addiu       $a0, $a0, 0x4248
    ctx->r4 = ADD32(ctx->r4, 0X4248);
    // 0x8017D170: addiu       $a2, $zero, 0x15
    ctx->r6 = ADD32(0, 0X15);
    // 0x8017D174: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8017D178: subu        $a1, $t6, $t4
    ctx->r5 = SUB32(ctx->r14, ctx->r12);
    // 0x8017D17C: jal         0x800C6C6C
    // 0x8017D180: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_8;
    // 0x8017D180: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_8:
    // 0x8017D184: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017D188: addiu       $t8, $t8, 0x3D00
    ctx->r24 = ADD32(ctx->r24, 0X3D00);
    // 0x8017D18C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017D190: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8017D194: lw          $a1, 0x0($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X0);
    // 0x8017D198: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8017D19C: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x8017D1A0: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8017D1A4: addiu       $a0, $a0, 0x42BC
    ctx->r4 = ADD32(ctx->r4, 0X42BC);
    // 0x8017D1A8: addiu       $a2, $zero, 0x15
    ctx->r6 = ADD32(0, 0X15);
    // 0x8017D1AC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8017D1B0: addiu       $a1, $a1, 0xA4
    ctx->r5 = ADD32(ctx->r5, 0XA4);
    // 0x8017D1B4: jal         0x800C6C6C
    // 0x8017D1B8: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_9;
    // 0x8017D1B8: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_9:
    // 0x8017D1BC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017D1C0: addiu       $t3, $t3, -0x2E18
    ctx->r11 = ADD32(ctx->r11, -0X2E18);
    // 0x8017D1C4: lw          $t2, 0x30($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X30);
    // 0x8017D1C8: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017D1CC: addiu       $t5, $t5, -0x2E18
    ctx->r13 = ADD32(ctx->r13, -0X2E18);
    // 0x8017D1D0: addiu       $t0, $t2, 0x1
    ctx->r8 = ADD32(ctx->r10, 0X1);
    // 0x8017D1D4: sw          $t0, 0x30($t3)
    MEM_W(0X30, ctx->r11) = ctx->r8;
    // 0x8017D1D8: lw          $t7, 0x30($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X30);
    // 0x8017D1DC: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8017D1E0: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8017D1E4: and         $t6, $t7, $at
    ctx->r14 = ctx->r15 & ctx->r1;
    // 0x8017D1E8: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8017D1EC: bne         $t6, $at, L_8017D80C
    if (ctx->r14 != ctx->r1) {
        // 0x8017D1F0: nop
    
            goto L_8017D80C;
    }
    // 0x8017D1F0: nop

    // 0x8017D1F4: lui         $t4, 0x200
    ctx->r12 = S32(0X200 << 16);
    // 0x8017D1F8: b           L_8017D80C
    // 0x8017D1FC: sw          $t4, 0x30($t5)
    MEM_W(0X30, ctx->r13) = ctx->r12;
        goto L_8017D80C;
    // 0x8017D1FC: sw          $t4, 0x30($t5)
    MEM_W(0X30, ctx->r13) = ctx->r12;
L_8017D200:
    // 0x8017D200: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017D204: addiu       $t9, $t9, -0x2E18
    ctx->r25 = ADD32(ctx->r25, -0X2E18);
    // 0x8017D208: lw          $t8, 0x30($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X30);
    // 0x8017D20C: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8017D210: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8017D214: and         $t1, $t8, $at
    ctx->r9 = ctx->r24 & ctx->r1;
    // 0x8017D218: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x8017D21C: bgez        $t1, L_8017D234
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8017D220: cvt.s.w     $f4, $f6
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
            goto L_8017D234;
    }
    // 0x8017D220: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8017D224: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8017D228: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8017D22C: nop

    // 0x8017D230: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
L_8017D234:
    // 0x8017D234: lui         $at, 0x3E00
    ctx->r1 = S32(0X3E00 << 16);
    // 0x8017D238: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017D23C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017D240: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x8017D244: mul.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8017D248: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017D24C: addiu       $t0, $t0, -0x2E18
    ctx->r8 = ADD32(ctx->r8, -0X2E18);
    // 0x8017D250: lui         $at, 0xFF00
    ctx->r1 = S32(0XFF00 << 16);
    // 0x8017D254: swc1        $f16, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f16.u32l;
    // 0x8017D258: lw          $t3, 0x2C($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X2C);
    // 0x8017D25C: and         $t7, $t3, $at
    ctx->r15 = ctx->r11 & ctx->r1;
    // 0x8017D260: bne         $t7, $zero, L_8017D2E8
    if (ctx->r15 != 0) {
        // 0x8017D264: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8017D2E8;
    }
    // 0x8017D264: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017D268: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8017D26C: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8017D270: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8017D274: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8017D278: addiu       $a0, $a0, 0x40A8
    ctx->r4 = ADD32(ctx->r4, 0X40A8);
    // 0x8017D27C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x8017D280: addiu       $a2, $zero, 0x19
    ctx->r6 = ADD32(0, 0X19);
    // 0x8017D284: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8017D288: jal         0x800C6C6C
    // 0x8017D28C: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_10;
    // 0x8017D28C: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_10:
    // 0x8017D290: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017D294: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x8017D298: lwc1        $f6, 0x0($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X0);
    // 0x8017D29C: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8017D2A0: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8017D2A4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017D2A8: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8017D2AC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017D2B0: add.d       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = ctx->f8.d + ctx->f4.d;
    // 0x8017D2B4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8017D2B8: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8017D2BC: addiu       $t5, $zero, 0x78
    ctx->r13 = ADD32(0, 0X78);
    // 0x8017D2C0: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x8017D2C4: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8017D2C8: addiu       $a0, $a0, 0x4190
    ctx->r4 = ADD32(ctx->r4, 0X4190);
    // 0x8017D2CC: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x8017D2D0: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x8017D2D4: addiu       $a2, $zero, 0x15
    ctx->r6 = ADD32(0, 0X15);
    // 0x8017D2D8: jal         0x800C6C6C
    // 0x8017D2DC: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_11;
    // 0x8017D2DC: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_11:
    // 0x8017D2E0: b           L_8017D3E0
    // 0x8017D2E4: nop

        goto L_8017D3E0;
    // 0x8017D2E4: nop

L_8017D2E8:
    // 0x8017D2E8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8017D2EC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017D2F0: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8017D2F4: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8017D2F8: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8017D2FC: addiu       $a0, $a0, 0x40A8
    ctx->r4 = ADD32(ctx->r4, 0X40A8);
    // 0x8017D300: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x8017D304: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
    // 0x8017D308: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8017D30C: jal         0x800C6C6C
    // 0x8017D310: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_12;
    // 0x8017D310: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_12:
    // 0x8017D314: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8017D318: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8017D31C: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8017D320: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8017D324: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8017D328: addiu       $a0, $a0, 0x40EC
    ctx->r4 = ADD32(ctx->r4, 0X40EC);
    // 0x8017D32C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x8017D330: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x8017D334: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8017D338: jal         0x800C6C6C
    // 0x8017D33C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_13;
    // 0x8017D33C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_13:
    // 0x8017D340: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017D344: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x8017D348: lwc1        $f4, 0x0($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X0);
    // 0x8017D34C: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8017D350: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8017D354: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8017D358: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x8017D35C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8017D360: add.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d + ctx->f16.d;
    // 0x8017D364: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8017D368: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8017D36C: addiu       $t2, $zero, 0x78
    ctx->r10 = ADD32(0, 0X78);
    // 0x8017D370: cvt.s.d     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f6.fl = CVT_S_D(ctx->f18.d);
    // 0x8017D374: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8017D378: addiu       $a0, $a0, 0x4190
    ctx->r4 = ADD32(ctx->r4, 0X4190);
    // 0x8017D37C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x8017D380: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x8017D384: addiu       $a2, $zero, 0x15
    ctx->r6 = ADD32(0, 0X15);
    // 0x8017D388: jal         0x800C6C6C
    // 0x8017D38C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_14;
    // 0x8017D38C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_14:
    // 0x8017D390: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017D394: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x8017D398: lwc1        $f4, 0x0($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8017D39C: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8017D3A0: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8017D3A4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8017D3A8: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x8017D3AC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8017D3B0: add.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d + ctx->f16.d;
    // 0x8017D3B4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8017D3B8: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8017D3BC: addiu       $t3, $zero, 0x78
    ctx->r11 = ADD32(0, 0X78);
    // 0x8017D3C0: cvt.s.d     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f6.fl = CVT_S_D(ctx->f18.d);
    // 0x8017D3C4: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x8017D3C8: addiu       $a0, $a0, 0x41D4
    ctx->r4 = ADD32(ctx->r4, 0X41D4);
    // 0x8017D3CC: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x8017D3D0: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x8017D3D4: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    // 0x8017D3D8: jal         0x800C6C6C
    // 0x8017D3DC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_15;
    // 0x8017D3DC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_15:
L_8017D3E0:
    // 0x8017D3E0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017D3E4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017D3E8: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8017D3EC: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8017D3F0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8017D3F4: addiu       $a0, $a0, 0x4248
    ctx->r4 = ADD32(ctx->r4, 0X4248);
    // 0x8017D3F8: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x8017D3FC: addiu       $a2, $zero, 0x15
    ctx->r6 = ADD32(0, 0X15);
    // 0x8017D400: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8017D404: jal         0x800C6C6C
    // 0x8017D408: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_16;
    // 0x8017D408: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_16:
    // 0x8017D40C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017D410: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017D414: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8017D418: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8017D41C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8017D420: addiu       $a0, $a0, 0x42BC
    ctx->r4 = ADD32(ctx->r4, 0X42BC);
    // 0x8017D424: addiu       $a1, $zero, 0x110
    ctx->r5 = ADD32(0, 0X110);
    // 0x8017D428: addiu       $a2, $zero, 0x15
    ctx->r6 = ADD32(0, 0X15);
    // 0x8017D42C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8017D430: jal         0x800C6C6C
    // 0x8017D434: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_17;
    // 0x8017D434: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_17:
    // 0x8017D438: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017D43C: addiu       $t4, $t4, -0x2E18
    ctx->r12 = ADD32(ctx->r12, -0X2E18);
    // 0x8017D440: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x8017D444: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017D448: addiu       $t8, $t8, -0x2E18
    ctx->r24 = ADD32(ctx->r24, -0X2E18);
    // 0x8017D44C: addiu       $t9, $t5, 0x1
    ctx->r25 = ADD32(ctx->r13, 0X1);
    // 0x8017D450: sw          $t9, 0x30($t4)
    MEM_W(0X30, ctx->r12) = ctx->r25;
    // 0x8017D454: lw          $t1, 0x30($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X30);
    // 0x8017D458: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8017D45C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8017D460: and         $t2, $t1, $at
    ctx->r10 = ctx->r9 & ctx->r1;
    // 0x8017D464: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8017D468: bne         $t2, $at, L_8017D80C
    if (ctx->r10 != ctx->r1) {
        // 0x8017D46C: nop
    
            goto L_8017D80C;
    }
    // 0x8017D46C: nop

    // 0x8017D470: lui         $t0, 0x300
    ctx->r8 = S32(0X300 << 16);
    // 0x8017D474: b           L_8017D80C
    // 0x8017D478: sw          $t0, 0x30($t8)
    MEM_W(0X30, ctx->r24) = ctx->r8;
        goto L_8017D80C;
    // 0x8017D478: sw          $t0, 0x30($t8)
    MEM_W(0X30, ctx->r24) = ctx->r8;
L_8017D47C:
    // 0x8017D47C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017D480: addiu       $t3, $t3, -0x2E18
    ctx->r11 = ADD32(ctx->r11, -0X2E18);
    // 0x8017D484: lw          $t7, 0x2C($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X2C);
    // 0x8017D488: lui         $at, 0xFF00
    ctx->r1 = S32(0XFF00 << 16);
    // 0x8017D48C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017D490: addiu       $t5, $t5, 0x3C00
    ctx->r13 = ADD32(ctx->r13, 0X3C00);
    // 0x8017D494: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017D498: and         $t6, $t7, $at
    ctx->r14 = ctx->r15 & ctx->r1;
    // 0x8017D49C: sw          $t6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r14;
    // 0x8017D4A0: addiu       $t9, $t9, -0x2E18
    ctx->r25 = ADD32(ctx->r25, -0X2E18);
    // 0x8017D4A4: lw          $t4, 0x2C($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X2C);
    // 0x8017D4A8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017D4AC: addiu       $t2, $t2, 0x3C00
    ctx->r10 = ADD32(ctx->r10, 0X3C00);
    // 0x8017D4B0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017D4B4: andi        $t1, $t4, 0xFF
    ctx->r9 = ctx->r12 & 0XFF;
    // 0x8017D4B8: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x8017D4BC: addiu       $t0, $t0, -0x2E18
    ctx->r8 = ADD32(ctx->r8, -0X2E18);
    // 0x8017D4C0: lw          $t8, 0x2C($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X2C);
    // 0x8017D4C4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017D4C8: addiu       $t6, $t6, 0x3C00
    ctx->r14 = ADD32(ctx->r14, 0X3C00);
    // 0x8017D4CC: andi        $t3, $t8, 0xFF00
    ctx->r11 = ctx->r24 & 0XFF00;
    // 0x8017D4D0: srl         $t7, $t3, 8
    ctx->r15 = S32(U32(ctx->r11) >> 8);
    // 0x8017D4D4: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017D4D8: sw          $t7, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r15;
    // 0x8017D4DC: addiu       $t5, $t5, 0x3C00
    ctx->r13 = ADD32(ctx->r13, 0X3C00);
    // 0x8017D4E0: lw          $t9, 0x0($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X0);
    // 0x8017D4E4: bne         $t9, $zero, L_8017D5DC
    if (ctx->r25 != 0) {
        // 0x8017D4E8: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8017D5DC;
    }
    // 0x8017D4E8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017D4EC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8017D4F0: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8017D4F4: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x8017D4F8: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8017D4FC: addiu       $a0, $a0, 0x40A8
    ctx->r4 = ADD32(ctx->r4, 0X40A8);
    // 0x8017D500: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x8017D504: addiu       $a2, $zero, 0x19
    ctx->r6 = ADD32(0, 0X19);
    // 0x8017D508: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8017D50C: jal         0x800C6C6C
    // 0x8017D510: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_18;
    // 0x8017D510: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_18:
    // 0x8017D514: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017D518: addiu       $t1, $t1, 0x3C00
    ctx->r9 = ADD32(ctx->r9, 0X3C00);
    // 0x8017D51C: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x8017D520: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017D524: addiu       $t8, $t8, -0x2A28
    ctx->r24 = ADD32(ctx->r24, -0X2A28);
    // 0x8017D528: sll         $t0, $t2, 2
    ctx->r8 = S32(ctx->r10 << 2);
    // 0x8017D52C: addu        $t0, $t0, $t2
    ctx->r8 = ADD32(ctx->r8, ctx->r10);
    // 0x8017D530: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8017D534: subu        $t0, $t0, $t2
    ctx->r8 = SUB32(ctx->r8, ctx->r10);
    // 0x8017D538: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8017D53C: addu        $t0, $t0, $t2
    ctx->r8 = ADD32(ctx->r8, ctx->r10);
    // 0x8017D540: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8017D544: addu        $t3, $t0, $t8
    ctx->r11 = ADD32(ctx->r8, ctx->r24);
    // 0x8017D548: lw          $t7, 0x20($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X20);
    // 0x8017D54C: beq         $t7, $zero, L_8017D7B4
    if (ctx->r15 == 0) {
        // 0x8017D550: nop
    
            goto L_8017D7B4;
    }
    // 0x8017D550: nop

    // 0x8017D554: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x8017D558: bgez        $t7, L_8017D570
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8017D55C: cvt.s.w     $f6, $f18
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
            goto L_8017D570;
    }
    // 0x8017D55C: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8017D560: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8017D564: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8017D568: nop

    // 0x8017D56C: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8017D570:
    // 0x8017D570: lw          $t6, 0x1C($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X1C);
    // 0x8017D574: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8017D578: bgez        $t6, L_8017D590
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8017D57C: cvt.s.w     $f10, $f4
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8017D590;
    }
    // 0x8017D57C: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8017D580: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8017D584: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8017D588: nop

    // 0x8017D58C: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_8017D590:
    // 0x8017D590: div.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8017D594: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017D598: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x8017D59C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017D5A0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017D5A4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8017D5A8: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x8017D5AC: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8017D5B0: addiu       $t4, $zero, 0x78
    ctx->r12 = ADD32(0, 0X78);
    // 0x8017D5B4: addiu       $a0, $a0, 0x4190
    ctx->r4 = ADD32(ctx->r4, 0X4190);
    // 0x8017D5B8: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x8017D5BC: addiu       $a2, $zero, 0x15
    ctx->r6 = ADD32(0, 0X15);
    // 0x8017D5C0: swc1        $f18, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f18.u32l;
    // 0x8017D5C4: lw          $a3, 0x0($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X0);
    // 0x8017D5C8: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8017D5CC: jal         0x800C6C6C
    // 0x8017D5D0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_19;
    // 0x8017D5D0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_19:
    // 0x8017D5D4: b           L_8017D7B4
    // 0x8017D5D8: nop

        goto L_8017D7B4;
    // 0x8017D5D8: nop

L_8017D5DC:
    // 0x8017D5DC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8017D5E0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017D5E4: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8017D5E8: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x8017D5EC: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8017D5F0: addiu       $a0, $a0, 0x40A8
    ctx->r4 = ADD32(ctx->r4, 0X40A8);
    // 0x8017D5F4: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x8017D5F8: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
    // 0x8017D5FC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8017D600: jal         0x800C6C6C
    // 0x8017D604: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_20;
    // 0x8017D604: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_20:
    // 0x8017D608: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8017D60C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8017D610: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8017D614: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x8017D618: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8017D61C: addiu       $a0, $a0, 0x40EC
    ctx->r4 = ADD32(ctx->r4, 0X40EC);
    // 0x8017D620: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x8017D624: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x8017D628: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8017D62C: jal         0x800C6C6C
    // 0x8017D630: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_21;
    // 0x8017D630: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_21:
    // 0x8017D634: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017D638: addiu       $t0, $t0, 0x3C00
    ctx->r8 = ADD32(ctx->r8, 0X3C00);
    // 0x8017D63C: lw          $t8, 0x4($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X4);
    // 0x8017D640: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017D644: addiu       $t3, $t3, -0x2A28
    ctx->r11 = ADD32(ctx->r11, -0X2A28);
    // 0x8017D648: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x8017D64C: addu        $t7, $t7, $t8
    ctx->r15 = ADD32(ctx->r15, ctx->r24);
    // 0x8017D650: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017D654: subu        $t7, $t7, $t8
    ctx->r15 = SUB32(ctx->r15, ctx->r24);
    // 0x8017D658: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017D65C: addu        $t7, $t7, $t8
    ctx->r15 = ADD32(ctx->r15, ctx->r24);
    // 0x8017D660: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017D664: addu        $t6, $t7, $t3
    ctx->r14 = ADD32(ctx->r15, ctx->r11);
    // 0x8017D668: lw          $t5, 0x20($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X20);
    // 0x8017D66C: beq         $t5, $zero, L_8017D6F4
    if (ctx->r13 == 0) {
        // 0x8017D670: nop
    
            goto L_8017D6F4;
    }
    // 0x8017D670: nop

    // 0x8017D674: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x8017D678: bgez        $t5, L_8017D690
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8017D67C: cvt.s.w     $f10, $f6
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
            goto L_8017D690;
    }
    // 0x8017D67C: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8017D680: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8017D684: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8017D688: nop

    // 0x8017D68C: add.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f18.fl;
L_8017D690:
    // 0x8017D690: lw          $t9, 0x1C($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X1C);
    // 0x8017D694: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x8017D698: bgez        $t9, L_8017D6B0
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8017D69C: cvt.s.w     $f4, $f8
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
            goto L_8017D6B0;
    }
    // 0x8017D69C: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8017D6A0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8017D6A4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8017D6A8: nop

    // 0x8017D6AC: add.s       $f4, $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f16.fl;
L_8017D6B0:
    // 0x8017D6B0: div.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8017D6B4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017D6B8: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x8017D6BC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017D6C0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8017D6C4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8017D6C8: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x8017D6CC: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8017D6D0: addiu       $t2, $zero, 0x78
    ctx->r10 = ADD32(0, 0X78);
    // 0x8017D6D4: addiu       $a0, $a0, 0x4190
    ctx->r4 = ADD32(ctx->r4, 0X4190);
    // 0x8017D6D8: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x8017D6DC: addiu       $a2, $zero, 0x15
    ctx->r6 = ADD32(0, 0X15);
    // 0x8017D6E0: swc1        $f6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f6.u32l;
    // 0x8017D6E4: lw          $a3, 0x0($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X0);
    // 0x8017D6E8: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8017D6EC: jal         0x800C6C6C
    // 0x8017D6F0: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_22;
    // 0x8017D6F0: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_22:
L_8017D6F4:
    // 0x8017D6F4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017D6F8: addiu       $t0, $t0, 0x3C00
    ctx->r8 = ADD32(ctx->r8, 0X3C00);
    // 0x8017D6FC: lw          $t8, 0x8($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X8);
    // 0x8017D700: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017D704: addiu       $t3, $t3, -0x2A28
    ctx->r11 = ADD32(ctx->r11, -0X2A28);
    // 0x8017D708: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x8017D70C: addu        $t7, $t7, $t8
    ctx->r15 = ADD32(ctx->r15, ctx->r24);
    // 0x8017D710: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017D714: subu        $t7, $t7, $t8
    ctx->r15 = SUB32(ctx->r15, ctx->r24);
    // 0x8017D718: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017D71C: addu        $t7, $t7, $t8
    ctx->r15 = ADD32(ctx->r15, ctx->r24);
    // 0x8017D720: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017D724: addu        $t5, $t7, $t3
    ctx->r13 = ADD32(ctx->r15, ctx->r11);
    // 0x8017D728: lw          $t6, 0x20($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X20);
    // 0x8017D72C: beq         $t6, $zero, L_8017D7B4
    if (ctx->r14 == 0) {
        // 0x8017D730: nop
    
            goto L_8017D7B4;
    }
    // 0x8017D730: nop

    // 0x8017D734: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x8017D738: bgez        $t6, L_8017D750
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8017D73C: cvt.s.w     $f16, $f8
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
            goto L_8017D750;
    }
    // 0x8017D73C: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8017D740: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8017D744: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017D748: nop

    // 0x8017D74C: add.s       $f16, $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f10.fl;
L_8017D750:
    // 0x8017D750: lw          $t9, 0x1C($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X1C);
    // 0x8017D754: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8017D758: bgez        $t9, L_8017D770
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8017D75C: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8017D770;
    }
    // 0x8017D75C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8017D760: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8017D764: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8017D768: nop

    // 0x8017D76C: add.s       $f6, $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f18.fl;
L_8017D770:
    // 0x8017D770: div.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f16.fl, ctx->f6.fl);
    // 0x8017D774: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017D778: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x8017D77C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017D780: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8017D784: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017D788: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x8017D78C: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8017D790: addiu       $t2, $zero, 0x78
    ctx->r10 = ADD32(0, 0X78);
    // 0x8017D794: addiu       $a0, $a0, 0x41D4
    ctx->r4 = ADD32(ctx->r4, 0X41D4);
    // 0x8017D798: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x8017D79C: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    // 0x8017D7A0: swc1        $f8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f8.u32l;
    // 0x8017D7A4: lw          $a3, 0x0($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X0);
    // 0x8017D7A8: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8017D7AC: jal         0x800C6C6C
    // 0x8017D7B0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_23;
    // 0x8017D7B0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_23:
L_8017D7B4:
    // 0x8017D7B4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017D7B8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017D7BC: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8017D7C0: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x8017D7C4: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8017D7C8: addiu       $a0, $a0, 0x4248
    ctx->r4 = ADD32(ctx->r4, 0X4248);
    // 0x8017D7CC: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x8017D7D0: addiu       $a2, $zero, 0x15
    ctx->r6 = ADD32(0, 0X15);
    // 0x8017D7D4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8017D7D8: jal         0x800C6C6C
    // 0x8017D7DC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_24;
    // 0x8017D7DC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_24:
    // 0x8017D7E0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017D7E4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8017D7E8: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8017D7EC: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8017D7F0: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8017D7F4: addiu       $a0, $a0, 0x42BC
    ctx->r4 = ADD32(ctx->r4, 0X42BC);
    // 0x8017D7F8: addiu       $a1, $zero, 0x110
    ctx->r5 = ADD32(0, 0X110);
    // 0x8017D7FC: addiu       $a2, $zero, 0x15
    ctx->r6 = ADD32(0, 0X15);
    // 0x8017D800: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8017D804: jal         0x800C6C6C
    // 0x8017D808: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_25;
    // 0x8017D808: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_25:
L_8017D80C:
    // 0x8017D80C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8017D810: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8017D814: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8017D818: jr          $ra
    // 0x8017D81C: nop

    return;
    // 0x8017D81C: nop

;}
RECOMP_FUNC void func_8017D820_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017D820: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8017D824: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8017D828: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8017D82C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017D830: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8017D834: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8017D838: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8017D83C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017D840: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8017D844: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017D848: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8017D84C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017D850: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8017D854: lw          $t8, -0x2A00($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2A00);
    // 0x8017D858: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x8017D85C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8017D860: lui         $s0, 0x801A
    ctx->r16 = S32(0X801A << 16);
    // 0x8017D864: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8017D868: addu        $s0, $s0, $t0
    ctx->r16 = ADD32(ctx->r16, ctx->r8);
    // 0x8017D86C: lbu         $s0, -0x24A4($s0)
    ctx->r16 = MEM_BU(ctx->r16, -0X24A4);
    // 0x8017D870: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8017D874: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x8017D878: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x8017D87C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8017D880: beq         $s0, $zero, L_8017D8AC
    if (ctx->r16 == 0) {
        // 0x8017D884: sw          $s1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r17;
            goto L_8017D8AC;
    }
    // 0x8017D884: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8017D888: addiu       $at, $zero, 0x25
    ctx->r1 = ADD32(0, 0X25);
    // 0x8017D88C: beq         $s0, $at, L_8017D8F4
    if (ctx->r16 == ctx->r1) {
        // 0x8017D890: addiu       $at, $zero, 0xFE
        ctx->r1 = ADD32(0, 0XFE);
            goto L_8017D8F4;
    }
    // 0x8017D890: addiu       $at, $zero, 0xFE
    ctx->r1 = ADD32(0, 0XFE);
    // 0x8017D894: beq         $s0, $at, L_8017DA6C
    if (ctx->r16 == ctx->r1) {
        // 0x8017D898: addiu       $at, $zero, 0xFF
        ctx->r1 = ADD32(0, 0XFF);
            goto L_8017DA6C;
    }
    // 0x8017D898: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8017D89C: beq         $s0, $at, L_8017D93C
    if (ctx->r16 == ctx->r1) {
        // 0x8017D8A0: nop
    
            goto L_8017D93C;
    }
    // 0x8017D8A0: nop

    // 0x8017D8A4: b           L_8017D968
    // 0x8017D8A8: nop

        goto L_8017D968;
    // 0x8017D8A8: nop

L_8017D8AC:
    // 0x8017D8AC: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8017D8B0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017D8B4: addiu       $t3, $t3, -0x2A28
    ctx->r11 = ADD32(ctx->r11, -0X2A28);
    // 0x8017D8B8: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8017D8BC: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8017D8C0: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8017D8C4: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x8017D8C8: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8017D8CC: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8017D8D0: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8017D8D4: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8017D8D8: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x8017D8DC: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8017D8E0: ori         $at, $at, 0x7FFF
    ctx->r1 = ctx->r1 | 0X7FFF;
    // 0x8017D8E4: and         $t6, $t5, $at
    ctx->r14 = ctx->r13 & ctx->r1;
    // 0x8017D8E8: sh          $t6, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r14;
    // 0x8017D8EC: b           L_8017DAA8
    // 0x8017D8F0: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
        goto L_8017DAA8;
    // 0x8017D8F0: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
L_8017D8F4:
    // 0x8017D8F4: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8017D8F8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017D8FC: addiu       $t9, $t9, -0x2A28
    ctx->r25 = ADD32(ctx->r25, -0X2A28);
    // 0x8017D900: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8017D904: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8017D908: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8017D90C: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8017D910: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8017D914: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8017D918: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8017D91C: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8017D920: lw          $a1, 0x60($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X60);
    // 0x8017D924: lw          $a2, 0x64($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X64);
    // 0x8017D928: lw          $a3, 0x68($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X68);
    // 0x8017D92C: jal         0x8018AB30
    // 0x8017D930: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    func_8018AB30_1501A0(rdram, ctx);
        goto after_0;
    // 0x8017D930: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    after_0:
    // 0x8017D934: b           L_8017DAA8
    // 0x8017D938: ori         $v0, $zero, 0xFFFE
    ctx->r2 = 0 | 0XFFFE;
        goto L_8017DAA8;
    // 0x8017D938: ori         $v0, $zero, 0xFFFE
    ctx->r2 = 0 | 0XFFFE;
L_8017D93C:
    // 0x8017D93C: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8017D940: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017D944: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8017D948: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8017D94C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8017D950: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x8017D954: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8017D958: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8017D95C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8017D960: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x8017D964: sw          $zero, -0x2A00($at)
    MEM_W(-0X2A00, ctx->r1) = 0;
L_8017D968:
    // 0x8017D968: jal         0x800D8790
    // 0x8017D96C: nop

    guRandom_recomp(rdram, ctx);
        goto after_1;
    // 0x8017D96C: nop

    after_1:
    // 0x8017D970: jal         0x800D8790
    // 0x8017D974: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    guRandom_recomp(rdram, ctx);
        goto after_2;
    // 0x8017D974: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    after_2:
    // 0x8017D978: jal         0x800D8790
    // 0x8017D97C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    guRandom_recomp(rdram, ctx);
        goto after_3;
    // 0x8017D97C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    after_3:
    // 0x8017D980: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8017D984: div         $zero, $s2, $at
    lo = S32(S64(S32(ctx->r18)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r18)) % S64(S32(ctx->r1)));
    // 0x8017D988: mfhi        $t0
    ctx->r8 = hi;
    // 0x8017D98C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8017D990: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x8017D994: div         $zero, $s1, $at
    lo = S32(S64(S32(ctx->r17)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r17)) % S64(S32(ctx->r1)));
    // 0x8017D998: mfhi        $t2
    ctx->r10 = hi;
    // 0x8017D99C: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x8017D9A0: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x8017D9A4: div         $zero, $s0, $at
    lo = S32(S64(S32(ctx->r16)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r16)) % S64(S32(ctx->r1)));
    // 0x8017D9A8: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x8017D9AC: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x8017D9B0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8017D9B4: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8017D9B8: subu        $t5, $t5, $t3
    ctx->r13 = SUB32(ctx->r13, ctx->r11);
    // 0x8017D9BC: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8017D9C0: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8017D9C4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017D9C8: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x8017D9CC: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8017D9D0: addiu       $t6, $t6, -0x2A28
    ctx->r14 = ADD32(ctx->r14, -0X2A28);
    // 0x8017D9D4: addu        $t4, $t5, $t6
    ctx->r12 = ADD32(ctx->r13, ctx->r14);
    // 0x8017D9D8: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8017D9DC: lwc1        $f16, 0x98($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X98);
    // 0x8017D9E0: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8017D9E4: lwc1        $f6, 0x60($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X60);
    // 0x8017D9E8: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x8017D9EC: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8017D9F0: mfhi        $t5
    ctx->r13 = hi;
    // 0x8017D9F4: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x8017D9F8: lw          $t7, 0x28($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X28);
    // 0x8017D9FC: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x8017DA00: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8017DA04: add.s       $f16, $f6, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8017DA08: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x8017DA0C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8017DA10: addu        $a0, $a0, $t9
    ctx->r4 = ADD32(ctx->r4, ctx->r25);
    // 0x8017DA14: add.s       $f6, $f10, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8017DA18: lbu         $a0, -0x24A4($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X24A4);
    // 0x8017DA1C: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8017DA20: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8017DA24: lwc1        $f6, 0x9C($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X9C);
    // 0x8017DA28: mul.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8017DA2C: lwc1        $f10, 0x64($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X64);
    // 0x8017DA30: mul.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x8017DA34: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8017DA38: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8017DA3C: add.s       $f10, $f16, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x8017DA40: cvt.s.w     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8017DA44: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8017DA48: lwc1        $f10, 0xA0($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0XA0);
    // 0x8017DA4C: mul.s       $f6, $f16, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x8017DA50: lwc1        $f16, 0x68($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X68);
    // 0x8017DA54: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8017DA58: add.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x8017DA5C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8017DA60: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x8017DA64: jal         0x8018AB30
    // 0x8017DA68: nop

    func_8018AB30_1501A0(rdram, ctx);
        goto after_4;
    // 0x8017DA68: nop

    after_4:
L_8017DA6C:
    // 0x8017DA6C: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8017DA70: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017DA74: addiu       $t9, $t9, -0x2A28
    ctx->r25 = ADD32(ctx->r25, -0X2A28);
    // 0x8017DA78: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8017DA7C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8017DA80: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8017DA84: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8017DA88: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8017DA8C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8017DA90: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8017DA94: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8017DA98: lw          $t1, 0x28($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X28);
    // 0x8017DA9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017DAA0: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8017DAA4: sw          $t2, 0x28($t0)
    MEM_W(0X28, ctx->r8) = ctx->r10;
L_8017DAA8:
    // 0x8017DAA8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8017DAAC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8017DAB0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8017DAB4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8017DAB8: jr          $ra
    // 0x8017DABC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8017DABC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8017DAC0_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017DAC0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8017DAC4: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8017DAC8: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x8017DACC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017DAD0: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x8017DAD4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8017DAD8: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8017DADC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017DAE0: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8017DAE4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017DAE8: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8017DAEC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017DAF0: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8017DAF4: lw          $t8, -0x2A00($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2A00);
    // 0x8017DAF8: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x8017DAFC: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8017DB00: lui         $s0, 0x801A
    ctx->r16 = S32(0X801A << 16);
    // 0x8017DB04: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8017DB08: addu        $s0, $s0, $t0
    ctx->r16 = ADD32(ctx->r16, ctx->r8);
    // 0x8017DB0C: lbu         $s0, -0x24A4($s0)
    ctx->r16 = MEM_BU(ctx->r16, -0X24A4);
    // 0x8017DB10: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8017DB14: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x8017DB18: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x8017DB1C: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8017DB20: beq         $s0, $zero, L_8017DB4C
    if (ctx->r16 == 0) {
        // 0x8017DB24: sw          $s1, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r17;
            goto L_8017DB4C;
    }
    // 0x8017DB24: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8017DB28: addiu       $at, $zero, 0x25
    ctx->r1 = ADD32(0, 0X25);
    // 0x8017DB2C: beq         $s0, $at, L_8017DB94
    if (ctx->r16 == ctx->r1) {
        // 0x8017DB30: addiu       $at, $zero, 0xFE
        ctx->r1 = ADD32(0, 0XFE);
            goto L_8017DB94;
    }
    // 0x8017DB30: addiu       $at, $zero, 0xFE
    ctx->r1 = ADD32(0, 0XFE);
    // 0x8017DB34: beq         $s0, $at, L_8017DE00
    if (ctx->r16 == ctx->r1) {
        // 0x8017DB38: addiu       $at, $zero, 0xFF
        ctx->r1 = ADD32(0, 0XFF);
            goto L_8017DE00;
    }
    // 0x8017DB38: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8017DB3C: beq         $s0, $at, L_8017DC5C
    if (ctx->r16 == ctx->r1) {
        // 0x8017DB40: nop
    
            goto L_8017DC5C;
    }
    // 0x8017DB40: nop

    // 0x8017DB44: b           L_8017DC88
    // 0x8017DB48: nop

        goto L_8017DC88;
    // 0x8017DB48: nop

L_8017DB4C:
    // 0x8017DB4C: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x8017DB50: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017DB54: addiu       $t3, $t3, -0x2A28
    ctx->r11 = ADD32(ctx->r11, -0X2A28);
    // 0x8017DB58: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8017DB5C: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8017DB60: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8017DB64: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x8017DB68: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8017DB6C: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8017DB70: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8017DB74: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8017DB78: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x8017DB7C: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8017DB80: ori         $at, $at, 0x7FFF
    ctx->r1 = ctx->r1 | 0X7FFF;
    // 0x8017DB84: and         $t6, $t5, $at
    ctx->r14 = ctx->r13 & ctx->r1;
    // 0x8017DB88: sh          $t6, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r14;
    // 0x8017DB8C: b           L_8017DE3C
    // 0x8017DB90: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
        goto L_8017DE3C;
    // 0x8017DB90: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
L_8017DB94:
    // 0x8017DB94: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x8017DB98: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017DB9C: addiu       $t0, $t0, -0x2A28
    ctx->r8 = ADD32(ctx->r8, -0X2A28);
    // 0x8017DBA0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8017DBA4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8017DBA8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8017DBAC: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8017DBB0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8017DBB4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8017DBB8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8017DBBC: addiu       $t9, $t8, 0xA4
    ctx->r25 = ADD32(ctx->r24, 0XA4);
    // 0x8017DBC0: addiu       $t1, $sp, 0x58
    ctx->r9 = ADD32(ctx->r29, 0X58);
    // 0x8017DBC4: addiu       $t2, $sp, 0x5C
    ctx->r10 = ADD32(ctx->r29, 0X5C);
    // 0x8017DBC8: addiu       $t3, $sp, 0x60
    ctx->r11 = ADD32(ctx->r29, 0X60);
    // 0x8017DBCC: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x8017DBD0: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8017DBD4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8017DBD8: addu        $a0, $t9, $t0
    ctx->r4 = ADD32(ctx->r25, ctx->r8);
    // 0x8017DBDC: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x8017DBE0: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    // 0x8017DBE4: jal         0x800D6E90
    // 0x8017DBE8: lw          $a3, 0x60($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X60);
    guMtxXFMF_recomp(rdram, ctx);
        goto after_0;
    // 0x8017DBE8: lw          $a3, 0x60($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X60);
    after_0:
    // 0x8017DBEC: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x8017DBF0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017DBF4: addiu       $t4, $t4, -0x2A28
    ctx->r12 = ADD32(ctx->r12, -0X2A28);
    // 0x8017DBF8: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8017DBFC: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8017DC00: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8017DC04: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x8017DC08: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8017DC0C: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8017DC10: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8017DC14: addu        $t7, $t6, $t4
    ctx->r15 = ADD32(ctx->r14, ctx->r12);
    // 0x8017DC18: lwc1        $f4, 0x60($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X60);
    // 0x8017DC1C: lwc1        $f6, 0x58($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8017DC20: lwc1        $f10, 0x64($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X64);
    // 0x8017DC24: lwc1        $f16, 0x5C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8017DC28: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8017DC2C: lwc1        $f6, 0x60($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8017DC30: lwc1        $f4, 0x68($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X68);
    // 0x8017DC34: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8017DC38: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8017DC3C: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    // 0x8017DC40: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8017DC44: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x8017DC48: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x8017DC4C: jal         0x8018AB30
    // 0x8017DC50: nop

    func_8018AB30_1501A0(rdram, ctx);
        goto after_1;
    // 0x8017DC50: nop

    after_1:
    // 0x8017DC54: b           L_8017DE3C
    // 0x8017DC58: ori         $v0, $zero, 0xFFFE
    ctx->r2 = 0 | 0XFFFE;
        goto L_8017DE3C;
    // 0x8017DC58: ori         $v0, $zero, 0xFFFE
    ctx->r2 = 0 | 0XFFFE;
L_8017DC5C:
    // 0x8017DC5C: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x8017DC60: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017DC64: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8017DC68: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8017DC6C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8017DC70: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8017DC74: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8017DC78: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8017DC7C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8017DC80: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8017DC84: sw          $zero, -0x2A00($at)
    MEM_W(-0X2A00, ctx->r1) = 0;
L_8017DC88:
    // 0x8017DC88: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x8017DC8C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017DC90: addiu       $t3, $t3, -0x2A28
    ctx->r11 = ADD32(ctx->r11, -0X2A28);
    // 0x8017DC94: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8017DC98: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8017DC9C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8017DCA0: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x8017DCA4: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8017DCA8: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8017DCAC: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8017DCB0: addiu       $t2, $t1, 0xA4
    ctx->r10 = ADD32(ctx->r9, 0XA4);
    // 0x8017DCB4: addiu       $t5, $sp, 0x58
    ctx->r13 = ADD32(ctx->r29, 0X58);
    // 0x8017DCB8: addiu       $t6, $sp, 0x5C
    ctx->r14 = ADD32(ctx->r29, 0X5C);
    // 0x8017DCBC: addiu       $t4, $sp, 0x60
    ctx->r12 = ADD32(ctx->r29, 0X60);
    // 0x8017DCC0: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x8017DCC4: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8017DCC8: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8017DCCC: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    // 0x8017DCD0: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x8017DCD4: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    // 0x8017DCD8: jal         0x800D6E90
    // 0x8017DCDC: lw          $a3, 0x60($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X60);
    guMtxXFMF_recomp(rdram, ctx);
        goto after_2;
    // 0x8017DCDC: lw          $a3, 0x60($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X60);
    after_2:
    // 0x8017DCE0: jal         0x800D8790
    // 0x8017DCE4: nop

    guRandom_recomp(rdram, ctx);
        goto after_3;
    // 0x8017DCE4: nop

    after_3:
    // 0x8017DCE8: jal         0x800D8790
    // 0x8017DCEC: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    guRandom_recomp(rdram, ctx);
        goto after_4;
    // 0x8017DCEC: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    after_4:
    // 0x8017DCF0: jal         0x800D8790
    // 0x8017DCF4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    guRandom_recomp(rdram, ctx);
        goto after_5;
    // 0x8017DCF4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    after_5:
    // 0x8017DCF8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8017DCFC: div         $zero, $s2, $at
    lo = S32(S64(S32(ctx->r18)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r18)) % S64(S32(ctx->r1)));
    // 0x8017DD00: mfhi        $t5
    ctx->r13 = hi;
    // 0x8017DD04: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8017DD08: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x8017DD0C: div         $zero, $s1, $at
    lo = S32(S64(S32(ctx->r17)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r17)) % S64(S32(ctx->r1)));
    // 0x8017DD10: mfhi        $t4
    ctx->r12 = hi;
    // 0x8017DD14: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8017DD18: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8017DD1C: div         $zero, $s0, $at
    lo = S32(S64(S32(ctx->r16)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r16)) % S64(S32(ctx->r1)));
    // 0x8017DD20: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8017DD24: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8017DD28: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8017DD2C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017DD30: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8017DD34: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8017DD38: addiu       $t9, $t9, -0x2A28
    ctx->r25 = ADD32(ctx->r25, -0X2A28);
    // 0x8017DD3C: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8017DD40: lwc1        $f4, 0x98($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X98);
    // 0x8017DD44: lwc1        $f6, 0x54($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8017DD48: lwc1        $f16, 0x60($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X60);
    // 0x8017DD4C: lwc1        $f10, 0x58($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8017DD50: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8017DD54: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x8017DD58: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8017DD5C: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x8017DD60: addiu       $t7, $t4, -0x1
    ctx->r15 = ADD32(ctx->r12, -0X1);
    // 0x8017DD64: mfhi        $t8
    ctx->r24 = hi;
    // 0x8017DD68: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8017DD6C: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8017DD70: lw          $t1, 0x28($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X28);
    // 0x8017DD74: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x8017DD78: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8017DD7C: add.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x8017DD80: lwc1        $f18, 0x50($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8017DD84: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x8017DD88: addu        $a0, $a0, $t3
    ctx->r4 = ADD32(ctx->r4, ctx->r11);
    // 0x8017DD8C: mul.s       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x8017DD90: lwc1        $f4, 0x5C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8017DD94: lbu         $a0, -0x24A4($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X24A4);
    // 0x8017DD98: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8017DD9C: lwc1        $f8, 0x64($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X64);
    // 0x8017DDA0: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8017DDA4: lwc1        $f16, 0x9C($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X9C);
    // 0x8017DDA8: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8017DDAC: mul.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x8017DDB0: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x8017DDB4: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8017DDB8: cvt.s.w     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8017DDBC: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8017DDC0: lwc1        $f10, 0x60($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8017DDC4: add.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8017DDC8: lwc1        $f4, 0x68($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X68);
    // 0x8017DDCC: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x8017DDD0: lwc1        $f16, 0xA0($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0XA0);
    // 0x8017DDD4: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8017DDD8: mul.s       $f10, $f16, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x8017DDDC: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x8017DDE0: nop

    // 0x8017DDE4: cvt.s.w     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8017DDE8: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8017DDEC: mul.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x8017DDF0: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8017DDF4: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x8017DDF8: jal         0x8018AB30
    // 0x8017DDFC: nop

    func_8018AB30_1501A0(rdram, ctx);
        goto after_6;
    // 0x8017DDFC: nop

    after_6:
L_8017DE00:
    // 0x8017DE00: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x8017DE04: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017DE08: addiu       $t3, $t3, -0x2A28
    ctx->r11 = ADD32(ctx->r11, -0X2A28);
    // 0x8017DE0C: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8017DE10: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8017DE14: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8017DE18: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x8017DE1C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8017DE20: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8017DE24: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8017DE28: addu        $t5, $t2, $t3
    ctx->r13 = ADD32(ctx->r10, ctx->r11);
    // 0x8017DE2C: lw          $t6, 0x28($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X28);
    // 0x8017DE30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017DE34: addiu       $t4, $t6, 0x1
    ctx->r12 = ADD32(ctx->r14, 0X1);
    // 0x8017DE38: sw          $t4, 0x28($t5)
    MEM_W(0X28, ctx->r13) = ctx->r12;
L_8017DE3C:
    // 0x8017DE3C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8017DE40: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8017DE44: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8017DE48: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8017DE4C: jr          $ra
    // 0x8017DE50: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8017DE50: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_8017DE54_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017DE54: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8017DE58: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x8017DE5C: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x8017DE60: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017DE64: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x8017DE68: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8017DE6C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8017DE70: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017DE74: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8017DE78: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017DE7C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8017DE80: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017DE84: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8017DE88: lw          $t8, -0x2A00($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2A00);
    // 0x8017DE8C: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x8017DE90: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x8017DE94: lui         $s0, 0x801A
    ctx->r16 = S32(0X801A << 16);
    // 0x8017DE98: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8017DE9C: addu        $s0, $s0, $t0
    ctx->r16 = ADD32(ctx->r16, ctx->r8);
    // 0x8017DEA0: lbu         $s0, -0x23A4($s0)
    ctx->r16 = MEM_BU(ctx->r16, -0X23A4);
    // 0x8017DEA4: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8017DEA8: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x8017DEAC: beq         $s0, $zero, L_8017DED0
    if (ctx->r16 == 0) {
        // 0x8017DEB0: sw          $a3, 0x64($sp)
        MEM_W(0X64, ctx->r29) = ctx->r7;
            goto L_8017DED0;
    }
    // 0x8017DEB0: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    // 0x8017DEB4: addiu       $at, $zero, 0xFE
    ctx->r1 = ADD32(0, 0XFE);
    // 0x8017DEB8: beq         $s0, $at, L_8017E198
    if (ctx->r16 == ctx->r1) {
        // 0x8017DEBC: addiu       $at, $zero, 0xFF
        ctx->r1 = ADD32(0, 0XFF);
            goto L_8017E198;
    }
    // 0x8017DEBC: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8017DEC0: beq         $s0, $at, L_8017DED8
    if (ctx->r16 == ctx->r1) {
        // 0x8017DEC4: nop
    
            goto L_8017DED8;
    }
    // 0x8017DEC4: nop

    // 0x8017DEC8: b           L_8017DF04
    // 0x8017DECC: nop

        goto L_8017DF04;
    // 0x8017DECC: nop

L_8017DED0:
    // 0x8017DED0: b           L_8017E1D4
    // 0x8017DED4: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
        goto L_8017E1D4;
    // 0x8017DED4: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
L_8017DED8:
    // 0x8017DED8: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x8017DEDC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017DEE0: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8017DEE4: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8017DEE8: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8017DEEC: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x8017DEF0: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8017DEF4: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8017DEF8: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8017DEFC: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x8017DF00: sw          $zero, -0x2A00($at)
    MEM_W(-0X2A00, ctx->r1) = 0;
L_8017DF04:
    // 0x8017DF04: jal         0x800D8790
    // 0x8017DF08: nop

    guRandom_recomp(rdram, ctx);
        goto after_0;
    // 0x8017DF08: nop

    after_0:
    // 0x8017DF0C: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x8017DF10: bgez        $v0, L_8017DF24
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8017DF14: andi        $t3, $v0, 0x3
        ctx->r11 = ctx->r2 & 0X3;
            goto L_8017DF24;
    }
    // 0x8017DF14: andi        $t3, $v0, 0x3
    ctx->r11 = ctx->r2 & 0X3;
    // 0x8017DF18: beq         $t3, $zero, L_8017DF24
    if (ctx->r11 == 0) {
        // 0x8017DF1C: nop
    
            goto L_8017DF24;
    }
    // 0x8017DF1C: nop

    // 0x8017DF20: addiu       $t3, $t3, -0x4
    ctx->r11 = ADD32(ctx->r11, -0X4);
L_8017DF24:
    // 0x8017DF24: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x8017DF28: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8017DF2C: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8017DF30: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x8017DF34: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8017DF38: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x8017DF3C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8017DF40: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8017DF44: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x8017DF48: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8017DF4C: lwc1        $f16, 0x60($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8017DF50: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8017DF54: sub.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d - ctx->f8.d;
    // 0x8017DF58: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8017DF5C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017DF60: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x8017DF64: lwc1        $f6, -0x2990($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2990);
    // 0x8017DF68: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8017DF6C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8017DF70: mul.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x8017DF74: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8017DF78: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017DF7C: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x8017DF80: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8017DF84: nop

    // 0x8017DF88: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8017DF8C: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x8017DF90: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x8017DF94: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8017DF98: jal         0x800D8790
    // 0x8017DF9C: swc1        $f10, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f10.u32l;
    guRandom_recomp(rdram, ctx);
        goto after_1;
    // 0x8017DF9C: swc1        $f10, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f10.u32l;
    after_1:
    // 0x8017DFA0: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x8017DFA4: bgez        $v0, L_8017DFB8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8017DFA8: andi        $t7, $v0, 0x3
        ctx->r15 = ctx->r2 & 0X3;
            goto L_8017DFB8;
    }
    // 0x8017DFA8: andi        $t7, $v0, 0x3
    ctx->r15 = ctx->r2 & 0X3;
    // 0x8017DFAC: beq         $t7, $zero, L_8017DFB8
    if (ctx->r15 == 0) {
        // 0x8017DFB0: nop
    
            goto L_8017DFB8;
    }
    // 0x8017DFB0: nop

    // 0x8017DFB4: addiu       $t7, $t7, -0x4
    ctx->r15 = ADD32(ctx->r15, -0X4);
L_8017DFB8:
    // 0x8017DFB8: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x8017DFBC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8017DFC0: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8017DFC4: cvt.d.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.d = CVT_D_W(ctx->f16.u32l);
    // 0x8017DFC8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8017DFCC: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x8017DFD0: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8017DFD4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017DFD8: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8017DFDC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8017DFE0: lwc1        $f8, 0x60($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8017DFE4: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8017DFE8: sub.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f18.d - ctx->f4.d;
    // 0x8017DFEC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8017DFF0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017DFF4: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8017DFF8: lwc1        $f18, -0x298C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X298C);
    // 0x8017DFFC: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8017E000: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8017E004: mul.d       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x8017E008: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017E00C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017E010: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x8017E014: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8017E018: nop

    // 0x8017E01C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8017E020: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x8017E024: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x8017E028: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8017E02C: jal         0x800D8790
    // 0x8017E030: swc1        $f6, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f6.u32l;
    guRandom_recomp(rdram, ctx);
        goto after_2;
    // 0x8017E030: swc1        $f6, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f6.u32l;
    after_2:
    // 0x8017E034: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x8017E038: bgez        $v0, L_8017E04C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8017E03C: andi        $t1, $v0, 0x3
        ctx->r9 = ctx->r2 & 0X3;
            goto L_8017E04C;
    }
    // 0x8017E03C: andi        $t1, $v0, 0x3
    ctx->r9 = ctx->r2 & 0X3;
    // 0x8017E040: beq         $t1, $zero, L_8017E04C
    if (ctx->r9 == 0) {
        // 0x8017E044: nop
    
            goto L_8017E04C;
    }
    // 0x8017E044: nop

    // 0x8017E048: addiu       $t1, $t1, -0x4
    ctx->r9 = ADD32(ctx->r9, -0X4);
L_8017E04C:
    // 0x8017E04C: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x8017E050: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8017E054: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8017E058: cvt.d.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.d = CVT_D_W(ctx->f8.u32l);
    // 0x8017E05C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8017E060: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x8017E064: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8017E068: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8017E06C: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x8017E070: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8017E074: lwc1        $f4, 0x60($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8017E078: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8017E07C: sub.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d - ctx->f16.d;
    // 0x8017E080: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8017E084: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017E088: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x8017E08C: lwc1        $f10, -0x2988($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2988);
    // 0x8017E090: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8017E094: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8017E098: mul.d       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f18.d, ctx->f6.d);
    // 0x8017E09C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8017E0A0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017E0A4: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x8017E0A8: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8017E0AC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017E0B0: addiu       $t7, $t7, -0x2A28
    ctx->r15 = ADD32(ctx->r15, -0X2A28);
    // 0x8017E0B4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017E0B8: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x8017E0BC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017E0C0: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x8017E0C4: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8017E0C8: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8017E0CC: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x8017E0D0: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x8017E0D4: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x8017E0D8: swc1        $f18, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->f18.u32l;
    // 0x8017E0DC: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    // 0x8017E0E0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017E0E4: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x8017E0E8: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8017E0EC: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8017E0F0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8017E0F4: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x8017E0F8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8017E0FC: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8017E100: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8017E104: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8017E108: lwc1        $f4, 0x60($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X60);
    // 0x8017E10C: lw          $t9, 0x28($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X28);
    // 0x8017E110: lw          $a2, 0x64($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X64);
    // 0x8017E114: lw          $a3, 0x68($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X68);
    // 0x8017E118: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8017E11C: lwc1        $f6, 0x64($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X64);
    // 0x8017E120: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8017E124: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x8017E128: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8017E12C: lwc1        $f8, 0x68($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X68);
    // 0x8017E130: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8017E134: addu        $a0, $a0, $t1
    ctx->r4 = ADD32(ctx->r4, ctx->r9);
    // 0x8017E138: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8017E13C: lwc1        $f10, 0x0($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X0);
    // 0x8017E140: lbu         $a0, -0x23A4($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X23A4);
    // 0x8017E144: add.s       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8017E148: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    // 0x8017E14C: lwc1        $f6, 0x64($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X64);
    // 0x8017E150: lwc1        $f18, 0x4($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X4);
    // 0x8017E154: add.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8017E158: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x8017E15C: lwc1        $f4, 0x68($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X68);
    // 0x8017E160: lwc1        $f10, 0x8($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X8);
    // 0x8017E164: add.s       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8017E168: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x8017E16C: lwc1        $f18, 0x88($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X88);
    // 0x8017E170: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    // 0x8017E174: lwc1        $f6, 0x8C($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X8C);
    // 0x8017E178: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x8017E17C: lwc1        $f8, 0x90($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X90);
    // 0x8017E180: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x8017E184: lw          $t5, 0x4($t8)
    ctx->r13 = MEM_W(ctx->r24, 0X4);
    // 0x8017E188: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x8017E18C: ori         $t6, $t5, 0x100
    ctx->r14 = ctx->r13 | 0X100;
    // 0x8017E190: jal         0x80187E5C
    // 0x8017E194: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    func_80187E5C_1501A0(rdram, ctx);
        goto after_3;
    // 0x8017E194: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    after_3:
L_8017E198:
    // 0x8017E198: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x8017E19C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017E1A0: addiu       $t0, $t0, -0x2A28
    ctx->r8 = ADD32(ctx->r8, -0X2A28);
    // 0x8017E1A4: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8017E1A8: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x8017E1AC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8017E1B0: subu        $t9, $t9, $t7
    ctx->r25 = SUB32(ctx->r25, ctx->r15);
    // 0x8017E1B4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8017E1B8: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x8017E1BC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8017E1C0: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8017E1C4: lw          $t2, 0x28($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X28);
    // 0x8017E1C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017E1CC: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8017E1D0: sw          $t3, 0x28($t1)
    MEM_W(0X28, ctx->r9) = ctx->r11;
L_8017E1D4:
    // 0x8017E1D4: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8017E1D8: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x8017E1DC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x8017E1E0: jr          $ra
    // 0x8017E1E4: nop

    return;
    // 0x8017E1E4: nop

;}
RECOMP_FUNC void func_8017E1E8_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017E1E8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8017E1EC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8017E1F0: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8017E1F4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017E1F8: addiu       $t8, $t8, -0x2A28
    ctx->r24 = ADD32(ctx->r24, -0X2A28);
    // 0x8017E1FC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8017E200: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8017E204: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017E208: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8017E20C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017E210: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8017E214: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017E218: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8017E21C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8017E220: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8017E224: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8017E228: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x8017E22C: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8017E230: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8017E234: lwc1        $f4, 0x98($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X98);
    // 0x8017E238: lwc1        $f8, 0x9C($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X9C);
    // 0x8017E23C: lwc1        $f18, 0xA0($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0XA0);
    // 0x8017E240: mul.s       $f6, $f4, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x8017E244: nop

    // 0x8017E248: mul.s       $f10, $f8, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x8017E24C: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8017E250: mul.s       $f4, $f18, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x8017E254: jal         0x800D68E0
    // 0x8017E258: add.s       $f12, $f4, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f16.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x8017E258: add.s       $f12, $f4, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f16.fl;
    after_0:
    // 0x8017E25C: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8017E260: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8017E264: lwc1        $f16, 0x3C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8017E268: mul.s       $f6, $f8, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x8017E26C: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x8017E270: mul.s       $f18, $f10, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x8017E274: add.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x8017E278: mul.s       $f8, $f16, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8017E27C: jal         0x800D68E0
    // 0x8017E280: add.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x8017E280: add.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f8.fl;
    after_1:
    // 0x8017E284: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8017E288: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017E28C: addiu       $t2, $t2, -0x2A28
    ctx->r10 = ADD32(ctx->r10, -0X2A28);
    // 0x8017E290: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8017E294: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8017E298: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8017E29C: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x8017E2A0: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8017E2A4: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8017E2A8: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8017E2AC: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x8017E2B0: lwc1        $f10, 0x98($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X98);
    // 0x8017E2B4: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8017E2B8: lwc1        $f16, 0x9C($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X9C);
    // 0x8017E2BC: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8017E2C0: mul.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x8017E2C4: lwc1        $f6, 0xA0($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0XA0);
    // 0x8017E2C8: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8017E2CC: mul.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x8017E2D0: lwc1        $f16, 0x3C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8017E2D4: mul.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x8017E2D8: add.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x8017E2DC: mul.s       $f8, $f20, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f22.fl);
    // 0x8017E2E0: add.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8017E2E4: jal         0x800E4BE0
    // 0x8017E2E8: div.s       $f12, $f18, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = DIV_S(ctx->f18.fl, ctx->f8.fl);
    func_800E4BE0(rdram, ctx);
        goto after_2;
    // 0x8017E2E8: div.s       $f12, $f18, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = DIV_S(ctx->f18.fl, ctx->f8.fl);
    after_2:
    // 0x8017E2EC: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8017E2F0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017E2F4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8017E2F8: lwc1        $f10, -0x3F0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X3F0);
    // 0x8017E2FC: mul.s       $f16, $f0, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8017E300: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017E304: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x8017E308: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017E30C: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x8017E310: div.s       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f10.fl);
    // 0x8017E314: swc1        $f4, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f4.u32l;
    // 0x8017E318: jal         0x800E4D20
    // 0x8017E31C: lwc1        $f12, 0x0($t5)
    ctx->f12.u32l = MEM_W(ctx->r13, 0X0);
    fabsf_recomp(rdram, ctx);
        goto after_3;
    // 0x8017E31C: lwc1        $f12, 0x0($t5)
    ctx->f12.u32l = MEM_W(ctx->r13, 0X0);
    after_3:
    // 0x8017E320: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017E324: lw          $t6, -0x2E40($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2E40);
    // 0x8017E328: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8017E32C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8017E330: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8017E334: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8017E338: lwc1        $f18, -0x2390($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2390);
    // 0x8017E33C: c.lt.s      $f18, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f18.fl < ctx->f20.fl;
    // 0x8017E340: nop

    // 0x8017E344: bc1f        L_8017E384
    if (!c1cs) {
        // 0x8017E348: nop
    
            goto L_8017E384;
    }
    // 0x8017E348: nop

    // 0x8017E34C: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8017E350: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017E354: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x8017E358: swc1        $f8, 0xC8($t8)
    MEM_W(0XC8, ctx->r24) = ctx->f8.u32l;
    // 0x8017E35C: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8017E360: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017E364: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x8017E368: swc1        $f6, 0xCC($t9)
    MEM_W(0XCC, ctx->r25) = ctx->f6.u32l;
    // 0x8017E36C: lwc1        $f16, 0x3C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8017E370: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017E374: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x8017E378: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8017E37C: b           L_8017E430
    // 0x8017E380: swc1        $f16, 0xD0($t0)
    MEM_W(0XD0, ctx->r8) = ctx->f16.u32l;
        goto L_8017E430;
    // 0x8017E380: swc1        $f16, 0xD0($t0)
    MEM_W(0XD0, ctx->r8) = ctx->f16.u32l;
L_8017E384:
    // 0x8017E384: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8017E388: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017E38C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017E390: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8017E394: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8017E398: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8017E39C: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x8017E3A0: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8017E3A4: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8017E3A8: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8017E3AC: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x8017E3B0: lwc1        $f10, -0x2990($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2990);
    // 0x8017E3B4: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x8017E3B8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017E3BC: swc1        $f10, 0xC8($t3)
    MEM_W(0XC8, ctx->r11) = ctx->f10.u32l;
    // 0x8017E3C0: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x8017E3C4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017E3C8: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x8017E3CC: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8017E3D0: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8017E3D4: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8017E3D8: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x8017E3DC: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8017E3E0: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8017E3E4: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8017E3E8: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x8017E3EC: lwc1        $f4, -0x298C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X298C);
    // 0x8017E3F0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017E3F4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017E3F8: swc1        $f4, 0xCC($t6)
    MEM_W(0XCC, ctx->r14) = ctx->f4.u32l;
    // 0x8017E3FC: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8017E400: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x8017E404: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017E408: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8017E40C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8017E410: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8017E414: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8017E418: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8017E41C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8017E420: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8017E424: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8017E428: lwc1        $f18, -0x2988($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2988);
    // 0x8017E42C: swc1        $f18, 0xD0($t9)
    MEM_W(0XD0, ctx->r25) = ctx->f18.u32l;
L_8017E430:
    // 0x8017E430: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8017E434: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8017E438: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x8017E43C: jr          $ra
    // 0x8017E440: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8017E440: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8017E444_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017E444: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8017E448: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x8017E44C: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x8017E450: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017E454: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x8017E458: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8017E45C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8017E460: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017E464: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8017E468: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017E46C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8017E470: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017E474: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8017E478: lhu         $t8, -0x2A28($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X2A28);
    // 0x8017E47C: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x8017E480: sw          $a2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r6;
    // 0x8017E484: andi        $t9, $t8, 0x800
    ctx->r25 = ctx->r24 & 0X800;
    // 0x8017E488: sw          $a3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r7;
    // 0x8017E48C: sdc1        $f24, 0x50($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X50, ctx->r29);
    // 0x8017E490: sdc1        $f22, 0x48($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X48, ctx->r29);
    // 0x8017E494: beq         $t9, $zero, L_8017E92C
    if (ctx->r25 == 0) {
        // 0x8017E498: sdc1        $f20, 0x40($sp)
        CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X40, ctx->r29);
            goto L_8017E92C;
    }
    // 0x8017E498: sdc1        $f20, 0x40($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X40, ctx->r29);
    // 0x8017E49C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017E4A0: lw          $t0, -0x2D68($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2D68);
    // 0x8017E4A4: bne         $t0, $zero, L_8017E92C
    if (ctx->r8 != 0) {
        // 0x8017E4A8: nop
    
            goto L_8017E92C;
    }
    // 0x8017E4A8: nop

    // 0x8017E4AC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017E4B0: lhu         $t1, -0x2BA8($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X2BA8);
    // 0x8017E4B4: andi        $t2, $t1, 0x4000
    ctx->r10 = ctx->r9 & 0X4000;
    // 0x8017E4B8: bne         $t2, $zero, L_8017E92C
    if (ctx->r10 != 0) {
        // 0x8017E4BC: nop
    
            goto L_8017E92C;
    }
    // 0x8017E4BC: nop

    // 0x8017E4C0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017E4C4: addiu       $t3, $t3, -0x2BA8
    ctx->r11 = ADD32(ctx->r11, -0X2BA8);
    // 0x8017E4C8: lw          $t4, 0xC($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XC);
    // 0x8017E4CC: bne         $t4, $zero, L_8017E4FC
    if (ctx->r12 != 0) {
        // 0x8017E4D0: nop
    
            goto L_8017E4FC;
    }
    // 0x8017E4D0: nop

    // 0x8017E4D4: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017E4D8: lw          $t5, -0x2E48($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2E48);
    // 0x8017E4DC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8017E4E0: bne         $t5, $at, L_8017E92C
    if (ctx->r13 != ctx->r1) {
        // 0x8017E4E4: nop
    
            goto L_8017E92C;
    }
    // 0x8017E4E4: nop

    // 0x8017E4E8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017E4EC: addiu       $t6, $t6, -0x2BA8
    ctx->r14 = ADD32(ctx->r14, -0X2BA8);
    // 0x8017E4F0: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x8017E4F4: beq         $t7, $zero, L_8017E92C
    if (ctx->r15 == 0) {
        // 0x8017E4F8: nop
    
            goto L_8017E92C;
    }
    // 0x8017E4F8: nop

L_8017E4FC:
    // 0x8017E4FC: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
    // 0x8017E500: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x8017E504: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017E508: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017E50C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8017E510: lwc1        $f6, -0x2E30($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x8017E514: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8017E518: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8017E51C: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8017E520: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8017E524: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8017E528: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8017E52C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8017E530: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017E534: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8017E538: lwc1        $f10, -0x2994($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2994);
    // 0x8017E53C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017E540: lwc1        $f18, -0x2BCC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2BCC);
    // 0x8017E544: div.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8017E548: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8017E54C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017E550: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017E554: addiu       $t0, $t0, -0x4198
    ctx->r8 = ADD32(ctx->r8, -0X4198);
    // 0x8017E558: lwc1        $f8, 0x0($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8017E55C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017E560: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x8017E564: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x8017E568: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017E56C: addiu       $t4, $t4, -0x4198
    ctx->r12 = ADD32(ctx->r12, -0X4198);
    // 0x8017E570: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017E574: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x8017E578: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017E57C: addiu       $t8, $t8, -0x4198
    ctx->r24 = ADD32(ctx->r24, -0X4198);
    // 0x8017E580: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017E584: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x8017E588: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017E58C: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x8017E590: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8017E594: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8017E598: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017E59C: div.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8017E5A0: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8017E5A4: swc1        $f16, 0xC8($t1)
    MEM_W(0XC8, ctx->r9) = ctx->f16.u32l;
    // 0x8017E5A8: lw          $t2, 0x70($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X70);
    // 0x8017E5AC: lwc1        $f4, -0x2E30($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x8017E5B0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017E5B4: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8017E5B8: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8017E5BC: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8017E5C0: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x8017E5C4: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8017E5C8: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8017E5CC: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8017E5D0: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8017E5D4: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x8017E5D8: lwc1        $f10, -0x2994($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2994);
    // 0x8017E5DC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017E5E0: lwc1        $f16, -0x2BC8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2BC8);
    // 0x8017E5E4: div.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f10.fl, ctx->f6.fl);
    // 0x8017E5E8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8017E5EC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017E5F0: lwc1        $f6, 0x4($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X4);
    // 0x8017E5F4: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x8017E5F8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017E5FC: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x8017E600: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017E604: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x8017E608: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017E60C: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x8017E610: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8017E614: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8017E618: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017E61C: div.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8017E620: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8017E624: swc1        $f8, 0xCC($t5)
    MEM_W(0XCC, ctx->r13) = ctx->f8.u32l;
    // 0x8017E628: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x8017E62C: lwc1        $f18, -0x2E30($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x8017E630: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017E634: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8017E638: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8017E63C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017E640: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8017E644: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8017E648: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017E64C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8017E650: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017E654: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8017E658: lwc1        $f10, -0x2994($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2994);
    // 0x8017E65C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017E660: lwc1        $f8, -0x2BC4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2BC4);
    // 0x8017E664: div.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8017E668: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8017E66C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8017E670: lwc1        $f4, 0x8($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X8);
    // 0x8017E674: mul.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8017E678: div.s       $f10, $f16, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8017E67C: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8017E680: swc1        $f6, 0xD0($t9)
    MEM_W(0XD0, ctx->r25) = ctx->f6.u32l;
    // 0x8017E684: lwc1        $f16, 0x78($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8017E688: lwc1        $f8, 0xC8($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0XC8);
    // 0x8017E68C: sub.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x8017E690: swc1        $f18, 0xD4($t0)
    MEM_W(0XD4, ctx->r8) = ctx->f18.u32l;
    // 0x8017E694: lwc1        $f4, 0x7C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8017E698: lwc1        $f10, 0xCC($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0XCC);
    // 0x8017E69C: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8017E6A0: swc1        $f6, 0xD8($t1)
    MEM_W(0XD8, ctx->r9) = ctx->f6.u32l;
    // 0x8017E6A4: lwc1        $f16, 0x80($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X80);
    // 0x8017E6A8: lwc1        $f8, 0xD0($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0XD0);
    // 0x8017E6AC: sub.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x8017E6B0: swc1        $f18, 0xDC($t2)
    MEM_W(0XDC, ctx->r10) = ctx->f18.u32l;
    // 0x8017E6B4: lwc1        $f10, 0xD4($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0XD4);
    // 0x8017E6B8: lwc1        $f6, 0xD8($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0XD8);
    // 0x8017E6BC: lwc1        $f18, 0xDC($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0XDC);
    // 0x8017E6C0: mul.s       $f4, $f10, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x8017E6C4: nop

    // 0x8017E6C8: mul.s       $f8, $f6, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x8017E6CC: add.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8017E6D0: mul.s       $f10, $f18, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x8017E6D4: jal         0x800D68E0
    // 0x8017E6D8: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x8017E6D8: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    after_0:
    // 0x8017E6DC: lw          $t4, 0x70($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X70);
    // 0x8017E6E0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017E6E4: addiu       $t6, $t6, -0x2A28
    ctx->r14 = ADD32(ctx->r14, -0X2A28);
    // 0x8017E6E8: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8017E6EC: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8017E6F0: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8017E6F4: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x8017E6F8: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8017E6FC: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8017E700: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8017E704: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x8017E708: lwc1        $f6, 0xC4($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0XC4);
    // 0x8017E70C: lwc1        $f8, 0xC8($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0XC8);
    // 0x8017E710: lwc1        $f16, 0xCC($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0XCC);
    // 0x8017E714: mul.s       $f4, $f6, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x8017E718: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x8017E71C: mul.s       $f18, $f8, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x8017E720: add.s       $f10, $f4, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x8017E724: mul.s       $f6, $f16, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8017E728: jal         0x800D68E0
    // 0x8017E72C: add.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x8017E72C: add.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f10.fl;
    after_1:
    // 0x8017E730: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x8017E734: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017E738: addiu       $t1, $t1, -0x2A28
    ctx->r9 = ADD32(ctx->r9, -0X2A28);
    // 0x8017E73C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8017E740: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8017E744: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8017E748: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x8017E74C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8017E750: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8017E754: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8017E758: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017E75C: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x8017E760: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8017E764: lwc1        $f4, 0xC4($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0XC4);
    // 0x8017E768: lwc1        $f8, 0xD4($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0XD4);
    // 0x8017E76C: lwc1        $f6, 0xC8($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0XC8);
    // 0x8017E770: lwc1        $f16, 0xD8($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0XD8);
    // 0x8017E774: mul.s       $f18, $f8, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8017E778: lwc1        $f4, 0xDC($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0XDC);
    // 0x8017E77C: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x8017E780: mul.s       $f10, $f16, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x8017E784: lwc1        $f16, 0xCC($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0XCC);
    // 0x8017E788: mul.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x8017E78C: add.s       $f8, $f18, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x8017E790: mul.s       $f10, $f22, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f24.fl);
    // 0x8017E794: add.s       $f18, $f8, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8017E798: jal         0x800E4BE0
    // 0x8017E79C: div.s       $f12, $f18, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = DIV_S(ctx->f18.fl, ctx->f10.fl);
    func_800E4BE0(rdram, ctx);
        goto after_2;
    // 0x8017E79C: div.s       $f12, $f18, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = DIV_S(ctx->f18.fl, ctx->f10.fl);
    after_2:
    // 0x8017E7A0: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8017E7A4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017E7A8: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8017E7AC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8017E7B0: mul.s       $f16, $f4, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x8017E7B4: lwc1        $f8, -0x3EC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3EC);
    // 0x8017E7B8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017E7BC: lw          $t3, -0x2E40($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2E40);
    // 0x8017E7C0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8017E7C4: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8017E7C8: div.s       $f6, $f16, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = DIV_S(ctx->f16.fl, ctx->f8.fl);
    // 0x8017E7CC: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x8017E7D0: lwc1        $f18, -0x2380($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2380);
    // 0x8017E7D4: c.lt.s      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.fl < ctx->f6.fl;
    // 0x8017E7D8: nop

    // 0x8017E7DC: bc1f        L_8017E890
    if (!c1cs) {
        // 0x8017E7E0: nop
    
            goto L_8017E890;
    }
    // 0x8017E7E0: nop

    // 0x8017E7E4: lw          $t5, 0x70($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X70);
    // 0x8017E7E8: lwc1        $f10, 0x78($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8017E7EC: lwc1        $f4, 0x7C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8017E7F0: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8017E7F4: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8017E7F8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8017E7FC: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x8017E800: lwc1        $f16, 0x80($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X80);
    // 0x8017E804: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8017E808: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017E80C: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8017E810: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8017E814: addiu       $t7, $t7, -0x2A28
    ctx->r15 = ADD32(ctx->r15, -0X2A28);
    // 0x8017E818: addu        $t9, $t6, $t7
    ctx->r25 = ADD32(ctx->r14, ctx->r15);
    // 0x8017E81C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8017E820: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x8017E824: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x8017E828: lwc1        $f8, 0xC4($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0XC4);
    // 0x8017E82C: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8017E830: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8017E834: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8017E838: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x8017E83C: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x8017E840: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x8017E844: lwc1        $f18, 0xC8($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0XC8);
    // 0x8017E848: add.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8017E84C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017E850: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8017E854: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x8017E858: lwc1        $f10, 0xCC($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0XCC);
    // 0x8017E85C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8017E860: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x8017E864: add.s       $f6, $f10, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8017E868: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    // 0x8017E86C: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x8017E870: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    // 0x8017E874: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x8017E878: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x8017E87C: ori         $t1, $t0, 0x100
    ctx->r9 = ctx->r8 | 0X100;
    // 0x8017E880: jal         0x80187E5C
    // 0x8017E884: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
    func_80187E5C_1501A0(rdram, ctx);
        goto after_3;
    // 0x8017E884: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
    after_3:
    // 0x8017E888: b           L_8017E92C
    // 0x8017E88C: nop

        goto L_8017E92C;
    // 0x8017E88C: nop

L_8017E890:
    // 0x8017E890: lwc1        $f10, 0x78($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8017E894: lwc1        $f16, 0x7C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8017E898: lwc1        $f6, 0x80($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X80);
    // 0x8017E89C: lw          $t2, 0x70($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X70);
    // 0x8017E8A0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017E8A4: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x8017E8A8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8017E8AC: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x8017E8B0: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x8017E8B4: lwc1        $f18, 0xC8($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0XC8);
    // 0x8017E8B8: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8017E8BC: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8017E8C0: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8017E8C4: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    // 0x8017E8C8: lwc1        $f4, 0xCC($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0XCC);
    // 0x8017E8CC: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x8017E8D0: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8017E8D4: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8017E8D8: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8017E8DC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017E8E0: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x8017E8E4: lwc1        $f8, 0xD0($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0XD0);
    // 0x8017E8E8: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8017E8EC: lw          $t4, -0x2A24($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2A24);
    // 0x8017E8F0: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8017E8F4: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x8017E8F8: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x8017E8FC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8017E900: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8017E904: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8017E908: ori         $t5, $t4, 0x100
    ctx->r13 = ctx->r12 | 0X100;
    // 0x8017E90C: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
    // 0x8017E910: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x8017E914: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x8017E918: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x8017E91C: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    // 0x8017E920: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    // 0x8017E924: jal         0x80187E5C
    // 0x8017E928: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    func_80187E5C_1501A0(rdram, ctx);
        goto after_4;
    // 0x8017E928: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    after_4:
L_8017E92C:
    // 0x8017E92C: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x8017E930: ldc1        $f20, 0x40($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X40);
    // 0x8017E934: ldc1        $f22, 0x48($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X48);
    // 0x8017E938: ldc1        $f24, 0x50($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X50);
    // 0x8017E93C: jr          $ra
    // 0x8017E940: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x8017E940: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_8017E944_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017E944: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8017E948: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x8017E94C: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x8017E950: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017E954: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8017E958: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8017E95C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8017E960: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017E964: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8017E968: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017E96C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8017E970: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017E974: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8017E978: lhu         $t8, -0x2A28($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X2A28);
    // 0x8017E97C: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x8017E980: sw          $a2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r6;
    // 0x8017E984: andi        $t9, $t8, 0x800
    ctx->r25 = ctx->r24 & 0X800;
    // 0x8017E988: sw          $a3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r7;
    // 0x8017E98C: sdc1        $f22, 0x48($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X48, ctx->r29);
    // 0x8017E990: beq         $t9, $zero, L_8017ED10
    if (ctx->r25 == 0) {
        // 0x8017E994: sdc1        $f20, 0x40($sp)
        CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X40, ctx->r29);
            goto L_8017ED10;
    }
    // 0x8017E994: sdc1        $f20, 0x40($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X40, ctx->r29);
    // 0x8017E998: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017E99C: lw          $t0, -0x2D68($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2D68);
    // 0x8017E9A0: bne         $t0, $zero, L_8017ED10
    if (ctx->r8 != 0) {
        // 0x8017E9A4: nop
    
            goto L_8017ED10;
    }
    // 0x8017E9A4: nop

    // 0x8017E9A8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017E9AC: lhu         $t1, -0x2BA8($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X2BA8);
    // 0x8017E9B0: andi        $t2, $t1, 0x4000
    ctx->r10 = ctx->r9 & 0X4000;
    // 0x8017E9B4: bne         $t2, $zero, L_8017ED10
    if (ctx->r10 != 0) {
        // 0x8017E9B8: nop
    
            goto L_8017ED10;
    }
    // 0x8017E9B8: nop

    // 0x8017E9BC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017E9C0: addiu       $t3, $t3, -0x2BA8
    ctx->r11 = ADD32(ctx->r11, -0X2BA8);
    // 0x8017E9C4: lw          $t4, 0xC($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XC);
    // 0x8017E9C8: bne         $t4, $zero, L_8017E9F8
    if (ctx->r12 != 0) {
        // 0x8017E9CC: nop
    
            goto L_8017E9F8;
    }
    // 0x8017E9CC: nop

    // 0x8017E9D0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017E9D4: lw          $t5, -0x2E48($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2E48);
    // 0x8017E9D8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8017E9DC: bne         $t5, $at, L_8017ED10
    if (ctx->r13 != ctx->r1) {
        // 0x8017E9E0: nop
    
            goto L_8017ED10;
    }
    // 0x8017E9E0: nop

    // 0x8017E9E4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017E9E8: addiu       $t6, $t6, -0x2BA8
    ctx->r14 = ADD32(ctx->r14, -0X2BA8);
    // 0x8017E9EC: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x8017E9F0: beq         $t7, $zero, L_8017ED10
    if (ctx->r15 == 0) {
        // 0x8017E9F4: nop
    
            goto L_8017ED10;
    }
    // 0x8017E9F4: nop

L_8017E9F8:
    // 0x8017E9F8: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
    // 0x8017E9FC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017EA00: addiu       $t0, $t0, -0x2A28
    ctx->r8 = ADD32(ctx->r8, -0X2A28);
    // 0x8017EA04: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8017EA08: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8017EA0C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8017EA10: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8017EA14: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8017EA18: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8017EA1C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8017EA20: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8017EA24: lwc1        $f4, 0x98($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X98);
    // 0x8017EA28: lwc1        $f8, 0x9C($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X9C);
    // 0x8017EA2C: lwc1        $f18, 0xA0($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0XA0);
    // 0x8017EA30: mul.s       $f6, $f4, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x8017EA34: nop

    // 0x8017EA38: mul.s       $f10, $f8, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x8017EA3C: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8017EA40: mul.s       $f4, $f18, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x8017EA44: jal         0x800D68E0
    // 0x8017EA48: add.s       $f12, $f4, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f16.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x8017EA48: add.s       $f12, $f4, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f16.fl;
    after_0:
    // 0x8017EA4C: lw          $t2, 0x70($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X70);
    // 0x8017EA50: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017EA54: addiu       $t4, $t4, -0x2A28
    ctx->r12 = ADD32(ctx->r12, -0X2A28);
    // 0x8017EA58: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8017EA5C: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8017EA60: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8017EA64: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x8017EA68: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8017EA6C: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8017EA70: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8017EA74: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8017EA78: lwc1        $f8, 0xC4($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0XC4);
    // 0x8017EA7C: lwc1        $f10, 0xC8($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0XC8);
    // 0x8017EA80: lwc1        $f16, 0xCC($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0XCC);
    // 0x8017EA84: mul.s       $f6, $f8, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x8017EA88: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x8017EA8C: mul.s       $f18, $f10, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x8017EA90: add.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x8017EA94: mul.s       $f8, $f16, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8017EA98: jal         0x800D68E0
    // 0x8017EA9C: add.s       $f12, $f8, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x8017EA9C: add.s       $f12, $f8, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f4.fl;
    after_1:
    // 0x8017EAA0: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x8017EAA4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017EAA8: addiu       $t8, $t8, -0x2A28
    ctx->r24 = ADD32(ctx->r24, -0X2A28);
    // 0x8017EAAC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8017EAB0: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8017EAB4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017EAB8: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8017EABC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017EAC0: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8017EAC4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017EAC8: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8017EACC: lwc1        $f10, 0x98($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X98);
    // 0x8017EAD0: lwc1        $f6, 0xC4($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0XC4);
    // 0x8017EAD4: lwc1        $f16, 0x9C($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X9C);
    // 0x8017EAD8: lwc1        $f8, 0xC8($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0XC8);
    // 0x8017EADC: mul.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x8017EAE0: lwc1        $f6, 0xA0($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0XA0);
    // 0x8017EAE4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8017EAE8: mul.s       $f4, $f16, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x8017EAEC: lwc1        $f16, 0xCC($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0XCC);
    // 0x8017EAF0: mul.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x8017EAF4: add.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8017EAF8: mul.s       $f4, $f20, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f22.fl);
    // 0x8017EAFC: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8017EB00: jal         0x800E4BE0
    // 0x8017EB04: div.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    func_800E4BE0(rdram, ctx);
        goto after_2;
    // 0x8017EB04: div.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    after_2:
    // 0x8017EB08: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8017EB0C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017EB10: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8017EB14: lwc1        $f10, -0x3E8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X3E8);
    // 0x8017EB18: mul.s       $f16, $f0, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8017EB1C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017EB20: lw          $t0, -0x2E40($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2E40);
    // 0x8017EB24: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8017EB28: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8017EB2C: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8017EB30: div.s       $f8, $f16, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = DIV_S(ctx->f16.fl, ctx->f10.fl);
    // 0x8017EB34: lwc1        $f18, -0x2390($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2390);
    // 0x8017EB38: c.lt.s      $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.fl < ctx->f8.fl;
    // 0x8017EB3C: swc1        $f8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f8.u32l;
    // 0x8017EB40: bc1f        L_8017EBD0
    if (!c1cs) {
        // 0x8017EB44: nop
    
            goto L_8017EBD0;
    }
    // 0x8017EB44: nop

    // 0x8017EB48: lw          $t2, 0x70($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X70);
    // 0x8017EB4C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017EB50: addiu       $t4, $t4, -0x2A28
    ctx->r12 = ADD32(ctx->r12, -0X2A28);
    // 0x8017EB54: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8017EB58: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8017EB5C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8017EB60: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x8017EB64: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8017EB68: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8017EB6C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8017EB70: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8017EB74: lwc1        $f4, 0x94($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X94);
    // 0x8017EB78: lwc1        $f6, 0xC4($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0XC4);
    // 0x8017EB7C: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8017EB80: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017EB84: mul.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8017EB88: nop

    // 0x8017EB8C: mul.s       $f8, $f16, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x8017EB90: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8017EB94: swc1        $f8, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f8.u32l;
    // 0x8017EB98: lwc1        $f18, 0x94($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X94);
    // 0x8017EB9C: lwc1        $f4, 0xC8($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0XC8);
    // 0x8017EBA0: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8017EBA4: nop

    // 0x8017EBA8: mul.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x8017EBAC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017EBB0: swc1        $f10, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f10.u32l;
    // 0x8017EBB4: lwc1        $f18, 0xCC($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0XCC);
    // 0x8017EBB8: lwc1        $f8, 0x94($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X94);
    // 0x8017EBBC: mul.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x8017EBC0: nop

    // 0x8017EBC4: mul.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8017EBC8: b           L_8017EC54
    // 0x8017EBCC: swc1        $f16, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f16.u32l;
        goto L_8017EC54;
    // 0x8017EBCC: swc1        $f16, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f16.u32l;
L_8017EBD0:
    // 0x8017EBD0: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x8017EBD4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017EBD8: addiu       $t8, $t8, -0x2A28
    ctx->r24 = ADD32(ctx->r24, -0X2A28);
    // 0x8017EBDC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8017EBE0: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8017EBE4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017EBE8: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8017EBEC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017EBF0: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8017EBF4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017EBF8: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8017EBFC: lwc1        $f10, 0x94($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X94);
    // 0x8017EC00: lwc1        $f8, 0x98($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X98);
    // 0x8017EC04: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8017EC08: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017EC0C: mul.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8017EC10: nop

    // 0x8017EC14: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8017EC18: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8017EC1C: swc1        $f6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f6.u32l;
    // 0x8017EC20: lwc1        $f16, 0x94($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X94);
    // 0x8017EC24: lwc1        $f10, 0x9C($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X9C);
    // 0x8017EC28: mul.s       $f8, $f16, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x8017EC2C: nop

    // 0x8017EC30: mul.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x8017EC34: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8017EC38: swc1        $f4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f4.u32l;
    // 0x8017EC3C: lwc1        $f16, 0xA0($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0XA0);
    // 0x8017EC40: lwc1        $f6, 0x94($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X94);
    // 0x8017EC44: mul.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x8017EC48: nop

    // 0x8017EC4C: mul.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8017EC50: swc1        $f18, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f18.u32l;
L_8017EC54:
    // 0x8017EC54: lw          $t0, 0x70($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X70);
    // 0x8017EC58: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017EC5C: addiu       $t2, $t2, -0x2A28
    ctx->r10 = ADD32(ctx->r10, -0X2A28);
    // 0x8017EC60: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8017EC64: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8017EC68: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8017EC6C: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x8017EC70: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8017EC74: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8017EC78: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8017EC7C: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x8017EC80: lwc1        $f4, 0x60($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X60);
    // 0x8017EC84: lwc1        $f6, 0x78($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8017EC88: lwc1        $f10, 0x64($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X64);
    // 0x8017EC8C: lwc1        $f8, 0x7C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8017EC90: add.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8017EC94: lwc1        $f6, 0x68($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X68);
    // 0x8017EC98: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x8017EC9C: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8017ECA0: lwc1        $f8, 0x80($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X80);
    // 0x8017ECA4: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x8017ECA8: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8017ECAC: add.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8017ECB0: lwc1        $f16, 0x6C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8017ECB4: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x8017ECB8: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x8017ECBC: add.s       $f18, $f4, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x8017ECC0: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x8017ECC4: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8017ECC8: lwc1        $f8, 0x68($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8017ECCC: lwc1        $f16, 0x64($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8017ECD0: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    // 0x8017ECD4: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8017ECD8: add.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x8017ECDC: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x8017ECE0: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    // 0x8017ECE4: lwc1        $f10, 0x88($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X88);
    // 0x8017ECE8: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x8017ECEC: lwc1        $f8, 0x8C($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X8C);
    // 0x8017ECF0: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x8017ECF4: lwc1        $f4, 0x90($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X90);
    // 0x8017ECF8: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x8017ECFC: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x8017ED00: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x8017ED04: ori         $t5, $t4, 0x100
    ctx->r13 = ctx->r12 | 0X100;
    // 0x8017ED08: jal         0x80187E5C
    // 0x8017ED0C: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
    func_80187E5C_1501A0(rdram, ctx);
        goto after_3;
    // 0x8017ED0C: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
    after_3:
L_8017ED10:
    // 0x8017ED10: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x8017ED14: ldc1        $f20, 0x40($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X40);
    // 0x8017ED18: ldc1        $f22, 0x48($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X48);
    // 0x8017ED1C: jr          $ra
    // 0x8017ED20: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x8017ED20: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_8017ED24_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017ED24: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8017ED28: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8017ED2C: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x8017ED30: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017ED34: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8017ED38: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8017ED3C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8017ED40: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017ED44: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8017ED48: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017ED4C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8017ED50: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017ED54: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8017ED58: lhu         $t8, -0x2A28($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X2A28);
    // 0x8017ED5C: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x8017ED60: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x8017ED64: andi        $t9, $t8, 0x800
    ctx->r25 = ctx->r24 & 0X800;
    // 0x8017ED68: beq         $t9, $zero, L_8017EE8C
    if (ctx->r25 == 0) {
        // 0x8017ED6C: sw          $a3, 0x54($sp)
        MEM_W(0X54, ctx->r29) = ctx->r7;
            goto L_8017EE8C;
    }
    // 0x8017ED6C: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x8017ED70: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017ED74: lw          $t0, -0x2D68($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2D68);
    // 0x8017ED78: bne         $t0, $zero, L_8017EE8C
    if (ctx->r8 != 0) {
        // 0x8017ED7C: nop
    
            goto L_8017EE8C;
    }
    // 0x8017ED7C: nop

    // 0x8017ED80: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017ED84: lhu         $t1, -0x2BA8($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X2BA8);
    // 0x8017ED88: andi        $t2, $t1, 0x4000
    ctx->r10 = ctx->r9 & 0X4000;
    // 0x8017ED8C: bne         $t2, $zero, L_8017EE8C
    if (ctx->r10 != 0) {
        // 0x8017ED90: nop
    
            goto L_8017EE8C;
    }
    // 0x8017ED90: nop

    // 0x8017ED94: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017ED98: addiu       $t3, $t3, -0x2BA8
    ctx->r11 = ADD32(ctx->r11, -0X2BA8);
    // 0x8017ED9C: lw          $t4, 0xC($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XC);
    // 0x8017EDA0: bne         $t4, $zero, L_8017EDD0
    if (ctx->r12 != 0) {
        // 0x8017EDA4: nop
    
            goto L_8017EDD0;
    }
    // 0x8017EDA4: nop

    // 0x8017EDA8: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017EDAC: lw          $t5, -0x2E48($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2E48);
    // 0x8017EDB0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8017EDB4: bne         $t5, $at, L_8017EE8C
    if (ctx->r13 != ctx->r1) {
        // 0x8017EDB8: nop
    
            goto L_8017EE8C;
    }
    // 0x8017EDB8: nop

    // 0x8017EDBC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017EDC0: addiu       $t6, $t6, -0x2BA8
    ctx->r14 = ADD32(ctx->r14, -0X2BA8);
    // 0x8017EDC4: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x8017EDC8: beq         $t7, $zero, L_8017EE8C
    if (ctx->r15 == 0) {
        // 0x8017EDCC: nop
    
            goto L_8017EE8C;
    }
    // 0x8017EDCC: nop

L_8017EDD0:
    // 0x8017EDD0: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x8017EDD4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017EDD8: addiu       $t0, $t0, -0x2A28
    ctx->r8 = ADD32(ctx->r8, -0X2A28);
    // 0x8017EDDC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8017EDE0: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8017EDE4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8017EDE8: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8017EDEC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8017EDF0: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8017EDF4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8017EDF8: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8017EDFC: lwc1        $f4, 0x60($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X60);
    // 0x8017EE00: lwc1        $f6, 0x50($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8017EE04: lwc1        $f10, 0x64($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X64);
    // 0x8017EE08: lwc1        $f16, 0x54($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8017EE0C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8017EE10: lwc1        $f6, 0x68($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X68);
    // 0x8017EE14: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8017EE18: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8017EE1C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8017EE20: lwc1        $f8, 0x58($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8017EE24: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x8017EE28: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x8017EE2C: add.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8017EE30: lwc1        $f18, 0x5C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8017EE34: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x8017EE38: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x8017EE3C: add.s       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x8017EE40: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x8017EE44: lwc1        $f16, 0x60($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8017EE48: lwc1        $f18, 0x64($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8017EE4C: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x8017EE50: add.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8017EE54: add.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x8017EE58: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x8017EE5C: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x8017EE60: lwc1        $f10, 0x88($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X88);
    // 0x8017EE64: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x8017EE68: lwc1        $f16, 0x8C($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X8C);
    // 0x8017EE6C: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    // 0x8017EE70: lwc1        $f4, 0x90($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X90);
    // 0x8017EE74: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x8017EE78: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x8017EE7C: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x8017EE80: ori         $t3, $t2, 0x100
    ctx->r11 = ctx->r10 | 0X100;
    // 0x8017EE84: jal         0x80187E5C
    // 0x8017EE88: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    func_80187E5C_1501A0(rdram, ctx);
        goto after_0;
    // 0x8017EE88: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    after_0:
L_8017EE8C:
    // 0x8017EE8C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8017EE90: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8017EE94: jr          $ra
    // 0x8017EE98: nop

    return;
    // 0x8017EE98: nop

;}
RECOMP_FUNC void func_8017EE9C_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017EE9C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8017EEA0: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x8017EEA4: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x8017EEA8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017EEAC: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8017EEB0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8017EEB4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8017EEB8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017EEBC: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8017EEC0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017EEC4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8017EEC8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017EECC: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8017EED0: lhu         $t8, -0x2A28($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X2A28);
    // 0x8017EED4: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x8017EED8: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x8017EEDC: andi        $t9, $t8, 0x800
    ctx->r25 = ctx->r24 & 0X800;
    // 0x8017EEE0: beq         $t9, $zero, L_8017F100
    if (ctx->r25 == 0) {
        // 0x8017EEE4: sw          $a3, 0x64($sp)
        MEM_W(0X64, ctx->r29) = ctx->r7;
            goto L_8017F100;
    }
    // 0x8017EEE4: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    // 0x8017EEE8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017EEEC: lw          $t0, -0x2D68($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2D68);
    // 0x8017EEF0: bne         $t0, $zero, L_8017F100
    if (ctx->r8 != 0) {
        // 0x8017EEF4: nop
    
            goto L_8017F100;
    }
    // 0x8017EEF4: nop

    // 0x8017EEF8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017EEFC: lhu         $t1, -0x2BA8($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X2BA8);
    // 0x8017EF00: andi        $t2, $t1, 0x4000
    ctx->r10 = ctx->r9 & 0X4000;
    // 0x8017EF04: bne         $t2, $zero, L_8017F100
    if (ctx->r10 != 0) {
        // 0x8017EF08: nop
    
            goto L_8017F100;
    }
    // 0x8017EF08: nop

    // 0x8017EF0C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017EF10: addiu       $t3, $t3, -0x2BA8
    ctx->r11 = ADD32(ctx->r11, -0X2BA8);
    // 0x8017EF14: lw          $t4, 0xC($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XC);
    // 0x8017EF18: bne         $t4, $zero, L_8017EF48
    if (ctx->r12 != 0) {
        // 0x8017EF1C: nop
    
            goto L_8017EF48;
    }
    // 0x8017EF1C: nop

    // 0x8017EF20: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017EF24: lw          $t5, -0x2E48($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2E48);
    // 0x8017EF28: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8017EF2C: bne         $t5, $at, L_8017F100
    if (ctx->r13 != ctx->r1) {
        // 0x8017EF30: nop
    
            goto L_8017F100;
    }
    // 0x8017EF30: nop

    // 0x8017EF34: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017EF38: addiu       $t6, $t6, -0x2BA8
    ctx->r14 = ADD32(ctx->r14, -0X2BA8);
    // 0x8017EF3C: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x8017EF40: beq         $t7, $zero, L_8017F100
    if (ctx->r15 == 0) {
        // 0x8017EF44: nop
    
            goto L_8017F100;
    }
    // 0x8017EF44: nop

L_8017EF48:
    // 0x8017EF48: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x8017EF4C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017EF50: addiu       $t0, $t0, -0x2A28
    ctx->r8 = ADD32(ctx->r8, -0X2A28);
    // 0x8017EF54: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8017EF58: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8017EF5C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8017EF60: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8017EF64: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8017EF68: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8017EF6C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8017EF70: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8017EF74: lwc1        $f4, 0xA4($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0XA4);
    // 0x8017EF78: lwc1        $f6, 0x60($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8017EF7C: lwc1        $f10, 0xB4($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0XB4);
    // 0x8017EF80: lwc1        $f16, 0x64($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8017EF84: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8017EF88: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x8017EF8C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8017EF90: lwc1        $f10, 0xC4($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0XC4);
    // 0x8017EF94: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x8017EF98: lwc1        $f8, 0x68($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8017EF9C: mul.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8017EFA0: add.s       $f10, $f4, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x8017EFA4: lwc1        $f4, 0x60($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X60);
    // 0x8017EFA8: add.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8017EFAC: swc1        $f18, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f18.u32l;
    // 0x8017EFB0: lwc1        $f4, 0xA8($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0XA8);
    // 0x8017EFB4: lwc1        $f18, 0xB8($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0XB8);
    // 0x8017EFB8: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x8017EFBC: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8017EFC0: nop

    // 0x8017EFC4: mul.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x8017EFC8: add.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8017EFCC: lwc1        $f10, 0xC8($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0XC8);
    // 0x8017EFD0: mul.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8017EFD4: add.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8017EFD8: lwc1        $f18, 0x64($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X64);
    // 0x8017EFDC: add.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x8017EFE0: swc1        $f4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f4.u32l;
    // 0x8017EFE4: lwc1        $f18, 0xAC($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0XAC);
    // 0x8017EFE8: lwc1        $f4, 0xBC($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0XBC);
    // 0x8017EFEC: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x8017EFF0: mul.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x8017EFF4: nop

    // 0x8017EFF8: mul.s       $f18, $f4, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x8017EFFC: lwc1        $f4, 0xCC($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0XCC);
    // 0x8017F000: mul.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8017F004: add.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8017F008: lwc1        $f18, 0x68($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X68);
    // 0x8017F00C: add.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x8017F010: lwc1        $f6, 0x6C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8017F014: add.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x8017F018: lwc1        $f10, 0x70($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8017F01C: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
    // 0x8017F020: lwc1        $f8, 0xA4($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0XA4);
    // 0x8017F024: lwc1        $f18, 0xB4($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0XB4);
    // 0x8017F028: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x8017F02C: mul.s       $f16, $f8, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8017F030: nop

    // 0x8017F034: mul.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x8017F038: lwc1        $f18, 0xC4($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0XC4);
    // 0x8017F03C: add.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x8017F040: lwc1        $f16, 0x74($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8017F044: mul.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x8017F048: add.s       $f18, $f8, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8017F04C: lwc1        $f8, 0x60($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X60);
    // 0x8017F050: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x8017F054: swc1        $f4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f4.u32l;
    // 0x8017F058: lwc1        $f8, 0xA8($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0XA8);
    // 0x8017F05C: mul.s       $f18, $f8, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8017F060: lwc1        $f8, 0xB8($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0XB8);
    // 0x8017F064: mul.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8017F068: add.s       $f18, $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x8017F06C: lwc1        $f8, 0xC8($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0XC8);
    // 0x8017F070: mul.s       $f8, $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8017F074: add.s       $f18, $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x8017F078: lwc1        $f8, 0x64($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X64);
    // 0x8017F07C: add.s       $f8, $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x8017F080: swc1        $f8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f8.u32l;
    // 0x8017F084: lwc1        $f18, 0xAC($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0XAC);
    // 0x8017F088: mul.s       $f18, $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x8017F08C: lwc1        $f6, 0xBC($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0XBC);
    // 0x8017F090: mul.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8017F094: add.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8017F098: lwc1        $f18, 0xCC($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0XCC);
    // 0x8017F09C: mul.s       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x8017F0A0: lwc1        $f16, 0x68($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X68);
    // 0x8017F0A4: add.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8017F0A8: add.s       $f10, $f16, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8017F0AC: swc1        $f10, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f10.u32l;
    // 0x8017F0B0: lwc1        $f6, 0x60($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X60);
    // 0x8017F0B4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x8017F0B8: lwc1        $f16, 0x64($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X64);
    // 0x8017F0BC: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x8017F0C0: lwc1        $f18, 0x68($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X68);
    // 0x8017F0C4: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    // 0x8017F0C8: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x8017F0CC: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x8017F0D0: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    // 0x8017F0D4: lwc1        $f6, 0x88($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X88);
    // 0x8017F0D8: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x8017F0DC: lwc1        $f16, 0x8C($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X8C);
    // 0x8017F0E0: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    // 0x8017F0E4: lwc1        $f18, 0x90($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X90);
    // 0x8017F0E8: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    // 0x8017F0EC: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x8017F0F0: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x8017F0F4: ori         $t3, $t2, 0x100
    ctx->r11 = ctx->r10 | 0X100;
    // 0x8017F0F8: jal         0x80187E5C
    // 0x8017F0FC: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    func_80187E5C_1501A0(rdram, ctx);
        goto after_0;
    // 0x8017F0FC: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    after_0:
L_8017F100:
    // 0x8017F100: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8017F104: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x8017F108: jr          $ra
    // 0x8017F10C: nop

    return;
    // 0x8017F10C: nop

;}
RECOMP_FUNC void func_8017F110_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017F110: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x8017F114: sw          $a0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r4;
    // 0x8017F118: lw          $t6, 0x88($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X88);
    // 0x8017F11C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017F120: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8017F124: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8017F128: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8017F12C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017F130: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8017F134: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017F138: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8017F13C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017F140: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8017F144: lhu         $t8, -0x2A28($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X2A28);
    // 0x8017F148: sw          $a1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r5;
    // 0x8017F14C: sw          $a2, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r6;
    // 0x8017F150: andi        $t9, $t8, 0x800
    ctx->r25 = ctx->r24 & 0X800;
    // 0x8017F154: sw          $a3, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r7;
    // 0x8017F158: sdc1        $f22, 0x48($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X48, ctx->r29);
    // 0x8017F15C: beq         $t9, $zero, L_8017F40C
    if (ctx->r25 == 0) {
        // 0x8017F160: sdc1        $f20, 0x40($sp)
        CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X40, ctx->r29);
            goto L_8017F40C;
    }
    // 0x8017F160: sdc1        $f20, 0x40($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X40, ctx->r29);
    // 0x8017F164: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017F168: lw          $t0, -0x2D68($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2D68);
    // 0x8017F16C: bne         $t0, $zero, L_8017F40C
    if (ctx->r8 != 0) {
        // 0x8017F170: nop
    
            goto L_8017F40C;
    }
    // 0x8017F170: nop

    // 0x8017F174: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017F178: lhu         $t1, -0x2BA8($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X2BA8);
    // 0x8017F17C: andi        $t2, $t1, 0x4000
    ctx->r10 = ctx->r9 & 0X4000;
    // 0x8017F180: bne         $t2, $zero, L_8017F40C
    if (ctx->r10 != 0) {
        // 0x8017F184: nop
    
            goto L_8017F40C;
    }
    // 0x8017F184: nop

    // 0x8017F188: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017F18C: addiu       $t3, $t3, -0x2BA8
    ctx->r11 = ADD32(ctx->r11, -0X2BA8);
    // 0x8017F190: lw          $t4, 0xC($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XC);
    // 0x8017F194: bne         $t4, $zero, L_8017F1C4
    if (ctx->r12 != 0) {
        // 0x8017F198: nop
    
            goto L_8017F1C4;
    }
    // 0x8017F198: nop

    // 0x8017F19C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017F1A0: lw          $t5, -0x2E48($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2E48);
    // 0x8017F1A4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8017F1A8: bne         $t5, $at, L_8017F40C
    if (ctx->r13 != ctx->r1) {
        // 0x8017F1AC: nop
    
            goto L_8017F40C;
    }
    // 0x8017F1AC: nop

    // 0x8017F1B0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017F1B4: addiu       $t6, $t6, -0x2BA8
    ctx->r14 = ADD32(ctx->r14, -0X2BA8);
    // 0x8017F1B8: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x8017F1BC: beq         $t7, $zero, L_8017F40C
    if (ctx->r15 == 0) {
        // 0x8017F1C0: nop
    
            goto L_8017F40C;
    }
    // 0x8017F1C0: nop

L_8017F1C4:
    // 0x8017F1C4: lw          $t8, 0x88($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X88);
    // 0x8017F1C8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017F1CC: addiu       $t0, $t0, -0x2A28
    ctx->r8 = ADD32(ctx->r8, -0X2A28);
    // 0x8017F1D0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8017F1D4: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8017F1D8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8017F1DC: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8017F1E0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8017F1E4: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8017F1E8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8017F1EC: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8017F1F0: lwc1        $f4, 0x98($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X98);
    // 0x8017F1F4: swc1        $f4, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f4.u32l;
    // 0x8017F1F8: lwc1        $f6, 0x9C($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X9C);
    // 0x8017F1FC: swc1        $f6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f6.u32l;
    // 0x8017F200: lwc1        $f8, 0xA0($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0XA0);
    // 0x8017F204: swc1        $f8, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f8.u32l;
    // 0x8017F208: lwc1        $f10, 0xC4($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0XC4);
    // 0x8017F20C: swc1        $f10, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f10.u32l;
    // 0x8017F210: lwc1        $f16, 0xC8($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0XC8);
    // 0x8017F214: mul.s       $f10, $f4, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x8017F218: swc1        $f16, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f16.u32l;
    // 0x8017F21C: mul.s       $f16, $f6, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x8017F220: lwc1        $f18, 0xCC($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0XCC);
    // 0x8017F224: mul.s       $f4, $f8, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x8017F228: swc1        $f18, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f18.u32l;
    // 0x8017F22C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8017F230: jal         0x800D68E0
    // 0x8017F234: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x8017F234: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    after_0:
    // 0x8017F238: lwc1        $f6, 0x68($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8017F23C: lwc1        $f16, 0x64($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8017F240: lwc1        $f4, 0x60($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8017F244: mul.s       $f10, $f6, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x8017F248: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x8017F24C: mul.s       $f8, $f16, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8017F250: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8017F254: mul.s       $f6, $f4, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x8017F258: jal         0x800D68E0
    // 0x8017F25C: add.s       $f12, $f18, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x8017F25C: add.s       $f12, $f18, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f6.fl;
    after_1:
    // 0x8017F260: lwc1        $f16, 0x74($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8017F264: lwc1        $f10, 0x68($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8017F268: lwc1        $f4, 0x70($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8017F26C: lwc1        $f18, 0x64($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8017F270: mul.s       $f8, $f16, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x8017F274: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8017F278: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8017F27C: mul.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x8017F280: lwc1        $f4, 0x60($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8017F284: mul.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8017F288: add.s       $f16, $f8, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8017F28C: mul.s       $f6, $f20, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f22.fl);
    // 0x8017F290: add.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8017F294: jal         0x800E4BE0
    // 0x8017F298: div.s       $f12, $f8, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = DIV_S(ctx->f8.fl, ctx->f6.fl);
    func_800E4BE0(rdram, ctx);
        goto after_2;
    // 0x8017F298: div.s       $f12, $f8, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = DIV_S(ctx->f8.fl, ctx->f6.fl);
    after_2:
    // 0x8017F29C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8017F2A0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017F2A4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8017F2A8: lwc1        $f16, -0x3E4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X3E4);
    // 0x8017F2AC: mul.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8017F2B0: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8017F2B4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8017F2B8: div.s       $f18, $f4, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f4.fl, ctx->f16.fl);
    // 0x8017F2BC: c.lt.s      $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f8.fl < ctx->f18.fl;
    // 0x8017F2C0: swc1        $f18, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f18.u32l;
    // 0x8017F2C4: bc1t        L_8017F40C
    if (c1cs) {
        // 0x8017F2C8: nop
    
            goto L_8017F40C;
    }
    // 0x8017F2C8: nop

    // 0x8017F2CC: lw          $t2, 0x88($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X88);
    // 0x8017F2D0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017F2D4: addiu       $t4, $t4, -0x2A28
    ctx->r12 = ADD32(ctx->r12, -0X2A28);
    // 0x8017F2D8: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8017F2DC: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8017F2E0: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8017F2E4: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x8017F2E8: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8017F2EC: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8017F2F0: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8017F2F4: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8017F2F8: lwc1        $f6, 0xA4($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0XA4);
    // 0x8017F2FC: lwc1        $f10, 0x90($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X90);
    // 0x8017F300: lwc1        $f16, 0xB4($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0XB4);
    // 0x8017F304: lwc1        $f18, 0x94($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8017F308: mul.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8017F30C: lw          $a0, 0x8C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X8C);
    // 0x8017F310: mul.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8017F314: lwc1        $f16, 0xC4($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0XC4);
    // 0x8017F318: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8017F31C: lwc1        $f4, 0x98($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X98);
    // 0x8017F320: mul.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x8017F324: add.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8017F328: lwc1        $f6, 0x60($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X60);
    // 0x8017F32C: add.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x8017F330: swc1        $f8, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f8.u32l;
    // 0x8017F334: lwc1        $f6, 0xA8($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0XA8);
    // 0x8017F338: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8017F33C: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8017F340: lwc1        $f6, 0xB8($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0XB8);
    // 0x8017F344: mul.s       $f6, $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x8017F348: add.s       $f16, $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x8017F34C: lwc1        $f6, 0xC8($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0XC8);
    // 0x8017F350: mul.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x8017F354: add.s       $f16, $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x8017F358: lwc1        $f6, 0x64($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X64);
    // 0x8017F35C: add.s       $f6, $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x8017F360: swc1        $f6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f6.u32l;
    // 0x8017F364: lwc1        $f16, 0xAC($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0XAC);
    // 0x8017F368: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8017F36C: mul.s       $f16, $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x8017F370: lwc1        $f10, 0xBC($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0XBC);
    // 0x8017F374: mul.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8017F378: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x8017F37C: lwc1        $f16, 0xCC($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0XCC);
    // 0x8017F380: mul.s       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x8017F384: lwc1        $f4, 0x68($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X68);
    // 0x8017F388: add.s       $f16, $f18, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x8017F38C: add.s       $f18, $f4, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x8017F390: swc1        $f18, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f18.u32l;
    // 0x8017F394: lwc1        $f10, 0x60($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X60);
    // 0x8017F398: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x8017F39C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8017F3A0: lwc1        $f4, 0x64($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X64);
    // 0x8017F3A4: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x8017F3A8: lwc1        $f16, 0x68($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0X68);
    // 0x8017F3AC: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x8017F3B0: lwc1        $f6, 0x60($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X60);
    // 0x8017F3B4: lwc1        $f8, 0xC4($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0XC4);
    // 0x8017F3B8: add.s       $f18, $f8, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8017F3BC: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    // 0x8017F3C0: lwc1        $f4, 0x64($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X64);
    // 0x8017F3C4: lwc1        $f10, 0xC8($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0XC8);
    // 0x8017F3C8: add.s       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8017F3CC: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x8017F3D0: lwc1        $f6, 0x68($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X68);
    // 0x8017F3D4: lwc1        $f8, 0xCC($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0XCC);
    // 0x8017F3D8: add.s       $f18, $f8, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8017F3DC: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    // 0x8017F3E0: lwc1        $f10, 0x88($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X88);
    // 0x8017F3E4: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x8017F3E8: lwc1        $f4, 0x8C($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X8C);
    // 0x8017F3EC: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x8017F3F0: lwc1        $f16, 0x90($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0X90);
    // 0x8017F3F4: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    // 0x8017F3F8: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x8017F3FC: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x8017F400: ori         $t7, $t6, 0x100
    ctx->r15 = ctx->r14 | 0X100;
    // 0x8017F404: jal         0x80187E5C
    // 0x8017F408: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    func_80187E5C_1501A0(rdram, ctx);
        goto after_3;
    // 0x8017F408: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    after_3:
L_8017F40C:
    // 0x8017F40C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x8017F410: ldc1        $f20, 0x40($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X40);
    // 0x8017F414: ldc1        $f22, 0x48($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X48);
    // 0x8017F418: jr          $ra
    // 0x8017F41C: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x8017F41C: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void func_8017F420_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017F420: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8017F424: swc1        $f12, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f12.u32l;
    // 0x8017F428: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017F42C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8017F430: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8017F434: swc1        $f14, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f14.u32l;
    // 0x8017F438: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x8017F43C: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8017F440: addiu       $t6, $t6, -0x4198
    ctx->r14 = ADD32(ctx->r14, -0X4198);
    // 0x8017F444: lwc1        $f6, 0x0($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X0);
    // 0x8017F448: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8017F44C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017F450: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x8017F454: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8017F458: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017F45C: addiu       $t8, $t8, -0x4198
    ctx->r24 = ADD32(ctx->r24, -0X4198);
    // 0x8017F460: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017F464: swc1        $f8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f8.u32l;
    // 0x8017F468: lwc1        $f16, 0x4($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X4);
    // 0x8017F46C: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8017F470: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x8017F474: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017F478: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8017F47C: addiu       $t0, $t0, -0x4198
    ctx->r8 = ADD32(ctx->r8, -0X4198);
    // 0x8017F480: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017F484: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x8017F488: swc1        $f18, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f18.u32l;
    // 0x8017F48C: lwc1        $f6, 0x8($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X8);
    // 0x8017F490: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8017F494: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017F498: addiu       $t2, $t2, -0x4198
    ctx->r10 = ADD32(ctx->r10, -0X4198);
    // 0x8017F49C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8017F4A0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017F4A4: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x8017F4A8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017F4AC: swc1        $f8, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f8.u32l;
    // 0x8017F4B0: lwc1        $f16, 0x0($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X0);
    // 0x8017F4B4: lwc1        $f10, 0xC($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0XC);
    // 0x8017F4B8: addiu       $t4, $t4, -0x4198
    ctx->r12 = ADD32(ctx->r12, -0X4198);
    // 0x8017F4BC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017F4C0: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8017F4C4: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x8017F4C8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017F4CC: addiu       $t6, $t6, -0x4198
    ctx->r14 = ADD32(ctx->r14, -0X4198);
    // 0x8017F4D0: swc1        $f18, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f18.u32l;
    // 0x8017F4D4: lwc1        $f6, 0x4($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X4);
    // 0x8017F4D8: lwc1        $f4, 0x10($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X10);
    // 0x8017F4DC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017F4E0: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x8017F4E4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8017F4E8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017F4EC: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x8017F4F0: swc1        $f8, 0x10($t5)
    MEM_W(0X10, ctx->r13) = ctx->f8.u32l;
    // 0x8017F4F4: lwc1        $f16, 0x8($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X8);
    // 0x8017F4F8: lwc1        $f10, 0x14($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X14);
    // 0x8017F4FC: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8017F500: swc1        $f18, 0x14($t7)
    MEM_W(0X14, ctx->r15) = ctx->f18.u32l;
    // 0x8017F504: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    // 0x8017F508: lwc1        $f8, 0x4($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X4);
    // 0x8017F50C: lwc1        $f18, 0x8($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X8);
    // 0x8017F510: mul.s       $f6, $f4, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x8017F514: nop

    // 0x8017F518: mul.s       $f10, $f8, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x8017F51C: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8017F520: mul.s       $f4, $f18, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x8017F524: jal         0x800D68E0
    // 0x8017F528: add.s       $f12, $f4, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f16.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x8017F528: add.s       $f12, $f4, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f16.fl;
    after_0:
    // 0x8017F52C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017F530: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x8017F534: lwc1        $f8, 0xC($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0XC);
    // 0x8017F538: lwc1        $f10, 0x10($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X10);
    // 0x8017F53C: lwc1        $f16, 0x14($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X14);
    // 0x8017F540: mul.s       $f6, $f8, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x8017F544: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x8017F548: mul.s       $f18, $f10, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x8017F54C: add.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x8017F550: mul.s       $f8, $f16, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8017F554: jal         0x800D68E0
    // 0x8017F558: add.s       $f12, $f8, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x8017F558: add.s       $f12, $f8, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f4.fl;
    after_1:
    // 0x8017F55C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017F560: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x8017F564: lwc1        $f10, 0x0($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8017F568: lwc1        $f6, 0xC($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0XC);
    // 0x8017F56C: lwc1        $f16, 0x4($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X4);
    // 0x8017F570: lwc1        $f8, 0x10($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X10);
    // 0x8017F574: mul.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x8017F578: lwc1        $f6, 0x8($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X8);
    // 0x8017F57C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8017F580: mul.s       $f4, $f16, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x8017F584: lwc1        $f16, 0x14($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X14);
    // 0x8017F588: mul.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x8017F58C: add.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8017F590: mul.s       $f4, $f20, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f22.fl);
    // 0x8017F594: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8017F598: jal         0x800E4BE0
    // 0x8017F59C: div.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    func_800E4BE0(rdram, ctx);
        goto after_2;
    // 0x8017F59C: div.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    after_2:
    // 0x8017F5A0: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8017F5A4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017F5A8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8017F5AC: lwc1        $f10, -0x3E0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X3E0);
    // 0x8017F5B0: mul.s       $f16, $f0, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8017F5B4: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8017F5B8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8017F5BC: div.s       $f8, $f16, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = DIV_S(ctx->f16.fl, ctx->f10.fl);
    // 0x8017F5C0: c.lt.s      $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f8.fl < ctx->f18.fl;
    // 0x8017F5C4: nop

    // 0x8017F5C8: bc1f        L_8017F5D8
    if (!c1cs) {
        // 0x8017F5CC: nop
    
            goto L_8017F5D8;
    }
    // 0x8017F5CC: nop

    // 0x8017F5D0: b           L_8017F5DC
    // 0x8017F5D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8017F5DC;
    // 0x8017F5D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8017F5D8:
    // 0x8017F5D8: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
L_8017F5DC:
    // 0x8017F5DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8017F5E0: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8017F5E4: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x8017F5E8: jr          $ra
    // 0x8017F5EC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8017F5EC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8017F5F0_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017F5F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017F5F4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8017F5F8: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8017F5FC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8017F600: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017F604: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8017F608: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8017F60C: lwc1        $f4, 0x0($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X0);
    // 0x8017F610: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8017F614: lwc1        $f8, 0x0($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X0);
    // 0x8017F618: mul.s       $f6, $f4, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x8017F61C: lwc1        $f18, 0x0($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X0);
    // 0x8017F620: mul.s       $f10, $f8, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x8017F624: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8017F628: mul.s       $f4, $f18, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x8017F62C: jal         0x800D68E0
    // 0x8017F630: add.s       $f12, $f4, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f16.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x8017F630: add.s       $f12, $f4, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f16.fl;
    after_0:
    // 0x8017F634: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8017F638: lwc1        $f8, 0x1C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8017F63C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8017F640: nop

    // 0x8017F644: c.eq.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl == ctx->f6.fl;
    // 0x8017F648: nop

    // 0x8017F64C: bc1t        L_8017F69C
    if (c1cs) {
        // 0x8017F650: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8017F69C;
    }
    // 0x8017F650: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017F654: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017F658: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8017F65C: div.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8017F660: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    // 0x8017F664: lwc1        $f4, 0x0($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X0);
    // 0x8017F668: mul.s       $f16, $f4, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x8017F66C: swc1        $f16, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f16.u32l;
    // 0x8017F670: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8017F674: lwc1        $f10, 0x1C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8017F678: lwc1        $f6, 0x0($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8017F67C: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8017F680: swc1        $f8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f8.u32l;
    // 0x8017F684: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8017F688: lwc1        $f18, 0x1C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8017F68C: lwc1        $f4, 0x0($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X0);
    // 0x8017F690: mul.s       $f16, $f4, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x8017F694: b           L_8017F6C4
    // 0x8017F698: swc1        $f16, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f16.u32l;
        goto L_8017F6C4;
    // 0x8017F698: swc1        $f16, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f16.u32l;
L_8017F69C:
    // 0x8017F69C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017F6A0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017F6A4: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8017F6A8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8017F6AC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8017F6B0: swc1        $f6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f6.u32l;
    // 0x8017F6B4: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8017F6B8: swc1        $f10, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f10.u32l;
    // 0x8017F6BC: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8017F6C0: swc1        $f8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f8.u32l;
L_8017F6C4:
    // 0x8017F6C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017F6C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017F6CC: jr          $ra
    // 0x8017F6D0: nop

    return;
    // 0x8017F6D0: nop

;}
RECOMP_FUNC void func_8017F6D4_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017F6D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017F6D8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8017F6DC: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8017F6E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017F6E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8017F6E8: sltiu       $at, $t6, 0x5
    ctx->r1 = ctx->r14 < 0X5 ? 1 : 0;
    // 0x8017F6EC: beq         $at, $zero, L_8017FA28
    if (ctx->r1 == 0) {
        // 0x8017F6F0: nop
    
            goto L_8017FA28;
    }
    // 0x8017F6F0: nop

    // 0x8017F6F4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8017F6F8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8017F6FC: addu        $at, $at, $t6
    gpr jr_addend_8017F704 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8017F700: lw          $t6, -0x3DC($at)
    ctx->r14 = ADD32(ctx->r1, -0X3DC);
    // 0x8017F704: jr          $t6
    // 0x8017F708: nop

    switch (jr_addend_8017F704 >> 2) {
        case 0: goto L_8017F70C; break;
        case 1: goto L_8017F74C; break;
        case 2: goto L_8017F804; break;
        case 3: goto L_8017F8BC; break;
        case 4: goto L_8017F974; break;
        default: switch_error(__func__, 0x8017F704, 0x8019FC24);
    }
    // 0x8017F708: nop

L_8017F70C:
    // 0x8017F70C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017F710: lwc1        $f4, -0x2BE0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2BE0);
    // 0x8017F714: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017F718: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x8017F71C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017F720: swc1        $f4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f4.u32l;
    // 0x8017F724: lwc1        $f6, -0x2BDC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2BDC);
    // 0x8017F728: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017F72C: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x8017F730: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017F734: swc1        $f6, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f6.u32l;
    // 0x8017F738: lwc1        $f8, -0x2BD8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2BD8);
    // 0x8017F73C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017F740: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x8017F744: b           L_8017FA28
    // 0x8017F748: swc1        $f8, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f8.u32l;
        goto L_8017FA28;
    // 0x8017F748: swc1        $f8, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f8.u32l;
L_8017F74C:
    // 0x8017F74C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017F750: addiu       $t0, $t0, -0x4198
    ctx->r8 = ADD32(ctx->r8, -0X4198);
    // 0x8017F754: lui         $at, 0x41B8
    ctx->r1 = S32(0X41B8 << 16);
    // 0x8017F758: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8017F75C: lwc1        $f10, 0x30($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X30);
    // 0x8017F760: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017F764: lwc1        $f4, -0x2E30($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x8017F768: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8017F76C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017F770: lwc1        $f8, -0x2BE0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2BE0);
    // 0x8017F774: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017F778: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x8017F77C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017F780: addiu       $t2, $t2, -0x4198
    ctx->r10 = ADD32(ctx->r10, -0X4198);
    // 0x8017F784: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8017F788: lui         $at, 0x41B8
    ctx->r1 = S32(0X41B8 << 16);
    // 0x8017F78C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8017F790: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017F794: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017F798: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x8017F79C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017F7A0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8017F7A4: addiu       $t4, $t4, -0x4198
    ctx->r12 = ADD32(ctx->r12, -0X4198);
    // 0x8017F7A8: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017F7AC: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x8017F7B0: swc1        $f10, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f10.u32l;
    // 0x8017F7B4: lwc1        $f16, 0x34($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X34);
    // 0x8017F7B8: lwc1        $f6, -0x2E30($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x8017F7BC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017F7C0: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8017F7C4: lwc1        $f10, -0x2BDC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2BDC);
    // 0x8017F7C8: lui         $at, 0x41B8
    ctx->r1 = S32(0X41B8 << 16);
    // 0x8017F7CC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8017F7D0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017F7D4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017F7D8: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8017F7DC: swc1        $f16, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->f16.u32l;
    // 0x8017F7E0: lwc1        $f18, 0x38($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X38);
    // 0x8017F7E4: lwc1        $f8, -0x2E30($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x8017F7E8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017F7EC: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8017F7F0: lwc1        $f16, -0x2BD8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2BD8);
    // 0x8017F7F4: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8017F7F8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8017F7FC: b           L_8017FA28
    // 0x8017F800: swc1        $f18, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->f18.u32l;
        goto L_8017FA28;
    // 0x8017F800: swc1        $f18, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->f18.u32l;
L_8017F804:
    // 0x8017F804: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017F808: addiu       $t6, $t6, -0x4198
    ctx->r14 = ADD32(ctx->r14, -0X4198);
    // 0x8017F80C: lui         $at, 0xC1B8
    ctx->r1 = S32(0XC1B8 << 16);
    // 0x8017F810: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017F814: lwc1        $f4, 0x30($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X30);
    // 0x8017F818: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017F81C: lwc1        $f10, -0x2E30($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x8017F820: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8017F824: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017F828: lwc1        $f18, -0x2BE0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2BE0);
    // 0x8017F82C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017F830: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x8017F834: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017F838: addiu       $t8, $t8, -0x4198
    ctx->r24 = ADD32(ctx->r24, -0X4198);
    // 0x8017F83C: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8017F840: lui         $at, 0xC1B8
    ctx->r1 = S32(0XC1B8 << 16);
    // 0x8017F844: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8017F848: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017F84C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017F850: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x8017F854: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017F858: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8017F85C: addiu       $t0, $t0, -0x4198
    ctx->r8 = ADD32(ctx->r8, -0X4198);
    // 0x8017F860: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017F864: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x8017F868: swc1        $f4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f4.u32l;
    // 0x8017F86C: lwc1        $f6, 0x34($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X34);
    // 0x8017F870: lwc1        $f16, -0x2E30($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x8017F874: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017F878: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8017F87C: lwc1        $f4, -0x2BDC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2BDC);
    // 0x8017F880: lui         $at, 0xC1B8
    ctx->r1 = S32(0XC1B8 << 16);
    // 0x8017F884: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8017F888: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017F88C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017F890: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8017F894: swc1        $f6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f6.u32l;
    // 0x8017F898: lwc1        $f8, 0x38($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X38);
    // 0x8017F89C: lwc1        $f18, -0x2E30($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x8017F8A0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017F8A4: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8017F8A8: lwc1        $f6, -0x2BD8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2BD8);
    // 0x8017F8AC: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8017F8B0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8017F8B4: b           L_8017FA28
    // 0x8017F8B8: swc1        $f8, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f8.u32l;
        goto L_8017FA28;
    // 0x8017F8B8: swc1        $f8, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f8.u32l;
L_8017F8BC:
    // 0x8017F8BC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017F8C0: addiu       $t2, $t2, -0x4198
    ctx->r10 = ADD32(ctx->r10, -0X4198);
    // 0x8017F8C4: lui         $at, 0x41A8
    ctx->r1 = S32(0X41A8 << 16);
    // 0x8017F8C8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8017F8CC: lwc1        $f10, 0x40($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X40);
    // 0x8017F8D0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017F8D4: lwc1        $f4, -0x2E30($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x8017F8D8: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8017F8DC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017F8E0: lwc1        $f8, -0x2BE0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2BE0);
    // 0x8017F8E4: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017F8E8: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x8017F8EC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017F8F0: addiu       $t4, $t4, -0x4198
    ctx->r12 = ADD32(ctx->r12, -0X4198);
    // 0x8017F8F4: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8017F8F8: lui         $at, 0x41A8
    ctx->r1 = S32(0X41A8 << 16);
    // 0x8017F8FC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8017F900: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017F904: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017F908: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x8017F90C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017F910: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8017F914: addiu       $t6, $t6, -0x4198
    ctx->r14 = ADD32(ctx->r14, -0X4198);
    // 0x8017F918: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017F91C: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x8017F920: swc1        $f10, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f10.u32l;
    // 0x8017F924: lwc1        $f16, 0x44($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X44);
    // 0x8017F928: lwc1        $f6, -0x2E30($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x8017F92C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017F930: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8017F934: lwc1        $f10, -0x2BDC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2BDC);
    // 0x8017F938: lui         $at, 0x41A8
    ctx->r1 = S32(0X41A8 << 16);
    // 0x8017F93C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8017F940: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017F944: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017F948: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8017F94C: swc1        $f16, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->f16.u32l;
    // 0x8017F950: lwc1        $f18, 0x48($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X48);
    // 0x8017F954: lwc1        $f8, -0x2E30($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x8017F958: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017F95C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8017F960: lwc1        $f16, -0x2BD8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2BD8);
    // 0x8017F964: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8017F968: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8017F96C: b           L_8017FA28
    // 0x8017F970: swc1        $f18, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->f18.u32l;
        goto L_8017FA28;
    // 0x8017F970: swc1        $f18, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->f18.u32l;
L_8017F974:
    // 0x8017F974: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017F978: addiu       $t8, $t8, -0x4198
    ctx->r24 = ADD32(ctx->r24, -0X4198);
    // 0x8017F97C: lui         $at, 0xC1A8
    ctx->r1 = S32(0XC1A8 << 16);
    // 0x8017F980: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017F984: lwc1        $f4, 0x40($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X40);
    // 0x8017F988: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017F98C: lwc1        $f10, -0x2E30($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x8017F990: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8017F994: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017F998: lwc1        $f18, -0x2BE0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2BE0);
    // 0x8017F99C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017F9A0: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x8017F9A4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017F9A8: addiu       $t0, $t0, -0x4198
    ctx->r8 = ADD32(ctx->r8, -0X4198);
    // 0x8017F9AC: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8017F9B0: lui         $at, 0xC1A8
    ctx->r1 = S32(0XC1A8 << 16);
    // 0x8017F9B4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8017F9B8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017F9BC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017F9C0: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x8017F9C4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017F9C8: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8017F9CC: addiu       $t2, $t2, -0x4198
    ctx->r10 = ADD32(ctx->r10, -0X4198);
    // 0x8017F9D0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017F9D4: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x8017F9D8: swc1        $f4, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f4.u32l;
    // 0x8017F9DC: lwc1        $f6, 0x44($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X44);
    // 0x8017F9E0: lwc1        $f16, -0x2E30($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x8017F9E4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017F9E8: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8017F9EC: lwc1        $f4, -0x2BDC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2BDC);
    // 0x8017F9F0: lui         $at, 0xC1A8
    ctx->r1 = S32(0XC1A8 << 16);
    // 0x8017F9F4: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8017F9F8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017F9FC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017FA00: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8017FA04: swc1        $f6, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->f6.u32l;
    // 0x8017FA08: lwc1        $f8, 0x48($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X48);
    // 0x8017FA0C: lwc1        $f18, -0x2E30($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x8017FA10: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017FA14: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8017FA18: lwc1        $f6, -0x2BD8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2BD8);
    // 0x8017FA1C: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8017FA20: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8017FA24: swc1        $f8, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f8.u32l;
L_8017FA28:
    // 0x8017FA28: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x8017FA2C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017FA30: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017FA34: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8017FA38: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8017FA3C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8017FA40: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x8017FA44: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8017FA48: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8017FA4C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8017FA50: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8017FA54: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x8017FA58: lwc1        $f10, 0x0($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X0);
    // 0x8017FA5C: lwc1        $f16, -0x29C8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X29C8);
    // 0x8017FA60: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017FA64: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017FA68: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8017FA6C: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x8017FA70: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017FA74: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x8017FA78: swc1        $f18, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f18.u32l;
    // 0x8017FA7C: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8017FA80: lwc1        $f4, 0x4($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X4);
    // 0x8017FA84: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017FA88: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8017FA8C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8017FA90: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8017FA94: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8017FA98: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8017FA9C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8017FAA0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8017FAA4: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8017FAA8: lwc1        $f6, -0x29C4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X29C4);
    // 0x8017FAAC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017FAB0: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x8017FAB4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8017FAB8: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    // 0x8017FABC: addiu       $a1, $t3, 0x4
    ctx->r5 = ADD32(ctx->r11, 0X4);
    // 0x8017FAC0: addiu       $a2, $t3, 0x8
    ctx->r6 = ADD32(ctx->r11, 0X8);
    // 0x8017FAC4: swc1        $f8, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f8.u32l;
    // 0x8017FAC8: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8017FACC: lwc1        $f10, 0x8($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X8);
    // 0x8017FAD0: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8017FAD4: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8017FAD8: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8017FADC: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x8017FAE0: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8017FAE4: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8017FAE8: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8017FAEC: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x8017FAF0: lwc1        $f16, -0x29C0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X29C0);
    // 0x8017FAF4: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8017FAF8: jal         0x8017F5F0
    // 0x8017FAFC: swc1        $f18, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f18.u32l;
    func_8017F5F0_1501A0(rdram, ctx);
        goto after_0;
    // 0x8017FAFC: swc1        $f18, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f18.u32l;
    after_0:
    // 0x8017FB00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017FB04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017FB08: jr          $ra
    // 0x8017FB0C: nop

    return;
    // 0x8017FB0C: nop

;}
RECOMP_FUNC void func_8017FB10_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017FB10: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8017FB14: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8017FB18: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8017FB1C: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x8017FB20: sll         $t0, $a0, 2
    ctx->r8 = S32(ctx->r4 << 2);
    // 0x8017FB24: addu        $t0, $t0, $a0
    ctx->r8 = ADD32(ctx->r8, ctx->r4);
    // 0x8017FB28: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8017FB2C: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8017FB30: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8017FB34: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017FB38: addiu       $t7, $t7, -0x2A28
    ctx->r15 = ADD32(ctx->r15, -0X2A28);
    // 0x8017FB3C: subu        $t0, $t0, $a0
    ctx->r8 = SUB32(ctx->r8, ctx->r4);
    // 0x8017FB40: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8017FB44: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8017FB48: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8017FB4C: addu        $t0, $t0, $a0
    ctx->r8 = ADD32(ctx->r8, ctx->r4);
    // 0x8017FB50: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8017FB54: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8017FB58: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8017FB5C: addu        $t1, $t0, $t7
    ctx->r9 = ADD32(ctx->r8, ctx->r15);
    // 0x8017FB60: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8017FB64: lw          $t2, 0x4C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4C);
    // 0x8017FB68: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x8017FB6C: lw          $t9, 0x58($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X58);
    // 0x8017FB70: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8017FB74: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8017FB78: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8017FB7C: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8017FB80: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8017FB84: addu        $t4, $t9, $t3
    ctx->r12 = ADD32(ctx->r25, ctx->r11);
    // 0x8017FB88: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x8017FB8C: lw          $t0, 0x24($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X24);
    // 0x8017FB90: sltu        $at, $t5, $t0
    ctx->r1 = ctx->r13 < ctx->r8 ? 1 : 0;
    // 0x8017FB94: beq         $at, $zero, L_8017FCE0
    if (ctx->r1 == 0) {
        // 0x8017FB98: nop
    
            goto L_8017FCE0;
    }
    // 0x8017FB98: nop

L_8017FB9C:
    // 0x8017FB9C: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x8017FBA0: addu        $t1, $t1, $a0
    ctx->r9 = ADD32(ctx->r9, ctx->r4);
    // 0x8017FBA4: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8017FBA8: subu        $t1, $t1, $a0
    ctx->r9 = SUB32(ctx->r9, ctx->r4);
    // 0x8017FBAC: sll         $t4, $a0, 2
    ctx->r12 = S32(ctx->r4 << 2);
    // 0x8017FBB0: addu        $t4, $t4, $a0
    ctx->r12 = ADD32(ctx->r12, ctx->r4);
    // 0x8017FBB4: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8017FBB8: addu        $t1, $t1, $a0
    ctx->r9 = ADD32(ctx->r9, ctx->r4);
    // 0x8017FBBC: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8017FBC0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017FBC4: addiu       $t2, $t2, -0x2A28
    ctx->r10 = ADD32(ctx->r10, -0X2A28);
    // 0x8017FBC8: subu        $t4, $t4, $a0
    ctx->r12 = SUB32(ctx->r12, ctx->r4);
    // 0x8017FBCC: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8017FBD0: addu        $t9, $t1, $t2
    ctx->r25 = ADD32(ctx->r9, ctx->r10);
    // 0x8017FBD4: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8017FBD8: addu        $t4, $t4, $a0
    ctx->r12 = ADD32(ctx->r12, ctx->r4);
    // 0x8017FBDC: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x8017FBE0: addu        $t1, $t1, $a0
    ctx->r9 = ADD32(ctx->r9, ctx->r4);
    // 0x8017FBE4: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8017FBE8: addu        $t6, $t4, $t2
    ctx->r14 = ADD32(ctx->r12, ctx->r10);
    // 0x8017FBEC: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8017FBF0: lw          $t7, 0x4C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4C);
    // 0x8017FBF4: subu        $t1, $t1, $a0
    ctx->r9 = SUB32(ctx->r9, ctx->r4);
    // 0x8017FBF8: lw          $t3, 0x58($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X58);
    // 0x8017FBFC: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8017FC00: addu        $t1, $t1, $a0
    ctx->r9 = ADD32(ctx->r9, ctx->r4);
    // 0x8017FC04: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8017FC08: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8017FC0C: addu        $t9, $t1, $t2
    ctx->r25 = ADD32(ctx->r9, ctx->r10);
    // 0x8017FC10: addu        $t5, $t3, $t8
    ctx->r13 = ADD32(ctx->r11, ctx->r24);
    // 0x8017FC14: lhu         $t0, 0x0($t5)
    ctx->r8 = MEM_HU(ctx->r13, 0X0);
    // 0x8017FC18: lw          $t4, 0x24($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X24);
    // 0x8017FC1C: sltu        $at, $t0, $t4
    ctx->r1 = ctx->r8 < ctx->r12 ? 1 : 0;
    // 0x8017FC20: beq         $at, $zero, L_8017FE44
    if (ctx->r1 == 0) {
        // 0x8017FC24: nop
    
            goto L_8017FE44;
    }
    // 0x8017FC24: nop

    // 0x8017FC28: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x8017FC2C: addu        $t8, $t8, $a0
    ctx->r24 = ADD32(ctx->r24, ctx->r4);
    // 0x8017FC30: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8017FC34: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8017FC38: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8017FC3C: subu        $t8, $t8, $a0
    ctx->r24 = SUB32(ctx->r24, ctx->r4);
    // 0x8017FC40: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8017FC44: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x8017FC48: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8017FC4C: addu        $t8, $t8, $a0
    ctx->r24 = ADD32(ctx->r24, ctx->r4);
    // 0x8017FC50: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8017FC54: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8017FC58: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8017FC5C: addu        $t5, $t8, $t2
    ctx->r13 = ADD32(ctx->r24, ctx->r10);
    // 0x8017FC60: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8017FC64: lw          $t1, 0x4C($t5)
    ctx->r9 = MEM_W(ctx->r13, 0X4C);
    // 0x8017FC68: addu        $t7, $t6, $t2
    ctx->r15 = ADD32(ctx->r14, ctx->r10);
    // 0x8017FC6C: lw          $t3, 0x58($t7)
    ctx->r11 = MEM_W(ctx->r15, 0X58);
    // 0x8017FC70: sll         $t9, $t1, 2
    ctx->r25 = S32(ctx->r9 << 2);
    // 0x8017FC74: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8017FC78: addu        $t0, $t3, $t9
    ctx->r8 = ADD32(ctx->r11, ctx->r25);
    // 0x8017FC7C: lhu         $t4, 0x2($t0)
    ctx->r12 = MEM_HU(ctx->r8, 0X2);
    // 0x8017FC80: beq         $t4, $at, L_8017FE44
    if (ctx->r12 == ctx->r1) {
        // 0x8017FC84: nop
    
            goto L_8017FE44;
    }
    // 0x8017FC84: nop

    // 0x8017FC88: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8017FC8C: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8017FC90: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8017FC94: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x8017FC98: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8017FC9C: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x8017FCA0: addu        $t1, $t1, $a0
    ctx->r9 = ADD32(ctx->r9, ctx->r4);
    // 0x8017FCA4: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8017FCA8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017FCAC: addiu       $t7, $t7, -0x2A28
    ctx->r15 = ADD32(ctx->r15, -0X2A28);
    // 0x8017FCB0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8017FCB4: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8017FCB8: subu        $t1, $t1, $a0
    ctx->r9 = SUB32(ctx->r9, ctx->r4);
    // 0x8017FCBC: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8017FCC0: lw          $t2, 0x4C($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X4C);
    // 0x8017FCC4: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8017FCC8: addu        $t1, $t1, $a0
    ctx->r9 = ADD32(ctx->r9, ctx->r4);
    // 0x8017FCCC: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8017FCD0: addu        $t3, $t1, $t7
    ctx->r11 = ADD32(ctx->r9, ctx->r15);
    // 0x8017FCD4: addiu       $t5, $t2, 0x1
    ctx->r13 = ADD32(ctx->r10, 0X1);
    // 0x8017FCD8: b           L_8017FB9C
    // 0x8017FCDC: sw          $t5, 0x4C($t3)
    MEM_W(0X4C, ctx->r11) = ctx->r13;
        goto L_8017FB9C;
    // 0x8017FCDC: sw          $t5, 0x4C($t3)
    MEM_W(0X4C, ctx->r11) = ctx->r13;
L_8017FCE0:
    // 0x8017FCE0: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x8017FCE4: addu        $t9, $t9, $a0
    ctx->r25 = ADD32(ctx->r25, ctx->r4);
    // 0x8017FCE8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8017FCEC: subu        $t9, $t9, $a0
    ctx->r25 = SUB32(ctx->r25, ctx->r4);
    // 0x8017FCF0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8017FCF4: sll         $t2, $a0, 2
    ctx->r10 = S32(ctx->r4 << 2);
    // 0x8017FCF8: addu        $t2, $t2, $a0
    ctx->r10 = ADD32(ctx->r10, ctx->r4);
    // 0x8017FCFC: addu        $t9, $t9, $a0
    ctx->r25 = ADD32(ctx->r25, ctx->r4);
    // 0x8017FD00: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017FD04: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x8017FD08: addiu       $t0, $t0, -0x2A28
    ctx->r8 = ADD32(ctx->r8, -0X2A28);
    // 0x8017FD0C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8017FD10: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8017FD14: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x8017FD18: subu        $t2, $t2, $a0
    ctx->r10 = SUB32(ctx->r10, ctx->r4);
    // 0x8017FD1C: addu        $t4, $t9, $t0
    ctx->r12 = ADD32(ctx->r25, ctx->r8);
    // 0x8017FD20: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017FD24: lw          $t6, 0x4C($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X4C);
    // 0x8017FD28: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8017FD2C: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x8017FD30: addu        $t2, $t2, $a0
    ctx->r10 = ADD32(ctx->r10, ctx->r4);
    // 0x8017FD34: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017FD38: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8017FD3C: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x8017FD40: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017FD44: addu        $t1, $t2, $t0
    ctx->r9 = ADD32(ctx->r10, ctx->r8);
    // 0x8017FD48: addiu       $t5, $t5, -0x2A28
    ctx->r13 = ADD32(ctx->r13, -0X2A28);
    // 0x8017FD4C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017FD50: addiu       $t8, $t6, -0x1
    ctx->r24 = ADD32(ctx->r14, -0X1);
    // 0x8017FD54: sw          $t8, 0x4C($t1)
    MEM_W(0X4C, ctx->r9) = ctx->r24;
    // 0x8017FD58: addu        $t3, $t7, $t5
    ctx->r11 = ADD32(ctx->r15, ctx->r13);
    // 0x8017FD5C: lw          $t9, 0x4C($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X4C);
    // 0x8017FD60: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8017FD64: beq         $t9, $at, L_8017FDF0
    if (ctx->r25 == ctx->r1) {
        // 0x8017FD68: nop
    
            goto L_8017FDF0;
    }
    // 0x8017FD68: nop

    // 0x8017FD6C: sll         $t4, $a0, 2
    ctx->r12 = S32(ctx->r4 << 2);
    // 0x8017FD70: addu        $t4, $t4, $a0
    ctx->r12 = ADD32(ctx->r12, ctx->r4);
    // 0x8017FD74: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8017FD78: subu        $t4, $t4, $a0
    ctx->r12 = SUB32(ctx->r12, ctx->r4);
    // 0x8017FD7C: sll         $t0, $a0, 2
    ctx->r8 = S32(ctx->r4 << 2);
    // 0x8017FD80: addu        $t0, $t0, $a0
    ctx->r8 = ADD32(ctx->r8, ctx->r4);
    // 0x8017FD84: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8017FD88: addu        $t4, $t4, $a0
    ctx->r12 = ADD32(ctx->r12, ctx->r4);
    // 0x8017FD8C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8017FD90: subu        $t0, $t0, $a0
    ctx->r8 = SUB32(ctx->r8, ctx->r4);
    // 0x8017FD94: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8017FD98: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x8017FD9C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8017FDA0: addu        $t0, $t0, $a0
    ctx->r8 = ADD32(ctx->r8, ctx->r4);
    // 0x8017FDA4: sll         $t4, $a0, 2
    ctx->r12 = S32(ctx->r4 << 2);
    // 0x8017FDA8: addu        $t4, $t4, $a0
    ctx->r12 = ADD32(ctx->r12, ctx->r4);
    // 0x8017FDAC: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8017FDB0: addu        $t8, $t0, $t5
    ctx->r24 = ADD32(ctx->r8, ctx->r13);
    // 0x8017FDB4: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8017FDB8: lw          $t1, 0x4C($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X4C);
    // 0x8017FDBC: subu        $t4, $t4, $a0
    ctx->r12 = SUB32(ctx->r12, ctx->r4);
    // 0x8017FDC0: lw          $t2, 0x58($t6)
    ctx->r10 = MEM_W(ctx->r14, 0X58);
    // 0x8017FDC4: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8017FDC8: addu        $t4, $t4, $a0
    ctx->r12 = ADD32(ctx->r12, ctx->r4);
    // 0x8017FDCC: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8017FDD0: sll         $t7, $t1, 2
    ctx->r15 = S32(ctx->r9 << 2);
    // 0x8017FDD4: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x8017FDD8: addu        $t3, $t2, $t7
    ctx->r11 = ADD32(ctx->r10, ctx->r15);
    // 0x8017FDDC: lhu         $t9, 0x0($t3)
    ctx->r25 = MEM_HU(ctx->r11, 0X0);
    // 0x8017FDE0: lw          $t0, 0x24($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X24);
    // 0x8017FDE4: sltu        $at, $t9, $t0
    ctx->r1 = ctx->r25 < ctx->r8 ? 1 : 0;
    // 0x8017FDE8: beq         $at, $zero, L_8017FCE0
    if (ctx->r1 == 0) {
        // 0x8017FDEC: nop
    
            goto L_8017FCE0;
    }
    // 0x8017FDEC: nop

L_8017FDF0:
    // 0x8017FDF0: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x8017FDF4: addu        $t8, $t8, $a0
    ctx->r24 = ADD32(ctx->r24, ctx->r4);
    // 0x8017FDF8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8017FDFC: subu        $t8, $t8, $a0
    ctx->r24 = SUB32(ctx->r24, ctx->r4);
    // 0x8017FE00: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8017FE04: sll         $t4, $a0, 2
    ctx->r12 = S32(ctx->r4 << 2);
    // 0x8017FE08: addu        $t4, $t4, $a0
    ctx->r12 = ADD32(ctx->r12, ctx->r4);
    // 0x8017FE0C: addu        $t8, $t8, $a0
    ctx->r24 = ADD32(ctx->r24, ctx->r4);
    // 0x8017FE10: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017FE14: addiu       $t1, $t1, -0x2A28
    ctx->r9 = ADD32(ctx->r9, -0X2A28);
    // 0x8017FE18: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8017FE1C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8017FE20: subu        $t4, $t4, $a0
    ctx->r12 = SUB32(ctx->r12, ctx->r4);
    // 0x8017FE24: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x8017FE28: lw          $t7, 0x4C($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X4C);
    // 0x8017FE2C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8017FE30: addu        $t4, $t4, $a0
    ctx->r12 = ADD32(ctx->r12, ctx->r4);
    // 0x8017FE34: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8017FE38: addu        $t5, $t4, $t1
    ctx->r13 = ADD32(ctx->r12, ctx->r9);
    // 0x8017FE3C: addiu       $t3, $t7, 0x1
    ctx->r11 = ADD32(ctx->r15, 0X1);
    // 0x8017FE40: sw          $t3, 0x4C($t5)
    MEM_W(0X4C, ctx->r13) = ctx->r11;
L_8017FE44:
    // 0x8017FE44: jr          $ra
    // 0x8017FE48: nop

    return;
    // 0x8017FE48: nop

;}
RECOMP_FUNC void func_8017FE4C_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017FE4C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017FE50: lw          $t6, -0x2D90($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2D90);
    // 0x8017FE54: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017FE58: lw          $t8, -0x2E34($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2E34);
    // 0x8017FE5C: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x8017FE60: sltu        $at, $t7, $t8
    ctx->r1 = ctx->r15 < ctx->r24 ? 1 : 0;
    // 0x8017FE64: beq         $at, $zero, L_8017FEB4
    if (ctx->r1 == 0) {
        // 0x8017FE68: nop
    
            goto L_8017FEB4;
    }
    // 0x8017FE68: nop

L_8017FE6C:
    // 0x8017FE6C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017FE70: lw          $t9, -0x2D90($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2D90);
    // 0x8017FE74: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017FE78: lw          $t1, -0x2E34($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2E34);
    // 0x8017FE7C: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x8017FE80: sltu        $at, $t0, $t1
    ctx->r1 = ctx->r8 < ctx->r9 ? 1 : 0;
    // 0x8017FE84: beq         $at, $zero, L_8017FF00
    if (ctx->r1 == 0) {
        // 0x8017FE88: nop
    
            goto L_8017FF00;
    }
    // 0x8017FE88: nop

    // 0x8017FE8C: lbu         $t2, 0x2($t9)
    ctx->r10 = MEM_BU(ctx->r25, 0X2);
    // 0x8017FE90: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8017FE94: beq         $t2, $at, L_8017FF00
    if (ctx->r10 == ctx->r1) {
        // 0x8017FE98: nop
    
            goto L_8017FF00;
    }
    // 0x8017FE98: nop

    // 0x8017FE9C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017FEA0: lw          $t3, -0x2D90($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2D90);
    // 0x8017FEA4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017FEA8: addiu       $t4, $t3, 0x10
    ctx->r12 = ADD32(ctx->r11, 0X10);
    // 0x8017FEAC: b           L_8017FE6C
    // 0x8017FEB0: sw          $t4, -0x2D90($at)
    MEM_W(-0X2D90, ctx->r1) = ctx->r12;
        goto L_8017FE6C;
    // 0x8017FEB0: sw          $t4, -0x2D90($at)
    MEM_W(-0X2D90, ctx->r1) = ctx->r12;
L_8017FEB4:
    // 0x8017FEB4: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017FEB8: lw          $t5, -0x2D90($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2D90);
    // 0x8017FEBC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017FEC0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017FEC4: addiu       $t6, $t5, -0x10
    ctx->r14 = ADD32(ctx->r13, -0X10);
    // 0x8017FEC8: sw          $t6, -0x2D90($at)
    MEM_W(-0X2D90, ctx->r1) = ctx->r14;
    // 0x8017FECC: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x8017FED0: lw          $t8, -0x2E34($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2E34);
    // 0x8017FED4: sltu        $at, $t7, $t8
    ctx->r1 = ctx->r15 < ctx->r24 ? 1 : 0;
    // 0x8017FED8: bne         $at, $zero, L_8017FEEC
    if (ctx->r1 != 0) {
        // 0x8017FEDC: nop
    
            goto L_8017FEEC;
    }
    // 0x8017FEDC: nop

    // 0x8017FEE0: lbu         $t0, 0x2($t6)
    ctx->r8 = MEM_BU(ctx->r14, 0X2);
    // 0x8017FEE4: bne         $t0, $zero, L_8017FEB4
    if (ctx->r8 != 0) {
        // 0x8017FEE8: nop
    
            goto L_8017FEB4;
    }
    // 0x8017FEE8: nop

L_8017FEEC:
    // 0x8017FEEC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017FEF0: lw          $t1, -0x2D90($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2D90);
    // 0x8017FEF4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017FEF8: addiu       $t9, $t1, 0x10
    ctx->r25 = ADD32(ctx->r9, 0X10);
    // 0x8017FEFC: sw          $t9, -0x2D90($at)
    MEM_W(-0X2D90, ctx->r1) = ctx->r25;
L_8017FF00:
    // 0x8017FF00: jr          $ra
    // 0x8017FF04: nop

    return;
    // 0x8017FF04: nop

;}
