#include "recomp.h"
extern void load_overlays(uint32_t rom, int32_t ram_addr, uint32_t size);
extern void unload_overlays(int32_t ram_addr, uint32_t size);
#include "funcs.h"

RECOMP_FUNC void func_801E05F4_0BA450(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E05F4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801E05F8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801E05FC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801E0600: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_801E0604:
    // 0x801E0604: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x801E0608: lui         $t9, 0x801E
    ctx->r25 = S32(0X801E << 16);
    // 0x801E060C: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x801E0610: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x801E0614: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x801E0618: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x801E061C: lhu         $t9, 0x7DE0($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X7DE0);
    // 0x801E0620: beq         $t9, $at, L_801E07AC
    if (ctx->r25 == ctx->r1) {
        // 0x801E0624: nop
    
            goto L_801E07AC;
    }
    // 0x801E0624: nop

    // 0x801E0628: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x801E062C: lui         $t3, 0x801E
    ctx->r11 = S32(0X801E << 16);
    // 0x801E0630: addiu       $t3, $t3, 0x7DE0
    ctx->r11 = ADD32(ctx->r11, 0X7DE0);
    // 0x801E0634: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x801E0638: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x801E063C: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x801E0640: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801E0644: lw          $t6, -0x2E34($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2E34);
    // 0x801E0648: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x801E064C: bne         $t5, $t6, L_801E079C
    if (ctx->r13 != ctx->r14) {
        // 0x801E0650: nop
    
            goto L_801E079C;
    }
    // 0x801E0650: nop

    // 0x801E0654: lhu         $s0, 0x2($t4)
    ctx->r16 = MEM_HU(ctx->r12, 0X2);
    // 0x801E0658: slti        $at, $s0, 0x20
    ctx->r1 = SIGNED(ctx->r16) < 0X20 ? 1 : 0;
    // 0x801E065C: bne         $at, $zero, L_801E0674
    if (ctx->r1 != 0) {
        // 0x801E0660: addiu       $at, $zero, 0xFF
        ctx->r1 = ADD32(0, 0XFF);
            goto L_801E0674;
    }
    // 0x801E0660: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x801E0664: beq         $s0, $at, L_801E0788
    if (ctx->r16 == ctx->r1) {
        // 0x801E0668: nop
    
            goto L_801E0788;
    }
    // 0x801E0668: nop

    // 0x801E066C: b           L_801E079C
    // 0x801E0670: nop

        goto L_801E079C;
    // 0x801E0670: nop

L_801E0674:
    // 0x801E0674: sltiu       $at, $s0, 0x20
    ctx->r1 = ctx->r16 < 0X20 ? 1 : 0;
    // 0x801E0678: beq         $at, $zero, L_801E079C
    if (ctx->r1 == 0) {
        // 0x801E067C: nop
    
            goto L_801E079C;
    }
    // 0x801E067C: nop

    // 0x801E0680: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x801E0684: lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // 0x801E0688: addu        $at, $at, $t7
    gpr jr_addend_801E0690 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x801E068C: lw          $t7, -0x17C0($at)
    ctx->r15 = ADD32(ctx->r1, -0X17C0);
    // 0x801E0690: jr          $t7
    // 0x801E0694: nop

    switch (jr_addend_801E0690 >> 2) {
        case 0: goto L_801E06A8; break;
        case 1: goto L_801E0698; break;
        case 2: goto L_801E079C; break;
        case 3: goto L_801E079C; break;
        case 4: goto L_801E079C; break;
        case 5: goto L_801E079C; break;
        case 6: goto L_801E079C; break;
        case 7: goto L_801E079C; break;
        case 8: goto L_801E079C; break;
        case 9: goto L_801E079C; break;
        case 10: goto L_801E06B8; break;
        case 11: goto L_801E06CC; break;
        case 12: goto L_801E079C; break;
        case 13: goto L_801E079C; break;
        case 14: goto L_801E079C; break;
        case 15: goto L_801E079C; break;
        case 16: goto L_801E079C; break;
        case 17: goto L_801E079C; break;
        case 18: goto L_801E079C; break;
        case 19: goto L_801E079C; break;
        case 20: goto L_801E06E0; break;
        case 21: goto L_801E06F4; break;
        case 22: goto L_801E079C; break;
        case 23: goto L_801E079C; break;
        case 24: goto L_801E079C; break;
        case 25: goto L_801E079C; break;
        case 26: goto L_801E079C; break;
        case 27: goto L_801E079C; break;
        case 28: goto L_801E079C; break;
        case 29: goto L_801E079C; break;
        case 30: goto L_801E0748; break;
        case 31: goto L_801E0708; break;
        default: switch_error(__func__, 0x801E0690, 0x801EE840);
    }
    // 0x801E0694: nop

L_801E0698:
    // 0x801E0698: jal         0x800C3320
    // 0x801E069C: nop

    func_800C3320(rdram, ctx);
        goto after_0;
    // 0x801E069C: nop

    after_0:
    // 0x801E06A0: b           L_801E079C
    // 0x801E06A4: nop

        goto L_801E079C;
    // 0x801E06A4: nop

L_801E06A8:
    // 0x801E06A8: jal         0x800C3308
    // 0x801E06AC: nop

    func_800C3308(rdram, ctx);
        goto after_1;
    // 0x801E06AC: nop

    after_1:
    // 0x801E06B0: b           L_801E079C
    // 0x801E06B4: nop

        goto L_801E079C;
    // 0x801E06B4: nop

L_801E06B8:
    // 0x801E06B8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801E06BC: addiu       $t9, $t9, -0x2E18
    ctx->r25 = ADD32(ctx->r25, -0X2E18);
    // 0x801E06C0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801E06C4: b           L_801E079C
    // 0x801E06C8: sw          $t8, 0x28($t9)
    MEM_W(0X28, ctx->r25) = ctx->r24;
        goto L_801E079C;
    // 0x801E06C8: sw          $t8, 0x28($t9)
    MEM_W(0X28, ctx->r25) = ctx->r24;
L_801E06CC:
    // 0x801E06CC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x801E06D0: addiu       $t1, $t1, -0x2E18
    ctx->r9 = ADD32(ctx->r9, -0X2E18);
    // 0x801E06D4: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x801E06D8: b           L_801E079C
    // 0x801E06DC: sw          $t0, 0x28($t1)
    MEM_W(0X28, ctx->r9) = ctx->r8;
        goto L_801E079C;
    // 0x801E06DC: sw          $t0, 0x28($t1)
    MEM_W(0X28, ctx->r9) = ctx->r8;
L_801E06E0:
    // 0x801E06E0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x801E06E4: addiu       $t3, $t3, 0x3C00
    ctx->r11 = ADD32(ctx->r11, 0X3C00);
    // 0x801E06E8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801E06EC: b           L_801E079C
    // 0x801E06F0: sw          $t2, 0xFC($t3)
    MEM_W(0XFC, ctx->r11) = ctx->r10;
        goto L_801E079C;
    // 0x801E06F0: sw          $t2, 0xFC($t3)
    MEM_W(0XFC, ctx->r11) = ctx->r10;
L_801E06F4:
    // 0x801E06F4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801E06F8: addiu       $t6, $t6, 0x3C00
    ctx->r14 = ADD32(ctx->r14, 0X3C00);
    // 0x801E06FC: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x801E0700: b           L_801E079C
    // 0x801E0704: sw          $t5, 0xFC($t6)
    MEM_W(0XFC, ctx->r14) = ctx->r13;
        goto L_801E079C;
    // 0x801E0704: sw          $t5, 0xFC($t6)
    MEM_W(0XFC, ctx->r14) = ctx->r13;
L_801E0708:
    // 0x801E0708: addiu       $a0, $zero, 0xFA
    ctx->r4 = ADD32(0, 0XFA);
    // 0x801E070C: addiu       $a1, $zero, 0xFA
    ctx->r5 = ADD32(0, 0XFA);
    // 0x801E0710: jal         0x800C6E0C
    // 0x801E0714: addiu       $a2, $zero, 0xFA
    ctx->r6 = ADD32(0, 0XFA);
    func_800C6E0C(rdram, ctx);
        goto after_2;
    // 0x801E0714: addiu       $a2, $zero, 0xFA
    ctx->r6 = ADD32(0, 0XFA);
    after_2:
    // 0x801E0718: addiu       $t4, $zero, 0x1E
    ctx->r12 = ADD32(0, 0X1E);
    // 0x801E071C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x801E0720: addiu       $a0, $zero, 0xFA
    ctx->r4 = ADD32(0, 0XFA);
    // 0x801E0724: addiu       $a1, $zero, 0xFA
    ctx->r5 = ADD32(0, 0XFA);
    // 0x801E0728: addiu       $a2, $zero, 0xFA
    ctx->r6 = ADD32(0, 0XFA);
    // 0x801E072C: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    // 0x801E0730: jal         0x800C6E68
    // 0x801E0734: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_800C6E68(rdram, ctx);
        goto after_3;
    // 0x801E0734: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_3:
    // 0x801E0738: jal         0x800C6DBC
    // 0x801E073C: nop

    func_800C6DBC(rdram, ctx);
        goto after_4;
    // 0x801E073C: nop

    after_4:
    // 0x801E0740: b           L_801E079C
    // 0x801E0744: nop

        goto L_801E079C;
    // 0x801E0744: nop

L_801E0748:
    // 0x801E0748: addiu       $a0, $zero, 0x78
    ctx->r4 = ADD32(0, 0X78);
    // 0x801E074C: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    // 0x801E0750: jal         0x800C6E0C
    // 0x801E0754: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    func_800C6E0C(rdram, ctx);
        goto after_5;
    // 0x801E0754: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    after_5:
    // 0x801E0758: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x801E075C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801E0760: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x801E0764: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    // 0x801E0768: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    // 0x801E076C: addiu       $a3, $zero, 0x1E
    ctx->r7 = ADD32(0, 0X1E);
    // 0x801E0770: jal         0x800C6E68
    // 0x801E0774: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_800C6E68(rdram, ctx);
        goto after_6;
    // 0x801E0774: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_6:
    // 0x801E0778: jal         0x800C6DBC
    // 0x801E077C: nop

    func_800C6DBC(rdram, ctx);
        goto after_7;
    // 0x801E077C: nop

    after_7:
    // 0x801E0780: b           L_801E079C
    // 0x801E0784: nop

        goto L_801E079C;
    // 0x801E0784: nop

L_801E0788:
    // 0x801E0788: jal         0x800C32CC
    // 0x801E078C: nop

    func_800C32CC(rdram, ctx);
        goto after_8;
    // 0x801E078C: nop

    after_8:
    // 0x801E0790: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x801E0794: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801E0798: sw          $t8, -0x2E4C($at)
    MEM_W(-0X2E4C, ctx->r1) = ctx->r24;
L_801E079C:
    // 0x801E079C: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x801E07A0: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x801E07A4: b           L_801E0604
    // 0x801E07A8: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
        goto L_801E0604;
    // 0x801E07A8: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
L_801E07AC:
    // 0x801E07AC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x801E07B0: addiu       $t1, $t1, 0x3C00
    ctx->r9 = ADD32(ctx->r9, 0X3C00);
    // 0x801E07B4: lw          $s0, 0xFC($t1)
    ctx->r16 = MEM_W(ctx->r9, 0XFC);
    // 0x801E07B8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801E07BC: beq         $s0, $at, L_801E07D4
    if (ctx->r16 == ctx->r1) {
        // 0x801E07C0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_801E07D4;
    }
    // 0x801E07C0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801E07C4: beq         $s0, $at, L_801E080C
    if (ctx->r16 == ctx->r1) {
        // 0x801E07C8: nop
    
            goto L_801E080C;
    }
    // 0x801E07C8: nop

    // 0x801E07CC: b           L_801E082C
    // 0x801E07D0: nop

        goto L_801E082C;
    // 0x801E07D0: nop

L_801E07D4:
    // 0x801E07D4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x801E07D8: addiu       $t2, $t2, 0x3D00
    ctx->r10 = ADD32(ctx->r10, 0X3D00);
    // 0x801E07DC: lw          $t3, 0xFC($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XFC);
    // 0x801E07E0: addiu       $at, $zero, -0x352
    ctx->r1 = ADD32(0, -0X352);
    // 0x801E07E4: beq         $t3, $at, L_801E082C
    if (ctx->r11 == ctx->r1) {
        // 0x801E07E8: nop
    
            goto L_801E082C;
    }
    // 0x801E07E8: nop

    // 0x801E07EC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x801E07F0: lw          $t5, -0x2E34($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2E34);
    // 0x801E07F4: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x801E07F8: beq         $t6, $zero, L_801E082C
    if (ctx->r14 == 0) {
        // 0x801E07FC: nop
    
            goto L_801E082C;
    }
    // 0x801E07FC: nop

    // 0x801E0800: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x801E0804: b           L_801E082C
    // 0x801E0808: sw          $t4, 0xFC($t2)
    MEM_W(0XFC, ctx->r10) = ctx->r12;
        goto L_801E082C;
    // 0x801E0808: sw          $t4, 0xFC($t2)
    MEM_W(0XFC, ctx->r10) = ctx->r12;
L_801E080C:
    // 0x801E080C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801E0810: addiu       $t7, $t7, 0x3B00
    ctx->r15 = ADD32(ctx->r15, 0X3B00);
    // 0x801E0814: lbu         $t8, 0x3F($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X3F);
    // 0x801E0818: addiu       $at, $zero, 0xC8
    ctx->r1 = ADD32(0, 0XC8);
    // 0x801E081C: beq         $t8, $at, L_801E082C
    if (ctx->r24 == ctx->r1) {
        // 0x801E0820: nop
    
            goto L_801E082C;
    }
    // 0x801E0820: nop

    // 0x801E0824: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x801E0828: sb          $t9, 0x3F($t7)
    MEM_B(0X3F, ctx->r15) = ctx->r25;
L_801E082C:
    // 0x801E082C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801E0830: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801E0834: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801E0838: jr          $ra
    // 0x801E083C: nop

    return;
    // 0x801E083C: nop

;}
RECOMP_FUNC void func_801E0840_0BA450(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E0840: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801E0844: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801E0848: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x801E084C: jal         0x800D54C8
    // 0x801E0850: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    spX2Init_recomp(rdram, ctx);
        goto after_0;
    // 0x801E0850: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    after_0:
    // 0x801E0854: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801E0858: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801E085C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801E0860: addiu       $t6, $t6, 0x3D00
    ctx->r14 = ADD32(ctx->r14, 0X3D00);
    // 0x801E0864: lw          $a2, 0xFC($t6)
    ctx->r6 = MEM_W(ctx->r14, 0XFC);
    // 0x801E0868: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801E086C: addiu       $t7, $zero, 0xC8
    ctx->r15 = ADD32(0, 0XC8);
    // 0x801E0870: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801E0874: addiu       $a0, $a0, -0x5468
    ctx->r4 = ADD32(ctx->r4, -0X5468);
    // 0x801E0878: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x801E087C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801E0880: jal         0x800C6C6C
    // 0x801E0884: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_1;
    // 0x801E0884: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x801E0888: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801E088C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801E0890: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x801E0894: addiu       $t8, $t8, 0x3B00
    ctx->r24 = ADD32(ctx->r24, 0X3B00);
    // 0x801E0898: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x801E089C: lbu         $t9, 0x3F($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X3F);
    // 0x801E08A0: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801E08A4: addiu       $a0, $a0, -0x5314
    ctx->r4 = ADD32(ctx->r4, -0X5314);
    // 0x801E08A8: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    // 0x801E08AC: addiu       $a2, $zero, 0x6C
    ctx->r6 = ADD32(0, 0X6C);
    // 0x801E08B0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801E08B4: jal         0x800C6C6C
    // 0x801E08B8: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    func_800C6C6C(rdram, ctx);
        goto after_2;
    // 0x801E08B8: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_2:
    // 0x801E08BC: jal         0x800C6D5C
    // 0x801E08C0: nop

    func_800C6D5C(rdram, ctx);
        goto after_3;
    // 0x801E08C0: nop

    after_3:
    // 0x801E08C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801E08C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801E08CC: jr          $ra
    // 0x801E08D0: nop

    return;
    // 0x801E08D0: nop

;}
RECOMP_FUNC void func_801E08D4_0BA450(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E08D4: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x801E08D8: lw          $t6, -0x4514($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4514);
    // 0x801E08DC: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x801E08E0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x801E08E4: sw          $t6, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r14;
    // 0x801E08E8: lw          $t9, 0xC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC);
    // 0x801E08EC: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x801E08F0: sw          $t7, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r15;
    // 0x801E08F4: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x801E08F8: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x801E08FC: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x801E0900: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x801E0904: lui         $t3, 0xD900
    ctx->r11 = S32(0XD900 << 16);
    // 0x801E0908: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x801E090C: lw          $t1, -0x4514($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4514);
    // 0x801E0910: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x801E0914: lui         $t8, 0xDE00
    ctx->r24 = S32(0XDE00 << 16);
    // 0x801E0918: sw          $t1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r9;
    // 0x801E091C: lw          $t4, 0x8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X8);
    // 0x801E0920: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x801E0924: sw          $t2, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r10;
    // 0x801E0928: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x801E092C: lw          $t5, 0x8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8);
    // 0x801E0930: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x801E0934: addiu       $t0, $t0, -0x51D0
    ctx->r8 = ADD32(ctx->r8, -0X51D0);
    // 0x801E0938: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
    // 0x801E093C: lw          $t6, -0x4514($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4514);
    // 0x801E0940: lui         $t2, 0x8011
    ctx->r10 = S32(0X8011 << 16);
    // 0x801E0944: lui         $t4, 0xE300
    ctx->r12 = S32(0XE300 << 16);
    // 0x801E0948: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x801E094C: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x801E0950: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x801E0954: sw          $t7, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r15;
    // 0x801E0958: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x801E095C: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x801E0960: ori         $t4, $t4, 0x1001
    ctx->r12 = ctx->r12 | 0X1001;
    // 0x801E0964: ori         $t6, $zero, 0x8000
    ctx->r14 = 0 | 0X8000;
    // 0x801E0968: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x801E096C: lw          $t2, -0x4514($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4514);
    // 0x801E0970: sw          $t2, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r10;
    // 0x801E0974: lw          $t5, 0x0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X0);
    // 0x801E0978: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x801E097C: sw          $t3, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r11;
    // 0x801E0980: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x801E0984: lw          $t7, 0x0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X0);
    // 0x801E0988: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    // 0x801E098C: jr          $ra
    // 0x801E0990: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    return;
    // 0x801E0990: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
;}
RECOMP_FUNC void func_801E0994_0BA450(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E0994: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x801E0998: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801E099C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801E09A0: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x801E09A4: addiu       $t6, $t6, -0x2E18
    ctx->r14 = ADD32(ctx->r14, -0X2E18);
    // 0x801E09A8: lw          $s0, 0x28($t6)
    ctx->r16 = MEM_W(ctx->r14, 0X28);
    // 0x801E09AC: beq         $s0, $zero, L_801E09CC
    if (ctx->r16 == 0) {
        // 0x801E09B0: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_801E09CC;
    }
    // 0x801E09B0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801E09B4: beq         $s0, $at, L_801E0A98
    if (ctx->r16 == ctx->r1) {
        // 0x801E09B8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_801E0A98;
    }
    // 0x801E09B8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801E09BC: beq         $s0, $at, L_801E0AFC
    if (ctx->r16 == ctx->r1) {
        // 0x801E09C0: nop
    
            goto L_801E0AFC;
    }
    // 0x801E09C0: nop

    // 0x801E09C4: b           L_801E0B58
    // 0x801E09C8: nop

        goto L_801E0B58;
    // 0x801E09C8: nop

L_801E09CC:
    // 0x801E09CC: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x801E09D0: jal         0x800D54C8
    // 0x801E09D4: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    spX2Init_recomp(rdram, ctx);
        goto after_0;
    // 0x801E09D4: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    after_0:
    // 0x801E09D8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801E09DC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801E09E0: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x801E09E4: addiu       $t7, $zero, 0x80
    ctx->r15 = ADD32(0, 0X80);
    // 0x801E09E8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801E09EC: addiu       $a0, $a0, -0x6FD4
    ctx->r4 = ADD32(ctx->r4, -0X6FD4);
    // 0x801E09F0: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    // 0x801E09F4: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    // 0x801E09F8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801E09FC: jal         0x800C6C6C
    // 0x801E0A00: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_1;
    // 0x801E0A00: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x801E0A04: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801E0A08: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801E0A0C: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x801E0A10: addiu       $t8, $zero, 0x80
    ctx->r24 = ADD32(0, 0X80);
    // 0x801E0A14: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x801E0A18: addiu       $a0, $a0, -0x6F90
    ctx->r4 = ADD32(ctx->r4, -0X6F90);
    // 0x801E0A1C: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x801E0A20: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801E0A24: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801E0A28: jal         0x800C6C6C
    // 0x801E0A2C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_2;
    // 0x801E0A2C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x801E0A30: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801E0A34: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801E0A38: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x801E0A3C: addiu       $t9, $zero, 0x80
    ctx->r25 = ADD32(0, 0X80);
    // 0x801E0A40: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x801E0A44: addiu       $a0, $a0, -0x6F4C
    ctx->r4 = ADD32(ctx->r4, -0X6F4C);
    // 0x801E0A48: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801E0A4C: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    // 0x801E0A50: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801E0A54: jal         0x800C6C6C
    // 0x801E0A58: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_3;
    // 0x801E0A58: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_3:
    // 0x801E0A5C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801E0A60: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801E0A64: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x801E0A68: addiu       $t0, $zero, 0x80
    ctx->r8 = ADD32(0, 0X80);
    // 0x801E0A6C: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x801E0A70: addiu       $a0, $a0, -0x6F08
    ctx->r4 = ADD32(ctx->r4, -0X6F08);
    // 0x801E0A74: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x801E0A78: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    // 0x801E0A7C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801E0A80: jal         0x800C6C6C
    // 0x801E0A84: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_4;
    // 0x801E0A84: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_4:
    // 0x801E0A88: jal         0x800C6D5C
    // 0x801E0A8C: nop

    func_800C6D5C(rdram, ctx);
        goto after_5;
    // 0x801E0A8C: nop

    after_5:
    // 0x801E0A90: b           L_801E0B58
    // 0x801E0A94: nop

        goto L_801E0B58;
    // 0x801E0A94: nop

L_801E0A98:
    // 0x801E0A98: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801E0A9C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801E0AA0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801E0AA4: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x801E0AA8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801E0AAC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801E0AB0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801E0AB4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801E0AB8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801E0ABC: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801E0AC0: ori         $t1, $zero, 0xFFFF
    ctx->r9 = 0 | 0XFFFF;
    // 0x801E0AC4: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x801E0AC8: addiu       $a0, $a0, -0x4700
    ctx->r4 = ADD32(ctx->r4, -0X4700);
    // 0x801E0ACC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801E0AD0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801E0AD4: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x801E0AD8: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x801E0ADC: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    // 0x801E0AE0: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x801E0AE4: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x801E0AE8: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x801E0AEC: jal         0x800C58E8
    // 0x801E0AF0: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    func_800C58E8(rdram, ctx);
        goto after_6;
    // 0x801E0AF0: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    after_6:
    // 0x801E0AF4: b           L_801E0B58
    // 0x801E0AF8: nop

        goto L_801E0B58;
    // 0x801E0AF8: nop

L_801E0AFC:
    // 0x801E0AFC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801E0B00: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801E0B04: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801E0B08: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x801E0B0C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801E0B10: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801E0B14: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801E0B18: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801E0B1C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801E0B20: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801E0B24: ori         $t2, $zero, 0xFFFF
    ctx->r10 = 0 | 0XFFFF;
    // 0x801E0B28: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x801E0B2C: addiu       $a0, $a0, -0x46B0
    ctx->r4 = ADD32(ctx->r4, -0X46B0);
    // 0x801E0B30: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801E0B34: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801E0B38: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x801E0B3C: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x801E0B40: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    // 0x801E0B44: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x801E0B48: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x801E0B4C: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    // 0x801E0B50: jal         0x800C58E8
    // 0x801E0B54: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    func_800C58E8(rdram, ctx);
        goto after_7;
    // 0x801E0B54: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    after_7:
L_801E0B58:
    // 0x801E0B58: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x801E0B5C: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x801E0B60: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x801E0B64: jr          $ra
    // 0x801E0B68: nop

    return;
    // 0x801E0B68: nop

;}
RECOMP_FUNC void func_801E0B6C_0BA450(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E0B6C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x801E0B70: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x801E0B74: lw          $t6, -0x4514($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4514);
    // 0x801E0B78: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x801E0B7C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x801E0B80: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    // 0x801E0B84: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x801E0B88: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x801E0B8C: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x801E0B90: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x801E0B94: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x801E0B98: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x801E0B9C: sw          $t7, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r15;
    // 0x801E0BA0: lui         $t8, 0xDE00
    ctx->r24 = S32(0XDE00 << 16);
    // 0x801E0BA4: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x801E0BA8: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x801E0BAC: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x801E0BB0: addiu       $t0, $t0, -0x59F0
    ctx->r8 = ADD32(ctx->r8, -0X59F0);
    // 0x801E0BB4: lui         $t2, 0x8011
    ctx->r10 = S32(0X8011 << 16);
    // 0x801E0BB8: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x801E0BBC: lw          $t2, -0x4514($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4514);
    // 0x801E0BC0: lui         $t4, 0xE700
    ctx->r12 = S32(0XE700 << 16);
    // 0x801E0BC4: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x801E0BC8: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
    // 0x801E0BCC: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x801E0BD0: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x801E0BD4: sw          $t3, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r11;
    // 0x801E0BD8: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x801E0BDC: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x801E0BE0: lui         $t9, 0xFB00
    ctx->r25 = S32(0XFB00 << 16);
    // 0x801E0BE4: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x801E0BE8: lw          $t7, -0x4514($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4514);
    // 0x801E0BEC: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x801E0BF0: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x801E0BF4: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x801E0BF8: sw          $t8, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r24;
    // 0x801E0BFC: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x801E0C00: lbu         $t1, 0x67($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X67);
    // 0x801E0C04: lbu         $t4, 0x6B($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X6B);
    // 0x801E0C08: lbu         $t8, 0x6F($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X6F);
    // 0x801E0C0C: andi        $t2, $t1, 0xFF
    ctx->r10 = ctx->r9 & 0XFF;
    // 0x801E0C10: sll         $t3, $t2, 24
    ctx->r11 = S32(ctx->r10 << 24);
    // 0x801E0C14: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x801E0C18: lbu         $t2, 0x73($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X73);
    // 0x801E0C1C: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x801E0C20: or          $t7, $t3, $t6
    ctx->r15 = ctx->r11 | ctx->r14;
    // 0x801E0C24: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x801E0C28: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x801E0C2C: sll         $t0, $t9, 8
    ctx->r8 = S32(ctx->r25 << 8);
    // 0x801E0C30: or          $t1, $t7, $t0
    ctx->r9 = ctx->r15 | ctx->r8;
    // 0x801E0C34: andi        $t4, $t2, 0xFF
    ctx->r12 = ctx->r10 & 0XFF;
    // 0x801E0C38: or          $t5, $t1, $t4
    ctx->r13 = ctx->r9 | ctx->r12;
    // 0x801E0C3C: sw          $t5, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r13;
    // 0x801E0C40: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x801E0C44: beq         $t6, $zero, L_801E0E28
    if (ctx->r14 == 0) {
        // 0x801E0C48: nop
    
            goto L_801E0E28;
    }
    // 0x801E0C48: nop

    // 0x801E0C4C: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x801E0C50: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801E0C54: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x801E0C58: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x801E0C5C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x801E0C60: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x801E0C64: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x801E0C68: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x801E0C6C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x801E0C70: addu        $t7, $t7, $t9
    ctx->r15 = ADD32(ctx->r15, ctx->r25);
    // 0x801E0C74: lw          $t7, -0x2A04($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2A04);
    // 0x801E0C78: andi        $t0, $t7, 0x8
    ctx->r8 = ctx->r15 & 0X8;
    // 0x801E0C7C: beq         $t0, $zero, L_801E0D24
    if (ctx->r8 == 0) {
        // 0x801E0C80: nop
    
            goto L_801E0D24;
    }
    // 0x801E0C80: nop

    // 0x801E0C84: lui         $t2, 0x8011
    ctx->r10 = S32(0X8011 << 16);
    // 0x801E0C88: lw          $t2, -0x4514($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4514);
    // 0x801E0C8C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x801E0C90: lui         $t4, 0xFA00
    ctx->r12 = S32(0XFA00 << 16);
    // 0x801E0C94: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    // 0x801E0C98: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x801E0C9C: addiu       $t1, $t2, 0x8
    ctx->r9 = ADD32(ctx->r10, 0X8);
    // 0x801E0CA0: sw          $t1, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r9;
    // 0x801E0CA4: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x801E0CA8: lbu         $t3, 0x57($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X57);
    // 0x801E0CAC: lbu         $t9, 0x5B($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X5B);
    // 0x801E0CB0: lbu         $t1, 0x5F($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X5F);
    // 0x801E0CB4: andi        $t6, $t3, 0xFF
    ctx->r14 = ctx->r11 & 0XFF;
    // 0x801E0CB8: sll         $t8, $t6, 24
    ctx->r24 = S32(ctx->r14 << 24);
    // 0x801E0CBC: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x801E0CC0: andi        $t7, $t9, 0xFF
    ctx->r15 = ctx->r25 & 0XFF;
    // 0x801E0CC4: sll         $t0, $t7, 16
    ctx->r8 = S32(ctx->r15 << 16);
    // 0x801E0CC8: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x801E0CCC: addu        $t9, $t9, $t6
    ctx->r25 = ADD32(ctx->r25, ctx->r14);
    // 0x801E0CD0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x801E0CD4: subu        $t9, $t9, $t6
    ctx->r25 = SUB32(ctx->r25, ctx->r14);
    // 0x801E0CD8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x801E0CDC: addu        $t9, $t9, $t6
    ctx->r25 = ADD32(ctx->r25, ctx->r14);
    // 0x801E0CE0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x801E0CE4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801E0CE8: addu        $t7, $t7, $t9
    ctx->r15 = ADD32(ctx->r15, ctx->r25);
    // 0x801E0CEC: lw          $t7, -0x2A04($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2A04);
    // 0x801E0CF0: or          $t2, $t8, $t0
    ctx->r10 = ctx->r24 | ctx->r8;
    // 0x801E0CF4: andi        $t4, $t1, 0xFF
    ctx->r12 = ctx->r9 & 0XFF;
    // 0x801E0CF8: sll         $t5, $t4, 8
    ctx->r13 = S32(ctx->r12 << 8);
    // 0x801E0CFC: andi        $t8, $t7, 0x7
    ctx->r24 = ctx->r15 & 0X7;
    // 0x801E0D00: sll         $t0, $t8, 5
    ctx->r8 = S32(ctx->r24 << 5);
    // 0x801E0D04: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x801E0D08: subu        $t4, $t1, $t0
    ctx->r12 = SUB32(ctx->r9, ctx->r8);
    // 0x801E0D0C: or          $t3, $t2, $t5
    ctx->r11 = ctx->r10 | ctx->r13;
    // 0x801E0D10: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x801E0D14: andi        $t2, $t4, 0xFF
    ctx->r10 = ctx->r12 & 0XFF;
    // 0x801E0D18: or          $t5, $t2, $t3
    ctx->r13 = ctx->r10 | ctx->r11;
    // 0x801E0D1C: b           L_801E0DBC
    // 0x801E0D20: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
        goto L_801E0DBC;
    // 0x801E0D20: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
L_801E0D24:
    // 0x801E0D24: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x801E0D28: lw          $t9, -0x4514($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4514);
    // 0x801E0D2C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x801E0D30: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x801E0D34: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x801E0D38: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x801E0D3C: addiu       $t7, $t9, 0x8
    ctx->r15 = ADD32(ctx->r25, 0X8);
    // 0x801E0D40: sw          $t7, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r15;
    // 0x801E0D44: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x801E0D48: lbu         $t0, 0x57($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X57);
    // 0x801E0D4C: lbu         $t3, 0x5B($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X5B);
    // 0x801E0D50: lbu         $t7, 0x5F($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X5F);
    // 0x801E0D54: andi        $t4, $t0, 0xFF
    ctx->r12 = ctx->r8 & 0XFF;
    // 0x801E0D58: sll         $t2, $t4, 24
    ctx->r10 = S32(ctx->r12 << 24);
    // 0x801E0D5C: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x801E0D60: andi        $t5, $t3, 0xFF
    ctx->r13 = ctx->r11 & 0XFF;
    // 0x801E0D64: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x801E0D68: sll         $t3, $t4, 2
    ctx->r11 = S32(ctx->r12 << 2);
    // 0x801E0D6C: addu        $t3, $t3, $t4
    ctx->r11 = ADD32(ctx->r11, ctx->r12);
    // 0x801E0D70: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x801E0D74: subu        $t3, $t3, $t4
    ctx->r11 = SUB32(ctx->r11, ctx->r12);
    // 0x801E0D78: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x801E0D7C: addu        $t3, $t3, $t4
    ctx->r11 = ADD32(ctx->r11, ctx->r12);
    // 0x801E0D80: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x801E0D84: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x801E0D88: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x801E0D8C: lw          $t5, -0x2A04($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2A04);
    // 0x801E0D90: or          $t9, $t2, $t6
    ctx->r25 = ctx->r10 | ctx->r14;
    // 0x801E0D94: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x801E0D98: sll         $t1, $t8, 8
    ctx->r9 = S32(ctx->r24 << 8);
    // 0x801E0D9C: andi        $t2, $t5, 0x7
    ctx->r10 = ctx->r13 & 0X7;
    // 0x801E0DA0: sll         $t6, $t2, 5
    ctx->r14 = S32(ctx->r10 << 5);
    // 0x801E0DA4: or          $t0, $t9, $t1
    ctx->r8 = ctx->r25 | ctx->r9;
    // 0x801E0DA8: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x801E0DAC: addiu       $t7, $t6, 0x1F
    ctx->r15 = ADD32(ctx->r14, 0X1F);
    // 0x801E0DB0: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x801E0DB4: or          $t9, $t8, $t0
    ctx->r25 = ctx->r24 | ctx->r8;
    // 0x801E0DB8: sw          $t9, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r25;
L_801E0DBC:
    // 0x801E0DBC: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x801E0DC0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x801E0DC4: addiu       $t5, $t5, -0x2A28
    ctx->r13 = ADD32(ctx->r13, -0X2A28);
    // 0x801E0DC8: sll         $t3, $t4, 2
    ctx->r11 = S32(ctx->r12 << 2);
    // 0x801E0DCC: addu        $t3, $t3, $t4
    ctx->r11 = ADD32(ctx->r11, ctx->r12);
    // 0x801E0DD0: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x801E0DD4: subu        $t3, $t3, $t4
    ctx->r11 = SUB32(ctx->r11, ctx->r12);
    // 0x801E0DD8: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x801E0DDC: addu        $t3, $t3, $t4
    ctx->r11 = ADD32(ctx->r11, ctx->r12);
    // 0x801E0DE0: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x801E0DE4: addu        $t2, $t3, $t5
    ctx->r10 = ADD32(ctx->r11, ctx->r13);
    // 0x801E0DE8: lwc1        $f4, 0x68($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X68);
    // 0x801E0DEC: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x801E0DF0: lw          $a2, 0x60($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X60);
    // 0x801E0DF4: lw          $a3, 0x64($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X64);
    // 0x801E0DF8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801E0DFC: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x801E0E00: addiu       $a0, $a0, -0x4818
    ctx->r4 = ADD32(ctx->r4, -0X4818);
    // 0x801E0E04: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801E0E08: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x801E0E0C: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x801E0E10: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x801E0E14: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x801E0E18: jal         0x800C6144
    // 0x801E0E1C: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    func_800C6144(rdram, ctx);
        goto after_0;
    // 0x801E0E1C: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x801E0E20: b           L_801E0F6C
    // 0x801E0E24: nop

        goto L_801E0F6C;
    // 0x801E0E24: nop

L_801E0E28:
    // 0x801E0E28: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x801E0E2C: lw          $t6, -0x4514($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4514);
    // 0x801E0E30: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x801E0E34: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x801E0E38: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x801E0E3C: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x801E0E40: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x801E0E44: sw          $t7, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r15;
    // 0x801E0E48: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x801E0E4C: lbu         $t9, 0x57($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X57);
    // 0x801E0E50: lbu         $t3, 0x5B($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X5B);
    // 0x801E0E54: lbu         $t7, 0x5F($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X5F);
    // 0x801E0E58: andi        $t1, $t9, 0xFF
    ctx->r9 = ctx->r25 & 0XFF;
    // 0x801E0E5C: sll         $t4, $t1, 24
    ctx->r12 = S32(ctx->r9 << 24);
    // 0x801E0E60: andi        $t5, $t3, 0xFF
    ctx->r13 = ctx->r11 & 0XFF;
    // 0x801E0E64: lbu         $t1, 0x63($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X63);
    // 0x801E0E68: sll         $t2, $t5, 16
    ctx->r10 = S32(ctx->r13 << 16);
    // 0x801E0E6C: or          $t6, $t4, $t2
    ctx->r14 = ctx->r12 | ctx->r10;
    // 0x801E0E70: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x801E0E74: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x801E0E78: sll         $t0, $t8, 8
    ctx->r8 = S32(ctx->r24 << 8);
    // 0x801E0E7C: or          $t9, $t6, $t0
    ctx->r25 = ctx->r14 | ctx->r8;
    // 0x801E0E80: andi        $t3, $t1, 0xFF
    ctx->r11 = ctx->r9 & 0XFF;
    // 0x801E0E84: or          $t5, $t9, $t3
    ctx->r13 = ctx->r25 | ctx->r11;
    // 0x801E0E88: sw          $t5, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r13;
    // 0x801E0E8C: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x801E0E90: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x801E0E94: addiu       $t8, $t8, -0x2A28
    ctx->r24 = ADD32(ctx->r24, -0X2A28);
    // 0x801E0E98: sll         $t7, $t2, 2
    ctx->r15 = S32(ctx->r10 << 2);
    // 0x801E0E9C: addu        $t7, $t7, $t2
    ctx->r15 = ADD32(ctx->r15, ctx->r10);
    // 0x801E0EA0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801E0EA4: subu        $t7, $t7, $t2
    ctx->r15 = SUB32(ctx->r15, ctx->r10);
    // 0x801E0EA8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801E0EAC: addu        $t7, $t7, $t2
    ctx->r15 = ADD32(ctx->r15, ctx->r10);
    // 0x801E0EB0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801E0EB4: addu        $t6, $t7, $t8
    ctx->r14 = ADD32(ctx->r15, ctx->r24);
    // 0x801E0EB8: lw          $t0, 0x24($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X24);
    // 0x801E0EBC: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x801E0EC0: beq         $t1, $zero, L_801E0F08
    if (ctx->r9 == 0) {
        // 0x801E0EC4: nop
    
            goto L_801E0F08;
    }
    // 0x801E0EC4: nop

    // 0x801E0EC8: lwc1        $f10, 0x68($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X68);
    // 0x801E0ECC: lwc1        $f16, 0x4C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x801E0ED0: lw          $a2, 0x60($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X60);
    // 0x801E0ED4: lw          $a3, 0x64($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X64);
    // 0x801E0ED8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801E0EDC: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x801E0EE0: addiu       $a0, $a0, -0x4818
    ctx->r4 = ADD32(ctx->r4, -0X4818);
    // 0x801E0EE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801E0EE8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x801E0EEC: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    // 0x801E0EF0: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x801E0EF4: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x801E0EF8: jal         0x800C6144
    // 0x801E0EFC: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    func_800C6144(rdram, ctx);
        goto after_1;
    // 0x801E0EFC: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    after_1:
    // 0x801E0F00: b           L_801E0F6C
    // 0x801E0F04: nop

        goto L_801E0F6C;
    // 0x801E0F04: nop

L_801E0F08:
    // 0x801E0F08: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x801E0F0C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x801E0F10: addiu       $t5, $t5, -0x2A28
    ctx->r13 = ADD32(ctx->r13, -0X2A28);
    // 0x801E0F14: sll         $t3, $t9, 2
    ctx->r11 = S32(ctx->r25 << 2);
    // 0x801E0F18: addu        $t3, $t3, $t9
    ctx->r11 = ADD32(ctx->r11, ctx->r25);
    // 0x801E0F1C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x801E0F20: subu        $t3, $t3, $t9
    ctx->r11 = SUB32(ctx->r11, ctx->r25);
    // 0x801E0F24: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x801E0F28: addu        $t3, $t3, $t9
    ctx->r11 = ADD32(ctx->r11, ctx->r25);
    // 0x801E0F2C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x801E0F30: addu        $t4, $t3, $t5
    ctx->r12 = ADD32(ctx->r11, ctx->r13);
    // 0x801E0F34: lwc1        $f4, 0x68($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X68);
    // 0x801E0F38: lwc1        $f6, 0x50($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X50);
    // 0x801E0F3C: lw          $a2, 0x60($t4)
    ctx->r6 = MEM_W(ctx->r12, 0X60);
    // 0x801E0F40: lw          $a3, 0x64($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X64);
    // 0x801E0F44: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801E0F48: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x801E0F4C: addiu       $a0, $a0, -0x4758
    ctx->r4 = ADD32(ctx->r4, -0X4758);
    // 0x801E0F50: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801E0F54: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x801E0F58: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x801E0F5C: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x801E0F60: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x801E0F64: jal         0x800C6144
    // 0x801E0F68: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    func_800C6144(rdram, ctx);
        goto after_2;
    // 0x801E0F68: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    after_2:
L_801E0F6C:
    // 0x801E0F6C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x801E0F70: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x801E0F74: jr          $ra
    // 0x801E0F78: nop

    return;
    // 0x801E0F78: nop

;}
RECOMP_FUNC void func_801E0F7C_0BA450(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E0F7C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801E0F80: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x801E0F84: lw          $t6, -0x4514($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4514);
    // 0x801E0F88: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x801E0F8C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801E0F90: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x801E0F94: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x801E0F98: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x801E0F9C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x801E0FA0: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x801E0FA4: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x801E0FA8: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x801E0FAC: sw          $t7, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r15;
    // 0x801E0FB0: lui         $t8, 0xDE00
    ctx->r24 = S32(0XDE00 << 16);
    // 0x801E0FB4: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x801E0FB8: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x801E0FBC: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x801E0FC0: addiu       $t0, $t0, -0x59F0
    ctx->r8 = ADD32(ctx->r8, -0X59F0);
    // 0x801E0FC4: lui         $t2, 0x8011
    ctx->r10 = S32(0X8011 << 16);
    // 0x801E0FC8: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x801E0FCC: lw          $t2, -0x4514($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4514);
    // 0x801E0FD0: lui         $t4, 0xE700
    ctx->r12 = S32(0XE700 << 16);
    // 0x801E0FD4: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x801E0FD8: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x801E0FDC: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x801E0FE0: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x801E0FE4: sw          $t3, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r11;
    // 0x801E0FE8: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x801E0FEC: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x801E0FF0: lui         $t9, 0xFB00
    ctx->r25 = S32(0XFB00 << 16);
    // 0x801E0FF4: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x801E0FF8: lw          $t7, -0x4514($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4514);
    // 0x801E0FFC: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x801E1000: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x801E1004: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x801E1008: sw          $t8, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r24;
    // 0x801E100C: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x801E1010: lbu         $t1, 0x57($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X57);
    // 0x801E1014: lbu         $t4, 0x5B($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X5B);
    // 0x801E1018: lbu         $t8, 0x5F($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X5F);
    // 0x801E101C: andi        $t2, $t1, 0xFF
    ctx->r10 = ctx->r9 & 0XFF;
    // 0x801E1020: sll         $t3, $t2, 24
    ctx->r11 = S32(ctx->r10 << 24);
    // 0x801E1024: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x801E1028: lbu         $t2, 0x63($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X63);
    // 0x801E102C: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x801E1030: or          $t7, $t3, $t6
    ctx->r15 = ctx->r11 | ctx->r14;
    // 0x801E1034: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x801E1038: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x801E103C: sll         $t0, $t9, 8
    ctx->r8 = S32(ctx->r25 << 8);
    // 0x801E1040: or          $t1, $t7, $t0
    ctx->r9 = ctx->r15 | ctx->r8;
    // 0x801E1044: andi        $t4, $t2, 0xFF
    ctx->r12 = ctx->r10 & 0XFF;
    // 0x801E1048: or          $t5, $t1, $t4
    ctx->r13 = ctx->r9 | ctx->r12;
    // 0x801E104C: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x801E1050: sw          $t5, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r13;
    // 0x801E1054: lw          $t6, -0x4514($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4514);
    // 0x801E1058: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x801E105C: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x801E1060: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x801E1064: addiu       $t8, $t6, 0x8
    ctx->r24 = ADD32(ctx->r14, 0X8);
    // 0x801E1068: sw          $t8, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r24;
    // 0x801E106C: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x801E1070: lbu         $t0, 0x47($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X47);
    // 0x801E1074: lbu         $t4, 0x4B($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X4B);
    // 0x801E1078: lbu         $t8, 0x4F($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X4F);
    // 0x801E107C: andi        $t2, $t0, 0xFF
    ctx->r10 = ctx->r8 & 0XFF;
    // 0x801E1080: sll         $t1, $t2, 24
    ctx->r9 = S32(ctx->r10 << 24);
    // 0x801E1084: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x801E1088: lbu         $t2, 0x53($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X53);
    // 0x801E108C: sll         $t3, $t5, 16
    ctx->r11 = S32(ctx->r13 << 16);
    // 0x801E1090: or          $t6, $t1, $t3
    ctx->r14 = ctx->r9 | ctx->r11;
    // 0x801E1094: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x801E1098: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x801E109C: sll         $t7, $t9, 8
    ctx->r15 = S32(ctx->r25 << 8);
    // 0x801E10A0: or          $t0, $t6, $t7
    ctx->r8 = ctx->r14 | ctx->r15;
    // 0x801E10A4: andi        $t4, $t2, 0xFF
    ctx->r12 = ctx->r10 & 0XFF;
    // 0x801E10A8: or          $t5, $t0, $t4
    ctx->r13 = ctx->r8 | ctx->r12;
    // 0x801E10AC: sw          $t5, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r13;
    // 0x801E10B0: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x801E10B4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801E10B8: addiu       $t9, $t9, -0x2A28
    ctx->r25 = ADD32(ctx->r25, -0X2A28);
    // 0x801E10BC: sll         $t8, $t3, 2
    ctx->r24 = S32(ctx->r11 << 2);
    // 0x801E10C0: addu        $t8, $t8, $t3
    ctx->r24 = ADD32(ctx->r24, ctx->r11);
    // 0x801E10C4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x801E10C8: subu        $t8, $t8, $t3
    ctx->r24 = SUB32(ctx->r24, ctx->r11);
    // 0x801E10CC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x801E10D0: addu        $t8, $t8, $t3
    ctx->r24 = ADD32(ctx->r24, ctx->r11);
    // 0x801E10D4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x801E10D8: addu        $t6, $t8, $t9
    ctx->r14 = ADD32(ctx->r24, ctx->r25);
    // 0x801E10DC: lw          $t7, 0x24($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X24);
    // 0x801E10E0: andi        $t2, $t7, 0x1
    ctx->r10 = ctx->r15 & 0X1;
    // 0x801E10E4: beq         $t2, $zero, L_801E1124
    if (ctx->r10 == 0) {
        // 0x801E10E8: nop
    
            goto L_801E1124;
    }
    // 0x801E10E8: nop

    // 0x801E10EC: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x801E10F0: lwc1        $f4, 0x68($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X68);
    // 0x801E10F4: lw          $a2, 0x60($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X60);
    // 0x801E10F8: lw          $a3, 0x64($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X64);
    // 0x801E10FC: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x801E1100: addiu       $a0, $a0, -0x48D8
    ctx->r4 = ADD32(ctx->r4, -0X48D8);
    // 0x801E1104: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801E1108: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x801E110C: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x801E1110: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x801E1114: jal         0x800C60A0
    // 0x801E1118: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800C60A0(rdram, ctx);
        goto after_0;
    // 0x801E1118: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x801E111C: b           L_801E1180
    // 0x801E1120: nop

        goto L_801E1180;
    // 0x801E1120: nop

L_801E1124:
    // 0x801E1124: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x801E1128: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x801E112C: addiu       $t5, $t5, -0x2A28
    ctx->r13 = ADD32(ctx->r13, -0X2A28);
    // 0x801E1130: sll         $t4, $t0, 2
    ctx->r12 = S32(ctx->r8 << 2);
    // 0x801E1134: addu        $t4, $t4, $t0
    ctx->r12 = ADD32(ctx->r12, ctx->r8);
    // 0x801E1138: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x801E113C: subu        $t4, $t4, $t0
    ctx->r12 = SUB32(ctx->r12, ctx->r8);
    // 0x801E1140: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x801E1144: addu        $t4, $t4, $t0
    ctx->r12 = ADD32(ctx->r12, ctx->r8);
    // 0x801E1148: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x801E114C: addu        $t1, $t4, $t5
    ctx->r9 = ADD32(ctx->r12, ctx->r13);
    // 0x801E1150: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x801E1154: lwc1        $f8, 0x68($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X68);
    // 0x801E1158: lw          $a2, 0x60($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X60);
    // 0x801E115C: lw          $a3, 0x64($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X64);
    // 0x801E1160: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x801E1164: addiu       $a0, $a0, -0x48A8
    ctx->r4 = ADD32(ctx->r4, -0X48A8);
    // 0x801E1168: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801E116C: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x801E1170: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x801E1174: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x801E1178: jal         0x800C60A0
    // 0x801E117C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800C60A0(rdram, ctx);
        goto after_1;
    // 0x801E117C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_1:
L_801E1180:
    // 0x801E1180: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801E1184: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x801E1188: jr          $ra
    // 0x801E118C: nop

    return;
    // 0x801E118C: nop

;}
RECOMP_FUNC void func_801E1190_0BA450(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E1190: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x801E1194: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x801E1198: lw          $t6, -0x4514($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4514);
    // 0x801E119C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x801E11A0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x801E11A4: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    // 0x801E11A8: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x801E11AC: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x801E11B0: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x801E11B4: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x801E11B8: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x801E11BC: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x801E11C0: sw          $t7, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r15;
    // 0x801E11C4: lui         $t8, 0xDE00
    ctx->r24 = S32(0XDE00 << 16);
    // 0x801E11C8: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x801E11CC: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x801E11D0: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x801E11D4: addiu       $t0, $t0, -0x4FE0
    ctx->r8 = ADD32(ctx->r8, -0X4FE0);
    // 0x801E11D8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x801E11DC: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x801E11E0: lw          $t4, -0x2E34($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2E34);
    // 0x801E11E4: lui         $t2, 0x8011
    ctx->r10 = S32(0X8011 << 16);
    // 0x801E11E8: lw          $t2, -0x4514($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4514);
    // 0x801E11EC: addiu       $t6, $zero, 0x1F
    ctx->r14 = ADD32(0, 0X1F);
    // 0x801E11F0: andi        $t5, $t4, 0x1F
    ctx->r13 = ctx->r12 & 0X1F;
    // 0x801E11F4: subu        $t7, $t6, $t5
    ctx->r15 = SUB32(ctx->r14, ctx->r13);
    // 0x801E11F8: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x801E11FC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x801E1200: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
    // 0x801E1204: addiu       $t2, $zero, 0x1F
    ctx->r10 = ADD32(0, 0X1F);
    // 0x801E1208: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x801E120C: sw          $t3, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r11;
    // 0x801E1210: subu        $t3, $t2, $t5
    ctx->r11 = SUB32(ctx->r10, ctx->r13);
    // 0x801E1214: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x801E1218: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x801E121C: lui         $at, 0xF200
    ctx->r1 = S32(0XF200 << 16);
    // 0x801E1220: sll         $t0, $t9, 12
    ctx->r8 = S32(ctx->r25 << 12);
    // 0x801E1224: or          $t1, $t0, $at
    ctx->r9 = ctx->r8 | ctx->r1;
    // 0x801E1228: andi        $t6, $t4, 0xFFF
    ctx->r14 = ctx->r12 & 0XFFF;
    // 0x801E122C: or          $t7, $t1, $t6
    ctx->r15 = ctx->r9 | ctx->r14;
    // 0x801E1230: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x801E1234: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x801E1238: lui         $t9, 0x7
    ctx->r25 = S32(0X7 << 16);
    // 0x801E123C: ori         $t9, $t9, 0xC07C
    ctx->r25 = ctx->r25 | 0XC07C;
    // 0x801E1240: lui         $t2, 0x8011
    ctx->r10 = S32(0X8011 << 16);
    // 0x801E1244: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x801E1248: lw          $t2, -0x4514($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4514);
    // 0x801E124C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x801E1250: lui         $t3, 0xD9FF
    ctx->r11 = S32(0XD9FF << 16);
    // 0x801E1254: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    // 0x801E1258: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x801E125C: addiu       $t5, $t2, 0x8
    ctx->r13 = ADD32(ctx->r10, 0X8);
    // 0x801E1260: sw          $t5, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r13;
    // 0x801E1264: ori         $t3, $t3, 0xFBFF
    ctx->r11 = ctx->r11 | 0XFBFF;
    // 0x801E1268: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x801E126C: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x801E1270: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801E1274: addiu       $t9, $t9, -0x2A28
    ctx->r25 = ADD32(ctx->r25, -0X2A28);
    // 0x801E1278: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x801E127C: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x801E1280: lwc1        $f16, 0x54($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X54);
    // 0x801E1284: lwc1        $f10, 0x50($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X50);
    // 0x801E1288: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801E128C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x801E1290: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801E1294: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x801E1298: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801E129C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x801E12A0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801E12A4: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x801E12A8: lwc1        $f4, 0x64($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X64);
    // 0x801E12AC: lw          $a3, 0x60($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X60);
    // 0x801E12B0: lwc1        $f8, 0x4C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x801E12B4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x801E12B8: lwc1        $f6, 0x68($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X68);
    // 0x801E12BC: addiu       $t8, $t7, 0xA4
    ctx->r24 = ADD32(ctx->r15, 0XA4);
    // 0x801E12C0: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x801E12C4: addiu       $a0, $a0, -0x45A8
    ctx->r4 = ADD32(ctx->r4, -0X45A8);
    // 0x801E12C8: addu        $a2, $t8, $t9
    ctx->r6 = ADD32(ctx->r24, ctx->r25);
    // 0x801E12CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801E12D0: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x801E12D4: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x801E12D8: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x801E12DC: jal         0x800C6868
    // 0x801E12E0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_800C6868(rdram, ctx);
        goto after_0;
    // 0x801E12E0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x801E12E4: lui         $t2, 0x8011
    ctx->r10 = S32(0X8011 << 16);
    // 0x801E12E8: lw          $t2, -0x4514($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4514);
    // 0x801E12EC: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x801E12F0: lui         $t3, 0xD900
    ctx->r11 = S32(0XD900 << 16);
    // 0x801E12F4: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    // 0x801E12F8: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x801E12FC: addiu       $t5, $t2, 0x8
    ctx->r13 = ADD32(ctx->r10, 0X8);
    // 0x801E1300: sw          $t5, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r13;
    // 0x801E1304: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x801E1308: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x801E130C: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x801E1310: lui         $t7, 0xDE00
    ctx->r15 = S32(0XDE00 << 16);
    // 0x801E1314: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x801E1318: lw          $t6, -0x4514($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4514);
    // 0x801E131C: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x801E1320: addiu       $t0, $t0, -0x51D0
    ctx->r8 = ADD32(ctx->r8, -0X51D0);
    // 0x801E1324: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x801E1328: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x801E132C: addiu       $t8, $t6, 0x8
    ctx->r24 = ADD32(ctx->r14, 0X8);
    // 0x801E1330: sw          $t8, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r24;
    // 0x801E1334: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
    // 0x801E1338: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x801E133C: sw          $t0, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r8;
    // 0x801E1340: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x801E1344: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x801E1348: jr          $ra
    // 0x801E134C: nop

    return;
    // 0x801E134C: nop

;}
RECOMP_FUNC void func_801E1350_0BA450(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E1350: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x801E1354: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x801E1358: sw          $zero, 0x74($sp)
    MEM_W(0X74, ctx->r29) = 0;
L_801E135C:
    // 0x801E135C: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x801E1360: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x801E1364: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801E1368: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x801E136C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801E1370: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x801E1374: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801E1378: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x801E137C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801E1380: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x801E1384: lhu         $t8, -0x2A28($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X2A28);
    // 0x801E1388: andi        $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 & 0X8000;
    // 0x801E138C: beq         $t9, $zero, L_801E2340
    if (ctx->r25 == 0) {
        // 0x801E1390: nop
    
            goto L_801E2340;
    }
    // 0x801E1390: nop

    // 0x801E1394: lui         $t0, 0x8011
    ctx->r8 = S32(0X8011 << 16);
    // 0x801E1398: lw          $t0, -0x4514($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X4514);
    // 0x801E139C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x801E13A0: lui         $t2, 0xDE00
    ctx->r10 = S32(0XDE00 << 16);
    // 0x801E13A4: sw          $t0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r8;
    // 0x801E13A8: lw          $t3, 0x70($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X70);
    // 0x801E13AC: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x801E13B0: sw          $t1, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r9;
    // 0x801E13B4: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x801E13B8: lw          $t5, 0x70($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X70);
    // 0x801E13BC: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x801E13C0: addiu       $t4, $t4, -0x51D0
    ctx->r12 = ADD32(ctx->r12, -0X51D0);
    // 0x801E13C4: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
    // 0x801E13C8: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x801E13CC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x801E13D0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801E13D4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x801E13D8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801E13DC: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x801E13E0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801E13E4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x801E13E8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801E13EC: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x801E13F0: lw          $t8, -0x2A24($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2A24);
    // 0x801E13F4: addiu       $t9, $t8, -0x10
    ctx->r25 = ADD32(ctx->r24, -0X10);
    // 0x801E13F8: sltiu       $at, $t9, 0x1C
    ctx->r1 = ctx->r25 < 0X1C ? 1 : 0;
    // 0x801E13FC: beq         $at, $zero, L_801E2338
    if (ctx->r1 == 0) {
        // 0x801E1400: nop
    
            goto L_801E2338;
    }
    // 0x801E1400: nop

    // 0x801E1404: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x801E1408: lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // 0x801E140C: addu        $at, $at, $t9
    gpr jr_addend_801E1414 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x801E1410: lw          $t9, -0x1740($at)
    ctx->r25 = ADD32(ctx->r1, -0X1740);
    // 0x801E1414: jr          $t9
    // 0x801E1418: nop

    switch (jr_addend_801E1414 >> 2) {
        case 0: goto L_801E141C; break;
        case 1: goto L_801E1674; break;
        case 2: goto L_801E18DC; break;
        case 3: goto L_801E1958; break;
        case 4: goto L_801E1958; break;
        case 5: goto L_801E18DC; break;
        case 6: goto L_801E19DC; break;
        case 7: goto L_801E1A3C; break;
        case 8: goto L_801E1A9C; break;
        case 9: goto L_801E1AEC; break;
        case 10: goto L_801E1B3C; break;
        case 11: goto L_801E1B9C; break;
        case 12: goto L_801E1BF8; break;
        case 13: goto L_801E2338; break;
        case 14: goto L_801E2338; break;
        case 15: goto L_801E2338; break;
        case 16: goto L_801E1C48; break;
        case 17: goto L_801E1CCC; break;
        case 18: goto L_801E1D50; break;
        case 19: goto L_801E1DD4; break;
        case 20: goto L_801E1E58; break;
        case 21: goto L_801E1EDC; break;
        case 22: goto L_801E1F60; break;
        case 23: goto L_801E1FE4; break;
        case 24: goto L_801E2068; break;
        case 25: goto L_801E20EC; break;
        case 26: goto L_801E21C4; break;
        case 27: goto L_801E2170; break;
        default: switch_error(__func__, 0x801E1414, 0x801EE8C0);
    }
    // 0x801E1418: nop

L_801E141C:
    // 0x801E141C: lw          $t0, 0x74($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X74);
    // 0x801E1420: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x801E1424: addiu       $t3, $t3, -0x2A28
    ctx->r11 = ADD32(ctx->r11, -0X2A28);
    // 0x801E1428: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x801E142C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x801E1430: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x801E1434: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x801E1438: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x801E143C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x801E1440: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x801E1444: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x801E1448: lwc1        $f4, 0x64($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X64);
    // 0x801E144C: lw          $a3, 0x60($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X60);
    // 0x801E1450: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801E1454: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x801E1458: lwc1        $f6, 0x68($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X68);
    // 0x801E145C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801E1460: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801E1464: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801E1468: addiu       $t2, $t1, 0xA4
    ctx->r10 = ADD32(ctx->r9, 0XA4);
    // 0x801E146C: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x801E1470: addiu       $a0, $a0, 0x50C8
    ctx->r4 = ADD32(ctx->r4, 0X50C8);
    // 0x801E1474: addu        $a2, $t2, $t3
    ctx->r6 = ADD32(ctx->r10, ctx->r11);
    // 0x801E1478: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801E147C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x801E1480: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x801E1484: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x801E1488: jal         0x800C6868
    // 0x801E148C: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    func_800C6868(rdram, ctx);
        goto after_0;
    // 0x801E148C: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    after_0:
    // 0x801E1490: lui         $t5, 0x8011
    ctx->r13 = S32(0X8011 << 16);
    // 0x801E1494: lw          $t5, -0x4514($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4514);
    // 0x801E1498: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x801E149C: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x801E14A0: sw          $t5, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r13;
    // 0x801E14A4: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
    // 0x801E14A8: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x801E14AC: sw          $t6, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r14;
    // 0x801E14B0: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x801E14B4: lw          $t9, 0x6C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X6C);
    // 0x801E14B8: lui         $t0, 0x8011
    ctx->r8 = S32(0X8011 << 16);
    // 0x801E14BC: lui         $t1, 0xFB00
    ctx->r9 = S32(0XFB00 << 16);
    // 0x801E14C0: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x801E14C4: lw          $t0, -0x4514($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X4514);
    // 0x801E14C8: lui         $t4, 0x2140
    ctx->r12 = S32(0X2140 << 16);
    // 0x801E14CC: ori         $t4, $t4, 0xFFFF
    ctx->r12 = ctx->r12 | 0XFFFF;
    // 0x801E14D0: sw          $t0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r8;
    // 0x801E14D4: lw          $t3, 0x68($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X68);
    // 0x801E14D8: addiu       $t2, $t0, 0x8
    ctx->r10 = ADD32(ctx->r8, 0X8);
    // 0x801E14DC: sw          $t2, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r10;
    // 0x801E14E0: sw          $t1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r9;
    // 0x801E14E4: lw          $t5, 0x68($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X68);
    // 0x801E14E8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x801E14EC: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
    // 0x801E14F0: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x801E14F4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801E14F8: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x801E14FC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801E1500: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x801E1504: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801E1508: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x801E150C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801E1510: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x801E1514: lw          $t8, -0x2A04($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2A04);
    // 0x801E1518: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x801E151C: beq         $t9, $zero, L_801E1558
    if (ctx->r25 == 0) {
        // 0x801E1520: nop
    
            goto L_801E1558;
    }
    // 0x801E1520: nop

    // 0x801E1524: lui         $t0, 0x8011
    ctx->r8 = S32(0X8011 << 16);
    // 0x801E1528: lw          $t0, -0x4514($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X4514);
    // 0x801E152C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x801E1530: lui         $t1, 0xFA00
    ctx->r9 = S32(0XFA00 << 16);
    // 0x801E1534: sw          $t0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r8;
    // 0x801E1538: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x801E153C: addiu       $t2, $t0, 0x8
    ctx->r10 = ADD32(ctx->r8, 0X8);
    // 0x801E1540: sw          $t2, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r10;
    // 0x801E1544: sw          $t1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r9;
    // 0x801E1548: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
    // 0x801E154C: addiu       $t4, $zero, -0x42
    ctx->r12 = ADD32(0, -0X42);
    // 0x801E1550: b           L_801E158C
    // 0x801E1554: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
        goto L_801E158C;
    // 0x801E1554: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
L_801E1558:
    // 0x801E1558: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x801E155C: lw          $t6, -0x4514($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4514);
    // 0x801E1560: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x801E1564: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x801E1568: sw          $t6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r14;
    // 0x801E156C: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x801E1570: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x801E1574: sw          $t7, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r15;
    // 0x801E1578: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x801E157C: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x801E1580: lui         $t0, 0xF0F0
    ctx->r8 = S32(0XF0F0 << 16);
    // 0x801E1584: ori         $t0, $t0, 0xF0F0
    ctx->r8 = ctx->r8 | 0XF0F0;
    // 0x801E1588: sw          $t0, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r8;
L_801E158C:
    // 0x801E158C: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x801E1590: lw          $t1, -0x4514($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4514);
    // 0x801E1594: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x801E1598: lui         $t4, 0xFC30
    ctx->r12 = S32(0XFC30 << 16);
    // 0x801E159C: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x801E15A0: lw          $t5, 0x5C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X5C);
    // 0x801E15A4: addiu       $t3, $t1, 0x8
    ctx->r11 = ADD32(ctx->r9, 0X8);
    // 0x801E15A8: sw          $t3, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r11;
    // 0x801E15AC: ori         $t4, $t4, 0x9661
    ctx->r12 = ctx->r12 | 0X9661;
    // 0x801E15B0: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x801E15B4: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x801E15B8: lui         $t6, 0x552E
    ctx->r14 = S32(0X552E << 16);
    // 0x801E15BC: ori         $t6, $t6, 0xFF7F
    ctx->r14 = ctx->r14 | 0XFF7F;
    // 0x801E15C0: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x801E15C4: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x801E15C8: lw          $t8, -0x4514($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4514);
    // 0x801E15CC: lui         $t0, 0xE200
    ctx->r8 = S32(0XE200 << 16);
    // 0x801E15D0: ori         $t0, $t0, 0x1C
    ctx->r8 = ctx->r8 | 0X1C;
    // 0x801E15D4: sw          $t8, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r24;
    // 0x801E15D8: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x801E15DC: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x801E15E0: sw          $t9, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r25;
    // 0x801E15E4: sw          $t0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r8;
    // 0x801E15E8: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x801E15EC: lui         $t1, 0x40
    ctx->r9 = S32(0X40 << 16);
    // 0x801E15F0: ori         $t1, $t1, 0x4340
    ctx->r9 = ctx->r9 | 0X4340;
    // 0x801E15F4: sw          $t1, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r9;
    // 0x801E15F8: lw          $t4, 0x74($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X74);
    // 0x801E15FC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801E1600: addiu       $t7, $t7, -0x2A28
    ctx->r15 = ADD32(ctx->r15, -0X2A28);
    // 0x801E1604: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x801E1608: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x801E160C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x801E1610: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x801E1614: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x801E1618: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x801E161C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x801E1620: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x801E1624: lwc1        $f18, 0x64($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X64);
    // 0x801E1628: lw          $a3, 0x60($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X60);
    // 0x801E162C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801E1630: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x801E1634: lwc1        $f4, 0x68($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X68);
    // 0x801E1638: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801E163C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801E1640: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801E1644: addiu       $t6, $t5, 0xA4
    ctx->r14 = ADD32(ctx->r13, 0XA4);
    // 0x801E1648: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x801E164C: addiu       $a0, $a0, 0x6C50
    ctx->r4 = ADD32(ctx->r4, 0X6C50);
    // 0x801E1650: addu        $a2, $t6, $t7
    ctx->r6 = ADD32(ctx->r14, ctx->r15);
    // 0x801E1654: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801E1658: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x801E165C: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x801E1660: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x801E1664: jal         0x800C6868
    // 0x801E1668: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    func_800C6868(rdram, ctx);
        goto after_1;
    // 0x801E1668: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x801E166C: b           L_801E2338
    // 0x801E1670: nop

        goto L_801E2338;
    // 0x801E1670: nop

L_801E1674:
    // 0x801E1674: lw          $t9, 0x74($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X74);
    // 0x801E1678: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x801E167C: addiu       $t1, $t1, -0x2A28
    ctx->r9 = ADD32(ctx->r9, -0X2A28);
    // 0x801E1680: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x801E1684: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x801E1688: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x801E168C: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x801E1690: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x801E1694: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x801E1698: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x801E169C: addu        $t3, $t0, $t1
    ctx->r11 = ADD32(ctx->r8, ctx->r9);
    // 0x801E16A0: lwc1        $f16, 0x64($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X64);
    // 0x801E16A4: lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // 0x801E16A8: lwc1        $f4, -0x16D0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X16D0);
    // 0x801E16AC: lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // 0x801E16B0: lw          $a3, 0x60($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X60);
    // 0x801E16B4: lwc1        $f6, -0x16CC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X16CC);
    // 0x801E16B8: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x801E16BC: lwc1        $f18, 0x68($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X68);
    // 0x801E16C0: lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // 0x801E16C4: lwc1        $f8, -0x16C8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X16C8);
    // 0x801E16C8: addiu       $t2, $t0, 0xA4
    ctx->r10 = ADD32(ctx->r8, 0XA4);
    // 0x801E16CC: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x801E16D0: addiu       $a0, $a0, 0x50C8
    ctx->r4 = ADD32(ctx->r4, 0X50C8);
    // 0x801E16D4: addu        $a2, $t2, $t1
    ctx->r6 = ADD32(ctx->r10, ctx->r9);
    // 0x801E16D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801E16DC: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x801E16E0: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x801E16E4: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x801E16E8: jal         0x800C6868
    // 0x801E16EC: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    func_800C6868(rdram, ctx);
        goto after_2;
    // 0x801E16EC: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x801E16F0: lui         $t4, 0x8011
    ctx->r12 = S32(0X8011 << 16);
    // 0x801E16F4: lw          $t4, -0x4514($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4514);
    // 0x801E16F8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x801E16FC: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x801E1700: sw          $t4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r12;
    // 0x801E1704: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x801E1708: addiu       $t6, $t4, 0x8
    ctx->r14 = ADD32(ctx->r12, 0X8);
    // 0x801E170C: sw          $t6, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r14;
    // 0x801E1710: sw          $t5, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r13;
    // 0x801E1714: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x801E1718: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x801E171C: lui         $t0, 0xFB00
    ctx->r8 = S32(0XFB00 << 16);
    // 0x801E1720: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x801E1724: lw          $t9, -0x4514($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4514);
    // 0x801E1728: lui         $t3, 0x2140
    ctx->r11 = S32(0X2140 << 16);
    // 0x801E172C: ori         $t3, $t3, 0xFFFF
    ctx->r11 = ctx->r11 | 0XFFFF;
    // 0x801E1730: sw          $t9, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r25;
    // 0x801E1734: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x801E1738: addiu       $t2, $t9, 0x8
    ctx->r10 = ADD32(ctx->r25, 0X8);
    // 0x801E173C: sw          $t2, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r10;
    // 0x801E1740: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x801E1744: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x801E1748: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801E174C: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    // 0x801E1750: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x801E1754: sll         $t5, $t6, 2
    ctx->r13 = S32(ctx->r14 << 2);
    // 0x801E1758: addu        $t5, $t5, $t6
    ctx->r13 = ADD32(ctx->r13, ctx->r14);
    // 0x801E175C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x801E1760: subu        $t5, $t5, $t6
    ctx->r13 = SUB32(ctx->r13, ctx->r14);
    // 0x801E1764: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x801E1768: addu        $t5, $t5, $t6
    ctx->r13 = ADD32(ctx->r13, ctx->r14);
    // 0x801E176C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x801E1770: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x801E1774: lw          $t7, -0x2A04($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2A04);
    // 0x801E1778: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x801E177C: beq         $t8, $zero, L_801E17B8
    if (ctx->r24 == 0) {
        // 0x801E1780: nop
    
            goto L_801E17B8;
    }
    // 0x801E1780: nop

    // 0x801E1784: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x801E1788: lw          $t9, -0x4514($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4514);
    // 0x801E178C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x801E1790: lui         $t0, 0xFA00
    ctx->r8 = S32(0XFA00 << 16);
    // 0x801E1794: sw          $t9, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r25;
    // 0x801E1798: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x801E179C: addiu       $t2, $t9, 0x8
    ctx->r10 = ADD32(ctx->r25, 0X8);
    // 0x801E17A0: sw          $t2, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r10;
    // 0x801E17A4: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x801E17A8: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x801E17AC: addiu       $t3, $zero, -0x42
    ctx->r11 = ADD32(0, -0X42);
    // 0x801E17B0: b           L_801E17EC
    // 0x801E17B4: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
        goto L_801E17EC;
    // 0x801E17B4: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
L_801E17B8:
    // 0x801E17B8: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x801E17BC: lw          $t6, -0x4514($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4514);
    // 0x801E17C0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x801E17C4: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x801E17C8: sw          $t6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r14;
    // 0x801E17CC: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x801E17D0: addiu       $t5, $t6, 0x8
    ctx->r13 = ADD32(ctx->r14, 0X8);
    // 0x801E17D4: sw          $t5, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r13;
    // 0x801E17D8: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x801E17DC: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x801E17E0: lui         $t9, 0xF0F0
    ctx->r25 = S32(0XF0F0 << 16);
    // 0x801E17E4: ori         $t9, $t9, 0xF0F0
    ctx->r25 = ctx->r25 | 0XF0F0;
    // 0x801E17E8: sw          $t9, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r25;
L_801E17EC:
    // 0x801E17EC: lui         $t0, 0x8011
    ctx->r8 = S32(0X8011 << 16);
    // 0x801E17F0: lw          $t0, -0x4514($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X4514);
    // 0x801E17F4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x801E17F8: lui         $t3, 0xFC30
    ctx->r11 = S32(0XFC30 << 16);
    // 0x801E17FC: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    // 0x801E1800: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x801E1804: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x801E1808: sw          $t1, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r9;
    // 0x801E180C: ori         $t3, $t3, 0x9661
    ctx->r11 = ctx->r11 | 0X9661;
    // 0x801E1810: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x801E1814: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x801E1818: lui         $t6, 0x552E
    ctx->r14 = S32(0X552E << 16);
    // 0x801E181C: ori         $t6, $t6, 0xFF7F
    ctx->r14 = ctx->r14 | 0XFF7F;
    // 0x801E1820: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x801E1824: sw          $t6, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r14;
    // 0x801E1828: lw          $t7, -0x4514($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4514);
    // 0x801E182C: lui         $t9, 0xE200
    ctx->r25 = S32(0XE200 << 16);
    // 0x801E1830: ori         $t9, $t9, 0x1C
    ctx->r25 = ctx->r25 | 0X1C;
    // 0x801E1834: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
    // 0x801E1838: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x801E183C: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x801E1840: sw          $t8, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r24;
    // 0x801E1844: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x801E1848: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x801E184C: lui         $t0, 0x40
    ctx->r8 = S32(0X40 << 16);
    // 0x801E1850: ori         $t0, $t0, 0x4340
    ctx->r8 = ctx->r8 | 0X4340;
    // 0x801E1854: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x801E1858: lw          $t3, 0x74($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X74);
    // 0x801E185C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x801E1860: addiu       $t5, $t5, -0x2A28
    ctx->r13 = ADD32(ctx->r13, -0X2A28);
    // 0x801E1864: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x801E1868: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x801E186C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x801E1870: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x801E1874: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x801E1878: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x801E187C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x801E1880: addu        $t7, $t4, $t5
    ctx->r15 = ADD32(ctx->r12, ctx->r13);
    // 0x801E1884: lwc1        $f10, 0x64($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X64);
    // 0x801E1888: lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // 0x801E188C: lwc1        $f18, -0x16C4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X16C4);
    // 0x801E1890: lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // 0x801E1894: lw          $a3, 0x60($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X60);
    // 0x801E1898: lwc1        $f4, -0x16C0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X16C0);
    // 0x801E189C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x801E18A0: lwc1        $f16, 0x68($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X68);
    // 0x801E18A4: lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // 0x801E18A8: lwc1        $f6, -0x16BC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X16BC);
    // 0x801E18AC: addiu       $t6, $t4, 0xA4
    ctx->r14 = ADD32(ctx->r12, 0XA4);
    // 0x801E18B0: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x801E18B4: addiu       $a0, $a0, 0x6C50
    ctx->r4 = ADD32(ctx->r4, 0X6C50);
    // 0x801E18B8: addu        $a2, $t6, $t5
    ctx->r6 = ADD32(ctx->r14, ctx->r13);
    // 0x801E18BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801E18C0: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    // 0x801E18C4: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x801E18C8: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x801E18CC: jal         0x800C6868
    // 0x801E18D0: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    func_800C6868(rdram, ctx);
        goto after_3;
    // 0x801E18D0: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    after_3:
    // 0x801E18D4: b           L_801E2338
    // 0x801E18D8: nop

        goto L_801E2338;
    // 0x801E18D8: nop

L_801E18DC:
    // 0x801E18DC: lw          $t8, 0x74($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X74);
    // 0x801E18E0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x801E18E4: addiu       $t0, $t0, -0x2A28
    ctx->r8 = ADD32(ctx->r8, -0X2A28);
    // 0x801E18E8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x801E18EC: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x801E18F0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x801E18F4: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x801E18F8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x801E18FC: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x801E1900: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x801E1904: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x801E1908: lwc1        $f8, 0x64($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X64);
    // 0x801E190C: lw          $a3, 0x60($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X60);
    // 0x801E1910: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801E1914: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x801E1918: lwc1        $f10, 0x68($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X68);
    // 0x801E191C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801E1920: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801E1924: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801E1928: addiu       $t2, $t9, 0xA4
    ctx->r10 = ADD32(ctx->r25, 0XA4);
    // 0x801E192C: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x801E1930: addiu       $a0, $a0, 0x6EA8
    ctx->r4 = ADD32(ctx->r4, 0X6EA8);
    // 0x801E1934: addu        $a2, $t2, $t0
    ctx->r6 = ADD32(ctx->r10, ctx->r8);
    // 0x801E1938: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801E193C: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x801E1940: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x801E1944: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    // 0x801E1948: jal         0x800C6868
    // 0x801E194C: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    func_800C6868(rdram, ctx);
        goto after_4;
    // 0x801E194C: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    after_4:
    // 0x801E1950: b           L_801E2338
    // 0x801E1954: nop

        goto L_801E2338;
    // 0x801E1954: nop

L_801E1958:
    // 0x801E1958: lw          $t3, 0x74($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X74);
    // 0x801E195C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x801E1960: addiu       $t5, $t5, -0x2A28
    ctx->r13 = ADD32(ctx->r13, -0X2A28);
    // 0x801E1964: sll         $t6, $t3, 2
    ctx->r14 = S32(ctx->r11 << 2);
    // 0x801E1968: addu        $t6, $t6, $t3
    ctx->r14 = ADD32(ctx->r14, ctx->r11);
    // 0x801E196C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801E1970: subu        $t6, $t6, $t3
    ctx->r14 = SUB32(ctx->r14, ctx->r11);
    // 0x801E1974: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801E1978: addu        $t6, $t6, $t3
    ctx->r14 = ADD32(ctx->r14, ctx->r11);
    // 0x801E197C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801E1980: addu        $t7, $t6, $t5
    ctx->r15 = ADD32(ctx->r14, ctx->r13);
    // 0x801E1984: lwc1        $f6, 0x64($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X64);
    // 0x801E1988: lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // 0x801E198C: lwc1        $f10, -0x16B8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X16B8);
    // 0x801E1990: lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // 0x801E1994: lw          $a3, 0x60($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X60);
    // 0x801E1998: lwc1        $f16, -0x16B4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X16B4);
    // 0x801E199C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x801E19A0: lwc1        $f8, 0x68($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X68);
    // 0x801E19A4: lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // 0x801E19A8: lwc1        $f18, -0x16B0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X16B0);
    // 0x801E19AC: addiu       $t4, $t6, 0xA4
    ctx->r12 = ADD32(ctx->r14, 0XA4);
    // 0x801E19B0: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x801E19B4: addiu       $a0, $a0, 0x6EA8
    ctx->r4 = ADD32(ctx->r4, 0X6EA8);
    // 0x801E19B8: addu        $a2, $t4, $t5
    ctx->r6 = ADD32(ctx->r12, ctx->r13);
    // 0x801E19BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801E19C0: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x801E19C4: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    // 0x801E19C8: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x801E19CC: jal         0x800C6868
    // 0x801E19D0: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    func_800C6868(rdram, ctx);
        goto after_5;
    // 0x801E19D0: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    after_5:
    // 0x801E19D4: b           L_801E2338
    // 0x801E19D8: nop

        goto L_801E2338;
    // 0x801E19D8: nop

L_801E19DC:
    // 0x801E19DC: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x801E19E0: lui         $a2, 0x3E38
    ctx->r6 = S32(0X3E38 << 16);
    // 0x801E19E4: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x801E19E8: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x801E19EC: addiu       $t9, $zero, 0xC8
    ctx->r25 = ADD32(0, 0XC8);
    // 0x801E19F0: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x801E19F4: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x801E19F8: addiu       $t3, $zero, 0xC8
    ctx->r11 = ADD32(0, 0XC8);
    // 0x801E19FC: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x801E1A00: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x801E1A04: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x801E1A08: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x801E1A0C: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x801E1A10: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x801E1A14: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x801E1A18: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x801E1A1C: ori         $a2, $a2, 0x51EC
    ctx->r6 = ctx->r6 | 0X51EC;
    // 0x801E1A20: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x801E1A24: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x801E1A28: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x801E1A2C: jal         0x801E0B6C
    // 0x801E1A30: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    func_801E0B6C_0BA450(rdram, ctx);
        goto after_6;
    // 0x801E1A30: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    after_6:
    // 0x801E1A34: b           L_801E2338
    // 0x801E1A38: nop

        goto L_801E2338;
    // 0x801E1A38: nop

L_801E1A3C:
    // 0x801E1A3C: lui         $a1, 0x3EC2
    ctx->r5 = S32(0X3EC2 << 16);
    // 0x801E1A40: lui         $a2, 0x3EB8
    ctx->r6 = S32(0X3EB8 << 16);
    // 0x801E1A44: addiu       $t6, $zero, 0xC8
    ctx->r14 = ADD32(0, 0XC8);
    // 0x801E1A48: addiu       $t5, $zero, 0xC8
    ctx->r13 = ADD32(0, 0XC8);
    // 0x801E1A4C: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x801E1A50: addiu       $t8, $zero, 0x8E
    ctx->r24 = ADD32(0, 0X8E);
    // 0x801E1A54: addiu       $t2, $zero, 0x8E
    ctx->r10 = ADD32(0, 0X8E);
    // 0x801E1A58: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x801E1A5C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801E1A60: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x801E1A64: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x801E1A68: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x801E1A6C: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x801E1A70: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x801E1A74: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x801E1A78: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801E1A7C: ori         $a2, $a2, 0x51EC
    ctx->r6 = ctx->r6 | 0X51EC;
    // 0x801E1A80: ori         $a1, $a1, 0x8F5C
    ctx->r5 = ctx->r5 | 0X8F5C;
    // 0x801E1A84: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x801E1A88: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x801E1A8C: jal         0x801E0B6C
    // 0x801E1A90: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_801E0B6C_0BA450(rdram, ctx);
        goto after_7;
    // 0x801E1A90: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_7:
    // 0x801E1A94: b           L_801E2338
    // 0x801E1A98: nop

        goto L_801E2338;
    // 0x801E1A98: nop

L_801E1A9C:
    // 0x801E1A9C: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x801E1AA0: lui         $a2, 0x3E38
    ctx->r6 = S32(0X3E38 << 16);
    // 0x801E1AA4: addiu       $t1, $zero, 0xC8
    ctx->r9 = ADD32(0, 0XC8);
    // 0x801E1AA8: addiu       $t3, $zero, 0xC8
    ctx->r11 = ADD32(0, 0XC8);
    // 0x801E1AAC: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x801E1AB0: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x801E1AB4: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x801E1AB8: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x801E1ABC: ori         $a2, $a2, 0x51EC
    ctx->r6 = ctx->r6 | 0X51EC;
    // 0x801E1AC0: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x801E1AC4: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x801E1AC8: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x801E1ACC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801E1AD0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x801E1AD4: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x801E1AD8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x801E1ADC: jal         0x801E0B6C
    // 0x801E1AE0: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    func_801E0B6C_0BA450(rdram, ctx);
        goto after_8;
    // 0x801E1AE0: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    after_8:
    // 0x801E1AE4: b           L_801E2338
    // 0x801E1AE8: nop

        goto L_801E2338;
    // 0x801E1AE8: nop

L_801E1AEC:
    // 0x801E1AEC: lui         $a1, 0x3EC2
    ctx->r5 = S32(0X3EC2 << 16);
    // 0x801E1AF0: lui         $a2, 0x3EB3
    ctx->r6 = S32(0X3EB3 << 16);
    // 0x801E1AF4: addiu       $t6, $zero, 0xC8
    ctx->r14 = ADD32(0, 0XC8);
    // 0x801E1AF8: addiu       $t5, $zero, 0xC8
    ctx->r13 = ADD32(0, 0XC8);
    // 0x801E1AFC: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x801E1B00: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x801E1B04: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x801E1B08: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x801E1B0C: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x801E1B10: ori         $a1, $a1, 0x8F5C
    ctx->r5 = ctx->r5 | 0X8F5C;
    // 0x801E1B14: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x801E1B18: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x801E1B1C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801E1B20: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x801E1B24: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x801E1B28: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x801E1B2C: jal         0x801E0B6C
    // 0x801E1B30: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    func_801E0B6C_0BA450(rdram, ctx);
        goto after_9;
    // 0x801E1B30: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    after_9:
    // 0x801E1B34: b           L_801E2338
    // 0x801E1B38: nop

        goto L_801E2338;
    // 0x801E1B38: nop

L_801E1B3C:
    // 0x801E1B3C: lui         $a1, 0x3CA3
    ctx->r5 = S32(0X3CA3 << 16);
    // 0x801E1B40: lui         $a2, 0x3C93
    ctx->r6 = S32(0X3C93 << 16);
    // 0x801E1B44: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x801E1B48: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x801E1B4C: addiu       $t9, $zero, 0xC8
    ctx->r25 = ADD32(0, 0XC8);
    // 0x801E1B50: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x801E1B54: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x801E1B58: addiu       $t3, $zero, 0xC8
    ctx->r11 = ADD32(0, 0XC8);
    // 0x801E1B5C: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x801E1B60: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x801E1B64: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x801E1B68: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x801E1B6C: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x801E1B70: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x801E1B74: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x801E1B78: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x801E1B7C: ori         $a2, $a2, 0x74BC
    ctx->r6 = ctx->r6 | 0X74BC;
    // 0x801E1B80: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    // 0x801E1B84: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x801E1B88: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x801E1B8C: jal         0x801E0B6C
    // 0x801E1B90: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    func_801E0B6C_0BA450(rdram, ctx);
        goto after_10;
    // 0x801E1B90: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    after_10:
    // 0x801E1B94: b           L_801E2338
    // 0x801E1B98: nop

        goto L_801E2338;
    // 0x801E1B98: nop

L_801E1B9C:
    // 0x801E1B9C: lui         $a1, 0x3D1B
    ctx->r5 = S32(0X3D1B << 16);
    // 0x801E1BA0: lui         $a2, 0x3D13
    ctx->r6 = S32(0X3D13 << 16);
    // 0x801E1BA4: addiu       $t6, $zero, 0xC8
    ctx->r14 = ADD32(0, 0XC8);
    // 0x801E1BA8: addiu       $t5, $zero, 0xC8
    ctx->r13 = ADD32(0, 0XC8);
    // 0x801E1BAC: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x801E1BB0: addiu       $t8, $zero, 0x8E
    ctx->r24 = ADD32(0, 0X8E);
    // 0x801E1BB4: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x801E1BB8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801E1BBC: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x801E1BC0: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x801E1BC4: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x801E1BC8: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x801E1BCC: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x801E1BD0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801E1BD4: ori         $a2, $a2, 0x74BC
    ctx->r6 = ctx->r6 | 0X74BC;
    // 0x801E1BD8: ori         $a1, $a1, 0xA5E3
    ctx->r5 = ctx->r5 | 0XA5E3;
    // 0x801E1BDC: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x801E1BE0: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x801E1BE4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x801E1BE8: jal         0x801E0B6C
    // 0x801E1BEC: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    func_801E0B6C_0BA450(rdram, ctx);
        goto after_11;
    // 0x801E1BEC: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_11:
    // 0x801E1BF0: b           L_801E2338
    // 0x801E1BF4: nop

        goto L_801E2338;
    // 0x801E1BF4: nop

L_801E1BF8:
    // 0x801E1BF8: lui         $a1, 0x3CA3
    ctx->r5 = S32(0X3CA3 << 16);
    // 0x801E1BFC: lui         $a2, 0x3C93
    ctx->r6 = S32(0X3C93 << 16);
    // 0x801E1C00: addiu       $t0, $zero, 0xC8
    ctx->r8 = ADD32(0, 0XC8);
    // 0x801E1C04: addiu       $t1, $zero, 0xC8
    ctx->r9 = ADD32(0, 0XC8);
    // 0x801E1C08: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x801E1C0C: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x801E1C10: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x801E1C14: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x801E1C18: ori         $a2, $a2, 0x74BC
    ctx->r6 = ctx->r6 | 0X74BC;
    // 0x801E1C1C: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    // 0x801E1C20: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x801E1C24: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x801E1C28: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801E1C2C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x801E1C30: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x801E1C34: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x801E1C38: jal         0x801E0B6C
    // 0x801E1C3C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    func_801E0B6C_0BA450(rdram, ctx);
        goto after_12;
    // 0x801E1C3C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    after_12:
    // 0x801E1C40: b           L_801E2338
    // 0x801E1C44: nop

        goto L_801E2338;
    // 0x801E1C44: nop

L_801E1C48:
    // 0x801E1C48: lw          $t4, 0x74($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X74);
    // 0x801E1C4C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801E1C50: addiu       $t7, $t7, -0x2A28
    ctx->r15 = ADD32(ctx->r15, -0X2A28);
    // 0x801E1C54: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x801E1C58: addu        $t6, $t6, $t4
    ctx->r14 = ADD32(ctx->r14, ctx->r12);
    // 0x801E1C5C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801E1C60: subu        $t6, $t6, $t4
    ctx->r14 = SUB32(ctx->r14, ctx->r12);
    // 0x801E1C64: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801E1C68: addu        $t6, $t6, $t4
    ctx->r14 = ADD32(ctx->r14, ctx->r12);
    // 0x801E1C6C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801E1C70: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x801E1C74: lwc1        $f4, 0x64($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X64);
    // 0x801E1C78: lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // 0x801E1C7C: lwc1        $f8, -0x16AC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X16AC);
    // 0x801E1C80: lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // 0x801E1C84: lw          $a3, 0x60($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X60);
    // 0x801E1C88: lwc1        $f10, -0x16A8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X16A8);
    // 0x801E1C8C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x801E1C90: lwc1        $f6, 0x68($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X68);
    // 0x801E1C94: lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // 0x801E1C98: lwc1        $f16, -0x16A4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X16A4);
    // 0x801E1C9C: addiu       $t5, $t6, 0xA4
    ctx->r13 = ADD32(ctx->r14, 0XA4);
    // 0x801E1CA0: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x801E1CA4: addiu       $a0, $a0, 0x46C8
    ctx->r4 = ADD32(ctx->r4, 0X46C8);
    // 0x801E1CA8: addu        $a2, $t5, $t7
    ctx->r6 = ADD32(ctx->r13, ctx->r15);
    // 0x801E1CAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801E1CB0: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x801E1CB4: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x801E1CB8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x801E1CBC: jal         0x800C6868
    // 0x801E1CC0: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    func_800C6868(rdram, ctx);
        goto after_13;
    // 0x801E1CC0: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    after_13:
    // 0x801E1CC4: b           L_801E2338
    // 0x801E1CC8: nop

        goto L_801E2338;
    // 0x801E1CC8: nop

L_801E1CCC:
    // 0x801E1CCC: lw          $t2, 0x74($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X74);
    // 0x801E1CD0: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x801E1CD4: addiu       $t1, $t1, -0x2A28
    ctx->r9 = ADD32(ctx->r9, -0X2A28);
    // 0x801E1CD8: sll         $t9, $t2, 2
    ctx->r25 = S32(ctx->r10 << 2);
    // 0x801E1CDC: addu        $t9, $t9, $t2
    ctx->r25 = ADD32(ctx->r25, ctx->r10);
    // 0x801E1CE0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x801E1CE4: subu        $t9, $t9, $t2
    ctx->r25 = SUB32(ctx->r25, ctx->r10);
    // 0x801E1CE8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x801E1CEC: addu        $t9, $t9, $t2
    ctx->r25 = ADD32(ctx->r25, ctx->r10);
    // 0x801E1CF0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x801E1CF4: addu        $t3, $t9, $t1
    ctx->r11 = ADD32(ctx->r25, ctx->r9);
    // 0x801E1CF8: lwc1        $f18, 0x64($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X64);
    // 0x801E1CFC: lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // 0x801E1D00: lwc1        $f6, -0x16A0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X16A0);
    // 0x801E1D04: lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // 0x801E1D08: lw          $a3, 0x60($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X60);
    // 0x801E1D0C: lwc1        $f8, -0x169C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X169C);
    // 0x801E1D10: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x801E1D14: lwc1        $f4, 0x68($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X68);
    // 0x801E1D18: lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // 0x801E1D1C: lwc1        $f10, -0x1698($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X1698);
    // 0x801E1D20: addiu       $t0, $t9, 0xA4
    ctx->r8 = ADD32(ctx->r25, 0XA4);
    // 0x801E1D24: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x801E1D28: addiu       $a0, $a0, 0x4F48
    ctx->r4 = ADD32(ctx->r4, 0X4F48);
    // 0x801E1D2C: addu        $a2, $t0, $t1
    ctx->r6 = ADD32(ctx->r8, ctx->r9);
    // 0x801E1D30: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801E1D34: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x801E1D38: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x801E1D3C: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x801E1D40: jal         0x800C6868
    // 0x801E1D44: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    func_800C6868(rdram, ctx);
        goto after_14;
    // 0x801E1D44: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    after_14:
    // 0x801E1D48: b           L_801E2338
    // 0x801E1D4C: nop

        goto L_801E2338;
    // 0x801E1D4C: nop

L_801E1D50:
    // 0x801E1D50: lw          $t4, 0x74($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X74);
    // 0x801E1D54: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801E1D58: addiu       $t7, $t7, -0x2A28
    ctx->r15 = ADD32(ctx->r15, -0X2A28);
    // 0x801E1D5C: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x801E1D60: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x801E1D64: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x801E1D68: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x801E1D6C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x801E1D70: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x801E1D74: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x801E1D78: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x801E1D7C: lwc1        $f16, 0x64($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X64);
    // 0x801E1D80: lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // 0x801E1D84: lwc1        $f4, -0x1694($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1694);
    // 0x801E1D88: lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // 0x801E1D8C: lw          $a3, 0x60($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X60);
    // 0x801E1D90: lwc1        $f6, -0x1690($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1690);
    // 0x801E1D94: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x801E1D98: lwc1        $f18, 0x68($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X68);
    // 0x801E1D9C: lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // 0x801E1DA0: lwc1        $f8, -0x168C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X168C);
    // 0x801E1DA4: addiu       $t6, $t5, 0xA4
    ctx->r14 = ADD32(ctx->r13, 0XA4);
    // 0x801E1DA8: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x801E1DAC: addiu       $a0, $a0, 0x50E8
    ctx->r4 = ADD32(ctx->r4, 0X50E8);
    // 0x801E1DB0: addu        $a2, $t6, $t7
    ctx->r6 = ADD32(ctx->r14, ctx->r15);
    // 0x801E1DB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801E1DB8: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x801E1DBC: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x801E1DC0: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x801E1DC4: jal         0x800C6868
    // 0x801E1DC8: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    func_800C6868(rdram, ctx);
        goto after_15;
    // 0x801E1DC8: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    after_15:
    // 0x801E1DCC: b           L_801E2338
    // 0x801E1DD0: nop

        goto L_801E2338;
    // 0x801E1DD0: nop

L_801E1DD4:
    // 0x801E1DD4: lw          $t2, 0x74($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X74);
    // 0x801E1DD8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x801E1DDC: addiu       $t1, $t1, -0x2A28
    ctx->r9 = ADD32(ctx->r9, -0X2A28);
    // 0x801E1DE0: sll         $t0, $t2, 2
    ctx->r8 = S32(ctx->r10 << 2);
    // 0x801E1DE4: addu        $t0, $t0, $t2
    ctx->r8 = ADD32(ctx->r8, ctx->r10);
    // 0x801E1DE8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x801E1DEC: subu        $t0, $t0, $t2
    ctx->r8 = SUB32(ctx->r8, ctx->r10);
    // 0x801E1DF0: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x801E1DF4: addu        $t0, $t0, $t2
    ctx->r8 = ADD32(ctx->r8, ctx->r10);
    // 0x801E1DF8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x801E1DFC: addu        $t3, $t0, $t1
    ctx->r11 = ADD32(ctx->r8, ctx->r9);
    // 0x801E1E00: lwc1        $f10, 0x64($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X64);
    // 0x801E1E04: lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // 0x801E1E08: lwc1        $f18, -0x1688($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X1688);
    // 0x801E1E0C: lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // 0x801E1E10: lw          $a3, 0x60($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X60);
    // 0x801E1E14: lwc1        $f4, -0x1684($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1684);
    // 0x801E1E18: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x801E1E1C: lwc1        $f16, 0x68($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X68);
    // 0x801E1E20: lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // 0x801E1E24: lwc1        $f6, -0x1680($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1680);
    // 0x801E1E28: addiu       $t9, $t0, 0xA4
    ctx->r25 = ADD32(ctx->r8, 0XA4);
    // 0x801E1E2C: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x801E1E30: addiu       $a0, $a0, 0x5218
    ctx->r4 = ADD32(ctx->r4, 0X5218);
    // 0x801E1E34: addu        $a2, $t9, $t1
    ctx->r6 = ADD32(ctx->r25, ctx->r9);
    // 0x801E1E38: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801E1E3C: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    // 0x801E1E40: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x801E1E44: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x801E1E48: jal         0x800C6868
    // 0x801E1E4C: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    func_800C6868(rdram, ctx);
        goto after_16;
    // 0x801E1E4C: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    after_16:
    // 0x801E1E50: b           L_801E2338
    // 0x801E1E54: nop

        goto L_801E2338;
    // 0x801E1E54: nop

L_801E1E58:
    // 0x801E1E58: lw          $t4, 0x74($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X74);
    // 0x801E1E5C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801E1E60: addiu       $t7, $t7, -0x2A28
    ctx->r15 = ADD32(ctx->r15, -0X2A28);
    // 0x801E1E64: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x801E1E68: addu        $t6, $t6, $t4
    ctx->r14 = ADD32(ctx->r14, ctx->r12);
    // 0x801E1E6C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801E1E70: subu        $t6, $t6, $t4
    ctx->r14 = SUB32(ctx->r14, ctx->r12);
    // 0x801E1E74: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801E1E78: addu        $t6, $t6, $t4
    ctx->r14 = ADD32(ctx->r14, ctx->r12);
    // 0x801E1E7C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801E1E80: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x801E1E84: lwc1        $f8, 0x64($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X64);
    // 0x801E1E88: lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // 0x801E1E8C: lwc1        $f16, -0x167C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X167C);
    // 0x801E1E90: lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // 0x801E1E94: lw          $a3, 0x60($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X60);
    // 0x801E1E98: lwc1        $f18, -0x1678($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X1678);
    // 0x801E1E9C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x801E1EA0: lwc1        $f10, 0x68($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X68);
    // 0x801E1EA4: lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // 0x801E1EA8: lwc1        $f4, -0x1674($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1674);
    // 0x801E1EAC: addiu       $t5, $t6, 0xA4
    ctx->r13 = ADD32(ctx->r14, 0XA4);
    // 0x801E1EB0: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x801E1EB4: addiu       $a0, $a0, 0x5348
    ctx->r4 = ADD32(ctx->r4, 0X5348);
    // 0x801E1EB8: addu        $a2, $t5, $t7
    ctx->r6 = ADD32(ctx->r13, ctx->r15);
    // 0x801E1EBC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801E1EC0: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x801E1EC4: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    // 0x801E1EC8: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x801E1ECC: jal         0x800C6868
    // 0x801E1ED0: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    func_800C6868(rdram, ctx);
        goto after_17;
    // 0x801E1ED0: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    after_17:
    // 0x801E1ED4: b           L_801E2338
    // 0x801E1ED8: nop

        goto L_801E2338;
    // 0x801E1ED8: nop

L_801E1EDC:
    // 0x801E1EDC: lw          $t2, 0x74($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X74);
    // 0x801E1EE0: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x801E1EE4: addiu       $t1, $t1, -0x2A28
    ctx->r9 = ADD32(ctx->r9, -0X2A28);
    // 0x801E1EE8: sll         $t9, $t2, 2
    ctx->r25 = S32(ctx->r10 << 2);
    // 0x801E1EEC: addu        $t9, $t9, $t2
    ctx->r25 = ADD32(ctx->r25, ctx->r10);
    // 0x801E1EF0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x801E1EF4: subu        $t9, $t9, $t2
    ctx->r25 = SUB32(ctx->r25, ctx->r10);
    // 0x801E1EF8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x801E1EFC: addu        $t9, $t9, $t2
    ctx->r25 = ADD32(ctx->r25, ctx->r10);
    // 0x801E1F00: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x801E1F04: addu        $t3, $t9, $t1
    ctx->r11 = ADD32(ctx->r25, ctx->r9);
    // 0x801E1F08: lwc1        $f6, 0x64($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X64);
    // 0x801E1F0C: lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // 0x801E1F10: lwc1        $f10, -0x1670($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X1670);
    // 0x801E1F14: lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // 0x801E1F18: lw          $a3, 0x60($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X60);
    // 0x801E1F1C: lwc1        $f16, -0x166C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X166C);
    // 0x801E1F20: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x801E1F24: lwc1        $f8, 0x68($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X68);
    // 0x801E1F28: lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // 0x801E1F2C: lwc1        $f18, -0x1668($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X1668);
    // 0x801E1F30: addiu       $t0, $t9, 0xA4
    ctx->r8 = ADD32(ctx->r25, 0XA4);
    // 0x801E1F34: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x801E1F38: addiu       $a0, $a0, 0x5518
    ctx->r4 = ADD32(ctx->r4, 0X5518);
    // 0x801E1F3C: addu        $a2, $t0, $t1
    ctx->r6 = ADD32(ctx->r8, ctx->r9);
    // 0x801E1F40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801E1F44: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x801E1F48: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    // 0x801E1F4C: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x801E1F50: jal         0x800C6868
    // 0x801E1F54: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    func_800C6868(rdram, ctx);
        goto after_18;
    // 0x801E1F54: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    after_18:
    // 0x801E1F58: b           L_801E2338
    // 0x801E1F5C: nop

        goto L_801E2338;
    // 0x801E1F5C: nop

L_801E1F60:
    // 0x801E1F60: lw          $t4, 0x74($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X74);
    // 0x801E1F64: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801E1F68: addiu       $t7, $t7, -0x2A28
    ctx->r15 = ADD32(ctx->r15, -0X2A28);
    // 0x801E1F6C: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x801E1F70: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x801E1F74: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x801E1F78: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x801E1F7C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x801E1F80: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x801E1F84: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x801E1F88: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x801E1F8C: lwc1        $f4, 0x64($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X64);
    // 0x801E1F90: lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // 0x801E1F94: lwc1        $f8, -0x1664($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1664);
    // 0x801E1F98: lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // 0x801E1F9C: lw          $a3, 0x60($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X60);
    // 0x801E1FA0: lwc1        $f10, -0x1660($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X1660);
    // 0x801E1FA4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x801E1FA8: lwc1        $f6, 0x68($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X68);
    // 0x801E1FAC: lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // 0x801E1FB0: lwc1        $f16, -0x165C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X165C);
    // 0x801E1FB4: addiu       $t6, $t5, 0xA4
    ctx->r14 = ADD32(ctx->r13, 0XA4);
    // 0x801E1FB8: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x801E1FBC: addiu       $a0, $a0, 0x5670
    ctx->r4 = ADD32(ctx->r4, 0X5670);
    // 0x801E1FC0: addu        $a2, $t6, $t7
    ctx->r6 = ADD32(ctx->r14, ctx->r15);
    // 0x801E1FC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801E1FC8: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x801E1FCC: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x801E1FD0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x801E1FD4: jal         0x800C6868
    // 0x801E1FD8: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    func_800C6868(rdram, ctx);
        goto after_19;
    // 0x801E1FD8: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    after_19:
    // 0x801E1FDC: b           L_801E2338
    // 0x801E1FE0: nop

        goto L_801E2338;
    // 0x801E1FE0: nop

L_801E1FE4:
    // 0x801E1FE4: lw          $t2, 0x74($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X74);
    // 0x801E1FE8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x801E1FEC: addiu       $t1, $t1, -0x2A28
    ctx->r9 = ADD32(ctx->r9, -0X2A28);
    // 0x801E1FF0: sll         $t0, $t2, 2
    ctx->r8 = S32(ctx->r10 << 2);
    // 0x801E1FF4: addu        $t0, $t0, $t2
    ctx->r8 = ADD32(ctx->r8, ctx->r10);
    // 0x801E1FF8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x801E1FFC: subu        $t0, $t0, $t2
    ctx->r8 = SUB32(ctx->r8, ctx->r10);
    // 0x801E2000: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x801E2004: addu        $t0, $t0, $t2
    ctx->r8 = ADD32(ctx->r8, ctx->r10);
    // 0x801E2008: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x801E200C: addu        $t3, $t0, $t1
    ctx->r11 = ADD32(ctx->r8, ctx->r9);
    // 0x801E2010: lwc1        $f18, 0x64($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X64);
    // 0x801E2014: lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // 0x801E2018: lwc1        $f6, -0x1658($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1658);
    // 0x801E201C: lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // 0x801E2020: lw          $a3, 0x60($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X60);
    // 0x801E2024: lwc1        $f8, -0x1654($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1654);
    // 0x801E2028: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x801E202C: lwc1        $f4, 0x68($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X68);
    // 0x801E2030: lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // 0x801E2034: lwc1        $f10, -0x1650($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X1650);
    // 0x801E2038: addiu       $t9, $t0, 0xA4
    ctx->r25 = ADD32(ctx->r8, 0XA4);
    // 0x801E203C: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x801E2040: addiu       $a0, $a0, 0x5840
    ctx->r4 = ADD32(ctx->r4, 0X5840);
    // 0x801E2044: addu        $a2, $t9, $t1
    ctx->r6 = ADD32(ctx->r25, ctx->r9);
    // 0x801E2048: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801E204C: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x801E2050: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x801E2054: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x801E2058: jal         0x800C6868
    // 0x801E205C: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    func_800C6868(rdram, ctx);
        goto after_20;
    // 0x801E205C: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    after_20:
    // 0x801E2060: b           L_801E2338
    // 0x801E2064: nop

        goto L_801E2338;
    // 0x801E2064: nop

L_801E2068:
    // 0x801E2068: lw          $t4, 0x74($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X74);
    // 0x801E206C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801E2070: addiu       $t7, $t7, -0x2A28
    ctx->r15 = ADD32(ctx->r15, -0X2A28);
    // 0x801E2074: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x801E2078: addu        $t6, $t6, $t4
    ctx->r14 = ADD32(ctx->r14, ctx->r12);
    // 0x801E207C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801E2080: subu        $t6, $t6, $t4
    ctx->r14 = SUB32(ctx->r14, ctx->r12);
    // 0x801E2084: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801E2088: addu        $t6, $t6, $t4
    ctx->r14 = ADD32(ctx->r14, ctx->r12);
    // 0x801E208C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801E2090: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x801E2094: lwc1        $f16, 0x64($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X64);
    // 0x801E2098: lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // 0x801E209C: lwc1        $f4, -0x164C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X164C);
    // 0x801E20A0: lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // 0x801E20A4: lw          $a3, 0x60($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X60);
    // 0x801E20A8: lwc1        $f6, -0x1648($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1648);
    // 0x801E20AC: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x801E20B0: lwc1        $f18, 0x68($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X68);
    // 0x801E20B4: lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // 0x801E20B8: lwc1        $f8, -0x1644($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1644);
    // 0x801E20BC: addiu       $t5, $t6, 0xA4
    ctx->r13 = ADD32(ctx->r14, 0XA4);
    // 0x801E20C0: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x801E20C4: addiu       $a0, $a0, 0x5998
    ctx->r4 = ADD32(ctx->r4, 0X5998);
    // 0x801E20C8: addu        $a2, $t5, $t7
    ctx->r6 = ADD32(ctx->r13, ctx->r15);
    // 0x801E20CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801E20D0: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x801E20D4: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x801E20D8: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x801E20DC: jal         0x800C6868
    // 0x801E20E0: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    func_800C6868(rdram, ctx);
        goto after_21;
    // 0x801E20E0: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    after_21:
    // 0x801E20E4: b           L_801E2338
    // 0x801E20E8: nop

        goto L_801E2338;
    // 0x801E20E8: nop

L_801E20EC:
    // 0x801E20EC: lw          $t2, 0x74($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X74);
    // 0x801E20F0: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x801E20F4: addiu       $t1, $t1, -0x2A28
    ctx->r9 = ADD32(ctx->r9, -0X2A28);
    // 0x801E20F8: sll         $t9, $t2, 2
    ctx->r25 = S32(ctx->r10 << 2);
    // 0x801E20FC: addu        $t9, $t9, $t2
    ctx->r25 = ADD32(ctx->r25, ctx->r10);
    // 0x801E2100: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x801E2104: subu        $t9, $t9, $t2
    ctx->r25 = SUB32(ctx->r25, ctx->r10);
    // 0x801E2108: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x801E210C: addu        $t9, $t9, $t2
    ctx->r25 = ADD32(ctx->r25, ctx->r10);
    // 0x801E2110: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x801E2114: addu        $t3, $t9, $t1
    ctx->r11 = ADD32(ctx->r25, ctx->r9);
    // 0x801E2118: lwc1        $f10, 0x64($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X64);
    // 0x801E211C: lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // 0x801E2120: lwc1        $f18, -0x1640($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X1640);
    // 0x801E2124: lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // 0x801E2128: lw          $a3, 0x60($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X60);
    // 0x801E212C: lwc1        $f4, -0x163C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X163C);
    // 0x801E2130: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x801E2134: lwc1        $f16, 0x68($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X68);
    // 0x801E2138: lui         $at, 0x801F
    ctx->r1 = S32(0X801F << 16);
    // 0x801E213C: lwc1        $f6, -0x1638($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1638);
    // 0x801E2140: addiu       $t0, $t9, 0xA4
    ctx->r8 = ADD32(ctx->r25, 0XA4);
    // 0x801E2144: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x801E2148: addiu       $a0, $a0, 0x5AC0
    ctx->r4 = ADD32(ctx->r4, 0X5AC0);
    // 0x801E214C: addu        $a2, $t0, $t1
    ctx->r6 = ADD32(ctx->r8, ctx->r9);
    // 0x801E2150: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801E2154: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    // 0x801E2158: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x801E215C: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x801E2160: jal         0x800C6868
    // 0x801E2164: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    func_800C6868(rdram, ctx);
        goto after_22;
    // 0x801E2164: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    after_22:
    // 0x801E2168: b           L_801E2338
    // 0x801E216C: nop

        goto L_801E2338;
    // 0x801E216C: nop

L_801E2170:
    // 0x801E2170: lui         $a1, 0x3E8F
    ctx->r5 = S32(0X3E8F << 16);
    // 0x801E2174: lui         $a2, 0x3E85
    ctx->r6 = S32(0X3E85 << 16);
    // 0x801E2178: addiu       $t4, $zero, 0xE6
    ctx->r12 = ADD32(0, 0XE6);
    // 0x801E217C: addiu       $t5, $zero, 0xE6
    ctx->r13 = ADD32(0, 0XE6);
    // 0x801E2180: addiu       $t6, $zero, 0xE6
    ctx->r14 = ADD32(0, 0XE6);
    // 0x801E2184: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x801E2188: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x801E218C: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x801E2190: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x801E2194: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x801E2198: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x801E219C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x801E21A0: ori         $a2, $a2, 0x1EB8
    ctx->r6 = ctx->r6 | 0X1EB8;
    // 0x801E21A4: ori         $a1, $a1, 0x5C29
    ctx->r5 = ctx->r5 | 0X5C29;
    // 0x801E21A8: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x801E21AC: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x801E21B0: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x801E21B4: jal         0x801E0F7C
    // 0x801E21B8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    func_801E0F7C_0BA450(rdram, ctx);
        goto after_23;
    // 0x801E21B8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_23:
    // 0x801E21BC: b           L_801E2338
    // 0x801E21C0: nop

        goto L_801E2338;
    // 0x801E21C0: nop

L_801E21C4:
    // 0x801E21C4: lw          $t2, 0x74($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X74);
    // 0x801E21C8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801E21CC: addiu       $t9, $t9, -0x2A28
    ctx->r25 = ADD32(ctx->r25, -0X2A28);
    // 0x801E21D0: sll         $t0, $t2, 2
    ctx->r8 = S32(ctx->r10 << 2);
    // 0x801E21D4: addu        $t0, $t0, $t2
    ctx->r8 = ADD32(ctx->r8, ctx->r10);
    // 0x801E21D8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x801E21DC: subu        $t0, $t0, $t2
    ctx->r8 = SUB32(ctx->r8, ctx->r10);
    // 0x801E21E0: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x801E21E4: addu        $t0, $t0, $t2
    ctx->r8 = ADD32(ctx->r8, ctx->r10);
    // 0x801E21E8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x801E21EC: addu        $t1, $t0, $t9
    ctx->r9 = ADD32(ctx->r8, ctx->r25);
    // 0x801E21F0: lhu         $t3, 0x0($t1)
    ctx->r11 = MEM_HU(ctx->r9, 0X0);
    // 0x801E21F4: andi        $t4, $t3, 0x8000
    ctx->r12 = ctx->r11 & 0X8000;
    // 0x801E21F8: bne         $t4, $zero, L_801E2208
    if (ctx->r12 != 0) {
        // 0x801E21FC: nop
    
            goto L_801E2208;
    }
    // 0x801E21FC: nop

    // 0x801E2200: b           L_801E2340
    // 0x801E2204: sw          $zero, 0x2C($t1)
    MEM_W(0X2C, ctx->r9) = 0;
        goto L_801E2340;
    // 0x801E2204: sw          $zero, 0x2C($t1)
    MEM_W(0X2C, ctx->r9) = 0;
L_801E2208:
    // 0x801E2208: lw          $t5, 0x74($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X74);
    // 0x801E220C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801E2210: addiu       $t7, $t7, -0x2A28
    ctx->r15 = ADD32(ctx->r15, -0X2A28);
    // 0x801E2214: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x801E2218: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x801E221C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801E2220: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x801E2224: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801E2228: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x801E222C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801E2230: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x801E2234: lw          $t2, 0x2C($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X2C);
    // 0x801E2238: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x801E223C: addiu       $t0, $t2, 0x1
    ctx->r8 = ADD32(ctx->r10, 0X1);
    // 0x801E2240: sw          $t0, 0x2C($t8)
    MEM_W(0X2C, ctx->r24) = ctx->r8;
    // 0x801E2244: lw          $t9, 0x74($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X74);
    // 0x801E2248: sll         $t3, $t9, 2
    ctx->r11 = S32(ctx->r25 << 2);
    // 0x801E224C: addu        $t3, $t3, $t9
    ctx->r11 = ADD32(ctx->r11, ctx->r25);
    // 0x801E2250: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x801E2254: subu        $t3, $t3, $t9
    ctx->r11 = SUB32(ctx->r11, ctx->r25);
    // 0x801E2258: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x801E225C: addu        $t3, $t3, $t9
    ctx->r11 = ADD32(ctx->r11, ctx->r25);
    // 0x801E2260: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x801E2264: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x801E2268: lw          $t4, -0x29FC($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X29FC);
    // 0x801E226C: sltiu       $at, $t4, 0x4
    ctx->r1 = ctx->r12 < 0X4 ? 1 : 0;
    // 0x801E2270: beq         $at, $zero, L_801E22E8
    if (ctx->r1 == 0) {
        // 0x801E2274: nop
    
            goto L_801E22E8;
    }
    // 0x801E2274: nop

    // 0x801E2278: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x801E227C: lw          $t1, -0x4514($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4514);
    // 0x801E2280: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x801E2284: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x801E2288: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x801E228C: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x801E2290: addiu       $t5, $t1, 0x8
    ctx->r13 = ADD32(ctx->r9, 0X8);
    // 0x801E2294: sw          $t5, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r13;
    // 0x801E2298: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x801E229C: lw          $t2, 0x74($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X74);
    // 0x801E22A0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x801E22A4: lui         $at, 0xFFFA
    ctx->r1 = S32(0XFFFA << 16);
    // 0x801E22A8: sll         $t0, $t2, 2
    ctx->r8 = S32(ctx->r10 << 2);
    // 0x801E22AC: addu        $t0, $t0, $t2
    ctx->r8 = ADD32(ctx->r8, ctx->r10);
    // 0x801E22B0: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x801E22B4: subu        $t0, $t0, $t2
    ctx->r8 = SUB32(ctx->r8, ctx->r10);
    // 0x801E22B8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x801E22BC: addu        $t0, $t0, $t2
    ctx->r8 = ADD32(ctx->r8, ctx->r10);
    // 0x801E22C0: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x801E22C4: addu        $t8, $t8, $t0
    ctx->r24 = ADD32(ctx->r24, ctx->r8);
    // 0x801E22C8: lw          $t8, -0x29FC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X29FC);
    // 0x801E22CC: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x801E22D0: ori         $at, $at, 0xFA00
    ctx->r1 = ctx->r1 | 0XFA00;
    // 0x801E22D4: sll         $t9, $t8, 6
    ctx->r25 = S32(ctx->r24 << 6);
    // 0x801E22D8: andi        $t3, $t9, 0xFF
    ctx->r11 = ctx->r25 & 0XFF;
    // 0x801E22DC: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x801E22E0: b           L_801E231C
    // 0x801E22E4: sw          $t4, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r12;
        goto L_801E231C;
    // 0x801E22E4: sw          $t4, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r12;
L_801E22E8:
    // 0x801E22E8: lui         $t5, 0x8011
    ctx->r13 = S32(0X8011 << 16);
    // 0x801E22EC: lw          $t5, -0x4514($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4514);
    // 0x801E22F0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x801E22F4: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x801E22F8: sw          $t5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r13;
    // 0x801E22FC: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x801E2300: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x801E2304: sw          $t6, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r14;
    // 0x801E2308: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
    // 0x801E230C: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x801E2310: lui         $t0, 0xFFFA
    ctx->r8 = S32(0XFFFA << 16);
    // 0x801E2314: ori         $t0, $t0, 0xFAFF
    ctx->r8 = ctx->r8 | 0XFAFF;
    // 0x801E2318: sw          $t0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r8;
L_801E231C:
    // 0x801E231C: lui         $a1, 0x3CA3
    ctx->r5 = S32(0X3CA3 << 16);
    // 0x801E2320: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    // 0x801E2324: lui         $a2, 0x3CF5
    ctx->r6 = S32(0X3CF5 << 16);
    // 0x801E2328: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x801E232C: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // 0x801E2330: jal         0x801E1190
    // 0x801E2334: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    func_801E1190_0BA450(rdram, ctx);
        goto after_24;
    // 0x801E2334: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    after_24:
L_801E2338:
    // 0x801E2338: jal         0x801E08D4
    // 0x801E233C: nop

    func_801E08D4_0BA450(rdram, ctx);
        goto after_25;
    // 0x801E233C: nop

    after_25:
L_801E2340:
    // 0x801E2340: lw          $t9, 0x74($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X74);
    // 0x801E2344: addiu       $t3, $t9, 0x1
    ctx->r11 = ADD32(ctx->r25, 0X1);
    // 0x801E2348: slti        $at, $t3, 0x30
    ctx->r1 = SIGNED(ctx->r11) < 0X30 ? 1 : 0;
    // 0x801E234C: bne         $at, $zero, L_801E135C
    if (ctx->r1 != 0) {
        // 0x801E2350: sw          $t3, 0x74($sp)
        MEM_W(0X74, ctx->r29) = ctx->r11;
            goto L_801E135C;
    }
    // 0x801E2350: sw          $t3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r11;
    // 0x801E2354: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x801E2358: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x801E235C: jr          $ra
    // 0x801E2360: nop

    return;
    // 0x801E2360: nop

;}
RECOMP_FUNC void func_801E2364_0BA450(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E2364: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x801E2368: lhu         $t6, -0x4530($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X4530);
    // 0x801E236C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E2370: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E2374: andi        $t7, $t6, 0x100
    ctx->r15 = ctx->r14 & 0X100;
    // 0x801E2378: bne         $t7, $zero, L_801E23A8
    if (ctx->r15 != 0) {
        // 0x801E237C: nop
    
            goto L_801E23A8;
    }
    // 0x801E237C: nop

    // 0x801E2380: jal         0x801E08D4
    // 0x801E2384: nop

    func_801E08D4_0BA450(rdram, ctx);
        goto after_0;
    // 0x801E2384: nop

    after_0:
    // 0x801E2388: jal         0x801E0994
    // 0x801E238C: nop

    func_801E0994_0BA450(rdram, ctx);
        goto after_1;
    // 0x801E238C: nop

    after_1:
    // 0x801E2390: jal         0x801E08D4
    // 0x801E2394: nop

    func_801E08D4_0BA450(rdram, ctx);
        goto after_2;
    // 0x801E2394: nop

    after_2:
    // 0x801E2398: jal         0x801E1350
    // 0x801E239C: nop

    func_801E1350_0BA450(rdram, ctx);
        goto after_3;
    // 0x801E239C: nop

    after_3:
    // 0x801E23A0: jal         0x801E08D4
    // 0x801E23A4: nop

    func_801E08D4_0BA450(rdram, ctx);
        goto after_4;
    // 0x801E23A4: nop

    after_4:
L_801E23A8:
    // 0x801E23A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E23AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E23B0: jr          $ra
    // 0x801E23B4: nop

    return;
    // 0x801E23B4: nop

    // 0x801E23B8: nop

    // 0x801E23BC: nop

;}
RECOMP_FUNC void func_8017B0C0_0EF7C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017B0C0: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x8017B0C4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017B0C8: sw          $t6, -0x2E50($at)
    MEM_W(-0X2E50, ctx->r1) = ctx->r14;
    // 0x8017B0CC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017B0D0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017B0D4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017B0D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017B0DC: addiu       $t7, $t7, -0x2E28
    ctx->r15 = ADD32(ctx->r15, -0X2E28);
    // 0x8017B0E0: sw          $zero, -0x2E4C($at)
    MEM_W(-0X2E4C, ctx->r1) = 0;
    // 0x8017B0E4: lbu         $t8, 0xA($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0XA);
    // 0x8017B0E8: addiu       $a0, $zero, 0x280
    ctx->r4 = ADD32(0, 0X280);
    // 0x8017B0EC: addiu       $a1, $zero, 0x1A4
    ctx->r5 = ADD32(0, 0X1A4);
    // 0x8017B0F0: andi        $t9, $t8, 0xFD
    ctx->r25 = ctx->r24 & 0XFD;
    // 0x8017B0F4: jal         0x800C30F4
    // 0x8017B0F8: sb          $t9, 0xA($t7)
    MEM_B(0XA, ctx->r15) = ctx->r25;
    func_800C30F4(rdram, ctx);
        goto after_0;
    // 0x8017B0F8: sb          $t9, 0xA($t7)
    MEM_B(0XA, ctx->r15) = ctx->r25;
    after_0:
    // 0x8017B0FC: jal         0x8017B2D4
    // 0x8017B100: nop

    func_8017B2D4_0EF7C0(rdram, ctx);
        goto after_1;
    // 0x8017B100: nop

    after_1:
    // 0x8017B104: jal         0x800C328C
    // 0x8017B108: nop

    func_800C328C(rdram, ctx);
        goto after_2;
    // 0x8017B108: nop

    after_2:
    // 0x8017B10C: jal         0x800C7FA4
    // 0x8017B110: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    func_800C7FA4(rdram, ctx);
        goto after_3;
    // 0x8017B110: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    after_3:
    // 0x8017B114: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8017B118: jal         0x800D1640
    // 0x8017B11C: addiu       $a0, $a0, -0x4E58
    ctx->r4 = ADD32(ctx->r4, -0X4E58);
    func_800D1640(rdram, ctx);
        goto after_4;
    // 0x8017B11C: addiu       $a0, $a0, -0x4E58
    ctx->r4 = ADD32(ctx->r4, -0X4E58);
    after_4:
    // 0x8017B120: jal         0x800C8544
    // 0x8017B124: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    func_800C8544(rdram, ctx);
        goto after_5;
    // 0x8017B124: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    after_5:
L_8017B128:
    // 0x8017B128: jal         0x800E4CDC
    // 0x8017B12C: nop

    func_800E4CDC(rdram, ctx);
        goto after_6;
    // 0x8017B12C: nop

    after_6:
    // 0x8017B130: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017B134: addiu       $t0, $t0, -0x2E18
    ctx->r8 = ADD32(ctx->r8, -0X2E18);
    // 0x8017B138: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x8017B13C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017B140: lw          $t1, -0x2E4C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2E4C);
    // 0x8017B144: beq         $t1, $zero, L_8017B128
    if (ctx->r9 == 0) {
        // 0x8017B148: nop
    
            goto L_8017B128;
    }
    // 0x8017B148: nop

    // 0x8017B14C: lui         $t2, 0x8011
    ctx->r10 = S32(0X8011 << 16);
    // 0x8017B150: lhu         $t2, -0x4530($t2)
    ctx->r10 = MEM_HU(ctx->r10, -0X4530);
    // 0x8017B154: andi        $t3, $t2, 0x2000
    ctx->r11 = ctx->r10 & 0X2000;
    // 0x8017B158: bne         $t3, $zero, L_8017B128
    if (ctx->r11 != 0) {
        // 0x8017B15C: nop
    
            goto L_8017B128;
    }
    // 0x8017B15C: nop

    // 0x8017B160: jal         0x800CB720
    // 0x8017B164: nop

    func_800CB720(rdram, ctx);
        goto after_7;
    // 0x8017B164: nop

    after_7:
    // 0x8017B168: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8017B16C: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8017B170: bne         $t4, $zero, L_8017B128
    if (ctx->r12 != 0) {
        // 0x8017B174: nop
    
            goto L_8017B128;
    }
    // 0x8017B174: nop

    // 0x8017B178: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017B17C: addiu       $t5, $t5, -0x2E28
    ctx->r13 = ADD32(ctx->r13, -0X2E28);
    // 0x8017B180: lbu         $t6, 0xA($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0XA);
    // 0x8017B184: andi        $t8, $t6, 0xFD
    ctx->r24 = ctx->r14 & 0XFD;
    // 0x8017B188: jal         0x800C6DD4
    // 0x8017B18C: sb          $t8, 0xA($t5)
    MEM_B(0XA, ctx->r13) = ctx->r24;
    func_800C6DD4(rdram, ctx);
        goto after_8;
    // 0x8017B18C: sb          $t8, 0xA($t5)
    MEM_B(0XA, ctx->r13) = ctx->r24;
    after_8:
    // 0x8017B190: jal         0x800C7154
    // 0x8017B194: nop

    func_800C7154(rdram, ctx);
        goto after_9;
    // 0x8017B194: nop

    after_9:
    // 0x8017B198: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017B19C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017B1A0: jr          $ra
    // 0x8017B1A4: nop

    return;
    // 0x8017B1A4: nop

;}
RECOMP_FUNC void func_8017B1A8_0EF7C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017B1A8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8017B1AC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8017B1B0: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8017B1B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8017B1B8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8017B1BC: bgtz        $t6, L_8017B2C0
    if (SIGNED(ctx->r14) > 0) {
        // 0x8017B1C0: nop
    
            goto L_8017B2C0;
    }
    // 0x8017B1C0: nop

    // 0x8017B1C4: jal         0x800C3704
    // 0x8017B1C8: nop

    func_800C3704(rdram, ctx);
        goto after_0;
    // 0x8017B1C8: nop

    after_0:
    // 0x8017B1CC: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x8017B1D0: lw          $t7, -0x4514($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4514);
    // 0x8017B1D4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8017B1D8: lui         $t9, 0xDB06
    ctx->r25 = S32(0XDB06 << 16);
    // 0x8017B1DC: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x8017B1E0: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8017B1E4: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8017B1E8: sw          $t8, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r24;
    // 0x8017B1EC: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x8017B1F0: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8017B1F4: jal         0x800C7458
    // 0x8017B1F8: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    func_800C7458(rdram, ctx);
        goto after_1;
    // 0x8017B1F8: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    after_1:
    // 0x8017B1FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8017B200: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8017B204: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8017B208: jal         0x800C25FC
    // 0x8017B20C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800C25FC(rdram, ctx);
        goto after_2;
    // 0x8017B20C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x8017B210: jal         0x800C3578
    // 0x8017B214: nop

    func_800C3578(rdram, ctx);
        goto after_3;
    // 0x8017B214: nop

    after_3:
    // 0x8017B218: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017B21C: addiu       $t2, $t2, 0x3B00
    ctx->r10 = ADD32(ctx->r10, 0X3B00);
    // 0x8017B220: lbu         $s0, 0x14($t2)
    ctx->r16 = MEM_BU(ctx->r10, 0X14);
    // 0x8017B224: beq         $s0, $zero, L_8017B23C
    if (ctx->r16 == 0) {
        // 0x8017B228: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8017B23C;
    }
    // 0x8017B228: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8017B22C: beq         $s0, $at, L_8017B254
    if (ctx->r16 == ctx->r1) {
        // 0x8017B230: nop
    
            goto L_8017B254;
    }
    // 0x8017B230: nop

    // 0x8017B234: b           L_8017B264
    // 0x8017B238: nop

        goto L_8017B264;
    // 0x8017B238: nop

L_8017B23C:
    // 0x8017B23C: jal         0x8017B4A4
    // 0x8017B240: nop

    func_8017B4A4_0EF7C0(rdram, ctx);
        goto after_4;
    // 0x8017B240: nop

    after_4:
    // 0x8017B244: jal         0x8017C0A8
    // 0x8017B248: nop

    func_8017C0A8_0EF7C0(rdram, ctx);
        goto after_5;
    // 0x8017B248: nop

    after_5:
    // 0x8017B24C: b           L_8017B264
    // 0x8017B250: nop

        goto L_8017B264;
    // 0x8017B250: nop

L_8017B254:
    // 0x8017B254: jal         0x8017BB94
    // 0x8017B258: nop

    func_8017BB94_0EF7C0(rdram, ctx);
        goto after_6;
    // 0x8017B258: nop

    after_6:
    // 0x8017B25C: jal         0x8017C95C
    // 0x8017B260: nop

    func_8017C95C_0EF7C0(rdram, ctx);
        goto after_7;
    // 0x8017B260: nop

    after_7:
L_8017B264:
    // 0x8017B264: jal         0x8017C024
    // 0x8017B268: nop

    func_8017C024_0EF7C0(rdram, ctx);
        goto after_8;
    // 0x8017B268: nop

    after_8:
    // 0x8017B26C: jal         0x800C3FD0
    // 0x8017B270: nop

    func_800C3FD0(rdram, ctx);
        goto after_9;
    // 0x8017B270: nop

    after_9:
    // 0x8017B274: jal         0x800C3760
    // 0x8017B278: nop

    func_800C3760(rdram, ctx);
        goto after_10;
    // 0x8017B278: nop

    after_10:
    // 0x8017B27C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017B280: lw          $t3, -0x2E4C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2E4C);
    // 0x8017B284: beq         $t3, $zero, L_8017B2C0
    if (ctx->r11 == 0) {
        // 0x8017B288: nop
    
            goto L_8017B2C0;
    }
    // 0x8017B288: nop

    // 0x8017B28C: lui         $t4, 0x8011
    ctx->r12 = S32(0X8011 << 16);
    // 0x8017B290: lhu         $t4, -0x4530($t4)
    ctx->r12 = MEM_HU(ctx->r12, -0X4530);
    // 0x8017B294: andi        $t5, $t4, 0x2000
    ctx->r13 = ctx->r12 & 0X2000;
    // 0x8017B298: bne         $t5, $zero, L_8017B2C0
    if (ctx->r13 != 0) {
        // 0x8017B29C: nop
    
            goto L_8017B2C0;
    }
    // 0x8017B29C: nop

    // 0x8017B2A0: jal         0x800CB720
    // 0x8017B2A4: nop

    func_800CB720(rdram, ctx);
        goto after_11;
    // 0x8017B2A4: nop

    after_11:
    // 0x8017B2A8: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8017B2AC: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8017B2B0: bne         $t6, $zero, L_8017B2C0
    if (ctx->r14 != 0) {
        // 0x8017B2B4: nop
    
            goto L_8017B2C0;
    }
    // 0x8017B2B4: nop

    // 0x8017B2B8: jal         0x800D1640
    // 0x8017B2BC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800D1640(rdram, ctx);
        goto after_12;
    // 0x8017B2BC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_12:
L_8017B2C0:
    // 0x8017B2C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8017B2C4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8017B2C8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8017B2CC: jr          $ra
    // 0x8017B2D0: nop

    return;
    // 0x8017B2D0: nop

;}
RECOMP_FUNC void func_8017B2D4_0EF7C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017B2D4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8017B2D8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017B2DC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8017B2E0: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8017B2E4: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8017B2E8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8017B2EC: addiu       $t6, $t6, 0x3B00
    ctx->r14 = ADD32(ctx->r14, 0X3B00);
    // 0x8017B2F0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017B2F4: addiu       $t7, $t7, 0x3B00
    ctx->r15 = ADD32(ctx->r15, 0X3B00);
    // 0x8017B2F8: sb          $zero, 0x29($t6)
    MEM_B(0X29, ctx->r14) = 0;
    // 0x8017B2FC: lbu         $s0, 0x29($t7)
    ctx->r16 = MEM_BU(ctx->r15, 0X29);
    // 0x8017B300: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017B304: addiu       $t8, $t8, 0x3B00
    ctx->r24 = ADD32(ctx->r24, 0X3B00);
    // 0x8017B308: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017B30C: sb          $s0, 0x1E($t7)
    MEM_B(0X1E, ctx->r15) = ctx->r16;
    // 0x8017B310: addiu       $t9, $t9, 0x3B80
    ctx->r25 = ADD32(ctx->r25, 0X3B80);
    // 0x8017B314: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017B318: sb          $s0, 0x14($t8)
    MEM_B(0X14, ctx->r24) = ctx->r16;
    // 0x8017B31C: sh          $zero, 0x1A($t9)
    MEM_H(0X1A, ctx->r25) = 0;
    // 0x8017B320: addiu       $t0, $t0, 0x3B80
    ctx->r8 = ADD32(ctx->r8, 0X3B80);
    // 0x8017B324: lhu         $s2, 0x1A($t0)
    ctx->r18 = MEM_HU(ctx->r8, 0X1A);
    // 0x8017B328: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017B32C: addiu       $t1, $t1, 0x3B80
    ctx->r9 = ADD32(ctx->r9, 0X3B80);
    // 0x8017B330: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017B334: sh          $s2, 0x18($t0)
    MEM_H(0X18, ctx->r8) = ctx->r18;
    // 0x8017B338: andi        $s1, $s2, 0xFFFF
    ctx->r17 = ctx->r18 & 0XFFFF;
    // 0x8017B33C: sh          $s1, 0x16($t1)
    MEM_H(0X16, ctx->r9) = ctx->r17;
    // 0x8017B340: addiu       $t2, $t2, 0x3B80
    ctx->r10 = ADD32(ctx->r10, 0X3B80);
    // 0x8017B344: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017B348: sh          $s1, 0x14($t2)
    MEM_H(0X14, ctx->r10) = ctx->r17;
    // 0x8017B34C: addiu       $t3, $t3, 0x3B80
    ctx->r11 = ADD32(ctx->r11, 0X3B80);
    // 0x8017B350: sh          $zero, 0x3C($t3)
    MEM_H(0X3C, ctx->r11) = 0;
    // 0x8017B354: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017B358: lw          $t4, -0x2E48($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2E48);
    // 0x8017B35C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017B360: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8017B364: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8017B368: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x8017B36C: lwc1        $f4, -0x1180($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1180);
    // 0x8017B370: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017B374: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x8017B378: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017B37C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8017B380: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8017B384: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017B388: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x8017B38C: swc1        $f4, 0x78($t6)
    MEM_W(0X78, ctx->r14) = ctx->f4.u32l;
    // 0x8017B390: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017B394: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8017B398: swc1        $f6, 0x7C($t7)
    MEM_W(0X7C, ctx->r15) = ctx->f6.u32l;
    // 0x8017B39C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8017B3A0: addiu       $t8, $t8, -0x4198
    ctx->r24 = ADD32(ctx->r24, -0X4198);
    // 0x8017B3A4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017B3A8: addiu       $t9, $t9, -0x4198
    ctx->r25 = ADD32(ctx->r25, -0X4198);
    // 0x8017B3AC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017B3B0: swc1        $f8, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f8.u32l;
    // 0x8017B3B4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8017B3B8: addiu       $t0, $t0, -0x4198
    ctx->r8 = ADD32(ctx->r8, -0X4198);
    // 0x8017B3BC: lui         $at, 0x42DC
    ctx->r1 = S32(0X42DC << 16);
    // 0x8017B3C0: swc1        $f10, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f10.u32l;
    // 0x8017B3C4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017B3C8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017B3CC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017B3D0: swc1        $f16, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f16.u32l;
    // 0x8017B3D4: addiu       $t1, $t1, -0x4198
    ctx->r9 = ADD32(ctx->r9, -0X4198);
    // 0x8017B3D8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017B3DC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8017B3E0: addiu       $t2, $t2, -0x4198
    ctx->r10 = ADD32(ctx->r10, -0X4198);
    // 0x8017B3E4: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017B3E8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017B3EC: swc1        $f18, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f18.u32l;
    // 0x8017B3F0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017B3F4: addiu       $t3, $t3, -0x4198
    ctx->r11 = ADD32(ctx->r11, -0X4198);
    // 0x8017B3F8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017B3FC: swc1        $f4, 0x10($t2)
    MEM_W(0X10, ctx->r10) = ctx->f4.u32l;
    // 0x8017B400: addiu       $t4, $t4, -0x4198
    ctx->r12 = ADD32(ctx->r12, -0X4198);
    // 0x8017B404: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017B408: swc1        $f6, 0x14($t3)
    MEM_W(0X14, ctx->r11) = ctx->f6.u32l;
    // 0x8017B40C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8017B410: addiu       $t5, $t5, -0x4198
    ctx->r13 = ADD32(ctx->r13, -0X4198);
    // 0x8017B414: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017B418: swc1        $f8, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->f8.u32l;
    // 0x8017B41C: addiu       $t6, $t6, -0x4198
    ctx->r14 = ADD32(ctx->r14, -0X4198);
    // 0x8017B420: swc1        $f10, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = ctx->f10.u32l;
    // 0x8017B424: jal         0x800C3FD0
    // 0x8017B428: swc1        $f16, 0x20($t6)
    MEM_W(0X20, ctx->r14) = ctx->f16.u32l;
    func_800C3FD0(rdram, ctx);
        goto after_0;
    // 0x8017B428: swc1        $f16, 0x20($t6)
    MEM_W(0X20, ctx->r14) = ctx->f16.u32l;
    after_0:
    // 0x8017B42C: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    // 0x8017B430: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    // 0x8017B434: jal         0x800C6E0C
    // 0x8017B438: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    func_800C6E0C(rdram, ctx);
        goto after_1;
    // 0x8017B438: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    after_1:
    // 0x8017B43C: addiu       $t7, $zero, 0x32
    ctx->r15 = ADD32(0, 0X32);
    // 0x8017B440: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x8017B444: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8017B448: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8017B44C: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    // 0x8017B450: addiu       $a1, $zero, 0x96
    ctx->r5 = ADD32(0, 0X96);
    // 0x8017B454: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    // 0x8017B458: jal         0x800C6E68
    // 0x8017B45C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800C6E68(rdram, ctx);
        goto after_2;
    // 0x8017B45C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x8017B460: addiu       $t9, $zero, 0x3E3
    ctx->r25 = ADD32(0, 0X3E3);
    // 0x8017B464: addiu       $t0, $zero, 0x3E8
    ctx->r8 = ADD32(0, 0X3E8);
    // 0x8017B468: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8017B46C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8017B470: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8017B474: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8017B478: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8017B47C: jal         0x800C70C0
    // 0x8017B480: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    func_800C70C0(rdram, ctx);
        goto after_3;
    // 0x8017B480: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_3:
    // 0x8017B484: jal         0x800C6DBC
    // 0x8017B488: nop

    func_800C6DBC(rdram, ctx);
        goto after_4;
    // 0x8017B488: nop

    after_4:
    // 0x8017B48C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8017B490: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8017B494: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8017B498: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8017B49C: jr          $ra
    // 0x8017B4A0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8017B4A0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8017B4A4_0EF7C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017B4A4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017B4A8: lw          $t6, -0x2E4C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2E4C);
    // 0x8017B4AC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8017B4B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8017B4B4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8017B4B8: beq         $t6, $zero, L_8017B524
    if (ctx->r14 == 0) {
        // 0x8017B4BC: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_8017B524;
    }
    // 0x8017B4BC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8017B4C0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8017B4C4: bne         $t6, $at, L_8017BB80
    if (ctx->r14 != ctx->r1) {
        // 0x8017B4C8: nop
    
            goto L_8017BB80;
    }
    // 0x8017B4C8: nop

    // 0x8017B4CC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017B4D0: addiu       $t7, $t7, -0x4198
    ctx->r15 = ADD32(ctx->r15, -0X4198);
    // 0x8017B4D4: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x8017B4D8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017B4DC: lwc1        $f4, 0x0($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X0);
    // 0x8017B4E0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017B4E4: addiu       $t8, $t8, -0x4198
    ctx->r24 = ADD32(ctx->r24, -0X4198);
    // 0x8017B4E8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8017B4EC: lui         $at, 0xC20C
    ctx->r1 = S32(0XC20C << 16);
    // 0x8017B4F0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8017B4F4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017B4F8: swc1        $f8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f8.u32l;
    // 0x8017B4FC: lwc1        $f10, 0x8($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X8);
    // 0x8017B500: addiu       $t9, $t9, -0x4198
    ctx->r25 = ADD32(ctx->r25, -0X4198);
    // 0x8017B504: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x8017B508: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8017B50C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017B510: swc1        $f18, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f18.u32l;
    // 0x8017B514: lwc1        $f4, 0x14($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X14);
    // 0x8017B518: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8017B51C: b           L_8017BB80
    // 0x8017B520: swc1        $f8, 0x14($t9)
    MEM_W(0X14, ctx->r25) = ctx->f8.u32l;
        goto L_8017BB80;
    // 0x8017B520: swc1        $f8, 0x14($t9)
    MEM_W(0X14, ctx->r25) = ctx->f8.u32l;
L_8017B524:
    // 0x8017B524: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017B528: addiu       $t0, $t0, 0x3B00
    ctx->r8 = ADD32(ctx->r8, 0X3B00);
    // 0x8017B52C: lbu         $s0, 0x1E($t0)
    ctx->r16 = MEM_BU(ctx->r8, 0X1E);
    // 0x8017B530: beq         $s0, $zero, L_8017B550
    if (ctx->r16 == 0) {
        // 0x8017B534: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8017B550;
    }
    // 0x8017B534: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8017B538: beq         $s0, $at, L_8017B69C
    if (ctx->r16 == ctx->r1) {
        // 0x8017B53C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8017B69C;
    }
    // 0x8017B53C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8017B540: beq         $s0, $at, L_8017B8D0
    if (ctx->r16 == ctx->r1) {
        // 0x8017B544: nop
    
            goto L_8017B8D0;
    }
    // 0x8017B544: nop

    // 0x8017B548: b           L_8017BB80
    // 0x8017B54C: nop

        goto L_8017BB80;
    // 0x8017B54C: nop

L_8017B550:
    // 0x8017B550: sb          $zero, 0x2F($sp)
    MEM_B(0X2F, ctx->r29) = 0;
    // 0x8017B554: sb          $zero, 0x2E($sp)
    MEM_B(0X2E, ctx->r29) = 0;
L_8017B558:
    // 0x8017B558: lbu         $t1, 0x2F($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X2F);
    // 0x8017B55C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017B560: addiu       $t3, $t3, 0x3B80
    ctx->r11 = ADD32(ctx->r11, 0X3B80);
    // 0x8017B564: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x8017B568: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8017B56C: lhu         $t5, 0x14($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X14);
    // 0x8017B570: slti        $at, $t5, 0x8
    ctx->r1 = SIGNED(ctx->r13) < 0X8 ? 1 : 0;
    // 0x8017B574: beq         $at, $zero, L_8017B5BC
    if (ctx->r1 == 0) {
        // 0x8017B578: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_8017B5BC;
    }
    // 0x8017B578: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8017B57C: beq         $t5, $at, L_8017B610
    if (ctx->r13 == ctx->r1) {
        // 0x8017B580: nop
    
            goto L_8017B610;
    }
    // 0x8017B580: nop

    // 0x8017B584: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8017B588: sh          $t6, 0x14($t4)
    MEM_H(0X14, ctx->r12) = ctx->r14;
    // 0x8017B58C: lbu         $t7, 0x2F($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X2F);
    // 0x8017B590: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017B594: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8017B598: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8017B59C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8017B5A0: lhu         $t9, 0x3B94($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X3B94);
    // 0x8017B5A4: bne         $t9, $at, L_8017B610
    if (ctx->r25 != ctx->r1) {
        // 0x8017B5A8: nop
    
            goto L_8017B610;
    }
    // 0x8017B5A8: nop

    // 0x8017B5AC: jal         0x800C8544
    // 0x8017B5B0: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    func_800C8544(rdram, ctx);
        goto after_0;
    // 0x8017B5B0: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_0:
    // 0x8017B5B4: b           L_8017B610
    // 0x8017B5B8: nop

        goto L_8017B610;
    // 0x8017B5B8: nop

L_8017B5BC:
    // 0x8017B5BC: lbu         $t0, 0x2F($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X2F);
    // 0x8017B5C0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017B5C4: addiu       $t2, $t2, 0x3B80
    ctx->r10 = ADD32(ctx->r10, 0X3B80);
    // 0x8017B5C8: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x8017B5CC: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x8017B5D0: lhu         $t5, 0x14($t3)
    ctx->r13 = MEM_HU(ctx->r11, 0X14);
    // 0x8017B5D4: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8017B5D8: beq         $t5, $at, L_8017B610
    if (ctx->r13 == ctx->r1) {
        // 0x8017B5DC: nop
    
            goto L_8017B610;
    }
    // 0x8017B5DC: nop

    // 0x8017B5E0: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x8017B5E4: sh          $t6, 0x14($t3)
    MEM_H(0X14, ctx->r11) = ctx->r14;
    // 0x8017B5E8: lbu         $t4, 0x2F($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X2F);
    // 0x8017B5EC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017B5F0: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8017B5F4: sll         $t7, $t4, 1
    ctx->r15 = S32(ctx->r12 << 1);
    // 0x8017B5F8: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8017B5FC: lhu         $t8, 0x3B94($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X3B94);
    // 0x8017B600: bne         $t8, $at, L_8017B610
    if (ctx->r24 != ctx->r1) {
        // 0x8017B604: nop
    
            goto L_8017B610;
    }
    // 0x8017B604: nop

    // 0x8017B608: jal         0x800C8544
    // 0x8017B60C: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    func_800C8544(rdram, ctx);
        goto after_1;
    // 0x8017B60C: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_1:
L_8017B610:
    // 0x8017B610: lbu         $t9, 0x2F($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X2F);
    // 0x8017B614: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017B618: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8017B61C: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x8017B620: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8017B624: lhu         $t1, 0x3B94($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X3B94);
    // 0x8017B628: beq         $t1, $at, L_8017B63C
    if (ctx->r9 == ctx->r1) {
        // 0x8017B62C: nop
    
            goto L_8017B63C;
    }
    // 0x8017B62C: nop

    // 0x8017B630: lbu         $t2, 0x2E($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X2E);
    // 0x8017B634: addiu       $t5, $t2, 0x1
    ctx->r13 = ADD32(ctx->r10, 0X1);
    // 0x8017B638: sb          $t5, 0x2E($sp)
    MEM_B(0X2E, ctx->r29) = ctx->r13;
L_8017B63C:
    // 0x8017B63C: lbu         $t6, 0x2F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X2F);
    // 0x8017B640: addiu       $t3, $t6, 0x1
    ctx->r11 = ADD32(ctx->r14, 0X1);
    // 0x8017B644: andi        $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 & 0XFF;
    // 0x8017B648: slti        $at, $t4, 0x4
    ctx->r1 = SIGNED(ctx->r12) < 0X4 ? 1 : 0;
    // 0x8017B64C: bne         $at, $zero, L_8017B558
    if (ctx->r1 != 0) {
        // 0x8017B650: sb          $t3, 0x2F($sp)
        MEM_B(0X2F, ctx->r29) = ctx->r11;
            goto L_8017B558;
    }
    // 0x8017B650: sb          $t3, 0x2F($sp)
    MEM_B(0X2F, ctx->r29) = ctx->r11;
    // 0x8017B654: lbu         $t7, 0x2E($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X2E);
    // 0x8017B658: bne         $t7, $zero, L_8017BB80
    if (ctx->r15 != 0) {
        // 0x8017B65C: nop
    
            goto L_8017BB80;
    }
    // 0x8017B65C: nop

    // 0x8017B660: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017B664: addiu       $t8, $t8, -0x2E28
    ctx->r24 = ADD32(ctx->r24, -0X2E28);
    // 0x8017B668: lbu         $t9, 0xA($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0XA);
    // 0x8017B66C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017B670: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017B674: ori         $t0, $t9, 0x2
    ctx->r8 = ctx->r25 | 0X2;
    // 0x8017B678: sb          $t0, 0xA($t8)
    MEM_B(0XA, ctx->r24) = ctx->r8;
    // 0x8017B67C: lw          $t1, -0x2E48($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2E48);
    // 0x8017B680: addiu       $t2, $t2, -0x2E18
    ctx->r10 = ADD32(ctx->r10, -0X2E18);
    // 0x8017B684: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017B688: addiu       $t6, $t6, 0x3B00
    ctx->r14 = ADD32(ctx->r14, 0X3B00);
    // 0x8017B68C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8017B690: sw          $t1, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r9;
    // 0x8017B694: b           L_8017BB80
    // 0x8017B698: sb          $t5, 0x1E($t6)
    MEM_B(0X1E, ctx->r14) = ctx->r13;
        goto L_8017BB80;
    // 0x8017B698: sb          $t5, 0x1E($t6)
    MEM_B(0X1E, ctx->r14) = ctx->r13;
L_8017B69C:
    // 0x8017B69C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017B6A0: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x8017B6A4: lwc1        $f10, 0x7C($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X7C);
    // 0x8017B6A8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8017B6AC: nop

    // 0x8017B6B0: c.eq.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl == ctx->f16.fl;
    // 0x8017B6B4: nop

    // 0x8017B6B8: bc1f        L_8017B7F0
    if (!c1cs) {
        // 0x8017B6BC: nop
    
            goto L_8017B7F0;
    }
    // 0x8017B6BC: nop

    // 0x8017B6C0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017B6C4: addiu       $t4, $t4, -0x41E0
    ctx->r12 = ADD32(ctx->r12, -0X41E0);
    // 0x8017B6C8: lhu         $t7, 0x2($t4)
    ctx->r15 = MEM_HU(ctx->r12, 0X2);
    // 0x8017B6CC: andi        $t9, $t7, 0xB000
    ctx->r25 = ctx->r15 & 0XB000;
    // 0x8017B6D0: beq         $t9, $zero, L_8017B6F8
    if (ctx->r25 == 0) {
        // 0x8017B6D4: nop
    
            goto L_8017B6F8;
    }
    // 0x8017B6D4: nop

    // 0x8017B6D8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017B6DC: addiu       $t8, $t8, 0x3B00
    ctx->r24 = ADD32(ctx->r24, 0X3B00);
    // 0x8017B6E0: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8017B6E4: sb          $t0, 0x1E($t8)
    MEM_B(0X1E, ctx->r24) = ctx->r8;
    // 0x8017B6E8: jal         0x800C8544
    // 0x8017B6EC: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    func_800C8544(rdram, ctx);
        goto after_2;
    // 0x8017B6EC: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    after_2:
    // 0x8017B6F0: b           L_8017BB80
    // 0x8017B6F4: nop

        goto L_8017BB80;
    // 0x8017B6F4: nop

L_8017B6F8:
    // 0x8017B6F8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017B6FC: addiu       $t1, $t1, -0x41E0
    ctx->r9 = ADD32(ctx->r9, -0X41E0);
    // 0x8017B700: lhu         $t2, 0x2($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X2);
    // 0x8017B704: andi        $t5, $t2, 0x4000
    ctx->r13 = ctx->r10 & 0X4000;
    // 0x8017B708: beq         $t5, $zero, L_8017B738
    if (ctx->r13 == 0) {
        // 0x8017B70C: nop
    
            goto L_8017B738;
    }
    // 0x8017B70C: nop

    // 0x8017B710: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017B714: lw          $t6, -0x2E4C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2E4C);
    // 0x8017B718: bne         $t6, $zero, L_8017B738
    if (ctx->r14 != 0) {
        // 0x8017B71C: nop
    
            goto L_8017B738;
    }
    // 0x8017B71C: nop

    // 0x8017B720: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x8017B724: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017B728: jal         0x800C32CC
    // 0x8017B72C: sw          $t3, -0x2E4C($at)
    MEM_W(-0X2E4C, ctx->r1) = ctx->r11;
    func_800C32CC(rdram, ctx);
        goto after_3;
    // 0x8017B72C: sw          $t3, -0x2E4C($at)
    MEM_W(-0X2E4C, ctx->r1) = ctx->r11;
    after_3:
    // 0x8017B730: b           L_8017BB80
    // 0x8017B734: nop

        goto L_8017BB80;
    // 0x8017B734: nop

L_8017B738:
    // 0x8017B738: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017B73C: addiu       $t4, $t4, -0x41E0
    ctx->r12 = ADD32(ctx->r12, -0X41E0);
    // 0x8017B740: lb          $t7, 0x6($t4)
    ctx->r15 = MEM_B(ctx->r12, 0X6);
    // 0x8017B744: slti        $at, $t7, 0xF
    ctx->r1 = SIGNED(ctx->r15) < 0XF ? 1 : 0;
    // 0x8017B748: beq         $at, $zero, L_8017B75C
    if (ctx->r1 == 0) {
        // 0x8017B74C: nop
    
            goto L_8017B75C;
    }
    // 0x8017B74C: nop

    // 0x8017B750: lhu         $t9, 0x0($t4)
    ctx->r25 = MEM_HU(ctx->r12, 0X0);
    // 0x8017B754: andi        $t0, $t9, 0x100
    ctx->r8 = ctx->r25 & 0X100;
    // 0x8017B758: beq         $t0, $zero, L_8017B794
    if (ctx->r8 == 0) {
        // 0x8017B75C: lui         $at, 0x4110
        ctx->r1 = S32(0X4110 << 16);
            goto L_8017B794;
    }
L_8017B75C:
    // 0x8017B75C: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x8017B760: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8017B764: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017B768: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x8017B76C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017B770: addiu       $t1, $t1, 0x3B80
    ctx->r9 = ADD32(ctx->r9, 0X3B80);
    // 0x8017B774: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017B778: swc1        $f18, 0x7C($t8)
    MEM_W(0X7C, ctx->r24) = ctx->f18.u32l;
    // 0x8017B77C: sh          $zero, 0x3C($t1)
    MEM_H(0X3C, ctx->r9) = 0;
    // 0x8017B780: addiu       $t2, $t2, -0x2E28
    ctx->r10 = ADD32(ctx->r10, -0X2E28);
    // 0x8017B784: lbu         $t5, 0xA($t2)
    ctx->r13 = MEM_BU(ctx->r10, 0XA);
    // 0x8017B788: xori        $t6, $t5, 0x2
    ctx->r14 = ctx->r13 ^ 0X2;
    // 0x8017B78C: b           L_8017BB80
    // 0x8017B790: sb          $t6, 0xA($t2)
    MEM_B(0XA, ctx->r10) = ctx->r14;
        goto L_8017BB80;
    // 0x8017B790: sb          $t6, 0xA($t2)
    MEM_B(0XA, ctx->r10) = ctx->r14;
L_8017B794:
    // 0x8017B794: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017B798: addiu       $t3, $t3, -0x41E0
    ctx->r11 = ADD32(ctx->r11, -0X41E0);
    // 0x8017B79C: lb          $t7, 0x6($t3)
    ctx->r15 = MEM_B(ctx->r11, 0X6);
    // 0x8017B7A0: slti        $at, $t7, -0xE
    ctx->r1 = SIGNED(ctx->r15) < -0XE ? 1 : 0;
    // 0x8017B7A4: bne         $at, $zero, L_8017B7B8
    if (ctx->r1 != 0) {
        // 0x8017B7A8: nop
    
            goto L_8017B7B8;
    }
    // 0x8017B7A8: nop

    // 0x8017B7AC: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x8017B7B0: andi        $t9, $t4, 0x200
    ctx->r25 = ctx->r12 & 0X200;
    // 0x8017B7B4: beq         $t9, $zero, L_8017BB80
    if (ctx->r25 == 0) {
        // 0x8017B7B8: lui         $at, 0xC110
        ctx->r1 = S32(0XC110 << 16);
            goto L_8017BB80;
    }
L_8017B7B8:
    // 0x8017B7B8: lui         $at, 0xC110
    ctx->r1 = S32(0XC110 << 16);
    // 0x8017B7BC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017B7C0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017B7C4: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x8017B7C8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017B7CC: addiu       $t8, $t8, 0x3B80
    ctx->r24 = ADD32(ctx->r24, 0X3B80);
    // 0x8017B7D0: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017B7D4: swc1        $f4, 0x7C($t0)
    MEM_W(0X7C, ctx->r8) = ctx->f4.u32l;
    // 0x8017B7D8: sh          $zero, 0x3C($t8)
    MEM_H(0X3C, ctx->r24) = 0;
    // 0x8017B7DC: addiu       $t1, $t1, -0x2E28
    ctx->r9 = ADD32(ctx->r9, -0X2E28);
    // 0x8017B7E0: lbu         $t5, 0xA($t1)
    ctx->r13 = MEM_BU(ctx->r9, 0XA);
    // 0x8017B7E4: xori        $t6, $t5, 0x2
    ctx->r14 = ctx->r13 ^ 0X2;
    // 0x8017B7E8: b           L_8017BB80
    // 0x8017B7EC: sb          $t6, 0xA($t1)
    MEM_B(0XA, ctx->r9) = ctx->r14;
        goto L_8017BB80;
    // 0x8017B7EC: sb          $t6, 0xA($t1)
    MEM_B(0XA, ctx->r9) = ctx->r14;
L_8017B7F0:
    // 0x8017B7F0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017B7F4: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x8017B7F8: lwc1        $f6, 0x78($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X78);
    // 0x8017B7FC: lwc1        $f8, 0x7C($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X7C);
    // 0x8017B800: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017B804: addiu       $t7, $t7, 0x3B80
    ctx->r15 = ADD32(ctx->r15, 0X3B80);
    // 0x8017B808: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8017B80C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017B810: addiu       $t9, $t9, 0x3B80
    ctx->r25 = ADD32(ctx->r25, 0X3B80);
    // 0x8017B814: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8017B818: swc1        $f10, 0x78($t2)
    MEM_W(0X78, ctx->r10) = ctx->f10.u32l;
    // 0x8017B81C: lhu         $t3, 0x3C($t7)
    ctx->r11 = MEM_HU(ctx->r15, 0X3C);
    // 0x8017B820: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8017B824: sh          $t4, 0x3C($t7)
    MEM_H(0X3C, ctx->r15) = ctx->r12;
    // 0x8017B828: lhu         $t0, 0x3C($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X3C);
    // 0x8017B82C: bne         $t0, $at, L_8017BB80
    if (ctx->r8 != ctx->r1) {
        // 0x8017B830: nop
    
            goto L_8017BB80;
    }
    // 0x8017B830: nop

    // 0x8017B834: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017B838: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x8017B83C: lwc1        $f16, 0x7C($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X7C);
    // 0x8017B840: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8017B844: nop

    // 0x8017B848: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x8017B84C: nop

    // 0x8017B850: bc1f        L_8017B874
    if (!c1cs) {
        // 0x8017B854: nop
    
            goto L_8017B874;
    }
    // 0x8017B854: nop

    // 0x8017B858: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017B85C: lw          $t5, -0x2E48($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2E48);
    // 0x8017B860: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017B864: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x8017B868: andi        $t1, $t6, 0x3
    ctx->r9 = ctx->r14 & 0X3;
    // 0x8017B86C: b           L_8017B88C
    // 0x8017B870: sw          $t1, -0x2E48($at)
    MEM_W(-0X2E48, ctx->r1) = ctx->r9;
        goto L_8017B88C;
    // 0x8017B870: sw          $t1, -0x2E48($at)
    MEM_W(-0X2E48, ctx->r1) = ctx->r9;
L_8017B874:
    // 0x8017B874: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017B878: lw          $t2, -0x2E48($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2E48);
    // 0x8017B87C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017B880: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8017B884: andi        $t4, $t3, 0x3
    ctx->r12 = ctx->r11 & 0X3;
    // 0x8017B888: sw          $t4, -0x2E48($at)
    MEM_W(-0X2E48, ctx->r1) = ctx->r12;
L_8017B88C:
    // 0x8017B88C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017B890: addiu       $t7, $t7, -0x2E28
    ctx->r15 = ADD32(ctx->r15, -0X2E28);
    // 0x8017B894: lbu         $t9, 0xA($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0XA);
    // 0x8017B898: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017B89C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017B8A0: ori         $t0, $t9, 0x2
    ctx->r8 = ctx->r25 | 0X2;
    // 0x8017B8A4: sb          $t0, 0xA($t7)
    MEM_B(0XA, ctx->r15) = ctx->r8;
    // 0x8017B8A8: lw          $t8, -0x2E48($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2E48);
    // 0x8017B8AC: addiu       $t5, $t5, -0x2E18
    ctx->r13 = ADD32(ctx->r13, -0X2E18);
    // 0x8017B8B0: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    // 0x8017B8B4: jal         0x800C8544
    // 0x8017B8B8: sw          $t8, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r24;
    func_800C8544(rdram, ctx);
        goto after_4;
    // 0x8017B8B8: sw          $t8, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r24;
    after_4:
    // 0x8017B8BC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017B8C0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017B8C4: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x8017B8C8: b           L_8017BB80
    // 0x8017B8CC: swc1        $f4, 0x7C($t6)
    MEM_W(0X7C, ctx->r14) = ctx->f4.u32l;
        goto L_8017BB80;
    // 0x8017B8CC: swc1        $f4, 0x7C($t6)
    MEM_W(0X7C, ctx->r14) = ctx->f4.u32l;
L_8017B8D0:
    // 0x8017B8D0: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017B8D4: addiu       $t1, $t1, 0x3B80
    ctx->r9 = ADD32(ctx->r9, 0X3B80);
    // 0x8017B8D8: lhu         $t2, 0x14($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X14);
    // 0x8017B8DC: beq         $t2, $zero, L_8017B964
    if (ctx->r10 == 0) {
        // 0x8017B8E0: addiu       $at, $zero, 0x10
        ctx->r1 = ADD32(0, 0X10);
            goto L_8017B964;
    }
    // 0x8017B8E0: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x8017B8E4: beq         $t2, $at, L_8017B964
    if (ctx->r10 == ctx->r1) {
        // 0x8017B8E8: nop
    
            goto L_8017B964;
    }
    // 0x8017B8E8: nop

    // 0x8017B8EC: sb          $zero, 0x2F($sp)
    MEM_B(0X2F, ctx->r29) = 0;
L_8017B8F0:
    // 0x8017B8F0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017B8F4: lw          $t4, -0x2E48($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2E48);
    // 0x8017B8F8: lbu         $t3, 0x2F($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X2F);
    // 0x8017B8FC: bne         $t3, $t4, L_8017B924
    if (ctx->r11 != ctx->r12) {
        // 0x8017B900: nop
    
            goto L_8017B924;
    }
    // 0x8017B900: nop

    // 0x8017B904: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017B908: addiu       $t0, $t0, 0x3B80
    ctx->r8 = ADD32(ctx->r8, 0X3B80);
    // 0x8017B90C: sll         $t9, $t3, 1
    ctx->r25 = S32(ctx->r11 << 1);
    // 0x8017B910: addu        $t7, $t9, $t0
    ctx->r15 = ADD32(ctx->r25, ctx->r8);
    // 0x8017B914: lhu         $t8, 0x14($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X14);
    // 0x8017B918: addiu       $t5, $t8, 0x1
    ctx->r13 = ADD32(ctx->r24, 0X1);
    // 0x8017B91C: b           L_8017B944
    // 0x8017B920: sh          $t5, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r13;
        goto L_8017B944;
    // 0x8017B920: sh          $t5, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r13;
L_8017B924:
    // 0x8017B924: lbu         $t6, 0x2F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X2F);
    // 0x8017B928: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017B92C: addiu       $t2, $t2, 0x3B80
    ctx->r10 = ADD32(ctx->r10, 0X3B80);
    // 0x8017B930: sll         $t1, $t6, 1
    ctx->r9 = S32(ctx->r14 << 1);
    // 0x8017B934: addu        $t4, $t1, $t2
    ctx->r12 = ADD32(ctx->r9, ctx->r10);
    // 0x8017B938: lhu         $t3, 0x14($t4)
    ctx->r11 = MEM_HU(ctx->r12, 0X14);
    // 0x8017B93C: addiu       $t9, $t3, -0x1
    ctx->r25 = ADD32(ctx->r11, -0X1);
    // 0x8017B940: sh          $t9, 0x14($t4)
    MEM_H(0X14, ctx->r12) = ctx->r25;
L_8017B944:
    // 0x8017B944: lbu         $t0, 0x2F($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X2F);
    // 0x8017B948: addiu       $t8, $t0, 0x1
    ctx->r24 = ADD32(ctx->r8, 0X1);
    // 0x8017B94C: andi        $t5, $t8, 0xFF
    ctx->r13 = ctx->r24 & 0XFF;
    // 0x8017B950: slti        $at, $t5, 0x4
    ctx->r1 = SIGNED(ctx->r13) < 0X4 ? 1 : 0;
    // 0x8017B954: bne         $at, $zero, L_8017B8F0
    if (ctx->r1 != 0) {
        // 0x8017B958: sb          $t8, 0x2F($sp)
        MEM_B(0X2F, ctx->r29) = ctx->r24;
            goto L_8017B8F0;
    }
    // 0x8017B958: sb          $t8, 0x2F($sp)
    MEM_B(0X2F, ctx->r29) = ctx->r24;
    // 0x8017B95C: b           L_8017BB80
    // 0x8017B960: nop

        goto L_8017BB80;
    // 0x8017B960: nop

L_8017B964:
    // 0x8017B964: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8017B968: lw          $s0, -0x2E48($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X2E48);
    // 0x8017B96C: beq         $s0, $zero, L_8017B994
    if (ctx->r16 == 0) {
        // 0x8017B970: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8017B994;
    }
    // 0x8017B970: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8017B974: beq         $s0, $at, L_8017B9F0
    if (ctx->r16 == ctx->r1) {
        // 0x8017B978: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8017B9F0;
    }
    // 0x8017B978: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8017B97C: beq         $s0, $at, L_8017BAA4
    if (ctx->r16 == ctx->r1) {
        // 0x8017B980: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8017BAA4;
    }
    // 0x8017B980: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8017B984: beq         $s0, $at, L_8017BB5C
    if (ctx->r16 == ctx->r1) {
        // 0x8017B988: nop
    
            goto L_8017BB5C;
    }
    // 0x8017B988: nop

    // 0x8017B98C: b           L_8017BB78
    // 0x8017B990: nop

        goto L_8017BB78;
    // 0x8017B990: nop

L_8017B994:
    // 0x8017B994: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8017B998: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017B99C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017B9A0: sw          $t7, -0x2E3C($at)
    MEM_W(-0X2E3C, ctx->r1) = ctx->r15;
    // 0x8017B9A4: addiu       $t1, $t1, 0x3B00
    ctx->r9 = ADD32(ctx->r9, 0X3B00);
    // 0x8017B9A8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8017B9AC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017B9B0: sb          $t6, 0x14($t1)
    MEM_B(0X14, ctx->r9) = ctx->r14;
    // 0x8017B9B4: addiu       $t2, $t2, 0x3B80
    ctx->r10 = ADD32(ctx->r10, 0X3B80);
    // 0x8017B9B8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017B9BC: addiu       $t3, $t3, 0x3B80
    ctx->r11 = ADD32(ctx->r11, 0X3B80);
    // 0x8017B9C0: sh          $zero, 0x52($t2)
    MEM_H(0X52, ctx->r10) = 0;
    // 0x8017B9C4: lhu         $s1, 0x52($t3)
    ctx->r17 = MEM_HU(ctx->r11, 0X52);
    // 0x8017B9C8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017B9CC: addiu       $t9, $t9, 0x3B00
    ctx->r25 = ADD32(ctx->r25, 0X3B00);
    // 0x8017B9D0: sh          $s1, 0x50($t3)
    MEM_H(0X50, ctx->r11) = ctx->r17;
    // 0x8017B9D4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017B9D8: sb          $s1, 0x28($t9)
    MEM_B(0X28, ctx->r25) = ctx->r17;
    // 0x8017B9DC: lwc1        $f6, -0xFA8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0XFA8);
    // 0x8017B9E0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017B9E4: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x8017B9E8: b           L_8017BB78
    // 0x8017B9EC: swc1        $f6, 0xA0($t4)
    MEM_W(0XA0, ctx->r12) = ctx->f6.u32l;
        goto L_8017BB78;
    // 0x8017B9EC: swc1        $f6, 0xA0($t4)
    MEM_W(0XA0, ctx->r12) = ctx->f6.u32l;
L_8017B9F0:
    // 0x8017B9F0: lui         $t0, 0x8011
    ctx->r8 = S32(0X8011 << 16);
    // 0x8017B9F4: lhu         $t0, -0x4530($t0)
    ctx->r8 = MEM_HU(ctx->r8, -0X4530);
    // 0x8017B9F8: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8017B9FC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8017BA00: andi        $t8, $t0, 0xF
    ctx->r24 = ctx->r8 & 0XF;
    // 0x8017BA04: addu        $t5, $t5, $t8
    ctx->r13 = ADD32(ctx->r13, ctx->r24);
    // 0x8017BA08: lbu         $t5, -0x1128($t5)
    ctx->r13 = MEM_BU(ctx->r13, -0X1128);
    // 0x8017BA0C: bne         $t5, $at, L_8017BA34
    if (ctx->r13 != ctx->r1) {
        // 0x8017BA10: nop
    
            goto L_8017BA34;
    }
    // 0x8017BA10: nop

    // 0x8017BA14: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017BA18: addiu       $t7, $t7, 0x3B00
    ctx->r15 = ADD32(ctx->r15, 0X3B00);
    // 0x8017BA1C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017BA20: addiu       $t6, $t6, 0x3B00
    ctx->r14 = ADD32(ctx->r14, 0X3B00);
    // 0x8017BA24: sb          $zero, 0x1E($t7)
    MEM_B(0X1E, ctx->r15) = 0;
    // 0x8017BA28: lbu         $t1, 0x1E($t6)
    ctx->r9 = MEM_BU(ctx->r14, 0X1E);
    // 0x8017BA2C: b           L_8017BB78
    // 0x8017BA30: sb          $t1, 0x14($t6)
    MEM_B(0X14, ctx->r14) = ctx->r9;
        goto L_8017BB78;
    // 0x8017BA30: sb          $t1, 0x14($t6)
    MEM_B(0X14, ctx->r14) = ctx->r9;
L_8017BA34:
    // 0x8017BA34: lui         $t2, 0x8011
    ctx->r10 = S32(0X8011 << 16);
    // 0x8017BA38: lhu         $t2, -0x4530($t2)
    ctx->r10 = MEM_HU(ctx->r10, -0X4530);
    // 0x8017BA3C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8017BA40: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017BA44: andi        $t3, $t2, 0xF
    ctx->r11 = ctx->r10 & 0XF;
    // 0x8017BA48: addu        $t9, $t9, $t3
    ctx->r25 = ADD32(ctx->r25, ctx->r11);
    // 0x8017BA4C: lbu         $t9, -0x1128($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X1128);
    // 0x8017BA50: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017BA54: addiu       $t0, $t0, 0x3B00
    ctx->r8 = ADD32(ctx->r8, 0X3B00);
    // 0x8017BA58: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8017BA5C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017BA60: sw          $t9, -0x2E3C($at)
    MEM_W(-0X2E3C, ctx->r1) = ctx->r25;
    // 0x8017BA64: sb          $t4, 0x14($t0)
    MEM_B(0X14, ctx->r8) = ctx->r12;
    // 0x8017BA68: addiu       $t8, $t8, 0x3B80
    ctx->r24 = ADD32(ctx->r24, 0X3B80);
    // 0x8017BA6C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017BA70: addiu       $t5, $t5, 0x3B80
    ctx->r13 = ADD32(ctx->r13, 0X3B80);
    // 0x8017BA74: sh          $zero, 0x52($t8)
    MEM_H(0X52, ctx->r24) = 0;
    // 0x8017BA78: lhu         $s1, 0x52($t5)
    ctx->r17 = MEM_HU(ctx->r13, 0X52);
    // 0x8017BA7C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017BA80: addiu       $t7, $t7, 0x3B00
    ctx->r15 = ADD32(ctx->r15, 0X3B00);
    // 0x8017BA84: sh          $s1, 0x50($t5)
    MEM_H(0X50, ctx->r13) = ctx->r17;
    // 0x8017BA88: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017BA8C: sb          $s1, 0x28($t7)
    MEM_B(0X28, ctx->r15) = ctx->r17;
    // 0x8017BA90: lwc1        $f8, -0xFA4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0XFA4);
    // 0x8017BA94: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017BA98: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x8017BA9C: b           L_8017BB78
    // 0x8017BAA0: swc1        $f8, 0xA0($t1)
    MEM_W(0XA0, ctx->r9) = ctx->f8.u32l;
        goto L_8017BB78;
    // 0x8017BAA0: swc1        $f8, 0xA0($t1)
    MEM_W(0XA0, ctx->r9) = ctx->f8.u32l;
L_8017BAA4:
    // 0x8017BAA4: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x8017BAA8: lhu         $t6, -0x4530($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X4530);
    // 0x8017BAAC: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8017BAB0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8017BAB4: andi        $t2, $t6, 0xF
    ctx->r10 = ctx->r14 & 0XF;
    // 0x8017BAB8: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8017BABC: lbu         $t3, -0x1128($t3)
    ctx->r11 = MEM_BU(ctx->r11, -0X1128);
    // 0x8017BAC0: bne         $t3, $at, L_8017BAE8
    if (ctx->r11 != ctx->r1) {
        // 0x8017BAC4: nop
    
            goto L_8017BAE8;
    }
    // 0x8017BAC4: nop

    // 0x8017BAC8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017BACC: addiu       $t9, $t9, 0x3B00
    ctx->r25 = ADD32(ctx->r25, 0X3B00);
    // 0x8017BAD0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017BAD4: addiu       $t4, $t4, 0x3B00
    ctx->r12 = ADD32(ctx->r12, 0X3B00);
    // 0x8017BAD8: sb          $zero, 0x1E($t9)
    MEM_B(0X1E, ctx->r25) = 0;
    // 0x8017BADC: lbu         $t0, 0x1E($t4)
    ctx->r8 = MEM_BU(ctx->r12, 0X1E);
    // 0x8017BAE0: b           L_8017BB78
    // 0x8017BAE4: sb          $t0, 0x14($t4)
    MEM_B(0X14, ctx->r12) = ctx->r8;
        goto L_8017BB78;
    // 0x8017BAE4: sb          $t0, 0x14($t4)
    MEM_B(0X14, ctx->r12) = ctx->r8;
L_8017BAE8:
    // 0x8017BAE8: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x8017BAEC: lhu         $t8, -0x4530($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X4530);
    // 0x8017BAF0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8017BAF4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017BAF8: andi        $t5, $t8, 0xF
    ctx->r13 = ctx->r24 & 0XF;
    // 0x8017BAFC: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x8017BB00: lbu         $t7, -0x1128($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X1128);
    // 0x8017BB04: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017BB08: addiu       $t2, $t2, 0x3B00
    ctx->r10 = ADD32(ctx->r10, 0X3B00);
    // 0x8017BB0C: andi        $t1, $t7, 0x6
    ctx->r9 = ctx->r15 & 0X6;
    // 0x8017BB10: sw          $t1, -0x2E3C($at)
    MEM_W(-0X2E3C, ctx->r1) = ctx->r9;
    // 0x8017BB14: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8017BB18: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017BB1C: sb          $t6, 0x14($t2)
    MEM_B(0X14, ctx->r10) = ctx->r14;
    // 0x8017BB20: addiu       $t3, $t3, 0x3B80
    ctx->r11 = ADD32(ctx->r11, 0X3B80);
    // 0x8017BB24: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017BB28: addiu       $t9, $t9, 0x3B80
    ctx->r25 = ADD32(ctx->r25, 0X3B80);
    // 0x8017BB2C: sh          $zero, 0x52($t3)
    MEM_H(0X52, ctx->r11) = 0;
    // 0x8017BB30: lhu         $s1, 0x52($t9)
    ctx->r17 = MEM_HU(ctx->r25, 0X52);
    // 0x8017BB34: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017BB38: addiu       $t0, $t0, 0x3B00
    ctx->r8 = ADD32(ctx->r8, 0X3B00);
    // 0x8017BB3C: sh          $s1, 0x50($t9)
    MEM_H(0X50, ctx->r25) = ctx->r17;
    // 0x8017BB40: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017BB44: sb          $s1, 0x28($t0)
    MEM_B(0X28, ctx->r8) = ctx->r17;
    // 0x8017BB48: lwc1        $f10, -0xFA0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0XFA0);
    // 0x8017BB4C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017BB50: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x8017BB54: b           L_8017BB78
    // 0x8017BB58: swc1        $f10, 0xA0($t4)
    MEM_W(0XA0, ctx->r12) = ctx->f10.u32l;
        goto L_8017BB78;
    // 0x8017BB58: swc1        $f10, 0xA0($t4)
    MEM_W(0XA0, ctx->r12) = ctx->f10.u32l;
L_8017BB5C:
    // 0x8017BB5C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8017BB60: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017BB64: sw          $t8, -0x2E3C($at)
    MEM_W(-0X2E3C, ctx->r1) = ctx->r24;
    // 0x8017BB68: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017BB6C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8017BB70: jal         0x800C32CC
    // 0x8017BB74: sw          $t5, -0x2E4C($at)
    MEM_W(-0X2E4C, ctx->r1) = ctx->r13;
    func_800C32CC(rdram, ctx);
        goto after_5;
    // 0x8017BB74: sw          $t5, -0x2E4C($at)
    MEM_W(-0X2E4C, ctx->r1) = ctx->r13;
    after_5:
L_8017BB78:
    // 0x8017BB78: jal         0x800C8544
    // 0x8017BB7C: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    func_800C8544(rdram, ctx);
        goto after_6;
    // 0x8017BB7C: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_6:
L_8017BB80:
    // 0x8017BB80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8017BB84: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8017BB88: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8017BB8C: jr          $ra
    // 0x8017BB90: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8017BB90: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8017BB94_0EF7C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017BB94: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017BB98: lw          $t6, -0x2E4C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2E4C);
    // 0x8017BB9C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8017BBA0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8017BBA4: beq         $t6, $zero, L_8017BC04
    if (ctx->r14 == 0) {
        // 0x8017BBA8: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_8017BC04;
    }
    // 0x8017BBA8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8017BBAC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017BBB0: addiu       $t7, $t7, -0x4198
    ctx->r15 = ADD32(ctx->r15, -0X4198);
    // 0x8017BBB4: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x8017BBB8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017BBBC: lwc1        $f4, 0x0($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X0);
    // 0x8017BBC0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017BBC4: addiu       $t8, $t8, -0x4198
    ctx->r24 = ADD32(ctx->r24, -0X4198);
    // 0x8017BBC8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8017BBCC: lui         $at, 0xC20C
    ctx->r1 = S32(0XC20C << 16);
    // 0x8017BBD0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8017BBD4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017BBD8: swc1        $f8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f8.u32l;
    // 0x8017BBDC: lwc1        $f10, 0x8($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X8);
    // 0x8017BBE0: addiu       $t9, $t9, -0x4198
    ctx->r25 = ADD32(ctx->r25, -0X4198);
    // 0x8017BBE4: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x8017BBE8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8017BBEC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017BBF0: swc1        $f18, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f18.u32l;
    // 0x8017BBF4: lwc1        $f4, 0x14($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X14);
    // 0x8017BBF8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8017BBFC: b           L_8017C010
    // 0x8017BC00: swc1        $f8, 0x14($t9)
    MEM_W(0X14, ctx->r25) = ctx->f8.u32l;
        goto L_8017C010;
    // 0x8017BC00: swc1        $f8, 0x14($t9)
    MEM_W(0X14, ctx->r25) = ctx->f8.u32l;
L_8017BC04:
    // 0x8017BC04: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017BC08: addiu       $t0, $t0, 0x3B00
    ctx->r8 = ADD32(ctx->r8, 0X3B00);
    // 0x8017BC0C: lbu         $s0, 0x28($t0)
    ctx->r16 = MEM_BU(ctx->r8, 0X28);
    // 0x8017BC10: beq         $s0, $zero, L_8017BC30
    if (ctx->r16 == 0) {
        // 0x8017BC14: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8017BC30;
    }
    // 0x8017BC14: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8017BC18: beq         $s0, $at, L_8017BCBC
    if (ctx->r16 == ctx->r1) {
        // 0x8017BC1C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8017BCBC;
    }
    // 0x8017BC1C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8017BC20: beq         $s0, $at, L_8017BF98
    if (ctx->r16 == ctx->r1) {
        // 0x8017BC24: nop
    
            goto L_8017BF98;
    }
    // 0x8017BC24: nop

    // 0x8017BC28: b           L_8017C010
    // 0x8017BC2C: nop

        goto L_8017C010;
    // 0x8017BC2C: nop

L_8017BC30:
    // 0x8017BC30: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017BC34: addiu       $t1, $t1, 0x3B00
    ctx->r9 = ADD32(ctx->r9, 0X3B00);
    // 0x8017BC38: lbu         $t2, 0x29($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X29);
    // 0x8017BC3C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8017BC40: beq         $t2, $at, L_8017BC54
    if (ctx->r10 == ctx->r1) {
        // 0x8017BC44: nop
    
            goto L_8017BC54;
    }
    // 0x8017BC44: nop

    // 0x8017BC48: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8017BC4C: b           L_8017C010
    // 0x8017BC50: sb          $t3, 0x29($t1)
    MEM_B(0X29, ctx->r9) = ctx->r11;
        goto L_8017C010;
    // 0x8017BC50: sb          $t3, 0x29($t1)
    MEM_B(0X29, ctx->r9) = ctx->r11;
L_8017BC54:
    // 0x8017BC54: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017BC58: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x8017BC5C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017BC60: lwc1        $f16, -0xF9C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0XF9C);
    // 0x8017BC64: lwc1        $f10, 0xA0($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0XA0);
    // 0x8017BC68: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x8017BC6C: nop

    // 0x8017BC70: bc1f        L_8017BC88
    if (!c1cs) {
        // 0x8017BC74: lui         $at, 0x8018
        ctx->r1 = S32(0X8018 << 16);
            goto L_8017BC88;
    }
    // 0x8017BC74: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017BC78: lwc1        $f18, -0xF98($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0XF98);
    // 0x8017BC7C: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8017BC80: b           L_8017C010
    // 0x8017BC84: swc1        $f4, 0xA0($t4)
    MEM_W(0XA0, ctx->r12) = ctx->f4.u32l;
        goto L_8017C010;
    // 0x8017BC84: swc1        $f4, 0xA0($t4)
    MEM_W(0XA0, ctx->r12) = ctx->f4.u32l;
L_8017BC88:
    // 0x8017BC88: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017BC8C: lwc1        $f6, -0xF94($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0XF94);
    // 0x8017BC90: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017BC94: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x8017BC98: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017BC9C: addiu       $t7, $t7, 0x3B00
    ctx->r15 = ADD32(ctx->r15, 0X3B00);
    // 0x8017BCA0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8017BCA4: swc1        $f6, 0xA0($t5)
    MEM_W(0XA0, ctx->r13) = ctx->f6.u32l;
    // 0x8017BCA8: sb          $t6, 0x28($t7)
    MEM_B(0X28, ctx->r15) = ctx->r14;
    // 0x8017BCAC: jal         0x800C8544
    // 0x8017BCB0: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    func_800C8544(rdram, ctx);
        goto after_0;
    // 0x8017BCB0: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_0:
    // 0x8017BCB4: b           L_8017C010
    // 0x8017BCB8: nop

        goto L_8017C010;
    // 0x8017BCB8: nop

L_8017BCBC:
    // 0x8017BCBC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017BCC0: addiu       $t8, $t8, 0x3B00
    ctx->r24 = ADD32(ctx->r24, 0X3B00);
    // 0x8017BCC4: lbu         $t9, 0x2A($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X2A);
    // 0x8017BCC8: bne         $t9, $zero, L_8017BDCC
    if (ctx->r25 != 0) {
        // 0x8017BCCC: nop
    
            goto L_8017BDCC;
    }
    // 0x8017BCCC: nop

    // 0x8017BCD0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017BCD4: lw          $t0, -0x2E4C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2E4C);
    // 0x8017BCD8: bne         $t0, $zero, L_8017BDCC
    if (ctx->r8 != 0) {
        // 0x8017BCDC: nop
    
            goto L_8017BDCC;
    }
    // 0x8017BCDC: nop

    // 0x8017BCE0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017BCE4: addiu       $t2, $t2, -0x41E0
    ctx->r10 = ADD32(ctx->r10, -0X41E0);
    // 0x8017BCE8: lhu         $t3, 0x2($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X2);
    // 0x8017BCEC: andi        $t1, $t3, 0xB000
    ctx->r9 = ctx->r11 & 0XB000;
    // 0x8017BCF0: beq         $t1, $zero, L_8017BD10
    if (ctx->r9 == 0) {
        // 0x8017BCF4: nop
    
            goto L_8017BD10;
    }
    // 0x8017BCF4: nop

    // 0x8017BCF8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8017BCFC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017BD00: jal         0x800C32CC
    // 0x8017BD04: sw          $t4, -0x2E4C($at)
    MEM_W(-0X2E4C, ctx->r1) = ctx->r12;
    func_800C32CC(rdram, ctx);
        goto after_1;
    // 0x8017BD04: sw          $t4, -0x2E4C($at)
    MEM_W(-0X2E4C, ctx->r1) = ctx->r12;
    after_1:
    // 0x8017BD08: b           L_8017C010
    // 0x8017BD0C: nop

        goto L_8017C010;
    // 0x8017BD0C: nop

L_8017BD10:
    // 0x8017BD10: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017BD14: addiu       $t5, $t5, -0x41E0
    ctx->r13 = ADD32(ctx->r13, -0X41E0);
    // 0x8017BD18: lhu         $t6, 0x2($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X2);
    // 0x8017BD1C: andi        $t7, $t6, 0x4000
    ctx->r15 = ctx->r14 & 0X4000;
    // 0x8017BD20: beq         $t7, $zero, L_8017BD44
    if (ctx->r15 == 0) {
        // 0x8017BD24: nop
    
            goto L_8017BD44;
    }
    // 0x8017BD24: nop

    // 0x8017BD28: jal         0x800C8544
    // 0x8017BD2C: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    func_800C8544(rdram, ctx);
        goto after_2;
    // 0x8017BD2C: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    after_2:
    // 0x8017BD30: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017BD34: addiu       $t9, $t9, 0x3B00
    ctx->r25 = ADD32(ctx->r25, 0X3B00);
    // 0x8017BD38: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8017BD3C: b           L_8017C010
    // 0x8017BD40: sb          $t8, 0x28($t9)
    MEM_B(0X28, ctx->r25) = ctx->r24;
        goto L_8017C010;
    // 0x8017BD40: sb          $t8, 0x28($t9)
    MEM_B(0X28, ctx->r25) = ctx->r24;
L_8017BD44:
    // 0x8017BD44: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017BD48: addiu       $t0, $t0, -0x41E0
    ctx->r8 = ADD32(ctx->r8, -0X41E0);
    // 0x8017BD4C: lb          $t2, 0x6($t0)
    ctx->r10 = MEM_B(ctx->r8, 0X6);
    // 0x8017BD50: slti        $at, $t2, 0xF
    ctx->r1 = SIGNED(ctx->r10) < 0XF ? 1 : 0;
    // 0x8017BD54: beq         $at, $zero, L_8017BD6C
    if (ctx->r1 == 0) {
        // 0x8017BD58: nop
    
            goto L_8017BD6C;
    }
    // 0x8017BD58: nop

    // 0x8017BD5C: lhu         $t3, 0x0($t0)
    ctx->r11 = MEM_HU(ctx->r8, 0X0);
    // 0x8017BD60: andi        $t1, $t3, 0x100
    ctx->r9 = ctx->r11 & 0X100;
    // 0x8017BD64: beq         $t1, $zero, L_8017BD88
    if (ctx->r9 == 0) {
        // 0x8017BD68: nop
    
            goto L_8017BD88;
    }
    // 0x8017BD68: nop

L_8017BD6C:
    // 0x8017BD6C: jal         0x800C8544
    // 0x8017BD70: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    func_800C8544(rdram, ctx);
        goto after_3;
    // 0x8017BD70: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    after_3:
    // 0x8017BD74: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017BD78: addiu       $t5, $t5, 0x3B00
    ctx->r13 = ADD32(ctx->r13, 0X3B00);
    // 0x8017BD7C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8017BD80: b           L_8017C010
    // 0x8017BD84: sb          $t4, 0x2A($t5)
    MEM_B(0X2A, ctx->r13) = ctx->r12;
        goto L_8017C010;
    // 0x8017BD84: sb          $t4, 0x2A($t5)
    MEM_B(0X2A, ctx->r13) = ctx->r12;
L_8017BD88:
    // 0x8017BD88: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017BD8C: addiu       $t6, $t6, -0x41E0
    ctx->r14 = ADD32(ctx->r14, -0X41E0);
    // 0x8017BD90: lb          $t7, 0x6($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X6);
    // 0x8017BD94: slti        $at, $t7, -0xE
    ctx->r1 = SIGNED(ctx->r15) < -0XE ? 1 : 0;
    // 0x8017BD98: bne         $at, $zero, L_8017BDB0
    if (ctx->r1 != 0) {
        // 0x8017BD9C: nop
    
            goto L_8017BDB0;
    }
    // 0x8017BD9C: nop

    // 0x8017BDA0: lhu         $t8, 0x0($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X0);
    // 0x8017BDA4: andi        $t9, $t8, 0x200
    ctx->r25 = ctx->r24 & 0X200;
    // 0x8017BDA8: beq         $t9, $zero, L_8017C010
    if (ctx->r25 == 0) {
        // 0x8017BDAC: nop
    
            goto L_8017C010;
    }
    // 0x8017BDAC: nop

L_8017BDB0:
    // 0x8017BDB0: jal         0x800C8544
    // 0x8017BDB4: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    func_800C8544(rdram, ctx);
        goto after_4;
    // 0x8017BDB4: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    after_4:
    // 0x8017BDB8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017BDBC: addiu       $t0, $t0, 0x3B00
    ctx->r8 = ADD32(ctx->r8, 0X3B00);
    // 0x8017BDC0: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x8017BDC4: b           L_8017C010
    // 0x8017BDC8: sb          $t2, 0x2A($t0)
    MEM_B(0X2A, ctx->r8) = ctx->r10;
        goto L_8017C010;
    // 0x8017BDC8: sb          $t2, 0x2A($t0)
    MEM_B(0X2A, ctx->r8) = ctx->r10;
L_8017BDCC:
    // 0x8017BDCC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017BDD0: addiu       $t3, $t3, 0x3B00
    ctx->r11 = ADD32(ctx->r11, 0X3B00);
    // 0x8017BDD4: lbu         $s0, 0x2A($t3)
    ctx->r16 = MEM_BU(ctx->r11, 0X2A);
    // 0x8017BDD8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8017BDDC: beq         $s0, $at, L_8017BDFC
    if (ctx->r16 == ctx->r1) {
        // 0x8017BDE0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8017BDFC;
    }
    // 0x8017BDE0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8017BDE4: beq         $s0, $at, L_8017BE98
    if (ctx->r16 == ctx->r1) {
        // 0x8017BDE8: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8017BE98;
    }
    // 0x8017BDE8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8017BDEC: beq         $s0, $at, L_8017BF34
    if (ctx->r16 == ctx->r1) {
        // 0x8017BDF0: nop
    
            goto L_8017BF34;
    }
    // 0x8017BDF0: nop

    // 0x8017BDF4: b           L_8017C010
    // 0x8017BDF8: nop

        goto L_8017C010;
    // 0x8017BDF8: nop

L_8017BDFC:
    // 0x8017BDFC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017BE00: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x8017BE04: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017BE08: lwc1        $f16, -0xF90($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0XF90);
    // 0x8017BE0C: lwc1        $f8, 0xA0($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0XA0);
    // 0x8017BE10: c.lt.s      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.fl < ctx->f8.fl;
    // 0x8017BE14: nop

    // 0x8017BE18: bc1f        L_8017BE30
    if (!c1cs) {
        // 0x8017BE1C: lui         $at, 0x8018
        ctx->r1 = S32(0X8018 << 16);
            goto L_8017BE30;
    }
    // 0x8017BE1C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017BE20: lwc1        $f10, -0xF8C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0XF8C);
    // 0x8017BE24: sub.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8017BE28: b           L_8017C010
    // 0x8017BE2C: swc1        $f18, 0xA0($t1)
    MEM_W(0XA0, ctx->r9) = ctx->f18.u32l;
        goto L_8017C010;
    // 0x8017BE2C: swc1        $f18, 0xA0($t1)
    MEM_W(0XA0, ctx->r9) = ctx->f18.u32l;
L_8017BE30:
    // 0x8017BE30: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017BE34: lw          $t4, -0x2E40($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2E40);
    // 0x8017BE38: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017BE3C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017BE40: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8017BE44: sw          $t5, -0x2E40($at)
    MEM_W(-0X2E40, ctx->r1) = ctx->r13;
    // 0x8017BE48: addiu       $t7, $t7, -0x2E28
    ctx->r15 = ADD32(ctx->r15, -0X2E28);
    // 0x8017BE4C: lbu         $t6, 0xF($t7)
    ctx->r14 = MEM_BU(ctx->r15, 0XF);
    // 0x8017BE50: andi        $t8, $t6, 0x1
    ctx->r24 = ctx->r14 & 0X1;
    // 0x8017BE54: beq         $t8, $zero, L_8017BE6C
    if (ctx->r24 == 0) {
        // 0x8017BE58: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8017BE6C;
    }
    // 0x8017BE58: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8017BE5C: bne         $t5, $at, L_8017BE84
    if (ctx->r13 != ctx->r1) {
        // 0x8017BE60: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8017BE84;
    }
    // 0x8017BE60: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017BE64: b           L_8017BE84
    // 0x8017BE68: sw          $zero, -0x2E40($at)
    MEM_W(-0X2E40, ctx->r1) = 0;
        goto L_8017BE84;
    // 0x8017BE68: sw          $zero, -0x2E40($at)
    MEM_W(-0X2E40, ctx->r1) = 0;
L_8017BE6C:
    // 0x8017BE6C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017BE70: lw          $t9, -0x2E40($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2E40);
    // 0x8017BE74: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8017BE78: bne         $t9, $at, L_8017BE84
    if (ctx->r25 != ctx->r1) {
        // 0x8017BE7C: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8017BE84;
    }
    // 0x8017BE7C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017BE80: sw          $zero, -0x2E40($at)
    MEM_W(-0X2E40, ctx->r1) = 0;
L_8017BE84:
    // 0x8017BE84: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017BE88: addiu       $t0, $t0, 0x3B00
    ctx->r8 = ADD32(ctx->r8, 0X3B00);
    // 0x8017BE8C: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x8017BE90: b           L_8017C010
    // 0x8017BE94: sb          $t2, 0x2A($t0)
    MEM_B(0X2A, ctx->r8) = ctx->r10;
        goto L_8017C010;
    // 0x8017BE94: sb          $t2, 0x2A($t0)
    MEM_B(0X2A, ctx->r8) = ctx->r10;
L_8017BE98:
    // 0x8017BE98: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017BE9C: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x8017BEA0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017BEA4: lwc1        $f6, -0xF88($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0XF88);
    // 0x8017BEA8: lwc1        $f4, 0xA0($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0XA0);
    // 0x8017BEAC: c.lt.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl < ctx->f4.fl;
    // 0x8017BEB0: nop

    // 0x8017BEB4: bc1f        L_8017BECC
    if (!c1cs) {
        // 0x8017BEB8: lui         $at, 0x8018
        ctx->r1 = S32(0X8018 << 16);
            goto L_8017BECC;
    }
    // 0x8017BEB8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017BEBC: lwc1        $f16, -0xF84($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0XF84);
    // 0x8017BEC0: sub.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x8017BEC4: b           L_8017C010
    // 0x8017BEC8: swc1        $f8, 0xA0($t3)
    MEM_W(0XA0, ctx->r11) = ctx->f8.u32l;
        goto L_8017C010;
    // 0x8017BEC8: swc1        $f8, 0xA0($t3)
    MEM_W(0XA0, ctx->r11) = ctx->f8.u32l;
L_8017BECC:
    // 0x8017BECC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017BED0: lw          $t1, -0x2E40($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2E40);
    // 0x8017BED4: beq         $t1, $zero, L_8017BEEC
    if (ctx->r9 == 0) {
        // 0x8017BED8: nop
    
            goto L_8017BEEC;
    }
    // 0x8017BED8: nop

    // 0x8017BEDC: addiu       $t4, $t1, -0x1
    ctx->r12 = ADD32(ctx->r9, -0X1);
    // 0x8017BEE0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017BEE4: b           L_8017BF20
    // 0x8017BEE8: sw          $t4, -0x2E40($at)
    MEM_W(-0X2E40, ctx->r1) = ctx->r12;
        goto L_8017BF20;
    // 0x8017BEE8: sw          $t4, -0x2E40($at)
    MEM_W(-0X2E40, ctx->r1) = ctx->r12;
L_8017BEEC:
    // 0x8017BEEC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017BEF0: addiu       $t7, $t7, -0x2E28
    ctx->r15 = ADD32(ctx->r15, -0X2E28);
    // 0x8017BEF4: lbu         $t6, 0xF($t7)
    ctx->r14 = MEM_BU(ctx->r15, 0XF);
    // 0x8017BEF8: andi        $t8, $t6, 0x1
    ctx->r24 = ctx->r14 & 0X1;
    // 0x8017BEFC: beq         $t8, $zero, L_8017BF14
    if (ctx->r24 == 0) {
        // 0x8017BF00: nop
    
            goto L_8017BF14;
    }
    // 0x8017BF00: nop

    // 0x8017BF04: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x8017BF08: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017BF0C: b           L_8017BF20
    // 0x8017BF10: sw          $t5, -0x2E40($at)
    MEM_W(-0X2E40, ctx->r1) = ctx->r13;
        goto L_8017BF20;
    // 0x8017BF10: sw          $t5, -0x2E40($at)
    MEM_W(-0X2E40, ctx->r1) = ctx->r13;
L_8017BF14:
    // 0x8017BF14: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8017BF18: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017BF1C: sw          $t9, -0x2E40($at)
    MEM_W(-0X2E40, ctx->r1) = ctx->r25;
L_8017BF20:
    // 0x8017BF20: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017BF24: addiu       $t0, $t0, 0x3B00
    ctx->r8 = ADD32(ctx->r8, 0X3B00);
    // 0x8017BF28: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x8017BF2C: b           L_8017C010
    // 0x8017BF30: sb          $t2, 0x2A($t0)
    MEM_B(0X2A, ctx->r8) = ctx->r10;
        goto L_8017C010;
    // 0x8017BF30: sb          $t2, 0x2A($t0)
    MEM_B(0X2A, ctx->r8) = ctx->r10;
L_8017BF34:
    // 0x8017BF34: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017BF38: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x8017BF3C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017BF40: lwc1        $f18, -0xF80($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0XF80);
    // 0x8017BF44: lwc1        $f10, 0xA0($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0XA0);
    // 0x8017BF48: c.lt.s      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.fl < ctx->f18.fl;
    // 0x8017BF4C: nop

    // 0x8017BF50: bc1f        L_8017BF68
    if (!c1cs) {
        // 0x8017BF54: lui         $at, 0x8018
        ctx->r1 = S32(0X8018 << 16);
            goto L_8017BF68;
    }
    // 0x8017BF54: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017BF58: lwc1        $f6, -0xF7C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0XF7C);
    // 0x8017BF5C: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8017BF60: b           L_8017C010
    // 0x8017BF64: swc1        $f4, 0xA0($t3)
    MEM_W(0XA0, ctx->r11) = ctx->f4.u32l;
        goto L_8017C010;
    // 0x8017BF64: swc1        $f4, 0xA0($t3)
    MEM_W(0XA0, ctx->r11) = ctx->f4.u32l;
L_8017BF68:
    // 0x8017BF68: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017BF6C: lwc1        $f16, -0xF78($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0XF78);
    // 0x8017BF70: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017BF74: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x8017BF78: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017BF7C: addiu       $t4, $t4, 0x3B00
    ctx->r12 = ADD32(ctx->r12, 0X3B00);
    // 0x8017BF80: swc1        $f16, 0xA0($t1)
    MEM_W(0XA0, ctx->r9) = ctx->f16.u32l;
    // 0x8017BF84: sb          $zero, 0x2A($t4)
    MEM_B(0X2A, ctx->r12) = 0;
    // 0x8017BF88: jal         0x800C8544
    // 0x8017BF8C: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    func_800C8544(rdram, ctx);
        goto after_5;
    // 0x8017BF8C: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_5:
    // 0x8017BF90: b           L_8017C010
    // 0x8017BF94: nop

        goto L_8017C010;
    // 0x8017BF94: nop

L_8017BF98:
    // 0x8017BF98: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017BF9C: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x8017BFA0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017BFA4: lwc1        $f18, -0xF74($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0XF74);
    // 0x8017BFA8: lwc1        $f8, 0xA0($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0XA0);
    // 0x8017BFAC: c.lt.s      $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.fl < ctx->f8.fl;
    // 0x8017BFB0: nop

    // 0x8017BFB4: bc1f        L_8017BFCC
    if (!c1cs) {
        // 0x8017BFB8: lui         $at, 0x8018
        ctx->r1 = S32(0X8018 << 16);
            goto L_8017BFCC;
    }
    // 0x8017BFB8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017BFBC: lwc1        $f10, -0xF70($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0XF70);
    // 0x8017BFC0: sub.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8017BFC4: b           L_8017C010
    // 0x8017BFC8: swc1        $f6, 0xA0($t7)
    MEM_W(0XA0, ctx->r15) = ctx->f6.u32l;
        goto L_8017C010;
    // 0x8017BFC8: swc1        $f6, 0xA0($t7)
    MEM_W(0XA0, ctx->r15) = ctx->f6.u32l;
L_8017BFCC:
    // 0x8017BFCC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017BFD0: addiu       $t6, $t6, 0x3B00
    ctx->r14 = ADD32(ctx->r14, 0X3B00);
    // 0x8017BFD4: lbu         $t8, 0x29($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X29);
    // 0x8017BFD8: beq         $t8, $zero, L_8017BFEC
    if (ctx->r24 == 0) {
        // 0x8017BFDC: nop
    
            goto L_8017BFEC;
    }
    // 0x8017BFDC: nop

    // 0x8017BFE0: addiu       $t5, $t8, -0x1
    ctx->r13 = ADD32(ctx->r24, -0X1);
    // 0x8017BFE4: b           L_8017C010
    // 0x8017BFE8: sb          $t5, 0x29($t6)
    MEM_B(0X29, ctx->r14) = ctx->r13;
        goto L_8017C010;
    // 0x8017BFE8: sb          $t5, 0x29($t6)
    MEM_B(0X29, ctx->r14) = ctx->r13;
L_8017BFEC:
    // 0x8017BFEC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017BFF0: addiu       $t9, $t9, 0x3B00
    ctx->r25 = ADD32(ctx->r25, 0X3B00);
    // 0x8017BFF4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017BFF8: addiu       $t2, $t2, 0x3B00
    ctx->r10 = ADD32(ctx->r10, 0X3B00);
    // 0x8017BFFC: sb          $zero, 0x1E($t9)
    MEM_B(0X1E, ctx->r25) = 0;
    // 0x8017C000: lbu         $t0, 0x1E($t2)
    ctx->r8 = MEM_BU(ctx->r10, 0X1E);
    // 0x8017C004: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    // 0x8017C008: jal         0x800C8544
    // 0x8017C00C: sb          $t0, 0x14($t2)
    MEM_B(0X14, ctx->r10) = ctx->r8;
    func_800C8544(rdram, ctx);
        goto after_6;
    // 0x8017C00C: sb          $t0, 0x14($t2)
    MEM_B(0X14, ctx->r10) = ctx->r8;
    after_6:
L_8017C010:
    // 0x8017C010: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8017C014: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8017C018: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8017C01C: jr          $ra
    // 0x8017C020: nop

    return;
    // 0x8017C020: nop

;}
RECOMP_FUNC void func_8017C024_0EF7C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017C024: lui         $at, 0x42DC
    ctx->r1 = S32(0X42DC << 16);
    // 0x8017C028: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017C02C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8017C030: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017C034: lwc1        $f6, -0xF6C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0XF6C);
    // 0x8017C038: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017C03C: lwc1        $f8, -0xF68($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0XF68);
    // 0x8017C040: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017C044: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8017C048: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017C04C: lwc1        $f10, -0xF64($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0XF64);
    // 0x8017C050: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8017C054: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8017C058: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8017C05C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8017C060: lui         $a3, 0xC113
    ctx->r7 = S32(0XC113 << 16);
    // 0x8017C064: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x8017C068: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x8017C06C: ori         $a3, $a3, 0x3333
    ctx->r7 = ctx->r7 | 0X3333;
    // 0x8017C070: addiu       $a0, $a0, -0x858
    ctx->r4 = ADD32(ctx->r4, -0X858);
    // 0x8017C074: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8017C078: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8017C07C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8017C080: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8017C084: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x8017C088: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x8017C08C: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x8017C090: jal         0x800C58E8
    // 0x8017C094: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    func_800C58E8(rdram, ctx);
        goto after_0;
    // 0x8017C094: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x8017C098: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8017C09C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8017C0A0: jr          $ra
    // 0x8017C0A4: nop

    return;
    // 0x8017C0A4: nop

;}
RECOMP_FUNC void func_8017C0A8_0EF7C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017C0A8: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8017C0AC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017C0B0: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8017C0B4: sdc1        $f22, 0x48($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X48, ctx->r29);
    // 0x8017C0B8: sdc1        $f20, 0x40($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X40, ctx->r29);
    // 0x8017C0BC: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x8017C0C0: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8017C0C4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017C0C8: lwc1        $f4, 0x78($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X78);
    // 0x8017C0CC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017C0D0: lwc1        $f10, -0xF60($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0XF60);
    // 0x8017C0D4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8017C0D8: mul.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8017C0DC: jal         0x800D6AB0
    // 0x8017C0E0: nop

    __cosf_recomp(rdram, ctx);
        goto after_0;
    // 0x8017C0E0: nop

    after_0:
    // 0x8017C0E4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017C0E8: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x8017C0EC: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8017C0F0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8017C0F4: lwc1        $f16, 0x78($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X78);
    // 0x8017C0F8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017C0FC: lwc1        $f6, -0xF5C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0XF5C);
    // 0x8017C100: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8017C104: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x8017C108: mul.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8017C10C: jal         0x800D68F0
    // 0x8017C110: nop

    sinf_recomp(rdram, ctx);
        goto after_1;
    // 0x8017C110: nop

    after_1:
    // 0x8017C114: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8017C118: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017C11C: addiu       $t9, $t9, 0x3B80
    ctx->r25 = ADD32(ctx->r25, 0X3B80);
    // 0x8017C120: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8017C124: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8017C128: lhu         $t0, 0x14($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X14);
    // 0x8017C12C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017C130: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8017C134: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8017C138: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8017C13C: lwc1        $f8, -0x1170($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1170);
    // 0x8017C140: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x8017C144: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017C148: lui         $at, 0x42DC
    ctx->r1 = S32(0X42DC << 16);
    // 0x8017C14C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017C150: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8017C154: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017C158: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017C15C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8017C160: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x8017C164: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017C168: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x8017C16C: mul.s       $f18, $f16, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f22.fl);
    // 0x8017C170: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    // 0x8017C174: addiu       $a0, $a0, -0x1110
    ctx->r4 = ADD32(ctx->r4, -0X1110);
    // 0x8017C178: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8017C17C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8017C180: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x8017C184: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x8017C188: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    // 0x8017C18C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8017C190: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8017C194: mul.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x8017C198: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8017C19C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8017C1A0: addiu       $a3, $zero, 0xFA
    ctx->r7 = ADD32(0, 0XFA);
    // 0x8017C1A4: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x8017C1A8: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    // 0x8017C1AC: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    // 0x8017C1B0: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x8017C1B4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8017C1B8: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    // 0x8017C1BC: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x8017C1C0: jal         0x801716C8
    // 0x8017C1C4: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    func_801716C8_02FC30(rdram, ctx);
        goto after_2;
    // 0x8017C1C4: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    after_2:
    // 0x8017C1C8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017C1CC: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x8017C1D0: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8017C1D4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017C1D8: lwc1        $f18, 0x78($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X78);
    // 0x8017C1DC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017C1E0: lwc1        $f6, -0xF58($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0XF58);
    // 0x8017C1E4: add.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8017C1E8: mul.s       $f12, $f8, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8017C1EC: jal         0x800D6AB0
    // 0x8017C1F0: nop

    __cosf_recomp(rdram, ctx);
        goto after_3;
    // 0x8017C1F0: nop

    after_3:
    // 0x8017C1F4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017C1F8: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x8017C1FC: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8017C200: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8017C204: lwc1        $f10, 0x78($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X78);
    // 0x8017C208: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017C20C: lwc1        $f4, -0xF54($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0XF54);
    // 0x8017C210: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8017C214: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x8017C218: mul.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8017C21C: jal         0x800D68F0
    // 0x8017C220: nop

    sinf_recomp(rdram, ctx);
        goto after_4;
    // 0x8017C220: nop

    after_4:
    // 0x8017C224: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x8017C228: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017C22C: addiu       $t6, $t6, 0x3B80
    ctx->r14 = ADD32(ctx->r14, 0X3B80);
    // 0x8017C230: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8017C234: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8017C238: lhu         $t7, 0x14($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X14);
    // 0x8017C23C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017C240: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8017C244: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8017C248: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8017C24C: lwc1        $f8, -0x1170($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1170);
    // 0x8017C250: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x8017C254: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017C258: lui         $at, 0xC170
    ctx->r1 = S32(0XC170 << 16);
    // 0x8017C25C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8017C260: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8017C264: lui         $at, 0x42DC
    ctx->r1 = S32(0X42DC << 16);
    // 0x8017C268: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017C26C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017C270: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    // 0x8017C274: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8017C278: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x8017C27C: mul.s       $f16, $f10, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f22.fl);
    // 0x8017C280: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
    // 0x8017C284: addiu       $a0, $a0, -0x1108
    ctx->r4 = ADD32(ctx->r4, -0X1108);
    // 0x8017C288: mul.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8017C28C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017C290: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x8017C294: addiu       $a2, $zero, 0x21
    ctx->r6 = ADD32(0, 0X21);
    // 0x8017C298: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x8017C29C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8017C2A0: lui         $at, 0xBF00
    ctx->r1 = S32(0XBF00 << 16);
    // 0x8017C2A4: mul.s       $f10, $f6, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x8017C2A8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8017C2AC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8017C2B0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8017C2B4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8017C2B8: addiu       $a3, $zero, 0x53
    ctx->r7 = ADD32(0, 0X53);
    // 0x8017C2BC: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x8017C2C0: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    // 0x8017C2C4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8017C2C8: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x8017C2CC: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    // 0x8017C2D0: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x8017C2D4: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    // 0x8017C2D8: jal         0x801716C8
    // 0x8017C2DC: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    func_801716C8_02FC30(rdram, ctx);
        goto after_5;
    // 0x8017C2DC: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    after_5:
    // 0x8017C2E0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017C2E4: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x8017C2E8: lwc1        $f16, 0x78($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X78);
    // 0x8017C2EC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8017C2F0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017C2F4: lwc1        $f4, -0xF50($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0XF50);
    // 0x8017C2F8: add.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8017C2FC: mul.s       $f12, $f8, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8017C300: jal         0x800D6AB0
    // 0x8017C304: nop

    __cosf_recomp(rdram, ctx);
        goto after_6;
    // 0x8017C304: nop

    after_6:
    // 0x8017C308: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017C30C: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x8017C310: lwc1        $f6, 0x78($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X78);
    // 0x8017C314: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8017C318: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017C31C: lwc1        $f18, -0xF4C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0XF4C);
    // 0x8017C320: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8017C324: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x8017C328: mul.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8017C32C: jal         0x800D68F0
    // 0x8017C330: nop

    sinf_recomp(rdram, ctx);
        goto after_7;
    // 0x8017C330: nop

    after_7:
    // 0x8017C334: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x8017C338: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017C33C: addiu       $t3, $t3, 0x3B80
    ctx->r11 = ADD32(ctx->r11, 0X3B80);
    // 0x8017C340: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8017C344: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8017C348: lhu         $t4, 0x16($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X16);
    // 0x8017C34C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017C350: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8017C354: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8017C358: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x8017C35C: lwc1        $f8, -0x1170($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1170);
    // 0x8017C360: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x8017C364: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017C368: lui         $at, 0x42DC
    ctx->r1 = S32(0X42DC << 16);
    // 0x8017C36C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8017C370: mul.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8017C374: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8017C378: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017C37C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8017C380: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    // 0x8017C384: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8017C388: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x8017C38C: mul.s       $f10, $f6, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x8017C390: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    // 0x8017C394: addiu       $a0, $a0, -0x1100
    ctx->r4 = ADD32(ctx->r4, -0X1100);
    // 0x8017C398: mul.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x8017C39C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8017C3A0: addiu       $a1, $zero, 0xD5
    ctx->r5 = ADD32(0, 0XD5);
    // 0x8017C3A4: addiu       $a2, $zero, 0xB2
    ctx->r6 = ADD32(0, 0XB2);
    // 0x8017C3A8: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x8017C3AC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017C3B0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8017C3B4: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x8017C3B8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017C3BC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8017C3C0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8017C3C4: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    // 0x8017C3C8: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    // 0x8017C3CC: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    // 0x8017C3D0: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x8017C3D4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8017C3D8: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x8017C3DC: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x8017C3E0: jal         0x801716C8
    // 0x8017C3E4: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    func_801716C8_02FC30(rdram, ctx);
        goto after_8;
    // 0x8017C3E4: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    after_8:
    // 0x8017C3E8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017C3EC: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x8017C3F0: lwc1        $f10, 0x78($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X78);
    // 0x8017C3F4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8017C3F8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017C3FC: lwc1        $f18, -0xF48($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0XF48);
    // 0x8017C400: add.s       $f8, $f10, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8017C404: mul.s       $f12, $f8, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x8017C408: jal         0x800D6AB0
    // 0x8017C40C: nop

    __cosf_recomp(rdram, ctx);
        goto after_9;
    // 0x8017C40C: nop

    after_9:
    // 0x8017C410: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017C414: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x8017C418: lwc1        $f4, 0x78($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X78);
    // 0x8017C41C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8017C420: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017C424: lwc1        $f16, -0xF44($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0XF44);
    // 0x8017C428: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8017C42C: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x8017C430: mul.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8017C434: jal         0x800D68F0
    // 0x8017C438: nop

    sinf_recomp(rdram, ctx);
        goto after_10;
    // 0x8017C438: nop

    after_10:
    // 0x8017C43C: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8017C440: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017C444: addiu       $t0, $t0, 0x3B80
    ctx->r8 = ADD32(ctx->r8, 0X3B80);
    // 0x8017C448: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8017C44C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8017C450: lhu         $t1, 0x16($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X16);
    // 0x8017C454: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017C458: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8017C45C: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8017C460: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x8017C464: lwc1        $f8, -0x1170($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1170);
    // 0x8017C468: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x8017C46C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8017C470: lui         $at, 0xC170
    ctx->r1 = S32(0XC170 << 16);
    // 0x8017C474: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017C478: mul.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x8017C47C: lui         $at, 0x42DC
    ctx->r1 = S32(0X42DC << 16);
    // 0x8017C480: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8017C484: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017C488: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x8017C48C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8017C490: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x8017C494: mul.s       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x8017C498: sw          $t3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r11;
    // 0x8017C49C: addiu       $a0, $a0, -0x10F8
    ctx->r4 = ADD32(ctx->r4, -0X10F8);
    // 0x8017C4A0: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8017C4A4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8017C4A8: addiu       $a1, $zero, 0x47
    ctx->r5 = ADD32(0, 0X47);
    // 0x8017C4AC: addiu       $a2, $zero, 0x3B
    ctx->r6 = ADD32(0, 0X3B);
    // 0x8017C4B0: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x8017C4B4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017C4B8: lui         $at, 0xBF00
    ctx->r1 = S32(0XBF00 << 16);
    // 0x8017C4BC: mul.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x8017C4C0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017C4C4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8017C4C8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8017C4CC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8017C4D0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8017C4D4: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    // 0x8017C4D8: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x8017C4DC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017C4E0: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    // 0x8017C4E4: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x8017C4E8: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x8017C4EC: swc1        $f18, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f18.u32l;
    // 0x8017C4F0: jal         0x801716C8
    // 0x8017C4F4: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    func_801716C8_02FC30(rdram, ctx);
        goto after_11;
    // 0x8017C4F4: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    after_11:
    // 0x8017C4F8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017C4FC: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x8017C500: lui         $at, 0x4387
    ctx->r1 = S32(0X4387 << 16);
    // 0x8017C504: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017C508: lwc1        $f6, 0x78($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X78);
    // 0x8017C50C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017C510: lwc1        $f16, -0xF40($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0XF40);
    // 0x8017C514: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8017C518: mul.s       $f12, $f8, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8017C51C: jal         0x800D6AB0
    // 0x8017C520: nop

    __cosf_recomp(rdram, ctx);
        goto after_12;
    // 0x8017C520: nop

    after_12:
    // 0x8017C524: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017C528: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x8017C52C: lui         $at, 0x4387
    ctx->r1 = S32(0X4387 << 16);
    // 0x8017C530: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017C534: lwc1        $f18, 0x78($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X78);
    // 0x8017C538: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017C53C: lwc1        $f10, -0xF3C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0XF3C);
    // 0x8017C540: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8017C544: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x8017C548: mul.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8017C54C: jal         0x800D68F0
    // 0x8017C550: nop

    sinf_recomp(rdram, ctx);
        goto after_13;
    // 0x8017C550: nop

    after_13:
    // 0x8017C554: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8017C558: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017C55C: addiu       $t7, $t7, 0x3B80
    ctx->r15 = ADD32(ctx->r15, 0X3B80);
    // 0x8017C560: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8017C564: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8017C568: lhu         $t8, 0x18($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X18);
    // 0x8017C56C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017C570: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8017C574: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8017C578: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8017C57C: lwc1        $f8, -0x1170($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1170);
    // 0x8017C580: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x8017C584: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8017C588: lui         $at, 0x42DC
    ctx->r1 = S32(0X42DC << 16);
    // 0x8017C58C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017C590: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8017C594: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8017C598: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017C59C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8017C5A0: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x8017C5A4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017C5A8: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x8017C5AC: mul.s       $f4, $f18, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f22.fl);
    // 0x8017C5B0: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    // 0x8017C5B4: addiu       $a0, $a0, -0x10F0
    ctx->r4 = ADD32(ctx->r4, -0X10F0);
    // 0x8017C5B8: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8017C5BC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8017C5C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8017C5C4: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    // 0x8017C5C8: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x8017C5CC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017C5D0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8017C5D4: mul.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x8017C5D8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8017C5DC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8017C5E0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8017C5E4: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x8017C5E8: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    // 0x8017C5EC: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x8017C5F0: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    // 0x8017C5F4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8017C5F8: swc1        $f16, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f16.u32l;
    // 0x8017C5FC: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x8017C600: jal         0x801716C8
    // 0x8017C604: swc1        $f18, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f18.u32l;
    func_801716C8_02FC30(rdram, ctx);
        goto after_14;
    // 0x8017C604: swc1        $f18, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f18.u32l;
    after_14:
    // 0x8017C608: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017C60C: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x8017C610: lui         $at, 0x4387
    ctx->r1 = S32(0X4387 << 16);
    // 0x8017C614: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017C618: lwc1        $f4, 0x78($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X78);
    // 0x8017C61C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017C620: lwc1        $f10, -0xF38($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0XF38);
    // 0x8017C624: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8017C628: mul.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8017C62C: jal         0x800D6AB0
    // 0x8017C630: nop

    __cosf_recomp(rdram, ctx);
        goto after_15;
    // 0x8017C630: nop

    after_15:
    // 0x8017C634: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017C638: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x8017C63C: lui         $at, 0x4387
    ctx->r1 = S32(0X4387 << 16);
    // 0x8017C640: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8017C644: lwc1        $f16, 0x78($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X78);
    // 0x8017C648: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017C64C: lwc1        $f6, -0xF34($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0XF34);
    // 0x8017C650: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8017C654: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x8017C658: mul.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8017C65C: jal         0x800D68F0
    // 0x8017C660: nop

    sinf_recomp(rdram, ctx);
        goto after_16;
    // 0x8017C660: nop

    after_16:
    // 0x8017C664: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x8017C668: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017C66C: addiu       $t4, $t4, 0x3B80
    ctx->r12 = ADD32(ctx->r12, 0X3B80);
    // 0x8017C670: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8017C674: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8017C678: lhu         $t5, 0x18($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X18);
    // 0x8017C67C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017C680: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8017C684: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8017C688: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8017C68C: lwc1        $f8, -0x1170($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1170);
    // 0x8017C690: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x8017C694: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017C698: lui         $at, 0xC170
    ctx->r1 = S32(0XC170 << 16);
    // 0x8017C69C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017C6A0: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8017C6A4: lui         $at, 0x42DC
    ctx->r1 = S32(0X42DC << 16);
    // 0x8017C6A8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017C6AC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017C6B0: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x8017C6B4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8017C6B8: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8017C6BC: mul.s       $f18, $f16, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f22.fl);
    // 0x8017C6C0: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x8017C6C4: addiu       $a0, $a0, -0x10E8
    ctx->r4 = ADD32(ctx->r4, -0X10E8);
    // 0x8017C6C8: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8017C6CC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8017C6D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8017C6D4: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    // 0x8017C6D8: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    // 0x8017C6DC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8017C6E0: lui         $at, 0xBF00
    ctx->r1 = S32(0XBF00 << 16);
    // 0x8017C6E4: mul.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x8017C6E8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017C6EC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8017C6F0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8017C6F4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8017C6F8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8017C6FC: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    // 0x8017C700: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x8017C704: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8017C708: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    // 0x8017C70C: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x8017C710: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x8017C714: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    // 0x8017C718: jal         0x801716C8
    // 0x8017C71C: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    func_801716C8_02FC30(rdram, ctx);
        goto after_17;
    // 0x8017C71C: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    after_17:
    // 0x8017C720: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017C724: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x8017C728: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8017C72C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017C730: lwc1        $f18, 0x78($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X78);
    // 0x8017C734: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017C738: lwc1        $f6, -0xF30($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0XF30);
    // 0x8017C73C: add.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8017C740: mul.s       $f12, $f8, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8017C744: jal         0x800D6AB0
    // 0x8017C748: nop

    __cosf_recomp(rdram, ctx);
        goto after_18;
    // 0x8017C748: nop

    after_18:
    // 0x8017C74C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017C750: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x8017C754: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8017C758: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8017C75C: lwc1        $f10, 0x78($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X78);
    // 0x8017C760: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017C764: lwc1        $f4, -0xF2C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0XF2C);
    // 0x8017C768: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8017C76C: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x8017C770: mul.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8017C774: jal         0x800D68F0
    // 0x8017C778: nop

    sinf_recomp(rdram, ctx);
        goto after_19;
    // 0x8017C778: nop

    after_19:
    // 0x8017C77C: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x8017C780: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017C784: addiu       $t1, $t1, 0x3B80
    ctx->r9 = ADD32(ctx->r9, 0X3B80);
    // 0x8017C788: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8017C78C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8017C790: lhu         $t2, 0x1A($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X1A);
    // 0x8017C794: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017C798: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8017C79C: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8017C7A0: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x8017C7A4: lwc1        $f8, -0x1170($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1170);
    // 0x8017C7A8: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x8017C7AC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017C7B0: lui         $at, 0x42DC
    ctx->r1 = S32(0X42DC << 16);
    // 0x8017C7B4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017C7B8: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8017C7BC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8017C7C0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017C7C4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8017C7C8: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    // 0x8017C7CC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8017C7D0: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x8017C7D4: mul.s       $f16, $f10, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f22.fl);
    // 0x8017C7D8: sw          $t4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r12;
    // 0x8017C7DC: addiu       $a0, $a0, -0x10E0
    ctx->r4 = ADD32(ctx->r4, -0X10E0);
    // 0x8017C7E0: mul.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8017C7E4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017C7E8: addiu       $a1, $zero, 0xB4
    ctx->r5 = ADD32(0, 0XB4);
    // 0x8017C7EC: addiu       $a2, $zero, 0xB4
    ctx->r6 = ADD32(0, 0XB4);
    // 0x8017C7F0: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x8017C7F4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8017C7F8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8017C7FC: mul.s       $f10, $f6, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x8017C800: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8017C804: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8017C808: addiu       $a3, $zero, 0xB4
    ctx->r7 = ADD32(0, 0XB4);
    // 0x8017C80C: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    // 0x8017C810: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x8017C814: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x8017C818: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    // 0x8017C81C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8017C820: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    // 0x8017C824: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x8017C828: jal         0x801716C8
    // 0x8017C82C: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    func_801716C8_02FC30(rdram, ctx);
        goto after_20;
    // 0x8017C82C: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    after_20:
    // 0x8017C830: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017C834: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x8017C838: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8017C83C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8017C840: lwc1        $f16, 0x78($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0X78);
    // 0x8017C844: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017C848: lwc1        $f4, -0xF28($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0XF28);
    // 0x8017C84C: add.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8017C850: mul.s       $f12, $f8, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8017C854: jal         0x800D6AB0
    // 0x8017C858: nop

    __cosf_recomp(rdram, ctx);
        goto after_21;
    // 0x8017C858: nop

    after_21:
    // 0x8017C85C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017C860: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x8017C864: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8017C868: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017C86C: lwc1        $f6, 0x78($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X78);
    // 0x8017C870: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017C874: lwc1        $f18, -0xF24($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0XF24);
    // 0x8017C878: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8017C87C: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x8017C880: mul.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8017C884: jal         0x800D68F0
    // 0x8017C888: nop

    sinf_recomp(rdram, ctx);
        goto after_22;
    // 0x8017C888: nop

    after_22:
    // 0x8017C88C: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8017C890: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017C894: addiu       $t8, $t8, 0x3B80
    ctx->r24 = ADD32(ctx->r24, 0X3B80);
    // 0x8017C898: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8017C89C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8017C8A0: lhu         $t9, 0x1A($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X1A);
    // 0x8017C8A4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017C8A8: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8017C8AC: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8017C8B0: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x8017C8B4: lwc1        $f8, -0x1170($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1170);
    // 0x8017C8B8: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x8017C8BC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017C8C0: lui         $at, 0xC170
    ctx->r1 = S32(0XC170 << 16);
    // 0x8017C8C4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8017C8C8: mul.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8017C8CC: lui         $at, 0x42DC
    ctx->r1 = S32(0X42DC << 16);
    // 0x8017C8D0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8017C8D4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017C8D8: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    // 0x8017C8DC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8017C8E0: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x8017C8E4: mul.s       $f10, $f6, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x8017C8E8: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x8017C8EC: addiu       $a0, $a0, -0x10D4
    ctx->r4 = ADD32(ctx->r4, -0X10D4);
    // 0x8017C8F0: mul.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x8017C8F4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8017C8F8: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x8017C8FC: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    // 0x8017C900: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x8017C904: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017C908: lui         $at, 0xBF00
    ctx->r1 = S32(0XBF00 << 16);
    // 0x8017C90C: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x8017C910: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8017C914: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8017C918: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8017C91C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017C920: addiu       $a3, $zero, 0x3C
    ctx->r7 = ADD32(0, 0X3C);
    // 0x8017C924: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    // 0x8017C928: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x8017C92C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8017C930: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    // 0x8017C934: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    // 0x8017C938: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x8017C93C: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x8017C940: jal         0x801716C8
    // 0x8017C944: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    func_801716C8_02FC30(rdram, ctx);
        goto after_23;
    // 0x8017C944: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    after_23:
    // 0x8017C948: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x8017C94C: ldc1        $f20, 0x40($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X40);
    // 0x8017C950: ldc1        $f22, 0x48($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X48);
    // 0x8017C954: jr          $ra
    // 0x8017C958: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8017C958: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_8017C95C_0EF7C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017C95C: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8017C960: sw          $s0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r16;
    // 0x8017C964: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8017C968: lw          $s0, -0x2E48($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X2E48);
    // 0x8017C96C: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x8017C970: sdc1        $f22, 0x50($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X50, ctx->r29);
    // 0x8017C974: beq         $s0, $zero, L_8017C9A0
    if (ctx->r16 == 0) {
        // 0x8017C978: sdc1        $f20, 0x48($sp)
        CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X48, ctx->r29);
            goto L_8017C9A0;
    }
    // 0x8017C978: sdc1        $f20, 0x48($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X48, ctx->r29);
    // 0x8017C97C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8017C980: beq         $s0, $at, L_8017CBD0
    if (ctx->r16 == ctx->r1) {
        // 0x8017C984: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8017CBD0;
    }
    // 0x8017C984: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8017C988: beq         $s0, $at, L_8017CDF0
    if (ctx->r16 == ctx->r1) {
        // 0x8017C98C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8017CDF0;
    }
    // 0x8017C98C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8017C990: beq         $s0, $at, L_8017D020
    if (ctx->r16 == ctx->r1) {
        // 0x8017C994: nop
    
            goto L_8017D020;
    }
    // 0x8017C994: nop

    // 0x8017C998: b           L_8017D248
    // 0x8017C99C: nop

        goto L_8017D248;
    // 0x8017C99C: nop

L_8017C9A0:
    // 0x8017C9A0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017C9A4: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x8017C9A8: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8017C9AC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017C9B0: lwc1        $f4, 0x78($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X78);
    // 0x8017C9B4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017C9B8: lwc1        $f10, -0xF20($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0XF20);
    // 0x8017C9BC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8017C9C0: mul.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8017C9C4: jal         0x800D6AB0
    // 0x8017C9C8: nop

    __cosf_recomp(rdram, ctx);
        goto after_0;
    // 0x8017C9C8: nop

    after_0:
    // 0x8017C9CC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017C9D0: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x8017C9D4: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8017C9D8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8017C9DC: lwc1        $f16, 0x78($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X78);
    // 0x8017C9E0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017C9E4: lwc1        $f6, -0xF1C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0XF1C);
    // 0x8017C9E8: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8017C9EC: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x8017C9F0: mul.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8017C9F4: jal         0x800D68F0
    // 0x8017C9F8: nop

    sinf_recomp(rdram, ctx);
        goto after_1;
    // 0x8017C9F8: nop

    after_1:
    // 0x8017C9FC: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8017CA00: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017CA04: addiu       $t9, $t9, 0x3B80
    ctx->r25 = ADD32(ctx->r25, 0X3B80);
    // 0x8017CA08: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8017CA0C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8017CA10: lhu         $t0, 0x14($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X14);
    // 0x8017CA14: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017CA18: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8017CA1C: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8017CA20: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8017CA24: lwc1        $f8, -0x1170($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1170);
    // 0x8017CA28: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x8017CA2C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017CA30: lui         $at, 0x42DC
    ctx->r1 = S32(0X42DC << 16);
    // 0x8017CA34: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017CA38: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8017CA3C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017CA40: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017CA44: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8017CA48: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x8017CA4C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017CA50: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x8017CA54: mul.s       $f18, $f16, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f22.fl);
    // 0x8017CA58: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    // 0x8017CA5C: addiu       $a0, $a0, -0x10C8
    ctx->r4 = ADD32(ctx->r4, -0X10C8);
    // 0x8017CA60: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8017CA64: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8017CA68: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x8017CA6C: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x8017CA70: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    // 0x8017CA74: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8017CA78: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8017CA7C: mul.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x8017CA80: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8017CA84: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8017CA88: addiu       $a3, $zero, 0xFA
    ctx->r7 = ADD32(0, 0XFA);
    // 0x8017CA8C: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x8017CA90: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    // 0x8017CA94: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    // 0x8017CA98: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x8017CA9C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8017CAA0: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    // 0x8017CAA4: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x8017CAA8: jal         0x801716C8
    // 0x8017CAAC: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    func_801716C8_02FC30(rdram, ctx);
        goto after_2;
    // 0x8017CAAC: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    after_2:
    // 0x8017CAB0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017CAB4: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x8017CAB8: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8017CABC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017CAC0: lwc1        $f18, 0x78($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X78);
    // 0x8017CAC4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017CAC8: lwc1        $f6, -0xF18($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0XF18);
    // 0x8017CACC: add.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8017CAD0: mul.s       $f12, $f8, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8017CAD4: jal         0x800D6AB0
    // 0x8017CAD8: nop

    __cosf_recomp(rdram, ctx);
        goto after_3;
    // 0x8017CAD8: nop

    after_3:
    // 0x8017CADC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017CAE0: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x8017CAE4: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8017CAE8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8017CAEC: lwc1        $f10, 0x78($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X78);
    // 0x8017CAF0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017CAF4: lwc1        $f4, -0xF14($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0XF14);
    // 0x8017CAF8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8017CAFC: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x8017CB00: mul.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8017CB04: jal         0x800D68F0
    // 0x8017CB08: nop

    sinf_recomp(rdram, ctx);
        goto after_4;
    // 0x8017CB08: nop

    after_4:
    // 0x8017CB0C: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x8017CB10: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017CB14: addiu       $t6, $t6, 0x3B80
    ctx->r14 = ADD32(ctx->r14, 0X3B80);
    // 0x8017CB18: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8017CB1C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8017CB20: lhu         $t7, 0x14($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X14);
    // 0x8017CB24: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017CB28: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8017CB2C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8017CB30: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8017CB34: lwc1        $f8, -0x1170($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1170);
    // 0x8017CB38: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x8017CB3C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017CB40: lui         $at, 0xC170
    ctx->r1 = S32(0XC170 << 16);
    // 0x8017CB44: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8017CB48: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8017CB4C: lui         $at, 0x42DC
    ctx->r1 = S32(0X42DC << 16);
    // 0x8017CB50: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017CB54: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017CB58: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    // 0x8017CB5C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8017CB60: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x8017CB64: mul.s       $f16, $f10, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f22.fl);
    // 0x8017CB68: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
    // 0x8017CB6C: addiu       $a0, $a0, -0x10C0
    ctx->r4 = ADD32(ctx->r4, -0X10C0);
    // 0x8017CB70: mul.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8017CB74: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017CB78: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x8017CB7C: addiu       $a2, $zero, 0x21
    ctx->r6 = ADD32(0, 0X21);
    // 0x8017CB80: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x8017CB84: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8017CB88: lui         $at, 0xBF00
    ctx->r1 = S32(0XBF00 << 16);
    // 0x8017CB8C: mul.s       $f10, $f6, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x8017CB90: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8017CB94: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8017CB98: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8017CB9C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8017CBA0: addiu       $a3, $zero, 0x53
    ctx->r7 = ADD32(0, 0X53);
    // 0x8017CBA4: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x8017CBA8: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    // 0x8017CBAC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8017CBB0: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x8017CBB4: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    // 0x8017CBB8: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x8017CBBC: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    // 0x8017CBC0: jal         0x801716C8
    // 0x8017CBC4: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    func_801716C8_02FC30(rdram, ctx);
        goto after_5;
    // 0x8017CBC4: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    after_5:
    // 0x8017CBC8: b           L_8017D248
    // 0x8017CBCC: nop

        goto L_8017D248;
    // 0x8017CBCC: nop

L_8017CBD0:
    // 0x8017CBD0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017CBD4: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x8017CBD8: lwc1        $f16, 0x78($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X78);
    // 0x8017CBDC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8017CBE0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017CBE4: lwc1        $f4, -0xF10($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0XF10);
    // 0x8017CBE8: add.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8017CBEC: mul.s       $f12, $f8, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8017CBF0: jal         0x800D6AB0
    // 0x8017CBF4: nop

    __cosf_recomp(rdram, ctx);
        goto after_6;
    // 0x8017CBF4: nop

    after_6:
    // 0x8017CBF8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017CBFC: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x8017CC00: lwc1        $f6, 0x78($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X78);
    // 0x8017CC04: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8017CC08: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017CC0C: lwc1        $f18, -0xF0C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0XF0C);
    // 0x8017CC10: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8017CC14: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x8017CC18: mul.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8017CC1C: jal         0x800D68F0
    // 0x8017CC20: nop

    sinf_recomp(rdram, ctx);
        goto after_7;
    // 0x8017CC20: nop

    after_7:
    // 0x8017CC24: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x8017CC28: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017CC2C: addiu       $t3, $t3, 0x3B80
    ctx->r11 = ADD32(ctx->r11, 0X3B80);
    // 0x8017CC30: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8017CC34: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8017CC38: lhu         $t4, 0x16($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X16);
    // 0x8017CC3C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017CC40: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8017CC44: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8017CC48: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x8017CC4C: lwc1        $f8, -0x1170($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1170);
    // 0x8017CC50: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x8017CC54: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017CC58: lui         $at, 0x42DC
    ctx->r1 = S32(0X42DC << 16);
    // 0x8017CC5C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8017CC60: mul.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8017CC64: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8017CC68: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017CC6C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8017CC70: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    // 0x8017CC74: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8017CC78: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x8017CC7C: mul.s       $f10, $f6, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x8017CC80: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    // 0x8017CC84: addiu       $a0, $a0, -0x10B8
    ctx->r4 = ADD32(ctx->r4, -0X10B8);
    // 0x8017CC88: mul.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x8017CC8C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8017CC90: addiu       $a1, $zero, 0xD5
    ctx->r5 = ADD32(0, 0XD5);
    // 0x8017CC94: addiu       $a2, $zero, 0xB2
    ctx->r6 = ADD32(0, 0XB2);
    // 0x8017CC98: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x8017CC9C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017CCA0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8017CCA4: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x8017CCA8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017CCAC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8017CCB0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8017CCB4: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    // 0x8017CCB8: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    // 0x8017CCBC: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    // 0x8017CCC0: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x8017CCC4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8017CCC8: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x8017CCCC: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x8017CCD0: jal         0x801716C8
    // 0x8017CCD4: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    func_801716C8_02FC30(rdram, ctx);
        goto after_8;
    // 0x8017CCD4: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    after_8:
    // 0x8017CCD8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017CCDC: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x8017CCE0: lwc1        $f10, 0x78($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X78);
    // 0x8017CCE4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8017CCE8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017CCEC: lwc1        $f18, -0xF08($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0XF08);
    // 0x8017CCF0: add.s       $f8, $f10, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8017CCF4: mul.s       $f12, $f8, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x8017CCF8: jal         0x800D6AB0
    // 0x8017CCFC: nop

    __cosf_recomp(rdram, ctx);
        goto after_9;
    // 0x8017CCFC: nop

    after_9:
    // 0x8017CD00: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017CD04: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x8017CD08: lwc1        $f4, 0x78($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X78);
    // 0x8017CD0C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8017CD10: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017CD14: lwc1        $f16, -0xF04($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0XF04);
    // 0x8017CD18: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8017CD1C: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x8017CD20: mul.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8017CD24: jal         0x800D68F0
    // 0x8017CD28: nop

    sinf_recomp(rdram, ctx);
        goto after_10;
    // 0x8017CD28: nop

    after_10:
    // 0x8017CD2C: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8017CD30: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017CD34: addiu       $t0, $t0, 0x3B80
    ctx->r8 = ADD32(ctx->r8, 0X3B80);
    // 0x8017CD38: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8017CD3C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8017CD40: lhu         $t1, 0x16($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X16);
    // 0x8017CD44: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017CD48: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8017CD4C: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8017CD50: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x8017CD54: lwc1        $f8, -0x1170($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1170);
    // 0x8017CD58: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x8017CD5C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8017CD60: lui         $at, 0xC170
    ctx->r1 = S32(0XC170 << 16);
    // 0x8017CD64: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017CD68: mul.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x8017CD6C: lui         $at, 0x42DC
    ctx->r1 = S32(0X42DC << 16);
    // 0x8017CD70: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8017CD74: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017CD78: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x8017CD7C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8017CD80: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x8017CD84: mul.s       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x8017CD88: sw          $t3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r11;
    // 0x8017CD8C: addiu       $a0, $a0, -0x10B0
    ctx->r4 = ADD32(ctx->r4, -0X10B0);
    // 0x8017CD90: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8017CD94: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8017CD98: addiu       $a1, $zero, 0x47
    ctx->r5 = ADD32(0, 0X47);
    // 0x8017CD9C: addiu       $a2, $zero, 0x3B
    ctx->r6 = ADD32(0, 0X3B);
    // 0x8017CDA0: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x8017CDA4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017CDA8: lui         $at, 0xBF00
    ctx->r1 = S32(0XBF00 << 16);
    // 0x8017CDAC: mul.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x8017CDB0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017CDB4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8017CDB8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8017CDBC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8017CDC0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8017CDC4: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    // 0x8017CDC8: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x8017CDCC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017CDD0: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    // 0x8017CDD4: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x8017CDD8: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x8017CDDC: swc1        $f18, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f18.u32l;
    // 0x8017CDE0: jal         0x801716C8
    // 0x8017CDE4: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    func_801716C8_02FC30(rdram, ctx);
        goto after_11;
    // 0x8017CDE4: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    after_11:
    // 0x8017CDE8: b           L_8017D248
    // 0x8017CDEC: nop

        goto L_8017D248;
    // 0x8017CDEC: nop

L_8017CDF0:
    // 0x8017CDF0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017CDF4: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x8017CDF8: lui         $at, 0x4387
    ctx->r1 = S32(0X4387 << 16);
    // 0x8017CDFC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017CE00: lwc1        $f6, 0x78($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X78);
    // 0x8017CE04: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017CE08: lwc1        $f16, -0xF00($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0XF00);
    // 0x8017CE0C: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8017CE10: mul.s       $f12, $f8, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8017CE14: jal         0x800D6AB0
    // 0x8017CE18: nop

    __cosf_recomp(rdram, ctx);
        goto after_12;
    // 0x8017CE18: nop

    after_12:
    // 0x8017CE1C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017CE20: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x8017CE24: lui         $at, 0x4387
    ctx->r1 = S32(0X4387 << 16);
    // 0x8017CE28: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017CE2C: lwc1        $f18, 0x78($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X78);
    // 0x8017CE30: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017CE34: lwc1        $f10, -0xEFC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0XEFC);
    // 0x8017CE38: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8017CE3C: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x8017CE40: mul.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8017CE44: jal         0x800D68F0
    // 0x8017CE48: nop

    sinf_recomp(rdram, ctx);
        goto after_13;
    // 0x8017CE48: nop

    after_13:
    // 0x8017CE4C: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8017CE50: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017CE54: addiu       $t7, $t7, 0x3B80
    ctx->r15 = ADD32(ctx->r15, 0X3B80);
    // 0x8017CE58: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8017CE5C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8017CE60: lhu         $t8, 0x18($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X18);
    // 0x8017CE64: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017CE68: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8017CE6C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8017CE70: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8017CE74: lwc1        $f8, -0x1170($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1170);
    // 0x8017CE78: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x8017CE7C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8017CE80: lui         $at, 0x42DC
    ctx->r1 = S32(0X42DC << 16);
    // 0x8017CE84: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017CE88: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8017CE8C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8017CE90: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017CE94: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8017CE98: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x8017CE9C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017CEA0: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x8017CEA4: mul.s       $f4, $f18, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f22.fl);
    // 0x8017CEA8: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    // 0x8017CEAC: addiu       $a0, $a0, -0x10A8
    ctx->r4 = ADD32(ctx->r4, -0X10A8);
    // 0x8017CEB0: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8017CEB4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8017CEB8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8017CEBC: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    // 0x8017CEC0: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x8017CEC4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017CEC8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8017CECC: mul.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x8017CED0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8017CED4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8017CED8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8017CEDC: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x8017CEE0: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    // 0x8017CEE4: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x8017CEE8: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    // 0x8017CEEC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8017CEF0: swc1        $f16, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f16.u32l;
    // 0x8017CEF4: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x8017CEF8: jal         0x801716C8
    // 0x8017CEFC: swc1        $f18, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f18.u32l;
    func_801716C8_02FC30(rdram, ctx);
        goto after_14;
    // 0x8017CEFC: swc1        $f18, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f18.u32l;
    after_14:
    // 0x8017CF00: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017CF04: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x8017CF08: lui         $at, 0x4387
    ctx->r1 = S32(0X4387 << 16);
    // 0x8017CF0C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017CF10: lwc1        $f4, 0x78($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X78);
    // 0x8017CF14: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017CF18: lwc1        $f10, -0xEF8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0XEF8);
    // 0x8017CF1C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8017CF20: mul.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8017CF24: jal         0x800D6AB0
    // 0x8017CF28: nop

    __cosf_recomp(rdram, ctx);
        goto after_15;
    // 0x8017CF28: nop

    after_15:
    // 0x8017CF2C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017CF30: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x8017CF34: lui         $at, 0x4387
    ctx->r1 = S32(0X4387 << 16);
    // 0x8017CF38: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8017CF3C: lwc1        $f16, 0x78($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X78);
    // 0x8017CF40: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017CF44: lwc1        $f6, -0xEF4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0XEF4);
    // 0x8017CF48: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8017CF4C: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x8017CF50: mul.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8017CF54: jal         0x800D68F0
    // 0x8017CF58: nop

    sinf_recomp(rdram, ctx);
        goto after_16;
    // 0x8017CF58: nop

    after_16:
    // 0x8017CF5C: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x8017CF60: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017CF64: addiu       $t4, $t4, 0x3B80
    ctx->r12 = ADD32(ctx->r12, 0X3B80);
    // 0x8017CF68: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8017CF6C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8017CF70: lhu         $t5, 0x18($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X18);
    // 0x8017CF74: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017CF78: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8017CF7C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8017CF80: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8017CF84: lwc1        $f8, -0x1170($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1170);
    // 0x8017CF88: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x8017CF8C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017CF90: lui         $at, 0xC170
    ctx->r1 = S32(0XC170 << 16);
    // 0x8017CF94: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017CF98: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8017CF9C: lui         $at, 0x42DC
    ctx->r1 = S32(0X42DC << 16);
    // 0x8017CFA0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017CFA4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017CFA8: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x8017CFAC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8017CFB0: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8017CFB4: mul.s       $f18, $f16, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f22.fl);
    // 0x8017CFB8: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x8017CFBC: addiu       $a0, $a0, -0x10A0
    ctx->r4 = ADD32(ctx->r4, -0X10A0);
    // 0x8017CFC0: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8017CFC4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8017CFC8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8017CFCC: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    // 0x8017CFD0: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    // 0x8017CFD4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8017CFD8: lui         $at, 0xBF00
    ctx->r1 = S32(0XBF00 << 16);
    // 0x8017CFDC: mul.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x8017CFE0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017CFE4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8017CFE8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8017CFEC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8017CFF0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8017CFF4: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    // 0x8017CFF8: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x8017CFFC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8017D000: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    // 0x8017D004: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x8017D008: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x8017D00C: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    // 0x8017D010: jal         0x801716C8
    // 0x8017D014: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    func_801716C8_02FC30(rdram, ctx);
        goto after_17;
    // 0x8017D014: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    after_17:
    // 0x8017D018: b           L_8017D248
    // 0x8017D01C: nop

        goto L_8017D248;
    // 0x8017D01C: nop

L_8017D020:
    // 0x8017D020: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017D024: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x8017D028: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8017D02C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017D030: lwc1        $f18, 0x78($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X78);
    // 0x8017D034: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017D038: lwc1        $f6, -0xEF0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0XEF0);
    // 0x8017D03C: add.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8017D040: mul.s       $f12, $f8, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8017D044: jal         0x800D6AB0
    // 0x8017D048: nop

    __cosf_recomp(rdram, ctx);
        goto after_18;
    // 0x8017D048: nop

    after_18:
    // 0x8017D04C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017D050: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x8017D054: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8017D058: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8017D05C: lwc1        $f10, 0x78($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X78);
    // 0x8017D060: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017D064: lwc1        $f4, -0xEEC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0XEEC);
    // 0x8017D068: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8017D06C: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x8017D070: mul.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8017D074: jal         0x800D68F0
    // 0x8017D078: nop

    sinf_recomp(rdram, ctx);
        goto after_19;
    // 0x8017D078: nop

    after_19:
    // 0x8017D07C: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x8017D080: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017D084: addiu       $t1, $t1, 0x3B80
    ctx->r9 = ADD32(ctx->r9, 0X3B80);
    // 0x8017D088: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8017D08C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8017D090: lhu         $t2, 0x1A($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X1A);
    // 0x8017D094: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017D098: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8017D09C: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8017D0A0: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x8017D0A4: lwc1        $f8, -0x1170($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1170);
    // 0x8017D0A8: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x8017D0AC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017D0B0: lui         $at, 0x42DC
    ctx->r1 = S32(0X42DC << 16);
    // 0x8017D0B4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017D0B8: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8017D0BC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8017D0C0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017D0C4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8017D0C8: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    // 0x8017D0CC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8017D0D0: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x8017D0D4: mul.s       $f16, $f10, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f22.fl);
    // 0x8017D0D8: sw          $t4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r12;
    // 0x8017D0DC: addiu       $a0, $a0, -0x1098
    ctx->r4 = ADD32(ctx->r4, -0X1098);
    // 0x8017D0E0: mul.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8017D0E4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017D0E8: addiu       $a1, $zero, 0xB4
    ctx->r5 = ADD32(0, 0XB4);
    // 0x8017D0EC: addiu       $a2, $zero, 0xB4
    ctx->r6 = ADD32(0, 0XB4);
    // 0x8017D0F0: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x8017D0F4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8017D0F8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8017D0FC: mul.s       $f10, $f6, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x8017D100: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8017D104: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8017D108: addiu       $a3, $zero, 0xB4
    ctx->r7 = ADD32(0, 0XB4);
    // 0x8017D10C: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    // 0x8017D110: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x8017D114: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x8017D118: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    // 0x8017D11C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8017D120: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    // 0x8017D124: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x8017D128: jal         0x801716C8
    // 0x8017D12C: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    func_801716C8_02FC30(rdram, ctx);
        goto after_20;
    // 0x8017D12C: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    after_20:
    // 0x8017D130: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017D134: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x8017D138: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8017D13C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8017D140: lwc1        $f16, 0x78($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0X78);
    // 0x8017D144: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017D148: lwc1        $f4, -0xEE8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0XEE8);
    // 0x8017D14C: add.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8017D150: mul.s       $f12, $f8, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8017D154: jal         0x800D6AB0
    // 0x8017D158: nop

    __cosf_recomp(rdram, ctx);
        goto after_21;
    // 0x8017D158: nop

    after_21:
    // 0x8017D15C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017D160: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x8017D164: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8017D168: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017D16C: lwc1        $f6, 0x78($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X78);
    // 0x8017D170: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017D174: lwc1        $f18, -0xEE4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0XEE4);
    // 0x8017D178: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8017D17C: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x8017D180: mul.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8017D184: jal         0x800D68F0
    // 0x8017D188: nop

    sinf_recomp(rdram, ctx);
        goto after_22;
    // 0x8017D188: nop

    after_22:
    // 0x8017D18C: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8017D190: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017D194: addiu       $t8, $t8, 0x3B80
    ctx->r24 = ADD32(ctx->r24, 0X3B80);
    // 0x8017D198: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8017D19C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8017D1A0: lhu         $t9, 0x1A($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X1A);
    // 0x8017D1A4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017D1A8: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8017D1AC: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8017D1B0: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x8017D1B4: lwc1        $f8, -0x1170($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1170);
    // 0x8017D1B8: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x8017D1BC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017D1C0: lui         $at, 0xC170
    ctx->r1 = S32(0XC170 << 16);
    // 0x8017D1C4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8017D1C8: mul.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8017D1CC: lui         $at, 0x42DC
    ctx->r1 = S32(0X42DC << 16);
    // 0x8017D1D0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8017D1D4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017D1D8: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    // 0x8017D1DC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8017D1E0: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x8017D1E4: mul.s       $f10, $f6, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x8017D1E8: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x8017D1EC: addiu       $a0, $a0, -0x108C
    ctx->r4 = ADD32(ctx->r4, -0X108C);
    // 0x8017D1F0: mul.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x8017D1F4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8017D1F8: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x8017D1FC: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    // 0x8017D200: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x8017D204: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017D208: lui         $at, 0xBF00
    ctx->r1 = S32(0XBF00 << 16);
    // 0x8017D20C: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x8017D210: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8017D214: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8017D218: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8017D21C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017D220: addiu       $a3, $zero, 0x3C
    ctx->r7 = ADD32(0, 0X3C);
    // 0x8017D224: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    // 0x8017D228: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x8017D22C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8017D230: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    // 0x8017D234: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    // 0x8017D238: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x8017D23C: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x8017D240: jal         0x801716C8
    // 0x8017D244: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    func_801716C8_02FC30(rdram, ctx);
        goto after_23;
    // 0x8017D244: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    after_23:
L_8017D248:
    // 0x8017D248: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017D24C: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x8017D250: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017D254: lwc1        $f16, -0xEE0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0XEE0);
    // 0x8017D258: lwc1        $f10, 0xA0($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0XA0);
    // 0x8017D25C: c.le.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl <= ctx->f10.fl;
    // 0x8017D260: nop

    // 0x8017D264: bc1f        L_8017D6F4
    if (!c1cs) {
        // 0x8017D268: nop
    
            goto L_8017D6F4;
    }
    // 0x8017D268: nop

    // 0x8017D26C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8017D270: lw          $s0, -0x2E40($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X2E40);
    // 0x8017D274: beq         $s0, $zero, L_8017D29C
    if (ctx->r16 == 0) {
        // 0x8017D278: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8017D29C;
    }
    // 0x8017D278: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8017D27C: beq         $s0, $at, L_8017D3B4
    if (ctx->r16 == ctx->r1) {
        // 0x8017D280: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8017D3B4;
    }
    // 0x8017D280: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8017D284: beq         $s0, $at, L_8017D4CC
    if (ctx->r16 == ctx->r1) {
        // 0x8017D288: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8017D4CC;
    }
    // 0x8017D288: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8017D28C: beq         $s0, $at, L_8017D5E4
    if (ctx->r16 == ctx->r1) {
        // 0x8017D290: nop
    
            goto L_8017D5E4;
    }
    // 0x8017D290: nop

    // 0x8017D294: b           L_8017D6F4
    // 0x8017D298: nop

        goto L_8017D6F4;
    // 0x8017D298: nop

L_8017D29C:
    // 0x8017D29C: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x8017D2A0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017D2A4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8017D2A8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8017D2AC: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x8017D2B0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017D2B4: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x8017D2B8: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8017D2BC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8017D2C0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8017D2C4: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x8017D2C8: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8017D2CC: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    // 0x8017D2D0: lwc1        $f6, 0xA0($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0XA0);
    // 0x8017D2D4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017D2D8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8017D2DC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8017D2E0: div.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8017D2E4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017D2E8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8017D2EC: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x8017D2F0: sw          $t5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r13;
    // 0x8017D2F4: addiu       $a0, $a0, -0x1080
    ctx->r4 = ADD32(ctx->r4, -0X1080);
    // 0x8017D2F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8017D2FC: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    // 0x8017D300: addiu       $a3, $zero, 0xD2
    ctx->r7 = ADD32(0, 0XD2);
    // 0x8017D304: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    // 0x8017D308: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x8017D30C: swc1        $f18, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f18.u32l;
    // 0x8017D310: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x8017D314: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x8017D318: jal         0x801716C8
    // 0x8017D31C: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    func_801716C8_02FC30(rdram, ctx);
        goto after_24;
    // 0x8017D31C: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    after_24:
    // 0x8017D320: lui         $at, 0xC184
    ctx->r1 = S32(0XC184 << 16);
    // 0x8017D324: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017D328: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x8017D32C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8017D330: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8017D334: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8017D338: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017D33C: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x8017D340: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8017D344: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8017D348: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8017D34C: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x8017D350: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x8017D354: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x8017D358: lwc1        $f8, 0xA0($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0XA0);
    // 0x8017D35C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017D360: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8017D364: neg.s       $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = -ctx->f8.fl;
    // 0x8017D368: div.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8017D36C: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    // 0x8017D370: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8017D374: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8017D378: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8017D37C: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x8017D380: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x8017D384: addiu       $a0, $a0, -0x1078
    ctx->r4 = ADD32(ctx->r4, -0X1078);
    // 0x8017D388: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8017D38C: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    // 0x8017D390: addiu       $a3, $zero, 0x46
    ctx->r7 = ADD32(0, 0X46);
    // 0x8017D394: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x8017D398: swc1        $f16, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f16.u32l;
    // 0x8017D39C: swc1        $f18, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f18.u32l;
    // 0x8017D3A0: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    // 0x8017D3A4: jal         0x801716C8
    // 0x8017D3A8: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    func_801716C8_02FC30(rdram, ctx);
        goto after_25;
    // 0x8017D3A8: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    after_25:
    // 0x8017D3AC: b           L_8017D6F4
    // 0x8017D3B0: nop

        goto L_8017D6F4;
    // 0x8017D3B0: nop

L_8017D3B4:
    // 0x8017D3B4: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x8017D3B8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017D3BC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8017D3C0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017D3C4: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8017D3C8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017D3CC: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x8017D3D0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8017D3D4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8017D3D8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8017D3DC: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x8017D3E0: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8017D3E4: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x8017D3E8: lwc1        $f10, 0xA0($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0XA0);
    // 0x8017D3EC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8017D3F0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017D3F4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8017D3F8: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8017D3FC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8017D400: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8017D404: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x8017D408: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x8017D40C: addiu       $a0, $a0, -0x1070
    ctx->r4 = ADD32(ctx->r4, -0X1070);
    // 0x8017D410: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8017D414: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    // 0x8017D418: addiu       $a3, $zero, 0xD2
    ctx->r7 = ADD32(0, 0XD2);
    // 0x8017D41C: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    // 0x8017D420: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x8017D424: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x8017D428: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x8017D42C: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    // 0x8017D430: jal         0x801716C8
    // 0x8017D434: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    func_801716C8_02FC30(rdram, ctx);
        goto after_26;
    // 0x8017D434: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    after_26:
    // 0x8017D438: lui         $at, 0xC184
    ctx->r1 = S32(0XC184 << 16);
    // 0x8017D43C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8017D440: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x8017D444: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8017D448: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8017D44C: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x8017D450: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017D454: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x8017D458: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8017D45C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8017D460: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8017D464: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    // 0x8017D468: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    // 0x8017D46C: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x8017D470: lwc1        $f8, 0xA0($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0XA0);
    // 0x8017D474: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017D478: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8017D47C: neg.s       $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = -ctx->f8.fl;
    // 0x8017D480: div.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8017D484: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x8017D488: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017D48C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8017D490: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8017D494: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x8017D498: sw          $t4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r12;
    // 0x8017D49C: addiu       $a0, $a0, -0x1068
    ctx->r4 = ADD32(ctx->r4, -0X1068);
    // 0x8017D4A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8017D4A4: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    // 0x8017D4A8: addiu       $a3, $zero, 0x46
    ctx->r7 = ADD32(0, 0X46);
    // 0x8017D4AC: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x8017D4B0: swc1        $f18, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f18.u32l;
    // 0x8017D4B4: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x8017D4B8: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    // 0x8017D4BC: jal         0x801716C8
    // 0x8017D4C0: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    func_801716C8_02FC30(rdram, ctx);
        goto after_27;
    // 0x8017D4C0: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    after_27:
    // 0x8017D4C4: b           L_8017D6F4
    // 0x8017D4C8: nop

        goto L_8017D6F4;
    // 0x8017D4C8: nop

L_8017D4CC:
    // 0x8017D4CC: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x8017D4D0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017D4D4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8017D4D8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8017D4DC: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x8017D4E0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017D4E4: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x8017D4E8: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8017D4EC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8017D4F0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8017D4F4: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    // 0x8017D4F8: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8017D4FC: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x8017D500: lwc1        $f16, 0xA0($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0XA0);
    // 0x8017D504: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8017D508: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8017D50C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8017D510: div.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8017D514: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8017D518: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8017D51C: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8017D520: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x8017D524: addiu       $a0, $a0, -0x1060
    ctx->r4 = ADD32(ctx->r4, -0X1060);
    // 0x8017D528: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8017D52C: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    // 0x8017D530: addiu       $a3, $zero, 0xD2
    ctx->r7 = ADD32(0, 0XD2);
    // 0x8017D534: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x8017D538: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    // 0x8017D53C: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    // 0x8017D540: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x8017D544: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    // 0x8017D548: jal         0x801716C8
    // 0x8017D54C: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    func_801716C8_02FC30(rdram, ctx);
        goto after_28;
    // 0x8017D54C: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    after_28:
    // 0x8017D550: lui         $at, 0xC184
    ctx->r1 = S32(0XC184 << 16);
    // 0x8017D554: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8017D558: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x8017D55C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017D560: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8017D564: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8017D568: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017D56C: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x8017D570: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8017D574: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8017D578: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8017D57C: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    // 0x8017D580: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x8017D584: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x8017D588: lwc1        $f8, 0xA0($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0XA0);
    // 0x8017D58C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017D590: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017D594: neg.s       $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = -ctx->f8.fl;
    // 0x8017D598: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8017D59C: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x8017D5A0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8017D5A4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8017D5A8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8017D5AC: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x8017D5B0: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    // 0x8017D5B4: addiu       $a0, $a0, -0x1058
    ctx->r4 = ADD32(ctx->r4, -0X1058);
    // 0x8017D5B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8017D5BC: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    // 0x8017D5C0: addiu       $a3, $zero, 0x46
    ctx->r7 = ADD32(0, 0X46);
    // 0x8017D5C4: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x8017D5C8: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x8017D5CC: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    // 0x8017D5D0: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    // 0x8017D5D4: jal         0x801716C8
    // 0x8017D5D8: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    func_801716C8_02FC30(rdram, ctx);
        goto after_29;
    // 0x8017D5D8: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    after_29:
    // 0x8017D5DC: b           L_8017D6F4
    // 0x8017D5E0: nop

        goto L_8017D6F4;
    // 0x8017D5E0: nop

L_8017D5E4:
    // 0x8017D5E4: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x8017D5E8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8017D5EC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8017D5F0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8017D5F4: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x8017D5F8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017D5FC: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x8017D600: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8017D604: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8017D608: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8017D60C: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x8017D610: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8017D614: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x8017D618: lwc1        $f18, 0xA0($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0XA0);
    // 0x8017D61C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017D620: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8017D624: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8017D628: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8017D62C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8017D630: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8017D634: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x8017D638: sw          $t3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r11;
    // 0x8017D63C: addiu       $a0, $a0, -0x1050
    ctx->r4 = ADD32(ctx->r4, -0X1050);
    // 0x8017D640: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8017D644: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    // 0x8017D648: addiu       $a3, $zero, 0xD2
    ctx->r7 = ADD32(0, 0XD2);
    // 0x8017D64C: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    // 0x8017D650: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    // 0x8017D654: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    // 0x8017D658: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x8017D65C: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    // 0x8017D660: jal         0x801716C8
    // 0x8017D664: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    func_801716C8_02FC30(rdram, ctx);
        goto after_30;
    // 0x8017D664: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    after_30:
    // 0x8017D668: lui         $at, 0xC184
    ctx->r1 = S32(0XC184 << 16);
    // 0x8017D66C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017D670: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x8017D674: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017D678: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8017D67C: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x8017D680: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017D684: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x8017D688: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8017D68C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8017D690: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8017D694: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x8017D698: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x8017D69C: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    // 0x8017D6A0: lwc1        $f8, 0xA0($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0XA0);
    // 0x8017D6A4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8017D6A8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8017D6AC: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8017D6B0: div.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8017D6B4: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x8017D6B8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8017D6BC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017D6C0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8017D6C4: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x8017D6C8: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    // 0x8017D6CC: addiu       $a0, $a0, -0x1048
    ctx->r4 = ADD32(ctx->r4, -0X1048);
    // 0x8017D6D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8017D6D4: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    // 0x8017D6D8: addiu       $a3, $zero, 0x46
    ctx->r7 = ADD32(0, 0X46);
    // 0x8017D6DC: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x8017D6E0: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    // 0x8017D6E4: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    // 0x8017D6E8: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x8017D6EC: jal         0x801716C8
    // 0x8017D6F0: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    func_801716C8_02FC30(rdram, ctx);
        goto after_31;
    // 0x8017D6F0: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    after_31:
L_8017D6F4:
    // 0x8017D6F4: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x8017D6F8: ldc1        $f20, 0x48($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X48);
    // 0x8017D6FC: ldc1        $f22, 0x50($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X50);
    // 0x8017D700: lw          $s0, 0x58($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X58);
    // 0x8017D704: jr          $ra
    // 0x8017D708: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x8017D708: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_8017D70C_0EF7C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017D70C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8017D710: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8017D714: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8017D718: jal         0x800C7AD0
    // 0x8017D71C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800C7AD0(rdram, ctx);
        goto after_0;
    // 0x8017D71C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x8017D720: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x8017D724: jal         0x800C7A60
    // 0x8017D728: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C7A60(rdram, ctx);
        goto after_1;
    // 0x8017D728: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8017D72C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8017D730: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x8017D734: mtc1        $at, $f15
    ctx->f_odd[(15 - 1) * 2] = ctx->r1;
    // 0x8017D738: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8017D73C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8017D740: jal         0x800C7A88
    // 0x8017D744: nop

    func_800C7A88(rdram, ctx);
        goto after_2;
    // 0x8017D744: nop

    after_2:
    // 0x8017D748: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017D74C: addiu       $t6, $t6, -0x2E28
    ctx->r14 = ADD32(ctx->r14, -0X2E28);
    // 0x8017D750: lbu         $t7, 0xA($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0XA);
    // 0x8017D754: andi        $t8, $t7, 0x2
    ctx->r24 = ctx->r15 & 0X2;
    // 0x8017D758: beq         $t8, $zero, L_8017D94C
    if (ctx->r24 == 0) {
        // 0x8017D75C: nop
    
            goto L_8017D94C;
    }
    // 0x8017D75C: nop

    // 0x8017D760: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017D764: addiu       $t9, $t9, -0x2E18
    ctx->r25 = ADD32(ctx->r25, -0X2E18);
    // 0x8017D768: lw          $s0, 0x8($t9)
    ctx->r16 = MEM_W(ctx->r25, 0X8);
    // 0x8017D76C: beq         $s0, $zero, L_8017D794
    if (ctx->r16 == 0) {
        // 0x8017D770: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8017D794;
    }
    // 0x8017D770: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8017D774: beq         $s0, $at, L_8017D7E4
    if (ctx->r16 == ctx->r1) {
        // 0x8017D778: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8017D7E4;
    }
    // 0x8017D778: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8017D77C: beq         $s0, $at, L_8017D874
    if (ctx->r16 == ctx->r1) {
        // 0x8017D780: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8017D874;
    }
    // 0x8017D780: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8017D784: beq         $s0, $at, L_8017D904
    if (ctx->r16 == ctx->r1) {
        // 0x8017D788: nop
    
            goto L_8017D904;
    }
    // 0x8017D788: nop

    // 0x8017D78C: b           L_8017D94C
    // 0x8017D790: nop

        goto L_8017D94C;
    // 0x8017D790: nop

L_8017D794:
    // 0x8017D794: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017D798: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017D79C: addiu       $a1, $a1, -0x1040
    ctx->r5 = ADD32(ctx->r5, -0X1040);
    // 0x8017D7A0: jal         0x800D87E4
    // 0x8017D7A4: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_3;
    // 0x8017D7A4: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_3:
    // 0x8017D7A8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8017D7AC: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8017D7B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8017D7B4: jal         0x800C7A9C
    // 0x8017D7B8: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    func_800C7A9C(rdram, ctx);
        goto after_4;
    // 0x8017D7B8: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_4:
    // 0x8017D7BC: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    // 0x8017D7C0: jal         0x800C7A74
    // 0x8017D7C4: addiu       $a1, $zero, 0x190
    ctx->r5 = ADD32(0, 0X190);
    func_800C7A74(rdram, ctx);
        goto after_5;
    // 0x8017D7C4: addiu       $a1, $zero, 0x190
    ctx->r5 = ADD32(0, 0X190);
    after_5:
    // 0x8017D7C8: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8017D7CC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8017D7D0: addiu       $a1, $a1, 0x3B40
    ctx->r5 = ADD32(ctx->r5, 0X3B40);
    // 0x8017D7D4: jal         0x800C767C
    // 0x8017D7D8: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    func_800C767C(rdram, ctx);
        goto after_6;
    // 0x8017D7D8: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    after_6:
    // 0x8017D7DC: b           L_8017D94C
    // 0x8017D7E0: nop

        goto L_8017D94C;
    // 0x8017D7E0: nop

L_8017D7E4:
    // 0x8017D7E4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017D7E8: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017D7EC: addiu       $a1, $a1, -0x1024
    ctx->r5 = ADD32(ctx->r5, -0X1024);
    // 0x8017D7F0: jal         0x800D87E4
    // 0x8017D7F4: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_7;
    // 0x8017D7F4: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_7:
    // 0x8017D7F8: lui         $t0, 0x8011
    ctx->r8 = S32(0X8011 << 16);
    // 0x8017D7FC: lhu         $t0, -0x4530($t0)
    ctx->r8 = MEM_HU(ctx->r8, -0X4530);
    // 0x8017D800: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8017D804: andi        $t1, $t0, 0xF
    ctx->r9 = ctx->r8 & 0XF;
    // 0x8017D808: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8017D80C: lbu         $t2, -0x1128($t2)
    ctx->r10 = MEM_BU(ctx->r10, -0X1128);
    // 0x8017D810: slti        $at, $t2, 0x2
    ctx->r1 = SIGNED(ctx->r10) < 0X2 ? 1 : 0;
    // 0x8017D814: bne         $at, $zero, L_8017D838
    if (ctx->r1 != 0) {
        // 0x8017D818: nop
    
            goto L_8017D838;
    }
    // 0x8017D818: nop

    // 0x8017D81C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8017D820: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8017D824: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8017D828: jal         0x800C7A9C
    // 0x8017D82C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    func_800C7A9C(rdram, ctx);
        goto after_8;
    // 0x8017D82C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_8:
    // 0x8017D830: b           L_8017D84C
    // 0x8017D834: nop

        goto L_8017D84C;
    // 0x8017D834: nop

L_8017D838:
    // 0x8017D838: addiu       $a0, $zero, 0xB4
    ctx->r4 = ADD32(0, 0XB4);
    // 0x8017D83C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8017D840: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8017D844: jal         0x800C7A9C
    // 0x8017D848: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    func_800C7A9C(rdram, ctx);
        goto after_9;
    // 0x8017D848: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_9:
L_8017D84C:
    // 0x8017D84C: addiu       $a0, $zero, 0x88
    ctx->r4 = ADD32(0, 0X88);
    // 0x8017D850: jal         0x800C7A74
    // 0x8017D854: addiu       $a1, $zero, 0x190
    ctx->r5 = ADD32(0, 0X190);
    func_800C7A74(rdram, ctx);
        goto after_10;
    // 0x8017D854: addiu       $a1, $zero, 0x190
    ctx->r5 = ADD32(0, 0X190);
    after_10:
    // 0x8017D858: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8017D85C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8017D860: addiu       $a1, $a1, 0x3B40
    ctx->r5 = ADD32(ctx->r5, 0X3B40);
    // 0x8017D864: jal         0x800C767C
    // 0x8017D868: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    func_800C767C(rdram, ctx);
        goto after_11;
    // 0x8017D868: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    after_11:
    // 0x8017D86C: b           L_8017D94C
    // 0x8017D870: nop

        goto L_8017D94C;
    // 0x8017D870: nop

L_8017D874:
    // 0x8017D874: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017D878: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017D87C: addiu       $a1, $a1, -0x100C
    ctx->r5 = ADD32(ctx->r5, -0X100C);
    // 0x8017D880: jal         0x800D87E4
    // 0x8017D884: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_12;
    // 0x8017D884: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_12:
    // 0x8017D888: lui         $t3, 0x8011
    ctx->r11 = S32(0X8011 << 16);
    // 0x8017D88C: lhu         $t3, -0x4530($t3)
    ctx->r11 = MEM_HU(ctx->r11, -0X4530);
    // 0x8017D890: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8017D894: andi        $t4, $t3, 0xF
    ctx->r12 = ctx->r11 & 0XF;
    // 0x8017D898: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8017D89C: lbu         $t5, -0x1128($t5)
    ctx->r13 = MEM_BU(ctx->r13, -0X1128);
    // 0x8017D8A0: slti        $at, $t5, 0x2
    ctx->r1 = SIGNED(ctx->r13) < 0X2 ? 1 : 0;
    // 0x8017D8A4: bne         $at, $zero, L_8017D8C8
    if (ctx->r1 != 0) {
        // 0x8017D8A8: nop
    
            goto L_8017D8C8;
    }
    // 0x8017D8A8: nop

    // 0x8017D8AC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8017D8B0: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8017D8B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8017D8B8: jal         0x800C7A9C
    // 0x8017D8BC: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    func_800C7A9C(rdram, ctx);
        goto after_13;
    // 0x8017D8BC: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_13:
    // 0x8017D8C0: b           L_8017D8DC
    // 0x8017D8C4: nop

        goto L_8017D8DC;
    // 0x8017D8C4: nop

L_8017D8C8:
    // 0x8017D8C8: addiu       $a0, $zero, 0xB4
    ctx->r4 = ADD32(0, 0XB4);
    // 0x8017D8CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8017D8D0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8017D8D4: jal         0x800C7A9C
    // 0x8017D8D8: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    func_800C7A9C(rdram, ctx);
        goto after_14;
    // 0x8017D8D8: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_14:
L_8017D8DC:
    // 0x8017D8DC: addiu       $a0, $zero, 0x50
    ctx->r4 = ADD32(0, 0X50);
    // 0x8017D8E0: jal         0x800C7A74
    // 0x8017D8E4: addiu       $a1, $zero, 0x190
    ctx->r5 = ADD32(0, 0X190);
    func_800C7A74(rdram, ctx);
        goto after_15;
    // 0x8017D8E4: addiu       $a1, $zero, 0x190
    ctx->r5 = ADD32(0, 0X190);
    after_15:
    // 0x8017D8E8: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8017D8EC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8017D8F0: addiu       $a1, $a1, 0x3B40
    ctx->r5 = ADD32(ctx->r5, 0X3B40);
    // 0x8017D8F4: jal         0x800C767C
    // 0x8017D8F8: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    func_800C767C(rdram, ctx);
        goto after_16;
    // 0x8017D8F8: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    after_16:
    // 0x8017D8FC: b           L_8017D94C
    // 0x8017D900: nop

        goto L_8017D94C;
    // 0x8017D900: nop

L_8017D904:
    // 0x8017D904: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017D908: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017D90C: addiu       $a1, $a1, -0xFEC
    ctx->r5 = ADD32(ctx->r5, -0XFEC);
    // 0x8017D910: jal         0x800D87E4
    // 0x8017D914: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_17;
    // 0x8017D914: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_17:
    // 0x8017D918: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8017D91C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8017D920: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8017D924: jal         0x800C7A9C
    // 0x8017D928: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    func_800C7A9C(rdram, ctx);
        goto after_18;
    // 0x8017D928: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_18:
    // 0x8017D92C: addiu       $a0, $zero, 0x68
    ctx->r4 = ADD32(0, 0X68);
    // 0x8017D930: jal         0x800C7A74
    // 0x8017D934: addiu       $a1, $zero, 0x190
    ctx->r5 = ADD32(0, 0X190);
    func_800C7A74(rdram, ctx);
        goto after_19;
    // 0x8017D934: addiu       $a1, $zero, 0x190
    ctx->r5 = ADD32(0, 0X190);
    after_19:
    // 0x8017D938: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8017D93C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8017D940: addiu       $a1, $a1, 0x3B40
    ctx->r5 = ADD32(ctx->r5, 0X3B40);
    // 0x8017D944: jal         0x800C767C
    // 0x8017D948: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    func_800C767C(rdram, ctx);
        goto after_20;
    // 0x8017D948: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    after_20:
L_8017D94C:
    // 0x8017D94C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8017D950: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x8017D954: mtc1        $at, $f15
    ctx->f_odd[(15 - 1) * 2] = ctx->r1;
    // 0x8017D958: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8017D95C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8017D960: jal         0x800C7A88
    // 0x8017D964: nop

    func_800C7A88(rdram, ctx);
        goto after_21;
    // 0x8017D964: nop

    after_21:
    // 0x8017D968: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    // 0x8017D96C: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    // 0x8017D970: addiu       $a2, $zero, 0xC8
    ctx->r6 = ADD32(0, 0XC8);
    // 0x8017D974: jal         0x800C7A9C
    // 0x8017D978: addiu       $a3, $zero, 0xC8
    ctx->r7 = ADD32(0, 0XC8);
    func_800C7A9C(rdram, ctx);
        goto after_22;
    // 0x8017D978: addiu       $a3, $zero, 0xC8
    ctx->r7 = ADD32(0, 0XC8);
    after_22:
    // 0x8017D97C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017D980: addiu       $t6, $t6, 0x3B00
    ctx->r14 = ADD32(ctx->r14, 0X3B00);
    // 0x8017D984: lbu         $t7, 0x14($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X14);
    // 0x8017D988: bne         $t7, $zero, L_8017D9AC
    if (ctx->r15 != 0) {
        // 0x8017D98C: nop
    
            goto L_8017D9AC;
    }
    // 0x8017D98C: nop

    // 0x8017D990: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017D994: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017D998: addiu       $a1, $a1, -0xFD0
    ctx->r5 = ADD32(ctx->r5, -0XFD0);
    // 0x8017D99C: jal         0x800D87E4
    // 0x8017D9A0: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_23;
    // 0x8017D9A0: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_23:
    // 0x8017D9A4: b           L_8017D9C0
    // 0x8017D9A8: nop

        goto L_8017D9C0;
    // 0x8017D9A8: nop

L_8017D9AC:
    // 0x8017D9AC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017D9B0: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017D9B4: addiu       $a1, $a1, -0xFBC
    ctx->r5 = ADD32(ctx->r5, -0XFBC);
    // 0x8017D9B8: jal         0x800D87E4
    // 0x8017D9BC: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_24;
    // 0x8017D9BC: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_24:
L_8017D9C0:
    // 0x8017D9C0: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    // 0x8017D9C4: jal         0x800C7A74
    // 0x8017D9C8: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    func_800C7A74(rdram, ctx);
        goto after_25;
    // 0x8017D9C8: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    after_25:
    // 0x8017D9CC: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8017D9D0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8017D9D4: addiu       $a1, $a1, 0x3B40
    ctx->r5 = ADD32(ctx->r5, 0X3B40);
    // 0x8017D9D8: jal         0x800C767C
    // 0x8017D9DC: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    func_800C767C(rdram, ctx);
        goto after_26;
    // 0x8017D9DC: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    after_26:
    // 0x8017D9E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8017D9E4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8017D9E8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8017D9EC: jr          $ra
    // 0x8017D9F0: nop

    return;
    // 0x8017D9F0: nop

    // 0x8017D9F4: nop

    // 0x8017D9F8: nop

    // 0x8017D9FC: nop

;}
RECOMP_FUNC void func_8017DA00_0EF7C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017DA00: addiu       $t6, $zero, 0xC
    ctx->r14 = ADD32(0, 0XC);
    // 0x8017DA04: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017DA08: sw          $t6, -0x2E50($at)
    MEM_W(-0X2E50, ctx->r1) = ctx->r14;
    // 0x8017DA0C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017DA10: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017DA14: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017DA18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017DA1C: addiu       $t7, $t7, -0x2E28
    ctx->r15 = ADD32(ctx->r15, -0X2E28);
    // 0x8017DA20: sw          $zero, -0x2E4C($at)
    MEM_W(-0X2E4C, ctx->r1) = 0;
    // 0x8017DA24: lbu         $t8, 0xA($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0XA);
    // 0x8017DA28: addiu       $a0, $zero, 0x280
    ctx->r4 = ADD32(0, 0X280);
    // 0x8017DA2C: addiu       $a1, $zero, 0x1A4
    ctx->r5 = ADD32(0, 0X1A4);
    // 0x8017DA30: andi        $t9, $t8, 0xFD
    ctx->r25 = ctx->r24 & 0XFD;
    // 0x8017DA34: jal         0x800C30F4
    // 0x8017DA38: sb          $t9, 0xA($t7)
    MEM_B(0XA, ctx->r15) = ctx->r25;
    func_800C30F4(rdram, ctx);
        goto after_0;
    // 0x8017DA38: sb          $t9, 0xA($t7)
    MEM_B(0XA, ctx->r15) = ctx->r25;
    after_0:
    // 0x8017DA3C: jal         0x8017DB94
    // 0x8017DA40: nop

    func_8017DB94_0EF7C0(rdram, ctx);
        goto after_1;
    // 0x8017DA40: nop

    after_1:
    // 0x8017DA44: jal         0x800C328C
    // 0x8017DA48: nop

    func_800C328C(rdram, ctx);
        goto after_2;
    // 0x8017DA48: nop

    after_2:
    // 0x8017DA4C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8017DA50: jal         0x800D1640
    // 0x8017DA54: addiu       $a0, $a0, -0x254C
    ctx->r4 = ADD32(ctx->r4, -0X254C);
    func_800D1640(rdram, ctx);
        goto after_3;
    // 0x8017DA54: addiu       $a0, $a0, -0x254C
    ctx->r4 = ADD32(ctx->r4, -0X254C);
    after_3:
L_8017DA58:
    // 0x8017DA58: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017DA5C: lw          $t0, -0x2E4C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2E4C);
    // 0x8017DA60: beq         $t0, $zero, L_8017DA58
    if (ctx->r8 == 0) {
        // 0x8017DA64: nop
    
            goto L_8017DA58;
    }
    // 0x8017DA64: nop

    // 0x8017DA68: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x8017DA6C: lhu         $t1, -0x4530($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X4530);
    // 0x8017DA70: andi        $t2, $t1, 0x2000
    ctx->r10 = ctx->r9 & 0X2000;
    // 0x8017DA74: bne         $t2, $zero, L_8017DA58
    if (ctx->r10 != 0) {
        // 0x8017DA78: nop
    
            goto L_8017DA58;
    }
    // 0x8017DA78: nop

    // 0x8017DA7C: jal         0x800CB720
    // 0x8017DA80: nop

    func_800CB720(rdram, ctx);
        goto after_4;
    // 0x8017DA80: nop

    after_4:
    // 0x8017DA84: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8017DA88: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x8017DA8C: bne         $t3, $zero, L_8017DA58
    if (ctx->r11 != 0) {
        // 0x8017DA90: nop
    
            goto L_8017DA58;
    }
    // 0x8017DA90: nop

    // 0x8017DA94: jal         0x800C6DD4
    // 0x8017DA98: nop

    func_800C6DD4(rdram, ctx);
        goto after_5;
    // 0x8017DA98: nop

    after_5:
    // 0x8017DA9C: jal         0x800C7154
    // 0x8017DAA0: nop

    func_800C7154(rdram, ctx);
        goto after_6;
    // 0x8017DAA0: nop

    after_6:
    // 0x8017DAA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017DAA8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017DAAC: jr          $ra
    // 0x8017DAB0: nop

    return;
    // 0x8017DAB0: nop

;}
RECOMP_FUNC void func_8017DAB4_0EF7C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017DAB4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017DAB8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8017DABC: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8017DAC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017DAC4: bgtz        $t6, L_8017DB84
    if (SIGNED(ctx->r14) > 0) {
        // 0x8017DAC8: nop
    
            goto L_8017DB84;
    }
    // 0x8017DAC8: nop

    // 0x8017DACC: jal         0x800C3704
    // 0x8017DAD0: nop

    func_800C3704(rdram, ctx);
        goto after_0;
    // 0x8017DAD0: nop

    after_0:
    // 0x8017DAD4: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x8017DAD8: lw          $t7, -0x4514($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4514);
    // 0x8017DADC: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8017DAE0: lui         $t9, 0xDB06
    ctx->r25 = S32(0XDB06 << 16);
    // 0x8017DAE4: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x8017DAE8: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8017DAEC: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8017DAF0: sw          $t8, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r24;
    // 0x8017DAF4: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x8017DAF8: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8017DAFC: jal         0x800C7458
    // 0x8017DB00: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    func_800C7458(rdram, ctx);
        goto after_1;
    // 0x8017DB00: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    after_1:
    // 0x8017DB04: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8017DB08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8017DB0C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8017DB10: jal         0x800C25FC
    // 0x8017DB14: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800C25FC(rdram, ctx);
        goto after_2;
    // 0x8017DB14: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x8017DB18: jal         0x800C3578
    // 0x8017DB1C: nop

    func_800C3578(rdram, ctx);
        goto after_3;
    // 0x8017DB1C: nop

    after_3:
    // 0x8017DB20: jal         0x8017DD44
    // 0x8017DB24: nop

    func_8017DD44_0EF7C0(rdram, ctx);
        goto after_4;
    // 0x8017DB24: nop

    after_4:
    // 0x8017DB28: jal         0x8017E3E0
    // 0x8017DB2C: nop

    func_8017E3E0_0EF7C0(rdram, ctx);
        goto after_5;
    // 0x8017DB2C: nop

    after_5:
    // 0x8017DB30: jal         0x800C3FD0
    // 0x8017DB34: nop

    func_800C3FD0(rdram, ctx);
        goto after_6;
    // 0x8017DB34: nop

    after_6:
    // 0x8017DB38: jal         0x800C3760
    // 0x8017DB3C: nop

    func_800C3760(rdram, ctx);
        goto after_7;
    // 0x8017DB3C: nop

    after_7:
    // 0x8017DB40: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017DB44: lw          $t2, -0x2E4C($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2E4C);
    // 0x8017DB48: beq         $t2, $zero, L_8017DB84
    if (ctx->r10 == 0) {
        // 0x8017DB4C: nop
    
            goto L_8017DB84;
    }
    // 0x8017DB4C: nop

    // 0x8017DB50: lui         $t3, 0x8011
    ctx->r11 = S32(0X8011 << 16);
    // 0x8017DB54: lhu         $t3, -0x4530($t3)
    ctx->r11 = MEM_HU(ctx->r11, -0X4530);
    // 0x8017DB58: andi        $t4, $t3, 0x2000
    ctx->r12 = ctx->r11 & 0X2000;
    // 0x8017DB5C: bne         $t4, $zero, L_8017DB84
    if (ctx->r12 != 0) {
        // 0x8017DB60: nop
    
            goto L_8017DB84;
    }
    // 0x8017DB60: nop

    // 0x8017DB64: jal         0x800CB720
    // 0x8017DB68: nop

    func_800CB720(rdram, ctx);
        goto after_8;
    // 0x8017DB68: nop

    after_8:
    // 0x8017DB6C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8017DB70: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x8017DB74: bne         $t5, $zero, L_8017DB84
    if (ctx->r13 != 0) {
        // 0x8017DB78: nop
    
            goto L_8017DB84;
    }
    // 0x8017DB78: nop

    // 0x8017DB7C: jal         0x800D1640
    // 0x8017DB80: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800D1640(rdram, ctx);
        goto after_9;
    // 0x8017DB80: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_9:
L_8017DB84:
    // 0x8017DB84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017DB88: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017DB8C: jr          $ra
    // 0x8017DB90: nop

    return;
    // 0x8017DB90: nop

;}
RECOMP_FUNC void func_8017DB94_0EF7C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017DB94: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8017DB98: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017DB9C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8017DBA0: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8017DBA4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8017DBA8: addiu       $t6, $t6, 0x3C00
    ctx->r14 = ADD32(ctx->r14, 0X3C00);
    // 0x8017DBAC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017DBB0: addiu       $t7, $t7, 0x3C00
    ctx->r15 = ADD32(ctx->r15, 0X3C00);
    // 0x8017DBB4: sw          $zero, 0xC($t6)
    MEM_W(0XC, ctx->r14) = 0;
    // 0x8017DBB8: lw          $s1, 0xC($t7)
    ctx->r17 = MEM_W(ctx->r15, 0XC);
    // 0x8017DBBC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017DBC0: addiu       $t8, $t8, 0x3C00
    ctx->r24 = ADD32(ctx->r24, 0X3C00);
    // 0x8017DBC4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017DBC8: sw          $s1, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r17;
    // 0x8017DBCC: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x8017DBD0: sw          $s0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r16;
    // 0x8017DBD4: addiu       $t9, $t9, 0x3C00
    ctx->r25 = ADD32(ctx->r25, 0X3C00);
    // 0x8017DBD8: sw          $s0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r16;
    // 0x8017DBDC: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
L_8017DBE0:
    // 0x8017DBE0: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8017DBE4: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x8017DBE8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017DBEC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017DBF0: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8017DBF4: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8017DBF8: addiu       $t4, $t4, 0x3C00
    ctx->r12 = ADD32(ctx->r12, 0X3C00);
    // 0x8017DBFC: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8017DC00: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8017DC04: sw          $zero, 0x3C50($at)
    MEM_W(0X3C50, ctx->r1) = 0;
    // 0x8017DC08: lw          $t6, 0x50($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X50);
    // 0x8017DC0C: sw          $t6, 0x28($t5)
    MEM_W(0X28, ctx->r13) = ctx->r14;
    // 0x8017DC10: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8017DC14: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8017DC18: sltiu       $at, $t8, 0xA
    ctx->r1 = ctx->r24 < 0XA ? 1 : 0;
    // 0x8017DC1C: bne         $at, $zero, L_8017DBE0
    if (ctx->r1 != 0) {
        // 0x8017DC20: sw          $t8, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r24;
            goto L_8017DBE0;
    }
    // 0x8017DC20: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    // 0x8017DC24: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017DC28: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017DC2C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8017DC30: addiu       $t0, $t0, 0x3B00
    ctx->r8 = ADD32(ctx->r8, 0X3B00);
    // 0x8017DC34: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8017DC38: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017DC3C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8017DC40: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8017DC44: sb          $t9, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r25;
    // 0x8017DC48: addiu       $t1, $t1, -0x4198
    ctx->r9 = ADD32(ctx->r9, -0X4198);
    // 0x8017DC4C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017DC50: addiu       $t2, $t2, -0x4198
    ctx->r10 = ADD32(ctx->r10, -0X4198);
    // 0x8017DC54: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017DC58: swc1        $f4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f4.u32l;
    // 0x8017DC5C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8017DC60: addiu       $t3, $t3, -0x4198
    ctx->r11 = ADD32(ctx->r11, -0X4198);
    // 0x8017DC64: swc1        $f6, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->f6.u32l;
    // 0x8017DC68: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8017DC6C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017DC70: swc1        $f8, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f8.u32l;
    // 0x8017DC74: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8017DC78: addiu       $t4, $t4, -0x4198
    ctx->r12 = ADD32(ctx->r12, -0X4198);
    // 0x8017DC7C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017DC80: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017DC84: addiu       $t6, $t6, -0x4198
    ctx->r14 = ADD32(ctx->r14, -0X4198);
    // 0x8017DC88: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017DC8C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017DC90: swc1        $f10, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->f10.u32l;
    // 0x8017DC94: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017DC98: addiu       $t5, $t5, -0x4198
    ctx->r13 = ADD32(ctx->r13, -0X4198);
    // 0x8017DC9C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017DCA0: swc1        $f16, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->f16.u32l;
    // 0x8017DCA4: addiu       $t7, $t7, -0x4198
    ctx->r15 = ADD32(ctx->r15, -0X4198);
    // 0x8017DCA8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017DCAC: swc1        $f18, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->f18.u32l;
    // 0x8017DCB0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8017DCB4: addiu       $t8, $t8, -0x4198
    ctx->r24 = ADD32(ctx->r24, -0X4198);
    // 0x8017DCB8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017DCBC: swc1        $f4, 0x18($t7)
    MEM_W(0X18, ctx->r15) = ctx->f4.u32l;
    // 0x8017DCC0: addiu       $t9, $t9, -0x4198
    ctx->r25 = ADD32(ctx->r25, -0X4198);
    // 0x8017DCC4: swc1        $f6, 0x1C($t8)
    MEM_W(0X1C, ctx->r24) = ctx->f6.u32l;
    // 0x8017DCC8: jal         0x800C3FD0
    // 0x8017DCCC: swc1        $f8, 0x20($t9)
    MEM_W(0X20, ctx->r25) = ctx->f8.u32l;
    func_800C3FD0(rdram, ctx);
        goto after_0;
    // 0x8017DCCC: swc1        $f8, 0x20($t9)
    MEM_W(0X20, ctx->r25) = ctx->f8.u32l;
    after_0:
    // 0x8017DCD0: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    // 0x8017DCD4: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    // 0x8017DCD8: jal         0x800C6E0C
    // 0x8017DCDC: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    func_800C6E0C(rdram, ctx);
        goto after_1;
    // 0x8017DCDC: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    after_1:
    // 0x8017DCE0: addiu       $t0, $zero, 0x32
    ctx->r8 = ADD32(0, 0X32);
    // 0x8017DCE4: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x8017DCE8: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8017DCEC: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8017DCF0: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    // 0x8017DCF4: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    // 0x8017DCF8: addiu       $a2, $zero, 0xC8
    ctx->r6 = ADD32(0, 0XC8);
    // 0x8017DCFC: jal         0x800C6E68
    // 0x8017DD00: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800C6E68(rdram, ctx);
        goto after_2;
    // 0x8017DD00: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x8017DD04: addiu       $t2, $zero, 0x3E3
    ctx->r10 = ADD32(0, 0X3E3);
    // 0x8017DD08: addiu       $t3, $zero, 0x3E8
    ctx->r11 = ADD32(0, 0X3E8);
    // 0x8017DD0C: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x8017DD10: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8017DD14: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8017DD18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8017DD1C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8017DD20: jal         0x800C70C0
    // 0x8017DD24: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    func_800C70C0(rdram, ctx);
        goto after_3;
    // 0x8017DD24: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_3:
    // 0x8017DD28: jal         0x800C6DBC
    // 0x8017DD2C: nop

    func_800C6DBC(rdram, ctx);
        goto after_4;
    // 0x8017DD2C: nop

    after_4:
    // 0x8017DD30: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8017DD34: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8017DD38: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8017DD3C: jr          $ra
    // 0x8017DD40: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8017DD40: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8017DD44_0EF7C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017DD44: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017DD48: lw          $t6, -0x2E4C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2E4C);
    // 0x8017DD4C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8017DD50: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8017DD54: bne         $t6, $zero, L_8017E3CC
    if (ctx->r14 != 0) {
        // 0x8017DD58: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_8017E3CC;
    }
    // 0x8017DD58: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8017DD5C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017DD60: addiu       $t7, $t7, 0x3C00
    ctx->r15 = ADD32(ctx->r15, 0X3C00);
    // 0x8017DD64: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x8017DD68: beq         $t8, $zero, L_8017DE28
    if (ctx->r24 == 0) {
        // 0x8017DD6C: nop
    
            goto L_8017DE28;
    }
    // 0x8017DD6C: nop

    // 0x8017DD70: lw          $s0, 0x8($t7)
    ctx->r16 = MEM_W(ctx->r15, 0X8);
    // 0x8017DD74: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8017DD78: beq         $s0, $at, L_8017DDA0
    if (ctx->r16 == ctx->r1) {
        // 0x8017DD7C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8017DDA0;
    }
    // 0x8017DD7C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8017DD80: beq         $s0, $at, L_8017DDA0
    if (ctx->r16 == ctx->r1) {
        // 0x8017DD84: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8017DDA0;
    }
    // 0x8017DD84: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8017DD88: beq         $s0, $at, L_8017DDA0
    if (ctx->r16 == ctx->r1) {
        // 0x8017DD8C: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_8017DDA0;
    }
    // 0x8017DD8C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8017DD90: beq         $s0, $at, L_8017DDB8
    if (ctx->r16 == ctx->r1) {
        // 0x8017DD94: nop
    
            goto L_8017DDB8;
    }
    // 0x8017DD94: nop

    // 0x8017DD98: b           L_8017E3CC
    // 0x8017DD9C: nop

        goto L_8017E3CC;
    // 0x8017DD9C: nop

L_8017DDA0:
    // 0x8017DDA0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017DDA4: addiu       $t9, $t9, 0x3C00
    ctx->r25 = ADD32(ctx->r25, 0X3C00);
    // 0x8017DDA8: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x8017DDAC: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x8017DDB0: b           L_8017E3CC
    // 0x8017DDB4: sw          $t1, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->r9;
        goto L_8017E3CC;
    // 0x8017DDB4: sw          $t1, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->r9;
L_8017DDB8:
    // 0x8017DDB8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017DDBC: lw          $t2, -0x2E3C($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2E3C);
    // 0x8017DDC0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8017DDC4: beq         $t2, $zero, L_8017E3CC
    if (ctx->r10 == 0) {
        // 0x8017DDC8: nop
    
            goto L_8017E3CC;
    }
    // 0x8017DDC8: nop

L_8017DDCC:
    // 0x8017DDCC: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8017DDD0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017DDD4: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8017DDD8: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8017DDDC: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x8017DDE0: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8017DDE4: lhu         $t5, -0x41DE($t5)
    ctx->r13 = MEM_HU(ctx->r13, -0X41DE);
    // 0x8017DDE8: andi        $t6, $t5, 0xB000
    ctx->r14 = ctx->r13 & 0XB000;
    // 0x8017DDEC: beq         $t6, $zero, L_8017DE00
    if (ctx->r14 == 0) {
        // 0x8017DDF0: nop
    
            goto L_8017DE00;
    }
    // 0x8017DDF0: nop

    // 0x8017DDF4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017DDF8: addiu       $t8, $t8, 0x3C00
    ctx->r24 = ADD32(ctx->r24, 0X3C00);
    // 0x8017DDFC: sw          $zero, 0xC($t8)
    MEM_W(0XC, ctx->r24) = 0;
L_8017DE00:
    // 0x8017DE00: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8017DE04: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017DE08: lw          $t1, -0x2E3C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2E3C);
    // 0x8017DE0C: addiu       $t0, $t7, 0x1
    ctx->r8 = ADD32(ctx->r15, 0X1);
    // 0x8017DE10: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x8017DE14: sltu        $at, $t0, $t1
    ctx->r1 = ctx->r8 < ctx->r9 ? 1 : 0;
    // 0x8017DE18: bne         $at, $zero, L_8017DDCC
    if (ctx->r1 != 0) {
        // 0x8017DE1C: nop
    
            goto L_8017DDCC;
    }
    // 0x8017DE1C: nop

    // 0x8017DE20: b           L_8017E3CC
    // 0x8017DE24: nop

        goto L_8017E3CC;
    // 0x8017DE24: nop

L_8017DE28:
    // 0x8017DE28: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017DE2C: addiu       $t9, $t9, 0x3C00
    ctx->r25 = ADD32(ctx->r25, 0X3C00);
    // 0x8017DE30: lw          $t2, 0x0($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X0);
    // 0x8017DE34: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8017DE38: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017DE3C: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8017DE40: lbu         $t3, -0xED0($t3)
    ctx->r11 = MEM_BU(ctx->r11, -0XED0);
    // 0x8017DE44: addiu       $t4, $t4, 0x3C00
    ctx->r12 = ADD32(ctx->r12, 0X3C00);
    // 0x8017DE48: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017DE4C: sw          $t3, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r11;
    // 0x8017DE50: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x8017DE54: addiu       $t8, $t8, 0x3C00
    ctx->r24 = ADD32(ctx->r24, 0X3C00);
    // 0x8017DE58: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8017DE5C: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x8017DE60: lw          $s0, 0x8($t8)
    ctx->r16 = MEM_W(ctx->r24, 0X8);
    // 0x8017DE64: sltiu       $at, $s0, 0x4
    ctx->r1 = ctx->r16 < 0X4 ? 1 : 0;
    // 0x8017DE68: bne         $at, $zero, L_8017DED0
    if (ctx->r1 != 0) {
        // 0x8017DE6C: sltiu       $at, $s0, 0x65
        ctx->r1 = ctx->r16 < 0X65 ? 1 : 0;
            goto L_8017DED0;
    }
    // 0x8017DE6C: sltiu       $at, $s0, 0x65
    ctx->r1 = ctx->r16 < 0X65 ? 1 : 0;
    // 0x8017DE70: bne         $at, $zero, L_8017DE88
    if (ctx->r1 != 0) {
        // 0x8017DE74: addiu       $at, $zero, 0xFF
        ctx->r1 = ADD32(0, 0XFF);
            goto L_8017DE88;
    }
    // 0x8017DE74: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8017DE78: beq         $s0, $at, L_8017DEF4
    if (ctx->r16 == ctx->r1) {
        // 0x8017DE7C: nop
    
            goto L_8017DEF4;
    }
    // 0x8017DE7C: nop

    // 0x8017DE80: b           L_8017E3CC
    // 0x8017DE84: nop

        goto L_8017E3CC;
    // 0x8017DE84: nop

L_8017DE88:
    // 0x8017DE88: sltiu       $at, $s0, 0xB
    ctx->r1 = ctx->r16 < 0XB ? 1 : 0;
    // 0x8017DE8C: bne         $at, $zero, L_8017DEBC
    if (ctx->r1 != 0) {
        // 0x8017DE90: nop
    
            goto L_8017DEBC;
    }
    // 0x8017DE90: nop

    // 0x8017DE94: addiu       $t7, $s0, -0x50
    ctx->r15 = ADD32(ctx->r16, -0X50);
    // 0x8017DE98: sltiu       $at, $t7, 0x15
    ctx->r1 = ctx->r15 < 0X15 ? 1 : 0;
    // 0x8017DE9C: beq         $at, $zero, L_8017E3CC
    if (ctx->r1 == 0) {
        // 0x8017DEA0: nop
    
            goto L_8017E3CC;
    }
    // 0x8017DEA0: nop

    // 0x8017DEA4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017DEA8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017DEAC: addu        $at, $at, $t7
    gpr jr_addend_8017DEB4 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8017DEB0: lw          $t7, -0xCF4($at)
    ctx->r15 = ADD32(ctx->r1, -0XCF4);
    // 0x8017DEB4: jr          $t7
    // 0x8017DEB8: nop

    switch (jr_addend_8017DEB4 >> 2) {
        case 0: goto L_8017DF5C; break;
        case 1: goto L_8017E040; break;
        case 2: goto L_8017E11C; break;
        case 3: goto L_8017E1E0; break;
        case 4: goto L_8017E2A4; break;
        case 5: goto L_8017E3CC; break;
        case 6: goto L_8017E3CC; break;
        case 7: goto L_8017E3CC; break;
        case 8: goto L_8017E3CC; break;
        case 9: goto L_8017E3CC; break;
        case 10: goto L_8017E3CC; break;
        case 11: goto L_8017E3CC; break;
        case 12: goto L_8017E3CC; break;
        case 13: goto L_8017E3CC; break;
        case 14: goto L_8017E3CC; break;
        case 15: goto L_8017E3CC; break;
        case 16: goto L_8017E3CC; break;
        case 17: goto L_8017E3CC; break;
        case 18: goto L_8017E3CC; break;
        case 19: goto L_8017E3CC; break;
        case 20: goto L_8017E3A8; break;
        default: switch_error(__func__, 0x8017DEB4, 0x8017F30C);
    }
    // 0x8017DEB8: nop

L_8017DEBC:
    // 0x8017DEBC: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8017DEC0: beq         $s0, $at, L_8017DF48
    if (ctx->r16 == ctx->r1) {
        // 0x8017DEC4: nop
    
            goto L_8017DF48;
    }
    // 0x8017DEC4: nop

    // 0x8017DEC8: b           L_8017E3CC
    // 0x8017DECC: nop

        goto L_8017E3CC;
    // 0x8017DECC: nop

L_8017DED0:
    // 0x8017DED0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8017DED4: beq         $s0, $at, L_8017DF0C
    if (ctx->r16 == ctx->r1) {
        // 0x8017DED8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8017DF0C;
    }
    // 0x8017DED8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8017DEDC: beq         $s0, $at, L_8017DF20
    if (ctx->r16 == ctx->r1) {
        // 0x8017DEE0: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8017DF20;
    }
    // 0x8017DEE0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8017DEE4: beq         $s0, $at, L_8017DF34
    if (ctx->r16 == ctx->r1) {
        // 0x8017DEE8: nop
    
            goto L_8017DF34;
    }
    // 0x8017DEE8: nop

    // 0x8017DEEC: b           L_8017E3CC
    // 0x8017DEF0: nop

        goto L_8017E3CC;
    // 0x8017DEF0: nop

L_8017DEF4:
    // 0x8017DEF4: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8017DEF8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017DEFC: jal         0x800C32CC
    // 0x8017DF00: sw          $t0, -0x2E4C($at)
    MEM_W(-0X2E4C, ctx->r1) = ctx->r8;
    func_800C32CC(rdram, ctx);
        goto after_0;
    // 0x8017DF00: sw          $t0, -0x2E4C($at)
    MEM_W(-0X2E4C, ctx->r1) = ctx->r8;
    after_0:
    // 0x8017DF04: b           L_8017E3CC
    // 0x8017DF08: nop

        goto L_8017E3CC;
    // 0x8017DF08: nop

L_8017DF0C:
    // 0x8017DF0C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017DF10: addiu       $t2, $t2, 0x3C00
    ctx->r10 = ADD32(ctx->r10, 0X3C00);
    // 0x8017DF14: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x8017DF18: b           L_8017E3CC
    // 0x8017DF1C: sw          $t1, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->r9;
        goto L_8017E3CC;
    // 0x8017DF1C: sw          $t1, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->r9;
L_8017DF20:
    // 0x8017DF20: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017DF24: addiu       $t9, $t9, 0x3C00
    ctx->r25 = ADD32(ctx->r25, 0X3C00);
    // 0x8017DF28: addiu       $t3, $zero, 0x14
    ctx->r11 = ADD32(0, 0X14);
    // 0x8017DF2C: b           L_8017E3CC
    // 0x8017DF30: sw          $t3, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->r11;
        goto L_8017E3CC;
    // 0x8017DF30: sw          $t3, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->r11;
L_8017DF34:
    // 0x8017DF34: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017DF38: addiu       $t6, $t6, 0x3C00
    ctx->r14 = ADD32(ctx->r14, 0X3C00);
    // 0x8017DF3C: addiu       $t5, $zero, 0x1E
    ctx->r13 = ADD32(0, 0X1E);
    // 0x8017DF40: b           L_8017E3CC
    // 0x8017DF44: sw          $t5, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r13;
        goto L_8017E3CC;
    // 0x8017DF44: sw          $t5, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r13;
L_8017DF48:
    // 0x8017DF48: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017DF4C: addiu       $t8, $t8, 0x3C00
    ctx->r24 = ADD32(ctx->r24, 0X3C00);
    // 0x8017DF50: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8017DF54: b           L_8017E3CC
    // 0x8017DF58: sw          $t4, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->r12;
        goto L_8017E3CC;
    // 0x8017DF58: sw          $t4, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->r12;
L_8017DF5C:
    // 0x8017DF5C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017DF60: addiu       $t7, $t7, 0x3988
    ctx->r15 = ADD32(ctx->r15, 0X3988);
    // 0x8017DF64: lw          $t0, 0x0($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X0);
    // 0x8017DF68: bne         $t0, $zero, L_8017DF80
    if (ctx->r8 != 0) {
        // 0x8017DF6C: nop
    
            goto L_8017DF80;
    }
    // 0x8017DF6C: nop

    // 0x8017DF70: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017DF74: addiu       $t1, $t1, 0x3C00
    ctx->r9 = ADD32(ctx->r9, 0X3C00);
    // 0x8017DF78: b           L_8017DFA4
    // 0x8017DF7C: sw          $zero, 0x28($t1)
    MEM_W(0X28, ctx->r9) = 0;
        goto L_8017DFA4;
    // 0x8017DF7C: sw          $zero, 0x28($t1)
    MEM_W(0X28, ctx->r9) = 0;
L_8017DF80:
    // 0x8017DF80: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017DF84: addiu       $t2, $t2, 0x3988
    ctx->r10 = ADD32(ctx->r10, 0X3988);
    // 0x8017DF88: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8017DF8C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8017DF90: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017DF94: divu        $zero, $t3, $at
    lo = S32(U32(ctx->r11) / U32(ctx->r1)); hi = S32(U32(ctx->r11) % U32(ctx->r1));
    // 0x8017DF98: mflo        $t9
    ctx->r25 = lo;
    // 0x8017DF9C: addiu       $t5, $t5, 0x3C00
    ctx->r13 = ADD32(ctx->r13, 0X3C00);
    // 0x8017DFA0: sw          $t9, 0x28($t5)
    MEM_W(0X28, ctx->r13) = ctx->r25;
L_8017DFA4:
    // 0x8017DFA4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017DFA8: addiu       $t6, $t6, 0x3988
    ctx->r14 = ADD32(ctx->r14, 0X3988);
    // 0x8017DFAC: lw          $t4, 0xC($t6)
    ctx->r12 = MEM_W(ctx->r14, 0XC);
    // 0x8017DFB0: bne         $t4, $zero, L_8017DFC8
    if (ctx->r12 != 0) {
        // 0x8017DFB4: nop
    
            goto L_8017DFC8;
    }
    // 0x8017DFB4: nop

    // 0x8017DFB8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017DFBC: addiu       $t8, $t8, 0x3C00
    ctx->r24 = ADD32(ctx->r24, 0X3C00);
    // 0x8017DFC0: b           L_8017DFEC
    // 0x8017DFC4: sw          $zero, 0x50($t8)
    MEM_W(0X50, ctx->r24) = 0;
        goto L_8017DFEC;
    // 0x8017DFC4: sw          $zero, 0x50($t8)
    MEM_W(0X50, ctx->r24) = 0;
L_8017DFC8:
    // 0x8017DFC8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017DFCC: addiu       $t7, $t7, 0x3988
    ctx->r15 = ADD32(ctx->r15, 0X3988);
    // 0x8017DFD0: lw          $t0, 0xC($t7)
    ctx->r8 = MEM_W(ctx->r15, 0XC);
    // 0x8017DFD4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8017DFD8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017DFDC: divu        $zero, $t0, $at
    lo = S32(U32(ctx->r8) / U32(ctx->r1)); hi = S32(U32(ctx->r8) % U32(ctx->r1));
    // 0x8017DFE0: mflo        $t1
    ctx->r9 = lo;
    // 0x8017DFE4: addiu       $t2, $t2, 0x3C00
    ctx->r10 = ADD32(ctx->r10, 0X3C00);
    // 0x8017DFE8: sw          $t1, 0x50($t2)
    MEM_W(0X50, ctx->r10) = ctx->r9;
L_8017DFEC:
    // 0x8017DFEC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017DFF0: addiu       $t3, $t3, 0x3C00
    ctx->r11 = ADD32(ctx->r11, 0X3C00);
    // 0x8017DFF4: lw          $t9, 0x4C($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X4C);
    // 0x8017DFF8: lw          $t5, 0x28($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X28);
    // 0x8017DFFC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017E000: addiu       $t4, $t4, 0x3C00
    ctx->r12 = ADD32(ctx->r12, 0X3C00);
    // 0x8017E004: addu        $t6, $t9, $t5
    ctx->r14 = ADD32(ctx->r25, ctx->r13);
    // 0x8017E008: sw          $t6, 0x4C($t3)
    MEM_W(0X4C, ctx->r11) = ctx->r14;
    // 0x8017E00C: lw          $t8, 0x74($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X74);
    // 0x8017E010: lw          $t7, 0x50($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X50);
    // 0x8017E014: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017E018: addiu       $t1, $t1, 0x3C00
    ctx->r9 = ADD32(ctx->r9, 0X3C00);
    // 0x8017E01C: addu        $t0, $t8, $t7
    ctx->r8 = ADD32(ctx->r24, ctx->r15);
    // 0x8017E020: sw          $t0, 0x74($t4)
    MEM_W(0X74, ctx->r12) = ctx->r8;
    // 0x8017E024: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x8017E028: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    // 0x8017E02C: ori         $t9, $t2, 0x1
    ctx->r25 = ctx->r10 | 0X1;
    // 0x8017E030: jal         0x800C8544
    // 0x8017E034: sw          $t9, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r25;
    func_800C8544(rdram, ctx);
        goto after_1;
    // 0x8017E034: sw          $t9, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r25;
    after_1:
    // 0x8017E038: b           L_8017E3CC
    // 0x8017E03C: nop

        goto L_8017E3CC;
    // 0x8017E03C: nop

L_8017E040:
    // 0x8017E040: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017E044: lw          $t5, -0x2E3C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2E3C);
    // 0x8017E048: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8017E04C: bne         $t5, $at, L_8017E088
    if (ctx->r13 != ctx->r1) {
        // 0x8017E050: nop
    
            goto L_8017E088;
    }
    // 0x8017E050: nop

    // 0x8017E054: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017E058: addiu       $t6, $t6, 0x39A0
    ctx->r14 = ADD32(ctx->r14, 0X39A0);
    // 0x8017E05C: lw          $t3, 0x1C($t6)
    ctx->r11 = MEM_W(ctx->r14, 0X1C);
    // 0x8017E060: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017E064: addiu       $t8, $t8, 0x3C00
    ctx->r24 = ADD32(ctx->r24, 0X3C00);
    // 0x8017E068: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017E06C: addiu       $t7, $t7, 0x39A0
    ctx->r15 = ADD32(ctx->r15, 0X39A0);
    // 0x8017E070: sw          $t3, 0x2C($t8)
    MEM_W(0X2C, ctx->r24) = ctx->r11;
    // 0x8017E074: lw          $t0, 0x3C($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X3C);
    // 0x8017E078: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017E07C: addiu       $t4, $t4, 0x3C00
    ctx->r12 = ADD32(ctx->r12, 0X3C00);
    // 0x8017E080: b           L_8017E0C8
    // 0x8017E084: sw          $t0, 0x54($t4)
    MEM_W(0X54, ctx->r12) = ctx->r8;
        goto L_8017E0C8;
    // 0x8017E084: sw          $t0, 0x54($t4)
    MEM_W(0X54, ctx->r12) = ctx->r8;
L_8017E088:
    // 0x8017E088: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017E08C: addiu       $t2, $t2, 0x39A0
    ctx->r10 = ADD32(ctx->r10, 0X39A0);
    // 0x8017E090: lw          $t9, 0x5C($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X5C);
    // 0x8017E094: lw          $t1, 0x1C($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X1C);
    // 0x8017E098: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017E09C: addiu       $t6, $t6, 0x3C00
    ctx->r14 = ADD32(ctx->r14, 0X3C00);
    // 0x8017E0A0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017E0A4: addu        $t5, $t9, $t1
    ctx->r13 = ADD32(ctx->r25, ctx->r9);
    // 0x8017E0A8: sw          $t5, 0x2C($t6)
    MEM_W(0X2C, ctx->r14) = ctx->r13;
    // 0x8017E0AC: addiu       $t3, $t3, 0x39A0
    ctx->r11 = ADD32(ctx->r11, 0X39A0);
    // 0x8017E0B0: lw          $t8, 0x7C($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X7C);
    // 0x8017E0B4: lw          $t7, 0x3C($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X3C);
    // 0x8017E0B8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017E0BC: addiu       $t4, $t4, 0x3C00
    ctx->r12 = ADD32(ctx->r12, 0X3C00);
    // 0x8017E0C0: addu        $t0, $t8, $t7
    ctx->r8 = ADD32(ctx->r24, ctx->r15);
    // 0x8017E0C4: sw          $t0, 0x54($t4)
    MEM_W(0X54, ctx->r12) = ctx->r8;
L_8017E0C8:
    // 0x8017E0C8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017E0CC: addiu       $t2, $t2, 0x3C00
    ctx->r10 = ADD32(ctx->r10, 0X3C00);
    // 0x8017E0D0: lw          $t9, 0x4C($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X4C);
    // 0x8017E0D4: lw          $t1, 0x2C($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X2C);
    // 0x8017E0D8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017E0DC: addiu       $t6, $t6, 0x3C00
    ctx->r14 = ADD32(ctx->r14, 0X3C00);
    // 0x8017E0E0: addu        $t5, $t9, $t1
    ctx->r13 = ADD32(ctx->r25, ctx->r9);
    // 0x8017E0E4: sw          $t5, 0x4C($t2)
    MEM_W(0X4C, ctx->r10) = ctx->r13;
    // 0x8017E0E8: lw          $t3, 0x74($t6)
    ctx->r11 = MEM_W(ctx->r14, 0X74);
    // 0x8017E0EC: lw          $t8, 0x54($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X54);
    // 0x8017E0F0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017E0F4: addiu       $t0, $t0, 0x3C00
    ctx->r8 = ADD32(ctx->r8, 0X3C00);
    // 0x8017E0F8: addu        $t7, $t3, $t8
    ctx->r15 = ADD32(ctx->r11, ctx->r24);
    // 0x8017E0FC: sw          $t7, 0x74($t6)
    MEM_W(0X74, ctx->r14) = ctx->r15;
    // 0x8017E100: lw          $t4, 0x4($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X4);
    // 0x8017E104: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    // 0x8017E108: ori         $t9, $t4, 0x2
    ctx->r25 = ctx->r12 | 0X2;
    // 0x8017E10C: jal         0x800C8544
    // 0x8017E110: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    func_800C8544(rdram, ctx);
        goto after_2;
    // 0x8017E110: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    after_2:
    // 0x8017E114: b           L_8017E3CC
    // 0x8017E118: nop

        goto L_8017E3CC;
    // 0x8017E118: nop

L_8017E11C:
    // 0x8017E11C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017E120: addiu       $t1, $t1, -0x2E28
    ctx->r9 = ADD32(ctx->r9, -0X2E28);
    // 0x8017E124: lbu         $t5, 0x7($t1)
    ctx->r13 = MEM_BU(ctx->r9, 0X7);
    // 0x8017E128: andi        $t2, $t5, 0x2
    ctx->r10 = ctx->r13 & 0X2;
    // 0x8017E12C: beq         $t2, $zero, L_8017E148
    if (ctx->r10 == 0) {
        // 0x8017E130: nop
    
            goto L_8017E148;
    }
    // 0x8017E130: nop

    // 0x8017E134: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017E138: addiu       $t8, $t8, 0x3C00
    ctx->r24 = ADD32(ctx->r24, 0X3C00);
    // 0x8017E13C: addiu       $t3, $zero, 0x64
    ctx->r11 = ADD32(0, 0X64);
    // 0x8017E140: b           L_8017E154
    // 0x8017E144: sw          $t3, 0x30($t8)
    MEM_W(0X30, ctx->r24) = ctx->r11;
        goto L_8017E154;
    // 0x8017E144: sw          $t3, 0x30($t8)
    MEM_W(0X30, ctx->r24) = ctx->r11;
L_8017E148:
    // 0x8017E148: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017E14C: addiu       $t7, $t7, 0x3C00
    ctx->r15 = ADD32(ctx->r15, 0X3C00);
    // 0x8017E150: sw          $zero, 0x30($t7)
    MEM_W(0X30, ctx->r15) = 0;
L_8017E154:
    // 0x8017E154: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017E158: addiu       $t6, $t6, -0x2E28
    ctx->r14 = ADD32(ctx->r14, -0X2E28);
    // 0x8017E15C: lbu         $t4, 0x7($t6)
    ctx->r12 = MEM_BU(ctx->r14, 0X7);
    // 0x8017E160: andi        $t9, $t4, 0x8
    ctx->r25 = ctx->r12 & 0X8;
    // 0x8017E164: beq         $t9, $zero, L_8017E180
    if (ctx->r25 == 0) {
        // 0x8017E168: nop
    
            goto L_8017E180;
    }
    // 0x8017E168: nop

    // 0x8017E16C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017E170: addiu       $t1, $t1, 0x3C00
    ctx->r9 = ADD32(ctx->r9, 0X3C00);
    // 0x8017E174: addiu       $t0, $zero, 0x64
    ctx->r8 = ADD32(0, 0X64);
    // 0x8017E178: b           L_8017E18C
    // 0x8017E17C: sw          $t0, 0x58($t1)
    MEM_W(0X58, ctx->r9) = ctx->r8;
        goto L_8017E18C;
    // 0x8017E17C: sw          $t0, 0x58($t1)
    MEM_W(0X58, ctx->r9) = ctx->r8;
L_8017E180:
    // 0x8017E180: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017E184: addiu       $t5, $t5, 0x3C00
    ctx->r13 = ADD32(ctx->r13, 0X3C00);
    // 0x8017E188: sw          $zero, 0x58($t5)
    MEM_W(0X58, ctx->r13) = 0;
L_8017E18C:
    // 0x8017E18C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017E190: addiu       $t2, $t2, 0x3C00
    ctx->r10 = ADD32(ctx->r10, 0X3C00);
    // 0x8017E194: lw          $t3, 0x4C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4C);
    // 0x8017E198: lw          $t8, 0x30($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X30);
    // 0x8017E19C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017E1A0: addiu       $t6, $t6, 0x3C00
    ctx->r14 = ADD32(ctx->r14, 0X3C00);
    // 0x8017E1A4: addu        $t7, $t3, $t8
    ctx->r15 = ADD32(ctx->r11, ctx->r24);
    // 0x8017E1A8: sw          $t7, 0x4C($t2)
    MEM_W(0X4C, ctx->r10) = ctx->r15;
    // 0x8017E1AC: lw          $t4, 0x74($t6)
    ctx->r12 = MEM_W(ctx->r14, 0X74);
    // 0x8017E1B0: lw          $t9, 0x58($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X58);
    // 0x8017E1B4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017E1B8: addiu       $t1, $t1, 0x3C00
    ctx->r9 = ADD32(ctx->r9, 0X3C00);
    // 0x8017E1BC: addu        $t0, $t4, $t9
    ctx->r8 = ADD32(ctx->r12, ctx->r25);
    // 0x8017E1C0: sw          $t0, 0x74($t6)
    MEM_W(0X74, ctx->r14) = ctx->r8;
    // 0x8017E1C4: lw          $t5, 0x4($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X4);
    // 0x8017E1C8: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    // 0x8017E1CC: ori         $t3, $t5, 0x4
    ctx->r11 = ctx->r13 | 0X4;
    // 0x8017E1D0: jal         0x800C8544
    // 0x8017E1D4: sw          $t3, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r11;
    func_800C8544(rdram, ctx);
        goto after_3;
    // 0x8017E1D4: sw          $t3, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r11;
    after_3:
    // 0x8017E1D8: b           L_8017E3CC
    // 0x8017E1DC: nop

        goto L_8017E3CC;
    // 0x8017E1DC: nop

L_8017E1E0:
    // 0x8017E1E0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017E1E4: addiu       $t8, $t8, -0x2E28
    ctx->r24 = ADD32(ctx->r24, -0X2E28);
    // 0x8017E1E8: lbu         $t7, 0x7($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0X7);
    // 0x8017E1EC: andi        $t2, $t7, 0x1
    ctx->r10 = ctx->r15 & 0X1;
    // 0x8017E1F0: beq         $t2, $zero, L_8017E20C
    if (ctx->r10 == 0) {
        // 0x8017E1F4: nop
    
            goto L_8017E20C;
    }
    // 0x8017E1F4: nop

    // 0x8017E1F8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017E1FC: addiu       $t9, $t9, 0x3C00
    ctx->r25 = ADD32(ctx->r25, 0X3C00);
    // 0x8017E200: addiu       $t4, $zero, 0x32
    ctx->r12 = ADD32(0, 0X32);
    // 0x8017E204: b           L_8017E218
    // 0x8017E208: sw          $t4, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->r12;
        goto L_8017E218;
    // 0x8017E208: sw          $t4, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->r12;
L_8017E20C:
    // 0x8017E20C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017E210: addiu       $t0, $t0, 0x3C00
    ctx->r8 = ADD32(ctx->r8, 0X3C00);
    // 0x8017E214: sw          $zero, 0x34($t0)
    MEM_W(0X34, ctx->r8) = 0;
L_8017E218:
    // 0x8017E218: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017E21C: addiu       $t6, $t6, -0x2E28
    ctx->r14 = ADD32(ctx->r14, -0X2E28);
    // 0x8017E220: lbu         $t5, 0x7($t6)
    ctx->r13 = MEM_BU(ctx->r14, 0X7);
    // 0x8017E224: andi        $t3, $t5, 0x4
    ctx->r11 = ctx->r13 & 0X4;
    // 0x8017E228: beq         $t3, $zero, L_8017E244
    if (ctx->r11 == 0) {
        // 0x8017E22C: nop
    
            goto L_8017E244;
    }
    // 0x8017E22C: nop

    // 0x8017E230: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017E234: addiu       $t8, $t8, 0x3C00
    ctx->r24 = ADD32(ctx->r24, 0X3C00);
    // 0x8017E238: addiu       $t1, $zero, 0x32
    ctx->r9 = ADD32(0, 0X32);
    // 0x8017E23C: b           L_8017E250
    // 0x8017E240: sw          $t1, 0x5C($t8)
    MEM_W(0X5C, ctx->r24) = ctx->r9;
        goto L_8017E250;
    // 0x8017E240: sw          $t1, 0x5C($t8)
    MEM_W(0X5C, ctx->r24) = ctx->r9;
L_8017E244:
    // 0x8017E244: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017E248: addiu       $t7, $t7, 0x3C00
    ctx->r15 = ADD32(ctx->r15, 0X3C00);
    // 0x8017E24C: sw          $zero, 0x5C($t7)
    MEM_W(0X5C, ctx->r15) = 0;
L_8017E250:
    // 0x8017E250: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017E254: addiu       $t2, $t2, 0x3C00
    ctx->r10 = ADD32(ctx->r10, 0X3C00);
    // 0x8017E258: lw          $t4, 0x4C($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X4C);
    // 0x8017E25C: lw          $t9, 0x34($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X34);
    // 0x8017E260: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017E264: addiu       $t6, $t6, 0x3C00
    ctx->r14 = ADD32(ctx->r14, 0X3C00);
    // 0x8017E268: addu        $t0, $t4, $t9
    ctx->r8 = ADD32(ctx->r12, ctx->r25);
    // 0x8017E26C: sw          $t0, 0x4C($t2)
    MEM_W(0X4C, ctx->r10) = ctx->r8;
    // 0x8017E270: lw          $t5, 0x74($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X74);
    // 0x8017E274: lw          $t3, 0x5C($t6)
    ctx->r11 = MEM_W(ctx->r14, 0X5C);
    // 0x8017E278: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017E27C: addiu       $t8, $t8, 0x3C00
    ctx->r24 = ADD32(ctx->r24, 0X3C00);
    // 0x8017E280: addu        $t1, $t5, $t3
    ctx->r9 = ADD32(ctx->r13, ctx->r11);
    // 0x8017E284: sw          $t1, 0x74($t6)
    MEM_W(0X74, ctx->r14) = ctx->r9;
    // 0x8017E288: lw          $t7, 0x4($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X4);
    // 0x8017E28C: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    // 0x8017E290: ori         $t4, $t7, 0x8
    ctx->r12 = ctx->r15 | 0X8;
    // 0x8017E294: jal         0x800C8544
    // 0x8017E298: sw          $t4, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r12;
    func_800C8544(rdram, ctx);
        goto after_4;
    // 0x8017E298: sw          $t4, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r12;
    after_4:
    // 0x8017E29C: b           L_8017E3CC
    // 0x8017E2A0: nop

        goto L_8017E3CC;
    // 0x8017E2A0: nop

L_8017E2A4:
    // 0x8017E2A4: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_8017E2A8:
    // 0x8017E2A8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017E2AC: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x8017E2B0: addiu       $t9, $t9, -0x2E18
    ctx->r25 = ADD32(ctx->r25, -0X2E18);
    // 0x8017E2B4: lw          $t0, 0x48($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X48);
    // 0x8017E2B8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8017E2BC: sllv        $t3, $t5, $t2
    ctx->r11 = S32(ctx->r13 << (ctx->r10 & 31));
    // 0x8017E2C0: and         $t1, $t0, $t3
    ctx->r9 = ctx->r8 & ctx->r11;
    // 0x8017E2C4: beq         $t1, $zero, L_8017E2F4
    if (ctx->r9 == 0) {
        // 0x8017E2C8: nop
    
            goto L_8017E2F4;
    }
    // 0x8017E2C8: nop

    // 0x8017E2CC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017E2D0: addiu       $t6, $t6, 0x3C00
    ctx->r14 = ADD32(ctx->r14, 0X3C00);
    // 0x8017E2D4: lw          $t7, 0x48($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X48);
    // 0x8017E2D8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017E2DC: addiu       $t8, $t8, 0x3C00
    ctx->r24 = ADD32(ctx->r24, 0X3C00);
    // 0x8017E2E0: addiu       $t4, $t7, 0x1
    ctx->r12 = ADD32(ctx->r15, 0X1);
    // 0x8017E2E4: sw          $t4, 0x48($t6)
    MEM_W(0X48, ctx->r14) = ctx->r12;
    // 0x8017E2E8: lw          $t9, 0x38($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X38);
    // 0x8017E2EC: addiu       $t5, $t9, 0x1E
    ctx->r13 = ADD32(ctx->r25, 0X1E);
    // 0x8017E2F0: sw          $t5, 0x38($t8)
    MEM_W(0X38, ctx->r24) = ctx->r13;
L_8017E2F4:
    // 0x8017E2F4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017E2F8: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8017E2FC: addiu       $t2, $t2, -0x2E18
    ctx->r10 = ADD32(ctx->r10, -0X2E18);
    // 0x8017E300: lw          $t0, 0x4C($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X4C);
    // 0x8017E304: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8017E308: sllv        $t7, $t1, $t3
    ctx->r15 = S32(ctx->r9 << (ctx->r11 & 31));
    // 0x8017E30C: and         $t4, $t0, $t7
    ctx->r12 = ctx->r8 & ctx->r15;
    // 0x8017E310: beq         $t4, $zero, L_8017E340
    if (ctx->r12 == 0) {
        // 0x8017E314: nop
    
            goto L_8017E340;
    }
    // 0x8017E314: nop

    // 0x8017E318: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017E31C: addiu       $t6, $t6, 0x3C00
    ctx->r14 = ADD32(ctx->r14, 0X3C00);
    // 0x8017E320: lw          $t9, 0x70($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X70);
    // 0x8017E324: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017E328: addiu       $t8, $t8, 0x3C00
    ctx->r24 = ADD32(ctx->r24, 0X3C00);
    // 0x8017E32C: addiu       $t5, $t9, 0x1
    ctx->r13 = ADD32(ctx->r25, 0X1);
    // 0x8017E330: sw          $t5, 0x70($t6)
    MEM_W(0X70, ctx->r14) = ctx->r13;
    // 0x8017E334: lw          $t2, 0x60($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X60);
    // 0x8017E338: addiu       $t1, $t2, 0x1E
    ctx->r9 = ADD32(ctx->r10, 0X1E);
    // 0x8017E33C: sw          $t1, 0x60($t8)
    MEM_W(0X60, ctx->r24) = ctx->r9;
L_8017E340:
    // 0x8017E340: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8017E344: addiu       $t0, $t3, 0x1
    ctx->r8 = ADD32(ctx->r11, 0X1);
    // 0x8017E348: sltiu       $at, $t0, 0x5
    ctx->r1 = ctx->r8 < 0X5 ? 1 : 0;
    // 0x8017E34C: bne         $at, $zero, L_8017E2A8
    if (ctx->r1 != 0) {
        // 0x8017E350: sw          $t0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r8;
            goto L_8017E2A8;
    }
    // 0x8017E350: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x8017E354: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017E358: addiu       $t7, $t7, 0x3C00
    ctx->r15 = ADD32(ctx->r15, 0X3C00);
    // 0x8017E35C: lw          $t4, 0x4C($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X4C);
    // 0x8017E360: lw          $t9, 0x38($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X38);
    // 0x8017E364: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017E368: addiu       $t6, $t6, 0x3C00
    ctx->r14 = ADD32(ctx->r14, 0X3C00);
    // 0x8017E36C: addu        $t5, $t4, $t9
    ctx->r13 = ADD32(ctx->r12, ctx->r25);
    // 0x8017E370: sw          $t5, 0x4C($t7)
    MEM_W(0X4C, ctx->r15) = ctx->r13;
    // 0x8017E374: lw          $t2, 0x74($t6)
    ctx->r10 = MEM_W(ctx->r14, 0X74);
    // 0x8017E378: lw          $t1, 0x60($t6)
    ctx->r9 = MEM_W(ctx->r14, 0X60);
    // 0x8017E37C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017E380: addiu       $t3, $t3, 0x3C00
    ctx->r11 = ADD32(ctx->r11, 0X3C00);
    // 0x8017E384: addu        $t8, $t2, $t1
    ctx->r24 = ADD32(ctx->r10, ctx->r9);
    // 0x8017E388: sw          $t8, 0x74($t6)
    MEM_W(0X74, ctx->r14) = ctx->r24;
    // 0x8017E38C: lw          $t0, 0x4($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X4);
    // 0x8017E390: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    // 0x8017E394: ori         $t4, $t0, 0x10
    ctx->r12 = ctx->r8 | 0X10;
    // 0x8017E398: jal         0x800C8544
    // 0x8017E39C: sw          $t4, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r12;
    func_800C8544(rdram, ctx);
        goto after_5;
    // 0x8017E39C: sw          $t4, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r12;
    after_5:
    // 0x8017E3A0: b           L_8017E3CC
    // 0x8017E3A4: nop

        goto L_8017E3CC;
    // 0x8017E3A4: nop

L_8017E3A8:
    // 0x8017E3A8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017E3AC: addiu       $t9, $t9, 0x3C00
    ctx->r25 = ADD32(ctx->r25, 0X3C00);
    // 0x8017E3B0: lw          $t5, 0x4($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X4);
    // 0x8017E3B4: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    // 0x8017E3B8: ori         $t7, $t5, 0x100
    ctx->r15 = ctx->r13 | 0X100;
    // 0x8017E3BC: jal         0x800C8544
    // 0x8017E3C0: sw          $t7, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r15;
    func_800C8544(rdram, ctx);
        goto after_6;
    // 0x8017E3C0: sw          $t7, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r15;
    after_6:
    // 0x8017E3C4: jal         0x800C7FA4
    // 0x8017E3C8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800C7FA4(rdram, ctx);
        goto after_7;
    // 0x8017E3C8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_7:
L_8017E3CC:
    // 0x8017E3CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8017E3D0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8017E3D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8017E3D8: jr          $ra
    // 0x8017E3DC: nop

    return;
    // 0x8017E3DC: nop

;}
RECOMP_FUNC void func_8017E3E0_0EF7C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017E3E0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8017E3E4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017E3E8: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8017E3EC: addiu       $t6, $t6, 0x3C00
    ctx->r14 = ADD32(ctx->r14, 0X3C00);
    // 0x8017E3F0: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8017E3F4: andi        $t8, $t7, 0x100
    ctx->r24 = ctx->r15 & 0X100;
    // 0x8017E3F8: beq         $t8, $zero, L_8017E5C8
    if (ctx->r24 == 0) {
        // 0x8017E3FC: nop
    
            goto L_8017E5C8;
    }
    // 0x8017E3FC: nop

    // 0x8017E400: lw          $t9, 0x74($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X74);
    // 0x8017E404: lw          $t0, 0x4C($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X4C);
    // 0x8017E408: bne         $t9, $t0, L_8017E498
    if (ctx->r25 != ctx->r8) {
        // 0x8017E40C: lui         $at, 0xC170
        ctx->r1 = S32(0XC170 << 16);
            goto L_8017E498;
    }
    // 0x8017E40C: lui         $at, 0xC170
    ctx->r1 = S32(0XC170 << 16);
    // 0x8017E410: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017E414: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8017E418: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017E41C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017E420: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8017E424: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017E428: lwc1        $f16, -0xCA0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0XCA0);
    // 0x8017E42C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017E430: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x8017E434: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x8017E438: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x8017E43C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8017E440: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017E444: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8017E448: lwc1        $f18, -0xC9C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0XC9C);
    // 0x8017E44C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8017E450: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x8017E454: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x8017E458: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    // 0x8017E45C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8017E460: addiu       $a0, $a0, -0xEC0
    ctx->r4 = ADD32(ctx->r4, -0XEC0);
    // 0x8017E464: addiu       $a1, $zero, 0xB4
    ctx->r5 = ADD32(0, 0XB4);
    // 0x8017E468: addiu       $a2, $zero, 0xB4
    ctx->r6 = ADD32(0, 0XB4);
    // 0x8017E46C: addiu       $a3, $zero, 0xB4
    ctx->r7 = ADD32(0, 0XB4);
    // 0x8017E470: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8017E474: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    // 0x8017E478: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    // 0x8017E47C: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    // 0x8017E480: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x8017E484: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    // 0x8017E488: jal         0x801716C8
    // 0x8017E48C: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    func_801716C8_02FC30(rdram, ctx);
        goto after_0;
    // 0x8017E48C: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x8017E490: b           L_8017E5C8
    // 0x8017E494: nop

        goto L_8017E5C8;
    // 0x8017E494: nop

L_8017E498:
    // 0x8017E498: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017E49C: addiu       $t3, $t3, 0x3C00
    ctx->r11 = ADD32(ctx->r11, 0X3C00);
    // 0x8017E4A0: lw          $t4, 0x4C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4C);
    // 0x8017E4A4: lw          $t5, 0x74($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X74);
    // 0x8017E4A8: sltu        $at, $t5, $t4
    ctx->r1 = ctx->r13 < ctx->r12 ? 1 : 0;
    // 0x8017E4AC: beq         $at, $zero, L_8017E540
    if (ctx->r1 == 0) {
        // 0x8017E4B0: lui         $at, 0xBFC0
        ctx->r1 = S32(0XBFC0 << 16);
            goto L_8017E540;
    }
    // 0x8017E4B0: lui         $at, 0xBFC0
    ctx->r1 = S32(0XBFC0 << 16);
    // 0x8017E4B4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017E4B8: lui         $at, 0xC170
    ctx->r1 = S32(0XC170 << 16);
    // 0x8017E4BC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8017E4C0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017E4C4: lwc1        $f4, -0xC98($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0XC98);
    // 0x8017E4C8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8017E4CC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017E4D0: lwc1        $f6, -0xC94($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0XC94);
    // 0x8017E4D4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017E4D8: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x8017E4DC: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    // 0x8017E4E0: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    // 0x8017E4E4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8017E4E8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8017E4EC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8017E4F0: lwc1        $f8, -0xC90($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0XC90);
    // 0x8017E4F4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8017E4F8: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8017E4FC: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x8017E500: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x8017E504: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8017E508: addiu       $a0, $a0, -0xEB8
    ctx->r4 = ADD32(ctx->r4, -0XEB8);
    // 0x8017E50C: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    // 0x8017E510: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8017E514: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8017E518: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8017E51C: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x8017E520: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x8017E524: swc1        $f18, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f18.u32l;
    // 0x8017E528: swc1        $f16, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f16.u32l;
    // 0x8017E52C: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x8017E530: jal         0x801716C8
    // 0x8017E534: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    func_801716C8_02FC30(rdram, ctx);
        goto after_1;
    // 0x8017E534: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x8017E538: b           L_8017E5C8
    // 0x8017E53C: nop

        goto L_8017E5C8;
    // 0x8017E53C: nop

L_8017E540:
    // 0x8017E540: lui         $at, 0x4198
    ctx->r1 = S32(0X4198 << 16);
    // 0x8017E544: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017E548: lui         $at, 0xC170
    ctx->r1 = S32(0XC170 << 16);
    // 0x8017E54C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017E550: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017E554: lwc1        $f10, -0xC8C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0XC8C);
    // 0x8017E558: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8017E55C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017E560: lwc1        $f16, -0xC88($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0XC88);
    // 0x8017E564: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017E568: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x8017E56C: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x8017E570: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x8017E574: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8017E578: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8017E57C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017E580: lwc1        $f18, -0xC84($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0XC84);
    // 0x8017E584: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8017E588: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8017E58C: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x8017E590: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
    // 0x8017E594: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8017E598: addiu       $a0, $a0, -0xEB4
    ctx->r4 = ADD32(ctx->r4, -0XEB4);
    // 0x8017E59C: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    // 0x8017E5A0: addiu       $a2, $zero, 0xB6
    ctx->r6 = ADD32(0, 0XB6);
    // 0x8017E5A4: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x8017E5A8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8017E5AC: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    // 0x8017E5B0: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    // 0x8017E5B4: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    // 0x8017E5B8: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    // 0x8017E5BC: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    // 0x8017E5C0: jal         0x801716C8
    // 0x8017E5C4: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    func_801716C8_02FC30(rdram, ctx);
        goto after_2;
    // 0x8017E5C4: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    after_2:
L_8017E5C8:
    // 0x8017E5C8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8017E5CC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8017E5D0: jr          $ra
    // 0x8017E5D4: nop

    return;
    // 0x8017E5D4: nop

;}
RECOMP_FUNC void func_8017E5D8_0EF7C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017E5D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017E5DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017E5E0: jal         0x800C7AD0
    // 0x8017E5E4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800C7AD0(rdram, ctx);
        goto after_0;
    // 0x8017E5E4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x8017E5E8: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x8017E5EC: jal         0x800C7A60
    // 0x8017E5F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C7A60(rdram, ctx);
        goto after_1;
    // 0x8017E5F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8017E5F4: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8017E5F8: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x8017E5FC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8017E600: mtc1        $at, $f15
    ctx->f_odd[(15 - 1) * 2] = ctx->r1;
    // 0x8017E604: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8017E608: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8017E60C: jal         0x800C7A88
    // 0x8017E610: nop

    func_800C7A88(rdram, ctx);
        goto after_2;
    // 0x8017E610: nop

    after_2:
    // 0x8017E614: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017E618: lw          $t6, -0x2E3C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2E3C);
    // 0x8017E61C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8017E620: bne         $t6, $at, L_8017E644
    if (ctx->r14 != ctx->r1) {
        // 0x8017E624: nop
    
            goto L_8017E644;
    }
    // 0x8017E624: nop

    // 0x8017E628: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017E62C: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017E630: addiu       $a1, $a1, -0xEB0
    ctx->r5 = ADD32(ctx->r5, -0XEB0);
    // 0x8017E634: jal         0x800D87E4
    // 0x8017E638: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_3;
    // 0x8017E638: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_3:
    // 0x8017E63C: b           L_8017E658
    // 0x8017E640: nop

        goto L_8017E658;
    // 0x8017E640: nop

L_8017E644:
    // 0x8017E644: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017E648: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017E64C: addiu       $a1, $a1, -0xEA0
    ctx->r5 = ADD32(ctx->r5, -0XEA0);
    // 0x8017E650: jal         0x800D87E4
    // 0x8017E654: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_4;
    // 0x8017E654: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_4:
L_8017E658:
    // 0x8017E658: addiu       $a0, $zero, 0xF8
    ctx->r4 = ADD32(0, 0XF8);
    // 0x8017E65C: jal         0x800C7A74
    // 0x8017E660: addiu       $a1, $zero, 0x48
    ctx->r5 = ADD32(0, 0X48);
    func_800C7A74(rdram, ctx);
        goto after_5;
    // 0x8017E660: addiu       $a1, $zero, 0x48
    ctx->r5 = ADD32(0, 0X48);
    after_5:
    // 0x8017E664: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    // 0x8017E668: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8017E66C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8017E670: jal         0x800C7A9C
    // 0x8017E674: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    func_800C7A9C(rdram, ctx);
        goto after_6;
    // 0x8017E674: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_6:
    // 0x8017E678: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8017E67C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8017E680: addiu       $a1, $a1, 0x3B40
    ctx->r5 = ADD32(ctx->r5, 0X3B40);
    // 0x8017E684: jal         0x800C767C
    // 0x8017E688: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    func_800C767C(rdram, ctx);
        goto after_7;
    // 0x8017E688: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    after_7:
    // 0x8017E68C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017E690: lw          $t7, -0x2E3C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2E3C);
    // 0x8017E694: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8017E698: bne         $t7, $at, L_8017E6BC
    if (ctx->r15 != ctx->r1) {
        // 0x8017E69C: nop
    
            goto L_8017E6BC;
    }
    // 0x8017E69C: nop

    // 0x8017E6A0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017E6A4: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017E6A8: addiu       $a1, $a1, -0xE8C
    ctx->r5 = ADD32(ctx->r5, -0XE8C);
    // 0x8017E6AC: jal         0x800D87E4
    // 0x8017E6B0: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_8;
    // 0x8017E6B0: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_8:
    // 0x8017E6B4: b           L_8017E6D0
    // 0x8017E6B8: nop

        goto L_8017E6D0;
    // 0x8017E6B8: nop

L_8017E6BC:
    // 0x8017E6BC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017E6C0: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017E6C4: addiu       $a1, $a1, -0xE7C
    ctx->r5 = ADD32(ctx->r5, -0XE7C);
    // 0x8017E6C8: jal         0x800D87E4
    // 0x8017E6CC: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_9;
    // 0x8017E6CC: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_9:
L_8017E6D0:
    // 0x8017E6D0: addiu       $a0, $zero, 0x1A8
    ctx->r4 = ADD32(0, 0X1A8);
    // 0x8017E6D4: jal         0x800C7A74
    // 0x8017E6D8: addiu       $a1, $zero, 0x48
    ctx->r5 = ADD32(0, 0X48);
    func_800C7A74(rdram, ctx);
        goto after_10;
    // 0x8017E6D8: addiu       $a1, $zero, 0x48
    ctx->r5 = ADD32(0, 0X48);
    after_10:
    // 0x8017E6DC: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    // 0x8017E6E0: addiu       $a1, $zero, 0xB6
    ctx->r5 = ADD32(0, 0XB6);
    // 0x8017E6E4: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8017E6E8: jal         0x800C7A9C
    // 0x8017E6EC: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    func_800C7A9C(rdram, ctx);
        goto after_11;
    // 0x8017E6EC: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_11:
    // 0x8017E6F0: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8017E6F4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8017E6F8: addiu       $a1, $a1, 0x3B40
    ctx->r5 = ADD32(ctx->r5, 0X3B40);
    // 0x8017E6FC: jal         0x800C767C
    // 0x8017E700: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    func_800C767C(rdram, ctx);
        goto after_12;
    // 0x8017E700: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    after_12:
    // 0x8017E704: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    // 0x8017E708: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    // 0x8017E70C: addiu       $a2, $zero, 0xC8
    ctx->r6 = ADD32(0, 0XC8);
    // 0x8017E710: jal         0x800C7A9C
    // 0x8017E714: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    func_800C7A9C(rdram, ctx);
        goto after_13;
    // 0x8017E714: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_13:
    // 0x8017E718: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017E71C: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017E720: addiu       $a1, $a1, -0xE68
    ctx->r5 = ADD32(ctx->r5, -0XE68);
    // 0x8017E724: jal         0x800D87E4
    // 0x8017E728: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_14;
    // 0x8017E728: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_14:
    // 0x8017E72C: addiu       $a0, $zero, 0x70
    ctx->r4 = ADD32(0, 0X70);
    // 0x8017E730: jal         0x800C7A74
    // 0x8017E734: addiu       $a1, $zero, 0x70
    ctx->r5 = ADD32(0, 0X70);
    func_800C7A74(rdram, ctx);
        goto after_15;
    // 0x8017E734: addiu       $a1, $zero, 0x70
    ctx->r5 = ADD32(0, 0X70);
    after_15:
    // 0x8017E738: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8017E73C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8017E740: addiu       $a1, $a1, 0x3B40
    ctx->r5 = ADD32(ctx->r5, 0X3B40);
    // 0x8017E744: jal         0x800C767C
    // 0x8017E748: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    func_800C767C(rdram, ctx);
        goto after_16;
    // 0x8017E748: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    after_16:
    // 0x8017E74C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017E750: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017E754: addiu       $a1, $a1, -0xE5C
    ctx->r5 = ADD32(ctx->r5, -0XE5C);
    // 0x8017E758: jal         0x800D87E4
    // 0x8017E75C: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_17;
    // 0x8017E75C: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_17:
    // 0x8017E760: addiu       $a0, $zero, 0x70
    ctx->r4 = ADD32(0, 0X70);
    // 0x8017E764: jal         0x800C7A74
    // 0x8017E768: addiu       $a1, $zero, 0x90
    ctx->r5 = ADD32(0, 0X90);
    func_800C7A74(rdram, ctx);
        goto after_18;
    // 0x8017E768: addiu       $a1, $zero, 0x90
    ctx->r5 = ADD32(0, 0X90);
    after_18:
    // 0x8017E76C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8017E770: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8017E774: addiu       $a1, $a1, 0x3B40
    ctx->r5 = ADD32(ctx->r5, 0X3B40);
    // 0x8017E778: jal         0x800C767C
    // 0x8017E77C: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    func_800C767C(rdram, ctx);
        goto after_19;
    // 0x8017E77C: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    after_19:
    // 0x8017E780: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017E784: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017E788: addiu       $a1, $a1, -0xE50
    ctx->r5 = ADD32(ctx->r5, -0XE50);
    // 0x8017E78C: jal         0x800D87E4
    // 0x8017E790: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_20;
    // 0x8017E790: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_20:
    // 0x8017E794: addiu       $a0, $zero, 0x78
    ctx->r4 = ADD32(0, 0X78);
    // 0x8017E798: jal         0x800C7A74
    // 0x8017E79C: addiu       $a1, $zero, 0xB0
    ctx->r5 = ADD32(0, 0XB0);
    func_800C7A74(rdram, ctx);
        goto after_21;
    // 0x8017E79C: addiu       $a1, $zero, 0xB0
    ctx->r5 = ADD32(0, 0XB0);
    after_21:
    // 0x8017E7A0: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8017E7A4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8017E7A8: addiu       $a1, $a1, 0x3B40
    ctx->r5 = ADD32(ctx->r5, 0X3B40);
    // 0x8017E7AC: jal         0x800C767C
    // 0x8017E7B0: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    func_800C767C(rdram, ctx);
        goto after_22;
    // 0x8017E7B0: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    after_22:
    // 0x8017E7B4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017E7B8: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017E7BC: addiu       $a1, $a1, -0xE44
    ctx->r5 = ADD32(ctx->r5, -0XE44);
    // 0x8017E7C0: jal         0x800D87E4
    // 0x8017E7C4: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_23;
    // 0x8017E7C4: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_23:
    // 0x8017E7C8: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    // 0x8017E7CC: jal         0x800C7A74
    // 0x8017E7D0: addiu       $a1, $zero, 0xD0
    ctx->r5 = ADD32(0, 0XD0);
    func_800C7A74(rdram, ctx);
        goto after_24;
    // 0x8017E7D0: addiu       $a1, $zero, 0xD0
    ctx->r5 = ADD32(0, 0XD0);
    after_24:
    // 0x8017E7D4: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8017E7D8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8017E7DC: addiu       $a1, $a1, 0x3B40
    ctx->r5 = ADD32(ctx->r5, 0X3B40);
    // 0x8017E7E0: jal         0x800C767C
    // 0x8017E7E4: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    func_800C767C(rdram, ctx);
        goto after_25;
    // 0x8017E7E4: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    after_25:
    // 0x8017E7E8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017E7EC: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017E7F0: addiu       $a1, $a1, -0xE30
    ctx->r5 = ADD32(ctx->r5, -0XE30);
    // 0x8017E7F4: jal         0x800D87E4
    // 0x8017E7F8: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_26;
    // 0x8017E7F8: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_26:
    // 0x8017E7FC: addiu       $a0, $zero, 0x68
    ctx->r4 = ADD32(0, 0X68);
    // 0x8017E800: jal         0x800C7A74
    // 0x8017E804: addiu       $a1, $zero, 0xF0
    ctx->r5 = ADD32(0, 0XF0);
    func_800C7A74(rdram, ctx);
        goto after_27;
    // 0x8017E804: addiu       $a1, $zero, 0xF0
    ctx->r5 = ADD32(0, 0XF0);
    after_27:
    // 0x8017E808: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8017E80C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8017E810: addiu       $a1, $a1, 0x3B40
    ctx->r5 = ADD32(ctx->r5, 0X3B40);
    // 0x8017E814: jal         0x800C767C
    // 0x8017E818: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    func_800C767C(rdram, ctx);
        goto after_28;
    // 0x8017E818: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    after_28:
    // 0x8017E81C: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8017E820: addiu       $a1, $zero, 0xB6
    ctx->r5 = ADD32(0, 0XB6);
    // 0x8017E824: addiu       $a2, $zero, 0x55
    ctx->r6 = ADD32(0, 0X55);
    // 0x8017E828: jal         0x800C7A9C
    // 0x8017E82C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    func_800C7A9C(rdram, ctx);
        goto after_29;
    // 0x8017E82C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_29:
    // 0x8017E830: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017E834: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017E838: addiu       $a1, $a1, -0xE20
    ctx->r5 = ADD32(ctx->r5, -0XE20);
    // 0x8017E83C: jal         0x800D87E4
    // 0x8017E840: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_30;
    // 0x8017E840: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_30:
    // 0x8017E844: addiu       $a0, $zero, 0x70
    ctx->r4 = ADD32(0, 0X70);
    // 0x8017E848: jal         0x800C7A74
    // 0x8017E84C: addiu       $a1, $zero, 0x118
    ctx->r5 = ADD32(0, 0X118);
    func_800C7A74(rdram, ctx);
        goto after_31;
    // 0x8017E84C: addiu       $a1, $zero, 0x118
    ctx->r5 = ADD32(0, 0X118);
    after_31:
    // 0x8017E850: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8017E854: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8017E858: addiu       $a1, $a1, 0x3B40
    ctx->r5 = ADD32(ctx->r5, 0X3B40);
    // 0x8017E85C: jal         0x800C767C
    // 0x8017E860: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    func_800C767C(rdram, ctx);
        goto after_32;
    // 0x8017E860: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    after_32:
    // 0x8017E864: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017E868: addiu       $t8, $t8, 0x3C00
    ctx->r24 = ADD32(ctx->r24, 0X3C00);
    // 0x8017E86C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017E870: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017E874: addiu       $a1, $a1, -0xE14
    ctx->r5 = ADD32(ctx->r5, -0XE14);
    // 0x8017E878: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    // 0x8017E87C: jal         0x800D87E4
    // 0x8017E880: lw          $a2, 0x4C($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X4C);
    sprintf_recomp(rdram, ctx);
        goto after_33;
    // 0x8017E880: lw          $a2, 0x4C($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X4C);
    after_33:
    // 0x8017E884: addiu       $a0, $zero, 0x158
    ctx->r4 = ADD32(0, 0X158);
    // 0x8017E888: jal         0x800C7A74
    // 0x8017E88C: addiu       $a1, $zero, 0x118
    ctx->r5 = ADD32(0, 0X118);
    func_800C7A74(rdram, ctx);
        goto after_34;
    // 0x8017E88C: addiu       $a1, $zero, 0x118
    ctx->r5 = ADD32(0, 0X118);
    after_34:
    // 0x8017E890: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8017E894: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8017E898: addiu       $a1, $a1, 0x3B40
    ctx->r5 = ADD32(ctx->r5, 0X3B40);
    // 0x8017E89C: jal         0x800C767C
    // 0x8017E8A0: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    func_800C767C(rdram, ctx);
        goto after_35;
    // 0x8017E8A0: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    after_35:
    // 0x8017E8A4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017E8A8: addiu       $t9, $t9, 0x3C00
    ctx->r25 = ADD32(ctx->r25, 0X3C00);
    // 0x8017E8AC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017E8B0: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017E8B4: addiu       $a1, $a1, -0xE10
    ctx->r5 = ADD32(ctx->r5, -0XE10);
    // 0x8017E8B8: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    // 0x8017E8BC: jal         0x800D87E4
    // 0x8017E8C0: lw          $a2, 0x74($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X74);
    sprintf_recomp(rdram, ctx);
        goto after_36;
    // 0x8017E8C0: lw          $a2, 0x74($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X74);
    after_36:
    // 0x8017E8C4: addiu       $a0, $zero, 0x208
    ctx->r4 = ADD32(0, 0X208);
    // 0x8017E8C8: jal         0x800C7A74
    // 0x8017E8CC: addiu       $a1, $zero, 0x118
    ctx->r5 = ADD32(0, 0X118);
    func_800C7A74(rdram, ctx);
        goto after_37;
    // 0x8017E8CC: addiu       $a1, $zero, 0x118
    ctx->r5 = ADD32(0, 0X118);
    after_37:
    // 0x8017E8D0: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8017E8D4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8017E8D8: addiu       $a1, $a1, 0x3B40
    ctx->r5 = ADD32(ctx->r5, 0X3B40);
    // 0x8017E8DC: jal         0x800C767C
    // 0x8017E8E0: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    func_800C767C(rdram, ctx);
        goto after_38;
    // 0x8017E8E0: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    after_38:
    // 0x8017E8E4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017E8E8: addiu       $t0, $t0, 0x3C00
    ctx->r8 = ADD32(ctx->r8, 0X3C00);
    // 0x8017E8EC: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x8017E8F0: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x8017E8F4: beq         $t2, $zero, L_8017EA84
    if (ctx->r10 == 0) {
        // 0x8017E8F8: nop
    
            goto L_8017EA84;
    }
    // 0x8017E8F8: nop

    // 0x8017E8FC: addiu       $a0, $zero, 0x48
    ctx->r4 = ADD32(0, 0X48);
    // 0x8017E900: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8017E904: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8017E908: jal         0x800C7A9C
    // 0x8017E90C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    func_800C7A9C(rdram, ctx);
        goto after_39;
    // 0x8017E90C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_39:
    // 0x8017E910: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017E914: addiu       $t3, $t3, 0x3988
    ctx->r11 = ADD32(ctx->r11, 0X3988);
    // 0x8017E918: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8017E91C: bne         $t4, $zero, L_8017E940
    if (ctx->r12 != 0) {
        // 0x8017E920: nop
    
            goto L_8017E940;
    }
    // 0x8017E920: nop

    // 0x8017E924: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017E928: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017E92C: addiu       $a1, $a1, -0xE0C
    ctx->r5 = ADD32(ctx->r5, -0XE0C);
    // 0x8017E930: jal         0x800D87E4
    // 0x8017E934: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_40;
    // 0x8017E934: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_40:
    // 0x8017E938: b           L_8017E960
    // 0x8017E93C: nop

        goto L_8017E960;
    // 0x8017E93C: nop

L_8017E940:
    // 0x8017E940: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017E944: addiu       $t5, $t5, 0x3988
    ctx->r13 = ADD32(ctx->r13, 0X3988);
    // 0x8017E948: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017E94C: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017E950: addiu       $a1, $a1, -0xE00
    ctx->r5 = ADD32(ctx->r5, -0XE00);
    // 0x8017E954: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    // 0x8017E958: jal         0x800D87E4
    // 0x8017E95C: lw          $a2, 0x0($t5)
    ctx->r6 = MEM_W(ctx->r13, 0X0);
    sprintf_recomp(rdram, ctx);
        goto after_41;
    // 0x8017E95C: lw          $a2, 0x0($t5)
    ctx->r6 = MEM_W(ctx->r13, 0X0);
    after_41:
L_8017E960:
    // 0x8017E960: addiu       $a0, $zero, 0xF0
    ctx->r4 = ADD32(0, 0XF0);
    // 0x8017E964: jal         0x800C7A74
    // 0x8017E968: addiu       $a1, $zero, 0x70
    ctx->r5 = ADD32(0, 0X70);
    func_800C7A74(rdram, ctx);
        goto after_42;
    // 0x8017E968: addiu       $a1, $zero, 0x70
    ctx->r5 = ADD32(0, 0X70);
    after_42:
    // 0x8017E96C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8017E970: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8017E974: addiu       $a1, $a1, 0x3B40
    ctx->r5 = ADD32(ctx->r5, 0X3B40);
    // 0x8017E978: jal         0x800C767C
    // 0x8017E97C: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    func_800C767C(rdram, ctx);
        goto after_43;
    // 0x8017E97C: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    after_43:
    // 0x8017E980: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017E984: addiu       $t6, $t6, 0x3C00
    ctx->r14 = ADD32(ctx->r14, 0X3C00);
    // 0x8017E988: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017E98C: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017E990: addiu       $a1, $a1, -0xDF8
    ctx->r5 = ADD32(ctx->r5, -0XDF8);
    // 0x8017E994: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    // 0x8017E998: jal         0x800D87E4
    // 0x8017E99C: lw          $a2, 0x28($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X28);
    sprintf_recomp(rdram, ctx);
        goto after_44;
    // 0x8017E99C: lw          $a2, 0x28($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X28);
    after_44:
    // 0x8017E9A0: addiu       $a0, $zero, 0x160
    ctx->r4 = ADD32(0, 0X160);
    // 0x8017E9A4: jal         0x800C7A74
    // 0x8017E9A8: addiu       $a1, $zero, 0x70
    ctx->r5 = ADD32(0, 0X70);
    func_800C7A74(rdram, ctx);
        goto after_45;
    // 0x8017E9A8: addiu       $a1, $zero, 0x70
    ctx->r5 = ADD32(0, 0X70);
    after_45:
    // 0x8017E9AC: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8017E9B0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8017E9B4: addiu       $a1, $a1, 0x3B40
    ctx->r5 = ADD32(ctx->r5, 0X3B40);
    // 0x8017E9B8: jal         0x800C767C
    // 0x8017E9BC: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    func_800C767C(rdram, ctx);
        goto after_46;
    // 0x8017E9BC: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    after_46:
    // 0x8017E9C0: addiu       $a0, $zero, 0x48
    ctx->r4 = ADD32(0, 0X48);
    // 0x8017E9C4: addiu       $a1, $zero, 0xB6
    ctx->r5 = ADD32(0, 0XB6);
    // 0x8017E9C8: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8017E9CC: jal         0x800C7A9C
    // 0x8017E9D0: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    func_800C7A9C(rdram, ctx);
        goto after_47;
    // 0x8017E9D0: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_47:
    // 0x8017E9D4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017E9D8: addiu       $t7, $t7, 0x3988
    ctx->r15 = ADD32(ctx->r15, 0X3988);
    // 0x8017E9DC: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x8017E9E0: bne         $t8, $zero, L_8017EA04
    if (ctx->r24 != 0) {
        // 0x8017E9E4: nop
    
            goto L_8017EA04;
    }
    // 0x8017E9E4: nop

    // 0x8017E9E8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017E9EC: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017E9F0: addiu       $a1, $a1, -0xDF4
    ctx->r5 = ADD32(ctx->r5, -0XDF4);
    // 0x8017E9F4: jal         0x800D87E4
    // 0x8017E9F8: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_48;
    // 0x8017E9F8: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_48:
    // 0x8017E9FC: b           L_8017EA24
    // 0x8017EA00: nop

        goto L_8017EA24;
    // 0x8017EA00: nop

L_8017EA04:
    // 0x8017EA04: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017EA08: addiu       $t9, $t9, 0x3988
    ctx->r25 = ADD32(ctx->r25, 0X3988);
    // 0x8017EA0C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017EA10: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017EA14: addiu       $a1, $a1, -0xDE8
    ctx->r5 = ADD32(ctx->r5, -0XDE8);
    // 0x8017EA18: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    // 0x8017EA1C: jal         0x800D87E4
    // 0x8017EA20: lw          $a2, 0xC($t9)
    ctx->r6 = MEM_W(ctx->r25, 0XC);
    sprintf_recomp(rdram, ctx);
        goto after_49;
    // 0x8017EA20: lw          $a2, 0xC($t9)
    ctx->r6 = MEM_W(ctx->r25, 0XC);
    after_49:
L_8017EA24:
    // 0x8017EA24: addiu       $a0, $zero, 0x1A0
    ctx->r4 = ADD32(0, 0X1A0);
    // 0x8017EA28: jal         0x800C7A74
    // 0x8017EA2C: addiu       $a1, $zero, 0x70
    ctx->r5 = ADD32(0, 0X70);
    func_800C7A74(rdram, ctx);
        goto after_50;
    // 0x8017EA2C: addiu       $a1, $zero, 0x70
    ctx->r5 = ADD32(0, 0X70);
    after_50:
    // 0x8017EA30: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8017EA34: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8017EA38: addiu       $a1, $a1, 0x3B40
    ctx->r5 = ADD32(ctx->r5, 0X3B40);
    // 0x8017EA3C: jal         0x800C767C
    // 0x8017EA40: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    func_800C767C(rdram, ctx);
        goto after_51;
    // 0x8017EA40: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    after_51:
    // 0x8017EA44: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017EA48: addiu       $t0, $t0, 0x3C00
    ctx->r8 = ADD32(ctx->r8, 0X3C00);
    // 0x8017EA4C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017EA50: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017EA54: addiu       $a1, $a1, -0xDE0
    ctx->r5 = ADD32(ctx->r5, -0XDE0);
    // 0x8017EA58: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    // 0x8017EA5C: jal         0x800D87E4
    // 0x8017EA60: lw          $a2, 0x50($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X50);
    sprintf_recomp(rdram, ctx);
        goto after_52;
    // 0x8017EA60: lw          $a2, 0x50($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X50);
    after_52:
    // 0x8017EA64: addiu       $a0, $zero, 0x210
    ctx->r4 = ADD32(0, 0X210);
    // 0x8017EA68: jal         0x800C7A74
    // 0x8017EA6C: addiu       $a1, $zero, 0x70
    ctx->r5 = ADD32(0, 0X70);
    func_800C7A74(rdram, ctx);
        goto after_53;
    // 0x8017EA6C: addiu       $a1, $zero, 0x70
    ctx->r5 = ADD32(0, 0X70);
    after_53:
    // 0x8017EA70: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8017EA74: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8017EA78: addiu       $a1, $a1, 0x3B40
    ctx->r5 = ADD32(ctx->r5, 0X3B40);
    // 0x8017EA7C: jal         0x800C767C
    // 0x8017EA80: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    func_800C767C(rdram, ctx);
        goto after_54;
    // 0x8017EA80: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    after_54:
L_8017EA84:
    // 0x8017EA84: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017EA88: addiu       $t1, $t1, 0x3C00
    ctx->r9 = ADD32(ctx->r9, 0X3C00);
    // 0x8017EA8C: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x8017EA90: andi        $t3, $t2, 0x2
    ctx->r11 = ctx->r10 & 0X2;
    // 0x8017EA94: beq         $t3, $zero, L_8017EB54
    if (ctx->r11 == 0) {
        // 0x8017EA98: nop
    
            goto L_8017EB54;
    }
    // 0x8017EA98: nop

    // 0x8017EA9C: addiu       $a0, $zero, 0x6D
    ctx->r4 = ADD32(0, 0X6D);
    // 0x8017EAA0: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8017EAA4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8017EAA8: jal         0x800C7A9C
    // 0x8017EAAC: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    func_800C7A9C(rdram, ctx);
        goto after_55;
    // 0x8017EAAC: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_55:
    // 0x8017EAB0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017EAB4: addiu       $t4, $t4, 0x3C00
    ctx->r12 = ADD32(ctx->r12, 0X3C00);
    // 0x8017EAB8: lw          $t5, 0x2C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X2C);
    // 0x8017EABC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017EAC0: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017EAC4: addiu       $a1, $a1, -0xDDC
    ctx->r5 = ADD32(ctx->r5, -0XDDC);
    // 0x8017EAC8: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    // 0x8017EACC: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
    // 0x8017EAD0: jal         0x800D87E4
    // 0x8017EAD4: or          $a3, $t5, $zero
    ctx->r7 = ctx->r13 | 0;
    sprintf_recomp(rdram, ctx);
        goto after_56;
    // 0x8017EAD4: or          $a3, $t5, $zero
    ctx->r7 = ctx->r13 | 0;
    after_56:
    // 0x8017EAD8: addiu       $a0, $zero, 0x110
    ctx->r4 = ADD32(0, 0X110);
    // 0x8017EADC: jal         0x800C7A74
    // 0x8017EAE0: addiu       $a1, $zero, 0x90
    ctx->r5 = ADD32(0, 0X90);
    func_800C7A74(rdram, ctx);
        goto after_57;
    // 0x8017EAE0: addiu       $a1, $zero, 0x90
    ctx->r5 = ADD32(0, 0X90);
    after_57:
    // 0x8017EAE4: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8017EAE8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8017EAEC: addiu       $a1, $a1, 0x3B40
    ctx->r5 = ADD32(ctx->r5, 0X3B40);
    // 0x8017EAF0: jal         0x800C767C
    // 0x8017EAF4: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    func_800C767C(rdram, ctx);
        goto after_58;
    // 0x8017EAF4: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    after_58:
    // 0x8017EAF8: addiu       $a0, $zero, 0x6D
    ctx->r4 = ADD32(0, 0X6D);
    // 0x8017EAFC: addiu       $a1, $zero, 0xB6
    ctx->r5 = ADD32(0, 0XB6);
    // 0x8017EB00: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8017EB04: jal         0x800C7A9C
    // 0x8017EB08: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    func_800C7A9C(rdram, ctx);
        goto after_59;
    // 0x8017EB08: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_59:
    // 0x8017EB0C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017EB10: addiu       $t6, $t6, 0x3C00
    ctx->r14 = ADD32(ctx->r14, 0X3C00);
    // 0x8017EB14: lw          $t7, 0x54($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X54);
    // 0x8017EB18: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017EB1C: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017EB20: addiu       $a1, $a1, -0xDCC
    ctx->r5 = ADD32(ctx->r5, -0XDCC);
    // 0x8017EB24: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    // 0x8017EB28: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x8017EB2C: jal         0x800D87E4
    // 0x8017EB30: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
    sprintf_recomp(rdram, ctx);
        goto after_60;
    // 0x8017EB30: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
    after_60:
    // 0x8017EB34: addiu       $a0, $zero, 0x1C0
    ctx->r4 = ADD32(0, 0X1C0);
    // 0x8017EB38: jal         0x800C7A74
    // 0x8017EB3C: addiu       $a1, $zero, 0x90
    ctx->r5 = ADD32(0, 0X90);
    func_800C7A74(rdram, ctx);
        goto after_61;
    // 0x8017EB3C: addiu       $a1, $zero, 0x90
    ctx->r5 = ADD32(0, 0X90);
    after_61:
    // 0x8017EB40: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8017EB44: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8017EB48: addiu       $a1, $a1, 0x3B40
    ctx->r5 = ADD32(ctx->r5, 0X3B40);
    // 0x8017EB4C: jal         0x800C767C
    // 0x8017EB50: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    func_800C767C(rdram, ctx);
        goto after_62;
    // 0x8017EB50: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    after_62:
L_8017EB54:
    // 0x8017EB54: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017EB58: addiu       $t8, $t8, 0x3C00
    ctx->r24 = ADD32(ctx->r24, 0X3C00);
    // 0x8017EB5C: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x8017EB60: andi        $t0, $t9, 0x4
    ctx->r8 = ctx->r25 & 0X4;
    // 0x8017EB64: beq         $t0, $zero, L_8017EC7C
    if (ctx->r8 == 0) {
        // 0x8017EB68: nop
    
            goto L_8017EC7C;
    }
    // 0x8017EB68: nop

    // 0x8017EB6C: addiu       $a0, $zero, 0x92
    ctx->r4 = ADD32(0, 0X92);
    // 0x8017EB70: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8017EB74: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8017EB78: jal         0x800C7A9C
    // 0x8017EB7C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    func_800C7A9C(rdram, ctx);
        goto after_63;
    // 0x8017EB7C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_63:
    // 0x8017EB80: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017EB84: addiu       $t1, $t1, 0x3C00
    ctx->r9 = ADD32(ctx->r9, 0X3C00);
    // 0x8017EB88: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x8017EB8C: bne         $t2, $zero, L_8017EBB4
    if (ctx->r10 != 0) {
        // 0x8017EB90: nop
    
            goto L_8017EBB4;
    }
    // 0x8017EB90: nop

    // 0x8017EB94: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017EB98: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017EB9C: addiu       $a1, $a1, -0xDBC
    ctx->r5 = ADD32(ctx->r5, -0XDBC);
    // 0x8017EBA0: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    // 0x8017EBA4: jal         0x800D87E4
    // 0x8017EBA8: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    sprintf_recomp(rdram, ctx);
        goto after_64;
    // 0x8017EBA8: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    after_64:
    // 0x8017EBAC: b           L_8017EBD4
    // 0x8017EBB0: nop

        goto L_8017EBD4;
    // 0x8017EBB0: nop

L_8017EBB4:
    // 0x8017EBB4: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017EBB8: addiu       $t3, $t3, 0x3C00
    ctx->r11 = ADD32(ctx->r11, 0X3C00);
    // 0x8017EBBC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017EBC0: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017EBC4: addiu       $a1, $a1, -0xDA8
    ctx->r5 = ADD32(ctx->r5, -0XDA8);
    // 0x8017EBC8: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    // 0x8017EBCC: jal         0x800D87E4
    // 0x8017EBD0: lw          $a2, 0x30($t3)
    ctx->r6 = MEM_W(ctx->r11, 0X30);
    sprintf_recomp(rdram, ctx);
        goto after_65;
    // 0x8017EBD0: lw          $a2, 0x30($t3)
    ctx->r6 = MEM_W(ctx->r11, 0X30);
    after_65:
L_8017EBD4:
    // 0x8017EBD4: addiu       $a0, $zero, 0xF8
    ctx->r4 = ADD32(0, 0XF8);
    // 0x8017EBD8: jal         0x800C7A74
    // 0x8017EBDC: addiu       $a1, $zero, 0xB0
    ctx->r5 = ADD32(0, 0XB0);
    func_800C7A74(rdram, ctx);
        goto after_66;
    // 0x8017EBDC: addiu       $a1, $zero, 0xB0
    ctx->r5 = ADD32(0, 0XB0);
    after_66:
    // 0x8017EBE0: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8017EBE4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8017EBE8: addiu       $a1, $a1, 0x3B40
    ctx->r5 = ADD32(ctx->r5, 0X3B40);
    // 0x8017EBEC: jal         0x800C767C
    // 0x8017EBF0: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    func_800C767C(rdram, ctx);
        goto after_67;
    // 0x8017EBF0: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    after_67:
    // 0x8017EBF4: addiu       $a0, $zero, 0x92
    ctx->r4 = ADD32(0, 0X92);
    // 0x8017EBF8: addiu       $a1, $zero, 0xB6
    ctx->r5 = ADD32(0, 0XB6);
    // 0x8017EBFC: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8017EC00: jal         0x800C7A9C
    // 0x8017EC04: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    func_800C7A9C(rdram, ctx);
        goto after_68;
    // 0x8017EC04: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_68:
    // 0x8017EC08: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017EC0C: addiu       $t4, $t4, 0x3C00
    ctx->r12 = ADD32(ctx->r12, 0X3C00);
    // 0x8017EC10: lw          $t5, 0x58($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X58);
    // 0x8017EC14: bne         $t5, $zero, L_8017EC3C
    if (ctx->r13 != 0) {
        // 0x8017EC18: nop
    
            goto L_8017EC3C;
    }
    // 0x8017EC18: nop

    // 0x8017EC1C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017EC20: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017EC24: addiu       $a1, $a1, -0xD94
    ctx->r5 = ADD32(ctx->r5, -0XD94);
    // 0x8017EC28: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    // 0x8017EC2C: jal         0x800D87E4
    // 0x8017EC30: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
    sprintf_recomp(rdram, ctx);
        goto after_69;
    // 0x8017EC30: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
    after_69:
    // 0x8017EC34: b           L_8017EC5C
    // 0x8017EC38: nop

        goto L_8017EC5C;
    // 0x8017EC38: nop

L_8017EC3C:
    // 0x8017EC3C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017EC40: addiu       $t6, $t6, 0x3C00
    ctx->r14 = ADD32(ctx->r14, 0X3C00);
    // 0x8017EC44: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017EC48: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017EC4C: addiu       $a1, $a1, -0xD80
    ctx->r5 = ADD32(ctx->r5, -0XD80);
    // 0x8017EC50: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    // 0x8017EC54: jal         0x800D87E4
    // 0x8017EC58: lw          $a2, 0x58($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X58);
    sprintf_recomp(rdram, ctx);
        goto after_70;
    // 0x8017EC58: lw          $a2, 0x58($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X58);
    after_70:
L_8017EC5C:
    // 0x8017EC5C: addiu       $a0, $zero, 0x1A8
    ctx->r4 = ADD32(0, 0X1A8);
    // 0x8017EC60: jal         0x800C7A74
    // 0x8017EC64: addiu       $a1, $zero, 0xB0
    ctx->r5 = ADD32(0, 0XB0);
    func_800C7A74(rdram, ctx);
        goto after_71;
    // 0x8017EC64: addiu       $a1, $zero, 0xB0
    ctx->r5 = ADD32(0, 0XB0);
    after_71:
    // 0x8017EC68: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8017EC6C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8017EC70: addiu       $a1, $a1, 0x3B40
    ctx->r5 = ADD32(ctx->r5, 0X3B40);
    // 0x8017EC74: jal         0x800C767C
    // 0x8017EC78: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    func_800C767C(rdram, ctx);
        goto after_72;
    // 0x8017EC78: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    after_72:
L_8017EC7C:
    // 0x8017EC7C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017EC80: addiu       $t7, $t7, 0x3C00
    ctx->r15 = ADD32(ctx->r15, 0X3C00);
    // 0x8017EC84: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8017EC88: andi        $t9, $t8, 0x8
    ctx->r25 = ctx->r24 & 0X8;
    // 0x8017EC8C: beq         $t9, $zero, L_8017EDA4
    if (ctx->r25 == 0) {
        // 0x8017EC90: nop
    
            goto L_8017EDA4;
    }
    // 0x8017EC90: nop

    // 0x8017EC94: addiu       $a0, $zero, 0xB6
    ctx->r4 = ADD32(0, 0XB6);
    // 0x8017EC98: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8017EC9C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8017ECA0: jal         0x800C7A9C
    // 0x8017ECA4: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    func_800C7A9C(rdram, ctx);
        goto after_73;
    // 0x8017ECA4: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_73:
    // 0x8017ECA8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017ECAC: addiu       $t0, $t0, 0x3C00
    ctx->r8 = ADD32(ctx->r8, 0X3C00);
    // 0x8017ECB0: lw          $t1, 0x34($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X34);
    // 0x8017ECB4: bne         $t1, $zero, L_8017ECDC
    if (ctx->r9 != 0) {
        // 0x8017ECB8: nop
    
            goto L_8017ECDC;
    }
    // 0x8017ECB8: nop

    // 0x8017ECBC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017ECC0: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017ECC4: addiu       $a1, $a1, -0xD6C
    ctx->r5 = ADD32(ctx->r5, -0XD6C);
    // 0x8017ECC8: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    // 0x8017ECCC: jal         0x800D87E4
    // 0x8017ECD0: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    sprintf_recomp(rdram, ctx);
        goto after_74;
    // 0x8017ECD0: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    after_74:
    // 0x8017ECD4: b           L_8017ECFC
    // 0x8017ECD8: nop

        goto L_8017ECFC;
    // 0x8017ECD8: nop

L_8017ECDC:
    // 0x8017ECDC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017ECE0: addiu       $t2, $t2, 0x3C00
    ctx->r10 = ADD32(ctx->r10, 0X3C00);
    // 0x8017ECE4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017ECE8: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017ECEC: addiu       $a1, $a1, -0xD58
    ctx->r5 = ADD32(ctx->r5, -0XD58);
    // 0x8017ECF0: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    // 0x8017ECF4: jal         0x800D87E4
    // 0x8017ECF8: lw          $a2, 0x34($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X34);
    sprintf_recomp(rdram, ctx);
        goto after_75;
    // 0x8017ECF8: lw          $a2, 0x34($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X34);
    after_75:
L_8017ECFC:
    // 0x8017ECFC: addiu       $a0, $zero, 0xF8
    ctx->r4 = ADD32(0, 0XF8);
    // 0x8017ED00: jal         0x800C7A74
    // 0x8017ED04: addiu       $a1, $zero, 0xD0
    ctx->r5 = ADD32(0, 0XD0);
    func_800C7A74(rdram, ctx);
        goto after_76;
    // 0x8017ED04: addiu       $a1, $zero, 0xD0
    ctx->r5 = ADD32(0, 0XD0);
    after_76:
    // 0x8017ED08: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8017ED0C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8017ED10: addiu       $a1, $a1, 0x3B40
    ctx->r5 = ADD32(ctx->r5, 0X3B40);
    // 0x8017ED14: jal         0x800C767C
    // 0x8017ED18: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    func_800C767C(rdram, ctx);
        goto after_77;
    // 0x8017ED18: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    after_77:
    // 0x8017ED1C: addiu       $a0, $zero, 0xB6
    ctx->r4 = ADD32(0, 0XB6);
    // 0x8017ED20: addiu       $a1, $zero, 0xB6
    ctx->r5 = ADD32(0, 0XB6);
    // 0x8017ED24: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8017ED28: jal         0x800C7A9C
    // 0x8017ED2C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    func_800C7A9C(rdram, ctx);
        goto after_78;
    // 0x8017ED2C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_78:
    // 0x8017ED30: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017ED34: addiu       $t3, $t3, 0x3C00
    ctx->r11 = ADD32(ctx->r11, 0X3C00);
    // 0x8017ED38: lw          $t4, 0x5C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X5C);
    // 0x8017ED3C: bne         $t4, $zero, L_8017ED64
    if (ctx->r12 != 0) {
        // 0x8017ED40: nop
    
            goto L_8017ED64;
    }
    // 0x8017ED40: nop

    // 0x8017ED44: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017ED48: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017ED4C: addiu       $a1, $a1, -0xD44
    ctx->r5 = ADD32(ctx->r5, -0XD44);
    // 0x8017ED50: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    // 0x8017ED54: jal         0x800D87E4
    // 0x8017ED58: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    sprintf_recomp(rdram, ctx);
        goto after_79;
    // 0x8017ED58: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    after_79:
    // 0x8017ED5C: b           L_8017ED84
    // 0x8017ED60: nop

        goto L_8017ED84;
    // 0x8017ED60: nop

L_8017ED64:
    // 0x8017ED64: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017ED68: addiu       $t5, $t5, 0x3C00
    ctx->r13 = ADD32(ctx->r13, 0X3C00);
    // 0x8017ED6C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017ED70: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017ED74: addiu       $a1, $a1, -0xD30
    ctx->r5 = ADD32(ctx->r5, -0XD30);
    // 0x8017ED78: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    // 0x8017ED7C: jal         0x800D87E4
    // 0x8017ED80: lw          $a2, 0x5C($t5)
    ctx->r6 = MEM_W(ctx->r13, 0X5C);
    sprintf_recomp(rdram, ctx);
        goto after_80;
    // 0x8017ED80: lw          $a2, 0x5C($t5)
    ctx->r6 = MEM_W(ctx->r13, 0X5C);
    after_80:
L_8017ED84:
    // 0x8017ED84: addiu       $a0, $zero, 0x1A8
    ctx->r4 = ADD32(0, 0X1A8);
    // 0x8017ED88: jal         0x800C7A74
    // 0x8017ED8C: addiu       $a1, $zero, 0xD0
    ctx->r5 = ADD32(0, 0XD0);
    func_800C7A74(rdram, ctx);
        goto after_81;
    // 0x8017ED8C: addiu       $a1, $zero, 0xD0
    ctx->r5 = ADD32(0, 0XD0);
    after_81:
    // 0x8017ED90: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8017ED94: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8017ED98: addiu       $a1, $a1, 0x3B40
    ctx->r5 = ADD32(ctx->r5, 0X3B40);
    // 0x8017ED9C: jal         0x800C767C
    // 0x8017EDA0: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    func_800C767C(rdram, ctx);
        goto after_82;
    // 0x8017EDA0: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    after_82:
L_8017EDA4:
    // 0x8017EDA4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017EDA8: addiu       $t6, $t6, 0x3C00
    ctx->r14 = ADD32(ctx->r14, 0X3C00);
    // 0x8017EDAC: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8017EDB0: andi        $t8, $t7, 0x10
    ctx->r24 = ctx->r15 & 0X10;
    // 0x8017EDB4: beq         $t8, $zero, L_8017EE6C
    if (ctx->r24 == 0) {
        // 0x8017EDB8: nop
    
            goto L_8017EE6C;
    }
    // 0x8017EDB8: nop

    // 0x8017EDBC: addiu       $a0, $zero, 0xDB
    ctx->r4 = ADD32(0, 0XDB);
    // 0x8017EDC0: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8017EDC4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8017EDC8: jal         0x800C7A9C
    // 0x8017EDCC: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    func_800C7A9C(rdram, ctx);
        goto after_83;
    // 0x8017EDCC: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_83:
    // 0x8017EDD0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017EDD4: addiu       $t9, $t9, 0x3C00
    ctx->r25 = ADD32(ctx->r25, 0X3C00);
    // 0x8017EDD8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017EDDC: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017EDE0: addiu       $a1, $a1, -0xD1C
    ctx->r5 = ADD32(ctx->r5, -0XD1C);
    // 0x8017EDE4: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    // 0x8017EDE8: lw          $a2, 0x48($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X48);
    // 0x8017EDEC: jal         0x800D87E4
    // 0x8017EDF0: lw          $a3, 0x38($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X38);
    sprintf_recomp(rdram, ctx);
        goto after_84;
    // 0x8017EDF0: lw          $a3, 0x38($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X38);
    after_84:
    // 0x8017EDF4: addiu       $a0, $zero, 0x110
    ctx->r4 = ADD32(0, 0X110);
    // 0x8017EDF8: jal         0x800C7A74
    // 0x8017EDFC: addiu       $a1, $zero, 0xF0
    ctx->r5 = ADD32(0, 0XF0);
    func_800C7A74(rdram, ctx);
        goto after_85;
    // 0x8017EDFC: addiu       $a1, $zero, 0xF0
    ctx->r5 = ADD32(0, 0XF0);
    after_85:
    // 0x8017EE00: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8017EE04: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8017EE08: addiu       $a1, $a1, 0x3B40
    ctx->r5 = ADD32(ctx->r5, 0X3B40);
    // 0x8017EE0C: jal         0x800C767C
    // 0x8017EE10: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    func_800C767C(rdram, ctx);
        goto after_86;
    // 0x8017EE10: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    after_86:
    // 0x8017EE14: addiu       $a0, $zero, 0xDB
    ctx->r4 = ADD32(0, 0XDB);
    // 0x8017EE18: addiu       $a1, $zero, 0xB6
    ctx->r5 = ADD32(0, 0XB6);
    // 0x8017EE1C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8017EE20: jal         0x800C7A9C
    // 0x8017EE24: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    func_800C7A9C(rdram, ctx);
        goto after_87;
    // 0x8017EE24: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_87:
    // 0x8017EE28: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017EE2C: addiu       $t0, $t0, 0x3C00
    ctx->r8 = ADD32(ctx->r8, 0X3C00);
    // 0x8017EE30: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017EE34: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017EE38: addiu       $a1, $a1, -0xD08
    ctx->r5 = ADD32(ctx->r5, -0XD08);
    // 0x8017EE3C: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    // 0x8017EE40: lw          $a2, 0x70($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X70);
    // 0x8017EE44: jal         0x800D87E4
    // 0x8017EE48: lw          $a3, 0x60($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X60);
    sprintf_recomp(rdram, ctx);
        goto after_88;
    // 0x8017EE48: lw          $a3, 0x60($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X60);
    after_88:
    // 0x8017EE4C: addiu       $a0, $zero, 0x1C0
    ctx->r4 = ADD32(0, 0X1C0);
    // 0x8017EE50: jal         0x800C7A74
    // 0x8017EE54: addiu       $a1, $zero, 0xF0
    ctx->r5 = ADD32(0, 0XF0);
    func_800C7A74(rdram, ctx);
        goto after_89;
    // 0x8017EE54: addiu       $a1, $zero, 0xF0
    ctx->r5 = ADD32(0, 0XF0);
    after_89:
    // 0x8017EE58: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8017EE5C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8017EE60: addiu       $a1, $a1, 0x3B40
    ctx->r5 = ADD32(ctx->r5, 0X3B40);
    // 0x8017EE64: jal         0x800C767C
    // 0x8017EE68: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    func_800C767C(rdram, ctx);
        goto after_90;
    // 0x8017EE68: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    after_90:
L_8017EE6C:
    // 0x8017EE6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017EE70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017EE74: jr          $ra
    // 0x8017EE78: nop

    return;
    // 0x8017EE78: nop

    // 0x8017EE7C: nop

;}
RECOMP_FUNC void func_8017B0C0_0F4810(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017B0C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017B0C4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017B0C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017B0CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8017B0D0: addiu       $t6, $t6, 0x3C00
    ctx->r14 = ADD32(ctx->r14, 0X3C00);
    // 0x8017B0D4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017B0D8: addiu       $t7, $t7, 0x3C00
    ctx->r15 = ADD32(ctx->r15, 0X3C00);
    // 0x8017B0DC: sw          $zero, 0x8($t6)
    MEM_W(0X8, ctx->r14) = 0;
    // 0x8017B0E0: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x8017B0E4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017B0E8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017B0EC: sw          $t8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r24;
    // 0x8017B0F0: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8017B0F4: addiu       $t0, $t0, 0x3C00
    ctx->r8 = ADD32(ctx->r8, 0X3C00);
    // 0x8017B0F8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017B0FC: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x8017B100: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017B104: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x8017B108: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x8017B10C: swc1        $f4, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->f4.u32l;
    // 0x8017B110: lwc1        $f6, 0x4($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X4);
    // 0x8017B114: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8017B118: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8017B11C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017B120: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8017B124: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8017B128: addiu       $t3, $t3, -0x4198
    ctx->r11 = ADD32(ctx->r11, -0X4198);
    // 0x8017B12C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017B130: swc1        $f6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f6.u32l;
    // 0x8017B134: addiu       $t4, $t4, -0x4198
    ctx->r12 = ADD32(ctx->r12, -0X4198);
    // 0x8017B138: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017B13C: swc1        $f8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f8.u32l;
    // 0x8017B140: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8017B144: addiu       $t5, $t5, -0x4198
    ctx->r13 = ADD32(ctx->r13, -0X4198);
    // 0x8017B148: swc1        $f10, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->f10.u32l;
    // 0x8017B14C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017B150: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017B154: swc1        $f16, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->f16.u32l;
    // 0x8017B158: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8017B15C: addiu       $t6, $t6, -0x4198
    ctx->r14 = ADD32(ctx->r14, -0X4198);
    // 0x8017B160: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017B164: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8017B168: addiu       $t8, $t8, -0x4198
    ctx->r24 = ADD32(ctx->r24, -0X4198);
    // 0x8017B16C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017B170: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017B174: swc1        $f18, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f18.u32l;
    // 0x8017B178: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017B17C: addiu       $t7, $t7, -0x4198
    ctx->r15 = ADD32(ctx->r15, -0X4198);
    // 0x8017B180: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017B184: swc1        $f4, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->f4.u32l;
    // 0x8017B188: addiu       $t9, $t9, -0x4198
    ctx->r25 = ADD32(ctx->r25, -0X4198);
    // 0x8017B18C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017B190: swc1        $f6, 0x14($t7)
    MEM_W(0X14, ctx->r15) = ctx->f6.u32l;
    // 0x8017B194: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8017B198: addiu       $t0, $t0, -0x4198
    ctx->r8 = ADD32(ctx->r8, -0X4198);
    // 0x8017B19C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017B1A0: swc1        $f8, 0x18($t9)
    MEM_W(0X18, ctx->r25) = ctx->f8.u32l;
    // 0x8017B1A4: addiu       $t1, $t1, -0x4198
    ctx->r9 = ADD32(ctx->r9, -0X4198);
    // 0x8017B1A8: swc1        $f10, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->f10.u32l;
    // 0x8017B1AC: jal         0x800C3FD0
    // 0x8017B1B0: swc1        $f16, 0x20($t1)
    MEM_W(0X20, ctx->r9) = ctx->f16.u32l;
    func_800C3FD0(rdram, ctx);
        goto after_0;
    // 0x8017B1B0: swc1        $f16, 0x20($t1)
    MEM_W(0X20, ctx->r9) = ctx->f16.u32l;
    after_0:
    // 0x8017B1B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017B1B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017B1BC: jr          $ra
    // 0x8017B1C0: nop

    return;
    // 0x8017B1C0: nop

;}
RECOMP_FUNC void func_8017B1C4_0F4810(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017B1C4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017B1C8: lw          $t6, -0x2E4C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2E4C);
    // 0x8017B1CC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8017B1D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8017B1D4: bne         $t6, $zero, L_8017B764
    if (ctx->r14 != 0) {
        // 0x8017B1D8: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_8017B764;
    }
    // 0x8017B1D8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8017B1DC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017B1E0: addiu       $t7, $t7, 0x3C00
    ctx->r15 = ADD32(ctx->r15, 0X3C00);
    // 0x8017B1E4: lw          $s0, 0x0($t7)
    ctx->r16 = MEM_W(ctx->r15, 0X0);
    // 0x8017B1E8: beq         $s0, $zero, L_8017B208
    if (ctx->r16 == 0) {
        // 0x8017B1EC: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8017B208;
    }
    // 0x8017B1EC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8017B1F0: beq         $s0, $at, L_8017B6B4
    if (ctx->r16 == ctx->r1) {
        // 0x8017B1F4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8017B6B4;
    }
    // 0x8017B1F4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8017B1F8: beq         $s0, $at, L_8017B724
    if (ctx->r16 == ctx->r1) {
        // 0x8017B1FC: nop
    
            goto L_8017B724;
    }
    // 0x8017B1FC: nop

    // 0x8017B200: b           L_8017B764
    // 0x8017B204: nop

        goto L_8017B764;
    // 0x8017B204: nop

L_8017B208:
    // 0x8017B208: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017B20C: addiu       $t8, $t8, 0x3C00
    ctx->r24 = ADD32(ctx->r24, 0X3C00);
    // 0x8017B210: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x8017B214: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017B218: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8017B21C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8017B220: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x8017B224: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8017B228: lhu         $t1, -0x41DE($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X41DE);
    // 0x8017B22C: andi        $t2, $t1, 0xB000
    ctx->r10 = ctx->r9 & 0XB000;
    // 0x8017B230: beq         $t2, $zero, L_8017B29C
    if (ctx->r10 == 0) {
        // 0x8017B234: nop
    
            goto L_8017B29C;
    }
    // 0x8017B234: nop

    // 0x8017B238: jal         0x800D1E30
    // 0x8017B23C: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    func_800D1E30(rdram, ctx);
        goto after_0;
    // 0x8017B23C: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_0:
    // 0x8017B240: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8017B244: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8017B248: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8017B24C: beq         $t3, $at, L_8017B27C
    if (ctx->r11 == ctx->r1) {
        // 0x8017B250: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_8017B27C;
    }
    // 0x8017B250: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8017B254: beq         $t3, $at, L_8017B27C
    if (ctx->r11 == ctx->r1) {
        // 0x8017B258: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8017B27C;
    }
    // 0x8017B258: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8017B25C: beq         $t3, $at, L_8017B27C
    if (ctx->r11 == ctx->r1) {
        // 0x8017B260: nop
    
            goto L_8017B27C;
    }
    // 0x8017B260: nop

    // 0x8017B264: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8017B268: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017B26C: jal         0x800C32CC
    // 0x8017B270: sw          $t4, -0x2E4C($at)
    MEM_W(-0X2E4C, ctx->r1) = ctx->r12;
    func_800C32CC(rdram, ctx);
        goto after_1;
    // 0x8017B270: sw          $t4, -0x2E4C($at)
    MEM_W(-0X2E4C, ctx->r1) = ctx->r12;
    after_1:
    // 0x8017B274: b           L_8017B764
    // 0x8017B278: nop

        goto L_8017B764;
    // 0x8017B278: nop

L_8017B27C:
    // 0x8017B27C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017B280: addiu       $t6, $t6, 0x3C00
    ctx->r14 = ADD32(ctx->r14, 0X3C00);
    // 0x8017B284: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8017B288: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x8017B28C: jal         0x800C8544
    // 0x8017B290: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    func_800C8544(rdram, ctx);
        goto after_2;
    // 0x8017B290: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    after_2:
    // 0x8017B294: b           L_8017B764
    // 0x8017B298: nop

        goto L_8017B764;
    // 0x8017B298: nop

L_8017B29C:
    // 0x8017B29C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017B2A0: addiu       $t7, $t7, 0x3C00
    ctx->r15 = ADD32(ctx->r15, 0X3C00);
    // 0x8017B2A4: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8017B2A8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017B2AC: sll         $t0, $t8, 2
    ctx->r8 = S32(ctx->r24 << 2);
    // 0x8017B2B0: addu        $t0, $t0, $t8
    ctx->r8 = ADD32(ctx->r8, ctx->r24);
    // 0x8017B2B4: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x8017B2B8: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8017B2BC: lb          $t1, -0x41DA($t1)
    ctx->r9 = MEM_B(ctx->r9, -0X41DA);
    // 0x8017B2C0: slti        $at, $t1, 0xF
    ctx->r1 = SIGNED(ctx->r9) < 0XF ? 1 : 0;
    // 0x8017B2C4: bne         $at, $zero, L_8017B2D8
    if (ctx->r1 != 0) {
        // 0x8017B2C8: nop
    
            goto L_8017B2D8;
    }
    // 0x8017B2C8: nop

    // 0x8017B2CC: lw          $t2, 0x8($t7)
    ctx->r10 = MEM_W(ctx->r15, 0X8);
    // 0x8017B2D0: beq         $t2, $zero, L_8017B308
    if (ctx->r10 == 0) {
        // 0x8017B2D4: nop
    
            goto L_8017B308;
    }
    // 0x8017B2D4: nop

L_8017B2D8:
    // 0x8017B2D8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017B2DC: addiu       $t9, $t9, 0x3C00
    ctx->r25 = ADD32(ctx->r25, 0X3C00);
    // 0x8017B2E0: lw          $t3, 0x4($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X4);
    // 0x8017B2E4: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017B2E8: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8017B2EC: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8017B2F0: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x8017B2F4: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8017B2F8: lhu         $t5, -0x41DE($t5)
    ctx->r13 = MEM_HU(ctx->r13, -0X41DE);
    // 0x8017B2FC: andi        $t6, $t5, 0x100
    ctx->r14 = ctx->r13 & 0X100;
    // 0x8017B300: beq         $t6, $zero, L_8017B384
    if (ctx->r14 == 0) {
        // 0x8017B304: nop
    
            goto L_8017B384;
    }
    // 0x8017B304: nop

L_8017B308:
    // 0x8017B308: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017B30C: addiu       $t0, $t0, 0x3C00
    ctx->r8 = ADD32(ctx->r8, 0X3C00);
    // 0x8017B310: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8017B314: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017B318: sw          $t8, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r24;
    // 0x8017B31C: addiu       $t1, $t1, 0x3C00
    ctx->r9 = ADD32(ctx->r9, 0X3C00);
    // 0x8017B320: lw          $t7, 0x4($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X4);
    // 0x8017B324: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017B328: addiu       $t9, $t9, 0x39A0
    ctx->r25 = ADD32(ctx->r25, 0X39A0);
    // 0x8017B32C: sll         $t2, $t7, 5
    ctx->r10 = S32(ctx->r15 << 5);
    // 0x8017B330: addu        $t3, $t2, $t9
    ctx->r11 = ADD32(ctx->r10, ctx->r25);
    // 0x8017B334: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8017B338: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8017B33C: bne         $t4, $at, L_8017B34C
    if (ctx->r12 != ctx->r1) {
        // 0x8017B340: nop
    
            goto L_8017B34C;
    }
    // 0x8017B340: nop

    // 0x8017B344: b           L_8017B374
    // 0x8017B348: sw          $zero, 0x0($t3)
    MEM_W(0X0, ctx->r11) = 0;
        goto L_8017B374;
    // 0x8017B348: sw          $zero, 0x0($t3)
    MEM_W(0X0, ctx->r11) = 0;
L_8017B34C:
    // 0x8017B34C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017B350: addiu       $t5, $t5, 0x3C00
    ctx->r13 = ADD32(ctx->r13, 0X3C00);
    // 0x8017B354: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x8017B358: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017B35C: addiu       $t0, $t0, 0x39A0
    ctx->r8 = ADD32(ctx->r8, 0X39A0);
    // 0x8017B360: sll         $t8, $t6, 5
    ctx->r24 = S32(ctx->r14 << 5);
    // 0x8017B364: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8017B368: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x8017B36C: addiu       $t2, $t7, 0x1
    ctx->r10 = ADD32(ctx->r15, 0X1);
    // 0x8017B370: sw          $t2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r10;
L_8017B374:
    // 0x8017B374: jal         0x800C8544
    // 0x8017B378: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    func_800C8544(rdram, ctx);
        goto after_3;
    // 0x8017B378: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    after_3:
    // 0x8017B37C: b           L_8017B764
    // 0x8017B380: nop

        goto L_8017B764;
    // 0x8017B380: nop

L_8017B384:
    // 0x8017B384: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017B388: addiu       $t9, $t9, 0x3C00
    ctx->r25 = ADD32(ctx->r25, 0X3C00);
    // 0x8017B38C: lw          $t4, 0x4($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X4);
    // 0x8017B390: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017B394: sll         $t3, $t4, 2
    ctx->r11 = S32(ctx->r12 << 2);
    // 0x8017B398: addu        $t3, $t3, $t4
    ctx->r11 = ADD32(ctx->r11, ctx->r12);
    // 0x8017B39C: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x8017B3A0: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x8017B3A4: lb          $t5, -0x41DA($t5)
    ctx->r13 = MEM_B(ctx->r13, -0X41DA);
    // 0x8017B3A8: slti        $at, $t5, -0xE
    ctx->r1 = SIGNED(ctx->r13) < -0XE ? 1 : 0;
    // 0x8017B3AC: beq         $at, $zero, L_8017B3C0
    if (ctx->r1 == 0) {
        // 0x8017B3B0: nop
    
            goto L_8017B3C0;
    }
    // 0x8017B3B0: nop

    // 0x8017B3B4: lw          $t6, 0x8($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X8);
    // 0x8017B3B8: beq         $t6, $zero, L_8017B3F0
    if (ctx->r14 == 0) {
        // 0x8017B3BC: nop
    
            goto L_8017B3F0;
    }
    // 0x8017B3BC: nop

L_8017B3C0:
    // 0x8017B3C0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017B3C4: addiu       $t8, $t8, 0x3C00
    ctx->r24 = ADD32(ctx->r24, 0X3C00);
    // 0x8017B3C8: lw          $t0, 0x4($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X4);
    // 0x8017B3CC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017B3D0: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x8017B3D4: addu        $t7, $t7, $t0
    ctx->r15 = ADD32(ctx->r15, ctx->r8);
    // 0x8017B3D8: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x8017B3DC: addu        $t2, $t2, $t7
    ctx->r10 = ADD32(ctx->r10, ctx->r15);
    // 0x8017B3E0: lhu         $t2, -0x41DE($t2)
    ctx->r10 = MEM_HU(ctx->r10, -0X41DE);
    // 0x8017B3E4: andi        $t1, $t2, 0x200
    ctx->r9 = ctx->r10 & 0X200;
    // 0x8017B3E8: beq         $t1, $zero, L_8017B46C
    if (ctx->r9 == 0) {
        // 0x8017B3EC: nop
    
            goto L_8017B46C;
    }
    // 0x8017B3EC: nop

L_8017B3F0:
    // 0x8017B3F0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017B3F4: addiu       $t3, $t3, 0x3C00
    ctx->r11 = ADD32(ctx->r11, 0X3C00);
    // 0x8017B3F8: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x8017B3FC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017B400: sw          $t4, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r12;
    // 0x8017B404: addiu       $t5, $t5, 0x3C00
    ctx->r13 = ADD32(ctx->r13, 0X3C00);
    // 0x8017B408: lw          $t9, 0x4($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X4);
    // 0x8017B40C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017B410: addiu       $t8, $t8, 0x39A0
    ctx->r24 = ADD32(ctx->r24, 0X39A0);
    // 0x8017B414: sll         $t6, $t9, 5
    ctx->r14 = S32(ctx->r25 << 5);
    // 0x8017B418: addu        $t0, $t6, $t8
    ctx->r8 = ADD32(ctx->r14, ctx->r24);
    // 0x8017B41C: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x8017B420: bne         $t7, $zero, L_8017B434
    if (ctx->r15 != 0) {
        // 0x8017B424: nop
    
            goto L_8017B434;
    }
    // 0x8017B424: nop

    // 0x8017B428: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x8017B42C: b           L_8017B45C
    // 0x8017B430: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
        goto L_8017B45C;
    // 0x8017B430: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
L_8017B434:
    // 0x8017B434: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017B438: addiu       $t1, $t1, 0x3C00
    ctx->r9 = ADD32(ctx->r9, 0X3C00);
    // 0x8017B43C: lw          $t4, 0x4($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X4);
    // 0x8017B440: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017B444: addiu       $t5, $t5, 0x39A0
    ctx->r13 = ADD32(ctx->r13, 0X39A0);
    // 0x8017B448: sll         $t3, $t4, 5
    ctx->r11 = S32(ctx->r12 << 5);
    // 0x8017B44C: addu        $t9, $t3, $t5
    ctx->r25 = ADD32(ctx->r11, ctx->r13);
    // 0x8017B450: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x8017B454: addiu       $t8, $t6, -0x1
    ctx->r24 = ADD32(ctx->r14, -0X1);
    // 0x8017B458: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
L_8017B45C:
    // 0x8017B45C: jal         0x800C8544
    // 0x8017B460: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    func_800C8544(rdram, ctx);
        goto after_4;
    // 0x8017B460: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    after_4:
    // 0x8017B464: b           L_8017B764
    // 0x8017B468: nop

        goto L_8017B764;
    // 0x8017B468: nop

L_8017B46C:
    // 0x8017B46C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017B470: addiu       $t7, $t7, 0x3C00
    ctx->r15 = ADD32(ctx->r15, 0X3C00);
    // 0x8017B474: lw          $t2, 0x4($t7)
    ctx->r10 = MEM_W(ctx->r15, 0X4);
    // 0x8017B478: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017B47C: sll         $t0, $t2, 2
    ctx->r8 = S32(ctx->r10 << 2);
    // 0x8017B480: addu        $t0, $t0, $t2
    ctx->r8 = ADD32(ctx->r8, ctx->r10);
    // 0x8017B484: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x8017B488: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8017B48C: lb          $t1, -0x41D9($t1)
    ctx->r9 = MEM_B(ctx->r9, -0X41D9);
    // 0x8017B490: slti        $at, $t1, 0xF
    ctx->r1 = SIGNED(ctx->r9) < 0XF ? 1 : 0;
    // 0x8017B494: bne         $at, $zero, L_8017B4A8
    if (ctx->r1 != 0) {
        // 0x8017B498: nop
    
            goto L_8017B4A8;
    }
    // 0x8017B498: nop

    // 0x8017B49C: lw          $t4, 0x8($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X8);
    // 0x8017B4A0: beq         $t4, $zero, L_8017B4D8
    if (ctx->r12 == 0) {
        // 0x8017B4A4: nop
    
            goto L_8017B4D8;
    }
    // 0x8017B4A4: nop

L_8017B4A8:
    // 0x8017B4A8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017B4AC: addiu       $t3, $t3, 0x3C00
    ctx->r11 = ADD32(ctx->r11, 0X3C00);
    // 0x8017B4B0: lw          $t5, 0x4($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X4);
    // 0x8017B4B4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017B4B8: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8017B4BC: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8017B4C0: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x8017B4C4: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x8017B4C8: lhu         $t8, -0x41DE($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X41DE);
    // 0x8017B4CC: andi        $t9, $t8, 0x400
    ctx->r25 = ctx->r24 & 0X400;
    // 0x8017B4D0: beq         $t9, $zero, L_8017B554
    if (ctx->r25 == 0) {
        // 0x8017B4D4: nop
    
            goto L_8017B554;
    }
    // 0x8017B4D4: nop

L_8017B4D8:
    // 0x8017B4D8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017B4DC: addiu       $t0, $t0, 0x3C00
    ctx->r8 = ADD32(ctx->r8, 0X3C00);
    // 0x8017B4E0: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x8017B4E4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017B4E8: sw          $t2, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r10;
    // 0x8017B4EC: addiu       $t1, $t1, 0x3C00
    ctx->r9 = ADD32(ctx->r9, 0X3C00);
    // 0x8017B4F0: lw          $t7, 0x4($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X4);
    // 0x8017B4F4: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017B4F8: addiu       $t3, $t3, 0x39A0
    ctx->r11 = ADD32(ctx->r11, 0X39A0);
    // 0x8017B4FC: sll         $t4, $t7, 5
    ctx->r12 = S32(ctx->r15 << 5);
    // 0x8017B500: addu        $t5, $t4, $t3
    ctx->r13 = ADD32(ctx->r12, ctx->r11);
    // 0x8017B504: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x8017B508: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8017B50C: bne         $t6, $at, L_8017B51C
    if (ctx->r14 != ctx->r1) {
        // 0x8017B510: nop
    
            goto L_8017B51C;
    }
    // 0x8017B510: nop

    // 0x8017B514: b           L_8017B544
    // 0x8017B518: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
        goto L_8017B544;
    // 0x8017B518: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
L_8017B51C:
    // 0x8017B51C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017B520: addiu       $t8, $t8, 0x3C00
    ctx->r24 = ADD32(ctx->r24, 0X3C00);
    // 0x8017B524: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x8017B528: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017B52C: addiu       $t0, $t0, 0x39A0
    ctx->r8 = ADD32(ctx->r8, 0X39A0);
    // 0x8017B530: sll         $t2, $t9, 5
    ctx->r10 = S32(ctx->r25 << 5);
    // 0x8017B534: addu        $t1, $t2, $t0
    ctx->r9 = ADD32(ctx->r10, ctx->r8);
    // 0x8017B538: lw          $t7, 0x4($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X4);
    // 0x8017B53C: addiu       $t4, $t7, 0x1
    ctx->r12 = ADD32(ctx->r15, 0X1);
    // 0x8017B540: sw          $t4, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r12;
L_8017B544:
    // 0x8017B544: jal         0x800C8544
    // 0x8017B548: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    func_800C8544(rdram, ctx);
        goto after_5;
    // 0x8017B548: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    after_5:
    // 0x8017B54C: b           L_8017B764
    // 0x8017B550: nop

        goto L_8017B764;
    // 0x8017B550: nop

L_8017B554:
    // 0x8017B554: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017B558: addiu       $t3, $t3, 0x3C00
    ctx->r11 = ADD32(ctx->r11, 0X3C00);
    // 0x8017B55C: lw          $t6, 0x4($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X4);
    // 0x8017B560: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017B564: sll         $t5, $t6, 2
    ctx->r13 = S32(ctx->r14 << 2);
    // 0x8017B568: addu        $t5, $t5, $t6
    ctx->r13 = ADD32(ctx->r13, ctx->r14);
    // 0x8017B56C: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x8017B570: addu        $t8, $t8, $t5
    ctx->r24 = ADD32(ctx->r24, ctx->r13);
    // 0x8017B574: lb          $t8, -0x41D9($t8)
    ctx->r24 = MEM_B(ctx->r24, -0X41D9);
    // 0x8017B578: slti        $at, $t8, -0xE
    ctx->r1 = SIGNED(ctx->r24) < -0XE ? 1 : 0;
    // 0x8017B57C: beq         $at, $zero, L_8017B590
    if (ctx->r1 == 0) {
        // 0x8017B580: nop
    
            goto L_8017B590;
    }
    // 0x8017B580: nop

    // 0x8017B584: lw          $t9, 0x8($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X8);
    // 0x8017B588: beq         $t9, $zero, L_8017B5C0
    if (ctx->r25 == 0) {
        // 0x8017B58C: nop
    
            goto L_8017B5C0;
    }
    // 0x8017B58C: nop

L_8017B590:
    // 0x8017B590: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017B594: addiu       $t2, $t2, 0x3C00
    ctx->r10 = ADD32(ctx->r10, 0X3C00);
    // 0x8017B598: lw          $t0, 0x4($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X4);
    // 0x8017B59C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017B5A0: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x8017B5A4: addu        $t7, $t7, $t0
    ctx->r15 = ADD32(ctx->r15, ctx->r8);
    // 0x8017B5A8: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x8017B5AC: addu        $t4, $t4, $t7
    ctx->r12 = ADD32(ctx->r12, ctx->r15);
    // 0x8017B5B0: lhu         $t4, -0x41DE($t4)
    ctx->r12 = MEM_HU(ctx->r12, -0X41DE);
    // 0x8017B5B4: andi        $t1, $t4, 0x800
    ctx->r9 = ctx->r12 & 0X800;
    // 0x8017B5B8: beq         $t1, $zero, L_8017B63C
    if (ctx->r9 == 0) {
        // 0x8017B5BC: nop
    
            goto L_8017B63C;
    }
    // 0x8017B5BC: nop

L_8017B5C0:
    // 0x8017B5C0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017B5C4: addiu       $t5, $t5, 0x3C00
    ctx->r13 = ADD32(ctx->r13, 0X3C00);
    // 0x8017B5C8: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8017B5CC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017B5D0: sw          $t6, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r14;
    // 0x8017B5D4: addiu       $t8, $t8, 0x3C00
    ctx->r24 = ADD32(ctx->r24, 0X3C00);
    // 0x8017B5D8: lw          $t3, 0x4($t8)
    ctx->r11 = MEM_W(ctx->r24, 0X4);
    // 0x8017B5DC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017B5E0: addiu       $t2, $t2, 0x39A0
    ctx->r10 = ADD32(ctx->r10, 0X39A0);
    // 0x8017B5E4: sll         $t9, $t3, 5
    ctx->r25 = S32(ctx->r11 << 5);
    // 0x8017B5E8: addu        $t0, $t9, $t2
    ctx->r8 = ADD32(ctx->r25, ctx->r10);
    // 0x8017B5EC: lw          $t7, 0x4($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X4);
    // 0x8017B5F0: bne         $t7, $zero, L_8017B604
    if (ctx->r15 != 0) {
        // 0x8017B5F4: nop
    
            goto L_8017B604;
    }
    // 0x8017B5F4: nop

    // 0x8017B5F8: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x8017B5FC: b           L_8017B62C
    // 0x8017B600: sw          $t4, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r12;
        goto L_8017B62C;
    // 0x8017B600: sw          $t4, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r12;
L_8017B604:
    // 0x8017B604: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017B608: addiu       $t1, $t1, 0x3C00
    ctx->r9 = ADD32(ctx->r9, 0X3C00);
    // 0x8017B60C: lw          $t6, 0x4($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X4);
    // 0x8017B610: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017B614: addiu       $t8, $t8, 0x39A0
    ctx->r24 = ADD32(ctx->r24, 0X39A0);
    // 0x8017B618: sll         $t5, $t6, 5
    ctx->r13 = S32(ctx->r14 << 5);
    // 0x8017B61C: addu        $t3, $t5, $t8
    ctx->r11 = ADD32(ctx->r13, ctx->r24);
    // 0x8017B620: lw          $t9, 0x4($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X4);
    // 0x8017B624: addiu       $t2, $t9, -0x1
    ctx->r10 = ADD32(ctx->r25, -0X1);
    // 0x8017B628: sw          $t2, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r10;
L_8017B62C:
    // 0x8017B62C: jal         0x800C8544
    // 0x8017B630: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    func_800C8544(rdram, ctx);
        goto after_6;
    // 0x8017B630: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    after_6:
    // 0x8017B634: b           L_8017B764
    // 0x8017B638: nop

        goto L_8017B764;
    // 0x8017B638: nop

L_8017B63C:
    // 0x8017B63C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017B640: addiu       $t7, $t7, 0x3C00
    ctx->r15 = ADD32(ctx->r15, 0X3C00);
    // 0x8017B644: lw          $t4, 0x4($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X4);
    // 0x8017B648: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017B64C: sll         $t0, $t4, 2
    ctx->r8 = S32(ctx->r12 << 2);
    // 0x8017B650: addu        $t0, $t0, $t4
    ctx->r8 = ADD32(ctx->r8, ctx->r12);
    // 0x8017B654: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x8017B658: addu        $a0, $a0, $t0
    ctx->r4 = ADD32(ctx->r4, ctx->r8);
    // 0x8017B65C: jal         0x800E4D30
    // 0x8017B660: lb          $a0, -0x41DA($a0)
    ctx->r4 = MEM_B(ctx->r4, -0X41DA);
    func_800E4D30(rdram, ctx);
        goto after_7;
    // 0x8017B660: lb          $a0, -0x41DA($a0)
    ctx->r4 = MEM_B(ctx->r4, -0X41DA);
    after_7:
    // 0x8017B664: slti        $at, $v0, 0x5
    ctx->r1 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x8017B668: beq         $at, $zero, L_8017B764
    if (ctx->r1 == 0) {
        // 0x8017B66C: nop
    
            goto L_8017B764;
    }
    // 0x8017B66C: nop

    // 0x8017B670: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017B674: addiu       $t1, $t1, 0x3C00
    ctx->r9 = ADD32(ctx->r9, 0X3C00);
    // 0x8017B678: lw          $t6, 0x4($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X4);
    // 0x8017B67C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017B680: sll         $t5, $t6, 2
    ctx->r13 = S32(ctx->r14 << 2);
    // 0x8017B684: addu        $t5, $t5, $t6
    ctx->r13 = ADD32(ctx->r13, ctx->r14);
    // 0x8017B688: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x8017B68C: addu        $a0, $a0, $t5
    ctx->r4 = ADD32(ctx->r4, ctx->r13);
    // 0x8017B690: jal         0x800E4D30
    // 0x8017B694: lb          $a0, -0x41D9($a0)
    ctx->r4 = MEM_B(ctx->r4, -0X41D9);
    func_800E4D30(rdram, ctx);
        goto after_8;
    // 0x8017B694: lb          $a0, -0x41D9($a0)
    ctx->r4 = MEM_B(ctx->r4, -0X41D9);
    after_8:
    // 0x8017B698: slti        $at, $v0, 0x5
    ctx->r1 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x8017B69C: beq         $at, $zero, L_8017B764
    if (ctx->r1 == 0) {
        // 0x8017B6A0: nop
    
            goto L_8017B764;
    }
    // 0x8017B6A0: nop

    // 0x8017B6A4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017B6A8: addiu       $t8, $t8, 0x3C00
    ctx->r24 = ADD32(ctx->r24, 0X3C00);
    // 0x8017B6AC: b           L_8017B764
    // 0x8017B6B0: sw          $zero, 0x8($t8)
    MEM_W(0X8, ctx->r24) = 0;
        goto L_8017B764;
    // 0x8017B6B0: sw          $zero, 0x8($t8)
    MEM_W(0X8, ctx->r24) = 0;
L_8017B6B4:
    // 0x8017B6B4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017B6B8: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x8017B6BC: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x8017B6C0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017B6C4: lwc1        $f4, 0x4($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X4);
    // 0x8017B6C8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017B6CC: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x8017B6D0: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8017B6D4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017B6D8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8017B6DC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017B6E0: swc1        $f8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f8.u32l;
    // 0x8017B6E4: lwc1        $f10, 0x0($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X0);
    // 0x8017B6E8: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x8017B6EC: lui         $at, 0xC2F0
    ctx->r1 = S32(0XC2F0 << 16);
    // 0x8017B6F0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8017B6F4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017B6F8: swc1        $f18, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f18.u32l;
    // 0x8017B6FC: lwc1        $f4, 0x4($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X4);
    // 0x8017B700: c.le.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl <= ctx->f6.fl;
    // 0x8017B704: nop

    // 0x8017B708: bc1f        L_8017B764
    if (!c1cs) {
        // 0x8017B70C: nop
    
            goto L_8017B764;
    }
    // 0x8017B70C: nop

    // 0x8017B710: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017B714: addiu       $t4, $t4, 0x3C00
    ctx->r12 = ADD32(ctx->r12, 0X3C00);
    // 0x8017B718: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8017B71C: b           L_8017B764
    // 0x8017B720: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
        goto L_8017B764;
    // 0x8017B720: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
L_8017B724:
    // 0x8017B724: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017B728: addiu       $t0, $t0, 0x3C00
    ctx->r8 = ADD32(ctx->r8, 0X3C00);
    // 0x8017B72C: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x8017B730: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017B734: sll         $t6, $t1, 2
    ctx->r14 = S32(ctx->r9 << 2);
    // 0x8017B738: addu        $t6, $t6, $t1
    ctx->r14 = ADD32(ctx->r14, ctx->r9);
    // 0x8017B73C: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x8017B740: addu        $t5, $t5, $t6
    ctx->r13 = ADD32(ctx->r13, ctx->r14);
    // 0x8017B744: lhu         $t5, -0x41DE($t5)
    ctx->r13 = MEM_HU(ctx->r13, -0X41DE);
    // 0x8017B748: andi        $t8, $t5, 0xB000
    ctx->r24 = ctx->r13 & 0XB000;
    // 0x8017B74C: beq         $t8, $zero, L_8017B764
    if (ctx->r24 == 0) {
        // 0x8017B750: nop
    
            goto L_8017B764;
    }
    // 0x8017B750: nop

    // 0x8017B754: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8017B758: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017B75C: jal         0x800C32CC
    // 0x8017B760: sw          $t9, -0x2E4C($at)
    MEM_W(-0X2E4C, ctx->r1) = ctx->r25;
    func_800C32CC(rdram, ctx);
        goto after_9;
    // 0x8017B760: sw          $t9, -0x2E4C($at)
    MEM_W(-0X2E4C, ctx->r1) = ctx->r25;
    after_9:
L_8017B764:
    // 0x8017B764: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8017B768: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8017B76C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8017B770: jr          $ra
    // 0x8017B774: nop

    return;
    // 0x8017B774: nop

;}
RECOMP_FUNC void func_8017B778_0F4810(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017B778: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017B77C: lwc1        $f6, -0x4324($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X4324);
    // 0x8017B780: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017B784: lwc1        $f8, -0x4320($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4320);
    // 0x8017B788: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8017B78C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017B790: lwc1        $f10, -0x431C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X431C);
    // 0x8017B794: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017B798: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017B79C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8017B7A0: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x8017B7A4: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8017B7A8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8017B7AC: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8017B7B0: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x8017B7B4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8017B7B8: lwc1        $f16, 0x0($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X0);
    // 0x8017B7BC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8017B7C0: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x8017B7C4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8017B7C8: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8017B7CC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8017B7D0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8017B7D4: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8017B7D8: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x8017B7DC: lwc1        $f6, 0x4($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X4);
    // 0x8017B7E0: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x8017B7E4: addiu       $a0, $a0, 0x3310
    ctx->r4 = ADD32(ctx->r4, 0X3310);
    // 0x8017B7E8: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8017B7EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8017B7F0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8017B7F4: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x8017B7F8: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    // 0x8017B7FC: jal         0x800C58E8
    // 0x8017B800: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    func_800C58E8(rdram, ctx);
        goto after_0;
    // 0x8017B800: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    after_0:
    // 0x8017B804: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8017B808: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8017B80C: jr          $ra
    // 0x8017B810: nop

    return;
    // 0x8017B810: nop

;}
RECOMP_FUNC void func_8017B814_0F4810(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017B814: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017B818: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8017B81C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8017B820: jal         0x800D54C8
    // 0x8017B824: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    spX2Init_recomp(rdram, ctx);
        goto after_0;
    // 0x8017B824: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    after_0:
    // 0x8017B828: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8017B82C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017B830: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8017B834: addiu       $a0, $a0, -0x4160
    ctx->r4 = ADD32(ctx->r4, -0X4160);
    // 0x8017B838: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8017B83C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8017B840: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x8017B844: jal         0x800C6B7C
    // 0x8017B848: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800C6B7C(rdram, ctx);
        goto after_1;
    // 0x8017B848: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8017B84C: jal         0x800C6D5C
    // 0x8017B850: nop

    func_800C6D5C(rdram, ctx);
        goto after_2;
    // 0x8017B850: nop

    after_2:
    // 0x8017B854: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8017B858: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017B85C: jr          $ra
    // 0x8017B860: nop

    return;
    // 0x8017B860: nop

;}
RECOMP_FUNC void func_8017B864_0F4810(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017B864: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017B868: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017B86C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8017B870: addiu       $t6, $t6, 0x3C00
    ctx->r14 = ADD32(ctx->r14, 0X3C00);
    // 0x8017B874: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8017B878: bne         $t7, $zero, L_8017B95C
    if (ctx->r15 != 0) {
        // 0x8017B87C: nop
    
            goto L_8017B95C;
    }
    // 0x8017B87C: nop

    // 0x8017B880: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8017B884: jal         0x800D54C8
    // 0x8017B888: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    spX2Init_recomp(rdram, ctx);
        goto after_0;
    // 0x8017B888: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    after_0:
    // 0x8017B88C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017B890: addiu       $t8, $t8, 0x3C00
    ctx->r24 = ADD32(ctx->r24, 0X3C00);
    // 0x8017B894: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x8017B898: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017B89C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017B8A0: sll         $t0, $t9, 5
    ctx->r8 = S32(ctx->r25 << 5);
    // 0x8017B8A4: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8017B8A8: lw          $t1, 0x39A0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X39A0);
    // 0x8017B8AC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017B8B0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8017B8B4: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8017B8B8: addu        $a0, $a0, $t2
    ctx->r4 = ADD32(ctx->r4, ctx->r10);
    // 0x8017B8BC: lw          $a0, -0x43B0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X43B0);
    // 0x8017B8C0: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x8017B8C4: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    // 0x8017B8C8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8017B8CC: jal         0x800C6B7C
    // 0x8017B8D0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800C6B7C(rdram, ctx);
        goto after_1;
    // 0x8017B8D0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8017B8D4: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017B8D8: addiu       $t3, $t3, 0x3C00
    ctx->r11 = ADD32(ctx->r11, 0X3C00);
    // 0x8017B8DC: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x8017B8E0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017B8E4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017B8E8: sll         $t5, $t4, 5
    ctx->r13 = S32(ctx->r12 << 5);
    // 0x8017B8EC: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8017B8F0: lw          $t6, 0x39A4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X39A4);
    // 0x8017B8F4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017B8F8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8017B8FC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8017B900: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x8017B904: lw          $a0, -0x43A0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X43A0);
    // 0x8017B908: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x8017B90C: addiu       $a2, $zero, 0x160
    ctx->r6 = ADD32(0, 0X160);
    // 0x8017B910: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8017B914: jal         0x800C6B7C
    // 0x8017B918: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800C6B7C(rdram, ctx);
        goto after_2;
    // 0x8017B918: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x8017B91C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017B920: addiu       $t8, $t8, 0x3C00
    ctx->r24 = ADD32(ctx->r24, 0X3C00);
    // 0x8017B924: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x8017B928: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017B92C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8017B930: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8017B934: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8017B938: addu        $a0, $a0, $t0
    ctx->r4 = ADD32(ctx->r4, ctx->r8);
    // 0x8017B93C: lw          $a0, -0x4394($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4394);
    // 0x8017B940: addiu       $a1, $zero, 0xC0
    ctx->r5 = ADD32(0, 0XC0);
    // 0x8017B944: addiu       $a2, $zero, 0x190
    ctx->r6 = ADD32(0, 0X190);
    // 0x8017B948: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8017B94C: jal         0x800C6B7C
    // 0x8017B950: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800C6B7C(rdram, ctx);
        goto after_3;
    // 0x8017B950: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_3:
    // 0x8017B954: jal         0x800C6D5C
    // 0x8017B958: nop

    func_800C6D5C(rdram, ctx);
        goto after_4;
    // 0x8017B958: nop

    after_4:
L_8017B95C:
    // 0x8017B95C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8017B960: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017B964: jr          $ra
    // 0x8017B968: nop

    return;
    // 0x8017B968: nop

;}
RECOMP_FUNC void func_8017B96C_0F4810(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017B96C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017B970: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017B974: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017B978: addiu       $t6, $t6, 0x3C00
    ctx->r14 = ADD32(ctx->r14, 0X3C00);
    // 0x8017B97C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8017B980: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8017B984: bne         $t7, $at, L_8017BA94
    if (ctx->r15 != ctx->r1) {
        // 0x8017B988: nop
    
            goto L_8017BA94;
    }
    // 0x8017B988: nop

    // 0x8017B98C: jal         0x800C7AD0
    // 0x8017B990: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800C7AD0(rdram, ctx);
        goto after_0;
    // 0x8017B990: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x8017B994: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    // 0x8017B998: jal         0x800C7A60
    // 0x8017B99C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C7A60(rdram, ctx);
        goto after_1;
    // 0x8017B99C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8017B9A0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8017B9A4: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x8017B9A8: mtc1        $at, $f15
    ctx->f_odd[(15 - 1) * 2] = ctx->r1;
    // 0x8017B9AC: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8017B9B0: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8017B9B4: jal         0x800C7A88
    // 0x8017B9B8: nop

    func_800C7A88(rdram, ctx);
        goto after_2;
    // 0x8017B9B8: nop

    after_2:
    // 0x8017B9BC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017B9C0: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017B9C4: addiu       $a1, $a1, -0x4380
    ctx->r5 = ADD32(ctx->r5, -0X4380);
    // 0x8017B9C8: jal         0x800D87E4
    // 0x8017B9CC: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_3;
    // 0x8017B9CC: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_3:
    // 0x8017B9D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8017B9D4: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    // 0x8017B9D8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8017B9DC: jal         0x800C7A9C
    // 0x8017B9E0: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    func_800C7A9C(rdram, ctx);
        goto after_4;
    // 0x8017B9E0: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_4:
    // 0x8017B9E4: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    // 0x8017B9E8: jal         0x800C7A74
    // 0x8017B9EC: addiu       $a1, $zero, 0x154
    ctx->r5 = ADD32(0, 0X154);
    func_800C7A74(rdram, ctx);
        goto after_5;
    // 0x8017B9EC: addiu       $a1, $zero, 0x154
    ctx->r5 = ADD32(0, 0X154);
    after_5:
    // 0x8017B9F0: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8017B9F4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8017B9F8: addiu       $a1, $a1, 0x3B40
    ctx->r5 = ADD32(ctx->r5, 0X3B40);
    // 0x8017B9FC: jal         0x800C767C
    // 0x8017BA00: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    func_800C767C(rdram, ctx);
        goto after_6;
    // 0x8017BA00: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    after_6:
    // 0x8017BA04: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017BA08: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017BA0C: addiu       $a1, $a1, -0x435C
    ctx->r5 = ADD32(ctx->r5, -0X435C);
    // 0x8017BA10: jal         0x800D87E4
    // 0x8017BA14: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_7;
    // 0x8017BA14: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_7:
    // 0x8017BA18: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8017BA1C: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    // 0x8017BA20: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8017BA24: jal         0x800C7A9C
    // 0x8017BA28: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    func_800C7A9C(rdram, ctx);
        goto after_8;
    // 0x8017BA28: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_8:
    // 0x8017BA2C: addiu       $a0, $zero, 0x78
    ctx->r4 = ADD32(0, 0X78);
    // 0x8017BA30: jal         0x800C7A74
    // 0x8017BA34: addiu       $a1, $zero, 0x17C
    ctx->r5 = ADD32(0, 0X17C);
    func_800C7A74(rdram, ctx);
        goto after_9;
    // 0x8017BA34: addiu       $a1, $zero, 0x17C
    ctx->r5 = ADD32(0, 0X17C);
    after_9:
    // 0x8017BA38: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8017BA3C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8017BA40: addiu       $a1, $a1, 0x3B40
    ctx->r5 = ADD32(ctx->r5, 0X3B40);
    // 0x8017BA44: jal         0x800C767C
    // 0x8017BA48: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    func_800C767C(rdram, ctx);
        goto after_10;
    // 0x8017BA48: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    after_10:
    // 0x8017BA4C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017BA50: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017BA54: addiu       $a1, $a1, -0x4340
    ctx->r5 = ADD32(ctx->r5, -0X4340);
    // 0x8017BA58: jal         0x800D87E4
    // 0x8017BA5C: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_11;
    // 0x8017BA5C: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_11:
    // 0x8017BA60: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8017BA64: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    // 0x8017BA68: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8017BA6C: jal         0x800C7A9C
    // 0x8017BA70: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    func_800C7A9C(rdram, ctx);
        goto after_12;
    // 0x8017BA70: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_12:
    // 0x8017BA74: addiu       $a0, $zero, 0x68
    ctx->r4 = ADD32(0, 0X68);
    // 0x8017BA78: jal         0x800C7A74
    // 0x8017BA7C: addiu       $a1, $zero, 0x1A4
    ctx->r5 = ADD32(0, 0X1A4);
    func_800C7A74(rdram, ctx);
        goto after_13;
    // 0x8017BA7C: addiu       $a1, $zero, 0x1A4
    ctx->r5 = ADD32(0, 0X1A4);
    after_13:
    // 0x8017BA80: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8017BA84: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8017BA88: addiu       $a1, $a1, 0x3B40
    ctx->r5 = ADD32(ctx->r5, 0X3B40);
    // 0x8017BA8C: jal         0x800C767C
    // 0x8017BA90: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    func_800C767C(rdram, ctx);
        goto after_14;
    // 0x8017BA90: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    after_14:
L_8017BA94:
    // 0x8017BA94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017BA98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017BA9C: jr          $ra
    // 0x8017BAA0: nop

    return;
    // 0x8017BAA0: nop

;}
RECOMP_FUNC void func_8017BAA4_0F4810(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017BAA4: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x8017BAA8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017BAAC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017BAB0: sw          $t6, -0x2E50($at)
    MEM_W(-0X2E50, ctx->r1) = ctx->r14;
    // 0x8017BAB4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017BAB8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017BABC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017BAC0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8017BAC4: addiu       $t7, $t7, -0x2E28
    ctx->r15 = ADD32(ctx->r15, -0X2E28);
    // 0x8017BAC8: sw          $zero, -0x2E4C($at)
    MEM_W(-0X2E4C, ctx->r1) = 0;
    // 0x8017BACC: lbu         $t8, 0xA($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0XA);
    // 0x8017BAD0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017BAD4: addiu       $t0, $t0, -0x2E18
    ctx->r8 = ADD32(ctx->r8, -0X2E18);
    // 0x8017BAD8: andi        $t9, $t8, 0xFD
    ctx->r25 = ctx->r24 & 0XFD;
    // 0x8017BADC: sb          $t9, 0xA($t7)
    MEM_B(0XA, ctx->r15) = ctx->r25;
    // 0x8017BAE0: sw          $zero, 0x8($t0)
    MEM_W(0X8, ctx->r8) = 0;
    // 0x8017BAE4: addiu       $a0, $zero, 0x280
    ctx->r4 = ADD32(0, 0X280);
    // 0x8017BAE8: jal         0x800C30F4
    // 0x8017BAEC: addiu       $a1, $zero, 0x1E0
    ctx->r5 = ADD32(0, 0X1E0);
    func_800C30F4(rdram, ctx);
        goto after_0;
    // 0x8017BAEC: addiu       $a1, $zero, 0x1E0
    ctx->r5 = ADD32(0, 0X1E0);
    after_0:
    // 0x8017BAF0: jal         0x8017B0C0
    // 0x8017BAF4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8017B0C0_0F4810(rdram, ctx);
        goto after_1;
    // 0x8017BAF4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8017BAF8: jal         0x800C328C
    // 0x8017BAFC: nop

    func_800C328C(rdram, ctx);
        goto after_2;
    // 0x8017BAFC: nop

    after_2:
    // 0x8017BB00: jal         0x800C7FA4
    // 0x8017BB04: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    func_800C7FA4(rdram, ctx);
        goto after_3;
    // 0x8017BB04: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    after_3:
    // 0x8017BB08: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8017BB0C: jal         0x800D1640
    // 0x8017BB10: addiu       $a0, $a0, -0x44A0
    ctx->r4 = ADD32(ctx->r4, -0X44A0);
    func_800D1640(rdram, ctx);
        goto after_4;
    // 0x8017BB10: addiu       $a0, $a0, -0x44A0
    ctx->r4 = ADD32(ctx->r4, -0X44A0);
    after_4:
L_8017BB14:
    // 0x8017BB14: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017BB18: lw          $t1, -0x2E4C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2E4C);
    // 0x8017BB1C: beq         $t1, $zero, L_8017BB14
    if (ctx->r9 == 0) {
        // 0x8017BB20: nop
    
            goto L_8017BB14;
    }
    // 0x8017BB20: nop

    // 0x8017BB24: lui         $t2, 0x8011
    ctx->r10 = S32(0X8011 << 16);
    // 0x8017BB28: lhu         $t2, -0x4530($t2)
    ctx->r10 = MEM_HU(ctx->r10, -0X4530);
    // 0x8017BB2C: andi        $t3, $t2, 0x2000
    ctx->r11 = ctx->r10 & 0X2000;
    // 0x8017BB30: bne         $t3, $zero, L_8017BB14
    if (ctx->r11 != 0) {
        // 0x8017BB34: nop
    
            goto L_8017BB14;
    }
    // 0x8017BB34: nop

    // 0x8017BB38: jal         0x800CB720
    // 0x8017BB3C: nop

    func_800CB720(rdram, ctx);
        goto after_5;
    // 0x8017BB3C: nop

    after_5:
    // 0x8017BB40: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8017BB44: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8017BB48: bne         $t4, $zero, L_8017BB14
    if (ctx->r12 != 0) {
        // 0x8017BB4C: nop
    
            goto L_8017BB14;
    }
    // 0x8017BB4C: nop

    // 0x8017BB50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017BB54: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017BB58: jr          $ra
    // 0x8017BB5C: nop

    return;
    // 0x8017BB5C: nop

;}
RECOMP_FUNC void func_8017BB60_0F4810(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017BB60: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017BB64: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8017BB68: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8017BB6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017BB70: bgtz        $t6, L_8017BC40
    if (SIGNED(ctx->r14) > 0) {
        // 0x8017BB74: nop
    
            goto L_8017BC40;
    }
    // 0x8017BB74: nop

    // 0x8017BB78: jal         0x800C3704
    // 0x8017BB7C: nop

    func_800C3704(rdram, ctx);
        goto after_0;
    // 0x8017BB7C: nop

    after_0:
    // 0x8017BB80: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x8017BB84: lw          $t7, -0x4514($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4514);
    // 0x8017BB88: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8017BB8C: lui         $t9, 0xDB06
    ctx->r25 = S32(0XDB06 << 16);
    // 0x8017BB90: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x8017BB94: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8017BB98: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8017BB9C: sw          $t8, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r24;
    // 0x8017BBA0: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x8017BBA4: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8017BBA8: jal         0x800C7458
    // 0x8017BBAC: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    func_800C7458(rdram, ctx);
        goto after_1;
    // 0x8017BBAC: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    after_1:
    // 0x8017BBB0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8017BBB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8017BBB8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8017BBBC: jal         0x800C25FC
    // 0x8017BBC0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800C25FC(rdram, ctx);
        goto after_2;
    // 0x8017BBC0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x8017BBC4: jal         0x8017B814
    // 0x8017BBC8: nop

    func_8017B814_0F4810(rdram, ctx);
        goto after_3;
    // 0x8017BBC8: nop

    after_3:
    // 0x8017BBCC: jal         0x800C3578
    // 0x8017BBD0: nop

    func_800C3578(rdram, ctx);
        goto after_4;
    // 0x8017BBD0: nop

    after_4:
    // 0x8017BBD4: jal         0x800C3FD0
    // 0x8017BBD8: nop

    func_800C3FD0(rdram, ctx);
        goto after_5;
    // 0x8017BBD8: nop

    after_5:
    // 0x8017BBDC: jal         0x8017B1C4
    // 0x8017BBE0: nop

    func_8017B1C4_0F4810(rdram, ctx);
        goto after_6;
    // 0x8017BBE0: nop

    after_6:
    // 0x8017BBE4: jal         0x8017B778
    // 0x8017BBE8: nop

    func_8017B778_0F4810(rdram, ctx);
        goto after_7;
    // 0x8017BBE8: nop

    after_7:
    // 0x8017BBEC: jal         0x8017B864
    // 0x8017BBF0: nop

    func_8017B864_0F4810(rdram, ctx);
        goto after_8;
    // 0x8017BBF0: nop

    after_8:
    // 0x8017BBF4: jal         0x800C3760
    // 0x8017BBF8: nop

    func_800C3760(rdram, ctx);
        goto after_9;
    // 0x8017BBF8: nop

    after_9:
    // 0x8017BBFC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017BC00: lw          $t2, -0x2E4C($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2E4C);
    // 0x8017BC04: beq         $t2, $zero, L_8017BC40
    if (ctx->r10 == 0) {
        // 0x8017BC08: nop
    
            goto L_8017BC40;
    }
    // 0x8017BC08: nop

    // 0x8017BC0C: lui         $t3, 0x8011
    ctx->r11 = S32(0X8011 << 16);
    // 0x8017BC10: lhu         $t3, -0x4530($t3)
    ctx->r11 = MEM_HU(ctx->r11, -0X4530);
    // 0x8017BC14: andi        $t4, $t3, 0x2000
    ctx->r12 = ctx->r11 & 0X2000;
    // 0x8017BC18: bne         $t4, $zero, L_8017BC40
    if (ctx->r12 != 0) {
        // 0x8017BC1C: nop
    
            goto L_8017BC40;
    }
    // 0x8017BC1C: nop

    // 0x8017BC20: jal         0x800CB720
    // 0x8017BC24: nop

    func_800CB720(rdram, ctx);
        goto after_10;
    // 0x8017BC24: nop

    after_10:
    // 0x8017BC28: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8017BC2C: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x8017BC30: bne         $t5, $zero, L_8017BC40
    if (ctx->r13 != 0) {
        // 0x8017BC34: nop
    
            goto L_8017BC40;
    }
    // 0x8017BC34: nop

    // 0x8017BC38: jal         0x800D1640
    // 0x8017BC3C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800D1640(rdram, ctx);
        goto after_11;
    // 0x8017BC3C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_11:
L_8017BC40:
    // 0x8017BC40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017BC44: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017BC48: jr          $ra
    // 0x8017BC4C: nop

    return;
    // 0x8017BC4C: nop

;}
RECOMP_FUNC void func_8017B0C0_111CC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017B0C0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8017B0C4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017B0C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8017B0CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8017B0D0: addiu       $t6, $t6, -0x41E0
    ctx->r14 = ADD32(ctx->r14, -0X41E0);
    // 0x8017B0D4: lb          $t7, 0x7($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X7);
    // 0x8017B0D8: slti        $at, $t7, -0x28
    ctx->r1 = SIGNED(ctx->r15) < -0X28 ? 1 : 0;
    // 0x8017B0DC: bne         $at, $zero, L_8017B100
    if (ctx->r1 != 0) {
        // 0x8017B0E0: slti        $at, $t7, 0x29
        ctx->r1 = SIGNED(ctx->r15) < 0X29 ? 1 : 0;
            goto L_8017B100;
    }
    // 0x8017B0E0: slti        $at, $t7, 0x29
    ctx->r1 = SIGNED(ctx->r15) < 0X29 ? 1 : 0;
    // 0x8017B0E4: beq         $at, $zero, L_8017B100
    if (ctx->r1 == 0) {
        // 0x8017B0E8: nop
    
            goto L_8017B100;
    }
    // 0x8017B0E8: nop

    // 0x8017B0EC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017B0F0: addiu       $t8, $t8, 0x3B00
    ctx->r24 = ADD32(ctx->r24, 0X3B00);
    // 0x8017B0F4: lbu         $t9, 0x21($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X21);
    // 0x8017B0F8: ori         $t0, $t9, 0x1
    ctx->r8 = ctx->r25 | 0X1;
    // 0x8017B0FC: sb          $t0, 0x21($t8)
    MEM_B(0X21, ctx->r24) = ctx->r8;
L_8017B100:
    // 0x8017B100: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017B104: addiu       $t1, $t1, 0x3B00
    ctx->r9 = ADD32(ctx->r9, 0X3B00);
    // 0x8017B108: lbu         $t2, 0x21($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X21);
    // 0x8017B10C: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x8017B110: beq         $t3, $zero, L_8017B130
    if (ctx->r11 == 0) {
        // 0x8017B114: nop
    
            goto L_8017B130;
    }
    // 0x8017B114: nop

    // 0x8017B118: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017B11C: addiu       $t4, $t4, -0x41E0
    ctx->r12 = ADD32(ctx->r12, -0X41E0);
    // 0x8017B120: lb          $t5, 0x7($t4)
    ctx->r13 = MEM_B(ctx->r12, 0X7);
    // 0x8017B124: slti        $at, $t5, 0x29
    ctx->r1 = SIGNED(ctx->r13) < 0X29 ? 1 : 0;
    // 0x8017B128: beq         $at, $zero, L_8017B148
    if (ctx->r1 == 0) {
        // 0x8017B12C: nop
    
            goto L_8017B148;
    }
    // 0x8017B12C: nop

L_8017B130:
    // 0x8017B130: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017B134: addiu       $t6, $t6, -0x41E0
    ctx->r14 = ADD32(ctx->r14, -0X41E0);
    // 0x8017B138: lhu         $t7, 0x4($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X4);
    // 0x8017B13C: andi        $t9, $t7, 0x800
    ctx->r25 = ctx->r15 & 0X800;
    // 0x8017B140: beq         $t9, $zero, L_8017B194
    if (ctx->r25 == 0) {
        // 0x8017B144: nop
    
            goto L_8017B194;
    }
    // 0x8017B144: nop

L_8017B148:
    // 0x8017B148: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017B14C: addiu       $t0, $t0, 0x3B00
    ctx->r8 = ADD32(ctx->r8, 0X3B00);
    // 0x8017B150: lbu         $t8, 0x21($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0X21);
    // 0x8017B154: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017B158: addiu       $t2, $t2, 0x3B40
    ctx->r10 = ADD32(ctx->r10, 0X3B40);
    // 0x8017B15C: andi        $t1, $t8, 0xFE
    ctx->r9 = ctx->r24 & 0XFE;
    // 0x8017B160: sb          $t1, 0x21($t0)
    MEM_B(0X21, ctx->r8) = ctx->r9;
    // 0x8017B164: lb          $t3, 0x10($t2)
    ctx->r11 = MEM_B(ctx->r10, 0X10);
    // 0x8017B168: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017B16C: addiu       $t5, $t5, 0x3B40
    ctx->r13 = ADD32(ctx->r13, 0X3B40);
    // 0x8017B170: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x8017B174: sb          $t4, 0x10($t2)
    MEM_B(0X10, ctx->r10) = ctx->r12;
    // 0x8017B178: lb          $t6, 0x10($t5)
    ctx->r14 = MEM_B(ctx->r13, 0X10);
    // 0x8017B17C: bgez        $t6, L_8017B18C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8017B180: nop
    
            goto L_8017B18C;
    }
    // 0x8017B180: nop

    // 0x8017B184: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x8017B188: sb          $t7, 0x10($t5)
    MEM_B(0X10, ctx->r13) = ctx->r15;
L_8017B18C:
    // 0x8017B18C: jal         0x800C8544
    // 0x8017B190: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    func_800C8544(rdram, ctx);
        goto after_0;
    // 0x8017B190: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    after_0:
L_8017B194:
    // 0x8017B194: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017B198: addiu       $t9, $t9, 0x3B00
    ctx->r25 = ADD32(ctx->r25, 0X3B00);
    // 0x8017B19C: lbu         $t8, 0x21($t9)
    ctx->r24 = MEM_BU(ctx->r25, 0X21);
    // 0x8017B1A0: andi        $t1, $t8, 0x1
    ctx->r9 = ctx->r24 & 0X1;
    // 0x8017B1A4: beq         $t1, $zero, L_8017B1C4
    if (ctx->r9 == 0) {
        // 0x8017B1A8: nop
    
            goto L_8017B1C4;
    }
    // 0x8017B1A8: nop

    // 0x8017B1AC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017B1B0: addiu       $t0, $t0, -0x41E0
    ctx->r8 = ADD32(ctx->r8, -0X41E0);
    // 0x8017B1B4: lb          $t3, 0x7($t0)
    ctx->r11 = MEM_B(ctx->r8, 0X7);
    // 0x8017B1B8: slti        $at, $t3, -0x28
    ctx->r1 = SIGNED(ctx->r11) < -0X28 ? 1 : 0;
    // 0x8017B1BC: bne         $at, $zero, L_8017B1DC
    if (ctx->r1 != 0) {
        // 0x8017B1C0: nop
    
            goto L_8017B1DC;
    }
    // 0x8017B1C0: nop

L_8017B1C4:
    // 0x8017B1C4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017B1C8: addiu       $t4, $t4, -0x41E0
    ctx->r12 = ADD32(ctx->r12, -0X41E0);
    // 0x8017B1CC: lhu         $t2, 0x4($t4)
    ctx->r10 = MEM_HU(ctx->r12, 0X4);
    // 0x8017B1D0: andi        $t6, $t2, 0x400
    ctx->r14 = ctx->r10 & 0X400;
    // 0x8017B1D4: beq         $t6, $zero, L_8017B228
    if (ctx->r14 == 0) {
        // 0x8017B1D8: nop
    
            goto L_8017B228;
    }
    // 0x8017B1D8: nop

L_8017B1DC:
    // 0x8017B1DC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017B1E0: addiu       $t7, $t7, 0x3B00
    ctx->r15 = ADD32(ctx->r15, 0X3B00);
    // 0x8017B1E4: lbu         $t5, 0x21($t7)
    ctx->r13 = MEM_BU(ctx->r15, 0X21);
    // 0x8017B1E8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017B1EC: addiu       $t8, $t8, 0x3B40
    ctx->r24 = ADD32(ctx->r24, 0X3B40);
    // 0x8017B1F0: andi        $t9, $t5, 0xFE
    ctx->r25 = ctx->r13 & 0XFE;
    // 0x8017B1F4: sb          $t9, 0x21($t7)
    MEM_B(0X21, ctx->r15) = ctx->r25;
    // 0x8017B1F8: lb          $t1, 0x10($t8)
    ctx->r9 = MEM_B(ctx->r24, 0X10);
    // 0x8017B1FC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017B200: addiu       $t3, $t3, 0x3B40
    ctx->r11 = ADD32(ctx->r11, 0X3B40);
    // 0x8017B204: addiu       $t0, $t1, 0x1
    ctx->r8 = ADD32(ctx->r9, 0X1);
    // 0x8017B208: sb          $t0, 0x10($t8)
    MEM_B(0X10, ctx->r24) = ctx->r8;
    // 0x8017B20C: lb          $t4, 0x10($t3)
    ctx->r12 = MEM_B(ctx->r11, 0X10);
    // 0x8017B210: slti        $at, $t4, 0x4
    ctx->r1 = SIGNED(ctx->r12) < 0X4 ? 1 : 0;
    // 0x8017B214: bne         $at, $zero, L_8017B220
    if (ctx->r1 != 0) {
        // 0x8017B218: nop
    
            goto L_8017B220;
    }
    // 0x8017B218: nop

    // 0x8017B21C: sb          $zero, 0x10($t3)
    MEM_B(0X10, ctx->r11) = 0;
L_8017B220:
    // 0x8017B220: jal         0x800C8544
    // 0x8017B224: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    func_800C8544(rdram, ctx);
        goto after_1;
    // 0x8017B224: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    after_1:
L_8017B228:
    // 0x8017B228: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017B22C: addiu       $t2, $t2, -0x41E0
    ctx->r10 = ADD32(ctx->r10, -0X41E0);
    // 0x8017B230: lhu         $t6, 0x2($t2)
    ctx->r14 = MEM_HU(ctx->r10, 0X2);
    // 0x8017B234: andi        $t5, $t6, 0xB000
    ctx->r13 = ctx->r14 & 0XB000;
    // 0x8017B238: beq         $t5, $zero, L_8017B2E4
    if (ctx->r13 == 0) {
        // 0x8017B23C: nop
    
            goto L_8017B2E4;
    }
    // 0x8017B23C: nop

    // 0x8017B240: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017B244: addiu       $t9, $t9, 0x3B40
    ctx->r25 = ADD32(ctx->r25, 0X3B40);
    // 0x8017B248: lb          $s0, 0x10($t9)
    ctx->r16 = MEM_B(ctx->r25, 0X10);
    // 0x8017B24C: beq         $s0, $zero, L_8017B274
    if (ctx->r16 == 0) {
        // 0x8017B250: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8017B274;
    }
    // 0x8017B250: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8017B254: beq         $s0, $at, L_8017B294
    if (ctx->r16 == ctx->r1) {
        // 0x8017B258: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8017B294;
    }
    // 0x8017B258: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8017B25C: beq         $s0, $at, L_8017B2B4
    if (ctx->r16 == ctx->r1) {
        // 0x8017B260: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8017B2B4;
    }
    // 0x8017B260: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8017B264: beq         $s0, $at, L_8017B2D4
    if (ctx->r16 == ctx->r1) {
        // 0x8017B268: nop
    
            goto L_8017B2D4;
    }
    // 0x8017B268: nop

    // 0x8017B26C: b           L_8017B2E4
    // 0x8017B270: nop

        goto L_8017B2E4;
    // 0x8017B270: nop

L_8017B274:
    // 0x8017B274: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017B278: addiu       $t7, $t7, 0x3B40
    ctx->r15 = ADD32(ctx->r15, 0X3B40);
    // 0x8017B27C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017B280: sb          $zero, 0x11($t7)
    MEM_B(0X11, ctx->r15) = 0;
    // 0x8017B284: addiu       $t0, $t0, 0x3B40
    ctx->r8 = ADD32(ctx->r8, 0X3B40);
    // 0x8017B288: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8017B28C: b           L_8017B2E4
    // 0x8017B290: sb          $t1, 0x1($t0)
    MEM_B(0X1, ctx->r8) = ctx->r9;
        goto L_8017B2E4;
    // 0x8017B290: sb          $t1, 0x1($t0)
    MEM_B(0X1, ctx->r8) = ctx->r9;
L_8017B294:
    // 0x8017B294: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017B298: addiu       $t8, $t8, 0x3B40
    ctx->r24 = ADD32(ctx->r24, 0X3B40);
    // 0x8017B29C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017B2A0: sb          $zero, 0x12($t8)
    MEM_B(0X12, ctx->r24) = 0;
    // 0x8017B2A4: addiu       $t3, $t3, 0x3B40
    ctx->r11 = ADD32(ctx->r11, 0X3B40);
    // 0x8017B2A8: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x8017B2AC: b           L_8017B2E4
    // 0x8017B2B0: sb          $t4, 0x1($t3)
    MEM_B(0X1, ctx->r11) = ctx->r12;
        goto L_8017B2E4;
    // 0x8017B2B0: sb          $t4, 0x1($t3)
    MEM_B(0X1, ctx->r11) = ctx->r12;
L_8017B2B4:
    // 0x8017B2B4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017B2B8: addiu       $t2, $t2, 0x3B40
    ctx->r10 = ADD32(ctx->r10, 0X3B40);
    // 0x8017B2BC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017B2C0: sb          $zero, 0x13($t2)
    MEM_B(0X13, ctx->r10) = 0;
    // 0x8017B2C4: addiu       $t5, $t5, 0x3B40
    ctx->r13 = ADD32(ctx->r13, 0X3B40);
    // 0x8017B2C8: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x8017B2CC: b           L_8017B2E4
    // 0x8017B2D0: sb          $t6, 0x1($t5)
    MEM_B(0X1, ctx->r13) = ctx->r14;
        goto L_8017B2E4;
    // 0x8017B2D0: sb          $t6, 0x1($t5)
    MEM_B(0X1, ctx->r13) = ctx->r14;
L_8017B2D4:
    // 0x8017B2D4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017B2D8: addiu       $t7, $t7, 0x3B40
    ctx->r15 = ADD32(ctx->r15, 0X3B40);
    // 0x8017B2DC: addiu       $t9, $zero, 0x6
    ctx->r25 = ADD32(0, 0X6);
    // 0x8017B2E0: sb          $t9, 0x1($t7)
    MEM_B(0X1, ctx->r15) = ctx->r25;
L_8017B2E4:
    // 0x8017B2E4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017B2E8: addiu       $t1, $t1, -0x41E0
    ctx->r9 = ADD32(ctx->r9, -0X41E0);
    // 0x8017B2EC: lhu         $t0, 0x2($t1)
    ctx->r8 = MEM_HU(ctx->r9, 0X2);
    // 0x8017B2F0: andi        $t8, $t0, 0x4000
    ctx->r24 = ctx->r8 & 0X4000;
    // 0x8017B2F4: beq         $t8, $zero, L_8017B32C
    if (ctx->r24 == 0) {
        // 0x8017B2F8: nop
    
            goto L_8017B32C;
    }
    // 0x8017B2F8: nop

    // 0x8017B2FC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017B300: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017B304: addiu       $t3, $t3, 0x3B40
    ctx->r11 = ADD32(ctx->r11, 0X3B40);
    // 0x8017B308: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x8017B30C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017B310: sb          $t4, 0x1($t3)
    MEM_B(0X1, ctx->r11) = ctx->r12;
    // 0x8017B314: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x8017B318: jal         0x800C32CC
    // 0x8017B31C: swc1        $f4, 0x80($t2)
    MEM_W(0X80, ctx->r10) = ctx->f4.u32l;
    func_800C32CC(rdram, ctx);
        goto after_2;
    // 0x8017B31C: swc1        $f4, 0x80($t2)
    MEM_W(0X80, ctx->r10) = ctx->f4.u32l;
    after_2:
    // 0x8017B320: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8017B324: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017B328: sh          $t6, -0x2E4C($at)
    MEM_H(-0X2E4C, ctx->r1) = ctx->r14;
L_8017B32C:
    // 0x8017B32C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8017B330: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8017B334: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8017B338: jr          $ra
    // 0x8017B33C: nop

    return;
    // 0x8017B33C: nop

;}
RECOMP_FUNC void func_8017B340_111CC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017B340: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017B344: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017B348: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017B34C: addiu       $t6, $t6, 0x3B40
    ctx->r14 = ADD32(ctx->r14, 0X3B40);
    // 0x8017B350: lb          $t7, 0x11($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X11);
    // 0x8017B354: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8017B358: bne         $t7, $at, L_8017B50C
    if (ctx->r15 != ctx->r1) {
        // 0x8017B35C: nop
    
            goto L_8017B50C;
    }
    // 0x8017B35C: nop

    // 0x8017B360: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017B364: addiu       $t8, $t8, -0x41E0
    ctx->r24 = ADD32(ctx->r24, -0X41E0);
    // 0x8017B368: lb          $t9, 0x6($t8)
    ctx->r25 = MEM_B(ctx->r24, 0X6);
    // 0x8017B36C: slti        $at, $t9, -0x28
    ctx->r1 = SIGNED(ctx->r25) < -0X28 ? 1 : 0;
    // 0x8017B370: bne         $at, $zero, L_8017B394
    if (ctx->r1 != 0) {
        // 0x8017B374: slti        $at, $t9, 0x29
        ctx->r1 = SIGNED(ctx->r25) < 0X29 ? 1 : 0;
            goto L_8017B394;
    }
    // 0x8017B374: slti        $at, $t9, 0x29
    ctx->r1 = SIGNED(ctx->r25) < 0X29 ? 1 : 0;
    // 0x8017B378: beq         $at, $zero, L_8017B394
    if (ctx->r1 == 0) {
        // 0x8017B37C: nop
    
            goto L_8017B394;
    }
    // 0x8017B37C: nop

    // 0x8017B380: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017B384: addiu       $t0, $t0, 0x3B00
    ctx->r8 = ADD32(ctx->r8, 0X3B00);
    // 0x8017B388: lbu         $t1, 0x21($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X21);
    // 0x8017B38C: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x8017B390: sb          $t2, 0x21($t0)
    MEM_B(0X21, ctx->r8) = ctx->r10;
L_8017B394:
    // 0x8017B394: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017B398: addiu       $t3, $t3, 0x3B00
    ctx->r11 = ADD32(ctx->r11, 0X3B00);
    // 0x8017B39C: lbu         $t4, 0x21($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X21);
    // 0x8017B3A0: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x8017B3A4: beq         $t5, $zero, L_8017B3C4
    if (ctx->r13 == 0) {
        // 0x8017B3A8: nop
    
            goto L_8017B3C4;
    }
    // 0x8017B3A8: nop

    // 0x8017B3AC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017B3B0: addiu       $t6, $t6, -0x41E0
    ctx->r14 = ADD32(ctx->r14, -0X41E0);
    // 0x8017B3B4: lb          $t7, 0x6($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X6);
    // 0x8017B3B8: slti        $at, $t7, 0x29
    ctx->r1 = SIGNED(ctx->r15) < 0X29 ? 1 : 0;
    // 0x8017B3BC: beq         $at, $zero, L_8017B3DC
    if (ctx->r1 == 0) {
        // 0x8017B3C0: nop
    
            goto L_8017B3DC;
    }
    // 0x8017B3C0: nop

L_8017B3C4:
    // 0x8017B3C4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017B3C8: addiu       $t8, $t8, -0x41E0
    ctx->r24 = ADD32(ctx->r24, -0X41E0);
    // 0x8017B3CC: lhu         $t9, 0x4($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X4);
    // 0x8017B3D0: andi        $t1, $t9, 0x100
    ctx->r9 = ctx->r25 & 0X100;
    // 0x8017B3D4: beq         $t1, $zero, L_8017B43C
    if (ctx->r9 == 0) {
        // 0x8017B3D8: nop
    
            goto L_8017B43C;
    }
    // 0x8017B3D8: nop

L_8017B3DC:
    // 0x8017B3DC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017B3E0: addiu       $t2, $t2, 0x3B00
    ctx->r10 = ADD32(ctx->r10, 0X3B00);
    // 0x8017B3E4: lbu         $t0, 0x21($t2)
    ctx->r8 = MEM_BU(ctx->r10, 0X21);
    // 0x8017B3E8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017B3EC: addiu       $t4, $t4, 0x3D00
    ctx->r12 = ADD32(ctx->r12, 0X3D00);
    // 0x8017B3F0: andi        $t3, $t0, 0xFE
    ctx->r11 = ctx->r8 & 0XFE;
    // 0x8017B3F4: sb          $t3, 0x21($t2)
    MEM_B(0X21, ctx->r10) = ctx->r11;
    // 0x8017B3F8: lwc1        $f4, 0x0($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X0);
    // 0x8017B3FC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8017B400: nop

    // 0x8017B404: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x8017B408: nop

    // 0x8017B40C: bc1t        L_8017B420
    if (c1cs) {
        // 0x8017B410: nop
    
            goto L_8017B420;
    }
    // 0x8017B410: nop

    // 0x8017B414: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8017B418: b           L_8017B434
    // 0x8017B41C: swc1        $f8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f8.u32l;
        goto L_8017B434;
    // 0x8017B41C: swc1        $f8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f8.u32l;
L_8017B420:
    // 0x8017B420: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017B424: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017B428: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017B42C: addiu       $t5, $t5, 0x3D00
    ctx->r13 = ADD32(ctx->r13, 0X3D00);
    // 0x8017B430: swc1        $f10, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f10.u32l;
L_8017B434:
    // 0x8017B434: jal         0x800C8544
    // 0x8017B438: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    func_800C8544(rdram, ctx);
        goto after_0;
    // 0x8017B438: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    after_0:
L_8017B43C:
    // 0x8017B43C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017B440: addiu       $t6, $t6, 0x3B00
    ctx->r14 = ADD32(ctx->r14, 0X3B00);
    // 0x8017B444: lbu         $t7, 0x21($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X21);
    // 0x8017B448: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x8017B44C: beq         $t8, $zero, L_8017B46C
    if (ctx->r24 == 0) {
        // 0x8017B450: nop
    
            goto L_8017B46C;
    }
    // 0x8017B450: nop

    // 0x8017B454: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017B458: addiu       $t9, $t9, -0x41E0
    ctx->r25 = ADD32(ctx->r25, -0X41E0);
    // 0x8017B45C: lb          $t1, 0x6($t9)
    ctx->r9 = MEM_B(ctx->r25, 0X6);
    // 0x8017B460: slti        $at, $t1, -0x28
    ctx->r1 = SIGNED(ctx->r9) < -0X28 ? 1 : 0;
    // 0x8017B464: bne         $at, $zero, L_8017B484
    if (ctx->r1 != 0) {
        // 0x8017B468: nop
    
            goto L_8017B484;
    }
    // 0x8017B468: nop

L_8017B46C:
    // 0x8017B46C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017B470: addiu       $t0, $t0, -0x41E0
    ctx->r8 = ADD32(ctx->r8, -0X41E0);
    // 0x8017B474: lhu         $t3, 0x4($t0)
    ctx->r11 = MEM_HU(ctx->r8, 0X4);
    // 0x8017B478: andi        $t2, $t3, 0x200
    ctx->r10 = ctx->r11 & 0X200;
    // 0x8017B47C: beq         $t2, $zero, L_8017B4E4
    if (ctx->r10 == 0) {
        // 0x8017B480: nop
    
            goto L_8017B4E4;
    }
    // 0x8017B480: nop

L_8017B484:
    // 0x8017B484: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017B488: addiu       $t4, $t4, 0x3B00
    ctx->r12 = ADD32(ctx->r12, 0X3B00);
    // 0x8017B48C: lbu         $t5, 0x21($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X21);
    // 0x8017B490: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017B494: addiu       $t7, $t7, 0x3D00
    ctx->r15 = ADD32(ctx->r15, 0X3D00);
    // 0x8017B498: andi        $t6, $t5, 0xFE
    ctx->r14 = ctx->r13 & 0XFE;
    // 0x8017B49C: sb          $t6, 0x21($t4)
    MEM_B(0X21, ctx->r12) = ctx->r14;
    // 0x8017B4A0: lwc1        $f16, 0x0($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X0);
    // 0x8017B4A4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8017B4A8: nop

    // 0x8017B4AC: c.eq.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl == ctx->f18.fl;
    // 0x8017B4B0: nop

    // 0x8017B4B4: bc1t        L_8017B4C8
    if (c1cs) {
        // 0x8017B4B8: nop
    
            goto L_8017B4C8;
    }
    // 0x8017B4B8: nop

    // 0x8017B4BC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017B4C0: b           L_8017B4DC
    // 0x8017B4C4: swc1        $f4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f4.u32l;
        goto L_8017B4DC;
    // 0x8017B4C4: swc1        $f4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f4.u32l;
L_8017B4C8:
    // 0x8017B4C8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017B4CC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017B4D0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017B4D4: addiu       $t8, $t8, 0x3D00
    ctx->r24 = ADD32(ctx->r24, 0X3D00);
    // 0x8017B4D8: swc1        $f6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f6.u32l;
L_8017B4DC:
    // 0x8017B4DC: jal         0x800C8544
    // 0x8017B4E0: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    func_800C8544(rdram, ctx);
        goto after_1;
    // 0x8017B4E0: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    after_1:
L_8017B4E4:
    // 0x8017B4E4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017B4E8: addiu       $t9, $t9, -0x41E0
    ctx->r25 = ADD32(ctx->r25, -0X41E0);
    // 0x8017B4EC: lhu         $t1, 0x2($t9)
    ctx->r9 = MEM_HU(ctx->r25, 0X2);
    // 0x8017B4F0: andi        $t0, $t1, 0xF000
    ctx->r8 = ctx->r9 & 0XF000;
    // 0x8017B4F4: beq         $t0, $zero, L_8017B50C
    if (ctx->r8 == 0) {
        // 0x8017B4F8: nop
    
            goto L_8017B50C;
    }
    // 0x8017B4F8: nop

    // 0x8017B4FC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017B500: addiu       $t2, $t2, 0x3B40
    ctx->r10 = ADD32(ctx->r10, 0X3B40);
    // 0x8017B504: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x8017B508: sb          $t3, 0x11($t2)
    MEM_B(0X11, ctx->r10) = ctx->r11;
L_8017B50C:
    // 0x8017B50C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017B510: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017B514: jr          $ra
    // 0x8017B518: nop

    return;
    // 0x8017B518: nop

;}
RECOMP_FUNC void func_8017B51C_111CC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017B51C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017B520: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017B524: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017B528: addiu       $t6, $t6, 0x3B40
    ctx->r14 = ADD32(ctx->r14, 0X3B40);
    // 0x8017B52C: lb          $t7, 0x12($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X12);
    // 0x8017B530: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8017B534: bne         $t7, $at, L_8017B73C
    if (ctx->r15 != ctx->r1) {
        // 0x8017B538: nop
    
            goto L_8017B73C;
    }
    // 0x8017B538: nop

    // 0x8017B53C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017B540: addiu       $t8, $t8, -0x41E0
    ctx->r24 = ADD32(ctx->r24, -0X41E0);
    // 0x8017B544: lb          $t9, 0x6($t8)
    ctx->r25 = MEM_B(ctx->r24, 0X6);
    // 0x8017B548: slti        $at, $t9, -0x28
    ctx->r1 = SIGNED(ctx->r25) < -0X28 ? 1 : 0;
    // 0x8017B54C: bne         $at, $zero, L_8017B588
    if (ctx->r1 != 0) {
        // 0x8017B550: slti        $at, $t9, 0x29
        ctx->r1 = SIGNED(ctx->r25) < 0X29 ? 1 : 0;
            goto L_8017B588;
    }
    // 0x8017B550: slti        $at, $t9, 0x29
    ctx->r1 = SIGNED(ctx->r25) < 0X29 ? 1 : 0;
    // 0x8017B554: beq         $at, $zero, L_8017B588
    if (ctx->r1 == 0) {
        // 0x8017B558: nop
    
            goto L_8017B588;
    }
    // 0x8017B558: nop

    // 0x8017B55C: lb          $t0, 0x7($t8)
    ctx->r8 = MEM_B(ctx->r24, 0X7);
    // 0x8017B560: slti        $at, $t0, -0x28
    ctx->r1 = SIGNED(ctx->r8) < -0X28 ? 1 : 0;
    // 0x8017B564: bne         $at, $zero, L_8017B588
    if (ctx->r1 != 0) {
        // 0x8017B568: slti        $at, $t0, 0x29
        ctx->r1 = SIGNED(ctx->r8) < 0X29 ? 1 : 0;
            goto L_8017B588;
    }
    // 0x8017B568: slti        $at, $t0, 0x29
    ctx->r1 = SIGNED(ctx->r8) < 0X29 ? 1 : 0;
    // 0x8017B56C: beq         $at, $zero, L_8017B588
    if (ctx->r1 == 0) {
        // 0x8017B570: nop
    
            goto L_8017B588;
    }
    // 0x8017B570: nop

    // 0x8017B574: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017B578: addiu       $t1, $t1, 0x3B00
    ctx->r9 = ADD32(ctx->r9, 0X3B00);
    // 0x8017B57C: lbu         $t2, 0x21($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X21);
    // 0x8017B580: ori         $t3, $t2, 0x1
    ctx->r11 = ctx->r10 | 0X1;
    // 0x8017B584: sb          $t3, 0x21($t1)
    MEM_B(0X21, ctx->r9) = ctx->r11;
L_8017B588:
    // 0x8017B588: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017B58C: addiu       $t4, $t4, 0x3B00
    ctx->r12 = ADD32(ctx->r12, 0X3B00);
    // 0x8017B590: lbu         $t5, 0x21($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X21);
    // 0x8017B594: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x8017B598: beq         $t6, $zero, L_8017B5C8
    if (ctx->r14 == 0) {
        // 0x8017B59C: nop
    
            goto L_8017B5C8;
    }
    // 0x8017B59C: nop

    // 0x8017B5A0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017B5A4: addiu       $t7, $t7, -0x41E0
    ctx->r15 = ADD32(ctx->r15, -0X41E0);
    // 0x8017B5A8: lb          $t9, 0x6($t7)
    ctx->r25 = MEM_B(ctx->r15, 0X6);
    // 0x8017B5AC: slti        $at, $t9, 0x29
    ctx->r1 = SIGNED(ctx->r25) < 0X29 ? 1 : 0;
    // 0x8017B5B0: beq         $at, $zero, L_8017B5E0
    if (ctx->r1 == 0) {
        // 0x8017B5B4: nop
    
            goto L_8017B5E0;
    }
    // 0x8017B5B4: nop

    // 0x8017B5B8: lb          $t8, 0x7($t7)
    ctx->r24 = MEM_B(ctx->r15, 0X7);
    // 0x8017B5BC: slti        $at, $t8, 0x29
    ctx->r1 = SIGNED(ctx->r24) < 0X29 ? 1 : 0;
    // 0x8017B5C0: beq         $at, $zero, L_8017B5E0
    if (ctx->r1 == 0) {
        // 0x8017B5C4: nop
    
            goto L_8017B5E0;
    }
    // 0x8017B5C4: nop

L_8017B5C8:
    // 0x8017B5C8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017B5CC: addiu       $t0, $t0, -0x41E0
    ctx->r8 = ADD32(ctx->r8, -0X41E0);
    // 0x8017B5D0: lhu         $t2, 0x4($t0)
    ctx->r10 = MEM_HU(ctx->r8, 0X4);
    // 0x8017B5D4: andi        $t3, $t2, 0x900
    ctx->r11 = ctx->r10 & 0X900;
    // 0x8017B5D8: beq         $t3, $zero, L_8017B650
    if (ctx->r11 == 0) {
        // 0x8017B5DC: nop
    
            goto L_8017B650;
    }
    // 0x8017B5DC: nop

L_8017B5E0:
    // 0x8017B5E0: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017B5E4: addiu       $t1, $t1, 0x3B00
    ctx->r9 = ADD32(ctx->r9, 0X3B00);
    // 0x8017B5E8: lbu         $t4, 0x21($t1)
    ctx->r12 = MEM_BU(ctx->r9, 0X21);
    // 0x8017B5EC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017B5F0: addiu       $t6, $t6, 0x3D00
    ctx->r14 = ADD32(ctx->r14, 0X3D00);
    // 0x8017B5F4: andi        $t5, $t4, 0xFE
    ctx->r13 = ctx->r12 & 0XFE;
    // 0x8017B5F8: sb          $t5, 0x21($t1)
    MEM_B(0X21, ctx->r9) = ctx->r13;
    // 0x8017B5FC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017B600: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017B604: lwc1        $f4, 0x4($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X4);
    // 0x8017B608: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017B60C: addiu       $t9, $t9, 0x3D00
    ctx->r25 = ADD32(ctx->r25, 0X3D00);
    // 0x8017B610: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8017B614: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8017B618: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8017B61C: swc1        $f8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f8.u32l;
    // 0x8017B620: lwc1        $f10, 0x4($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X4);
    // 0x8017B624: c.lt.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl < ctx->f10.fl;
    // 0x8017B628: nop

    // 0x8017B62C: bc1f        L_8017B640
    if (!c1cs) {
        // 0x8017B630: lui         $at, 0x4100
        ctx->r1 = S32(0X4100 << 16);
            goto L_8017B640;
    }
    // 0x8017B630: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8017B634: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8017B638: b           L_8017B648
    // 0x8017B63C: swc1        $f18, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f18.u32l;
        goto L_8017B648;
    // 0x8017B63C: swc1        $f18, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f18.u32l;
L_8017B640:
    // 0x8017B640: jal         0x800C8544
    // 0x8017B644: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    func_800C8544(rdram, ctx);
        goto after_0;
    // 0x8017B644: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    after_0:
L_8017B648:
    // 0x8017B648: jal         0x8017DD9C
    // 0x8017B64C: nop

    func_8017DD9C_111CC0(rdram, ctx);
        goto after_1;
    // 0x8017B64C: nop

    after_1:
L_8017B650:
    // 0x8017B650: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017B654: addiu       $t7, $t7, 0x3B00
    ctx->r15 = ADD32(ctx->r15, 0X3B00);
    // 0x8017B658: lbu         $t8, 0x21($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X21);
    // 0x8017B65C: andi        $t0, $t8, 0x1
    ctx->r8 = ctx->r24 & 0X1;
    // 0x8017B660: beq         $t0, $zero, L_8017B690
    if (ctx->r8 == 0) {
        // 0x8017B664: nop
    
            goto L_8017B690;
    }
    // 0x8017B664: nop

    // 0x8017B668: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017B66C: addiu       $t2, $t2, -0x41E0
    ctx->r10 = ADD32(ctx->r10, -0X41E0);
    // 0x8017B670: lb          $t3, 0x6($t2)
    ctx->r11 = MEM_B(ctx->r10, 0X6);
    // 0x8017B674: slti        $at, $t3, -0x28
    ctx->r1 = SIGNED(ctx->r11) < -0X28 ? 1 : 0;
    // 0x8017B678: bne         $at, $zero, L_8017B6A8
    if (ctx->r1 != 0) {
        // 0x8017B67C: nop
    
            goto L_8017B6A8;
    }
    // 0x8017B67C: nop

    // 0x8017B680: lb          $t4, 0x7($t2)
    ctx->r12 = MEM_B(ctx->r10, 0X7);
    // 0x8017B684: slti        $at, $t4, -0x28
    ctx->r1 = SIGNED(ctx->r12) < -0X28 ? 1 : 0;
    // 0x8017B688: bne         $at, $zero, L_8017B6A8
    if (ctx->r1 != 0) {
        // 0x8017B68C: nop
    
            goto L_8017B6A8;
    }
    // 0x8017B68C: nop

L_8017B690:
    // 0x8017B690: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017B694: addiu       $t5, $t5, -0x41E0
    ctx->r13 = ADD32(ctx->r13, -0X41E0);
    // 0x8017B698: lhu         $t1, 0x4($t5)
    ctx->r9 = MEM_HU(ctx->r13, 0X4);
    // 0x8017B69C: andi        $t6, $t1, 0x600
    ctx->r14 = ctx->r9 & 0X600;
    // 0x8017B6A0: beq         $t6, $zero, L_8017B714
    if (ctx->r14 == 0) {
        // 0x8017B6A4: nop
    
            goto L_8017B714;
    }
    // 0x8017B6A4: nop

L_8017B6A8:
    // 0x8017B6A8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017B6AC: addiu       $t9, $t9, 0x3B00
    ctx->r25 = ADD32(ctx->r25, 0X3B00);
    // 0x8017B6B0: lbu         $t7, 0x21($t9)
    ctx->r15 = MEM_BU(ctx->r25, 0X21);
    // 0x8017B6B4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017B6B8: addiu       $t0, $t0, 0x3D00
    ctx->r8 = ADD32(ctx->r8, 0X3D00);
    // 0x8017B6BC: andi        $t8, $t7, 0xFE
    ctx->r24 = ctx->r15 & 0XFE;
    // 0x8017B6C0: sb          $t8, 0x21($t9)
    MEM_B(0X21, ctx->r25) = ctx->r24;
    // 0x8017B6C4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017B6C8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017B6CC: lwc1        $f4, 0x4($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X4);
    // 0x8017B6D0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017B6D4: addiu       $t3, $t3, 0x3D00
    ctx->r11 = ADD32(ctx->r11, 0X3D00);
    // 0x8017B6D8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8017B6DC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8017B6E0: swc1        $f8, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f8.u32l;
    // 0x8017B6E4: lwc1        $f10, 0x4($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X4);
    // 0x8017B6E8: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x8017B6EC: nop

    // 0x8017B6F0: bc1f        L_8017B704
    if (!c1cs) {
        // 0x8017B6F4: nop
    
            goto L_8017B704;
    }
    // 0x8017B6F4: nop

    // 0x8017B6F8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8017B6FC: b           L_8017B70C
    // 0x8017B700: swc1        $f18, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->f18.u32l;
        goto L_8017B70C;
    // 0x8017B700: swc1        $f18, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->f18.u32l;
L_8017B704:
    // 0x8017B704: jal         0x800C8544
    // 0x8017B708: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    func_800C8544(rdram, ctx);
        goto after_2;
    // 0x8017B708: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    after_2:
L_8017B70C:
    // 0x8017B70C: jal         0x8017DD9C
    // 0x8017B710: nop

    func_8017DD9C_111CC0(rdram, ctx);
        goto after_3;
    // 0x8017B710: nop

    after_3:
L_8017B714:
    // 0x8017B714: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017B718: addiu       $t2, $t2, -0x41E0
    ctx->r10 = ADD32(ctx->r10, -0X41E0);
    // 0x8017B71C: lhu         $t4, 0x2($t2)
    ctx->r12 = MEM_HU(ctx->r10, 0X2);
    // 0x8017B720: andi        $t5, $t4, 0xF000
    ctx->r13 = ctx->r12 & 0XF000;
    // 0x8017B724: beq         $t5, $zero, L_8017B73C
    if (ctx->r13 == 0) {
        // 0x8017B728: nop
    
            goto L_8017B73C;
    }
    // 0x8017B728: nop

    // 0x8017B72C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017B730: addiu       $t6, $t6, 0x3B40
    ctx->r14 = ADD32(ctx->r14, 0X3B40);
    // 0x8017B734: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x8017B738: sb          $t1, 0x12($t6)
    MEM_B(0X12, ctx->r14) = ctx->r9;
L_8017B73C:
    // 0x8017B73C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017B740: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017B744: jr          $ra
    // 0x8017B748: nop

    return;
    // 0x8017B748: nop

;}
RECOMP_FUNC void func_8017B74C_111CC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017B74C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017B750: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017B754: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017B758: addiu       $t6, $t6, 0x3B40
    ctx->r14 = ADD32(ctx->r14, 0X3B40);
    // 0x8017B75C: lb          $t7, 0x13($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X13);
    // 0x8017B760: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8017B764: bne         $t7, $at, L_8017B96C
    if (ctx->r15 != ctx->r1) {
        // 0x8017B768: nop
    
            goto L_8017B96C;
    }
    // 0x8017B768: nop

    // 0x8017B76C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017B770: addiu       $t8, $t8, -0x41E0
    ctx->r24 = ADD32(ctx->r24, -0X41E0);
    // 0x8017B774: lb          $t9, 0x6($t8)
    ctx->r25 = MEM_B(ctx->r24, 0X6);
    // 0x8017B778: slti        $at, $t9, -0x28
    ctx->r1 = SIGNED(ctx->r25) < -0X28 ? 1 : 0;
    // 0x8017B77C: bne         $at, $zero, L_8017B7B8
    if (ctx->r1 != 0) {
        // 0x8017B780: slti        $at, $t9, 0x29
        ctx->r1 = SIGNED(ctx->r25) < 0X29 ? 1 : 0;
            goto L_8017B7B8;
    }
    // 0x8017B780: slti        $at, $t9, 0x29
    ctx->r1 = SIGNED(ctx->r25) < 0X29 ? 1 : 0;
    // 0x8017B784: beq         $at, $zero, L_8017B7B8
    if (ctx->r1 == 0) {
        // 0x8017B788: nop
    
            goto L_8017B7B8;
    }
    // 0x8017B788: nop

    // 0x8017B78C: lb          $t0, 0x7($t8)
    ctx->r8 = MEM_B(ctx->r24, 0X7);
    // 0x8017B790: slti        $at, $t0, -0x28
    ctx->r1 = SIGNED(ctx->r8) < -0X28 ? 1 : 0;
    // 0x8017B794: bne         $at, $zero, L_8017B7B8
    if (ctx->r1 != 0) {
        // 0x8017B798: slti        $at, $t0, 0x29
        ctx->r1 = SIGNED(ctx->r8) < 0X29 ? 1 : 0;
            goto L_8017B7B8;
    }
    // 0x8017B798: slti        $at, $t0, 0x29
    ctx->r1 = SIGNED(ctx->r8) < 0X29 ? 1 : 0;
    // 0x8017B79C: beq         $at, $zero, L_8017B7B8
    if (ctx->r1 == 0) {
        // 0x8017B7A0: nop
    
            goto L_8017B7B8;
    }
    // 0x8017B7A0: nop

    // 0x8017B7A4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017B7A8: addiu       $t1, $t1, 0x3B00
    ctx->r9 = ADD32(ctx->r9, 0X3B00);
    // 0x8017B7AC: lbu         $t2, 0x21($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X21);
    // 0x8017B7B0: ori         $t3, $t2, 0x1
    ctx->r11 = ctx->r10 | 0X1;
    // 0x8017B7B4: sb          $t3, 0x21($t1)
    MEM_B(0X21, ctx->r9) = ctx->r11;
L_8017B7B8:
    // 0x8017B7B8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017B7BC: addiu       $t4, $t4, 0x3B00
    ctx->r12 = ADD32(ctx->r12, 0X3B00);
    // 0x8017B7C0: lbu         $t5, 0x21($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X21);
    // 0x8017B7C4: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x8017B7C8: beq         $t6, $zero, L_8017B7F8
    if (ctx->r14 == 0) {
        // 0x8017B7CC: nop
    
            goto L_8017B7F8;
    }
    // 0x8017B7CC: nop

    // 0x8017B7D0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017B7D4: addiu       $t7, $t7, -0x41E0
    ctx->r15 = ADD32(ctx->r15, -0X41E0);
    // 0x8017B7D8: lb          $t9, 0x6($t7)
    ctx->r25 = MEM_B(ctx->r15, 0X6);
    // 0x8017B7DC: slti        $at, $t9, 0x29
    ctx->r1 = SIGNED(ctx->r25) < 0X29 ? 1 : 0;
    // 0x8017B7E0: beq         $at, $zero, L_8017B810
    if (ctx->r1 == 0) {
        // 0x8017B7E4: nop
    
            goto L_8017B810;
    }
    // 0x8017B7E4: nop

    // 0x8017B7E8: lb          $t8, 0x7($t7)
    ctx->r24 = MEM_B(ctx->r15, 0X7);
    // 0x8017B7EC: slti        $at, $t8, 0x29
    ctx->r1 = SIGNED(ctx->r24) < 0X29 ? 1 : 0;
    // 0x8017B7F0: beq         $at, $zero, L_8017B810
    if (ctx->r1 == 0) {
        // 0x8017B7F4: nop
    
            goto L_8017B810;
    }
    // 0x8017B7F4: nop

L_8017B7F8:
    // 0x8017B7F8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017B7FC: addiu       $t0, $t0, -0x41E0
    ctx->r8 = ADD32(ctx->r8, -0X41E0);
    // 0x8017B800: lhu         $t2, 0x4($t0)
    ctx->r10 = MEM_HU(ctx->r8, 0X4);
    // 0x8017B804: andi        $t3, $t2, 0x900
    ctx->r11 = ctx->r10 & 0X900;
    // 0x8017B808: beq         $t3, $zero, L_8017B880
    if (ctx->r11 == 0) {
        // 0x8017B80C: nop
    
            goto L_8017B880;
    }
    // 0x8017B80C: nop

L_8017B810:
    // 0x8017B810: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017B814: addiu       $t1, $t1, 0x3B00
    ctx->r9 = ADD32(ctx->r9, 0X3B00);
    // 0x8017B818: lbu         $t4, 0x21($t1)
    ctx->r12 = MEM_BU(ctx->r9, 0X21);
    // 0x8017B81C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017B820: addiu       $t6, $t6, 0x3D00
    ctx->r14 = ADD32(ctx->r14, 0X3D00);
    // 0x8017B824: andi        $t5, $t4, 0xFE
    ctx->r13 = ctx->r12 & 0XFE;
    // 0x8017B828: sb          $t5, 0x21($t1)
    MEM_B(0X21, ctx->r9) = ctx->r13;
    // 0x8017B82C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017B830: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017B834: lwc1        $f4, 0x8($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X8);
    // 0x8017B838: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017B83C: addiu       $t9, $t9, 0x3D00
    ctx->r25 = ADD32(ctx->r25, 0X3D00);
    // 0x8017B840: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8017B844: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8017B848: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8017B84C: swc1        $f8, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f8.u32l;
    // 0x8017B850: lwc1        $f10, 0x8($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X8);
    // 0x8017B854: c.lt.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl < ctx->f10.fl;
    // 0x8017B858: nop

    // 0x8017B85C: bc1f        L_8017B870
    if (!c1cs) {
        // 0x8017B860: lui         $at, 0x4100
        ctx->r1 = S32(0X4100 << 16);
            goto L_8017B870;
    }
    // 0x8017B860: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8017B864: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8017B868: b           L_8017B878
    // 0x8017B86C: swc1        $f18, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f18.u32l;
        goto L_8017B878;
    // 0x8017B86C: swc1        $f18, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f18.u32l;
L_8017B870:
    // 0x8017B870: jal         0x800C8544
    // 0x8017B874: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    func_800C8544(rdram, ctx);
        goto after_0;
    // 0x8017B874: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    after_0:
L_8017B878:
    // 0x8017B878: jal         0x8017DD9C
    // 0x8017B87C: nop

    func_8017DD9C_111CC0(rdram, ctx);
        goto after_1;
    // 0x8017B87C: nop

    after_1:
L_8017B880:
    // 0x8017B880: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017B884: addiu       $t7, $t7, 0x3B00
    ctx->r15 = ADD32(ctx->r15, 0X3B00);
    // 0x8017B888: lbu         $t8, 0x21($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X21);
    // 0x8017B88C: andi        $t0, $t8, 0x1
    ctx->r8 = ctx->r24 & 0X1;
    // 0x8017B890: beq         $t0, $zero, L_8017B8C0
    if (ctx->r8 == 0) {
        // 0x8017B894: nop
    
            goto L_8017B8C0;
    }
    // 0x8017B894: nop

    // 0x8017B898: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017B89C: addiu       $t2, $t2, -0x41E0
    ctx->r10 = ADD32(ctx->r10, -0X41E0);
    // 0x8017B8A0: lb          $t3, 0x6($t2)
    ctx->r11 = MEM_B(ctx->r10, 0X6);
    // 0x8017B8A4: slti        $at, $t3, -0x28
    ctx->r1 = SIGNED(ctx->r11) < -0X28 ? 1 : 0;
    // 0x8017B8A8: bne         $at, $zero, L_8017B8D8
    if (ctx->r1 != 0) {
        // 0x8017B8AC: nop
    
            goto L_8017B8D8;
    }
    // 0x8017B8AC: nop

    // 0x8017B8B0: lb          $t4, 0x7($t2)
    ctx->r12 = MEM_B(ctx->r10, 0X7);
    // 0x8017B8B4: slti        $at, $t4, -0x28
    ctx->r1 = SIGNED(ctx->r12) < -0X28 ? 1 : 0;
    // 0x8017B8B8: bne         $at, $zero, L_8017B8D8
    if (ctx->r1 != 0) {
        // 0x8017B8BC: nop
    
            goto L_8017B8D8;
    }
    // 0x8017B8BC: nop

L_8017B8C0:
    // 0x8017B8C0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017B8C4: addiu       $t5, $t5, -0x41E0
    ctx->r13 = ADD32(ctx->r13, -0X41E0);
    // 0x8017B8C8: lhu         $t1, 0x4($t5)
    ctx->r9 = MEM_HU(ctx->r13, 0X4);
    // 0x8017B8CC: andi        $t6, $t1, 0x600
    ctx->r14 = ctx->r9 & 0X600;
    // 0x8017B8D0: beq         $t6, $zero, L_8017B944
    if (ctx->r14 == 0) {
        // 0x8017B8D4: nop
    
            goto L_8017B944;
    }
    // 0x8017B8D4: nop

L_8017B8D8:
    // 0x8017B8D8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017B8DC: addiu       $t9, $t9, 0x3B00
    ctx->r25 = ADD32(ctx->r25, 0X3B00);
    // 0x8017B8E0: lbu         $t7, 0x21($t9)
    ctx->r15 = MEM_BU(ctx->r25, 0X21);
    // 0x8017B8E4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017B8E8: addiu       $t0, $t0, 0x3D00
    ctx->r8 = ADD32(ctx->r8, 0X3D00);
    // 0x8017B8EC: andi        $t8, $t7, 0xFE
    ctx->r24 = ctx->r15 & 0XFE;
    // 0x8017B8F0: sb          $t8, 0x21($t9)
    MEM_B(0X21, ctx->r25) = ctx->r24;
    // 0x8017B8F4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017B8F8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017B8FC: lwc1        $f4, 0x8($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X8);
    // 0x8017B900: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017B904: addiu       $t3, $t3, 0x3D00
    ctx->r11 = ADD32(ctx->r11, 0X3D00);
    // 0x8017B908: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8017B90C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8017B910: swc1        $f8, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f8.u32l;
    // 0x8017B914: lwc1        $f10, 0x8($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X8);
    // 0x8017B918: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x8017B91C: nop

    // 0x8017B920: bc1f        L_8017B934
    if (!c1cs) {
        // 0x8017B924: nop
    
            goto L_8017B934;
    }
    // 0x8017B924: nop

    // 0x8017B928: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8017B92C: b           L_8017B93C
    // 0x8017B930: swc1        $f18, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f18.u32l;
        goto L_8017B93C;
    // 0x8017B930: swc1        $f18, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f18.u32l;
L_8017B934:
    // 0x8017B934: jal         0x800C8544
    // 0x8017B938: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    func_800C8544(rdram, ctx);
        goto after_2;
    // 0x8017B938: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    after_2:
L_8017B93C:
    // 0x8017B93C: jal         0x8017DD9C
    // 0x8017B940: nop

    func_8017DD9C_111CC0(rdram, ctx);
        goto after_3;
    // 0x8017B940: nop

    after_3:
L_8017B944:
    // 0x8017B944: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017B948: addiu       $t2, $t2, -0x41E0
    ctx->r10 = ADD32(ctx->r10, -0X41E0);
    // 0x8017B94C: lhu         $t4, 0x2($t2)
    ctx->r12 = MEM_HU(ctx->r10, 0X2);
    // 0x8017B950: andi        $t5, $t4, 0xF000
    ctx->r13 = ctx->r12 & 0XF000;
    // 0x8017B954: beq         $t5, $zero, L_8017B96C
    if (ctx->r13 == 0) {
        // 0x8017B958: nop
    
            goto L_8017B96C;
    }
    // 0x8017B958: nop

    // 0x8017B95C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017B960: addiu       $t6, $t6, 0x3B40
    ctx->r14 = ADD32(ctx->r14, 0X3B40);
    // 0x8017B964: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x8017B968: sb          $t1, 0x13($t6)
    MEM_B(0X13, ctx->r14) = ctx->r9;
L_8017B96C:
    // 0x8017B96C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017B970: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017B974: jr          $ra
    // 0x8017B978: nop

    return;
    // 0x8017B978: nop

;}
RECOMP_FUNC void func_8017B97C_111CC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017B97C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017B980: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017B984: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017B988: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017B98C: addiu       $t7, $t7, 0x3B40
    ctx->r15 = ADD32(ctx->r15, 0X3B40);
    // 0x8017B990: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x8017B994: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017B998: sb          $t6, 0x1($t7)
    MEM_B(0X1, ctx->r15) = ctx->r14;
    // 0x8017B99C: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x8017B9A0: jal         0x800C32CC
    // 0x8017B9A4: swc1        $f4, 0x80($t8)
    MEM_W(0X80, ctx->r24) = ctx->f4.u32l;
    func_800C32CC(rdram, ctx);
        goto after_0;
    // 0x8017B9A4: swc1        $f4, 0x80($t8)
    MEM_W(0X80, ctx->r24) = ctx->f4.u32l;
    after_0:
    // 0x8017B9A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017B9AC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8017B9B0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017B9B4: sh          $t9, -0x2E4C($at)
    MEM_H(-0X2E4C, ctx->r1) = ctx->r25;
    // 0x8017B9B8: jr          $ra
    // 0x8017B9BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8017B9BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8017B9C0_111CC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017B9C0: lui         $at, 0x4090
    ctx->r1 = S32(0X4090 << 16);
    // 0x8017B9C4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017B9C8: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8017B9CC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8017B9D0: mul.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x8017B9D4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8017B9D8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017B9DC: mul.s       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f8.fl);
    // 0x8017B9E0: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x8017B9E4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017B9E8: mul.s       $f18, $f12, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x8017B9EC: swc1        $f6, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f6.u32l;
    // 0x8017B9F0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017B9F4: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x8017B9F8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017B9FC: swc1        $f10, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->f10.u32l;
    // 0x8017BA00: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x8017BA04: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017BA08: swc1        $f18, 0x14($t8)
    MEM_W(0X14, ctx->r24) = ctx->f18.u32l;
    // 0x8017BA0C: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x8017BA10: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017BA14: addiu       $t1, $t1, 0x3B00
    ctx->r9 = ADD32(ctx->r9, 0X3B00);
    // 0x8017BA18: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x8017BA1C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017BA20: swc1        $f4, 0x18($t9)
    MEM_W(0X18, ctx->r25) = ctx->f4.u32l;
    // 0x8017BA24: sb          $t0, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r8;
    // 0x8017BA28: addiu       $t3, $t3, 0x3B00
    ctx->r11 = ADD32(ctx->r11, 0X3B00);
    // 0x8017BA2C: addiu       $t2, $zero, 0xBE
    ctx->r10 = ADD32(0, 0XBE);
    // 0x8017BA30: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017BA34: sb          $t2, 0x1($t3)
    MEM_B(0X1, ctx->r11) = ctx->r10;
    // 0x8017BA38: addiu       $t4, $t4, 0x3B00
    ctx->r12 = ADD32(ctx->r12, 0X3B00);
    // 0x8017BA3C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017BA40: sb          $zero, 0x2($t4)
    MEM_B(0X2, ctx->r12) = 0;
    // 0x8017BA44: addiu       $t6, $t6, 0x3B00
    ctx->r14 = ADD32(ctx->r14, 0X3B00);
    // 0x8017BA48: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x8017BA4C: jr          $ra
    // 0x8017BA50: sb          $t5, 0x3($t6)
    MEM_B(0X3, ctx->r14) = ctx->r13;
    return;
    // 0x8017BA50: sb          $t5, 0x3($t6)
    MEM_B(0X3, ctx->r14) = ctx->r13;
;}
RECOMP_FUNC void func_8017BA54_111CC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017BA54: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x8017BA58: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017BA5C: lui         $at, 0xC396
    ctx->r1 = S32(0XC396 << 16);
    // 0x8017BA60: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8017BA64: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8017BA68: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017BA6C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017BA70: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017BA74: lui         $at, 0x4060
    ctx->r1 = S32(0X4060 << 16);
    // 0x8017BA78: mul.s       $f16, $f12, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x8017BA7C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8017BA80: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x8017BA84: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017BA88: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x8017BA8C: swc1        $f4, 0x20($t6)
    MEM_W(0X20, ctx->r14) = ctx->f4.u32l;
    // 0x8017BA90: swc1        $f6, 0x24($t7)
    MEM_W(0X24, ctx->r15) = ctx->f6.u32l;
    // 0x8017BA94: mul.s       $f4, $f12, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f18.fl);
    // 0x8017BA98: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8017BA9C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017BAA0: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x8017BAA4: swc1        $f8, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->f8.u32l;
    // 0x8017BAA8: mul.s       $f8, $f12, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f6.fl);
    // 0x8017BAAC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017BAB0: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x8017BAB4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017BAB8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8017BABC: swc1        $f16, 0x2C($t9)
    MEM_W(0X2C, ctx->r25) = ctx->f16.u32l;
    // 0x8017BAC0: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x8017BAC4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017BAC8: swc1        $f4, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->f4.u32l;
    // 0x8017BACC: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x8017BAD0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017BAD4: swc1        $f8, 0x34($t1)
    MEM_W(0X34, ctx->r9) = ctx->f8.u32l;
    // 0x8017BAD8: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x8017BADC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017BAE0: swc1        $f10, 0x38($t2)
    MEM_W(0X38, ctx->r10) = ctx->f10.u32l;
    // 0x8017BAE4: lwc1        $f16, -0x1E58($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X1E58);
    // 0x8017BAE8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017BAEC: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x8017BAF0: mul.s       $f18, $f12, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x8017BAF4: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017BAF8: addiu       $t5, $t5, 0x3B00
    ctx->r13 = ADD32(ctx->r13, 0X3B00);
    // 0x8017BAFC: addiu       $t4, $zero, 0xE6
    ctx->r12 = ADD32(0, 0XE6);
    // 0x8017BB00: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017BB04: addiu       $t7, $t7, 0x3B00
    ctx->r15 = ADD32(ctx->r15, 0X3B00);
    // 0x8017BB08: addiu       $t6, $zero, 0xE6
    ctx->r14 = ADD32(0, 0XE6);
    // 0x8017BB0C: swc1        $f18, 0x3C($t3)
    MEM_W(0X3C, ctx->r11) = ctx->f18.u32l;
    // 0x8017BB10: sb          $t4, 0x8($t5)
    MEM_B(0X8, ctx->r13) = ctx->r12;
    // 0x8017BB14: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017BB18: sb          $t6, 0x9($t7)
    MEM_B(0X9, ctx->r15) = ctx->r14;
    // 0x8017BB1C: addiu       $t9, $t9, 0x3B00
    ctx->r25 = ADD32(ctx->r25, 0X3B00);
    // 0x8017BB20: addiu       $t8, $zero, 0xE6
    ctx->r24 = ADD32(0, 0XE6);
    // 0x8017BB24: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017BB28: sb          $t8, 0xA($t9)
    MEM_B(0XA, ctx->r25) = ctx->r24;
    // 0x8017BB2C: addiu       $t0, $t0, 0x3B00
    ctx->r8 = ADD32(ctx->r8, 0X3B00);
    // 0x8017BB30: jr          $ra
    // 0x8017BB34: sb          $a1, 0xB($t0)
    MEM_B(0XB, ctx->r8) = ctx->r5;
    return;
    // 0x8017BB34: sb          $a1, 0xB($t0)
    MEM_B(0XB, ctx->r8) = ctx->r5;
;}
RECOMP_FUNC void func_8017BB38_111CC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017BB38: lui         $at, 0xC396
    ctx->r1 = S32(0XC396 << 16);
    // 0x8017BB3C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8017BB40: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8017BB44: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017BB48: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017BB4C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8017BB50: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017BB54: lui         $at, 0x4060
    ctx->r1 = S32(0X4060 << 16);
    // 0x8017BB58: mul.s       $f16, $f12, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x8017BB5C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8017BB60: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x8017BB64: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017BB68: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x8017BB6C: swc1        $f4, 0x40($t6)
    MEM_W(0X40, ctx->r14) = ctx->f4.u32l;
    // 0x8017BB70: swc1        $f6, 0x44($t7)
    MEM_W(0X44, ctx->r15) = ctx->f6.u32l;
    // 0x8017BB74: mul.s       $f4, $f12, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f18.fl);
    // 0x8017BB78: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8017BB7C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017BB80: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x8017BB84: swc1        $f8, 0x48($t8)
    MEM_W(0X48, ctx->r24) = ctx->f8.u32l;
    // 0x8017BB88: mul.s       $f8, $f12, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f6.fl);
    // 0x8017BB8C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017BB90: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x8017BB94: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017BB98: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8017BB9C: swc1        $f16, 0x4C($t9)
    MEM_W(0X4C, ctx->r25) = ctx->f16.u32l;
    // 0x8017BBA0: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x8017BBA4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017BBA8: swc1        $f4, 0x50($t0)
    MEM_W(0X50, ctx->r8) = ctx->f4.u32l;
    // 0x8017BBAC: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x8017BBB0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017BBB4: swc1        $f8, 0x54($t1)
    MEM_W(0X54, ctx->r9) = ctx->f8.u32l;
    // 0x8017BBB8: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x8017BBBC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017BBC0: swc1        $f10, 0x58($t2)
    MEM_W(0X58, ctx->r10) = ctx->f10.u32l;
    // 0x8017BBC4: lwc1        $f16, -0x1E54($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X1E54);
    // 0x8017BBC8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017BBCC: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x8017BBD0: mul.s       $f18, $f12, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x8017BBD4: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017BBD8: addiu       $t5, $t5, 0x3B00
    ctx->r13 = ADD32(ctx->r13, 0X3B00);
    // 0x8017BBDC: addiu       $t4, $zero, 0xE6
    ctx->r12 = ADD32(0, 0XE6);
    // 0x8017BBE0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017BBE4: addiu       $t7, $t7, 0x3B00
    ctx->r15 = ADD32(ctx->r15, 0X3B00);
    // 0x8017BBE8: addiu       $t6, $zero, 0xE6
    ctx->r14 = ADD32(0, 0XE6);
    // 0x8017BBEC: swc1        $f18, 0x5C($t3)
    MEM_W(0X5C, ctx->r11) = ctx->f18.u32l;
    // 0x8017BBF0: sb          $t4, 0x10($t5)
    MEM_B(0X10, ctx->r13) = ctx->r12;
    // 0x8017BBF4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017BBF8: sb          $t6, 0x11($t7)
    MEM_B(0X11, ctx->r15) = ctx->r14;
    // 0x8017BBFC: addiu       $t9, $t9, 0x3B00
    ctx->r25 = ADD32(ctx->r25, 0X3B00);
    // 0x8017BC00: addiu       $t8, $zero, 0xE6
    ctx->r24 = ADD32(0, 0XE6);
    // 0x8017BC04: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017BC08: sb          $t8, 0x12($t9)
    MEM_B(0X12, ctx->r25) = ctx->r24;
    // 0x8017BC0C: addiu       $t0, $t0, 0x3B00
    ctx->r8 = ADD32(ctx->r8, 0X3B00);
    // 0x8017BC10: jr          $ra
    // 0x8017BC14: sb          $a1, 0x13($t0)
    MEM_B(0X13, ctx->r8) = ctx->r5;
    return;
    // 0x8017BC14: sb          $a1, 0x13($t0)
    MEM_B(0X13, ctx->r8) = ctx->r5;
;}
RECOMP_FUNC void func_8017BC18_111CC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017BC18: lui         $at, 0xC28C
    ctx->r1 = S32(0XC28C << 16);
    // 0x8017BC1C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017BC20: lui         $at, 0xC396
    ctx->r1 = S32(0XC396 << 16);
    // 0x8017BC24: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8017BC28: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8017BC2C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017BC30: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017BC34: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017BC38: lui         $at, 0x4060
    ctx->r1 = S32(0X4060 << 16);
    // 0x8017BC3C: mul.s       $f16, $f12, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x8017BC40: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8017BC44: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x8017BC48: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017BC4C: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x8017BC50: swc1        $f4, 0x60($t6)
    MEM_W(0X60, ctx->r14) = ctx->f4.u32l;
    // 0x8017BC54: swc1        $f6, 0x64($t7)
    MEM_W(0X64, ctx->r15) = ctx->f6.u32l;
    // 0x8017BC58: mul.s       $f4, $f12, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f18.fl);
    // 0x8017BC5C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8017BC60: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017BC64: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x8017BC68: swc1        $f8, 0x68($t8)
    MEM_W(0X68, ctx->r24) = ctx->f8.u32l;
    // 0x8017BC6C: mul.s       $f8, $f12, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f6.fl);
    // 0x8017BC70: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017BC74: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x8017BC78: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017BC7C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8017BC80: swc1        $f16, 0x6C($t9)
    MEM_W(0X6C, ctx->r25) = ctx->f16.u32l;
    // 0x8017BC84: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x8017BC88: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017BC8C: swc1        $f4, 0x70($t0)
    MEM_W(0X70, ctx->r8) = ctx->f4.u32l;
    // 0x8017BC90: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x8017BC94: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017BC98: swc1        $f8, 0x74($t1)
    MEM_W(0X74, ctx->r9) = ctx->f8.u32l;
    // 0x8017BC9C: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x8017BCA0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017BCA4: swc1        $f10, 0x78($t2)
    MEM_W(0X78, ctx->r10) = ctx->f10.u32l;
    // 0x8017BCA8: lwc1        $f16, -0x1E50($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X1E50);
    // 0x8017BCAC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017BCB0: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x8017BCB4: mul.s       $f18, $f12, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x8017BCB8: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017BCBC: addiu       $t5, $t5, 0x3B00
    ctx->r13 = ADD32(ctx->r13, 0X3B00);
    // 0x8017BCC0: addiu       $t4, $zero, 0xE6
    ctx->r12 = ADD32(0, 0XE6);
    // 0x8017BCC4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017BCC8: addiu       $t7, $t7, 0x3B00
    ctx->r15 = ADD32(ctx->r15, 0X3B00);
    // 0x8017BCCC: addiu       $t6, $zero, 0xE6
    ctx->r14 = ADD32(0, 0XE6);
    // 0x8017BCD0: swc1        $f18, 0x7C($t3)
    MEM_W(0X7C, ctx->r11) = ctx->f18.u32l;
    // 0x8017BCD4: sb          $t4, 0x18($t5)
    MEM_B(0X18, ctx->r13) = ctx->r12;
    // 0x8017BCD8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017BCDC: sb          $t6, 0x19($t7)
    MEM_B(0X19, ctx->r15) = ctx->r14;
    // 0x8017BCE0: addiu       $t9, $t9, 0x3B00
    ctx->r25 = ADD32(ctx->r25, 0X3B00);
    // 0x8017BCE4: addiu       $t8, $zero, 0xE6
    ctx->r24 = ADD32(0, 0XE6);
    // 0x8017BCE8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017BCEC: sb          $t8, 0x1A($t9)
    MEM_B(0X1A, ctx->r25) = ctx->r24;
    // 0x8017BCF0: addiu       $t0, $t0, 0x3B00
    ctx->r8 = ADD32(ctx->r8, 0X3B00);
    // 0x8017BCF4: jr          $ra
    // 0x8017BCF8: sb          $a1, 0x1B($t0)
    MEM_B(0X1B, ctx->r8) = ctx->r5;
    return;
    // 0x8017BCF8: sb          $a1, 0x1B($t0)
    MEM_B(0X1B, ctx->r8) = ctx->r5;
;}
RECOMP_FUNC void func_8017BCFC_111CC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017BCFC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017BD00: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x8017BD04: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017BD08: swc1        $f12, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f12.u32l;
    // 0x8017BD0C: addiu       $t7, $t7, 0x3B00
    ctx->r15 = ADD32(ctx->r15, 0X3B00);
    // 0x8017BD10: jr          $ra
    // 0x8017BD14: sb          $a1, 0x1C($t7)
    MEM_B(0X1C, ctx->r15) = ctx->r5;
    return;
    // 0x8017BD14: sb          $a1, 0x1C($t7)
    MEM_B(0X1C, ctx->r15) = ctx->r5;
;}
RECOMP_FUNC void func_8017BD18_111CC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017BD18: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8017BD1C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8017BD20: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_8017BD24:
    // 0x8017BD24: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8017BD28: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8017BD2C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017BD30: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017BD34: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8017BD38: sb          $zero, 0x3B00($at)
    MEM_B(0X3B00, ctx->r1) = 0;
    // 0x8017BD3C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8017BD40: lbu         $t8, 0x3B00($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X3B00);
    // 0x8017BD44: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8017BD48: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017BD4C: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8017BD50: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017BD54: sb          $t8, 0x3B40($at)
    MEM_B(0X3B40, ctx->r1) = ctx->r24;
    // 0x8017BD58: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8017BD5C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017BD60: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8017BD64: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x8017BD68: swc1        $f4, 0x3E00($at)
    MEM_W(0X3E00, ctx->r1) = ctx->f4.u32l;
    // 0x8017BD6C: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8017BD70: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017BD74: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x8017BD78: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x8017BD7C: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x8017BD80: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8017BD84: sh          $zero, 0x3B80($at)
    MEM_H(0X3B80, ctx->r1) = 0;
    // 0x8017BD88: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017BD8C: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8017BD90: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x8017BD94: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8017BD98: swc1        $f6, 0x3D00($at)
    MEM_W(0X3D00, ctx->r1) = ctx->f6.u32l;
    // 0x8017BD9C: slti        $at, $t6, 0x40
    ctx->r1 = SIGNED(ctx->r14) < 0X40 ? 1 : 0;
    // 0x8017BDA0: bne         $at, $zero, L_8017BD24
    if (ctx->r1 != 0) {
        // 0x8017BDA4: sw          $t6, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r14;
            goto L_8017BD24;
    }
    // 0x8017BDA4: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x8017BDA8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8017BDAC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8017BDB0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017BDB4: lui         $at, 0x442F
    ctx->r1 = S32(0X442F << 16);
    // 0x8017BDB8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8017BDBC: addiu       $t8, $t8, -0x4198
    ctx->r24 = ADD32(ctx->r24, -0X4198);
    // 0x8017BDC0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017BDC4: addiu       $t7, $t7, -0x4198
    ctx->r15 = ADD32(ctx->r15, -0X4198);
    // 0x8017BDC8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017BDCC: swc1        $f8, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f8.u32l;
    // 0x8017BDD0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8017BDD4: addiu       $t9, $t9, -0x4198
    ctx->r25 = ADD32(ctx->r25, -0X4198);
    // 0x8017BDD8: swc1        $f10, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f10.u32l;
    // 0x8017BDDC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017BDE0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017BDE4: swc1        $f16, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f16.u32l;
    // 0x8017BDE8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8017BDEC: addiu       $t0, $t0, -0x4198
    ctx->r8 = ADD32(ctx->r8, -0X4198);
    // 0x8017BDF0: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017BDF4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8017BDF8: addiu       $t1, $t1, -0x4198
    ctx->r9 = ADD32(ctx->r9, -0X4198);
    // 0x8017BDFC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017BE00: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017BE04: swc1        $f18, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->f18.u32l;
    // 0x8017BE08: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017BE0C: addiu       $t2, $t2, -0x4198
    ctx->r10 = ADD32(ctx->r10, -0X4198);
    // 0x8017BE10: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017BE14: swc1        $f4, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->f4.u32l;
    // 0x8017BE18: addiu       $t3, $t3, -0x4198
    ctx->r11 = ADD32(ctx->r11, -0X4198);
    // 0x8017BE1C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017BE20: swc1        $f6, 0x14($t2)
    MEM_W(0X14, ctx->r10) = ctx->f6.u32l;
    // 0x8017BE24: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8017BE28: addiu       $t4, $t4, -0x4198
    ctx->r12 = ADD32(ctx->r12, -0X4198);
    // 0x8017BE2C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017BE30: swc1        $f8, 0x18($t3)
    MEM_W(0X18, ctx->r11) = ctx->f8.u32l;
    // 0x8017BE34: addiu       $t5, $t5, -0x4198
    ctx->r13 = ADD32(ctx->r13, -0X4198);
    // 0x8017BE38: swc1        $f10, 0x1C($t4)
    MEM_W(0X1C, ctx->r12) = ctx->f10.u32l;
    // 0x8017BE3C: addiu       $a0, $zero, 0x50
    ctx->r4 = ADD32(0, 0X50);
    // 0x8017BE40: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    // 0x8017BE44: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    // 0x8017BE48: jal         0x800C6E0C
    // 0x8017BE4C: swc1        $f16, 0x20($t5)
    MEM_W(0X20, ctx->r13) = ctx->f16.u32l;
    func_800C6E0C(rdram, ctx);
        goto after_0;
    // 0x8017BE4C: swc1        $f16, 0x20($t5)
    MEM_W(0X20, ctx->r13) = ctx->f16.u32l;
    after_0:
    // 0x8017BE50: addiu       $t6, $zero, 0x45
    ctx->r14 = ADD32(0, 0X45);
    // 0x8017BE54: addiu       $t8, $zero, 0x45
    ctx->r24 = ADD32(0, 0X45);
    // 0x8017BE58: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8017BE5C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8017BE60: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    // 0x8017BE64: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    // 0x8017BE68: addiu       $a2, $zero, 0xC8
    ctx->r6 = ADD32(0, 0XC8);
    // 0x8017BE6C: jal         0x800C6E68
    // 0x8017BE70: addiu       $a3, $zero, -0x45
    ctx->r7 = ADD32(0, -0X45);
    func_800C6E68(rdram, ctx);
        goto after_1;
    // 0x8017BE70: addiu       $a3, $zero, -0x45
    ctx->r7 = ADD32(0, -0X45);
    after_1:
    // 0x8017BE74: jal         0x800C6DBC
    // 0x8017BE78: nop

    func_800C6DBC(rdram, ctx);
        goto after_2;
    // 0x8017BE78: nop

    after_2:
    // 0x8017BE7C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017BE80: addiu       $t9, $t9, 0x3B40
    ctx->r25 = ADD32(ctx->r25, 0X3B40);
    // 0x8017BE84: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8017BE88: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017BE8C: sb          $t7, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r15;
    // 0x8017BE90: addiu       $t0, $t0, 0x3B40
    ctx->r8 = ADD32(ctx->r8, 0X3B40);
    // 0x8017BE94: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017BE98: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017BE9C: sb          $zero, 0x1($t0)
    MEM_B(0X1, ctx->r8) = 0;
    // 0x8017BEA0: addiu       $t1, $t1, 0x3B40
    ctx->r9 = ADD32(ctx->r9, 0X3B40);
    // 0x8017BEA4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8017BEA8: jal         0x8017B9C0
    // 0x8017BEAC: sb          $zero, 0x2($t1)
    MEM_B(0X2, ctx->r9) = 0;
    func_8017B9C0_111CC0(rdram, ctx);
        goto after_3;
    // 0x8017BEAC: sb          $zero, 0x2($t1)
    MEM_B(0X2, ctx->r9) = 0;
    after_3:
    // 0x8017BEB0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017BEB4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8017BEB8: jal         0x8017BA54
    // 0x8017BEBC: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    func_8017BA54_111CC0(rdram, ctx);
        goto after_4;
    // 0x8017BEBC: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    after_4:
    // 0x8017BEC0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017BEC4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8017BEC8: jal         0x8017BB38
    // 0x8017BECC: addiu       $a1, $zero, 0x91
    ctx->r5 = ADD32(0, 0X91);
    func_8017BB38_111CC0(rdram, ctx);
        goto after_5;
    // 0x8017BECC: addiu       $a1, $zero, 0x91
    ctx->r5 = ADD32(0, 0X91);
    after_5:
    // 0x8017BED0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017BED4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8017BED8: jal         0x8017BC18
    // 0x8017BEDC: addiu       $a1, $zero, 0x91
    ctx->r5 = ADD32(0, 0X91);
    func_8017BC18_111CC0(rdram, ctx);
        goto after_6;
    // 0x8017BEDC: addiu       $a1, $zero, 0x91
    ctx->r5 = ADD32(0, 0X91);
    after_6:
    // 0x8017BEE0: jal         0x800CB8BC
    // 0x8017BEE4: nop

    func_800CB8BC(rdram, ctx);
        goto after_7;
    // 0x8017BEE4: nop

    after_7:
    // 0x8017BEE8: mtc1        $v0, $f18
    ctx->f18.u32l = ctx->r2;
    // 0x8017BEEC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017BEF0: addiu       $t2, $t2, 0x3D00
    ctx->r10 = ADD32(ctx->r10, 0X3D00);
    // 0x8017BEF4: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8017BEF8: jal         0x800CB7FC
    // 0x8017BEFC: swc1        $f4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f4.u32l;
    func_800CB7FC(rdram, ctx);
        goto after_8;
    // 0x8017BEFC: swc1        $f4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f4.u32l;
    after_8:
    // 0x8017BF00: addiu       $t3, $v0, 0x1
    ctx->r11 = ADD32(ctx->r2, 0X1);
    // 0x8017BF04: bgez        $t3, L_8017BF14
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8017BF08: sra         $t4, $t3, 12
        ctx->r12 = S32(SIGNED(ctx->r11) >> 12);
            goto L_8017BF14;
    }
    // 0x8017BF08: sra         $t4, $t3, 12
    ctx->r12 = S32(SIGNED(ctx->r11) >> 12);
    // 0x8017BF0C: addiu       $at, $t3, 0xFFF
    ctx->r1 = ADD32(ctx->r11, 0XFFF);
    // 0x8017BF10: sra         $t4, $at, 12
    ctx->r12 = S32(SIGNED(ctx->r1) >> 12);
L_8017BF14:
    // 0x8017BF14: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x8017BF18: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017BF1C: addiu       $t5, $t5, 0x3D00
    ctx->r13 = ADD32(ctx->r13, 0X3D00);
    // 0x8017BF20: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8017BF24: jal         0x800CB894
    // 0x8017BF28: swc1        $f8, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->f8.u32l;
    func_800CB894(rdram, ctx);
        goto after_9;
    // 0x8017BF28: swc1        $f8, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->f8.u32l;
    after_9:
    // 0x8017BF2C: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x8017BF30: bgez        $t6, L_8017BF40
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8017BF34: sra         $t8, $t6, 12
        ctx->r24 = S32(SIGNED(ctx->r14) >> 12);
            goto L_8017BF40;
    }
    // 0x8017BF34: sra         $t8, $t6, 12
    ctx->r24 = S32(SIGNED(ctx->r14) >> 12);
    // 0x8017BF38: addiu       $at, $t6, 0xFFF
    ctx->r1 = ADD32(ctx->r14, 0XFFF);
    // 0x8017BF3C: sra         $t8, $at, 12
    ctx->r24 = S32(SIGNED(ctx->r1) >> 12);
L_8017BF40:
    // 0x8017BF40: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x8017BF44: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x8017BF48: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8017BF4C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8017BF50: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017BF54: addiu       $t7, $t7, 0x3D00
    ctx->r15 = ADD32(ctx->r15, 0X3D00);
    // 0x8017BF58: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017BF5C: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x8017BF60: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017BF64: swc1        $f16, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->f16.u32l;
    // 0x8017BF68: addiu       $t0, $t0, 0x3B40
    ctx->r8 = ADD32(ctx->r8, 0X3B40);
    // 0x8017BF6C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017BF70: swc1        $f18, 0x80($t9)
    MEM_W(0X80, ctx->r25) = ctx->f18.u32l;
    // 0x8017BF74: sb          $zero, 0x10($t0)
    MEM_B(0X10, ctx->r8) = 0;
    // 0x8017BF78: addiu       $t1, $t1, 0x3B40
    ctx->r9 = ADD32(ctx->r9, 0X3B40);
    // 0x8017BF7C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017BF80: sb          $zero, 0x11($t1)
    MEM_B(0X11, ctx->r9) = 0;
    // 0x8017BF84: addiu       $t2, $t2, 0x3B40
    ctx->r10 = ADD32(ctx->r10, 0X3B40);
    // 0x8017BF88: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017BF8C: sb          $zero, 0x12($t2)
    MEM_B(0X12, ctx->r10) = 0;
    // 0x8017BF90: addiu       $t3, $t3, 0x3B40
    ctx->r11 = ADD32(ctx->r11, 0X3B40);
    // 0x8017BF94: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017BF98: sb          $zero, 0x13($t3)
    MEM_B(0X13, ctx->r11) = 0;
    // 0x8017BF9C: addiu       $t4, $t4, 0x3B00
    ctx->r12 = ADD32(ctx->r12, 0X3B00);
    // 0x8017BFA0: sb          $zero, 0x21($t4)
    MEM_B(0X21, ctx->r12) = 0;
    // 0x8017BFA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8017BFA8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8017BFAC: jr          $ra
    // 0x8017BFB0: nop

    return;
    // 0x8017BFB0: nop

;}
RECOMP_FUNC void func_8017BFB4_111CC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017BFB4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8017BFB8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017BFBC: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8017BFC0: addiu       $t6, $t6, 0x3B00
    ctx->r14 = ADD32(ctx->r14, 0X3B00);
    // 0x8017BFC4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017BFC8: lwc1        $f4, -0x1E4C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1E4C);
    // 0x8017BFCC: lbu         $t7, 0x3($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X3);
    // 0x8017BFD0: lui         $at, 0x432A
    ctx->r1 = S32(0X432A << 16);
    // 0x8017BFD4: lbu         $a1, 0x0($t6)
    ctx->r5 = MEM_BU(ctx->r14, 0X0);
    // 0x8017BFD8: lbu         $a2, 0x1($t6)
    ctx->r6 = MEM_BU(ctx->r14, 0X1);
    // 0x8017BFDC: lbu         $a3, 0x2($t6)
    ctx->r7 = MEM_BU(ctx->r14, 0X2);
    // 0x8017BFE0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8017BFE4: lui         $at, 0xC396
    ctx->r1 = S32(0XC396 << 16);
    // 0x8017BFE8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017BFEC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8017BFF0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017BFF4: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x8017BFF8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8017BFFC: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x8017C000: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8017C004: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x8017C008: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    // 0x8017C00C: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x8017C010: lwc1        $f16, 0xC($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0XC);
    // 0x8017C014: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8017C018: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8017C01C: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    // 0x8017C020: lwc1        $f18, 0x10($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X10);
    // 0x8017C024: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8017C028: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8017C02C: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    // 0x8017C030: lwc1        $f4, 0x14($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X14);
    // 0x8017C034: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8017C038: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    // 0x8017C03C: addiu       $a0, $a0, -0x1ED0
    ctx->r4 = ADD32(ctx->r4, -0X1ED0);
    // 0x8017C040: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    // 0x8017C044: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    // 0x8017C048: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    // 0x8017C04C: jal         0x80171C88
    // 0x8017C050: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    func_80171C88_02FC30(rdram, ctx);
        goto after_0;
    // 0x8017C050: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8017C054: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017C058: addiu       $t0, $t0, 0x3B00
    ctx->r8 = ADD32(ctx->r8, 0X3B00);
    // 0x8017C05C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017C060: lwc1        $f16, -0x1E48($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X1E48);
    // 0x8017C064: lbu         $t1, 0xB($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0XB);
    // 0x8017C068: lbu         $a1, 0x8($t0)
    ctx->r5 = MEM_BU(ctx->r8, 0X8);
    // 0x8017C06C: lbu         $a2, 0x9($t0)
    ctx->r6 = MEM_BU(ctx->r8, 0X9);
    // 0x8017C070: lbu         $a3, 0xA($t0)
    ctx->r7 = MEM_BU(ctx->r8, 0XA);
    // 0x8017C074: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017C078: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x8017C07C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8017C080: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x8017C084: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8017C088: lwc1        $f18, 0x20($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X20);
    // 0x8017C08C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8017C090: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x8017C094: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    // 0x8017C098: lwc1        $f4, 0x24($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X24);
    // 0x8017C09C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8017C0A0: addiu       $a0, $a0, -0x1EC0
    ctx->r4 = ADD32(ctx->r4, -0X1EC0);
    // 0x8017C0A4: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x8017C0A8: lwc1        $f6, 0x28($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X28);
    // 0x8017C0AC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017C0B0: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    // 0x8017C0B4: lwc1        $f8, 0x2C($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X2C);
    // 0x8017C0B8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8017C0BC: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x8017C0C0: lwc1        $f10, 0x30($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X30);
    // 0x8017C0C4: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    // 0x8017C0C8: lwc1        $f16, 0x34($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X34);
    // 0x8017C0CC: sw          $t3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r11;
    // 0x8017C0D0: swc1        $f18, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f18.u32l;
    // 0x8017C0D4: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x8017C0D8: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    // 0x8017C0DC: jal         0x80171C88
    // 0x8017C0E0: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    func_80171C88_02FC30(rdram, ctx);
        goto after_1;
    // 0x8017C0E0: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    after_1:
    // 0x8017C0E4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017C0E8: addiu       $t4, $t4, 0x3B00
    ctx->r12 = ADD32(ctx->r12, 0X3B00);
    // 0x8017C0EC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017C0F0: lwc1        $f8, -0x1E44($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1E44);
    // 0x8017C0F4: lbu         $t5, 0x13($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X13);
    // 0x8017C0F8: lbu         $a1, 0x10($t4)
    ctx->r5 = MEM_BU(ctx->r12, 0X10);
    // 0x8017C0FC: lbu         $a2, 0x11($t4)
    ctx->r6 = MEM_BU(ctx->r12, 0X11);
    // 0x8017C100: lbu         $a3, 0x12($t4)
    ctx->r7 = MEM_BU(ctx->r12, 0X12);
    // 0x8017C104: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017C108: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x8017C10C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8017C110: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8017C114: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8017C118: lwc1        $f10, 0x40($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X40);
    // 0x8017C11C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8017C120: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8017C124: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x8017C128: lwc1        $f16, 0x44($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X44);
    // 0x8017C12C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8017C130: addiu       $a0, $a0, -0x1EB8
    ctx->r4 = ADD32(ctx->r4, -0X1EB8);
    // 0x8017C134: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x8017C138: lwc1        $f18, 0x48($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X48);
    // 0x8017C13C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8017C140: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    // 0x8017C144: lwc1        $f4, 0x4C($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X4C);
    // 0x8017C148: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8017C14C: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x8017C150: lwc1        $f6, 0x50($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X50);
    // 0x8017C154: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x8017C158: lwc1        $f8, 0x54($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X54);
    // 0x8017C15C: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
    // 0x8017C160: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    // 0x8017C164: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    // 0x8017C168: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    // 0x8017C16C: jal         0x80171C88
    // 0x8017C170: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    func_80171C88_02FC30(rdram, ctx);
        goto after_2;
    // 0x8017C170: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x8017C174: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017C178: addiu       $t8, $t8, 0x3B00
    ctx->r24 = ADD32(ctx->r24, 0X3B00);
    // 0x8017C17C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017C180: lwc1        $f4, -0x1E40($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1E40);
    // 0x8017C184: lbu         $t9, 0x1B($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X1B);
    // 0x8017C188: lbu         $a1, 0x18($t8)
    ctx->r5 = MEM_BU(ctx->r24, 0X18);
    // 0x8017C18C: lbu         $a2, 0x19($t8)
    ctx->r6 = MEM_BU(ctx->r24, 0X19);
    // 0x8017C190: lbu         $a3, 0x1A($t8)
    ctx->r7 = MEM_BU(ctx->r24, 0X1A);
    // 0x8017C194: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017C198: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x8017C19C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8017C1A0: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x8017C1A4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8017C1A8: lwc1        $f6, 0x60($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X60);
    // 0x8017C1AC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8017C1B0: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x8017C1B4: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x8017C1B8: lwc1        $f8, 0x64($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X64);
    // 0x8017C1BC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8017C1C0: addiu       $a0, $a0, -0x1EAC
    ctx->r4 = ADD32(ctx->r4, -0X1EAC);
    // 0x8017C1C4: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x8017C1C8: lwc1        $f10, 0x68($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X68);
    // 0x8017C1CC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8017C1D0: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    // 0x8017C1D4: lwc1        $f16, 0x6C($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X6C);
    // 0x8017C1D8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8017C1DC: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    // 0x8017C1E0: lwc1        $f18, 0x70($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X70);
    // 0x8017C1E4: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    // 0x8017C1E8: lwc1        $f4, 0x74($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X74);
    // 0x8017C1EC: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    // 0x8017C1F0: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    // 0x8017C1F4: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    // 0x8017C1F8: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    // 0x8017C1FC: jal         0x80171C88
    // 0x8017C200: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    func_80171C88_02FC30(rdram, ctx);
        goto after_3;
    // 0x8017C200: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x8017C204: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017C208: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017C20C: lwc1        $f16, -0x1E3C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X1E3C);
    // 0x8017C210: addiu       $t2, $t2, 0x3B00
    ctx->r10 = ADD32(ctx->r10, 0X3B00);
    // 0x8017C214: lbu         $t3, 0x1C($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X1C);
    // 0x8017C218: lui         $at, 0xC32A
    ctx->r1 = S32(0XC32A << 16);
    // 0x8017C21C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017C220: lui         $at, 0xC396
    ctx->r1 = S32(0XC396 << 16);
    // 0x8017C224: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017C228: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8017C22C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017C230: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x8017C234: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8017C238: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8017C23C: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x8017C240: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8017C244: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x8017C248: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    // 0x8017C24C: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    // 0x8017C250: lwc1        $f8, 0x0($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X0);
    // 0x8017C254: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017C258: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8017C25C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8017C260: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8017C264: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8017C268: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8017C26C: mul.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x8017C270: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x8017C274: sw          $t5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r13;
    // 0x8017C278: addiu       $a0, $a0, -0x1EA0
    ctx->r4 = ADD32(ctx->r4, -0X1EA0);
    // 0x8017C27C: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    // 0x8017C280: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    // 0x8017C284: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8017C288: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x8017C28C: addiu       $a1, $zero, 0xE6
    ctx->r5 = ADD32(0, 0XE6);
    // 0x8017C290: addiu       $a2, $zero, 0xE6
    ctx->r6 = ADD32(0, 0XE6);
    // 0x8017C294: addiu       $a3, $zero, 0xE6
    ctx->r7 = ADD32(0, 0XE6);
    // 0x8017C298: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    // 0x8017C29C: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    // 0x8017C2A0: jal         0x80171C88
    // 0x8017C2A4: swc1        $f16, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f16.u32l;
    func_80171C88_02FC30(rdram, ctx);
        goto after_4;
    // 0x8017C2A4: swc1        $f16, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f16.u32l;
    after_4:
    // 0x8017C2A8: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8017C2AC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8017C2B0: jr          $ra
    // 0x8017C2B4: nop

    return;
    // 0x8017C2B4: nop

;}
RECOMP_FUNC void func_8017C2B8_111CC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017C2B8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8017C2BC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017C2C0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8017C2C4: addiu       $t6, $t6, 0x3B00
    ctx->r14 = ADD32(ctx->r14, 0X3B00);
    // 0x8017C2C8: lbu         $t7, 0x3($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X3);
    // 0x8017C2CC: lbu         $a1, 0x0($t6)
    ctx->r5 = MEM_BU(ctx->r14, 0X0);
    // 0x8017C2D0: lbu         $a2, 0x1($t6)
    ctx->r6 = MEM_BU(ctx->r14, 0X1);
    // 0x8017C2D4: lbu         $a3, 0x2($t6)
    ctx->r7 = MEM_BU(ctx->r14, 0X2);
    // 0x8017C2D8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017C2DC: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x8017C2E0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8017C2E4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8017C2E8: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    // 0x8017C2EC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8017C2F0: addiu       $a0, $a0, -0x1E98
    ctx->r4 = ADD32(ctx->r4, -0X1E98);
    // 0x8017C2F4: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x8017C2F8: lwc1        $f6, 0x4($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X4);
    // 0x8017C2FC: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x8017C300: lwc1        $f8, 0x8($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X8);
    // 0x8017C304: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x8017C308: lwc1        $f10, 0xC($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0XC);
    // 0x8017C30C: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    // 0x8017C310: lwc1        $f16, 0x10($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X10);
    // 0x8017C314: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    // 0x8017C318: lwc1        $f18, 0x14($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X14);
    // 0x8017C31C: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    // 0x8017C320: lwc1        $f4, 0x18($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X18);
    // 0x8017C324: jal         0x80171F90
    // 0x8017C328: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    func_80171F90_02FC30(rdram, ctx);
        goto after_0;
    // 0x8017C328: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8017C32C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017C330: addiu       $t9, $t9, 0x3B00
    ctx->r25 = ADD32(ctx->r25, 0X3B00);
    // 0x8017C334: lbu         $t0, 0xB($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0XB);
    // 0x8017C338: lbu         $a1, 0x8($t9)
    ctx->r5 = MEM_BU(ctx->r25, 0X8);
    // 0x8017C33C: lbu         $a2, 0x9($t9)
    ctx->r6 = MEM_BU(ctx->r25, 0X9);
    // 0x8017C340: lbu         $a3, 0xA($t9)
    ctx->r7 = MEM_BU(ctx->r25, 0XA);
    // 0x8017C344: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017C348: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x8017C34C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8017C350: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8017C354: lwc1        $f6, 0x20($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X20);
    // 0x8017C358: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8017C35C: addiu       $a0, $a0, -0x1E88
    ctx->r4 = ADD32(ctx->r4, -0X1E88);
    // 0x8017C360: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x8017C364: lwc1        $f8, 0x24($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X24);
    // 0x8017C368: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x8017C36C: lwc1        $f10, 0x28($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X28);
    // 0x8017C370: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    // 0x8017C374: lwc1        $f16, 0x2C($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X2C);
    // 0x8017C378: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x8017C37C: lwc1        $f18, 0x30($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X30);
    // 0x8017C380: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    // 0x8017C384: lwc1        $f4, 0x34($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X34);
    // 0x8017C388: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x8017C38C: lwc1        $f6, 0x38($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X38);
    // 0x8017C390: jal         0x80171F90
    // 0x8017C394: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    func_80171F90_02FC30(rdram, ctx);
        goto after_1;
    // 0x8017C394: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x8017C398: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017C39C: addiu       $t2, $t2, 0x3B00
    ctx->r10 = ADD32(ctx->r10, 0X3B00);
    // 0x8017C3A0: lbu         $t3, 0x13($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X13);
    // 0x8017C3A4: lbu         $a1, 0x10($t2)
    ctx->r5 = MEM_BU(ctx->r10, 0X10);
    // 0x8017C3A8: lbu         $a2, 0x11($t2)
    ctx->r6 = MEM_BU(ctx->r10, 0X11);
    // 0x8017C3AC: lbu         $a3, 0x12($t2)
    ctx->r7 = MEM_BU(ctx->r10, 0X12);
    // 0x8017C3B0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017C3B4: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x8017C3B8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8017C3BC: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8017C3C0: lwc1        $f8, 0x40($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X40);
    // 0x8017C3C4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8017C3C8: addiu       $a0, $a0, -0x1E80
    ctx->r4 = ADD32(ctx->r4, -0X1E80);
    // 0x8017C3CC: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8017C3D0: lwc1        $f10, 0x44($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X44);
    // 0x8017C3D4: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x8017C3D8: lwc1        $f16, 0x48($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X48);
    // 0x8017C3DC: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x8017C3E0: lwc1        $f18, 0x4C($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X4C);
    // 0x8017C3E4: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    // 0x8017C3E8: lwc1        $f4, 0x50($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X50);
    // 0x8017C3EC: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x8017C3F0: lwc1        $f6, 0x54($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X54);
    // 0x8017C3F4: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x8017C3F8: lwc1        $f8, 0x58($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X58);
    // 0x8017C3FC: jal         0x80171F90
    // 0x8017C400: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    func_80171F90_02FC30(rdram, ctx);
        goto after_2;
    // 0x8017C400: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x8017C404: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017C408: addiu       $t5, $t5, 0x3B00
    ctx->r13 = ADD32(ctx->r13, 0X3B00);
    // 0x8017C40C: lbu         $t6, 0x1B($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X1B);
    // 0x8017C410: lbu         $a1, 0x18($t5)
    ctx->r5 = MEM_BU(ctx->r13, 0X18);
    // 0x8017C414: lbu         $a2, 0x19($t5)
    ctx->r6 = MEM_BU(ctx->r13, 0X19);
    // 0x8017C418: lbu         $a3, 0x1A($t5)
    ctx->r7 = MEM_BU(ctx->r13, 0X1A);
    // 0x8017C41C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017C420: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x8017C424: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8017C428: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8017C42C: lwc1        $f10, 0x60($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X60);
    // 0x8017C430: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8017C434: addiu       $a0, $a0, -0x1E74
    ctx->r4 = ADD32(ctx->r4, -0X1E74);
    // 0x8017C438: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x8017C43C: lwc1        $f16, 0x64($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X64);
    // 0x8017C440: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    // 0x8017C444: lwc1        $f18, 0x68($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0X68);
    // 0x8017C448: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    // 0x8017C44C: lwc1        $f4, 0x6C($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X6C);
    // 0x8017C450: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x8017C454: lwc1        $f6, 0x70($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X70);
    // 0x8017C458: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x8017C45C: lwc1        $f8, 0x74($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X74);
    // 0x8017C460: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x8017C464: lwc1        $f10, 0x78($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X78);
    // 0x8017C468: jal         0x80171F90
    // 0x8017C46C: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    func_80171F90_02FC30(rdram, ctx);
        goto after_3;
    // 0x8017C46C: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    after_3:
    // 0x8017C470: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8017C474: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8017C478: jr          $ra
    // 0x8017C47C: nop

    return;
    // 0x8017C47C: nop

;}
RECOMP_FUNC void func_8017C480_111CC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017C480: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8017C484: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017C488: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8017C48C: addiu       $t6, $t6, 0x3B00
    ctx->r14 = ADD32(ctx->r14, 0X3B00);
    // 0x8017C490: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017C494: lwc1        $f4, -0x1E38($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1E38);
    // 0x8017C498: lbu         $t7, 0x33($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X33);
    // 0x8017C49C: lbu         $a1, 0x30($t6)
    ctx->r5 = MEM_BU(ctx->r14, 0X30);
    // 0x8017C4A0: lbu         $a2, 0x31($t6)
    ctx->r6 = MEM_BU(ctx->r14, 0X31);
    // 0x8017C4A4: lbu         $a3, 0x32($t6)
    ctx->r7 = MEM_BU(ctx->r14, 0X32);
    // 0x8017C4A8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017C4AC: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x8017C4B0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8017C4B4: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x8017C4B8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8017C4BC: lwc1        $f6, 0xC0($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0XC0);
    // 0x8017C4C0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8017C4C4: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8017C4C8: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x8017C4CC: lwc1        $f8, 0xC4($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0XC4);
    // 0x8017C4D0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8017C4D4: addiu       $a0, $a0, -0x1E68
    ctx->r4 = ADD32(ctx->r4, -0X1E68);
    // 0x8017C4D8: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x8017C4DC: lwc1        $f10, 0xC8($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0XC8);
    // 0x8017C4E0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8017C4E4: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    // 0x8017C4E8: lwc1        $f16, 0xCC($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0XCC);
    // 0x8017C4EC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8017C4F0: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    // 0x8017C4F4: lwc1        $f18, 0xD0($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0XD0);
    // 0x8017C4F8: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    // 0x8017C4FC: lwc1        $f4, 0xD4($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0XD4);
    // 0x8017C500: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    // 0x8017C504: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    // 0x8017C508: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    // 0x8017C50C: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    // 0x8017C510: jal         0x80171C88
    // 0x8017C514: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    func_80171C88_02FC30(rdram, ctx);
        goto after_0;
    // 0x8017C514: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8017C518: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017C51C: addiu       $t0, $t0, 0x3B00
    ctx->r8 = ADD32(ctx->r8, 0X3B00);
    // 0x8017C520: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017C524: lwc1        $f16, -0x1E34($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X1E34);
    // 0x8017C528: lbu         $t1, 0x3B($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X3B);
    // 0x8017C52C: lbu         $a1, 0x38($t0)
    ctx->r5 = MEM_BU(ctx->r8, 0X38);
    // 0x8017C530: lbu         $a2, 0x39($t0)
    ctx->r6 = MEM_BU(ctx->r8, 0X39);
    // 0x8017C534: lbu         $a3, 0x3A($t0)
    ctx->r7 = MEM_BU(ctx->r8, 0X3A);
    // 0x8017C538: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017C53C: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x8017C540: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8017C544: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x8017C548: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8017C54C: lwc1        $f18, 0xE0($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0XE0);
    // 0x8017C550: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8017C554: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x8017C558: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    // 0x8017C55C: lwc1        $f4, 0xE4($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0XE4);
    // 0x8017C560: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8017C564: addiu       $a0, $a0, -0x1E60
    ctx->r4 = ADD32(ctx->r4, -0X1E60);
    // 0x8017C568: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x8017C56C: lwc1        $f6, 0xE8($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0XE8);
    // 0x8017C570: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017C574: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    // 0x8017C578: lwc1        $f8, 0xEC($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0XEC);
    // 0x8017C57C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8017C580: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x8017C584: lwc1        $f10, 0xF0($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0XF0);
    // 0x8017C588: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    // 0x8017C58C: lwc1        $f16, 0xF4($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0XF4);
    // 0x8017C590: sw          $t3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r11;
    // 0x8017C594: swc1        $f18, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f18.u32l;
    // 0x8017C598: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x8017C59C: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    // 0x8017C5A0: jal         0x80171C88
    // 0x8017C5A4: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    func_80171C88_02FC30(rdram, ctx);
        goto after_1;
    // 0x8017C5A4: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    after_1:
    // 0x8017C5A8: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8017C5AC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8017C5B0: jr          $ra
    // 0x8017C5B4: nop

    return;
    // 0x8017C5B4: nop

;}
RECOMP_FUNC void func_8017C5B8_111CC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017C5B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017C5BC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017C5C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017C5C4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8017C5C8: jal         0x8017BA54
    // 0x8017C5CC: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    func_8017BA54_111CC0(rdram, ctx);
        goto after_0;
    // 0x8017C5CC: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    after_0:
    // 0x8017C5D0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017C5D4: lwc1        $f12, -0x1E30($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X1E30);
    // 0x8017C5D8: jal         0x8017BB38
    // 0x8017C5DC: addiu       $a1, $zero, 0x91
    ctx->r5 = ADD32(0, 0X91);
    func_8017BB38_111CC0(rdram, ctx);
        goto after_1;
    // 0x8017C5DC: addiu       $a1, $zero, 0x91
    ctx->r5 = ADD32(0, 0X91);
    after_1:
    // 0x8017C5E0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017C5E4: lwc1        $f12, -0x1E2C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X1E2C);
    // 0x8017C5E8: jal         0x8017BC18
    // 0x8017C5EC: addiu       $a1, $zero, 0x91
    ctx->r5 = ADD32(0, 0X91);
    func_8017BC18_111CC0(rdram, ctx);
        goto after_2;
    // 0x8017C5EC: addiu       $a1, $zero, 0x91
    ctx->r5 = ADD32(0, 0X91);
    after_2:
    // 0x8017C5F0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017C5F4: lwc1        $f12, -0x1E28($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X1E28);
    // 0x8017C5F8: jal         0x8017BCFC
    // 0x8017C5FC: addiu       $a1, $zero, 0x91
    ctx->r5 = ADD32(0, 0X91);
    func_8017BCFC_111CC0(rdram, ctx);
        goto after_3;
    // 0x8017C5FC: addiu       $a1, $zero, 0x91
    ctx->r5 = ADD32(0, 0X91);
    after_3:
    // 0x8017C600: jal         0x8017BFB4
    // 0x8017C604: nop

    func_8017BFB4_111CC0(rdram, ctx);
        goto after_4;
    // 0x8017C604: nop

    after_4:
    // 0x8017C608: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017C60C: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x8017C610: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8017C614: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017C618: lwc1        $f4, 0x80($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X80);
    // 0x8017C61C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017C620: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x8017C624: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8017C628: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8017C62C: swc1        $f8, 0x80($t6)
    MEM_W(0X80, ctx->r14) = ctx->f8.u32l;
    // 0x8017C630: lwc1        $f10, 0x80($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X80);
    // 0x8017C634: c.le.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl <= ctx->f10.fl;
    // 0x8017C638: nop

    // 0x8017C63C: bc1f        L_8017C654
    if (!c1cs) {
        // 0x8017C640: nop
    
            goto L_8017C654;
    }
    // 0x8017C640: nop

    // 0x8017C644: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017C648: addiu       $t9, $t9, 0x3B40
    ctx->r25 = ADD32(ctx->r25, 0X3B40);
    // 0x8017C64C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8017C650: sb          $t8, 0x1($t9)
    MEM_B(0X1, ctx->r25) = ctx->r24;
L_8017C654:
    // 0x8017C654: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017C658: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017C65C: jr          $ra
    // 0x8017C660: nop

    return;
    // 0x8017C660: nop

;}
RECOMP_FUNC void func_8017C664_111CC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017C664: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8017C668: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017C66C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8017C670: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8017C674: addiu       $t6, $t6, 0x3B40
    ctx->r14 = ADD32(ctx->r14, 0X3B40);
    // 0x8017C678: lb          $s0, 0x10($t6)
    ctx->r16 = MEM_B(ctx->r14, 0X10);
    // 0x8017C67C: beq         $s0, $zero, L_8017C6A4
    if (ctx->r16 == 0) {
        // 0x8017C680: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8017C6A4;
    }
    // 0x8017C680: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8017C684: beq         $s0, $at, L_8017C6EC
    if (ctx->r16 == ctx->r1) {
        // 0x8017C688: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8017C6EC;
    }
    // 0x8017C688: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8017C68C: beq         $s0, $at, L_8017C734
    if (ctx->r16 == ctx->r1) {
        // 0x8017C690: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8017C734;
    }
    // 0x8017C690: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8017C694: beq         $s0, $at, L_8017C77C
    if (ctx->r16 == ctx->r1) {
        // 0x8017C698: nop
    
            goto L_8017C77C;
    }
    // 0x8017C698: nop

    // 0x8017C69C: b           L_8017C7BC
    // 0x8017C6A0: nop

        goto L_8017C7BC;
    // 0x8017C6A0: nop

L_8017C6A4:
    // 0x8017C6A4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017C6A8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8017C6AC: jal         0x8017BA54
    // 0x8017C6B0: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    func_8017BA54_111CC0(rdram, ctx);
        goto after_0;
    // 0x8017C6B0: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    after_0:
    // 0x8017C6B4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017C6B8: lwc1        $f12, -0x1E24($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X1E24);
    // 0x8017C6BC: jal         0x8017BB38
    // 0x8017C6C0: addiu       $a1, $zero, 0x91
    ctx->r5 = ADD32(0, 0X91);
    func_8017BB38_111CC0(rdram, ctx);
        goto after_1;
    // 0x8017C6C0: addiu       $a1, $zero, 0x91
    ctx->r5 = ADD32(0, 0X91);
    after_1:
    // 0x8017C6C4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017C6C8: lwc1        $f12, -0x1E20($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X1E20);
    // 0x8017C6CC: jal         0x8017BC18
    // 0x8017C6D0: addiu       $a1, $zero, 0x91
    ctx->r5 = ADD32(0, 0X91);
    func_8017BC18_111CC0(rdram, ctx);
        goto after_2;
    // 0x8017C6D0: addiu       $a1, $zero, 0x91
    ctx->r5 = ADD32(0, 0X91);
    after_2:
    // 0x8017C6D4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017C6D8: lwc1        $f12, -0x1E1C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X1E1C);
    // 0x8017C6DC: jal         0x8017BCFC
    // 0x8017C6E0: addiu       $a1, $zero, 0x91
    ctx->r5 = ADD32(0, 0X91);
    func_8017BCFC_111CC0(rdram, ctx);
        goto after_3;
    // 0x8017C6E0: addiu       $a1, $zero, 0x91
    ctx->r5 = ADD32(0, 0X91);
    after_3:
    // 0x8017C6E4: b           L_8017C7BC
    // 0x8017C6E8: nop

        goto L_8017C7BC;
    // 0x8017C6E8: nop

L_8017C6EC:
    // 0x8017C6EC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017C6F0: lwc1        $f12, -0x1E18($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X1E18);
    // 0x8017C6F4: jal         0x8017BA54
    // 0x8017C6F8: addiu       $a1, $zero, 0x91
    ctx->r5 = ADD32(0, 0X91);
    func_8017BA54_111CC0(rdram, ctx);
        goto after_4;
    // 0x8017C6F8: addiu       $a1, $zero, 0x91
    ctx->r5 = ADD32(0, 0X91);
    after_4:
    // 0x8017C6FC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017C700: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8017C704: jal         0x8017BB38
    // 0x8017C708: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    func_8017BB38_111CC0(rdram, ctx);
        goto after_5;
    // 0x8017C708: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    after_5:
    // 0x8017C70C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017C710: lwc1        $f12, -0x1E14($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X1E14);
    // 0x8017C714: jal         0x8017BC18
    // 0x8017C718: addiu       $a1, $zero, 0x91
    ctx->r5 = ADD32(0, 0X91);
    func_8017BC18_111CC0(rdram, ctx);
        goto after_6;
    // 0x8017C718: addiu       $a1, $zero, 0x91
    ctx->r5 = ADD32(0, 0X91);
    after_6:
    // 0x8017C71C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017C720: lwc1        $f12, -0x1E10($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X1E10);
    // 0x8017C724: jal         0x8017BCFC
    // 0x8017C728: addiu       $a1, $zero, 0x91
    ctx->r5 = ADD32(0, 0X91);
    func_8017BCFC_111CC0(rdram, ctx);
        goto after_7;
    // 0x8017C728: addiu       $a1, $zero, 0x91
    ctx->r5 = ADD32(0, 0X91);
    after_7:
    // 0x8017C72C: b           L_8017C7BC
    // 0x8017C730: nop

        goto L_8017C7BC;
    // 0x8017C730: nop

L_8017C734:
    // 0x8017C734: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017C738: lwc1        $f12, -0x1E0C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X1E0C);
    // 0x8017C73C: jal         0x8017BA54
    // 0x8017C740: addiu       $a1, $zero, 0x91
    ctx->r5 = ADD32(0, 0X91);
    func_8017BA54_111CC0(rdram, ctx);
        goto after_8;
    // 0x8017C740: addiu       $a1, $zero, 0x91
    ctx->r5 = ADD32(0, 0X91);
    after_8:
    // 0x8017C744: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017C748: lwc1        $f12, -0x1E08($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X1E08);
    // 0x8017C74C: jal         0x8017BB38
    // 0x8017C750: addiu       $a1, $zero, 0x91
    ctx->r5 = ADD32(0, 0X91);
    func_8017BB38_111CC0(rdram, ctx);
        goto after_9;
    // 0x8017C750: addiu       $a1, $zero, 0x91
    ctx->r5 = ADD32(0, 0X91);
    after_9:
    // 0x8017C754: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017C758: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8017C75C: jal         0x8017BC18
    // 0x8017C760: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    func_8017BC18_111CC0(rdram, ctx);
        goto after_10;
    // 0x8017C760: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    after_10:
    // 0x8017C764: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017C768: lwc1        $f12, -0x1E04($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X1E04);
    // 0x8017C76C: jal         0x8017BCFC
    // 0x8017C770: addiu       $a1, $zero, 0x91
    ctx->r5 = ADD32(0, 0X91);
    func_8017BCFC_111CC0(rdram, ctx);
        goto after_11;
    // 0x8017C770: addiu       $a1, $zero, 0x91
    ctx->r5 = ADD32(0, 0X91);
    after_11:
    // 0x8017C774: b           L_8017C7BC
    // 0x8017C778: nop

        goto L_8017C7BC;
    // 0x8017C778: nop

L_8017C77C:
    // 0x8017C77C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017C780: lwc1        $f12, -0x1E00($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X1E00);
    // 0x8017C784: jal         0x8017BA54
    // 0x8017C788: addiu       $a1, $zero, 0x91
    ctx->r5 = ADD32(0, 0X91);
    func_8017BA54_111CC0(rdram, ctx);
        goto after_12;
    // 0x8017C788: addiu       $a1, $zero, 0x91
    ctx->r5 = ADD32(0, 0X91);
    after_12:
    // 0x8017C78C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017C790: lwc1        $f12, -0x1DFC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X1DFC);
    // 0x8017C794: jal         0x8017BB38
    // 0x8017C798: addiu       $a1, $zero, 0x91
    ctx->r5 = ADD32(0, 0X91);
    func_8017BB38_111CC0(rdram, ctx);
        goto after_13;
    // 0x8017C798: addiu       $a1, $zero, 0x91
    ctx->r5 = ADD32(0, 0X91);
    after_13:
    // 0x8017C79C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017C7A0: lwc1        $f12, -0x1DF8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X1DF8);
    // 0x8017C7A4: jal         0x8017BC18
    // 0x8017C7A8: addiu       $a1, $zero, 0x91
    ctx->r5 = ADD32(0, 0X91);
    func_8017BC18_111CC0(rdram, ctx);
        goto after_14;
    // 0x8017C7A8: addiu       $a1, $zero, 0x91
    ctx->r5 = ADD32(0, 0X91);
    after_14:
    // 0x8017C7AC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017C7B0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8017C7B4: jal         0x8017BCFC
    // 0x8017C7B8: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    func_8017BCFC_111CC0(rdram, ctx);
        goto after_15;
    // 0x8017C7B8: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    after_15:
L_8017C7BC:
    // 0x8017C7BC: jal         0x8017BFB4
    // 0x8017C7C0: nop

    func_8017BFB4_111CC0(rdram, ctx);
        goto after_16;
    // 0x8017C7C0: nop

    after_16:
    // 0x8017C7C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8017C7C8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8017C7CC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8017C7D0: jr          $ra
    // 0x8017C7D4: nop

    return;
    // 0x8017C7D4: nop

;}
RECOMP_FUNC void func_8017C7D8_111CC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017C7D8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8017C7DC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017C7E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017C7E4: addiu       $t6, $t6, 0x3B40
    ctx->r14 = ADD32(ctx->r14, 0X3B40);
    // 0x8017C7E8: lbu         $t7, 0x11($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X11);
    // 0x8017C7EC: sltiu       $at, $t7, 0x5
    ctx->r1 = ctx->r15 < 0X5 ? 1 : 0;
    // 0x8017C7F0: beq         $at, $zero, L_8017D0A4
    if (ctx->r1 == 0) {
        // 0x8017C7F4: nop
    
            goto L_8017D0A4;
    }
    // 0x8017C7F4: nop

    // 0x8017C7F8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017C7FC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017C800: addu        $at, $at, $t7
    gpr jr_addend_8017C808 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8017C804: lw          $t7, -0x1DF4($at)
    ctx->r15 = ADD32(ctx->r1, -0X1DF4);
    // 0x8017C808: jr          $t7
    // 0x8017C80C: nop

    switch (jr_addend_8017C808 >> 2) {
        case 0: goto L_8017C810; break;
        case 1: goto L_8017CBFC; break;
        case 2: goto L_8017CCC4; break;
        case 3: goto L_8017CEE8; break;
        case 4: goto L_8017CF98; break;
        default: switch_error(__func__, 0x8017C808, 0x8017E20C);
    }
    // 0x8017C80C: nop

L_8017C810:
    // 0x8017C810: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017C814: addiu       $t8, $t8, 0x3B00
    ctx->r24 = ADD32(ctx->r24, 0X3B00);
    // 0x8017C818: lbu         $t9, 0x13($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X13);
    // 0x8017C81C: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x8017C820: lbu         $t0, 0x1B($t8)
    ctx->r8 = MEM_BU(ctx->r24, 0X1B);
    // 0x8017C824: addiu       $t2, $t9, -0x1E
    ctx->r10 = ADD32(ctx->r25, -0X1E);
    // 0x8017C828: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8017C82C: lbu         $t1, 0x1C($t8)
    ctx->r9 = MEM_BU(ctx->r24, 0X1C);
    // 0x8017C830: addiu       $t3, $t0, -0x1E
    ctx->r11 = ADD32(ctx->r8, -0X1E);
    // 0x8017C834: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x8017C838: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x8017C83C: addiu       $t4, $t1, -0x1E
    ctx->r12 = ADD32(ctx->r9, -0X1E);
    // 0x8017C840: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x8017C844: bgtz        $t2, L_8017C854
    if (SIGNED(ctx->r10) > 0) {
        // 0x8017C848: sw          $t4, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r12;
            goto L_8017C854;
    }
    // 0x8017C848: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x8017C84C: b           L_8017C864
    // 0x8017C850: sb          $zero, 0x13($t8)
    MEM_B(0X13, ctx->r24) = 0;
        goto L_8017C864;
    // 0x8017C850: sb          $zero, 0x13($t8)
    MEM_B(0X13, ctx->r24) = 0;
L_8017C854:
    // 0x8017C854: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x8017C858: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017C85C: addiu       $t6, $t6, 0x3B00
    ctx->r14 = ADD32(ctx->r14, 0X3B00);
    // 0x8017C860: sb          $t5, 0x13($t6)
    MEM_B(0X13, ctx->r14) = ctx->r13;
L_8017C864:
    // 0x8017C864: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8017C868: bgtz        $t7, L_8017C880
    if (SIGNED(ctx->r15) > 0) {
        // 0x8017C86C: nop
    
            goto L_8017C880;
    }
    // 0x8017C86C: nop

    // 0x8017C870: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017C874: addiu       $t9, $t9, 0x3B00
    ctx->r25 = ADD32(ctx->r25, 0X3B00);
    // 0x8017C878: b           L_8017C890
    // 0x8017C87C: sb          $zero, 0x1B($t9)
    MEM_B(0X1B, ctx->r25) = 0;
        goto L_8017C890;
    // 0x8017C87C: sb          $zero, 0x1B($t9)
    MEM_B(0X1B, ctx->r25) = 0;
L_8017C880:
    // 0x8017C880: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8017C884: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017C888: addiu       $t3, $t3, 0x3B00
    ctx->r11 = ADD32(ctx->r11, 0X3B00);
    // 0x8017C88C: sb          $t0, 0x1B($t3)
    MEM_B(0X1B, ctx->r11) = ctx->r8;
L_8017C890:
    // 0x8017C890: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8017C894: bgtz        $t1, L_8017C8AC
    if (SIGNED(ctx->r9) > 0) {
        // 0x8017C898: nop
    
            goto L_8017C8AC;
    }
    // 0x8017C898: nop

    // 0x8017C89C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017C8A0: addiu       $t4, $t4, 0x3B00
    ctx->r12 = ADD32(ctx->r12, 0X3B00);
    // 0x8017C8A4: b           L_8017C8BC
    // 0x8017C8A8: sb          $zero, 0x1C($t4)
    MEM_B(0X1C, ctx->r12) = 0;
        goto L_8017C8BC;
    // 0x8017C8A8: sb          $zero, 0x1C($t4)
    MEM_B(0X1C, ctx->r12) = 0;
L_8017C8AC:
    // 0x8017C8AC: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8017C8B0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017C8B4: addiu       $t8, $t8, 0x3B00
    ctx->r24 = ADD32(ctx->r24, 0X3B00);
    // 0x8017C8B8: sb          $t2, 0x1C($t8)
    MEM_B(0X1C, ctx->r24) = ctx->r10;
L_8017C8BC:
    // 0x8017C8BC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017C8C0: addiu       $t5, $t5, 0x3B00
    ctx->r13 = ADD32(ctx->r13, 0X3B00);
    // 0x8017C8C4: lbu         $t6, 0x13($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X13);
    // 0x8017C8C8: bne         $t6, $zero, L_8017D0A4
    if (ctx->r14 != 0) {
        // 0x8017C8CC: nop
    
            goto L_8017D0A4;
    }
    // 0x8017C8CC: nop

    // 0x8017C8D0: lbu         $t7, 0x1B($t5)
    ctx->r15 = MEM_BU(ctx->r13, 0X1B);
    // 0x8017C8D4: bne         $t7, $zero, L_8017D0A4
    if (ctx->r15 != 0) {
        // 0x8017C8D8: nop
    
            goto L_8017D0A4;
    }
    // 0x8017C8D8: nop

    // 0x8017C8DC: lbu         $t9, 0x1C($t5)
    ctx->r25 = MEM_BU(ctx->r13, 0X1C);
    // 0x8017C8E0: bne         $t9, $zero, L_8017D0A4
    if (ctx->r25 != 0) {
        // 0x8017C8E4: lui         $at, 0xC316
        ctx->r1 = S32(0XC316 << 16);
            goto L_8017D0A4;
    }
    // 0x8017C8E4: lui         $at, 0xC316
    ctx->r1 = S32(0XC316 << 16);
    // 0x8017C8E8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017C8EC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017C8F0: lui         $at, 0xC270
    ctx->r1 = S32(0XC270 << 16);
    // 0x8017C8F4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017C8F8: addiu       $t3, $t3, 0x3B40
    ctx->r11 = ADD32(ctx->r11, 0X3B40);
    // 0x8017C8FC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8017C900: sb          $t0, 0x11($t3)
    MEM_B(0X11, ctx->r11) = ctx->r8;
    // 0x8017C904: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017C908: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x8017C90C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017C910: lui         $at, 0xC396
    ctx->r1 = S32(0XC396 << 16);
    // 0x8017C914: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8017C918: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x8017C91C: swc1        $f4, 0xC0($t1)
    MEM_W(0XC0, ctx->r9) = ctx->f4.u32l;
    // 0x8017C920: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017C924: swc1        $f6, 0xC4($t4)
    MEM_W(0XC4, ctx->r12) = ctx->f6.u32l;
    // 0x8017C928: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x8017C92C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017C930: addiu       $t6, $t6, 0x3B00
    ctx->r14 = ADD32(ctx->r14, 0X3B00);
    // 0x8017C934: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8017C938: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017C93C: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x8017C940: swc1        $f8, 0xC8($t2)
    MEM_W(0XC8, ctx->r10) = ctx->f8.u32l;
    // 0x8017C944: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017C948: sb          $t8, 0x30($t6)
    MEM_B(0X30, ctx->r14) = ctx->r24;
    // 0x8017C94C: addiu       $t5, $t5, 0x3B00
    ctx->r13 = ADD32(ctx->r13, 0X3B00);
    // 0x8017C950: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8017C954: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017C958: sb          $t7, 0x31($t5)
    MEM_B(0X31, ctx->r13) = ctx->r15;
    // 0x8017C95C: addiu       $t0, $t0, 0x3B00
    ctx->r8 = ADD32(ctx->r8, 0X3B00);
    // 0x8017C960: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8017C964: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017C968: lui         $at, 0xC270
    ctx->r1 = S32(0XC270 << 16);
    // 0x8017C96C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8017C970: sb          $t9, 0x32($t0)
    MEM_B(0X32, ctx->r8) = ctx->r25;
    // 0x8017C974: addiu       $t3, $t3, 0x3B00
    ctx->r11 = ADD32(ctx->r11, 0X3B00);
    // 0x8017C978: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017C97C: sb          $zero, 0x33($t3)
    MEM_B(0X33, ctx->r11) = 0;
    // 0x8017C980: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x8017C984: lui         $at, 0xC396
    ctx->r1 = S32(0XC396 << 16);
    // 0x8017C988: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8017C98C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017C990: swc1        $f10, 0xE0($t1)
    MEM_W(0XE0, ctx->r9) = ctx->f10.u32l;
    // 0x8017C994: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x8017C998: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017C99C: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x8017C9A0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017C9A4: swc1        $f16, 0xE4($t4)
    MEM_W(0XE4, ctx->r12) = ctx->f16.u32l;
    // 0x8017C9A8: addiu       $t6, $t6, 0x3B00
    ctx->r14 = ADD32(ctx->r14, 0X3B00);
    // 0x8017C9AC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017C9B0: swc1        $f18, 0xE8($t2)
    MEM_W(0XE8, ctx->r10) = ctx->f18.u32l;
    // 0x8017C9B4: sb          $t8, 0x38($t6)
    MEM_B(0X38, ctx->r14) = ctx->r24;
    // 0x8017C9B8: addiu       $t5, $t5, 0x3B00
    ctx->r13 = ADD32(ctx->r13, 0X3B00);
    // 0x8017C9BC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017C9C0: sb          $t7, 0x39($t5)
    MEM_B(0X39, ctx->r13) = ctx->r15;
    // 0x8017C9C4: addiu       $t0, $t0, 0x3B00
    ctx->r8 = ADD32(ctx->r8, 0X3B00);
    // 0x8017C9C8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017C9CC: sb          $t9, 0x3A($t0)
    MEM_B(0X3A, ctx->r8) = ctx->r25;
    // 0x8017C9D0: addiu       $t3, $t3, 0x3B00
    ctx->r11 = ADD32(ctx->r11, 0X3B00);
    // 0x8017C9D4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017C9D8: sb          $zero, 0x3B($t3)
    MEM_B(0X3B, ctx->r11) = 0;
    // 0x8017C9DC: addiu       $t1, $t1, 0x3D00
    ctx->r9 = ADD32(ctx->r9, 0X3D00);
    // 0x8017C9E0: lwc1        $f4, 0x0($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X0);
    // 0x8017C9E4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8017C9E8: nop

    // 0x8017C9EC: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x8017C9F0: nop

    // 0x8017C9F4: bc1t        L_8017CAF4
    if (c1cs) {
        // 0x8017C9F8: lui         $at, 0x8018
        ctx->r1 = S32(0X8018 << 16);
            goto L_8017CAF4;
    }
    // 0x8017C9F8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017C9FC: lwc1        $f8, -0x1DE0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1DE0);
    // 0x8017CA00: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017CA04: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x8017CA08: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017CA0C: swc1        $f8, 0xCC($t4)
    MEM_W(0XCC, ctx->r12) = ctx->f8.u32l;
    // 0x8017CA10: lwc1        $f10, -0x1DDC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X1DDC);
    // 0x8017CA14: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8017CA18: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017CA1C: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x8017CA20: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017CA24: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x8017CA28: swc1        $f10, 0xD0($t2)
    MEM_W(0XD0, ctx->r10) = ctx->f10.u32l;
    // 0x8017CA2C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017CA30: swc1        $f16, 0xD4($t8)
    MEM_W(0XD4, ctx->r24) = ctx->f16.u32l;
    // 0x8017CA34: lwc1        $f18, -0x1DD8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X1DD8);
    // 0x8017CA38: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017CA3C: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x8017CA40: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017CA44: swc1        $f18, 0xD8($t6)
    MEM_W(0XD8, ctx->r14) = ctx->f18.u32l;
    // 0x8017CA48: lwc1        $f4, -0x1DD4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1DD4);
    // 0x8017CA4C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017CA50: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x8017CA54: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017CA58: swc1        $f4, 0xEC($t7)
    MEM_W(0XEC, ctx->r15) = ctx->f4.u32l;
    // 0x8017CA5C: lwc1        $f6, -0x1DD0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1DD0);
    // 0x8017CA60: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8017CA64: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017CA68: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x8017CA6C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017CA70: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x8017CA74: swc1        $f6, 0xF0($t5)
    MEM_W(0XF0, ctx->r13) = ctx->f6.u32l;
    // 0x8017CA78: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017CA7C: swc1        $f8, 0xF4($t9)
    MEM_W(0XF4, ctx->r25) = ctx->f8.u32l;
    // 0x8017CA80: lwc1        $f10, -0x1DCC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X1DCC);
    // 0x8017CA84: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017CA88: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x8017CA8C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017CA90: addiu       $t1, $t1, 0x3B00
    ctx->r9 = ADD32(ctx->r9, 0X3B00);
    // 0x8017CA94: addiu       $t3, $zero, 0x80
    ctx->r11 = ADD32(0, 0X80);
    // 0x8017CA98: swc1        $f10, 0xF8($t0)
    MEM_W(0XF8, ctx->r8) = ctx->f10.u32l;
    // 0x8017CA9C: sb          $t3, 0x30($t1)
    MEM_B(0X30, ctx->r9) = ctx->r11;
    // 0x8017CAA0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017CAA4: addiu       $t2, $t2, 0x3B00
    ctx->r10 = ADD32(ctx->r10, 0X3B00);
    // 0x8017CAA8: addiu       $t4, $zero, 0x80
    ctx->r12 = ADD32(0, 0X80);
    // 0x8017CAAC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017CAB0: sb          $t4, 0x31($t2)
    MEM_B(0X31, ctx->r10) = ctx->r12;
    // 0x8017CAB4: addiu       $t6, $t6, 0x3B00
    ctx->r14 = ADD32(ctx->r14, 0X3B00);
    // 0x8017CAB8: addiu       $t8, $zero, 0x80
    ctx->r24 = ADD32(0, 0X80);
    // 0x8017CABC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017CAC0: sb          $t8, 0x32($t6)
    MEM_B(0X32, ctx->r14) = ctx->r24;
    // 0x8017CAC4: addiu       $t5, $t5, 0x3B00
    ctx->r13 = ADD32(ctx->r13, 0X3B00);
    // 0x8017CAC8: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8017CACC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017CAD0: sb          $t7, 0x38($t5)
    MEM_B(0X38, ctx->r13) = ctx->r15;
    // 0x8017CAD4: addiu       $t0, $t0, 0x3B00
    ctx->r8 = ADD32(ctx->r8, 0X3B00);
    // 0x8017CAD8: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8017CADC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017CAE0: sb          $t9, 0x39($t0)
    MEM_B(0X39, ctx->r8) = ctx->r25;
    // 0x8017CAE4: addiu       $t1, $t1, 0x3B00
    ctx->r9 = ADD32(ctx->r9, 0X3B00);
    // 0x8017CAE8: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x8017CAEC: b           L_8017CBEC
    // 0x8017CAF0: sb          $t3, 0x3A($t1)
    MEM_B(0X3A, ctx->r9) = ctx->r11;
        goto L_8017CBEC;
    // 0x8017CAF0: sb          $t3, 0x3A($t1)
    MEM_B(0X3A, ctx->r9) = ctx->r11;
L_8017CAF4:
    // 0x8017CAF4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017CAF8: lwc1        $f16, -0x1DC8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X1DC8);
    // 0x8017CAFC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017CB00: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x8017CB04: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017CB08: swc1        $f16, 0xCC($t4)
    MEM_W(0XCC, ctx->r12) = ctx->f16.u32l;
    // 0x8017CB0C: lwc1        $f18, -0x1DC4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X1DC4);
    // 0x8017CB10: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017CB14: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017CB18: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x8017CB1C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017CB20: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x8017CB24: swc1        $f18, 0xD0($t2)
    MEM_W(0XD0, ctx->r10) = ctx->f18.u32l;
    // 0x8017CB28: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017CB2C: swc1        $f4, 0xD4($t8)
    MEM_W(0XD4, ctx->r24) = ctx->f4.u32l;
    // 0x8017CB30: lwc1        $f6, -0x1DC0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1DC0);
    // 0x8017CB34: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017CB38: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x8017CB3C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017CB40: swc1        $f6, 0xD8($t6)
    MEM_W(0XD8, ctx->r14) = ctx->f6.u32l;
    // 0x8017CB44: lwc1        $f8, -0x1DBC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1DBC);
    // 0x8017CB48: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017CB4C: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x8017CB50: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017CB54: swc1        $f8, 0xEC($t7)
    MEM_W(0XEC, ctx->r15) = ctx->f8.u32l;
    // 0x8017CB58: lwc1        $f10, -0x1DB8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X1DB8);
    // 0x8017CB5C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8017CB60: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017CB64: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x8017CB68: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017CB6C: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x8017CB70: swc1        $f10, 0xF0($t5)
    MEM_W(0XF0, ctx->r13) = ctx->f10.u32l;
    // 0x8017CB74: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017CB78: swc1        $f16, 0xF4($t9)
    MEM_W(0XF4, ctx->r25) = ctx->f16.u32l;
    // 0x8017CB7C: lwc1        $f18, -0x1DB4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X1DB4);
    // 0x8017CB80: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017CB84: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x8017CB88: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017CB8C: addiu       $t1, $t1, 0x3B00
    ctx->r9 = ADD32(ctx->r9, 0X3B00);
    // 0x8017CB90: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x8017CB94: swc1        $f18, 0xF8($t0)
    MEM_W(0XF8, ctx->r8) = ctx->f18.u32l;
    // 0x8017CB98: sb          $t3, 0x30($t1)
    MEM_B(0X30, ctx->r9) = ctx->r11;
    // 0x8017CB9C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017CBA0: addiu       $t2, $t2, 0x3B00
    ctx->r10 = ADD32(ctx->r10, 0X3B00);
    // 0x8017CBA4: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x8017CBA8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017CBAC: sb          $t4, 0x31($t2)
    MEM_B(0X31, ctx->r10) = ctx->r12;
    // 0x8017CBB0: addiu       $t6, $t6, 0x3B00
    ctx->r14 = ADD32(ctx->r14, 0X3B00);
    // 0x8017CBB4: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8017CBB8: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017CBBC: sb          $t8, 0x32($t6)
    MEM_B(0X32, ctx->r14) = ctx->r24;
    // 0x8017CBC0: addiu       $t5, $t5, 0x3B00
    ctx->r13 = ADD32(ctx->r13, 0X3B00);
    // 0x8017CBC4: addiu       $t7, $zero, 0x80
    ctx->r15 = ADD32(0, 0X80);
    // 0x8017CBC8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017CBCC: sb          $t7, 0x38($t5)
    MEM_B(0X38, ctx->r13) = ctx->r15;
    // 0x8017CBD0: addiu       $t0, $t0, 0x3B00
    ctx->r8 = ADD32(ctx->r8, 0X3B00);
    // 0x8017CBD4: addiu       $t9, $zero, 0x80
    ctx->r25 = ADD32(0, 0X80);
    // 0x8017CBD8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017CBDC: sb          $t9, 0x39($t0)
    MEM_B(0X39, ctx->r8) = ctx->r25;
    // 0x8017CBE0: addiu       $t1, $t1, 0x3B00
    ctx->r9 = ADD32(ctx->r9, 0X3B00);
    // 0x8017CBE4: addiu       $t3, $zero, 0x80
    ctx->r11 = ADD32(0, 0X80);
    // 0x8017CBE8: sb          $t3, 0x3A($t1)
    MEM_B(0X3A, ctx->r9) = ctx->r11;
L_8017CBEC:
    // 0x8017CBEC: jal         0x8017C480
    // 0x8017CBF0: nop

    func_8017C480_111CC0(rdram, ctx);
        goto after_0;
    // 0x8017CBF0: nop

    after_0:
    // 0x8017CBF4: b           L_8017D0A4
    // 0x8017CBF8: nop

        goto L_8017D0A4;
    // 0x8017CBF8: nop

L_8017CBFC:
    // 0x8017CBFC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017CC00: addiu       $t4, $t4, 0x3B00
    ctx->r12 = ADD32(ctx->r12, 0X3B00);
    // 0x8017CC04: lbu         $t2, 0x33($t4)
    ctx->r10 = MEM_BU(ctx->r12, 0X33);
    // 0x8017CC08: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x8017CC0C: lbu         $t8, 0x3B($t4)
    ctx->r24 = MEM_BU(ctx->r12, 0X3B);
    // 0x8017CC10: addiu       $t6, $t2, 0x1E
    ctx->r14 = ADD32(ctx->r10, 0X1E);
    // 0x8017CC14: slti        $at, $t6, 0xFF
    ctx->r1 = SIGNED(ctx->r14) < 0XFF ? 1 : 0;
    // 0x8017CC18: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x8017CC1C: addiu       $t7, $t8, 0x1E
    ctx->r15 = ADD32(ctx->r24, 0X1E);
    // 0x8017CC20: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x8017CC24: bne         $at, $zero, L_8017CC38
    if (ctx->r1 != 0) {
        // 0x8017CC28: sw          $t7, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r15;
            goto L_8017CC38;
    }
    // 0x8017CC28: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x8017CC2C: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x8017CC30: b           L_8017CC48
    // 0x8017CC34: sb          $t5, 0x33($t4)
    MEM_B(0X33, ctx->r12) = ctx->r13;
        goto L_8017CC48;
    // 0x8017CC34: sb          $t5, 0x33($t4)
    MEM_B(0X33, ctx->r12) = ctx->r13;
L_8017CC38:
    // 0x8017CC38: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8017CC3C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017CC40: addiu       $t0, $t0, 0x3B00
    ctx->r8 = ADD32(ctx->r8, 0X3B00);
    // 0x8017CC44: sb          $t9, 0x33($t0)
    MEM_B(0X33, ctx->r8) = ctx->r25;
L_8017CC48:
    // 0x8017CC48: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x8017CC4C: slti        $at, $t3, 0xFF
    ctx->r1 = SIGNED(ctx->r11) < 0XFF ? 1 : 0;
    // 0x8017CC50: bne         $at, $zero, L_8017CC6C
    if (ctx->r1 != 0) {
        // 0x8017CC54: nop
    
            goto L_8017CC6C;
    }
    // 0x8017CC54: nop

    // 0x8017CC58: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017CC5C: addiu       $t2, $t2, 0x3B00
    ctx->r10 = ADD32(ctx->r10, 0X3B00);
    // 0x8017CC60: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x8017CC64: b           L_8017CC7C
    // 0x8017CC68: sb          $t1, 0x3B($t2)
    MEM_B(0X3B, ctx->r10) = ctx->r9;
        goto L_8017CC7C;
    // 0x8017CC68: sb          $t1, 0x3B($t2)
    MEM_B(0X3B, ctx->r10) = ctx->r9;
L_8017CC6C:
    // 0x8017CC6C: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8017CC70: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017CC74: addiu       $t7, $t7, 0x3B00
    ctx->r15 = ADD32(ctx->r15, 0X3B00);
    // 0x8017CC78: sb          $t8, 0x3B($t7)
    MEM_B(0X3B, ctx->r15) = ctx->r24;
L_8017CC7C:
    // 0x8017CC7C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017CC80: addiu       $t6, $t6, 0x3B00
    ctx->r14 = ADD32(ctx->r14, 0X3B00);
    // 0x8017CC84: lbu         $t5, 0x33($t6)
    ctx->r13 = MEM_BU(ctx->r14, 0X33);
    // 0x8017CC88: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8017CC8C: bne         $t5, $at, L_8017CCB4
    if (ctx->r13 != ctx->r1) {
        // 0x8017CC90: nop
    
            goto L_8017CCB4;
    }
    // 0x8017CC90: nop

    // 0x8017CC94: lbu         $t4, 0x3B($t6)
    ctx->r12 = MEM_BU(ctx->r14, 0X3B);
    // 0x8017CC98: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8017CC9C: bne         $t4, $at, L_8017CCB4
    if (ctx->r12 != ctx->r1) {
        // 0x8017CCA0: nop
    
            goto L_8017CCB4;
    }
    // 0x8017CCA0: nop

    // 0x8017CCA4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017CCA8: addiu       $t0, $t0, 0x3B40
    ctx->r8 = ADD32(ctx->r8, 0X3B40);
    // 0x8017CCAC: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8017CCB0: sb          $t9, 0x11($t0)
    MEM_B(0X11, ctx->r8) = ctx->r25;
L_8017CCB4:
    // 0x8017CCB4: jal         0x8017C480
    // 0x8017CCB8: nop

    func_8017C480_111CC0(rdram, ctx);
        goto after_1;
    // 0x8017CCB8: nop

    after_1:
    // 0x8017CCBC: b           L_8017D0A4
    // 0x8017CCC0: nop

        goto L_8017D0A4;
    // 0x8017CCC0: nop

L_8017CCC4:
    // 0x8017CCC4: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017CCC8: addiu       $t3, $t3, 0x3D00
    ctx->r11 = ADD32(ctx->r11, 0X3D00);
    // 0x8017CCCC: lwc1        $f4, 0x0($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X0);
    // 0x8017CCD0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8017CCD4: nop

    // 0x8017CCD8: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x8017CCDC: nop

    // 0x8017CCE0: bc1t        L_8017CDE0
    if (c1cs) {
        // 0x8017CCE4: lui         $at, 0x8018
        ctx->r1 = S32(0X8018 << 16);
            goto L_8017CDE0;
    }
    // 0x8017CCE4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017CCE8: lwc1        $f8, -0x1DB0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1DB0);
    // 0x8017CCEC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017CCF0: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x8017CCF4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017CCF8: swc1        $f8, 0xEC($t1)
    MEM_W(0XEC, ctx->r9) = ctx->f8.u32l;
    // 0x8017CCFC: lwc1        $f10, -0x1DAC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X1DAC);
    // 0x8017CD00: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8017CD04: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017CD08: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x8017CD0C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017CD10: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x8017CD14: swc1        $f10, 0xF0($t2)
    MEM_W(0XF0, ctx->r10) = ctx->f10.u32l;
    // 0x8017CD18: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017CD1C: swc1        $f16, 0xF4($t8)
    MEM_W(0XF4, ctx->r24) = ctx->f16.u32l;
    // 0x8017CD20: lwc1        $f18, -0x1DA8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X1DA8);
    // 0x8017CD24: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017CD28: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x8017CD2C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017CD30: swc1        $f18, 0xF8($t7)
    MEM_W(0XF8, ctx->r15) = ctx->f18.u32l;
    // 0x8017CD34: lwc1        $f4, -0x1DA4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1DA4);
    // 0x8017CD38: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017CD3C: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x8017CD40: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017CD44: swc1        $f4, 0xCC($t5)
    MEM_W(0XCC, ctx->r13) = ctx->f4.u32l;
    // 0x8017CD48: lwc1        $f6, -0x1DA0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1DA0);
    // 0x8017CD4C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8017CD50: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017CD54: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x8017CD58: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017CD5C: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x8017CD60: swc1        $f6, 0xD0($t6)
    MEM_W(0XD0, ctx->r14) = ctx->f6.u32l;
    // 0x8017CD64: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017CD68: swc1        $f8, 0xD4($t4)
    MEM_W(0XD4, ctx->r12) = ctx->f8.u32l;
    // 0x8017CD6C: lwc1        $f10, -0x1D9C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X1D9C);
    // 0x8017CD70: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017CD74: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x8017CD78: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017CD7C: addiu       $t3, $t3, 0x3B00
    ctx->r11 = ADD32(ctx->r11, 0X3B00);
    // 0x8017CD80: addiu       $t0, $zero, 0x80
    ctx->r8 = ADD32(0, 0X80);
    // 0x8017CD84: swc1        $f10, 0xD8($t9)
    MEM_W(0XD8, ctx->r25) = ctx->f10.u32l;
    // 0x8017CD88: sb          $t0, 0x30($t3)
    MEM_B(0X30, ctx->r11) = ctx->r8;
    // 0x8017CD8C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017CD90: addiu       $t2, $t2, 0x3B00
    ctx->r10 = ADD32(ctx->r10, 0X3B00);
    // 0x8017CD94: addiu       $t1, $zero, 0x80
    ctx->r9 = ADD32(0, 0X80);
    // 0x8017CD98: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017CD9C: sb          $t1, 0x31($t2)
    MEM_B(0X31, ctx->r10) = ctx->r9;
    // 0x8017CDA0: addiu       $t7, $t7, 0x3B00
    ctx->r15 = ADD32(ctx->r15, 0X3B00);
    // 0x8017CDA4: addiu       $t8, $zero, 0x80
    ctx->r24 = ADD32(0, 0X80);
    // 0x8017CDA8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017CDAC: sb          $t8, 0x32($t7)
    MEM_B(0X32, ctx->r15) = ctx->r24;
    // 0x8017CDB0: addiu       $t6, $t6, 0x3B00
    ctx->r14 = ADD32(ctx->r14, 0X3B00);
    // 0x8017CDB4: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x8017CDB8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017CDBC: sb          $t5, 0x38($t6)
    MEM_B(0X38, ctx->r14) = ctx->r13;
    // 0x8017CDC0: addiu       $t9, $t9, 0x3B00
    ctx->r25 = ADD32(ctx->r25, 0X3B00);
    // 0x8017CDC4: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x8017CDC8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017CDCC: sb          $t4, 0x39($t9)
    MEM_B(0X39, ctx->r25) = ctx->r12;
    // 0x8017CDD0: addiu       $t3, $t3, 0x3B00
    ctx->r11 = ADD32(ctx->r11, 0X3B00);
    // 0x8017CDD4: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x8017CDD8: b           L_8017CED8
    // 0x8017CDDC: sb          $t0, 0x3A($t3)
    MEM_B(0X3A, ctx->r11) = ctx->r8;
        goto L_8017CED8;
    // 0x8017CDDC: sb          $t0, 0x3A($t3)
    MEM_B(0X3A, ctx->r11) = ctx->r8;
L_8017CDE0:
    // 0x8017CDE0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017CDE4: lwc1        $f16, -0x1D98($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X1D98);
    // 0x8017CDE8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017CDEC: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x8017CDF0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017CDF4: swc1        $f16, 0xEC($t1)
    MEM_W(0XEC, ctx->r9) = ctx->f16.u32l;
    // 0x8017CDF8: lwc1        $f18, -0x1D94($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X1D94);
    // 0x8017CDFC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017CE00: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017CE04: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x8017CE08: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017CE0C: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x8017CE10: swc1        $f18, 0xF0($t2)
    MEM_W(0XF0, ctx->r10) = ctx->f18.u32l;
    // 0x8017CE14: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017CE18: swc1        $f4, 0xF4($t8)
    MEM_W(0XF4, ctx->r24) = ctx->f4.u32l;
    // 0x8017CE1C: lwc1        $f6, -0x1D90($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1D90);
    // 0x8017CE20: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017CE24: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x8017CE28: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017CE2C: swc1        $f6, 0xF8($t7)
    MEM_W(0XF8, ctx->r15) = ctx->f6.u32l;
    // 0x8017CE30: lwc1        $f8, -0x1D8C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1D8C);
    // 0x8017CE34: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017CE38: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x8017CE3C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017CE40: swc1        $f8, 0xCC($t5)
    MEM_W(0XCC, ctx->r13) = ctx->f8.u32l;
    // 0x8017CE44: lwc1        $f10, -0x1D88($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X1D88);
    // 0x8017CE48: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8017CE4C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017CE50: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x8017CE54: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017CE58: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x8017CE5C: swc1        $f10, 0xD0($t6)
    MEM_W(0XD0, ctx->r14) = ctx->f10.u32l;
    // 0x8017CE60: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017CE64: swc1        $f16, 0xD4($t4)
    MEM_W(0XD4, ctx->r12) = ctx->f16.u32l;
    // 0x8017CE68: lwc1        $f18, -0x1D84($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X1D84);
    // 0x8017CE6C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017CE70: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x8017CE74: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017CE78: addiu       $t3, $t3, 0x3B00
    ctx->r11 = ADD32(ctx->r11, 0X3B00);
    // 0x8017CE7C: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x8017CE80: swc1        $f18, 0xD8($t9)
    MEM_W(0XD8, ctx->r25) = ctx->f18.u32l;
    // 0x8017CE84: sb          $t0, 0x30($t3)
    MEM_B(0X30, ctx->r11) = ctx->r8;
    // 0x8017CE88: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017CE8C: addiu       $t2, $t2, 0x3B00
    ctx->r10 = ADD32(ctx->r10, 0X3B00);
    // 0x8017CE90: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x8017CE94: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017CE98: sb          $t1, 0x31($t2)
    MEM_B(0X31, ctx->r10) = ctx->r9;
    // 0x8017CE9C: addiu       $t7, $t7, 0x3B00
    ctx->r15 = ADD32(ctx->r15, 0X3B00);
    // 0x8017CEA0: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8017CEA4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017CEA8: sb          $t8, 0x32($t7)
    MEM_B(0X32, ctx->r15) = ctx->r24;
    // 0x8017CEAC: addiu       $t6, $t6, 0x3B00
    ctx->r14 = ADD32(ctx->r14, 0X3B00);
    // 0x8017CEB0: addiu       $t5, $zero, 0x80
    ctx->r13 = ADD32(0, 0X80);
    // 0x8017CEB4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017CEB8: sb          $t5, 0x38($t6)
    MEM_B(0X38, ctx->r14) = ctx->r13;
    // 0x8017CEBC: addiu       $t9, $t9, 0x3B00
    ctx->r25 = ADD32(ctx->r25, 0X3B00);
    // 0x8017CEC0: addiu       $t4, $zero, 0x80
    ctx->r12 = ADD32(0, 0X80);
    // 0x8017CEC4: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017CEC8: sb          $t4, 0x39($t9)
    MEM_B(0X39, ctx->r25) = ctx->r12;
    // 0x8017CECC: addiu       $t3, $t3, 0x3B00
    ctx->r11 = ADD32(ctx->r11, 0X3B00);
    // 0x8017CED0: addiu       $t0, $zero, 0x80
    ctx->r8 = ADD32(0, 0X80);
    // 0x8017CED4: sb          $t0, 0x3A($t3)
    MEM_B(0X3A, ctx->r11) = ctx->r8;
L_8017CED8:
    // 0x8017CED8: jal         0x8017C480
    // 0x8017CEDC: nop

    func_8017C480_111CC0(rdram, ctx);
        goto after_2;
    // 0x8017CEDC: nop

    after_2:
    // 0x8017CEE0: b           L_8017D0A4
    // 0x8017CEE4: nop

        goto L_8017D0A4;
    // 0x8017CEE4: nop

L_8017CEE8:
    // 0x8017CEE8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017CEEC: addiu       $t1, $t1, 0x3B00
    ctx->r9 = ADD32(ctx->r9, 0X3B00);
    // 0x8017CEF0: lbu         $t2, 0x33($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X33);
    // 0x8017CEF4: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x8017CEF8: lbu         $t8, 0x3B($t1)
    ctx->r24 = MEM_BU(ctx->r9, 0X3B);
    // 0x8017CEFC: addiu       $t7, $t2, -0x1E
    ctx->r15 = ADD32(ctx->r10, -0X1E);
    // 0x8017CF00: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x8017CF04: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x8017CF08: addiu       $t5, $t8, -0x1E
    ctx->r13 = ADD32(ctx->r24, -0X1E);
    // 0x8017CF0C: bgez        $t7, L_8017CF1C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8017CF10: sw          $t5, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r13;
            goto L_8017CF1C;
    }
    // 0x8017CF10: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x8017CF14: b           L_8017CF2C
    // 0x8017CF18: sb          $zero, 0x33($t1)
    MEM_B(0X33, ctx->r9) = 0;
        goto L_8017CF2C;
    // 0x8017CF18: sb          $zero, 0x33($t1)
    MEM_B(0X33, ctx->r9) = 0;
L_8017CF1C:
    // 0x8017CF1C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8017CF20: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017CF24: addiu       $t4, $t4, 0x3B00
    ctx->r12 = ADD32(ctx->r12, 0X3B00);
    // 0x8017CF28: sb          $t6, 0x33($t4)
    MEM_B(0X33, ctx->r12) = ctx->r14;
L_8017CF2C:
    // 0x8017CF2C: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8017CF30: bgez        $t9, L_8017CF48
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8017CF34: nop
    
            goto L_8017CF48;
    }
    // 0x8017CF34: nop

    // 0x8017CF38: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017CF3C: addiu       $t0, $t0, 0x3B00
    ctx->r8 = ADD32(ctx->r8, 0X3B00);
    // 0x8017CF40: b           L_8017CF58
    // 0x8017CF44: sb          $zero, 0x3B($t0)
    MEM_B(0X3B, ctx->r8) = 0;
        goto L_8017CF58;
    // 0x8017CF44: sb          $zero, 0x3B($t0)
    MEM_B(0X3B, ctx->r8) = 0;
L_8017CF48:
    // 0x8017CF48: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x8017CF4C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017CF50: addiu       $t2, $t2, 0x3B00
    ctx->r10 = ADD32(ctx->r10, 0X3B00);
    // 0x8017CF54: sb          $t3, 0x3B($t2)
    MEM_B(0X3B, ctx->r10) = ctx->r11;
L_8017CF58:
    // 0x8017CF58: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017CF5C: addiu       $t8, $t8, 0x3B00
    ctx->r24 = ADD32(ctx->r24, 0X3B00);
    // 0x8017CF60: lbu         $t5, 0x33($t8)
    ctx->r13 = MEM_BU(ctx->r24, 0X33);
    // 0x8017CF64: bne         $t5, $zero, L_8017CF88
    if (ctx->r13 != 0) {
        // 0x8017CF68: nop
    
            goto L_8017CF88;
    }
    // 0x8017CF68: nop

    // 0x8017CF6C: lbu         $t7, 0x3B($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0X3B);
    // 0x8017CF70: bne         $t7, $zero, L_8017CF88
    if (ctx->r15 != 0) {
        // 0x8017CF74: nop
    
            goto L_8017CF88;
    }
    // 0x8017CF74: nop

    // 0x8017CF78: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017CF7C: addiu       $t6, $t6, 0x3B40
    ctx->r14 = ADD32(ctx->r14, 0X3B40);
    // 0x8017CF80: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x8017CF84: sb          $t1, 0x11($t6)
    MEM_B(0X11, ctx->r14) = ctx->r9;
L_8017CF88:
    // 0x8017CF88: jal         0x8017C480
    // 0x8017CF8C: nop

    func_8017C480_111CC0(rdram, ctx);
        goto after_3;
    // 0x8017CF8C: nop

    after_3:
    // 0x8017CF90: b           L_8017D0A4
    // 0x8017CF94: nop

        goto L_8017D0A4;
    // 0x8017CF94: nop

L_8017CF98:
    // 0x8017CF98: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017CF9C: addiu       $t4, $t4, 0x3B00
    ctx->r12 = ADD32(ctx->r12, 0X3B00);
    // 0x8017CFA0: lbu         $t9, 0x13($t4)
    ctx->r25 = MEM_BU(ctx->r12, 0X13);
    // 0x8017CFA4: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x8017CFA8: lbu         $t0, 0x1B($t4)
    ctx->r8 = MEM_BU(ctx->r12, 0X1B);
    // 0x8017CFAC: addiu       $t2, $t9, 0x1E
    ctx->r10 = ADD32(ctx->r25, 0X1E);
    // 0x8017CFB0: slti        $at, $t2, 0x92
    ctx->r1 = SIGNED(ctx->r10) < 0X92 ? 1 : 0;
    // 0x8017CFB4: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8017CFB8: lbu         $t3, 0x1C($t4)
    ctx->r11 = MEM_BU(ctx->r12, 0X1C);
    // 0x8017CFBC: addiu       $t5, $t0, 0x1E
    ctx->r13 = ADD32(ctx->r8, 0X1E);
    // 0x8017CFC0: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x8017CFC4: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x8017CFC8: addiu       $t8, $t3, 0x1E
    ctx->r24 = ADD32(ctx->r11, 0X1E);
    // 0x8017CFCC: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x8017CFD0: bne         $at, $zero, L_8017CFE4
    if (ctx->r1 != 0) {
        // 0x8017CFD4: sw          $t8, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r24;
            goto L_8017CFE4;
    }
    // 0x8017CFD4: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x8017CFD8: addiu       $t7, $zero, 0x91
    ctx->r15 = ADD32(0, 0X91);
    // 0x8017CFDC: b           L_8017CFF4
    // 0x8017CFE0: sb          $t7, 0x13($t4)
    MEM_B(0X13, ctx->r12) = ctx->r15;
        goto L_8017CFF4;
    // 0x8017CFE0: sb          $t7, 0x13($t4)
    MEM_B(0X13, ctx->r12) = ctx->r15;
L_8017CFE4:
    // 0x8017CFE4: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8017CFE8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017CFEC: addiu       $t6, $t6, 0x3B00
    ctx->r14 = ADD32(ctx->r14, 0X3B00);
    // 0x8017CFF0: sb          $t1, 0x13($t6)
    MEM_B(0X13, ctx->r14) = ctx->r9;
L_8017CFF4:
    // 0x8017CFF4: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8017CFF8: slti        $at, $t9, 0x92
    ctx->r1 = SIGNED(ctx->r25) < 0X92 ? 1 : 0;
    // 0x8017CFFC: bne         $at, $zero, L_8017D018
    if (ctx->r1 != 0) {
        // 0x8017D000: nop
    
            goto L_8017D018;
    }
    // 0x8017D000: nop

    // 0x8017D004: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017D008: addiu       $t5, $t5, 0x3B00
    ctx->r13 = ADD32(ctx->r13, 0X3B00);
    // 0x8017D00C: addiu       $t0, $zero, 0x91
    ctx->r8 = ADD32(0, 0X91);
    // 0x8017D010: b           L_8017D028
    // 0x8017D014: sb          $t0, 0x1B($t5)
    MEM_B(0X1B, ctx->r13) = ctx->r8;
        goto L_8017D028;
    // 0x8017D014: sb          $t0, 0x1B($t5)
    MEM_B(0X1B, ctx->r13) = ctx->r8;
L_8017D018:
    // 0x8017D018: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x8017D01C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017D020: addiu       $t8, $t8, 0x3B00
    ctx->r24 = ADD32(ctx->r24, 0X3B00);
    // 0x8017D024: sb          $t3, 0x1B($t8)
    MEM_B(0X1B, ctx->r24) = ctx->r11;
L_8017D028:
    // 0x8017D028: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8017D02C: slti        $at, $t2, 0x92
    ctx->r1 = SIGNED(ctx->r10) < 0X92 ? 1 : 0;
    // 0x8017D030: bne         $at, $zero, L_8017D04C
    if (ctx->r1 != 0) {
        // 0x8017D034: nop
    
            goto L_8017D04C;
    }
    // 0x8017D034: nop

    // 0x8017D038: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017D03C: addiu       $t4, $t4, 0x3B00
    ctx->r12 = ADD32(ctx->r12, 0X3B00);
    // 0x8017D040: addiu       $t7, $zero, 0x91
    ctx->r15 = ADD32(0, 0X91);
    // 0x8017D044: b           L_8017D05C
    // 0x8017D048: sb          $t7, 0x1C($t4)
    MEM_B(0X1C, ctx->r12) = ctx->r15;
        goto L_8017D05C;
    // 0x8017D048: sb          $t7, 0x1C($t4)
    MEM_B(0X1C, ctx->r12) = ctx->r15;
L_8017D04C:
    // 0x8017D04C: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8017D050: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017D054: addiu       $t6, $t6, 0x3B00
    ctx->r14 = ADD32(ctx->r14, 0X3B00);
    // 0x8017D058: sb          $t1, 0x1C($t6)
    MEM_B(0X1C, ctx->r14) = ctx->r9;
L_8017D05C:
    // 0x8017D05C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017D060: addiu       $t9, $t9, 0x3B00
    ctx->r25 = ADD32(ctx->r25, 0X3B00);
    // 0x8017D064: lbu         $t0, 0x13($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X13);
    // 0x8017D068: addiu       $at, $zero, 0x91
    ctx->r1 = ADD32(0, 0X91);
    // 0x8017D06C: bne         $t0, $at, L_8017D0A4
    if (ctx->r8 != ctx->r1) {
        // 0x8017D070: nop
    
            goto L_8017D0A4;
    }
    // 0x8017D070: nop

    // 0x8017D074: lbu         $t5, 0x1B($t9)
    ctx->r13 = MEM_BU(ctx->r25, 0X1B);
    // 0x8017D078: addiu       $at, $zero, 0x91
    ctx->r1 = ADD32(0, 0X91);
    // 0x8017D07C: bne         $t5, $at, L_8017D0A4
    if (ctx->r13 != ctx->r1) {
        // 0x8017D080: nop
    
            goto L_8017D0A4;
    }
    // 0x8017D080: nop

    // 0x8017D084: lbu         $t3, 0x1C($t9)
    ctx->r11 = MEM_BU(ctx->r25, 0X1C);
    // 0x8017D088: addiu       $at, $zero, 0x91
    ctx->r1 = ADD32(0, 0X91);
    // 0x8017D08C: bne         $t3, $at, L_8017D0A4
    if (ctx->r11 != ctx->r1) {
        // 0x8017D090: nop
    
            goto L_8017D0A4;
    }
    // 0x8017D090: nop

    // 0x8017D094: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017D098: addiu       $t2, $t2, 0x3B40
    ctx->r10 = ADD32(ctx->r10, 0X3B40);
    // 0x8017D09C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8017D0A0: sb          $t8, 0x1($t2)
    MEM_B(0X1, ctx->r10) = ctx->r24;
L_8017D0A4:
    // 0x8017D0A4: jal         0x8017BFB4
    // 0x8017D0A8: nop

    func_8017BFB4_111CC0(rdram, ctx);
        goto after_4;
    // 0x8017D0A8: nop

    after_4:
    // 0x8017D0AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017D0B0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8017D0B4: jr          $ra
    // 0x8017D0B8: nop

    return;
    // 0x8017D0B8: nop

;}
RECOMP_FUNC void func_8017D0BC_111CC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017D0BC: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8017D0C0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017D0C4: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8017D0C8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017D0CC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8017D0D0: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8017D0D4: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x8017D0D8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017D0DC: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x8017D0E0: lui         $at, 0x4060
    ctx->r1 = S32(0X4060 << 16);
    // 0x8017D0E4: swc1        $f4, 0xC0($t6)
    MEM_W(0XC0, ctx->r14) = ctx->f4.u32l;
    // 0x8017D0E8: lwc1        $f6, 0xC0($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0XC0);
    // 0x8017D0EC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8017D0F0: nop

    // 0x8017D0F4: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8017D0F8: swc1        $f10, 0xC4($t7)
    MEM_W(0XC4, ctx->r15) = ctx->f10.u32l;
    // 0x8017D0FC: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
L_8017D100:
    // 0x8017D100: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x8017D104: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x8017D108: slt         $at, $t9, $t8
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8017D10C: beq         $at, $zero, L_8017D170
    if (ctx->r1 == 0) {
        // 0x8017D110: nop
    
            goto L_8017D170;
    }
    // 0x8017D110: nop

    // 0x8017D114: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x8017D118: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017D11C: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x8017D120: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8017D124: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x8017D128: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8017D12C: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x8017D130: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017D134: addiu       $t5, $t5, 0x3B00
    ctx->r13 = ADD32(ctx->r13, 0X3B00);
    // 0x8017D138: swc1        $f18, 0xC8($t0)
    MEM_W(0XC8, ctx->r8) = ctx->f18.u32l;
    // 0x8017D13C: lw          $t1, -0x4514($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4514);
    // 0x8017D140: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x8017D144: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x8017D148: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x8017D14C: sw          $t2, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r10;
    // 0x8017D150: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x8017D154: lbu         $t6, 0x30($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X30);
    // 0x8017D158: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x8017D15C: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x8017D160: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x8017D164: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x8017D168: b           L_8017D1C8
    // 0x8017D16C: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
        goto L_8017D1C8;
    // 0x8017D16C: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
L_8017D170:
    // 0x8017D170: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017D174: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017D178: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x8017D17C: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x8017D180: swc1        $f4, 0xC8($t0)
    MEM_W(0XC8, ctx->r8) = ctx->f4.u32l;
    // 0x8017D184: lw          $t1, -0x4514($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4514);
    // 0x8017D188: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8017D18C: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x8017D190: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x8017D194: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8017D198: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x8017D19C: sw          $t2, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r10;
    // 0x8017D1A0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017D1A4: addiu       $t5, $t5, 0x3B00
    ctx->r13 = ADD32(ctx->r13, 0X3B00);
    // 0x8017D1A8: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x8017D1AC: lbu         $t6, 0x30($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X30);
    // 0x8017D1B0: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8017D1B4: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8017D1B8: ori         $at, $at, 0x4000
    ctx->r1 = ctx->r1 | 0X4000;
    // 0x8017D1BC: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x8017D1C0: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x8017D1C4: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
L_8017D1C8:
    // 0x8017D1C8: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x8017D1CC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017D1D0: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x8017D1D4: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x8017D1D8: lwc1        $f6, 0xC0($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0XC0);
    // 0x8017D1DC: lwc1        $f4, 0xC4($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0XC4);
    // 0x8017D1E0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8017D1E4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8017D1E8: lui         $at, 0xC396
    ctx->r1 = S32(0XC396 << 16);
    // 0x8017D1EC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8017D1F0: ori         $t2, $zero, 0xFFFF
    ctx->r10 = 0 | 0XFFFF;
    // 0x8017D1F4: sub.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8017D1F8: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8017D1FC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017D200: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8017D204: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8017D208: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017D20C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8017D210: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x8017D214: add.s       $f6, $f16, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x8017D218: lwc1        $f16, -0x1D80($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X1D80);
    // 0x8017D21C: lwc1        $f4, 0xC8($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0XC8);
    // 0x8017D220: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8017D224: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8017D228: mul.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x8017D22C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017D230: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017D234: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8017D238: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8017D23C: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x8017D240: addiu       $a0, $a0, -0x4FE0
    ctx->r4 = ADD32(ctx->r4, -0X4FE0);
    // 0x8017D244: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8017D248: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8017D24C: lui         $a3, 0xC2D2
    ctx->r7 = S32(0XC2D2 << 16);
    // 0x8017D250: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x8017D254: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x8017D258: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    // 0x8017D25C: jal         0x800C58E8
    // 0x8017D260: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    func_800C58E8(rdram, ctx);
        goto after_0;
    // 0x8017D260: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    after_0:
    // 0x8017D264: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x8017D268: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8017D26C: slti        $at, $t4, 0x8
    ctx->r1 = SIGNED(ctx->r12) < 0X8 ? 1 : 0;
    // 0x8017D270: bne         $at, $zero, L_8017D100
    if (ctx->r1 != 0) {
        // 0x8017D274: sw          $t4, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r12;
            goto L_8017D100;
    }
    // 0x8017D274: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
    // 0x8017D278: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8017D27C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8017D280: jr          $ra
    // 0x8017D284: nop

    return;
    // 0x8017D284: nop

;}
