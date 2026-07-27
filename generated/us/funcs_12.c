#include "recomp.h"
extern void load_overlays(uint32_t rom, int32_t ram_addr, uint32_t size);
extern void unload_overlays(int32_t ram_addr, uint32_t size);
#include "funcs.h"

RECOMP_FUNC void func_8016ED94_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016ED94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8016ED98: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8016ED9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016EDA0: addiu       $t6, $t6, -0x2E18
    ctx->r14 = ADD32(ctx->r14, -0X2E18);
    // 0x8016EDA4: lw          $t7, 0x7C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X7C);
    // 0x8016EDA8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8016EDAC: bne         $t7, $at, L_8016EE14
    if (ctx->r15 != ctx->r1) {
        // 0x8016EDB0: nop
    
            goto L_8016EE14;
    }
    // 0x8016EDB0: nop

    // 0x8016EDB4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8016EDB8: addiu       $t8, $t8, 0x39A0
    ctx->r24 = ADD32(ctx->r24, 0X39A0);
    // 0x8016EDBC: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8016EDC0: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8016EDC4: addiu       $t2, $t2, -0xD50
    ctx->r10 = ADD32(ctx->r10, -0XD50);
    // 0x8016EDC8: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8016EDCC: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x8016EDD0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8016EDD4: addiu       $t5, $t5, -0x41E0
    ctx->r13 = ADD32(ctx->r13, -0X41E0);
    // 0x8016EDD8: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x8016EDDC: lhu         $t4, 0x6($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X6);
    // 0x8016EDE0: lhu         $t7, 0x0($t5)
    ctx->r15 = MEM_HU(ctx->r13, 0X0);
    // 0x8016EDE4: and         $t8, $t4, $t7
    ctx->r24 = ctx->r12 & ctx->r15;
    // 0x8016EDE8: beq         $t8, $zero, L_8016EEC8
    if (ctx->r24 == 0) {
        // 0x8016EDEC: nop
    
            goto L_8016EEC8;
    }
    // 0x8016EDEC: nop

    // 0x8016EDF0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8016EDF4: addiu       $t0, $t0, -0x41E0
    ctx->r8 = ADD32(ctx->r8, -0X41E0);
    // 0x8016EDF8: lhu         $t1, 0x2($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X2);
    // 0x8016EDFC: lhu         $t9, 0x4($t3)
    ctx->r25 = MEM_HU(ctx->r11, 0X4);
    // 0x8016EE00: and         $t2, $t9, $t1
    ctx->r10 = ctx->r25 & ctx->r9;
    // 0x8016EE04: beq         $t2, $zero, L_8016EEC8
    if (ctx->r10 == 0) {
        // 0x8016EE08: nop
    
            goto L_8016EEC8;
    }
    // 0x8016EE08: nop

    // 0x8016EE0C: b           L_8016EEC8
    // 0x8016EE10: sw          $zero, 0x7C($t6)
    MEM_W(0X7C, ctx->r14) = 0;
        goto L_8016EEC8;
    // 0x8016EE10: sw          $zero, 0x7C($t6)
    MEM_W(0X7C, ctx->r14) = 0;
L_8016EE14:
    // 0x8016EE14: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8016EE18: addiu       $t5, $t5, -0x2E18
    ctx->r13 = ADD32(ctx->r13, -0X2E18);
    // 0x8016EE1C: lw          $t4, 0x7C($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X7C);
    // 0x8016EE20: bne         $t4, $zero, L_8016EEC8
    if (ctx->r12 != 0) {
        // 0x8016EE24: nop
    
            goto L_8016EEC8;
    }
    // 0x8016EE24: nop

    // 0x8016EE28: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8016EE2C: addiu       $t7, $t7, 0x39A0
    ctx->r15 = ADD32(ctx->r15, 0X39A0);
    // 0x8016EE30: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8016EE34: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8016EE38: addiu       $t9, $t9, -0xD50
    ctx->r25 = ADD32(ctx->r25, -0XD50);
    // 0x8016EE3C: sll         $t3, $t8, 2
    ctx->r11 = S32(ctx->r24 << 2);
    // 0x8016EE40: sll         $t0, $t3, 1
    ctx->r8 = S32(ctx->r11 << 1);
    // 0x8016EE44: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8016EE48: addiu       $t6, $t6, -0x41E0
    ctx->r14 = ADD32(ctx->r14, -0X41E0);
    // 0x8016EE4C: addu        $t1, $t0, $t9
    ctx->r9 = ADD32(ctx->r8, ctx->r25);
    // 0x8016EE50: lhu         $t2, 0x6($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X6);
    // 0x8016EE54: lhu         $t5, 0x0($t6)
    ctx->r13 = MEM_HU(ctx->r14, 0X0);
    // 0x8016EE58: and         $t4, $t2, $t5
    ctx->r12 = ctx->r10 & ctx->r13;
    // 0x8016EE5C: beq         $t4, $zero, L_8016EEB0
    if (ctx->r12 == 0) {
        // 0x8016EE60: nop
    
            goto L_8016EEB0;
    }
    // 0x8016EE60: nop

    // 0x8016EE64: lhu         $t8, 0x4($t1)
    ctx->r24 = MEM_HU(ctx->r9, 0X4);
    // 0x8016EE68: lhu         $t3, 0x2($t6)
    ctx->r11 = MEM_HU(ctx->r14, 0X2);
    // 0x8016EE6C: and         $t0, $t8, $t3
    ctx->r8 = ctx->r24 & ctx->r11;
    // 0x8016EE70: beq         $t0, $zero, L_8016EEC8
    if (ctx->r8 == 0) {
        // 0x8016EE74: nop
    
            goto L_8016EEC8;
    }
    // 0x8016EE74: nop

    // 0x8016EE78: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x8016EE7C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8016EE80: addiu       $t5, $t5, 0x39A0
    ctx->r13 = ADD32(ctx->r13, 0X39A0);
    // 0x8016EE84: addiu       $t2, $t9, 0x1
    ctx->r10 = ADD32(ctx->r25, 0X1);
    // 0x8016EE88: sw          $t2, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r10;
    // 0x8016EE8C: lw          $t4, 0x8($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X8);
    // 0x8016EE90: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8016EE94: bne         $t4, $at, L_8016EEA0
    if (ctx->r12 != ctx->r1) {
        // 0x8016EE98: nop
    
            goto L_8016EEA0;
    }
    // 0x8016EE98: nop

    // 0x8016EE9C: sw          $zero, 0x8($t5)
    MEM_W(0X8, ctx->r13) = 0;
L_8016EEA0:
    // 0x8016EEA0: jal         0x800C8544
    // 0x8016EEA4: addiu       $a0, $zero, 0x7B
    ctx->r4 = ADD32(0, 0X7B);
    func_800C8544(rdram, ctx);
        goto after_0;
    // 0x8016EEA4: addiu       $a0, $zero, 0x7B
    ctx->r4 = ADD32(0, 0X7B);
    after_0:
    // 0x8016EEA8: b           L_8016EEC8
    // 0x8016EEAC: nop

        goto L_8016EEC8;
    // 0x8016EEAC: nop

L_8016EEB0:
    // 0x8016EEB0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8016EEB4: addiu       $t6, $t6, -0x2E18
    ctx->r14 = ADD32(ctx->r14, -0X2E18);
    // 0x8016EEB8: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x8016EEBC: sw          $t1, 0x7C($t6)
    MEM_W(0X7C, ctx->r14) = ctx->r9;
    // 0x8016EEC0: jal         0x80173864
    // 0x8016EEC4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80173864_1501A0(rdram, ctx);
        goto after_1;
    // 0x8016EEC4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
L_8016EEC8:
    // 0x8016EEC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016EECC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8016EED0: jr          $ra
    // 0x8016EED4: nop

    return;
    // 0x8016EED4: nop

;}
RECOMP_FUNC void func_8016EED8_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016EED8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8016EEDC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8016EEE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016EEE4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8016EEE8: addiu       $t6, $t6, -0x2E18
    ctx->r14 = ADD32(ctx->r14, -0X2E18);
    // 0x8016EEEC: lw          $t7, 0x7C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X7C);
    // 0x8016EEF0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8016EEF4: bne         $t7, $at, L_8016EF80
    if (ctx->r15 != ctx->r1) {
        // 0x8016EEF8: nop
    
            goto L_8016EF80;
    }
    // 0x8016EEF8: nop

    // 0x8016EEFC: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8016EF00: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8016EF04: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8016EF08: sll         $t9, $t8, 5
    ctx->r25 = S32(ctx->r24 << 5);
    // 0x8016EF0C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8016EF10: lw          $t0, 0x39A0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X39A0);
    // 0x8016EF14: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x8016EF18: addu        $t7, $t7, $t8
    ctx->r15 = ADD32(ctx->r15, ctx->r24);
    // 0x8016EF1C: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8016EF20: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x8016EF24: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x8016EF28: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8016EF2C: addiu       $t3, $t3, -0xD50
    ctx->r11 = ADD32(ctx->r11, -0XD50);
    // 0x8016EF30: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8016EF34: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x8016EF38: lhu         $t9, -0x41E0($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X41E0);
    // 0x8016EF3C: lhu         $t5, 0x6($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X6);
    // 0x8016EF40: and         $t0, $t5, $t9
    ctx->r8 = ctx->r13 & ctx->r25;
    // 0x8016EF44: beq         $t0, $zero, L_8016F108
    if (ctx->r8 == 0) {
        // 0x8016EF48: nop
    
            goto L_8016F108;
    }
    // 0x8016EF48: nop

    // 0x8016EF4C: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x8016EF50: addu        $t7, $t7, $t8
    ctx->r15 = ADD32(ctx->r15, ctx->r24);
    // 0x8016EF54: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x8016EF58: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8016EF5C: addu        $t5, $t5, $t7
    ctx->r13 = ADD32(ctx->r13, ctx->r15);
    // 0x8016EF60: addu        $t1, $t2, $t3
    ctx->r9 = ADD32(ctx->r10, ctx->r11);
    // 0x8016EF64: lhu         $t4, 0x4($t1)
    ctx->r12 = MEM_HU(ctx->r9, 0X4);
    // 0x8016EF68: lhu         $t5, -0x41DE($t5)
    ctx->r13 = MEM_HU(ctx->r13, -0X41DE);
    // 0x8016EF6C: and         $t9, $t4, $t5
    ctx->r25 = ctx->r12 & ctx->r13;
    // 0x8016EF70: beq         $t9, $zero, L_8016F108
    if (ctx->r25 == 0) {
        // 0x8016EF74: nop
    
            goto L_8016F108;
    }
    // 0x8016EF74: nop

    // 0x8016EF78: b           L_8016F108
    // 0x8016EF7C: sw          $t8, 0x7C($t6)
    MEM_W(0X7C, ctx->r14) = ctx->r24;
        goto L_8016F108;
    // 0x8016EF7C: sw          $t8, 0x7C($t6)
    MEM_W(0X7C, ctx->r14) = ctx->r24;
L_8016EF80:
    // 0x8016EF80: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8016EF84: addiu       $t0, $t0, -0x2E18
    ctx->r8 = ADD32(ctx->r8, -0X2E18);
    // 0x8016EF88: lw          $t2, 0x7C($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X7C);
    // 0x8016EF8C: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x8016EF90: bne         $t2, $t3, L_8016F108
    if (ctx->r10 != ctx->r11) {
        // 0x8016EF94: nop
    
            goto L_8016F108;
    }
    // 0x8016EF94: nop

    // 0x8016EF98: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8016EF9C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8016EFA0: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x8016EFA4: sll         $t7, $t1, 5
    ctx->r15 = S32(ctx->r9 << 5);
    // 0x8016EFA8: addu        $t4, $t4, $t7
    ctx->r12 = ADD32(ctx->r12, ctx->r15);
    // 0x8016EFAC: lw          $t4, 0x39A0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X39A0);
    // 0x8016EFB0: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8016EFB4: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8016EFB8: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8016EFBC: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8016EFC0: sll         $t9, $t5, 1
    ctx->r25 = S32(ctx->r13 << 1);
    // 0x8016EFC4: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x8016EFC8: addiu       $t3, $t3, -0x41E0
    ctx->r11 = ADD32(ctx->r11, -0X41E0);
    // 0x8016EFCC: addiu       $t8, $t8, -0xD50
    ctx->r24 = ADD32(ctx->r24, -0XD50);
    // 0x8016EFD0: addu        $t6, $t9, $t8
    ctx->r14 = ADD32(ctx->r25, ctx->r24);
    // 0x8016EFD4: addu        $t7, $t2, $t3
    ctx->r15 = ADD32(ctx->r10, ctx->r11);
    // 0x8016EFD8: lhu         $t4, 0x0($t7)
    ctx->r12 = MEM_HU(ctx->r15, 0X0);
    // 0x8016EFDC: lhu         $t0, 0x6($t6)
    ctx->r8 = MEM_HU(ctx->r14, 0X6);
    // 0x8016EFE0: and         $t5, $t0, $t4
    ctx->r13 = ctx->r8 & ctx->r12;
    // 0x8016EFE4: beq         $t5, $zero, L_8016F0F0
    if (ctx->r13 == 0) {
        // 0x8016EFE8: nop
    
            goto L_8016F0F0;
    }
    // 0x8016EFE8: nop

    // 0x8016EFEC: sll         $t8, $t1, 2
    ctx->r24 = S32(ctx->r9 << 2);
    // 0x8016EFF0: addu        $t8, $t8, $t1
    ctx->r24 = ADD32(ctx->r24, ctx->r9);
    // 0x8016EFF4: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x8016EFF8: addu        $t2, $t8, $t3
    ctx->r10 = ADD32(ctx->r24, ctx->r11);
    // 0x8016EFFC: lhu         $t7, 0x2($t2)
    ctx->r15 = MEM_HU(ctx->r10, 0X2);
    // 0x8016F000: lhu         $t9, 0x4($t6)
    ctx->r25 = MEM_HU(ctx->r14, 0X4);
    // 0x8016F004: and         $t0, $t9, $t7
    ctx->r8 = ctx->r25 & ctx->r15;
    // 0x8016F008: beq         $t0, $zero, L_8016F108
    if (ctx->r8 == 0) {
        // 0x8016F00C: nop
    
            goto L_8016F108;
    }
    // 0x8016F00C: nop

L_8016F010:
    // 0x8016F010: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x8016F014: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8016F018: addiu       $t6, $t6, 0x39A0
    ctx->r14 = ADD32(ctx->r14, 0X39A0);
    // 0x8016F01C: sll         $t5, $t4, 5
    ctx->r13 = S32(ctx->r12 << 5);
    // 0x8016F020: addu        $t1, $t5, $t6
    ctx->r9 = ADD32(ctx->r13, ctx->r14);
    // 0x8016F024: lw          $t8, 0x8($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X8);
    // 0x8016F028: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8016F02C: addiu       $t7, $t7, 0x39A0
    ctx->r15 = ADD32(ctx->r15, 0X39A0);
    // 0x8016F030: addiu       $t3, $t8, 0x1
    ctx->r11 = ADD32(ctx->r24, 0X1);
    // 0x8016F034: sw          $t3, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r11;
    // 0x8016F038: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8016F03C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8016F040: sll         $t9, $t2, 5
    ctx->r25 = S32(ctx->r10 << 5);
    // 0x8016F044: addu        $t0, $t9, $t7
    ctx->r8 = ADD32(ctx->r25, ctx->r15);
    // 0x8016F048: lw          $t4, 0x8($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X8);
    // 0x8016F04C: bne         $t4, $at, L_8016F058
    if (ctx->r12 != ctx->r1) {
        // 0x8016F050: nop
    
            goto L_8016F058;
    }
    // 0x8016F050: nop

    // 0x8016F054: sw          $zero, 0x8($t0)
    MEM_W(0X8, ctx->r8) = 0;
L_8016F058:
    // 0x8016F058: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8016F05C: lw          $t5, -0x2E3C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2E3C);
    // 0x8016F060: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8016F064: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8016F068: beq         $t5, $zero, L_8016F0D4
    if (ctx->r13 == 0) {
        // 0x8016F06C: nop
    
            goto L_8016F0D4;
    }
    // 0x8016F06C: nop

L_8016F070:
    // 0x8016F070: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8016F074: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8016F078: beq         $t6, $t8, L_8016F0B4
    if (ctx->r14 == ctx->r24) {
        // 0x8016F07C: nop
    
            goto L_8016F0B4;
    }
    // 0x8016F07C: nop

    // 0x8016F080: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8016F084: addiu       $t1, $t1, 0x39A0
    ctx->r9 = ADD32(ctx->r9, 0X39A0);
    // 0x8016F088: sll         $t3, $t8, 5
    ctx->r11 = S32(ctx->r24 << 5);
    // 0x8016F08C: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x8016F090: addu        $t4, $t7, $t1
    ctx->r12 = ADD32(ctx->r15, ctx->r9);
    // 0x8016F094: addu        $t2, $t3, $t1
    ctx->r10 = ADD32(ctx->r11, ctx->r9);
    // 0x8016F098: lw          $t9, 0x8($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X8);
    // 0x8016F09C: lw          $t0, 0x8($t4)
    ctx->r8 = MEM_W(ctx->r12, 0X8);
    // 0x8016F0A0: bne         $t9, $t0, L_8016F0B4
    if (ctx->r25 != ctx->r8) {
        // 0x8016F0A4: nop
    
            goto L_8016F0B4;
    }
    // 0x8016F0A4: nop

    // 0x8016F0A8: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x8016F0AC: addiu       $t8, $t5, 0x1
    ctx->r24 = ADD32(ctx->r13, 0X1);
    // 0x8016F0B0: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
L_8016F0B4:
    // 0x8016F0B4: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x8016F0B8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8016F0BC: lw          $t6, -0x2E3C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2E3C);
    // 0x8016F0C0: addiu       $t2, $t3, 0x1
    ctx->r10 = ADD32(ctx->r11, 0X1);
    // 0x8016F0C4: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x8016F0C8: sltu        $at, $t2, $t6
    ctx->r1 = ctx->r10 < ctx->r14 ? 1 : 0;
    // 0x8016F0CC: bne         $at, $zero, L_8016F070
    if (ctx->r1 != 0) {
        // 0x8016F0D0: nop
    
            goto L_8016F070;
    }
    // 0x8016F0D0: nop

L_8016F0D4:
    // 0x8016F0D4: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8016F0D8: bne         $t7, $zero, L_8016F010
    if (ctx->r15 != 0) {
        // 0x8016F0DC: nop
    
            goto L_8016F010;
    }
    // 0x8016F0DC: nop

    // 0x8016F0E0: jal         0x800C8544
    // 0x8016F0E4: addiu       $a0, $zero, 0x7B
    ctx->r4 = ADD32(0, 0X7B);
    func_800C8544(rdram, ctx);
        goto after_0;
    // 0x8016F0E4: addiu       $a0, $zero, 0x7B
    ctx->r4 = ADD32(0, 0X7B);
    after_0:
    // 0x8016F0E8: b           L_8016F108
    // 0x8016F0EC: nop

        goto L_8016F108;
    // 0x8016F0EC: nop

L_8016F0F0:
    // 0x8016F0F0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8016F0F4: addiu       $t4, $t4, -0x2E18
    ctx->r12 = ADD32(ctx->r12, -0X2E18);
    // 0x8016F0F8: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x8016F0FC: sw          $t1, 0x7C($t4)
    MEM_W(0X7C, ctx->r12) = ctx->r9;
    // 0x8016F100: jal         0x80173864
    // 0x8016F104: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80173864_1501A0(rdram, ctx);
        goto after_1;
    // 0x8016F104: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
L_8016F108:
    // 0x8016F108: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016F10C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8016F110: jr          $ra
    // 0x8016F114: nop

    return;
    // 0x8016F114: nop

;}
RECOMP_FUNC void func_8016F118_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016F118: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8016F11C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8016F120: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016F124: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8016F128: addiu       $t6, $t6, -0x2E18
    ctx->r14 = ADD32(ctx->r14, -0X2E18);
    // 0x8016F12C: lw          $t7, 0x7C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X7C);
    // 0x8016F130: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8016F134: bne         $t7, $at, L_8016F1C0
    if (ctx->r15 != ctx->r1) {
        // 0x8016F138: nop
    
            goto L_8016F1C0;
    }
    // 0x8016F138: nop

    // 0x8016F13C: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8016F140: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8016F144: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8016F148: sll         $t9, $t8, 5
    ctx->r25 = S32(ctx->r24 << 5);
    // 0x8016F14C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8016F150: lw          $t0, 0x39A0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X39A0);
    // 0x8016F154: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x8016F158: addu        $t7, $t7, $t8
    ctx->r15 = ADD32(ctx->r15, ctx->r24);
    // 0x8016F15C: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8016F160: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x8016F164: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x8016F168: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8016F16C: addiu       $t3, $t3, -0xD50
    ctx->r11 = ADD32(ctx->r11, -0XD50);
    // 0x8016F170: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8016F174: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x8016F178: lhu         $t9, -0x41E0($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X41E0);
    // 0x8016F17C: lhu         $t5, 0x6($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X6);
    // 0x8016F180: and         $t0, $t5, $t9
    ctx->r8 = ctx->r13 & ctx->r25;
    // 0x8016F184: beq         $t0, $zero, L_8016F364
    if (ctx->r8 == 0) {
        // 0x8016F188: nop
    
            goto L_8016F364;
    }
    // 0x8016F188: nop

    // 0x8016F18C: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x8016F190: addu        $t7, $t7, $t8
    ctx->r15 = ADD32(ctx->r15, ctx->r24);
    // 0x8016F194: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x8016F198: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8016F19C: addu        $t5, $t5, $t7
    ctx->r13 = ADD32(ctx->r13, ctx->r15);
    // 0x8016F1A0: addu        $t1, $t2, $t3
    ctx->r9 = ADD32(ctx->r10, ctx->r11);
    // 0x8016F1A4: lhu         $t4, 0x4($t1)
    ctx->r12 = MEM_HU(ctx->r9, 0X4);
    // 0x8016F1A8: lhu         $t5, -0x41DE($t5)
    ctx->r13 = MEM_HU(ctx->r13, -0X41DE);
    // 0x8016F1AC: and         $t9, $t4, $t5
    ctx->r25 = ctx->r12 & ctx->r13;
    // 0x8016F1B0: beq         $t9, $zero, L_8016F364
    if (ctx->r25 == 0) {
        // 0x8016F1B4: nop
    
            goto L_8016F364;
    }
    // 0x8016F1B4: nop

    // 0x8016F1B8: b           L_8016F364
    // 0x8016F1BC: sw          $t8, 0x7C($t6)
    MEM_W(0X7C, ctx->r14) = ctx->r24;
        goto L_8016F364;
    // 0x8016F1BC: sw          $t8, 0x7C($t6)
    MEM_W(0X7C, ctx->r14) = ctx->r24;
L_8016F1C0:
    // 0x8016F1C0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8016F1C4: addiu       $t0, $t0, -0x2E18
    ctx->r8 = ADD32(ctx->r8, -0X2E18);
    // 0x8016F1C8: lw          $t2, 0x7C($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X7C);
    // 0x8016F1CC: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x8016F1D0: bne         $t2, $t3, L_8016F364
    if (ctx->r10 != ctx->r11) {
        // 0x8016F1D4: nop
    
            goto L_8016F364;
    }
    // 0x8016F1D4: nop

    // 0x8016F1D8: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8016F1DC: beq         $t1, $zero, L_8016F1EC
    if (ctx->r9 == 0) {
        // 0x8016F1E0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8016F1EC;
    }
    // 0x8016F1E0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8016F1E4: bne         $t1, $at, L_8016F1F4
    if (ctx->r9 != ctx->r1) {
        // 0x8016F1E8: nop
    
            goto L_8016F1F4;
    }
    // 0x8016F1E8: nop

L_8016F1EC:
    // 0x8016F1EC: b           L_8016F1FC
    // 0x8016F1F0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
        goto L_8016F1FC;
    // 0x8016F1F0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_8016F1F4:
    // 0x8016F1F4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8016F1F8: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
L_8016F1FC:
    // 0x8016F1FC: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x8016F200: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8016F204: addiu       $t9, $t9, 0x39A0
    ctx->r25 = ADD32(ctx->r25, 0X39A0);
    // 0x8016F208: sll         $t5, $t4, 5
    ctx->r13 = S32(ctx->r12 << 5);
    // 0x8016F20C: addu        $t8, $t5, $t9
    ctx->r24 = ADD32(ctx->r13, ctx->r25);
    // 0x8016F210: lw          $t6, 0x0($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X0);
    // 0x8016F214: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8016F218: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8016F21C: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8016F220: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8016F224: sll         $t0, $t6, 2
    ctx->r8 = S32(ctx->r14 << 2);
    // 0x8016F228: sll         $t2, $t0, 1
    ctx->r10 = S32(ctx->r8 << 1);
    // 0x8016F22C: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x8016F230: addiu       $t3, $t3, -0xD50
    ctx->r11 = ADD32(ctx->r11, -0XD50);
    // 0x8016F234: addiu       $t8, $t8, -0x41E0
    ctx->r24 = ADD32(ctx->r24, -0X41E0);
    // 0x8016F238: addu        $t6, $t5, $t8
    ctx->r14 = ADD32(ctx->r13, ctx->r24);
    // 0x8016F23C: addu        $t1, $t2, $t3
    ctx->r9 = ADD32(ctx->r10, ctx->r11);
    // 0x8016F240: lhu         $t7, 0x6($t1)
    ctx->r15 = MEM_HU(ctx->r9, 0X6);
    // 0x8016F244: lhu         $t0, 0x0($t6)
    ctx->r8 = MEM_HU(ctx->r14, 0X0);
    // 0x8016F248: and         $t2, $t7, $t0
    ctx->r10 = ctx->r15 & ctx->r8;
    // 0x8016F24C: beq         $t2, $zero, L_8016F340
    if (ctx->r10 == 0) {
        // 0x8016F250: nop
    
            goto L_8016F340;
    }
    // 0x8016F250: nop

    // 0x8016F254: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x8016F258: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8016F25C: sll         $t5, $t3, 5
    ctx->r13 = S32(ctx->r11 << 5);
    // 0x8016F260: addu        $t6, $t5, $t9
    ctx->r14 = ADD32(ctx->r13, ctx->r25);
    // 0x8016F264: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x8016F268: beq         $t7, $at, L_8016F364
    if (ctx->r15 == ctx->r1) {
        // 0x8016F26C: nop
    
            goto L_8016F364;
    }
    // 0x8016F26C: nop

    // 0x8016F270: sll         $t2, $t4, 2
    ctx->r10 = S32(ctx->r12 << 2);
    // 0x8016F274: addu        $t2, $t2, $t4
    ctx->r10 = ADD32(ctx->r10, ctx->r12);
    // 0x8016F278: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x8016F27C: addu        $t3, $t2, $t8
    ctx->r11 = ADD32(ctx->r10, ctx->r24);
    // 0x8016F280: lhu         $t5, 0x2($t3)
    ctx->r13 = MEM_HU(ctx->r11, 0X2);
    // 0x8016F284: lhu         $t0, 0x4($t1)
    ctx->r8 = MEM_HU(ctx->r9, 0X4);
    // 0x8016F288: and         $t9, $t0, $t5
    ctx->r25 = ctx->r8 & ctx->r13;
    // 0x8016F28C: beq         $t9, $zero, L_8016F364
    if (ctx->r25 == 0) {
        // 0x8016F290: nop
    
            goto L_8016F364;
    }
    // 0x8016F290: nop

L_8016F294:
    // 0x8016F294: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8016F298: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8016F29C: addiu       $t1, $t1, 0x39A0
    ctx->r9 = ADD32(ctx->r9, 0X39A0);
    // 0x8016F2A0: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x8016F2A4: addu        $t4, $t7, $t1
    ctx->r12 = ADD32(ctx->r15, ctx->r9);
    // 0x8016F2A8: lw          $t2, 0x8($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X8);
    // 0x8016F2AC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8016F2B0: addiu       $t5, $t5, 0x39A0
    ctx->r13 = ADD32(ctx->r13, 0X39A0);
    // 0x8016F2B4: addiu       $t8, $t2, 0x1
    ctx->r24 = ADD32(ctx->r10, 0X1);
    // 0x8016F2B8: sw          $t8, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r24;
    // 0x8016F2BC: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x8016F2C0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8016F2C4: sll         $t0, $t3, 5
    ctx->r8 = S32(ctx->r11 << 5);
    // 0x8016F2C8: addu        $t9, $t0, $t5
    ctx->r25 = ADD32(ctx->r8, ctx->r13);
    // 0x8016F2CC: lw          $t6, 0x8($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X8);
    // 0x8016F2D0: bne         $t6, $at, L_8016F2DC
    if (ctx->r14 != ctx->r1) {
        // 0x8016F2D4: nop
    
            goto L_8016F2DC;
    }
    // 0x8016F2D4: nop

    // 0x8016F2D8: sw          $zero, 0x8($t9)
    MEM_W(0X8, ctx->r25) = 0;
L_8016F2DC:
    // 0x8016F2DC: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8016F2E0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8016F2E4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8016F2E8: sll         $t1, $t7, 5
    ctx->r9 = S32(ctx->r15 << 5);
    // 0x8016F2EC: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8016F2F0: sll         $t3, $t7, 2
    ctx->r11 = S32(ctx->r15 << 2);
    // 0x8016F2F4: lw          $t2, 0x39A8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X39A8);
    // 0x8016F2F8: addu        $t0, $t0, $t3
    ctx->r8 = ADD32(ctx->r8, ctx->r11);
    // 0x8016F2FC: lw          $t0, -0x2DD0($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2DD0);
    // 0x8016F300: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8016F304: sllv        $t4, $t8, $t2
    ctx->r12 = S32(ctx->r24 << (ctx->r10 & 31));
    // 0x8016F308: and         $t5, $t4, $t0
    ctx->r13 = ctx->r12 & ctx->r8;
    // 0x8016F30C: beq         $t5, $zero, L_8016F294
    if (ctx->r13 == 0) {
        // 0x8016F310: nop
    
            goto L_8016F294;
    }
    // 0x8016F310: nop

    // 0x8016F314: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8016F318: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8016F31C: addiu       $t1, $t1, 0x39A0
    ctx->r9 = ADD32(ctx->r9, 0X39A0);
    // 0x8016F320: sll         $t9, $t6, 5
    ctx->r25 = S32(ctx->r14 << 5);
    // 0x8016F324: addu        $t8, $t9, $t1
    ctx->r24 = ADD32(ctx->r25, ctx->r9);
    // 0x8016F328: lw          $t2, 0x8($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X8);
    // 0x8016F32C: addiu       $a0, $zero, 0x7B
    ctx->r4 = ADD32(0, 0X7B);
    // 0x8016F330: jal         0x800C8544
    // 0x8016F334: sw          $t2, 0x48($t8)
    MEM_W(0X48, ctx->r24) = ctx->r10;
    func_800C8544(rdram, ctx);
        goto after_0;
    // 0x8016F334: sw          $t2, 0x48($t8)
    MEM_W(0X48, ctx->r24) = ctx->r10;
    after_0:
    // 0x8016F338: b           L_8016F364
    // 0x8016F33C: nop

        goto L_8016F364;
    // 0x8016F33C: nop

L_8016F340:
    // 0x8016F340: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8016F344: addiu       $t3, $t3, -0x2E18
    ctx->r11 = ADD32(ctx->r11, -0X2E18);
    // 0x8016F348: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8016F34C: sw          $t7, 0x7C($t3)
    MEM_W(0X7C, ctx->r11) = ctx->r15;
    // 0x8016F350: jal         0x80173864
    // 0x8016F354: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_80173864_1501A0(rdram, ctx);
        goto after_1;
    // 0x8016F354: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x8016F358: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8016F35C: jal         0x80173864
    // 0x8016F360: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    func_80173864_1501A0(rdram, ctx);
        goto after_2;
    // 0x8016F360: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    after_2:
L_8016F364:
    // 0x8016F364: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016F368: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8016F36C: jr          $ra
    // 0x8016F370: nop

    return;
    // 0x8016F370: nop

;}
RECOMP_FUNC void func_8016F374_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016F374: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8016F378: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8016F37C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8016F380: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8016F384: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x8016F388: addiu       $t8, $t8, -0x4198
    ctx->r24 = ADD32(ctx->r24, -0X4198);
    // 0x8016F38C: lui         $at, 0xBFC0
    ctx->r1 = S32(0XBFC0 << 16);
    // 0x8016F390: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8016F394: lwc1        $f4, 0x40($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X40);
    // 0x8016F398: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016F39C: lwc1        $f10, -0x2E30($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x8016F3A0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8016F3A4: lwc1        $f18, 0x0($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X0);
    // 0x8016F3A8: lui         $at, 0xBFC0
    ctx->r1 = S32(0XBFC0 << 16);
    // 0x8016F3AC: lwc1        $f6, 0x44($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X44);
    // 0x8016F3B0: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x8016F3B4: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x8016F3B8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8016F3BC: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8016F3C0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8016F3C4: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x8016F3C8: sll         $t9, $t6, 3
    ctx->r25 = S32(ctx->r14 << 3);
    // 0x8016F3CC: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x8016F3D0: subu        $t9, $t9, $t6
    ctx->r25 = SUB32(ctx->r25, ctx->r14);
    // 0x8016F3D4: sll         $t9, $t9, 5
    ctx->r25 = S32(ctx->r25 << 5);
    // 0x8016F3D8: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8016F3DC: mul.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8016F3E0: lwc1        $f6, 0x4($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X4);
    // 0x8016F3E4: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x8016F3E8: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8016F3EC: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x8016F3F0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8016F3F4: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x8016F3F8: mul.s       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x8016F3FC: lwc1        $f16, 0x48($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X48);
    // 0x8016F400: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x8016F404: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8016F408: lw          $t3, 0x351C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X351C);
    // 0x8016F40C: lw          $a0, 0x39A8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X39A8);
    // 0x8016F410: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8016F414: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8016F418: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016F41C: addiu       $a0, $a0, 0xA
    ctx->r4 = ADD32(ctx->r4, 0XA);
    // 0x8016F420: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x8016F424: lwc1        $f16, 0x8($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X8);
    // 0x8016F428: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8016F42C: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x8016F430: lwc1        $f18, -0x2BCC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2BCC);
    // 0x8016F434: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016F438: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8016F43C: lwc1        $f6, 0x4($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X4);
    // 0x8016F440: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8016F444: lwc1        $f10, 0x8($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X8);
    // 0x8016F448: lwc1        $f6, -0x2BC8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2BC8);
    // 0x8016F44C: add.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8016F450: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x8016F454: lwc1        $f8, 0xC($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0XC);
    // 0x8016F458: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016F45C: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x8016F460: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x8016F464: lwc1        $f16, 0x10($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X10);
    // 0x8016F468: lwc1        $f10, -0x2BC4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2BC4);
    // 0x8016F46C: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x8016F470: lwc1        $f4, 0x14($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X14);
    // 0x8016F474: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x8016F478: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
    // 0x8016F47C: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    // 0x8016F480: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x8016F484: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    // 0x8016F488: jal         0x80187E5C
    // 0x8016F48C: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    func_80187E5C_1501A0(rdram, ctx);
        goto after_0;
    // 0x8016F48C: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8016F490: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8016F494: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8016F498: jr          $ra
    // 0x8016F49C: nop

    return;
    // 0x8016F49C: nop

;}
RECOMP_FUNC void func_8016F4A0_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016F4A0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8016F4A4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8016F4A8: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8016F4AC: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8016F4B0: addiu       $t8, $t8, -0x4198
    ctx->r24 = ADD32(ctx->r24, -0X4198);
    // 0x8016F4B4: lui         $at, 0xBFC0
    ctx->r1 = S32(0XBFC0 << 16);
    // 0x8016F4B8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8016F4BC: lwc1        $f4, 0x40($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X40);
    // 0x8016F4C0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016F4C4: lwc1        $f10, -0x2E30($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x8016F4C8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8016F4CC: lwc1        $f18, 0x0($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X0);
    // 0x8016F4D0: lui         $at, 0xBFC0
    ctx->r1 = S32(0XBFC0 << 16);
    // 0x8016F4D4: lwc1        $f6, 0x44($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X44);
    // 0x8016F4D8: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x8016F4DC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8016F4E0: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8016F4E4: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8016F4E8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8016F4EC: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x8016F4F0: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x8016F4F4: lw          $a0, 0x39A8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X39A8);
    // 0x8016F4F8: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8016F4FC: mul.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8016F500: lwc1        $f6, 0x4($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X4);
    // 0x8016F504: addiu       $a0, $a0, 0xA
    ctx->r4 = ADD32(ctx->r4, 0XA);
    // 0x8016F508: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8016F50C: mul.s       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x8016F510: lwc1        $f16, 0x48($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X48);
    // 0x8016F514: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8016F518: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8016F51C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016F520: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x8016F524: lwc1        $f16, 0x8($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X8);
    // 0x8016F528: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8016F52C: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x8016F530: lwc1        $f18, -0x2BCC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2BCC);
    // 0x8016F534: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016F538: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8016F53C: lwc1        $f6, 0x4($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X4);
    // 0x8016F540: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8016F544: lwc1        $f10, 0x8($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X8);
    // 0x8016F548: lwc1        $f6, -0x2BC8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2BC8);
    // 0x8016F54C: add.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8016F550: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x8016F554: lwc1        $f8, 0xC($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0XC);
    // 0x8016F558: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016F55C: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x8016F560: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x8016F564: lwc1        $f16, 0x10($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X10);
    // 0x8016F568: lwc1        $f10, -0x2BC4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2BC4);
    // 0x8016F56C: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x8016F570: lwc1        $f4, 0x14($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X14);
    // 0x8016F574: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
    // 0x8016F578: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x8016F57C: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    // 0x8016F580: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x8016F584: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    // 0x8016F588: jal         0x80187E5C
    // 0x8016F58C: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    func_80187E5C_1501A0(rdram, ctx);
        goto after_0;
    // 0x8016F58C: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8016F590: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8016F594: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8016F598: jr          $ra
    // 0x8016F59C: nop

    return;
    // 0x8016F59C: nop

;}
RECOMP_FUNC void func_8016F5A0_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016F5A0: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8016F5A4: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_8016F5A8:
    // 0x8016F5A8: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x8016F5AC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8016F5B0: addiu       $t8, $t8, 0xF98
    ctx->r24 = ADD32(ctx->r24, 0XF98);
    // 0x8016F5B4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8016F5B8: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8016F5BC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8016F5C0: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8016F5C4: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8016F5C8: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8016F5CC: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8016F5D0: sltiu       $at, $t0, 0xA
    ctx->r1 = ctx->r8 < 0XA ? 1 : 0;
    // 0x8016F5D4: bne         $at, $zero, L_8016F5F8
    if (ctx->r1 != 0) {
        // 0x8016F5D8: sltiu       $at, $t0, 0xF
        ctx->r1 = ctx->r8 < 0XF ? 1 : 0;
            goto L_8016F5F8;
    }
    // 0x8016F5D8: sltiu       $at, $t0, 0xF
    ctx->r1 = ctx->r8 < 0XF ? 1 : 0;
    // 0x8016F5DC: beq         $at, $zero, L_8016F5F8
    if (ctx->r1 == 0) {
        // 0x8016F5E0: nop
    
            goto L_8016F5F8;
    }
    // 0x8016F5E0: nop

    // 0x8016F5E4: lw          $t1, 0x8($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X8);
    // 0x8016F5E8: bne         $t1, $a0, L_8016F5F8
    if (ctx->r9 != ctx->r4) {
        // 0x8016F5EC: nop
    
            goto L_8016F5F8;
    }
    // 0x8016F5EC: nop

    // 0x8016F5F0: b           L_8016F610
    // 0x8016F5F4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8016F610;
    // 0x8016F5F4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8016F5F8:
    // 0x8016F5F8: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x8016F5FC: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8016F600: sltiu       $at, $t3, 0x30
    ctx->r1 = ctx->r11 < 0X30 ? 1 : 0;
    // 0x8016F604: bne         $at, $zero, L_8016F5A8
    if (ctx->r1 != 0) {
        // 0x8016F608: sw          $t3, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r11;
            goto L_8016F5A8;
    }
    // 0x8016F608: sw          $t3, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r11;
    // 0x8016F60C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8016F610:
    // 0x8016F610: jr          $ra
    // 0x8016F614: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8016F614: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8016F618_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016F618: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8016F61C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8016F620: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8016F624: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8016F628: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016F62C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8016F630: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8016F634: lw          $t8, -0x2B6C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2B6C);
    // 0x8016F638: sltiu       $at, $t8, 0xE
    ctx->r1 = ctx->r24 < 0XE ? 1 : 0;
    // 0x8016F63C: beq         $at, $zero, L_8016F974
    if (ctx->r1 == 0) {
        // 0x8016F640: nop
    
            goto L_8016F974;
    }
    // 0x8016F640: nop

    // 0x8016F644: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8016F648: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8016F64C: addu        $at, $at, $t8
    gpr jr_addend_8016F654 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8016F650: lw          $t8, -0x518($at)
    ctx->r24 = ADD32(ctx->r1, -0X518);
    // 0x8016F654: jr          $t8
    // 0x8016F658: nop

    switch (jr_addend_8016F654 >> 2) {
        case 0: goto L_8016F65C; break;
        case 1: goto L_8016F800; break;
        case 2: goto L_8016F974; break;
        case 3: goto L_8016F974; break;
        case 4: goto L_8016F974; break;
        case 5: goto L_8016F860; break;
        case 6: goto L_8016F974; break;
        case 7: goto L_8016F974; break;
        case 8: goto L_8016F974; break;
        case 9: goto L_8016F8C0; break;
        case 10: goto L_8016F974; break;
        case 11: goto L_8016F974; break;
        case 12: goto L_8016F974; break;
        case 13: goto L_8016F920; break;
        default: switch_error(__func__, 0x8016F654, 0x8019FAE8);
    }
    // 0x8016F658: nop

L_8016F65C:
    // 0x8016F65C: jal         0x8016F5A0
    // 0x8016F660: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8016F5A0_1501A0(rdram, ctx);
        goto after_0;
    // 0x8016F660: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_0:
    // 0x8016F664: bne         $v0, $zero, L_8016F994
    if (ctx->r2 != 0) {
        // 0x8016F668: nop
    
            goto L_8016F994;
    }
    // 0x8016F668: nop

    // 0x8016F66C: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8016F670: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8016F674: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8016F678: sll         $t0, $t9, 5
    ctx->r8 = S32(ctx->r25 << 5);
    // 0x8016F67C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8016F680: lw          $t1, 0x39A0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X39A0);
    // 0x8016F684: sll         $t5, $t9, 2
    ctx->r13 = S32(ctx->r25 << 2);
    // 0x8016F688: addu        $t5, $t5, $t9
    ctx->r13 = ADD32(ctx->r13, ctx->r25);
    // 0x8016F68C: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8016F690: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x8016F694: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x8016F698: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8016F69C: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8016F6A0: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8016F6A4: lhu         $t4, -0xD4E($t4)
    ctx->r12 = MEM_HU(ctx->r12, -0XD4E);
    // 0x8016F6A8: lhu         $t6, -0x41E0($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X41E0);
    // 0x8016F6AC: and         $t7, $t4, $t6
    ctx->r15 = ctx->r12 & ctx->r14;
    // 0x8016F6B0: beq         $t7, $zero, L_8016F6C8
    if (ctx->r15 == 0) {
        // 0x8016F6B4: nop
    
            goto L_8016F6C8;
    }
    // 0x8016F6B4: nop

    // 0x8016F6B8: jal         0x801738C4
    // 0x8016F6BC: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    func_801738C4_1501A0(rdram, ctx);
        goto after_1;
    // 0x8016F6BC: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_1:
    // 0x8016F6C0: b           L_8016F994
    // 0x8016F6C4: nop

        goto L_8016F994;
    // 0x8016F6C4: nop

L_8016F6C8:
    // 0x8016F6C8: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8016F6CC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016F6D0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8016F6D4: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8016F6D8: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8016F6DC: sw          $t8, -0x2B6C($at)
    MEM_W(-0X2B6C, ctx->r1) = ctx->r24;
    // 0x8016F6E0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_8016F6E4:
    // 0x8016F6E4: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8016F6E8: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x8016F6EC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8016F6F0: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x8016F6F4: sll         $t4, $t5, 3
    ctx->r12 = S32(ctx->r13 << 3);
    // 0x8016F6F8: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x8016F6FC: subu        $t4, $t4, $t5
    ctx->r12 = SUB32(ctx->r12, ctx->r13);
    // 0x8016F700: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x8016F704: sll         $t3, $t3, 5
    ctx->r11 = S32(ctx->r11 << 5);
    // 0x8016F708: addu        $t6, $t3, $t4
    ctx->r14 = ADD32(ctx->r11, ctx->r12);
    // 0x8016F70C: addiu       $t7, $t7, 0x3518
    ctx->r15 = ADD32(ctx->r15, 0X3518);
    // 0x8016F710: addu        $t9, $t6, $t7
    ctx->r25 = ADD32(ctx->r14, ctx->r15);
    // 0x8016F714: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8016F718: beq         $t0, $zero, L_8016F7E4
    if (ctx->r8 == 0) {
        // 0x8016F71C: nop
    
            goto L_8016F7E4;
    }
    // 0x8016F71C: nop

    // 0x8016F720: addu        $t8, $t3, $t4
    ctx->r24 = ADD32(ctx->r11, ctx->r12);
    // 0x8016F724: addu        $t1, $t8, $t7
    ctx->r9 = ADD32(ctx->r24, ctx->r15);
    // 0x8016F728: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x8016F72C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8016F730: beq         $t2, $at, L_8016F7E4
    if (ctx->r10 == ctx->r1) {
        // 0x8016F734: nop
    
            goto L_8016F7E4;
    }
    // 0x8016F734: nop

    // 0x8016F738: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8016F73C: addu        $t6, $t5, $t7
    ctx->r14 = ADD32(ctx->r13, ctx->r15);
    // 0x8016F740: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
    // 0x8016F744: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8016F748: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8016F74C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8016F750: sll         $t1, $t8, 3
    ctx->r9 = S32(ctx->r24 << 3);
    // 0x8016F754: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x8016F758: subu        $t1, $t1, $t8
    ctx->r9 = SUB32(ctx->r9, ctx->r24);
    // 0x8016F75C: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x8016F760: sll         $t0, $t0, 5
    ctx->r8 = S32(ctx->r8 << 5);
    // 0x8016F764: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x8016F768: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8016F76C: addiu       $t3, $t3, 0x3518
    ctx->r11 = ADD32(ctx->r11, 0X3518);
    // 0x8016F770: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8016F774: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x8016F778: addiu       $t4, $zero, 0x10
    ctx->r12 = ADD32(0, 0X10);
    // 0x8016F77C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8016F780: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x8016F784: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x8016F788: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8016F78C: subu        $t7, $t7, $t5
    ctx->r15 = SUB32(ctx->r15, ctx->r13);
    // 0x8016F790: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8016F794: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x8016F798: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8016F79C: addiu       $t6, $t6, -0x2A28
    ctx->r14 = ADD32(ctx->r14, -0X2A28);
    // 0x8016F7A0: sllv        $t5, $t4, $t9
    ctx->r13 = S32(ctx->r12 << (ctx->r25 & 31));
    // 0x8016F7A4: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x8016F7A8: addu        $t4, $t0, $t1
    ctx->r12 = ADD32(ctx->r8, ctx->r9);
    // 0x8016F7AC: lhu         $t2, 0x0($t8)
    ctx->r10 = MEM_HU(ctx->r24, 0X0);
    // 0x8016F7B0: addu        $t9, $t4, $t3
    ctx->r25 = ADD32(ctx->r12, ctx->r11);
    // 0x8016F7B4: xori        $t7, $t5, 0xFFFF
    ctx->r15 = ctx->r13 ^ 0XFFFF;
    // 0x8016F7B8: lw          $t5, 0x4($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X4);
    // 0x8016F7BC: and         $t8, $t2, $t7
    ctx->r24 = ctx->r10 & ctx->r15;
    // 0x8016F7C0: sll         $t2, $t5, 2
    ctx->r10 = S32(ctx->r13 << 2);
    // 0x8016F7C4: addu        $t2, $t2, $t5
    ctx->r10 = ADD32(ctx->r10, ctx->r13);
    // 0x8016F7C8: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8016F7CC: subu        $t2, $t2, $t5
    ctx->r10 = SUB32(ctx->r10, ctx->r13);
    // 0x8016F7D0: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8016F7D4: addu        $t2, $t2, $t5
    ctx->r10 = ADD32(ctx->r10, ctx->r13);
    // 0x8016F7D8: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8016F7DC: addu        $t7, $t2, $t6
    ctx->r15 = ADD32(ctx->r10, ctx->r14);
    // 0x8016F7E0: sh          $t8, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r24;
L_8016F7E4:
    // 0x8016F7E4: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8016F7E8: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8016F7EC: sltiu       $at, $t1, 0x4
    ctx->r1 = ctx->r9 < 0X4 ? 1 : 0;
    // 0x8016F7F0: bne         $at, $zero, L_8016F6E4
    if (ctx->r1 != 0) {
        // 0x8016F7F4: sw          $t1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r9;
            goto L_8016F6E4;
    }
    // 0x8016F7F4: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x8016F7F8: b           L_8016F994
    // 0x8016F7FC: nop

        goto L_8016F994;
    // 0x8016F7FC: nop

L_8016F800:
    // 0x8016F800: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x8016F804: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8016F808: addiu       $t9, $t9, 0x3518
    ctx->r25 = ADD32(ctx->r25, 0X3518);
    // 0x8016F80C: sll         $t3, $t4, 3
    ctx->r11 = S32(ctx->r12 << 3);
    // 0x8016F810: subu        $t3, $t3, $t4
    ctx->r11 = SUB32(ctx->r11, ctx->r12);
    // 0x8016F814: sll         $t3, $t3, 5
    ctx->r11 = S32(ctx->r11 << 5);
    // 0x8016F818: addu        $t5, $t3, $t9
    ctx->r13 = ADD32(ctx->r11, ctx->r25);
    // 0x8016F81C: lw          $t2, 0x0($t5)
    ctx->r10 = MEM_W(ctx->r13, 0X0);
    // 0x8016F820: beq         $t2, $zero, L_8016F860
    if (ctx->r10 == 0) {
        // 0x8016F824: nop
    
            goto L_8016F860;
    }
    // 0x8016F824: nop

    // 0x8016F828: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x8016F82C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8016F830: bne         $t6, $at, L_8016F860
    if (ctx->r14 != ctx->r1) {
        // 0x8016F834: nop
    
            goto L_8016F860;
    }
    // 0x8016F834: nop

    // 0x8016F838: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x8016F83C: jal         0x8016F374
    // 0x8016F840: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8016F374_1501A0(rdram, ctx);
        goto after_2;
    // 0x8016F840: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8016F844: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8016F848: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016F84C: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8016F850: sll         $t0, $t7, 2
    ctx->r8 = S32(ctx->r15 << 2);
    // 0x8016F854: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x8016F858: b           L_8016F994
    // 0x8016F85C: sw          $t8, -0x2B6C($at)
    MEM_W(-0X2B6C, ctx->r1) = ctx->r24;
        goto L_8016F994;
    // 0x8016F85C: sw          $t8, -0x2B6C($at)
    MEM_W(-0X2B6C, ctx->r1) = ctx->r24;
L_8016F860:
    // 0x8016F860: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8016F864: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8016F868: addiu       $t9, $t9, 0x3518
    ctx->r25 = ADD32(ctx->r25, 0X3518);
    // 0x8016F86C: sll         $t3, $t1, 3
    ctx->r11 = S32(ctx->r9 << 3);
    // 0x8016F870: subu        $t3, $t3, $t1
    ctx->r11 = SUB32(ctx->r11, ctx->r9);
    // 0x8016F874: sll         $t3, $t3, 5
    ctx->r11 = S32(ctx->r11 << 5);
    // 0x8016F878: addu        $t2, $t3, $t9
    ctx->r10 = ADD32(ctx->r11, ctx->r25);
    // 0x8016F87C: lw          $t5, 0x38($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X38);
    // 0x8016F880: beq         $t5, $zero, L_8016F8C0
    if (ctx->r13 == 0) {
        // 0x8016F884: nop
    
            goto L_8016F8C0;
    }
    // 0x8016F884: nop

    // 0x8016F888: lw          $t6, 0x40($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X40);
    // 0x8016F88C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8016F890: bne         $t6, $at, L_8016F8C0
    if (ctx->r14 != ctx->r1) {
        // 0x8016F894: nop
    
            goto L_8016F8C0;
    }
    // 0x8016F894: nop

    // 0x8016F898: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x8016F89C: jal         0x8016F374
    // 0x8016F8A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8016F374_1501A0(rdram, ctx);
        goto after_3;
    // 0x8016F8A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x8016F8A4: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8016F8A8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016F8AC: addiu       $t4, $zero, 0x6
    ctx->r12 = ADD32(0, 0X6);
    // 0x8016F8B0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8016F8B4: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8016F8B8: b           L_8016F994
    // 0x8016F8BC: sw          $t4, -0x2B6C($at)
    MEM_W(-0X2B6C, ctx->r1) = ctx->r12;
        goto L_8016F994;
    // 0x8016F8BC: sw          $t4, -0x2B6C($at)
    MEM_W(-0X2B6C, ctx->r1) = ctx->r12;
L_8016F8C0:
    // 0x8016F8C0: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8016F8C4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8016F8C8: addiu       $t9, $t9, 0x3518
    ctx->r25 = ADD32(ctx->r25, 0X3518);
    // 0x8016F8CC: sll         $t3, $t0, 3
    ctx->r11 = S32(ctx->r8 << 3);
    // 0x8016F8D0: subu        $t3, $t3, $t0
    ctx->r11 = SUB32(ctx->r11, ctx->r8);
    // 0x8016F8D4: sll         $t3, $t3, 5
    ctx->r11 = S32(ctx->r11 << 5);
    // 0x8016F8D8: addu        $t5, $t3, $t9
    ctx->r13 = ADD32(ctx->r11, ctx->r25);
    // 0x8016F8DC: lw          $t2, 0x70($t5)
    ctx->r10 = MEM_W(ctx->r13, 0X70);
    // 0x8016F8E0: beq         $t2, $zero, L_8016F920
    if (ctx->r10 == 0) {
        // 0x8016F8E4: nop
    
            goto L_8016F920;
    }
    // 0x8016F8E4: nop

    // 0x8016F8E8: lw          $t6, 0x78($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X78);
    // 0x8016F8EC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8016F8F0: bne         $t6, $at, L_8016F920
    if (ctx->r14 != ctx->r1) {
        // 0x8016F8F4: nop
    
            goto L_8016F920;
    }
    // 0x8016F8F4: nop

    // 0x8016F8F8: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x8016F8FC: jal         0x8016F374
    // 0x8016F900: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8016F374_1501A0(rdram, ctx);
        goto after_4;
    // 0x8016F900: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x8016F904: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8016F908: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016F90C: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x8016F910: sll         $t4, $t7, 2
    ctx->r12 = S32(ctx->r15 << 2);
    // 0x8016F914: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x8016F918: b           L_8016F994
    // 0x8016F91C: sw          $t1, -0x2B6C($at)
    MEM_W(-0X2B6C, ctx->r1) = ctx->r9;
        goto L_8016F994;
    // 0x8016F91C: sw          $t1, -0x2B6C($at)
    MEM_W(-0X2B6C, ctx->r1) = ctx->r9;
L_8016F920:
    // 0x8016F920: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8016F924: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8016F928: addiu       $t9, $t9, 0x3518
    ctx->r25 = ADD32(ctx->r25, 0X3518);
    // 0x8016F92C: sll         $t3, $t8, 3
    ctx->r11 = S32(ctx->r24 << 3);
    // 0x8016F930: subu        $t3, $t3, $t8
    ctx->r11 = SUB32(ctx->r11, ctx->r24);
    // 0x8016F934: sll         $t3, $t3, 5
    ctx->r11 = S32(ctx->r11 << 5);
    // 0x8016F938: addu        $t2, $t3, $t9
    ctx->r10 = ADD32(ctx->r11, ctx->r25);
    // 0x8016F93C: lw          $t5, 0xA8($t2)
    ctx->r13 = MEM_W(ctx->r10, 0XA8);
    // 0x8016F940: beq         $t5, $zero, L_8016F964
    if (ctx->r13 == 0) {
        // 0x8016F944: nop
    
            goto L_8016F964;
    }
    // 0x8016F944: nop

    // 0x8016F948: lw          $t6, 0xB0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0XB0);
    // 0x8016F94C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8016F950: bne         $t6, $at, L_8016F964
    if (ctx->r14 != ctx->r1) {
        // 0x8016F954: nop
    
            goto L_8016F964;
    }
    // 0x8016F954: nop

    // 0x8016F958: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x8016F95C: jal         0x8016F374
    // 0x8016F960: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8016F374_1501A0(rdram, ctx);
        goto after_5;
    // 0x8016F960: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_5:
L_8016F964:
    // 0x8016F964: jal         0x80173864
    // 0x8016F968: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80173864_1501A0(rdram, ctx);
        goto after_6;
    // 0x8016F968: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_6:
    // 0x8016F96C: b           L_8016F994
    // 0x8016F970: nop

        goto L_8016F994;
    // 0x8016F970: nop

L_8016F974:
    // 0x8016F974: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8016F978: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8016F97C: addiu       $t1, $t1, -0x2BA8
    ctx->r9 = ADD32(ctx->r9, -0X2BA8);
    // 0x8016F980: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x8016F984: addu        $t4, $t7, $t1
    ctx->r12 = ADD32(ctx->r15, ctx->r9);
    // 0x8016F988: lw          $t3, 0x3C($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X3C);
    // 0x8016F98C: addiu       $t9, $t3, 0x1
    ctx->r25 = ADD32(ctx->r11, 0X1);
    // 0x8016F990: sw          $t9, 0x3C($t4)
    MEM_W(0X3C, ctx->r12) = ctx->r25;
L_8016F994:
    // 0x8016F994: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016F998: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8016F99C: jr          $ra
    // 0x8016F9A0: nop

    return;
    // 0x8016F9A0: nop

;}
RECOMP_FUNC void func_8016F9A4_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016F9A4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8016F9A8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8016F9AC: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8016F9B0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8016F9B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016F9B8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8016F9BC: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8016F9C0: lw          $t8, -0x2B6C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2B6C);
    // 0x8016F9C4: bne         $t8, $zero, L_8016FB70
    if (ctx->r24 != 0) {
        // 0x8016F9C8: nop
    
            goto L_8016FB70;
    }
    // 0x8016F9C8: nop

    // 0x8016F9CC: jal         0x8016F5A0
    // 0x8016F9D0: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    func_8016F5A0_1501A0(rdram, ctx);
        goto after_0;
    // 0x8016F9D0: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_0:
    // 0x8016F9D4: bne         $v0, $zero, L_8016FBBC
    if (ctx->r2 != 0) {
        // 0x8016F9D8: nop
    
            goto L_8016FBBC;
    }
    // 0x8016F9D8: nop

    // 0x8016F9DC: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8016F9E0: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8016F9E4: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8016F9E8: sll         $t0, $t9, 5
    ctx->r8 = S32(ctx->r25 << 5);
    // 0x8016F9EC: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8016F9F0: lw          $t1, 0x39A0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X39A0);
    // 0x8016F9F4: sll         $t5, $t9, 2
    ctx->r13 = S32(ctx->r25 << 2);
    // 0x8016F9F8: addu        $t5, $t5, $t9
    ctx->r13 = ADD32(ctx->r13, ctx->r25);
    // 0x8016F9FC: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8016FA00: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x8016FA04: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x8016FA08: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8016FA0C: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x8016FA10: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8016FA14: lhu         $t4, -0xD4E($t4)
    ctx->r12 = MEM_HU(ctx->r12, -0XD4E);
    // 0x8016FA18: lhu         $t7, -0x41E0($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X41E0);
    // 0x8016FA1C: and         $t8, $t4, $t7
    ctx->r24 = ctx->r12 & ctx->r15;
    // 0x8016FA20: beq         $t8, $zero, L_8016FA38
    if (ctx->r24 == 0) {
        // 0x8016FA24: nop
    
            goto L_8016FA38;
    }
    // 0x8016FA24: nop

    // 0x8016FA28: jal         0x801738C4
    // 0x8016FA2C: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    func_801738C4_1501A0(rdram, ctx);
        goto after_1;
    // 0x8016FA2C: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_1:
    // 0x8016FA30: b           L_8016FBBC
    // 0x8016FA34: nop

        goto L_8016FBBC;
    // 0x8016FA34: nop

L_8016FA38:
    // 0x8016FA38: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8016FA3C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016FA40: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8016FA44: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8016FA48: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8016FA4C: sw          $t6, -0x2B6C($at)
    MEM_W(-0X2B6C, ctx->r1) = ctx->r14;
    // 0x8016FA50: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_8016FA54:
    // 0x8016FA54: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8016FA58: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x8016FA5C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8016FA60: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x8016FA64: sll         $t4, $t5, 3
    ctx->r12 = S32(ctx->r13 << 3);
    // 0x8016FA68: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x8016FA6C: subu        $t4, $t4, $t5
    ctx->r12 = SUB32(ctx->r12, ctx->r13);
    // 0x8016FA70: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x8016FA74: sll         $t3, $t3, 5
    ctx->r11 = S32(ctx->r11 << 5);
    // 0x8016FA78: addu        $t7, $t3, $t4
    ctx->r15 = ADD32(ctx->r11, ctx->r12);
    // 0x8016FA7C: addiu       $t8, $t8, 0x3518
    ctx->r24 = ADD32(ctx->r24, 0X3518);
    // 0x8016FA80: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8016FA84: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8016FA88: beq         $t0, $zero, L_8016FB54
    if (ctx->r8 == 0) {
        // 0x8016FA8C: nop
    
            goto L_8016FB54;
    }
    // 0x8016FA8C: nop

    // 0x8016FA90: addu        $t6, $t3, $t4
    ctx->r14 = ADD32(ctx->r11, ctx->r12);
    // 0x8016FA94: addu        $t1, $t6, $t8
    ctx->r9 = ADD32(ctx->r14, ctx->r24);
    // 0x8016FA98: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x8016FA9C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8016FAA0: beq         $t2, $at, L_8016FB54
    if (ctx->r10 == ctx->r1) {
        // 0x8016FAA4: nop
    
            goto L_8016FB54;
    }
    // 0x8016FAA4: nop

    // 0x8016FAA8: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8016FAAC: addu        $t7, $t5, $t8
    ctx->r15 = ADD32(ctx->r13, ctx->r24);
    // 0x8016FAB0: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
    // 0x8016FAB4: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8016FAB8: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8016FABC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8016FAC0: sll         $t1, $t6, 3
    ctx->r9 = S32(ctx->r14 << 3);
    // 0x8016FAC4: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x8016FAC8: subu        $t1, $t1, $t6
    ctx->r9 = SUB32(ctx->r9, ctx->r14);
    // 0x8016FACC: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x8016FAD0: sll         $t0, $t0, 5
    ctx->r8 = S32(ctx->r8 << 5);
    // 0x8016FAD4: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x8016FAD8: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8016FADC: addiu       $t3, $t3, 0x3518
    ctx->r11 = ADD32(ctx->r11, 0X3518);
    // 0x8016FAE0: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8016FAE4: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x8016FAE8: addiu       $t4, $zero, 0x10
    ctx->r12 = ADD32(0, 0X10);
    // 0x8016FAEC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8016FAF0: sll         $t8, $t5, 2
    ctx->r24 = S32(ctx->r13 << 2);
    // 0x8016FAF4: addu        $t8, $t8, $t5
    ctx->r24 = ADD32(ctx->r24, ctx->r13);
    // 0x8016FAF8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8016FAFC: subu        $t8, $t8, $t5
    ctx->r24 = SUB32(ctx->r24, ctx->r13);
    // 0x8016FB00: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8016FB04: addu        $t8, $t8, $t5
    ctx->r24 = ADD32(ctx->r24, ctx->r13);
    // 0x8016FB08: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8016FB0C: addiu       $t7, $t7, -0x2A28
    ctx->r15 = ADD32(ctx->r15, -0X2A28);
    // 0x8016FB10: sllv        $t5, $t4, $t9
    ctx->r13 = S32(ctx->r12 << (ctx->r25 & 31));
    // 0x8016FB14: addu        $t6, $t8, $t7
    ctx->r14 = ADD32(ctx->r24, ctx->r15);
    // 0x8016FB18: addu        $t4, $t0, $t1
    ctx->r12 = ADD32(ctx->r8, ctx->r9);
    // 0x8016FB1C: lhu         $t2, 0x0($t6)
    ctx->r10 = MEM_HU(ctx->r14, 0X0);
    // 0x8016FB20: addu        $t9, $t4, $t3
    ctx->r25 = ADD32(ctx->r12, ctx->r11);
    // 0x8016FB24: xori        $t8, $t5, 0xFFFF
    ctx->r24 = ctx->r13 ^ 0XFFFF;
    // 0x8016FB28: lw          $t5, 0x4($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X4);
    // 0x8016FB2C: and         $t6, $t2, $t8
    ctx->r14 = ctx->r10 & ctx->r24;
    // 0x8016FB30: sll         $t2, $t5, 2
    ctx->r10 = S32(ctx->r13 << 2);
    // 0x8016FB34: addu        $t2, $t2, $t5
    ctx->r10 = ADD32(ctx->r10, ctx->r13);
    // 0x8016FB38: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8016FB3C: subu        $t2, $t2, $t5
    ctx->r10 = SUB32(ctx->r10, ctx->r13);
    // 0x8016FB40: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8016FB44: addu        $t2, $t2, $t5
    ctx->r10 = ADD32(ctx->r10, ctx->r13);
    // 0x8016FB48: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8016FB4C: addu        $t8, $t2, $t7
    ctx->r24 = ADD32(ctx->r10, ctx->r15);
    // 0x8016FB50: sh          $t6, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r14;
L_8016FB54:
    // 0x8016FB54: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8016FB58: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8016FB5C: sltiu       $at, $t1, 0x4
    ctx->r1 = ctx->r9 < 0X4 ? 1 : 0;
    // 0x8016FB60: bne         $at, $zero, L_8016FA54
    if (ctx->r1 != 0) {
        // 0x8016FB64: sw          $t1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r9;
            goto L_8016FA54;
    }
    // 0x8016FB64: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x8016FB68: b           L_8016FBBC
    // 0x8016FB6C: nop

        goto L_8016FBBC;
    // 0x8016FB6C: nop

L_8016FB70:
    // 0x8016FB70: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x8016FB74: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8016FB78: addiu       $t9, $t9, 0x3518
    ctx->r25 = ADD32(ctx->r25, 0X3518);
    // 0x8016FB7C: sll         $t3, $t4, 3
    ctx->r11 = S32(ctx->r12 << 3);
    // 0x8016FB80: subu        $t3, $t3, $t4
    ctx->r11 = SUB32(ctx->r11, ctx->r12);
    // 0x8016FB84: sll         $t3, $t3, 5
    ctx->r11 = S32(ctx->r11 << 5);
    // 0x8016FB88: addu        $t5, $t3, $t9
    ctx->r13 = ADD32(ctx->r11, ctx->r25);
    // 0x8016FB8C: lw          $t2, 0x0($t5)
    ctx->r10 = MEM_W(ctx->r13, 0X0);
    // 0x8016FB90: beq         $t2, $zero, L_8016FBB4
    if (ctx->r10 == 0) {
        // 0x8016FB94: nop
    
            goto L_8016FBB4;
    }
    // 0x8016FB94: nop

    // 0x8016FB98: lw          $t7, 0x8($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X8);
    // 0x8016FB9C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8016FBA0: bne         $t7, $at, L_8016FBB4
    if (ctx->r15 != ctx->r1) {
        // 0x8016FBA4: nop
    
            goto L_8016FBB4;
    }
    // 0x8016FBA4: nop

    // 0x8016FBA8: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x8016FBAC: jal         0x8016F374
    // 0x8016FBB0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8016F374_1501A0(rdram, ctx);
        goto after_2;
    // 0x8016FBB0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
L_8016FBB4:
    // 0x8016FBB4: jal         0x80173864
    // 0x8016FBB8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80173864_1501A0(rdram, ctx);
        goto after_3;
    // 0x8016FBB8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
L_8016FBBC:
    // 0x8016FBBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016FBC0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8016FBC4: jr          $ra
    // 0x8016FBC8: nop

    return;
    // 0x8016FBC8: nop

;}
RECOMP_FUNC void func_8016FBCC_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016FBCC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8016FBD0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8016FBD4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8016FBD8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8016FBDC: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8016FBE0: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x8016FBE4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8016FBE8: lw          $t8, 0x39A0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X39A0);
    // 0x8016FBEC: sll         $t2, $t6, 2
    ctx->r10 = S32(ctx->r14 << 2);
    // 0x8016FBF0: addu        $t2, $t2, $t6
    ctx->r10 = ADD32(ctx->r10, ctx->r14);
    // 0x8016FBF4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8016FBF8: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x8016FBFC: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x8016FC00: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8016FC04: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8016FC08: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8016FC0C: lhu         $t1, -0xD4E($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0XD4E);
    // 0x8016FC10: lhu         $t3, -0x41E0($t3)
    ctx->r11 = MEM_HU(ctx->r11, -0X41E0);
    // 0x8016FC14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016FC18: and         $t4, $t1, $t3
    ctx->r12 = ctx->r9 & ctx->r11;
    // 0x8016FC1C: beq         $t4, $zero, L_8016FC90
    if (ctx->r12 == 0) {
        // 0x8016FC20: nop
    
            goto L_8016FC90;
    }
    // 0x8016FC20: nop

    // 0x8016FC24: jal         0x8016F5A0
    // 0x8016FC28: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    func_8016F5A0_1501A0(rdram, ctx);
        goto after_0;
    // 0x8016FC28: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_0:
    // 0x8016FC2C: bne         $v0, $zero, L_8016FCC0
    if (ctx->r2 != 0) {
        // 0x8016FC30: nop
    
            goto L_8016FCC0;
    }
    // 0x8016FC30: nop

    // 0x8016FC34: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x8016FC38: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8016FC3C: addiu       $t8, $t8, -0x2BA8
    ctx->r24 = ADD32(ctx->r24, -0X2BA8);
    // 0x8016FC40: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x8016FC44: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8016FC48: lw          $t0, 0x3C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X3C);
    // 0x8016FC4C: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x8016FC50: beq         $t0, $at, L_8016FCC0
    if (ctx->r8 == ctx->r1) {
        // 0x8016FC54: nop
    
            goto L_8016FCC0;
    }
    // 0x8016FC54: nop

    // 0x8016FC58: addiu       $t2, $t0, 0x1
    ctx->r10 = ADD32(ctx->r8, 0X1);
    // 0x8016FC5C: sw          $t2, 0x3C($t9)
    MEM_W(0X3C, ctx->r25) = ctx->r10;
    // 0x8016FC60: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8016FC64: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8016FC68: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x8016FC6C: sll         $t3, $t1, 2
    ctx->r11 = S32(ctx->r9 << 2);
    // 0x8016FC70: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8016FC74: lw          $t4, -0x2B6C($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2B6C);
    // 0x8016FC78: bne         $t4, $at, L_8016FCC0
    if (ctx->r12 != ctx->r1) {
        // 0x8016FC7C: nop
    
            goto L_8016FCC0;
    }
    // 0x8016FC7C: nop

    // 0x8016FC80: jal         0x800C8544
    // 0x8016FC84: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    func_800C8544(rdram, ctx);
        goto after_1;
    // 0x8016FC84: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_1:
    // 0x8016FC88: b           L_8016FCC0
    // 0x8016FC8C: nop

        goto L_8016FCC0;
    // 0x8016FC8C: nop

L_8016FC90:
    // 0x8016FC90: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8016FC94: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8016FC98: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x8016FC9C: sll         $t5, $t6, 2
    ctx->r13 = S32(ctx->r14 << 2);
    // 0x8016FCA0: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x8016FCA4: lw          $t7, -0x2B6C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2B6C);
    // 0x8016FCA8: bne         $t7, $at, L_8016FCB8
    if (ctx->r15 != ctx->r1) {
        // 0x8016FCAC: nop
    
            goto L_8016FCB8;
    }
    // 0x8016FCAC: nop

    // 0x8016FCB0: jal         0x8016F4A0
    // 0x8016FCB4: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    func_8016F4A0_1501A0(rdram, ctx);
        goto after_2;
    // 0x8016FCB4: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_2:
L_8016FCB8:
    // 0x8016FCB8: jal         0x80173864
    // 0x8016FCBC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80173864_1501A0(rdram, ctx);
        goto after_3;
    // 0x8016FCBC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
L_8016FCC0:
    // 0x8016FCC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016FCC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8016FCC8: jr          $ra
    // 0x8016FCCC: nop

    return;
    // 0x8016FCCC: nop

;}
RECOMP_FUNC void func_8016FCD0_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016FCD0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8016FCD4: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x8016FCD8: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x8016FCDC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8016FCE0: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8016FCE4: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x8016FCE8: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8016FCEC: lw          $t8, 0x39A0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X39A0);
    // 0x8016FCF0: sll         $t2, $t6, 2
    ctx->r10 = S32(ctx->r14 << 2);
    // 0x8016FCF4: addu        $t2, $t2, $t6
    ctx->r10 = ADD32(ctx->r10, ctx->r14);
    // 0x8016FCF8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8016FCFC: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x8016FD00: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x8016FD04: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8016FD08: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8016FD0C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8016FD10: lhu         $t1, -0xD4E($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0XD4E);
    // 0x8016FD14: lhu         $t3, -0x41E0($t3)
    ctx->r11 = MEM_HU(ctx->r11, -0X41E0);
    // 0x8016FD18: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8016FD1C: and         $t4, $t1, $t3
    ctx->r12 = ctx->r9 & ctx->r11;
    // 0x8016FD20: beq         $t4, $zero, L_8016FD94
    if (ctx->r12 == 0) {
        // 0x8016FD24: nop
    
            goto L_8016FD94;
    }
    // 0x8016FD24: nop

    // 0x8016FD28: jal         0x8016F5A0
    // 0x8016FD2C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    func_8016F5A0_1501A0(rdram, ctx);
        goto after_0;
    // 0x8016FD2C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_0:
    // 0x8016FD30: bne         $v0, $zero, L_80170048
    if (ctx->r2 != 0) {
        // 0x8016FD34: nop
    
            goto L_80170048;
    }
    // 0x8016FD34: nop

    // 0x8016FD38: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x8016FD3C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8016FD40: addiu       $t8, $t8, -0x2BA8
    ctx->r24 = ADD32(ctx->r24, -0X2BA8);
    // 0x8016FD44: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x8016FD48: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8016FD4C: lw          $t0, 0x3C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X3C);
    // 0x8016FD50: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x8016FD54: beq         $t0, $at, L_80170048
    if (ctx->r8 == ctx->r1) {
        // 0x8016FD58: nop
    
            goto L_80170048;
    }
    // 0x8016FD58: nop

    // 0x8016FD5C: addiu       $t2, $t0, 0x1
    ctx->r10 = ADD32(ctx->r8, 0X1);
    // 0x8016FD60: sw          $t2, 0x3C($t9)
    MEM_W(0X3C, ctx->r25) = ctx->r10;
    // 0x8016FD64: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x8016FD68: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8016FD6C: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x8016FD70: sll         $t3, $t1, 2
    ctx->r11 = S32(ctx->r9 << 2);
    // 0x8016FD74: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8016FD78: lw          $t4, -0x2B6C($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2B6C);
    // 0x8016FD7C: bne         $t4, $at, L_80170048
    if (ctx->r12 != ctx->r1) {
        // 0x8016FD80: nop
    
            goto L_80170048;
    }
    // 0x8016FD80: nop

    // 0x8016FD84: jal         0x800C8544
    // 0x8016FD88: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    func_800C8544(rdram, ctx);
        goto after_1;
    // 0x8016FD88: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_1:
    // 0x8016FD8C: b           L_80170048
    // 0x8016FD90: nop

        goto L_80170048;
    // 0x8016FD90: nop

L_8016FD94:
    // 0x8016FD94: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8016FD98: lw          $t6, -0x2E3C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2E3C);
    // 0x8016FD9C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8016FDA0: bne         $t6, $at, L_8016FDB4
    if (ctx->r14 != ctx->r1) {
        // 0x8016FDA4: nop
    
            goto L_8016FDB4;
    }
    // 0x8016FDA4: nop

    // 0x8016FDA8: addiu       $t5, $zero, 0x7
    ctx->r13 = ADD32(0, 0X7);
    // 0x8016FDAC: b           L_8016FDBC
    // 0x8016FDB0: sw          $t5, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r13;
        goto L_8016FDBC;
    // 0x8016FDB0: sw          $t5, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r13;
L_8016FDB4:
    // 0x8016FDB4: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8016FDB8: sw          $t7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r15;
L_8016FDBC:
    // 0x8016FDBC: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x8016FDC0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8016FDC4: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x8016FDC8: sll         $t0, $t8, 2
    ctx->r8 = S32(ctx->r24 << 2);
    // 0x8016FDCC: addu        $t2, $t2, $t0
    ctx->r10 = ADD32(ctx->r10, ctx->r8);
    // 0x8016FDD0: lw          $t2, -0x2B6C($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2B6C);
    // 0x8016FDD4: bne         $t2, $at, L_80170040
    if (ctx->r10 != ctx->r1) {
        // 0x8016FDD8: nop
    
            goto L_80170040;
    }
    // 0x8016FDD8: nop

    // 0x8016FDDC: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x8016FDE0: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x8016FDE4: beq         $t9, $zero, L_80170038
    if (ctx->r25 == 0) {
        // 0x8016FDE8: nop
    
            goto L_80170038;
    }
    // 0x8016FDE8: nop

L_8016FDEC:
    // 0x8016FDEC: jal         0x800E4CDC
    // 0x8016FDF0: nop

    func_800E4CDC(rdram, ctx);
        goto after_2;
    // 0x8016FDF0: nop

    after_2:
    // 0x8016FDF4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8016FDF8: addiu       $t1, $t1, 0x3C00
    ctx->r9 = ADD32(ctx->r9, 0X3C00);
    // 0x8016FDFC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8016FE00: sw          $v0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r2;
    // 0x8016FE04: addiu       $t3, $t3, 0x3C00
    ctx->r11 = ADD32(ctx->r11, 0X3C00);
    // 0x8016FE08: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8016FE0C: andi        $t6, $t4, 0x1000
    ctx->r14 = ctx->r12 & 0X1000;
    // 0x8016FE10: beq         $t6, $zero, L_8016FE3C
    if (ctx->r14 == 0) {
        // 0x8016FE14: nop
    
            goto L_8016FE3C;
    }
    // 0x8016FE14: nop

    // 0x8016FE18: jal         0x800E4CDC
    // 0x8016FE1C: nop

    func_800E4CDC(rdram, ctx);
        goto after_3;
    // 0x8016FE1C: nop

    after_3:
    // 0x8016FE20: andi        $t5, $v0, 0xF
    ctx->r13 = ctx->r2 & 0XF;
    // 0x8016FE24: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x8016FE28: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8016FE2C: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x8016FE30: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8016FE34: b           L_8016FE68
    // 0x8016FE38: swc1        $f6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f6.u32l;
        goto L_8016FE68;
    // 0x8016FE38: swc1        $f6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f6.u32l;
L_8016FE3C:
    // 0x8016FE3C: jal         0x800E4CDC
    // 0x8016FE40: nop

    func_800E4CDC(rdram, ctx);
        goto after_4;
    // 0x8016FE40: nop

    after_4:
    // 0x8016FE44: andi        $t8, $v0, 0xF
    ctx->r24 = ctx->r2 & 0XF;
    // 0x8016FE48: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x8016FE4C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8016FE50: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8016FE54: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8016FE58: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8016FE5C: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x8016FE60: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8016FE64: swc1        $f18, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f18.u32l;
L_8016FE68:
    // 0x8016FE68: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8016FE6C: addiu       $t2, $t2, 0x3C00
    ctx->r10 = ADD32(ctx->r10, 0X3C00);
    // 0x8016FE70: lw          $t9, 0x0($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X0);
    // 0x8016FE74: andi        $t1, $t9, 0x2000
    ctx->r9 = ctx->r25 & 0X2000;
    // 0x8016FE78: beq         $t1, $zero, L_8016FEA8
    if (ctx->r9 == 0) {
        // 0x8016FE7C: nop
    
            goto L_8016FEA8;
    }
    // 0x8016FE7C: nop

    // 0x8016FE80: jal         0x800E4CDC
    // 0x8016FE84: nop

    func_800E4CDC(rdram, ctx);
        goto after_5;
    // 0x8016FE84: nop

    after_5:
    // 0x8016FE88: andi        $t3, $v0, 0xF0
    ctx->r11 = ctx->r2 & 0XF0;
    // 0x8016FE8C: sra         $t4, $t3, 4
    ctx->r12 = S32(SIGNED(ctx->r11) >> 4);
    // 0x8016FE90: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x8016FE94: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8016FE98: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x8016FE9C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8016FEA0: b           L_8016FED8
    // 0x8016FEA4: swc1        $f6, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f6.u32l;
        goto L_8016FED8;
    // 0x8016FEA4: swc1        $f6, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f6.u32l;
L_8016FEA8:
    // 0x8016FEA8: jal         0x800E4CDC
    // 0x8016FEAC: nop

    func_800E4CDC(rdram, ctx);
        goto after_6;
    // 0x8016FEAC: nop

    after_6:
    // 0x8016FEB0: andi        $t5, $v0, 0xF0
    ctx->r13 = ctx->r2 & 0XF0;
    // 0x8016FEB4: sra         $t7, $t5, 4
    ctx->r15 = S32(SIGNED(ctx->r13) >> 4);
    // 0x8016FEB8: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x8016FEBC: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8016FEC0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8016FEC4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8016FEC8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8016FECC: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x8016FED0: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8016FED4: swc1        $f18, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f18.u32l;
L_8016FED8:
    // 0x8016FED8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8016FEDC: addiu       $t0, $t0, 0x3C00
    ctx->r8 = ADD32(ctx->r8, 0X3C00);
    // 0x8016FEE0: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x8016FEE4: andi        $t9, $t2, 0x4000
    ctx->r25 = ctx->r10 & 0X4000;
    // 0x8016FEE8: beq         $t9, $zero, L_8016FF18
    if (ctx->r25 == 0) {
        // 0x8016FEEC: nop
    
            goto L_8016FF18;
    }
    // 0x8016FEEC: nop

    // 0x8016FEF0: jal         0x800E4CDC
    // 0x8016FEF4: nop

    func_800E4CDC(rdram, ctx);
        goto after_7;
    // 0x8016FEF4: nop

    after_7:
    // 0x8016FEF8: andi        $t1, $v0, 0xF00
    ctx->r9 = ctx->r2 & 0XF00;
    // 0x8016FEFC: sra         $t3, $t1, 8
    ctx->r11 = S32(SIGNED(ctx->r9) >> 8);
    // 0x8016FF00: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x8016FF04: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8016FF08: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x8016FF0C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8016FF10: b           L_8016FF48
    // 0x8016FF14: swc1        $f6, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->f6.u32l;
        goto L_8016FF48;
    // 0x8016FF14: swc1        $f6, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->f6.u32l;
L_8016FF18:
    // 0x8016FF18: jal         0x800E4CDC
    // 0x8016FF1C: nop

    func_800E4CDC(rdram, ctx);
        goto after_8;
    // 0x8016FF1C: nop

    after_8:
    // 0x8016FF20: andi        $t6, $v0, 0xF00
    ctx->r14 = ctx->r2 & 0XF00;
    // 0x8016FF24: sra         $t5, $t6, 8
    ctx->r13 = S32(SIGNED(ctx->r14) >> 8);
    // 0x8016FF28: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x8016FF2C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8016FF30: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8016FF34: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8016FF38: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8016FF3C: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x8016FF40: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8016FF44: swc1        $f18, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->f18.u32l;
L_8016FF48:
    // 0x8016FF48: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8016FF4C: addiu       $t8, $t8, -0x4198
    ctx->r24 = ADD32(ctx->r24, -0X4198);
    // 0x8016FF50: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    // 0x8016FF54: lwc1        $f6, 0x4($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X4);
    // 0x8016FF58: lwc1        $f8, 0x8($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X8);
    // 0x8016FF5C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8016FF60: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x8016FF64: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8016FF68: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8016FF6C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8016FF70: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8016FF74: lwc1        $f10, 0x0($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8016FF78: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8016FF7C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016FF80: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8016FF84: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8016FF88: lwc1        $f4, -0x2E30($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x8016FF8C: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8016FF90: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x8016FF94: lwc1        $f8, 0xC($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0XC);
    // 0x8016FF98: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8016FF9C: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x8016FFA0: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8016FFA4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8016FFA8: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8016FFAC: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    // 0x8016FFB0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8016FFB4: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x8016FFB8: lwc1        $f16, 0x4($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X4);
    // 0x8016FFBC: lwc1        $f10, 0x10($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X10);
    // 0x8016FFC0: mul.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8016FFC4: nop

    // 0x8016FFC8: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x8016FFCC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8016FFD0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016FFD4: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8016FFD8: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x8016FFDC: lwc1        $f18, 0x8($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X8);
    // 0x8016FFE0: lwc1        $f16, 0x14($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X14);
    // 0x8016FFE4: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
    // 0x8016FFE8: mul.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x8016FFEC: lwc1        $f6, -0x2BCC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2BCC);
    // 0x8016FFF0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8016FFF4: sw          $t2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r10;
    // 0x8016FFF8: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x8016FFFC: mul.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x80170000: lwc1        $f8, -0x2BC8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2BC8);
    // 0x80170004: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80170008: lwc1        $f4, -0x2BC4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2BC4);
    // 0x8017000C: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x80170010: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x80170014: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80170018: jal         0x80187E5C
    // 0x8017001C: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    func_80187E5C_1501A0(rdram, ctx);
        goto after_9;
    // 0x8017001C: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    after_9:
    // 0x80170020: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x80170024: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x80170028: addiu       $t3, $t1, 0x1
    ctx->r11 = ADD32(ctx->r9, 0X1);
    // 0x8017002C: sltu        $at, $t3, $t4
    ctx->r1 = ctx->r11 < ctx->r12 ? 1 : 0;
    // 0x80170030: bne         $at, $zero, L_8016FDEC
    if (ctx->r1 != 0) {
        // 0x80170034: sw          $t3, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r11;
            goto L_8016FDEC;
    }
    // 0x80170034: sw          $t3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r11;
L_80170038:
    // 0x80170038: jal         0x800C8544
    // 0x8017003C: addiu       $a0, $zero, 0x73
    ctx->r4 = ADD32(0, 0X73);
    func_800C8544(rdram, ctx);
        goto after_10;
    // 0x8017003C: addiu       $a0, $zero, 0x73
    ctx->r4 = ADD32(0, 0X73);
    after_10:
L_80170040:
    // 0x80170040: jal         0x80173864
    // 0x80170044: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_80173864_1501A0(rdram, ctx);
        goto after_11;
    // 0x80170044: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_11:
L_80170048:
    // 0x80170048: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8017004C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80170050: jr          $ra
    // 0x80170054: nop

    return;
    // 0x80170054: nop

;}
RECOMP_FUNC void func_80170058_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80170058: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8017005C: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80170060: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x80170064: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80170068: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8017006C: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x80170070: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80170074: lw          $t8, 0x39A0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X39A0);
    // 0x80170078: sll         $t2, $t6, 2
    ctx->r10 = S32(ctx->r14 << 2);
    // 0x8017007C: addu        $t2, $t2, $t6
    ctx->r10 = ADD32(ctx->r10, ctx->r14);
    // 0x80170080: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80170084: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x80170088: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x8017008C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80170090: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80170094: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80170098: lhu         $t1, -0xD4E($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0XD4E);
    // 0x8017009C: lhu         $t3, -0x41E0($t3)
    ctx->r11 = MEM_HU(ctx->r11, -0X41E0);
    // 0x801700A0: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x801700A4: and         $t4, $t1, $t3
    ctx->r12 = ctx->r9 & ctx->r11;
    // 0x801700A8: beq         $t4, $zero, L_8017011C
    if (ctx->r12 == 0) {
        // 0x801700AC: nop
    
            goto L_8017011C;
    }
    // 0x801700AC: nop

    // 0x801700B0: jal         0x8016F5A0
    // 0x801700B4: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    func_8016F5A0_1501A0(rdram, ctx);
        goto after_0;
    // 0x801700B4: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_0:
    // 0x801700B8: bne         $v0, $zero, L_8017058C
    if (ctx->r2 != 0) {
        // 0x801700BC: nop
    
            goto L_8017058C;
    }
    // 0x801700BC: nop

    // 0x801700C0: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x801700C4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x801700C8: addiu       $t8, $t8, -0x2BA8
    ctx->r24 = ADD32(ctx->r24, -0X2BA8);
    // 0x801700CC: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x801700D0: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x801700D4: lw          $t0, 0x3C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X3C);
    // 0x801700D8: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x801700DC: beq         $t0, $at, L_8017058C
    if (ctx->r8 == ctx->r1) {
        // 0x801700E0: nop
    
            goto L_8017058C;
    }
    // 0x801700E0: nop

    // 0x801700E4: addiu       $t2, $t0, 0x1
    ctx->r10 = ADD32(ctx->r8, 0X1);
    // 0x801700E8: sw          $t2, 0x3C($t9)
    MEM_W(0X3C, ctx->r25) = ctx->r10;
    // 0x801700EC: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x801700F0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x801700F4: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x801700F8: sll         $t3, $t1, 2
    ctx->r11 = S32(ctx->r9 << 2);
    // 0x801700FC: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x80170100: lw          $t4, -0x2B6C($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2B6C);
    // 0x80170104: bne         $t4, $at, L_8017058C
    if (ctx->r12 != ctx->r1) {
        // 0x80170108: nop
    
            goto L_8017058C;
    }
    // 0x80170108: nop

    // 0x8017010C: jal         0x800C8544
    // 0x80170110: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    func_800C8544(rdram, ctx);
        goto after_1;
    // 0x80170110: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_1:
    // 0x80170114: b           L_8017058C
    // 0x80170118: nop

        goto L_8017058C;
    // 0x80170118: nop

L_8017011C:
    // 0x8017011C: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x80170120: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80170124: addiu       $t7, $t7, -0x2BA8
    ctx->r15 = ADD32(ctx->r15, -0X2BA8);
    // 0x80170128: sll         $t5, $t6, 2
    ctx->r13 = S32(ctx->r14 << 2);
    // 0x8017012C: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x80170130: lw          $t0, 0x3C($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X3C);
    // 0x80170134: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x80170138: bne         $t0, $at, L_80170584
    if (ctx->r8 != ctx->r1) {
        // 0x8017013C: nop
    
            goto L_80170584;
    }
    // 0x8017013C: nop

    // 0x80170140: lw          $a0, 0x64($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X64);
    // 0x80170144: jal         0x8019C1D0
    // 0x80170148: lw          $a1, 0x74($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X74);
    func_8019C1D0_1501A0(rdram, ctx);
        goto after_2;
    // 0x80170148: lw          $a1, 0x74($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X74);
    after_2:
    // 0x8017014C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80170150: addiu       $t2, $t2, -0x4198
    ctx->r10 = ADD32(ctx->r10, -0X4198);
    // 0x80170154: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x80170158: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017015C: lwc1        $f4, 0x30($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X30);
    // 0x80170160: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80170164: lwc1        $f10, -0x2E30($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x80170168: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8017016C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80170170: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x80170174: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80170178: addiu       $t1, $t1, -0x4198
    ctx->r9 = ADD32(ctx->r9, -0X4198);
    // 0x8017017C: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x80170180: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80170184: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80170188: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017018C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80170190: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x80170194: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80170198: addiu       $t4, $t4, -0x4198
    ctx->r12 = ADD32(ctx->r12, -0X4198);
    // 0x8017019C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801701A0: swc1        $f16, 0x28($t9)
    MEM_W(0X28, ctx->r25) = ctx->f16.u32l;
    // 0x801701A4: lwc1        $f18, 0x34($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X34);
    // 0x801701A8: lwc1        $f8, -0x2E30($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x801701AC: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x801701B0: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x801701B4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801701B8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801701BC: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x801701C0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x801701C4: addiu       $t5, $t5, -0x4198
    ctx->r13 = ADD32(ctx->r13, -0X4198);
    // 0x801701C8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801701CC: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801701D0: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x801701D4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x801701D8: addiu       $t0, $t0, -0x4198
    ctx->r8 = ADD32(ctx->r8, -0X4198);
    // 0x801701DC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x801701E0: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x801701E4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x801701E8: swc1        $f10, 0x2C($t3)
    MEM_W(0X2C, ctx->r11) = ctx->f10.u32l;
    // 0x801701EC: lwc1        $f16, 0x38($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X38);
    // 0x801701F0: lwc1        $f6, -0x2E30($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x801701F4: lui         $at, 0xBFC0
    ctx->r1 = S32(0XBFC0 << 16);
    // 0x801701F8: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x801701FC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80170200: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80170204: addiu       $t2, $t2, -0x4198
    ctx->r10 = ADD32(ctx->r10, -0X4198);
    // 0x80170208: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017020C: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x80170210: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80170214: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80170218: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017021C: addiu       $t1, $t1, -0x4198
    ctx->r9 = ADD32(ctx->r9, -0X4198);
    // 0x80170220: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x80170224: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x80170228: swc1        $f8, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->f8.u32l;
    // 0x8017022C: lwc1        $f10, 0x40($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X40);
    // 0x80170230: lwc1        $f4, -0x2E30($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x80170234: lui         $at, 0xBFC0
    ctx->r1 = S32(0XBFC0 << 16);
    // 0x80170238: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8017023C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80170240: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80170244: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80170248: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8017024C: swc1        $f6, 0x3C($t7)
    MEM_W(0X3C, ctx->r15) = ctx->f6.u32l;
    // 0x80170250: lwc1        $f8, 0x44($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X44);
    // 0x80170254: lwc1        $f18, -0x2E30($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x80170258: lui         $at, 0xBFC0
    ctx->r1 = S32(0XBFC0 << 16);
    // 0x8017025C: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80170260: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80170264: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80170268: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8017026C: swc1        $f4, 0x40($t8)
    MEM_W(0X40, ctx->r24) = ctx->f4.u32l;
    // 0x80170270: lwc1        $f6, 0x48($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X48);
    // 0x80170274: lwc1        $f16, -0x2E30($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x80170278: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x8017027C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80170280: nop

    // 0x80170284: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80170288: swc1        $f18, 0x44($t9)
    MEM_W(0X44, ctx->r25) = ctx->f18.u32l;
    // 0x8017028C: lwc1        $f6, 0x28($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X28);
    // 0x80170290: lwc1        $f4, 0x0($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X0);
    // 0x80170294: lwc1        $f10, 0x3C($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X3C);
    // 0x80170298: lwc1        $f18, 0x4($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X4);
    // 0x8017029C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801702A0: lwc1        $f6, 0x2C($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X2C);
    // 0x801702A4: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x801702A8: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x801702AC: lwc1        $f8, 0x40($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X40);
    // 0x801702B0: add.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x801702B4: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x801702B8: lwc1        $f6, 0x8($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X8);
    // 0x801702BC: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801702C0: lwc1        $f8, 0x30($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X30);
    // 0x801702C4: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x801702C8: lwc1        $f16, 0x44($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X44);
    // 0x801702CC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801702D0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x801702D4: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x801702D8: lwc1        $f8, 0x8($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X8);
    // 0x801702DC: add.s       $f6, $f16, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x801702E0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801702E4: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x801702E8: lwc1        $f16, 0x0($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X0);
    // 0x801702EC: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x801702F0: mul.s       $f6, $f16, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x801702F4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801702F8: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x801702FC: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x80170300: lwc1        $f16, 0x4($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X4);
    // 0x80170304: mul.s       $f6, $f16, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x80170308: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8017030C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80170310: add.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x80170314: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x80170318: lwc1        $f8, 0x8($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X8);
    // 0x8017031C: lwc1        $f6, 0x8($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X8);
    // 0x80170320: lwc1        $f4, -0x2BCC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2BCC);
    // 0x80170324: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80170328: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017032C: lwc1        $f8, -0x2BC8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2BC8);
    // 0x80170330: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80170334: lwc1        $f16, -0x2BC4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2BC4);
    // 0x80170338: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    // 0x8017033C: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
    // 0x80170340: add.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80170344: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x80170348: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x8017034C: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    // 0x80170350: jal         0x80187E5C
    // 0x80170354: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    func_80187E5C_1501A0(rdram, ctx);
        goto after_3;
    // 0x80170354: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    after_3:
    // 0x80170358: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x8017035C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80170360: addiu       $t0, $t0, -0x2BA8
    ctx->r8 = ADD32(ctx->r8, -0X2BA8);
    // 0x80170364: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x80170368: addu        $t8, $t7, $t0
    ctx->r24 = ADD32(ctx->r15, ctx->r8);
    // 0x8017036C: lw          $a0, 0x64($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X64);
    // 0x80170370: jal         0x8019C1D0
    // 0x80170374: lw          $a1, 0x74($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X74);
    func_8019C1D0_1501A0(rdram, ctx);
        goto after_4;
    // 0x80170374: lw          $a1, 0x74($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X74);
    after_4:
    // 0x80170378: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017037C: addiu       $t2, $t2, -0x4198
    ctx->r10 = ADD32(ctx->r10, -0X4198);
    // 0x80170380: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x80170384: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80170388: lwc1        $f10, 0x30($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X30);
    // 0x8017038C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80170390: lwc1        $f4, -0x2E30($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x80170394: mul.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80170398: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017039C: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x801703A0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x801703A4: addiu       $t3, $t3, -0x4198
    ctx->r11 = ADD32(ctx->r11, -0X4198);
    // 0x801703A8: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x801703AC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801703B0: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x801703B4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801703B8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x801703BC: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x801703C0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x801703C4: addiu       $t4, $t4, -0x4198
    ctx->r12 = ADD32(ctx->r12, -0X4198);
    // 0x801703C8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801703CC: swc1        $f8, 0x28($t9)
    MEM_W(0X28, ctx->r25) = ctx->f8.u32l;
    // 0x801703D0: lwc1        $f16, 0x34($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X34);
    // 0x801703D4: lwc1        $f18, -0x2E30($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x801703D8: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x801703DC: mul.s       $f6, $f16, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x801703E0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801703E4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801703E8: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x801703EC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x801703F0: addiu       $t5, $t5, -0x4198
    ctx->r13 = ADD32(ctx->r13, -0X4198);
    // 0x801703F4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801703F8: mul.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x801703FC: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x80170400: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80170404: addiu       $t0, $t0, -0x4198
    ctx->r8 = ADD32(ctx->r8, -0X4198);
    // 0x80170408: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017040C: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x80170410: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80170414: swc1        $f4, 0x2C($t1)
    MEM_W(0X2C, ctx->r9) = ctx->f4.u32l;
    // 0x80170418: lwc1        $f8, 0x38($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X38);
    // 0x8017041C: lwc1        $f6, -0x2E30($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x80170420: lui         $at, 0xBFC0
    ctx->r1 = S32(0XBFC0 << 16);
    // 0x80170424: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80170428: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8017042C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80170430: addiu       $t2, $t2, -0x4198
    ctx->r10 = ADD32(ctx->r10, -0X4198);
    // 0x80170434: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80170438: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x8017043C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80170440: mul.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80170444: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80170448: addiu       $t3, $t3, -0x4198
    ctx->r11 = ADD32(ctx->r11, -0X4198);
    // 0x8017044C: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x80170450: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x80170454: swc1        $f18, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->f18.u32l;
    // 0x80170458: lwc1        $f4, 0x40($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X40);
    // 0x8017045C: lwc1        $f10, -0x2E30($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x80170460: lui         $at, 0xBFC0
    ctx->r1 = S32(0XBFC0 << 16);
    // 0x80170464: mul.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80170468: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017046C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80170470: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80170474: mul.s       $f6, $f16, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x80170478: swc1        $f6, 0x3C($t7)
    MEM_W(0X3C, ctx->r15) = ctx->f6.u32l;
    // 0x8017047C: lwc1        $f18, 0x44($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X44);
    // 0x80170480: lwc1        $f16, -0x2E30($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x80170484: lui         $at, 0xBFC0
    ctx->r1 = S32(0XBFC0 << 16);
    // 0x80170488: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8017048C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80170490: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80170494: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80170498: swc1        $f10, 0x40($t8)
    MEM_W(0X40, ctx->r24) = ctx->f10.u32l;
    // 0x8017049C: lwc1        $f6, 0x48($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X48);
    // 0x801704A0: lwc1        $f8, -0x2E30($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x801704A4: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x801704A8: mul.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x801704AC: nop

    // 0x801704B0: mul.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x801704B4: swc1        $f16, 0x44($t9)
    MEM_W(0X44, ctx->r25) = ctx->f16.u32l;
    // 0x801704B8: lwc1        $f6, 0x28($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X28);
    // 0x801704BC: lwc1        $f10, 0x0($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X0);
    // 0x801704C0: lwc1        $f4, 0x3C($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X3C);
    // 0x801704C4: lwc1        $f16, 0x4($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X4);
    // 0x801704C8: sub.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x801704CC: lwc1        $f6, 0x2C($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X2C);
    // 0x801704D0: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x801704D4: add.s       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x801704D8: lwc1        $f18, 0x40($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X40);
    // 0x801704DC: sub.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x801704E0: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x801704E4: lwc1        $f6, 0x8($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X8);
    // 0x801704E8: add.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801704EC: lwc1        $f18, 0x30($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X30);
    // 0x801704F0: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x801704F4: lwc1        $f8, 0x44($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X44);
    // 0x801704F8: sub.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f18.fl;
    // 0x801704FC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80170500: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x80170504: lwc1        $f18, 0x8($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X8);
    // 0x80170508: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8017050C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80170510: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    // 0x80170514: lwc1        $f8, 0x0($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X0);
    // 0x80170518: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x8017051C: mul.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x80170520: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80170524: add.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80170528: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    // 0x8017052C: lwc1        $f8, 0x4($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X4);
    // 0x80170530: mul.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x80170534: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80170538: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017053C: add.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x80170540: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    // 0x80170544: lwc1        $f18, 0x8($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X8);
    // 0x80170548: lwc1        $f6, 0x8($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X8);
    // 0x8017054C: lwc1        $f10, -0x2BCC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2BCC);
    // 0x80170550: mul.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x80170554: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80170558: lwc1        $f18, -0x2BC8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2BC8);
    // 0x8017055C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80170560: lwc1        $f8, -0x2BC4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2BC4);
    // 0x80170564: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    // 0x80170568: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
    // 0x8017056C: add.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80170570: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x80170574: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    // 0x80170578: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x8017057C: jal         0x80187E5C
    // 0x80170580: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    func_80187E5C_1501A0(rdram, ctx);
        goto after_5;
    // 0x80170580: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    after_5:
L_80170584:
    // 0x80170584: jal         0x80173864
    // 0x80170588: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    func_80173864_1501A0(rdram, ctx);
        goto after_6;
    // 0x80170588: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_6:
L_8017058C:
    // 0x8017058C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80170590: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80170594: jr          $ra
    // 0x80170598: nop

    return;
    // 0x80170598: nop

;}
RECOMP_FUNC void func_8017059C_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017059C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801705A0: lw          $t6, -0x2E3C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2E3C);
    // 0x801705A4: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x801705A8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801705AC: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x801705B0: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x801705B4: bne         $t6, $at, L_801705E8
    if (ctx->r14 != ctx->r1) {
        // 0x801705B8: sw          $s0, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r16;
            goto L_801705E8;
    }
    // 0x801705B8: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x801705BC: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x801705C0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801705C4: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x801705C8: sll         $t8, $t7, 5
    ctx->r24 = S32(ctx->r15 << 5);
    // 0x801705CC: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x801705D0: lw          $t9, 0x39B0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X39B0);
    // 0x801705D4: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x801705D8: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x801705DC: lw          $t1, -0x2D50($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2D50);
    // 0x801705E0: b           L_80170610
    // 0x801705E4: sw          $t1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r9;
        goto L_80170610;
    // 0x801705E4: sw          $t1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r9;
L_801705E8:
    // 0x801705E8: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x801705EC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x801705F0: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x801705F4: sll         $t3, $t2, 5
    ctx->r11 = S32(ctx->r10 << 5);
    // 0x801705F8: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x801705FC: lw          $t4, 0x39B0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X39B0);
    // 0x80170600: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80170604: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80170608: lw          $t6, -0x2D38($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2D38);
    // 0x8017060C: sw          $t6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r14;
L_80170610:
    // 0x80170610: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x80170614: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80170618: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x8017061C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80170620: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80170624: lw          $t0, -0x2B7C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2B7C);
    // 0x80170628: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x8017062C: addu        $t2, $t7, $t1
    ctx->r10 = ADD32(ctx->r15, ctx->r9);
    // 0x80170630: lhu         $s0, 0x0($t2)
    ctx->r16 = MEM_HU(ctx->r10, 0X0);
    // 0x80170634: andi        $t3, $s0, 0xFF00
    ctx->r11 = ctx->r16 & 0XFF00;
    // 0x80170638: or          $s0, $t3, $zero
    ctx->r16 = ctx->r11 | 0;
    // 0x8017063C: beq         $s0, $zero, L_801708E8
    if (ctx->r16 == 0) {
        // 0x80170640: addiu       $at, $zero, 0x100
        ctx->r1 = ADD32(0, 0X100);
            goto L_801708E8;
    }
    // 0x80170640: addiu       $at, $zero, 0x100
    ctx->r1 = ADD32(0, 0X100);
    // 0x80170644: beq         $s0, $at, L_8017073C
    if (ctx->r16 == ctx->r1) {
        // 0x80170648: ori         $at, $zero, 0x8000
        ctx->r1 = 0 | 0X8000;
            goto L_8017073C;
    }
    // 0x80170648: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8017064C: beq         $s0, $at, L_80170664
    if (ctx->r16 == ctx->r1) {
        // 0x80170650: ori         $at, $zero, 0xFF00
        ctx->r1 = 0 | 0XFF00;
            goto L_80170664;
    }
    // 0x80170650: ori         $at, $zero, 0xFF00
    ctx->r1 = 0 | 0XFF00;
    // 0x80170654: beq         $s0, $at, L_80170724
    if (ctx->r16 == ctx->r1) {
        // 0x80170658: nop
    
            goto L_80170724;
    }
    // 0x80170658: nop

    // 0x8017065C: b           L_80170908
    // 0x80170660: nop

        goto L_80170908;
    // 0x80170660: nop

L_80170664:
    // 0x80170664: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x80170668: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017066C: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x80170670: sll         $t5, $t4, 5
    ctx->r13 = S32(ctx->r12 << 5);
    // 0x80170674: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80170678: lw          $t6, 0x39A0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X39A0);
    // 0x8017067C: sll         $t7, $t4, 2
    ctx->r15 = S32(ctx->r12 << 2);
    // 0x80170680: addu        $t7, $t7, $t4
    ctx->r15 = ADD32(ctx->r15, ctx->r12);
    // 0x80170684: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80170688: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8017068C: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x80170690: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80170694: addu        $t1, $t1, $t7
    ctx->r9 = ADD32(ctx->r9, ctx->r15);
    // 0x80170698: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8017069C: lhu         $t0, -0xD50($t0)
    ctx->r8 = MEM_HU(ctx->r8, -0XD50);
    // 0x801706A0: lhu         $t1, -0x41E0($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X41E0);
    // 0x801706A4: and         $t2, $t0, $t1
    ctx->r10 = ctx->r8 & ctx->r9;
    // 0x801706A8: beq         $t2, $zero, L_80170908
    if (ctx->r10 == 0) {
        // 0x801706AC: nop
    
            goto L_80170908;
    }
    // 0x801706AC: nop

    // 0x801706B0: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x801706B4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801706B8: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x801706BC: lw          $t6, -0x2B7C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2B7C);
    // 0x801706C0: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x801706C4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x801706C8: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x801706CC: addu        $t9, $t3, $t8
    ctx->r25 = ADD32(ctx->r11, ctx->r24);
    // 0x801706D0: lhu         $a0, 0x0($t9)
    ctx->r4 = MEM_HU(ctx->r25, 0X0);
    // 0x801706D4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x801706D8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x801706DC: addiu       $t2, $t2, -0x4198
    ctx->r10 = ADD32(ctx->r10, -0X4198);
    // 0x801706E0: addiu       $t1, $t1, -0x4198
    ctx->r9 = ADD32(ctx->r9, -0X4198);
    // 0x801706E4: addiu       $t0, $t0, -0x4198
    ctx->r8 = ADD32(ctx->r8, -0X4198);
    // 0x801706E8: andi        $t7, $a0, 0xFF
    ctx->r15 = ctx->r4 & 0XFF;
    // 0x801706EC: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x801706F0: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x801706F4: lw          $a2, 0x4($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X4);
    // 0x801706F8: jal         0x8019CC88
    // 0x801706FC: lw          $a3, 0x8($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X8);
    func_8019CC88_1501A0(rdram, ctx);
        goto after_0;
    // 0x801706FC: lw          $a3, 0x8($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X8);
    after_0:
    // 0x80170700: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x80170704: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80170708: addiu       $t6, $t6, -0x2BA8
    ctx->r14 = ADD32(ctx->r14, -0X2BA8);
    // 0x8017070C: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80170710: addu        $t3, $t5, $t6
    ctx->r11 = ADD32(ctx->r13, ctx->r14);
    // 0x80170714: lw          $t8, 0x2C($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X2C);
    // 0x80170718: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8017071C: b           L_80170908
    // 0x80170720: sw          $t9, 0x2C($t3)
    MEM_W(0X2C, ctx->r11) = ctx->r25;
        goto L_80170908;
    // 0x80170720: sw          $t9, 0x2C($t3)
    MEM_W(0X2C, ctx->r11) = ctx->r25;
L_80170724:
    // 0x80170724: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x80170728: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017072C: sll         $t0, $t7, 2
    ctx->r8 = S32(ctx->r15 << 2);
    // 0x80170730: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80170734: b           L_80170908
    // 0x80170738: sw          $zero, -0x2B7C($at)
    MEM_W(-0X2B7C, ctx->r1) = 0;
        goto L_80170908;
    // 0x80170738: sw          $zero, -0x2B7C($at)
    MEM_W(-0X2B7C, ctx->r1) = 0;
L_8017073C:
    // 0x8017073C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80170740: lw          $t1, -0x2E3C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2E3C);
    // 0x80170744: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80170748: bne         $t1, $at, L_80170760
    if (ctx->r9 != ctx->r1) {
        // 0x8017074C: nop
    
            goto L_80170760;
    }
    // 0x8017074C: nop

    // 0x80170750: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80170754: addiu       $t2, $t2, 0x3C00
    ctx->r10 = ADD32(ctx->r10, 0X3C00);
    // 0x80170758: b           L_80170770
    // 0x8017075C: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
        goto L_80170770;
    // 0x8017075C: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
L_80170760:
    // 0x80170760: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80170764: addiu       $t5, $t5, 0x3C00
    ctx->r13 = ADD32(ctx->r13, 0X3C00);
    // 0x80170768: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x8017076C: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
L_80170770:
    // 0x80170770: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x80170774: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80170778: addiu       $t9, $t9, -0x2BA8
    ctx->r25 = ADD32(ctx->r25, -0X2BA8);
    // 0x8017077C: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80170780: addu        $t3, $t8, $t9
    ctx->r11 = ADD32(ctx->r24, ctx->r25);
    // 0x80170784: lw          $a0, 0x64($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X64);
    // 0x80170788: jal         0x8019C1D0
    // 0x8017078C: lw          $a1, 0x74($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X74);
    func_8019C1D0_1501A0(rdram, ctx);
        goto after_1;
    // 0x8017078C: lw          $a1, 0x74($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X74);
    after_1:
    // 0x80170790: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x80170794: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80170798: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x8017079C: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x801707A0: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x801707A4: lw          $t2, -0x2B7C($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2B7C);
    // 0x801707A8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x801707AC: addiu       $t8, $t8, -0x4198
    ctx->r24 = ADD32(ctx->r24, -0X4198);
    // 0x801707B0: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    // 0x801707B4: sll         $t4, $t2, 1
    ctx->r12 = S32(ctx->r10 << 1);
    // 0x801707B8: addu        $t5, $t7, $t4
    ctx->r13 = ADD32(ctx->r15, ctx->r12);
    // 0x801707BC: lhu         $a0, 0x0($t5)
    ctx->r4 = MEM_HU(ctx->r13, 0X0);
    // 0x801707C0: lw          $a2, 0x4($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X4);
    // 0x801707C4: lw          $a3, 0x8($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X8);
    // 0x801707C8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x801707CC: lwc1        $f6, 0x4($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X4);
    // 0x801707D0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801707D4: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x801707D8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x801707DC: lwc1        $f8, 0x8($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X8);
    // 0x801707E0: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x801707E4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801707E8: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x801707EC: lwc1        $f10, 0x0($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X0);
    // 0x801707F0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x801707F4: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x801707F8: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x801707FC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80170800: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80170804: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80170808: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x8017080C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80170810: addiu       $t2, $t2, 0x3C00
    ctx->r10 = ADD32(ctx->r10, 0X3C00);
    // 0x80170814: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80170818: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x8017081C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80170820: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x80170824: lwc1        $f8, 0x4($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X4);
    // 0x80170828: lwc1        $f18, 0x4($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X4);
    // 0x8017082C: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80170830: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80170834: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80170838: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8017083C: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x80170840: lwc1        $f6, 0x8($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X8);
    // 0x80170844: lwc1        $f16, 0x8($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X8);
    // 0x80170848: lwc1        $f4, -0x2BCC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2BCC);
    // 0x8017084C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80170850: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80170854: lwc1        $f6, -0x2BC8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2BC8);
    // 0x80170858: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017085C: lwc1        $f8, -0x2BC4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2BC4);
    // 0x80170860: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x80170864: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x80170868: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8017086C: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x80170870: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x80170874: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    // 0x80170878: lw          $t7, 0x0($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X0);
    // 0x8017087C: jal         0x80187E5C
    // 0x80170880: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    func_80187E5C_1501A0(rdram, ctx);
        goto after_2;
    // 0x80170880: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    after_2:
    // 0x80170884: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x80170888: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017088C: addiu       $t6, $t6, 0x39A0
    ctx->r14 = ADD32(ctx->r14, 0X39A0);
    // 0x80170890: sll         $t5, $t4, 5
    ctx->r13 = S32(ctx->r12 << 5);
    // 0x80170894: addu        $t9, $t5, $t6
    ctx->r25 = ADD32(ctx->r13, ctx->r14);
    // 0x80170898: lw          $t3, 0x14($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X14);
    // 0x8017089C: addiu       $at, $zero, 0x270F
    ctx->r1 = ADD32(0, 0X270F);
    // 0x801708A0: beq         $t3, $at, L_801708B0
    if (ctx->r11 == ctx->r1) {
        // 0x801708A4: nop
    
            goto L_801708B0;
    }
    // 0x801708A4: nop

    // 0x801708A8: addiu       $t1, $t3, 0x1
    ctx->r9 = ADD32(ctx->r11, 0X1);
    // 0x801708AC: sw          $t1, 0x14($t9)
    MEM_W(0X14, ctx->r25) = ctx->r9;
L_801708B0:
    // 0x801708B0: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x801708B4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x801708B8: addiu       $t2, $t2, -0x2BA8
    ctx->r10 = ADD32(ctx->r10, -0X2BA8);
    // 0x801708BC: sll         $t0, $t8, 2
    ctx->r8 = S32(ctx->r24 << 2);
    // 0x801708C0: addu        $t7, $t0, $t2
    ctx->r15 = ADD32(ctx->r8, ctx->r10);
    // 0x801708C4: lw          $t4, 0x2C($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X2C);
    // 0x801708C8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801708CC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801708D0: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x801708D4: sw          $t5, 0x2C($t7)
    MEM_W(0X2C, ctx->r15) = ctx->r13;
    // 0x801708D8: lw          $t6, -0x2A40($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2A40);
    // 0x801708DC: addiu       $t3, $t6, 0x1
    ctx->r11 = ADD32(ctx->r14, 0X1);
    // 0x801708E0: b           L_80170908
    // 0x801708E4: sw          $t3, -0x2A40($at)
    MEM_W(-0X2A40, ctx->r1) = ctx->r11;
        goto L_80170908;
    // 0x801708E4: sw          $t3, -0x2A40($at)
    MEM_W(-0X2A40, ctx->r1) = ctx->r11;
L_801708E8:
    // 0x801708E8: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x801708EC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x801708F0: addiu       $t8, $t8, -0x2BA8
    ctx->r24 = ADD32(ctx->r24, -0X2BA8);
    // 0x801708F4: sll         $t9, $t1, 2
    ctx->r25 = S32(ctx->r9 << 2);
    // 0x801708F8: addu        $t0, $t9, $t8
    ctx->r8 = ADD32(ctx->r25, ctx->r24);
    // 0x801708FC: lw          $t2, 0x2C($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X2C);
    // 0x80170900: addiu       $t4, $t2, 0x1
    ctx->r12 = ADD32(ctx->r10, 0X1);
    // 0x80170904: sw          $t4, 0x2C($t0)
    MEM_W(0X2C, ctx->r8) = ctx->r12;
L_80170908:
    // 0x80170908: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8017090C: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x80170910: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80170914: jr          $ra
    // 0x80170918: nop

    return;
    // 0x80170918: nop

;}
RECOMP_FUNC void func_8017091C_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017091C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80170920: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80170924: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80170928: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017092C: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80170930: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x80170934: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80170938: lw          $t8, 0x39A0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X39A0);
    // 0x8017093C: sll         $t2, $t6, 2
    ctx->r10 = S32(ctx->r14 << 2);
    // 0x80170940: addu        $t2, $t2, $t6
    ctx->r10 = ADD32(ctx->r10, ctx->r14);
    // 0x80170944: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80170948: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x8017094C: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x80170950: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80170954: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80170958: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8017095C: lhu         $t1, -0xD4A($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0XD4A);
    // 0x80170960: lhu         $t3, -0x41E0($t3)
    ctx->r11 = MEM_HU(ctx->r11, -0X41E0);
    // 0x80170964: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80170968: and         $t4, $t1, $t3
    ctx->r12 = ctx->r9 & ctx->r11;
    // 0x8017096C: bne         $t4, $zero, L_80170B84
    if (ctx->r12 != 0) {
        // 0x80170970: nop
    
            goto L_80170B84;
    }
    // 0x80170970: nop

    // 0x80170974: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80170978: lw          $t5, -0x2E48($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2E48);
    // 0x8017097C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80170980: beq         $t5, $at, L_80170A30
    if (ctx->r13 == ctx->r1) {
        // 0x80170984: nop
    
            goto L_80170A30;
    }
    // 0x80170984: nop

    // 0x80170988: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017098C: addiu       $t7, $t7, -0x2BA8
    ctx->r15 = ADD32(ctx->r15, -0X2BA8);
    // 0x80170990: lw          $t8, 0x14($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X14);
    // 0x80170994: beq         $t8, $zero, L_80170B84
    if (ctx->r24 == 0) {
        // 0x80170998: nop
    
            goto L_80170B84;
    }
    // 0x80170998: nop

    // 0x8017099C: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x801709A0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801709A4: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x801709A8: sll         $t0, $t9, 5
    ctx->r8 = S32(ctx->r25 << 5);
    // 0x801709AC: addu        $t6, $t6, $t0
    ctx->r14 = ADD32(ctx->r14, ctx->r8);
    // 0x801709B0: lw          $t6, 0x39A0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X39A0);
    // 0x801709B4: sll         $t4, $t9, 2
    ctx->r12 = S32(ctx->r25 << 2);
    // 0x801709B8: addu        $t4, $t4, $t9
    ctx->r12 = ADD32(ctx->r12, ctx->r25);
    // 0x801709BC: sll         $t2, $t6, 2
    ctx->r10 = S32(ctx->r14 << 2);
    // 0x801709C0: sll         $t1, $t2, 1
    ctx->r9 = S32(ctx->r10 << 1);
    // 0x801709C4: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x801709C8: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x801709CC: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x801709D0: addu        $t3, $t3, $t1
    ctx->r11 = ADD32(ctx->r11, ctx->r9);
    // 0x801709D4: lhu         $t3, -0xD4C($t3)
    ctx->r11 = MEM_HU(ctx->r11, -0XD4C);
    // 0x801709D8: lhu         $t5, -0x41DE($t5)
    ctx->r13 = MEM_HU(ctx->r13, -0X41DE);
    // 0x801709DC: and         $t7, $t3, $t5
    ctx->r15 = ctx->r11 & ctx->r13;
    // 0x801709E0: beq         $t7, $zero, L_80170B84
    if (ctx->r15 == 0) {
        // 0x801709E4: nop
    
            goto L_80170B84;
    }
    // 0x801709E4: nop

    // 0x801709E8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x801709EC: addiu       $t8, $t8, -0x2BA8
    ctx->r24 = ADD32(ctx->r24, -0X2BA8);
    // 0x801709F0: lw          $t0, 0x14($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X14);
    // 0x801709F4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x801709F8: addiu       $t2, $t2, -0x2E28
    ctx->r10 = ADD32(ctx->r10, -0X2E28);
    // 0x801709FC: addiu       $t6, $t0, -0x1
    ctx->r14 = ADD32(ctx->r8, -0X1);
    // 0x80170A00: sw          $t6, 0x14($t8)
    MEM_W(0X14, ctx->r24) = ctx->r14;
    // 0x80170A04: lbu         $t1, 0xC($t2)
    ctx->r9 = MEM_BU(ctx->r10, 0XC);
    // 0x80170A08: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80170A0C: addiu       $t3, $t3, -0x2E18
    ctx->r11 = ADD32(ctx->r11, -0X2E18);
    // 0x80170A10: ori         $t9, $t1, 0x4
    ctx->r25 = ctx->r9 | 0X4;
    // 0x80170A14: sb          $t9, 0xC($t2)
    MEM_B(0XC, ctx->r10) = ctx->r25;
    // 0x80170A18: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80170A1C: sw          $t4, 0x34($t3)
    MEM_W(0X34, ctx->r11) = ctx->r12;
    // 0x80170A20: jal         0x80170B94
    // 0x80170A24: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80170B94_1501A0(rdram, ctx);
        goto after_0;
    // 0x80170A24: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_0:
    // 0x80170A28: b           L_80170B84
    // 0x80170A2C: nop

        goto L_80170B84;
    // 0x80170A2C: nop

L_80170A30:
    // 0x80170A30: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x80170A34: andi        $t7, $t5, 0x1
    ctx->r15 = ctx->r13 & 0X1;
    // 0x80170A38: bne         $t7, $zero, L_80170AE4
    if (ctx->r15 != 0) {
        // 0x80170A3C: nop
    
            goto L_80170AE4;
    }
    // 0x80170A3C: nop

    // 0x80170A40: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80170A44: addiu       $t0, $t0, -0x2BA8
    ctx->r8 = ADD32(ctx->r8, -0X2BA8);
    // 0x80170A48: lw          $t6, 0x14($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X14);
    // 0x80170A4C: beq         $t6, $zero, L_80170B84
    if (ctx->r14 == 0) {
        // 0x80170A50: nop
    
            goto L_80170B84;
    }
    // 0x80170A50: nop

    // 0x80170A54: sll         $t8, $t5, 5
    ctx->r24 = S32(ctx->r13 << 5);
    // 0x80170A58: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80170A5C: addu        $t1, $t1, $t8
    ctx->r9 = ADD32(ctx->r9, ctx->r24);
    // 0x80170A60: lw          $t1, 0x39A0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X39A0);
    // 0x80170A64: sll         $t3, $t5, 2
    ctx->r11 = S32(ctx->r13 << 2);
    // 0x80170A68: addu        $t3, $t3, $t5
    ctx->r11 = ADD32(ctx->r11, ctx->r13);
    // 0x80170A6C: sll         $t9, $t1, 2
    ctx->r25 = S32(ctx->r9 << 2);
    // 0x80170A70: sll         $t2, $t9, 1
    ctx->r10 = S32(ctx->r25 << 1);
    // 0x80170A74: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x80170A78: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x80170A7C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80170A80: addu        $t7, $t7, $t3
    ctx->r15 = ADD32(ctx->r15, ctx->r11);
    // 0x80170A84: addu        $t4, $t4, $t2
    ctx->r12 = ADD32(ctx->r12, ctx->r10);
    // 0x80170A88: lhu         $t4, -0xD4C($t4)
    ctx->r12 = MEM_HU(ctx->r12, -0XD4C);
    // 0x80170A8C: lhu         $t7, -0x41DE($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X41DE);
    // 0x80170A90: and         $t0, $t4, $t7
    ctx->r8 = ctx->r12 & ctx->r15;
    // 0x80170A94: beq         $t0, $zero, L_80170B84
    if (ctx->r8 == 0) {
        // 0x80170A98: nop
    
            goto L_80170B84;
    }
    // 0x80170A98: nop

    // 0x80170A9C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80170AA0: addiu       $t6, $t6, -0x2BA8
    ctx->r14 = ADD32(ctx->r14, -0X2BA8);
    // 0x80170AA4: lw          $t8, 0x14($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X14);
    // 0x80170AA8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80170AAC: addiu       $t9, $t9, -0x2E28
    ctx->r25 = ADD32(ctx->r25, -0X2E28);
    // 0x80170AB0: addiu       $t1, $t8, -0x1
    ctx->r9 = ADD32(ctx->r24, -0X1);
    // 0x80170AB4: sw          $t1, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r9;
    // 0x80170AB8: lbu         $t2, 0xC($t9)
    ctx->r10 = MEM_BU(ctx->r25, 0XC);
    // 0x80170ABC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80170AC0: addiu       $t4, $t4, -0x2E18
    ctx->r12 = ADD32(ctx->r12, -0X2E18);
    // 0x80170AC4: ori         $t5, $t2, 0x4
    ctx->r13 = ctx->r10 | 0X4;
    // 0x80170AC8: sb          $t5, 0xC($t9)
    MEM_B(0XC, ctx->r25) = ctx->r13;
    // 0x80170ACC: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80170AD0: sw          $t3, 0x34($t4)
    MEM_W(0X34, ctx->r12) = ctx->r11;
    // 0x80170AD4: jal         0x80170B94
    // 0x80170AD8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80170B94_1501A0(rdram, ctx);
        goto after_1;
    // 0x80170AD8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80170ADC: b           L_80170B84
    // 0x80170AE0: nop

        goto L_80170B84;
    // 0x80170AE0: nop

L_80170AE4:
    // 0x80170AE4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80170AE8: addiu       $t7, $t7, -0x2BA8
    ctx->r15 = ADD32(ctx->r15, -0X2BA8);
    // 0x80170AEC: lw          $t0, 0x18($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X18);
    // 0x80170AF0: beq         $t0, $zero, L_80170B84
    if (ctx->r8 == 0) {
        // 0x80170AF4: nop
    
            goto L_80170B84;
    }
    // 0x80170AF4: nop

    // 0x80170AF8: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80170AFC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80170B00: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80170B04: sll         $t1, $t8, 5
    ctx->r9 = S32(ctx->r24 << 5);
    // 0x80170B08: addu        $t6, $t6, $t1
    ctx->r14 = ADD32(ctx->r14, ctx->r9);
    // 0x80170B0C: lw          $t6, 0x39A0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X39A0);
    // 0x80170B10: sll         $t3, $t8, 2
    ctx->r11 = S32(ctx->r24 << 2);
    // 0x80170B14: addu        $t3, $t3, $t8
    ctx->r11 = ADD32(ctx->r11, ctx->r24);
    // 0x80170B18: sll         $t2, $t6, 2
    ctx->r10 = S32(ctx->r14 << 2);
    // 0x80170B1C: sll         $t5, $t2, 1
    ctx->r13 = S32(ctx->r10 << 1);
    // 0x80170B20: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x80170B24: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80170B28: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x80170B2C: addu        $t9, $t9, $t5
    ctx->r25 = ADD32(ctx->r25, ctx->r13);
    // 0x80170B30: lhu         $t9, -0xD4C($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0XD4C);
    // 0x80170B34: lhu         $t4, -0x41DE($t4)
    ctx->r12 = MEM_HU(ctx->r12, -0X41DE);
    // 0x80170B38: and         $t7, $t9, $t4
    ctx->r15 = ctx->r25 & ctx->r12;
    // 0x80170B3C: beq         $t7, $zero, L_80170B84
    if (ctx->r15 == 0) {
        // 0x80170B40: nop
    
            goto L_80170B84;
    }
    // 0x80170B40: nop

    // 0x80170B44: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80170B48: addiu       $t0, $t0, -0x2BA8
    ctx->r8 = ADD32(ctx->r8, -0X2BA8);
    // 0x80170B4C: lw          $t1, 0x18($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X18);
    // 0x80170B50: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80170B54: addiu       $t2, $t2, -0x2E28
    ctx->r10 = ADD32(ctx->r10, -0X2E28);
    // 0x80170B58: addiu       $t6, $t1, -0x1
    ctx->r14 = ADD32(ctx->r9, -0X1);
    // 0x80170B5C: sw          $t6, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->r14;
    // 0x80170B60: lbu         $t5, 0xC($t2)
    ctx->r13 = MEM_BU(ctx->r10, 0XC);
    // 0x80170B64: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80170B68: addiu       $t9, $t9, -0x2E18
    ctx->r25 = ADD32(ctx->r25, -0X2E18);
    // 0x80170B6C: ori         $t8, $t5, 0x4
    ctx->r24 = ctx->r13 | 0X4;
    // 0x80170B70: sb          $t8, 0xC($t2)
    MEM_B(0XC, ctx->r10) = ctx->r24;
    // 0x80170B74: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80170B78: sw          $t3, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->r11;
    // 0x80170B7C: jal         0x80170B94
    // 0x80170B80: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80170B94_1501A0(rdram, ctx);
        goto after_2;
    // 0x80170B80: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
L_80170B84:
    // 0x80170B84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80170B88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80170B8C: jr          $ra
    // 0x80170B90: nop

    return;
    // 0x80170B90: nop

;}
RECOMP_FUNC void func_80170B94_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80170B94: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80170B98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80170B9C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80170BA0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_80170BA4:
    // 0x80170BA4: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80170BA8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80170BAC: addiu       $t8, $t8, -0x2A28
    ctx->r24 = ADD32(ctx->r24, -0X2A28);
    // 0x80170BB0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80170BB4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80170BB8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80170BBC: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80170BC0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80170BC4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80170BC8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80170BCC: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80170BD0: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x80170BD4: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80170BD8: andi        $t1, $t0, 0x9700
    ctx->r9 = ctx->r8 & 0X9700;
    // 0x80170BDC: bne         $t1, $at, L_80170E38
    if (ctx->r9 != ctx->r1) {
        // 0x80170BE0: lui         $at, 0x4448
        ctx->r1 = S32(0X4448 << 16);
            goto L_80170E38;
    }
    // 0x80170BE0: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x80170BE4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80170BE8: lwc1        $f4, 0x94($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X94);
    // 0x80170BEC: c.le.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl <= ctx->f6.fl;
    // 0x80170BF0: nop

    // 0x80170BF4: bc1f        L_80170E38
    if (!c1cs) {
        // 0x80170BF8: nop
    
            goto L_80170E38;
    }
    // 0x80170BF8: nop

    // 0x80170BFC: lw          $t2, 0x20($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X20);
    // 0x80170C00: sltiu       $at, $t2, 0x191
    ctx->r1 = ctx->r10 < 0X191 ? 1 : 0;
    // 0x80170C04: bne         $at, $zero, L_80170D28
    if (ctx->r1 != 0) {
        // 0x80170C08: nop
    
            goto L_80170D28;
    }
    // 0x80170C08: nop

    // 0x80170C0C: ori         $t3, $t0, 0x200
    ctx->r11 = ctx->r8 | 0X200;
    // 0x80170C10: sh          $t3, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r11;
    // 0x80170C14: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x80170C18: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80170C1C: addiu       $t6, $t6, -0x2A28
    ctx->r14 = ADD32(ctx->r14, -0X2A28);
    // 0x80170C20: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80170C24: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x80170C28: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80170C2C: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x80170C30: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80170C34: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x80170C38: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80170C3C: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80170C40: lw          $t8, 0x20($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X20);
    // 0x80170C44: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80170C48: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80170C4C: addiu       $t1, $t8, -0x190
    ctx->r9 = ADD32(ctx->r24, -0X190);
    // 0x80170C50: sw          $t1, 0x20($t7)
    MEM_W(0X20, ctx->r15) = ctx->r9;
    // 0x80170C54: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80170C58: lw          $t3, -0x2E44($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2E44);
    // 0x80170C5C: sll         $t0, $t2, 2
    ctx->r8 = S32(ctx->r10 << 2);
    // 0x80170C60: addu        $t0, $t0, $t2
    ctx->r8 = ADD32(ctx->r8, ctx->r10);
    // 0x80170C64: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80170C68: subu        $t0, $t0, $t2
    ctx->r8 = SUB32(ctx->r8, ctx->r10);
    // 0x80170C6C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80170C70: addu        $t0, $t0, $t2
    ctx->r8 = ADD32(ctx->r8, ctx->r10);
    // 0x80170C74: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80170C78: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80170C7C: sw          $zero, -0x2A18($at)
    MEM_W(-0X2A18, ctx->r1) = 0;
    // 0x80170C80: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80170C84: bne         $t3, $at, L_80170CCC
    if (ctx->r11 != ctx->r1) {
        // 0x80170C88: nop
    
            goto L_80170CCC;
    }
    // 0x80170C88: nop

    // 0x80170C8C: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80170C90: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80170C94: addiu       $at, $zero, 0x61
    ctx->r1 = ADD32(0, 0X61);
    // 0x80170C98: sll         $t4, $t9, 2
    ctx->r12 = S32(ctx->r25 << 2);
    // 0x80170C9C: addu        $t4, $t4, $t9
    ctx->r12 = ADD32(ctx->r12, ctx->r25);
    // 0x80170CA0: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80170CA4: subu        $t4, $t4, $t9
    ctx->r12 = SUB32(ctx->r12, ctx->r25);
    // 0x80170CA8: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80170CAC: addu        $t4, $t4, $t9
    ctx->r12 = ADD32(ctx->r12, ctx->r25);
    // 0x80170CB0: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80170CB4: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x80170CB8: lw          $t5, -0x2A24($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2A24);
    // 0x80170CBC: bne         $t5, $at, L_80170CCC
    if (ctx->r13 != ctx->r1) {
        // 0x80170CC0: nop
    
            goto L_80170CCC;
    }
    // 0x80170CC0: nop

    // 0x80170CC4: jal         0x800C8544
    // 0x80170CC8: addiu       $a0, $zero, 0x5A
    ctx->r4 = ADD32(0, 0X5A);
    func_800C8544(rdram, ctx);
        goto after_0;
    // 0x80170CC8: addiu       $a0, $zero, 0x5A
    ctx->r4 = ADD32(0, 0X5A);
    after_0:
L_80170CCC:
    // 0x80170CCC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80170CD0: lw          $t6, -0x2E44($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2E44);
    // 0x80170CD4: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80170CD8: bne         $t6, $at, L_80170E38
    if (ctx->r14 != ctx->r1) {
        // 0x80170CDC: nop
    
            goto L_80170E38;
    }
    // 0x80170CDC: nop

    // 0x80170CE0: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80170CE4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80170CE8: addiu       $at, $zero, 0x46
    ctx->r1 = ADD32(0, 0X46);
    // 0x80170CEC: sll         $t1, $t8, 2
    ctx->r9 = S32(ctx->r24 << 2);
    // 0x80170CF0: addu        $t1, $t1, $t8
    ctx->r9 = ADD32(ctx->r9, ctx->r24);
    // 0x80170CF4: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80170CF8: subu        $t1, $t1, $t8
    ctx->r9 = SUB32(ctx->r9, ctx->r24);
    // 0x80170CFC: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80170D00: addu        $t1, $t1, $t8
    ctx->r9 = ADD32(ctx->r9, ctx->r24);
    // 0x80170D04: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80170D08: addu        $t7, $t7, $t1
    ctx->r15 = ADD32(ctx->r15, ctx->r9);
    // 0x80170D0C: lw          $t7, -0x2A24($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2A24);
    // 0x80170D10: bne         $t7, $at, L_80170E38
    if (ctx->r15 != ctx->r1) {
        // 0x80170D14: nop
    
            goto L_80170E38;
    }
    // 0x80170D14: nop

    // 0x80170D18: jal         0x800C8544
    // 0x80170D1C: addiu       $a0, $zero, 0x6C
    ctx->r4 = ADD32(0, 0X6C);
    func_800C8544(rdram, ctx);
        goto after_1;
    // 0x80170D1C: addiu       $a0, $zero, 0x6C
    ctx->r4 = ADD32(0, 0X6C);
    after_1:
    // 0x80170D20: b           L_80170E38
    // 0x80170D24: nop

        goto L_80170E38;
    // 0x80170D24: nop

L_80170D28:
    // 0x80170D28: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80170D2C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80170D30: addiu       $t3, $t3, -0x2A28
    ctx->r11 = ADD32(ctx->r11, -0X2A28);
    // 0x80170D34: sll         $t0, $t2, 2
    ctx->r8 = S32(ctx->r10 << 2);
    // 0x80170D38: addu        $t0, $t0, $t2
    ctx->r8 = ADD32(ctx->r8, ctx->r10);
    // 0x80170D3C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80170D40: subu        $t0, $t0, $t2
    ctx->r8 = SUB32(ctx->r8, ctx->r10);
    // 0x80170D44: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80170D48: addu        $t0, $t0, $t2
    ctx->r8 = ADD32(ctx->r8, ctx->r10);
    // 0x80170D4C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80170D50: addu        $t9, $t0, $t3
    ctx->r25 = ADD32(ctx->r8, ctx->r11);
    // 0x80170D54: lhu         $t4, 0x0($t9)
    ctx->r12 = MEM_HU(ctx->r25, 0X0);
    // 0x80170D58: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80170D5C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80170D60: ori         $t5, $t4, 0x400
    ctx->r13 = ctx->r12 | 0X400;
    // 0x80170D64: sh          $t5, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r13;
    // 0x80170D68: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80170D6C: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80170D70: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80170D74: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80170D78: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x80170D7C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80170D80: subu        $t8, $t8, $t6
    ctx->r24 = SUB32(ctx->r24, ctx->r14);
    // 0x80170D84: sll         $t7, $t1, 2
    ctx->r15 = S32(ctx->r9 << 2);
    // 0x80170D88: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80170D8C: addu        $t7, $t7, $t1
    ctx->r15 = ADD32(ctx->r15, ctx->r9);
    // 0x80170D90: sll         $t0, $t2, 2
    ctx->r8 = S32(ctx->r10 << 2);
    // 0x80170D94: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80170D98: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x80170D9C: addu        $t0, $t0, $t2
    ctx->r8 = ADD32(ctx->r8, ctx->r10);
    // 0x80170DA0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80170DA4: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80170DA8: subu        $t7, $t7, $t1
    ctx->r15 = SUB32(ctx->r15, ctx->r9);
    // 0x80170DAC: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80170DB0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80170DB4: subu        $t0, $t0, $t2
    ctx->r8 = SUB32(ctx->r8, ctx->r10);
    // 0x80170DB8: sw          $zero, -0x2A08($at)
    MEM_W(-0X2A08, ctx->r1) = 0;
    // 0x80170DBC: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80170DC0: addu        $t7, $t7, $t1
    ctx->r15 = ADD32(ctx->r15, ctx->r9);
    // 0x80170DC4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80170DC8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80170DCC: addu        $t0, $t0, $t2
    ctx->r8 = ADD32(ctx->r8, ctx->r10);
    // 0x80170DD0: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80170DD4: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80170DD8: addiu       $t3, $t3, -0x2A28
    ctx->r11 = ADD32(ctx->r11, -0X2A28);
    // 0x80170DDC: addu        $t4, $t0, $t3
    ctx->r12 = ADD32(ctx->r8, ctx->r11);
    // 0x80170DE0: sw          $zero, -0x2A18($at)
    MEM_W(-0X2A18, ctx->r1) = 0;
    // 0x80170DE4: lw          $t5, 0x10($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X10);
    // 0x80170DE8: sw          $t5, 0x28($t4)
    MEM_W(0X28, ctx->r12) = ctx->r13;
    // 0x80170DEC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80170DF0: jal         0x8017CCE4
    // 0x80170DF4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_8017CCE4_1501A0(rdram, ctx);
        goto after_2;
    // 0x80170DF4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80170DF8: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80170DFC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80170E00: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80170E04: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x80170E08: addu        $t6, $t6, $t9
    ctx->r14 = ADD32(ctx->r14, ctx->r25);
    // 0x80170E0C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80170E10: subu        $t6, $t6, $t9
    ctx->r14 = SUB32(ctx->r14, ctx->r25);
    // 0x80170E14: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80170E18: addu        $t6, $t6, $t9
    ctx->r14 = ADD32(ctx->r14, ctx->r25);
    // 0x80170E1C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80170E20: addu        $a1, $a1, $t6
    ctx->r5 = ADD32(ctx->r5, ctx->r14);
    // 0x80170E24: jal         0x80193424
    // 0x80170E28: lw          $a1, -0x2A10($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X2A10);
    func_80193424_1501A0(rdram, ctx);
        goto after_3;
    // 0x80170E28: lw          $a1, -0x2A10($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X2A10);
    after_3:
    // 0x80170E2C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80170E30: jal         0x80193518
    // 0x80170E34: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_80193518_1501A0(rdram, ctx);
        goto after_4;
    // 0x80170E34: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_4:
L_80170E38:
    // 0x80170E38: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80170E3C: addiu       $t1, $t8, 0x1
    ctx->r9 = ADD32(ctx->r24, 0X1);
    // 0x80170E40: sltiu       $at, $t1, 0x30
    ctx->r1 = ctx->r9 < 0X30 ? 1 : 0;
    // 0x80170E44: bne         $at, $zero, L_80170BA4
    if (ctx->r1 != 0) {
        // 0x80170E48: sw          $t1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r9;
            goto L_80170BA4;
    }
    // 0x80170E48: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x80170E4C: jal         0x80189FEC
    // 0x80170E50: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80189FEC_1501A0(rdram, ctx);
        goto after_5;
    // 0x80170E50: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_5:
    // 0x80170E54: jal         0x800C8544
    // 0x80170E58: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    func_800C8544(rdram, ctx);
        goto after_6;
    // 0x80170E58: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    after_6:
    // 0x80170E5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80170E60: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80170E64: jr          $ra
    // 0x80170E68: nop

    return;
    // 0x80170E68: nop

;}
RECOMP_FUNC void func_80170E6C_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80170E6C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80170E70: lw          $t6, -0x2BA0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2BA0);
    // 0x80170E74: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80170E78: lui         $at, 0xF000
    ctx->r1 = S32(0XF000 << 16);
    // 0x80170E7C: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x80170E80: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80170E84: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80170E88: bne         $t7, $zero, L_80170F7C
    if (ctx->r15 != 0) {
        // 0x80170E8C: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_80170F7C;
    }
    // 0x80170E8C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80170E90: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80170E94: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80170E98: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80170E9C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80170EA0: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x80170EA4: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80170EA8: lhu         $t0, -0x41DE($t0)
    ctx->r8 = MEM_HU(ctx->r8, -0X41DE);
    // 0x80170EAC: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x80170EB0: beq         $t1, $zero, L_80170EC8
    if (ctx->r9 == 0) {
        // 0x80170EB4: lui         $at, 0xF000
        ctx->r1 = S32(0XF000 << 16);
            goto L_80170EC8;
    }
    // 0x80170EB4: lui         $at, 0xF000
    ctx->r1 = S32(0XF000 << 16);
    // 0x80170EB8: or          $t2, $t8, $at
    ctx->r10 = ctx->r24 | ctx->r1;
    // 0x80170EBC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80170EC0: b           L_80171144
    // 0x80170EC4: sw          $t2, -0x2BA0($at)
    MEM_W(-0X2BA0, ctx->r1) = ctx->r10;
        goto L_80171144;
    // 0x80170EC4: sw          $t2, -0x2BA0($at)
    MEM_W(-0X2BA0, ctx->r1) = ctx->r10;
L_80170EC8:
    // 0x80170EC8: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80170ECC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80170ED0: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80170ED4: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x80170ED8: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x80170EDC: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x80170EE0: lhu         $t5, -0x41DE($t5)
    ctx->r13 = MEM_HU(ctx->r13, -0X41DE);
    // 0x80170EE4: andi        $t6, $t5, 0x2
    ctx->r14 = ctx->r13 & 0X2;
    // 0x80170EE8: beq         $t6, $zero, L_80170F04
    if (ctx->r14 == 0) {
        // 0x80170EEC: lui         $at, 0xF000
        ctx->r1 = S32(0XF000 << 16);
            goto L_80170F04;
    }
    // 0x80170EEC: lui         $at, 0xF000
    ctx->r1 = S32(0XF000 << 16);
    // 0x80170EF0: ori         $at, $at, 0x10
    ctx->r1 = ctx->r1 | 0X10;
    // 0x80170EF4: or          $t7, $t3, $at
    ctx->r15 = ctx->r11 | ctx->r1;
    // 0x80170EF8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80170EFC: b           L_80171144
    // 0x80170F00: sw          $t7, -0x2BA0($at)
    MEM_W(-0X2BA0, ctx->r1) = ctx->r15;
        goto L_80171144;
    // 0x80170F00: sw          $t7, -0x2BA0($at)
    MEM_W(-0X2BA0, ctx->r1) = ctx->r15;
L_80170F04:
    // 0x80170F04: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80170F08: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80170F0C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80170F10: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80170F14: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x80170F18: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80170F1C: lhu         $t1, -0x41DE($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X41DE);
    // 0x80170F20: andi        $t8, $t1, 0x8
    ctx->r24 = ctx->r9 & 0X8;
    // 0x80170F24: beq         $t8, $zero, L_80170F40
    if (ctx->r24 == 0) {
        // 0x80170F28: lui         $at, 0xF000
        ctx->r1 = S32(0XF000 << 16);
            goto L_80170F40;
    }
    // 0x80170F28: lui         $at, 0xF000
    ctx->r1 = S32(0XF000 << 16);
    // 0x80170F2C: ori         $at, $at, 0x20
    ctx->r1 = ctx->r1 | 0X20;
    // 0x80170F30: or          $t2, $t9, $at
    ctx->r10 = ctx->r25 | ctx->r1;
    // 0x80170F34: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80170F38: b           L_80171144
    // 0x80170F3C: sw          $t2, -0x2BA0($at)
    MEM_W(-0X2BA0, ctx->r1) = ctx->r10;
        goto L_80171144;
    // 0x80170F3C: sw          $t2, -0x2BA0($at)
    MEM_W(-0X2BA0, ctx->r1) = ctx->r10;
L_80170F40:
    // 0x80170F40: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80170F44: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80170F48: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80170F4C: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x80170F50: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x80170F54: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80170F58: lhu         $t6, -0x41DE($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X41DE);
    // 0x80170F5C: andi        $t3, $t6, 0x4
    ctx->r11 = ctx->r14 & 0X4;
    // 0x80170F60: beq         $t3, $zero, L_80171144
    if (ctx->r11 == 0) {
        // 0x80170F64: lui         $at, 0xF000
        ctx->r1 = S32(0XF000 << 16);
            goto L_80171144;
    }
    // 0x80170F64: lui         $at, 0xF000
    ctx->r1 = S32(0XF000 << 16);
    // 0x80170F68: ori         $at, $at, 0x30
    ctx->r1 = ctx->r1 | 0X30;
    // 0x80170F6C: or          $t7, $t4, $at
    ctx->r15 = ctx->r12 | ctx->r1;
    // 0x80170F70: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80170F74: b           L_80171144
    // 0x80170F78: sw          $t7, -0x2BA0($at)
    MEM_W(-0X2BA0, ctx->r1) = ctx->r15;
        goto L_80171144;
    // 0x80170F78: sw          $t7, -0x2BA0($at)
    MEM_W(-0X2BA0, ctx->r1) = ctx->r15;
L_80170F7C:
    // 0x80170F7C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80170F80: lw          $t0, -0x2BA0($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2BA0);
    // 0x80170F84: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80170F88: andi        $t1, $t0, 0xF
    ctx->r9 = ctx->r8 & 0XF;
    // 0x80170F8C: bne         $t1, $t8, L_80171144
    if (ctx->r9 != ctx->r24) {
        // 0x80170F90: nop
    
            goto L_80171144;
    }
    // 0x80170F90: nop

    // 0x80170F94: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80170F98: lw          $s0, -0x2BA0($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X2BA0);
    // 0x80170F9C: andi        $t9, $s0, 0xF0
    ctx->r25 = ctx->r16 & 0XF0;
    // 0x80170FA0: or          $s0, $t9, $zero
    ctx->r16 = ctx->r25 | 0;
    // 0x80170FA4: beq         $s0, $zero, L_80170FCC
    if (ctx->r16 == 0) {
        // 0x80170FA8: addiu       $at, $zero, 0x10
        ctx->r1 = ADD32(0, 0X10);
            goto L_80170FCC;
    }
    // 0x80170FA8: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x80170FAC: beq         $s0, $at, L_8017102C
    if (ctx->r16 == ctx->r1) {
        // 0x80170FB0: addiu       $at, $zero, 0x20
        ctx->r1 = ADD32(0, 0X20);
            goto L_8017102C;
    }
    // 0x80170FB0: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x80170FB4: beq         $s0, $at, L_8017108C
    if (ctx->r16 == ctx->r1) {
        // 0x80170FB8: addiu       $at, $zero, 0x30
        ctx->r1 = ADD32(0, 0X30);
            goto L_8017108C;
    }
    // 0x80170FB8: addiu       $at, $zero, 0x30
    ctx->r1 = ADD32(0, 0X30);
    // 0x80170FBC: beq         $s0, $at, L_801710EC
    if (ctx->r16 == ctx->r1) {
        // 0x80170FC0: nop
    
            goto L_801710EC;
    }
    // 0x80170FC0: nop

    // 0x80170FC4: b           L_80171144
    // 0x80170FC8: nop

        goto L_80171144;
    // 0x80170FC8: nop

L_80170FCC:
    // 0x80170FCC: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80170FD0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80170FD4: sll         $t5, $t2, 2
    ctx->r13 = S32(ctx->r10 << 2);
    // 0x80170FD8: addu        $t5, $t5, $t2
    ctx->r13 = ADD32(ctx->r13, ctx->r10);
    // 0x80170FDC: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x80170FE0: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80170FE4: lhu         $t6, -0x41E0($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X41E0);
    // 0x80170FE8: andi        $t3, $t6, 0x1
    ctx->r11 = ctx->r14 & 0X1;
    // 0x80170FEC: beq         $t3, $zero, L_8017100C
    if (ctx->r11 == 0) {
        // 0x80170FF0: nop
    
            goto L_8017100C;
    }
    // 0x80170FF0: nop

    // 0x80170FF4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80170FF8: lw          $t4, -0x2BA0($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2BA0);
    // 0x80170FFC: lui         $at, 0xF00
    ctx->r1 = S32(0XF00 << 16);
    // 0x80171000: and         $t7, $t4, $at
    ctx->r15 = ctx->r12 & ctx->r1;
    // 0x80171004: beq         $t7, $zero, L_8017101C
    if (ctx->r15 == 0) {
        // 0x80171008: nop
    
            goto L_8017101C;
    }
    // 0x80171008: nop

L_8017100C:
    // 0x8017100C: jal         0x8017177C
    // 0x80171010: nop

    func_8017177C_1501A0(rdram, ctx);
        goto after_0;
    // 0x80171010: nop

    after_0:
    // 0x80171014: b           L_80171144
    // 0x80171018: nop

        goto L_80171144;
    // 0x80171018: nop

L_8017101C:
    // 0x8017101C: jal         0x801711FC
    // 0x80171020: nop

    func_801711FC_1501A0(rdram, ctx);
        goto after_1;
    // 0x80171020: nop

    after_1:
    // 0x80171024: b           L_80171144
    // 0x80171028: nop

        goto L_80171144;
    // 0x80171028: nop

L_8017102C:
    // 0x8017102C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80171030: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80171034: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80171038: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8017103C: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x80171040: addu        $t8, $t8, $t1
    ctx->r24 = ADD32(ctx->r24, ctx->r9);
    // 0x80171044: lhu         $t8, -0x41E0($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X41E0);
    // 0x80171048: andi        $t9, $t8, 0x2
    ctx->r25 = ctx->r24 & 0X2;
    // 0x8017104C: beq         $t9, $zero, L_8017106C
    if (ctx->r25 == 0) {
        // 0x80171050: nop
    
            goto L_8017106C;
    }
    // 0x80171050: nop

    // 0x80171054: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80171058: lw          $t2, -0x2BA0($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2BA0);
    // 0x8017105C: lui         $at, 0xF00
    ctx->r1 = S32(0XF00 << 16);
    // 0x80171060: and         $t5, $t2, $at
    ctx->r13 = ctx->r10 & ctx->r1;
    // 0x80171064: beq         $t5, $zero, L_8017107C
    if (ctx->r13 == 0) {
        // 0x80171068: nop
    
            goto L_8017107C;
    }
    // 0x80171068: nop

L_8017106C:
    // 0x8017106C: jal         0x801717C4
    // 0x80171070: nop

    func_801717C4_1501A0(rdram, ctx);
        goto after_2;
    // 0x80171070: nop

    after_2:
    // 0x80171074: b           L_80171144
    // 0x80171078: nop

        goto L_80171144;
    // 0x80171078: nop

L_8017107C:
    // 0x8017107C: jal         0x8017135C
    // 0x80171080: nop

    func_8017135C_1501A0(rdram, ctx);
        goto after_3;
    // 0x80171080: nop

    after_3:
    // 0x80171084: b           L_80171144
    // 0x80171088: nop

        goto L_80171144;
    // 0x80171088: nop

L_8017108C:
    // 0x8017108C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80171090: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80171094: sll         $t3, $t6, 2
    ctx->r11 = S32(ctx->r14 << 2);
    // 0x80171098: addu        $t3, $t3, $t6
    ctx->r11 = ADD32(ctx->r11, ctx->r14);
    // 0x8017109C: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x801710A0: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x801710A4: lhu         $t4, -0x41E0($t4)
    ctx->r12 = MEM_HU(ctx->r12, -0X41E0);
    // 0x801710A8: andi        $t7, $t4, 0x8
    ctx->r15 = ctx->r12 & 0X8;
    // 0x801710AC: beq         $t7, $zero, L_801710CC
    if (ctx->r15 == 0) {
        // 0x801710B0: nop
    
            goto L_801710CC;
    }
    // 0x801710B0: nop

    // 0x801710B4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x801710B8: lw          $t0, -0x2BA0($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2BA0);
    // 0x801710BC: lui         $at, 0xF00
    ctx->r1 = S32(0XF00 << 16);
    // 0x801710C0: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x801710C4: beq         $t1, $zero, L_801710DC
    if (ctx->r9 == 0) {
        // 0x801710C8: nop
    
            goto L_801710DC;
    }
    // 0x801710C8: nop

L_801710CC:
    // 0x801710CC: jal         0x8017180C
    // 0x801710D0: nop

    func_8017180C_1501A0(rdram, ctx);
        goto after_4;
    // 0x801710D0: nop

    after_4:
    // 0x801710D4: b           L_80171144
    // 0x801710D8: nop

        goto L_80171144;
    // 0x801710D8: nop

L_801710DC:
    // 0x801710DC: jal         0x801714BC
    // 0x801710E0: nop

    func_801714BC_1501A0(rdram, ctx);
        goto after_5;
    // 0x801710E0: nop

    after_5:
    // 0x801710E4: b           L_80171144
    // 0x801710E8: nop

        goto L_80171144;
    // 0x801710E8: nop

L_801710EC:
    // 0x801710EC: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x801710F0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x801710F4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x801710F8: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x801710FC: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x80171100: addu        $t2, $t2, $t9
    ctx->r10 = ADD32(ctx->r10, ctx->r25);
    // 0x80171104: lhu         $t2, -0x41E0($t2)
    ctx->r10 = MEM_HU(ctx->r10, -0X41E0);
    // 0x80171108: andi        $t5, $t2, 0x4
    ctx->r13 = ctx->r10 & 0X4;
    // 0x8017110C: beq         $t5, $zero, L_8017112C
    if (ctx->r13 == 0) {
        // 0x80171110: nop
    
            goto L_8017112C;
    }
    // 0x80171110: nop

    // 0x80171114: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80171118: lw          $t6, -0x2BA0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2BA0);
    // 0x8017111C: lui         $at, 0xF00
    ctx->r1 = S32(0XF00 << 16);
    // 0x80171120: and         $t3, $t6, $at
    ctx->r11 = ctx->r14 & ctx->r1;
    // 0x80171124: beq         $t3, $zero, L_8017113C
    if (ctx->r11 == 0) {
        // 0x80171128: nop
    
            goto L_8017113C;
    }
    // 0x80171128: nop

L_8017112C:
    // 0x8017112C: jal         0x80171854
    // 0x80171130: nop

    func_80171854_1501A0(rdram, ctx);
        goto after_6;
    // 0x80171130: nop

    after_6:
    // 0x80171134: b           L_80171144
    // 0x80171138: nop

        goto L_80171144;
    // 0x80171138: nop

L_8017113C:
    // 0x8017113C: jal         0x8017161C
    // 0x80171140: nop

    func_8017161C_1501A0(rdram, ctx);
        goto after_7;
    // 0x80171140: nop

    after_7:
L_80171144:
    // 0x80171144: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80171148: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8017114C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80171150: jr          $ra
    // 0x80171154: nop

    return;
    // 0x80171154: nop

;}
RECOMP_FUNC void func_80171158_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80171158: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017115C: lw          $t6, -0x2BA0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2BA0);
    // 0x80171160: lui         $at, 0xF000
    ctx->r1 = S32(0XF000 << 16);
    // 0x80171164: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80171168: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x8017116C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80171170: beq         $t7, $zero, L_801711E8
    if (ctx->r15 == 0) {
        // 0x80171174: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_801711E8;
    }
    // 0x80171174: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80171178: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8017117C: lw          $s0, -0x2BA0($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X2BA0);
    // 0x80171180: andi        $t8, $s0, 0xF0
    ctx->r24 = ctx->r16 & 0XF0;
    // 0x80171184: or          $s0, $t8, $zero
    ctx->r16 = ctx->r24 | 0;
    // 0x80171188: beq         $s0, $zero, L_801711B0
    if (ctx->r16 == 0) {
        // 0x8017118C: addiu       $at, $zero, 0x10
        ctx->r1 = ADD32(0, 0X10);
            goto L_801711B0;
    }
    // 0x8017118C: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x80171190: beq         $s0, $at, L_801711C0
    if (ctx->r16 == ctx->r1) {
        // 0x80171194: addiu       $at, $zero, 0x20
        ctx->r1 = ADD32(0, 0X20);
            goto L_801711C0;
    }
    // 0x80171194: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x80171198: beq         $s0, $at, L_801711D0
    if (ctx->r16 == ctx->r1) {
        // 0x8017119C: addiu       $at, $zero, 0x30
        ctx->r1 = ADD32(0, 0X30);
            goto L_801711D0;
    }
    // 0x8017119C: addiu       $at, $zero, 0x30
    ctx->r1 = ADD32(0, 0X30);
    // 0x801711A0: beq         $s0, $at, L_801711E0
    if (ctx->r16 == ctx->r1) {
        // 0x801711A4: nop
    
            goto L_801711E0;
    }
    // 0x801711A4: nop

    // 0x801711A8: b           L_801711E8
    // 0x801711AC: nop

        goto L_801711E8;
    // 0x801711AC: nop

L_801711B0:
    // 0x801711B0: jal         0x8017177C
    // 0x801711B4: nop

    func_8017177C_1501A0(rdram, ctx);
        goto after_0;
    // 0x801711B4: nop

    after_0:
    // 0x801711B8: b           L_801711E8
    // 0x801711BC: nop

        goto L_801711E8;
    // 0x801711BC: nop

L_801711C0:
    // 0x801711C0: jal         0x801717C4
    // 0x801711C4: nop

    func_801717C4_1501A0(rdram, ctx);
        goto after_1;
    // 0x801711C4: nop

    after_1:
    // 0x801711C8: b           L_801711E8
    // 0x801711CC: nop

        goto L_801711E8;
    // 0x801711CC: nop

L_801711D0:
    // 0x801711D0: jal         0x8017180C
    // 0x801711D4: nop

    func_8017180C_1501A0(rdram, ctx);
        goto after_2;
    // 0x801711D4: nop

    after_2:
    // 0x801711D8: b           L_801711E8
    // 0x801711DC: nop

        goto L_801711E8;
    // 0x801711DC: nop

L_801711E0:
    // 0x801711E0: jal         0x80171854
    // 0x801711E4: nop

    func_80171854_1501A0(rdram, ctx);
        goto after_3;
    // 0x801711E4: nop

    after_3:
L_801711E8:
    // 0x801711E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801711EC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801711F0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801711F4: jr          $ra
    // 0x801711F8: nop

    return;
    // 0x801711F8: nop

;}
RECOMP_FUNC void func_801711FC_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801711FC: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80171200: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80171204: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80171208: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017120C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80171210: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80171214: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x80171218: bc1f        L_8017134C
    if (!c1cs) {
        // 0x8017121C: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8017134C;
    }
L_8017121C:
    // 0x8017121C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80171220: lwc1        $f8, -0x2BC0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2BC0);
    // 0x80171224: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80171228: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017122C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80171230: lwc1        $f18, 0x1C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80171234: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80171238: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017123C: addiu       $t6, $t6, -0x4198
    ctx->r14 = ADD32(ctx->r14, -0X4198);
    // 0x80171240: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80171244: swc1        $f16, -0x2BC0($at)
    MEM_W(-0X2BC0, ctx->r1) = ctx->f16.u32l;
    // 0x80171248: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8017124C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80171250: lwc1        $f8, 0x30($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X30);
    // 0x80171254: lwc1        $f16, 0x0($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X0);
    // 0x80171258: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8017125C: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x80171260: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80171264: addiu       $t8, $t8, -0x4198
    ctx->r24 = ADD32(ctx->r24, -0X4198);
    // 0x80171268: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8017126C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80171270: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80171274: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x80171278: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017127C: addiu       $t0, $t0, -0x4198
    ctx->r8 = ADD32(ctx->r8, -0X4198);
    // 0x80171280: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80171284: sub.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x80171288: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x8017128C: swc1        $f18, 0xC8($t7)
    MEM_W(0XC8, ctx->r15) = ctx->f18.u32l;
    // 0x80171290: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80171294: lwc1        $f16, 0x34($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X34);
    // 0x80171298: lwc1        $f18, 0x4($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X4);
    // 0x8017129C: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x801712A0: mul.s       $f10, $f16, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x801712A4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801712A8: sub.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x801712AC: swc1        $f4, 0xCC($t9)
    MEM_W(0XCC, ctx->r25) = ctx->f4.u32l;
    // 0x801712B0: lwc1        $f8, 0x1C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x801712B4: lwc1        $f18, 0x38($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X38);
    // 0x801712B8: lwc1        $f4, 0x8($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X8);
    // 0x801712BC: add.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x801712C0: mul.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x801712C4: sub.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x801712C8: jal         0x80199214
    // 0x801712CC: swc1        $f8, 0xD0($t1)
    MEM_W(0XD0, ctx->r9) = ctx->f8.u32l;
    func_80199214_1501A0(rdram, ctx);
        goto after_0;
    // 0x801712CC: swc1        $f8, 0xD0($t1)
    MEM_W(0XD0, ctx->r9) = ctx->f8.u32l;
    after_0:
    // 0x801712D0: beq         $v0, $zero, L_801712F4
    if (ctx->r2 == 0) {
        // 0x801712D4: nop
    
            goto L_801712F4;
    }
    // 0x801712D4: nop

    // 0x801712D8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x801712DC: lw          $t2, -0x2BA0($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2BA0);
    // 0x801712E0: lui         $at, 0xF00
    ctx->r1 = S32(0XF00 << 16);
    // 0x801712E4: or          $t3, $t2, $at
    ctx->r11 = ctx->r10 | ctx->r1;
    // 0x801712E8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801712EC: b           L_8017134C
    // 0x801712F0: sw          $t3, -0x2BA0($at)
    MEM_W(-0X2BA0, ctx->r1) = ctx->r11;
        goto L_8017134C;
    // 0x801712F0: sw          $t3, -0x2BA0($at)
    MEM_W(-0X2BA0, ctx->r1) = ctx->r11;
L_801712F4:
    // 0x801712F4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801712F8: lwc1        $f16, -0x2BC0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2BC0);
    // 0x801712FC: lui         $at, 0x41B8
    ctx->r1 = S32(0X41B8 << 16);
    // 0x80171300: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80171304: nop

    // 0x80171308: c.le.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl <= ctx->f16.fl;
    // 0x8017130C: nop

    // 0x80171310: bc1f        L_80171324
    if (!c1cs) {
        // 0x80171314: lui         $at, 0x41B8
        ctx->r1 = S32(0X41B8 << 16);
            goto L_80171324;
    }
    // 0x80171314: lui         $at, 0x41B8
    ctx->r1 = S32(0X41B8 << 16);
    // 0x80171318: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017131C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80171320: swc1        $f6, -0x2BC0($at)
    MEM_W(-0X2BC0, ctx->r1) = ctx->f6.u32l;
L_80171324:
    // 0x80171324: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80171328: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017132C: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80171330: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80171334: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80171338: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8017133C: c.lt.s      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.fl < ctx->f16.fl;
    // 0x80171340: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x80171344: bc1t        L_8017121C
    if (c1cs) {
        // 0x80171348: nop
    
            goto L_8017121C;
    }
    // 0x80171348: nop

L_8017134C:
    // 0x8017134C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80171350: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80171354: jr          $ra
    // 0x80171358: nop

    return;
    // 0x80171358: nop

;}
RECOMP_FUNC void func_8017135C_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017135C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80171360: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80171364: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80171368: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017136C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80171370: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80171374: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x80171378: bc1f        L_801714AC
    if (!c1cs) {
        // 0x8017137C: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_801714AC;
    }
L_8017137C:
    // 0x8017137C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80171380: lwc1        $f8, -0x2BC0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2BC0);
    // 0x80171384: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80171388: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017138C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80171390: lwc1        $f18, 0x1C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80171394: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80171398: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017139C: addiu       $t6, $t6, -0x4198
    ctx->r14 = ADD32(ctx->r14, -0X4198);
    // 0x801713A0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801713A4: swc1        $f16, -0x2BC0($at)
    MEM_W(-0X2BC0, ctx->r1) = ctx->f16.u32l;
    // 0x801713A8: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801713AC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801713B0: lwc1        $f8, 0x30($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X30);
    // 0x801713B4: lwc1        $f16, 0x0($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X0);
    // 0x801713B8: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801713BC: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x801713C0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x801713C4: addiu       $t8, $t8, -0x4198
    ctx->r24 = ADD32(ctx->r24, -0X4198);
    // 0x801713C8: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x801713CC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801713D0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801713D4: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x801713D8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x801713DC: addiu       $t0, $t0, -0x4198
    ctx->r8 = ADD32(ctx->r8, -0X4198);
    // 0x801713E0: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x801713E4: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801713E8: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x801713EC: swc1        $f18, 0xC8($t7)
    MEM_W(0XC8, ctx->r15) = ctx->f18.u32l;
    // 0x801713F0: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x801713F4: lwc1        $f10, 0x34($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X34);
    // 0x801713F8: lwc1        $f18, 0x4($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X4);
    // 0x801713FC: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80171400: mul.s       $f16, $f10, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80171404: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80171408: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8017140C: swc1        $f4, 0xCC($t9)
    MEM_W(0XCC, ctx->r25) = ctx->f4.u32l;
    // 0x80171410: lwc1        $f8, 0x1C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80171414: lwc1        $f16, 0x38($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X38);
    // 0x80171418: lwc1        $f4, 0x8($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X8);
    // 0x8017141C: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80171420: mul.s       $f18, $f16, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x80171424: add.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80171428: jal         0x80199214
    // 0x8017142C: swc1        $f8, 0xD0($t1)
    MEM_W(0XD0, ctx->r9) = ctx->f8.u32l;
    func_80199214_1501A0(rdram, ctx);
        goto after_0;
    // 0x8017142C: swc1        $f8, 0xD0($t1)
    MEM_W(0XD0, ctx->r9) = ctx->f8.u32l;
    after_0:
    // 0x80171430: beq         $v0, $zero, L_80171454
    if (ctx->r2 == 0) {
        // 0x80171434: nop
    
            goto L_80171454;
    }
    // 0x80171434: nop

    // 0x80171438: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017143C: lw          $t2, -0x2BA0($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2BA0);
    // 0x80171440: lui         $at, 0xF00
    ctx->r1 = S32(0XF00 << 16);
    // 0x80171444: or          $t3, $t2, $at
    ctx->r11 = ctx->r10 | ctx->r1;
    // 0x80171448: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017144C: b           L_801714AC
    // 0x80171450: sw          $t3, -0x2BA0($at)
    MEM_W(-0X2BA0, ctx->r1) = ctx->r11;
        goto L_801714AC;
    // 0x80171450: sw          $t3, -0x2BA0($at)
    MEM_W(-0X2BA0, ctx->r1) = ctx->r11;
L_80171454:
    // 0x80171454: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80171458: lwc1        $f10, -0x2BC0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2BC0);
    // 0x8017145C: lui         $at, 0xC1B8
    ctx->r1 = S32(0XC1B8 << 16);
    // 0x80171460: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80171464: nop

    // 0x80171468: c.le.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl <= ctx->f16.fl;
    // 0x8017146C: nop

    // 0x80171470: bc1f        L_80171484
    if (!c1cs) {
        // 0x80171474: lui         $at, 0xC1B8
        ctx->r1 = S32(0XC1B8 << 16);
            goto L_80171484;
    }
    // 0x80171474: lui         $at, 0xC1B8
    ctx->r1 = S32(0XC1B8 << 16);
    // 0x80171478: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017147C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80171480: swc1        $f6, -0x2BC0($at)
    MEM_W(-0X2BC0, ctx->r1) = ctx->f6.u32l;
L_80171484:
    // 0x80171484: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80171488: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017148C: lwc1        $f18, 0x1C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80171490: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80171494: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80171498: add.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8017149C: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x801714A0: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x801714A4: bc1t        L_8017137C
    if (c1cs) {
        // 0x801714A8: nop
    
            goto L_8017137C;
    }
    // 0x801714A8: nop

L_801714AC:
    // 0x801714AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801714B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801714B4: jr          $ra
    // 0x801714B8: nop

    return;
    // 0x801714B8: nop

;}
RECOMP_FUNC void func_801714BC_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801714BC: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x801714C0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801714C4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801714C8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801714CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801714D0: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x801714D4: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x801714D8: bc1f        L_8017160C
    if (!c1cs) {
        // 0x801714DC: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8017160C;
    }
L_801714DC:
    // 0x801714DC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801714E0: lwc1        $f8, -0x2BBC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2BBC);
    // 0x801714E4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801714E8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801714EC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801714F0: lwc1        $f18, 0x1C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x801714F4: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801714F8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801714FC: addiu       $t6, $t6, -0x4198
    ctx->r14 = ADD32(ctx->r14, -0X4198);
    // 0x80171500: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80171504: swc1        $f16, -0x2BBC($at)
    MEM_W(-0X2BBC, ctx->r1) = ctx->f16.u32l;
    // 0x80171508: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8017150C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80171510: lwc1        $f8, 0x40($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X40);
    // 0x80171514: lwc1        $f16, 0x0($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X0);
    // 0x80171518: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8017151C: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x80171520: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80171524: addiu       $t8, $t8, -0x4198
    ctx->r24 = ADD32(ctx->r24, -0X4198);
    // 0x80171528: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8017152C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80171530: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80171534: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x80171538: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017153C: addiu       $t0, $t0, -0x4198
    ctx->r8 = ADD32(ctx->r8, -0X4198);
    // 0x80171540: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80171544: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80171548: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x8017154C: swc1        $f18, 0xC8($t7)
    MEM_W(0XC8, ctx->r15) = ctx->f18.u32l;
    // 0x80171550: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80171554: lwc1        $f10, 0x44($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X44);
    // 0x80171558: lwc1        $f18, 0x4($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X4);
    // 0x8017155C: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80171560: mul.s       $f16, $f10, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80171564: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80171568: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8017156C: swc1        $f4, 0xCC($t9)
    MEM_W(0XCC, ctx->r25) = ctx->f4.u32l;
    // 0x80171570: lwc1        $f8, 0x1C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80171574: lwc1        $f16, 0x48($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X48);
    // 0x80171578: lwc1        $f4, 0x8($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X8);
    // 0x8017157C: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80171580: mul.s       $f18, $f16, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x80171584: add.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80171588: jal         0x80199214
    // 0x8017158C: swc1        $f8, 0xD0($t1)
    MEM_W(0XD0, ctx->r9) = ctx->f8.u32l;
    func_80199214_1501A0(rdram, ctx);
        goto after_0;
    // 0x8017158C: swc1        $f8, 0xD0($t1)
    MEM_W(0XD0, ctx->r9) = ctx->f8.u32l;
    after_0:
    // 0x80171590: beq         $v0, $zero, L_801715B4
    if (ctx->r2 == 0) {
        // 0x80171594: nop
    
            goto L_801715B4;
    }
    // 0x80171594: nop

    // 0x80171598: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017159C: lw          $t2, -0x2BA0($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2BA0);
    // 0x801715A0: lui         $at, 0xF00
    ctx->r1 = S32(0XF00 << 16);
    // 0x801715A4: or          $t3, $t2, $at
    ctx->r11 = ctx->r10 | ctx->r1;
    // 0x801715A8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801715AC: b           L_8017160C
    // 0x801715B0: sw          $t3, -0x2BA0($at)
    MEM_W(-0X2BA0, ctx->r1) = ctx->r11;
        goto L_8017160C;
    // 0x801715B0: sw          $t3, -0x2BA0($at)
    MEM_W(-0X2BA0, ctx->r1) = ctx->r11;
L_801715B4:
    // 0x801715B4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801715B8: lwc1        $f10, -0x2BBC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2BBC);
    // 0x801715BC: lui         $at, 0x41B8
    ctx->r1 = S32(0X41B8 << 16);
    // 0x801715C0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801715C4: nop

    // 0x801715C8: c.le.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl <= ctx->f10.fl;
    // 0x801715CC: nop

    // 0x801715D0: bc1f        L_801715E4
    if (!c1cs) {
        // 0x801715D4: lui         $at, 0x41B8
        ctx->r1 = S32(0X41B8 << 16);
            goto L_801715E4;
    }
    // 0x801715D4: lui         $at, 0x41B8
    ctx->r1 = S32(0X41B8 << 16);
    // 0x801715D8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801715DC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801715E0: swc1        $f6, -0x2BBC($at)
    MEM_W(-0X2BBC, ctx->r1) = ctx->f6.u32l;
L_801715E4:
    // 0x801715E4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801715E8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801715EC: lwc1        $f18, 0x1C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x801715F0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x801715F4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801715F8: add.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801715FC: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80171600: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x80171604: bc1t        L_801714DC
    if (c1cs) {
        // 0x80171608: nop
    
            goto L_801714DC;
    }
    // 0x80171608: nop

L_8017160C:
    // 0x8017160C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80171610: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80171614: jr          $ra
    // 0x80171618: nop

    return;
    // 0x80171618: nop

;}
RECOMP_FUNC void func_8017161C_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017161C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80171620: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80171624: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80171628: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017162C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80171630: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80171634: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x80171638: bc1f        L_8017176C
    if (!c1cs) {
        // 0x8017163C: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8017176C;
    }
L_8017163C:
    // 0x8017163C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80171640: lwc1        $f8, -0x2BBC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2BBC);
    // 0x80171644: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80171648: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017164C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80171650: lwc1        $f18, 0x1C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80171654: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80171658: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017165C: addiu       $t6, $t6, -0x4198
    ctx->r14 = ADD32(ctx->r14, -0X4198);
    // 0x80171660: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80171664: swc1        $f16, -0x2BBC($at)
    MEM_W(-0X2BBC, ctx->r1) = ctx->f16.u32l;
    // 0x80171668: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8017166C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80171670: lwc1        $f8, 0x40($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X40);
    // 0x80171674: lwc1        $f16, 0x0($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X0);
    // 0x80171678: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8017167C: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x80171680: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80171684: addiu       $t8, $t8, -0x4198
    ctx->r24 = ADD32(ctx->r24, -0X4198);
    // 0x80171688: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8017168C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80171690: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80171694: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x80171698: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017169C: addiu       $t0, $t0, -0x4198
    ctx->r8 = ADD32(ctx->r8, -0X4198);
    // 0x801716A0: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x801716A4: sub.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x801716A8: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x801716AC: swc1        $f18, 0xC8($t7)
    MEM_W(0XC8, ctx->r15) = ctx->f18.u32l;
    // 0x801716B0: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x801716B4: lwc1        $f16, 0x44($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X44);
    // 0x801716B8: lwc1        $f18, 0x4($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X4);
    // 0x801716BC: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x801716C0: mul.s       $f10, $f16, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x801716C4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801716C8: sub.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x801716CC: swc1        $f4, 0xCC($t9)
    MEM_W(0XCC, ctx->r25) = ctx->f4.u32l;
    // 0x801716D0: lwc1        $f8, 0x1C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x801716D4: lwc1        $f18, 0x48($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X48);
    // 0x801716D8: lwc1        $f4, 0x8($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X8);
    // 0x801716DC: add.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x801716E0: mul.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x801716E4: sub.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x801716E8: jal         0x80199214
    // 0x801716EC: swc1        $f8, 0xD0($t1)
    MEM_W(0XD0, ctx->r9) = ctx->f8.u32l;
    func_80199214_1501A0(rdram, ctx);
        goto after_0;
    // 0x801716EC: swc1        $f8, 0xD0($t1)
    MEM_W(0XD0, ctx->r9) = ctx->f8.u32l;
    after_0:
    // 0x801716F0: beq         $v0, $zero, L_80171714
    if (ctx->r2 == 0) {
        // 0x801716F4: nop
    
            goto L_80171714;
    }
    // 0x801716F4: nop

    // 0x801716F8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x801716FC: lw          $t2, -0x2BA0($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2BA0);
    // 0x80171700: lui         $at, 0xF00
    ctx->r1 = S32(0XF00 << 16);
    // 0x80171704: or          $t3, $t2, $at
    ctx->r11 = ctx->r10 | ctx->r1;
    // 0x80171708: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017170C: b           L_8017176C
    // 0x80171710: sw          $t3, -0x2BA0($at)
    MEM_W(-0X2BA0, ctx->r1) = ctx->r11;
        goto L_8017176C;
    // 0x80171710: sw          $t3, -0x2BA0($at)
    MEM_W(-0X2BA0, ctx->r1) = ctx->r11;
L_80171714:
    // 0x80171714: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80171718: lwc1        $f16, -0x2BBC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2BBC);
    // 0x8017171C: lui         $at, 0xC1B8
    ctx->r1 = S32(0XC1B8 << 16);
    // 0x80171720: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80171724: nop

    // 0x80171728: c.le.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl <= ctx->f18.fl;
    // 0x8017172C: nop

    // 0x80171730: bc1f        L_80171744
    if (!c1cs) {
        // 0x80171734: lui         $at, 0xC1B8
        ctx->r1 = S32(0XC1B8 << 16);
            goto L_80171744;
    }
    // 0x80171734: lui         $at, 0xC1B8
    ctx->r1 = S32(0XC1B8 << 16);
    // 0x80171738: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017173C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80171740: swc1        $f6, -0x2BBC($at)
    MEM_W(-0X2BBC, ctx->r1) = ctx->f6.u32l;
L_80171744:
    // 0x80171744: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80171748: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017174C: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80171750: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80171754: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80171758: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8017175C: c.lt.s      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.fl < ctx->f16.fl;
    // 0x80171760: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x80171764: bc1t        L_8017163C
    if (c1cs) {
        // 0x80171768: nop
    
            goto L_8017163C;
    }
    // 0x80171768: nop

L_8017176C:
    // 0x8017176C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80171770: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80171774: jr          $ra
    // 0x80171778: nop

    return;
    // 0x80171778: nop

;}
RECOMP_FUNC void func_8017177C_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017177C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80171780: lwc1        $f4, -0x2BC0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2BC0);
    // 0x80171784: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80171788: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017178C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80171790: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80171794: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80171798: c.le.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl <= ctx->f10.fl;
    // 0x8017179C: swc1        $f8, -0x2BC0($at)
    MEM_W(-0X2BC0, ctx->r1) = ctx->f8.u32l;
    // 0x801717A0: bc1f        L_801717BC
    if (!c1cs) {
        // 0x801717A4: nop
    
            goto L_801717BC;
    }
    // 0x801717A4: nop

    // 0x801717A8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801717AC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801717B0: swc1        $f16, -0x2BC0($at)
    MEM_W(-0X2BC0, ctx->r1) = ctx->f16.u32l;
    // 0x801717B4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801717B8: sw          $zero, -0x2BA0($at)
    MEM_W(-0X2BA0, ctx->r1) = 0;
L_801717BC:
    // 0x801717BC: jr          $ra
    // 0x801717C0: nop

    return;
    // 0x801717C0: nop

;}
RECOMP_FUNC void func_801717C4_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801717C4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801717C8: lwc1        $f4, -0x2BC0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2BC0);
    // 0x801717CC: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x801717D0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801717D4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801717D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801717DC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801717E0: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x801717E4: swc1        $f8, -0x2BC0($at)
    MEM_W(-0X2BC0, ctx->r1) = ctx->f8.u32l;
    // 0x801717E8: bc1f        L_80171804
    if (!c1cs) {
        // 0x801717EC: nop
    
            goto L_80171804;
    }
    // 0x801717EC: nop

    // 0x801717F0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801717F4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801717F8: swc1        $f16, -0x2BC0($at)
    MEM_W(-0X2BC0, ctx->r1) = ctx->f16.u32l;
    // 0x801717FC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80171800: sw          $zero, -0x2BA0($at)
    MEM_W(-0X2BA0, ctx->r1) = 0;
L_80171804:
    // 0x80171804: jr          $ra
    // 0x80171808: nop

    return;
    // 0x80171808: nop

;}
RECOMP_FUNC void func_8017180C_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017180C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80171810: lwc1        $f4, -0x2BBC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2BBC);
    // 0x80171814: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80171818: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017181C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80171820: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80171824: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80171828: c.le.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl <= ctx->f10.fl;
    // 0x8017182C: swc1        $f8, -0x2BBC($at)
    MEM_W(-0X2BBC, ctx->r1) = ctx->f8.u32l;
    // 0x80171830: bc1f        L_8017184C
    if (!c1cs) {
        // 0x80171834: nop
    
            goto L_8017184C;
    }
    // 0x80171834: nop

    // 0x80171838: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8017183C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80171840: swc1        $f16, -0x2BBC($at)
    MEM_W(-0X2BBC, ctx->r1) = ctx->f16.u32l;
    // 0x80171844: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80171848: sw          $zero, -0x2BA0($at)
    MEM_W(-0X2BA0, ctx->r1) = 0;
L_8017184C:
    // 0x8017184C: jr          $ra
    // 0x80171850: nop

    return;
    // 0x80171850: nop

;}
RECOMP_FUNC void func_80171854_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80171854: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80171858: lwc1        $f4, -0x2BBC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2BBC);
    // 0x8017185C: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80171860: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80171864: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80171868: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017186C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80171870: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x80171874: swc1        $f8, -0x2BBC($at)
    MEM_W(-0X2BBC, ctx->r1) = ctx->f8.u32l;
    // 0x80171878: bc1f        L_80171894
    if (!c1cs) {
        // 0x8017187C: nop
    
            goto L_80171894;
    }
    // 0x8017187C: nop

    // 0x80171880: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80171884: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80171888: swc1        $f16, -0x2BBC($at)
    MEM_W(-0X2BBC, ctx->r1) = ctx->f16.u32l;
    // 0x8017188C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80171890: sw          $zero, -0x2BA0($at)
    MEM_W(-0X2BA0, ctx->r1) = 0;
L_80171894:
    // 0x80171894: jr          $ra
    // 0x80171898: nop

    return;
    // 0x80171898: nop

;}
RECOMP_FUNC void func_8017189C_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017189C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801718A0: sw          $zero, -0x2C04($at)
    MEM_W(-0X2C04, ctx->r1) = 0;
    // 0x801718A4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801718A8: sh          $zero, -0x2C08($at)
    MEM_H(-0X2C08, ctx->r1) = 0;
    // 0x801718AC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801718B0: lw          $t6, -0x2BB8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2BB8);
    // 0x801718B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801718B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801718BC: lwc1        $f4, 0x4($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X4);
    // 0x801718C0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801718C4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801718C8: addiu       $t7, $t7, -0x4198
    ctx->r15 = ADD32(ctx->r15, -0X4198);
    // 0x801718CC: swc1        $f4, -0x2BE0($at)
    MEM_W(-0X2BE0, ctx->r1) = ctx->f4.u32l;
    // 0x801718D0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x801718D4: swc1        $f4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f4.u32l;
    // 0x801718D8: lw          $t8, -0x2BB8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2BB8);
    // 0x801718DC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801718E0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801718E4: lwc1        $f6, 0x8($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X8);
    // 0x801718E8: addiu       $t9, $t9, -0x4198
    ctx->r25 = ADD32(ctx->r25, -0X4198);
    // 0x801718EC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x801718F0: swc1        $f6, -0x2BDC($at)
    MEM_W(-0X2BDC, ctx->r1) = ctx->f6.u32l;
    // 0x801718F4: swc1        $f6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f6.u32l;
    // 0x801718F8: lw          $t0, -0x2BB8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2BB8);
    // 0x801718FC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80171900: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80171904: lwc1        $f8, 0xC($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0XC);
    // 0x80171908: addiu       $t1, $t1, -0x4198
    ctx->r9 = ADD32(ctx->r9, -0X4198);
    // 0x8017190C: swc1        $f8, -0x2BD8($at)
    MEM_W(-0X2BD8, ctx->r1) = ctx->f8.u32l;
    // 0x80171910: jal         0x80172DC4
    // 0x80171914: swc1        $f8, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f8.u32l;
    func_80172DC4_1501A0(rdram, ctx);
        goto after_0;
    // 0x80171914: swc1        $f8, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f8.u32l;
    after_0:
    // 0x80171918: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8017191C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80171920: sw          $t2, -0x2BEC($at)
    MEM_W(-0X2BEC, ctx->r1) = ctx->r10;
    // 0x80171924: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80171928: sw          $zero, -0x2BE4($at)
    MEM_W(-0X2BE4, ctx->r1) = 0;
    // 0x8017192C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80171930: lw          $t3, -0x2BB0($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2BB0);
    // 0x80171934: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80171938: lwc1        $f10, 0x4($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X4);
    // 0x8017193C: swc1        $f10, -0x2BD0($at)
    MEM_W(-0X2BD0, ctx->r1) = ctx->f10.u32l;
    // 0x80171940: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80171944: lwc1        $f16, -0x4E0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X4E0);
    // 0x80171948: mul.s       $f12, $f16, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x8017194C: jal         0x800D68F0
    // 0x80171950: nop

    sinf_recomp(rdram, ctx);
        goto after_1;
    // 0x80171950: nop

    after_1:
    // 0x80171954: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80171958: addiu       $t4, $t4, -0x4198
    ctx->r12 = ADD32(ctx->r12, -0X4198);
    // 0x8017195C: swc1        $f0, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->f0.u32l;
    // 0x80171960: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80171964: lwc1        $f18, -0x4DC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X4DC);
    // 0x80171968: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017196C: lwc1        $f4, -0x2BD0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2BD0);
    // 0x80171970: mul.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80171974: jal         0x800D6AB0
    // 0x80171978: nop

    __cosf_recomp(rdram, ctx);
        goto after_2;
    // 0x80171978: nop

    after_2:
    // 0x8017197C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80171980: addiu       $t5, $t5, -0x4198
    ctx->r13 = ADD32(ctx->r13, -0X4198);
    // 0x80171984: jal         0x80172E34
    // 0x80171988: swc1        $f0, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = ctx->f0.u32l;
    func_80172E34_1501A0(rdram, ctx);
        goto after_3;
    // 0x80171988: swc1        $f0, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = ctx->f0.u32l;
    after_3:
    // 0x8017198C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80171990: sw          $zero, -0x2BF8($at)
    MEM_W(-0X2BF8, ctx->r1) = 0;
    // 0x80171994: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80171998: lw          $t6, -0x2BB4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2BB4);
    // 0x8017199C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801719A0: addiu       $t7, $t7, -0x4198
    ctx->r15 = ADD32(ctx->r15, -0X4198);
    // 0x801719A4: lwc1        $f6, 0x4($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X4);
    // 0x801719A8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x801719AC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801719B0: swc1        $f6, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f6.u32l;
    // 0x801719B4: lw          $t8, -0x2BB4($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2BB4);
    // 0x801719B8: addiu       $t9, $t9, -0x4198
    ctx->r25 = ADD32(ctx->r25, -0X4198);
    // 0x801719BC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x801719C0: lwc1        $f8, 0x8($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X8);
    // 0x801719C4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x801719C8: addiu       $t1, $t1, -0x4198
    ctx->r9 = ADD32(ctx->r9, -0X4198);
    // 0x801719CC: swc1        $f8, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->f8.u32l;
    // 0x801719D0: lw          $t0, -0x2BB4($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2BB4);
    // 0x801719D4: lwc1        $f16, 0xC($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0XC);
    // 0x801719D8: jal         0x80172F04
    // 0x801719DC: swc1        $f16, 0x14($t1)
    MEM_W(0X14, ctx->r9) = ctx->f16.u32l;
    func_80172F04_1501A0(rdram, ctx);
        goto after_4;
    // 0x801719DC: swc1        $f16, 0x14($t1)
    MEM_W(0X14, ctx->r9) = ctx->f16.u32l;
    after_4:
    // 0x801719E0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801719E4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801719E8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801719EC: swc1        $f10, -0x2BC4($at)
    MEM_W(-0X2BC4, ctx->r1) = ctx->f10.u32l;
    // 0x801719F0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801719F4: swc1        $f10, -0x2BC8($at)
    MEM_W(-0X2BC8, ctx->r1) = ctx->f10.u32l;
    // 0x801719F8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801719FC: swc1        $f10, -0x2BCC($at)
    MEM_W(-0X2BCC, ctx->r1) = ctx->f10.u32l;
    // 0x80171A00: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80171A04: swc1        $f18, -0x2BBC($at)
    MEM_W(-0X2BBC, ctx->r1) = ctx->f18.u32l;
    // 0x80171A08: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80171A0C: jal         0x800C3FD0
    // 0x80171A10: swc1        $f18, -0x2BC0($at)
    MEM_W(-0X2BC0, ctx->r1) = ctx->f18.u32l;
    func_800C3FD0(rdram, ctx);
        goto after_5;
    // 0x80171A10: swc1        $f18, -0x2BC0($at)
    MEM_W(-0X2BC0, ctx->r1) = ctx->f18.u32l;
    after_5:
    // 0x80171A14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80171A18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80171A1C: jr          $ra
    // 0x80171A20: nop

    return;
    // 0x80171A20: nop

;}
RECOMP_FUNC void func_80171A24_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80171A24: addiu       $sp, $sp, -0xC8
    ctx->r29 = ADD32(ctx->r29, -0XC8);
    // 0x80171A28: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80171A2C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80171A30: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80171A34: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80171A38: addiu       $t6, $t6, -0x2E28
    ctx->r14 = ADD32(ctx->r14, -0X2E28);
    // 0x80171A3C: lbu         $t7, 0xC($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0XC);
    // 0x80171A40: andi        $t8, $t7, 0x10
    ctx->r24 = ctx->r15 & 0X10;
    // 0x80171A44: bne         $t8, $zero, L_80172DB0
    if (ctx->r24 != 0) {
        // 0x80171A48: nop
    
            goto L_80172DB0;
    }
    // 0x80171A48: nop

    // 0x80171A4C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80171A50: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80171A54: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80171A58: swc1        $f4, -0x2BC4($at)
    MEM_W(-0X2BC4, ctx->r1) = ctx->f4.u32l;
    // 0x80171A5C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80171A60: swc1        $f4, -0x2BC8($at)
    MEM_W(-0X2BC8, ctx->r1) = ctx->f4.u32l;
    // 0x80171A64: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80171A68: addiu       $t9, $t9, -0x4198
    ctx->r25 = ADD32(ctx->r25, -0X4198);
    // 0x80171A6C: swc1        $f4, -0x2BCC($at)
    MEM_W(-0X2BCC, ctx->r1) = ctx->f4.u32l;
    // 0x80171A70: lwc1        $f6, 0x0($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X0);
    // 0x80171A74: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80171A78: lhu         $t0, -0x2C08($t0)
    ctx->r8 = MEM_HU(ctx->r8, -0X2C08);
    // 0x80171A7C: swc1        $f6, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f6.u32l;
    // 0x80171A80: lwc1        $f8, 0x4($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X4);
    // 0x80171A84: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80171A88: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x80171A8C: swc1        $f8, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f8.u32l;
    // 0x80171A90: lwc1        $f10, 0x8($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X8);
    // 0x80171A94: beq         $t1, $at, L_8017205C
    if (ctx->r9 == ctx->r1) {
        // 0x80171A98: swc1        $f10, 0xBC($sp)
        MEM_W(0XBC, ctx->r29) = ctx->f10.u32l;
            goto L_8017205C;
    }
    // 0x80171A98: swc1        $f10, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f10.u32l;
    // 0x80171A9C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80171AA0: lw          $t3, -0x2C04($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2C04);
    // 0x80171AA4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80171AA8: lw          $t2, -0x2BB8($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2BB8);
    // 0x80171AAC: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x80171AB0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80171AB4: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80171AB8: lwc1        $f16, 0x4($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0X4);
    // 0x80171ABC: addiu       $t6, $t6, 0x3918
    ctx->r14 = ADD32(ctx->r14, 0X3918);
    // 0x80171AC0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80171AC4: swc1        $f16, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f16.u32l;
    // 0x80171AC8: lw          $t8, -0x2C04($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2C04);
    // 0x80171ACC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80171AD0: lw          $t7, -0x2BB8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2BB8);
    // 0x80171AD4: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x80171AD8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80171ADC: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80171AE0: lwc1        $f18, 0x8($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X8);
    // 0x80171AE4: addiu       $t1, $t1, 0x3918
    ctx->r9 = ADD32(ctx->r9, 0X3918);
    // 0x80171AE8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80171AEC: swc1        $f18, 0x14($t1)
    MEM_W(0X14, ctx->r9) = ctx->f18.u32l;
    // 0x80171AF0: lw          $t2, -0x2C04($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2C04);
    // 0x80171AF4: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80171AF8: lw          $t3, -0x2BB8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2BB8);
    // 0x80171AFC: sll         $t4, $t2, 4
    ctx->r12 = S32(ctx->r10 << 4);
    // 0x80171B00: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80171B04: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x80171B08: lwc1        $f4, 0xC($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0XC);
    // 0x80171B0C: addiu       $t6, $t6, 0x3918
    ctx->r14 = ADD32(ctx->r14, 0X3918);
    // 0x80171B10: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80171B14: swc1        $f4, 0x24($t6)
    MEM_W(0X24, ctx->r14) = ctx->f4.u32l;
    // 0x80171B18: lw          $t8, -0x2C04($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2C04);
    // 0x80171B1C: bne         $t8, $zero, L_80171B98
    if (ctx->r24 != 0) {
        // 0x80171B20: nop
    
            goto L_80171B98;
    }
    // 0x80171B20: nop

    // 0x80171B24: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80171B28: lw          $t7, -0x2BB8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2BB8);
    // 0x80171B2C: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x80171B30: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80171B34: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80171B38: lwc1        $f6, 0x4($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X4);
    // 0x80171B3C: addiu       $t1, $t1, 0x3918
    ctx->r9 = ADD32(ctx->r9, 0X3918);
    // 0x80171B40: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80171B44: swc1        $f6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f6.u32l;
    // 0x80171B48: lw          $t3, -0x2C04($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2C04);
    // 0x80171B4C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80171B50: lw          $t2, -0x2BB8($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2BB8);
    // 0x80171B54: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x80171B58: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80171B5C: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80171B60: lwc1        $f8, 0x8($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X8);
    // 0x80171B64: addiu       $t6, $t6, 0x3918
    ctx->r14 = ADD32(ctx->r14, 0X3918);
    // 0x80171B68: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80171B6C: swc1        $f8, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->f8.u32l;
    // 0x80171B70: lw          $t7, -0x2C04($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2C04);
    // 0x80171B74: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80171B78: lw          $t8, -0x2BB8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2BB8);
    // 0x80171B7C: sll         $t9, $t7, 4
    ctx->r25 = S32(ctx->r15 << 4);
    // 0x80171B80: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80171B84: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80171B88: lwc1        $f10, 0xC($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0XC);
    // 0x80171B8C: addiu       $t1, $t1, 0x3918
    ctx->r9 = ADD32(ctx->r9, 0X3918);
    // 0x80171B90: b           L_80171C10
    // 0x80171B94: swc1        $f10, 0x20($t1)
    MEM_W(0X20, ctx->r9) = ctx->f10.u32l;
        goto L_80171C10;
    // 0x80171B94: swc1        $f10, 0x20($t1)
    MEM_W(0X20, ctx->r9) = ctx->f10.u32l;
L_80171B98:
    // 0x80171B98: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80171B9C: lw          $t2, -0x2C04($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2C04);
    // 0x80171BA0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80171BA4: lw          $t3, -0x2BB8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2BB8);
    // 0x80171BA8: sll         $t4, $t2, 4
    ctx->r12 = S32(ctx->r10 << 4);
    // 0x80171BAC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80171BB0: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x80171BB4: lwc1        $f16, -0xC($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, -0XC);
    // 0x80171BB8: addiu       $t6, $t6, 0x3918
    ctx->r14 = ADD32(ctx->r14, 0X3918);
    // 0x80171BBC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80171BC0: swc1        $f16, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f16.u32l;
    // 0x80171BC4: lw          $t8, -0x2C04($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2C04);
    // 0x80171BC8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80171BCC: lw          $t7, -0x2BB8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2BB8);
    // 0x80171BD0: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x80171BD4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80171BD8: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80171BDC: lwc1        $f18, -0x8($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, -0X8);
    // 0x80171BE0: addiu       $t1, $t1, 0x3918
    ctx->r9 = ADD32(ctx->r9, 0X3918);
    // 0x80171BE4: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80171BE8: swc1        $f18, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->f18.u32l;
    // 0x80171BEC: lw          $t3, -0x2C04($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2C04);
    // 0x80171BF0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80171BF4: lw          $t2, -0x2BB8($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2BB8);
    // 0x80171BF8: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x80171BFC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80171C00: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80171C04: lwc1        $f4, -0x4($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, -0X4);
    // 0x80171C08: addiu       $t6, $t6, 0x3918
    ctx->r14 = ADD32(ctx->r14, 0X3918);
    // 0x80171C0C: swc1        $f4, 0x20($t6)
    MEM_W(0X20, ctx->r14) = ctx->f4.u32l;
L_80171C10:
    // 0x80171C10: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80171C14: lw          $t7, -0x2C04($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2C04);
    // 0x80171C18: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80171C1C: lw          $t8, -0x2BB8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2BB8);
    // 0x80171C20: sll         $t9, $t7, 4
    ctx->r25 = S32(ctx->r15 << 4);
    // 0x80171C24: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80171C28: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80171C2C: lhu         $t1, 0x10($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X10);
    // 0x80171C30: bne         $t1, $at, L_80171D14
    if (ctx->r9 != ctx->r1) {
        // 0x80171C34: nop
    
            goto L_80171D14;
    }
    // 0x80171C34: nop

    // 0x80171C38: lwc1        $f6, 0x4($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X4);
    // 0x80171C3C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80171C40: addiu       $t3, $t3, 0x3918
    ctx->r11 = ADD32(ctx->r11, 0X3918);
    // 0x80171C44: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80171C48: swc1        $f6, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f6.u32l;
    // 0x80171C4C: lw          $t4, -0x2C04($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2C04);
    // 0x80171C50: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80171C54: lw          $t2, -0x2BB8($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2BB8);
    // 0x80171C58: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x80171C5C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80171C60: addu        $t6, $t2, $t5
    ctx->r14 = ADD32(ctx->r10, ctx->r13);
    // 0x80171C64: lwc1        $f8, 0x8($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X8);
    // 0x80171C68: addiu       $t7, $t7, 0x3918
    ctx->r15 = ADD32(ctx->r15, 0X3918);
    // 0x80171C6C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80171C70: swc1        $f8, 0x18($t7)
    MEM_W(0X18, ctx->r15) = ctx->f8.u32l;
    // 0x80171C74: lw          $t9, -0x2C04($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2C04);
    // 0x80171C78: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80171C7C: lw          $t8, -0x2BB8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2BB8);
    // 0x80171C80: sll         $t1, $t9, 4
    ctx->r9 = S32(ctx->r25 << 4);
    // 0x80171C84: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80171C88: addu        $t0, $t8, $t1
    ctx->r8 = ADD32(ctx->r24, ctx->r9);
    // 0x80171C8C: lwc1        $f10, 0xC($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0XC);
    // 0x80171C90: addiu       $t3, $t3, 0x3918
    ctx->r11 = ADD32(ctx->r11, 0X3918);
    // 0x80171C94: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80171C98: swc1        $f10, 0x28($t3)
    MEM_W(0X28, ctx->r11) = ctx->f10.u32l;
    // 0x80171C9C: lw          $t2, -0x2C04($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2C04);
    // 0x80171CA0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80171CA4: lw          $t4, -0x2BB8($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2BB8);
    // 0x80171CA8: sll         $t5, $t2, 4
    ctx->r13 = S32(ctx->r10 << 4);
    // 0x80171CAC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80171CB0: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x80171CB4: lwc1        $f16, 0x4($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X4);
    // 0x80171CB8: addiu       $t7, $t7, 0x3918
    ctx->r15 = ADD32(ctx->r15, 0X3918);
    // 0x80171CBC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80171CC0: swc1        $f16, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f16.u32l;
    // 0x80171CC4: lw          $t8, -0x2C04($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2C04);
    // 0x80171CC8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80171CCC: lw          $t9, -0x2BB8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2BB8);
    // 0x80171CD0: sll         $t1, $t8, 4
    ctx->r9 = S32(ctx->r24 << 4);
    // 0x80171CD4: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80171CD8: addu        $t0, $t9, $t1
    ctx->r8 = ADD32(ctx->r25, ctx->r9);
    // 0x80171CDC: lwc1        $f18, 0x8($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X8);
    // 0x80171CE0: addiu       $t3, $t3, 0x3918
    ctx->r11 = ADD32(ctx->r11, 0X3918);
    // 0x80171CE4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80171CE8: swc1        $f18, 0x1C($t3)
    MEM_W(0X1C, ctx->r11) = ctx->f18.u32l;
    // 0x80171CEC: lw          $t4, -0x2C04($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2C04);
    // 0x80171CF0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80171CF4: lw          $t2, -0x2BB8($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2BB8);
    // 0x80171CF8: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x80171CFC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80171D00: addu        $t6, $t2, $t5
    ctx->r14 = ADD32(ctx->r10, ctx->r13);
    // 0x80171D04: lwc1        $f4, 0xC($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0XC);
    // 0x80171D08: addiu       $t7, $t7, 0x3918
    ctx->r15 = ADD32(ctx->r15, 0X3918);
    // 0x80171D0C: b           L_80171E90
    // 0x80171D10: swc1        $f4, 0x2C($t7)
    MEM_W(0X2C, ctx->r15) = ctx->f4.u32l;
        goto L_80171E90;
    // 0x80171D10: swc1        $f4, 0x2C($t7)
    MEM_W(0X2C, ctx->r15) = ctx->f4.u32l;
L_80171D14:
    // 0x80171D14: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80171D18: lw          $t9, -0x2C04($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2C04);
    // 0x80171D1C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80171D20: lw          $t8, -0x2BB8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2BB8);
    // 0x80171D24: sll         $t1, $t9, 4
    ctx->r9 = S32(ctx->r25 << 4);
    // 0x80171D28: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80171D2C: addu        $t0, $t8, $t1
    ctx->r8 = ADD32(ctx->r24, ctx->r9);
    // 0x80171D30: lwc1        $f6, 0x14($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X14);
    // 0x80171D34: addiu       $t3, $t3, 0x3918
    ctx->r11 = ADD32(ctx->r11, 0X3918);
    // 0x80171D38: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80171D3C: swc1        $f6, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f6.u32l;
    // 0x80171D40: lw          $t2, -0x2C04($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2C04);
    // 0x80171D44: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80171D48: lw          $t4, -0x2BB8($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2BB8);
    // 0x80171D4C: sll         $t5, $t2, 4
    ctx->r13 = S32(ctx->r10 << 4);
    // 0x80171D50: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80171D54: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x80171D58: lwc1        $f8, 0x18($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X18);
    // 0x80171D5C: addiu       $t7, $t7, 0x3918
    ctx->r15 = ADD32(ctx->r15, 0X3918);
    // 0x80171D60: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80171D64: swc1        $f8, 0x18($t7)
    MEM_W(0X18, ctx->r15) = ctx->f8.u32l;
    // 0x80171D68: lw          $t8, -0x2C04($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2C04);
    // 0x80171D6C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80171D70: lw          $t9, -0x2BB8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2BB8);
    // 0x80171D74: sll         $t1, $t8, 4
    ctx->r9 = S32(ctx->r24 << 4);
    // 0x80171D78: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80171D7C: addu        $t0, $t9, $t1
    ctx->r8 = ADD32(ctx->r25, ctx->r9);
    // 0x80171D80: lwc1        $f10, 0x1C($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X1C);
    // 0x80171D84: addiu       $t3, $t3, 0x3918
    ctx->r11 = ADD32(ctx->r11, 0X3918);
    // 0x80171D88: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80171D8C: swc1        $f10, 0x28($t3)
    MEM_W(0X28, ctx->r11) = ctx->f10.u32l;
    // 0x80171D90: lw          $t4, -0x2C04($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2C04);
    // 0x80171D94: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80171D98: lw          $t2, -0x2BB8($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2BB8);
    // 0x80171D9C: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x80171DA0: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80171DA4: addu        $t6, $t2, $t5
    ctx->r14 = ADD32(ctx->r10, ctx->r13);
    // 0x80171DA8: lhu         $t7, 0x20($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X20);
    // 0x80171DAC: bne         $t7, $at, L_80171E18
    if (ctx->r15 != ctx->r1) {
        // 0x80171DB0: nop
    
            goto L_80171E18;
    }
    // 0x80171DB0: nop

    // 0x80171DB4: lwc1        $f16, 0x14($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X14);
    // 0x80171DB8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80171DBC: addiu       $t8, $t8, 0x3918
    ctx->r24 = ADD32(ctx->r24, 0X3918);
    // 0x80171DC0: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80171DC4: swc1        $f16, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f16.u32l;
    // 0x80171DC8: lw          $t1, -0x2C04($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2C04);
    // 0x80171DCC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80171DD0: lw          $t9, -0x2BB8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2BB8);
    // 0x80171DD4: sll         $t0, $t1, 4
    ctx->r8 = S32(ctx->r9 << 4);
    // 0x80171DD8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80171DDC: addu        $t3, $t9, $t0
    ctx->r11 = ADD32(ctx->r25, ctx->r8);
    // 0x80171DE0: lwc1        $f18, 0x18($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X18);
    // 0x80171DE4: addiu       $t4, $t4, 0x3918
    ctx->r12 = ADD32(ctx->r12, 0X3918);
    // 0x80171DE8: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80171DEC: swc1        $f18, 0x1C($t4)
    MEM_W(0X1C, ctx->r12) = ctx->f18.u32l;
    // 0x80171DF0: lw          $t5, -0x2C04($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2C04);
    // 0x80171DF4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80171DF8: lw          $t2, -0x2BB8($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2BB8);
    // 0x80171DFC: sll         $t7, $t5, 4
    ctx->r15 = S32(ctx->r13 << 4);
    // 0x80171E00: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80171E04: addu        $t6, $t2, $t7
    ctx->r14 = ADD32(ctx->r10, ctx->r15);
    // 0x80171E08: lwc1        $f4, 0x1C($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X1C);
    // 0x80171E0C: addiu       $t8, $t8, 0x3918
    ctx->r24 = ADD32(ctx->r24, 0X3918);
    // 0x80171E10: b           L_80171E90
    // 0x80171E14: swc1        $f4, 0x2C($t8)
    MEM_W(0X2C, ctx->r24) = ctx->f4.u32l;
        goto L_80171E90;
    // 0x80171E14: swc1        $f4, 0x2C($t8)
    MEM_W(0X2C, ctx->r24) = ctx->f4.u32l;
L_80171E18:
    // 0x80171E18: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80171E1C: lw          $t9, -0x2C04($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2C04);
    // 0x80171E20: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80171E24: lw          $t1, -0x2BB8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2BB8);
    // 0x80171E28: sll         $t0, $t9, 4
    ctx->r8 = S32(ctx->r25 << 4);
    // 0x80171E2C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80171E30: addu        $t3, $t1, $t0
    ctx->r11 = ADD32(ctx->r9, ctx->r8);
    // 0x80171E34: lwc1        $f6, 0x24($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X24);
    // 0x80171E38: addiu       $t4, $t4, 0x3918
    ctx->r12 = ADD32(ctx->r12, 0X3918);
    // 0x80171E3C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80171E40: swc1        $f6, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->f6.u32l;
    // 0x80171E44: lw          $t2, -0x2C04($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2C04);
    // 0x80171E48: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80171E4C: lw          $t5, -0x2BB8($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2BB8);
    // 0x80171E50: sll         $t7, $t2, 4
    ctx->r15 = S32(ctx->r10 << 4);
    // 0x80171E54: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80171E58: addu        $t6, $t5, $t7
    ctx->r14 = ADD32(ctx->r13, ctx->r15);
    // 0x80171E5C: lwc1        $f8, 0x28($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X28);
    // 0x80171E60: addiu       $t8, $t8, 0x3918
    ctx->r24 = ADD32(ctx->r24, 0X3918);
    // 0x80171E64: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80171E68: swc1        $f8, 0x1C($t8)
    MEM_W(0X1C, ctx->r24) = ctx->f8.u32l;
    // 0x80171E6C: lw          $t1, -0x2C04($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2C04);
    // 0x80171E70: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80171E74: lw          $t9, -0x2BB8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2BB8);
    // 0x80171E78: sll         $t0, $t1, 4
    ctx->r8 = S32(ctx->r9 << 4);
    // 0x80171E7C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80171E80: addu        $t3, $t9, $t0
    ctx->r11 = ADD32(ctx->r25, ctx->r8);
    // 0x80171E84: lwc1        $f10, 0x2C($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X2C);
    // 0x80171E88: addiu       $t4, $t4, 0x3918
    ctx->r12 = ADD32(ctx->r12, 0X3918);
    // 0x80171E8C: swc1        $f10, 0x2C($t4)
    MEM_W(0X2C, ctx->r12) = ctx->f10.u32l;
L_80171E90:
    // 0x80171E90: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80171E94: addiu       $t2, $t2, 0x3918
    ctx->r10 = ADD32(ctx->r10, 0X3918);
    // 0x80171E98: lwc1        $f16, 0x8($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X8);
    // 0x80171E9C: lwc1        $f18, 0x4($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X4);
    // 0x80171EA0: c.eq.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl == ctx->f18.fl;
    // 0x80171EA4: nop

    // 0x80171EA8: bc1f        L_80171F74
    if (!c1cs) {
        // 0x80171EAC: nop
    
            goto L_80171F74;
    }
    // 0x80171EAC: nop

    // 0x80171EB0: lwc1        $f4, 0x18($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X18);
    // 0x80171EB4: lwc1        $f6, 0x14($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X14);
    // 0x80171EB8: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80171EBC: nop

    // 0x80171EC0: bc1f        L_80171F74
    if (!c1cs) {
        // 0x80171EC4: nop
    
            goto L_80171F74;
    }
    // 0x80171EC4: nop

    // 0x80171EC8: lwc1        $f8, 0x28($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X28);
    // 0x80171ECC: lwc1        $f10, 0x24($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X24);
    // 0x80171ED0: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x80171ED4: nop

    // 0x80171ED8: bc1f        L_80171F74
    if (!c1cs) {
        // 0x80171EDC: nop
    
            goto L_80171F74;
    }
    // 0x80171EDC: nop

    // 0x80171EE0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80171EE4: lw          $t7, -0x2C04($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2C04);
    // 0x80171EE8: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80171EEC: lw          $t5, -0x2BB8($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2BB8);
    // 0x80171EF0: sll         $t6, $t7, 4
    ctx->r14 = S32(ctx->r15 << 4);
    // 0x80171EF4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80171EF8: addu        $t8, $t5, $t6
    ctx->r24 = ADD32(ctx->r13, ctx->r14);
    // 0x80171EFC: lwc1        $f16, 0x4($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X4);
    // 0x80171F00: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80171F04: addiu       $t1, $t1, -0x4198
    ctx->r9 = ADD32(ctx->r9, -0X4198);
    // 0x80171F08: swc1        $f16, -0x2BE0($at)
    MEM_W(-0X2BE0, ctx->r1) = ctx->f16.u32l;
    // 0x80171F0C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80171F10: swc1        $f16, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f16.u32l;
    // 0x80171F14: lw          $t0, -0x2C04($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2C04);
    // 0x80171F18: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80171F1C: lw          $t9, -0x2BB8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2BB8);
    // 0x80171F20: sll         $t3, $t0, 4
    ctx->r11 = S32(ctx->r8 << 4);
    // 0x80171F24: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80171F28: addu        $t4, $t9, $t3
    ctx->r12 = ADD32(ctx->r25, ctx->r11);
    // 0x80171F2C: lwc1        $f18, 0x8($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X8);
    // 0x80171F30: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80171F34: addiu       $t2, $t2, -0x4198
    ctx->r10 = ADD32(ctx->r10, -0X4198);
    // 0x80171F38: swc1        $f18, -0x2BDC($at)
    MEM_W(-0X2BDC, ctx->r1) = ctx->f18.u32l;
    // 0x80171F3C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80171F40: swc1        $f18, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->f18.u32l;
    // 0x80171F44: lw          $t5, -0x2C04($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2C04);
    // 0x80171F48: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80171F4C: lw          $t7, -0x2BB8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2BB8);
    // 0x80171F50: sll         $t6, $t5, 4
    ctx->r14 = S32(ctx->r13 << 4);
    // 0x80171F54: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80171F58: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x80171F5C: lwc1        $f4, 0xC($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0XC);
    // 0x80171F60: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80171F64: addiu       $t1, $t1, -0x4198
    ctx->r9 = ADD32(ctx->r9, -0X4198);
    // 0x80171F68: swc1        $f4, -0x2BD8($at)
    MEM_W(-0X2BD8, ctx->r1) = ctx->f4.u32l;
    // 0x80171F6C: b           L_80172020
    // 0x80171F70: swc1        $f4, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f4.u32l;
        goto L_80172020;
    // 0x80171F70: swc1        $f4, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f4.u32l;
L_80171F74:
    // 0x80171F74: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80171F78: lw          $t0, -0x2BFC($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2BFC);
    // 0x80171F7C: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x80171F80: bgez        $t0, L_80171F98
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80171F84: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80171F98;
    }
    // 0x80171F84: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80171F88: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80171F8C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80171F90: nop

    // 0x80171F94: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_80171F98:
    // 0x80171F98: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80171F9C: lw          $t9, -0x2C00($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2C00);
    // 0x80171FA0: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x80171FA4: bgez        $t9, L_80171FBC
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80171FA8: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_80171FBC;
    }
    // 0x80171FA8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80171FAC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80171FB0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80171FB4: nop

    // 0x80171FB8: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_80171FBC:
    // 0x80171FBC: div.s       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = DIV_S(ctx->f8.fl, ctx->f18.fl);
    // 0x80171FC0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80171FC4: jal         0x8019BE2C
    // 0x80171FC8: swc1        $f6, 0x3948($at)
    MEM_W(0X3948, ctx->r1) = ctx->f6.u32l;
    func_8019BE2C_1501A0(rdram, ctx);
        goto after_0;
    // 0x80171FC8: swc1        $f6, 0x3948($at)
    MEM_W(0X3948, ctx->r1) = ctx->f6.u32l;
    after_0:
    // 0x80171FCC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80171FD0: lwc1        $f10, 0x394C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X394C);
    // 0x80171FD4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80171FD8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80171FDC: swc1        $f10, -0x2BE0($at)
    MEM_W(-0X2BE0, ctx->r1) = ctx->f10.u32l;
    // 0x80171FE0: addiu       $t3, $t3, -0x4198
    ctx->r11 = ADD32(ctx->r11, -0X4198);
    // 0x80171FE4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80171FE8: swc1        $f10, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f10.u32l;
    // 0x80171FEC: lwc1        $f16, 0x3950($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X3950);
    // 0x80171FF0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80171FF4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80171FF8: swc1        $f16, -0x2BDC($at)
    MEM_W(-0X2BDC, ctx->r1) = ctx->f16.u32l;
    // 0x80171FFC: addiu       $t4, $t4, -0x4198
    ctx->r12 = ADD32(ctx->r12, -0X4198);
    // 0x80172000: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80172004: swc1        $f16, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->f16.u32l;
    // 0x80172008: lwc1        $f4, 0x3954($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X3954);
    // 0x8017200C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80172010: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80172014: addiu       $t2, $t2, -0x4198
    ctx->r10 = ADD32(ctx->r10, -0X4198);
    // 0x80172018: swc1        $f4, -0x2BD8($at)
    MEM_W(-0X2BD8, ctx->r1) = ctx->f4.u32l;
    // 0x8017201C: swc1        $f4, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->f4.u32l;
L_80172020:
    // 0x80172020: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80172024: lw          $t5, -0x2BFC($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2BFC);
    // 0x80172028: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017202C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80172030: addiu       $t7, $t5, 0x1
    ctx->r15 = ADD32(ctx->r13, 0X1);
    // 0x80172034: sw          $t7, -0x2BFC($at)
    MEM_W(-0X2BFC, ctx->r1) = ctx->r15;
    // 0x80172038: lw          $t6, -0x2C00($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2C00);
    // 0x8017203C: bne         $t7, $t6, L_8017205C
    if (ctx->r15 != ctx->r14) {
        // 0x80172040: nop
    
            goto L_8017205C;
    }
    // 0x80172040: nop

    // 0x80172044: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80172048: lw          $t8, -0x2C04($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2C04);
    // 0x8017204C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80172050: addiu       $t1, $t8, 0x1
    ctx->r9 = ADD32(ctx->r24, 0X1);
    // 0x80172054: jal         0x80172DC4
    // 0x80172058: sw          $t1, -0x2C04($at)
    MEM_W(-0X2C04, ctx->r1) = ctx->r9;
    func_80172DC4_1501A0(rdram, ctx);
        goto after_1;
    // 0x80172058: sw          $t1, -0x2C04($at)
    MEM_W(-0X2C04, ctx->r1) = ctx->r9;
    after_1:
L_8017205C:
    // 0x8017205C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80172060: lhu         $t0, -0x2C08($t0)
    ctx->r8 = MEM_HU(ctx->r8, -0X2C08);
    // 0x80172064: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80172068: andi        $t9, $t0, 0x2
    ctx->r25 = ctx->r8 & 0X2;
    // 0x8017206C: beq         $t9, $at, L_801728EC
    if (ctx->r25 == ctx->r1) {
        // 0x80172070: nop
    
            goto L_801728EC;
    }
    // 0x80172070: nop

    // 0x80172074: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80172078: lw          $t4, -0x2BF8($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2BF8);
    // 0x8017207C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80172080: lw          $t3, -0x2BB4($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2BB4);
    // 0x80172084: sll         $t2, $t4, 4
    ctx->r10 = S32(ctx->r12 << 4);
    // 0x80172088: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017208C: addu        $t5, $t3, $t2
    ctx->r13 = ADD32(ctx->r11, ctx->r10);
    // 0x80172090: lwc1        $f8, 0x4($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X4);
    // 0x80172094: addiu       $t7, $t7, 0x3918
    ctx->r15 = ADD32(ctx->r15, 0X3918);
    // 0x80172098: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017209C: swc1        $f8, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f8.u32l;
    // 0x801720A0: lw          $t8, -0x2BF8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2BF8);
    // 0x801720A4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801720A8: lw          $t6, -0x2BB4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2BB4);
    // 0x801720AC: sll         $t1, $t8, 4
    ctx->r9 = S32(ctx->r24 << 4);
    // 0x801720B0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801720B4: addu        $t0, $t6, $t1
    ctx->r8 = ADD32(ctx->r14, ctx->r9);
    // 0x801720B8: lwc1        $f18, 0x8($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X8);
    // 0x801720BC: addiu       $t9, $t9, 0x3918
    ctx->r25 = ADD32(ctx->r25, 0X3918);
    // 0x801720C0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x801720C4: swc1        $f18, 0x14($t9)
    MEM_W(0X14, ctx->r25) = ctx->f18.u32l;
    // 0x801720C8: lw          $t3, -0x2BF8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2BF8);
    // 0x801720CC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x801720D0: lw          $t4, -0x2BB4($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2BB4);
    // 0x801720D4: sll         $t2, $t3, 4
    ctx->r10 = S32(ctx->r11 << 4);
    // 0x801720D8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801720DC: addu        $t5, $t4, $t2
    ctx->r13 = ADD32(ctx->r12, ctx->r10);
    // 0x801720E0: lwc1        $f6, 0xC($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0XC);
    // 0x801720E4: addiu       $t7, $t7, 0x3918
    ctx->r15 = ADD32(ctx->r15, 0X3918);
    // 0x801720E8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x801720EC: swc1        $f6, 0x24($t7)
    MEM_W(0X24, ctx->r15) = ctx->f6.u32l;
    // 0x801720F0: lw          $t8, -0x2BF8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2BF8);
    // 0x801720F4: bne         $t8, $zero, L_80172170
    if (ctx->r24 != 0) {
        // 0x801720F8: nop
    
            goto L_80172170;
    }
    // 0x801720F8: nop

    // 0x801720FC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80172100: lw          $t6, -0x2BB4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2BB4);
    // 0x80172104: sll         $t1, $t8, 4
    ctx->r9 = S32(ctx->r24 << 4);
    // 0x80172108: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017210C: addu        $t0, $t6, $t1
    ctx->r8 = ADD32(ctx->r14, ctx->r9);
    // 0x80172110: lwc1        $f10, 0x4($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X4);
    // 0x80172114: addiu       $t9, $t9, 0x3918
    ctx->r25 = ADD32(ctx->r25, 0X3918);
    // 0x80172118: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017211C: swc1        $f10, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f10.u32l;
    // 0x80172120: lw          $t4, -0x2BF8($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2BF8);
    // 0x80172124: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80172128: lw          $t3, -0x2BB4($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2BB4);
    // 0x8017212C: sll         $t2, $t4, 4
    ctx->r10 = S32(ctx->r12 << 4);
    // 0x80172130: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80172134: addu        $t5, $t3, $t2
    ctx->r13 = ADD32(ctx->r11, ctx->r10);
    // 0x80172138: lwc1        $f16, 0x8($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0X8);
    // 0x8017213C: addiu       $t7, $t7, 0x3918
    ctx->r15 = ADD32(ctx->r15, 0X3918);
    // 0x80172140: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80172144: swc1        $f16, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->f16.u32l;
    // 0x80172148: lw          $t6, -0x2BF8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2BF8);
    // 0x8017214C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80172150: lw          $t8, -0x2BB4($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2BB4);
    // 0x80172154: sll         $t1, $t6, 4
    ctx->r9 = S32(ctx->r14 << 4);
    // 0x80172158: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017215C: addu        $t0, $t8, $t1
    ctx->r8 = ADD32(ctx->r24, ctx->r9);
    // 0x80172160: lwc1        $f4, 0xC($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0XC);
    // 0x80172164: addiu       $t9, $t9, 0x3918
    ctx->r25 = ADD32(ctx->r25, 0X3918);
    // 0x80172168: b           L_801721E8
    // 0x8017216C: swc1        $f4, 0x20($t9)
    MEM_W(0X20, ctx->r25) = ctx->f4.u32l;
        goto L_801721E8;
    // 0x8017216C: swc1        $f4, 0x20($t9)
    MEM_W(0X20, ctx->r25) = ctx->f4.u32l;
L_80172170:
    // 0x80172170: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80172174: lw          $t3, -0x2BF8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2BF8);
    // 0x80172178: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017217C: lw          $t4, -0x2BB4($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2BB4);
    // 0x80172180: sll         $t2, $t3, 4
    ctx->r10 = S32(ctx->r11 << 4);
    // 0x80172184: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80172188: addu        $t5, $t4, $t2
    ctx->r13 = ADD32(ctx->r12, ctx->r10);
    // 0x8017218C: lwc1        $f8, -0xC($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, -0XC);
    // 0x80172190: addiu       $t7, $t7, 0x3918
    ctx->r15 = ADD32(ctx->r15, 0X3918);
    // 0x80172194: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80172198: swc1        $f8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f8.u32l;
    // 0x8017219C: lw          $t8, -0x2BF8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2BF8);
    // 0x801721A0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801721A4: lw          $t6, -0x2BB4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2BB4);
    // 0x801721A8: sll         $t1, $t8, 4
    ctx->r9 = S32(ctx->r24 << 4);
    // 0x801721AC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801721B0: addu        $t0, $t6, $t1
    ctx->r8 = ADD32(ctx->r14, ctx->r9);
    // 0x801721B4: lwc1        $f18, -0x8($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, -0X8);
    // 0x801721B8: addiu       $t9, $t9, 0x3918
    ctx->r25 = ADD32(ctx->r25, 0X3918);
    // 0x801721BC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x801721C0: swc1        $f18, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->f18.u32l;
    // 0x801721C4: lw          $t4, -0x2BF8($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2BF8);
    // 0x801721C8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x801721CC: lw          $t3, -0x2BB4($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2BB4);
    // 0x801721D0: sll         $t2, $t4, 4
    ctx->r10 = S32(ctx->r12 << 4);
    // 0x801721D4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801721D8: addu        $t5, $t3, $t2
    ctx->r13 = ADD32(ctx->r11, ctx->r10);
    // 0x801721DC: lwc1        $f6, -0x4($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, -0X4);
    // 0x801721E0: addiu       $t7, $t7, 0x3918
    ctx->r15 = ADD32(ctx->r15, 0X3918);
    // 0x801721E4: swc1        $f6, 0x20($t7)
    MEM_W(0X20, ctx->r15) = ctx->f6.u32l;
L_801721E8:
    // 0x801721E8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801721EC: lw          $t6, -0x2BF8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2BF8);
    // 0x801721F0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x801721F4: lw          $t8, -0x2BB4($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2BB4);
    // 0x801721F8: sll         $t1, $t6, 4
    ctx->r9 = S32(ctx->r14 << 4);
    // 0x801721FC: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80172200: addu        $t0, $t8, $t1
    ctx->r8 = ADD32(ctx->r24, ctx->r9);
    // 0x80172204: lhu         $t9, 0x10($t0)
    ctx->r25 = MEM_HU(ctx->r8, 0X10);
    // 0x80172208: bne         $t9, $at, L_801722EC
    if (ctx->r25 != ctx->r1) {
        // 0x8017220C: nop
    
            goto L_801722EC;
    }
    // 0x8017220C: nop

    // 0x80172210: lwc1        $f10, 0x4($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X4);
    // 0x80172214: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80172218: addiu       $t4, $t4, 0x3918
    ctx->r12 = ADD32(ctx->r12, 0X3918);
    // 0x8017221C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80172220: swc1        $f10, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->f10.u32l;
    // 0x80172224: lw          $t2, -0x2BF8($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2BF8);
    // 0x80172228: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017222C: lw          $t3, -0x2BB4($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2BB4);
    // 0x80172230: sll         $t5, $t2, 4
    ctx->r13 = S32(ctx->r10 << 4);
    // 0x80172234: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80172238: addu        $t7, $t3, $t5
    ctx->r15 = ADD32(ctx->r11, ctx->r13);
    // 0x8017223C: lwc1        $f16, 0x8($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X8);
    // 0x80172240: addiu       $t6, $t6, 0x3918
    ctx->r14 = ADD32(ctx->r14, 0X3918);
    // 0x80172244: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80172248: swc1        $f16, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->f16.u32l;
    // 0x8017224C: lw          $t1, -0x2BF8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2BF8);
    // 0x80172250: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80172254: lw          $t8, -0x2BB4($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2BB4);
    // 0x80172258: sll         $t9, $t1, 4
    ctx->r25 = S32(ctx->r9 << 4);
    // 0x8017225C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80172260: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80172264: lwc1        $f4, 0xC($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0XC);
    // 0x80172268: addiu       $t4, $t4, 0x3918
    ctx->r12 = ADD32(ctx->r12, 0X3918);
    // 0x8017226C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80172270: swc1        $f4, 0x28($t4)
    MEM_W(0X28, ctx->r12) = ctx->f4.u32l;
    // 0x80172274: lw          $t3, -0x2BF8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2BF8);
    // 0x80172278: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017227C: lw          $t2, -0x2BB4($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2BB4);
    // 0x80172280: sll         $t5, $t3, 4
    ctx->r13 = S32(ctx->r11 << 4);
    // 0x80172284: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80172288: addu        $t7, $t2, $t5
    ctx->r15 = ADD32(ctx->r10, ctx->r13);
    // 0x8017228C: lwc1        $f8, 0x4($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X4);
    // 0x80172290: addiu       $t6, $t6, 0x3918
    ctx->r14 = ADD32(ctx->r14, 0X3918);
    // 0x80172294: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80172298: swc1        $f8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f8.u32l;
    // 0x8017229C: lw          $t8, -0x2BF8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2BF8);
    // 0x801722A0: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x801722A4: lw          $t1, -0x2BB4($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2BB4);
    // 0x801722A8: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x801722AC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x801722B0: addu        $t0, $t1, $t9
    ctx->r8 = ADD32(ctx->r9, ctx->r25);
    // 0x801722B4: lwc1        $f18, 0x8($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X8);
    // 0x801722B8: addiu       $t4, $t4, 0x3918
    ctx->r12 = ADD32(ctx->r12, 0X3918);
    // 0x801722BC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x801722C0: swc1        $f18, 0x1C($t4)
    MEM_W(0X1C, ctx->r12) = ctx->f18.u32l;
    // 0x801722C4: lw          $t2, -0x2BF8($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2BF8);
    // 0x801722C8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x801722CC: lw          $t3, -0x2BB4($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2BB4);
    // 0x801722D0: sll         $t5, $t2, 4
    ctx->r13 = S32(ctx->r10 << 4);
    // 0x801722D4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801722D8: addu        $t7, $t3, $t5
    ctx->r15 = ADD32(ctx->r11, ctx->r13);
    // 0x801722DC: lwc1        $f6, 0xC($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0XC);
    // 0x801722E0: addiu       $t6, $t6, 0x3918
    ctx->r14 = ADD32(ctx->r14, 0X3918);
    // 0x801722E4: b           L_80172468
    // 0x801722E8: swc1        $f6, 0x2C($t6)
    MEM_W(0X2C, ctx->r14) = ctx->f6.u32l;
        goto L_80172468;
    // 0x801722E8: swc1        $f6, 0x2C($t6)
    MEM_W(0X2C, ctx->r14) = ctx->f6.u32l;
L_801722EC:
    // 0x801722EC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x801722F0: lw          $t1, -0x2BF8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2BF8);
    // 0x801722F4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x801722F8: lw          $t8, -0x2BB4($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2BB4);
    // 0x801722FC: sll         $t9, $t1, 4
    ctx->r25 = S32(ctx->r9 << 4);
    // 0x80172300: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80172304: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80172308: lwc1        $f10, 0x14($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X14);
    // 0x8017230C: addiu       $t4, $t4, 0x3918
    ctx->r12 = ADD32(ctx->r12, 0X3918);
    // 0x80172310: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80172314: swc1        $f10, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->f10.u32l;
    // 0x80172318: lw          $t3, -0x2BF8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2BF8);
    // 0x8017231C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80172320: lw          $t2, -0x2BB4($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2BB4);
    // 0x80172324: sll         $t5, $t3, 4
    ctx->r13 = S32(ctx->r11 << 4);
    // 0x80172328: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017232C: addu        $t7, $t2, $t5
    ctx->r15 = ADD32(ctx->r10, ctx->r13);
    // 0x80172330: lwc1        $f16, 0x18($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X18);
    // 0x80172334: addiu       $t6, $t6, 0x3918
    ctx->r14 = ADD32(ctx->r14, 0X3918);
    // 0x80172338: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017233C: swc1        $f16, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->f16.u32l;
    // 0x80172340: lw          $t8, -0x2BF8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2BF8);
    // 0x80172344: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80172348: lw          $t1, -0x2BB4($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2BB4);
    // 0x8017234C: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x80172350: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80172354: addu        $t0, $t1, $t9
    ctx->r8 = ADD32(ctx->r9, ctx->r25);
    // 0x80172358: lwc1        $f4, 0x1C($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X1C);
    // 0x8017235C: addiu       $t4, $t4, 0x3918
    ctx->r12 = ADD32(ctx->r12, 0X3918);
    // 0x80172360: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80172364: swc1        $f4, 0x28($t4)
    MEM_W(0X28, ctx->r12) = ctx->f4.u32l;
    // 0x80172368: lw          $t2, -0x2BF8($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2BF8);
    // 0x8017236C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80172370: lw          $t3, -0x2BB4($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2BB4);
    // 0x80172374: sll         $t5, $t2, 4
    ctx->r13 = S32(ctx->r10 << 4);
    // 0x80172378: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8017237C: addu        $t7, $t3, $t5
    ctx->r15 = ADD32(ctx->r11, ctx->r13);
    // 0x80172380: lhu         $t6, 0x20($t7)
    ctx->r14 = MEM_HU(ctx->r15, 0X20);
    // 0x80172384: bne         $t6, $at, L_801723F0
    if (ctx->r14 != ctx->r1) {
        // 0x80172388: nop
    
            goto L_801723F0;
    }
    // 0x80172388: nop

    // 0x8017238C: lwc1        $f8, 0x14($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X14);
    // 0x80172390: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80172394: addiu       $t8, $t8, 0x3918
    ctx->r24 = ADD32(ctx->r24, 0X3918);
    // 0x80172398: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017239C: swc1        $f8, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f8.u32l;
    // 0x801723A0: lw          $t9, -0x2BF8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2BF8);
    // 0x801723A4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x801723A8: lw          $t1, -0x2BB4($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2BB4);
    // 0x801723AC: sll         $t0, $t9, 4
    ctx->r8 = S32(ctx->r25 << 4);
    // 0x801723B0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x801723B4: addu        $t4, $t1, $t0
    ctx->r12 = ADD32(ctx->r9, ctx->r8);
    // 0x801723B8: lwc1        $f18, 0x18($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X18);
    // 0x801723BC: addiu       $t2, $t2, 0x3918
    ctx->r10 = ADD32(ctx->r10, 0X3918);
    // 0x801723C0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x801723C4: swc1        $f18, 0x1C($t2)
    MEM_W(0X1C, ctx->r10) = ctx->f18.u32l;
    // 0x801723C8: lw          $t5, -0x2BF8($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2BF8);
    // 0x801723CC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x801723D0: lw          $t3, -0x2BB4($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2BB4);
    // 0x801723D4: sll         $t6, $t5, 4
    ctx->r14 = S32(ctx->r13 << 4);
    // 0x801723D8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x801723DC: addu        $t7, $t3, $t6
    ctx->r15 = ADD32(ctx->r11, ctx->r14);
    // 0x801723E0: lwc1        $f6, 0x1C($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X1C);
    // 0x801723E4: addiu       $t8, $t8, 0x3918
    ctx->r24 = ADD32(ctx->r24, 0X3918);
    // 0x801723E8: b           L_80172468
    // 0x801723EC: swc1        $f6, 0x2C($t8)
    MEM_W(0X2C, ctx->r24) = ctx->f6.u32l;
        goto L_80172468;
    // 0x801723EC: swc1        $f6, 0x2C($t8)
    MEM_W(0X2C, ctx->r24) = ctx->f6.u32l;
L_801723F0:
    // 0x801723F0: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x801723F4: lw          $t1, -0x2BF8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2BF8);
    // 0x801723F8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801723FC: lw          $t9, -0x2BB4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2BB4);
    // 0x80172400: sll         $t0, $t1, 4
    ctx->r8 = S32(ctx->r9 << 4);
    // 0x80172404: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80172408: addu        $t4, $t9, $t0
    ctx->r12 = ADD32(ctx->r25, ctx->r8);
    // 0x8017240C: lwc1        $f10, 0x24($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X24);
    // 0x80172410: addiu       $t2, $t2, 0x3918
    ctx->r10 = ADD32(ctx->r10, 0X3918);
    // 0x80172414: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80172418: swc1        $f10, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f10.u32l;
    // 0x8017241C: lw          $t3, -0x2BF8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2BF8);
    // 0x80172420: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80172424: lw          $t5, -0x2BB4($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2BB4);
    // 0x80172428: sll         $t6, $t3, 4
    ctx->r14 = S32(ctx->r11 << 4);
    // 0x8017242C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80172430: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80172434: lwc1        $f16, 0x28($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X28);
    // 0x80172438: addiu       $t8, $t8, 0x3918
    ctx->r24 = ADD32(ctx->r24, 0X3918);
    // 0x8017243C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80172440: swc1        $f16, 0x1C($t8)
    MEM_W(0X1C, ctx->r24) = ctx->f16.u32l;
    // 0x80172444: lw          $t9, -0x2BF8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2BF8);
    // 0x80172448: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017244C: lw          $t1, -0x2BB4($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2BB4);
    // 0x80172450: sll         $t0, $t9, 4
    ctx->r8 = S32(ctx->r25 << 4);
    // 0x80172454: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80172458: addu        $t4, $t1, $t0
    ctx->r12 = ADD32(ctx->r9, ctx->r8);
    // 0x8017245C: lwc1        $f4, 0x2C($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X2C);
    // 0x80172460: addiu       $t2, $t2, 0x3918
    ctx->r10 = ADD32(ctx->r10, 0X3918);
    // 0x80172464: swc1        $f4, 0x2C($t2)
    MEM_W(0X2C, ctx->r10) = ctx->f4.u32l;
L_80172468:
    // 0x80172468: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017246C: addiu       $t3, $t3, 0x3918
    ctx->r11 = ADD32(ctx->r11, 0X3918);
    // 0x80172470: lwc1        $f8, 0x8($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X8);
    // 0x80172474: lwc1        $f18, 0x4($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X4);
    // 0x80172478: c.eq.s      $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f8.fl == ctx->f18.fl;
    // 0x8017247C: nop

    // 0x80172480: bc1f        L_80172508
    if (!c1cs) {
        // 0x80172484: nop
    
            goto L_80172508;
    }
    // 0x80172484: nop

    // 0x80172488: lwc1        $f6, 0x18($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X18);
    // 0x8017248C: lwc1        $f10, 0x14($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X14);
    // 0x80172490: c.eq.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl == ctx->f10.fl;
    // 0x80172494: nop

    // 0x80172498: bc1f        L_80172508
    if (!c1cs) {
        // 0x8017249C: nop
    
            goto L_80172508;
    }
    // 0x8017249C: nop

    // 0x801724A0: lwc1        $f16, 0x28($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X28);
    // 0x801724A4: lwc1        $f4, 0x24($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X24);
    // 0x801724A8: c.eq.s      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.fl == ctx->f4.fl;
    // 0x801724AC: nop

    // 0x801724B0: bc1f        L_80172508
    if (!c1cs) {
        // 0x801724B4: nop
    
            goto L_80172508;
    }
    // 0x801724B4: nop

    // 0x801724B8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801724BC: lw          $t6, -0x2BF8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2BF8);
    // 0x801724C0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x801724C4: lw          $t5, -0x2BB4($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2BB4);
    // 0x801724C8: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x801724CC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801724D0: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x801724D4: lwc1        $f8, 0x4($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X4);
    // 0x801724D8: sll         $t9, $t6, 4
    ctx->r25 = S32(ctx->r14 << 4);
    // 0x801724DC: addu        $t1, $t5, $t9
    ctx->r9 = ADD32(ctx->r13, ctx->r25);
    // 0x801724E0: swc1        $f8, 0x394C($at)
    MEM_W(0X394C, ctx->r1) = ctx->f8.u32l;
    // 0x801724E4: lwc1        $f18, 0x8($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X8);
    // 0x801724E8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801724EC: sll         $t0, $t6, 4
    ctx->r8 = S32(ctx->r14 << 4);
    // 0x801724F0: addu        $t4, $t5, $t0
    ctx->r12 = ADD32(ctx->r13, ctx->r8);
    // 0x801724F4: swc1        $f18, 0x3950($at)
    MEM_W(0X3950, ctx->r1) = ctx->f18.u32l;
    // 0x801724F8: lwc1        $f6, 0xC($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0XC);
    // 0x801724FC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80172500: b           L_80172560
    // 0x80172504: swc1        $f6, 0x3954($at)
    MEM_W(0X3954, ctx->r1) = ctx->f6.u32l;
        goto L_80172560;
    // 0x80172504: swc1        $f6, 0x3954($at)
    MEM_W(0X3954, ctx->r1) = ctx->f6.u32l;
L_80172508:
    // 0x80172508: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017250C: lw          $t2, -0x2BF0($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2BF0);
    // 0x80172510: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x80172514: bgez        $t2, L_8017252C
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80172518: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_8017252C;
    }
    // 0x80172518: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8017251C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80172520: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80172524: nop

    // 0x80172528: add.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f4.fl;
L_8017252C:
    // 0x8017252C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80172530: lw          $t3, -0x2BF4($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2BF4);
    // 0x80172534: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x80172538: bgez        $t3, L_80172550
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8017253C: cvt.s.w     $f18, $f8
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
            goto L_80172550;
    }
    // 0x8017253C: cvt.s.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80172540: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80172544: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80172548: nop

    // 0x8017254C: add.s       $f18, $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f6.fl;
L_80172550:
    // 0x80172550: div.s       $f10, $f16, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80172554: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80172558: jal         0x8019BE2C
    // 0x8017255C: swc1        $f10, 0x3948($at)
    MEM_W(0X3948, ctx->r1) = ctx->f10.u32l;
    func_8019BE2C_1501A0(rdram, ctx);
        goto after_2;
    // 0x8017255C: swc1        $f10, 0x3948($at)
    MEM_W(0X3948, ctx->r1) = ctx->f10.u32l;
    after_2:
L_80172560:
    // 0x80172560: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80172564: addiu       $t7, $t7, -0x4198
    ctx->r15 = ADD32(ctx->r15, -0X4198);
    // 0x80172568: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017256C: lwc1        $f4, 0x394C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X394C);
    // 0x80172570: lwc1        $f8, 0x0($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X0);
    // 0x80172574: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80172578: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x8017257C: sub.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80172580: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80172584: addiu       $t9, $t9, -0x4198
    ctx->r25 = ADD32(ctx->r25, -0X4198);
    // 0x80172588: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017258C: swc1        $f6, 0x1C($t8)
    MEM_W(0X1C, ctx->r24) = ctx->f6.u32l;
    // 0x80172590: lwc1        $f18, 0x4($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X4);
    // 0x80172594: lwc1        $f16, 0x3950($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X3950);
    // 0x80172598: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017259C: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x801725A0: sub.s       $f10, $f16, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x801725A4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801725A8: addiu       $t6, $t6, -0x4198
    ctx->r14 = ADD32(ctx->r14, -0X4198);
    // 0x801725AC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801725B0: swc1        $f10, 0x20($t1)
    MEM_W(0X20, ctx->r9) = ctx->f10.u32l;
    // 0x801725B4: lwc1        $f8, 0x8($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X8);
    // 0x801725B8: lwc1        $f4, 0x3954($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X3954);
    // 0x801725BC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x801725C0: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x801725C4: sub.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x801725C8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x801725CC: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x801725D0: swc1        $f6, 0x24($t5)
    MEM_W(0X24, ctx->r13) = ctx->f6.u32l;
    // 0x801725D4: jal         0x800E4D20
    // 0x801725D8: lwc1        $f12, 0x1C($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0X1C);
    fabsf_recomp(rdram, ctx);
        goto after_3;
    // 0x801725D8: lwc1        $f12, 0x1C($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0X1C);
    after_3:
    // 0x801725DC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x801725E0: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x801725E4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x801725E8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x801725EC: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x801725F0: swc1        $f20, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->f20.u32l;
    // 0x801725F4: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x801725F8: swc1        $f20, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f20.u32l;
    // 0x801725FC: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x80172600: jal         0x800E4D20
    // 0x80172604: lwc1        $f12, 0x20($t3)
    ctx->f12.u32l = MEM_W(ctx->r11, 0X20);
    fabsf_recomp(rdram, ctx);
        goto after_4;
    // 0x80172604: lwc1        $f12, 0x20($t3)
    ctx->f12.u32l = MEM_W(ctx->r11, 0X20);
    after_4:
    // 0x80172608: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017260C: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x80172610: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80172614: swc1        $f0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f0.u32l;
    // 0x80172618: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x8017261C: jal         0x800E4D20
    // 0x80172620: lwc1        $f12, 0x24($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0X24);
    fabsf_recomp(rdram, ctx);
        goto after_5;
    // 0x80172620: lwc1        $f12, 0x24($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0X24);
    after_5:
    // 0x80172624: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80172628: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x8017262C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80172630: swc1        $f0, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f0.u32l;
    // 0x80172634: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x80172638: lwc1        $f16, 0x4($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X4);
    // 0x8017263C: lwc1        $f18, 0x0($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X0);
    // 0x80172640: c.le.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl <= ctx->f16.fl;
    // 0x80172644: nop

    // 0x80172648: bc1f        L_80172668
    if (!c1cs) {
        // 0x8017264C: nop
    
            goto L_80172668;
    }
    // 0x8017264C: nop

    // 0x80172650: lwc1        $f10, 0x8($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X8);
    // 0x80172654: c.le.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl <= ctx->f16.fl;
    // 0x80172658: nop

    // 0x8017265C: bc1f        L_80172668
    if (!c1cs) {
        // 0x80172660: nop
    
            goto L_80172668;
    }
    // 0x80172660: nop

    // 0x80172664: swc1        $f16, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->f16.u32l;
L_80172668:
    // 0x80172668: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017266C: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x80172670: lwc1        $f4, 0x8($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X8);
    // 0x80172674: lwc1        $f8, 0x0($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X0);
    // 0x80172678: c.le.s      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.fl <= ctx->f4.fl;
    // 0x8017267C: nop

    // 0x80172680: bc1f        L_801726A0
    if (!c1cs) {
        // 0x80172684: nop
    
            goto L_801726A0;
    }
    // 0x80172684: nop

    // 0x80172688: lwc1        $f6, 0x4($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X4);
    // 0x8017268C: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80172690: nop

    // 0x80172694: bc1f        L_801726A0
    if (!c1cs) {
        // 0x80172698: nop
    
            goto L_801726A0;
    }
    // 0x80172698: nop

    // 0x8017269C: swc1        $f4, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->f4.u32l;
L_801726A0:
    // 0x801726A0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x801726A4: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x801726A8: lwc1        $f18, 0x1C($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X1C);
    // 0x801726AC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801726B0: nop

    // 0x801726B4: c.lt.s      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.fl < ctx->f10.fl;
    // 0x801726B8: nop

    // 0x801726BC: bc1f        L_80172710
    if (!c1cs) {
        // 0x801726C0: nop
    
            goto L_80172710;
    }
    // 0x801726C0: nop

    // 0x801726C4: lwc1        $f16, 0x0($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0X0);
    // 0x801726C8: lwc1        $f8, 0x10($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X10);
    // 0x801726CC: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x801726D0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801726D4: div.s       $f6, $f16, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = DIV_S(ctx->f16.fl, ctx->f8.fl);
    // 0x801726D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801726DC: lwc1        $f18, -0x2E30($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x801726E0: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x801726E4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801726E8: mul.s       $f10, $f4, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x801726EC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x801726F0: addiu       $t0, $t0, -0x4198
    ctx->r8 = ADD32(ctx->r8, -0X4198);
    // 0x801726F4: lwc1        $f18, 0x0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X0);
    // 0x801726F8: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x801726FC: nop

    // 0x80172700: mul.s       $f4, $f16, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x80172704: add.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x80172708: b           L_80172750
    // 0x8017270C: swc1        $f6, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->f6.u32l;
        goto L_80172750;
    // 0x8017270C: swc1        $f6, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->f6.u32l;
L_80172710:
    // 0x80172710: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80172714: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x80172718: lwc1        $f10, 0x0($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X0);
    // 0x8017271C: lwc1        $f16, 0x10($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X10);
    // 0x80172720: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80172724: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80172728: div.s       $f8, $f10, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8017272C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80172730: lwc1        $f18, -0x2E30($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x80172734: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80172738: addiu       $t2, $t2, -0x4198
    ctx->r10 = ADD32(ctx->r10, -0X4198);
    // 0x8017273C: mul.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x80172740: lwc1        $f16, 0x0($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X0);
    // 0x80172744: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x80172748: add.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8017274C: swc1        $f4, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f4.u32l;
L_80172750:
    // 0x80172750: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80172754: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x80172758: lwc1        $f18, 0x20($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X20);
    // 0x8017275C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80172760: nop

    // 0x80172764: c.lt.s      $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.fl < ctx->f8.fl;
    // 0x80172768: nop

    // 0x8017276C: bc1f        L_801727C0
    if (!c1cs) {
        // 0x80172770: nop
    
            goto L_801727C0;
    }
    // 0x80172770: nop

    // 0x80172774: lwc1        $f6, 0x4($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X4);
    // 0x80172778: lwc1        $f10, 0x10($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X10);
    // 0x8017277C: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80172780: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80172784: div.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80172788: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017278C: lwc1        $f18, -0x2E30($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x80172790: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80172794: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80172798: mul.s       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x8017279C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801727A0: addiu       $t7, $t7, -0x4198
    ctx->r15 = ADD32(ctx->r15, -0X4198);
    // 0x801727A4: lwc1        $f18, 0x4($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0X4);
    // 0x801727A8: mul.s       $f6, $f16, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x801727AC: nop

    // 0x801727B0: mul.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x801727B4: add.s       $f16, $f4, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x801727B8: b           L_80172800
    // 0x801727BC: swc1        $f16, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->f16.u32l;
        goto L_80172800;
    // 0x801727BC: swc1        $f16, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->f16.u32l;
L_801727C0:
    // 0x801727C0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x801727C4: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x801727C8: lwc1        $f8, 0x4($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X4);
    // 0x801727CC: lwc1        $f6, 0x10($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X10);
    // 0x801727D0: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x801727D4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801727D8: div.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f6.fl);
    // 0x801727DC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801727E0: lwc1        $f18, -0x2E30($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x801727E4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801727E8: addiu       $t9, $t9, -0x4198
    ctx->r25 = ADD32(ctx->r25, -0X4198);
    // 0x801727EC: mul.s       $f16, $f4, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x801727F0: lwc1        $f6, 0x4($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X4);
    // 0x801727F4: mul.s       $f8, $f10, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x801727F8: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x801727FC: swc1        $f4, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->f4.u32l;
L_80172800:
    // 0x80172800: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80172804: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x80172808: lwc1        $f18, 0x24($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X24);
    // 0x8017280C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80172810: nop

    // 0x80172814: c.lt.s      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.fl < ctx->f10.fl;
    // 0x80172818: nop

    // 0x8017281C: bc1f        L_80172870
    if (!c1cs) {
        // 0x80172820: nop
    
            goto L_80172870;
    }
    // 0x80172820: nop

    // 0x80172824: lwc1        $f16, 0x8($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X8);
    // 0x80172828: lwc1        $f8, 0x10($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X10);
    // 0x8017282C: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80172830: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80172834: div.s       $f6, $f16, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = DIV_S(ctx->f16.fl, ctx->f8.fl);
    // 0x80172838: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017283C: lwc1        $f18, -0x2E30($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x80172840: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80172844: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80172848: mul.s       $f10, $f4, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x8017284C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80172850: addiu       $t6, $t6, -0x4198
    ctx->r14 = ADD32(ctx->r14, -0X4198);
    // 0x80172854: lwc1        $f18, 0x8($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X8);
    // 0x80172858: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8017285C: nop

    // 0x80172860: mul.s       $f4, $f16, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x80172864: add.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x80172868: b           L_801728B0
    // 0x8017286C: swc1        $f6, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->f6.u32l;
        goto L_801728B0;
    // 0x8017286C: swc1        $f6, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->f6.u32l;
L_80172870:
    // 0x80172870: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80172874: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x80172878: lwc1        $f10, 0x8($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X8);
    // 0x8017287C: lwc1        $f16, 0x10($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0X10);
    // 0x80172880: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80172884: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80172888: div.s       $f8, $f10, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8017288C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80172890: lwc1        $f18, -0x2E30($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x80172894: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80172898: addiu       $t0, $t0, -0x4198
    ctx->r8 = ADD32(ctx->r8, -0X4198);
    // 0x8017289C: mul.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x801728A0: lwc1        $f16, 0x8($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X8);
    // 0x801728A4: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x801728A8: add.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801728AC: swc1        $f4, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->f4.u32l;
L_801728B0:
    // 0x801728B0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x801728B4: lw          $t4, -0x2BF0($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2BF0);
    // 0x801728B8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801728BC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x801728C0: addiu       $t2, $t4, 0x1
    ctx->r10 = ADD32(ctx->r12, 0X1);
    // 0x801728C4: sw          $t2, -0x2BF0($at)
    MEM_W(-0X2BF0, ctx->r1) = ctx->r10;
    // 0x801728C8: lw          $t3, -0x2BF4($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2BF4);
    // 0x801728CC: bne         $t2, $t3, L_801728EC
    if (ctx->r10 != ctx->r11) {
        // 0x801728D0: nop
    
            goto L_801728EC;
    }
    // 0x801728D0: nop

    // 0x801728D4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801728D8: lw          $t7, -0x2BF8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2BF8);
    // 0x801728DC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801728E0: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x801728E4: jal         0x80172F04
    // 0x801728E8: sw          $t8, -0x2BF8($at)
    MEM_W(-0X2BF8, ctx->r1) = ctx->r24;
    func_80172F04_1501A0(rdram, ctx);
        goto after_6;
    // 0x801728E8: sw          $t8, -0x2BF8($at)
    MEM_W(-0X2BF8, ctx->r1) = ctx->r24;
    after_6:
L_801728EC:
    // 0x801728EC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801728F0: lhu         $t9, -0x2C08($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X2C08);
    // 0x801728F4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x801728F8: andi        $t1, $t9, 0x4
    ctx->r9 = ctx->r25 & 0X4;
    // 0x801728FC: beq         $t1, $at, L_80172BD0
    if (ctx->r9 == ctx->r1) {
        // 0x80172900: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_80172BD0;
    }
    // 0x80172900: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80172904: lwc1        $f18, -0x2BD0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2BD0);
    // 0x80172908: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017290C: lwc1        $f8, -0x2BD4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2BD4);
    // 0x80172910: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80172914: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80172918: add.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x8017291C: addiu       $t6, $t6, -0x4198
    ctx->r14 = ADD32(ctx->r14, -0X4198);
    // 0x80172920: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80172924: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x80172928: swc1        $f6, -0x2BD0($at)
    MEM_W(-0X2BD0, ctx->r1) = ctx->f6.u32l;
    // 0x8017292C: lwc1        $f16, 0x0($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X0);
    // 0x80172930: lwc1        $f10, 0xC($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0XC);
    // 0x80172934: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80172938: addiu       $t0, $t0, -0x4198
    ctx->r8 = ADD32(ctx->r8, -0X4198);
    // 0x8017293C: sub.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80172940: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80172944: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x80172948: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017294C: swc1        $f4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f4.u32l;
    // 0x80172950: lwc1        $f8, 0x4($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X4);
    // 0x80172954: lwc1        $f18, 0x10($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X10);
    // 0x80172958: addiu       $t2, $t2, -0x4198
    ctx->r10 = ADD32(ctx->r10, -0X4198);
    // 0x8017295C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80172960: sub.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x80172964: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x80172968: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017296C: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x80172970: swc1        $f6, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->f6.u32l;
    // 0x80172974: lwc1        $f16, 0x8($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X8);
    // 0x80172978: lwc1        $f10, 0x14($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X14);
    // 0x8017297C: sub.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80172980: swc1        $f4, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f4.u32l;
    // 0x80172984: lwc1        $f14, 0x8($t7)
    ctx->f14.u32l = MEM_W(ctx->r15, 0X8);
    // 0x80172988: jal         0x800E4940
    // 0x8017298C: lwc1        $f12, 0x0($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X0);
    func_800E4940(rdram, ctx);
        goto after_7;
    // 0x8017298C: lwc1        $f12, 0x0($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X0);
    after_7:
    // 0x80172990: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80172994: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80172998: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8017299C: lwc1        $f6, -0x4D8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X4D8);
    // 0x801729A0: mul.s       $f8, $f0, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x801729A4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x801729A8: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x801729AC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801729B0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801729B4: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x801729B8: addiu       $a0, $sp, 0x7C
    ctx->r4 = ADD32(ctx->r29, 0X7C);
    // 0x801729BC: div.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f6.fl);
    // 0x801729C0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801729C4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801729C8: swc1        $f10, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f10.u32l;
    // 0x801729CC: lw          $a1, 0xC($t9)
    ctx->r5 = MEM_W(ctx->r25, 0XC);
    // 0x801729D0: jal         0x800D7120
    // 0x801729D4: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    guAlignF_recomp(rdram, ctx);
        goto after_8;
    // 0x801729D4: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_8:
    // 0x801729D8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x801729DC: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x801729E0: lwc1        $f4, 0x0($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X0);
    // 0x801729E4: lwc1        $f8, 0x4($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X4);
    // 0x801729E8: lwc1        $f16, 0x8($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X8);
    // 0x801729EC: mul.s       $f18, $f4, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x801729F0: nop

    // 0x801729F4: mul.s       $f6, $f8, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x801729F8: add.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x801729FC: mul.s       $f4, $f16, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x80172A00: jal         0x800D68E0
    // 0x80172A04: add.s       $f12, $f4, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_9;
    // 0x80172A04: add.s       $f12, $f4, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f10.fl;
    after_9:
    // 0x80172A08: addiu       $t6, $sp, 0x7C
    ctx->r14 = ADD32(ctx->r29, 0X7C);
    // 0x80172A0C: lwc1        $f8, 0x20($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X20);
    // 0x80172A10: lwc1        $f6, 0x24($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X24);
    // 0x80172A14: lwc1        $f10, 0x28($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X28);
    // 0x80172A18: mul.s       $f18, $f8, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x80172A1C: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x80172A20: mul.s       $f16, $f6, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x80172A24: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80172A28: mul.s       $f8, $f10, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x80172A2C: jal         0x800D68E0
    // 0x80172A30: add.s       $f12, $f8, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_10;
    // 0x80172A30: add.s       $f12, $f8, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f4.fl;
    after_10:
    // 0x80172A34: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80172A38: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x80172A3C: addiu       $t0, $sp, 0x7C
    ctx->r8 = ADD32(ctx->r29, 0X7C);
    // 0x80172A40: lwc1        $f18, 0x20($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X20);
    // 0x80172A44: lwc1        $f6, 0x0($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X0);
    // 0x80172A48: lwc1        $f8, 0x24($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X24);
    // 0x80172A4C: lwc1        $f10, 0x4($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X4);
    // 0x80172A50: mul.s       $f16, $f6, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x80172A54: lwc1        $f18, 0x8($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X8);
    // 0x80172A58: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80172A5C: mul.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80172A60: lwc1        $f10, 0x28($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X28);
    // 0x80172A64: mul.s       $f8, $f18, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x80172A68: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x80172A6C: mul.s       $f4, $f20, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f22.fl);
    // 0x80172A70: add.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80172A74: jal         0x800E4BE0
    // 0x80172A78: div.s       $f12, $f16, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = DIV_S(ctx->f16.fl, ctx->f4.fl);
    func_800E4BE0(rdram, ctx);
        goto after_11;
    // 0x80172A78: div.s       $f12, $f16, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = DIV_S(ctx->f16.fl, ctx->f4.fl);
    after_11:
    // 0x80172A7C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80172A80: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80172A84: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80172A88: lwc1        $f6, -0x4D4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X4D4);
    // 0x80172A8C: mul.s       $f10, $f0, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80172A90: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80172A94: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x80172A98: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80172A9C: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x80172AA0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80172AA4: div.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80172AA8: swc1        $f8, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->f8.u32l;
    // 0x80172AAC: lwc1        $f16, 0x4($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X4);
    // 0x80172AB0: c.lt.s      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.fl < ctx->f16.fl;
    // 0x80172AB4: nop

    // 0x80172AB8: bc1f        L_80172AD0
    if (!c1cs) {
        // 0x80172ABC: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_80172AD0;
    }
    // 0x80172ABC: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80172AC0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80172AC4: lwc1        $f18, 0x10($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X10);
    // 0x80172AC8: mul.s       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x80172ACC: swc1        $f6, 0x10($t2)
    MEM_W(0X10, ctx->r10) = ctx->f6.u32l;
L_80172AD0:
    // 0x80172AD0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80172AD4: addiu       $t7, $sp, 0x7C
    ctx->r15 = ADD32(ctx->r29, 0X7C);
    // 0x80172AD8: lwc1        $f8, 0x8($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X8);
    // 0x80172ADC: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x80172AE0: lw          $a1, 0x10($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X10);
    // 0x80172AE4: lw          $a2, 0x0($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X0);
    // 0x80172AE8: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x80172AEC: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80172AF0: jal         0x800D7120
    // 0x80172AF4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    guAlignF_recomp(rdram, ctx);
        goto after_12;
    // 0x80172AF4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_12:
    // 0x80172AF8: addiu       $t8, $sp, 0x7C
    ctx->r24 = ADD32(ctx->r29, 0X7C);
    // 0x80172AFC: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x80172B00: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x80172B04: jal         0x800D6F30
    // 0x80172B08: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    guMtxCatF_recomp(rdram, ctx);
        goto after_13;
    // 0x80172B08: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_13:
    // 0x80172B0C: addiu       $t9, $sp, 0x7C
    ctx->r25 = ADD32(ctx->r29, 0X7C);
    // 0x80172B10: lwc1        $f16, 0x28($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X28);
    // 0x80172B14: lw          $a2, 0x20($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X20);
    // 0x80172B18: lw          $a3, 0x24($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X24);
    // 0x80172B1C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80172B20: lw          $a1, -0x2BD0($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X2BD0);
    // 0x80172B24: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x80172B28: jal         0x800D7120
    // 0x80172B2C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    guAlignF_recomp(rdram, ctx);
        goto after_14;
    // 0x80172B2C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_14:
    // 0x80172B30: addiu       $t1, $sp, 0x7C
    ctx->r9 = ADD32(ctx->r29, 0X7C);
    // 0x80172B34: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x80172B38: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    // 0x80172B3C: jal         0x800D6F30
    // 0x80172B40: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    guMtxCatF_recomp(rdram, ctx);
        goto after_15;
    // 0x80172B40: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_15:
    // 0x80172B44: addiu       $t6, $sp, 0x7C
    ctx->r14 = ADD32(ctx->r29, 0X7C);
    // 0x80172B48: lwc1        $f4, 0x10($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X10);
    // 0x80172B4C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80172B50: addiu       $t5, $t5, -0x4198
    ctx->r13 = ADD32(ctx->r13, -0X4198);
    // 0x80172B54: addiu       $t0, $sp, 0x7C
    ctx->r8 = ADD32(ctx->r29, 0X7C);
    // 0x80172B58: swc1        $f4, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f4.u32l;
    // 0x80172B5C: lwc1        $f18, 0x14($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X14);
    // 0x80172B60: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80172B64: addiu       $t4, $t4, -0x4198
    ctx->r12 = ADD32(ctx->r12, -0X4198);
    // 0x80172B68: addiu       $t2, $sp, 0x7C
    ctx->r10 = ADD32(ctx->r29, 0X7C);
    // 0x80172B6C: swc1        $f18, 0x1C($t4)
    MEM_W(0X1C, ctx->r12) = ctx->f18.u32l;
    // 0x80172B70: lwc1        $f10, 0x18($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X18);
    // 0x80172B74: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80172B78: addiu       $t3, $t3, -0x4198
    ctx->r11 = ADD32(ctx->r11, -0X4198);
    // 0x80172B7C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80172B80: swc1        $f10, 0x20($t3)
    MEM_W(0X20, ctx->r11) = ctx->f10.u32l;
    // 0x80172B84: lw          $t7, -0x2BE4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2BE4);
    // 0x80172B88: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80172B8C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80172B90: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80172B94: sw          $t8, -0x2BE4($at)
    MEM_W(-0X2BE4, ctx->r1) = ctx->r24;
    // 0x80172B98: lw          $t1, -0x2BEC($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2BEC);
    // 0x80172B9C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80172BA0: lw          $t9, -0x2BB0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2BB0);
    // 0x80172BA4: sll         $t6, $t1, 3
    ctx->r14 = S32(ctx->r9 << 3);
    // 0x80172BA8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80172BAC: addu        $t5, $t9, $t6
    ctx->r13 = ADD32(ctx->r25, ctx->r14);
    // 0x80172BB0: lhu         $t0, 0x0($t5)
    ctx->r8 = MEM_HU(ctx->r13, 0X0);
    // 0x80172BB4: lw          $t4, -0x2E34($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2E34);
    // 0x80172BB8: bne         $t0, $t4, L_80172BD0
    if (ctx->r8 != ctx->r12) {
        // 0x80172BBC: nop
    
            goto L_80172BD0;
    }
    // 0x80172BBC: nop

    // 0x80172BC0: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80172BC4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80172BC8: jal         0x80172E34
    // 0x80172BCC: sw          $t2, -0x2BEC($at)
    MEM_W(-0X2BEC, ctx->r1) = ctx->r10;
    func_80172E34_1501A0(rdram, ctx);
        goto after_16;
    // 0x80172BCC: sw          $t2, -0x2BEC($at)
    MEM_W(-0X2BEC, ctx->r1) = ctx->r10;
    after_16:
L_80172BD0:
    // 0x80172BD0: jal         0x800C3FD0
    // 0x80172BD4: nop

    func_800C3FD0(rdram, ctx);
        goto after_17;
    // 0x80172BD4: nop

    after_17:
    // 0x80172BD8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80172BDC: lwc1        $f6, -0x2BC0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2BC0);
    // 0x80172BE0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80172BE4: nop

    // 0x80172BE8: c.eq.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl == ctx->f8.fl;
    // 0x80172BEC: nop

    // 0x80172BF0: bc1t        L_80172C80
    if (c1cs) {
        // 0x80172BF4: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_80172C80;
    }
    // 0x80172BF4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80172BF8: lwc1        $f16, -0x2E30($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x80172BFC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80172C00: addiu       $t3, $t3, -0x4198
    ctx->r11 = ADD32(ctx->r11, -0X4198);
    // 0x80172C04: mul.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x80172C08: lwc1        $f18, 0x30($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X30);
    // 0x80172C0C: lwc1        $f8, 0x0($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X0);
    // 0x80172C10: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80172C14: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80172C18: addiu       $t7, $t7, -0x4198
    ctx->r15 = ADD32(ctx->r15, -0X4198);
    // 0x80172C1C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80172C20: mul.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80172C24: addiu       $t8, $t8, -0x4198
    ctx->r24 = ADD32(ctx->r24, -0X4198);
    // 0x80172C28: sub.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80172C2C: swc1        $f6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f6.u32l;
    // 0x80172C30: lwc1        $f16, -0x2BC0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2BC0);
    // 0x80172C34: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80172C38: lwc1        $f18, -0x2E30($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x80172C3C: lwc1        $f8, 0x34($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X34);
    // 0x80172C40: lwc1        $f6, 0x4($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X4);
    // 0x80172C44: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80172C48: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80172C4C: mul.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x80172C50: sub.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80172C54: swc1        $f16, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f16.u32l;
    // 0x80172C58: lwc1        $f18, -0x2BC0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2BC0);
    // 0x80172C5C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80172C60: lwc1        $f8, -0x2E30($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x80172C64: lwc1        $f6, 0x38($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X38);
    // 0x80172C68: lwc1        $f16, 0x8($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X8);
    // 0x80172C6C: mul.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x80172C70: nop

    // 0x80172C74: mul.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x80172C78: sub.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x80172C7C: swc1        $f18, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f18.u32l;
L_80172C80:
    // 0x80172C80: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80172C84: lwc1        $f8, -0x2BBC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2BBC);
    // 0x80172C88: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80172C8C: nop

    // 0x80172C90: c.eq.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl == ctx->f6.fl;
    // 0x80172C94: nop

    // 0x80172C98: bc1t        L_80172D28
    if (c1cs) {
        // 0x80172C9C: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_80172D28;
    }
    // 0x80172C9C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80172CA0: lwc1        $f4, -0x2E30($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x80172CA4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80172CA8: addiu       $t9, $t9, -0x4198
    ctx->r25 = ADD32(ctx->r25, -0X4198);
    // 0x80172CAC: mul.s       $f16, $f8, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x80172CB0: lwc1        $f10, 0x40($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X40);
    // 0x80172CB4: lwc1        $f6, 0x0($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X0);
    // 0x80172CB8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80172CBC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80172CC0: addiu       $t6, $t6, -0x4198
    ctx->r14 = ADD32(ctx->r14, -0X4198);
    // 0x80172CC4: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80172CC8: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80172CCC: addiu       $t5, $t5, -0x4198
    ctx->r13 = ADD32(ctx->r13, -0X4198);
    // 0x80172CD0: add.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x80172CD4: swc1        $f8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f8.u32l;
    // 0x80172CD8: lwc1        $f4, -0x2BBC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2BBC);
    // 0x80172CDC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80172CE0: lwc1        $f10, -0x2E30($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x80172CE4: lwc1        $f6, 0x44($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X44);
    // 0x80172CE8: lwc1        $f8, 0x4($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X4);
    // 0x80172CEC: mul.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x80172CF0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80172CF4: mul.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x80172CF8: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80172CFC: swc1        $f4, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f4.u32l;
    // 0x80172D00: lwc1        $f10, -0x2BBC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2BBC);
    // 0x80172D04: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80172D08: lwc1        $f6, -0x2E30($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x80172D0C: lwc1        $f8, 0x48($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X48);
    // 0x80172D10: lwc1        $f4, 0x8($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X8);
    // 0x80172D14: mul.s       $f16, $f10, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80172D18: nop

    // 0x80172D1C: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80172D20: add.s       $f10, $f4, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x80172D24: swc1        $f10, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->f10.u32l;
L_80172D28:
    // 0x80172D28: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80172D2C: lwc1        $f6, -0x2BC0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2BC0);
    // 0x80172D30: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80172D34: nop

    // 0x80172D38: c.eq.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl == ctx->f8.fl;
    // 0x80172D3C: nop

    // 0x80172D40: bc1f        L_80172D64
    if (!c1cs) {
        // 0x80172D44: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_80172D64;
    }
    // 0x80172D44: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80172D48: lwc1        $f16, -0x2BBC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2BBC);
    // 0x80172D4C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80172D50: nop

    // 0x80172D54: c.eq.s      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.fl == ctx->f4.fl;
    // 0x80172D58: nop

    // 0x80172D5C: bc1t        L_80172D6C
    if (c1cs) {
        // 0x80172D60: nop
    
            goto L_80172D6C;
    }
    // 0x80172D60: nop

L_80172D64:
    // 0x80172D64: jal         0x800C3FD0
    // 0x80172D68: nop

    func_800C3FD0(rdram, ctx);
        goto after_18;
    // 0x80172D68: nop

    after_18:
L_80172D6C:
    // 0x80172D6C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80172D70: addiu       $t0, $t0, -0x4198
    ctx->r8 = ADD32(ctx->r8, -0X4198);
    // 0x80172D74: lwc1        $f18, 0x0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80172D78: lwc1        $f10, 0xC4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x80172D7C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80172D80: lwc1        $f16, 0xC0($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x80172D84: sub.s       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x80172D88: lwc1        $f10, 0xBC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x80172D8C: swc1        $f6, -0x2BCC($at)
    MEM_W(-0X2BCC, ctx->r1) = ctx->f6.u32l;
    // 0x80172D90: lwc1        $f8, 0x4($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X4);
    // 0x80172D94: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80172D98: sub.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x80172D9C: swc1        $f4, -0x2BC8($at)
    MEM_W(-0X2BC8, ctx->r1) = ctx->f4.u32l;
    // 0x80172DA0: lwc1        $f18, 0x8($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X8);
    // 0x80172DA4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80172DA8: sub.s       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x80172DAC: swc1        $f6, -0x2BC4($at)
    MEM_W(-0X2BC4, ctx->r1) = ctx->f6.u32l;
L_80172DB0:
    // 0x80172DB0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80172DB4: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80172DB8: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80172DBC: jr          $ra
    // 0x80172DC0: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
    return;
    // 0x80172DC0: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
;}
RECOMP_FUNC void func_80172DC4_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80172DC4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80172DC8: lw          $t7, -0x2C04($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2C04);
    // 0x80172DCC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80172DD0: lw          $t6, -0x2BB8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2BB8);
    // 0x80172DD4: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x80172DD8: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80172DDC: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80172DE0: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x80172DE4: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80172DE8: sh          $t0, 0x6($sp)
    MEM_H(0X6, ctx->r29) = ctx->r8;
    // 0x80172DEC: lhu         $t1, 0x10($t9)
    ctx->r9 = MEM_HU(ctx->r25, 0X10);
    // 0x80172DF0: bne         $t1, $at, L_80172E10
    if (ctx->r9 != ctx->r1) {
        // 0x80172DF4: sh          $t1, 0x4($sp)
        MEM_H(0X4, ctx->r29) = ctx->r9;
            goto L_80172E10;
    }
    // 0x80172DF4: sh          $t1, 0x4($sp)
    MEM_H(0X4, ctx->r29) = ctx->r9;
    // 0x80172DF8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80172DFC: lhu         $t2, -0x2C08($t2)
    ctx->r10 = MEM_HU(ctx->r10, -0X2C08);
    // 0x80172E00: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80172E04: ori         $t3, $t2, 0x1
    ctx->r11 = ctx->r10 | 0X1;
    // 0x80172E08: b           L_80172E2C
    // 0x80172E0C: sh          $t3, -0x2C08($at)
    MEM_H(-0X2C08, ctx->r1) = ctx->r11;
        goto L_80172E2C;
    // 0x80172E0C: sh          $t3, -0x2C08($at)
    MEM_H(-0X2C08, ctx->r1) = ctx->r11;
L_80172E10:
    // 0x80172E10: lhu         $t4, 0x4($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X4);
    // 0x80172E14: lhu         $t5, 0x6($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X6);
    // 0x80172E18: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80172E1C: subu        $t7, $t4, $t5
    ctx->r15 = SUB32(ctx->r12, ctx->r13);
    // 0x80172E20: sw          $t7, -0x2C00($at)
    MEM_W(-0X2C00, ctx->r1) = ctx->r15;
    // 0x80172E24: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80172E28: sw          $zero, -0x2BFC($at)
    MEM_W(-0X2BFC, ctx->r1) = 0;
L_80172E2C:
    // 0x80172E2C: jr          $ra
    // 0x80172E30: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80172E30: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80172E34_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80172E34: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80172E38: lw          $t7, -0x2BEC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2BEC);
    // 0x80172E3C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80172E40: lw          $t6, -0x2BB0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2BB0);
    // 0x80172E44: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80172E48: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80172E4C: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80172E50: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x80172E54: sw          $t0, -0x2BE8($at)
    MEM_W(-0X2BE8, ctx->r1) = ctx->r8;
    // 0x80172E58: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80172E5C: bne         $t0, $at, L_80172E7C
    if (ctx->r8 != ctx->r1) {
        // 0x80172E60: nop
    
            goto L_80172E7C;
    }
    // 0x80172E60: nop

    // 0x80172E64: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80172E68: lhu         $t1, -0x2C08($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X2C08);
    // 0x80172E6C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80172E70: ori         $t2, $t1, 0x4
    ctx->r10 = ctx->r9 | 0X4;
    // 0x80172E74: jr          $ra
    // 0x80172E78: sh          $t2, -0x2C08($at)
    MEM_H(-0X2C08, ctx->r1) = ctx->r10;
    return;
    // 0x80172E78: sh          $t2, -0x2C08($at)
    MEM_H(-0X2C08, ctx->r1) = ctx->r10;
L_80172E7C:
    // 0x80172E7C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80172E80: lw          $t4, -0x2BEC($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2BEC);
    // 0x80172E84: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80172E88: lw          $t3, -0x2BB0($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2BB0);
    // 0x80172E8C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80172E90: lw          $t6, -0x2BE8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2BE8);
    // 0x80172E94: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x80172E98: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80172E9C: addu        $t7, $t3, $t5
    ctx->r15 = ADD32(ctx->r11, ctx->r13);
    // 0x80172EA0: lwc1        $f4, 0x4($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X4);
    // 0x80172EA4: lwc1        $f6, -0x2BD0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2BD0);
    // 0x80172EA8: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x80172EAC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80172EB0: bgez        $t6, L_80172EC8
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80172EB4: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80172EC8;
    }
    // 0x80172EB4: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80172EB8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80172EBC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80172EC0: nop

    // 0x80172EC4: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_80172EC8:
    // 0x80172EC8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80172ECC: lw          $t8, -0x2E34($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2E34);
    // 0x80172ED0: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80172ED4: bgez        $t8, L_80172EEC
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80172ED8: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80172EEC;
    }
    // 0x80172ED8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80172EDC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80172EE0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80172EE4: nop

    // 0x80172EE8: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
L_80172EEC:
    // 0x80172EEC: sub.s       $f18, $f16, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x80172EF0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80172EF4: div.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f8.fl, ctx->f18.fl);
    // 0x80172EF8: swc1        $f4, -0x2BD4($at)
    MEM_W(-0X2BD4, ctx->r1) = ctx->f4.u32l;
    // 0x80172EFC: jr          $ra
    // 0x80172F00: nop

    return;
    // 0x80172F00: nop

;}
RECOMP_FUNC void func_80172F04_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80172F04: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80172F08: lw          $t7, -0x2BF8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2BF8);
    // 0x80172F0C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80172F10: lw          $t6, -0x2BB4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2BB4);
    // 0x80172F14: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x80172F18: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80172F1C: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80172F20: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x80172F24: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80172F28: sh          $t0, 0x6($sp)
    MEM_H(0X6, ctx->r29) = ctx->r8;
    // 0x80172F2C: lhu         $t1, 0x10($t9)
    ctx->r9 = MEM_HU(ctx->r25, 0X10);
    // 0x80172F30: bne         $t1, $at, L_80172F50
    if (ctx->r9 != ctx->r1) {
        // 0x80172F34: sh          $t1, 0x4($sp)
        MEM_H(0X4, ctx->r29) = ctx->r9;
            goto L_80172F50;
    }
    // 0x80172F34: sh          $t1, 0x4($sp)
    MEM_H(0X4, ctx->r29) = ctx->r9;
    // 0x80172F38: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80172F3C: lhu         $t2, -0x2C08($t2)
    ctx->r10 = MEM_HU(ctx->r10, -0X2C08);
    // 0x80172F40: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80172F44: ori         $t3, $t2, 0x2
    ctx->r11 = ctx->r10 | 0X2;
    // 0x80172F48: b           L_80172F6C
    // 0x80172F4C: sh          $t3, -0x2C08($at)
    MEM_H(-0X2C08, ctx->r1) = ctx->r11;
        goto L_80172F6C;
    // 0x80172F4C: sh          $t3, -0x2C08($at)
    MEM_H(-0X2C08, ctx->r1) = ctx->r11;
L_80172F50:
    // 0x80172F50: lhu         $t4, 0x4($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X4);
    // 0x80172F54: lhu         $t5, 0x6($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X6);
    // 0x80172F58: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80172F5C: subu        $t7, $t4, $t5
    ctx->r15 = SUB32(ctx->r12, ctx->r13);
    // 0x80172F60: sw          $t7, -0x2BF4($at)
    MEM_W(-0X2BF4, ctx->r1) = ctx->r15;
    // 0x80172F64: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80172F68: sw          $zero, -0x2BF0($at)
    MEM_W(-0X2BF0, ctx->r1) = 0;
L_80172F6C:
    // 0x80172F6C: jr          $ra
    // 0x80172F70: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80172F70: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80172F74_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80172F74: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80172F78: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80172F7C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80172F80: addiu       $t6, $t6, -0x2E28
    ctx->r14 = ADD32(ctx->r14, -0X2E28);
    // 0x80172F84: lbu         $t7, 0xC($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0XC);
    // 0x80172F88: andi        $t8, $t7, 0x10
    ctx->r24 = ctx->r15 & 0X10;
    // 0x80172F8C: beq         $t8, $zero, L_80172FA4
    if (ctx->r24 == 0) {
        // 0x80172F90: nop
    
            goto L_80172FA4;
    }
    // 0x80172F90: nop

    // 0x80172F94: jal         0x8017A6CC
    // 0x80172F98: nop

    func_8017A6CC_1501A0(rdram, ctx);
        goto after_0;
    // 0x80172F98: nop

    after_0:
    // 0x80172F9C: b           L_80173528
    // 0x80172FA0: nop

        goto L_80173528;
    // 0x80172FA0: nop

L_80172FA4:
    // 0x80172FA4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80172FA8: lhu         $t9, -0x2BA8($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X2BA8);
    // 0x80172FAC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80172FB0: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x80172FB4: beq         $t0, $at, L_80173474
    if (ctx->r8 == ctx->r1) {
        // 0x80172FB8: nop
    
            goto L_80173474;
    }
    // 0x80172FB8: nop

    // 0x80172FBC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80172FC0: lw          $t2, -0x2B5C($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2B5C);
    // 0x80172FC4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80172FC8: lw          $t1, -0x2AC8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2AC8);
    // 0x80172FCC: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x80172FD0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80172FD4: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x80172FD8: lwc1        $f4, 0x4($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X4);
    // 0x80172FDC: addiu       $t5, $t5, 0x3918
    ctx->r13 = ADD32(ctx->r13, 0X3918);
    // 0x80172FE0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80172FE4: swc1        $f4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->f4.u32l;
    // 0x80172FE8: lw          $t7, -0x2B5C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2B5C);
    // 0x80172FEC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80172FF0: lw          $t6, -0x2AC8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2AC8);
    // 0x80172FF4: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x80172FF8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80172FFC: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80173000: lwc1        $f6, 0x8($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X8);
    // 0x80173004: addiu       $t0, $t0, 0x3918
    ctx->r8 = ADD32(ctx->r8, 0X3918);
    // 0x80173008: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017300C: swc1        $f6, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->f6.u32l;
    // 0x80173010: lw          $t1, -0x2B5C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2B5C);
    // 0x80173014: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80173018: lw          $t2, -0x2AC8($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2AC8);
    // 0x8017301C: sll         $t3, $t1, 4
    ctx->r11 = S32(ctx->r9 << 4);
    // 0x80173020: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80173024: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80173028: lwc1        $f8, 0xC($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0XC);
    // 0x8017302C: addiu       $t5, $t5, 0x3918
    ctx->r13 = ADD32(ctx->r13, 0X3918);
    // 0x80173030: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80173034: swc1        $f8, 0x24($t5)
    MEM_W(0X24, ctx->r13) = ctx->f8.u32l;
    // 0x80173038: lw          $t7, -0x2B5C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2B5C);
    // 0x8017303C: bne         $t7, $zero, L_801730B8
    if (ctx->r15 != 0) {
        // 0x80173040: nop
    
            goto L_801730B8;
    }
    // 0x80173040: nop

    // 0x80173044: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80173048: lw          $t6, -0x2AC8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2AC8);
    // 0x8017304C: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x80173050: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80173054: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80173058: lwc1        $f10, 0x4($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X4);
    // 0x8017305C: addiu       $t0, $t0, 0x3918
    ctx->r8 = ADD32(ctx->r8, 0X3918);
    // 0x80173060: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80173064: swc1        $f10, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f10.u32l;
    // 0x80173068: lw          $t2, -0x2B5C($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2B5C);
    // 0x8017306C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80173070: lw          $t1, -0x2AC8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2AC8);
    // 0x80173074: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x80173078: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017307C: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x80173080: lwc1        $f16, 0x8($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X8);
    // 0x80173084: addiu       $t5, $t5, 0x3918
    ctx->r13 = ADD32(ctx->r13, 0X3918);
    // 0x80173088: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017308C: swc1        $f16, 0x10($t5)
    MEM_W(0X10, ctx->r13) = ctx->f16.u32l;
    // 0x80173090: lw          $t6, -0x2B5C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2B5C);
    // 0x80173094: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80173098: lw          $t7, -0x2AC8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2AC8);
    // 0x8017309C: sll         $t8, $t6, 4
    ctx->r24 = S32(ctx->r14 << 4);
    // 0x801730A0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x801730A4: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x801730A8: lwc1        $f18, 0xC($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0XC);
    // 0x801730AC: addiu       $t0, $t0, 0x3918
    ctx->r8 = ADD32(ctx->r8, 0X3918);
    // 0x801730B0: b           L_80173130
    // 0x801730B4: swc1        $f18, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->f18.u32l;
        goto L_80173130;
    // 0x801730B4: swc1        $f18, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->f18.u32l;
L_801730B8:
    // 0x801730B8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x801730BC: lw          $t1, -0x2B5C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2B5C);
    // 0x801730C0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x801730C4: lw          $t2, -0x2AC8($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2AC8);
    // 0x801730C8: sll         $t3, $t1, 4
    ctx->r11 = S32(ctx->r9 << 4);
    // 0x801730CC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x801730D0: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x801730D4: lwc1        $f4, -0xC($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, -0XC);
    // 0x801730D8: addiu       $t5, $t5, 0x3918
    ctx->r13 = ADD32(ctx->r13, 0X3918);
    // 0x801730DC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801730E0: swc1        $f4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f4.u32l;
    // 0x801730E4: lw          $t7, -0x2B5C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2B5C);
    // 0x801730E8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801730EC: lw          $t6, -0x2AC8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2AC8);
    // 0x801730F0: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x801730F4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x801730F8: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x801730FC: lwc1        $f6, -0x8($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, -0X8);
    // 0x80173100: addiu       $t0, $t0, 0x3918
    ctx->r8 = ADD32(ctx->r8, 0X3918);
    // 0x80173104: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80173108: swc1        $f6, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->f6.u32l;
    // 0x8017310C: lw          $t2, -0x2B5C($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2B5C);
    // 0x80173110: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80173114: lw          $t1, -0x2AC8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2AC8);
    // 0x80173118: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x8017311C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80173120: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x80173124: lwc1        $f8, -0x4($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, -0X4);
    // 0x80173128: addiu       $t5, $t5, 0x3918
    ctx->r13 = ADD32(ctx->r13, 0X3918);
    // 0x8017312C: swc1        $f8, 0x20($t5)
    MEM_W(0X20, ctx->r13) = ctx->f8.u32l;
L_80173130:
    // 0x80173130: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80173134: lw          $t6, -0x2B5C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2B5C);
    // 0x80173138: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017313C: lw          $t7, -0x2AC8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2AC8);
    // 0x80173140: sll         $t8, $t6, 4
    ctx->r24 = S32(ctx->r14 << 4);
    // 0x80173144: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80173148: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8017314C: lhu         $t0, 0x10($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X10);
    // 0x80173150: bne         $t0, $at, L_80173234
    if (ctx->r8 != ctx->r1) {
        // 0x80173154: nop
    
            goto L_80173234;
    }
    // 0x80173154: nop

    // 0x80173158: lwc1        $f10, 0x4($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X4);
    // 0x8017315C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80173160: addiu       $t2, $t2, 0x3918
    ctx->r10 = ADD32(ctx->r10, 0X3918);
    // 0x80173164: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80173168: swc1        $f10, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->f10.u32l;
    // 0x8017316C: lw          $t3, -0x2B5C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2B5C);
    // 0x80173170: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80173174: lw          $t1, -0x2AC8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2AC8);
    // 0x80173178: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x8017317C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80173180: addu        $t5, $t1, $t4
    ctx->r13 = ADD32(ctx->r9, ctx->r12);
    // 0x80173184: lwc1        $f16, 0x8($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0X8);
    // 0x80173188: addiu       $t6, $t6, 0x3918
    ctx->r14 = ADD32(ctx->r14, 0X3918);
    // 0x8017318C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80173190: swc1        $f16, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->f16.u32l;
    // 0x80173194: lw          $t8, -0x2B5C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2B5C);
    // 0x80173198: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017319C: lw          $t7, -0x2AC8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2AC8);
    // 0x801731A0: sll         $t0, $t8, 4
    ctx->r8 = S32(ctx->r24 << 4);
    // 0x801731A4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x801731A8: addu        $t9, $t7, $t0
    ctx->r25 = ADD32(ctx->r15, ctx->r8);
    // 0x801731AC: lwc1        $f18, 0xC($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0XC);
    // 0x801731B0: addiu       $t2, $t2, 0x3918
    ctx->r10 = ADD32(ctx->r10, 0X3918);
    // 0x801731B4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x801731B8: swc1        $f18, 0x28($t2)
    MEM_W(0X28, ctx->r10) = ctx->f18.u32l;
    // 0x801731BC: lw          $t1, -0x2B5C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2B5C);
    // 0x801731C0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x801731C4: lw          $t3, -0x2AC8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2AC8);
    // 0x801731C8: sll         $t4, $t1, 4
    ctx->r12 = S32(ctx->r9 << 4);
    // 0x801731CC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801731D0: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x801731D4: lwc1        $f4, 0x4($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X4);
    // 0x801731D8: addiu       $t6, $t6, 0x3918
    ctx->r14 = ADD32(ctx->r14, 0X3918);
    // 0x801731DC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801731E0: swc1        $f4, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f4.u32l;
    // 0x801731E4: lw          $t7, -0x2B5C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2B5C);
    // 0x801731E8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x801731EC: lw          $t8, -0x2AC8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2AC8);
    // 0x801731F0: sll         $t0, $t7, 4
    ctx->r8 = S32(ctx->r15 << 4);
    // 0x801731F4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x801731F8: addu        $t9, $t8, $t0
    ctx->r25 = ADD32(ctx->r24, ctx->r8);
    // 0x801731FC: lwc1        $f6, 0x8($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X8);
    // 0x80173200: addiu       $t2, $t2, 0x3918
    ctx->r10 = ADD32(ctx->r10, 0X3918);
    // 0x80173204: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80173208: swc1        $f6, 0x1C($t2)
    MEM_W(0X1C, ctx->r10) = ctx->f6.u32l;
    // 0x8017320C: lw          $t3, -0x2B5C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2B5C);
    // 0x80173210: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80173214: lw          $t1, -0x2AC8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2AC8);
    // 0x80173218: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x8017321C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80173220: addu        $t5, $t1, $t4
    ctx->r13 = ADD32(ctx->r9, ctx->r12);
    // 0x80173224: lwc1        $f8, 0xC($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0XC);
    // 0x80173228: addiu       $t6, $t6, 0x3918
    ctx->r14 = ADD32(ctx->r14, 0X3918);
    // 0x8017322C: b           L_801733B0
    // 0x80173230: swc1        $f8, 0x2C($t6)
    MEM_W(0X2C, ctx->r14) = ctx->f8.u32l;
        goto L_801733B0;
    // 0x80173230: swc1        $f8, 0x2C($t6)
    MEM_W(0X2C, ctx->r14) = ctx->f8.u32l;
L_80173234:
    // 0x80173234: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80173238: lw          $t8, -0x2B5C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2B5C);
    // 0x8017323C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80173240: lw          $t7, -0x2AC8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2AC8);
    // 0x80173244: sll         $t0, $t8, 4
    ctx->r8 = S32(ctx->r24 << 4);
    // 0x80173248: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017324C: addu        $t9, $t7, $t0
    ctx->r25 = ADD32(ctx->r15, ctx->r8);
    // 0x80173250: lwc1        $f10, 0x14($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X14);
    // 0x80173254: addiu       $t2, $t2, 0x3918
    ctx->r10 = ADD32(ctx->r10, 0X3918);
    // 0x80173258: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017325C: swc1        $f10, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->f10.u32l;
    // 0x80173260: lw          $t1, -0x2B5C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2B5C);
    // 0x80173264: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80173268: lw          $t3, -0x2AC8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2AC8);
    // 0x8017326C: sll         $t4, $t1, 4
    ctx->r12 = S32(ctx->r9 << 4);
    // 0x80173270: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80173274: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x80173278: lwc1        $f16, 0x18($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0X18);
    // 0x8017327C: addiu       $t6, $t6, 0x3918
    ctx->r14 = ADD32(ctx->r14, 0X3918);
    // 0x80173280: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80173284: swc1        $f16, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->f16.u32l;
    // 0x80173288: lw          $t7, -0x2B5C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2B5C);
    // 0x8017328C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80173290: lw          $t8, -0x2AC8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2AC8);
    // 0x80173294: sll         $t0, $t7, 4
    ctx->r8 = S32(ctx->r15 << 4);
    // 0x80173298: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017329C: addu        $t9, $t8, $t0
    ctx->r25 = ADD32(ctx->r24, ctx->r8);
    // 0x801732A0: lwc1        $f18, 0x1C($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X1C);
    // 0x801732A4: addiu       $t2, $t2, 0x3918
    ctx->r10 = ADD32(ctx->r10, 0X3918);
    // 0x801732A8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x801732AC: swc1        $f18, 0x28($t2)
    MEM_W(0X28, ctx->r10) = ctx->f18.u32l;
    // 0x801732B0: lw          $t3, -0x2B5C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2B5C);
    // 0x801732B4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x801732B8: lw          $t1, -0x2AC8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2AC8);
    // 0x801732BC: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x801732C0: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x801732C4: addu        $t5, $t1, $t4
    ctx->r13 = ADD32(ctx->r9, ctx->r12);
    // 0x801732C8: lhu         $t6, 0x20($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X20);
    // 0x801732CC: bne         $t6, $at, L_80173338
    if (ctx->r14 != ctx->r1) {
        // 0x801732D0: nop
    
            goto L_80173338;
    }
    // 0x801732D0: nop

    // 0x801732D4: lwc1        $f4, 0x14($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X14);
    // 0x801732D8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801732DC: addiu       $t7, $t7, 0x3918
    ctx->r15 = ADD32(ctx->r15, 0X3918);
    // 0x801732E0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x801732E4: swc1        $f4, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f4.u32l;
    // 0x801732E8: lw          $t0, -0x2B5C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2B5C);
    // 0x801732EC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x801732F0: lw          $t8, -0x2AC8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2AC8);
    // 0x801732F4: sll         $t9, $t0, 4
    ctx->r25 = S32(ctx->r8 << 4);
    // 0x801732F8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x801732FC: addu        $t2, $t8, $t9
    ctx->r10 = ADD32(ctx->r24, ctx->r25);
    // 0x80173300: lwc1        $f6, 0x18($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X18);
    // 0x80173304: addiu       $t3, $t3, 0x3918
    ctx->r11 = ADD32(ctx->r11, 0X3918);
    // 0x80173308: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017330C: swc1        $f6, 0x1C($t3)
    MEM_W(0X1C, ctx->r11) = ctx->f6.u32l;
    // 0x80173310: lw          $t4, -0x2B5C($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2B5C);
    // 0x80173314: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80173318: lw          $t1, -0x2AC8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2AC8);
    // 0x8017331C: sll         $t6, $t4, 4
    ctx->r14 = S32(ctx->r12 << 4);
    // 0x80173320: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80173324: addu        $t5, $t1, $t6
    ctx->r13 = ADD32(ctx->r9, ctx->r14);
    // 0x80173328: lwc1        $f8, 0x1C($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X1C);
    // 0x8017332C: addiu       $t7, $t7, 0x3918
    ctx->r15 = ADD32(ctx->r15, 0X3918);
    // 0x80173330: b           L_801733B0
    // 0x80173334: swc1        $f8, 0x2C($t7)
    MEM_W(0X2C, ctx->r15) = ctx->f8.u32l;
        goto L_801733B0;
    // 0x80173334: swc1        $f8, 0x2C($t7)
    MEM_W(0X2C, ctx->r15) = ctx->f8.u32l;
L_80173338:
    // 0x80173338: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017333C: lw          $t8, -0x2B5C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2B5C);
    // 0x80173340: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80173344: lw          $t0, -0x2AC8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2AC8);
    // 0x80173348: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x8017334C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80173350: addu        $t2, $t0, $t9
    ctx->r10 = ADD32(ctx->r8, ctx->r25);
    // 0x80173354: lwc1        $f10, 0x24($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X24);
    // 0x80173358: addiu       $t3, $t3, 0x3918
    ctx->r11 = ADD32(ctx->r11, 0X3918);
    // 0x8017335C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80173360: swc1        $f10, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f10.u32l;
    // 0x80173364: lw          $t1, -0x2B5C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2B5C);
    // 0x80173368: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017336C: lw          $t4, -0x2AC8($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2AC8);
    // 0x80173370: sll         $t6, $t1, 4
    ctx->r14 = S32(ctx->r9 << 4);
    // 0x80173374: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80173378: addu        $t5, $t4, $t6
    ctx->r13 = ADD32(ctx->r12, ctx->r14);
    // 0x8017337C: lwc1        $f16, 0x28($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0X28);
    // 0x80173380: addiu       $t7, $t7, 0x3918
    ctx->r15 = ADD32(ctx->r15, 0X3918);
    // 0x80173384: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80173388: swc1        $f16, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->f16.u32l;
    // 0x8017338C: lw          $t0, -0x2B5C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2B5C);
    // 0x80173390: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80173394: lw          $t8, -0x2AC8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2AC8);
    // 0x80173398: sll         $t9, $t0, 4
    ctx->r25 = S32(ctx->r8 << 4);
    // 0x8017339C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x801733A0: addu        $t2, $t8, $t9
    ctx->r10 = ADD32(ctx->r24, ctx->r25);
    // 0x801733A4: lwc1        $f18, 0x2C($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X2C);
    // 0x801733A8: addiu       $t3, $t3, 0x3918
    ctx->r11 = ADD32(ctx->r11, 0X3918);
    // 0x801733AC: swc1        $f18, 0x2C($t3)
    MEM_W(0X2C, ctx->r11) = ctx->f18.u32l;
L_801733B0:
    // 0x801733B0: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x801733B4: lw          $t1, -0x2B54($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2B54);
    // 0x801733B8: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x801733BC: bgez        $t1, L_801733D4
    if (SIGNED(ctx->r9) >= 0) {
        // 0x801733C0: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801733D4;
    }
    // 0x801733C0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801733C4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801733C8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801733CC: nop

    // 0x801733D0: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_801733D4:
    // 0x801733D4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x801733D8: lw          $t4, -0x2B58($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2B58);
    // 0x801733DC: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x801733E0: bgez        $t4, L_801733F8
    if (SIGNED(ctx->r12) >= 0) {
        // 0x801733E4: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_801733F8;
    }
    // 0x801733E4: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801733E8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801733EC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801733F0: nop

    // 0x801733F4: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_801733F8:
    // 0x801733F8: div.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = DIV_S(ctx->f6.fl, ctx->f16.fl);
    // 0x801733FC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80173400: jal         0x8019BE2C
    // 0x80173404: swc1        $f4, 0x3948($at)
    MEM_W(0X3948, ctx->r1) = ctx->f4.u32l;
    func_8019BE2C_1501A0(rdram, ctx);
        goto after_1;
    // 0x80173404: swc1        $f4, 0x3948($at)
    MEM_W(0X3948, ctx->r1) = ctx->f4.u32l;
    after_1:
    // 0x80173408: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017340C: lwc1        $f8, 0x394C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X394C);
    // 0x80173410: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80173414: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80173418: swc1        $f8, -0x2B24($at)
    MEM_W(-0X2B24, ctx->r1) = ctx->f8.u32l;
    // 0x8017341C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80173420: lwc1        $f10, 0x3950($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X3950);
    // 0x80173424: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80173428: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017342C: swc1        $f10, -0x2B20($at)
    MEM_W(-0X2B20, ctx->r1) = ctx->f10.u32l;
    // 0x80173430: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80173434: lwc1        $f18, 0x3954($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X3954);
    // 0x80173438: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017343C: swc1        $f18, -0x2B1C($at)
    MEM_W(-0X2B1C, ctx->r1) = ctx->f18.u32l;
    // 0x80173440: lw          $t6, -0x2B54($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2B54);
    // 0x80173444: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80173448: addiu       $t5, $t6, 0x1
    ctx->r13 = ADD32(ctx->r14, 0X1);
    // 0x8017344C: sw          $t5, -0x2B54($at)
    MEM_W(-0X2B54, ctx->r1) = ctx->r13;
    // 0x80173450: lw          $t7, -0x2B58($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2B58);
    // 0x80173454: bne         $t5, $t7, L_80173474
    if (ctx->r13 != ctx->r15) {
        // 0x80173458: nop
    
            goto L_80173474;
    }
    // 0x80173458: nop

    // 0x8017345C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80173460: lw          $t0, -0x2B5C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2B5C);
    // 0x80173464: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80173468: addiu       $t8, $t0, 0x1
    ctx->r24 = ADD32(ctx->r8, 0X1);
    // 0x8017346C: jal         0x80173538
    // 0x80173470: sw          $t8, -0x2B5C($at)
    MEM_W(-0X2B5C, ctx->r1) = ctx->r24;
    func_80173538_1501A0(rdram, ctx);
        goto after_2;
    // 0x80173470: sw          $t8, -0x2B5C($at)
    MEM_W(-0X2B5C, ctx->r1) = ctx->r24;
    after_2:
L_80173474:
    // 0x80173474: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80173478: lhu         $t9, -0x2BA8($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X2BA8);
    // 0x8017347C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80173480: andi        $t2, $t9, 0x2
    ctx->r10 = ctx->r25 & 0X2;
    // 0x80173484: beq         $t2, $at, L_80173528
    if (ctx->r10 == ctx->r1) {
        // 0x80173488: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_80173528;
    }
    // 0x80173488: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017348C: lwc1        $f6, -0x2B0C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2B0C);
    // 0x80173490: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80173494: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80173498: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8017349C: lw          $a3, -0x2B10($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X2B10);
    // 0x801734A0: lw          $a2, -0x2B14($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X2B14);
    // 0x801734A4: lw          $a1, -0x2B18($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X2B18);
    // 0x801734A8: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x801734AC: jal         0x800D7120
    // 0x801734B0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    guAlignF_recomp(rdram, ctx);
        goto after_3;
    // 0x801734B0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_3:
    // 0x801734B4: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x801734B8: addiu       $t3, $t3, -0x2BA8
    ctx->r11 = ADD32(ctx->r11, -0X2BA8);
    // 0x801734BC: addiu       $t1, $t3, 0xA0
    ctx->r9 = ADD32(ctx->r11, 0XA0);
    // 0x801734C0: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x801734C4: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    // 0x801734C8: jal         0x800D6F30
    // 0x801734CC: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    guMtxCatF_recomp(rdram, ctx);
        goto after_4;
    // 0x801734CC: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_4:
    // 0x801734D0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x801734D4: lw          $t4, -0x2B48($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2B48);
    // 0x801734D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801734DC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801734E0: addiu       $t6, $t4, 0x1
    ctx->r14 = ADD32(ctx->r12, 0X1);
    // 0x801734E4: sw          $t6, -0x2B48($at)
    MEM_W(-0X2B48, ctx->r1) = ctx->r14;
    // 0x801734E8: lw          $t7, -0x2B50($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2B50);
    // 0x801734EC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x801734F0: lw          $t5, -0x2AC4($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2AC4);
    // 0x801734F4: sll         $t0, $t7, 2
    ctx->r8 = S32(ctx->r15 << 2);
    // 0x801734F8: addu        $t0, $t0, $t7
    ctx->r8 = ADD32(ctx->r8, ctx->r15);
    // 0x801734FC: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80173500: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80173504: addu        $t8, $t5, $t0
    ctx->r24 = ADD32(ctx->r13, ctx->r8);
    // 0x80173508: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x8017350C: lw          $t2, -0x2E34($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2E34);
    // 0x80173510: bne         $t9, $t2, L_80173528
    if (ctx->r25 != ctx->r10) {
        // 0x80173514: nop
    
            goto L_80173528;
    }
    // 0x80173514: nop

    // 0x80173518: addiu       $t3, $t7, 0x1
    ctx->r11 = ADD32(ctx->r15, 0X1);
    // 0x8017351C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80173520: jal         0x801735A8
    // 0x80173524: sw          $t3, -0x2B50($at)
    MEM_W(-0X2B50, ctx->r1) = ctx->r11;
    func_801735A8_1501A0(rdram, ctx);
        goto after_5;
    // 0x80173524: sw          $t3, -0x2B50($at)
    MEM_W(-0X2B50, ctx->r1) = ctx->r11;
    after_5:
L_80173528:
    // 0x80173528: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8017352C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x80173530: jr          $ra
    // 0x80173534: nop

    return;
    // 0x80173534: nop

;}
RECOMP_FUNC void func_80173538_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80173538: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017353C: lw          $t7, -0x2B5C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2B5C);
    // 0x80173540: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80173544: lw          $t6, -0x2AC8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2AC8);
    // 0x80173548: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x8017354C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80173550: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80173554: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x80173558: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8017355C: sh          $t0, 0x6($sp)
    MEM_H(0X6, ctx->r29) = ctx->r8;
    // 0x80173560: lhu         $t1, 0x10($t9)
    ctx->r9 = MEM_HU(ctx->r25, 0X10);
    // 0x80173564: bne         $t1, $at, L_80173584
    if (ctx->r9 != ctx->r1) {
        // 0x80173568: sh          $t1, 0x4($sp)
        MEM_H(0X4, ctx->r29) = ctx->r9;
            goto L_80173584;
    }
    // 0x80173568: sh          $t1, 0x4($sp)
    MEM_H(0X4, ctx->r29) = ctx->r9;
    // 0x8017356C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80173570: lhu         $t2, -0x2BA8($t2)
    ctx->r10 = MEM_HU(ctx->r10, -0X2BA8);
    // 0x80173574: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80173578: ori         $t3, $t2, 0x1
    ctx->r11 = ctx->r10 | 0X1;
    // 0x8017357C: b           L_801735A0
    // 0x80173580: sh          $t3, -0x2BA8($at)
    MEM_H(-0X2BA8, ctx->r1) = ctx->r11;
        goto L_801735A0;
    // 0x80173580: sh          $t3, -0x2BA8($at)
    MEM_H(-0X2BA8, ctx->r1) = ctx->r11;
L_80173584:
    // 0x80173584: lhu         $t4, 0x4($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X4);
    // 0x80173588: lhu         $t5, 0x6($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X6);
    // 0x8017358C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80173590: subu        $t7, $t4, $t5
    ctx->r15 = SUB32(ctx->r12, ctx->r13);
    // 0x80173594: sw          $t7, -0x2B58($at)
    MEM_W(-0X2B58, ctx->r1) = ctx->r15;
    // 0x80173598: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017359C: sw          $zero, -0x2B54($at)
    MEM_W(-0X2B54, ctx->r1) = 0;
L_801735A0:
    // 0x801735A0: jr          $ra
    // 0x801735A4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x801735A4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_801735A8_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801735A8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801735AC: lw          $t7, -0x2B50($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2B50);
    // 0x801735B0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801735B4: lw          $t6, -0x2AC4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2AC4);
    // 0x801735B8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x801735BC: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x801735C0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x801735C4: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x801735C8: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x801735CC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801735D0: sw          $t0, -0x2B4C($at)
    MEM_W(-0X2B4C, ctx->r1) = ctx->r8;
    // 0x801735D4: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x801735D8: bne         $t0, $at, L_801735F8
    if (ctx->r8 != ctx->r1) {
        // 0x801735DC: nop
    
            goto L_801735F8;
    }
    // 0x801735DC: nop

    // 0x801735E0: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x801735E4: lhu         $t1, -0x2BA8($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X2BA8);
    // 0x801735E8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801735EC: ori         $t2, $t1, 0x2
    ctx->r10 = ctx->r9 | 0X2;
    // 0x801735F0: jr          $ra
    // 0x801735F4: sh          $t2, -0x2BA8($at)
    MEM_H(-0X2BA8, ctx->r1) = ctx->r10;
    return;
    // 0x801735F4: sh          $t2, -0x2BA8($at)
    MEM_H(-0X2BA8, ctx->r1) = ctx->r10;
L_801735F8:
    // 0x801735F8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x801735FC: lw          $t4, -0x2B50($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2B50);
    // 0x80173600: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80173604: lw          $t6, -0x2B4C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2B4C);
    // 0x80173608: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017360C: lw          $t3, -0x2AC4($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2AC4);
    // 0x80173610: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80173614: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x80173618: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x8017361C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80173620: addu        $t7, $t3, $t5
    ctx->r15 = ADD32(ctx->r11, ctx->r13);
    // 0x80173624: lwc1        $f4, 0x4($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X4);
    // 0x80173628: bgez        $t6, L_80173640
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8017362C: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80173640;
    }
    // 0x8017362C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80173630: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80173634: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80173638: nop

    // 0x8017363C: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_80173640:
    // 0x80173640: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80173644: lw          $t8, -0x2E34($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2E34);
    // 0x80173648: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x8017364C: bgez        $t8, L_80173664
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80173650: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_80173664;
    }
    // 0x80173650: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80173654: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80173658: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017365C: nop

    // 0x80173660: add.s       $f18, $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f6.fl;
L_80173664:
    // 0x80173664: sub.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x80173668: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017366C: div.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f4.fl, ctx->f10.fl);
    // 0x80173670: swc1        $f16, -0x2B18($at)
    MEM_W(-0X2B18, ctx->r1) = ctx->f16.u32l;
    // 0x80173674: lwc1        $f6, 0x8($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X8);
    // 0x80173678: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017367C: swc1        $f6, -0x2B14($at)
    MEM_W(-0X2B14, ctx->r1) = ctx->f6.u32l;
    // 0x80173680: lwc1        $f8, 0xC($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0XC);
    // 0x80173684: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80173688: swc1        $f8, -0x2B10($at)
    MEM_W(-0X2B10, ctx->r1) = ctx->f8.u32l;
    // 0x8017368C: lwc1        $f18, 0x10($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0X10);
    // 0x80173690: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80173694: swc1        $f18, -0x2B0C($at)
    MEM_W(-0X2B0C, ctx->r1) = ctx->f18.u32l;
    // 0x80173698: jr          $ra
    // 0x8017369C: nop

    return;
    // 0x8017369C: nop

;}
RECOMP_FUNC void func_801736A0_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801736A0: addiu       $t6, $zero, 0x4000
    ctx->r14 = ADD32(0, 0X4000);
    // 0x801736A4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801736A8: sh          $t6, -0x2BA8($at)
    MEM_H(-0X2BA8, ctx->r1) = ctx->r14;
    // 0x801736AC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801736B0: sw          $zero, -0x2B5C($at)
    MEM_W(-0X2B5C, ctx->r1) = 0;
    // 0x801736B4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801736B8: lw          $t7, -0x2AC8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2AC8);
    // 0x801736BC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801736C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801736C4: lwc1        $f4, 0x4($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X4);
    // 0x801736C8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801736CC: swc1        $f4, -0x2B24($at)
    MEM_W(-0X2B24, ctx->r1) = ctx->f4.u32l;
    // 0x801736D0: lwc1        $f6, 0x8($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X8);
    // 0x801736D4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801736D8: swc1        $f6, -0x2B20($at)
    MEM_W(-0X2B20, ctx->r1) = ctx->f6.u32l;
    // 0x801736DC: lwc1        $f8, 0xC($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0XC);
    // 0x801736E0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801736E4: jal         0x80173538
    // 0x801736E8: swc1        $f8, -0x2B1C($at)
    MEM_W(-0X2B1C, ctx->r1) = ctx->f8.u32l;
    func_80173538_1501A0(rdram, ctx);
        goto after_0;
    // 0x801736E8: swc1        $f8, -0x2B1C($at)
    MEM_W(-0X2B1C, ctx->r1) = ctx->f8.u32l;
    after_0:
    // 0x801736EC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801736F0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801736F4: sw          $t8, -0x2B50($at)
    MEM_W(-0X2B50, ctx->r1) = ctx->r24;
    // 0x801736F8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801736FC: sw          $zero, -0x2B48($at)
    MEM_W(-0X2B48, ctx->r1) = 0;
    // 0x80173700: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80173704: lw          $t9, -0x2AC4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2AC4);
    // 0x80173708: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017370C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80173710: lwc1        $f10, 0x4($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X4);
    // 0x80173714: addiu       $a0, $a0, -0x2BA8
    ctx->r4 = ADD32(ctx->r4, -0X2BA8);
    // 0x80173718: addiu       $a0, $a0, 0xA0
    ctx->r4 = ADD32(ctx->r4, 0XA0);
    // 0x8017371C: swc1        $f10, -0x2B18($at)
    MEM_W(-0X2B18, ctx->r1) = ctx->f10.u32l;
    // 0x80173720: lwc1        $f16, 0x8($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X8);
    // 0x80173724: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80173728: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8017372C: swc1        $f16, -0x2B14($at)
    MEM_W(-0X2B14, ctx->r1) = ctx->f16.u32l;
    // 0x80173730: lwc1        $f18, 0xC($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0XC);
    // 0x80173734: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80173738: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x8017373C: swc1        $f18, -0x2B10($at)
    MEM_W(-0X2B10, ctx->r1) = ctx->f18.u32l;
    // 0x80173740: lwc1        $f4, 0x10($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X10);
    // 0x80173744: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80173748: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x8017374C: swc1        $f4, -0x2B0C($at)
    MEM_W(-0X2B0C, ctx->r1) = ctx->f4.u32l;
    // 0x80173750: jal         0x800D7120
    // 0x80173754: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    guAlignF_recomp(rdram, ctx);
        goto after_1;
    // 0x80173754: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80173758: jal         0x801735A8
    // 0x8017375C: nop

    func_801735A8_1501A0(rdram, ctx);
        goto after_2;
    // 0x8017375C: nop

    after_2:
    // 0x80173760: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80173764: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80173768: sw          $zero, -0x2BA0($at)
    MEM_W(-0X2BA0, ctx->r1) = 0;
    // 0x8017376C: addiu       $t1, $t1, -0x2BA8
    ctx->r9 = ADD32(ctx->r9, -0X2BA8);
    // 0x80173770: addiu       $t0, $zero, 0x64
    ctx->r8 = ADD32(0, 0X64);
    // 0x80173774: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80173778: addiu       $t2, $t2, -0x2BA8
    ctx->r10 = ADD32(ctx->r10, -0X2BA8);
    // 0x8017377C: sw          $t0, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->r8;
    // 0x80173780: lw          $t3, 0x10($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X10);
    // 0x80173784: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80173788: addiu       $t4, $t4, -0x2BA8
    ctx->r12 = ADD32(ctx->r12, -0X2BA8);
    // 0x8017378C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80173790: sw          $t3, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->r11;
    // 0x80173794: sw          $zero, 0x28($t4)
    MEM_W(0X28, ctx->r12) = 0;
    // 0x80173798: addiu       $t5, $t5, -0x2BA8
    ctx->r13 = ADD32(ctx->r13, -0X2BA8);
    // 0x8017379C: lw          $t6, 0x28($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X28);
    // 0x801737A0: sw          $t6, 0x24($t5)
    MEM_W(0X24, ctx->r13) = ctx->r14;
    // 0x801737A4: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_801737A8:
    // 0x801737A8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801737AC: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x801737B0: lw          $t9, -0x2E3C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2E3C);
    // 0x801737B4: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x801737B8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x801737BC: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x801737C0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801737C4: sll         $t3, $t1, 1
    ctx->r11 = S32(ctx->r9 << 1);
    // 0x801737C8: lw          $t7, -0x2E3C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2E3C);
    // 0x801737CC: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x801737D0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801737D4: addu        $t2, $t0, $t3
    ctx->r10 = ADD32(ctx->r8, ctx->r11);
    // 0x801737D8: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x801737DC: sll         $t4, $t2, 2
    ctx->r12 = S32(ctx->r10 << 2);
    // 0x801737E0: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x801737E4: addu        $t6, $t6, $t4
    ctx->r14 = ADD32(ctx->r14, ctx->r12);
    // 0x801737E8: lw          $t6, -0x2BDC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2BDC);
    // 0x801737EC: sw          $zero, -0x2B7C($at)
    MEM_W(-0X2B7C, ctx->r1) = 0;
    // 0x801737F0: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x801737F4: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x801737F8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801737FC: addu        $t3, $t8, $t0
    ctx->r11 = ADD32(ctx->r24, ctx->r8);
    // 0x80173800: sll         $t5, $t1, 2
    ctx->r13 = S32(ctx->r9 << 2);
    // 0x80173804: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x80173808: sll         $t2, $t3, 2
    ctx->r10 = S32(ctx->r11 << 2);
    // 0x8017380C: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x80173810: addu        $t4, $t4, $t2
    ctx->r12 = ADD32(ctx->r12, ctx->r10);
    // 0x80173814: sw          $t6, -0x2B44($at)
    MEM_W(-0X2B44, ctx->r1) = ctx->r14;
    // 0x80173818: lw          $t4, -0x2BD8($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2BD8);
    // 0x8017381C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80173820: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x80173824: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80173828: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8017382C: jal         0x80173864
    // 0x80173830: sw          $t4, -0x2B34($at)
    MEM_W(-0X2B34, ctx->r1) = ctx->r12;
    func_80173864_1501A0(rdram, ctx);
        goto after_3;
    // 0x80173830: sw          $t4, -0x2B34($at)
    MEM_W(-0X2B34, ctx->r1) = ctx->r12;
    after_3:
    // 0x80173834: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80173838: addiu       $t5, $t6, 0x1
    ctx->r13 = ADD32(ctx->r14, 0X1);
    // 0x8017383C: sltiu       $at, $t5, 0x4
    ctx->r1 = ctx->r13 < 0X4 ? 1 : 0;
    // 0x80173840: bne         $at, $zero, L_801737A8
    if (ctx->r1 != 0) {
        // 0x80173844: sw          $t5, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r13;
            goto L_801737A8;
    }
    // 0x80173844: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x80173848: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8017384C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80173850: sw          $zero, -0x2A3C($at)
    MEM_W(-0X2A3C, ctx->r1) = 0;
    // 0x80173854: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80173858: sw          $zero, -0x2A40($at)
    MEM_W(-0X2A40, ctx->r1) = 0;
    // 0x8017385C: jr          $ra
    // 0x80173860: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80173860: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80173864_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80173864: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80173868: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017386C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80173870: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80173874: sw          $zero, -0x2B6C($at)
    MEM_W(-0X2B6C, ctx->r1) = 0;
    // 0x80173878: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_8017387C:
    // 0x8017387C: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x80173880: sll         $t7, $a0, 3
    ctx->r15 = S32(ctx->r4 << 3);
    // 0x80173884: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x80173888: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x8017388C: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80173890: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x80173894: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80173898: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x8017389C: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x801738A0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801738A4: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x801738A8: sw          $zero, 0x3518($at)
    MEM_W(0X3518, ctx->r1) = 0;
    // 0x801738AC: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x801738B0: sltiu       $at, $t2, 0x4
    ctx->r1 = ctx->r10 < 0X4 ? 1 : 0;
    // 0x801738B4: bne         $at, $zero, L_8017387C
    if (ctx->r1 != 0) {
        // 0x801738B8: sw          $t2, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r10;
            goto L_8017387C;
    }
    // 0x801738B8: sw          $t2, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r10;
    // 0x801738BC: jr          $ra
    // 0x801738C0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x801738C0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_801738C4_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801738C4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801738C8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801738CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801738D0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x801738D4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801738D8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x801738DC: addiu       $t6, $t6, -0x2E28
    ctx->r14 = ADD32(ctx->r14, -0X2E28);
    // 0x801738E0: lbu         $t7, 0xA($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0XA);
    // 0x801738E4: andi        $t8, $t7, 0x2
    ctx->r24 = ctx->r15 & 0X2;
    // 0x801738E8: beq         $t8, $zero, L_80173904
    if (ctx->r24 == 0) {
        // 0x801738EC: nop
    
            goto L_80173904;
    }
    // 0x801738EC: nop

    // 0x801738F0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801738F4: addiu       $t9, $t9, -0x2E18
    ctx->r25 = ADD32(ctx->r25, -0X2E18);
    // 0x801738F8: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x801738FC: beq         $t0, $zero, L_80173C88
    if (ctx->r8 == 0) {
        // 0x80173900: nop
    
            goto L_80173C88;
    }
    // 0x80173900: nop

L_80173904:
    // 0x80173904: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80173908: lw          $t1, -0x2D68($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2D68);
    // 0x8017390C: bne         $t1, $zero, L_80173C88
    if (ctx->r9 != 0) {
        // 0x80173910: nop
    
            goto L_80173C88;
    }
    // 0x80173910: nop

    // 0x80173914: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80173918: addiu       $t2, $t2, -0x2E28
    ctx->r10 = ADD32(ctx->r10, -0X2E28);
    // 0x8017391C: lbu         $t3, 0xA($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0XA);
    // 0x80173920: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x80173924: bne         $t4, $zero, L_80173C88
    if (ctx->r12 != 0) {
        // 0x80173928: nop
    
            goto L_80173C88;
    }
    // 0x80173928: nop

    // 0x8017392C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80173930: addiu       $t5, $t5, -0x2E28
    ctx->r13 = ADD32(ctx->r13, -0X2E28);
    // 0x80173934: lbu         $t6, 0xC($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0XC);
    // 0x80173938: andi        $t7, $t6, 0x10
    ctx->r15 = ctx->r14 & 0X10;
    // 0x8017393C: bne         $t7, $zero, L_80173C88
    if (ctx->r15 != 0) {
        // 0x80173940: nop
    
            goto L_80173C88;
    }
    // 0x80173940: nop

    // 0x80173944: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80173948: lhu         $t8, -0x2BA8($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X2BA8);
    // 0x8017394C: andi        $t9, $t8, 0x4000
    ctx->r25 = ctx->r24 & 0X4000;
    // 0x80173950: bne         $t9, $zero, L_80173C88
    if (ctx->r25 != 0) {
        // 0x80173954: nop
    
            goto L_80173C88;
    }
    // 0x80173954: nop

    // 0x80173958: jal         0x80173C9C
    // 0x8017395C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_80173C9C_1501A0(rdram, ctx);
        goto after_0;
    // 0x8017395C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_0:
    // 0x80173960: bne         $v0, $zero, L_80173C88
    if (ctx->r2 != 0) {
        // 0x80173964: nop
    
            goto L_80173C88;
    }
    // 0x80173964: nop

    // 0x80173968: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8017396C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80173970: addiu       $t1, $zero, 0x10
    ctx->r9 = ADD32(0, 0X10);
    // 0x80173974: sll         $t3, $t0, 5
    ctx->r11 = S32(ctx->r8 << 5);
    // 0x80173978: addu        $s0, $s0, $t3
    ctx->r16 = ADD32(ctx->r16, ctx->r11);
    // 0x8017397C: lw          $s0, 0x39A8($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X39A8);
    // 0x80173980: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80173984: sllv        $t2, $t1, $t0
    ctx->r10 = S32(ctx->r9 << (ctx->r8 & 31));
    // 0x80173988: addiu       $s0, $s0, 0xA
    ctx->r16 = ADD32(ctx->r16, 0XA);
    // 0x8017398C: beq         $s0, $at, L_80173A78
    if (ctx->r16 == ctx->r1) {
        // 0x80173990: sw          $t2, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r10;
            goto L_80173A78;
    }
    // 0x80173990: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x80173994: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80173998: bne         $s0, $at, L_80173C88
    if (ctx->r16 != ctx->r1) {
        // 0x8017399C: nop
    
            goto L_80173C88;
    }
    // 0x8017399C: nop

    // 0x801739A0: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x801739A4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801739A8: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x801739AC: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x801739B0: sll         $t5, $t5, 5
    ctx->r13 = S32(ctx->r13 << 5);
    // 0x801739B4: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x801739B8: lw          $t6, 0x3518($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3518);
    // 0x801739BC: bne         $t6, $zero, L_801739D8
    if (ctx->r14 != 0) {
        // 0x801739C0: nop
    
            goto L_801739D8;
    }
    // 0x801739C0: nop

    // 0x801739C4: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x801739C8: jal         0x80174158
    // 0x801739CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80174158_1501A0(rdram, ctx);
        goto after_1;
    // 0x801739CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x801739D0: b           L_80173C88
    // 0x801739D4: nop

        goto L_80173C88;
    // 0x801739D4: nop

L_801739D8:
    // 0x801739D8: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x801739DC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x801739E0: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x801739E4: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x801739E8: sll         $t8, $t8, 5
    ctx->r24 = S32(ctx->r24 << 5);
    // 0x801739EC: addu        $a0, $a0, $t8
    ctx->r4 = ADD32(ctx->r4, ctx->r24);
    // 0x801739F0: jal         0x80173F3C
    // 0x801739F4: lw          $a0, 0x351C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X351C);
    func_80173F3C_1501A0(rdram, ctx);
        goto after_2;
    // 0x801739F4: lw          $a0, 0x351C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X351C);
    after_2:
    // 0x801739F8: bne         $v0, $zero, L_80173C88
    if (ctx->r2 != 0) {
        // 0x801739FC: nop
    
            goto L_80173C88;
    }
    // 0x801739FC: nop

    // 0x80173A00: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80173A04: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80173A08: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80173A0C: sll         $t1, $t9, 3
    ctx->r9 = S32(ctx->r25 << 3);
    // 0x80173A10: subu        $t1, $t1, $t9
    ctx->r9 = SUB32(ctx->r9, ctx->r25);
    // 0x80173A14: sll         $t0, $t2, 3
    ctx->r8 = S32(ctx->r10 << 3);
    // 0x80173A18: sll         $t1, $t1, 5
    ctx->r9 = S32(ctx->r9 << 5);
    // 0x80173A1C: subu        $t0, $t0, $t2
    ctx->r8 = SUB32(ctx->r8, ctx->r10);
    // 0x80173A20: sll         $t0, $t0, 5
    ctx->r8 = S32(ctx->r8 << 5);
    // 0x80173A24: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80173A28: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80173A2C: addu        $t3, $t3, $t0
    ctx->r11 = ADD32(ctx->r11, ctx->r8);
    // 0x80173A30: sw          $zero, 0x3518($at)
    MEM_W(0X3518, ctx->r1) = 0;
    // 0x80173A34: lw          $t3, 0x351C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X351C);
    // 0x80173A38: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80173A3C: addiu       $t6, $t6, -0x2A28
    ctx->r14 = ADD32(ctx->r14, -0X2A28);
    // 0x80173A40: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x80173A44: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x80173A48: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80173A4C: subu        $t5, $t5, $t3
    ctx->r13 = SUB32(ctx->r13, ctx->r11);
    // 0x80173A50: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80173A54: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x80173A58: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80173A5C: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80173A60: addu        $t4, $t5, $t6
    ctx->r12 = ADD32(ctx->r13, ctx->r14);
    // 0x80173A64: lhu         $t7, 0x0($t4)
    ctx->r15 = MEM_HU(ctx->r12, 0X0);
    // 0x80173A68: xori        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 ^ 0XFFFF;
    // 0x80173A6C: and         $t1, $t7, $t9
    ctx->r9 = ctx->r15 & ctx->r25;
    // 0x80173A70: b           L_80173C88
    // 0x80173A74: sh          $t1, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r9;
        goto L_80173C88;
    // 0x80173A74: sh          $t1, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r9;
L_80173A78:
    // 0x80173A78: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
L_80173A7C:
    // 0x80173A7C: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80173A80: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80173A84: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80173A88: sll         $t0, $t2, 3
    ctx->r8 = S32(ctx->r10 << 3);
    // 0x80173A8C: sll         $t5, $t3, 3
    ctx->r13 = S32(ctx->r11 << 3);
    // 0x80173A90: subu        $t0, $t0, $t2
    ctx->r8 = SUB32(ctx->r8, ctx->r10);
    // 0x80173A94: subu        $t5, $t5, $t3
    ctx->r13 = SUB32(ctx->r13, ctx->r11);
    // 0x80173A98: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x80173A9C: sll         $t0, $t0, 5
    ctx->r8 = S32(ctx->r8 << 5);
    // 0x80173AA0: addu        $t6, $t0, $t5
    ctx->r14 = ADD32(ctx->r8, ctx->r13);
    // 0x80173AA4: addiu       $t8, $t8, 0x3518
    ctx->r24 = ADD32(ctx->r24, 0X3518);
    // 0x80173AA8: addu        $t7, $t6, $t8
    ctx->r15 = ADD32(ctx->r14, ctx->r24);
    // 0x80173AAC: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80173AB0: beq         $t9, $zero, L_80173BEC
    if (ctx->r25 == 0) {
        // 0x80173AB4: nop
    
            goto L_80173BEC;
    }
    // 0x80173AB4: nop

    // 0x80173AB8: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80173ABC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80173AC0: sllv        $t2, $t4, $t3
    ctx->r10 = S32(ctx->r12 << (ctx->r11 & 31));
    // 0x80173AC4: addu        $t7, $t0, $t5
    ctx->r15 = ADD32(ctx->r8, ctx->r13);
    // 0x80173AC8: or          $t6, $t1, $t2
    ctx->r14 = ctx->r9 | ctx->r10;
    // 0x80173ACC: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x80173AD0: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80173AD4: jal         0x80173F3C
    // 0x80173AD8: lw          $a0, 0x4($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X4);
    func_80173F3C_1501A0(rdram, ctx);
        goto after_3;
    // 0x80173AD8: lw          $a0, 0x4($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X4);
    after_3:
    // 0x80173ADC: bne         $v0, $zero, L_80173BB4
    if (ctx->r2 != 0) {
        // 0x80173AE0: nop
    
            goto L_80173BB4;
    }
    // 0x80173AE0: nop

    // 0x80173AE4: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80173AE8: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80173AEC: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80173AF0: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80173AF4: sll         $t3, $t4, 3
    ctx->r11 = S32(ctx->r12 << 3);
    // 0x80173AF8: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x80173AFC: subu        $t3, $t3, $t4
    ctx->r11 = SUB32(ctx->r11, ctx->r12);
    // 0x80173B00: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x80173B04: sll         $t5, $t0, 3
    ctx->r13 = S32(ctx->r8 << 3);
    // 0x80173B08: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80173B0C: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x80173B10: sll         $t3, $t3, 5
    ctx->r11 = S32(ctx->r11 << 5);
    // 0x80173B14: subu        $t5, $t5, $t0
    ctx->r13 = SUB32(ctx->r13, ctx->r8);
    // 0x80173B18: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80173B1C: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80173B20: sll         $t5, $t5, 5
    ctx->r13 = S32(ctx->r13 << 5);
    // 0x80173B24: addu        $t6, $t3, $t2
    ctx->r14 = ADD32(ctx->r11, ctx->r10);
    // 0x80173B28: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80173B2C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80173B30: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80173B34: addiu       $t4, $t4, 0x3518
    ctx->r12 = ADD32(ctx->r12, 0X3518);
    // 0x80173B38: addu        $t9, $t5, $t8
    ctx->r25 = ADD32(ctx->r13, ctx->r24);
    // 0x80173B3C: addu        $t1, $t9, $t4
    ctx->r9 = ADD32(ctx->r25, ctx->r12);
    // 0x80173B40: sw          $zero, 0x3518($at)
    MEM_W(0X3518, ctx->r1) = 0;
    // 0x80173B44: lw          $t3, 0x4($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X4);
    // 0x80173B48: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80173B4C: addiu       $t6, $t6, -0x2A28
    ctx->r14 = ADD32(ctx->r14, -0X2A28);
    // 0x80173B50: sll         $t2, $t3, 2
    ctx->r10 = S32(ctx->r11 << 2);
    // 0x80173B54: addu        $t2, $t2, $t3
    ctx->r10 = ADD32(ctx->r10, ctx->r11);
    // 0x80173B58: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80173B5C: subu        $t2, $t2, $t3
    ctx->r10 = SUB32(ctx->r10, ctx->r11);
    // 0x80173B60: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80173B64: addu        $t2, $t2, $t3
    ctx->r10 = ADD32(ctx->r10, ctx->r11);
    // 0x80173B68: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80173B6C: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80173B70: addu        $t0, $t2, $t6
    ctx->r8 = ADD32(ctx->r10, ctx->r14);
    // 0x80173B74: lhu         $t7, 0x0($t0)
    ctx->r15 = MEM_HU(ctx->r8, 0X0);
    // 0x80173B78: addu        $t2, $t5, $t8
    ctx->r10 = ADD32(ctx->r13, ctx->r24);
    // 0x80173B7C: addu        $t0, $t2, $t4
    ctx->r8 = ADD32(ctx->r10, ctx->r12);
    // 0x80173B80: xori        $t1, $t9, 0xFFFF
    ctx->r9 = ctx->r25 ^ 0XFFFF;
    // 0x80173B84: lw          $t9, 0x4($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X4);
    // 0x80173B88: and         $t3, $t7, $t1
    ctx->r11 = ctx->r15 & ctx->r9;
    // 0x80173B8C: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x80173B90: addu        $t7, $t7, $t9
    ctx->r15 = ADD32(ctx->r15, ctx->r25);
    // 0x80173B94: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80173B98: subu        $t7, $t7, $t9
    ctx->r15 = SUB32(ctx->r15, ctx->r25);
    // 0x80173B9C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80173BA0: addu        $t7, $t7, $t9
    ctx->r15 = ADD32(ctx->r15, ctx->r25);
    // 0x80173BA4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80173BA8: addu        $t1, $t7, $t6
    ctx->r9 = ADD32(ctx->r15, ctx->r14);
    // 0x80173BAC: b           L_80173BEC
    // 0x80173BB0: sh          $t3, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r11;
        goto L_80173BEC;
    // 0x80173BB0: sh          $t3, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r11;
L_80173BB4:
    // 0x80173BB4: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x80173BB8: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80173BBC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80173BC0: sll         $t8, $t5, 3
    ctx->r24 = S32(ctx->r13 << 3);
    // 0x80173BC4: sll         $t4, $t2, 3
    ctx->r12 = S32(ctx->r10 << 3);
    // 0x80173BC8: subu        $t8, $t8, $t5
    ctx->r24 = SUB32(ctx->r24, ctx->r13);
    // 0x80173BCC: subu        $t4, $t4, $t2
    ctx->r12 = SUB32(ctx->r12, ctx->r10);
    // 0x80173BD0: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x80173BD4: sll         $t8, $t8, 5
    ctx->r24 = S32(ctx->r24 << 5);
    // 0x80173BD8: addu        $t0, $t8, $t4
    ctx->r8 = ADD32(ctx->r24, ctx->r12);
    // 0x80173BDC: addu        $t9, $t9, $t0
    ctx->r25 = ADD32(ctx->r25, ctx->r8);
    // 0x80173BE0: lw          $t9, 0x3520($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X3520);
    // 0x80173BE4: beq         $t9, $zero, L_80173C88
    if (ctx->r25 == 0) {
        // 0x80173BE8: nop
    
            goto L_80173C88;
    }
    // 0x80173BE8: nop

L_80173BEC:
    // 0x80173BEC: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80173BF0: addiu       $t6, $t7, 0x1
    ctx->r14 = ADD32(ctx->r15, 0X1);
    // 0x80173BF4: sltiu       $at, $t6, 0x4
    ctx->r1 = ctx->r14 < 0X4 ? 1 : 0;
    // 0x80173BF8: bne         $at, $zero, L_80173A7C
    if (ctx->r1 != 0) {
        // 0x80173BFC: sw          $t6, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r14;
            goto L_80173A7C;
    }
    // 0x80173BFC: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x80173C00: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80173C04: andi        $t1, $t3, 0x1
    ctx->r9 = ctx->r11 & 0X1;
    // 0x80173C08: bne         $t1, $zero, L_80173C24
    if (ctx->r9 != 0) {
        // 0x80173C0C: nop
    
            goto L_80173C24;
    }
    // 0x80173C0C: nop

    // 0x80173C10: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80173C14: jal         0x80174158
    // 0x80173C18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80174158_1501A0(rdram, ctx);
        goto after_4;
    // 0x80173C18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80173C1C: b           L_80173C88
    // 0x80173C20: nop

        goto L_80173C88;
    // 0x80173C20: nop

L_80173C24:
    // 0x80173C24: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80173C28: andi        $t2, $t5, 0x2
    ctx->r10 = ctx->r13 & 0X2;
    // 0x80173C2C: bne         $t2, $zero, L_80173C48
    if (ctx->r10 != 0) {
        // 0x80173C30: nop
    
            goto L_80173C48;
    }
    // 0x80173C30: nop

    // 0x80173C34: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80173C38: jal         0x80174158
    // 0x80173C3C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80174158_1501A0(rdram, ctx);
        goto after_5;
    // 0x80173C3C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80173C40: b           L_80173C88
    // 0x80173C44: nop

        goto L_80173C88;
    // 0x80173C44: nop

L_80173C48:
    // 0x80173C48: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80173C4C: andi        $t4, $t8, 0x4
    ctx->r12 = ctx->r24 & 0X4;
    // 0x80173C50: bne         $t4, $zero, L_80173C6C
    if (ctx->r12 != 0) {
        // 0x80173C54: nop
    
            goto L_80173C6C;
    }
    // 0x80173C54: nop

    // 0x80173C58: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80173C5C: jal         0x80174158
    // 0x80173C60: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80174158_1501A0(rdram, ctx);
        goto after_6;
    // 0x80173C60: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_6:
    // 0x80173C64: b           L_80173C88
    // 0x80173C68: nop

        goto L_80173C88;
    // 0x80173C68: nop

L_80173C6C:
    // 0x80173C6C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80173C70: andi        $t9, $t0, 0x8
    ctx->r25 = ctx->r8 & 0X8;
    // 0x80173C74: bne         $t9, $zero, L_80173C88
    if (ctx->r25 != 0) {
        // 0x80173C78: nop
    
            goto L_80173C88;
    }
    // 0x80173C78: nop

    // 0x80173C7C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80173C80: jal         0x80174158
    // 0x80173C84: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80174158_1501A0(rdram, ctx);
        goto after_7;
    // 0x80173C84: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_7:
L_80173C88:
    // 0x80173C88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80173C8C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80173C90: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80173C94: jr          $ra
    // 0x80173C98: nop

    return;
    // 0x80173C98: nop

;}
RECOMP_FUNC void func_80173C9C_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80173C9C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80173CA0: lw          $t6, -0x2E48($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2E48);
    // 0x80173CA4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80173CA8: beq         $t6, $at, L_80173CCC
    if (ctx->r14 == ctx->r1) {
        // 0x80173CAC: nop
    
            goto L_80173CCC;
    }
    // 0x80173CAC: nop

    // 0x80173CB0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80173CB4: addiu       $t7, $t7, -0x2BA8
    ctx->r15 = ADD32(ctx->r15, -0X2BA8);
    // 0x80173CB8: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80173CBC: bne         $t8, $zero, L_80173D14
    if (ctx->r24 != 0) {
        // 0x80173CC0: nop
    
            goto L_80173D14;
    }
    // 0x80173CC0: nop

    // 0x80173CC4: jr          $ra
    // 0x80173CC8: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    return;
    // 0x80173CC8: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_80173CCC:
    // 0x80173CCC: beq         $a0, $zero, L_80173CDC
    if (ctx->r4 == 0) {
        // 0x80173CD0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80173CDC;
    }
    // 0x80173CD0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80173CD4: bne         $a0, $at, L_80173CF8
    if (ctx->r4 != ctx->r1) {
        // 0x80173CD8: nop
    
            goto L_80173CF8;
    }
    // 0x80173CD8: nop

L_80173CDC:
    // 0x80173CDC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80173CE0: addiu       $t9, $t9, -0x2BA8
    ctx->r25 = ADD32(ctx->r25, -0X2BA8);
    // 0x80173CE4: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x80173CE8: bne         $t0, $zero, L_80173D14
    if (ctx->r8 != 0) {
        // 0x80173CEC: nop
    
            goto L_80173D14;
    }
    // 0x80173CEC: nop

    // 0x80173CF0: jr          $ra
    // 0x80173CF4: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    return;
    // 0x80173CF4: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_80173CF8:
    // 0x80173CF8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80173CFC: addiu       $t1, $t1, -0x2BA8
    ctx->r9 = ADD32(ctx->r9, -0X2BA8);
    // 0x80173D00: lw          $t2, 0x10($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X10);
    // 0x80173D04: bne         $t2, $zero, L_80173D14
    if (ctx->r10 != 0) {
        // 0x80173D08: nop
    
            goto L_80173D14;
    }
    // 0x80173D08: nop

    // 0x80173D0C: jr          $ra
    // 0x80173D10: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    return;
    // 0x80173D10: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_80173D14:
    // 0x80173D14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80173D18: jr          $ra
    // 0x80173D1C: nop

    return;
    // 0x80173D1C: nop

;}
RECOMP_FUNC void func_80173D20_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80173D20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80173D24: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80173D28: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80173D2C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80173D30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80173D34: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80173D38: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80173D3C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80173D40: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80173D44: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80173D48: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80173D4C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80173D50: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80173D54: lhu         $t8, -0x2A28($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X2A28);
    // 0x80173D58: andi        $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 & 0X8000;
    // 0x80173D5C: bne         $t9, $zero, L_80173D6C
    if (ctx->r25 != 0) {
        // 0x80173D60: nop
    
            goto L_80173D6C;
    }
    // 0x80173D60: nop

    // 0x80173D64: b           L_80173F2C
    // 0x80173D68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80173F2C;
    // 0x80173D68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80173D6C:
    // 0x80173D6C: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80173D70: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80173D74: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80173D78: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80173D7C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80173D80: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x80173D84: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80173D88: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80173D8C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80173D90: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80173D94: lhu         $t2, -0x2A28($t2)
    ctx->r10 = MEM_HU(ctx->r10, -0X2A28);
    // 0x80173D98: andi        $t3, $t2, 0x2000
    ctx->r11 = ctx->r10 & 0X2000;
    // 0x80173D9C: beq         $t3, $zero, L_80173DAC
    if (ctx->r11 == 0) {
        // 0x80173DA0: nop
    
            goto L_80173DAC;
    }
    // 0x80173DA0: nop

    // 0x80173DA4: b           L_80173F2C
    // 0x80173DA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80173F2C;
    // 0x80173DA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80173DAC:
    // 0x80173DAC: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x80173DB0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80173DB4: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80173DB8: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x80173DBC: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80173DC0: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x80173DC4: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80173DC8: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x80173DCC: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80173DD0: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80173DD4: lhu         $t6, -0x2A28($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X2A28);
    // 0x80173DD8: andi        $t7, $t6, 0x400
    ctx->r15 = ctx->r14 & 0X400;
    // 0x80173DDC: beq         $t7, $zero, L_80173DEC
    if (ctx->r15 == 0) {
        // 0x80173DE0: nop
    
            goto L_80173DEC;
    }
    // 0x80173DE0: nop

    // 0x80173DE4: b           L_80173F2C
    // 0x80173DE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80173F2C;
    // 0x80173DE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80173DEC:
    // 0x80173DEC: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80173DF0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80173DF4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80173DF8: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80173DFC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80173E00: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80173E04: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80173E08: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80173E0C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80173E10: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80173E14: lhu         $t0, -0x2A28($t0)
    ctx->r8 = MEM_HU(ctx->r8, -0X2A28);
    // 0x80173E18: andi        $t1, $t0, 0x800
    ctx->r9 = ctx->r8 & 0X800;
    // 0x80173E1C: bne         $t1, $zero, L_80173E2C
    if (ctx->r9 != 0) {
        // 0x80173E20: nop
    
            goto L_80173E2C;
    }
    // 0x80173E20: nop

    // 0x80173E24: b           L_80173F2C
    // 0x80173E28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80173F2C;
    // 0x80173E28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80173E2C:
    // 0x80173E2C: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x80173E30: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80173E34: lw          $t4, -0x2E44($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2E44);
    // 0x80173E38: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80173E3C: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80173E40: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80173E44: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x80173E48: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80173E4C: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80173E50: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80173E54: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80173E58: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x80173E5C: lwc1        $f4, -0x2994($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2994);
    // 0x80173E60: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x80173E64: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80173E68: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80173E6C: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80173E70: lwc1        $f6, -0x2B3C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2B3C);
    // 0x80173E74: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80173E78: nop

    // 0x80173E7C: bc1t        L_80173EA4
    if (c1cs) {
        // 0x80173E80: lui         $at, 0x4448
        ctx->r1 = S32(0X4448 << 16);
            goto L_80173EA4;
    }
    // 0x80173E80: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x80173E84: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80173E88: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80173E8C: lwc1        $f10, -0x2E30($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x80173E90: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80173E94: c.lt.s      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.fl < ctx->f4.fl;
    // 0x80173E98: nop

    // 0x80173E9C: bc1f        L_80173EAC
    if (!c1cs) {
        // 0x80173EA0: nop
    
            goto L_80173EAC;
    }
    // 0x80173EA0: nop

L_80173EA4:
    // 0x80173EA4: b           L_80173F2C
    // 0x80173EA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80173F2C;
    // 0x80173EA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80173EAC:
    // 0x80173EAC: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80173EB0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80173EB4: addiu       $t9, $t9, -0x2A28
    ctx->r25 = ADD32(ctx->r25, -0X2A28);
    // 0x80173EB8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80173EBC: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80173EC0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80173EC4: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80173EC8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80173ECC: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80173ED0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80173ED4: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80173ED8: lwc1        $f12, 0x60($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0X60);
    // 0x80173EDC: lwc1        $f14, 0x64($t0)
    ctx->f14.u32l = MEM_W(ctx->r8, 0X64);
    // 0x80173EE0: jal         0x8019C46C
    // 0x80173EE4: lw          $a2, 0x68($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X68);
    func_8019C46C_1501A0(rdram, ctx);
        goto after_0;
    // 0x80173EE4: lw          $a2, 0x68($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X68);
    after_0:
    // 0x80173EE8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80173EEC: addiu       $t1, $t1, 0x3D00
    ctx->r9 = ADD32(ctx->r9, 0X3D00);
    // 0x80173EF0: jal         0x800E4D30
    // 0x80173EF4: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    func_800E4D30(rdram, ctx);
        goto after_1;
    // 0x80173EF4: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    after_1:
    // 0x80173EF8: slti        $at, $v0, 0x8C
    ctx->r1 = SIGNED(ctx->r2) < 0X8C ? 1 : 0;
    // 0x80173EFC: beq         $at, $zero, L_80173F20
    if (ctx->r1 == 0) {
        // 0x80173F00: nop
    
            goto L_80173F20;
    }
    // 0x80173F00: nop

    // 0x80173F04: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80173F08: addiu       $t2, $t2, 0x3D00
    ctx->r10 = ADD32(ctx->r10, 0X3D00);
    // 0x80173F0C: jal         0x800E4D30
    // 0x80173F10: lw          $a0, 0x4($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X4);
    func_800E4D30(rdram, ctx);
        goto after_2;
    // 0x80173F10: lw          $a0, 0x4($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X4);
    after_2:
    // 0x80173F14: slti        $at, $v0, 0x64
    ctx->r1 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x80173F18: bne         $at, $zero, L_80173F28
    if (ctx->r1 != 0) {
        // 0x80173F1C: nop
    
            goto L_80173F28;
    }
    // 0x80173F1C: nop

L_80173F20:
    // 0x80173F20: b           L_80173F2C
    // 0x80173F24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80173F2C;
    // 0x80173F24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80173F28:
    // 0x80173F28: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_80173F2C:
    // 0x80173F2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80173F30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80173F34: jr          $ra
    // 0x80173F38: nop

    return;
    // 0x80173F38: nop

;}
RECOMP_FUNC void func_80173F3C_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80173F3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80173F40: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80173F44: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80173F48: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80173F4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80173F50: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80173F54: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80173F58: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80173F5C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80173F60: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80173F64: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80173F68: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80173F6C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80173F70: lhu         $t8, -0x2A28($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X2A28);
    // 0x80173F74: andi        $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 & 0X8000;
    // 0x80173F78: bne         $t9, $zero, L_80173F88
    if (ctx->r25 != 0) {
        // 0x80173F7C: nop
    
            goto L_80173F88;
    }
    // 0x80173F7C: nop

    // 0x80173F80: b           L_80174148
    // 0x80173F84: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80174148;
    // 0x80173F84: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80173F88:
    // 0x80173F88: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80173F8C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80173F90: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80173F94: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80173F98: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80173F9C: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x80173FA0: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80173FA4: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80173FA8: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80173FAC: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80173FB0: lhu         $t2, -0x2A28($t2)
    ctx->r10 = MEM_HU(ctx->r10, -0X2A28);
    // 0x80173FB4: andi        $t3, $t2, 0x2000
    ctx->r11 = ctx->r10 & 0X2000;
    // 0x80173FB8: beq         $t3, $zero, L_80173FC8
    if (ctx->r11 == 0) {
        // 0x80173FBC: nop
    
            goto L_80173FC8;
    }
    // 0x80173FBC: nop

    // 0x80173FC0: b           L_80174148
    // 0x80173FC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80174148;
    // 0x80173FC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80173FC8:
    // 0x80173FC8: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x80173FCC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80173FD0: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80173FD4: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x80173FD8: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80173FDC: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x80173FE0: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80173FE4: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x80173FE8: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80173FEC: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80173FF0: lhu         $t6, -0x2A28($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X2A28);
    // 0x80173FF4: andi        $t7, $t6, 0x400
    ctx->r15 = ctx->r14 & 0X400;
    // 0x80173FF8: beq         $t7, $zero, L_80174008
    if (ctx->r15 == 0) {
        // 0x80173FFC: nop
    
            goto L_80174008;
    }
    // 0x80173FFC: nop

    // 0x80174000: b           L_80174148
    // 0x80174004: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80174148;
    // 0x80174004: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80174008:
    // 0x80174008: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8017400C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80174010: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80174014: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80174018: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8017401C: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80174020: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80174024: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80174028: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8017402C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80174030: lhu         $t0, -0x2A28($t0)
    ctx->r8 = MEM_HU(ctx->r8, -0X2A28);
    // 0x80174034: andi        $t1, $t0, 0x800
    ctx->r9 = ctx->r8 & 0X800;
    // 0x80174038: bne         $t1, $zero, L_80174048
    if (ctx->r9 != 0) {
        // 0x8017403C: nop
    
            goto L_80174048;
    }
    // 0x8017403C: nop

    // 0x80174040: b           L_80174148
    // 0x80174044: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80174148;
    // 0x80174044: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80174048:
    // 0x80174048: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x8017404C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80174050: lw          $t4, -0x2E44($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2E44);
    // 0x80174054: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80174058: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8017405C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80174060: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x80174064: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80174068: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8017406C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80174070: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80174074: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x80174078: lwc1        $f4, -0x2994($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2994);
    // 0x8017407C: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x80174080: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80174084: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80174088: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8017408C: lwc1        $f6, -0x2B38($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2B38);
    // 0x80174090: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80174094: nop

    // 0x80174098: bc1t        L_801740C0
    if (c1cs) {
        // 0x8017409C: lui         $at, 0x4461
        ctx->r1 = S32(0X4461 << 16);
            goto L_801740C0;
    }
    // 0x8017409C: lui         $at, 0x4461
    ctx->r1 = S32(0X4461 << 16);
    // 0x801740A0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801740A4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801740A8: lwc1        $f10, -0x2E30($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x801740AC: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x801740B0: c.lt.s      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.fl < ctx->f4.fl;
    // 0x801740B4: nop

    // 0x801740B8: bc1f        L_801740C8
    if (!c1cs) {
        // 0x801740BC: nop
    
            goto L_801740C8;
    }
    // 0x801740BC: nop

L_801740C0:
    // 0x801740C0: b           L_80174148
    // 0x801740C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80174148;
    // 0x801740C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801740C8:
    // 0x801740C8: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x801740CC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801740D0: addiu       $t9, $t9, -0x2A28
    ctx->r25 = ADD32(ctx->r25, -0X2A28);
    // 0x801740D4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x801740D8: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x801740DC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x801740E0: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x801740E4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x801740E8: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x801740EC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x801740F0: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x801740F4: lwc1        $f12, 0x60($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0X60);
    // 0x801740F8: lwc1        $f14, 0x64($t0)
    ctx->f14.u32l = MEM_W(ctx->r8, 0X64);
    // 0x801740FC: jal         0x8019C46C
    // 0x80174100: lw          $a2, 0x68($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X68);
    func_8019C46C_1501A0(rdram, ctx);
        goto after_0;
    // 0x80174100: lw          $a2, 0x68($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X68);
    after_0:
    // 0x80174104: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80174108: addiu       $t1, $t1, 0x3D00
    ctx->r9 = ADD32(ctx->r9, 0X3D00);
    // 0x8017410C: jal         0x800E4D30
    // 0x80174110: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    func_800E4D30(rdram, ctx);
        goto after_1;
    // 0x80174110: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    after_1:
    // 0x80174114: slti        $at, $v0, 0x96
    ctx->r1 = SIGNED(ctx->r2) < 0X96 ? 1 : 0;
    // 0x80174118: beq         $at, $zero, L_8017413C
    if (ctx->r1 == 0) {
        // 0x8017411C: nop
    
            goto L_8017413C;
    }
    // 0x8017411C: nop

    // 0x80174120: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80174124: addiu       $t2, $t2, 0x3D00
    ctx->r10 = ADD32(ctx->r10, 0X3D00);
    // 0x80174128: jal         0x800E4D30
    // 0x8017412C: lw          $a0, 0x4($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X4);
    func_800E4D30(rdram, ctx);
        goto after_2;
    // 0x8017412C: lw          $a0, 0x4($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X4);
    after_2:
    // 0x80174130: slti        $at, $v0, 0x6E
    ctx->r1 = SIGNED(ctx->r2) < 0X6E ? 1 : 0;
    // 0x80174134: bne         $at, $zero, L_80174144
    if (ctx->r1 != 0) {
        // 0x80174138: nop
    
            goto L_80174144;
    }
    // 0x80174138: nop

L_8017413C:
    // 0x8017413C: b           L_80174148
    // 0x80174140: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80174148;
    // 0x80174140: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80174144:
    // 0x80174144: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_80174148:
    // 0x80174148: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017414C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80174150: jr          $ra
    // 0x80174154: nop

    return;
    // 0x80174154: nop

;}
RECOMP_FUNC void func_80174158_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80174158: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8017415C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80174160: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80174164: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x80174168: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8017416C: sllv        $t8, $t7, $t6
    ctx->r24 = S32(ctx->r15 << (ctx->r14 & 31));
    // 0x80174170: xori        $t9, $t8, 0xF0
    ctx->r25 = ctx->r24 ^ 0XF0;
    // 0x80174174: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80174178: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8017417C: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x80174180: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x80174184: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_80174188:
    // 0x80174188: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8017418C: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80174190: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80174194: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80174198: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8017419C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x801741A0: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x801741A4: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x801741A8: sw          $zero, 0x3D78($at)
    MEM_W(0X3D78, ctx->r1) = 0;
    // 0x801741AC: lw          $t4, 0x3D78($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X3D78);
    // 0x801741B0: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x801741B4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801741B8: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x801741BC: sw          $t4, 0x3C14($at)
    MEM_W(0X3C14, ctx->r1) = ctx->r12;
    // 0x801741C0: addiu       $t7, $t5, 0x1
    ctx->r15 = ADD32(ctx->r13, 0X1);
    // 0x801741C4: sltiu       $at, $t7, 0x5
    ctx->r1 = ctx->r15 < 0X5 ? 1 : 0;
    // 0x801741C8: bne         $at, $zero, L_80174188
    if (ctx->r1 != 0) {
        // 0x801741CC: sw          $t7, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r15;
            goto L_80174188;
    }
    // 0x801741CC: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x801741D0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801741D4: addiu       $t6, $t6, 0x3C00
    ctx->r14 = ADD32(ctx->r14, 0X3C00);
    // 0x801741D8: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x801741DC: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
    // 0x801741E0: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x801741E4: sltiu       $at, $t8, 0x30
    ctx->r1 = ctx->r24 < 0X30 ? 1 : 0;
    // 0x801741E8: beq         $at, $zero, L_80174338
    if (ctx->r1 == 0) {
        // 0x801741EC: nop
    
            goto L_80174338;
    }
    // 0x801741EC: nop

L_801741F0:
    // 0x801741F0: jal         0x80173D20
    // 0x801741F4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_80173D20_1501A0(rdram, ctx);
        goto after_0;
    // 0x801741F4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_0:
    // 0x801741F8: beq         $v0, $zero, L_80174324
    if (ctx->r2 == 0) {
        // 0x801741FC: nop
    
            goto L_80174324;
    }
    // 0x801741FC: nop

    // 0x80174200: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80174204: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80174208: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8017420C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80174210: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80174214: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80174218: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x8017421C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80174220: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80174224: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80174228: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8017422C: lhu         $t1, -0x2A28($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X2A28);
    // 0x80174230: and         $t4, $t1, $t2
    ctx->r12 = ctx->r9 & ctx->r10;
    // 0x80174234: bne         $t4, $zero, L_80174324
    if (ctx->r12 != 0) {
        // 0x80174238: nop
    
            goto L_80174324;
    }
    // 0x80174238: nop

    // 0x8017423C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80174240: addiu       $t3, $t3, 0x3C00
    ctx->r11 = ADD32(ctx->r11, 0X3C00);
    // 0x80174244: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x80174248: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017424C: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x80174250: addu        $t6, $t7, $t3
    ctx->r14 = ADD32(ctx->r15, ctx->r11);
    // 0x80174254: sw          $t9, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r25;
    // 0x80174258: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8017425C: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80174260: sll         $t0, $t8, 2
    ctx->r8 = S32(ctx->r24 << 2);
    // 0x80174264: addu        $t0, $t0, $t8
    ctx->r8 = ADD32(ctx->r8, ctx->r24);
    // 0x80174268: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8017426C: subu        $t0, $t0, $t8
    ctx->r8 = SUB32(ctx->r8, ctx->r24);
    // 0x80174270: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80174274: addu        $t0, $t0, $t8
    ctx->r8 = ADD32(ctx->r8, ctx->r24);
    // 0x80174278: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8017427C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80174280: lhu         $t1, -0x2A28($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X2A28);
    // 0x80174284: and         $t4, $t1, $t2
    ctx->r12 = ctx->r9 & ctx->r10;
    // 0x80174288: beq         $t4, $zero, L_801742B4
    if (ctx->r12 == 0) {
        // 0x8017428C: nop
    
            goto L_801742B4;
    }
    // 0x8017428C: nop

    // 0x80174290: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80174294: addiu       $t7, $t7, 0x3C00
    ctx->r15 = ADD32(ctx->r15, 0X3C00);
    // 0x80174298: lw          $t3, 0x0($t7)
    ctx->r11 = MEM_W(ctx->r15, 0X0);
    // 0x8017429C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801742A0: addiu       $t5, $zero, 0x118
    ctx->r13 = ADD32(0, 0X118);
    // 0x801742A4: sll         $t9, $t3, 2
    ctx->r25 = S32(ctx->r11 << 2);
    // 0x801742A8: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x801742AC: b           L_801742F8
    // 0x801742B0: sw          $t5, 0x3D78($at)
    MEM_W(0X3D78, ctx->r1) = ctx->r13;
        goto L_801742F8;
    // 0x801742B0: sw          $t5, 0x3D78($at)
    MEM_W(0X3D78, ctx->r1) = ctx->r13;
L_801742B4:
    // 0x801742B4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801742B8: addiu       $t6, $t6, 0x3D00
    ctx->r14 = ADD32(ctx->r14, 0X3D00);
    // 0x801742BC: jal         0x800E4D30
    // 0x801742C0: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_800E4D30(rdram, ctx);
        goto after_1;
    // 0x801742C0: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_1:
    // 0x801742C4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x801742C8: addiu       $t8, $t8, 0x3D00
    ctx->r24 = ADD32(ctx->r24, 0X3D00);
    // 0x801742CC: lw          $a0, 0x4($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X4);
    // 0x801742D0: jal         0x800E4D30
    // 0x801742D4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    func_800E4D30(rdram, ctx);
        goto after_2;
    // 0x801742D4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    after_2:
    // 0x801742D8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x801742DC: addiu       $t1, $t1, 0x3C00
    ctx->r9 = ADD32(ctx->r9, 0X3C00);
    // 0x801742E0: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x801742E4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801742E8: addu        $t0, $v0, $s0
    ctx->r8 = ADD32(ctx->r2, ctx->r16);
    // 0x801742EC: sll         $t4, $t2, 2
    ctx->r12 = S32(ctx->r10 << 2);
    // 0x801742F0: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x801742F4: sw          $t0, 0x3D78($at)
    MEM_W(0X3D78, ctx->r1) = ctx->r8;
L_801742F8:
    // 0x801742F8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801742FC: addiu       $t7, $t7, 0x3C00
    ctx->r15 = ADD32(ctx->r15, 0X3C00);
    // 0x80174300: lw          $t3, 0x0($t7)
    ctx->r11 = MEM_W(ctx->r15, 0X0);
    // 0x80174304: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80174308: addiu       $t9, $t9, 0x3C00
    ctx->r25 = ADD32(ctx->r25, 0X3C00);
    // 0x8017430C: addiu       $t5, $t3, 0x1
    ctx->r13 = ADD32(ctx->r11, 0X1);
    // 0x80174310: sw          $t5, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r13;
    // 0x80174314: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x80174318: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8017431C: beq         $t6, $at, L_80174338
    if (ctx->r14 == ctx->r1) {
        // 0x80174320: nop
    
            goto L_80174338;
    }
    // 0x80174320: nop

L_80174324:
    // 0x80174324: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80174328: addiu       $t1, $t8, 0x1
    ctx->r9 = ADD32(ctx->r24, 0X1);
    // 0x8017432C: sltiu       $at, $t1, 0x30
    ctx->r1 = ctx->r9 < 0X30 ? 1 : 0;
    // 0x80174330: bne         $at, $zero, L_801741F0
    if (ctx->r1 != 0) {
        // 0x80174334: sw          $t1, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r9;
            goto L_801741F0;
    }
    // 0x80174334: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
L_80174338:
    // 0x80174338: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017433C: addiu       $t2, $t2, 0x3C00
    ctx->r10 = ADD32(ctx->r10, 0X3C00);
    // 0x80174340: lw          $t0, 0x0($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X0);
    // 0x80174344: beq         $t0, $zero, L_8017458C
    if (ctx->r8 == 0) {
        // 0x80174348: nop
    
            goto L_8017458C;
    }
    // 0x80174348: nop

    // 0x8017434C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80174350: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80174354: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80174358: addiu       $t5, $t5, 0x3D00
    ctx->r13 = ADD32(ctx->r13, 0X3D00);
    // 0x8017435C: sw          $t4, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r12;
    // 0x80174360: addiu       $t3, $zero, 0x270F
    ctx->r11 = ADD32(0, 0X270F);
    // 0x80174364: sw          $t3, 0xA0($t5)
    MEM_W(0XA0, ctx->r13) = ctx->r11;
    // 0x80174368: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017436C: addiu       $t9, $t9, 0x3C00
    ctx->r25 = ADD32(ctx->r25, 0X3C00);
    // 0x80174370: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x80174374: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80174378: sltu        $at, $t7, $t6
    ctx->r1 = ctx->r15 < ctx->r14 ? 1 : 0;
    // 0x8017437C: beq         $at, $zero, L_80174400
    if (ctx->r1 == 0) {
        // 0x80174380: nop
    
            goto L_80174400;
    }
    // 0x80174380: nop

L_80174384:
    // 0x80174384: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80174388: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017438C: addiu       $t8, $t8, 0x3D00
    ctx->r24 = ADD32(ctx->r24, 0X3D00);
    // 0x80174390: sll         $t4, $t0, 2
    ctx->r12 = S32(ctx->r8 << 2);
    // 0x80174394: addu        $t2, $t4, $t8
    ctx->r10 = ADD32(ctx->r12, ctx->r24);
    // 0x80174398: lw          $t3, 0x78($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X78);
    // 0x8017439C: lw          $t1, 0xA0($t8)
    ctx->r9 = MEM_W(ctx->r24, 0XA0);
    // 0x801743A0: slt         $at, $t3, $t1
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x801743A4: beq         $at, $zero, L_801743DC
    if (ctx->r1 == 0) {
        // 0x801743A8: nop
    
            goto L_801743DC;
    }
    // 0x801743A8: nop

    // 0x801743AC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x801743B0: addiu       $t5, $t5, 0x3C00
    ctx->r13 = ADD32(ctx->r13, 0X3C00);
    // 0x801743B4: addu        $t9, $t4, $t5
    ctx->r25 = ADD32(ctx->r12, ctx->r13);
    // 0x801743B8: lw          $t7, 0x14($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X14);
    // 0x801743BC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x801743C0: addiu       $t8, $t8, 0x3D00
    ctx->r24 = ADD32(ctx->r24, 0X3D00);
    // 0x801743C4: sw          $t7, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r15;
    // 0x801743C8: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x801743CC: sll         $t0, $t6, 2
    ctx->r8 = S32(ctx->r14 << 2);
    // 0x801743D0: addu        $t2, $t0, $t8
    ctx->r10 = ADD32(ctx->r8, ctx->r24);
    // 0x801743D4: lw          $t1, 0x78($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X78);
    // 0x801743D8: sw          $t1, 0xA0($t8)
    MEM_W(0XA0, ctx->r24) = ctx->r9;
L_801743DC:
    // 0x801743DC: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x801743E0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801743E4: addiu       $t9, $t9, 0x3C00
    ctx->r25 = ADD32(ctx->r25, 0X3C00);
    // 0x801743E8: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x801743EC: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x801743F0: lw          $t7, 0x0($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X0);
    // 0x801743F4: sltu        $at, $t4, $t7
    ctx->r1 = ctx->r12 < ctx->r15 ? 1 : 0;
    // 0x801743F8: bne         $at, $zero, L_80174384
    if (ctx->r1 != 0) {
        // 0x801743FC: nop
    
            goto L_80174384;
    }
    // 0x801743FC: nop

L_80174400:
    // 0x80174400: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80174404: addiu       $t5, $t5, 0x3C00
    ctx->r13 = ADD32(ctx->r13, 0X3C00);
    // 0x80174408: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x8017440C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80174410: addiu       $t2, $t2, -0x2A28
    ctx->r10 = ADD32(ctx->r10, -0X2A28);
    // 0x80174414: sll         $t0, $t6, 2
    ctx->r8 = S32(ctx->r14 << 2);
    // 0x80174418: addu        $t0, $t0, $t6
    ctx->r8 = ADD32(ctx->r8, ctx->r14);
    // 0x8017441C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80174420: subu        $t0, $t0, $t6
    ctx->r8 = SUB32(ctx->r8, ctx->r14);
    // 0x80174424: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80174428: addu        $t0, $t0, $t6
    ctx->r8 = ADD32(ctx->r8, ctx->r14);
    // 0x8017442C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80174430: addu        $t1, $t0, $t2
    ctx->r9 = ADD32(ctx->r8, ctx->r10);
    // 0x80174434: lhu         $t8, 0x0($t1)
    ctx->r24 = MEM_HU(ctx->r9, 0X0);
    // 0x80174438: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8017443C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80174440: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80174444: or          $t9, $t8, $t3
    ctx->r25 = ctx->r24 | ctx->r11;
    // 0x80174448: sh          $t9, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r25;
    // 0x8017444C: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80174450: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80174454: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80174458: sll         $t5, $t7, 3
    ctx->r13 = S32(ctx->r15 << 3);
    // 0x8017445C: subu        $t5, $t5, $t7
    ctx->r13 = SUB32(ctx->r13, ctx->r15);
    // 0x80174460: sll         $t0, $t6, 3
    ctx->r8 = S32(ctx->r14 << 3);
    // 0x80174464: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80174468: subu        $t0, $t0, $t6
    ctx->r8 = SUB32(ctx->r8, ctx->r14);
    // 0x8017446C: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x80174470: sll         $t5, $t5, 5
    ctx->r13 = S32(ctx->r13 << 5);
    // 0x80174474: addu        $t2, $t5, $t0
    ctx->r10 = ADD32(ctx->r13, ctx->r8);
    // 0x80174478: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x8017447C: sll         $t1, $t9, 3
    ctx->r9 = S32(ctx->r25 << 3);
    // 0x80174480: sll         $t6, $t7, 3
    ctx->r14 = S32(ctx->r15 << 3);
    // 0x80174484: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80174488: subu        $t1, $t1, $t9
    ctx->r9 = SUB32(ctx->r9, ctx->r25);
    // 0x8017448C: subu        $t6, $t6, $t7
    ctx->r14 = SUB32(ctx->r14, ctx->r15);
    // 0x80174490: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x80174494: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80174498: sw          $t4, 0x3518($at)
    MEM_W(0X3518, ctx->r1) = ctx->r12;
    // 0x8017449C: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x801744A0: sll         $t1, $t1, 5
    ctx->r9 = S32(ctx->r9 << 5);
    // 0x801744A4: addiu       $t8, $t8, 0x3C00
    ctx->r24 = ADD32(ctx->r24, 0X3C00);
    // 0x801744A8: lw          $t3, 0x4($t8)
    ctx->r11 = MEM_W(ctx->r24, 0X4);
    // 0x801744AC: addu        $t5, $t1, $t6
    ctx->r13 = ADD32(ctx->r9, ctx->r14);
    // 0x801744B0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801744B4: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x801744B8: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x801744BC: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x801744C0: sll         $t8, $t2, 3
    ctx->r24 = S32(ctx->r10 << 3);
    // 0x801744C4: sll         $t4, $t0, 3
    ctx->r12 = S32(ctx->r8 << 3);
    // 0x801744C8: subu        $t8, $t8, $t2
    ctx->r24 = SUB32(ctx->r24, ctx->r10);
    // 0x801744CC: subu        $t4, $t4, $t0
    ctx->r12 = SUB32(ctx->r12, ctx->r8);
    // 0x801744D0: sw          $t3, 0x351C($at)
    MEM_W(0X351C, ctx->r1) = ctx->r11;
    // 0x801744D4: sll         $t4, $t4, 5
    ctx->r12 = S32(ctx->r12 << 5);
    // 0x801744D8: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x801744DC: addu        $t9, $t4, $t8
    ctx->r25 = ADD32(ctx->r12, ctx->r24);
    // 0x801744E0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801744E4: sll         $t3, $t6, 3
    ctx->r11 = S32(ctx->r14 << 3);
    // 0x801744E8: sll         $t1, $t7, 3
    ctx->r9 = S32(ctx->r15 << 3);
    // 0x801744EC: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x801744F0: subu        $t3, $t3, $t6
    ctx->r11 = SUB32(ctx->r11, ctx->r14);
    // 0x801744F4: subu        $t1, $t1, $t7
    ctx->r9 = SUB32(ctx->r9, ctx->r15);
    // 0x801744F8: sw          $zero, 0x3520($at)
    MEM_W(0X3520, ctx->r1) = 0;
    // 0x801744FC: sll         $t1, $t1, 5
    ctx->r9 = S32(ctx->r9 << 5);
    // 0x80174500: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x80174504: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80174508: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8017450C: addu        $t5, $t1, $t3
    ctx->r13 = ADD32(ctx->r9, ctx->r11);
    // 0x80174510: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80174514: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80174518: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x8017451C: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80174520: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80174524: sll         $t8, $t4, 3
    ctx->r24 = S32(ctx->r12 << 3);
    // 0x80174528: sll         $t2, $t0, 3
    ctx->r10 = S32(ctx->r8 << 3);
    // 0x8017452C: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x80174530: subu        $t8, $t8, $t4
    ctx->r24 = SUB32(ctx->r24, ctx->r12);
    // 0x80174534: subu        $t2, $t2, $t0
    ctx->r10 = SUB32(ctx->r10, ctx->r8);
    // 0x80174538: sll         $t3, $t1, 3
    ctx->r11 = S32(ctx->r9 << 3);
    // 0x8017453C: sll         $t6, $t7, 3
    ctx->r14 = S32(ctx->r15 << 3);
    // 0x80174540: sll         $t2, $t2, 5
    ctx->r10 = S32(ctx->r10 << 5);
    // 0x80174544: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80174548: swc1        $f4, 0x352C($at)
    MEM_W(0X352C, ctx->r1) = ctx->f4.u32l;
    // 0x8017454C: subu        $t3, $t3, $t1
    ctx->r11 = SUB32(ctx->r11, ctx->r9);
    // 0x80174550: subu        $t6, $t6, $t7
    ctx->r14 = SUB32(ctx->r14, ctx->r15);
    // 0x80174554: sll         $t6, $t6, 5
    ctx->r14 = S32(ctx->r14 << 5);
    // 0x80174558: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x8017455C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80174560: addu        $t9, $t2, $t8
    ctx->r25 = ADD32(ctx->r10, ctx->r24);
    // 0x80174564: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80174568: addiu       $t0, $t0, 0x3518
    ctx->r8 = ADD32(ctx->r8, 0X3518);
    // 0x8017456C: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80174570: addu        $t5, $t6, $t3
    ctx->r13 = ADD32(ctx->r14, ctx->r11);
    // 0x80174574: addu        $t4, $t5, $t0
    ctx->r12 = ADD32(ctx->r13, ctx->r8);
    // 0x80174578: sw          $zero, 0x3528($at)
    MEM_W(0X3528, ctx->r1) = 0;
    // 0x8017457C: lw          $t2, 0x10($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X10);
    // 0x80174580: addu        $t8, $t6, $t3
    ctx->r24 = ADD32(ctx->r14, ctx->r11);
    // 0x80174584: addu        $t9, $t8, $t0
    ctx->r25 = ADD32(ctx->r24, ctx->r8);
    // 0x80174588: sw          $t2, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->r10;
L_8017458C:
    // 0x8017458C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80174590: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80174594: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80174598: jr          $ra
    // 0x8017459C: nop

    return;
    // 0x8017459C: nop

;}
RECOMP_FUNC void func_801745A0_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801745A0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801745A4: lw          $t6, -0x2E3C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2E3C);
    // 0x801745A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801745AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801745B0: beq         $t6, $zero, L_80174994
    if (ctx->r14 == 0) {
        // 0x801745B4: sw          $zero, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = 0;
            goto L_80174994;
    }
    // 0x801745B4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_801745B8:
    // 0x801745B8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
L_801745BC:
    // 0x801745BC: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x801745C0: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x801745C4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x801745C8: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x801745CC: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x801745D0: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x801745D4: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x801745D8: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x801745DC: sll         $t8, $t8, 5
    ctx->r24 = S32(ctx->r24 << 5);
    // 0x801745E0: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x801745E4: addiu       $t2, $t2, 0x3518
    ctx->r10 = ADD32(ctx->r10, 0X3518);
    // 0x801745E8: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x801745EC: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x801745F0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801745F4: bne         $t4, $at, L_80174960
    if (ctx->r12 != ctx->r1) {
        // 0x801745F8: nop
    
            goto L_80174960;
    }
    // 0x801745F8: nop

    // 0x801745FC: addu        $t5, $t8, $t0
    ctx->r13 = ADD32(ctx->r24, ctx->r8);
    // 0x80174600: addu        $t6, $t5, $t2
    ctx->r14 = ADD32(ctx->r13, ctx->r10);
    // 0x80174604: lw          $t1, 0x8($t6)
    ctx->r9 = MEM_W(ctx->r14, 0X8);
    // 0x80174608: bne         $t1, $zero, L_80174924
    if (ctx->r9 != 0) {
        // 0x8017460C: nop
    
            goto L_80174924;
    }
    // 0x8017460C: nop

    // 0x80174610: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x80174614: jal         0x801749A4
    // 0x80174618: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    func_801749A4_1501A0(rdram, ctx);
        goto after_0;
    // 0x80174618: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    after_0:
    // 0x8017461C: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x80174620: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80174624: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80174628: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8017462C: sll         $t8, $t4, 3
    ctx->r24 = S32(ctx->r12 << 3);
    // 0x80174630: sll         $t5, $t0, 3
    ctx->r13 = S32(ctx->r8 << 3);
    // 0x80174634: subu        $t8, $t8, $t4
    ctx->r24 = SUB32(ctx->r24, ctx->r12);
    // 0x80174638: subu        $t5, $t5, $t0
    ctx->r13 = SUB32(ctx->r13, ctx->r8);
    // 0x8017463C: sll         $t1, $t6, 3
    ctx->r9 = S32(ctx->r14 << 3);
    // 0x80174640: sll         $t9, $t7, 3
    ctx->r25 = S32(ctx->r15 << 3);
    // 0x80174644: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x80174648: sll         $t8, $t8, 5
    ctx->r24 = S32(ctx->r24 << 5);
    // 0x8017464C: subu        $t1, $t1, $t6
    ctx->r9 = SUB32(ctx->r9, ctx->r14);
    // 0x80174650: subu        $t9, $t9, $t7
    ctx->r25 = SUB32(ctx->r25, ctx->r15);
    // 0x80174654: addu        $t2, $t8, $t5
    ctx->r10 = ADD32(ctx->r24, ctx->r13);
    // 0x80174658: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017465C: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80174660: sll         $t1, $t1, 5
    ctx->r9 = S32(ctx->r9 << 5);
    // 0x80174664: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80174668: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x8017466C: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80174670: addiu       $t0, $t0, 0x3518
    ctx->r8 = ADD32(ctx->r8, 0X3518);
    // 0x80174674: addu        $t4, $t1, $t9
    ctx->r12 = ADD32(ctx->r9, ctx->r25);
    // 0x80174678: sw          $t3, 0x3524($at)
    MEM_W(0X3524, ctx->r1) = ctx->r11;
    // 0x8017467C: addu        $t8, $t4, $t0
    ctx->r24 = ADD32(ctx->r12, ctx->r8);
    // 0x80174680: lw          $t5, 0x4($t8)
    ctx->r13 = MEM_W(ctx->r24, 0X4);
    // 0x80174684: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80174688: addu        $t2, $t1, $t9
    ctx->r10 = ADD32(ctx->r9, ctx->r25);
    // 0x8017468C: sll         $t3, $t5, 2
    ctx->r11 = S32(ctx->r13 << 2);
    // 0x80174690: addu        $t3, $t3, $t5
    ctx->r11 = ADD32(ctx->r11, ctx->r13);
    // 0x80174694: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80174698: subu        $t3, $t3, $t5
    ctx->r11 = SUB32(ctx->r11, ctx->r13);
    // 0x8017469C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x801746A0: addu        $t3, $t3, $t5
    ctx->r11 = ADD32(ctx->r11, ctx->r13);
    // 0x801746A4: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x801746A8: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x801746AC: lwc1        $f4, -0x29C8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X29C8);
    // 0x801746B0: addu        $t6, $t2, $t0
    ctx->r14 = ADD32(ctx->r10, ctx->r8);
    // 0x801746B4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x801746B8: swc1        $f4, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->f4.u32l;
    // 0x801746BC: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x801746C0: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x801746C4: addiu       $t1, $t1, 0x3518
    ctx->r9 = ADD32(ctx->r9, 0X3518);
    // 0x801746C8: sll         $t5, $t8, 3
    ctx->r13 = S32(ctx->r24 << 3);
    // 0x801746CC: sll         $t4, $t7, 3
    ctx->r12 = S32(ctx->r15 << 3);
    // 0x801746D0: subu        $t5, $t5, $t8
    ctx->r13 = SUB32(ctx->r13, ctx->r24);
    // 0x801746D4: subu        $t4, $t4, $t7
    ctx->r12 = SUB32(ctx->r12, ctx->r15);
    // 0x801746D8: sll         $t4, $t4, 5
    ctx->r12 = S32(ctx->r12 << 5);
    // 0x801746DC: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x801746E0: addu        $t3, $t4, $t5
    ctx->r11 = ADD32(ctx->r12, ctx->r13);
    // 0x801746E4: addu        $t9, $t3, $t1
    ctx->r25 = ADD32(ctx->r11, ctx->r9);
    // 0x801746E8: lw          $t2, 0x4($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X4);
    // 0x801746EC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801746F0: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x801746F4: sll         $t0, $t2, 2
    ctx->r8 = S32(ctx->r10 << 2);
    // 0x801746F8: addu        $t0, $t0, $t2
    ctx->r8 = ADD32(ctx->r8, ctx->r10);
    // 0x801746FC: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80174700: subu        $t0, $t0, $t2
    ctx->r8 = SUB32(ctx->r8, ctx->r10);
    // 0x80174704: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80174708: addu        $t0, $t0, $t2
    ctx->r8 = ADD32(ctx->r8, ctx->r10);
    // 0x8017470C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80174710: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80174714: lwc1        $f6, -0x29C4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X29C4);
    // 0x80174718: addu        $t7, $t6, $t1
    ctx->r15 = ADD32(ctx->r14, ctx->r9);
    // 0x8017471C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80174720: swc1        $f6, 0x20($t7)
    MEM_W(0X20, ctx->r15) = ctx->f6.u32l;
    // 0x80174724: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80174728: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8017472C: addiu       $t4, $t4, 0x3518
    ctx->r12 = ADD32(ctx->r12, 0X3518);
    // 0x80174730: sll         $t2, $t9, 3
    ctx->r10 = S32(ctx->r25 << 3);
    // 0x80174734: sll         $t3, $t8, 3
    ctx->r11 = S32(ctx->r24 << 3);
    // 0x80174738: subu        $t2, $t2, $t9
    ctx->r10 = SUB32(ctx->r10, ctx->r25);
    // 0x8017473C: subu        $t3, $t3, $t8
    ctx->r11 = SUB32(ctx->r11, ctx->r24);
    // 0x80174740: sll         $t3, $t3, 5
    ctx->r11 = S32(ctx->r11 << 5);
    // 0x80174744: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x80174748: addu        $t0, $t3, $t2
    ctx->r8 = ADD32(ctx->r11, ctx->r10);
    // 0x8017474C: addu        $t5, $t0, $t4
    ctx->r13 = ADD32(ctx->r8, ctx->r12);
    // 0x80174750: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x80174754: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80174758: addu        $t7, $t3, $t2
    ctx->r15 = ADD32(ctx->r11, ctx->r10);
    // 0x8017475C: sll         $t1, $t6, 2
    ctx->r9 = S32(ctx->r14 << 2);
    // 0x80174760: addu        $t1, $t1, $t6
    ctx->r9 = ADD32(ctx->r9, ctx->r14);
    // 0x80174764: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80174768: subu        $t1, $t1, $t6
    ctx->r9 = SUB32(ctx->r9, ctx->r14);
    // 0x8017476C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80174770: addu        $t1, $t1, $t6
    ctx->r9 = ADD32(ctx->r9, ctx->r14);
    // 0x80174774: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80174778: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8017477C: lwc1        $f8, -0x29C0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X29C0);
    // 0x80174780: addu        $t8, $t7, $t4
    ctx->r24 = ADD32(ctx->r15, ctx->r12);
    // 0x80174784: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80174788: swc1        $f8, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->f8.u32l;
    // 0x8017478C: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x80174790: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80174794: addiu       $t3, $t3, 0x3518
    ctx->r11 = ADD32(ctx->r11, 0X3518);
    // 0x80174798: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x8017479C: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x801747A0: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x801747A4: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x801747A8: sll         $t0, $t0, 5
    ctx->r8 = S32(ctx->r8 << 5);
    // 0x801747AC: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x801747B0: addu        $t1, $t0, $t6
    ctx->r9 = ADD32(ctx->r8, ctx->r14);
    // 0x801747B4: addu        $t2, $t1, $t3
    ctx->r10 = ADD32(ctx->r9, ctx->r11);
    // 0x801747B8: lwc1        $f10, 0x14($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X14);
    // 0x801747BC: addu        $t7, $t0, $t6
    ctx->r15 = ADD32(ctx->r8, ctx->r14);
    // 0x801747C0: addu        $t4, $t7, $t3
    ctx->r12 = ADD32(ctx->r15, ctx->r11);
    // 0x801747C4: swc1        $f10, 0x30($t4)
    MEM_W(0X30, ctx->r12) = ctx->f10.u32l;
    // 0x801747C8: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x801747CC: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x801747D0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x801747D4: sll         $t1, $t5, 3
    ctx->r9 = S32(ctx->r13 << 3);
    // 0x801747D8: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x801747DC: subu        $t1, $t1, $t5
    ctx->r9 = SUB32(ctx->r9, ctx->r13);
    // 0x801747E0: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x801747E4: sll         $t9, $t9, 5
    ctx->r25 = S32(ctx->r25 << 5);
    // 0x801747E8: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x801747EC: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x801747F0: addiu       $t0, $t0, 0x3518
    ctx->r8 = ADD32(ctx->r8, 0X3518);
    // 0x801747F4: addu        $t6, $t2, $t0
    ctx->r14 = ADD32(ctx->r10, ctx->r8);
    // 0x801747F8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801747FC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80174800: lwc1        $f16, 0x14($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X14);
    // 0x80174804: c.le.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl <= ctx->f18.fl;
    // 0x80174808: nop

    // 0x8017480C: bc1f        L_8017486C
    if (!c1cs) {
        // 0x80174810: nop
    
            goto L_8017486C;
    }
    // 0x80174810: nop

    // 0x80174814: addu        $t3, $t9, $t1
    ctx->r11 = ADD32(ctx->r25, ctx->r9);
    // 0x80174818: addu        $t4, $t3, $t0
    ctx->r12 = ADD32(ctx->r11, ctx->r8);
    // 0x8017481C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80174820: sw          $t7, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r15;
    // 0x80174824: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x80174828: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8017482C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80174830: sll         $t6, $t2, 3
    ctx->r14 = S32(ctx->r10 << 3);
    // 0x80174834: sll         $t5, $t8, 3
    ctx->r13 = S32(ctx->r24 << 3);
    // 0x80174838: subu        $t6, $t6, $t2
    ctx->r14 = SUB32(ctx->r14, ctx->r10);
    // 0x8017483C: subu        $t5, $t5, $t8
    ctx->r13 = SUB32(ctx->r13, ctx->r24);
    // 0x80174840: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80174844: sll         $t5, $t5, 5
    ctx->r13 = S32(ctx->r13 << 5);
    // 0x80174848: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8017484C: addu        $t9, $t5, $t6
    ctx->r25 = ADD32(ctx->r13, ctx->r14);
    // 0x80174850: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80174854: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80174858: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x8017485C: jal         0x800C8544
    // 0x80174860: swc1        $f4, 0x352C($at)
    MEM_W(0X352C, ctx->r1) = ctx->f4.u32l;
    func_800C8544(rdram, ctx);
        goto after_1;
    // 0x80174860: swc1        $f4, 0x352C($at)
    MEM_W(0X352C, ctx->r1) = ctx->f4.u32l;
    after_1:
    // 0x80174864: b           L_80174960
    // 0x80174868: nop

        goto L_80174960;
    // 0x80174868: nop

L_8017486C:
    // 0x8017486C: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80174870: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80174874: sll         $t3, $t1, 5
    ctx->r11 = S32(ctx->r9 << 5);
    // 0x80174878: addu        $t0, $t0, $t3
    ctx->r8 = ADD32(ctx->r8, ctx->r11);
    // 0x8017487C: lw          $t0, 0x39A8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X39A8);
    // 0x80174880: bne         $t0, $zero, L_801748D4
    if (ctx->r8 != 0) {
        // 0x80174884: nop
    
            goto L_801748D4;
    }
    // 0x80174884: nop

    // 0x80174888: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x8017488C: sll         $t7, $t1, 3
    ctx->r15 = S32(ctx->r9 << 3);
    // 0x80174890: subu        $t7, $t7, $t1
    ctx->r15 = SUB32(ctx->r15, ctx->r9);
    // 0x80174894: sll         $t8, $t4, 3
    ctx->r24 = S32(ctx->r12 << 3);
    // 0x80174898: subu        $t8, $t8, $t4
    ctx->r24 = SUB32(ctx->r24, ctx->r12);
    // 0x8017489C: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x801748A0: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x801748A4: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x801748A8: addiu       $t5, $t5, 0x3518
    ctx->r13 = ADD32(ctx->r13, 0X3518);
    // 0x801748AC: addu        $t2, $t7, $t8
    ctx->r10 = ADD32(ctx->r15, ctx->r24);
    // 0x801748B0: addu        $t6, $t2, $t5
    ctx->r14 = ADD32(ctx->r10, ctx->r13);
    // 0x801748B4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801748B8: lwc1        $f8, -0x4D0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4D0);
    // 0x801748BC: lwc1        $f6, 0x14($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X14);
    // 0x801748C0: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x801748C4: addu        $t3, $t9, $t5
    ctx->r11 = ADD32(ctx->r25, ctx->r13);
    // 0x801748C8: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x801748CC: b           L_80174960
    // 0x801748D0: swc1        $f10, 0x14($t3)
    MEM_W(0X14, ctx->r11) = ctx->f10.u32l;
        goto L_80174960;
    // 0x801748D0: swc1        $f10, 0x14($t3)
    MEM_W(0X14, ctx->r11) = ctx->f10.u32l;
L_801748D4:
    // 0x801748D4: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x801748D8: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x801748DC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801748E0: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x801748E4: sll         $t2, $t4, 3
    ctx->r10 = S32(ctx->r12 << 3);
    // 0x801748E8: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x801748EC: subu        $t2, $t2, $t4
    ctx->r10 = SUB32(ctx->r10, ctx->r12);
    // 0x801748F0: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x801748F4: sll         $t1, $t1, 5
    ctx->r9 = S32(ctx->r9 << 5);
    // 0x801748F8: addu        $t6, $t1, $t2
    ctx->r14 = ADD32(ctx->r9, ctx->r10);
    // 0x801748FC: addiu       $t7, $t7, 0x3518
    ctx->r15 = ADD32(ctx->r15, 0X3518);
    // 0x80174900: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80174904: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80174908: lwc1        $f18, -0x4CC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X4CC);
    // 0x8017490C: lwc1        $f16, 0x14($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X14);
    // 0x80174910: addu        $t9, $t1, $t2
    ctx->r25 = ADD32(ctx->r9, ctx->r10);
    // 0x80174914: addu        $t5, $t9, $t7
    ctx->r13 = ADD32(ctx->r25, ctx->r15);
    // 0x80174918: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8017491C: b           L_80174960
    // 0x80174920: swc1        $f4, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->f4.u32l;
        goto L_80174960;
    // 0x80174920: swc1        $f4, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->f4.u32l;
L_80174924:
    // 0x80174924: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80174928: jal         0x801749A4
    // 0x8017492C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    func_801749A4_1501A0(rdram, ctx);
        goto after_2;
    // 0x8017492C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80174930: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x80174934: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x80174938: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017493C: sll         $t0, $t3, 3
    ctx->r8 = S32(ctx->r11 << 3);
    // 0x80174940: sll         $t6, $t4, 3
    ctx->r14 = S32(ctx->r12 << 3);
    // 0x80174944: subu        $t0, $t0, $t3
    ctx->r8 = SUB32(ctx->r8, ctx->r11);
    // 0x80174948: subu        $t6, $t6, $t4
    ctx->r14 = SUB32(ctx->r14, ctx->r12);
    // 0x8017494C: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80174950: sll         $t0, $t0, 5
    ctx->r8 = S32(ctx->r8 << 5);
    // 0x80174954: addu        $t8, $t0, $t6
    ctx->r24 = ADD32(ctx->r8, ctx->r14);
    // 0x80174958: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8017495C: sw          $zero, 0x3524($at)
    MEM_W(0X3524, ctx->r1) = 0;
L_80174960:
    // 0x80174960: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x80174964: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80174968: sltiu       $at, $t2, 0x4
    ctx->r1 = ctx->r10 < 0X4 ? 1 : 0;
    // 0x8017496C: bne         $at, $zero, L_801745BC
    if (ctx->r1 != 0) {
        // 0x80174970: sw          $t2, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r10;
            goto L_801745BC;
    }
    // 0x80174970: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x80174974: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80174978: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017497C: lw          $t5, -0x2E3C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2E3C);
    // 0x80174980: addiu       $t7, $t9, 0x1
    ctx->r15 = ADD32(ctx->r25, 0X1);
    // 0x80174984: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80174988: sltu        $at, $t7, $t5
    ctx->r1 = ctx->r15 < ctx->r13 ? 1 : 0;
    // 0x8017498C: bne         $at, $zero, L_801745B8
    if (ctx->r1 != 0) {
        // 0x80174990: nop
    
            goto L_801745B8;
    }
    // 0x80174990: nop

L_80174994:
    // 0x80174994: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80174998: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017499C: jr          $ra
    // 0x801749A0: nop

    return;
    // 0x801749A0: nop

;}
RECOMP_FUNC void func_801749A4_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801749A4: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x801749A8: sll         $t7, $a1, 3
    ctx->r15 = S32(ctx->r5 << 3);
    // 0x801749AC: subu        $t7, $t7, $a1
    ctx->r15 = SUB32(ctx->r15, ctx->r5);
    // 0x801749B0: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x801749B4: sll         $t2, $a0, 3
    ctx->r10 = S32(ctx->r4 << 3);
    // 0x801749B8: sll         $t3, $a1, 3
    ctx->r11 = S32(ctx->r5 << 3);
    // 0x801749BC: subu        $t3, $t3, $a1
    ctx->r11 = SUB32(ctx->r11, ctx->r5);
    // 0x801749C0: subu        $t2, $t2, $a0
    ctx->r10 = SUB32(ctx->r10, ctx->r4);
    // 0x801749C4: sll         $t6, $t6, 5
    ctx->r14 = S32(ctx->r14 << 5);
    // 0x801749C8: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x801749CC: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x801749D0: sll         $t2, $t2, 5
    ctx->r10 = S32(ctx->r10 << 5);
    // 0x801749D4: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x801749D8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801749DC: addiu       $t9, $t9, 0x3518
    ctx->r25 = ADD32(ctx->r25, 0X3518);
    // 0x801749E0: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x801749E4: addu        $t5, $t4, $t9
    ctx->r13 = ADD32(ctx->r12, ctx->r25);
    // 0x801749E8: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x801749EC: sll         $t7, $a1, 3
    ctx->r15 = S32(ctx->r5 << 3);
    // 0x801749F0: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x801749F4: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x801749F8: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x801749FC: subu        $t7, $t7, $a1
    ctx->r15 = SUB32(ctx->r15, ctx->r5);
    // 0x80174A00: sll         $t4, $a1, 3
    ctx->r12 = S32(ctx->r5 << 3);
    // 0x80174A04: sll         $t3, $a0, 3
    ctx->r11 = S32(ctx->r4 << 3);
    // 0x80174A08: subu        $t3, $t3, $a0
    ctx->r11 = SUB32(ctx->r11, ctx->r4);
    // 0x80174A0C: subu        $t4, $t4, $a1
    ctx->r12 = SUB32(ctx->r12, ctx->r5);
    // 0x80174A10: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80174A14: sll         $t6, $t6, 5
    ctx->r14 = S32(ctx->r14 << 5);
    // 0x80174A18: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80174A1C: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x80174A20: sll         $t3, $t3, 5
    ctx->r11 = S32(ctx->r11 << 5);
    // 0x80174A24: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80174A28: addiu       $t0, $t0, 0x3518
    ctx->r8 = ADD32(ctx->r8, 0X3518);
    // 0x80174A2C: addu        $t9, $t3, $t4
    ctx->r25 = ADD32(ctx->r11, ctx->r12);
    // 0x80174A30: sw          $t1, 0x10($t5)
    MEM_W(0X10, ctx->r13) = ctx->r9;
    // 0x80174A34: addu        $t2, $t8, $t0
    ctx->r10 = ADD32(ctx->r24, ctx->r8);
    // 0x80174A38: sll         $t5, $a0, 3
    ctx->r13 = S32(ctx->r4 << 3);
    // 0x80174A3C: sll         $t6, $a1, 3
    ctx->r14 = S32(ctx->r5 << 3);
    // 0x80174A40: lwc1        $f4, 0x18($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X18);
    // 0x80174A44: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x80174A48: subu        $t5, $t5, $a0
    ctx->r13 = SUB32(ctx->r13, ctx->r4);
    // 0x80174A4C: sll         $t4, $a1, 3
    ctx->r12 = S32(ctx->r5 << 3);
    // 0x80174A50: sll         $t3, $a0, 3
    ctx->r11 = S32(ctx->r4 << 3);
    // 0x80174A54: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80174A58: subu        $t3, $t3, $a0
    ctx->r11 = SUB32(ctx->r11, ctx->r4);
    // 0x80174A5C: subu        $t4, $t4, $a1
    ctx->r12 = SUB32(ctx->r12, ctx->r5);
    // 0x80174A60: sll         $t5, $t5, 5
    ctx->r13 = S32(ctx->r13 << 5);
    // 0x80174A64: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80174A68: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80174A6C: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x80174A70: sll         $t3, $t3, 5
    ctx->r11 = S32(ctx->r11 << 5);
    // 0x80174A74: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80174A78: addiu       $t8, $t8, 0x3518
    ctx->r24 = ADD32(ctx->r24, 0X3518);
    // 0x80174A7C: addu        $t9, $t3, $t4
    ctx->r25 = ADD32(ctx->r11, ctx->r12);
    // 0x80174A80: swc1        $f4, 0x1C($t1)
    MEM_W(0X1C, ctx->r9) = ctx->f4.u32l;
    // 0x80174A84: addu        $t2, $t7, $t8
    ctx->r10 = ADD32(ctx->r15, ctx->r24);
    // 0x80174A88: sll         $t1, $a0, 3
    ctx->r9 = S32(ctx->r4 << 3);
    // 0x80174A8C: sll         $t5, $a1, 3
    ctx->r13 = S32(ctx->r5 << 3);
    // 0x80174A90: lwc1        $f6, 0x20($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X20);
    // 0x80174A94: subu        $t5, $t5, $a1
    ctx->r13 = SUB32(ctx->r13, ctx->r5);
    // 0x80174A98: subu        $t1, $t1, $a0
    ctx->r9 = SUB32(ctx->r9, ctx->r4);
    // 0x80174A9C: addu        $t0, $t9, $t8
    ctx->r8 = ADD32(ctx->r25, ctx->r24);
    // 0x80174AA0: sll         $t1, $t1, 5
    ctx->r9 = S32(ctx->r9 << 5);
    // 0x80174AA4: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x80174AA8: sll         $t4, $a1, 3
    ctx->r12 = S32(ctx->r5 << 3);
    // 0x80174AAC: sll         $t3, $a0, 3
    ctx->r11 = S32(ctx->r4 << 3);
    // 0x80174AB0: subu        $t3, $t3, $a0
    ctx->r11 = SUB32(ctx->r11, ctx->r4);
    // 0x80174AB4: subu        $t4, $t4, $a1
    ctx->r12 = SUB32(ctx->r12, ctx->r5);
    // 0x80174AB8: addu        $t6, $t1, $t5
    ctx->r14 = ADD32(ctx->r9, ctx->r13);
    // 0x80174ABC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80174AC0: addiu       $t7, $t7, 0x3518
    ctx->r15 = ADD32(ctx->r15, 0X3518);
    // 0x80174AC4: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x80174AC8: sll         $t3, $t3, 5
    ctx->r11 = S32(ctx->r11 << 5);
    // 0x80174ACC: swc1        $f6, 0x24($t0)
    MEM_W(0X24, ctx->r8) = ctx->f6.u32l;
    // 0x80174AD0: addu        $t9, $t3, $t4
    ctx->r25 = ADD32(ctx->r11, ctx->r12);
    // 0x80174AD4: addu        $t2, $t6, $t7
    ctx->r10 = ADD32(ctx->r14, ctx->r15);
    // 0x80174AD8: sll         $t0, $a0, 3
    ctx->r8 = S32(ctx->r4 << 3);
    // 0x80174ADC: sll         $t1, $a1, 3
    ctx->r9 = S32(ctx->r5 << 3);
    // 0x80174AE0: lwc1        $f8, 0x28($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X28);
    // 0x80174AE4: subu        $t1, $t1, $a1
    ctx->r9 = SUB32(ctx->r9, ctx->r5);
    // 0x80174AE8: subu        $t0, $t0, $a0
    ctx->r8 = SUB32(ctx->r8, ctx->r4);
    // 0x80174AEC: sll         $t0, $t0, 5
    ctx->r8 = S32(ctx->r8 << 5);
    // 0x80174AF0: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x80174AF4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80174AF8: sll         $t4, $a1, 3
    ctx->r12 = S32(ctx->r5 << 3);
    // 0x80174AFC: sll         $t3, $a0, 3
    ctx->r11 = S32(ctx->r4 << 3);
    // 0x80174B00: addu        $t8, $t9, $t7
    ctx->r24 = ADD32(ctx->r25, ctx->r15);
    // 0x80174B04: subu        $t3, $t3, $a0
    ctx->r11 = SUB32(ctx->r11, ctx->r4);
    // 0x80174B08: subu        $t4, $t4, $a1
    ctx->r12 = SUB32(ctx->r12, ctx->r5);
    // 0x80174B0C: addiu       $t6, $t6, 0x3518
    ctx->r14 = ADD32(ctx->r14, 0X3518);
    // 0x80174B10: addu        $t5, $t0, $t1
    ctx->r13 = ADD32(ctx->r8, ctx->r9);
    // 0x80174B14: addu        $t2, $t5, $t6
    ctx->r10 = ADD32(ctx->r13, ctx->r14);
    // 0x80174B18: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x80174B1C: sll         $t3, $t3, 5
    ctx->r11 = S32(ctx->r11 << 5);
    // 0x80174B20: swc1        $f8, 0x2C($t8)
    MEM_W(0X2C, ctx->r24) = ctx->f8.u32l;
    // 0x80174B24: lwc1        $f10, 0x30($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X30);
    // 0x80174B28: addu        $t9, $t3, $t4
    ctx->r25 = ADD32(ctx->r11, ctx->r12);
    // 0x80174B2C: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x80174B30: jr          $ra
    // 0x80174B34: swc1        $f10, 0x34($t7)
    MEM_W(0X34, ctx->r15) = ctx->f10.u32l;
    return;
    // 0x80174B34: swc1        $f10, 0x34($t7)
    MEM_W(0X34, ctx->r15) = ctx->f10.u32l;
;}
RECOMP_FUNC void func_80174B38_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80174B38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80174B3C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80174B40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80174B44: addiu       $t6, $t6, -0x2E28
    ctx->r14 = ADD32(ctx->r14, -0X2E28);
    // 0x80174B48: lbu         $t7, 0xA($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0XA);
    // 0x80174B4C: andi        $t8, $t7, 0x2
    ctx->r24 = ctx->r15 & 0X2;
    // 0x80174B50: beq         $t8, $zero, L_80174B6C
    if (ctx->r24 == 0) {
        // 0x80174B54: nop
    
            goto L_80174B6C;
    }
    // 0x80174B54: nop

    // 0x80174B58: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80174B5C: addiu       $t9, $t9, -0x2E18
    ctx->r25 = ADD32(ctx->r25, -0X2E18);
    // 0x80174B60: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x80174B64: beq         $t0, $zero, L_80174BE0
    if (ctx->r8 == 0) {
        // 0x80174B68: nop
    
            goto L_80174BE0;
    }
    // 0x80174B68: nop

L_80174B6C:
    // 0x80174B6C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80174B70: addiu       $t1, $t1, -0x2E28
    ctx->r9 = ADD32(ctx->r9, -0X2E28);
    // 0x80174B74: lbu         $t2, 0xC($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0XC);
    // 0x80174B78: andi        $t3, $t2, 0x10
    ctx->r11 = ctx->r10 & 0X10;
    // 0x80174B7C: bne         $t3, $zero, L_80174BE0
    if (ctx->r11 != 0) {
        // 0x80174B80: nop
    
            goto L_80174BE0;
    }
    // 0x80174B80: nop

    // 0x80174B84: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80174B88: lw          $t4, -0x2D68($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2D68);
    // 0x80174B8C: bne         $t4, $zero, L_80174BE0
    if (ctx->r12 != 0) {
        // 0x80174B90: nop
    
            goto L_80174BE0;
    }
    // 0x80174B90: nop

    // 0x80174B94: lbu         $t5, 0xA($t1)
    ctx->r13 = MEM_BU(ctx->r9, 0XA);
    // 0x80174B98: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x80174B9C: bne         $t6, $zero, L_80174BE0
    if (ctx->r14 != 0) {
        // 0x80174BA0: nop
    
            goto L_80174BE0;
    }
    // 0x80174BA0: nop

    // 0x80174BA4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80174BA8: lhu         $t7, -0x2BA8($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X2BA8);
    // 0x80174BAC: andi        $t8, $t7, 0x4000
    ctx->r24 = ctx->r15 & 0X4000;
    // 0x80174BB0: bne         $t8, $zero, L_80174BE0
    if (ctx->r24 != 0) {
        // 0x80174BB4: nop
    
            goto L_80174BE0;
    }
    // 0x80174BB4: nop

    // 0x80174BB8: jal         0x801756B0
    // 0x80174BBC: nop

    func_801756B0_1501A0(rdram, ctx);
        goto after_0;
    // 0x80174BBC: nop

    after_0:
    // 0x80174BC0: jal         0x80174BF0
    // 0x80174BC4: nop

    func_80174BF0_1501A0(rdram, ctx);
        goto after_1;
    // 0x80174BC4: nop

    after_1:
    // 0x80174BC8: jal         0x801754E0
    // 0x80174BCC: nop

    func_801754E0_1501A0(rdram, ctx);
        goto after_2;
    // 0x80174BCC: nop

    after_2:
    // 0x80174BD0: jal         0x80176860
    // 0x80174BD4: nop

    func_80176860_1501A0(rdram, ctx);
        goto after_3;
    // 0x80174BD4: nop

    after_3:
    // 0x80174BD8: jal         0x8017CD94
    // 0x80174BDC: nop

    func_8017CD94_1501A0(rdram, ctx);
        goto after_4;
    // 0x80174BDC: nop

    after_4:
L_80174BE0:
    // 0x80174BE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80174BE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80174BE8: jr          $ra
    // 0x80174BEC: nop

    return;
    // 0x80174BEC: nop

;}
RECOMP_FUNC void func_80174BF0_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80174BF0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80174BF4: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80174BF8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80174BFC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80174C00: addiu       $t7, $t7, 0x2880
    ctx->r15 = ADD32(ctx->r15, 0X2880);
    // 0x80174C04: addiu       $t6, $zero, 0x843
    ctx->r14 = ADD32(0, 0X843);
    // 0x80174C08: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80174C0C: sh          $t6, 0x18($t7)
    MEM_H(0X18, ctx->r15) = ctx->r14;
    // 0x80174C10: addiu       $t8, $t8, -0x2BA8
    ctx->r24 = ADD32(ctx->r24, -0X2BA8);
    // 0x80174C14: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x80174C18: beq         $t9, $zero, L_80174F14
    if (ctx->r25 == 0) {
        // 0x80174C1C: nop
    
            goto L_80174F14;
    }
    // 0x80174C1C: nop

    // 0x80174C20: sll         $s0, $t9, 2
    ctx->r16 = S32(ctx->r25 << 2);
    // 0x80174C24: subu        $s0, $s0, $t9
    ctx->r16 = SUB32(ctx->r16, ctx->r25);
    // 0x80174C28: sll         $s0, $s0, 3
    ctx->r16 = S32(ctx->r16 << 3);
    // 0x80174C2C: addu        $s0, $s0, $t9
    ctx->r16 = ADD32(ctx->r16, ctx->r25);
    // 0x80174C30: sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16 << 2);
    // 0x80174C34: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x80174C38: divu        $zero, $s0, $at
    lo = S32(U32(ctx->r16) / U32(ctx->r1)); hi = S32(U32(ctx->r16) % U32(ctx->r1));
    // 0x80174C3C: mflo        $t0
    ctx->r8 = lo;
    // 0x80174C40: or          $s0, $t0, $zero
    ctx->r16 = ctx->r8 | 0;
    // 0x80174C44: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80174C48: divu        $zero, $s0, $at
    lo = S32(U32(ctx->r16) / U32(ctx->r1)); hi = S32(U32(ctx->r16) % U32(ctx->r1));
    // 0x80174C4C: mflo        $t1
    ctx->r9 = lo;
    // 0x80174C50: or          $s0, $t1, $zero
    ctx->r16 = ctx->r9 | 0;
    // 0x80174C54: beq         $s0, $zero, L_80174CFC
    if (ctx->r16 == 0) {
        // 0x80174C58: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80174CFC;
    }
    // 0x80174C58: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80174C5C: beq         $s0, $at, L_80174CB4
    if (ctx->r16 == ctx->r1) {
        // 0x80174C60: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80174CB4;
    }
    // 0x80174C60: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80174C64: bne         $s0, $at, L_80174D44
    if (ctx->r16 != ctx->r1) {
        // 0x80174C68: nop
    
            goto L_80174D44;
    }
    // 0x80174C68: nop

    // 0x80174C6C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80174C70: addiu       $t2, $t2, -0x2E18
    ctx->r10 = ADD32(ctx->r10, -0X2E18);
    // 0x80174C74: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x80174C78: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80174C7C: addiu       $t7, $t7, 0x2880
    ctx->r15 = ADD32(ctx->r15, 0X2880);
    // 0x80174C80: andi        $t4, $t3, 0xF
    ctx->r12 = ctx->r11 & 0XF;
    // 0x80174C84: sll         $t5, $t4, 11
    ctx->r13 = S32(ctx->r12 << 11);
    // 0x80174C88: ori         $t6, $t5, 0x1
    ctx->r14 = ctx->r13 | 0X1;
    // 0x80174C8C: jal         0x801751F4
    // 0x80174C90: sh          $t6, 0x18($t7)
    MEM_H(0X18, ctx->r15) = ctx->r14;
    func_801751F4_1501A0(rdram, ctx);
        goto after_0;
    // 0x80174C90: sh          $t6, 0x18($t7)
    MEM_H(0X18, ctx->r15) = ctx->r14;
    after_0:
    // 0x80174C94: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80174C98: addiu       $t8, $t8, -0x2E18
    ctx->r24 = ADD32(ctx->r24, -0X2E18);
    // 0x80174C9C: lw          $t9, 0x68($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X68);
    // 0x80174CA0: sltiu       $at, $t9, 0x80
    ctx->r1 = ctx->r25 < 0X80 ? 1 : 0;
    // 0x80174CA4: bne         $at, $zero, L_80174D54
    if (ctx->r1 != 0) {
        // 0x80174CA8: nop
    
            goto L_80174D54;
    }
    // 0x80174CA8: nop

    // 0x80174CAC: b           L_80174D54
    // 0x80174CB0: sw          $zero, 0x68($t8)
    MEM_W(0X68, ctx->r24) = 0;
        goto L_80174D54;
    // 0x80174CB0: sw          $zero, 0x68($t8)
    MEM_W(0X68, ctx->r24) = 0;
L_80174CB4:
    // 0x80174CB4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80174CB8: addiu       $t0, $t0, -0x2E18
    ctx->r8 = ADD32(ctx->r8, -0X2E18);
    // 0x80174CBC: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x80174CC0: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80174CC4: addiu       $t5, $t5, 0x2880
    ctx->r13 = ADD32(ctx->r13, 0X2880);
    // 0x80174CC8: andi        $t2, $t1, 0x7
    ctx->r10 = ctx->r9 & 0X7;
    // 0x80174CCC: sll         $t3, $t2, 12
    ctx->r11 = S32(ctx->r10 << 12);
    // 0x80174CD0: ori         $t4, $t3, 0x1
    ctx->r12 = ctx->r11 | 0X1;
    // 0x80174CD4: jal         0x801751F4
    // 0x80174CD8: sh          $t4, 0x18($t5)
    MEM_H(0X18, ctx->r13) = ctx->r12;
    func_801751F4_1501A0(rdram, ctx);
        goto after_1;
    // 0x80174CD8: sh          $t4, 0x18($t5)
    MEM_H(0X18, ctx->r13) = ctx->r12;
    after_1:
    // 0x80174CDC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80174CE0: addiu       $t6, $t6, -0x2E18
    ctx->r14 = ADD32(ctx->r14, -0X2E18);
    // 0x80174CE4: lw          $t7, 0x68($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X68);
    // 0x80174CE8: sltiu       $at, $t7, 0x60
    ctx->r1 = ctx->r15 < 0X60 ? 1 : 0;
    // 0x80174CEC: bne         $at, $zero, L_80174D54
    if (ctx->r1 != 0) {
        // 0x80174CF0: nop
    
            goto L_80174D54;
    }
    // 0x80174CF0: nop

    // 0x80174CF4: b           L_80174D54
    // 0x80174CF8: sw          $zero, 0x68($t6)
    MEM_W(0X68, ctx->r14) = 0;
        goto L_80174D54;
    // 0x80174CF8: sw          $zero, 0x68($t6)
    MEM_W(0X68, ctx->r14) = 0;
L_80174CFC:
    // 0x80174CFC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80174D00: addiu       $t9, $t9, -0x2E18
    ctx->r25 = ADD32(ctx->r25, -0X2E18);
    // 0x80174D04: lw          $t8, 0x4($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X4);
    // 0x80174D08: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80174D0C: addiu       $t3, $t3, 0x2880
    ctx->r11 = ADD32(ctx->r11, 0X2880);
    // 0x80174D10: andi        $t0, $t8, 0x3
    ctx->r8 = ctx->r24 & 0X3;
    // 0x80174D14: sll         $t1, $t0, 13
    ctx->r9 = S32(ctx->r8 << 13);
    // 0x80174D18: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80174D1C: jal         0x801751F4
    // 0x80174D20: sh          $t2, 0x18($t3)
    MEM_H(0X18, ctx->r11) = ctx->r10;
    func_801751F4_1501A0(rdram, ctx);
        goto after_2;
    // 0x80174D20: sh          $t2, 0x18($t3)
    MEM_H(0X18, ctx->r11) = ctx->r10;
    after_2:
    // 0x80174D24: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80174D28: addiu       $t4, $t4, -0x2E18
    ctx->r12 = ADD32(ctx->r12, -0X2E18);
    // 0x80174D2C: lw          $t5, 0x68($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X68);
    // 0x80174D30: sltiu       $at, $t5, 0x40
    ctx->r1 = ctx->r13 < 0X40 ? 1 : 0;
    // 0x80174D34: bne         $at, $zero, L_80174D54
    if (ctx->r1 != 0) {
        // 0x80174D38: nop
    
            goto L_80174D54;
    }
    // 0x80174D38: nop

    // 0x80174D3C: b           L_80174D54
    // 0x80174D40: sw          $zero, 0x68($t4)
    MEM_W(0X68, ctx->r12) = 0;
        goto L_80174D54;
    // 0x80174D40: sw          $zero, 0x68($t4)
    MEM_W(0X68, ctx->r12) = 0;
L_80174D44:
    // 0x80174D44: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80174D48: addiu       $t6, $t6, -0x2E18
    ctx->r14 = ADD32(ctx->r14, -0X2E18);
    // 0x80174D4C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80174D50: sw          $t7, 0x68($t6)
    MEM_W(0X68, ctx->r14) = ctx->r15;
L_80174D54:
    // 0x80174D54: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80174D58: lw          $t9, -0x2E48($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2E48);
    // 0x80174D5C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80174D60: beq         $t9, $at, L_80174D7C
    if (ctx->r25 == ctx->r1) {
        // 0x80174D64: nop
    
            goto L_80174D7C;
    }
    // 0x80174D64: nop

    // 0x80174D68: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80174D6C: addiu       $t0, $t0, 0x3D00
    ctx->r8 = ADD32(ctx->r8, 0X3D00);
    // 0x80174D70: addiu       $t8, $zero, 0x14
    ctx->r24 = ADD32(0, 0X14);
    // 0x80174D74: b           L_80174D8C
    // 0x80174D78: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
        goto L_80174D8C;
    // 0x80174D78: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
L_80174D7C:
    // 0x80174D7C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80174D80: addiu       $t2, $t2, 0x3D00
    ctx->r10 = ADD32(ctx->r10, 0X3D00);
    // 0x80174D84: addiu       $t1, $zero, 0x10
    ctx->r9 = ADD32(0, 0X10);
    // 0x80174D88: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
L_80174D8C:
    // 0x80174D8C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80174D90: addiu       $t3, $t3, 0x3D00
    ctx->r11 = ADD32(ctx->r11, 0X3D00);
    // 0x80174D94: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80174D98: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80174D9C: lw          $a1, 0x0($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X0);
    // 0x80174DA0: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80174DA4: addiu       $t5, $zero, 0x82
    ctx->r13 = ADD32(0, 0X82);
    // 0x80174DA8: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80174DAC: addiu       $a0, $a0, 0x28C0
    ctx->r4 = ADD32(ctx->r4, 0X28C0);
    // 0x80174DB0: addiu       $a2, $zero, 0xB4
    ctx->r6 = ADD32(0, 0XB4);
    // 0x80174DB4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80174DB8: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x80174DBC: jal         0x800C6C6C
    // 0x80174DC0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_3;
    // 0x80174DC0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x80174DC4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80174DC8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80174DCC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80174DD0: addiu       $t4, $t4, 0x3D00
    ctx->r12 = ADD32(ctx->r12, 0X3D00);
    // 0x80174DD4: lw          $a1, 0x0($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X0);
    // 0x80174DD8: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80174DDC: addiu       $t7, $zero, 0x82
    ctx->r15 = ADD32(0, 0X82);
    // 0x80174DE0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80174DE4: addiu       $a0, $a0, 0x27E8
    ctx->r4 = ADD32(ctx->r4, 0X27E8);
    // 0x80174DE8: addiu       $a2, $zero, 0xAC
    ctx->r6 = ADD32(0, 0XAC);
    // 0x80174DEC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80174DF0: jal         0x800C6C6C
    // 0x80174DF4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_4;
    // 0x80174DF4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_4:
    // 0x80174DF8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80174DFC: addiu       $t6, $t6, 0x3D00
    ctx->r14 = ADD32(ctx->r14, 0X3D00);
    // 0x80174E00: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80174E04: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80174E08: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    // 0x80174E0C: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80174E10: addiu       $t9, $zero, 0x82
    ctx->r25 = ADD32(0, 0X82);
    // 0x80174E14: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80174E18: addiu       $a0, $a0, 0x2978
    ctx->r4 = ADD32(ctx->r4, 0X2978);
    // 0x80174E1C: addiu       $a2, $zero, 0xB3
    ctx->r6 = ADD32(0, 0XB3);
    // 0x80174E20: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80174E24: addiu       $a1, $a1, 0x22
    ctx->r5 = ADD32(ctx->r5, 0X22);
    // 0x80174E28: jal         0x800C6C6C
    // 0x80174E2C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_5;
    // 0x80174E2C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_5:
    // 0x80174E30: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80174E34: addiu       $t8, $t8, -0x2BA8
    ctx->r24 = ADD32(ctx->r24, -0X2BA8);
    // 0x80174E38: lw          $t0, 0xC($t8)
    ctx->r8 = MEM_W(ctx->r24, 0XC);
    // 0x80174E3C: beq         $t0, $zero, L_80174F14
    if (ctx->r8 == 0) {
        // 0x80174E40: addiu       $at, $zero, 0x64
        ctx->r1 = ADD32(0, 0X64);
            goto L_80174F14;
    }
    // 0x80174E40: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x80174E44: bne         $t0, $at, L_80174E88
    if (ctx->r8 != ctx->r1) {
        // 0x80174E48: nop
    
            goto L_80174E88;
    }
    // 0x80174E48: nop

    // 0x80174E4C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80174E50: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80174E54: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80174E58: addiu       $t1, $t1, 0x3D00
    ctx->r9 = ADD32(ctx->r9, 0X3D00);
    // 0x80174E5C: lw          $a1, 0x0($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X0);
    // 0x80174E60: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80174E64: addiu       $t2, $zero, 0x82
    ctx->r10 = ADD32(0, 0X82);
    // 0x80174E68: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80174E6C: addiu       $a0, $a0, 0x2A30
    ctx->r4 = ADD32(ctx->r4, 0X2A30);
    // 0x80174E70: addiu       $a2, $zero, 0xAC
    ctx->r6 = ADD32(0, 0XAC);
    // 0x80174E74: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80174E78: jal         0x800C6C6C
    // 0x80174E7C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_6;
    // 0x80174E7C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_6:
    // 0x80174E80: b           L_80174F14
    // 0x80174E84: nop

        goto L_80174F14;
    // 0x80174E84: nop

L_80174E88:
    // 0x80174E88: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80174E8C: addiu       $t3, $t3, -0x2BA8
    ctx->r11 = ADD32(ctx->r11, -0X2BA8);
    // 0x80174E90: lw          $t5, 0xC($t3)
    ctx->r13 = MEM_W(ctx->r11, 0XC);
    // 0x80174E94: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x80174E98: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x80174E9C: sll         $t4, $t5, 4
    ctx->r12 = S32(ctx->r13 << 4);
    // 0x80174EA0: subu        $t4, $t4, $t5
    ctx->r12 = SUB32(ctx->r12, ctx->r13);
    // 0x80174EA4: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x80174EA8: divu        $zero, $t4, $at
    lo = S32(U32(ctx->r12) / U32(ctx->r1)); hi = S32(U32(ctx->r12) % U32(ctx->r1));
    // 0x80174EAC: mflo        $t7
    ctx->r15 = lo;
    // 0x80174EB0: sll         $t9, $t7, 1
    ctx->r25 = S32(ctx->r15 << 1);
    // 0x80174EB4: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x80174EB8: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x80174EBC: addiu       $t0, $t0, -0x2A14
    ctx->r8 = ADD32(ctx->r8, -0X2A14);
    // 0x80174EC0: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80174EC4: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x80174EC8: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80174ECC: sll         $t4, $t9, 2
    ctx->r12 = S32(ctx->r25 << 2);
    // 0x80174ED0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80174ED4: addiu       $t3, $t3, 0x3D00
    ctx->r11 = ADD32(ctx->r11, 0X3D00);
    // 0x80174ED8: addu        $t6, $t4, $t0
    ctx->r14 = ADD32(ctx->r12, ctx->r8);
    // 0x80174EDC: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x80174EE0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80174EE4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80174EE8: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x80174EEC: lw          $a2, 0x4($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X4);
    // 0x80174EF0: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x80174EF4: addiu       $t7, $zero, 0x82
    ctx->r15 = ADD32(0, 0X82);
    // 0x80174EF8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80174EFC: lw          $a0, -0x2B04($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2B04);
    // 0x80174F00: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80174F04: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x80174F08: addiu       $a2, $a2, 0xAC
    ctx->r6 = ADD32(ctx->r6, 0XAC);
    // 0x80174F0C: jal         0x800C6C6C
    // 0x80174F10: addu        $a1, $t2, $t5
    ctx->r5 = ADD32(ctx->r10, ctx->r13);
    func_800C6C6C(rdram, ctx);
        goto after_7;
    // 0x80174F10: addu        $a1, $t2, $t5
    ctx->r5 = ADD32(ctx->r10, ctx->r13);
    after_7:
L_80174F14:
    // 0x80174F14: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80174F18: lw          $t8, -0x2E48($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2E48);
    // 0x80174F1C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80174F20: bne         $t8, $at, L_801751E0
    if (ctx->r24 != ctx->r1) {
        // 0x80174F24: nop
    
            goto L_801751E0;
    }
    // 0x80174F24: nop

    // 0x80174F28: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80174F2C: addiu       $t1, $t1, -0x2BA8
    ctx->r9 = ADD32(ctx->r9, -0X2BA8);
    // 0x80174F30: lw          $t3, 0x10($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X10);
    // 0x80174F34: beq         $t3, $zero, L_801751E0
    if (ctx->r11 == 0) {
        // 0x80174F38: nop
    
            goto L_801751E0;
    }
    // 0x80174F38: nop

    // 0x80174F3C: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80174F40: addiu       $t5, $t5, 0x28A0
    ctx->r13 = ADD32(ctx->r13, 0X28A0);
    // 0x80174F44: addiu       $t2, $zero, 0x843
    ctx->r10 = ADD32(0, 0X843);
    // 0x80174F48: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80174F4C: sh          $t2, 0x18($t5)
    MEM_H(0X18, ctx->r13) = ctx->r10;
    // 0x80174F50: addiu       $t9, $t9, -0x2BA8
    ctx->r25 = ADD32(ctx->r25, -0X2BA8);
    // 0x80174F54: lw          $s0, 0x10($t9)
    ctx->r16 = MEM_W(ctx->r25, 0X10);
    // 0x80174F58: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x80174F5C: sll         $t4, $s0, 2
    ctx->r12 = S32(ctx->r16 << 2);
    // 0x80174F60: subu        $t4, $t4, $s0
    ctx->r12 = SUB32(ctx->r12, ctx->r16);
    // 0x80174F64: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x80174F68: addu        $t4, $t4, $s0
    ctx->r12 = ADD32(ctx->r12, ctx->r16);
    // 0x80174F6C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80174F70: or          $s0, $t4, $zero
    ctx->r16 = ctx->r12 | 0;
    // 0x80174F74: divu        $zero, $s0, $at
    lo = S32(U32(ctx->r16) / U32(ctx->r1)); hi = S32(U32(ctx->r16) % U32(ctx->r1));
    // 0x80174F78: mflo        $t0
    ctx->r8 = lo;
    // 0x80174F7C: or          $s0, $t0, $zero
    ctx->r16 = ctx->r8 | 0;
    // 0x80174F80: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80174F84: divu        $zero, $s0, $at
    lo = S32(U32(ctx->r16) / U32(ctx->r1)); hi = S32(U32(ctx->r16) % U32(ctx->r1));
    // 0x80174F88: mflo        $t6
    ctx->r14 = lo;
    // 0x80174F8C: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    // 0x80174F90: beq         $s0, $zero, L_80175038
    if (ctx->r16 == 0) {
        // 0x80174F94: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80175038;
    }
    // 0x80174F94: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80174F98: beq         $s0, $at, L_80174FF0
    if (ctx->r16 == ctx->r1) {
        // 0x80174F9C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80174FF0;
    }
    // 0x80174F9C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80174FA0: bne         $s0, $at, L_80175080
    if (ctx->r16 != ctx->r1) {
        // 0x80174FA4: nop
    
            goto L_80175080;
    }
    // 0x80174FA4: nop

    // 0x80174FA8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80174FAC: addiu       $t7, $t7, -0x2E18
    ctx->r15 = ADD32(ctx->r15, -0X2E18);
    // 0x80174FB0: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80174FB4: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80174FB8: addiu       $t5, $t5, 0x28A0
    ctx->r13 = ADD32(ctx->r13, 0X28A0);
    // 0x80174FBC: andi        $t1, $t8, 0xF
    ctx->r9 = ctx->r24 & 0XF;
    // 0x80174FC0: sll         $t3, $t1, 11
    ctx->r11 = S32(ctx->r9 << 11);
    // 0x80174FC4: ori         $t2, $t3, 0x1
    ctx->r10 = ctx->r11 | 0X1;
    // 0x80174FC8: jal         0x80175278
    // 0x80174FCC: sh          $t2, 0x18($t5)
    MEM_H(0X18, ctx->r13) = ctx->r10;
    func_80175278_1501A0(rdram, ctx);
        goto after_8;
    // 0x80174FCC: sh          $t2, 0x18($t5)
    MEM_H(0X18, ctx->r13) = ctx->r10;
    after_8:
    // 0x80174FD0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80174FD4: addiu       $t9, $t9, -0x2E18
    ctx->r25 = ADD32(ctx->r25, -0X2E18);
    // 0x80174FD8: lw          $t4, 0x6C($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X6C);
    // 0x80174FDC: sltiu       $at, $t4, 0x80
    ctx->r1 = ctx->r12 < 0X80 ? 1 : 0;
    // 0x80174FE0: bne         $at, $zero, L_80175090
    if (ctx->r1 != 0) {
        // 0x80174FE4: nop
    
            goto L_80175090;
    }
    // 0x80174FE4: nop

    // 0x80174FE8: b           L_80175090
    // 0x80174FEC: sw          $zero, 0x6C($t9)
    MEM_W(0X6C, ctx->r25) = 0;
        goto L_80175090;
    // 0x80174FEC: sw          $zero, 0x6C($t9)
    MEM_W(0X6C, ctx->r25) = 0;
L_80174FF0:
    // 0x80174FF0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80174FF4: addiu       $t0, $t0, -0x2E18
    ctx->r8 = ADD32(ctx->r8, -0X2E18);
    // 0x80174FF8: lw          $t6, 0x4($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X4);
    // 0x80174FFC: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80175000: addiu       $t3, $t3, 0x28A0
    ctx->r11 = ADD32(ctx->r11, 0X28A0);
    // 0x80175004: andi        $t7, $t6, 0x7
    ctx->r15 = ctx->r14 & 0X7;
    // 0x80175008: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x8017500C: ori         $t1, $t8, 0x1
    ctx->r9 = ctx->r24 | 0X1;
    // 0x80175010: jal         0x80175278
    // 0x80175014: sh          $t1, 0x18($t3)
    MEM_H(0X18, ctx->r11) = ctx->r9;
    func_80175278_1501A0(rdram, ctx);
        goto after_9;
    // 0x80175014: sh          $t1, 0x18($t3)
    MEM_H(0X18, ctx->r11) = ctx->r9;
    after_9:
    // 0x80175018: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017501C: addiu       $t2, $t2, -0x2E18
    ctx->r10 = ADD32(ctx->r10, -0X2E18);
    // 0x80175020: lw          $t5, 0x6C($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X6C);
    // 0x80175024: sltiu       $at, $t5, 0x60
    ctx->r1 = ctx->r13 < 0X60 ? 1 : 0;
    // 0x80175028: bne         $at, $zero, L_80175090
    if (ctx->r1 != 0) {
        // 0x8017502C: nop
    
            goto L_80175090;
    }
    // 0x8017502C: nop

    // 0x80175030: b           L_80175090
    // 0x80175034: sw          $zero, 0x6C($t2)
    MEM_W(0X6C, ctx->r10) = 0;
        goto L_80175090;
    // 0x80175034: sw          $zero, 0x6C($t2)
    MEM_W(0X6C, ctx->r10) = 0;
L_80175038:
    // 0x80175038: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017503C: addiu       $t4, $t4, -0x2E18
    ctx->r12 = ADD32(ctx->r12, -0X2E18);
    // 0x80175040: lw          $t9, 0x4($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X4);
    // 0x80175044: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80175048: addiu       $t8, $t8, 0x28A0
    ctx->r24 = ADD32(ctx->r24, 0X28A0);
    // 0x8017504C: andi        $t0, $t9, 0x3
    ctx->r8 = ctx->r25 & 0X3;
    // 0x80175050: sll         $t6, $t0, 13
    ctx->r14 = S32(ctx->r8 << 13);
    // 0x80175054: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x80175058: jal         0x80175278
    // 0x8017505C: sh          $t7, 0x18($t8)
    MEM_H(0X18, ctx->r24) = ctx->r15;
    func_80175278_1501A0(rdram, ctx);
        goto after_10;
    // 0x8017505C: sh          $t7, 0x18($t8)
    MEM_H(0X18, ctx->r24) = ctx->r15;
    after_10:
    // 0x80175060: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80175064: addiu       $t1, $t1, -0x2E18
    ctx->r9 = ADD32(ctx->r9, -0X2E18);
    // 0x80175068: lw          $t3, 0x6C($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X6C);
    // 0x8017506C: sltiu       $at, $t3, 0x40
    ctx->r1 = ctx->r11 < 0X40 ? 1 : 0;
    // 0x80175070: bne         $at, $zero, L_80175090
    if (ctx->r1 != 0) {
        // 0x80175074: nop
    
            goto L_80175090;
    }
    // 0x80175074: nop

    // 0x80175078: b           L_80175090
    // 0x8017507C: sw          $zero, 0x6C($t1)
    MEM_W(0X6C, ctx->r9) = 0;
        goto L_80175090;
    // 0x8017507C: sw          $zero, 0x6C($t1)
    MEM_W(0X6C, ctx->r9) = 0;
L_80175080:
    // 0x80175080: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80175084: addiu       $t2, $t2, -0x2E18
    ctx->r10 = ADD32(ctx->r10, -0X2E18);
    // 0x80175088: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x8017508C: sw          $t5, 0x6C($t2)
    MEM_W(0X6C, ctx->r10) = ctx->r13;
L_80175090:
    // 0x80175090: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80175094: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80175098: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8017509C: addiu       $t4, $zero, 0x82
    ctx->r12 = ADD32(0, 0X82);
    // 0x801750A0: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x801750A4: addiu       $a0, $a0, 0x2904
    ctx->r4 = ADD32(ctx->r4, 0X2904);
    // 0x801750A8: addiu       $a1, $zero, 0xF1
    ctx->r5 = ADD32(0, 0XF1);
    // 0x801750AC: addiu       $a2, $zero, 0xB4
    ctx->r6 = ADD32(0, 0XB4);
    // 0x801750B0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801750B4: jal         0x800C6C6C
    // 0x801750B8: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_11;
    // 0x801750B8: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_11:
    // 0x801750BC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801750C0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801750C4: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x801750C8: addiu       $t9, $zero, 0x82
    ctx->r25 = ADD32(0, 0X82);
    // 0x801750CC: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x801750D0: addiu       $a0, $a0, 0x282C
    ctx->r4 = ADD32(ctx->r4, 0X282C);
    // 0x801750D4: addiu       $a1, $zero, 0xE9
    ctx->r5 = ADD32(0, 0XE9);
    // 0x801750D8: addiu       $a2, $zero, 0xAC
    ctx->r6 = ADD32(0, 0XAC);
    // 0x801750DC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801750E0: jal         0x800C6C6C
    // 0x801750E4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_12;
    // 0x801750E4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_12:
    // 0x801750E8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801750EC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801750F0: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x801750F4: addiu       $t0, $zero, 0x82
    ctx->r8 = ADD32(0, 0X82);
    // 0x801750F8: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x801750FC: addiu       $a0, $a0, 0x29BC
    ctx->r4 = ADD32(ctx->r4, 0X29BC);
    // 0x80175100: addiu       $a1, $zero, 0x10B
    ctx->r5 = ADD32(0, 0X10B);
    // 0x80175104: addiu       $a2, $zero, 0xB3
    ctx->r6 = ADD32(0, 0XB3);
    // 0x80175108: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8017510C: jal         0x800C6C6C
    // 0x80175110: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_13;
    // 0x80175110: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_13:
    // 0x80175114: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80175118: addiu       $t6, $t6, -0x2BA8
    ctx->r14 = ADD32(ctx->r14, -0X2BA8);
    // 0x8017511C: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x80175120: beq         $t7, $zero, L_801751E0
    if (ctx->r15 == 0) {
        // 0x80175124: addiu       $at, $zero, 0x64
        ctx->r1 = ADD32(0, 0X64);
            goto L_801751E0;
    }
    // 0x80175124: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x80175128: bne         $t7, $at, L_80175160
    if (ctx->r15 != ctx->r1) {
        // 0x8017512C: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80175160;
    }
    // 0x8017512C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80175130: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80175134: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80175138: addiu       $t8, $zero, 0x82
    ctx->r24 = ADD32(0, 0X82);
    // 0x8017513C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80175140: addiu       $a0, $a0, 0x2A74
    ctx->r4 = ADD32(ctx->r4, 0X2A74);
    // 0x80175144: addiu       $a1, $zero, 0xE9
    ctx->r5 = ADD32(0, 0XE9);
    // 0x80175148: addiu       $a2, $zero, 0xAC
    ctx->r6 = ADD32(0, 0XAC);
    // 0x8017514C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80175150: jal         0x800C6C6C
    // 0x80175154: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_14;
    // 0x80175154: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_14:
    // 0x80175158: b           L_801751E0
    // 0x8017515C: nop

        goto L_801751E0;
    // 0x8017515C: nop

L_80175160:
    // 0x80175160: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80175164: addiu       $t3, $t3, -0x2BA8
    ctx->r11 = ADD32(ctx->r11, -0X2BA8);
    // 0x80175168: lw          $t1, 0x10($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X10);
    // 0x8017516C: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x80175170: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80175174: sll         $t5, $t1, 4
    ctx->r13 = S32(ctx->r9 << 4);
    // 0x80175178: subu        $t5, $t5, $t1
    ctx->r13 = SUB32(ctx->r13, ctx->r9);
    // 0x8017517C: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x80175180: divu        $zero, $t5, $at
    lo = S32(U32(ctx->r13) / U32(ctx->r1)); hi = S32(U32(ctx->r13) % U32(ctx->r1));
    // 0x80175184: mflo        $t2
    ctx->r10 = lo;
    // 0x80175188: sll         $t9, $t2, 1
    ctx->r25 = S32(ctx->r10 << 1);
    // 0x8017518C: addiu       $t6, $t6, -0x2A14
    ctx->r14 = ADD32(ctx->r14, -0X2A14);
    // 0x80175190: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x80175194: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80175198: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x8017519C: addu        $t3, $t8, $t6
    ctx->r11 = ADD32(ctx->r24, ctx->r14);
    // 0x801751A0: addu        $t7, $t0, $t6
    ctx->r15 = ADD32(ctx->r8, ctx->r14);
    // 0x801751A4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801751A8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801751AC: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    // 0x801751B0: lw          $a2, 0x4($t3)
    ctx->r6 = MEM_W(ctx->r11, 0X4);
    // 0x801751B4: sll         $t4, $t2, 2
    ctx->r12 = S32(ctx->r10 << 2);
    // 0x801751B8: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x801751BC: addu        $a0, $a0, $t4
    ctx->r4 = ADD32(ctx->r4, ctx->r12);
    // 0x801751C0: addiu       $t1, $zero, 0x82
    ctx->r9 = ADD32(0, 0X82);
    // 0x801751C4: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x801751C8: lw          $a0, -0x2A8C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2A8C);
    // 0x801751CC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801751D0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x801751D4: addiu       $a1, $a1, 0xE9
    ctx->r5 = ADD32(ctx->r5, 0XE9);
    // 0x801751D8: jal         0x800C6C6C
    // 0x801751DC: addiu       $a2, $a2, 0xAC
    ctx->r6 = ADD32(ctx->r6, 0XAC);
    func_800C6C6C(rdram, ctx);
        goto after_15;
    // 0x801751DC: addiu       $a2, $a2, 0xAC
    ctx->r6 = ADD32(ctx->r6, 0XAC);
    after_15:
L_801751E0:
    // 0x801751E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801751E4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801751E8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801751EC: jr          $ra
    // 0x801751F0: nop

    return;
    // 0x801751F0: nop

;}
RECOMP_FUNC void func_801751F4_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801751F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801751F8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801751FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80175200: addiu       $t6, $t6, -0x2E28
    ctx->r14 = ADD32(ctx->r14, -0X2E28);
    // 0x80175204: lbu         $t7, 0xE($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0XE);
    // 0x80175208: andi        $t8, $t7, 0x80
    ctx->r24 = ctx->r15 & 0X80;
    // 0x8017520C: bne         $t8, $zero, L_80175268
    if (ctx->r24 != 0) {
        // 0x80175210: nop
    
            goto L_80175268;
    }
    // 0x80175210: nop

    // 0x80175214: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80175218: addiu       $t9, $t9, -0x2E18
    ctx->r25 = ADD32(ctx->r25, -0X2E18);
    // 0x8017521C: lw          $t0, 0x68($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X68);
    // 0x80175220: bne         $t0, $zero, L_80175254
    if (ctx->r8 != 0) {
        // 0x80175224: nop
    
            goto L_80175254;
    }
    // 0x80175224: nop

    // 0x80175228: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017522C: lw          $t1, -0x2E48($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2E48);
    // 0x80175230: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80175234: beq         $t1, $at, L_8017524C
    if (ctx->r9 == ctx->r1) {
        // 0x80175238: nop
    
            goto L_8017524C;
    }
    // 0x80175238: nop

    // 0x8017523C: jal         0x800C8544
    // 0x80175240: addiu       $a0, $zero, 0x38
    ctx->r4 = ADD32(0, 0X38);
    func_800C8544(rdram, ctx);
        goto after_0;
    // 0x80175240: addiu       $a0, $zero, 0x38
    ctx->r4 = ADD32(0, 0X38);
    after_0:
    // 0x80175244: b           L_80175254
    // 0x80175248: nop

        goto L_80175254;
    // 0x80175248: nop

L_8017524C:
    // 0x8017524C: jal         0x800C8544
    // 0x80175250: addiu       $a0, $zero, 0x79
    ctx->r4 = ADD32(0, 0X79);
    func_800C8544(rdram, ctx);
        goto after_1;
    // 0x80175250: addiu       $a0, $zero, 0x79
    ctx->r4 = ADD32(0, 0X79);
    after_1:
L_80175254:
    // 0x80175254: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80175258: addiu       $t2, $t2, -0x2E18
    ctx->r10 = ADD32(ctx->r10, -0X2E18);
    // 0x8017525C: lw          $t3, 0x68($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X68);
    // 0x80175260: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80175264: sw          $t4, 0x68($t2)
    MEM_W(0X68, ctx->r10) = ctx->r12;
L_80175268:
    // 0x80175268: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017526C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80175270: jr          $ra
    // 0x80175274: nop

    return;
    // 0x80175274: nop

;}
RECOMP_FUNC void func_80175278_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80175278: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017527C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80175280: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80175284: addiu       $t6, $t6, -0x2E28
    ctx->r14 = ADD32(ctx->r14, -0X2E28);
    // 0x80175288: lbu         $t7, 0xE($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0XE);
    // 0x8017528C: andi        $t8, $t7, 0x80
    ctx->r24 = ctx->r15 & 0X80;
    // 0x80175290: bne         $t8, $zero, L_801752C8
    if (ctx->r24 != 0) {
        // 0x80175294: nop
    
            goto L_801752C8;
    }
    // 0x80175294: nop

    // 0x80175298: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017529C: addiu       $t9, $t9, -0x2E18
    ctx->r25 = ADD32(ctx->r25, -0X2E18);
    // 0x801752A0: lw          $t0, 0x6C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X6C);
    // 0x801752A4: bne         $t0, $zero, L_801752B4
    if (ctx->r8 != 0) {
        // 0x801752A8: nop
    
            goto L_801752B4;
    }
    // 0x801752A8: nop

    // 0x801752AC: jal         0x800C8544
    // 0x801752B0: addiu       $a0, $zero, 0x7A
    ctx->r4 = ADD32(0, 0X7A);
    func_800C8544(rdram, ctx);
        goto after_0;
    // 0x801752B0: addiu       $a0, $zero, 0x7A
    ctx->r4 = ADD32(0, 0X7A);
    after_0:
L_801752B4:
    // 0x801752B4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x801752B8: addiu       $t1, $t1, -0x2E18
    ctx->r9 = ADD32(ctx->r9, -0X2E18);
    // 0x801752BC: lw          $t2, 0x6C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X6C);
    // 0x801752C0: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x801752C4: sw          $t3, 0x6C($t1)
    MEM_W(0X6C, ctx->r9) = ctx->r11;
L_801752C8:
    // 0x801752C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801752CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801752D0: jr          $ra
    // 0x801752D4: nop

    return;
    // 0x801752D4: nop

;}
RECOMP_FUNC void func_801752D8_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801752D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801752DC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801752E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801752E4: addiu       $t6, $t6, -0x2E28
    ctx->r14 = ADD32(ctx->r14, -0X2E28);
    // 0x801752E8: lbu         $t7, 0xA($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0XA);
    // 0x801752EC: andi        $t8, $t7, 0x2
    ctx->r24 = ctx->r15 & 0X2;
    // 0x801752F0: beq         $t8, $zero, L_8017530C
    if (ctx->r24 == 0) {
        // 0x801752F4: nop
    
            goto L_8017530C;
    }
    // 0x801752F4: nop

    // 0x801752F8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801752FC: addiu       $t9, $t9, -0x2E18
    ctx->r25 = ADD32(ctx->r25, -0X2E18);
    // 0x80175300: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x80175304: beq         $t0, $zero, L_801754D0
    if (ctx->r8 == 0) {
        // 0x80175308: nop
    
            goto L_801754D0;
    }
    // 0x80175308: nop

L_8017530C:
    // 0x8017530C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80175310: addiu       $t1, $t1, -0x2E28
    ctx->r9 = ADD32(ctx->r9, -0X2E28);
    // 0x80175314: lbu         $t2, 0xC($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0XC);
    // 0x80175318: andi        $t3, $t2, 0x10
    ctx->r11 = ctx->r10 & 0X10;
    // 0x8017531C: bne         $t3, $zero, L_801754D0
    if (ctx->r11 != 0) {
        // 0x80175320: nop
    
            goto L_801754D0;
    }
    // 0x80175320: nop

    // 0x80175324: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80175328: lw          $t4, -0x2D68($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2D68);
    // 0x8017532C: bne         $t4, $zero, L_801754D0
    if (ctx->r12 != 0) {
        // 0x80175330: nop
    
            goto L_801754D0;
    }
    // 0x80175330: nop

    // 0x80175334: lbu         $t5, 0xA($t1)
    ctx->r13 = MEM_BU(ctx->r9, 0XA);
    // 0x80175338: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x8017533C: bne         $t6, $zero, L_801754D0
    if (ctx->r14 != 0) {
        // 0x80175340: nop
    
            goto L_801754D0;
    }
    // 0x80175340: nop

    // 0x80175344: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80175348: lhu         $t7, -0x2BA8($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X2BA8);
    // 0x8017534C: andi        $t8, $t7, 0x4000
    ctx->r24 = ctx->r15 & 0X4000;
    // 0x80175350: bne         $t8, $zero, L_801754D0
    if (ctx->r24 != 0) {
        // 0x80175354: lui         $at, 0x3FF0
        ctx->r1 = S32(0X3FF0 << 16);
            goto L_801754D0;
    }
    // 0x80175354: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80175358: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x8017535C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80175360: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80175364: jal         0x800C7A88
    // 0x80175368: ldc1        $f14, -0x4C8($at)
    CHECK_FR(ctx, 14);
    ctx->f14.u64 = LD(ctx->r1, -0X4C8);
    func_800C7A88(rdram, ctx);
        goto after_0;
    // 0x80175368: ldc1        $f14, -0x4C8($at)
    CHECK_FR(ctx, 14);
    ctx->f14.u64 = LD(ctx->r1, -0X4C8);
    after_0:
    // 0x8017536C: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80175370: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80175374: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80175378: jal         0x800C7A9C
    // 0x8017537C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    func_800C7A9C(rdram, ctx);
        goto after_1;
    // 0x8017537C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_1:
    // 0x80175380: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80175384: addiu       $t9, $t9, -0x2BA8
    ctx->r25 = ADD32(ctx->r25, -0X2BA8);
    // 0x80175388: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x8017538C: beq         $t0, $zero, L_80175440
    if (ctx->r8 == 0) {
        // 0x80175390: nop
    
            goto L_80175440;
    }
    // 0x80175390: nop

    // 0x80175394: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80175398: lw          $t2, -0x2E48($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2E48);
    // 0x8017539C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801753A0: beq         $t2, $at, L_801753BC
    if (ctx->r10 == ctx->r1) {
        // 0x801753A4: nop
    
            goto L_801753BC;
    }
    // 0x801753A4: nop

    // 0x801753A8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x801753AC: addiu       $t4, $t4, 0x3D00
    ctx->r12 = ADD32(ctx->r12, 0X3D00);
    // 0x801753B0: addiu       $t3, $zero, 0x14
    ctx->r11 = ADD32(0, 0X14);
    // 0x801753B4: b           L_801753CC
    // 0x801753B8: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
        goto L_801753CC;
    // 0x801753B8: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
L_801753BC:
    // 0x801753BC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x801753C0: addiu       $t5, $t5, 0x3D00
    ctx->r13 = ADD32(ctx->r13, 0X3D00);
    // 0x801753C4: addiu       $t1, $zero, 0x10
    ctx->r9 = ADD32(0, 0X10);
    // 0x801753C8: sw          $t1, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r9;
L_801753CC:
    // 0x801753CC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801753D0: addiu       $t6, $t6, 0x3D00
    ctx->r14 = ADD32(ctx->r14, 0X3D00);
    // 0x801753D4: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x801753D8: addiu       $a1, $zero, 0xB7
    ctx->r5 = ADD32(0, 0XB7);
    // 0x801753DC: jal         0x800C7A74
    // 0x801753E0: addiu       $a0, $a0, 0x27
    ctx->r4 = ADD32(ctx->r4, 0X27);
    func_800C7A74(rdram, ctx);
        goto after_2;
    // 0x801753E0: addiu       $a0, $a0, 0x27
    ctx->r4 = ADD32(ctx->r4, 0X27);
    after_2:
    // 0x801753E4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801753E8: addiu       $t7, $t7, -0x2BA8
    ctx->r15 = ADD32(ctx->r15, -0X2BA8);
    // 0x801753EC: lw          $a2, 0xC($t7)
    ctx->r6 = MEM_W(ctx->r15, 0XC);
    // 0x801753F0: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x801753F4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x801753F8: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x801753FC: subu        $t8, $t8, $a2
    ctx->r24 = SUB32(ctx->r24, ctx->r6);
    // 0x80175400: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80175404: addu        $t8, $t8, $a2
    ctx->r24 = ADD32(ctx->r24, ctx->r6);
    // 0x80175408: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8017540C: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x80175410: divu        $zero, $a2, $at
    lo = S32(U32(ctx->r6) / U32(ctx->r1)); hi = S32(U32(ctx->r6) % U32(ctx->r1));
    // 0x80175414: mflo        $t9
    ctx->r25 = lo;
    // 0x80175418: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x8017541C: addiu       $a1, $a1, -0xD20
    ctx->r5 = ADD32(ctx->r5, -0XD20);
    // 0x80175420: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x80175424: jal         0x800D87E4
    // 0x80175428: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_3;
    // 0x80175428: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_3:
    // 0x8017542C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80175430: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80175434: addiu       $a1, $a1, 0x3B40
    ctx->r5 = ADD32(ctx->r5, 0X3B40);
    // 0x80175438: jal         0x800C767C
    // 0x8017543C: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    func_800C767C(rdram, ctx);
        goto after_4;
    // 0x8017543C: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    after_4:
L_80175440:
    // 0x80175440: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80175444: lw          $t0, -0x2E48($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2E48);
    // 0x80175448: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8017544C: bne         $t0, $at, L_801754D0
    if (ctx->r8 != ctx->r1) {
        // 0x80175450: nop
    
            goto L_801754D0;
    }
    // 0x80175450: nop

    // 0x80175454: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80175458: addiu       $t2, $t2, -0x2BA8
    ctx->r10 = ADD32(ctx->r10, -0X2BA8);
    // 0x8017545C: lw          $t3, 0x10($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X10);
    // 0x80175460: beq         $t3, $zero, L_801754D0
    if (ctx->r11 == 0) {
        // 0x80175464: nop
    
            goto L_801754D0;
    }
    // 0x80175464: nop

    // 0x80175468: addiu       $a0, $zero, 0x110
    ctx->r4 = ADD32(0, 0X110);
    // 0x8017546C: jal         0x800C7A74
    // 0x80175470: addiu       $a1, $zero, 0xB7
    ctx->r5 = ADD32(0, 0XB7);
    func_800C7A74(rdram, ctx);
        goto after_5;
    // 0x80175470: addiu       $a1, $zero, 0xB7
    ctx->r5 = ADD32(0, 0XB7);
    after_5:
    // 0x80175474: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80175478: addiu       $t4, $t4, -0x2BA8
    ctx->r12 = ADD32(ctx->r12, -0X2BA8);
    // 0x8017547C: lw          $a2, 0x10($t4)
    ctx->r6 = MEM_W(ctx->r12, 0X10);
    // 0x80175480: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x80175484: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80175488: sll         $t1, $a2, 2
    ctx->r9 = S32(ctx->r6 << 2);
    // 0x8017548C: subu        $t1, $t1, $a2
    ctx->r9 = SUB32(ctx->r9, ctx->r6);
    // 0x80175490: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x80175494: addu        $t1, $t1, $a2
    ctx->r9 = ADD32(ctx->r9, ctx->r6);
    // 0x80175498: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8017549C: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    // 0x801754A0: divu        $zero, $a2, $at
    lo = S32(U32(ctx->r6) / U32(ctx->r1)); hi = S32(U32(ctx->r6) % U32(ctx->r1));
    // 0x801754A4: mflo        $t5
    ctx->r13 = lo;
    // 0x801754A8: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x801754AC: addiu       $a1, $a1, -0xD1C
    ctx->r5 = ADD32(ctx->r5, -0XD1C);
    // 0x801754B0: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
    // 0x801754B4: jal         0x800D87E4
    // 0x801754B8: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_6;
    // 0x801754B8: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_6:
    // 0x801754BC: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x801754C0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x801754C4: addiu       $a1, $a1, 0x3B40
    ctx->r5 = ADD32(ctx->r5, 0X3B40);
    // 0x801754C8: jal         0x800C767C
    // 0x801754CC: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    func_800C767C(rdram, ctx);
        goto after_7;
    // 0x801754CC: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    after_7:
L_801754D0:
    // 0x801754D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801754D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801754D8: jr          $ra
    // 0x801754DC: nop

    return;
    // 0x801754DC: nop

;}
RECOMP_FUNC void func_801754E0_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801754E0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801754E4: lw          $t6, -0x2E48($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2E48);
    // 0x801754E8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801754EC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801754F0: beq         $t6, $at, L_80175538
    if (ctx->r14 == ctx->r1) {
        // 0x801754F4: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_80175538;
    }
    // 0x801754F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801754F8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801754FC: addiu       $t7, $t7, -0x2BA8
    ctx->r15 = ADD32(ctx->r15, -0X2BA8);
    // 0x80175500: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80175504: beq         $t8, $zero, L_80175598
    if (ctx->r24 == 0) {
        // 0x80175508: nop
    
            goto L_80175598;
    }
    // 0x80175508: nop

    // 0x8017550C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80175510: addiu       $t9, $t9, -0x2BA8
    ctx->r25 = ADD32(ctx->r25, -0X2BA8);
    // 0x80175514: lw          $a0, 0x14($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X14);
    // 0x80175518: lw          $a1, 0x1C($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X1C);
    // 0x8017551C: addiu       $t0, $zero, 0xBC
    ctx->r8 = ADD32(0, 0XBC);
    // 0x80175520: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80175524: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80175528: jal         0x801755A8
    // 0x8017552C: addiu       $a3, $zero, 0xD7
    ctx->r7 = ADD32(0, 0XD7);
    func_801755A8_1501A0(rdram, ctx);
        goto after_0;
    // 0x8017552C: addiu       $a3, $zero, 0xD7
    ctx->r7 = ADD32(0, 0XD7);
    after_0:
    // 0x80175530: b           L_80175598
    // 0x80175534: nop

        goto L_80175598;
    // 0x80175534: nop

L_80175538:
    // 0x80175538: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017553C: addiu       $t1, $t1, -0x2BA8
    ctx->r9 = ADD32(ctx->r9, -0X2BA8);
    // 0x80175540: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x80175544: beq         $t2, $zero, L_80175568
    if (ctx->r10 == 0) {
        // 0x80175548: nop
    
            goto L_80175568;
    }
    // 0x80175548: nop

    // 0x8017554C: lw          $a0, 0x14($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X14);
    // 0x80175550: lw          $a1, 0x1C($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X1C);
    // 0x80175554: addiu       $t3, $zero, 0xBC
    ctx->r11 = ADD32(0, 0XBC);
    // 0x80175558: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8017555C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80175560: jal         0x801755A8
    // 0x80175564: addiu       $a3, $zero, 0x4E
    ctx->r7 = ADD32(0, 0X4E);
    func_801755A8_1501A0(rdram, ctx);
        goto after_1;
    // 0x80175564: addiu       $a3, $zero, 0x4E
    ctx->r7 = ADD32(0, 0X4E);
    after_1:
L_80175568:
    // 0x80175568: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017556C: addiu       $t4, $t4, -0x2BA8
    ctx->r12 = ADD32(ctx->r12, -0X2BA8);
    // 0x80175570: lw          $t5, 0x10($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X10);
    // 0x80175574: beq         $t5, $zero, L_80175598
    if (ctx->r13 == 0) {
        // 0x80175578: nop
    
            goto L_80175598;
    }
    // 0x80175578: nop

    // 0x8017557C: lw          $a0, 0x18($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X18);
    // 0x80175580: lw          $a1, 0x20($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X20);
    // 0x80175584: addiu       $t6, $zero, 0xBC
    ctx->r14 = ADD32(0, 0XBC);
    // 0x80175588: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8017558C: addiu       $a2, $zero, 0x22
    ctx->r6 = ADD32(0, 0X22);
    // 0x80175590: jal         0x801755A8
    // 0x80175594: addiu       $a3, $zero, 0x9C
    ctx->r7 = ADD32(0, 0X9C);
    func_801755A8_1501A0(rdram, ctx);
        goto after_2;
    // 0x80175594: addiu       $a3, $zero, 0x9C
    ctx->r7 = ADD32(0, 0X9C);
    after_2:
L_80175598:
    // 0x80175598: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8017559C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801755A0: jr          $ra
    // 0x801755A4: nop

    return;
    // 0x801755A4: nop

;}
RECOMP_FUNC void func_801755A8_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801755A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801755AC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x801755B0: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x801755B4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801755B8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801755BC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801755C0: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x801755C4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801755C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801755CC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801755D0: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x801755D4: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x801755D8: addiu       $t8, $zero, 0xB4
    ctx->r24 = ADD32(0, 0XB4);
    // 0x801755DC: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x801755E0: lw          $a0, -0x2924($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2924);
    // 0x801755E4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x801755E8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801755EC: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x801755F0: jal         0x800C6C6C
    // 0x801755F4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_0;
    // 0x801755F4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x801755F8: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x801755FC: beq         $t9, $zero, L_80175640
    if (ctx->r25 == 0) {
        // 0x80175600: nop
    
            goto L_80175640;
    }
    // 0x80175600: nop

    // 0x80175604: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80175608: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017560C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80175610: addu        $t1, $t0, $t9
    ctx->r9 = ADD32(ctx->r8, ctx->r25);
    // 0x80175614: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80175618: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8017561C: addu        $a0, $a0, $t2
    ctx->r4 = ADD32(ctx->r4, ctx->r10);
    // 0x80175620: addiu       $t3, $zero, 0xB4
    ctx->r11 = ADD32(0, 0XB4);
    // 0x80175624: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80175628: lw          $a0, -0x2924($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2924);
    // 0x8017562C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80175630: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80175634: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80175638: jal         0x800C6C6C
    // 0x8017563C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_1;
    // 0x8017563C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_1:
L_80175640:
    // 0x80175640: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80175644: beq         $t4, $zero, L_801756A0
    if (ctx->r12 == 0) {
        // 0x80175648: nop
    
            goto L_801756A0;
    }
    // 0x80175648: nop

    // 0x8017564C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80175650: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80175654: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80175658: sll         $t0, $t6, 2
    ctx->r8 = S32(ctx->r14 << 2);
    // 0x8017565C: addu        $t9, $t9, $t0
    ctx->r25 = ADD32(ctx->r25, ctx->r8);
    // 0x80175660: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80175664: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80175668: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8017566C: lw          $t9, -0x2818($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2818);
    // 0x80175670: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80175674: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80175678: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8017567C: addu        $a0, $a0, $t8
    ctx->r4 = ADD32(ctx->r4, ctx->r24);
    // 0x80175680: addiu       $t2, $zero, 0xB4
    ctx->r10 = ADD32(0, 0XB4);
    // 0x80175684: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80175688: lw          $a0, -0x2918($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2918);
    // 0x8017568C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80175690: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80175694: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x80175698: jal         0x800C6C6C
    // 0x8017569C: addu        $a2, $t9, $t1
    ctx->r6 = ADD32(ctx->r25, ctx->r9);
    func_800C6C6C(rdram, ctx);
        goto after_2;
    // 0x8017569C: addu        $a2, $t9, $t1
    ctx->r6 = ADD32(ctx->r25, ctx->r9);
    after_2:
L_801756A0:
    // 0x801756A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801756A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801756A8: jr          $ra
    // 0x801756AC: nop

    return;
    // 0x801756AC: nop

;}
RECOMP_FUNC void func_801756B0_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801756B0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801756B4: lw          $t6, -0x2E48($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2E48);
    // 0x801756B8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801756BC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801756C0: beq         $t6, $at, L_80175720
    if (ctx->r14 == ctx->r1) {
        // 0x801756C4: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80175720;
    }
    // 0x801756C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801756C8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801756CC: addiu       $t7, $t7, -0x2BA8
    ctx->r15 = ADD32(ctx->r15, -0X2BA8);
    // 0x801756D0: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x801756D4: beq         $t8, $zero, L_80175790
    if (ctx->r24 == 0) {
        // 0x801756D8: nop
    
            goto L_80175790;
    }
    // 0x801756D8: nop

    // 0x801756DC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801756E0: lw          $t9, -0x2E3C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2E3C);
    // 0x801756E4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x801756E8: beq         $t9, $zero, L_80175790
    if (ctx->r25 == 0) {
        // 0x801756EC: nop
    
            goto L_80175790;
    }
    // 0x801756EC: nop

L_801756F0:
    // 0x801756F0: jal         0x801757A0
    // 0x801756F4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_801757A0_1501A0(rdram, ctx);
        goto after_0;
    // 0x801756F4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_0:
    // 0x801756F8: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x801756FC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80175700: lw          $t2, -0x2E3C($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2E3C);
    // 0x80175704: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80175708: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x8017570C: sltu        $at, $t1, $t2
    ctx->r1 = ctx->r9 < ctx->r10 ? 1 : 0;
    // 0x80175710: bne         $at, $zero, L_801756F0
    if (ctx->r1 != 0) {
        // 0x80175714: nop
    
            goto L_801756F0;
    }
    // 0x80175714: nop

    // 0x80175718: b           L_80175790
    // 0x8017571C: nop

        goto L_80175790;
    // 0x8017571C: nop

L_80175720:
    // 0x80175720: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80175724: addiu       $t3, $t3, -0x2BA8
    ctx->r11 = ADD32(ctx->r11, -0X2BA8);
    // 0x80175728: lw          $t4, 0xC($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XC);
    // 0x8017572C: beq         $t4, $zero, L_80175758
    if (ctx->r12 == 0) {
        // 0x80175730: nop
    
            goto L_80175758;
    }
    // 0x80175730: nop

    // 0x80175734: jal         0x801757A0
    // 0x80175738: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_801757A0_1501A0(rdram, ctx);
        goto after_1;
    // 0x80175738: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x8017573C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80175740: lw          $t5, -0x2E3C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2E3C);
    // 0x80175744: sltiu       $at, $t5, 0x3
    ctx->r1 = ctx->r13 < 0X3 ? 1 : 0;
    // 0x80175748: bne         $at, $zero, L_80175758
    if (ctx->r1 != 0) {
        // 0x8017574C: nop
    
            goto L_80175758;
    }
    // 0x8017574C: nop

    // 0x80175750: jal         0x801757A0
    // 0x80175754: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_801757A0_1501A0(rdram, ctx);
        goto after_2;
    // 0x80175754: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_2:
L_80175758:
    // 0x80175758: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017575C: addiu       $t6, $t6, -0x2BA8
    ctx->r14 = ADD32(ctx->r14, -0X2BA8);
    // 0x80175760: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x80175764: beq         $t7, $zero, L_80175790
    if (ctx->r15 == 0) {
        // 0x80175768: nop
    
            goto L_80175790;
    }
    // 0x80175768: nop

    // 0x8017576C: jal         0x801757A0
    // 0x80175770: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_801757A0_1501A0(rdram, ctx);
        goto after_3;
    // 0x80175770: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x80175774: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80175778: lw          $t8, -0x2E3C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2E3C);
    // 0x8017577C: sltiu       $at, $t8, 0x3
    ctx->r1 = ctx->r24 < 0X3 ? 1 : 0;
    // 0x80175780: bne         $at, $zero, L_80175790
    if (ctx->r1 != 0) {
        // 0x80175784: nop
    
            goto L_80175790;
    }
    // 0x80175784: nop

    // 0x80175788: jal         0x801757A0
    // 0x8017578C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_801757A0_1501A0(rdram, ctx);
        goto after_4;
    // 0x8017578C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_4:
L_80175790:
    // 0x80175790: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80175794: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80175798: jr          $ra
    // 0x8017579C: nop

    return;
    // 0x8017579C: nop

;}
RECOMP_FUNC void func_801757A0_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801757A0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801757A4: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x801757A8: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x801757AC: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x801757B0: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x801757B4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801757B8: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x801757BC: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x801757C0: addu        $t1, $t1, $t7
    ctx->r9 = ADD32(ctx->r9, ctx->r15);
    // 0x801757C4: sll         $t9, $t6, 1
    ctx->r25 = S32(ctx->r14 << 1);
    // 0x801757C8: lw          $t8, -0x278C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X278C);
    // 0x801757CC: lbu         $t1, -0x2769($t1)
    ctx->r9 = MEM_BU(ctx->r9, -0X2769);
    // 0x801757D0: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x801757D4: lui         $s2, 0x801A
    ctx->r18 = S32(0X801A << 16);
    // 0x801757D8: addu        $s2, $s2, $t0
    ctx->r18 = ADD32(ctx->r18, ctx->r8);
    // 0x801757DC: lhu         $s2, -0x277C($s2)
    ctx->r18 = MEM_HU(ctx->r18, -0X277C);
    // 0x801757E0: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x801757E4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x801757E8: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x801757EC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801757F0: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x801757F4: addu        $t3, $t8, $t2
    ctx->r11 = ADD32(ctx->r24, ctx->r10);
    // 0x801757F8: sh          $s2, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r18;
    // 0x801757FC: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x80175800: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80175804: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x80175808: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8017580C: addu        $t9, $t9, $t6
    ctx->r25 = ADD32(ctx->r25, ctx->r14);
    // 0x80175810: lbu         $t9, -0x276A($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X276A);
    // 0x80175814: andi        $s1, $s2, 0xFFFF
    ctx->r17 = ctx->r18 & 0XFFFF;
    // 0x80175818: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8017581C: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x80175820: addu        $t7, $t4, $t0
    ctx->r15 = ADD32(ctx->r12, ctx->r8);
    // 0x80175824: sh          $s1, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r17;
    // 0x80175828: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x8017582C: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x80175830: andi        $s0, $s1, 0xFFFF
    ctx->r16 = ctx->r17 & 0XFFFF;
    // 0x80175834: sll         $t2, $t8, 2
    ctx->r10 = S32(ctx->r24 << 2);
    // 0x80175838: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8017583C: lbu         $t3, -0x276B($t3)
    ctx->r11 = MEM_BU(ctx->r11, -0X276B);
    // 0x80175840: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80175844: sll         $t5, $t3, 1
    ctx->r13 = S32(ctx->r11 << 1);
    // 0x80175848: addu        $t6, $t1, $t5
    ctx->r14 = ADD32(ctx->r9, ctx->r13);
    // 0x8017584C: sh          $s0, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r16;
    // 0x80175850: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x80175854: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x80175858: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017585C: sll         $t0, $t4, 2
    ctx->r8 = S32(ctx->r12 << 2);
    // 0x80175860: addu        $t7, $t7, $t0
    ctx->r15 = ADD32(ctx->r15, ctx->r8);
    // 0x80175864: lbu         $t7, -0x276C($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X276C);
    // 0x80175868: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8017586C: addu        $t2, $t9, $t8
    ctx->r10 = ADD32(ctx->r25, ctx->r24);
    // 0x80175870: sh          $s0, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r16;
    // 0x80175874: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x80175878: sll         $t1, $t3, 5
    ctx->r9 = S32(ctx->r11 << 5);
    // 0x8017587C: addu        $t5, $t5, $t1
    ctx->r13 = ADD32(ctx->r13, ctx->r9);
    // 0x80175880: lw          $t5, 0x39A8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X39A8);
    // 0x80175884: sltiu       $at, $t5, 0x5
    ctx->r1 = ctx->r13 < 0X5 ? 1 : 0;
    // 0x80175888: beq         $at, $zero, L_80175D9C
    if (ctx->r1 == 0) {
        // 0x8017588C: nop
    
            goto L_80175D9C;
    }
    // 0x8017588C: nop

    // 0x80175890: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80175894: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80175898: addu        $at, $at, $t5
    gpr jr_addend_801758A0 = ctx->r13;
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x8017589C: lw          $t5, -0x4C0($at)
    ctx->r13 = ADD32(ctx->r1, -0X4C0);
    // 0x801758A0: jr          $t5
    // 0x801758A4: nop

    switch (jr_addend_801758A0 >> 2) {
        case 0: goto L_801758A8; break;
        case 1: goto L_80175A4C; break;
        case 2: goto L_80175B30; break;
        case 3: goto L_80175C00; break;
        case 4: goto L_80175CD0; break;
        default: switch_error(__func__, 0x801758A0, 0x8019FB40);
    }
    // 0x801758A4: nop

L_801758A8:
    // 0x801758A8: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x801758AC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x801758B0: addiu       $t0, $t0, 0x3518
    ctx->r8 = ADD32(ctx->r8, 0X3518);
    // 0x801758B4: sll         $t4, $t6, 3
    ctx->r12 = S32(ctx->r14 << 3);
    // 0x801758B8: subu        $t4, $t4, $t6
    ctx->r12 = SUB32(ctx->r12, ctx->r14);
    // 0x801758BC: sll         $t4, $t4, 5
    ctx->r12 = S32(ctx->r12 << 5);
    // 0x801758C0: addu        $t7, $t4, $t0
    ctx->r15 = ADD32(ctx->r12, ctx->r8);
    // 0x801758C4: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801758C8: beq         $t9, $zero, L_80175910
    if (ctx->r25 == 0) {
        // 0x801758CC: nop
    
            goto L_80175910;
    }
    // 0x801758CC: nop

    // 0x801758D0: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801758D4: beq         $t8, $zero, L_80175910
    if (ctx->r24 == 0) {
        // 0x801758D8: nop
    
            goto L_80175910;
    }
    // 0x801758D8: nop

    // 0x801758DC: sll         $t4, $t6, 2
    ctx->r12 = S32(ctx->r14 << 2);
    // 0x801758E0: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x801758E4: addu        $t0, $t0, $t4
    ctx->r8 = ADD32(ctx->r8, ctx->r12);
    // 0x801758E8: sll         $t2, $t6, 1
    ctx->r10 = S32(ctx->r14 << 1);
    // 0x801758EC: lbu         $t0, -0x276C($t0)
    ctx->r8 = MEM_BU(ctx->r8, -0X276C);
    // 0x801758F0: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x801758F4: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x801758F8: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x801758FC: addu        $t1, $t1, $t3
    ctx->r9 = ADD32(ctx->r9, ctx->r11);
    // 0x80175900: lhu         $t1, -0x277A($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X277A);
    // 0x80175904: sll         $t9, $t0, 1
    ctx->r25 = S32(ctx->r8 << 1);
    // 0x80175908: addu        $t7, $t5, $t9
    ctx->r15 = ADD32(ctx->r13, ctx->r25);
    // 0x8017590C: sh          $t1, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r9;
L_80175910:
    // 0x80175910: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x80175914: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80175918: addiu       $t3, $t3, 0x3518
    ctx->r11 = ADD32(ctx->r11, 0X3518);
    // 0x8017591C: sll         $t2, $t8, 3
    ctx->r10 = S32(ctx->r24 << 3);
    // 0x80175920: subu        $t2, $t2, $t8
    ctx->r10 = SUB32(ctx->r10, ctx->r24);
    // 0x80175924: sll         $t2, $t2, 5
    ctx->r10 = S32(ctx->r10 << 5);
    // 0x80175928: addu        $t6, $t2, $t3
    ctx->r14 = ADD32(ctx->r10, ctx->r11);
    // 0x8017592C: lw          $t4, 0x38($t6)
    ctx->r12 = MEM_W(ctx->r14, 0X38);
    // 0x80175930: beq         $t4, $zero, L_80175978
    if (ctx->r12 == 0) {
        // 0x80175934: nop
    
            goto L_80175978;
    }
    // 0x80175934: nop

    // 0x80175938: lw          $t0, 0x40($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X40);
    // 0x8017593C: beq         $t0, $zero, L_80175978
    if (ctx->r8 == 0) {
        // 0x80175940: nop
    
            goto L_80175978;
    }
    // 0x80175940: nop

    // 0x80175944: sll         $t2, $t8, 2
    ctx->r10 = S32(ctx->r24 << 2);
    // 0x80175948: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8017594C: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80175950: sll         $t5, $t8, 1
    ctx->r13 = S32(ctx->r24 << 1);
    // 0x80175954: lbu         $t3, -0x276B($t3)
    ctx->r11 = MEM_BU(ctx->r11, -0X276B);
    // 0x80175958: sll         $t9, $t5, 1
    ctx->r25 = S32(ctx->r13 << 1);
    // 0x8017595C: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80175960: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80175964: addu        $t1, $t1, $t9
    ctx->r9 = ADD32(ctx->r9, ctx->r25);
    // 0x80175968: lhu         $t1, -0x277A($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X277A);
    // 0x8017596C: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x80175970: addu        $t6, $t7, $t4
    ctx->r14 = ADD32(ctx->r15, ctx->r12);
    // 0x80175974: sh          $t1, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r9;
L_80175978:
    // 0x80175978: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x8017597C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80175980: addiu       $t9, $t9, 0x3518
    ctx->r25 = ADD32(ctx->r25, 0X3518);
    // 0x80175984: sll         $t5, $t0, 3
    ctx->r13 = S32(ctx->r8 << 3);
    // 0x80175988: subu        $t5, $t5, $t0
    ctx->r13 = SUB32(ctx->r13, ctx->r8);
    // 0x8017598C: sll         $t5, $t5, 5
    ctx->r13 = S32(ctx->r13 << 5);
    // 0x80175990: addu        $t8, $t5, $t9
    ctx->r24 = ADD32(ctx->r13, ctx->r25);
    // 0x80175994: lw          $t2, 0x70($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X70);
    // 0x80175998: beq         $t2, $zero, L_801759E0
    if (ctx->r10 == 0) {
        // 0x8017599C: nop
    
            goto L_801759E0;
    }
    // 0x8017599C: nop

    // 0x801759A0: lw          $t3, 0x78($t8)
    ctx->r11 = MEM_W(ctx->r24, 0X78);
    // 0x801759A4: beq         $t3, $zero, L_801759E0
    if (ctx->r11 == 0) {
        // 0x801759A8: nop
    
            goto L_801759E0;
    }
    // 0x801759A8: nop

    // 0x801759AC: sll         $t5, $t0, 2
    ctx->r13 = S32(ctx->r8 << 2);
    // 0x801759B0: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x801759B4: addu        $t9, $t9, $t5
    ctx->r25 = ADD32(ctx->r25, ctx->r13);
    // 0x801759B8: sll         $t7, $t0, 1
    ctx->r15 = S32(ctx->r8 << 1);
    // 0x801759BC: lbu         $t9, -0x276A($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X276A);
    // 0x801759C0: sll         $t4, $t7, 1
    ctx->r12 = S32(ctx->r15 << 1);
    // 0x801759C4: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x801759C8: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x801759CC: addu        $t1, $t1, $t4
    ctx->r9 = ADD32(ctx->r9, ctx->r12);
    // 0x801759D0: lhu         $t1, -0x277A($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X277A);
    // 0x801759D4: sll         $t2, $t9, 1
    ctx->r10 = S32(ctx->r25 << 1);
    // 0x801759D8: addu        $t8, $t6, $t2
    ctx->r24 = ADD32(ctx->r14, ctx->r10);
    // 0x801759DC: sh          $t1, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r9;
L_801759E0:
    // 0x801759E0: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x801759E4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x801759E8: addiu       $t4, $t4, 0x3518
    ctx->r12 = ADD32(ctx->r12, 0X3518);
    // 0x801759EC: sll         $t7, $t3, 3
    ctx->r15 = S32(ctx->r11 << 3);
    // 0x801759F0: subu        $t7, $t7, $t3
    ctx->r15 = SUB32(ctx->r15, ctx->r11);
    // 0x801759F4: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x801759F8: addu        $t0, $t7, $t4
    ctx->r8 = ADD32(ctx->r15, ctx->r12);
    // 0x801759FC: lw          $t5, 0xA8($t0)
    ctx->r13 = MEM_W(ctx->r8, 0XA8);
    // 0x80175A00: beq         $t5, $zero, L_80175D9C
    if (ctx->r13 == 0) {
        // 0x80175A04: nop
    
            goto L_80175D9C;
    }
    // 0x80175A04: nop

    // 0x80175A08: lw          $t9, 0xB0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0XB0);
    // 0x80175A0C: beq         $t9, $zero, L_80175D9C
    if (ctx->r25 == 0) {
        // 0x80175A10: nop
    
            goto L_80175D9C;
    }
    // 0x80175A10: nop

    // 0x80175A14: sll         $t7, $t3, 2
    ctx->r15 = S32(ctx->r11 << 2);
    // 0x80175A18: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x80175A1C: addu        $t4, $t4, $t7
    ctx->r12 = ADD32(ctx->r12, ctx->r15);
    // 0x80175A20: lbu         $t4, -0x2769($t4)
    ctx->r12 = MEM_BU(ctx->r12, -0X2769);
    // 0x80175A24: sll         $t6, $t3, 1
    ctx->r14 = S32(ctx->r11 << 1);
    // 0x80175A28: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80175A2C: sll         $t2, $t6, 1
    ctx->r10 = S32(ctx->r14 << 1);
    // 0x80175A30: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80175A34: addu        $t1, $t1, $t2
    ctx->r9 = ADD32(ctx->r9, ctx->r10);
    // 0x80175A38: lhu         $t1, -0x277A($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X277A);
    // 0x80175A3C: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x80175A40: addu        $t0, $t8, $t5
    ctx->r8 = ADD32(ctx->r24, ctx->r13);
    // 0x80175A44: b           L_80175D9C
    // 0x80175A48: sh          $t1, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r9;
        goto L_80175D9C;
    // 0x80175A48: sh          $t1, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r9;
L_80175A4C:
    // 0x80175A4C: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x80175A50: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80175A54: addiu       $t2, $t2, 0x3518
    ctx->r10 = ADD32(ctx->r10, 0X3518);
    // 0x80175A58: sll         $t6, $t9, 3
    ctx->r14 = S32(ctx->r25 << 3);
    // 0x80175A5C: subu        $t6, $t6, $t9
    ctx->r14 = SUB32(ctx->r14, ctx->r25);
    // 0x80175A60: sll         $t6, $t6, 5
    ctx->r14 = S32(ctx->r14 << 5);
    // 0x80175A64: addu        $t3, $t6, $t2
    ctx->r11 = ADD32(ctx->r14, ctx->r10);
    // 0x80175A68: lw          $t7, 0x0($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X0);
    // 0x80175A6C: beq         $t7, $zero, L_80175D9C
    if (ctx->r15 == 0) {
        // 0x80175A70: nop
    
            goto L_80175D9C;
    }
    // 0x80175A70: nop

    // 0x80175A74: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x80175A78: beq         $t4, $zero, L_80175D9C
    if (ctx->r12 == 0) {
        // 0x80175A7C: nop
    
            goto L_80175D9C;
    }
    // 0x80175A7C: nop

    // 0x80175A80: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x80175A84: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80175A88: lui         $s2, 0x801A
    ctx->r18 = S32(0X801A << 16);
    // 0x80175A8C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80175A90: addu        $t6, $t6, $t9
    ctx->r14 = ADD32(ctx->r14, ctx->r25);
    // 0x80175A94: sll         $t5, $t8, 1
    ctx->r13 = S32(ctx->r24 << 1);
    // 0x80175A98: lbu         $t6, -0x2769($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X2769);
    // 0x80175A9C: sll         $t1, $t5, 1
    ctx->r9 = S32(ctx->r13 << 1);
    // 0x80175AA0: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80175AA4: addu        $s2, $s2, $t1
    ctx->r18 = ADD32(ctx->r18, ctx->r9);
    // 0x80175AA8: lhu         $s2, -0x277A($s2)
    ctx->r18 = MEM_HU(ctx->r18, -0X277A);
    // 0x80175AAC: sll         $t2, $t6, 1
    ctx->r10 = S32(ctx->r14 << 1);
    // 0x80175AB0: addu        $t7, $t0, $t2
    ctx->r15 = ADD32(ctx->r8, ctx->r10);
    // 0x80175AB4: sh          $s2, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r18;
    // 0x80175AB8: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x80175ABC: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80175AC0: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x80175AC4: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80175AC8: addu        $t1, $t1, $t5
    ctx->r9 = ADD32(ctx->r9, ctx->r13);
    // 0x80175ACC: lbu         $t1, -0x276A($t1)
    ctx->r9 = MEM_BU(ctx->r9, -0X276A);
    // 0x80175AD0: andi        $s1, $s2, 0xFFFF
    ctx->r17 = ctx->r18 & 0XFFFF;
    // 0x80175AD4: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80175AD8: sll         $t8, $t1, 1
    ctx->r24 = S32(ctx->r9 << 1);
    // 0x80175ADC: addu        $t9, $t3, $t8
    ctx->r25 = ADD32(ctx->r11, ctx->r24);
    // 0x80175AE0: sh          $s1, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r17;
    // 0x80175AE4: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x80175AE8: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80175AEC: andi        $s0, $s1, 0xFFFF
    ctx->r16 = ctx->r17 & 0XFFFF;
    // 0x80175AF0: sll         $t2, $t0, 2
    ctx->r10 = S32(ctx->r8 << 2);
    // 0x80175AF4: addu        $t7, $t7, $t2
    ctx->r15 = ADD32(ctx->r15, ctx->r10);
    // 0x80175AF8: lbu         $t7, -0x276B($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X276B);
    // 0x80175AFC: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80175B00: sll         $t4, $t7, 1
    ctx->r12 = S32(ctx->r15 << 1);
    // 0x80175B04: addu        $t5, $t6, $t4
    ctx->r13 = ADD32(ctx->r14, ctx->r12);
    // 0x80175B08: sh          $s0, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r16;
    // 0x80175B0C: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x80175B10: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x80175B14: sll         $t8, $t3, 2
    ctx->r24 = S32(ctx->r11 << 2);
    // 0x80175B18: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80175B1C: lbu         $t9, -0x276C($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X276C);
    // 0x80175B20: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x80175B24: addu        $t2, $t1, $t0
    ctx->r10 = ADD32(ctx->r9, ctx->r8);
    // 0x80175B28: b           L_80175D9C
    // 0x80175B2C: sh          $s0, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r16;
        goto L_80175D9C;
    // 0x80175B2C: sh          $s0, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r16;
L_80175B30:
    // 0x80175B30: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x80175B34: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80175B38: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x80175B3C: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x80175B40: addu        $t4, $t4, $t6
    ctx->r12 = ADD32(ctx->r12, ctx->r14);
    // 0x80175B44: lw          $t4, -0x2B6C($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2B6C);
    // 0x80175B48: bne         $t4, $at, L_80175D9C
    if (ctx->r12 != ctx->r1) {
        // 0x80175B4C: nop
    
            goto L_80175D9C;
    }
    // 0x80175B4C: nop

    // 0x80175B50: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x80175B54: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x80175B58: lui         $s2, 0x801A
    ctx->r18 = S32(0X801A << 16);
    // 0x80175B5C: sll         $t1, $t5, 2
    ctx->r9 = S32(ctx->r13 << 2);
    // 0x80175B60: addu        $t0, $t0, $t1
    ctx->r8 = ADD32(ctx->r8, ctx->r9);
    // 0x80175B64: sll         $t3, $t5, 1
    ctx->r11 = S32(ctx->r13 << 1);
    // 0x80175B68: lbu         $t0, -0x2769($t0)
    ctx->r8 = MEM_BU(ctx->r8, -0X2769);
    // 0x80175B6C: sll         $t8, $t3, 1
    ctx->r24 = S32(ctx->r11 << 1);
    // 0x80175B70: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x80175B74: addu        $s2, $s2, $t8
    ctx->r18 = ADD32(ctx->r18, ctx->r24);
    // 0x80175B78: lhu         $s2, -0x277A($s2)
    ctx->r18 = MEM_HU(ctx->r18, -0X277A);
    // 0x80175B7C: sll         $t2, $t0, 1
    ctx->r10 = S32(ctx->r8 << 1);
    // 0x80175B80: addu        $t7, $t9, $t2
    ctx->r15 = ADD32(ctx->r25, ctx->r10);
    // 0x80175B84: sh          $s2, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r18;
    // 0x80175B88: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x80175B8C: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80175B90: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80175B94: sll         $t3, $t4, 2
    ctx->r11 = S32(ctx->r12 << 2);
    // 0x80175B98: addu        $t8, $t8, $t3
    ctx->r24 = ADD32(ctx->r24, ctx->r11);
    // 0x80175B9C: lbu         $t8, -0x276A($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X276A);
    // 0x80175BA0: andi        $s1, $s2, 0xFFFF
    ctx->r17 = ctx->r18 & 0XFFFF;
    // 0x80175BA4: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80175BA8: sll         $t5, $t8, 1
    ctx->r13 = S32(ctx->r24 << 1);
    // 0x80175BAC: addu        $t1, $t6, $t5
    ctx->r9 = ADD32(ctx->r14, ctx->r13);
    // 0x80175BB0: sh          $s1, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r17;
    // 0x80175BB4: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x80175BB8: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80175BBC: andi        $s0, $s1, 0xFFFF
    ctx->r16 = ctx->r17 & 0XFFFF;
    // 0x80175BC0: sll         $t2, $t9, 2
    ctx->r10 = S32(ctx->r25 << 2);
    // 0x80175BC4: addu        $t7, $t7, $t2
    ctx->r15 = ADD32(ctx->r15, ctx->r10);
    // 0x80175BC8: lbu         $t7, -0x276B($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X276B);
    // 0x80175BCC: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80175BD0: sll         $t4, $t7, 1
    ctx->r12 = S32(ctx->r15 << 1);
    // 0x80175BD4: addu        $t3, $t0, $t4
    ctx->r11 = ADD32(ctx->r8, ctx->r12);
    // 0x80175BD8: sh          $s0, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r16;
    // 0x80175BDC: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80175BE0: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80175BE4: sll         $t5, $t6, 2
    ctx->r13 = S32(ctx->r14 << 2);
    // 0x80175BE8: addu        $t1, $t1, $t5
    ctx->r9 = ADD32(ctx->r9, ctx->r13);
    // 0x80175BEC: lbu         $t1, -0x276C($t1)
    ctx->r9 = MEM_BU(ctx->r9, -0X276C);
    // 0x80175BF0: sll         $t9, $t1, 1
    ctx->r25 = S32(ctx->r9 << 1);
    // 0x80175BF4: addu        $t2, $t8, $t9
    ctx->r10 = ADD32(ctx->r24, ctx->r25);
    // 0x80175BF8: b           L_80175D9C
    // 0x80175BFC: sh          $s0, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r16;
        goto L_80175D9C;
    // 0x80175BFC: sh          $s0, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r16;
L_80175C00:
    // 0x80175C00: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x80175C04: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80175C08: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x80175C0C: sll         $t0, $t7, 2
    ctx->r8 = S32(ctx->r15 << 2);
    // 0x80175C10: addu        $t4, $t4, $t0
    ctx->r12 = ADD32(ctx->r12, ctx->r8);
    // 0x80175C14: lw          $t4, -0x2B6C($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2B6C);
    // 0x80175C18: bne         $t4, $at, L_80175D9C
    if (ctx->r12 != ctx->r1) {
        // 0x80175C1C: nop
    
            goto L_80175D9C;
    }
    // 0x80175C1C: nop

    // 0x80175C20: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x80175C24: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80175C28: lui         $s2, 0x801A
    ctx->r18 = S32(0X801A << 16);
    // 0x80175C2C: sll         $t8, $t3, 2
    ctx->r24 = S32(ctx->r11 << 2);
    // 0x80175C30: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80175C34: sll         $t6, $t3, 1
    ctx->r14 = S32(ctx->r11 << 1);
    // 0x80175C38: lbu         $t9, -0x2769($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X2769);
    // 0x80175C3C: sll         $t5, $t6, 1
    ctx->r13 = S32(ctx->r14 << 1);
    // 0x80175C40: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x80175C44: addu        $s2, $s2, $t5
    ctx->r18 = ADD32(ctx->r18, ctx->r13);
    // 0x80175C48: lhu         $s2, -0x277A($s2)
    ctx->r18 = MEM_HU(ctx->r18, -0X277A);
    // 0x80175C4C: sll         $t2, $t9, 1
    ctx->r10 = S32(ctx->r25 << 1);
    // 0x80175C50: addu        $t7, $t1, $t2
    ctx->r15 = ADD32(ctx->r9, ctx->r10);
    // 0x80175C54: sh          $s2, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r18;
    // 0x80175C58: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x80175C5C: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80175C60: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80175C64: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x80175C68: addu        $t5, $t5, $t6
    ctx->r13 = ADD32(ctx->r13, ctx->r14);
    // 0x80175C6C: lbu         $t5, -0x276A($t5)
    ctx->r13 = MEM_BU(ctx->r13, -0X276A);
    // 0x80175C70: andi        $s1, $s2, 0xFFFF
    ctx->r17 = ctx->r18 & 0XFFFF;
    // 0x80175C74: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80175C78: sll         $t3, $t5, 1
    ctx->r11 = S32(ctx->r13 << 1);
    // 0x80175C7C: addu        $t8, $t0, $t3
    ctx->r24 = ADD32(ctx->r8, ctx->r11);
    // 0x80175C80: sh          $s1, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r17;
    // 0x80175C84: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x80175C88: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x80175C8C: andi        $s0, $s1, 0xFFFF
    ctx->r16 = ctx->r17 & 0XFFFF;
    // 0x80175C90: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80175C94: addu        $t7, $t7, $t2
    ctx->r15 = ADD32(ctx->r15, ctx->r10);
    // 0x80175C98: lbu         $t7, -0x276B($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X276B);
    // 0x80175C9C: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80175CA0: sll         $t4, $t7, 1
    ctx->r12 = S32(ctx->r15 << 1);
    // 0x80175CA4: addu        $t6, $t9, $t4
    ctx->r14 = ADD32(ctx->r25, ctx->r12);
    // 0x80175CA8: sh          $s0, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r16;
    // 0x80175CAC: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x80175CB0: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x80175CB4: sll         $t3, $t0, 2
    ctx->r11 = S32(ctx->r8 << 2);
    // 0x80175CB8: addu        $t8, $t8, $t3
    ctx->r24 = ADD32(ctx->r24, ctx->r11);
    // 0x80175CBC: lbu         $t8, -0x276C($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X276C);
    // 0x80175CC0: sll         $t1, $t8, 1
    ctx->r9 = S32(ctx->r24 << 1);
    // 0x80175CC4: addu        $t2, $t5, $t1
    ctx->r10 = ADD32(ctx->r13, ctx->r9);
    // 0x80175CC8: b           L_80175D9C
    // 0x80175CCC: sh          $s0, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r16;
        goto L_80175D9C;
    // 0x80175CCC: sh          $s0, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r16;
L_80175CD0:
    // 0x80175CD0: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x80175CD4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80175CD8: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x80175CDC: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x80175CE0: addu        $t4, $t4, $t9
    ctx->r12 = ADD32(ctx->r12, ctx->r25);
    // 0x80175CE4: lw          $t4, -0x2B6C($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2B6C);
    // 0x80175CE8: bne         $t4, $at, L_80175D9C
    if (ctx->r12 != ctx->r1) {
        // 0x80175CEC: nop
    
            goto L_80175D9C;
    }
    // 0x80175CEC: nop

    // 0x80175CF0: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80175CF4: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80175CF8: lui         $s2, 0x801A
    ctx->r18 = S32(0X801A << 16);
    // 0x80175CFC: sll         $t5, $t6, 2
    ctx->r13 = S32(ctx->r14 << 2);
    // 0x80175D00: addu        $t1, $t1, $t5
    ctx->r9 = ADD32(ctx->r9, ctx->r13);
    // 0x80175D04: sll         $t0, $t6, 1
    ctx->r8 = S32(ctx->r14 << 1);
    // 0x80175D08: lbu         $t1, -0x2769($t1)
    ctx->r9 = MEM_BU(ctx->r9, -0X2769);
    // 0x80175D0C: sll         $t3, $t0, 1
    ctx->r11 = S32(ctx->r8 << 1);
    // 0x80175D10: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80175D14: addu        $s2, $s2, $t3
    ctx->r18 = ADD32(ctx->r18, ctx->r11);
    // 0x80175D18: lhu         $s2, -0x277A($s2)
    ctx->r18 = MEM_HU(ctx->r18, -0X277A);
    // 0x80175D1C: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x80175D20: addu        $t7, $t8, $t2
    ctx->r15 = ADD32(ctx->r24, ctx->r10);
    // 0x80175D24: sh          $s2, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r18;
    // 0x80175D28: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x80175D2C: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80175D30: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x80175D34: sll         $t0, $t4, 2
    ctx->r8 = S32(ctx->r12 << 2);
    // 0x80175D38: addu        $t3, $t3, $t0
    ctx->r11 = ADD32(ctx->r11, ctx->r8);
    // 0x80175D3C: lbu         $t3, -0x276A($t3)
    ctx->r11 = MEM_BU(ctx->r11, -0X276A);
    // 0x80175D40: andi        $s1, $s2, 0xFFFF
    ctx->r17 = ctx->r18 & 0XFFFF;
    // 0x80175D44: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80175D48: sll         $t6, $t3, 1
    ctx->r14 = S32(ctx->r11 << 1);
    // 0x80175D4C: addu        $t5, $t9, $t6
    ctx->r13 = ADD32(ctx->r25, ctx->r14);
    // 0x80175D50: sh          $s1, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r17;
    // 0x80175D54: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x80175D58: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x80175D5C: andi        $s0, $s1, 0xFFFF
    ctx->r16 = ctx->r17 & 0XFFFF;
    // 0x80175D60: sll         $t2, $t8, 2
    ctx->r10 = S32(ctx->r24 << 2);
    // 0x80175D64: addu        $t7, $t7, $t2
    ctx->r15 = ADD32(ctx->r15, ctx->r10);
    // 0x80175D68: lbu         $t7, -0x276B($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X276B);
    // 0x80175D6C: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80175D70: sll         $t4, $t7, 1
    ctx->r12 = S32(ctx->r15 << 1);
    // 0x80175D74: addu        $t0, $t1, $t4
    ctx->r8 = ADD32(ctx->r9, ctx->r12);
    // 0x80175D78: sh          $s0, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r16;
    // 0x80175D7C: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x80175D80: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x80175D84: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x80175D88: addu        $t5, $t5, $t6
    ctx->r13 = ADD32(ctx->r13, ctx->r14);
    // 0x80175D8C: lbu         $t5, -0x276C($t5)
    ctx->r13 = MEM_BU(ctx->r13, -0X276C);
    // 0x80175D90: sll         $t8, $t5, 1
    ctx->r24 = S32(ctx->r13 << 1);
    // 0x80175D94: addu        $t2, $t3, $t8
    ctx->r10 = ADD32(ctx->r11, ctx->r24);
    // 0x80175D98: sh          $s0, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r16;
L_80175D9C:
    // 0x80175D9C: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x80175DA0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80175DA4: addiu       $t4, $t4, -0x2BA8
    ctx->r12 = ADD32(ctx->r12, -0X2BA8);
    // 0x80175DA8: sll         $t1, $t7, 2
    ctx->r9 = S32(ctx->r15 << 2);
    // 0x80175DAC: addu        $t0, $t1, $t4
    ctx->r8 = ADD32(ctx->r9, ctx->r12);
    // 0x80175DB0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80175DB4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80175DB8: lw          $a1, 0x64($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X64);
    // 0x80175DBC: lw          $a2, 0x74($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X74);
    // 0x80175DC0: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80175DC4: addu        $a0, $a0, $t1
    ctx->r4 = ADD32(ctx->r4, ctx->r9);
    // 0x80175DC8: addiu       $t9, $zero, 0xC8
    ctx->r25 = ADD32(0, 0XC8);
    // 0x80175DCC: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80175DD0: lw          $a0, -0x279C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X279C);
    // 0x80175DD4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80175DD8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80175DDC: addiu       $a1, $a1, 0x90
    ctx->r5 = ADD32(ctx->r5, 0X90);
    // 0x80175DE0: jal         0x800C6C6C
    // 0x80175DE4: addiu       $a2, $a2, 0x68
    ctx->r6 = ADD32(ctx->r6, 0X68);
    func_800C6C6C(rdram, ctx);
        goto after_0;
    // 0x80175DE4: addiu       $a2, $a2, 0x68
    ctx->r6 = ADD32(ctx->r6, 0X68);
    after_0:
    // 0x80175DE8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80175DEC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80175DF0: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80175DF4: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80175DF8: jr          $ra
    // 0x80175DFC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80175DFC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
