#include "recomp.h"
extern void load_overlays(uint32_t rom, int32_t ram_addr, uint32_t size);
extern void unload_overlays(int32_t ram_addr, uint32_t size);
#include "funcs.h"

RECOMP_FUNC void func_801955B0_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801955B0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801955B4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801955B8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x801955BC: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x801955C0: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x801955C4: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x801955C8: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x801955CC: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x801955D0: addiu       $t6, $t6, -0x2E28
    ctx->r14 = ADD32(ctx->r14, -0X2E28);
    // 0x801955D4: lbu         $t7, 0xA($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0XA);
    // 0x801955D8: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x801955DC: beq         $t8, $zero, L_801956F4
    if (ctx->r24 == 0) {
        // 0x801955E0: nop
    
            goto L_801956F4;
    }
    // 0x801955E0: nop

    // 0x801955E4: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x801955E8: sltiu       $at, $s0, 0x5
    ctx->r1 = ctx->r16 < 0X5 ? 1 : 0;
    // 0x801955EC: bne         $at, $zero, L_80195604
    if (ctx->r1 != 0) {
        // 0x801955F0: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_80195604;
    }
    // 0x801955F0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801955F4: beq         $s0, $at, L_801956B4
    if (ctx->r16 == ctx->r1) {
        // 0x801955F8: nop
    
            goto L_801956B4;
    }
    // 0x801955F8: nop

    // 0x801955FC: b           L_801956C8
    // 0x80195600: nop

        goto L_801956C8;
    // 0x80195600: nop

L_80195604:
    // 0x80195604: sltiu       $at, $s0, 0x5
    ctx->r1 = ctx->r16 < 0X5 ? 1 : 0;
    // 0x80195608: beq         $at, $zero, L_801956C8
    if (ctx->r1 == 0) {
        // 0x8019560C: nop
    
            goto L_801956C8;
    }
    // 0x8019560C: nop

    // 0x80195610: sll         $t9, $s0, 2
    ctx->r25 = S32(ctx->r16 << 2);
    // 0x80195614: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80195618: addu        $at, $at, $t9
    gpr jr_addend_80195620 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8019561C: lw          $t9, 0x85C($at)
    ctx->r25 = ADD32(ctx->r1, 0X85C);
    // 0x80195620: jr          $t9
    // 0x80195624: nop

    switch (jr_addend_80195620 >> 2) {
        case 0: goto L_80195628; break;
        case 1: goto L_80195644; break;
        case 2: goto L_80195660; break;
        case 3: goto L_8019567C; break;
        case 4: goto L_80195698; break;
        default: switch_error(__func__, 0x80195620, 0x801A085C);
    }
    // 0x80195624: nop

L_80195628:
    // 0x80195628: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8019562C: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80195630: addiu       $a1, $a1, -0xC38
    ctx->r5 = ADD32(ctx->r5, -0XC38);
    // 0x80195634: jal         0x800D87E4
    // 0x80195638: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_0;
    // 0x80195638: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_0:
    // 0x8019563C: b           L_801956C8
    // 0x80195640: nop

        goto L_801956C8;
    // 0x80195640: nop

L_80195644:
    // 0x80195644: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80195648: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x8019564C: addiu       $a1, $a1, -0xC18
    ctx->r5 = ADD32(ctx->r5, -0XC18);
    // 0x80195650: jal         0x800D87E4
    // 0x80195654: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_1;
    // 0x80195654: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_1:
    // 0x80195658: b           L_801956C8
    // 0x8019565C: nop

        goto L_801956C8;
    // 0x8019565C: nop

L_80195660:
    // 0x80195660: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80195664: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80195668: addiu       $a1, $a1, -0xBF8
    ctx->r5 = ADD32(ctx->r5, -0XBF8);
    // 0x8019566C: jal         0x800D87E4
    // 0x80195670: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_2;
    // 0x80195670: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_2:
    // 0x80195674: b           L_801956C8
    // 0x80195678: nop

        goto L_801956C8;
    // 0x80195678: nop

L_8019567C:
    // 0x8019567C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80195680: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80195684: addiu       $a1, $a1, -0xBE0
    ctx->r5 = ADD32(ctx->r5, -0XBE0);
    // 0x80195688: jal         0x800D87E4
    // 0x8019568C: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_3;
    // 0x8019568C: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_3:
    // 0x80195690: b           L_801956C8
    // 0x80195694: nop

        goto L_801956C8;
    // 0x80195694: nop

L_80195698:
    // 0x80195698: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8019569C: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x801956A0: addiu       $a1, $a1, -0xBC8
    ctx->r5 = ADD32(ctx->r5, -0XBC8);
    // 0x801956A4: jal         0x800D87E4
    // 0x801956A8: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_4;
    // 0x801956A8: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_4:
    // 0x801956AC: b           L_801956C8
    // 0x801956B0: nop

        goto L_801956C8;
    // 0x801956B0: nop

L_801956B4:
    // 0x801956B4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x801956B8: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x801956BC: addiu       $a1, $a1, -0xBB0
    ctx->r5 = ADD32(ctx->r5, -0XBB0);
    // 0x801956C0: jal         0x800D87E4
    // 0x801956C4: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_5;
    // 0x801956C4: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_5:
L_801956C8:
    // 0x801956C8: addiu       $t0, $zero, 0xB3
    ctx->r8 = ADD32(0, 0XB3);
    // 0x801956CC: addiu       $t1, $zero, 0xB3
    ctx->r9 = ADD32(0, 0XB3);
    // 0x801956D0: addiu       $t2, $zero, 0x68
    ctx->r10 = ADD32(0, 0X68);
    // 0x801956D4: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x801956D8: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x801956DC: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x801956E0: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x801956E4: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x801956E8: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x801956EC: jal         0x80193DE8
    // 0x801956F0: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    func_80193DE8_1501A0(rdram, ctx);
        goto after_6;
    // 0x801956F0: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    after_6:
L_801956F4:
    // 0x801956F4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x801956F8: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x801956FC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80195700: jr          $ra
    // 0x80195704: nop

    return;
    // 0x80195704: nop

;}
RECOMP_FUNC void func_80195708_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80195708: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8019570C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80195710: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80195714: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80195718: addiu       $a1, $a1, -0xB9C
    ctx->r5 = ADD32(ctx->r5, -0XB9C);
    // 0x8019571C: jal         0x800D87E4
    // 0x80195720: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_0;
    // 0x80195720: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_0:
    // 0x80195724: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80195728: addiu       $t6, $t6, -0x2E18
    ctx->r14 = ADD32(ctx->r14, -0X2E18);
    // 0x8019572C: lw          $t7, 0x40($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X40);
    // 0x80195730: andi        $t8, $t7, 0x20
    ctx->r24 = ctx->r15 & 0X20;
    // 0x80195734: beq         $t8, $zero, L_80195770
    if (ctx->r24 == 0) {
        // 0x80195738: nop
    
            goto L_80195770;
    }
    // 0x80195738: nop

    // 0x8019573C: andi        $t9, $t7, 0x1F
    ctx->r25 = ctx->r15 & 0X1F;
    // 0x80195740: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x80195744: addiu       $t1, $t0, 0x7
    ctx->r9 = ADD32(ctx->r8, 0X7);
    // 0x80195748: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8019574C: addiu       $a0, $zero, 0x5C
    ctx->r4 = ADD32(0, 0X5C);
    // 0x80195750: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    // 0x80195754: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80195758: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8019575C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80195760: jal         0x80193DE8
    // 0x80195764: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    func_80193DE8_1501A0(rdram, ctx);
        goto after_1;
    // 0x80195764: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_1:
    // 0x80195768: b           L_801957AC
    // 0x8019576C: nop

        goto L_801957AC;
    // 0x8019576C: nop

L_80195770:
    // 0x80195770: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80195774: addiu       $t2, $t2, -0x2E18
    ctx->r10 = ADD32(ctx->r10, -0X2E18);
    // 0x80195778: lw          $t3, 0x40($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X40);
    // 0x8019577C: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80195780: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80195784: andi        $t4, $t3, 0x1F
    ctx->r12 = ctx->r11 & 0X1F;
    // 0x80195788: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x8019578C: subu        $t8, $t6, $t5
    ctx->r24 = SUB32(ctx->r14, ctx->r13);
    // 0x80195790: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80195794: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80195798: addiu       $a0, $zero, 0x5C
    ctx->r4 = ADD32(0, 0X5C);
    // 0x8019579C: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    // 0x801957A0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x801957A4: jal         0x80193DE8
    // 0x801957A8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_80193DE8_1501A0(rdram, ctx);
        goto after_2;
    // 0x801957A8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_2:
L_801957AC:
    // 0x801957AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801957B0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801957B4: jr          $ra
    // 0x801957B8: nop

    return;
    // 0x801957B8: nop

;}
RECOMP_FUNC void func_801957BC_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801957BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801957C0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801957C4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801957C8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801957CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801957D0: addiu       $t6, $t6, 0x3988
    ctx->r14 = ADD32(ctx->r14, 0X3988);
    // 0x801957D4: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x801957D8: addiu       $a1, $zero, 0x48
    ctx->r5 = ADD32(0, 0X48);
    // 0x801957DC: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    // 0x801957E0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801957E4: jal         0x80195280
    // 0x801957E8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80195280_1501A0(rdram, ctx);
        goto after_0;
    // 0x801957E8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x801957EC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801957F0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801957F4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801957F8: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    // 0x801957FC: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    // 0x80195800: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80195804: jal         0x8019530C
    // 0x80195808: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_8019530C_1501A0(rdram, ctx);
        goto after_1;
    // 0x80195808: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x8019580C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80195810: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80195814: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80195818: addiu       $t7, $t7, 0x39A0
    ctx->r15 = ADD32(ctx->r15, 0X39A0);
    // 0x8019581C: lw          $a0, 0x1C($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X1C);
    // 0x80195820: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x80195824: addiu       $a2, $zero, 0x48
    ctx->r6 = ADD32(0, 0X48);
    // 0x80195828: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8019582C: jal         0x80195378
    // 0x80195830: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_80195378_1501A0(rdram, ctx);
        goto after_2;
    // 0x80195830: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x80195834: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80195838: addiu       $t8, $t8, 0x39A0
    ctx->r24 = ADD32(ctx->r24, 0X39A0);
    // 0x8019583C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80195840: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80195844: lw          $a0, 0x10($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X10);
    // 0x80195848: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x8019584C: addiu       $a2, $zero, 0x60
    ctx->r6 = ADD32(0, 0X60);
    // 0x80195850: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80195854: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80195858: jal         0x80195448
    // 0x8019585C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_80195448_1501A0(rdram, ctx);
        goto after_3;
    // 0x8019585C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_3:
    // 0x80195860: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80195864: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80195868: addiu       $t9, $t9, 0x39A0
    ctx->r25 = ADD32(ctx->r25, 0X39A0);
    // 0x8019586C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80195870: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80195874: lw          $a0, 0x18($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X18);
    // 0x80195878: lw          $a1, 0x14($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X14);
    // 0x8019587C: addiu       $a2, $zero, 0x60
    ctx->r6 = ADD32(0, 0X60);
    // 0x80195880: addiu       $a3, $zero, 0x74
    ctx->r7 = ADD32(0, 0X74);
    // 0x80195884: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x80195888: jal         0x801954DC
    // 0x8019588C: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    func_801954DC_1501A0(rdram, ctx);
        goto after_4;
    // 0x8019588C: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_4:
    // 0x80195890: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80195894: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80195898: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019589C: addiu       $t0, $t0, 0x39A0
    ctx->r8 = ADD32(ctx->r8, 0X39A0);
    // 0x801958A0: lw          $a0, 0x8($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X8);
    // 0x801958A4: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x801958A8: addiu       $a2, $zero, 0x8C
    ctx->r6 = ADD32(0, 0X8C);
    // 0x801958AC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801958B0: jal         0x801955B0
    // 0x801958B4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_801955B0_1501A0(rdram, ctx);
        goto after_5;
    // 0x801958B4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_5:
    // 0x801958B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801958BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801958C0: jr          $ra
    // 0x801958C4: nop

    return;
    // 0x801958C4: nop

;}
RECOMP_FUNC void func_801958C8_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801958C8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801958CC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801958D0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801958D4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801958D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801958DC: addiu       $t6, $t6, 0x3988
    ctx->r14 = ADD32(ctx->r14, 0X3988);
    // 0x801958E0: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x801958E4: addiu       $a1, $zero, 0x48
    ctx->r5 = ADD32(0, 0X48);
    // 0x801958E8: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    // 0x801958EC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801958F0: jal         0x80195280
    // 0x801958F4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80195280_1501A0(rdram, ctx);
        goto after_0;
    // 0x801958F4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x801958F8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801958FC: lw          $t7, -0x2E3C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2E3C);
    // 0x80195900: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80195904: beq         $t7, $zero, L_80195A50
    if (ctx->r15 == 0) {
        // 0x80195908: nop
    
            goto L_80195A50;
    }
    // 0x80195908: nop

L_8019590C:
    // 0x8019590C: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80195910: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80195914: addiu       $t0, $t0, -0x2E18
    ctx->r8 = ADD32(ctx->r8, -0X2E18);
    // 0x80195918: lw          $t1, 0x18($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X18);
    // 0x8019591C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80195920: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80195924: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80195928: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019592C: sll         $t9, $t9, 6
    ctx->r25 = S32(ctx->r25 << 6);
    // 0x80195930: subu        $t2, $t9, $t1
    ctx->r10 = SUB32(ctx->r25, ctx->r9);
    // 0x80195934: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x80195938: addiu       $a1, $t2, 0x64
    ctx->r5 = ADD32(ctx->r10, 0X64);
    // 0x8019593C: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    // 0x80195940: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80195944: addiu       $a0, $t8, 0x1
    ctx->r4 = ADD32(ctx->r24, 0X1);
    // 0x80195948: jal         0x8019530C
    // 0x8019594C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_8019530C_1501A0(rdram, ctx);
        goto after_1;
    // 0x8019594C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x80195950: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80195954: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80195958: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019595C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80195960: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80195964: sll         $t4, $t3, 5
    ctx->r12 = S32(ctx->r11 << 5);
    // 0x80195968: addu        $a0, $a0, $t4
    ctx->r4 = ADD32(ctx->r4, ctx->r12);
    // 0x8019596C: lw          $a0, 0x39BC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X39BC);
    // 0x80195970: addiu       $a2, $zero, 0x48
    ctx->r6 = ADD32(0, 0X48);
    // 0x80195974: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80195978: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    // 0x8019597C: jal         0x80195378
    // 0x80195980: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_80195378_1501A0(rdram, ctx);
        goto after_2;
    // 0x80195980: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x80195984: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80195988: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8019598C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80195990: sll         $t6, $t5, 5
    ctx->r14 = S32(ctx->r13 << 5);
    // 0x80195994: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x80195998: lw          $a0, 0x39B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X39B0);
    // 0x8019599C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801959A0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x801959A4: addiu       $a2, $zero, 0x60
    ctx->r6 = ADD32(0, 0X60);
    // 0x801959A8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801959AC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x801959B0: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    // 0x801959B4: jal         0x80195448
    // 0x801959B8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_80195448_1501A0(rdram, ctx);
        goto after_3;
    // 0x801959B8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_3:
    // 0x801959BC: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x801959C0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801959C4: addiu       $t9, $t9, 0x39A0
    ctx->r25 = ADD32(ctx->r25, 0X39A0);
    // 0x801959C8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801959CC: sll         $t0, $t7, 5
    ctx->r8 = S32(ctx->r15 << 5);
    // 0x801959D0: addu        $t1, $t0, $t9
    ctx->r9 = ADD32(ctx->r8, ctx->r25);
    // 0x801959D4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801959D8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801959DC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x801959E0: lw          $a0, 0x18($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X18);
    // 0x801959E4: lw          $a1, 0x14($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X14);
    // 0x801959E8: addiu       $a3, $zero, 0x74
    ctx->r7 = ADD32(0, 0X74);
    // 0x801959EC: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x801959F0: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x801959F4: jal         0x801954DC
    // 0x801959F8: addiu       $a2, $a2, 0x60
    ctx->r6 = ADD32(ctx->r6, 0X60);
    func_801954DC_1501A0(rdram, ctx);
        goto after_4;
    // 0x801959F8: addiu       $a2, $a2, 0x60
    ctx->r6 = ADD32(ctx->r6, 0X60);
    after_4:
    // 0x801959FC: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80195A00: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80195A04: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80195A08: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80195A0C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80195A10: sll         $t2, $t8, 5
    ctx->r10 = S32(ctx->r24 << 5);
    // 0x80195A14: addu        $a0, $a0, $t2
    ctx->r4 = ADD32(ctx->r4, ctx->r10);
    // 0x80195A18: lw          $a0, 0x39A8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X39A8);
    // 0x80195A1C: addiu       $a2, $zero, 0x8C
    ctx->r6 = ADD32(0, 0X8C);
    // 0x80195A20: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80195A24: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    // 0x80195A28: jal         0x801955B0
    // 0x80195A2C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_801955B0_1501A0(rdram, ctx);
        goto after_5;
    // 0x80195A2C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_5:
    // 0x80195A30: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80195A34: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80195A38: lw          $t5, -0x2E3C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2E3C);
    // 0x80195A3C: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80195A40: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x80195A44: sltu        $at, $t4, $t5
    ctx->r1 = ctx->r12 < ctx->r13 ? 1 : 0;
    // 0x80195A48: bne         $at, $zero, L_8019590C
    if (ctx->r1 != 0) {
        // 0x80195A4C: nop
    
            goto L_8019590C;
    }
    // 0x80195A4C: nop

L_80195A50:
    // 0x80195A50: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80195A54: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80195A58: jr          $ra
    // 0x80195A5C: nop

    return;
    // 0x80195A5C: nop

;}
RECOMP_FUNC void func_80195A60_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80195A60: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80195A64: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80195A68: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80195A6C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80195A70: addiu       $t6, $t6, 0x3988
    ctx->r14 = ADD32(ctx->r14, 0X3988);
    // 0x80195A74: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80195A78: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80195A7C: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x80195A80: lw          $a1, 0xC($t6)
    ctx->r5 = MEM_W(ctx->r14, 0XC);
    // 0x80195A84: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    // 0x80195A88: addiu       $a3, $zero, 0x18
    ctx->r7 = ADD32(0, 0X18);
    // 0x80195A8C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80195A90: jal         0x80195E20
    // 0x80195A94: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_80195E20_1501A0(rdram, ctx);
        goto after_0;
    // 0x80195A94: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x80195A98: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80195A9C: lw          $t7, -0x2E3C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2E3C);
    // 0x80195AA0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80195AA4: bne         $t7, $at, L_80195BEC
    if (ctx->r15 != ctx->r1) {
        // 0x80195AA8: nop
    
            goto L_80195BEC;
    }
    // 0x80195AA8: nop

    // 0x80195AAC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80195AB0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80195AB4: addiu       $t8, $t8, 0x39A0
    ctx->r24 = ADD32(ctx->r24, 0X39A0);
    // 0x80195AB8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80195ABC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80195AC0: lw          $a0, 0x1C($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X1C);
    // 0x80195AC4: lw          $a1, 0x3C($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X3C);
    // 0x80195AC8: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x80195ACC: addiu       $a3, $zero, 0x2C
    ctx->r7 = ADD32(0, 0X2C);
    // 0x80195AD0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x80195AD4: jal         0x80195EF4
    // 0x80195AD8: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    func_80195EF4_1501A0(rdram, ctx);
        goto after_1;
    // 0x80195AD8: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x80195ADC: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_80195AE0:
    // 0x80195AE0: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80195AE4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80195AE8: addiu       $t1, $t1, -0x2E18
    ctx->r9 = ADD32(ctx->r9, -0X2E18);
    // 0x80195AEC: lw          $t2, 0x18($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X18);
    // 0x80195AF0: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80195AF4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80195AF8: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80195AFC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80195B00: sll         $t0, $t0, 6
    ctx->r8 = S32(ctx->r8 << 6);
    // 0x80195B04: subu        $t3, $t0, $t2
    ctx->r11 = SUB32(ctx->r8, ctx->r10);
    // 0x80195B08: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x80195B0C: addiu       $a1, $t3, 0x64
    ctx->r5 = ADD32(ctx->r11, 0X64);
    // 0x80195B10: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    // 0x80195B14: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80195B18: addiu       $a0, $t9, 0x1
    ctx->r4 = ADD32(ctx->r25, 0X1);
    // 0x80195B1C: jal         0x8019530C
    // 0x80195B20: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_8019530C_1501A0(rdram, ctx);
        goto after_2;
    // 0x80195B20: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_2:
    // 0x80195B24: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80195B28: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80195B2C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80195B30: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80195B34: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80195B38: sll         $t5, $t4, 5
    ctx->r13 = S32(ctx->r12 << 5);
    // 0x80195B3C: addu        $a0, $a0, $t5
    ctx->r4 = ADD32(ctx->r4, ctx->r13);
    // 0x80195B40: lw          $a0, 0x39BC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X39BC);
    // 0x80195B44: addiu       $a2, $zero, 0x5C
    ctx->r6 = ADD32(0, 0X5C);
    // 0x80195B48: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80195B4C: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    // 0x80195B50: jal         0x80195378
    // 0x80195B54: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_80195378_1501A0(rdram, ctx);
        goto after_3;
    // 0x80195B54: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_3:
    // 0x80195B58: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80195B5C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80195B60: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80195B64: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x80195B68: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x80195B6C: lw          $a0, 0x39B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X39B0);
    // 0x80195B70: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80195B74: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80195B78: addiu       $a2, $zero, 0x74
    ctx->r6 = ADD32(0, 0X74);
    // 0x80195B7C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80195B80: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80195B84: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    // 0x80195B88: jal         0x80195448
    // 0x80195B8C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80195448_1501A0(rdram, ctx);
        goto after_4;
    // 0x80195B8C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_4:
    // 0x80195B90: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80195B94: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80195B98: addiu       $t0, $t0, 0x39A0
    ctx->r8 = ADD32(ctx->r8, 0X39A0);
    // 0x80195B9C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80195BA0: sll         $t1, $t8, 5
    ctx->r9 = S32(ctx->r24 << 5);
    // 0x80195BA4: addu        $t2, $t1, $t0
    ctx->r10 = ADD32(ctx->r9, ctx->r8);
    // 0x80195BA8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80195BAC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80195BB0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80195BB4: lw          $a0, 0x18($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X18);
    // 0x80195BB8: lw          $a1, 0x14($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X14);
    // 0x80195BBC: addiu       $a3, $zero, 0x88
    ctx->r7 = ADD32(0, 0X88);
    // 0x80195BC0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x80195BC4: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x80195BC8: jal         0x801954DC
    // 0x80195BCC: addiu       $a2, $a2, 0x60
    ctx->r6 = ADD32(ctx->r6, 0X60);
    func_801954DC_1501A0(rdram, ctx);
        goto after_5;
    // 0x80195BCC: addiu       $a2, $a2, 0x60
    ctx->r6 = ADD32(ctx->r6, 0X60);
    after_5:
    // 0x80195BD0: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80195BD4: addiu       $t3, $t9, 0x1
    ctx->r11 = ADD32(ctx->r25, 0X1);
    // 0x80195BD8: sltiu       $at, $t3, 0x2
    ctx->r1 = ctx->r11 < 0X2 ? 1 : 0;
    // 0x80195BDC: bne         $at, $zero, L_80195AE0
    if (ctx->r1 != 0) {
        // 0x80195BE0: sw          $t3, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r11;
            goto L_80195AE0;
    }
    // 0x80195BE0: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x80195BE4: b           L_80195E10
    // 0x80195BE8: nop

        goto L_80195E10;
    // 0x80195BE8: nop

L_80195BEC:
    // 0x80195BEC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80195BF0: addiu       $t4, $t4, 0x39A0
    ctx->r12 = ADD32(ctx->r12, 0X39A0);
    // 0x80195BF4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80195BF8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80195BFC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80195C00: lw          $t5, 0x5C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X5C);
    // 0x80195C04: lw          $t6, 0x1C($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X1C);
    // 0x80195C08: lw          $t7, 0x7C($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X7C);
    // 0x80195C0C: lw          $t8, 0x3C($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X3C);
    // 0x80195C10: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    // 0x80195C14: addiu       $a3, $zero, 0x2C
    ctx->r7 = ADD32(0, 0X2C);
    // 0x80195C18: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80195C1C: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x80195C20: addu        $a0, $t5, $t6
    ctx->r4 = ADD32(ctx->r13, ctx->r14);
    // 0x80195C24: jal         0x80195EF4
    // 0x80195C28: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    func_80195EF4_1501A0(rdram, ctx);
        goto after_6;
    // 0x80195C28: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_6:
    // 0x80195C2C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_80195C30:
    // 0x80195C30: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80195C34: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80195C38: addiu       $t2, $t2, -0x2E18
    ctx->r10 = ADD32(ctx->r10, -0X2E18);
    // 0x80195C3C: lw          $t9, 0x18($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X18);
    // 0x80195C40: sll         $t0, $t1, 2
    ctx->r8 = S32(ctx->r9 << 2);
    // 0x80195C44: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80195C48: addu        $t0, $t0, $t1
    ctx->r8 = ADD32(ctx->r8, ctx->r9);
    // 0x80195C4C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80195C50: sll         $t0, $t0, 6
    ctx->r8 = S32(ctx->r8 << 6);
    // 0x80195C54: subu        $t3, $t0, $t9
    ctx->r11 = SUB32(ctx->r8, ctx->r25);
    // 0x80195C58: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x80195C5C: addiu       $a1, $t3, 0x64
    ctx->r5 = ADD32(ctx->r11, 0X64);
    // 0x80195C60: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    // 0x80195C64: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80195C68: addiu       $a0, $t1, 0x1
    ctx->r4 = ADD32(ctx->r9, 0X1);
    // 0x80195C6C: jal         0x8019530C
    // 0x80195C70: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_8019530C_1501A0(rdram, ctx);
        goto after_7;
    // 0x80195C70: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_7:
    // 0x80195C74: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80195C78: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80195C7C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80195C80: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80195C84: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80195C88: sll         $t6, $t5, 5
    ctx->r14 = S32(ctx->r13 << 5);
    // 0x80195C8C: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x80195C90: lw          $a0, 0x39BC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X39BC);
    // 0x80195C94: addiu       $a2, $zero, 0x4E
    ctx->r6 = ADD32(0, 0X4E);
    // 0x80195C98: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80195C9C: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    // 0x80195CA0: jal         0x80195378
    // 0x80195CA4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80195378_1501A0(rdram, ctx);
        goto after_8;
    // 0x80195CA4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_8:
    // 0x80195CA8: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80195CAC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80195CB0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80195CB4: sll         $t7, $t4, 5
    ctx->r15 = S32(ctx->r12 << 5);
    // 0x80195CB8: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x80195CBC: lw          $a0, 0x39B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X39B0);
    // 0x80195CC0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80195CC4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80195CC8: addiu       $a2, $zero, 0x58
    ctx->r6 = ADD32(0, 0X58);
    // 0x80195CCC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80195CD0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80195CD4: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    // 0x80195CD8: jal         0x80195448
    // 0x80195CDC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_80195448_1501A0(rdram, ctx);
        goto after_9;
    // 0x80195CDC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_9:
    // 0x80195CE0: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80195CE4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80195CE8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80195CEC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80195CF0: addiu       $t0, $t0, 0x39A0
    ctx->r8 = ADD32(ctx->r8, 0X39A0);
    // 0x80195CF4: sll         $t2, $t8, 5
    ctx->r10 = S32(ctx->r24 << 5);
    // 0x80195CF8: addu        $t9, $t2, $t0
    ctx->r25 = ADD32(ctx->r10, ctx->r8);
    // 0x80195CFC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80195D00: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80195D04: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80195D08: lw          $a0, 0x18($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X18);
    // 0x80195D0C: lw          $a1, 0x14($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X14);
    // 0x80195D10: addiu       $a3, $zero, 0x62
    ctx->r7 = ADD32(0, 0X62);
    // 0x80195D14: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x80195D18: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x80195D1C: jal         0x801954DC
    // 0x80195D20: addiu       $a2, $a2, 0x60
    ctx->r6 = ADD32(ctx->r6, 0X60);
    func_801954DC_1501A0(rdram, ctx);
        goto after_10;
    // 0x80195D20: addiu       $a2, $a2, 0x60
    ctx->r6 = ADD32(ctx->r6, 0X60);
    after_10:
    // 0x80195D24: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80195D28: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80195D2C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80195D30: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80195D34: addiu       $a2, $zero, 0x70
    ctx->r6 = ADD32(0, 0X70);
    // 0x80195D38: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80195D3C: addiu       $a0, $a0, 0x3
    ctx->r4 = ADD32(ctx->r4, 0X3);
    // 0x80195D40: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x80195D44: jal         0x8019530C
    // 0x80195D48: addiu       $a1, $a1, 0x64
    ctx->r5 = ADD32(ctx->r5, 0X64);
    func_8019530C_1501A0(rdram, ctx);
        goto after_11;
    // 0x80195D48: addiu       $a1, $a1, 0x64
    ctx->r5 = ADD32(ctx->r5, 0X64);
    after_11:
    // 0x80195D4C: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80195D50: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80195D54: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80195D58: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80195D5C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80195D60: sll         $t3, $t1, 5
    ctx->r11 = S32(ctx->r9 << 5);
    // 0x80195D64: addu        $a0, $a0, $t3
    ctx->r4 = ADD32(ctx->r4, ctx->r11);
    // 0x80195D68: lw          $a0, 0x39FC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X39FC);
    // 0x80195D6C: addiu       $a2, $zero, 0x7A
    ctx->r6 = ADD32(0, 0X7A);
    // 0x80195D70: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80195D74: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    // 0x80195D78: jal         0x80195378
    // 0x80195D7C: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_80195378_1501A0(rdram, ctx);
        goto after_12;
    // 0x80195D7C: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_12:
    // 0x80195D80: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80195D84: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80195D88: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80195D8C: sll         $t6, $t5, 5
    ctx->r14 = S32(ctx->r13 << 5);
    // 0x80195D90: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x80195D94: lw          $a0, 0x39F0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X39F0);
    // 0x80195D98: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80195D9C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80195DA0: addiu       $a2, $zero, 0x84
    ctx->r6 = ADD32(0, 0X84);
    // 0x80195DA4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80195DA8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80195DAC: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    // 0x80195DB0: jal         0x80195448
    // 0x80195DB4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80195448_1501A0(rdram, ctx);
        goto after_13;
    // 0x80195DB4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_13:
    // 0x80195DB8: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80195DBC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80195DC0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80195DC4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80195DC8: addiu       $t8, $t8, 0x39A0
    ctx->r24 = ADD32(ctx->r24, 0X39A0);
    // 0x80195DCC: sll         $t7, $t4, 5
    ctx->r15 = S32(ctx->r12 << 5);
    // 0x80195DD0: addu        $t2, $t7, $t8
    ctx->r10 = ADD32(ctx->r15, ctx->r24);
    // 0x80195DD4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80195DD8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80195DDC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80195DE0: lw          $a0, 0x58($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X58);
    // 0x80195DE4: lw          $a1, 0x14($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X14);
    // 0x80195DE8: addiu       $a3, $zero, 0x8E
    ctx->r7 = ADD32(0, 0X8E);
    // 0x80195DEC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x80195DF0: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x80195DF4: jal         0x801954DC
    // 0x80195DF8: addiu       $a2, $a2, 0x60
    ctx->r6 = ADD32(ctx->r6, 0X60);
    func_801954DC_1501A0(rdram, ctx);
        goto after_14;
    // 0x80195DF8: addiu       $a2, $a2, 0x60
    ctx->r6 = ADD32(ctx->r6, 0X60);
    after_14:
    // 0x80195DFC: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80195E00: addiu       $t9, $t0, 0x1
    ctx->r25 = ADD32(ctx->r8, 0X1);
    // 0x80195E04: sltiu       $at, $t9, 0x2
    ctx->r1 = ctx->r25 < 0X2 ? 1 : 0;
    // 0x80195E08: bne         $at, $zero, L_80195C30
    if (ctx->r1 != 0) {
        // 0x80195E0C: sw          $t9, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r25;
            goto L_80195C30;
    }
    // 0x80195E0C: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
L_80195E10:
    // 0x80195E10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80195E14: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80195E18: jr          $ra
    // 0x80195E1C: nop

    return;
    // 0x80195E1C: nop

;}
RECOMP_FUNC void func_80195E20_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80195E20: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80195E24: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80195E28: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80195E2C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80195E30: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80195E34: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80195E38: bne         $t6, $zero, L_80195E5C
    if (ctx->r14 != 0) {
        // 0x80195E3C: sw          $a3, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r7;
            goto L_80195E5C;
    }
    // 0x80195E3C: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x80195E40: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80195E44: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80195E48: addiu       $a1, $a1, -0xB88
    ctx->r5 = ADD32(ctx->r5, -0XB88);
    // 0x80195E4C: jal         0x800D87E4
    // 0x80195E50: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_0;
    // 0x80195E50: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_0:
    // 0x80195E54: b           L_80195E74
    // 0x80195E58: nop

        goto L_80195E74;
    // 0x80195E58: nop

L_80195E5C:
    // 0x80195E5C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80195E60: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80195E64: addiu       $a1, $a1, -0xB74
    ctx->r5 = ADD32(ctx->r5, -0XB74);
    // 0x80195E68: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    // 0x80195E6C: jal         0x800D87E4
    // 0x80195E70: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    sprintf_recomp(rdram, ctx);
        goto after_1;
    // 0x80195E70: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    after_1:
L_80195E74:
    // 0x80195E74: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x80195E78: bne         $t7, $zero, L_80195E98
    if (ctx->r15 != 0) {
        // 0x80195E7C: nop
    
            goto L_80195E98;
    }
    // 0x80195E7C: nop

    // 0x80195E80: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80195E84: addiu       $a1, $a1, -0xB60
    ctx->r5 = ADD32(ctx->r5, -0XB60);
    // 0x80195E88: jal         0x800D87E4
    // 0x80195E8C: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    sprintf_recomp(rdram, ctx);
        goto after_2;
    // 0x80195E8C: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_2:
    // 0x80195E90: b           L_80195EAC
    // 0x80195E94: nop

        goto L_80195EAC;
    // 0x80195E94: nop

L_80195E98:
    // 0x80195E98: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80195E9C: addiu       $a1, $a1, -0xB50
    ctx->r5 = ADD32(ctx->r5, -0XB50);
    // 0x80195EA0: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80195EA4: jal         0x800D87E4
    // 0x80195EA8: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    sprintf_recomp(rdram, ctx);
        goto after_3;
    // 0x80195EA8: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    after_3:
L_80195EAC:
    // 0x80195EAC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80195EB0: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    // 0x80195EB4: jal         0x800E4F10
    // 0x80195EB8: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_800E4F10(rdram, ctx);
        goto after_4;
    // 0x80195EB8: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_4:
    // 0x80195EBC: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80195EC0: addiu       $t9, $zero, 0x8C
    ctx->r25 = ADD32(0, 0X8C);
    // 0x80195EC4: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80195EC8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80195ECC: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80195ED0: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x80195ED4: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x80195ED8: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    // 0x80195EDC: jal         0x80193DE8
    // 0x80195EE0: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    func_80193DE8_1501A0(rdram, ctx);
        goto after_5;
    // 0x80195EE0: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_5:
    // 0x80195EE4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80195EE8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80195EEC: jr          $ra
    // 0x80195EF0: nop

    return;
    // 0x80195EF0: nop

;}
RECOMP_FUNC void func_80195EF4_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80195EF4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80195EF8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80195EFC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80195F00: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80195F04: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80195F08: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80195F0C: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80195F10: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80195F14: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x80195F18: addiu       $t6, $t6, -0x2E18
    ctx->r14 = ADD32(ctx->r14, -0X2E18);
    // 0x80195F1C: lw          $t7, 0x64($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X64);
    // 0x80195F20: beq         $t7, $zero, L_80195F60
    if (ctx->r15 == 0) {
        // 0x80195F24: nop
    
            goto L_80195F60;
    }
    // 0x80195F24: nop

    // 0x80195F28: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80195F2C: beq         $t8, $zero, L_80195F60
    if (ctx->r24 == 0) {
        // 0x80195F30: nop
    
            goto L_80195F60;
    }
    // 0x80195F30: nop

    // 0x80195F34: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80195F38: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80195F3C: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80195F40: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80195F44: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80195F48: divu        $zero, $t9, $t7
    lo = S32(U32(ctx->r25) / U32(ctx->r15)); hi = S32(U32(ctx->r25) % U32(ctx->r15));
    // 0x80195F4C: mflo        $t0
    ctx->r8 = lo;
    // 0x80195F50: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x80195F54: bne         $t7, $zero, L_80195F60
    if (ctx->r15 != 0) {
        // 0x80195F58: nop
    
            goto L_80195F60;
    }
    // 0x80195F58: nop

    // 0x80195F5C: break       7
    do_break(2149146460);
L_80195F60:
    // 0x80195F60: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80195F64: addiu       $t1, $t1, -0x2E18
    ctx->r9 = ADD32(ctx->r9, -0X2E18);
    // 0x80195F68: lw          $t2, 0x64($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X64);
    // 0x80195F6C: beq         $t2, $zero, L_80195FAC
    if (ctx->r10 == 0) {
        // 0x80195F70: nop
    
            goto L_80195FAC;
    }
    // 0x80195F70: nop

    // 0x80195F74: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x80195F78: beq         $t3, $zero, L_80195FAC
    if (ctx->r11 == 0) {
        // 0x80195F7C: nop
    
            goto L_80195FAC;
    }
    // 0x80195F7C: nop

    // 0x80195F80: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80195F84: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x80195F88: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x80195F8C: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x80195F90: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80195F94: divu        $zero, $t4, $t2
    lo = S32(U32(ctx->r12) / U32(ctx->r10)); hi = S32(U32(ctx->r12) % U32(ctx->r10));
    // 0x80195F98: mflo        $t5
    ctx->r13 = lo;
    // 0x80195F9C: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
    // 0x80195FA0: bne         $t2, $zero, L_80195FAC
    if (ctx->r10 != 0) {
        // 0x80195FA4: nop
    
            goto L_80195FAC;
    }
    // 0x80195FA4: nop

    // 0x80195FA8: break       7
    do_break(2149146536);
L_80195FAC:
    // 0x80195FAC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80195FB0: addiu       $t6, $t6, -0x2E18
    ctx->r14 = ADD32(ctx->r14, -0X2E18);
    // 0x80195FB4: lw          $t8, 0x64($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X64);
    // 0x80195FB8: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80195FBC: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80195FC0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80195FC4: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80195FC8: addiu       $a1, $a1, -0xB44
    ctx->r5 = ADD32(ctx->r5, -0XB44);
    // 0x80195FCC: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    // 0x80195FD0: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80195FD4: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x80195FD8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80195FDC: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x80195FE0: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80195FE4: jal         0x800D87E4
    // 0x80195FE8: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    sprintf_recomp(rdram, ctx);
        goto after_0;
    // 0x80195FE8: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    after_0:
    // 0x80195FEC: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80195FF0: addiu       $t1, $zero, 0x8C
    ctx->r9 = ADD32(0, 0X8C);
    // 0x80195FF4: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80195FF8: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80195FFC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80196000: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80196004: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x80196008: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x8019600C: jal         0x80193DE8
    // 0x80196010: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    func_80193DE8_1501A0(rdram, ctx);
        goto after_1;
    // 0x80196010: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_1:
    // 0x80196014: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80196018: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8019601C: jr          $ra
    // 0x80196020: nop

    return;
    // 0x80196020: nop

;}
RECOMP_FUNC void func_80196024_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80196024: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80196028: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8019602C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80196030: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80196034: addiu       $a1, $a1, -0xB20
    ctx->r5 = ADD32(ctx->r5, -0XB20);
    // 0x80196038: jal         0x800D87E4
    // 0x8019603C: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_0;
    // 0x8019603C: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_0:
    // 0x80196040: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80196044: addiu       $t6, $t6, -0x2E18
    ctx->r14 = ADD32(ctx->r14, -0X2E18);
    // 0x80196048: lw          $t7, 0x1C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1C);
    // 0x8019604C: bne         $t7, $zero, L_80196088
    if (ctx->r15 != 0) {
        // 0x80196050: nop
    
            goto L_80196088;
    }
    // 0x80196050: nop

    // 0x80196054: addiu       $t8, $zero, 0xB4
    ctx->r24 = ADD32(0, 0XB4);
    // 0x80196058: addiu       $t9, $zero, 0xB4
    ctx->r25 = ADD32(0, 0XB4);
    // 0x8019605C: addiu       $t0, $zero, 0xB4
    ctx->r8 = ADD32(0, 0XB4);
    // 0x80196060: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x80196064: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80196068: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8019606C: addiu       $a0, $zero, 0x88
    ctx->r4 = ADD32(0, 0X88);
    // 0x80196070: addiu       $a1, $zero, 0x56
    ctx->r5 = ADD32(0, 0X56);
    // 0x80196074: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80196078: jal         0x80193DE8
    // 0x8019607C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_80193DE8_1501A0(rdram, ctx);
        goto after_1;
    // 0x8019607C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x80196080: b           L_801960B4
    // 0x80196084: nop

        goto L_801960B4;
    // 0x80196084: nop

L_80196088:
    // 0x80196088: addiu       $t1, $zero, 0x50
    ctx->r9 = ADD32(0, 0X50);
    // 0x8019608C: addiu       $t2, $zero, 0x50
    ctx->r10 = ADD32(0, 0X50);
    // 0x80196090: addiu       $t3, $zero, 0x50
    ctx->r11 = ADD32(0, 0X50);
    // 0x80196094: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x80196098: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8019609C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x801960A0: addiu       $a0, $zero, 0x88
    ctx->r4 = ADD32(0, 0X88);
    // 0x801960A4: addiu       $a1, $zero, 0x56
    ctx->r5 = ADD32(0, 0X56);
    // 0x801960A8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x801960AC: jal         0x80193DE8
    // 0x801960B0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_80193DE8_1501A0(rdram, ctx);
        goto after_2;
    // 0x801960B0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_2:
L_801960B4:
    // 0x801960B4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x801960B8: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x801960BC: addiu       $a1, $a1, -0xB18
    ctx->r5 = ADD32(ctx->r5, -0XB18);
    // 0x801960C0: jal         0x800D87E4
    // 0x801960C4: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_3;
    // 0x801960C4: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_3:
    // 0x801960C8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x801960CC: addiu       $t4, $t4, -0x2E18
    ctx->r12 = ADD32(ctx->r12, -0X2E18);
    // 0x801960D0: lw          $t5, 0x1C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X1C);
    // 0x801960D4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801960D8: bne         $t5, $at, L_80196114
    if (ctx->r13 != ctx->r1) {
        // 0x801960DC: nop
    
            goto L_80196114;
    }
    // 0x801960DC: nop

    // 0x801960E0: addiu       $t6, $zero, 0xB4
    ctx->r14 = ADD32(0, 0XB4);
    // 0x801960E4: addiu       $t7, $zero, 0xB4
    ctx->r15 = ADD32(0, 0XB4);
    // 0x801960E8: addiu       $t8, $zero, 0xB4
    ctx->r24 = ADD32(0, 0XB4);
    // 0x801960EC: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801960F0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801960F4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801960F8: addiu       $a0, $zero, 0x6C
    ctx->r4 = ADD32(0, 0X6C);
    // 0x801960FC: addiu       $a1, $zero, 0x70
    ctx->r5 = ADD32(0, 0X70);
    // 0x80196100: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80196104: jal         0x80193DE8
    // 0x80196108: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_80193DE8_1501A0(rdram, ctx);
        goto after_4;
    // 0x80196108: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_4:
    // 0x8019610C: b           L_80196140
    // 0x80196110: nop

        goto L_80196140;
    // 0x80196110: nop

L_80196114:
    // 0x80196114: addiu       $t9, $zero, 0x50
    ctx->r25 = ADD32(0, 0X50);
    // 0x80196118: addiu       $t0, $zero, 0x50
    ctx->r8 = ADD32(0, 0X50);
    // 0x8019611C: addiu       $t1, $zero, 0x50
    ctx->r9 = ADD32(0, 0X50);
    // 0x80196120: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x80196124: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80196128: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8019612C: addiu       $a0, $zero, 0x6C
    ctx->r4 = ADD32(0, 0X6C);
    // 0x80196130: addiu       $a1, $zero, 0x70
    ctx->r5 = ADD32(0, 0X70);
    // 0x80196134: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80196138: jal         0x80193DE8
    // 0x8019613C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_80193DE8_1501A0(rdram, ctx);
        goto after_5;
    // 0x8019613C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_5:
L_80196140:
    // 0x80196140: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80196144: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80196148: addiu       $a1, $a1, -0xB08
    ctx->r5 = ADD32(ctx->r5, -0XB08);
    // 0x8019614C: jal         0x800D87E4
    // 0x80196150: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_6;
    // 0x80196150: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_6:
    // 0x80196154: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80196158: addiu       $t2, $t2, -0x2E18
    ctx->r10 = ADD32(ctx->r10, -0X2E18);
    // 0x8019615C: lw          $t3, 0x1C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X1C);
    // 0x80196160: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80196164: bne         $t3, $at, L_801961A0
    if (ctx->r11 != ctx->r1) {
        // 0x80196168: nop
    
            goto L_801961A0;
    }
    // 0x80196168: nop

    // 0x8019616C: addiu       $t4, $zero, 0xB4
    ctx->r12 = ADD32(0, 0XB4);
    // 0x80196170: addiu       $t5, $zero, 0xB4
    ctx->r13 = ADD32(0, 0XB4);
    // 0x80196174: addiu       $t6, $zero, 0xB4
    ctx->r14 = ADD32(0, 0XB4);
    // 0x80196178: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x8019617C: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80196180: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80196184: addiu       $a0, $zero, 0x90
    ctx->r4 = ADD32(0, 0X90);
    // 0x80196188: addiu       $a1, $zero, 0x8A
    ctx->r5 = ADD32(0, 0X8A);
    // 0x8019618C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80196190: jal         0x80193DE8
    // 0x80196194: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_80193DE8_1501A0(rdram, ctx);
        goto after_7;
    // 0x80196194: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_7:
    // 0x80196198: b           L_801961CC
    // 0x8019619C: nop

        goto L_801961CC;
    // 0x8019619C: nop

L_801961A0:
    // 0x801961A0: addiu       $t7, $zero, 0x50
    ctx->r15 = ADD32(0, 0X50);
    // 0x801961A4: addiu       $t8, $zero, 0x50
    ctx->r24 = ADD32(0, 0X50);
    // 0x801961A8: addiu       $t9, $zero, 0x50
    ctx->r25 = ADD32(0, 0X50);
    // 0x801961AC: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x801961B0: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x801961B4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801961B8: addiu       $a0, $zero, 0x90
    ctx->r4 = ADD32(0, 0X90);
    // 0x801961BC: addiu       $a1, $zero, 0x8A
    ctx->r5 = ADD32(0, 0X8A);
    // 0x801961C0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x801961C4: jal         0x80193DE8
    // 0x801961C8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_80193DE8_1501A0(rdram, ctx);
        goto after_8;
    // 0x801961C8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_8:
L_801961CC:
    // 0x801961CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801961D0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801961D4: jr          $ra
    // 0x801961D8: nop

    return;
    // 0x801961D8: nop

;}
RECOMP_FUNC void func_801961DC_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801961DC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801961E0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801961E4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801961E8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801961EC: addiu       $t6, $t6, -0x2E18
    ctx->r14 = ADD32(ctx->r14, -0X2E18);
    // 0x801961F0: lw          $t7, 0x14($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14);
    // 0x801961F4: bne         $t7, $zero, L_801967FC
    if (ctx->r15 != 0) {
        // 0x801961F8: nop
    
            goto L_801967FC;
    }
    // 0x801961F8: nop

    // 0x801961FC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80196200: addiu       $t8, $t8, -0x2E28
    ctx->r24 = ADD32(ctx->r24, -0X2E28);
    // 0x80196204: lbu         $t9, 0xA($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0XA);
    // 0x80196208: andi        $t0, $t9, 0x3
    ctx->r8 = ctx->r25 & 0X3;
    // 0x8019620C: beq         $t0, $zero, L_801967FC
    if (ctx->r8 == 0) {
        // 0x80196210: nop
    
            goto L_801967FC;
    }
    // 0x80196210: nop

    // 0x80196214: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80196218: addiu       $t1, $t1, -0x2E28
    ctx->r9 = ADD32(ctx->r9, -0X2E28);
    // 0x8019621C: lbu         $t2, 0xA($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0XA);
    // 0x80196220: andi        $t3, $t2, 0x2
    ctx->r11 = ctx->r10 & 0X2;
    // 0x80196224: beq         $t3, $zero, L_80196240
    if (ctx->r11 == 0) {
        // 0x80196228: nop
    
            goto L_80196240;
    }
    // 0x80196228: nop

    // 0x8019622C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80196230: addiu       $t4, $t4, -0x2E18
    ctx->r12 = ADD32(ctx->r12, -0X2E18);
    // 0x80196234: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x80196238: bne         $t5, $zero, L_801967FC
    if (ctx->r13 != 0) {
        // 0x8019623C: nop
    
            goto L_801967FC;
    }
    // 0x8019623C: nop

L_80196240:
    // 0x80196240: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80196244: lw          $s0, -0x2E48($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X2E48);
    // 0x80196248: beq         $s0, $zero, L_80196268
    if (ctx->r16 == 0) {
        // 0x8019624C: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80196268;
    }
    // 0x8019624C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80196250: beq         $s0, $at, L_8019632C
    if (ctx->r16 == ctx->r1) {
        // 0x80196254: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8019632C;
    }
    // 0x80196254: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80196258: beq         $s0, $at, L_801964D8
    if (ctx->r16 == ctx->r1) {
        // 0x8019625C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_801964D8;
    }
    // 0x8019625C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80196260: bne         $s0, $at, L_801967FC
    if (ctx->r16 != ctx->r1) {
        // 0x80196264: nop
    
            goto L_801967FC;
    }
    // 0x80196264: nop

L_80196268:
    // 0x80196268: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8019626C: addiu       $t6, $t6, -0x2E28
    ctx->r14 = ADD32(ctx->r14, -0X2E28);
    // 0x80196270: lbu         $t7, 0xA($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0XA);
    // 0x80196274: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80196278: beq         $t8, $zero, L_801967FC
    if (ctx->r24 == 0) {
        // 0x8019627C: nop
    
            goto L_801967FC;
    }
    // 0x8019627C: nop

    // 0x80196280: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
L_80196284:
    // 0x80196284: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80196288: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8019628C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80196290: sll         $a1, $t9, 2
    ctx->r5 = S32(ctx->r25 << 2);
    // 0x80196294: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80196298: subu        $a1, $a1, $t9
    ctx->r5 = SUB32(ctx->r5, ctx->r25);
    // 0x8019629C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x801962A0: addu        $a0, $a0, $t0
    ctx->r4 = ADD32(ctx->r4, ctx->r8);
    // 0x801962A4: sll         $a1, $a1, 4
    ctx->r5 = S32(ctx->r5 << 4);
    // 0x801962A8: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x801962AC: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x801962B0: addiu       $a1, $a1, 0x30
    ctx->r5 = ADD32(ctx->r5, 0X30);
    // 0x801962B4: lw          $a0, -0xEE8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0XEE8);
    // 0x801962B8: addiu       $a2, $zero, 0xA0
    ctx->r6 = ADD32(0, 0XA0);
    // 0x801962BC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801962C0: jal         0x800C6C6C
    // 0x801962C4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_0;
    // 0x801962C4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x801962C8: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x801962CC: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x801962D0: sltiu       $at, $t3, 0x5
    ctx->r1 = ctx->r11 < 0X5 ? 1 : 0;
    // 0x801962D4: bne         $at, $zero, L_80196284
    if (ctx->r1 != 0) {
        // 0x801962D8: sw          $t3, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r11;
            goto L_80196284;
    }
    // 0x801962D8: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x801962DC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x801962E0: addiu       $t4, $t4, 0x39A0
    ctx->r12 = ADD32(ctx->r12, 0X39A0);
    // 0x801962E4: lw          $a1, 0x8($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X8);
    // 0x801962E8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801962EC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801962F0: sll         $t5, $a1, 2
    ctx->r13 = S32(ctx->r5 << 2);
    // 0x801962F4: subu        $t5, $t5, $a1
    ctx->r13 = SUB32(ctx->r13, ctx->r5);
    // 0x801962F8: sll         $t5, $t5, 4
    ctx->r13 = S32(ctx->r13 << 4);
    // 0x801962FC: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
    // 0x80196300: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80196304: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80196308: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8019630C: addiu       $a0, $a0, 0xED4
    ctx->r4 = ADD32(ctx->r4, 0XED4);
    // 0x80196310: addiu       $a1, $a1, 0x30
    ctx->r5 = ADD32(ctx->r5, 0X30);
    // 0x80196314: addiu       $a2, $zero, 0xA0
    ctx->r6 = ADD32(0, 0XA0);
    // 0x80196318: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8019631C: jal         0x800C6C6C
    // 0x80196320: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_1;
    // 0x80196320: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x80196324: b           L_801967FC
    // 0x80196328: nop

        goto L_801967FC;
    // 0x80196328: nop

L_8019632C:
    // 0x8019632C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80196330: addiu       $t7, $t7, -0x2E18
    ctx->r15 = ADD32(ctx->r15, -0X2E18);
    // 0x80196334: lw          $t8, 0x18($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X18);
    // 0x80196338: addiu       $at, $zero, 0x140
    ctx->r1 = ADD32(0, 0X140);
    // 0x8019633C: divu        $zero, $t8, $at
    lo = S32(U32(ctx->r24) / U32(ctx->r1)); hi = S32(U32(ctx->r24) % U32(ctx->r1));
    // 0x80196340: mfhi        $t0
    ctx->r8 = hi;
    // 0x80196344: bne         $t0, $zero, L_801963D0
    if (ctx->r8 != 0) {
        // 0x80196348: nop
    
            goto L_801963D0;
    }
    // 0x80196348: nop

    // 0x8019634C: beq         $t8, $zero, L_8019637C
    if (ctx->r24 == 0) {
        // 0x80196350: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8019637C;
    }
    // 0x80196350: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80196354: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80196358: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8019635C: addiu       $t9, $zero, 0xC8
    ctx->r25 = ADD32(0, 0XC8);
    // 0x80196360: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80196364: addiu       $a0, $a0, 0x143C
    ctx->r4 = ADD32(ctx->r4, 0X143C);
    // 0x80196368: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    // 0x8019636C: addiu       $a2, $zero, 0xC8
    ctx->r6 = ADD32(0, 0XC8);
    // 0x80196370: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80196374: jal         0x800C6C6C
    // 0x80196378: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_2;
    // 0x80196378: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_2:
L_8019637C:
    // 0x8019637C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80196380: addiu       $t1, $t1, -0x2E18
    ctx->r9 = ADD32(ctx->r9, -0X2E18);
    // 0x80196384: lw          $t2, 0x18($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X18);
    // 0x80196388: addiu       $at, $zero, 0x140
    ctx->r1 = ADD32(0, 0X140);
    // 0x8019638C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80196390: divu        $zero, $t2, $at
    lo = S32(U32(ctx->r10) / U32(ctx->r1)); hi = S32(U32(ctx->r10) % U32(ctx->r1));
    // 0x80196394: lw          $t5, -0x2E3C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2E3C);
    // 0x80196398: mflo        $t3
    ctx->r11 = lo;
    // 0x8019639C: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x801963A0: beq         $t4, $t5, L_801963D0
    if (ctx->r12 == ctx->r13) {
        // 0x801963A4: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_801963D0;
    }
    // 0x801963A4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801963A8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801963AC: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x801963B0: addiu       $t6, $zero, 0xC8
    ctx->r14 = ADD32(0, 0XC8);
    // 0x801963B4: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x801963B8: addiu       $a0, $a0, 0x14B0
    ctx->r4 = ADD32(ctx->r4, 0X14B0);
    // 0x801963BC: addiu       $a1, $zero, 0x115
    ctx->r5 = ADD32(0, 0X115);
    // 0x801963C0: addiu       $a2, $zero, 0xC8
    ctx->r6 = ADD32(0, 0XC8);
    // 0x801963C4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801963C8: jal         0x800C6C6C
    // 0x801963CC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_3;
    // 0x801963CC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_3:
L_801963D0:
    // 0x801963D0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801963D4: addiu       $t7, $t7, -0x2E28
    ctx->r15 = ADD32(ctx->r15, -0X2E28);
    // 0x801963D8: lbu         $t0, 0xA($t7)
    ctx->r8 = MEM_BU(ctx->r15, 0XA);
    // 0x801963DC: andi        $t8, $t0, 0x1
    ctx->r24 = ctx->r8 & 0X1;
    // 0x801963E0: beq         $t8, $zero, L_801967FC
    if (ctx->r24 == 0) {
        // 0x801963E4: nop
    
            goto L_801967FC;
    }
    // 0x801963E4: nop

    // 0x801963E8: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
L_801963EC:
    // 0x801963EC: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x801963F0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801963F4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801963F8: sll         $a1, $t9, 2
    ctx->r5 = S32(ctx->r25 << 2);
    // 0x801963FC: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80196400: subu        $a1, $a1, $t9
    ctx->r5 = SUB32(ctx->r5, ctx->r25);
    // 0x80196404: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x80196408: addu        $a0, $a0, $t1
    ctx->r4 = ADD32(ctx->r4, ctx->r9);
    // 0x8019640C: sll         $a1, $a1, 4
    ctx->r5 = S32(ctx->r5 << 4);
    // 0x80196410: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80196414: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80196418: addiu       $a1, $a1, 0x30
    ctx->r5 = ADD32(ctx->r5, 0X30);
    // 0x8019641C: lw          $a0, -0xEE8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0XEE8);
    // 0x80196420: addiu       $a2, $zero, 0xA0
    ctx->r6 = ADD32(0, 0XA0);
    // 0x80196424: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80196428: jal         0x800C6C6C
    // 0x8019642C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_4;
    // 0x8019642C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_4:
    // 0x80196430: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x80196434: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80196438: sltiu       $at, $t4, 0x5
    ctx->r1 = ctx->r12 < 0X5 ? 1 : 0;
    // 0x8019643C: bne         $at, $zero, L_801963EC
    if (ctx->r1 != 0) {
        // 0x80196440: sw          $t4, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r12;
            goto L_801963EC;
    }
    // 0x80196440: sw          $t4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r12;
    // 0x80196444: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80196448: lw          $t5, -0x2E3C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2E3C);
    // 0x8019644C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80196450: beq         $t5, $zero, L_801967FC
    if (ctx->r13 == 0) {
        // 0x80196454: nop
    
            goto L_801967FC;
    }
    // 0x80196454: nop

L_80196458:
    // 0x80196458: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8019645C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80196460: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80196464: sll         $t0, $t6, 5
    ctx->r8 = S32(ctx->r14 << 5);
    // 0x80196468: addu        $a1, $a1, $t0
    ctx->r5 = ADD32(ctx->r5, ctx->r8);
    // 0x8019646C: lw          $a1, 0x39A8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X39A8);
    // 0x80196470: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80196474: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80196478: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x8019647C: subu        $t8, $t8, $a1
    ctx->r24 = SUB32(ctx->r24, ctx->r5);
    // 0x80196480: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x80196484: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80196488: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x8019648C: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x80196490: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80196494: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80196498: addiu       $a1, $a1, 0x30
    ctx->r5 = ADD32(ctx->r5, 0X30);
    // 0x8019649C: lw          $a0, -0xEF8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0XEF8);
    // 0x801964A0: addiu       $a2, $zero, 0xA0
    ctx->r6 = ADD32(0, 0XA0);
    // 0x801964A4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801964A8: jal         0x800C6C6C
    // 0x801964AC: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_5;
    // 0x801964AC: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_5:
    // 0x801964B0: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x801964B4: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x801964B8: lw          $t3, -0x2E3C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2E3C);
    // 0x801964BC: addiu       $t2, $t9, 0x1
    ctx->r10 = ADD32(ctx->r25, 0X1);
    // 0x801964C0: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x801964C4: sltu        $at, $t2, $t3
    ctx->r1 = ctx->r10 < ctx->r11 ? 1 : 0;
    // 0x801964C8: bne         $at, $zero, L_80196458
    if (ctx->r1 != 0) {
        // 0x801964CC: nop
    
            goto L_80196458;
    }
    // 0x801964CC: nop

    // 0x801964D0: b           L_801967FC
    // 0x801964D4: nop

        goto L_801967FC;
    // 0x801964D4: nop

L_801964D8:
    // 0x801964D8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x801964DC: addiu       $t4, $t4, -0x2E18
    ctx->r12 = ADD32(ctx->r12, -0X2E18);
    // 0x801964E0: lw          $t5, 0x18($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X18);
    // 0x801964E4: addiu       $at, $zero, 0x140
    ctx->r1 = ADD32(0, 0X140);
    // 0x801964E8: divu        $zero, $t5, $at
    lo = S32(U32(ctx->r13) / U32(ctx->r1)); hi = S32(U32(ctx->r13) % U32(ctx->r1));
    // 0x801964EC: mfhi        $t7
    ctx->r15 = hi;
    // 0x801964F0: bne         $t7, $zero, L_8019655C
    if (ctx->r15 != 0) {
        // 0x801964F4: nop
    
            goto L_8019655C;
    }
    // 0x801964F4: nop

    // 0x801964F8: beq         $t5, $zero, L_80196530
    if (ctx->r13 == 0) {
        // 0x801964FC: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80196530;
    }
    // 0x801964FC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80196500: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80196504: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80196508: addiu       $t6, $zero, 0xC8
    ctx->r14 = ADD32(0, 0XC8);
    // 0x8019650C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80196510: addiu       $a0, $a0, 0x143C
    ctx->r4 = ADD32(ctx->r4, 0X143C);
    // 0x80196514: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    // 0x80196518: addiu       $a2, $zero, 0xC8
    ctx->r6 = ADD32(0, 0XC8);
    // 0x8019651C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80196520: jal         0x800C6C6C
    // 0x80196524: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_6;
    // 0x80196524: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_6:
    // 0x80196528: b           L_8019655C
    // 0x8019652C: nop

        goto L_8019655C;
    // 0x8019652C: nop

L_80196530:
    // 0x80196530: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80196534: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80196538: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8019653C: addiu       $t0, $zero, 0xC8
    ctx->r8 = ADD32(0, 0XC8);
    // 0x80196540: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80196544: addiu       $a0, $a0, 0x14B0
    ctx->r4 = ADD32(ctx->r4, 0X14B0);
    // 0x80196548: addiu       $a1, $zero, 0x115
    ctx->r5 = ADD32(0, 0X115);
    // 0x8019654C: addiu       $a2, $zero, 0xC8
    ctx->r6 = ADD32(0, 0XC8);
    // 0x80196550: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80196554: jal         0x800C6C6C
    // 0x80196558: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_7;
    // 0x80196558: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_7:
L_8019655C:
    // 0x8019655C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80196560: addiu       $t8, $t8, -0x2E28
    ctx->r24 = ADD32(ctx->r24, -0X2E28);
    // 0x80196564: lbu         $t1, 0xA($t8)
    ctx->r9 = MEM_BU(ctx->r24, 0XA);
    // 0x80196568: andi        $t9, $t1, 0x1
    ctx->r25 = ctx->r9 & 0X1;
    // 0x8019656C: beq         $t9, $zero, L_801967FC
    if (ctx->r25 == 0) {
        // 0x80196570: nop
    
            goto L_801967FC;
    }
    // 0x80196570: nop

    // 0x80196574: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
L_80196578:
    // 0x80196578: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8019657C: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80196580: addiu       $t2, $t2, -0x2E18
    ctx->r10 = ADD32(ctx->r10, -0X2E18);
    // 0x80196584: lw          $t3, 0x48($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X48);
    // 0x80196588: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8019658C: sllv        $t5, $t7, $t4
    ctx->r13 = S32(ctx->r15 << (ctx->r12 & 31));
    // 0x80196590: and         $t6, $t3, $t5
    ctx->r14 = ctx->r11 & ctx->r13;
    // 0x80196594: beq         $t6, $zero, L_801965B0
    if (ctx->r14 == 0) {
        // 0x80196598: nop
    
            goto L_801965B0;
    }
    // 0x80196598: nop

    // 0x8019659C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x801965A0: addiu       $t8, $t8, 0x3B00
    ctx->r24 = ADD32(ctx->r24, 0X3B00);
    // 0x801965A4: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x801965A8: b           L_801965C0
    // 0x801965AC: sb          $t0, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r8;
        goto L_801965C0;
    // 0x801965AC: sb          $t0, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r8;
L_801965B0:
    // 0x801965B0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801965B4: addiu       $t9, $t9, 0x3B00
    ctx->r25 = ADD32(ctx->r25, 0X3B00);
    // 0x801965B8: addiu       $t1, $zero, 0x40
    ctx->r9 = ADD32(0, 0X40);
    // 0x801965BC: sb          $t1, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r9;
L_801965C0:
    // 0x801965C0: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x801965C4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x801965C8: addiu       $t4, $t4, -0x2E18
    ctx->r12 = ADD32(ctx->r12, -0X2E18);
    // 0x801965CC: lw          $t3, 0x18($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X18);
    // 0x801965D0: sll         $t7, $t2, 2
    ctx->r15 = S32(ctx->r10 << 2);
    // 0x801965D4: subu        $t7, $t7, $t2
    ctx->r15 = SUB32(ctx->r15, ctx->r10);
    // 0x801965D8: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x801965DC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x801965E0: subu        $t5, $t7, $t3
    ctx->r13 = SUB32(ctx->r15, ctx->r11);
    // 0x801965E4: addiu       $t6, $t5, 0x30
    ctx->r14 = ADD32(ctx->r13, 0X30);
    // 0x801965E8: addiu       $t0, $t0, 0x3D00
    ctx->r8 = ADD32(ctx->r8, 0X3D00);
    // 0x801965EC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801965F0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801965F4: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x801965F8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801965FC: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80196600: addiu       $t9, $t9, 0x3D00
    ctx->r25 = ADD32(ctx->r25, 0X3D00);
    // 0x80196604: lw          $a1, 0x0($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X0);
    // 0x80196608: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8019660C: addiu       $t2, $t2, 0x3B00
    ctx->r10 = ADD32(ctx->r10, 0X3B00);
    // 0x80196610: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x80196614: lbu         $t4, 0x0($t2)
    ctx->r12 = MEM_BU(ctx->r10, 0X0);
    // 0x80196618: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8019661C: sll         $t1, $t8, 2
    ctx->r9 = S32(ctx->r24 << 2);
    // 0x80196620: addu        $a0, $a0, $t1
    ctx->r4 = ADD32(ctx->r4, ctx->r9);
    // 0x80196624: lw          $a0, -0xEE8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0XEE8);
    // 0x80196628: addiu       $a2, $zero, 0xA0
    ctx->r6 = ADD32(0, 0XA0);
    // 0x8019662C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80196630: jal         0x800C6C6C
    // 0x80196634: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    func_800C6C6C(rdram, ctx);
        goto after_8;
    // 0x80196634: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    after_8:
    // 0x80196638: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8019663C: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x80196640: addiu       $t7, $t7, -0x2E18
    ctx->r15 = ADD32(ctx->r15, -0X2E18);
    // 0x80196644: lw          $t3, 0x4C($t7)
    ctx->r11 = MEM_W(ctx->r15, 0X4C);
    // 0x80196648: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8019664C: sllv        $t0, $t6, $t5
    ctx->r8 = S32(ctx->r14 << (ctx->r13 & 31));
    // 0x80196650: and         $t8, $t3, $t0
    ctx->r24 = ctx->r11 & ctx->r8;
    // 0x80196654: beq         $t8, $zero, L_80196670
    if (ctx->r24 == 0) {
        // 0x80196658: nop
    
            goto L_80196670;
    }
    // 0x80196658: nop

    // 0x8019665C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80196660: addiu       $t9, $t9, 0x3B00
    ctx->r25 = ADD32(ctx->r25, 0X3B00);
    // 0x80196664: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80196668: b           L_80196680
    // 0x8019666C: sb          $t1, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r9;
        goto L_80196680;
    // 0x8019666C: sb          $t1, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r9;
L_80196670:
    // 0x80196670: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80196674: addiu       $t4, $t4, 0x3B00
    ctx->r12 = ADD32(ctx->r12, 0X3B00);
    // 0x80196678: addiu       $t2, $zero, 0x40
    ctx->r10 = ADD32(0, 0X40);
    // 0x8019667C: sb          $t2, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r10;
L_80196680:
    // 0x80196680: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80196684: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80196688: addiu       $t5, $t5, -0x2E18
    ctx->r13 = ADD32(ctx->r13, -0X2E18);
    // 0x8019668C: lw          $t3, 0x18($t5)
    ctx->r11 = MEM_W(ctx->r13, 0X18);
    // 0x80196690: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x80196694: subu        $t6, $t6, $t7
    ctx->r14 = SUB32(ctx->r14, ctx->r15);
    // 0x80196698: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x8019669C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x801966A0: subu        $t0, $t6, $t3
    ctx->r8 = SUB32(ctx->r14, ctx->r11);
    // 0x801966A4: addiu       $t8, $t0, 0x170
    ctx->r24 = ADD32(ctx->r8, 0X170);
    // 0x801966A8: addiu       $t1, $t1, 0x3D00
    ctx->r9 = ADD32(ctx->r9, 0X3D00);
    // 0x801966AC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801966B0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801966B4: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x801966B8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x801966BC: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x801966C0: addiu       $t4, $t4, 0x3D00
    ctx->r12 = ADD32(ctx->r12, 0X3D00);
    // 0x801966C4: lw          $a1, 0x0($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X0);
    // 0x801966C8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801966CC: addiu       $t7, $t7, 0x3B00
    ctx->r15 = ADD32(ctx->r15, 0X3B00);
    // 0x801966D0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x801966D4: lbu         $t5, 0x0($t7)
    ctx->r13 = MEM_BU(ctx->r15, 0X0);
    // 0x801966D8: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x801966DC: sll         $t2, $t9, 2
    ctx->r10 = S32(ctx->r25 << 2);
    // 0x801966E0: addu        $a0, $a0, $t2
    ctx->r4 = ADD32(ctx->r4, ctx->r10);
    // 0x801966E4: lw          $a0, -0xED4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0XED4);
    // 0x801966E8: addiu       $a2, $zero, 0xA0
    ctx->r6 = ADD32(0, 0XA0);
    // 0x801966EC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801966F0: jal         0x800C6C6C
    // 0x801966F4: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    func_800C6C6C(rdram, ctx);
        goto after_9;
    // 0x801966F4: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    after_9:
    // 0x801966F8: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x801966FC: addiu       $t3, $t6, 0x1
    ctx->r11 = ADD32(ctx->r14, 0X1);
    // 0x80196700: sltiu       $at, $t3, 0x5
    ctx->r1 = ctx->r11 < 0X5 ? 1 : 0;
    // 0x80196704: bne         $at, $zero, L_80196578
    if (ctx->r1 != 0) {
        // 0x80196708: sw          $t3, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r11;
            goto L_80196578;
    }
    // 0x80196708: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x8019670C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80196710: addiu       $t0, $t0, 0x39A0
    ctx->r8 = ADD32(ctx->r8, 0X39A0);
    // 0x80196714: lw          $t8, 0x8($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X8);
    // 0x80196718: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8019671C: beq         $t8, $at, L_80196784
    if (ctx->r24 == ctx->r1) {
        // 0x80196720: nop
    
            goto L_80196784;
    }
    // 0x80196720: nop

    // 0x80196724: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80196728: addiu       $t9, $t9, -0x2E18
    ctx->r25 = ADD32(ctx->r25, -0X2E18);
    // 0x8019672C: lw          $t2, 0x18($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X18);
    // 0x80196730: sll         $t1, $t8, 2
    ctx->r9 = S32(ctx->r24 << 2);
    // 0x80196734: subu        $t1, $t1, $t8
    ctx->r9 = SUB32(ctx->r9, ctx->r24);
    // 0x80196738: sll         $t1, $t1, 4
    ctx->r9 = S32(ctx->r9 << 4);
    // 0x8019673C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80196740: subu        $t4, $t1, $t2
    ctx->r12 = SUB32(ctx->r9, ctx->r10);
    // 0x80196744: addiu       $t7, $t4, 0x30
    ctx->r15 = ADD32(ctx->r12, 0X30);
    // 0x80196748: addiu       $t5, $t5, 0x3D00
    ctx->r13 = ADD32(ctx->r13, 0X3D00);
    // 0x8019674C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80196750: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80196754: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80196758: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x8019675C: addiu       $t6, $t6, 0x3D00
    ctx->r14 = ADD32(ctx->r14, 0X3D00);
    // 0x80196760: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    // 0x80196764: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80196768: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x8019676C: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80196770: addiu       $a0, $a0, 0xED4
    ctx->r4 = ADD32(ctx->r4, 0XED4);
    // 0x80196774: addiu       $a2, $zero, 0xA0
    ctx->r6 = ADD32(0, 0XA0);
    // 0x80196778: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8019677C: jal         0x800C6C6C
    // 0x80196780: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_10;
    // 0x80196780: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_10:
L_80196784:
    // 0x80196784: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80196788: addiu       $t0, $t0, 0x39A0
    ctx->r8 = ADD32(ctx->r8, 0X39A0);
    // 0x8019678C: lw          $t8, 0x28($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X28);
    // 0x80196790: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80196794: beq         $t8, $at, L_801967FC
    if (ctx->r24 == ctx->r1) {
        // 0x80196798: nop
    
            goto L_801967FC;
    }
    // 0x80196798: nop

    // 0x8019679C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x801967A0: addiu       $t1, $t1, -0x2E18
    ctx->r9 = ADD32(ctx->r9, -0X2E18);
    // 0x801967A4: lw          $t2, 0x18($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X18);
    // 0x801967A8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x801967AC: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x801967B0: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x801967B4: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x801967B8: subu        $t4, $t9, $t2
    ctx->r12 = SUB32(ctx->r25, ctx->r10);
    // 0x801967BC: addiu       $t7, $t4, 0x170
    ctx->r15 = ADD32(ctx->r12, 0X170);
    // 0x801967C0: addiu       $t5, $t5, 0x3D00
    ctx->r13 = ADD32(ctx->r13, 0X3D00);
    // 0x801967C4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801967C8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801967CC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801967D0: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x801967D4: addiu       $t6, $t6, 0x3D00
    ctx->r14 = ADD32(ctx->r14, 0X3D00);
    // 0x801967D8: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    // 0x801967DC: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x801967E0: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x801967E4: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x801967E8: addiu       $a0, $a0, 0xF48
    ctx->r4 = ADD32(ctx->r4, 0XF48);
    // 0x801967EC: addiu       $a2, $zero, 0xA0
    ctx->r6 = ADD32(0, 0XA0);
    // 0x801967F0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801967F4: jal         0x800C6C6C
    // 0x801967F8: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_11;
    // 0x801967F8: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_11:
L_801967FC:
    // 0x801967FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80196800: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80196804: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80196808: jr          $ra
    // 0x8019680C: nop

    return;
    // 0x8019680C: nop

;}
RECOMP_FUNC void func_80196810_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80196810: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80196814: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80196818: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8019681C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80196820: addiu       $t6, $t6, -0x2E18
    ctx->r14 = ADD32(ctx->r14, -0X2E18);
    // 0x80196824: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x80196828: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8019682C: lw          $s0, -0x2E48($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X2E48);
    // 0x80196830: srl         $t8, $t7, 16
    ctx->r24 = S32(U32(ctx->r15) >> 16);
    // 0x80196834: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    // 0x80196838: beq         $s0, $zero, L_80196858
    if (ctx->r16 == 0) {
        // 0x8019683C: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80196858;
    }
    // 0x8019683C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80196840: beq         $s0, $at, L_80196920
    if (ctx->r16 == ctx->r1) {
        // 0x80196844: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80196920;
    }
    // 0x80196844: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80196848: beq         $s0, $at, L_80196A10
    if (ctx->r16 == ctx->r1) {
        // 0x8019684C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80196A10;
    }
    // 0x8019684C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80196850: bne         $s0, $at, L_801970BC
    if (ctx->r16 != ctx->r1) {
        // 0x80196854: nop
    
            goto L_801970BC;
    }
    // 0x80196854: nop

L_80196858:
    // 0x80196858: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8019685C: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x80196860: addiu       $t9, $t9, -0x2E18
    ctx->r25 = ADD32(ctx->r25, -0X2E18);
    // 0x80196864: lw          $s0, 0x8($t9)
    ctx->r16 = MEM_W(ctx->r25, 0X8);
    // 0x80196868: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8019686C: andi        $t0, $s0, 0xFFFF
    ctx->r8 = ctx->r16 & 0XFFFF;
    // 0x80196870: or          $s0, $t0, $zero
    ctx->r16 = ctx->r8 | 0;
    // 0x80196874: beq         $s0, $at, L_80196894
    if (ctx->r16 == ctx->r1) {
        // 0x80196878: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80196894;
    }
    // 0x80196878: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8019687C: beq         $s0, $at, L_801968B0
    if (ctx->r16 == ctx->r1) {
        // 0x80196880: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_801968B0;
    }
    // 0x80196880: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80196884: beq         $s0, $at, L_80196904
    if (ctx->r16 == ctx->r1) {
        // 0x80196888: nop
    
            goto L_80196904;
    }
    // 0x80196888: nop

    // 0x8019688C: b           L_801970BC
    // 0x80196890: nop

        goto L_801970BC;
    // 0x80196890: nop

L_80196894:
    // 0x80196894: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80196898: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x8019689C: addiu       $a1, $a1, -0xB00
    ctx->r5 = ADD32(ctx->r5, -0XB00);
    // 0x801968A0: jal         0x800D87E4
    // 0x801968A4: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_0;
    // 0x801968A4: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_0:
    // 0x801968A8: b           L_801970BC
    // 0x801968AC: nop

        goto L_801970BC;
    // 0x801968AC: nop

L_801968B0:
    // 0x801968B0: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x801968B4: addiu       $t1, $t1, 0x39A0
    ctx->r9 = ADD32(ctx->r9, 0X39A0);
    // 0x801968B8: lw          $t2, 0x10($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X10);
    // 0x801968BC: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x801968C0: beq         $t2, $at, L_801968E8
    if (ctx->r10 == ctx->r1) {
        // 0x801968C4: nop
    
            goto L_801968E8;
    }
    // 0x801968C4: nop

    // 0x801968C8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x801968CC: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x801968D0: addiu       $a1, $a1, -0xAEC
    ctx->r5 = ADD32(ctx->r5, -0XAEC);
    // 0x801968D4: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    // 0x801968D8: jal         0x800D87E4
    // 0x801968DC: addiu       $a2, $t2, 0x1
    ctx->r6 = ADD32(ctx->r10, 0X1);
    sprintf_recomp(rdram, ctx);
        goto after_1;
    // 0x801968DC: addiu       $a2, $t2, 0x1
    ctx->r6 = ADD32(ctx->r10, 0X1);
    after_1:
    // 0x801968E0: b           L_801970BC
    // 0x801968E4: nop

        goto L_801970BC;
    // 0x801968E4: nop

L_801968E8:
    // 0x801968E8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x801968EC: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x801968F0: addiu       $a1, $a1, -0xACC
    ctx->r5 = ADD32(ctx->r5, -0XACC);
    // 0x801968F4: jal         0x800D87E4
    // 0x801968F8: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_2;
    // 0x801968F8: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_2:
    // 0x801968FC: b           L_801970BC
    // 0x80196900: nop

        goto L_801970BC;
    // 0x80196900: nop

L_80196904:
    // 0x80196904: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80196908: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x8019690C: addiu       $a1, $a1, -0xAA8
    ctx->r5 = ADD32(ctx->r5, -0XAA8);
    // 0x80196910: jal         0x800D87E4
    // 0x80196914: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_3;
    // 0x80196914: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_3:
    // 0x80196918: b           L_801970BC
    // 0x8019691C: nop

        goto L_801970BC;
    // 0x8019691C: nop

L_80196920:
    // 0x80196920: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x80196924: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x80196928: bne         $t3, $at, L_80196938
    if (ctx->r11 != ctx->r1) {
        // 0x8019692C: sw          $t3, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r11;
            goto L_80196938;
    }
    // 0x8019692C: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x80196930: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80196934: sw          $t4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r12;
L_80196938:
    // 0x80196938: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8019693C: addiu       $t5, $t5, -0x2E18
    ctx->r13 = ADD32(ctx->r13, -0X2E18);
    // 0x80196940: lw          $s0, 0x8($t5)
    ctx->r16 = MEM_W(ctx->r13, 0X8);
    // 0x80196944: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80196948: andi        $t6, $s0, 0xFFFF
    ctx->r14 = ctx->r16 & 0XFFFF;
    // 0x8019694C: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    // 0x80196950: beq         $s0, $at, L_80196970
    if (ctx->r16 == ctx->r1) {
        // 0x80196954: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80196970;
    }
    // 0x80196954: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80196958: beq         $s0, $at, L_8019698C
    if (ctx->r16 == ctx->r1) {
        // 0x8019695C: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8019698C;
    }
    // 0x8019695C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80196960: beq         $s0, $at, L_801969F4
    if (ctx->r16 == ctx->r1) {
        // 0x80196964: nop
    
            goto L_801969F4;
    }
    // 0x80196964: nop

    // 0x80196968: b           L_801970BC
    // 0x8019696C: nop

        goto L_801970BC;
    // 0x8019696C: nop

L_80196970:
    // 0x80196970: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80196974: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80196978: addiu       $a1, $a1, -0xA88
    ctx->r5 = ADD32(ctx->r5, -0XA88);
    // 0x8019697C: jal         0x800D87E4
    // 0x80196980: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_4;
    // 0x80196980: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_4:
    // 0x80196984: b           L_801970BC
    // 0x80196988: nop

        goto L_801970BC;
    // 0x80196988: nop

L_8019698C:
    // 0x8019698C: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80196990: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80196994: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80196998: sll         $t8, $t7, 5
    ctx->r24 = S32(ctx->r15 << 5);
    // 0x8019699C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x801969A0: lw          $t9, 0x39B0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X39B0);
    // 0x801969A4: beq         $t9, $at, L_801969D0
    if (ctx->r25 == ctx->r1) {
        // 0x801969A8: nop
    
            goto L_801969D0;
    }
    // 0x801969A8: nop

    // 0x801969AC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x801969B0: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x801969B4: addiu       $a1, $a1, -0xA74
    ctx->r5 = ADD32(ctx->r5, -0XA74);
    // 0x801969B8: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    // 0x801969BC: addiu       $a2, $t7, 0x1
    ctx->r6 = ADD32(ctx->r15, 0X1);
    // 0x801969C0: jal         0x800D87E4
    // 0x801969C4: addiu       $a3, $t9, 0x1
    ctx->r7 = ADD32(ctx->r25, 0X1);
    sprintf_recomp(rdram, ctx);
        goto after_5;
    // 0x801969C4: addiu       $a3, $t9, 0x1
    ctx->r7 = ADD32(ctx->r25, 0X1);
    after_5:
    // 0x801969C8: b           L_801970BC
    // 0x801969CC: nop

        goto L_801970BC;
    // 0x801969CC: nop

L_801969D0:
    // 0x801969D0: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x801969D4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x801969D8: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x801969DC: addiu       $a1, $a1, -0xA50
    ctx->r5 = ADD32(ctx->r5, -0XA50);
    // 0x801969E0: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    // 0x801969E4: jal         0x800D87E4
    // 0x801969E8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    sprintf_recomp(rdram, ctx);
        goto after_6;
    // 0x801969E8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    after_6:
    // 0x801969EC: b           L_801970BC
    // 0x801969F0: nop

        goto L_801970BC;
    // 0x801969F0: nop

L_801969F4:
    // 0x801969F4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x801969F8: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x801969FC: addiu       $a1, $a1, -0xA28
    ctx->r5 = ADD32(ctx->r5, -0XA28);
    // 0x80196A00: jal         0x800D87E4
    // 0x80196A04: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_7;
    // 0x80196A04: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_7:
    // 0x80196A08: b           L_801970BC
    // 0x80196A0C: nop

        goto L_801970BC;
    // 0x80196A0C: nop

L_80196A10:
    // 0x80196A10: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80196A14: addiu       $at, $zero, 0x65
    ctx->r1 = ADD32(0, 0X65);
    // 0x80196A18: bne         $t0, $at, L_80196A24
    if (ctx->r8 != ctx->r1) {
        // 0x80196A1C: sw          $t0, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r8;
            goto L_80196A24;
    }
    // 0x80196A1C: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    // 0x80196A20: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
L_80196A24:
    // 0x80196A24: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80196A28: addiu       $at, $zero, 0x66
    ctx->r1 = ADD32(0, 0X66);
    // 0x80196A2C: bne         $t1, $at, L_80196A3C
    if (ctx->r9 != ctx->r1) {
        // 0x80196A30: nop
    
            goto L_80196A3C;
    }
    // 0x80196A30: nop

    // 0x80196A34: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80196A38: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
L_80196A3C:
    // 0x80196A3C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80196A40: addiu       $t3, $t3, -0x2E18
    ctx->r11 = ADD32(ctx->r11, -0X2E18);
    // 0x80196A44: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x80196A48: andi        $t5, $t4, 0xFFFF
    ctx->r13 = ctx->r12 & 0XFFFF;
    // 0x80196A4C: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x80196A50: sltiu       $at, $t6, 0x14
    ctx->r1 = ctx->r14 < 0X14 ? 1 : 0;
    // 0x80196A54: beq         $at, $zero, L_801970BC
    if (ctx->r1 == 0) {
        // 0x80196A58: nop
    
            goto L_801970BC;
    }
    // 0x80196A58: nop

    // 0x80196A5C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80196A60: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80196A64: addu        $at, $at, $t6
    gpr jr_addend_80196A6C = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80196A68: lw          $t6, 0x870($at)
    ctx->r14 = ADD32(ctx->r1, 0X870);
    // 0x80196A6C: jr          $t6
    // 0x80196A70: nop

    switch (jr_addend_80196A6C >> 2) {
        case 0: goto L_80196A74; break;
        case 1: goto L_80196B1C; break;
        case 2: goto L_801970BC; break;
        case 3: goto L_80196B84; break;
        case 4: goto L_80196C2C; break;
        case 5: goto L_801970BC; break;
        case 6: goto L_801970BC; break;
        case 7: goto L_801970BC; break;
        case 8: goto L_801970BC; break;
        case 9: goto L_80196CD4; break;
        case 10: goto L_80196D7C; break;
        case 11: goto L_80196E24; break;
        case 12: goto L_80196ECC; break;
        case 13: goto L_80196F74; break;
        case 14: goto L_801970BC; break;
        case 15: goto L_801970BC; break;
        case 16: goto L_801970BC; break;
        case 17: goto L_801970BC; break;
        case 18: goto L_801970BC; break;
        case 19: goto L_8019701C; break;
        default: switch_error(__func__, 0x80196A6C, 0x801A0870);
    }
    // 0x80196A70: nop

L_80196A74:
    // 0x80196A74: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x80196A78: addiu       $at, $zero, 0x65
    ctx->r1 = ADD32(0, 0X65);
    // 0x80196A7C: bne         $t8, $at, L_80196AD0
    if (ctx->r24 != ctx->r1) {
        // 0x80196A80: nop
    
            goto L_80196AD0;
    }
    // 0x80196A80: nop

    // 0x80196A84: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80196A88: lw          $t7, -0x2E3C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2E3C);
    // 0x80196A8C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80196A90: bne         $t7, $at, L_80196AB4
    if (ctx->r15 != ctx->r1) {
        // 0x80196A94: nop
    
            goto L_80196AB4;
    }
    // 0x80196A94: nop

    // 0x80196A98: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80196A9C: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80196AA0: addiu       $a1, $a1, -0xA08
    ctx->r5 = ADD32(ctx->r5, -0XA08);
    // 0x80196AA4: jal         0x800D87E4
    // 0x80196AA8: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_8;
    // 0x80196AA8: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_8:
    // 0x80196AAC: b           L_801970BC
    // 0x80196AB0: nop

        goto L_801970BC;
    // 0x80196AB0: nop

L_80196AB4:
    // 0x80196AB4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80196AB8: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80196ABC: addiu       $a1, $a1, -0x9F0
    ctx->r5 = ADD32(ctx->r5, -0X9F0);
    // 0x80196AC0: jal         0x800D87E4
    // 0x80196AC4: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_9;
    // 0x80196AC4: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_9:
    // 0x80196AC8: b           L_801970BC
    // 0x80196ACC: nop

        goto L_801970BC;
    // 0x80196ACC: nop

L_80196AD0:
    // 0x80196AD0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80196AD4: lw          $t9, -0x2E3C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2E3C);
    // 0x80196AD8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80196ADC: bne         $t9, $at, L_80196B00
    if (ctx->r25 != ctx->r1) {
        // 0x80196AE0: nop
    
            goto L_80196B00;
    }
    // 0x80196AE0: nop

    // 0x80196AE4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80196AE8: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80196AEC: addiu       $a1, $a1, -0x9D4
    ctx->r5 = ADD32(ctx->r5, -0X9D4);
    // 0x80196AF0: jal         0x800D87E4
    // 0x80196AF4: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_10;
    // 0x80196AF4: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_10:
    // 0x80196AF8: b           L_801970BC
    // 0x80196AFC: nop

        goto L_801970BC;
    // 0x80196AFC: nop

L_80196B00:
    // 0x80196B00: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80196B04: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80196B08: addiu       $a1, $a1, -0x9BC
    ctx->r5 = ADD32(ctx->r5, -0X9BC);
    // 0x80196B0C: jal         0x800D87E4
    // 0x80196B10: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_11;
    // 0x80196B10: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_11:
    // 0x80196B14: b           L_801970BC
    // 0x80196B18: nop

        goto L_801970BC;
    // 0x80196B18: nop

L_80196B1C:
    // 0x80196B1C: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80196B20: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80196B24: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80196B28: sll         $t1, $t0, 5
    ctx->r9 = S32(ctx->r8 << 5);
    // 0x80196B2C: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80196B30: lw          $t2, 0x39B0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X39B0);
    // 0x80196B34: beq         $t2, $at, L_80196B60
    if (ctx->r10 == ctx->r1) {
        // 0x80196B38: nop
    
            goto L_80196B60;
    }
    // 0x80196B38: nop

    // 0x80196B3C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80196B40: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80196B44: addiu       $a1, $a1, -0x9A0
    ctx->r5 = ADD32(ctx->r5, -0X9A0);
    // 0x80196B48: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    // 0x80196B4C: addiu       $a2, $t0, 0x1
    ctx->r6 = ADD32(ctx->r8, 0X1);
    // 0x80196B50: jal         0x800D87E4
    // 0x80196B54: addiu       $a3, $t2, 0x1
    ctx->r7 = ADD32(ctx->r10, 0X1);
    sprintf_recomp(rdram, ctx);
        goto after_12;
    // 0x80196B54: addiu       $a3, $t2, 0x1
    ctx->r7 = ADD32(ctx->r10, 0X1);
    after_12:
    // 0x80196B58: b           L_801970BC
    // 0x80196B5C: nop

        goto L_801970BC;
    // 0x80196B5C: nop

L_80196B60:
    // 0x80196B60: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x80196B64: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80196B68: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80196B6C: addiu       $a1, $a1, -0x97C
    ctx->r5 = ADD32(ctx->r5, -0X97C);
    // 0x80196B70: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    // 0x80196B74: jal         0x800D87E4
    // 0x80196B78: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    sprintf_recomp(rdram, ctx);
        goto after_13;
    // 0x80196B78: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    after_13:
    // 0x80196B7C: b           L_801970BC
    // 0x80196B80: nop

        goto L_801970BC;
    // 0x80196B80: nop

L_80196B84:
    // 0x80196B84: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x80196B88: addiu       $at, $zero, 0x65
    ctx->r1 = ADD32(0, 0X65);
    // 0x80196B8C: bne         $t3, $at, L_80196BE0
    if (ctx->r11 != ctx->r1) {
        // 0x80196B90: nop
    
            goto L_80196BE0;
    }
    // 0x80196B90: nop

    // 0x80196B94: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80196B98: lw          $t4, -0x2E3C($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2E3C);
    // 0x80196B9C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80196BA0: bne         $t4, $at, L_80196BC4
    if (ctx->r12 != ctx->r1) {
        // 0x80196BA4: nop
    
            goto L_80196BC4;
    }
    // 0x80196BA4: nop

    // 0x80196BA8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80196BAC: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80196BB0: addiu       $a1, $a1, -0x954
    ctx->r5 = ADD32(ctx->r5, -0X954);
    // 0x80196BB4: jal         0x800D87E4
    // 0x80196BB8: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_14;
    // 0x80196BB8: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_14:
    // 0x80196BBC: b           L_801970BC
    // 0x80196BC0: nop

        goto L_801970BC;
    // 0x80196BC0: nop

L_80196BC4:
    // 0x80196BC4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80196BC8: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80196BCC: addiu       $a1, $a1, -0x930
    ctx->r5 = ADD32(ctx->r5, -0X930);
    // 0x80196BD0: jal         0x800D87E4
    // 0x80196BD4: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_15;
    // 0x80196BD4: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_15:
    // 0x80196BD8: b           L_801970BC
    // 0x80196BDC: nop

        goto L_801970BC;
    // 0x80196BDC: nop

L_80196BE0:
    // 0x80196BE0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80196BE4: lw          $t5, -0x2E3C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2E3C);
    // 0x80196BE8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80196BEC: bne         $t5, $at, L_80196C10
    if (ctx->r13 != ctx->r1) {
        // 0x80196BF0: nop
    
            goto L_80196C10;
    }
    // 0x80196BF0: nop

    // 0x80196BF4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80196BF8: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80196BFC: addiu       $a1, $a1, -0x908
    ctx->r5 = ADD32(ctx->r5, -0X908);
    // 0x80196C00: jal         0x800D87E4
    // 0x80196C04: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_16;
    // 0x80196C04: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_16:
    // 0x80196C08: b           L_801970BC
    // 0x80196C0C: nop

        goto L_801970BC;
    // 0x80196C0C: nop

L_80196C10:
    // 0x80196C10: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80196C14: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80196C18: addiu       $a1, $a1, -0x8E4
    ctx->r5 = ADD32(ctx->r5, -0X8E4);
    // 0x80196C1C: jal         0x800D87E4
    // 0x80196C20: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_17;
    // 0x80196C20: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_17:
    // 0x80196C24: b           L_801970BC
    // 0x80196C28: nop

        goto L_801970BC;
    // 0x80196C28: nop

L_80196C2C:
    // 0x80196C2C: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80196C30: addiu       $at, $zero, 0x65
    ctx->r1 = ADD32(0, 0X65);
    // 0x80196C34: bne         $t6, $at, L_80196C88
    if (ctx->r14 != ctx->r1) {
        // 0x80196C38: nop
    
            goto L_80196C88;
    }
    // 0x80196C38: nop

    // 0x80196C3C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80196C40: lw          $t8, -0x2E3C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2E3C);
    // 0x80196C44: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80196C48: bne         $t8, $at, L_80196C6C
    if (ctx->r24 != ctx->r1) {
        // 0x80196C4C: nop
    
            goto L_80196C6C;
    }
    // 0x80196C4C: nop

    // 0x80196C50: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80196C54: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80196C58: addiu       $a1, $a1, -0x8BC
    ctx->r5 = ADD32(ctx->r5, -0X8BC);
    // 0x80196C5C: jal         0x800D87E4
    // 0x80196C60: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_18;
    // 0x80196C60: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_18:
    // 0x80196C64: b           L_801970BC
    // 0x80196C68: nop

        goto L_801970BC;
    // 0x80196C68: nop

L_80196C6C:
    // 0x80196C6C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80196C70: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80196C74: addiu       $a1, $a1, -0x898
    ctx->r5 = ADD32(ctx->r5, -0X898);
    // 0x80196C78: jal         0x800D87E4
    // 0x80196C7C: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_19;
    // 0x80196C7C: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_19:
    // 0x80196C80: b           L_801970BC
    // 0x80196C84: nop

        goto L_801970BC;
    // 0x80196C84: nop

L_80196C88:
    // 0x80196C88: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80196C8C: lw          $t7, -0x2E3C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2E3C);
    // 0x80196C90: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80196C94: bne         $t7, $at, L_80196CB8
    if (ctx->r15 != ctx->r1) {
        // 0x80196C98: nop
    
            goto L_80196CB8;
    }
    // 0x80196C98: nop

    // 0x80196C9C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80196CA0: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80196CA4: addiu       $a1, $a1, -0x870
    ctx->r5 = ADD32(ctx->r5, -0X870);
    // 0x80196CA8: jal         0x800D87E4
    // 0x80196CAC: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_20;
    // 0x80196CAC: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_20:
    // 0x80196CB0: b           L_801970BC
    // 0x80196CB4: nop

        goto L_801970BC;
    // 0x80196CB4: nop

L_80196CB8:
    // 0x80196CB8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80196CBC: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80196CC0: addiu       $a1, $a1, -0x84C
    ctx->r5 = ADD32(ctx->r5, -0X84C);
    // 0x80196CC4: jal         0x800D87E4
    // 0x80196CC8: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_21;
    // 0x80196CC8: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_21:
    // 0x80196CCC: b           L_801970BC
    // 0x80196CD0: nop

        goto L_801970BC;
    // 0x80196CD0: nop

L_80196CD4:
    // 0x80196CD4: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80196CD8: addiu       $at, $zero, 0x65
    ctx->r1 = ADD32(0, 0X65);
    // 0x80196CDC: bne         $t9, $at, L_80196D30
    if (ctx->r25 != ctx->r1) {
        // 0x80196CE0: nop
    
            goto L_80196D30;
    }
    // 0x80196CE0: nop

    // 0x80196CE4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80196CE8: lw          $t1, -0x2E3C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2E3C);
    // 0x80196CEC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80196CF0: bne         $t1, $at, L_80196D14
    if (ctx->r9 != ctx->r1) {
        // 0x80196CF4: nop
    
            goto L_80196D14;
    }
    // 0x80196CF4: nop

    // 0x80196CF8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80196CFC: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80196D00: addiu       $a1, $a1, -0x824
    ctx->r5 = ADD32(ctx->r5, -0X824);
    // 0x80196D04: jal         0x800D87E4
    // 0x80196D08: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_22;
    // 0x80196D08: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_22:
    // 0x80196D0C: b           L_801970BC
    // 0x80196D10: nop

        goto L_801970BC;
    // 0x80196D10: nop

L_80196D14:
    // 0x80196D14: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80196D18: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80196D1C: addiu       $a1, $a1, -0x804
    ctx->r5 = ADD32(ctx->r5, -0X804);
    // 0x80196D20: jal         0x800D87E4
    // 0x80196D24: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_23;
    // 0x80196D24: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_23:
    // 0x80196D28: b           L_801970BC
    // 0x80196D2C: nop

        goto L_801970BC;
    // 0x80196D2C: nop

L_80196D30:
    // 0x80196D30: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80196D34: lw          $t0, -0x2E3C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2E3C);
    // 0x80196D38: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80196D3C: bne         $t0, $at, L_80196D60
    if (ctx->r8 != ctx->r1) {
        // 0x80196D40: nop
    
            goto L_80196D60;
    }
    // 0x80196D40: nop

    // 0x80196D44: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80196D48: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80196D4C: addiu       $a1, $a1, -0x7E0
    ctx->r5 = ADD32(ctx->r5, -0X7E0);
    // 0x80196D50: jal         0x800D87E4
    // 0x80196D54: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_24;
    // 0x80196D54: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_24:
    // 0x80196D58: b           L_801970BC
    // 0x80196D5C: nop

        goto L_801970BC;
    // 0x80196D5C: nop

L_80196D60:
    // 0x80196D60: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80196D64: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80196D68: addiu       $a1, $a1, -0x7C0
    ctx->r5 = ADD32(ctx->r5, -0X7C0);
    // 0x80196D6C: jal         0x800D87E4
    // 0x80196D70: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_25;
    // 0x80196D70: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_25:
    // 0x80196D74: b           L_801970BC
    // 0x80196D78: nop

        goto L_801970BC;
    // 0x80196D78: nop

L_80196D7C:
    // 0x80196D7C: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x80196D80: addiu       $at, $zero, 0x65
    ctx->r1 = ADD32(0, 0X65);
    // 0x80196D84: bne         $t2, $at, L_80196DD8
    if (ctx->r10 != ctx->r1) {
        // 0x80196D88: nop
    
            goto L_80196DD8;
    }
    // 0x80196D88: nop

    // 0x80196D8C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80196D90: lw          $t3, -0x2E3C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2E3C);
    // 0x80196D94: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80196D98: bne         $t3, $at, L_80196DBC
    if (ctx->r11 != ctx->r1) {
        // 0x80196D9C: nop
    
            goto L_80196DBC;
    }
    // 0x80196D9C: nop

    // 0x80196DA0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80196DA4: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80196DA8: addiu       $a1, $a1, -0x79C
    ctx->r5 = ADD32(ctx->r5, -0X79C);
    // 0x80196DAC: jal         0x800D87E4
    // 0x80196DB0: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_26;
    // 0x80196DB0: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_26:
    // 0x80196DB4: b           L_801970BC
    // 0x80196DB8: nop

        goto L_801970BC;
    // 0x80196DB8: nop

L_80196DBC:
    // 0x80196DBC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80196DC0: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80196DC4: addiu       $a1, $a1, -0x77C
    ctx->r5 = ADD32(ctx->r5, -0X77C);
    // 0x80196DC8: jal         0x800D87E4
    // 0x80196DCC: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_27;
    // 0x80196DCC: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_27:
    // 0x80196DD0: b           L_801970BC
    // 0x80196DD4: nop

        goto L_801970BC;
    // 0x80196DD4: nop

L_80196DD8:
    // 0x80196DD8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80196DDC: lw          $t4, -0x2E3C($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2E3C);
    // 0x80196DE0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80196DE4: bne         $t4, $at, L_80196E08
    if (ctx->r12 != ctx->r1) {
        // 0x80196DE8: nop
    
            goto L_80196E08;
    }
    // 0x80196DE8: nop

    // 0x80196DEC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80196DF0: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80196DF4: addiu       $a1, $a1, -0x758
    ctx->r5 = ADD32(ctx->r5, -0X758);
    // 0x80196DF8: jal         0x800D87E4
    // 0x80196DFC: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_28;
    // 0x80196DFC: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_28:
    // 0x80196E00: b           L_801970BC
    // 0x80196E04: nop

        goto L_801970BC;
    // 0x80196E04: nop

L_80196E08:
    // 0x80196E08: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80196E0C: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80196E10: addiu       $a1, $a1, -0x738
    ctx->r5 = ADD32(ctx->r5, -0X738);
    // 0x80196E14: jal         0x800D87E4
    // 0x80196E18: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_29;
    // 0x80196E18: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_29:
    // 0x80196E1C: b           L_801970BC
    // 0x80196E20: nop

        goto L_801970BC;
    // 0x80196E20: nop

L_80196E24:
    // 0x80196E24: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x80196E28: addiu       $at, $zero, 0x65
    ctx->r1 = ADD32(0, 0X65);
    // 0x80196E2C: bne         $t5, $at, L_80196E80
    if (ctx->r13 != ctx->r1) {
        // 0x80196E30: nop
    
            goto L_80196E80;
    }
    // 0x80196E30: nop

    // 0x80196E34: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80196E38: lw          $t6, -0x2E3C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2E3C);
    // 0x80196E3C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80196E40: bne         $t6, $at, L_80196E64
    if (ctx->r14 != ctx->r1) {
        // 0x80196E44: nop
    
            goto L_80196E64;
    }
    // 0x80196E44: nop

    // 0x80196E48: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80196E4C: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80196E50: addiu       $a1, $a1, -0x714
    ctx->r5 = ADD32(ctx->r5, -0X714);
    // 0x80196E54: jal         0x800D87E4
    // 0x80196E58: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_30;
    // 0x80196E58: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_30:
    // 0x80196E5C: b           L_801970BC
    // 0x80196E60: nop

        goto L_801970BC;
    // 0x80196E60: nop

L_80196E64:
    // 0x80196E64: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80196E68: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80196E6C: addiu       $a1, $a1, -0x6FC
    ctx->r5 = ADD32(ctx->r5, -0X6FC);
    // 0x80196E70: jal         0x800D87E4
    // 0x80196E74: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_31;
    // 0x80196E74: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_31:
    // 0x80196E78: b           L_801970BC
    // 0x80196E7C: nop

        goto L_801970BC;
    // 0x80196E7C: nop

L_80196E80:
    // 0x80196E80: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80196E84: lw          $t8, -0x2E3C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2E3C);
    // 0x80196E88: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80196E8C: bne         $t8, $at, L_80196EB0
    if (ctx->r24 != ctx->r1) {
        // 0x80196E90: nop
    
            goto L_80196EB0;
    }
    // 0x80196E90: nop

    // 0x80196E94: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80196E98: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80196E9C: addiu       $a1, $a1, -0x6E0
    ctx->r5 = ADD32(ctx->r5, -0X6E0);
    // 0x80196EA0: jal         0x800D87E4
    // 0x80196EA4: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_32;
    // 0x80196EA4: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_32:
    // 0x80196EA8: b           L_801970BC
    // 0x80196EAC: nop

        goto L_801970BC;
    // 0x80196EAC: nop

L_80196EB0:
    // 0x80196EB0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80196EB4: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80196EB8: addiu       $a1, $a1, -0x6C8
    ctx->r5 = ADD32(ctx->r5, -0X6C8);
    // 0x80196EBC: jal         0x800D87E4
    // 0x80196EC0: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_33;
    // 0x80196EC0: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_33:
    // 0x80196EC4: b           L_801970BC
    // 0x80196EC8: nop

        goto L_801970BC;
    // 0x80196EC8: nop

L_80196ECC:
    // 0x80196ECC: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80196ED0: addiu       $at, $zero, 0x65
    ctx->r1 = ADD32(0, 0X65);
    // 0x80196ED4: bne         $t7, $at, L_80196F28
    if (ctx->r15 != ctx->r1) {
        // 0x80196ED8: nop
    
            goto L_80196F28;
    }
    // 0x80196ED8: nop

    // 0x80196EDC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80196EE0: lw          $t9, -0x2E3C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2E3C);
    // 0x80196EE4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80196EE8: bne         $t9, $at, L_80196F0C
    if (ctx->r25 != ctx->r1) {
        // 0x80196EEC: nop
    
            goto L_80196F0C;
    }
    // 0x80196EEC: nop

    // 0x80196EF0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80196EF4: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80196EF8: addiu       $a1, $a1, -0x6AC
    ctx->r5 = ADD32(ctx->r5, -0X6AC);
    // 0x80196EFC: jal         0x800D87E4
    // 0x80196F00: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_34;
    // 0x80196F00: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_34:
    // 0x80196F04: b           L_801970BC
    // 0x80196F08: nop

        goto L_801970BC;
    // 0x80196F08: nop

L_80196F0C:
    // 0x80196F0C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80196F10: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80196F14: addiu       $a1, $a1, -0x694
    ctx->r5 = ADD32(ctx->r5, -0X694);
    // 0x80196F18: jal         0x800D87E4
    // 0x80196F1C: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_35;
    // 0x80196F1C: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_35:
    // 0x80196F20: b           L_801970BC
    // 0x80196F24: nop

        goto L_801970BC;
    // 0x80196F24: nop

L_80196F28:
    // 0x80196F28: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80196F2C: lw          $t1, -0x2E3C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2E3C);
    // 0x80196F30: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80196F34: bne         $t1, $at, L_80196F58
    if (ctx->r9 != ctx->r1) {
        // 0x80196F38: nop
    
            goto L_80196F58;
    }
    // 0x80196F38: nop

    // 0x80196F3C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80196F40: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80196F44: addiu       $a1, $a1, -0x678
    ctx->r5 = ADD32(ctx->r5, -0X678);
    // 0x80196F48: jal         0x800D87E4
    // 0x80196F4C: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_36;
    // 0x80196F4C: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_36:
    // 0x80196F50: b           L_801970BC
    // 0x80196F54: nop

        goto L_801970BC;
    // 0x80196F54: nop

L_80196F58:
    // 0x80196F58: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80196F5C: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80196F60: addiu       $a1, $a1, -0x660
    ctx->r5 = ADD32(ctx->r5, -0X660);
    // 0x80196F64: jal         0x800D87E4
    // 0x80196F68: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_37;
    // 0x80196F68: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_37:
    // 0x80196F6C: b           L_801970BC
    // 0x80196F70: nop

        goto L_801970BC;
    // 0x80196F70: nop

L_80196F74:
    // 0x80196F74: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80196F78: addiu       $at, $zero, 0x65
    ctx->r1 = ADD32(0, 0X65);
    // 0x80196F7C: bne         $t0, $at, L_80196FD0
    if (ctx->r8 != ctx->r1) {
        // 0x80196F80: nop
    
            goto L_80196FD0;
    }
    // 0x80196F80: nop

    // 0x80196F84: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80196F88: lw          $t2, -0x2E3C($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2E3C);
    // 0x80196F8C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80196F90: bne         $t2, $at, L_80196FB4
    if (ctx->r10 != ctx->r1) {
        // 0x80196F94: nop
    
            goto L_80196FB4;
    }
    // 0x80196F94: nop

    // 0x80196F98: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80196F9C: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80196FA0: addiu       $a1, $a1, -0x644
    ctx->r5 = ADD32(ctx->r5, -0X644);
    // 0x80196FA4: jal         0x800D87E4
    // 0x80196FA8: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_38;
    // 0x80196FA8: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_38:
    // 0x80196FAC: b           L_801970BC
    // 0x80196FB0: nop

        goto L_801970BC;
    // 0x80196FB0: nop

L_80196FB4:
    // 0x80196FB4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80196FB8: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80196FBC: addiu       $a1, $a1, -0x62C
    ctx->r5 = ADD32(ctx->r5, -0X62C);
    // 0x80196FC0: jal         0x800D87E4
    // 0x80196FC4: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_39;
    // 0x80196FC4: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_39:
    // 0x80196FC8: b           L_801970BC
    // 0x80196FCC: nop

        goto L_801970BC;
    // 0x80196FCC: nop

L_80196FD0:
    // 0x80196FD0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80196FD4: lw          $t3, -0x2E3C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2E3C);
    // 0x80196FD8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80196FDC: bne         $t3, $at, L_80197000
    if (ctx->r11 != ctx->r1) {
        // 0x80196FE0: nop
    
            goto L_80197000;
    }
    // 0x80196FE0: nop

    // 0x80196FE4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80196FE8: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80196FEC: addiu       $a1, $a1, -0x610
    ctx->r5 = ADD32(ctx->r5, -0X610);
    // 0x80196FF0: jal         0x800D87E4
    // 0x80196FF4: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_40;
    // 0x80196FF4: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_40:
    // 0x80196FF8: b           L_801970BC
    // 0x80196FFC: nop

        goto L_801970BC;
    // 0x80196FFC: nop

L_80197000:
    // 0x80197000: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80197004: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80197008: addiu       $a1, $a1, -0x5F8
    ctx->r5 = ADD32(ctx->r5, -0X5F8);
    // 0x8019700C: jal         0x800D87E4
    // 0x80197010: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_41;
    // 0x80197010: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_41:
    // 0x80197014: b           L_801970BC
    // 0x80197018: nop

        goto L_801970BC;
    // 0x80197018: nop

L_8019701C:
    // 0x8019701C: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80197020: addiu       $at, $zero, 0x65
    ctx->r1 = ADD32(0, 0X65);
    // 0x80197024: bne         $t4, $at, L_80197078
    if (ctx->r12 != ctx->r1) {
        // 0x80197028: nop
    
            goto L_80197078;
    }
    // 0x80197028: nop

    // 0x8019702C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80197030: lw          $t5, -0x2E3C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2E3C);
    // 0x80197034: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80197038: bne         $t5, $at, L_8019705C
    if (ctx->r13 != ctx->r1) {
        // 0x8019703C: nop
    
            goto L_8019705C;
    }
    // 0x8019703C: nop

    // 0x80197040: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80197044: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80197048: addiu       $a1, $a1, -0x5DC
    ctx->r5 = ADD32(ctx->r5, -0X5DC);
    // 0x8019704C: jal         0x800D87E4
    // 0x80197050: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_42;
    // 0x80197050: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_42:
    // 0x80197054: b           L_801970BC
    // 0x80197058: nop

        goto L_801970BC;
    // 0x80197058: nop

L_8019705C:
    // 0x8019705C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80197060: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80197064: addiu       $a1, $a1, -0x5B8
    ctx->r5 = ADD32(ctx->r5, -0X5B8);
    // 0x80197068: jal         0x800D87E4
    // 0x8019706C: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_43;
    // 0x8019706C: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_43:
    // 0x80197070: b           L_801970BC
    // 0x80197074: nop

        goto L_801970BC;
    // 0x80197074: nop

L_80197078:
    // 0x80197078: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8019707C: lw          $t6, -0x2E3C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2E3C);
    // 0x80197080: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80197084: bne         $t6, $at, L_801970A8
    if (ctx->r14 != ctx->r1) {
        // 0x80197088: nop
    
            goto L_801970A8;
    }
    // 0x80197088: nop

    // 0x8019708C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80197090: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80197094: addiu       $a1, $a1, -0x590
    ctx->r5 = ADD32(ctx->r5, -0X590);
    // 0x80197098: jal         0x800D87E4
    // 0x8019709C: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_44;
    // 0x8019709C: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_44:
    // 0x801970A0: b           L_801970BC
    // 0x801970A4: nop

        goto L_801970BC;
    // 0x801970A4: nop

L_801970A8:
    // 0x801970A8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x801970AC: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x801970B0: addiu       $a1, $a1, -0x56C
    ctx->r5 = ADD32(ctx->r5, -0X56C);
    // 0x801970B4: jal         0x800D87E4
    // 0x801970B8: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_45;
    // 0x801970B8: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_45:
L_801970BC:
    // 0x801970BC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x801970C0: jal         0x800DD77C
    // 0x801970C4: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    strlen_recomp(rdram, ctx);
        goto after_46;
    // 0x801970C4: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_46:
    // 0x801970C8: sll         $t8, $v0, 3
    ctx->r24 = S32(ctx->r2 << 3);
    // 0x801970CC: negu        $t7, $t8
    ctx->r15 = SUB32(0, ctx->r24);
    // 0x801970D0: addiu       $t9, $zero, 0xC0
    ctx->r25 = ADD32(0, 0XC0);
    // 0x801970D4: subu        $t1, $t9, $t7
    ctx->r9 = SUB32(ctx->r25, ctx->r15);
    // 0x801970D8: addiu       $at, $zero, 0x78
    ctx->r1 = ADD32(0, 0X78);
    // 0x801970DC: div         $zero, $t1, $at
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r1)));
    // 0x801970E0: mflo        $t0
    ctx->r8 = lo;
    // 0x801970E4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x801970E8: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x801970EC: addiu       $t2, $t2, -0x2E18
    ctx->r10 = ADD32(ctx->r10, -0X2E18);
    // 0x801970F0: lw          $t3, 0xC($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XC);
    // 0x801970F4: addiu       $t4, $t0, 0x1
    ctx->r12 = ADD32(ctx->r8, 0X1);
    // 0x801970F8: addiu       $t6, $zero, 0x100
    ctx->r14 = ADD32(0, 0X100);
    // 0x801970FC: multu       $t3, $t4
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80197100: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    // 0x80197104: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80197108: addiu       $a2, $zero, 0x38
    ctx->r6 = ADD32(0, 0X38);
    // 0x8019710C: addiu       $a3, $zero, 0x47
    ctx->r7 = ADD32(0, 0X47);
    // 0x80197110: mflo        $t5
    ctx->r13 = lo;
    // 0x80197114: subu        $t8, $t6, $t5
    ctx->r24 = SUB32(ctx->r14, ctx->r13);
    // 0x80197118: jal         0x800D3D84
    // 0x8019711C: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    spScissor_recomp(rdram, ctx);
        goto after_47;
    // 0x8019711C: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    after_47:
    // 0x80197120: jal         0x800C7AD0
    // 0x80197124: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800C7AD0(rdram, ctx);
        goto after_48;
    // 0x80197124: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_48:
    // 0x80197128: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    // 0x8019712C: jal         0x800C7A60
    // 0x80197130: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C7A60(rdram, ctx);
        goto after_49;
    // 0x80197130: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_49:
    // 0x80197134: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80197138: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x8019713C: mtc1        $at, $f15
    ctx->f_odd[(15 - 1) * 2] = ctx->r1;
    // 0x80197140: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80197144: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80197148: jal         0x800C7A88
    // 0x8019714C: nop

    func_800C7A88(rdram, ctx);
        goto after_50;
    // 0x8019714C: nop

    after_50:
    // 0x80197150: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80197154: lui         $t1, 0x800F
    ctx->r9 = S32(0X800F << 16);
    // 0x80197158: addiu       $t1, $t1, -0x5248
    ctx->r9 = ADD32(ctx->r9, -0X5248);
    // 0x8019715C: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x80197160: subu        $t7, $t7, $t9
    ctx->r15 = SUB32(ctx->r15, ctx->r25);
    // 0x80197164: addu        $t2, $t7, $t1
    ctx->r10 = ADD32(ctx->r15, ctx->r9);
    // 0x80197168: lbu         $a0, 0x0($t2)
    ctx->r4 = MEM_BU(ctx->r10, 0X0);
    // 0x8019716C: lbu         $a1, 0x1($t2)
    ctx->r5 = MEM_BU(ctx->r10, 0X1);
    // 0x80197170: lbu         $a2, 0x2($t2)
    ctx->r6 = MEM_BU(ctx->r10, 0X2);
    // 0x80197174: jal         0x800C7A9C
    // 0x80197178: addiu       $a3, $zero, 0x78
    ctx->r7 = ADD32(0, 0X78);
    func_800C7A9C(rdram, ctx);
        goto after_51;
    // 0x80197178: addiu       $a3, $zero, 0x78
    ctx->r7 = ADD32(0, 0X78);
    after_51:
    // 0x8019717C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80197180: jal         0x800C7A74
    // 0x80197184: addiu       $a1, $zero, 0x38
    ctx->r5 = ADD32(0, 0X38);
    func_800C7A74(rdram, ctx);
        goto after_52;
    // 0x80197184: addiu       $a1, $zero, 0x38
    ctx->r5 = ADD32(0, 0X38);
    after_52:
    // 0x80197188: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8019718C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80197190: addiu       $a1, $a1, 0x3B40
    ctx->r5 = ADD32(ctx->r5, 0X3B40);
    // 0x80197194: jal         0x800C780C
    // 0x80197198: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    func_800C780C(rdram, ctx);
        goto after_53;
    // 0x80197198: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    after_53:
    // 0x8019719C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x801971A0: addiu       $t0, $t0, -0x2E18
    ctx->r8 = ADD32(ctx->r8, -0X2E18);
    // 0x801971A4: lw          $t3, 0xC($t0)
    ctx->r11 = MEM_W(ctx->r8, 0XC);
    // 0x801971A8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801971AC: addiu       $t6, $t6, -0x2E18
    ctx->r14 = ADD32(ctx->r14, -0X2E18);
    // 0x801971B0: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x801971B4: sw          $t4, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r12;
    // 0x801971B8: lw          $t5, 0xC($t6)
    ctx->r13 = MEM_W(ctx->r14, 0XC);
    // 0x801971BC: addiu       $at, $zero, 0x78
    ctx->r1 = ADD32(0, 0X78);
    // 0x801971C0: bne         $t5, $at, L_801971DC
    if (ctx->r13 != ctx->r1) {
        // 0x801971C4: nop
    
            goto L_801971DC;
    }
    // 0x801971C4: nop

    // 0x801971C8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x801971CC: addiu       $t8, $t8, -0x2E28
    ctx->r24 = ADD32(ctx->r24, -0X2E28);
    // 0x801971D0: lbu         $t9, 0xA($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0XA);
    // 0x801971D4: andi        $t7, $t9, 0xFD
    ctx->r15 = ctx->r25 & 0XFD;
    // 0x801971D8: sb          $t7, 0xA($t8)
    MEM_B(0XA, ctx->r24) = ctx->r15;
L_801971DC:
    // 0x801971DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801971E0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801971E4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x801971E8: jr          $ra
    // 0x801971EC: nop

    return;
    // 0x801971EC: nop

;}
RECOMP_FUNC void func_801971F0_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801971F0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801971F4: lw          $t6, -0x2E44($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2E44);
    // 0x801971F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801971FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80197200: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80197204: sltiu       $at, $t7, 0x6
    ctx->r1 = ctx->r15 < 0X6 ? 1 : 0;
    // 0x80197208: beq         $at, $zero, L_80197298
    if (ctx->r1 == 0) {
        // 0x8019720C: nop
    
            goto L_80197298;
    }
    // 0x8019720C: nop

    // 0x80197210: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80197214: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80197218: addu        $at, $at, $t7
    gpr jr_addend_80197220 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8019721C: lw          $t7, 0x8C0($at)
    ctx->r15 = ADD32(ctx->r1, 0X8C0);
    // 0x80197220: jr          $t7
    // 0x80197224: nop

    switch (jr_addend_80197220 >> 2) {
        case 0: goto L_80197228; break;
        case 1: goto L_8019723C; break;
        case 2: goto L_80197250; break;
        case 3: goto L_80197264; break;
        case 4: goto L_80197278; break;
        case 5: goto L_8019728C; break;
        default: switch_error(__func__, 0x80197220, 0x801A08C0);
    }
    // 0x80197224: nop

L_80197228:
    // 0x80197228: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8019722C: jal         0x800C3968
    // 0x80197230: addiu       $a0, $a0, -0x48B4
    ctx->r4 = ADD32(ctx->r4, -0X48B4);
    func_800C3968(rdram, ctx);
        goto after_0;
    // 0x80197230: addiu       $a0, $a0, -0x48B4
    ctx->r4 = ADD32(ctx->r4, -0X48B4);
    after_0:
    // 0x80197234: b           L_80197298
    // 0x80197238: nop

        goto L_80197298;
    // 0x80197238: nop

L_8019723C:
    // 0x8019723C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80197240: jal         0x800C3968
    // 0x80197244: addiu       $a0, $a0, -0x4860
    ctx->r4 = ADD32(ctx->r4, -0X4860);
    func_800C3968(rdram, ctx);
        goto after_1;
    // 0x80197244: addiu       $a0, $a0, -0x4860
    ctx->r4 = ADD32(ctx->r4, -0X4860);
    after_1:
    // 0x80197248: b           L_80197298
    // 0x8019724C: nop

        goto L_80197298;
    // 0x8019724C: nop

L_80197250:
    // 0x80197250: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80197254: jal         0x800C3968
    // 0x80197258: addiu       $a0, $a0, -0x47F0
    ctx->r4 = ADD32(ctx->r4, -0X47F0);
    func_800C3968(rdram, ctx);
        goto after_2;
    // 0x80197258: addiu       $a0, $a0, -0x47F0
    ctx->r4 = ADD32(ctx->r4, -0X47F0);
    after_2:
    // 0x8019725C: b           L_80197298
    // 0x80197260: nop

        goto L_80197298;
    // 0x80197260: nop

L_80197264:
    // 0x80197264: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80197268: jal         0x800C3968
    // 0x8019726C: addiu       $a0, $a0, -0x479C
    ctx->r4 = ADD32(ctx->r4, -0X479C);
    func_800C3968(rdram, ctx);
        goto after_3;
    // 0x8019726C: addiu       $a0, $a0, -0x479C
    ctx->r4 = ADD32(ctx->r4, -0X479C);
    after_3:
    // 0x80197270: b           L_80197298
    // 0x80197274: nop

        goto L_80197298;
    // 0x80197274: nop

L_80197278:
    // 0x80197278: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8019727C: jal         0x800C3968
    // 0x80197280: addiu       $a0, $a0, -0x4748
    ctx->r4 = ADD32(ctx->r4, -0X4748);
    func_800C3968(rdram, ctx);
        goto after_4;
    // 0x80197280: addiu       $a0, $a0, -0x4748
    ctx->r4 = ADD32(ctx->r4, -0X4748);
    after_4:
    // 0x80197284: b           L_80197298
    // 0x80197288: nop

        goto L_80197298;
    // 0x80197288: nop

L_8019728C:
    // 0x8019728C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80197290: jal         0x800C3968
    // 0x80197294: addiu       $a0, $a0, -0x46AC
    ctx->r4 = ADD32(ctx->r4, -0X46AC);
    func_800C3968(rdram, ctx);
        goto after_5;
    // 0x80197294: addiu       $a0, $a0, -0x46AC
    ctx->r4 = ADD32(ctx->r4, -0X46AC);
    after_5:
L_80197298:
    // 0x80197298: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8019729C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801972A0: jr          $ra
    // 0x801972A4: nop

    return;
    // 0x801972A4: nop

;}
RECOMP_FUNC void func_801972A8_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801972A8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801972AC: lw          $t6, -0x2E48($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2E48);
    // 0x801972B0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801972B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801972B8: sltiu       $at, $t6, 0x2
    ctx->r1 = ctx->r14 < 0X2 ? 1 : 0;
    // 0x801972BC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x801972C0: beq         $at, $zero, L_80197428
    if (ctx->r1 == 0) {
        // 0x801972C4: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_80197428;
    }
    // 0x801972C4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801972C8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801972CC: addiu       $t7, $t7, -0x2BA8
    ctx->r15 = ADD32(ctx->r15, -0X2BA8);
    // 0x801972D0: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x801972D4: beq         $t8, $zero, L_80197428
    if (ctx->r24 == 0) {
        // 0x801972D8: nop
    
            goto L_80197428;
    }
    // 0x801972D8: nop

    // 0x801972DC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801972E0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801972E4: sw          $t9, -0x2D68($at)
    MEM_W(-0X2D68, ctx->r1) = ctx->r25;
    // 0x801972E8: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x801972EC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801972F0: sw          $zero, -0x2D58($at)
    MEM_W(-0X2D58, ctx->r1) = 0;
    // 0x801972F4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801972F8: sw          $t0, -0x2D54($at)
    MEM_W(-0X2D54, ctx->r1) = ctx->r8;
    // 0x801972FC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80197300: sw          $zero, -0x2D40($at)
    MEM_W(-0X2D40, ctx->r1) = 0;
    // 0x80197304: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80197308: sw          $zero, -0x2D48($at)
    MEM_W(-0X2D48, ctx->r1) = 0;
    // 0x8019730C: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x80197310: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80197314: addiu       $t1, $t1, -0x1C00
    ctx->r9 = ADD32(ctx->r9, -0X1C00);
    // 0x80197318: sw          $zero, -0x2D50($at)
    MEM_W(-0X2D50, ctx->r1) = 0;
    // 0x8019731C: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80197320: lbu         $t3, 0x0($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X0);
    // 0x80197324: ori         $at, $zero, 0x8030
    ctx->r1 = 0 | 0X8030;
    // 0x80197328: andi        $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 & 0XFF;
    // 0x8019732C: sh          $t4, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r12;
    // 0x80197330: lbu         $t5, 0x1($t2)
    ctx->r13 = MEM_BU(ctx->r10, 0X1);
    // 0x80197334: andi        $t9, $t4, 0xFFFF
    ctx->r25 = ctx->r12 & 0XFFFF;
    // 0x80197338: andi        $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 & 0XFF;
    // 0x8019733C: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x80197340: sll         $t8, $t7, 8
    ctx->r24 = S32(ctx->r15 << 8);
    // 0x80197344: addu        $s0, $t9, $t8
    ctx->r16 = ADD32(ctx->r25, ctx->r24);
    // 0x80197348: beq         $s0, $at, L_8019737C
    if (ctx->r16 == ctx->r1) {
        // 0x8019734C: sh          $t6, 0x2C($sp)
        MEM_H(0X2C, ctx->r29) = ctx->r14;
            goto L_8019737C;
    }
    // 0x8019734C: sh          $t6, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r14;
    // 0x80197350: ori         $at, $zero, 0x8031
    ctx->r1 = 0 | 0X8031;
    // 0x80197354: bne         $s0, $at, L_8019739C
    if (ctx->r16 != ctx->r1) {
        // 0x80197358: nop
    
            goto L_8019739C;
    }
    // 0x80197358: nop

    // 0x8019735C: jal         0x800CD438
    // 0x80197360: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800CD438(rdram, ctx);
        goto after_0;
    // 0x80197360: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80197364: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80197368: lw          $t0, -0x2D54($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2D54);
    // 0x8019736C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80197370: addiu       $t1, $t0, 0x2
    ctx->r9 = ADD32(ctx->r8, 0X2);
    // 0x80197374: b           L_801973A4
    // 0x80197378: sw          $t1, -0x2D54($at)
    MEM_W(-0X2D54, ctx->r1) = ctx->r9;
        goto L_801973A4;
    // 0x80197378: sw          $t1, -0x2D54($at)
    MEM_W(-0X2D54, ctx->r1) = ctx->r9;
L_8019737C:
    // 0x8019737C: jal         0x800CD438
    // 0x80197380: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800CD438(rdram, ctx);
        goto after_1;
    // 0x80197380: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x80197384: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80197388: lw          $t3, -0x2D54($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2D54);
    // 0x8019738C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80197390: addiu       $t2, $t3, 0x2
    ctx->r10 = ADD32(ctx->r11, 0X2);
    // 0x80197394: b           L_801973A4
    // 0x80197398: sw          $t2, -0x2D54($at)
    MEM_W(-0X2D54, ctx->r1) = ctx->r10;
        goto L_801973A4;
    // 0x80197398: sw          $t2, -0x2D54($at)
    MEM_W(-0X2D54, ctx->r1) = ctx->r10;
L_8019739C:
    // 0x8019739C: jal         0x800CD438
    // 0x801973A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800CD438(rdram, ctx);
        goto after_2;
    // 0x801973A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
L_801973A4:
    // 0x801973A4: jal         0x800C8544
    // 0x801973A8: addiu       $a0, $zero, 0x35
    ctx->r4 = ADD32(0, 0X35);
    func_800C8544(rdram, ctx);
        goto after_3;
    // 0x801973A8: addiu       $a0, $zero, 0x35
    ctx->r4 = ADD32(0, 0X35);
    after_3:
    // 0x801973AC: jal         0x800D1680
    // 0x801973B0: nop

    func_800D1680(rdram, ctx);
        goto after_4;
    // 0x801973B0: nop

    after_4:
    // 0x801973B4: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x801973B8: lw          $t5, -0x2E3C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2E3C);
    // 0x801973BC: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x801973C0: beq         $t5, $zero, L_80197404
    if (ctx->r13 == 0) {
        // 0x801973C4: nop
    
            goto L_80197404;
    }
    // 0x801973C4: nop

L_801973C8:
    // 0x801973C8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x801973CC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801973D0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x801973D4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801973D8: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x801973DC: jal         0x80173864
    // 0x801973E0: sw          $zero, -0x2B7C($at)
    MEM_W(-0X2B7C, ctx->r1) = 0;
    func_80173864_1501A0(rdram, ctx);
        goto after_5;
    // 0x801973E0: sw          $zero, -0x2B7C($at)
    MEM_W(-0X2B7C, ctx->r1) = 0;
    after_5:
    // 0x801973E4: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x801973E8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x801973EC: lw          $t8, -0x2E3C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2E3C);
    // 0x801973F0: addiu       $t9, $t4, 0x1
    ctx->r25 = ADD32(ctx->r12, 0X1);
    // 0x801973F4: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x801973F8: sltu        $at, $t9, $t8
    ctx->r1 = ctx->r25 < ctx->r24 ? 1 : 0;
    // 0x801973FC: bne         $at, $zero, L_801973C8
    if (ctx->r1 != 0) {
        // 0x80197400: nop
    
            goto L_801973C8;
    }
    // 0x80197400: nop

L_80197404:
    // 0x80197404: addiu       $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
    // 0x80197408: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8019740C: sw          $t0, -0x2D98($at)
    MEM_W(-0X2D98, ctx->r1) = ctx->r8;
    // 0x80197410: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80197414: addiu       $t1, $zero, 0x0
    ctx->r9 = ADD32(0, 0X0);
    // 0x80197418: sw          $t1, -0x2D94($at)
    MEM_W(-0X2D94, ctx->r1) = ctx->r9;
    // 0x8019741C: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x80197420: jal         0x800D7A20
    // 0x80197424: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    osSetTime_recomp(rdram, ctx);
        goto after_6;
    // 0x80197424: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_6:
L_80197428:
    // 0x80197428: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8019742C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80197430: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80197434: jr          $ra
    // 0x80197438: nop

    return;
    // 0x80197438: nop

;}
RECOMP_FUNC void func_8019743C_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019743C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80197440: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80197444: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80197448: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8019744C: addiu       $t6, $t6, -0x2E28
    ctx->r14 = ADD32(ctx->r14, -0X2E28);
    // 0x80197450: lbu         $t7, 0x2($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X2);
    // 0x80197454: andi        $t8, $t7, 0x80
    ctx->r24 = ctx->r15 & 0X80;
    // 0x80197458: beq         $t8, $zero, L_80197470
    if (ctx->r24 == 0) {
        // 0x8019745C: nop
    
            goto L_80197470;
    }
    // 0x8019745C: nop

    // 0x80197460: jal         0x800CCDC8
    // 0x80197464: nop

    func_800CCDC8(rdram, ctx);
        goto after_0;
    // 0x80197464: nop

    after_0:
    // 0x80197468: b           L_801978AC
    // 0x8019746C: nop

        goto L_801978AC;
    // 0x8019746C: nop

L_80197470:
    // 0x80197470: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80197474: lw          $s0, -0x2D68($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X2D68);
    // 0x80197478: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8019747C: beq         $s0, $at, L_8019749C
    if (ctx->r16 == ctx->r1) {
        // 0x80197480: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8019749C;
    }
    // 0x80197480: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80197484: beq         $s0, $at, L_801974CC
    if (ctx->r16 == ctx->r1) {
        // 0x80197488: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_801974CC;
    }
    // 0x80197488: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8019748C: beq         $s0, $at, L_80197888
    if (ctx->r16 == ctx->r1) {
        // 0x80197490: nop
    
            goto L_80197888;
    }
    // 0x80197490: nop

    // 0x80197494: b           L_801978AC
    // 0x80197498: nop

        goto L_801978AC;
    // 0x80197498: nop

L_8019749C:
    // 0x8019749C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801974A0: lw          $t9, -0x2D58($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2D58);
    // 0x801974A4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801974A8: addiu       $t0, $t9, 0x16
    ctx->r8 = ADD32(ctx->r25, 0X16);
    // 0x801974AC: sw          $t0, -0x2D58($at)
    MEM_W(-0X2D58, ctx->r1) = ctx->r8;
    // 0x801974B0: addiu       $at, $zero, 0xC6
    ctx->r1 = ADD32(0, 0XC6);
    // 0x801974B4: bne         $t0, $at, L_801978AC
    if (ctx->r8 != ctx->r1) {
        // 0x801974B8: nop
    
            goto L_801978AC;
    }
    // 0x801974B8: nop

    // 0x801974BC: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x801974C0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801974C4: b           L_801978AC
    // 0x801974C8: sw          $t1, -0x2D68($at)
    MEM_W(-0X2D68, ctx->r1) = ctx->r9;
        goto L_801978AC;
    // 0x801974C8: sw          $t1, -0x2D68($at)
    MEM_W(-0X2D68, ctx->r1) = ctx->r9;
L_801974CC:
    // 0x801974CC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x801974D0: lw          $t2, -0x2D48($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2D48);
    // 0x801974D4: beq         $t2, $zero, L_801974EC
    if (ctx->r10 == 0) {
        // 0x801974D8: nop
    
            goto L_801974EC;
    }
    // 0x801974D8: nop

    // 0x801974DC: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x801974E0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801974E4: b           L_801978AC
    // 0x801974E8: sw          $t3, -0x2D48($at)
    MEM_W(-0X2D48, ctx->r1) = ctx->r11;
        goto L_801978AC;
    // 0x801974E8: sw          $t3, -0x2D48($at)
    MEM_W(-0X2D48, ctx->r1) = ctx->r11;
L_801974EC:
    // 0x801974EC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x801974F0: lw          $t4, -0x2D54($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2D54);
    // 0x801974F4: lui         $t5, 0x800C
    ctx->r13 = S32(0X800C << 16);
    // 0x801974F8: addiu       $t5, $t5, -0x1C00
    ctx->r13 = ADD32(ctx->r13, -0X1C00);
    // 0x801974FC: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x80197500: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x80197504: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80197508: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8019750C: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x80197510: sh          $t8, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r24;
    // 0x80197514: lbu         $t9, 0x1($t6)
    ctx->r25 = MEM_BU(ctx->r14, 0X1);
    // 0x80197518: andi        $t3, $t8, 0xFFFF
    ctx->r11 = ctx->r24 & 0XFFFF;
    // 0x8019751C: addiu       $t7, $t4, 0x2
    ctx->r15 = ADD32(ctx->r12, 0X2);
    // 0x80197520: andi        $t0, $t9, 0xFF
    ctx->r8 = ctx->r25 & 0XFF;
    // 0x80197524: andi        $t1, $t0, 0xFFFF
    ctx->r9 = ctx->r8 & 0XFFFF;
    // 0x80197528: sll         $t2, $t1, 8
    ctx->r10 = S32(ctx->r9 << 8);
    // 0x8019752C: addu        $t5, $t3, $t2
    ctx->r13 = ADD32(ctx->r11, ctx->r10);
    // 0x80197530: sw          $t5, -0x2D50($at)
    MEM_W(-0X2D50, ctx->r1) = ctx->r13;
    // 0x80197534: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80197538: sw          $t7, -0x2D54($at)
    MEM_W(-0X2D54, ctx->r1) = ctx->r15;
    // 0x8019753C: lw          $s0, -0x2D50($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X2D50);
    // 0x80197540: sh          $t0, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r8;
    // 0x80197544: andi        $t6, $s0, 0xC000
    ctx->r14 = ctx->r16 & 0XC000;
    // 0x80197548: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    // 0x8019754C: beq         $s0, $zero, L_80197564
    if (ctx->r16 == 0) {
        // 0x80197550: ori         $at, $zero, 0x8000
        ctx->r1 = 0 | 0X8000;
            goto L_80197564;
    }
    // 0x80197550: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80197554: beq         $s0, $at, L_801975D8
    if (ctx->r16 == ctx->r1) {
        // 0x80197558: nop
    
            goto L_801975D8;
    }
    // 0x80197558: nop

    // 0x8019755C: b           L_801978AC
    // 0x80197560: nop

        goto L_801978AC;
    // 0x80197560: nop

L_80197564:
    // 0x80197564: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80197568: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8019756C: lw          $t8, -0x2D5C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2D5C);
    // 0x80197570: lw          $t0, -0x2D60($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2D60);
    // 0x80197574: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80197578: lw          $t9, -0x2D50($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2D50);
    // 0x8019757C: sll         $t3, $t8, 1
    ctx->r11 = S32(ctx->r24 << 1);
    // 0x80197580: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x80197584: addu        $t2, $t1, $t3
    ctx->r10 = ADD32(ctx->r9, ctx->r11);
    // 0x80197588: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8019758C: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x80197590: sh          $t9, -0x2D30($at)
    MEM_H(-0X2D30, ctx->r1) = ctx->r25;
    // 0x80197594: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80197598: sw          $zero, -0x2D48($at)
    MEM_W(-0X2D48, ctx->r1) = 0;
    // 0x8019759C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x801975A0: lw          $t5, -0x2D60($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2D60);
    // 0x801975A4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801975A8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801975AC: addiu       $t4, $t5, 0x1
    ctx->r12 = ADD32(ctx->r13, 0X1);
    // 0x801975B0: sw          $t4, -0x2D60($at)
    MEM_W(-0X2D60, ctx->r1) = ctx->r12;
    // 0x801975B4: lw          $t7, -0x2D54($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2D54);
    // 0x801975B8: andi        $t6, $t7, 0x3
    ctx->r14 = ctx->r15 & 0X3;
    // 0x801975BC: bne         $t6, $zero, L_801978AC
    if (ctx->r14 != 0) {
        // 0x801975C0: nop
    
            goto L_801978AC;
    }
    // 0x801975C0: nop

    // 0x801975C4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x801975C8: lw          $t0, -0x2D50($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2D50);
    // 0x801975CC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801975D0: b           L_801978AC
    // 0x801975D4: sw          $t0, -0x2D4C($at)
    MEM_W(-0X2D4C, ctx->r1) = ctx->r8;
        goto L_801978AC;
    // 0x801975D4: sw          $t0, -0x2D4C($at)
    MEM_W(-0X2D4C, ctx->r1) = ctx->r8;
L_801975D8:
    // 0x801975D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801975DC: sw          $zero, -0x2D4C($at)
    MEM_W(-0X2D4C, ctx->r1) = 0;
    // 0x801975E0: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x801975E4: lw          $s0, -0x2D50($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X2D50);
    // 0x801975E8: ori         $at, $zero, 0x8081
    ctx->r1 = 0 | 0X8081;
    // 0x801975EC: sltu        $at, $s0, $at
    ctx->r1 = ctx->r16 < ctx->r1 ? 1 : 0;
    // 0x801975F0: bne         $at, $zero, L_80197610
    if (ctx->r1 != 0) {
        // 0x801975F4: ori         $at, $zero, 0x8081
        ctx->r1 = 0 | 0X8081;
            goto L_80197610;
    }
    // 0x801975F4: ori         $at, $zero, 0x8081
    ctx->r1 = 0 | 0X8081;
    // 0x801975F8: beq         $s0, $at, L_80197660
    if (ctx->r16 == ctx->r1) {
        // 0x801975FC: ori         $at, $zero, 0x8082
        ctx->r1 = 0 | 0X8082;
            goto L_80197660;
    }
    // 0x801975FC: ori         $at, $zero, 0x8082
    ctx->r1 = 0 | 0X8082;
    // 0x80197600: beq         $s0, $at, L_80197660
    if (ctx->r16 == ctx->r1) {
        // 0x80197604: nop
    
            goto L_80197660;
    }
    // 0x80197604: nop

    // 0x80197608: b           L_801978AC
    // 0x8019760C: nop

        goto L_801978AC;
    // 0x8019760C: nop

L_80197610:
    // 0x80197610: ori         $at, $zero, 0x8032
    ctx->r1 = 0 | 0X8032;
    // 0x80197614: sltu        $at, $s0, $at
    ctx->r1 = ctx->r16 < ctx->r1 ? 1 : 0;
    // 0x80197618: bne         $at, $zero, L_80197630
    if (ctx->r1 != 0) {
        // 0x8019761C: ori         $at, $zero, 0x8080
        ctx->r1 = 0 | 0X8080;
            goto L_80197630;
    }
    // 0x8019761C: ori         $at, $zero, 0x8080
    ctx->r1 = 0 | 0X8080;
    // 0x80197620: beq         $s0, $at, L_80197660
    if (ctx->r16 == ctx->r1) {
        // 0x80197624: nop
    
            goto L_80197660;
    }
    // 0x80197624: nop

    // 0x80197628: b           L_801978AC
    // 0x8019762C: nop

        goto L_801978AC;
    // 0x8019762C: nop

L_80197630:
    // 0x80197630: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80197634: ori         $at, $at, 0x7FF0
    ctx->r1 = ctx->r1 | 0X7FF0;
    // 0x80197638: addu        $t8, $s0, $at
    ctx->r24 = ADD32(ctx->r16, ctx->r1);
    // 0x8019763C: sltiu       $at, $t8, 0x22
    ctx->r1 = ctx->r24 < 0X22 ? 1 : 0;
    // 0x80197640: beq         $at, $zero, L_801978AC
    if (ctx->r1 == 0) {
        // 0x80197644: nop
    
            goto L_801978AC;
    }
    // 0x80197644: nop

    // 0x80197648: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8019764C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80197650: addu        $at, $at, $t8
    gpr jr_addend_80197658 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80197654: lw          $t8, 0x8D8($at)
    ctx->r24 = ADD32(ctx->r1, 0X8D8);
    // 0x80197658: jr          $t8
    // 0x8019765C: nop

    switch (jr_addend_80197658 >> 2) {
        case 0: goto L_80197694; break;
        case 1: goto L_80197694; break;
        case 2: goto L_80197694; break;
        case 3: goto L_80197694; break;
        case 4: goto L_80197694; break;
        case 5: goto L_80197694; break;
        case 6: goto L_80197694; break;
        case 7: goto L_80197694; break;
        case 8: goto L_80197694; break;
        case 9: goto L_80197694; break;
        case 10: goto L_801978AC; break;
        case 11: goto L_801978AC; break;
        case 12: goto L_801978AC; break;
        case 13: goto L_801978AC; break;
        case 14: goto L_801978AC; break;
        case 15: goto L_801978AC; break;
        case 16: goto L_801976B8; break;
        case 17: goto L_80197800; break;
        case 18: goto L_80197830; break;
        case 19: goto L_801978AC; break;
        case 20: goto L_801978AC; break;
        case 21: goto L_801978AC; break;
        case 22: goto L_801978AC; break;
        case 23: goto L_801978AC; break;
        case 24: goto L_801978AC; break;
        case 25: goto L_801978AC; break;
        case 26: goto L_801978AC; break;
        case 27: goto L_801978AC; break;
        case 28: goto L_801978AC; break;
        case 29: goto L_801978AC; break;
        case 30: goto L_801978AC; break;
        case 31: goto L_801978AC; break;
        case 32: goto L_80197860; break;
        case 33: goto L_80197870; break;
        default: switch_error(__func__, 0x80197658, 0x801A08D8);
    }
    // 0x8019765C: nop

L_80197660:
    // 0x80197660: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80197664: lw          $t1, -0x2D50($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2D50);
    // 0x80197668: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8019766C: ori         $at, $at, 0x7F80
    ctx->r1 = ctx->r1 | 0X7F80;
    // 0x80197670: addu        $t3, $t1, $at
    ctx->r11 = ADD32(ctx->r9, ctx->r1);
    // 0x80197674: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80197678: sw          $t3, -0x2D3C($at)
    MEM_W(-0X2D3C, ctx->r1) = ctx->r11;
    // 0x8019767C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80197680: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80197684: sw          $t9, -0x2D40($at)
    MEM_W(-0X2D40, ctx->r1) = ctx->r25;
    // 0x80197688: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8019768C: b           L_801978AC
    // 0x80197690: sw          $zero, -0x2D38($at)
    MEM_W(-0X2D38, ctx->r1) = 0;
        goto L_801978AC;
    // 0x80197690: sw          $zero, -0x2D38($at)
    MEM_W(-0X2D38, ctx->r1) = 0;
L_80197694:
    // 0x80197694: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80197698: lw          $t2, -0x2D50($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2D50);
    // 0x8019769C: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x801976A0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801976A4: sll         $t5, $t2, 2
    ctx->r13 = S32(ctx->r10 << 2);
    // 0x801976A8: addu        $t4, $t4, $t5
    ctx->r12 = ADD32(ctx->r12, ctx->r13);
    // 0x801976AC: lw          $t4, -0x5278($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X5278);
    // 0x801976B0: b           L_801978AC
    // 0x801976B4: sw          $t4, -0x2D48($at)
    MEM_W(-0X2D48, ctx->r1) = ctx->r12;
        goto L_801978AC;
    // 0x801976B4: sw          $t4, -0x2D48($at)
    MEM_W(-0X2D48, ctx->r1) = ctx->r12;
L_801976B8:
    // 0x801976B8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801976BC: sw          $zero, -0x2D60($at)
    MEM_W(-0X2D60, ctx->r1) = 0;
    // 0x801976C0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801976C4: lw          $t7, -0x2D64($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2D64);
    // 0x801976C8: bne         $t7, $zero, L_8019774C
    if (ctx->r15 != 0) {
        // 0x801976CC: nop
    
            goto L_8019774C;
    }
    // 0x801976CC: nop

    // 0x801976D0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801976D4: lw          $t6, -0x2D5C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2D5C);
    // 0x801976D8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801976DC: bne         $t6, $at, L_80197734
    if (ctx->r14 != ctx->r1) {
        // 0x801976E0: nop
    
            goto L_80197734;
    }
    // 0x801976E0: nop

    // 0x801976E4: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_801976E8:
    // 0x801976E8: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x801976EC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x801976F0: addiu       $t1, $t1, -0x2D68
    ctx->r9 = ADD32(ctx->r9, -0X2D68);
    // 0x801976F4: sll         $t8, $t0, 3
    ctx->r24 = S32(ctx->r8 << 3);
    // 0x801976F8: addu        $t3, $t8, $t1
    ctx->r11 = ADD32(ctx->r24, ctx->r9);
    // 0x801976FC: lhu         $t9, 0x3A($t3)
    ctx->r25 = MEM_HU(ctx->r11, 0X3A);
    // 0x80197700: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80197704: sh          $t9, 0x38($t3)
    MEM_H(0X38, ctx->r11) = ctx->r25;
    // 0x80197708: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8019770C: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80197710: sll         $t5, $t2, 3
    ctx->r13 = S32(ctx->r10 << 3);
    // 0x80197714: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x80197718: sh          $zero, -0x2D2E($at)
    MEM_H(-0X2D2E, ctx->r1) = 0;
    // 0x8019771C: addiu       $t7, $t4, 0x1
    ctx->r15 = ADD32(ctx->r12, 0X1);
    // 0x80197720: sltiu       $at, $t7, 0x20
    ctx->r1 = ctx->r15 < 0X20 ? 1 : 0;
    // 0x80197724: bne         $at, $zero, L_801976E8
    if (ctx->r1 != 0) {
        // 0x80197728: sw          $t7, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r15;
            goto L_801976E8;
    }
    // 0x80197728: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x8019772C: b           L_80197880
    // 0x80197730: nop

        goto L_80197880;
    // 0x80197730: nop

L_80197734:
    // 0x80197734: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80197738: lw          $t6, -0x2D5C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2D5C);
    // 0x8019773C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80197740: addiu       $t0, $t6, 0x1
    ctx->r8 = ADD32(ctx->r14, 0X1);
    // 0x80197744: b           L_801978AC
    // 0x80197748: sw          $t0, -0x2D5C($at)
    MEM_W(-0X2D5C, ctx->r1) = ctx->r8;
        goto L_801978AC;
    // 0x80197748: sw          $t0, -0x2D5C($at)
    MEM_W(-0X2D5C, ctx->r1) = ctx->r8;
L_8019774C:
    // 0x8019774C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80197750: lw          $t8, -0x2D5C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2D5C);
    // 0x80197754: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80197758: bne         $t8, $at, L_801977E8
    if (ctx->r24 != ctx->r1) {
        // 0x8019775C: nop
    
            goto L_801977E8;
    }
    // 0x8019775C: nop

    // 0x80197760: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_80197764:
    // 0x80197764: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x80197768: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8019776C: addiu       $t3, $t3, -0x2D68
    ctx->r11 = ADD32(ctx->r11, -0X2D68);
    // 0x80197770: sll         $t9, $t1, 3
    ctx->r25 = S32(ctx->r9 << 3);
    // 0x80197774: addu        $t2, $t9, $t3
    ctx->r10 = ADD32(ctx->r25, ctx->r11);
    // 0x80197778: lhu         $t5, 0x3A($t2)
    ctx->r13 = MEM_HU(ctx->r10, 0X3A);
    // 0x8019777C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80197780: addiu       $t6, $t6, -0x2D68
    ctx->r14 = ADD32(ctx->r14, -0X2D68);
    // 0x80197784: sh          $t5, 0x38($t2)
    MEM_H(0X38, ctx->r10) = ctx->r13;
    // 0x80197788: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x8019778C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80197790: addiu       $t3, $t3, -0x2D68
    ctx->r11 = ADD32(ctx->r11, -0X2D68);
    // 0x80197794: sll         $t7, $t4, 3
    ctx->r15 = S32(ctx->r12 << 3);
    // 0x80197798: addu        $t0, $t7, $t6
    ctx->r8 = ADD32(ctx->r15, ctx->r14);
    // 0x8019779C: lhu         $t8, 0x3C($t0)
    ctx->r24 = MEM_HU(ctx->r8, 0X3C);
    // 0x801977A0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801977A4: sh          $t8, 0x3A($t0)
    MEM_H(0X3A, ctx->r8) = ctx->r24;
    // 0x801977A8: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x801977AC: sll         $t9, $t1, 3
    ctx->r25 = S32(ctx->r9 << 3);
    // 0x801977B0: addu        $t5, $t9, $t3
    ctx->r13 = ADD32(ctx->r25, ctx->r11);
    // 0x801977B4: lhu         $t2, 0x3E($t5)
    ctx->r10 = MEM_HU(ctx->r13, 0X3E);
    // 0x801977B8: sh          $t2, 0x3C($t5)
    MEM_H(0X3C, ctx->r13) = ctx->r10;
    // 0x801977BC: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x801977C0: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x801977C4: sll         $t7, $t4, 3
    ctx->r15 = S32(ctx->r12 << 3);
    // 0x801977C8: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x801977CC: sh          $zero, -0x2D2E($at)
    MEM_H(-0X2D2E, ctx->r1) = 0;
    // 0x801977D0: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x801977D4: sltiu       $at, $t8, 0x20
    ctx->r1 = ctx->r24 < 0X20 ? 1 : 0;
    // 0x801977D8: bne         $at, $zero, L_80197764
    if (ctx->r1 != 0) {
        // 0x801977DC: sw          $t8, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r24;
            goto L_80197764;
    }
    // 0x801977DC: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x801977E0: b           L_801978AC
    // 0x801977E4: nop

        goto L_801978AC;
    // 0x801977E4: nop

L_801977E8:
    // 0x801977E8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x801977EC: lw          $t0, -0x2D5C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2D5C);
    // 0x801977F0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801977F4: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x801977F8: b           L_801978AC
    // 0x801977FC: sw          $t1, -0x2D5C($at)
    MEM_W(-0X2D5C, ctx->r1) = ctx->r9;
        goto L_801978AC;
    // 0x801977FC: sw          $t1, -0x2D5C($at)
    MEM_W(-0X2D5C, ctx->r1) = ctx->r9;
L_80197800:
    // 0x80197800: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80197804: lw          $t9, -0x2D64($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2D64);
    // 0x80197808: bne         $t9, $zero, L_80197820
    if (ctx->r25 != 0) {
        // 0x8019780C: nop
    
            goto L_80197820;
    }
    // 0x8019780C: nop

    // 0x80197810: jal         0x800CD438
    // 0x80197814: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800CD438(rdram, ctx);
        goto after_1;
    // 0x80197814: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x80197818: b           L_801978AC
    // 0x8019781C: nop

        goto L_801978AC;
    // 0x8019781C: nop

L_80197820:
    // 0x80197820: jal         0x800CD438
    // 0x80197824: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800CD438(rdram, ctx);
        goto after_2;
    // 0x80197824: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x80197828: b           L_801978AC
    // 0x8019782C: nop

        goto L_801978AC;
    // 0x8019782C: nop

L_80197830:
    // 0x80197830: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x80197834: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80197838: sw          $t3, -0x2D68($at)
    MEM_W(-0X2D68, ctx->r1) = ctx->r11;
    // 0x8019783C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80197840: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x80197844: sw          $t2, -0x2D40($at)
    MEM_W(-0X2D40, ctx->r1) = ctx->r10;
    // 0x80197848: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8019784C: sw          $zero, -0x2D38($at)
    MEM_W(-0X2D38, ctx->r1) = 0;
    // 0x80197850: jal         0x800C8544
    // 0x80197854: addiu       $a0, $zero, 0x36
    ctx->r4 = ADD32(0, 0X36);
    func_800C8544(rdram, ctx);
        goto after_3;
    // 0x80197854: addiu       $a0, $zero, 0x36
    ctx->r4 = ADD32(0, 0X36);
    after_3:
    // 0x80197858: b           L_801978AC
    // 0x8019785C: nop

        goto L_801978AC;
    // 0x8019785C: nop

L_80197860:
    // 0x80197860: jal         0x800CD438
    // 0x80197864: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800CD438(rdram, ctx);
        goto after_4;
    // 0x80197864: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x80197868: b           L_801978AC
    // 0x8019786C: nop

        goto L_801978AC;
    // 0x8019786C: nop

L_80197870:
    // 0x80197870: jal         0x800CD438
    // 0x80197874: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800CD438(rdram, ctx);
        goto after_5;
    // 0x80197874: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_5:
    // 0x80197878: b           L_801978AC
    // 0x8019787C: nop

        goto L_801978AC;
    // 0x8019787C: nop

L_80197880:
    // 0x80197880: b           L_801978AC
    // 0x80197884: nop

        goto L_801978AC;
    // 0x80197884: nop

L_80197888:
    // 0x80197888: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8019788C: lw          $t5, -0x2D58($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2D58);
    // 0x80197890: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80197894: addiu       $t4, $t5, -0x16
    ctx->r12 = ADD32(ctx->r13, -0X16);
    // 0x80197898: bne         $t4, $zero, L_801978AC
    if (ctx->r12 != 0) {
        // 0x8019789C: sw          $t4, -0x2D58($at)
        MEM_W(-0X2D58, ctx->r1) = ctx->r12;
            goto L_801978AC;
    }
    // 0x8019789C: sw          $t4, -0x2D58($at)
    MEM_W(-0X2D58, ctx->r1) = ctx->r12;
    // 0x801978A0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801978A4: jal         0x800D28C0
    // 0x801978A8: sw          $zero, -0x2D68($at)
    MEM_W(-0X2D68, ctx->r1) = 0;
    func_800D28C0(rdram, ctx);
        goto after_6;
    // 0x801978A8: sw          $zero, -0x2D68($at)
    MEM_W(-0X2D68, ctx->r1) = 0;
    after_6:
L_801978AC:
    // 0x801978AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801978B0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801978B4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801978B8: jr          $ra
    // 0x801978BC: nop

    return;
    // 0x801978BC: nop

;}
RECOMP_FUNC void func_801978C0_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801978C0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801978C4: lw          $t6, -0x2D68($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2D68);
    // 0x801978C8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801978CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801978D0: beq         $t6, $zero, L_80197B44
    if (ctx->r14 == 0) {
        // 0x801978D4: nop
    
            goto L_80197B44;
    }
    // 0x801978D4: nop

    // 0x801978D8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801978DC: addiu       $t7, $t7, -0x2E28
    ctx->r15 = ADD32(ctx->r15, -0X2E28);
    // 0x801978E0: lbu         $t8, 0x2($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X2);
    // 0x801978E4: andi        $t9, $t8, 0x80
    ctx->r25 = ctx->r24 & 0X80;
    // 0x801978E8: beq         $t9, $zero, L_80197900
    if (ctx->r25 == 0) {
        // 0x801978EC: nop
    
            goto L_80197900;
    }
    // 0x801978EC: nop

    // 0x801978F0: jal         0x800CD230
    // 0x801978F4: nop

    func_800CD230(rdram, ctx);
        goto after_0;
    // 0x801978F4: nop

    after_0:
    // 0x801978F8: b           L_80197B44
    // 0x801978FC: nop

        goto L_80197B44;
    // 0x801978FC: nop

L_80197900:
    // 0x80197900: jal         0x80197B54
    // 0x80197904: nop

    func_80197B54_1501A0(rdram, ctx);
        goto after_1;
    // 0x80197904: nop

    after_1:
    // 0x80197908: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8019790C: lw          $t0, -0x2D64($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2D64);
    // 0x80197910: bne         $t0, $zero, L_80197A00
    if (ctx->r8 != 0) {
        // 0x80197914: nop
    
            goto L_80197A00;
    }
    // 0x80197914: nop

    // 0x80197918: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8019791C: sh          $zero, 0x20($sp)
    MEM_H(0X20, ctx->r29) = 0;
L_80197920:
    // 0x80197920: sh          $zero, 0x22($sp)
    MEM_H(0X22, ctx->r29) = 0;
L_80197924:
    // 0x80197924: lhu         $t1, 0x22($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X22);
    // 0x80197928: lhu         $t3, 0x20($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X20);
    // 0x8019792C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80197930: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x80197934: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x80197938: addiu       $t6, $t6, -0x2D68
    ctx->r14 = ADD32(ctx->r14, -0X2D68);
    // 0x8019793C: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80197940: addu        $t8, $t2, $t4
    ctx->r24 = ADD32(ctx->r10, ctx->r12);
    // 0x80197944: addu        $t9, $t8, $t6
    ctx->r25 = ADD32(ctx->r24, ctx->r14);
    // 0x80197948: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x8019794C: lhu         $a0, 0x38($t7)
    ctx->r4 = MEM_HU(ctx->r15, 0X38);
    // 0x80197950: lhu         $a1, 0x40($t9)
    ctx->r5 = MEM_HU(ctx->r25, 0X40);
    // 0x80197954: jal         0x800CD4B4
    // 0x80197958: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    func_800CD4B4(rdram, ctx);
        goto after_2;
    // 0x80197958: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x8019795C: lhu         $t3, 0x22($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X22);
    // 0x80197960: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80197964: addiu       $t5, $t3, 0x2
    ctx->r13 = ADD32(ctx->r11, 0X2);
    // 0x80197968: andi        $t7, $t5, 0xFFFF
    ctx->r15 = ctx->r13 & 0XFFFF;
    // 0x8019796C: slti        $at, $t7, 0x20
    ctx->r1 = SIGNED(ctx->r15) < 0X20 ? 1 : 0;
    // 0x80197970: addiu       $t1, $t0, 0x80
    ctx->r9 = ADD32(ctx->r8, 0X80);
    // 0x80197974: sh          $t5, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r13;
    // 0x80197978: bne         $at, $zero, L_80197924
    if (ctx->r1 != 0) {
        // 0x8019797C: sw          $t1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r9;
            goto L_80197924;
    }
    // 0x8019797C: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x80197980: lhu         $t2, 0x20($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X20);
    // 0x80197984: addiu       $t4, $t2, 0x1
    ctx->r12 = ADD32(ctx->r10, 0X1);
    // 0x80197988: andi        $t8, $t4, 0xFFFF
    ctx->r24 = ctx->r12 & 0XFFFF;
    // 0x8019798C: slti        $at, $t8, 0x2
    ctx->r1 = SIGNED(ctx->r24) < 0X2 ? 1 : 0;
    // 0x80197990: bne         $at, $zero, L_80197920
    if (ctx->r1 != 0) {
        // 0x80197994: sh          $t4, 0x20($sp)
        MEM_H(0X20, ctx->r29) = ctx->r12;
            goto L_80197920;
    }
    // 0x80197994: sh          $t4, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r12;
    // 0x80197998: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8019799C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801979A0: lw          $t6, -0x2D58($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2D58);
    // 0x801979A4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801979A8: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x801979AC: addiu       $a0, $a0, 0x6B48
    ctx->r4 = ADD32(ctx->r4, 0X6B48);
    // 0x801979B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801979B4: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x801979B8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801979BC: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x801979C0: jal         0x800C6C6C
    // 0x801979C4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_3;
    // 0x801979C4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x801979C8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801979CC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801979D0: lw          $t9, -0x2D58($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2D58);
    // 0x801979D4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801979D8: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x801979DC: addiu       $a0, $a0, -0x4BF0
    ctx->r4 = ADD32(ctx->r4, -0X4BF0);
    // 0x801979E0: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    // 0x801979E4: addiu       $a2, $zero, 0x24
    ctx->r6 = ADD32(0, 0X24);
    // 0x801979E8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801979EC: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x801979F0: jal         0x800C6C6C
    // 0x801979F4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_4;
    // 0x801979F4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_4:
    // 0x801979F8: b           L_80197AE0
    // 0x801979FC: nop

        goto L_80197AE0;
    // 0x801979FC: nop

L_80197A00:
    // 0x80197A00: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80197A04: sh          $zero, 0x20($sp)
    MEM_H(0X20, ctx->r29) = 0;
L_80197A08:
    // 0x80197A08: sh          $zero, 0x22($sp)
    MEM_H(0X22, ctx->r29) = 0;
L_80197A0C:
    // 0x80197A0C: lhu         $t0, 0x22($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X22);
    // 0x80197A10: lhu         $t3, 0x20($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X20);
    // 0x80197A14: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80197A18: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x80197A1C: sll         $t5, $t3, 1
    ctx->r13 = S32(ctx->r11 << 1);
    // 0x80197A20: addiu       $t2, $t2, -0x2D68
    ctx->r10 = ADD32(ctx->r10, -0X2D68);
    // 0x80197A24: addu        $t7, $t1, $t5
    ctx->r15 = ADD32(ctx->r9, ctx->r13);
    // 0x80197A28: addu        $t8, $t1, $t5
    ctx->r24 = ADD32(ctx->r9, ctx->r13);
    // 0x80197A2C: addu        $t6, $t8, $t2
    ctx->r14 = ADD32(ctx->r24, ctx->r10);
    // 0x80197A30: addu        $t4, $t7, $t2
    ctx->r12 = ADD32(ctx->r15, ctx->r10);
    // 0x80197A34: lhu         $a0, 0x38($t4)
    ctx->r4 = MEM_HU(ctx->r12, 0X38);
    // 0x80197A38: lhu         $a1, 0x40($t6)
    ctx->r5 = MEM_HU(ctx->r14, 0X40);
    // 0x80197A3C: jal         0x800CD4B4
    // 0x80197A40: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    func_800CD4B4(rdram, ctx);
        goto after_5;
    // 0x80197A40: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    after_5:
    // 0x80197A44: lhu         $t3, 0x22($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X22);
    // 0x80197A48: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80197A4C: addiu       $t7, $t3, 0x2
    ctx->r15 = ADD32(ctx->r11, 0X2);
    // 0x80197A50: andi        $t4, $t7, 0xFFFF
    ctx->r12 = ctx->r15 & 0XFFFF;
    // 0x80197A54: slti        $at, $t4, 0x20
    ctx->r1 = SIGNED(ctx->r12) < 0X20 ? 1 : 0;
    // 0x80197A58: addiu       $t0, $t9, 0x80
    ctx->r8 = ADD32(ctx->r25, 0X80);
    // 0x80197A5C: sh          $t7, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r15;
    // 0x80197A60: bne         $at, $zero, L_80197A0C
    if (ctx->r1 != 0) {
        // 0x80197A64: sw          $t0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r8;
            goto L_80197A0C;
    }
    // 0x80197A64: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x80197A68: lhu         $t1, 0x20($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X20);
    // 0x80197A6C: addiu       $t5, $t1, 0x1
    ctx->r13 = ADD32(ctx->r9, 0X1);
    // 0x80197A70: andi        $t8, $t5, 0xFFFF
    ctx->r24 = ctx->r13 & 0XFFFF;
    // 0x80197A74: slti        $at, $t8, 0x4
    ctx->r1 = SIGNED(ctx->r24) < 0X4 ? 1 : 0;
    // 0x80197A78: bne         $at, $zero, L_80197A08
    if (ctx->r1 != 0) {
        // 0x80197A7C: sh          $t5, 0x20($sp)
        MEM_H(0X20, ctx->r29) = ctx->r13;
            goto L_80197A08;
    }
    // 0x80197A7C: sh          $t5, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r13;
    // 0x80197A80: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80197A84: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80197A88: lw          $t2, -0x2D58($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2D58);
    // 0x80197A8C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80197A90: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80197A94: addiu       $a0, $a0, 0x78BC
    ctx->r4 = ADD32(ctx->r4, 0X78BC);
    // 0x80197A98: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80197A9C: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x80197AA0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80197AA4: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80197AA8: jal         0x800C6C6C
    // 0x80197AAC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_6;
    // 0x80197AAC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_6:
    // 0x80197AB0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80197AB4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80197AB8: lw          $t6, -0x2D58($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2D58);
    // 0x80197ABC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80197AC0: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80197AC4: addiu       $a0, $a0, -0x4BAC
    ctx->r4 = ADD32(ctx->r4, -0X4BAC);
    // 0x80197AC8: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    // 0x80197ACC: addiu       $a2, $zero, 0x24
    ctx->r6 = ADD32(0, 0X24);
    // 0x80197AD0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80197AD4: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80197AD8: jal         0x800C6C6C
    // 0x80197ADC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_7;
    // 0x80197ADC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_7:
L_80197AE0:
    // 0x80197AE0: jal         0x800E0C80
    // 0x80197AE4: nop

    osGetTime_recomp(rdram, ctx);
        goto after_8;
    // 0x80197AE4: nop

    after_8:
    // 0x80197AE8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80197AEC: sw          $v0, -0x2D98($at)
    MEM_W(-0X2D98, ctx->r1) = ctx->r2;
    // 0x80197AF0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80197AF4: sw          $v1, -0x2D94($at)
    MEM_W(-0X2D94, ctx->r1) = ctx->r3;
    // 0x80197AF8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80197AFC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80197B00: lw          $t1, -0x2D94($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2D94);
    // 0x80197B04: lw          $t0, -0x2D98($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2D98);
    // 0x80197B08: bne         $t0, $zero, L_80197B20
    if (ctx->r8 != 0) {
        // 0x80197B0C: lui         $at, 0x2A
        ctx->r1 = S32(0X2A << 16);
            goto L_80197B20;
    }
    // 0x80197B0C: lui         $at, 0x2A
    ctx->r1 = S32(0X2A << 16);
    // 0x80197B10: ori         $at, $at, 0xB980
    ctx->r1 = ctx->r1 | 0XB980;
    // 0x80197B14: sltu        $at, $t1, $at
    ctx->r1 = ctx->r9 < ctx->r1 ? 1 : 0;
    // 0x80197B18: bne         $at, $zero, L_80197AE0
    if (ctx->r1 != 0) {
        // 0x80197B1C: nop
    
            goto L_80197AE0;
    }
    // 0x80197B1C: nop

L_80197B20:
    // 0x80197B20: addiu       $t4, $zero, 0x0
    ctx->r12 = ADD32(0, 0X0);
    // 0x80197B24: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80197B28: sw          $t4, -0x2D98($at)
    MEM_W(-0X2D98, ctx->r1) = ctx->r12;
    // 0x80197B2C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80197B30: addiu       $t5, $zero, 0x0
    ctx->r13 = ADD32(0, 0X0);
    // 0x80197B34: sw          $t5, -0x2D94($at)
    MEM_W(-0X2D94, ctx->r1) = ctx->r13;
    // 0x80197B38: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x80197B3C: jal         0x800D7A20
    // 0x80197B40: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    osSetTime_recomp(rdram, ctx);
        goto after_9;
    // 0x80197B40: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_9:
L_80197B44:
    // 0x80197B44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80197B48: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80197B4C: jr          $ra
    // 0x80197B50: nop

    return;
    // 0x80197B50: nop

;}
RECOMP_FUNC void func_80197B54_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80197B54: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80197B58: lw          $t6, -0x2D64($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2D64);
    // 0x80197B5C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80197B60: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80197B64: bne         $t6, $zero, L_80197B80
    if (ctx->r14 != 0) {
        // 0x80197B68: nop
    
            goto L_80197B80;
    }
    // 0x80197B68: nop

    // 0x80197B6C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80197B70: addiu       $t8, $t8, 0x3D00
    ctx->r24 = ADD32(ctx->r24, 0X3D00);
    // 0x80197B74: addiu       $t7, $zero, 0x4E
    ctx->r15 = ADD32(0, 0X4E);
    // 0x80197B78: b           L_80197B90
    // 0x80197B7C: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
        goto L_80197B90;
    // 0x80197B7C: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
L_80197B80:
    // 0x80197B80: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80197B84: addiu       $t0, $t0, 0x3D00
    ctx->r8 = ADD32(ctx->r8, 0X3D00);
    // 0x80197B88: addiu       $t9, $zero, 0x6C
    ctx->r25 = ADD32(0, 0X6C);
    // 0x80197B8C: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
L_80197B90:
    // 0x80197B90: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80197B94: lw          $t1, -0x2D40($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2D40);
    // 0x80197B98: sltiu       $at, $t1, 0x5
    ctx->r1 = ctx->r9 < 0X5 ? 1 : 0;
    // 0x80197B9C: beq         $at, $zero, L_80197E90
    if (ctx->r1 == 0) {
        // 0x80197BA0: nop
    
            goto L_80197E90;
    }
    // 0x80197BA0: nop

    // 0x80197BA4: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80197BA8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80197BAC: addu        $at, $at, $t1
    gpr jr_addend_80197BB4 = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80197BB0: lw          $t1, 0x960($at)
    ctx->r9 = ADD32(ctx->r1, 0X960);
    // 0x80197BB4: jr          $t1
    // 0x80197BB8: nop

    switch (jr_addend_80197BB4 >> 2) {
        case 0: goto L_80197EF0; break;
        case 1: goto L_80197BBC; break;
        case 2: goto L_80197CC4; break;
        case 3: goto L_80197D08; break;
        case 4: goto L_80197E2C; break;
        default: switch_error(__func__, 0x80197BB4, 0x801A0960);
    }
    // 0x80197BB8: nop

L_80197BBC:
    // 0x80197BBC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80197BC0: lw          $t2, -0x2D38($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2D38);
    // 0x80197BC4: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x80197BC8: bgez        $t2, L_80197BE0
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80197BCC: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80197BE0;
    }
    // 0x80197BCC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80197BD0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80197BD4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80197BD8: nop

    // 0x80197BDC: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80197BE0:
    // 0x80197BE0: lui         $at, 0x3E00
    ctx->r1 = S32(0X3E00 << 16);
    // 0x80197BE4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80197BE8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80197BEC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80197BF0: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80197BF4: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x80197BF8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80197BFC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80197C00: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80197C04: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80197C08: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x80197C0C: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80197C10: addiu       $t4, $t4, 0x3D00
    ctx->r12 = ADD32(ctx->r12, 0X3D00);
    // 0x80197C14: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80197C18: addiu       $t6, $zero, 0x64
    ctx->r14 = ADD32(0, 0X64);
    // 0x80197C1C: swc1        $f4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f4.u32l;
    // 0x80197C20: lw          $a3, 0x0($t5)
    ctx->r7 = MEM_W(ctx->r13, 0X0);
    // 0x80197C24: lw          $a2, 0x0($t4)
    ctx->r6 = MEM_W(ctx->r12, 0X0);
    // 0x80197C28: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80197C2C: addiu       $a0, $a0, 0x79B0
    ctx->r4 = ADD32(ctx->r4, 0X79B0);
    // 0x80197C30: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x80197C34: jal         0x800C6C6C
    // 0x80197C38: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_0;
    // 0x80197C38: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x80197C3C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80197C40: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80197C44: lw          $a1, -0x2D38($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X2D38);
    // 0x80197C48: lw          $t7, -0x2D3C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2D3C);
    // 0x80197C4C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80197C50: addiu       $t0, $t0, 0x3D00
    ctx->r8 = ADD32(ctx->r8, 0X3D00);
    // 0x80197C54: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80197C58: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80197C5C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80197C60: lw          $a2, 0x0($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X0);
    // 0x80197C64: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x80197C68: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80197C6C: sll         $t9, $a1, 1
    ctx->r25 = S32(ctx->r5 << 1);
    // 0x80197C70: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80197C74: addu        $a0, $a0, $t8
    ctx->r4 = ADD32(ctx->r4, ctx->r24);
    // 0x80197C78: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x80197C7C: lw          $a3, 0x0($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X0);
    // 0x80197C80: addiu       $a1, $a1, 0x12
    ctx->r5 = ADD32(ctx->r5, 0X12);
    // 0x80197C84: lw          $a0, -0xEC0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0XEC0);
    // 0x80197C88: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x80197C8C: jal         0x800C6B7C
    // 0x80197C90: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    func_800C6B7C(rdram, ctx);
        goto after_1;
    // 0x80197C90: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    after_1:
    // 0x80197C94: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80197C98: lw          $t2, -0x2D38($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2D38);
    // 0x80197C9C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80197CA0: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80197CA4: sw          $t3, -0x2D38($at)
    MEM_W(-0X2D38, ctx->r1) = ctx->r11;
    // 0x80197CA8: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80197CAC: bne         $t3, $at, L_80197E90
    if (ctx->r11 != ctx->r1) {
        // 0x80197CB0: nop
    
            goto L_80197E90;
    }
    // 0x80197CB0: nop

    // 0x80197CB4: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x80197CB8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80197CBC: b           L_80197E90
    // 0x80197CC0: sw          $t4, -0x2D40($at)
    MEM_W(-0X2D40, ctx->r1) = ctx->r12;
        goto L_80197E90;
    // 0x80197CC0: sw          $t4, -0x2D40($at)
    MEM_W(-0X2D40, ctx->r1) = ctx->r12;
L_80197CC4:
    // 0x80197CC4: jal         0x80197F00
    // 0x80197CC8: nop

    func_80197F00_1501A0(rdram, ctx);
        goto after_2;
    // 0x80197CC8: nop

    after_2:
    // 0x80197CCC: jal         0x800E4CDC
    // 0x80197CD0: nop

    func_800E4CDC(rdram, ctx);
        goto after_3;
    // 0x80197CD0: nop

    after_3:
    // 0x80197CD4: andi        $t5, $v0, 0x3F
    ctx->r13 = ctx->r2 & 0X3F;
    // 0x80197CD8: bne         $t5, $zero, L_80197E90
    if (ctx->r13 != 0) {
        // 0x80197CDC: nop
    
            goto L_80197E90;
    }
    // 0x80197CDC: nop

    // 0x80197CE0: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80197CE4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80197CE8: sw          $t6, -0x2D40($at)
    MEM_W(-0X2D40, ctx->r1) = ctx->r14;
    // 0x80197CEC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80197CF0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80197CF4: sw          $t7, -0x2D34($at)
    MEM_W(-0X2D34, ctx->r1) = ctx->r15;
    // 0x80197CF8: jal         0x800C8544
    // 0x80197CFC: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    func_800C8544(rdram, ctx);
        goto after_4;
    // 0x80197CFC: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    after_4:
    // 0x80197D00: b           L_80197E90
    // 0x80197D04: nop

        goto L_80197E90;
    // 0x80197D04: nop

L_80197D08:
    // 0x80197D08: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80197D0C: lw          $t8, -0x2D38($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2D38);
    // 0x80197D10: addiu       $t9, $zero, 0x7
    ctx->r25 = ADD32(0, 0X7);
    // 0x80197D14: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80197D18: addiu       $t1, $t1, 0x3C00
    ctx->r9 = ADD32(ctx->r9, 0X3C00);
    // 0x80197D1C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80197D20: subu        $t0, $t9, $t8
    ctx->r8 = SUB32(ctx->r25, ctx->r24);
    // 0x80197D24: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x80197D28: addiu       $t2, $t2, 0x3C00
    ctx->r10 = ADD32(ctx->r10, 0X3C00);
    // 0x80197D2C: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80197D30: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x80197D34: bgez        $t3, L_80197D4C
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80197D38: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80197D4C;
    }
    // 0x80197D38: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80197D3C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80197D40: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80197D44: nop

    // 0x80197D48: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_80197D4C:
    // 0x80197D4C: lui         $at, 0x3E00
    ctx->r1 = S32(0X3E00 << 16);
    // 0x80197D50: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80197D54: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80197D58: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80197D5C: mul.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x80197D60: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x80197D64: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80197D68: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80197D6C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80197D70: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80197D74: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x80197D78: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80197D7C: addiu       $t5, $t5, 0x3D00
    ctx->r13 = ADD32(ctx->r13, 0X3D00);
    // 0x80197D80: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80197D84: addiu       $t7, $zero, 0x64
    ctx->r15 = ADD32(0, 0X64);
    // 0x80197D88: swc1        $f10, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f10.u32l;
    // 0x80197D8C: lw          $a3, 0x0($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X0);
    // 0x80197D90: lw          $a2, 0x0($t5)
    ctx->r6 = MEM_W(ctx->r13, 0X0);
    // 0x80197D94: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80197D98: addiu       $a0, $a0, 0x79B0
    ctx->r4 = ADD32(ctx->r4, 0X79B0);
    // 0x80197D9C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x80197DA0: jal         0x800C6C6C
    // 0x80197DA4: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_5;
    // 0x80197DA4: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_5:
    // 0x80197DA8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80197DAC: addiu       $t0, $t0, 0x3C00
    ctx->r8 = ADD32(ctx->r8, 0X3C00);
    // 0x80197DB0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80197DB4: lw          $t9, -0x2D3C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2D3C);
    // 0x80197DB8: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x80197DBC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80197DC0: addiu       $t2, $t2, 0x3D00
    ctx->r10 = ADD32(ctx->r10, 0X3D00);
    // 0x80197DC4: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80197DC8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80197DCC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80197DD0: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x80197DD4: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x80197DD8: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80197DDC: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80197DE0: sll         $t1, $a1, 1
    ctx->r9 = S32(ctx->r5 << 1);
    // 0x80197DE4: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x80197DE8: addu        $a0, $a0, $t8
    ctx->r4 = ADD32(ctx->r4, ctx->r24);
    // 0x80197DEC: lw          $a3, 0x0($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X0);
    // 0x80197DF0: lw          $a0, -0xEC0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0XEC0);
    // 0x80197DF4: addiu       $a1, $a1, 0x12
    ctx->r5 = ADD32(ctx->r5, 0X12);
    // 0x80197DF8: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x80197DFC: jal         0x800C6B7C
    // 0x80197E00: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    func_800C6B7C(rdram, ctx);
        goto after_6;
    // 0x80197E00: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    after_6:
    // 0x80197E04: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80197E08: lw          $t4, -0x2D38($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2D38);
    // 0x80197E0C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80197E10: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80197E14: sw          $t5, -0x2D38($at)
    MEM_W(-0X2D38, ctx->r1) = ctx->r13;
    // 0x80197E18: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80197E1C: bne         $t5, $at, L_80197E90
    if (ctx->r13 != ctx->r1) {
        // 0x80197E20: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_80197E90;
    }
    // 0x80197E20: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80197E24: b           L_80197E90
    // 0x80197E28: sw          $zero, -0x2D40($at)
    MEM_W(-0X2D40, ctx->r1) = 0;
        goto L_80197E90;
    // 0x80197E28: sw          $zero, -0x2D40($at)
    MEM_W(-0X2D40, ctx->r1) = 0;
L_80197E2C:
    // 0x80197E2C: jal         0x80197F00
    // 0x80197E30: nop

    func_80197F00_1501A0(rdram, ctx);
        goto after_7;
    // 0x80197E30: nop

    after_7:
    // 0x80197E34: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80197E38: addiu       $t6, $t6, 0x3D00
    ctx->r14 = ADD32(ctx->r14, 0X3D00);
    // 0x80197E3C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80197E40: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80197E44: lw          $a2, 0x0($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X0);
    // 0x80197E48: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80197E4C: addiu       $t7, $zero, 0x32
    ctx->r15 = ADD32(0, 0X32);
    // 0x80197E50: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80197E54: addiu       $a0, $a0, 0x7A54
    ctx->r4 = ADD32(ctx->r4, 0X7A54);
    // 0x80197E58: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x80197E5C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80197E60: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x80197E64: jal         0x800C6C6C
    // 0x80197E68: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_8;
    // 0x80197E68: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_8:
    // 0x80197E6C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80197E70: lw          $t9, -0x2D34($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2D34);
    // 0x80197E74: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80197E78: addiu       $t8, $t9, -0x1
    ctx->r24 = ADD32(ctx->r25, -0X1);
    // 0x80197E7C: bne         $t8, $zero, L_80197E90
    if (ctx->r24 != 0) {
        // 0x80197E80: sw          $t8, -0x2D34($at)
        MEM_W(-0X2D34, ctx->r1) = ctx->r24;
            goto L_80197E90;
    }
    // 0x80197E80: sw          $t8, -0x2D34($at)
    MEM_W(-0X2D34, ctx->r1) = ctx->r24;
    // 0x80197E84: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x80197E88: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80197E8C: sw          $t0, -0x2D40($at)
    MEM_W(-0X2D40, ctx->r1) = ctx->r8;
L_80197E90:
    // 0x80197E90: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80197E94: addiu       $t1, $t1, -0x2E18
    ctx->r9 = ADD32(ctx->r9, -0X2E18);
    // 0x80197E98: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x80197E9C: andi        $t3, $t2, 0x20
    ctx->r11 = ctx->r10 & 0X20;
    // 0x80197EA0: beq         $t3, $zero, L_80197EC4
    if (ctx->r11 == 0) {
        // 0x80197EA4: nop
    
            goto L_80197EC4;
    }
    // 0x80197EA4: nop

    // 0x80197EA8: andi        $t4, $t2, 0x1F
    ctx->r12 = ctx->r10 & 0X1F;
    // 0x80197EAC: sll         $t5, $t4, 11
    ctx->r13 = S32(ctx->r12 << 11);
    // 0x80197EB0: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80197EB4: addiu       $t7, $t7, 0x7990
    ctx->r15 = ADD32(ctx->r15, 0X7990);
    // 0x80197EB8: ori         $t6, $t5, 0x1
    ctx->r14 = ctx->r13 | 0X1;
    // 0x80197EBC: b           L_80197EF0
    // 0x80197EC0: sh          $t6, 0xE($t7)
    MEM_H(0XE, ctx->r15) = ctx->r14;
        goto L_80197EF0;
    // 0x80197EC0: sh          $t6, 0xE($t7)
    MEM_H(0XE, ctx->r15) = ctx->r14;
L_80197EC4:
    // 0x80197EC4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80197EC8: addiu       $t9, $t9, -0x2E18
    ctx->r25 = ADD32(ctx->r25, -0X2E18);
    // 0x80197ECC: lw          $t8, 0x4($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X4);
    // 0x80197ED0: addiu       $t1, $zero, 0x1F
    ctx->r9 = ADD32(0, 0X1F);
    // 0x80197ED4: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80197ED8: andi        $t0, $t8, 0x1F
    ctx->r8 = ctx->r24 & 0X1F;
    // 0x80197EDC: subu        $t3, $t1, $t0
    ctx->r11 = SUB32(ctx->r9, ctx->r8);
    // 0x80197EE0: sll         $t2, $t3, 11
    ctx->r10 = S32(ctx->r11 << 11);
    // 0x80197EE4: ori         $t4, $t2, 0x1
    ctx->r12 = ctx->r10 | 0X1;
    // 0x80197EE8: addiu       $t5, $t5, 0x7990
    ctx->r13 = ADD32(ctx->r13, 0X7990);
    // 0x80197EEC: sh          $t4, 0xE($t5)
    MEM_H(0XE, ctx->r13) = ctx->r12;
L_80197EF0:
    // 0x80197EF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80197EF4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80197EF8: jr          $ra
    // 0x80197EFC: nop

    return;
    // 0x80197EFC: nop

;}
RECOMP_FUNC void func_80197F00_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80197F00: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80197F04: lw          $t6, -0x2D3C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2D3C);
    // 0x80197F08: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80197F0C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80197F10: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x80197F14: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80197F18: addiu       $t9, $t9, -0xE84
    ctx->r25 = ADD32(ctx->r25, -0XE84);
    // 0x80197F1C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80197F20: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80197F24: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80197F28: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80197F2C: addiu       $t4, $t4, 0x3D00
    ctx->r12 = ADD32(ctx->r12, 0X3D00);
    // 0x80197F30: addiu       $t2, $t1, 0x20
    ctx->r10 = ADD32(ctx->r9, 0X20);
    // 0x80197F34: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x80197F38: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x80197F3C: lw          $t3, 0x4($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X4);
    // 0x80197F40: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80197F44: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80197F48: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x80197F4C: addiu       $t7, $t6, 0x10
    ctx->r15 = ADD32(ctx->r14, 0X10);
    // 0x80197F50: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x80197F54: lw          $a2, 0x0($t4)
    ctx->r6 = MEM_W(ctx->r12, 0X0);
    // 0x80197F58: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x80197F5C: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80197F60: addiu       $a0, $a0, 0x79B0
    ctx->r4 = ADD32(ctx->r4, 0X79B0);
    // 0x80197F64: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80197F68: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x80197F6C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80197F70: jal         0x800C6C6C
    // 0x80197F74: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_0;
    // 0x80197F74: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80197F78: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80197F7C: lw          $t9, -0x2D3C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2D3C);
    // 0x80197F80: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80197F84: addiu       $t2, $t2, 0x3D00
    ctx->r10 = ADD32(ctx->r10, 0X3D00);
    // 0x80197F88: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80197F8C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80197F90: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x80197F94: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80197F98: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x80197F9C: addu        $a0, $a0, $t1
    ctx->r4 = ADD32(ctx->r4, ctx->r9);
    // 0x80197FA0: lw          $a0, -0xEC0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0XEC0);
    // 0x80197FA4: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x80197FA8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80197FAC: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x80197FB0: jal         0x800C6B7C
    // 0x80197FB4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800C6B7C(rdram, ctx);
        goto after_1;
    // 0x80197FB4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x80197FB8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80197FBC: lw          $t0, -0x2D4C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2D4C);
    // 0x80197FC0: andi        $t3, $t0, 0x3
    ctx->r11 = ctx->r8 & 0X3;
    // 0x80197FC4: beq         $t3, $zero, L_80198014
    if (ctx->r11 == 0) {
        // 0x80197FC8: nop
    
            goto L_80198014;
    }
    // 0x80197FC8: nop

    // 0x80197FCC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80197FD0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80197FD4: lw          $t7, -0x2D4C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2D4C);
    // 0x80197FD8: lw          $t5, -0x2D3C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2D3C);
    // 0x80197FDC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80197FE0: andi        $t4, $t7, 0x3
    ctx->r12 = ctx->r15 & 0X3;
    // 0x80197FE4: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80197FE8: addu        $t8, $t6, $t4
    ctx->r24 = ADD32(ctx->r14, ctx->r12);
    // 0x80197FEC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80197FF0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80197FF4: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80197FF8: addu        $a0, $a0, $t9
    ctx->r4 = ADD32(ctx->r4, ctx->r25);
    // 0x80197FFC: lw          $a0, -0xEB4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0XEB4);
    // 0x80198000: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80198004: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80198008: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8019800C: jal         0x800C6B7C
    // 0x80198010: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800C6B7C(rdram, ctx);
        goto after_2;
    // 0x80198010: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_2:
L_80198014:
    // 0x80198014: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80198018: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8019801C: jr          $ra
    // 0x80198020: nop

    return;
    // 0x80198020: nop

;}
RECOMP_FUNC void func_80198024_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80198024: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80198028: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8019802C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80198030: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x80198034: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80198038: addiu       $t6, $t6, 0x3C00
    ctx->r14 = ADD32(ctx->r14, 0X3C00);
    // 0x8019803C: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
    // 0x80198040: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
L_80198044:
    // 0x80198044: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x80198048: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8019804C: addiu       $t9, $t9, -0x2A28
    ctx->r25 = ADD32(ctx->r25, -0X2A28);
    // 0x80198050: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80198054: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80198058: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8019805C: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80198060: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80198064: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80198068: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8019806C: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80198070: lhu         $t1, 0x0($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X0);
    // 0x80198074: ori         $at, $zero, 0x8800
    ctx->r1 = 0 | 0X8800;
    // 0x80198078: andi        $t2, $t1, 0x8800
    ctx->r10 = ctx->r9 & 0X8800;
    // 0x8019807C: bne         $t2, $at, L_80198220
    if (ctx->r10 != ctx->r1) {
        // 0x80198080: nop
    
            goto L_80198220;
    }
    // 0x80198080: nop

    // 0x80198084: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x80198088: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8019808C: lwc1        $f4, 0x60($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X60);
    // 0x80198090: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80198094: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x80198098: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8019809C: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x801980A0: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x801980A4: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x801980A8: lwc1        $f6, 0xFB0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0XFB0);
    // 0x801980AC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x801980B0: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x801980B4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801980B8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801980BC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x801980C0: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x801980C4: swc1        $f8, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f8.u32l;
    // 0x801980C8: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x801980CC: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x801980D0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x801980D4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801980D8: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x801980DC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801980E0: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x801980E4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801980E8: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x801980EC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x801980F0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801980F4: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x801980F8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x801980FC: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80198100: lwc1        $f10, -0x29C4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X29C4);
    // 0x80198104: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80198108: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x8019810C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80198110: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80198114: lwc1        $f16, 0xFB4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0XFB4);
    // 0x80198118: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8019811C: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x80198120: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80198124: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80198128: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x8019812C: swc1        $f18, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->f18.u32l;
    // 0x80198130: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x80198134: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x80198138: sll         $t0, $t2, 2
    ctx->r8 = S32(ctx->r10 << 2);
    // 0x8019813C: addu        $t0, $t0, $t2
    ctx->r8 = ADD32(ctx->r8, ctx->r10);
    // 0x80198140: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80198144: subu        $t0, $t0, $t2
    ctx->r8 = SUB32(ctx->r8, ctx->r10);
    // 0x80198148: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8019814C: addu        $t0, $t0, $t2
    ctx->r8 = ADD32(ctx->r8, ctx->r10);
    // 0x80198150: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80198154: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80198158: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x8019815C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80198160: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80198164: lwc1        $f4, -0x29C0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X29C0);
    // 0x80198168: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8019816C: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x80198170: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80198174: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x80198178: lwc1        $f6, 0xFB8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0XFB8);
    // 0x8019817C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80198180: swc1        $f8, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->f8.u32l;
    // 0x80198184: lwc1        $f10, 0x0($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X0);
    // 0x80198188: lwc1        $f18, 0x4($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X4);
    // 0x8019818C: lwc1        $f8, 0x8($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X8);
    // 0x80198190: mul.s       $f16, $f10, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x80198194: nop

    // 0x80198198: mul.s       $f4, $f18, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x8019819C: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x801981A0: mul.s       $f10, $f8, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x801981A4: jal         0x800D68E0
    // 0x801981A8: add.s       $f12, $f10, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x801981A8: add.s       $f12, $f10, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f6.fl;
    after_0:
    // 0x801981AC: lui         $at, 0x43AF
    ctx->r1 = S32(0X43AF << 16);
    // 0x801981B0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801981B4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801981B8: lwc1        $f16, -0x2E30($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x801981BC: mul.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x801981C0: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x801981C4: nop

    // 0x801981C8: bc1f        L_80198220
    if (!c1cs) {
        // 0x801981CC: nop
    
            goto L_80198220;
    }
    // 0x801981CC: nop

    // 0x801981D0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801981D4: addiu       $t7, $t7, 0x3C00
    ctx->r15 = ADD32(ctx->r15, 0X3C00);
    // 0x801981D8: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x801981DC: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x801981E0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x801981E4: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x801981E8: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x801981EC: sb          $zero, 0x400($at)
    MEM_B(0X400, ctx->r1) = 0;
    // 0x801981F0: addiu       $t2, $t2, 0x3C00
    ctx->r10 = ADD32(ctx->r10, 0X3C00);
    // 0x801981F4: lw          $t0, 0x0($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X0);
    // 0x801981F8: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x801981FC: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80198200: sll         $t3, $t0, 1
    ctx->r11 = S32(ctx->r8 << 1);
    // 0x80198204: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x80198208: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8019820C: addiu       $t4, $t4, 0x3C00
    ctx->r12 = ADD32(ctx->r12, 0X3C00);
    // 0x80198210: sb          $t1, 0x401($at)
    MEM_B(0X401, ctx->r1) = ctx->r9;
    // 0x80198214: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x80198218: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8019821C: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
L_80198220:
    // 0x80198220: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x80198224: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80198228: sltiu       $at, $t8, 0x30
    ctx->r1 = ctx->r24 < 0X30 ? 1 : 0;
    // 0x8019822C: bne         $at, $zero, L_80198044
    if (ctx->r1 != 0) {
        // 0x80198230: sw          $t8, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r24;
            goto L_80198044;
    }
    // 0x80198230: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
    // 0x80198234: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x80198238: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8019823C: sll         $t2, $t9, 2
    ctx->r10 = S32(ctx->r25 << 2);
    // 0x80198240: subu        $t2, $t2, $t9
    ctx->r10 = SUB32(ctx->r10, ctx->r25);
    // 0x80198244: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80198248: addu        $t2, $t2, $t9
    ctx->r10 = ADD32(ctx->r10, ctx->r25);
    // 0x8019824C: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x80198250: addu        $t0, $t0, $t2
    ctx->r8 = ADD32(ctx->r8, ctx->r10);
    // 0x80198254: lw          $t0, 0xF98($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XF98);
    // 0x80198258: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x8019825C: sltiu       $at, $t1, 0xD
    ctx->r1 = ctx->r9 < 0XD ? 1 : 0;
    // 0x80198260: beq         $at, $zero, L_80198468
    if (ctx->r1 == 0) {
        // 0x80198264: nop
    
            goto L_80198468;
    }
    // 0x80198264: nop

    // 0x80198268: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8019826C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80198270: addu        $at, $at, $t1
    gpr jr_addend_80198278 = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80198274: lw          $t1, 0x974($at)
    ctx->r9 = ADD32(ctx->r1, 0X974);
    // 0x80198278: jr          $t1
    // 0x8019827C: nop

    switch (jr_addend_80198278 >> 2) {
        case 0: goto L_80198280; break;
        case 1: goto L_80198280; break;
        case 2: goto L_80198280; break;
        case 3: goto L_80198280; break;
        case 4: goto L_80198280; break;
        case 5: goto L_80198280; break;
        case 6: goto L_80198468; break;
        case 7: goto L_80198468; break;
        case 8: goto L_80198468; break;
        case 9: goto L_80198468; break;
        case 10: goto L_80198468; break;
        case 11: goto L_80198468; break;
        case 12: goto L_80198280; break;
        default: switch_error(__func__, 0x80198278, 0x801A0974);
    }
    // 0x8019827C: nop

L_80198280:
    // 0x80198280: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
L_80198284:
    // 0x80198284: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x80198288: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    // 0x8019828C: beq         $t3, $t5, L_80198454
    if (ctx->r11 == ctx->r13) {
        // 0x80198290: nop
    
            goto L_80198454;
    }
    // 0x80198290: nop

    // 0x80198294: sll         $t6, $t3, 2
    ctx->r14 = S32(ctx->r11 << 2);
    // 0x80198298: subu        $t6, $t6, $t3
    ctx->r14 = SUB32(ctx->r14, ctx->r11);
    // 0x8019829C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801982A0: addu        $t6, $t6, $t3
    ctx->r14 = ADD32(ctx->r14, ctx->r11);
    // 0x801982A4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x801982A8: addiu       $t4, $t4, 0xF98
    ctx->r12 = ADD32(ctx->r12, 0XF98);
    // 0x801982AC: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x801982B0: addu        $t7, $t6, $t4
    ctx->r15 = ADD32(ctx->r14, ctx->r12);
    // 0x801982B4: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x801982B8: sltiu       $at, $t8, 0x28
    ctx->r1 = ctx->r24 < 0X28 ? 1 : 0;
    // 0x801982BC: bne         $at, $zero, L_80198454
    if (ctx->r1 != 0) {
        // 0x801982C0: addiu       $at, $zero, 0x43
        ctx->r1 = ADD32(0, 0X43);
            goto L_80198454;
    }
    // 0x801982C0: addiu       $at, $zero, 0x43
    ctx->r1 = ADD32(0, 0X43);
    // 0x801982C4: beq         $t8, $at, L_80198454
    if (ctx->r24 == ctx->r1) {
        // 0x801982C8: nop
    
            goto L_80198454;
    }
    // 0x801982C8: nop

    // 0x801982CC: sll         $t9, $t5, 2
    ctx->r25 = S32(ctx->r13 << 2);
    // 0x801982D0: subu        $t9, $t9, $t5
    ctx->r25 = SUB32(ctx->r25, ctx->r13);
    // 0x801982D4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x801982D8: addu        $t9, $t9, $t5
    ctx->r25 = ADD32(ctx->r25, ctx->r13);
    // 0x801982DC: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x801982E0: addu        $t2, $t9, $t4
    ctx->r10 = ADD32(ctx->r25, ctx->r12);
    // 0x801982E4: lwc1        $f10, 0x18($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X18);
    // 0x801982E8: lwc1        $f8, 0x18($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X18);
    // 0x801982EC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x801982F0: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x801982F4: sub.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801982F8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801982FC: addiu       $t6, $t6, 0xF98
    ctx->r14 = ADD32(ctx->r14, 0XF98);
    // 0x80198300: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80198304: swc1        $f6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f6.u32l;
    // 0x80198308: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x8019830C: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x80198310: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x80198314: sll         $t5, $t7, 2
    ctx->r13 = S32(ctx->r15 << 2);
    // 0x80198318: sll         $t3, $t1, 2
    ctx->r11 = S32(ctx->r9 << 2);
    // 0x8019831C: subu        $t5, $t5, $t7
    ctx->r13 = SUB32(ctx->r13, ctx->r15);
    // 0x80198320: subu        $t3, $t3, $t1
    ctx->r11 = SUB32(ctx->r11, ctx->r9);
    // 0x80198324: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80198328: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8019832C: addu        $t5, $t5, $t7
    ctx->r13 = ADD32(ctx->r13, ctx->r15);
    // 0x80198330: addu        $t3, $t3, $t1
    ctx->r11 = ADD32(ctx->r11, ctx->r9);
    // 0x80198334: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x80198338: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8019833C: addu        $t9, $t5, $t6
    ctx->r25 = ADD32(ctx->r13, ctx->r14);
    // 0x80198340: addu        $t8, $t3, $t6
    ctx->r24 = ADD32(ctx->r11, ctx->r14);
    // 0x80198344: lwc1        $f18, 0x1C($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X1C);
    // 0x80198348: lwc1        $f16, 0x1C($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X1C);
    // 0x8019834C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80198350: addiu       $t1, $t1, 0xF98
    ctx->r9 = ADD32(ctx->r9, 0XF98);
    // 0x80198354: sub.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x80198358: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8019835C: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x80198360: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80198364: swc1        $f4, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->f4.u32l;
    // 0x80198368: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x8019836C: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x80198370: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x80198374: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x80198378: sll         $t0, $t2, 2
    ctx->r8 = S32(ctx->r10 << 2);
    // 0x8019837C: subu        $t7, $t7, $t8
    ctx->r15 = SUB32(ctx->r15, ctx->r24);
    // 0x80198380: subu        $t0, $t0, $t2
    ctx->r8 = SUB32(ctx->r8, ctx->r10);
    // 0x80198384: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80198388: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8019838C: addu        $t7, $t7, $t8
    ctx->r15 = ADD32(ctx->r15, ctx->r24);
    // 0x80198390: addu        $t0, $t0, $t2
    ctx->r8 = ADD32(ctx->r8, ctx->r10);
    // 0x80198394: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x80198398: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8019839C: addu        $t5, $t7, $t1
    ctx->r13 = ADD32(ctx->r15, ctx->r9);
    // 0x801983A0: addu        $t3, $t0, $t1
    ctx->r11 = ADD32(ctx->r8, ctx->r9);
    // 0x801983A4: lwc1        $f8, 0x20($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X20);
    // 0x801983A8: lwc1        $f10, 0x20($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X20);
    // 0x801983AC: sub.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801983B0: swc1        $f6, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f6.u32l;
    // 0x801983B4: lwc1        $f18, 0x0($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X0);
    // 0x801983B8: lwc1        $f4, 0x4($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X4);
    // 0x801983BC: lwc1        $f6, 0x8($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X8);
    // 0x801983C0: mul.s       $f16, $f18, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x801983C4: nop

    // 0x801983C8: mul.s       $f8, $f4, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x801983CC: add.s       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x801983D0: mul.s       $f18, $f6, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x801983D4: jal         0x800D68E0
    // 0x801983D8: add.s       $f12, $f18, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x801983D8: add.s       $f12, $f18, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f10.fl;
    after_1:
    // 0x801983DC: lui         $at, 0x43AF
    ctx->r1 = S32(0X43AF << 16);
    // 0x801983E0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801983E4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801983E8: lwc1        $f16, -0x2E30($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x801983EC: mul.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x801983F0: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x801983F4: nop

    // 0x801983F8: bc1f        L_80198454
    if (!c1cs) {
        // 0x801983FC: nop
    
            goto L_80198454;
    }
    // 0x801983FC: nop

    // 0x80198400: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80198404: addiu       $t2, $t2, 0x3C00
    ctx->r10 = ADD32(ctx->r10, 0X3C00);
    // 0x80198408: lw          $t0, 0x0($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X0);
    // 0x8019840C: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80198410: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80198414: sll         $t3, $t0, 1
    ctx->r11 = S32(ctx->r8 << 1);
    // 0x80198418: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x8019841C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80198420: sb          $t4, 0x400($at)
    MEM_B(0X400, ctx->r1) = ctx->r12;
    // 0x80198424: addiu       $t7, $t7, 0x3C00
    ctx->r15 = ADD32(ctx->r15, 0X3C00);
    // 0x80198428: lw          $t1, 0x0($t7)
    ctx->r9 = MEM_W(ctx->r15, 0X0);
    // 0x8019842C: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x80198430: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80198434: sll         $t5, $t1, 1
    ctx->r13 = S32(ctx->r9 << 1);
    // 0x80198438: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x8019843C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80198440: addiu       $t6, $t6, 0x3C00
    ctx->r14 = ADD32(ctx->r14, 0X3C00);
    // 0x80198444: sb          $t8, 0x401($at)
    MEM_B(0X401, ctx->r1) = ctx->r24;
    // 0x80198448: lw          $t9, 0x0($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X0);
    // 0x8019844C: addiu       $t2, $t9, 0x1
    ctx->r10 = ADD32(ctx->r25, 0X1);
    // 0x80198450: sw          $t2, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r10;
L_80198454:
    // 0x80198454: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x80198458: addiu       $t4, $t0, 0x1
    ctx->r12 = ADD32(ctx->r8, 0X1);
    // 0x8019845C: sltiu       $at, $t4, 0x30
    ctx->r1 = ctx->r12 < 0X30 ? 1 : 0;
    // 0x80198460: bne         $at, $zero, L_80198284
    if (ctx->r1 != 0) {
        // 0x80198464: sw          $t4, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r12;
            goto L_80198284;
    }
    // 0x80198464: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
L_80198468:
    // 0x80198468: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8019846C: addiu       $t3, $t3, 0x3C00
    ctx->r11 = ADD32(ctx->r11, 0X3C00);
    // 0x80198470: lw          $t7, 0x0($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X0);
    // 0x80198474: sltiu       $at, $t7, 0x2
    ctx->r1 = ctx->r15 < 0X2 ? 1 : 0;
    // 0x80198478: bne         $at, $zero, L_801986F4
    if (ctx->r1 != 0) {
        // 0x8019847C: nop
    
            goto L_801986F4;
    }
    // 0x8019847C: nop

    // 0x80198480: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x80198484: lw          $t1, 0x0($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X0);
    // 0x80198488: addiu       $t8, $t1, -0x1
    ctx->r24 = ADD32(ctx->r9, -0X1);
    // 0x8019848C: beq         $t8, $zero, L_801986F4
    if (ctx->r24 == 0) {
        // 0x80198490: nop
    
            goto L_801986F4;
    }
    // 0x80198490: nop

L_80198494:
    // 0x80198494: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x80198498: lui         $t2, 0x800C
    ctx->r10 = S32(0X800C << 16);
    // 0x8019849C: addiu       $t2, $t2, 0x400
    ctx->r10 = ADD32(ctx->r10, 0X400);
    // 0x801984A0: sll         $t9, $t5, 1
    ctx->r25 = S32(ctx->r13 << 1);
    // 0x801984A4: addu        $t6, $t9, $t2
    ctx->r14 = ADD32(ctx->r25, ctx->r10);
    // 0x801984A8: lbu         $t0, 0x0($t6)
    ctx->r8 = MEM_BU(ctx->r14, 0X0);
    // 0x801984AC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801984B0: bne         $t0, $at, L_801984EC
    if (ctx->r8 != ctx->r1) {
        // 0x801984B4: nop
    
            goto L_801984EC;
    }
    // 0x801984B4: nop

    // 0x801984B8: lbu         $t4, 0x1($t6)
    ctx->r12 = MEM_BU(ctx->r14, 0X1);
    // 0x801984BC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801984C0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x801984C4: sll         $t7, $t4, 2
    ctx->r15 = S32(ctx->r12 << 2);
    // 0x801984C8: subu        $t7, $t7, $t4
    ctx->r15 = SUB32(ctx->r15, ctx->r12);
    // 0x801984CC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801984D0: addu        $t7, $t7, $t4
    ctx->r15 = ADD32(ctx->r15, ctx->r12);
    // 0x801984D4: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x801984D8: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x801984DC: lwc1        $f6, 0xFCC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0XFCC);
    // 0x801984E0: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x801984E4: b           L_80198534
    // 0x801984E8: swc1        $f6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f6.u32l;
        goto L_80198534;
    // 0x801984E8: swc1        $f6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f6.u32l;
L_801984EC:
    // 0x801984EC: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x801984F0: lui         $t5, 0x800C
    ctx->r13 = S32(0X800C << 16);
    // 0x801984F4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801984F8: sll         $t8, $t1, 1
    ctx->r24 = S32(ctx->r9 << 1);
    // 0x801984FC: addu        $t5, $t5, $t8
    ctx->r13 = ADD32(ctx->r13, ctx->r24);
    // 0x80198500: lbu         $t5, 0x401($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X401);
    // 0x80198504: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80198508: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x8019850C: sll         $t9, $t5, 2
    ctx->r25 = S32(ctx->r13 << 2);
    // 0x80198510: addu        $t9, $t9, $t5
    ctx->r25 = ADD32(ctx->r25, ctx->r13);
    // 0x80198514: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80198518: subu        $t9, $t9, $t5
    ctx->r25 = SUB32(ctx->r25, ctx->r13);
    // 0x8019851C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80198520: addu        $t9, $t9, $t5
    ctx->r25 = ADD32(ctx->r25, ctx->r13);
    // 0x80198524: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80198528: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8019852C: lwc1        $f18, -0x2994($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2994);
    // 0x80198530: swc1        $f18, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f18.u32l;
L_80198534:
    // 0x80198534: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x80198538: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8019853C: addiu       $t4, $t4, 0x3C00
    ctx->r12 = ADD32(ctx->r12, 0X3C00);
    // 0x80198540: addiu       $t6, $t0, 0x1
    ctx->r14 = ADD32(ctx->r8, 0X1);
    // 0x80198544: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    // 0x80198548: lw          $t7, 0x0($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X0);
    // 0x8019854C: sltu        $at, $t6, $t7
    ctx->r1 = ctx->r14 < ctx->r15 ? 1 : 0;
    // 0x80198550: beq         $at, $zero, L_801986CC
    if (ctx->r1 == 0) {
        // 0x80198554: nop
    
            goto L_801986CC;
    }
    // 0x80198554: nop

L_80198558:
    // 0x80198558: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x8019855C: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x80198560: addiu       $t8, $t8, 0x400
    ctx->r24 = ADD32(ctx->r24, 0X400);
    // 0x80198564: sll         $t1, $t3, 1
    ctx->r9 = S32(ctx->r11 << 1);
    // 0x80198568: addu        $t5, $t1, $t8
    ctx->r13 = ADD32(ctx->r9, ctx->r24);
    // 0x8019856C: lbu         $t9, 0x0($t5)
    ctx->r25 = MEM_BU(ctx->r13, 0X0);
    // 0x80198570: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80198574: bne         $t9, $at, L_801985B0
    if (ctx->r25 != ctx->r1) {
        // 0x80198578: nop
    
            goto L_801985B0;
    }
    // 0x80198578: nop

    // 0x8019857C: lbu         $t2, 0x1($t5)
    ctx->r10 = MEM_BU(ctx->r13, 0X1);
    // 0x80198580: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80198584: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80198588: sll         $t0, $t2, 2
    ctx->r8 = S32(ctx->r10 << 2);
    // 0x8019858C: subu        $t0, $t0, $t2
    ctx->r8 = SUB32(ctx->r8, ctx->r10);
    // 0x80198590: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80198594: addu        $t0, $t0, $t2
    ctx->r8 = ADD32(ctx->r8, ctx->r10);
    // 0x80198598: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x8019859C: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x801985A0: lwc1        $f10, 0xFCC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0XFCC);
    // 0x801985A4: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x801985A8: b           L_801985F8
    // 0x801985AC: swc1        $f10, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->f10.u32l;
        goto L_801985F8;
    // 0x801985AC: swc1        $f10, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->f10.u32l;
L_801985B0:
    // 0x801985B0: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x801985B4: lui         $t3, 0x800C
    ctx->r11 = S32(0X800C << 16);
    // 0x801985B8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801985BC: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x801985C0: addu        $t3, $t3, $t7
    ctx->r11 = ADD32(ctx->r11, ctx->r15);
    // 0x801985C4: lbu         $t3, 0x401($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X401);
    // 0x801985C8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x801985CC: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x801985D0: sll         $t1, $t3, 2
    ctx->r9 = S32(ctx->r11 << 2);
    // 0x801985D4: addu        $t1, $t1, $t3
    ctx->r9 = ADD32(ctx->r9, ctx->r11);
    // 0x801985D8: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x801985DC: subu        $t1, $t1, $t3
    ctx->r9 = SUB32(ctx->r9, ctx->r11);
    // 0x801985E0: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x801985E4: addu        $t1, $t1, $t3
    ctx->r9 = ADD32(ctx->r9, ctx->r11);
    // 0x801985E8: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x801985EC: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x801985F0: lwc1        $f4, -0x2994($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2994);
    // 0x801985F4: swc1        $f4, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f4.u32l;
L_801985F8:
    // 0x801985F8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801985FC: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x80198600: lwc1        $f16, 0x0($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X0);
    // 0x80198604: lwc1        $f8, 0x4($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X4);
    // 0x80198608: c.lt.s      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.fl < ctx->f16.fl;
    // 0x8019860C: nop

    // 0x80198610: bc1f        L_801986A8
    if (!c1cs) {
        // 0x80198614: nop
    
            goto L_801986A8;
    }
    // 0x80198614: nop

    // 0x80198618: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x8019861C: lui         $t0, 0x800C
    ctx->r8 = S32(0X800C << 16);
    // 0x80198620: addiu       $t0, $t0, 0x400
    ctx->r8 = ADD32(ctx->r8, 0X400);
    // 0x80198624: sll         $t2, $t5, 1
    ctx->r10 = S32(ctx->r13 << 1);
    // 0x80198628: addu        $t4, $t2, $t0
    ctx->r12 = ADD32(ctx->r10, ctx->r8);
    // 0x8019862C: lbu         $t6, 0x0($t4)
    ctx->r14 = MEM_BU(ctx->r12, 0X0);
    // 0x80198630: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x80198634: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80198638: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    // 0x8019863C: lbu         $t7, 0x1($t4)
    ctx->r15 = MEM_BU(ctx->r12, 0X1);
    // 0x80198640: sll         $t1, $t3, 1
    ctx->r9 = S32(ctx->r11 << 1);
    // 0x80198644: addu        $t8, $t1, $t0
    ctx->r24 = ADD32(ctx->r9, ctx->r8);
    // 0x80198648: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x8019864C: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x80198650: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x80198654: addiu       $t6, $t6, 0x400
    ctx->r14 = ADD32(ctx->r14, 0X400);
    // 0x80198658: sb          $t9, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r25;
    // 0x8019865C: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x80198660: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x80198664: sll         $t2, $t5, 1
    ctx->r10 = S32(ctx->r13 << 1);
    // 0x80198668: addu        $t7, $t2, $t6
    ctx->r15 = ADD32(ctx->r10, ctx->r14);
    // 0x8019866C: lbu         $t3, 0x1($t7)
    ctx->r11 = MEM_BU(ctx->r15, 0X1);
    // 0x80198670: sll         $t0, $t1, 1
    ctx->r8 = S32(ctx->r9 << 1);
    // 0x80198674: addu        $t8, $t0, $t6
    ctx->r24 = ADD32(ctx->r8, ctx->r14);
    // 0x80198678: sb          $t3, 0x1($t8)
    MEM_B(0X1, ctx->r24) = ctx->r11;
    // 0x8019867C: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x80198680: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x80198684: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x80198688: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x8019868C: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x80198690: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80198694: sb          $t9, 0x400($at)
    MEM_B(0X400, ctx->r1) = ctx->r25;
    // 0x80198698: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8019869C: sll         $t1, $t7, 1
    ctx->r9 = S32(ctx->r15 << 1);
    // 0x801986A0: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x801986A4: sb          $t2, 0x401($at)
    MEM_B(0X401, ctx->r1) = ctx->r10;
L_801986A8:
    // 0x801986A8: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x801986AC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x801986B0: addiu       $t3, $t3, 0x3C00
    ctx->r11 = ADD32(ctx->r11, 0X3C00);
    // 0x801986B4: addiu       $t6, $t0, 0x1
    ctx->r14 = ADD32(ctx->r8, 0X1);
    // 0x801986B8: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    // 0x801986BC: lw          $t8, 0x0($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X0);
    // 0x801986C0: sltu        $at, $t6, $t8
    ctx->r1 = ctx->r14 < ctx->r24 ? 1 : 0;
    // 0x801986C4: bne         $at, $zero, L_80198558
    if (ctx->r1 != 0) {
        // 0x801986C8: nop
    
            goto L_80198558;
    }
    // 0x801986C8: nop

L_801986CC:
    // 0x801986CC: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x801986D0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x801986D4: addiu       $t5, $t5, 0x3C00
    ctx->r13 = ADD32(ctx->r13, 0X3C00);
    // 0x801986D8: addiu       $t9, $t4, 0x1
    ctx->r25 = ADD32(ctx->r12, 0X1);
    // 0x801986DC: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x801986E0: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x801986E4: addiu       $t2, $t7, -0x1
    ctx->r10 = ADD32(ctx->r15, -0X1);
    // 0x801986E8: sltu        $at, $t9, $t2
    ctx->r1 = ctx->r25 < ctx->r10 ? 1 : 0;
    // 0x801986EC: bne         $at, $zero, L_80198494
    if (ctx->r1 != 0) {
        // 0x801986F0: nop
    
            goto L_80198494;
    }
    // 0x801986F0: nop

L_801986F4:
    // 0x801986F4: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x801986F8: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x801986FC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80198700: sll         $t0, $t1, 2
    ctx->r8 = S32(ctx->r9 << 2);
    // 0x80198704: subu        $t0, $t0, $t1
    ctx->r8 = SUB32(ctx->r8, ctx->r9);
    // 0x80198708: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8019870C: addu        $t0, $t0, $t1
    ctx->r8 = ADD32(ctx->r8, ctx->r9);
    // 0x80198710: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x80198714: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80198718: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x8019871C: lwc1        $f18, 0xFCC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0XFCC);
    // 0x80198720: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x80198724: c.lt.s      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.fl < ctx->f18.fl;
    // 0x80198728: nop

    // 0x8019872C: bc1f        L_8019873C
    if (!c1cs) {
        // 0x80198730: nop
    
            goto L_8019873C;
    }
    // 0x80198730: nop

    // 0x80198734: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80198738: sw          $t3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r11;
L_8019873C:
    // 0x8019873C: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x80198740: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80198744: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80198748: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x8019874C: subu        $t8, $t8, $t6
    ctx->r24 = SUB32(ctx->r24, ctx->r14);
    // 0x80198750: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80198754: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x80198758: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8019875C: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80198760: lwc1        $f10, 0xFD8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0XFD8);
    // 0x80198764: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x80198768: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8019876C: swc1        $f10, 0xC8($t4)
    MEM_W(0XC8, ctx->r12) = ctx->f10.u32l;
    // 0x80198770: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    // 0x80198774: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80198778: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x8019877C: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x80198780: subu        $t7, $t7, $t5
    ctx->r15 = SUB32(ctx->r15, ctx->r13);
    // 0x80198784: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80198788: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x8019878C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80198790: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80198794: lwc1        $f4, 0xFDC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XFDC);
    // 0x80198798: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8019879C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x801987A0: swc1        $f4, 0xCC($t9)
    MEM_W(0XCC, ctx->r25) = ctx->f4.u32l;
    // 0x801987A4: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x801987A8: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x801987AC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x801987B0: sll         $t1, $t2, 2
    ctx->r9 = S32(ctx->r10 << 2);
    // 0x801987B4: subu        $t1, $t1, $t2
    ctx->r9 = SUB32(ctx->r9, ctx->r10);
    // 0x801987B8: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x801987BC: addu        $t1, $t1, $t2
    ctx->r9 = ADD32(ctx->r9, ctx->r10);
    // 0x801987C0: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x801987C4: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x801987C8: lwc1        $f16, 0xFE0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0XFE0);
    // 0x801987CC: addiu       $t8, $t8, 0xF98
    ctx->r24 = ADD32(ctx->r24, 0XF98);
    // 0x801987D0: swc1        $f16, 0xD0($t0)
    MEM_W(0XD0, ctx->r8) = ctx->f16.u32l;
    // 0x801987D4: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x801987D8: sll         $t6, $t3, 2
    ctx->r14 = S32(ctx->r11 << 2);
    // 0x801987DC: subu        $t6, $t6, $t3
    ctx->r14 = SUB32(ctx->r14, ctx->r11);
    // 0x801987E0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801987E4: addu        $t6, $t6, $t3
    ctx->r14 = ADD32(ctx->r14, ctx->r11);
    // 0x801987E8: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x801987EC: addu        $t4, $t6, $t8
    ctx->r12 = ADD32(ctx->r14, ctx->r24);
    // 0x801987F0: lwc1        $f8, 0x40($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X40);
    // 0x801987F4: lwc1        $f6, 0x18($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X18);
    // 0x801987F8: c.eq.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl == ctx->f6.fl;
    // 0x801987FC: nop

    // 0x80198800: bc1f        L_8019881C
    if (!c1cs) {
        // 0x80198804: nop
    
            goto L_8019881C;
    }
    // 0x80198804: nop

    // 0x80198808: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8019880C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80198810: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x80198814: b           L_8019887C
    // 0x80198818: swc1        $f18, 0xDC($t5)
    MEM_W(0XDC, ctx->r13) = ctx->f18.u32l;
        goto L_8019887C;
    // 0x80198818: swc1        $f18, 0xDC($t5)
    MEM_W(0XDC, ctx->r13) = ctx->f18.u32l;
L_8019881C:
    // 0x8019881C: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x80198820: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80198824: addiu       $t2, $t2, 0xF98
    ctx->r10 = ADD32(ctx->r10, 0XF98);
    // 0x80198828: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8019882C: subu        $t9, $t9, $t7
    ctx->r25 = SUB32(ctx->r25, ctx->r15);
    // 0x80198830: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80198834: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x80198838: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x8019883C: addu        $t1, $t9, $t2
    ctx->r9 = ADD32(ctx->r25, ctx->r10);
    // 0x80198840: lwc1        $f10, 0x18($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X18);
    // 0x80198844: lwc1        $f4, 0x40($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X40);
    // 0x80198848: lwc1        $f8, 0x30($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X30);
    // 0x8019884C: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80198850: sub.s       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80198854: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80198858: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8019885C: lwc1        $f10, -0x2E30($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x80198860: div.s       $f6, $f16, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = DIV_S(ctx->f16.fl, ctx->f8.fl);
    // 0x80198864: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80198868: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x8019886C: mul.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x80198870: nop

    // 0x80198874: mul.s       $f16, $f6, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x80198878: swc1        $f16, 0xDC($t0)
    MEM_W(0XDC, ctx->r8) = ctx->f16.u32l;
L_8019887C:
    // 0x8019887C: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x80198880: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80198884: addiu       $t8, $t8, 0xF98
    ctx->r24 = ADD32(ctx->r24, 0XF98);
    // 0x80198888: sll         $t6, $t3, 2
    ctx->r14 = S32(ctx->r11 << 2);
    // 0x8019888C: subu        $t6, $t6, $t3
    ctx->r14 = SUB32(ctx->r14, ctx->r11);
    // 0x80198890: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80198894: addu        $t6, $t6, $t3
    ctx->r14 = ADD32(ctx->r14, ctx->r11);
    // 0x80198898: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8019889C: addu        $t4, $t6, $t8
    ctx->r12 = ADD32(ctx->r14, ctx->r24);
    // 0x801988A0: lwc1        $f8, 0x44($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X44);
    // 0x801988A4: lwc1        $f18, 0x1C($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X1C);
    // 0x801988A8: c.eq.s      $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f8.fl == ctx->f18.fl;
    // 0x801988AC: nop

    // 0x801988B0: bc1f        L_801988CC
    if (!c1cs) {
        // 0x801988B4: nop
    
            goto L_801988CC;
    }
    // 0x801988B4: nop

    // 0x801988B8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801988BC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x801988C0: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x801988C4: b           L_8019892C
    // 0x801988C8: swc1        $f10, 0xE0($t5)
    MEM_W(0XE0, ctx->r13) = ctx->f10.u32l;
        goto L_8019892C;
    // 0x801988C8: swc1        $f10, 0xE0($t5)
    MEM_W(0XE0, ctx->r13) = ctx->f10.u32l;
L_801988CC:
    // 0x801988CC: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x801988D0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x801988D4: addiu       $t2, $t2, 0xF98
    ctx->r10 = ADD32(ctx->r10, 0XF98);
    // 0x801988D8: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x801988DC: subu        $t9, $t9, $t7
    ctx->r25 = SUB32(ctx->r25, ctx->r15);
    // 0x801988E0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x801988E4: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x801988E8: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x801988EC: addu        $t1, $t9, $t2
    ctx->r9 = ADD32(ctx->r25, ctx->r10);
    // 0x801988F0: lwc1        $f6, 0x1C($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X1C);
    // 0x801988F4: lwc1        $f4, 0x44($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X44);
    // 0x801988F8: lwc1        $f8, 0x30($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X30);
    // 0x801988FC: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80198900: sub.s       $f16, $f6, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80198904: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80198908: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8019890C: lwc1        $f6, -0x2E30($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x80198910: div.s       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f8.fl);
    // 0x80198914: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80198918: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x8019891C: mul.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80198920: nop

    // 0x80198924: mul.s       $f16, $f18, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80198928: swc1        $f16, 0xE0($t0)
    MEM_W(0XE0, ctx->r8) = ctx->f16.u32l;
L_8019892C:
    // 0x8019892C: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x80198930: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80198934: addiu       $t8, $t8, 0xF98
    ctx->r24 = ADD32(ctx->r24, 0XF98);
    // 0x80198938: sll         $t6, $t3, 2
    ctx->r14 = S32(ctx->r11 << 2);
    // 0x8019893C: subu        $t6, $t6, $t3
    ctx->r14 = SUB32(ctx->r14, ctx->r11);
    // 0x80198940: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80198944: addu        $t6, $t6, $t3
    ctx->r14 = ADD32(ctx->r14, ctx->r11);
    // 0x80198948: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8019894C: addu        $t4, $t6, $t8
    ctx->r12 = ADD32(ctx->r14, ctx->r24);
    // 0x80198950: lwc1        $f8, 0x48($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X48);
    // 0x80198954: lwc1        $f10, 0x20($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X20);
    // 0x80198958: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x8019895C: nop

    // 0x80198960: bc1f        L_8019897C
    if (!c1cs) {
        // 0x80198964: nop
    
            goto L_8019897C;
    }
    // 0x80198964: nop

    // 0x80198968: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8019896C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80198970: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x80198974: b           L_801989DC
    // 0x80198978: swc1        $f6, 0xE4($t5)
    MEM_W(0XE4, ctx->r13) = ctx->f6.u32l;
        goto L_801989DC;
    // 0x80198978: swc1        $f6, 0xE4($t5)
    MEM_W(0XE4, ctx->r13) = ctx->f6.u32l;
L_8019897C:
    // 0x8019897C: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x80198980: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80198984: addiu       $t2, $t2, 0xF98
    ctx->r10 = ADD32(ctx->r10, 0XF98);
    // 0x80198988: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8019898C: subu        $t9, $t9, $t7
    ctx->r25 = SUB32(ctx->r25, ctx->r15);
    // 0x80198990: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80198994: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x80198998: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x8019899C: addu        $t1, $t9, $t2
    ctx->r9 = ADD32(ctx->r25, ctx->r10);
    // 0x801989A0: lwc1        $f18, 0x20($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X20);
    // 0x801989A4: lwc1        $f4, 0x48($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X48);
    // 0x801989A8: lwc1        $f8, 0x30($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X30);
    // 0x801989AC: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x801989B0: sub.s       $f16, $f18, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x801989B4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801989B8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801989BC: lwc1        $f18, -0x2E30($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x801989C0: div.s       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f16.fl, ctx->f8.fl);
    // 0x801989C4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x801989C8: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x801989CC: mul.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x801989D0: nop

    // 0x801989D4: mul.s       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x801989D8: swc1        $f16, 0xE4($t0)
    MEM_W(0XE4, ctx->r8) = ctx->f16.u32l;
L_801989DC:
    // 0x801989DC: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x801989E0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801989E4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801989E8: sll         $t6, $t3, 2
    ctx->r14 = S32(ctx->r11 << 2);
    // 0x801989EC: subu        $t6, $t6, $t3
    ctx->r14 = SUB32(ctx->r14, ctx->r11);
    // 0x801989F0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801989F4: addu        $t6, $t6, $t3
    ctx->r14 = ADD32(ctx->r14, ctx->r11);
    // 0x801989F8: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x801989FC: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80198A00: lwc1        $f6, 0xFC8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0XFC8);
    // 0x80198A04: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    // 0x80198A08: swc1        $f8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f8.u32l;
    // 0x80198A0C: c.lt.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl < ctx->f6.fl;
    // 0x80198A10: nop

    // 0x80198A14: bc1f        L_80198EB4
    if (!c1cs) {
        // 0x80198A18: nop
    
            goto L_80198EB4;
    }
    // 0x80198A18: nop

L_80198A1C:
    // 0x80198A1C: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x80198A20: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x80198A24: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80198A28: andi        $t4, $t8, 0x1
    ctx->r12 = ctx->r24 & 0X1;
    // 0x80198A2C: or          $t7, $t4, $t5
    ctx->r15 = ctx->r12 | ctx->r13;
    // 0x80198A30: beq         $t7, $at, L_80198E10
    if (ctx->r15 == ctx->r1) {
        // 0x80198A34: nop
    
            goto L_80198E10;
    }
    // 0x80198A34: nop

    // 0x80198A38: jal         0x80199214
    // 0x80198A3C: nop

    func_80199214_1501A0(rdram, ctx);
        goto after_2;
    // 0x80198A3C: nop

    after_2:
    // 0x80198A40: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80198A44: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80198A48: beq         $t9, $zero, L_80198A84
    if (ctx->r25 == 0) {
        // 0x80198A4C: nop
    
            goto L_80198A84;
    }
    // 0x80198A4C: nop

    // 0x80198A50: jal         0x80199D70
    // 0x80198A54: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    func_80199D70_1501A0(rdram, ctx);
        goto after_3;
    // 0x80198A54: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    after_3:
    // 0x80198A58: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x80198A5C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80198A60: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80198A64: sll         $t1, $t2, 2
    ctx->r9 = S32(ctx->r10 << 2);
    // 0x80198A68: subu        $t1, $t1, $t2
    ctx->r9 = SUB32(ctx->r9, ctx->r10);
    // 0x80198A6C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80198A70: addu        $t1, $t1, $t2
    ctx->r9 = ADD32(ctx->r9, ctx->r10);
    // 0x80198A74: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x80198A78: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80198A7C: b           L_80198EB8
    // 0x80198A80: sw          $zero, 0xF98($at)
    MEM_W(0XF98, ctx->r1) = 0;
        goto L_80198EB8;
    // 0x80198A80: sw          $zero, 0xF98($at)
    MEM_W(0XF98, ctx->r1) = 0;
L_80198A84:
    // 0x80198A84: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80198A88: addiu       $t0, $t0, 0x3C00
    ctx->r8 = ADD32(ctx->r8, 0X3C00);
    // 0x80198A8C: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x80198A90: beq         $t3, $zero, L_80198E10
    if (ctx->r11 == 0) {
        // 0x80198A94: nop
    
            goto L_80198E10;
    }
    // 0x80198A94: nop

    // 0x80198A98: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x80198A9C: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x80198AA0: beq         $t6, $zero, L_80198E10
    if (ctx->r14 == 0) {
        // 0x80198AA4: nop
    
            goto L_80198E10;
    }
    // 0x80198AA4: nop

L_80198AA8:
    // 0x80198AA8: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x80198AAC: lui         $t5, 0x800C
    ctx->r13 = S32(0X800C << 16);
    // 0x80198AB0: addiu       $t5, $t5, 0x400
    ctx->r13 = ADD32(ctx->r13, 0X400);
    // 0x80198AB4: sll         $t4, $t8, 1
    ctx->r12 = S32(ctx->r24 << 1);
    // 0x80198AB8: addu        $t7, $t4, $t5
    ctx->r15 = ADD32(ctx->r12, ctx->r13);
    // 0x80198ABC: lbu         $t9, 0x1($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X1);
    // 0x80198AC0: sw          $t9, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r25;
    // 0x80198AC4: lbu         $t2, 0x0($t7)
    ctx->r10 = MEM_BU(ctx->r15, 0X0);
    // 0x80198AC8: bne         $t2, $zero, L_80198D9C
    if (ctx->r10 != 0) {
        // 0x80198ACC: nop
    
            goto L_80198D9C;
    }
    // 0x80198ACC: nop

    // 0x80198AD0: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
L_80198AD4:
    // 0x80198AD4: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x80198AD8: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80198ADC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80198AE0: sll         $t3, $t1, 2
    ctx->r11 = S32(ctx->r9 << 2);
    // 0x80198AE4: addu        $t3, $t3, $t1
    ctx->r11 = ADD32(ctx->r11, ctx->r9);
    // 0x80198AE8: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80198AEC: subu        $t3, $t3, $t1
    ctx->r11 = SUB32(ctx->r11, ctx->r9);
    // 0x80198AF0: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80198AF4: addu        $t3, $t3, $t1
    ctx->r11 = ADD32(ctx->r11, ctx->r9);
    // 0x80198AF8: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80198AFC: addu        $t0, $t0, $t3
    ctx->r8 = ADD32(ctx->r8, ctx->r11);
    // 0x80198B00: lw          $t0, -0x29CC($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X29CC);
    // 0x80198B04: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80198B08: sll         $t4, $t8, 2
    ctx->r12 = S32(ctx->r24 << 2);
    // 0x80198B0C: addu        $t5, $t0, $t4
    ctx->r13 = ADD32(ctx->r8, ctx->r12);
    // 0x80198B10: lwc1        $f18, 0xC($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0XC);
    // 0x80198B14: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80198B18: nop

    // 0x80198B1C: c.eq.s      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.fl == ctx->f10.fl;
    // 0x80198B20: nop

    // 0x80198B24: bc1t        L_80198DEC
    if (c1cs) {
        // 0x80198B28: nop
    
            goto L_80198DEC;
    }
    // 0x80198B28: nop

    // 0x80198B2C: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x80198B30: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x80198B34: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80198B38: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x80198B3C: addu        $t7, $t7, $t9
    ctx->r15 = ADD32(ctx->r15, ctx->r25);
    // 0x80198B40: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80198B44: subu        $t7, $t7, $t9
    ctx->r15 = SUB32(ctx->r15, ctx->r25);
    // 0x80198B48: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80198B4C: addu        $t7, $t7, $t9
    ctx->r15 = ADD32(ctx->r15, ctx->r25);
    // 0x80198B50: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80198B54: addu        $t2, $t2, $t7
    ctx->r10 = ADD32(ctx->r10, ctx->r15);
    // 0x80198B58: lw          $t2, -0x29CC($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X29CC);
    // 0x80198B5C: sll         $t3, $t1, 2
    ctx->r11 = S32(ctx->r9 << 2);
    // 0x80198B60: sll         $t6, $t3, 2
    ctx->r14 = S32(ctx->r11 << 2);
    // 0x80198B64: addu        $t8, $t2, $t6
    ctx->r24 = ADD32(ctx->r10, ctx->r14);
    // 0x80198B68: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    // 0x80198B6C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80198B70: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x80198B74: swc1        $f4, 0x28($t0)
    MEM_W(0X28, ctx->r8) = ctx->f4.u32l;
    // 0x80198B78: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x80198B7C: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x80198B80: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80198B84: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80198B88: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x80198B8C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80198B90: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x80198B94: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80198B98: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x80198B9C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80198BA0: addu        $t9, $t9, $t5
    ctx->r25 = ADD32(ctx->r25, ctx->r13);
    // 0x80198BA4: lw          $t9, -0x29CC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X29CC);
    // 0x80198BA8: sll         $t1, $t7, 2
    ctx->r9 = S32(ctx->r15 << 2);
    // 0x80198BAC: sll         $t3, $t1, 2
    ctx->r11 = S32(ctx->r9 << 2);
    // 0x80198BB0: addu        $t2, $t9, $t3
    ctx->r10 = ADD32(ctx->r25, ctx->r11);
    // 0x80198BB4: lwc1        $f16, 0x4($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X4);
    // 0x80198BB8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80198BBC: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x80198BC0: swc1        $f16, 0x2C($t6)
    MEM_W(0X2C, ctx->r14) = ctx->f16.u32l;
    // 0x80198BC4: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x80198BC8: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x80198BCC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80198BD0: sll         $t0, $t8, 2
    ctx->r8 = S32(ctx->r24 << 2);
    // 0x80198BD4: addu        $t0, $t0, $t8
    ctx->r8 = ADD32(ctx->r8, ctx->r24);
    // 0x80198BD8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80198BDC: subu        $t0, $t0, $t8
    ctx->r8 = SUB32(ctx->r8, ctx->r24);
    // 0x80198BE0: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80198BE4: addu        $t0, $t0, $t8
    ctx->r8 = ADD32(ctx->r8, ctx->r24);
    // 0x80198BE8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80198BEC: addu        $t4, $t4, $t0
    ctx->r12 = ADD32(ctx->r12, ctx->r8);
    // 0x80198BF0: lw          $t4, -0x29CC($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X29CC);
    // 0x80198BF4: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x80198BF8: sll         $t1, $t7, 2
    ctx->r9 = S32(ctx->r15 << 2);
    // 0x80198BFC: addu        $t9, $t4, $t1
    ctx->r25 = ADD32(ctx->r12, ctx->r9);
    // 0x80198C00: lwc1        $f8, 0x8($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X8);
    // 0x80198C04: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80198C08: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x80198C0C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80198C10: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x80198C14: swc1        $f8, 0x30($t3)
    MEM_W(0X30, ctx->r11) = ctx->f8.u32l;
    // 0x80198C18: lwc1        $f6, 0x28($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X28);
    // 0x80198C1C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80198C20: nop

    // 0x80198C24: c.eq.s      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.fl == ctx->f18.fl;
    // 0x80198C28: nop

    // 0x80198C2C: bc1f        L_80198C6C
    if (!c1cs) {
        // 0x80198C30: nop
    
            goto L_80198C6C;
    }
    // 0x80198C30: nop

    // 0x80198C34: lwc1        $f10, 0x2C($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X2C);
    // 0x80198C38: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80198C3C: nop

    // 0x80198C40: c.eq.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl == ctx->f4.fl;
    // 0x80198C44: nop

    // 0x80198C48: bc1f        L_80198C6C
    if (!c1cs) {
        // 0x80198C4C: nop
    
            goto L_80198C6C;
    }
    // 0x80198C4C: nop

    // 0x80198C50: lwc1        $f16, 0x30($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X30);
    // 0x80198C54: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80198C58: nop

    // 0x80198C5C: c.eq.s      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.fl == ctx->f8.fl;
    // 0x80198C60: nop

    // 0x80198C64: bc1t        L_80198CD0
    if (c1cs) {
        // 0x80198C68: nop
    
            goto L_80198CD0;
    }
    // 0x80198C68: nop

L_80198C6C:
    // 0x80198C6C: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x80198C70: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80198C74: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x80198C78: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80198C7C: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x80198C80: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80198C84: subu        $t8, $t8, $t6
    ctx->r24 = SUB32(ctx->r24, ctx->r14);
    // 0x80198C88: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80198C8C: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x80198C90: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80198C94: lw          $a1, 0x28($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X28);
    // 0x80198C98: lw          $a2, 0x2C($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X2C);
    // 0x80198C9C: lw          $a3, 0x30($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X30);
    // 0x80198CA0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80198CA4: addiu       $t5, $t5, -0x2A28
    ctx->r13 = ADD32(ctx->r13, -0X2A28);
    // 0x80198CA8: addiu       $t0, $t8, 0xA4
    ctx->r8 = ADD32(ctx->r24, 0XA4);
    // 0x80198CAC: addiu       $t4, $t7, 0x4
    ctx->r12 = ADD32(ctx->r15, 0X4);
    // 0x80198CB0: addiu       $t1, $t7, 0x8
    ctx->r9 = ADD32(ctx->r15, 0X8);
    // 0x80198CB4: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x80198CB8: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80198CBC: addu        $a0, $t0, $t5
    ctx->r4 = ADD32(ctx->r8, ctx->r13);
    // 0x80198CC0: jal         0x800D6E90
    // 0x80198CC4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    guMtxXFMF_recomp(rdram, ctx);
        goto after_4;
    // 0x80198CC4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_4:
    // 0x80198CC8: b           L_80198CFC
    // 0x80198CCC: nop

        goto L_80198CFC;
    // 0x80198CCC: nop

L_80198CD0:
    // 0x80198CD0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80198CD4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80198CD8: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x80198CDC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80198CE0: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x80198CE4: swc1        $f6, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f6.u32l;
    // 0x80198CE8: lwc1        $f20, 0x8($t3)
    ctx->f20.u32l = MEM_W(ctx->r11, 0X8);
    // 0x80198CEC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80198CF0: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x80198CF4: swc1        $f20, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->f20.u32l;
    // 0x80198CF8: swc1        $f20, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f20.u32l;
L_80198CFC:
    // 0x80198CFC: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x80198D00: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x80198D04: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80198D08: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80198D0C: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x80198D10: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80198D14: subu        $t8, $t8, $t6
    ctx->r24 = SUB32(ctx->r24, ctx->r14);
    // 0x80198D18: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80198D1C: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x80198D20: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80198D24: addu        $t0, $t0, $t8
    ctx->r8 = ADD32(ctx->r8, ctx->r24);
    // 0x80198D28: lw          $t0, -0x29CC($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X29CC);
    // 0x80198D2C: sll         $t4, $t5, 2
    ctx->r12 = S32(ctx->r13 << 2);
    // 0x80198D30: sll         $t7, $t4, 2
    ctx->r15 = S32(ctx->r12 << 2);
    // 0x80198D34: addu        $t1, $t0, $t7
    ctx->r9 = ADD32(ctx->r8, ctx->r15);
    // 0x80198D38: lw          $a1, 0xC($t1)
    ctx->r5 = MEM_W(ctx->r9, 0XC);
    // 0x80198D3C: jal         0x80198ECC
    // 0x80198D40: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    func_80198ECC_1501A0(rdram, ctx);
        goto after_5;
    // 0x80198D40: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_5:
    // 0x80198D44: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80198D48: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80198D4C: beq         $t9, $zero, L_80198D8C
    if (ctx->r25 == 0) {
        // 0x80198D50: nop
    
            goto L_80198D8C;
    }
    // 0x80198D50: nop

    // 0x80198D54: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80198D58: jal         0x8019A0CC
    // 0x80198D5C: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    func_8019A0CC_1501A0(rdram, ctx);
        goto after_6;
    // 0x80198D5C: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    after_6:
    // 0x80198D60: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x80198D64: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80198D68: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80198D6C: sll         $t2, $t3, 2
    ctx->r10 = S32(ctx->r11 << 2);
    // 0x80198D70: subu        $t2, $t2, $t3
    ctx->r10 = SUB32(ctx->r10, ctx->r11);
    // 0x80198D74: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80198D78: addu        $t2, $t2, $t3
    ctx->r10 = ADD32(ctx->r10, ctx->r11);
    // 0x80198D7C: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x80198D80: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x80198D84: b           L_80198EB8
    // 0x80198D88: sw          $zero, 0xF98($at)
    MEM_W(0XF98, ctx->r1) = 0;
        goto L_80198EB8;
    // 0x80198D88: sw          $zero, 0xF98($at)
    MEM_W(0XF98, ctx->r1) = 0;
L_80198D8C:
    // 0x80198D8C: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80198D90: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x80198D94: b           L_80198AD4
    // 0x80198D98: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
        goto L_80198AD4;
    // 0x80198D98: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
L_80198D9C:
    // 0x80198D9C: jal         0x80199044
    // 0x80198DA0: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_80199044_1501A0(rdram, ctx);
        goto after_7;
    // 0x80198DA0: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_7:
    // 0x80198DA4: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80198DA8: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x80198DAC: beq         $t5, $zero, L_80198DEC
    if (ctx->r13 == 0) {
        // 0x80198DB0: nop
    
            goto L_80198DEC;
    }
    // 0x80198DB0: nop

    // 0x80198DB4: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80198DB8: jal         0x8019A7A8
    // 0x80198DBC: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    func_8019A7A8_1501A0(rdram, ctx);
        goto after_8;
    // 0x80198DBC: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    after_8:
    // 0x80198DC0: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x80198DC4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80198DC8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80198DCC: sll         $t0, $t4, 2
    ctx->r8 = S32(ctx->r12 << 2);
    // 0x80198DD0: subu        $t0, $t0, $t4
    ctx->r8 = SUB32(ctx->r8, ctx->r12);
    // 0x80198DD4: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80198DD8: addu        $t0, $t0, $t4
    ctx->r8 = ADD32(ctx->r8, ctx->r12);
    // 0x80198DDC: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x80198DE0: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80198DE4: b           L_80198EB8
    // 0x80198DE8: sw          $zero, 0xF98($at)
    MEM_W(0XF98, ctx->r1) = 0;
        goto L_80198EB8;
    // 0x80198DE8: sw          $zero, 0xF98($at)
    MEM_W(0XF98, ctx->r1) = 0;
L_80198DEC:
    // 0x80198DEC: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x80198DF0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80198DF4: addiu       $t9, $t9, 0x3C00
    ctx->r25 = ADD32(ctx->r25, 0X3C00);
    // 0x80198DF8: addiu       $t1, $t7, 0x1
    ctx->r9 = ADD32(ctx->r15, 0X1);
    // 0x80198DFC: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    // 0x80198E00: lw          $t3, 0x0($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X0);
    // 0x80198E04: sltu        $at, $t1, $t3
    ctx->r1 = ctx->r9 < ctx->r11 ? 1 : 0;
    // 0x80198E08: bne         $at, $zero, L_80198AA8
    if (ctx->r1 != 0) {
        // 0x80198E0C: nop
    
            goto L_80198AA8;
    }
    // 0x80198E0C: nop

L_80198E10:
    // 0x80198E10: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80198E14: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x80198E18: lwc1        $f18, 0xC8($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0XC8);
    // 0x80198E1C: lwc1        $f10, 0xDC($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0XDC);
    // 0x80198E20: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80198E24: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x80198E28: add.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x80198E2C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80198E30: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x80198E34: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80198E38: swc1        $f4, 0xC8($t2)
    MEM_W(0XC8, ctx->r10) = ctx->f4.u32l;
    // 0x80198E3C: lwc1        $f16, 0xCC($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0XCC);
    // 0x80198E40: lwc1        $f8, 0xE0($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0XE0);
    // 0x80198E44: add.s       $f6, $f16, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x80198E48: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80198E4C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80198E50: swc1        $f6, 0xCC($t6)
    MEM_W(0XCC, ctx->r14) = ctx->f6.u32l;
    // 0x80198E54: lwc1        $f18, 0xD0($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0XD0);
    // 0x80198E58: lwc1        $f10, 0xE4($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0XE4);
    // 0x80198E5C: add.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x80198E60: swc1        $f4, 0xD0($t8)
    MEM_W(0XD0, ctx->r24) = ctx->f4.u32l;
    // 0x80198E64: lwc1        $f8, -0x2E30($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x80198E68: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x80198E6C: lwc1        $f18, 0x54($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80198E70: mul.s       $f6, $f16, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x80198E74: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x80198E78: subu        $t7, $t7, $t0
    ctx->r15 = SUB32(ctx->r15, ctx->r8);
    // 0x80198E7C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80198E80: addu        $t7, $t7, $t0
    ctx->r15 = ADD32(ctx->r15, ctx->r8);
    // 0x80198E84: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80198E88: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80198E8C: add.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80198E90: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80198E94: lwc1        $f4, 0xFC8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XFC8);
    // 0x80198E98: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x80198E9C: swc1        $f10, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f10.u32l;
    // 0x80198EA0: c.lt.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl < ctx->f4.fl;
    // 0x80198EA4: addiu       $t4, $t5, 0x1
    ctx->r12 = ADD32(ctx->r13, 0X1);
    // 0x80198EA8: sw          $t4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r12;
    // 0x80198EAC: bc1t        L_80198A1C
    if (c1cs) {
        // 0x80198EB0: nop
    
            goto L_80198A1C;
    }
    // 0x80198EB0: nop

L_80198EB4:
    // 0x80198EB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80198EB8:
    // 0x80198EB8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80198EBC: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80198EC0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80198EC4: jr          $ra
    // 0x80198EC8: nop

    return;
    // 0x80198EC8: nop

;}
RECOMP_FUNC void func_80198ECC_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80198ECC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80198ED0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80198ED4: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80198ED8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80198EDC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80198EE0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80198EE4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80198EE8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80198EEC: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80198EF0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80198EF4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80198EF8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80198EFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80198F00: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80198F04: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80198F08: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x80198F0C: lwc1        $f4, 0x0($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X0);
    // 0x80198F10: lwc1        $f6, -0x29C8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X29C8);
    // 0x80198F14: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80198F18: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80198F1C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80198F20: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x80198F24: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80198F28: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x80198F2C: swc1        $f8, 0x78($t6)
    MEM_W(0X78, ctx->r14) = ctx->f8.u32l;
    // 0x80198F30: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80198F34: lwc1        $f10, 0x4($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X4);
    // 0x80198F38: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80198F3C: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80198F40: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80198F44: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80198F48: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x80198F4C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80198F50: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80198F54: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80198F58: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80198F5C: lwc1        $f16, -0x29C4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X29C4);
    // 0x80198F60: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80198F64: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x80198F68: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80198F6C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80198F70: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x80198F74: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80198F78: swc1        $f18, 0x7C($t9)
    MEM_W(0X7C, ctx->r25) = ctx->f18.u32l;
    // 0x80198F7C: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x80198F80: lwc1        $f4, 0x8($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X8);
    // 0x80198F84: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x80198F88: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80198F8C: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x80198F90: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80198F94: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x80198F98: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80198F9C: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x80198FA0: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80198FA4: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x80198FA8: lwc1        $f6, -0x29C0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X29C0);
    // 0x80198FAC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80198FB0: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x80198FB4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80198FB8: swc1        $f8, 0x80($t2)
    MEM_W(0X80, ctx->r10) = ctx->f8.u32l;
    // 0x80198FBC: lwc1        $f16, 0x78($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0X78);
    // 0x80198FC0: lwc1        $f10, 0xC8($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0XC8);
    // 0x80198FC4: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80198FC8: swc1        $f18, 0x8C($t5)
    MEM_W(0X8C, ctx->r13) = ctx->f18.u32l;
    // 0x80198FCC: lwc1        $f6, 0x7C($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X7C);
    // 0x80198FD0: lwc1        $f4, 0xCC($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0XCC);
    // 0x80198FD4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80198FD8: swc1        $f8, 0x90($t7)
    MEM_W(0X90, ctx->r15) = ctx->f8.u32l;
    // 0x80198FDC: lwc1        $f16, 0x80($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X80);
    // 0x80198FE0: lwc1        $f10, 0xD0($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0XD0);
    // 0x80198FE4: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80198FE8: swc1        $f18, 0x94($t8)
    MEM_W(0X94, ctx->r24) = ctx->f18.u32l;
    // 0x80198FEC: lwc1        $f4, 0x8C($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X8C);
    // 0x80198FF0: lwc1        $f8, 0x90($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X90);
    // 0x80198FF4: lwc1        $f18, 0x94($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X94);
    // 0x80198FF8: mul.s       $f6, $f4, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x80198FFC: nop

    // 0x80199000: mul.s       $f10, $f8, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x80199004: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80199008: mul.s       $f4, $f18, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x8019900C: jal         0x800D68E0
    // 0x80199010: add.s       $f12, $f4, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f16.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x80199010: add.s       $f12, $f4, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f16.fl;
    after_0:
    // 0x80199014: lwc1        $f8, 0x1C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80199018: c.le.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl <= ctx->f8.fl;
    // 0x8019901C: nop

    // 0x80199020: bc1f        L_80199030
    if (!c1cs) {
        // 0x80199024: nop
    
            goto L_80199030;
    }
    // 0x80199024: nop

    // 0x80199028: b           L_80199034
    // 0x8019902C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
        goto L_80199034;
    // 0x8019902C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_80199030:
    // 0x80199030: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80199034:
    // 0x80199034: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80199038: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8019903C: jr          $ra
    // 0x80199040: nop

    return;
    // 0x80199040: nop

;}
RECOMP_FUNC void func_80199044_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80199044: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80199048: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8019904C: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80199050: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80199054: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80199058: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8019905C: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80199060: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80199064: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80199068: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8019906C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80199070: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80199074: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x80199078: lwc1        $f4, 0xC8($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0XC8);
    // 0x8019907C: lwc1        $f6, 0xFB0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0XFB0);
    // 0x80199080: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80199084: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80199088: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8019908C: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x80199090: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80199094: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x80199098: swc1        $f8, 0x78($t6)
    MEM_W(0X78, ctx->r14) = ctx->f8.u32l;
    // 0x8019909C: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x801990A0: lwc1        $f10, 0xCC($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0XCC);
    // 0x801990A4: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x801990A8: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x801990AC: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x801990B0: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x801990B4: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x801990B8: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x801990BC: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x801990C0: lwc1        $f16, 0xFB4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0XFB4);
    // 0x801990C4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801990C8: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x801990CC: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x801990D0: swc1        $f18, 0x7C($t9)
    MEM_W(0X7C, ctx->r25) = ctx->f18.u32l;
    // 0x801990D4: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x801990D8: lwc1        $f4, 0xD0($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0XD0);
    // 0x801990DC: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x801990E0: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x801990E4: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x801990E8: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x801990EC: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x801990F0: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x801990F4: lwc1        $f6, 0xFB8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0XFB8);
    // 0x801990F8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801990FC: swc1        $f8, 0x80($t2)
    MEM_W(0X80, ctx->r10) = ctx->f8.u32l;
    // 0x80199100: lwc1        $f10, 0x78($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X78);
    // 0x80199104: lwc1        $f18, 0x7C($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X7C);
    // 0x80199108: lwc1        $f8, 0x80($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X80);
    // 0x8019910C: mul.s       $f16, $f10, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x80199110: nop

    // 0x80199114: mul.s       $f4, $f18, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x80199118: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x8019911C: mul.s       $f10, $f8, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x80199120: jal         0x800D68E0
    // 0x80199124: add.s       $f12, $f10, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x80199124: add.s       $f12, $f10, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f6.fl;
    after_0:
    // 0x80199128: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8019912C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80199130: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80199134: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80199138: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8019913C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80199140: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80199144: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80199148: addu        $t6, $t6, $t8
    ctx->r14 = ADD32(ctx->r14, ctx->r24);
    // 0x8019914C: lw          $t6, 0xF98($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XF98);
    // 0x80199150: addiu       $t1, $t1, -0x232C
    ctx->r9 = ADD32(ctx->r9, -0X232C);
    // 0x80199154: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80199158: sll         $t0, $t6, 3
    ctx->r8 = S32(ctx->r14 << 3);
    // 0x8019915C: subu        $t0, $t0, $t6
    ctx->r8 = SUB32(ctx->r8, ctx->r14);
    // 0x80199160: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80199164: addu        $t9, $t0, $t1
    ctx->r25 = ADD32(ctx->r8, ctx->r9);
    // 0x80199168: lhu         $t3, 0x0($t9)
    ctx->r11 = MEM_HU(ctx->r25, 0X0);
    // 0x8019916C: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x80199170: beq         $t4, $zero, L_801991A8
    if (ctx->r12 == 0) {
        // 0x80199174: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_801991A8;
    }
    // 0x80199174: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80199178: lwc1        $f16, -0x2E30($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x8019917C: lwc1        $f18, 0x10($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X10);
    // 0x80199180: lwc1        $f8, 0x1C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80199184: mul.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x80199188: c.le.s      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.fl <= ctx->f4.fl;
    // 0x8019918C: nop

    // 0x80199190: bc1f        L_801991A0
    if (!c1cs) {
        // 0x80199194: nop
    
            goto L_801991A0;
    }
    // 0x80199194: nop

    // 0x80199198: b           L_80199204
    // 0x8019919C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
        goto L_80199204;
    // 0x8019919C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_801991A0:
    // 0x801991A0: b           L_80199204
    // 0x801991A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80199204;
    // 0x801991A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801991A8:
    // 0x801991A8: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x801991AC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801991B0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801991B4: sll         $t5, $t2, 2
    ctx->r13 = S32(ctx->r10 << 2);
    // 0x801991B8: subu        $t5, $t5, $t2
    ctx->r13 = SUB32(ctx->r13, ctx->r10);
    // 0x801991BC: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x801991C0: addu        $t5, $t5, $t2
    ctx->r13 = ADD32(ctx->r13, ctx->r10);
    // 0x801991C4: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x801991C8: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x801991CC: lw          $t7, 0xF98($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XF98);
    // 0x801991D0: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x801991D4: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x801991D8: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x801991DC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x801991E0: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x801991E4: lwc1        $f10, -0x231C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X231C);
    // 0x801991E8: c.le.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl <= ctx->f10.fl;
    // 0x801991EC: nop

    // 0x801991F0: bc1f        L_80199200
    if (!c1cs) {
        // 0x801991F4: nop
    
            goto L_80199200;
    }
    // 0x801991F4: nop

    // 0x801991F8: b           L_80199204
    // 0x801991FC: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
        goto L_80199204;
    // 0x801991FC: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_80199200:
    // 0x80199200: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80199204:
    // 0x80199204: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80199208: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8019920C: jr          $ra
    // 0x80199210: nop

    return;
    // 0x80199210: nop

;}
RECOMP_FUNC void func_80199214_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80199214: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80199218: lw          $t6, -0x2E44($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2E44);
    // 0x8019921C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80199220: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80199224: sltiu       $at, $t7, 0x6
    ctx->r1 = ctx->r15 < 0X6 ? 1 : 0;
    // 0x80199228: beq         $at, $zero, L_80199864
    if (ctx->r1 == 0) {
        // 0x8019922C: nop
    
            goto L_80199864;
    }
    // 0x8019922C: nop

    // 0x80199230: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80199234: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80199238: addu        $at, $at, $t7
    gpr jr_addend_80199240 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8019923C: lw          $t7, 0x9A8($at)
    ctx->r15 = ADD32(ctx->r1, 0X9A8);
    // 0x80199240: jr          $t7
    // 0x80199244: nop

    switch (jr_addend_80199240 >> 2) {
        case 0: goto L_80199248; break;
        case 1: goto L_80199350; break;
        case 2: goto L_80199458; break;
        case 3: goto L_8019955C; break;
        case 4: goto L_80199660; break;
        case 5: goto L_80199764; break;
        default: switch_error(__func__, 0x80199240, 0x801A09A8);
    }
    // 0x80199244: nop

L_80199248:
    // 0x80199248: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8019924C: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x80199250: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80199254: lwc1        $f6, 0x9C0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X9C0);
    // 0x80199258: lwc1        $f4, 0xC8($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0XC8);
    // 0x8019925C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80199260: nop

    // 0x80199264: bc1t        L_801992B0
    if (c1cs) {
        // 0x80199268: lui         $at, 0x457A
        ctx->r1 = S32(0X457A << 16);
            goto L_801992B0;
    }
    // 0x80199268: lui         $at, 0x457A
    ctx->r1 = S32(0X457A << 16);
    // 0x8019926C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80199270: nop

    // 0x80199274: c.le.s      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.fl <= ctx->f4.fl;
    // 0x80199278: nop

    // 0x8019927C: bc1t        L_801992B0
    if (c1cs) {
        // 0x80199280: lui         $at, 0x801A
        ctx->r1 = S32(0X801A << 16);
            goto L_801992B0;
    }
    // 0x80199280: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80199284: lwc1        $f16, 0x9C4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X9C4);
    // 0x80199288: lwc1        $f10, 0xD0($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0XD0);
    // 0x8019928C: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x80199290: nop

    // 0x80199294: bc1t        L_801992B0
    if (c1cs) {
        // 0x80199298: lui         $at, 0x801A
        ctx->r1 = S32(0X801A << 16);
            goto L_801992B0;
    }
    // 0x80199298: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019929C: lwc1        $f18, 0x9C8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X9C8);
    // 0x801992A0: c.le.s      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.fl <= ctx->f10.fl;
    // 0x801992A4: nop

    // 0x801992A8: bc1f        L_801992B8
    if (!c1cs) {
        // 0x801992AC: nop
    
            goto L_801992B8;
    }
    // 0x801992AC: nop

L_801992B0:
    // 0x801992B0: b           L_80199D68
    // 0x801992B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80199D68;
    // 0x801992B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801992B8:
    // 0x801992B8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801992BC: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x801992C0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801992C4: lwc1        $f4, 0x9CC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X9CC);
    // 0x801992C8: lwc1        $f6, 0xC8($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0XC8);
    // 0x801992CC: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x801992D0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801992D4: sub.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x801992D8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x801992DC: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x801992E0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801992E4: div.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f16.fl);
    // 0x801992E8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x801992EC: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x801992F0: swc1        $f10, 0xB0($t9)
    MEM_W(0XB0, ctx->r25) = ctx->f10.u32l;
    // 0x801992F4: lwc1        $f6, 0x9D0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X9D0);
    // 0x801992F8: lwc1        $f18, 0xD0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0XD0);
    // 0x801992FC: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x80199300: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80199304: sub.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x80199308: lui         $t9, 0x801E
    ctx->r25 = S32(0X801E << 16);
    // 0x8019930C: div.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80199310: swc1        $f16, 0xB4($t0)
    MEM_W(0XB4, ctx->r8) = ctx->f16.u32l;
    // 0x80199314: lwc1        $f10, 0xB4($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0XB4);
    // 0x80199318: lwc1        $f6, 0xB0($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0XB0);
    // 0x8019931C: trunc.w.s   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80199320: trunc.w.s   $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80199324: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
    // 0x80199328: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    // 0x8019932C: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x80199330: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x80199334: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80199338: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x8019933C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80199340: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80199344: lw          $t9, 0x6920($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6920);
    // 0x80199348: b           L_80199864
    // 0x8019934C: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
        goto L_80199864;
    // 0x8019934C: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
L_80199350:
    // 0x80199350: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80199354: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x80199358: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019935C: lwc1        $f16, 0x9D4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X9D4);
    // 0x80199360: lwc1        $f8, 0xC8($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0XC8);
    // 0x80199364: c.lt.s      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.fl < ctx->f16.fl;
    // 0x80199368: nop

    // 0x8019936C: bc1t        L_801993BC
    if (c1cs) {
        // 0x80199370: lui         $at, 0x44FA
        ctx->r1 = S32(0X44FA << 16);
            goto L_801993BC;
    }
    // 0x80199370: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x80199374: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80199378: nop

    // 0x8019937C: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x80199380: nop

    // 0x80199384: bc1t        L_801993BC
    if (c1cs) {
        // 0x80199388: lui         $at, 0xC47A
        ctx->r1 = S32(0XC47A << 16);
            goto L_801993BC;
    }
    // 0x80199388: lui         $at, 0xC47A
    ctx->r1 = S32(0XC47A << 16);
    // 0x8019938C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80199390: lwc1        $f18, 0xD0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0XD0);
    // 0x80199394: c.lt.s      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.fl < ctx->f6.fl;
    // 0x80199398: nop

    // 0x8019939C: bc1t        L_801993BC
    if (c1cs) {
        // 0x801993A0: lui         $at, 0x44FA
        ctx->r1 = S32(0X44FA << 16);
            goto L_801993BC;
    }
    // 0x801993A0: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x801993A4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801993A8: nop

    // 0x801993AC: c.le.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl <= ctx->f18.fl;
    // 0x801993B0: nop

    // 0x801993B4: bc1f        L_801993C4
    if (!c1cs) {
        // 0x801993B8: nop
    
            goto L_801993C4;
    }
    // 0x801993B8: nop

L_801993BC:
    // 0x801993BC: b           L_80199D68
    // 0x801993C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80199D68;
    // 0x801993C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801993C4:
    // 0x801993C4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x801993C8: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x801993CC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801993D0: lwc1        $f8, 0x9D8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X9D8);
    // 0x801993D4: lwc1        $f16, 0xC8($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0XC8);
    // 0x801993D8: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x801993DC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801993E0: sub.s       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x801993E4: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x801993E8: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x801993EC: lui         $at, 0xC47A
    ctx->r1 = S32(0XC47A << 16);
    // 0x801993F0: div.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f6.fl);
    // 0x801993F4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801993F8: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x801993FC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80199400: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80199404: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x80199408: swc1        $f18, 0xB0($t2)
    MEM_W(0XB0, ctx->r10) = ctx->f18.u32l;
    // 0x8019940C: lwc1        $f4, 0xD0($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0XD0);
    // 0x80199410: lui         $t2, 0x801F
    ctx->r10 = S32(0X801F << 16);
    // 0x80199414: sub.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x80199418: div.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8019941C: swc1        $f6, 0xB4($t3)
    MEM_W(0XB4, ctx->r11) = ctx->f6.u32l;
    // 0x80199420: lwc1        $f18, 0xB4($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0XB4);
    // 0x80199424: lwc1        $f16, 0xB0($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0XB0);
    // 0x80199428: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8019942C: trunc.w.s   $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    ctx->f8.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80199430: mfc1        $t4, $f4
    ctx->r12 = (int32_t)ctx->f4.u32l;
    // 0x80199434: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x80199438: sll         $t6, $t4, 4
    ctx->r14 = S32(ctx->r12 << 4);
    // 0x8019943C: addu        $t6, $t6, $t4
    ctx->r14 = ADD32(ctx->r14, ctx->r12);
    // 0x80199440: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80199444: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80199448: addu        $t2, $t2, $t0
    ctx->r10 = ADD32(ctx->r10, ctx->r8);
    // 0x8019944C: lw          $t2, -0x59EC($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X59EC);
    // 0x80199450: b           L_80199864
    // 0x80199454: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
        goto L_80199864;
    // 0x80199454: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
L_80199458:
    // 0x80199458: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8019945C: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x80199460: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80199464: lwc1        $f6, 0x9DC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X9DC);
    // 0x80199468: lwc1        $f10, 0xC8($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0XC8);
    // 0x8019946C: c.lt.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl < ctx->f6.fl;
    // 0x80199470: nop

    // 0x80199474: bc1t        L_801994BC
    if (c1cs) {
        // 0x80199478: lui         $at, 0x801A
        ctx->r1 = S32(0X801A << 16);
            goto L_801994BC;
    }
    // 0x80199478: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019947C: lwc1        $f18, 0x9E0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X9E0);
    // 0x80199480: c.le.s      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.fl <= ctx->f10.fl;
    // 0x80199484: nop

    // 0x80199488: bc1t        L_801994BC
    if (c1cs) {
        // 0x8019948C: lui         $at, 0x801A
        ctx->r1 = S32(0X801A << 16);
            goto L_801994BC;
    }
    // 0x8019948C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80199490: lwc1        $f16, 0x9E4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X9E4);
    // 0x80199494: lwc1        $f4, 0xD0($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0XD0);
    // 0x80199498: c.lt.s      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.fl < ctx->f16.fl;
    // 0x8019949C: nop

    // 0x801994A0: bc1t        L_801994BC
    if (c1cs) {
        // 0x801994A4: lui         $at, 0x801A
        ctx->r1 = S32(0X801A << 16);
            goto L_801994BC;
    }
    // 0x801994A4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801994A8: lwc1        $f8, 0x9E8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X9E8);
    // 0x801994AC: c.le.s      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.fl <= ctx->f4.fl;
    // 0x801994B0: nop

    // 0x801994B4: bc1f        L_801994C4
    if (!c1cs) {
        // 0x801994B8: nop
    
            goto L_801994C4;
    }
    // 0x801994B8: nop

L_801994BC:
    // 0x801994BC: b           L_80199D68
    // 0x801994C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80199D68;
    // 0x801994C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801994C4:
    // 0x801994C4: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x801994C8: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x801994CC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801994D0: lwc1        $f10, 0x9EC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X9EC);
    // 0x801994D4: lwc1        $f6, 0xC8($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0XC8);
    // 0x801994D8: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x801994DC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801994E0: sub.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x801994E4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x801994E8: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x801994EC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801994F0: div.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f16.fl);
    // 0x801994F4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x801994F8: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x801994FC: swc1        $f4, 0xB0($t5)
    MEM_W(0XB0, ctx->r13) = ctx->f4.u32l;
    // 0x80199500: lwc1        $f6, 0x9F0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X9F0);
    // 0x80199504: lwc1        $f8, 0xD0($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0XD0);
    // 0x80199508: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x8019950C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80199510: sub.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x80199514: lui         $t5, 0x801E
    ctx->r13 = S32(0X801E << 16);
    // 0x80199518: div.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8019951C: swc1        $f16, 0xB4($t4)
    MEM_W(0XB4, ctx->r12) = ctx->f16.u32l;
    // 0x80199520: lwc1        $f4, 0xB4($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0XB4);
    // 0x80199524: lwc1        $f6, 0xB0($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0XB0);
    // 0x80199528: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8019952C: trunc.w.s   $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80199530: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x80199534: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x80199538: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x8019953C: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x80199540: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80199544: addu        $t2, $t8, $t0
    ctx->r10 = ADD32(ctx->r24, ctx->r8);
    // 0x80199548: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8019954C: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x80199550: lw          $t5, 0x32F8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X32F8);
    // 0x80199554: b           L_80199864
    // 0x80199558: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
        goto L_80199864;
    // 0x80199558: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
L_8019955C:
    // 0x8019955C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80199560: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x80199564: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80199568: lwc1        $f16, 0x9F4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X9F4);
    // 0x8019956C: lwc1        $f18, 0xC8($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0XC8);
    // 0x80199570: c.lt.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl < ctx->f16.fl;
    // 0x80199574: nop

    // 0x80199578: bc1t        L_801995C0
    if (c1cs) {
        // 0x8019957C: lui         $at, 0x801A
        ctx->r1 = S32(0X801A << 16);
            goto L_801995C0;
    }
    // 0x8019957C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80199580: lwc1        $f4, 0x9F8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X9F8);
    // 0x80199584: c.le.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl <= ctx->f18.fl;
    // 0x80199588: nop

    // 0x8019958C: bc1t        L_801995C0
    if (c1cs) {
        // 0x80199590: lui         $at, 0xC3FA
        ctx->r1 = S32(0XC3FA << 16);
            goto L_801995C0;
    }
    // 0x80199590: lui         $at, 0xC3FA
    ctx->r1 = S32(0XC3FA << 16);
    // 0x80199594: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80199598: lwc1        $f8, 0xD0($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0XD0);
    // 0x8019959C: c.lt.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl < ctx->f6.fl;
    // 0x801995A0: nop

    // 0x801995A4: bc1t        L_801995C0
    if (c1cs) {
        // 0x801995A8: lui         $at, 0x801A
        ctx->r1 = S32(0X801A << 16);
            goto L_801995C0;
    }
    // 0x801995A8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801995AC: lwc1        $f10, 0x9FC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X9FC);
    // 0x801995B0: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x801995B4: nop

    // 0x801995B8: bc1f        L_801995C8
    if (!c1cs) {
        // 0x801995BC: nop
    
            goto L_801995C8;
    }
    // 0x801995BC: nop

L_801995C0:
    // 0x801995C0: b           L_80199D68
    // 0x801995C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80199D68;
    // 0x801995C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801995C8:
    // 0x801995C8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801995CC: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x801995D0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801995D4: lwc1        $f18, 0xA00($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0XA00);
    // 0x801995D8: lwc1        $f16, 0xC8($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0XC8);
    // 0x801995DC: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x801995E0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801995E4: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x801995E8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801995EC: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x801995F0: lui         $at, 0xC3FA
    ctx->r1 = S32(0XC3FA << 16);
    // 0x801995F4: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801995F8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801995FC: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x80199600: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80199604: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80199608: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x8019960C: swc1        $f8, 0xB0($t7)
    MEM_W(0XB0, ctx->r15) = ctx->f8.u32l;
    // 0x80199610: lwc1        $f10, 0xD0($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0XD0);
    // 0x80199614: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x80199618: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8019961C: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80199620: swc1        $f6, 0xB4($t6)
    MEM_W(0XB4, ctx->r14) = ctx->f6.u32l;
    // 0x80199624: lwc1        $f8, 0xB4($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0XB4);
    // 0x80199628: lwc1        $f16, 0xB0($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0XB0);
    // 0x8019962C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80199630: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80199634: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x80199638: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
    // 0x8019963C: sll         $t0, $t8, 4
    ctx->r8 = S32(ctx->r24 << 4);
    // 0x80199640: subu        $t0, $t0, $t8
    ctx->r8 = SUB32(ctx->r8, ctx->r24);
    // 0x80199644: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x80199648: addu        $t5, $t0, $t3
    ctx->r13 = ADD32(ctx->r8, ctx->r11);
    // 0x8019964C: sll         $t4, $t5, 2
    ctx->r12 = S32(ctx->r13 << 2);
    // 0x80199650: addu        $t7, $t7, $t4
    ctx->r15 = ADD32(ctx->r15, ctx->r12);
    // 0x80199654: lw          $t7, -0x1E58($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X1E58);
    // 0x80199658: b           L_80199864
    // 0x8019965C: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
        goto L_80199864;
    // 0x8019965C: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
L_80199660:
    // 0x80199660: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80199664: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x80199668: lui         $at, 0xC3FA
    ctx->r1 = S32(0XC3FA << 16);
    // 0x8019966C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80199670: lwc1        $f4, 0xC8($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0XC8);
    // 0x80199674: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80199678: nop

    // 0x8019967C: bc1t        L_801996C8
    if (c1cs) {
        // 0x80199680: lui         $at, 0x801A
        ctx->r1 = S32(0X801A << 16);
            goto L_801996C8;
    }
    // 0x80199680: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80199684: lwc1        $f8, 0xA04($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0XA04);
    // 0x80199688: c.le.s      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.fl <= ctx->f4.fl;
    // 0x8019968C: nop

    // 0x80199690: bc1t        L_801996C8
    if (c1cs) {
        // 0x80199694: lui         $at, 0xC37A
        ctx->r1 = S32(0XC37A << 16);
            goto L_801996C8;
    }
    // 0x80199694: lui         $at, 0xC37A
    ctx->r1 = S32(0XC37A << 16);
    // 0x80199698: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8019969C: lwc1        $f10, 0xD0($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0XD0);
    // 0x801996A0: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x801996A4: nop

    // 0x801996A8: bc1t        L_801996C8
    if (c1cs) {
        // 0x801996AC: lui         $at, 0x43FA
        ctx->r1 = S32(0X43FA << 16);
            goto L_801996C8;
    }
    // 0x801996AC: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x801996B0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801996B4: nop

    // 0x801996B8: c.le.s      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.fl <= ctx->f10.fl;
    // 0x801996BC: nop

    // 0x801996C0: bc1f        L_801996D0
    if (!c1cs) {
        // 0x801996C4: nop
    
            goto L_801996D0;
    }
    // 0x801996C4: nop

L_801996C8:
    // 0x801996C8: b           L_80199D68
    // 0x801996CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80199D68;
    // 0x801996CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801996D0:
    // 0x801996D0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801996D4: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x801996D8: lui         $at, 0xC3FA
    ctx->r1 = S32(0XC3FA << 16);
    // 0x801996DC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801996E0: lwc1        $f6, 0xC8($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0XC8);
    // 0x801996E4: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x801996E8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801996EC: sub.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x801996F0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x801996F4: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x801996F8: lui         $at, 0xC37A
    ctx->r1 = S32(0XC37A << 16);
    // 0x801996FC: div.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80199700: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80199704: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x80199708: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019970C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80199710: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x80199714: swc1        $f10, 0xB0($t9)
    MEM_W(0XB0, ctx->r25) = ctx->f10.u32l;
    // 0x80199718: lwc1        $f18, 0xD0($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0XD0);
    // 0x8019971C: lui         $t9, 0x801D
    ctx->r25 = S32(0X801D << 16);
    // 0x80199720: sub.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x80199724: div.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80199728: swc1        $f16, 0xB4($t8)
    MEM_W(0XB4, ctx->r24) = ctx->f16.u32l;
    // 0x8019972C: lwc1        $f10, 0xB4($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0XB4);
    // 0x80199730: lwc1        $f6, 0xB0($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0XB0);
    // 0x80199734: trunc.w.s   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80199738: trunc.w.s   $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8019973C: mfc1        $t0, $f18
    ctx->r8 = (int32_t)ctx->f18.u32l;
    // 0x80199740: mfc1        $t4, $f4
    ctx->r12 = (int32_t)ctx->f4.u32l;
    // 0x80199744: sll         $t3, $t0, 2
    ctx->r11 = S32(ctx->r8 << 2);
    // 0x80199748: addu        $t3, $t3, $t0
    ctx->r11 = ADD32(ctx->r11, ctx->r8);
    // 0x8019974C: addu        $t7, $t3, $t4
    ctx->r15 = ADD32(ctx->r11, ctx->r12);
    // 0x80199750: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x80199754: addu        $t9, $t9, $t6
    ctx->r25 = ADD32(ctx->r25, ctx->r14);
    // 0x80199758: lw          $t9, 0x7780($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7780);
    // 0x8019975C: b           L_80199864
    // 0x80199760: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
        goto L_80199864;
    // 0x80199760: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
L_80199764:
    // 0x80199764: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80199768: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x8019976C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80199770: lwc1        $f16, 0xA08($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0XA08);
    // 0x80199774: lwc1        $f8, 0xC8($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0XC8);
    // 0x80199778: c.lt.s      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.fl < ctx->f16.fl;
    // 0x8019977C: nop

    // 0x80199780: bc1t        L_801997C8
    if (c1cs) {
        // 0x80199784: lui         $at, 0x801A
        ctx->r1 = S32(0X801A << 16);
            goto L_801997C8;
    }
    // 0x80199784: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80199788: lwc1        $f10, 0xA0C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0XA0C);
    // 0x8019978C: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x80199790: nop

    // 0x80199794: bc1t        L_801997C8
    if (c1cs) {
        // 0x80199798: lui         $at, 0xC3FA
        ctx->r1 = S32(0XC3FA << 16);
            goto L_801997C8;
    }
    // 0x80199798: lui         $at, 0xC3FA
    ctx->r1 = S32(0XC3FA << 16);
    // 0x8019979C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801997A0: lwc1        $f18, 0xD0($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0XD0);
    // 0x801997A4: c.lt.s      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.fl < ctx->f6.fl;
    // 0x801997A8: nop

    // 0x801997AC: bc1t        L_801997C8
    if (c1cs) {
        // 0x801997B0: lui         $at, 0x801A
        ctx->r1 = S32(0X801A << 16);
            goto L_801997C8;
    }
    // 0x801997B0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801997B4: lwc1        $f4, 0xA10($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XA10);
    // 0x801997B8: c.le.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl <= ctx->f18.fl;
    // 0x801997BC: nop

    // 0x801997C0: bc1f        L_801997D0
    if (!c1cs) {
        // 0x801997C4: nop
    
            goto L_801997D0;
    }
    // 0x801997C4: nop

L_801997C8:
    // 0x801997C8: b           L_80199D68
    // 0x801997CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80199D68;
    // 0x801997CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801997D0:
    // 0x801997D0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x801997D4: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x801997D8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801997DC: lwc1        $f8, 0xA14($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0XA14);
    // 0x801997E0: lwc1        $f16, 0xC8($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0XC8);
    // 0x801997E4: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x801997E8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801997EC: sub.s       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x801997F0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x801997F4: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x801997F8: lui         $at, 0xC3FA
    ctx->r1 = S32(0XC3FA << 16);
    // 0x801997FC: div.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80199800: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80199804: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x80199808: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019980C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80199810: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x80199814: swc1        $f18, 0xB0($t2)
    MEM_W(0XB0, ctx->r10) = ctx->f18.u32l;
    // 0x80199818: lwc1        $f4, 0xD0($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0XD0);
    // 0x8019981C: lui         $t2, 0x801E
    ctx->r10 = S32(0X801E << 16);
    // 0x80199820: sub.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x80199824: div.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80199828: swc1        $f6, 0xB4($t0)
    MEM_W(0XB4, ctx->r8) = ctx->f6.u32l;
    // 0x8019982C: lwc1        $f18, 0xB4($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0XB4);
    // 0x80199830: lwc1        $f16, 0xB0($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0XB0);
    // 0x80199834: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80199838: trunc.w.s   $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    ctx->f8.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8019983C: mfc1        $t3, $f4
    ctx->r11 = (int32_t)ctx->f4.u32l;
    // 0x80199840: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x80199844: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80199848: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8019984C: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x80199850: addu        $t9, $t4, $t6
    ctx->r25 = ADD32(ctx->r12, ctx->r14);
    // 0x80199854: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80199858: addu        $t2, $t2, $t8
    ctx->r10 = ADD32(ctx->r10, ctx->r24);
    // 0x8019985C: lw          $t2, 0x14C4($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X14C4);
    // 0x80199860: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
L_80199864:
    // 0x80199864: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
L_80199868:
    // 0x80199868: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8019986C: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x80199870: lui         $t1, 0x8000
    ctx->r9 = S32(0X8000 << 16);
    // 0x80199874: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80199878: addu        $t3, $t0, $t5
    ctx->r11 = ADD32(ctx->r8, ctx->r13);
    // 0x8019987C: addu        $t1, $t1, $t3
    ctx->r9 = ADD32(ctx->r9, ctx->r11);
    // 0x80199880: lbu         $t1, 0x400($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X400);
    // 0x80199884: bne         $t1, $at, L_80199894
    if (ctx->r9 != ctx->r1) {
        // 0x80199888: nop
    
            goto L_80199894;
    }
    // 0x80199888: nop

    // 0x8019988C: b           L_80199D68
    // 0x80199890: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80199D68;
    // 0x80199890: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80199894:
    // 0x80199894: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80199898: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x8019989C: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x801998A0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x801998A4: addu        $t6, $t7, $t4
    ctx->r14 = ADD32(ctx->r15, ctx->r12);
    // 0x801998A8: addu        $t9, $t9, $t6
    ctx->r25 = ADD32(ctx->r25, ctx->r14);
    // 0x801998AC: lbu         $t9, 0x401($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X401);
    // 0x801998B0: addiu       $t8, $t8, 0x3C00
    ctx->r24 = ADD32(ctx->r24, 0X3C00);
    // 0x801998B4: lui         $t3, 0x8000
    ctx->r11 = S32(0X8000 << 16);
    // 0x801998B8: sw          $t9, 0x50($t8)
    MEM_W(0X50, ctx->r24) = ctx->r25;
    // 0x801998BC: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x801998C0: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x801998C4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x801998C8: addiu       $t1, $t1, 0x3C00
    ctx->r9 = ADD32(ctx->r9, 0X3C00);
    // 0x801998CC: addu        $t5, $t2, $t0
    ctx->r13 = ADD32(ctx->r10, ctx->r8);
    // 0x801998D0: addu        $t3, $t3, $t5
    ctx->r11 = ADD32(ctx->r11, ctx->r13);
    // 0x801998D4: lbu         $t3, 0x402($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X402);
    // 0x801998D8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801998DC: addiu       $t7, $t7, 0x3C00
    ctx->r15 = ADD32(ctx->r15, 0X3C00);
    // 0x801998E0: sw          $t3, 0x54($t1)
    MEM_W(0X54, ctx->r9) = ctx->r11;
    // 0x801998E4: lw          $t4, 0x54($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X54);
    // 0x801998E8: lw          $t9, 0x50($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X50);
    // 0x801998EC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x801998F0: sll         $t6, $t4, 8
    ctx->r14 = S32(ctx->r12 << 8);
    // 0x801998F4: addu        $t8, $t6, $t9
    ctx->r24 = ADD32(ctx->r14, ctx->r25);
    // 0x801998F8: sw          $t8, 0x28($t7)
    MEM_W(0X28, ctx->r15) = ctx->r24;
    // 0x801998FC: addiu       $t2, $t2, 0x3C00
    ctx->r10 = ADD32(ctx->r10, 0X3C00);
    // 0x80199900: lw          $t0, 0x28($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X28);
    // 0x80199904: andi        $t5, $t0, 0x8000
    ctx->r13 = ctx->r8 & 0X8000;
    // 0x80199908: beq         $t5, $zero, L_80199960
    if (ctx->r13 == 0) {
        // 0x8019990C: nop
    
            goto L_80199960;
    }
    // 0x8019990C: nop

    // 0x80199910: andi        $t3, $t0, 0x7FFF
    ctx->r11 = ctx->r8 & 0X7FFF;
    // 0x80199914: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80199918: sw          $t3, 0x28($t2)
    MEM_W(0X28, ctx->r10) = ctx->r11;
    // 0x8019991C: addiu       $t1, $t1, 0x3C00
    ctx->r9 = ADD32(ctx->r9, 0X3C00);
    // 0x80199920: lw          $t4, 0x28($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X28);
    // 0x80199924: ori         $t6, $zero, 0x8000
    ctx->r14 = 0 | 0X8000;
    // 0x80199928: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8019992C: subu        $t9, $t6, $t4
    ctx->r25 = SUB32(ctx->r14, ctx->r12);
    // 0x80199930: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x80199934: bgez        $t9, L_8019994C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80199938: cvt.s.w     $f18, $f6
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.fl = CVT_S_W(ctx->f6.u32l);
            goto L_8019994C;
    }
    // 0x80199938: cvt.s.w     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8019993C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80199940: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80199944: nop

    // 0x80199948: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_8019994C:
    // 0x8019994C: sub.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x80199950: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80199954: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x80199958: b           L_80199994
    // 0x8019995C: swc1        $f16, 0xA0($t8)
    MEM_W(0XA0, ctx->r24) = ctx->f16.u32l;
        goto L_80199994;
    // 0x8019995C: swc1        $f16, 0xA0($t8)
    MEM_W(0XA0, ctx->r24) = ctx->f16.u32l;
L_80199960:
    // 0x80199960: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80199964: addiu       $t7, $t7, 0x3C00
    ctx->r15 = ADD32(ctx->r15, 0X3C00);
    // 0x80199968: lw          $t5, 0x28($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X28);
    // 0x8019996C: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x80199970: bgez        $t5, L_80199988
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80199974: cvt.s.w     $f6, $f8
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
            goto L_80199988;
    }
    // 0x80199974: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80199978: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8019997C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80199980: nop

    // 0x80199984: add.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f4.fl;
L_80199988:
    // 0x80199988: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8019998C: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x80199990: swc1        $f6, 0xA0($t0)
    MEM_W(0XA0, ctx->r8) = ctx->f6.u32l;
L_80199994:
    // 0x80199994: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80199998: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x8019999C: lwc1        $f10, 0xA0($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0XA0);
    // 0x801999A0: lwc1        $f18, 0xC8($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0XC8);
    // 0x801999A4: c.le.s      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.fl <= ctx->f18.fl;
    // 0x801999A8: nop

    // 0x801999AC: bc1f        L_80199D58
    if (!c1cs) {
        // 0x801999B0: nop
    
            goto L_80199D58;
    }
    // 0x801999B0: nop

    // 0x801999B4: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x801999B8: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x801999BC: lui         $t4, 0x8000
    ctx->r12 = S32(0X8000 << 16);
    // 0x801999C0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801999C4: addu        $t6, $t2, $t1
    ctx->r14 = ADD32(ctx->r10, ctx->r9);
    // 0x801999C8: addu        $t4, $t4, $t6
    ctx->r12 = ADD32(ctx->r12, ctx->r14);
    // 0x801999CC: lbu         $t4, 0x403($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X403);
    // 0x801999D0: addiu       $t9, $t9, 0x3C00
    ctx->r25 = ADD32(ctx->r25, 0X3C00);
    // 0x801999D4: lui         $t0, 0x8000
    ctx->r8 = S32(0X8000 << 16);
    // 0x801999D8: sw          $t4, 0x58($t9)
    MEM_W(0X58, ctx->r25) = ctx->r12;
    // 0x801999DC: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x801999E0: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x801999E4: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x801999E8: addiu       $t3, $t3, 0x3C00
    ctx->r11 = ADD32(ctx->r11, 0X3C00);
    // 0x801999EC: addu        $t5, $t8, $t7
    ctx->r13 = ADD32(ctx->r24, ctx->r15);
    // 0x801999F0: addu        $t0, $t0, $t5
    ctx->r8 = ADD32(ctx->r8, ctx->r13);
    // 0x801999F4: lbu         $t0, 0x404($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X404);
    // 0x801999F8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x801999FC: addiu       $t2, $t2, 0x3C00
    ctx->r10 = ADD32(ctx->r10, 0X3C00);
    // 0x80199A00: sw          $t0, 0x5C($t3)
    MEM_W(0X5C, ctx->r11) = ctx->r8;
    // 0x80199A04: lw          $t1, 0x5C($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X5C);
    // 0x80199A08: lw          $t4, 0x58($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X58);
    // 0x80199A0C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80199A10: sll         $t6, $t1, 8
    ctx->r14 = S32(ctx->r9 << 8);
    // 0x80199A14: addu        $t9, $t6, $t4
    ctx->r25 = ADD32(ctx->r14, ctx->r12);
    // 0x80199A18: sw          $t9, 0x2C($t2)
    MEM_W(0X2C, ctx->r10) = ctx->r25;
    // 0x80199A1C: addiu       $t8, $t8, 0x3C00
    ctx->r24 = ADD32(ctx->r24, 0X3C00);
    // 0x80199A20: lw          $t7, 0x2C($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X2C);
    // 0x80199A24: andi        $t5, $t7, 0x8000
    ctx->r13 = ctx->r15 & 0X8000;
    // 0x80199A28: beq         $t5, $zero, L_80199A80
    if (ctx->r13 == 0) {
        // 0x80199A2C: nop
    
            goto L_80199A80;
    }
    // 0x80199A2C: nop

    // 0x80199A30: andi        $t0, $t7, 0x7FFF
    ctx->r8 = ctx->r15 & 0X7FFF;
    // 0x80199A34: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80199A38: sw          $t0, 0x2C($t8)
    MEM_W(0X2C, ctx->r24) = ctx->r8;
    // 0x80199A3C: addiu       $t3, $t3, 0x3C00
    ctx->r11 = ADD32(ctx->r11, 0X3C00);
    // 0x80199A40: lw          $t1, 0x2C($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X2C);
    // 0x80199A44: ori         $t6, $zero, 0x8000
    ctx->r14 = 0 | 0X8000;
    // 0x80199A48: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80199A4C: subu        $t4, $t6, $t1
    ctx->r12 = SUB32(ctx->r14, ctx->r9);
    // 0x80199A50: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x80199A54: bgez        $t4, L_80199A6C
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80199A58: cvt.s.w     $f4, $f8
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
            goto L_80199A6C;
    }
    // 0x80199A58: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80199A5C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80199A60: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80199A64: nop

    // 0x80199A68: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_80199A6C:
    // 0x80199A6C: sub.s       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x80199A70: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80199A74: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x80199A78: b           L_80199AB4
    // 0x80199A7C: swc1        $f10, 0xA4($t9)
    MEM_W(0XA4, ctx->r25) = ctx->f10.u32l;
        goto L_80199AB4;
    // 0x80199A7C: swc1        $f10, 0xA4($t9)
    MEM_W(0XA4, ctx->r25) = ctx->f10.u32l;
L_80199A80:
    // 0x80199A80: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80199A84: addiu       $t2, $t2, 0x3C00
    ctx->r10 = ADD32(ctx->r10, 0X3C00);
    // 0x80199A88: lw          $t5, 0x2C($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X2C);
    // 0x80199A8C: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x80199A90: bgez        $t5, L_80199AA8
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80199A94: cvt.s.w     $f8, $f18
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
            goto L_80199AA8;
    }
    // 0x80199A94: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80199A98: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80199A9C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80199AA0: nop

    // 0x80199AA4: add.s       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f6.fl;
L_80199AA8:
    // 0x80199AA8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80199AAC: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x80199AB0: swc1        $f8, 0xA4($t7)
    MEM_W(0XA4, ctx->r15) = ctx->f8.u32l;
L_80199AB4:
    // 0x80199AB4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80199AB8: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x80199ABC: lwc1        $f16, 0xA4($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0XA4);
    // 0x80199AC0: lwc1        $f4, 0xCC($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0XCC);
    // 0x80199AC4: c.le.s      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.fl <= ctx->f4.fl;
    // 0x80199AC8: nop

    // 0x80199ACC: bc1f        L_80199D58
    if (!c1cs) {
        // 0x80199AD0: nop
    
            goto L_80199D58;
    }
    // 0x80199AD0: nop

    // 0x80199AD4: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80199AD8: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80199ADC: lui         $t1, 0x8000
    ctx->r9 = S32(0X8000 << 16);
    // 0x80199AE0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80199AE4: addu        $t6, $t8, $t3
    ctx->r14 = ADD32(ctx->r24, ctx->r11);
    // 0x80199AE8: addu        $t1, $t1, $t6
    ctx->r9 = ADD32(ctx->r9, ctx->r14);
    // 0x80199AEC: lbu         $t1, 0x405($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X405);
    // 0x80199AF0: addiu       $t4, $t4, 0x3C00
    ctx->r12 = ADD32(ctx->r12, 0X3C00);
    // 0x80199AF4: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x80199AF8: sw          $t1, 0x60($t4)
    MEM_W(0X60, ctx->r12) = ctx->r9;
    // 0x80199AFC: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80199B00: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80199B04: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80199B08: addiu       $t0, $t0, 0x3C00
    ctx->r8 = ADD32(ctx->r8, 0X3C00);
    // 0x80199B0C: addu        $t5, $t9, $t2
    ctx->r13 = ADD32(ctx->r25, ctx->r10);
    // 0x80199B10: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x80199B14: lbu         $t7, 0x406($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X406);
    // 0x80199B18: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80199B1C: addiu       $t8, $t8, 0x3C00
    ctx->r24 = ADD32(ctx->r24, 0X3C00);
    // 0x80199B20: sw          $t7, 0x64($t0)
    MEM_W(0X64, ctx->r8) = ctx->r15;
    // 0x80199B24: lw          $t3, 0x64($t8)
    ctx->r11 = MEM_W(ctx->r24, 0X64);
    // 0x80199B28: lw          $t1, 0x60($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X60);
    // 0x80199B2C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80199B30: sll         $t6, $t3, 8
    ctx->r14 = S32(ctx->r11 << 8);
    // 0x80199B34: addu        $t4, $t6, $t1
    ctx->r12 = ADD32(ctx->r14, ctx->r9);
    // 0x80199B38: sw          $t4, 0x30($t8)
    MEM_W(0X30, ctx->r24) = ctx->r12;
    // 0x80199B3C: addiu       $t9, $t9, 0x3C00
    ctx->r25 = ADD32(ctx->r25, 0X3C00);
    // 0x80199B40: lw          $t2, 0x30($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X30);
    // 0x80199B44: andi        $t5, $t2, 0x8000
    ctx->r13 = ctx->r10 & 0X8000;
    // 0x80199B48: beq         $t5, $zero, L_80199BA0
    if (ctx->r13 == 0) {
        // 0x80199B4C: nop
    
            goto L_80199BA0;
    }
    // 0x80199B4C: nop

    // 0x80199B50: andi        $t7, $t2, 0x7FFF
    ctx->r15 = ctx->r10 & 0X7FFF;
    // 0x80199B54: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80199B58: sw          $t7, 0x30($t9)
    MEM_W(0X30, ctx->r25) = ctx->r15;
    // 0x80199B5C: addiu       $t0, $t0, 0x3C00
    ctx->r8 = ADD32(ctx->r8, 0X3C00);
    // 0x80199B60: lw          $t3, 0x30($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X30);
    // 0x80199B64: ori         $t6, $zero, 0x8000
    ctx->r14 = 0 | 0X8000;
    // 0x80199B68: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80199B6C: subu        $t1, $t6, $t3
    ctx->r9 = SUB32(ctx->r14, ctx->r11);
    // 0x80199B70: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x80199B74: bgez        $t1, L_80199B8C
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80199B78: cvt.s.w     $f6, $f18
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
            goto L_80199B8C;
    }
    // 0x80199B78: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80199B7C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80199B80: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80199B84: nop

    // 0x80199B88: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80199B8C:
    // 0x80199B8C: sub.s       $f16, $f10, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x80199B90: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80199B94: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x80199B98: b           L_80199BD4
    // 0x80199B9C: swc1        $f16, 0xA8($t4)
    MEM_W(0XA8, ctx->r12) = ctx->f16.u32l;
        goto L_80199BD4;
    // 0x80199B9C: swc1        $f16, 0xA8($t4)
    MEM_W(0XA8, ctx->r12) = ctx->f16.u32l;
L_80199BA0:
    // 0x80199BA0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80199BA4: addiu       $t8, $t8, 0x3C00
    ctx->r24 = ADD32(ctx->r24, 0X3C00);
    // 0x80199BA8: lw          $t5, 0x30($t8)
    ctx->r13 = MEM_W(ctx->r24, 0X30);
    // 0x80199BAC: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x80199BB0: bgez        $t5, L_80199BC8
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80199BB4: cvt.s.w     $f18, $f4
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80199BC8;
    }
    // 0x80199BB4: cvt.s.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80199BB8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80199BBC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80199BC0: nop

    // 0x80199BC4: add.s       $f18, $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f8.fl;
L_80199BC8:
    // 0x80199BC8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80199BCC: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x80199BD0: swc1        $f18, 0xA8($t2)
    MEM_W(0XA8, ctx->r10) = ctx->f18.u32l;
L_80199BD4:
    // 0x80199BD4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80199BD8: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x80199BDC: lwc1        $f10, 0xA8($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0XA8);
    // 0x80199BE0: lwc1        $f6, 0xD0($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0XD0);
    // 0x80199BE4: c.le.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl <= ctx->f6.fl;
    // 0x80199BE8: nop

    // 0x80199BEC: bc1f        L_80199D58
    if (!c1cs) {
        // 0x80199BF0: nop
    
            goto L_80199D58;
    }
    // 0x80199BF0: nop

    // 0x80199BF4: lwc1        $f16, 0xC8($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0XC8);
    // 0x80199BF8: lwc1        $f4, 0xA0($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0XA0);
    // 0x80199BFC: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80199C00: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80199C04: sub.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x80199C08: lui         $t3, 0x8000
    ctx->r11 = S32(0X8000 << 16);
    // 0x80199C0C: addu        $t6, $t9, $t0
    ctx->r14 = ADD32(ctx->r25, ctx->r8);
    // 0x80199C10: addu        $t3, $t3, $t6
    ctx->r11 = ADD32(ctx->r11, ctx->r14);
    // 0x80199C14: swc1        $f8, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->f8.u32l;
    // 0x80199C18: lwc1        $f10, 0xA4($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0XA4);
    // 0x80199C1C: lwc1        $f18, 0xCC($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0XCC);
    // 0x80199C20: lbu         $t3, 0x407($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X407);
    // 0x80199C24: sub.s       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x80199C28: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x80199C2C: swc1        $f6, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f6.u32l;
    // 0x80199C30: lwc1        $f4, 0xA8($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0XA8);
    // 0x80199C34: lwc1        $f16, 0xD0($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0XD0);
    // 0x80199C38: cvt.s.w     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80199C3C: sub.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x80199C40: bgez        $t3, L_80199C58
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80199C44: swc1        $f8, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->f8.u32l;
            goto L_80199C58;
    }
    // 0x80199C44: swc1        $f8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f8.u32l;
    // 0x80199C48: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80199C4C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80199C50: nop

    // 0x80199C54: add.s       $f10, $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f6.fl;
L_80199C58:
    // 0x80199C58: swc1        $f10, 0xB4($t7)
    MEM_W(0XB4, ctx->r15) = ctx->f10.u32l;
    // 0x80199C5C: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80199C60: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80199C64: lui         $t5, 0x8000
    ctx->r13 = S32(0X8000 << 16);
    // 0x80199C68: addu        $t8, $t1, $t4
    ctx->r24 = ADD32(ctx->r9, ctx->r12);
    // 0x80199C6C: addu        $t5, $t5, $t8
    ctx->r13 = ADD32(ctx->r13, ctx->r24);
    // 0x80199C70: lbu         $t5, 0x408($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X408);
    // 0x80199C74: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x80199C78: bgez        $t5, L_80199C90
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80199C7C: cvt.s.w     $f4, $f16
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
            goto L_80199C90;
    }
    // 0x80199C7C: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80199C80: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80199C84: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80199C88: nop

    // 0x80199C8C: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
L_80199C90:
    // 0x80199C90: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80199C94: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x80199C98: swc1        $f4, 0xB8($t2)
    MEM_W(0XB8, ctx->r10) = ctx->f4.u32l;
    // 0x80199C9C: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80199CA0: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80199CA4: lui         $t3, 0x8000
    ctx->r11 = S32(0X8000 << 16);
    // 0x80199CA8: addu        $t6, $t9, $t0
    ctx->r14 = ADD32(ctx->r25, ctx->r8);
    // 0x80199CAC: addu        $t3, $t3, $t6
    ctx->r11 = ADD32(ctx->r11, ctx->r14);
    // 0x80199CB0: lbu         $t3, 0x409($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X409);
    // 0x80199CB4: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x80199CB8: bgez        $t3, L_80199CD0
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80199CBC: cvt.s.w     $f6, $f18
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
            goto L_80199CD0;
    }
    // 0x80199CBC: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80199CC0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80199CC4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80199CC8: nop

    // 0x80199CCC: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
L_80199CD0:
    // 0x80199CD0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80199CD4: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x80199CD8: swc1        $f6, 0xBC($t7)
    MEM_W(0XBC, ctx->r15) = ctx->f6.u32l;
    // 0x80199CDC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80199CE0: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x80199CE4: lwc1        $f16, 0xB4($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0XB4);
    // 0x80199CE8: lwc1        $f8, 0xC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XC);
    // 0x80199CEC: c.le.s      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.fl <= ctx->f16.fl;
    // 0x80199CF0: nop

    // 0x80199CF4: bc1f        L_80199D58
    if (!c1cs) {
        // 0x80199CF8: nop
    
            goto L_80199D58;
    }
    // 0x80199CF8: nop

    // 0x80199CFC: lwc1        $f4, 0xB8($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0XB8);
    // 0x80199D00: lwc1        $f18, 0x8($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X8);
    // 0x80199D04: c.le.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl <= ctx->f4.fl;
    // 0x80199D08: nop

    // 0x80199D0C: bc1f        L_80199D58
    if (!c1cs) {
        // 0x80199D10: nop
    
            goto L_80199D58;
    }
    // 0x80199D10: nop

    // 0x80199D14: lwc1        $f10, 0xBC($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0XBC);
    // 0x80199D18: lwc1        $f6, 0x4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4);
    // 0x80199D1C: c.le.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl <= ctx->f10.fl;
    // 0x80199D20: nop

    // 0x80199D24: bc1f        L_80199D58
    if (!c1cs) {
        // 0x80199D28: nop
    
            goto L_80199D58;
    }
    // 0x80199D28: nop

    // 0x80199D2C: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80199D30: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80199D34: lui         $t2, 0x8000
    ctx->r10 = S32(0X8000 << 16);
    // 0x80199D38: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80199D3C: addu        $t5, $t4, $t8
    ctx->r13 = ADD32(ctx->r12, ctx->r24);
    // 0x80199D40: addu        $t2, $t2, $t5
    ctx->r10 = ADD32(ctx->r10, ctx->r13);
    // 0x80199D44: lbu         $t2, 0x400($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X400);
    // 0x80199D48: addiu       $t9, $t9, 0x3B00
    ctx->r25 = ADD32(ctx->r25, 0X3B00);
    // 0x80199D4C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80199D50: b           L_80199D68
    // 0x80199D54: sb          $t2, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r10;
        goto L_80199D68;
    // 0x80199D54: sb          $t2, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r10;
L_80199D58:
    // 0x80199D58: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80199D5C: addiu       $t6, $t0, 0xA
    ctx->r14 = ADD32(ctx->r8, 0XA);
    // 0x80199D60: b           L_80199868
    // 0x80199D64: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
        goto L_80199868;
    // 0x80199D64: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
L_80199D68:
    // 0x80199D68: jr          $ra
    // 0x80199D6C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80199D6C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80199D70_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80199D70: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80199D74: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80199D78: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80199D7C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80199D80: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80199D84: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x80199D88: lwc1        $f4, 0xC8($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0XC8);
    // 0x80199D8C: lwc1        $f6, 0xDC($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0XDC);
    // 0x80199D90: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80199D94: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x80199D98: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80199D9C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80199DA0: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x80199DA4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80199DA8: swc1        $f8, 0xC8($t6)
    MEM_W(0XC8, ctx->r14) = ctx->f8.u32l;
    // 0x80199DAC: lwc1        $f10, 0xCC($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0XCC);
    // 0x80199DB0: lwc1        $f16, 0xE0($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0XE0);
    // 0x80199DB4: addiu       $t9, $t9, 0x3B00
    ctx->r25 = ADD32(ctx->r25, 0X3B00);
    // 0x80199DB8: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80199DBC: swc1        $f18, 0xCC($t7)
    MEM_W(0XCC, ctx->r15) = ctx->f18.u32l;
    // 0x80199DC0: lwc1        $f4, 0xD0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0XD0);
    // 0x80199DC4: lwc1        $f6, 0xE4($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0XE4);
    // 0x80199DC8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80199DCC: swc1        $f8, 0xD0($t8)
    MEM_W(0XD0, ctx->r24) = ctx->f8.u32l;
    // 0x80199DD0: lbu         $s0, 0x0($t9)
    ctx->r16 = MEM_BU(ctx->r25, 0X0);
    // 0x80199DD4: beq         $s0, $zero, L_80199DF4
    if (ctx->r16 == 0) {
        // 0x80199DD8: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80199DF4;
    }
    // 0x80199DD8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80199DDC: beq         $s0, $at, L_80199F38
    if (ctx->r16 == ctx->r1) {
        // 0x80199DE0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80199F38;
    }
    // 0x80199DE0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80199DE4: beq         $s0, $at, L_8019A02C
    if (ctx->r16 == ctx->r1) {
        // 0x80199DE8: nop
    
            goto L_8019A02C;
    }
    // 0x80199DE8: nop

    // 0x80199DEC: b           L_8019A0B8
    // 0x80199DF0: nop

        goto L_8019A0B8;
    // 0x80199DF0: nop

L_80199DF4:
    // 0x80199DF4: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80199DF8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80199DFC: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80199E00: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x80199E04: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80199E08: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80199E0C: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x80199E10: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80199E14: lw          $t2, 0xF98($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XF98);
    // 0x80199E18: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x80199E1C: sltiu       $at, $t3, 0xE
    ctx->r1 = ctx->r11 < 0XE ? 1 : 0;
    // 0x80199E20: beq         $at, $zero, L_8019A0B8
    if (ctx->r1 == 0) {
        // 0x80199E24: nop
    
            goto L_8019A0B8;
    }
    // 0x80199E24: nop

    // 0x80199E28: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80199E2C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80199E30: addu        $at, $at, $t3
    gpr jr_addend_80199E38 = ctx->r11;
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x80199E34: lw          $t3, 0xA18($at)
    ctx->r11 = ADD32(ctx->r1, 0XA18);
    // 0x80199E38: jr          $t3
    // 0x80199E3C: nop

    switch (jr_addend_80199E38 >> 2) {
        case 0: goto L_80199E40; break;
        case 1: goto L_80199E40; break;
        case 2: goto L_80199E40; break;
        case 3: goto L_80199E40; break;
        case 4: goto L_80199E40; break;
        case 5: goto L_80199E40; break;
        case 6: goto L_8019A0B8; break;
        case 7: goto L_8019A0B8; break;
        case 8: goto L_8019A0B8; break;
        case 9: goto L_80199E64; break;
        case 10: goto L_80199EA4; break;
        case 11: goto L_80199EC8; break;
        case 12: goto L_80199E40; break;
        case 13: goto L_80199F14; break;
        default: switch_error(__func__, 0x80199E38, 0x801A0A18);
    }
    // 0x80199E3C: nop

L_80199E40:
    // 0x80199E40: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80199E44: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x80199E48: lw          $a1, 0xC8($t4)
    ctx->r5 = MEM_W(ctx->r12, 0XC8);
    // 0x80199E4C: lw          $a2, 0xCC($t4)
    ctx->r6 = MEM_W(ctx->r12, 0XCC);
    // 0x80199E50: lw          $a3, 0xD0($t4)
    ctx->r7 = MEM_W(ctx->r12, 0XD0);
    // 0x80199E54: jal         0x8018AB30
    // 0x80199E58: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    func_8018AB30_1501A0(rdram, ctx);
        goto after_0;
    // 0x80199E58: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    after_0:
    // 0x80199E5C: b           L_8019A0B8
    // 0x80199E60: nop

        goto L_8019A0B8;
    // 0x80199E60: nop

L_80199E64:
    // 0x80199E64: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80199E68: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x80199E6C: lw          $a1, 0xC8($t5)
    ctx->r5 = MEM_W(ctx->r13, 0XC8);
    // 0x80199E70: lw          $a2, 0xCC($t5)
    ctx->r6 = MEM_W(ctx->r13, 0XCC);
    // 0x80199E74: lw          $a3, 0xD0($t5)
    ctx->r7 = MEM_W(ctx->r13, 0XD0);
    // 0x80199E78: jal         0x8018AB30
    // 0x80199E7C: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    func_8018AB30_1501A0(rdram, ctx);
        goto after_1;
    // 0x80199E7C: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    after_1:
    // 0x80199E80: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80199E84: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x80199E88: lw          $a1, 0xC8($t6)
    ctx->r5 = MEM_W(ctx->r14, 0XC8);
    // 0x80199E8C: lw          $a2, 0xCC($t6)
    ctx->r6 = MEM_W(ctx->r14, 0XCC);
    // 0x80199E90: lw          $a3, 0xD0($t6)
    ctx->r7 = MEM_W(ctx->r14, 0XD0);
    // 0x80199E94: jal         0x8018AB30
    // 0x80199E98: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    func_8018AB30_1501A0(rdram, ctx);
        goto after_2;
    // 0x80199E98: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    after_2:
    // 0x80199E9C: b           L_8019A0B8
    // 0x80199EA0: nop

        goto L_8019A0B8;
    // 0x80199EA0: nop

L_80199EA4:
    // 0x80199EA4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80199EA8: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x80199EAC: lw          $a1, 0xC8($t7)
    ctx->r5 = MEM_W(ctx->r15, 0XC8);
    // 0x80199EB0: lw          $a2, 0xCC($t7)
    ctx->r6 = MEM_W(ctx->r15, 0XCC);
    // 0x80199EB4: lw          $a3, 0xD0($t7)
    ctx->r7 = MEM_W(ctx->r15, 0XD0);
    // 0x80199EB8: jal         0x8018AB30
    // 0x80199EBC: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    func_8018AB30_1501A0(rdram, ctx);
        goto after_3;
    // 0x80199EBC: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_3:
    // 0x80199EC0: b           L_8019A0B8
    // 0x80199EC4: nop

        goto L_8019A0B8;
    // 0x80199EC4: nop

L_80199EC8:
    // 0x80199EC8: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80199ECC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80199ED0: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x80199ED4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80199ED8: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80199EDC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80199EE0: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80199EE4: lwc1        $f10, 0xD0($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0XD0);
    // 0x80199EE8: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80199EEC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80199EF0: addu        $a1, $a1, $t9
    ctx->r5 = ADD32(ctx->r5, ctx->r25);
    // 0x80199EF4: lw          $a2, 0xC8($t0)
    ctx->r6 = MEM_W(ctx->r8, 0XC8);
    // 0x80199EF8: lw          $a3, 0xCC($t0)
    ctx->r7 = MEM_W(ctx->r8, 0XCC);
    // 0x80199EFC: lw          $a1, 0xFA0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0XFA0);
    // 0x80199F00: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x80199F04: jal         0x8018AE94
    // 0x80199F08: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_8018AE94_1501A0(rdram, ctx);
        goto after_4;
    // 0x80199F08: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_4:
    // 0x80199F0C: b           L_8019A0B8
    // 0x80199F10: nop

        goto L_8019A0B8;
    // 0x80199F10: nop

L_80199F14:
    // 0x80199F14: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80199F18: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x80199F1C: lw          $a1, 0xC8($t1)
    ctx->r5 = MEM_W(ctx->r9, 0XC8);
    // 0x80199F20: lw          $a2, 0xCC($t1)
    ctx->r6 = MEM_W(ctx->r9, 0XCC);
    // 0x80199F24: lw          $a3, 0xD0($t1)
    ctx->r7 = MEM_W(ctx->r9, 0XD0);
    // 0x80199F28: jal         0x8018AB30
    // 0x80199F2C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    func_8018AB30_1501A0(rdram, ctx);
        goto after_5;
    // 0x80199F2C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_5:
    // 0x80199F30: b           L_8019A0B8
    // 0x80199F34: nop

        goto L_8019A0B8;
    // 0x80199F34: nop

L_80199F38:
    // 0x80199F38: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80199F3C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80199F40: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80199F44: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x80199F48: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80199F4C: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80199F50: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x80199F54: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x80199F58: lw          $t4, 0xF98($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XF98);
    // 0x80199F5C: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x80199F60: sltiu       $at, $t5, 0xE
    ctx->r1 = ctx->r13 < 0XE ? 1 : 0;
    // 0x80199F64: beq         $at, $zero, L_8019A0B8
    if (ctx->r1 == 0) {
        // 0x80199F68: nop
    
            goto L_8019A0B8;
    }
    // 0x80199F68: nop

    // 0x80199F6C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80199F70: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80199F74: addu        $at, $at, $t5
    gpr jr_addend_80199F7C = ctx->r13;
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x80199F78: lw          $t5, 0xA50($at)
    ctx->r13 = ADD32(ctx->r1, 0XA50);
    // 0x80199F7C: jr          $t5
    // 0x80199F80: nop

    switch (jr_addend_80199F7C >> 2) {
        case 0: goto L_80199F84; break;
        case 1: goto L_80199F84; break;
        case 2: goto L_80199F84; break;
        case 3: goto L_80199F84; break;
        case 4: goto L_80199F84; break;
        case 5: goto L_80199F84; break;
        case 6: goto L_8019A0B8; break;
        case 7: goto L_8019A0B8; break;
        case 8: goto L_8019A0B8; break;
        case 9: goto L_80199FD8; break;
        case 10: goto L_80199FD8; break;
        case 11: goto L_80199FD8; break;
        case 12: goto L_80199F84; break;
        case 13: goto L_80199FD8; break;
        default: switch_error(__func__, 0x80199F7C, 0x801A0A50);
    }
    // 0x80199F80: nop

L_80199F84:
    // 0x80199F84: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80199F88: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x80199F8C: lw          $a1, 0xC8($t6)
    ctx->r5 = MEM_W(ctx->r14, 0XC8);
    // 0x80199F90: lw          $a2, 0xCC($t6)
    ctx->r6 = MEM_W(ctx->r14, 0XCC);
    // 0x80199F94: lw          $a3, 0xD0($t6)
    ctx->r7 = MEM_W(ctx->r14, 0XD0);
    // 0x80199F98: jal         0x8018AB30
    // 0x80199F9C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_8018AB30_1501A0(rdram, ctx);
        goto after_6;
    // 0x80199F9C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_6:
    // 0x80199FA0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80199FA4: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x80199FA8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80199FAC: lwc1        $f18, 0xA88($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0XA88);
    // 0x80199FB0: lwc1        $f16, 0xCC($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0XCC);
    // 0x80199FB4: lw          $a1, 0xC8($t7)
    ctx->r5 = MEM_W(ctx->r15, 0XC8);
    // 0x80199FB8: lw          $a3, 0xD0($t7)
    ctx->r7 = MEM_W(ctx->r15, 0XD0);
    // 0x80199FBC: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80199FC0: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    // 0x80199FC4: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80199FC8: jal         0x8018AB30
    // 0x80199FCC: nop

    func_8018AB30_1501A0(rdram, ctx);
        goto after_7;
    // 0x80199FCC: nop

    after_7:
    // 0x80199FD0: b           L_8019A0B8
    // 0x80199FD4: nop

        goto L_8019A0B8;
    // 0x80199FD4: nop

L_80199FD8:
    // 0x80199FD8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80199FDC: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x80199FE0: lw          $a1, 0xC8($t8)
    ctx->r5 = MEM_W(ctx->r24, 0XC8);
    // 0x80199FE4: lw          $a2, 0xCC($t8)
    ctx->r6 = MEM_W(ctx->r24, 0XCC);
    // 0x80199FE8: lw          $a3, 0xD0($t8)
    ctx->r7 = MEM_W(ctx->r24, 0XD0);
    // 0x80199FEC: jal         0x8018AB30
    // 0x80199FF0: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    func_8018AB30_1501A0(rdram, ctx);
        goto after_8;
    // 0x80199FF0: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_8:
    // 0x80199FF4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80199FF8: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x80199FFC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019A000: lwc1        $f8, 0xA8C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0XA8C);
    // 0x8019A004: lwc1        $f6, 0xCC($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0XCC);
    // 0x8019A008: lw          $a1, 0xC8($t9)
    ctx->r5 = MEM_W(ctx->r25, 0XC8);
    // 0x8019A00C: lw          $a3, 0xD0($t9)
    ctx->r7 = MEM_W(ctx->r25, 0XD0);
    // 0x8019A010: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8019A014: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    // 0x8019A018: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8019A01C: jal         0x8018AB30
    // 0x8019A020: nop

    func_8018AB30_1501A0(rdram, ctx);
        goto after_9;
    // 0x8019A020: nop

    after_9:
    // 0x8019A024: b           L_8019A0B8
    // 0x8019A028: nop

        goto L_8019A0B8;
    // 0x8019A028: nop

L_8019A02C:
    // 0x8019A02C: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8019A030: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8019A034: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8019A038: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x8019A03C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8019A040: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8019A044: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x8019A048: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8019A04C: lw          $t2, 0xF98($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XF98);
    // 0x8019A050: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x8019A054: sltiu       $at, $t3, 0xE
    ctx->r1 = ctx->r11 < 0XE ? 1 : 0;
    // 0x8019A058: beq         $at, $zero, L_8019A0B8
    if (ctx->r1 == 0) {
        // 0x8019A05C: nop
    
            goto L_8019A0B8;
    }
    // 0x8019A05C: nop

    // 0x8019A060: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8019A064: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019A068: addu        $at, $at, $t3
    gpr jr_addend_8019A070 = ctx->r11;
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x8019A06C: lw          $t3, 0xA90($at)
    ctx->r11 = ADD32(ctx->r1, 0XA90);
    // 0x8019A070: jr          $t3
    // 0x8019A074: nop

    switch (jr_addend_8019A070 >> 2) {
        case 0: goto L_8019A078; break;
        case 1: goto L_8019A078; break;
        case 2: goto L_8019A078; break;
        case 3: goto L_8019A078; break;
        case 4: goto L_8019A078; break;
        case 5: goto L_8019A078; break;
        case 6: goto L_8019A0B8; break;
        case 7: goto L_8019A0B8; break;
        case 8: goto L_8019A0B8; break;
        case 9: goto L_8019A09C; break;
        case 10: goto L_8019A09C; break;
        case 11: goto L_8019A09C; break;
        case 12: goto L_8019A078; break;
        case 13: goto L_8019A09C; break;
        default: switch_error(__func__, 0x8019A070, 0x801A0A90);
    }
    // 0x8019A074: nop

L_8019A078:
    // 0x8019A078: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8019A07C: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x8019A080: lw          $a1, 0xC8($t4)
    ctx->r5 = MEM_W(ctx->r12, 0XC8);
    // 0x8019A084: lw          $a2, 0xCC($t4)
    ctx->r6 = MEM_W(ctx->r12, 0XCC);
    // 0x8019A088: lw          $a3, 0xD0($t4)
    ctx->r7 = MEM_W(ctx->r12, 0XD0);
    // 0x8019A08C: jal         0x8018AB30
    // 0x8019A090: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_8018AB30_1501A0(rdram, ctx);
        goto after_10;
    // 0x8019A090: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_10:
    // 0x8019A094: b           L_8019A0B8
    // 0x8019A098: nop

        goto L_8019A0B8;
    // 0x8019A098: nop

L_8019A09C:
    // 0x8019A09C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8019A0A0: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x8019A0A4: lw          $a1, 0xC8($t5)
    ctx->r5 = MEM_W(ctx->r13, 0XC8);
    // 0x8019A0A8: lw          $a2, 0xCC($t5)
    ctx->r6 = MEM_W(ctx->r13, 0XCC);
    // 0x8019A0AC: lw          $a3, 0xD0($t5)
    ctx->r7 = MEM_W(ctx->r13, 0XD0);
    // 0x8019A0B0: jal         0x8018AB30
    // 0x8019A0B4: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    func_8018AB30_1501A0(rdram, ctx);
        goto after_11;
    // 0x8019A0B4: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_11:
L_8019A0B8:
    // 0x8019A0B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8019A0BC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8019A0C0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8019A0C4: jr          $ra
    // 0x8019A0C8: nop

    return;
    // 0x8019A0C8: nop

;}
RECOMP_FUNC void func_8019A0CC_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019A0CC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8019A0D0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8019A0D4: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8019A0D8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8019A0DC: addiu       $t8, $t8, -0x2A28
    ctx->r24 = ADD32(ctx->r24, -0X2A28);
    // 0x8019A0E0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8019A0E4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8019A0E8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8019A0EC: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8019A0F0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8019A0F4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8019A0F8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8019A0FC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8019A100: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8019A104: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8019A108: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x8019A10C: andi        $t1, $t0, 0x4000
    ctx->r9 = ctx->r8 & 0X4000;
    // 0x8019A110: beq         $t1, $zero, L_8019A120
    if (ctx->r9 == 0) {
        // 0x8019A114: nop
    
            goto L_8019A120;
    }
    // 0x8019A114: nop

    // 0x8019A118: lw          $t2, 0x14($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X14);
    // 0x8019A11C: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
L_8019A120:
    // 0x8019A120: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8019A124: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x8019A128: lwc1        $f4, 0xC8($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0XC8);
    // 0x8019A12C: lwc1        $f6, 0xDC($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0XDC);
    // 0x8019A130: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8019A134: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x8019A138: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8019A13C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8019A140: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x8019A144: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8019A148: swc1        $f8, 0xC8($t3)
    MEM_W(0XC8, ctx->r11) = ctx->f8.u32l;
    // 0x8019A14C: lwc1        $f10, 0xCC($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0XCC);
    // 0x8019A150: lwc1        $f16, 0xE0($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0XE0);
    // 0x8019A154: addiu       $t8, $t8, -0x2A28
    ctx->r24 = ADD32(ctx->r24, -0X2A28);
    // 0x8019A158: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8019A15C: swc1        $f18, 0xCC($t4)
    MEM_W(0XCC, ctx->r12) = ctx->f18.u32l;
    // 0x8019A160: lwc1        $f4, 0xD0($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0XD0);
    // 0x8019A164: lwc1        $f6, 0xE4($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0XE4);
    // 0x8019A168: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8019A16C: swc1        $f8, 0xD0($t5)
    MEM_W(0XD0, ctx->r13) = ctx->f8.u32l;
    // 0x8019A170: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8019A174: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8019A178: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8019A17C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8019A180: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8019A184: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8019A188: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8019A18C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8019A190: addu        $t0, $t7, $t8
    ctx->r8 = ADD32(ctx->r15, ctx->r24);
    // 0x8019A194: lhu         $t1, 0x0($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X0);
    // 0x8019A198: andi        $t9, $t1, 0x1400
    ctx->r25 = ctx->r9 & 0X1400;
    // 0x8019A19C: bne         $t9, $zero, L_8019A638
    if (ctx->r25 != 0) {
        // 0x8019A1A0: nop
    
            goto L_8019A638;
    }
    // 0x8019A1A0: nop

    // 0x8019A1A4: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8019A1A8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8019A1AC: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8019A1B0: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8019A1B4: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x8019A1B8: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8019A1BC: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8019A1C0: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x8019A1C4: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8019A1C8: lw          $t4, 0xF98($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XF98);
    // 0x8019A1CC: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x8019A1D0: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x8019A1D4: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8019A1D8: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8019A1DC: lhu         $t6, -0x2318($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X2318);
    // 0x8019A1E0: sh          $t6, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r14;
    // 0x8019A1E4: lw          $t7, 0x20($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X20);
    // 0x8019A1E8: sltu        $at, $t6, $t7
    ctx->r1 = ctx->r14 < ctx->r15 ? 1 : 0;
    // 0x8019A1EC: beq         $at, $zero, L_8019A318
    if (ctx->r1 == 0) {
        // 0x8019A1F0: nop
    
            goto L_8019A318;
    }
    // 0x8019A1F0: nop

    // 0x8019A1F4: lhu         $t8, 0x0($t0)
    ctx->r24 = MEM_HU(ctx->r8, 0X0);
    // 0x8019A1F8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8019A1FC: addiu       $t3, $t3, -0x2A28
    ctx->r11 = ADD32(ctx->r11, -0X2A28);
    // 0x8019A200: ori         $t1, $t8, 0x200
    ctx->r9 = ctx->r24 | 0X200;
    // 0x8019A204: sh          $t1, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r9;
    // 0x8019A208: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8019A20C: lhu         $t7, 0x26($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X26);
    // 0x8019A210: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8019A214: sll         $t2, $t9, 2
    ctx->r10 = S32(ctx->r25 << 2);
    // 0x8019A218: addu        $t2, $t2, $t9
    ctx->r10 = ADD32(ctx->r10, ctx->r25);
    // 0x8019A21C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8019A220: subu        $t2, $t2, $t9
    ctx->r10 = SUB32(ctx->r10, ctx->r25);
    // 0x8019A224: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8019A228: addu        $t2, $t2, $t9
    ctx->r10 = ADD32(ctx->r10, ctx->r25);
    // 0x8019A22C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8019A230: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8019A234: lw          $t5, 0x20($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X20);
    // 0x8019A238: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8019A23C: subu        $t6, $t5, $t7
    ctx->r14 = SUB32(ctx->r13, ctx->r15);
    // 0x8019A240: sw          $t6, 0x20($t4)
    MEM_W(0X20, ctx->r12) = ctx->r14;
    // 0x8019A244: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8019A248: lw          $t0, -0x2E44($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2E44);
    // 0x8019A24C: sll         $t1, $t8, 2
    ctx->r9 = S32(ctx->r24 << 2);
    // 0x8019A250: addu        $t1, $t1, $t8
    ctx->r9 = ADD32(ctx->r9, ctx->r24);
    // 0x8019A254: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8019A258: subu        $t1, $t1, $t8
    ctx->r9 = SUB32(ctx->r9, ctx->r24);
    // 0x8019A25C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8019A260: addu        $t1, $t1, $t8
    ctx->r9 = ADD32(ctx->r9, ctx->r24);
    // 0x8019A264: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8019A268: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8019A26C: sw          $zero, -0x2A18($at)
    MEM_W(-0X2A18, ctx->r1) = 0;
    // 0x8019A270: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8019A274: bne         $t0, $at, L_8019A2BC
    if (ctx->r8 != ctx->r1) {
        // 0x8019A278: nop
    
            goto L_8019A2BC;
    }
    // 0x8019A278: nop

    // 0x8019A27C: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8019A280: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8019A284: addiu       $at, $zero, 0x61
    ctx->r1 = ADD32(0, 0X61);
    // 0x8019A288: sll         $t2, $t9, 2
    ctx->r10 = S32(ctx->r25 << 2);
    // 0x8019A28C: addu        $t2, $t2, $t9
    ctx->r10 = ADD32(ctx->r10, ctx->r25);
    // 0x8019A290: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8019A294: subu        $t2, $t2, $t9
    ctx->r10 = SUB32(ctx->r10, ctx->r25);
    // 0x8019A298: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8019A29C: addu        $t2, $t2, $t9
    ctx->r10 = ADD32(ctx->r10, ctx->r25);
    // 0x8019A2A0: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8019A2A4: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8019A2A8: lw          $t3, -0x2A24($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2A24);
    // 0x8019A2AC: bne         $t3, $at, L_8019A2BC
    if (ctx->r11 != ctx->r1) {
        // 0x8019A2B0: nop
    
            goto L_8019A2BC;
    }
    // 0x8019A2B0: nop

    // 0x8019A2B4: jal         0x800C8544
    // 0x8019A2B8: addiu       $a0, $zero, 0x5A
    ctx->r4 = ADD32(0, 0X5A);
    func_800C8544(rdram, ctx);
        goto after_0;
    // 0x8019A2B8: addiu       $a0, $zero, 0x5A
    ctx->r4 = ADD32(0, 0X5A);
    after_0:
L_8019A2BC:
    // 0x8019A2BC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8019A2C0: lw          $t5, -0x2E44($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2E44);
    // 0x8019A2C4: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8019A2C8: bne         $t5, $at, L_8019A414
    if (ctx->r13 != ctx->r1) {
        // 0x8019A2CC: nop
    
            goto L_8019A414;
    }
    // 0x8019A2CC: nop

    // 0x8019A2D0: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8019A2D4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8019A2D8: addiu       $at, $zero, 0x46
    ctx->r1 = ADD32(0, 0X46);
    // 0x8019A2DC: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x8019A2E0: addu        $t6, $t6, $t7
    ctx->r14 = ADD32(ctx->r14, ctx->r15);
    // 0x8019A2E4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8019A2E8: subu        $t6, $t6, $t7
    ctx->r14 = SUB32(ctx->r14, ctx->r15);
    // 0x8019A2EC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8019A2F0: addu        $t6, $t6, $t7
    ctx->r14 = ADD32(ctx->r14, ctx->r15);
    // 0x8019A2F4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8019A2F8: addu        $t4, $t4, $t6
    ctx->r12 = ADD32(ctx->r12, ctx->r14);
    // 0x8019A2FC: lw          $t4, -0x2A24($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2A24);
    // 0x8019A300: bne         $t4, $at, L_8019A414
    if (ctx->r12 != ctx->r1) {
        // 0x8019A304: nop
    
            goto L_8019A414;
    }
    // 0x8019A304: nop

    // 0x8019A308: jal         0x800C8544
    // 0x8019A30C: addiu       $a0, $zero, 0x6C
    ctx->r4 = ADD32(0, 0X6C);
    func_800C8544(rdram, ctx);
        goto after_1;
    // 0x8019A30C: addiu       $a0, $zero, 0x6C
    ctx->r4 = ADD32(0, 0X6C);
    after_1:
    // 0x8019A310: b           L_8019A414
    // 0x8019A314: nop

        goto L_8019A414;
    // 0x8019A314: nop

L_8019A318:
    // 0x8019A318: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8019A31C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8019A320: addiu       $t0, $t0, -0x2A28
    ctx->r8 = ADD32(ctx->r8, -0X2A28);
    // 0x8019A324: sll         $t1, $t8, 2
    ctx->r9 = S32(ctx->r24 << 2);
    // 0x8019A328: addu        $t1, $t1, $t8
    ctx->r9 = ADD32(ctx->r9, ctx->r24);
    // 0x8019A32C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8019A330: subu        $t1, $t1, $t8
    ctx->r9 = SUB32(ctx->r9, ctx->r24);
    // 0x8019A334: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8019A338: addu        $t1, $t1, $t8
    ctx->r9 = ADD32(ctx->r9, ctx->r24);
    // 0x8019A33C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8019A340: addu        $t9, $t1, $t0
    ctx->r25 = ADD32(ctx->r9, ctx->r8);
    // 0x8019A344: lhu         $t2, 0x0($t9)
    ctx->r10 = MEM_HU(ctx->r25, 0X0);
    // 0x8019A348: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8019A34C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8019A350: ori         $t3, $t2, 0x400
    ctx->r11 = ctx->r10 | 0X400;
    // 0x8019A354: sh          $t3, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r11;
    // 0x8019A358: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8019A35C: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8019A360: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8019A364: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x8019A368: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x8019A36C: sll         $t1, $t8, 2
    ctx->r9 = S32(ctx->r24 << 2);
    // 0x8019A370: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8019A374: addu        $t1, $t1, $t8
    ctx->r9 = ADD32(ctx->r9, ctx->r24);
    // 0x8019A378: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8019A37C: subu        $t7, $t7, $t5
    ctx->r15 = SUB32(ctx->r15, ctx->r13);
    // 0x8019A380: sll         $t4, $t6, 2
    ctx->r12 = S32(ctx->r14 << 2);
    // 0x8019A384: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8019A388: subu        $t1, $t1, $t8
    ctx->r9 = SUB32(ctx->r9, ctx->r24);
    // 0x8019A38C: subu        $t4, $t4, $t6
    ctx->r12 = SUB32(ctx->r12, ctx->r14);
    // 0x8019A390: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8019A394: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8019A398: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x8019A39C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8019A3A0: addu        $t1, $t1, $t8
    ctx->r9 = ADD32(ctx->r9, ctx->r24);
    // 0x8019A3A4: addu        $t4, $t4, $t6
    ctx->r12 = ADD32(ctx->r12, ctx->r14);
    // 0x8019A3A8: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8019A3AC: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x8019A3B0: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8019A3B4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8019A3B8: sw          $zero, -0x2A08($at)
    MEM_W(-0X2A08, ctx->r1) = 0;
    // 0x8019A3BC: addu        $a1, $a1, $t1
    ctx->r5 = ADD32(ctx->r5, ctx->r9);
    // 0x8019A3C0: addu        $a0, $a0, $t4
    ctx->r4 = ADD32(ctx->r4, ctx->r12);
    // 0x8019A3C4: lw          $a0, 0xFA0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XFA0);
    // 0x8019A3C8: jal         0x80193424
    // 0x8019A3CC: lw          $a1, -0x2A10($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X2A10);
    func_80193424_1501A0(rdram, ctx);
        goto after_2;
    // 0x8019A3CC: lw          $a1, -0x2A10($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X2A10);
    after_2:
    // 0x8019A3D0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8019A3D4: jal         0x8017C220
    // 0x8019A3D8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_8017C220_1501A0(rdram, ctx);
        goto after_3;
    // 0x8019A3D8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_3:
    // 0x8019A3DC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8019A3E0: jal         0x8017CCE4
    // 0x8019A3E4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_8017CCE4_1501A0(rdram, ctx);
        goto after_4;
    // 0x8019A3E4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_4:
    // 0x8019A3E8: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8019A3EC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8019A3F0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8019A3F4: sll         $t2, $t0, 2
    ctx->r10 = S32(ctx->r8 << 2);
    // 0x8019A3F8: subu        $t2, $t2, $t0
    ctx->r10 = SUB32(ctx->r10, ctx->r8);
    // 0x8019A3FC: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8019A400: addu        $t2, $t2, $t0
    ctx->r10 = ADD32(ctx->r10, ctx->r8);
    // 0x8019A404: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x8019A408: addu        $a0, $a0, $t2
    ctx->r4 = ADD32(ctx->r4, ctx->r10);
    // 0x8019A40C: jal         0x80193518
    // 0x8019A410: lw          $a0, 0xFA0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XFA0);
    func_80193518_1501A0(rdram, ctx);
        goto after_5;
    // 0x8019A410: lw          $a0, 0xFA0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XFA0);
    after_5:
L_8019A414:
    // 0x8019A414: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8019A418: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8019A41C: sll         $t9, $t3, 2
    ctx->r25 = S32(ctx->r11 << 2);
    // 0x8019A420: subu        $t9, $t9, $t3
    ctx->r25 = SUB32(ctx->r25, ctx->r11);
    // 0x8019A424: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8019A428: addu        $t9, $t9, $t3
    ctx->r25 = ADD32(ctx->r25, ctx->r11);
    // 0x8019A42C: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x8019A430: addu        $t5, $t5, $t9
    ctx->r13 = ADD32(ctx->r13, ctx->r25);
    // 0x8019A434: lw          $t5, 0xF98($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XF98);
    // 0x8019A438: addiu       $t7, $t5, -0x1
    ctx->r15 = ADD32(ctx->r13, -0X1);
    // 0x8019A43C: sltiu       $at, $t7, 0xE
    ctx->r1 = ctx->r15 < 0XE ? 1 : 0;
    // 0x8019A440: beq         $at, $zero, L_8019A798
    if (ctx->r1 == 0) {
        // 0x8019A444: nop
    
            goto L_8019A798;
    }
    // 0x8019A444: nop

    // 0x8019A448: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8019A44C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019A450: addu        $at, $at, $t7
    gpr jr_addend_8019A458 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8019A454: lw          $t7, 0xAC8($at)
    ctx->r15 = ADD32(ctx->r1, 0XAC8);
    // 0x8019A458: jr          $t7
    // 0x8019A45C: nop

    switch (jr_addend_8019A458 >> 2) {
        case 0: goto L_8019A460; break;
        case 1: goto L_8019A460; break;
        case 2: goto L_8019A460; break;
        case 3: goto L_8019A460; break;
        case 4: goto L_8019A460; break;
        case 5: goto L_8019A460; break;
        case 6: goto L_8019A798; break;
        case 7: goto L_8019A798; break;
        case 8: goto L_8019A798; break;
        case 9: goto L_8019A508; break;
        case 10: goto L_8019A548; break;
        case 11: goto L_8019A56C; break;
        case 12: goto L_8019A5B8; break;
        case 13: goto L_8019A614; break;
        default: switch_error(__func__, 0x8019A458, 0x801A0AC8);
    }
    // 0x8019A45C: nop

L_8019A460:
    // 0x8019A460: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8019A464: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8019A468: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8019A46C: sll         $t4, $t6, 2
    ctx->r12 = S32(ctx->r14 << 2);
    // 0x8019A470: subu        $t4, $t4, $t6
    ctx->r12 = SUB32(ctx->r12, ctx->r14);
    // 0x8019A474: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8019A478: addu        $t4, $t4, $t6
    ctx->r12 = ADD32(ctx->r12, ctx->r14);
    // 0x8019A47C: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x8019A480: addu        $t8, $t8, $t4
    ctx->r24 = ADD32(ctx->r24, ctx->r12);
    // 0x8019A484: lw          $t8, 0xFA0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XFA0);
    // 0x8019A488: addiu       $t0, $t0, 0x39A0
    ctx->r8 = ADD32(ctx->r8, 0X39A0);
    // 0x8019A48C: addiu       $at, $zero, 0x270F
    ctx->r1 = ADD32(0, 0X270F);
    // 0x8019A490: sll         $t1, $t8, 5
    ctx->r9 = S32(ctx->r24 << 5);
    // 0x8019A494: addu        $t2, $t1, $t0
    ctx->r10 = ADD32(ctx->r9, ctx->r8);
    // 0x8019A498: lw          $t3, 0x18($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X18);
    // 0x8019A49C: beq         $t3, $at, L_8019A4AC
    if (ctx->r11 == ctx->r1) {
        // 0x8019A4A0: nop
    
            goto L_8019A4AC;
    }
    // 0x8019A4A0: nop

    // 0x8019A4A4: addiu       $t9, $t3, 0x1
    ctx->r25 = ADD32(ctx->r11, 0X1);
    // 0x8019A4A8: sw          $t9, 0x18($t2)
    MEM_W(0X18, ctx->r10) = ctx->r25;
L_8019A4AC:
    // 0x8019A4AC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8019A4B0: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x8019A4B4: lw          $a1, 0xC8($t5)
    ctx->r5 = MEM_W(ctx->r13, 0XC8);
    // 0x8019A4B8: lw          $a2, 0xCC($t5)
    ctx->r6 = MEM_W(ctx->r13, 0XCC);
    // 0x8019A4BC: lw          $a3, 0xD0($t5)
    ctx->r7 = MEM_W(ctx->r13, 0XD0);
    // 0x8019A4C0: jal         0x8018AB30
    // 0x8019A4C4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8018AB30_1501A0(rdram, ctx);
        goto after_6;
    // 0x8019A4C4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_6:
    // 0x8019A4C8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8019A4CC: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x8019A4D0: lw          $a1, 0xC8($t7)
    ctx->r5 = MEM_W(ctx->r15, 0XC8);
    // 0x8019A4D4: lw          $a2, 0xCC($t7)
    ctx->r6 = MEM_W(ctx->r15, 0XCC);
    // 0x8019A4D8: lw          $a3, 0xD0($t7)
    ctx->r7 = MEM_W(ctx->r15, 0XD0);
    // 0x8019A4DC: jal         0x8018AB30
    // 0x8019A4E0: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    func_8018AB30_1501A0(rdram, ctx);
        goto after_7;
    // 0x8019A4E0: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    after_7:
    // 0x8019A4E4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8019A4E8: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x8019A4EC: lw          $a1, 0xC8($t6)
    ctx->r5 = MEM_W(ctx->r14, 0XC8);
    // 0x8019A4F0: lw          $a2, 0xCC($t6)
    ctx->r6 = MEM_W(ctx->r14, 0XCC);
    // 0x8019A4F4: lw          $a3, 0xD0($t6)
    ctx->r7 = MEM_W(ctx->r14, 0XD0);
    // 0x8019A4F8: jal         0x8019CC88
    // 0x8019A4FC: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    func_8019CC88_1501A0(rdram, ctx);
        goto after_8;
    // 0x8019A4FC: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_8:
    // 0x8019A500: b           L_8019A798
    // 0x8019A504: nop

        goto L_8019A798;
    // 0x8019A504: nop

L_8019A508:
    // 0x8019A508: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8019A50C: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x8019A510: lw          $a1, 0xC8($t4)
    ctx->r5 = MEM_W(ctx->r12, 0XC8);
    // 0x8019A514: lw          $a2, 0xCC($t4)
    ctx->r6 = MEM_W(ctx->r12, 0XCC);
    // 0x8019A518: lw          $a3, 0xD0($t4)
    ctx->r7 = MEM_W(ctx->r12, 0XD0);
    // 0x8019A51C: jal         0x8018AB30
    // 0x8019A520: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_8018AB30_1501A0(rdram, ctx);
        goto after_9;
    // 0x8019A520: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_9:
    // 0x8019A524: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8019A528: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x8019A52C: lw          $a1, 0xC8($t8)
    ctx->r5 = MEM_W(ctx->r24, 0XC8);
    // 0x8019A530: lw          $a2, 0xCC($t8)
    ctx->r6 = MEM_W(ctx->r24, 0XCC);
    // 0x8019A534: lw          $a3, 0xD0($t8)
    ctx->r7 = MEM_W(ctx->r24, 0XD0);
    // 0x8019A538: jal         0x8018AB30
    // 0x8019A53C: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    func_8018AB30_1501A0(rdram, ctx);
        goto after_10;
    // 0x8019A53C: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    after_10:
    // 0x8019A540: b           L_8019A798
    // 0x8019A544: nop

        goto L_8019A798;
    // 0x8019A544: nop

L_8019A548:
    // 0x8019A548: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8019A54C: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x8019A550: lw          $a1, 0xC8($t1)
    ctx->r5 = MEM_W(ctx->r9, 0XC8);
    // 0x8019A554: lw          $a2, 0xCC($t1)
    ctx->r6 = MEM_W(ctx->r9, 0XCC);
    // 0x8019A558: lw          $a3, 0xD0($t1)
    ctx->r7 = MEM_W(ctx->r9, 0XD0);
    // 0x8019A55C: jal         0x8018AB30
    // 0x8019A560: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    func_8018AB30_1501A0(rdram, ctx);
        goto after_11;
    // 0x8019A560: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_11:
    // 0x8019A564: b           L_8019A798
    // 0x8019A568: nop

        goto L_8019A798;
    // 0x8019A568: nop

L_8019A56C:
    // 0x8019A56C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8019A570: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8019A574: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x8019A578: sll         $t3, $t0, 2
    ctx->r11 = S32(ctx->r8 << 2);
    // 0x8019A57C: subu        $t3, $t3, $t0
    ctx->r11 = SUB32(ctx->r11, ctx->r8);
    // 0x8019A580: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8019A584: addu        $t3, $t3, $t0
    ctx->r11 = ADD32(ctx->r11, ctx->r8);
    // 0x8019A588: lwc1        $f10, 0xD0($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0XD0);
    // 0x8019A58C: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x8019A590: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8019A594: addu        $a1, $a1, $t3
    ctx->r5 = ADD32(ctx->r5, ctx->r11);
    // 0x8019A598: lw          $a2, 0xC8($t9)
    ctx->r6 = MEM_W(ctx->r25, 0XC8);
    // 0x8019A59C: lw          $a3, 0xCC($t9)
    ctx->r7 = MEM_W(ctx->r25, 0XCC);
    // 0x8019A5A0: lw          $a1, 0xFA0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0XFA0);
    // 0x8019A5A4: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x8019A5A8: jal         0x8018AE94
    // 0x8019A5AC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_8018AE94_1501A0(rdram, ctx);
        goto after_12;
    // 0x8019A5AC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_12:
    // 0x8019A5B0: b           L_8019A798
    // 0x8019A5B4: nop

        goto L_8019A798;
    // 0x8019A5B4: nop

L_8019A5B8:
    // 0x8019A5B8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8019A5BC: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x8019A5C0: lw          $a1, 0xC8($t2)
    ctx->r5 = MEM_W(ctx->r10, 0XC8);
    // 0x8019A5C4: lw          $a2, 0xCC($t2)
    ctx->r6 = MEM_W(ctx->r10, 0XCC);
    // 0x8019A5C8: lw          $a3, 0xD0($t2)
    ctx->r7 = MEM_W(ctx->r10, 0XD0);
    // 0x8019A5CC: jal         0x8018AB30
    // 0x8019A5D0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8018AB30_1501A0(rdram, ctx);
        goto after_13;
    // 0x8019A5D0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_13:
    // 0x8019A5D4: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8019A5D8: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x8019A5DC: lw          $a1, 0xC8($t5)
    ctx->r5 = MEM_W(ctx->r13, 0XC8);
    // 0x8019A5E0: lw          $a2, 0xCC($t5)
    ctx->r6 = MEM_W(ctx->r13, 0XCC);
    // 0x8019A5E4: lw          $a3, 0xD0($t5)
    ctx->r7 = MEM_W(ctx->r13, 0XD0);
    // 0x8019A5E8: jal         0x8018AB30
    // 0x8019A5EC: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    func_8018AB30_1501A0(rdram, ctx);
        goto after_14;
    // 0x8019A5EC: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    after_14:
    // 0x8019A5F0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8019A5F4: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x8019A5F8: lw          $a1, 0xC8($t7)
    ctx->r5 = MEM_W(ctx->r15, 0XC8);
    // 0x8019A5FC: lw          $a2, 0xCC($t7)
    ctx->r6 = MEM_W(ctx->r15, 0XCC);
    // 0x8019A600: lw          $a3, 0xD0($t7)
    ctx->r7 = MEM_W(ctx->r15, 0XD0);
    // 0x8019A604: jal         0x8019CC88
    // 0x8019A608: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    func_8019CC88_1501A0(rdram, ctx);
        goto after_15;
    // 0x8019A608: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_15:
    // 0x8019A60C: b           L_8019A798
    // 0x8019A610: nop

        goto L_8019A798;
    // 0x8019A610: nop

L_8019A614:
    // 0x8019A614: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8019A618: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x8019A61C: lw          $a1, 0xC8($t6)
    ctx->r5 = MEM_W(ctx->r14, 0XC8);
    // 0x8019A620: lw          $a2, 0xCC($t6)
    ctx->r6 = MEM_W(ctx->r14, 0XCC);
    // 0x8019A624: lw          $a3, 0xD0($t6)
    ctx->r7 = MEM_W(ctx->r14, 0XD0);
    // 0x8019A628: jal         0x8018AB30
    // 0x8019A62C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    func_8018AB30_1501A0(rdram, ctx);
        goto after_16;
    // 0x8019A62C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_16:
    // 0x8019A630: b           L_8019A798
    // 0x8019A634: nop

        goto L_8019A798;
    // 0x8019A634: nop

L_8019A638:
    // 0x8019A638: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8019A63C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8019A640: sll         $t8, $t4, 2
    ctx->r24 = S32(ctx->r12 << 2);
    // 0x8019A644: subu        $t8, $t8, $t4
    ctx->r24 = SUB32(ctx->r24, ctx->r12);
    // 0x8019A648: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8019A64C: addu        $t8, $t8, $t4
    ctx->r24 = ADD32(ctx->r24, ctx->r12);
    // 0x8019A650: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8019A654: addu        $t1, $t1, $t8
    ctx->r9 = ADD32(ctx->r9, ctx->r24);
    // 0x8019A658: lw          $t1, 0xF98($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XF98);
    // 0x8019A65C: addiu       $t0, $t1, -0x1
    ctx->r8 = ADD32(ctx->r9, -0X1);
    // 0x8019A660: sltiu       $at, $t0, 0xE
    ctx->r1 = ctx->r8 < 0XE ? 1 : 0;
    // 0x8019A664: beq         $at, $zero, L_8019A798
    if (ctx->r1 == 0) {
        // 0x8019A668: nop
    
            goto L_8019A798;
    }
    // 0x8019A668: nop

    // 0x8019A66C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8019A670: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019A674: addu        $at, $at, $t0
    gpr jr_addend_8019A67C = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x8019A678: lw          $t0, 0xB00($at)
    ctx->r8 = ADD32(ctx->r1, 0XB00);
    // 0x8019A67C: jr          $t0
    // 0x8019A680: nop

    switch (jr_addend_8019A67C >> 2) {
        case 0: goto L_8019A684; break;
        case 1: goto L_8019A684; break;
        case 2: goto L_8019A684; break;
        case 3: goto L_8019A684; break;
        case 4: goto L_8019A684; break;
        case 5: goto L_8019A684; break;
        case 6: goto L_8019A798; break;
        case 7: goto L_8019A798; break;
        case 8: goto L_8019A798; break;
        case 9: goto L_8019A6A8; break;
        case 10: goto L_8019A6E8; break;
        case 11: goto L_8019A70C; break;
        case 12: goto L_8019A758; break;
        case 13: goto L_8019A77C; break;
        default: switch_error(__func__, 0x8019A67C, 0x801A0B00);
    }
    // 0x8019A680: nop

L_8019A684:
    // 0x8019A684: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8019A688: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x8019A68C: lw          $a1, 0xC8($t3)
    ctx->r5 = MEM_W(ctx->r11, 0XC8);
    // 0x8019A690: lw          $a2, 0xCC($t3)
    ctx->r6 = MEM_W(ctx->r11, 0XCC);
    // 0x8019A694: lw          $a3, 0xD0($t3)
    ctx->r7 = MEM_W(ctx->r11, 0XD0);
    // 0x8019A698: jal         0x8018AB30
    // 0x8019A69C: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    func_8018AB30_1501A0(rdram, ctx);
        goto after_17;
    // 0x8019A69C: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    after_17:
    // 0x8019A6A0: b           L_8019A798
    // 0x8019A6A4: nop

        goto L_8019A798;
    // 0x8019A6A4: nop

L_8019A6A8:
    // 0x8019A6A8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8019A6AC: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x8019A6B0: lw          $a1, 0xC8($t9)
    ctx->r5 = MEM_W(ctx->r25, 0XC8);
    // 0x8019A6B4: lw          $a2, 0xCC($t9)
    ctx->r6 = MEM_W(ctx->r25, 0XCC);
    // 0x8019A6B8: lw          $a3, 0xD0($t9)
    ctx->r7 = MEM_W(ctx->r25, 0XD0);
    // 0x8019A6BC: jal         0x8018AB30
    // 0x8019A6C0: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_8018AB30_1501A0(rdram, ctx);
        goto after_18;
    // 0x8019A6C0: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_18:
    // 0x8019A6C4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8019A6C8: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x8019A6CC: lw          $a1, 0xC8($t2)
    ctx->r5 = MEM_W(ctx->r10, 0XC8);
    // 0x8019A6D0: lw          $a2, 0xCC($t2)
    ctx->r6 = MEM_W(ctx->r10, 0XCC);
    // 0x8019A6D4: lw          $a3, 0xD0($t2)
    ctx->r7 = MEM_W(ctx->r10, 0XD0);
    // 0x8019A6D8: jal         0x8018AB30
    // 0x8019A6DC: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    func_8018AB30_1501A0(rdram, ctx);
        goto after_19;
    // 0x8019A6DC: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    after_19:
    // 0x8019A6E0: b           L_8019A798
    // 0x8019A6E4: nop

        goto L_8019A798;
    // 0x8019A6E4: nop

L_8019A6E8:
    // 0x8019A6E8: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8019A6EC: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x8019A6F0: lw          $a1, 0xC8($t5)
    ctx->r5 = MEM_W(ctx->r13, 0XC8);
    // 0x8019A6F4: lw          $a2, 0xCC($t5)
    ctx->r6 = MEM_W(ctx->r13, 0XCC);
    // 0x8019A6F8: lw          $a3, 0xD0($t5)
    ctx->r7 = MEM_W(ctx->r13, 0XD0);
    // 0x8019A6FC: jal         0x8018AB30
    // 0x8019A700: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    func_8018AB30_1501A0(rdram, ctx);
        goto after_20;
    // 0x8019A700: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_20:
    // 0x8019A704: b           L_8019A798
    // 0x8019A708: nop

        goto L_8019A798;
    // 0x8019A708: nop

L_8019A70C:
    // 0x8019A70C: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8019A710: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8019A714: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x8019A718: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x8019A71C: subu        $t6, $t6, $t7
    ctx->r14 = SUB32(ctx->r14, ctx->r15);
    // 0x8019A720: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8019A724: addu        $t6, $t6, $t7
    ctx->r14 = ADD32(ctx->r14, ctx->r15);
    // 0x8019A728: lwc1        $f16, 0xD0($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0XD0);
    // 0x8019A72C: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8019A730: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8019A734: addu        $a1, $a1, $t6
    ctx->r5 = ADD32(ctx->r5, ctx->r14);
    // 0x8019A738: lw          $a2, 0xC8($t4)
    ctx->r6 = MEM_W(ctx->r12, 0XC8);
    // 0x8019A73C: lw          $a3, 0xCC($t4)
    ctx->r7 = MEM_W(ctx->r12, 0XCC);
    // 0x8019A740: lw          $a1, 0xFA0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0XFA0);
    // 0x8019A744: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x8019A748: jal         0x8018AE94
    // 0x8019A74C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_8018AE94_1501A0(rdram, ctx);
        goto after_21;
    // 0x8019A74C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_21:
    // 0x8019A750: b           L_8019A798
    // 0x8019A754: nop

        goto L_8019A798;
    // 0x8019A754: nop

L_8019A758:
    // 0x8019A758: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8019A75C: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x8019A760: lw          $a1, 0xC8($t8)
    ctx->r5 = MEM_W(ctx->r24, 0XC8);
    // 0x8019A764: lw          $a2, 0xCC($t8)
    ctx->r6 = MEM_W(ctx->r24, 0XCC);
    // 0x8019A768: lw          $a3, 0xD0($t8)
    ctx->r7 = MEM_W(ctx->r24, 0XD0);
    // 0x8019A76C: jal         0x8018AB30
    // 0x8019A770: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    func_8018AB30_1501A0(rdram, ctx);
        goto after_22;
    // 0x8019A770: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    after_22:
    // 0x8019A774: b           L_8019A798
    // 0x8019A778: nop

        goto L_8019A798;
    // 0x8019A778: nop

L_8019A77C:
    // 0x8019A77C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8019A780: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x8019A784: lw          $a1, 0xC8($t1)
    ctx->r5 = MEM_W(ctx->r9, 0XC8);
    // 0x8019A788: lw          $a2, 0xCC($t1)
    ctx->r6 = MEM_W(ctx->r9, 0XCC);
    // 0x8019A78C: lw          $a3, 0xD0($t1)
    ctx->r7 = MEM_W(ctx->r9, 0XD0);
    // 0x8019A790: jal         0x8018AB30
    // 0x8019A794: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    func_8018AB30_1501A0(rdram, ctx);
        goto after_23;
    // 0x8019A794: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_23:
L_8019A798:
    // 0x8019A798: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8019A79C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8019A7A0: jr          $ra
    // 0x8019A7A4: nop

    return;
    // 0x8019A7A4: nop

;}
RECOMP_FUNC void func_8019A7A8_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019A7A8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8019A7AC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8019A7B0: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8019A7B4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8019A7B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8019A7BC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8019A7C0: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8019A7C4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8019A7C8: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8019A7CC: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8019A7D0: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8019A7D4: lw          $t8, 0xF98($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XF98);
    // 0x8019A7D8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8019A7DC: addiu       $t9, $t8, -0x58
    ctx->r25 = ADD32(ctx->r24, -0X58);
    // 0x8019A7E0: sltiu       $at, $t9, 0x25
    ctx->r1 = ctx->r25 < 0X25 ? 1 : 0;
    // 0x8019A7E4: beq         $at, $zero, L_8019A828
    if (ctx->r1 == 0) {
        // 0x8019A7E8: nop
    
            goto L_8019A828;
    }
    // 0x8019A7E8: nop

    // 0x8019A7EC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8019A7F0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019A7F4: addu        $at, $at, $t9
    gpr jr_addend_8019A7FC = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8019A7F8: lw          $t9, 0xB38($at)
    ctx->r25 = ADD32(ctx->r1, 0XB38);
    // 0x8019A7FC: jr          $t9
    // 0x8019A800: nop

    switch (jr_addend_8019A7FC >> 2) {
        case 0: goto L_8019A804; break;
        case 1: goto L_8019A828; break;
        case 2: goto L_8019A828; break;
        case 3: goto L_8019A828; break;
        case 4: goto L_8019A828; break;
        case 5: goto L_8019A828; break;
        case 6: goto L_8019A828; break;
        case 7: goto L_8019A828; break;
        case 8: goto L_8019A828; break;
        case 9: goto L_8019A828; break;
        case 10: goto L_8019A828; break;
        case 11: goto L_8019A828; break;
        case 12: goto L_8019A828; break;
        case 13: goto L_8019A828; break;
        case 14: goto L_8019A828; break;
        case 15: goto L_8019A828; break;
        case 16: goto L_8019A828; break;
        case 17: goto L_8019A828; break;
        case 18: goto L_8019A828; break;
        case 19: goto L_8019A828; break;
        case 20: goto L_8019A828; break;
        case 21: goto L_8019A828; break;
        case 22: goto L_8019A804; break;
        case 23: goto L_8019A804; break;
        case 24: goto L_8019A804; break;
        case 25: goto L_8019A828; break;
        case 26: goto L_8019A828; break;
        case 27: goto L_8019A828; break;
        case 28: goto L_8019A828; break;
        case 29: goto L_8019A828; break;
        case 30: goto L_8019A828; break;
        case 31: goto L_8019A828; break;
        case 32: goto L_8019A828; break;
        case 33: goto L_8019A828; break;
        case 34: goto L_8019A828; break;
        case 35: goto L_8019A828; break;
        case 36: goto L_8019A804; break;
        default: switch_error(__func__, 0x8019A7FC, 0x801A0B38);
    }
    // 0x8019A800: nop

L_8019A804:
    // 0x8019A804: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8019A808: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x8019A80C: lw          $a1, 0xC8($t0)
    ctx->r5 = MEM_W(ctx->r8, 0XC8);
    // 0x8019A810: lw          $a2, 0xCC($t0)
    ctx->r6 = MEM_W(ctx->r8, 0XCC);
    // 0x8019A814: lw          $a3, 0xD0($t0)
    ctx->r7 = MEM_W(ctx->r8, 0XD0);
    // 0x8019A818: jal         0x8018AB30
    // 0x8019A81C: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    func_8018AB30_1501A0(rdram, ctx);
        goto after_0;
    // 0x8019A81C: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    after_0:
    // 0x8019A820: b           L_8019A97C
    // 0x8019A824: nop

        goto L_8019A97C;
    // 0x8019A824: nop

L_8019A828:
    // 0x8019A828: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8019A82C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8019A830: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8019A834: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8019A838: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x8019A83C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8019A840: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8019A844: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8019A848: addiu       $t3, $t3, 0xF98
    ctx->r11 = ADD32(ctx->r11, 0XF98);
    // 0x8019A84C: addu        $t7, $t6, $t3
    ctx->r15 = ADD32(ctx->r14, ctx->r11);
    // 0x8019A850: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8019A854: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8019A858: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x8019A85C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8019A860: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x8019A864: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8019A868: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8019A86C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8019A870: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x8019A874: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x8019A878: addu        $a1, $a1, $t9
    ctx->r5 = ADD32(ctx->r5, ctx->r25);
    // 0x8019A87C: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8019A880: lw          $a0, 0x8($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X8);
    // 0x8019A884: jal         0x80193424
    // 0x8019A888: lhu         $a1, -0x2316($a1)
    ctx->r5 = MEM_HU(ctx->r5, -0X2316);
    func_80193424_1501A0(rdram, ctx);
        goto after_1;
    // 0x8019A888: lhu         $a1, -0x2316($a1)
    ctx->r5 = MEM_HU(ctx->r5, -0X2316);
    after_1:
    // 0x8019A88C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8019A890: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8019A894: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8019A898: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8019A89C: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x8019A8A0: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8019A8A4: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8019A8A8: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x8019A8AC: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8019A8B0: lw          $t2, 0xF98($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XF98);
    // 0x8019A8B4: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x8019A8B8: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8019A8BC: sll         $t4, $t2, 3
    ctx->r12 = S32(ctx->r10 << 3);
    // 0x8019A8C0: subu        $t4, $t4, $t2
    ctx->r12 = SUB32(ctx->r12, ctx->r10);
    // 0x8019A8C4: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8019A8C8: addu        $a0, $a0, $t4
    ctx->r4 = ADD32(ctx->r4, ctx->r12);
    // 0x8019A8CC: lhu         $a0, -0x2314($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X2314);
    // 0x8019A8D0: lw          $a1, 0xC8($t5)
    ctx->r5 = MEM_W(ctx->r13, 0XC8);
    // 0x8019A8D4: lw          $a2, 0xCC($t5)
    ctx->r6 = MEM_W(ctx->r13, 0XCC);
    // 0x8019A8D8: jal         0x8018AB30
    // 0x8019A8DC: lw          $a3, 0xD0($t5)
    ctx->r7 = MEM_W(ctx->r13, 0XD0);
    func_8018AB30_1501A0(rdram, ctx);
        goto after_2;
    // 0x8019A8DC: lw          $a3, 0xD0($t5)
    ctx->r7 = MEM_W(ctx->r13, 0XD0);
    after_2:
    // 0x8019A8E0: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8019A8E4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8019A8E8: addiu       $t7, $t7, 0xF98
    ctx->r15 = ADD32(ctx->r15, 0XF98);
    // 0x8019A8EC: sll         $t3, $t6, 2
    ctx->r11 = S32(ctx->r14 << 2);
    // 0x8019A8F0: subu        $t3, $t3, $t6
    ctx->r11 = SUB32(ctx->r11, ctx->r14);
    // 0x8019A8F4: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8019A8F8: addu        $t3, $t3, $t6
    ctx->r11 = ADD32(ctx->r11, ctx->r14);
    // 0x8019A8FC: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x8019A900: addu        $t8, $t3, $t7
    ctx->r24 = ADD32(ctx->r11, ctx->r15);
    // 0x8019A904: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8019A908: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8019A90C: lw          $a1, 0x18($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X18);
    // 0x8019A910: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x8019A914: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x8019A918: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8019A91C: addu        $a0, $a0, $t0
    ctx->r4 = ADD32(ctx->r4, ctx->r8);
    // 0x8019A920: lhu         $a0, -0x2314($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X2314);
    // 0x8019A924: lw          $a2, 0x1C($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X1C);
    // 0x8019A928: jal         0x8018AB30
    // 0x8019A92C: lw          $a3, 0x20($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X20);
    func_8018AB30_1501A0(rdram, ctx);
        goto after_3;
    // 0x8019A92C: lw          $a3, 0x20($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X20);
    after_3:
    // 0x8019A930: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8019A934: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8019A938: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8019A93C: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x8019A940: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8019A944: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8019A948: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x8019A94C: addu        $a0, $a0, $t2
    ctx->r4 = ADD32(ctx->r4, ctx->r10);
    // 0x8019A950: jal         0x800C8124
    // 0x8019A954: lw          $a0, 0xF9C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XF9C);
    func_800C8124(rdram, ctx);
        goto after_4;
    // 0x8019A954: lw          $a0, 0xF9C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XF9C);
    after_4:
    // 0x8019A958: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x8019A95C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8019A960: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8019A964: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x8019A968: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8019A96C: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8019A970: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8019A974: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x8019A978: sw          $zero, 0xF98($at)
    MEM_W(0XF98, ctx->r1) = 0;
L_8019A97C:
    // 0x8019A97C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8019A980: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8019A984: jr          $ra
    // 0x8019A988: nop

    return;
    // 0x8019A988: nop

;}
RECOMP_FUNC void func_8019A98C_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019A98C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8019A990: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8019A994: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8019A998: jal         0x8019B688
    // 0x8019A99C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8019B688_1501A0(rdram, ctx);
        goto after_0;
    // 0x8019A99C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_0:
    // 0x8019A9A0: bne         $v0, $zero, L_8019A9B0
    if (ctx->r2 != 0) {
        // 0x8019A9A4: nop
    
            goto L_8019A9B0;
    }
    // 0x8019A9A4: nop

    // 0x8019A9A8: b           L_8019AB28
    // 0x8019A9AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8019AB28;
    // 0x8019A9AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8019A9B0:
    // 0x8019A9B0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8019A9B4: lw          $t6, -0x2E48($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2E48);
    // 0x8019A9B8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8019A9BC: beq         $t6, $at, L_8019AA28
    if (ctx->r14 == ctx->r1) {
        // 0x8019A9C0: nop
    
            goto L_8019AA28;
    }
    // 0x8019A9C0: nop

    // 0x8019A9C4: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8019A9C8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8019A9CC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8019A9D0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8019A9D4: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8019A9D8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8019A9DC: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8019A9E0: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8019A9E4: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8019A9E8: lw          $t9, 0xF98($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XF98);
    // 0x8019A9EC: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x8019A9F0: lwc1        $f4, 0x58($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X58);
    // 0x8019A9F4: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x8019A9F8: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x8019A9FC: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8019AA00: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8019AA04: addu        $a0, $a0, $t0
    ctx->r4 = ADD32(ctx->r4, ctx->r8);
    // 0x8019AA08: lw          $a2, 0x50($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X50);
    // 0x8019AA0C: lw          $a3, 0x54($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X54);
    // 0x8019AA10: lhu         $a0, -0x2318($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X2318);
    // 0x8019AA14: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x8019AA18: jal         0x8019AC88
    // 0x8019AA1C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_8019AC88_1501A0(rdram, ctx);
        goto after_1;
    // 0x8019AA1C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8019AA20: b           L_8019AB24
    // 0x8019AA24: nop

        goto L_8019AB24;
    // 0x8019AA24: nop

L_8019AA28:
    // 0x8019AA28: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8019AA2C: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x8019AA30: lwc1        $f12, 0x50($t2)
    ctx->f12.u32l = MEM_W(ctx->r10, 0X50);
    // 0x8019AA34: lwc1        $f14, 0x54($t2)
    ctx->f14.u32l = MEM_W(ctx->r10, 0X54);
    // 0x8019AA38: jal         0x8019C46C
    // 0x8019AA3C: lw          $a2, 0x58($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X58);
    func_8019C46C_1501A0(rdram, ctx);
        goto after_2;
    // 0x8019AA3C: lw          $a2, 0x58($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X58);
    after_2:
    // 0x8019AA40: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8019AA44: addiu       $t3, $t3, 0x3D00
    ctx->r11 = ADD32(ctx->r11, 0X3D00);
    // 0x8019AA48: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8019AA4C: bgez        $t4, L_8019AAC8
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8019AA50: nop
    
            goto L_8019AAC8;
    }
    // 0x8019AA50: nop

    // 0x8019AA54: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x8019AA58: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8019AA5C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8019AA60: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8019AA64: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x8019AA68: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8019AA6C: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8019AA70: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8019AA74: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x8019AA78: lw          $t8, 0xF98($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XF98);
    // 0x8019AA7C: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x8019AA80: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8019AA84: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x8019AA88: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8019AA8C: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8019AA90: lwc1        $f6, 0x58($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X58);
    // 0x8019AA94: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8019AA98: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x8019AA9C: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x8019AAA0: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8019AAA4: addu        $a0, $a0, $t9
    ctx->r4 = ADD32(ctx->r4, ctx->r25);
    // 0x8019AAA8: lw          $a2, 0x50($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X50);
    // 0x8019AAAC: lw          $a3, 0x54($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X54);
    // 0x8019AAB0: lhu         $a0, -0x2318($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X2318);
    // 0x8019AAB4: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
    // 0x8019AAB8: jal         0x8019AFB0
    // 0x8019AABC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_8019AFB0_1501A0(rdram, ctx);
        goto after_3;
    // 0x8019AABC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_3:
    // 0x8019AAC0: b           L_8019AB24
    // 0x8019AAC4: nop

        goto L_8019AB24;
    // 0x8019AAC4: nop

L_8019AAC8:
    // 0x8019AAC8: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8019AACC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8019AAD0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8019AAD4: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8019AAD8: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x8019AADC: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8019AAE0: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8019AAE4: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x8019AAE8: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8019AAEC: lw          $t4, 0xF98($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XF98);
    // 0x8019AAF0: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x8019AAF4: lwc1        $f8, 0x58($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X58);
    // 0x8019AAF8: sll         $t6, $t4, 3
    ctx->r14 = S32(ctx->r12 << 3);
    // 0x8019AAFC: subu        $t6, $t6, $t4
    ctx->r14 = SUB32(ctx->r14, ctx->r12);
    // 0x8019AB00: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8019AB04: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8019AB08: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x8019AB0C: lw          $a2, 0x50($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X50);
    // 0x8019AB10: lw          $a3, 0x54($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X54);
    // 0x8019AB14: lhu         $a0, -0x2318($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X2318);
    // 0x8019AB18: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    // 0x8019AB1C: jal         0x8019B31C
    // 0x8019AB20: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_8019B31C_1501A0(rdram, ctx);
        goto after_4;
    // 0x8019AB20: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_4:
L_8019AB24:
    // 0x8019AB24: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8019AB28:
    // 0x8019AB28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8019AB2C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8019AB30: jr          $ra
    // 0x8019AB34: nop

    return;
    // 0x8019AB34: nop

;}
RECOMP_FUNC void func_8019AB38_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019AB38: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8019AB3C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8019AB40: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8019AB44: jal         0x8019BA3C
    // 0x8019AB48: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8019BA3C_1501A0(rdram, ctx);
        goto after_0;
    // 0x8019AB48: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_0:
    // 0x8019AB4C: bne         $v0, $zero, L_8019AB5C
    if (ctx->r2 != 0) {
        // 0x8019AB50: nop
    
            goto L_8019AB5C;
    }
    // 0x8019AB50: nop

    // 0x8019AB54: b           L_8019AC78
    // 0x8019AB58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8019AC78;
    // 0x8019AB58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8019AB5C:
    // 0x8019AB5C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8019AB60: lw          $t6, -0x2E48($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2E48);
    // 0x8019AB64: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8019AB68: beq         $t6, $at, L_8019ABCC
    if (ctx->r14 == ctx->r1) {
        // 0x8019AB6C: nop
    
            goto L_8019ABCC;
    }
    // 0x8019AB6C: nop

    // 0x8019AB70: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8019AB74: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8019AB78: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8019AB7C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8019AB80: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8019AB84: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8019AB88: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8019AB8C: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8019AB90: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8019AB94: lw          $t9, 0xF98($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XF98);
    // 0x8019AB98: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8019AB9C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8019ABA0: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x8019ABA4: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x8019ABA8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8019ABAC: addu        $a0, $a0, $t0
    ctx->r4 = ADD32(ctx->r4, ctx->r8);
    // 0x8019ABB0: lhu         $a0, -0x2318($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X2318);
    // 0x8019ABB4: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x8019ABB8: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x8019ABBC: jal         0x8019AC88
    // 0x8019ABC0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_8019AC88_1501A0(rdram, ctx);
        goto after_1;
    // 0x8019ABC0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8019ABC4: b           L_8019AC74
    // 0x8019ABC8: nop

        goto L_8019AC74;
    // 0x8019ABC8: nop

L_8019ABCC:
    // 0x8019ABCC: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8019ABD0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8019ABD4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8019ABD8: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8019ABDC: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x8019ABE0: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8019ABE4: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8019ABE8: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x8019ABEC: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8019ABF0: lw          $t3, 0xF98($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XF98);
    // 0x8019ABF4: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8019ABF8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8019ABFC: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x8019AC00: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x8019AC04: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8019AC08: addu        $a0, $a0, $t4
    ctx->r4 = ADD32(ctx->r4, ctx->r12);
    // 0x8019AC0C: lhu         $a0, -0x2318($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X2318);
    // 0x8019AC10: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x8019AC14: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x8019AC18: jal         0x8019AFB0
    // 0x8019AC1C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_8019AFB0_1501A0(rdram, ctx);
        goto after_2;
    // 0x8019AC1C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x8019AC20: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x8019AC24: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8019AC28: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8019AC2C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8019AC30: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x8019AC34: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8019AC38: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8019AC3C: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8019AC40: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x8019AC44: lw          $t8, 0xF98($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XF98);
    // 0x8019AC48: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8019AC4C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8019AC50: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x8019AC54: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8019AC58: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8019AC5C: addu        $a0, $a0, $t9
    ctx->r4 = ADD32(ctx->r4, ctx->r25);
    // 0x8019AC60: lhu         $a0, -0x2318($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X2318);
    // 0x8019AC64: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x8019AC68: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
    // 0x8019AC6C: jal         0x8019B31C
    // 0x8019AC70: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_8019B31C_1501A0(rdram, ctx);
        goto after_3;
    // 0x8019AC70: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_3:
L_8019AC74:
    // 0x8019AC74: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_8019AC78:
    // 0x8019AC78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8019AC7C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8019AC80: jr          $ra
    // 0x8019AC84: nop

    return;
    // 0x8019AC84: nop

;}
RECOMP_FUNC void func_8019AC88_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019AC88: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8019AC8C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8019AC90: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8019AC94: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8019AC98: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8019AC9C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8019ACA0: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8019ACA4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8019ACA8: addiu       $t6, $t6, -0x2BA8
    ctx->r14 = ADD32(ctx->r14, -0X2BA8);
    // 0x8019ACAC: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8019ACB0: beq         $t7, $zero, L_8019AF9C
    if (ctx->r15 == 0) {
        // 0x8019ACB4: nop
    
            goto L_8019AF9C;
    }
    // 0x8019ACB4: nop

    // 0x8019ACB8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8019ACBC: addiu       $t8, $t8, -0x2E18
    ctx->r24 = ADD32(ctx->r24, -0X2E18);
    // 0x8019ACC0: lw          $t9, 0x68($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X68);
    // 0x8019ACC4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8019ACC8: bne         $t9, $at, L_8019ACD4
    if (ctx->r25 != ctx->r1) {
        // 0x8019ACCC: nop
    
            goto L_8019ACD4;
    }
    // 0x8019ACCC: nop

    // 0x8019ACD0: sw          $zero, 0x68($t8)
    MEM_W(0X68, ctx->r24) = 0;
L_8019ACD4:
    // 0x8019ACD4: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8019ACD8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8019ACDC: bne         $t0, $at, L_8019ACF4
    if (ctx->r8 != ctx->r1) {
        // 0x8019ACE0: nop
    
            goto L_8019ACF4;
    }
    // 0x8019ACE0: nop

    // 0x8019ACE4: jal         0x800C8544
    // 0x8019ACE8: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    func_800C8544(rdram, ctx);
        goto after_0;
    // 0x8019ACE8: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_0:
    // 0x8019ACEC: b           L_8019AD3C
    // 0x8019ACF0: nop

        goto L_8019AD3C;
    // 0x8019ACF0: nop

L_8019ACF4:
    // 0x8019ACF4: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x8019ACF8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8019ACFC: addiu       $at, $zero, 0x6F
    ctx->r1 = ADD32(0, 0X6F);
    // 0x8019AD00: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8019AD04: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x8019AD08: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8019AD0C: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8019AD10: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x8019AD14: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8019AD18: lw          $t3, 0xF98($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XF98);
    // 0x8019AD1C: bne         $t3, $at, L_8019AD34
    if (ctx->r11 != ctx->r1) {
        // 0x8019AD20: nop
    
            goto L_8019AD34;
    }
    // 0x8019AD20: nop

    // 0x8019AD24: jal         0x800C8544
    // 0x8019AD28: addiu       $a0, $zero, 0x63
    ctx->r4 = ADD32(0, 0X63);
    func_800C8544(rdram, ctx);
        goto after_1;
    // 0x8019AD28: addiu       $a0, $zero, 0x63
    ctx->r4 = ADD32(0, 0X63);
    after_1:
    // 0x8019AD2C: b           L_8019AD3C
    // 0x8019AD30: nop

        goto L_8019AD3C;
    // 0x8019AD30: nop

L_8019AD34:
    // 0x8019AD34: jal         0x800C8544
    // 0x8019AD38: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    func_800C8544(rdram, ctx);
        goto after_2;
    // 0x8019AD38: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_2:
L_8019AD3C:
    // 0x8019AD3C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8019AD40: lw          $t4, -0x2E3C($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2E3C);
    // 0x8019AD44: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8019AD48: beq         $t4, $zero, L_8019AD7C
    if (ctx->r12 == 0) {
        // 0x8019AD4C: nop
    
            goto L_8019AD7C;
    }
    // 0x8019AD4C: nop

L_8019AD50:
    // 0x8019AD50: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8019AD54: jal         0x8019BDA4
    // 0x8019AD58: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_8019BDA4_1501A0(rdram, ctx);
        goto after_3;
    // 0x8019AD58: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x8019AD5C: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8019AD60: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8019AD64: lw          $t7, -0x2E3C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2E3C);
    // 0x8019AD68: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8019AD6C: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x8019AD70: sltu        $at, $t6, $t7
    ctx->r1 = ctx->r14 < ctx->r15 ? 1 : 0;
    // 0x8019AD74: bne         $at, $zero, L_8019AD50
    if (ctx->r1 != 0) {
        // 0x8019AD78: nop
    
            goto L_8019AD50;
    }
    // 0x8019AD78: nop

L_8019AD7C:
    // 0x8019AD7C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8019AD80: addiu       $t9, $t9, -0x2BA8
    ctx->r25 = ADD32(ctx->r25, -0X2BA8);
    // 0x8019AD84: lw          $t8, 0xC($t9)
    ctx->r24 = MEM_W(ctx->r25, 0XC);
    // 0x8019AD88: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8019AD8C: sltu        $at, $t0, $t8
    ctx->r1 = ctx->r8 < ctx->r24 ? 1 : 0;
    // 0x8019AD90: beq         $at, $zero, L_8019ADA4
    if (ctx->r1 == 0) {
        // 0x8019AD94: nop
    
            goto L_8019ADA4;
    }
    // 0x8019AD94: nop

    // 0x8019AD98: subu        $t1, $t8, $t0
    ctx->r9 = SUB32(ctx->r24, ctx->r8);
    // 0x8019AD9C: b           L_8019AF04
    // 0x8019ADA0: sw          $t1, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->r9;
        goto L_8019AF04;
    // 0x8019ADA0: sw          $t1, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->r9;
L_8019ADA4:
    // 0x8019ADA4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8019ADA8: addiu       $t2, $t2, -0x2E18
    ctx->r10 = ADD32(ctx->r10, -0X2E18);
    // 0x8019ADAC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8019ADB0: addiu       $t3, $t3, -0x2E18
    ctx->r11 = ADD32(ctx->r11, -0X2E18);
    // 0x8019ADB4: sw          $zero, 0x78($t2)
    MEM_W(0X78, ctx->r10) = 0;
    // 0x8019ADB8: lw          $s0, 0x78($t3)
    ctx->r16 = MEM_W(ctx->r11, 0X78);
    // 0x8019ADBC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8019ADC0: addiu       $t4, $t4, -0x2BA8
    ctx->r12 = ADD32(ctx->r12, -0X2BA8);
    // 0x8019ADC4: sw          $s0, 0x70($t3)
    MEM_W(0X70, ctx->r11) = ctx->r16;
    // 0x8019ADC8: jal         0x80189E60
    // 0x8019ADCC: sw          $s0, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r16;
    func_80189E60_1501A0(rdram, ctx);
        goto after_4;
    // 0x8019ADCC: sw          $s0, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r16;
    after_4:
    // 0x8019ADD0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8019ADD4: lw          $t5, -0x2E3C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2E3C);
    // 0x8019ADD8: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8019ADDC: beq         $t5, $zero, L_8019AF04
    if (ctx->r13 == 0) {
        // 0x8019ADE0: nop
    
            goto L_8019AF04;
    }
    // 0x8019ADE0: nop

L_8019ADE4:
    // 0x8019ADE4: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
L_8019ADE8:
    // 0x8019ADE8: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8019ADEC: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8019ADF0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8019ADF4: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8019ADF8: sll         $t0, $t8, 3
    ctx->r8 = S32(ctx->r24 << 3);
    // 0x8019ADFC: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8019AE00: subu        $t0, $t0, $t8
    ctx->r8 = SUB32(ctx->r8, ctx->r24);
    // 0x8019AE04: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x8019AE08: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x8019AE0C: addu        $t1, $t7, $t0
    ctx->r9 = ADD32(ctx->r15, ctx->r8);
    // 0x8019AE10: addiu       $t9, $t9, 0x3518
    ctx->r25 = ADD32(ctx->r25, 0X3518);
    // 0x8019AE14: addu        $t2, $t1, $t9
    ctx->r10 = ADD32(ctx->r9, ctx->r25);
    // 0x8019AE18: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8019AE1C: beq         $t3, $zero, L_8019AED0
    if (ctx->r11 == 0) {
        // 0x8019AE20: nop
    
            goto L_8019AED0;
    }
    // 0x8019AE20: nop

    // 0x8019AE24: addu        $t4, $t7, $t0
    ctx->r12 = ADD32(ctx->r15, ctx->r8);
    // 0x8019AE28: addu        $t5, $t4, $t9
    ctx->r13 = ADD32(ctx->r12, ctx->r25);
    // 0x8019AE2C: sw          $zero, 0x0($t5)
    MEM_W(0X0, ctx->r13) = 0;
    // 0x8019AE30: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8019AE34: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8019AE38: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8019AE3C: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x8019AE40: sll         $t8, $t6, 3
    ctx->r24 = S32(ctx->r14 << 3);
    // 0x8019AE44: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x8019AE48: subu        $t8, $t8, $t6
    ctx->r24 = SUB32(ctx->r24, ctx->r14);
    // 0x8019AE4C: sll         $t8, $t8, 5
    ctx->r24 = S32(ctx->r24 << 5);
    // 0x8019AE50: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x8019AE54: addu        $t3, $t8, $t2
    ctx->r11 = ADD32(ctx->r24, ctx->r10);
    // 0x8019AE58: addiu       $t7, $t7, 0x3518
    ctx->r15 = ADD32(ctx->r15, 0X3518);
    // 0x8019AE5C: addu        $t0, $t3, $t7
    ctx->r8 = ADD32(ctx->r11, ctx->r15);
    // 0x8019AE60: lw          $t4, 0x4($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X4);
    // 0x8019AE64: addiu       $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
    // 0x8019AE68: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8019AE6C: sll         $t9, $t4, 2
    ctx->r25 = S32(ctx->r12 << 2);
    // 0x8019AE70: addu        $t9, $t9, $t4
    ctx->r25 = ADD32(ctx->r25, ctx->r12);
    // 0x8019AE74: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8019AE78: subu        $t9, $t9, $t4
    ctx->r25 = SUB32(ctx->r25, ctx->r12);
    // 0x8019AE7C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8019AE80: addu        $t9, $t9, $t4
    ctx->r25 = ADD32(ctx->r25, ctx->r12);
    // 0x8019AE84: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8019AE88: addiu       $t5, $t5, -0x2A28
    ctx->r13 = ADD32(ctx->r13, -0X2A28);
    // 0x8019AE8C: sllv        $t4, $t0, $t6
    ctx->r12 = S32(ctx->r8 << (ctx->r14 & 31));
    // 0x8019AE90: addu        $t1, $t9, $t5
    ctx->r9 = ADD32(ctx->r25, ctx->r13);
    // 0x8019AE94: addu        $t0, $t8, $t2
    ctx->r8 = ADD32(ctx->r24, ctx->r10);
    // 0x8019AE98: lhu         $t3, 0x0($t1)
    ctx->r11 = MEM_HU(ctx->r9, 0X0);
    // 0x8019AE9C: addu        $t6, $t0, $t7
    ctx->r14 = ADD32(ctx->r8, ctx->r15);
    // 0x8019AEA0: xori        $t9, $t4, 0xFFFF
    ctx->r25 = ctx->r12 ^ 0XFFFF;
    // 0x8019AEA4: lw          $t4, 0x4($t6)
    ctx->r12 = MEM_W(ctx->r14, 0X4);
    // 0x8019AEA8: and         $t1, $t3, $t9
    ctx->r9 = ctx->r11 & ctx->r25;
    // 0x8019AEAC: sll         $t3, $t4, 2
    ctx->r11 = S32(ctx->r12 << 2);
    // 0x8019AEB0: addu        $t3, $t3, $t4
    ctx->r11 = ADD32(ctx->r11, ctx->r12);
    // 0x8019AEB4: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8019AEB8: subu        $t3, $t3, $t4
    ctx->r11 = SUB32(ctx->r11, ctx->r12);
    // 0x8019AEBC: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8019AEC0: addu        $t3, $t3, $t4
    ctx->r11 = ADD32(ctx->r11, ctx->r12);
    // 0x8019AEC4: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8019AEC8: addu        $t9, $t3, $t5
    ctx->r25 = ADD32(ctx->r11, ctx->r13);
    // 0x8019AECC: sh          $t1, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r9;
L_8019AED0:
    // 0x8019AED0: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8019AED4: addiu       $t2, $t8, 0x1
    ctx->r10 = ADD32(ctx->r24, 0X1);
    // 0x8019AED8: sltiu       $at, $t2, 0x4
    ctx->r1 = ctx->r10 < 0X4 ? 1 : 0;
    // 0x8019AEDC: bne         $at, $zero, L_8019ADE8
    if (ctx->r1 != 0) {
        // 0x8019AEE0: sw          $t2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r10;
            goto L_8019ADE8;
    }
    // 0x8019AEE0: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x8019AEE4: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8019AEE8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8019AEEC: lw          $t6, -0x2E3C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2E3C);
    // 0x8019AEF0: addiu       $t7, $t0, 0x1
    ctx->r15 = ADD32(ctx->r8, 0X1);
    // 0x8019AEF4: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x8019AEF8: sltu        $at, $t7, $t6
    ctx->r1 = ctx->r15 < ctx->r14 ? 1 : 0;
    // 0x8019AEFC: bne         $at, $zero, L_8019ADE4
    if (ctx->r1 != 0) {
        // 0x8019AF00: nop
    
            goto L_8019ADE4;
    }
    // 0x8019AF00: nop

L_8019AF04:
    // 0x8019AF04: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x8019AF08: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8019AF0C: beq         $t4, $at, L_8019AF88
    if (ctx->r12 == ctx->r1) {
        // 0x8019AF10: nop
    
            goto L_8019AF88;
    }
    // 0x8019AF10: nop

    // 0x8019AF14: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8019AF18: lwc1        $f14, 0x3C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8019AF1C: jal         0x8019C46C
    // 0x8019AF20: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    func_8019C46C_1501A0(rdram, ctx);
        goto after_5;
    // 0x8019AF20: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    after_5:
    // 0x8019AF24: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x8019AF28: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8019AF2C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8019AF30: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x8019AF34: subu        $t5, $t5, $t3
    ctx->r13 = SUB32(ctx->r13, ctx->r11);
    // 0x8019AF38: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8019AF3C: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x8019AF40: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8019AF44: addu        $t1, $t1, $t5
    ctx->r9 = ADD32(ctx->r9, ctx->r13);
    // 0x8019AF48: lw          $t1, 0xF98($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XF98);
    // 0x8019AF4C: addiu       $t8, $t8, 0x3D00
    ctx->r24 = ADD32(ctx->r24, 0X3D00);
    // 0x8019AF50: lw          $a2, 0x0($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X0);
    // 0x8019AF54: sll         $t9, $t1, 3
    ctx->r25 = S32(ctx->r9 << 3);
    // 0x8019AF58: subu        $t9, $t9, $t1
    ctx->r25 = SUB32(ctx->r25, ctx->r9);
    // 0x8019AF5C: lw          $a3, 0x4($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X4);
    // 0x8019AF60: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8019AF64: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x8019AF68: addu        $a1, $a1, $t9
    ctx->r5 = ADD32(ctx->r5, ctx->r25);
    // 0x8019AF6C: lhu         $a1, -0x2312($a1)
    ctx->r5 = MEM_HU(ctx->r5, -0X2312);
    // 0x8019AF70: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8019AF74: addiu       $a2, $a2, 0xA0
    ctx->r6 = ADD32(ctx->r6, 0XA0);
    // 0x8019AF78: jal         0x80176F04
    // 0x8019AF7C: addiu       $a3, $a3, 0x78
    ctx->r7 = ADD32(ctx->r7, 0X78);
    func_80176F04_1501A0(rdram, ctx);
        goto after_6;
    // 0x8019AF7C: addiu       $a3, $a3, 0x78
    ctx->r7 = ADD32(ctx->r7, 0X78);
    after_6:
    // 0x8019AF80: b           L_8019AF9C
    // 0x8019AF84: nop

        goto L_8019AF9C;
    // 0x8019AF84: nop

L_8019AF88:
    // 0x8019AF88: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8019AF8C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8019AF90: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8019AF94: jal         0x80176F04
    // 0x8019AF98: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80176F04_1501A0(rdram, ctx);
        goto after_7;
    // 0x8019AF98: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_7:
L_8019AF9C:
    // 0x8019AF9C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8019AFA0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8019AFA4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8019AFA8: jr          $ra
    // 0x8019AFAC: nop

    return;
    // 0x8019AFAC: nop

;}
RECOMP_FUNC void func_8019AFB0_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019AFB0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8019AFB4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8019AFB8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8019AFBC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8019AFC0: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8019AFC4: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8019AFC8: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8019AFCC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8019AFD0: addiu       $t6, $t6, -0x2BA8
    ctx->r14 = ADD32(ctx->r14, -0X2BA8);
    // 0x8019AFD4: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8019AFD8: beq         $t7, $zero, L_8019B308
    if (ctx->r15 == 0) {
        // 0x8019AFDC: nop
    
            goto L_8019B308;
    }
    // 0x8019AFDC: nop

    // 0x8019AFE0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8019AFE4: addiu       $t8, $t8, -0x2E18
    ctx->r24 = ADD32(ctx->r24, -0X2E18);
    // 0x8019AFE8: lw          $t9, 0x68($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X68);
    // 0x8019AFEC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8019AFF0: bne         $t9, $at, L_8019AFFC
    if (ctx->r25 != ctx->r1) {
        // 0x8019AFF4: nop
    
            goto L_8019AFFC;
    }
    // 0x8019AFF4: nop

    // 0x8019AFF8: sw          $zero, 0x68($t8)
    MEM_W(0X68, ctx->r24) = 0;
L_8019AFFC:
    // 0x8019AFFC: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8019B000: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8019B004: bne         $t0, $at, L_8019B01C
    if (ctx->r8 != ctx->r1) {
        // 0x8019B008: nop
    
            goto L_8019B01C;
    }
    // 0x8019B008: nop

    // 0x8019B00C: jal         0x800C8544
    // 0x8019B010: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    func_800C8544(rdram, ctx);
        goto after_0;
    // 0x8019B010: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_0:
    // 0x8019B014: b           L_8019B064
    // 0x8019B018: nop

        goto L_8019B064;
    // 0x8019B018: nop

L_8019B01C:
    // 0x8019B01C: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x8019B020: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8019B024: addiu       $at, $zero, 0x6F
    ctx->r1 = ADD32(0, 0X6F);
    // 0x8019B028: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8019B02C: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x8019B030: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8019B034: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8019B038: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x8019B03C: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8019B040: lw          $t3, 0xF98($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XF98);
    // 0x8019B044: bne         $t3, $at, L_8019B05C
    if (ctx->r11 != ctx->r1) {
        // 0x8019B048: nop
    
            goto L_8019B05C;
    }
    // 0x8019B048: nop

    // 0x8019B04C: jal         0x800C8544
    // 0x8019B050: addiu       $a0, $zero, 0x63
    ctx->r4 = ADD32(0, 0X63);
    func_800C8544(rdram, ctx);
        goto after_1;
    // 0x8019B050: addiu       $a0, $zero, 0x63
    ctx->r4 = ADD32(0, 0X63);
    after_1:
    // 0x8019B054: b           L_8019B064
    // 0x8019B058: nop

        goto L_8019B064;
    // 0x8019B058: nop

L_8019B05C:
    // 0x8019B05C: jal         0x800C8544
    // 0x8019B060: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    func_800C8544(rdram, ctx);
        goto after_2;
    // 0x8019B060: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_2:
L_8019B064:
    // 0x8019B064: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8019B068: jal         0x8019BDA4
    // 0x8019B06C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_8019BDA4_1501A0(rdram, ctx);
        goto after_3;
    // 0x8019B06C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x8019B070: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8019B074: jal         0x8019BDA4
    // 0x8019B078: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_8019BDA4_1501A0(rdram, ctx);
        goto after_4;
    // 0x8019B078: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_4:
    // 0x8019B07C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8019B080: addiu       $t4, $t4, -0x2BA8
    ctx->r12 = ADD32(ctx->r12, -0X2BA8);
    // 0x8019B084: lw          $t5, 0xC($t4)
    ctx->r13 = MEM_W(ctx->r12, 0XC);
    // 0x8019B088: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8019B08C: sltu        $at, $t6, $t5
    ctx->r1 = ctx->r14 < ctx->r13 ? 1 : 0;
    // 0x8019B090: beq         $at, $zero, L_8019B0A4
    if (ctx->r1 == 0) {
        // 0x8019B094: nop
    
            goto L_8019B0A4;
    }
    // 0x8019B094: nop

    // 0x8019B098: subu        $t7, $t5, $t6
    ctx->r15 = SUB32(ctx->r13, ctx->r14);
    // 0x8019B09C: b           L_8019B270
    // 0x8019B0A0: sw          $t7, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r15;
        goto L_8019B270;
    // 0x8019B0A0: sw          $t7, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r15;
L_8019B0A4:
    // 0x8019B0A4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8019B0A8: addiu       $t9, $t9, -0x2E18
    ctx->r25 = ADD32(ctx->r25, -0X2E18);
    // 0x8019B0AC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8019B0B0: addiu       $t8, $t8, -0x2E18
    ctx->r24 = ADD32(ctx->r24, -0X2E18);
    // 0x8019B0B4: sw          $zero, 0x78($t9)
    MEM_W(0X78, ctx->r25) = 0;
    // 0x8019B0B8: lw          $s0, 0x78($t8)
    ctx->r16 = MEM_W(ctx->r24, 0X78);
    // 0x8019B0BC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8019B0C0: addiu       $t0, $t0, -0x2BA8
    ctx->r8 = ADD32(ctx->r8, -0X2BA8);
    // 0x8019B0C4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8019B0C8: sw          $s0, 0x70($t8)
    MEM_W(0X70, ctx->r24) = ctx->r16;
    // 0x8019B0CC: addiu       $t1, $t1, 0x3988
    ctx->r9 = ADD32(ctx->r9, 0X3988);
    // 0x8019B0D0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8019B0D4: sw          $s0, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r16;
    // 0x8019B0D8: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x8019B0DC: addiu       $t2, $t2, -0x2BA8
    ctx->r10 = ADD32(ctx->r10, -0X2BA8);
    // 0x8019B0E0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8019B0E4: addiu       $t3, $t3, -0x2BA8
    ctx->r11 = ADD32(ctx->r11, -0X2BA8);
    // 0x8019B0E8: sw          $zero, 0x1C($t2)
    MEM_W(0X1C, ctx->r10) = 0;
    // 0x8019B0EC: lw          $t5, 0x1C($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X1C);
    // 0x8019B0F0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8019B0F4: addiu       $t6, $t6, 0x39A0
    ctx->r14 = ADD32(ctx->r14, 0X39A0);
    // 0x8019B0F8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8019B0FC: sw          $t5, 0x14($t3)
    MEM_W(0X14, ctx->r11) = ctx->r13;
    // 0x8019B100: sw          $zero, 0x50($t6)
    MEM_W(0X50, ctx->r14) = 0;
    // 0x8019B104: addiu       $t7, $t7, 0x39A0
    ctx->r15 = ADD32(ctx->r15, 0X39A0);
    // 0x8019B108: lw          $t4, 0x50($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X50);
    // 0x8019B10C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8019B110: addiu       $t8, $t8, 0x39A0
    ctx->r24 = ADD32(ctx->r24, 0X39A0);
    // 0x8019B114: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8019B118: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8019B11C: sw          $t4, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->r12;
    // 0x8019B120: sw          $t9, 0x48($t8)
    MEM_W(0X48, ctx->r24) = ctx->r25;
    // 0x8019B124: addiu       $t0, $t0, 0x39A0
    ctx->r8 = ADD32(ctx->r8, 0X39A0);
    // 0x8019B128: lw          $t1, 0x48($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X48);
    // 0x8019B12C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8019B130: addiu       $t2, $t2, -0x2E18
    ctx->r10 = ADD32(ctx->r10, -0X2E18);
    // 0x8019B134: sw          $t1, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r9;
    // 0x8019B138: sw          $zero, 0x48($t2)
    MEM_W(0X48, ctx->r10) = 0;
    // 0x8019B13C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8019B140: lw          $t5, -0x2E3C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2E3C);
    // 0x8019B144: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8019B148: beq         $t5, $zero, L_8019B270
    if (ctx->r13 == 0) {
        // 0x8019B14C: nop
    
            goto L_8019B270;
    }
    // 0x8019B14C: nop

L_8019B150:
    // 0x8019B150: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
L_8019B154:
    // 0x8019B154: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x8019B158: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8019B15C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8019B160: sll         $t6, $t3, 3
    ctx->r14 = S32(ctx->r11 << 3);
    // 0x8019B164: sll         $t7, $t4, 3
    ctx->r15 = S32(ctx->r12 << 3);
    // 0x8019B168: subu        $t6, $t6, $t3
    ctx->r14 = SUB32(ctx->r14, ctx->r11);
    // 0x8019B16C: subu        $t7, $t7, $t4
    ctx->r15 = SUB32(ctx->r15, ctx->r12);
    // 0x8019B170: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8019B174: sll         $t6, $t6, 5
    ctx->r14 = S32(ctx->r14 << 5);
    // 0x8019B178: addu        $t9, $t6, $t7
    ctx->r25 = ADD32(ctx->r14, ctx->r15);
    // 0x8019B17C: addiu       $t8, $t8, 0x3518
    ctx->r24 = ADD32(ctx->r24, 0X3518);
    // 0x8019B180: addu        $t1, $t9, $t8
    ctx->r9 = ADD32(ctx->r25, ctx->r24);
    // 0x8019B184: lw          $t0, 0x0($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X0);
    // 0x8019B188: beq         $t0, $zero, L_8019B23C
    if (ctx->r8 == 0) {
        // 0x8019B18C: nop
    
            goto L_8019B23C;
    }
    // 0x8019B18C: nop

    // 0x8019B190: addu        $t2, $t6, $t7
    ctx->r10 = ADD32(ctx->r14, ctx->r15);
    // 0x8019B194: addu        $t5, $t2, $t8
    ctx->r13 = ADD32(ctx->r10, ctx->r24);
    // 0x8019B198: sw          $zero, 0x0($t5)
    MEM_W(0X0, ctx->r13) = 0;
    // 0x8019B19C: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8019B1A0: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x8019B1A4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8019B1A8: sll         $t1, $t9, 3
    ctx->r9 = S32(ctx->r25 << 3);
    // 0x8019B1AC: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x8019B1B0: subu        $t1, $t1, $t9
    ctx->r9 = SUB32(ctx->r9, ctx->r25);
    // 0x8019B1B4: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x8019B1B8: sll         $t4, $t4, 5
    ctx->r12 = S32(ctx->r12 << 5);
    // 0x8019B1BC: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x8019B1C0: addu        $t0, $t4, $t1
    ctx->r8 = ADD32(ctx->r12, ctx->r9);
    // 0x8019B1C4: addiu       $t6, $t6, 0x3518
    ctx->r14 = ADD32(ctx->r14, 0X3518);
    // 0x8019B1C8: addu        $t7, $t0, $t6
    ctx->r15 = ADD32(ctx->r8, ctx->r14);
    // 0x8019B1CC: lw          $t2, 0x4($t7)
    ctx->r10 = MEM_W(ctx->r15, 0X4);
    // 0x8019B1D0: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x8019B1D4: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8019B1D8: sll         $t8, $t2, 2
    ctx->r24 = S32(ctx->r10 << 2);
    // 0x8019B1DC: addu        $t8, $t8, $t2
    ctx->r24 = ADD32(ctx->r24, ctx->r10);
    // 0x8019B1E0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8019B1E4: subu        $t8, $t8, $t2
    ctx->r24 = SUB32(ctx->r24, ctx->r10);
    // 0x8019B1E8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8019B1EC: addu        $t8, $t8, $t2
    ctx->r24 = ADD32(ctx->r24, ctx->r10);
    // 0x8019B1F0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8019B1F4: addiu       $t5, $t5, -0x2A28
    ctx->r13 = ADD32(ctx->r13, -0X2A28);
    // 0x8019B1F8: sllv        $t2, $t7, $t3
    ctx->r10 = S32(ctx->r15 << (ctx->r11 & 31));
    // 0x8019B1FC: addu        $t9, $t8, $t5
    ctx->r25 = ADD32(ctx->r24, ctx->r13);
    // 0x8019B200: addu        $t7, $t4, $t1
    ctx->r15 = ADD32(ctx->r12, ctx->r9);
    // 0x8019B204: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x8019B208: addu        $t3, $t7, $t6
    ctx->r11 = ADD32(ctx->r15, ctx->r14);
    // 0x8019B20C: xori        $t8, $t2, 0xFFFF
    ctx->r24 = ctx->r10 ^ 0XFFFF;
    // 0x8019B210: lw          $t2, 0x4($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X4);
    // 0x8019B214: and         $t9, $t0, $t8
    ctx->r25 = ctx->r8 & ctx->r24;
    // 0x8019B218: sll         $t0, $t2, 2
    ctx->r8 = S32(ctx->r10 << 2);
    // 0x8019B21C: addu        $t0, $t0, $t2
    ctx->r8 = ADD32(ctx->r8, ctx->r10);
    // 0x8019B220: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8019B224: subu        $t0, $t0, $t2
    ctx->r8 = SUB32(ctx->r8, ctx->r10);
    // 0x8019B228: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8019B22C: addu        $t0, $t0, $t2
    ctx->r8 = ADD32(ctx->r8, ctx->r10);
    // 0x8019B230: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8019B234: addu        $t8, $t0, $t5
    ctx->r24 = ADD32(ctx->r8, ctx->r13);
    // 0x8019B238: sh          $t9, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r25;
L_8019B23C:
    // 0x8019B23C: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8019B240: addiu       $t1, $t4, 0x1
    ctx->r9 = ADD32(ctx->r12, 0X1);
    // 0x8019B244: sltiu       $at, $t1, 0x4
    ctx->r1 = ctx->r9 < 0X4 ? 1 : 0;
    // 0x8019B248: bne         $at, $zero, L_8019B154
    if (ctx->r1 != 0) {
        // 0x8019B24C: sw          $t1, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r9;
            goto L_8019B154;
    }
    // 0x8019B24C: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x8019B250: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8019B254: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8019B258: lw          $t3, -0x2E3C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2E3C);
    // 0x8019B25C: addiu       $t6, $t7, 0x1
    ctx->r14 = ADD32(ctx->r15, 0X1);
    // 0x8019B260: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x8019B264: sltu        $at, $t6, $t3
    ctx->r1 = ctx->r14 < ctx->r11 ? 1 : 0;
    // 0x8019B268: bne         $at, $zero, L_8019B150
    if (ctx->r1 != 0) {
        // 0x8019B26C: nop
    
            goto L_8019B150;
    }
    // 0x8019B26C: nop

L_8019B270:
    // 0x8019B270: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x8019B274: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8019B278: beq         $t2, $at, L_8019B2F4
    if (ctx->r10 == ctx->r1) {
        // 0x8019B27C: nop
    
            goto L_8019B2F4;
    }
    // 0x8019B27C: nop

    // 0x8019B280: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8019B284: lwc1        $f14, 0x3C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8019B288: jal         0x8019C46C
    // 0x8019B28C: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    func_8019C46C_1501A0(rdram, ctx);
        goto after_5;
    // 0x8019B28C: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    after_5:
    // 0x8019B290: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8019B294: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8019B298: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8019B29C: sll         $t5, $t0, 2
    ctx->r13 = S32(ctx->r8 << 2);
    // 0x8019B2A0: subu        $t5, $t5, $t0
    ctx->r13 = SUB32(ctx->r13, ctx->r8);
    // 0x8019B2A4: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8019B2A8: addu        $t5, $t5, $t0
    ctx->r13 = ADD32(ctx->r13, ctx->r8);
    // 0x8019B2AC: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8019B2B0: addu        $t9, $t9, $t5
    ctx->r25 = ADD32(ctx->r25, ctx->r13);
    // 0x8019B2B4: lw          $t9, 0xF98($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XF98);
    // 0x8019B2B8: addiu       $t4, $t4, 0x3D00
    ctx->r12 = ADD32(ctx->r12, 0X3D00);
    // 0x8019B2BC: lw          $a2, 0x0($t4)
    ctx->r6 = MEM_W(ctx->r12, 0X0);
    // 0x8019B2C0: sll         $t8, $t9, 3
    ctx->r24 = S32(ctx->r25 << 3);
    // 0x8019B2C4: subu        $t8, $t8, $t9
    ctx->r24 = SUB32(ctx->r24, ctx->r25);
    // 0x8019B2C8: lw          $a3, 0x4($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X4);
    // 0x8019B2CC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8019B2D0: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x8019B2D4: addu        $a1, $a1, $t8
    ctx->r5 = ADD32(ctx->r5, ctx->r24);
    // 0x8019B2D8: lhu         $a1, -0x2312($a1)
    ctx->r5 = MEM_HU(ctx->r5, -0X2312);
    // 0x8019B2DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8019B2E0: addiu       $a2, $a2, 0xA0
    ctx->r6 = ADD32(ctx->r6, 0XA0);
    // 0x8019B2E4: jal         0x80176F04
    // 0x8019B2E8: addiu       $a3, $a3, 0x78
    ctx->r7 = ADD32(ctx->r7, 0X78);
    func_80176F04_1501A0(rdram, ctx);
        goto after_6;
    // 0x8019B2E8: addiu       $a3, $a3, 0x78
    ctx->r7 = ADD32(ctx->r7, 0X78);
    after_6:
    // 0x8019B2EC: b           L_8019B308
    // 0x8019B2F0: nop

        goto L_8019B308;
    // 0x8019B2F0: nop

L_8019B2F4:
    // 0x8019B2F4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8019B2F8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8019B2FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8019B300: jal         0x80176F04
    // 0x8019B304: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80176F04_1501A0(rdram, ctx);
        goto after_7;
    // 0x8019B304: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_7:
L_8019B308:
    // 0x8019B308: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8019B30C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8019B310: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8019B314: jr          $ra
    // 0x8019B318: nop

    return;
    // 0x8019B318: nop

;}
RECOMP_FUNC void func_8019B31C_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019B31C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8019B320: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8019B324: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8019B328: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8019B32C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8019B330: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8019B334: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8019B338: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8019B33C: addiu       $t6, $t6, -0x2BA8
    ctx->r14 = ADD32(ctx->r14, -0X2BA8);
    // 0x8019B340: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x8019B344: beq         $t7, $zero, L_8019B674
    if (ctx->r15 == 0) {
        // 0x8019B348: nop
    
            goto L_8019B674;
    }
    // 0x8019B348: nop

    // 0x8019B34C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8019B350: addiu       $t8, $t8, -0x2E18
    ctx->r24 = ADD32(ctx->r24, -0X2E18);
    // 0x8019B354: lw          $t9, 0x6C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X6C);
    // 0x8019B358: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8019B35C: bne         $t9, $at, L_8019B368
    if (ctx->r25 != ctx->r1) {
        // 0x8019B360: nop
    
            goto L_8019B368;
    }
    // 0x8019B360: nop

    // 0x8019B364: sw          $zero, 0x6C($t8)
    MEM_W(0X6C, ctx->r24) = 0;
L_8019B368:
    // 0x8019B368: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8019B36C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8019B370: bne         $t0, $at, L_8019B388
    if (ctx->r8 != ctx->r1) {
        // 0x8019B374: nop
    
            goto L_8019B388;
    }
    // 0x8019B374: nop

    // 0x8019B378: jal         0x800C8544
    // 0x8019B37C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    func_800C8544(rdram, ctx);
        goto after_0;
    // 0x8019B37C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_0:
    // 0x8019B380: b           L_8019B3D0
    // 0x8019B384: nop

        goto L_8019B3D0;
    // 0x8019B384: nop

L_8019B388:
    // 0x8019B388: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x8019B38C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8019B390: addiu       $at, $zero, 0x6F
    ctx->r1 = ADD32(0, 0X6F);
    // 0x8019B394: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8019B398: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x8019B39C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8019B3A0: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8019B3A4: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x8019B3A8: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8019B3AC: lw          $t3, 0xF98($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XF98);
    // 0x8019B3B0: bne         $t3, $at, L_8019B3C8
    if (ctx->r11 != ctx->r1) {
        // 0x8019B3B4: nop
    
            goto L_8019B3C8;
    }
    // 0x8019B3B4: nop

    // 0x8019B3B8: jal         0x800C8544
    // 0x8019B3BC: addiu       $a0, $zero, 0x63
    ctx->r4 = ADD32(0, 0X63);
    func_800C8544(rdram, ctx);
        goto after_1;
    // 0x8019B3BC: addiu       $a0, $zero, 0x63
    ctx->r4 = ADD32(0, 0X63);
    after_1:
    // 0x8019B3C0: b           L_8019B3D0
    // 0x8019B3C4: nop

        goto L_8019B3D0;
    // 0x8019B3C4: nop

L_8019B3C8:
    // 0x8019B3C8: jal         0x800C8544
    // 0x8019B3CC: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    func_800C8544(rdram, ctx);
        goto after_2;
    // 0x8019B3CC: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_2:
L_8019B3D0:
    // 0x8019B3D0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8019B3D4: jal         0x8019BDA4
    // 0x8019B3D8: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_8019BDA4_1501A0(rdram, ctx);
        goto after_3;
    // 0x8019B3D8: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x8019B3DC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8019B3E0: jal         0x8019BDA4
    // 0x8019B3E4: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_8019BDA4_1501A0(rdram, ctx);
        goto after_4;
    // 0x8019B3E4: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_4:
    // 0x8019B3E8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8019B3EC: addiu       $t4, $t4, -0x2BA8
    ctx->r12 = ADD32(ctx->r12, -0X2BA8);
    // 0x8019B3F0: lw          $t5, 0x10($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X10);
    // 0x8019B3F4: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8019B3F8: sltu        $at, $t6, $t5
    ctx->r1 = ctx->r14 < ctx->r13 ? 1 : 0;
    // 0x8019B3FC: beq         $at, $zero, L_8019B410
    if (ctx->r1 == 0) {
        // 0x8019B400: nop
    
            goto L_8019B410;
    }
    // 0x8019B400: nop

    // 0x8019B404: subu        $t7, $t5, $t6
    ctx->r15 = SUB32(ctx->r13, ctx->r14);
    // 0x8019B408: b           L_8019B5DC
    // 0x8019B40C: sw          $t7, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->r15;
        goto L_8019B5DC;
    // 0x8019B40C: sw          $t7, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->r15;
L_8019B410:
    // 0x8019B410: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8019B414: addiu       $t9, $t9, -0x2E18
    ctx->r25 = ADD32(ctx->r25, -0X2E18);
    // 0x8019B418: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8019B41C: addiu       $t8, $t8, -0x2E18
    ctx->r24 = ADD32(ctx->r24, -0X2E18);
    // 0x8019B420: sw          $zero, 0x78($t9)
    MEM_W(0X78, ctx->r25) = 0;
    // 0x8019B424: lw          $s0, 0x78($t8)
    ctx->r16 = MEM_W(ctx->r24, 0X78);
    // 0x8019B428: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8019B42C: addiu       $t0, $t0, -0x2BA8
    ctx->r8 = ADD32(ctx->r8, -0X2BA8);
    // 0x8019B430: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8019B434: sw          $s0, 0x74($t8)
    MEM_W(0X74, ctx->r24) = ctx->r16;
    // 0x8019B438: addiu       $t1, $t1, 0x3988
    ctx->r9 = ADD32(ctx->r9, 0X3988);
    // 0x8019B43C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8019B440: sw          $s0, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r16;
    // 0x8019B444: sw          $zero, 0xC($t1)
    MEM_W(0XC, ctx->r9) = 0;
    // 0x8019B448: addiu       $t2, $t2, -0x2BA8
    ctx->r10 = ADD32(ctx->r10, -0X2BA8);
    // 0x8019B44C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8019B450: addiu       $t3, $t3, -0x2BA8
    ctx->r11 = ADD32(ctx->r11, -0X2BA8);
    // 0x8019B454: sw          $zero, 0x20($t2)
    MEM_W(0X20, ctx->r10) = 0;
    // 0x8019B458: lw          $t5, 0x20($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X20);
    // 0x8019B45C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8019B460: addiu       $t6, $t6, 0x39A0
    ctx->r14 = ADD32(ctx->r14, 0X39A0);
    // 0x8019B464: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8019B468: sw          $t5, 0x18($t3)
    MEM_W(0X18, ctx->r11) = ctx->r13;
    // 0x8019B46C: sw          $zero, 0x70($t6)
    MEM_W(0X70, ctx->r14) = 0;
    // 0x8019B470: addiu       $t7, $t7, 0x39A0
    ctx->r15 = ADD32(ctx->r15, 0X39A0);
    // 0x8019B474: lw          $t4, 0x70($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X70);
    // 0x8019B478: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8019B47C: addiu       $t8, $t8, 0x39A0
    ctx->r24 = ADD32(ctx->r24, 0X39A0);
    // 0x8019B480: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8019B484: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8019B488: sw          $t4, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->r12;
    // 0x8019B48C: sw          $t9, 0x68($t8)
    MEM_W(0X68, ctx->r24) = ctx->r25;
    // 0x8019B490: addiu       $t0, $t0, 0x39A0
    ctx->r8 = ADD32(ctx->r8, 0X39A0);
    // 0x8019B494: lw          $t1, 0x68($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X68);
    // 0x8019B498: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8019B49C: addiu       $t2, $t2, -0x2E18
    ctx->r10 = ADD32(ctx->r10, -0X2E18);
    // 0x8019B4A0: sw          $t1, 0x28($t0)
    MEM_W(0X28, ctx->r8) = ctx->r9;
    // 0x8019B4A4: sw          $zero, 0x4C($t2)
    MEM_W(0X4C, ctx->r10) = 0;
    // 0x8019B4A8: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8019B4AC: lw          $t5, -0x2E3C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2E3C);
    // 0x8019B4B0: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8019B4B4: beq         $t5, $zero, L_8019B5DC
    if (ctx->r13 == 0) {
        // 0x8019B4B8: nop
    
            goto L_8019B5DC;
    }
    // 0x8019B4B8: nop

L_8019B4BC:
    // 0x8019B4BC: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
L_8019B4C0:
    // 0x8019B4C0: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x8019B4C4: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8019B4C8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8019B4CC: sll         $t6, $t3, 3
    ctx->r14 = S32(ctx->r11 << 3);
    // 0x8019B4D0: sll         $t7, $t4, 3
    ctx->r15 = S32(ctx->r12 << 3);
    // 0x8019B4D4: subu        $t6, $t6, $t3
    ctx->r14 = SUB32(ctx->r14, ctx->r11);
    // 0x8019B4D8: subu        $t7, $t7, $t4
    ctx->r15 = SUB32(ctx->r15, ctx->r12);
    // 0x8019B4DC: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8019B4E0: sll         $t6, $t6, 5
    ctx->r14 = S32(ctx->r14 << 5);
    // 0x8019B4E4: addu        $t9, $t6, $t7
    ctx->r25 = ADD32(ctx->r14, ctx->r15);
    // 0x8019B4E8: addiu       $t8, $t8, 0x3518
    ctx->r24 = ADD32(ctx->r24, 0X3518);
    // 0x8019B4EC: addu        $t1, $t9, $t8
    ctx->r9 = ADD32(ctx->r25, ctx->r24);
    // 0x8019B4F0: lw          $t0, 0x0($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X0);
    // 0x8019B4F4: beq         $t0, $zero, L_8019B5A8
    if (ctx->r8 == 0) {
        // 0x8019B4F8: nop
    
            goto L_8019B5A8;
    }
    // 0x8019B4F8: nop

    // 0x8019B4FC: addu        $t2, $t6, $t7
    ctx->r10 = ADD32(ctx->r14, ctx->r15);
    // 0x8019B500: addu        $t5, $t2, $t8
    ctx->r13 = ADD32(ctx->r10, ctx->r24);
    // 0x8019B504: sw          $zero, 0x0($t5)
    MEM_W(0X0, ctx->r13) = 0;
    // 0x8019B508: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8019B50C: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x8019B510: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8019B514: sll         $t1, $t9, 3
    ctx->r9 = S32(ctx->r25 << 3);
    // 0x8019B518: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x8019B51C: subu        $t1, $t1, $t9
    ctx->r9 = SUB32(ctx->r9, ctx->r25);
    // 0x8019B520: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x8019B524: sll         $t4, $t4, 5
    ctx->r12 = S32(ctx->r12 << 5);
    // 0x8019B528: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x8019B52C: addu        $t0, $t4, $t1
    ctx->r8 = ADD32(ctx->r12, ctx->r9);
    // 0x8019B530: addiu       $t6, $t6, 0x3518
    ctx->r14 = ADD32(ctx->r14, 0X3518);
    // 0x8019B534: addu        $t7, $t0, $t6
    ctx->r15 = ADD32(ctx->r8, ctx->r14);
    // 0x8019B538: lw          $t2, 0x4($t7)
    ctx->r10 = MEM_W(ctx->r15, 0X4);
    // 0x8019B53C: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x8019B540: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8019B544: sll         $t8, $t2, 2
    ctx->r24 = S32(ctx->r10 << 2);
    // 0x8019B548: addu        $t8, $t8, $t2
    ctx->r24 = ADD32(ctx->r24, ctx->r10);
    // 0x8019B54C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8019B550: subu        $t8, $t8, $t2
    ctx->r24 = SUB32(ctx->r24, ctx->r10);
    // 0x8019B554: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8019B558: addu        $t8, $t8, $t2
    ctx->r24 = ADD32(ctx->r24, ctx->r10);
    // 0x8019B55C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8019B560: addiu       $t5, $t5, -0x2A28
    ctx->r13 = ADD32(ctx->r13, -0X2A28);
    // 0x8019B564: sllv        $t2, $t7, $t3
    ctx->r10 = S32(ctx->r15 << (ctx->r11 & 31));
    // 0x8019B568: addu        $t9, $t8, $t5
    ctx->r25 = ADD32(ctx->r24, ctx->r13);
    // 0x8019B56C: addu        $t7, $t4, $t1
    ctx->r15 = ADD32(ctx->r12, ctx->r9);
    // 0x8019B570: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x8019B574: addu        $t3, $t7, $t6
    ctx->r11 = ADD32(ctx->r15, ctx->r14);
    // 0x8019B578: xori        $t8, $t2, 0xFFFF
    ctx->r24 = ctx->r10 ^ 0XFFFF;
    // 0x8019B57C: lw          $t2, 0x4($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X4);
    // 0x8019B580: and         $t9, $t0, $t8
    ctx->r25 = ctx->r8 & ctx->r24;
    // 0x8019B584: sll         $t0, $t2, 2
    ctx->r8 = S32(ctx->r10 << 2);
    // 0x8019B588: addu        $t0, $t0, $t2
    ctx->r8 = ADD32(ctx->r8, ctx->r10);
    // 0x8019B58C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8019B590: subu        $t0, $t0, $t2
    ctx->r8 = SUB32(ctx->r8, ctx->r10);
    // 0x8019B594: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8019B598: addu        $t0, $t0, $t2
    ctx->r8 = ADD32(ctx->r8, ctx->r10);
    // 0x8019B59C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8019B5A0: addu        $t8, $t0, $t5
    ctx->r24 = ADD32(ctx->r8, ctx->r13);
    // 0x8019B5A4: sh          $t9, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r25;
L_8019B5A8:
    // 0x8019B5A8: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8019B5AC: addiu       $t1, $t4, 0x1
    ctx->r9 = ADD32(ctx->r12, 0X1);
    // 0x8019B5B0: sltiu       $at, $t1, 0x4
    ctx->r1 = ctx->r9 < 0X4 ? 1 : 0;
    // 0x8019B5B4: bne         $at, $zero, L_8019B4C0
    if (ctx->r1 != 0) {
        // 0x8019B5B8: sw          $t1, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r9;
            goto L_8019B4C0;
    }
    // 0x8019B5B8: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x8019B5BC: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8019B5C0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8019B5C4: lw          $t3, -0x2E3C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2E3C);
    // 0x8019B5C8: addiu       $t6, $t7, 0x1
    ctx->r14 = ADD32(ctx->r15, 0X1);
    // 0x8019B5CC: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x8019B5D0: sltu        $at, $t6, $t3
    ctx->r1 = ctx->r14 < ctx->r11 ? 1 : 0;
    // 0x8019B5D4: bne         $at, $zero, L_8019B4BC
    if (ctx->r1 != 0) {
        // 0x8019B5D8: nop
    
            goto L_8019B4BC;
    }
    // 0x8019B5D8: nop

L_8019B5DC:
    // 0x8019B5DC: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x8019B5E0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8019B5E4: beq         $t2, $at, L_8019B660
    if (ctx->r10 == ctx->r1) {
        // 0x8019B5E8: nop
    
            goto L_8019B660;
    }
    // 0x8019B5E8: nop

    // 0x8019B5EC: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8019B5F0: lwc1        $f14, 0x3C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8019B5F4: jal         0x8019C46C
    // 0x8019B5F8: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    func_8019C46C_1501A0(rdram, ctx);
        goto after_5;
    // 0x8019B5F8: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    after_5:
    // 0x8019B5FC: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8019B600: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8019B604: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8019B608: sll         $t5, $t0, 2
    ctx->r13 = S32(ctx->r8 << 2);
    // 0x8019B60C: subu        $t5, $t5, $t0
    ctx->r13 = SUB32(ctx->r13, ctx->r8);
    // 0x8019B610: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8019B614: addu        $t5, $t5, $t0
    ctx->r13 = ADD32(ctx->r13, ctx->r8);
    // 0x8019B618: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8019B61C: addu        $t9, $t9, $t5
    ctx->r25 = ADD32(ctx->r25, ctx->r13);
    // 0x8019B620: lw          $t9, 0xF98($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XF98);
    // 0x8019B624: addiu       $t4, $t4, 0x3D00
    ctx->r12 = ADD32(ctx->r12, 0X3D00);
    // 0x8019B628: lw          $a2, 0x0($t4)
    ctx->r6 = MEM_W(ctx->r12, 0X0);
    // 0x8019B62C: sll         $t8, $t9, 3
    ctx->r24 = S32(ctx->r25 << 3);
    // 0x8019B630: subu        $t8, $t8, $t9
    ctx->r24 = SUB32(ctx->r24, ctx->r25);
    // 0x8019B634: lw          $a3, 0x4($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X4);
    // 0x8019B638: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8019B63C: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x8019B640: addu        $a1, $a1, $t8
    ctx->r5 = ADD32(ctx->r5, ctx->r24);
    // 0x8019B644: lhu         $a1, -0x2312($a1)
    ctx->r5 = MEM_HU(ctx->r5, -0X2312);
    // 0x8019B648: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8019B64C: addiu       $a2, $a2, 0xA0
    ctx->r6 = ADD32(ctx->r6, 0XA0);
    // 0x8019B650: jal         0x80176F04
    // 0x8019B654: addiu       $a3, $a3, 0x78
    ctx->r7 = ADD32(ctx->r7, 0X78);
    func_80176F04_1501A0(rdram, ctx);
        goto after_6;
    // 0x8019B654: addiu       $a3, $a3, 0x78
    ctx->r7 = ADD32(ctx->r7, 0X78);
    after_6:
    // 0x8019B658: b           L_8019B674
    // 0x8019B65C: nop

        goto L_8019B674;
    // 0x8019B65C: nop

L_8019B660:
    // 0x8019B660: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8019B664: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8019B668: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8019B66C: jal         0x80176F04
    // 0x8019B670: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80176F04_1501A0(rdram, ctx);
        goto after_7;
    // 0x8019B670: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_7:
L_8019B674:
    // 0x8019B674: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8019B678: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8019B67C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8019B680: jr          $ra
    // 0x8019B684: nop

    return;
    // 0x8019B684: nop

;}
RECOMP_FUNC void func_8019B688_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019B688: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8019B68C: lw          $t6, -0x2E44($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2E44);
    // 0x8019B690: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8019B694: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8019B698: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8019B69C: sltiu       $at, $t7, 0x6
    ctx->r1 = ctx->r15 < 0X6 ? 1 : 0;
    // 0x8019B6A0: beq         $at, $zero, L_8019B6F0
    if (ctx->r1 == 0) {
        // 0x8019B6A4: sw          $a0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r4;
            goto L_8019B6F0;
    }
    // 0x8019B6A4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8019B6A8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8019B6AC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019B6B0: addu        $at, $at, $t7
    gpr jr_addend_8019B6B8 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8019B6B4: lw          $t7, 0xBCC($at)
    ctx->r15 = ADD32(ctx->r1, 0XBCC);
    // 0x8019B6B8: jr          $t7
    // 0x8019B6BC: nop

    switch (jr_addend_8019B6B8 >> 2) {
        case 0: goto L_8019B6C0; break;
        case 1: goto L_8019B6D0; break;
        case 2: goto L_8019B6E0; break;
        case 3: goto L_8019B6E0; break;
        case 4: goto L_8019B6E0; break;
        case 5: goto L_8019B6E0; break;
        default: switch_error(__func__, 0x8019B6B8, 0x801A0BCC);
    }
    // 0x8019B6BC: nop

L_8019B6C0:
    // 0x8019B6C0: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x8019B6C4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019B6C8: b           L_8019B6F0
    // 0x8019B6CC: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
        goto L_8019B6F0;
    // 0x8019B6CC: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
L_8019B6D0:
    // 0x8019B6D0: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8019B6D4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019B6D8: b           L_8019B6F0
    // 0x8019B6DC: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
        goto L_8019B6F0;
    // 0x8019B6DC: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
L_8019B6E0:
    // 0x8019B6E0: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8019B6E4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019B6E8: nop

    // 0x8019B6EC: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
L_8019B6F0:
    // 0x8019B6F0: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8019B6F4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8019B6F8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8019B6FC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8019B700: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8019B704: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8019B708: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8019B70C: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x8019B710: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8019B714: lwc1        $f10, 0xFD8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0XFD8);
    // 0x8019B718: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x8019B71C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8019B720: swc1        $f10, 0x50($t0)
    MEM_W(0X50, ctx->r8) = ctx->f10.u32l;
    // 0x8019B724: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8019B728: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8019B72C: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x8019B730: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8019B734: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x8019B738: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8019B73C: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8019B740: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x8019B744: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x8019B748: lwc1        $f16, 0xFDC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0XFDC);
    // 0x8019B74C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8019B750: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8019B754: swc1        $f16, 0x54($t3)
    MEM_W(0X54, ctx->r11) = ctx->f16.u32l;
    // 0x8019B758: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x8019B75C: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x8019B760: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8019B764: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8019B768: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x8019B76C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8019B770: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8019B774: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8019B778: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x8019B77C: lwc1        $f18, 0xFE0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0XFE0);
    // 0x8019B780: addiu       $t9, $t9, 0xF98
    ctx->r25 = ADD32(ctx->r25, 0XF98);
    // 0x8019B784: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8019B788: swc1        $f18, 0x58($t6)
    MEM_W(0X58, ctx->r14) = ctx->f18.u32l;
    // 0x8019B78C: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8019B790: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x8019B794: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8019B798: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8019B79C: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8019B7A0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8019B7A4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8019B7A8: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8019B7AC: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8019B7B0: lwc1        $f4, 0x18($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X18);
    // 0x8019B7B4: lwc1        $f6, 0x40($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X40);
    // 0x8019B7B8: lwc1        $f10, 0x30($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X30);
    // 0x8019B7BC: addiu       $t4, $t4, 0xF98
    ctx->r12 = ADD32(ctx->r12, 0XF98);
    // 0x8019B7C0: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8019B7C4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8019B7C8: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x8019B7CC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8019B7D0: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8019B7D4: addiu       $t9, $t9, 0xF98
    ctx->r25 = ADD32(ctx->r25, 0XF98);
    // 0x8019B7D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8019B7DC: swc1        $f16, 0x5C($t1)
    MEM_W(0X5C, ctx->r9) = ctx->f16.u32l;
    // 0x8019B7E0: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8019B7E4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8019B7E8: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x8019B7EC: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8019B7F0: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x8019B7F4: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8019B7F8: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8019B7FC: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x8019B800: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8019B804: lwc1        $f18, 0x1C($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X1C);
    // 0x8019B808: lwc1        $f4, 0x44($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X44);
    // 0x8019B80C: lwc1        $f8, 0x30($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X30);
    // 0x8019B810: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8019B814: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8019B818: swc1        $f10, 0x60($t6)
    MEM_W(0X60, ctx->r14) = ctx->f10.u32l;
    // 0x8019B81C: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8019B820: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8019B824: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8019B828: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8019B82C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8019B830: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8019B834: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8019B838: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8019B83C: lwc1        $f16, 0x20($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X20);
    // 0x8019B840: lwc1        $f18, 0x48($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X48);
    // 0x8019B844: lwc1        $f6, 0x30($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X30);
    // 0x8019B848: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8019B84C: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8019B850: swc1        $f8, 0x64($t1)
    MEM_W(0X64, ctx->r9) = ctx->f8.u32l;
    // 0x8019B854: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8019B858: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x8019B85C: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8019B860: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x8019B864: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8019B868: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8019B86C: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x8019B870: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x8019B874: lwc1        $f16, 0xFC8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0XFC8);
    // 0x8019B878: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x8019B87C: nop

    // 0x8019B880: bc1f        L_8019BA28
    if (!c1cs) {
        // 0x8019B884: nop
    
            goto L_8019BA28;
    }
    // 0x8019B884: nop

L_8019B888:
    // 0x8019B888: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8019B88C: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x8019B890: lwc1        $f18, 0x50($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X50);
    // 0x8019B894: lwc1        $f4, 0x5C($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X5C);
    // 0x8019B898: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8019B89C: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x8019B8A0: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8019B8A4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8019B8A8: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x8019B8AC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8019B8B0: swc1        $f6, 0x50($t4)
    MEM_W(0X50, ctx->r12) = ctx->f6.u32l;
    // 0x8019B8B4: lwc1        $f8, 0x54($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X54);
    // 0x8019B8B8: lwc1        $f10, 0x60($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X60);
    // 0x8019B8BC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8019B8C0: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x8019B8C4: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8019B8C8: addiu       $t7, $t7, -0x4198
    ctx->r15 = ADD32(ctx->r15, -0X4198);
    // 0x8019B8CC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8019B8D0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8019B8D4: swc1        $f16, 0x54($t5)
    MEM_W(0X54, ctx->r13) = ctx->f16.u32l;
    // 0x8019B8D8: lwc1        $f18, 0x58($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X58);
    // 0x8019B8DC: lwc1        $f4, 0x64($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X64);
    // 0x8019B8E0: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x8019B8E4: addiu       $t9, $t9, -0x4198
    ctx->r25 = ADD32(ctx->r25, -0X4198);
    // 0x8019B8E8: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8019B8EC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8019B8F0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8019B8F4: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x8019B8F8: swc1        $f6, 0x58($t6)
    MEM_W(0X58, ctx->r14) = ctx->f6.u32l;
    // 0x8019B8FC: lwc1        $f10, 0x50($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X50);
    // 0x8019B900: lwc1        $f8, 0x0($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X0);
    // 0x8019B904: addiu       $t1, $t1, -0x4198
    ctx->r9 = ADD32(ctx->r9, -0X4198);
    // 0x8019B908: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8019B90C: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8019B910: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x8019B914: swc1        $f16, 0x34($t8)
    MEM_W(0X34, ctx->r24) = ctx->f16.u32l;
    // 0x8019B918: lwc1        $f4, 0x54($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X54);
    // 0x8019B91C: lwc1        $f18, 0x4($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X4);
    // 0x8019B920: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8019B924: swc1        $f6, 0x38($t0)
    MEM_W(0X38, ctx->r8) = ctx->f6.u32l;
    // 0x8019B928: lwc1        $f10, 0x58($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X58);
    // 0x8019B92C: lwc1        $f8, 0x8($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X8);
    // 0x8019B930: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8019B934: swc1        $f16, 0x3C($t2)
    MEM_W(0X3C, ctx->r10) = ctx->f16.u32l;
    // 0x8019B938: lwc1        $f18, 0x34($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X34);
    // 0x8019B93C: lwc1        $f6, 0x38($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X38);
    // 0x8019B940: lwc1        $f16, 0x3C($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X3C);
    // 0x8019B944: mul.s       $f4, $f18, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x8019B948: nop

    // 0x8019B94C: mul.s       $f8, $f6, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x8019B950: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8019B954: mul.s       $f18, $f16, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8019B958: jal         0x800D68E0
    // 0x8019B95C: add.s       $f12, $f18, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x8019B95C: add.s       $f12, $f18, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f10.fl;
    after_0:
    // 0x8019B960: lwc1        $f6, 0x18($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8019B964: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x8019B968: nop

    // 0x8019B96C: bc1f        L_8019B9E0
    if (!c1cs) {
        // 0x8019B970: nop
    
            goto L_8019B9E0;
    }
    // 0x8019B970: nop

    // 0x8019B974: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8019B978: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x8019B97C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8019B980: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019B984: lwc1        $f4, 0x5C($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X5C);
    // 0x8019B988: lwc1        $f18, 0x50($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X50);
    // 0x8019B98C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8019B990: mul.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8019B994: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x8019B998: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019B99C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8019B9A0: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x8019B9A4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8019B9A8: sub.s       $f10, $f18, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x8019B9AC: swc1        $f10, 0x50($t4)
    MEM_W(0X50, ctx->r12) = ctx->f10.u32l;
    // 0x8019B9B0: lwc1        $f6, 0x60($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X60);
    // 0x8019B9B4: lwc1        $f18, 0x54($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X54);
    // 0x8019B9B8: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x8019B9BC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019B9C0: sub.s       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x8019B9C4: swc1        $f16, 0x54($t5)
    MEM_W(0X54, ctx->r13) = ctx->f16.u32l;
    // 0x8019B9C8: lwc1        $f10, 0x64($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X64);
    // 0x8019B9CC: lwc1        $f18, 0x58($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X58);
    // 0x8019B9D0: mul.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x8019B9D4: sub.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8019B9D8: b           L_8019BA2C
    // 0x8019B9DC: swc1        $f8, 0x58($t6)
    MEM_W(0X58, ctx->r14) = ctx->f8.u32l;
        goto L_8019BA2C;
    // 0x8019B9DC: swc1        $f8, 0x58($t6)
    MEM_W(0X58, ctx->r14) = ctx->f8.u32l;
L_8019B9E0:
    // 0x8019B9E0: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8019B9E4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8019B9E8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019B9EC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8019B9F0: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8019B9F4: lwc1        $f16, 0x1C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8019B9F8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8019B9FC: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8019BA00: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8019BA04: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8019BA08: add.s       $f6, $f16, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x8019BA0C: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8019BA10: lwc1        $f18, 0xFC8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0XFC8);
    // 0x8019BA14: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x8019BA18: c.lt.s      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.fl < ctx->f18.fl;
    // 0x8019BA1C: nop

    // 0x8019BA20: bc1t        L_8019B888
    if (c1cs) {
        // 0x8019BA24: nop
    
            goto L_8019B888;
    }
    // 0x8019BA24: nop

L_8019BA28:
    // 0x8019BA28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8019BA2C:
    // 0x8019BA2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8019BA30: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8019BA34: jr          $ra
    // 0x8019BA38: nop

    return;
    // 0x8019BA38: nop

;}
RECOMP_FUNC void func_8019BA3C_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019BA3C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8019BA40: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8019BA44: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8019BA48: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8019BA4C: addiu       $t8, $t8, 0xF98
    ctx->r24 = ADD32(ctx->r24, 0XF98);
    // 0x8019BA50: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8019BA54: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8019BA58: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8019BA5C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8019BA60: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8019BA64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8019BA68: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8019BA6C: lwc1        $f4, 0x5C($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X5C);
    // 0x8019BA70: lwc1        $f6, 0x18($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X18);
    // 0x8019BA74: lwc1        $f16, 0x60($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X60);
    // 0x8019BA78: lwc1        $f18, 0x1C($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X1C);
    // 0x8019BA7C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8019BA80: lwc1        $f6, 0x60($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X60);
    // 0x8019BA84: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8019BA88: mul.s       $f10, $f8, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x8019BA8C: lwc1        $f8, 0x1C($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X1C);
    // 0x8019BA90: sub.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8019BA94: lwc1        $f8, 0x64($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X64);
    // 0x8019BA98: mul.s       $f18, $f4, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x8019BA9C: lwc1        $f4, 0x20($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X20);
    // 0x8019BAA0: sub.s       $f16, $f8, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x8019BAA4: add.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8019BAA8: mul.s       $f10, $f16, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8019BAAC: jal         0x800D68E0
    // 0x8019BAB0: add.s       $f12, $f10, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x8019BAB0: add.s       $f12, $f10, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f6.fl;
    after_0:
    // 0x8019BAB4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8019BAB8: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x8019BABC: swc1        $f0, 0x68($t0)
    MEM_W(0X68, ctx->r8) = ctx->f0.u32l;
    // 0x8019BAC0: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8019BAC4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8019BAC8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8019BACC: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8019BAD0: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x8019BAD4: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8019BAD8: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8019BADC: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x8019BAE0: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x8019BAE4: lwc1        $f18, 0xFF4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0XFF4);
    // 0x8019BAE8: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x8019BAEC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8019BAF0: swc1        $f18, 0x50($t3)
    MEM_W(0X50, ctx->r11) = ctx->f18.u32l;
    // 0x8019BAF4: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x8019BAF8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8019BAFC: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x8019BB00: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8019BB04: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x8019BB08: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8019BB0C: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8019BB10: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8019BB14: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x8019BB18: lwc1        $f8, 0xFF8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0XFF8);
    // 0x8019BB1C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8019BB20: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8019BB24: swc1        $f8, 0x54($t6)
    MEM_W(0X54, ctx->r14) = ctx->f8.u32l;
    // 0x8019BB28: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8019BB2C: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x8019BB30: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8019BB34: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8019BB38: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8019BB3C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8019BB40: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8019BB44: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8019BB48: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8019BB4C: lwc1        $f4, 0xFFC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XFFC);
    // 0x8019BB50: addiu       $t2, $t2, 0xF98
    ctx->r10 = ADD32(ctx->r10, 0XF98);
    // 0x8019BB54: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8019BB58: swc1        $f4, 0x58($t9)
    MEM_W(0X58, ctx->r25) = ctx->f4.u32l;
    // 0x8019BB5C: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8019BB60: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x8019BB64: lwc1        $f18, 0x68($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X68);
    // 0x8019BB68: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8019BB6C: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x8019BB70: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8019BB74: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8019BB78: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x8019BB7C: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x8019BB80: lwc1        $f16, 0x18($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X18);
    // 0x8019BB84: lwc1        $f10, 0x5C($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X5C);
    // 0x8019BB88: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8019BB8C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019BB90: sub.s       $f6, $f16, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x8019BB94: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8019BB98: addiu       $t7, $t7, 0xF98
    ctx->r15 = ADD32(ctx->r15, 0XF98);
    // 0x8019BB9C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8019BBA0: div.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f18.fl);
    // 0x8019BBA4: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x8019BBA8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8019BBAC: addiu       $t2, $t2, 0xF98
    ctx->r10 = ADD32(ctx->r10, 0XF98);
    // 0x8019BBB0: mul.s       $f16, $f8, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8019BBB4: swc1        $f16, 0x5C($t4)
    MEM_W(0X5C, ctx->r12) = ctx->f16.u32l;
    // 0x8019BBB8: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x8019BBBC: lwc1        $f8, 0x68($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X68);
    // 0x8019BBC0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8019BBC4: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8019BBC8: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x8019BBCC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8019BBD0: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8019BBD4: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8019BBD8: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8019BBDC: lwc1        $f10, 0x1C($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X1C);
    // 0x8019BBE0: lwc1        $f6, 0x60($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X60);
    // 0x8019BBE4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8019BBE8: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x8019BBEC: sub.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x8019BBF0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8019BBF4: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x8019BBF8: div.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f8.fl);
    // 0x8019BBFC: mul.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x8019BC00: swc1        $f10, 0x60($t9)
    MEM_W(0X60, ctx->r25) = ctx->f10.u32l;
    // 0x8019BC04: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8019BC08: lwc1        $f4, 0x68($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X68);
    // 0x8019BC0C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019BC10: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8019BC14: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x8019BC18: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8019BC1C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8019BC20: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x8019BC24: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x8019BC28: lwc1        $f6, 0x20($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X20);
    // 0x8019BC2C: lwc1        $f18, 0x64($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X64);
    // 0x8019BC30: sub.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f18.fl;
    // 0x8019BC34: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8019BC38: div.s       $f16, $f8, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8019BC3C: mul.s       $f6, $f16, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x8019BC40: swc1        $f6, 0x64($t4)
    MEM_W(0X64, ctx->r12) = ctx->f6.u32l;
    // 0x8019BC44: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    // 0x8019BC48: lwc1        $f8, 0x68($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X68);
    // 0x8019BC4C: c.lt.s      $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.fl < ctx->f8.fl;
    // 0x8019BC50: nop

    // 0x8019BC54: bc1f        L_8019BD90
    if (!c1cs) {
        // 0x8019BC58: nop
    
            goto L_8019BD90;
    }
    // 0x8019BC58: nop

L_8019BC5C:
    // 0x8019BC5C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8019BC60: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x8019BC64: lwc1        $f4, 0x50($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X50);
    // 0x8019BC68: lwc1        $f16, 0x5C($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X5C);
    // 0x8019BC6C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8019BC70: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x8019BC74: add.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x8019BC78: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8019BC7C: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x8019BC80: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8019BC84: swc1        $f10, 0x50($t6)
    MEM_W(0X50, ctx->r14) = ctx->f10.u32l;
    // 0x8019BC88: lwc1        $f6, 0x54($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X54);
    // 0x8019BC8C: lwc1        $f18, 0x60($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0X60);
    // 0x8019BC90: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8019BC94: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x8019BC98: add.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x8019BC9C: addiu       $t9, $t9, -0x4198
    ctx->r25 = ADD32(ctx->r25, -0X4198);
    // 0x8019BCA0: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8019BCA4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8019BCA8: swc1        $f8, 0x54($t7)
    MEM_W(0X54, ctx->r15) = ctx->f8.u32l;
    // 0x8019BCAC: lwc1        $f4, 0x58($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X58);
    // 0x8019BCB0: lwc1        $f16, 0x64($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X64);
    // 0x8019BCB4: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x8019BCB8: addiu       $t1, $t1, -0x4198
    ctx->r9 = ADD32(ctx->r9, -0X4198);
    // 0x8019BCBC: add.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x8019BCC0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8019BCC4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8019BCC8: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x8019BCCC: swc1        $f10, 0x58($t8)
    MEM_W(0X58, ctx->r24) = ctx->f10.u32l;
    // 0x8019BCD0: lwc1        $f18, 0x50($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X50);
    // 0x8019BCD4: lwc1        $f6, 0x0($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X0);
    // 0x8019BCD8: addiu       $t3, $t3, -0x4198
    ctx->r11 = ADD32(ctx->r11, -0X4198);
    // 0x8019BCDC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8019BCE0: sub.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f18.fl;
    // 0x8019BCE4: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x8019BCE8: swc1        $f8, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->f8.u32l;
    // 0x8019BCEC: lwc1        $f16, 0x54($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X54);
    // 0x8019BCF0: lwc1        $f4, 0x4($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X4);
    // 0x8019BCF4: sub.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x8019BCF8: swc1        $f10, 0x38($t2)
    MEM_W(0X38, ctx->r10) = ctx->f10.u32l;
    // 0x8019BCFC: lwc1        $f18, 0x58($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X58);
    // 0x8019BD00: lwc1        $f6, 0x8($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X8);
    // 0x8019BD04: sub.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f18.fl;
    // 0x8019BD08: swc1        $f8, 0x3C($t4)
    MEM_W(0X3C, ctx->r12) = ctx->f8.u32l;
    // 0x8019BD0C: lwc1        $f4, 0x34($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X34);
    // 0x8019BD10: lwc1        $f10, 0x38($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X38);
    // 0x8019BD14: lwc1        $f8, 0x3C($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X3C);
    // 0x8019BD18: mul.s       $f16, $f4, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x8019BD1C: nop

    // 0x8019BD20: mul.s       $f6, $f10, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x8019BD24: add.s       $f18, $f16, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x8019BD28: mul.s       $f4, $f8, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x8019BD2C: jal         0x800D68E0
    // 0x8019BD30: add.s       $f12, $f4, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f18.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x8019BD30: add.s       $f12, $f4, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f18.fl;
    after_1:
    // 0x8019BD34: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8019BD38: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019BD3C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8019BD40: lwc1        $f16, -0x2E30($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x8019BD44: mul.s       $f6, $f10, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8019BD48: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x8019BD4C: nop

    // 0x8019BD50: bc1f        L_8019BD60
    if (!c1cs) {
        // 0x8019BD54: nop
    
            goto L_8019BD60;
    }
    // 0x8019BD54: nop

    // 0x8019BD58: b           L_8019BD94
    // 0x8019BD5C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8019BD94;
    // 0x8019BD5C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8019BD60:
    // 0x8019BD60: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8019BD64: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019BD68: lwc1        $f8, 0x1C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8019BD6C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8019BD70: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x8019BD74: add.s       $f18, $f8, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8019BD78: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    // 0x8019BD7C: lwc1        $f10, 0x68($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X68);
    // 0x8019BD80: c.lt.s      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.fl < ctx->f10.fl;
    // 0x8019BD84: nop

    // 0x8019BD88: bc1t        L_8019BC5C
    if (c1cs) {
        // 0x8019BD8C: nop
    
            goto L_8019BC5C;
    }
    // 0x8019BD8C: nop

L_8019BD90:
    // 0x8019BD90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8019BD94:
    // 0x8019BD94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8019BD98: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8019BD9C: jr          $ra
    // 0x8019BDA0: nop

    return;
    // 0x8019BDA0: nop

;}
RECOMP_FUNC void func_8019BDA4_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019BDA4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8019BDA8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8019BDAC: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8019BDB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8019BDB4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8019BDB8: sltiu       $at, $t6, 0x10
    ctx->r1 = ctx->r14 < 0X10 ? 1 : 0;
    // 0x8019BDBC: bne         $at, $zero, L_8019BDD0
    if (ctx->r1 != 0) {
        // 0x8019BDC0: nop
    
            goto L_8019BDD0;
    }
    // 0x8019BDC0: nop

    // 0x8019BDC4: addiu       $t7, $zero, 0x18
    ctx->r15 = ADD32(0, 0X18);
    // 0x8019BDC8: b           L_8019BDE8
    // 0x8019BDCC: sh          $t7, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r15;
        goto L_8019BDE8;
    // 0x8019BDCC: sh          $t7, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r15;
L_8019BDD0:
    // 0x8019BDD0: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8019BDD4: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8019BDD8: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8019BDDC: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8019BDE0: lhu         $t0, -0xE6C($t0)
    ctx->r8 = MEM_HU(ctx->r8, -0XE6C);
    // 0x8019BDE4: sh          $t0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r8;
L_8019BDE8:
    // 0x8019BDE8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8019BDEC: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x8019BDF0: addiu       $t1, $t1, -0x2E28
    ctx->r9 = ADD32(ctx->r9, -0X2E28);
    // 0x8019BDF4: lbu         $t2, 0xF($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0XF);
    // 0x8019BDF8: addiu       $t4, $zero, 0x10
    ctx->r12 = ADD32(0, 0X10);
    // 0x8019BDFC: sllv        $t5, $t4, $t3
    ctx->r13 = S32(ctx->r12 << (ctx->r11 & 31));
    // 0x8019BE00: and         $t6, $t2, $t5
    ctx->r14 = ctx->r10 & ctx->r13;
    // 0x8019BE04: beq         $t6, $zero, L_8019BE1C
    if (ctx->r14 == 0) {
        // 0x8019BE08: nop
    
            goto L_8019BE1C;
    }
    // 0x8019BE08: nop

    // 0x8019BE0C: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    // 0x8019BE10: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    // 0x8019BE14: jal         0x800D2800
    // 0x8019BE18: lhu         $a2, 0x1E($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X1E);
    func_800D2800(rdram, ctx);
        goto after_0;
    // 0x8019BE18: lhu         $a2, 0x1E($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X1E);
    after_0:
L_8019BE1C:
    // 0x8019BE1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8019BE20: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8019BE24: jr          $ra
    // 0x8019BE28: nop

    return;
    // 0x8019BE28: nop

;}
RECOMP_FUNC void func_8019BE2C_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019BE2C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8019BE30: lwc1        $f18, 0x3948($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X3948);
    // 0x8019BE34: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8019BE38: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8019BE3C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8019BE40: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8019BE44: sub.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x8019BE48: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8019BE4C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8019BE50: sub.s       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f18.fl;
    // 0x8019BE54: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019BE58: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x8019BE5C: addiu       $t8, $t8, 0x3918
    ctx->r24 = ADD32(ctx->r24, 0X3918);
    // 0x8019BE60: mul.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8019BE64: sub.s       $f16, $f18, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x8019BE68: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019BE6C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8019BE70: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8019BE74: addiu       $t9, $t9, 0x3918
    ctx->r25 = ADD32(ctx->r25, 0X3918);
    // 0x8019BE78: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8019BE7C: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8019BE80: addiu       $t0, $t0, 0x3918
    ctx->r8 = ADD32(ctx->r8, 0X3918);
    // 0x8019BE84: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8019BE88: addiu       $t1, $t1, 0x3918
    ctx->r9 = ADD32(ctx->r9, 0X3918);
    // 0x8019BE8C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8019BE90: addiu       $t2, $t2, 0x3918
    ctx->r10 = ADD32(ctx->r10, 0X3918);
    // 0x8019BE94: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8019BE98: div.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f10.fl, ctx->f6.fl);
    // 0x8019BE9C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019BEA0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8019BEA4: addiu       $t3, $t3, 0x3918
    ctx->r11 = ADD32(ctx->r11, 0X3918);
    // 0x8019BEA8: add.s       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x8019BEAC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8019BEB0: addiu       $t4, $t4, 0x3918
    ctx->r12 = ADD32(ctx->r12, 0X3918);
    // 0x8019BEB4: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8019BEB8: mul.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x8019BEBC: addiu       $t5, $t5, 0x3918
    ctx->r13 = ADD32(ctx->r13, 0X3918);
    // 0x8019BEC0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8019BEC4: addiu       $t6, $t6, 0x3918
    ctx->r14 = ADD32(ctx->r14, 0X3918);
    // 0x8019BEC8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8019BECC: addiu       $t7, $t7, 0x3918
    ctx->r15 = ADD32(ctx->r15, 0X3918);
    // 0x8019BED0: mul.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8019BED4: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x8019BED8: swc1        $f8, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f8.u32l;
    // 0x8019BEDC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019BEE0: nop

    // 0x8019BEE4: div.s       $f10, $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8019BEE8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8019BEEC: nop

    // 0x8019BEF0: sub.s       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x8019BEF4: mul.s       $f8, $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x8019BEF8: nop

    // 0x8019BEFC: mul.s       $f8, $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8019BF00: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8019BF04: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x8019BF08: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8019BF0C: div.s       $f8, $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = DIV_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8019BF10: mul.s       $f16, $f6, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x8019BF14: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8019BF18: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8019BF1C: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x8019BF20: swc1        $f8, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->f8.u32l;
    // 0x8019BF24: lwc1        $f4, 0x0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X0);
    // 0x8019BF28: div.s       $f16, $f6, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = DIV_S(ctx->f6.fl, ctx->f18.fl);
    // 0x8019BF2C: swc1        $f16, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f16.u32l;
    // 0x8019BF30: lwc1        $f6, 0x0($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X0);
    // 0x8019BF34: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8019BF38: addiu       $t8, $t8, 0x3918
    ctx->r24 = ADD32(ctx->r24, 0X3918);
    // 0x8019BF3C: mul.s       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8019BF40: lwc1        $f6, 0x4($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X4);
    // 0x8019BF44: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8019BF48: addiu       $t9, $t9, 0x3918
    ctx->r25 = ADD32(ctx->r25, 0X3918);
    // 0x8019BF4C: mul.s       $f6, $f10, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x8019BF50: add.s       $f18, $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8019BF54: lwc1        $f6, 0x8($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X8);
    // 0x8019BF58: mul.s       $f6, $f8, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8019BF5C: add.s       $f18, $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8019BF60: lwc1        $f6, 0xC($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0XC);
    // 0x8019BF64: mul.s       $f6, $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x8019BF68: add.s       $f6, $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x8019BF6C: swc1        $f6, 0x394C($at)
    MEM_W(0X394C, ctx->r1) = ctx->f6.u32l;
    // 0x8019BF70: lwc1        $f18, 0x10($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X10);
    // 0x8019BF74: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8019BF78: mul.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x8019BF7C: lwc1        $f18, 0x14($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X14);
    // 0x8019BF80: mul.s       $f18, $f10, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8019BF84: add.s       $f6, $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x8019BF88: lwc1        $f18, 0x18($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X18);
    // 0x8019BF8C: mul.s       $f18, $f8, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x8019BF90: add.s       $f6, $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x8019BF94: lwc1        $f18, 0x1C($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X1C);
    // 0x8019BF98: mul.s       $f18, $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x8019BF9C: add.s       $f18, $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8019BFA0: swc1        $f18, 0x3950($at)
    MEM_W(0X3950, ctx->r1) = ctx->f18.u32l;
    // 0x8019BFA4: lwc1        $f6, 0x20($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X20);
    // 0x8019BFA8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8019BFAC: mul.s       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8019BFB0: lwc1        $f4, 0x24($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X24);
    // 0x8019BFB4: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8019BFB8: lwc1        $f4, 0x28($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X28);
    // 0x8019BFBC: add.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8019BFC0: mul.s       $f18, $f8, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8019BFC4: lwc1        $f8, 0x2C($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X2C);
    // 0x8019BFC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8019BFCC: mul.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8019BFD0: add.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8019BFD4: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8019BFD8: jr          $ra
    // 0x8019BFDC: swc1        $f10, 0x3954($at)
    MEM_W(0X3954, ctx->r1) = ctx->f10.u32l;
    return;
    // 0x8019BFDC: swc1        $f10, 0x3954($at)
    MEM_W(0X3954, ctx->r1) = ctx->f10.u32l;
;}
RECOMP_FUNC void func_8019BFE0_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019BFE0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8019BFE4: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8019BFE8: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    // 0x8019BFEC: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8019BFF0: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8019BFF4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8019BFF8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8019BFFC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8019C000: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8019C004: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    // 0x8019C008: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8019C00C: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x8019C010: swc1        $f8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f8.u32l;
    // 0x8019C014: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8019C018: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8019C01C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8019C020: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x8019C024: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8019C028: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8019C02C: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x8019C030: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8019C034: swc1        $f18, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->f18.u32l;
    // 0x8019C038: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8019C03C: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8019C040: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x8019C044: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8019C048: swc1        $f8, 0x14($t8)
    MEM_W(0X14, ctx->r24) = ctx->f8.u32l;
    // 0x8019C04C: lwc1        $f10, 0xC($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0XC);
    // 0x8019C050: lwc1        $f18, 0x10($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X10);
    // 0x8019C054: lwc1        $f8, 0x14($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X14);
    // 0x8019C058: mul.s       $f16, $f10, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x8019C05C: nop

    // 0x8019C060: mul.s       $f4, $f18, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x8019C064: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x8019C068: mul.s       $f10, $f8, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x8019C06C: jal         0x800D68E0
    // 0x8019C070: add.s       $f12, $f10, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x8019C070: add.s       $f12, $f10, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f6.fl;
    after_0:
    // 0x8019C074: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8019C078: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x8019C07C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8019C080: swc1        $f0, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->f0.u32l;
    // 0x8019C084: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x8019C088: lwc1        $f18, 0x14($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X14);
    // 0x8019C08C: lwc1        $f4, 0xC($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0XC);
    // 0x8019C090: mul.s       $f16, $f18, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x8019C094: nop

    // 0x8019C098: mul.s       $f8, $f4, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x8019C09C: jal         0x800D68E0
    // 0x8019C0A0: add.s       $f12, $f16, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x8019C0A0: add.s       $f12, $f16, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f8.fl;
    after_1:
    // 0x8019C0A4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8019C0A8: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x8019C0AC: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8019C0B0: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    // 0x8019C0B4: jal         0x800E4940
    // 0x8019C0B8: lwc1        $f12, 0x10($t2)
    ctx->f12.u32l = MEM_W(ctx->r10, 0X10);
    func_800E4940(rdram, ctx);
        goto after_2;
    // 0x8019C0B8: lwc1        $f12, 0x10($t2)
    ctx->f12.u32l = MEM_W(ctx->r10, 0X10);
    after_2:
    // 0x8019C0BC: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8019C0C0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019C0C4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019C0C8: lwc1        $f18, 0xBE4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0XBE4);
    // 0x8019C0CC: mul.s       $f6, $f0, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8019C0D0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8019C0D4: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x8019C0D8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8019C0DC: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x8019C0E0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8019C0E4: div.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f6.fl, ctx->f18.fl);
    // 0x8019C0E8: swc1        $f4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f4.u32l;
    // 0x8019C0EC: lwc1        $f16, 0x0($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X0);
    // 0x8019C0F0: c.lt.s      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.fl < ctx->f8.fl;
    // 0x8019C0F4: nop

    // 0x8019C0F8: bc1f        L_8019C110
    if (!c1cs) {
        // 0x8019C0FC: lui         $at, 0x43B4
        ctx->r1 = S32(0X43B4 << 16);
            goto L_8019C110;
    }
    // 0x8019C0FC: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8019C100: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019C104: nop

    // 0x8019C108: add.s       $f6, $f16, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x8019C10C: swc1        $f6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f6.u32l;
L_8019C110:
    // 0x8019C110: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8019C114: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x8019C118: lwc1        $f12, 0xC($t5)
    ctx->f12.u32l = MEM_W(ctx->r13, 0XC);
    // 0x8019C11C: jal         0x800E4940
    // 0x8019C120: lwc1        $f14, 0x14($t5)
    ctx->f14.u32l = MEM_W(ctx->r13, 0X14);
    func_800E4940(rdram, ctx);
        goto after_3;
    // 0x8019C120: lwc1        $f14, 0x14($t5)
    ctx->f14.u32l = MEM_W(ctx->r13, 0X14);
    after_3:
    // 0x8019C124: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8019C128: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8019C12C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019C130: lwc1        $f8, 0xBE8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0XBE8);
    // 0x8019C134: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8019C138: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8019C13C: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x8019C140: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8019C144: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x8019C148: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8019C14C: div.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8019C150: swc1        $f16, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f16.u32l;
    // 0x8019C154: lwc1        $f10, 0x4($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X4);
    // 0x8019C158: c.lt.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl < ctx->f6.fl;
    // 0x8019C15C: nop

    // 0x8019C160: bc1f        L_8019C178
    if (!c1cs) {
        // 0x8019C164: lui         $at, 0x43B4
        ctx->r1 = S32(0X43B4 << 16);
            goto L_8019C178;
    }
    // 0x8019C164: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8019C168: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8019C16C: nop

    // 0x8019C170: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8019C174: swc1        $f4, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f4.u32l;
L_8019C178:
    // 0x8019C178: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8019C17C: addiu       $t8, $t8, -0x4198
    ctx->r24 = ADD32(ctx->r24, -0X4198);
    // 0x8019C180: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019C184: lwc1        $f16, 0xBEC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0XBEC);
    // 0x8019C188: lwc1        $f8, 0x24($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X24);
    // 0x8019C18C: mul.s       $f12, $f8, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8019C190: jal         0x800D68F0
    // 0x8019C194: nop

    sinf_recomp(rdram, ctx);
        goto after_4;
    // 0x8019C194: nop

    after_4:
    // 0x8019C198: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8019C19C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8019C1A0: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x8019C1A4: addiu       $t9, $t9, -0x4198
    ctx->r25 = ADD32(ctx->r25, -0X4198);
    // 0x8019C1A8: lwc1        $f6, 0x28($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X28);
    // 0x8019C1AC: lwc1        $f10, 0x4($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X4);
    // 0x8019C1B0: sub.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x8019C1B4: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8019C1B8: swc1        $f4, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f4.u32l;
    // 0x8019C1BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8019C1C0: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8019C1C4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8019C1C8: jr          $ra
    // 0x8019C1CC: nop

    return;
    // 0x8019C1CC: nop

;}
RECOMP_FUNC void func_8019C1D0_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019C1D0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8019C1D4: lwc1        $f4, -0x41B0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X41B0);
    // 0x8019C1D8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8019C1DC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019C1E0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019C1E4: lwc1        $f10, 0xBF0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0XBF0);
    // 0x8019C1E8: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8019C1EC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8019C1F0: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8019C1F4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8019C1F8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8019C1FC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8019C200: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8019C204: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8019C208: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8019C20C: jal         0x800E4E30
    // 0x8019C210: div.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    func_800E4E30(rdram, ctx);
        goto after_0;
    // 0x8019C210: div.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    after_0:
    // 0x8019C214: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8019C218: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019C21C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8019C220: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x8019C224: div.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8019C228: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8019C22C: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x8019C230: swc1        $f6, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f6.u32l;
    // 0x8019C234: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8019C238: lwc1        $f14, 0x0($t8)
    ctx->f14.u32l = MEM_W(ctx->r24, 0X0);
    // 0x8019C23C: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x8019C240: jal         0x800E4940
    // 0x8019C244: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    func_800E4940(rdram, ctx);
        goto after_1;
    // 0x8019C244: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    after_1:
    // 0x8019C248: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8019C24C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019C250: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8019C254: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019C258: mul.s       $f16, $f20, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f20.fl, ctx->f10.fl);
    // 0x8019C25C: lwc1        $f18, 0xBF4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0XBF4);
    // 0x8019C260: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8019C264: addiu       $t9, $t9, -0x4198
    ctx->r25 = ADD32(ctx->r25, -0X4198);
    // 0x8019C268: lwc1        $f6, 0x38($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X38);
    // 0x8019C26C: lw          $a2, 0x30($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X30);
    // 0x8019C270: lw          $a3, 0x34($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X34);
    // 0x8019C274: div.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8019C278: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8019C27C: addiu       $a0, $a0, 0x4300
    ctx->r4 = ADD32(ctx->r4, 0X4300);
    // 0x8019C280: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x8019C284: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8019C288: jal         0x800D7120
    // 0x8019C28C: nop

    guAlignF_recomp(rdram, ctx);
        goto after_2;
    // 0x8019C28C: nop

    after_2:
    // 0x8019C290: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8019C294: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8019C298: addiu       $t0, $t0, 0x4300
    ctx->r8 = ADD32(ctx->r8, 0X4300);
    // 0x8019C29C: addiu       $a0, $a0, -0x4198
    ctx->r4 = ADD32(ctx->r4, -0X4198);
    // 0x8019C2A0: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    // 0x8019C2A4: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    // 0x8019C2A8: jal         0x800D6F30
    // 0x8019C2AC: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    guMtxCatF_recomp(rdram, ctx);
        goto after_3;
    // 0x8019C2AC: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    after_3:
    // 0x8019C2B0: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8019C2B4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8019C2B8: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x8019C2BC: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x8019C2C0: lwc1        $f14, 0x0($t2)
    ctx->f14.u32l = MEM_W(ctx->r10, 0X0);
    // 0x8019C2C4: jal         0x800E4940
    // 0x8019C2C8: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    func_800E4940(rdram, ctx);
        goto after_4;
    // 0x8019C2C8: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    after_4:
    // 0x8019C2CC: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8019C2D0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019C2D4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8019C2D8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019C2DC: mul.s       $f16, $f20, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f20.fl, ctx->f10.fl);
    // 0x8019C2E0: lwc1        $f18, 0xBF8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0XBF8);
    // 0x8019C2E4: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8019C2E8: addiu       $t3, $t3, 0x4300
    ctx->r11 = ADD32(ctx->r11, 0X4300);
    // 0x8019C2EC: lwc1        $f8, 0x18($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X18);
    // 0x8019C2F0: lw          $a2, 0x10($t3)
    ctx->r6 = MEM_W(ctx->r11, 0X10);
    // 0x8019C2F4: lw          $a3, 0x14($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X14);
    // 0x8019C2F8: div.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8019C2FC: addiu       $a0, $t3, 0x40
    ctx->r4 = ADD32(ctx->r11, 0X40);
    // 0x8019C300: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x8019C304: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8019C308: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8019C30C: jal         0x800D7120
    // 0x8019C310: nop

    guAlignF_recomp(rdram, ctx);
        goto after_5;
    // 0x8019C310: nop

    after_5:
    // 0x8019C314: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8019C318: addiu       $t4, $t4, 0x4300
    ctx->r12 = ADD32(ctx->r12, 0X4300);
    // 0x8019C31C: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x8019C320: addiu       $a1, $t4, 0x40
    ctx->r5 = ADD32(ctx->r12, 0X40);
    // 0x8019C324: jal         0x800D6F30
    // 0x8019C328: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    guMtxCatF_recomp(rdram, ctx);
        goto after_6;
    // 0x8019C328: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    after_6:
    // 0x8019C32C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8019C330: addiu       $t5, $t5, 0x4300
    ctx->r13 = ADD32(ctx->r13, 0X4300);
    // 0x8019C334: lwc1        $f10, 0x20($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X20);
    // 0x8019C338: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8019C33C: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x8019C340: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8019C344: addiu       $t7, $t7, 0x4300
    ctx->r15 = ADD32(ctx->r15, 0X4300);
    // 0x8019C348: swc1        $f10, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f10.u32l;
    // 0x8019C34C: lwc1        $f16, 0x24($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X24);
    // 0x8019C350: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8019C354: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x8019C358: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8019C35C: addiu       $t9, $t9, 0x4300
    ctx->r25 = ADD32(ctx->r25, 0X4300);
    // 0x8019C360: swc1        $f16, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f16.u32l;
    // 0x8019C364: lwc1        $f18, 0x28($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X28);
    // 0x8019C368: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8019C36C: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x8019C370: swc1        $f18, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f18.u32l;
    // 0x8019C374: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8019C378: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8019C37C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8019C380: jr          $ra
    // 0x8019C384: nop

    return;
    // 0x8019C384: nop

;}
RECOMP_FUNC void func_8019C388_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019C388: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8019C38C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8019C390: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8019C394: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8019C398: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8019C39C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8019C3A0: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8019C3A4: lwc1        $f4, 0x0($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X0);
    // 0x8019C3A8: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8019C3AC: lwc1        $f8, 0x0($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X0);
    // 0x8019C3B0: mul.s       $f6, $f4, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x8019C3B4: lwc1        $f18, 0x0($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X0);
    // 0x8019C3B8: mul.s       $f10, $f8, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x8019C3BC: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8019C3C0: mul.s       $f4, $f18, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x8019C3C4: jal         0x800D68E0
    // 0x8019C3C8: add.s       $f12, $f4, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f16.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x8019C3C8: add.s       $f12, $f4, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f16.fl;
    after_0:
    // 0x8019C3CC: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8019C3D0: lwc1        $f8, 0x1C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8019C3D4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8019C3D8: nop

    // 0x8019C3DC: c.eq.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl == ctx->f6.fl;
    // 0x8019C3E0: nop

    // 0x8019C3E4: bc1t        L_8019C434
    if (c1cs) {
        // 0x8019C3E8: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8019C434;
    }
    // 0x8019C3E8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8019C3EC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019C3F0: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8019C3F4: div.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8019C3F8: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    // 0x8019C3FC: lwc1        $f4, 0x0($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X0);
    // 0x8019C400: mul.s       $f16, $f4, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x8019C404: swc1        $f16, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f16.u32l;
    // 0x8019C408: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8019C40C: lwc1        $f10, 0x1C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8019C410: lwc1        $f6, 0x0($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8019C414: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8019C418: swc1        $f8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f8.u32l;
    // 0x8019C41C: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8019C420: lwc1        $f18, 0x1C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8019C424: lwc1        $f4, 0x0($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X0);
    // 0x8019C428: mul.s       $f16, $f4, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x8019C42C: b           L_8019C45C
    // 0x8019C430: swc1        $f16, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f16.u32l;
        goto L_8019C45C;
    // 0x8019C430: swc1        $f16, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f16.u32l;
L_8019C434:
    // 0x8019C434: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8019C438: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019C43C: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8019C440: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8019C444: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8019C448: swc1        $f6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f6.u32l;
    // 0x8019C44C: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8019C450: swc1        $f10, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f10.u32l;
    // 0x8019C454: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8019C458: swc1        $f8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f8.u32l;
L_8019C45C:
    // 0x8019C45C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8019C460: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8019C464: jr          $ra
    // 0x8019C468: nop

    return;
    // 0x8019C468: nop

;}
RECOMP_FUNC void func_8019C46C_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019C46C: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8019C470: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8019C474: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8019C478: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x8019C47C: swc1        $f12, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f12.u32l;
    // 0x8019C480: swc1        $f14, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f14.u32l;
    // 0x8019C484: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8019C488: addiu       $t6, $t6, -0x4198
    ctx->r14 = ADD32(ctx->r14, -0X4198);
    // 0x8019C48C: lwc1        $f4, 0xC($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0XC);
    // 0x8019C490: lwc1        $f6, 0x0($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X0);
    // 0x8019C494: addiu       $a2, $sp, 0x5C
    ctx->r6 = ADD32(ctx->r29, 0X5C);
    // 0x8019C498: addiu       $a0, $sp, 0x64
    ctx->r4 = ADD32(ctx->r29, 0X64);
    // 0x8019C49C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8019C4A0: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    // 0x8019C4A4: swc1        $f8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f8.u32l;
    // 0x8019C4A8: lwc1        $f16, 0x4($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X4);
    // 0x8019C4AC: lwc1        $f10, 0x10($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X10);
    // 0x8019C4B0: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8019C4B4: swc1        $f18, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f18.u32l;
    // 0x8019C4B8: lwc1        $f6, 0x8($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X8);
    // 0x8019C4BC: lwc1        $f4, 0x14($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X14);
    // 0x8019C4C0: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8019C4C4: jal         0x8019C388
    // 0x8019C4C8: swc1        $f8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f8.u32l;
    func_8019C388_1501A0(rdram, ctx);
        goto after_0;
    // 0x8019C4C8: swc1        $f8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x8019C4CC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8019C4D0: addiu       $t7, $t7, -0x4198
    ctx->r15 = ADD32(ctx->r15, -0X4198);
    // 0x8019C4D4: lwc1        $f16, 0x20($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X20);
    // 0x8019C4D8: lwc1        $f10, 0x60($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8019C4DC: lwc1        $f4, 0x1C($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X1C);
    // 0x8019C4E0: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8019C4E4: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8019C4E8: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x8019C4EC: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x8019C4F0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8019C4F4: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    // 0x8019C4F8: sub.s       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x8019C4FC: swc1        $f16, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f16.u32l;
    // 0x8019C500: lwc1        $f4, 0x18($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X18);
    // 0x8019C504: lwc1        $f8, 0x20($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X20);
    // 0x8019C508: lwc1        $f16, 0x64($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8019C50C: mul.s       $f18, $f6, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x8019C510: nop

    // 0x8019C514: mul.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8019C518: sub.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x8019C51C: swc1        $f4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f4.u32l;
    // 0x8019C520: lwc1        $f8, 0x1C($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X1C);
    // 0x8019C524: lwc1        $f6, 0x18($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X18);
    // 0x8019C528: mul.s       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x8019C52C: nop

    // 0x8019C530: mul.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8019C534: sub.s       $f16, $f18, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8019C538: jal         0x8019C388
    // 0x8019C53C: swc1        $f16, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f16.u32l;
    func_8019C388_1501A0(rdram, ctx);
        goto after_1;
    // 0x8019C53C: swc1        $f16, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f16.u32l;
    after_1:
    // 0x8019C540: lwc1        $f8, 0x64($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8019C544: lwc1        $f6, 0x68($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8019C548: lwc1        $f18, 0x60($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8019C54C: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8019C550: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8019C554: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8019C558: addiu       $t8, $t8, -0x4198
    ctx->r24 = ADD32(ctx->r24, -0X4198);
    // 0x8019C55C: mul.s       $f16, $f18, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8019C560: lwc1        $f4, 0x5C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8019C564: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8019C568: add.s       $f6, $f10, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8019C56C: lwc1        $f10, 0x70($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8019C570: mul.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8019C574: add.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x8019C578: neg.s       $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = -ctx->f10.fl;
    // 0x8019C57C: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    // 0x8019C580: lwc1        $f16, 0x0($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X0);
    // 0x8019C584: mul.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8019C588: lwc1        $f16, 0x4($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X4);
    // 0x8019C58C: mul.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x8019C590: add.s       $f6, $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x8019C594: lwc1        $f16, 0x8($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X8);
    // 0x8019C598: mul.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x8019C59C: add.s       $f16, $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x8019C5A0: sub.s       $f6, $f16, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x8019C5A4: neg.s       $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = -ctx->f6.fl;
    // 0x8019C5A8: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    // 0x8019C5AC: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8019C5B0: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    // 0x8019C5B4: lwc1        $f6, 0x0($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X0);
    // 0x8019C5B8: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8019C5BC: mul.s       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x8019C5C0: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
    // 0x8019C5C4: lwc1        $f10, 0x4($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X4);
    // 0x8019C5C8: mul.s       $f18, $f4, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x8019C5CC: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8019C5D0: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
    // 0x8019C5D4: lwc1        $f8, -0x41B0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X41B0);
    // 0x8019C5D8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8019C5DC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019C5E0: lwc1        $f10, 0x8($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X8);
    // 0x8019C5E4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019C5E8: div.s       $f16, $f8, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8019C5EC: add.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8019C5F0: lwc1        $f10, 0xBFC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0XBFC);
    // 0x8019C5F4: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8019C5F8: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    // 0x8019C5FC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019C600: mul.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x8019C604: jal         0x800D68F0
    // 0x8019C608: div.s       $f12, $f18, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = DIV_S(ctx->f18.fl, ctx->f6.fl);
    sinf_recomp(rdram, ctx);
        goto after_2;
    // 0x8019C608: div.s       $f12, $f18, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = DIV_S(ctx->f18.fl, ctx->f6.fl);
    after_2:
    // 0x8019C60C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8019C610: lwc1        $f8, -0x41B0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X41B0);
    // 0x8019C614: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8019C618: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019C61C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019C620: lwc1        $f10, 0xC00($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0XC00);
    // 0x8019C624: div.s       $f16, $f8, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8019C628: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8019C62C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019C630: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8019C634: mul.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x8019C638: jal         0x800D6AB0
    // 0x8019C63C: div.s       $f12, $f18, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = DIV_S(ctx->f18.fl, ctx->f6.fl);
    __cosf_recomp(rdram, ctx);
        goto after_3;
    // 0x8019C63C: div.s       $f12, $f18, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = DIV_S(ctx->f18.fl, ctx->f6.fl);
    after_3:
    // 0x8019C640: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8019C644: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8019C648: mul.s       $f4, $f8, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x8019C64C: div.s       $f16, $f4, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8019C650: c.eq.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl == ctx->f10.fl;
    // 0x8019C654: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    // 0x8019C658: bc1f        L_8019C668
    if (!c1cs) {
        // 0x8019C65C: lui         $at, 0x801A
        ctx->r1 = S32(0X801A << 16);
            goto L_8019C668;
    }
    // 0x8019C65C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019C660: lwc1        $f18, 0xC04($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0XC04);
    // 0x8019C664: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
L_8019C668:
    // 0x8019C668: lwc1        $f6, 0x68($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8019C66C: lwc1        $f8, 0x4C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8019C670: lwc1        $f16, 0x6C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8019C674: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8019C678: sub.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8019C67C: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8019C680: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8019C684: sub.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x8019C688: lwc1        $f10, 0x58($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8019C68C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8019C690: sub.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8019C694: mul.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8019C698: lwc1        $f8, 0x54($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8019C69C: swc1        $f4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f4.u32l;
    // 0x8019C6A0: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    // 0x8019C6A4: mul.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x8019C6A8: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    // 0x8019C6AC: addiu       $t9, $t9, -0x4198
    ctx->r25 = ADD32(ctx->r25, -0X4198);
    // 0x8019C6B0: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8019C6B4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8019C6B8: addiu       $a1, $a1, 0x3E00
    ctx->r5 = ADD32(ctx->r5, 0X3E00);
    // 0x8019C6BC: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8019C6C0: lwc1        $f6, 0x50($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8019C6C4: mul.s       $f10, $f16, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x8019C6C8: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8019C6CC: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x8019C6D0: lwc1        $f8, 0x18($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X18);
    // 0x8019C6D4: lwc1        $f6, 0x1C($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X1C);
    // 0x8019C6D8: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8019C6DC: nop

    // 0x8019C6E0: mul.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x8019C6E4: lwc1        $f18, 0x20($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X20);
    // 0x8019C6E8: mul.s       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x8019C6EC: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8019C6F0: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8019C6F4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019C6F8: nop

    // 0x8019C6FC: mul.s       $f16, $f4, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x8019C700: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8019C704: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8019C708: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    // 0x8019C70C: jal         0x800E4E00
    // 0x8019C710: div.s       $f12, $f16, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = DIV_S(ctx->f16.fl, ctx->f6.fl);
    func_800E4E00(rdram, ctx);
        goto after_4;
    // 0x8019C710: div.s       $f12, $f16, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = DIV_S(ctx->f16.fl, ctx->f6.fl);
    after_4:
    // 0x8019C714: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8019C718: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019C71C: nop

    // 0x8019C720: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x8019C724: nop

    // 0x8019C728: bc1f        L_8019C74C
    if (!c1cs) {
        // 0x8019C72C: nop
    
            goto L_8019C74C;
    }
    // 0x8019C72C: nop

    // 0x8019C730: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8019C734: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x8019C738: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8019C73C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019C740: lwc1        $f10, 0x0($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8019C744: add.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8019C748: swc1        $f18, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f18.u32l;
L_8019C74C:
    // 0x8019C74C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8019C750: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x8019C754: lwc1        $f16, 0x0($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X0);
    // 0x8019C758: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8019C75C: addiu       $t4, $t4, 0x3D00
    ctx->r12 = ADD32(ctx->r12, 0X3D00);
    // 0x8019C760: trunc.w.s   $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8019C764: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8019C768: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019C76C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8019C770: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x8019C774: addiu       $a1, $a1, 0x3E00
    ctx->r5 = ADD32(ctx->r5, 0X3E00);
    // 0x8019C778: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8019C77C: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x8019C780: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8019C784: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8019C788: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8019C78C: jal         0x800E4E00
    // 0x8019C790: div.s       $f12, $f4, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = DIV_S(ctx->f4.fl, ctx->f18.fl);
    func_800E4E00(rdram, ctx);
        goto after_5;
    // 0x8019C790: div.s       $f12, $f4, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = DIV_S(ctx->f4.fl, ctx->f18.fl);
    after_5:
    // 0x8019C794: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8019C798: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8019C79C: nop

    // 0x8019C7A0: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x8019C7A4: nop

    // 0x8019C7A8: bc1f        L_8019C7CC
    if (!c1cs) {
        // 0x8019C7AC: nop
    
            goto L_8019C7CC;
    }
    // 0x8019C7AC: nop

    // 0x8019C7B0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8019C7B4: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x8019C7B8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8019C7BC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019C7C0: lwc1        $f6, 0x4($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X4);
    // 0x8019C7C4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8019C7C8: swc1        $f10, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->f10.u32l;
L_8019C7CC:
    // 0x8019C7CC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8019C7D0: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x8019C7D4: lwc1        $f4, 0x4($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X4);
    // 0x8019C7D8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8019C7DC: addiu       $t9, $t9, 0x3D00
    ctx->r25 = ADD32(ctx->r25, 0X3D00);
    // 0x8019C7E0: trunc.w.s   $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8019C7E4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8019C7E8: addiu       $t0, $t0, 0x3D00
    ctx->r8 = ADD32(ctx->r8, 0X3D00);
    // 0x8019C7EC: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x8019C7F0: nop

    // 0x8019C7F4: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x8019C7F8: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x8019C7FC: negu        $t2, $t1
    ctx->r10 = SUB32(0, ctx->r9);
    // 0x8019C800: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
    // 0x8019C804: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8019C808: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8019C80C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x8019C810: jr          $ra
    // 0x8019C814: nop

    return;
    // 0x8019C814: nop

;}
RECOMP_FUNC void func_8019C818_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019C818: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8019C81C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8019C820: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8019C824: addiu       $t6, $t6, -0x2E28
    ctx->r14 = ADD32(ctx->r14, -0X2E28);
    // 0x8019C828: lbu         $t7, 0xC($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0XC);
    // 0x8019C82C: andi        $t8, $t7, 0x10
    ctx->r24 = ctx->r15 & 0X10;
    // 0x8019C830: beq         $t8, $zero, L_8019C8E0
    if (ctx->r24 == 0) {
        // 0x8019C834: nop
    
            goto L_8019C8E0;
    }
    // 0x8019C834: nop

    // 0x8019C838: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8019C83C: addiu       $t9, $t9, -0x2BA8
    ctx->r25 = ADD32(ctx->r25, -0X2BA8);
    // 0x8019C840: lw          $t0, 0x10C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X10C);
    // 0x8019C844: andi        $t1, $t0, 0x10
    ctx->r9 = ctx->r8 & 0X10;
    // 0x8019C848: bne         $t1, $zero, L_8019C8E0
    if (ctx->r9 != 0) {
        // 0x8019C84C: nop
    
            goto L_8019C8E0;
    }
    // 0x8019C84C: nop

    // 0x8019C850: lui         $t2, 0x8011
    ctx->r10 = S32(0X8011 << 16);
    // 0x8019C854: lw          $t2, -0x4514($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4514);
    // 0x8019C858: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8019C85C: lui         $t4, 0xDE00
    ctx->r12 = S32(0XDE00 << 16);
    // 0x8019C860: sw          $t2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r10;
    // 0x8019C864: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x8019C868: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x8019C86C: sw          $t3, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r11;
    // 0x8019C870: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x8019C874: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8019C878: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8019C87C: addiu       $t6, $t6, -0x68E8
    ctx->r14 = ADD32(ctx->r14, -0X68E8);
    // 0x8019C880: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8019C884: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x8019C888: lwc1        $f4, -0x2B20($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2B20);
    // 0x8019C88C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8019C890: lwc1        $f6, -0x2B1C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2B1C);
    // 0x8019C894: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8019C898: lwc1        $f8, -0x2E30($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x8019C89C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019C8A0: lwc1        $f10, 0xC08($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0XC08);
    // 0x8019C8A4: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8019C8A8: addiu       $a2, $a2, -0x2BA8
    ctx->r6 = ADD32(ctx->r6, -0X2BA8);
    // 0x8019C8AC: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8019C8B0: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8019C8B4: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8019C8B8: lw          $a3, -0x2B24($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X2B24);
    // 0x8019C8BC: addiu       $a0, $a0, -0x31E0
    ctx->r4 = ADD32(ctx->r4, -0X31E0);
    // 0x8019C8C0: addiu       $a2, $a2, 0xA0
    ctx->r6 = ADD32(ctx->r6, 0XA0);
    // 0x8019C8C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8019C8C8: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x8019C8CC: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    // 0x8019C8D0: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x8019C8D4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8019C8D8: jal         0x800C6868
    // 0x8019C8DC: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_800C6868(rdram, ctx);
        goto after_0;
    // 0x8019C8DC: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_0:
L_8019C8E0:
    // 0x8019C8E0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8019C8E4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8019C8E8: jr          $ra
    // 0x8019C8EC: nop

    return;
    // 0x8019C8EC: nop

;}
RECOMP_FUNC void func_8019C8F0_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019C8F0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8019C8F4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8019C8F8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8019C8FC: addiu       $t6, $t6, -0x2E28
    ctx->r14 = ADD32(ctx->r14, -0X2E28);
    // 0x8019C900: lbu         $t7, 0x2($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X2);
    // 0x8019C904: andi        $t8, $t7, 0x80
    ctx->r24 = ctx->r15 & 0X80;
    // 0x8019C908: bne         $t8, $zero, L_8019CC78
    if (ctx->r24 != 0) {
        // 0x8019C90C: nop
    
            goto L_8019CC78;
    }
    // 0x8019C90C: nop

    // 0x8019C910: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8019C914: lhu         $t9, -0x2BA8($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X2BA8);
    // 0x8019C918: andi        $t0, $t9, 0x4000
    ctx->r8 = ctx->r25 & 0X4000;
    // 0x8019C91C: beq         $t0, $zero, L_8019CC78
    if (ctx->r8 == 0) {
        // 0x8019C920: nop
    
            goto L_8019CC78;
    }
    // 0x8019C920: nop

    // 0x8019C924: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8019C928: addiu       $t1, $t1, -0x2E28
    ctx->r9 = ADD32(ctx->r9, -0X2E28);
    // 0x8019C92C: lbu         $t2, 0xC($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0XC);
    // 0x8019C930: andi        $t3, $t2, 0x10
    ctx->r11 = ctx->r10 & 0X10;
    // 0x8019C934: bne         $t3, $zero, L_8019CC78
    if (ctx->r11 != 0) {
        // 0x8019C938: nop
    
            goto L_8019CC78;
    }
    // 0x8019C938: nop

    // 0x8019C93C: lui         $t4, 0x8011
    ctx->r12 = S32(0X8011 << 16);
    // 0x8019C940: lw          $t4, -0x4514($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4514);
    // 0x8019C944: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8019C948: lui         $t6, 0xDE00
    ctx->r14 = S32(0XDE00 << 16);
    // 0x8019C94C: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
    // 0x8019C950: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8019C954: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x8019C958: sw          $t5, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r13;
    // 0x8019C95C: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8019C960: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x8019C964: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x8019C968: addiu       $t8, $t8, -0x68E8
    ctx->r24 = ADD32(ctx->r24, -0X68E8);
    // 0x8019C96C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8019C970: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x8019C974: lwc1        $f4, -0x2B20($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2B20);
    // 0x8019C978: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8019C97C: lwc1        $f6, -0x2B1C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2B1C);
    // 0x8019C980: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8019C984: lwc1        $f8, -0x2E30($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x8019C988: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019C98C: lwc1        $f10, 0xC0C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0XC0C);
    // 0x8019C990: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8019C994: addiu       $a2, $a2, -0x2BA8
    ctx->r6 = ADD32(ctx->r6, -0X2BA8);
    // 0x8019C998: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8019C99C: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8019C9A0: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8019C9A4: lw          $a3, -0x2B24($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X2B24);
    // 0x8019C9A8: addiu       $a0, $a0, -0x31E0
    ctx->r4 = ADD32(ctx->r4, -0X31E0);
    // 0x8019C9AC: addiu       $a2, $a2, 0xA0
    ctx->r6 = ADD32(ctx->r6, 0XA0);
    // 0x8019C9B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8019C9B4: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x8019C9B8: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    // 0x8019C9BC: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x8019C9C0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8019C9C4: jal         0x800C6868
    // 0x8019C9C8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_800C6868(rdram, ctx);
        goto after_0;
    // 0x8019C9C8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x8019C9CC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019C9D0: lwc1        $f18, 0xC10($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0XC10);
    // 0x8019C9D4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8019C9D8: lwc1        $f4, -0x2E30($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x8019C9DC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019C9E0: lwc1        $f8, 0xC14($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0XC14);
    // 0x8019C9E4: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8019C9E8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019C9EC: lwc1        $f16, 0xC18($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0XC18);
    // 0x8019C9F0: mul.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8019C9F4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8019C9F8: addiu       $a0, $a0, -0x2BA8
    ctx->r4 = ADD32(ctx->r4, -0X2BA8);
    // 0x8019C9FC: mul.s       $f18, $f16, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x8019CA00: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8019CA04: addiu       $t0, $sp, 0x4C
    ctx->r8 = ADD32(ctx->r29, 0X4C);
    // 0x8019CA08: addiu       $t1, $sp, 0x48
    ctx->r9 = ADD32(ctx->r29, 0X48);
    // 0x8019CA0C: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8019CA10: addiu       $t2, $sp, 0x44
    ctx->r10 = ADD32(ctx->r29, 0X44);
    // 0x8019CA14: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x8019CA18: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x8019CA1C: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8019CA20: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8019CA24: jal         0x800D6E90
    // 0x8019CA28: addiu       $a0, $a0, 0xA0
    ctx->r4 = ADD32(ctx->r4, 0XA0);
    guMtxXFMF_recomp(rdram, ctx);
        goto after_1;
    // 0x8019CA28: addiu       $a0, $a0, 0xA0
    ctx->r4 = ADD32(ctx->r4, 0XA0);
    after_1:
    // 0x8019CA2C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019CA30: lwc1        $f6, 0xC1C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0XC1C);
    // 0x8019CA34: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8019CA38: lwc1        $f8, -0x2E30($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x8019CA3C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019CA40: lwc1        $f16, 0xC20($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0XC20);
    // 0x8019CA44: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8019CA48: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019CA4C: lwc1        $f18, 0xC24($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0XC24);
    // 0x8019CA50: mul.s       $f4, $f16, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x8019CA54: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8019CA58: addiu       $a0, $a0, -0x2BA8
    ctx->r4 = ADD32(ctx->r4, -0X2BA8);
    // 0x8019CA5C: mul.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x8019CA60: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8019CA64: addiu       $t3, $sp, 0x40
    ctx->r11 = ADD32(ctx->r29, 0X40);
    // 0x8019CA68: addiu       $t4, $sp, 0x3C
    ctx->r12 = ADD32(ctx->r29, 0X3C);
    // 0x8019CA6C: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8019CA70: addiu       $t5, $sp, 0x38
    ctx->r13 = ADD32(ctx->r29, 0X38);
    // 0x8019CA74: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x8019CA78: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x8019CA7C: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8019CA80: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8019CA84: jal         0x800D6E90
    // 0x8019CA88: addiu       $a0, $a0, 0xA0
    ctx->r4 = ADD32(ctx->r4, 0XA0);
    guMtxXFMF_recomp(rdram, ctx);
        goto after_2;
    // 0x8019CA88: addiu       $a0, $a0, 0xA0
    ctx->r4 = ADD32(ctx->r4, 0XA0);
    after_2:
    // 0x8019CA8C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8019CA90: lwc1        $f16, -0x2B24($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2B24);
    // 0x8019CA94: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8019CA98: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8019CA9C: lwc1        $f8, -0x2B20($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2B20);
    // 0x8019CAA0: add.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8019CAA4: lwc1        $f18, 0x48($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8019CAA8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8019CAAC: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8019CAB0: add.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x8019CAB4: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
    // 0x8019CAB8: lwc1        $f4, -0x2B1C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2B1C);
    // 0x8019CABC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8019CAC0: swc1        $f6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f6.u32l;
    // 0x8019CAC4: add.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8019CAC8: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8019CACC: lw          $t6, -0x2E34($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2E34);
    // 0x8019CAD0: add.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x8019CAD4: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    // 0x8019CAD8: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8019CADC: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8019CAE0: swc1        $f10, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f10.u32l;
    // 0x8019CAE4: add.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x8019CAE8: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x8019CAEC: add.s       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x8019CAF0: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    // 0x8019CAF4: beq         $t7, $zero, L_8019CBA4
    if (ctx->r15 == 0) {
        // 0x8019CAF8: swc1        $f10, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
            goto L_8019CBA4;
    }
    // 0x8019CAF8: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    // 0x8019CAFC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019CB00: lwc1        $f18, 0xC28($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0XC28);
    // 0x8019CB04: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8019CB08: lwc1        $f8, -0x2E30($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x8019CB0C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8019CB10: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x8019CB14: mul.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x8019CB18: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8019CB1C: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x8019CB20: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8019CB24: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8019CB28: addiu       $a0, $a0, -0x3218
    ctx->r4 = ADD32(ctx->r4, -0X3218);
    // 0x8019CB2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8019CB30: swc1        $f6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f6.u32l;
    // 0x8019CB34: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8019CB38: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    // 0x8019CB3C: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x8019CB40: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x8019CB44: lwc1        $f4, 0x0($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X0);
    // 0x8019CB48: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    // 0x8019CB4C: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x8019CB50: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x8019CB54: jal         0x800C6144
    // 0x8019CB58: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    func_800C6144(rdram, ctx);
        goto after_3;
    // 0x8019CB58: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x8019CB5C: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8019CB60: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8019CB64: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x8019CB68: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x8019CB6C: lwc1        $f8, 0x0($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8019CB70: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8019CB74: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8019CB78: addiu       $a0, $a0, -0x3218
    ctx->r4 = ADD32(ctx->r4, -0X3218);
    // 0x8019CB7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8019CB80: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x8019CB84: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x8019CB88: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x8019CB8C: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8019CB90: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x8019CB94: jal         0x800C6144
    // 0x8019CB98: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    func_800C6144(rdram, ctx);
        goto after_4;
    // 0x8019CB98: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    after_4:
    // 0x8019CB9C: b           L_8019CC44
    // 0x8019CBA0: nop

        goto L_8019CC44;
    // 0x8019CBA0: nop

L_8019CBA4:
    // 0x8019CBA4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019CBA8: lwc1        $f16, 0xC2C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0XC2C);
    // 0x8019CBAC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8019CBB0: lwc1        $f4, -0x2E30($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x8019CBB4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8019CBB8: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x8019CBBC: mul.s       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x8019CBC0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8019CBC4: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x8019CBC8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8019CBCC: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8019CBD0: addiu       $a0, $a0, -0x3250
    ctx->r4 = ADD32(ctx->r4, -0X3250);
    // 0x8019CBD4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8019CBD8: swc1        $f10, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f10.u32l;
    // 0x8019CBDC: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8019CBE0: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    // 0x8019CBE4: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x8019CBE8: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x8019CBEC: lwc1        $f8, 0x0($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X0);
    // 0x8019CBF0: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x8019CBF4: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x8019CBF8: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8019CBFC: jal         0x800C6144
    // 0x8019CC00: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    func_800C6144(rdram, ctx);
        goto after_5;
    // 0x8019CC00: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    after_5:
    // 0x8019CC04: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8019CC08: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8019CC0C: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x8019CC10: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x8019CC14: lwc1        $f4, 0x0($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X0);
    // 0x8019CC18: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8019CC1C: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8019CC20: addiu       $a0, $a0, -0x3250
    ctx->r4 = ADD32(ctx->r4, -0X3250);
    // 0x8019CC24: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8019CC28: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x8019CC2C: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x8019CC30: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x8019CC34: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x8019CC38: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x8019CC3C: jal         0x800C6144
    // 0x8019CC40: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    func_800C6144(rdram, ctx);
        goto after_6;
    // 0x8019CC40: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    after_6:
L_8019CC44:
    // 0x8019CC44: lui         $t4, 0x8011
    ctx->r12 = S32(0X8011 << 16);
    // 0x8019CC48: lw          $t4, -0x4514($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4514);
    // 0x8019CC4C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8019CC50: lui         $t6, 0xDE00
    ctx->r14 = S32(0XDE00 << 16);
    // 0x8019CC54: sw          $t4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r12;
    // 0x8019CC58: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8019CC5C: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x8019CC60: sw          $t5, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r13;
    // 0x8019CC64: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8019CC68: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x8019CC6C: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x8019CC70: addiu       $t8, $t8, -0x68E8
    ctx->r24 = ADD32(ctx->r24, -0X68E8);
    // 0x8019CC74: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
L_8019CC78:
    // 0x8019CC78: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8019CC7C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8019CC80: jr          $ra
    // 0x8019CC84: nop

    return;
    // 0x8019CC84: nop

;}
RECOMP_FUNC void func_8019CC88_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019CC88: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8019CC8C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8019CC90: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8019CC94: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8019CC98: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8019CC9C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8019CCA0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8019CCA4: addiu       $t6, $t6, -0x4198
    ctx->r14 = ADD32(ctx->r14, -0X4198);
    // 0x8019CCA8: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8019CCAC: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8019CCB0: lwc1        $f12, 0x0($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X0);
    // 0x8019CCB4: lwc1        $f14, 0x4($t6)
    ctx->f14.u32l = MEM_W(ctx->r14, 0X4);
    // 0x8019CCB8: lw          $a2, 0x8($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X8);
    // 0x8019CCBC: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x8019CCC0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8019CCC4: jal         0x8019BFE0
    // 0x8019CCC8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_8019BFE0_1501A0(rdram, ctx);
        goto after_0;
    // 0x8019CCC8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8019CCCC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8019CCD0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8019CCD4: addiu       $t8, $t8, -0x4198
    ctx->r24 = ADD32(ctx->r24, -0X4198);
    // 0x8019CCD8: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x8019CCDC: lwc1        $f8, 0x4($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X4);
    // 0x8019CCE0: lwc1        $f10, 0x28($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X28);
    // 0x8019CCE4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8019CCE8: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x8019CCEC: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8019CCF0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8019CCF4: swc1        $f16, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f16.u32l;
    // 0x8019CCF8: lwc1        $f18, 0xC($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0XC);
    // 0x8019CCFC: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x8019CD00: nop

    // 0x8019CD04: bc1f        L_8019CD1C
    if (!c1cs) {
        // 0x8019CD08: lui         $at, 0x43B4
        ctx->r1 = S32(0X43B4 << 16);
            goto L_8019CD1C;
    }
    // 0x8019CD08: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8019CD0C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019CD10: nop

    // 0x8019CD14: add.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8019CD18: swc1        $f8, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f8.u32l;
L_8019CD1C:
    // 0x8019CD1C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8019CD20: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x8019CD24: lw          $a1, 0x18($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X18);
    // 0x8019CD28: lw          $a2, 0xC($t0)
    ctx->r6 = MEM_W(ctx->r8, 0XC);
    // 0x8019CD2C: jal         0x800C85B0
    // 0x8019CD30: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_800C85B0(rdram, ctx);
        goto after_1;
    // 0x8019CD30: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x8019CD34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8019CD38: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8019CD3C: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8019CD40: jr          $ra
    // 0x8019CD44: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8019CD44: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8019CD48_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019CD48: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8019CD4C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8019CD50: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8019CD54: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8019CD58: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8019CD5C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8019CD60: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8019CD64: addiu       $t6, $t6, -0x4198
    ctx->r14 = ADD32(ctx->r14, -0X4198);
    // 0x8019CD68: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8019CD6C: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8019CD70: lwc1        $f12, 0x0($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X0);
    // 0x8019CD74: lwc1        $f14, 0x4($t6)
    ctx->f14.u32l = MEM_W(ctx->r14, 0X4);
    // 0x8019CD78: lw          $a2, 0x8($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X8);
    // 0x8019CD7C: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x8019CD80: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8019CD84: jal         0x8019BFE0
    // 0x8019CD88: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_8019BFE0_1501A0(rdram, ctx);
        goto after_0;
    // 0x8019CD88: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8019CD8C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8019CD90: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8019CD94: addiu       $t8, $t8, -0x4198
    ctx->r24 = ADD32(ctx->r24, -0X4198);
    // 0x8019CD98: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x8019CD9C: lwc1        $f8, 0x4($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X4);
    // 0x8019CDA0: lwc1        $f10, 0x28($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X28);
    // 0x8019CDA4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8019CDA8: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x8019CDAC: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8019CDB0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8019CDB4: swc1        $f16, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f16.u32l;
    // 0x8019CDB8: lwc1        $f18, 0xC($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0XC);
    // 0x8019CDBC: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x8019CDC0: nop

    // 0x8019CDC4: bc1f        L_8019CDDC
    if (!c1cs) {
        // 0x8019CDC8: lui         $at, 0x43B4
        ctx->r1 = S32(0X43B4 << 16);
            goto L_8019CDDC;
    }
    // 0x8019CDC8: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8019CDCC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019CDD0: nop

    // 0x8019CDD4: add.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8019CDD8: swc1        $f8, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f8.u32l;
L_8019CDDC:
    // 0x8019CDDC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8019CDE0: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x8019CDE4: lw          $a1, 0x18($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X18);
    // 0x8019CDE8: lw          $a2, 0xC($t0)
    ctx->r6 = MEM_W(ctx->r8, 0XC);
    // 0x8019CDEC: jal         0x800C81F8
    // 0x8019CDF0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800C81F8(rdram, ctx);
        goto after_1;
    // 0x8019CDF0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8019CDF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8019CDF8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8019CDFC: jr          $ra
    // 0x8019CE00: nop

    return;
    // 0x8019CE00: nop

;}
RECOMP_FUNC void func_8019CE04_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019CE04: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8019CE08: addiu       $t6, $zero, 0x14
    ctx->r14 = ADD32(0, 0X14);
    // 0x8019CE0C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8019CE10: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8019CE14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8019CE18: addiu       $t7, $t7, -0x2E28
    ctx->r15 = ADD32(ctx->r15, -0X2E28);
    // 0x8019CE1C: sw          $t6, -0x2E50($at)
    MEM_W(-0X2E50, ctx->r1) = ctx->r14;
    // 0x8019CE20: lbu         $t8, 0xA($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0XA);
    // 0x8019CE24: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8019CE28: addiu       $a0, $zero, 0x140
    ctx->r4 = ADD32(0, 0X140);
    // 0x8019CE2C: andi        $t9, $t8, 0xFD
    ctx->r25 = ctx->r24 & 0XFD;
    // 0x8019CE30: sb          $t9, 0xA($t7)
    MEM_B(0XA, ctx->r15) = ctx->r25;
    // 0x8019CE34: sw          $zero, -0x2E4C($at)
    MEM_W(-0X2E4C, ctx->r1) = 0;
    // 0x8019CE38: jal         0x800C3044
    // 0x8019CE3C: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    func_800C3044(rdram, ctx);
        goto after_0;
    // 0x8019CE3C: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    after_0:
    // 0x8019CE40: jal         0x800C328C
    // 0x8019CE44: nop

    func_800C328C(rdram, ctx);
        goto after_1;
    // 0x8019CE44: nop

    after_1:
    // 0x8019CE48: jal         0x8016D6F0
    // 0x8019CE4C: nop

    func_8016D6F0_1501A0(rdram, ctx);
        goto after_2;
    // 0x8019CE4C: nop

    after_2:
    // 0x8019CE50: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8019CE54: jal         0x800D1640
    // 0x8019CE58: addiu       $a0, $a0, -0x307C
    ctx->r4 = ADD32(ctx->r4, -0X307C);
    func_800D1640(rdram, ctx);
        goto after_3;
    // 0x8019CE58: addiu       $a0, $a0, -0x307C
    ctx->r4 = ADD32(ctx->r4, -0X307C);
    after_3:
L_8019CE5C:
    // 0x8019CE5C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8019CE60: addiu       $t0, $t0, -0x2E28
    ctx->r8 = ADD32(ctx->r8, -0X2E28);
    // 0x8019CE64: lbu         $t1, 0xE($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0XE);
    // 0x8019CE68: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x8019CE6C: beq         $t2, $zero, L_8019CF20
    if (ctx->r10 == 0) {
        // 0x8019CE70: nop
    
            goto L_8019CF20;
    }
    // 0x8019CE70: nop

    // 0x8019CE74: jal         0x800D1610
    // 0x8019CE78: nop

    func_800D1610(rdram, ctx);
        goto after_4;
    // 0x8019CE78: nop

    after_4:
    // 0x8019CE7C: jal         0x800D1640
    // 0x8019CE80: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800D1640(rdram, ctx);
        goto after_5;
    // 0x8019CE80: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
L_8019CE84:
    // 0x8019CE84: jal         0x801921B8
    // 0x8019CE88: nop

    func_801921B8_1501A0(rdram, ctx);
        goto after_6;
    // 0x8019CE88: nop

    after_6:
    // 0x8019CE8C: jal         0x80171A24
    // 0x8019CE90: nop

    func_80171A24_1501A0(rdram, ctx);
        goto after_7;
    // 0x8019CE90: nop

    after_7:
    // 0x8019CE94: jal         0x80172F74
    // 0x8019CE98: nop

    func_80172F74_1501A0(rdram, ctx);
        goto after_8;
    // 0x8019CE98: nop

    after_8:
    // 0x8019CE9C: jal         0x8017AEB4
    // 0x8019CEA0: nop

    func_8017AEB4_1501A0(rdram, ctx);
        goto after_9;
    // 0x8019CEA0: nop

    after_9:
    // 0x8019CEA4: jal         0x8019743C
    // 0x8019CEA8: nop

    func_8019743C_1501A0(rdram, ctx);
        goto after_10;
    // 0x8019CEA8: nop

    after_10:
    // 0x8019CEAC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8019CEB0: lw          $t3, -0x2E34($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2E34);
    // 0x8019CEB4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8019CEB8: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8019CEBC: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8019CEC0: sw          $t4, -0x2E34($at)
    MEM_W(-0X2E34, ctx->r1) = ctx->r12;
    // 0x8019CEC4: addiu       $t5, $t5, -0x2E18
    ctx->r13 = ADD32(ctx->r13, -0X2E18);
    // 0x8019CEC8: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x8019CECC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8019CED0: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x8019CED4: sw          $t8, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r24;
    // 0x8019CED8: lw          $t9, -0x2D68($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2D68);
    // 0x8019CEDC: bne         $t9, $zero, L_8019CE84
    if (ctx->r25 != 0) {
        // 0x8019CEE0: nop
    
            goto L_8019CE84;
    }
    // 0x8019CEE0: nop

    // 0x8019CEE4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8019CEE8: lhu         $t7, -0x2BA8($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X2BA8);
    // 0x8019CEEC: andi        $t0, $t7, 0x4000
    ctx->r8 = ctx->r15 & 0X4000;
    // 0x8019CEF0: bne         $t0, $zero, L_8019CE84
    if (ctx->r8 != 0) {
        // 0x8019CEF4: nop
    
            goto L_8019CE84;
    }
    // 0x8019CEF4: nop

    // 0x8019CEF8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8019CEFC: addiu       $t1, $t1, -0x2E28
    ctx->r9 = ADD32(ctx->r9, -0X2E28);
    // 0x8019CF00: lbu         $t2, 0xE($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0XE);
    // 0x8019CF04: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8019CF08: addiu       $a0, $a0, -0x307C
    ctx->r4 = ADD32(ctx->r4, -0X307C);
    // 0x8019CF0C: andi        $t3, $t2, 0xFE
    ctx->r11 = ctx->r10 & 0XFE;
    // 0x8019CF10: jal         0x800D1640
    // 0x8019CF14: sb          $t3, 0xE($t1)
    MEM_B(0XE, ctx->r9) = ctx->r11;
    func_800D1640(rdram, ctx);
        goto after_11;
    // 0x8019CF14: sb          $t3, 0xE($t1)
    MEM_B(0XE, ctx->r9) = ctx->r11;
    after_11:
    // 0x8019CF18: jal         0x800D1D00
    // 0x8019CF1C: nop

    func_800D1D00(rdram, ctx);
        goto after_12;
    // 0x8019CF1C: nop

    after_12:
L_8019CF20:
    // 0x8019CF20: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8019CF24: lw          $t4, -0x2E4C($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2E4C);
    // 0x8019CF28: beq         $t4, $zero, L_8019CE5C
    if (ctx->r12 == 0) {
        // 0x8019CF2C: nop
    
            goto L_8019CE5C;
    }
    // 0x8019CF2C: nop

    // 0x8019CF30: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x8019CF34: lhu         $t6, -0x4530($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X4530);
    // 0x8019CF38: andi        $t8, $t6, 0x2000
    ctx->r24 = ctx->r14 & 0X2000;
    // 0x8019CF3C: bne         $t8, $zero, L_8019CE5C
    if (ctx->r24 != 0) {
        // 0x8019CF40: nop
    
            goto L_8019CE5C;
    }
    // 0x8019CF40: nop

    // 0x8019CF44: jal         0x800CB720
    // 0x8019CF48: nop

    func_800CB720(rdram, ctx);
        goto after_13;
    // 0x8019CF48: nop

    after_13:
    // 0x8019CF4C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8019CF50: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x8019CF54: bne         $t5, $zero, L_8019CE5C
    if (ctx->r13 != 0) {
        // 0x8019CF58: nop
    
            goto L_8019CE5C;
    }
    // 0x8019CF58: nop

    // 0x8019CF5C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8019CF60: addiu       $t9, $t9, -0x2E28
    ctx->r25 = ADD32(ctx->r25, -0X2E28);
    // 0x8019CF64: lbu         $t7, 0xA($t9)
    ctx->r15 = MEM_BU(ctx->r25, 0XA);
    // 0x8019CF68: andi        $t0, $t7, 0xFE
    ctx->r8 = ctx->r15 & 0XFE;
    // 0x8019CF6C: jal         0x800D1680
    // 0x8019CF70: sb          $t0, 0xA($t9)
    MEM_B(0XA, ctx->r25) = ctx->r8;
    func_800D1680(rdram, ctx);
        goto after_14;
    // 0x8019CF70: sb          $t0, 0xA($t9)
    MEM_B(0XA, ctx->r25) = ctx->r8;
    after_14:
    // 0x8019CF74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8019CF78: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8019CF7C: jr          $ra
    // 0x8019CF80: nop

    return;
    // 0x8019CF80: nop

;}
RECOMP_FUNC void func_8019CF84_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019CF84: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8019CF88: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8019CF8C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8019CF90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8019CF94: bgtz        $t6, L_8019D0FC
    if (SIGNED(ctx->r14) > 0) {
        // 0x8019CF98: nop
    
            goto L_8019D0FC;
    }
    // 0x8019CF98: nop

    // 0x8019CF9C: jal         0x800C3704
    // 0x8019CFA0: nop

    func_800C3704(rdram, ctx);
        goto after_0;
    // 0x8019CFA0: nop

    after_0:
    // 0x8019CFA4: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x8019CFA8: lw          $t7, -0x4514($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4514);
    // 0x8019CFAC: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8019CFB0: lui         $t9, 0xDB06
    ctx->r25 = S32(0XDB06 << 16);
    // 0x8019CFB4: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x8019CFB8: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8019CFBC: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8019CFC0: sw          $t8, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r24;
    // 0x8019CFC4: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x8019CFC8: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8019CFCC: jal         0x800C7458
    // 0x8019CFD0: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    func_800C7458(rdram, ctx);
        goto after_1;
    // 0x8019CFD0: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    after_1:
    // 0x8019CFD4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8019CFD8: addiu       $t2, $t2, -0x2E28
    ctx->r10 = ADD32(ctx->r10, -0X2E28);
    // 0x8019CFDC: lbu         $t3, 0xA($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0XA);
    // 0x8019CFE0: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x8019CFE4: bne         $t4, $zero, L_8019D06C
    if (ctx->r12 != 0) {
        // 0x8019CFE8: nop
    
            goto L_8019D06C;
    }
    // 0x8019CFE8: nop

    // 0x8019CFEC: jal         0x801921B8
    // 0x8019CFF0: nop

    func_801921B8_1501A0(rdram, ctx);
        goto after_2;
    // 0x8019CFF0: nop

    after_2:
    // 0x8019CFF4: jal         0x801745A0
    // 0x8019CFF8: nop

    func_801745A0_1501A0(rdram, ctx);
        goto after_3;
    // 0x8019CFF8: nop

    after_3:
    // 0x8019CFFC: jal         0x8018AFAC
    // 0x8019D000: nop

    func_8018AFAC_1501A0(rdram, ctx);
        goto after_4;
    // 0x8019D000: nop

    after_4:
    // 0x8019D004: jal         0x801864BC
    // 0x8019D008: nop

    func_801864BC_1501A0(rdram, ctx);
        goto after_5;
    // 0x8019D008: nop

    after_5:
    // 0x8019D00C: jal         0x80171A24
    // 0x8019D010: nop

    func_80171A24_1501A0(rdram, ctx);
        goto after_6;
    // 0x8019D010: nop

    after_6:
    // 0x8019D014: jal         0x80172F74
    // 0x8019D018: nop

    func_80172F74_1501A0(rdram, ctx);
        goto after_7;
    // 0x8019D018: nop

    after_7:
    // 0x8019D01C: jal         0x8017AEB4
    // 0x8019D020: nop

    func_8017AEB4_1501A0(rdram, ctx);
        goto after_8;
    // 0x8019D020: nop

    after_8:
    // 0x8019D024: jal         0x8016DF5C
    // 0x8019D028: nop

    func_8016DF5C_1501A0(rdram, ctx);
        goto after_9;
    // 0x8019D028: nop

    after_9:
    // 0x8019D02C: jal         0x8019743C
    // 0x8019D030: nop

    func_8019743C_1501A0(rdram, ctx);
        goto after_10;
    // 0x8019D030: nop

    after_10:
    // 0x8019D034: jal         0x80176E40
    // 0x8019D038: nop

    func_80176E40_1501A0(rdram, ctx);
        goto after_11;
    // 0x8019D038: nop

    after_11:
    // 0x8019D03C: jal         0x8019D23C
    // 0x8019D040: nop

    func_8019D23C_1501A0(rdram, ctx);
        goto after_12;
    // 0x8019D040: nop

    after_12:
    // 0x8019D044: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8019D048: lw          $t5, -0x2E34($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2E34);
    // 0x8019D04C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8019D050: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8019D054: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8019D058: sw          $t6, -0x2E34($at)
    MEM_W(-0X2E34, ctx->r1) = ctx->r14;
    // 0x8019D05C: addiu       $t7, $t7, -0x2E18
    ctx->r15 = ADD32(ctx->r15, -0X2E18);
    // 0x8019D060: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8019D064: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8019D068: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
L_8019D06C:
    // 0x8019D06C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8019D070: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8019D074: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8019D078: lbu         $a2, -0x2C2D($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X2C2D);
    // 0x8019D07C: lbu         $a1, -0x2C2E($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X2C2E);
    // 0x8019D080: lbu         $a0, -0x2C2F($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X2C2F);
    // 0x8019D084: jal         0x800C25FC
    // 0x8019D088: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800C25FC(rdram, ctx);
        goto after_13;
    // 0x8019D088: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_13:
    // 0x8019D08C: jal         0x8019D10C
    // 0x8019D090: nop

    func_8019D10C_1501A0(rdram, ctx);
        goto after_14;
    // 0x8019D090: nop

    after_14:
    // 0x8019D094: jal         0x8018C4E8
    // 0x8019D098: nop

    func_8018C4E8_1501A0(rdram, ctx);
        goto after_15;
    // 0x8019D098: nop

    after_15:
    // 0x8019D09C: jal         0x800C3760
    // 0x8019D0A0: nop

    func_800C3760(rdram, ctx);
        goto after_16;
    // 0x8019D0A0: nop

    after_16:
    // 0x8019D0A4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8019D0A8: lw          $t0, -0x2E4C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2E4C);
    // 0x8019D0AC: beq         $t0, $zero, L_8019D0E8
    if (ctx->r8 == 0) {
        // 0x8019D0B0: nop
    
            goto L_8019D0E8;
    }
    // 0x8019D0B0: nop

    // 0x8019D0B4: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x8019D0B8: lhu         $t1, -0x4530($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X4530);
    // 0x8019D0BC: andi        $t2, $t1, 0x2000
    ctx->r10 = ctx->r9 & 0X2000;
    // 0x8019D0C0: bne         $t2, $zero, L_8019D0E8
    if (ctx->r10 != 0) {
        // 0x8019D0C4: nop
    
            goto L_8019D0E8;
    }
    // 0x8019D0C4: nop

    // 0x8019D0C8: jal         0x800CB720
    // 0x8019D0CC: nop

    func_800CB720(rdram, ctx);
        goto after_17;
    // 0x8019D0CC: nop

    after_17:
    // 0x8019D0D0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8019D0D4: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x8019D0D8: bne         $t3, $zero, L_8019D0E8
    if (ctx->r11 != 0) {
        // 0x8019D0DC: nop
    
            goto L_8019D0E8;
    }
    // 0x8019D0DC: nop

    // 0x8019D0E0: jal         0x800D1640
    // 0x8019D0E4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800D1640(rdram, ctx);
        goto after_18;
    // 0x8019D0E4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_18:
L_8019D0E8:
    // 0x8019D0E8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8019D0EC: addiu       $t4, $t4, -0x2E18
    ctx->r12 = ADD32(ctx->r12, -0X2E18);
    // 0x8019D0F0: lw          $t5, 0x40($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X40);
    // 0x8019D0F4: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8019D0F8: sw          $t6, 0x40($t4)
    MEM_W(0X40, ctx->r12) = ctx->r14;
L_8019D0FC:
    // 0x8019D0FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8019D100: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8019D104: jr          $ra
    // 0x8019D108: nop

    return;
    // 0x8019D108: nop

;}
RECOMP_FUNC void func_8019D10C_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019D10C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8019D110: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8019D114: jal         0x800C3578
    // 0x8019D118: nop

    func_800C3578(rdram, ctx);
        goto after_0;
    // 0x8019D118: nop

    after_0:
    // 0x8019D11C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8019D120: lw          $t6, -0x2E44($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2E44);
    // 0x8019D124: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8019D128: sltiu       $at, $t7, 0x6
    ctx->r1 = ctx->r15 < 0X6 ? 1 : 0;
    // 0x8019D12C: beq         $at, $zero, L_8019D1FC
    if (ctx->r1 == 0) {
        // 0x8019D130: nop
    
            goto L_8019D1FC;
    }
    // 0x8019D130: nop

    // 0x8019D134: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8019D138: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019D13C: addu        $at, $at, $t7
    gpr jr_addend_8019D144 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8019D140: lw          $t7, 0xC30($at)
    ctx->r15 = ADD32(ctx->r1, 0XC30);
    // 0x8019D144: jr          $t7
    // 0x8019D148: nop

    switch (jr_addend_8019D144 >> 2) {
        case 0: goto L_8019D14C; break;
        case 1: goto L_8019D16C; break;
        case 2: goto L_8019D18C; break;
        case 3: goto L_8019D1AC; break;
        case 4: goto L_8019D1C4; break;
        case 5: goto L_8019D1E4; break;
        default: switch_error(__func__, 0x8019D144, 0x801A0C30);
    }
    // 0x8019D148: nop

L_8019D14C:
    // 0x8019D14C: jal         0x801E4258
    // 0x8019D150: nop

    func_801E4258_1B66F0(rdram, ctx);
        goto after_1;
    // 0x8019D150: nop

    after_1:
    // 0x8019D154: jal         0x801E42A0
    // 0x8019D158: nop

    func_801E42A0_1B66F0(rdram, ctx);
        goto after_2;
    // 0x8019D158: nop

    after_2:
    // 0x8019D15C: jal         0x801D64D4
    // 0x8019D160: nop

    func_801D64D4_1B66F0(rdram, ctx);
        goto after_3;
    // 0x8019D160: nop

    after_3:
    // 0x8019D164: b           L_8019D1FC
    // 0x8019D168: nop

        goto L_8019D1FC;
    // 0x8019D168: nop

L_8019D16C:
    // 0x8019D16C: jal         0x801E94D4
    // 0x8019D170: nop

    func_801E94D4_255660(rdram, ctx);
        goto after_4;
    // 0x8019D170: nop

    after_4:
    // 0x8019D174: jal         0x801E3E90
    // 0x8019D178: nop

    func_801E3E90_255660(rdram, ctx);
        goto after_5;
    // 0x8019D178: nop

    after_5:
    // 0x8019D17C: jal         0x801D5784
    // 0x8019D180: nop

    func_801D5784_255660(rdram, ctx);
        goto after_6;
    // 0x8019D180: nop

    after_6:
    // 0x8019D184: b           L_8019D1FC
    // 0x8019D188: nop

        goto L_8019D1FC;
    // 0x8019D188: nop

L_8019D18C:
    // 0x8019D18C: jal         0x801E2DA0
    // 0x8019D190: nop

    func_801E2DA0_34B590(rdram, ctx);
        goto after_7;
    // 0x8019D190: nop

    after_7:
    // 0x8019D194: jal         0x801E2D24
    // 0x8019D198: nop

    func_801E2D24_34B590(rdram, ctx);
        goto after_8;
    // 0x8019D198: nop

    after_8:
    // 0x8019D19C: jal         0x801DF9F4
    // 0x8019D1A0: nop

    func_801DF9F4_34B590(rdram, ctx);
        goto after_9;
    // 0x8019D1A0: nop

    after_9:
    // 0x8019D1A4: b           L_8019D1FC
    // 0x8019D1A8: nop

        goto L_8019D1FC;
    // 0x8019D1A8: nop

L_8019D1AC:
    // 0x8019D1AC: jal         0x801DB6D0
    // 0x8019D1B0: nop

    func_801DB6D0_3EFDD0(rdram, ctx);
        goto after_10;
    // 0x8019D1B0: nop

    after_10:
    // 0x8019D1B4: jal         0x801DBBF0
    // 0x8019D1B8: nop

    func_801DBBF0_3EFDD0(rdram, ctx);
        goto after_11;
    // 0x8019D1B8: nop

    after_11:
    // 0x8019D1BC: b           L_8019D1FC
    // 0x8019D1C0: nop

        goto L_8019D1FC;
    // 0x8019D1C0: nop

L_8019D1C4:
    // 0x8019D1C4: jal         0x801D6044
    // 0x8019D1C8: nop

    func_801D6044_497140(rdram, ctx);
        goto after_12;
    // 0x8019D1C8: nop

    after_12:
    // 0x8019D1CC: jal         0x801D61F8
    // 0x8019D1D0: nop

    func_801D61F8_497140(rdram, ctx);
        goto after_13;
    // 0x8019D1D0: nop

    after_13:
    // 0x8019D1D4: jal         0x801D3178
    // 0x8019D1D8: nop

    func_801D3178_497140(rdram, ctx);
        goto after_14;
    // 0x8019D1D8: nop

    after_14:
    // 0x8019D1DC: b           L_8019D1FC
    // 0x8019D1E0: nop

        goto L_8019D1FC;
    // 0x8019D1E0: nop

L_8019D1E4:
    // 0x8019D1E4: jal         0x801DD2C0
    // 0x8019D1E8: nop

    func_801DD2C0_4DC6D0(rdram, ctx);
        goto after_15;
    // 0x8019D1E8: nop

    after_15:
    // 0x8019D1EC: jal         0x801DDA78
    // 0x8019D1F0: nop

    func_801DDA78_4DC6D0(rdram, ctx);
        goto after_16;
    // 0x8019D1F0: nop

    after_16:
    // 0x8019D1F4: jal         0x801D3BB0
    // 0x8019D1F8: nop

    func_801D3BB0_4DC6D0(rdram, ctx);
        goto after_17;
    // 0x8019D1F8: nop

    after_17:
L_8019D1FC:
    // 0x8019D1FC: jal         0x8019C8F0
    // 0x8019D200: nop

    func_8019C8F0_1501A0(rdram, ctx);
        goto after_18;
    // 0x8019D200: nop

    after_18:
    // 0x8019D204: jal         0x8019C818
    // 0x8019D208: nop

    func_8019C818_1501A0(rdram, ctx);
        goto after_19;
    // 0x8019D208: nop

    after_19:
    // 0x8019D20C: jal         0x8018F198
    // 0x8019D210: nop

    func_8018F198_1501A0(rdram, ctx);
        goto after_20;
    // 0x8019D210: nop

    after_20:
    // 0x8019D214: jal         0x8018F938
    // 0x8019D218: nop

    func_8018F938_1501A0(rdram, ctx);
        goto after_21;
    // 0x8019D218: nop

    after_21:
    // 0x8019D21C: jal         0x80175E00
    // 0x8019D220: nop

    func_80175E00_1501A0(rdram, ctx);
        goto after_22;
    // 0x8019D220: nop

    after_22:
    // 0x8019D224: jal         0x80175FB0
    // 0x8019D228: nop

    func_80175FB0_1501A0(rdram, ctx);
        goto after_23;
    // 0x8019D228: nop

    after_23:
    // 0x8019D22C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8019D230: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8019D234: jr          $ra
    // 0x8019D238: nop

    return;
    // 0x8019D238: nop

;}
RECOMP_FUNC void func_8019D23C_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019D23C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8019D240: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8019D244: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8019D248: lw          $s0, -0x2E44($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X2E44);
    // 0x8019D24C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8019D250: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8019D254: beq         $s0, $at, L_8019D274
    if (ctx->r16 == ctx->r1) {
        // 0x8019D258: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8019D274;
    }
    // 0x8019D258: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8019D25C: beq         $s0, $at, L_8019D284
    if (ctx->r16 == ctx->r1) {
        // 0x8019D260: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_8019D284;
    }
    // 0x8019D260: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8019D264: beq         $s0, $at, L_8019D294
    if (ctx->r16 == ctx->r1) {
        // 0x8019D268: nop
    
            goto L_8019D294;
    }
    // 0x8019D268: nop

    // 0x8019D26C: b           L_8019D29C
    // 0x8019D270: nop

        goto L_8019D29C;
    // 0x8019D270: nop

L_8019D274:
    // 0x8019D274: jal         0x801D54A4
    // 0x8019D278: nop

    func_801D54A4_255660(rdram, ctx);
        goto after_0;
    // 0x8019D278: nop

    after_0:
    // 0x8019D27C: b           L_8019D29C
    // 0x8019D280: nop

        goto L_8019D29C;
    // 0x8019D280: nop

L_8019D284:
    // 0x8019D284: jal         0x801D44E0
    // 0x8019D288: nop

    func_801D44E0_34B590(rdram, ctx);
        goto after_1;
    // 0x8019D288: nop

    after_1:
    // 0x8019D28C: b           L_8019D29C
    // 0x8019D290: nop

        goto L_8019D29C;
    // 0x8019D290: nop

L_8019D294:
    // 0x8019D294: jal         0x801D38F8
    // 0x8019D298: nop

    func_801D38F8_4DC6D0(rdram, ctx);
        goto after_2;
    // 0x8019D298: nop

    after_2:
L_8019D29C:
    // 0x8019D29C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8019D2A0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8019D2A4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8019D2A8: jr          $ra
    // 0x8019D2AC: nop

    return;
    // 0x8019D2AC: nop

;}
RECOMP_FUNC void func_801D21F0_1B66F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D21F0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801D21F4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801D21F8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801D21FC: addiu       $t6, $t6, -0x2E28
    ctx->r14 = ADD32(ctx->r14, -0X2E28);
    // 0x801D2200: sb          $zero, 0x1($t6)
    MEM_B(0X1, ctx->r14) = 0;
    // 0x801D2204: lui         $t7, 0x8020
    ctx->r15 = S32(0X8020 << 16);
    // 0x801D2208: lw          $t7, -0x1B14($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X1B14);
    // 0x801D220C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D2210: lui         $t8, 0x8020
    ctx->r24 = S32(0X8020 << 16);
    // 0x801D2214: swc1        $f4, -0x2E30($at)
    MEM_W(-0X2E30, ctx->r1) = ctx->f4.u32l;
    // 0x801D2218: lw          $t8, -0x1B10($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X1B10);
    // 0x801D221C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D2220: lui         $t9, 0x8020
    ctx->r25 = S32(0X8020 << 16);
    // 0x801D2224: sw          $t7, -0x2BB8($at)
    MEM_W(-0X2BB8, ctx->r1) = ctx->r15;
    // 0x801D2228: lw          $t9, -0x1B0C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X1B0C);
    // 0x801D222C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D2230: lui         $t0, 0x8020
    ctx->r8 = S32(0X8020 << 16);
    // 0x801D2234: sw          $t8, -0x2BB0($at)
    MEM_W(-0X2BB0, ctx->r1) = ctx->r24;
    // 0x801D2238: lw          $t0, -0x1B08($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X1B08);
    // 0x801D223C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D2240: lui         $t1, 0x8020
    ctx->r9 = S32(0X8020 << 16);
    // 0x801D2244: sw          $t9, -0x2BB4($at)
    MEM_W(-0X2BB4, ctx->r1) = ctx->r25;
    // 0x801D2248: lw          $t1, -0x1B04($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X1B04);
    // 0x801D224C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D2250: sw          $t0, -0x2AC8($at)
    MEM_W(-0X2AC8, ctx->r1) = ctx->r8;
    // 0x801D2254: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D2258: lui         $t2, 0x8020
    ctx->r10 = S32(0X8020 << 16);
    // 0x801D225C: sw          $t1, -0x2AC4($at)
    MEM_W(-0X2AC4, ctx->r1) = ctx->r9;
    // 0x801D2260: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D2264: addiu       $t2, $t2, -0x1B00
    ctx->r10 = ADD32(ctx->r10, -0X1B00);
    // 0x801D2268: jr          $ra
    // 0x801D226C: sw          $t2, -0x2D90($at)
    MEM_W(-0X2D90, ctx->r1) = ctx->r10;
    return;
    // 0x801D226C: sw          $t2, -0x2D90($at)
    MEM_W(-0X2D90, ctx->r1) = ctx->r10;
;}
RECOMP_FUNC void func_801D2270_1B66F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D2270: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801D2274: lhu         $t6, -0x2D84($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X2D84);
    // 0x801D2278: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801D227C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D2280: addiu       $t7, $t6, -0x1100
    ctx->r15 = ADD32(ctx->r14, -0X1100);
    // 0x801D2284: sltiu       $at, $t7, 0xC
    ctx->r1 = ctx->r15 < 0XC ? 1 : 0;
    // 0x801D2288: beq         $at, $zero, L_801D2390
    if (ctx->r1 == 0) {
        // 0x801D228C: nop
    
            goto L_801D2390;
    }
    // 0x801D228C: nop

    // 0x801D2290: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801D2294: lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // 0x801D2298: addu        $at, $at, $t7
    gpr jr_addend_801D22A0 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x801D229C: lw          $t7, -0x7CA0($at)
    ctx->r15 = ADD32(ctx->r1, -0X7CA0);
    // 0x801D22A0: jr          $t7
    // 0x801D22A4: nop

    switch (jr_addend_801D22A0 >> 2) {
        case 0: goto L_801D22A8; break;
        case 1: goto L_801D22BC; break;
        case 2: goto L_801D22D0; break;
        case 3: goto L_801D22E4; break;
        case 4: goto L_801D22F8; break;
        case 5: goto L_801D230C; break;
        case 6: goto L_801D2320; break;
        case 7: goto L_801D2334; break;
        case 8: goto L_801D2348; break;
        case 9: goto L_801D235C; break;
        case 10: goto L_801D2370; break;
        case 11: goto L_801D2384; break;
        default: switch_error(__func__, 0x801D22A0, 0x801E8360);
    }
    // 0x801D22A4: nop

L_801D22A8:
    // 0x801D22A8: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D22AC: jal         0x80192CA0
    // 0x801D22B0: addiu       $a0, $a0, 0x68C0
    ctx->r4 = ADD32(ctx->r4, 0X68C0);
    func_80192CA0_1501A0(rdram, ctx);
        goto after_0;
    // 0x801D22B0: addiu       $a0, $a0, 0x68C0
    ctx->r4 = ADD32(ctx->r4, 0X68C0);
    after_0:
    // 0x801D22B4: b           L_801D2390
    // 0x801D22B8: nop

        goto L_801D2390;
    // 0x801D22B8: nop

L_801D22BC:
    // 0x801D22BC: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D22C0: jal         0x80192CA0
    // 0x801D22C4: addiu       $a0, $a0, 0x68CC
    ctx->r4 = ADD32(ctx->r4, 0X68CC);
    func_80192CA0_1501A0(rdram, ctx);
        goto after_1;
    // 0x801D22C4: addiu       $a0, $a0, 0x68CC
    ctx->r4 = ADD32(ctx->r4, 0X68CC);
    after_1:
    // 0x801D22C8: b           L_801D2390
    // 0x801D22CC: nop

        goto L_801D2390;
    // 0x801D22CC: nop

L_801D22D0:
    // 0x801D22D0: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D22D4: jal         0x80192CA0
    // 0x801D22D8: addiu       $a0, $a0, 0x68D8
    ctx->r4 = ADD32(ctx->r4, 0X68D8);
    func_80192CA0_1501A0(rdram, ctx);
        goto after_2;
    // 0x801D22D8: addiu       $a0, $a0, 0x68D8
    ctx->r4 = ADD32(ctx->r4, 0X68D8);
    after_2:
    // 0x801D22DC: b           L_801D2390
    // 0x801D22E0: nop

        goto L_801D2390;
    // 0x801D22E0: nop

L_801D22E4:
    // 0x801D22E4: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D22E8: jal         0x80192CA0
    // 0x801D22EC: addiu       $a0, $a0, 0x68E4
    ctx->r4 = ADD32(ctx->r4, 0X68E4);
    func_80192CA0_1501A0(rdram, ctx);
        goto after_3;
    // 0x801D22EC: addiu       $a0, $a0, 0x68E4
    ctx->r4 = ADD32(ctx->r4, 0X68E4);
    after_3:
    // 0x801D22F0: b           L_801D2390
    // 0x801D22F4: nop

        goto L_801D2390;
    // 0x801D22F4: nop

L_801D22F8:
    // 0x801D22F8: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D22FC: jal         0x80192CA0
    // 0x801D2300: addiu       $a0, $a0, 0x68F0
    ctx->r4 = ADD32(ctx->r4, 0X68F0);
    func_80192CA0_1501A0(rdram, ctx);
        goto after_4;
    // 0x801D2300: addiu       $a0, $a0, 0x68F0
    ctx->r4 = ADD32(ctx->r4, 0X68F0);
    after_4:
    // 0x801D2304: b           L_801D2390
    // 0x801D2308: nop

        goto L_801D2390;
    // 0x801D2308: nop

L_801D230C:
    // 0x801D230C: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D2310: jal         0x80192CA0
    // 0x801D2314: addiu       $a0, $a0, 0x68FC
    ctx->r4 = ADD32(ctx->r4, 0X68FC);
    func_80192CA0_1501A0(rdram, ctx);
        goto after_5;
    // 0x801D2314: addiu       $a0, $a0, 0x68FC
    ctx->r4 = ADD32(ctx->r4, 0X68FC);
    after_5:
    // 0x801D2318: b           L_801D2390
    // 0x801D231C: nop

        goto L_801D2390;
    // 0x801D231C: nop

L_801D2320:
    // 0x801D2320: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D2324: jal         0x80192CA0
    // 0x801D2328: addiu       $a0, $a0, 0x6908
    ctx->r4 = ADD32(ctx->r4, 0X6908);
    func_80192CA0_1501A0(rdram, ctx);
        goto after_6;
    // 0x801D2328: addiu       $a0, $a0, 0x6908
    ctx->r4 = ADD32(ctx->r4, 0X6908);
    after_6:
    // 0x801D232C: b           L_801D2390
    // 0x801D2330: nop

        goto L_801D2390;
    // 0x801D2330: nop

L_801D2334:
    // 0x801D2334: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D2338: jal         0x80192CA0
    // 0x801D233C: addiu       $a0, $a0, 0x6914
    ctx->r4 = ADD32(ctx->r4, 0X6914);
    func_80192CA0_1501A0(rdram, ctx);
        goto after_7;
    // 0x801D233C: addiu       $a0, $a0, 0x6914
    ctx->r4 = ADD32(ctx->r4, 0X6914);
    after_7:
    // 0x801D2340: b           L_801D2390
    // 0x801D2344: nop

        goto L_801D2390;
    // 0x801D2344: nop

L_801D2348:
    // 0x801D2348: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D234C: jal         0x80192CA0
    // 0x801D2350: addiu       $a0, $a0, 0x68D8
    ctx->r4 = ADD32(ctx->r4, 0X68D8);
    func_80192CA0_1501A0(rdram, ctx);
        goto after_8;
    // 0x801D2350: addiu       $a0, $a0, 0x68D8
    ctx->r4 = ADD32(ctx->r4, 0X68D8);
    after_8:
    // 0x801D2354: b           L_801D2390
    // 0x801D2358: nop

        goto L_801D2390;
    // 0x801D2358: nop

L_801D235C:
    // 0x801D235C: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D2360: jal         0x80192CA0
    // 0x801D2364: addiu       $a0, $a0, 0x68D8
    ctx->r4 = ADD32(ctx->r4, 0X68D8);
    func_80192CA0_1501A0(rdram, ctx);
        goto after_9;
    // 0x801D2364: addiu       $a0, $a0, 0x68D8
    ctx->r4 = ADD32(ctx->r4, 0X68D8);
    after_9:
    // 0x801D2368: b           L_801D2390
    // 0x801D236C: nop

        goto L_801D2390;
    // 0x801D236C: nop

L_801D2370:
    // 0x801D2370: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D2374: jal         0x80192CA0
    // 0x801D2378: addiu       $a0, $a0, 0x6908
    ctx->r4 = ADD32(ctx->r4, 0X6908);
    func_80192CA0_1501A0(rdram, ctx);
        goto after_10;
    // 0x801D2378: addiu       $a0, $a0, 0x6908
    ctx->r4 = ADD32(ctx->r4, 0X6908);
    after_10:
    // 0x801D237C: b           L_801D2390
    // 0x801D2380: nop

        goto L_801D2390;
    // 0x801D2380: nop

L_801D2384:
    // 0x801D2384: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D2388: jal         0x80192CA0
    // 0x801D238C: addiu       $a0, $a0, 0x6914
    ctx->r4 = ADD32(ctx->r4, 0X6914);
    func_80192CA0_1501A0(rdram, ctx);
        goto after_11;
    // 0x801D238C: addiu       $a0, $a0, 0x6914
    ctx->r4 = ADD32(ctx->r4, 0X6914);
    after_11:
L_801D2390:
    // 0x801D2390: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801D2394: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801D2398: jr          $ra
    // 0x801D239C: nop

    return;
    // 0x801D239C: nop

;}
RECOMP_FUNC void func_801D23A0_1B66F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D23A0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801D23A4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801D23A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801D23AC: lhu         $s0, 0x2A($sp)
    ctx->r16 = MEM_HU(ctx->r29, 0X2A);
    // 0x801D23B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801D23B4: slti        $at, $s0, 0x1201
    ctx->r1 = SIGNED(ctx->r16) < 0X1201 ? 1 : 0;
    // 0x801D23B8: bne         $at, $zero, L_801D2468
    if (ctx->r1 != 0) {
        // 0x801D23BC: slti        $at, $s0, 0x127A
        ctx->r1 = SIGNED(ctx->r16) < 0X127A ? 1 : 0;
            goto L_801D2468;
    }
    // 0x801D23BC: slti        $at, $s0, 0x127A
    ctx->r1 = SIGNED(ctx->r16) < 0X127A ? 1 : 0;
    // 0x801D23C0: bne         $at, $zero, L_801D2420
    if (ctx->r1 != 0) {
        // 0x801D23C4: slti        $at, $s0, 0x1327
        ctx->r1 = SIGNED(ctx->r16) < 0X1327 ? 1 : 0;
            goto L_801D2420;
    }
    // 0x801D23C4: slti        $at, $s0, 0x1327
    ctx->r1 = SIGNED(ctx->r16) < 0X1327 ? 1 : 0;
    // 0x801D23C8: bne         $at, $zero, L_801D23F8
    if (ctx->r1 != 0) {
        // 0x801D23CC: nop
    
            goto L_801D23F8;
    }
    // 0x801D23CC: nop

    // 0x801D23D0: addiu       $t6, $s0, -0x1500
    ctx->r14 = ADD32(ctx->r16, -0X1500);
    // 0x801D23D4: sltiu       $at, $t6, 0x16
    ctx->r1 = ctx->r14 < 0X16 ? 1 : 0;
    // 0x801D23D8: beq         $at, $zero, L_801D36BC
    if (ctx->r1 == 0) {
        // 0x801D23DC: nop
    
            goto L_801D36BC;
    }
    // 0x801D23DC: nop

    // 0x801D23E0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801D23E4: lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // 0x801D23E8: addu        $at, $at, $t6
    gpr jr_addend_801D23F0 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x801D23EC: lw          $t6, -0x7C70($at)
    ctx->r14 = ADD32(ctx->r1, -0X7C70);
    // 0x801D23F0: jr          $t6
    // 0x801D23F4: nop

    switch (jr_addend_801D23F0 >> 2) {
        case 0: goto L_801D24F0; break;
        case 1: goto L_801D2500; break;
        case 2: goto L_801D2510; break;
        case 3: goto L_801D2520; break;
        case 4: goto L_801D2530; break;
        case 5: goto L_801D36BC; break;
        case 6: goto L_801D36BC; break;
        case 7: goto L_801D36BC; break;
        case 8: goto L_801D36BC; break;
        case 9: goto L_801D36BC; break;
        case 10: goto L_801D36BC; break;
        case 11: goto L_801D36BC; break;
        case 12: goto L_801D36BC; break;
        case 13: goto L_801D36BC; break;
        case 14: goto L_801D36BC; break;
        case 15: goto L_801D36BC; break;
        case 16: goto L_801D2540; break;
        case 17: goto L_801D2550; break;
        case 18: goto L_801D2560; break;
        case 19: goto L_801D2570; break;
        case 20: goto L_801D2580; break;
        case 21: goto L_801D2590; break;
        default: switch_error(__func__, 0x801D23F0, 0x801E8390);
    }
    // 0x801D23F4: nop

L_801D23F8:
    // 0x801D23F8: addiu       $t7, $s0, -0x1300
    ctx->r15 = ADD32(ctx->r16, -0X1300);
    // 0x801D23FC: sltiu       $at, $t7, 0x27
    ctx->r1 = ctx->r15 < 0X27 ? 1 : 0;
    // 0x801D2400: beq         $at, $zero, L_801D36BC
    if (ctx->r1 == 0) {
        // 0x801D2404: nop
    
            goto L_801D36BC;
    }
    // 0x801D2404: nop

    // 0x801D2408: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801D240C: lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // 0x801D2410: addu        $at, $at, $t7
    gpr jr_addend_801D2418 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x801D2414: lw          $t7, -0x7C18($at)
    ctx->r15 = ADD32(ctx->r1, -0X7C18);
    // 0x801D2418: jr          $t7
    // 0x801D241C: nop

    switch (jr_addend_801D2418 >> 2) {
        case 0: goto L_801D2780; break;
        case 1: goto L_801D2794; break;
        case 2: goto L_801D27A8; break;
        case 3: goto L_801D27BC; break;
        case 4: goto L_801D27D0; break;
        case 5: goto L_801D36BC; break;
        case 6: goto L_801D36BC; break;
        case 7: goto L_801D36BC; break;
        case 8: goto L_801D36BC; break;
        case 9: goto L_801D36BC; break;
        case 10: goto L_801D36BC; break;
        case 11: goto L_801D36BC; break;
        case 12: goto L_801D36BC; break;
        case 13: goto L_801D36BC; break;
        case 14: goto L_801D36BC; break;
        case 15: goto L_801D36BC; break;
        case 16: goto L_801D27E4; break;
        case 17: goto L_801D27F8; break;
        case 18: goto L_801D280C; break;
        case 19: goto L_801D36BC; break;
        case 20: goto L_801D36BC; break;
        case 21: goto L_801D36BC; break;
        case 22: goto L_801D36BC; break;
        case 23: goto L_801D36BC; break;
        case 24: goto L_801D36BC; break;
        case 25: goto L_801D36BC; break;
        case 26: goto L_801D36BC; break;
        case 27: goto L_801D36BC; break;
        case 28: goto L_801D36BC; break;
        case 29: goto L_801D36BC; break;
        case 30: goto L_801D36BC; break;
        case 31: goto L_801D36BC; break;
        case 32: goto L_801D2838; break;
        case 33: goto L_801D284C; break;
        case 34: goto L_801D2860; break;
        case 35: goto L_801D2874; break;
        case 36: goto L_801D2888; break;
        case 37: goto L_801D289C; break;
        case 38: goto L_801D28B0; break;
        default: switch_error(__func__, 0x801D2418, 0x801E83E8);
    }
    // 0x801D241C: nop

L_801D2420:
    // 0x801D2420: slti        $at, $s0, 0x1202
    ctx->r1 = SIGNED(ctx->r16) < 0X1202 ? 1 : 0;
    // 0x801D2424: bne         $at, $zero, L_801D2454
    if (ctx->r1 != 0) {
        // 0x801D2428: nop
    
            goto L_801D2454;
    }
    // 0x801D2428: nop

    // 0x801D242C: addiu       $t8, $s0, -0x1250
    ctx->r24 = ADD32(ctx->r16, -0X1250);
    // 0x801D2430: sltiu       $at, $t8, 0x2A
    ctx->r1 = ctx->r24 < 0X2A ? 1 : 0;
    // 0x801D2434: beq         $at, $zero, L_801D36BC
    if (ctx->r1 == 0) {
        // 0x801D2438: nop
    
            goto L_801D36BC;
    }
    // 0x801D2438: nop

    // 0x801D243C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x801D2440: lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // 0x801D2444: addu        $at, $at, $t8
    gpr jr_addend_801D244C = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x801D2448: lw          $t8, -0x7B7C($at)
    ctx->r24 = ADD32(ctx->r1, -0X7B7C);
    // 0x801D244C: jr          $t8
    // 0x801D2450: nop

    switch (jr_addend_801D244C >> 2) {
        case 0: goto L_801D29E4; break;
        case 1: goto L_801D2B24; break;
        case 2: goto L_801D2C64; break;
        case 3: goto L_801D36BC; break;
        case 4: goto L_801D30FC; break;
        case 5: goto L_801D2ECC; break;
        case 6: goto L_801D3070; break;
        case 7: goto L_801D2F58; break;
        case 8: goto L_801D2FE4; break;
        case 9: goto L_801D3188; break;
        case 10: goto L_801D36BC; break;
        case 11: goto L_801D36BC; break;
        case 12: goto L_801D36BC; break;
        case 13: goto L_801D36BC; break;
        case 14: goto L_801D36BC; break;
        case 15: goto L_801D36BC; break;
        case 16: goto L_801D36BC; break;
        case 17: goto L_801D36BC; break;
        case 18: goto L_801D36BC; break;
        case 19: goto L_801D36BC; break;
        case 20: goto L_801D36BC; break;
        case 21: goto L_801D36BC; break;
        case 22: goto L_801D36BC; break;
        case 23: goto L_801D36BC; break;
        case 24: goto L_801D36BC; break;
        case 25: goto L_801D36BC; break;
        case 26: goto L_801D36BC; break;
        case 27: goto L_801D36BC; break;
        case 28: goto L_801D36BC; break;
        case 29: goto L_801D36BC; break;
        case 30: goto L_801D36BC; break;
        case 31: goto L_801D36BC; break;
        case 32: goto L_801D3214; break;
        case 33: goto L_801D328C; break;
        case 34: goto L_801D3304; break;
        case 35: goto L_801D337C; break;
        case 36: goto L_801D33F4; break;
        case 37: goto L_801D346C; break;
        case 38: goto L_801D34E4; break;
        case 39: goto L_801D355C; break;
        case 40: goto L_801D35D4; break;
        case 41: goto L_801D364C; break;
        default: switch_error(__func__, 0x801D244C, 0x801E8484);
    }
    // 0x801D2450: nop

L_801D2454:
    // 0x801D2454: addiu       $at, $zero, 0x1201
    ctx->r1 = ADD32(0, 0X1201);
    // 0x801D2458: beq         $s0, $at, L_801D2954
    if (ctx->r16 == ctx->r1) {
        // 0x801D245C: nop
    
            goto L_801D2954;
    }
    // 0x801D245C: nop

    // 0x801D2460: b           L_801D36BC
    // 0x801D2464: nop

        goto L_801D36BC;
    // 0x801D2464: nop

L_801D2468:
    // 0x801D2468: slti        $at, $s0, 0x1003
    ctx->r1 = SIGNED(ctx->r16) < 0X1003 ? 1 : 0;
    // 0x801D246C: bne         $at, $zero, L_801D24B4
    if (ctx->r1 != 0) {
        // 0x801D2470: slti        $at, $s0, 0x110C
        ctx->r1 = SIGNED(ctx->r16) < 0X110C ? 1 : 0;
            goto L_801D24B4;
    }
    // 0x801D2470: slti        $at, $s0, 0x110C
    ctx->r1 = SIGNED(ctx->r16) < 0X110C ? 1 : 0;
    // 0x801D2474: bne         $at, $zero, L_801D248C
    if (ctx->r1 != 0) {
        // 0x801D2478: addiu       $at, $zero, 0x1200
        ctx->r1 = ADD32(0, 0X1200);
            goto L_801D248C;
    }
    // 0x801D2478: addiu       $at, $zero, 0x1200
    ctx->r1 = ADD32(0, 0X1200);
    // 0x801D247C: beq         $s0, $at, L_801D28C4
    if (ctx->r16 == ctx->r1) {
        // 0x801D2480: nop
    
            goto L_801D28C4;
    }
    // 0x801D2480: nop

    // 0x801D2484: b           L_801D36BC
    // 0x801D2488: nop

        goto L_801D36BC;
    // 0x801D2488: nop

L_801D248C:
    // 0x801D248C: addiu       $t9, $s0, -0x1100
    ctx->r25 = ADD32(ctx->r16, -0X1100);
    // 0x801D2490: sltiu       $at, $t9, 0xC
    ctx->r1 = ctx->r25 < 0XC ? 1 : 0;
    // 0x801D2494: beq         $at, $zero, L_801D36BC
    if (ctx->r1 == 0) {
        // 0x801D2498: nop
    
            goto L_801D36BC;
    }
    // 0x801D2498: nop

    // 0x801D249C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x801D24A0: lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // 0x801D24A4: addu        $at, $at, $t9
    gpr jr_addend_801D24AC = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x801D24A8: lw          $t9, -0x7AD4($at)
    ctx->r25 = ADD32(ctx->r1, -0X7AD4);
    // 0x801D24AC: jr          $t9
    // 0x801D24B0: nop

    switch (jr_addend_801D24AC >> 2) {
        case 0: goto L_801D25A0; break;
        case 1: goto L_801D25C8; break;
        case 2: goto L_801D25F0; break;
        case 3: goto L_801D2618; break;
        case 4: goto L_801D2640; break;
        case 5: goto L_801D2668; break;
        case 6: goto L_801D2690; break;
        case 7: goto L_801D26B8; break;
        case 8: goto L_801D26E0; break;
        case 9: goto L_801D2708; break;
        case 10: goto L_801D2730; break;
        case 11: goto L_801D2758; break;
        default: switch_error(__func__, 0x801D24AC, 0x801E852C);
    }
    // 0x801D24B0: nop

L_801D24B4:
    // 0x801D24B4: addiu       $at, $zero, 0x1000
    ctx->r1 = ADD32(0, 0X1000);
    // 0x801D24B8: beq         $s0, $at, L_801D24D0
    if (ctx->r16 == ctx->r1) {
        // 0x801D24BC: addiu       $at, $zero, 0x1001
        ctx->r1 = ADD32(0, 0X1001);
            goto L_801D24D0;
    }
    // 0x801D24BC: addiu       $at, $zero, 0x1001
    ctx->r1 = ADD32(0, 0X1001);
    // 0x801D24C0: beq         $s0, $at, L_801D24D0
    if (ctx->r16 == ctx->r1) {
        // 0x801D24C4: addiu       $at, $zero, 0x1002
        ctx->r1 = ADD32(0, 0X1002);
            goto L_801D24D0;
    }
    // 0x801D24C4: addiu       $at, $zero, 0x1002
    ctx->r1 = ADD32(0, 0X1002);
    // 0x801D24C8: bne         $s0, $at, L_801D36BC
    if (ctx->r16 != ctx->r1) {
        // 0x801D24CC: nop
    
            goto L_801D36BC;
    }
    // 0x801D24CC: nop

L_801D24D0:
    // 0x801D24D0: lhu         $t0, 0x2A($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X2A);
    // 0x801D24D4: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801D24D8: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x801D24DC: addu        $a0, $a0, $t1
    ctx->r4 = ADD32(ctx->r4, ctx->r9);
    // 0x801D24E0: jal         0x801972A8
    // 0x801D24E4: lw          $a0, 0x4FF0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4FF0);
    func_801972A8_1501A0(rdram, ctx);
        goto after_0;
    // 0x801D24E4: lw          $a0, 0x4FF0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4FF0);
    after_0:
    // 0x801D24E8: b           L_801D36BC
    // 0x801D24EC: nop

        goto L_801D36BC;
    // 0x801D24EC: nop

L_801D24F0:
    // 0x801D24F0: jal         0x800C992C
    // 0x801D24F4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800C992C(rdram, ctx);
        goto after_1;
    // 0x801D24F4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x801D24F8: b           L_801D36BC
    // 0x801D24FC: nop

        goto L_801D36BC;
    // 0x801D24FC: nop

L_801D2500:
    // 0x801D2500: jal         0x800C992C
    // 0x801D2504: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_800C992C(rdram, ctx);
        goto after_2;
    // 0x801D2504: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_2:
    // 0x801D2508: b           L_801D36BC
    // 0x801D250C: nop

        goto L_801D36BC;
    // 0x801D250C: nop

L_801D2510:
    // 0x801D2510: jal         0x800C992C
    // 0x801D2514: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_800C992C(rdram, ctx);
        goto after_3;
    // 0x801D2514: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_3:
    // 0x801D2518: b           L_801D36BC
    // 0x801D251C: nop

        goto L_801D36BC;
    // 0x801D251C: nop

L_801D2520:
    // 0x801D2520: jal         0x800C992C
    // 0x801D2524: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    func_800C992C(rdram, ctx);
        goto after_4;
    // 0x801D2524: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_4:
    // 0x801D2528: b           L_801D36BC
    // 0x801D252C: nop

        goto L_801D36BC;
    // 0x801D252C: nop

L_801D2530:
    // 0x801D2530: jal         0x800C992C
    // 0x801D2534: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    func_800C992C(rdram, ctx);
        goto after_5;
    // 0x801D2534: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_5:
    // 0x801D2538: b           L_801D36BC
    // 0x801D253C: nop

        goto L_801D36BC;
    // 0x801D253C: nop

L_801D2540:
    // 0x801D2540: jal         0x800C992C
    // 0x801D2544: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    func_800C992C(rdram, ctx);
        goto after_6;
    // 0x801D2544: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    after_6:
    // 0x801D2548: b           L_801D36BC
    // 0x801D254C: nop

        goto L_801D36BC;
    // 0x801D254C: nop

L_801D2550:
    // 0x801D2550: jal         0x800C992C
    // 0x801D2554: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    func_800C992C(rdram, ctx);
        goto after_7;
    // 0x801D2554: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    after_7:
    // 0x801D2558: b           L_801D36BC
    // 0x801D255C: nop

        goto L_801D36BC;
    // 0x801D255C: nop

L_801D2560:
    // 0x801D2560: jal         0x800C992C
    // 0x801D2564: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    func_800C992C(rdram, ctx);
        goto after_8;
    // 0x801D2564: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_8:
    // 0x801D2568: b           L_801D36BC
    // 0x801D256C: nop

        goto L_801D36BC;
    // 0x801D256C: nop

L_801D2570:
    // 0x801D2570: jal         0x800C992C
    // 0x801D2574: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    func_800C992C(rdram, ctx);
        goto after_9;
    // 0x801D2574: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    after_9:
    // 0x801D2578: b           L_801D36BC
    // 0x801D257C: nop

        goto L_801D36BC;
    // 0x801D257C: nop

L_801D2580:
    // 0x801D2580: jal         0x800C992C
    // 0x801D2584: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    func_800C992C(rdram, ctx);
        goto after_10;
    // 0x801D2584: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    after_10:
    // 0x801D2588: b           L_801D36BC
    // 0x801D258C: nop

        goto L_801D36BC;
    // 0x801D258C: nop

L_801D2590:
    // 0x801D2590: jal         0x800C992C
    // 0x801D2594: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    func_800C992C(rdram, ctx);
        goto after_11;
    // 0x801D2594: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    after_11:
    // 0x801D2598: b           L_801D36BC
    // 0x801D259C: nop

        goto L_801D36BC;
    // 0x801D259C: nop

L_801D25A0:
    // 0x801D25A0: lhu         $t2, 0x2A($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X2A);
    // 0x801D25A4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D25A8: addiu       $a0, $zero, 0x3E4
    ctx->r4 = ADD32(0, 0X3E4);
    // 0x801D25AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801D25B0: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x801D25B4: addiu       $a3, $zero, -0x14
    ctx->r7 = ADD32(0, -0X14);
    // 0x801D25B8: jal         0x801932D8
    // 0x801D25BC: sh          $t2, -0x2D84($at)
    MEM_H(-0X2D84, ctx->r1) = ctx->r10;
    func_801932D8_1501A0(rdram, ctx);
        goto after_12;
    // 0x801D25BC: sh          $t2, -0x2D84($at)
    MEM_H(-0X2D84, ctx->r1) = ctx->r10;
    after_12:
    // 0x801D25C0: b           L_801D36BC
    // 0x801D25C4: nop

        goto L_801D36BC;
    // 0x801D25C4: nop

L_801D25C8:
    // 0x801D25C8: lhu         $t3, 0x2A($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X2A);
    // 0x801D25CC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D25D0: addiu       $a0, $zero, 0x3E4
    ctx->r4 = ADD32(0, 0X3E4);
    // 0x801D25D4: addiu       $a1, $zero, -0x28
    ctx->r5 = ADD32(0, -0X28);
    // 0x801D25D8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801D25DC: addiu       $a3, $zero, -0x1E
    ctx->r7 = ADD32(0, -0X1E);
    // 0x801D25E0: jal         0x801932D8
    // 0x801D25E4: sh          $t3, -0x2D84($at)
    MEM_H(-0X2D84, ctx->r1) = ctx->r11;
    func_801932D8_1501A0(rdram, ctx);
        goto after_13;
    // 0x801D25E4: sh          $t3, -0x2D84($at)
    MEM_H(-0X2D84, ctx->r1) = ctx->r11;
    after_13:
    // 0x801D25E8: b           L_801D36BC
    // 0x801D25EC: nop

        goto L_801D36BC;
    // 0x801D25EC: nop

L_801D25F0:
    // 0x801D25F0: lhu         $t4, 0x2A($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X2A);
    // 0x801D25F4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D25F8: addiu       $a0, $zero, 0x3E4
    ctx->r4 = ADD32(0, 0X3E4);
    // 0x801D25FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801D2600: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    // 0x801D2604: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801D2608: jal         0x801932D8
    // 0x801D260C: sh          $t4, -0x2D84($at)
    MEM_H(-0X2D84, ctx->r1) = ctx->r12;
    func_801932D8_1501A0(rdram, ctx);
        goto after_14;
    // 0x801D260C: sh          $t4, -0x2D84($at)
    MEM_H(-0X2D84, ctx->r1) = ctx->r12;
    after_14:
    // 0x801D2610: b           L_801D36BC
    // 0x801D2614: nop

        goto L_801D36BC;
    // 0x801D2614: nop

L_801D2618:
    // 0x801D2618: lhu         $t5, 0x2A($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X2A);
    // 0x801D261C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D2620: addiu       $a0, $zero, 0x3E4
    ctx->r4 = ADD32(0, 0X3E4);
    // 0x801D2624: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801D2628: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x801D262C: addiu       $a3, $zero, -0x14
    ctx->r7 = ADD32(0, -0X14);
    // 0x801D2630: jal         0x801932D8
    // 0x801D2634: sh          $t5, -0x2D84($at)
    MEM_H(-0X2D84, ctx->r1) = ctx->r13;
    func_801932D8_1501A0(rdram, ctx);
        goto after_15;
    // 0x801D2634: sh          $t5, -0x2D84($at)
    MEM_H(-0X2D84, ctx->r1) = ctx->r13;
    after_15:
    // 0x801D2638: b           L_801D36BC
    // 0x801D263C: nop

        goto L_801D36BC;
    // 0x801D263C: nop

L_801D2640:
    // 0x801D2640: lhu         $t6, 0x2A($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X2A);
    // 0x801D2644: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D2648: addiu       $a0, $zero, 0x3E4
    ctx->r4 = ADD32(0, 0X3E4);
    // 0x801D264C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801D2650: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    // 0x801D2654: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801D2658: jal         0x801932D8
    // 0x801D265C: sh          $t6, -0x2D84($at)
    MEM_H(-0X2D84, ctx->r1) = ctx->r14;
    func_801932D8_1501A0(rdram, ctx);
        goto after_16;
    // 0x801D265C: sh          $t6, -0x2D84($at)
    MEM_H(-0X2D84, ctx->r1) = ctx->r14;
    after_16:
    // 0x801D2660: b           L_801D36BC
    // 0x801D2664: nop

        goto L_801D36BC;
    // 0x801D2664: nop

L_801D2668:
    // 0x801D2668: lhu         $t7, 0x2A($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X2A);
    // 0x801D266C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D2670: addiu       $a0, $zero, 0x3E4
    ctx->r4 = ADD32(0, 0X3E4);
    // 0x801D2674: addiu       $a1, $zero, -0x14
    ctx->r5 = ADD32(0, -0X14);
    // 0x801D2678: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x801D267C: addiu       $a3, $zero, -0x14
    ctx->r7 = ADD32(0, -0X14);
    // 0x801D2680: jal         0x801932D8
    // 0x801D2684: sh          $t7, -0x2D84($at)
    MEM_H(-0X2D84, ctx->r1) = ctx->r15;
    func_801932D8_1501A0(rdram, ctx);
        goto after_17;
    // 0x801D2684: sh          $t7, -0x2D84($at)
    MEM_H(-0X2D84, ctx->r1) = ctx->r15;
    after_17:
    // 0x801D2688: b           L_801D36BC
    // 0x801D268C: nop

        goto L_801D36BC;
    // 0x801D268C: nop

L_801D2690:
    // 0x801D2690: lhu         $t8, 0x2A($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X2A);
    // 0x801D2694: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D2698: addiu       $a0, $zero, 0x3E4
    ctx->r4 = ADD32(0, 0X3E4);
    // 0x801D269C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801D26A0: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x801D26A4: addiu       $a3, $zero, -0x14
    ctx->r7 = ADD32(0, -0X14);
    // 0x801D26A8: jal         0x801932D8
    // 0x801D26AC: sh          $t8, -0x2D84($at)
    MEM_H(-0X2D84, ctx->r1) = ctx->r24;
    func_801932D8_1501A0(rdram, ctx);
        goto after_18;
    // 0x801D26AC: sh          $t8, -0x2D84($at)
    MEM_H(-0X2D84, ctx->r1) = ctx->r24;
    after_18:
    // 0x801D26B0: b           L_801D36BC
    // 0x801D26B4: nop

        goto L_801D36BC;
    // 0x801D26B4: nop

L_801D26B8:
    // 0x801D26B8: lhu         $t9, 0x2A($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X2A);
    // 0x801D26BC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D26C0: addiu       $a0, $zero, 0x3E4
    ctx->r4 = ADD32(0, 0X3E4);
    // 0x801D26C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801D26C8: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x801D26CC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801D26D0: jal         0x801932D8
    // 0x801D26D4: sh          $t9, -0x2D84($at)
    MEM_H(-0X2D84, ctx->r1) = ctx->r25;
    func_801932D8_1501A0(rdram, ctx);
        goto after_19;
    // 0x801D26D4: sh          $t9, -0x2D84($at)
    MEM_H(-0X2D84, ctx->r1) = ctx->r25;
    after_19:
    // 0x801D26D8: b           L_801D36BC
    // 0x801D26DC: nop

        goto L_801D36BC;
    // 0x801D26DC: nop

L_801D26E0:
    // 0x801D26E0: lhu         $t0, 0x2A($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X2A);
    // 0x801D26E4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D26E8: addiu       $a0, $zero, 0x3E4
    ctx->r4 = ADD32(0, 0X3E4);
    // 0x801D26EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801D26F0: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    // 0x801D26F4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801D26F8: jal         0x801932D8
    // 0x801D26FC: sh          $t0, -0x2D84($at)
    MEM_H(-0X2D84, ctx->r1) = ctx->r8;
    func_801932D8_1501A0(rdram, ctx);
        goto after_20;
    // 0x801D26FC: sh          $t0, -0x2D84($at)
    MEM_H(-0X2D84, ctx->r1) = ctx->r8;
    after_20:
    // 0x801D2700: b           L_801D36BC
    // 0x801D2704: nop

        goto L_801D36BC;
    // 0x801D2704: nop

L_801D2708:
    // 0x801D2708: lhu         $t1, 0x2A($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X2A);
    // 0x801D270C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D2710: addiu       $a0, $zero, 0x3E4
    ctx->r4 = ADD32(0, 0X3E4);
    // 0x801D2714: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801D2718: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    // 0x801D271C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801D2720: jal         0x801932D8
    // 0x801D2724: sh          $t1, -0x2D84($at)
    MEM_H(-0X2D84, ctx->r1) = ctx->r9;
    func_801932D8_1501A0(rdram, ctx);
        goto after_21;
    // 0x801D2724: sh          $t1, -0x2D84($at)
    MEM_H(-0X2D84, ctx->r1) = ctx->r9;
    after_21:
    // 0x801D2728: b           L_801D36BC
    // 0x801D272C: nop

        goto L_801D36BC;
    // 0x801D272C: nop

L_801D2730:
    // 0x801D2730: lhu         $t2, 0x2A($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X2A);
    // 0x801D2734: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D2738: addiu       $a0, $zero, 0x3E4
    ctx->r4 = ADD32(0, 0X3E4);
    // 0x801D273C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801D2740: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x801D2744: addiu       $a3, $zero, -0x14
    ctx->r7 = ADD32(0, -0X14);
    // 0x801D2748: jal         0x801932D8
    // 0x801D274C: sh          $t2, -0x2D84($at)
    MEM_H(-0X2D84, ctx->r1) = ctx->r10;
    func_801932D8_1501A0(rdram, ctx);
        goto after_22;
    // 0x801D274C: sh          $t2, -0x2D84($at)
    MEM_H(-0X2D84, ctx->r1) = ctx->r10;
    after_22:
    // 0x801D2750: b           L_801D36BC
    // 0x801D2754: nop

        goto L_801D36BC;
    // 0x801D2754: nop

L_801D2758:
    // 0x801D2758: lhu         $t3, 0x2A($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X2A);
    // 0x801D275C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D2760: addiu       $a0, $zero, 0x3E4
    ctx->r4 = ADD32(0, 0X3E4);
    // 0x801D2764: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801D2768: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x801D276C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801D2770: jal         0x801932D8
    // 0x801D2774: sh          $t3, -0x2D84($at)
    MEM_H(-0X2D84, ctx->r1) = ctx->r11;
    func_801932D8_1501A0(rdram, ctx);
        goto after_23;
    // 0x801D2774: sh          $t3, -0x2D84($at)
    MEM_H(-0X2D84, ctx->r1) = ctx->r11;
    after_23:
    // 0x801D2778: b           L_801D36BC
    // 0x801D277C: nop

        goto L_801D36BC;
    // 0x801D277C: nop

L_801D2780:
    // 0x801D2780: addiu       $a0, $zero, 0x42
    ctx->r4 = ADD32(0, 0X42);
    // 0x801D2784: jal         0x8019337C
    // 0x801D2788: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    func_8019337C_1501A0(rdram, ctx);
        goto after_24;
    // 0x801D2788: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_24:
    // 0x801D278C: b           L_801D36BC
    // 0x801D2790: nop

        goto L_801D36BC;
    // 0x801D2790: nop

L_801D2794:
    // 0x801D2794: addiu       $a0, $zero, 0x41
    ctx->r4 = ADD32(0, 0X41);
    // 0x801D2798: jal         0x8019337C
    // 0x801D279C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    func_8019337C_1501A0(rdram, ctx);
        goto after_25;
    // 0x801D279C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_25:
    // 0x801D27A0: b           L_801D36BC
    // 0x801D27A4: nop

        goto L_801D36BC;
    // 0x801D27A4: nop

L_801D27A8:
    // 0x801D27A8: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    // 0x801D27AC: jal         0x8019337C
    // 0x801D27B0: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    func_8019337C_1501A0(rdram, ctx);
        goto after_26;
    // 0x801D27B0: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_26:
    // 0x801D27B4: b           L_801D36BC
    // 0x801D27B8: nop

        goto L_801D36BC;
    // 0x801D27B8: nop

L_801D27BC:
    // 0x801D27BC: addiu       $a0, $zero, 0x3F
    ctx->r4 = ADD32(0, 0X3F);
    // 0x801D27C0: jal         0x8019337C
    // 0x801D27C4: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    func_8019337C_1501A0(rdram, ctx);
        goto after_27;
    // 0x801D27C4: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_27:
    // 0x801D27C8: b           L_801D36BC
    // 0x801D27CC: nop

        goto L_801D36BC;
    // 0x801D27CC: nop

L_801D27D0:
    // 0x801D27D0: addiu       $a0, $zero, 0x3E
    ctx->r4 = ADD32(0, 0X3E);
    // 0x801D27D4: jal         0x8019337C
    // 0x801D27D8: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    func_8019337C_1501A0(rdram, ctx);
        goto after_28;
    // 0x801D27D8: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_28:
    // 0x801D27DC: b           L_801D36BC
    // 0x801D27E0: nop

        goto L_801D36BC;
    // 0x801D27E0: nop

L_801D27E4:
    // 0x801D27E4: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x801D27E8: jal         0x8019337C
    // 0x801D27EC: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    func_8019337C_1501A0(rdram, ctx);
        goto after_29;
    // 0x801D27EC: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_29:
    // 0x801D27F0: b           L_801D36BC
    // 0x801D27F4: nop

        goto L_801D36BC;
    // 0x801D27F4: nop

L_801D27F8:
    // 0x801D27F8: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x801D27FC: jal         0x8019337C
    // 0x801D2800: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    func_8019337C_1501A0(rdram, ctx);
        goto after_30;
    // 0x801D2800: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_30:
    // 0x801D2804: b           L_801D36BC
    // 0x801D2808: nop

        goto L_801D36BC;
    // 0x801D2808: nop

L_801D280C:
    // 0x801D280C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x801D2810: addiu       $t4, $t4, -0x2E28
    ctx->r12 = ADD32(ctx->r12, -0X2E28);
    // 0x801D2814: lbu         $t5, 0x1($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X1);
    // 0x801D2818: andi        $t6, $t5, 0x80
    ctx->r14 = ctx->r13 & 0X80;
    // 0x801D281C: beq         $t6, $zero, L_801D36BC
    if (ctx->r14 == 0) {
        // 0x801D2820: nop
    
            goto L_801D36BC;
    }
    // 0x801D2820: nop

    // 0x801D2824: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x801D2828: jal         0x8019337C
    // 0x801D282C: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    func_8019337C_1501A0(rdram, ctx);
        goto after_31;
    // 0x801D282C: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_31:
    // 0x801D2830: b           L_801D36BC
    // 0x801D2834: nop

        goto L_801D36BC;
    // 0x801D2834: nop

L_801D2838:
    // 0x801D2838: addiu       $a0, $zero, 0xC0
    ctx->r4 = ADD32(0, 0XC0);
    // 0x801D283C: jal         0x8019337C
    // 0x801D2840: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_8019337C_1501A0(rdram, ctx);
        goto after_32;
    // 0x801D2840: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_32:
    // 0x801D2844: b           L_801D36BC
    // 0x801D2848: nop

        goto L_801D36BC;
    // 0x801D2848: nop

L_801D284C:
    // 0x801D284C: addiu       $a0, $zero, 0xC1
    ctx->r4 = ADD32(0, 0XC1);
    // 0x801D2850: jal         0x8019337C
    // 0x801D2854: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_8019337C_1501A0(rdram, ctx);
        goto after_33;
    // 0x801D2854: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_33:
    // 0x801D2858: b           L_801D36BC
    // 0x801D285C: nop

        goto L_801D36BC;
    // 0x801D285C: nop

L_801D2860:
    // 0x801D2860: addiu       $a0, $zero, 0xC9
    ctx->r4 = ADD32(0, 0XC9);
    // 0x801D2864: jal         0x8019337C
    // 0x801D2868: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_8019337C_1501A0(rdram, ctx);
        goto after_34;
    // 0x801D2868: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_34:
    // 0x801D286C: b           L_801D36BC
    // 0x801D2870: nop

        goto L_801D36BC;
    // 0x801D2870: nop

L_801D2874:
    // 0x801D2874: addiu       $a0, $zero, 0xC4
    ctx->r4 = ADD32(0, 0XC4);
    // 0x801D2878: jal         0x8019337C
    // 0x801D287C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_8019337C_1501A0(rdram, ctx);
        goto after_35;
    // 0x801D287C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_35:
    // 0x801D2880: b           L_801D36BC
    // 0x801D2884: nop

        goto L_801D36BC;
    // 0x801D2884: nop

L_801D2888:
    // 0x801D2888: addiu       $a0, $zero, 0xC5
    ctx->r4 = ADD32(0, 0XC5);
    // 0x801D288C: jal         0x8019337C
    // 0x801D2890: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_8019337C_1501A0(rdram, ctx);
        goto after_36;
    // 0x801D2890: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_36:
    // 0x801D2894: b           L_801D36BC
    // 0x801D2898: nop

        goto L_801D36BC;
    // 0x801D2898: nop

L_801D289C:
    // 0x801D289C: addiu       $a0, $zero, 0xC6
    ctx->r4 = ADD32(0, 0XC6);
    // 0x801D28A0: jal         0x8019337C
    // 0x801D28A4: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_8019337C_1501A0(rdram, ctx);
        goto after_37;
    // 0x801D28A4: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_37:
    // 0x801D28A8: b           L_801D36BC
    // 0x801D28AC: nop

        goto L_801D36BC;
    // 0x801D28AC: nop

L_801D28B0:
    // 0x801D28B0: addiu       $a0, $zero, 0xC7
    ctx->r4 = ADD32(0, 0XC7);
    // 0x801D28B4: jal         0x8019337C
    // 0x801D28B8: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_8019337C_1501A0(rdram, ctx);
        goto after_38;
    // 0x801D28B8: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_38:
    // 0x801D28BC: b           L_801D36BC
    // 0x801D28C0: nop

        goto L_801D36BC;
    // 0x801D28C0: nop

L_801D28C4:
    // 0x801D28C4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801D28C8: addiu       $t7, $t7, -0x2E28
    ctx->r15 = ADD32(ctx->r15, -0X2E28);
    // 0x801D28CC: lbu         $t8, 0x1($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X1);
    // 0x801D28D0: andi        $t9, $t8, 0x2
    ctx->r25 = ctx->r24 & 0X2;
    // 0x801D28D4: beq         $t9, $zero, L_801D36BC
    if (ctx->r25 == 0) {
        // 0x801D28D8: nop
    
            goto L_801D36BC;
    }
    // 0x801D28D8: nop

    // 0x801D28DC: addiu       $t0, $zero, 0x20E4
    ctx->r8 = ADD32(0, 0X20E4);
    // 0x801D28E0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D28E4: sw          $t0, -0x2E34($at)
    MEM_W(-0X2E34, ctx->r1) = ctx->r8;
    // 0x801D28E8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D28EC: addiu       $t1, $zero, 0x102
    ctx->r9 = ADD32(0, 0X102);
    // 0x801D28F0: sw          $t1, -0x2C04($at)
    MEM_W(-0X2C04, ctx->r1) = ctx->r9;
    // 0x801D28F4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D28F8: addiu       $t2, $zero, 0xBA
    ctx->r10 = ADD32(0, 0XBA);
    // 0x801D28FC: sw          $t2, -0x2BEC($at)
    MEM_W(-0X2BEC, ctx->r1) = ctx->r10;
    // 0x801D2900: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D2904: addiu       $t3, $zero, 0x102
    ctx->r11 = ADD32(0, 0X102);
    // 0x801D2908: jal         0x80172DC4
    // 0x801D290C: sw          $t3, -0x2BF8($at)
    MEM_W(-0X2BF8, ctx->r1) = ctx->r11;
    func_80172DC4_1501A0(rdram, ctx);
        goto after_39;
    // 0x801D290C: sw          $t3, -0x2BF8($at)
    MEM_W(-0X2BF8, ctx->r1) = ctx->r11;
    after_39:
    // 0x801D2910: jal         0x80172E34
    // 0x801D2914: nop

    func_80172E34_1501A0(rdram, ctx);
        goto after_40;
    // 0x801D2914: nop

    after_40:
    // 0x801D2918: jal         0x80172F04
    // 0x801D291C: nop

    func_80172F04_1501A0(rdram, ctx);
        goto after_41;
    // 0x801D291C: nop

    after_41:
    // 0x801D2920: addiu       $t4, $zero, 0x36
    ctx->r12 = ADD32(0, 0X36);
    // 0x801D2924: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D2928: sw          $t4, -0x2B5C($at)
    MEM_W(-0X2B5C, ctx->r1) = ctx->r12;
    // 0x801D292C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D2930: addiu       $t5, $zero, 0x37
    ctx->r13 = ADD32(0, 0X37);
    // 0x801D2934: jal         0x80173538
    // 0x801D2938: sw          $t5, -0x2B50($at)
    MEM_W(-0X2B50, ctx->r1) = ctx->r13;
    func_80173538_1501A0(rdram, ctx);
        goto after_42;
    // 0x801D2938: sw          $t5, -0x2B50($at)
    MEM_W(-0X2B50, ctx->r1) = ctx->r13;
    after_42:
    // 0x801D293C: jal         0x801735A8
    // 0x801D2940: nop

    func_801735A8_1501A0(rdram, ctx);
        goto after_43;
    // 0x801D2940: nop

    after_43:
    // 0x801D2944: jal         0x801E2834
    // 0x801D2948: nop

    func_801E2834_1B66F0(rdram, ctx);
        goto after_44;
    // 0x801D2948: nop

    after_44:
    // 0x801D294C: b           L_801D36BC
    // 0x801D2950: nop

        goto L_801D36BC;
    // 0x801D2950: nop

L_801D2954:
    // 0x801D2954: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801D2958: addiu       $t6, $t6, -0x2E28
    ctx->r14 = ADD32(ctx->r14, -0X2E28);
    // 0x801D295C: lbu         $t7, 0x1($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X1);
    // 0x801D2960: andi        $t8, $t7, 0x2
    ctx->r24 = ctx->r15 & 0X2;
    // 0x801D2964: bne         $t8, $zero, L_801D36BC
    if (ctx->r24 != 0) {
        // 0x801D2968: nop
    
            goto L_801D36BC;
    }
    // 0x801D2968: nop

    // 0x801D296C: addiu       $t9, $zero, 0x1DCE
    ctx->r25 = ADD32(0, 0X1DCE);
    // 0x801D2970: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D2974: sw          $t9, -0x2E34($at)
    MEM_W(-0X2E34, ctx->r1) = ctx->r25;
    // 0x801D2978: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D297C: addiu       $t0, $zero, 0xE3
    ctx->r8 = ADD32(0, 0XE3);
    // 0x801D2980: sw          $t0, -0x2C04($at)
    MEM_W(-0X2C04, ctx->r1) = ctx->r8;
    // 0x801D2984: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D2988: addiu       $t1, $zero, 0x9D
    ctx->r9 = ADD32(0, 0X9D);
    // 0x801D298C: sw          $t1, -0x2BEC($at)
    MEM_W(-0X2BEC, ctx->r1) = ctx->r9;
    // 0x801D2990: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D2994: addiu       $t2, $zero, 0xE3
    ctx->r10 = ADD32(0, 0XE3);
    // 0x801D2998: jal         0x80172DC4
    // 0x801D299C: sw          $t2, -0x2BF8($at)
    MEM_W(-0X2BF8, ctx->r1) = ctx->r10;
    func_80172DC4_1501A0(rdram, ctx);
        goto after_45;
    // 0x801D299C: sw          $t2, -0x2BF8($at)
    MEM_W(-0X2BF8, ctx->r1) = ctx->r10;
    after_45:
    // 0x801D29A0: jal         0x80172E34
    // 0x801D29A4: nop

    func_80172E34_1501A0(rdram, ctx);
        goto after_46;
    // 0x801D29A4: nop

    after_46:
    // 0x801D29A8: jal         0x80172F04
    // 0x801D29AC: nop

    func_80172F04_1501A0(rdram, ctx);
        goto after_47;
    // 0x801D29AC: nop

    after_47:
    // 0x801D29B0: addiu       $t3, $zero, 0x35
    ctx->r11 = ADD32(0, 0X35);
    // 0x801D29B4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D29B8: sw          $t3, -0x2B5C($at)
    MEM_W(-0X2B5C, ctx->r1) = ctx->r11;
    // 0x801D29BC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D29C0: addiu       $t4, $zero, 0x36
    ctx->r12 = ADD32(0, 0X36);
    // 0x801D29C4: jal         0x80173538
    // 0x801D29C8: sw          $t4, -0x2B50($at)
    MEM_W(-0X2B50, ctx->r1) = ctx->r12;
    func_80173538_1501A0(rdram, ctx);
        goto after_48;
    // 0x801D29C8: sw          $t4, -0x2B50($at)
    MEM_W(-0X2B50, ctx->r1) = ctx->r12;
    after_48:
    // 0x801D29CC: jal         0x801735A8
    // 0x801D29D0: nop

    func_801735A8_1501A0(rdram, ctx);
        goto after_49;
    // 0x801D29D0: nop

    after_49:
    // 0x801D29D4: jal         0x801E2834
    // 0x801D29D8: nop

    func_801E2834_1B66F0(rdram, ctx);
        goto after_50;
    // 0x801D29D8: nop

    after_50:
    // 0x801D29DC: b           L_801D36BC
    // 0x801D29E0: nop

        goto L_801D36BC;
    // 0x801D29E0: nop

L_801D29E4:
    // 0x801D29E4: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x801D29E8: lw          $t5, -0x2E48($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2E48);
    // 0x801D29EC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801D29F0: bne         $t5, $at, L_801D2A88
    if (ctx->r13 != ctx->r1) {
        // 0x801D29F4: nop
    
            goto L_801D2A88;
    }
    // 0x801D29F4: nop

    // 0x801D29F8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801D29FC: addiu       $t6, $t6, -0x2E28
    ctx->r14 = ADD32(ctx->r14, -0X2E28);
    // 0x801D2A00: lbu         $t7, 0x8($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X8);
    // 0x801D2A04: andi        $t8, $t7, 0x2
    ctx->r24 = ctx->r15 & 0X2;
    // 0x801D2A08: beq         $t8, $zero, L_801D36BC
    if (ctx->r24 == 0) {
        // 0x801D2A0C: nop
    
            goto L_801D36BC;
    }
    // 0x801D2A0C: nop

    // 0x801D2A10: addiu       $t9, $zero, 0x528A
    ctx->r25 = ADD32(0, 0X528A);
    // 0x801D2A14: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D2A18: sw          $t9, -0x2E34($at)
    MEM_W(-0X2E34, ctx->r1) = ctx->r25;
    // 0x801D2A1C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D2A20: addiu       $t0, $zero, 0x117
    ctx->r8 = ADD32(0, 0X117);
    // 0x801D2A24: sw          $t0, -0x2C04($at)
    MEM_W(-0X2C04, ctx->r1) = ctx->r8;
    // 0x801D2A28: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D2A2C: addiu       $t1, $zero, 0xCC
    ctx->r9 = ADD32(0, 0XCC);
    // 0x801D2A30: sw          $t1, -0x2BEC($at)
    MEM_W(-0X2BEC, ctx->r1) = ctx->r9;
    // 0x801D2A34: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D2A38: addiu       $t2, $zero, 0x117
    ctx->r10 = ADD32(0, 0X117);
    // 0x801D2A3C: jal         0x80172DC4
    // 0x801D2A40: sw          $t2, -0x2BF8($at)
    MEM_W(-0X2BF8, ctx->r1) = ctx->r10;
    func_80172DC4_1501A0(rdram, ctx);
        goto after_51;
    // 0x801D2A40: sw          $t2, -0x2BF8($at)
    MEM_W(-0X2BF8, ctx->r1) = ctx->r10;
    after_51:
    // 0x801D2A44: jal         0x80172E34
    // 0x801D2A48: nop

    func_80172E34_1501A0(rdram, ctx);
        goto after_52;
    // 0x801D2A48: nop

    after_52:
    // 0x801D2A4C: jal         0x80172F04
    // 0x801D2A50: nop

    func_80172F04_1501A0(rdram, ctx);
        goto after_53;
    // 0x801D2A50: nop

    after_53:
    // 0x801D2A54: addiu       $t3, $zero, 0x47
    ctx->r11 = ADD32(0, 0X47);
    // 0x801D2A58: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D2A5C: sw          $t3, -0x2B5C($at)
    MEM_W(-0X2B5C, ctx->r1) = ctx->r11;
    // 0x801D2A60: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D2A64: addiu       $t4, $zero, 0x43
    ctx->r12 = ADD32(0, 0X43);
    // 0x801D2A68: jal         0x80173538
    // 0x801D2A6C: sw          $t4, -0x2B50($at)
    MEM_W(-0X2B50, ctx->r1) = ctx->r12;
    func_80173538_1501A0(rdram, ctx);
        goto after_54;
    // 0x801D2A6C: sw          $t4, -0x2B50($at)
    MEM_W(-0X2B50, ctx->r1) = ctx->r12;
    after_54:
    // 0x801D2A70: jal         0x801735A8
    // 0x801D2A74: nop

    func_801735A8_1501A0(rdram, ctx);
        goto after_55;
    // 0x801D2A74: nop

    after_55:
    // 0x801D2A78: jal         0x801E2834
    // 0x801D2A7C: nop

    func_801E2834_1B66F0(rdram, ctx);
        goto after_56;
    // 0x801D2A7C: nop

    after_56:
    // 0x801D2A80: b           L_801D36BC
    // 0x801D2A84: nop

        goto L_801D36BC;
    // 0x801D2A84: nop

L_801D2A88:
    // 0x801D2A88: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x801D2A8C: lw          $t5, -0x2E38($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2E38);
    // 0x801D2A90: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801D2A94: beq         $t5, $at, L_801D2AAC
    if (ctx->r13 == ctx->r1) {
        // 0x801D2A98: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_801D2AAC;
    }
    // 0x801D2A98: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x801D2A9C: beq         $t5, $at, L_801D2AAC
    if (ctx->r13 == ctx->r1) {
        // 0x801D2AA0: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_801D2AAC;
    }
    // 0x801D2AA0: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x801D2AA4: bne         $t5, $at, L_801D36BC
    if (ctx->r13 != ctx->r1) {
        // 0x801D2AA8: nop
    
            goto L_801D36BC;
    }
    // 0x801D2AA8: nop

L_801D2AAC:
    // 0x801D2AAC: addiu       $t6, $zero, 0x528A
    ctx->r14 = ADD32(0, 0X528A);
    // 0x801D2AB0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D2AB4: sw          $t6, -0x2E34($at)
    MEM_W(-0X2E34, ctx->r1) = ctx->r14;
    // 0x801D2AB8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D2ABC: addiu       $t7, $zero, 0x117
    ctx->r15 = ADD32(0, 0X117);
    // 0x801D2AC0: sw          $t7, -0x2C04($at)
    MEM_W(-0X2C04, ctx->r1) = ctx->r15;
    // 0x801D2AC4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D2AC8: addiu       $t8, $zero, 0xCC
    ctx->r24 = ADD32(0, 0XCC);
    // 0x801D2ACC: sw          $t8, -0x2BEC($at)
    MEM_W(-0X2BEC, ctx->r1) = ctx->r24;
    // 0x801D2AD0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D2AD4: addiu       $t9, $zero, 0x117
    ctx->r25 = ADD32(0, 0X117);
    // 0x801D2AD8: jal         0x80172DC4
    // 0x801D2ADC: sw          $t9, -0x2BF8($at)
    MEM_W(-0X2BF8, ctx->r1) = ctx->r25;
    func_80172DC4_1501A0(rdram, ctx);
        goto after_57;
    // 0x801D2ADC: sw          $t9, -0x2BF8($at)
    MEM_W(-0X2BF8, ctx->r1) = ctx->r25;
    after_57:
    // 0x801D2AE0: jal         0x80172E34
    // 0x801D2AE4: nop

    func_80172E34_1501A0(rdram, ctx);
        goto after_58;
    // 0x801D2AE4: nop

    after_58:
    // 0x801D2AE8: jal         0x80172F04
    // 0x801D2AEC: nop

    func_80172F04_1501A0(rdram, ctx);
        goto after_59;
    // 0x801D2AEC: nop

    after_59:
    // 0x801D2AF0: addiu       $t0, $zero, 0x47
    ctx->r8 = ADD32(0, 0X47);
    // 0x801D2AF4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D2AF8: sw          $t0, -0x2B5C($at)
    MEM_W(-0X2B5C, ctx->r1) = ctx->r8;
    // 0x801D2AFC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D2B00: addiu       $t1, $zero, 0x43
    ctx->r9 = ADD32(0, 0X43);
    // 0x801D2B04: jal         0x80173538
    // 0x801D2B08: sw          $t1, -0x2B50($at)
    MEM_W(-0X2B50, ctx->r1) = ctx->r9;
    func_80173538_1501A0(rdram, ctx);
        goto after_60;
    // 0x801D2B08: sw          $t1, -0x2B50($at)
    MEM_W(-0X2B50, ctx->r1) = ctx->r9;
    after_60:
    // 0x801D2B0C: jal         0x801735A8
    // 0x801D2B10: nop

    func_801735A8_1501A0(rdram, ctx);
        goto after_61;
    // 0x801D2B10: nop

    after_61:
    // 0x801D2B14: jal         0x801E2834
    // 0x801D2B18: nop

    func_801E2834_1B66F0(rdram, ctx);
        goto after_62;
    // 0x801D2B18: nop

    after_62:
    // 0x801D2B1C: b           L_801D36BC
    // 0x801D2B20: nop

        goto L_801D36BC;
    // 0x801D2B20: nop

L_801D2B24:
    // 0x801D2B24: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x801D2B28: lw          $t2, -0x2E48($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2E48);
    // 0x801D2B2C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801D2B30: bne         $t2, $at, L_801D2BC8
    if (ctx->r10 != ctx->r1) {
        // 0x801D2B34: nop
    
            goto L_801D2BC8;
    }
    // 0x801D2B34: nop

    // 0x801D2B38: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x801D2B3C: addiu       $t3, $t3, -0x2E28
    ctx->r11 = ADD32(ctx->r11, -0X2E28);
    // 0x801D2B40: lbu         $t4, 0x8($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X8);
    // 0x801D2B44: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x801D2B48: beq         $t5, $zero, L_801D36BC
    if (ctx->r13 == 0) {
        // 0x801D2B4C: nop
    
            goto L_801D36BC;
    }
    // 0x801D2B4C: nop

    // 0x801D2B50: addiu       $t6, $zero, 0x56D6
    ctx->r14 = ADD32(0, 0X56D6);
    // 0x801D2B54: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D2B58: sw          $t6, -0x2E34($at)
    MEM_W(-0X2E34, ctx->r1) = ctx->r14;
    // 0x801D2B5C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D2B60: addiu       $t7, $zero, 0x13E
    ctx->r15 = ADD32(0, 0X13E);
    // 0x801D2B64: sw          $t7, -0x2C04($at)
    MEM_W(-0X2C04, ctx->r1) = ctx->r15;
    // 0x801D2B68: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D2B6C: addiu       $t8, $zero, 0xE6
    ctx->r24 = ADD32(0, 0XE6);
    // 0x801D2B70: sw          $t8, -0x2BEC($at)
    MEM_W(-0X2BEC, ctx->r1) = ctx->r24;
    // 0x801D2B74: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D2B78: addiu       $t9, $zero, 0x13E
    ctx->r25 = ADD32(0, 0X13E);
    // 0x801D2B7C: jal         0x80172DC4
    // 0x801D2B80: sw          $t9, -0x2BF8($at)
    MEM_W(-0X2BF8, ctx->r1) = ctx->r25;
    func_80172DC4_1501A0(rdram, ctx);
        goto after_63;
    // 0x801D2B80: sw          $t9, -0x2BF8($at)
    MEM_W(-0X2BF8, ctx->r1) = ctx->r25;
    after_63:
    // 0x801D2B84: jal         0x80172E34
    // 0x801D2B88: nop

    func_80172E34_1501A0(rdram, ctx);
        goto after_64;
    // 0x801D2B88: nop

    after_64:
    // 0x801D2B8C: jal         0x80172F04
    // 0x801D2B90: nop

    func_80172F04_1501A0(rdram, ctx);
        goto after_65;
    // 0x801D2B90: nop

    after_65:
    // 0x801D2B94: addiu       $t0, $zero, 0x52
    ctx->r8 = ADD32(0, 0X52);
    // 0x801D2B98: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D2B9C: sw          $t0, -0x2B5C($at)
    MEM_W(-0X2B5C, ctx->r1) = ctx->r8;
    // 0x801D2BA0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D2BA4: addiu       $t1, $zero, 0x4E
    ctx->r9 = ADD32(0, 0X4E);
    // 0x801D2BA8: jal         0x80173538
    // 0x801D2BAC: sw          $t1, -0x2B50($at)
    MEM_W(-0X2B50, ctx->r1) = ctx->r9;
    func_80173538_1501A0(rdram, ctx);
        goto after_66;
    // 0x801D2BAC: sw          $t1, -0x2B50($at)
    MEM_W(-0X2B50, ctx->r1) = ctx->r9;
    after_66:
    // 0x801D2BB0: jal         0x801735A8
    // 0x801D2BB4: nop

    func_801735A8_1501A0(rdram, ctx);
        goto after_67;
    // 0x801D2BB4: nop

    after_67:
    // 0x801D2BB8: jal         0x801E2834
    // 0x801D2BBC: nop

    func_801E2834_1B66F0(rdram, ctx);
        goto after_68;
    // 0x801D2BBC: nop

    after_68:
    // 0x801D2BC0: b           L_801D36BC
    // 0x801D2BC4: nop

        goto L_801D36BC;
    // 0x801D2BC4: nop

L_801D2BC8:
    // 0x801D2BC8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x801D2BCC: lw          $t2, -0x2E38($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2E38);
    // 0x801D2BD0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801D2BD4: beq         $t2, $at, L_801D2BEC
    if (ctx->r10 == ctx->r1) {
        // 0x801D2BD8: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_801D2BEC;
    }
    // 0x801D2BD8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x801D2BDC: beq         $t2, $at, L_801D2BEC
    if (ctx->r10 == ctx->r1) {
        // 0x801D2BE0: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_801D2BEC;
    }
    // 0x801D2BE0: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x801D2BE4: bne         $t2, $at, L_801D36BC
    if (ctx->r10 != ctx->r1) {
        // 0x801D2BE8: nop
    
            goto L_801D36BC;
    }
    // 0x801D2BE8: nop

L_801D2BEC:
    // 0x801D2BEC: addiu       $t3, $zero, 0x56D6
    ctx->r11 = ADD32(0, 0X56D6);
    // 0x801D2BF0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D2BF4: sw          $t3, -0x2E34($at)
    MEM_W(-0X2E34, ctx->r1) = ctx->r11;
    // 0x801D2BF8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D2BFC: addiu       $t4, $zero, 0x13E
    ctx->r12 = ADD32(0, 0X13E);
    // 0x801D2C00: sw          $t4, -0x2C04($at)
    MEM_W(-0X2C04, ctx->r1) = ctx->r12;
    // 0x801D2C04: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D2C08: addiu       $t5, $zero, 0xE6
    ctx->r13 = ADD32(0, 0XE6);
    // 0x801D2C0C: sw          $t5, -0x2BEC($at)
    MEM_W(-0X2BEC, ctx->r1) = ctx->r13;
    // 0x801D2C10: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D2C14: addiu       $t6, $zero, 0x13E
    ctx->r14 = ADD32(0, 0X13E);
    // 0x801D2C18: jal         0x80172DC4
    // 0x801D2C1C: sw          $t6, -0x2BF8($at)
    MEM_W(-0X2BF8, ctx->r1) = ctx->r14;
    func_80172DC4_1501A0(rdram, ctx);
        goto after_69;
    // 0x801D2C1C: sw          $t6, -0x2BF8($at)
    MEM_W(-0X2BF8, ctx->r1) = ctx->r14;
    after_69:
    // 0x801D2C20: jal         0x80172E34
    // 0x801D2C24: nop

    func_80172E34_1501A0(rdram, ctx);
        goto after_70;
    // 0x801D2C24: nop

    after_70:
    // 0x801D2C28: jal         0x80172F04
    // 0x801D2C2C: nop

    func_80172F04_1501A0(rdram, ctx);
        goto after_71;
    // 0x801D2C2C: nop

    after_71:
    // 0x801D2C30: addiu       $t7, $zero, 0x52
    ctx->r15 = ADD32(0, 0X52);
    // 0x801D2C34: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D2C38: sw          $t7, -0x2B5C($at)
    MEM_W(-0X2B5C, ctx->r1) = ctx->r15;
    // 0x801D2C3C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D2C40: addiu       $t8, $zero, 0x4E
    ctx->r24 = ADD32(0, 0X4E);
    // 0x801D2C44: jal         0x80173538
    // 0x801D2C48: sw          $t8, -0x2B50($at)
    MEM_W(-0X2B50, ctx->r1) = ctx->r24;
    func_80173538_1501A0(rdram, ctx);
        goto after_72;
    // 0x801D2C48: sw          $t8, -0x2B50($at)
    MEM_W(-0X2B50, ctx->r1) = ctx->r24;
    after_72:
    // 0x801D2C4C: jal         0x801735A8
    // 0x801D2C50: nop

    func_801735A8_1501A0(rdram, ctx);
        goto after_73;
    // 0x801D2C50: nop

    after_73:
    // 0x801D2C54: jal         0x801E2834
    // 0x801D2C58: nop

    func_801E2834_1B66F0(rdram, ctx);
        goto after_74;
    // 0x801D2C58: nop

    after_74:
    // 0x801D2C5C: b           L_801D36BC
    // 0x801D2C60: nop

        goto L_801D36BC;
    // 0x801D2C60: nop

L_801D2C64:
    // 0x801D2C64: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801D2C68: lw          $t9, -0x2E48($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2E48);
    // 0x801D2C6C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801D2C70: bne         $t9, $at, L_801D2D94
    if (ctx->r25 != ctx->r1) {
        // 0x801D2C74: nop
    
            goto L_801D2D94;
    }
    // 0x801D2C74: nop

    // 0x801D2C78: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x801D2C7C: addiu       $t0, $t0, -0x2E28
    ctx->r8 = ADD32(ctx->r8, -0X2E28);
    // 0x801D2C80: lbu         $t1, 0x8($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X8);
    // 0x801D2C84: andi        $t2, $t1, 0x4
    ctx->r10 = ctx->r9 & 0X4;
    // 0x801D2C88: beq         $t2, $zero, L_801D36BC
    if (ctx->r10 == 0) {
        // 0x801D2C8C: nop
    
            goto L_801D36BC;
    }
    // 0x801D2C8C: nop

    // 0x801D2C90: jal         0x800E4CDC
    // 0x801D2C94: nop

    func_800E4CDC(rdram, ctx);
        goto after_75;
    // 0x801D2C94: nop

    after_75:
    // 0x801D2C98: andi        $t3, $v0, 0x8000
    ctx->r11 = ctx->r2 & 0X8000;
    // 0x801D2C9C: beq         $t3, $zero, L_801D2D1C
    if (ctx->r11 == 0) {
        // 0x801D2CA0: nop
    
            goto L_801D2D1C;
    }
    // 0x801D2CA0: nop

    // 0x801D2CA4: addiu       $t4, $zero, 0x5BEA
    ctx->r12 = ADD32(0, 0X5BEA);
    // 0x801D2CA8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D2CAC: sw          $t4, -0x2E34($at)
    MEM_W(-0X2E34, ctx->r1) = ctx->r12;
    // 0x801D2CB0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D2CB4: addiu       $t5, $zero, 0x15C
    ctx->r13 = ADD32(0, 0X15C);
    // 0x801D2CB8: sw          $t5, -0x2C04($at)
    MEM_W(-0X2C04, ctx->r1) = ctx->r13;
    // 0x801D2CBC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D2CC0: addiu       $t6, $zero, 0xFD
    ctx->r14 = ADD32(0, 0XFD);
    // 0x801D2CC4: sw          $t6, -0x2BEC($at)
    MEM_W(-0X2BEC, ctx->r1) = ctx->r14;
    // 0x801D2CC8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D2CCC: addiu       $t7, $zero, 0x15C
    ctx->r15 = ADD32(0, 0X15C);
    // 0x801D2CD0: jal         0x80172DC4
    // 0x801D2CD4: sw          $t7, -0x2BF8($at)
    MEM_W(-0X2BF8, ctx->r1) = ctx->r15;
    func_80172DC4_1501A0(rdram, ctx);
        goto after_76;
    // 0x801D2CD4: sw          $t7, -0x2BF8($at)
    MEM_W(-0X2BF8, ctx->r1) = ctx->r15;
    after_76:
    // 0x801D2CD8: jal         0x80172E34
    // 0x801D2CDC: nop

    func_80172E34_1501A0(rdram, ctx);
        goto after_77;
    // 0x801D2CDC: nop

    after_77:
    // 0x801D2CE0: jal         0x80172F04
    // 0x801D2CE4: nop

    func_80172F04_1501A0(rdram, ctx);
        goto after_78;
    // 0x801D2CE4: nop

    after_78:
    // 0x801D2CE8: addiu       $t8, $zero, 0x60
    ctx->r24 = ADD32(0, 0X60);
    // 0x801D2CEC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D2CF0: sw          $t8, -0x2B5C($at)
    MEM_W(-0X2B5C, ctx->r1) = ctx->r24;
    // 0x801D2CF4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D2CF8: addiu       $t9, $zero, 0x5C
    ctx->r25 = ADD32(0, 0X5C);
    // 0x801D2CFC: jal         0x80173538
    // 0x801D2D00: sw          $t9, -0x2B50($at)
    MEM_W(-0X2B50, ctx->r1) = ctx->r25;
    func_80173538_1501A0(rdram, ctx);
        goto after_79;
    // 0x801D2D00: sw          $t9, -0x2B50($at)
    MEM_W(-0X2B50, ctx->r1) = ctx->r25;
    after_79:
    // 0x801D2D04: jal         0x801735A8
    // 0x801D2D08: nop

    func_801735A8_1501A0(rdram, ctx);
        goto after_80;
    // 0x801D2D08: nop

    after_80:
    // 0x801D2D0C: jal         0x801E2834
    // 0x801D2D10: nop

    func_801E2834_1B66F0(rdram, ctx);
        goto after_81;
    // 0x801D2D10: nop

    after_81:
    // 0x801D2D14: b           L_801D36BC
    // 0x801D2D18: nop

        goto L_801D36BC;
    // 0x801D2D18: nop

L_801D2D1C:
    // 0x801D2D1C: addiu       $t0, $zero, 0x628E
    ctx->r8 = ADD32(0, 0X628E);
    // 0x801D2D20: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D2D24: sw          $t0, -0x2E34($at)
    MEM_W(-0X2E34, ctx->r1) = ctx->r8;
    // 0x801D2D28: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D2D2C: addiu       $t1, $zero, 0x192
    ctx->r9 = ADD32(0, 0X192);
    // 0x801D2D30: sw          $t1, -0x2C04($at)
    MEM_W(-0X2C04, ctx->r1) = ctx->r9;
    // 0x801D2D34: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D2D38: addiu       $t2, $zero, 0x118
    ctx->r10 = ADD32(0, 0X118);
    // 0x801D2D3C: sw          $t2, -0x2BEC($at)
    MEM_W(-0X2BEC, ctx->r1) = ctx->r10;
    // 0x801D2D40: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D2D44: addiu       $t3, $zero, 0x192
    ctx->r11 = ADD32(0, 0X192);
    // 0x801D2D48: jal         0x80172DC4
    // 0x801D2D4C: sw          $t3, -0x2BF8($at)
    MEM_W(-0X2BF8, ctx->r1) = ctx->r11;
    func_80172DC4_1501A0(rdram, ctx);
        goto after_82;
    // 0x801D2D4C: sw          $t3, -0x2BF8($at)
    MEM_W(-0X2BF8, ctx->r1) = ctx->r11;
    after_82:
    // 0x801D2D50: jal         0x80172E34
    // 0x801D2D54: nop

    func_80172E34_1501A0(rdram, ctx);
        goto after_83;
    // 0x801D2D54: nop

    after_83:
    // 0x801D2D58: jal         0x80172F04
    // 0x801D2D5C: nop

    func_80172F04_1501A0(rdram, ctx);
        goto after_84;
    // 0x801D2D5C: nop

    after_84:
    // 0x801D2D60: addiu       $t4, $zero, 0x64
    ctx->r12 = ADD32(0, 0X64);
    // 0x801D2D64: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D2D68: sw          $t4, -0x2B5C($at)
    MEM_W(-0X2B5C, ctx->r1) = ctx->r12;
    // 0x801D2D6C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D2D70: addiu       $t5, $zero, 0x60
    ctx->r13 = ADD32(0, 0X60);
    // 0x801D2D74: jal         0x80173538
    // 0x801D2D78: sw          $t5, -0x2B50($at)
    MEM_W(-0X2B50, ctx->r1) = ctx->r13;
    func_80173538_1501A0(rdram, ctx);
        goto after_85;
    // 0x801D2D78: sw          $t5, -0x2B50($at)
    MEM_W(-0X2B50, ctx->r1) = ctx->r13;
    after_85:
    // 0x801D2D7C: jal         0x801735A8
    // 0x801D2D80: nop

    func_801735A8_1501A0(rdram, ctx);
        goto after_86;
    // 0x801D2D80: nop

    after_86:
    // 0x801D2D84: jal         0x801E2834
    // 0x801D2D88: nop

    func_801E2834_1B66F0(rdram, ctx);
        goto after_87;
    // 0x801D2D88: nop

    after_87:
    // 0x801D2D8C: b           L_801D36BC
    // 0x801D2D90: nop

        goto L_801D36BC;
    // 0x801D2D90: nop

L_801D2D94:
    // 0x801D2D94: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801D2D98: lw          $t6, -0x2E38($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2E38);
    // 0x801D2D9C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801D2DA0: beq         $t6, $at, L_801D2DB8
    if (ctx->r14 == ctx->r1) {
        // 0x801D2DA4: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_801D2DB8;
    }
    // 0x801D2DA4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x801D2DA8: beq         $t6, $at, L_801D2DB8
    if (ctx->r14 == ctx->r1) {
        // 0x801D2DAC: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_801D2DB8;
    }
    // 0x801D2DAC: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x801D2DB0: bne         $t6, $at, L_801D2E30
    if (ctx->r14 != ctx->r1) {
        // 0x801D2DB4: nop
    
            goto L_801D2E30;
    }
    // 0x801D2DB4: nop

L_801D2DB8:
    // 0x801D2DB8: addiu       $t7, $zero, 0x5BEA
    ctx->r15 = ADD32(0, 0X5BEA);
    // 0x801D2DBC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D2DC0: sw          $t7, -0x2E34($at)
    MEM_W(-0X2E34, ctx->r1) = ctx->r15;
    // 0x801D2DC4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D2DC8: addiu       $t8, $zero, 0x15C
    ctx->r24 = ADD32(0, 0X15C);
    // 0x801D2DCC: sw          $t8, -0x2C04($at)
    MEM_W(-0X2C04, ctx->r1) = ctx->r24;
    // 0x801D2DD0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D2DD4: addiu       $t9, $zero, 0xFD
    ctx->r25 = ADD32(0, 0XFD);
    // 0x801D2DD8: sw          $t9, -0x2BEC($at)
    MEM_W(-0X2BEC, ctx->r1) = ctx->r25;
    // 0x801D2DDC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D2DE0: addiu       $t0, $zero, 0x15C
    ctx->r8 = ADD32(0, 0X15C);
    // 0x801D2DE4: jal         0x80172DC4
    // 0x801D2DE8: sw          $t0, -0x2BF8($at)
    MEM_W(-0X2BF8, ctx->r1) = ctx->r8;
    func_80172DC4_1501A0(rdram, ctx);
        goto after_88;
    // 0x801D2DE8: sw          $t0, -0x2BF8($at)
    MEM_W(-0X2BF8, ctx->r1) = ctx->r8;
    after_88:
    // 0x801D2DEC: jal         0x80172E34
    // 0x801D2DF0: nop

    func_80172E34_1501A0(rdram, ctx);
        goto after_89;
    // 0x801D2DF0: nop

    after_89:
    // 0x801D2DF4: jal         0x80172F04
    // 0x801D2DF8: nop

    func_80172F04_1501A0(rdram, ctx);
        goto after_90;
    // 0x801D2DF8: nop

    after_90:
    // 0x801D2DFC: addiu       $t1, $zero, 0x60
    ctx->r9 = ADD32(0, 0X60);
    // 0x801D2E00: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D2E04: sw          $t1, -0x2B5C($at)
    MEM_W(-0X2B5C, ctx->r1) = ctx->r9;
    // 0x801D2E08: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D2E0C: addiu       $t2, $zero, 0x5C
    ctx->r10 = ADD32(0, 0X5C);
    // 0x801D2E10: jal         0x80173538
    // 0x801D2E14: sw          $t2, -0x2B50($at)
    MEM_W(-0X2B50, ctx->r1) = ctx->r10;
    func_80173538_1501A0(rdram, ctx);
        goto after_91;
    // 0x801D2E14: sw          $t2, -0x2B50($at)
    MEM_W(-0X2B50, ctx->r1) = ctx->r10;
    after_91:
    // 0x801D2E18: jal         0x801735A8
    // 0x801D2E1C: nop

    func_801735A8_1501A0(rdram, ctx);
        goto after_92;
    // 0x801D2E1C: nop

    after_92:
    // 0x801D2E20: jal         0x801E2834
    // 0x801D2E24: nop

    func_801E2834_1B66F0(rdram, ctx);
        goto after_93;
    // 0x801D2E24: nop

    after_93:
    // 0x801D2E28: b           L_801D36BC
    // 0x801D2E2C: nop

        goto L_801D36BC;
    // 0x801D2E2C: nop

L_801D2E30:
    // 0x801D2E30: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x801D2E34: lw          $t3, -0x2E38($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2E38);
    // 0x801D2E38: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x801D2E3C: beq         $t3, $at, L_801D2E54
    if (ctx->r11 == ctx->r1) {
        // 0x801D2E40: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_801D2E54;
    }
    // 0x801D2E40: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x801D2E44: beq         $t3, $at, L_801D2E54
    if (ctx->r11 == ctx->r1) {
        // 0x801D2E48: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_801D2E54;
    }
    // 0x801D2E48: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x801D2E4C: bne         $t3, $at, L_801D36BC
    if (ctx->r11 != ctx->r1) {
        // 0x801D2E50: nop
    
            goto L_801D36BC;
    }
    // 0x801D2E50: nop

L_801D2E54:
    // 0x801D2E54: addiu       $t4, $zero, 0x628E
    ctx->r12 = ADD32(0, 0X628E);
    // 0x801D2E58: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D2E5C: sw          $t4, -0x2E34($at)
    MEM_W(-0X2E34, ctx->r1) = ctx->r12;
    // 0x801D2E60: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D2E64: addiu       $t5, $zero, 0x192
    ctx->r13 = ADD32(0, 0X192);
    // 0x801D2E68: sw          $t5, -0x2C04($at)
    MEM_W(-0X2C04, ctx->r1) = ctx->r13;
    // 0x801D2E6C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D2E70: addiu       $t6, $zero, 0x118
    ctx->r14 = ADD32(0, 0X118);
    // 0x801D2E74: sw          $t6, -0x2BEC($at)
    MEM_W(-0X2BEC, ctx->r1) = ctx->r14;
    // 0x801D2E78: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D2E7C: addiu       $t7, $zero, 0x192
    ctx->r15 = ADD32(0, 0X192);
    // 0x801D2E80: jal         0x80172DC4
    // 0x801D2E84: sw          $t7, -0x2BF8($at)
    MEM_W(-0X2BF8, ctx->r1) = ctx->r15;
    func_80172DC4_1501A0(rdram, ctx);
        goto after_94;
    // 0x801D2E84: sw          $t7, -0x2BF8($at)
    MEM_W(-0X2BF8, ctx->r1) = ctx->r15;
    after_94:
    // 0x801D2E88: jal         0x80172E34
    // 0x801D2E8C: nop

    func_80172E34_1501A0(rdram, ctx);
        goto after_95;
    // 0x801D2E8C: nop

    after_95:
    // 0x801D2E90: jal         0x80172F04
    // 0x801D2E94: nop

    func_80172F04_1501A0(rdram, ctx);
        goto after_96;
    // 0x801D2E94: nop

    after_96:
    // 0x801D2E98: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x801D2E9C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D2EA0: sw          $t8, -0x2B5C($at)
    MEM_W(-0X2B5C, ctx->r1) = ctx->r24;
    // 0x801D2EA4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D2EA8: addiu       $t9, $zero, 0x60
    ctx->r25 = ADD32(0, 0X60);
    // 0x801D2EAC: jal         0x80173538
    // 0x801D2EB0: sw          $t9, -0x2B50($at)
    MEM_W(-0X2B50, ctx->r1) = ctx->r25;
    func_80173538_1501A0(rdram, ctx);
        goto after_97;
    // 0x801D2EB0: sw          $t9, -0x2B50($at)
    MEM_W(-0X2B50, ctx->r1) = ctx->r25;
    after_97:
    // 0x801D2EB4: jal         0x801735A8
    // 0x801D2EB8: nop

    func_801735A8_1501A0(rdram, ctx);
        goto after_98;
    // 0x801D2EB8: nop

    after_98:
    // 0x801D2EBC: jal         0x801E2834
    // 0x801D2EC0: nop

    func_801E2834_1B66F0(rdram, ctx);
        goto after_99;
    // 0x801D2EC0: nop

    after_99:
    // 0x801D2EC4: b           L_801D36BC
    // 0x801D2EC8: nop

        goto L_801D36BC;
    // 0x801D2EC8: nop

L_801D2ECC:
    // 0x801D2ECC: jal         0x800E4CDC
    // 0x801D2ED0: nop

    func_800E4CDC(rdram, ctx);
        goto after_100;
    // 0x801D2ED0: nop

    after_100:
    // 0x801D2ED4: andi        $t0, $v0, 0x100
    ctx->r8 = ctx->r2 & 0X100;
    // 0x801D2ED8: beq         $t0, $zero, L_801D36BC
    if (ctx->r8 == 0) {
        // 0x801D2EDC: nop
    
            goto L_801D36BC;
    }
    // 0x801D2EDC: nop

    // 0x801D2EE0: addiu       $t1, $zero, 0x6C61
    ctx->r9 = ADD32(0, 0X6C61);
    // 0x801D2EE4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D2EE8: sw          $t1, -0x2E34($at)
    MEM_W(-0X2E34, ctx->r1) = ctx->r9;
    // 0x801D2EEC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D2EF0: addiu       $t2, $zero, 0x1E3
    ctx->r10 = ADD32(0, 0X1E3);
    // 0x801D2EF4: sw          $t2, -0x2C04($at)
    MEM_W(-0X2C04, ctx->r1) = ctx->r10;
    // 0x801D2EF8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D2EFC: addiu       $t3, $zero, 0x148
    ctx->r11 = ADD32(0, 0X148);
    // 0x801D2F00: sw          $t3, -0x2BEC($at)
    MEM_W(-0X2BEC, ctx->r1) = ctx->r11;
    // 0x801D2F04: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D2F08: addiu       $t4, $zero, 0x1E3
    ctx->r12 = ADD32(0, 0X1E3);
    // 0x801D2F0C: jal         0x80172DC4
    // 0x801D2F10: sw          $t4, -0x2BF8($at)
    MEM_W(-0X2BF8, ctx->r1) = ctx->r12;
    func_80172DC4_1501A0(rdram, ctx);
        goto after_101;
    // 0x801D2F10: sw          $t4, -0x2BF8($at)
    MEM_W(-0X2BF8, ctx->r1) = ctx->r12;
    after_101:
    // 0x801D2F14: jal         0x80172E34
    // 0x801D2F18: nop

    func_80172E34_1501A0(rdram, ctx);
        goto after_102;
    // 0x801D2F18: nop

    after_102:
    // 0x801D2F1C: jal         0x80172F04
    // 0x801D2F20: nop

    func_80172F04_1501A0(rdram, ctx);
        goto after_103;
    // 0x801D2F20: nop

    after_103:
    // 0x801D2F24: addiu       $t5, $zero, 0x6C
    ctx->r13 = ADD32(0, 0X6C);
    // 0x801D2F28: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D2F2C: sw          $t5, -0x2B5C($at)
    MEM_W(-0X2B5C, ctx->r1) = ctx->r13;
    // 0x801D2F30: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D2F34: addiu       $t6, $zero, 0x68
    ctx->r14 = ADD32(0, 0X68);
    // 0x801D2F38: jal         0x80173538
    // 0x801D2F3C: sw          $t6, -0x2B50($at)
    MEM_W(-0X2B50, ctx->r1) = ctx->r14;
    func_80173538_1501A0(rdram, ctx);
        goto after_104;
    // 0x801D2F3C: sw          $t6, -0x2B50($at)
    MEM_W(-0X2B50, ctx->r1) = ctx->r14;
    after_104:
    // 0x801D2F40: jal         0x801735A8
    // 0x801D2F44: nop

    func_801735A8_1501A0(rdram, ctx);
        goto after_105;
    // 0x801D2F44: nop

    after_105:
    // 0x801D2F48: jal         0x801E2834
    // 0x801D2F4C: nop

    func_801E2834_1B66F0(rdram, ctx);
        goto after_106;
    // 0x801D2F4C: nop

    after_106:
    // 0x801D2F50: b           L_801D36BC
    // 0x801D2F54: nop

        goto L_801D36BC;
    // 0x801D2F54: nop

L_801D2F58:
    // 0x801D2F58: jal         0x800E4CDC
    // 0x801D2F5C: nop

    func_800E4CDC(rdram, ctx);
        goto after_107;
    // 0x801D2F5C: nop

    after_107:
    // 0x801D2F60: andi        $t7, $v0, 0x100
    ctx->r15 = ctx->r2 & 0X100;
    // 0x801D2F64: beq         $t7, $zero, L_801D36BC
    if (ctx->r15 == 0) {
        // 0x801D2F68: nop
    
            goto L_801D36BC;
    }
    // 0x801D2F68: nop

    // 0x801D2F6C: addiu       $t8, $zero, 0x715C
    ctx->r24 = ADD32(0, 0X715C);
    // 0x801D2F70: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D2F74: sw          $t8, -0x2E34($at)
    MEM_W(-0X2E34, ctx->r1) = ctx->r24;
    // 0x801D2F78: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D2F7C: addiu       $t9, $zero, 0x20A
    ctx->r25 = ADD32(0, 0X20A);
    // 0x801D2F80: sw          $t9, -0x2C04($at)
    MEM_W(-0X2C04, ctx->r1) = ctx->r25;
    // 0x801D2F84: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D2F88: addiu       $t0, $zero, 0x164
    ctx->r8 = ADD32(0, 0X164);
    // 0x801D2F8C: sw          $t0, -0x2BEC($at)
    MEM_W(-0X2BEC, ctx->r1) = ctx->r8;
    // 0x801D2F90: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D2F94: addiu       $t1, $zero, 0x20A
    ctx->r9 = ADD32(0, 0X20A);
    // 0x801D2F98: jal         0x80172DC4
    // 0x801D2F9C: sw          $t1, -0x2BF8($at)
    MEM_W(-0X2BF8, ctx->r1) = ctx->r9;
    func_80172DC4_1501A0(rdram, ctx);
        goto after_108;
    // 0x801D2F9C: sw          $t1, -0x2BF8($at)
    MEM_W(-0X2BF8, ctx->r1) = ctx->r9;
    after_108:
    // 0x801D2FA0: jal         0x80172E34
    // 0x801D2FA4: nop

    func_80172E34_1501A0(rdram, ctx);
        goto after_109;
    // 0x801D2FA4: nop

    after_109:
    // 0x801D2FA8: jal         0x80172F04
    // 0x801D2FAC: nop

    func_80172F04_1501A0(rdram, ctx);
        goto after_110;
    // 0x801D2FAC: nop

    after_110:
    // 0x801D2FB0: addiu       $t2, $zero, 0x74
    ctx->r10 = ADD32(0, 0X74);
    // 0x801D2FB4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D2FB8: sw          $t2, -0x2B5C($at)
    MEM_W(-0X2B5C, ctx->r1) = ctx->r10;
    // 0x801D2FBC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D2FC0: addiu       $t3, $zero, 0x70
    ctx->r11 = ADD32(0, 0X70);
    // 0x801D2FC4: jal         0x80173538
    // 0x801D2FC8: sw          $t3, -0x2B50($at)
    MEM_W(-0X2B50, ctx->r1) = ctx->r11;
    func_80173538_1501A0(rdram, ctx);
        goto after_111;
    // 0x801D2FC8: sw          $t3, -0x2B50($at)
    MEM_W(-0X2B50, ctx->r1) = ctx->r11;
    after_111:
    // 0x801D2FCC: jal         0x801735A8
    // 0x801D2FD0: nop

    func_801735A8_1501A0(rdram, ctx);
        goto after_112;
    // 0x801D2FD0: nop

    after_112:
    // 0x801D2FD4: jal         0x801E2834
    // 0x801D2FD8: nop

    func_801E2834_1B66F0(rdram, ctx);
        goto after_113;
    // 0x801D2FD8: nop

    after_113:
    // 0x801D2FDC: b           L_801D36BC
    // 0x801D2FE0: nop

        goto L_801D36BC;
    // 0x801D2FE0: nop

L_801D2FE4:
    // 0x801D2FE4: jal         0x800E4CDC
    // 0x801D2FE8: nop

    func_800E4CDC(rdram, ctx);
        goto after_114;
    // 0x801D2FE8: nop

    after_114:
    // 0x801D2FEC: andi        $t4, $v0, 0x100
    ctx->r12 = ctx->r2 & 0X100;
    // 0x801D2FF0: beq         $t4, $zero, L_801D36BC
    if (ctx->r12 == 0) {
        // 0x801D2FF4: nop
    
            goto L_801D36BC;
    }
    // 0x801D2FF4: nop

    // 0x801D2FF8: addiu       $t5, $zero, 0x7549
    ctx->r13 = ADD32(0, 0X7549);
    // 0x801D2FFC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D3000: sw          $t5, -0x2E34($at)
    MEM_W(-0X2E34, ctx->r1) = ctx->r13;
    // 0x801D3004: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D3008: addiu       $t6, $zero, 0x22D
    ctx->r14 = ADD32(0, 0X22D);
    // 0x801D300C: sw          $t6, -0x2C04($at)
    MEM_W(-0X2C04, ctx->r1) = ctx->r14;
    // 0x801D3010: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D3014: addiu       $t7, $zero, 0x17C
    ctx->r15 = ADD32(0, 0X17C);
    // 0x801D3018: sw          $t7, -0x2BEC($at)
    MEM_W(-0X2BEC, ctx->r1) = ctx->r15;
    // 0x801D301C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D3020: addiu       $t8, $zero, 0x22D
    ctx->r24 = ADD32(0, 0X22D);
    // 0x801D3024: jal         0x80172DC4
    // 0x801D3028: sw          $t8, -0x2BF8($at)
    MEM_W(-0X2BF8, ctx->r1) = ctx->r24;
    func_80172DC4_1501A0(rdram, ctx);
        goto after_115;
    // 0x801D3028: sw          $t8, -0x2BF8($at)
    MEM_W(-0X2BF8, ctx->r1) = ctx->r24;
    after_115:
    // 0x801D302C: jal         0x80172E34
    // 0x801D3030: nop

    func_80172E34_1501A0(rdram, ctx);
        goto after_116;
    // 0x801D3030: nop

    after_116:
    // 0x801D3034: jal         0x80172F04
    // 0x801D3038: nop

    func_80172F04_1501A0(rdram, ctx);
        goto after_117;
    // 0x801D3038: nop

    after_117:
    // 0x801D303C: addiu       $t9, $zero, 0x7D
    ctx->r25 = ADD32(0, 0X7D);
    // 0x801D3040: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D3044: sw          $t9, -0x2B5C($at)
    MEM_W(-0X2B5C, ctx->r1) = ctx->r25;
    // 0x801D3048: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D304C: addiu       $t0, $zero, 0x79
    ctx->r8 = ADD32(0, 0X79);
    // 0x801D3050: jal         0x80173538
    // 0x801D3054: sw          $t0, -0x2B50($at)
    MEM_W(-0X2B50, ctx->r1) = ctx->r8;
    func_80173538_1501A0(rdram, ctx);
        goto after_118;
    // 0x801D3054: sw          $t0, -0x2B50($at)
    MEM_W(-0X2B50, ctx->r1) = ctx->r8;
    after_118:
    // 0x801D3058: jal         0x801735A8
    // 0x801D305C: nop

    func_801735A8_1501A0(rdram, ctx);
        goto after_119;
    // 0x801D305C: nop

    after_119:
    // 0x801D3060: jal         0x801E2834
    // 0x801D3064: nop

    func_801E2834_1B66F0(rdram, ctx);
        goto after_120;
    // 0x801D3064: nop

    after_120:
    // 0x801D3068: b           L_801D36BC
    // 0x801D306C: nop

        goto L_801D36BC;
    // 0x801D306C: nop

L_801D3070:
    // 0x801D3070: jal         0x800E4CDC
    // 0x801D3074: nop

    func_800E4CDC(rdram, ctx);
        goto after_121;
    // 0x801D3074: nop

    after_121:
    // 0x801D3078: andi        $t1, $v0, 0x200
    ctx->r9 = ctx->r2 & 0X200;
    // 0x801D307C: beq         $t1, $zero, L_801D36BC
    if (ctx->r9 == 0) {
        // 0x801D3080: nop
    
            goto L_801D36BC;
    }
    // 0x801D3080: nop

    // 0x801D3084: addiu       $t2, $zero, 0x6EC8
    ctx->r10 = ADD32(0, 0X6EC8);
    // 0x801D3088: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D308C: sw          $t2, -0x2E34($at)
    MEM_W(-0X2E34, ctx->r1) = ctx->r10;
    // 0x801D3090: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D3094: addiu       $t3, $zero, 0x1F8
    ctx->r11 = ADD32(0, 0X1F8);
    // 0x801D3098: sw          $t3, -0x2C04($at)
    MEM_W(-0X2C04, ctx->r1) = ctx->r11;
    // 0x801D309C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D30A0: addiu       $t4, $zero, 0x159
    ctx->r12 = ADD32(0, 0X159);
    // 0x801D30A4: sw          $t4, -0x2BEC($at)
    MEM_W(-0X2BEC, ctx->r1) = ctx->r12;
    // 0x801D30A8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D30AC: addiu       $t5, $zero, 0x1F8
    ctx->r13 = ADD32(0, 0X1F8);
    // 0x801D30B0: jal         0x80172DC4
    // 0x801D30B4: sw          $t5, -0x2BF8($at)
    MEM_W(-0X2BF8, ctx->r1) = ctx->r13;
    func_80172DC4_1501A0(rdram, ctx);
        goto after_122;
    // 0x801D30B4: sw          $t5, -0x2BF8($at)
    MEM_W(-0X2BF8, ctx->r1) = ctx->r13;
    after_122:
    // 0x801D30B8: jal         0x80172E34
    // 0x801D30BC: nop

    func_80172E34_1501A0(rdram, ctx);
        goto after_123;
    // 0x801D30BC: nop

    after_123:
    // 0x801D30C0: jal         0x80172F04
    // 0x801D30C4: nop

    func_80172F04_1501A0(rdram, ctx);
        goto after_124;
    // 0x801D30C4: nop

    after_124:
    // 0x801D30C8: addiu       $t6, $zero, 0x6F
    ctx->r14 = ADD32(0, 0X6F);
    // 0x801D30CC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D30D0: sw          $t6, -0x2B5C($at)
    MEM_W(-0X2B5C, ctx->r1) = ctx->r14;
    // 0x801D30D4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D30D8: addiu       $t7, $zero, 0x6B
    ctx->r15 = ADD32(0, 0X6B);
    // 0x801D30DC: jal         0x80173538
    // 0x801D30E0: sw          $t7, -0x2B50($at)
    MEM_W(-0X2B50, ctx->r1) = ctx->r15;
    func_80173538_1501A0(rdram, ctx);
        goto after_125;
    // 0x801D30E0: sw          $t7, -0x2B50($at)
    MEM_W(-0X2B50, ctx->r1) = ctx->r15;
    after_125:
    // 0x801D30E4: jal         0x801735A8
    // 0x801D30E8: nop

    func_801735A8_1501A0(rdram, ctx);
        goto after_126;
    // 0x801D30E8: nop

    after_126:
    // 0x801D30EC: jal         0x801E2834
    // 0x801D30F0: nop

    func_801E2834_1B66F0(rdram, ctx);
        goto after_127;
    // 0x801D30F0: nop

    after_127:
    // 0x801D30F4: b           L_801D36BC
    // 0x801D30F8: nop

        goto L_801D36BC;
    // 0x801D30F8: nop

L_801D30FC:
    // 0x801D30FC: jal         0x800E4CDC
    // 0x801D3100: nop

    func_800E4CDC(rdram, ctx);
        goto after_128;
    // 0x801D3100: nop

    after_128:
    // 0x801D3104: andi        $t8, $v0, 0x400
    ctx->r24 = ctx->r2 & 0X400;
    // 0x801D3108: beq         $t8, $zero, L_801D36BC
    if (ctx->r24 == 0) {
        // 0x801D310C: nop
    
            goto L_801D36BC;
    }
    // 0x801D310C: nop

    // 0x801D3110: addiu       $t9, $zero, 0x6950
    ctx->r25 = ADD32(0, 0X6950);
    // 0x801D3114: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D3118: sw          $t9, -0x2E34($at)
    MEM_W(-0X2E34, ctx->r1) = ctx->r25;
    // 0x801D311C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D3120: addiu       $t0, $zero, 0x1CB
    ctx->r8 = ADD32(0, 0X1CB);
    // 0x801D3124: sw          $t0, -0x2C04($at)
    MEM_W(-0X2C04, ctx->r1) = ctx->r8;
    // 0x801D3128: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D312C: addiu       $t1, $zero, 0x134
    ctx->r9 = ADD32(0, 0X134);
    // 0x801D3130: sw          $t1, -0x2BEC($at)
    MEM_W(-0X2BEC, ctx->r1) = ctx->r9;
    // 0x801D3134: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D3138: addiu       $t2, $zero, 0x1CB
    ctx->r10 = ADD32(0, 0X1CB);
    // 0x801D313C: jal         0x80172DC4
    // 0x801D3140: sw          $t2, -0x2BF8($at)
    MEM_W(-0X2BF8, ctx->r1) = ctx->r10;
    func_80172DC4_1501A0(rdram, ctx);
        goto after_129;
    // 0x801D3140: sw          $t2, -0x2BF8($at)
    MEM_W(-0X2BF8, ctx->r1) = ctx->r10;
    after_129:
    // 0x801D3144: jal         0x80172E34
    // 0x801D3148: nop

    func_80172E34_1501A0(rdram, ctx);
        goto after_130;
    // 0x801D3148: nop

    after_130:
    // 0x801D314C: jal         0x80172F04
    // 0x801D3150: nop

    func_80172F04_1501A0(rdram, ctx);
        goto after_131;
    // 0x801D3150: nop

    after_131:
    // 0x801D3154: addiu       $t3, $zero, 0x69
    ctx->r11 = ADD32(0, 0X69);
    // 0x801D3158: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D315C: sw          $t3, -0x2B5C($at)
    MEM_W(-0X2B5C, ctx->r1) = ctx->r11;
    // 0x801D3160: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D3164: addiu       $t4, $zero, 0x65
    ctx->r12 = ADD32(0, 0X65);
    // 0x801D3168: jal         0x80173538
    // 0x801D316C: sw          $t4, -0x2B50($at)
    MEM_W(-0X2B50, ctx->r1) = ctx->r12;
    func_80173538_1501A0(rdram, ctx);
        goto after_132;
    // 0x801D316C: sw          $t4, -0x2B50($at)
    MEM_W(-0X2B50, ctx->r1) = ctx->r12;
    after_132:
    // 0x801D3170: jal         0x801735A8
    // 0x801D3174: nop

    func_801735A8_1501A0(rdram, ctx);
        goto after_133;
    // 0x801D3174: nop

    after_133:
    // 0x801D3178: jal         0x801E2834
    // 0x801D317C: nop

    func_801E2834_1B66F0(rdram, ctx);
        goto after_134;
    // 0x801D317C: nop

    after_134:
    // 0x801D3180: b           L_801D36BC
    // 0x801D3184: nop

        goto L_801D36BC;
    // 0x801D3184: nop

L_801D3188:
    // 0x801D3188: jal         0x800E4CDC
    // 0x801D318C: nop

    func_800E4CDC(rdram, ctx);
        goto after_135;
    // 0x801D318C: nop

    after_135:
    // 0x801D3190: andi        $t5, $v0, 0x800
    ctx->r13 = ctx->r2 & 0X800;
    // 0x801D3194: beq         $t5, $zero, L_801D36BC
    if (ctx->r13 == 0) {
        // 0x801D3198: nop
    
            goto L_801D36BC;
    }
    // 0x801D3198: nop

    // 0x801D319C: addiu       $t6, $zero, 0x7A8A
    ctx->r14 = ADD32(0, 0X7A8A);
    // 0x801D31A0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D31A4: sw          $t6, -0x2E34($at)
    MEM_W(-0X2E34, ctx->r1) = ctx->r14;
    // 0x801D31A8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D31AC: addiu       $t7, $zero, 0x24B
    ctx->r15 = ADD32(0, 0X24B);
    // 0x801D31B0: sw          $t7, -0x2C04($at)
    MEM_W(-0X2C04, ctx->r1) = ctx->r15;
    // 0x801D31B4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D31B8: addiu       $t8, $zero, 0x195
    ctx->r24 = ADD32(0, 0X195);
    // 0x801D31BC: sw          $t8, -0x2BEC($at)
    MEM_W(-0X2BEC, ctx->r1) = ctx->r24;
    // 0x801D31C0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D31C4: addiu       $t9, $zero, 0x24B
    ctx->r25 = ADD32(0, 0X24B);
    // 0x801D31C8: jal         0x80172DC4
    // 0x801D31CC: sw          $t9, -0x2BF8($at)
    MEM_W(-0X2BF8, ctx->r1) = ctx->r25;
    func_80172DC4_1501A0(rdram, ctx);
        goto after_136;
    // 0x801D31CC: sw          $t9, -0x2BF8($at)
    MEM_W(-0X2BF8, ctx->r1) = ctx->r25;
    after_136:
    // 0x801D31D0: jal         0x80172E34
    // 0x801D31D4: nop

    func_80172E34_1501A0(rdram, ctx);
        goto after_137;
    // 0x801D31D4: nop

    after_137:
    // 0x801D31D8: jal         0x80172F04
    // 0x801D31DC: nop

    func_80172F04_1501A0(rdram, ctx);
        goto after_138;
    // 0x801D31DC: nop

    after_138:
    // 0x801D31E0: addiu       $t0, $zero, 0x89
    ctx->r8 = ADD32(0, 0X89);
    // 0x801D31E4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D31E8: sw          $t0, -0x2B5C($at)
    MEM_W(-0X2B5C, ctx->r1) = ctx->r8;
    // 0x801D31EC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D31F0: addiu       $t1, $zero, 0x85
    ctx->r9 = ADD32(0, 0X85);
    // 0x801D31F4: jal         0x80173538
    // 0x801D31F8: sw          $t1, -0x2B50($at)
    MEM_W(-0X2B50, ctx->r1) = ctx->r9;
    func_80173538_1501A0(rdram, ctx);
        goto after_139;
    // 0x801D31F8: sw          $t1, -0x2B50($at)
    MEM_W(-0X2B50, ctx->r1) = ctx->r9;
    after_139:
    // 0x801D31FC: jal         0x801735A8
    // 0x801D3200: nop

    func_801735A8_1501A0(rdram, ctx);
        goto after_140;
    // 0x801D3200: nop

    after_140:
    // 0x801D3204: jal         0x801E2834
    // 0x801D3208: nop

    func_801E2834_1B66F0(rdram, ctx);
        goto after_141;
    // 0x801D3208: nop

    after_141:
    // 0x801D320C: b           L_801D36BC
    // 0x801D3210: nop

        goto L_801D36BC;
    // 0x801D3210: nop

L_801D3214:
    // 0x801D3214: addiu       $t2, $zero, 0x67C
    ctx->r10 = ADD32(0, 0X67C);
    // 0x801D3218: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D321C: sw          $t2, -0x2E34($at)
    MEM_W(-0X2E34, ctx->r1) = ctx->r10;
    // 0x801D3220: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D3224: addiu       $t3, $zero, 0x34
    ctx->r11 = ADD32(0, 0X34);
    // 0x801D3228: sw          $t3, -0x2C04($at)
    MEM_W(-0X2C04, ctx->r1) = ctx->r11;
    // 0x801D322C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D3230: addiu       $t4, $zero, 0x2B
    ctx->r12 = ADD32(0, 0X2B);
    // 0x801D3234: sw          $t4, -0x2BEC($at)
    MEM_W(-0X2BEC, ctx->r1) = ctx->r12;
    // 0x801D3238: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D323C: addiu       $t5, $zero, 0x34
    ctx->r13 = ADD32(0, 0X34);
    // 0x801D3240: jal         0x80172DC4
    // 0x801D3244: sw          $t5, -0x2BF8($at)
    MEM_W(-0X2BF8, ctx->r1) = ctx->r13;
    func_80172DC4_1501A0(rdram, ctx);
        goto after_142;
    // 0x801D3244: sw          $t5, -0x2BF8($at)
    MEM_W(-0X2BF8, ctx->r1) = ctx->r13;
    after_142:
    // 0x801D3248: jal         0x80172E34
    // 0x801D324C: nop

    func_80172E34_1501A0(rdram, ctx);
        goto after_143;
    // 0x801D324C: nop

    after_143:
    // 0x801D3250: jal         0x80172F04
    // 0x801D3254: nop

    func_80172F04_1501A0(rdram, ctx);
        goto after_144;
    // 0x801D3254: nop

    after_144:
    // 0x801D3258: addiu       $t6, $zero, 0x23
    ctx->r14 = ADD32(0, 0X23);
    // 0x801D325C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D3260: sw          $t6, -0x2B5C($at)
    MEM_W(-0X2B5C, ctx->r1) = ctx->r14;
    // 0x801D3264: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D3268: addiu       $t7, $zero, 0x24
    ctx->r15 = ADD32(0, 0X24);
    // 0x801D326C: jal         0x80173538
    // 0x801D3270: sw          $t7, -0x2B50($at)
    MEM_W(-0X2B50, ctx->r1) = ctx->r15;
    func_80173538_1501A0(rdram, ctx);
        goto after_145;
    // 0x801D3270: sw          $t7, -0x2B50($at)
    MEM_W(-0X2B50, ctx->r1) = ctx->r15;
    after_145:
    // 0x801D3274: jal         0x801735A8
    // 0x801D3278: nop

    func_801735A8_1501A0(rdram, ctx);
        goto after_146;
    // 0x801D3278: nop

    after_146:
    // 0x801D327C: jal         0x801E2834
    // 0x801D3280: nop

    func_801E2834_1B66F0(rdram, ctx);
        goto after_147;
    // 0x801D3280: nop

    after_147:
    // 0x801D3284: b           L_801D36BC
    // 0x801D3288: nop

        goto L_801D36BC;
    // 0x801D3288: nop

L_801D328C:
    // 0x801D328C: addiu       $t8, $zero, 0x730
    ctx->r24 = ADD32(0, 0X730);
    // 0x801D3290: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D3294: sw          $t8, -0x2E34($at)
    MEM_W(-0X2E34, ctx->r1) = ctx->r24;
    // 0x801D3298: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D329C: addiu       $t9, $zero, 0x3C
    ctx->r25 = ADD32(0, 0X3C);
    // 0x801D32A0: sw          $t9, -0x2C04($at)
    MEM_W(-0X2C04, ctx->r1) = ctx->r25;
    // 0x801D32A4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D32A8: addiu       $t0, $zero, 0x32
    ctx->r8 = ADD32(0, 0X32);
    // 0x801D32AC: sw          $t0, -0x2BEC($at)
    MEM_W(-0X2BEC, ctx->r1) = ctx->r8;
    // 0x801D32B0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D32B4: addiu       $t1, $zero, 0x3C
    ctx->r9 = ADD32(0, 0X3C);
    // 0x801D32B8: jal         0x80172DC4
    // 0x801D32BC: sw          $t1, -0x2BF8($at)
    MEM_W(-0X2BF8, ctx->r1) = ctx->r9;
    func_80172DC4_1501A0(rdram, ctx);
        goto after_148;
    // 0x801D32BC: sw          $t1, -0x2BF8($at)
    MEM_W(-0X2BF8, ctx->r1) = ctx->r9;
    after_148:
    // 0x801D32C0: jal         0x80172E34
    // 0x801D32C4: nop

    func_80172E34_1501A0(rdram, ctx);
        goto after_149;
    // 0x801D32C4: nop

    after_149:
    // 0x801D32C8: jal         0x80172F04
    // 0x801D32CC: nop

    func_80172F04_1501A0(rdram, ctx);
        goto after_150;
    // 0x801D32CC: nop

    after_150:
    // 0x801D32D0: addiu       $t2, $zero, 0x27
    ctx->r10 = ADD32(0, 0X27);
    // 0x801D32D4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D32D8: sw          $t2, -0x2B5C($at)
    MEM_W(-0X2B5C, ctx->r1) = ctx->r10;
    // 0x801D32DC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D32E0: addiu       $t3, $zero, 0x28
    ctx->r11 = ADD32(0, 0X28);
    // 0x801D32E4: jal         0x80173538
    // 0x801D32E8: sw          $t3, -0x2B50($at)
    MEM_W(-0X2B50, ctx->r1) = ctx->r11;
    func_80173538_1501A0(rdram, ctx);
        goto after_151;
    // 0x801D32E8: sw          $t3, -0x2B50($at)
    MEM_W(-0X2B50, ctx->r1) = ctx->r11;
    after_151:
    // 0x801D32EC: jal         0x801735A8
    // 0x801D32F0: nop

    func_801735A8_1501A0(rdram, ctx);
        goto after_152;
    // 0x801D32F0: nop

    after_152:
    // 0x801D32F4: jal         0x801E2834
    // 0x801D32F8: nop

    func_801E2834_1B66F0(rdram, ctx);
        goto after_153;
    // 0x801D32F8: nop

    after_153:
    // 0x801D32FC: b           L_801D36BC
    // 0x801D3300: nop

        goto L_801D36BC;
    // 0x801D3300: nop

L_801D3304:
    // 0x801D3304: addiu       $t4, $zero, 0x1266
    ctx->r12 = ADD32(0, 0X1266);
    // 0x801D3308: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D330C: sw          $t4, -0x2E34($at)
    MEM_W(-0X2E34, ctx->r1) = ctx->r12;
    // 0x801D3310: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D3314: addiu       $t5, $zero, 0x99
    ctx->r13 = ADD32(0, 0X99);
    // 0x801D3318: sw          $t5, -0x2C04($at)
    MEM_W(-0X2C04, ctx->r1) = ctx->r13;
    // 0x801D331C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D3320: addiu       $t6, $zero, 0x6F
    ctx->r14 = ADD32(0, 0X6F);
    // 0x801D3324: sw          $t6, -0x2BEC($at)
    MEM_W(-0X2BEC, ctx->r1) = ctx->r14;
    // 0x801D3328: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D332C: addiu       $t7, $zero, 0x99
    ctx->r15 = ADD32(0, 0X99);
    // 0x801D3330: jal         0x80172DC4
    // 0x801D3334: sw          $t7, -0x2BF8($at)
    MEM_W(-0X2BF8, ctx->r1) = ctx->r15;
    func_80172DC4_1501A0(rdram, ctx);
        goto after_154;
    // 0x801D3334: sw          $t7, -0x2BF8($at)
    MEM_W(-0X2BF8, ctx->r1) = ctx->r15;
    after_154:
    // 0x801D3338: jal         0x80172E34
    // 0x801D333C: nop

    func_80172E34_1501A0(rdram, ctx);
        goto after_155;
    // 0x801D333C: nop

    after_155:
    // 0x801D3340: jal         0x80172F04
    // 0x801D3344: nop

    func_80172F04_1501A0(rdram, ctx);
        goto after_156;
    // 0x801D3344: nop

    after_156:
    // 0x801D3348: addiu       $t8, $zero, 0x30
    ctx->r24 = ADD32(0, 0X30);
    // 0x801D334C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D3350: sw          $t8, -0x2B5C($at)
    MEM_W(-0X2B5C, ctx->r1) = ctx->r24;
    // 0x801D3354: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D3358: addiu       $t9, $zero, 0x31
    ctx->r25 = ADD32(0, 0X31);
    // 0x801D335C: jal         0x80173538
    // 0x801D3360: sw          $t9, -0x2B50($at)
    MEM_W(-0X2B50, ctx->r1) = ctx->r25;
    func_80173538_1501A0(rdram, ctx);
        goto after_157;
    // 0x801D3360: sw          $t9, -0x2B50($at)
    MEM_W(-0X2B50, ctx->r1) = ctx->r25;
    after_157:
    // 0x801D3364: jal         0x801735A8
    // 0x801D3368: nop

    func_801735A8_1501A0(rdram, ctx);
        goto after_158;
    // 0x801D3368: nop

    after_158:
    // 0x801D336C: jal         0x801E2834
    // 0x801D3370: nop

    func_801E2834_1B66F0(rdram, ctx);
        goto after_159;
    // 0x801D3370: nop

    after_159:
    // 0x801D3374: b           L_801D36BC
    // 0x801D3378: nop

        goto L_801D36BC;
    // 0x801D3378: nop

L_801D337C:
    // 0x801D337C: addiu       $t0, $zero, 0x127A
    ctx->r8 = ADD32(0, 0X127A);
    // 0x801D3380: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D3384: sw          $t0, -0x2E34($at)
    MEM_W(-0X2E34, ctx->r1) = ctx->r8;
    // 0x801D3388: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D338C: addiu       $t1, $zero, 0x9A
    ctx->r9 = ADD32(0, 0X9A);
    // 0x801D3390: sw          $t1, -0x2C04($at)
    MEM_W(-0X2C04, ctx->r1) = ctx->r9;
    // 0x801D3394: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D3398: addiu       $t2, $zero, 0x70
    ctx->r10 = ADD32(0, 0X70);
    // 0x801D339C: sw          $t2, -0x2BEC($at)
    MEM_W(-0X2BEC, ctx->r1) = ctx->r10;
    // 0x801D33A0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D33A4: addiu       $t3, $zero, 0x9A
    ctx->r11 = ADD32(0, 0X9A);
    // 0x801D33A8: jal         0x80172DC4
    // 0x801D33AC: sw          $t3, -0x2BF8($at)
    MEM_W(-0X2BF8, ctx->r1) = ctx->r11;
    func_80172DC4_1501A0(rdram, ctx);
        goto after_160;
    // 0x801D33AC: sw          $t3, -0x2BF8($at)
    MEM_W(-0X2BF8, ctx->r1) = ctx->r11;
    after_160:
    // 0x801D33B0: jal         0x80172E34
    // 0x801D33B4: nop

    func_80172E34_1501A0(rdram, ctx);
        goto after_161;
    // 0x801D33B4: nop

    after_161:
    // 0x801D33B8: jal         0x80172F04
    // 0x801D33BC: nop

    func_80172F04_1501A0(rdram, ctx);
        goto after_162;
    // 0x801D33BC: nop

    after_162:
    // 0x801D33C0: addiu       $t4, $zero, 0x31
    ctx->r12 = ADD32(0, 0X31);
    // 0x801D33C4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D33C8: sw          $t4, -0x2B5C($at)
    MEM_W(-0X2B5C, ctx->r1) = ctx->r12;
    // 0x801D33CC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D33D0: addiu       $t5, $zero, 0x32
    ctx->r13 = ADD32(0, 0X32);
    // 0x801D33D4: jal         0x80173538
    // 0x801D33D8: sw          $t5, -0x2B50($at)
    MEM_W(-0X2B50, ctx->r1) = ctx->r13;
    func_80173538_1501A0(rdram, ctx);
        goto after_163;
    // 0x801D33D8: sw          $t5, -0x2B50($at)
    MEM_W(-0X2B50, ctx->r1) = ctx->r13;
    after_163:
    // 0x801D33DC: jal         0x801735A8
    // 0x801D33E0: nop

    func_801735A8_1501A0(rdram, ctx);
        goto after_164;
    // 0x801D33E0: nop

    after_164:
    // 0x801D33E4: jal         0x801E2834
    // 0x801D33E8: nop

    func_801E2834_1B66F0(rdram, ctx);
        goto after_165;
    // 0x801D33E8: nop

    after_165:
    // 0x801D33EC: b           L_801D36BC
    // 0x801D33F0: nop

        goto L_801D36BC;
    // 0x801D33F0: nop

L_801D33F4:
    // 0x801D33F4: addiu       $t6, $zero, 0xB3B
    ctx->r14 = ADD32(0, 0XB3B);
    // 0x801D33F8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D33FC: sw          $t6, -0x2E34($at)
    MEM_W(-0X2E34, ctx->r1) = ctx->r14;
    // 0x801D3400: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D3404: addiu       $t7, $zero, 0x63
    ctx->r15 = ADD32(0, 0X63);
    // 0x801D3408: sw          $t7, -0x2C04($at)
    MEM_W(-0X2C04, ctx->r1) = ctx->r15;
    // 0x801D340C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D3410: addiu       $t8, $zero, 0x50
    ctx->r24 = ADD32(0, 0X50);
    // 0x801D3414: sw          $t8, -0x2BEC($at)
    MEM_W(-0X2BEC, ctx->r1) = ctx->r24;
    // 0x801D3418: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D341C: addiu       $t9, $zero, 0x63
    ctx->r25 = ADD32(0, 0X63);
    // 0x801D3420: jal         0x80172DC4
    // 0x801D3424: sw          $t9, -0x2BF8($at)
    MEM_W(-0X2BF8, ctx->r1) = ctx->r25;
    func_80172DC4_1501A0(rdram, ctx);
        goto after_166;
    // 0x801D3424: sw          $t9, -0x2BF8($at)
    MEM_W(-0X2BF8, ctx->r1) = ctx->r25;
    after_166:
    // 0x801D3428: jal         0x80172E34
    // 0x801D342C: nop

    func_80172E34_1501A0(rdram, ctx);
        goto after_167;
    // 0x801D342C: nop

    after_167:
    // 0x801D3430: jal         0x80172F04
    // 0x801D3434: nop

    func_80172F04_1501A0(rdram, ctx);
        goto after_168;
    // 0x801D3434: nop

    after_168:
    // 0x801D3438: addiu       $t0, $zero, 0x2D
    ctx->r8 = ADD32(0, 0X2D);
    // 0x801D343C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D3440: sw          $t0, -0x2B5C($at)
    MEM_W(-0X2B5C, ctx->r1) = ctx->r8;
    // 0x801D3444: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D3448: addiu       $t1, $zero, 0x2E
    ctx->r9 = ADD32(0, 0X2E);
    // 0x801D344C: jal         0x80173538
    // 0x801D3450: sw          $t1, -0x2B50($at)
    MEM_W(-0X2B50, ctx->r1) = ctx->r9;
    func_80173538_1501A0(rdram, ctx);
        goto after_169;
    // 0x801D3450: sw          $t1, -0x2B50($at)
    MEM_W(-0X2B50, ctx->r1) = ctx->r9;
    after_169:
    // 0x801D3454: jal         0x801735A8
    // 0x801D3458: nop

    func_801735A8_1501A0(rdram, ctx);
        goto after_170;
    // 0x801D3458: nop

    after_170:
    // 0x801D345C: jal         0x801E2834
    // 0x801D3460: nop

    func_801E2834_1B66F0(rdram, ctx);
        goto after_171;
    // 0x801D3460: nop

    after_171:
    // 0x801D3464: b           L_801D36BC
    // 0x801D3468: nop

        goto L_801D36BC;
    // 0x801D3468: nop

L_801D346C:
    // 0x801D346C: addiu       $t2, $zero, 0x56E
    ctx->r10 = ADD32(0, 0X56E);
    // 0x801D3470: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D3474: sw          $t2, -0x2E34($at)
    MEM_W(-0X2E34, ctx->r1) = ctx->r10;
    // 0x801D3478: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D347C: addiu       $t3, $zero, 0x2A
    ctx->r11 = ADD32(0, 0X2A);
    // 0x801D3480: sw          $t3, -0x2C04($at)
    MEM_W(-0X2C04, ctx->r1) = ctx->r11;
    // 0x801D3484: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D3488: addiu       $t4, $zero, 0x21
    ctx->r12 = ADD32(0, 0X21);
    // 0x801D348C: sw          $t4, -0x2BEC($at)
    MEM_W(-0X2BEC, ctx->r1) = ctx->r12;
    // 0x801D3490: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D3494: addiu       $t5, $zero, 0x2A
    ctx->r13 = ADD32(0, 0X2A);
    // 0x801D3498: jal         0x80172DC4
    // 0x801D349C: sw          $t5, -0x2BF8($at)
    MEM_W(-0X2BF8, ctx->r1) = ctx->r13;
    func_80172DC4_1501A0(rdram, ctx);
        goto after_172;
    // 0x801D349C: sw          $t5, -0x2BF8($at)
    MEM_W(-0X2BF8, ctx->r1) = ctx->r13;
    after_172:
    // 0x801D34A0: jal         0x80172E34
    // 0x801D34A4: nop

    func_80172E34_1501A0(rdram, ctx);
        goto after_173;
    // 0x801D34A4: nop

    after_173:
    // 0x801D34A8: jal         0x80172F04
    // 0x801D34AC: nop

    func_80172F04_1501A0(rdram, ctx);
        goto after_174;
    // 0x801D34AC: nop

    after_174:
    // 0x801D34B0: addiu       $t6, $zero, 0x21
    ctx->r14 = ADD32(0, 0X21);
    // 0x801D34B4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D34B8: sw          $t6, -0x2B5C($at)
    MEM_W(-0X2B5C, ctx->r1) = ctx->r14;
    // 0x801D34BC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D34C0: addiu       $t7, $zero, 0x22
    ctx->r15 = ADD32(0, 0X22);
    // 0x801D34C4: jal         0x80173538
    // 0x801D34C8: sw          $t7, -0x2B50($at)
    MEM_W(-0X2B50, ctx->r1) = ctx->r15;
    func_80173538_1501A0(rdram, ctx);
        goto after_175;
    // 0x801D34C8: sw          $t7, -0x2B50($at)
    MEM_W(-0X2B50, ctx->r1) = ctx->r15;
    after_175:
    // 0x801D34CC: jal         0x801735A8
    // 0x801D34D0: nop

    func_801735A8_1501A0(rdram, ctx);
        goto after_176;
    // 0x801D34D0: nop

    after_176:
    // 0x801D34D4: jal         0x801E2834
    // 0x801D34D8: nop

    func_801E2834_1B66F0(rdram, ctx);
        goto after_177;
    // 0x801D34D8: nop

    after_177:
    // 0x801D34DC: b           L_801D36BC
    // 0x801D34E0: nop

        goto L_801D36BC;
    // 0x801D34E0: nop

L_801D34E4:
    // 0x801D34E4: addiu       $t8, $zero, 0x92E
    ctx->r24 = ADD32(0, 0X92E);
    // 0x801D34E8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D34EC: sw          $t8, -0x2E34($at)
    MEM_W(-0X2E34, ctx->r1) = ctx->r24;
    // 0x801D34F0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D34F4: addiu       $t9, $zero, 0x4E
    ctx->r25 = ADD32(0, 0X4E);
    // 0x801D34F8: sw          $t9, -0x2C04($at)
    MEM_W(-0X2C04, ctx->r1) = ctx->r25;
    // 0x801D34FC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D3500: addiu       $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
    // 0x801D3504: sw          $t0, -0x2BEC($at)
    MEM_W(-0X2BEC, ctx->r1) = ctx->r8;
    // 0x801D3508: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D350C: addiu       $t1, $zero, 0x4E
    ctx->r9 = ADD32(0, 0X4E);
    // 0x801D3510: jal         0x80172DC4
    // 0x801D3514: sw          $t1, -0x2BF8($at)
    MEM_W(-0X2BF8, ctx->r1) = ctx->r9;
    func_80172DC4_1501A0(rdram, ctx);
        goto after_178;
    // 0x801D3514: sw          $t1, -0x2BF8($at)
    MEM_W(-0X2BF8, ctx->r1) = ctx->r9;
    after_178:
    // 0x801D3518: jal         0x80172E34
    // 0x801D351C: nop

    func_80172E34_1501A0(rdram, ctx);
        goto after_179;
    // 0x801D351C: nop

    after_179:
    // 0x801D3520: jal         0x80172F04
    // 0x801D3524: nop

    func_80172F04_1501A0(rdram, ctx);
        goto after_180;
    // 0x801D3524: nop

    after_180:
    // 0x801D3528: addiu       $t2, $zero, 0x2B
    ctx->r10 = ADD32(0, 0X2B);
    // 0x801D352C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D3530: sw          $t2, -0x2B5C($at)
    MEM_W(-0X2B5C, ctx->r1) = ctx->r10;
    // 0x801D3534: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D3538: addiu       $t3, $zero, 0x2C
    ctx->r11 = ADD32(0, 0X2C);
    // 0x801D353C: jal         0x80173538
    // 0x801D3540: sw          $t3, -0x2B50($at)
    MEM_W(-0X2B50, ctx->r1) = ctx->r11;
    func_80173538_1501A0(rdram, ctx);
        goto after_181;
    // 0x801D3540: sw          $t3, -0x2B50($at)
    MEM_W(-0X2B50, ctx->r1) = ctx->r11;
    after_181:
    // 0x801D3544: jal         0x801735A8
    // 0x801D3548: nop

    func_801735A8_1501A0(rdram, ctx);
        goto after_182;
    // 0x801D3548: nop

    after_182:
    // 0x801D354C: jal         0x801E2834
    // 0x801D3550: nop

    func_801E2834_1B66F0(rdram, ctx);
        goto after_183;
    // 0x801D3550: nop

    after_183:
    // 0x801D3554: b           L_801D36BC
    // 0x801D3558: nop

        goto L_801D36BC;
    // 0x801D3558: nop

L_801D355C:
    // 0x801D355C: addiu       $t4, $zero, 0x55C8
    ctx->r12 = ADD32(0, 0X55C8);
    // 0x801D3560: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D3564: sw          $t4, -0x2E34($at)
    MEM_W(-0X2E34, ctx->r1) = ctx->r12;
    // 0x801D3568: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D356C: addiu       $t5, $zero, 0x138
    ctx->r13 = ADD32(0, 0X138);
    // 0x801D3570: sw          $t5, -0x2C04($at)
    MEM_W(-0X2C04, ctx->r1) = ctx->r13;
    // 0x801D3574: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D3578: addiu       $t6, $zero, 0xE0
    ctx->r14 = ADD32(0, 0XE0);
    // 0x801D357C: sw          $t6, -0x2BEC($at)
    MEM_W(-0X2BEC, ctx->r1) = ctx->r14;
    // 0x801D3580: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D3584: addiu       $t7, $zero, 0x138
    ctx->r15 = ADD32(0, 0X138);
    // 0x801D3588: jal         0x80172DC4
    // 0x801D358C: sw          $t7, -0x2BF8($at)
    MEM_W(-0X2BF8, ctx->r1) = ctx->r15;
    func_80172DC4_1501A0(rdram, ctx);
        goto after_184;
    // 0x801D358C: sw          $t7, -0x2BF8($at)
    MEM_W(-0X2BF8, ctx->r1) = ctx->r15;
    after_184:
    // 0x801D3590: jal         0x80172E34
    // 0x801D3594: nop

    func_80172E34_1501A0(rdram, ctx);
        goto after_185;
    // 0x801D3594: nop

    after_185:
    // 0x801D3598: jal         0x80172F04
    // 0x801D359C: nop

    func_80172F04_1501A0(rdram, ctx);
        goto after_186;
    // 0x801D359C: nop

    after_186:
    // 0x801D35A0: addiu       $t8, $zero, 0x4F
    ctx->r24 = ADD32(0, 0X4F);
    // 0x801D35A4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D35A8: sw          $t8, -0x2B5C($at)
    MEM_W(-0X2B5C, ctx->r1) = ctx->r24;
    // 0x801D35AC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D35B0: addiu       $t9, $zero, 0x4B
    ctx->r25 = ADD32(0, 0X4B);
    // 0x801D35B4: jal         0x80173538
    // 0x801D35B8: sw          $t9, -0x2B50($at)
    MEM_W(-0X2B50, ctx->r1) = ctx->r25;
    func_80173538_1501A0(rdram, ctx);
        goto after_187;
    // 0x801D35B8: sw          $t9, -0x2B50($at)
    MEM_W(-0X2B50, ctx->r1) = ctx->r25;
    after_187:
    // 0x801D35BC: jal         0x801735A8
    // 0x801D35C0: nop

    func_801735A8_1501A0(rdram, ctx);
        goto after_188;
    // 0x801D35C0: nop

    after_188:
    // 0x801D35C4: jal         0x801E2834
    // 0x801D35C8: nop

    func_801E2834_1B66F0(rdram, ctx);
        goto after_189;
    // 0x801D35C8: nop

    after_189:
    // 0x801D35CC: b           L_801D36BC
    // 0x801D35D0: nop

        goto L_801D36BC;
    // 0x801D35D0: nop

L_801D35D4:
    // 0x801D35D4: addiu       $t0, $zero, 0x5B0E
    ctx->r8 = ADD32(0, 0X5B0E);
    // 0x801D35D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D35DC: sw          $t0, -0x2E34($at)
    MEM_W(-0X2E34, ctx->r1) = ctx->r8;
    // 0x801D35E0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D35E4: addiu       $t1, $zero, 0x156
    ctx->r9 = ADD32(0, 0X156);
    // 0x801D35E8: sw          $t1, -0x2C04($at)
    MEM_W(-0X2C04, ctx->r1) = ctx->r9;
    // 0x801D35EC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D35F0: addiu       $t2, $zero, 0xF7
    ctx->r10 = ADD32(0, 0XF7);
    // 0x801D35F4: sw          $t2, -0x2BEC($at)
    MEM_W(-0X2BEC, ctx->r1) = ctx->r10;
    // 0x801D35F8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D35FC: addiu       $t3, $zero, 0x156
    ctx->r11 = ADD32(0, 0X156);
    // 0x801D3600: jal         0x80172DC4
    // 0x801D3604: sw          $t3, -0x2BF8($at)
    MEM_W(-0X2BF8, ctx->r1) = ctx->r11;
    func_80172DC4_1501A0(rdram, ctx);
        goto after_190;
    // 0x801D3604: sw          $t3, -0x2BF8($at)
    MEM_W(-0X2BF8, ctx->r1) = ctx->r11;
    after_190:
    // 0x801D3608: jal         0x80172E34
    // 0x801D360C: nop

    func_80172E34_1501A0(rdram, ctx);
        goto after_191;
    // 0x801D360C: nop

    after_191:
    // 0x801D3610: jal         0x80172F04
    // 0x801D3614: nop

    func_80172F04_1501A0(rdram, ctx);
        goto after_192;
    // 0x801D3614: nop

    after_192:
    // 0x801D3618: addiu       $t4, $zero, 0x5D
    ctx->r12 = ADD32(0, 0X5D);
    // 0x801D361C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D3620: sw          $t4, -0x2B5C($at)
    MEM_W(-0X2B5C, ctx->r1) = ctx->r12;
    // 0x801D3624: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D3628: addiu       $t5, $zero, 0x59
    ctx->r13 = ADD32(0, 0X59);
    // 0x801D362C: jal         0x80173538
    // 0x801D3630: sw          $t5, -0x2B50($at)
    MEM_W(-0X2B50, ctx->r1) = ctx->r13;
    func_80173538_1501A0(rdram, ctx);
        goto after_193;
    // 0x801D3630: sw          $t5, -0x2B50($at)
    MEM_W(-0X2B50, ctx->r1) = ctx->r13;
    after_193:
    // 0x801D3634: jal         0x801735A8
    // 0x801D3638: nop

    func_801735A8_1501A0(rdram, ctx);
        goto after_194;
    // 0x801D3638: nop

    after_194:
    // 0x801D363C: jal         0x801E2834
    // 0x801D3640: nop

    func_801E2834_1B66F0(rdram, ctx);
        goto after_195;
    // 0x801D3640: nop

    after_195:
    // 0x801D3644: b           L_801D36BC
    // 0x801D3648: nop

        goto L_801D36BC;
    // 0x801D3648: nop

L_801D364C:
    // 0x801D364C: addiu       $t6, $zero, 0x1414
    ctx->r14 = ADD32(0, 0X1414);
    // 0x801D3650: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D3654: sw          $t6, -0x2E34($at)
    MEM_W(-0X2E34, ctx->r1) = ctx->r14;
    // 0x801D3658: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D365C: addiu       $t7, $zero, 0xAA
    ctx->r15 = ADD32(0, 0XAA);
    // 0x801D3660: sw          $t7, -0x2C04($at)
    MEM_W(-0X2C04, ctx->r1) = ctx->r15;
    // 0x801D3664: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D3668: addiu       $t8, $zero, 0x7D
    ctx->r24 = ADD32(0, 0X7D);
    // 0x801D366C: sw          $t8, -0x2BEC($at)
    MEM_W(-0X2BEC, ctx->r1) = ctx->r24;
    // 0x801D3670: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D3674: addiu       $t9, $zero, 0xAA
    ctx->r25 = ADD32(0, 0XAA);
    // 0x801D3678: jal         0x80172DC4
    // 0x801D367C: sw          $t9, -0x2BF8($at)
    MEM_W(-0X2BF8, ctx->r1) = ctx->r25;
    func_80172DC4_1501A0(rdram, ctx);
        goto after_196;
    // 0x801D367C: sw          $t9, -0x2BF8($at)
    MEM_W(-0X2BF8, ctx->r1) = ctx->r25;
    after_196:
    // 0x801D3680: jal         0x80172E34
    // 0x801D3684: nop

    func_80172E34_1501A0(rdram, ctx);
        goto after_197;
    // 0x801D3684: nop

    after_197:
    // 0x801D3688: jal         0x80172F04
    // 0x801D368C: nop

    func_80172F04_1501A0(rdram, ctx);
        goto after_198;
    // 0x801D368C: nop

    after_198:
    // 0x801D3690: addiu       $t0, $zero, 0x33
    ctx->r8 = ADD32(0, 0X33);
    // 0x801D3694: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D3698: sw          $t0, -0x2B5C($at)
    MEM_W(-0X2B5C, ctx->r1) = ctx->r8;
    // 0x801D369C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D36A0: addiu       $t1, $zero, 0x34
    ctx->r9 = ADD32(0, 0X34);
    // 0x801D36A4: jal         0x80173538
    // 0x801D36A8: sw          $t1, -0x2B50($at)
    MEM_W(-0X2B50, ctx->r1) = ctx->r9;
    func_80173538_1501A0(rdram, ctx);
        goto after_199;
    // 0x801D36A8: sw          $t1, -0x2B50($at)
    MEM_W(-0X2B50, ctx->r1) = ctx->r9;
    after_199:
    // 0x801D36AC: jal         0x801735A8
    // 0x801D36B0: nop

    func_801735A8_1501A0(rdram, ctx);
        goto after_200;
    // 0x801D36B0: nop

    after_200:
    // 0x801D36B4: jal         0x801E2834
    // 0x801D36B8: nop

    func_801E2834_1B66F0(rdram, ctx);
        goto after_201;
    // 0x801D36B8: nop

    after_201:
L_801D36BC:
    // 0x801D36BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801D36C0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801D36C4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801D36C8: jr          $ra
    // 0x801D36CC: nop

    return;
    // 0x801D36CC: nop

;}
RECOMP_FUNC void func_801D36D0_1B66F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D36D0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801D36D4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801D36D8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x801D36DC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801D36E0: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x801D36E4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801D36E8: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x801D36EC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801D36F0: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x801D36F4: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x801D36F8: addu        $s0, $s0, $t7
    ctx->r16 = ADD32(ctx->r16, ctx->r15);
    // 0x801D36FC: lw          $s0, 0xF98($s0)
    ctx->r16 = MEM_W(ctx->r16, 0XF98);
    // 0x801D3700: addiu       $at, $zero, 0x46
    ctx->r1 = ADD32(0, 0X46);
    // 0x801D3704: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801D3708: beq         $s0, $at, L_801D383C
    if (ctx->r16 == ctx->r1) {
        // 0x801D370C: addiu       $at, $zero, 0x4B
        ctx->r1 = ADD32(0, 0X4B);
            goto L_801D383C;
    }
    // 0x801D370C: addiu       $at, $zero, 0x4B
    ctx->r1 = ADD32(0, 0X4B);
    // 0x801D3710: beq         $s0, $at, L_801D3720
    if (ctx->r16 == ctx->r1) {
        // 0x801D3714: addiu       $at, $zero, 0x4C
        ctx->r1 = ADD32(0, 0X4C);
            goto L_801D3720;
    }
    // 0x801D3714: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
    // 0x801D3718: bne         $s0, $at, L_801D39CC
    if (ctx->r16 != ctx->r1) {
        // 0x801D371C: nop
    
            goto L_801D39CC;
    }
    // 0x801D371C: nop

L_801D3720:
    // 0x801D3720: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x801D3724: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x801D3728: addiu       $t0, $t0, 0xF98
    ctx->r8 = ADD32(ctx->r8, 0XF98);
    // 0x801D372C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x801D3730: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x801D3734: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x801D3738: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x801D373C: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x801D3740: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x801D3744: lwc1        $f4, 0x18($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X18);
    // 0x801D3748: lwc1        $f6, 0x24($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X24);
    // 0x801D374C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x801D3750: addiu       $t4, $t4, 0xF98
    ctx->r12 = ADD32(ctx->r12, 0XF98);
    // 0x801D3754: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801D3758: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x801D375C: addiu       $t8, $t8, 0xF98
    ctx->r24 = ADD32(ctx->r24, 0XF98);
    // 0x801D3760: swc1        $f8, 0x18($t1)
    MEM_W(0X18, ctx->r9) = ctx->f8.u32l;
    // 0x801D3764: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x801D3768: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x801D376C: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x801D3770: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x801D3774: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x801D3778: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x801D377C: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x801D3780: lwc1        $f10, 0x1C($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X1C);
    // 0x801D3784: lwc1        $f16, 0x28($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0X28);
    // 0x801D3788: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801D378C: swc1        $f18, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = ctx->f18.u32l;
    // 0x801D3790: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x801D3794: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801D3798: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x801D379C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801D37A0: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x801D37A4: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x801D37A8: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x801D37AC: lwc1        $f4, 0x20($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X20);
    // 0x801D37B0: lwc1        $f6, 0x2C($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X2C);
    // 0x801D37B4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801D37B8: swc1        $f8, 0x20($t9)
    MEM_W(0X20, ctx->r25) = ctx->f8.u32l;
    // 0x801D37BC: jal         0x8018A5C8
    // 0x801D37C0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_8018A5C8_1501A0(rdram, ctx);
        goto after_0;
    // 0x801D37C0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_0:
    // 0x801D37C4: jal         0x8019A98C
    // 0x801D37C8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_8019A98C_1501A0(rdram, ctx);
        goto after_1;
    // 0x801D37C8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x801D37CC: bne         $v0, $zero, L_801D37E4
    if (ctx->r2 != 0) {
        // 0x801D37D0: nop
    
            goto L_801D37E4;
    }
    // 0x801D37D0: nop

    // 0x801D37D4: jal         0x8018A43C
    // 0x801D37D8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_8018A43C_1501A0(rdram, ctx);
        goto after_2;
    // 0x801D37D8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x801D37DC: beq         $v0, $zero, L_801D3808
    if (ctx->r2 == 0) {
        // 0x801D37E0: nop
    
            goto L_801D3808;
    }
    // 0x801D37E0: nop

L_801D37E4:
    // 0x801D37E4: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x801D37E8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D37EC: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x801D37F0: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x801D37F4: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x801D37F8: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x801D37FC: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x801D3800: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x801D3804: sw          $zero, 0xF98($at)
    MEM_W(0XF98, ctx->r1) = 0;
L_801D3808:
    // 0x801D3808: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x801D380C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x801D3810: addiu       $t4, $t4, 0xF98
    ctx->r12 = ADD32(ctx->r12, 0XF98);
    // 0x801D3814: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x801D3818: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x801D381C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x801D3820: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x801D3824: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x801D3828: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x801D382C: lw          $t6, 0x14($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X14);
    // 0x801D3830: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x801D3834: b           L_801D39CC
    // 0x801D3838: sw          $t7, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->r15;
        goto L_801D39CC;
    // 0x801D3838: sw          $t7, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->r15;
L_801D383C:
    // 0x801D383C: jal         0x80189188
    // 0x801D3840: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80189188_1501A0(rdram, ctx);
        goto after_3;
    // 0x801D3840: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x801D3844: jal         0x801894B8
    // 0x801D3848: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_801894B8_1501A0(rdram, ctx);
        goto after_4;
    // 0x801D3848: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_4:
    // 0x801D384C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x801D3850: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x801D3854: addiu       $t0, $t0, 0xF98
    ctx->r8 = ADD32(ctx->r8, 0XF98);
    // 0x801D3858: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x801D385C: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x801D3860: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x801D3864: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x801D3868: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x801D386C: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x801D3870: lwc1        $f10, 0x18($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X18);
    // 0x801D3874: lwc1        $f16, 0x24($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X24);
    // 0x801D3878: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x801D387C: addiu       $t4, $t4, 0xF98
    ctx->r12 = ADD32(ctx->r12, 0XF98);
    // 0x801D3880: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801D3884: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x801D3888: addiu       $t8, $t8, 0xF98
    ctx->r24 = ADD32(ctx->r24, 0XF98);
    // 0x801D388C: swc1        $f18, 0x18($t1)
    MEM_W(0X18, ctx->r9) = ctx->f18.u32l;
    // 0x801D3890: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x801D3894: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x801D3898: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x801D389C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x801D38A0: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x801D38A4: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x801D38A8: addu        $t6, $t3, $t4
    ctx->r14 = ADD32(ctx->r11, ctx->r12);
    // 0x801D38AC: lwc1        $f4, 0x1C($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X1C);
    // 0x801D38B0: lwc1        $f6, 0x28($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X28);
    // 0x801D38B4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x801D38B8: addiu       $t2, $t2, 0xF98
    ctx->r10 = ADD32(ctx->r10, 0XF98);
    // 0x801D38BC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801D38C0: swc1        $f8, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = ctx->f8.u32l;
    // 0x801D38C4: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x801D38C8: sll         $t5, $t7, 2
    ctx->r13 = S32(ctx->r15 << 2);
    // 0x801D38CC: subu        $t5, $t5, $t7
    ctx->r13 = SUB32(ctx->r13, ctx->r15);
    // 0x801D38D0: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x801D38D4: addu        $t5, $t5, $t7
    ctx->r13 = ADD32(ctx->r13, ctx->r15);
    // 0x801D38D8: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x801D38DC: addu        $t9, $t5, $t8
    ctx->r25 = ADD32(ctx->r13, ctx->r24);
    // 0x801D38E0: lwc1        $f10, 0x20($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X20);
    // 0x801D38E4: lwc1        $f16, 0x2C($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X2C);
    // 0x801D38E8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801D38EC: swc1        $f18, 0x20($t9)
    MEM_W(0X20, ctx->r25) = ctx->f18.u32l;
    // 0x801D38F0: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x801D38F4: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x801D38F8: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x801D38FC: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x801D3900: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x801D3904: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x801D3908: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x801D390C: lw          $a0, 0x4($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X4);
    // 0x801D3910: lw          $a1, 0x18($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X18);
    // 0x801D3914: lw          $a2, 0x1C($t3)
    ctx->r6 = MEM_W(ctx->r11, 0X1C);
    // 0x801D3918: jal         0x8019CD48
    // 0x801D391C: lw          $a3, 0x20($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X20);
    func_8019CD48_1501A0(rdram, ctx);
        goto after_5;
    // 0x801D391C: lw          $a3, 0x20($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X20);
    after_5:
    // 0x801D3920: jal         0x8018A5C8
    // 0x801D3924: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_8018A5C8_1501A0(rdram, ctx);
        goto after_6;
    // 0x801D3924: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_6:
    // 0x801D3928: jal         0x8019A98C
    // 0x801D392C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_8019A98C_1501A0(rdram, ctx);
        goto after_7;
    // 0x801D392C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_7:
    // 0x801D3930: bne         $v0, $zero, L_801D3948
    if (ctx->r2 != 0) {
        // 0x801D3934: nop
    
            goto L_801D3948;
    }
    // 0x801D3934: nop

    // 0x801D3938: jal         0x8018A43C
    // 0x801D393C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_8018A43C_1501A0(rdram, ctx);
        goto after_8;
    // 0x801D393C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_8:
    // 0x801D3940: beq         $v0, $zero, L_801D396C
    if (ctx->r2 == 0) {
        // 0x801D3944: nop
    
            goto L_801D396C;
    }
    // 0x801D3944: nop

L_801D3948:
    // 0x801D3948: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x801D394C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D3950: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x801D3954: subu        $t6, $t6, $t4
    ctx->r14 = SUB32(ctx->r14, ctx->r12);
    // 0x801D3958: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801D395C: addu        $t6, $t6, $t4
    ctx->r14 = ADD32(ctx->r14, ctx->r12);
    // 0x801D3960: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x801D3964: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x801D3968: sw          $zero, 0xF98($at)
    MEM_W(0XF98, ctx->r1) = 0;
L_801D396C:
    // 0x801D396C: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x801D3970: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x801D3974: sll         $t5, $t7, 2
    ctx->r13 = S32(ctx->r15 << 2);
    // 0x801D3978: subu        $t5, $t5, $t7
    ctx->r13 = SUB32(ctx->r13, ctx->r15);
    // 0x801D397C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x801D3980: addu        $t5, $t5, $t7
    ctx->r13 = ADD32(ctx->r13, ctx->r15);
    // 0x801D3984: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x801D3988: addu        $a0, $a0, $t5
    ctx->r4 = ADD32(ctx->r4, ctx->r13);
    // 0x801D398C: jal         0x800C8124
    // 0x801D3990: lw          $a0, 0xF9C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XF9C);
    func_800C8124(rdram, ctx);
        goto after_9;
    // 0x801D3990: lw          $a0, 0xF9C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XF9C);
    after_9:
    // 0x801D3994: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x801D3998: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x801D399C: addiu       $t0, $t0, 0xF98
    ctx->r8 = ADD32(ctx->r8, 0XF98);
    // 0x801D39A0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x801D39A4: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x801D39A8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x801D39AC: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x801D39B0: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x801D39B4: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x801D39B8: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x801D39BC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801D39C0: lwc1        $f4, 0x38($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X38);
    // 0x801D39C4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801D39C8: swc1        $f8, 0x38($t1)
    MEM_W(0X38, ctx->r9) = ctx->f8.u32l;
L_801D39CC:
    // 0x801D39CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801D39D0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801D39D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801D39D8: jr          $ra
    // 0x801D39DC: nop

    return;
    // 0x801D39DC: nop

;}
RECOMP_FUNC void func_801D39E0_1B66F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D39E0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801D39E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D39E8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x801D39EC: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x801D39F0: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    // 0x801D39F4: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    // 0x801D39F8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_801D39FC:
    // 0x801D39FC: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x801D3A00: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x801D3A04: addiu       $t8, $t8, 0xF98
    ctx->r24 = ADD32(ctx->r24, 0XF98);
    // 0x801D3A08: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801D3A0C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x801D3A10: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801D3A14: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x801D3A18: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x801D3A1C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x801D3A20: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x801D3A24: addiu       $at, $zero, 0x47
    ctx->r1 = ADD32(0, 0X47);
    // 0x801D3A28: bne         $t0, $at, L_801D3E28
    if (ctx->r8 != ctx->r1) {
        // 0x801D3A2C: nop
    
            goto L_801D3E28;
    }
    // 0x801D3A2C: nop

    // 0x801D3A30: lwc1        $f4, 0x18($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X18);
    // 0x801D3A34: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x801D3A38: addiu       $t3, $t3, 0xF98
    ctx->r11 = ADD32(ctx->r11, 0XF98);
    // 0x801D3A3C: swc1        $f4, 0x40($t9)
    MEM_W(0X40, ctx->r25) = ctx->f4.u32l;
    // 0x801D3A40: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x801D3A44: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801D3A48: addiu       $t7, $t7, 0xF98
    ctx->r15 = ADD32(ctx->r15, 0XF98);
    // 0x801D3A4C: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x801D3A50: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x801D3A54: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x801D3A58: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x801D3A5C: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x801D3A60: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x801D3A64: lwc1        $f6, 0x1C($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X1C);
    // 0x801D3A68: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D3A6C: swc1        $f6, 0x44($t4)
    MEM_W(0X44, ctx->r12) = ctx->f6.u32l;
    // 0x801D3A70: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x801D3A74: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x801D3A78: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x801D3A7C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801D3A80: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x801D3A84: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x801D3A88: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x801D3A8C: lwc1        $f8, 0x20($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X20);
    // 0x801D3A90: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801D3A94: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x801D3A98: swc1        $f8, 0x48($t8)
    MEM_W(0X48, ctx->r24) = ctx->f8.u32l;
    // 0x801D3A9C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x801D3AA0: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x801D3AA4: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801D3AA8: sll         $t9, $t0, 2
    ctx->r25 = S32(ctx->r8 << 2);
    // 0x801D3AAC: subu        $t9, $t9, $t0
    ctx->r25 = SUB32(ctx->r25, ctx->r8);
    // 0x801D3AB0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x801D3AB4: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x801D3AB8: addu        $t9, $t9, $t0
    ctx->r25 = ADD32(ctx->r25, ctx->r8);
    // 0x801D3ABC: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x801D3AC0: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x801D3AC4: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x801D3AC8: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x801D3ACC: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x801D3AD0: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801D3AD4: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x801D3AD8: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x801D3ADC: swc1        $f10, 0xFF4($at)
    MEM_W(0XFF4, ctx->r1) = ctx->f10.u32l;
    // 0x801D3AE0: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x801D3AE4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D3AE8: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x801D3AEC: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x801D3AF0: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x801D3AF4: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x801D3AF8: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801D3AFC: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x801D3B00: swc1        $f16, 0xFF8($at)
    MEM_W(0XFF8, ctx->r1) = ctx->f16.u32l;
    // 0x801D3B04: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x801D3B08: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D3B0C: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x801D3B10: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x801D3B14: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x801D3B18: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801D3B1C: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x801D3B20: swc1        $f18, 0xFFC($at)
    MEM_W(0XFFC, ctx->r1) = ctx->f18.u32l;
    // 0x801D3B24: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D3B28: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x801D3B2C: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x801D3B30: lwc1        $f6, 0xFB0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0XFB0);
    // 0x801D3B34: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801D3B38: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D3B3C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801D3B40: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801D3B44: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x801D3B48: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x801D3B4C: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x801D3B50: swc1        $f8, 0xA0($t7)
    MEM_W(0XA0, ctx->r15) = ctx->f8.u32l;
    // 0x801D3B54: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x801D3B58: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x801D3B5C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x801D3B60: sll         $t0, $t8, 2
    ctx->r8 = S32(ctx->r24 << 2);
    // 0x801D3B64: subu        $t0, $t0, $t8
    ctx->r8 = SUB32(ctx->r8, ctx->r24);
    // 0x801D3B68: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x801D3B6C: addu        $t0, $t0, $t8
    ctx->r8 = ADD32(ctx->r8, ctx->r24);
    // 0x801D3B70: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x801D3B74: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x801D3B78: lwc1        $f16, 0xFB4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0XFB4);
    // 0x801D3B7C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D3B80: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x801D3B84: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x801D3B88: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801D3B8C: swc1        $f18, 0xA4($t9)
    MEM_W(0XA4, ctx->r25) = ctx->f18.u32l;
    // 0x801D3B90: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x801D3B94: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x801D3B98: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x801D3B9C: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x801D3BA0: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x801D3BA4: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x801D3BA8: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x801D3BAC: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x801D3BB0: lwc1        $f6, 0xFB8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0XFB8);
    // 0x801D3BB4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801D3BB8: swc1        $f8, 0xA8($t3)
    MEM_W(0XA8, ctx->r11) = ctx->f8.u32l;
    // 0x801D3BBC: lwc1        $f10, 0xA0($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0XA0);
    // 0x801D3BC0: c.eq.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl == ctx->f16.fl;
    // 0x801D3BC4: nop

    // 0x801D3BC8: bc1t        L_801D3BE0
    if (c1cs) {
        // 0x801D3BCC: lui         $at, 0x4140
        ctx->r1 = S32(0X4140 << 16);
            goto L_801D3BE0;
    }
    // 0x801D3BCC: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x801D3BD0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801D3BD4: nop

    // 0x801D3BD8: div.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x801D3BDC: swc1        $f4, 0xA0($t4)
    MEM_W(0XA0, ctx->r12) = ctx->f4.u32l;
L_801D3BE0:
    // 0x801D3BE0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x801D3BE4: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x801D3BE8: lwc1        $f6, 0xA4($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0XA4);
    // 0x801D3BEC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801D3BF0: nop

    // 0x801D3BF4: c.eq.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl == ctx->f8.fl;
    // 0x801D3BF8: nop

    // 0x801D3BFC: bc1t        L_801D3C14
    if (c1cs) {
        // 0x801D3C00: lui         $at, 0x4140
        ctx->r1 = S32(0X4140 << 16);
            goto L_801D3C14;
    }
    // 0x801D3C00: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x801D3C04: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801D3C08: nop

    // 0x801D3C0C: div.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f16.fl);
    // 0x801D3C10: swc1        $f10, 0xA4($t5)
    MEM_W(0XA4, ctx->r13) = ctx->f10.u32l;
L_801D3C14:
    // 0x801D3C14: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801D3C18: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x801D3C1C: lwc1        $f18, 0xA8($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0XA8);
    // 0x801D3C20: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801D3C24: nop

    // 0x801D3C28: c.eq.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl == ctx->f4.fl;
    // 0x801D3C2C: nop

    // 0x801D3C30: bc1t        L_801D3C48
    if (c1cs) {
        // 0x801D3C34: lui         $at, 0x4140
        ctx->r1 = S32(0X4140 << 16);
            goto L_801D3C48;
    }
    // 0x801D3C34: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x801D3C38: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801D3C3C: nop

    // 0x801D3C40: div.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f8.fl);
    // 0x801D3C44: swc1        $f6, 0xA8($t6)
    MEM_W(0XA8, ctx->r14) = ctx->f6.u32l;
L_801D3C48:
    // 0x801D3C48: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x801D3C4C: addiu       $t8, $zero, 0x14
    ctx->r24 = ADD32(0, 0X14);
    // 0x801D3C50: sb          $t8, 0x1B($sp)
    MEM_B(0X1B, ctx->r29) = ctx->r24;
    // 0x801D3C54: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x801D3C58: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_801D3C5C:
    // 0x801D3C5C: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x801D3C60: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x801D3C64: beq         $t0, $at, L_801D3C74
    if (ctx->r8 == ctx->r1) {
        // 0x801D3C68: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_801D3C74;
    }
    // 0x801D3C68: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x801D3C6C: bne         $t0, $at, L_801D3C9C
    if (ctx->r8 != ctx->r1) {
        // 0x801D3C70: nop
    
            goto L_801D3C9C;
    }
    // 0x801D3C70: nop

L_801D3C74:
    // 0x801D3C74: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801D3C78: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x801D3C7C: jal         0x801D50FC
    // 0x801D3C80: lbu         $a2, 0x1B($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X1B);
    func_801D50FC_1B66F0(rdram, ctx);
        goto after_0;
    // 0x801D3C80: lbu         $a2, 0x1B($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X1B);
    after_0:
    // 0x801D3C84: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x801D3C88: lbu         $t2, 0x1B($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X1B);
    // 0x801D3C8C: addiu       $t1, $t9, 0x5
    ctx->r9 = ADD32(ctx->r25, 0X5);
    // 0x801D3C90: addiu       $t3, $t2, 0x14
    ctx->r11 = ADD32(ctx->r10, 0X14);
    // 0x801D3C94: sb          $t3, 0x1B($sp)
    MEM_B(0X1B, ctx->r29) = ctx->r11;
    // 0x801D3C98: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
L_801D3C9C:
    // 0x801D3C9C: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x801D3CA0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801D3CA4: addiu       $t6, $t6, 0xF98
    ctx->r14 = ADD32(ctx->r14, 0XF98);
    // 0x801D3CA8: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x801D3CAC: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x801D3CB0: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x801D3CB4: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x801D3CB8: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x801D3CBC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x801D3CC0: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x801D3CC4: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x801D3CC8: lwc1        $f16, 0x18($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X18);
    // 0x801D3CCC: lwc1        $f10, 0xA0($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0XA0);
    // 0x801D3CD0: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x801D3CD4: addiu       $t1, $t1, 0xF98
    ctx->r9 = ADD32(ctx->r9, 0XF98);
    // 0x801D3CD8: add.s       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x801D3CDC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x801D3CE0: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x801D3CE4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801D3CE8: swc1        $f4, 0x18($t7)
    MEM_W(0X18, ctx->r15) = ctx->f4.u32l;
    // 0x801D3CEC: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x801D3CF0: lwc1        $f8, 0xA4($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0XA4);
    // 0x801D3CF4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801D3CF8: sll         $t9, $t0, 2
    ctx->r25 = S32(ctx->r8 << 2);
    // 0x801D3CFC: subu        $t9, $t9, $t0
    ctx->r25 = SUB32(ctx->r25, ctx->r8);
    // 0x801D3D00: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x801D3D04: addu        $t9, $t9, $t0
    ctx->r25 = ADD32(ctx->r25, ctx->r8);
    // 0x801D3D08: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x801D3D0C: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x801D3D10: lwc1        $f18, 0x1C($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X1C);
    // 0x801D3D14: addiu       $t6, $t6, 0xF98
    ctx->r14 = ADD32(ctx->r14, 0XF98);
    // 0x801D3D18: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x801D3D1C: add.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x801D3D20: swc1        $f6, 0x1C($t2)
    MEM_W(0X1C, ctx->r10) = ctx->f6.u32l;
    // 0x801D3D24: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x801D3D28: lwc1        $f10, 0xA8($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0XA8);
    // 0x801D3D2C: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x801D3D30: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x801D3D34: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x801D3D38: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x801D3D3C: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x801D3D40: addu        $t8, $t5, $t6
    ctx->r24 = ADD32(ctx->r13, ctx->r14);
    // 0x801D3D44: lwc1        $f16, 0x20($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X20);
    // 0x801D3D48: add.s       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x801D3D4C: swc1        $f4, 0x20($t8)
    MEM_W(0X20, ctx->r24) = ctx->f4.u32l;
    // 0x801D3D50: jal         0x8019AB38
    // 0x801D3D54: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_8019AB38_1501A0(rdram, ctx);
        goto after_1;
    // 0x801D3D54: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x801D3D58: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x801D3D5C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x801D3D60: sll         $t9, $t0, 2
    ctx->r25 = S32(ctx->r8 << 2);
    // 0x801D3D64: subu        $t9, $t9, $t0
    ctx->r25 = SUB32(ctx->r25, ctx->r8);
    // 0x801D3D68: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x801D3D6C: addu        $t9, $t9, $t0
    ctx->r25 = ADD32(ctx->r25, ctx->r8);
    // 0x801D3D70: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x801D3D74: addu        $t1, $t1, $t9
    ctx->r9 = ADD32(ctx->r9, ctx->r25);
    // 0x801D3D78: lw          $t1, 0xF98($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XF98);
    // 0x801D3D7C: beq         $t1, $zero, L_801D3E3C
    if (ctx->r9 == 0) {
        // 0x801D3D80: nop
    
            goto L_801D3E3C;
    }
    // 0x801D3D80: nop

    // 0x801D3D84: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x801D3D88: addiu       $t2, $t3, 0x1
    ctx->r10 = ADD32(ctx->r11, 0X1);
    // 0x801D3D8C: sltiu       $at, $t2, 0xC
    ctx->r1 = ctx->r10 < 0XC ? 1 : 0;
    // 0x801D3D90: bne         $at, $zero, L_801D3C5C
    if (ctx->r1 != 0) {
        // 0x801D3D94: sw          $t2, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r10;
            goto L_801D3C5C;
    }
    // 0x801D3D94: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x801D3D98: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x801D3D9C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x801D3DA0: lwc1        $f18, 0x34($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801D3DA4: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x801D3DA8: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x801D3DAC: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x801D3DB0: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x801D3DB4: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x801D3DB8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801D3DBC: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x801D3DC0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D3DC4: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x801D3DC8: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x801D3DCC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801D3DD0: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x801D3DD4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x801D3DD8: swc1        $f18, 0xFB0($at)
    MEM_W(0XFB0, ctx->r1) = ctx->f18.u32l;
    // 0x801D3DDC: sll         $t0, $t8, 2
    ctx->r8 = S32(ctx->r24 << 2);
    // 0x801D3DE0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D3DE4: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x801D3DE8: subu        $t0, $t0, $t8
    ctx->r8 = SUB32(ctx->r8, ctx->r24);
    // 0x801D3DEC: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x801D3DF0: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x801D3DF4: addu        $t0, $t0, $t8
    ctx->r8 = ADD32(ctx->r8, ctx->r24);
    // 0x801D3DF8: swc1        $f8, 0xFB4($at)
    MEM_W(0XFB4, ctx->r1) = ctx->f8.u32l;
    // 0x801D3DFC: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x801D3E00: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D3E04: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x801D3E08: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x801D3E0C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801D3E10: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x801D3E14: lbu         $a2, 0x1B($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X1B);
    // 0x801D3E18: jal         0x801D50FC
    // 0x801D3E1C: swc1        $f6, 0xFB8($at)
    MEM_W(0XFB8, ctx->r1) = ctx->f6.u32l;
    func_801D50FC_1B66F0(rdram, ctx);
        goto after_2;
    // 0x801D3E1C: swc1        $f6, 0xFB8($at)
    MEM_W(0XFB8, ctx->r1) = ctx->f6.u32l;
    after_2:
    // 0x801D3E20: b           L_801D3E3C
    // 0x801D3E24: nop

        goto L_801D3E3C;
    // 0x801D3E24: nop

L_801D3E28:
    // 0x801D3E28: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x801D3E2C: addiu       $t1, $t9, 0x1
    ctx->r9 = ADD32(ctx->r25, 0X1);
    // 0x801D3E30: sltiu       $at, $t1, 0x30
    ctx->r1 = ctx->r9 < 0X30 ? 1 : 0;
    // 0x801D3E34: bne         $at, $zero, L_801D39FC
    if (ctx->r1 != 0) {
        // 0x801D3E38: sw          $t1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r9;
            goto L_801D39FC;
    }
    // 0x801D3E38: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
L_801D3E3C:
    // 0x801D3E3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801D3E40: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801D3E44: jr          $ra
    // 0x801D3E48: nop

    return;
    // 0x801D3E48: nop

;}
RECOMP_FUNC void func_801D3E4C_1B66F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801D3E4C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801D3E50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801D3E54: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x801D3E58: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x801D3E5C: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    // 0x801D3E60: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    // 0x801D3E64: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_801D3E68:
    // 0x801D3E68: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x801D3E6C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x801D3E70: addiu       $t8, $t8, 0xF98
    ctx->r24 = ADD32(ctx->r24, 0XF98);
    // 0x801D3E74: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801D3E78: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x801D3E7C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801D3E80: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x801D3E84: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x801D3E88: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x801D3E8C: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x801D3E90: addiu       $at, $zero, 0x48
    ctx->r1 = ADD32(0, 0X48);
    // 0x801D3E94: bne         $t0, $at, L_801D46BC
    if (ctx->r8 != ctx->r1) {
        // 0x801D3E98: nop
    
            goto L_801D46BC;
    }
    // 0x801D3E98: nop

    // 0x801D3E9C: lwc1        $f4, 0x18($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X18);
    // 0x801D3EA0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x801D3EA4: addiu       $t3, $t3, 0xF98
    ctx->r11 = ADD32(ctx->r11, 0XF98);
    // 0x801D3EA8: swc1        $f4, 0x40($t9)
    MEM_W(0X40, ctx->r25) = ctx->f4.u32l;
    // 0x801D3EAC: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x801D3EB0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801D3EB4: addiu       $t7, $t7, 0xF98
    ctx->r15 = ADD32(ctx->r15, 0XF98);
    // 0x801D3EB8: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x801D3EBC: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x801D3EC0: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x801D3EC4: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x801D3EC8: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x801D3ECC: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x801D3ED0: lwc1        $f6, 0x1C($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X1C);
    // 0x801D3ED4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D3ED8: swc1        $f6, 0x44($t4)
    MEM_W(0X44, ctx->r12) = ctx->f6.u32l;
    // 0x801D3EDC: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x801D3EE0: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x801D3EE4: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x801D3EE8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801D3EEC: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x801D3EF0: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x801D3EF4: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x801D3EF8: lwc1        $f8, 0x20($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X20);
    // 0x801D3EFC: swc1        $f8, 0x48($t8)
    MEM_W(0X48, ctx->r24) = ctx->f8.u32l;
    // 0x801D3F00: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x801D3F04: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x801D3F08: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801D3F0C: sll         $t9, $t0, 2
    ctx->r25 = S32(ctx->r8 << 2);
    // 0x801D3F10: subu        $t9, $t9, $t0
    ctx->r25 = SUB32(ctx->r25, ctx->r8);
    // 0x801D3F14: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x801D3F18: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x801D3F1C: addu        $t9, $t9, $t0
    ctx->r25 = ADD32(ctx->r25, ctx->r8);
    // 0x801D3F20: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x801D3F24: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x801D3F28: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x801D3F2C: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x801D3F30: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x801D3F34: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801D3F38: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x801D3F3C: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x801D3F40: swc1        $f10, 0xFB0($at)
    MEM_W(0XFB0, ctx->r1) = ctx->f10.u32l;
    // 0x801D3F44: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x801D3F48: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D3F4C: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x801D3F50: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x801D3F54: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x801D3F58: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x801D3F5C: lwc1        $f18, 0x34($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801D3F60: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x801D3F64: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x801D3F68: swc1        $f16, 0xFB4($at)
    MEM_W(0XFB4, ctx->r1) = ctx->f16.u32l;
    // 0x801D3F6C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x801D3F70: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D3F74: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x801D3F78: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x801D3F7C: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x801D3F80: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801D3F84: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x801D3F88: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x801D3F8C: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x801D3F90: swc1        $f18, 0xFB8($at)
    MEM_W(0XFB8, ctx->r1) = ctx->f18.u32l;
    // 0x801D3F94: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x801D3F98: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D3F9C: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x801D3FA0: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x801D3FA4: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x801D3FA8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x801D3FAC: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801D3FB0: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x801D3FB4: swc1        $f4, 0xFF4($at)
    MEM_W(0XFF4, ctx->r1) = ctx->f4.u32l;
    // 0x801D3FB8: sll         $t9, $t0, 2
    ctx->r25 = S32(ctx->r8 << 2);
    // 0x801D3FBC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D3FC0: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x801D3FC4: subu        $t9, $t9, $t0
    ctx->r25 = SUB32(ctx->r25, ctx->r8);
    // 0x801D3FC8: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x801D3FCC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x801D3FD0: addu        $t9, $t9, $t0
    ctx->r25 = ADD32(ctx->r25, ctx->r8);
    // 0x801D3FD4: swc1        $f6, 0xFF8($at)
    MEM_W(0XFF8, ctx->r1) = ctx->f6.u32l;
    // 0x801D3FD8: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801D3FDC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D3FE0: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x801D3FE4: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x801D3FE8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x801D3FEC: jal         0x801D56F4
    // 0x801D3FF0: swc1        $f8, 0xFFC($at)
    MEM_W(0XFFC, ctx->r1) = ctx->f8.u32l;
    func_801D56F4_1B66F0(rdram, ctx);
        goto after_0;
    // 0x801D3FF0: swc1        $f8, 0xFFC($at)
    MEM_W(0XFFC, ctx->r1) = ctx->f8.u32l;
    after_0:
    // 0x801D3FF4: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x801D3FF8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x801D3FFC: addiu       $t3, $t3, 0xF98
    ctx->r11 = ADD32(ctx->r11, 0XF98);
    // 0x801D4000: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x801D4004: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x801D4008: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x801D400C: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x801D4010: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x801D4014: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x801D4018: lwc1        $f10, 0x18($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X18);
    // 0x801D401C: lwc1        $f16, 0x5C($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X5C);
    // 0x801D4020: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x801D4024: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x801D4028: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801D402C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x801D4030: addiu       $t8, $t8, 0xF98
    ctx->r24 = ADD32(ctx->r24, 0XF98);
    // 0x801D4034: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801D4038: swc1        $f18, 0xC8($t5)
    MEM_W(0XC8, ctx->r13) = ctx->f18.u32l;
    // 0x801D403C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x801D4040: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x801D4044: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x801D4048: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801D404C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x801D4050: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801D4054: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x801D4058: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x801D405C: addu        $t0, $t7, $t8
    ctx->r8 = ADD32(ctx->r15, ctx->r24);
    // 0x801D4060: lwc1        $f4, 0x1C($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X1C);
    // 0x801D4064: lwc1        $f6, 0x60($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X60);
    // 0x801D4068: addiu       $t3, $t3, 0xF98
    ctx->r11 = ADD32(ctx->r11, 0XF98);
    // 0x801D406C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x801D4070: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801D4074: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x801D4078: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801D407C: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x801D4080: swc1        $f8, 0xCC($t9)
    MEM_W(0XCC, ctx->r25) = ctx->f8.u32l;
    // 0x801D4084: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x801D4088: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801D408C: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x801D4090: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x801D4094: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x801D4098: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x801D409C: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x801D40A0: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x801D40A4: lwc1        $f10, 0x20($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X20);
    // 0x801D40A8: lwc1        $f16, 0x64($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X64);
    // 0x801D40AC: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801D40B0: swc1        $f18, 0xD0($t5)
    MEM_W(0XD0, ctx->r13) = ctx->f18.u32l;
    // 0x801D40B4: lwc1        $f4, 0xC8($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0XC8);
    // 0x801D40B8: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x801D40BC: nop

    // 0x801D40C0: bc1t        L_801D40D8
    if (c1cs) {
        // 0x801D40C4: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_801D40D8;
    }
    // 0x801D40C4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801D40C8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801D40CC: nop

    // 0x801D40D0: div.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x801D40D4: swc1        $f10, 0xC8($t6)
    MEM_W(0XC8, ctx->r14) = ctx->f10.u32l;
L_801D40D8:
    // 0x801D40D8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801D40DC: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x801D40E0: lwc1        $f16, 0xCC($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0XCC);
    // 0x801D40E4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801D40E8: nop

    // 0x801D40EC: c.eq.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl == ctx->f18.fl;
    // 0x801D40F0: nop

    // 0x801D40F4: bc1t        L_801D410C
    if (c1cs) {
        // 0x801D40F8: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_801D410C;
    }
    // 0x801D40F8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801D40FC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801D4100: nop

    // 0x801D4104: div.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f6.fl);
    // 0x801D4108: swc1        $f4, 0xCC($t7)
    MEM_W(0XCC, ctx->r15) = ctx->f4.u32l;
L_801D410C:
    // 0x801D410C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x801D4110: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x801D4114: lwc1        $f8, 0xD0($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0XD0);
    // 0x801D4118: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801D411C: nop

    // 0x801D4120: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x801D4124: nop

    // 0x801D4128: bc1t        L_801D4140
    if (c1cs) {
        // 0x801D412C: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_801D4140;
    }
    // 0x801D412C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801D4130: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801D4134: nop

    // 0x801D4138: div.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f18.fl);
    // 0x801D413C: swc1        $f16, 0xD0($t8)
    MEM_W(0XD0, ctx->r24) = ctx->f16.u32l;
L_801D4140:
    // 0x801D4140: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x801D4144: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x801D4148: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D414C: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x801D4150: subu        $t1, $t1, $t9
    ctx->r9 = SUB32(ctx->r9, ctx->r25);
    // 0x801D4154: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x801D4158: addu        $t1, $t1, $t9
    ctx->r9 = ADD32(ctx->r9, ctx->r25);
    // 0x801D415C: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x801D4160: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x801D4164: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x801D4168: lwc1        $f6, 0xC8($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0XC8);
    // 0x801D416C: lwc1        $f4, 0xFB0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XFB0);
    // 0x801D4170: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D4174: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x801D4178: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x801D417C: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x801D4180: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x801D4184: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x801D4188: swc1        $f10, 0xC8($t0)
    MEM_W(0XC8, ctx->r8) = ctx->f10.u32l;
    // 0x801D418C: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x801D4190: lwc1        $f8, 0xCC($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0XCC);
    // 0x801D4194: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x801D4198: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x801D419C: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x801D41A0: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x801D41A4: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x801D41A8: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x801D41AC: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x801D41B0: lwc1        $f18, 0xFB4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0XFB4);
    // 0x801D41B4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D41B8: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x801D41BC: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x801D41C0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801D41C4: swc1        $f16, 0xCC($t2)
    MEM_W(0XCC, ctx->r10) = ctx->f16.u32l;
    // 0x801D41C8: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x801D41CC: lwc1        $f6, 0xD0($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0XD0);
    // 0x801D41D0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801D41D4: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x801D41D8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801D41DC: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x801D41E0: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x801D41E4: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x801D41E8: lwc1        $f4, 0xFB8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XFB8);
    // 0x801D41EC: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x801D41F0: swc1        $f10, 0xD0($t5)
    MEM_W(0XD0, ctx->r13) = ctx->f10.u32l;
    // 0x801D41F4: lwc1        $f8, 0xC8($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0XC8);
    // 0x801D41F8: c.eq.s      $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f8.fl == ctx->f18.fl;
    // 0x801D41FC: nop

    // 0x801D4200: bc1t        L_801D4218
    if (c1cs) {
        // 0x801D4204: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_801D4218;
    }
    // 0x801D4204: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801D4208: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801D420C: nop

    // 0x801D4210: div.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = DIV_S(ctx->f8.fl, ctx->f16.fl);
    // 0x801D4214: swc1        $f6, 0xC8($t8)
    MEM_W(0XC8, ctx->r24) = ctx->f6.u32l;
L_801D4218:
    // 0x801D4218: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801D421C: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x801D4220: lwc1        $f4, 0xCC($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0XCC);
    // 0x801D4224: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801D4228: nop

    // 0x801D422C: c.eq.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl == ctx->f10.fl;
    // 0x801D4230: nop

    // 0x801D4234: bc1t        L_801D424C
    if (c1cs) {
        // 0x801D4238: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_801D424C;
    }
    // 0x801D4238: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801D423C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801D4240: nop

    // 0x801D4244: div.s       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f18.fl);
    // 0x801D4248: swc1        $f8, 0xCC($t9)
    MEM_W(0XCC, ctx->r25) = ctx->f8.u32l;
L_801D424C:
    // 0x801D424C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x801D4250: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x801D4254: lwc1        $f16, 0xD0($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0XD0);
    // 0x801D4258: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801D425C: nop

    // 0x801D4260: c.eq.s      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.fl == ctx->f6.fl;
    // 0x801D4264: nop

    // 0x801D4268: bc1t        L_801D4280
    if (c1cs) {
        // 0x801D426C: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_801D4280;
    }
    // 0x801D426C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801D4270: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801D4274: nop

    // 0x801D4278: div.s       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f10.fl);
    // 0x801D427C: swc1        $f4, 0xD0($t1)
    MEM_W(0XD0, ctx->r9) = ctx->f4.u32l;
L_801D4280:
    // 0x801D4280: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x801D4284: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D4288: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x801D428C: sll         $t3, $t0, 2
    ctx->r11 = S32(ctx->r8 << 2);
    // 0x801D4290: subu        $t3, $t3, $t0
    ctx->r11 = SUB32(ctx->r11, ctx->r8);
    // 0x801D4294: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x801D4298: addu        $t3, $t3, $t0
    ctx->r11 = ADD32(ctx->r11, ctx->r8);
    // 0x801D429C: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x801D42A0: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x801D42A4: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x801D42A8: lwc1        $f8, 0xC8($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0XC8);
    // 0x801D42AC: lwc1        $f18, 0xFB0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0XFB0);
    // 0x801D42B0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801D42B4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801D42B8: sub.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x801D42BC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x801D42C0: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x801D42C4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D42C8: swc1        $f6, 0x14($t4)
    MEM_W(0X14, ctx->r12) = ctx->f6.u32l;
    // 0x801D42CC: swc1        $f16, 0x28($t2)
    MEM_W(0X28, ctx->r10) = ctx->f16.u32l;
    // 0x801D42D0: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x801D42D4: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x801D42D8: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x801D42DC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801D42E0: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x801D42E4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801D42E8: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x801D42EC: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x801D42F0: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x801D42F4: lwc1        $f10, 0xFB4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0XFB4);
    // 0x801D42F8: lwc1        $f4, 0xCC($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0XCC);
    // 0x801D42FC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801D4300: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801D4304: sub.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x801D4308: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x801D430C: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x801D4310: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801D4314: swc1        $f18, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f18.u32l;
    // 0x801D4318: swc1        $f8, 0x2C($t8)
    MEM_W(0X2C, ctx->r24) = ctx->f8.u32l;
    // 0x801D431C: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x801D4320: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x801D4324: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x801D4328: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x801D432C: subu        $t1, $t1, $t9
    ctx->r9 = SUB32(ctx->r9, ctx->r25);
    // 0x801D4330: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x801D4334: addu        $t1, $t1, $t9
    ctx->r9 = ADD32(ctx->r9, ctx->r25);
    // 0x801D4338: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x801D433C: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x801D4340: lwc1        $f6, 0xFB8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0XFB8);
    // 0x801D4344: lwc1        $f16, 0xD0($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0XD0);
    // 0x801D4348: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801D434C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801D4350: sub.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x801D4354: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x801D4358: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x801D435C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x801D4360: swc1        $f10, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->f10.u32l;
    // 0x801D4364: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x801D4368: swc1        $f4, 0x30($t3)
    MEM_W(0X30, ctx->r11) = ctx->f4.u32l;
    // 0x801D436C: lwc1        $f18, 0x14($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X14);
    // 0x801D4370: lwc1        $f6, 0x18($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X18);
    // 0x801D4374: lwc1        $f4, 0x1C($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X1C);
    // 0x801D4378: mul.s       $f8, $f18, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x801D437C: nop

    // 0x801D4380: mul.s       $f16, $f6, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x801D4384: add.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x801D4388: mul.s       $f18, $f4, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x801D438C: jal         0x800D68E0
    // 0x801D4390: add.s       $f12, $f18, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x801D4390: add.s       $f12, $f18, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f10.fl;
    after_1:
    // 0x801D4394: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x801D4398: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x801D439C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801D43A0: swc1        $f0, 0x24($t2)
    MEM_W(0X24, ctx->r10) = ctx->f0.u32l;
    // 0x801D43A4: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x801D43A8: lwc1        $f6, 0x14($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X14);
    // 0x801D43AC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801D43B0: nop

    // 0x801D43B4: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x801D43B8: nop

    // 0x801D43BC: bc1f        L_801D43E8
    if (!c1cs) {
        // 0x801D43C0: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_801D43E8;
    }
    // 0x801D43C0: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x801D43C4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801D43C8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801D43CC: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x801D43D0: swc1        $f16, 0x28($t6)
    MEM_W(0X28, ctx->r14) = ctx->f16.u32l;
    // 0x801D43D4: jal         0x800E4D20
    // 0x801D43D8: lwc1        $f12, 0x14($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X14);
    fabsf_recomp(rdram, ctx);
        goto after_2;
    // 0x801D43D8: lwc1        $f12, 0x14($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X14);
    after_2:
    // 0x801D43DC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x801D43E0: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x801D43E4: swc1        $f0, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->f0.u32l;
L_801D43E8:
    // 0x801D43E8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x801D43EC: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x801D43F0: lwc1        $f4, 0x18($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X18);
    // 0x801D43F4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801D43F8: nop

    // 0x801D43FC: c.lt.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl < ctx->f18.fl;
    // 0x801D4400: nop

    // 0x801D4404: bc1f        L_801D4430
    if (!c1cs) {
        // 0x801D4408: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_801D4430;
    }
    // 0x801D4408: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x801D440C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801D4410: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801D4414: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x801D4418: swc1        $f10, 0x2C($t8)
    MEM_W(0X2C, ctx->r24) = ctx->f10.u32l;
    // 0x801D441C: jal         0x800E4D20
    // 0x801D4420: lwc1        $f12, 0x18($t9)
    ctx->f12.u32l = MEM_W(ctx->r25, 0X18);
    fabsf_recomp(rdram, ctx);
        goto after_3;
    // 0x801D4420: lwc1        $f12, 0x18($t9)
    ctx->f12.u32l = MEM_W(ctx->r25, 0X18);
    after_3:
    // 0x801D4424: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x801D4428: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x801D442C: swc1        $f0, 0x18($t1)
    MEM_W(0X18, ctx->r9) = ctx->f0.u32l;
L_801D4430:
    // 0x801D4430: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x801D4434: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x801D4438: lwc1        $f6, 0x1C($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X1C);
    // 0x801D443C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801D4440: nop

    // 0x801D4444: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x801D4448: nop

    // 0x801D444C: bc1f        L_801D4478
    if (!c1cs) {
        // 0x801D4450: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_801D4478;
    }
    // 0x801D4450: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x801D4454: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801D4458: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x801D445C: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x801D4460: swc1        $f16, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->f16.u32l;
    // 0x801D4464: jal         0x800E4D20
    // 0x801D4468: lwc1        $f12, 0x1C($t3)
    ctx->f12.u32l = MEM_W(ctx->r11, 0X1C);
    fabsf_recomp(rdram, ctx);
        goto after_4;
    // 0x801D4468: lwc1        $f12, 0x1C($t3)
    ctx->f12.u32l = MEM_W(ctx->r11, 0X1C);
    after_4:
    // 0x801D446C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x801D4470: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x801D4474: swc1        $f0, 0x1C($t4)
    MEM_W(0X1C, ctx->r12) = ctx->f0.u32l;
L_801D4478:
    // 0x801D4478: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x801D447C: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x801D4480: lwc1        $f4, 0x14($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X14);
    // 0x801D4484: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801D4488: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x801D448C: swc1        $f4, 0x50($t2)
    MEM_W(0X50, ctx->r10) = ctx->f4.u32l;
    // 0x801D4490: lwc1        $f10, 0x14($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X14);
    // 0x801D4494: lwc1        $f18, 0x18($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X18);
    // 0x801D4498: c.le.s      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.fl <= ctx->f18.fl;
    // 0x801D449C: nop

    // 0x801D44A0: bc1f        L_801D44C0
    if (!c1cs) {
        // 0x801D44A4: nop
    
            goto L_801D44C0;
    }
    // 0x801D44A4: nop

    // 0x801D44A8: lwc1        $f6, 0x1C($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X1C);
    // 0x801D44AC: c.le.s      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.fl <= ctx->f18.fl;
    // 0x801D44B0: nop

    // 0x801D44B4: bc1f        L_801D44C0
    if (!c1cs) {
        // 0x801D44B8: nop
    
            goto L_801D44C0;
    }
    // 0x801D44B8: nop

    // 0x801D44BC: swc1        $f18, 0x50($t6)
    MEM_W(0X50, ctx->r14) = ctx->f18.u32l;
L_801D44C0:
    // 0x801D44C0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801D44C4: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x801D44C8: lwc1        $f8, 0x1C($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X1C);
    // 0x801D44CC: lwc1        $f16, 0x14($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X14);
    // 0x801D44D0: c.le.s      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.fl <= ctx->f8.fl;
    // 0x801D44D4: nop

    // 0x801D44D8: bc1f        L_801D44F8
    if (!c1cs) {
        // 0x801D44DC: nop
    
            goto L_801D44F8;
    }
    // 0x801D44DC: nop

    // 0x801D44E0: lwc1        $f4, 0x18($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X18);
    // 0x801D44E4: c.le.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl <= ctx->f8.fl;
    // 0x801D44E8: nop

    // 0x801D44EC: bc1f        L_801D44F8
    if (!c1cs) {
        // 0x801D44F0: nop
    
            goto L_801D44F8;
    }
    // 0x801D44F0: nop

    // 0x801D44F4: swc1        $f8, 0x50($t7)
    MEM_W(0X50, ctx->r15) = ctx->f8.u32l;
L_801D44F8:
    // 0x801D44F8: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x801D44FC: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x801D4500: lwc1        $f10, 0x14($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X14);
    // 0x801D4504: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801D4508: nop

    // 0x801D450C: c.eq.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl == ctx->f6.fl;
    // 0x801D4510: nop

    // 0x801D4514: bc1t        L_801D4540
    if (c1cs) {
        // 0x801D4518: nop
    
            goto L_801D4540;
    }
    // 0x801D4518: nop

    // 0x801D451C: lwc1        $f18, 0x50($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X50);
    // 0x801D4520: lwc1        $f4, 0x28($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X28);
    // 0x801D4524: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x801D4528: div.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x801D452C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801D4530: mul.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x801D4534: nop

    // 0x801D4538: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x801D453C: swc1        $f10, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->f10.u32l;
L_801D4540:
    // 0x801D4540: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x801D4544: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x801D4548: lwc1        $f18, 0x18($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X18);
    // 0x801D454C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801D4550: nop

    // 0x801D4554: c.eq.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl == ctx->f4.fl;
    // 0x801D4558: nop

    // 0x801D455C: bc1t        L_801D4588
    if (c1cs) {
        // 0x801D4560: nop
    
            goto L_801D4588;
    }
    // 0x801D4560: nop

    // 0x801D4564: lwc1        $f16, 0x50($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X50);
    // 0x801D4568: lwc1        $f6, 0x2C($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X2C);
    // 0x801D456C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x801D4570: div.s       $f8, $f18, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = DIV_S(ctx->f18.fl, ctx->f16.fl);
    // 0x801D4574: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801D4578: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801D457C: nop

    // 0x801D4580: mul.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x801D4584: swc1        $f18, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->f18.u32l;
L_801D4588:
    // 0x801D4588: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801D458C: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x801D4590: lwc1        $f16, 0x1C($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X1C);
    // 0x801D4594: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801D4598: nop

    // 0x801D459C: c.eq.s      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.fl == ctx->f6.fl;
    // 0x801D45A0: nop

    // 0x801D45A4: bc1t        L_801D45D0
    if (c1cs) {
        // 0x801D45A8: nop
    
            goto L_801D45D0;
    }
    // 0x801D45A8: nop

    // 0x801D45AC: lwc1        $f8, 0x50($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X50);
    // 0x801D45B0: lwc1        $f4, 0x30($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X30);
    // 0x801D45B4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x801D45B8: div.s       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f16.fl, ctx->f8.fl);
    // 0x801D45BC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801D45C0: mul.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x801D45C4: nop

    // 0x801D45C8: mul.s       $f16, $f18, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x801D45CC: swc1        $f16, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->f16.u32l;
L_801D45D0:
    // 0x801D45D0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801D45D4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x801D45D8: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x801D45DC: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x801D45E0: lwc1        $f4, 0x24($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X24);
    // 0x801D45E4: c.lt.s      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.fl < ctx->f4.fl;
    // 0x801D45E8: nop

    // 0x801D45EC: bc1f        L_801D46D0
    if (!c1cs) {
        // 0x801D45F0: nop
    
            goto L_801D46D0;
    }
    // 0x801D45F0: nop

L_801D45F4:
    // 0x801D45F4: jal         0x80199214
    // 0x801D45F8: nop

    func_80199214_1501A0(rdram, ctx);
        goto after_5;
    // 0x801D45F8: nop

    after_5:
    // 0x801D45FC: beq         $v0, $zero, L_801D463C
    if (ctx->r2 == 0) {
        // 0x801D4600: nop
    
            goto L_801D463C;
    }
    // 0x801D4600: nop

    // 0x801D4604: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x801D4608: lw          $t0, -0x2E34($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2E34);
    // 0x801D460C: andi        $t3, $t0, 0x1
    ctx->r11 = ctx->r8 & 0X1;
    // 0x801D4610: bne         $t3, $zero, L_801D46D0
    if (ctx->r11 != 0) {
        // 0x801D4614: nop
    
            goto L_801D46D0;
    }
    // 0x801D4614: nop

    // 0x801D4618: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x801D461C: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x801D4620: lw          $a1, 0xC8($t4)
    ctx->r5 = MEM_W(ctx->r12, 0XC8);
    // 0x801D4624: lw          $a2, 0xCC($t4)
    ctx->r6 = MEM_W(ctx->r12, 0XCC);
    // 0x801D4628: lw          $a3, 0xD0($t4)
    ctx->r7 = MEM_W(ctx->r12, 0XD0);
    // 0x801D462C: jal         0x8018AB30
    // 0x801D4630: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    func_8018AB30_1501A0(rdram, ctx);
        goto after_6;
    // 0x801D4630: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_6:
    // 0x801D4634: b           L_801D46D0
    // 0x801D4638: nop

        goto L_801D46D0;
    // 0x801D4638: nop

L_801D463C:
    // 0x801D463C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x801D4640: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x801D4644: lwc1        $f10, 0xC8($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0XC8);
    // 0x801D4648: lwc1        $f18, 0x14($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X14);
    // 0x801D464C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801D4650: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x801D4654: add.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x801D4658: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801D465C: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x801D4660: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x801D4664: swc1        $f6, 0xC8($t2)
    MEM_W(0XC8, ctx->r10) = ctx->f6.u32l;
    // 0x801D4668: lwc1        $f16, 0xCC($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0XCC);
    // 0x801D466C: lwc1        $f8, 0x18($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X18);
    // 0x801D4670: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x801D4674: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x801D4678: add.s       $f4, $f16, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x801D467C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801D4680: swc1        $f4, 0xCC($t6)
    MEM_W(0XCC, ctx->r14) = ctx->f4.u32l;
    // 0x801D4684: lwc1        $f10, 0xD0($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0XD0);
    // 0x801D4688: lwc1        $f18, 0x1C($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0X1C);
    // 0x801D468C: add.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x801D4690: swc1        $f6, 0xD0($t7)
    MEM_W(0XD0, ctx->r15) = ctx->f6.u32l;
    // 0x801D4694: lwc1        $f16, 0x18($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X18);
    // 0x801D4698: add.s       $f4, $f16, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x801D469C: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x801D46A0: lwc1        $f10, 0x24($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X24);
    // 0x801D46A4: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x801D46A8: nop

    // 0x801D46AC: bc1t        L_801D45F4
    if (c1cs) {
        // 0x801D46B0: nop
    
            goto L_801D45F4;
    }
    // 0x801D46B0: nop

    // 0x801D46B4: b           L_801D46D0
    // 0x801D46B8: nop

        goto L_801D46D0;
    // 0x801D46B8: nop

L_801D46BC:
    // 0x801D46BC: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x801D46C0: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x801D46C4: sltiu       $at, $t9, 0x30
    ctx->r1 = ctx->r25 < 0X30 ? 1 : 0;
    // 0x801D46C8: bne         $at, $zero, L_801D3E68
    if (ctx->r1 != 0) {
        // 0x801D46CC: sw          $t9, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r25;
            goto L_801D3E68;
    }
    // 0x801D46CC: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
L_801D46D0:
    // 0x801D46D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801D46D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801D46D8: jr          $ra
    // 0x801D46DC: nop

    return;
    // 0x801D46DC: nop

;}
