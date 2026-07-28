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

RECOMP_FUNC void func_8017151C_02FC30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017151C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80171520: lbu         $t6, 0x5B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X5B);
    // 0x80171524: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80171528: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8017152C: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80171530: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x80171534: beq         $t6, $zero, L_801715D4
    if (ctx->r14 == 0) {
        // 0x80171538: sw          $a3, 0x54($sp)
        MEM_W(0X54, ctx->r29) = ctx->r7;
            goto L_801715D4;
    }
    // 0x80171538: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x8017153C: lbu         $t8, 0x5F($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X5F);
    // 0x80171540: lwc1        $f4, 0x60($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80171544: lbu         $t7, 0x5B($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X5B);
    // 0x80171548: lwc1        $f6, 0x64($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8017154C: lwc1        $f8, 0x68($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80171550: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80171554: lwc1        $f16, 0x70($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80171558: lwc1        $f18, 0x74($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8017155C: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x80171560: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80171564: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80171568: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x8017156C: addiu       $t0, $t0, -0x4198
    ctx->r8 = ADD32(ctx->r8, -0X4198);
    // 0x80171570: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x80171574: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80171578: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8017157C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80171580: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80171584: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x80171588: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x8017158C: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    // 0x80171590: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    // 0x80171594: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    // 0x80171598: lwc1        $f6, 0x24($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X24);
    // 0x8017159C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801715A0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801715A4: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x801715A8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801715AC: lbu         $a0, 0x4B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X4B);
    // 0x801715B0: lbu         $a1, 0x4F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X4F);
    // 0x801715B4: lbu         $a2, 0x53($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X53);
    // 0x801715B8: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x801715BC: lwc1        $f10, 0x28($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X28);
    // 0x801715C0: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    // 0x801715C4: lbu         $a3, 0x57($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X57);
    // 0x801715C8: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    // 0x801715CC: jal         0x801707E8
    // 0x801715D0: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    func_801707E8_02FC30(rdram, ctx);
        goto after_0;
    // 0x801715D0: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    after_0:
L_801715D4:
    // 0x801715D4: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x801715D8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x801715DC: jr          $ra
    // 0x801715E0: nop

    return;
    // 0x801715E0: nop

;}
RECOMP_FUNC void func_801715E4_02FC30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801715E4: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x801715E8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x801715EC: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x801715F0: beq         $a1, $at, L_8017162C
    if (ctx->r5 == ctx->r1) {
        // 0x801715F4: addiu       $sp, $sp, -0x8
        ctx->r29 = ADD32(ctx->r29, -0X8);
            goto L_8017162C;
    }
    // 0x801715F4: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x801715F8: addiu       $at, $zero, 0x5B
    ctx->r1 = ADD32(0, 0X5B);
    // 0x801715FC: beq         $a1, $at, L_8017161C
    if (ctx->r5 == ctx->r1) {
        // 0x80171600: addiu       $at, $zero, 0x5F
        ctx->r1 = ADD32(0, 0X5F);
            goto L_8017161C;
    }
    // 0x80171600: addiu       $at, $zero, 0x5F
    ctx->r1 = ADD32(0, 0X5F);
    // 0x80171604: bne         $a1, $at, L_8017163C
    if (ctx->r5 != ctx->r1) {
        // 0x80171608: nop
    
            goto L_8017163C;
    }
    // 0x80171608: nop

    // 0x8017160C: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x80171610: addiu       $t6, $t6, 0x25C8
    ctx->r14 = ADD32(ctx->r14, 0X25C8);
    // 0x80171614: b           L_801716C0
    // 0x80171618: lwc1        $f0, 0x0($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X0);
        goto L_801716C0;
    // 0x80171618: lwc1        $f0, 0x0($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X0);
L_8017161C:
    // 0x8017161C: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x80171620: addiu       $t7, $t7, 0x25C8
    ctx->r15 = ADD32(ctx->r15, 0X25C8);
    // 0x80171624: b           L_801716C0
    // 0x80171628: lwc1        $f0, 0x4($t7)
    ctx->f0.u32l = MEM_W(ctx->r15, 0X4);
        goto L_801716C0;
    // 0x80171628: lwc1        $f0, 0x4($t7)
    ctx->f0.u32l = MEM_W(ctx->r15, 0X4);
L_8017162C:
    // 0x8017162C: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x80171630: addiu       $t8, $t8, 0x25C8
    ctx->r24 = ADD32(ctx->r24, 0X25C8);
    // 0x80171634: b           L_801716C0
    // 0x80171638: lwc1        $f0, 0x8($t8)
    ctx->f0.u32l = MEM_W(ctx->r24, 0X8);
        goto L_801716C0;
    // 0x80171638: lwc1        $f0, 0x8($t8)
    ctx->f0.u32l = MEM_W(ctx->r24, 0X8);
L_8017163C:
    // 0x8017163C: slti        $at, $a0, 0x30
    ctx->r1 = SIGNED(ctx->r4) < 0X30 ? 1 : 0;
    // 0x80171640: bne         $at, $zero, L_80171664
    if (ctx->r1 != 0) {
        // 0x80171644: slti        $at, $a0, 0x3A
        ctx->r1 = SIGNED(ctx->r4) < 0X3A ? 1 : 0;
            goto L_80171664;
    }
    // 0x80171644: slti        $at, $a0, 0x3A
    ctx->r1 = SIGNED(ctx->r4) < 0X3A ? 1 : 0;
    // 0x80171648: beq         $at, $zero, L_80171664
    if (ctx->r1 == 0) {
        // 0x8017164C: nop
    
            goto L_80171664;
    }
    // 0x8017164C: nop

    // 0x80171650: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x80171654: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80171658: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8017165C: b           L_801716C0
    // 0x80171660: lwc1        $f0, 0x2514($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X2514);
        goto L_801716C0;
    // 0x80171660: lwc1        $f0, 0x2514($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X2514);
L_80171664:
    // 0x80171664: slti        $at, $a0, 0x41
    ctx->r1 = SIGNED(ctx->r4) < 0X41 ? 1 : 0;
    // 0x80171668: bne         $at, $zero, L_8017168C
    if (ctx->r1 != 0) {
        // 0x8017166C: slti        $at, $a0, 0x5B
        ctx->r1 = SIGNED(ctx->r4) < 0X5B ? 1 : 0;
            goto L_8017168C;
    }
    // 0x8017166C: slti        $at, $a0, 0x5B
    ctx->r1 = SIGNED(ctx->r4) < 0X5B ? 1 : 0;
    // 0x80171670: beq         $at, $zero, L_8017168C
    if (ctx->r1 == 0) {
        // 0x80171674: nop
    
            goto L_8017168C;
    }
    // 0x80171674: nop

    // 0x80171678: sll         $t0, $a0, 2
    ctx->r8 = S32(ctx->r4 << 2);
    // 0x8017167C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80171680: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80171684: b           L_801716C0
    // 0x80171688: lwc1        $f0, 0x24F8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X24F8);
        goto L_801716C0;
    // 0x80171688: lwc1        $f0, 0x24F8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X24F8);
L_8017168C:
    // 0x8017168C: slti        $at, $a0, 0x61
    ctx->r1 = SIGNED(ctx->r4) < 0X61 ? 1 : 0;
    // 0x80171690: bne         $at, $zero, L_801716B4
    if (ctx->r1 != 0) {
        // 0x80171694: slti        $at, $a0, 0x7B
        ctx->r1 = SIGNED(ctx->r4) < 0X7B ? 1 : 0;
            goto L_801716B4;
    }
    // 0x80171694: slti        $at, $a0, 0x7B
    ctx->r1 = SIGNED(ctx->r4) < 0X7B ? 1 : 0;
    // 0x80171698: beq         $at, $zero, L_801716B4
    if (ctx->r1 == 0) {
        // 0x8017169C: nop
    
            goto L_801716B4;
    }
    // 0x8017169C: nop

    // 0x801716A0: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x801716A4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801716A8: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x801716AC: b           L_801716C0
    // 0x801716B0: lwc1        $f0, 0x2478($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X2478);
        goto L_801716C0;
    // 0x801716B0: lwc1        $f0, 0x2478($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X2478);
L_801716B4:
    // 0x801716B4: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x801716B8: addiu       $t2, $t2, 0x25C8
    ctx->r10 = ADD32(ctx->r10, 0X25C8);
    // 0x801716BC: lwc1        $f0, 0x8($t2)
    ctx->f0.u32l = MEM_W(ctx->r10, 0X8);
L_801716C0:
    // 0x801716C0: jr          $ra
    // 0x801716C4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x801716C4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_801716C8_02FC30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801716C8: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x801716CC: lbu         $t6, 0x83($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X83);
    // 0x801716D0: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x801716D4: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x801716D8: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x801716DC: sw          $a2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r6;
    // 0x801716E0: sw          $a3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r7;
    // 0x801716E4: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x801716E8: beq         $t6, $zero, L_801719AC
    if (ctx->r14 == 0) {
        // 0x801716EC: sdc1        $f20, 0x48($sp)
        CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X48, ctx->r29);
            goto L_801719AC;
    }
    // 0x801716EC: sdc1        $f20, 0x48($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X48, ctx->r29);
    // 0x801716F0: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x801716F4: lw          $t7, -0x4514($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4514);
    // 0x801716F8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x801716FC: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x80171700: sw          $t7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r15;
    // 0x80171704: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x80171708: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8017170C: sw          $t8, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r24;
    // 0x80171710: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80171714: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x80171718: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017171C: addiu       $a0, $a0, -0x3F68
    ctx->r4 = ADD32(ctx->r4, -0X3F68);
    // 0x80171720: addiu       $a0, $a0, 0xC0
    ctx->r4 = ADD32(ctx->r4, 0XC0);
    // 0x80171724: jal         0x800D6D20
    // 0x80171728: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    guMtxIdentF_recomp(rdram, ctx);
        goto after_0;
    // 0x80171728: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    after_0:
    // 0x8017172C: lw          $t2, 0x70($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X70);
    // 0x80171730: sw          $zero, 0x68($sp)
    MEM_W(0X68, ctx->r29) = 0;
    // 0x80171734: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80171738: lbu         $s0, 0x0($t2)
    ctx->r16 = MEM_BU(ctx->r10, 0X0);
    // 0x8017173C: sw          $t4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r12;
    // 0x80171740: sltu        $t3, $zero, $s0
    ctx->r11 = 0 < ctx->r16 ? 1 : 0;
    // 0x80171744: or          $s0, $t3, $zero
    ctx->r16 = ctx->r11 | 0;
    // 0x80171748: beq         $s0, $zero, L_80171778
    if (ctx->r16 == 0) {
        // 0x8017174C: nop
    
            goto L_80171778;
    }
    // 0x8017174C: nop

L_80171750:
    // 0x80171750: lw          $t5, 0x68($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X68);
    // 0x80171754: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x80171758: addiu       $t9, $t5, 0x1
    ctx->r25 = ADD32(ctx->r13, 0X1);
    // 0x8017175C: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80171760: lbu         $s0, 0x0($t7)
    ctx->r16 = MEM_BU(ctx->r15, 0X0);
    // 0x80171764: sw          $t9, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r25;
    // 0x80171768: sltu        $t8, $zero, $s0
    ctx->r24 = 0 < ctx->r16 ? 1 : 0;
    // 0x8017176C: or          $s0, $t8, $zero
    ctx->r16 = ctx->r24 | 0;
    // 0x80171770: bne         $s0, $zero, L_80171750
    if (ctx->r16 != 0) {
        // 0x80171774: nop
    
            goto L_80171750;
    }
    // 0x80171774: nop

L_80171778:
    // 0x80171778: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017177C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80171780: addiu       $t0, $t0, -0x3FA8
    ctx->r8 = ADD32(ctx->r8, -0X3FA8);
    // 0x80171784: swc1        $f4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f4.u32l;
    // 0x80171788: lw          $t1, 0x68($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X68);
    // 0x8017178C: sw          $zero, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = 0;
    // 0x80171790: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x80171794: blez        $t2, L_801717F8
    if (SIGNED(ctx->r10) <= 0) {
        // 0x80171798: nop
    
            goto L_801717F8;
    }
    // 0x80171798: nop

L_8017179C:
    // 0x8017179C: lw          $t3, 0x70($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X70);
    // 0x801717A0: lw          $t4, 0x6C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X6C);
    // 0x801717A4: addu        $t6, $t3, $t4
    ctx->r14 = ADD32(ctx->r11, ctx->r12);
    // 0x801717A8: jal         0x801715E4
    // 0x801717AC: lbu         $a0, 0x0($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X0);
    func_801715E4_02FC30(rdram, ctx);
        goto after_1;
    // 0x801717AC: lbu         $a0, 0x0($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X0);
    after_1:
    // 0x801717B0: lwc1        $f6, 0x94($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X94);
    // 0x801717B4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x801717B8: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801717BC: mul.s       $f8, $f20, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f6.fl);
    // 0x801717C0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801717C4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801717C8: addiu       $t7, $t7, -0x3FA8
    ctx->r15 = ADD32(ctx->r15, -0X3FA8);
    // 0x801717CC: lwc1        $f18, 0x0($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0X0);
    // 0x801717D0: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801717D4: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x801717D8: swc1        $f4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f4.u32l;
    // 0x801717DC: lw          $t9, 0x68($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X68);
    // 0x801717E0: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
    // 0x801717E4: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x801717E8: addiu       $t5, $t8, 0x1
    ctx->r13 = ADD32(ctx->r24, 0X1);
    // 0x801717EC: slt         $at, $t5, $t0
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x801717F0: bne         $at, $zero, L_8017179C
    if (ctx->r1 != 0) {
        // 0x801717F4: sw          $t5, 0x6C($sp)
        MEM_W(0X6C, ctx->r29) = ctx->r13;
            goto L_8017179C;
    }
    // 0x801717F4: sw          $t5, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r13;
L_801717F8:
    // 0x801717F8: lw          $t1, 0x68($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X68);
    // 0x801717FC: lw          $t2, 0x70($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X70);
    // 0x80171800: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80171804: jal         0x801715E4
    // 0x80171808: lbu         $a0, -0x1($t3)
    ctx->r4 = MEM_BU(ctx->r11, -0X1);
    func_801715E4_02FC30(rdram, ctx);
        goto after_2;
    // 0x80171808: lbu         $a0, -0x1($t3)
    ctx->r4 = MEM_BU(ctx->r11, -0X1);
    after_2:
    // 0x8017180C: lwc1        $f6, 0x94($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X94);
    // 0x80171810: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80171814: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80171818: mul.s       $f8, $f20, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f6.fl);
    // 0x8017181C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80171820: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80171824: addiu       $t4, $t4, -0x3FA8
    ctx->r12 = ADD32(ctx->r12, -0X3FA8);
    // 0x80171828: lwc1        $f16, 0x0($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X0);
    // 0x8017182C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80171830: addiu       $t6, $t6, -0x3FA8
    ctx->r14 = ADD32(ctx->r14, -0X3FA8);
    // 0x80171834: div.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80171838: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8017183C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80171840: addiu       $t7, $t7, -0x3FA8
    ctx->r15 = ADD32(ctx->r15, -0X3FA8);
    // 0x80171844: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80171848: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8017184C: swc1        $f4, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f4.u32l;
    // 0x80171850: lwc1        $f6, 0x0($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X0);
    // 0x80171854: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80171858: swc1        $f10, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f10.u32l;
    // 0x8017185C: swc1        $f16, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f16.u32l;
    // 0x80171860: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x80171864: sw          $zero, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = 0;
    // 0x80171868: blez        $t8, L_801719AC
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8017186C: nop
    
            goto L_801719AC;
    }
    // 0x8017186C: nop

L_80171870:
    // 0x80171870: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x80171874: lw          $t5, 0x6C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X6C);
    // 0x80171878: addu        $t0, $t9, $t5
    ctx->r8 = ADD32(ctx->r25, ctx->r13);
    // 0x8017187C: jal         0x801715E4
    // 0x80171880: lbu         $a0, 0x0($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X0);
    func_801715E4_02FC30(rdram, ctx);
        goto after_3;
    // 0x80171880: lbu         $a0, 0x0($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X0);
    after_3:
    // 0x80171884: lwc1        $f18, 0x94($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X94);
    // 0x80171888: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8017188C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80171890: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80171894: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80171898: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017189C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x801718A0: addiu       $t1, $t1, -0x3FA8
    ctx->r9 = ADD32(ctx->r9, -0X3FA8);
    // 0x801718A4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x801718A8: addiu       $t2, $t2, -0x3FA8
    ctx->r10 = ADD32(ctx->r10, -0X3FA8);
    // 0x801718AC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801718B0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801718B4: addiu       $t9, $t9, -0x3FA8
    ctx->r25 = ADD32(ctx->r25, -0X3FA8);
    // 0x801718B8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x801718BC: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x801718C0: swc1        $f16, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f16.u32l;
    // 0x801718C4: lwc1        $f18, 0x0($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X0);
    // 0x801718C8: lwc1        $f4, 0x8($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X8);
    // 0x801718CC: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801718D0: swc1        $f6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f6.u32l;
    // 0x801718D4: lw          $t4, 0x6C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X6C);
    // 0x801718D8: lw          $t3, 0x70($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X70);
    // 0x801718DC: lbu         $t8, 0x87($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X87);
    // 0x801718E0: lbu         $t7, 0x83($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X83);
    // 0x801718E4: addu        $t6, $t3, $t4
    ctx->r14 = ADD32(ctx->r11, ctx->r12);
    // 0x801718E8: lbu         $a0, 0x0($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X0);
    // 0x801718EC: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x801718F0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801718F4: lwc1        $f10, 0x4($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X4);
    // 0x801718F8: lwc1        $f8, 0x88($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X88);
    // 0x801718FC: lwc1        $f18, 0x0($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X0);
    // 0x80171900: lwc1        $f6, 0x8C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x80171904: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80171908: lwc1        $f10, 0x94($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8017190C: lwc1        $f8, 0x90($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X90);
    // 0x80171910: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x80171914: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80171918: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8017191C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80171920: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x80171924: div.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80171928: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x8017192C: lwc1        $f4, 0x98($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X98);
    // 0x80171930: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80171934: lwc1        $f10, 0x9C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x80171938: lh          $t5, 0xAE($sp)
    ctx->r13 = MEM_H(ctx->r29, 0XAE);
    // 0x8017193C: lbu         $a3, 0x7F($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X7F);
    // 0x80171940: lbu         $a2, 0x7B($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X7B);
    // 0x80171944: lbu         $a1, 0x77($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X77);
    // 0x80171948: sw          $t5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r13;
    // 0x8017194C: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80171950: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x80171954: lwc1        $f6, 0xA4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x80171958: lwc1        $f4, 0xA0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x8017195C: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    // 0x80171960: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x80171964: div.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80171968: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x8017196C: lwc1        $f8, 0xA8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x80171970: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    // 0x80171974: jal         0x801707E8
    // 0x80171978: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    func_801707E8_02FC30(rdram, ctx);
        goto after_4;
    // 0x80171978: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    after_4:
    // 0x8017197C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80171980: addiu       $t0, $t0, -0x3FA8
    ctx->r8 = ADD32(ctx->r8, -0X3FA8);
    // 0x80171984: lwc1        $f10, 0x0($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80171988: lwc1        $f18, 0x8($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X8);
    // 0x8017198C: add.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80171990: swc1        $f16, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f16.u32l;
    // 0x80171994: lw          $t1, 0x6C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X6C);
    // 0x80171998: lw          $t3, 0x68($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X68);
    // 0x8017199C: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x801719A0: slt         $at, $t2, $t3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x801719A4: bne         $at, $zero, L_80171870
    if (ctx->r1 != 0) {
        // 0x801719A8: sw          $t2, 0x6C($sp)
        MEM_W(0X6C, ctx->r29) = ctx->r10;
            goto L_80171870;
    }
    // 0x801719A8: sw          $t2, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r10;
L_801719AC:
    // 0x801719AC: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x801719B0: ldc1        $f20, 0x48($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X48);
    // 0x801719B4: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x801719B8: jr          $ra
    // 0x801719BC: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x801719BC: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_801719C0_02FC30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801719C0: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x801719C4: lbu         $t6, 0x73($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X73);
    // 0x801719C8: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x801719CC: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x801719D0: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x801719D4: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x801719D8: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    // 0x801719DC: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x801719E0: beq         $t6, $zero, L_80171C74
    if (ctx->r14 == 0) {
        // 0x801719E4: sdc1        $f20, 0x38($sp)
        CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X38, ctx->r29);
            goto L_80171C74;
    }
    // 0x801719E4: sdc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X38, ctx->r29);
    // 0x801719E8: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x801719EC: lw          $t7, -0x4514($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4514);
    // 0x801719F0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x801719F4: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x801719F8: sw          $t7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r15;
    // 0x801719FC: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x80171A00: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x80171A04: sw          $t8, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r24;
    // 0x80171A08: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80171A0C: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x80171A10: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80171A14: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x80171A18: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x80171A1C: sw          $zero, 0x58($sp)
    MEM_W(0X58, ctx->r29) = 0;
    // 0x80171A20: lbu         $s0, 0x0($t2)
    ctx->r16 = MEM_BU(ctx->r10, 0X0);
    // 0x80171A24: sw          $t4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r12;
    // 0x80171A28: sltu        $t3, $zero, $s0
    ctx->r11 = 0 < ctx->r16 ? 1 : 0;
    // 0x80171A2C: or          $s0, $t3, $zero
    ctx->r16 = ctx->r11 | 0;
    // 0x80171A30: beq         $s0, $zero, L_80171A60
    if (ctx->r16 == 0) {
        // 0x80171A34: nop
    
            goto L_80171A60;
    }
    // 0x80171A34: nop

L_80171A38:
    // 0x80171A38: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    // 0x80171A3C: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x80171A40: addiu       $t9, $t5, 0x1
    ctx->r25 = ADD32(ctx->r13, 0X1);
    // 0x80171A44: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80171A48: lbu         $s0, 0x0($t7)
    ctx->r16 = MEM_BU(ctx->r15, 0X0);
    // 0x80171A4C: sw          $t9, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r25;
    // 0x80171A50: sltu        $t8, $zero, $s0
    ctx->r24 = 0 < ctx->r16 ? 1 : 0;
    // 0x80171A54: or          $s0, $t8, $zero
    ctx->r16 = ctx->r24 | 0;
    // 0x80171A58: bne         $s0, $zero, L_80171A38
    if (ctx->r16 != 0) {
        // 0x80171A5C: nop
    
            goto L_80171A38;
    }
    // 0x80171A5C: nop

L_80171A60:
    // 0x80171A60: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80171A64: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80171A68: addiu       $t0, $t0, -0x3FA8
    ctx->r8 = ADD32(ctx->r8, -0X3FA8);
    // 0x80171A6C: swc1        $f4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f4.u32l;
    // 0x80171A70: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x80171A74: sw          $zero, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = 0;
    // 0x80171A78: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x80171A7C: blez        $t2, L_80171AE0
    if (SIGNED(ctx->r10) <= 0) {
        // 0x80171A80: nop
    
            goto L_80171AE0;
    }
    // 0x80171A80: nop

L_80171A84:
    // 0x80171A84: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
    // 0x80171A88: lw          $t4, 0x5C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X5C);
    // 0x80171A8C: addu        $t6, $t3, $t4
    ctx->r14 = ADD32(ctx->r11, ctx->r12);
    // 0x80171A90: jal         0x801715E4
    // 0x80171A94: lbu         $a0, 0x0($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X0);
    func_801715E4_02FC30(rdram, ctx);
        goto after_0;
    // 0x80171A94: lbu         $a0, 0x0($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X0);
    after_0:
    // 0x80171A98: lwc1        $f6, 0x84($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80171A9C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80171AA0: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80171AA4: mul.s       $f8, $f20, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f6.fl);
    // 0x80171AA8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80171AAC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80171AB0: addiu       $t7, $t7, -0x3FA8
    ctx->r15 = ADD32(ctx->r15, -0X3FA8);
    // 0x80171AB4: lwc1        $f18, 0x0($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0X0);
    // 0x80171AB8: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80171ABC: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80171AC0: swc1        $f4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f4.u32l;
    // 0x80171AC4: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x80171AC8: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x80171ACC: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x80171AD0: addiu       $t5, $t8, 0x1
    ctx->r13 = ADD32(ctx->r24, 0X1);
    // 0x80171AD4: slt         $at, $t5, $t0
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80171AD8: bne         $at, $zero, L_80171A84
    if (ctx->r1 != 0) {
        // 0x80171ADC: sw          $t5, 0x5C($sp)
        MEM_W(0X5C, ctx->r29) = ctx->r13;
            goto L_80171A84;
    }
    // 0x80171ADC: sw          $t5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r13;
L_80171AE0:
    // 0x80171AE0: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x80171AE4: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x80171AE8: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80171AEC: jal         0x801715E4
    // 0x80171AF0: lbu         $a0, -0x1($t3)
    ctx->r4 = MEM_BU(ctx->r11, -0X1);
    func_801715E4_02FC30(rdram, ctx);
        goto after_1;
    // 0x80171AF0: lbu         $a0, -0x1($t3)
    ctx->r4 = MEM_BU(ctx->r11, -0X1);
    after_1:
    // 0x80171AF4: lwc1        $f6, 0x84($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80171AF8: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80171AFC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80171B00: mul.s       $f8, $f20, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f6.fl);
    // 0x80171B04: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80171B08: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80171B0C: addiu       $t4, $t4, -0x3FA8
    ctx->r12 = ADD32(ctx->r12, -0X3FA8);
    // 0x80171B10: lwc1        $f16, 0x0($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X0);
    // 0x80171B14: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80171B18: addiu       $t6, $t6, -0x3FA8
    ctx->r14 = ADD32(ctx->r14, -0X3FA8);
    // 0x80171B1C: div.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80171B20: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80171B24: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80171B28: addiu       $t7, $t7, -0x3FA8
    ctx->r15 = ADD32(ctx->r15, -0X3FA8);
    // 0x80171B2C: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80171B30: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80171B34: swc1        $f4, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f4.u32l;
    // 0x80171B38: lwc1        $f6, 0x0($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X0);
    // 0x80171B3C: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80171B40: swc1        $f10, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f10.u32l;
    // 0x80171B44: swc1        $f16, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f16.u32l;
    // 0x80171B48: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x80171B4C: sw          $zero, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = 0;
    // 0x80171B50: blez        $t8, L_80171C74
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80171B54: nop
    
            goto L_80171C74;
    }
    // 0x80171B54: nop

L_80171B58:
    // 0x80171B58: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x80171B5C: lw          $t5, 0x5C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X5C);
    // 0x80171B60: addu        $t0, $t9, $t5
    ctx->r8 = ADD32(ctx->r25, ctx->r13);
    // 0x80171B64: jal         0x801715E4
    // 0x80171B68: lbu         $a0, 0x0($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X0);
    func_801715E4_02FC30(rdram, ctx);
        goto after_2;
    // 0x80171B68: lbu         $a0, 0x0($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X0);
    after_2:
    // 0x80171B6C: lwc1        $f18, 0x84($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80171B70: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80171B74: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80171B78: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80171B7C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80171B80: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80171B84: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80171B88: addiu       $t1, $t1, -0x3FA8
    ctx->r9 = ADD32(ctx->r9, -0X3FA8);
    // 0x80171B8C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80171B90: addiu       $t2, $t2, -0x3FA8
    ctx->r10 = ADD32(ctx->r10, -0X3FA8);
    // 0x80171B94: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80171B98: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80171B9C: addiu       $t9, $t9, -0x3FA8
    ctx->r25 = ADD32(ctx->r25, -0X3FA8);
    // 0x80171BA0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80171BA4: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80171BA8: swc1        $f16, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f16.u32l;
    // 0x80171BAC: lwc1        $f18, 0x0($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X0);
    // 0x80171BB0: lwc1        $f4, 0x8($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X8);
    // 0x80171BB4: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80171BB8: swc1        $f6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f6.u32l;
    // 0x80171BBC: lw          $t4, 0x5C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X5C);
    // 0x80171BC0: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
    // 0x80171BC4: lbu         $t8, 0x77($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X77);
    // 0x80171BC8: lbu         $t7, 0x73($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X73);
    // 0x80171BCC: addu        $t6, $t3, $t4
    ctx->r14 = ADD32(ctx->r11, ctx->r12);
    // 0x80171BD0: lbu         $a0, 0x0($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X0);
    // 0x80171BD4: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80171BD8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80171BDC: lwc1        $f10, 0x4($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X4);
    // 0x80171BE0: lwc1        $f8, 0x78($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80171BE4: lwc1        $f18, 0x0($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X0);
    // 0x80171BE8: lwc1        $f6, 0x7C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80171BEC: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80171BF0: lwc1        $f10, 0x84($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80171BF4: lwc1        $f8, 0x80($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80171BF8: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x80171BFC: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80171C00: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80171C04: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80171C08: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x80171C0C: div.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80171C10: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x80171C14: lwc1        $f4, 0x88($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X88);
    // 0x80171C18: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80171C1C: lwc1        $f10, 0x8C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x80171C20: lbu         $a3, 0x6F($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X6F);
    // 0x80171C24: lbu         $a2, 0x6B($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X6B);
    // 0x80171C28: lbu         $a1, 0x67($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X67);
    // 0x80171C2C: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80171C30: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x80171C34: div.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80171C38: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x80171C3C: jal         0x8017151C
    // 0x80171C40: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    func_8017151C_02FC30(rdram, ctx);
        goto after_3;
    // 0x80171C40: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    after_3:
    // 0x80171C44: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80171C48: addiu       $t5, $t5, -0x3FA8
    ctx->r13 = ADD32(ctx->r13, -0X3FA8);
    // 0x80171C4C: lwc1        $f4, 0x0($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X0);
    // 0x80171C50: lwc1        $f6, 0x8($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X8);
    // 0x80171C54: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80171C58: swc1        $f8, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f8.u32l;
    // 0x80171C5C: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x80171C60: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x80171C64: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80171C68: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80171C6C: bne         $at, $zero, L_80171B58
    if (ctx->r1 != 0) {
        // 0x80171C70: sw          $t1, 0x5C($sp)
        MEM_W(0X5C, ctx->r29) = ctx->r9;
            goto L_80171B58;
    }
    // 0x80171C70: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
L_80171C74:
    // 0x80171C74: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80171C78: ldc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X38);
    // 0x80171C7C: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x80171C80: jr          $ra
    // 0x80171C84: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80171C84: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_80171C88_02FC30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80171C88: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80171C8C: lbu         $t6, 0x83($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X83);
    // 0x80171C90: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80171C94: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x80171C98: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x80171C9C: sw          $a2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r6;
    // 0x80171CA0: sw          $a3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r7;
    // 0x80171CA4: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x80171CA8: beq         $t6, $zero, L_80171F7C
    if (ctx->r14 == 0) {
        // 0x80171CAC: sdc1        $f20, 0x48($sp)
        CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X48, ctx->r29);
            goto L_80171F7C;
    }
    // 0x80171CAC: sdc1        $f20, 0x48($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X48, ctx->r29);
    // 0x80171CB0: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x80171CB4: lw          $t7, -0x4514($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4514);
    // 0x80171CB8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80171CBC: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x80171CC0: sw          $t7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r15;
    // 0x80171CC4: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x80171CC8: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x80171CCC: sw          $t8, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r24;
    // 0x80171CD0: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80171CD4: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x80171CD8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80171CDC: addiu       $a0, $a0, -0x3F68
    ctx->r4 = ADD32(ctx->r4, -0X3F68);
    // 0x80171CE0: addiu       $a0, $a0, 0xC0
    ctx->r4 = ADD32(ctx->r4, 0XC0);
    // 0x80171CE4: jal         0x800D6D20
    // 0x80171CE8: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    guMtxIdentF_recomp(rdram, ctx);
        goto after_0;
    // 0x80171CE8: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    after_0:
    // 0x80171CEC: lwc1        $f4, 0x88($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X88);
    // 0x80171CF0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80171CF4: addiu       $t2, $t2, -0x3F68
    ctx->r10 = ADD32(ctx->r10, -0X3F68);
    // 0x80171CF8: swc1        $f4, 0xD0($t2)
    MEM_W(0XD0, ctx->r10) = ctx->f4.u32l;
    // 0x80171CFC: lw          $t3, 0x70($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X70);
    // 0x80171D00: sw          $zero, 0x68($sp)
    MEM_W(0X68, ctx->r29) = 0;
    // 0x80171D04: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80171D08: lbu         $s0, 0x0($t3)
    ctx->r16 = MEM_BU(ctx->r11, 0X0);
    // 0x80171D0C: sw          $t5, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r13;
    // 0x80171D10: sltu        $t4, $zero, $s0
    ctx->r12 = 0 < ctx->r16 ? 1 : 0;
    // 0x80171D14: or          $s0, $t4, $zero
    ctx->r16 = ctx->r12 | 0;
    // 0x80171D18: beq         $s0, $zero, L_80171D48
    if (ctx->r16 == 0) {
        // 0x80171D1C: nop
    
            goto L_80171D48;
    }
    // 0x80171D1C: nop

L_80171D20:
    // 0x80171D20: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x80171D24: lw          $t7, 0x70($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X70);
    // 0x80171D28: addiu       $t0, $t6, 0x1
    ctx->r8 = ADD32(ctx->r14, 0X1);
    // 0x80171D2C: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80171D30: lbu         $s0, 0x0($t8)
    ctx->r16 = MEM_BU(ctx->r24, 0X0);
    // 0x80171D34: sw          $t0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r8;
    // 0x80171D38: sltu        $t9, $zero, $s0
    ctx->r25 = 0 < ctx->r16 ? 1 : 0;
    // 0x80171D3C: or          $s0, $t9, $zero
    ctx->r16 = ctx->r25 | 0;
    // 0x80171D40: bne         $s0, $zero, L_80171D20
    if (ctx->r16 != 0) {
        // 0x80171D44: nop
    
            goto L_80171D20;
    }
    // 0x80171D44: nop

L_80171D48:
    // 0x80171D48: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80171D4C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80171D50: addiu       $t1, $t1, -0x3FA8
    ctx->r9 = ADD32(ctx->r9, -0X3FA8);
    // 0x80171D54: swc1        $f6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f6.u32l;
    // 0x80171D58: lw          $t2, 0x68($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X68);
    // 0x80171D5C: sw          $zero, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = 0;
    // 0x80171D60: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x80171D64: blez        $t3, L_80171DC8
    if (SIGNED(ctx->r11) <= 0) {
        // 0x80171D68: nop
    
            goto L_80171DC8;
    }
    // 0x80171D68: nop

L_80171D6C:
    // 0x80171D6C: lw          $t4, 0x70($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X70);
    // 0x80171D70: lw          $t5, 0x6C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X6C);
    // 0x80171D74: addu        $t7, $t4, $t5
    ctx->r15 = ADD32(ctx->r12, ctx->r13);
    // 0x80171D78: jal         0x801715E4
    // 0x80171D7C: lbu         $a0, 0x0($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X0);
    func_801715E4_02FC30(rdram, ctx);
        goto after_1;
    // 0x80171D7C: lbu         $a0, 0x0($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X0);
    after_1:
    // 0x80171D80: lwc1        $f8, 0x98($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X98);
    // 0x80171D84: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80171D88: lui         $at, 0x4090
    ctx->r1 = S32(0X4090 << 16);
    // 0x80171D8C: mul.s       $f10, $f20, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f8.fl);
    // 0x80171D90: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80171D94: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80171D98: addiu       $t8, $t8, -0x3FA8
    ctx->r24 = ADD32(ctx->r24, -0X3FA8);
    // 0x80171D9C: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    // 0x80171DA0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80171DA4: add.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x80171DA8: swc1        $f6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f6.u32l;
    // 0x80171DAC: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
    // 0x80171DB0: lw          $t9, 0x6C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X6C);
    // 0x80171DB4: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x80171DB8: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x80171DBC: slt         $at, $t6, $t1
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80171DC0: bne         $at, $zero, L_80171D6C
    if (ctx->r1 != 0) {
        // 0x80171DC4: sw          $t6, 0x6C($sp)
        MEM_W(0X6C, ctx->r29) = ctx->r14;
            goto L_80171D6C;
    }
    // 0x80171DC4: sw          $t6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r14;
L_80171DC8:
    // 0x80171DC8: lw          $t2, 0x68($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X68);
    // 0x80171DCC: lw          $t3, 0x70($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X70);
    // 0x80171DD0: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80171DD4: jal         0x801715E4
    // 0x80171DD8: lbu         $a0, -0x1($t4)
    ctx->r4 = MEM_BU(ctx->r12, -0X1);
    func_801715E4_02FC30(rdram, ctx);
        goto after_2;
    // 0x80171DD8: lbu         $a0, -0x1($t4)
    ctx->r4 = MEM_BU(ctx->r12, -0X1);
    after_2:
    // 0x80171DDC: lwc1        $f8, 0x98($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X98);
    // 0x80171DE0: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80171DE4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80171DE8: mul.s       $f10, $f20, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f8.fl);
    // 0x80171DEC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80171DF0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80171DF4: addiu       $t5, $t5, -0x3FA8
    ctx->r13 = ADD32(ctx->r13, -0X3FA8);
    // 0x80171DF8: lwc1        $f18, 0x0($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X0);
    // 0x80171DFC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80171E00: addiu       $t7, $t7, -0x3FA8
    ctx->r15 = ADD32(ctx->r15, -0X3FA8);
    // 0x80171E04: div.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80171E08: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80171E0C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80171E10: addiu       $t8, $t8, -0x3FA8
    ctx->r24 = ADD32(ctx->r24, -0X3FA8);
    // 0x80171E14: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80171E18: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80171E1C: swc1        $f6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f6.u32l;
    // 0x80171E20: lwc1        $f8, 0x0($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X0);
    // 0x80171E24: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80171E28: swc1        $f16, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f16.u32l;
    // 0x80171E2C: swc1        $f18, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f18.u32l;
    // 0x80171E30: lw          $t9, 0x68($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X68);
    // 0x80171E34: sw          $zero, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = 0;
    // 0x80171E38: blez        $t9, L_80171F7C
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80171E3C: nop
    
            goto L_80171F7C;
    }
    // 0x80171E3C: nop

L_80171E40:
    // 0x80171E40: lw          $t0, 0x70($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X70);
    // 0x80171E44: lw          $t6, 0x6C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X6C);
    // 0x80171E48: addu        $t1, $t0, $t6
    ctx->r9 = ADD32(ctx->r8, ctx->r14);
    // 0x80171E4C: jal         0x801715E4
    // 0x80171E50: lbu         $a0, 0x0($t1)
    ctx->r4 = MEM_BU(ctx->r9, 0X0);
    func_801715E4_02FC30(rdram, ctx);
        goto after_3;
    // 0x80171E50: lbu         $a0, 0x0($t1)
    ctx->r4 = MEM_BU(ctx->r9, 0X0);
    after_3:
    // 0x80171E54: lwc1        $f4, 0x98($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X98);
    // 0x80171E58: lui         $at, 0x4090
    ctx->r1 = S32(0X4090 << 16);
    // 0x80171E5C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80171E60: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80171E64: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80171E68: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80171E6C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80171E70: addiu       $t2, $t2, -0x3FA8
    ctx->r10 = ADD32(ctx->r10, -0X3FA8);
    // 0x80171E74: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80171E78: addiu       $t3, $t3, -0x3FA8
    ctx->r11 = ADD32(ctx->r11, -0X3FA8);
    // 0x80171E7C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80171E80: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80171E84: addiu       $t0, $t0, -0x3FA8
    ctx->r8 = ADD32(ctx->r8, -0X3FA8);
    // 0x80171E88: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80171E8C: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80171E90: swc1        $f18, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->f18.u32l;
    // 0x80171E94: lwc1        $f4, 0x0($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X0);
    // 0x80171E98: lwc1        $f6, 0x8($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X8);
    // 0x80171E9C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80171EA0: swc1        $f8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f8.u32l;
    // 0x80171EA4: lw          $t5, 0x6C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X6C);
    // 0x80171EA8: lw          $t4, 0x70($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X70);
    // 0x80171EAC: lbu         $t9, 0x87($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X87);
    // 0x80171EB0: lbu         $t8, 0x83($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X83);
    // 0x80171EB4: addu        $t7, $t4, $t5
    ctx->r15 = ADD32(ctx->r12, ctx->r13);
    // 0x80171EB8: lbu         $a0, 0x0($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X0);
    // 0x80171EBC: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80171EC0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80171EC4: lwc1        $f16, 0x4($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X4);
    // 0x80171EC8: lwc1        $f10, 0x8C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x80171ECC: lwc1        $f4, 0x0($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80171ED0: lwc1        $f8, 0x90($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X90);
    // 0x80171ED4: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80171ED8: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
    // 0x80171EDC: lwc1        $f10, 0x94($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X94);
    // 0x80171EE0: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x80171EE4: add.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x80171EE8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80171EEC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80171EF0: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    // 0x80171EF4: div.s       $f18, $f16, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f4.fl);
    // 0x80171EF8: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x80171EFC: lwc1        $f6, 0x9C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x80171F00: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80171F04: lwc1        $f16, 0xA0($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80171F08: lh          $t6, 0xB2($sp)
    ctx->r14 = MEM_H(ctx->r29, 0XB2);
    // 0x80171F0C: lbu         $a3, 0x7F($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X7F);
    // 0x80171F10: lbu         $a2, 0x7B($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X7B);
    // 0x80171F14: lbu         $a1, 0x77($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X77);
    // 0x80171F18: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    // 0x80171F1C: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80171F20: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    // 0x80171F24: lwc1        $f8, 0xA8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x80171F28: lwc1        $f6, 0xA4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x80171F2C: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    // 0x80171F30: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    // 0x80171F34: div.s       $f18, $f16, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f4.fl);
    // 0x80171F38: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x80171F3C: lwc1        $f10, 0xAC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x80171F40: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    // 0x80171F44: jal         0x80170EA0
    // 0x80171F48: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    func_80170EA0_02FC30(rdram, ctx);
        goto after_4;
    // 0x80171F48: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    after_4:
    // 0x80171F4C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80171F50: addiu       $t1, $t1, -0x3FA8
    ctx->r9 = ADD32(ctx->r9, -0X3FA8);
    // 0x80171F54: lwc1        $f16, 0x0($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X0);
    // 0x80171F58: lwc1        $f4, 0x8($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X8);
    // 0x80171F5C: add.s       $f18, $f16, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x80171F60: swc1        $f18, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f18.u32l;
    // 0x80171F64: lw          $t2, 0x6C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X6C);
    // 0x80171F68: lw          $t4, 0x68($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X68);
    // 0x80171F6C: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80171F70: slt         $at, $t3, $t4
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80171F74: bne         $at, $zero, L_80171E40
    if (ctx->r1 != 0) {
        // 0x80171F78: sw          $t3, 0x6C($sp)
        MEM_W(0X6C, ctx->r29) = ctx->r11;
            goto L_80171E40;
    }
    // 0x80171F78: sw          $t3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r11;
L_80171F7C:
    // 0x80171F7C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x80171F80: ldc1        $f20, 0x48($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X48);
    // 0x80171F84: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x80171F88: jr          $ra
    // 0x80171F8C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80171F8C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_80171F90_02FC30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80171F90: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80171F94: lbu         $t6, 0x7B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X7B);
    // 0x80171F98: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80171F9C: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x80171FA0: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x80171FA4: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x80171FA8: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    // 0x80171FAC: beq         $t6, $zero, L_80172250
    if (ctx->r14 == 0) {
        // 0x80171FB0: sw          $s0, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r16;
            goto L_80172250;
    }
    // 0x80171FB0: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x80171FB4: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x80171FB8: lw          $t7, -0x4514($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4514);
    // 0x80171FBC: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80171FC0: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x80171FC4: sw          $t7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r15;
    // 0x80171FC8: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x80171FCC: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x80171FD0: sw          $t8, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r24;
    // 0x80171FD4: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80171FD8: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x80171FDC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80171FE0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80171FE4: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x80171FE8: lwc1        $f6, 0x8C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x80171FEC: lwc1        $f4, 0x2684($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X2684);
    // 0x80171FF0: addiu       $t2, $t2, -0x3FA8
    ctx->r10 = ADD32(ctx->r10, -0X3FA8);
    // 0x80171FF4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80171FF8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80171FFC: swc1        $f8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f8.u32l;
    // 0x80172000: lw          $t3, 0x68($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X68);
    // 0x80172004: sw          $zero, 0x60($sp)
    MEM_W(0X60, ctx->r29) = 0;
    // 0x80172008: lbu         $s0, 0x0($t3)
    ctx->r16 = MEM_BU(ctx->r11, 0X0);
    // 0x8017200C: sw          $t5, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r13;
    // 0x80172010: sltu        $t4, $zero, $s0
    ctx->r12 = 0 < ctx->r16 ? 1 : 0;
    // 0x80172014: or          $s0, $t4, $zero
    ctx->r16 = ctx->r12 | 0;
    // 0x80172018: beq         $s0, $zero, L_80172048
    if (ctx->r16 == 0) {
        // 0x8017201C: nop
    
            goto L_80172048;
    }
    // 0x8017201C: nop

L_80172020:
    // 0x80172020: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x80172024: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x80172028: addiu       $t0, $t6, 0x1
    ctx->r8 = ADD32(ctx->r14, 0X1);
    // 0x8017202C: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80172030: lbu         $s0, 0x0($t8)
    ctx->r16 = MEM_BU(ctx->r24, 0X0);
    // 0x80172034: sw          $t0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r8;
    // 0x80172038: sltu        $t9, $zero, $s0
    ctx->r25 = 0 < ctx->r16 ? 1 : 0;
    // 0x8017203C: or          $s0, $t9, $zero
    ctx->r16 = ctx->r25 | 0;
    // 0x80172040: bne         $s0, $zero, L_80172020
    if (ctx->r16 != 0) {
        // 0x80172044: nop
    
            goto L_80172020;
    }
    // 0x80172044: nop

L_80172048:
    // 0x80172048: lw          $t1, 0x60($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X60);
    // 0x8017204C: sltiu       $s0, $t1, 0x1
    ctx->r16 = ctx->r9 < 0X1 ? 1 : 0;
    // 0x80172050: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x80172054: bne         $s0, $zero, L_80172250
    if (ctx->r16 != 0) {
        // 0x80172058: sw          $t2, 0x60($sp)
        MEM_W(0X60, ctx->r29) = ctx->r10;
            goto L_80172250;
    }
    // 0x80172058: sw          $t2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r10;
    // 0x8017205C: lw          $t4, 0x60($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X60);
    // 0x80172060: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80172064: addiu       $t3, $t3, -0x3FA8
    ctx->r11 = ADD32(ctx->r11, -0X3FA8);
    // 0x80172068: sra         $t5, $t4, 1
    ctx->r13 = S32(SIGNED(ctx->r12) >> 1);
    // 0x8017206C: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x80172070: lwc1        $f10, 0x0($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X0);
    // 0x80172074: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80172078: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8017207C: swc1        $f4, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->f4.u32l;
    // 0x80172080: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x80172084: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80172088: bne         $t8, $zero, L_801720B4
    if (ctx->r24 != 0) {
        // 0x8017208C: nop
    
            goto L_801720B4;
    }
    // 0x8017208C: nop

    // 0x80172090: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80172094: addiu       $t9, $t9, -0x3FA8
    ctx->r25 = ADD32(ctx->r25, -0X3FA8);
    // 0x80172098: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8017209C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801720A0: lwc1        $f6, 0x0($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X0);
    // 0x801720A4: lwc1        $f10, 0x4($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X4);
    // 0x801720A8: div.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801720AC: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x801720B0: swc1        $f18, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f18.u32l;
L_801720B4:
    // 0x801720B4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801720B8: lwc1        $f4, 0x2688($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X2688);
    // 0x801720BC: lwc1        $f6, 0x98($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X98);
    // 0x801720C0: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x801720C4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801720C8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801720CC: jal         0x800D68F0
    // 0x801720D0: div.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    sinf_recomp(rdram, ctx);
        goto after_0;
    // 0x801720D0: div.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    after_0:
    // 0x801720D4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801720D8: lwc1        $f16, 0x268C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X268C);
    // 0x801720DC: lwc1        $f18, 0x98($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X98);
    // 0x801720E0: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x801720E4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801720E8: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x801720EC: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x801720F0: jal         0x800D6AB0
    // 0x801720F4: div.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    __cosf_recomp(rdram, ctx);
        goto after_1;
    // 0x801720F4: div.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    after_1:
    // 0x801720F8: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x801720FC: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x80172100: sw          $zero, 0x64($sp)
    MEM_W(0X64, ctx->r29) = 0;
    // 0x80172104: blez        $t6, L_80172250
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80172108: nop
    
            goto L_80172250;
    }
    // 0x80172108: nop

L_8017210C:
    // 0x8017210C: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x80172110: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80172114: addiu       $t0, $t0, -0x3FA8
    ctx->r8 = ADD32(ctx->r8, -0X3FA8);
    // 0x80172118: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x8017211C: lwc1        $f8, 0x0($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80172120: lwc1        $f6, 0x4($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X4);
    // 0x80172124: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80172128: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017212C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80172130: addiu       $t2, $t2, -0x3FA8
    ctx->r10 = ADD32(ctx->r10, -0X3FA8);
    // 0x80172134: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80172138: sub.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8017213C: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80172140: addiu       $t4, $t4, -0x3FA8
    ctx->r12 = ADD32(ctx->r12, -0X3FA8);
    // 0x80172144: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80172148: addiu       $t5, $t5, -0x3FA8
    ctx->r13 = ADD32(ctx->r13, -0X3FA8);
    // 0x8017214C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80172150: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80172154: addiu       $t1, $t1, -0x3FA8
    ctx->r9 = ADD32(ctx->r9, -0X3FA8);
    // 0x80172158: add.s       $f8, $f18, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x8017215C: swc1        $f8, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f8.u32l;
    // 0x80172160: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80172164: lwc1        $f16, 0x8($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X8);
    // 0x80172168: lwc1        $f18, 0x80($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X80);
    // 0x8017216C: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x80172170: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x80172174: add.s       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x80172178: swc1        $f10, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f10.u32l;
    // 0x8017217C: lwc1        $f8, 0x84($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80172180: swc1        $f8, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->f8.u32l;
    // 0x80172184: lwc1        $f16, 0x8($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0X8);
    // 0x80172188: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8017218C: lwc1        $f10, 0x88($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X88);
    // 0x80172190: neg.s       $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = -ctx->f16.fl;
    // 0x80172194: mul.s       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80172198: add.s       $f8, $f18, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x8017219C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801721A0: swc1        $f8, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->f8.u32l;
    // 0x801721A4: lwc1        $f18, 0x8C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x801721A8: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x801721AC: lw          $t3, 0x68($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X68);
    // 0x801721B0: div.s       $f8, $f18, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = DIV_S(ctx->f18.fl, ctx->f10.fl);
    // 0x801721B4: lbu         $t6, 0x7F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X7F);
    // 0x801721B8: lbu         $t9, 0x7B($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X7B);
    // 0x801721BC: addu        $t8, $t3, $t7
    ctx->r24 = ADD32(ctx->r11, ctx->r15);
    // 0x801721C0: lbu         $a0, 0x0($t8)
    ctx->r4 = MEM_BU(ctx->r24, 0X0);
    // 0x801721C4: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x801721C8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x801721CC: lwc1        $f16, 0xC($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0XC);
    // 0x801721D0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801721D4: lwc1        $f18, 0x94($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X94);
    // 0x801721D8: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x801721DC: lwc1        $f4, 0x10($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X10);
    // 0x801721E0: lwc1        $f16, 0x90($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X90);
    // 0x801721E4: lbu         $a3, 0x77($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X77);
    // 0x801721E8: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x801721EC: lwc1        $f6, 0x14($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X14);
    // 0x801721F0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801721F4: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    // 0x801721F8: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x801721FC: lbu         $a2, 0x73($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X73);
    // 0x80172200: lbu         $a1, 0x6F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X6F);
    // 0x80172204: div.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f16.fl, ctx->f4.fl);
    // 0x80172208: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x8017220C: lwc1        $f4, 0x98($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X98);
    // 0x80172210: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80172214: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x80172218: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    // 0x8017221C: div.s       $f8, $f18, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = DIV_S(ctx->f18.fl, ctx->f10.fl);
    // 0x80172220: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x80172224: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80172228: nop

    // 0x8017222C: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    // 0x80172230: jal         0x801707E8
    // 0x80172234: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    func_801707E8_02FC30(rdram, ctx);
        goto after_2;
    // 0x80172234: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x80172238: lw          $t2, 0x64($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X64);
    // 0x8017223C: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
    // 0x80172240: addiu       $t4, $t2, 0x1
    ctx->r12 = ADD32(ctx->r10, 0X1);
    // 0x80172244: slt         $at, $t4, $t5
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80172248: bne         $at, $zero, L_8017210C
    if (ctx->r1 != 0) {
        // 0x8017224C: sw          $t4, 0x64($sp)
        MEM_W(0X64, ctx->r29) = ctx->r12;
            goto L_8017210C;
    }
    // 0x8017224C: sw          $t4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r12;
L_80172250:
    // 0x80172250: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80172254: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x80172258: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x8017225C: jr          $ra
    // 0x80172260: nop

    return;
    // 0x80172260: nop

;}
RECOMP_FUNC void func_80172264_02FC30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80172264: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80172268: lbu         $t6, 0x7B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X7B);
    // 0x8017226C: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80172270: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x80172274: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x80172278: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x8017227C: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    // 0x80172280: beq         $t6, $zero, L_8017251C
    if (ctx->r14 == 0) {
        // 0x80172284: sw          $s0, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r16;
            goto L_8017251C;
    }
    // 0x80172284: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x80172288: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x8017228C: lw          $t7, -0x4514($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4514);
    // 0x80172290: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80172294: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x80172298: sw          $t7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r15;
    // 0x8017229C: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x801722A0: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x801722A4: sw          $t8, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r24;
    // 0x801722A8: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x801722AC: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x801722B0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801722B4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x801722B8: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x801722BC: lwc1        $f6, 0x8C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x801722C0: lwc1        $f4, 0x2690($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X2690);
    // 0x801722C4: addiu       $t2, $t2, -0x3FA8
    ctx->r10 = ADD32(ctx->r10, -0X3FA8);
    // 0x801722C8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801722CC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801722D0: swc1        $f8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f8.u32l;
    // 0x801722D4: lw          $t3, 0x68($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X68);
    // 0x801722D8: sw          $zero, 0x60($sp)
    MEM_W(0X60, ctx->r29) = 0;
    // 0x801722DC: lbu         $s0, 0x0($t3)
    ctx->r16 = MEM_BU(ctx->r11, 0X0);
    // 0x801722E0: sw          $t5, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r13;
    // 0x801722E4: sltu        $t4, $zero, $s0
    ctx->r12 = 0 < ctx->r16 ? 1 : 0;
    // 0x801722E8: or          $s0, $t4, $zero
    ctx->r16 = ctx->r12 | 0;
    // 0x801722EC: beq         $s0, $zero, L_8017231C
    if (ctx->r16 == 0) {
        // 0x801722F0: nop
    
            goto L_8017231C;
    }
    // 0x801722F0: nop

L_801722F4:
    // 0x801722F4: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x801722F8: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x801722FC: addiu       $t0, $t6, 0x1
    ctx->r8 = ADD32(ctx->r14, 0X1);
    // 0x80172300: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80172304: lbu         $s0, 0x0($t8)
    ctx->r16 = MEM_BU(ctx->r24, 0X0);
    // 0x80172308: sw          $t0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r8;
    // 0x8017230C: sltu        $t9, $zero, $s0
    ctx->r25 = 0 < ctx->r16 ? 1 : 0;
    // 0x80172310: or          $s0, $t9, $zero
    ctx->r16 = ctx->r25 | 0;
    // 0x80172314: bne         $s0, $zero, L_801722F4
    if (ctx->r16 != 0) {
        // 0x80172318: nop
    
            goto L_801722F4;
    }
    // 0x80172318: nop

L_8017231C:
    // 0x8017231C: lw          $t1, 0x60($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X60);
    // 0x80172320: sltiu       $s0, $t1, 0x1
    ctx->r16 = ctx->r9 < 0X1 ? 1 : 0;
    // 0x80172324: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x80172328: bne         $s0, $zero, L_8017251C
    if (ctx->r16 != 0) {
        // 0x8017232C: sw          $t2, 0x60($sp)
        MEM_W(0X60, ctx->r29) = ctx->r10;
            goto L_8017251C;
    }
    // 0x8017232C: sw          $t2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r10;
    // 0x80172330: lw          $t4, 0x60($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X60);
    // 0x80172334: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80172338: addiu       $t3, $t3, -0x3FA8
    ctx->r11 = ADD32(ctx->r11, -0X3FA8);
    // 0x8017233C: sra         $t5, $t4, 1
    ctx->r13 = S32(SIGNED(ctx->r12) >> 1);
    // 0x80172340: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x80172344: lwc1        $f10, 0x0($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X0);
    // 0x80172348: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8017234C: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80172350: swc1        $f4, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->f4.u32l;
    // 0x80172354: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x80172358: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x8017235C: bne         $t8, $zero, L_80172388
    if (ctx->r24 != 0) {
        // 0x80172360: nop
    
            goto L_80172388;
    }
    // 0x80172360: nop

    // 0x80172364: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80172368: addiu       $t9, $t9, -0x3FA8
    ctx->r25 = ADD32(ctx->r25, -0X3FA8);
    // 0x8017236C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80172370: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80172374: lwc1        $f6, 0x0($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X0);
    // 0x80172378: lwc1        $f10, 0x4($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X4);
    // 0x8017237C: div.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80172380: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80172384: swc1        $f18, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f18.u32l;
L_80172388:
    // 0x80172388: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8017238C: lwc1        $f4, 0x2694($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X2694);
    // 0x80172390: lwc1        $f6, 0x98($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X98);
    // 0x80172394: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80172398: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017239C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801723A0: jal         0x800D68F0
    // 0x801723A4: div.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    sinf_recomp(rdram, ctx);
        goto after_0;
    // 0x801723A4: div.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    after_0:
    // 0x801723A8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801723AC: lwc1        $f16, 0x2698($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X2698);
    // 0x801723B0: lwc1        $f18, 0x98($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X98);
    // 0x801723B4: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x801723B8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801723BC: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x801723C0: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x801723C4: jal         0x800D6AB0
    // 0x801723C8: div.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    __cosf_recomp(rdram, ctx);
        goto after_1;
    // 0x801723C8: div.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    after_1:
    // 0x801723CC: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x801723D0: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x801723D4: sw          $zero, 0x64($sp)
    MEM_W(0X64, ctx->r29) = 0;
    // 0x801723D8: blez        $t6, L_8017251C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x801723DC: nop
    
            goto L_8017251C;
    }
    // 0x801723DC: nop

L_801723E0:
    // 0x801723E0: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x801723E4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x801723E8: addiu       $t0, $t0, -0x3FA8
    ctx->r8 = ADD32(ctx->r8, -0X3FA8);
    // 0x801723EC: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x801723F0: lwc1        $f8, 0x0($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X0);
    // 0x801723F4: lwc1        $f6, 0x4($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X4);
    // 0x801723F8: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801723FC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80172400: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80172404: addiu       $t2, $t2, -0x3FA8
    ctx->r10 = ADD32(ctx->r10, -0X3FA8);
    // 0x80172408: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017240C: sub.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80172410: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80172414: addiu       $t4, $t4, -0x3FA8
    ctx->r12 = ADD32(ctx->r12, -0X3FA8);
    // 0x80172418: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017241C: addiu       $t5, $t5, -0x3FA8
    ctx->r13 = ADD32(ctx->r13, -0X3FA8);
    // 0x80172420: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80172424: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80172428: addiu       $t1, $t1, -0x3FA8
    ctx->r9 = ADD32(ctx->r9, -0X3FA8);
    // 0x8017242C: add.s       $f8, $f18, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x80172430: swc1        $f8, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f8.u32l;
    // 0x80172434: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80172438: lwc1        $f16, 0x8($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X8);
    // 0x8017243C: lwc1        $f18, 0x80($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80172440: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x80172444: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x80172448: add.s       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x8017244C: swc1        $f10, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f10.u32l;
    // 0x80172450: lwc1        $f16, 0x5C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80172454: lwc1        $f8, 0x8($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X8);
    // 0x80172458: lwc1        $f6, 0x84($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X84);
    // 0x8017245C: mul.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80172460: add.s       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80172464: swc1        $f18, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->f18.u32l;
    // 0x80172468: lwc1        $f10, 0x88($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8017246C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80172470: swc1        $f10, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->f10.u32l;
    // 0x80172474: lwc1        $f6, 0x8C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x80172478: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x8017247C: lw          $t3, 0x68($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X68);
    // 0x80172480: div.s       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f18.fl);
    // 0x80172484: lbu         $t6, 0x7F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X7F);
    // 0x80172488: lbu         $t9, 0x7B($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X7B);
    // 0x8017248C: addu        $t8, $t3, $t7
    ctx->r24 = ADD32(ctx->r11, ctx->r15);
    // 0x80172490: lbu         $a0, 0x0($t8)
    ctx->r4 = MEM_BU(ctx->r24, 0X0);
    // 0x80172494: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80172498: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8017249C: lwc1        $f8, 0xC($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0XC);
    // 0x801724A0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801724A4: lwc1        $f6, 0x94($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X94);
    // 0x801724A8: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x801724AC: lwc1        $f16, 0x10($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X10);
    // 0x801724B0: lwc1        $f8, 0x90($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X90);
    // 0x801724B4: lbu         $a3, 0x77($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X77);
    // 0x801724B8: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    // 0x801724BC: lwc1        $f4, 0x14($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X14);
    // 0x801724C0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801724C4: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    // 0x801724C8: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x801724CC: lbu         $a2, 0x73($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X73);
    // 0x801724D0: lbu         $a1, 0x6F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X6F);
    // 0x801724D4: div.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = DIV_S(ctx->f8.fl, ctx->f16.fl);
    // 0x801724D8: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    // 0x801724DC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801724E0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801724E4: swc1        $f16, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f16.u32l;
    // 0x801724E8: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x801724EC: div.s       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f18.fl);
    // 0x801724F0: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x801724F4: lwc1        $f4, 0x98($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X98);
    // 0x801724F8: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x801724FC: jal         0x801707E8
    // 0x80172500: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    func_801707E8_02FC30(rdram, ctx);
        goto after_2;
    // 0x80172500: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    after_2:
    // 0x80172504: lw          $t2, 0x64($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X64);
    // 0x80172508: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
    // 0x8017250C: addiu       $t4, $t2, 0x1
    ctx->r12 = ADD32(ctx->r10, 0X1);
    // 0x80172510: slt         $at, $t4, $t5
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80172514: bne         $at, $zero, L_801723E0
    if (ctx->r1 != 0) {
        // 0x80172518: sw          $t4, 0x64($sp)
        MEM_W(0X64, ctx->r29) = ctx->r12;
            goto L_801723E0;
    }
    // 0x80172518: sw          $t4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r12;
L_8017251C:
    // 0x8017251C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80172520: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x80172524: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x80172528: jr          $ra
    // 0x8017252C: nop

    return;
    // 0x8017252C: nop

;}
RECOMP_FUNC void func_8017B0C0_03D600(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017B0C0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017B0C4: sw          $zero, -0x2E50($at)
    MEM_W(-0X2E50, ctx->r1) = 0;
    // 0x8017B0C8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017B0CC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017B0D0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017B0D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017B0D8: addiu       $t6, $t6, -0x2E28
    ctx->r14 = ADD32(ctx->r14, -0X2E28);
    // 0x8017B0DC: sw          $zero, -0x2E4C($at)
    MEM_W(-0X2E4C, ctx->r1) = 0;
    // 0x8017B0E0: lbu         $t7, 0xA($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0XA);
    // 0x8017B0E4: addiu       $a0, $zero, 0x280
    ctx->r4 = ADD32(0, 0X280);
    // 0x8017B0E8: addiu       $a1, $zero, 0x1E0
    ctx->r5 = ADD32(0, 0X1E0);
    // 0x8017B0EC: andi        $t8, $t7, 0xFD
    ctx->r24 = ctx->r15 & 0XFD;
    // 0x8017B0F0: jal         0x800C30F4
    // 0x8017B0F4: sb          $t8, 0xA($t6)
    MEM_B(0XA, ctx->r14) = ctx->r24;
    func_800C30F4(rdram, ctx);
        goto after_0;
    // 0x8017B0F4: sb          $t8, 0xA($t6)
    MEM_B(0XA, ctx->r14) = ctx->r24;
    after_0:
    // 0x8017B0F8: jal         0x8017B248
    // 0x8017B0FC: nop

    func_8017B248_03D600(rdram, ctx);
        goto after_1;
    // 0x8017B0FC: nop

    after_1:
    // 0x8017B100: jal         0x800C328C
    // 0x8017B104: nop

    func_800C328C(rdram, ctx);
        goto after_2;
    // 0x8017B104: nop

    after_2:
    // 0x8017B108: jal         0x800C7FA4
    // 0x8017B10C: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    func_800C7FA4(rdram, ctx);
        goto after_3;
    // 0x8017B10C: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_3:
    // 0x8017B110: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8017B114: jal         0x800D1640
    // 0x8017B118: addiu       $a0, $a0, -0x4E90
    ctx->r4 = ADD32(ctx->r4, -0X4E90);
    func_800D1640(rdram, ctx);
        goto after_4;
    // 0x8017B118: addiu       $a0, $a0, -0x4E90
    ctx->r4 = ADD32(ctx->r4, -0X4E90);
    after_4:
L_8017B11C:
    yield_self_1ms(rdram);
    // 0x8017B11C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017B120: lw          $t9, -0x2E4C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2E4C);
    // 0x8017B124: beq         $t9, $zero, L_8017B11C
    if (ctx->r25 == 0) {
        // 0x8017B128: nop
    
            goto L_8017B11C;
    }
    // 0x8017B128: nop

    // 0x8017B12C: lui         $t0, 0x8011
    ctx->r8 = S32(0X8011 << 16);
    // 0x8017B130: lhu         $t0, -0x4530($t0)
    ctx->r8 = MEM_HU(ctx->r8, -0X4530);
    // 0x8017B134: andi        $t1, $t0, 0x2000
    ctx->r9 = ctx->r8 & 0X2000;
    // 0x8017B138: bne         $t1, $zero, L_8017B11C
    if (ctx->r9 != 0) {
        // 0x8017B13C: nop
    
            goto L_8017B11C;
    }
    // 0x8017B13C: nop

    // 0x8017B140: jal         0x800CB720
    // 0x8017B144: nop

    func_800CB720(rdram, ctx);
        goto after_5;
    // 0x8017B144: nop

    after_5:
    // 0x8017B148: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8017B14C: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8017B150: bne         $t2, $zero, L_8017B11C
    if (ctx->r10 != 0) {
        // 0x8017B154: nop
    
            goto L_8017B11C;
    }
    // 0x8017B154: nop

    // 0x8017B158: jal         0x800C6DD4
    // 0x8017B15C: nop

    func_800C6DD4(rdram, ctx);
        goto after_6;
    // 0x8017B15C: nop

    after_6:
    // 0x8017B160: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017B164: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017B168: jr          $ra
    // 0x8017B16C: nop

    return;
    // 0x8017B16C: nop

;}
RECOMP_FUNC void func_8017B170_03D600(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017B170: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017B174: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8017B178: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8017B17C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017B180: bgtz        $t6, L_8017B238
    if (SIGNED(ctx->r14) > 0) {
        // 0x8017B184: nop
    
            goto L_8017B238;
    }
    // 0x8017B184: nop

    // 0x8017B188: jal         0x800C3704
    // 0x8017B18C: nop

    func_800C3704(rdram, ctx);
        goto after_0;
    // 0x8017B18C: nop

    after_0:
    // 0x8017B190: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x8017B194: lw          $t7, -0x4514($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4514);
    // 0x8017B198: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8017B19C: lui         $t9, 0xDB06
    ctx->r25 = S32(0XDB06 << 16);
    // 0x8017B1A0: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x8017B1A4: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8017B1A8: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8017B1AC: sw          $t8, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r24;
    // 0x8017B1B0: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x8017B1B4: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8017B1B8: jal         0x800C7458
    // 0x8017B1BC: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    func_800C7458(rdram, ctx);
        goto after_1;
    // 0x8017B1BC: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    after_1:
    // 0x8017B1C0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8017B1C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8017B1C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8017B1CC: jal         0x800C25FC
    // 0x8017B1D0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800C25FC(rdram, ctx);
        goto after_2;
    // 0x8017B1D0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x8017B1D4: jal         0x800C3578
    // 0x8017B1D8: nop

    func_800C3578(rdram, ctx);
        goto after_3;
    // 0x8017B1D8: nop

    after_3:
    // 0x8017B1DC: jal         0x8017B48C
    // 0x8017B1E0: nop

    func_8017B48C_03D600(rdram, ctx);
        goto after_4;
    // 0x8017B1E0: nop

    after_4:
    // 0x8017B1E4: jal         0x8017B364
    // 0x8017B1E8: nop

    func_8017B364_03D600(rdram, ctx);
        goto after_5;
    // 0x8017B1E8: nop

    after_5:
    // 0x8017B1EC: jal         0x800C3760
    // 0x8017B1F0: nop

    func_800C3760(rdram, ctx);
        goto after_6;
    // 0x8017B1F0: nop

    after_6:
    // 0x8017B1F4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017B1F8: lw          $t2, -0x2E4C($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2E4C);
    // 0x8017B1FC: beq         $t2, $zero, L_8017B238
    if (ctx->r10 == 0) {
        // 0x8017B200: nop
    
            goto L_8017B238;
    }
    // 0x8017B200: nop

    // 0x8017B204: lui         $t3, 0x8011
    ctx->r11 = S32(0X8011 << 16);
    // 0x8017B208: lhu         $t3, -0x4530($t3)
    ctx->r11 = MEM_HU(ctx->r11, -0X4530);
    // 0x8017B20C: andi        $t4, $t3, 0x2000
    ctx->r12 = ctx->r11 & 0X2000;
    // 0x8017B210: bne         $t4, $zero, L_8017B238
    if (ctx->r12 != 0) {
        // 0x8017B214: nop
    
            goto L_8017B238;
    }
    // 0x8017B214: nop

    // 0x8017B218: jal         0x800CB720
    // 0x8017B21C: nop

    func_800CB720(rdram, ctx);
        goto after_7;
    // 0x8017B21C: nop

    after_7:
    // 0x8017B220: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8017B224: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x8017B228: bne         $t5, $zero, L_8017B238
    if (ctx->r13 != 0) {
        // 0x8017B22C: nop
    
            goto L_8017B238;
    }
    // 0x8017B22C: nop

    // 0x8017B230: jal         0x800D1640
    // 0x8017B234: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800D1640(rdram, ctx);
        goto after_8;
    // 0x8017B234: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_8:
L_8017B238:
    // 0x8017B238: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017B23C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017B240: jr          $ra
    // 0x8017B244: nop

    return;
    // 0x8017B244: nop

;}
RECOMP_FUNC void func_8017B248_03D600(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017B248: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8017B24C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017B250: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8017B254: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8017B258: addiu       $t7, $t7, 0x3C00
    ctx->r15 = ADD32(ctx->r15, 0X3C00);
    // 0x8017B25C: addiu       $t6, $zero, 0x50
    ctx->r14 = ADD32(0, 0X50);
    // 0x8017B260: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017B264: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8017B268: addiu       $t8, $t8, 0x3C00
    ctx->r24 = ADD32(ctx->r24, 0X3C00);
    // 0x8017B26C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017B270: addiu       $t9, $t9, 0x3C00
    ctx->r25 = ADD32(ctx->r25, 0X3C00);
    // 0x8017B274: sw          $zero, 0x2C($t8)
    MEM_W(0X2C, ctx->r24) = 0;
    // 0x8017B278: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x8017B27C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017B280: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017B284: addiu       $t1, $t1, -0x4198
    ctx->r9 = ADD32(ctx->r9, -0X4198);
    // 0x8017B288: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017B28C: sw          $t0, 0x28($t9)
    MEM_W(0X28, ctx->r25) = ctx->r8;
    // 0x8017B290: addiu       $t2, $t2, -0x4198
    ctx->r10 = ADD32(ctx->r10, -0X4198);
    // 0x8017B294: swc1        $f4, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->f4.u32l;
    // 0x8017B298: lwc1        $f6, 0x4($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X4);
    // 0x8017B29C: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x8017B2A0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8017B2A4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8017B2A8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017B2AC: addiu       $t3, $t3, -0x4198
    ctx->r11 = ADD32(ctx->r11, -0X4198);
    // 0x8017B2B0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017B2B4: swc1        $f6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f6.u32l;
    // 0x8017B2B8: addiu       $t4, $t4, -0x4198
    ctx->r12 = ADD32(ctx->r12, -0X4198);
    // 0x8017B2BC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017B2C0: swc1        $f8, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f8.u32l;
    // 0x8017B2C4: addiu       $t5, $t5, -0x4198
    ctx->r13 = ADD32(ctx->r13, -0X4198);
    // 0x8017B2C8: swc1        $f10, 0x14($t4)
    MEM_W(0X14, ctx->r12) = ctx->f10.u32l;
    // 0x8017B2CC: lwc1        $f20, 0x14($t5)
    ctx->f20.u32l = MEM_W(ctx->r13, 0X14);
    // 0x8017B2D0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8017B2D4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017B2D8: addiu       $t6, $t6, -0x4198
    ctx->r14 = ADD32(ctx->r14, -0X4198);
    // 0x8017B2DC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017B2E0: swc1        $f20, 0x10($t5)
    MEM_W(0X10, ctx->r13) = ctx->f20.u32l;
    // 0x8017B2E4: addiu       $t7, $t7, -0x4198
    ctx->r15 = ADD32(ctx->r15, -0X4198);
    // 0x8017B2E8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017B2EC: swc1        $f20, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f20.u32l;
    // 0x8017B2F0: addiu       $t8, $t8, -0x4198
    ctx->r24 = ADD32(ctx->r24, -0X4198);
    // 0x8017B2F4: swc1        $f16, 0x20($t7)
    MEM_W(0X20, ctx->r15) = ctx->f16.u32l;
    // 0x8017B2F8: lwc1        $f18, 0x20($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X20);
    // 0x8017B2FC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017B300: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017B304: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017B308: addiu       $t0, $t0, -0x4198
    ctx->r8 = ADD32(ctx->r8, -0X4198);
    // 0x8017B30C: swc1        $f18, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->f18.u32l;
    // 0x8017B310: jal         0x800C3FD0
    // 0x8017B314: swc1        $f4, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->f4.u32l;
    func_800C3FD0(rdram, ctx);
        goto after_0;
    // 0x8017B314: swc1        $f4, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->f4.u32l;
    after_0:
    // 0x8017B318: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    // 0x8017B31C: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    // 0x8017B320: jal         0x800C6E0C
    // 0x8017B324: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    func_800C6E0C(rdram, ctx);
        goto after_1;
    // 0x8017B324: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    after_1:
    // 0x8017B328: addiu       $t9, $zero, -0x1E
    ctx->r25 = ADD32(0, -0X1E);
    // 0x8017B32C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8017B330: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    // 0x8017B334: addiu       $a1, $zero, 0x96
    ctx->r5 = ADD32(0, 0X96);
    // 0x8017B338: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    // 0x8017B33C: addiu       $a3, $zero, -0x1E
    ctx->r7 = ADD32(0, -0X1E);
    // 0x8017B340: jal         0x800C6E68
    // 0x8017B344: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_800C6E68(rdram, ctx);
        goto after_2;
    // 0x8017B344: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_2:
    // 0x8017B348: jal         0x800C6DBC
    // 0x8017B34C: nop

    func_800C6DBC(rdram, ctx);
        goto after_3;
    // 0x8017B34C: nop

    after_3:
    // 0x8017B350: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8017B354: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8017B358: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8017B35C: jr          $ra
    // 0x8017B360: nop

    return;
    // 0x8017B360: nop

;}
RECOMP_FUNC void func_8017B364_03D600(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017B364: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017B368: lw          $t6, -0x2E4C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2E4C);
    // 0x8017B36C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017B370: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017B374: bne         $t6, $zero, L_8017B47C
    if (ctx->r14 != 0) {
        // 0x8017B378: nop
    
            goto L_8017B47C;
    }
    // 0x8017B378: nop

    // 0x8017B37C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017B380: addiu       $t7, $t7, 0x3C00
    ctx->r15 = ADD32(ctx->r15, 0X3C00);
    // 0x8017B384: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8017B388: bne         $t8, $zero, L_8017B3A8
    if (ctx->r24 != 0) {
        // 0x8017B38C: nop
    
            goto L_8017B3A8;
    }
    // 0x8017B38C: nop

    // 0x8017B390: jal         0x800C32CC
    // 0x8017B394: nop

    func_800C32CC(rdram, ctx);
        goto after_0;
    // 0x8017B394: nop

    after_0:
    // 0x8017B398: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8017B39C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017B3A0: b           L_8017B47C
    // 0x8017B3A4: sw          $t9, -0x2E4C($at)
    MEM_W(-0X2E4C, ctx->r1) = ctx->r25;
        goto L_8017B47C;
    // 0x8017B3A4: sw          $t9, -0x2E4C($at)
    MEM_W(-0X2E4C, ctx->r1) = ctx->r25;
L_8017B3A8:
    // 0x8017B3A8: lui         $t0, 0x8011
    ctx->r8 = S32(0X8011 << 16);
    // 0x8017B3AC: lhu         $t0, -0x4530($t0)
    ctx->r8 = MEM_HU(ctx->r8, -0X4530);
    // 0x8017B3B0: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x8017B3B4: beq         $t1, $zero, L_8017B3D0
    if (ctx->r9 == 0) {
        // 0x8017B3B8: nop
    
            goto L_8017B3D0;
    }
    // 0x8017B3B8: nop

    // 0x8017B3BC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017B3C0: addiu       $t2, $t2, 0x3C00
    ctx->r10 = ADD32(ctx->r10, 0X3C00);
    // 0x8017B3C4: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8017B3C8: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x8017B3CC: sw          $t4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r12;
L_8017B3D0:
    // 0x8017B3D0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017B3D4: addiu       $t5, $t5, 0x3C00
    ctx->r13 = ADD32(ctx->r13, 0X3C00);
    // 0x8017B3D8: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x8017B3DC: bne         $t6, $zero, L_8017B47C
    if (ctx->r14 != 0) {
        // 0x8017B3E0: nop
    
            goto L_8017B47C;
    }
    // 0x8017B3E0: nop

    // 0x8017B3E4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017B3E8: addiu       $t7, $t7, -0x41E0
    ctx->r15 = ADD32(ctx->r15, -0X41E0);
    // 0x8017B3EC: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x8017B3F0: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
    // 0x8017B3F4: andi        $t9, $t8, 0x38
    ctx->r25 = ctx->r24 & 0X38;
    // 0x8017B3F8: bne         $t9, $at, L_8017B47C
    if (ctx->r25 != ctx->r1) {
        // 0x8017B3FC: nop
    
            goto L_8017B47C;
    }
    // 0x8017B3FC: nop

    // 0x8017B400: lw          $t0, 0x28($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X28);
    // 0x8017B404: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8017B408: lhu         $t4, 0x2($t7)
    ctx->r12 = MEM_HU(ctx->r15, 0X2);
    // 0x8017B40C: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x8017B410: addu        $t3, $t3, $t1
    ctx->r11 = ADD32(ctx->r11, ctx->r9);
    // 0x8017B414: lhu         $t3, -0x4680($t3)
    ctx->r11 = MEM_HU(ctx->r11, -0X4680);
    // 0x8017B418: bne         $t3, $t4, L_8017B47C
    if (ctx->r11 != ctx->r12) {
        // 0x8017B41C: nop
    
            goto L_8017B47C;
    }
    // 0x8017B41C: nop

    // 0x8017B420: addiu       $t2, $t0, 0x1
    ctx->r10 = ADD32(ctx->r8, 0X1);
    // 0x8017B424: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017B428: sw          $t2, 0x28($t5)
    MEM_W(0X28, ctx->r13) = ctx->r10;
    // 0x8017B42C: addiu       $t6, $t6, 0x3C00
    ctx->r14 = ADD32(ctx->r14, 0X3C00);
    // 0x8017B430: lw          $t8, 0x28($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X28);
    // 0x8017B434: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8017B438: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8017B43C: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8017B440: addu        $t1, $t1, $t9
    ctx->r9 = ADD32(ctx->r9, ctx->r25);
    // 0x8017B444: lhu         $t1, -0x4680($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X4680);
    // 0x8017B448: bne         $t1, $at, L_8017B47C
    if (ctx->r9 != ctx->r1) {
        // 0x8017B44C: nop
    
            goto L_8017B47C;
    }
    // 0x8017B44C: nop

    // 0x8017B450: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017B454: addiu       $t7, $t7, -0x2E28
    ctx->r15 = ADD32(ctx->r15, -0X2E28);
    // 0x8017B458: lbu         $t3, 0xF($t7)
    ctx->r11 = MEM_BU(ctx->r15, 0XF);
    // 0x8017B45C: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x8017B460: ori         $t4, $t3, 0x1
    ctx->r12 = ctx->r11 | 0X1;
    // 0x8017B464: jal         0x800C8544
    // 0x8017B468: sb          $t4, 0xF($t7)
    MEM_B(0XF, ctx->r15) = ctx->r12;
    func_800C8544(rdram, ctx);
        goto after_1;
    // 0x8017B468: sb          $t4, 0xF($t7)
    MEM_B(0XF, ctx->r15) = ctx->r12;
    after_1:
    // 0x8017B46C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017B470: addiu       $t2, $t2, 0x3C00
    ctx->r10 = ADD32(ctx->r10, 0X3C00);
    // 0x8017B474: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8017B478: sw          $t0, 0x2C($t2)
    MEM_W(0X2C, ctx->r10) = ctx->r8;
L_8017B47C:
    // 0x8017B47C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017B480: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017B484: jr          $ra
    // 0x8017B488: nop

    return;
    // 0x8017B488: nop

;}
RECOMP_FUNC void func_8017B48C_03D600(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017B48C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8017B490: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8017B494: jal         0x800C3FD0
    // 0x8017B498: nop

    func_800C3FD0(rdram, ctx);
        goto after_0;
    // 0x8017B498: nop

    after_0:
    // 0x8017B49C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017B4A0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017B4A4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017B4A8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8017B4AC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017B4B0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8017B4B4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017B4B8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8017B4BC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8017B4C0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8017B4C4: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x8017B4C8: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x8017B4CC: addiu       $a0, $a0, -0xFE0
    ctx->r4 = ADD32(ctx->r4, -0XFE0);
    // 0x8017B4D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8017B4D4: lui         $a2, 0xC360
    ctx->r6 = S32(0XC360 << 16);
    // 0x8017B4D8: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x8017B4DC: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8017B4E0: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x8017B4E4: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8017B4E8: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x8017B4EC: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x8017B4F0: jal         0x800C58E8
    // 0x8017B4F4: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    func_800C58E8(rdram, ctx);
        goto after_1;
    // 0x8017B4F4: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    after_1:
    // 0x8017B4F8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8017B4FC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017B500: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8017B504: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x8017B508: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8017B50C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017B510: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8017B514: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8017B518: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017B51C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8017B520: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8017B524: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x8017B528: addiu       $a0, $a0, -0xFB8
    ctx->r4 = ADD32(ctx->r4, -0XFB8);
    // 0x8017B52C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8017B530: lui         $a2, 0xC2F4
    ctx->r6 = S32(0XC2F4 << 16);
    // 0x8017B534: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x8017B538: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x8017B53C: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x8017B540: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x8017B544: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    // 0x8017B548: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    // 0x8017B54C: jal         0x800C58E8
    // 0x8017B550: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    func_800C58E8(rdram, ctx);
        goto after_2;
    // 0x8017B550: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x8017B554: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8017B558: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017B55C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017B560: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x8017B564: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8017B568: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8017B56C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8017B570: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017B574: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8017B578: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8017B57C: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x8017B580: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x8017B584: addiu       $a0, $a0, -0xF90
    ctx->r4 = ADD32(ctx->r4, -0XF90);
    // 0x8017B588: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8017B58C: lui         $a2, 0xC0A0
    ctx->r6 = S32(0XC0A0 << 16);
    // 0x8017B590: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x8017B594: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x8017B598: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x8017B59C: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x8017B5A0: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    // 0x8017B5A4: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x8017B5A8: jal         0x800C58E8
    // 0x8017B5AC: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    func_800C58E8(rdram, ctx);
        goto after_3;
    // 0x8017B5AC: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    after_3:
    // 0x8017B5B0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8017B5B4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017B5B8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8017B5BC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8017B5C0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8017B5C4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8017B5C8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017B5CC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8017B5D0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8017B5D4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8017B5D8: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x8017B5DC: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x8017B5E0: addiu       $a0, $a0, -0xF68
    ctx->r4 = ADD32(ctx->r4, -0XF68);
    // 0x8017B5E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8017B5E8: lui         $a2, 0x42EC
    ctx->r6 = S32(0X42EC << 16);
    // 0x8017B5EC: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x8017B5F0: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x8017B5F4: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x8017B5F8: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    // 0x8017B5FC: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x8017B600: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x8017B604: jal         0x800C58E8
    // 0x8017B608: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    func_800C58E8(rdram, ctx);
        goto after_4;
    // 0x8017B608: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    after_4:
    // 0x8017B60C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8017B610: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017B614: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8017B618: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x8017B61C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8017B620: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017B624: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017B628: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8017B62C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8017B630: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8017B634: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x8017B638: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x8017B63C: addiu       $a0, $a0, -0xF40
    ctx->r4 = ADD32(ctx->r4, -0XF40);
    // 0x8017B640: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8017B644: lui         $a2, 0x4375
    ctx->r6 = S32(0X4375 << 16);
    // 0x8017B648: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x8017B64C: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x8017B650: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    // 0x8017B654: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x8017B658: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x8017B65C: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x8017B660: jal         0x800C58E8
    // 0x8017B664: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    func_800C58E8(rdram, ctx);
        goto after_5;
    // 0x8017B664: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    after_5:
    // 0x8017B668: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8017B66C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8017B670: jr          $ra
    // 0x8017B674: nop

    return;
    // 0x8017B674: nop

;}
RECOMP_FUNC void func_8017B678_03D600(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017B678: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8017B67C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8017B680: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8017B684: jal         0x800C7AD0
    // 0x8017B688: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800C7AD0(rdram, ctx);
        goto after_0;
    // 0x8017B688: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x8017B68C: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    // 0x8017B690: jal         0x800C7A60
    // 0x8017B694: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C7A60(rdram, ctx);
        goto after_1;
    // 0x8017B694: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8017B698: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8017B69C: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x8017B6A0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017B6A4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8017B6A8: jal         0x800C7A88
    // 0x8017B6AC: ldc1        $f14, -0x45C8($at)
    CHECK_FR(ctx, 14);
    ctx->f14.u64 = LD(ctx->r1, -0X45C8);
    func_800C7A88(rdram, ctx);
        goto after_2;
    // 0x8017B6AC: ldc1        $f14, -0x45C8($at)
    CHECK_FR(ctx, 14);
    ctx->f14.u64 = LD(ctx->r1, -0X45C8);
    after_2:
    // 0x8017B6B0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017B6B4: addiu       $t6, $t6, -0x2E28
    ctx->r14 = ADD32(ctx->r14, -0X2E28);
    // 0x8017B6B8: lbu         $t7, 0xF($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0XF);
    // 0x8017B6BC: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x8017B6C0: beq         $t8, $zero, L_8017B6E4
    if (ctx->r24 == 0) {
        // 0x8017B6C4: nop
    
            goto L_8017B6E4;
    }
    // 0x8017B6C4: nop

    // 0x8017B6C8: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8017B6CC: addiu       $a1, $zero, 0xB6
    ctx->r5 = ADD32(0, 0XB6);
    // 0x8017B6D0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8017B6D4: jal         0x800C7A9C
    // 0x8017B6D8: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    func_800C7A9C(rdram, ctx);
        goto after_3;
    // 0x8017B6D8: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_3:
    // 0x8017B6DC: b           L_8017B6F8
    // 0x8017B6E0: nop

        goto L_8017B6F8;
    // 0x8017B6E0: nop

L_8017B6E4:
    // 0x8017B6E4: addiu       $a0, $zero, 0xE6
    ctx->r4 = ADD32(0, 0XE6);
    // 0x8017B6E8: addiu       $a1, $zero, 0xE6
    ctx->r5 = ADD32(0, 0XE6);
    // 0x8017B6EC: addiu       $a2, $zero, 0xE6
    ctx->r6 = ADD32(0, 0XE6);
    // 0x8017B6F0: jal         0x800C7A9C
    // 0x8017B6F4: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    func_800C7A9C(rdram, ctx);
        goto after_4;
    // 0x8017B6F4: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_4:
L_8017B6F8:
    // 0x8017B6F8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017B6FC: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017B700: addiu       $a1, $a1, -0x4670
    ctx->r5 = ADD32(ctx->r5, -0X4670);
    // 0x8017B704: jal         0x800D87E4
    // 0x8017B708: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_5;
    // 0x8017B708: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_5:
    // 0x8017B70C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017B710: jal         0x800DD77C
    // 0x8017B714: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    strlen_recomp(rdram, ctx);
        goto after_6;
    // 0x8017B714: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_6:
    // 0x8017B718: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8017B71C: sll         $t9, $s0, 3
    ctx->r25 = S32(ctx->r16 << 3);
    // 0x8017B720: bgez        $t9, L_8017B730
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8017B724: sra         $t0, $t9, 1
        ctx->r8 = S32(SIGNED(ctx->r25) >> 1);
            goto L_8017B730;
    }
    // 0x8017B724: sra         $t0, $t9, 1
    ctx->r8 = S32(SIGNED(ctx->r25) >> 1);
    // 0x8017B728: addiu       $at, $t9, 0x1
    ctx->r1 = ADD32(ctx->r25, 0X1);
    // 0x8017B72C: sra         $t0, $at, 1
    ctx->r8 = S32(SIGNED(ctx->r1) >> 1);
L_8017B730:
    // 0x8017B730: addiu       $t1, $zero, 0x140
    ctx->r9 = ADD32(0, 0X140);
    // 0x8017B734: subu        $a0, $t1, $t0
    ctx->r4 = SUB32(ctx->r9, ctx->r8);
    // 0x8017B738: jal         0x800C7A74
    // 0x8017B73C: addiu       $a1, $zero, 0x17C
    ctx->r5 = ADD32(0, 0X17C);
    func_800C7A74(rdram, ctx);
        goto after_7;
    // 0x8017B73C: addiu       $a1, $zero, 0x17C
    ctx->r5 = ADD32(0, 0X17C);
    after_7:
    // 0x8017B740: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8017B744: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8017B748: addiu       $a1, $a1, 0x3B40
    ctx->r5 = ADD32(ctx->r5, 0X3B40);
    // 0x8017B74C: jal         0x800C767C
    // 0x8017B750: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    func_800C767C(rdram, ctx);
        goto after_8;
    // 0x8017B750: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    after_8:
    // 0x8017B754: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017B758: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017B75C: addiu       $a1, $a1, -0x464C
    ctx->r5 = ADD32(ctx->r5, -0X464C);
    // 0x8017B760: jal         0x800D87E4
    // 0x8017B764: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_9;
    // 0x8017B764: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_9:
    // 0x8017B768: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017B76C: jal         0x800DD77C
    // 0x8017B770: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    strlen_recomp(rdram, ctx);
        goto after_10;
    // 0x8017B770: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_10:
    // 0x8017B774: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8017B778: sll         $t2, $s0, 3
    ctx->r10 = S32(ctx->r16 << 3);
    // 0x8017B77C: bgez        $t2, L_8017B78C
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8017B780: sra         $t3, $t2, 1
        ctx->r11 = S32(SIGNED(ctx->r10) >> 1);
            goto L_8017B78C;
    }
    // 0x8017B780: sra         $t3, $t2, 1
    ctx->r11 = S32(SIGNED(ctx->r10) >> 1);
    // 0x8017B784: addiu       $at, $t2, 0x1
    ctx->r1 = ADD32(ctx->r10, 0X1);
    // 0x8017B788: sra         $t3, $at, 1
    ctx->r11 = S32(SIGNED(ctx->r1) >> 1);
L_8017B78C:
    // 0x8017B78C: addiu       $t4, $zero, 0x140
    ctx->r12 = ADD32(0, 0X140);
    // 0x8017B790: subu        $a0, $t4, $t3
    ctx->r4 = SUB32(ctx->r12, ctx->r11);
    // 0x8017B794: jal         0x800C7A74
    // 0x8017B798: addiu       $a1, $zero, 0x190
    ctx->r5 = ADD32(0, 0X190);
    func_800C7A74(rdram, ctx);
        goto after_11;
    // 0x8017B798: addiu       $a1, $zero, 0x190
    ctx->r5 = ADD32(0, 0X190);
    after_11:
    // 0x8017B79C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8017B7A0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8017B7A4: addiu       $a1, $a1, 0x3B40
    ctx->r5 = ADD32(ctx->r5, 0X3B40);
    // 0x8017B7A8: jal         0x800C767C
    // 0x8017B7AC: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    func_800C767C(rdram, ctx);
        goto after_12;
    // 0x8017B7AC: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    after_12:
    // 0x8017B7B0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017B7B4: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017B7B8: addiu       $a1, $a1, -0x461C
    ctx->r5 = ADD32(ctx->r5, -0X461C);
    // 0x8017B7BC: jal         0x800D87E4
    // 0x8017B7C0: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_13;
    // 0x8017B7C0: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_13:
    // 0x8017B7C4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017B7C8: jal         0x800DD77C
    // 0x8017B7CC: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    strlen_recomp(rdram, ctx);
        goto after_14;
    // 0x8017B7CC: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_14:
    // 0x8017B7D0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8017B7D4: sll         $t5, $s0, 3
    ctx->r13 = S32(ctx->r16 << 3);
    // 0x8017B7D8: bgez        $t5, L_8017B7E8
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8017B7DC: sra         $t6, $t5, 1
        ctx->r14 = S32(SIGNED(ctx->r13) >> 1);
            goto L_8017B7E8;
    }
    // 0x8017B7DC: sra         $t6, $t5, 1
    ctx->r14 = S32(SIGNED(ctx->r13) >> 1);
    // 0x8017B7E0: addiu       $at, $t5, 0x1
    ctx->r1 = ADD32(ctx->r13, 0X1);
    // 0x8017B7E4: sra         $t6, $at, 1
    ctx->r14 = S32(SIGNED(ctx->r1) >> 1);
L_8017B7E8:
    // 0x8017B7E8: addiu       $t7, $zero, 0x140
    ctx->r15 = ADD32(0, 0X140);
    // 0x8017B7EC: subu        $a0, $t7, $t6
    ctx->r4 = SUB32(ctx->r15, ctx->r14);
    // 0x8017B7F0: jal         0x800C7A74
    // 0x8017B7F4: addiu       $a1, $zero, 0x1AE
    ctx->r5 = ADD32(0, 0X1AE);
    func_800C7A74(rdram, ctx);
        goto after_15;
    // 0x8017B7F4: addiu       $a1, $zero, 0x1AE
    ctx->r5 = ADD32(0, 0X1AE);
    after_15:
    // 0x8017B7F8: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8017B7FC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8017B800: addiu       $a1, $a1, 0x3B40
    ctx->r5 = ADD32(ctx->r5, 0X3B40);
    // 0x8017B804: jal         0x800C767C
    // 0x8017B808: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    func_800C767C(rdram, ctx);
        goto after_16;
    // 0x8017B808: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    after_16:
    // 0x8017B80C: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x8017B810: lhu         $t8, -0x4530($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X4530);
    // 0x8017B814: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x8017B818: bne         $t9, $zero, L_8017B960
    if (ctx->r25 != 0) {
        // 0x8017B81C: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_8017B960;
    }
    // 0x8017B81C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8017B820: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x8017B824: mtc1        $at, $f15
    ctx->f_odd[(15 - 1) * 2] = ctx->r1;
    // 0x8017B828: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8017B82C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8017B830: jal         0x800C7A88
    // 0x8017B834: nop

    func_800C7A88(rdram, ctx);
        goto after_17;
    // 0x8017B834: nop

    after_17:
    // 0x8017B838: addiu       $a0, $zero, 0xE6
    ctx->r4 = ADD32(0, 0XE6);
    // 0x8017B83C: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    // 0x8017B840: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    // 0x8017B844: jal         0x800C7A9C
    // 0x8017B848: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    func_800C7A9C(rdram, ctx);
        goto after_18;
    // 0x8017B848: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_18:
    // 0x8017B84C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017B850: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017B854: addiu       $a1, $a1, -0x4604
    ctx->r5 = ADD32(ctx->r5, -0X4604);
    // 0x8017B858: jal         0x800D87E4
    // 0x8017B85C: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_19;
    // 0x8017B85C: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_19:
    // 0x8017B860: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017B864: jal         0x800DD77C
    // 0x8017B868: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    strlen_recomp(rdram, ctx);
        goto after_20;
    // 0x8017B868: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_20:
    // 0x8017B86C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8017B870: sll         $t1, $s0, 4
    ctx->r9 = S32(ctx->r16 << 4);
    // 0x8017B874: bgez        $t1, L_8017B884
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8017B878: sra         $t0, $t1, 1
        ctx->r8 = S32(SIGNED(ctx->r9) >> 1);
            goto L_8017B884;
    }
    // 0x8017B878: sra         $t0, $t1, 1
    ctx->r8 = S32(SIGNED(ctx->r9) >> 1);
    // 0x8017B87C: addiu       $at, $t1, 0x1
    ctx->r1 = ADD32(ctx->r9, 0X1);
    // 0x8017B880: sra         $t0, $at, 1
    ctx->r8 = S32(SIGNED(ctx->r1) >> 1);
L_8017B884:
    // 0x8017B884: addiu       $t2, $zero, 0x140
    ctx->r10 = ADD32(0, 0X140);
    // 0x8017B888: subu        $a0, $t2, $t0
    ctx->r4 = SUB32(ctx->r10, ctx->r8);
    // 0x8017B88C: jal         0x800C7A74
    // 0x8017B890: addiu       $a1, $zero, 0xB8
    ctx->r5 = ADD32(0, 0XB8);
    func_800C7A74(rdram, ctx);
        goto after_21;
    // 0x8017B890: addiu       $a1, $zero, 0xB8
    ctx->r5 = ADD32(0, 0XB8);
    after_21:
    // 0x8017B894: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8017B898: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8017B89C: addiu       $a1, $a1, 0x3B40
    ctx->r5 = ADD32(ctx->r5, 0X3B40);
    // 0x8017B8A0: jal         0x800C767C
    // 0x8017B8A4: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    func_800C767C(rdram, ctx);
        goto after_22;
    // 0x8017B8A4: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    after_22:
    // 0x8017B8A8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017B8AC: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017B8B0: addiu       $a1, $a1, -0x45F4
    ctx->r5 = ADD32(ctx->r5, -0X45F4);
    // 0x8017B8B4: jal         0x800D87E4
    // 0x8017B8B8: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_23;
    // 0x8017B8B8: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_23:
    // 0x8017B8BC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017B8C0: jal         0x800DD77C
    // 0x8017B8C4: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    strlen_recomp(rdram, ctx);
        goto after_24;
    // 0x8017B8C4: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_24:
    // 0x8017B8C8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8017B8CC: sll         $t4, $s0, 4
    ctx->r12 = S32(ctx->r16 << 4);
    // 0x8017B8D0: bgez        $t4, L_8017B8E0
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8017B8D4: sra         $t3, $t4, 1
        ctx->r11 = S32(SIGNED(ctx->r12) >> 1);
            goto L_8017B8E0;
    }
    // 0x8017B8D4: sra         $t3, $t4, 1
    ctx->r11 = S32(SIGNED(ctx->r12) >> 1);
    // 0x8017B8D8: addiu       $at, $t4, 0x1
    ctx->r1 = ADD32(ctx->r12, 0X1);
    // 0x8017B8DC: sra         $t3, $at, 1
    ctx->r11 = S32(SIGNED(ctx->r1) >> 1);
L_8017B8E0:
    // 0x8017B8E0: addiu       $t5, $zero, 0x140
    ctx->r13 = ADD32(0, 0X140);
    // 0x8017B8E4: subu        $a0, $t5, $t3
    ctx->r4 = SUB32(ctx->r13, ctx->r11);
    // 0x8017B8E8: jal         0x800C7A74
    // 0x8017B8EC: addiu       $a1, $zero, 0xE0
    ctx->r5 = ADD32(0, 0XE0);
    func_800C7A74(rdram, ctx);
        goto after_25;
    // 0x8017B8EC: addiu       $a1, $zero, 0xE0
    ctx->r5 = ADD32(0, 0XE0);
    after_25:
    // 0x8017B8F0: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8017B8F4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8017B8F8: addiu       $a1, $a1, 0x3B40
    ctx->r5 = ADD32(ctx->r5, 0X3B40);
    // 0x8017B8FC: jal         0x800C767C
    // 0x8017B900: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    func_800C767C(rdram, ctx);
        goto after_26;
    // 0x8017B900: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    after_26:
    // 0x8017B904: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017B908: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017B90C: addiu       $a1, $a1, -0x45DC
    ctx->r5 = ADD32(ctx->r5, -0X45DC);
    // 0x8017B910: jal         0x800D87E4
    // 0x8017B914: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_27;
    // 0x8017B914: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_27:
    // 0x8017B918: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017B91C: jal         0x800DD77C
    // 0x8017B920: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    strlen_recomp(rdram, ctx);
        goto after_28;
    // 0x8017B920: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_28:
    // 0x8017B924: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8017B928: sll         $t7, $s0, 4
    ctx->r15 = S32(ctx->r16 << 4);
    // 0x8017B92C: bgez        $t7, L_8017B93C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8017B930: sra         $t6, $t7, 1
        ctx->r14 = S32(SIGNED(ctx->r15) >> 1);
            goto L_8017B93C;
    }
    // 0x8017B930: sra         $t6, $t7, 1
    ctx->r14 = S32(SIGNED(ctx->r15) >> 1);
    // 0x8017B934: addiu       $at, $t7, 0x1
    ctx->r1 = ADD32(ctx->r15, 0X1);
    // 0x8017B938: sra         $t6, $at, 1
    ctx->r14 = S32(SIGNED(ctx->r1) >> 1);
L_8017B93C:
    // 0x8017B93C: addiu       $t8, $zero, 0x140
    ctx->r24 = ADD32(0, 0X140);
    // 0x8017B940: subu        $a0, $t8, $t6
    ctx->r4 = SUB32(ctx->r24, ctx->r14);
    // 0x8017B944: jal         0x800C7A74
    // 0x8017B948: addiu       $a1, $zero, 0x108
    ctx->r5 = ADD32(0, 0X108);
    func_800C7A74(rdram, ctx);
        goto after_29;
    // 0x8017B948: addiu       $a1, $zero, 0x108
    ctx->r5 = ADD32(0, 0X108);
    after_29:
    // 0x8017B94C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8017B950: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8017B954: addiu       $a1, $a1, 0x3B40
    ctx->r5 = ADD32(ctx->r5, 0X3B40);
    // 0x8017B958: jal         0x800C767C
    // 0x8017B95C: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    func_800C767C(rdram, ctx);
        goto after_30;
    // 0x8017B95C: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    after_30:
L_8017B960:
    // 0x8017B960: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8017B964: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8017B968: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8017B96C: jr          $ra
    // 0x8017B970: nop

    return;
    // 0x8017B970: nop

    // 0x8017B974: nop

    // 0x8017B978: nop

;}
RECOMP_FUNC void func_8017B97C_03D600(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017B97C: nop

;}
RECOMP_FUNC void func_8017B0C0_041650(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017B0C0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
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
    // 0x8017B0FC: jal         0x8017B274
    // 0x8017B100: nop

    func_8017B274_041650(rdram, ctx);
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
    // 0x8017B110: addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
    func_800C7FA4(rdram, ctx);
        goto after_3;
    // 0x8017B110: addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
    after_3:
    // 0x8017B114: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8017B118: jal         0x800D1640
    // 0x8017B11C: addiu       $a0, $a0, -0x4E84
    ctx->r4 = ADD32(ctx->r4, -0X4E84);
    func_800D1640(rdram, ctx);
        goto after_4;
    // 0x8017B11C: addiu       $a0, $a0, -0x4E84
    ctx->r4 = ADD32(ctx->r4, -0X4E84);
    after_4:
L_8017B120:
    yield_self_1ms(rdram);
    // 0x8017B120: jal         0x800E4CDC
    // 0x8017B124: nop

    func_800E4CDC(rdram, ctx);
        goto after_5;
    // 0x8017B124: nop

    after_5:
    // 0x8017B128: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017B12C: lw          $t0, -0x2E4C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2E4C);
    // 0x8017B130: beq         $t0, $zero, L_8017B120
    if (ctx->r8 == 0) {
        // 0x8017B134: nop
    
            goto L_8017B120;
    }
    // 0x8017B134: nop

    // 0x8017B138: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x8017B13C: lhu         $t1, -0x4530($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X4530);
    // 0x8017B140: andi        $t2, $t1, 0x2000
    ctx->r10 = ctx->r9 & 0X2000;
    // 0x8017B144: bne         $t2, $zero, L_8017B120
    if (ctx->r10 != 0) {
        // 0x8017B148: nop
    
            goto L_8017B120;
    }
    // 0x8017B148: nop

    // 0x8017B14C: jal         0x800CB720
    // 0x8017B150: nop

    func_800CB720(rdram, ctx);
        goto after_6;
    // 0x8017B150: nop

    after_6:
    // 0x8017B154: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8017B158: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x8017B15C: bne         $t3, $zero, L_8017B120
    if (ctx->r11 != 0) {
        // 0x8017B160: nop
    
            goto L_8017B120;
    }
    // 0x8017B160: nop

    // 0x8017B164: jal         0x800C6DD4
    // 0x8017B168: nop

    func_800C6DD4(rdram, ctx);
        goto after_7;
    // 0x8017B168: nop

    after_7:
    // 0x8017B16C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017B170: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017B174: jr          $ra
    // 0x8017B178: nop

    return;
    // 0x8017B178: nop

;}
RECOMP_FUNC void func_8017B17C_041650(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017B17C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017B180: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8017B184: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8017B188: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017B18C: bgtz        $t6, L_8017B264
    if (SIGNED(ctx->r14) > 0) {
        // 0x8017B190: nop
    
            goto L_8017B264;
    }
    // 0x8017B190: nop

    // 0x8017B194: jal         0x800C3704
    // 0x8017B198: nop

    func_800C3704(rdram, ctx);
        goto after_0;
    // 0x8017B198: nop

    after_0:
    // 0x8017B19C: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x8017B1A0: lw          $t7, -0x4514($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4514);
    // 0x8017B1A4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8017B1A8: lui         $t9, 0xDB06
    ctx->r25 = S32(0XDB06 << 16);
    // 0x8017B1AC: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x8017B1B0: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8017B1B4: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8017B1B8: sw          $t8, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r24;
    // 0x8017B1BC: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x8017B1C0: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8017B1C4: jal         0x800C7458
    // 0x8017B1C8: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    func_800C7458(rdram, ctx);
        goto after_1;
    // 0x8017B1C8: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    after_1:
    // 0x8017B1CC: jal         0x8016D9E8
    // 0x8017B1D0: nop

    func_8016D9E8_02FC30(rdram, ctx);
        goto after_2;
    // 0x8017B1D0: nop

    after_2:
    // 0x8017B1D4: jal         0x8016E8B0
    // 0x8017B1D8: nop

    func_8016E8B0_02FC30(rdram, ctx);
        goto after_3;
    // 0x8017B1D8: nop

    after_3:
    // 0x8017B1DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8017B1E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8017B1E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8017B1E8: jal         0x800C25FC
    // 0x8017B1EC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800C25FC(rdram, ctx);
        goto after_4;
    // 0x8017B1EC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
    // 0x8017B1F0: jal         0x8017BA8C
    // 0x8017B1F4: nop

    func_8017BA8C_041650(rdram, ctx);
        goto after_5;
    // 0x8017B1F4: nop

    after_5:
    // 0x8017B1F8: jal         0x800C3578
    // 0x8017B1FC: nop

    func_800C3578(rdram, ctx);
        goto after_6;
    // 0x8017B1FC: nop

    after_6:
    // 0x8017B200: jal         0x8017C138
    // 0x8017B204: nop

    func_8017C138_041650(rdram, ctx);
        goto after_7;
    // 0x8017B204: nop

    after_7:
    // 0x8017B208: jal         0x800C3760
    // 0x8017B20C: nop

    func_800C3760(rdram, ctx);
        goto after_8;
    // 0x8017B20C: nop

    after_8:
    // 0x8017B210: jal         0x8016FBBC
    // 0x8017B214: nop

    func_8016FBBC_02FC30(rdram, ctx);
        goto after_9;
    // 0x8017B214: nop

    after_9:
    // 0x8017B218: jal         0x8017B3C8
    // 0x8017B21C: nop

    func_8017B3C8_041650(rdram, ctx);
        goto after_10;
    // 0x8017B21C: nop

    after_10:
    // 0x8017B220: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017B224: lw          $t2, -0x2E4C($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2E4C);
    // 0x8017B228: beq         $t2, $zero, L_8017B264
    if (ctx->r10 == 0) {
        // 0x8017B22C: nop
    
            goto L_8017B264;
    }
    // 0x8017B22C: nop

    // 0x8017B230: lui         $t3, 0x8011
    ctx->r11 = S32(0X8011 << 16);
    // 0x8017B234: lhu         $t3, -0x4530($t3)
    ctx->r11 = MEM_HU(ctx->r11, -0X4530);
    // 0x8017B238: andi        $t4, $t3, 0x2000
    ctx->r12 = ctx->r11 & 0X2000;
    // 0x8017B23C: bne         $t4, $zero, L_8017B264
    if (ctx->r12 != 0) {
        // 0x8017B240: nop
    
            goto L_8017B264;
    }
    // 0x8017B240: nop

    // 0x8017B244: jal         0x800CB720
    // 0x8017B248: nop

    func_800CB720(rdram, ctx);
        goto after_11;
    // 0x8017B248: nop

    after_11:
    // 0x8017B24C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8017B250: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x8017B254: bne         $t5, $zero, L_8017B264
    if (ctx->r13 != 0) {
        // 0x8017B258: nop
    
            goto L_8017B264;
    }
    // 0x8017B258: nop

    // 0x8017B25C: jal         0x800D1640
    // 0x8017B260: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800D1640(rdram, ctx);
        goto after_12;
    // 0x8017B260: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_12:
L_8017B264:
    // 0x8017B264: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017B268: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017B26C: jr          $ra
    return;
;}
RECOMP_FUNC void func_8017B270_041650(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017B270: nop

;}
RECOMP_FUNC void func_8017B274_041650(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017B274: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8017B278: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017B27C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8017B280: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8017B284: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x8017B288: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x8017B28C: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8017B290: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8017B294: sw          $zero, -0x2E34($at)
    MEM_W(-0X2E34, ctx->r1) = 0;
    // 0x8017B298: addiu       $t6, $t6, -0x3838
    ctx->r14 = ADD32(ctx->r14, -0X3838);
    // 0x8017B29C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8017B2A0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017B2A4: sw          $t7, -0x2BB8($at)
    MEM_W(-0X2BB8, ctx->r1) = ctx->r15;
    // 0x8017B2A8: lw          $t8, 0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X4);
    // 0x8017B2AC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017B2B0: sw          $t8, -0x2BB0($at)
    MEM_W(-0X2BB0, ctx->r1) = ctx->r24;
    // 0x8017B2B4: lw          $t9, 0x8($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X8);
    // 0x8017B2B8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017B2BC: jal         0x8016D8A4
    // 0x8017B2C0: sw          $t9, -0x2BB4($at)
    MEM_W(-0X2BB4, ctx->r1) = ctx->r25;
    func_8016D8A4_02FC30(rdram, ctx);
        goto after_0;
    // 0x8017B2C0: sw          $t9, -0x2BB4($at)
    MEM_W(-0X2BB4, ctx->r1) = ctx->r25;
    after_0:
    // 0x8017B2C4: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8017B2C8: addiu       $t0, $t0, -0x382C
    ctx->r8 = ADD32(ctx->r8, -0X382C);
    // 0x8017B2CC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017B2D0: jal         0x8016E85C
    // 0x8017B2D4: sw          $t0, -0x2D8C($at)
    MEM_W(-0X2D8C, ctx->r1) = ctx->r8;
    func_8016E85C_02FC30(rdram, ctx);
        goto after_1;
    // 0x8017B2D4: sw          $t0, -0x2D8C($at)
    MEM_W(-0X2D8C, ctx->r1) = ctx->r8;
    after_1:
    // 0x8017B2D8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017B2DC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017B2E0: addiu       $t1, $t1, -0x2D90
    ctx->r9 = ADD32(ctx->r9, -0X2D90);
    // 0x8017B2E4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017B2E8: addiu       $t2, $t2, -0x2D90
    ctx->r10 = ADD32(ctx->r10, -0X2D90);
    // 0x8017B2EC: swc1        $f4, 0x20($t1)
    MEM_W(0X20, ctx->r9) = ctx->f4.u32l;
    // 0x8017B2F0: lwc1        $f22, 0x20($t2)
    ctx->f22.u32l = MEM_W(ctx->r10, 0X20);
    // 0x8017B2F4: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017B2F8: addiu       $t3, $t3, -0x2D90
    ctx->r11 = ADD32(ctx->r11, -0X2D90);
    // 0x8017B2FC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017B300: swc1        $f22, 0x1C($t2)
    MEM_W(0X1C, ctx->r10) = ctx->f22.u32l;
    // 0x8017B304: mov.s       $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    ctx->f20.fl = ctx->f22.fl;
    // 0x8017B308: swc1        $f20, 0x18($t3)
    MEM_W(0X18, ctx->r11) = ctx->f20.u32l;
    // 0x8017B30C: addiu       $t4, $t4, -0x2D90
    ctx->r12 = ADD32(ctx->r12, -0X2D90);
    // 0x8017B310: swc1        $f20, 0x14($t4)
    MEM_W(0X14, ctx->r12) = ctx->f20.u32l;
    // 0x8017B314: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    // 0x8017B318: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    // 0x8017B31C: jal         0x800C6E0C
    // 0x8017B320: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    func_800C6E0C(rdram, ctx);
        goto after_2;
    // 0x8017B320: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    after_2:
    // 0x8017B324: addiu       $t5, $zero, 0xA
    ctx->r13 = ADD32(0, 0XA);
    // 0x8017B328: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8017B32C: addiu       $a0, $zero, 0xFA
    ctx->r4 = ADD32(0, 0XFA);
    // 0x8017B330: addiu       $a1, $zero, 0xFA
    ctx->r5 = ADD32(0, 0XFA);
    // 0x8017B334: addiu       $a2, $zero, 0xFA
    ctx->r6 = ADD32(0, 0XFA);
    // 0x8017B338: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8017B33C: jal         0x800C6E68
    // 0x8017B340: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_800C6E68(rdram, ctx);
        goto after_3;
    // 0x8017B340: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_3:
    // 0x8017B344: jal         0x800C6DBC
    // 0x8017B348: nop

    func_800C6DBC(rdram, ctx);
        goto after_4;
    // 0x8017B348: nop

    after_4:
    // 0x8017B34C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017B350: addiu       $t7, $t7, 0x3C00
    ctx->r15 = ADD32(ctx->r15, 0X3C00);
    // 0x8017B354: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017B358: addiu       $t8, $t8, 0x3C00
    ctx->r24 = ADD32(ctx->r24, 0X3C00);
    // 0x8017B35C: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x8017B360: lw          $t6, 0x4($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X4);
    // 0x8017B364: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017B368: addiu       $t9, $t9, 0x3B00
    ctx->r25 = ADD32(ctx->r25, 0X3B00);
    // 0x8017B36C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017B370: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x8017B374: sb          $zero, 0x3($t9)
    MEM_B(0X3, ctx->r25) = 0;
    // 0x8017B378: addiu       $t0, $t0, 0x3B00
    ctx->r8 = ADD32(ctx->r8, 0X3B00);
    // 0x8017B37C: lbu         $s1, 0x3($t0)
    ctx->r17 = MEM_BU(ctx->r8, 0X3);
    // 0x8017B380: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017B384: addiu       $t1, $t1, 0x3B00
    ctx->r9 = ADD32(ctx->r9, 0X3B00);
    // 0x8017B388: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017B38C: sb          $s1, 0x2($t0)
    MEM_B(0X2, ctx->r8) = ctx->r17;
    // 0x8017B390: andi        $s0, $s1, 0xFF
    ctx->r16 = ctx->r17 & 0XFF;
    // 0x8017B394: sb          $s0, 0x1($t1)
    MEM_B(0X1, ctx->r9) = ctx->r16;
    // 0x8017B398: addiu       $t2, $t2, 0x3B00
    ctx->r10 = ADD32(ctx->r10, 0X3B00);
    // 0x8017B39C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017B3A0: sb          $s0, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r16;
    // 0x8017B3A4: addiu       $t3, $t3, 0x3B00
    ctx->r11 = ADD32(ctx->r11, 0X3B00);
    // 0x8017B3A8: sb          $zero, 0xA($t3)
    MEM_B(0XA, ctx->r11) = 0;
    // 0x8017B3AC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8017B3B0: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x8017B3B4: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x8017B3B8: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8017B3BC: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8017B3C0: jr          $ra
    // 0x8017B3C4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8017B3C4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_8017B3C8_041650(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017B3C8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8017B3CC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017B3D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8017B3D4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8017B3D8: addiu       $t6, $t6, 0x3C00
    ctx->r14 = ADD32(ctx->r14, 0X3C00);
    // 0x8017B3DC: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8017B3E0: sltiu       $at, $t7, 0x6
    ctx->r1 = ctx->r15 < 0X6 ? 1 : 0;
    // 0x8017B3E4: beq         $at, $zero, L_8017BA78
    if (ctx->r1 == 0) {
        // 0x8017B3E8: nop
    
            goto L_8017BA78;
    }
    // 0x8017B3E8: nop

    // 0x8017B3EC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017B3F0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017B3F4: addu        $at, $at, $t7
    gpr jr_addend_8017B3FC = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8017B3F8: lw          $t7, -0x375C($at)
    ctx->r15 = ADD32(ctx->r1, -0X375C);
    // 0x8017B3FC: jr          $t7
    // 0x8017B400: nop

    switch (jr_addend_8017B3FC >> 2) {
        case 0: goto L_8017B404; break;
        case 1: goto L_8017B564; break;
        case 2: goto L_8017B6E8; break;
        case 3: goto L_8017B7A8; break;
        case 4: goto L_8017BA78; break;
        case 5: goto L_8017B9A8; break;
        default: switch_error(__func__, 0x8017B3FC, 0x8017C8A4);
    }
    // 0x8017B400: nop

L_8017B404:
    // 0x8017B404: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017B408: addiu       $t8, $t8, -0x41E0
    ctx->r24 = ADD32(ctx->r24, -0X41E0);
    // 0x8017B40C: lhu         $t9, 0x2($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X2);
    // 0x8017B410: andi        $t0, $t9, 0xF000
    ctx->r8 = ctx->r25 & 0XF000;
    // 0x8017B414: beq         $t0, $zero, L_8017B530
    if (ctx->r8 == 0) {
        // 0x8017B418: nop
    
            goto L_8017B530;
    }
    // 0x8017B418: nop

    // 0x8017B41C: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x8017B420: lhu         $t1, -0x4530($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X4530);
    // 0x8017B424: andi        $t2, $t1, 0x10
    ctx->r10 = ctx->r9 & 0X10;
    // 0x8017B428: bne         $t2, $zero, L_8017B530
    if (ctx->r10 != 0) {
        // 0x8017B42C: nop
    
            goto L_8017B530;
    }
    // 0x8017B42C: nop

    // 0x8017B430: addiu       $t3, $zero, 0x6A
    ctx->r11 = ADD32(0, 0X6A);
    // 0x8017B434: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017B438: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017B43C: sw          $t3, -0x2E34($at)
    MEM_W(-0X2E34, ctx->r1) = ctx->r11;
    // 0x8017B440: addiu       $t4, $t4, -0x2A28
    ctx->r12 = ADD32(ctx->r12, -0X2A28);
    // 0x8017B444: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x8017B448: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017B44C: addiu       $a0, $a0, -0x2A28
    ctx->r4 = ADD32(ctx->r4, -0X2A28);
    // 0x8017B450: ori         $t6, $t5, 0x3
    ctx->r14 = ctx->r13 | 0X3;
    // 0x8017B454: sh          $t6, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r14;
    // 0x8017B458: jal         0x800D6D20
    // 0x8017B45C: addiu       $a0, $a0, 0xA4
    ctx->r4 = ADD32(ctx->r4, 0XA4);
    guMtxIdentF_recomp(rdram, ctx);
        goto after_0;
    // 0x8017B45C: addiu       $a0, $a0, 0xA4
    ctx->r4 = ADD32(ctx->r4, 0XA4);
    after_0:
    // 0x8017B460: lui         $at, 0x42DC
    ctx->r1 = S32(0X42DC << 16);
    // 0x8017B464: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017B468: lui         $at, 0x42E0
    ctx->r1 = S32(0X42E0 << 16);
    // 0x8017B46C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017B470: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017B474: lui         $at, 0x42AA
    ctx->r1 = S32(0X42AA << 16);
    // 0x8017B478: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8017B47C: addiu       $t7, $t7, -0x2A28
    ctx->r15 = ADD32(ctx->r15, -0X2A28);
    // 0x8017B480: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017B484: addiu       $t8, $t8, -0x2A28
    ctx->r24 = ADD32(ctx->r24, -0X2A28);
    // 0x8017B488: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017B48C: swc1        $f4, 0x60($t7)
    MEM_W(0X60, ctx->r15) = ctx->f4.u32l;
    // 0x8017B490: addiu       $t9, $t9, -0x2A28
    ctx->r25 = ADD32(ctx->r25, -0X2A28);
    // 0x8017B494: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017B498: swc1        $f6, 0x64($t8)
    MEM_W(0X64, ctx->r24) = ctx->f6.u32l;
    // 0x8017B49C: addiu       $t0, $t0, -0x2A28
    ctx->r8 = ADD32(ctx->r8, -0X2A28);
    // 0x8017B4A0: swc1        $f8, 0x68($t9)
    MEM_W(0X68, ctx->r25) = ctx->f8.u32l;
    // 0x8017B4A4: lhu         $t1, 0x134($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X134);
    // 0x8017B4A8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017B4AC: addiu       $a0, $a0, -0x2A28
    ctx->r4 = ADD32(ctx->r4, -0X2A28);
    // 0x8017B4B0: ori         $t2, $t1, 0x3
    ctx->r10 = ctx->r9 | 0X3;
    // 0x8017B4B4: sh          $t2, 0x134($t0)
    MEM_H(0X134, ctx->r8) = ctx->r10;
    // 0x8017B4B8: jal         0x800D6D20
    // 0x8017B4BC: addiu       $a0, $a0, 0x1D8
    ctx->r4 = ADD32(ctx->r4, 0X1D8);
    guMtxIdentF_recomp(rdram, ctx);
        goto after_1;
    // 0x8017B4BC: addiu       $a0, $a0, 0x1D8
    ctx->r4 = ADD32(ctx->r4, 0X1D8);
    after_1:
    // 0x8017B4C0: lui         $at, 0xC2EB
    ctx->r1 = S32(0XC2EB << 16);
    // 0x8017B4C4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017B4C8: lui         $at, 0x42DC
    ctx->r1 = S32(0X42DC << 16);
    // 0x8017B4CC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8017B4D0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017B4D4: lui         $at, 0x42AA
    ctx->r1 = S32(0X42AA << 16);
    // 0x8017B4D8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8017B4DC: addiu       $t3, $t3, -0x2A28
    ctx->r11 = ADD32(ctx->r11, -0X2A28);
    // 0x8017B4E0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017B4E4: addiu       $t5, $t5, -0x2A28
    ctx->r13 = ADD32(ctx->r13, -0X2A28);
    // 0x8017B4E8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017B4EC: swc1        $f10, 0x194($t3)
    MEM_W(0X194, ctx->r11) = ctx->f10.u32l;
    // 0x8017B4F0: addiu       $t6, $t6, -0x2A28
    ctx->r14 = ADD32(ctx->r14, -0X2A28);
    // 0x8017B4F4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017B4F8: swc1        $f16, 0x198($t5)
    MEM_W(0X198, ctx->r13) = ctx->f16.u32l;
    // 0x8017B4FC: addiu       $t7, $t7, 0x3B00
    ctx->r15 = ADD32(ctx->r15, 0X3B00);
    // 0x8017B500: addiu       $t4, $zero, 0x8C
    ctx->r12 = ADD32(0, 0X8C);
    // 0x8017B504: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017B508: swc1        $f18, 0x19C($t6)
    MEM_W(0X19C, ctx->r14) = ctx->f18.u32l;
    // 0x8017B50C: sb          $t4, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r12;
    // 0x8017B510: addiu       $t9, $t9, 0x3B00
    ctx->r25 = ADD32(ctx->r25, 0X3B00);
    // 0x8017B514: addiu       $t8, $zero, 0xDC
    ctx->r24 = ADD32(0, 0XDC);
    // 0x8017B518: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017B51C: addiu       $t2, $t2, 0x3C00
    ctx->r10 = ADD32(ctx->r10, 0X3C00);
    // 0x8017B520: sb          $t8, 0x3($t9)
    MEM_B(0X3, ctx->r25) = ctx->r24;
    // 0x8017B524: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8017B528: b           L_8017BA78
    // 0x8017B52C: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
        goto L_8017BA78;
    // 0x8017B52C: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
L_8017B530:
    // 0x8017B530: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017B534: lw          $t0, -0x2E34($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2E34);
    // 0x8017B538: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017B53C: addiu       $t3, $t0, 0x1
    ctx->r11 = ADD32(ctx->r8, 0X1);
    // 0x8017B540: sw          $t3, -0x2E34($at)
    MEM_W(-0X2E34, ctx->r1) = ctx->r11;
    // 0x8017B544: addiu       $at, $zero, 0x60
    ctx->r1 = ADD32(0, 0X60);
    // 0x8017B548: bne         $t3, $at, L_8017BA78
    if (ctx->r11 != ctx->r1) {
        // 0x8017B54C: nop
    
            goto L_8017BA78;
    }
    // 0x8017B54C: nop

    // 0x8017B550: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017B554: addiu       $t6, $t6, 0x3C00
    ctx->r14 = ADD32(ctx->r14, 0X3C00);
    // 0x8017B558: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8017B55C: b           L_8017BA78
    // 0x8017B560: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
        goto L_8017BA78;
    // 0x8017B560: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
L_8017B564:
    // 0x8017B564: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017B568: addiu       $t4, $t4, -0x41E0
    ctx->r12 = ADD32(ctx->r12, -0X41E0);
    // 0x8017B56C: lhu         $t7, 0x2($t4)
    ctx->r15 = MEM_HU(ctx->r12, 0X2);
    // 0x8017B570: andi        $t8, $t7, 0xF000
    ctx->r24 = ctx->r15 & 0XF000;
    // 0x8017B574: beq         $t8, $zero, L_8017B690
    if (ctx->r24 == 0) {
        // 0x8017B578: nop
    
            goto L_8017B690;
    }
    // 0x8017B578: nop

    // 0x8017B57C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017B580: lw          $t9, -0x2E34($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2E34);
    // 0x8017B584: sltiu       $at, $t9, 0x6A
    ctx->r1 = ctx->r25 < 0X6A ? 1 : 0;
    // 0x8017B588: beq         $at, $zero, L_8017B65C
    if (ctx->r1 == 0) {
        // 0x8017B58C: nop
    
            goto L_8017B65C;
    }
    // 0x8017B58C: nop

    // 0x8017B590: addiu       $t1, $zero, 0x6A
    ctx->r9 = ADD32(0, 0X6A);
    // 0x8017B594: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017B598: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017B59C: sw          $t1, -0x2E34($at)
    MEM_W(-0X2E34, ctx->r1) = ctx->r9;
    // 0x8017B5A0: addiu       $t2, $t2, -0x2A28
    ctx->r10 = ADD32(ctx->r10, -0X2A28);
    // 0x8017B5A4: lhu         $t0, 0x0($t2)
    ctx->r8 = MEM_HU(ctx->r10, 0X0);
    // 0x8017B5A8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017B5AC: addiu       $a0, $a0, -0x2A28
    ctx->r4 = ADD32(ctx->r4, -0X2A28);
    // 0x8017B5B0: ori         $t3, $t0, 0x3
    ctx->r11 = ctx->r8 | 0X3;
    // 0x8017B5B4: sh          $t3, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r11;
    // 0x8017B5B8: jal         0x800D6D20
    // 0x8017B5BC: addiu       $a0, $a0, 0xA4
    ctx->r4 = ADD32(ctx->r4, 0XA4);
    guMtxIdentF_recomp(rdram, ctx);
        goto after_2;
    // 0x8017B5BC: addiu       $a0, $a0, 0xA4
    ctx->r4 = ADD32(ctx->r4, 0XA4);
    after_2:
    // 0x8017B5C0: lui         $at, 0x42DC
    ctx->r1 = S32(0X42DC << 16);
    // 0x8017B5C4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017B5C8: lui         $at, 0x42E0
    ctx->r1 = S32(0X42E0 << 16);
    // 0x8017B5CC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017B5D0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017B5D4: lui         $at, 0x42AA
    ctx->r1 = S32(0X42AA << 16);
    // 0x8017B5D8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8017B5DC: addiu       $t5, $t5, -0x2A28
    ctx->r13 = ADD32(ctx->r13, -0X2A28);
    // 0x8017B5E0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017B5E4: addiu       $t6, $t6, -0x2A28
    ctx->r14 = ADD32(ctx->r14, -0X2A28);
    // 0x8017B5E8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017B5EC: swc1        $f4, 0x60($t5)
    MEM_W(0X60, ctx->r13) = ctx->f4.u32l;
    // 0x8017B5F0: addiu       $t4, $t4, -0x2A28
    ctx->r12 = ADD32(ctx->r12, -0X2A28);
    // 0x8017B5F4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017B5F8: swc1        $f6, 0x64($t6)
    MEM_W(0X64, ctx->r14) = ctx->f6.u32l;
    // 0x8017B5FC: addiu       $t7, $t7, -0x2A28
    ctx->r15 = ADD32(ctx->r15, -0X2A28);
    // 0x8017B600: swc1        $f8, 0x68($t4)
    MEM_W(0X68, ctx->r12) = ctx->f8.u32l;
    // 0x8017B604: lhu         $t8, 0x134($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X134);
    // 0x8017B608: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017B60C: addiu       $a0, $a0, -0x2A28
    ctx->r4 = ADD32(ctx->r4, -0X2A28);
    // 0x8017B610: ori         $t9, $t8, 0x3
    ctx->r25 = ctx->r24 | 0X3;
    // 0x8017B614: sh          $t9, 0x134($t7)
    MEM_H(0X134, ctx->r15) = ctx->r25;
    // 0x8017B618: jal         0x800D6D20
    // 0x8017B61C: addiu       $a0, $a0, 0x1D8
    ctx->r4 = ADD32(ctx->r4, 0X1D8);
    guMtxIdentF_recomp(rdram, ctx);
        goto after_3;
    // 0x8017B61C: addiu       $a0, $a0, 0x1D8
    ctx->r4 = ADD32(ctx->r4, 0X1D8);
    after_3:
    // 0x8017B620: lui         $at, 0xC2EB
    ctx->r1 = S32(0XC2EB << 16);
    // 0x8017B624: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017B628: lui         $at, 0x42DC
    ctx->r1 = S32(0X42DC << 16);
    // 0x8017B62C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8017B630: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017B634: lui         $at, 0x42AA
    ctx->r1 = S32(0X42AA << 16);
    // 0x8017B638: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8017B63C: addiu       $t1, $t1, -0x2A28
    ctx->r9 = ADD32(ctx->r9, -0X2A28);
    // 0x8017B640: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017B644: addiu       $t0, $t0, -0x2A28
    ctx->r8 = ADD32(ctx->r8, -0X2A28);
    // 0x8017B648: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017B64C: swc1        $f10, 0x194($t1)
    MEM_W(0X194, ctx->r9) = ctx->f10.u32l;
    // 0x8017B650: addiu       $t3, $t3, -0x2A28
    ctx->r11 = ADD32(ctx->r11, -0X2A28);
    // 0x8017B654: swc1        $f16, 0x198($t0)
    MEM_W(0X198, ctx->r8) = ctx->f16.u32l;
    // 0x8017B658: swc1        $f18, 0x19C($t3)
    MEM_W(0X19C, ctx->r11) = ctx->f18.u32l;
L_8017B65C:
    // 0x8017B65C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017B660: addiu       $t5, $t5, 0x3B00
    ctx->r13 = ADD32(ctx->r13, 0X3B00);
    // 0x8017B664: addiu       $t2, $zero, 0x8C
    ctx->r10 = ADD32(0, 0X8C);
    // 0x8017B668: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017B66C: addiu       $t4, $t4, 0x3B00
    ctx->r12 = ADD32(ctx->r12, 0X3B00);
    // 0x8017B670: sb          $t2, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r10;
    // 0x8017B674: addiu       $t6, $zero, 0xDC
    ctx->r14 = ADD32(0, 0XDC);
    // 0x8017B678: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017B67C: addiu       $t9, $t9, 0x3C00
    ctx->r25 = ADD32(ctx->r25, 0X3C00);
    // 0x8017B680: sb          $t6, 0x3($t4)
    MEM_B(0X3, ctx->r12) = ctx->r14;
    // 0x8017B684: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8017B688: b           L_8017BA78
    // 0x8017B68C: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
        goto L_8017BA78;
    // 0x8017B68C: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
L_8017B690:
    // 0x8017B690: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017B694: lw          $t7, -0x2E34($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2E34);
    // 0x8017B698: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017B69C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017B6A0: addiu       $t1, $t7, 0x1
    ctx->r9 = ADD32(ctx->r15, 0X1);
    // 0x8017B6A4: sw          $t1, -0x2E34($at)
    MEM_W(-0X2E34, ctx->r1) = ctx->r9;
    // 0x8017B6A8: addiu       $t0, $t0, 0x3B00
    ctx->r8 = ADD32(ctx->r8, 0X3B00);
    // 0x8017B6AC: lbu         $t3, 0x0($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X0);
    // 0x8017B6B0: addiu       $at, $zero, 0x8C
    ctx->r1 = ADD32(0, 0X8C);
    // 0x8017B6B4: bne         $t3, $at, L_8017B6D0
    if (ctx->r11 != ctx->r1) {
        // 0x8017B6B8: nop
    
            goto L_8017B6D0;
    }
    // 0x8017B6B8: nop

    // 0x8017B6BC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017B6C0: addiu       $t5, $t5, 0x3C00
    ctx->r13 = ADD32(ctx->r13, 0X3C00);
    // 0x8017B6C4: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x8017B6C8: b           L_8017BA78
    // 0x8017B6CC: sw          $t2, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r10;
        goto L_8017BA78;
    // 0x8017B6CC: sw          $t2, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r10;
L_8017B6D0:
    // 0x8017B6D0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017B6D4: addiu       $t6, $t6, 0x3B00
    ctx->r14 = ADD32(ctx->r14, 0X3B00);
    // 0x8017B6D8: lbu         $t4, 0x0($t6)
    ctx->r12 = MEM_BU(ctx->r14, 0X0);
    // 0x8017B6DC: addiu       $t8, $t4, 0xA
    ctx->r24 = ADD32(ctx->r12, 0XA);
    // 0x8017B6E0: b           L_8017BA78
    // 0x8017B6E4: sb          $t8, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r24;
        goto L_8017BA78;
    // 0x8017B6E4: sb          $t8, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r24;
L_8017B6E8:
    // 0x8017B6E8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017B6EC: lw          $t9, -0x2E4C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2E4C);
    // 0x8017B6F0: bne         $t9, $zero, L_8017BA78
    if (ctx->r25 != 0) {
        // 0x8017B6F4: nop
    
            goto L_8017BA78;
    }
    // 0x8017B6F4: nop

    // 0x8017B6F8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017B6FC: addiu       $t7, $t7, 0x3C00
    ctx->r15 = ADD32(ctx->r15, 0X3C00);
    // 0x8017B700: lw          $t1, 0x4($t7)
    ctx->r9 = MEM_W(ctx->r15, 0X4);
    // 0x8017B704: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017B708: addiu       $t3, $t3, 0x3C00
    ctx->r11 = ADD32(ctx->r11, 0X3C00);
    // 0x8017B70C: addiu       $t0, $t1, 0x1
    ctx->r8 = ADD32(ctx->r9, 0X1);
    // 0x8017B710: sw          $t0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r8;
    // 0x8017B714: lw          $t2, 0x4($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X4);
    // 0x8017B718: addiu       $at, $zero, 0xF3
    ctx->r1 = ADD32(0, 0XF3);
    // 0x8017B71C: bne         $t2, $at, L_8017B738
    if (ctx->r10 != ctx->r1) {
        // 0x8017B720: nop
    
            goto L_8017B738;
    }
    // 0x8017B720: nop

    // 0x8017B724: jal         0x800C32CC
    // 0x8017B728: nop

    func_800C32CC(rdram, ctx);
        goto after_4;
    // 0x8017B728: nop

    after_4:
    // 0x8017B72C: addiu       $t5, $zero, 0x14
    ctx->r13 = ADD32(0, 0X14);
    // 0x8017B730: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017B734: sw          $t5, -0x2E4C($at)
    MEM_W(-0X2E4C, ctx->r1) = ctx->r13;
L_8017B738:
    // 0x8017B738: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017B73C: addiu       $t4, $t4, 0x3B00
    ctx->r12 = ADD32(ctx->r12, 0X3B00);
    // 0x8017B740: lbu         $t8, 0x3($t4)
    ctx->r24 = MEM_BU(ctx->r12, 0X3);
    // 0x8017B744: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017B748: addiu       $t9, $t9, 0x3B00
    ctx->r25 = ADD32(ctx->r25, 0X3B00);
    // 0x8017B74C: addiu       $t6, $t8, 0x14
    ctx->r14 = ADD32(ctx->r24, 0X14);
    // 0x8017B750: sb          $t6, 0x3($t4)
    MEM_B(0X3, ctx->r12) = ctx->r14;
    // 0x8017B754: lbu         $t1, 0x3($t9)
    ctx->r9 = MEM_BU(ctx->r25, 0X3);
    // 0x8017B758: slti        $at, $t1, 0xDC
    ctx->r1 = SIGNED(ctx->r9) < 0XDC ? 1 : 0;
    // 0x8017B75C: bne         $at, $zero, L_8017B76C
    if (ctx->r1 != 0) {
        // 0x8017B760: nop
    
            goto L_8017B76C;
    }
    // 0x8017B760: nop

    // 0x8017B764: addiu       $t0, $zero, 0xDC
    ctx->r8 = ADD32(0, 0XDC);
    // 0x8017B768: sb          $t0, 0x3($t9)
    MEM_B(0X3, ctx->r25) = ctx->r8;
L_8017B76C:
    // 0x8017B76C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017B770: addiu       $t7, $t7, -0x41E0
    ctx->r15 = ADD32(ctx->r15, -0X41E0);
    // 0x8017B774: lhu         $t3, 0x2($t7)
    ctx->r11 = MEM_HU(ctx->r15, 0X2);
    // 0x8017B778: andi        $t2, $t3, 0xF000
    ctx->r10 = ctx->r11 & 0XF000;
    // 0x8017B77C: beq         $t2, $zero, L_8017BA78
    if (ctx->r10 == 0) {
        // 0x8017B780: nop
    
            goto L_8017BA78;
    }
    // 0x8017B780: nop

    // 0x8017B784: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017B788: addiu       $t8, $t8, 0x3C00
    ctx->r24 = ADD32(ctx->r24, 0X3C00);
    // 0x8017B78C: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x8017B790: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017B794: addiu       $t4, $t4, 0x3B00
    ctx->r12 = ADD32(ctx->r12, 0X3B00);
    // 0x8017B798: sw          $t5, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r13;
    // 0x8017B79C: addiu       $t6, $zero, 0xDC
    ctx->r14 = ADD32(0, 0XDC);
    // 0x8017B7A0: b           L_8017BA78
    // 0x8017B7A4: sb          $t6, 0x3($t4)
    MEM_B(0X3, ctx->r12) = ctx->r14;
        goto L_8017BA78;
    // 0x8017B7A4: sb          $t6, 0x3($t4)
    MEM_B(0X3, ctx->r12) = ctx->r14;
L_8017B7A8:
    // 0x8017B7A8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017B7AC: lw          $t1, -0x2E4C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2E4C);
    // 0x8017B7B0: bne         $t1, $zero, L_8017BA78
    if (ctx->r9 != 0) {
        // 0x8017B7B4: nop
    
            goto L_8017BA78;
    }
    // 0x8017B7B4: nop

    // 0x8017B7B8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017B7BC: addiu       $t0, $t0, -0x41E0
    ctx->r8 = ADD32(ctx->r8, -0X41E0);
    // 0x8017B7C0: lhu         $t9, 0x2($t0)
    ctx->r25 = MEM_HU(ctx->r8, 0X2);
    // 0x8017B7C4: andi        $t7, $t9, 0xB000
    ctx->r15 = ctx->r25 & 0XB000;
    // 0x8017B7C8: beq         $t7, $zero, L_8017B850
    if (ctx->r15 == 0) {
        // 0x8017B7CC: nop
    
            goto L_8017B850;
    }
    // 0x8017B7CC: nop

    // 0x8017B7D0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017B7D4: addiu       $t3, $t3, 0x3B00
    ctx->r11 = ADD32(ctx->r11, 0X3B00);
    // 0x8017B7D8: lbu         $s0, 0x1($t3)
    ctx->r16 = MEM_BU(ctx->r11, 0X1);
    // 0x8017B7DC: beq         $s0, $zero, L_8017B7FC
    if (ctx->r16 == 0) {
        // 0x8017B7E0: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8017B7FC;
    }
    // 0x8017B7E0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8017B7E4: beq         $s0, $at, L_8017B814
    if (ctx->r16 == ctx->r1) {
        // 0x8017B7E8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8017B814;
    }
    // 0x8017B7E8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8017B7EC: beq         $s0, $at, L_8017B838
    if (ctx->r16 == ctx->r1) {
        // 0x8017B7F0: nop
    
            goto L_8017B838;
    }
    // 0x8017B7F0: nop

    // 0x8017B7F4: b           L_8017B850
    // 0x8017B7F8: nop

        goto L_8017B850;
    // 0x8017B7F8: nop

L_8017B7FC:
    // 0x8017B7FC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8017B800: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017B804: jal         0x800C32CC
    // 0x8017B808: sw          $t2, -0x2E4C($at)
    MEM_W(-0X2E4C, ctx->r1) = ctx->r10;
    func_800C32CC(rdram, ctx);
        goto after_5;
    // 0x8017B808: sw          $t2, -0x2E4C($at)
    MEM_W(-0X2E4C, ctx->r1) = ctx->r10;
    after_5:
    // 0x8017B80C: b           L_8017BA78
    // 0x8017B810: nop

        goto L_8017BA78;
    // 0x8017B810: nop

L_8017B814:
    // 0x8017B814: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017B818: addiu       $t8, $t8, 0x3C00
    ctx->r24 = ADD32(ctx->r24, 0X3C00);
    // 0x8017B81C: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x8017B820: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017B824: addiu       $t4, $t4, 0x3B00
    ctx->r12 = ADD32(ctx->r12, 0X3B00);
    // 0x8017B828: sw          $t5, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r13;
    // 0x8017B82C: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8017B830: b           L_8017BA78
    // 0x8017B834: sb          $t6, 0x2($t4)
    MEM_B(0X2, ctx->r12) = ctx->r14;
        goto L_8017BA78;
    // 0x8017B834: sb          $t6, 0x2($t4)
    MEM_B(0X2, ctx->r12) = ctx->r14;
L_8017B838:
    // 0x8017B838: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x8017B83C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017B840: jal         0x800C32CC
    // 0x8017B844: sw          $t1, -0x2E4C($at)
    MEM_W(-0X2E4C, ctx->r1) = ctx->r9;
    func_800C32CC(rdram, ctx);
        goto after_6;
    // 0x8017B844: sw          $t1, -0x2E4C($at)
    MEM_W(-0X2E4C, ctx->r1) = ctx->r9;
    after_6:
    // 0x8017B848: b           L_8017BA78
    // 0x8017B84C: nop

        goto L_8017BA78;
    // 0x8017B84C: nop

L_8017B850:
    // 0x8017B850: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017B854: addiu       $t0, $t0, 0x3B00
    ctx->r8 = ADD32(ctx->r8, 0X3B00);
    // 0x8017B858: lbu         $t9, 0xA($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0XA);
    // 0x8017B85C: bne         $t9, $zero, L_8017B87C
    if (ctx->r25 != 0) {
        // 0x8017B860: nop
    
            goto L_8017B87C;
    }
    // 0x8017B860: nop

    // 0x8017B864: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017B868: addiu       $t7, $t7, -0x41E0
    ctx->r15 = ADD32(ctx->r15, -0X41E0);
    // 0x8017B86C: lb          $t3, 0x7($t7)
    ctx->r11 = MEM_B(ctx->r15, 0X7);
    // 0x8017B870: slti        $at, $t3, -0xE
    ctx->r1 = SIGNED(ctx->r11) < -0XE ? 1 : 0;
    // 0x8017B874: bne         $at, $zero, L_8017B894
    if (ctx->r1 != 0) {
        // 0x8017B878: nop
    
            goto L_8017B894;
    }
    // 0x8017B878: nop

L_8017B87C:
    // 0x8017B87C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017B880: addiu       $t2, $t2, -0x41E0
    ctx->r10 = ADD32(ctx->r10, -0X41E0);
    // 0x8017B884: lhu         $t5, 0x4($t2)
    ctx->r13 = MEM_HU(ctx->r10, 0X4);
    // 0x8017B888: andi        $t8, $t5, 0x400
    ctx->r24 = ctx->r13 & 0X400;
    // 0x8017B88C: beq         $t8, $zero, L_8017B8E4
    if (ctx->r24 == 0) {
        // 0x8017B890: nop
    
            goto L_8017B8E4;
    }
    // 0x8017B890: nop

L_8017B894:
    // 0x8017B894: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017B898: addiu       $t6, $t6, 0x3B00
    ctx->r14 = ADD32(ctx->r14, 0X3B00);
    // 0x8017B89C: lbu         $t4, 0x1($t6)
    ctx->r12 = MEM_BU(ctx->r14, 0X1);
    // 0x8017B8A0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017B8A4: addiu       $t0, $t0, 0x3B00
    ctx->r8 = ADD32(ctx->r8, 0X3B00);
    // 0x8017B8A8: addiu       $t1, $t4, 0x1
    ctx->r9 = ADD32(ctx->r12, 0X1);
    // 0x8017B8AC: sb          $t1, 0x1($t6)
    MEM_B(0X1, ctx->r14) = ctx->r9;
    // 0x8017B8B0: lbu         $t9, 0x1($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X1);
    // 0x8017B8B4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8017B8B8: bne         $t9, $at, L_8017B8C4
    if (ctx->r25 != ctx->r1) {
        // 0x8017B8BC: nop
    
            goto L_8017B8C4;
    }
    // 0x8017B8BC: nop

    // 0x8017B8C0: sb          $zero, 0x1($t0)
    MEM_B(0X1, ctx->r8) = 0;
L_8017B8C4:
    // 0x8017B8C4: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017B8C8: addiu       $t3, $t3, 0x3B00
    ctx->r11 = ADD32(ctx->r11, 0X3B00);
    // 0x8017B8CC: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8017B8D0: sb          $t7, 0xA($t3)
    MEM_B(0XA, ctx->r11) = ctx->r15;
    // 0x8017B8D4: jal         0x800C8544
    // 0x8017B8D8: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    func_800C8544(rdram, ctx);
        goto after_7;
    // 0x8017B8D8: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    after_7:
    // 0x8017B8DC: b           L_8017BA78
    // 0x8017B8E0: nop

        goto L_8017BA78;
    // 0x8017B8E0: nop

L_8017B8E4:
    // 0x8017B8E4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017B8E8: addiu       $t2, $t2, 0x3B00
    ctx->r10 = ADD32(ctx->r10, 0X3B00);
    // 0x8017B8EC: lbu         $t5, 0xA($t2)
    ctx->r13 = MEM_BU(ctx->r10, 0XA);
    // 0x8017B8F0: bne         $t5, $zero, L_8017B910
    if (ctx->r13 != 0) {
        // 0x8017B8F4: nop
    
            goto L_8017B910;
    }
    // 0x8017B8F4: nop

    // 0x8017B8F8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017B8FC: addiu       $t8, $t8, -0x41E0
    ctx->r24 = ADD32(ctx->r24, -0X41E0);
    // 0x8017B900: lb          $t4, 0x7($t8)
    ctx->r12 = MEM_B(ctx->r24, 0X7);
    // 0x8017B904: slti        $at, $t4, 0xF
    ctx->r1 = SIGNED(ctx->r12) < 0XF ? 1 : 0;
    // 0x8017B908: beq         $at, $zero, L_8017B928
    if (ctx->r1 == 0) {
        // 0x8017B90C: nop
    
            goto L_8017B928;
    }
    // 0x8017B90C: nop

L_8017B910:
    // 0x8017B910: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017B914: addiu       $t1, $t1, -0x41E0
    ctx->r9 = ADD32(ctx->r9, -0X41E0);
    // 0x8017B918: lhu         $t6, 0x4($t1)
    ctx->r14 = MEM_HU(ctx->r9, 0X4);
    // 0x8017B91C: andi        $t9, $t6, 0x800
    ctx->r25 = ctx->r14 & 0X800;
    // 0x8017B920: beq         $t9, $zero, L_8017B97C
    if (ctx->r25 == 0) {
        // 0x8017B924: nop
    
            goto L_8017B97C;
    }
    // 0x8017B924: nop

L_8017B928:
    // 0x8017B928: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017B92C: addiu       $t0, $t0, 0x3B00
    ctx->r8 = ADD32(ctx->r8, 0X3B00);
    // 0x8017B930: lbu         $t7, 0x1($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X1);
    // 0x8017B934: bne         $t7, $zero, L_8017B948
    if (ctx->r15 != 0) {
        // 0x8017B938: nop
    
            goto L_8017B948;
    }
    // 0x8017B938: nop

    // 0x8017B93C: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x8017B940: b           L_8017B95C
    // 0x8017B944: sb          $t3, 0x1($t0)
    MEM_B(0X1, ctx->r8) = ctx->r11;
        goto L_8017B95C;
    // 0x8017B944: sb          $t3, 0x1($t0)
    MEM_B(0X1, ctx->r8) = ctx->r11;
L_8017B948:
    // 0x8017B948: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017B94C: addiu       $t2, $t2, 0x3B00
    ctx->r10 = ADD32(ctx->r10, 0X3B00);
    // 0x8017B950: lbu         $t5, 0x1($t2)
    ctx->r13 = MEM_BU(ctx->r10, 0X1);
    // 0x8017B954: addiu       $t8, $t5, -0x1
    ctx->r24 = ADD32(ctx->r13, -0X1);
    // 0x8017B958: sb          $t8, 0x1($t2)
    MEM_B(0X1, ctx->r10) = ctx->r24;
L_8017B95C:
    // 0x8017B95C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017B960: addiu       $t1, $t1, 0x3B00
    ctx->r9 = ADD32(ctx->r9, 0X3B00);
    // 0x8017B964: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x8017B968: sb          $t4, 0xA($t1)
    MEM_B(0XA, ctx->r9) = ctx->r12;
    // 0x8017B96C: jal         0x800C8544
    // 0x8017B970: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    func_800C8544(rdram, ctx);
        goto after_8;
    // 0x8017B970: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    after_8:
    // 0x8017B974: b           L_8017BA78
    // 0x8017B978: nop

        goto L_8017BA78;
    // 0x8017B978: nop

L_8017B97C:
    // 0x8017B97C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017B980: addiu       $t6, $t6, -0x41E0
    ctx->r14 = ADD32(ctx->r14, -0X41E0);
    // 0x8017B984: jal         0x800E4D30
    // 0x8017B988: lb          $a0, 0x7($t6)
    ctx->r4 = MEM_B(ctx->r14, 0X7);
    func_800E4D30(rdram, ctx);
        goto after_9;
    // 0x8017B988: lb          $a0, 0x7($t6)
    ctx->r4 = MEM_B(ctx->r14, 0X7);
    after_9:
    // 0x8017B98C: slti        $at, $v0, 0x6
    ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x8017B990: beq         $at, $zero, L_8017BA78
    if (ctx->r1 == 0) {
        // 0x8017B994: nop
    
            goto L_8017BA78;
    }
    // 0x8017B994: nop

    // 0x8017B998: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017B99C: addiu       $t9, $t9, 0x3B00
    ctx->r25 = ADD32(ctx->r25, 0X3B00);
    // 0x8017B9A0: b           L_8017BA78
    // 0x8017B9A4: sb          $zero, 0xA($t9)
    MEM_B(0XA, ctx->r25) = 0;
        goto L_8017BA78;
    // 0x8017B9A4: sb          $zero, 0xA($t9)
    MEM_B(0XA, ctx->r25) = 0;
L_8017B9A8:
    // 0x8017B9A8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017B9AC: lw          $t7, -0x2E4C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2E4C);
    // 0x8017B9B0: bne         $t7, $zero, L_8017BA78
    if (ctx->r15 != 0) {
        // 0x8017B9B4: nop
    
            goto L_8017BA78;
    }
    // 0x8017B9B4: nop

    // 0x8017B9B8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_8017B9BC:
    // 0x8017B9BC: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8017B9C0: lui         $t3, 0x8011
    ctx->r11 = S32(0X8011 << 16);
    // 0x8017B9C4: lhu         $t3, -0x4530($t3)
    ctx->r11 = MEM_HU(ctx->r11, -0X4530);
    // 0x8017B9C8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8017B9CC: sllv        $t8, $t5, $t0
    ctx->r24 = S32(ctx->r13 << (ctx->r8 & 31));
    // 0x8017B9D0: and         $t2, $t3, $t8
    ctx->r10 = ctx->r11 & ctx->r24;
    // 0x8017B9D4: beq         $t2, $zero, L_8017BA64
    if (ctx->r10 == 0) {
        // 0x8017B9D8: nop
    
            goto L_8017BA64;
    }
    // 0x8017B9D8: nop

    // 0x8017B9DC: sll         $t4, $t0, 2
    ctx->r12 = S32(ctx->r8 << 2);
    // 0x8017B9E0: addu        $t4, $t4, $t0
    ctx->r12 = ADD32(ctx->r12, ctx->r8);
    // 0x8017B9E4: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x8017B9E8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017B9EC: addu        $t1, $t1, $t4
    ctx->r9 = ADD32(ctx->r9, ctx->r12);
    // 0x8017B9F0: lhu         $t1, -0x41DE($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X41DE);
    // 0x8017B9F4: andi        $t6, $t1, 0xB000
    ctx->r14 = ctx->r9 & 0XB000;
    // 0x8017B9F8: beq         $t6, $zero, L_8017BA28
    if (ctx->r14 == 0) {
        // 0x8017B9FC: nop
    
            goto L_8017BA28;
    }
    // 0x8017B9FC: nop

    // 0x8017BA00: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017BA04: addiu       $t9, $t9, 0x3B00
    ctx->r25 = ADD32(ctx->r25, 0X3B00);
    // 0x8017BA08: sb          $t0, 0x2($t9)
    MEM_B(0X2, ctx->r25) = ctx->r8;
    // 0x8017BA0C: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8017BA10: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8017BA14: addiu       $t5, $t7, 0x5
    ctx->r13 = ADD32(ctx->r15, 0X5);
    // 0x8017BA18: jal         0x800C32CC
    // 0x8017BA1C: sw          $t5, -0x2E4C($at)
    MEM_W(-0X2E4C, ctx->r1) = ctx->r13;
    func_800C32CC(rdram, ctx);
        goto after_10;
    // 0x8017BA1C: sw          $t5, -0x2E4C($at)
    MEM_W(-0X2E4C, ctx->r1) = ctx->r13;
    after_10:
    // 0x8017BA20: b           L_8017BA78
    // 0x8017BA24: nop

        goto L_8017BA78;
    // 0x8017BA24: nop

L_8017BA28:
    // 0x8017BA28: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8017BA2C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017BA30: sll         $t8, $t3, 2
    ctx->r24 = S32(ctx->r11 << 2);
    // 0x8017BA34: addu        $t8, $t8, $t3
    ctx->r24 = ADD32(ctx->r24, ctx->r11);
    // 0x8017BA38: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x8017BA3C: addu        $t2, $t2, $t8
    ctx->r10 = ADD32(ctx->r10, ctx->r24);
    // 0x8017BA40: lhu         $t2, -0x41DE($t2)
    ctx->r10 = MEM_HU(ctx->r10, -0X41DE);
    // 0x8017BA44: andi        $t4, $t2, 0x4000
    ctx->r12 = ctx->r10 & 0X4000;
    // 0x8017BA48: beq         $t4, $zero, L_8017BA64
    if (ctx->r12 == 0) {
        // 0x8017BA4C: nop
    
            goto L_8017BA64;
    }
    // 0x8017BA4C: nop

    // 0x8017BA50: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017BA54: addiu       $t6, $t6, 0x3C00
    ctx->r14 = ADD32(ctx->r14, 0X3C00);
    // 0x8017BA58: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x8017BA5C: b           L_8017BA78
    // 0x8017BA60: sw          $t1, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r9;
        goto L_8017BA78;
    // 0x8017BA60: sw          $t1, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r9;
L_8017BA64:
    // 0x8017BA64: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8017BA68: addiu       $t9, $t0, 0x1
    ctx->r25 = ADD32(ctx->r8, 0X1);
    // 0x8017BA6C: sltiu       $at, $t9, 0x4
    ctx->r1 = ctx->r25 < 0X4 ? 1 : 0;
    // 0x8017BA70: bne         $at, $zero, L_8017B9BC
    if (ctx->r1 != 0) {
        // 0x8017BA74: sw          $t9, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r25;
            goto L_8017B9BC;
    }
    // 0x8017BA74: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
L_8017BA78:
    // 0x8017BA78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8017BA7C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8017BA80: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8017BA84: jr          $ra
    // 0x8017BA88: nop

    return;
    // 0x8017BA88: nop

;}
RECOMP_FUNC void func_8017BA8C_041650(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017BA8C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017BA90: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017BA94: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8017BA98: addiu       $t6, $t6, 0x3C00
    ctx->r14 = ADD32(ctx->r14, 0X3C00);
    // 0x8017BA9C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8017BAA0: sltiu       $at, $t7, 0x7
    ctx->r1 = ctx->r15 < 0X7 ? 1 : 0;
    // 0x8017BAA4: beq         $at, $zero, L_8017BC24
    if (ctx->r1 == 0) {
        // 0x8017BAA8: nop
    
            goto L_8017BC24;
    }
    // 0x8017BAA8: nop

    // 0x8017BAAC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8017BAB0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8017BAB4: addu        $at, $at, $t7
    gpr jr_addend_8017BABC = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8017BAB8: lw          $t7, -0x3744($at)
    ctx->r15 = ADD32(ctx->r1, -0X3744);
    // 0x8017BABC: jr          $t7
    // 0x8017BAC0: nop

    switch (jr_addend_8017BABC >> 2) {
        case 0: goto L_8017BC24; break;
        case 1: goto L_8017BAC4; break;
        case 2: goto L_8017BB14; break;
        case 3: goto L_8017BB98; break;
        case 4: goto L_8017BB98; break;
        case 5: goto L_8017BB98; break;
        case 6: goto L_8017BB98; break;
        default: switch_error(__func__, 0x8017BABC, 0x8017C8BC);
    }
    // 0x8017BAC0: nop

L_8017BAC4:
    // 0x8017BAC4: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8017BAC8: jal         0x800D54C8
    // 0x8017BACC: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    spX2Init_recomp(rdram, ctx);
        goto after_0;
    // 0x8017BACC: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    after_0:
    // 0x8017BAD0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017BAD4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017BAD8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017BADC: addiu       $t8, $t8, 0x3B00
    ctx->r24 = ADD32(ctx->r24, 0X3B00);
    // 0x8017BAE0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8017BAE4: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x8017BAE8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8017BAEC: addiu       $a0, $a0, 0x5F10
    ctx->r4 = ADD32(ctx->r4, 0X5F10);
    // 0x8017BAF0: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x8017BAF4: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8017BAF8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8017BAFC: jal         0x800C6C6C
    // 0x8017BB00: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    func_800C6C6C(rdram, ctx);
        goto after_1;
    // 0x8017BB00: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_1:
    // 0x8017BB04: jal         0x800C6D5C
    // 0x8017BB08: nop

    func_800C6D5C(rdram, ctx);
        goto after_2;
    // 0x8017BB08: nop

    after_2:
    // 0x8017BB0C: b           L_8017BC24
    // 0x8017BB10: nop

        goto L_8017BC24;
    // 0x8017BB10: nop

L_8017BB14:
    // 0x8017BB14: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8017BB18: jal         0x800D54C8
    // 0x8017BB1C: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    spX2Init_recomp(rdram, ctx);
        goto after_3;
    // 0x8017BB1C: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    after_3:
    // 0x8017BB20: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017BB24: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017BB28: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8017BB2C: addiu       $t0, $t0, 0x3B00
    ctx->r8 = ADD32(ctx->r8, 0X3B00);
    // 0x8017BB30: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x8017BB34: lbu         $t1, 0x0($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X0);
    // 0x8017BB38: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8017BB3C: addiu       $a0, $a0, 0x5F10
    ctx->r4 = ADD32(ctx->r4, 0X5F10);
    // 0x8017BB40: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x8017BB44: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8017BB48: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8017BB4C: jal         0x800C6C6C
    // 0x8017BB50: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    func_800C6C6C(rdram, ctx);
        goto after_4;
    // 0x8017BB50: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    after_4:
    // 0x8017BB54: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017BB58: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8017BB5C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8017BB60: addiu       $t2, $t2, 0x3B00
    ctx->r10 = ADD32(ctx->r10, 0X3B00);
    // 0x8017BB64: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x8017BB68: lbu         $t3, 0x3($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X3);
    // 0x8017BB6C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8017BB70: addiu       $a0, $a0, 0x61F4
    ctx->r4 = ADD32(ctx->r4, 0X61F4);
    // 0x8017BB74: addiu       $a1, $zero, 0x11D
    ctx->r5 = ADD32(0, 0X11D);
    // 0x8017BB78: addiu       $a2, $zero, 0xB2
    ctx->r6 = ADD32(0, 0XB2);
    // 0x8017BB7C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8017BB80: jal         0x800C6C6C
    // 0x8017BB84: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    func_800C6C6C(rdram, ctx);
        goto after_5;
    // 0x8017BB84: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    after_5:
    // 0x8017BB88: jal         0x800C6D5C
    // 0x8017BB8C: nop

    func_800C6D5C(rdram, ctx);
        goto after_6;
    // 0x8017BB8C: nop

    after_6:
    // 0x8017BB90: b           L_8017BC24
    // 0x8017BB94: nop

        goto L_8017BC24;
    // 0x8017BB94: nop

L_8017BB98:
    // 0x8017BB98: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8017BB9C: jal         0x800D54C8
    // 0x8017BBA0: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    spX2Init_recomp(rdram, ctx);
        goto after_7;
    // 0x8017BBA0: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    after_7:
    // 0x8017BBA4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017BBA8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017BBAC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8017BBB0: addiu       $t4, $t4, 0x3B00
    ctx->r12 = ADD32(ctx->r12, 0X3B00);
    // 0x8017BBB4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8017BBB8: lbu         $t5, 0x0($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X0);
    // 0x8017BBBC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8017BBC0: addiu       $a0, $a0, 0x5F10
    ctx->r4 = ADD32(ctx->r4, 0X5F10);
    // 0x8017BBC4: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x8017BBC8: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8017BBCC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8017BBD0: bgez        $t5, L_8017BBE0
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8017BBD4: sra         $t6, $t5, 1
        ctx->r14 = S32(SIGNED(ctx->r13) >> 1);
            goto L_8017BBE0;
    }
    // 0x8017BBD4: sra         $t6, $t5, 1
    ctx->r14 = S32(SIGNED(ctx->r13) >> 1);
    // 0x8017BBD8: addiu       $at, $t5, 0x1
    ctx->r1 = ADD32(ctx->r13, 0X1);
    // 0x8017BBDC: sra         $t6, $at, 1
    ctx->r14 = S32(SIGNED(ctx->r1) >> 1);
L_8017BBE0:
    // 0x8017BBE0: jal         0x800C6C6C
    // 0x8017BBE4: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    func_800C6C6C(rdram, ctx);
        goto after_8;
    // 0x8017BBE4: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_8:
    // 0x8017BBE8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017BBEC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8017BBF0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017BBF4: addiu       $t7, $t7, 0x3B00
    ctx->r15 = ADD32(ctx->r15, 0X3B00);
    // 0x8017BBF8: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x8017BBFC: lbu         $t8, 0x3($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X3);
    // 0x8017BC00: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8017BC04: addiu       $a0, $a0, 0x61F4
    ctx->r4 = ADD32(ctx->r4, 0X61F4);
    // 0x8017BC08: addiu       $a1, $zero, 0x11D
    ctx->r5 = ADD32(0, 0X11D);
    // 0x8017BC0C: addiu       $a2, $zero, 0xB2
    ctx->r6 = ADD32(0, 0XB2);
    // 0x8017BC10: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8017BC14: jal         0x800C6C6C
    // 0x8017BC18: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    func_800C6C6C(rdram, ctx);
        goto after_9;
    // 0x8017BC18: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_9:
    // 0x8017BC1C: jal         0x800C6D5C
    // 0x8017BC20: nop

    func_800C6D5C(rdram, ctx);
        goto after_10;
    // 0x8017BC20: nop

    after_10:
L_8017BC24:
    // 0x8017BC24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8017BC28: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017BC2C: jr          $ra
    // 0x8017BC30: nop

    return;
    // 0x8017BC30: nop

;}
RECOMP_FUNC void func_8017BC34_041650(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017BC34: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8017BC38: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8017BC3C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8017BC40: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8017BC44: addiu       $t6, $t6, 0x3C00
    ctx->r14 = ADD32(ctx->r14, 0X3C00);
    // 0x8017BC48: lw          $s0, 0x0($t6)
    ctx->r16 = MEM_W(ctx->r14, 0X0);
    // 0x8017BC4C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8017BC50: beq         $s0, $at, L_8017BC78
    if (ctx->r16 == ctx->r1) {
        // 0x8017BC54: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8017BC78;
    }
    // 0x8017BC54: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8017BC58: beq         $s0, $at, L_8017BEAC
    if (ctx->r16 == ctx->r1) {
        // 0x8017BC5C: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8017BEAC;
    }
    // 0x8017BC5C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8017BC60: beq         $s0, $at, L_8017BEAC
    if (ctx->r16 == ctx->r1) {
        // 0x8017BC64: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_8017BEAC;
    }
    // 0x8017BC64: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8017BC68: beq         $s0, $at, L_8017BEAC
    if (ctx->r16 == ctx->r1) {
        // 0x8017BC6C: nop
    
            goto L_8017BEAC;
    }
    // 0x8017BC6C: nop

    // 0x8017BC70: b           L_8017C0C8
    // 0x8017BC74: nop

        goto L_8017C0C8;
    // 0x8017BC74: nop

L_8017BC78:
    // 0x8017BC78: jal         0x800C7AD0
    // 0x8017BC7C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800C7AD0(rdram, ctx);
        goto after_0;
    // 0x8017BC7C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x8017BC80: addiu       $a0, $zero, 0x36
    ctx->r4 = ADD32(0, 0X36);
    // 0x8017BC84: jal         0x800C7A60
    // 0x8017BC88: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C7A60(rdram, ctx);
        goto after_1;
    // 0x8017BC88: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8017BC8C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017BC90: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017BC94: addiu       $a1, $a1, -0x37F0
    ctx->r5 = ADD32(ctx->r5, -0X37F0);
    // 0x8017BC98: jal         0x800D87E4
    // 0x8017BC9C: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_2;
    // 0x8017BC9C: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_2:
    // 0x8017BCA0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8017BCA4: addiu       $t7, $t7, 0x3B00
    ctx->r15 = ADD32(ctx->r15, 0X3B00);
    // 0x8017BCA8: lbu         $t8, 0x1($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X1);
    // 0x8017BCAC: bne         $t8, $zero, L_8017BCF8
    if (ctx->r24 != 0) {
        // 0x8017BCB0: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_8017BCF8;
    }
    // 0x8017BCB0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8017BCB4: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x8017BCB8: mtc1        $at, $f15
    ctx->f_odd[(15 - 1) * 2] = ctx->r1;
    // 0x8017BCBC: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8017BCC0: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8017BCC4: jal         0x800C7A88
    // 0x8017BCC8: nop

    func_800C7A88(rdram, ctx);
        goto after_3;
    // 0x8017BCC8: nop

    after_3:
    // 0x8017BCCC: addiu       $t9, $zero, 0xC8
    ctx->r25 = ADD32(0, 0XC8);
    // 0x8017BCD0: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x8017BCD4: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8017BCD8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8017BCDC: addiu       $a0, $zero, 0xF0
    ctx->r4 = ADD32(0, 0XF0);
    // 0x8017BCE0: addiu       $a1, $zero, 0x159
    ctx->r5 = ADD32(0, 0X159);
    // 0x8017BCE4: addiu       $a2, $zero, 0xC8
    ctx->r6 = ADD32(0, 0XC8);
    // 0x8017BCE8: jal         0x8017C0DC
    // 0x8017BCEC: addiu       $a3, $zero, 0xC8
    ctx->r7 = ADD32(0, 0XC8);
    func_8017C0DC_041650(rdram, ctx);
        goto after_4;
    // 0x8017BCEC: addiu       $a3, $zero, 0xC8
    ctx->r7 = ADD32(0, 0XC8);
    after_4:
    // 0x8017BCF0: b           L_8017BD3C
    // 0x8017BCF4: nop

        goto L_8017BD3C;
    // 0x8017BCF4: nop

L_8017BCF8:
    // 0x8017BCF8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8017BCFC: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x8017BD00: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x8017BD04: mtc1        $at, $f15
    ctx->f_odd[(15 - 1) * 2] = ctx->r1;
    // 0x8017BD08: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8017BD0C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8017BD10: jal         0x800C7A88
    // 0x8017BD14: nop

    func_800C7A88(rdram, ctx);
        goto after_5;
    // 0x8017BD14: nop

    after_5:
    // 0x8017BD18: addiu       $t1, $zero, 0xC8
    ctx->r9 = ADD32(0, 0XC8);
    // 0x8017BD1C: addiu       $t2, $zero, 0xAA
    ctx->r10 = ADD32(0, 0XAA);
    // 0x8017BD20: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8017BD24: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8017BD28: addiu       $a0, $zero, 0xF0
    ctx->r4 = ADD32(0, 0XF0);
    // 0x8017BD2C: addiu       $a1, $zero, 0x15D
    ctx->r5 = ADD32(0, 0X15D);
    // 0x8017BD30: addiu       $a2, $zero, 0xC8
    ctx->r6 = ADD32(0, 0XC8);
    // 0x8017BD34: jal         0x8017C0DC
    // 0x8017BD38: addiu       $a3, $zero, 0xC8
    ctx->r7 = ADD32(0, 0XC8);
    func_8017C0DC_041650(rdram, ctx);
        goto after_6;
    // 0x8017BD38: addiu       $a3, $zero, 0xC8
    ctx->r7 = ADD32(0, 0XC8);
    after_6:
L_8017BD3C:
    // 0x8017BD3C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017BD40: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017BD44: addiu       $a1, $a1, -0x37E4
    ctx->r5 = ADD32(ctx->r5, -0X37E4);
    // 0x8017BD48: jal         0x800D87E4
    // 0x8017BD4C: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_7;
    // 0x8017BD4C: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_7:
    // 0x8017BD50: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017BD54: addiu       $t3, $t3, 0x3B00
    ctx->r11 = ADD32(ctx->r11, 0X3B00);
    // 0x8017BD58: lbu         $t4, 0x1($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X1);
    // 0x8017BD5C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8017BD60: bne         $t4, $at, L_8017BDAC
    if (ctx->r12 != ctx->r1) {
        // 0x8017BD64: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_8017BDAC;
    }
    // 0x8017BD64: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8017BD68: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x8017BD6C: mtc1        $at, $f15
    ctx->f_odd[(15 - 1) * 2] = ctx->r1;
    // 0x8017BD70: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8017BD74: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8017BD78: jal         0x800C7A88
    // 0x8017BD7C: nop

    func_800C7A88(rdram, ctx);
        goto after_8;
    // 0x8017BD7C: nop

    after_8:
    // 0x8017BD80: addiu       $t5, $zero, 0xC8
    ctx->r13 = ADD32(0, 0XC8);
    // 0x8017BD84: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8017BD88: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8017BD8C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8017BD90: addiu       $a0, $zero, 0xB8
    ctx->r4 = ADD32(0, 0XB8);
    // 0x8017BD94: addiu       $a1, $zero, 0x179
    ctx->r5 = ADD32(0, 0X179);
    // 0x8017BD98: addiu       $a2, $zero, 0xC8
    ctx->r6 = ADD32(0, 0XC8);
    // 0x8017BD9C: jal         0x8017C0DC
    // 0x8017BDA0: addiu       $a3, $zero, 0xC8
    ctx->r7 = ADD32(0, 0XC8);
    func_8017C0DC_041650(rdram, ctx);
        goto after_9;
    // 0x8017BDA0: addiu       $a3, $zero, 0xC8
    ctx->r7 = ADD32(0, 0XC8);
    after_9:
    // 0x8017BDA4: b           L_8017BDF0
    // 0x8017BDA8: nop

        goto L_8017BDF0;
    // 0x8017BDA8: nop

L_8017BDAC:
    // 0x8017BDAC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8017BDB0: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x8017BDB4: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x8017BDB8: mtc1        $at, $f15
    ctx->f_odd[(15 - 1) * 2] = ctx->r1;
    // 0x8017BDBC: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8017BDC0: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8017BDC4: jal         0x800C7A88
    // 0x8017BDC8: nop

    func_800C7A88(rdram, ctx);
        goto after_10;
    // 0x8017BDC8: nop

    after_10:
    // 0x8017BDCC: addiu       $t7, $zero, 0xC8
    ctx->r15 = ADD32(0, 0XC8);
    // 0x8017BDD0: addiu       $t8, $zero, 0xAA
    ctx->r24 = ADD32(0, 0XAA);
    // 0x8017BDD4: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8017BDD8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8017BDDC: addiu       $a0, $zero, 0xB8
    ctx->r4 = ADD32(0, 0XB8);
    // 0x8017BDE0: addiu       $a1, $zero, 0x17D
    ctx->r5 = ADD32(0, 0X17D);
    // 0x8017BDE4: addiu       $a2, $zero, 0xC8
    ctx->r6 = ADD32(0, 0XC8);
    // 0x8017BDE8: jal         0x8017C0DC
    // 0x8017BDEC: addiu       $a3, $zero, 0xC8
    ctx->r7 = ADD32(0, 0XC8);
    func_8017C0DC_041650(rdram, ctx);
        goto after_11;
    // 0x8017BDEC: addiu       $a3, $zero, 0xC8
    ctx->r7 = ADD32(0, 0XC8);
    after_11:
L_8017BDF0:
    // 0x8017BDF0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017BDF4: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017BDF8: addiu       $a1, $a1, -0x37D0
    ctx->r5 = ADD32(ctx->r5, -0X37D0);
    // 0x8017BDFC: jal         0x800D87E4
    // 0x8017BE00: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_12;
    // 0x8017BE00: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_12:
    // 0x8017BE04: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8017BE08: addiu       $t9, $t9, 0x3B00
    ctx->r25 = ADD32(ctx->r25, 0X3B00);
    // 0x8017BE0C: lbu         $t0, 0x1($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X1);
    // 0x8017BE10: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8017BE14: bne         $t0, $at, L_8017BE60
    if (ctx->r8 != ctx->r1) {
        // 0x8017BE18: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_8017BE60;
    }
    // 0x8017BE18: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8017BE1C: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x8017BE20: mtc1        $at, $f15
    ctx->f_odd[(15 - 1) * 2] = ctx->r1;
    // 0x8017BE24: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8017BE28: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8017BE2C: jal         0x800C7A88
    // 0x8017BE30: nop

    func_800C7A88(rdram, ctx);
        goto after_13;
    // 0x8017BE30: nop

    after_13:
    // 0x8017BE34: addiu       $t1, $zero, 0xC8
    ctx->r9 = ADD32(0, 0XC8);
    // 0x8017BE38: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x8017BE3C: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8017BE40: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8017BE44: addiu       $a0, $zero, 0xE0
    ctx->r4 = ADD32(0, 0XE0);
    // 0x8017BE48: addiu       $a1, $zero, 0x199
    ctx->r5 = ADD32(0, 0X199);
    // 0x8017BE4C: addiu       $a2, $zero, 0xC8
    ctx->r6 = ADD32(0, 0XC8);
    // 0x8017BE50: jal         0x8017C0DC
    // 0x8017BE54: addiu       $a3, $zero, 0xC8
    ctx->r7 = ADD32(0, 0XC8);
    func_8017C0DC_041650(rdram, ctx);
        goto after_14;
    // 0x8017BE54: addiu       $a3, $zero, 0xC8
    ctx->r7 = ADD32(0, 0XC8);
    after_14:
    // 0x8017BE58: b           L_8017C0C8
    // 0x8017BE5C: nop

        goto L_8017C0C8;
    // 0x8017BE5C: nop

L_8017BE60:
    // 0x8017BE60: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8017BE64: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x8017BE68: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x8017BE6C: mtc1        $at, $f15
    ctx->f_odd[(15 - 1) * 2] = ctx->r1;
    // 0x8017BE70: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8017BE74: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8017BE78: jal         0x800C7A88
    // 0x8017BE7C: nop

    func_800C7A88(rdram, ctx);
        goto after_15;
    // 0x8017BE7C: nop

    after_15:
    // 0x8017BE80: addiu       $t3, $zero, 0xC8
    ctx->r11 = ADD32(0, 0XC8);
    // 0x8017BE84: addiu       $t4, $zero, 0xAA
    ctx->r12 = ADD32(0, 0XAA);
    // 0x8017BE88: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8017BE8C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8017BE90: addiu       $a0, $zero, 0xE0
    ctx->r4 = ADD32(0, 0XE0);
    // 0x8017BE94: addiu       $a1, $zero, 0x19D
    ctx->r5 = ADD32(0, 0X19D);
    // 0x8017BE98: addiu       $a2, $zero, 0xC8
    ctx->r6 = ADD32(0, 0XC8);
    // 0x8017BE9C: jal         0x8017C0DC
    // 0x8017BEA0: addiu       $a3, $zero, 0xC8
    ctx->r7 = ADD32(0, 0XC8);
    func_8017C0DC_041650(rdram, ctx);
        goto after_16;
    // 0x8017BEA0: addiu       $a3, $zero, 0xC8
    ctx->r7 = ADD32(0, 0XC8);
    after_16:
    // 0x8017BEA4: b           L_8017C0C8
    // 0x8017BEA8: nop

        goto L_8017C0C8;
    // 0x8017BEA8: nop

L_8017BEAC:
    // 0x8017BEAC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8017BEB0: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x8017BEB4: mtc1        $at, $f15
    ctx->f_odd[(15 - 1) * 2] = ctx->r1;
    // 0x8017BEB8: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8017BEBC: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8017BEC0: jal         0x800C7A88
    // 0x8017BEC4: nop

    func_800C7A88(rdram, ctx);
        goto after_17;
    // 0x8017BEC4: nop

    after_17:
    // 0x8017BEC8: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017BECC: addiu       $t5, $t5, 0x3B00
    ctx->r13 = ADD32(ctx->r13, 0X3B00);
    // 0x8017BED0: lbu         $t6, 0x2($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X2);
    // 0x8017BED4: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8017BED8: bne         $t6, $at, L_8017BFF4
    if (ctx->r14 != ctx->r1) {
        // 0x8017BEDC: nop
    
            goto L_8017BFF4;
    }
    // 0x8017BEDC: nop

    // 0x8017BEE0: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_8017BEE4:
    // 0x8017BEE4: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8017BEE8: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x8017BEEC: lhu         $t7, -0x4530($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X4530);
    // 0x8017BEF0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8017BEF4: sllv        $t0, $t9, $t8
    ctx->r8 = S32(ctx->r25 << (ctx->r24 & 31));
    // 0x8017BEF8: and         $t1, $t7, $t0
    ctx->r9 = ctx->r15 & ctx->r8;
    // 0x8017BEFC: beq         $t1, $zero, L_8017BF60
    if (ctx->r9 == 0) {
        // 0x8017BF00: nop
    
            goto L_8017BF60;
    }
    // 0x8017BF00: nop

    // 0x8017BF04: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017BF08: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017BF0C: addiu       $a1, $a1, -0x37C0
    ctx->r5 = ADD32(ctx->r5, -0X37C0);
    // 0x8017BF10: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    // 0x8017BF14: jal         0x800D87E4
    // 0x8017BF18: addiu       $a2, $t8, 0x1
    ctx->r6 = ADD32(ctx->r24, 0X1);
    sprintf_recomp(rdram, ctx);
        goto after_18;
    // 0x8017BF18: addiu       $a2, $t8, 0x1
    ctx->r6 = ADD32(ctx->r24, 0X1);
    after_18:
    // 0x8017BF1C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8017BF20: addiu       $t3, $zero, 0xC8
    ctx->r11 = ADD32(0, 0XC8);
    // 0x8017BF24: addiu       $t4, $zero, 0xAA
    ctx->r12 = ADD32(0, 0XAA);
    // 0x8017BF28: sll         $t2, $a1, 3
    ctx->r10 = S32(ctx->r5 << 3);
    // 0x8017BF2C: addu        $t2, $t2, $a1
    ctx->r10 = ADD32(ctx->r10, ctx->r5);
    // 0x8017BF30: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8017BF34: subu        $t2, $t2, $a1
    ctx->r10 = SUB32(ctx->r10, ctx->r5);
    // 0x8017BF38: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    // 0x8017BF3C: addiu       $a1, $a1, 0x11C
    ctx->r5 = ADD32(ctx->r5, 0X11C);
    // 0x8017BF40: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8017BF44: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8017BF48: addiu       $a0, $zero, 0x8C
    ctx->r4 = ADD32(0, 0X8C);
    // 0x8017BF4C: addiu       $a2, $zero, 0xC8
    ctx->r6 = ADD32(0, 0XC8);
    // 0x8017BF50: jal         0x8017C0DC
    // 0x8017BF54: addiu       $a3, $zero, 0xC8
    ctx->r7 = ADD32(0, 0XC8);
    func_8017C0DC_041650(rdram, ctx);
        goto after_19;
    // 0x8017BF54: addiu       $a3, $zero, 0xC8
    ctx->r7 = ADD32(0, 0XC8);
    after_19:
    // 0x8017BF58: b           L_8017BFD8
    // 0x8017BF5C: nop

        goto L_8017BFD8;
    // 0x8017BF5C: nop

L_8017BF60:
    // 0x8017BF60: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8017BF64: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017BF68: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017BF6C: addiu       $a1, $a1, -0x37B4
    ctx->r5 = ADD32(ctx->r5, -0X37B4);
    // 0x8017BF70: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    // 0x8017BF74: jal         0x800D87E4
    // 0x8017BF78: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    sprintf_recomp(rdram, ctx);
        goto after_20;
    // 0x8017BF78: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    after_20:
    // 0x8017BF7C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8017BF80: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x8017BF84: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x8017BF88: mtc1        $at, $f15
    ctx->f_odd[(15 - 1) * 2] = ctx->r1;
    // 0x8017BF8C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8017BF90: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8017BF94: jal         0x800C7A88
    // 0x8017BF98: nop

    func_800C7A88(rdram, ctx);
        goto after_21;
    // 0x8017BF98: nop

    after_21:
    // 0x8017BF9C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8017BFA0: addiu       $t6, $zero, 0xAA
    ctx->r14 = ADD32(0, 0XAA);
    // 0x8017BFA4: addiu       $t9, $zero, 0x64
    ctx->r25 = ADD32(0, 0X64);
    // 0x8017BFA8: sll         $t5, $a1, 3
    ctx->r13 = S32(ctx->r5 << 3);
    // 0x8017BFAC: addu        $t5, $t5, $a1
    ctx->r13 = ADD32(ctx->r13, ctx->r5);
    // 0x8017BFB0: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8017BFB4: subu        $t5, $t5, $a1
    ctx->r13 = SUB32(ctx->r13, ctx->r5);
    // 0x8017BFB8: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
    // 0x8017BFBC: addiu       $a1, $a1, 0x120
    ctx->r5 = ADD32(ctx->r5, 0X120);
    // 0x8017BFC0: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8017BFC4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8017BFC8: addiu       $a0, $zero, 0x8C
    ctx->r4 = ADD32(0, 0X8C);
    // 0x8017BFCC: addiu       $a2, $zero, 0xB6
    ctx->r6 = ADD32(0, 0XB6);
    // 0x8017BFD0: jal         0x8017C0DC
    // 0x8017BFD4: addiu       $a3, $zero, 0x6D
    ctx->r7 = ADD32(0, 0X6D);
    func_8017C0DC_041650(rdram, ctx);
        goto after_22;
    // 0x8017BFD4: addiu       $a3, $zero, 0x6D
    ctx->r7 = ADD32(0, 0X6D);
    after_22:
L_8017BFD8:
    // 0x8017BFD8: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8017BFDC: addiu       $t0, $t7, 0x1
    ctx->r8 = ADD32(ctx->r15, 0X1);
    // 0x8017BFE0: sltiu       $at, $t0, 0x4
    ctx->r1 = ctx->r8 < 0X4 ? 1 : 0;
    // 0x8017BFE4: bne         $at, $zero, L_8017BEE4
    if (ctx->r1 != 0) {
        // 0x8017BFE8: sw          $t0, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r8;
            goto L_8017BEE4;
    }
    // 0x8017BFE8: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x8017BFEC: b           L_8017C078
    // 0x8017BFF0: nop

        goto L_8017C078;
    // 0x8017BFF0: nop

L_8017BFF4:
    // 0x8017BFF4: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_8017BFF8:
    // 0x8017BFF8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8017BFFC: addiu       $t1, $t1, 0x3B00
    ctx->r9 = ADD32(ctx->r9, 0X3B00);
    // 0x8017C000: lbu         $t8, 0x2($t1)
    ctx->r24 = MEM_BU(ctx->r9, 0X2);
    // 0x8017C004: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8017C008: bne         $t8, $t2, L_8017C064
    if (ctx->r24 != ctx->r10) {
        // 0x8017C00C: nop
    
            goto L_8017C064;
    }
    // 0x8017C00C: nop

    // 0x8017C010: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017C014: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017C018: addiu       $a1, $a1, -0x3798
    ctx->r5 = ADD32(ctx->r5, -0X3798);
    // 0x8017C01C: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    // 0x8017C020: jal         0x800D87E4
    // 0x8017C024: addiu       $a2, $t2, 0x1
    ctx->r6 = ADD32(ctx->r10, 0X1);
    sprintf_recomp(rdram, ctx);
        goto after_23;
    // 0x8017C024: addiu       $a2, $t2, 0x1
    ctx->r6 = ADD32(ctx->r10, 0X1);
    after_23:
    // 0x8017C028: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8017C02C: addiu       $t4, $zero, 0xC8
    ctx->r12 = ADD32(0, 0XC8);
    // 0x8017C030: addiu       $t5, $zero, 0xAA
    ctx->r13 = ADD32(0, 0XAA);
    // 0x8017C034: sll         $t3, $a1, 3
    ctx->r11 = S32(ctx->r5 << 3);
    // 0x8017C038: addu        $t3, $t3, $a1
    ctx->r11 = ADD32(ctx->r11, ctx->r5);
    // 0x8017C03C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8017C040: subu        $t3, $t3, $a1
    ctx->r11 = SUB32(ctx->r11, ctx->r5);
    // 0x8017C044: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    // 0x8017C048: addiu       $a1, $a1, 0x11C
    ctx->r5 = ADD32(ctx->r5, 0X11C);
    // 0x8017C04C: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8017C050: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8017C054: addiu       $a0, $zero, 0x8C
    ctx->r4 = ADD32(0, 0X8C);
    // 0x8017C058: addiu       $a2, $zero, 0xC8
    ctx->r6 = ADD32(0, 0XC8);
    // 0x8017C05C: jal         0x8017C0DC
    // 0x8017C060: addiu       $a3, $zero, 0xC8
    ctx->r7 = ADD32(0, 0XC8);
    func_8017C0DC_041650(rdram, ctx);
        goto after_24;
    // 0x8017C060: addiu       $a3, $zero, 0xC8
    ctx->r7 = ADD32(0, 0XC8);
    after_24:
L_8017C064:
    // 0x8017C064: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8017C068: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x8017C06C: sltiu       $at, $t9, 0x4
    ctx->r1 = ctx->r25 < 0X4 ? 1 : 0;
    // 0x8017C070: bne         $at, $zero, L_8017BFF8
    if (ctx->r1 != 0) {
        // 0x8017C074: sw          $t9, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r25;
            goto L_8017BFF8;
    }
    // 0x8017C074: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
L_8017C078:
    // 0x8017C078: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8017C07C: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x8017C080: mtc1        $at, $f15
    ctx->f_odd[(15 - 1) * 2] = ctx->r1;
    // 0x8017C084: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8017C088: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8017C08C: jal         0x800C7A88
    // 0x8017C090: nop

    func_800C7A88(rdram, ctx);
        goto after_25;
    // 0x8017C090: nop

    after_25:
    // 0x8017C094: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8017C098: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017C09C: addiu       $a1, $a1, -0x378C
    ctx->r5 = ADD32(ctx->r5, -0X378C);
    // 0x8017C0A0: jal         0x800D87E4
    // 0x8017C0A4: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_26;
    // 0x8017C0A4: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_26:
    // 0x8017C0A8: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8017C0AC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8017C0B0: addiu       $a0, $zero, 0xAC
    ctx->r4 = ADD32(0, 0XAC);
    // 0x8017C0B4: addiu       $a1, $zero, 0x1AE
    ctx->r5 = ADD32(0, 0X1AE);
    // 0x8017C0B8: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8017C0BC: addiu       $a3, $zero, 0xB6
    ctx->r7 = ADD32(0, 0XB6);
    // 0x8017C0C0: jal         0x8017C0DC
    // 0x8017C0C4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_8017C0DC_041650(rdram, ctx);
        goto after_27;
    // 0x8017C0C4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_27:
L_8017C0C8:
    // 0x8017C0C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8017C0CC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8017C0D0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8017C0D4: jr          $ra
    // 0x8017C0D8: nop

    return;
    // 0x8017C0D8: nop

;}
RECOMP_FUNC void func_8017C0DC_041650(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017C0DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017C0E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017C0E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8017C0E8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8017C0EC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8017C0F0: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8017C0F4: lbu         $a1, 0x27($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X27);
    // 0x8017C0F8: lbu         $a3, 0x2F($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X2F);
    // 0x8017C0FC: lbu         $a0, 0x23($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X23);
    // 0x8017C100: jal         0x800C7A9C
    // 0x8017C104: lbu         $a2, 0x2B($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X2B);
    func_800C7A9C(rdram, ctx);
        goto after_0;
    // 0x8017C104: lbu         $a2, 0x2B($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X2B);
    after_0:
    // 0x8017C108: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8017C10C: jal         0x800C7A74
    // 0x8017C110: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_800C7A74(rdram, ctx);
        goto after_1;
    // 0x8017C110: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x8017C114: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8017C118: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8017C11C: addiu       $a1, $a1, 0x3B40
    ctx->r5 = ADD32(ctx->r5, 0X3B40);
    // 0x8017C120: jal         0x800C767C
    // 0x8017C124: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    func_800C767C(rdram, ctx);
        goto after_2;
    // 0x8017C124: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    after_2:
    // 0x8017C128: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017C12C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017C130: jr          $ra
    // 0x8017C134: nop

    return;
    // 0x8017C134: nop

;}
RECOMP_FUNC void func_8017C138_041650(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017C138: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x8017C13C: lw          $t6, -0x4514($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4514);
    // 0x8017C140: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8017C144: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8017C148: sw          $t6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r14;
    // 0x8017C14C: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x8017C150: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8017C154: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8017C158: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8017C15C: sw          $t7, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r15;
    // 0x8017C160: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x8017C164: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8017C168: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x8017C16C: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x8017C170: lui         $t3, 0xD900
    ctx->r11 = S32(0XD900 << 16);
    // 0x8017C174: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x8017C178: lw          $t1, -0x4514($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4514);
    // 0x8017C17C: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x8017C180: lui         $t8, 0xDE00
    ctx->r24 = S32(0XDE00 << 16);
    // 0x8017C184: sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
    // 0x8017C188: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x8017C18C: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x8017C190: sw          $t2, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r10;
    // 0x8017C194: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x8017C198: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x8017C19C: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x8017C1A0: addiu       $t0, $t0, -0x51D0
    ctx->r8 = ADD32(ctx->r8, -0X51D0);
    // 0x8017C1A4: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
    // 0x8017C1A8: lw          $t6, -0x4514($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4514);
    // 0x8017C1AC: lui         $t2, 0x8011
    ctx->r10 = S32(0X8011 << 16);
    // 0x8017C1B0: lui         $t4, 0xE300
    ctx->r12 = S32(0XE300 << 16);
    // 0x8017C1B4: sw          $t6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r14;
    // 0x8017C1B8: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x8017C1BC: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8017C1C0: sw          $t7, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r15;
    // 0x8017C1C4: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8017C1C8: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x8017C1CC: ori         $t4, $t4, 0x1001
    ctx->r12 = ctx->r12 | 0X1001;
    // 0x8017C1D0: ori         $t6, $zero, 0x8000
    ctx->r14 = 0 | 0X8000;
    // 0x8017C1D4: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x8017C1D8: lw          $t2, -0x4514($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4514);
    // 0x8017C1DC: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x8017C1E0: lui         $t0, 0xE700
    ctx->r8 = S32(0XE700 << 16);
    // 0x8017C1E4: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    // 0x8017C1E8: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x8017C1EC: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x8017C1F0: sw          $t3, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r11;
    // 0x8017C1F4: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x8017C1F8: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x8017C1FC: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x8017C200: lw          $t8, -0x4514($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4514);
    // 0x8017C204: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x8017C208: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8017C20C: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8017C210: sw          $t9, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r25;
    // 0x8017C214: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x8017C218: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x8017C21C: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x8017C220: sw          $zero, 0x54($sp)
    MEM_W(0X54, ctx->r29) = 0;
L_8017C224:
    // 0x8017C224: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x8017C228: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8017C22C: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8017C230: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8017C234: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8017C238: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x8017C23C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8017C240: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8017C244: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8017C248: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8017C24C: lhu         $t5, -0x2A28($t5)
    ctx->r13 = MEM_HU(ctx->r13, -0X2A28);
    // 0x8017C250: andi        $t6, $t5, 0x8000
    ctx->r14 = ctx->r13 & 0X8000;
    // 0x8017C254: beq         $t6, $zero, L_8017C3A0
    if (ctx->r14 == 0) {
        // 0x8017C258: nop
    
            goto L_8017C3A0;
    }
    // 0x8017C258: nop

    // 0x8017C25C: andi        $t7, $t5, 0x800
    ctx->r15 = ctx->r13 & 0X800;
    // 0x8017C260: beq         $t7, $zero, L_8017C3A0
    if (ctx->r15 == 0) {
        // 0x8017C264: nop
    
            goto L_8017C3A0;
    }
    // 0x8017C264: nop

    // 0x8017C268: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x8017C26C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8017C270: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x8017C274: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8017C278: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8017C27C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8017C280: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8017C284: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8017C288: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8017C28C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8017C290: addu        $s0, $s0, $t9
    ctx->r16 = ADD32(ctx->r16, ctx->r25);
    // 0x8017C294: lw          $s0, -0x2A24($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X2A24);
    // 0x8017C298: beq         $s0, $at, L_8017C2B0
    if (ctx->r16 == ctx->r1) {
        // 0x8017C29C: addiu       $at, $zero, 0x11
        ctx->r1 = ADD32(0, 0X11);
            goto L_8017C2B0;
    }
    // 0x8017C29C: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x8017C2A0: beq         $s0, $at, L_8017C32C
    if (ctx->r16 == ctx->r1) {
        // 0x8017C2A4: nop
    
            goto L_8017C32C;
    }
    // 0x8017C2A4: nop

    // 0x8017C2A8: b           L_8017C3A0
    // 0x8017C2AC: nop

        goto L_8017C3A0;
    // 0x8017C2AC: nop

L_8017C2B0:
    // 0x8017C2B0: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x8017C2B4: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8017C2B8: addiu       $t3, $t3, -0x2A28
    ctx->r11 = ADD32(ctx->r11, -0X2A28);
    // 0x8017C2BC: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8017C2C0: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8017C2C4: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8017C2C8: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x8017C2CC: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8017C2D0: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8017C2D4: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8017C2D8: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x8017C2DC: lwc1        $f4, 0x64($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X64);
    // 0x8017C2E0: lw          $a3, 0x60($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X60);
    // 0x8017C2E4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017C2E8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8017C2EC: lwc1        $f6, 0x68($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X68);
    // 0x8017C2F0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8017C2F4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017C2F8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8017C2FC: addiu       $t2, $t1, 0xA4
    ctx->r10 = ADD32(ctx->r9, 0XA4);
    // 0x8017C300: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8017C304: addiu       $a0, $a0, 0x3390
    ctx->r4 = ADD32(ctx->r4, 0X3390);
    // 0x8017C308: addu        $a2, $t2, $t3
    ctx->r6 = ADD32(ctx->r10, ctx->r11);
    // 0x8017C30C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8017C310: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8017C314: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8017C318: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x8017C31C: jal         0x800C6868
    // 0x8017C320: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    func_800C6868(rdram, ctx);
        goto after_0;
    // 0x8017C320: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    after_0:
    // 0x8017C324: b           L_8017C3A0
    // 0x8017C328: nop

        goto L_8017C3A0;
    // 0x8017C328: nop

L_8017C32C:
    // 0x8017C32C: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x8017C330: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8017C334: addiu       $t8, $t8, -0x2A28
    ctx->r24 = ADD32(ctx->r24, -0X2A28);
    // 0x8017C338: sll         $t5, $t6, 2
    ctx->r13 = S32(ctx->r14 << 2);
    // 0x8017C33C: addu        $t5, $t5, $t6
    ctx->r13 = ADD32(ctx->r13, ctx->r14);
    // 0x8017C340: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8017C344: subu        $t5, $t5, $t6
    ctx->r13 = SUB32(ctx->r13, ctx->r14);
    // 0x8017C348: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8017C34C: addu        $t5, $t5, $t6
    ctx->r13 = ADD32(ctx->r13, ctx->r14);
    // 0x8017C350: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8017C354: addu        $t9, $t5, $t8
    ctx->r25 = ADD32(ctx->r13, ctx->r24);
    // 0x8017C358: lwc1        $f18, 0x64($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X64);
    // 0x8017C35C: lw          $a3, 0x60($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X60);
    // 0x8017C360: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017C364: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x8017C368: lwc1        $f4, 0x68($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X68);
    // 0x8017C36C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017C370: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8017C374: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017C378: addiu       $t7, $t5, 0xA4
    ctx->r15 = ADD32(ctx->r13, 0XA4);
    // 0x8017C37C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8017C380: addiu       $a0, $a0, 0x4020
    ctx->r4 = ADD32(ctx->r4, 0X4020);
    // 0x8017C384: addu        $a2, $t7, $t8
    ctx->r6 = ADD32(ctx->r15, ctx->r24);
    // 0x8017C388: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8017C38C: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x8017C390: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x8017C394: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x8017C398: jal         0x800C6868
    // 0x8017C39C: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    func_800C6868(rdram, ctx);
        goto after_1;
    // 0x8017C39C: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    after_1:
L_8017C3A0:
    // 0x8017C3A0: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x8017C3A4: addiu       $t2, $t0, 0x1
    ctx->r10 = ADD32(ctx->r8, 0X1);
    // 0x8017C3A8: slti        $at, $t2, 0x30
    ctx->r1 = SIGNED(ctx->r10) < 0X30 ? 1 : 0;
    // 0x8017C3AC: bne         $at, $zero, L_8017C224
    if (ctx->r1 != 0) {
        // 0x8017C3B0: sw          $t2, 0x54($sp)
        MEM_W(0X54, ctx->r29) = ctx->r10;
            goto L_8017C224;
    }
    // 0x8017C3B0: sw          $t2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r10;
    // 0x8017C3B4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8017C3B8: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8017C3BC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x8017C3C0: jr          $ra
    // 0x8017C3C4: nop

    return;
    // 0x8017C3C4: nop

    // 0x8017C3C8: nop

    // 0x8017C3CC: nop

;}
RECOMP_FUNC void func_801DC320_0BA450(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801DC320: addiu       $t6, $zero, 0x1E
    ctx->r14 = ADD32(0, 0X1E);
    // 0x801DC324: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801DC328: sw          $t6, -0x2E50($at)
    MEM_W(-0X2E50, ctx->r1) = ctx->r14;
    // 0x801DC32C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801DC330: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801DC334: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801DC338: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801DC33C: addiu       $t7, $t7, -0x2E28
    ctx->r15 = ADD32(ctx->r15, -0X2E28);
    // 0x801DC340: sw          $zero, -0x2E4C($at)
    MEM_W(-0X2E4C, ctx->r1) = 0;
    // 0x801DC344: lbu         $t8, 0xA($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0XA);
    // 0x801DC348: addiu       $a0, $zero, 0x140
    ctx->r4 = ADD32(0, 0X140);
    // 0x801DC34C: addiu       $a1, $zero, 0xF0
    ctx->r5 = ADD32(0, 0XF0);
    // 0x801DC350: andi        $t9, $t8, 0xFD
    ctx->r25 = ctx->r24 & 0XFD;
    // 0x801DC354: jal         0x800C3044
    // 0x801DC358: sb          $t9, 0xA($t7)
    MEM_B(0XA, ctx->r15) = ctx->r25;
    func_800C3044(rdram, ctx);
        goto after_0;
    // 0x801DC358: sb          $t9, 0xA($t7)
    MEM_B(0XA, ctx->r15) = ctx->r25;
    after_0:
    // 0x801DC35C: jal         0x801DC4F8
    // 0x801DC360: nop

    func_801DC4F8_0BA450(rdram, ctx);
        goto after_1;
    // 0x801DC360: nop

    after_1:
    // 0x801DC364: jal         0x800C328C
    // 0x801DC368: nop

    func_800C328C(rdram, ctx);
        goto after_2;
    // 0x801DC368: nop

    after_2:
    // 0x801DC36C: jal         0x800C7FA4
    // 0x801DC370: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    func_800C7FA4(rdram, ctx);
        goto after_3;
    // 0x801DC370: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    after_3:
    // 0x801DC374: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801DC378: jal         0x800D1640
    // 0x801DC37C: addiu       $a0, $a0, -0x3C1C
    ctx->r4 = ADD32(ctx->r4, -0X3C1C);
    func_800D1640(rdram, ctx);
        goto after_4;
    // 0x801DC37C: addiu       $a0, $a0, -0x3C1C
    ctx->r4 = ADD32(ctx->r4, -0X3C1C);
    after_4:
L_801DC380:
    yield_self_1ms(rdram);
    // 0x801DC380: jal         0x800E4CDC
    // 0x801DC384: nop

    func_800E4CDC(rdram, ctx);
        goto after_5;
    // 0x801DC384: nop

    after_5:
    // 0x801DC388: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x801DC38C: lw          $t0, -0x2E4C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2E4C);
    // 0x801DC390: beq         $t0, $zero, L_801DC380
    if (ctx->r8 == 0) {
        // 0x801DC394: nop
    
            goto L_801DC380;
    }
    // 0x801DC394: nop

    // 0x801DC398: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x801DC39C: lhu         $t1, -0x4530($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X4530);
    // 0x801DC3A0: andi        $t2, $t1, 0x2000
    ctx->r10 = ctx->r9 & 0X2000;
    // 0x801DC3A4: bne         $t2, $zero, L_801DC380
    if (ctx->r10 != 0) {
        // 0x801DC3A8: nop
    
            goto L_801DC380;
    }
    // 0x801DC3A8: nop

    // 0x801DC3AC: jal         0x800CB720
    // 0x801DC3B0: nop

    func_800CB720(rdram, ctx);
        goto after_6;
    // 0x801DC3B0: nop

    after_6:
    // 0x801DC3B4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x801DC3B8: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x801DC3BC: bne         $t3, $zero, L_801DC380
    if (ctx->r11 != 0) {
        // 0x801DC3C0: nop
    
            goto L_801DC380;
    }
    // 0x801DC3C0: nop

    // 0x801DC3C4: jal         0x800C6DD4
    // 0x801DC3C8: nop

    func_800C6DD4(rdram, ctx);
        goto after_7;
    // 0x801DC3C8: nop

    after_7:
    // 0x801DC3CC: jal         0x800C7154
    // 0x801DC3D0: nop

    func_800C7154(rdram, ctx);
        goto after_8;
    // 0x801DC3D0: nop

    after_8:
    // 0x801DC3D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801DC3D8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801DC3DC: jr          $ra
    // 0x801DC3E0: nop

    return;
    // 0x801DC3E0: nop

;}
RECOMP_FUNC void func_801DC3E4_0BA450(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801DC3E4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801DC3E8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801DC3EC: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x801DC3F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801DC3F4: bgtz        $t6, L_801DC4E8
    if (SIGNED(ctx->r14) > 0) {
        // 0x801DC3F8: nop
    
            goto L_801DC4E8;
    }
    // 0x801DC3F8: nop

    // 0x801DC3FC: jal         0x800C3704
    // 0x801DC400: nop

    func_800C3704(rdram, ctx);
        goto after_0;
    // 0x801DC400: nop

    after_0:
    // 0x801DC404: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x801DC408: lw          $t7, -0x4514($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4514);
    // 0x801DC40C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x801DC410: lui         $t9, 0xDB06
    ctx->r25 = S32(0XDB06 << 16);
    // 0x801DC414: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x801DC418: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x801DC41C: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x801DC420: sw          $t8, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r24;
    // 0x801DC424: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x801DC428: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x801DC42C: jal         0x800C7458
    // 0x801DC430: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    func_800C7458(rdram, ctx);
        goto after_1;
    // 0x801DC430: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    after_1:
    // 0x801DC434: jal         0x8016D9E8
    // 0x801DC438: nop

    func_8016D9E8_02FC30(rdram, ctx);
        goto after_2;
    // 0x801DC438: nop

    after_2:
    // 0x801DC43C: jal         0x8016E8B0
    // 0x801DC440: nop

    func_8016E8B0_02FC30(rdram, ctx);
        goto after_3;
    // 0x801DC440: nop

    after_3:
    // 0x801DC444: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x801DC448: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x801DC44C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x801DC450: lbu         $a2, -0x2C2D($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X2C2D);
    // 0x801DC454: lbu         $a1, -0x2C2E($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X2C2E);
    // 0x801DC458: lbu         $a0, -0x2C2F($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X2C2F);
    // 0x801DC45C: jal         0x800C25FC
    // 0x801DC460: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800C25FC(rdram, ctx);
        goto after_4;
    // 0x801DC460: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
    // 0x801DC464: jal         0x800C3578
    // 0x801DC468: nop

    func_800C3578(rdram, ctx);
        goto after_5;
    // 0x801DC468: nop

    after_5:
    // 0x801DC46C: jal         0x801E0264
    // 0x801DC470: nop

    func_801E0264_0BA450(rdram, ctx);
        goto after_6;
    // 0x801DC470: nop

    after_6:
    // 0x801DC474: jal         0x801DCB5C
    // 0x801DC478: nop

    func_801DCB5C_0BA450(rdram, ctx);
        goto after_7;
    // 0x801DC478: nop

    after_7:
    // 0x801DC47C: jal         0x800C3760
    // 0x801DC480: nop

    func_800C3760(rdram, ctx);
        goto after_8;
    // 0x801DC480: nop

    after_8:
    // 0x801DC484: jal         0x8016FBBC
    // 0x801DC488: nop

    func_8016FBBC_02FC30(rdram, ctx);
        goto after_9;
    // 0x801DC488: nop

    after_9:
    // 0x801DC48C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x801DC490: lw          $t2, -0x2E34($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2E34);
    // 0x801DC494: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801DC498: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x801DC49C: jal         0x801DC62C
    // 0x801DC4A0: sw          $t3, -0x2E34($at)
    MEM_W(-0X2E34, ctx->r1) = ctx->r11;
    func_801DC62C_0BA450(rdram, ctx);
        goto after_10;
    // 0x801DC4A0: sw          $t3, -0x2E34($at)
    MEM_W(-0X2E34, ctx->r1) = ctx->r11;
    after_10:
    // 0x801DC4A4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x801DC4A8: lw          $t4, -0x2E4C($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2E4C);
    // 0x801DC4AC: beq         $t4, $zero, L_801DC4E8
    if (ctx->r12 == 0) {
        // 0x801DC4B0: nop
    
            goto L_801DC4E8;
    }
    // 0x801DC4B0: nop

    // 0x801DC4B4: lui         $t5, 0x8011
    ctx->r13 = S32(0X8011 << 16);
    // 0x801DC4B8: lhu         $t5, -0x4530($t5)
    ctx->r13 = MEM_HU(ctx->r13, -0X4530);
    // 0x801DC4BC: andi        $t6, $t5, 0x2000
    ctx->r14 = ctx->r13 & 0X2000;
    // 0x801DC4C0: bne         $t6, $zero, L_801DC4E8
    if (ctx->r14 != 0) {
        // 0x801DC4C4: nop
    
            goto L_801DC4E8;
    }
    // 0x801DC4C4: nop

    // 0x801DC4C8: jal         0x800CB720
    // 0x801DC4CC: nop

    func_800CB720(rdram, ctx);
        goto after_11;
    // 0x801DC4CC: nop

    after_11:
    // 0x801DC4D0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x801DC4D4: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x801DC4D8: bne         $t7, $zero, L_801DC4E8
    if (ctx->r15 != 0) {
        // 0x801DC4DC: nop
    
            goto L_801DC4E8;
    }
    // 0x801DC4DC: nop

    // 0x801DC4E0: jal         0x800D1640
    // 0x801DC4E4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800D1640(rdram, ctx);
        goto after_12;
    // 0x801DC4E4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_12:
L_801DC4E8:
    // 0x801DC4E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801DC4EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801DC4F0: jr          $ra
    // 0x801DC4F4: nop

    return;
    // 0x801DC4F4: nop

;}
RECOMP_FUNC void func_801DC4F8_0BA450(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801DC4F8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801DC4FC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801DC500: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x801DC504: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x801DC508: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x801DC50C: addiu       $t6, $t6, -0x2E18
    ctx->r14 = ADD32(ctx->r14, -0X2E18);
    // 0x801DC510: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801DC514: addiu       $t7, $t7, -0x2E18
    ctx->r15 = ADD32(ctx->r15, -0X2E18);
    // 0x801DC518: sw          $zero, 0x28($t6)
    MEM_W(0X28, ctx->r14) = 0;
    // 0x801DC51C: lw          $t8, 0x28($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X28);
    // 0x801DC520: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801DC524: lui         $t9, 0x801E
    ctx->r25 = S32(0X801E << 16);
    // 0x801DC528: addiu       $t9, $t9, 0x7678
    ctx->r25 = ADD32(ctx->r25, 0X7678);
    // 0x801DC52C: sw          $t8, -0x2E34($at)
    MEM_W(-0X2E34, ctx->r1) = ctx->r24;
    // 0x801DC530: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x801DC534: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801DC538: sw          $t0, -0x2BB8($at)
    MEM_W(-0X2BB8, ctx->r1) = ctx->r8;
    // 0x801DC53C: lw          $t1, 0x4($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X4);
    // 0x801DC540: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801DC544: sw          $t1, -0x2BB0($at)
    MEM_W(-0X2BB0, ctx->r1) = ctx->r9;
    // 0x801DC548: lw          $t2, 0x8($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X8);
    // 0x801DC54C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801DC550: jal         0x8016D8A4
    // 0x801DC554: sw          $t2, -0x2BB4($at)
    MEM_W(-0X2BB4, ctx->r1) = ctx->r10;
    func_8016D8A4_02FC30(rdram, ctx);
        goto after_0;
    // 0x801DC554: sw          $t2, -0x2BB4($at)
    MEM_W(-0X2BB4, ctx->r1) = ctx->r10;
    after_0:
    // 0x801DC558: lui         $t3, 0x801E
    ctx->r11 = S32(0X801E << 16);
    // 0x801DC55C: addiu       $t3, $t3, 0x7684
    ctx->r11 = ADD32(ctx->r11, 0X7684);
    // 0x801DC560: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801DC564: jal         0x8016E85C
    // 0x801DC568: sw          $t3, -0x2D8C($at)
    MEM_W(-0X2D8C, ctx->r1) = ctx->r11;
    func_8016E85C_02FC30(rdram, ctx);
        goto after_1;
    // 0x801DC568: sw          $t3, -0x2D8C($at)
    MEM_W(-0X2D8C, ctx->r1) = ctx->r11;
    after_1:
    // 0x801DC56C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801DC570: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x801DC574: addiu       $t4, $t4, -0x2D90
    ctx->r12 = ADD32(ctx->r12, -0X2D90);
    // 0x801DC578: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x801DC57C: addiu       $t5, $t5, -0x2D90
    ctx->r13 = ADD32(ctx->r13, -0X2D90);
    // 0x801DC580: swc1        $f4, 0x20($t4)
    MEM_W(0X20, ctx->r12) = ctx->f4.u32l;
    // 0x801DC584: lwc1        $f22, 0x20($t5)
    ctx->f22.u32l = MEM_W(ctx->r13, 0X20);
    // 0x801DC588: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801DC58C: addiu       $t6, $t6, -0x2D90
    ctx->r14 = ADD32(ctx->r14, -0X2D90);
    // 0x801DC590: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801DC594: swc1        $f22, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = ctx->f22.u32l;
    // 0x801DC598: mov.s       $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    ctx->f20.fl = ctx->f22.fl;
    // 0x801DC59C: swc1        $f20, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->f20.u32l;
    // 0x801DC5A0: addiu       $t7, $t7, -0x2D90
    ctx->r15 = ADD32(ctx->r15, -0X2D90);
    // 0x801DC5A4: swc1        $f20, 0x14($t7)
    MEM_W(0X14, ctx->r15) = ctx->f20.u32l;
    // 0x801DC5A8: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x801DC5AC: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x801DC5B0: jal         0x800C6E0C
    // 0x801DC5B4: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    func_800C6E0C(rdram, ctx);
        goto after_2;
    // 0x801DC5B4: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    after_2:
    // 0x801DC5B8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801DC5BC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801DC5C0: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x801DC5C4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x801DC5C8: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    // 0x801DC5CC: addiu       $a1, $zero, 0x96
    ctx->r5 = ADD32(0, 0X96);
    // 0x801DC5D0: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    // 0x801DC5D4: jal         0x800C6E68
    // 0x801DC5D8: addiu       $a3, $zero, 0x32
    ctx->r7 = ADD32(0, 0X32);
    func_800C6E68(rdram, ctx);
        goto after_3;
    // 0x801DC5D8: addiu       $a3, $zero, 0x32
    ctx->r7 = ADD32(0, 0X32);
    after_3:
    // 0x801DC5DC: jal         0x800C6DBC
    // 0x801DC5E0: nop

    func_800C6DBC(rdram, ctx);
        goto after_4;
    // 0x801DC5E0: nop

    after_4:
    // 0x801DC5E4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801DC5E8: sb          $zero, -0x2C2D($at)
    MEM_B(-0X2C2D, ctx->r1) = 0;
    // 0x801DC5EC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801DC5F0: sb          $zero, -0x2C2E($at)
    MEM_B(-0X2C2E, ctx->r1) = 0;
    // 0x801DC5F4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801DC5F8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801DC5FC: sb          $zero, -0x2C2F($at)
    MEM_B(-0X2C2F, ctx->r1) = 0;
    // 0x801DC600: addiu       $t9, $t9, 0x3D00
    ctx->r25 = ADD32(ctx->r25, 0X3D00);
    // 0x801DC604: addiu       $t1, $zero, 0xF0
    ctx->r9 = ADD32(0, 0XF0);
    // 0x801DC608: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x801DC60C: sw          $t1, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r9;
    // 0x801DC610: addiu       $t2, $t2, 0x3C00
    ctx->r10 = ADD32(ctx->r10, 0X3C00);
    // 0x801DC614: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
    // 0x801DC618: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x801DC61C: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x801DC620: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x801DC624: jr          $ra
    // 0x801DC628: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x801DC628: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_801DC62C_0BA450(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801DC62C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801DC630: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801DC634: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801DC638: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801DC63C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x801DC640: addiu       $t6, $t6, 0x3C00
    ctx->r14 = ADD32(ctx->r14, 0X3C00);
    // 0x801DC644: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x801DC648: beq         $t7, $zero, L_801DC7D0
    if (ctx->r15 == 0) {
        // 0x801DC64C: nop
    
            goto L_801DC7D0;
    }
    // 0x801DC64C: nop

    // 0x801DC650: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x801DC654: lw          $t8, -0x2E34($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2E34);
    // 0x801DC658: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x801DC65C: beq         $t9, $zero, L_801DC678
    if (ctx->r25 == 0) {
        // 0x801DC660: nop
    
            goto L_801DC678;
    }
    // 0x801DC660: nop

    // 0x801DC664: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x801DC668: addiu       $t0, $t0, 0x3D00
    ctx->r8 = ADD32(ctx->r8, 0X3D00);
    // 0x801DC66C: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x801DC670: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x801DC674: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
L_801DC678:
    // 0x801DC678: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x801DC67C: lbu         $t3, -0x2C2F($t3)
    ctx->r11 = MEM_BU(ctx->r11, -0X2C2F);
    // 0x801DC680: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    // 0x801DC684: beq         $t3, $at, L_801DC698
    if (ctx->r11 == ctx->r1) {
        // 0x801DC688: nop
    
            goto L_801DC698;
    }
    // 0x801DC688: nop

    // 0x801DC68C: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x801DC690: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801DC694: sb          $t4, -0x2C2F($at)
    MEM_B(-0X2C2F, ctx->r1) = ctx->r12;
L_801DC698:
    // 0x801DC698: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x801DC69C: lbu         $t5, -0x2C2E($t5)
    ctx->r13 = MEM_BU(ctx->r13, -0X2C2E);
    // 0x801DC6A0: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x801DC6A4: beq         $t5, $at, L_801DC6B8
    if (ctx->r13 == ctx->r1) {
        // 0x801DC6A8: nop
    
            goto L_801DC6B8;
    }
    // 0x801DC6A8: nop

    // 0x801DC6AC: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x801DC6B0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801DC6B4: sb          $t6, -0x2C2E($at)
    MEM_B(-0X2C2E, ctx->r1) = ctx->r14;
L_801DC6B8:
    // 0x801DC6B8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801DC6BC: lbu         $t7, -0x2C29($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X2C29);
    // 0x801DC6C0: addiu       $at, $zero, 0x21
    ctx->r1 = ADD32(0, 0X21);
    // 0x801DC6C4: beq         $t7, $at, L_801DC6D8
    if (ctx->r15 == ctx->r1) {
        // 0x801DC6C8: nop
    
            goto L_801DC6D8;
    }
    // 0x801DC6C8: nop

    // 0x801DC6CC: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x801DC6D0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801DC6D4: sb          $t8, -0x2C29($at)
    MEM_B(-0X2C29, ctx->r1) = ctx->r24;
L_801DC6D8:
    // 0x801DC6D8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801DC6DC: lbu         $t9, -0x2C28($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X2C28);
    // 0x801DC6E0: addiu       $at, $zero, 0x21
    ctx->r1 = ADD32(0, 0X21);
    // 0x801DC6E4: beq         $t9, $at, L_801DC6F8
    if (ctx->r25 == ctx->r1) {
        // 0x801DC6E8: nop
    
            goto L_801DC6F8;
    }
    // 0x801DC6E8: nop

    // 0x801DC6EC: addiu       $t1, $t9, -0x1
    ctx->r9 = ADD32(ctx->r25, -0X1);
    // 0x801DC6F0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801DC6F4: sb          $t1, -0x2C28($at)
    MEM_B(-0X2C28, ctx->r1) = ctx->r9;
L_801DC6F8:
    // 0x801DC6F8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x801DC6FC: lbu         $t2, -0x2C27($t2)
    ctx->r10 = MEM_BU(ctx->r10, -0X2C27);
    // 0x801DC700: addiu       $at, $zero, 0x21
    ctx->r1 = ADD32(0, 0X21);
    // 0x801DC704: beq         $t2, $at, L_801DC718
    if (ctx->r10 == ctx->r1) {
        // 0x801DC708: nop
    
            goto L_801DC718;
    }
    // 0x801DC708: nop

    // 0x801DC70C: addiu       $t0, $t2, -0x1
    ctx->r8 = ADD32(ctx->r10, -0X1);
    // 0x801DC710: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801DC714: sb          $t0, -0x2C27($at)
    MEM_B(-0X2C27, ctx->r1) = ctx->r8;
L_801DC718:
    // 0x801DC718: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x801DC71C: lbu         $t3, -0x2C26($t3)
    ctx->r11 = MEM_BU(ctx->r11, -0X2C26);
    // 0x801DC720: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x801DC724: beq         $t3, $at, L_801DC738
    if (ctx->r11 == ctx->r1) {
        // 0x801DC728: nop
    
            goto L_801DC738;
    }
    // 0x801DC728: nop

    // 0x801DC72C: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x801DC730: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801DC734: sb          $t4, -0x2C26($at)
    MEM_B(-0X2C26, ctx->r1) = ctx->r12;
L_801DC738:
    // 0x801DC738: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x801DC73C: lbu         $t5, -0x2C25($t5)
    ctx->r13 = MEM_BU(ctx->r13, -0X2C25);
    // 0x801DC740: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x801DC744: beq         $t5, $at, L_801DC758
    if (ctx->r13 == ctx->r1) {
        // 0x801DC748: nop
    
            goto L_801DC758;
    }
    // 0x801DC748: nop

    // 0x801DC74C: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x801DC750: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801DC754: sb          $t6, -0x2C25($at)
    MEM_B(-0X2C25, ctx->r1) = ctx->r14;
L_801DC758:
    // 0x801DC758: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801DC75C: lbu         $t7, -0x2C24($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X2C24);
    // 0x801DC760: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x801DC764: beq         $t7, $at, L_801DC778
    if (ctx->r15 == ctx->r1) {
        // 0x801DC768: nop
    
            goto L_801DC778;
    }
    // 0x801DC768: nop

    // 0x801DC76C: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x801DC770: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801DC774: sb          $t8, -0x2C24($at)
    MEM_B(-0X2C24, ctx->r1) = ctx->r24;
L_801DC778:
    // 0x801DC778: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x801DC77C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x801DC780: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x801DC784: lbu         $a2, -0x2C27($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X2C27);
    // 0x801DC788: lbu         $a1, -0x2C28($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X2C28);
    // 0x801DC78C: jal         0x800C6E0C
    // 0x801DC790: lbu         $a0, -0x2C29($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X2C29);
    func_800C6E0C(rdram, ctx);
        goto after_0;
    // 0x801DC790: lbu         $a0, -0x2C29($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X2C29);
    after_0:
    // 0x801DC794: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801DC798: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x801DC79C: lb          $t1, -0x2C21($t1)
    ctx->r9 = MEM_B(ctx->r9, -0X2C21);
    // 0x801DC7A0: lb          $t9, -0x2C22($t9)
    ctx->r25 = MEM_B(ctx->r25, -0X2C22);
    // 0x801DC7A4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x801DC7A8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x801DC7AC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x801DC7B0: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x801DC7B4: lb          $a3, -0x2C23($a3)
    ctx->r7 = MEM_B(ctx->r7, -0X2C23);
    // 0x801DC7B8: lbu         $a2, -0x2C24($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X2C24);
    // 0x801DC7BC: lbu         $a1, -0x2C25($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X2C25);
    // 0x801DC7C0: lbu         $a0, -0x2C26($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X2C26);
    // 0x801DC7C4: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x801DC7C8: jal         0x800C6E68
    // 0x801DC7CC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    func_800C6E68(rdram, ctx);
        goto after_1;
    // 0x801DC7CC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_1:
L_801DC7D0:
    // 0x801DC7D0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x801DC7D4: lw          $t2, -0x2E4C($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2E4C);
    // 0x801DC7D8: bne         $t2, $zero, L_801DC80C
    if (ctx->r10 != 0) {
        // 0x801DC7DC: nop
    
            goto L_801DC80C;
    }
    // 0x801DC7DC: nop

    // 0x801DC7E0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x801DC7E4: addiu       $t0, $t0, -0x41E0
    ctx->r8 = ADD32(ctx->r8, -0X41E0);
    // 0x801DC7E8: lhu         $t3, 0x2($t0)
    ctx->r11 = MEM_HU(ctx->r8, 0X2);
    // 0x801DC7EC: andi        $t4, $t3, 0xB000
    ctx->r12 = ctx->r11 & 0XB000;
    // 0x801DC7F0: beq         $t4, $zero, L_801DC80C
    if (ctx->r12 == 0) {
        // 0x801DC7F4: nop
    
            goto L_801DC80C;
    }
    // 0x801DC7F4: nop

    // 0x801DC7F8: jal         0x800C32CC
    // 0x801DC7FC: nop

    func_800C32CC(rdram, ctx);
        goto after_2;
    // 0x801DC7FC: nop

    after_2:
    // 0x801DC800: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801DC804: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801DC808: sw          $t5, -0x2E4C($at)
    MEM_W(-0X2E4C, ctx->r1) = ctx->r13;
L_801DC80C:
    // 0x801DC80C: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x801DC810: lui         $t9, 0x801E
    ctx->r25 = S32(0X801E << 16);
    // 0x801DC814: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x801DC818: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x801DC81C: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x801DC820: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x801DC824: lhu         $t9, 0x23C0($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X23C0);
    // 0x801DC828: beq         $t9, $at, L_801DCB48
    if (ctx->r25 == ctx->r1) {
        // 0x801DC82C: nop
    
            goto L_801DCB48;
    }
    // 0x801DC82C: nop

    // 0x801DC830: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x801DC834: lui         $t3, 0x801E
    ctx->r11 = S32(0X801E << 16);
    // 0x801DC838: addiu       $t3, $t3, 0x23C0
    ctx->r11 = ADD32(ctx->r11, 0X23C0);
    // 0x801DC83C: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x801DC840: sll         $t0, $t2, 1
    ctx->r8 = S32(ctx->r10 << 1);
    // 0x801DC844: addu        $t4, $t0, $t3
    ctx->r12 = ADD32(ctx->r8, ctx->r11);
    // 0x801DC848: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801DC84C: lw          $t6, -0x2E34($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2E34);
    // 0x801DC850: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x801DC854: bne         $t5, $t6, L_801DCB38
    if (ctx->r13 != ctx->r14) {
        // 0x801DC858: nop
    
            goto L_801DCB38;
    }
    // 0x801DC858: nop

    // 0x801DC85C: lhu         $s0, 0x2($t4)
    ctx->r16 = MEM_HU(ctx->r12, 0X2);
    // 0x801DC860: slti        $at, $s0, 0x15
    ctx->r1 = SIGNED(ctx->r16) < 0X15 ? 1 : 0;
    // 0x801DC864: bne         $at, $zero, L_801DC87C
    if (ctx->r1 != 0) {
        // 0x801DC868: addiu       $at, $zero, 0xFF
        ctx->r1 = ADD32(0, 0XFF);
            goto L_801DC87C;
    }
    // 0x801DC868: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x801DC86C: beq         $s0, $at, L_801DCB14
    if (ctx->r16 == ctx->r1) {
        // 0x801DC870: nop
    
            goto L_801DCB14;
    }
    // 0x801DC870: nop

    // 0x801DC874: b           L_801DCB38
    // 0x801DC878: nop

        goto L_801DCB38;
    // 0x801DC878: nop

L_801DC87C:
    // 0x801DC87C: sltiu       $at, $s0, 0x15
    ctx->r1 = ctx->r16 < 0X15 ? 1 : 0;
    // 0x801DC880: beq         $at, $zero, L_801DCB38
    if (ctx->r1 == 0) {
        // 0x801DC884: nop
    
            goto L_801DCB38;
    }
    // 0x801DC884: nop

    // 0x801DC888: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x801DC88C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DC890: addu        $at, $at, $t7
    gpr jr_addend_801DC898 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x801DC894: lw          $t7, 0x7B70($at)
    ctx->r15 = ADD32(ctx->r1, 0X7B70);
    // 0x801DC898: jr          $t7
    // 0x801DC89C: nop

    switch (jr_addend_801DC898 >> 2) {
        case 0: goto L_801DC8B0; break;
        case 1: goto L_801DC8A0; break;
        case 2: goto L_801DCB38; break;
        case 3: goto L_801DCB38; break;
        case 4: goto L_801DCB38; break;
        case 5: goto L_801DCB38; break;
        case 6: goto L_801DCB38; break;
        case 7: goto L_801DCB38; break;
        case 8: goto L_801DCB38; break;
        case 9: goto L_801DCB38; break;
        case 10: goto L_801DC8C0; break;
        case 11: goto L_801DCA24; break;
        case 12: goto L_801DCB38; break;
        case 13: goto L_801DCB38; break;
        case 14: goto L_801DCB38; break;
        case 15: goto L_801DCB38; break;
        case 16: goto L_801DCB38; break;
        case 17: goto L_801DCB38; break;
        case 18: goto L_801DCB38; break;
        case 19: goto L_801DCB38; break;
        case 20: goto L_801DCB00; break;
        default: switch_error(__func__, 0x801DC898, 0x801E7B70);
    }
    // 0x801DC89C: nop

L_801DC8A0:
    // 0x801DC8A0: jal         0x800C3234
    // 0x801DC8A4: nop

    func_800C3234(rdram, ctx);
        goto after_3;
    // 0x801DC8A4: nop

    after_3:
    // 0x801DC8A8: b           L_801DCB38
    // 0x801DC8AC: nop

        goto L_801DCB38;
    // 0x801DC8AC: nop

L_801DC8B0:
    // 0x801DC8B0: jal         0x800C3264
    // 0x801DC8B4: nop

    func_800C3264(rdram, ctx);
        goto after_4;
    // 0x801DC8B4: nop

    after_4:
    // 0x801DC8B8: b           L_801DCB38
    // 0x801DC8BC: nop

        goto L_801DCB38;
    // 0x801DC8BC: nop

L_801DC8C0:
    // 0x801DC8C0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x801DC8C4: addiu       $t8, $t8, -0x2E18
    ctx->r24 = ADD32(ctx->r24, -0X2E18);
    // 0x801DC8C8: lw          $t9, 0x28($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X28);
    // 0x801DC8CC: addiu       $t2, $zero, 0x5C
    ctx->r10 = ADD32(0, 0X5C);
    // 0x801DC8D0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801DC8D4: addiu       $t1, $t9, 0x1
    ctx->r9 = ADD32(ctx->r25, 0X1);
    // 0x801DC8D8: sw          $t1, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r9;
    // 0x801DC8DC: sb          $t2, -0x2C2F($at)
    MEM_B(-0X2C2F, ctx->r1) = ctx->r10;
    // 0x801DC8E0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801DC8E4: addiu       $t0, $zero, 0x33
    ctx->r8 = ADD32(0, 0X33);
    // 0x801DC8E8: sb          $t0, -0x2C2E($at)
    MEM_B(-0X2C2E, ctx->r1) = ctx->r8;
    // 0x801DC8EC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801DC8F0: sb          $zero, -0x2C2D($at)
    MEM_B(-0X2C2D, ctx->r1) = 0;
    // 0x801DC8F4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801DC8F8: addiu       $t3, $zero, 0x64
    ctx->r11 = ADD32(0, 0X64);
    // 0x801DC8FC: sb          $t3, -0x2C29($at)
    MEM_B(-0X2C29, ctx->r1) = ctx->r11;
    // 0x801DC900: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801DC904: addiu       $t5, $zero, 0x3C
    ctx->r13 = ADD32(0, 0X3C);
    // 0x801DC908: sb          $t5, -0x2C28($at)
    MEM_B(-0X2C28, ctx->r1) = ctx->r13;
    // 0x801DC90C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801DC910: addiu       $t6, $zero, 0x3C
    ctx->r14 = ADD32(0, 0X3C);
    // 0x801DC914: sb          $t6, -0x2C27($at)
    MEM_B(-0X2C27, ctx->r1) = ctx->r14;
    // 0x801DC918: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801DC91C: addiu       $t4, $zero, 0xB4
    ctx->r12 = ADD32(0, 0XB4);
    // 0x801DC920: sb          $t4, -0x2C26($at)
    MEM_B(-0X2C26, ctx->r1) = ctx->r12;
    // 0x801DC924: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801DC928: addiu       $t7, $zero, 0x82
    ctx->r15 = ADD32(0, 0X82);
    // 0x801DC92C: sb          $t7, -0x2C25($at)
    MEM_B(-0X2C25, ctx->r1) = ctx->r15;
    // 0x801DC930: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801DC934: addiu       $t9, $zero, 0x82
    ctx->r25 = ADD32(0, 0X82);
    // 0x801DC938: sb          $t9, -0x2C24($at)
    MEM_B(-0X2C24, ctx->r1) = ctx->r25;
    // 0x801DC93C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801DC940: addiu       $t1, $zero, 0x14
    ctx->r9 = ADD32(0, 0X14);
    // 0x801DC944: sb          $t1, -0x2C23($at)
    MEM_B(-0X2C23, ctx->r1) = ctx->r9;
    // 0x801DC948: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801DC94C: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x801DC950: sb          $t8, -0x2C22($at)
    MEM_B(-0X2C22, ctx->r1) = ctx->r24;
    // 0x801DC954: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801DC958: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801DC95C: sb          $t2, -0x2C21($at)
    MEM_B(-0X2C21, ctx->r1) = ctx->r10;
    // 0x801DC960: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801DC964: addiu       $t0, $zero, 0x5C
    ctx->r8 = ADD32(0, 0X5C);
    // 0x801DC968: sb          $t0, -0x2C2C($at)
    MEM_B(-0X2C2C, ctx->r1) = ctx->r8;
    // 0x801DC96C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801DC970: addiu       $t3, $zero, 0x33
    ctx->r11 = ADD32(0, 0X33);
    // 0x801DC974: sb          $t3, -0x2C2B($at)
    MEM_B(-0X2C2B, ctx->r1) = ctx->r11;
    // 0x801DC978: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801DC97C: sb          $zero, -0x2C2A($at)
    MEM_B(-0X2C2A, ctx->r1) = 0;
    // 0x801DC980: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801DC984: addiu       $t5, $zero, 0x3E4
    ctx->r13 = ADD32(0, 0X3E4);
    // 0x801DC988: sh          $t5, -0x2C20($at)
    MEM_H(-0X2C20, ctx->r1) = ctx->r13;
    // 0x801DC98C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801DC990: addiu       $t6, $zero, 0x3E8
    ctx->r14 = ADD32(0, 0X3E8);
    // 0x801DC994: sh          $t6, -0x2C1E($at)
    MEM_H(-0X2C1E, ctx->r1) = ctx->r14;
    // 0x801DC998: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    // 0x801DC99C: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x801DC9A0: jal         0x800C6E0C
    // 0x801DC9A4: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    func_800C6E0C(rdram, ctx);
        goto after_5;
    // 0x801DC9A4: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    after_5:
    // 0x801DC9A8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x801DC9AC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801DC9B0: lb          $t7, -0x2C21($t7)
    ctx->r15 = MEM_B(ctx->r15, -0X2C21);
    // 0x801DC9B4: lb          $t4, -0x2C22($t4)
    ctx->r12 = MEM_B(ctx->r12, -0X2C22);
    // 0x801DC9B8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x801DC9BC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x801DC9C0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x801DC9C4: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x801DC9C8: lb          $a3, -0x2C23($a3)
    ctx->r7 = MEM_B(ctx->r7, -0X2C23);
    // 0x801DC9CC: lbu         $a2, -0x2C24($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X2C24);
    // 0x801DC9D0: lbu         $a1, -0x2C25($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X2C25);
    // 0x801DC9D4: lbu         $a0, -0x2C26($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X2C26);
    // 0x801DC9D8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801DC9DC: jal         0x800C6E68
    // 0x801DC9E0: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    func_800C6E68(rdram, ctx);
        goto after_6;
    // 0x801DC9E0: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_6:
    // 0x801DC9E4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801DC9E8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x801DC9EC: lhu         $t1, -0x2C1E($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X2C1E);
    // 0x801DC9F0: lhu         $t9, -0x2C20($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X2C20);
    // 0x801DC9F4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x801DC9F8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x801DC9FC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x801DCA00: lbu         $a2, -0x2C2A($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X2C2A);
    // 0x801DCA04: lbu         $a1, -0x2C2B($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X2C2B);
    // 0x801DCA08: lbu         $a0, -0x2C2C($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X2C2C);
    // 0x801DCA0C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x801DCA10: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x801DCA14: jal         0x800C70C0
    // 0x801DCA18: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    func_800C70C0(rdram, ctx);
        goto after_7;
    // 0x801DCA18: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_7:
    // 0x801DCA1C: b           L_801DCB38
    // 0x801DCA20: nop

        goto L_801DCB38;
    // 0x801DCA20: nop

L_801DCA24:
    // 0x801DCA24: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x801DCA28: addiu       $t8, $t8, -0x2E18
    ctx->r24 = ADD32(ctx->r24, -0X2E18);
    // 0x801DCA2C: lw          $t2, 0x28($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X28);
    // 0x801DCA30: addiu       $t3, $zero, 0x64
    ctx->r11 = ADD32(0, 0X64);
    // 0x801DCA34: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801DCA38: addiu       $t0, $t2, 0x1
    ctx->r8 = ADD32(ctx->r10, 0X1);
    // 0x801DCA3C: sw          $t0, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r8;
    // 0x801DCA40: sb          $t3, -0x2C29($at)
    MEM_B(-0X2C29, ctx->r1) = ctx->r11;
    // 0x801DCA44: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801DCA48: addiu       $t5, $zero, 0x64
    ctx->r13 = ADD32(0, 0X64);
    // 0x801DCA4C: sb          $t5, -0x2C28($at)
    MEM_B(-0X2C28, ctx->r1) = ctx->r13;
    // 0x801DCA50: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801DCA54: addiu       $t6, $zero, 0x64
    ctx->r14 = ADD32(0, 0X64);
    // 0x801DCA58: sb          $t6, -0x2C27($at)
    MEM_B(-0X2C27, ctx->r1) = ctx->r14;
    // 0x801DCA5C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801DCA60: addiu       $t4, $zero, 0x96
    ctx->r12 = ADD32(0, 0X96);
    // 0x801DCA64: sb          $t4, -0x2C26($at)
    MEM_B(-0X2C26, ctx->r1) = ctx->r12;
    // 0x801DCA68: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801DCA6C: addiu       $t7, $zero, 0x96
    ctx->r15 = ADD32(0, 0X96);
    // 0x801DCA70: sb          $t7, -0x2C25($at)
    MEM_B(-0X2C25, ctx->r1) = ctx->r15;
    // 0x801DCA74: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801DCA78: addiu       $t9, $zero, 0x96
    ctx->r25 = ADD32(0, 0X96);
    // 0x801DCA7C: sb          $t9, -0x2C24($at)
    MEM_B(-0X2C24, ctx->r1) = ctx->r25;
    // 0x801DCA80: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801DCA84: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x801DCA88: sb          $t1, -0x2C23($at)
    MEM_B(-0X2C23, ctx->r1) = ctx->r9;
    // 0x801DCA8C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801DCA90: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
    // 0x801DCA94: sb          $t2, -0x2C22($at)
    MEM_B(-0X2C22, ctx->r1) = ctx->r10;
    // 0x801DCA98: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801DCA9C: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x801DCAA0: sb          $t0, -0x2C21($at)
    MEM_B(-0X2C21, ctx->r1) = ctx->r8;
    // 0x801DCAA4: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    // 0x801DCAA8: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    // 0x801DCAAC: jal         0x800C6E0C
    // 0x801DCAB0: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    func_800C6E0C(rdram, ctx);
        goto after_8;
    // 0x801DCAB0: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    after_8:
    // 0x801DCAB4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x801DCAB8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x801DCABC: lb          $t3, -0x2C21($t3)
    ctx->r11 = MEM_B(ctx->r11, -0X2C21);
    // 0x801DCAC0: lb          $t8, -0x2C22($t8)
    ctx->r24 = MEM_B(ctx->r24, -0X2C22);
    // 0x801DCAC4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x801DCAC8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x801DCACC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x801DCAD0: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x801DCAD4: lb          $a3, -0x2C23($a3)
    ctx->r7 = MEM_B(ctx->r7, -0X2C23);
    // 0x801DCAD8: lbu         $a2, -0x2C24($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X2C24);
    // 0x801DCADC: lbu         $a1, -0x2C25($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X2C25);
    // 0x801DCAE0: lbu         $a0, -0x2C26($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X2C26);
    // 0x801DCAE4: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x801DCAE8: jal         0x800C6E68
    // 0x801DCAEC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    func_800C6E68(rdram, ctx);
        goto after_9;
    // 0x801DCAEC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_9:
    // 0x801DCAF0: jal         0x800C7154
    // 0x801DCAF4: nop

    func_800C7154(rdram, ctx);
        goto after_10;
    // 0x801DCAF4: nop

    after_10:
    // 0x801DCAF8: b           L_801DCB38
    // 0x801DCAFC: nop

        goto L_801DCB38;
    // 0x801DCAFC: nop

L_801DCB00:
    // 0x801DCB00: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801DCB04: addiu       $t6, $t6, 0x3C00
    ctx->r14 = ADD32(ctx->r14, 0X3C00);
    // 0x801DCB08: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x801DCB0C: b           L_801DCB38
    // 0x801DCB10: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
        goto L_801DCB38;
    // 0x801DCB10: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
L_801DCB14:
    // 0x801DCB14: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x801DCB18: lw          $t4, -0x2E4C($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2E4C);
    // 0x801DCB1C: bne         $t4, $zero, L_801DCB48
    if (ctx->r12 != 0) {
        // 0x801DCB20: nop
    
            goto L_801DCB48;
    }
    // 0x801DCB20: nop

    // 0x801DCB24: jal         0x800C32CC
    // 0x801DCB28: nop

    func_800C32CC(rdram, ctx);
        goto after_11;
    // 0x801DCB28: nop

    after_11:
    // 0x801DCB2C: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x801DCB30: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801DCB34: sw          $t7, -0x2E4C($at)
    MEM_W(-0X2E4C, ctx->r1) = ctx->r15;
L_801DCB38:
    // 0x801DCB38: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x801DCB3C: addiu       $t1, $t9, 0x1
    ctx->r9 = ADD32(ctx->r25, 0X1);
    // 0x801DCB40: b           L_801DC80C
    // 0x801DCB44: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
        goto L_801DC80C;
    // 0x801DCB44: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
L_801DCB48:
    // 0x801DCB48: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801DCB4C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801DCB50: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801DCB54: jr          $ra
    // 0x801DCB58: nop

    return;
    // 0x801DCB58: nop

;}
RECOMP_FUNC void func_801DCB5C_0BA450(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801DCB5C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801DCB60: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801DCB64: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x801DCB68: jal         0x800D54C8
    // 0x801DCB6C: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    spX2Init_recomp(rdram, ctx);
        goto after_0;
    // 0x801DCB6C: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    after_0:
    // 0x801DCB70: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801DCB74: lw          $t6, -0x2E34($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2E34);
    // 0x801DCB78: sltiu       $at, $t6, 0x25
    ctx->r1 = ctx->r14 < 0X25 ? 1 : 0;
    // 0x801DCB7C: bne         $at, $zero, L_801DCBC4
    if (ctx->r1 != 0) {
        // 0x801DCB80: sltiu       $at, $t6, 0x2F
        ctx->r1 = ctx->r14 < 0X2F ? 1 : 0;
            goto L_801DCBC4;
    }
    // 0x801DCB80: sltiu       $at, $t6, 0x2F
    ctx->r1 = ctx->r14 < 0X2F ? 1 : 0;
    // 0x801DCB84: beq         $at, $zero, L_801DCBC4
    if (ctx->r1 == 0) {
        // 0x801DCB88: nop
    
            goto L_801DCBC4;
    }
    // 0x801DCB88: nop

    // 0x801DCB8C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801DCB90: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x801DCB94: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x801DCB98: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801DCB9C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801DCBA0: addiu       $t8, $t7, -0x2E4
    ctx->r24 = ADD32(ctx->r15, -0X2E4);
    // 0x801DCBA4: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x801DCBA8: addiu       $a0, $a0, -0x7338
    ctx->r4 = ADD32(ctx->r4, -0X7338);
    // 0x801DCBAC: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x801DCBB0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801DCBB4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801DCBB8: lui         $a3, 0x4080
    ctx->r7 = S32(0X4080 << 16);
    // 0x801DCBBC: jal         0x800C6C6C
    // 0x801DCBC0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_1;
    // 0x801DCBC0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
L_801DCBC4:
    // 0x801DCBC4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801DCBC8: lw          $t9, -0x2E34($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2E34);
    // 0x801DCBCC: sltiu       $at, $t9, 0x2F
    ctx->r1 = ctx->r25 < 0X2F ? 1 : 0;
    // 0x801DCBD0: bne         $at, $zero, L_801DCC1C
    if (ctx->r1 != 0) {
        // 0x801DCBD4: sltiu       $at, $t9, 0x43
        ctx->r1 = ctx->r25 < 0X43 ? 1 : 0;
            goto L_801DCC1C;
    }
    // 0x801DCBD4: sltiu       $at, $t9, 0x43
    ctx->r1 = ctx->r25 < 0X43 ? 1 : 0;
    // 0x801DCBD8: beq         $at, $zero, L_801DCC1C
    if (ctx->r1 == 0) {
        // 0x801DCBDC: nop
    
            goto L_801DCC1C;
    }
    // 0x801DCBDC: nop

    // 0x801DCBE0: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x801DCBE4: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x801DCBE8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x801DCBEC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801DCBF0: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x801DCBF4: addiu       $t1, $zero, 0x29E
    ctx->r9 = ADD32(0, 0X29E);
    // 0x801DCBF8: subu        $t2, $t1, $t0
    ctx->r10 = SUB32(ctx->r9, ctx->r8);
    // 0x801DCBFC: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x801DCC00: addiu       $a0, $a0, -0x7338
    ctx->r4 = ADD32(ctx->r4, -0X7338);
    // 0x801DCC04: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x801DCC08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801DCC0C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801DCC10: lui         $a3, 0x4080
    ctx->r7 = S32(0X4080 << 16);
    // 0x801DCC14: jal         0x800C6C6C
    // 0x801DCC18: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_2;
    // 0x801DCC18: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_2:
L_801DCC1C:
    // 0x801DCC1C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x801DCC20: addiu       $t3, $t3, 0x3C00
    ctx->r11 = ADD32(ctx->r11, 0X3C00);
    // 0x801DCC24: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x801DCC28: beq         $t4, $zero, L_801DCC64
    if (ctx->r12 == 0) {
        // 0x801DCC2C: nop
    
            goto L_801DCC64;
    }
    // 0x801DCC2C: nop

    // 0x801DCC30: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x801DCC34: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801DCC38: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801DCC3C: addiu       $t5, $t5, 0x3D00
    ctx->r13 = ADD32(ctx->r13, 0X3D00);
    // 0x801DCC40: lw          $a2, 0x0($t5)
    ctx->r6 = MEM_W(ctx->r13, 0X0);
    // 0x801DCC44: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801DCC48: addiu       $t6, $zero, 0x78
    ctx->r14 = ADD32(0, 0X78);
    // 0x801DCC4C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x801DCC50: addiu       $a0, $a0, -0x4800
    ctx->r4 = ADD32(ctx->r4, -0X4800);
    // 0x801DCC54: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x801DCC58: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801DCC5C: jal         0x800C6C6C
    // 0x801DCC60: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_3;
    // 0x801DCC60: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_3:
L_801DCC64:
    // 0x801DCC64: jal         0x800C6D5C
    // 0x801DCC68: nop

    func_800C6D5C(rdram, ctx);
        goto after_4;
    // 0x801DCC68: nop

    after_4:
    // 0x801DCC6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801DCC70: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801DCC74: jr          $ra
    return;
;}
RECOMP_FUNC void func_801DCC78_0BA450(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801DCC78: nop

;}
RECOMP_FUNC void func_801DCC7C_0BA450(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801DCC7C: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x801DCC80: lw          $t6, -0x4514($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4514);
    // 0x801DCC84: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x801DCC88: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x801DCC8C: sw          $t6, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r14;
    // 0x801DCC90: lw          $t9, 0xC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC);
    // 0x801DCC94: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x801DCC98: sw          $t7, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r15;
    // 0x801DCC9C: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x801DCCA0: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x801DCCA4: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x801DCCA8: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x801DCCAC: lui         $t3, 0xD900
    ctx->r11 = S32(0XD900 << 16);
    // 0x801DCCB0: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x801DCCB4: lw          $t1, -0x4514($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4514);
    // 0x801DCCB8: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x801DCCBC: lui         $t8, 0xDE00
    ctx->r24 = S32(0XDE00 << 16);
    // 0x801DCCC0: sw          $t1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r9;
    // 0x801DCCC4: lw          $t4, 0x8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X8);
    // 0x801DCCC8: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x801DCCCC: sw          $t2, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r10;
    // 0x801DCCD0: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x801DCCD4: lw          $t5, 0x8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8);
    // 0x801DCCD8: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x801DCCDC: addiu       $t0, $t0, -0x51D0
    ctx->r8 = ADD32(ctx->r8, -0X51D0);
    // 0x801DCCE0: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
    // 0x801DCCE4: lw          $t6, -0x4514($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4514);
    // 0x801DCCE8: lui         $t2, 0x8011
    ctx->r10 = S32(0X8011 << 16);
    // 0x801DCCEC: lui         $t4, 0xE300
    ctx->r12 = S32(0XE300 << 16);
    // 0x801DCCF0: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x801DCCF4: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x801DCCF8: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x801DCCFC: sw          $t7, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r15;
    // 0x801DCD00: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x801DCD04: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x801DCD08: ori         $t4, $t4, 0x1001
    ctx->r12 = ctx->r12 | 0X1001;
    // 0x801DCD0C: ori         $t6, $zero, 0x8000
    ctx->r14 = 0 | 0X8000;
    // 0x801DCD10: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x801DCD14: lw          $t2, -0x4514($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4514);
    // 0x801DCD18: sw          $t2, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r10;
    // 0x801DCD1C: lw          $t5, 0x0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X0);
    // 0x801DCD20: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x801DCD24: sw          $t3, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r11;
    // 0x801DCD28: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x801DCD2C: lw          $t7, 0x0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X0);
    // 0x801DCD30: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    // 0x801DCD34: jr          $ra
    // 0x801DCD38: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    return;
    // 0x801DCD38: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
;}
RECOMP_FUNC void func_801DCD3C_0BA450(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801DCD3C: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x801DCD40: lw          $t6, -0x4514($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4514);
    // 0x801DCD44: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x801DCD48: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x801DCD4C: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    // 0x801DCD50: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x801DCD54: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x801DCD58: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x801DCD5C: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x801DCD60: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x801DCD64: sw          $t7, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r15;
    // 0x801DCD68: lui         $t8, 0xDE00
    ctx->r24 = S32(0XDE00 << 16);
    // 0x801DCD6C: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x801DCD70: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x801DCD74: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x801DCD78: addiu       $t0, $t0, -0x5950
    ctx->r8 = ADD32(ctx->r8, -0X5950);
    // 0x801DCD7C: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x801DCD80: lui         $t2, 0x8011
    ctx->r10 = S32(0X8011 << 16);
    // 0x801DCD84: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x801DCD88: lw          $t4, -0x2E34($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2E34);
    // 0x801DCD8C: lw          $t2, -0x4514($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4514);
    // 0x801DCD90: addiu       $t6, $zero, 0x1F
    ctx->r14 = ADD32(0, 0X1F);
    // 0x801DCD94: andi        $t5, $t4, 0x1F
    ctx->r13 = ctx->r12 & 0X1F;
    // 0x801DCD98: subu        $t7, $t6, $t5
    ctx->r15 = SUB32(ctx->r14, ctx->r13);
    // 0x801DCD9C: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
    // 0x801DCDA0: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x801DCDA4: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x801DCDA8: sw          $t3, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r11;
    // 0x801DCDAC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x801DCDB0: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x801DCDB4: lui         $at, 0xF200
    ctx->r1 = S32(0XF200 << 16);
    // 0x801DCDB8: or          $t0, $t9, $at
    ctx->r8 = ctx->r25 | ctx->r1;
    // 0x801DCDBC: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x801DCDC0: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x801DCDC4: lui         $t2, 0x7
    ctx->r10 = S32(0X7 << 16);
    // 0x801DCDC8: ori         $t2, $t2, 0xC07C
    ctx->r10 = ctx->r10 | 0XC07C;
    // 0x801DCDCC: lui         $t4, 0x8011
    ctx->r12 = S32(0X8011 << 16);
    // 0x801DCDD0: sw          $t2, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r10;
    // 0x801DCDD4: lw          $t4, -0x4514($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4514);
    // 0x801DCDD8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x801DCDDC: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x801DCDE0: sw          $t4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r12;
    // 0x801DCDE4: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x801DCDE8: addiu       $t6, $t4, 0x8
    ctx->r14 = ADD32(ctx->r12, 0X8);
    // 0x801DCDEC: sw          $t6, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r14;
    // 0x801DCDF0: sw          $t5, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r13;
    // 0x801DCDF4: lbu         $t8, 0x4F($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X4F);
    // 0x801DCDF8: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x801DCDFC: lui         $at, 0xFF40
    ctx->r1 = S32(0XFF40 << 16);
    // 0x801DCE00: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x801DCE04: or          $t0, $t9, $at
    ctx->r8 = ctx->r25 | ctx->r1;
    // 0x801DCE08: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x801DCE0C: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x801DCE10: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801DCE14: addiu       $t6, $t6, -0x2A28
    ctx->r14 = ADD32(ctx->r14, -0X2A28);
    // 0x801DCE18: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x801DCE1C: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x801DCE20: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x801DCE24: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x801DCE28: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x801DCE2C: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x801DCE30: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x801DCE34: addu        $t5, $t3, $t6
    ctx->r13 = ADD32(ctx->r11, ctx->r14);
    // 0x801DCE38: lwc1        $f4, 0x64($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X64);
    // 0x801DCE3C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DCE40: lwc1        $f8, 0x7BC4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7BC4);
    // 0x801DCE44: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DCE48: lw          $a3, 0x60($t5)
    ctx->r7 = MEM_W(ctx->r13, 0X60);
    // 0x801DCE4C: lwc1        $f10, 0x7BC8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7BC8);
    // 0x801DCE50: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x801DCE54: lwc1        $f6, 0x68($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X68);
    // 0x801DCE58: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DCE5C: lwc1        $f16, 0x7BCC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7BCC);
    // 0x801DCE60: addiu       $t4, $t3, 0xA4
    ctx->r12 = ADD32(ctx->r11, 0XA4);
    // 0x801DCE64: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x801DCE68: addiu       $a0, $a0, -0x4F70
    ctx->r4 = ADD32(ctx->r4, -0X4F70);
    // 0x801DCE6C: addu        $a2, $t4, $t6
    ctx->r6 = ADD32(ctx->r12, ctx->r14);
    // 0x801DCE70: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801DCE74: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x801DCE78: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x801DCE7C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x801DCE80: jal         0x800C6868
    // 0x801DCE84: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    func_800C6868(rdram, ctx);
        goto after_0;
    // 0x801DCE84: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    after_0:
    // 0x801DCE88: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x801DCE8C: lw          $t7, -0x4514($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4514);
    // 0x801DCE90: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x801DCE94: lui         $t9, 0xD900
    ctx->r25 = S32(0XD900 << 16);
    // 0x801DCE98: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x801DCE9C: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x801DCEA0: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x801DCEA4: sw          $t8, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r24;
    // 0x801DCEA8: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x801DCEAC: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x801DCEB0: lui         $t2, 0x8011
    ctx->r10 = S32(0X8011 << 16);
    // 0x801DCEB4: lui         $t3, 0xDE00
    ctx->r11 = S32(0XDE00 << 16);
    // 0x801DCEB8: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x801DCEBC: lw          $t2, -0x4514($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4514);
    // 0x801DCEC0: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x801DCEC4: addiu       $t5, $t5, -0x51D0
    ctx->r13 = ADD32(ctx->r13, -0X51D0);
    // 0x801DCEC8: sw          $t2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r10;
    // 0x801DCECC: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x801DCED0: addiu       $t4, $t2, 0x8
    ctx->r12 = ADD32(ctx->r10, 0X8);
    // 0x801DCED4: sw          $t4, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r12;
    // 0x801DCED8: sw          $t3, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r11;
    // 0x801DCEDC: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x801DCEE0: sw          $t5, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r13;
    // 0x801DCEE4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x801DCEE8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x801DCEEC: jr          $ra
    // 0x801DCEF0: nop

    return;
    // 0x801DCEF0: nop

;}
RECOMP_FUNC void func_801DCEF4_0BA450(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801DCEF4: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x801DCEF8: lw          $t6, -0x4514($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4514);
    // 0x801DCEFC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801DCF00: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x801DCF04: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    // 0x801DCF08: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x801DCF0C: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x801DCF10: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x801DCF14: sw          $t7, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r15;
    // 0x801DCF18: lui         $t8, 0xDE00
    ctx->r24 = S32(0XDE00 << 16);
    // 0x801DCF1C: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x801DCF20: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x801DCF24: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x801DCF28: addiu       $t0, $t0, -0x59C0
    ctx->r8 = ADD32(ctx->r8, -0X59C0);
    // 0x801DCF2C: lui         $t2, 0x8011
    ctx->r10 = S32(0X8011 << 16);
    // 0x801DCF30: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x801DCF34: lw          $t2, -0x4514($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4514);
    // 0x801DCF38: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x801DCF3C: lw          $t4, -0x2E34($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2E34);
    // 0x801DCF40: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    // 0x801DCF44: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x801DCF48: andi        $t5, $t4, 0x3F
    ctx->r13 = ctx->r12 & 0X3F;
    // 0x801DCF4C: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x801DCF50: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x801DCF54: sw          $t3, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r11;
    // 0x801DCF58: lui         $at, 0xF200
    ctx->r1 = S32(0XF200 << 16);
    // 0x801DCF5C: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x801DCF60: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x801DCF64: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x801DCF68: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x801DCF6C: lui         $t0, 0x7
    ctx->r8 = S32(0X7 << 16);
    // 0x801DCF70: ori         $t0, $t0, 0xC07C
    ctx->r8 = ctx->r8 | 0XC07C;
    // 0x801DCF74: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x801DCF78: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801DCF7C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801DCF80: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801DCF84: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x801DCF88: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801DCF8C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801DCF90: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801DCF94: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801DCF98: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801DCF9C: ori         $t2, $zero, 0xFFFF
    ctx->r10 = 0 | 0XFFFF;
    // 0x801DCFA0: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x801DCFA4: addiu       $a0, $a0, 0x3510
    ctx->r4 = ADD32(ctx->r4, 0X3510);
    // 0x801DCFA8: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x801DCFAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801DCFB0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801DCFB4: lui         $a3, 0x4248
    ctx->r7 = S32(0X4248 << 16);
    // 0x801DCFB8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x801DCFBC: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x801DCFC0: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x801DCFC4: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x801DCFC8: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x801DCFCC: jal         0x800C58E8
    // 0x801DCFD0: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    func_800C58E8(rdram, ctx);
        goto after_0;
    // 0x801DCFD0: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x801DCFD4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801DCFD8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801DCFDC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801DCFE0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x801DCFE4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801DCFE8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801DCFEC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801DCFF0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801DCFF4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801DCFF8: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x801DCFFC: ori         $t3, $zero, 0xFFFF
    ctx->r11 = 0 | 0XFFFF;
    // 0x801DD000: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x801DD004: addiu       $a0, $a0, 0x3510
    ctx->r4 = ADD32(ctx->r4, 0X3510);
    // 0x801DD008: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801DD00C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801DD010: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x801DD014: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x801DD018: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x801DD01C: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x801DD020: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    // 0x801DD024: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    // 0x801DD028: jal         0x800C58E8
    // 0x801DD02C: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    func_800C58E8(rdram, ctx);
        goto after_1;
    // 0x801DD02C: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x801DD030: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x801DD034: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x801DD038: jr          $ra
    // 0x801DD03C: nop

    return;
    // 0x801DD03C: nop

;}
RECOMP_FUNC void func_801DD040_0BA450(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801DD040: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x801DD044: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801DD048: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801DD04C: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x801DD050: addiu       $t6, $t6, -0x2E18
    ctx->r14 = ADD32(ctx->r14, -0X2E18);
    // 0x801DD054: lw          $s0, 0x28($t6)
    ctx->r16 = MEM_W(ctx->r14, 0X28);
    // 0x801DD058: beq         $s0, $zero, L_801DD078
    if (ctx->r16 == 0) {
        // 0x801DD05C: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_801DD078;
    }
    // 0x801DD05C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801DD060: beq         $s0, $at, L_801DD0DC
    if (ctx->r16 == ctx->r1) {
        // 0x801DD064: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_801DD0DC;
    }
    // 0x801DD064: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801DD068: beq         $s0, $at, L_801DD148
    if (ctx->r16 == ctx->r1) {
        // 0x801DD06C: nop
    
            goto L_801DD148;
    }
    // 0x801DD06C: nop

    // 0x801DD070: b           L_801DD1A4
    // 0x801DD074: nop

        goto L_801DD1A4;
    // 0x801DD074: nop

L_801DD078:
    // 0x801DD078: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801DD07C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801DD080: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801DD084: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x801DD088: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801DD08C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801DD090: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801DD094: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801DD098: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801DD09C: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801DD0A0: ori         $t7, $zero, 0xFFFF
    ctx->r15 = 0 | 0XFFFF;
    // 0x801DD0A4: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x801DD0A8: addiu       $a0, $a0, -0x47B8
    ctx->r4 = ADD32(ctx->r4, -0X47B8);
    // 0x801DD0AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801DD0B0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801DD0B4: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x801DD0B8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x801DD0BC: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x801DD0C0: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x801DD0C4: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x801DD0C8: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x801DD0CC: jal         0x800C58E8
    // 0x801DD0D0: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    func_800C58E8(rdram, ctx);
        goto after_0;
    // 0x801DD0D0: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x801DD0D4: b           L_801DD1A4
    // 0x801DD0D8: nop

        goto L_801DD1A4;
    // 0x801DD0D8: nop

L_801DD0DC:
    // 0x801DD0DC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801DD0E0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801DD0E4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801DD0E8: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x801DD0EC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801DD0F0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801DD0F4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801DD0F8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801DD0FC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801DD100: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801DD104: ori         $t8, $zero, 0xFFFF
    ctx->r24 = 0 | 0XFFFF;
    // 0x801DD108: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x801DD10C: addiu       $a0, $a0, -0x4750
    ctx->r4 = ADD32(ctx->r4, -0X4750);
    // 0x801DD110: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801DD114: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801DD118: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x801DD11C: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x801DD120: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x801DD124: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x801DD128: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    // 0x801DD12C: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    // 0x801DD130: jal         0x800C58E8
    // 0x801DD134: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    func_800C58E8(rdram, ctx);
        goto after_1;
    // 0x801DD134: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x801DD138: jal         0x801DCEF4
    // 0x801DD13C: nop

    func_801DCEF4_0BA450(rdram, ctx);
        goto after_2;
    // 0x801DD13C: nop

    after_2:
    // 0x801DD140: b           L_801DD1A4
    // 0x801DD144: nop

        goto L_801DD1A4;
    // 0x801DD144: nop

L_801DD148:
    // 0x801DD148: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801DD14C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801DD150: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801DD154: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x801DD158: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801DD15C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801DD160: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801DD164: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801DD168: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801DD16C: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801DD170: ori         $t9, $zero, 0xFFFF
    ctx->r25 = 0 | 0XFFFF;
    // 0x801DD174: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x801DD178: addiu       $a0, $a0, -0x4728
    ctx->r4 = ADD32(ctx->r4, -0X4728);
    // 0x801DD17C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801DD180: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801DD184: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x801DD188: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x801DD18C: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x801DD190: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x801DD194: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    // 0x801DD198: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x801DD19C: jal         0x800C58E8
    // 0x801DD1A0: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    func_800C58E8(rdram, ctx);
        goto after_3;
    // 0x801DD1A0: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    after_3:
L_801DD1A4:
    // 0x801DD1A4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x801DD1A8: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x801DD1AC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x801DD1B0: jr          $ra
    // 0x801DD1B4: nop

    return;
    // 0x801DD1B4: nop

;}
RECOMP_FUNC void func_801DD1B8_0BA450(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801DD1B8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801DD1BC: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x801DD1C0: lw          $t6, -0x4514($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4514);
    // 0x801DD1C4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x801DD1C8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801DD1CC: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    // 0x801DD1D0: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x801DD1D4: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x801DD1D8: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x801DD1DC: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x801DD1E0: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x801DD1E4: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x801DD1E8: sw          $t7, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r15;
    // 0x801DD1EC: lui         $t8, 0xDE00
    ctx->r24 = S32(0XDE00 << 16);
    // 0x801DD1F0: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x801DD1F4: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x801DD1F8: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x801DD1FC: addiu       $t0, $t0, -0x59F0
    ctx->r8 = ADD32(ctx->r8, -0X59F0);
    // 0x801DD200: lui         $t2, 0x8011
    ctx->r10 = S32(0X8011 << 16);
    // 0x801DD204: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x801DD208: lw          $t2, -0x4514($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4514);
    // 0x801DD20C: lui         $t4, 0xE700
    ctx->r12 = S32(0XE700 << 16);
    // 0x801DD210: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x801DD214: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    // 0x801DD218: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x801DD21C: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x801DD220: sw          $t3, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r11;
    // 0x801DD224: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x801DD228: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x801DD22C: lui         $t9, 0xFB00
    ctx->r25 = S32(0XFB00 << 16);
    // 0x801DD230: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x801DD234: lw          $t7, -0x4514($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4514);
    // 0x801DD238: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x801DD23C: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x801DD240: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x801DD244: sw          $t8, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r24;
    // 0x801DD248: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x801DD24C: lbu         $t1, 0x5F($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X5F);
    // 0x801DD250: lbu         $t4, 0x63($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X63);
    // 0x801DD254: lbu         $t8, 0x67($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X67);
    // 0x801DD258: andi        $t2, $t1, 0xFF
    ctx->r10 = ctx->r9 & 0XFF;
    // 0x801DD25C: sll         $t3, $t2, 24
    ctx->r11 = S32(ctx->r10 << 24);
    // 0x801DD260: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x801DD264: lbu         $t2, 0x6B($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X6B);
    // 0x801DD268: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x801DD26C: or          $t7, $t3, $t6
    ctx->r15 = ctx->r11 | ctx->r14;
    // 0x801DD270: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x801DD274: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x801DD278: sll         $t0, $t9, 8
    ctx->r8 = S32(ctx->r25 << 8);
    // 0x801DD27C: or          $t1, $t7, $t0
    ctx->r9 = ctx->r15 | ctx->r8;
    // 0x801DD280: andi        $t4, $t2, 0xFF
    ctx->r12 = ctx->r10 & 0XFF;
    // 0x801DD284: or          $t5, $t1, $t4
    ctx->r13 = ctx->r9 | ctx->r12;
    // 0x801DD288: sw          $t5, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r13;
    // 0x801DD28C: lw          $t6, 0x6C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X6C);
    // 0x801DD290: beq         $t6, $zero, L_801DD46C
    if (ctx->r14 == 0) {
        // 0x801DD294: nop
    
            goto L_801DD46C;
    }
    // 0x801DD294: nop

    // 0x801DD298: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x801DD29C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801DD2A0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x801DD2A4: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x801DD2A8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x801DD2AC: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x801DD2B0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x801DD2B4: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x801DD2B8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x801DD2BC: addu        $t7, $t7, $t9
    ctx->r15 = ADD32(ctx->r15, ctx->r25);
    // 0x801DD2C0: lw          $t7, -0x2A04($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2A04);
    // 0x801DD2C4: andi        $t0, $t7, 0x8
    ctx->r8 = ctx->r15 & 0X8;
    // 0x801DD2C8: beq         $t0, $zero, L_801DD370
    if (ctx->r8 == 0) {
        // 0x801DD2CC: nop
    
            goto L_801DD370;
    }
    // 0x801DD2CC: nop

    // 0x801DD2D0: lui         $t2, 0x8011
    ctx->r10 = S32(0X8011 << 16);
    // 0x801DD2D4: lw          $t2, -0x4514($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4514);
    // 0x801DD2D8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x801DD2DC: lui         $t4, 0xFA00
    ctx->r12 = S32(0XFA00 << 16);
    // 0x801DD2E0: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x801DD2E4: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x801DD2E8: addiu       $t1, $t2, 0x8
    ctx->r9 = ADD32(ctx->r10, 0X8);
    // 0x801DD2EC: sw          $t1, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r9;
    // 0x801DD2F0: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x801DD2F4: lbu         $t3, 0x4F($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X4F);
    // 0x801DD2F8: lbu         $t9, 0x53($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X53);
    // 0x801DD2FC: lbu         $t1, 0x57($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X57);
    // 0x801DD300: andi        $t6, $t3, 0xFF
    ctx->r14 = ctx->r11 & 0XFF;
    // 0x801DD304: sll         $t8, $t6, 24
    ctx->r24 = S32(ctx->r14 << 24);
    // 0x801DD308: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x801DD30C: andi        $t7, $t9, 0xFF
    ctx->r15 = ctx->r25 & 0XFF;
    // 0x801DD310: sll         $t0, $t7, 16
    ctx->r8 = S32(ctx->r15 << 16);
    // 0x801DD314: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x801DD318: addu        $t9, $t9, $t6
    ctx->r25 = ADD32(ctx->r25, ctx->r14);
    // 0x801DD31C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x801DD320: subu        $t9, $t9, $t6
    ctx->r25 = SUB32(ctx->r25, ctx->r14);
    // 0x801DD324: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x801DD328: addu        $t9, $t9, $t6
    ctx->r25 = ADD32(ctx->r25, ctx->r14);
    // 0x801DD32C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x801DD330: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801DD334: addu        $t7, $t7, $t9
    ctx->r15 = ADD32(ctx->r15, ctx->r25);
    // 0x801DD338: lw          $t7, -0x2A04($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2A04);
    // 0x801DD33C: or          $t2, $t8, $t0
    ctx->r10 = ctx->r24 | ctx->r8;
    // 0x801DD340: andi        $t4, $t1, 0xFF
    ctx->r12 = ctx->r9 & 0XFF;
    // 0x801DD344: sll         $t5, $t4, 8
    ctx->r13 = S32(ctx->r12 << 8);
    // 0x801DD348: andi        $t8, $t7, 0x7
    ctx->r24 = ctx->r15 & 0X7;
    // 0x801DD34C: sll         $t0, $t8, 5
    ctx->r8 = S32(ctx->r24 << 5);
    // 0x801DD350: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x801DD354: subu        $t4, $t1, $t0
    ctx->r12 = SUB32(ctx->r9, ctx->r8);
    // 0x801DD358: or          $t3, $t2, $t5
    ctx->r11 = ctx->r10 | ctx->r13;
    // 0x801DD35C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x801DD360: andi        $t2, $t4, 0xFF
    ctx->r10 = ctx->r12 & 0XFF;
    // 0x801DD364: or          $t5, $t2, $t3
    ctx->r13 = ctx->r10 | ctx->r11;
    // 0x801DD368: b           L_801DD408
    // 0x801DD36C: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
        goto L_801DD408;
    // 0x801DD36C: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
L_801DD370:
    // 0x801DD370: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x801DD374: lw          $t9, -0x4514($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4514);
    // 0x801DD378: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x801DD37C: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x801DD380: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x801DD384: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x801DD388: addiu       $t7, $t9, 0x8
    ctx->r15 = ADD32(ctx->r25, 0X8);
    // 0x801DD38C: sw          $t7, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r15;
    // 0x801DD390: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x801DD394: lbu         $t0, 0x4F($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X4F);
    // 0x801DD398: lbu         $t3, 0x53($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X53);
    // 0x801DD39C: lbu         $t7, 0x57($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X57);
    // 0x801DD3A0: andi        $t4, $t0, 0xFF
    ctx->r12 = ctx->r8 & 0XFF;
    // 0x801DD3A4: sll         $t2, $t4, 24
    ctx->r10 = S32(ctx->r12 << 24);
    // 0x801DD3A8: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x801DD3AC: andi        $t5, $t3, 0xFF
    ctx->r13 = ctx->r11 & 0XFF;
    // 0x801DD3B0: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x801DD3B4: sll         $t3, $t4, 2
    ctx->r11 = S32(ctx->r12 << 2);
    // 0x801DD3B8: addu        $t3, $t3, $t4
    ctx->r11 = ADD32(ctx->r11, ctx->r12);
    // 0x801DD3BC: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x801DD3C0: subu        $t3, $t3, $t4
    ctx->r11 = SUB32(ctx->r11, ctx->r12);
    // 0x801DD3C4: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x801DD3C8: addu        $t3, $t3, $t4
    ctx->r11 = ADD32(ctx->r11, ctx->r12);
    // 0x801DD3CC: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x801DD3D0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x801DD3D4: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x801DD3D8: lw          $t5, -0x2A04($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2A04);
    // 0x801DD3DC: or          $t9, $t2, $t6
    ctx->r25 = ctx->r10 | ctx->r14;
    // 0x801DD3E0: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x801DD3E4: sll         $t1, $t8, 8
    ctx->r9 = S32(ctx->r24 << 8);
    // 0x801DD3E8: andi        $t2, $t5, 0x7
    ctx->r10 = ctx->r13 & 0X7;
    // 0x801DD3EC: sll         $t6, $t2, 5
    ctx->r14 = S32(ctx->r10 << 5);
    // 0x801DD3F0: or          $t0, $t9, $t1
    ctx->r8 = ctx->r25 | ctx->r9;
    // 0x801DD3F4: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x801DD3F8: addiu       $t7, $t6, 0x1F
    ctx->r15 = ADD32(ctx->r14, 0X1F);
    // 0x801DD3FC: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x801DD400: or          $t9, $t8, $t0
    ctx->r25 = ctx->r24 | ctx->r8;
    // 0x801DD404: sw          $t9, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r25;
L_801DD408:
    // 0x801DD408: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x801DD40C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x801DD410: addiu       $t5, $t5, -0x2A28
    ctx->r13 = ADD32(ctx->r13, -0X2A28);
    // 0x801DD414: sll         $t3, $t4, 2
    ctx->r11 = S32(ctx->r12 << 2);
    // 0x801DD418: addu        $t3, $t3, $t4
    ctx->r11 = ADD32(ctx->r11, ctx->r12);
    // 0x801DD41C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x801DD420: subu        $t3, $t3, $t4
    ctx->r11 = SUB32(ctx->r11, ctx->r12);
    // 0x801DD424: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x801DD428: addu        $t3, $t3, $t4
    ctx->r11 = ADD32(ctx->r11, ctx->r12);
    // 0x801DD42C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x801DD430: addu        $t2, $t3, $t5
    ctx->r10 = ADD32(ctx->r11, ctx->r13);
    // 0x801DD434: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x801DD438: lwc1        $f4, 0x68($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X68);
    // 0x801DD43C: lw          $a2, 0x60($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X60);
    // 0x801DD440: lw          $a3, 0x64($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X64);
    // 0x801DD444: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x801DD448: addiu       $a0, $a0, -0x4818
    ctx->r4 = ADD32(ctx->r4, -0X4818);
    // 0x801DD44C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801DD450: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x801DD454: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x801DD458: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x801DD45C: jal         0x800C60A0
    // 0x801DD460: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800C60A0(rdram, ctx);
        goto after_0;
    // 0x801DD460: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x801DD464: b           L_801DD5A0
    // 0x801DD468: nop

        goto L_801DD5A0;
    // 0x801DD468: nop

L_801DD46C:
    // 0x801DD46C: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x801DD470: lw          $t6, -0x4514($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4514);
    // 0x801DD474: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x801DD478: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x801DD47C: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x801DD480: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x801DD484: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x801DD488: sw          $t7, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r15;
    // 0x801DD48C: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x801DD490: lbu         $t9, 0x4F($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X4F);
    // 0x801DD494: lbu         $t3, 0x53($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X53);
    // 0x801DD498: lbu         $t7, 0x57($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X57);
    // 0x801DD49C: andi        $t1, $t9, 0xFF
    ctx->r9 = ctx->r25 & 0XFF;
    // 0x801DD4A0: sll         $t4, $t1, 24
    ctx->r12 = S32(ctx->r9 << 24);
    // 0x801DD4A4: andi        $t5, $t3, 0xFF
    ctx->r13 = ctx->r11 & 0XFF;
    // 0x801DD4A8: lbu         $t1, 0x5B($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X5B);
    // 0x801DD4AC: sll         $t2, $t5, 16
    ctx->r10 = S32(ctx->r13 << 16);
    // 0x801DD4B0: or          $t6, $t4, $t2
    ctx->r14 = ctx->r12 | ctx->r10;
    // 0x801DD4B4: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x801DD4B8: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x801DD4BC: sll         $t0, $t8, 8
    ctx->r8 = S32(ctx->r24 << 8);
    // 0x801DD4C0: or          $t9, $t6, $t0
    ctx->r25 = ctx->r14 | ctx->r8;
    // 0x801DD4C4: andi        $t3, $t1, 0xFF
    ctx->r11 = ctx->r9 & 0XFF;
    // 0x801DD4C8: or          $t5, $t9, $t3
    ctx->r13 = ctx->r25 | ctx->r11;
    // 0x801DD4CC: sw          $t5, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r13;
    // 0x801DD4D0: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x801DD4D4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x801DD4D8: addiu       $t8, $t8, -0x2A28
    ctx->r24 = ADD32(ctx->r24, -0X2A28);
    // 0x801DD4DC: sll         $t7, $t2, 2
    ctx->r15 = S32(ctx->r10 << 2);
    // 0x801DD4E0: addu        $t7, $t7, $t2
    ctx->r15 = ADD32(ctx->r15, ctx->r10);
    // 0x801DD4E4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801DD4E8: subu        $t7, $t7, $t2
    ctx->r15 = SUB32(ctx->r15, ctx->r10);
    // 0x801DD4EC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801DD4F0: addu        $t7, $t7, $t2
    ctx->r15 = ADD32(ctx->r15, ctx->r10);
    // 0x801DD4F4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801DD4F8: addu        $t6, $t7, $t8
    ctx->r14 = ADD32(ctx->r15, ctx->r24);
    // 0x801DD4FC: lw          $t0, 0x24($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X24);
    // 0x801DD500: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x801DD504: beq         $t1, $zero, L_801DD544
    if (ctx->r9 == 0) {
        // 0x801DD508: nop
    
            goto L_801DD544;
    }
    // 0x801DD508: nop

    // 0x801DD50C: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x801DD510: lwc1        $f8, 0x68($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X68);
    // 0x801DD514: lw          $a2, 0x60($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X60);
    // 0x801DD518: lw          $a3, 0x64($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X64);
    // 0x801DD51C: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x801DD520: addiu       $a0, $a0, -0x4818
    ctx->r4 = ADD32(ctx->r4, -0X4818);
    // 0x801DD524: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801DD528: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x801DD52C: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x801DD530: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x801DD534: jal         0x800C60A0
    // 0x801DD538: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800C60A0(rdram, ctx);
        goto after_1;
    // 0x801DD538: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x801DD53C: b           L_801DD5A0
    // 0x801DD540: nop

        goto L_801DD5A0;
    // 0x801DD540: nop

L_801DD544:
    // 0x801DD544: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x801DD548: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x801DD54C: addiu       $t5, $t5, -0x2A28
    ctx->r13 = ADD32(ctx->r13, -0X2A28);
    // 0x801DD550: sll         $t3, $t9, 2
    ctx->r11 = S32(ctx->r25 << 2);
    // 0x801DD554: addu        $t3, $t3, $t9
    ctx->r11 = ADD32(ctx->r11, ctx->r25);
    // 0x801DD558: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x801DD55C: subu        $t3, $t3, $t9
    ctx->r11 = SUB32(ctx->r11, ctx->r25);
    // 0x801DD560: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x801DD564: addu        $t3, $t3, $t9
    ctx->r11 = ADD32(ctx->r11, ctx->r25);
    // 0x801DD568: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x801DD56C: addu        $t4, $t3, $t5
    ctx->r12 = ADD32(ctx->r11, ctx->r13);
    // 0x801DD570: lwc1        $f18, 0x48($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X48);
    // 0x801DD574: lwc1        $f16, 0x68($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X68);
    // 0x801DD578: lw          $a2, 0x60($t4)
    ctx->r6 = MEM_W(ctx->r12, 0X60);
    // 0x801DD57C: lw          $a3, 0x64($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X64);
    // 0x801DD580: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x801DD584: addiu       $a0, $a0, -0x4758
    ctx->r4 = ADD32(ctx->r4, -0X4758);
    // 0x801DD588: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801DD58C: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    // 0x801DD590: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    // 0x801DD594: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x801DD598: jal         0x800C60A0
    // 0x801DD59C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800C60A0(rdram, ctx);
        goto after_2;
    // 0x801DD59C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_2:
L_801DD5A0:
    // 0x801DD5A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801DD5A4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x801DD5A8: jr          $ra
    // 0x801DD5AC: nop

    return;
    // 0x801DD5AC: nop

;}
RECOMP_FUNC void func_801DD5B0_0BA450(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801DD5B0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801DD5B4: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x801DD5B8: lw          $t6, -0x4514($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4514);
    // 0x801DD5BC: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x801DD5C0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x801DD5C4: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    // 0x801DD5C8: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x801DD5CC: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x801DD5D0: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x801DD5D4: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x801DD5D8: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x801DD5DC: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x801DD5E0: sw          $t7, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r15;
    // 0x801DD5E4: lui         $t8, 0xDE00
    ctx->r24 = S32(0XDE00 << 16);
    // 0x801DD5E8: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x801DD5EC: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x801DD5F0: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x801DD5F4: addiu       $t0, $t0, -0x59F0
    ctx->r8 = ADD32(ctx->r8, -0X59F0);
    // 0x801DD5F8: lui         $t2, 0x8011
    ctx->r10 = S32(0X8011 << 16);
    // 0x801DD5FC: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x801DD600: lw          $t2, -0x4514($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4514);
    // 0x801DD604: lui         $t4, 0xE700
    ctx->r12 = S32(0XE700 << 16);
    // 0x801DD608: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x801DD60C: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    // 0x801DD610: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x801DD614: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x801DD618: sw          $t3, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r11;
    // 0x801DD61C: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x801DD620: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x801DD624: lui         $t9, 0xFB00
    ctx->r25 = S32(0XFB00 << 16);
    // 0x801DD628: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x801DD62C: lw          $t7, -0x4514($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4514);
    // 0x801DD630: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x801DD634: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x801DD638: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x801DD63C: sw          $t8, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r24;
    // 0x801DD640: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x801DD644: lbu         $t1, 0x5F($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X5F);
    // 0x801DD648: lbu         $t4, 0x63($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X63);
    // 0x801DD64C: lbu         $t8, 0x67($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X67);
    // 0x801DD650: andi        $t2, $t1, 0xFF
    ctx->r10 = ctx->r9 & 0XFF;
    // 0x801DD654: sll         $t3, $t2, 24
    ctx->r11 = S32(ctx->r10 << 24);
    // 0x801DD658: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x801DD65C: lbu         $t2, 0x6B($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X6B);
    // 0x801DD660: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x801DD664: or          $t7, $t3, $t6
    ctx->r15 = ctx->r11 | ctx->r14;
    // 0x801DD668: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x801DD66C: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x801DD670: sll         $t0, $t9, 8
    ctx->r8 = S32(ctx->r25 << 8);
    // 0x801DD674: or          $t1, $t7, $t0
    ctx->r9 = ctx->r15 | ctx->r8;
    // 0x801DD678: andi        $t4, $t2, 0xFF
    ctx->r12 = ctx->r10 & 0XFF;
    // 0x801DD67C: or          $t5, $t1, $t4
    ctx->r13 = ctx->r9 | ctx->r12;
    // 0x801DD680: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x801DD684: sw          $t5, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r13;
    // 0x801DD688: lw          $t6, -0x4514($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4514);
    // 0x801DD68C: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x801DD690: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x801DD694: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x801DD698: addiu       $t8, $t6, 0x8
    ctx->r24 = ADD32(ctx->r14, 0X8);
    // 0x801DD69C: sw          $t8, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r24;
    // 0x801DD6A0: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x801DD6A4: lbu         $t0, 0x4F($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X4F);
    // 0x801DD6A8: lbu         $t4, 0x53($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X53);
    // 0x801DD6AC: lbu         $t8, 0x57($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X57);
    // 0x801DD6B0: andi        $t2, $t0, 0xFF
    ctx->r10 = ctx->r8 & 0XFF;
    // 0x801DD6B4: sll         $t1, $t2, 24
    ctx->r9 = S32(ctx->r10 << 24);
    // 0x801DD6B8: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x801DD6BC: lbu         $t2, 0x5B($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X5B);
    // 0x801DD6C0: sll         $t3, $t5, 16
    ctx->r11 = S32(ctx->r13 << 16);
    // 0x801DD6C4: or          $t6, $t1, $t3
    ctx->r14 = ctx->r9 | ctx->r11;
    // 0x801DD6C8: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x801DD6CC: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x801DD6D0: sll         $t7, $t9, 8
    ctx->r15 = S32(ctx->r25 << 8);
    // 0x801DD6D4: or          $t0, $t6, $t7
    ctx->r8 = ctx->r14 | ctx->r15;
    // 0x801DD6D8: andi        $t4, $t2, 0xFF
    ctx->r12 = ctx->r10 & 0XFF;
    // 0x801DD6DC: or          $t5, $t0, $t4
    ctx->r13 = ctx->r8 | ctx->r12;
    // 0x801DD6E0: sw          $t5, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r13;
    // 0x801DD6E4: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x801DD6E8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801DD6EC: addiu       $t9, $t9, -0x2A28
    ctx->r25 = ADD32(ctx->r25, -0X2A28);
    // 0x801DD6F0: sll         $t8, $t3, 2
    ctx->r24 = S32(ctx->r11 << 2);
    // 0x801DD6F4: addu        $t8, $t8, $t3
    ctx->r24 = ADD32(ctx->r24, ctx->r11);
    // 0x801DD6F8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x801DD6FC: subu        $t8, $t8, $t3
    ctx->r24 = SUB32(ctx->r24, ctx->r11);
    // 0x801DD700: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x801DD704: addu        $t8, $t8, $t3
    ctx->r24 = ADD32(ctx->r24, ctx->r11);
    // 0x801DD708: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x801DD70C: addu        $t6, $t8, $t9
    ctx->r14 = ADD32(ctx->r24, ctx->r25);
    // 0x801DD710: lw          $t7, 0x24($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X24);
    // 0x801DD714: andi        $t2, $t7, 0x1
    ctx->r10 = ctx->r15 & 0X1;
    // 0x801DD718: beq         $t2, $zero, L_801DD760
    if (ctx->r10 == 0) {
        // 0x801DD71C: nop
    
            goto L_801DD760;
    }
    // 0x801DD71C: nop

    // 0x801DD720: lwc1        $f4, 0x64($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X64);
    // 0x801DD724: lw          $a3, 0x60($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X60);
    // 0x801DD728: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x801DD72C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x801DD730: lwc1        $f6, 0x68($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X68);
    // 0x801DD734: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x801DD738: addiu       $a0, $a0, -0x4948
    ctx->r4 = ADD32(ctx->r4, -0X4948);
    // 0x801DD73C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801DD740: addiu       $a2, $t6, 0xA4
    ctx->r6 = ADD32(ctx->r14, 0XA4);
    // 0x801DD744: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x801DD748: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x801DD74C: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x801DD750: jal         0x800C6868
    // 0x801DD754: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_800C6868(rdram, ctx);
        goto after_0;
    // 0x801DD754: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x801DD758: b           L_801DD7C8
    // 0x801DD75C: nop

        goto L_801DD7C8;
    // 0x801DD75C: nop

L_801DD760:
    // 0x801DD760: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x801DD764: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x801DD768: addiu       $t1, $t1, -0x2A28
    ctx->r9 = ADD32(ctx->r9, -0X2A28);
    // 0x801DD76C: sll         $t4, $t0, 2
    ctx->r12 = S32(ctx->r8 << 2);
    // 0x801DD770: addu        $t4, $t4, $t0
    ctx->r12 = ADD32(ctx->r12, ctx->r8);
    // 0x801DD774: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x801DD778: subu        $t4, $t4, $t0
    ctx->r12 = SUB32(ctx->r12, ctx->r8);
    // 0x801DD77C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x801DD780: addu        $t4, $t4, $t0
    ctx->r12 = ADD32(ctx->r12, ctx->r8);
    // 0x801DD784: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x801DD788: addu        $t3, $t4, $t1
    ctx->r11 = ADD32(ctx->r12, ctx->r9);
    // 0x801DD78C: lwc1        $f10, 0x64($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X64);
    // 0x801DD790: lw          $a3, 0x60($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X60);
    // 0x801DD794: lwc1        $f18, 0x48($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X48);
    // 0x801DD798: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x801DD79C: lwc1        $f16, 0x68($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X68);
    // 0x801DD7A0: addiu       $t5, $t4, 0xA4
    ctx->r13 = ADD32(ctx->r12, 0XA4);
    // 0x801DD7A4: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x801DD7A8: addiu       $a0, $a0, -0x4910
    ctx->r4 = ADD32(ctx->r4, -0X4910);
    // 0x801DD7AC: addu        $a2, $t5, $t1
    ctx->r6 = ADD32(ctx->r13, ctx->r9);
    // 0x801DD7B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801DD7B4: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    // 0x801DD7B8: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    // 0x801DD7BC: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    // 0x801DD7C0: jal         0x800C6868
    // 0x801DD7C4: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    func_800C6868(rdram, ctx);
        goto after_1;
    // 0x801DD7C4: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    after_1:
L_801DD7C8:
    // 0x801DD7C8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x801DD7CC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x801DD7D0: jr          $ra
    // 0x801DD7D4: nop

    return;
    // 0x801DD7D4: nop

;}
RECOMP_FUNC void func_801DD7D8_0BA450(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801DD7D8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801DD7DC: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x801DD7E0: lw          $t6, -0x4514($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4514);
    // 0x801DD7E4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x801DD7E8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801DD7EC: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x801DD7F0: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x801DD7F4: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x801DD7F8: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x801DD7FC: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x801DD800: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x801DD804: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x801DD808: sw          $t7, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r15;
    // 0x801DD80C: lui         $t8, 0xDE00
    ctx->r24 = S32(0XDE00 << 16);
    // 0x801DD810: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x801DD814: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x801DD818: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x801DD81C: addiu       $t0, $t0, -0x59F0
    ctx->r8 = ADD32(ctx->r8, -0X59F0);
    // 0x801DD820: lui         $t2, 0x8011
    ctx->r10 = S32(0X8011 << 16);
    // 0x801DD824: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x801DD828: lw          $t2, -0x4514($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4514);
    // 0x801DD82C: lui         $t4, 0xE700
    ctx->r12 = S32(0XE700 << 16);
    // 0x801DD830: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x801DD834: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x801DD838: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x801DD83C: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x801DD840: sw          $t3, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r11;
    // 0x801DD844: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x801DD848: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x801DD84C: lui         $t9, 0xFB00
    ctx->r25 = S32(0XFB00 << 16);
    // 0x801DD850: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x801DD854: lw          $t7, -0x4514($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4514);
    // 0x801DD858: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x801DD85C: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x801DD860: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x801DD864: sw          $t8, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r24;
    // 0x801DD868: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x801DD86C: lbu         $t1, 0x57($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X57);
    // 0x801DD870: lbu         $t4, 0x5B($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X5B);
    // 0x801DD874: lbu         $t8, 0x5F($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X5F);
    // 0x801DD878: andi        $t2, $t1, 0xFF
    ctx->r10 = ctx->r9 & 0XFF;
    // 0x801DD87C: sll         $t3, $t2, 24
    ctx->r11 = S32(ctx->r10 << 24);
    // 0x801DD880: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x801DD884: lbu         $t2, 0x63($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X63);
    // 0x801DD888: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x801DD88C: or          $t7, $t3, $t6
    ctx->r15 = ctx->r11 | ctx->r14;
    // 0x801DD890: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x801DD894: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x801DD898: sll         $t0, $t9, 8
    ctx->r8 = S32(ctx->r25 << 8);
    // 0x801DD89C: or          $t1, $t7, $t0
    ctx->r9 = ctx->r15 | ctx->r8;
    // 0x801DD8A0: andi        $t4, $t2, 0xFF
    ctx->r12 = ctx->r10 & 0XFF;
    // 0x801DD8A4: or          $t5, $t1, $t4
    ctx->r13 = ctx->r9 | ctx->r12;
    // 0x801DD8A8: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x801DD8AC: sw          $t5, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r13;
    // 0x801DD8B0: lw          $t6, -0x4514($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4514);
    // 0x801DD8B4: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x801DD8B8: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x801DD8BC: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x801DD8C0: addiu       $t8, $t6, 0x8
    ctx->r24 = ADD32(ctx->r14, 0X8);
    // 0x801DD8C4: sw          $t8, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r24;
    // 0x801DD8C8: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x801DD8CC: lbu         $t0, 0x47($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X47);
    // 0x801DD8D0: lbu         $t4, 0x4B($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X4B);
    // 0x801DD8D4: lbu         $t8, 0x4F($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X4F);
    // 0x801DD8D8: andi        $t2, $t0, 0xFF
    ctx->r10 = ctx->r8 & 0XFF;
    // 0x801DD8DC: sll         $t1, $t2, 24
    ctx->r9 = S32(ctx->r10 << 24);
    // 0x801DD8E0: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x801DD8E4: lbu         $t2, 0x53($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X53);
    // 0x801DD8E8: sll         $t3, $t5, 16
    ctx->r11 = S32(ctx->r13 << 16);
    // 0x801DD8EC: or          $t6, $t1, $t3
    ctx->r14 = ctx->r9 | ctx->r11;
    // 0x801DD8F0: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x801DD8F4: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x801DD8F8: sll         $t7, $t9, 8
    ctx->r15 = S32(ctx->r25 << 8);
    // 0x801DD8FC: or          $t0, $t6, $t7
    ctx->r8 = ctx->r14 | ctx->r15;
    // 0x801DD900: andi        $t4, $t2, 0xFF
    ctx->r12 = ctx->r10 & 0XFF;
    // 0x801DD904: or          $t5, $t0, $t4
    ctx->r13 = ctx->r8 | ctx->r12;
    // 0x801DD908: sw          $t5, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r13;
    // 0x801DD90C: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x801DD910: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801DD914: addiu       $t9, $t9, -0x2A28
    ctx->r25 = ADD32(ctx->r25, -0X2A28);
    // 0x801DD918: sll         $t8, $t3, 2
    ctx->r24 = S32(ctx->r11 << 2);
    // 0x801DD91C: addu        $t8, $t8, $t3
    ctx->r24 = ADD32(ctx->r24, ctx->r11);
    // 0x801DD920: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x801DD924: subu        $t8, $t8, $t3
    ctx->r24 = SUB32(ctx->r24, ctx->r11);
    // 0x801DD928: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x801DD92C: addu        $t8, $t8, $t3
    ctx->r24 = ADD32(ctx->r24, ctx->r11);
    // 0x801DD930: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x801DD934: addu        $t6, $t8, $t9
    ctx->r14 = ADD32(ctx->r24, ctx->r25);
    // 0x801DD938: lw          $t7, 0x24($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X24);
    // 0x801DD93C: andi        $t2, $t7, 0x1
    ctx->r10 = ctx->r15 & 0X1;
    // 0x801DD940: beq         $t2, $zero, L_801DD980
    if (ctx->r10 == 0) {
        // 0x801DD944: nop
    
            goto L_801DD980;
    }
    // 0x801DD944: nop

    // 0x801DD948: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x801DD94C: lwc1        $f4, 0x68($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X68);
    // 0x801DD950: lw          $a2, 0x60($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X60);
    // 0x801DD954: lw          $a3, 0x64($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X64);
    // 0x801DD958: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x801DD95C: addiu       $a0, $a0, -0x48D8
    ctx->r4 = ADD32(ctx->r4, -0X48D8);
    // 0x801DD960: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801DD964: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x801DD968: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x801DD96C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x801DD970: jal         0x800C60A0
    // 0x801DD974: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800C60A0(rdram, ctx);
        goto after_0;
    // 0x801DD974: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x801DD978: b           L_801DD9DC
    // 0x801DD97C: nop

        goto L_801DD9DC;
    // 0x801DD97C: nop

L_801DD980:
    // 0x801DD980: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x801DD984: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x801DD988: addiu       $t5, $t5, -0x2A28
    ctx->r13 = ADD32(ctx->r13, -0X2A28);
    // 0x801DD98C: sll         $t4, $t0, 2
    ctx->r12 = S32(ctx->r8 << 2);
    // 0x801DD990: addu        $t4, $t4, $t0
    ctx->r12 = ADD32(ctx->r12, ctx->r8);
    // 0x801DD994: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x801DD998: subu        $t4, $t4, $t0
    ctx->r12 = SUB32(ctx->r12, ctx->r8);
    // 0x801DD99C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x801DD9A0: addu        $t4, $t4, $t0
    ctx->r12 = ADD32(ctx->r12, ctx->r8);
    // 0x801DD9A4: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x801DD9A8: addu        $t1, $t4, $t5
    ctx->r9 = ADD32(ctx->r12, ctx->r13);
    // 0x801DD9AC: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x801DD9B0: lwc1        $f8, 0x68($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X68);
    // 0x801DD9B4: lw          $a2, 0x60($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X60);
    // 0x801DD9B8: lw          $a3, 0x64($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X64);
    // 0x801DD9BC: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x801DD9C0: addiu       $a0, $a0, -0x48A8
    ctx->r4 = ADD32(ctx->r4, -0X48A8);
    // 0x801DD9C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801DD9C8: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x801DD9CC: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x801DD9D0: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x801DD9D4: jal         0x800C60A0
    // 0x801DD9D8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800C60A0(rdram, ctx);
        goto after_1;
    // 0x801DD9D8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_1:
L_801DD9DC:
    // 0x801DD9DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801DD9E0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x801DD9E4: jr          $ra
    // 0x801DD9E8: nop

    return;
    // 0x801DD9E8: nop

;}
RECOMP_FUNC void func_801DD9EC_0BA450(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801DD9EC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801DD9F0: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x801DD9F4: lw          $t6, -0x4514($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4514);
    // 0x801DD9F8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x801DD9FC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x801DDA00: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    // 0x801DDA04: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x801DDA08: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x801DDA0C: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x801DDA10: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x801DDA14: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x801DDA18: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x801DDA1C: sw          $t7, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r15;
    // 0x801DDA20: lui         $t8, 0xDE00
    ctx->r24 = S32(0XDE00 << 16);
    // 0x801DDA24: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x801DDA28: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x801DDA2C: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x801DDA30: addiu       $t0, $t0, -0x4FE0
    ctx->r8 = ADD32(ctx->r8, -0X4FE0);
    // 0x801DDA34: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x801DDA38: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x801DDA3C: lw          $t4, -0x2E34($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2E34);
    // 0x801DDA40: lui         $t2, 0x8011
    ctx->r10 = S32(0X8011 << 16);
    // 0x801DDA44: lw          $t2, -0x4514($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4514);
    // 0x801DDA48: addiu       $t6, $zero, 0x1F
    ctx->r14 = ADD32(0, 0X1F);
    // 0x801DDA4C: andi        $t5, $t4, 0x1F
    ctx->r13 = ctx->r12 & 0X1F;
    // 0x801DDA50: subu        $t7, $t6, $t5
    ctx->r15 = SUB32(ctx->r14, ctx->r13);
    // 0x801DDA54: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x801DDA58: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x801DDA5C: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    // 0x801DDA60: addiu       $t2, $zero, 0x1F
    ctx->r10 = ADD32(0, 0X1F);
    // 0x801DDA64: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x801DDA68: sw          $t3, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r11;
    // 0x801DDA6C: subu        $t3, $t2, $t5
    ctx->r11 = SUB32(ctx->r10, ctx->r13);
    // 0x801DDA70: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x801DDA74: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x801DDA78: lui         $at, 0xF200
    ctx->r1 = S32(0XF200 << 16);
    // 0x801DDA7C: sll         $t0, $t9, 12
    ctx->r8 = S32(ctx->r25 << 12);
    // 0x801DDA80: or          $t1, $t0, $at
    ctx->r9 = ctx->r8 | ctx->r1;
    // 0x801DDA84: andi        $t6, $t4, 0xFFF
    ctx->r14 = ctx->r12 & 0XFFF;
    // 0x801DDA88: or          $t7, $t1, $t6
    ctx->r15 = ctx->r9 | ctx->r14;
    // 0x801DDA8C: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x801DDA90: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x801DDA94: lui         $t9, 0x7
    ctx->r25 = S32(0X7 << 16);
    // 0x801DDA98: ori         $t9, $t9, 0xC07C
    ctx->r25 = ctx->r25 | 0XC07C;
    // 0x801DDA9C: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x801DDAA0: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x801DDAA4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x801DDAA8: addiu       $t4, $t4, -0x2A28
    ctx->r12 = ADD32(ctx->r12, -0X2A28);
    // 0x801DDAAC: sll         $t5, $t2, 2
    ctx->r13 = S32(ctx->r10 << 2);
    // 0x801DDAB0: addu        $t5, $t5, $t2
    ctx->r13 = ADD32(ctx->r13, ctx->r10);
    // 0x801DDAB4: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x801DDAB8: subu        $t5, $t5, $t2
    ctx->r13 = SUB32(ctx->r13, ctx->r10);
    // 0x801DDABC: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x801DDAC0: addu        $t5, $t5, $t2
    ctx->r13 = ADD32(ctx->r13, ctx->r10);
    // 0x801DDAC4: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x801DDAC8: addu        $t1, $t5, $t4
    ctx->r9 = ADD32(ctx->r13, ctx->r12);
    // 0x801DDACC: lwc1        $f4, 0x64($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X64);
    // 0x801DDAD0: lw          $a3, 0x60($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X60);
    // 0x801DDAD4: lwc1        $f16, 0x4C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x801DDAD8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x801DDADC: lwc1        $f6, 0x68($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X68);
    // 0x801DDAE0: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x801DDAE4: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x801DDAE8: addiu       $t3, $t5, 0xA4
    ctx->r11 = ADD32(ctx->r13, 0XA4);
    // 0x801DDAEC: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x801DDAF0: addiu       $a0, $a0, -0x45A8
    ctx->r4 = ADD32(ctx->r4, -0X45A8);
    // 0x801DDAF4: addu        $a2, $t3, $t4
    ctx->r6 = ADD32(ctx->r11, ctx->r12);
    // 0x801DDAF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801DDAFC: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x801DDB00: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x801DDB04: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x801DDB08: jal         0x800C6868
    // 0x801DDB0C: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    func_800C6868(rdram, ctx);
        goto after_0;
    // 0x801DDB0C: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x801DDB10: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x801DDB14: lw          $t6, -0x4514($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4514);
    // 0x801DDB18: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x801DDB1C: lui         $t8, 0xD900
    ctx->r24 = S32(0XD900 << 16);
    // 0x801DDB20: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x801DDB24: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x801DDB28: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x801DDB2C: sw          $t7, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r15;
    // 0x801DDB30: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x801DDB34: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x801DDB38: lui         $t2, 0x8011
    ctx->r10 = S32(0X8011 << 16);
    // 0x801DDB3C: lui         $t5, 0xDE00
    ctx->r13 = S32(0XDE00 << 16);
    // 0x801DDB40: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x801DDB44: lw          $t2, -0x4514($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4514);
    // 0x801DDB48: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x801DDB4C: addiu       $t1, $t1, -0x51D0
    ctx->r9 = ADD32(ctx->r9, -0X51D0);
    // 0x801DDB50: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x801DDB54: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x801DDB58: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x801DDB5C: sw          $t3, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r11;
    // 0x801DDB60: sw          $t5, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r13;
    // 0x801DDB64: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x801DDB68: sw          $t1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r9;
    // 0x801DDB6C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x801DDB70: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x801DDB74: jr          $ra
    // 0x801DDB78: nop

    return;
    // 0x801DDB78: nop

;}
RECOMP_FUNC void func_801DDB7C_0BA450(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801DDB7C: addiu       $sp, $sp, -0xC0
    ctx->r29 = ADD32(ctx->r29, -0XC0);
    // 0x801DDB80: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x801DDB84: sw          $zero, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = 0;
L_801DDB88:
    // 0x801DDB88: lw          $t6, 0xBC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XBC);
    // 0x801DDB8C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x801DDB90: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801DDB94: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x801DDB98: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801DDB9C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x801DDBA0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801DDBA4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x801DDBA8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801DDBAC: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x801DDBB0: lw          $t8, -0x2A24($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2A24);
    // 0x801DDBB4: addiu       $t9, $t8, -0x10
    ctx->r25 = ADD32(ctx->r24, -0X10);
    // 0x801DDBB8: sltiu       $at, $t9, 0x32
    ctx->r1 = ctx->r25 < 0X32 ? 1 : 0;
    // 0x801DDBBC: beq         $at, $zero, L_801DF8E4
    if (ctx->r1 == 0) {
        // 0x801DDBC0: nop
    
            goto L_801DF8E4;
    }
    // 0x801DDBC0: nop

    // 0x801DDBC4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x801DDBC8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DDBCC: addu        $at, $at, $t9
    gpr jr_addend_801DDBD4 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x801DDBD0: lw          $t9, 0x7BD0($at)
    ctx->r25 = ADD32(ctx->r1, 0X7BD0);
    // 0x801DDBD4: jr          $t9
    // 0x801DDBD8: nop

    switch (jr_addend_801DDBD4 >> 2) {
        case 0: goto L_801DE504; break;
        case 1: goto L_801DE5F4; break;
        case 2: goto L_801DE6E4; break;
        case 3: goto L_801DE7D4; break;
        case 4: goto L_801DE8C4; break;
        case 5: goto L_801DE9B4; break;
        case 6: goto L_801DEAA4; break;
        case 7: goto L_801DEB94; break;
        case 8: goto L_801DEC84; break;
        case 9: goto L_801DED74; break;
        case 10: goto L_801DDFE0; break;
        case 11: goto L_801DE09C; break;
        case 12: goto L_801DE158; break;
        case 13: goto L_801DE214; break;
        case 14: goto L_801DE2D0; break;
        case 15: goto L_801DE38C; break;
        case 16: goto L_801DE448; break;
        case 17: goto L_801DDDA4; break;
        case 18: goto L_801DF1D4; break;
        case 19: goto L_801DDBDC; break;
        case 20: goto L_801DDCDC; break;
        case 21: goto L_801DF8E4; break;
        case 22: goto L_801DF8E4; break;
        case 23: goto L_801DF8E4; break;
        case 24: goto L_801DF8E4; break;
        case 25: goto L_801DF8E4; break;
        case 26: goto L_801DF8E4; break;
        case 27: goto L_801DF8E4; break;
        case 28: goto L_801DF8E4; break;
        case 29: goto L_801DF8E4; break;
        case 30: goto L_801DF8E4; break;
        case 31: goto L_801DF5F4; break;
        case 32: goto L_801DF8E4; break;
        case 33: goto L_801DF8E4; break;
        case 34: goto L_801DF8E4; break;
        case 35: goto L_801DF8E4; break;
        case 36: goto L_801DF8E4; break;
        case 37: goto L_801DF8E4; break;
        case 38: goto L_801DF8E4; break;
        case 39: goto L_801DF2D4; break;
        case 40: goto L_801DF3EC; break;
        case 41: goto L_801DF360; break;
        case 42: goto L_801DF478; break;
        case 43: goto L_801DF770; break;
        case 44: goto L_801DEE64; break;
        case 45: goto L_801DEEF4; break;
        case 46: goto L_801DEF88; break;
        case 47: goto L_801DF01C; break;
        case 48: goto L_801DF0B4; break;
        case 49: goto L_801DF144; break;
        default: switch_error(__func__, 0x801DDBD4, 0x801E7BD0);
    }
    // 0x801DDBD8: nop

L_801DDBDC:
    // 0x801DDBDC: lw          $t0, 0xBC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XBC);
    // 0x801DDBE0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x801DDBE4: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x801DDBE8: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x801DDBEC: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x801DDBF0: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x801DDBF4: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x801DDBF8: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x801DDBFC: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x801DDC00: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x801DDC04: lhu         $t2, -0x2A28($t2)
    ctx->r10 = MEM_HU(ctx->r10, -0X2A28);
    // 0x801DDC08: andi        $t3, $t2, 0x8000
    ctx->r11 = ctx->r10 & 0X8000;
    // 0x801DDC0C: beq         $t3, $zero, L_801DF8EC
    if (ctx->r11 == 0) {
        // 0x801DDC10: nop
    
            goto L_801DF8EC;
    }
    // 0x801DDC10: nop

    // 0x801DDC14: andi        $t4, $t2, 0x800
    ctx->r12 = ctx->r10 & 0X800;
    // 0x801DDC18: beq         $t4, $zero, L_801DF8EC
    if (ctx->r12 == 0) {
        // 0x801DDC1C: nop
    
            goto L_801DF8EC;
    }
    // 0x801DDC1C: nop

    // 0x801DDC20: lui         $t5, 0x8011
    ctx->r13 = S32(0X8011 << 16);
    // 0x801DDC24: lw          $t5, -0x4514($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4514);
    // 0x801DDC28: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x801DDC2C: lui         $t7, 0xE200
    ctx->r15 = S32(0XE200 << 16);
    // 0x801DDC30: sw          $t5, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r13;
    // 0x801DDC34: lw          $t8, 0xB8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB8);
    // 0x801DDC38: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x801DDC3C: sw          $t6, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r14;
    // 0x801DDC40: ori         $t7, $t7, 0x1C
    ctx->r15 = ctx->r15 | 0X1C;
    // 0x801DDC44: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x801DDC48: lw          $t0, 0xB8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB8);
    // 0x801DDC4C: lui         $t9, 0x44
    ctx->r25 = S32(0X44 << 16);
    // 0x801DDC50: ori         $t9, $t9, 0x2478
    ctx->r25 = ctx->r25 | 0X2478;
    // 0x801DDC54: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x801DDC58: lw          $t1, 0xBC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XBC);
    // 0x801DDC5C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x801DDC60: addiu       $t4, $t4, -0x2A28
    ctx->r12 = ADD32(ctx->r12, -0X2A28);
    // 0x801DDC64: sll         $t3, $t1, 2
    ctx->r11 = S32(ctx->r9 << 2);
    // 0x801DDC68: addu        $t3, $t3, $t1
    ctx->r11 = ADD32(ctx->r11, ctx->r9);
    // 0x801DDC6C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x801DDC70: subu        $t3, $t3, $t1
    ctx->r11 = SUB32(ctx->r11, ctx->r9);
    // 0x801DDC74: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x801DDC78: addu        $t3, $t3, $t1
    ctx->r11 = ADD32(ctx->r11, ctx->r9);
    // 0x801DDC7C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x801DDC80: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x801DDC84: lwc1        $f4, 0x64($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X64);
    // 0x801DDC88: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DDC8C: lwc1        $f8, 0x7C98($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7C98);
    // 0x801DDC90: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DDC94: lw          $a3, 0x60($t5)
    ctx->r7 = MEM_W(ctx->r13, 0X60);
    // 0x801DDC98: lwc1        $f10, 0x7C9C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7C9C);
    // 0x801DDC9C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x801DDCA0: lwc1        $f6, 0x68($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X68);
    // 0x801DDCA4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DDCA8: lwc1        $f16, 0x7CA0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7CA0);
    // 0x801DDCAC: addiu       $t2, $t3, 0xA4
    ctx->r10 = ADD32(ctx->r11, 0XA4);
    // 0x801DDCB0: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x801DDCB4: addiu       $a0, $a0, 0x74B0
    ctx->r4 = ADD32(ctx->r4, 0X74B0);
    // 0x801DDCB8: addu        $a2, $t2, $t4
    ctx->r6 = ADD32(ctx->r10, ctx->r12);
    // 0x801DDCBC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801DDCC0: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x801DDCC4: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x801DDCC8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x801DDCCC: jal         0x800C6868
    // 0x801DDCD0: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    func_800C6868(rdram, ctx);
        goto after_0;
    // 0x801DDCD0: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    after_0:
    // 0x801DDCD4: b           L_801DF8E4
    // 0x801DDCD8: nop

        goto L_801DF8E4;
    // 0x801DDCD8: nop

L_801DDCDC:
    // 0x801DDCDC: lw          $t6, 0xBC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XBC);
    // 0x801DDCE0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x801DDCE4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801DDCE8: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x801DDCEC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801DDCF0: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x801DDCF4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801DDCF8: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x801DDCFC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801DDD00: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x801DDD04: lhu         $t8, -0x2A28($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X2A28);
    // 0x801DDD08: andi        $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 & 0X8000;
    // 0x801DDD0C: beq         $t9, $zero, L_801DF8EC
    if (ctx->r25 == 0) {
        // 0x801DDD10: nop
    
            goto L_801DF8EC;
    }
    // 0x801DDD10: nop

    // 0x801DDD14: andi        $t0, $t8, 0x800
    ctx->r8 = ctx->r24 & 0X800;
    // 0x801DDD18: beq         $t0, $zero, L_801DF8EC
    if (ctx->r8 == 0) {
        // 0x801DDD1C: nop
    
            goto L_801DF8EC;
    }
    // 0x801DDD1C: nop

    // 0x801DDD20: lw          $t1, 0xBC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XBC);
    // 0x801DDD24: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x801DDD28: addiu       $t4, $t4, -0x2A28
    ctx->r12 = ADD32(ctx->r12, -0X2A28);
    // 0x801DDD2C: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x801DDD30: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x801DDD34: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x801DDD38: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x801DDD3C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x801DDD40: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x801DDD44: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x801DDD48: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x801DDD4C: lwc1        $f18, 0x64($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X64);
    // 0x801DDD50: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DDD54: lwc1        $f6, 0x7CA4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7CA4);
    // 0x801DDD58: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DDD5C: lw          $a3, 0x60($t5)
    ctx->r7 = MEM_W(ctx->r13, 0X60);
    // 0x801DDD60: lwc1        $f8, 0x7CA8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7CA8);
    // 0x801DDD64: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x801DDD68: lwc1        $f4, 0x68($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X68);
    // 0x801DDD6C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DDD70: lwc1        $f10, 0x7CAC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7CAC);
    // 0x801DDD74: addiu       $t3, $t2, 0xA4
    ctx->r11 = ADD32(ctx->r10, 0XA4);
    // 0x801DDD78: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x801DDD7C: addiu       $a0, $a0, -0x7C70
    ctx->r4 = ADD32(ctx->r4, -0X7C70);
    // 0x801DDD80: addu        $a2, $t3, $t4
    ctx->r6 = ADD32(ctx->r11, ctx->r12);
    // 0x801DDD84: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801DDD88: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x801DDD8C: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x801DDD90: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x801DDD94: jal         0x800C6868
    // 0x801DDD98: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    func_800C6868(rdram, ctx);
        goto after_1;
    // 0x801DDD98: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x801DDD9C: b           L_801DF8E4
    // 0x801DDDA0: nop

        goto L_801DF8E4;
    // 0x801DDDA0: nop

L_801DDDA4:
    // 0x801DDDA4: lw          $t6, 0xBC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XBC);
    // 0x801DDDA8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801DDDAC: addiu       $t9, $t9, -0x2A28
    ctx->r25 = ADD32(ctx->r25, -0X2A28);
    // 0x801DDDB0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801DDDB4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x801DDDB8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801DDDBC: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x801DDDC0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801DDDC4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x801DDDC8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801DDDCC: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x801DDDD0: lhu         $t0, 0x0($t8)
    ctx->r8 = MEM_HU(ctx->r24, 0X0);
    // 0x801DDDD4: andi        $t1, $t0, 0x8000
    ctx->r9 = ctx->r8 & 0X8000;
    // 0x801DDDD8: bne         $t1, $zero, L_801DDDE8
    if (ctx->r9 != 0) {
        // 0x801DDDDC: nop
    
            goto L_801DDDE8;
    }
    // 0x801DDDDC: nop

    // 0x801DDDE0: b           L_801DF8EC
    // 0x801DDDE4: sw          $zero, 0x2C($t8)
    MEM_W(0X2C, ctx->r24) = 0;
        goto L_801DF8EC;
    // 0x801DDDE4: sw          $zero, 0x2C($t8)
    MEM_W(0X2C, ctx->r24) = 0;
L_801DDDE8:
    // 0x801DDDE8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x801DDDEC: lw          $t3, -0x2E34($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2E34);
    // 0x801DDDF0: sltiu       $at, $t3, 0x3A1
    ctx->r1 = ctx->r11 < 0X3A1 ? 1 : 0;
    // 0x801DDDF4: bne         $at, $zero, L_801DDF24
    if (ctx->r1 != 0) {
        // 0x801DDDF8: sltiu       $at, $t3, 0x407
        ctx->r1 = ctx->r11 < 0X407 ? 1 : 0;
            goto L_801DDF24;
    }
    // 0x801DDDF8: sltiu       $at, $t3, 0x407
    ctx->r1 = ctx->r11 < 0X407 ? 1 : 0;
    // 0x801DDDFC: beq         $at, $zero, L_801DDF24
    if (ctx->r1 == 0) {
        // 0x801DDE00: nop
    
            goto L_801DDF24;
    }
    // 0x801DDE00: nop

    // 0x801DDE04: lui         $t2, 0x8011
    ctx->r10 = S32(0X8011 << 16);
    // 0x801DDE08: lw          $t2, -0x4514($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4514);
    // 0x801DDE0C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x801DDE10: lui         $t5, 0xFC35
    ctx->r13 = S32(0XFC35 << 16);
    // 0x801DDE14: sw          $t2, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r10;
    // 0x801DDE18: lw          $t6, 0xB4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB4);
    // 0x801DDE1C: addiu       $t4, $t2, 0x8
    ctx->r12 = ADD32(ctx->r10, 0X8);
    // 0x801DDE20: sw          $t4, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r12;
    // 0x801DDE24: ori         $t5, $t5, 0x166A
    ctx->r13 = ctx->r13 | 0X166A;
    // 0x801DDE28: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x801DDE2C: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
    // 0x801DDE30: lui         $t7, 0x112C
    ctx->r15 = S32(0X112C << 16);
    // 0x801DDE34: ori         $t7, $t7, 0xFE7F
    ctx->r15 = ctx->r15 | 0XFE7F;
    // 0x801DDE38: sw          $t7, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r15;
    // 0x801DDE3C: lw          $t0, 0xBC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XBC);
    // 0x801DDE40: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x801DDE44: addiu       $t8, $t8, -0x2A28
    ctx->r24 = ADD32(ctx->r24, -0X2A28);
    // 0x801DDE48: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x801DDE4C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x801DDE50: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x801DDE54: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x801DDE58: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x801DDE5C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x801DDE60: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x801DDE64: addu        $t3, $t1, $t8
    ctx->r11 = ADD32(ctx->r9, ctx->r24);
    // 0x801DDE68: lw          $t2, 0x2C($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X2C);
    // 0x801DDE6C: sltiu       $at, $t2, 0x1F
    ctx->r1 = ctx->r10 < 0X1F ? 1 : 0;
    // 0x801DDE70: beq         $at, $zero, L_801DDEF0
    if (ctx->r1 == 0) {
        // 0x801DDE74: nop
    
            goto L_801DDEF0;
    }
    // 0x801DDE74: nop

    // 0x801DDE78: addiu       $t4, $t2, 0x1
    ctx->r12 = ADD32(ctx->r10, 0X1);
    // 0x801DDE7C: sw          $t4, 0x2C($t3)
    MEM_W(0X2C, ctx->r11) = ctx->r12;
    // 0x801DDE80: lui         $t5, 0x8011
    ctx->r13 = S32(0X8011 << 16);
    // 0x801DDE84: lw          $t5, -0x4514($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4514);
    // 0x801DDE88: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x801DDE8C: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x801DDE90: sw          $t5, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r13;
    // 0x801DDE94: lw          $t9, 0xB0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB0);
    // 0x801DDE98: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x801DDE9C: sw          $t6, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r14;
    // 0x801DDEA0: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
    // 0x801DDEA4: lw          $t0, 0xBC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XBC);
    // 0x801DDEA8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x801DDEAC: lw          $t5, 0xB0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB0);
    // 0x801DDEB0: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x801DDEB4: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x801DDEB8: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x801DDEBC: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x801DDEC0: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x801DDEC4: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x801DDEC8: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x801DDECC: addu        $t8, $t8, $t1
    ctx->r24 = ADD32(ctx->r24, ctx->r9);
    // 0x801DDED0: lw          $t8, -0x29FC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X29FC);
    // 0x801DDED4: lui         $at, 0xFF40
    ctx->r1 = S32(0XFF40 << 16);
    // 0x801DDED8: sll         $t2, $t8, 2
    ctx->r10 = S32(ctx->r24 << 2);
    // 0x801DDEDC: addu        $t2, $t2, $t8
    ctx->r10 = ADD32(ctx->r10, ctx->r24);
    // 0x801DDEE0: andi        $t4, $t2, 0xFF
    ctx->r12 = ctx->r10 & 0XFF;
    // 0x801DDEE4: or          $t3, $t4, $at
    ctx->r11 = ctx->r12 | ctx->r1;
    // 0x801DDEE8: b           L_801DDF24
    // 0x801DDEEC: sw          $t3, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r11;
        goto L_801DDF24;
    // 0x801DDEEC: sw          $t3, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r11;
L_801DDEF0:
    // 0x801DDEF0: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x801DDEF4: lw          $t6, -0x4514($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4514);
    // 0x801DDEF8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x801DDEFC: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x801DDF00: sw          $t6, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r14;
    // 0x801DDF04: lw          $t0, 0xAC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XAC);
    // 0x801DDF08: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x801DDF0C: sw          $t7, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r15;
    // 0x801DDF10: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x801DDF14: lw          $t8, 0xAC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XAC);
    // 0x801DDF18: lui         $t1, 0xFF40
    ctx->r9 = S32(0XFF40 << 16);
    // 0x801DDF1C: ori         $t1, $t1, 0xA0
    ctx->r9 = ctx->r9 | 0XA0;
    // 0x801DDF20: sw          $t1, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r9;
L_801DDF24:
    // 0x801DDF24: lui         $t2, 0x8011
    ctx->r10 = S32(0X8011 << 16);
    // 0x801DDF28: lw          $t2, -0x4514($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4514);
    // 0x801DDF2C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x801DDF30: lui         $t3, 0xE200
    ctx->r11 = S32(0XE200 << 16);
    // 0x801DDF34: sw          $t2, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r10;
    // 0x801DDF38: lw          $t5, 0xA8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA8);
    // 0x801DDF3C: addiu       $t4, $t2, 0x8
    ctx->r12 = ADD32(ctx->r10, 0X8);
    // 0x801DDF40: sw          $t4, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r12;
    // 0x801DDF44: ori         $t3, $t3, 0x1C
    ctx->r11 = ctx->r11 | 0X1C;
    // 0x801DDF48: sw          $t3, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r11;
    // 0x801DDF4C: lw          $t7, 0xA8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA8);
    // 0x801DDF50: lui         $t6, 0x44
    ctx->r14 = S32(0X44 << 16);
    // 0x801DDF54: ori         $t6, $t6, 0x2478
    ctx->r14 = ctx->r14 | 0X2478;
    // 0x801DDF58: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x801DDF5C: lw          $t9, 0xBC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XBC);
    // 0x801DDF60: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x801DDF64: addiu       $t8, $t8, -0x2A28
    ctx->r24 = ADD32(ctx->r24, -0X2A28);
    // 0x801DDF68: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x801DDF6C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x801DDF70: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x801DDF74: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x801DDF78: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x801DDF7C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x801DDF80: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x801DDF84: addu        $t2, $t0, $t8
    ctx->r10 = ADD32(ctx->r8, ctx->r24);
    // 0x801DDF88: lwc1        $f16, 0x64($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X64);
    // 0x801DDF8C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DDF90: lwc1        $f4, 0x7CB0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7CB0);
    // 0x801DDF94: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DDF98: lw          $a3, 0x60($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X60);
    // 0x801DDF9C: lwc1        $f6, 0x7CB4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7CB4);
    // 0x801DDFA0: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x801DDFA4: lwc1        $f18, 0x68($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X68);
    // 0x801DDFA8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DDFAC: lwc1        $f8, 0x7CB8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7CB8);
    // 0x801DDFB0: addiu       $t1, $t0, 0xA4
    ctx->r9 = ADD32(ctx->r8, 0XA4);
    // 0x801DDFB4: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x801DDFB8: addiu       $a0, $a0, 0x6C20
    ctx->r4 = ADD32(ctx->r4, 0X6C20);
    // 0x801DDFBC: addu        $a2, $t1, $t8
    ctx->r6 = ADD32(ctx->r9, ctx->r24);
    // 0x801DDFC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801DDFC4: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x801DDFC8: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x801DDFCC: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x801DDFD0: jal         0x800C6868
    // 0x801DDFD4: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    func_800C6868(rdram, ctx);
        goto after_2;
    // 0x801DDFD4: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x801DDFD8: b           L_801DF8E4
    // 0x801DDFDC: nop

        goto L_801DF8E4;
    // 0x801DDFDC: nop

L_801DDFE0:
    // 0x801DDFE0: lw          $t4, 0xBC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XBC);
    // 0x801DDFE4: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x801DDFE8: sll         $t3, $t4, 2
    ctx->r11 = S32(ctx->r12 << 2);
    // 0x801DDFEC: addu        $t3, $t3, $t4
    ctx->r11 = ADD32(ctx->r11, ctx->r12);
    // 0x801DDFF0: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x801DDFF4: subu        $t3, $t3, $t4
    ctx->r11 = SUB32(ctx->r11, ctx->r12);
    // 0x801DDFF8: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x801DDFFC: addu        $t3, $t3, $t4
    ctx->r11 = ADD32(ctx->r11, ctx->r12);
    // 0x801DE000: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x801DE004: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x801DE008: lhu         $t5, -0x2A28($t5)
    ctx->r13 = MEM_HU(ctx->r13, -0X2A28);
    // 0x801DE00C: andi        $t6, $t5, 0x8000
    ctx->r14 = ctx->r13 & 0X8000;
    // 0x801DE010: beq         $t6, $zero, L_801DF8EC
    if (ctx->r14 == 0) {
        // 0x801DE014: nop
    
            goto L_801DF8EC;
    }
    // 0x801DE014: nop

    // 0x801DE018: lw          $t7, 0xBC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XBC);
    // 0x801DE01C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x801DE020: addiu       $t0, $t0, -0x2A28
    ctx->r8 = ADD32(ctx->r8, -0X2A28);
    // 0x801DE024: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x801DE028: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x801DE02C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x801DE030: subu        $t9, $t9, $t7
    ctx->r25 = SUB32(ctx->r25, ctx->r15);
    // 0x801DE034: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x801DE038: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x801DE03C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x801DE040: addu        $t8, $t9, $t0
    ctx->r24 = ADD32(ctx->r25, ctx->r8);
    // 0x801DE044: lwc1        $f10, 0x64($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X64);
    // 0x801DE048: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DE04C: lwc1        $f18, 0x7CBC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7CBC);
    // 0x801DE050: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DE054: lw          $a3, 0x60($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X60);
    // 0x801DE058: lwc1        $f4, 0x7CC0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7CC0);
    // 0x801DE05C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x801DE060: lwc1        $f16, 0x68($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X68);
    // 0x801DE064: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DE068: lwc1        $f6, 0x7CC4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7CC4);
    // 0x801DE06C: addiu       $t1, $t9, 0xA4
    ctx->r9 = ADD32(ctx->r25, 0XA4);
    // 0x801DE070: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x801DE074: addiu       $a0, $a0, 0x5BE8
    ctx->r4 = ADD32(ctx->r4, 0X5BE8);
    // 0x801DE078: addu        $a2, $t1, $t0
    ctx->r6 = ADD32(ctx->r9, ctx->r8);
    // 0x801DE07C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801DE080: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    // 0x801DE084: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x801DE088: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x801DE08C: jal         0x800C6868
    // 0x801DE090: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    func_800C6868(rdram, ctx);
        goto after_3;
    // 0x801DE090: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    after_3:
    // 0x801DE094: b           L_801DF8E4
    // 0x801DE098: nop

        goto L_801DF8E4;
    // 0x801DE098: nop

L_801DE09C:
    // 0x801DE09C: lw          $t2, 0xBC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XBC);
    // 0x801DE0A0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x801DE0A4: sll         $t4, $t2, 2
    ctx->r12 = S32(ctx->r10 << 2);
    // 0x801DE0A8: addu        $t4, $t4, $t2
    ctx->r12 = ADD32(ctx->r12, ctx->r10);
    // 0x801DE0AC: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x801DE0B0: subu        $t4, $t4, $t2
    ctx->r12 = SUB32(ctx->r12, ctx->r10);
    // 0x801DE0B4: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x801DE0B8: addu        $t4, $t4, $t2
    ctx->r12 = ADD32(ctx->r12, ctx->r10);
    // 0x801DE0BC: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x801DE0C0: addu        $t3, $t3, $t4
    ctx->r11 = ADD32(ctx->r11, ctx->r12);
    // 0x801DE0C4: lhu         $t3, -0x2A28($t3)
    ctx->r11 = MEM_HU(ctx->r11, -0X2A28);
    // 0x801DE0C8: andi        $t5, $t3, 0x8000
    ctx->r13 = ctx->r11 & 0X8000;
    // 0x801DE0CC: beq         $t5, $zero, L_801DF8EC
    if (ctx->r13 == 0) {
        // 0x801DE0D0: nop
    
            goto L_801DF8EC;
    }
    // 0x801DE0D0: nop

    // 0x801DE0D4: lw          $t6, 0xBC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XBC);
    // 0x801DE0D8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801DE0DC: addiu       $t9, $t9, -0x2A28
    ctx->r25 = ADD32(ctx->r25, -0X2A28);
    // 0x801DE0E0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801DE0E4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x801DE0E8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801DE0EC: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x801DE0F0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801DE0F4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x801DE0F8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801DE0FC: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x801DE100: lwc1        $f8, 0x64($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X64);
    // 0x801DE104: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DE108: lwc1        $f16, 0x7CC8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7CC8);
    // 0x801DE10C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DE110: lw          $a3, 0x60($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X60);
    // 0x801DE114: lwc1        $f18, 0x7CCC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7CCC);
    // 0x801DE118: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x801DE11C: lwc1        $f10, 0x68($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X68);
    // 0x801DE120: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DE124: lwc1        $f4, 0x7CD0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7CD0);
    // 0x801DE128: addiu       $t1, $t7, 0xA4
    ctx->r9 = ADD32(ctx->r15, 0XA4);
    // 0x801DE12C: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x801DE130: addiu       $a0, $a0, 0x6590
    ctx->r4 = ADD32(ctx->r4, 0X6590);
    // 0x801DE134: addu        $a2, $t1, $t9
    ctx->r6 = ADD32(ctx->r9, ctx->r25);
    // 0x801DE138: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801DE13C: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x801DE140: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    // 0x801DE144: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x801DE148: jal         0x800C6868
    // 0x801DE14C: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    func_800C6868(rdram, ctx);
        goto after_4;
    // 0x801DE14C: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    after_4:
    // 0x801DE150: b           L_801DF8E4
    // 0x801DE154: nop

        goto L_801DF8E4;
    // 0x801DE154: nop

L_801DE158:
    // 0x801DE158: lw          $t8, 0xBC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XBC);
    // 0x801DE15C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x801DE160: sll         $t2, $t8, 2
    ctx->r10 = S32(ctx->r24 << 2);
    // 0x801DE164: addu        $t2, $t2, $t8
    ctx->r10 = ADD32(ctx->r10, ctx->r24);
    // 0x801DE168: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x801DE16C: subu        $t2, $t2, $t8
    ctx->r10 = SUB32(ctx->r10, ctx->r24);
    // 0x801DE170: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x801DE174: addu        $t2, $t2, $t8
    ctx->r10 = ADD32(ctx->r10, ctx->r24);
    // 0x801DE178: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x801DE17C: addu        $t4, $t4, $t2
    ctx->r12 = ADD32(ctx->r12, ctx->r10);
    // 0x801DE180: lhu         $t4, -0x2A28($t4)
    ctx->r12 = MEM_HU(ctx->r12, -0X2A28);
    // 0x801DE184: andi        $t3, $t4, 0x8000
    ctx->r11 = ctx->r12 & 0X8000;
    // 0x801DE188: beq         $t3, $zero, L_801DF8EC
    if (ctx->r11 == 0) {
        // 0x801DE18C: nop
    
            goto L_801DF8EC;
    }
    // 0x801DE18C: nop

    // 0x801DE190: lw          $t5, 0xBC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XBC);
    // 0x801DE194: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801DE198: addiu       $t7, $t7, -0x2A28
    ctx->r15 = ADD32(ctx->r15, -0X2A28);
    // 0x801DE19C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x801DE1A0: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x801DE1A4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801DE1A8: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x801DE1AC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801DE1B0: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x801DE1B4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801DE1B8: addu        $t9, $t6, $t7
    ctx->r25 = ADD32(ctx->r14, ctx->r15);
    // 0x801DE1BC: lwc1        $f6, 0x64($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X64);
    // 0x801DE1C0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DE1C4: lwc1        $f10, 0x7CD4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7CD4);
    // 0x801DE1C8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DE1CC: lw          $a3, 0x60($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X60);
    // 0x801DE1D0: lwc1        $f16, 0x7CD8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7CD8);
    // 0x801DE1D4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x801DE1D8: lwc1        $f8, 0x68($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X68);
    // 0x801DE1DC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DE1E0: lwc1        $f18, 0x7CDC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7CDC);
    // 0x801DE1E4: addiu       $t1, $t6, 0xA4
    ctx->r9 = ADD32(ctx->r14, 0XA4);
    // 0x801DE1E8: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x801DE1EC: addiu       $a0, $a0, 0x66F8
    ctx->r4 = ADD32(ctx->r4, 0X66F8);
    // 0x801DE1F0: addu        $a2, $t1, $t7
    ctx->r6 = ADD32(ctx->r9, ctx->r15);
    // 0x801DE1F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801DE1F8: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x801DE1FC: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    // 0x801DE200: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x801DE204: jal         0x800C6868
    // 0x801DE208: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    func_800C6868(rdram, ctx);
        goto after_5;
    // 0x801DE208: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    after_5:
    // 0x801DE20C: b           L_801DF8E4
    // 0x801DE210: nop

        goto L_801DF8E4;
    // 0x801DE210: nop

L_801DE214:
    // 0x801DE214: lw          $t0, 0xBC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XBC);
    // 0x801DE218: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x801DE21C: sll         $t8, $t0, 2
    ctx->r24 = S32(ctx->r8 << 2);
    // 0x801DE220: addu        $t8, $t8, $t0
    ctx->r24 = ADD32(ctx->r24, ctx->r8);
    // 0x801DE224: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x801DE228: subu        $t8, $t8, $t0
    ctx->r24 = SUB32(ctx->r24, ctx->r8);
    // 0x801DE22C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x801DE230: addu        $t8, $t8, $t0
    ctx->r24 = ADD32(ctx->r24, ctx->r8);
    // 0x801DE234: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x801DE238: addu        $t2, $t2, $t8
    ctx->r10 = ADD32(ctx->r10, ctx->r24);
    // 0x801DE23C: lhu         $t2, -0x2A28($t2)
    ctx->r10 = MEM_HU(ctx->r10, -0X2A28);
    // 0x801DE240: andi        $t4, $t2, 0x8000
    ctx->r12 = ctx->r10 & 0X8000;
    // 0x801DE244: beq         $t4, $zero, L_801DF8EC
    if (ctx->r12 == 0) {
        // 0x801DE248: nop
    
            goto L_801DF8EC;
    }
    // 0x801DE248: nop

    // 0x801DE24C: lw          $t3, 0xBC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XBC);
    // 0x801DE250: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801DE254: addiu       $t6, $t6, -0x2A28
    ctx->r14 = ADD32(ctx->r14, -0X2A28);
    // 0x801DE258: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x801DE25C: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x801DE260: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x801DE264: subu        $t5, $t5, $t3
    ctx->r13 = SUB32(ctx->r13, ctx->r11);
    // 0x801DE268: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x801DE26C: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x801DE270: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x801DE274: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x801DE278: lwc1        $f4, 0x64($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X64);
    // 0x801DE27C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DE280: lwc1        $f8, 0x7CE0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7CE0);
    // 0x801DE284: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DE288: lw          $a3, 0x60($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X60);
    // 0x801DE28C: lwc1        $f10, 0x7CE4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7CE4);
    // 0x801DE290: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x801DE294: lwc1        $f6, 0x68($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X68);
    // 0x801DE298: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DE29C: lwc1        $f16, 0x7CE8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7CE8);
    // 0x801DE2A0: addiu       $t1, $t5, 0xA4
    ctx->r9 = ADD32(ctx->r13, 0XA4);
    // 0x801DE2A4: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x801DE2A8: addiu       $a0, $a0, 0x6860
    ctx->r4 = ADD32(ctx->r4, 0X6860);
    // 0x801DE2AC: addu        $a2, $t1, $t6
    ctx->r6 = ADD32(ctx->r9, ctx->r14);
    // 0x801DE2B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801DE2B4: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x801DE2B8: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x801DE2BC: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x801DE2C0: jal         0x800C6868
    // 0x801DE2C4: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    func_800C6868(rdram, ctx);
        goto after_6;
    // 0x801DE2C4: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    after_6:
    // 0x801DE2C8: b           L_801DF8E4
    // 0x801DE2CC: nop

        goto L_801DF8E4;
    // 0x801DE2CC: nop

L_801DE2D0:
    // 0x801DE2D0: lw          $t9, 0xBC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XBC);
    // 0x801DE2D4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x801DE2D8: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x801DE2DC: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x801DE2E0: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x801DE2E4: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x801DE2E8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x801DE2EC: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x801DE2F0: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x801DE2F4: addu        $t8, $t8, $t0
    ctx->r24 = ADD32(ctx->r24, ctx->r8);
    // 0x801DE2F8: lhu         $t8, -0x2A28($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X2A28);
    // 0x801DE2FC: andi        $t2, $t8, 0x8000
    ctx->r10 = ctx->r24 & 0X8000;
    // 0x801DE300: beq         $t2, $zero, L_801DF8EC
    if (ctx->r10 == 0) {
        // 0x801DE304: nop
    
            goto L_801DF8EC;
    }
    // 0x801DE304: nop

    // 0x801DE308: lw          $t4, 0xBC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XBC);
    // 0x801DE30C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x801DE310: addiu       $t5, $t5, -0x2A28
    ctx->r13 = ADD32(ctx->r13, -0X2A28);
    // 0x801DE314: sll         $t3, $t4, 2
    ctx->r11 = S32(ctx->r12 << 2);
    // 0x801DE318: addu        $t3, $t3, $t4
    ctx->r11 = ADD32(ctx->r11, ctx->r12);
    // 0x801DE31C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x801DE320: subu        $t3, $t3, $t4
    ctx->r11 = SUB32(ctx->r11, ctx->r12);
    // 0x801DE324: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x801DE328: addu        $t3, $t3, $t4
    ctx->r11 = ADD32(ctx->r11, ctx->r12);
    // 0x801DE32C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x801DE330: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x801DE334: lwc1        $f18, 0x64($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X64);
    // 0x801DE338: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DE33C: lwc1        $f6, 0x7CEC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7CEC);
    // 0x801DE340: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DE344: lw          $a3, 0x60($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X60);
    // 0x801DE348: lwc1        $f8, 0x7CF0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7CF0);
    // 0x801DE34C: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x801DE350: lwc1        $f4, 0x68($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X68);
    // 0x801DE354: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DE358: lwc1        $f10, 0x7CF4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7CF4);
    // 0x801DE35C: addiu       $t1, $t3, 0xA4
    ctx->r9 = ADD32(ctx->r11, 0XA4);
    // 0x801DE360: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x801DE364: addiu       $a0, $a0, 0x69D8
    ctx->r4 = ADD32(ctx->r4, 0X69D8);
    // 0x801DE368: addu        $a2, $t1, $t5
    ctx->r6 = ADD32(ctx->r9, ctx->r13);
    // 0x801DE36C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801DE370: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x801DE374: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x801DE378: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x801DE37C: jal         0x800C6868
    // 0x801DE380: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    func_800C6868(rdram, ctx);
        goto after_7;
    // 0x801DE380: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    after_7:
    // 0x801DE384: b           L_801DF8E4
    // 0x801DE388: nop

        goto L_801DF8E4;
    // 0x801DE388: nop

L_801DE38C:
    // 0x801DE38C: lw          $t7, 0xBC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XBC);
    // 0x801DE390: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x801DE394: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x801DE398: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x801DE39C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x801DE3A0: subu        $t9, $t9, $t7
    ctx->r25 = SUB32(ctx->r25, ctx->r15);
    // 0x801DE3A4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x801DE3A8: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x801DE3AC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x801DE3B0: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x801DE3B4: lhu         $t0, -0x2A28($t0)
    ctx->r8 = MEM_HU(ctx->r8, -0X2A28);
    // 0x801DE3B8: andi        $t8, $t0, 0x8000
    ctx->r24 = ctx->r8 & 0X8000;
    // 0x801DE3BC: beq         $t8, $zero, L_801DF8EC
    if (ctx->r24 == 0) {
        // 0x801DE3C0: nop
    
            goto L_801DF8EC;
    }
    // 0x801DE3C0: nop

    // 0x801DE3C4: lw          $t2, 0xBC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XBC);
    // 0x801DE3C8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x801DE3CC: addiu       $t3, $t3, -0x2A28
    ctx->r11 = ADD32(ctx->r11, -0X2A28);
    // 0x801DE3D0: sll         $t4, $t2, 2
    ctx->r12 = S32(ctx->r10 << 2);
    // 0x801DE3D4: addu        $t4, $t4, $t2
    ctx->r12 = ADD32(ctx->r12, ctx->r10);
    // 0x801DE3D8: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x801DE3DC: subu        $t4, $t4, $t2
    ctx->r12 = SUB32(ctx->r12, ctx->r10);
    // 0x801DE3E0: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x801DE3E4: addu        $t4, $t4, $t2
    ctx->r12 = ADD32(ctx->r12, ctx->r10);
    // 0x801DE3E8: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x801DE3EC: addu        $t5, $t4, $t3
    ctx->r13 = ADD32(ctx->r12, ctx->r11);
    // 0x801DE3F0: lwc1        $f16, 0x64($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0X64);
    // 0x801DE3F4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DE3F8: lwc1        $f4, 0x7CF8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7CF8);
    // 0x801DE3FC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DE400: lw          $a3, 0x60($t5)
    ctx->r7 = MEM_W(ctx->r13, 0X60);
    // 0x801DE404: lwc1        $f6, 0x7CFC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7CFC);
    // 0x801DE408: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x801DE40C: lwc1        $f18, 0x68($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X68);
    // 0x801DE410: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DE414: lwc1        $f8, 0x7D00($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7D00);
    // 0x801DE418: addiu       $t1, $t4, 0xA4
    ctx->r9 = ADD32(ctx->r12, 0XA4);
    // 0x801DE41C: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x801DE420: addiu       $a0, $a0, 0x6AC0
    ctx->r4 = ADD32(ctx->r4, 0X6AC0);
    // 0x801DE424: addu        $a2, $t1, $t3
    ctx->r6 = ADD32(ctx->r9, ctx->r11);
    // 0x801DE428: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801DE42C: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x801DE430: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x801DE434: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x801DE438: jal         0x800C6868
    // 0x801DE43C: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    func_800C6868(rdram, ctx);
        goto after_8;
    // 0x801DE43C: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    after_8:
    // 0x801DE440: b           L_801DF8E4
    // 0x801DE444: nop

        goto L_801DF8E4;
    // 0x801DE444: nop

L_801DE448:
    // 0x801DE448: lw          $t6, 0xBC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XBC);
    // 0x801DE44C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801DE450: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801DE454: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x801DE458: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801DE45C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x801DE460: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801DE464: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x801DE468: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801DE46C: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x801DE470: lhu         $t9, -0x2A28($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X2A28);
    // 0x801DE474: andi        $t0, $t9, 0x8000
    ctx->r8 = ctx->r25 & 0X8000;
    // 0x801DE478: beq         $t0, $zero, L_801DF8EC
    if (ctx->r8 == 0) {
        // 0x801DE47C: nop
    
            goto L_801DF8EC;
    }
    // 0x801DE47C: nop

    // 0x801DE480: lw          $t8, 0xBC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XBC);
    // 0x801DE484: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x801DE488: addiu       $t4, $t4, -0x2A28
    ctx->r12 = ADD32(ctx->r12, -0X2A28);
    // 0x801DE48C: sll         $t2, $t8, 2
    ctx->r10 = S32(ctx->r24 << 2);
    // 0x801DE490: addu        $t2, $t2, $t8
    ctx->r10 = ADD32(ctx->r10, ctx->r24);
    // 0x801DE494: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x801DE498: subu        $t2, $t2, $t8
    ctx->r10 = SUB32(ctx->r10, ctx->r24);
    // 0x801DE49C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x801DE4A0: addu        $t2, $t2, $t8
    ctx->r10 = ADD32(ctx->r10, ctx->r24);
    // 0x801DE4A4: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x801DE4A8: addu        $t3, $t2, $t4
    ctx->r11 = ADD32(ctx->r10, ctx->r12);
    // 0x801DE4AC: lwc1        $f10, 0x64($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X64);
    // 0x801DE4B0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DE4B4: lwc1        $f18, 0x7D04($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7D04);
    // 0x801DE4B8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DE4BC: lw          $a3, 0x60($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X60);
    // 0x801DE4C0: lwc1        $f4, 0x7D08($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7D08);
    // 0x801DE4C4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x801DE4C8: lwc1        $f16, 0x68($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X68);
    // 0x801DE4CC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DE4D0: lwc1        $f6, 0x7D0C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7D0C);
    // 0x801DE4D4: addiu       $t1, $t2, 0xA4
    ctx->r9 = ADD32(ctx->r10, 0XA4);
    // 0x801DE4D8: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x801DE4DC: addiu       $a0, $a0, 0x6B68
    ctx->r4 = ADD32(ctx->r4, 0X6B68);
    // 0x801DE4E0: addu        $a2, $t1, $t4
    ctx->r6 = ADD32(ctx->r9, ctx->r12);
    // 0x801DE4E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801DE4E8: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    // 0x801DE4EC: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x801DE4F0: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x801DE4F4: jal         0x800C6868
    // 0x801DE4F8: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    func_800C6868(rdram, ctx);
        goto after_9;
    // 0x801DE4F8: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    after_9:
    // 0x801DE4FC: b           L_801DF8E4
    // 0x801DE500: nop

        goto L_801DF8E4;
    // 0x801DE500: nop

L_801DE504:
    // 0x801DE504: lw          $t5, 0xBC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XBC);
    // 0x801DE508: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801DE50C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x801DE510: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x801DE514: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801DE518: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x801DE51C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801DE520: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x801DE524: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801DE528: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x801DE52C: lhu         $t7, -0x2A28($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X2A28);
    // 0x801DE530: andi        $t9, $t7, 0x8000
    ctx->r25 = ctx->r15 & 0X8000;
    // 0x801DE534: beq         $t9, $zero, L_801DF8EC
    if (ctx->r25 == 0) {
        // 0x801DE538: nop
    
            goto L_801DF8EC;
    }
    // 0x801DE538: nop

    // 0x801DE53C: lui         $t0, 0x8011
    ctx->r8 = S32(0X8011 << 16);
    // 0x801DE540: lw          $t0, -0x4514($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X4514);
    // 0x801DE544: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x801DE548: lui         $t1, 0xDE00
    ctx->r9 = S32(0XDE00 << 16);
    // 0x801DE54C: sw          $t0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r8;
    // 0x801DE550: lw          $t2, 0xA4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XA4);
    // 0x801DE554: addiu       $t8, $t0, 0x8
    ctx->r24 = ADD32(ctx->r8, 0X8);
    // 0x801DE558: sw          $t8, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r24;
    // 0x801DE55C: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x801DE560: lw          $t3, 0xA4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XA4);
    // 0x801DE564: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x801DE568: addiu       $t4, $t4, -0x51D0
    ctx->r12 = ADD32(ctx->r12, -0X51D0);
    // 0x801DE56C: sw          $t4, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r12;
    // 0x801DE570: lw          $t5, 0xBC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XBC);
    // 0x801DE574: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801DE578: addiu       $t9, $t9, -0x2A28
    ctx->r25 = ADD32(ctx->r25, -0X2A28);
    // 0x801DE57C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x801DE580: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x801DE584: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801DE588: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x801DE58C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801DE590: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x801DE594: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801DE598: addu        $t0, $t6, $t9
    ctx->r8 = ADD32(ctx->r14, ctx->r25);
    // 0x801DE59C: lwc1        $f8, 0x64($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X64);
    // 0x801DE5A0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DE5A4: lwc1        $f16, 0x7D10($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7D10);
    // 0x801DE5A8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DE5AC: lw          $a3, 0x60($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X60);
    // 0x801DE5B0: lwc1        $f18, 0x7D14($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7D14);
    // 0x801DE5B4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x801DE5B8: lwc1        $f10, 0x68($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X68);
    // 0x801DE5BC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DE5C0: lwc1        $f4, 0x7D18($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7D18);
    // 0x801DE5C4: addiu       $t7, $t6, 0xA4
    ctx->r15 = ADD32(ctx->r14, 0XA4);
    // 0x801DE5C8: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x801DE5CC: addiu       $a0, $a0, 0x46C8
    ctx->r4 = ADD32(ctx->r4, 0X46C8);
    // 0x801DE5D0: addu        $a2, $t7, $t9
    ctx->r6 = ADD32(ctx->r15, ctx->r25);
    // 0x801DE5D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801DE5D8: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x801DE5DC: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    // 0x801DE5E0: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x801DE5E4: jal         0x800C6868
    // 0x801DE5E8: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    func_800C6868(rdram, ctx);
        goto after_10;
    // 0x801DE5E8: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    after_10:
    // 0x801DE5EC: b           L_801DF8E4
    // 0x801DE5F0: nop

        goto L_801DF8E4;
    // 0x801DE5F0: nop

L_801DE5F4:
    // 0x801DE5F4: lw          $t8, 0xBC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XBC);
    // 0x801DE5F8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x801DE5FC: sll         $t1, $t8, 2
    ctx->r9 = S32(ctx->r24 << 2);
    // 0x801DE600: addu        $t1, $t1, $t8
    ctx->r9 = ADD32(ctx->r9, ctx->r24);
    // 0x801DE604: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x801DE608: subu        $t1, $t1, $t8
    ctx->r9 = SUB32(ctx->r9, ctx->r24);
    // 0x801DE60C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x801DE610: addu        $t1, $t1, $t8
    ctx->r9 = ADD32(ctx->r9, ctx->r24);
    // 0x801DE614: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x801DE618: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x801DE61C: lhu         $t2, -0x2A28($t2)
    ctx->r10 = MEM_HU(ctx->r10, -0X2A28);
    // 0x801DE620: andi        $t4, $t2, 0x8000
    ctx->r12 = ctx->r10 & 0X8000;
    // 0x801DE624: beq         $t4, $zero, L_801DF8EC
    if (ctx->r12 == 0) {
        // 0x801DE628: nop
    
            goto L_801DF8EC;
    }
    // 0x801DE628: nop

    // 0x801DE62C: lui         $t3, 0x8011
    ctx->r11 = S32(0X8011 << 16);
    // 0x801DE630: lw          $t3, -0x4514($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4514);
    // 0x801DE634: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x801DE638: lui         $t7, 0xDE00
    ctx->r15 = S32(0XDE00 << 16);
    // 0x801DE63C: sw          $t3, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r11;
    // 0x801DE640: lw          $t6, 0xA0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA0);
    // 0x801DE644: addiu       $t5, $t3, 0x8
    ctx->r13 = ADD32(ctx->r11, 0X8);
    // 0x801DE648: sw          $t5, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r13;
    // 0x801DE64C: sw          $t7, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r15;
    // 0x801DE650: lw          $t0, 0xA0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA0);
    // 0x801DE654: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x801DE658: addiu       $t9, $t9, -0x51D0
    ctx->r25 = ADD32(ctx->r25, -0X51D0);
    // 0x801DE65C: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x801DE660: lw          $t8, 0xBC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XBC);
    // 0x801DE664: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x801DE668: addiu       $t4, $t4, -0x2A28
    ctx->r12 = ADD32(ctx->r12, -0X2A28);
    // 0x801DE66C: sll         $t1, $t8, 2
    ctx->r9 = S32(ctx->r24 << 2);
    // 0x801DE670: addu        $t1, $t1, $t8
    ctx->r9 = ADD32(ctx->r9, ctx->r24);
    // 0x801DE674: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x801DE678: subu        $t1, $t1, $t8
    ctx->r9 = SUB32(ctx->r9, ctx->r24);
    // 0x801DE67C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x801DE680: addu        $t1, $t1, $t8
    ctx->r9 = ADD32(ctx->r9, ctx->r24);
    // 0x801DE684: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x801DE688: addu        $t3, $t1, $t4
    ctx->r11 = ADD32(ctx->r9, ctx->r12);
    // 0x801DE68C: lwc1        $f6, 0x64($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X64);
    // 0x801DE690: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DE694: lwc1        $f10, 0x7D1C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7D1C);
    // 0x801DE698: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DE69C: lw          $a3, 0x60($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X60);
    // 0x801DE6A0: lwc1        $f16, 0x7D20($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x801DE6A4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x801DE6A8: lwc1        $f8, 0x68($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X68);
    // 0x801DE6AC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DE6B0: lwc1        $f18, 0x7D24($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7D24);
    // 0x801DE6B4: addiu       $t2, $t1, 0xA4
    ctx->r10 = ADD32(ctx->r9, 0XA4);
    // 0x801DE6B8: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x801DE6BC: addiu       $a0, $a0, 0x4F48
    ctx->r4 = ADD32(ctx->r4, 0X4F48);
    // 0x801DE6C0: addu        $a2, $t2, $t4
    ctx->r6 = ADD32(ctx->r10, ctx->r12);
    // 0x801DE6C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801DE6C8: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x801DE6CC: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    // 0x801DE6D0: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x801DE6D4: jal         0x800C6868
    // 0x801DE6D8: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    func_800C6868(rdram, ctx);
        goto after_11;
    // 0x801DE6D8: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    after_11:
    // 0x801DE6DC: b           L_801DF8E4
    // 0x801DE6E0: nop

        goto L_801DF8E4;
    // 0x801DE6E0: nop

L_801DE6E4:
    // 0x801DE6E4: lw          $t5, 0xBC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XBC);
    // 0x801DE6E8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801DE6EC: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x801DE6F0: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x801DE6F4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801DE6F8: subu        $t7, $t7, $t5
    ctx->r15 = SUB32(ctx->r15, ctx->r13);
    // 0x801DE6FC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801DE700: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x801DE704: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801DE708: addu        $t6, $t6, $t7
    ctx->r14 = ADD32(ctx->r14, ctx->r15);
    // 0x801DE70C: lhu         $t6, -0x2A28($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X2A28);
    // 0x801DE710: andi        $t9, $t6, 0x8000
    ctx->r25 = ctx->r14 & 0X8000;
    // 0x801DE714: beq         $t9, $zero, L_801DF8EC
    if (ctx->r25 == 0) {
        // 0x801DE718: nop
    
            goto L_801DF8EC;
    }
    // 0x801DE718: nop

    // 0x801DE71C: lui         $t0, 0x8011
    ctx->r8 = S32(0X8011 << 16);
    // 0x801DE720: lw          $t0, -0x4514($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X4514);
    // 0x801DE724: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x801DE728: lui         $t2, 0xDE00
    ctx->r10 = S32(0XDE00 << 16);
    // 0x801DE72C: sw          $t0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r8;
    // 0x801DE730: lw          $t1, 0x9C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X9C);
    // 0x801DE734: addiu       $t8, $t0, 0x8
    ctx->r24 = ADD32(ctx->r8, 0X8);
    // 0x801DE738: sw          $t8, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r24;
    // 0x801DE73C: sw          $t2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r10;
    // 0x801DE740: lw          $t3, 0x9C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X9C);
    // 0x801DE744: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x801DE748: addiu       $t4, $t4, -0x51D0
    ctx->r12 = ADD32(ctx->r12, -0X51D0);
    // 0x801DE74C: sw          $t4, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r12;
    // 0x801DE750: lw          $t5, 0xBC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XBC);
    // 0x801DE754: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801DE758: addiu       $t9, $t9, -0x2A28
    ctx->r25 = ADD32(ctx->r25, -0X2A28);
    // 0x801DE75C: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x801DE760: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x801DE764: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801DE768: subu        $t7, $t7, $t5
    ctx->r15 = SUB32(ctx->r15, ctx->r13);
    // 0x801DE76C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801DE770: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x801DE774: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801DE778: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x801DE77C: lwc1        $f4, 0x64($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X64);
    // 0x801DE780: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DE784: lwc1        $f8, 0x7D28($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7D28);
    // 0x801DE788: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DE78C: lw          $a3, 0x60($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X60);
    // 0x801DE790: lwc1        $f10, 0x7D2C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7D2C);
    // 0x801DE794: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x801DE798: lwc1        $f6, 0x68($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X68);
    // 0x801DE79C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DE7A0: lwc1        $f16, 0x7D30($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7D30);
    // 0x801DE7A4: addiu       $t6, $t7, 0xA4
    ctx->r14 = ADD32(ctx->r15, 0XA4);
    // 0x801DE7A8: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x801DE7AC: addiu       $a0, $a0, 0x50E8
    ctx->r4 = ADD32(ctx->r4, 0X50E8);
    // 0x801DE7B0: addu        $a2, $t6, $t9
    ctx->r6 = ADD32(ctx->r14, ctx->r25);
    // 0x801DE7B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801DE7B8: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x801DE7BC: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x801DE7C0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x801DE7C4: jal         0x800C6868
    // 0x801DE7C8: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    func_800C6868(rdram, ctx);
        goto after_12;
    // 0x801DE7C8: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    after_12:
    // 0x801DE7CC: b           L_801DF8E4
    // 0x801DE7D0: nop

        goto L_801DF8E4;
    // 0x801DE7D0: nop

L_801DE7D4:
    // 0x801DE7D4: lw          $t8, 0xBC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XBC);
    // 0x801DE7D8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x801DE7DC: sll         $t2, $t8, 2
    ctx->r10 = S32(ctx->r24 << 2);
    // 0x801DE7E0: addu        $t2, $t2, $t8
    ctx->r10 = ADD32(ctx->r10, ctx->r24);
    // 0x801DE7E4: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x801DE7E8: subu        $t2, $t2, $t8
    ctx->r10 = SUB32(ctx->r10, ctx->r24);
    // 0x801DE7EC: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x801DE7F0: addu        $t2, $t2, $t8
    ctx->r10 = ADD32(ctx->r10, ctx->r24);
    // 0x801DE7F4: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x801DE7F8: addu        $t1, $t1, $t2
    ctx->r9 = ADD32(ctx->r9, ctx->r10);
    // 0x801DE7FC: lhu         $t1, -0x2A28($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X2A28);
    // 0x801DE800: andi        $t4, $t1, 0x8000
    ctx->r12 = ctx->r9 & 0X8000;
    // 0x801DE804: beq         $t4, $zero, L_801DF8EC
    if (ctx->r12 == 0) {
        // 0x801DE808: nop
    
            goto L_801DF8EC;
    }
    // 0x801DE808: nop

    // 0x801DE80C: lui         $t3, 0x8011
    ctx->r11 = S32(0X8011 << 16);
    // 0x801DE810: lw          $t3, -0x4514($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4514);
    // 0x801DE814: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x801DE818: lui         $t6, 0xDE00
    ctx->r14 = S32(0XDE00 << 16);
    // 0x801DE81C: sw          $t3, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r11;
    // 0x801DE820: lw          $t7, 0x98($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X98);
    // 0x801DE824: addiu       $t5, $t3, 0x8
    ctx->r13 = ADD32(ctx->r11, 0X8);
    // 0x801DE828: sw          $t5, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r13;
    // 0x801DE82C: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x801DE830: lw          $t0, 0x98($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X98);
    // 0x801DE834: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x801DE838: addiu       $t9, $t9, -0x51D0
    ctx->r25 = ADD32(ctx->r25, -0X51D0);
    // 0x801DE83C: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x801DE840: lw          $t8, 0xBC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XBC);
    // 0x801DE844: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x801DE848: addiu       $t4, $t4, -0x2A28
    ctx->r12 = ADD32(ctx->r12, -0X2A28);
    // 0x801DE84C: sll         $t2, $t8, 2
    ctx->r10 = S32(ctx->r24 << 2);
    // 0x801DE850: addu        $t2, $t2, $t8
    ctx->r10 = ADD32(ctx->r10, ctx->r24);
    // 0x801DE854: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x801DE858: subu        $t2, $t2, $t8
    ctx->r10 = SUB32(ctx->r10, ctx->r24);
    // 0x801DE85C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x801DE860: addu        $t2, $t2, $t8
    ctx->r10 = ADD32(ctx->r10, ctx->r24);
    // 0x801DE864: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x801DE868: addu        $t3, $t2, $t4
    ctx->r11 = ADD32(ctx->r10, ctx->r12);
    // 0x801DE86C: lwc1        $f18, 0x64($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X64);
    // 0x801DE870: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DE874: lwc1        $f6, 0x7D34($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7D34);
    // 0x801DE878: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DE87C: lw          $a3, 0x60($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X60);
    // 0x801DE880: lwc1        $f8, 0x7D38($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7D38);
    // 0x801DE884: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x801DE888: lwc1        $f4, 0x68($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X68);
    // 0x801DE88C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DE890: lwc1        $f10, 0x7D3C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7D3C);
    // 0x801DE894: addiu       $t1, $t2, 0xA4
    ctx->r9 = ADD32(ctx->r10, 0XA4);
    // 0x801DE898: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x801DE89C: addiu       $a0, $a0, 0x5218
    ctx->r4 = ADD32(ctx->r4, 0X5218);
    // 0x801DE8A0: addu        $a2, $t1, $t4
    ctx->r6 = ADD32(ctx->r9, ctx->r12);
    // 0x801DE8A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801DE8A8: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x801DE8AC: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x801DE8B0: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x801DE8B4: jal         0x800C6868
    // 0x801DE8B8: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    func_800C6868(rdram, ctx);
        goto after_13;
    // 0x801DE8B8: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    after_13:
    // 0x801DE8BC: b           L_801DF8E4
    // 0x801DE8C0: nop

        goto L_801DF8E4;
    // 0x801DE8C0: nop

L_801DE8C4:
    // 0x801DE8C4: lw          $t5, 0xBC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XBC);
    // 0x801DE8C8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801DE8CC: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x801DE8D0: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x801DE8D4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801DE8D8: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x801DE8DC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801DE8E0: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x801DE8E4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801DE8E8: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x801DE8EC: lhu         $t7, -0x2A28($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X2A28);
    // 0x801DE8F0: andi        $t9, $t7, 0x8000
    ctx->r25 = ctx->r15 & 0X8000;
    // 0x801DE8F4: beq         $t9, $zero, L_801DF8EC
    if (ctx->r25 == 0) {
        // 0x801DE8F8: nop
    
            goto L_801DF8EC;
    }
    // 0x801DE8F8: nop

    // 0x801DE8FC: lui         $t0, 0x8011
    ctx->r8 = S32(0X8011 << 16);
    // 0x801DE900: lw          $t0, -0x4514($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X4514);
    // 0x801DE904: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x801DE908: lui         $t1, 0xDE00
    ctx->r9 = S32(0XDE00 << 16);
    // 0x801DE90C: sw          $t0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r8;
    // 0x801DE910: lw          $t2, 0x94($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X94);
    // 0x801DE914: addiu       $t8, $t0, 0x8
    ctx->r24 = ADD32(ctx->r8, 0X8);
    // 0x801DE918: sw          $t8, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r24;
    // 0x801DE91C: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x801DE920: lw          $t3, 0x94($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X94);
    // 0x801DE924: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x801DE928: addiu       $t4, $t4, -0x51D0
    ctx->r12 = ADD32(ctx->r12, -0X51D0);
    // 0x801DE92C: sw          $t4, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r12;
    // 0x801DE930: lw          $t5, 0xBC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XBC);
    // 0x801DE934: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801DE938: addiu       $t9, $t9, -0x2A28
    ctx->r25 = ADD32(ctx->r25, -0X2A28);
    // 0x801DE93C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x801DE940: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x801DE944: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801DE948: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x801DE94C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801DE950: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x801DE954: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801DE958: addu        $t0, $t6, $t9
    ctx->r8 = ADD32(ctx->r14, ctx->r25);
    // 0x801DE95C: lwc1        $f16, 0x64($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X64);
    // 0x801DE960: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DE964: lwc1        $f4, 0x7D40($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7D40);
    // 0x801DE968: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DE96C: lw          $a3, 0x60($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X60);
    // 0x801DE970: lwc1        $f6, 0x7D44($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7D44);
    // 0x801DE974: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x801DE978: lwc1        $f18, 0x68($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X68);
    // 0x801DE97C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DE980: lwc1        $f8, 0x7D48($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7D48);
    // 0x801DE984: addiu       $t7, $t6, 0xA4
    ctx->r15 = ADD32(ctx->r14, 0XA4);
    // 0x801DE988: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x801DE98C: addiu       $a0, $a0, 0x5348
    ctx->r4 = ADD32(ctx->r4, 0X5348);
    // 0x801DE990: addu        $a2, $t7, $t9
    ctx->r6 = ADD32(ctx->r15, ctx->r25);
    // 0x801DE994: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801DE998: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x801DE99C: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x801DE9A0: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x801DE9A4: jal         0x800C6868
    // 0x801DE9A8: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    func_800C6868(rdram, ctx);
        goto after_14;
    // 0x801DE9A8: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    after_14:
    // 0x801DE9AC: b           L_801DF8E4
    // 0x801DE9B0: nop

        goto L_801DF8E4;
    // 0x801DE9B0: nop

L_801DE9B4:
    // 0x801DE9B4: lw          $t8, 0xBC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XBC);
    // 0x801DE9B8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x801DE9BC: sll         $t1, $t8, 2
    ctx->r9 = S32(ctx->r24 << 2);
    // 0x801DE9C0: addu        $t1, $t1, $t8
    ctx->r9 = ADD32(ctx->r9, ctx->r24);
    // 0x801DE9C4: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x801DE9C8: subu        $t1, $t1, $t8
    ctx->r9 = SUB32(ctx->r9, ctx->r24);
    // 0x801DE9CC: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x801DE9D0: addu        $t1, $t1, $t8
    ctx->r9 = ADD32(ctx->r9, ctx->r24);
    // 0x801DE9D4: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x801DE9D8: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x801DE9DC: lhu         $t2, -0x2A28($t2)
    ctx->r10 = MEM_HU(ctx->r10, -0X2A28);
    // 0x801DE9E0: andi        $t4, $t2, 0x8000
    ctx->r12 = ctx->r10 & 0X8000;
    // 0x801DE9E4: beq         $t4, $zero, L_801DF8EC
    if (ctx->r12 == 0) {
        // 0x801DE9E8: nop
    
            goto L_801DF8EC;
    }
    // 0x801DE9E8: nop

    // 0x801DE9EC: lui         $t3, 0x8011
    ctx->r11 = S32(0X8011 << 16);
    // 0x801DE9F0: lw          $t3, -0x4514($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4514);
    // 0x801DE9F4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x801DE9F8: lui         $t7, 0xDE00
    ctx->r15 = S32(0XDE00 << 16);
    // 0x801DE9FC: sw          $t3, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r11;
    // 0x801DEA00: lw          $t6, 0x90($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X90);
    // 0x801DEA04: addiu       $t5, $t3, 0x8
    ctx->r13 = ADD32(ctx->r11, 0X8);
    // 0x801DEA08: sw          $t5, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r13;
    // 0x801DEA0C: sw          $t7, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r15;
    // 0x801DEA10: lw          $t0, 0x90($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X90);
    // 0x801DEA14: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x801DEA18: addiu       $t9, $t9, -0x51D0
    ctx->r25 = ADD32(ctx->r25, -0X51D0);
    // 0x801DEA1C: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x801DEA20: lw          $t8, 0xBC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XBC);
    // 0x801DEA24: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x801DEA28: addiu       $t4, $t4, -0x2A28
    ctx->r12 = ADD32(ctx->r12, -0X2A28);
    // 0x801DEA2C: sll         $t1, $t8, 2
    ctx->r9 = S32(ctx->r24 << 2);
    // 0x801DEA30: addu        $t1, $t1, $t8
    ctx->r9 = ADD32(ctx->r9, ctx->r24);
    // 0x801DEA34: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x801DEA38: subu        $t1, $t1, $t8
    ctx->r9 = SUB32(ctx->r9, ctx->r24);
    // 0x801DEA3C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x801DEA40: addu        $t1, $t1, $t8
    ctx->r9 = ADD32(ctx->r9, ctx->r24);
    // 0x801DEA44: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x801DEA48: addu        $t3, $t1, $t4
    ctx->r11 = ADD32(ctx->r9, ctx->r12);
    // 0x801DEA4C: lwc1        $f10, 0x64($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X64);
    // 0x801DEA50: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DEA54: lwc1        $f18, 0x7D4C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7D4C);
    // 0x801DEA58: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DEA5C: lw          $a3, 0x60($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X60);
    // 0x801DEA60: lwc1        $f4, 0x7D50($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7D50);
    // 0x801DEA64: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x801DEA68: lwc1        $f16, 0x68($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X68);
    // 0x801DEA6C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DEA70: lwc1        $f6, 0x7D54($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7D54);
    // 0x801DEA74: addiu       $t2, $t1, 0xA4
    ctx->r10 = ADD32(ctx->r9, 0XA4);
    // 0x801DEA78: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x801DEA7C: addiu       $a0, $a0, 0x5518
    ctx->r4 = ADD32(ctx->r4, 0X5518);
    // 0x801DEA80: addu        $a2, $t2, $t4
    ctx->r6 = ADD32(ctx->r10, ctx->r12);
    // 0x801DEA84: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801DEA88: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    // 0x801DEA8C: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x801DEA90: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x801DEA94: jal         0x800C6868
    // 0x801DEA98: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    func_800C6868(rdram, ctx);
        goto after_15;
    // 0x801DEA98: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    after_15:
    // 0x801DEA9C: b           L_801DF8E4
    // 0x801DEAA0: nop

        goto L_801DF8E4;
    // 0x801DEAA0: nop

L_801DEAA4:
    // 0x801DEAA4: lw          $t5, 0xBC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XBC);
    // 0x801DEAA8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801DEAAC: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x801DEAB0: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x801DEAB4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801DEAB8: subu        $t7, $t7, $t5
    ctx->r15 = SUB32(ctx->r15, ctx->r13);
    // 0x801DEABC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801DEAC0: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x801DEAC4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801DEAC8: addu        $t6, $t6, $t7
    ctx->r14 = ADD32(ctx->r14, ctx->r15);
    // 0x801DEACC: lhu         $t6, -0x2A28($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X2A28);
    // 0x801DEAD0: andi        $t9, $t6, 0x8000
    ctx->r25 = ctx->r14 & 0X8000;
    // 0x801DEAD4: beq         $t9, $zero, L_801DF8EC
    if (ctx->r25 == 0) {
        // 0x801DEAD8: nop
    
            goto L_801DF8EC;
    }
    // 0x801DEAD8: nop

    // 0x801DEADC: lui         $t0, 0x8011
    ctx->r8 = S32(0X8011 << 16);
    // 0x801DEAE0: lw          $t0, -0x4514($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X4514);
    // 0x801DEAE4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x801DEAE8: lui         $t2, 0xDE00
    ctx->r10 = S32(0XDE00 << 16);
    // 0x801DEAEC: sw          $t0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r8;
    // 0x801DEAF0: lw          $t1, 0x8C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8C);
    // 0x801DEAF4: addiu       $t8, $t0, 0x8
    ctx->r24 = ADD32(ctx->r8, 0X8);
    // 0x801DEAF8: sw          $t8, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r24;
    // 0x801DEAFC: sw          $t2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r10;
    // 0x801DEB00: lw          $t3, 0x8C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X8C);
    // 0x801DEB04: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x801DEB08: addiu       $t4, $t4, -0x51D0
    ctx->r12 = ADD32(ctx->r12, -0X51D0);
    // 0x801DEB0C: sw          $t4, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r12;
    // 0x801DEB10: lw          $t5, 0xBC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XBC);
    // 0x801DEB14: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801DEB18: addiu       $t9, $t9, -0x2A28
    ctx->r25 = ADD32(ctx->r25, -0X2A28);
    // 0x801DEB1C: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x801DEB20: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x801DEB24: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801DEB28: subu        $t7, $t7, $t5
    ctx->r15 = SUB32(ctx->r15, ctx->r13);
    // 0x801DEB2C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801DEB30: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x801DEB34: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801DEB38: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x801DEB3C: lwc1        $f8, 0x64($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X64);
    // 0x801DEB40: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DEB44: lwc1        $f16, 0x7D58($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7D58);
    // 0x801DEB48: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DEB4C: lw          $a3, 0x60($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X60);
    // 0x801DEB50: lwc1        $f18, 0x7D5C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7D5C);
    // 0x801DEB54: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x801DEB58: lwc1        $f10, 0x68($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X68);
    // 0x801DEB5C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DEB60: lwc1        $f4, 0x7D60($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7D60);
    // 0x801DEB64: addiu       $t6, $t7, 0xA4
    ctx->r14 = ADD32(ctx->r15, 0XA4);
    // 0x801DEB68: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x801DEB6C: addiu       $a0, $a0, 0x5670
    ctx->r4 = ADD32(ctx->r4, 0X5670);
    // 0x801DEB70: addu        $a2, $t6, $t9
    ctx->r6 = ADD32(ctx->r14, ctx->r25);
    // 0x801DEB74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801DEB78: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x801DEB7C: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    // 0x801DEB80: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x801DEB84: jal         0x800C6868
    // 0x801DEB88: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    func_800C6868(rdram, ctx);
        goto after_16;
    // 0x801DEB88: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    after_16:
    // 0x801DEB8C: b           L_801DF8E4
    // 0x801DEB90: nop

        goto L_801DF8E4;
    // 0x801DEB90: nop

L_801DEB94:
    // 0x801DEB94: lw          $t8, 0xBC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XBC);
    // 0x801DEB98: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x801DEB9C: sll         $t2, $t8, 2
    ctx->r10 = S32(ctx->r24 << 2);
    // 0x801DEBA0: addu        $t2, $t2, $t8
    ctx->r10 = ADD32(ctx->r10, ctx->r24);
    // 0x801DEBA4: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x801DEBA8: subu        $t2, $t2, $t8
    ctx->r10 = SUB32(ctx->r10, ctx->r24);
    // 0x801DEBAC: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x801DEBB0: addu        $t2, $t2, $t8
    ctx->r10 = ADD32(ctx->r10, ctx->r24);
    // 0x801DEBB4: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x801DEBB8: addu        $t1, $t1, $t2
    ctx->r9 = ADD32(ctx->r9, ctx->r10);
    // 0x801DEBBC: lhu         $t1, -0x2A28($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X2A28);
    // 0x801DEBC0: andi        $t4, $t1, 0x8000
    ctx->r12 = ctx->r9 & 0X8000;
    // 0x801DEBC4: beq         $t4, $zero, L_801DF8EC
    if (ctx->r12 == 0) {
        // 0x801DEBC8: nop
    
            goto L_801DF8EC;
    }
    // 0x801DEBC8: nop

    // 0x801DEBCC: lui         $t3, 0x8011
    ctx->r11 = S32(0X8011 << 16);
    // 0x801DEBD0: lw          $t3, -0x4514($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4514);
    // 0x801DEBD4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x801DEBD8: lui         $t6, 0xDE00
    ctx->r14 = S32(0XDE00 << 16);
    // 0x801DEBDC: sw          $t3, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r11;
    // 0x801DEBE0: lw          $t7, 0x88($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X88);
    // 0x801DEBE4: addiu       $t5, $t3, 0x8
    ctx->r13 = ADD32(ctx->r11, 0X8);
    // 0x801DEBE8: sw          $t5, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r13;
    // 0x801DEBEC: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x801DEBF0: lw          $t0, 0x88($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X88);
    // 0x801DEBF4: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x801DEBF8: addiu       $t9, $t9, -0x51D0
    ctx->r25 = ADD32(ctx->r25, -0X51D0);
    // 0x801DEBFC: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x801DEC00: lw          $t8, 0xBC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XBC);
    // 0x801DEC04: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x801DEC08: addiu       $t4, $t4, -0x2A28
    ctx->r12 = ADD32(ctx->r12, -0X2A28);
    // 0x801DEC0C: sll         $t2, $t8, 2
    ctx->r10 = S32(ctx->r24 << 2);
    // 0x801DEC10: addu        $t2, $t2, $t8
    ctx->r10 = ADD32(ctx->r10, ctx->r24);
    // 0x801DEC14: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x801DEC18: subu        $t2, $t2, $t8
    ctx->r10 = SUB32(ctx->r10, ctx->r24);
    // 0x801DEC1C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x801DEC20: addu        $t2, $t2, $t8
    ctx->r10 = ADD32(ctx->r10, ctx->r24);
    // 0x801DEC24: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x801DEC28: addu        $t3, $t2, $t4
    ctx->r11 = ADD32(ctx->r10, ctx->r12);
    // 0x801DEC2C: lwc1        $f6, 0x64($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X64);
    // 0x801DEC30: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DEC34: lwc1        $f10, 0x7D64($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7D64);
    // 0x801DEC38: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DEC3C: lw          $a3, 0x60($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X60);
    // 0x801DEC40: lwc1        $f16, 0x7D68($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7D68);
    // 0x801DEC44: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x801DEC48: lwc1        $f8, 0x68($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X68);
    // 0x801DEC4C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DEC50: lwc1        $f18, 0x7D6C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7D6C);
    // 0x801DEC54: addiu       $t1, $t2, 0xA4
    ctx->r9 = ADD32(ctx->r10, 0XA4);
    // 0x801DEC58: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x801DEC5C: addiu       $a0, $a0, 0x5840
    ctx->r4 = ADD32(ctx->r4, 0X5840);
    // 0x801DEC60: addu        $a2, $t1, $t4
    ctx->r6 = ADD32(ctx->r9, ctx->r12);
    // 0x801DEC64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801DEC68: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x801DEC6C: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    // 0x801DEC70: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x801DEC74: jal         0x800C6868
    // 0x801DEC78: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    func_800C6868(rdram, ctx);
        goto after_17;
    // 0x801DEC78: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    after_17:
    // 0x801DEC7C: b           L_801DF8E4
    // 0x801DEC80: nop

        goto L_801DF8E4;
    // 0x801DEC80: nop

L_801DEC84:
    // 0x801DEC84: lw          $t5, 0xBC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XBC);
    // 0x801DEC88: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801DEC8C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x801DEC90: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x801DEC94: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801DEC98: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x801DEC9C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801DECA0: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x801DECA4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801DECA8: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x801DECAC: lhu         $t7, -0x2A28($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X2A28);
    // 0x801DECB0: andi        $t9, $t7, 0x8000
    ctx->r25 = ctx->r15 & 0X8000;
    // 0x801DECB4: beq         $t9, $zero, L_801DF8EC
    if (ctx->r25 == 0) {
        // 0x801DECB8: nop
    
            goto L_801DF8EC;
    }
    // 0x801DECB8: nop

    // 0x801DECBC: lui         $t0, 0x8011
    ctx->r8 = S32(0X8011 << 16);
    // 0x801DECC0: lw          $t0, -0x4514($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X4514);
    // 0x801DECC4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x801DECC8: lui         $t1, 0xDE00
    ctx->r9 = S32(0XDE00 << 16);
    // 0x801DECCC: sw          $t0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r8;
    // 0x801DECD0: lw          $t2, 0x84($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X84);
    // 0x801DECD4: addiu       $t8, $t0, 0x8
    ctx->r24 = ADD32(ctx->r8, 0X8);
    // 0x801DECD8: sw          $t8, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r24;
    // 0x801DECDC: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x801DECE0: lw          $t3, 0x84($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X84);
    // 0x801DECE4: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x801DECE8: addiu       $t4, $t4, -0x51D0
    ctx->r12 = ADD32(ctx->r12, -0X51D0);
    // 0x801DECEC: sw          $t4, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r12;
    // 0x801DECF0: lw          $t5, 0xBC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XBC);
    // 0x801DECF4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801DECF8: addiu       $t9, $t9, -0x2A28
    ctx->r25 = ADD32(ctx->r25, -0X2A28);
    // 0x801DECFC: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x801DED00: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x801DED04: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801DED08: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x801DED0C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801DED10: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x801DED14: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801DED18: addu        $t0, $t6, $t9
    ctx->r8 = ADD32(ctx->r14, ctx->r25);
    // 0x801DED1C: lwc1        $f4, 0x64($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X64);
    // 0x801DED20: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DED24: lwc1        $f8, 0x7D70($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7D70);
    // 0x801DED28: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DED2C: lw          $a3, 0x60($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X60);
    // 0x801DED30: lwc1        $f10, 0x7D74($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7D74);
    // 0x801DED34: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x801DED38: lwc1        $f6, 0x68($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X68);
    // 0x801DED3C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DED40: lwc1        $f16, 0x7D78($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7D78);
    // 0x801DED44: addiu       $t7, $t6, 0xA4
    ctx->r15 = ADD32(ctx->r14, 0XA4);
    // 0x801DED48: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x801DED4C: addiu       $a0, $a0, 0x5998
    ctx->r4 = ADD32(ctx->r4, 0X5998);
    // 0x801DED50: addu        $a2, $t7, $t9
    ctx->r6 = ADD32(ctx->r15, ctx->r25);
    // 0x801DED54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801DED58: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x801DED5C: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x801DED60: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x801DED64: jal         0x800C6868
    // 0x801DED68: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    func_800C6868(rdram, ctx);
        goto after_18;
    // 0x801DED68: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    after_18:
    // 0x801DED6C: b           L_801DF8E4
    // 0x801DED70: nop

        goto L_801DF8E4;
    // 0x801DED70: nop

L_801DED74:
    // 0x801DED74: lw          $t8, 0xBC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XBC);
    // 0x801DED78: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x801DED7C: sll         $t1, $t8, 2
    ctx->r9 = S32(ctx->r24 << 2);
    // 0x801DED80: addu        $t1, $t1, $t8
    ctx->r9 = ADD32(ctx->r9, ctx->r24);
    // 0x801DED84: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x801DED88: subu        $t1, $t1, $t8
    ctx->r9 = SUB32(ctx->r9, ctx->r24);
    // 0x801DED8C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x801DED90: addu        $t1, $t1, $t8
    ctx->r9 = ADD32(ctx->r9, ctx->r24);
    // 0x801DED94: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x801DED98: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x801DED9C: lhu         $t2, -0x2A28($t2)
    ctx->r10 = MEM_HU(ctx->r10, -0X2A28);
    // 0x801DEDA0: andi        $t4, $t2, 0x8000
    ctx->r12 = ctx->r10 & 0X8000;
    // 0x801DEDA4: beq         $t4, $zero, L_801DF8EC
    if (ctx->r12 == 0) {
        // 0x801DEDA8: nop
    
            goto L_801DF8EC;
    }
    // 0x801DEDA8: nop

    // 0x801DEDAC: lui         $t3, 0x8011
    ctx->r11 = S32(0X8011 << 16);
    // 0x801DEDB0: lw          $t3, -0x4514($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4514);
    // 0x801DEDB4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x801DEDB8: lui         $t7, 0xDE00
    ctx->r15 = S32(0XDE00 << 16);
    // 0x801DEDBC: sw          $t3, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r11;
    // 0x801DEDC0: lw          $t6, 0x80($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X80);
    // 0x801DEDC4: addiu       $t5, $t3, 0x8
    ctx->r13 = ADD32(ctx->r11, 0X8);
    // 0x801DEDC8: sw          $t5, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r13;
    // 0x801DEDCC: sw          $t7, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r15;
    // 0x801DEDD0: lw          $t0, 0x80($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X80);
    // 0x801DEDD4: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x801DEDD8: addiu       $t9, $t9, -0x51D0
    ctx->r25 = ADD32(ctx->r25, -0X51D0);
    // 0x801DEDDC: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x801DEDE0: lw          $t8, 0xBC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XBC);
    // 0x801DEDE4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x801DEDE8: addiu       $t4, $t4, -0x2A28
    ctx->r12 = ADD32(ctx->r12, -0X2A28);
    // 0x801DEDEC: sll         $t1, $t8, 2
    ctx->r9 = S32(ctx->r24 << 2);
    // 0x801DEDF0: addu        $t1, $t1, $t8
    ctx->r9 = ADD32(ctx->r9, ctx->r24);
    // 0x801DEDF4: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x801DEDF8: subu        $t1, $t1, $t8
    ctx->r9 = SUB32(ctx->r9, ctx->r24);
    // 0x801DEDFC: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x801DEE00: addu        $t1, $t1, $t8
    ctx->r9 = ADD32(ctx->r9, ctx->r24);
    // 0x801DEE04: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x801DEE08: addu        $t3, $t1, $t4
    ctx->r11 = ADD32(ctx->r9, ctx->r12);
    // 0x801DEE0C: lwc1        $f18, 0x64($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X64);
    // 0x801DEE10: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DEE14: lwc1        $f6, 0x7D7C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7D7C);
    // 0x801DEE18: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DEE1C: lw          $a3, 0x60($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X60);
    // 0x801DEE20: lwc1        $f8, 0x7D80($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7D80);
    // 0x801DEE24: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x801DEE28: lwc1        $f4, 0x68($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X68);
    // 0x801DEE2C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DEE30: lwc1        $f10, 0x7D84($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7D84);
    // 0x801DEE34: addiu       $t2, $t1, 0xA4
    ctx->r10 = ADD32(ctx->r9, 0XA4);
    // 0x801DEE38: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x801DEE3C: addiu       $a0, $a0, 0x5AC0
    ctx->r4 = ADD32(ctx->r4, 0X5AC0);
    // 0x801DEE40: addu        $a2, $t2, $t4
    ctx->r6 = ADD32(ctx->r10, ctx->r12);
    // 0x801DEE44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801DEE48: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x801DEE4C: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x801DEE50: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x801DEE54: jal         0x800C6868
    // 0x801DEE58: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    func_800C6868(rdram, ctx);
        goto after_19;
    // 0x801DEE58: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    after_19:
    // 0x801DEE5C: b           L_801DF8E4
    // 0x801DEE60: nop

        goto L_801DF8E4;
    // 0x801DEE60: nop

L_801DEE64:
    // 0x801DEE64: lw          $t5, 0xBC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XBC);
    // 0x801DEE68: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801DEE6C: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x801DEE70: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x801DEE74: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801DEE78: subu        $t7, $t7, $t5
    ctx->r15 = SUB32(ctx->r15, ctx->r13);
    // 0x801DEE7C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801DEE80: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x801DEE84: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801DEE88: addu        $t6, $t6, $t7
    ctx->r14 = ADD32(ctx->r14, ctx->r15);
    // 0x801DEE8C: lhu         $t6, -0x2A28($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X2A28);
    // 0x801DEE90: andi        $t9, $t6, 0x8000
    ctx->r25 = ctx->r14 & 0X8000;
    // 0x801DEE94: beq         $t9, $zero, L_801DF8EC
    if (ctx->r25 == 0) {
        // 0x801DEE98: nop
    
            goto L_801DF8EC;
    }
    // 0x801DEE98: nop

    // 0x801DEE9C: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x801DEEA0: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x801DEEA4: addiu       $t8, $zero, 0xE6
    ctx->r24 = ADD32(0, 0XE6);
    // 0x801DEEA8: addiu       $t2, $zero, 0xE6
    ctx->r10 = ADD32(0, 0XE6);
    // 0x801DEEAC: addiu       $t1, $zero, 0xC8
    ctx->r9 = ADD32(0, 0XC8);
    // 0x801DEEB0: addiu       $t4, $zero, 0xC8
    ctx->r12 = ADD32(0, 0XC8);
    // 0x801DEEB4: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x801DEEB8: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x801DEEBC: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x801DEEC0: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x801DEEC4: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x801DEEC8: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x801DEECC: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x801DEED0: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x801DEED4: lw          $a0, 0xBC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XBC);
    // 0x801DEED8: lui         $a2, 0x3E80
    ctx->r6 = S32(0X3E80 << 16);
    // 0x801DEEDC: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x801DEEE0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x801DEEE4: jal         0x801DD1B8
    // 0x801DEEE8: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    func_801DD1B8_0BA450(rdram, ctx);
        goto after_20;
    // 0x801DEEE8: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    after_20:
    // 0x801DEEEC: b           L_801DF8E4
    // 0x801DEEF0: nop

        goto L_801DF8E4;
    // 0x801DEEF0: nop

L_801DEEF4:
    // 0x801DEEF4: lw          $t5, 0xBC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XBC);
    // 0x801DEEF8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801DEEFC: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x801DEF00: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x801DEF04: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801DEF08: subu        $t7, $t7, $t5
    ctx->r15 = SUB32(ctx->r15, ctx->r13);
    // 0x801DEF0C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801DEF10: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x801DEF14: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801DEF18: addu        $t6, $t6, $t7
    ctx->r14 = ADD32(ctx->r14, ctx->r15);
    // 0x801DEF1C: lhu         $t6, -0x2A28($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X2A28);
    // 0x801DEF20: andi        $t9, $t6, 0x8000
    ctx->r25 = ctx->r14 & 0X8000;
    // 0x801DEF24: beq         $t9, $zero, L_801DF8EC
    if (ctx->r25 == 0) {
        // 0x801DEF28: nop
    
            goto L_801DF8EC;
    }
    // 0x801DEF28: nop

    // 0x801DEF2C: lui         $a1, 0x3ECC
    ctx->r5 = S32(0X3ECC << 16);
    // 0x801DEF30: lui         $a2, 0x3EB3
    ctx->r6 = S32(0X3EB3 << 16);
    // 0x801DEF34: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x801DEF38: addiu       $t8, $zero, 0xE6
    ctx->r24 = ADD32(0, 0XE6);
    // 0x801DEF3C: addiu       $t2, $zero, 0xE6
    ctx->r10 = ADD32(0, 0XE6);
    // 0x801DEF40: addiu       $t1, $zero, 0xC8
    ctx->r9 = ADD32(0, 0XC8);
    // 0x801DEF44: addiu       $t4, $zero, 0xC8
    ctx->r12 = ADD32(0, 0XC8);
    // 0x801DEF48: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x801DEF4C: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x801DEF50: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x801DEF54: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x801DEF58: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x801DEF5C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x801DEF60: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x801DEF64: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x801DEF68: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x801DEF6C: lw          $a0, 0xBC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XBC);
    // 0x801DEF70: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x801DEF74: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x801DEF78: jal         0x801DD1B8
    // 0x801DEF7C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    func_801DD1B8_0BA450(rdram, ctx);
        goto after_21;
    // 0x801DEF7C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    after_21:
    // 0x801DEF80: b           L_801DF8E4
    // 0x801DEF84: nop

        goto L_801DF8E4;
    // 0x801DEF84: nop

L_801DEF88:
    // 0x801DEF88: lw          $t5, 0xBC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XBC);
    // 0x801DEF8C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801DEF90: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x801DEF94: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x801DEF98: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801DEF9C: subu        $t7, $t7, $t5
    ctx->r15 = SUB32(ctx->r15, ctx->r13);
    // 0x801DEFA0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801DEFA4: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x801DEFA8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801DEFAC: addu        $t6, $t6, $t7
    ctx->r14 = ADD32(ctx->r14, ctx->r15);
    // 0x801DEFB0: lhu         $t6, -0x2A28($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X2A28);
    // 0x801DEFB4: andi        $t9, $t6, 0x8000
    ctx->r25 = ctx->r14 & 0X8000;
    // 0x801DEFB8: beq         $t9, $zero, L_801DF8EC
    if (ctx->r25 == 0) {
        // 0x801DEFBC: nop
    
            goto L_801DF8EC;
    }
    // 0x801DEFBC: nop

    // 0x801DEFC0: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x801DEFC4: lui         $a2, 0x3E19
    ctx->r6 = S32(0X3E19 << 16);
    // 0x801DEFC8: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x801DEFCC: addiu       $t8, $zero, 0xE6
    ctx->r24 = ADD32(0, 0XE6);
    // 0x801DEFD0: addiu       $t2, $zero, 0xE6
    ctx->r10 = ADD32(0, 0XE6);
    // 0x801DEFD4: addiu       $t1, $zero, 0xC8
    ctx->r9 = ADD32(0, 0XC8);
    // 0x801DEFD8: addiu       $t4, $zero, 0xC8
    ctx->r12 = ADD32(0, 0XC8);
    // 0x801DEFDC: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x801DEFE0: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x801DEFE4: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x801DEFE8: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x801DEFEC: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x801DEFF0: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x801DEFF4: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x801DEFF8: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x801DEFFC: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x801DF000: lw          $a0, 0xBC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XBC);
    // 0x801DF004: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x801DF008: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x801DF00C: jal         0x801DD1B8
    // 0x801DF010: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    func_801DD1B8_0BA450(rdram, ctx);
        goto after_22;
    // 0x801DF010: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    after_22:
    // 0x801DF014: b           L_801DF8E4
    // 0x801DF018: nop

        goto L_801DF8E4;
    // 0x801DF018: nop

L_801DF01C:
    // 0x801DF01C: lw          $t5, 0xBC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XBC);
    // 0x801DF020: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801DF024: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x801DF028: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x801DF02C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801DF030: subu        $t7, $t7, $t5
    ctx->r15 = SUB32(ctx->r15, ctx->r13);
    // 0x801DF034: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801DF038: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x801DF03C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801DF040: addu        $t6, $t6, $t7
    ctx->r14 = ADD32(ctx->r14, ctx->r15);
    // 0x801DF044: lhu         $t6, -0x2A28($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X2A28);
    // 0x801DF048: andi        $t9, $t6, 0x8000
    ctx->r25 = ctx->r14 & 0X8000;
    // 0x801DF04C: beq         $t9, $zero, L_801DF8EC
    if (ctx->r25 == 0) {
        // 0x801DF050: nop
    
            goto L_801DF8EC;
    }
    // 0x801DF050: nop

    // 0x801DF054: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x801DF058: lui         $a2, 0x3E19
    ctx->r6 = S32(0X3E19 << 16);
    // 0x801DF05C: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x801DF060: addiu       $t8, $zero, 0xE6
    ctx->r24 = ADD32(0, 0XE6);
    // 0x801DF064: addiu       $t2, $zero, 0xE6
    ctx->r10 = ADD32(0, 0XE6);
    // 0x801DF068: addiu       $t1, $zero, 0xC8
    ctx->r9 = ADD32(0, 0XC8);
    // 0x801DF06C: addiu       $t4, $zero, 0xC8
    ctx->r12 = ADD32(0, 0XC8);
    // 0x801DF070: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x801DF074: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801DF078: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x801DF07C: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x801DF080: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x801DF084: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x801DF088: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x801DF08C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x801DF090: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x801DF094: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x801DF098: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x801DF09C: lw          $a0, 0xBC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XBC);
    // 0x801DF0A0: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x801DF0A4: jal         0x801DD1B8
    // 0x801DF0A8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    func_801DD1B8_0BA450(rdram, ctx);
        goto after_23;
    // 0x801DF0A8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_23:
    // 0x801DF0AC: b           L_801DF8E4
    // 0x801DF0B0: nop

        goto L_801DF8E4;
    // 0x801DF0B0: nop

L_801DF0B4:
    // 0x801DF0B4: lw          $t7, 0xBC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XBC);
    // 0x801DF0B8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801DF0BC: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x801DF0C0: addu        $t6, $t6, $t7
    ctx->r14 = ADD32(ctx->r14, ctx->r15);
    // 0x801DF0C4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801DF0C8: subu        $t6, $t6, $t7
    ctx->r14 = SUB32(ctx->r14, ctx->r15);
    // 0x801DF0CC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801DF0D0: addu        $t6, $t6, $t7
    ctx->r14 = ADD32(ctx->r14, ctx->r15);
    // 0x801DF0D4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801DF0D8: addu        $t9, $t9, $t6
    ctx->r25 = ADD32(ctx->r25, ctx->r14);
    // 0x801DF0DC: lhu         $t9, -0x2A28($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X2A28);
    // 0x801DF0E0: andi        $t0, $t9, 0x8000
    ctx->r8 = ctx->r25 & 0X8000;
    // 0x801DF0E4: beq         $t0, $zero, L_801DF8EC
    if (ctx->r8 == 0) {
        // 0x801DF0E8: nop
    
            goto L_801DF8EC;
    }
    // 0x801DF0E8: nop

    // 0x801DF0EC: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x801DF0F0: addiu       $t8, $zero, 0xC8
    ctx->r24 = ADD32(0, 0XC8);
    // 0x801DF0F4: addiu       $t2, $zero, 0xC8
    ctx->r10 = ADD32(0, 0XC8);
    // 0x801DF0F8: addiu       $t1, $zero, 0xE6
    ctx->r9 = ADD32(0, 0XE6);
    // 0x801DF0FC: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x801DF100: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x801DF104: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801DF108: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x801DF10C: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x801DF110: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x801DF114: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x801DF118: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x801DF11C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x801DF120: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x801DF124: lw          $a0, 0xBC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XBC);
    // 0x801DF128: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x801DF12C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x801DF130: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x801DF134: jal         0x801DD1B8
    // 0x801DF138: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    func_801DD1B8_0BA450(rdram, ctx);
        goto after_24;
    // 0x801DF138: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_24:
    // 0x801DF13C: b           L_801DF8E4
    // 0x801DF140: nop

        goto L_801DF8E4;
    // 0x801DF140: nop

L_801DF144:
    // 0x801DF144: lw          $t7, 0xBC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XBC);
    // 0x801DF148: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801DF14C: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x801DF150: addu        $t6, $t6, $t7
    ctx->r14 = ADD32(ctx->r14, ctx->r15);
    // 0x801DF154: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801DF158: subu        $t6, $t6, $t7
    ctx->r14 = SUB32(ctx->r14, ctx->r15);
    // 0x801DF15C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801DF160: addu        $t6, $t6, $t7
    ctx->r14 = ADD32(ctx->r14, ctx->r15);
    // 0x801DF164: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801DF168: addu        $t9, $t9, $t6
    ctx->r25 = ADD32(ctx->r25, ctx->r14);
    // 0x801DF16C: lhu         $t9, -0x2A28($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X2A28);
    // 0x801DF170: andi        $t0, $t9, 0x8000
    ctx->r8 = ctx->r25 & 0X8000;
    // 0x801DF174: beq         $t0, $zero, L_801DF8EC
    if (ctx->r8 == 0) {
        // 0x801DF178: nop
    
            goto L_801DF8EC;
    }
    // 0x801DF178: nop

    // 0x801DF17C: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x801DF180: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x801DF184: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x801DF188: addiu       $t1, $zero, 0xE6
    ctx->r9 = ADD32(0, 0XE6);
    // 0x801DF18C: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x801DF190: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x801DF194: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801DF198: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x801DF19C: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x801DF1A0: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x801DF1A4: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x801DF1A8: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x801DF1AC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x801DF1B0: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x801DF1B4: lw          $a0, 0xBC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XBC);
    // 0x801DF1B8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x801DF1BC: addiu       $a3, $zero, 0xC8
    ctx->r7 = ADD32(0, 0XC8);
    // 0x801DF1C0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x801DF1C4: jal         0x801DD1B8
    // 0x801DF1C8: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    func_801DD1B8_0BA450(rdram, ctx);
        goto after_25;
    // 0x801DF1C8: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    after_25:
    // 0x801DF1CC: b           L_801DF8E4
    // 0x801DF1D0: nop

        goto L_801DF8E4;
    // 0x801DF1D0: nop

L_801DF1D4:
    // 0x801DF1D4: lw          $t7, 0xBC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XBC);
    // 0x801DF1D8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801DF1DC: addiu       $t9, $t9, -0x2A28
    ctx->r25 = ADD32(ctx->r25, -0X2A28);
    // 0x801DF1E0: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x801DF1E4: addu        $t6, $t6, $t7
    ctx->r14 = ADD32(ctx->r14, ctx->r15);
    // 0x801DF1E8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801DF1EC: subu        $t6, $t6, $t7
    ctx->r14 = SUB32(ctx->r14, ctx->r15);
    // 0x801DF1F0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801DF1F4: addu        $t6, $t6, $t7
    ctx->r14 = ADD32(ctx->r14, ctx->r15);
    // 0x801DF1F8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801DF1FC: addu        $t0, $t6, $t9
    ctx->r8 = ADD32(ctx->r14, ctx->r25);
    // 0x801DF200: lhu         $t8, 0x0($t0)
    ctx->r24 = MEM_HU(ctx->r8, 0X0);
    // 0x801DF204: andi        $t2, $t8, 0x8000
    ctx->r10 = ctx->r24 & 0X8000;
    // 0x801DF208: bne         $t2, $zero, L_801DF218
    if (ctx->r10 != 0) {
        // 0x801DF20C: nop
    
            goto L_801DF218;
    }
    // 0x801DF20C: nop

    // 0x801DF210: b           L_801DF8EC
    // 0x801DF214: sw          $zero, 0x2C($t0)
    MEM_W(0X2C, ctx->r8) = 0;
        goto L_801DF8EC;
    // 0x801DF214: sw          $zero, 0x2C($t0)
    MEM_W(0X2C, ctx->r8) = 0;
L_801DF218:
    // 0x801DF218: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x801DF21C: lw          $t1, -0x2E34($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2E34);
    // 0x801DF220: sltiu       $at, $t1, 0x3A1
    ctx->r1 = ctx->r9 < 0X3A1 ? 1 : 0;
    // 0x801DF224: bne         $at, $zero, L_801DF8E4
    if (ctx->r1 != 0) {
        // 0x801DF228: sltiu       $at, $t1, 0x407
        ctx->r1 = ctx->r9 < 0X407 ? 1 : 0;
            goto L_801DF8E4;
    }
    // 0x801DF228: sltiu       $at, $t1, 0x407
    ctx->r1 = ctx->r9 < 0X407 ? 1 : 0;
    // 0x801DF22C: beq         $at, $zero, L_801DF8E4
    if (ctx->r1 == 0) {
        // 0x801DF230: nop
    
            goto L_801DF8E4;
    }
    // 0x801DF230: nop

    // 0x801DF234: lw          $t4, 0xBC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XBC);
    // 0x801DF238: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x801DF23C: addiu       $t5, $t5, -0x2A28
    ctx->r13 = ADD32(ctx->r13, -0X2A28);
    // 0x801DF240: sll         $t3, $t4, 2
    ctx->r11 = S32(ctx->r12 << 2);
    // 0x801DF244: addu        $t3, $t3, $t4
    ctx->r11 = ADD32(ctx->r11, ctx->r12);
    // 0x801DF248: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x801DF24C: subu        $t3, $t3, $t4
    ctx->r11 = SUB32(ctx->r11, ctx->r12);
    // 0x801DF250: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x801DF254: addu        $t3, $t3, $t4
    ctx->r11 = ADD32(ctx->r11, ctx->r12);
    // 0x801DF258: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x801DF25C: addu        $t7, $t3, $t5
    ctx->r15 = ADD32(ctx->r11, ctx->r13);
    // 0x801DF260: lw          $t6, 0x2C($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X2C);
    // 0x801DF264: sltiu       $at, $t6, 0x1F
    ctx->r1 = ctx->r14 < 0X1F ? 1 : 0;
    // 0x801DF268: beq         $at, $zero, L_801DF2C0
    if (ctx->r1 == 0) {
        // 0x801DF26C: nop
    
            goto L_801DF2C0;
    }
    // 0x801DF26C: nop

    // 0x801DF270: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x801DF274: sw          $t9, 0x2C($t7)
    MEM_W(0X2C, ctx->r15) = ctx->r25;
    // 0x801DF278: lw          $t8, 0xBC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XBC);
    // 0x801DF27C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x801DF280: sll         $t2, $t8, 2
    ctx->r10 = S32(ctx->r24 << 2);
    // 0x801DF284: addu        $t2, $t2, $t8
    ctx->r10 = ADD32(ctx->r10, ctx->r24);
    // 0x801DF288: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x801DF28C: subu        $t2, $t2, $t8
    ctx->r10 = SUB32(ctx->r10, ctx->r24);
    // 0x801DF290: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x801DF294: addu        $t2, $t2, $t8
    ctx->r10 = ADD32(ctx->r10, ctx->r24);
    // 0x801DF298: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x801DF29C: addu        $a1, $a1, $t2
    ctx->r5 = ADD32(ctx->r5, ctx->r10);
    // 0x801DF2A0: lw          $a1, -0x29FC($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X29FC);
    // 0x801DF2A4: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x801DF2A8: sll         $t0, $a1, 3
    ctx->r8 = S32(ctx->r5 << 3);
    // 0x801DF2AC: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    // 0x801DF2B0: jal         0x801DCD3C
    // 0x801DF2B4: addiu       $a1, $a1, 0x7
    ctx->r5 = ADD32(ctx->r5, 0X7);
    func_801DCD3C_0BA450(rdram, ctx);
        goto after_26;
    // 0x801DF2B4: addiu       $a1, $a1, 0x7
    ctx->r5 = ADD32(ctx->r5, 0X7);
    after_26:
    // 0x801DF2B8: b           L_801DF8E4
    // 0x801DF2BC: nop

        goto L_801DF8E4;
    // 0x801DF2BC: nop

L_801DF2C0:
    // 0x801DF2C0: lw          $a0, 0xBC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XBC);
    // 0x801DF2C4: jal         0x801DCD3C
    // 0x801DF2C8: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    func_801DCD3C_0BA450(rdram, ctx);
        goto after_27;
    // 0x801DF2C8: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    after_27:
    // 0x801DF2CC: b           L_801DF8E4
    // 0x801DF2D0: nop

        goto L_801DF8E4;
    // 0x801DF2D0: nop

L_801DF2D4:
    // 0x801DF2D4: lw          $t1, 0xBC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XBC);
    // 0x801DF2D8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x801DF2DC: sll         $t4, $t1, 2
    ctx->r12 = S32(ctx->r9 << 2);
    // 0x801DF2E0: addu        $t4, $t4, $t1
    ctx->r12 = ADD32(ctx->r12, ctx->r9);
    // 0x801DF2E4: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x801DF2E8: subu        $t4, $t4, $t1
    ctx->r12 = SUB32(ctx->r12, ctx->r9);
    // 0x801DF2EC: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x801DF2F0: addu        $t4, $t4, $t1
    ctx->r12 = ADD32(ctx->r12, ctx->r9);
    // 0x801DF2F4: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x801DF2F8: addu        $t3, $t3, $t4
    ctx->r11 = ADD32(ctx->r11, ctx->r12);
    // 0x801DF2FC: lhu         $t3, -0x2A28($t3)
    ctx->r11 = MEM_HU(ctx->r11, -0X2A28);
    // 0x801DF300: andi        $t5, $t3, 0x8000
    ctx->r13 = ctx->r11 & 0X8000;
    // 0x801DF304: beq         $t5, $zero, L_801DF8EC
    if (ctx->r13 == 0) {
        // 0x801DF308: nop
    
            goto L_801DF8EC;
    }
    // 0x801DF308: nop

    // 0x801DF30C: lui         $a1, 0x3E19
    ctx->r5 = S32(0X3E19 << 16);
    // 0x801DF310: lui         $a2, 0x3E05
    ctx->r6 = S32(0X3E05 << 16);
    // 0x801DF314: addiu       $t6, $zero, 0xE6
    ctx->r14 = ADD32(0, 0XE6);
    // 0x801DF318: addiu       $t9, $zero, 0xE6
    ctx->r25 = ADD32(0, 0XE6);
    // 0x801DF31C: addiu       $t7, $zero, 0xE6
    ctx->r15 = ADD32(0, 0XE6);
    // 0x801DF320: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x801DF324: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x801DF328: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x801DF32C: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x801DF330: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x801DF334: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x801DF338: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801DF33C: ori         $a2, $a2, 0x1EB8
    ctx->r6 = ctx->r6 | 0X1EB8;
    // 0x801DF340: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x801DF344: lw          $a0, 0xBC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XBC);
    // 0x801DF348: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x801DF34C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x801DF350: jal         0x801DD5B0
    // 0x801DF354: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    func_801DD5B0_0BA450(rdram, ctx);
        goto after_28;
    // 0x801DF354: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_28:
    // 0x801DF358: b           L_801DF8E4
    // 0x801DF35C: nop

        goto L_801DF8E4;
    // 0x801DF35C: nop

L_801DF360:
    // 0x801DF360: lw          $t0, 0xBC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XBC);
    // 0x801DF364: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x801DF368: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x801DF36C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x801DF370: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x801DF374: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x801DF378: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x801DF37C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x801DF380: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x801DF384: addu        $t4, $t4, $t1
    ctx->r12 = ADD32(ctx->r12, ctx->r9);
    // 0x801DF388: lhu         $t4, -0x2A28($t4)
    ctx->r12 = MEM_HU(ctx->r12, -0X2A28);
    // 0x801DF38C: andi        $t3, $t4, 0x8000
    ctx->r11 = ctx->r12 & 0X8000;
    // 0x801DF390: beq         $t3, $zero, L_801DF8EC
    if (ctx->r11 == 0) {
        // 0x801DF394: nop
    
            goto L_801DF8EC;
    }
    // 0x801DF394: nop

    // 0x801DF398: lui         $a1, 0x3E8F
    ctx->r5 = S32(0X3E8F << 16);
    // 0x801DF39C: lui         $a2, 0x3E85
    ctx->r6 = S32(0X3E85 << 16);
    // 0x801DF3A0: addiu       $t5, $zero, 0xE6
    ctx->r13 = ADD32(0, 0XE6);
    // 0x801DF3A4: addiu       $t6, $zero, 0xE6
    ctx->r14 = ADD32(0, 0XE6);
    // 0x801DF3A8: addiu       $t9, $zero, 0xE6
    ctx->r25 = ADD32(0, 0XE6);
    // 0x801DF3AC: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x801DF3B0: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x801DF3B4: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x801DF3B8: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x801DF3BC: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x801DF3C0: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x801DF3C4: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x801DF3C8: ori         $a2, $a2, 0x1EB8
    ctx->r6 = ctx->r6 | 0X1EB8;
    // 0x801DF3CC: ori         $a1, $a1, 0x5C29
    ctx->r5 = ctx->r5 | 0X5C29;
    // 0x801DF3D0: lw          $a0, 0xBC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XBC);
    // 0x801DF3D4: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x801DF3D8: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x801DF3DC: jal         0x801DD7D8
    // 0x801DF3E0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    func_801DD7D8_0BA450(rdram, ctx);
        goto after_29;
    // 0x801DF3E0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_29:
    // 0x801DF3E4: b           L_801DF8E4
    // 0x801DF3E8: nop

        goto L_801DF8E4;
    // 0x801DF3E8: nop

L_801DF3EC:
    // 0x801DF3EC: lw          $t2, 0xBC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XBC);
    // 0x801DF3F0: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x801DF3F4: sll         $t0, $t2, 2
    ctx->r8 = S32(ctx->r10 << 2);
    // 0x801DF3F8: addu        $t0, $t0, $t2
    ctx->r8 = ADD32(ctx->r8, ctx->r10);
    // 0x801DF3FC: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x801DF400: subu        $t0, $t0, $t2
    ctx->r8 = SUB32(ctx->r8, ctx->r10);
    // 0x801DF404: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x801DF408: addu        $t0, $t0, $t2
    ctx->r8 = ADD32(ctx->r8, ctx->r10);
    // 0x801DF40C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x801DF410: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x801DF414: lhu         $t1, -0x2A28($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X2A28);
    // 0x801DF418: andi        $t4, $t1, 0x8000
    ctx->r12 = ctx->r9 & 0X8000;
    // 0x801DF41C: beq         $t4, $zero, L_801DF8EC
    if (ctx->r12 == 0) {
        // 0x801DF420: nop
    
            goto L_801DF8EC;
    }
    // 0x801DF420: nop

    // 0x801DF424: lui         $a1, 0x3ECC
    ctx->r5 = S32(0X3ECC << 16);
    // 0x801DF428: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x801DF42C: addiu       $t3, $zero, 0xE6
    ctx->r11 = ADD32(0, 0XE6);
    // 0x801DF430: addiu       $t5, $zero, 0xE6
    ctx->r13 = ADD32(0, 0XE6);
    // 0x801DF434: addiu       $t6, $zero, 0xE6
    ctx->r14 = ADD32(0, 0XE6);
    // 0x801DF438: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x801DF43C: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x801DF440: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x801DF444: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x801DF448: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x801DF44C: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x801DF450: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x801DF454: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x801DF458: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x801DF45C: lw          $a0, 0xBC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XBC);
    // 0x801DF460: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x801DF464: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x801DF468: jal         0x801DD5B0
    // 0x801DF46C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    func_801DD5B0_0BA450(rdram, ctx);
        goto after_30;
    // 0x801DF46C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_30:
    // 0x801DF470: b           L_801DF8E4
    // 0x801DF474: nop

        goto L_801DF8E4;
    // 0x801DF474: nop

L_801DF478:
    // 0x801DF478: lw          $t8, 0xBC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XBC);
    // 0x801DF47C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x801DF480: addiu       $t0, $t0, -0x2A28
    ctx->r8 = ADD32(ctx->r8, -0X2A28);
    // 0x801DF484: sll         $t2, $t8, 2
    ctx->r10 = S32(ctx->r24 << 2);
    // 0x801DF488: addu        $t2, $t2, $t8
    ctx->r10 = ADD32(ctx->r10, ctx->r24);
    // 0x801DF48C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x801DF490: subu        $t2, $t2, $t8
    ctx->r10 = SUB32(ctx->r10, ctx->r24);
    // 0x801DF494: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x801DF498: addu        $t2, $t2, $t8
    ctx->r10 = ADD32(ctx->r10, ctx->r24);
    // 0x801DF49C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x801DF4A0: addu        $t1, $t2, $t0
    ctx->r9 = ADD32(ctx->r10, ctx->r8);
    // 0x801DF4A4: lhu         $t4, 0x0($t1)
    ctx->r12 = MEM_HU(ctx->r9, 0X0);
    // 0x801DF4A8: andi        $t3, $t4, 0x8000
    ctx->r11 = ctx->r12 & 0X8000;
    // 0x801DF4AC: bne         $t3, $zero, L_801DF4BC
    if (ctx->r11 != 0) {
        // 0x801DF4B0: nop
    
            goto L_801DF4BC;
    }
    // 0x801DF4B0: nop

    // 0x801DF4B4: b           L_801DF8EC
    // 0x801DF4B8: sw          $zero, 0x2C($t1)
    MEM_W(0X2C, ctx->r9) = 0;
        goto L_801DF8EC;
    // 0x801DF4B8: sw          $zero, 0x2C($t1)
    MEM_W(0X2C, ctx->r9) = 0;
L_801DF4BC:
    // 0x801DF4BC: lw          $t5, 0xBC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XBC);
    // 0x801DF4C0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801DF4C4: addiu       $t9, $t9, -0x2A28
    ctx->r25 = ADD32(ctx->r25, -0X2A28);
    // 0x801DF4C8: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x801DF4CC: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x801DF4D0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801DF4D4: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x801DF4D8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801DF4DC: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x801DF4E0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801DF4E4: addu        $t7, $t6, $t9
    ctx->r15 = ADD32(ctx->r14, ctx->r25);
    // 0x801DF4E8: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801DF4EC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x801DF4F0: addiu       $t2, $t8, 0x1
    ctx->r10 = ADD32(ctx->r24, 0X1);
    // 0x801DF4F4: sw          $t2, 0x2C($t7)
    MEM_W(0X2C, ctx->r15) = ctx->r10;
    // 0x801DF4F8: lw          $t0, 0xBC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XBC);
    // 0x801DF4FC: sll         $t4, $t0, 2
    ctx->r12 = S32(ctx->r8 << 2);
    // 0x801DF500: addu        $t4, $t4, $t0
    ctx->r12 = ADD32(ctx->r12, ctx->r8);
    // 0x801DF504: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x801DF508: subu        $t4, $t4, $t0
    ctx->r12 = SUB32(ctx->r12, ctx->r8);
    // 0x801DF50C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x801DF510: addu        $t4, $t4, $t0
    ctx->r12 = ADD32(ctx->r12, ctx->r8);
    // 0x801DF514: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x801DF518: addu        $t3, $t3, $t4
    ctx->r11 = ADD32(ctx->r11, ctx->r12);
    // 0x801DF51C: lw          $t3, -0x29FC($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X29FC);
    // 0x801DF520: sltiu       $at, $t3, 0x4
    ctx->r1 = ctx->r11 < 0X4 ? 1 : 0;
    // 0x801DF524: beq         $at, $zero, L_801DF59C
    if (ctx->r1 == 0) {
        // 0x801DF528: nop
    
            goto L_801DF59C;
    }
    // 0x801DF528: nop

    // 0x801DF52C: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x801DF530: lw          $t1, -0x4514($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4514);
    // 0x801DF534: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x801DF538: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x801DF53C: sw          $t1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r9;
    // 0x801DF540: lw          $t9, 0x7C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X7C);
    // 0x801DF544: addiu       $t5, $t1, 0x8
    ctx->r13 = ADD32(ctx->r9, 0X8);
    // 0x801DF548: sw          $t5, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r13;
    // 0x801DF54C: sw          $t6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r14;
    // 0x801DF550: lw          $t8, 0xBC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XBC);
    // 0x801DF554: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801DF558: lui         $at, 0xFFFA
    ctx->r1 = S32(0XFFFA << 16);
    // 0x801DF55C: sll         $t2, $t8, 2
    ctx->r10 = S32(ctx->r24 << 2);
    // 0x801DF560: addu        $t2, $t2, $t8
    ctx->r10 = ADD32(ctx->r10, ctx->r24);
    // 0x801DF564: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x801DF568: subu        $t2, $t2, $t8
    ctx->r10 = SUB32(ctx->r10, ctx->r24);
    // 0x801DF56C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x801DF570: addu        $t2, $t2, $t8
    ctx->r10 = ADD32(ctx->r10, ctx->r24);
    // 0x801DF574: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x801DF578: addu        $t7, $t7, $t2
    ctx->r15 = ADD32(ctx->r15, ctx->r10);
    // 0x801DF57C: lw          $t7, -0x29FC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X29FC);
    // 0x801DF580: lw          $t1, 0x7C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X7C);
    // 0x801DF584: ori         $at, $at, 0xFA00
    ctx->r1 = ctx->r1 | 0XFA00;
    // 0x801DF588: sll         $t0, $t7, 6
    ctx->r8 = S32(ctx->r15 << 6);
    // 0x801DF58C: andi        $t4, $t0, 0xFF
    ctx->r12 = ctx->r8 & 0XFF;
    // 0x801DF590: or          $t3, $t4, $at
    ctx->r11 = ctx->r12 | ctx->r1;
    // 0x801DF594: b           L_801DF5D0
    // 0x801DF598: sw          $t3, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r11;
        goto L_801DF5D0;
    // 0x801DF598: sw          $t3, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r11;
L_801DF59C:
    // 0x801DF59C: lui         $t5, 0x8011
    ctx->r13 = S32(0X8011 << 16);
    // 0x801DF5A0: lw          $t5, -0x4514($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4514);
    // 0x801DF5A4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x801DF5A8: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x801DF5AC: sw          $t5, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r13;
    // 0x801DF5B0: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
    // 0x801DF5B4: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x801DF5B8: sw          $t6, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r14;
    // 0x801DF5BC: sw          $t9, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r25;
    // 0x801DF5C0: lw          $t7, 0x78($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X78);
    // 0x801DF5C4: lui         $t2, 0xFFFA
    ctx->r10 = S32(0XFFFA << 16);
    // 0x801DF5C8: ori         $t2, $t2, 0xFAFF
    ctx->r10 = ctx->r10 | 0XFAFF;
    // 0x801DF5CC: sw          $t2, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r10;
L_801DF5D0:
    // 0x801DF5D0: lui         $a1, 0x3D8F
    ctx->r5 = S32(0X3D8F << 16);
    // 0x801DF5D4: ori         $a1, $a1, 0x5C29
    ctx->r5 = ctx->r5 | 0X5C29;
    // 0x801DF5D8: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x801DF5DC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801DF5E0: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // 0x801DF5E4: jal         0x801DD9EC
    // 0x801DF5E8: lw          $a0, 0xBC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XBC);
    func_801DD9EC_0BA450(rdram, ctx);
        goto after_31;
    // 0x801DF5E8: lw          $a0, 0xBC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XBC);
    after_31:
    // 0x801DF5EC: b           L_801DF8E4
    // 0x801DF5F0: nop

        goto L_801DF8E4;
    // 0x801DF5F0: nop

L_801DF5F4:
    // 0x801DF5F4: lw          $t0, 0xBC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XBC);
    // 0x801DF5F8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x801DF5FC: addiu       $t3, $t3, -0x2A28
    ctx->r11 = ADD32(ctx->r11, -0X2A28);
    // 0x801DF600: sll         $t4, $t0, 2
    ctx->r12 = S32(ctx->r8 << 2);
    // 0x801DF604: addu        $t4, $t4, $t0
    ctx->r12 = ADD32(ctx->r12, ctx->r8);
    // 0x801DF608: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x801DF60C: subu        $t4, $t4, $t0
    ctx->r12 = SUB32(ctx->r12, ctx->r8);
    // 0x801DF610: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x801DF614: addu        $t4, $t4, $t0
    ctx->r12 = ADD32(ctx->r12, ctx->r8);
    // 0x801DF618: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x801DF61C: addu        $t1, $t4, $t3
    ctx->r9 = ADD32(ctx->r12, ctx->r11);
    // 0x801DF620: lhu         $t5, 0x0($t1)
    ctx->r13 = MEM_HU(ctx->r9, 0X0);
    // 0x801DF624: andi        $t6, $t5, 0x8000
    ctx->r14 = ctx->r13 & 0X8000;
    // 0x801DF628: bne         $t6, $zero, L_801DF638
    if (ctx->r14 != 0) {
        // 0x801DF62C: nop
    
            goto L_801DF638;
    }
    // 0x801DF62C: nop

    // 0x801DF630: b           L_801DF8EC
    // 0x801DF634: sw          $zero, 0x2C($t1)
    MEM_W(0X2C, ctx->r9) = 0;
        goto L_801DF8EC;
    // 0x801DF634: sw          $zero, 0x2C($t1)
    MEM_W(0X2C, ctx->r9) = 0;
L_801DF638:
    // 0x801DF638: lw          $t9, 0xBC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XBC);
    // 0x801DF63C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x801DF640: addiu       $t2, $t2, -0x2A28
    ctx->r10 = ADD32(ctx->r10, -0X2A28);
    // 0x801DF644: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x801DF648: addu        $t8, $t8, $t9
    ctx->r24 = ADD32(ctx->r24, ctx->r25);
    // 0x801DF64C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x801DF650: subu        $t8, $t8, $t9
    ctx->r24 = SUB32(ctx->r24, ctx->r25);
    // 0x801DF654: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x801DF658: addu        $t8, $t8, $t9
    ctx->r24 = ADD32(ctx->r24, ctx->r25);
    // 0x801DF65C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x801DF660: addu        $t7, $t8, $t2
    ctx->r15 = ADD32(ctx->r24, ctx->r10);
    // 0x801DF664: lw          $t0, 0x2C($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X2C);
    // 0x801DF668: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801DF66C: addiu       $t4, $t0, 0x1
    ctx->r12 = ADD32(ctx->r8, 0X1);
    // 0x801DF670: sw          $t4, 0x2C($t7)
    MEM_W(0X2C, ctx->r15) = ctx->r12;
    // 0x801DF674: lw          $t3, 0xBC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XBC);
    // 0x801DF678: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x801DF67C: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x801DF680: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x801DF684: subu        $t5, $t5, $t3
    ctx->r13 = SUB32(ctx->r13, ctx->r11);
    // 0x801DF688: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x801DF68C: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x801DF690: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x801DF694: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x801DF698: lw          $t6, -0x29FC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X29FC);
    // 0x801DF69C: sltiu       $at, $t6, 0x4
    ctx->r1 = ctx->r14 < 0X4 ? 1 : 0;
    // 0x801DF6A0: beq         $at, $zero, L_801DF718
    if (ctx->r1 == 0) {
        // 0x801DF6A4: nop
    
            goto L_801DF718;
    }
    // 0x801DF6A4: nop

    // 0x801DF6A8: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x801DF6AC: lw          $t1, -0x4514($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4514);
    // 0x801DF6B0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x801DF6B4: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x801DF6B8: sw          $t1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r9;
    // 0x801DF6BC: lw          $t2, 0x74($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X74);
    // 0x801DF6C0: addiu       $t9, $t1, 0x8
    ctx->r25 = ADD32(ctx->r9, 0X8);
    // 0x801DF6C4: sw          $t9, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r25;
    // 0x801DF6C8: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
    // 0x801DF6CC: lw          $t0, 0xBC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XBC);
    // 0x801DF6D0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801DF6D4: lui         $at, 0xFFFA
    ctx->r1 = S32(0XFFFA << 16);
    // 0x801DF6D8: sll         $t4, $t0, 2
    ctx->r12 = S32(ctx->r8 << 2);
    // 0x801DF6DC: addu        $t4, $t4, $t0
    ctx->r12 = ADD32(ctx->r12, ctx->r8);
    // 0x801DF6E0: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x801DF6E4: subu        $t4, $t4, $t0
    ctx->r12 = SUB32(ctx->r12, ctx->r8);
    // 0x801DF6E8: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x801DF6EC: addu        $t4, $t4, $t0
    ctx->r12 = ADD32(ctx->r12, ctx->r8);
    // 0x801DF6F0: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x801DF6F4: addu        $t7, $t7, $t4
    ctx->r15 = ADD32(ctx->r15, ctx->r12);
    // 0x801DF6F8: lw          $t7, -0x29FC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X29FC);
    // 0x801DF6FC: lw          $t1, 0x74($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X74);
    // 0x801DF700: ori         $at, $at, 0xFA00
    ctx->r1 = ctx->r1 | 0XFA00;
    // 0x801DF704: sll         $t3, $t7, 6
    ctx->r11 = S32(ctx->r15 << 6);
    // 0x801DF708: andi        $t5, $t3, 0xFF
    ctx->r13 = ctx->r11 & 0XFF;
    // 0x801DF70C: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x801DF710: b           L_801DF74C
    // 0x801DF714: sw          $t6, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r14;
        goto L_801DF74C;
    // 0x801DF714: sw          $t6, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r14;
L_801DF718:
    // 0x801DF718: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x801DF71C: lw          $t9, -0x4514($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4514);
    // 0x801DF720: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x801DF724: lui         $t2, 0xFA00
    ctx->r10 = S32(0XFA00 << 16);
    // 0x801DF728: sw          $t9, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r25;
    // 0x801DF72C: lw          $t0, 0x70($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X70);
    // 0x801DF730: addiu       $t8, $t9, 0x8
    ctx->r24 = ADD32(ctx->r25, 0X8);
    // 0x801DF734: sw          $t8, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r24;
    // 0x801DF738: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x801DF73C: lw          $t7, 0x70($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X70);
    // 0x801DF740: lui         $t4, 0xFFFA
    ctx->r12 = S32(0XFFFA << 16);
    // 0x801DF744: ori         $t4, $t4, 0xFAFF
    ctx->r12 = ctx->r12 | 0XFAFF;
    // 0x801DF748: sw          $t4, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r12;
L_801DF74C:
    // 0x801DF74C: lui         $a1, 0x3CA3
    ctx->r5 = S32(0X3CA3 << 16);
    // 0x801DF750: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    // 0x801DF754: lui         $a2, 0x3CF5
    ctx->r6 = S32(0X3CF5 << 16);
    // 0x801DF758: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x801DF75C: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // 0x801DF760: jal         0x801DD9EC
    // 0x801DF764: lw          $a0, 0xBC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XBC);
    func_801DD9EC_0BA450(rdram, ctx);
        goto after_32;
    // 0x801DF764: lw          $a0, 0xBC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XBC);
    after_32:
    // 0x801DF768: b           L_801DF8E4
    // 0x801DF76C: nop

        goto L_801DF8E4;
    // 0x801DF76C: nop

L_801DF770:
    // 0x801DF770: lw          $t3, 0xBC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XBC);
    // 0x801DF774: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801DF778: addiu       $t6, $t6, -0x2A28
    ctx->r14 = ADD32(ctx->r14, -0X2A28);
    // 0x801DF77C: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x801DF780: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x801DF784: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x801DF788: subu        $t5, $t5, $t3
    ctx->r13 = SUB32(ctx->r13, ctx->r11);
    // 0x801DF78C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x801DF790: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x801DF794: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x801DF798: addu        $t1, $t5, $t6
    ctx->r9 = ADD32(ctx->r13, ctx->r14);
    // 0x801DF79C: lhu         $t9, 0x0($t1)
    ctx->r25 = MEM_HU(ctx->r9, 0X0);
    // 0x801DF7A0: andi        $t8, $t9, 0x8000
    ctx->r24 = ctx->r25 & 0X8000;
    // 0x801DF7A4: bne         $t8, $zero, L_801DF7B4
    if (ctx->r24 != 0) {
        // 0x801DF7A8: nop
    
            goto L_801DF7B4;
    }
    // 0x801DF7A8: nop

    // 0x801DF7AC: b           L_801DF8EC
    // 0x801DF7B0: sw          $zero, 0x2C($t1)
    MEM_W(0X2C, ctx->r9) = 0;
        goto L_801DF8EC;
    // 0x801DF7B0: sw          $zero, 0x2C($t1)
    MEM_W(0X2C, ctx->r9) = 0;
L_801DF7B4:
    // 0x801DF7B4: lw          $t2, 0xBC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XBC);
    // 0x801DF7B8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x801DF7BC: addiu       $t4, $t4, -0x2A28
    ctx->r12 = ADD32(ctx->r12, -0X2A28);
    // 0x801DF7C0: sll         $t0, $t2, 2
    ctx->r8 = S32(ctx->r10 << 2);
    // 0x801DF7C4: addu        $t0, $t0, $t2
    ctx->r8 = ADD32(ctx->r8, ctx->r10);
    // 0x801DF7C8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x801DF7CC: subu        $t0, $t0, $t2
    ctx->r8 = SUB32(ctx->r8, ctx->r10);
    // 0x801DF7D0: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x801DF7D4: addu        $t0, $t0, $t2
    ctx->r8 = ADD32(ctx->r8, ctx->r10);
    // 0x801DF7D8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x801DF7DC: addu        $t7, $t0, $t4
    ctx->r15 = ADD32(ctx->r8, ctx->r12);
    // 0x801DF7E0: lw          $t3, 0x2C($t7)
    ctx->r11 = MEM_W(ctx->r15, 0X2C);
    // 0x801DF7E4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x801DF7E8: addiu       $t5, $t3, 0x1
    ctx->r13 = ADD32(ctx->r11, 0X1);
    // 0x801DF7EC: sw          $t5, 0x2C($t7)
    MEM_W(0X2C, ctx->r15) = ctx->r13;
    // 0x801DF7F0: lw          $t6, 0xBC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XBC);
    // 0x801DF7F4: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x801DF7F8: addu        $t9, $t9, $t6
    ctx->r25 = ADD32(ctx->r25, ctx->r14);
    // 0x801DF7FC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x801DF800: subu        $t9, $t9, $t6
    ctx->r25 = SUB32(ctx->r25, ctx->r14);
    // 0x801DF804: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x801DF808: addu        $t9, $t9, $t6
    ctx->r25 = ADD32(ctx->r25, ctx->r14);
    // 0x801DF80C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x801DF810: addu        $t8, $t8, $t9
    ctx->r24 = ADD32(ctx->r24, ctx->r25);
    // 0x801DF814: lw          $t8, -0x29FC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X29FC);
    // 0x801DF818: sltiu       $at, $t8, 0x4
    ctx->r1 = ctx->r24 < 0X4 ? 1 : 0;
    // 0x801DF81C: beq         $at, $zero, L_801DF894
    if (ctx->r1 == 0) {
        // 0x801DF820: nop
    
            goto L_801DF894;
    }
    // 0x801DF820: nop

    // 0x801DF824: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x801DF828: lw          $t1, -0x4514($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4514);
    // 0x801DF82C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x801DF830: lui         $t0, 0xFA00
    ctx->r8 = S32(0XFA00 << 16);
    // 0x801DF834: sw          $t1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r9;
    // 0x801DF838: lw          $t4, 0x6C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X6C);
    // 0x801DF83C: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x801DF840: sw          $t2, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r10;
    // 0x801DF844: sw          $t0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r8;
    // 0x801DF848: lw          $t3, 0xBC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XBC);
    // 0x801DF84C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801DF850: lui         $at, 0xFFFA
    ctx->r1 = S32(0XFFFA << 16);
    // 0x801DF854: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x801DF858: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x801DF85C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x801DF860: subu        $t5, $t5, $t3
    ctx->r13 = SUB32(ctx->r13, ctx->r11);
    // 0x801DF864: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x801DF868: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x801DF86C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x801DF870: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x801DF874: lw          $t7, -0x29FC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X29FC);
    // 0x801DF878: lw          $t1, 0x6C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X6C);
    // 0x801DF87C: ori         $at, $at, 0xFA00
    ctx->r1 = ctx->r1 | 0XFA00;
    // 0x801DF880: sll         $t6, $t7, 6
    ctx->r14 = S32(ctx->r15 << 6);
    // 0x801DF884: andi        $t9, $t6, 0xFF
    ctx->r25 = ctx->r14 & 0XFF;
    // 0x801DF888: or          $t8, $t9, $at
    ctx->r24 = ctx->r25 | ctx->r1;
    // 0x801DF88C: b           L_801DF8C8
    // 0x801DF890: sw          $t8, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r24;
        goto L_801DF8C8;
    // 0x801DF890: sw          $t8, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r24;
L_801DF894:
    // 0x801DF894: lui         $t2, 0x8011
    ctx->r10 = S32(0X8011 << 16);
    // 0x801DF898: lw          $t2, -0x4514($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4514);
    // 0x801DF89C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x801DF8A0: lui         $t4, 0xFA00
    ctx->r12 = S32(0XFA00 << 16);
    // 0x801DF8A4: sw          $t2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r10;
    // 0x801DF8A8: lw          $t3, 0x68($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X68);
    // 0x801DF8AC: addiu       $t0, $t2, 0x8
    ctx->r8 = ADD32(ctx->r10, 0X8);
    // 0x801DF8B0: sw          $t0, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r8;
    // 0x801DF8B4: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    // 0x801DF8B8: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x801DF8BC: lui         $t5, 0xFFFA
    ctx->r13 = S32(0XFFFA << 16);
    // 0x801DF8C0: ori         $t5, $t5, 0xFAFF
    ctx->r13 = ctx->r13 | 0XFAFF;
    // 0x801DF8C4: sw          $t5, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r13;
L_801DF8C8:
    // 0x801DF8C8: lui         $a1, 0x3CA3
    ctx->r5 = S32(0X3CA3 << 16);
    // 0x801DF8CC: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    // 0x801DF8D0: lui         $a2, 0x3CF5
    ctx->r6 = S32(0X3CF5 << 16);
    // 0x801DF8D4: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x801DF8D8: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // 0x801DF8DC: jal         0x801DD9EC
    // 0x801DF8E0: lw          $a0, 0xBC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XBC);
    func_801DD9EC_0BA450(rdram, ctx);
        goto after_33;
    // 0x801DF8E0: lw          $a0, 0xBC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XBC);
    after_33:
L_801DF8E4:
    // 0x801DF8E4: jal         0x801DCC7C
    // 0x801DF8E8: nop

    func_801DCC7C_0BA450(rdram, ctx);
        goto after_34;
    // 0x801DF8E8: nop

    after_34:
L_801DF8EC:
    // 0x801DF8EC: lw          $t6, 0xBC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XBC);
    // 0x801DF8F0: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x801DF8F4: slti        $at, $t9, 0x30
    ctx->r1 = SIGNED(ctx->r25) < 0X30 ? 1 : 0;
    // 0x801DF8F8: bne         $at, $zero, L_801DDB88
    if (ctx->r1 != 0) {
        // 0x801DF8FC: sw          $t9, 0xBC($sp)
        MEM_W(0XBC, ctx->r29) = ctx->r25;
            goto L_801DDB88;
    }
    // 0x801DF8FC: sw          $t9, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r25;
    // 0x801DF900: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x801DF904: lw          $t8, -0x2E34($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2E34);
    // 0x801DF908: sltiu       $at, $t8, 0x6D
    ctx->r1 = ctx->r24 < 0X6D ? 1 : 0;
    // 0x801DF90C: beq         $at, $zero, L_801E0230
    if (ctx->r1 == 0) {
        // 0x801DF910: nop
    
            goto L_801E0230;
    }
    // 0x801DF910: nop

    // 0x801DF914: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x801DF918: lw          $t1, -0x4514($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4514);
    // 0x801DF91C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x801DF920: lui         $t0, 0xE700
    ctx->r8 = S32(0XE700 << 16);
    // 0x801DF924: sw          $t1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r9;
    // 0x801DF928: lw          $t4, 0x64($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X64);
    // 0x801DF92C: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x801DF930: sw          $t2, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r10;
    // 0x801DF934: sw          $t0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r8;
    // 0x801DF938: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x801DF93C: lui         $t5, 0x8011
    ctx->r13 = S32(0X8011 << 16);
    // 0x801DF940: lui         $t6, 0xE200
    ctx->r14 = S32(0XE200 << 16);
    // 0x801DF944: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x801DF948: lw          $t5, -0x4514($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4514);
    // 0x801DF94C: ori         $t6, $t6, 0x1C
    ctx->r14 = ctx->r14 | 0X1C;
    // 0x801DF950: lui         $t8, 0x40
    ctx->r24 = S32(0X40 << 16);
    // 0x801DF954: sw          $t5, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r13;
    // 0x801DF958: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x801DF95C: addiu       $t7, $t5, 0x8
    ctx->r15 = ADD32(ctx->r13, 0X8);
    // 0x801DF960: sw          $t7, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r15;
    // 0x801DF964: sw          $t6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r14;
    // 0x801DF968: lw          $t1, 0x60($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X60);
    // 0x801DF96C: ori         $t8, $t8, 0x49D8
    ctx->r24 = ctx->r24 | 0X49D8;
    // 0x801DF970: lui         $t2, 0x8011
    ctx->r10 = S32(0X8011 << 16);
    // 0x801DF974: sw          $t8, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r24;
    // 0x801DF978: lw          $t2, -0x4514($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4514);
    // 0x801DF97C: lui         $t4, 0xFC11
    ctx->r12 = S32(0XFC11 << 16);
    // 0x801DF980: ori         $t4, $t4, 0x9623
    ctx->r12 = ctx->r12 | 0X9623;
    // 0x801DF984: sw          $t2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r10;
    // 0x801DF988: lw          $t3, 0x5C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X5C);
    // 0x801DF98C: addiu       $t0, $t2, 0x8
    ctx->r8 = ADD32(ctx->r10, 0X8);
    // 0x801DF990: sw          $t0, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r8;
    // 0x801DF994: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    // 0x801DF998: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x801DF99C: lui         $t5, 0xFF2F
    ctx->r13 = S32(0XFF2F << 16);
    // 0x801DF9A0: ori         $t5, $t5, 0xFFFF
    ctx->r13 = ctx->r13 | 0XFFFF;
    // 0x801DF9A4: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x801DF9A8: sw          $t5, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r13;
    // 0x801DF9AC: lw          $t6, -0x4514($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4514);
    // 0x801DF9B0: lui         $t8, 0xE300
    ctx->r24 = S32(0XE300 << 16);
    // 0x801DF9B4: ori         $t8, $t8, 0x1001
    ctx->r24 = ctx->r24 | 0X1001;
    // 0x801DF9B8: sw          $t6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r14;
    // 0x801DF9BC: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x801DF9C0: addiu       $t9, $t6, 0x8
    ctx->r25 = ADD32(ctx->r14, 0X8);
    // 0x801DF9C4: sw          $t9, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r25;
    // 0x801DF9C8: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x801DF9CC: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x801DF9D0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x801DF9D4: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x801DF9D8: lw          $t0, -0x2E34($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2E34);
    // 0x801DF9DC: sltiu       $at, $t0, 0xB
    ctx->r1 = ctx->r8 < 0XB ? 1 : 0;
    // 0x801DF9E0: beq         $at, $zero, L_801DF9FC
    if (ctx->r1 == 0) {
        // 0x801DF9E4: nop
    
            goto L_801DF9FC;
    }
    // 0x801DF9E4: nop

    // 0x801DF9E8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801DF9EC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x801DF9F0: addiu       $t4, $t4, -0x2D90
    ctx->r12 = ADD32(ctx->r12, -0X2D90);
    // 0x801DF9F4: b           L_801DFA74
    // 0x801DF9F8: swc1        $f16, 0x14($t4)
    MEM_W(0X14, ctx->r12) = ctx->f16.u32l;
        goto L_801DFA74;
    // 0x801DF9F8: swc1        $f16, 0x14($t4)
    MEM_W(0X14, ctx->r12) = ctx->f16.u32l;
L_801DF9FC:
    // 0x801DF9FC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x801DFA00: lw          $t3, -0x2E34($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2E34);
    // 0x801DFA04: sltiu       $at, $t3, 0x2F
    ctx->r1 = ctx->r11 < 0X2F ? 1 : 0;
    // 0x801DFA08: beq         $at, $zero, L_801DFA30
    if (ctx->r1 == 0) {
        // 0x801DFA0C: nop
    
            goto L_801DFA30;
    }
    // 0x801DFA0C: nop

    // 0x801DFA10: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x801DFA14: addiu       $t5, $t5, -0x2D90
    ctx->r13 = ADD32(ctx->r13, -0X2D90);
    // 0x801DFA18: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DFA1C: lwc1        $f4, 0x7D88($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7D88);
    // 0x801DFA20: lwc1        $f18, 0x14($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X14);
    // 0x801DFA24: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801DFA28: b           L_801DFA74
    // 0x801DFA2C: swc1        $f6, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->f6.u32l;
        goto L_801DFA74;
    // 0x801DFA2C: swc1        $f6, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->f6.u32l;
L_801DFA30:
    // 0x801DFA30: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801DFA34: lw          $t7, -0x2E34($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2E34);
    // 0x801DFA38: addiu       $at, $zero, 0x2F
    ctx->r1 = ADD32(0, 0X2F);
    // 0x801DFA3C: bne         $t7, $at, L_801DFA58
    if (ctx->r15 != ctx->r1) {
        // 0x801DFA40: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_801DFA58;
    }
    // 0x801DFA40: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801DFA44: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801DFA48: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801DFA4C: addiu       $t6, $t6, -0x2D90
    ctx->r14 = ADD32(ctx->r14, -0X2D90);
    // 0x801DFA50: b           L_801DFA74
    // 0x801DFA54: swc1        $f8, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->f8.u32l;
        goto L_801DFA74;
    // 0x801DFA54: swc1        $f8, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->f8.u32l;
L_801DFA58:
    // 0x801DFA58: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801DFA5C: addiu       $t9, $t9, -0x2D90
    ctx->r25 = ADD32(ctx->r25, -0X2D90);
    // 0x801DFA60: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DFA64: lwc1        $f16, 0x7D8C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7D8C);
    // 0x801DFA68: lwc1        $f10, 0x14($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X14);
    // 0x801DFA6C: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x801DFA70: swc1        $f18, 0x14($t9)
    MEM_W(0X14, ctx->r25) = ctx->f18.u32l;
L_801DFA74:
    // 0x801DFA74: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x801DFA78: lw          $t8, -0x4514($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4514);
    // 0x801DFA7C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x801DFA80: lui         $t2, 0xFA00
    ctx->r10 = S32(0XFA00 << 16);
    // 0x801DFA84: sw          $t8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r24;
    // 0x801DFA88: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x801DFA8C: addiu       $t1, $t8, 0x8
    ctx->r9 = ADD32(ctx->r24, 0X8);
    // 0x801DFA90: sw          $t1, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r9;
    // 0x801DFA94: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x801DFA98: addiu       $t4, $t4, -0x2D90
    ctx->r12 = ADD32(ctx->r12, -0X2D90);
    // 0x801DFA9C: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x801DFAA0: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x801DFAA4: lwc1        $f4, 0x14($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X14);
    // 0x801DFAA8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801DFAAC: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x801DFAB0: lui         $at, 0xC8FF
    ctx->r1 = S32(0XC8FF << 16);
    // 0x801DFAB4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801DFAB8: ori         $at, $at, 0xC800
    ctx->r1 = ctx->r1 | 0XC800;
    // 0x801DFABC: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x801DFAC0: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x801DFAC4: nop

    // 0x801DFAC8: sll         $t7, $t5, 16
    ctx->r15 = S32(ctx->r13 << 16);
    // 0x801DFACC: sra         $t6, $t7, 16
    ctx->r14 = S32(SIGNED(ctx->r15) >> 16);
    // 0x801DFAD0: andi        $t9, $t6, 0xFF
    ctx->r25 = ctx->r14 & 0XFF;
    // 0x801DFAD4: or          $t8, $t9, $at
    ctx->r24 = ctx->r25 | ctx->r1;
    // 0x801DFAD8: sw          $t8, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r24;
    // 0x801DFADC: sw          $zero, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = 0;
L_801DFAE0:
    // 0x801DFAE0: lw          $t2, 0xBC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XBC);
    // 0x801DFAE4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x801DFAE8: addiu       $at, $zero, 0x800
    ctx->r1 = ADD32(0, 0X800);
    // 0x801DFAEC: sll         $t0, $t2, 2
    ctx->r8 = S32(ctx->r10 << 2);
    // 0x801DFAF0: addu        $t0, $t0, $t2
    ctx->r8 = ADD32(ctx->r8, ctx->r10);
    // 0x801DFAF4: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x801DFAF8: subu        $t0, $t0, $t2
    ctx->r8 = SUB32(ctx->r8, ctx->r10);
    // 0x801DFAFC: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x801DFB00: addu        $t0, $t0, $t2
    ctx->r8 = ADD32(ctx->r8, ctx->r10);
    // 0x801DFB04: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x801DFB08: addu        $t4, $t4, $t0
    ctx->r12 = ADD32(ctx->r12, ctx->r8);
    // 0x801DFB0C: lhu         $t4, -0x2A28($t4)
    ctx->r12 = MEM_HU(ctx->r12, -0X2A28);
    // 0x801DFB10: andi        $t3, $t4, 0x800
    ctx->r11 = ctx->r12 & 0X800;
    // 0x801DFB14: bne         $t3, $at, L_801DFBA4
    if (ctx->r11 != ctx->r1) {
        // 0x801DFB18: nop
    
            goto L_801DFBA4;
    }
    // 0x801DFB18: nop

    // 0x801DFB1C: lw          $t5, 0xBC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XBC);
    // 0x801DFB20: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801DFB24: addiu       $t6, $t6, -0x2A28
    ctx->r14 = ADD32(ctx->r14, -0X2A28);
    // 0x801DFB28: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x801DFB2C: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x801DFB30: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801DFB34: subu        $t7, $t7, $t5
    ctx->r15 = SUB32(ctx->r15, ctx->r13);
    // 0x801DFB38: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801DFB3C: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x801DFB40: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801DFB44: addu        $t9, $t7, $t6
    ctx->r25 = ADD32(ctx->r15, ctx->r14);
    // 0x801DFB48: lw          $t8, 0x4($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X4);
    // 0x801DFB4C: addiu       $at, $zero, 0x2A
    ctx->r1 = ADD32(0, 0X2A);
    // 0x801DFB50: bne         $t8, $at, L_801DFBA4
    if (ctx->r24 != ctx->r1) {
        // 0x801DFB54: nop
    
            goto L_801DFBA4;
    }
    // 0x801DFB54: nop

    // 0x801DFB58: lwc1        $f16, 0x64($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X64);
    // 0x801DFB5C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DFB60: lwc1        $f4, 0x7D90($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7D90);
    // 0x801DFB64: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DFB68: lw          $a3, 0x60($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X60);
    // 0x801DFB6C: lwc1        $f6, 0x7D94($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7D94);
    // 0x801DFB70: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x801DFB74: lwc1        $f18, 0x68($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X68);
    // 0x801DFB78: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DFB7C: lwc1        $f8, 0x7D98($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7D98);
    // 0x801DFB80: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x801DFB84: addiu       $a0, $a0, -0x76D8
    ctx->r4 = ADD32(ctx->r4, -0X76D8);
    // 0x801DFB88: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801DFB8C: addiu       $a2, $t9, 0xA4
    ctx->r6 = ADD32(ctx->r25, 0XA4);
    // 0x801DFB90: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x801DFB94: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x801DFB98: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x801DFB9C: jal         0x800C6868
    // 0x801DFBA0: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    func_800C6868(rdram, ctx);
        goto after_35;
    // 0x801DFBA0: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    after_35:
L_801DFBA4:
    // 0x801DFBA4: lw          $t1, 0xBC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XBC);
    // 0x801DFBA8: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x801DFBAC: slti        $at, $t2, 0x30
    ctx->r1 = SIGNED(ctx->r10) < 0X30 ? 1 : 0;
    // 0x801DFBB0: bne         $at, $zero, L_801DFAE0
    if (ctx->r1 != 0) {
        // 0x801DFBB4: sw          $t2, 0xBC($sp)
        MEM_W(0XBC, ctx->r29) = ctx->r10;
            goto L_801DFAE0;
    }
    // 0x801DFBB4: sw          $t2, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r10;
    // 0x801DFBB8: lui         $t0, 0x8011
    ctx->r8 = S32(0X8011 << 16);
    // 0x801DFBBC: lw          $t0, -0x4514($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X4514);
    // 0x801DFBC0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x801DFBC4: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x801DFBC8: sw          $t0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r8;
    // 0x801DFBCC: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x801DFBD0: addiu       $t4, $t0, 0x8
    ctx->r12 = ADD32(ctx->r8, 0X8);
    // 0x801DFBD4: sw          $t4, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r12;
    // 0x801DFBD8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801DFBDC: addiu       $t7, $t7, -0x2D90
    ctx->r15 = ADD32(ctx->r15, -0X2D90);
    // 0x801DFBE0: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x801DFBE4: sw          $t3, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r11;
    // 0x801DFBE8: lwc1        $f10, 0x14($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X14);
    // 0x801DFBEC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801DFBF0: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x801DFBF4: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x801DFBF8: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x801DFBFC: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x801DFC00: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x801DFC04: nop

    // 0x801DFC08: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x801DFC0C: sra         $t1, $t9, 16
    ctx->r9 = S32(SIGNED(ctx->r25) >> 16);
    // 0x801DFC10: andi        $t2, $t1, 0xFF
    ctx->r10 = ctx->r9 & 0XFF;
    // 0x801DFC14: or          $t0, $t2, $at
    ctx->r8 = ctx->r10 | ctx->r1;
    // 0x801DFC18: sw          $t0, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r8;
    // 0x801DFC1C: sw          $zero, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = 0;
L_801DFC20:
    // 0x801DFC20: lw          $t3, 0xBC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XBC);
    // 0x801DFC24: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801DFC28: addiu       $at, $zero, 0x800
    ctx->r1 = ADD32(0, 0X800);
    // 0x801DFC2C: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x801DFC30: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x801DFC34: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x801DFC38: subu        $t5, $t5, $t3
    ctx->r13 = SUB32(ctx->r13, ctx->r11);
    // 0x801DFC3C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x801DFC40: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x801DFC44: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x801DFC48: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x801DFC4C: lhu         $t7, -0x2A28($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X2A28);
    // 0x801DFC50: andi        $t6, $t7, 0x800
    ctx->r14 = ctx->r15 & 0X800;
    // 0x801DFC54: bne         $t6, $at, L_801DFCE4
    if (ctx->r14 != ctx->r1) {
        // 0x801DFC58: nop
    
            goto L_801DFCE4;
    }
    // 0x801DFC58: nop

    // 0x801DFC5C: lw          $t8, 0xBC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XBC);
    // 0x801DFC60: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x801DFC64: addiu       $t1, $t1, -0x2A28
    ctx->r9 = ADD32(ctx->r9, -0X2A28);
    // 0x801DFC68: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x801DFC6C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x801DFC70: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x801DFC74: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x801DFC78: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x801DFC7C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x801DFC80: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x801DFC84: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x801DFC88: lw          $t0, 0x4($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X4);
    // 0x801DFC8C: addiu       $at, $zero, 0x2D
    ctx->r1 = ADD32(0, 0X2D);
    // 0x801DFC90: bne         $t0, $at, L_801DFCE4
    if (ctx->r8 != ctx->r1) {
        // 0x801DFC94: nop
    
            goto L_801DFCE4;
    }
    // 0x801DFC94: nop

    // 0x801DFC98: lwc1        $f6, 0x64($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X64);
    // 0x801DFC9C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DFCA0: lwc1        $f10, 0x7D9C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7D9C);
    // 0x801DFCA4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DFCA8: lw          $a3, 0x60($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X60);
    // 0x801DFCAC: lwc1        $f16, 0x7DA0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7DA0);
    // 0x801DFCB0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x801DFCB4: lwc1        $f8, 0x68($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X68);
    // 0x801DFCB8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DFCBC: lwc1        $f18, 0x7DA4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7DA4);
    // 0x801DFCC0: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x801DFCC4: addiu       $a0, $a0, -0x75B8
    ctx->r4 = ADD32(ctx->r4, -0X75B8);
    // 0x801DFCC8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801DFCCC: addiu       $a2, $t2, 0xA4
    ctx->r6 = ADD32(ctx->r10, 0XA4);
    // 0x801DFCD0: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x801DFCD4: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    // 0x801DFCD8: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x801DFCDC: jal         0x800C6868
    // 0x801DFCE0: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    func_800C6868(rdram, ctx);
        goto after_36;
    // 0x801DFCE0: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    after_36:
L_801DFCE4:
    // 0x801DFCE4: lw          $t4, 0xBC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XBC);
    // 0x801DFCE8: addiu       $t3, $t4, 0x1
    ctx->r11 = ADD32(ctx->r12, 0X1);
    // 0x801DFCEC: slti        $at, $t3, 0x30
    ctx->r1 = SIGNED(ctx->r11) < 0X30 ? 1 : 0;
    // 0x801DFCF0: bne         $at, $zero, L_801DFC20
    if (ctx->r1 != 0) {
        // 0x801DFCF4: sw          $t3, 0xBC($sp)
        MEM_W(0XBC, ctx->r29) = ctx->r11;
            goto L_801DFC20;
    }
    // 0x801DFCF4: sw          $t3, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r11;
    // 0x801DFCF8: lui         $t5, 0x8011
    ctx->r13 = S32(0X8011 << 16);
    // 0x801DFCFC: lw          $t5, -0x4514($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4514);
    // 0x801DFD00: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x801DFD04: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x801DFD08: sw          $t5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r13;
    // 0x801DFD0C: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x801DFD10: addiu       $t7, $t5, 0x8
    ctx->r15 = ADD32(ctx->r13, 0X8);
    // 0x801DFD14: sw          $t7, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r15;
    // 0x801DFD18: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801DFD1C: addiu       $t9, $t9, -0x2D90
    ctx->r25 = ADD32(ctx->r25, -0X2D90);
    // 0x801DFD20: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x801DFD24: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x801DFD28: lwc1        $f4, 0x14($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X14);
    // 0x801DFD2C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801DFD30: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x801DFD34: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801DFD38: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x801DFD3C: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x801DFD40: nop

    // 0x801DFD44: sll         $t2, $t0, 16
    ctx->r10 = S32(ctx->r8 << 16);
    // 0x801DFD48: sra         $t4, $t2, 16
    ctx->r12 = S32(SIGNED(ctx->r10) >> 16);
    // 0x801DFD4C: andi        $t3, $t4, 0xFF
    ctx->r11 = ctx->r12 & 0XFF;
    // 0x801DFD50: ori         $t5, $t3, 0xFF00
    ctx->r13 = ctx->r11 | 0XFF00;
    // 0x801DFD54: sw          $t5, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r13;
    // 0x801DFD58: sw          $zero, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = 0;
L_801DFD5C:
    // 0x801DFD5C: lw          $t6, 0xBC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XBC);
    // 0x801DFD60: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801DFD64: addiu       $at, $zero, 0x800
    ctx->r1 = ADD32(0, 0X800);
    // 0x801DFD68: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x801DFD6C: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x801DFD70: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x801DFD74: subu        $t8, $t8, $t6
    ctx->r24 = SUB32(ctx->r24, ctx->r14);
    // 0x801DFD78: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x801DFD7C: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x801DFD80: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x801DFD84: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x801DFD88: lhu         $t9, -0x2A28($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X2A28);
    // 0x801DFD8C: andi        $t1, $t9, 0x800
    ctx->r9 = ctx->r25 & 0X800;
    // 0x801DFD90: bne         $t1, $at, L_801DFE20
    if (ctx->r9 != ctx->r1) {
        // 0x801DFD94: nop
    
            goto L_801DFE20;
    }
    // 0x801DFD94: nop

    // 0x801DFD98: lw          $t0, 0xBC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XBC);
    // 0x801DFD9C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x801DFDA0: addiu       $t4, $t4, -0x2A28
    ctx->r12 = ADD32(ctx->r12, -0X2A28);
    // 0x801DFDA4: sll         $t2, $t0, 2
    ctx->r10 = S32(ctx->r8 << 2);
    // 0x801DFDA8: addu        $t2, $t2, $t0
    ctx->r10 = ADD32(ctx->r10, ctx->r8);
    // 0x801DFDAC: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x801DFDB0: subu        $t2, $t2, $t0
    ctx->r10 = SUB32(ctx->r10, ctx->r8);
    // 0x801DFDB4: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x801DFDB8: addu        $t2, $t2, $t0
    ctx->r10 = ADD32(ctx->r10, ctx->r8);
    // 0x801DFDBC: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x801DFDC0: addu        $t3, $t2, $t4
    ctx->r11 = ADD32(ctx->r10, ctx->r12);
    // 0x801DFDC4: lw          $t5, 0x4($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X4);
    // 0x801DFDC8: addiu       $at, $zero, 0x2C
    ctx->r1 = ADD32(0, 0X2C);
    // 0x801DFDCC: bne         $t5, $at, L_801DFE20
    if (ctx->r13 != ctx->r1) {
        // 0x801DFDD0: nop
    
            goto L_801DFE20;
    }
    // 0x801DFDD0: nop

    // 0x801DFDD4: lwc1        $f16, 0x64($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X64);
    // 0x801DFDD8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DFDDC: lwc1        $f4, 0x7DA8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7DA8);
    // 0x801DFDE0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DFDE4: lw          $a3, 0x60($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X60);
    // 0x801DFDE8: lwc1        $f6, 0x7DAC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7DAC);
    // 0x801DFDEC: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x801DFDF0: lwc1        $f18, 0x68($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X68);
    // 0x801DFDF4: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DFDF8: lwc1        $f8, 0x7DB0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7DB0);
    // 0x801DFDFC: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x801DFE00: addiu       $a0, $a0, -0x7618
    ctx->r4 = ADD32(ctx->r4, -0X7618);
    // 0x801DFE04: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801DFE08: addiu       $a2, $t3, 0xA4
    ctx->r6 = ADD32(ctx->r11, 0XA4);
    // 0x801DFE0C: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x801DFE10: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x801DFE14: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x801DFE18: jal         0x800C6868
    // 0x801DFE1C: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    func_800C6868(rdram, ctx);
        goto after_37;
    // 0x801DFE1C: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    after_37:
L_801DFE20:
    // 0x801DFE20: lw          $t7, 0xBC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XBC);
    // 0x801DFE24: addiu       $t6, $t7, 0x1
    ctx->r14 = ADD32(ctx->r15, 0X1);
    // 0x801DFE28: slti        $at, $t6, 0x30
    ctx->r1 = SIGNED(ctx->r14) < 0X30 ? 1 : 0;
    // 0x801DFE2C: bne         $at, $zero, L_801DFD5C
    if (ctx->r1 != 0) {
        // 0x801DFE30: sw          $t6, 0xBC($sp)
        MEM_W(0XBC, ctx->r29) = ctx->r14;
            goto L_801DFD5C;
    }
    // 0x801DFE30: sw          $t6, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r14;
    // 0x801DFE34: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x801DFE38: lw          $t8, -0x4514($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4514);
    // 0x801DFE3C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x801DFE40: lui         $t1, 0xFA00
    ctx->r9 = S32(0XFA00 << 16);
    // 0x801DFE44: sw          $t8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r24;
    // 0x801DFE48: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x801DFE4C: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x801DFE50: sw          $t9, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r25;
    // 0x801DFE54: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x801DFE58: addiu       $t2, $t2, -0x2D90
    ctx->r10 = ADD32(ctx->r10, -0X2D90);
    // 0x801DFE5C: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x801DFE60: sw          $t1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r9;
    // 0x801DFE64: lwc1        $f10, 0x14($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X14);
    // 0x801DFE68: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801DFE6C: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x801DFE70: lui         $at, 0xC864
    ctx->r1 = S32(0XC864 << 16);
    // 0x801DFE74: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x801DFE78: ori         $at, $at, 0xC800
    ctx->r1 = ctx->r1 | 0XC800;
    // 0x801DFE7C: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x801DFE80: mfc1        $t5, $f4
    ctx->r13 = (int32_t)ctx->f4.u32l;
    // 0x801DFE84: nop

    // 0x801DFE88: sll         $t3, $t5, 16
    ctx->r11 = S32(ctx->r13 << 16);
    // 0x801DFE8C: sra         $t7, $t3, 16
    ctx->r15 = S32(SIGNED(ctx->r11) >> 16);
    // 0x801DFE90: andi        $t6, $t7, 0xFF
    ctx->r14 = ctx->r15 & 0XFF;
    // 0x801DFE94: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x801DFE98: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x801DFE9C: sw          $zero, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = 0;
L_801DFEA0:
    // 0x801DFEA0: lw          $t1, 0xBC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XBC);
    // 0x801DFEA4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x801DFEA8: addiu       $at, $zero, 0x800
    ctx->r1 = ADD32(0, 0X800);
    // 0x801DFEAC: sll         $t0, $t1, 2
    ctx->r8 = S32(ctx->r9 << 2);
    // 0x801DFEB0: addu        $t0, $t0, $t1
    ctx->r8 = ADD32(ctx->r8, ctx->r9);
    // 0x801DFEB4: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x801DFEB8: subu        $t0, $t0, $t1
    ctx->r8 = SUB32(ctx->r8, ctx->r9);
    // 0x801DFEBC: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x801DFEC0: addu        $t0, $t0, $t1
    ctx->r8 = ADD32(ctx->r8, ctx->r9);
    // 0x801DFEC4: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x801DFEC8: addu        $t2, $t2, $t0
    ctx->r10 = ADD32(ctx->r10, ctx->r8);
    // 0x801DFECC: lhu         $t2, -0x2A28($t2)
    ctx->r10 = MEM_HU(ctx->r10, -0X2A28);
    // 0x801DFED0: andi        $t4, $t2, 0x800
    ctx->r12 = ctx->r10 & 0X800;
    // 0x801DFED4: bne         $t4, $at, L_801DFF64
    if (ctx->r12 != ctx->r1) {
        // 0x801DFED8: nop
    
            goto L_801DFF64;
    }
    // 0x801DFED8: nop

    // 0x801DFEDC: lw          $t5, 0xBC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XBC);
    // 0x801DFEE0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801DFEE4: addiu       $t7, $t7, -0x2A28
    ctx->r15 = ADD32(ctx->r15, -0X2A28);
    // 0x801DFEE8: sll         $t3, $t5, 2
    ctx->r11 = S32(ctx->r13 << 2);
    // 0x801DFEEC: addu        $t3, $t3, $t5
    ctx->r11 = ADD32(ctx->r11, ctx->r13);
    // 0x801DFEF0: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x801DFEF4: subu        $t3, $t3, $t5
    ctx->r11 = SUB32(ctx->r11, ctx->r13);
    // 0x801DFEF8: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x801DFEFC: addu        $t3, $t3, $t5
    ctx->r11 = ADD32(ctx->r11, ctx->r13);
    // 0x801DFF00: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x801DFF04: addu        $t6, $t3, $t7
    ctx->r14 = ADD32(ctx->r11, ctx->r15);
    // 0x801DFF08: lw          $t8, 0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X4);
    // 0x801DFF0C: addiu       $at, $zero, 0x29
    ctx->r1 = ADD32(0, 0X29);
    // 0x801DFF10: bne         $t8, $at, L_801DFF64
    if (ctx->r24 != ctx->r1) {
        // 0x801DFF14: nop
    
            goto L_801DFF64;
    }
    // 0x801DFF14: nop

    // 0x801DFF18: lwc1        $f6, 0x64($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X64);
    // 0x801DFF1C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DFF20: lwc1        $f10, 0x7DB4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7DB4);
    // 0x801DFF24: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DFF28: lw          $a3, 0x60($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X60);
    // 0x801DFF2C: lwc1        $f16, 0x7DB8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7DB8);
    // 0x801DFF30: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x801DFF34: lwc1        $f8, 0x68($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X68);
    // 0x801DFF38: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801DFF3C: lwc1        $f18, 0x7DBC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7DBC);
    // 0x801DFF40: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x801DFF44: addiu       $a0, $a0, -0x7740
    ctx->r4 = ADD32(ctx->r4, -0X7740);
    // 0x801DFF48: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801DFF4C: addiu       $a2, $t6, 0xA4
    ctx->r6 = ADD32(ctx->r14, 0XA4);
    // 0x801DFF50: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x801DFF54: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    // 0x801DFF58: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x801DFF5C: jal         0x800C6868
    // 0x801DFF60: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    func_800C6868(rdram, ctx);
        goto after_38;
    // 0x801DFF60: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    after_38:
L_801DFF64:
    // 0x801DFF64: lw          $t9, 0xBC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XBC);
    // 0x801DFF68: addiu       $t1, $t9, 0x1
    ctx->r9 = ADD32(ctx->r25, 0X1);
    // 0x801DFF6C: slti        $at, $t1, 0x30
    ctx->r1 = SIGNED(ctx->r9) < 0X30 ? 1 : 0;
    // 0x801DFF70: bne         $at, $zero, L_801DFEA0
    if (ctx->r1 != 0) {
        // 0x801DFF74: sw          $t1, 0xBC($sp)
        MEM_W(0XBC, ctx->r29) = ctx->r9;
            goto L_801DFEA0;
    }
    // 0x801DFF74: sw          $t1, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r9;
    // 0x801DFF78: lui         $t0, 0x8011
    ctx->r8 = S32(0X8011 << 16);
    // 0x801DFF7C: lw          $t0, -0x4514($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X4514);
    // 0x801DFF80: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x801DFF84: lui         $t4, 0xFA00
    ctx->r12 = S32(0XFA00 << 16);
    // 0x801DFF88: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    // 0x801DFF8C: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x801DFF90: addiu       $t2, $t0, 0x8
    ctx->r10 = ADD32(ctx->r8, 0X8);
    // 0x801DFF94: sw          $t2, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r10;
    // 0x801DFF98: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x801DFF9C: addiu       $t3, $t3, -0x2D90
    ctx->r11 = ADD32(ctx->r11, -0X2D90);
    // 0x801DFFA0: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x801DFFA4: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x801DFFA8: lwc1        $f4, 0x14($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X14);
    // 0x801DFFAC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801DFFB0: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x801DFFB4: lui         $at, 0xC8FF
    ctx->r1 = S32(0XC8FF << 16);
    // 0x801DFFB8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801DFFBC: ori         $at, $at, 0xC800
    ctx->r1 = ctx->r1 | 0XC800;
    // 0x801DFFC0: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x801DFFC4: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x801DFFC8: nop

    // 0x801DFFCC: sll         $t6, $t8, 16
    ctx->r14 = S32(ctx->r24 << 16);
    // 0x801DFFD0: sra         $t9, $t6, 16
    ctx->r25 = S32(SIGNED(ctx->r14) >> 16);
    // 0x801DFFD4: andi        $t1, $t9, 0xFF
    ctx->r9 = ctx->r25 & 0XFF;
    // 0x801DFFD8: or          $t0, $t1, $at
    ctx->r8 = ctx->r9 | ctx->r1;
    // 0x801DFFDC: sw          $t0, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r8;
    // 0x801DFFE0: sw          $zero, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = 0;
L_801DFFE4:
    // 0x801DFFE4: lw          $t4, 0xBC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XBC);
    // 0x801DFFE8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x801DFFEC: addiu       $at, $zero, 0x800
    ctx->r1 = ADD32(0, 0X800);
    // 0x801DFFF0: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x801DFFF4: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x801DFFF8: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x801DFFFC: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x801E0000: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x801E0004: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x801E0008: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x801E000C: addu        $t3, $t3, $t5
    ctx->r11 = ADD32(ctx->r11, ctx->r13);
    // 0x801E0010: lhu         $t3, -0x2A28($t3)
    ctx->r11 = MEM_HU(ctx->r11, -0X2A28);
    // 0x801E0014: andi        $t7, $t3, 0x800
    ctx->r15 = ctx->r11 & 0X800;
    // 0x801E0018: bne         $t7, $at, L_801E00A8
    if (ctx->r15 != ctx->r1) {
        // 0x801E001C: nop
    
            goto L_801E00A8;
    }
    // 0x801E001C: nop

    // 0x801E0020: lw          $t8, 0xBC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XBC);
    // 0x801E0024: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801E0028: addiu       $t9, $t9, -0x2A28
    ctx->r25 = ADD32(ctx->r25, -0X2A28);
    // 0x801E002C: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x801E0030: addu        $t6, $t6, $t8
    ctx->r14 = ADD32(ctx->r14, ctx->r24);
    // 0x801E0034: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801E0038: subu        $t6, $t6, $t8
    ctx->r14 = SUB32(ctx->r14, ctx->r24);
    // 0x801E003C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801E0040: addu        $t6, $t6, $t8
    ctx->r14 = ADD32(ctx->r14, ctx->r24);
    // 0x801E0044: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801E0048: addu        $t1, $t6, $t9
    ctx->r9 = ADD32(ctx->r14, ctx->r25);
    // 0x801E004C: lw          $t0, 0x4($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X4);
    // 0x801E0050: addiu       $at, $zero, 0x2B
    ctx->r1 = ADD32(0, 0X2B);
    // 0x801E0054: bne         $t0, $at, L_801E00A8
    if (ctx->r8 != ctx->r1) {
        // 0x801E0058: nop
    
            goto L_801E00A8;
    }
    // 0x801E0058: nop

    // 0x801E005C: lwc1        $f16, 0x64($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X64);
    // 0x801E0060: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801E0064: lwc1        $f4, 0x7DC0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7DC0);
    // 0x801E0068: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801E006C: lw          $a3, 0x60($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X60);
    // 0x801E0070: lwc1        $f6, 0x7DC4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7DC4);
    // 0x801E0074: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x801E0078: lwc1        $f18, 0x68($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X68);
    // 0x801E007C: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801E0080: lwc1        $f8, 0x7DC8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7DC8);
    // 0x801E0084: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x801E0088: addiu       $a0, $a0, -0x7678
    ctx->r4 = ADD32(ctx->r4, -0X7678);
    // 0x801E008C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801E0090: addiu       $a2, $t1, 0xA4
    ctx->r6 = ADD32(ctx->r9, 0XA4);
    // 0x801E0094: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x801E0098: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x801E009C: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x801E00A0: jal         0x800C6868
    // 0x801E00A4: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    func_800C6868(rdram, ctx);
        goto after_39;
    // 0x801E00A4: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    after_39:
L_801E00A8:
    // 0x801E00A8: lw          $t2, 0xBC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XBC);
    // 0x801E00AC: addiu       $t4, $t2, 0x1
    ctx->r12 = ADD32(ctx->r10, 0X1);
    // 0x801E00B0: slti        $at, $t4, 0x30
    ctx->r1 = SIGNED(ctx->r12) < 0X30 ? 1 : 0;
    // 0x801E00B4: bne         $at, $zero, L_801DFFE4
    if (ctx->r1 != 0) {
        // 0x801E00B8: sw          $t4, 0xBC($sp)
        MEM_W(0XBC, ctx->r29) = ctx->r12;
            goto L_801DFFE4;
    }
    // 0x801E00B8: sw          $t4, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r12;
    // 0x801E00BC: lui         $t5, 0x8011
    ctx->r13 = S32(0X8011 << 16);
    // 0x801E00C0: lw          $t5, -0x4514($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4514);
    // 0x801E00C4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x801E00C8: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x801E00CC: sw          $t5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r13;
    // 0x801E00D0: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x801E00D4: addiu       $t3, $t5, 0x8
    ctx->r11 = ADD32(ctx->r13, 0X8);
    // 0x801E00D8: sw          $t3, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r11;
    // 0x801E00DC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801E00E0: addiu       $t6, $t6, -0x2D90
    ctx->r14 = ADD32(ctx->r14, -0X2D90);
    // 0x801E00E4: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x801E00E8: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x801E00EC: lwc1        $f10, 0x14($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X14);
    // 0x801E00F0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801E00F4: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x801E00F8: addiu       $at, $zero, -0x4C00
    ctx->r1 = ADD32(0, -0X4C00);
    // 0x801E00FC: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x801E0100: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x801E0104: mfc1        $t0, $f4
    ctx->r8 = (int32_t)ctx->f4.u32l;
    // 0x801E0108: nop

    // 0x801E010C: sll         $t1, $t0, 16
    ctx->r9 = S32(ctx->r8 << 16);
    // 0x801E0110: sra         $t2, $t1, 16
    ctx->r10 = S32(SIGNED(ctx->r9) >> 16);
    // 0x801E0114: andi        $t4, $t2, 0xFF
    ctx->r12 = ctx->r10 & 0XFF;
    // 0x801E0118: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x801E011C: sw          $t5, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r13;
    // 0x801E0120: sw          $zero, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = 0;
L_801E0124:
    // 0x801E0124: lw          $t7, 0xBC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XBC);
    // 0x801E0128: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801E012C: addiu       $at, $zero, 0x800
    ctx->r1 = ADD32(0, 0X800);
    // 0x801E0130: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x801E0134: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x801E0138: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x801E013C: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x801E0140: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x801E0144: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x801E0148: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x801E014C: addu        $t6, $t6, $t8
    ctx->r14 = ADD32(ctx->r14, ctx->r24);
    // 0x801E0150: lhu         $t6, -0x2A28($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X2A28);
    // 0x801E0154: andi        $t9, $t6, 0x800
    ctx->r25 = ctx->r14 & 0X800;
    // 0x801E0158: bne         $t9, $at, L_801E01E8
    if (ctx->r25 != ctx->r1) {
        // 0x801E015C: nop
    
            goto L_801E01E8;
    }
    // 0x801E015C: nop

    // 0x801E0160: lw          $t0, 0xBC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XBC);
    // 0x801E0164: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x801E0168: addiu       $t2, $t2, -0x2A28
    ctx->r10 = ADD32(ctx->r10, -0X2A28);
    // 0x801E016C: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x801E0170: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x801E0174: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x801E0178: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x801E017C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x801E0180: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x801E0184: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x801E0188: addu        $t4, $t1, $t2
    ctx->r12 = ADD32(ctx->r9, ctx->r10);
    // 0x801E018C: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x801E0190: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x801E0194: bne         $t5, $at, L_801E01E8
    if (ctx->r13 != ctx->r1) {
        // 0x801E0198: nop
    
            goto L_801E01E8;
    }
    // 0x801E0198: nop

    // 0x801E019C: lwc1        $f6, 0x64($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X64);
    // 0x801E01A0: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801E01A4: lwc1        $f10, 0x7DCC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7DCC);
    // 0x801E01A8: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801E01AC: lw          $a3, 0x60($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X60);
    // 0x801E01B0: lwc1        $f16, 0x7DD0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7DD0);
    // 0x801E01B4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x801E01B8: lwc1        $f8, 0x68($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X68);
    // 0x801E01BC: lui         $at, 0x801E
    ctx->r1 = S32(0X801E << 16);
    // 0x801E01C0: lwc1        $f18, 0x7DD4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7DD4);
    // 0x801E01C4: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x801E01C8: addiu       $a0, $a0, -0x77A8
    ctx->r4 = ADD32(ctx->r4, -0X77A8);
    // 0x801E01CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801E01D0: addiu       $a2, $t4, 0xA4
    ctx->r6 = ADD32(ctx->r12, 0XA4);
    // 0x801E01D4: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x801E01D8: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    // 0x801E01DC: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x801E01E0: jal         0x800C6868
    // 0x801E01E4: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    func_800C6868(rdram, ctx);
        goto after_40;
    // 0x801E01E4: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    after_40:
L_801E01E8:
    // 0x801E01E8: lw          $t3, 0xBC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XBC);
    // 0x801E01EC: addiu       $t7, $t3, 0x1
    ctx->r15 = ADD32(ctx->r11, 0X1);
    // 0x801E01F0: slti        $at, $t7, 0x30
    ctx->r1 = SIGNED(ctx->r15) < 0X30 ? 1 : 0;
    // 0x801E01F4: bne         $at, $zero, L_801E0124
    if (ctx->r1 != 0) {
        // 0x801E01F8: sw          $t7, 0xBC($sp)
        MEM_W(0XBC, ctx->r29) = ctx->r15;
            goto L_801E0124;
    }
    // 0x801E01F8: sw          $t7, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r15;
    // 0x801E01FC: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x801E0200: lw          $t8, -0x4514($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4514);
    // 0x801E0204: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x801E0208: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x801E020C: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x801E0210: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x801E0214: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x801E0218: sw          $t6, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r14;
    // 0x801E021C: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x801E0220: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x801E0224: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x801E0228: b           L_801E0254
    // 0x801E022C: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
        goto L_801E0254;
    // 0x801E022C: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
L_801E0230:
    // 0x801E0230: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x801E0234: lw          $t5, -0x2E34($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2E34);
    // 0x801E0238: addiu       $at, $zero, 0x6D
    ctx->r1 = ADD32(0, 0X6D);
    // 0x801E023C: bne         $t5, $at, L_801E0254
    if (ctx->r13 != ctx->r1) {
        // 0x801E0240: nop
    
            goto L_801E0254;
    }
    // 0x801E0240: nop

    // 0x801E0244: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801E0248: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x801E024C: addiu       $t4, $t4, -0x2D90
    ctx->r12 = ADD32(ctx->r12, -0X2D90);
    // 0x801E0250: swc1        $f4, 0x14($t4)
    MEM_W(0X14, ctx->r12) = ctx->f4.u32l;
L_801E0254:
    // 0x801E0254: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x801E0258: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
    // 0x801E025C: jr          $ra
    // 0x801E0260: nop

    return;
    // 0x801E0260: nop

;}
RECOMP_FUNC void func_801E0264_0BA450(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E0264: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x801E0268: lhu         $t6, -0x4530($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X4530);
    // 0x801E026C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801E0270: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E0274: andi        $t7, $t6, 0x100
    ctx->r15 = ctx->r14 & 0X100;
    // 0x801E0278: bne         $t7, $zero, L_801E02A8
    if (ctx->r15 != 0) {
        // 0x801E027C: nop
    
            goto L_801E02A8;
    }
    // 0x801E027C: nop

    // 0x801E0280: jal         0x801DCC7C
    // 0x801E0284: nop

    func_801DCC7C_0BA450(rdram, ctx);
        goto after_0;
    // 0x801E0284: nop

    after_0:
    // 0x801E0288: jal         0x801DD040
    // 0x801E028C: nop

    func_801DD040_0BA450(rdram, ctx);
        goto after_1;
    // 0x801E028C: nop

    after_1:
    // 0x801E0290: jal         0x801DCC7C
    // 0x801E0294: nop

    func_801DCC7C_0BA450(rdram, ctx);
        goto after_2;
    // 0x801E0294: nop

    after_2:
    // 0x801E0298: jal         0x801DDB7C
    // 0x801E029C: nop

    func_801DDB7C_0BA450(rdram, ctx);
        goto after_3;
    // 0x801E029C: nop

    after_3:
    // 0x801E02A0: jal         0x801DCC7C
    // 0x801E02A4: nop

    func_801DCC7C_0BA450(rdram, ctx);
        goto after_4;
    // 0x801E02A4: nop

    after_4:
L_801E02A8:
    // 0x801E02A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E02AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801E02B0: jr          $ra
    // 0x801E02B4: nop

    return;
    // 0x801E02B4: nop

    // 0x801E02B8: nop

    // 0x801E02BC: nop

;}
RECOMP_FUNC void func_801E02C0_0BA450(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E02C0: addiu       $t6, $zero, 0xB
    ctx->r14 = ADD32(0, 0XB);
    // 0x801E02C4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801E02C8: sw          $t6, -0x2E50($at)
    MEM_W(-0X2E50, ctx->r1) = ctx->r14;
    // 0x801E02CC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801E02D0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801E02D4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801E02D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E02DC: addiu       $t7, $t7, -0x2E28
    ctx->r15 = ADD32(ctx->r15, -0X2E28);
    // 0x801E02E0: sw          $zero, -0x2E4C($at)
    MEM_W(-0X2E4C, ctx->r1) = 0;
    // 0x801E02E4: lbu         $t8, 0xA($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0XA);
    // 0x801E02E8: addiu       $a0, $zero, 0x140
    ctx->r4 = ADD32(0, 0X140);
    // 0x801E02EC: addiu       $a1, $zero, 0xF0
    ctx->r5 = ADD32(0, 0XF0);
    // 0x801E02F0: andi        $t9, $t8, 0xFD
    ctx->r25 = ctx->r24 & 0XFD;
    // 0x801E02F4: jal         0x800C3044
    // 0x801E02F8: sb          $t9, 0xA($t7)
    MEM_B(0XA, ctx->r15) = ctx->r25;
    func_800C3044(rdram, ctx);
        goto after_0;
    // 0x801E02F8: sb          $t9, 0xA($t7)
    MEM_B(0XA, ctx->r15) = ctx->r25;
    after_0:
    // 0x801E02FC: jal         0x801E0490
    // 0x801E0300: nop

    func_801E0490_0BA450(rdram, ctx);
        goto after_1;
    // 0x801E0300: nop

    after_1:
    // 0x801E0304: jal         0x800C328C
    // 0x801E0308: nop

    func_800C328C(rdram, ctx);
        goto after_2;
    // 0x801E0308: nop

    after_2:
    // 0x801E030C: jal         0x800C7FA4
    // 0x801E0310: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    func_800C7FA4(rdram, ctx);
        goto after_3;
    // 0x801E0310: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    after_3:
    // 0x801E0314: lui         $a0, 0x801E
    ctx->r4 = S32(0X801E << 16);
    // 0x801E0318: jal         0x800D1640
    // 0x801E031C: addiu       $a0, $a0, 0x37C
    ctx->r4 = ADD32(ctx->r4, 0X37C);
    func_800D1640(rdram, ctx);
        goto after_4;
    // 0x801E031C: addiu       $a0, $a0, 0x37C
    ctx->r4 = ADD32(ctx->r4, 0X37C);
    after_4:
L_801E0320:
    yield_self_1ms(rdram);
    // 0x801E0320: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x801E0324: lw          $t0, -0x2E4C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2E4C);
    // 0x801E0328: beq         $t0, $zero, L_801E0320
    if (ctx->r8 == 0) {
        // 0x801E032C: nop
    
            goto L_801E0320;
    }
    // 0x801E032C: nop

    // 0x801E0330: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x801E0334: lhu         $t1, -0x4530($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X4530);
    // 0x801E0338: andi        $t2, $t1, 0x2000
    ctx->r10 = ctx->r9 & 0X2000;
    // 0x801E033C: bne         $t2, $zero, L_801E0320
    if (ctx->r10 != 0) {
        // 0x801E0340: nop
    
            goto L_801E0320;
    }
    // 0x801E0340: nop

    // 0x801E0344: jal         0x800CB720
    // 0x801E0348: nop

    func_800CB720(rdram, ctx);
        goto after_5;
    // 0x801E0348: nop

    after_5:
    // 0x801E034C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x801E0350: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x801E0354: bne         $t3, $zero, L_801E0320
    if (ctx->r11 != 0) {
        // 0x801E0358: nop
    
            goto L_801E0320;
    }
    // 0x801E0358: nop

    // 0x801E035C: jal         0x800C6DD4
    // 0x801E0360: nop

    func_800C6DD4(rdram, ctx);
        goto after_6;
    // 0x801E0360: nop

    after_6:
    // 0x801E0364: jal         0x800C7154
    // 0x801E0368: nop

    func_800C7154(rdram, ctx);
        goto after_7;
    // 0x801E0368: nop

    after_7:
    // 0x801E036C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E0370: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801E0374: jr          $ra
    // 0x801E0378: nop

    return;
    // 0x801E0378: nop

;}
RECOMP_FUNC void func_801E037C_0BA450(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E037C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801E0380: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801E0384: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x801E0388: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801E038C: bgtz        $t6, L_801E0480
    if (SIGNED(ctx->r14) > 0) {
        // 0x801E0390: nop
    
            goto L_801E0480;
    }
    // 0x801E0390: nop

    // 0x801E0394: jal         0x800C3704
    // 0x801E0398: nop

    func_800C3704(rdram, ctx);
        goto after_0;
    // 0x801E0398: nop

    after_0:
    // 0x801E039C: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x801E03A0: lw          $t7, -0x4514($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4514);
    // 0x801E03A4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x801E03A8: lui         $t9, 0xDB06
    ctx->r25 = S32(0XDB06 << 16);
    // 0x801E03AC: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x801E03B0: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x801E03B4: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x801E03B8: sw          $t8, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r24;
    // 0x801E03BC: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x801E03C0: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x801E03C4: jal         0x800C7458
    // 0x801E03C8: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    func_800C7458(rdram, ctx);
        goto after_1;
    // 0x801E03C8: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    after_1:
    // 0x801E03CC: jal         0x8016D9E8
    // 0x801E03D0: nop

    func_8016D9E8_02FC30(rdram, ctx);
        goto after_2;
    // 0x801E03D0: nop

    after_2:
    // 0x801E03D4: jal         0x8016E8B0
    // 0x801E03D8: nop

    func_8016E8B0_02FC30(rdram, ctx);
        goto after_3;
    // 0x801E03D8: nop

    after_3:
    // 0x801E03DC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x801E03E0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x801E03E4: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x801E03E8: lbu         $a2, -0x2C2D($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X2C2D);
    // 0x801E03EC: lbu         $a1, -0x2C2E($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X2C2E);
    // 0x801E03F0: lbu         $a0, -0x2C2F($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X2C2F);
    // 0x801E03F4: jal         0x800C25FC
    // 0x801E03F8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800C25FC(rdram, ctx);
        goto after_4;
    // 0x801E03F8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
    // 0x801E03FC: jal         0x800C3578
    // 0x801E0400: nop

    func_800C3578(rdram, ctx);
        goto after_5;
    // 0x801E0400: nop

    after_5:
    // 0x801E0404: jal         0x801E2364
    // 0x801E0408: nop

    func_801E2364_0BA450(rdram, ctx);
        goto after_6;
    // 0x801E0408: nop

    after_6:
    // 0x801E040C: jal         0x801E0840
    // 0x801E0410: nop

    func_801E0840_0BA450(rdram, ctx);
        goto after_7;
    // 0x801E0410: nop

    after_7:
    // 0x801E0414: jal         0x800C3760
    // 0x801E0418: nop

    func_800C3760(rdram, ctx);
        goto after_8;
    // 0x801E0418: nop

    after_8:
    // 0x801E041C: jal         0x8016FBBC
    // 0x801E0420: nop

    func_8016FBBC_02FC30(rdram, ctx);
        goto after_9;
    // 0x801E0420: nop

    after_9:
    // 0x801E0424: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x801E0428: lw          $t2, -0x2E34($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2E34);
    // 0x801E042C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801E0430: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x801E0434: jal         0x801E05F4
    // 0x801E0438: sw          $t3, -0x2E34($at)
    MEM_W(-0X2E34, ctx->r1) = ctx->r11;
    func_801E05F4_0BA450(rdram, ctx);
        goto after_10;
    // 0x801E0438: sw          $t3, -0x2E34($at)
    MEM_W(-0X2E34, ctx->r1) = ctx->r11;
    after_10:
    // 0x801E043C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x801E0440: lw          $t4, -0x2E4C($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2E4C);
    // 0x801E0444: beq         $t4, $zero, L_801E0480
    if (ctx->r12 == 0) {
        // 0x801E0448: nop
    
            goto L_801E0480;
    }
    // 0x801E0448: nop

    // 0x801E044C: lui         $t5, 0x8011
    ctx->r13 = S32(0X8011 << 16);
    // 0x801E0450: lhu         $t5, -0x4530($t5)
    ctx->r13 = MEM_HU(ctx->r13, -0X4530);
    // 0x801E0454: andi        $t6, $t5, 0x2000
    ctx->r14 = ctx->r13 & 0X2000;
    // 0x801E0458: bne         $t6, $zero, L_801E0480
    if (ctx->r14 != 0) {
        // 0x801E045C: nop
    
            goto L_801E0480;
    }
    // 0x801E045C: nop

    // 0x801E0460: jal         0x800CB720
    // 0x801E0464: nop

    func_800CB720(rdram, ctx);
        goto after_11;
    // 0x801E0464: nop

    after_11:
    // 0x801E0468: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x801E046C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x801E0470: bne         $t7, $zero, L_801E0480
    if (ctx->r15 != 0) {
        // 0x801E0474: nop
    
            goto L_801E0480;
    }
    // 0x801E0474: nop

    // 0x801E0478: jal         0x800D1640
    // 0x801E047C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800D1640(rdram, ctx);
        goto after_12;
    // 0x801E047C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_12:
L_801E0480:
    // 0x801E0480: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801E0484: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801E0488: jr          $ra
    // 0x801E048C: nop

    return;
    // 0x801E048C: nop

;}
RECOMP_FUNC void func_801E0490_0BA450(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801E0490: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801E0494: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801E0498: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x801E049C: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x801E04A0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x801E04A4: addiu       $t6, $t6, -0x2E18
    ctx->r14 = ADD32(ctx->r14, -0X2E18);
    // 0x801E04A8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801E04AC: addiu       $t7, $t7, -0x2E18
    ctx->r15 = ADD32(ctx->r15, -0X2E18);
    // 0x801E04B0: sw          $zero, 0x28($t6)
    MEM_W(0X28, ctx->r14) = 0;
    // 0x801E04B4: lw          $t8, 0x28($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X28);
    // 0x801E04B8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801E04BC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801E04C0: addiu       $t9, $t9, 0x3C00
    ctx->r25 = ADD32(ctx->r25, 0X3C00);
    // 0x801E04C4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x801E04C8: sw          $t8, -0x2E34($at)
    MEM_W(-0X2E34, ctx->r1) = ctx->r24;
    // 0x801E04CC: sw          $zero, 0xFC($t9)
    MEM_W(0XFC, ctx->r25) = 0;
    // 0x801E04D0: addiu       $t1, $t1, 0x3D00
    ctx->r9 = ADD32(ctx->r9, 0X3D00);
    // 0x801E04D4: addiu       $t0, $zero, 0xF0
    ctx->r8 = ADD32(0, 0XF0);
    // 0x801E04D8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x801E04DC: addiu       $t2, $t2, 0x3B00
    ctx->r10 = ADD32(ctx->r10, 0X3B00);
    // 0x801E04E0: sw          $t0, 0xFC($t1)
    MEM_W(0XFC, ctx->r9) = ctx->r8;
    // 0x801E04E4: sb          $zero, 0x3F($t2)
    MEM_B(0X3F, ctx->r10) = 0;
    // 0x801E04E8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x801E04EC: lw          $t3, -0x2E40($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2E40);
    // 0x801E04F0: lui         $t5, 0x801F
    ctx->r13 = S32(0X801F << 16);
    // 0x801E04F4: addiu       $t5, $t5, -0x1F4C
    ctx->r13 = ADD32(ctx->r13, -0X1F4C);
    // 0x801E04F8: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x801E04FC: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x801E0500: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x801E0504: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x801E0508: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x801E050C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801E0510: sw          $t7, -0x2BB8($at)
    MEM_W(-0X2BB8, ctx->r1) = ctx->r15;
    // 0x801E0514: lw          $t8, 0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X4);
    // 0x801E0518: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801E051C: sw          $t8, -0x2BB0($at)
    MEM_W(-0X2BB0, ctx->r1) = ctx->r24;
    // 0x801E0520: lw          $t9, 0x8($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X8);
    // 0x801E0524: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801E0528: jal         0x8016D8A4
    // 0x801E052C: sw          $t9, -0x2BB4($at)
    MEM_W(-0X2BB4, ctx->r1) = ctx->r25;
    func_8016D8A4_02FC30(rdram, ctx);
        goto after_0;
    // 0x801E052C: sw          $t9, -0x2BB4($at)
    MEM_W(-0X2BB4, ctx->r1) = ctx->r25;
    after_0:
    // 0x801E0530: lui         $t0, 0x801F
    ctx->r8 = S32(0X801F << 16);
    // 0x801E0534: addiu       $t0, $t0, -0x1F10
    ctx->r8 = ADD32(ctx->r8, -0X1F10);
    // 0x801E0538: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801E053C: jal         0x8016E85C
    // 0x801E0540: sw          $t0, -0x2D8C($at)
    MEM_W(-0X2D8C, ctx->r1) = ctx->r8;
    func_8016E85C_02FC30(rdram, ctx);
        goto after_1;
    // 0x801E0540: sw          $t0, -0x2D8C($at)
    MEM_W(-0X2D8C, ctx->r1) = ctx->r8;
    after_1:
    // 0x801E0544: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801E0548: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x801E054C: addiu       $t1, $t1, -0x2D90
    ctx->r9 = ADD32(ctx->r9, -0X2D90);
    // 0x801E0550: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x801E0554: addiu       $t2, $t2, -0x2D90
    ctx->r10 = ADD32(ctx->r10, -0X2D90);
    // 0x801E0558: swc1        $f4, 0x20($t1)
    MEM_W(0X20, ctx->r9) = ctx->f4.u32l;
    // 0x801E055C: lwc1        $f22, 0x20($t2)
    ctx->f22.u32l = MEM_W(ctx->r10, 0X20);
    // 0x801E0560: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x801E0564: addiu       $t3, $t3, -0x2D90
    ctx->r11 = ADD32(ctx->r11, -0X2D90);
    // 0x801E0568: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x801E056C: swc1        $f22, 0x1C($t2)
    MEM_W(0X1C, ctx->r10) = ctx->f22.u32l;
    // 0x801E0570: mov.s       $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    ctx->f20.fl = ctx->f22.fl;
    // 0x801E0574: swc1        $f20, 0x18($t3)
    MEM_W(0X18, ctx->r11) = ctx->f20.u32l;
    // 0x801E0578: addiu       $t4, $t4, -0x2D90
    ctx->r12 = ADD32(ctx->r12, -0X2D90);
    // 0x801E057C: swc1        $f20, 0x14($t4)
    MEM_W(0X14, ctx->r12) = ctx->f20.u32l;
    // 0x801E0580: addiu       $a0, $zero, 0x78
    ctx->r4 = ADD32(0, 0X78);
    // 0x801E0584: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    // 0x801E0588: jal         0x800C6E0C
    // 0x801E058C: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    func_800C6E0C(rdram, ctx);
        goto after_2;
    // 0x801E058C: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    after_2:
    // 0x801E0590: addiu       $t5, $zero, 0xA
    ctx->r13 = ADD32(0, 0XA);
    // 0x801E0594: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x801E0598: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x801E059C: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    // 0x801E05A0: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    // 0x801E05A4: addiu       $a3, $zero, 0x1E
    ctx->r7 = ADD32(0, 0X1E);
    // 0x801E05A8: jal         0x800C6E68
    // 0x801E05AC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_800C6E68(rdram, ctx);
        goto after_3;
    // 0x801E05AC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_3:
    // 0x801E05B0: jal         0x800C6DBC
    // 0x801E05B4: nop

    func_800C6DBC(rdram, ctx);
        goto after_4;
    // 0x801E05B4: nop

    after_4:
    // 0x801E05B8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801E05BC: sb          $zero, -0x2C2D($at)
    MEM_B(-0X2C2D, ctx->r1) = 0;
    // 0x801E05C0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801E05C4: sb          $zero, -0x2C2E($at)
    MEM_B(-0X2C2E, ctx->r1) = 0;
    // 0x801E05C8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801E05CC: sb          $zero, -0x2C2F($at)
    MEM_B(-0X2C2F, ctx->r1) = 0;
    // 0x801E05D0: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x801E05D4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801E05D8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x801E05DC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801E05E0: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x801E05E4: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x801E05E8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x801E05EC: jr          $ra
    // 0x801E05F0: swc1        $f6, -0x41A4($at)
    MEM_W(-0X41A4, ctx->r1) = ctx->f6.u32l;
    return;
    // 0x801E05F0: swc1        $f6, -0x41A4($at)
    MEM_W(-0X41A4, ctx->r1) = ctx->f6.u32l;
;}
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
