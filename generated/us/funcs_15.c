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

RECOMP_FUNC void func_8018C608_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018C608: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018C60C: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    // 0x8018C610: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8018C614: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018C618: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8018C61C: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    // 0x8018C620: addiu       $t6, $t6, -0x4198
    ctx->r14 = ADD32(ctx->r14, -0X4198);
    // 0x8018C624: lwc1        $f4, 0x0($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X0);
    // 0x8018C628: lwc1        $f6, 0x18($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8018C62C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8018C630: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x8018C634: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8018C638: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8018C63C: addiu       $t8, $t8, -0x4198
    ctx->r24 = ADD32(ctx->r24, -0X4198);
    // 0x8018C640: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8018C644: swc1        $f8, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f8.u32l;
    // 0x8018C648: lwc1        $f16, 0x1C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8018C64C: lwc1        $f10, 0x4($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X4);
    // 0x8018C650: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x8018C654: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8018C658: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8018C65C: addiu       $t0, $t0, -0x4198
    ctx->r8 = ADD32(ctx->r8, -0X4198);
    // 0x8018C660: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8018C664: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x8018C668: swc1        $f18, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f18.u32l;
    // 0x8018C66C: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8018C670: lwc1        $f4, 0x8($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X8);
    // 0x8018C674: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8018C678: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x8018C67C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8018C680: swc1        $f8, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f8.u32l;
    // 0x8018C684: lwc1        $f10, 0x4($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X4);
    // 0x8018C688: lwc1        $f18, 0x8($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X8);
    // 0x8018C68C: lwc1        $f8, 0xC($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0XC);
    // 0x8018C690: mul.s       $f16, $f10, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x8018C694: nop

    // 0x8018C698: mul.s       $f4, $f18, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x8018C69C: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x8018C6A0: mul.s       $f10, $f8, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x8018C6A4: jal         0x800D68E0
    // 0x8018C6A8: add.s       $f12, $f10, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x8018C6A8: add.s       $f12, $f10, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f6.fl;
    after_0:
    // 0x8018C6AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018C6B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018C6B4: jr          $ra
    // 0x8018C6B8: nop

    return;
    // 0x8018C6B8: nop

;}
RECOMP_FUNC void func_8018C6BC_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018C6BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018C6C0: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    // 0x8018C6C4: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8018C6C8: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    // 0x8018C6CC: lwc1        $f8, 0x1C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8018C6D0: mul.s       $f6, $f4, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x8018C6D4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8018C6D8: lwc1        $f18, 0x20($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8018C6DC: mul.s       $f10, $f8, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x8018C6E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018C6E4: mul.s       $f4, $f18, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x8018C6E8: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8018C6EC: jal         0x800D68E0
    // 0x8018C6F0: add.s       $f12, $f16, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x8018C6F0: add.s       $f12, $f16, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f4.fl;
    after_0:
    // 0x8018C6F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018C6F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018C6FC: jr          $ra
    // 0x8018C700: nop

    return;
    // 0x8018C700: nop

;}
RECOMP_FUNC void func_8018C704_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018C704: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8018C708: swc1        $f12, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f12.u32l;
    // 0x8018C70C: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8018C710: swc1        $f14, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f14.u32l;
    // 0x8018C714: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8018C718: mul.s       $f6, $f4, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x8018C71C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8018C720: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8018C724: mul.s       $f10, $f8, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x8018C728: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8018C72C: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8018C730: mul.s       $f4, $f18, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x8018C734: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8018C738: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8018C73C: jal         0x800D68E0
    // 0x8018C740: add.s       $f12, $f16, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x8018C740: add.s       $f12, $f16, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f4.fl;
    after_0:
    // 0x8018C744: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8018C748: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8018C74C: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8018C750: mul.s       $f6, $f8, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x8018C754: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8018C758: mul.s       $f18, $f10, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x8018C75C: add.s       $f16, $f6, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x8018C760: mul.s       $f8, $f4, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x8018C764: jal         0x800D68E0
    // 0x8018C768: add.s       $f12, $f16, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x8018C768: add.s       $f12, $f16, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f8.fl;
    after_1:
    // 0x8018C76C: mul.s       $f10, $f0, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8018C770: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8018C774: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x8018C778: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8018C77C: c.eq.s      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.fl == ctx->f18.fl;
    // 0x8018C780: nop

    // 0x8018C784: bc1t        L_8018C7E4
    if (c1cs) {
        // 0x8018C788: nop
    
            goto L_8018C7E4;
    }
    // 0x8018C788: nop

    // 0x8018C78C: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8018C790: lwc1        $f16, 0x3C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8018C794: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8018C798: lwc1        $f18, 0x40($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8018C79C: mul.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x8018C7A0: nop

    // 0x8018C7A4: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8018C7A8: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8018C7AC: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8018C7B0: add.s       $f16, $f8, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8018C7B4: mul.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8018C7B8: add.s       $f4, $f16, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x8018C7BC: jal         0x800E4BE0
    // 0x8018C7C0: div.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    func_800E4BE0(rdram, ctx);
        goto after_2;
    // 0x8018C7C0: div.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    after_2:
    // 0x8018C7C4: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8018C7C8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018C7CC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018C7D0: lwc1        $f16, 0x1E8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X1E8);
    // 0x8018C7D4: mul.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8018C7D8: div.s       $f8, $f18, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = DIV_S(ctx->f18.fl, ctx->f16.fl);
    // 0x8018C7DC: b           L_8018C7F0
    // 0x8018C7E0: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
        goto L_8018C7F0;
    // 0x8018C7E0: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
L_8018C7E4:
    // 0x8018C7E4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8018C7E8: nop

    // 0x8018C7EC: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
L_8018C7F0:
    // 0x8018C7F0: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8018C7F4: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8018C7F8: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8018C7FC: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8018C800: mul.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8018C804: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x8018C808: mul.s       $f4, $f16, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x8018C80C: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8018C810: swc1        $f6, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f6.u32l;
    // 0x8018C814: lwc1        $f16, 0x3C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8018C818: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8018C81C: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8018C820: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8018C824: mul.s       $f8, $f10, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8018C828: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x8018C82C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8018C830: sub.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x8018C834: swc1        $f10, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f10.u32l;
    // 0x8018C838: lwc1        $f18, 0x40($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8018C83C: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8018C840: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8018C844: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8018C848: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8018C84C: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x8018C850: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8018C854: sub.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x8018C858: swc1        $f16, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f16.u32l;
    // 0x8018C85C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8018C860: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8018C864: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8018C868: jr          $ra
    // 0x8018C86C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8018C86C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8018C870_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018C870: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x8018C874: lw          $t6, 0xC8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC8);
    // 0x8018C878: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8018C87C: sw          $a0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r4;
    // 0x8018C880: sw          $a1, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r5;
    // 0x8018C884: sw          $a2, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r6;
    // 0x8018C888: bne         $t6, $zero, L_8018C948
    if (ctx->r14 != 0) {
        // 0x8018C88C: sw          $a3, 0xC4($sp)
        MEM_W(0XC4, ctx->r29) = ctx->r7;
            goto L_8018C948;
    }
    // 0x8018C88C: sw          $a3, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r7;
    // 0x8018C890: lw          $t7, 0xC0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC0);
    // 0x8018C894: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8018C898: addiu       $t9, $t9, 0xF98
    ctx->r25 = ADD32(ctx->r25, 0XF98);
    // 0x8018C89C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8018C8A0: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8018C8A4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8018C8A8: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8018C8AC: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8018C8B0: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8018C8B4: lwc1        $f4, 0x50($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X50);
    // 0x8018C8B8: lwc1        $f6, 0x24($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X24);
    // 0x8018C8BC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8018C8C0: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x8018C8C4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8018C8C8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8018C8CC: addiu       $t4, $t4, 0xF98
    ctx->r12 = ADD32(ctx->r12, 0XF98);
    // 0x8018C8D0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8018C8D4: swc1        $f8, 0x50($t1)
    MEM_W(0X50, ctx->r9) = ctx->f8.u32l;
    // 0x8018C8D8: lw          $t2, 0xC0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC0);
    // 0x8018C8DC: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x8018C8E0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8018C8E4: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8018C8E8: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x8018C8EC: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8018C8F0: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8018C8F4: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x8018C8F8: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8018C8FC: lwc1        $f10, 0x54($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X54);
    // 0x8018C900: lwc1        $f16, 0x28($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0X28);
    // 0x8018C904: addiu       $t9, $t9, 0xF98
    ctx->r25 = ADD32(ctx->r25, 0XF98);
    // 0x8018C908: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8018C90C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8018C910: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x8018C914: swc1        $f18, 0x54($t6)
    MEM_W(0X54, ctx->r14) = ctx->f18.u32l;
    // 0x8018C918: lw          $t7, 0xC0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC0);
    // 0x8018C91C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8018C920: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8018C924: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8018C928: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8018C92C: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8018C930: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8018C934: lwc1        $f4, 0x58($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X58);
    // 0x8018C938: lwc1        $f6, 0x2C($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X2C);
    // 0x8018C93C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8018C940: b           L_8018C9D8
    // 0x8018C944: swc1        $f8, 0x58($t1)
    MEM_W(0X58, ctx->r9) = ctx->f8.u32l;
        goto L_8018C9D8;
    // 0x8018C944: swc1        $f8, 0x58($t1)
    MEM_W(0X58, ctx->r9) = ctx->f8.u32l;
L_8018C948:
    // 0x8018C948: lw          $t2, 0xC0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC0);
    // 0x8018C94C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018C950: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8018C954: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8018C958: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x8018C95C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8018C960: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8018C964: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x8018C968: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x8018C96C: lwc1        $f10, 0xFBC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0XFBC);
    // 0x8018C970: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x8018C974: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018C978: swc1        $f10, 0x50($t4)
    MEM_W(0X50, ctx->r12) = ctx->f10.u32l;
    // 0x8018C97C: lw          $t5, 0xC0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC0);
    // 0x8018C980: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8018C984: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x8018C988: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8018C98C: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x8018C990: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8018C994: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8018C998: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8018C99C: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8018C9A0: lwc1        $f16, 0xFC0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0XFC0);
    // 0x8018C9A4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018C9A8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8018C9AC: swc1        $f16, 0x54($t7)
    MEM_W(0X54, ctx->r15) = ctx->f16.u32l;
    // 0x8018C9B0: lw          $t8, 0xC0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC0);
    // 0x8018C9B4: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x8018C9B8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8018C9BC: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8018C9C0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8018C9C4: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8018C9C8: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x8018C9CC: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8018C9D0: lwc1        $f18, 0xFC4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0XFC4);
    // 0x8018C9D4: swc1        $f18, 0x58($t0)
    MEM_W(0X58, ctx->r8) = ctx->f18.u32l;
L_8018C9D8:
    // 0x8018C9D8: jal         0x800D6D20
    // 0x8018C9DC: addiu       $a0, $sp, 0x78
    ctx->r4 = ADD32(ctx->r29, 0X78);
    guMtxIdentF_recomp(rdram, ctx);
        goto after_0;
    // 0x8018C9DC: addiu       $a0, $sp, 0x78
    ctx->r4 = ADD32(ctx->r29, 0X78);
    after_0:
    // 0x8018C9E0: jal         0x800D6D20
    // 0x8018C9E4: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    guMtxIdentF_recomp(rdram, ctx);
        goto after_1;
    // 0x8018C9E4: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    after_1:
    // 0x8018C9E8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8018C9EC: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x8018C9F0: lwc1        $f4, 0x50($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X50);
    // 0x8018C9F4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8018C9F8: nop

    // 0x8018C9FC: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x8018CA00: nop

    // 0x8018CA04: bc1f        L_8018CA44
    if (!c1cs) {
        // 0x8018CA08: nop
    
            goto L_8018CA44;
    }
    // 0x8018CA08: nop

    // 0x8018CA0C: lwc1        $f8, 0x54($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X54);
    // 0x8018CA10: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8018CA14: nop

    // 0x8018CA18: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x8018CA1C: nop

    // 0x8018CA20: bc1f        L_8018CA44
    if (!c1cs) {
        // 0x8018CA24: nop
    
            goto L_8018CA44;
    }
    // 0x8018CA24: nop

    // 0x8018CA28: lwc1        $f16, 0x58($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X58);
    // 0x8018CA2C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8018CA30: nop

    // 0x8018CA34: c.eq.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl == ctx->f18.fl;
    // 0x8018CA38: nop

    // 0x8018CA3C: bc1t        L_8018CD64
    if (c1cs) {
        // 0x8018CA40: nop
    
            goto L_8018CD64;
    }
    // 0x8018CA40: nop

L_8018CA44:
    // 0x8018CA44: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8018CA48: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x8018CA4C: lwc1        $f4, 0x50($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X50);
    // 0x8018CA50: lwc1        $f8, 0x54($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X54);
    // 0x8018CA54: lwc1        $f18, 0x58($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X58);
    // 0x8018CA58: mul.s       $f6, $f4, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x8018CA5C: nop

    // 0x8018CA60: mul.s       $f10, $f8, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x8018CA64: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8018CA68: mul.s       $f4, $f18, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x8018CA6C: jal         0x800D68E0
    // 0x8018CA70: add.s       $f12, $f4, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f16.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_2;
    // 0x8018CA70: add.s       $f12, $f4, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f16.fl;
    after_2:
    // 0x8018CA74: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018CA78: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018CA7C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8018CA80: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x8018CA84: div.s       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8018CA88: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8018CA8C: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x8018CA90: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8018CA94: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x8018CA98: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8018CA9C: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x8018CAA0: addiu       $t7, $t6, 0x5C
    ctx->r15 = ADD32(ctx->r14, 0X5C);
    // 0x8018CAA4: addiu       $t8, $t6, 0x60
    ctx->r24 = ADD32(ctx->r14, 0X60);
    // 0x8018CAA8: addiu       $t9, $t6, 0x64
    ctx->r25 = ADD32(ctx->r14, 0X64);
    // 0x8018CAAC: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8018CAB0: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8018CAB4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8018CAB8: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    // 0x8018CABC: lwc1        $f10, 0x50($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X50);
    // 0x8018CAC0: mul.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x8018CAC4: swc1        $f18, 0x50($t3)
    MEM_W(0X50, ctx->r11) = ctx->f18.u32l;
    // 0x8018CAC8: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8018CACC: lwc1        $f4, 0x54($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X54);
    // 0x8018CAD0: mul.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x8018CAD4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8018CAD8: swc1        $f8, 0x54($t4)
    MEM_W(0X54, ctx->r12) = ctx->f8.u32l;
    // 0x8018CADC: lwc1        $f10, 0x58($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X58);
    // 0x8018CAE0: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8018CAE4: mul.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x8018CAE8: swc1        $f18, 0x58($t5)
    MEM_W(0X58, ctx->r13) = ctx->f18.u32l;
    // 0x8018CAEC: lw          $a3, 0x50($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X50);
    // 0x8018CAF0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8018CAF4: lwc1        $f16, 0x58($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X58);
    // 0x8018CAF8: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x8018CAFC: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x8018CB00: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x8018CB04: jal         0x8018C704
    // 0x8018CB08: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    func_8018C704_1501A0(rdram, ctx);
        goto after_3;
    // 0x8018CB08: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    after_3:
    // 0x8018CB0C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8018CB10: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x8018CB14: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8018CB18: swc1        $f0, 0x80($t0)
    MEM_W(0X80, ctx->r8) = ctx->f0.u32l;
    // 0x8018CB1C: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x8018CB20: lwc1        $f8, 0x5C($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X5C);
    // 0x8018CB24: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8018CB28: nop

    // 0x8018CB2C: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x8018CB30: nop

    // 0x8018CB34: bc1f        L_8018CB74
    if (!c1cs) {
        // 0x8018CB38: nop
    
            goto L_8018CB74;
    }
    // 0x8018CB38: nop

    // 0x8018CB3C: lwc1        $f6, 0x60($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X60);
    // 0x8018CB40: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8018CB44: nop

    // 0x8018CB48: c.eq.s      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.fl == ctx->f18.fl;
    // 0x8018CB4C: nop

    // 0x8018CB50: bc1f        L_8018CB74
    if (!c1cs) {
        // 0x8018CB54: nop
    
            goto L_8018CB74;
    }
    // 0x8018CB54: nop

    // 0x8018CB58: lwc1        $f4, 0x64($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X64);
    // 0x8018CB5C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8018CB60: nop

    // 0x8018CB64: c.eq.s      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.fl == ctx->f16.fl;
    // 0x8018CB68: nop

    // 0x8018CB6C: bc1t        L_8018CB98
    if (c1cs) {
        // 0x8018CB70: nop
    
            goto L_8018CB98;
    }
    // 0x8018CB70: nop

L_8018CB74:
    // 0x8018CB74: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8018CB78: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x8018CB7C: lwc1        $f8, 0x64($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X64);
    // 0x8018CB80: lw          $a1, 0x80($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X80);
    // 0x8018CB84: lw          $a2, 0x5C($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X5C);
    // 0x8018CB88: lw          $a3, 0x60($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X60);
    // 0x8018CB8C: addiu       $a0, $sp, 0x78
    ctx->r4 = ADD32(ctx->r29, 0X78);
    // 0x8018CB90: jal         0x800D7120
    // 0x8018CB94: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    guAlignF_recomp(rdram, ctx);
        goto after_4;
    // 0x8018CB94: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_4:
L_8018CB98:
    // 0x8018CB98: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8018CB9C: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x8018CBA0: lwc1        $f10, 0x50($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X50);
    // 0x8018CBA4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8018CBA8: nop

    // 0x8018CBAC: c.eq.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl == ctx->f6.fl;
    // 0x8018CBB0: nop

    // 0x8018CBB4: bc1f        L_8018CC24
    if (!c1cs) {
        // 0x8018CBB8: nop
    
            goto L_8018CC24;
    }
    // 0x8018CBB8: nop

    // 0x8018CBBC: lwc1        $f18, 0x58($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X58);
    // 0x8018CBC0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8018CBC4: nop

    // 0x8018CBC8: c.eq.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl == ctx->f4.fl;
    // 0x8018CBCC: nop

    // 0x8018CBD0: bc1f        L_8018CC24
    if (!c1cs) {
        // 0x8018CBD4: nop
    
            goto L_8018CC24;
    }
    // 0x8018CBD4: nop

    // 0x8018CBD8: lwc1        $f16, 0x54($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X54);
    // 0x8018CBDC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8018CBE0: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8018CBE4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8018CBE8: addiu       $t4, $t3, 0x68
    ctx->r12 = ADD32(ctx->r11, 0X68);
    // 0x8018CBEC: addiu       $t5, $t3, 0x6C
    ctx->r13 = ADD32(ctx->r11, 0X6C);
    // 0x8018CBF0: addiu       $t7, $t3, 0x70
    ctx->r15 = ADD32(ctx->r11, 0X70);
    // 0x8018CBF4: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x8018CBF8: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x8018CBFC: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x8018CC00: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8018CC04: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x8018CC08: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x8018CC0C: jal         0x8018C704
    // 0x8018CC10: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    func_8018C704_1501A0(rdram, ctx);
        goto after_5;
    // 0x8018CC10: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_5:
    // 0x8018CC14: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8018CC18: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x8018CC1C: b           L_8018CC78
    // 0x8018CC20: swc1        $f0, 0x84($t8)
    MEM_W(0X84, ctx->r24) = ctx->f0.u32l;
        goto L_8018CC78;
    // 0x8018CC20: swc1        $f0, 0x84($t8)
    MEM_W(0X84, ctx->r24) = ctx->f0.u32l;
L_8018CC24:
    // 0x8018CC24: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8018CC28: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x8018CC2C: lwc1        $f10, 0x50($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X50);
    // 0x8018CC30: lwc1        $f6, 0x58($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X58);
    // 0x8018CC34: lwc1        $f18, 0x54($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X54);
    // 0x8018CC38: addiu       $t9, $t6, 0x68
    ctx->r25 = ADD32(ctx->r14, 0X68);
    // 0x8018CC3C: addiu       $t0, $t6, 0x6C
    ctx->r8 = ADD32(ctx->r14, 0X6C);
    // 0x8018CC40: addiu       $t1, $t6, 0x70
    ctx->r9 = ADD32(ctx->r14, 0X70);
    // 0x8018CC44: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8018CC48: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x8018CC4C: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8018CC50: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x8018CC54: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x8018CC58: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x8018CC5C: mov.s       $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = ctx->f10.fl;
    // 0x8018CC60: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8018CC64: jal         0x8018C704
    // 0x8018CC68: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_8018C704_1501A0(rdram, ctx);
        goto after_6;
    // 0x8018CC68: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_6:
    // 0x8018CC6C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8018CC70: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x8018CC74: swc1        $f0, 0x84($t2)
    MEM_W(0X84, ctx->r10) = ctx->f0.u32l;
L_8018CC78:
    // 0x8018CC78: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8018CC7C: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x8018CC80: lwc1        $f4, 0x68($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X68);
    // 0x8018CC84: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8018CC88: nop

    // 0x8018CC8C: c.eq.s      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.fl == ctx->f16.fl;
    // 0x8018CC90: nop

    // 0x8018CC94: bc1f        L_8018CCD4
    if (!c1cs) {
        // 0x8018CC98: nop
    
            goto L_8018CCD4;
    }
    // 0x8018CC98: nop

    // 0x8018CC9C: lwc1        $f8, 0x6C($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X6C);
    // 0x8018CCA0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8018CCA4: nop

    // 0x8018CCA8: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x8018CCAC: nop

    // 0x8018CCB0: bc1f        L_8018CCD4
    if (!c1cs) {
        // 0x8018CCB4: nop
    
            goto L_8018CCD4;
    }
    // 0x8018CCB4: nop

    // 0x8018CCB8: lwc1        $f18, 0x70($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X70);
    // 0x8018CCBC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8018CCC0: nop

    // 0x8018CCC4: c.eq.s      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.fl == ctx->f6.fl;
    // 0x8018CCC8: nop

    // 0x8018CCCC: bc1t        L_8018CCF8
    if (c1cs) {
        // 0x8018CCD0: nop
    
            goto L_8018CCF8;
    }
    // 0x8018CCD0: nop

L_8018CCD4:
    // 0x8018CCD4: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8018CCD8: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x8018CCDC: lwc1        $f4, 0x70($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X70);
    // 0x8018CCE0: lw          $a1, 0x84($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X84);
    // 0x8018CCE4: lw          $a2, 0x68($t5)
    ctx->r6 = MEM_W(ctx->r13, 0X68);
    // 0x8018CCE8: lw          $a3, 0x6C($t5)
    ctx->r7 = MEM_W(ctx->r13, 0X6C);
    // 0x8018CCEC: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x8018CCF0: jal         0x800D7120
    // 0x8018CCF4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    guAlignF_recomp(rdram, ctx);
        goto after_7;
    // 0x8018CCF4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_7:
L_8018CCF8:
    // 0x8018CCF8: addiu       $t3, $sp, 0x78
    ctx->r11 = ADD32(ctx->r29, 0X78);
    // 0x8018CCFC: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    // 0x8018CD00: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    // 0x8018CD04: jal         0x800D6F30
    // 0x8018CD08: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    guMtxCatF_recomp(rdram, ctx);
        goto after_8;
    // 0x8018CD08: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_8:
    // 0x8018CD0C: lw          $t7, 0xC0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC0);
    // 0x8018CD10: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8018CD14: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x8018CD18: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8018CD1C: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8018CD20: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8018CD24: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8018CD28: lwc1        $f16, 0x58($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X58);
    // 0x8018CD2C: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8018CD30: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8018CD34: addu        $a1, $a1, $t8
    ctx->r5 = ADD32(ctx->r5, ctx->r24);
    // 0x8018CD38: lw          $a2, 0x50($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X50);
    // 0x8018CD3C: lw          $a3, 0x54($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X54);
    // 0x8018CD40: lw          $a1, 0xFD0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0XFD0);
    // 0x8018CD44: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x8018CD48: jal         0x800D7120
    // 0x8018CD4C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    guAlignF_recomp(rdram, ctx);
        goto after_9;
    // 0x8018CD4C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_9:
    // 0x8018CD50: addiu       $t0, $sp, 0x78
    ctx->r8 = ADD32(ctx->r29, 0X78);
    // 0x8018CD54: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x8018CD58: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    // 0x8018CD5C: jal         0x800D6F30
    // 0x8018CD60: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    guMtxCatF_recomp(rdram, ctx);
        goto after_10;
    // 0x8018CD60: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_10:
L_8018CD64:
    // 0x8018CD64: lw          $t6, 0xC0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC0);
    // 0x8018CD68: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8018CD6C: addiu       $t2, $t2, 0xF98
    ctx->r10 = ADD32(ctx->r10, 0XF98);
    // 0x8018CD70: sll         $t1, $t6, 2
    ctx->r9 = S32(ctx->r14 << 2);
    // 0x8018CD74: subu        $t1, $t1, $t6
    ctx->r9 = SUB32(ctx->r9, ctx->r14);
    // 0x8018CD78: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8018CD7C: addu        $t1, $t1, $t6
    ctx->r9 = ADD32(ctx->r9, ctx->r14);
    // 0x8018CD80: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x8018CD84: addu        $t4, $t1, $t2
    ctx->r12 = ADD32(ctx->r9, ctx->r10);
    // 0x8018CD88: lwc1        $f8, 0x1C($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X1C);
    // 0x8018CD8C: lw          $a3, 0x18($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X18);
    // 0x8018CD90: lwc1        $f18, 0xC4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x8018CD94: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x8018CD98: lwc1        $f10, 0x20($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X20);
    // 0x8018CD9C: lw          $a0, 0xB8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB8);
    // 0x8018CDA0: lbu         $a1, 0xBF($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0XBF);
    // 0x8018CDA4: addiu       $a2, $sp, 0x78
    ctx->r6 = ADD32(ctx->r29, 0X78);
    // 0x8018CDA8: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    // 0x8018CDAC: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    // 0x8018CDB0: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    // 0x8018CDB4: jal         0x800C6868
    // 0x8018CDB8: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    func_800C6868(rdram, ctx);
        goto after_11;
    // 0x8018CDB8: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_11:
    // 0x8018CDBC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8018CDC0: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    // 0x8018CDC4: jr          $ra
    // 0x8018CDC8: nop

    return;
    // 0x8018CDC8: nop

;}
RECOMP_FUNC void func_8018CDCC_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018CDCC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8018CDD0: lw          $t6, -0x2E3C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2E3C);
    // 0x8018CDD4: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8018CDD8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8018CDDC: sltiu       $at, $t6, 0x2
    ctx->r1 = ctx->r14 < 0X2 ? 1 : 0;
    // 0x8018CDE0: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x8018CDE4: bne         $at, $zero, L_8018D520
    if (ctx->r1 != 0) {
        // 0x8018CDE8: sw          $a1, 0x5C($sp)
        MEM_W(0X5C, ctx->r29) = ctx->r5;
            goto L_8018D520;
    }
    // 0x8018CDE8: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x8018CDEC: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x8018CDF0: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8018CDF4: sltiu       $at, $t8, 0x6
    ctx->r1 = ctx->r24 < 0X6 ? 1 : 0;
    // 0x8018CDF8: beq         $at, $zero, L_8018D520
    if (ctx->r1 == 0) {
        // 0x8018CDFC: nop
    
            goto L_8018D520;
    }
    // 0x8018CDFC: nop

    // 0x8018CE00: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8018CE04: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018CE08: addu        $at, $at, $t8
    gpr jr_addend_8018CE10 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8018CE0C: lw          $t8, 0x1EC($at)
    ctx->r24 = ADD32(ctx->r1, 0X1EC);
    // 0x8018CE10: jr          $t8
    // 0x8018CE14: nop

    switch (jr_addend_8018CE10 >> 2) {
        case 0: goto L_8018CE18; break;
        case 1: goto L_8018CF44; break;
        case 2: goto L_8018D070; break;
        case 3: goto L_8018D19C; break;
        case 4: goto L_8018D2C8; break;
        case 5: goto L_8018D3F4; break;
        default: switch_error(__func__, 0x8018CE10, 0x801A01EC);
    }
    // 0x8018CE14: nop

L_8018CE18:
    // 0x8018CE18: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x8018CE1C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018CE20: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8018CE24: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x8018CE28: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8018CE2C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8018CE30: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x8018CE34: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x8018CE38: lwc1        $f4, 0xFCC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XFCC);
    // 0x8018CE3C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8018CE40: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018CE44: nop

    // 0x8018CE48: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8018CE4C: nop

    // 0x8018CE50: bc1f        L_8018CF3C
    if (!c1cs) {
        // 0x8018CE54: nop
    
            goto L_8018CF3C;
    }
    // 0x8018CE54: nop

    // 0x8018CE58: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x8018CE5C: lw          $t1, -0x4514($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4514);
    // 0x8018CE60: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8018CE64: lui         $t3, 0xDE00
    ctx->r11 = S32(0XDE00 << 16);
    // 0x8018CE68: sw          $t1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r9;
    // 0x8018CE6C: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x8018CE70: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x8018CE74: sw          $t2, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r10;
    // 0x8018CE78: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x8018CE7C: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x8018CE80: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x8018CE84: addiu       $t5, $t5, -0x67D8
    ctx->r13 = ADD32(ctx->r13, -0X67D8);
    // 0x8018CE88: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018CE8C: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x8018CE90: lwc1        $f8, 0x204($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X204);
    // 0x8018CE94: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018CE98: lwc1        $f10, -0x2E30($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x8018CE9C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8018CEA0: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x8018CEA4: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8018CEA8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8018CEAC: addiu       $t0, $t0, 0xF98
    ctx->r8 = ADD32(ctx->r8, 0XF98);
    // 0x8018CEB0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8018CEB4: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x8018CEB8: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8018CEBC: addiu       $a0, $a0, 0x6650
    ctx->r4 = ADD32(ctx->r4, 0X6650);
    // 0x8018CEC0: swc1        $f16, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f16.u32l;
    // 0x8018CEC4: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x8018CEC8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018CECC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8018CED0: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8018CED4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8018CED8: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8018CEDC: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x8018CEE0: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8018CEE4: lwc1        $f18, 0x20($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X20);
    // 0x8018CEE8: lw          $a2, 0x18($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X18);
    // 0x8018CEEC: lw          $a3, 0x1C($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X1C);
    // 0x8018CEF0: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x8018CEF4: lwc1        $f4, 0x0($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X0);
    // 0x8018CEF8: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x8018CEFC: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x8018CF00: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x8018CF04: lw          $t3, 0x10($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X10);
    // 0x8018CF08: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x8018CF0C: bgez        $t3, L_8018CF24
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8018CF10: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_8018CF24;
    }
    // 0x8018CF10: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8018CF14: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8018CF18: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018CF1C: nop

    // 0x8018CF20: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_8018CF24:
    // 0x8018CF24: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8018CF28: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8018CF2C: nop

    // 0x8018CF30: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8018CF34: jal         0x800C6144
    // 0x8018CF38: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    func_800C6144(rdram, ctx);
        goto after_0;
    // 0x8018CF38: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    after_0:
L_8018CF3C:
    // 0x8018CF3C: b           L_8018DB14
    // 0x8018CF40: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8018DB14;
    // 0x8018CF40: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8018CF44:
    // 0x8018CF44: lw          $t4, 0x5C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X5C);
    // 0x8018CF48: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018CF4C: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8018CF50: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x8018CF54: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8018CF58: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8018CF5C: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8018CF60: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x8018CF64: lwc1        $f4, 0xFCC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XFCC);
    // 0x8018CF68: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8018CF6C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018CF70: nop

    // 0x8018CF74: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8018CF78: nop

    // 0x8018CF7C: bc1f        L_8018D068
    if (!c1cs) {
        // 0x8018CF80: nop
    
            goto L_8018D068;
    }
    // 0x8018CF80: nop

    // 0x8018CF84: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x8018CF88: lw          $t6, -0x4514($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4514);
    // 0x8018CF8C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8018CF90: lui         $t8, 0xDE00
    ctx->r24 = S32(0XDE00 << 16);
    // 0x8018CF94: sw          $t6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r14;
    // 0x8018CF98: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x8018CF9C: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8018CFA0: sw          $t7, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r15;
    // 0x8018CFA4: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8018CFA8: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x8018CFAC: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x8018CFB0: addiu       $t0, $t0, -0x67D8
    ctx->r8 = ADD32(ctx->r8, -0X67D8);
    // 0x8018CFB4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018CFB8: sw          $t0, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r8;
    // 0x8018CFBC: lwc1        $f10, 0x208($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X208);
    // 0x8018CFC0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018CFC4: lwc1        $f8, -0x2E30($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x8018CFC8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8018CFCC: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x8018CFD0: mul.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8018CFD4: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8018CFD8: addiu       $t5, $t5, 0xF98
    ctx->r13 = ADD32(ctx->r13, 0XF98);
    // 0x8018CFDC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8018CFE0: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x8018CFE4: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8018CFE8: addiu       $a0, $a0, 0x66F0
    ctx->r4 = ADD32(ctx->r4, 0X66F0);
    // 0x8018CFEC: swc1        $f16, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f16.u32l;
    // 0x8018CFF0: lw          $t3, 0x5C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X5C);
    // 0x8018CFF4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018CFF8: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8018CFFC: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x8018D000: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8018D004: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8018D008: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x8018D00C: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x8018D010: lwc1        $f18, 0x20($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X20);
    // 0x8018D014: lw          $a2, 0x18($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X18);
    // 0x8018D018: lw          $a3, 0x1C($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X1C);
    // 0x8018D01C: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x8018D020: lwc1        $f4, 0x0($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X0);
    // 0x8018D024: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x8018D028: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x8018D02C: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x8018D030: lw          $t8, 0x10($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X10);
    // 0x8018D034: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x8018D038: bgez        $t8, L_8018D050
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8018D03C: cvt.s.w     $f10, $f6
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
            goto L_8018D050;
    }
    // 0x8018D03C: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8018D040: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8018D044: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018D048: nop

    // 0x8018D04C: add.s       $f10, $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f8.fl;
L_8018D050:
    // 0x8018D050: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8018D054: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8018D058: nop

    // 0x8018D05C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8018D060: jal         0x800C6144
    // 0x8018D064: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    func_800C6144(rdram, ctx);
        goto after_1;
    // 0x8018D064: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    after_1:
L_8018D068:
    // 0x8018D068: b           L_8018DB14
    // 0x8018D06C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8018DB14;
    // 0x8018D06C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8018D070:
    // 0x8018D070: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x8018D074: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018D078: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8018D07C: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x8018D080: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8018D084: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8018D088: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x8018D08C: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x8018D090: lwc1        $f4, 0xFCC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XFCC);
    // 0x8018D094: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8018D098: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018D09C: nop

    // 0x8018D0A0: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8018D0A4: nop

    // 0x8018D0A8: bc1f        L_8018D194
    if (!c1cs) {
        // 0x8018D0AC: nop
    
            goto L_8018D194;
    }
    // 0x8018D0AC: nop

    // 0x8018D0B0: lui         $t2, 0x8011
    ctx->r10 = S32(0X8011 << 16);
    // 0x8018D0B4: lw          $t2, -0x4514($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4514);
    // 0x8018D0B8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8018D0BC: lui         $t3, 0xDE00
    ctx->r11 = S32(0XDE00 << 16);
    // 0x8018D0C0: sw          $t2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r10;
    // 0x8018D0C4: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x8018D0C8: addiu       $t1, $t2, 0x8
    ctx->r9 = ADD32(ctx->r10, 0X8);
    // 0x8018D0CC: sw          $t1, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r9;
    // 0x8018D0D0: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x8018D0D4: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x8018D0D8: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x8018D0DC: addiu       $t5, $t5, -0x67D8
    ctx->r13 = ADD32(ctx->r13, -0X67D8);
    // 0x8018D0E0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018D0E4: sw          $t5, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r13;
    // 0x8018D0E8: lwc1        $f8, 0x20C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X20C);
    // 0x8018D0EC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018D0F0: lwc1        $f10, -0x2E30($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x8018D0F4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8018D0F8: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x8018D0FC: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8018D100: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8018D104: addiu       $t0, $t0, 0xF98
    ctx->r8 = ADD32(ctx->r8, 0XF98);
    // 0x8018D108: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8018D10C: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x8018D110: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8018D114: addiu       $a0, $a0, 0x6790
    ctx->r4 = ADD32(ctx->r4, 0X6790);
    // 0x8018D118: swc1        $f16, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f16.u32l;
    // 0x8018D11C: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x8018D120: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018D124: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8018D128: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8018D12C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8018D130: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8018D134: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x8018D138: addu        $t2, $t9, $t0
    ctx->r10 = ADD32(ctx->r25, ctx->r8);
    // 0x8018D13C: lwc1        $f18, 0x20($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X20);
    // 0x8018D140: lw          $a2, 0x18($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X18);
    // 0x8018D144: lw          $a3, 0x1C($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X1C);
    // 0x8018D148: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x8018D14C: lwc1        $f4, 0x0($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X0);
    // 0x8018D150: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x8018D154: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x8018D158: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x8018D15C: lw          $t3, 0x10($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X10);
    // 0x8018D160: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x8018D164: bgez        $t3, L_8018D17C
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8018D168: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_8018D17C;
    }
    // 0x8018D168: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8018D16C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8018D170: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018D174: nop

    // 0x8018D178: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_8018D17C:
    // 0x8018D17C: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8018D180: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8018D184: nop

    // 0x8018D188: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8018D18C: jal         0x800C6144
    // 0x8018D190: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    func_800C6144(rdram, ctx);
        goto after_2;
    // 0x8018D190: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    after_2:
L_8018D194:
    // 0x8018D194: b           L_8018DB14
    // 0x8018D198: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8018DB14;
    // 0x8018D198: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8018D19C:
    // 0x8018D19C: lw          $t4, 0x5C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X5C);
    // 0x8018D1A0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018D1A4: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8018D1A8: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x8018D1AC: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8018D1B0: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8018D1B4: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8018D1B8: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x8018D1BC: lwc1        $f4, 0xFCC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XFCC);
    // 0x8018D1C0: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8018D1C4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018D1C8: nop

    // 0x8018D1CC: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8018D1D0: nop

    // 0x8018D1D4: bc1f        L_8018D2C0
    if (!c1cs) {
        // 0x8018D1D8: nop
    
            goto L_8018D2C0;
    }
    // 0x8018D1D8: nop

    // 0x8018D1DC: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x8018D1E0: lw          $t7, -0x4514($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4514);
    // 0x8018D1E4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8018D1E8: lui         $t8, 0xDE00
    ctx->r24 = S32(0XDE00 << 16);
    // 0x8018D1EC: sw          $t7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r15;
    // 0x8018D1F0: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x8018D1F4: addiu       $t6, $t7, 0x8
    ctx->r14 = ADD32(ctx->r15, 0X8);
    // 0x8018D1F8: sw          $t6, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r14;
    // 0x8018D1FC: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8018D200: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x8018D204: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x8018D208: addiu       $t0, $t0, -0x67D8
    ctx->r8 = ADD32(ctx->r8, -0X67D8);
    // 0x8018D20C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018D210: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x8018D214: lwc1        $f10, 0x210($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X210);
    // 0x8018D218: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018D21C: lwc1        $f8, -0x2E30($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x8018D220: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8018D224: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x8018D228: mul.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8018D22C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8018D230: addiu       $t5, $t5, 0xF98
    ctx->r13 = ADD32(ctx->r13, 0XF98);
    // 0x8018D234: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8018D238: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x8018D23C: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8018D240: addiu       $a0, $a0, 0x6830
    ctx->r4 = ADD32(ctx->r4, 0X6830);
    // 0x8018D244: swc1        $f16, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f16.u32l;
    // 0x8018D248: lw          $t3, 0x5C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X5C);
    // 0x8018D24C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018D250: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8018D254: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x8018D258: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8018D25C: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8018D260: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x8018D264: addu        $t7, $t4, $t5
    ctx->r15 = ADD32(ctx->r12, ctx->r13);
    // 0x8018D268: lwc1        $f18, 0x20($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0X20);
    // 0x8018D26C: lw          $a2, 0x18($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X18);
    // 0x8018D270: lw          $a3, 0x1C($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X1C);
    // 0x8018D274: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x8018D278: lwc1        $f4, 0x0($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X0);
    // 0x8018D27C: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x8018D280: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x8018D284: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x8018D288: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x8018D28C: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x8018D290: bgez        $t8, L_8018D2A8
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8018D294: cvt.s.w     $f10, $f6
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
            goto L_8018D2A8;
    }
    // 0x8018D294: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8018D298: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8018D29C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018D2A0: nop

    // 0x8018D2A4: add.s       $f10, $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f8.fl;
L_8018D2A8:
    // 0x8018D2A8: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8018D2AC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8018D2B0: nop

    // 0x8018D2B4: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8018D2B8: jal         0x800C6144
    // 0x8018D2BC: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    func_800C6144(rdram, ctx);
        goto after_3;
    // 0x8018D2BC: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    after_3:
L_8018D2C0:
    // 0x8018D2C0: b           L_8018DB14
    // 0x8018D2C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8018DB14;
    // 0x8018D2C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8018D2C8:
    // 0x8018D2C8: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x8018D2CC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018D2D0: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8018D2D4: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x8018D2D8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8018D2DC: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8018D2E0: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x8018D2E4: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x8018D2E8: lwc1        $f4, 0xFCC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XFCC);
    // 0x8018D2EC: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8018D2F0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018D2F4: nop

    // 0x8018D2F8: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8018D2FC: nop

    // 0x8018D300: bc1f        L_8018D3EC
    if (!c1cs) {
        // 0x8018D304: nop
    
            goto L_8018D3EC;
    }
    // 0x8018D304: nop

    // 0x8018D308: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x8018D30C: lw          $t1, -0x4514($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4514);
    // 0x8018D310: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8018D314: lui         $t3, 0xDE00
    ctx->r11 = S32(0XDE00 << 16);
    // 0x8018D318: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    // 0x8018D31C: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x8018D320: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x8018D324: sw          $t2, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r10;
    // 0x8018D328: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x8018D32C: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x8018D330: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x8018D334: addiu       $t5, $t5, -0x67D8
    ctx->r13 = ADD32(ctx->r13, -0X67D8);
    // 0x8018D338: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018D33C: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x8018D340: lwc1        $f8, 0x214($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X214);
    // 0x8018D344: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018D348: lwc1        $f10, -0x2E30($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x8018D34C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8018D350: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x8018D354: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8018D358: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8018D35C: addiu       $t0, $t0, 0xF98
    ctx->r8 = ADD32(ctx->r8, 0XF98);
    // 0x8018D360: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8018D364: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x8018D368: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8018D36C: addiu       $a0, $a0, 0x68D0
    ctx->r4 = ADD32(ctx->r4, 0X68D0);
    // 0x8018D370: swc1        $f16, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f16.u32l;
    // 0x8018D374: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x8018D378: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018D37C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8018D380: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8018D384: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8018D388: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8018D38C: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x8018D390: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8018D394: lwc1        $f18, 0x20($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X20);
    // 0x8018D398: lw          $a2, 0x18($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X18);
    // 0x8018D39C: lw          $a3, 0x1C($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X1C);
    // 0x8018D3A0: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x8018D3A4: lwc1        $f4, 0x0($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X0);
    // 0x8018D3A8: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x8018D3AC: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x8018D3B0: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x8018D3B4: lw          $t3, 0x10($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X10);
    // 0x8018D3B8: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x8018D3BC: bgez        $t3, L_8018D3D4
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8018D3C0: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_8018D3D4;
    }
    // 0x8018D3C0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8018D3C4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8018D3C8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018D3CC: nop

    // 0x8018D3D0: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_8018D3D4:
    // 0x8018D3D4: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8018D3D8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8018D3DC: nop

    // 0x8018D3E0: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8018D3E4: jal         0x800C6144
    // 0x8018D3E8: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    func_800C6144(rdram, ctx);
        goto after_4;
    // 0x8018D3E8: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    after_4:
L_8018D3EC:
    // 0x8018D3EC: b           L_8018DB14
    // 0x8018D3F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8018DB14;
    // 0x8018D3F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8018D3F4:
    // 0x8018D3F4: lw          $t4, 0x5C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X5C);
    // 0x8018D3F8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018D3FC: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8018D400: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x8018D404: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8018D408: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8018D40C: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8018D410: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x8018D414: lwc1        $f4, 0xFCC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XFCC);
    // 0x8018D418: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8018D41C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018D420: nop

    // 0x8018D424: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8018D428: nop

    // 0x8018D42C: bc1f        L_8018D518
    if (!c1cs) {
        // 0x8018D430: nop
    
            goto L_8018D518;
    }
    // 0x8018D430: nop

    // 0x8018D434: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x8018D438: lw          $t6, -0x4514($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4514);
    // 0x8018D43C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8018D440: lui         $t8, 0xDE00
    ctx->r24 = S32(0XDE00 << 16);
    // 0x8018D444: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    // 0x8018D448: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x8018D44C: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8018D450: sw          $t7, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r15;
    // 0x8018D454: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8018D458: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x8018D45C: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x8018D460: addiu       $t0, $t0, -0x67D8
    ctx->r8 = ADD32(ctx->r8, -0X67D8);
    // 0x8018D464: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018D468: sw          $t0, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r8;
    // 0x8018D46C: lwc1        $f10, 0x218($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X218);
    // 0x8018D470: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018D474: lwc1        $f8, -0x2E30($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x8018D478: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8018D47C: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x8018D480: mul.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8018D484: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8018D488: addiu       $t5, $t5, 0xF98
    ctx->r13 = ADD32(ctx->r13, 0XF98);
    // 0x8018D48C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8018D490: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x8018D494: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8018D498: addiu       $a0, $a0, 0x6970
    ctx->r4 = ADD32(ctx->r4, 0X6970);
    // 0x8018D49C: swc1        $f16, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f16.u32l;
    // 0x8018D4A0: lw          $t3, 0x5C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X5C);
    // 0x8018D4A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018D4A8: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8018D4AC: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x8018D4B0: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8018D4B4: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8018D4B8: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x8018D4BC: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x8018D4C0: lwc1        $f18, 0x20($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X20);
    // 0x8018D4C4: lw          $a2, 0x18($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X18);
    // 0x8018D4C8: lw          $a3, 0x1C($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X1C);
    // 0x8018D4CC: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x8018D4D0: lwc1        $f4, 0x0($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X0);
    // 0x8018D4D4: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x8018D4D8: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x8018D4DC: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x8018D4E0: lw          $t8, 0x10($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X10);
    // 0x8018D4E4: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x8018D4E8: bgez        $t8, L_8018D500
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8018D4EC: cvt.s.w     $f10, $f6
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
            goto L_8018D500;
    }
    // 0x8018D4EC: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8018D4F0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8018D4F4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018D4F8: nop

    // 0x8018D4FC: add.s       $f10, $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f8.fl;
L_8018D500:
    // 0x8018D500: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8018D504: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8018D508: nop

    // 0x8018D50C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8018D510: jal         0x800C6144
    // 0x8018D514: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    func_800C6144(rdram, ctx);
        goto after_5;
    // 0x8018D514: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    after_5:
L_8018D518:
    // 0x8018D518: b           L_8018DB14
    // 0x8018D51C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8018DB14;
    // 0x8018D51C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8018D520:
    // 0x8018D520: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x8018D524: addiu       $t0, $t9, -0xA
    ctx->r8 = ADD32(ctx->r25, -0XA);
    // 0x8018D528: sltiu       $at, $t0, 0x5
    ctx->r1 = ctx->r8 < 0X5 ? 1 : 0;
    // 0x8018D52C: beq         $at, $zero, L_8018DB10
    if (ctx->r1 == 0) {
        // 0x8018D530: nop
    
            goto L_8018DB10;
    }
    // 0x8018D530: nop

    // 0x8018D534: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8018D538: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018D53C: addu        $at, $at, $t0
    gpr jr_addend_8018D544 = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x8018D540: lw          $t0, 0x21C($at)
    ctx->r8 = ADD32(ctx->r1, 0X21C);
    // 0x8018D544: jr          $t0
    // 0x8018D548: nop

    switch (jr_addend_8018D544 >> 2) {
        case 0: goto L_8018D54C; break;
        case 1: goto L_8018D808; break;
        case 2: goto L_8018D6A4; break;
        case 3: goto L_8018DA1C; break;
        case 4: goto L_8018D92C; break;
        default: switch_error(__func__, 0x8018D544, 0x801A021C);
    }
    // 0x8018D548: nop

L_8018D54C:
    // 0x8018D54C: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x8018D550: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018D554: sll         $t1, $t2, 2
    ctx->r9 = S32(ctx->r10 << 2);
    // 0x8018D558: subu        $t1, $t1, $t2
    ctx->r9 = SUB32(ctx->r9, ctx->r10);
    // 0x8018D55C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8018D560: addu        $t1, $t1, $t2
    ctx->r9 = ADD32(ctx->r9, ctx->r10);
    // 0x8018D564: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x8018D568: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8018D56C: lwc1        $f4, 0xFCC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XFCC);
    // 0x8018D570: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8018D574: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018D578: nop

    // 0x8018D57C: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8018D580: nop

    // 0x8018D584: bc1f        L_8018D69C
    if (!c1cs) {
        // 0x8018D588: lui         $at, 0x801A
        ctx->r1 = S32(0X801A << 16);
            goto L_8018D69C;
    }
    // 0x8018D588: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018D58C: lwc1        $f8, 0x230($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X230);
    // 0x8018D590: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018D594: lwc1        $f10, -0x2E30($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x8018D598: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8018D59C: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x8018D5A0: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8018D5A4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018D5A8: swc1        $f16, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f16.u32l;
    // 0x8018D5AC: lw          $t4, 0x5C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X5C);
    // 0x8018D5B0: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8018D5B4: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x8018D5B8: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8018D5BC: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8018D5C0: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8018D5C4: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x8018D5C8: lwc1        $f18, 0xFCC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0XFCC);
    // 0x8018D5CC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018D5D0: lwc1        $f4, -0x2C1C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2C1C);
    // 0x8018D5D4: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x8018D5D8: nop

    // 0x8018D5DC: bc1f        L_8018D610
    if (!c1cs) {
        // 0x8018D5E0: nop
    
            goto L_8018D610;
    }
    // 0x8018D5E0: nop

    // 0x8018D5E4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8018D5E8: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x8018D5EC: lw          $a3, 0x0($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X0);
    // 0x8018D5F0: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8018D5F4: addiu       $a0, $a0, 0x6AE8
    ctx->r4 = ADD32(ctx->r4, 0X6AE8);
    // 0x8018D5F8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8018D5FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018D600: jal         0x8018C870
    // 0x8018D604: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    func_8018C870_1501A0(rdram, ctx);
        goto after_6;
    // 0x8018D604: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    after_6:
    // 0x8018D608: b           L_8018D69C
    // 0x8018D60C: nop

        goto L_8018D69C;
    // 0x8018D60C: nop

L_8018D610:
    // 0x8018D610: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x8018D614: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018D618: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x8018D61C: subu        $t8, $t8, $t6
    ctx->r24 = SUB32(ctx->r24, ctx->r14);
    // 0x8018D620: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8018D624: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x8018D628: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8018D62C: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8018D630: lwc1        $f6, 0xFCC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0XFCC);
    // 0x8018D634: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018D638: lwc1        $f8, -0x2C18($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2C18);
    // 0x8018D63C: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x8018D640: nop

    // 0x8018D644: bc1f        L_8018D678
    if (!c1cs) {
        // 0x8018D648: nop
    
            goto L_8018D678;
    }
    // 0x8018D648: nop

    // 0x8018D64C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8018D650: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x8018D654: lw          $a3, 0x0($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X0);
    // 0x8018D658: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8018D65C: addiu       $a0, $a0, 0x6B38
    ctx->r4 = ADD32(ctx->r4, 0X6B38);
    // 0x8018D660: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8018D664: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018D668: jal         0x8018C870
    // 0x8018D66C: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    func_8018C870_1501A0(rdram, ctx);
        goto after_7;
    // 0x8018D66C: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    after_7:
    // 0x8018D670: b           L_8018D69C
    // 0x8018D674: nop

        goto L_8018D69C;
    // 0x8018D674: nop

L_8018D678:
    // 0x8018D678: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8018D67C: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x8018D680: lw          $a3, 0x0($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X0);
    // 0x8018D684: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8018D688: addiu       $a0, $a0, 0x4F18
    ctx->r4 = ADD32(ctx->r4, 0X4F18);
    // 0x8018D68C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8018D690: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018D694: jal         0x8018C870
    // 0x8018D698: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    func_8018C870_1501A0(rdram, ctx);
        goto after_8;
    // 0x8018D698: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    after_8:
L_8018D69C:
    // 0x8018D69C: b           L_8018DB14
    // 0x8018D6A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8018DB14;
    // 0x8018D6A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8018D6A4:
    // 0x8018D6A4: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x8018D6A8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018D6AC: sll         $t1, $t2, 2
    ctx->r9 = S32(ctx->r10 << 2);
    // 0x8018D6B0: subu        $t1, $t1, $t2
    ctx->r9 = SUB32(ctx->r9, ctx->r10);
    // 0x8018D6B4: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8018D6B8: addu        $t1, $t1, $t2
    ctx->r9 = ADD32(ctx->r9, ctx->r10);
    // 0x8018D6BC: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x8018D6C0: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8018D6C4: lwc1        $f10, 0xFCC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0XFCC);
    // 0x8018D6C8: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8018D6CC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8018D6D0: nop

    // 0x8018D6D4: c.le.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl <= ctx->f10.fl;
    // 0x8018D6D8: nop

    // 0x8018D6DC: bc1f        L_8018D800
    if (!c1cs) {
        // 0x8018D6E0: lui         $at, 0x801A
        ctx->r1 = S32(0X801A << 16);
            goto L_8018D800;
    }
    // 0x8018D6E0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018D6E4: lwc1        $f18, 0x234($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X234);
    // 0x8018D6E8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018D6EC: lwc1        $f4, -0x2E30($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x8018D6F0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8018D6F4: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x8018D6F8: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8018D6FC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018D700: swc1        $f6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f6.u32l;
    // 0x8018D704: lw          $t5, 0x5C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X5C);
    // 0x8018D708: sll         $t4, $t5, 2
    ctx->r12 = S32(ctx->r13 << 2);
    // 0x8018D70C: subu        $t4, $t4, $t5
    ctx->r12 = SUB32(ctx->r12, ctx->r13);
    // 0x8018D710: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8018D714: addu        $t4, $t4, $t5
    ctx->r12 = ADD32(ctx->r12, ctx->r13);
    // 0x8018D718: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x8018D71C: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x8018D720: lwc1        $f8, 0xFCC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0XFCC);
    // 0x8018D724: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018D728: lwc1        $f10, -0x2C1C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2C1C);
    // 0x8018D72C: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x8018D730: nop

    // 0x8018D734: bc1f        L_8018D76C
    if (!c1cs) {
        // 0x8018D738: nop
    
            goto L_8018D76C;
    }
    // 0x8018D738: nop

    // 0x8018D73C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8018D740: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x8018D744: lw          $a3, 0x0($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X0);
    // 0x8018D748: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8018D74C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8018D750: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8018D754: addiu       $a0, $a0, 0x6B10
    ctx->r4 = ADD32(ctx->r4, 0X6B10);
    // 0x8018D758: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018D75C: jal         0x8018C870
    // 0x8018D760: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
    func_8018C870_1501A0(rdram, ctx);
        goto after_9;
    // 0x8018D760: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
    after_9:
    // 0x8018D764: b           L_8018D800
    // 0x8018D768: nop

        goto L_8018D800;
    // 0x8018D768: nop

L_8018D76C:
    // 0x8018D76C: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x8018D770: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018D774: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x8018D778: subu        $t9, $t9, $t6
    ctx->r25 = SUB32(ctx->r25, ctx->r14);
    // 0x8018D77C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8018D780: addu        $t9, $t9, $t6
    ctx->r25 = ADD32(ctx->r25, ctx->r14);
    // 0x8018D784: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x8018D788: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8018D78C: lwc1        $f16, 0xFCC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0XFCC);
    // 0x8018D790: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018D794: lwc1        $f18, -0x2C18($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2C18);
    // 0x8018D798: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x8018D79C: nop

    // 0x8018D7A0: bc1f        L_8018D7D8
    if (!c1cs) {
        // 0x8018D7A4: nop
    
            goto L_8018D7D8;
    }
    // 0x8018D7A4: nop

    // 0x8018D7A8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8018D7AC: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x8018D7B0: lw          $a3, 0x0($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X0);
    // 0x8018D7B4: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8018D7B8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8018D7BC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8018D7C0: addiu       $a0, $a0, 0x6B60
    ctx->r4 = ADD32(ctx->r4, 0X6B60);
    // 0x8018D7C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018D7C8: jal         0x8018C870
    // 0x8018D7CC: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    func_8018C870_1501A0(rdram, ctx);
        goto after_10;
    // 0x8018D7CC: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    after_10:
    // 0x8018D7D0: b           L_8018D800
    // 0x8018D7D4: nop

        goto L_8018D800;
    // 0x8018D7D4: nop

L_8018D7D8:
    // 0x8018D7D8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8018D7DC: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x8018D7E0: lw          $a3, 0x0($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X0);
    // 0x8018D7E4: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8018D7E8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8018D7EC: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8018D7F0: addiu       $a0, $a0, 0x5538
    ctx->r4 = ADD32(ctx->r4, 0X5538);
    // 0x8018D7F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018D7F8: jal         0x8018C870
    // 0x8018D7FC: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    func_8018C870_1501A0(rdram, ctx);
        goto after_11;
    // 0x8018D7FC: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    after_11:
L_8018D800:
    // 0x8018D800: b           L_8018DB14
    // 0x8018D804: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8018DB14;
    // 0x8018D804: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8018D808:
    // 0x8018D808: lw          $t4, 0x5C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X5C);
    // 0x8018D80C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018D810: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8018D814: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x8018D818: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8018D81C: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8018D820: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8018D824: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x8018D828: lwc1        $f4, 0xFCC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XFCC);
    // 0x8018D82C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8018D830: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018D834: nop

    // 0x8018D838: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8018D83C: nop

    // 0x8018D840: bc1f        L_8018D924
    if (!c1cs) {
        // 0x8018D844: nop
    
            goto L_8018D924;
    }
    // 0x8018D844: nop

    // 0x8018D848: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x8018D84C: lw          $t7, -0x4514($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4514);
    // 0x8018D850: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8018D854: lui         $t9, 0xDE00
    ctx->r25 = S32(0XDE00 << 16);
    // 0x8018D858: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x8018D85C: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8018D860: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8018D864: sw          $t8, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r24;
    // 0x8018D868: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x8018D86C: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x8018D870: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x8018D874: addiu       $t0, $t0, -0x6710
    ctx->r8 = ADD32(ctx->r8, -0X6710);
    // 0x8018D878: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018D87C: sw          $t0, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r8;
    // 0x8018D880: lwc1        $f8, 0x238($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X238);
    // 0x8018D884: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018D888: lwc1        $f10, -0x2E30($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x8018D88C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8018D890: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x8018D894: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8018D898: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8018D89C: addiu       $t5, $t5, 0xF98
    ctx->r13 = ADD32(ctx->r13, 0XF98);
    // 0x8018D8A0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8018D8A4: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x8018D8A8: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8018D8AC: addiu       $a0, $a0, 0x6598
    ctx->r4 = ADD32(ctx->r4, 0X6598);
    // 0x8018D8B0: swc1        $f16, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f16.u32l;
    // 0x8018D8B4: lw          $t3, 0x5C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X5C);
    // 0x8018D8B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018D8BC: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8018D8C0: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x8018D8C4: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8018D8C8: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8018D8CC: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x8018D8D0: addu        $t7, $t4, $t5
    ctx->r15 = ADD32(ctx->r12, ctx->r13);
    // 0x8018D8D4: lwc1        $f18, 0x20($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0X20);
    // 0x8018D8D8: lw          $a2, 0x18($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X18);
    // 0x8018D8DC: lw          $a3, 0x1C($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X1C);
    // 0x8018D8E0: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x8018D8E4: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    // 0x8018D8E8: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x8018D8EC: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x8018D8F0: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x8018D8F4: lwc1        $f6, 0x38($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X38);
    // 0x8018D8F8: jal         0x800C6144
    // 0x8018D8FC: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    func_800C6144(rdram, ctx);
        goto after_12;
    // 0x8018D8FC: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    after_12:
    // 0x8018D900: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8018D904: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x8018D908: lw          $a3, 0x0($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X0);
    // 0x8018D90C: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8018D910: addiu       $a0, $a0, 0x6550
    ctx->r4 = ADD32(ctx->r4, 0X6550);
    // 0x8018D914: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8018D918: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018D91C: jal         0x8018C870
    // 0x8018D920: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    func_8018C870_1501A0(rdram, ctx);
        goto after_13;
    // 0x8018D920: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    after_13:
L_8018D924:
    // 0x8018D924: b           L_8018DB14
    // 0x8018D928: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8018DB14;
    // 0x8018D928: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8018D92C:
    // 0x8018D92C: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x8018D930: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018D934: sll         $t0, $t6, 2
    ctx->r8 = S32(ctx->r14 << 2);
    // 0x8018D938: subu        $t0, $t0, $t6
    ctx->r8 = SUB32(ctx->r8, ctx->r14);
    // 0x8018D93C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8018D940: addu        $t0, $t0, $t6
    ctx->r8 = ADD32(ctx->r8, ctx->r14);
    // 0x8018D944: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x8018D948: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x8018D94C: lwc1        $f8, 0xFCC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0XFCC);
    // 0x8018D950: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8018D954: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018D958: nop

    // 0x8018D95C: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x8018D960: nop

    // 0x8018D964: bc1f        L_8018DA14
    if (!c1cs) {
        // 0x8018D968: lui         $at, 0x801A
        ctx->r1 = S32(0X801A << 16);
            goto L_8018DA14;
    }
    // 0x8018D968: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018D96C: lwc1        $f16, 0x23C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X23C);
    // 0x8018D970: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018D974: lwc1        $f18, -0x2E30($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x8018D978: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8018D97C: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x8018D980: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8018D984: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x8018D988: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8018D98C: lui         $t4, 0xDE00
    ctx->r12 = S32(0XDE00 << 16);
    // 0x8018D990: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x8018D994: addiu       $t8, $t8, -0x6710
    ctx->r24 = ADD32(ctx->r24, -0X6710);
    // 0x8018D998: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x8018D99C: swc1        $f4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f4.u32l;
    // 0x8018D9A0: lw          $t1, -0x4514($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4514);
    // 0x8018D9A4: lui         $t0, 0xFA00
    ctx->r8 = S32(0XFA00 << 16);
    // 0x8018D9A8: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8018D9AC: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x8018D9B0: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x8018D9B4: addiu       $t3, $t1, 0x8
    ctx->r11 = ADD32(ctx->r9, 0X8);
    // 0x8018D9B8: sw          $t3, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r11;
    // 0x8018D9BC: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x8018D9C0: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8018D9C4: lui         $t1, 0x8080
    ctx->r9 = S32(0X8080 << 16);
    // 0x8018D9C8: ori         $t1, $t1, 0xFFFF
    ctx->r9 = ctx->r9 | 0XFFFF;
    // 0x8018D9CC: sw          $t8, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r24;
    // 0x8018D9D0: lw          $t9, -0x4514($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4514);
    // 0x8018D9D4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8018D9D8: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x8018D9DC: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x8018D9E0: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x8018D9E4: addiu       $t6, $t9, 0x8
    ctx->r14 = ADD32(ctx->r25, 0X8);
    // 0x8018D9E8: sw          $t6, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r14;
    // 0x8018D9EC: sw          $t0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r8;
    // 0x8018D9F0: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x8018D9F4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8018D9F8: addiu       $a0, $a0, 0x6188
    ctx->r4 = ADD32(ctx->r4, 0X6188);
    // 0x8018D9FC: sw          $t1, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r9;
    // 0x8018DA00: lw          $a3, 0x0($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X0);
    // 0x8018DA04: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8018DA08: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    // 0x8018DA0C: jal         0x8018C870
    // 0x8018DA10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8018C870_1501A0(rdram, ctx);
        goto after_14;
    // 0x8018DA10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_14:
L_8018DA14:
    // 0x8018DA14: b           L_8018DB14
    // 0x8018DA18: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8018DB14;
    // 0x8018DA18: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8018DA1C:
    // 0x8018DA1C: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x8018DA20: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018DA24: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x8018DA28: subu        $t7, $t7, $t8
    ctx->r15 = SUB32(ctx->r15, ctx->r24);
    // 0x8018DA2C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8018DA30: addu        $t7, $t7, $t8
    ctx->r15 = ADD32(ctx->r15, ctx->r24);
    // 0x8018DA34: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8018DA38: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8018DA3C: lwc1        $f6, 0xFCC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0XFCC);
    // 0x8018DA40: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8018DA44: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018DA48: nop

    // 0x8018DA4C: c.le.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl <= ctx->f6.fl;
    // 0x8018DA50: nop

    // 0x8018DA54: bc1f        L_8018DB08
    if (!c1cs) {
        // 0x8018DA58: lui         $at, 0x801A
        ctx->r1 = S32(0X801A << 16);
            goto L_8018DB08;
    }
    // 0x8018DA58: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018DA5C: lwc1        $f10, 0x240($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X240);
    // 0x8018DA60: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018DA64: lwc1        $f16, -0x2E30($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x8018DA68: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8018DA6C: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x8018DA70: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8018DA74: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x8018DA78: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8018DA7C: lui         $t2, 0xDE00
    ctx->r10 = S32(0XDE00 << 16);
    // 0x8018DA80: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x8018DA84: addiu       $t3, $t3, -0x6710
    ctx->r11 = ADD32(ctx->r11, -0X6710);
    // 0x8018DA88: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8018DA8C: swc1        $f18, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f18.u32l;
    // 0x8018DA90: lw          $t6, -0x4514($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4514);
    // 0x8018DA94: addiu       $t7, $t7, 0xF98
    ctx->r15 = ADD32(ctx->r15, 0XF98);
    // 0x8018DA98: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8018DA9C: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x8018DAA0: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8018DAA4: addiu       $t0, $t6, 0x8
    ctx->r8 = ADD32(ctx->r14, 0X8);
    // 0x8018DAA8: sw          $t0, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r8;
    // 0x8018DAAC: sw          $t2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r10;
    // 0x8018DAB0: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x8018DAB4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8018DAB8: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x8018DABC: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    // 0x8018DAC0: lw          $t5, 0x5C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X5C);
    // 0x8018DAC4: addiu       $a0, $a0, 0x6A10
    ctx->r4 = ADD32(ctx->r4, 0X6A10);
    // 0x8018DAC8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018DACC: sll         $t8, $t5, 2
    ctx->r24 = S32(ctx->r13 << 2);
    // 0x8018DAD0: subu        $t8, $t8, $t5
    ctx->r24 = SUB32(ctx->r24, ctx->r13);
    // 0x8018DAD4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8018DAD8: addu        $t8, $t8, $t5
    ctx->r24 = ADD32(ctx->r24, ctx->r13);
    // 0x8018DADC: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8018DAE0: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x8018DAE4: lwc1        $f4, 0x20($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X20);
    // 0x8018DAE8: lw          $a2, 0x18($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X18);
    // 0x8018DAEC: lw          $a3, 0x1C($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X1C);
    // 0x8018DAF0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8018DAF4: lwc1        $f6, 0x0($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X0);
    // 0x8018DAF8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8018DAFC: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x8018DB00: jal         0x800C60A0
    // 0x8018DB04: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    func_800C60A0(rdram, ctx);
        goto after_15;
    // 0x8018DB04: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    after_15:
L_8018DB08:
    // 0x8018DB08: b           L_8018DB14
    // 0x8018DB0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8018DB14;
    // 0x8018DB0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8018DB10:
    // 0x8018DB10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8018DB14:
    // 0x8018DB14: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8018DB18: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x8018DB1C: jr          $ra
    // 0x8018DB20: nop

    return;
    // 0x8018DB20: nop

;}
RECOMP_FUNC void func_8018DB24_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DB24: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8018DB28: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8018DB2C: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8018DB30: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8018DB34: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8018DB38: addiu       $t7, $t6, -0x1E
    ctx->r15 = ADD32(ctx->r14, -0X1E);
    // 0x8018DB3C: sltiu       $at, $t7, 0x26
    ctx->r1 = ctx->r15 < 0X26 ? 1 : 0;
    // 0x8018DB40: beq         $at, $zero, L_8018E084
    if (ctx->r1 == 0) {
        // 0x8018DB44: nop
    
            goto L_8018E084;
    }
    // 0x8018DB44: nop

    // 0x8018DB48: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8018DB4C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018DB50: addu        $at, $at, $t7
    gpr jr_addend_8018DB58 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8018DB54: lw          $t7, 0x244($at)
    ctx->r15 = ADD32(ctx->r1, 0X244);
    // 0x8018DB58: jr          $t7
    // 0x8018DB5C: nop

    switch (jr_addend_8018DB58 >> 2) {
        case 0: goto L_8018DB60; break;
        case 1: goto L_8018DC18; break;
        case 2: goto L_8018DCD0; break;
        case 3: goto L_8018DD88; break;
        case 4: goto L_8018E084; break;
        case 5: goto L_8018E084; break;
        case 6: goto L_8018E084; break;
        case 7: goto L_8018E084; break;
        case 8: goto L_8018E084; break;
        case 9: goto L_8018E084; break;
        case 10: goto L_8018DE40; break;
        case 11: goto L_8018DE40; break;
        case 12: goto L_8018DE40; break;
        case 13: goto L_8018DE40; break;
        case 14: goto L_8018DE40; break;
        case 15: goto L_8018DE40; break;
        case 16: goto L_8018DE40; break;
        case 17: goto L_8018DE40; break;
        case 18: goto L_8018DF5C; break;
        case 19: goto L_8018DF5C; break;
        case 20: goto L_8018DF5C; break;
        case 21: goto L_8018DF5C; break;
        case 22: goto L_8018DF5C; break;
        case 23: goto L_8018DF5C; break;
        case 24: goto L_8018DF5C; break;
        case 25: goto L_8018DF5C; break;
        case 26: goto L_8018E084; break;
        case 27: goto L_8018E084; break;
        case 28: goto L_8018E084; break;
        case 29: goto L_8018E084; break;
        case 30: goto L_8018E084; break;
        case 31: goto L_8018E084; break;
        case 32: goto L_8018E084; break;
        case 33: goto L_8018E084; break;
        case 34: goto L_8018E084; break;
        case 35: goto L_8018E084; break;
        case 36: goto L_8018E084; break;
        case 37: goto L_8018DB60; break;
        default: switch_error(__func__, 0x8018DB58, 0x801A0244);
    }
    // 0x8018DB5C: nop

L_8018DB60:
    // 0x8018DB60: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x8018DB64: lw          $t8, -0x4514($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4514);
    // 0x8018DB68: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8018DB6C: lui         $t0, 0xDE00
    ctx->r8 = S32(0XDE00 << 16);
    // 0x8018DB70: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    // 0x8018DB74: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x8018DB78: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8018DB7C: sw          $t9, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r25;
    // 0x8018DB80: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x8018DB84: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x8018DB88: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x8018DB8C: addiu       $t2, $t2, -0x6710
    ctx->r10 = ADD32(ctx->r10, -0X6710);
    // 0x8018DB90: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018DB94: sw          $t2, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r10;
    // 0x8018DB98: lwc1        $f4, 0x2DC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X2DC);
    // 0x8018DB9C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018DBA0: lwc1        $f6, -0x2E30($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x8018DBA4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8018DBA8: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x8018DBAC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8018DBB0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8018DBB4: addiu       $t7, $t7, 0xF98
    ctx->r15 = ADD32(ctx->r15, 0XF98);
    // 0x8018DBB8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8018DBBC: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x8018DBC0: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8018DBC4: addiu       $a0, $a0, 0x5D78
    ctx->r4 = ADD32(ctx->r4, 0X5D78);
    // 0x8018DBC8: swc1        $f8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f8.u32l;
    // 0x8018DBCC: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x8018DBD0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018DBD4: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8018DBD8: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x8018DBDC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8018DBE0: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8018DBE4: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8018DBE8: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8018DBEC: lwc1        $f10, 0x20($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X20);
    // 0x8018DBF0: lw          $a2, 0x18($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X18);
    // 0x8018DBF4: lw          $a3, 0x1C($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X1C);
    // 0x8018DBF8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8018DBFC: lwc1        $f16, 0x0($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X0);
    // 0x8018DC00: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x8018DC04: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x8018DC08: jal         0x800C60A0
    // 0x8018DC0C: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    func_800C60A0(rdram, ctx);
        goto after_0;
    // 0x8018DC0C: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    after_0:
    // 0x8018DC10: b           L_8018E128
    // 0x8018DC14: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8018E128;
    // 0x8018DC14: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8018DC18:
    // 0x8018DC18: lui         $t0, 0x8011
    ctx->r8 = S32(0X8011 << 16);
    // 0x8018DC1C: lw          $t0, -0x4514($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X4514);
    // 0x8018DC20: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8018DC24: lui         $t2, 0xDE00
    ctx->r10 = S32(0XDE00 << 16);
    // 0x8018DC28: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    // 0x8018DC2C: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x8018DC30: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x8018DC34: sw          $t1, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r9;
    // 0x8018DC38: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x8018DC3C: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x8018DC40: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x8018DC44: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x8018DC48: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018DC4C: addiu       $t4, $t4, -0x6710
    ctx->r12 = ADD32(ctx->r12, -0X6710);
    // 0x8018DC50: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018DC54: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
    // 0x8018DC58: lwc1        $f4, -0x2E30($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x8018DC5C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8018DC60: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x8018DC64: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8018DC68: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8018DC6C: addiu       $t9, $t9, 0xF98
    ctx->r25 = ADD32(ctx->r25, 0XF98);
    // 0x8018DC70: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8018DC74: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x8018DC78: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8018DC7C: addiu       $a0, $a0, 0x5DD8
    ctx->r4 = ADD32(ctx->r4, 0X5DD8);
    // 0x8018DC80: swc1        $f6, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f6.u32l;
    // 0x8018DC84: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8018DC88: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018DC8C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8018DC90: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8018DC94: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8018DC98: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8018DC9C: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8018DCA0: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8018DCA4: lwc1        $f8, 0x20($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X20);
    // 0x8018DCA8: lw          $a2, 0x18($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X18);
    // 0x8018DCAC: lw          $a3, 0x1C($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X1C);
    // 0x8018DCB0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x8018DCB4: lwc1        $f10, 0x0($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X0);
    // 0x8018DCB8: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x8018DCBC: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x8018DCC0: jal         0x800C60A0
    // 0x8018DCC4: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    func_800C60A0(rdram, ctx);
        goto after_1;
    // 0x8018DCC4: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x8018DCC8: b           L_8018E128
    // 0x8018DCCC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8018E128;
    // 0x8018DCCC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8018DCD0:
    // 0x8018DCD0: lui         $t2, 0x8011
    ctx->r10 = S32(0X8011 << 16);
    // 0x8018DCD4: lw          $t2, -0x4514($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4514);
    // 0x8018DCD8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8018DCDC: lui         $t4, 0xDE00
    ctx->r12 = S32(0XDE00 << 16);
    // 0x8018DCE0: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x8018DCE4: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8018DCE8: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x8018DCEC: sw          $t3, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r11;
    // 0x8018DCF0: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x8018DCF4: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8018DCF8: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8018DCFC: addiu       $t6, $t6, -0x6710
    ctx->r14 = ADD32(ctx->r14, -0X6710);
    // 0x8018DD00: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018DD04: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x8018DD08: lwc1        $f16, 0x2E0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X2E0);
    // 0x8018DD0C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018DD10: lwc1        $f18, -0x2E30($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x8018DD14: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8018DD18: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x8018DD1C: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8018DD20: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8018DD24: addiu       $t1, $t1, 0xF98
    ctx->r9 = ADD32(ctx->r9, 0XF98);
    // 0x8018DD28: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8018DD2C: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x8018DD30: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8018DD34: addiu       $a0, $a0, 0x5E38
    ctx->r4 = ADD32(ctx->r4, 0X5E38);
    // 0x8018DD38: swc1        $f4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f4.u32l;
    // 0x8018DD3C: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x8018DD40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018DD44: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8018DD48: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x8018DD4C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8018DD50: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8018DD54: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x8018DD58: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8018DD5C: lwc1        $f6, 0x20($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X20);
    // 0x8018DD60: lw          $a2, 0x18($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X18);
    // 0x8018DD64: lw          $a3, 0x1C($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X1C);
    // 0x8018DD68: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x8018DD6C: lwc1        $f8, 0x0($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X0);
    // 0x8018DD70: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x8018DD74: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8018DD78: jal         0x800C60A0
    // 0x8018DD7C: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    func_800C60A0(rdram, ctx);
        goto after_2;
    // 0x8018DD7C: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x8018DD80: b           L_8018E128
    // 0x8018DD84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8018E128;
    // 0x8018DD84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8018DD88:
    // 0x8018DD88: lui         $t4, 0x8011
    ctx->r12 = S32(0X8011 << 16);
    // 0x8018DD8C: lw          $t4, -0x4514($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4514);
    // 0x8018DD90: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8018DD94: lui         $t6, 0xDE00
    ctx->r14 = S32(0XDE00 << 16);
    // 0x8018DD98: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x8018DD9C: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8018DDA0: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x8018DDA4: sw          $t5, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r13;
    // 0x8018DDA8: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8018DDAC: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8018DDB0: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x8018DDB4: addiu       $t8, $t8, -0x6710
    ctx->r24 = ADD32(ctx->r24, -0X6710);
    // 0x8018DDB8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018DDBC: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x8018DDC0: lwc1        $f10, 0x2E4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X2E4);
    // 0x8018DDC4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018DDC8: lwc1        $f16, -0x2E30($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x8018DDCC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8018DDD0: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x8018DDD4: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8018DDD8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8018DDDC: addiu       $t3, $t3, 0xF98
    ctx->r11 = ADD32(ctx->r11, 0XF98);
    // 0x8018DDE0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8018DDE4: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x8018DDE8: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8018DDEC: addiu       $a0, $a0, 0x5E98
    ctx->r4 = ADD32(ctx->r4, 0X5E98);
    // 0x8018DDF0: swc1        $f18, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f18.u32l;
    // 0x8018DDF4: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x8018DDF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018DDFC: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8018DE00: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x8018DE04: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8018DE08: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8018DE0C: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x8018DE10: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8018DE14: lwc1        $f4, 0x20($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X20);
    // 0x8018DE18: lw          $a2, 0x18($t4)
    ctx->r6 = MEM_W(ctx->r12, 0X18);
    // 0x8018DE1C: lw          $a3, 0x1C($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X1C);
    // 0x8018DE20: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8018DE24: lwc1        $f6, 0x0($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X0);
    // 0x8018DE28: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8018DE2C: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x8018DE30: jal         0x800C60A0
    // 0x8018DE34: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    func_800C60A0(rdram, ctx);
        goto after_3;
    // 0x8018DE34: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    after_3:
    // 0x8018DE38: b           L_8018E128
    // 0x8018DE3C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8018E128;
    // 0x8018DE3C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8018DE40:
    // 0x8018DE40: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018DE44: lwc1        $f8, 0x2E8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X2E8);
    // 0x8018DE48: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018DE4C: lwc1        $f10, -0x2E30($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x8018DE50: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8018DE54: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x8018DE58: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8018DE5C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018DE60: swc1        $f16, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f16.u32l;
    // 0x8018DE64: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8018DE68: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8018DE6C: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8018DE70: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8018DE74: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8018DE78: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8018DE7C: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8018DE80: lwc1        $f18, 0xFCC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0XFCC);
    // 0x8018DE84: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018DE88: lwc1        $f4, -0x2C1C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2C1C);
    // 0x8018DE8C: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x8018DE90: nop

    // 0x8018DE94: bc1f        L_8018DEC8
    if (!c1cs) {
        // 0x8018DE98: nop
    
            goto L_8018DEC8;
    }
    // 0x8018DE98: nop

    // 0x8018DE9C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8018DEA0: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x8018DEA4: lw          $a3, 0x0($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X0);
    // 0x8018DEA8: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8018DEAC: addiu       $a0, $a0, 0x4C10
    ctx->r4 = ADD32(ctx->r4, 0X4C10);
    // 0x8018DEB0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8018DEB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018DEB8: jal         0x8018C870
    // 0x8018DEBC: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    func_8018C870_1501A0(rdram, ctx);
        goto after_4;
    // 0x8018DEBC: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    after_4:
    // 0x8018DEC0: b           L_8018DF54
    // 0x8018DEC4: nop

        goto L_8018DF54;
    // 0x8018DEC4: nop

L_8018DEC8:
    // 0x8018DEC8: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x8018DECC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018DED0: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8018DED4: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x8018DED8: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8018DEDC: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8018DEE0: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x8018DEE4: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8018DEE8: lwc1        $f6, 0xFCC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0XFCC);
    // 0x8018DEEC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018DEF0: lwc1        $f8, -0x2C18($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2C18);
    // 0x8018DEF4: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x8018DEF8: nop

    // 0x8018DEFC: bc1f        L_8018DF30
    if (!c1cs) {
        // 0x8018DF00: nop
    
            goto L_8018DF30;
    }
    // 0x8018DF00: nop

    // 0x8018DF04: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8018DF08: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x8018DF0C: lw          $a3, 0x0($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X0);
    // 0x8018DF10: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8018DF14: addiu       $a0, $a0, 0x48C8
    ctx->r4 = ADD32(ctx->r4, 0X48C8);
    // 0x8018DF18: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8018DF1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018DF20: jal         0x8018C870
    // 0x8018DF24: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    func_8018C870_1501A0(rdram, ctx);
        goto after_5;
    // 0x8018DF24: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    after_5:
    // 0x8018DF28: b           L_8018DF54
    // 0x8018DF2C: nop

        goto L_8018DF54;
    // 0x8018DF2C: nop

L_8018DF30:
    // 0x8018DF30: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8018DF34: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x8018DF38: lw          $a3, 0x0($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X0);
    // 0x8018DF3C: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8018DF40: addiu       $a0, $a0, 0x49B8
    ctx->r4 = ADD32(ctx->r4, 0X49B8);
    // 0x8018DF44: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8018DF48: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018DF4C: jal         0x8018C870
    // 0x8018DF50: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    func_8018C870_1501A0(rdram, ctx);
        goto after_6;
    // 0x8018DF50: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    after_6:
L_8018DF54:
    // 0x8018DF54: b           L_8018E128
    // 0x8018DF58: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8018E128;
    // 0x8018DF58: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8018DF5C:
    // 0x8018DF5C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018DF60: lwc1        $f10, 0x2EC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X2EC);
    // 0x8018DF64: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018DF68: lwc1        $f16, -0x2E30($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x8018DF6C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8018DF70: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x8018DF74: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8018DF78: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018DF7C: swc1        $f18, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f18.u32l;
    // 0x8018DF80: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x8018DF84: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8018DF88: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x8018DF8C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8018DF90: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8018DF94: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8018DF98: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8018DF9C: lwc1        $f4, 0xFCC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XFCC);
    // 0x8018DFA0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018DFA4: lwc1        $f6, -0x2C1C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2C1C);
    // 0x8018DFA8: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8018DFAC: nop

    // 0x8018DFB0: bc1f        L_8018DFE8
    if (!c1cs) {
        // 0x8018DFB4: nop
    
            goto L_8018DFE8;
    }
    // 0x8018DFB4: nop

    // 0x8018DFB8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8018DFBC: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x8018DFC0: lw          $a3, 0x0($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X0);
    // 0x8018DFC4: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8018DFC8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8018DFCC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8018DFD0: addiu       $a0, $a0, 0x4C10
    ctx->r4 = ADD32(ctx->r4, 0X4C10);
    // 0x8018DFD4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018DFD8: jal         0x8018C870
    // 0x8018DFDC: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
    func_8018C870_1501A0(rdram, ctx);
        goto after_7;
    // 0x8018DFDC: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
    after_7:
    // 0x8018DFE0: b           L_8018E07C
    // 0x8018DFE4: nop

        goto L_8018E07C;
    // 0x8018DFE4: nop

L_8018DFE8:
    // 0x8018DFE8: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x8018DFEC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018DFF0: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x8018DFF4: subu        $t1, $t1, $t9
    ctx->r9 = SUB32(ctx->r9, ctx->r25);
    // 0x8018DFF8: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8018DFFC: addu        $t1, $t1, $t9
    ctx->r9 = ADD32(ctx->r9, ctx->r25);
    // 0x8018E000: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x8018E004: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8018E008: lwc1        $f8, 0xFCC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0XFCC);
    // 0x8018E00C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018E010: lwc1        $f10, -0x2C18($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2C18);
    // 0x8018E014: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x8018E018: nop

    // 0x8018E01C: bc1f        L_8018E054
    if (!c1cs) {
        // 0x8018E020: nop
    
            goto L_8018E054;
    }
    // 0x8018E020: nop

    // 0x8018E024: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8018E028: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x8018E02C: lw          $a3, 0x0($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X0);
    // 0x8018E030: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8018E034: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8018E038: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8018E03C: addiu       $a0, $a0, 0x48C8
    ctx->r4 = ADD32(ctx->r4, 0X48C8);
    // 0x8018E040: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018E044: jal         0x8018C870
    // 0x8018E048: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    func_8018C870_1501A0(rdram, ctx);
        goto after_8;
    // 0x8018E048: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    after_8:
    // 0x8018E04C: b           L_8018E07C
    // 0x8018E050: nop

        goto L_8018E07C;
    // 0x8018E050: nop

L_8018E054:
    // 0x8018E054: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8018E058: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x8018E05C: lw          $a3, 0x0($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X0);
    // 0x8018E060: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8018E064: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8018E068: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8018E06C: addiu       $a0, $a0, 0x49B8
    ctx->r4 = ADD32(ctx->r4, 0X49B8);
    // 0x8018E070: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018E074: jal         0x8018C870
    // 0x8018E078: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    func_8018C870_1501A0(rdram, ctx);
        goto after_9;
    // 0x8018E078: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    after_9:
L_8018E07C:
    // 0x8018E07C: b           L_8018E128
    // 0x8018E080: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8018E128;
    // 0x8018E080: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8018E084:
    // 0x8018E084: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8018E088: lw          $t6, -0x2E44($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2E44);
    // 0x8018E08C: addiu       $t5, $t6, -0x1
    ctx->r13 = ADD32(ctx->r14, -0X1);
    // 0x8018E090: sltiu       $at, $t5, 0x6
    ctx->r1 = ctx->r13 < 0X6 ? 1 : 0;
    // 0x8018E094: beq         $at, $zero, L_8018E124
    if (ctx->r1 == 0) {
        // 0x8018E098: nop
    
            goto L_8018E124;
    }
    // 0x8018E098: nop

    // 0x8018E09C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8018E0A0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018E0A4: addu        $at, $at, $t5
    gpr jr_addend_8018E0AC = ctx->r13;
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x8018E0A8: lw          $t5, 0x2F0($at)
    ctx->r13 = ADD32(ctx->r1, 0X2F0);
    // 0x8018E0AC: jr          $t5
    // 0x8018E0B0: nop

    switch (jr_addend_8018E0AC >> 2) {
        case 0: goto L_8018E0B4; break;
        case 1: goto L_8018E0C8; break;
        case 2: goto L_8018E0DC; break;
        case 3: goto L_8018E0F0; break;
        case 4: goto L_8018E104; break;
        case 5: goto L_8018E118; break;
        default: switch_error(__func__, 0x8018E0AC, 0x801A02F0);
    }
    // 0x8018E0B0: nop

L_8018E0B4:
    // 0x8018E0B4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8018E0B8: jal         0x801E63E0
    // 0x8018E0BC: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    func_801E63E0_1B66F0(rdram, ctx);
        goto after_10;
    // 0x8018E0BC: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_10:
    // 0x8018E0C0: b           L_8018E124
    // 0x8018E0C4: nop

        goto L_8018E124;
    // 0x8018E0C4: nop

L_8018E0C8:
    // 0x8018E0C8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8018E0CC: jal         0x801EA004
    // 0x8018E0D0: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    func_801EA004_255660(rdram, ctx);
        goto after_11;
    // 0x8018E0D0: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_11:
    // 0x8018E0D4: b           L_8018E124
    // 0x8018E0D8: nop

        goto L_8018E124;
    // 0x8018E0D8: nop

L_8018E0DC:
    // 0x8018E0DC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8018E0E0: jal         0x801E2FA8
    // 0x8018E0E4: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    func_801E2FA8_34B590(rdram, ctx);
        goto after_12;
    // 0x8018E0E4: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_12:
    // 0x8018E0E8: b           L_8018E124
    // 0x8018E0EC: nop

        goto L_8018E124;
    // 0x8018E0EC: nop

L_8018E0F0:
    // 0x8018E0F0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8018E0F4: jal         0x801DE034
    // 0x8018E0F8: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    func_801DE034_3EFDD0(rdram, ctx);
        goto after_13;
    // 0x8018E0F8: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_13:
    // 0x8018E0FC: b           L_8018E124
    // 0x8018E100: nop

        goto L_8018E124;
    // 0x8018E100: nop

L_8018E104:
    // 0x8018E104: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8018E108: jal         0x801D7470
    // 0x8018E10C: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    func_801D7470_497140(rdram, ctx);
        goto after_14;
    // 0x8018E10C: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_14:
    // 0x8018E110: b           L_8018E124
    // 0x8018E114: nop

        goto L_8018E124;
    // 0x8018E114: nop

L_8018E118:
    // 0x8018E118: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8018E11C: jal         0x801E0EC8
    // 0x8018E120: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    func_801E0EC8_4DC6D0(rdram, ctx);
        goto after_15;
    // 0x8018E120: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_15:
L_8018E124:
    // 0x8018E124: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8018E128:
    // 0x8018E128: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8018E12C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8018E130: jr          $ra
    // 0x8018E134: nop

    return;
    // 0x8018E134: nop

;}
RECOMP_FUNC void func_8018E138_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018E138: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8018E13C: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x8018E140: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8018E144: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8018E148: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8018E14C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8018E150: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8018E154: sll         $t0, $a0, 2
    ctx->r8 = S32(ctx->r4 << 2);
    // 0x8018E158: lw          $t7, 0xFA8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XFA8);
    // 0x8018E15C: subu        $t0, $t0, $a0
    ctx->r8 = SUB32(ctx->r8, ctx->r4);
    // 0x8018E160: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8018E164: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8018E168: addu        $t0, $t0, $a0
    ctx->r8 = ADD32(ctx->r8, ctx->r4);
    // 0x8018E16C: addiu       $t9, $t9, 0x3C00
    ctx->r25 = ADD32(ctx->r25, 0X3C00);
    // 0x8018E170: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x8018E174: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8018E178: andi        $t8, $t7, 0x7
    ctx->r24 = ctx->r15 & 0X7;
    // 0x8018E17C: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8018E180: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8018E184: lw          $t1, 0xFA8($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XFA8);
    // 0x8018E188: sll         $t5, $a0, 2
    ctx->r13 = S32(ctx->r4 << 2);
    // 0x8018E18C: subu        $t5, $t5, $a0
    ctx->r13 = SUB32(ctx->r13, ctx->r4);
    // 0x8018E190: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8018E194: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8018E198: addu        $t5, $t5, $a0
    ctx->r13 = ADD32(ctx->r13, ctx->r4);
    // 0x8018E19C: srl         $t2, $t1, 3
    ctx->r10 = S32(U32(ctx->r9) >> 3);
    // 0x8018E1A0: andi        $t3, $t2, 0x7
    ctx->r11 = ctx->r10 & 0X7;
    // 0x8018E1A4: addiu       $t4, $t4, 0x3C00
    ctx->r12 = ADD32(ctx->r12, 0X3C00);
    // 0x8018E1A8: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8018E1AC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8018E1B0: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    // 0x8018E1B4: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8018E1B8: lw          $t6, 0xFA8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XFA8);
    // 0x8018E1BC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8018E1C0: addiu       $t9, $t9, 0x3C00
    ctx->r25 = ADD32(ctx->r25, 0X3C00);
    // 0x8018E1C4: srl         $t7, $t6, 6
    ctx->r15 = S32(U32(ctx->r14) >> 6);
    // 0x8018E1C8: andi        $t8, $t7, 0x7
    ctx->r24 = ctx->r15 & 0X7;
    // 0x8018E1CC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8018E1D0: sw          $t8, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r24;
    // 0x8018E1D4: addiu       $t0, $t0, 0x3C00
    ctx->r8 = ADD32(ctx->r8, 0X3C00);
    // 0x8018E1D8: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x8018E1DC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8018E1E0: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8018E1E4: beq         $a1, $at, L_8018E20C
    if (ctx->r5 == ctx->r1) {
        // 0x8018E1E8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8018E20C;
    }
    // 0x8018E1E8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8018E1EC: beq         $a1, $at, L_8018E23C
    if (ctx->r5 == ctx->r1) {
        // 0x8018E1F0: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8018E23C;
    }
    // 0x8018E1F0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8018E1F4: beq         $a1, $at, L_8018E270
    if (ctx->r5 == ctx->r1) {
        // 0x8018E1F8: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_8018E270;
    }
    // 0x8018E1F8: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8018E1FC: beq         $a1, $at, L_8018E2AC
    if (ctx->r5 == ctx->r1) {
        // 0x8018E200: nop
    
            goto L_8018E2AC;
    }
    // 0x8018E200: nop

    // 0x8018E204: b           L_8018E2EC
    // 0x8018E208: nop

        goto L_8018E2EC;
    // 0x8018E208: nop

L_8018E20C:
    // 0x8018E20C: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x8018E210: subu        $t1, $t1, $a0
    ctx->r9 = SUB32(ctx->r9, ctx->r4);
    // 0x8018E214: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8018E218: addu        $t1, $t1, $a0
    ctx->r9 = ADD32(ctx->r9, ctx->r4);
    // 0x8018E21C: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x8018E220: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018E224: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8018E228: lwc1        $f4, 0xFD0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XFD0);
    // 0x8018E22C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8018E230: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x8018E234: b           L_8018E2FC
    // 0x8018E238: swc1        $f4, 0x44($t2)
    MEM_W(0X44, ctx->r10) = ctx->f4.u32l;
        goto L_8018E2FC;
    // 0x8018E238: swc1        $f4, 0x44($t2)
    MEM_W(0X44, ctx->r10) = ctx->f4.u32l;
L_8018E23C:
    // 0x8018E23C: sll         $t3, $a0, 2
    ctx->r11 = S32(ctx->r4 << 2);
    // 0x8018E240: subu        $t3, $t3, $a0
    ctx->r11 = SUB32(ctx->r11, ctx->r4);
    // 0x8018E244: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8018E248: addu        $t3, $t3, $a0
    ctx->r11 = ADD32(ctx->r11, ctx->r4);
    // 0x8018E24C: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x8018E250: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018E254: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x8018E258: lwc1        $f6, 0xFD0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0XFD0);
    // 0x8018E25C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8018E260: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x8018E264: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x8018E268: b           L_8018E2FC
    // 0x8018E26C: swc1        $f8, 0x44($t4)
    MEM_W(0X44, ctx->r12) = ctx->f8.u32l;
        goto L_8018E2FC;
    // 0x8018E26C: swc1        $f8, 0x44($t4)
    MEM_W(0X44, ctx->r12) = ctx->f8.u32l;
L_8018E270:
    // 0x8018E270: sll         $t5, $a0, 2
    ctx->r13 = S32(ctx->r4 << 2);
    // 0x8018E274: subu        $t5, $t5, $a0
    ctx->r13 = SUB32(ctx->r13, ctx->r4);
    // 0x8018E278: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8018E27C: addu        $t5, $t5, $a0
    ctx->r13 = ADD32(ctx->r13, ctx->r4);
    // 0x8018E280: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8018E284: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018E288: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x8018E28C: lwc1        $f10, 0xFD0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0XFD0);
    // 0x8018E290: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8018E294: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8018E298: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8018E29C: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x8018E2A0: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8018E2A4: b           L_8018E2FC
    // 0x8018E2A8: swc1        $f18, 0x44($t6)
    MEM_W(0X44, ctx->r14) = ctx->f18.u32l;
        goto L_8018E2FC;
    // 0x8018E2A8: swc1        $f18, 0x44($t6)
    MEM_W(0X44, ctx->r14) = ctx->f18.u32l;
L_8018E2AC:
    // 0x8018E2AC: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x8018E2B0: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x8018E2B4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8018E2B8: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x8018E2BC: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8018E2C0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018E2C4: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8018E2C8: lwc1        $f4, 0xFD0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XFD0);
    // 0x8018E2CC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8018E2D0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018E2D4: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8018E2D8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8018E2DC: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8018E2E0: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x8018E2E4: b           L_8018E2FC
    // 0x8018E2E8: swc1        $f10, 0x44($t8)
    MEM_W(0X44, ctx->r24) = ctx->f10.u32l;
        goto L_8018E2FC;
    // 0x8018E2E8: swc1        $f10, 0x44($t8)
    MEM_W(0X44, ctx->r24) = ctx->f10.u32l;
L_8018E2EC:
    // 0x8018E2EC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8018E2F0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8018E2F4: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x8018E2F8: swc1        $f16, 0x44($t9)
    MEM_W(0X44, ctx->r25) = ctx->f16.u32l;
L_8018E2FC:
    // 0x8018E2FC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8018E300: addiu       $t0, $t0, 0x3C00
    ctx->r8 = ADD32(ctx->r8, 0X3C00);
    // 0x8018E304: lw          $a1, 0x4($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X4);
    // 0x8018E308: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8018E30C: beq         $a1, $at, L_8018E334
    if (ctx->r5 == ctx->r1) {
        // 0x8018E310: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8018E334;
    }
    // 0x8018E310: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8018E314: beq         $a1, $at, L_8018E364
    if (ctx->r5 == ctx->r1) {
        // 0x8018E318: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8018E364;
    }
    // 0x8018E318: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8018E31C: beq         $a1, $at, L_8018E398
    if (ctx->r5 == ctx->r1) {
        // 0x8018E320: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_8018E398;
    }
    // 0x8018E320: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8018E324: beq         $a1, $at, L_8018E3D4
    if (ctx->r5 == ctx->r1) {
        // 0x8018E328: nop
    
            goto L_8018E3D4;
    }
    // 0x8018E328: nop

    // 0x8018E32C: b           L_8018E414
    // 0x8018E330: nop

        goto L_8018E414;
    // 0x8018E330: nop

L_8018E334:
    // 0x8018E334: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x8018E338: subu        $t1, $t1, $a0
    ctx->r9 = SUB32(ctx->r9, ctx->r4);
    // 0x8018E33C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8018E340: addu        $t1, $t1, $a0
    ctx->r9 = ADD32(ctx->r9, ctx->r4);
    // 0x8018E344: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x8018E348: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018E34C: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8018E350: lwc1        $f18, 0xFD0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0XFD0);
    // 0x8018E354: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8018E358: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x8018E35C: b           L_8018E424
    // 0x8018E360: swc1        $f18, 0x48($t2)
    MEM_W(0X48, ctx->r10) = ctx->f18.u32l;
        goto L_8018E424;
    // 0x8018E360: swc1        $f18, 0x48($t2)
    MEM_W(0X48, ctx->r10) = ctx->f18.u32l;
L_8018E364:
    // 0x8018E364: sll         $t3, $a0, 2
    ctx->r11 = S32(ctx->r4 << 2);
    // 0x8018E368: subu        $t3, $t3, $a0
    ctx->r11 = SUB32(ctx->r11, ctx->r4);
    // 0x8018E36C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8018E370: addu        $t3, $t3, $a0
    ctx->r11 = ADD32(ctx->r11, ctx->r4);
    // 0x8018E374: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x8018E378: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018E37C: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x8018E380: lwc1        $f4, 0xFD0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XFD0);
    // 0x8018E384: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8018E388: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x8018E38C: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8018E390: b           L_8018E424
    // 0x8018E394: swc1        $f6, 0x48($t4)
    MEM_W(0X48, ctx->r12) = ctx->f6.u32l;
        goto L_8018E424;
    // 0x8018E394: swc1        $f6, 0x48($t4)
    MEM_W(0X48, ctx->r12) = ctx->f6.u32l;
L_8018E398:
    // 0x8018E398: sll         $t5, $a0, 2
    ctx->r13 = S32(ctx->r4 << 2);
    // 0x8018E39C: subu        $t5, $t5, $a0
    ctx->r13 = SUB32(ctx->r13, ctx->r4);
    // 0x8018E3A0: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8018E3A4: addu        $t5, $t5, $a0
    ctx->r13 = ADD32(ctx->r13, ctx->r4);
    // 0x8018E3A8: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8018E3AC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018E3B0: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x8018E3B4: lwc1        $f8, 0xFD0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0XFD0);
    // 0x8018E3B8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8018E3BC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018E3C0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8018E3C4: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x8018E3C8: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8018E3CC: b           L_8018E424
    // 0x8018E3D0: swc1        $f16, 0x48($t6)
    MEM_W(0X48, ctx->r14) = ctx->f16.u32l;
        goto L_8018E424;
    // 0x8018E3D0: swc1        $f16, 0x48($t6)
    MEM_W(0X48, ctx->r14) = ctx->f16.u32l;
L_8018E3D4:
    // 0x8018E3D4: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x8018E3D8: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x8018E3DC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8018E3E0: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x8018E3E4: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8018E3E8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018E3EC: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8018E3F0: lwc1        $f18, 0xFD0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0XFD0);
    // 0x8018E3F4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8018E3F8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018E3FC: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x8018E400: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8018E404: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8018E408: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x8018E40C: b           L_8018E424
    // 0x8018E410: swc1        $f8, 0x48($t8)
    MEM_W(0X48, ctx->r24) = ctx->f8.u32l;
        goto L_8018E424;
    // 0x8018E410: swc1        $f8, 0x48($t8)
    MEM_W(0X48, ctx->r24) = ctx->f8.u32l;
L_8018E414:
    // 0x8018E414: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8018E418: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8018E41C: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x8018E420: swc1        $f10, 0x48($t9)
    MEM_W(0X48, ctx->r25) = ctx->f10.u32l;
L_8018E424:
    // 0x8018E424: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8018E428: addiu       $t0, $t0, 0x3C00
    ctx->r8 = ADD32(ctx->r8, 0X3C00);
    // 0x8018E42C: lw          $a1, 0x8($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X8);
    // 0x8018E430: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8018E434: beq         $a1, $at, L_8018E45C
    if (ctx->r5 == ctx->r1) {
        // 0x8018E438: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8018E45C;
    }
    // 0x8018E438: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8018E43C: beq         $a1, $at, L_8018E48C
    if (ctx->r5 == ctx->r1) {
        // 0x8018E440: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8018E48C;
    }
    // 0x8018E440: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8018E444: beq         $a1, $at, L_8018E4C0
    if (ctx->r5 == ctx->r1) {
        // 0x8018E448: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_8018E4C0;
    }
    // 0x8018E448: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8018E44C: beq         $a1, $at, L_8018E4FC
    if (ctx->r5 == ctx->r1) {
        // 0x8018E450: nop
    
            goto L_8018E4FC;
    }
    // 0x8018E450: nop

    // 0x8018E454: b           L_8018E53C
    // 0x8018E458: nop

        goto L_8018E53C;
    // 0x8018E458: nop

L_8018E45C:
    // 0x8018E45C: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x8018E460: subu        $t1, $t1, $a0
    ctx->r9 = SUB32(ctx->r9, ctx->r4);
    // 0x8018E464: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8018E468: addu        $t1, $t1, $a0
    ctx->r9 = ADD32(ctx->r9, ctx->r4);
    // 0x8018E46C: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x8018E470: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018E474: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8018E478: lwc1        $f16, 0xFD0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0XFD0);
    // 0x8018E47C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8018E480: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x8018E484: b           L_8018E54C
    // 0x8018E488: swc1        $f16, 0x4C($t2)
    MEM_W(0X4C, ctx->r10) = ctx->f16.u32l;
        goto L_8018E54C;
    // 0x8018E488: swc1        $f16, 0x4C($t2)
    MEM_W(0X4C, ctx->r10) = ctx->f16.u32l;
L_8018E48C:
    // 0x8018E48C: sll         $t3, $a0, 2
    ctx->r11 = S32(ctx->r4 << 2);
    // 0x8018E490: subu        $t3, $t3, $a0
    ctx->r11 = SUB32(ctx->r11, ctx->r4);
    // 0x8018E494: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8018E498: addu        $t3, $t3, $a0
    ctx->r11 = ADD32(ctx->r11, ctx->r4);
    // 0x8018E49C: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x8018E4A0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018E4A4: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x8018E4A8: lwc1        $f18, 0xFD0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0XFD0);
    // 0x8018E4AC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8018E4B0: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x8018E4B4: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x8018E4B8: b           L_8018E54C
    // 0x8018E4BC: swc1        $f4, 0x4C($t4)
    MEM_W(0X4C, ctx->r12) = ctx->f4.u32l;
        goto L_8018E54C;
    // 0x8018E4BC: swc1        $f4, 0x4C($t4)
    MEM_W(0X4C, ctx->r12) = ctx->f4.u32l;
L_8018E4C0:
    // 0x8018E4C0: sll         $t5, $a0, 2
    ctx->r13 = S32(ctx->r4 << 2);
    // 0x8018E4C4: subu        $t5, $t5, $a0
    ctx->r13 = SUB32(ctx->r13, ctx->r4);
    // 0x8018E4C8: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8018E4CC: addu        $t5, $t5, $a0
    ctx->r13 = ADD32(ctx->r13, ctx->r4);
    // 0x8018E4D0: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8018E4D4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018E4D8: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x8018E4DC: lwc1        $f6, 0xFD0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0XFD0);
    // 0x8018E4E0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8018E4E4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018E4E8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8018E4EC: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x8018E4F0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8018E4F4: b           L_8018E54C
    // 0x8018E4F8: swc1        $f10, 0x4C($t6)
    MEM_W(0X4C, ctx->r14) = ctx->f10.u32l;
        goto L_8018E54C;
    // 0x8018E4F8: swc1        $f10, 0x4C($t6)
    MEM_W(0X4C, ctx->r14) = ctx->f10.u32l;
L_8018E4FC:
    // 0x8018E4FC: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x8018E500: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x8018E504: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8018E508: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x8018E50C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8018E510: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018E514: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8018E518: lwc1        $f16, 0xFD0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0XFD0);
    // 0x8018E51C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8018E520: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018E524: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x8018E528: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8018E52C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8018E530: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x8018E534: b           L_8018E54C
    // 0x8018E538: swc1        $f6, 0x4C($t8)
    MEM_W(0X4C, ctx->r24) = ctx->f6.u32l;
        goto L_8018E54C;
    // 0x8018E538: swc1        $f6, 0x4C($t8)
    MEM_W(0X4C, ctx->r24) = ctx->f6.u32l;
L_8018E53C:
    // 0x8018E53C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8018E540: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8018E544: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x8018E548: swc1        $f8, 0x4C($t9)
    MEM_W(0X4C, ctx->r25) = ctx->f8.u32l;
L_8018E54C:
    // 0x8018E54C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8018E550: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x8018E554: lwc1        $f10, 0x44($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X44);
    // 0x8018E558: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8018E55C: nop

    // 0x8018E560: c.eq.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl == ctx->f16.fl;
    // 0x8018E564: nop

    // 0x8018E568: bc1f        L_8018E5BC
    if (!c1cs) {
        // 0x8018E56C: nop
    
            goto L_8018E5BC;
    }
    // 0x8018E56C: nop

    // 0x8018E570: lwc1        $f18, 0x48($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X48);
    // 0x8018E574: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8018E578: nop

    // 0x8018E57C: c.eq.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl == ctx->f4.fl;
    // 0x8018E580: nop

    // 0x8018E584: bc1f        L_8018E5BC
    if (!c1cs) {
        // 0x8018E588: nop
    
            goto L_8018E5BC;
    }
    // 0x8018E588: nop

    // 0x8018E58C: lwc1        $f6, 0x4C($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X4C);
    // 0x8018E590: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8018E594: nop

    // 0x8018E598: c.eq.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl == ctx->f8.fl;
    // 0x8018E59C: nop

    // 0x8018E5A0: bc1f        L_8018E5BC
    if (!c1cs) {
        // 0x8018E5A4: nop
    
            goto L_8018E5BC;
    }
    // 0x8018E5A4: nop

    // 0x8018E5A8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8018E5AC: addiu       $t2, $t2, 0x3C00
    ctx->r10 = ADD32(ctx->r10, 0X3C00);
    // 0x8018E5B0: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x8018E5B4: b           L_8018E5CC
    // 0x8018E5B8: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
        goto L_8018E5CC;
    // 0x8018E5B8: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
L_8018E5BC:
    // 0x8018E5BC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8018E5C0: addiu       $t4, $t4, 0x3C00
    ctx->r12 = ADD32(ctx->r12, 0X3C00);
    // 0x8018E5C4: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x8018E5C8: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
L_8018E5CC:
    // 0x8018E5CC: jr          $ra
    // 0x8018E5D0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8018E5D0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8018E5D4_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018E5D4: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x8018E5D8: lw          $t6, -0x4514($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4514);
    // 0x8018E5DC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8018E5E0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8018E5E4: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    // 0x8018E5E8: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x8018E5EC: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8018E5F0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8018E5F4: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8018E5F8: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8018E5FC: sw          $t7, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r15;
    // 0x8018E600: lui         $t8, 0xDE00
    ctx->r24 = S32(0XDE00 << 16);
    // 0x8018E604: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8018E608: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x8018E60C: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x8018E610: addiu       $t0, $t0, -0x6860
    ctx->r8 = ADD32(ctx->r8, -0X6860);
    // 0x8018E614: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x8018E618: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x8018E61C: addiu       $t3, $t2, -0x82
    ctx->r11 = ADD32(ctx->r10, -0X82);
    // 0x8018E620: sltiu       $at, $t3, 0x10
    ctx->r1 = ctx->r11 < 0X10 ? 1 : 0;
    // 0x8018E624: beq         $at, $zero, L_8018F184
    if (ctx->r1 == 0) {
        // 0x8018E628: nop
    
            goto L_8018F184;
    }
    // 0x8018E628: nop

    // 0x8018E62C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8018E630: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018E634: addu        $at, $at, $t3
    gpr jr_addend_8018E63C = ctx->r11;
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x8018E638: lw          $t3, 0x308($at)
    ctx->r11 = ADD32(ctx->r1, 0X308);
    // 0x8018E63C: jr          $t3
    // 0x8018E640: nop

    switch (jr_addend_8018E63C >> 2) {
        case 0: goto L_8018E644; break;
        case 1: goto L_8018E6F8; break;
        case 2: goto L_8018E7AC; break;
        case 3: goto L_8018E860; break;
        case 4: goto L_8018E914; break;
        case 5: goto L_8018E9C8; break;
        case 6: goto L_8018EA7C; break;
        case 7: goto L_8018EB30; break;
        case 8: goto L_8018EBE4; break;
        case 9: goto L_8018EC98; break;
        case 10: goto L_8018ED4C; break;
        case 11: goto L_8018EE00; break;
        case 12: goto L_8018EEB4; break;
        case 13: goto L_8018EF68; break;
        case 14: goto L_8018F01C; break;
        case 15: goto L_8018F0D0; break;
        default: switch_error(__func__, 0x8018E63C, 0x801A0308);
    }
    // 0x8018E640: nop

L_8018E644:
    // 0x8018E644: jal         0x8018E138
    // 0x8018E648: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    func_8018E138_1501A0(rdram, ctx);
        goto after_0;
    // 0x8018E648: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    after_0:
    // 0x8018E64C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018E650: lwc1        $f4, 0x348($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X348);
    // 0x8018E654: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018E658: lwc1        $f6, -0x2E30($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x8018E65C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8018E660: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x8018E664: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8018E668: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8018E66C: addiu       $t7, $t7, 0xF98
    ctx->r15 = ADD32(ctx->r15, 0XF98);
    // 0x8018E670: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8018E674: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x8018E678: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8018E67C: addiu       $t0, $t0, 0x3C00
    ctx->r8 = ADD32(ctx->r8, 0X3C00);
    // 0x8018E680: swc1        $f8, 0x40($t4)
    MEM_W(0X40, ctx->r12) = ctx->f8.u32l;
    // 0x8018E684: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x8018E688: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8018E68C: addiu       $a0, $a0, 0x18C0
    ctx->r4 = ADD32(ctx->r4, 0X18C0);
    // 0x8018E690: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8018E694: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x8018E698: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8018E69C: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8018E6A0: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8018E6A4: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8018E6A8: lwc1        $f10, 0x20($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X20);
    // 0x8018E6AC: lw          $a2, 0x18($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X18);
    // 0x8018E6B0: lw          $a3, 0x1C($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X1C);
    // 0x8018E6B4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8018E6B8: lwc1        $f16, 0x0($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X0);
    // 0x8018E6BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018E6C0: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x8018E6C4: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x8018E6C8: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    // 0x8018E6CC: lwc1        $f18, 0x44($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X44);
    // 0x8018E6D0: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    // 0x8018E6D4: lwc1        $f4, 0x48($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X48);
    // 0x8018E6D8: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x8018E6DC: lwc1        $f6, 0x4C($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X4C);
    // 0x8018E6E0: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x8018E6E4: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8018E6E8: jal         0x800C58E8
    // 0x8018E6EC: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    func_800C58E8(rdram, ctx);
        goto after_1;
    // 0x8018E6EC: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    after_1:
    // 0x8018E6F0: b           L_8018F188
    // 0x8018E6F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8018F188;
    // 0x8018E6F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8018E6F8:
    // 0x8018E6F8: jal         0x8018E138
    // 0x8018E6FC: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    func_8018E138_1501A0(rdram, ctx);
        goto after_2;
    // 0x8018E6FC: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    after_2:
    // 0x8018E700: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018E704: lwc1        $f8, 0x34C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X34C);
    // 0x8018E708: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018E70C: lwc1        $f10, -0x2E30($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x8018E710: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8018E714: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x8018E718: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8018E71C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8018E720: addiu       $t5, $t5, 0xF98
    ctx->r13 = ADD32(ctx->r13, 0XF98);
    // 0x8018E724: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8018E728: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x8018E72C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8018E730: addiu       $t8, $t8, 0x3C00
    ctx->r24 = ADD32(ctx->r24, 0X3C00);
    // 0x8018E734: swc1        $f16, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f16.u32l;
    // 0x8018E738: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x8018E73C: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8018E740: addiu       $a0, $a0, 0x18F0
    ctx->r4 = ADD32(ctx->r4, 0X18F0);
    // 0x8018E744: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8018E748: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x8018E74C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8018E750: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8018E754: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x8018E758: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x8018E75C: lwc1        $f18, 0x20($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X20);
    // 0x8018E760: lw          $a2, 0x18($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X18);
    // 0x8018E764: lw          $a3, 0x1C($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X1C);
    // 0x8018E768: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x8018E76C: lwc1        $f4, 0x0($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X0);
    // 0x8018E770: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018E774: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x8018E778: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x8018E77C: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x8018E780: lwc1        $f6, 0x44($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X44);
    // 0x8018E784: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x8018E788: lwc1        $f8, 0x48($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X48);
    // 0x8018E78C: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x8018E790: lwc1        $f10, 0x4C($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X4C);
    // 0x8018E794: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x8018E798: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8018E79C: jal         0x800C58E8
    // 0x8018E7A0: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    func_800C58E8(rdram, ctx);
        goto after_3;
    // 0x8018E7A0: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    after_3:
    // 0x8018E7A4: b           L_8018F188
    // 0x8018E7A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8018F188;
    // 0x8018E7A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8018E7AC:
    // 0x8018E7AC: jal         0x8018E138
    // 0x8018E7B0: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    func_8018E138_1501A0(rdram, ctx);
        goto after_4;
    // 0x8018E7B0: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    after_4:
    // 0x8018E7B4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018E7B8: lwc1        $f16, 0x350($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X350);
    // 0x8018E7BC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018E7C0: lwc1        $f18, -0x2E30($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x8018E7C4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8018E7C8: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x8018E7CC: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8018E7D0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8018E7D4: addiu       $t3, $t3, 0xF98
    ctx->r11 = ADD32(ctx->r11, 0XF98);
    // 0x8018E7D8: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8018E7DC: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x8018E7E0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8018E7E4: addiu       $t6, $t6, 0x3C00
    ctx->r14 = ADD32(ctx->r14, 0X3C00);
    // 0x8018E7E8: swc1        $f4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f4.u32l;
    // 0x8018E7EC: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x8018E7F0: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8018E7F4: addiu       $a0, $a0, 0x1928
    ctx->r4 = ADD32(ctx->r4, 0X1928);
    // 0x8018E7F8: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8018E7FC: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x8018E800: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8018E804: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8018E808: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x8018E80C: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8018E810: lwc1        $f6, 0x20($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X20);
    // 0x8018E814: lw          $a2, 0x18($t4)
    ctx->r6 = MEM_W(ctx->r12, 0X18);
    // 0x8018E818: lw          $a3, 0x1C($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X1C);
    // 0x8018E81C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x8018E820: lwc1        $f8, 0x0($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X0);
    // 0x8018E824: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018E828: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x8018E82C: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8018E830: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x8018E834: lwc1        $f10, 0x44($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X44);
    // 0x8018E838: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    // 0x8018E83C: lwc1        $f16, 0x48($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0X48);
    // 0x8018E840: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x8018E844: lwc1        $f18, 0x4C($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X4C);
    // 0x8018E848: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    // 0x8018E84C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8018E850: jal         0x800C58E8
    // 0x8018E854: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    func_800C58E8(rdram, ctx);
        goto after_5;
    // 0x8018E854: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    after_5:
    // 0x8018E858: b           L_8018F188
    // 0x8018E85C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8018F188;
    // 0x8018E85C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8018E860:
    // 0x8018E860: jal         0x8018E138
    // 0x8018E864: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    func_8018E138_1501A0(rdram, ctx);
        goto after_6;
    // 0x8018E864: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    after_6:
    // 0x8018E868: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018E86C: lwc1        $f4, 0x354($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X354);
    // 0x8018E870: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018E874: lwc1        $f6, -0x2E30($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x8018E878: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8018E87C: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x8018E880: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8018E884: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8018E888: addiu       $t1, $t1, 0xF98
    ctx->r9 = ADD32(ctx->r9, 0XF98);
    // 0x8018E88C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8018E890: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x8018E894: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8018E898: addiu       $t4, $t4, 0x3C00
    ctx->r12 = ADD32(ctx->r12, 0X3C00);
    // 0x8018E89C: swc1        $f8, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f8.u32l;
    // 0x8018E8A0: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x8018E8A4: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8018E8A8: addiu       $a0, $a0, 0x1960
    ctx->r4 = ADD32(ctx->r4, 0X1960);
    // 0x8018E8AC: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8018E8B0: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x8018E8B4: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8018E8B8: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8018E8BC: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x8018E8C0: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8018E8C4: lwc1        $f10, 0x20($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X20);
    // 0x8018E8C8: lw          $a2, 0x18($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X18);
    // 0x8018E8CC: lw          $a3, 0x1C($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X1C);
    // 0x8018E8D0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8018E8D4: lwc1        $f16, 0x0($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X0);
    // 0x8018E8D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018E8DC: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x8018E8E0: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x8018E8E4: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    // 0x8018E8E8: lwc1        $f18, 0x44($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X44);
    // 0x8018E8EC: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    // 0x8018E8F0: lwc1        $f4, 0x48($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X48);
    // 0x8018E8F4: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x8018E8F8: lwc1        $f6, 0x4C($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X4C);
    // 0x8018E8FC: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x8018E900: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x8018E904: jal         0x800C58E8
    // 0x8018E908: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    func_800C58E8(rdram, ctx);
        goto after_7;
    // 0x8018E908: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    after_7:
    // 0x8018E90C: b           L_8018F188
    // 0x8018E910: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8018F188;
    // 0x8018E910: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8018E914:
    // 0x8018E914: jal         0x8018E138
    // 0x8018E918: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    func_8018E138_1501A0(rdram, ctx);
        goto after_8;
    // 0x8018E918: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    after_8:
    // 0x8018E91C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018E920: lwc1        $f8, 0x358($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X358);
    // 0x8018E924: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018E928: lwc1        $f10, -0x2E30($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x8018E92C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8018E930: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x8018E934: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8018E938: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8018E93C: addiu       $t9, $t9, 0xF98
    ctx->r25 = ADD32(ctx->r25, 0XF98);
    // 0x8018E940: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8018E944: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x8018E948: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8018E94C: addiu       $t2, $t2, 0x3C00
    ctx->r10 = ADD32(ctx->r10, 0X3C00);
    // 0x8018E950: swc1        $f16, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f16.u32l;
    // 0x8018E954: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x8018E958: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8018E95C: addiu       $a0, $a0, 0x18C0
    ctx->r4 = ADD32(ctx->r4, 0X18C0);
    // 0x8018E960: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8018E964: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8018E968: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8018E96C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8018E970: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8018E974: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8018E978: lwc1        $f18, 0x20($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X20);
    // 0x8018E97C: lw          $a2, 0x18($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X18);
    // 0x8018E980: lw          $a3, 0x1C($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X1C);
    // 0x8018E984: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x8018E988: lwc1        $f4, 0x0($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X0);
    // 0x8018E98C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018E990: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x8018E994: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x8018E998: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x8018E99C: lwc1        $f6, 0x44($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X44);
    // 0x8018E9A0: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x8018E9A4: lwc1        $f8, 0x48($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X48);
    // 0x8018E9A8: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x8018E9AC: lwc1        $f10, 0x4C($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X4C);
    // 0x8018E9B0: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x8018E9B4: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8018E9B8: jal         0x800C58E8
    // 0x8018E9BC: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    func_800C58E8(rdram, ctx);
        goto after_9;
    // 0x8018E9BC: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    after_9:
    // 0x8018E9C0: b           L_8018F188
    // 0x8018E9C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8018F188;
    // 0x8018E9C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8018E9C8:
    // 0x8018E9C8: jal         0x8018E138
    // 0x8018E9CC: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    func_8018E138_1501A0(rdram, ctx);
        goto after_10;
    // 0x8018E9CC: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    after_10:
    // 0x8018E9D0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018E9D4: lwc1        $f16, 0x35C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X35C);
    // 0x8018E9D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018E9DC: lwc1        $f18, -0x2E30($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x8018E9E0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8018E9E4: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x8018E9E8: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8018E9EC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8018E9F0: addiu       $t7, $t7, 0xF98
    ctx->r15 = ADD32(ctx->r15, 0XF98);
    // 0x8018E9F4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8018E9F8: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x8018E9FC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8018EA00: addiu       $t0, $t0, 0x3C00
    ctx->r8 = ADD32(ctx->r8, 0X3C00);
    // 0x8018EA04: swc1        $f4, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f4.u32l;
    // 0x8018EA08: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x8018EA0C: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8018EA10: addiu       $a0, $a0, 0x18F0
    ctx->r4 = ADD32(ctx->r4, 0X18F0);
    // 0x8018EA14: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8018EA18: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x8018EA1C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8018EA20: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8018EA24: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8018EA28: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8018EA2C: lwc1        $f6, 0x20($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X20);
    // 0x8018EA30: lw          $a2, 0x18($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X18);
    // 0x8018EA34: lw          $a3, 0x1C($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X1C);
    // 0x8018EA38: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x8018EA3C: lwc1        $f8, 0x0($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X0);
    // 0x8018EA40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018EA44: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x8018EA48: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8018EA4C: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x8018EA50: lwc1        $f10, 0x44($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X44);
    // 0x8018EA54: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    // 0x8018EA58: lwc1        $f16, 0x48($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X48);
    // 0x8018EA5C: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x8018EA60: lwc1        $f18, 0x4C($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X4C);
    // 0x8018EA64: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    // 0x8018EA68: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8018EA6C: jal         0x800C58E8
    // 0x8018EA70: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    func_800C58E8(rdram, ctx);
        goto after_11;
    // 0x8018EA70: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    after_11:
    // 0x8018EA74: b           L_8018F188
    // 0x8018EA78: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8018F188;
    // 0x8018EA78: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8018EA7C:
    // 0x8018EA7C: jal         0x8018E138
    // 0x8018EA80: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    func_8018E138_1501A0(rdram, ctx);
        goto after_12;
    // 0x8018EA80: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    after_12:
    // 0x8018EA84: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018EA88: lwc1        $f4, 0x360($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X360);
    // 0x8018EA8C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018EA90: lwc1        $f6, -0x2E30($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x8018EA94: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8018EA98: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x8018EA9C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8018EAA0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8018EAA4: addiu       $t5, $t5, 0xF98
    ctx->r13 = ADD32(ctx->r13, 0XF98);
    // 0x8018EAA8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8018EAAC: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x8018EAB0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8018EAB4: addiu       $t8, $t8, 0x3C00
    ctx->r24 = ADD32(ctx->r24, 0X3C00);
    // 0x8018EAB8: swc1        $f8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f8.u32l;
    // 0x8018EABC: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x8018EAC0: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8018EAC4: addiu       $a0, $a0, 0x1928
    ctx->r4 = ADD32(ctx->r4, 0X1928);
    // 0x8018EAC8: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8018EACC: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x8018EAD0: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8018EAD4: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8018EAD8: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x8018EADC: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x8018EAE0: lwc1        $f10, 0x20($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X20);
    // 0x8018EAE4: lw          $a2, 0x18($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X18);
    // 0x8018EAE8: lw          $a3, 0x1C($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X1C);
    // 0x8018EAEC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8018EAF0: lwc1        $f16, 0x0($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X0);
    // 0x8018EAF4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018EAF8: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x8018EAFC: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x8018EB00: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    // 0x8018EB04: lwc1        $f18, 0x44($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0X44);
    // 0x8018EB08: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    // 0x8018EB0C: lwc1        $f4, 0x48($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X48);
    // 0x8018EB10: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x8018EB14: lwc1        $f6, 0x4C($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X4C);
    // 0x8018EB18: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x8018EB1C: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8018EB20: jal         0x800C58E8
    // 0x8018EB24: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    func_800C58E8(rdram, ctx);
        goto after_13;
    // 0x8018EB24: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    after_13:
    // 0x8018EB28: b           L_8018F188
    // 0x8018EB2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8018F188;
    // 0x8018EB2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8018EB30:
    // 0x8018EB30: jal         0x8018E138
    // 0x8018EB34: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    func_8018E138_1501A0(rdram, ctx);
        goto after_14;
    // 0x8018EB34: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    after_14:
    // 0x8018EB38: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018EB3C: lwc1        $f8, 0x364($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X364);
    // 0x8018EB40: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018EB44: lwc1        $f10, -0x2E30($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x8018EB48: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8018EB4C: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x8018EB50: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8018EB54: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8018EB58: addiu       $t3, $t3, 0xF98
    ctx->r11 = ADD32(ctx->r11, 0XF98);
    // 0x8018EB5C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8018EB60: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x8018EB64: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8018EB68: addiu       $t6, $t6, 0x3C00
    ctx->r14 = ADD32(ctx->r14, 0X3C00);
    // 0x8018EB6C: swc1        $f16, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f16.u32l;
    // 0x8018EB70: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x8018EB74: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8018EB78: addiu       $a0, $a0, 0x1960
    ctx->r4 = ADD32(ctx->r4, 0X1960);
    // 0x8018EB7C: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8018EB80: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x8018EB84: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8018EB88: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8018EB8C: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x8018EB90: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8018EB94: lwc1        $f18, 0x20($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X20);
    // 0x8018EB98: lw          $a2, 0x18($t4)
    ctx->r6 = MEM_W(ctx->r12, 0X18);
    // 0x8018EB9C: lw          $a3, 0x1C($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X1C);
    // 0x8018EBA0: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x8018EBA4: lwc1        $f4, 0x0($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X0);
    // 0x8018EBA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018EBAC: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x8018EBB0: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x8018EBB4: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x8018EBB8: lwc1        $f6, 0x44($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X44);
    // 0x8018EBBC: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x8018EBC0: lwc1        $f8, 0x48($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X48);
    // 0x8018EBC4: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x8018EBC8: lwc1        $f10, 0x4C($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X4C);
    // 0x8018EBCC: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x8018EBD0: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8018EBD4: jal         0x800C58E8
    // 0x8018EBD8: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    func_800C58E8(rdram, ctx);
        goto after_15;
    // 0x8018EBD8: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    after_15:
    // 0x8018EBDC: b           L_8018F188
    // 0x8018EBE0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8018F188;
    // 0x8018EBE0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8018EBE4:
    // 0x8018EBE4: jal         0x8018E138
    // 0x8018EBE8: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    func_8018E138_1501A0(rdram, ctx);
        goto after_16;
    // 0x8018EBE8: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    after_16:
    // 0x8018EBEC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018EBF0: lwc1        $f16, 0x368($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X368);
    // 0x8018EBF4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018EBF8: lwc1        $f18, -0x2E30($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x8018EBFC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8018EC00: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x8018EC04: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8018EC08: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8018EC0C: addiu       $t1, $t1, 0xF98
    ctx->r9 = ADD32(ctx->r9, 0XF98);
    // 0x8018EC10: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8018EC14: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x8018EC18: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8018EC1C: addiu       $t4, $t4, 0x3C00
    ctx->r12 = ADD32(ctx->r12, 0X3C00);
    // 0x8018EC20: swc1        $f4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f4.u32l;
    // 0x8018EC24: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x8018EC28: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8018EC2C: addiu       $a0, $a0, 0x18C0
    ctx->r4 = ADD32(ctx->r4, 0X18C0);
    // 0x8018EC30: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8018EC34: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x8018EC38: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8018EC3C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8018EC40: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x8018EC44: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8018EC48: lwc1        $f6, 0x20($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X20);
    // 0x8018EC4C: lw          $a2, 0x18($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X18);
    // 0x8018EC50: lw          $a3, 0x1C($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X1C);
    // 0x8018EC54: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x8018EC58: lwc1        $f8, 0x0($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X0);
    // 0x8018EC5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018EC60: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x8018EC64: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8018EC68: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x8018EC6C: lwc1        $f10, 0x44($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X44);
    // 0x8018EC70: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    // 0x8018EC74: lwc1        $f16, 0x48($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X48);
    // 0x8018EC78: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x8018EC7C: lwc1        $f18, 0x4C($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X4C);
    // 0x8018EC80: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    // 0x8018EC84: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x8018EC88: jal         0x800C58E8
    // 0x8018EC8C: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    func_800C58E8(rdram, ctx);
        goto after_17;
    // 0x8018EC8C: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    after_17:
    // 0x8018EC90: b           L_8018F188
    // 0x8018EC94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8018F188;
    // 0x8018EC94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8018EC98:
    // 0x8018EC98: jal         0x8018E138
    // 0x8018EC9C: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    func_8018E138_1501A0(rdram, ctx);
        goto after_18;
    // 0x8018EC9C: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    after_18:
    // 0x8018ECA0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018ECA4: lwc1        $f4, 0x36C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X36C);
    // 0x8018ECA8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018ECAC: lwc1        $f6, -0x2E30($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x8018ECB0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8018ECB4: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x8018ECB8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8018ECBC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8018ECC0: addiu       $t9, $t9, 0xF98
    ctx->r25 = ADD32(ctx->r25, 0XF98);
    // 0x8018ECC4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8018ECC8: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x8018ECCC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8018ECD0: addiu       $t2, $t2, 0x3C00
    ctx->r10 = ADD32(ctx->r10, 0X3C00);
    // 0x8018ECD4: swc1        $f8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f8.u32l;
    // 0x8018ECD8: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x8018ECDC: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8018ECE0: addiu       $a0, $a0, 0x18F0
    ctx->r4 = ADD32(ctx->r4, 0X18F0);
    // 0x8018ECE4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8018ECE8: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8018ECEC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8018ECF0: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8018ECF4: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8018ECF8: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8018ECFC: lwc1        $f10, 0x20($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X20);
    // 0x8018ED00: lw          $a2, 0x18($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X18);
    // 0x8018ED04: lw          $a3, 0x1C($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X1C);
    // 0x8018ED08: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8018ED0C: lwc1        $f16, 0x0($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X0);
    // 0x8018ED10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018ED14: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x8018ED18: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x8018ED1C: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    // 0x8018ED20: lwc1        $f18, 0x44($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X44);
    // 0x8018ED24: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    // 0x8018ED28: lwc1        $f4, 0x48($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X48);
    // 0x8018ED2C: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x8018ED30: lwc1        $f6, 0x4C($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X4C);
    // 0x8018ED34: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x8018ED38: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8018ED3C: jal         0x800C58E8
    // 0x8018ED40: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    func_800C58E8(rdram, ctx);
        goto after_19;
    // 0x8018ED40: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    after_19:
    // 0x8018ED44: b           L_8018F188
    // 0x8018ED48: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8018F188;
    // 0x8018ED48: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8018ED4C:
    // 0x8018ED4C: jal         0x8018E138
    // 0x8018ED50: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    func_8018E138_1501A0(rdram, ctx);
        goto after_20;
    // 0x8018ED50: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    after_20:
    // 0x8018ED54: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018ED58: lwc1        $f8, 0x370($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X370);
    // 0x8018ED5C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018ED60: lwc1        $f10, -0x2E30($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x8018ED64: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8018ED68: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x8018ED6C: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8018ED70: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8018ED74: addiu       $t7, $t7, 0xF98
    ctx->r15 = ADD32(ctx->r15, 0XF98);
    // 0x8018ED78: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8018ED7C: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x8018ED80: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8018ED84: addiu       $t0, $t0, 0x3C00
    ctx->r8 = ADD32(ctx->r8, 0X3C00);
    // 0x8018ED88: swc1        $f16, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f16.u32l;
    // 0x8018ED8C: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x8018ED90: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8018ED94: addiu       $a0, $a0, 0x1928
    ctx->r4 = ADD32(ctx->r4, 0X1928);
    // 0x8018ED98: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8018ED9C: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x8018EDA0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8018EDA4: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8018EDA8: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8018EDAC: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8018EDB0: lwc1        $f18, 0x20($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X20);
    // 0x8018EDB4: lw          $a2, 0x18($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X18);
    // 0x8018EDB8: lw          $a3, 0x1C($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X1C);
    // 0x8018EDBC: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x8018EDC0: lwc1        $f4, 0x0($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X0);
    // 0x8018EDC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018EDC8: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x8018EDCC: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x8018EDD0: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x8018EDD4: lwc1        $f6, 0x44($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X44);
    // 0x8018EDD8: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x8018EDDC: lwc1        $f8, 0x48($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X48);
    // 0x8018EDE0: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x8018EDE4: lwc1        $f10, 0x4C($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X4C);
    // 0x8018EDE8: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x8018EDEC: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8018EDF0: jal         0x800C58E8
    // 0x8018EDF4: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    func_800C58E8(rdram, ctx);
        goto after_21;
    // 0x8018EDF4: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    after_21:
    // 0x8018EDF8: b           L_8018F188
    // 0x8018EDFC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8018F188;
    // 0x8018EDFC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8018EE00:
    // 0x8018EE00: jal         0x8018E138
    // 0x8018EE04: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    func_8018E138_1501A0(rdram, ctx);
        goto after_22;
    // 0x8018EE04: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    after_22:
    // 0x8018EE08: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018EE0C: lwc1        $f16, 0x374($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X374);
    // 0x8018EE10: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018EE14: lwc1        $f18, -0x2E30($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x8018EE18: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8018EE1C: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x8018EE20: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8018EE24: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8018EE28: addiu       $t5, $t5, 0xF98
    ctx->r13 = ADD32(ctx->r13, 0XF98);
    // 0x8018EE2C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8018EE30: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x8018EE34: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8018EE38: addiu       $t8, $t8, 0x3C00
    ctx->r24 = ADD32(ctx->r24, 0X3C00);
    // 0x8018EE3C: swc1        $f4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f4.u32l;
    // 0x8018EE40: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x8018EE44: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8018EE48: addiu       $a0, $a0, 0x1960
    ctx->r4 = ADD32(ctx->r4, 0X1960);
    // 0x8018EE4C: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8018EE50: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x8018EE54: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8018EE58: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8018EE5C: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x8018EE60: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x8018EE64: lwc1        $f6, 0x20($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X20);
    // 0x8018EE68: lw          $a2, 0x18($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X18);
    // 0x8018EE6C: lw          $a3, 0x1C($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X1C);
    // 0x8018EE70: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x8018EE74: lwc1        $f8, 0x0($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X0);
    // 0x8018EE78: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018EE7C: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x8018EE80: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8018EE84: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x8018EE88: lwc1        $f10, 0x44($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X44);
    // 0x8018EE8C: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    // 0x8018EE90: lwc1        $f16, 0x48($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X48);
    // 0x8018EE94: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x8018EE98: lwc1        $f18, 0x4C($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0X4C);
    // 0x8018EE9C: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    // 0x8018EEA0: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8018EEA4: jal         0x800C58E8
    // 0x8018EEA8: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    func_800C58E8(rdram, ctx);
        goto after_23;
    // 0x8018EEA8: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    after_23:
    // 0x8018EEAC: b           L_8018F188
    // 0x8018EEB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8018F188;
    // 0x8018EEB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8018EEB4:
    // 0x8018EEB4: jal         0x8018E138
    // 0x8018EEB8: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    func_8018E138_1501A0(rdram, ctx);
        goto after_24;
    // 0x8018EEB8: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    after_24:
    // 0x8018EEBC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018EEC0: lwc1        $f4, 0x378($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X378);
    // 0x8018EEC4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018EEC8: lwc1        $f6, -0x2E30($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x8018EECC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8018EED0: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x8018EED4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8018EED8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8018EEDC: addiu       $t3, $t3, 0xF98
    ctx->r11 = ADD32(ctx->r11, 0XF98);
    // 0x8018EEE0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8018EEE4: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x8018EEE8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8018EEEC: addiu       $t6, $t6, 0x3C00
    ctx->r14 = ADD32(ctx->r14, 0X3C00);
    // 0x8018EEF0: swc1        $f8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f8.u32l;
    // 0x8018EEF4: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x8018EEF8: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8018EEFC: addiu       $a0, $a0, 0x18C0
    ctx->r4 = ADD32(ctx->r4, 0X18C0);
    // 0x8018EF00: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8018EF04: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x8018EF08: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8018EF0C: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8018EF10: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x8018EF14: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8018EF18: lwc1        $f10, 0x20($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X20);
    // 0x8018EF1C: lw          $a2, 0x18($t4)
    ctx->r6 = MEM_W(ctx->r12, 0X18);
    // 0x8018EF20: lw          $a3, 0x1C($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X1C);
    // 0x8018EF24: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8018EF28: lwc1        $f16, 0x0($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0X0);
    // 0x8018EF2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018EF30: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x8018EF34: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x8018EF38: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    // 0x8018EF3C: lwc1        $f18, 0x44($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X44);
    // 0x8018EF40: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    // 0x8018EF44: lwc1        $f4, 0x48($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X48);
    // 0x8018EF48: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x8018EF4C: lwc1        $f6, 0x4C($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X4C);
    // 0x8018EF50: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x8018EF54: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8018EF58: jal         0x800C58E8
    // 0x8018EF5C: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    func_800C58E8(rdram, ctx);
        goto after_25;
    // 0x8018EF5C: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    after_25:
    // 0x8018EF60: b           L_8018F188
    // 0x8018EF64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8018F188;
    // 0x8018EF64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8018EF68:
    // 0x8018EF68: jal         0x8018E138
    // 0x8018EF6C: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    func_8018E138_1501A0(rdram, ctx);
        goto after_26;
    // 0x8018EF6C: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    after_26:
    // 0x8018EF70: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018EF74: lwc1        $f8, 0x37C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X37C);
    // 0x8018EF78: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018EF7C: lwc1        $f10, -0x2E30($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x8018EF80: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8018EF84: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x8018EF88: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8018EF8C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8018EF90: addiu       $t1, $t1, 0xF98
    ctx->r9 = ADD32(ctx->r9, 0XF98);
    // 0x8018EF94: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8018EF98: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x8018EF9C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8018EFA0: addiu       $t4, $t4, 0x3C00
    ctx->r12 = ADD32(ctx->r12, 0X3C00);
    // 0x8018EFA4: swc1        $f16, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f16.u32l;
    // 0x8018EFA8: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x8018EFAC: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8018EFB0: addiu       $a0, $a0, 0x18F0
    ctx->r4 = ADD32(ctx->r4, 0X18F0);
    // 0x8018EFB4: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8018EFB8: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x8018EFBC: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8018EFC0: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8018EFC4: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x8018EFC8: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8018EFCC: lwc1        $f18, 0x20($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X20);
    // 0x8018EFD0: lw          $a2, 0x18($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X18);
    // 0x8018EFD4: lw          $a3, 0x1C($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X1C);
    // 0x8018EFD8: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x8018EFDC: lwc1        $f4, 0x0($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X0);
    // 0x8018EFE0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018EFE4: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x8018EFE8: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x8018EFEC: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x8018EFF0: lwc1        $f6, 0x44($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X44);
    // 0x8018EFF4: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x8018EFF8: lwc1        $f8, 0x48($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X48);
    // 0x8018EFFC: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x8018F000: lwc1        $f10, 0x4C($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X4C);
    // 0x8018F004: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x8018F008: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x8018F00C: jal         0x800C58E8
    // 0x8018F010: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    func_800C58E8(rdram, ctx);
        goto after_27;
    // 0x8018F010: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    after_27:
    // 0x8018F014: b           L_8018F188
    // 0x8018F018: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8018F188;
    // 0x8018F018: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8018F01C:
    // 0x8018F01C: jal         0x8018E138
    // 0x8018F020: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    func_8018E138_1501A0(rdram, ctx);
        goto after_28;
    // 0x8018F020: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    after_28:
    // 0x8018F024: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018F028: lwc1        $f16, 0x380($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X380);
    // 0x8018F02C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018F030: lwc1        $f18, -0x2E30($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x8018F034: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8018F038: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x8018F03C: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8018F040: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8018F044: addiu       $t9, $t9, 0xF98
    ctx->r25 = ADD32(ctx->r25, 0XF98);
    // 0x8018F048: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8018F04C: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x8018F050: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8018F054: addiu       $t2, $t2, 0x3C00
    ctx->r10 = ADD32(ctx->r10, 0X3C00);
    // 0x8018F058: swc1        $f4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f4.u32l;
    // 0x8018F05C: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x8018F060: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8018F064: addiu       $a0, $a0, 0x1928
    ctx->r4 = ADD32(ctx->r4, 0X1928);
    // 0x8018F068: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8018F06C: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8018F070: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8018F074: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8018F078: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8018F07C: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8018F080: lwc1        $f6, 0x20($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X20);
    // 0x8018F084: lw          $a2, 0x18($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X18);
    // 0x8018F088: lw          $a3, 0x1C($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X1C);
    // 0x8018F08C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x8018F090: lwc1        $f8, 0x0($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X0);
    // 0x8018F094: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018F098: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x8018F09C: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8018F0A0: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x8018F0A4: lwc1        $f10, 0x44($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X44);
    // 0x8018F0A8: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    // 0x8018F0AC: lwc1        $f16, 0x48($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X48);
    // 0x8018F0B0: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x8018F0B4: lwc1        $f18, 0x4C($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X4C);
    // 0x8018F0B8: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    // 0x8018F0BC: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8018F0C0: jal         0x800C58E8
    // 0x8018F0C4: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    func_800C58E8(rdram, ctx);
        goto after_29;
    // 0x8018F0C4: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    after_29:
    // 0x8018F0C8: b           L_8018F188
    // 0x8018F0CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8018F188;
    // 0x8018F0CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8018F0D0:
    // 0x8018F0D0: jal         0x8018E138
    // 0x8018F0D4: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    func_8018E138_1501A0(rdram, ctx);
        goto after_30;
    // 0x8018F0D4: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    after_30:
    // 0x8018F0D8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018F0DC: lwc1        $f4, 0x384($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X384);
    // 0x8018F0E0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018F0E4: lwc1        $f6, -0x2E30($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x8018F0E8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8018F0EC: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x8018F0F0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8018F0F4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8018F0F8: addiu       $t7, $t7, 0xF98
    ctx->r15 = ADD32(ctx->r15, 0XF98);
    // 0x8018F0FC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8018F100: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x8018F104: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8018F108: addiu       $t0, $t0, 0x3C00
    ctx->r8 = ADD32(ctx->r8, 0X3C00);
    // 0x8018F10C: swc1        $f8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f8.u32l;
    // 0x8018F110: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x8018F114: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8018F118: addiu       $a0, $a0, 0x1960
    ctx->r4 = ADD32(ctx->r4, 0X1960);
    // 0x8018F11C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8018F120: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x8018F124: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8018F128: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8018F12C: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8018F130: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8018F134: lwc1        $f10, 0x20($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X20);
    // 0x8018F138: lw          $a2, 0x18($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X18);
    // 0x8018F13C: lw          $a3, 0x1C($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X1C);
    // 0x8018F140: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8018F144: lwc1        $f16, 0x0($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X0);
    // 0x8018F148: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018F14C: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x8018F150: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x8018F154: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    // 0x8018F158: lwc1        $f18, 0x44($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X44);
    // 0x8018F15C: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    // 0x8018F160: lwc1        $f4, 0x48($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X48);
    // 0x8018F164: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x8018F168: lwc1        $f6, 0x4C($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X4C);
    // 0x8018F16C: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x8018F170: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8018F174: jal         0x800C58E8
    // 0x8018F178: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    func_800C58E8(rdram, ctx);
        goto after_31;
    // 0x8018F178: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    after_31:
    // 0x8018F17C: b           L_8018F188
    // 0x8018F180: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8018F188;
    // 0x8018F180: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8018F184:
    // 0x8018F184: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8018F188:
    // 0x8018F188: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8018F18C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8018F190: jr          $ra
    // 0x8018F194: nop

    return;
    // 0x8018F194: nop

;}
RECOMP_FUNC void func_8018F198_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018F198: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8018F19C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018F1A0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_8018F1A4:
    // 0x8018F1A4: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8018F1A8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8018F1AC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8018F1B0: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8018F1B4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8018F1B8: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8018F1BC: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8018F1C0: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8018F1C4: lw          $t8, 0xF98($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XF98);
    // 0x8018F1C8: beq         $t8, $zero, L_8018F2D4
    if (ctx->r24 == 0) {
        // 0x8018F1CC: nop
    
            goto L_8018F2D4;
    }
    // 0x8018F1CC: nop

    // 0x8018F1D0: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8018F1D4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018F1D8: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8018F1DC: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x8018F1E0: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8018F1E4: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8018F1E8: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x8018F1EC: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x8018F1F0: lwc1        $f4, 0xFCC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XFCC);
    // 0x8018F1F4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018F1F8: lwc1        $f6, -0x2C14($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2C14);
    // 0x8018F1FC: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8018F200: nop

    // 0x8018F204: bc1t        L_8018F2D4
    if (c1cs) {
        // 0x8018F208: nop
    
            goto L_8018F2D4;
    }
    // 0x8018F208: nop

    // 0x8018F20C: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8018F210: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8018F214: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8018F218: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x8018F21C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8018F220: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8018F224: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x8018F228: addu        $a0, $a0, $t2
    ctx->r4 = ADD32(ctx->r4, ctx->r10);
    // 0x8018F22C: lw          $a0, 0xF98($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XF98);
    // 0x8018F230: jal         0x8018E5D4
    // 0x8018F234: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    func_8018E5D4_1501A0(rdram, ctx);
        goto after_0;
    // 0x8018F234: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    after_0:
    // 0x8018F238: bne         $v0, $zero, L_8018F2D4
    if (ctx->r2 != 0) {
        // 0x8018F23C: nop
    
            goto L_8018F2D4;
    }
    // 0x8018F23C: nop

    // 0x8018F240: lui         $t3, 0x8011
    ctx->r11 = S32(0X8011 << 16);
    // 0x8018F244: lw          $t3, -0x4514($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4514);
    // 0x8018F248: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8018F24C: lui         $t5, 0xDE00
    ctx->r13 = S32(0XDE00 << 16);
    // 0x8018F250: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x8018F254: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8018F258: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x8018F25C: sw          $t4, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r12;
    // 0x8018F260: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x8018F264: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8018F268: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8018F26C: addiu       $t7, $t7, -0x68E8
    ctx->r15 = ADD32(ctx->r15, -0X68E8);
    // 0x8018F270: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x8018F274: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8018F278: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8018F27C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8018F280: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x8018F284: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8018F288: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8018F28C: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x8018F290: addu        $a0, $a0, $t0
    ctx->r4 = ADD32(ctx->r4, ctx->r8);
    // 0x8018F294: lw          $a0, 0xF98($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XF98);
    // 0x8018F298: jal         0x8018CDCC
    // 0x8018F29C: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    func_8018CDCC_1501A0(rdram, ctx);
        goto after_1;
    // 0x8018F29C: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    after_1:
    // 0x8018F2A0: bne         $v0, $zero, L_8018F2D4
    if (ctx->r2 != 0) {
        // 0x8018F2A4: nop
    
            goto L_8018F2D4;
    }
    // 0x8018F2A4: nop

    // 0x8018F2A8: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8018F2AC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8018F2B0: sll         $t1, $t2, 2
    ctx->r9 = S32(ctx->r10 << 2);
    // 0x8018F2B4: subu        $t1, $t1, $t2
    ctx->r9 = SUB32(ctx->r9, ctx->r10);
    // 0x8018F2B8: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8018F2BC: addu        $t1, $t1, $t2
    ctx->r9 = ADD32(ctx->r9, ctx->r10);
    // 0x8018F2C0: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x8018F2C4: addu        $a0, $a0, $t1
    ctx->r4 = ADD32(ctx->r4, ctx->r9);
    // 0x8018F2C8: lw          $a0, 0xF98($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XF98);
    // 0x8018F2CC: jal         0x8018DB24
    // 0x8018F2D0: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    func_8018DB24_1501A0(rdram, ctx);
        goto after_2;
    // 0x8018F2D0: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    after_2:
L_8018F2D4:
    // 0x8018F2D4: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x8018F2D8: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8018F2DC: slti        $at, $t4, 0x30
    ctx->r1 = SIGNED(ctx->r12) < 0X30 ? 1 : 0;
    // 0x8018F2E0: bne         $at, $zero, L_8018F1A4
    if (ctx->r1 != 0) {
        // 0x8018F2E4: sw          $t4, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r12;
            goto L_8018F1A4;
    }
    // 0x8018F2E4: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x8018F2E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018F2EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8018F2F0: jr          $ra
    // 0x8018F2F4: nop

    return;
    // 0x8018F2F4: nop

;}
RECOMP_FUNC void func_8018F2F8_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018F2F8: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x8018F2FC: sw          $a1, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r5;
    // 0x8018F300: lwc1        $f4, 0xBC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x8018F304: lwc1        $f6, 0xC8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x8018F308: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8018F30C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8018F310: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8018F314: sw          $a0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r4;
    // 0x8018F318: sw          $a2, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r6;
    // 0x8018F31C: sw          $a3, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r7;
    // 0x8018F320: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x8018F324: swc1        $f8, 0x50($t6)
    MEM_W(0X50, ctx->r14) = ctx->f8.u32l;
    // 0x8018F328: lwc1        $f16, 0xCC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x8018F32C: lwc1        $f10, 0xC0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x8018F330: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8018F334: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x8018F338: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8018F33C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8018F340: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x8018F344: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8018F348: swc1        $f18, 0x54($t7)
    MEM_W(0X54, ctx->r15) = ctx->f18.u32l;
    // 0x8018F34C: lwc1        $f6, 0xD0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XD0);
    // 0x8018F350: lwc1        $f4, 0xC4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x8018F354: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x8018F358: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8018F35C: swc1        $f8, 0x58($t8)
    MEM_W(0X58, ctx->r24) = ctx->f8.u32l;
    // 0x8018F360: lw          $a2, 0x58($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X58);
    // 0x8018F364: lwc1        $f14, 0x54($t9)
    ctx->f14.u32l = MEM_W(ctx->r25, 0X54);
    // 0x8018F368: jal         0x8018C6BC
    // 0x8018F36C: lwc1        $f12, 0x50($t9)
    ctx->f12.u32l = MEM_W(ctx->r25, 0X50);
    func_8018C6BC_1501A0(rdram, ctx);
        goto after_0;
    // 0x8018F36C: lwc1        $f12, 0x50($t9)
    ctx->f12.u32l = MEM_W(ctx->r25, 0X50);
    after_0:
    // 0x8018F370: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8018F374: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018F378: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8018F37C: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x8018F380: div.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8018F384: addiu       $a0, $sp, 0x78
    ctx->r4 = ADD32(ctx->r29, 0X78);
    // 0x8018F388: jal         0x800D6D20
    // 0x8018F38C: swc1        $f16, 0x4C($t0)
    MEM_W(0X4C, ctx->r8) = ctx->f16.u32l;
    guMtxIdentF_recomp(rdram, ctx);
        goto after_1;
    // 0x8018F38C: swc1        $f16, 0x4C($t0)
    MEM_W(0X4C, ctx->r8) = ctx->f16.u32l;
    after_1:
    // 0x8018F390: jal         0x800D6D20
    // 0x8018F394: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    guMtxIdentF_recomp(rdram, ctx);
        goto after_2;
    // 0x8018F394: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    after_2:
    // 0x8018F398: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8018F39C: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x8018F3A0: lwc1        $f18, 0x50($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X50);
    // 0x8018F3A4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8018F3A8: nop

    // 0x8018F3AC: c.eq.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl == ctx->f4.fl;
    // 0x8018F3B0: nop

    // 0x8018F3B4: bc1f        L_8018F3F4
    if (!c1cs) {
        // 0x8018F3B8: nop
    
            goto L_8018F3F4;
    }
    // 0x8018F3B8: nop

    // 0x8018F3BC: lwc1        $f6, 0x54($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X54);
    // 0x8018F3C0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8018F3C4: nop

    // 0x8018F3C8: c.eq.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl == ctx->f8.fl;
    // 0x8018F3CC: nop

    // 0x8018F3D0: bc1f        L_8018F3F4
    if (!c1cs) {
        // 0x8018F3D4: nop
    
            goto L_8018F3F4;
    }
    // 0x8018F3D4: nop

    // 0x8018F3D8: lwc1        $f10, 0x58($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X58);
    // 0x8018F3DC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8018F3E0: nop

    // 0x8018F3E4: c.eq.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl == ctx->f16.fl;
    // 0x8018F3E8: nop

    // 0x8018F3EC: bc1t        L_8018F6BC
    if (c1cs) {
        // 0x8018F3F0: nop
    
            goto L_8018F6BC;
    }
    // 0x8018F3F0: nop

L_8018F3F4:
    // 0x8018F3F4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8018F3F8: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x8018F3FC: lwc1        $f18, 0x50($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X50);
    // 0x8018F400: lwc1        $f6, 0x54($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X54);
    // 0x8018F404: lwc1        $f16, 0x58($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X58);
    // 0x8018F408: mul.s       $f4, $f18, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x8018F40C: nop

    // 0x8018F410: mul.s       $f8, $f6, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x8018F414: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8018F418: mul.s       $f18, $f16, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8018F41C: jal         0x800D68E0
    // 0x8018F420: add.s       $f12, $f18, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_3;
    // 0x8018F420: add.s       $f12, $f18, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f10.fl;
    after_3:
    // 0x8018F424: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018F428: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018F42C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8018F430: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x8018F434: div.s       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8018F438: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8018F43C: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x8018F440: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8018F444: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x8018F448: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8018F44C: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x8018F450: addiu       $t7, $t6, 0x5C
    ctx->r15 = ADD32(ctx->r14, 0X5C);
    // 0x8018F454: addiu       $t8, $t6, 0x60
    ctx->r24 = ADD32(ctx->r14, 0X60);
    // 0x8018F458: addiu       $t9, $t6, 0x64
    ctx->r25 = ADD32(ctx->r14, 0X64);
    // 0x8018F45C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8018F460: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8018F464: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8018F468: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x8018F46C: lwc1        $f8, 0x50($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X50);
    // 0x8018F470: mul.s       $f16, $f8, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8018F474: swc1        $f16, 0x50($t3)
    MEM_W(0X50, ctx->r11) = ctx->f16.u32l;
    // 0x8018F478: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8018F47C: lwc1        $f18, 0x54($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X54);
    // 0x8018F480: mul.s       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x8018F484: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8018F488: swc1        $f6, 0x54($t4)
    MEM_W(0X54, ctx->r12) = ctx->f6.u32l;
    // 0x8018F48C: lwc1        $f8, 0x58($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X58);
    // 0x8018F490: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8018F494: mul.s       $f16, $f8, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8018F498: swc1        $f16, 0x58($t5)
    MEM_W(0X58, ctx->r13) = ctx->f16.u32l;
    // 0x8018F49C: lw          $a3, 0x50($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X50);
    // 0x8018F4A0: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x8018F4A4: lwc1        $f10, 0x58($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X58);
    // 0x8018F4A8: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x8018F4AC: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x8018F4B0: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x8018F4B4: jal         0x8018C704
    // 0x8018F4B8: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    func_8018C704_1501A0(rdram, ctx);
        goto after_4;
    // 0x8018F4B8: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_4:
    // 0x8018F4BC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8018F4C0: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x8018F4C4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8018F4C8: swc1        $f0, 0x80($t0)
    MEM_W(0X80, ctx->r8) = ctx->f0.u32l;
    // 0x8018F4CC: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x8018F4D0: lwc1        $f6, 0x5C($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X5C);
    // 0x8018F4D4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8018F4D8: nop

    // 0x8018F4DC: c.eq.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl == ctx->f8.fl;
    // 0x8018F4E0: nop

    // 0x8018F4E4: bc1f        L_8018F524
    if (!c1cs) {
        // 0x8018F4E8: nop
    
            goto L_8018F524;
    }
    // 0x8018F4E8: nop

    // 0x8018F4EC: lwc1        $f4, 0x60($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X60);
    // 0x8018F4F0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8018F4F4: nop

    // 0x8018F4F8: c.eq.s      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.fl == ctx->f16.fl;
    // 0x8018F4FC: nop

    // 0x8018F500: bc1f        L_8018F524
    if (!c1cs) {
        // 0x8018F504: nop
    
            goto L_8018F524;
    }
    // 0x8018F504: nop

    // 0x8018F508: lwc1        $f18, 0x64($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X64);
    // 0x8018F50C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8018F510: nop

    // 0x8018F514: c.eq.s      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.fl == ctx->f10.fl;
    // 0x8018F518: nop

    // 0x8018F51C: bc1t        L_8018F548
    if (c1cs) {
        // 0x8018F520: nop
    
            goto L_8018F548;
    }
    // 0x8018F520: nop

L_8018F524:
    // 0x8018F524: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8018F528: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x8018F52C: lwc1        $f6, 0x64($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X64);
    // 0x8018F530: lw          $a1, 0x80($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X80);
    // 0x8018F534: lw          $a2, 0x5C($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X5C);
    // 0x8018F538: lw          $a3, 0x60($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X60);
    // 0x8018F53C: addiu       $a0, $sp, 0x78
    ctx->r4 = ADD32(ctx->r29, 0X78);
    // 0x8018F540: jal         0x800D7120
    // 0x8018F544: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    guAlignF_recomp(rdram, ctx);
        goto after_5;
    // 0x8018F544: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_5:
L_8018F548:
    // 0x8018F548: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8018F54C: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x8018F550: lwc1        $f8, 0x50($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X50);
    // 0x8018F554: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8018F558: nop

    // 0x8018F55C: c.eq.s      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.fl == ctx->f4.fl;
    // 0x8018F560: nop

    // 0x8018F564: bc1f        L_8018F5D4
    if (!c1cs) {
        // 0x8018F568: nop
    
            goto L_8018F5D4;
    }
    // 0x8018F568: nop

    // 0x8018F56C: lwc1        $f16, 0x58($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X58);
    // 0x8018F570: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8018F574: nop

    // 0x8018F578: c.eq.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl == ctx->f18.fl;
    // 0x8018F57C: nop

    // 0x8018F580: bc1f        L_8018F5D4
    if (!c1cs) {
        // 0x8018F584: nop
    
            goto L_8018F5D4;
    }
    // 0x8018F584: nop

    // 0x8018F588: lwc1        $f10, 0x54($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X54);
    // 0x8018F58C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8018F590: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8018F594: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8018F598: addiu       $t4, $t3, 0x68
    ctx->r12 = ADD32(ctx->r11, 0X68);
    // 0x8018F59C: addiu       $t5, $t3, 0x6C
    ctx->r13 = ADD32(ctx->r11, 0X6C);
    // 0x8018F5A0: addiu       $t7, $t3, 0x70
    ctx->r15 = ADD32(ctx->r11, 0X70);
    // 0x8018F5A4: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x8018F5A8: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x8018F5AC: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x8018F5B0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8018F5B4: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x8018F5B8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8018F5BC: jal         0x8018C704
    // 0x8018F5C0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_8018C704_1501A0(rdram, ctx);
        goto after_6;
    // 0x8018F5C0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_6:
    // 0x8018F5C4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8018F5C8: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x8018F5CC: b           L_8018F628
    // 0x8018F5D0: swc1        $f0, 0x84($t8)
    MEM_W(0X84, ctx->r24) = ctx->f0.u32l;
        goto L_8018F628;
    // 0x8018F5D0: swc1        $f0, 0x84($t8)
    MEM_W(0X84, ctx->r24) = ctx->f0.u32l;
L_8018F5D4:
    // 0x8018F5D4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8018F5D8: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x8018F5DC: lwc1        $f8, 0x50($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X50);
    // 0x8018F5E0: lwc1        $f4, 0x58($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X58);
    // 0x8018F5E4: lwc1        $f16, 0x54($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X54);
    // 0x8018F5E8: addiu       $t9, $t6, 0x68
    ctx->r25 = ADD32(ctx->r14, 0X68);
    // 0x8018F5EC: addiu       $t0, $t6, 0x6C
    ctx->r8 = ADD32(ctx->r14, 0X6C);
    // 0x8018F5F0: addiu       $t1, $t6, 0x70
    ctx->r9 = ADD32(ctx->r14, 0X70);
    // 0x8018F5F4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8018F5F8: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x8018F5FC: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8018F600: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x8018F604: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x8018F608: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x8018F60C: mov.s       $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = ctx->f8.fl;
    // 0x8018F610: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x8018F614: jal         0x8018C704
    // 0x8018F618: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_8018C704_1501A0(rdram, ctx);
        goto after_7;
    // 0x8018F618: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_7:
    // 0x8018F61C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8018F620: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x8018F624: swc1        $f0, 0x84($t2)
    MEM_W(0X84, ctx->r10) = ctx->f0.u32l;
L_8018F628:
    // 0x8018F628: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8018F62C: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x8018F630: lwc1        $f18, 0x68($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X68);
    // 0x8018F634: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8018F638: nop

    // 0x8018F63C: c.eq.s      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.fl == ctx->f10.fl;
    // 0x8018F640: nop

    // 0x8018F644: bc1f        L_8018F684
    if (!c1cs) {
        // 0x8018F648: nop
    
            goto L_8018F684;
    }
    // 0x8018F648: nop

    // 0x8018F64C: lwc1        $f6, 0x6C($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X6C);
    // 0x8018F650: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8018F654: nop

    // 0x8018F658: c.eq.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl == ctx->f8.fl;
    // 0x8018F65C: nop

    // 0x8018F660: bc1f        L_8018F684
    if (!c1cs) {
        // 0x8018F664: nop
    
            goto L_8018F684;
    }
    // 0x8018F664: nop

    // 0x8018F668: lwc1        $f16, 0x70($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X70);
    // 0x8018F66C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8018F670: nop

    // 0x8018F674: c.eq.s      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.fl == ctx->f4.fl;
    // 0x8018F678: nop

    // 0x8018F67C: bc1t        L_8018F6A8
    if (c1cs) {
        // 0x8018F680: nop
    
            goto L_8018F6A8;
    }
    // 0x8018F680: nop

L_8018F684:
    // 0x8018F684: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8018F688: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x8018F68C: lwc1        $f18, 0x70($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X70);
    // 0x8018F690: lw          $a1, 0x84($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X84);
    // 0x8018F694: lw          $a2, 0x68($t5)
    ctx->r6 = MEM_W(ctx->r13, 0X68);
    // 0x8018F698: lw          $a3, 0x6C($t5)
    ctx->r7 = MEM_W(ctx->r13, 0X6C);
    // 0x8018F69C: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x8018F6A0: jal         0x800D7120
    // 0x8018F6A4: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    guAlignF_recomp(rdram, ctx);
        goto after_8;
    // 0x8018F6A4: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_8:
L_8018F6A8:
    // 0x8018F6A8: addiu       $t3, $sp, 0x78
    ctx->r11 = ADD32(ctx->r29, 0X78);
    // 0x8018F6AC: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    // 0x8018F6B0: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    // 0x8018F6B4: jal         0x800D6F30
    // 0x8018F6B8: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    guMtxCatF_recomp(rdram, ctx);
        goto after_9;
    // 0x8018F6B8: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_9:
L_8018F6BC:
    // 0x8018F6BC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018F6C0: lwc1        $f10, 0x388($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X388);
    // 0x8018F6C4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8018F6C8: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x8018F6CC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018F6D0: swc1        $f10, 0x50($t7)
    MEM_W(0X50, ctx->r15) = ctx->f10.u32l;
    // 0x8018F6D4: lwc1        $f6, 0x38C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X38C);
    // 0x8018F6D8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8018F6DC: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x8018F6E0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8018F6E4: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x8018F6E8: swc1        $f6, 0x54($t8)
    MEM_W(0X54, ctx->r24) = ctx->f6.u32l;
    // 0x8018F6EC: lwc1        $f8, 0x4C($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X4C);
    // 0x8018F6F0: lui         $t0, 0x8011
    ctx->r8 = S32(0X8011 << 16);
    // 0x8018F6F4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8018F6F8: swc1        $f8, 0x58($t9)
    MEM_W(0X58, ctx->r25) = ctx->f8.u32l;
    // 0x8018F6FC: lw          $t0, -0x4514($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X4514);
    // 0x8018F700: lui         $t1, 0xDE00
    ctx->r9 = S32(0XDE00 << 16);
    // 0x8018F704: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x8018F708: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    // 0x8018F70C: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x8018F710: addiu       $t6, $t0, 0x8
    ctx->r14 = ADD32(ctx->r8, 0X8);
    // 0x8018F714: sw          $t6, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r14;
    // 0x8018F718: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x8018F71C: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x8018F720: addiu       $t4, $t4, -0x6710
    ctx->r12 = ADD32(ctx->r12, -0X6710);
    // 0x8018F724: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
    // 0x8018F728: lw          $t3, 0xB8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XB8);
    // 0x8018F72C: sltiu       $at, $t3, 0x6
    ctx->r1 = ctx->r11 < 0X6 ? 1 : 0;
    // 0x8018F730: beq         $at, $zero, L_8018F928
    if (ctx->r1 == 0) {
        // 0x8018F734: nop
    
            goto L_8018F928;
    }
    // 0x8018F734: nop

    // 0x8018F738: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8018F73C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018F740: addu        $at, $at, $t3
    gpr jr_addend_8018F748 = ctx->r11;
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x8018F744: lw          $t3, 0x390($at)
    ctx->r11 = ADD32(ctx->r1, 0X390);
    // 0x8018F748: jr          $t3
    // 0x8018F74C: nop

    switch (jr_addend_8018F748 >> 2) {
        case 0: goto L_8018F750; break;
        case 1: goto L_8018F7A0; break;
        case 2: goto L_8018F7F0; break;
        case 3: goto L_8018F840; break;
        case 4: goto L_8018F890; break;
        case 5: goto L_8018F8E0; break;
        default: switch_error(__func__, 0x8018F748, 0x801A0390);
    }
    // 0x8018F74C: nop

L_8018F750:
    // 0x8018F750: lwc1        $f16, 0xCC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x8018F754: lwc1        $f4, 0xD0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XD0);
    // 0x8018F758: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8018F75C: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x8018F760: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x8018F764: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x8018F768: lwc1        $f18, 0x50($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0X50);
    // 0x8018F76C: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8018F770: addiu       $a0, $a0, 0x6400
    ctx->r4 = ADD32(ctx->r4, 0X6400);
    // 0x8018F774: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    // 0x8018F778: lwc1        $f10, 0x54($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X54);
    // 0x8018F77C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018F780: addiu       $a2, $sp, 0x78
    ctx->r6 = ADD32(ctx->r29, 0X78);
    // 0x8018F784: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x8018F788: lwc1        $f6, 0x58($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X58);
    // 0x8018F78C: lw          $a3, 0xC8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC8);
    // 0x8018F790: jal         0x800C6868
    // 0x8018F794: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    func_800C6868(rdram, ctx);
        goto after_10;
    // 0x8018F794: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    after_10:
    // 0x8018F798: b           L_8018F928
    // 0x8018F79C: nop

        goto L_8018F928;
    // 0x8018F79C: nop

L_8018F7A0:
    // 0x8018F7A0: lwc1        $f8, 0xCC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x8018F7A4: lwc1        $f16, 0xD0($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XD0);
    // 0x8018F7A8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8018F7AC: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x8018F7B0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x8018F7B4: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x8018F7B8: lwc1        $f4, 0x50($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X50);
    // 0x8018F7BC: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8018F7C0: addiu       $a0, $a0, 0x6438
    ctx->r4 = ADD32(ctx->r4, 0X6438);
    // 0x8018F7C4: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x8018F7C8: lwc1        $f18, 0x54($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X54);
    // 0x8018F7CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018F7D0: addiu       $a2, $sp, 0x78
    ctx->r6 = ADD32(ctx->r29, 0X78);
    // 0x8018F7D4: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    // 0x8018F7D8: lwc1        $f10, 0x58($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X58);
    // 0x8018F7DC: lw          $a3, 0xC8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC8);
    // 0x8018F7E0: jal         0x800C6868
    // 0x8018F7E4: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    func_800C6868(rdram, ctx);
        goto after_11;
    // 0x8018F7E4: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    after_11:
    // 0x8018F7E8: b           L_8018F928
    // 0x8018F7EC: nop

        goto L_8018F928;
    // 0x8018F7EC: nop

L_8018F7F0:
    // 0x8018F7F0: lwc1        $f6, 0xCC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x8018F7F4: lwc1        $f8, 0xD0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XD0);
    // 0x8018F7F8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8018F7FC: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x8018F800: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x8018F804: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x8018F808: lwc1        $f16, 0x50($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X50);
    // 0x8018F80C: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8018F810: addiu       $a0, $a0, 0x6470
    ctx->r4 = ADD32(ctx->r4, 0X6470);
    // 0x8018F814: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x8018F818: lwc1        $f4, 0x54($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X54);
    // 0x8018F81C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018F820: addiu       $a2, $sp, 0x78
    ctx->r6 = ADD32(ctx->r29, 0X78);
    // 0x8018F824: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x8018F828: lwc1        $f18, 0x58($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X58);
    // 0x8018F82C: lw          $a3, 0xC8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC8);
    // 0x8018F830: jal         0x800C6868
    // 0x8018F834: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    func_800C6868(rdram, ctx);
        goto after_12;
    // 0x8018F834: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    after_12:
    // 0x8018F838: b           L_8018F928
    // 0x8018F83C: nop

        goto L_8018F928;
    // 0x8018F83C: nop

L_8018F840:
    // 0x8018F840: lwc1        $f10, 0xCC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x8018F844: lwc1        $f6, 0xD0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XD0);
    // 0x8018F848: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8018F84C: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x8018F850: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8018F854: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8018F858: lwc1        $f8, 0x50($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X50);
    // 0x8018F85C: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8018F860: addiu       $a0, $a0, 0x64A8
    ctx->r4 = ADD32(ctx->r4, 0X64A8);
    // 0x8018F864: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8018F868: lwc1        $f16, 0x54($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X54);
    // 0x8018F86C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018F870: addiu       $a2, $sp, 0x78
    ctx->r6 = ADD32(ctx->r29, 0X78);
    // 0x8018F874: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    // 0x8018F878: lwc1        $f4, 0x58($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X58);
    // 0x8018F87C: lw          $a3, 0xC8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC8);
    // 0x8018F880: jal         0x800C6868
    // 0x8018F884: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    func_800C6868(rdram, ctx);
        goto after_13;
    // 0x8018F884: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    after_13:
    // 0x8018F888: b           L_8018F928
    // 0x8018F88C: nop

        goto L_8018F928;
    // 0x8018F88C: nop

L_8018F890:
    // 0x8018F890: lwc1        $f18, 0xCC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x8018F894: lwc1        $f10, 0xD0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XD0);
    // 0x8018F898: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8018F89C: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x8018F8A0: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x8018F8A4: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x8018F8A8: lwc1        $f6, 0x50($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X50);
    // 0x8018F8AC: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8018F8B0: addiu       $a0, $a0, 0x64E0
    ctx->r4 = ADD32(ctx->r4, 0X64E0);
    // 0x8018F8B4: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x8018F8B8: lwc1        $f8, 0x54($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X54);
    // 0x8018F8BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018F8C0: addiu       $a2, $sp, 0x78
    ctx->r6 = ADD32(ctx->r29, 0X78);
    // 0x8018F8C4: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x8018F8C8: lwc1        $f16, 0x58($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X58);
    // 0x8018F8CC: lw          $a3, 0xC8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC8);
    // 0x8018F8D0: jal         0x800C6868
    // 0x8018F8D4: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    func_800C6868(rdram, ctx);
        goto after_14;
    // 0x8018F8D4: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    after_14:
    // 0x8018F8D8: b           L_8018F928
    // 0x8018F8DC: nop

        goto L_8018F928;
    // 0x8018F8DC: nop

L_8018F8E0:
    // 0x8018F8E0: lwc1        $f4, 0xCC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x8018F8E4: lwc1        $f18, 0xD0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XD0);
    // 0x8018F8E8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8018F8EC: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x8018F8F0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8018F8F4: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x8018F8F8: lwc1        $f10, 0x50($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X50);
    // 0x8018F8FC: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8018F900: addiu       $a0, $a0, 0x6518
    ctx->r4 = ADD32(ctx->r4, 0X6518);
    // 0x8018F904: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x8018F908: lwc1        $f6, 0x54($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X54);
    // 0x8018F90C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018F910: addiu       $a2, $sp, 0x78
    ctx->r6 = ADD32(ctx->r29, 0X78);
    // 0x8018F914: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x8018F918: lwc1        $f8, 0x58($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X58);
    // 0x8018F91C: lw          $a3, 0xC8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC8);
    // 0x8018F920: jal         0x800C6868
    // 0x8018F924: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    func_800C6868(rdram, ctx);
        goto after_15;
    // 0x8018F924: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    after_15:
L_8018F928:
    // 0x8018F928: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8018F92C: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    // 0x8018F930: jr          $ra
    // 0x8018F934: nop

    return;
    // 0x8018F934: nop

;}
RECOMP_FUNC void func_8018F938_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018F938: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x8018F93C: lw          $t6, -0x4514($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4514);
    // 0x8018F940: addiu       $sp, $sp, -0xE8
    ctx->r29 = ADD32(ctx->r29, -0XE8);
    // 0x8018F944: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8018F948: sw          $t6, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r14;
    // 0x8018F94C: lw          $t9, 0xE0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XE0);
    // 0x8018F950: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8018F954: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8018F958: sw          $t7, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r15;
    // 0x8018F95C: lui         $t8, 0xDE00
    ctx->r24 = S32(0XDE00 << 16);
    // 0x8018F960: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8018F964: lw          $t1, 0xE0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XE0);
    // 0x8018F968: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x8018F96C: addiu       $t0, $t0, -0x6710
    ctx->r8 = ADD32(ctx->r8, -0X6710);
    // 0x8018F970: lui         $t2, 0x8011
    ctx->r10 = S32(0X8011 << 16);
    // 0x8018F974: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x8018F978: lw          $t2, -0x4514($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4514);
    // 0x8018F97C: lui         $t4, 0xE300
    ctx->r12 = S32(0XE300 << 16);
    // 0x8018F980: ori         $t4, $t4, 0x1001
    ctx->r12 = ctx->r12 | 0X1001;
    // 0x8018F984: sw          $t2, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r10;
    // 0x8018F988: lw          $t5, 0xDC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XDC);
    // 0x8018F98C: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x8018F990: sw          $t3, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r11;
    // 0x8018F994: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x8018F998: lw          $t7, 0xDC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XDC);
    // 0x8018F99C: ori         $t6, $zero, 0x8000
    ctx->r14 = 0 | 0X8000;
    // 0x8018F9A0: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x8018F9A4: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x8018F9A8: lw          $t8, -0x4514($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4514);
    // 0x8018F9AC: lui         $t0, 0xFD10
    ctx->r8 = S32(0XFD10 << 16);
    // 0x8018F9B0: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x8018F9B4: sw          $t8, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r24;
    // 0x8018F9B8: lw          $t1, 0xD8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XD8);
    // 0x8018F9BC: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8018F9C0: sw          $t9, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r25;
    // 0x8018F9C4: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x8018F9C8: lw          $t3, 0xD8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XD8);
    // 0x8018F9CC: addiu       $t2, $t2, -0x4E44
    ctx->r10 = ADD32(ctx->r10, -0X4E44);
    // 0x8018F9D0: lui         $t4, 0x8011
    ctx->r12 = S32(0X8011 << 16);
    // 0x8018F9D4: sw          $t2, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r10;
    // 0x8018F9D8: lw          $t4, -0x4514($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4514);
    // 0x8018F9DC: lui         $t6, 0xE800
    ctx->r14 = S32(0XE800 << 16);
    // 0x8018F9E0: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x8018F9E4: sw          $t4, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r12;
    // 0x8018F9E8: lw          $t7, 0xD4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XD4);
    // 0x8018F9EC: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x8018F9F0: sw          $t5, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r13;
    // 0x8018F9F4: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8018F9F8: lw          $t8, 0xD4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XD4);
    // 0x8018F9FC: lui         $t1, 0xF500
    ctx->r9 = S32(0XF500 << 16);
    // 0x8018FA00: ori         $t1, $t1, 0x100
    ctx->r9 = ctx->r9 | 0X100;
    // 0x8018FA04: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x8018FA08: lw          $t9, -0x4514($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4514);
    // 0x8018FA0C: lui         $t3, 0x700
    ctx->r11 = S32(0X700 << 16);
    // 0x8018FA10: lui         $t5, 0x8011
    ctx->r13 = S32(0X8011 << 16);
    // 0x8018FA14: sw          $t9, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r25;
    // 0x8018FA18: lw          $t2, 0xD0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XD0);
    // 0x8018FA1C: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x8018FA20: sw          $t0, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r8;
    // 0x8018FA24: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x8018FA28: lw          $t4, 0xD0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XD0);
    // 0x8018FA2C: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x8018FA30: lui         $t0, 0x8011
    ctx->r8 = S32(0X8011 << 16);
    // 0x8018FA34: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    // 0x8018FA38: lw          $t5, -0x4514($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4514);
    // 0x8018FA3C: lui         $t2, 0xF000
    ctx->r10 = S32(0XF000 << 16);
    // 0x8018FA40: lui         $t4, 0x73F
    ctx->r12 = S32(0X73F << 16);
    // 0x8018FA44: sw          $t5, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r13;
    // 0x8018FA48: lw          $t8, 0xCC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XCC);
    // 0x8018FA4C: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x8018FA50: sw          $t6, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r14;
    // 0x8018FA54: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8018FA58: lw          $t9, 0xCC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XCC);
    // 0x8018FA5C: ori         $t4, $t4, 0xC000
    ctx->r12 = ctx->r12 | 0XC000;
    // 0x8018FA60: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x8018FA64: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x8018FA68: lw          $t0, -0x4514($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X4514);
    // 0x8018FA6C: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x8018FA70: sw          $t0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r8;
    // 0x8018FA74: lw          $t3, 0xC8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC8);
    // 0x8018FA78: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x8018FA7C: sw          $t1, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r9;
    // 0x8018FA80: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x8018FA84: lw          $t5, 0xC8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC8);
    // 0x8018FA88: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
    // 0x8018FA8C: lw          $t6, -0x4514($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4514);
    // 0x8018FA90: sw          $t6, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r14;
    // 0x8018FA94: lw          $t9, 0xC4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC4);
    // 0x8018FA98: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8018FA9C: sw          $t7, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r15;
    // 0x8018FAA0: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8018FAA4: lw          $t0, 0xC4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC4);
    // 0x8018FAA8: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x8018FAAC: sw          $zero, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = 0;
L_8018FAB0:
    // 0x8018FAB0: lw          $t1, 0xE4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XE4);
    // 0x8018FAB4: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8018FAB8: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x8018FABC: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8018FAC0: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8018FAC4: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8018FAC8: lw          $t3, 0x2318($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X2318);
    // 0x8018FACC: beq         $t3, $zero, L_80192160
    if (ctx->r11 == 0) {
        // 0x8018FAD0: nop
    
            goto L_80192160;
    }
    // 0x8018FAD0: nop

    // 0x8018FAD4: lw          $t4, 0xE4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XE4);
    // 0x8018FAD8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018FADC: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x8018FAE0: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8018FAE4: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8018FAE8: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x8018FAEC: lwc1        $f4, 0x2334($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X2334);
    // 0x8018FAF0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018FAF4: lwc1        $f6, -0x2C14($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2C14);
    // 0x8018FAF8: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8018FAFC: nop

    // 0x8018FB00: bc1t        L_80192160
    if (c1cs) {
        // 0x8018FB04: nop
    
            goto L_80192160;
    }
    // 0x8018FB04: nop

    // 0x8018FB08: lw          $t6, 0xE4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XE4);
    // 0x8018FB0C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8018FB10: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8018FB14: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8018FB18: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8018FB1C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8018FB20: lw          $t8, 0x2318($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X2318);
    // 0x8018FB24: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8018FB28: sltiu       $at, $t9, 0x46
    ctx->r1 = ctx->r25 < 0X46 ? 1 : 0;
    // 0x8018FB2C: beq         $at, $zero, L_80192160
    if (ctx->r1 == 0) {
        // 0x8018FB30: nop
    
            goto L_80192160;
    }
    // 0x8018FB30: nop

    // 0x8018FB34: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8018FB38: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018FB3C: addu        $at, $at, $t9
    gpr jr_addend_8018FB44 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8018FB40: lw          $t9, 0x3A8($at)
    ctx->r25 = ADD32(ctx->r1, 0X3A8);
    // 0x8018FB44: jr          $t9
    // 0x8018FB48: nop

    switch (jr_addend_8018FB44 >> 2) {
        case 0: goto L_8019061C; break;
        case 1: goto L_8018FB4C; break;
        case 2: goto L_8018FC94; break;
        case 3: goto L_8018FEC0; break;
        case 4: goto L_80190344; break;
        case 5: goto L_801907F4; break;
        case 6: goto L_801907F4; break;
        case 7: goto L_801914E8; break;
        case 8: goto L_8018FBF0; break;
        case 9: goto L_8018FE1C; break;
        case 10: goto L_8018FFE4; break;
        case 11: goto L_80190498; break;
        case 12: goto L_80192160; break;
        case 13: goto L_80192160; break;
        case 14: goto L_801915D8; break;
        case 15: goto L_801916C0; break;
        case 16: goto L_801915D8; break;
        case 17: goto L_80192160; break;
        case 18: goto L_80192160; break;
        case 19: goto L_80190724; break;
        case 20: goto L_80190724; break;
        case 21: goto L_801907F4; break;
        case 22: goto L_801908CC; break;
        case 23: goto L_80190724; break;
        case 24: goto L_801909D4; break;
        case 25: goto L_80190B00; break;
        case 26: goto L_80190C2C; break;
        case 27: goto L_80192160; break;
        case 28: goto L_80192160; break;
        case 29: goto L_80190D58; break;
        case 30: goto L_801911AC; break;
        case 31: goto L_80190E8C; break;
        case 32: goto L_801912C0; break;
        case 33: goto L_8019101C; break;
        case 34: goto L_801913D4; break;
        case 35: goto L_80192160; break;
        case 36: goto L_801914E8; break;
        case 37: goto L_801914E8; break;
        case 38: goto L_801914E8; break;
        case 39: goto L_801917A8; break;
        case 40: goto L_801918DC; break;
        case 41: goto L_80191A6C; break;
        case 42: goto L_80191BFC; break;
        case 43: goto L_80191D00; break;
        case 44: goto L_80192160; break;
        case 45: goto L_80192034; break;
        case 46: goto L_8019022C; break;
        case 47: goto L_80190108; break;
        case 48: goto L_801907F4; break;
        case 49: goto L_80191F30; break;
        case 50: goto L_801907F4; break;
        case 51: goto L_80192160; break;
        case 52: goto L_80192160; break;
        case 53: goto L_80192160; break;
        case 54: goto L_80192160; break;
        case 55: goto L_80192160; break;
        case 56: goto L_80192160; break;
        case 57: goto L_80192160; break;
        case 58: goto L_80192160; break;
        case 59: goto L_80192160; break;
        case 60: goto L_80192160; break;
        case 61: goto L_80192160; break;
        case 62: goto L_80192160; break;
        case 63: goto L_80192160; break;
        case 64: goto L_80192160; break;
        case 65: goto L_80192160; break;
        case 66: goto L_80192160; break;
        case 67: goto L_80192160; break;
        case 68: goto L_80192160; break;
        case 69: goto L_80191E04; break;
        default: switch_error(__func__, 0x8018FB44, 0x801A03A8);
    }
    // 0x8018FB48: nop

L_8018FB4C:
    // 0x8018FB4C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018FB50: lwc1        $f8, 0x4C0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X4C0);
    // 0x8018FB54: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018FB58: lwc1        $f10, -0x2E30($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x8018FB5C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8018FB60: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x8018FB64: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8018FB68: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8018FB6C: addiu       $t3, $t3, 0x2318
    ctx->r11 = ADD32(ctx->r11, 0X2318);
    // 0x8018FB70: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8018FB74: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x8018FB78: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8018FB7C: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x8018FB80: swc1        $f16, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f16.u32l;
    // 0x8018FB84: lw          $t1, 0xE4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XE4);
    // 0x8018FB88: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8018FB8C: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x8018FB90: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x8018FB94: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8018FB98: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8018FB9C: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8018FBA0: lwc1        $f18, 0x18($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X18);
    // 0x8018FBA4: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x8018FBA8: lw          $a2, 0x10($t4)
    ctx->r6 = MEM_W(ctx->r12, 0X10);
    // 0x8018FBAC: lw          $a3, 0x14($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X14);
    // 0x8018FBB0: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x8018FBB4: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    // 0x8018FBB8: andi        $t6, $t5, 0x3
    ctx->r14 = ctx->r13 & 0X3;
    // 0x8018FBBC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8018FBC0: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x8018FBC4: lwc1        $f6, 0x0($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X0);
    // 0x8018FBC8: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8018FBCC: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x8018FBD0: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x8018FBD4: lwc1        $f8, 0x0($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8018FBD8: lw          $a0, -0x11EC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X11EC);
    // 0x8018FBDC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018FBE0: jal         0x800C60A0
    // 0x8018FBE4: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    func_800C60A0(rdram, ctx);
        goto after_0;
    // 0x8018FBE4: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x8018FBE8: b           L_80192160
    // 0x8018FBEC: nop

        goto L_80192160;
    // 0x8018FBEC: nop

L_8018FBF0:
    // 0x8018FBF0: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x8018FBF4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018FBF8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018FBFC: lwc1        $f16, -0x2E30($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x8018FC00: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8018FC04: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x8018FC08: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8018FC0C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8018FC10: addiu       $t5, $t5, 0x2318
    ctx->r13 = ADD32(ctx->r13, 0X2318);
    // 0x8018FC14: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8018FC18: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x8018FC1C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8018FC20: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x8018FC24: swc1        $f18, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f18.u32l;
    // 0x8018FC28: lw          $t2, 0xE4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XE4);
    // 0x8018FC2C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8018FC30: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x8018FC34: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x8018FC38: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8018FC3C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8018FC40: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x8018FC44: lwc1        $f4, 0x18($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X18);
    // 0x8018FC48: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x8018FC4C: lw          $a2, 0x10($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X10);
    // 0x8018FC50: lw          $a3, 0x14($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X14);
    // 0x8018FC54: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8018FC58: lwc1        $f6, 0x0($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X0);
    // 0x8018FC5C: andi        $t4, $t7, 0x3
    ctx->r12 = ctx->r15 & 0X3;
    // 0x8018FC60: sll         $t8, $t4, 2
    ctx->r24 = S32(ctx->r12 << 2);
    // 0x8018FC64: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8018FC68: lwc1        $f8, 0x0($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8018FC6C: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8018FC70: addu        $a0, $a0, $t8
    ctx->r4 = ADD32(ctx->r4, ctx->r24);
    // 0x8018FC74: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8018FC78: lwc1        $f10, 0x0($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X0);
    // 0x8018FC7C: lw          $a0, -0x1174($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1174);
    // 0x8018FC80: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018FC84: jal         0x800C60A0
    // 0x8018FC88: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    func_800C60A0(rdram, ctx);
        goto after_1;
    // 0x8018FC88: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x8018FC8C: b           L_80192160
    // 0x8018FC90: nop

        goto L_80192160;
    // 0x8018FC90: nop

L_8018FC94:
    // 0x8018FC94: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8018FC98: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8018FC9C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018FCA0: lwc1        $f18, -0x2E30($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x8018FCA4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8018FCA8: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x8018FCAC: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8018FCB0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8018FCB4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8018FCB8: addiu       $t8, $t8, 0x3C00
    ctx->r24 = ADD32(ctx->r24, 0X3C00);
    // 0x8018FCBC: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x8018FCC0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8018FCC4: lui         $t0, 0xE700
    ctx->r8 = S32(0XE700 << 16);
    // 0x8018FCC8: swc1        $f4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f4.u32l;
    // 0x8018FCCC: lw          $t3, 0xE4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XE4);
    // 0x8018FCD0: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8018FCD4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018FCD8: sll         $t5, $t3, 3
    ctx->r13 = S32(ctx->r11 << 3);
    // 0x8018FCDC: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x8018FCE0: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8018FCE4: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x8018FCE8: lw          $t7, 0x2320($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X2320);
    // 0x8018FCEC: lui         $t3, 0x8011
    ctx->r11 = S32(0X8011 << 16);
    // 0x8018FCF0: andi        $t4, $t7, 0x7
    ctx->r12 = ctx->r15 & 0X7;
    // 0x8018FCF4: sw          $t4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r12;
    // 0x8018FCF8: lw          $t6, -0x4514($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4514);
    // 0x8018FCFC: lui         $t7, 0xFB00
    ctx->r15 = S32(0XFB00 << 16);
    // 0x8018FD00: lui         $t8, 0xFF00
    ctx->r24 = S32(0XFF00 << 16);
    // 0x8018FD04: sw          $t6, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r14;
    // 0x8018FD08: lw          $t1, 0xC0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC0);
    // 0x8018FD0C: addiu       $t9, $t6, 0x8
    ctx->r25 = ADD32(ctx->r14, 0X8);
    // 0x8018FD10: sw          $t9, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r25;
    // 0x8018FD14: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x8018FD18: lw          $t2, 0xC0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC0);
    // 0x8018FD1C: ori         $t8, $t8, 0xFF
    ctx->r24 = ctx->r24 | 0XFF;
    // 0x8018FD20: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x8018FD24: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x8018FD28: lw          $t3, -0x4514($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4514);
    // 0x8018FD2C: lui         $t1, 0xFA00
    ctx->r9 = S32(0XFA00 << 16);
    // 0x8018FD30: sw          $t3, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r11;
    // 0x8018FD34: lw          $t4, 0xBC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XBC);
    // 0x8018FD38: addiu       $t5, $t3, 0x8
    ctx->r13 = ADD32(ctx->r11, 0X8);
    // 0x8018FD3C: sw          $t5, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r13;
    // 0x8018FD40: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    // 0x8018FD44: lw          $t6, 0xBC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XBC);
    // 0x8018FD48: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8018FD4C: addiu       $t3, $t3, 0x3C00
    ctx->r11 = ADD32(ctx->r11, 0X3C00);
    // 0x8018FD50: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x8018FD54: lw          $t9, -0x4514($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4514);
    // 0x8018FD58: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x8018FD5C: sw          $t9, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r25;
    // 0x8018FD60: lw          $t2, 0xB8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XB8);
    // 0x8018FD64: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x8018FD68: sw          $t0, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r8;
    // 0x8018FD6C: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x8018FD70: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x8018FD74: lw          $t0, 0xB8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB8);
    // 0x8018FD78: lui         $at, 0xFFDC
    ctx->r1 = S32(0XFFDC << 16);
    // 0x8018FD7C: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x8018FD80: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x8018FD84: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8018FD88: subu        $t8, $t4, $t7
    ctx->r24 = SUB32(ctx->r12, ctx->r15);
    // 0x8018FD8C: andi        $t6, $t8, 0xFF
    ctx->r14 = ctx->r24 & 0XFF;
    // 0x8018FD90: ori         $at, $at, 0x4000
    ctx->r1 = ctx->r1 | 0X4000;
    // 0x8018FD94: or          $t9, $t6, $at
    ctx->r25 = ctx->r14 | ctx->r1;
    // 0x8018FD98: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x8018FD9C: lw          $t5, 0xE4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XE4);
    // 0x8018FDA0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8018FDA4: addiu       $t7, $t7, 0x2318
    ctx->r15 = ADD32(ctx->r15, 0X2318);
    // 0x8018FDA8: sll         $t4, $t5, 3
    ctx->r12 = S32(ctx->r13 << 3);
    // 0x8018FDAC: addu        $t4, $t4, $t5
    ctx->r12 = ADD32(ctx->r12, ctx->r13);
    // 0x8018FDB0: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8018FDB4: addu        $t8, $t4, $t7
    ctx->r24 = ADD32(ctx->r12, ctx->r15);
    // 0x8018FDB8: lwc1        $f6, 0x18($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X18);
    // 0x8018FDBC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8018FDC0: addiu       $t1, $t1, 0x3C00
    ctx->r9 = ADD32(ctx->r9, 0X3C00);
    // 0x8018FDC4: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8018FDC8: lw          $a2, 0x10($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X10);
    // 0x8018FDCC: lw          $a3, 0x14($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X14);
    // 0x8018FDD0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8018FDD4: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x8018FDD8: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x8018FDDC: lwc1        $f8, 0x0($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X0);
    // 0x8018FDE0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8018FDE4: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x8018FDE8: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x8018FDEC: lwc1        $f10, 0x0($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X0);
    // 0x8018FDF0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8018FDF4: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x8018FDF8: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x8018FDFC: lwc1        $f16, 0x0($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8018FE00: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8018FE04: addu        $a0, $a0, $t3
    ctx->r4 = ADD32(ctx->r4, ctx->r11);
    // 0x8018FE08: lw          $a0, -0x108C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X108C);
    // 0x8018FE0C: jal         0x800C60A0
    // 0x8018FE10: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    func_800C60A0(rdram, ctx);
        goto after_2;
    // 0x8018FE10: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    after_2:
    // 0x8018FE14: b           L_80192160
    // 0x8018FE18: nop

        goto L_80192160;
    // 0x8018FE18: nop

L_8018FE1C:
    // 0x8018FE1C: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x8018FE20: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018FE24: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018FE28: lwc1        $f4, -0x2E30($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x8018FE2C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8018FE30: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x8018FE34: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8018FE38: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8018FE3C: addiu       $t5, $t5, 0x2318
    ctx->r13 = ADD32(ctx->r13, 0X2318);
    // 0x8018FE40: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8018FE44: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x8018FE48: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8018FE4C: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x8018FE50: swc1        $f6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f6.u32l;
    // 0x8018FE54: lw          $t2, 0xE4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XE4);
    // 0x8018FE58: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8018FE5C: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x8018FE60: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x8018FE64: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8018FE68: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8018FE6C: addu        $t4, $t3, $t5
    ctx->r12 = ADD32(ctx->r11, ctx->r13);
    // 0x8018FE70: lwc1        $f8, 0x18($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X18);
    // 0x8018FE74: lw          $t7, 0x8($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X8);
    // 0x8018FE78: lw          $a2, 0x10($t4)
    ctx->r6 = MEM_W(ctx->r12, 0X10);
    // 0x8018FE7C: lw          $a3, 0x14($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X14);
    // 0x8018FE80: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x8018FE84: lwc1        $f10, 0x0($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X0);
    // 0x8018FE88: andi        $t8, $t7, 0x3
    ctx->r24 = ctx->r15 & 0X3;
    // 0x8018FE8C: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x8018FE90: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x8018FE94: lwc1        $f16, 0x0($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8018FE98: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8018FE9C: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x8018FEA0: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x8018FEA4: lwc1        $f18, 0x0($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X0);
    // 0x8018FEA8: lw          $a0, -0x1164($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1164);
    // 0x8018FEAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018FEB0: jal         0x800C60A0
    // 0x8018FEB4: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    func_800C60A0(rdram, ctx);
        goto after_3;
    // 0x8018FEB4: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    after_3:
    // 0x8018FEB8: b           L_80192160
    // 0x8018FEBC: nop

        goto L_80192160;
    // 0x8018FEBC: nop

L_8018FEC0:
    // 0x8018FEC0: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8018FEC4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018FEC8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018FECC: lwc1        $f6, -0x2E30($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x8018FED0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8018FED4: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x8018FED8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8018FEDC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8018FEE0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8018FEE4: addiu       $t8, $t8, 0x3C00
    ctx->r24 = ADD32(ctx->r24, 0X3C00);
    // 0x8018FEE8: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x8018FEEC: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8018FEF0: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x8018FEF4: swc1        $f8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f8.u32l;
    // 0x8018FEF8: lw          $t3, 0xE4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XE4);
    // 0x8018FEFC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8018FF00: addiu       $t1, $t1, 0x3C00
    ctx->r9 = ADD32(ctx->r9, 0X3C00);
    // 0x8018FF04: sll         $t5, $t3, 3
    ctx->r13 = S32(ctx->r11 << 3);
    // 0x8018FF08: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x8018FF0C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8018FF10: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x8018FF14: lw          $t7, 0x2320($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X2320);
    // 0x8018FF18: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x8018FF1C: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8018FF20: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8018FF24: lw          $t6, -0x4514($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4514);
    // 0x8018FF28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018FF2C: sw          $t6, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r14;
    // 0x8018FF30: lw          $t0, 0xB4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB4);
    // 0x8018FF34: addiu       $t4, $t6, 0x8
    ctx->r12 = ADD32(ctx->r14, 0X8);
    // 0x8018FF38: sw          $t4, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r12;
    // 0x8018FF3C: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x8018FF40: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8018FF44: lw          $t8, 0xB4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB4);
    // 0x8018FF48: lui         $at, 0xE6FF
    ctx->r1 = S32(0XE6FF << 16);
    // 0x8018FF4C: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8018FF50: lbu         $t3, -0xFB8($t3)
    ctx->r11 = MEM_BU(ctx->r11, -0XFB8);
    // 0x8018FF54: ori         $at, $at, 0xFF00
    ctx->r1 = ctx->r1 | 0XFF00;
    // 0x8018FF58: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8018FF5C: andi        $t5, $t3, 0xFF
    ctx->r13 = ctx->r11 & 0XFF;
    // 0x8018FF60: or          $t7, $t5, $at
    ctx->r15 = ctx->r13 | ctx->r1;
    // 0x8018FF64: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x8018FF68: lw          $t0, 0xE4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XE4);
    // 0x8018FF6C: addiu       $t2, $t2, 0x2318
    ctx->r10 = ADD32(ctx->r10, 0X2318);
    // 0x8018FF70: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8018FF74: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x8018FF78: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8018FF7C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8018FF80: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x8018FF84: lwc1        $f10, 0x18($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X18);
    // 0x8018FF88: addiu       $t6, $t6, 0x3C00
    ctx->r14 = ADD32(ctx->r14, 0X3C00);
    // 0x8018FF8C: lw          $t4, 0x0($t6)
    ctx->r12 = MEM_W(ctx->r14, 0X0);
    // 0x8018FF90: lw          $a2, 0x10($t3)
    ctx->r6 = MEM_W(ctx->r11, 0X10);
    // 0x8018FF94: lw          $a3, 0x14($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X14);
    // 0x8018FF98: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8018FF9C: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x8018FFA0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8018FFA4: lwc1        $f16, 0x0($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0X0);
    // 0x8018FFA8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8018FFAC: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x8018FFB0: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x8018FFB4: lwc1        $f18, 0x0($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0X0);
    // 0x8018FFB8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8018FFBC: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x8018FFC0: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    // 0x8018FFC4: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    // 0x8018FFC8: sll         $t9, $t4, 2
    ctx->r25 = S32(ctx->r12 << 2);
    // 0x8018FFCC: addu        $a0, $a0, $t9
    ctx->r4 = ADD32(ctx->r4, ctx->r25);
    // 0x8018FFD0: lw          $a0, -0x1154($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1154);
    // 0x8018FFD4: jal         0x800C60A0
    // 0x8018FFD8: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    func_800C60A0(rdram, ctx);
        goto after_4;
    // 0x8018FFD8: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    after_4:
    // 0x8018FFDC: b           L_80192160
    // 0x8018FFE0: nop

        goto L_80192160;
    // 0x8018FFE0: nop

L_8018FFE4:
    // 0x8018FFE4: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8018FFE8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018FFEC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8018FFF0: lwc1        $f8, -0x2E30($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x8018FFF4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8018FFF8: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x8018FFFC: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80190000: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80190004: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80190008: addiu       $t1, $t1, 0x3C00
    ctx->r9 = ADD32(ctx->r9, 0X3C00);
    // 0x8019000C: lui         $t2, 0x8011
    ctx->r10 = S32(0X8011 << 16);
    // 0x80190010: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80190014: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x80190018: swc1        $f10, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f10.u32l;
    // 0x8019001C: lw          $t4, 0xE4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XE4);
    // 0x80190020: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80190024: addiu       $t8, $t8, 0x3C00
    ctx->r24 = ADD32(ctx->r24, 0X3C00);
    // 0x80190028: sll         $t9, $t4, 3
    ctx->r25 = S32(ctx->r12 << 3);
    // 0x8019002C: addu        $t9, $t9, $t4
    ctx->r25 = ADD32(ctx->r25, ctx->r12);
    // 0x80190030: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80190034: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80190038: lw          $t0, 0x2320($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X2320);
    // 0x8019003C: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x80190040: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80190044: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x80190048: lw          $t2, -0x4514($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4514);
    // 0x8019004C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80190050: sw          $t2, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r10;
    // 0x80190054: lw          $t7, 0xB0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB0);
    // 0x80190058: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x8019005C: sw          $t3, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r11;
    // 0x80190060: sw          $t5, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r13;
    // 0x80190064: lw          $t6, 0x0($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X0);
    // 0x80190068: lw          $t1, 0xB0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XB0);
    // 0x8019006C: lui         $at, 0xE6FF
    ctx->r1 = S32(0XE6FF << 16);
    // 0x80190070: addu        $t4, $t4, $t6
    ctx->r12 = ADD32(ctx->r12, ctx->r14);
    // 0x80190074: lbu         $t4, -0xFB8($t4)
    ctx->r12 = MEM_BU(ctx->r12, -0XFB8);
    // 0x80190078: ori         $at, $at, 0xFF00
    ctx->r1 = ctx->r1 | 0XFF00;
    // 0x8019007C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80190080: andi        $t9, $t4, 0xFF
    ctx->r25 = ctx->r12 & 0XFF;
    // 0x80190084: or          $t0, $t9, $at
    ctx->r8 = ctx->r25 | ctx->r1;
    // 0x80190088: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x8019008C: lw          $t7, 0xE4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XE4);
    // 0x80190090: addiu       $t6, $t6, 0x2318
    ctx->r14 = ADD32(ctx->r14, 0X2318);
    // 0x80190094: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80190098: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8019009C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x801900A0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x801900A4: addu        $t4, $t8, $t6
    ctx->r12 = ADD32(ctx->r24, ctx->r14);
    // 0x801900A8: lwc1        $f16, 0x18($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X18);
    // 0x801900AC: addiu       $t2, $t2, 0x3C00
    ctx->r10 = ADD32(ctx->r10, 0X3C00);
    // 0x801900B0: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x801900B4: lw          $a2, 0x10($t4)
    ctx->r6 = MEM_W(ctx->r12, 0X10);
    // 0x801900B8: lw          $a3, 0x14($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X14);
    // 0x801900BC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801900C0: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x801900C4: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x801900C8: lwc1        $f18, 0x0($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X0);
    // 0x801900CC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x801900D0: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x801900D4: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x801900D8: lwc1        $f4, 0x0($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X0);
    // 0x801900DC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x801900E0: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x801900E4: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x801900E8: lwc1        $f6, 0x0($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X0);
    // 0x801900EC: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x801900F0: addu        $a0, $a0, $t5
    ctx->r4 = ADD32(ctx->r4, ctx->r13);
    // 0x801900F4: lw          $a0, -0x1154($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1154);
    // 0x801900F8: jal         0x800C60A0
    // 0x801900FC: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    func_800C60A0(rdram, ctx);
        goto after_5;
    // 0x801900FC: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    after_5:
    // 0x80190100: b           L_80192160
    // 0x80190104: nop

        goto L_80192160;
    // 0x80190104: nop

L_80190108:
    // 0x80190108: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8019010C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80190110: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80190114: lwc1        $f10, -0x2E30($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x80190118: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8019011C: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x80190120: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80190124: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80190128: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8019012C: addiu       $t8, $t8, 0x3C00
    ctx->r24 = ADD32(ctx->r24, 0X3C00);
    // 0x80190130: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x80190134: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80190138: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x8019013C: swc1        $f16, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f16.u32l;
    // 0x80190140: lw          $t3, 0xE4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XE4);
    // 0x80190144: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80190148: addiu       $t1, $t1, 0x3C00
    ctx->r9 = ADD32(ctx->r9, 0X3C00);
    // 0x8019014C: sll         $t5, $t3, 3
    ctx->r13 = S32(ctx->r11 << 3);
    // 0x80190150: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x80190154: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80190158: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x8019015C: lw          $t7, 0x2320($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X2320);
    // 0x80190160: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80190164: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80190168: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8019016C: lw          $t6, -0x4514($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4514);
    // 0x80190170: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80190174: sw          $t6, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r14;
    // 0x80190178: lw          $t0, 0xAC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XAC);
    // 0x8019017C: addiu       $t4, $t6, 0x8
    ctx->r12 = ADD32(ctx->r14, 0X8);
    // 0x80190180: sw          $t4, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r12;
    // 0x80190184: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80190188: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8019018C: lw          $t8, 0xAC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XAC);
    // 0x80190190: lui         $at, 0xE6FF
    ctx->r1 = S32(0XE6FF << 16);
    // 0x80190194: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80190198: lbu         $t3, -0xFB8($t3)
    ctx->r11 = MEM_BU(ctx->r11, -0XFB8);
    // 0x8019019C: ori         $at, $at, 0xFF00
    ctx->r1 = ctx->r1 | 0XFF00;
    // 0x801901A0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x801901A4: andi        $t5, $t3, 0xFF
    ctx->r13 = ctx->r11 & 0XFF;
    // 0x801901A8: or          $t7, $t5, $at
    ctx->r15 = ctx->r13 | ctx->r1;
    // 0x801901AC: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x801901B0: lw          $t0, 0xE4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XE4);
    // 0x801901B4: addiu       $t2, $t2, 0x2318
    ctx->r10 = ADD32(ctx->r10, 0X2318);
    // 0x801901B8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801901BC: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x801901C0: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x801901C4: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x801901C8: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x801901CC: lwc1        $f18, 0x18($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X18);
    // 0x801901D0: addiu       $t6, $t6, 0x3C00
    ctx->r14 = ADD32(ctx->r14, 0X3C00);
    // 0x801901D4: lw          $t4, 0x0($t6)
    ctx->r12 = MEM_W(ctx->r14, 0X0);
    // 0x801901D8: lw          $a2, 0x10($t3)
    ctx->r6 = MEM_W(ctx->r11, 0X10);
    // 0x801901DC: lw          $a3, 0x14($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X14);
    // 0x801901E0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x801901E4: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x801901E8: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x801901EC: lwc1        $f4, 0x0($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X0);
    // 0x801901F0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801901F4: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x801901F8: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x801901FC: lwc1        $f6, 0x0($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X0);
    // 0x80190200: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80190204: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x80190208: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x8019020C: lwc1        $f8, 0x0($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X0);
    // 0x80190210: sll         $t9, $t4, 2
    ctx->r25 = S32(ctx->r12 << 2);
    // 0x80190214: addu        $a0, $a0, $t9
    ctx->r4 = ADD32(ctx->r4, ctx->r25);
    // 0x80190218: lw          $a0, -0x1154($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1154);
    // 0x8019021C: jal         0x800C60A0
    // 0x80190220: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    func_800C60A0(rdram, ctx);
        goto after_6;
    // 0x80190220: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    after_6:
    // 0x80190224: b           L_80192160
    // 0x80190228: nop

        goto L_80192160;
    // 0x80190228: nop

L_8019022C:
    // 0x8019022C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80190230: lwc1        $f10, -0x2E30($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x80190234: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80190238: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x8019023C: swc1        $f10, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f10.u32l;
    // 0x80190240: lw          $t4, 0xE4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XE4);
    // 0x80190244: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80190248: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8019024C: sll         $t9, $t4, 3
    ctx->r25 = S32(ctx->r12 << 3);
    // 0x80190250: addu        $t9, $t9, $t4
    ctx->r25 = ADD32(ctx->r25, ctx->r12);
    // 0x80190254: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80190258: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8019025C: lw          $t0, 0x2320($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X2320);
    // 0x80190260: addiu       $t1, $t1, 0x3C00
    ctx->r9 = ADD32(ctx->r9, 0X3C00);
    // 0x80190264: lui         $t2, 0x8011
    ctx->r10 = S32(0X8011 << 16);
    // 0x80190268: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x8019026C: lw          $t2, -0x4514($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4514);
    // 0x80190270: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80190274: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x80190278: sw          $t2, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r10;
    // 0x8019027C: lw          $t7, 0xA8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA8);
    // 0x80190280: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x80190284: sw          $t3, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r11;
    // 0x80190288: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8019028C: addiu       $t8, $t8, 0x3C00
    ctx->r24 = ADD32(ctx->r24, 0X3C00);
    // 0x80190290: sw          $t5, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r13;
    // 0x80190294: lw          $t6, 0x0($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X0);
    // 0x80190298: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8019029C: lw          $t1, 0xA8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA8);
    // 0x801902A0: addu        $t4, $t4, $t6
    ctx->r12 = ADD32(ctx->r12, ctx->r14);
    // 0x801902A4: lbu         $t4, -0xFB8($t4)
    ctx->r12 = MEM_BU(ctx->r12, -0XFB8);
    // 0x801902A8: lui         $at, 0xE6FF
    ctx->r1 = S32(0XE6FF << 16);
    // 0x801902AC: ori         $at, $at, 0xFF00
    ctx->r1 = ctx->r1 | 0XFF00;
    // 0x801902B0: andi        $t9, $t4, 0xFF
    ctx->r25 = ctx->r12 & 0XFF;
    // 0x801902B4: or          $t0, $t9, $at
    ctx->r8 = ctx->r25 | ctx->r1;
    // 0x801902B8: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x801902BC: lw          $t7, 0xE4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XE4);
    // 0x801902C0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801902C4: addiu       $t6, $t6, 0x2318
    ctx->r14 = ADD32(ctx->r14, 0X2318);
    // 0x801902C8: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x801902CC: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x801902D0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x801902D4: addu        $t4, $t8, $t6
    ctx->r12 = ADD32(ctx->r24, ctx->r14);
    // 0x801902D8: lwc1        $f16, 0x18($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X18);
    // 0x801902DC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x801902E0: addiu       $t2, $t2, 0x3C00
    ctx->r10 = ADD32(ctx->r10, 0X3C00);
    // 0x801902E4: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x801902E8: lw          $a2, 0x10($t4)
    ctx->r6 = MEM_W(ctx->r12, 0X10);
    // 0x801902EC: lw          $a3, 0x14($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X14);
    // 0x801902F0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801902F4: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x801902F8: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x801902FC: lwc1        $f18, 0x0($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X0);
    // 0x80190300: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80190304: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x80190308: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x8019030C: lwc1        $f4, 0x0($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80190310: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80190314: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x80190318: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x8019031C: lwc1        $f6, 0x0($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X0);
    // 0x80190320: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80190324: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x80190328: addu        $a0, $a0, $t5
    ctx->r4 = ADD32(ctx->r4, ctx->r13);
    // 0x8019032C: lw          $a0, -0x1154($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1154);
    // 0x80190330: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80190334: jal         0x800C60A0
    // 0x80190338: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    func_800C60A0(rdram, ctx);
        goto after_7;
    // 0x80190338: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    after_7:
    // 0x8019033C: b           L_80192160
    // 0x80190340: nop

        goto L_80192160;
    // 0x80190340: nop

L_80190344:
    // 0x80190344: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80190348: lwc1        $f8, 0x4C4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X4C4);
    // 0x8019034C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80190350: lwc1        $f10, -0x2E30($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x80190354: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80190358: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x8019035C: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80190360: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80190364: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80190368: addiu       $t8, $t8, 0x3C00
    ctx->r24 = ADD32(ctx->r24, 0X3C00);
    // 0x8019036C: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x80190370: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80190374: lui         $t9, 0xDE00
    ctx->r25 = S32(0XDE00 << 16);
    // 0x80190378: swc1        $f16, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f16.u32l;
    // 0x8019037C: lw          $t3, 0xE4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XE4);
    // 0x80190380: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x80190384: addiu       $t1, $t1, -0x13C8
    ctx->r9 = ADD32(ctx->r9, -0X13C8);
    // 0x80190388: sll         $t5, $t3, 3
    ctx->r13 = S32(ctx->r11 << 3);
    // 0x8019038C: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x80190390: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80190394: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x80190398: lw          $t7, 0x2320($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X2320);
    // 0x8019039C: lui         $t3, 0x8011
    ctx->r11 = S32(0X8011 << 16);
    // 0x801903A0: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x801903A4: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x801903A8: lw          $t6, -0x4514($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4514);
    // 0x801903AC: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x801903B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801903B4: sw          $t6, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r14;
    // 0x801903B8: lw          $t0, 0xA4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA4);
    // 0x801903BC: addiu       $t4, $t6, 0x8
    ctx->r12 = ADD32(ctx->r14, 0X8);
    // 0x801903C0: sw          $t4, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r12;
    // 0x801903C4: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x801903C8: lw          $t2, 0xA4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XA4);
    // 0x801903CC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801903D0: addiu       $t6, $t6, 0x3C00
    ctx->r14 = ADD32(ctx->r14, 0X3C00);
    // 0x801903D4: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x801903D8: lw          $t3, -0x4514($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4514);
    // 0x801903DC: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x801903E0: sw          $t3, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r11;
    // 0x801903E4: lw          $t8, 0xA0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA0);
    // 0x801903E8: addiu       $t5, $t3, 0x8
    ctx->r13 = ADD32(ctx->r11, 0X8);
    // 0x801903EC: sw          $t5, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r13;
    // 0x801903F0: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x801903F4: lw          $t4, 0x0($t6)
    ctx->r12 = MEM_W(ctx->r14, 0X0);
    // 0x801903F8: lw          $t2, 0xA0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XA0);
    // 0x801903FC: lui         $at, 0xFF20
    ctx->r1 = S32(0XFF20 << 16);
    // 0x80190400: addu        $t9, $t9, $t4
    ctx->r25 = ADD32(ctx->r25, ctx->r12);
    // 0x80190404: lbu         $t9, -0xFCC($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0XFCC);
    // 0x80190408: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x8019040C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80190410: andi        $t0, $t9, 0xFF
    ctx->r8 = ctx->r25 & 0XFF;
    // 0x80190414: or          $t1, $t0, $at
    ctx->r9 = ctx->r8 | ctx->r1;
    // 0x80190418: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x8019041C: lw          $t8, 0xE4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XE4);
    // 0x80190420: addiu       $t4, $t4, 0x2318
    ctx->r12 = ADD32(ctx->r12, 0X2318);
    // 0x80190424: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80190428: sll         $t6, $t8, 3
    ctx->r14 = S32(ctx->r24 << 3);
    // 0x8019042C: addu        $t6, $t6, $t8
    ctx->r14 = ADD32(ctx->r14, ctx->r24);
    // 0x80190430: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80190434: addu        $t9, $t6, $t4
    ctx->r25 = ADD32(ctx->r14, ctx->r12);
    // 0x80190438: lwc1        $f18, 0x18($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X18);
    // 0x8019043C: addiu       $t3, $t3, 0x3C00
    ctx->r11 = ADD32(ctx->r11, 0X3C00);
    // 0x80190440: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x80190444: lw          $a2, 0x10($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X10);
    // 0x80190448: lw          $a3, 0x14($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X14);
    // 0x8019044C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80190450: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x80190454: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x80190458: lwc1        $f4, 0x0($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8019045C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80190460: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x80190464: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x80190468: lwc1        $f6, 0x0($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X0);
    // 0x8019046C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80190470: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x80190474: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x80190478: lwc1        $f8, 0x0($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X0);
    // 0x8019047C: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x80190480: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x80190484: lw          $a0, -0x11DC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X11DC);
    // 0x80190488: jal         0x800C60A0
    // 0x8019048C: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    func_800C60A0(rdram, ctx);
        goto after_8;
    // 0x8019048C: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    after_8:
    // 0x80190490: b           L_80192160
    // 0x80190494: nop

        goto L_80192160;
    // 0x80190494: nop

L_80190498:
    // 0x80190498: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019049C: lwc1        $f10, 0x4C8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X4C8);
    // 0x801904A0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801904A4: lwc1        $f16, -0x2E30($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x801904A8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x801904AC: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x801904B0: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x801904B4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x801904B8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801904BC: addiu       $t6, $t6, 0x3C00
    ctx->r14 = ADD32(ctx->r14, 0X3C00);
    // 0x801904C0: lui         $t4, 0x8011
    ctx->r12 = S32(0X8011 << 16);
    // 0x801904C4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x801904C8: lui         $t0, 0xE300
    ctx->r8 = S32(0XE300 << 16);
    // 0x801904CC: swc1        $f18, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f18.u32l;
    // 0x801904D0: lw          $t5, 0xE4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XE4);
    // 0x801904D4: ori         $t0, $t0, 0x1001
    ctx->r8 = ctx->r8 | 0X1001;
    // 0x801904D8: ori         $t2, $zero, 0x8000
    ctx->r10 = 0 | 0X8000;
    // 0x801904DC: sll         $t7, $t5, 3
    ctx->r15 = S32(ctx->r13 << 3);
    // 0x801904E0: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x801904E4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801904E8: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x801904EC: lw          $t8, 0x2320($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X2320);
    // 0x801904F0: lui         $t5, 0x8011
    ctx->r13 = S32(0X8011 << 16);
    // 0x801904F4: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x801904F8: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x801904FC: lw          $t4, -0x4514($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4514);
    // 0x80190500: lui         $t8, 0xFCFF
    ctx->r24 = S32(0XFCFF << 16);
    // 0x80190504: ori         $t8, $t8, 0x97FF
    ctx->r24 = ctx->r24 | 0X97FF;
    // 0x80190508: sw          $t4, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r12;
    // 0x8019050C: lw          $t1, 0x9C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X9C);
    // 0x80190510: addiu       $t9, $t4, 0x8
    ctx->r25 = ADD32(ctx->r12, 0X8);
    // 0x80190514: sw          $t9, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r25;
    // 0x80190518: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x8019051C: lw          $t3, 0x9C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X9C);
    // 0x80190520: lui         $t4, 0xFF2C
    ctx->r12 = S32(0XFF2C << 16);
    // 0x80190524: ori         $t4, $t4, 0xFE7F
    ctx->r12 = ctx->r12 | 0XFE7F;
    // 0x80190528: sw          $t2, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r10;
    // 0x8019052C: lw          $t5, -0x4514($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4514);
    // 0x80190530: lui         $t0, 0x8011
    ctx->r8 = S32(0X8011 << 16);
    // 0x80190534: lui         $t2, 0xFA00
    ctx->r10 = S32(0XFA00 << 16);
    // 0x80190538: sw          $t5, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r13;
    // 0x8019053C: lw          $t6, 0x98($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X98);
    // 0x80190540: addiu       $t7, $t5, 0x8
    ctx->r15 = ADD32(ctx->r13, 0X8);
    // 0x80190544: sw          $t7, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r15;
    // 0x80190548: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x8019054C: lw          $t9, 0x98($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X98);
    // 0x80190550: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80190554: addiu       $t5, $t5, 0x3C00
    ctx->r13 = ADD32(ctx->r13, 0X3C00);
    // 0x80190558: sw          $t4, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r12;
    // 0x8019055C: lw          $t0, -0x4514($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X4514);
    // 0x80190560: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80190564: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80190568: sw          $t0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r8;
    // 0x8019056C: lw          $t3, 0x94($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X94);
    // 0x80190570: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x80190574: sw          $t1, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r9;
    // 0x80190578: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x8019057C: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x80190580: lw          $t9, 0x94($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X94);
    // 0x80190584: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x80190588: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8019058C: lbu         $t8, -0xFA4($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0XFA4);
    // 0x80190590: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80190594: addiu       $t7, $t7, 0x2318
    ctx->r15 = ADD32(ctx->r15, 0X2318);
    // 0x80190598: andi        $t6, $t8, 0xFF
    ctx->r14 = ctx->r24 & 0XFF;
    // 0x8019059C: or          $t4, $t6, $at
    ctx->r12 = ctx->r14 | ctx->r1;
    // 0x801905A0: sw          $t4, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r12;
    // 0x801905A4: lw          $t3, 0xE4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XE4);
    // 0x801905A8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x801905AC: addiu       $t0, $t0, 0x3C00
    ctx->r8 = ADD32(ctx->r8, 0X3C00);
    // 0x801905B0: sll         $t5, $t3, 3
    ctx->r13 = S32(ctx->r11 << 3);
    // 0x801905B4: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x801905B8: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x801905BC: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x801905C0: lwc1        $f4, 0x18($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X18);
    // 0x801905C4: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x801905C8: lw          $a2, 0x10($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X10);
    // 0x801905CC: lw          $a3, 0x14($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X14);
    // 0x801905D0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801905D4: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x801905D8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x801905DC: lwc1        $f6, 0x0($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X0);
    // 0x801905E0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x801905E4: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x801905E8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x801905EC: lwc1        $f8, 0x0($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X0);
    // 0x801905F0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801905F4: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x801905F8: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x801905FC: lwc1        $f10, 0x0($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X0);
    // 0x80190600: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80190604: addu        $a0, $a0, $t2
    ctx->r4 = ADD32(ctx->r4, ctx->r10);
    // 0x80190608: lw          $a0, -0x110C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X110C);
    // 0x8019060C: jal         0x800C60A0
    // 0x80190610: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    func_800C60A0(rdram, ctx);
        goto after_9;
    // 0x80190610: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    after_9:
    // 0x80190614: b           L_80192160
    // 0x80190618: nop

        goto L_80192160;
    // 0x80190618: nop

L_8019061C:
    // 0x8019061C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80190620: lwc1        $f16, 0x4CC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X4CC);
    // 0x80190624: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80190628: lwc1        $f18, -0x2E30($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x8019062C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80190630: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x80190634: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80190638: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8019063C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80190640: addiu       $t5, $t5, 0x3C00
    ctx->r13 = ADD32(ctx->r13, 0X3C00);
    // 0x80190644: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x80190648: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8019064C: lui         $t6, 0xFC12
    ctx->r14 = S32(0XFC12 << 16);
    // 0x80190650: swc1        $f4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f4.u32l;
    // 0x80190654: lw          $t1, 0xE4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XE4);
    // 0x80190658: ori         $t6, $t6, 0x1824
    ctx->r14 = ctx->r14 | 0X1824;
    // 0x8019065C: lui         $t9, 0xFF33
    ctx->r25 = S32(0XFF33 << 16);
    // 0x80190660: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x80190664: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80190668: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8019066C: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80190670: lw          $t3, 0x2320($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X2320);
    // 0x80190674: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x80190678: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8019067C: sw          $t3, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r11;
    // 0x80190680: lw          $t7, -0x4514($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4514);
    // 0x80190684: addiu       $t1, $t1, 0x3C00
    ctx->r9 = ADD32(ctx->r9, 0X3C00);
    // 0x80190688: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8019068C: sw          $t7, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r15;
    // 0x80190690: lw          $t4, 0x90($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X90);
    // 0x80190694: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x80190698: sw          $t8, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r24;
    // 0x8019069C: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x801906A0: lw          $t0, 0x90($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X90);
    // 0x801906A4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x801906A8: addiu       $t8, $t8, 0x2318
    ctx->r24 = ADD32(ctx->r24, 0X2318);
    // 0x801906AC: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x801906B0: lw          $t5, 0xE4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XE4);
    // 0x801906B4: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x801906B8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x801906BC: sll         $t7, $t5, 3
    ctx->r15 = S32(ctx->r13 << 3);
    // 0x801906C0: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x801906C4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801906C8: addu        $t6, $t7, $t8
    ctx->r14 = ADD32(ctx->r15, ctx->r24);
    // 0x801906CC: lwc1        $f6, 0x18($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X18);
    // 0x801906D0: lw          $a2, 0x10($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X10);
    // 0x801906D4: lw          $a3, 0x14($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X14);
    // 0x801906D8: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x801906DC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x801906E0: lwc1        $f8, 0x0($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X0);
    // 0x801906E4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801906E8: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x801906EC: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x801906F0: lwc1        $f10, 0x0($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X0);
    // 0x801906F4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x801906F8: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x801906FC: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x80190700: lwc1        $f16, 0x0($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80190704: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80190708: addu        $a0, $a0, $t3
    ctx->r4 = ADD32(ctx->r4, ctx->r11);
    // 0x8019070C: lw          $a0, -0x11F4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X11F4);
    // 0x80190710: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80190714: jal         0x800C60A0
    // 0x80190718: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    func_800C60A0(rdram, ctx);
        goto after_10;
    // 0x80190718: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    after_10:
    // 0x8019071C: b           L_80192160
    // 0x80190720: nop

        goto L_80192160;
    // 0x80190720: nop

L_80190724:
    // 0x80190724: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80190728: lwc1        $f18, 0x4D0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X4D0);
    // 0x8019072C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80190730: lwc1        $f4, -0x2E30($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x80190734: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80190738: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x8019073C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80190740: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80190744: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80190748: addiu       $t7, $t7, 0x3C00
    ctx->r15 = ADD32(ctx->r15, 0X3C00);
    // 0x8019074C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80190750: addiu       $t8, $t8, 0x3C00
    ctx->r24 = ADD32(ctx->r24, 0X3C00);
    // 0x80190754: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80190758: swc1        $f6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f6.u32l;
    // 0x8019075C: lw          $t2, 0xE4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XE4);
    // 0x80190760: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80190764: addiu       $t1, $t1, 0x2318
    ctx->r9 = ADD32(ctx->r9, 0X2318);
    // 0x80190768: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x8019076C: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80190770: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80190774: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x80190778: lw          $t5, 0x2320($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X2320);
    // 0x8019077C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80190780: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x80190784: sw          $t5, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r13;
    // 0x80190788: lw          $t9, 0xE4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XE4);
    // 0x8019078C: lw          $t6, 0x0($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X0);
    // 0x80190790: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80190794: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x80190798: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8019079C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x801907A0: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x801907A4: lwc1        $f8, 0x18($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X18);
    // 0x801907A8: lw          $a2, 0x10($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X10);
    // 0x801907AC: lw          $a3, 0x14($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X14);
    // 0x801907B0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x801907B4: lwc1        $f10, 0x0($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X0);
    // 0x801907B8: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x801907BC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801907C0: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x801907C4: lwc1        $f16, 0x0($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0X0);
    // 0x801907C8: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x801907CC: sll         $t4, $t6, 2
    ctx->r12 = S32(ctx->r14 << 2);
    // 0x801907D0: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x801907D4: lwc1        $f18, 0x0($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0X0);
    // 0x801907D8: addu        $a0, $a0, $t4
    ctx->r4 = ADD32(ctx->r4, ctx->r12);
    // 0x801907DC: lw          $a0, -0x10EC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X10EC);
    // 0x801907E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801907E4: jal         0x800C60A0
    // 0x801907E8: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    func_800C60A0(rdram, ctx);
        goto after_11;
    // 0x801907E8: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    after_11:
    // 0x801907EC: b           L_80192160
    // 0x801907F0: nop

        goto L_80192160;
    // 0x801907F0: nop

L_801907F4:
    // 0x801907F4: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x801907F8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801907FC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80190800: lwc1        $f6, -0x2E30($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x80190804: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80190808: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x8019080C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80190810: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x80190814: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80190818: lui         $t9, 0xFC12
    ctx->r25 = S32(0XFC12 << 16);
    // 0x8019081C: ori         $t9, $t9, 0x1824
    ctx->r25 = ctx->r25 | 0X1824;
    // 0x80190820: lui         $t1, 0xFF33
    ctx->r9 = S32(0XFF33 << 16);
    // 0x80190824: ori         $t1, $t1, 0xFFFF
    ctx->r9 = ctx->r9 | 0XFFFF;
    // 0x80190828: swc1        $f8, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f8.u32l;
    // 0x8019082C: lw          $t6, -0x4514($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4514);
    // 0x80190830: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80190834: addiu       $t7, $t7, 0x2318
    ctx->r15 = ADD32(ctx->r15, 0X2318);
    // 0x80190838: sw          $t6, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r14;
    // 0x8019083C: lw          $t0, 0x8C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X8C);
    // 0x80190840: addiu       $t4, $t6, 0x8
    ctx->r12 = ADD32(ctx->r14, 0X8);
    // 0x80190844: sw          $t4, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r12;
    // 0x80190848: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x8019084C: lw          $t2, 0x8C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X8C);
    // 0x80190850: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80190854: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x80190858: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x8019085C: lw          $t3, 0xE4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XE4);
    // 0x80190860: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80190864: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x80190868: sll         $t5, $t3, 3
    ctx->r13 = S32(ctx->r11 << 3);
    // 0x8019086C: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x80190870: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80190874: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x80190878: lwc1        $f10, 0x18($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X18);
    // 0x8019087C: lw          $t6, 0x8($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X8);
    // 0x80190880: lw          $a2, 0x10($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X10);
    // 0x80190884: lw          $a3, 0x14($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X14);
    // 0x80190888: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8019088C: lwc1        $f16, 0x0($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X0);
    // 0x80190890: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80190894: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x80190898: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x8019089C: lwc1        $f18, 0x0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X0);
    // 0x801908A0: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x801908A4: sll         $t4, $t6, 2
    ctx->r12 = S32(ctx->r14 << 2);
    // 0x801908A8: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    // 0x801908AC: lwc1        $f4, 0x0($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X0);
    // 0x801908B0: addu        $a0, $a0, $t4
    ctx->r4 = ADD32(ctx->r4, ctx->r12);
    // 0x801908B4: lw          $a0, -0x10CC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X10CC);
    // 0x801908B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801908BC: jal         0x800C60A0
    // 0x801908C0: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    func_800C60A0(rdram, ctx);
        goto after_12;
    // 0x801908C0: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    after_12:
    // 0x801908C4: b           L_80192160
    // 0x801908C8: nop

        goto L_80192160;
    // 0x801908C8: nop

L_801908CC:
    // 0x801908CC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801908D0: lwc1        $f6, 0x4D4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X4D4);
    // 0x801908D4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801908D8: lwc1        $f8, -0x2E30($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x801908DC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x801908E0: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x801908E4: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801908E8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801908EC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801908F0: addiu       $t6, $t6, 0x3C00
    ctx->r14 = ADD32(ctx->r14, 0X3C00);
    // 0x801908F4: lui         $t4, 0x8011
    ctx->r12 = S32(0X8011 << 16);
    // 0x801908F8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x801908FC: lui         $t9, 0xFC12
    ctx->r25 = S32(0XFC12 << 16);
    // 0x80190900: swc1        $f10, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f10.u32l;
    // 0x80190904: lw          $t3, 0xE4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XE4);
    // 0x80190908: ori         $t9, $t9, 0x1824
    ctx->r25 = ctx->r25 | 0X1824;
    // 0x8019090C: lui         $t1, 0xFF33
    ctx->r9 = S32(0XFF33 << 16);
    // 0x80190910: sll         $t5, $t3, 3
    ctx->r13 = S32(ctx->r11 << 3);
    // 0x80190914: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x80190918: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8019091C: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x80190920: lw          $t7, 0x2320($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X2320);
    // 0x80190924: ori         $t1, $t1, 0xFFFF
    ctx->r9 = ctx->r9 | 0XFFFF;
    // 0x80190928: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8019092C: sw          $t7, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r15;
    // 0x80190930: lw          $t4, -0x4514($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4514);
    // 0x80190934: addiu       $t3, $t3, 0x3C00
    ctx->r11 = ADD32(ctx->r11, 0X3C00);
    // 0x80190938: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8019093C: sw          $t4, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r12;
    // 0x80190940: lw          $t0, 0x88($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X88);
    // 0x80190944: addiu       $t8, $t4, 0x8
    ctx->r24 = ADD32(ctx->r12, 0X8);
    // 0x80190948: sw          $t8, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r24;
    // 0x8019094C: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80190950: lw          $t2, 0x88($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X88);
    // 0x80190954: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80190958: addiu       $t8, $t8, 0x2318
    ctx->r24 = ADD32(ctx->r24, 0X2318);
    // 0x8019095C: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x80190960: lw          $t6, 0xE4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XE4);
    // 0x80190964: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x80190968: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8019096C: sll         $t4, $t6, 3
    ctx->r12 = S32(ctx->r14 << 3);
    // 0x80190970: addu        $t4, $t4, $t6
    ctx->r12 = ADD32(ctx->r12, ctx->r14);
    // 0x80190974: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80190978: addu        $t9, $t4, $t8
    ctx->r25 = ADD32(ctx->r12, ctx->r24);
    // 0x8019097C: lwc1        $f16, 0x18($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X18);
    // 0x80190980: lw          $a2, 0x10($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X10);
    // 0x80190984: lw          $a3, 0x14($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X14);
    // 0x80190988: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x8019098C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x80190990: lwc1        $f18, 0x0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80190994: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80190998: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x8019099C: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x801909A0: lwc1        $f4, 0x0($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X0);
    // 0x801909A4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x801909A8: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x801909AC: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x801909B0: lwc1        $f6, 0x0($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X0);
    // 0x801909B4: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x801909B8: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x801909BC: lw          $a0, -0x10AC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X10AC);
    // 0x801909C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801909C4: jal         0x800C60A0
    // 0x801909C8: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    func_800C60A0(rdram, ctx);
        goto after_13;
    // 0x801909C8: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    after_13:
    // 0x801909CC: b           L_80192160
    // 0x801909D0: nop

        goto L_80192160;
    // 0x801909D0: nop

L_801909D4:
    // 0x801909D4: lw          $t3, 0xE4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XE4);
    // 0x801909D8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801909DC: sll         $t5, $t3, 3
    ctx->r13 = S32(ctx->r11 << 3);
    // 0x801909E0: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x801909E4: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x801909E8: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x801909EC: lw          $t7, 0x2320($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X2320);
    // 0x801909F0: andi        $t6, $t7, 0x1
    ctx->r14 = ctx->r15 & 0X1;
    // 0x801909F4: beq         $t6, $zero, L_80190A7C
    if (ctx->r14 == 0) {
        // 0x801909F8: lui         $at, 0x801A
        ctx->r1 = S32(0X801A << 16);
            goto L_80190A7C;
    }
    // 0x801909F8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801909FC: lwc1        $f8, 0x4D8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X4D8);
    // 0x80190A00: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80190A04: lwc1        $f10, -0x2E30($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x80190A08: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80190A0C: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x80190A10: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80190A14: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80190A18: addiu       $t0, $t0, 0x2318
    ctx->r8 = ADD32(ctx->r8, 0X2318);
    // 0x80190A1C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80190A20: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x80190A24: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80190A28: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x80190A2C: swc1        $f16, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f16.u32l;
    // 0x80190A30: lw          $t8, 0xE4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XE4);
    // 0x80190A34: addiu       $a0, $a0, 0x1110
    ctx->r4 = ADD32(ctx->r4, 0X1110);
    // 0x80190A38: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80190A3C: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x80190A40: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80190A44: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80190A48: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80190A4C: lwc1        $f18, 0x18($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X18);
    // 0x80190A50: lw          $a2, 0x10($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X10);
    // 0x80190A54: lw          $a3, 0x14($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X14);
    // 0x80190A58: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x80190A5C: lwc1        $f4, 0x0($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X0);
    // 0x80190A60: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x80190A64: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x80190A68: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x80190A6C: jal         0x800C6144
    // 0x80190A70: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    func_800C6144(rdram, ctx);
        goto after_14;
    // 0x80190A70: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    after_14:
    // 0x80190A74: b           L_80192160
    // 0x80190A78: nop

        goto L_80192160;
    // 0x80190A78: nop

L_80190A7C:
    // 0x80190A7C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80190A80: lwc1        $f8, 0x4DC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X4DC);
    // 0x80190A84: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80190A88: lwc1        $f10, -0x2E30($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x80190A8C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80190A90: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x80190A94: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80190A98: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80190A9C: addiu       $t6, $t6, 0x2318
    ctx->r14 = ADD32(ctx->r14, 0X2318);
    // 0x80190AA0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80190AA4: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x80190AA8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80190AAC: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x80190AB0: swc1        $f16, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f16.u32l;
    // 0x80190AB4: lw          $t5, 0xE4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XE4);
    // 0x80190AB8: addiu       $a0, $a0, 0xD50
    ctx->r4 = ADD32(ctx->r4, 0XD50);
    // 0x80190ABC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80190AC0: sll         $t7, $t5, 3
    ctx->r15 = S32(ctx->r13 << 3);
    // 0x80190AC4: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x80190AC8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80190ACC: addu        $t4, $t7, $t6
    ctx->r12 = ADD32(ctx->r15, ctx->r14);
    // 0x80190AD0: lwc1        $f18, 0x18($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X18);
    // 0x80190AD4: lw          $a2, 0x10($t4)
    ctx->r6 = MEM_W(ctx->r12, 0X10);
    // 0x80190AD8: lw          $a3, 0x14($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X14);
    // 0x80190ADC: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x80190AE0: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    // 0x80190AE4: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x80190AE8: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x80190AEC: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x80190AF0: jal         0x800C6144
    // 0x80190AF4: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    func_800C6144(rdram, ctx);
        goto after_15;
    // 0x80190AF4: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    after_15:
    // 0x80190AF8: b           L_80192160
    // 0x80190AFC: nop

        goto L_80192160;
    // 0x80190AFC: nop

L_80190B00:
    // 0x80190B00: lw          $t9, 0xE4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XE4);
    // 0x80190B04: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80190B08: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x80190B0C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80190B10: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80190B14: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80190B18: lw          $t1, 0x2320($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X2320);
    // 0x80190B1C: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x80190B20: beq         $t2, $zero, L_80190BA8
    if (ctx->r10 == 0) {
        // 0x80190B24: lui         $at, 0x801A
        ctx->r1 = S32(0X801A << 16);
            goto L_80190BA8;
    }
    // 0x80190B24: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80190B28: lwc1        $f8, 0x4E0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X4E0);
    // 0x80190B2C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80190B30: lwc1        $f10, -0x2E30($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x80190B34: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80190B38: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x80190B3C: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80190B40: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80190B44: addiu       $t6, $t6, 0x2318
    ctx->r14 = ADD32(ctx->r14, 0X2318);
    // 0x80190B48: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80190B4C: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x80190B50: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80190B54: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x80190B58: swc1        $f16, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f16.u32l;
    // 0x80190B5C: lw          $t5, 0xE4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XE4);
    // 0x80190B60: addiu       $a0, $a0, 0x1110
    ctx->r4 = ADD32(ctx->r4, 0X1110);
    // 0x80190B64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80190B68: sll         $t7, $t5, 3
    ctx->r15 = S32(ctx->r13 << 3);
    // 0x80190B6C: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x80190B70: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80190B74: addu        $t4, $t7, $t6
    ctx->r12 = ADD32(ctx->r15, ctx->r14);
    // 0x80190B78: lwc1        $f18, 0x18($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X18);
    // 0x80190B7C: lw          $a2, 0x10($t4)
    ctx->r6 = MEM_W(ctx->r12, 0X10);
    // 0x80190B80: lw          $a3, 0x14($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X14);
    // 0x80190B84: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x80190B88: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    // 0x80190B8C: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x80190B90: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x80190B94: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x80190B98: jal         0x800C6144
    // 0x80190B9C: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    func_800C6144(rdram, ctx);
        goto after_16;
    // 0x80190B9C: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    after_16:
    // 0x80190BA0: b           L_80192160
    // 0x80190BA4: nop

        goto L_80192160;
    // 0x80190BA4: nop

L_80190BA8:
    // 0x80190BA8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80190BAC: lwc1        $f8, 0x4E4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X4E4);
    // 0x80190BB0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80190BB4: lwc1        $f10, -0x2E30($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x80190BB8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80190BBC: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x80190BC0: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80190BC4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80190BC8: addiu       $t2, $t2, 0x2318
    ctx->r10 = ADD32(ctx->r10, 0X2318);
    // 0x80190BCC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80190BD0: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x80190BD4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80190BD8: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x80190BDC: swc1        $f16, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f16.u32l;
    // 0x80190BE0: lw          $t0, 0xE4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XE4);
    // 0x80190BE4: addiu       $a0, $a0, 0xD50
    ctx->r4 = ADD32(ctx->r4, 0XD50);
    // 0x80190BE8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80190BEC: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x80190BF0: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80190BF4: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80190BF8: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80190BFC: lwc1        $f18, 0x18($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X18);
    // 0x80190C00: lw          $a2, 0x10($t3)
    ctx->r6 = MEM_W(ctx->r11, 0X10);
    // 0x80190C04: lw          $a3, 0x14($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X14);
    // 0x80190C08: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x80190C0C: lwc1        $f4, 0x0($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X0);
    // 0x80190C10: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x80190C14: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x80190C18: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x80190C1C: jal         0x800C6144
    // 0x80190C20: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    func_800C6144(rdram, ctx);
        goto after_17;
    // 0x80190C20: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    after_17:
    // 0x80190C24: b           L_80192160
    // 0x80190C28: nop

        goto L_80192160;
    // 0x80190C28: nop

L_80190C2C:
    // 0x80190C2C: lw          $t7, 0xE4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XE4);
    // 0x80190C30: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80190C34: sll         $t6, $t7, 3
    ctx->r14 = S32(ctx->r15 << 3);
    // 0x80190C38: addu        $t6, $t6, $t7
    ctx->r14 = ADD32(ctx->r14, ctx->r15);
    // 0x80190C3C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80190C40: addu        $t4, $t4, $t6
    ctx->r12 = ADD32(ctx->r12, ctx->r14);
    // 0x80190C44: lw          $t4, 0x2320($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X2320);
    // 0x80190C48: andi        $t8, $t4, 0x1
    ctx->r24 = ctx->r12 & 0X1;
    // 0x80190C4C: beq         $t8, $zero, L_80190CD4
    if (ctx->r24 == 0) {
        // 0x80190C50: lui         $at, 0x801A
        ctx->r1 = S32(0X801A << 16);
            goto L_80190CD4;
    }
    // 0x80190C50: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80190C54: lwc1        $f8, 0x4E8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X4E8);
    // 0x80190C58: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80190C5C: lwc1        $f10, -0x2E30($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x80190C60: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80190C64: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x80190C68: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80190C6C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80190C70: addiu       $t2, $t2, 0x2318
    ctx->r10 = ADD32(ctx->r10, 0X2318);
    // 0x80190C74: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80190C78: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x80190C7C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80190C80: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x80190C84: swc1        $f16, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f16.u32l;
    // 0x80190C88: lw          $t0, 0xE4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XE4);
    // 0x80190C8C: addiu       $a0, $a0, 0x1110
    ctx->r4 = ADD32(ctx->r4, 0X1110);
    // 0x80190C90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80190C94: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x80190C98: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80190C9C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80190CA0: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80190CA4: lwc1        $f18, 0x18($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X18);
    // 0x80190CA8: lw          $a2, 0x10($t3)
    ctx->r6 = MEM_W(ctx->r11, 0X10);
    // 0x80190CAC: lw          $a3, 0x14($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X14);
    // 0x80190CB0: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x80190CB4: lwc1        $f4, 0x0($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X0);
    // 0x80190CB8: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x80190CBC: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x80190CC0: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x80190CC4: jal         0x800C6144
    // 0x80190CC8: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    func_800C6144(rdram, ctx);
        goto after_18;
    // 0x80190CC8: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    after_18:
    // 0x80190CCC: b           L_80192160
    // 0x80190CD0: nop

        goto L_80192160;
    // 0x80190CD0: nop

L_80190CD4:
    // 0x80190CD4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80190CD8: lwc1        $f8, 0x4EC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X4EC);
    // 0x80190CDC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80190CE0: lwc1        $f10, -0x2E30($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x80190CE4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80190CE8: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x80190CEC: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80190CF0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80190CF4: addiu       $t8, $t8, 0x2318
    ctx->r24 = ADD32(ctx->r24, 0X2318);
    // 0x80190CF8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80190CFC: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x80190D00: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80190D04: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x80190D08: swc1        $f16, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f16.u32l;
    // 0x80190D0C: lw          $t6, 0xE4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XE4);
    // 0x80190D10: addiu       $a0, $a0, 0xD50
    ctx->r4 = ADD32(ctx->r4, 0XD50);
    // 0x80190D14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80190D18: sll         $t4, $t6, 3
    ctx->r12 = S32(ctx->r14 << 3);
    // 0x80190D1C: addu        $t4, $t4, $t6
    ctx->r12 = ADD32(ctx->r12, ctx->r14);
    // 0x80190D20: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80190D24: addu        $t9, $t4, $t8
    ctx->r25 = ADD32(ctx->r12, ctx->r24);
    // 0x80190D28: lwc1        $f18, 0x18($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X18);
    // 0x80190D2C: lw          $a2, 0x10($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X10);
    // 0x80190D30: lw          $a3, 0x14($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X14);
    // 0x80190D34: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x80190D38: lwc1        $f4, 0x0($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80190D3C: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x80190D40: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x80190D44: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x80190D48: jal         0x800C6144
    // 0x80190D4C: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    func_800C6144(rdram, ctx);
        goto after_19;
    // 0x80190D4C: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    after_19:
    // 0x80190D50: b           L_80192160
    // 0x80190D54: nop

        goto L_80192160;
    // 0x80190D54: nop

L_80190D58:
    // 0x80190D58: lw          $t1, 0xE4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XE4);
    // 0x80190D5C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80190D60: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80190D64: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x80190D68: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80190D6C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80190D70: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80190D74: lw          $t3, 0x2320($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X2320);
    // 0x80190D78: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x80190D7C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80190D80: addiu       $t5, $t5, 0x3C00
    ctx->r13 = ADD32(ctx->r13, 0X3C00);
    // 0x80190D84: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80190D88: sw          $t3, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r11;
    // 0x80190D8C: lwc1        $f10, -0x2E30($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x80190D90: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80190D94: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x80190D98: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80190D9C: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x80190DA0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80190DA4: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x80190DA8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80190DAC: addiu       $t0, $t0, 0x3C00
    ctx->r8 = ADD32(ctx->r8, 0X3C00);
    // 0x80190DB0: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80190DB4: swc1        $f16, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f16.u32l;
    // 0x80190DB8: lw          $t6, -0x4514($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4514);
    // 0x80190DBC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80190DC0: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80190DC4: sw          $t6, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r14;
    // 0x80190DC8: lw          $t9, 0x84($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X84);
    // 0x80190DCC: addiu       $t4, $t6, 0x8
    ctx->r12 = ADD32(ctx->r14, 0X8);
    // 0x80190DD0: sw          $t4, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r12;
    // 0x80190DD4: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80190DD8: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80190DDC: lw          $t4, 0x84($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X84);
    // 0x80190DE0: lui         $at, 0xFFDC
    ctx->r1 = S32(0XFFDC << 16);
    // 0x80190DE4: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x80190DE8: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x80190DEC: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x80190DF0: subu        $t5, $t3, $t2
    ctx->r13 = SUB32(ctx->r11, ctx->r10);
    // 0x80190DF4: andi        $t7, $t5, 0xFF
    ctx->r15 = ctx->r13 & 0XFF;
    // 0x80190DF8: ori         $at, $at, 0x4000
    ctx->r1 = ctx->r1 | 0X4000;
    // 0x80190DFC: or          $t6, $t7, $at
    ctx->r14 = ctx->r15 | ctx->r1;
    // 0x80190E00: sw          $t6, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r14;
    // 0x80190E04: lw          $t1, 0xE4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XE4);
    // 0x80190E08: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80190E0C: addiu       $t2, $t2, 0x2318
    ctx->r10 = ADD32(ctx->r10, 0X2318);
    // 0x80190E10: sll         $t3, $t1, 3
    ctx->r11 = S32(ctx->r9 << 3);
    // 0x80190E14: addu        $t3, $t3, $t1
    ctx->r11 = ADD32(ctx->r11, ctx->r9);
    // 0x80190E18: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80190E1C: addu        $t5, $t3, $t2
    ctx->r13 = ADD32(ctx->r11, ctx->r10);
    // 0x80190E20: lwc1        $f18, 0x18($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X18);
    // 0x80190E24: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80190E28: addiu       $t8, $t8, 0x3C00
    ctx->r24 = ADD32(ctx->r24, 0X3C00);
    // 0x80190E2C: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80190E30: lw          $a2, 0x10($t5)
    ctx->r6 = MEM_W(ctx->r13, 0X10);
    // 0x80190E34: lw          $a3, 0x14($t5)
    ctx->r7 = MEM_W(ctx->r13, 0X14);
    // 0x80190E38: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80190E3C: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x80190E40: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x80190E44: lwc1        $f4, 0x0($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X0);
    // 0x80190E48: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80190E4C: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x80190E50: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x80190E54: lwc1        $f6, 0x0($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X0);
    // 0x80190E58: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80190E5C: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x80190E60: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x80190E64: lwc1        $f8, 0x0($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X0);
    // 0x80190E68: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80190E6C: addu        $a0, $a0, $t0
    ctx->r4 = ADD32(ctx->r4, ctx->r8);
    // 0x80190E70: lw          $a0, -0x108C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X108C);
    // 0x80190E74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80190E78: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    // 0x80190E7C: jal         0x800C6144
    // 0x80190E80: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    func_800C6144(rdram, ctx);
        goto after_20;
    // 0x80190E80: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    after_20:
    // 0x80190E84: b           L_80192160
    // 0x80190E88: nop

        goto L_80192160;
    // 0x80190E88: nop

L_80190E8C:
    // 0x80190E8C: lw          $t8, 0xE4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XE4);
    // 0x80190E90: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80190E94: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80190E98: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x80190E9C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80190EA0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80190EA4: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80190EA8: lw          $t0, 0x2320($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X2320);
    // 0x80190EAC: addiu       $t1, $t1, 0x3C00
    ctx->r9 = ADD32(ctx->r9, 0X3C00);
    // 0x80190EB0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80190EB4: addiu       $t3, $t3, 0x3C00
    ctx->r11 = ADD32(ctx->r11, 0X3C00);
    // 0x80190EB8: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x80190EBC: lw          $t2, 0x0($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X0);
    // 0x80190EC0: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x80190EC4: bgez        $t2, L_80190EDC
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80190EC8: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_80190EDC;
    }
    // 0x80190EC8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80190ECC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80190ED0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80190ED4: nop

    // 0x80190ED8: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_80190EDC:
    // 0x80190EDC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80190EE0: lwc1        $f6, 0x4F0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X4F0);
    // 0x80190EE4: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80190EE8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80190EEC: mul.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x80190EF0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80190EF4: lwc1        $f4, -0x2E30($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x80190EF8: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80190EFC: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x80190F00: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x80190F04: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80190F08: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80190F0C: lui         $t4, 0xFA00
    ctx->r12 = S32(0XFA00 << 16);
    // 0x80190F10: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80190F14: addiu       $t9, $t9, 0x3C00
    ctx->r25 = ADD32(ctx->r25, 0X3C00);
    // 0x80190F18: mul.s       $f18, $f16, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x80190F1C: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80190F20: addiu       $t3, $t3, -0xF9C
    ctx->r11 = ADD32(ctx->r11, -0XF9C);
    // 0x80190F24: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80190F28: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80190F2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80190F30: swc1        $f18, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f18.u32l;
    // 0x80190F34: lw          $t7, -0x4514($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4514);
    // 0x80190F38: sw          $t7, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r15;
    // 0x80190F3C: lw          $t8, 0x80($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X80);
    // 0x80190F40: addiu       $t6, $t7, 0x8
    ctx->r14 = ADD32(ctx->r15, 0X8);
    // 0x80190F44: sw          $t6, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r14;
    // 0x80190F48: sw          $t4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r12;
    // 0x80190F4C: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80190F50: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80190F54: addu        $t2, $t1, $t3
    ctx->r10 = ADD32(ctx->r9, ctx->r11);
    // 0x80190F58: lbu         $t4, 0x1($t2)
    ctx->r12 = MEM_BU(ctx->r10, 0X1);
    // 0x80190F5C: lbu         $t5, 0x0($t2)
    ctx->r13 = MEM_BU(ctx->r10, 0X0);
    // 0x80190F60: lbu         $t1, 0x2($t2)
    ctx->r9 = MEM_BU(ctx->r10, 0X2);
    // 0x80190F64: andi        $t8, $t4, 0xFF
    ctx->r24 = ctx->r12 & 0XFF;
    // 0x80190F68: andi        $t7, $t5, 0xFF
    ctx->r15 = ctx->r13 & 0XFF;
    // 0x80190F6C: lbu         $t4, 0x3($t2)
    ctx->r12 = MEM_BU(ctx->r10, 0X3);
    // 0x80190F70: sll         $t6, $t7, 24
    ctx->r14 = S32(ctx->r15 << 24);
    // 0x80190F74: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x80190F78: or          $t0, $t6, $t9
    ctx->r8 = ctx->r14 | ctx->r25;
    // 0x80190F7C: andi        $t3, $t1, 0xFF
    ctx->r11 = ctx->r9 & 0XFF;
    // 0x80190F80: lw          $t9, 0x80($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X80);
    // 0x80190F84: sll         $t5, $t3, 8
    ctx->r13 = S32(ctx->r11 << 8);
    // 0x80190F88: or          $t7, $t0, $t5
    ctx->r15 = ctx->r8 | ctx->r13;
    // 0x80190F8C: andi        $t8, $t4, 0xFF
    ctx->r24 = ctx->r12 & 0XFF;
    // 0x80190F90: or          $t6, $t8, $t7
    ctx->r14 = ctx->r24 | ctx->r15;
    // 0x80190F94: sw          $t6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r14;
    // 0x80190F98: lw          $t5, 0xE4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XE4);
    // 0x80190F9C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80190FA0: addiu       $t4, $t4, 0x2318
    ctx->r12 = ADD32(ctx->r12, 0X2318);
    // 0x80190FA4: sll         $t2, $t5, 3
    ctx->r10 = S32(ctx->r13 << 3);
    // 0x80190FA8: addu        $t2, $t2, $t5
    ctx->r10 = ADD32(ctx->r10, ctx->r13);
    // 0x80190FAC: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80190FB0: addu        $t8, $t2, $t4
    ctx->r24 = ADD32(ctx->r10, ctx->r12);
    // 0x80190FB4: lwc1        $f6, 0x18($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X18);
    // 0x80190FB8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80190FBC: addiu       $t1, $t1, 0x3C00
    ctx->r9 = ADD32(ctx->r9, 0X3C00);
    // 0x80190FC0: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x80190FC4: lw          $a2, 0x10($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X10);
    // 0x80190FC8: lw          $a3, 0x14($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X14);
    // 0x80190FCC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80190FD0: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x80190FD4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x80190FD8: lwc1        $f8, 0x0($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X0);
    // 0x80190FDC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80190FE0: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x80190FE4: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x80190FE8: lwc1        $f10, 0x0($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X0);
    // 0x80190FEC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80190FF0: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x80190FF4: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x80190FF8: lwc1        $f16, 0x0($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X0);
    // 0x80190FFC: sll         $t0, $t3, 2
    ctx->r8 = S32(ctx->r11 << 2);
    // 0x80191000: addu        $a0, $a0, $t0
    ctx->r4 = ADD32(ctx->r4, ctx->r8);
    // 0x80191004: lw          $a0, -0x106C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X106C);
    // 0x80191008: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x8019100C: jal         0x800C6144
    // 0x80191010: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    func_800C6144(rdram, ctx);
        goto after_21;
    // 0x80191010: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    after_21:
    // 0x80191014: b           L_80192160
    // 0x80191018: nop

        goto L_80192160;
    // 0x80191018: nop

L_8019101C:
    // 0x8019101C: lw          $t1, 0xE4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XE4);
    // 0x80191020: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80191024: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80191028: sll         $t3, $t1, 3
    ctx->r11 = S32(ctx->r9 << 3);
    // 0x8019102C: addu        $t3, $t3, $t1
    ctx->r11 = ADD32(ctx->r11, ctx->r9);
    // 0x80191030: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80191034: addu        $t0, $t0, $t3
    ctx->r8 = ADD32(ctx->r8, ctx->r11);
    // 0x80191038: lw          $t0, 0x2320($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X2320);
    // 0x8019103C: addiu       $t5, $t5, 0x3C00
    ctx->r13 = ADD32(ctx->r13, 0X3C00);
    // 0x80191040: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80191044: addiu       $t2, $t2, 0x3C00
    ctx->r10 = ADD32(ctx->r10, 0X3C00);
    // 0x80191048: sw          $t0, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r8;
    // 0x8019104C: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80191050: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x80191054: bgez        $t4, L_8019106C
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80191058: cvt.s.w     $f6, $f18
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
            goto L_8019106C;
    }
    // 0x80191058: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8019105C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80191060: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80191064: nop

    // 0x80191068: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8019106C:
    // 0x8019106C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80191070: lwc1        $f10, 0x4F4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X4F4);
    // 0x80191074: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80191078: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019107C: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80191080: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80191084: lwc1        $f8, -0x2E30($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x80191088: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8019108C: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x80191090: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x80191094: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80191098: add.s       $f18, $f16, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x8019109C: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x801910A0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x801910A4: addiu       $t3, $t3, 0x3C00
    ctx->r11 = ADD32(ctx->r11, 0X3C00);
    // 0x801910A8: mul.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x801910AC: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x801910B0: addiu       $t2, $t2, -0xF7C
    ctx->r10 = ADD32(ctx->r10, -0XF7C);
    // 0x801910B4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801910B8: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x801910BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801910C0: swc1        $f6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f6.u32l;
    // 0x801910C4: lw          $t7, -0x4514($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4514);
    // 0x801910C8: sw          $t7, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r15;
    // 0x801910CC: lw          $t1, 0x7C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X7C);
    // 0x801910D0: addiu       $t6, $t7, 0x8
    ctx->r14 = ADD32(ctx->r15, 0X8);
    // 0x801910D4: sw          $t6, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r14;
    // 0x801910D8: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x801910DC: lw          $t0, 0x0($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X0);
    // 0x801910E0: sll         $t5, $t0, 2
    ctx->r13 = S32(ctx->r8 << 2);
    // 0x801910E4: addu        $t4, $t5, $t2
    ctx->r12 = ADD32(ctx->r13, ctx->r10);
    // 0x801910E8: lbu         $t9, 0x1($t4)
    ctx->r25 = MEM_BU(ctx->r12, 0X1);
    // 0x801910EC: lbu         $t8, 0x0($t4)
    ctx->r24 = MEM_BU(ctx->r12, 0X0);
    // 0x801910F0: lbu         $t5, 0x2($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X2);
    // 0x801910F4: andi        $t1, $t9, 0xFF
    ctx->r9 = ctx->r25 & 0XFF;
    // 0x801910F8: andi        $t7, $t8, 0xFF
    ctx->r15 = ctx->r24 & 0XFF;
    // 0x801910FC: lbu         $t9, 0x3($t4)
    ctx->r25 = MEM_BU(ctx->r12, 0X3);
    // 0x80191100: sll         $t6, $t7, 24
    ctx->r14 = S32(ctx->r15 << 24);
    // 0x80191104: sll         $t3, $t1, 16
    ctx->r11 = S32(ctx->r9 << 16);
    // 0x80191108: or          $t0, $t6, $t3
    ctx->r8 = ctx->r14 | ctx->r11;
    // 0x8019110C: andi        $t2, $t5, 0xFF
    ctx->r10 = ctx->r13 & 0XFF;
    // 0x80191110: lw          $t3, 0x7C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X7C);
    // 0x80191114: sll         $t8, $t2, 8
    ctx->r24 = S32(ctx->r10 << 8);
    // 0x80191118: or          $t7, $t0, $t8
    ctx->r15 = ctx->r8 | ctx->r24;
    // 0x8019111C: andi        $t1, $t9, 0xFF
    ctx->r9 = ctx->r25 & 0XFF;
    // 0x80191120: or          $t6, $t1, $t7
    ctx->r14 = ctx->r9 | ctx->r15;
    // 0x80191124: sw          $t6, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r14;
    // 0x80191128: lw          $t8, 0xE4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XE4);
    // 0x8019112C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80191130: addiu       $t9, $t9, 0x2318
    ctx->r25 = ADD32(ctx->r25, 0X2318);
    // 0x80191134: sll         $t4, $t8, 3
    ctx->r12 = S32(ctx->r24 << 3);
    // 0x80191138: addu        $t4, $t4, $t8
    ctx->r12 = ADD32(ctx->r12, ctx->r24);
    // 0x8019113C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80191140: addu        $t1, $t4, $t9
    ctx->r9 = ADD32(ctx->r12, ctx->r25);
    // 0x80191144: lwc1        $f10, 0x18($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X18);
    // 0x80191148: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8019114C: addiu       $t5, $t5, 0x3C00
    ctx->r13 = ADD32(ctx->r13, 0X3C00);
    // 0x80191150: lw          $t2, 0x0($t5)
    ctx->r10 = MEM_W(ctx->r13, 0X0);
    // 0x80191154: lw          $a2, 0x10($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X10);
    // 0x80191158: lw          $a3, 0x14($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X14);
    // 0x8019115C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80191160: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x80191164: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80191168: lwc1        $f16, 0x0($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X0);
    // 0x8019116C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80191170: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x80191174: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x80191178: lwc1        $f4, 0x0($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X0);
    // 0x8019117C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80191180: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x80191184: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x80191188: lwc1        $f18, 0x0($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X0);
    // 0x8019118C: sll         $t0, $t2, 2
    ctx->r8 = S32(ctx->r10 << 2);
    // 0x80191190: addu        $a0, $a0, $t0
    ctx->r4 = ADD32(ctx->r4, ctx->r8);
    // 0x80191194: lw          $a0, -0x104C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X104C);
    // 0x80191198: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x8019119C: jal         0x800C6144
    // 0x801911A0: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    func_800C6144(rdram, ctx);
        goto after_22;
    // 0x801911A0: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    after_22:
    // 0x801911A4: b           L_80192160
    // 0x801911A8: nop

        goto L_80192160;
    // 0x801911A8: nop

L_801911AC:
    // 0x801911AC: lw          $t5, 0xE4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XE4);
    // 0x801911B0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x801911B4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x801911B8: sll         $t2, $t5, 3
    ctx->r10 = S32(ctx->r13 << 3);
    // 0x801911BC: addu        $t2, $t2, $t5
    ctx->r10 = ADD32(ctx->r10, ctx->r13);
    // 0x801911C0: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x801911C4: addu        $t0, $t0, $t2
    ctx->r8 = ADD32(ctx->r8, ctx->r10);
    // 0x801911C8: lw          $t0, 0x2320($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X2320);
    // 0x801911CC: addiu       $t8, $t8, 0x3C00
    ctx->r24 = ADD32(ctx->r24, 0X3C00);
    // 0x801911D0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x801911D4: addiu       $t4, $t4, 0x3C00
    ctx->r12 = ADD32(ctx->r12, 0X3C00);
    // 0x801911D8: sw          $t0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r8;
    // 0x801911DC: lw          $t9, 0x0($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X0);
    // 0x801911E0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801911E4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801911E8: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x801911EC: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x801911F0: lwc1        $f6, -0xF48($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0XF48);
    // 0x801911F4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801911F8: lwc1        $f10, -0x2E30($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x801911FC: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x80191200: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x80191204: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80191208: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8019120C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80191210: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x80191214: addiu       $t0, $t0, 0x3C00
    ctx->r8 = ADD32(ctx->r8, 0X3C00);
    // 0x80191218: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x8019121C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80191220: swc1        $f16, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f16.u32l;
    // 0x80191224: lw          $t6, -0x4514($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4514);
    // 0x80191228: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8019122C: addiu       $a0, $a0, 0x15E0
    ctx->r4 = ADD32(ctx->r4, 0X15E0);
    // 0x80191230: sw          $t6, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r14;
    // 0x80191234: lw          $t2, 0x78($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X78);
    // 0x80191238: addiu       $t3, $t6, 0x8
    ctx->r11 = ADD32(ctx->r14, 0X8);
    // 0x8019123C: sw          $t3, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r11;
    // 0x80191240: sw          $t5, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r13;
    // 0x80191244: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x80191248: lw          $t7, 0x78($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X78);
    // 0x8019124C: lui         $at, 0x2814
    ctx->r1 = S32(0X2814 << 16);
    // 0x80191250: addu        $t4, $t4, $t8
    ctx->r12 = ADD32(ctx->r12, ctx->r24);
    // 0x80191254: lbu         $t4, -0xF5C($t4)
    ctx->r12 = MEM_BU(ctx->r12, -0XF5C);
    // 0x80191258: ori         $at, $at, 0xA00
    ctx->r1 = ctx->r1 | 0XA00;
    // 0x8019125C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80191260: andi        $t9, $t4, 0xFF
    ctx->r25 = ctx->r12 & 0XFF;
    // 0x80191264: or          $t1, $t9, $at
    ctx->r9 = ctx->r25 | ctx->r1;
    // 0x80191268: sw          $t1, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r9;
    // 0x8019126C: lw          $t6, 0xE4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XE4);
    // 0x80191270: addiu       $t5, $t5, 0x2318
    ctx->r13 = ADD32(ctx->r13, 0X2318);
    // 0x80191274: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80191278: sll         $t3, $t6, 3
    ctx->r11 = S32(ctx->r14 << 3);
    // 0x8019127C: addu        $t3, $t3, $t6
    ctx->r11 = ADD32(ctx->r11, ctx->r14);
    // 0x80191280: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80191284: addu        $t2, $t3, $t5
    ctx->r10 = ADD32(ctx->r11, ctx->r13);
    // 0x80191288: lwc1        $f4, 0x18($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X18);
    // 0x8019128C: lw          $a2, 0x10($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X10);
    // 0x80191290: lw          $a3, 0x14($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X14);
    // 0x80191294: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x80191298: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8019129C: lwc1        $f18, 0x0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X0);
    // 0x801912A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801912A4: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x801912A8: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x801912AC: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    // 0x801912B0: jal         0x800C6144
    // 0x801912B4: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    func_800C6144(rdram, ctx);
        goto after_23;
    // 0x801912B4: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    after_23:
    // 0x801912B8: b           L_80192160
    // 0x801912BC: nop

        goto L_80192160;
    // 0x801912BC: nop

L_801912C0:
    // 0x801912C0: lw          $t8, 0xE4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XE4);
    // 0x801912C4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801912C8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x801912CC: sll         $t4, $t8, 3
    ctx->r12 = S32(ctx->r24 << 3);
    // 0x801912D0: addu        $t4, $t4, $t8
    ctx->r12 = ADD32(ctx->r12, ctx->r24);
    // 0x801912D4: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x801912D8: addu        $t9, $t9, $t4
    ctx->r25 = ADD32(ctx->r25, ctx->r12);
    // 0x801912DC: lw          $t9, 0x2320($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X2320);
    // 0x801912E0: addiu       $t1, $t1, 0x3C00
    ctx->r9 = ADD32(ctx->r9, 0X3C00);
    // 0x801912E4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801912E8: addiu       $t7, $t7, 0x3C00
    ctx->r15 = ADD32(ctx->r15, 0X3C00);
    // 0x801912EC: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x801912F0: lw          $t6, 0x0($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X0);
    // 0x801912F4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801912F8: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x801912FC: sll         $t3, $t6, 2
    ctx->r11 = S32(ctx->r14 << 2);
    // 0x80191300: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x80191304: lwc1        $f6, -0xF38($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0XF38);
    // 0x80191308: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8019130C: lwc1        $f10, -0x2E30($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x80191310: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x80191314: lui         $t2, 0x8011
    ctx->r10 = S32(0X8011 << 16);
    // 0x80191318: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8019131C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80191320: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80191324: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x80191328: addiu       $t9, $t9, 0x3C00
    ctx->r25 = ADD32(ctx->r25, 0X3C00);
    // 0x8019132C: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80191330: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80191334: swc1        $f16, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f16.u32l;
    // 0x80191338: lw          $t2, -0x4514($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4514);
    // 0x8019133C: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x80191340: addiu       $a0, $a0, 0x1610
    ctx->r4 = ADD32(ctx->r4, 0X1610);
    // 0x80191344: sw          $t2, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r10;
    // 0x80191348: lw          $t4, 0x74($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X74);
    // 0x8019134C: addiu       $t0, $t2, 0x8
    ctx->r8 = ADD32(ctx->r10, 0X8);
    // 0x80191350: sw          $t0, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r8;
    // 0x80191354: sw          $t8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r24;
    // 0x80191358: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x8019135C: lw          $t5, 0x74($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X74);
    // 0x80191360: lui         $at, 0x231E
    ctx->r1 = S32(0X231E << 16);
    // 0x80191364: addu        $t7, $t7, $t1
    ctx->r15 = ADD32(ctx->r15, ctx->r9);
    // 0x80191368: lbu         $t7, -0xF58($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0XF58);
    // 0x8019136C: ori         $at, $at, 0xF00
    ctx->r1 = ctx->r1 | 0XF00;
    // 0x80191370: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80191374: andi        $t6, $t7, 0xFF
    ctx->r14 = ctx->r15 & 0XFF;
    // 0x80191378: or          $t3, $t6, $at
    ctx->r11 = ctx->r14 | ctx->r1;
    // 0x8019137C: sw          $t3, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r11;
    // 0x80191380: lw          $t2, 0xE4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XE4);
    // 0x80191384: addiu       $t8, $t8, 0x2318
    ctx->r24 = ADD32(ctx->r24, 0X2318);
    // 0x80191388: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8019138C: sll         $t0, $t2, 3
    ctx->r8 = S32(ctx->r10 << 3);
    // 0x80191390: addu        $t0, $t0, $t2
    ctx->r8 = ADD32(ctx->r8, ctx->r10);
    // 0x80191394: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80191398: addu        $t4, $t0, $t8
    ctx->r12 = ADD32(ctx->r8, ctx->r24);
    // 0x8019139C: lwc1        $f4, 0x18($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X18);
    // 0x801913A0: lw          $a2, 0x10($t4)
    ctx->r6 = MEM_W(ctx->r12, 0X10);
    // 0x801913A4: lw          $a3, 0x14($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X14);
    // 0x801913A8: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x801913AC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x801913B0: lwc1        $f18, 0x0($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X0);
    // 0x801913B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801913B8: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x801913BC: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x801913C0: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    // 0x801913C4: jal         0x800C6144
    // 0x801913C8: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    func_800C6144(rdram, ctx);
        goto after_24;
    // 0x801913C8: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    after_24:
    // 0x801913CC: b           L_80192160
    // 0x801913D0: nop

        goto L_80192160;
    // 0x801913D0: nop

L_801913D4:
    // 0x801913D4: lw          $t1, 0xE4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XE4);
    // 0x801913D8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801913DC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x801913E0: sll         $t7, $t1, 3
    ctx->r15 = S32(ctx->r9 << 3);
    // 0x801913E4: addu        $t7, $t7, $t1
    ctx->r15 = ADD32(ctx->r15, ctx->r9);
    // 0x801913E8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801913EC: addu        $t6, $t6, $t7
    ctx->r14 = ADD32(ctx->r14, ctx->r15);
    // 0x801913F0: lw          $t6, 0x2320($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2320);
    // 0x801913F4: addiu       $t3, $t3, 0x3C00
    ctx->r11 = ADD32(ctx->r11, 0X3C00);
    // 0x801913F8: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x801913FC: addiu       $t5, $t5, 0x3C00
    ctx->r13 = ADD32(ctx->r13, 0X3C00);
    // 0x80191400: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x80191404: lw          $t2, 0x0($t5)
    ctx->r10 = MEM_W(ctx->r13, 0X0);
    // 0x80191408: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019140C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80191410: sll         $t0, $t2, 2
    ctx->r8 = S32(ctx->r10 << 2);
    // 0x80191414: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80191418: lwc1        $f6, -0xF18($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0XF18);
    // 0x8019141C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80191420: lwc1        $f10, -0x2E30($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x80191424: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x80191428: lui         $t4, 0x8011
    ctx->r12 = S32(0X8011 << 16);
    // 0x8019142C: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80191430: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80191434: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80191438: lui         $t1, 0xFA00
    ctx->r9 = S32(0XFA00 << 16);
    // 0x8019143C: addiu       $t6, $t6, 0x3C00
    ctx->r14 = ADD32(ctx->r14, 0X3C00);
    // 0x80191440: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80191444: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80191448: swc1        $f16, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f16.u32l;
    // 0x8019144C: lw          $t4, -0x4514($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4514);
    // 0x80191450: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x80191454: addiu       $a0, $a0, 0x1650
    ctx->r4 = ADD32(ctx->r4, 0X1650);
    // 0x80191458: sw          $t4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r12;
    // 0x8019145C: lw          $t7, 0x70($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X70);
    // 0x80191460: addiu       $t9, $t4, 0x8
    ctx->r25 = ADD32(ctx->r12, 0X8);
    // 0x80191464: sw          $t9, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r25;
    // 0x80191468: sw          $t1, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r9;
    // 0x8019146C: lw          $t3, 0x0($t6)
    ctx->r11 = MEM_W(ctx->r14, 0X0);
    // 0x80191470: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
    // 0x80191474: lui         $at, 0x3228
    ctx->r1 = S32(0X3228 << 16);
    // 0x80191478: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x8019147C: lbu         $t5, -0xF50($t5)
    ctx->r13 = MEM_BU(ctx->r13, -0XF50);
    // 0x80191480: ori         $at, $at, 0x2800
    ctx->r1 = ctx->r1 | 0X2800;
    // 0x80191484: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80191488: andi        $t2, $t5, 0xFF
    ctx->r10 = ctx->r13 & 0XFF;
    // 0x8019148C: or          $t0, $t2, $at
    ctx->r8 = ctx->r10 | ctx->r1;
    // 0x80191490: sw          $t0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r8;
    // 0x80191494: lw          $t4, 0xE4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XE4);
    // 0x80191498: addiu       $t1, $t1, 0x2318
    ctx->r9 = ADD32(ctx->r9, 0X2318);
    // 0x8019149C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801914A0: sll         $t9, $t4, 3
    ctx->r25 = S32(ctx->r12 << 3);
    // 0x801914A4: addu        $t9, $t9, $t4
    ctx->r25 = ADD32(ctx->r25, ctx->r12);
    // 0x801914A8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x801914AC: addu        $t7, $t9, $t1
    ctx->r15 = ADD32(ctx->r25, ctx->r9);
    // 0x801914B0: lwc1        $f4, 0x18($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X18);
    // 0x801914B4: lw          $a2, 0x10($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X10);
    // 0x801914B8: lw          $a3, 0x14($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X14);
    // 0x801914BC: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x801914C0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x801914C4: lwc1        $f18, 0x0($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X0);
    // 0x801914C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801914CC: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x801914D0: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x801914D4: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    // 0x801914D8: jal         0x800C6144
    // 0x801914DC: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    func_800C6144(rdram, ctx);
        goto after_25;
    // 0x801914DC: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    after_25:
    // 0x801914E0: b           L_80192160
    // 0x801914E4: nop

        goto L_80192160;
    // 0x801914E4: nop

L_801914E8:
    // 0x801914E8: lw          $t3, 0xE4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XE4);
    // 0x801914EC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801914F0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x801914F4: sll         $t5, $t3, 3
    ctx->r13 = S32(ctx->r11 << 3);
    // 0x801914F8: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x801914FC: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80191500: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x80191504: lwc1        $f6, 0x2338($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X2338);
    // 0x80191508: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8019150C: lwc1        $f10, -0x2E30($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x80191510: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x80191514: lui         $t0, 0x8011
    ctx->r8 = S32(0X8011 << 16);
    // 0x80191518: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8019151C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80191520: lui         $t4, 0xFC12
    ctx->r12 = S32(0XFC12 << 16);
    // 0x80191524: ori         $t4, $t4, 0x1824
    ctx->r12 = ctx->r12 | 0X1824;
    // 0x80191528: lui         $t1, 0xFF33
    ctx->r9 = S32(0XFF33 << 16);
    // 0x8019152C: ori         $t1, $t1, 0xFFFF
    ctx->r9 = ctx->r9 | 0XFFFF;
    // 0x80191530: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80191534: swc1        $f16, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f16.u32l;
    // 0x80191538: lw          $t0, -0x4514($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X4514);
    // 0x8019153C: addiu       $t5, $t5, 0x2318
    ctx->r13 = ADD32(ctx->r13, 0X2318);
    // 0x80191540: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80191544: sw          $t0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r8;
    // 0x80191548: lw          $t9, 0x6C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X6C);
    // 0x8019154C: addiu       $t8, $t0, 0x8
    ctx->r24 = ADD32(ctx->r8, 0X8);
    // 0x80191550: sw          $t8, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r24;
    // 0x80191554: sw          $t4, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r12;
    // 0x80191558: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
    // 0x8019155C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80191560: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x80191564: sw          $t1, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r9;
    // 0x80191568: lw          $t6, 0xE4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XE4);
    // 0x8019156C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80191570: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x80191574: sll         $t3, $t6, 3
    ctx->r11 = S32(ctx->r14 << 3);
    // 0x80191578: addu        $t3, $t3, $t6
    ctx->r11 = ADD32(ctx->r11, ctx->r14);
    // 0x8019157C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80191580: addu        $t2, $t3, $t5
    ctx->r10 = ADD32(ctx->r11, ctx->r13);
    // 0x80191584: lwc1        $f4, 0x18($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X18);
    // 0x80191588: lw          $t0, 0x8($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X8);
    // 0x8019158C: lw          $a2, 0x10($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X10);
    // 0x80191590: lw          $a3, 0x14($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X14);
    // 0x80191594: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80191598: lwc1        $f18, 0x0($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X0);
    // 0x8019159C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801915A0: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x801915A4: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x801915A8: lwc1        $f8, 0x0($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X0);
    // 0x801915AC: andi        $t8, $t0, 0xF
    ctx->r24 = ctx->r8 & 0XF;
    // 0x801915B0: sll         $t4, $t8, 2
    ctx->r12 = S32(ctx->r24 << 2);
    // 0x801915B4: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x801915B8: lwc1        $f6, 0x0($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X0);
    // 0x801915BC: addu        $a0, $a0, $t4
    ctx->r4 = ADD32(ctx->r4, ctx->r12);
    // 0x801915C0: lw          $a0, -0x102C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X102C);
    // 0x801915C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801915C8: jal         0x800C60A0
    // 0x801915CC: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    func_800C60A0(rdram, ctx);
        goto after_26;
    // 0x801915CC: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    after_26:
    // 0x801915D0: b           L_80192160
    // 0x801915D4: nop

        goto L_80192160;
    // 0x801915D4: nop

L_801915D8:
    // 0x801915D8: lw          $t6, 0xE4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XE4);
    // 0x801915DC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801915E0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x801915E4: sll         $t3, $t6, 3
    ctx->r11 = S32(ctx->r14 << 3);
    // 0x801915E8: addu        $t3, $t3, $t6
    ctx->r11 = ADD32(ctx->r11, ctx->r14);
    // 0x801915EC: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x801915F0: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x801915F4: lwc1        $f10, 0x2338($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X2338);
    // 0x801915F8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801915FC: lwc1        $f16, -0x2E30($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x80191600: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x80191604: lui         $t0, 0x8011
    ctx->r8 = S32(0X8011 << 16);
    // 0x80191608: mul.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8019160C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80191610: lui         $t4, 0xFC12
    ctx->r12 = S32(0XFC12 << 16);
    // 0x80191614: ori         $t4, $t4, 0x1824
    ctx->r12 = ctx->r12 | 0X1824;
    // 0x80191618: lui         $t9, 0xFF33
    ctx->r25 = S32(0XFF33 << 16);
    // 0x8019161C: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x80191620: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80191624: swc1        $f4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f4.u32l;
    // 0x80191628: lw          $t0, -0x4514($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X4514);
    // 0x8019162C: addiu       $t3, $t3, 0x2318
    ctx->r11 = ADD32(ctx->r11, 0X2318);
    // 0x80191630: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80191634: sw          $t0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r8;
    // 0x80191638: lw          $t2, 0x68($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X68);
    // 0x8019163C: addiu       $t8, $t0, 0x8
    ctx->r24 = ADD32(ctx->r8, 0X8);
    // 0x80191640: sw          $t8, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r24;
    // 0x80191644: sw          $t4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r12;
    // 0x80191648: lw          $t1, 0x68($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X68);
    // 0x8019164C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80191650: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x80191654: sw          $t9, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r25;
    // 0x80191658: lw          $t7, 0xE4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XE4);
    // 0x8019165C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80191660: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80191664: sll         $t6, $t7, 3
    ctx->r14 = S32(ctx->r15 << 3);
    // 0x80191668: addu        $t6, $t6, $t7
    ctx->r14 = ADD32(ctx->r14, ctx->r15);
    // 0x8019166C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80191670: addu        $t5, $t6, $t3
    ctx->r13 = ADD32(ctx->r14, ctx->r11);
    // 0x80191674: lwc1        $f18, 0x18($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X18);
    // 0x80191678: lw          $a2, 0x10($t5)
    ctx->r6 = MEM_W(ctx->r13, 0X10);
    // 0x8019167C: lw          $a3, 0x14($t5)
    ctx->r7 = MEM_W(ctx->r13, 0X14);
    // 0x80191680: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x80191684: lwc1        $f8, 0x0($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80191688: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x8019168C: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x80191690: addiu       $a0, $a0, 0xB90
    ctx->r4 = ADD32(ctx->r4, 0XB90);
    // 0x80191694: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x80191698: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8019169C: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    // 0x801916A0: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    // 0x801916A4: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x801916A8: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x801916AC: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x801916B0: jal         0x800C58E8
    // 0x801916B4: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    func_800C58E8(rdram, ctx);
        goto after_27;
    // 0x801916B4: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    after_27:
    // 0x801916B8: b           L_80192160
    // 0x801916BC: nop

        goto L_80192160;
    // 0x801916BC: nop

L_801916C0:
    // 0x801916C0: lw          $t4, 0xE4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XE4);
    // 0x801916C4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801916C8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801916CC: sll         $t2, $t4, 3
    ctx->r10 = S32(ctx->r12 << 3);
    // 0x801916D0: addu        $t2, $t2, $t4
    ctx->r10 = ADD32(ctx->r10, ctx->r12);
    // 0x801916D4: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x801916D8: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x801916DC: lwc1        $f4, 0x2338($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X2338);
    // 0x801916E0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801916E4: lwc1        $f18, -0x2E30($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x801916E8: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x801916EC: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x801916F0: mul.s       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x801916F4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x801916F8: lui         $t6, 0xFC12
    ctx->r14 = S32(0XFC12 << 16);
    // 0x801916FC: ori         $t6, $t6, 0x1824
    ctx->r14 = ctx->r14 | 0X1824;
    // 0x80191700: lui         $t5, 0xFF33
    ctx->r13 = S32(0XFF33 << 16);
    // 0x80191704: ori         $t5, $t5, 0xFFFF
    ctx->r13 = ctx->r13 | 0XFFFF;
    // 0x80191708: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8019170C: swc1        $f8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f8.u32l;
    // 0x80191710: lw          $t1, -0x4514($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4514);
    // 0x80191714: addiu       $t2, $t2, 0x2318
    ctx->r10 = ADD32(ctx->r10, 0X2318);
    // 0x80191718: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8019171C: sw          $t1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r9;
    // 0x80191720: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x80191724: addiu       $t7, $t1, 0x8
    ctx->r15 = ADD32(ctx->r9, 0X8);
    // 0x80191728: sw          $t7, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r15;
    // 0x8019172C: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x80191730: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x80191734: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80191738: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x8019173C: sw          $t5, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r13;
    // 0x80191740: lw          $t8, 0xE4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XE4);
    // 0x80191744: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80191748: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8019174C: sll         $t4, $t8, 3
    ctx->r12 = S32(ctx->r24 << 3);
    // 0x80191750: addu        $t4, $t4, $t8
    ctx->r12 = ADD32(ctx->r12, ctx->r24);
    // 0x80191754: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80191758: addu        $t9, $t4, $t2
    ctx->r25 = ADD32(ctx->r12, ctx->r10);
    // 0x8019175C: lwc1        $f6, 0x18($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X18);
    // 0x80191760: lw          $a2, 0x10($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X10);
    // 0x80191764: lw          $a3, 0x14($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X14);
    // 0x80191768: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x8019176C: lwc1        $f10, 0x0($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X0);
    // 0x80191770: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80191774: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x80191778: addiu       $a0, $a0, 0xBB0
    ctx->r4 = ADD32(ctx->r4, 0XBB0);
    // 0x8019177C: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x80191780: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80191784: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    // 0x80191788: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x8019178C: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x80191790: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x80191794: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x80191798: jal         0x800C58E8
    // 0x8019179C: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    func_800C58E8(rdram, ctx);
        goto after_28;
    // 0x8019179C: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    after_28:
    // 0x801917A0: b           L_80192160
    // 0x801917A4: nop

        goto L_80192160;
    // 0x801917A4: nop

L_801917A8:
    // 0x801917A8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801917AC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801917B0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801917B4: lwc1        $f6, -0x2E30($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x801917B8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801917BC: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x801917C0: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x801917C4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x801917C8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x801917CC: addiu       $t8, $t8, 0x3C00
    ctx->r24 = ADD32(ctx->r24, 0X3C00);
    // 0x801917D0: lui         $t4, 0x8011
    ctx->r12 = S32(0X8011 << 16);
    // 0x801917D4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x801917D8: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x801917DC: swc1        $f10, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f10.u32l;
    // 0x801917E0: lw          $t3, 0xE4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XE4);
    // 0x801917E4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801917E8: addiu       $t7, $t7, 0x3C00
    ctx->r15 = ADD32(ctx->r15, 0X3C00);
    // 0x801917EC: sll         $t5, $t3, 3
    ctx->r13 = S32(ctx->r11 << 3);
    // 0x801917F0: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x801917F4: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x801917F8: addu        $t0, $t0, $t5
    ctx->r8 = ADD32(ctx->r8, ctx->r13);
    // 0x801917FC: lw          $t0, 0x2320($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X2320);
    // 0x80191800: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x80191804: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80191808: sw          $t0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r8;
    // 0x8019180C: lw          $t4, -0x4514($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4514);
    // 0x80191810: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80191814: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80191818: sw          $t4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r12;
    // 0x8019181C: lw          $t1, 0x60($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X60);
    // 0x80191820: addiu       $t2, $t4, 0x8
    ctx->r10 = ADD32(ctx->r12, 0X8);
    // 0x80191824: sw          $t2, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r10;
    // 0x80191828: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8019182C: lw          $t6, 0x0($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X0);
    // 0x80191830: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x80191834: lui         $at, 0xFFDC
    ctx->r1 = S32(0XFFDC << 16);
    // 0x80191838: sll         $t3, $t6, 4
    ctx->r11 = S32(ctx->r14 << 4);
    // 0x8019183C: subu        $t3, $t3, $t6
    ctx->r11 = SUB32(ctx->r11, ctx->r14);
    // 0x80191840: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x80191844: subu        $t0, $t5, $t3
    ctx->r8 = SUB32(ctx->r13, ctx->r11);
    // 0x80191848: andi        $t8, $t0, 0xFF
    ctx->r24 = ctx->r8 & 0XFF;
    // 0x8019184C: ori         $at, $at, 0x4000
    ctx->r1 = ctx->r1 | 0X4000;
    // 0x80191850: or          $t4, $t8, $at
    ctx->r12 = ctx->r24 | ctx->r1;
    // 0x80191854: sw          $t4, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r12;
    // 0x80191858: lw          $t6, 0xE4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XE4);
    // 0x8019185C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80191860: addiu       $t3, $t3, 0x2318
    ctx->r11 = ADD32(ctx->r11, 0X2318);
    // 0x80191864: sll         $t5, $t6, 3
    ctx->r13 = S32(ctx->r14 << 3);
    // 0x80191868: addu        $t5, $t5, $t6
    ctx->r13 = ADD32(ctx->r13, ctx->r14);
    // 0x8019186C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80191870: addu        $t0, $t5, $t3
    ctx->r8 = ADD32(ctx->r13, ctx->r11);
    // 0x80191874: lwc1        $f16, 0x18($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X18);
    // 0x80191878: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8019187C: addiu       $t9, $t9, 0x3C00
    ctx->r25 = ADD32(ctx->r25, 0X3C00);
    // 0x80191880: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x80191884: lw          $a2, 0x10($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X10);
    // 0x80191888: lw          $a3, 0x14($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X14);
    // 0x8019188C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80191890: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x80191894: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x80191898: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    // 0x8019189C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x801918A0: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x801918A4: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x801918A8: lwc1        $f18, 0x0($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X0);
    // 0x801918AC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x801918B0: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x801918B4: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    // 0x801918B8: lwc1        $f8, 0x0($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X0);
    // 0x801918BC: sll         $t7, $t1, 2
    ctx->r15 = S32(ctx->r9 << 2);
    // 0x801918C0: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x801918C4: lw          $a0, -0x108C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X108C);
    // 0x801918C8: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x801918CC: jal         0x800C6144
    // 0x801918D0: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    func_800C6144(rdram, ctx);
        goto after_29;
    // 0x801918D0: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    after_29:
    // 0x801918D4: b           L_80192160
    // 0x801918D8: nop

        goto L_80192160;
    // 0x801918D8: nop

L_801918DC:
    // 0x801918DC: lw          $t9, 0xE4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XE4);
    // 0x801918E0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801918E4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801918E8: sll         $t1, $t9, 3
    ctx->r9 = S32(ctx->r25 << 3);
    // 0x801918EC: addu        $t1, $t1, $t9
    ctx->r9 = ADD32(ctx->r9, ctx->r25);
    // 0x801918F0: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x801918F4: addu        $t7, $t7, $t1
    ctx->r15 = ADD32(ctx->r15, ctx->r9);
    // 0x801918F8: lw          $t7, 0x2320($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X2320);
    // 0x801918FC: addiu       $t6, $t6, 0x3C00
    ctx->r14 = ADD32(ctx->r14, 0X3C00);
    // 0x80191900: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80191904: addiu       $t5, $t5, 0x3C00
    ctx->r13 = ADD32(ctx->r13, 0X3C00);
    // 0x80191908: sw          $t7, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r15;
    // 0x8019190C: lw          $t3, 0x0($t5)
    ctx->r11 = MEM_W(ctx->r13, 0X0);
    // 0x80191910: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x80191914: bgez        $t3, L_8019192C
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80191918: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_8019192C;
    }
    // 0x80191918: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8019191C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80191920: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80191924: nop

    // 0x80191928: add.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f4.fl;
L_8019192C:
    // 0x8019192C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80191930: lwc1        $f18, 0x4F8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X4F8);
    // 0x80191934: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80191938: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019193C: mul.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80191940: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80191944: lwc1        $f4, -0x2E30($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x80191948: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8019194C: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x80191950: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x80191954: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80191958: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8019195C: lui         $t2, 0xFA00
    ctx->r10 = S32(0XFA00 << 16);
    // 0x80191960: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80191964: addiu       $t1, $t1, 0x3C00
    ctx->r9 = ADD32(ctx->r9, 0X3C00);
    // 0x80191968: mul.s       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8019196C: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x80191970: addiu       $t5, $t5, -0xF9C
    ctx->r13 = ADD32(ctx->r13, -0XF9C);
    // 0x80191974: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80191978: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8019197C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80191980: swc1        $f16, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f16.u32l;
    // 0x80191984: lw          $t8, -0x4514($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4514);
    // 0x80191988: sw          $t8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r24;
    // 0x8019198C: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x80191990: addiu       $t4, $t8, 0x8
    ctx->r12 = ADD32(ctx->r24, 0X8);
    // 0x80191994: sw          $t4, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r12;
    // 0x80191998: sw          $t2, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r10;
    // 0x8019199C: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x801919A0: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x801919A4: addu        $t3, $t6, $t5
    ctx->r11 = ADD32(ctx->r14, ctx->r13);
    // 0x801919A8: lbu         $t2, 0x1($t3)
    ctx->r10 = MEM_BU(ctx->r11, 0X1);
    // 0x801919AC: lbu         $t0, 0x0($t3)
    ctx->r8 = MEM_BU(ctx->r11, 0X0);
    // 0x801919B0: lbu         $t6, 0x2($t3)
    ctx->r14 = MEM_BU(ctx->r11, 0X2);
    // 0x801919B4: andi        $t9, $t2, 0xFF
    ctx->r25 = ctx->r10 & 0XFF;
    // 0x801919B8: andi        $t8, $t0, 0xFF
    ctx->r24 = ctx->r8 & 0XFF;
    // 0x801919BC: lbu         $t2, 0x3($t3)
    ctx->r10 = MEM_BU(ctx->r11, 0X3);
    // 0x801919C0: sll         $t4, $t8, 24
    ctx->r12 = S32(ctx->r24 << 24);
    // 0x801919C4: sll         $t1, $t9, 16
    ctx->r9 = S32(ctx->r25 << 16);
    // 0x801919C8: or          $t7, $t4, $t1
    ctx->r15 = ctx->r12 | ctx->r9;
    // 0x801919CC: andi        $t5, $t6, 0xFF
    ctx->r13 = ctx->r14 & 0XFF;
    // 0x801919D0: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x801919D4: sll         $t0, $t5, 8
    ctx->r8 = S32(ctx->r13 << 8);
    // 0x801919D8: or          $t8, $t7, $t0
    ctx->r24 = ctx->r15 | ctx->r8;
    // 0x801919DC: andi        $t9, $t2, 0xFF
    ctx->r25 = ctx->r10 & 0XFF;
    // 0x801919E0: or          $t4, $t9, $t8
    ctx->r12 = ctx->r25 | ctx->r24;
    // 0x801919E4: sw          $t4, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r12;
    // 0x801919E8: lw          $t0, 0xE4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XE4);
    // 0x801919EC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x801919F0: addiu       $t2, $t2, 0x2318
    ctx->r10 = ADD32(ctx->r10, 0X2318);
    // 0x801919F4: sll         $t3, $t0, 3
    ctx->r11 = S32(ctx->r8 << 3);
    // 0x801919F8: addu        $t3, $t3, $t0
    ctx->r11 = ADD32(ctx->r11, ctx->r8);
    // 0x801919FC: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80191A00: addu        $t9, $t3, $t2
    ctx->r25 = ADD32(ctx->r11, ctx->r10);
    // 0x80191A04: lwc1        $f18, 0x18($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X18);
    // 0x80191A08: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80191A0C: addiu       $t6, $t6, 0x3C00
    ctx->r14 = ADD32(ctx->r14, 0X3C00);
    // 0x80191A10: lw          $t5, 0x0($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X0);
    // 0x80191A14: lw          $a2, 0x10($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X10);
    // 0x80191A18: lw          $a3, 0x14($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X14);
    // 0x80191A1C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80191A20: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x80191A24: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x80191A28: lwc1        $f8, 0x0($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X0);
    // 0x80191A2C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80191A30: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x80191A34: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x80191A38: lwc1        $f6, 0x0($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X0);
    // 0x80191A3C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80191A40: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x80191A44: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x80191A48: lwc1        $f10, 0x0($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X0);
    // 0x80191A4C: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x80191A50: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x80191A54: lw          $a0, -0x106C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X106C);
    // 0x80191A58: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x80191A5C: jal         0x800C6144
    // 0x80191A60: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    func_800C6144(rdram, ctx);
        goto after_30;
    // 0x80191A60: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    after_30:
    // 0x80191A64: b           L_80192160
    // 0x80191A68: nop

        goto L_80192160;
    // 0x80191A68: nop

L_80191A6C:
    // 0x80191A6C: lw          $t6, 0xE4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XE4);
    // 0x80191A70: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80191A74: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80191A78: sll         $t5, $t6, 3
    ctx->r13 = S32(ctx->r14 << 3);
    // 0x80191A7C: addu        $t5, $t5, $t6
    ctx->r13 = ADD32(ctx->r13, ctx->r14);
    // 0x80191A80: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80191A84: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x80191A88: lw          $t7, 0x2320($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X2320);
    // 0x80191A8C: addiu       $t0, $t0, 0x3C00
    ctx->r8 = ADD32(ctx->r8, 0X3C00);
    // 0x80191A90: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80191A94: addiu       $t3, $t3, 0x3C00
    ctx->r11 = ADD32(ctx->r11, 0X3C00);
    // 0x80191A98: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x80191A9C: lw          $t2, 0x0($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X0);
    // 0x80191AA0: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x80191AA4: bgez        $t2, L_80191ABC
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80191AA8: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_80191ABC;
    }
    // 0x80191AA8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80191AAC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80191AB0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80191AB4: nop

    // 0x80191AB8: add.s       $f18, $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f8.fl;
L_80191ABC:
    // 0x80191ABC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80191AC0: lwc1        $f6, 0x4FC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X4FC);
    // 0x80191AC4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80191AC8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80191ACC: mul.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x80191AD0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80191AD4: lwc1        $f8, -0x2E30($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x80191AD8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80191ADC: addiu       $t9, $t9, 0x3E00
    ctx->r25 = ADD32(ctx->r25, 0X3E00);
    // 0x80191AE0: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x80191AE4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80191AE8: add.s       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80191AEC: lui         $t1, 0xFA00
    ctx->r9 = S32(0XFA00 << 16);
    // 0x80191AF0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80191AF4: addiu       $t5, $t5, 0x3C00
    ctx->r13 = ADD32(ctx->r13, 0X3C00);
    // 0x80191AF8: mul.s       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x80191AFC: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80191B00: addiu       $t3, $t3, -0xF7C
    ctx->r11 = ADD32(ctx->r11, -0XF7C);
    // 0x80191B04: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80191B08: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80191B0C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80191B10: swc1        $f18, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f18.u32l;
    // 0x80191B14: lw          $t8, -0x4514($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4514);
    // 0x80191B18: sw          $t8, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r24;
    // 0x80191B1C: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x80191B20: addiu       $t4, $t8, 0x8
    ctx->r12 = ADD32(ctx->r24, 0X8);
    // 0x80191B24: sw          $t4, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r12;
    // 0x80191B28: sw          $t1, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r9;
    // 0x80191B2C: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x80191B30: sll         $t0, $t7, 2
    ctx->r8 = S32(ctx->r15 << 2);
    // 0x80191B34: addu        $t2, $t0, $t3
    ctx->r10 = ADD32(ctx->r8, ctx->r11);
    // 0x80191B38: lbu         $t1, 0x1($t2)
    ctx->r9 = MEM_BU(ctx->r10, 0X1);
    // 0x80191B3C: lbu         $t9, 0x0($t2)
    ctx->r25 = MEM_BU(ctx->r10, 0X0);
    // 0x80191B40: lbu         $t0, 0x2($t2)
    ctx->r8 = MEM_BU(ctx->r10, 0X2);
    // 0x80191B44: andi        $t6, $t1, 0xFF
    ctx->r14 = ctx->r9 & 0XFF;
    // 0x80191B48: andi        $t8, $t9, 0xFF
    ctx->r24 = ctx->r25 & 0XFF;
    // 0x80191B4C: lbu         $t1, 0x3($t2)
    ctx->r9 = MEM_BU(ctx->r10, 0X3);
    // 0x80191B50: sll         $t4, $t8, 24
    ctx->r12 = S32(ctx->r24 << 24);
    // 0x80191B54: sll         $t5, $t6, 16
    ctx->r13 = S32(ctx->r14 << 16);
    // 0x80191B58: or          $t7, $t4, $t5
    ctx->r15 = ctx->r12 | ctx->r13;
    // 0x80191B5C: andi        $t3, $t0, 0xFF
    ctx->r11 = ctx->r8 & 0XFF;
    // 0x80191B60: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    // 0x80191B64: sll         $t9, $t3, 8
    ctx->r25 = S32(ctx->r11 << 8);
    // 0x80191B68: or          $t8, $t7, $t9
    ctx->r24 = ctx->r15 | ctx->r25;
    // 0x80191B6C: andi        $t6, $t1, 0xFF
    ctx->r14 = ctx->r9 & 0XFF;
    // 0x80191B70: or          $t4, $t6, $t8
    ctx->r12 = ctx->r14 | ctx->r24;
    // 0x80191B74: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
    // 0x80191B78: lw          $t9, 0xE4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XE4);
    // 0x80191B7C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80191B80: addiu       $t1, $t1, 0x2318
    ctx->r9 = ADD32(ctx->r9, 0X2318);
    // 0x80191B84: sll         $t2, $t9, 3
    ctx->r10 = S32(ctx->r25 << 3);
    // 0x80191B88: addu        $t2, $t2, $t9
    ctx->r10 = ADD32(ctx->r10, ctx->r25);
    // 0x80191B8C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80191B90: addu        $t6, $t2, $t1
    ctx->r14 = ADD32(ctx->r10, ctx->r9);
    // 0x80191B94: lwc1        $f6, 0x18($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X18);
    // 0x80191B98: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80191B9C: addiu       $t0, $t0, 0x3C00
    ctx->r8 = ADD32(ctx->r8, 0X3C00);
    // 0x80191BA0: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x80191BA4: lw          $a2, 0x10($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X10);
    // 0x80191BA8: lw          $a3, 0x14($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X14);
    // 0x80191BAC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80191BB0: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x80191BB4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x80191BB8: lwc1        $f10, 0x0($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X0);
    // 0x80191BBC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80191BC0: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x80191BC4: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x80191BC8: lwc1        $f4, 0x0($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X0);
    // 0x80191BCC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80191BD0: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x80191BD4: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x80191BD8: lwc1        $f16, 0x0($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0X0);
    // 0x80191BDC: sll         $t7, $t3, 2
    ctx->r15 = S32(ctx->r11 << 2);
    // 0x80191BE0: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x80191BE4: lw          $a0, -0x104C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X104C);
    // 0x80191BE8: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x80191BEC: jal         0x800C6144
    // 0x80191BF0: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    func_800C6144(rdram, ctx);
        goto after_31;
    // 0x80191BF0: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    after_31:
    // 0x80191BF4: b           L_80192160
    // 0x80191BF8: nop

        goto L_80192160;
    // 0x80191BF8: nop

L_80191BFC:
    // 0x80191BFC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80191C00: lwc1        $f18, -0x2E30($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x80191C04: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80191C08: lwc1        $f6, 0x500($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X500);
    // 0x80191C0C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80191C10: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x80191C14: mul.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x80191C18: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80191C1C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80191C20: addiu       $t2, $t2, 0x3C00
    ctx->r10 = ADD32(ctx->r10, 0X3C00);
    // 0x80191C24: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x80191C28: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80191C2C: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x80191C30: swc1        $f10, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f10.u32l;
    // 0x80191C34: lw          $t3, 0xE4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XE4);
    // 0x80191C38: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80191C3C: addiu       $t5, $t5, 0x3C00
    ctx->r13 = ADD32(ctx->r13, 0X3C00);
    // 0x80191C40: sll         $t7, $t3, 3
    ctx->r15 = S32(ctx->r11 << 3);
    // 0x80191C44: addu        $t7, $t7, $t3
    ctx->r15 = ADD32(ctx->r15, ctx->r11);
    // 0x80191C48: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80191C4C: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x80191C50: lw          $t9, 0x2320($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X2320);
    // 0x80191C54: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80191C58: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80191C5C: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x80191C60: lw          $t1, -0x4514($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4514);
    // 0x80191C64: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x80191C68: addiu       $a0, $a0, 0x15E0
    ctx->r4 = ADD32(ctx->r4, 0X15E0);
    // 0x80191C6C: sw          $t1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r9;
    // 0x80191C70: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x80191C74: addiu       $t6, $t1, 0x8
    ctx->r14 = ADD32(ctx->r9, 0X8);
    // 0x80191C78: sw          $t6, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r14;
    // 0x80191C7C: sw          $t8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r24;
    // 0x80191C80: lw          $t0, 0x0($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X0);
    // 0x80191C84: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x80191C88: lui         $at, 0x2814
    ctx->r1 = S32(0X2814 << 16);
    // 0x80191C8C: addu        $t3, $t3, $t0
    ctx->r11 = ADD32(ctx->r11, ctx->r8);
    // 0x80191C90: lbu         $t3, -0xF5C($t3)
    ctx->r11 = MEM_BU(ctx->r11, -0XF5C);
    // 0x80191C94: ori         $at, $at, 0xA00
    ctx->r1 = ctx->r1 | 0XA00;
    // 0x80191C98: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80191C9C: sra         $t7, $t3, 1
    ctx->r15 = S32(SIGNED(ctx->r11) >> 1);
    // 0x80191CA0: andi        $t9, $t7, 0xFF
    ctx->r25 = ctx->r15 & 0XFF;
    // 0x80191CA4: or          $t2, $t9, $at
    ctx->r10 = ctx->r25 | ctx->r1;
    // 0x80191CA8: sw          $t2, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r10;
    // 0x80191CAC: lw          $t6, 0xE4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XE4);
    // 0x80191CB0: addiu       $t4, $t4, 0x2318
    ctx->r12 = ADD32(ctx->r12, 0X2318);
    // 0x80191CB4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80191CB8: sll         $t8, $t6, 3
    ctx->r24 = S32(ctx->r14 << 3);
    // 0x80191CBC: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x80191CC0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80191CC4: addu        $t5, $t8, $t4
    ctx->r13 = ADD32(ctx->r24, ctx->r12);
    // 0x80191CC8: lwc1        $f4, 0x18($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X18);
    // 0x80191CCC: lw          $a2, 0x10($t5)
    ctx->r6 = MEM_W(ctx->r13, 0X10);
    // 0x80191CD0: lw          $a3, 0x14($t5)
    ctx->r7 = MEM_W(ctx->r13, 0X14);
    // 0x80191CD4: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x80191CD8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80191CDC: lwc1        $f16, 0x0($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80191CE0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80191CE4: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x80191CE8: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x80191CEC: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x80191CF0: jal         0x800C6144
    // 0x80191CF4: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    func_800C6144(rdram, ctx);
        goto after_32;
    // 0x80191CF4: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    after_32:
    // 0x80191CF8: b           L_80192160
    // 0x80191CFC: nop

        goto L_80192160;
    // 0x80191CFC: nop

L_80191D00:
    // 0x80191D00: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80191D04: lwc1        $f18, -0x2E30($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x80191D08: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80191D0C: lwc1        $f6, 0x504($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X504);
    // 0x80191D10: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80191D14: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x80191D18: mul.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x80191D1C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80191D20: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80191D24: addiu       $t1, $t1, 0x3C00
    ctx->r9 = ADD32(ctx->r9, 0X3C00);
    // 0x80191D28: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x80191D2C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80191D30: lui         $t4, 0xFA00
    ctx->r12 = S32(0XFA00 << 16);
    // 0x80191D34: swc1        $f10, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f10.u32l;
    // 0x80191D38: lw          $t7, 0xE4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XE4);
    // 0x80191D3C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80191D40: addiu       $t0, $t0, 0x3C00
    ctx->r8 = ADD32(ctx->r8, 0X3C00);
    // 0x80191D44: sll         $t9, $t7, 3
    ctx->r25 = S32(ctx->r15 << 3);
    // 0x80191D48: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x80191D4C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80191D50: addu        $t2, $t2, $t9
    ctx->r10 = ADD32(ctx->r10, ctx->r25);
    // 0x80191D54: lw          $t2, 0x2320($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X2320);
    // 0x80191D58: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80191D5C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80191D60: sw          $t2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r10;
    // 0x80191D64: lw          $t6, -0x4514($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4514);
    // 0x80191D68: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x80191D6C: addiu       $a0, $a0, 0x1610
    ctx->r4 = ADD32(ctx->r4, 0X1610);
    // 0x80191D70: sw          $t6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r14;
    // 0x80191D74: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x80191D78: addiu       $t8, $t6, 0x8
    ctx->r24 = ADD32(ctx->r14, 0X8);
    // 0x80191D7C: sw          $t8, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r24;
    // 0x80191D80: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x80191D84: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x80191D88: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x80191D8C: lui         $at, 0x231E
    ctx->r1 = S32(0X231E << 16);
    // 0x80191D90: addu        $t7, $t7, $t3
    ctx->r15 = ADD32(ctx->r15, ctx->r11);
    // 0x80191D94: lbu         $t7, -0xF58($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0XF58);
    // 0x80191D98: ori         $at, $at, 0xF00
    ctx->r1 = ctx->r1 | 0XF00;
    // 0x80191D9C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80191DA0: sra         $t9, $t7, 1
    ctx->r25 = S32(SIGNED(ctx->r15) >> 1);
    // 0x80191DA4: andi        $t2, $t9, 0xFF
    ctx->r10 = ctx->r25 & 0XFF;
    // 0x80191DA8: or          $t1, $t2, $at
    ctx->r9 = ctx->r10 | ctx->r1;
    // 0x80191DAC: sw          $t1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r9;
    // 0x80191DB0: lw          $t8, 0xE4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XE4);
    // 0x80191DB4: addiu       $t5, $t5, 0x2318
    ctx->r13 = ADD32(ctx->r13, 0X2318);
    // 0x80191DB8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80191DBC: sll         $t4, $t8, 3
    ctx->r12 = S32(ctx->r24 << 3);
    // 0x80191DC0: addu        $t4, $t4, $t8
    ctx->r12 = ADD32(ctx->r12, ctx->r24);
    // 0x80191DC4: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80191DC8: addu        $t0, $t4, $t5
    ctx->r8 = ADD32(ctx->r12, ctx->r13);
    // 0x80191DCC: lwc1        $f4, 0x18($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X18);
    // 0x80191DD0: lw          $a2, 0x10($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X10);
    // 0x80191DD4: lw          $a3, 0x14($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X14);
    // 0x80191DD8: addiu       $t3, $t3, 0x3E00
    ctx->r11 = ADD32(ctx->r11, 0X3E00);
    // 0x80191DDC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80191DE0: lwc1        $f16, 0x0($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X0);
    // 0x80191DE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80191DE8: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x80191DEC: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x80191DF0: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x80191DF4: jal         0x800C6144
    // 0x80191DF8: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    func_800C6144(rdram, ctx);
        goto after_33;
    // 0x80191DF8: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    after_33:
    // 0x80191DFC: b           L_80192160
    // 0x80191E00: nop

        goto L_80192160;
    // 0x80191E00: nop

L_80191E04:
    // 0x80191E04: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80191E08: lwc1        $f18, -0x2E30($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x80191E0C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80191E10: addiu       $t7, $t7, 0x3E00
    ctx->r15 = ADD32(ctx->r15, 0X3E00);
    // 0x80191E14: swc1        $f18, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f18.u32l;
    // 0x80191E18: lw          $t9, 0xE4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XE4);
    // 0x80191E1C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80191E20: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80191E24: sll         $t2, $t9, 3
    ctx->r10 = S32(ctx->r25 << 3);
    // 0x80191E28: addu        $t2, $t2, $t9
    ctx->r10 = ADD32(ctx->r10, ctx->r25);
    // 0x80191E2C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80191E30: addu        $t1, $t1, $t2
    ctx->r9 = ADD32(ctx->r9, ctx->r10);
    // 0x80191E34: lw          $t1, 0x2320($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X2320);
    // 0x80191E38: addiu       $t6, $t6, 0x3C00
    ctx->r14 = ADD32(ctx->r14, 0X3C00);
    // 0x80191E3C: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x80191E40: sw          $t1, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r9;
    // 0x80191E44: lw          $t8, -0x4514($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4514);
    // 0x80191E48: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80191E4C: lui         $t5, 0xFC12
    ctx->r13 = S32(0XFC12 << 16);
    // 0x80191E50: sw          $t8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r24;
    // 0x80191E54: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x80191E58: addiu       $t4, $t8, 0x8
    ctx->r12 = ADD32(ctx->r24, 0X8);
    // 0x80191E5C: sw          $t4, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r12;
    // 0x80191E60: ori         $t5, $t5, 0x1824
    ctx->r13 = ctx->r13 | 0X1824;
    // 0x80191E64: sw          $t5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r13;
    // 0x80191E68: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x80191E6C: lui         $t3, 0xFF33
    ctx->r11 = S32(0XFF33 << 16);
    // 0x80191E70: ori         $t3, $t3, 0xFFFF
    ctx->r11 = ctx->r11 | 0XFFFF;
    // 0x80191E74: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x80191E78: sw          $t3, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r11;
    // 0x80191E7C: lw          $t9, -0x4514($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4514);
    // 0x80191E80: lui         $t1, 0xE300
    ctx->r9 = S32(0XE300 << 16);
    // 0x80191E84: ori         $t1, $t1, 0x1001
    ctx->r9 = ctx->r9 | 0X1001;
    // 0x80191E88: sw          $t9, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r25;
    // 0x80191E8C: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x80191E90: addiu       $t2, $t9, 0x8
    ctx->r10 = ADD32(ctx->r25, 0X8);
    // 0x80191E94: sw          $t2, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r10;
    // 0x80191E98: sw          $t1, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r9;
    // 0x80191E9C: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x80191EA0: ori         $t8, $zero, 0x8000
    ctx->r24 = 0 | 0X8000;
    // 0x80191EA4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80191EA8: sw          $t8, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r24;
    // 0x80191EAC: lw          $t7, 0xE4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XE4);
    // 0x80191EB0: addiu       $t2, $t2, 0x2318
    ctx->r10 = ADD32(ctx->r10, 0X2318);
    // 0x80191EB4: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80191EB8: sll         $t9, $t7, 3
    ctx->r25 = S32(ctx->r15 << 3);
    // 0x80191EBC: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x80191EC0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80191EC4: addu        $t1, $t9, $t2
    ctx->r9 = ADD32(ctx->r25, ctx->r10);
    // 0x80191EC8: lwc1        $f6, 0x18($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X18);
    // 0x80191ECC: addiu       $t5, $t5, 0x3C00
    ctx->r13 = ADD32(ctx->r13, 0X3C00);
    // 0x80191ED0: lw          $t0, 0x0($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X0);
    // 0x80191ED4: lw          $a2, 0x10($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X10);
    // 0x80191ED8: lw          $a3, 0x14($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X14);
    // 0x80191EDC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80191EE0: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x80191EE4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x80191EE8: lwc1        $f10, 0x0($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X0);
    // 0x80191EEC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80191EF0: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x80191EF4: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x80191EF8: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    // 0x80191EFC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80191F00: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x80191F04: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x80191F08: lwc1        $f16, 0x0($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X0);
    // 0x80191F0C: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80191F10: sll         $t3, $t0, 2
    ctx->r11 = S32(ctx->r8 << 2);
    // 0x80191F14: addu        $a0, $a0, $t3
    ctx->r4 = ADD32(ctx->r4, ctx->r11);
    // 0x80191F18: lw          $a0, -0xFEC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0XFEC);
    // 0x80191F1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80191F20: jal         0x800C60A0
    // 0x80191F24: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    func_800C60A0(rdram, ctx);
        goto after_34;
    // 0x80191F24: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    after_34:
    // 0x80191F28: b           L_80192160
    // 0x80191F2C: nop

        goto L_80192160;
    // 0x80191F2C: nop

L_80191F30:
    // 0x80191F30: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80191F34: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80191F38: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80191F3C: lwc1        $f18, -0x2E30($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x80191F40: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80191F44: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x80191F48: mul.s       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x80191F4C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80191F50: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80191F54: addiu       $t9, $t9, 0x3C00
    ctx->r25 = ADD32(ctx->r25, 0X3C00);
    // 0x80191F58: lui         $t2, 0x8011
    ctx->r10 = S32(0X8011 << 16);
    // 0x80191F5C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80191F60: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x80191F64: swc1        $f6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f6.u32l;
    // 0x80191F68: lw          $t0, 0xE4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XE4);
    // 0x80191F6C: lui         $t4, 0xFFDC
    ctx->r12 = S32(0XFFDC << 16);
    // 0x80191F70: ori         $t4, $t4, 0x40FF
    ctx->r12 = ctx->r12 | 0X40FF;
    // 0x80191F74: sll         $t3, $t0, 3
    ctx->r11 = S32(ctx->r8 << 3);
    // 0x80191F78: addu        $t3, $t3, $t0
    ctx->r11 = ADD32(ctx->r11, ctx->r8);
    // 0x80191F7C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80191F80: addu        $t7, $t7, $t3
    ctx->r15 = ADD32(ctx->r15, ctx->r11);
    // 0x80191F84: lw          $t7, 0x2320($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X2320);
    // 0x80191F88: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80191F8C: addiu       $t0, $t0, 0x3C00
    ctx->r8 = ADD32(ctx->r8, 0X3C00);
    // 0x80191F90: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
    // 0x80191F94: lw          $t2, -0x4514($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4514);
    // 0x80191F98: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80191F9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80191FA0: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    // 0x80191FA4: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x80191FA8: addiu       $t1, $t2, 0x8
    ctx->r9 = ADD32(ctx->r10, 0X8);
    // 0x80191FAC: sw          $t1, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r9;
    // 0x80191FB0: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x80191FB4: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x80191FB8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80191FBC: addiu       $t1, $t1, 0x2318
    ctx->r9 = ADD32(ctx->r9, 0X2318);
    // 0x80191FC0: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
    // 0x80191FC4: lw          $t9, 0xE4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XE4);
    // 0x80191FC8: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x80191FCC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80191FD0: sll         $t2, $t9, 3
    ctx->r10 = S32(ctx->r25 << 3);
    // 0x80191FD4: addu        $t2, $t2, $t9
    ctx->r10 = ADD32(ctx->r10, ctx->r25);
    // 0x80191FD8: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80191FDC: addu        $t6, $t2, $t1
    ctx->r14 = ADD32(ctx->r10, ctx->r9);
    // 0x80191FE0: lwc1        $f10, 0x18($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X18);
    // 0x80191FE4: lw          $a2, 0x10($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X10);
    // 0x80191FE8: lw          $a3, 0x14($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X14);
    // 0x80191FEC: addiu       $t8, $t8, 0x3E00
    ctx->r24 = ADD32(ctx->r24, 0X3E00);
    // 0x80191FF0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80191FF4: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    // 0x80191FF8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80191FFC: addiu       $t4, $t4, 0x3E00
    ctx->r12 = ADD32(ctx->r12, 0X3E00);
    // 0x80192000: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x80192004: lwc1        $f16, 0x0($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X0);
    // 0x80192008: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8019200C: addiu       $t5, $t5, 0x3E00
    ctx->r13 = ADD32(ctx->r13, 0X3E00);
    // 0x80192010: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x80192014: lwc1        $f8, 0x0($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X0);
    // 0x80192018: sll         $t7, $t3, 2
    ctx->r15 = S32(ctx->r11 << 2);
    // 0x8019201C: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x80192020: lw          $a0, -0x108C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X108C);
    // 0x80192024: jal         0x800C60A0
    // 0x80192028: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    func_800C60A0(rdram, ctx);
        goto after_35;
    // 0x80192028: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    after_35:
    // 0x8019202C: b           L_80192160
    // 0x80192030: nop

        goto L_80192160;
    // 0x80192030: nop

L_80192034:
    // 0x80192034: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x80192038: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8019203C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80192040: lwc1        $f6, -0x2E30($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2E30);
    // 0x80192044: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80192048: addiu       $t0, $t0, 0x3E00
    ctx->r8 = ADD32(ctx->r8, 0X3E00);
    // 0x8019204C: mul.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x80192050: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80192054: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80192058: addiu       $t2, $t2, 0x3C00
    ctx->r10 = ADD32(ctx->r10, 0X3C00);
    // 0x8019205C: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x80192060: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80192064: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x80192068: swc1        $f10, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f10.u32l;
    // 0x8019206C: lw          $t3, 0xE4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XE4);
    // 0x80192070: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80192074: addiu       $t5, $t5, 0x3C00
    ctx->r13 = ADD32(ctx->r13, 0X3C00);
    // 0x80192078: sll         $t7, $t3, 3
    ctx->r15 = S32(ctx->r11 << 3);
    // 0x8019207C: addu        $t7, $t7, $t3
    ctx->r15 = ADD32(ctx->r15, ctx->r11);
    // 0x80192080: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80192084: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x80192088: lw          $t9, 0x2320($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X2320);
    // 0x8019208C: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80192090: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80192094: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x80192098: lw          $t1, -0x4514($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4514);
    // 0x8019209C: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x801920A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801920A4: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    // 0x801920A8: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x801920AC: addiu       $t6, $t1, 0x8
    ctx->r14 = ADD32(ctx->r9, 0X8);
    // 0x801920B0: sw          $t6, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r14;
    // 0x801920B4: sw          $t8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r24;
    // 0x801920B8: lw          $t0, 0x0($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X0);
    // 0x801920BC: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x801920C0: lui         $at, 0xFFDC
    ctx->r1 = S32(0XFFDC << 16);
    // 0x801920C4: sll         $t3, $t0, 4
    ctx->r11 = S32(ctx->r8 << 4);
    // 0x801920C8: subu        $t3, $t3, $t0
    ctx->r11 = SUB32(ctx->r11, ctx->r8);
    // 0x801920CC: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x801920D0: subu        $t9, $t7, $t3
    ctx->r25 = SUB32(ctx->r15, ctx->r11);
    // 0x801920D4: andi        $t2, $t9, 0xFF
    ctx->r10 = ctx->r25 & 0XFF;
    // 0x801920D8: ori         $at, $at, 0x4000
    ctx->r1 = ctx->r1 | 0X4000;
    // 0x801920DC: or          $t1, $t2, $at
    ctx->r9 = ctx->r10 | ctx->r1;
    // 0x801920E0: sw          $t1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r9;
    // 0x801920E4: lw          $t0, 0xE4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XE4);
    // 0x801920E8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x801920EC: addiu       $t3, $t3, 0x2318
    ctx->r11 = ADD32(ctx->r11, 0X2318);
    // 0x801920F0: sll         $t7, $t0, 3
    ctx->r15 = S32(ctx->r8 << 3);
    // 0x801920F4: addu        $t7, $t7, $t0
    ctx->r15 = ADD32(ctx->r15, ctx->r8);
    // 0x801920F8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801920FC: addu        $t9, $t7, $t3
    ctx->r25 = ADD32(ctx->r15, ctx->r11);
    // 0x80192100: lwc1        $f4, 0x18($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X18);
    // 0x80192104: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80192108: addiu       $t8, $t8, 0x3C00
    ctx->r24 = ADD32(ctx->r24, 0X3C00);
    // 0x8019210C: lw          $t4, 0x0($t8)
    ctx->r12 = MEM_W(ctx->r24, 0X0);
    // 0x80192110: lw          $a2, 0x10($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X10);
    // 0x80192114: lw          $a3, 0x14($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X14);
    // 0x80192118: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8019211C: addiu       $t2, $t2, 0x3E00
    ctx->r10 = ADD32(ctx->r10, 0X3E00);
    // 0x80192120: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80192124: lwc1        $f16, 0x0($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X0);
    // 0x80192128: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8019212C: addiu       $t1, $t1, 0x3E00
    ctx->r9 = ADD32(ctx->r9, 0X3E00);
    // 0x80192130: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x80192134: lwc1        $f8, 0x0($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X0);
    // 0x80192138: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8019213C: addiu       $t6, $t6, 0x3E00
    ctx->r14 = ADD32(ctx->r14, 0X3E00);
    // 0x80192140: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x80192144: lwc1        $f18, 0x0($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X0);
    // 0x80192148: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8019214C: addu        $a0, $a0, $t5
    ctx->r4 = ADD32(ctx->r4, ctx->r13);
    // 0x80192150: lw          $a0, -0x108C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X108C);
    // 0x80192154: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x80192158: jal         0x800C6144
    // 0x8019215C: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    func_800C6144(rdram, ctx);
        goto after_36;
    // 0x8019215C: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    after_36:
L_80192160:
    // 0x80192160: lw          $t8, 0xE4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XE4);
    // 0x80192164: addiu       $t4, $t8, 0x1
    ctx->r12 = ADD32(ctx->r24, 0X1);
    // 0x80192168: slti        $at, $t4, 0x80
    ctx->r1 = SIGNED(ctx->r12) < 0X80 ? 1 : 0;
    // 0x8019216C: bne         $at, $zero, L_8018FAB0
    if (ctx->r1 != 0) {
        // 0x80192170: sw          $t4, 0xE4($sp)
        MEM_W(0XE4, ctx->r29) = ctx->r12;
            goto L_8018FAB0;
    }
    // 0x80192170: sw          $t4, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r12;
    // 0x80192174: lui         $t5, 0x8011
    ctx->r13 = S32(0X8011 << 16);
    // 0x80192178: lw          $t5, -0x4514($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4514);
    // 0x8019217C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80192180: lui         $t7, 0xDE00
    ctx->r15 = S32(0XDE00 << 16);
    // 0x80192184: sw          $t5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r13;
    // 0x80192188: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x8019218C: addiu       $t0, $t5, 0x8
    ctx->r8 = ADD32(ctx->r13, 0X8);
    // 0x80192190: sw          $t0, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r8;
    // 0x80192194: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x80192198: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x8019219C: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x801921A0: addiu       $t9, $t9, -0x68E8
    ctx->r25 = ADD32(ctx->r25, -0X68E8);
    // 0x801921A4: sw          $t9, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r25;
    // 0x801921A8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x801921AC: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
    // 0x801921B0: jr          $ra
    // 0x801921B4: nop

    return;
    // 0x801921B4: nop

;}
RECOMP_FUNC void func_801921B8_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801921B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801921BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801921C0: jal         0x801921E8
    // 0x801921C4: nop

    func_801921E8_1501A0(rdram, ctx);
        goto after_0;
    // 0x801921C4: nop

    after_0:
    // 0x801921C8: jal         0x801922A8
    // 0x801921CC: nop

    func_801922A8_1501A0(rdram, ctx);
        goto after_1;
    // 0x801921CC: nop

    after_1:
    // 0x801921D0: jal         0x801928DC
    // 0x801921D4: nop

    func_801928DC_1501A0(rdram, ctx);
        goto after_2;
    // 0x801921D4: nop

    after_2:
    // 0x801921D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801921DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801921E0: jr          $ra
    // 0x801921E4: nop

    return;
    // 0x801921E4: nop

;}
RECOMP_FUNC void func_801921E8_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801921E8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801921EC: lhu         $t6, -0x2D84($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X2D84);
    // 0x801921F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801921F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801921F8: bne         $t6, $zero, L_80192210
    if (ctx->r14 != 0) {
        // 0x801921FC: nop
    
            goto L_80192210;
    }
    // 0x801921FC: nop

    // 0x80192200: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80192204: lhu         $t7, -0x2D82($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X2D82);
    // 0x80192208: beq         $t7, $zero, L_80192298
    if (ctx->r15 == 0) {
        // 0x8019220C: nop
    
            goto L_80192298;
    }
    // 0x8019220C: nop

L_80192210:
    // 0x80192210: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80192214: lw          $t8, -0x2E44($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2E44);
    // 0x80192218: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8019221C: sltiu       $at, $t9, 0x6
    ctx->r1 = ctx->r25 < 0X6 ? 1 : 0;
    // 0x80192220: beq         $at, $zero, L_80192298
    if (ctx->r1 == 0) {
        // 0x80192224: nop
    
            goto L_80192298;
    }
    // 0x80192224: nop

    // 0x80192228: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8019222C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80192230: addu        $at, $at, $t9
    gpr jr_addend_80192238 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80192234: lw          $t9, 0x508($at)
    ctx->r25 = ADD32(ctx->r1, 0X508);
    // 0x80192238: jr          $t9
    // 0x8019223C: nop

    switch (jr_addend_80192238 >> 2) {
        case 0: goto L_80192240; break;
        case 1: goto L_80192250; break;
        case 2: goto L_80192260; break;
        case 3: goto L_80192270; break;
        case 4: goto L_80192280; break;
        case 5: goto L_80192290; break;
        default: switch_error(__func__, 0x80192238, 0x801A0508);
    }
    // 0x8019223C: nop

L_80192240:
    // 0x80192240: jal         0x801D2270
    // 0x80192244: nop

    LOOKUP_FUNC(0x801D2270)(rdram, ctx);
        goto after_0;
    // 0x80192244: nop

    after_0:
    // 0x80192248: b           L_80192298
    // 0x8019224C: nop

        goto L_80192298;
    // 0x8019224C: nop

L_80192250:
    // 0x80192250: jal         0x801D2270
    // 0x80192254: nop

    LOOKUP_FUNC(0x801D2270)(rdram, ctx);
        goto after_1;
    // 0x80192254: nop

    after_1:
    // 0x80192258: b           L_80192298
    // 0x8019225C: nop

        goto L_80192298;
    // 0x8019225C: nop

L_80192260:
    // 0x80192260: jal         0x801D2270
    // 0x80192264: nop

    LOOKUP_FUNC(0x801D2270)(rdram, ctx);
        goto after_2;
    // 0x80192264: nop

    after_2:
    // 0x80192268: b           L_80192298
    // 0x8019226C: nop

        goto L_80192298;
    // 0x8019226C: nop

L_80192270:
    // 0x80192270: jal         0x801D2270
    // 0x80192274: nop

    LOOKUP_FUNC(0x801D2270)(rdram, ctx);
        goto after_3;
    // 0x80192274: nop

    after_3:
    // 0x80192278: b           L_80192298
    // 0x8019227C: nop

        goto L_80192298;
    // 0x8019227C: nop

L_80192280:
    // 0x80192280: jal         0x801D2270
    // 0x80192284: nop

    LOOKUP_FUNC(0x801D2270)(rdram, ctx);
        goto after_4;
    // 0x80192284: nop

    after_4:
    // 0x80192288: b           L_80192298
    // 0x8019228C: nop

        goto L_80192298;
    // 0x8019228C: nop

L_80192290:
    // 0x80192290: jal         0x801D228C
    // 0x80192294: nop

    func_801D228C_4DC6D0(rdram, ctx);
        goto after_5;
    // 0x80192294: nop

    after_5:
L_80192298:
    // 0x80192298: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8019229C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801922A0: jr          $ra
    // 0x801922A4: nop

    return;
    // 0x801922A4: nop

;}
RECOMP_FUNC void func_801922A8_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801922A8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801922AC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801922B0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801922B4: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
L_801922B8:
    // 0x801922B8: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x801922BC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801922C0: lw          $t6, -0x2D88($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2D88);
    // 0x801922C4: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x801922C8: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x801922CC: addu        $t0, $t6, $t9
    ctx->r8 = ADD32(ctx->r14, ctx->r25);
    // 0x801922D0: lhu         $t1, 0x0($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X0);
    // 0x801922D4: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x801922D8: beq         $t1, $at, L_801928C8
    if (ctx->r9 == ctx->r1) {
        // 0x801922DC: nop
    
            goto L_801928C8;
    }
    // 0x801922DC: nop

    // 0x801922E0: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x801922E4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x801922E8: lw          $t2, -0x2D88($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2D88);
    // 0x801922EC: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x801922F0: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x801922F4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801922F8: addu        $t7, $t2, $t5
    ctx->r15 = ADD32(ctx->r10, ctx->r13);
    // 0x801922FC: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x80192300: lw          $t6, -0x2E34($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2E34);
    // 0x80192304: bne         $t8, $t6, L_801928B8
    if (ctx->r24 != ctx->r14) {
        // 0x80192308: nop
    
            goto L_801928B8;
    }
    // 0x80192308: nop

    // 0x8019230C: lhu         $t9, 0x2($t7)
    ctx->r25 = MEM_HU(ctx->r15, 0X2);
    // 0x80192310: ori         $at, $zero, 0xF000
    ctx->r1 = 0 | 0XF000;
    // 0x80192314: slt         $at, $t9, $at
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80192318: bne         $at, $zero, L_80192828
    if (ctx->r1 != 0) {
        // 0x8019231C: sh          $t9, 0x26($sp)
        MEM_H(0X26, ctx->r29) = ctx->r25;
            goto L_80192828;
    }
    // 0x8019231C: sh          $t9, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r25;
    // 0x80192320: or          $s0, $t9, $zero
    ctx->r16 = ctx->r25 | 0;
    // 0x80192324: ori         $at, $zero, 0xF229
    ctx->r1 = 0 | 0XF229;
    // 0x80192328: slt         $at, $s0, $at
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8019232C: bne         $at, $zero, L_80192354
    if (ctx->r1 != 0) {
        // 0x80192330: ori         $at, $zero, 0xFC00
        ctx->r1 = 0 | 0XFC00;
            goto L_80192354;
    }
    // 0x80192330: ori         $at, $zero, 0xFC00
    ctx->r1 = 0 | 0XFC00;
    // 0x80192334: beq         $s0, $at, L_8019277C
    if (ctx->r16 == ctx->r1) {
        // 0x80192338: ori         $at, $zero, 0xFC10
        ctx->r1 = 0 | 0XFC10;
            goto L_8019277C;
    }
    // 0x80192338: ori         $at, $zero, 0xFC10
    ctx->r1 = 0 | 0XFC10;
    // 0x8019233C: beq         $s0, $at, L_801927C0
    if (ctx->r16 == ctx->r1) {
        // 0x80192340: ori         $at, $zero, 0xFF00
        ctx->r1 = 0 | 0XFF00;
            goto L_801927C0;
    }
    // 0x80192340: ori         $at, $zero, 0xFF00
    ctx->r1 = 0 | 0XFF00;
    // 0x80192344: beq         $s0, $at, L_8019274C
    if (ctx->r16 == ctx->r1) {
        // 0x80192348: nop
    
            goto L_8019274C;
    }
    // 0x80192348: nop

    // 0x8019234C: b           L_801928B8
    // 0x80192350: nop

        goto L_801928B8;
    // 0x80192350: nop

L_80192354:
    // 0x80192354: ori         $at, $zero, 0xF128
    ctx->r1 = 0 | 0XF128;
    // 0x80192358: slt         $at, $s0, $at
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8019235C: bne         $at, $zero, L_80192390
    if (ctx->r1 != 0) {
        // 0x80192360: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_80192390;
    }
    // 0x80192360: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80192364: ori         $at, $at, 0xE00
    ctx->r1 = ctx->r1 | 0XE00;
    // 0x80192368: addu        $t0, $s0, $at
    ctx->r8 = ADD32(ctx->r16, ctx->r1);
    // 0x8019236C: sltiu       $at, $t0, 0x29
    ctx->r1 = ctx->r8 < 0X29 ? 1 : 0;
    // 0x80192370: beq         $at, $zero, L_801928B8
    if (ctx->r1 == 0) {
        // 0x80192374: nop
    
            goto L_801928B8;
    }
    // 0x80192374: nop

    // 0x80192378: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8019237C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80192380: addu        $at, $at, $t0
    gpr jr_addend_80192388 = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80192384: lw          $t0, 0x520($at)
    ctx->r8 = ADD32(ctx->r1, 0X520);
    // 0x80192388: jr          $t0
    // 0x8019238C: nop

    switch (jr_addend_80192388 >> 2) {
        case 0: goto L_801925F8; break;
        case 1: goto L_80192660; break;
        case 2: goto L_80192660; break;
        case 3: goto L_80192660; break;
        case 4: goto L_80192660; break;
        case 5: goto L_80192660; break;
        case 6: goto L_80192660; break;
        case 7: goto L_80192660; break;
        case 8: goto L_80192660; break;
        case 9: goto L_80192660; break;
        case 10: goto L_80192660; break;
        case 11: goto L_80192660; break;
        case 12: goto L_80192660; break;
        case 13: goto L_80192660; break;
        case 14: goto L_80192660; break;
        case 15: goto L_80192660; break;
        case 16: goto L_80192660; break;
        case 17: goto L_80192660; break;
        case 18: goto L_80192660; break;
        case 19: goto L_80192660; break;
        case 20: goto L_80192660; break;
        case 21: goto L_80192660; break;
        case 22: goto L_80192660; break;
        case 23: goto L_80192660; break;
        case 24: goto L_80192660; break;
        case 25: goto L_80192660; break;
        case 26: goto L_80192660; break;
        case 27: goto L_80192660; break;
        case 28: goto L_80192660; break;
        case 29: goto L_80192660; break;
        case 30: goto L_80192660; break;
        case 31: goto L_80192660; break;
        case 32: goto L_80192660; break;
        case 33: goto L_80192660; break;
        case 34: goto L_80192660; break;
        case 35: goto L_80192660; break;
        case 36: goto L_80192660; break;
        case 37: goto L_80192660; break;
        case 38: goto L_80192660; break;
        case 39: goto L_80192660; break;
        case 40: goto L_80192660; break;
        default: switch_error(__func__, 0x80192388, 0x801A0520);
    }
    // 0x8019238C: nop

L_80192390:
    // 0x80192390: ori         $at, $zero, 0xF041
    ctx->r1 = 0 | 0XF041;
    // 0x80192394: slt         $at, $s0, $at
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80192398: bne         $at, $zero, L_801923CC
    if (ctx->r1 != 0) {
        // 0x8019239C: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_801923CC;
    }
    // 0x8019239C: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x801923A0: ori         $at, $at, 0xF00
    ctx->r1 = ctx->r1 | 0XF00;
    // 0x801923A4: addu        $t1, $s0, $at
    ctx->r9 = ADD32(ctx->r16, ctx->r1);
    // 0x801923A8: sltiu       $at, $t1, 0x28
    ctx->r1 = ctx->r9 < 0X28 ? 1 : 0;
    // 0x801923AC: beq         $at, $zero, L_801928B8
    if (ctx->r1 == 0) {
        // 0x801923B0: nop
    
            goto L_801928B8;
    }
    // 0x801923B0: nop

    // 0x801923B4: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x801923B8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801923BC: addu        $at, $at, $t1
    gpr jr_addend_801923C4 = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x801923C0: lw          $t1, 0x5C4($at)
    ctx->r9 = ADD32(ctx->r1, 0X5C4);
    // 0x801923C4: jr          $t1
    // 0x801923C8: nop

    switch (jr_addend_801923C4 >> 2) {
        case 0: goto L_801923FC; break;
        case 1: goto L_80192414; break;
        case 2: goto L_80192414; break;
        case 3: goto L_80192414; break;
        case 4: goto L_80192414; break;
        case 5: goto L_80192414; break;
        case 6: goto L_80192414; break;
        case 7: goto L_80192414; break;
        case 8: goto L_80192414; break;
        case 9: goto L_80192414; break;
        case 10: goto L_80192414; break;
        case 11: goto L_80192414; break;
        case 12: goto L_80192414; break;
        case 13: goto L_80192414; break;
        case 14: goto L_80192414; break;
        case 15: goto L_80192414; break;
        case 16: goto L_80192414; break;
        case 17: goto L_80192414; break;
        case 18: goto L_80192414; break;
        case 19: goto L_80192414; break;
        case 20: goto L_80192414; break;
        case 21: goto L_80192414; break;
        case 22: goto L_80192414; break;
        case 23: goto L_80192414; break;
        case 24: goto L_80192414; break;
        case 25: goto L_80192414; break;
        case 26: goto L_80192414; break;
        case 27: goto L_80192414; break;
        case 28: goto L_80192414; break;
        case 29: goto L_80192414; break;
        case 30: goto L_80192414; break;
        case 31: goto L_80192414; break;
        case 32: goto L_80192414; break;
        case 33: goto L_80192414; break;
        case 34: goto L_80192414; break;
        case 35: goto L_80192414; break;
        case 36: goto L_80192414; break;
        case 37: goto L_80192414; break;
        case 38: goto L_80192414; break;
        case 39: goto L_80192414; break;
        default: switch_error(__func__, 0x801923C4, 0x801A05C4);
    }
    // 0x801923C8: nop

L_801923CC:
    // 0x801923CC: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x801923D0: ori         $at, $at, 0xFFF
    ctx->r1 = ctx->r1 | 0XFFF;
    // 0x801923D4: addu        $t3, $s0, $at
    ctx->r11 = ADD32(ctx->r16, ctx->r1);
    // 0x801923D8: sltiu       $at, $t3, 0x40
    ctx->r1 = ctx->r11 < 0X40 ? 1 : 0;
    // 0x801923DC: beq         $at, $zero, L_801928B8
    if (ctx->r1 == 0) {
        // 0x801923E0: nop
    
            goto L_801928B8;
    }
    // 0x801923E0: nop

    // 0x801923E4: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x801923E8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801923EC: addu        $at, $at, $t3
    gpr jr_addend_801923F4 = ctx->r11;
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x801923F0: lw          $t3, 0x664($at)
    ctx->r11 = ADD32(ctx->r1, 0X664);
    // 0x801923F4: jr          $t3
    // 0x801923F8: nop

    switch (jr_addend_801923F4 >> 2) {
        case 0: goto L_80192434; break;
        case 1: goto L_80192494; break;
        case 2: goto L_801924AC; break;
        case 3: goto L_801928B8; break;
        case 4: goto L_801928B8; break;
        case 5: goto L_801928B8; break;
        case 6: goto L_801928B8; break;
        case 7: goto L_801928B8; break;
        case 8: goto L_801928B8; break;
        case 9: goto L_801928B8; break;
        case 10: goto L_801928B8; break;
        case 11: goto L_801928B8; break;
        case 12: goto L_801928B8; break;
        case 13: goto L_801928B8; break;
        case 14: goto L_801928B8; break;
        case 15: goto L_801924BC; break;
        case 16: goto L_8019252C; break;
        case 17: goto L_801928B8; break;
        case 18: goto L_801928B8; break;
        case 19: goto L_801928B8; break;
        case 20: goto L_801928B8; break;
        case 21: goto L_801928B8; break;
        case 22: goto L_801928B8; break;
        case 23: goto L_801928B8; break;
        case 24: goto L_801928B8; break;
        case 25: goto L_801928B8; break;
        case 26: goto L_801928B8; break;
        case 27: goto L_801928B8; break;
        case 28: goto L_801928B8; break;
        case 29: goto L_801928B8; break;
        case 30: goto L_801928B8; break;
        case 31: goto L_8019257C; break;
        case 32: goto L_8019258C; break;
        case 33: goto L_801928B8; break;
        case 34: goto L_801928B8; break;
        case 35: goto L_801928B8; break;
        case 36: goto L_801928B8; break;
        case 37: goto L_801928B8; break;
        case 38: goto L_801928B8; break;
        case 39: goto L_801928B8; break;
        case 40: goto L_801928B8; break;
        case 41: goto L_801928B8; break;
        case 42: goto L_801928B8; break;
        case 43: goto L_801928B8; break;
        case 44: goto L_801928B8; break;
        case 45: goto L_801928B8; break;
        case 46: goto L_801928B8; break;
        case 47: goto L_801925B8; break;
        case 48: goto L_801925E8; break;
        case 49: goto L_801925C8; break;
        case 50: goto L_801925D8; break;
        case 51: goto L_801928B8; break;
        case 52: goto L_801928B8; break;
        case 53: goto L_801928B8; break;
        case 54: goto L_801928B8; break;
        case 55: goto L_801928B8; break;
        case 56: goto L_801928B8; break;
        case 57: goto L_801928B8; break;
        case 58: goto L_801928B8; break;
        case 59: goto L_801928B8; break;
        case 60: goto L_801928B8; break;
        case 61: goto L_801928B8; break;
        case 62: goto L_801928B8; break;
        case 63: goto L_801926F0; break;
        default: switch_error(__func__, 0x801923F4, 0x801A0664);
    }
    // 0x801923F8: nop

L_801923FC:
    // 0x801923FC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80192400: addiu       $t4, $t4, -0x2E18
    ctx->r12 = ADD32(ctx->r12, -0X2E18);
    // 0x80192404: lw          $t2, 0x28($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X28);
    // 0x80192408: addiu       $t5, $t2, 0x1
    ctx->r13 = ADD32(ctx->r10, 0X1);
    // 0x8019240C: b           L_801928B8
    // 0x80192410: sw          $t5, 0x28($t4)
    MEM_W(0X28, ctx->r12) = ctx->r13;
        goto L_801928B8;
    // 0x80192410: sw          $t5, 0x28($t4)
    MEM_W(0X28, ctx->r12) = ctx->r13;
L_80192414:
    // 0x80192414: lhu         $t8, 0x26($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X26);
    // 0x80192418: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8019241C: ori         $at, $at, 0xF00
    ctx->r1 = ctx->r1 | 0XF00;
    // 0x80192420: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80192424: addiu       $t7, $t7, -0x2E18
    ctx->r15 = ADD32(ctx->r15, -0X2E18);
    // 0x80192428: addu        $t6, $t8, $at
    ctx->r14 = ADD32(ctx->r24, ctx->r1);
    // 0x8019242C: b           L_801928B8
    // 0x80192430: sw          $t6, 0x28($t7)
    MEM_W(0X28, ctx->r15) = ctx->r14;
        goto L_801928B8;
    // 0x80192430: sw          $t6, 0x28($t7)
    MEM_W(0X28, ctx->r15) = ctx->r14;
L_80192434:
    // 0x80192434: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80192438: addiu       $t9, $t9, -0x2E28
    ctx->r25 = ADD32(ctx->r25, -0X2E28);
    // 0x8019243C: lbu         $t0, 0xA($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0XA);
    // 0x80192440: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80192444: addiu       $t3, $t3, -0x2E28
    ctx->r11 = ADD32(ctx->r11, -0X2E28);
    // 0x80192448: ori         $t1, $t0, 0x2
    ctx->r9 = ctx->r8 | 0X2;
    // 0x8019244C: sb          $t1, 0xA($t9)
    MEM_B(0XA, ctx->r25) = ctx->r9;
    // 0x80192450: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80192454: sb          $zero, 0xD($t3)
    MEM_B(0XD, ctx->r11) = 0;
    // 0x80192458: addiu       $t2, $t2, -0x2E18
    ctx->r10 = ADD32(ctx->r10, -0X2E18);
    // 0x8019245C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80192460: addiu       $t5, $t5, -0x2E18
    ctx->r13 = ADD32(ctx->r13, -0X2E18);
    // 0x80192464: sw          $zero, 0x8($t2)
    MEM_W(0X8, ctx->r10) = 0;
    // 0x80192468: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8019246C: addiu       $t4, $t4, -0x2E18
    ctx->r12 = ADD32(ctx->r12, -0X2E18);
    // 0x80192470: sw          $zero, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = 0;
    // 0x80192474: lw          $s0, 0x1C($t4)
    ctx->r16 = MEM_W(ctx->r12, 0X1C);
    // 0x80192478: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8019247C: addiu       $t8, $t8, -0x2E18
    ctx->r24 = ADD32(ctx->r24, -0X2E18);
    // 0x80192480: sw          $s0, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->r16;
    // 0x80192484: jal         0x800D1680
    // 0x80192488: sw          $s0, 0x14($t8)
    MEM_W(0X14, ctx->r24) = ctx->r16;
    func_800D1680(rdram, ctx);
        goto after_0;
    // 0x80192488: sw          $s0, 0x14($t8)
    MEM_W(0X14, ctx->r24) = ctx->r16;
    after_0:
    // 0x8019248C: b           L_801928B8
    // 0x80192490: nop

        goto L_801928B8;
    // 0x80192490: nop

L_80192494:
    // 0x80192494: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80192498: addiu       $t6, $t6, -0x2E28
    ctx->r14 = ADD32(ctx->r14, -0X2E28);
    // 0x8019249C: lbu         $t7, 0xA($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0XA);
    // 0x801924A0: andi        $t0, $t7, 0xFB
    ctx->r8 = ctx->r15 & 0XFB;
    // 0x801924A4: b           L_801928B8
    // 0x801924A8: sb          $t0, 0xA($t6)
    MEM_B(0XA, ctx->r14) = ctx->r8;
        goto L_801928B8;
    // 0x801924A8: sb          $t0, 0xA($t6)
    MEM_B(0XA, ctx->r14) = ctx->r8;
L_801924AC:
    // 0x801924AC: jal         0x80192C24
    // 0x801924B0: nop

    func_80192C24_1501A0(rdram, ctx);
        goto after_1;
    // 0x801924B0: nop

    after_1:
    // 0x801924B4: b           L_801928B8
    // 0x801924B8: nop

        goto L_801928B8;
    // 0x801924B8: nop

L_801924BC:
    // 0x801924BC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x801924C0: lhu         $t1, -0x2BA8($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X2BA8);
    // 0x801924C4: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x801924C8: lw          $t3, -0x2E3C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2E3C);
    // 0x801924CC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801924D0: ori         $t9, $t1, 0x4000
    ctx->r25 = ctx->r9 | 0X4000;
    // 0x801924D4: sh          $t9, -0x2BA8($at)
    MEM_H(-0X2BA8, ctx->r1) = ctx->r25;
    // 0x801924D8: beq         $t3, $zero, L_8019251C
    if (ctx->r11 == 0) {
        // 0x801924DC: sw          $zero, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = 0;
            goto L_8019251C;
    }
    // 0x801924DC: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_801924E0:
    // 0x801924E0: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x801924E4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801924E8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x801924EC: sll         $t5, $t2, 2
    ctx->r13 = S32(ctx->r10 << 2);
    // 0x801924F0: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x801924F4: jal         0x80173864
    // 0x801924F8: sw          $zero, -0x2B7C($at)
    MEM_W(-0X2B7C, ctx->r1) = 0;
    func_80173864_1501A0(rdram, ctx);
        goto after_2;
    // 0x801924F8: sw          $zero, -0x2B7C($at)
    MEM_W(-0X2B7C, ctx->r1) = 0;
    after_2:
    // 0x801924FC: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80192500: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80192504: lw          $t7, -0x2E3C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2E3C);
    // 0x80192508: addiu       $t8, $t4, 0x1
    ctx->r24 = ADD32(ctx->r12, 0X1);
    // 0x8019250C: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x80192510: sltu        $at, $t8, $t7
    ctx->r1 = ctx->r24 < ctx->r15 ? 1 : 0;
    // 0x80192514: bne         $at, $zero, L_801924E0
    if (ctx->r1 != 0) {
        // 0x80192518: nop
    
            goto L_801924E0;
    }
    // 0x80192518: nop

L_8019251C:
    // 0x8019251C: jal         0x800D1680
    // 0x80192520: nop

    func_800D1680(rdram, ctx);
        goto after_3;
    // 0x80192520: nop

    after_3:
    // 0x80192524: b           L_801928B8
    // 0x80192528: nop

        goto L_801928B8;
    // 0x80192528: nop

L_8019252C:
    // 0x8019252C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80192530: lhu         $t0, -0x2BA8($t0)
    ctx->r8 = MEM_HU(ctx->r8, -0X2BA8);
    // 0x80192534: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80192538: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8019253C: andi        $t6, $t0, 0xBFFF
    ctx->r14 = ctx->r8 & 0XBFFF;
    // 0x80192540: sh          $t6, -0x2BA8($at)
    MEM_H(-0X2BA8, ctx->r1) = ctx->r14;
    // 0x80192544: addiu       $t1, $t1, -0x2E28
    ctx->r9 = ADD32(ctx->r9, -0X2E28);
    // 0x80192548: lbu         $t9, 0xE($t1)
    ctx->r25 = MEM_BU(ctx->r9, 0XE);
    // 0x8019254C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80192550: ori         $t3, $t9, 0x2
    ctx->r11 = ctx->r25 | 0X2;
    // 0x80192554: sb          $t3, 0xE($t1)
    MEM_B(0XE, ctx->r9) = ctx->r11;
    // 0x80192558: lw          $t2, -0x2D68($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2D68);
    // 0x8019255C: bne         $t2, $zero, L_8019256C
    if (ctx->r10 != 0) {
        // 0x80192560: nop
    
            goto L_8019256C;
    }
    // 0x80192560: nop

    // 0x80192564: jal         0x800C8544
    // 0x80192568: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    func_800C8544(rdram, ctx);
        goto after_4;
    // 0x80192568: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_4:
L_8019256C:
    // 0x8019256C: jal         0x800D28C0
    // 0x80192570: nop

    func_800D28C0(rdram, ctx);
        goto after_5;
    // 0x80192570: nop

    after_5:
    // 0x80192574: b           L_801928B8
    // 0x80192578: nop

        goto L_801928B8;
    // 0x80192578: nop

L_8019257C:
    // 0x8019257C: jal         0x800C9514
    // 0x80192580: nop

    func_800C9514(rdram, ctx);
        goto after_6;
    // 0x80192580: nop

    after_6:
    // 0x80192584: b           L_801928B8
    // 0x80192588: nop

        goto L_801928B8;
    // 0x80192588: nop

L_8019258C:
    // 0x8019258C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80192590: lw          $t5, -0x2E48($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2E48);
    // 0x80192594: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80192598: beq         $t5, $at, L_801928B8
    if (ctx->r13 == ctx->r1) {
        // 0x8019259C: nop
    
            goto L_801928B8;
    }
    // 0x8019259C: nop

    // 0x801925A0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x801925A4: lw          $a0, -0x2E44($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2E44);
    // 0x801925A8: jal         0x800C9560
    // 0x801925AC: addiu       $a0, $a0, 0xA
    ctx->r4 = ADD32(ctx->r4, 0XA);
    func_800C9560(rdram, ctx);
        goto after_7;
    // 0x801925AC: addiu       $a0, $a0, 0xA
    ctx->r4 = ADD32(ctx->r4, 0XA);
    after_7:
    // 0x801925B0: b           L_801928B8
    // 0x801925B4: nop

        goto L_801928B8;
    // 0x801925B4: nop

L_801925B8:
    // 0x801925B8: jal         0x800C3264
    // 0x801925BC: nop

    func_800C3264(rdram, ctx);
        goto after_8;
    // 0x801925BC: nop

    after_8:
    // 0x801925C0: b           L_801928B8
    // 0x801925C4: nop

        goto L_801928B8;
    // 0x801925C4: nop

L_801925C8:
    // 0x801925C8: jal         0x800C328C
    // 0x801925CC: nop

    func_800C328C(rdram, ctx);
        goto after_9;
    // 0x801925CC: nop

    after_9:
    // 0x801925D0: b           L_801928B8
    // 0x801925D4: nop

        goto L_801928B8;
    // 0x801925D4: nop

L_801925D8:
    // 0x801925D8: jal         0x800C32CC
    // 0x801925DC: nop

    func_800C32CC(rdram, ctx);
        goto after_10;
    // 0x801925DC: nop

    after_10:
    // 0x801925E0: b           L_801928B8
    // 0x801925E4: nop

        goto L_801928B8;
    // 0x801925E4: nop

L_801925E8:
    // 0x801925E8: jal         0x800C3234
    // 0x801925EC: nop

    func_800C3234(rdram, ctx);
        goto after_11;
    // 0x801925EC: nop

    after_11:
    // 0x801925F0: b           L_801928B8
    // 0x801925F4: nop

        goto L_801928B8;
    // 0x801925F4: nop

L_801925F8:
    // 0x801925F8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x801925FC: addiu       $t4, $t4, -0x2D90
    ctx->r12 = ADD32(ctx->r12, -0X2D90);
    // 0x80192600: lwc1        $f4, 0x20($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X20);
    // 0x80192604: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80192608: swc1        $f4, -0x2C0C($at)
    MEM_W(-0X2C0C, ctx->r1) = ctx->f4.u32l;
    // 0x8019260C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80192610: swc1        $f4, -0x41A4($at)
    MEM_W(-0X41A4, ctx->r1) = ctx->f4.u32l;
    // 0x80192614: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80192618: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019261C: lwc1        $f6, 0x20($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X20);
    // 0x80192620: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80192624: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80192628: swc1        $f10, -0x2C1C($at)
    MEM_W(-0X2C1C, ctx->r1) = ctx->f10.u32l;
    // 0x8019262C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80192630: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80192634: lwc1        $f16, 0x20($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X20);
    // 0x80192638: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8019263C: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80192640: swc1        $f4, -0x2C18($at)
    MEM_W(-0X2C18, ctx->r1) = ctx->f4.u32l;
    // 0x80192644: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80192648: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019264C: lwc1        $f6, 0x20($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X20);
    // 0x80192650: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80192654: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80192658: b           L_801928B8
    // 0x8019265C: swc1        $f10, -0x2C14($at)
    MEM_W(-0X2C14, ctx->r1) = ctx->f10.u32l;
        goto L_801928B8;
    // 0x8019265C: swc1        $f10, -0x2C14($at)
    MEM_W(-0X2C14, ctx->r1) = ctx->f10.u32l;
L_80192660:
    // 0x80192660: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80192664: lwc1        $f16, -0x2C0C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2C0C);
    // 0x80192668: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8019266C: addiu       $t8, $t8, -0x2D90
    ctx->r24 = ADD32(ctx->r24, -0X2D90);
    // 0x80192670: swc1        $f16, 0x20($t8)
    MEM_W(0X20, ctx->r24) = ctx->f16.u32l;
    // 0x80192674: lhu         $t7, 0x26($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X26);
    // 0x80192678: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8019267C: ori         $at, $at, 0xDFF
    ctx->r1 = ctx->r1 | 0XDFF;
    // 0x80192680: addu        $t0, $t7, $at
    ctx->r8 = ADD32(ctx->r15, ctx->r1);
    // 0x80192684: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x80192688: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8019268C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80192690: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80192694: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80192698: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8019269C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801926A0: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801926A4: swc1        $f16, -0x2C0C($at)
    MEM_W(-0X2C0C, ctx->r1) = ctx->f16.u32l;
    // 0x801926A8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801926AC: swc1        $f16, -0x41A4($at)
    MEM_W(-0X41A4, ctx->r1) = ctx->f16.u32l;
    // 0x801926B0: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x801926B4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801926B8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801926BC: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x801926C0: swc1        $f4, -0x2C1C($at)
    MEM_W(-0X2C1C, ctx->r1) = ctx->f4.u32l;
    // 0x801926C4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801926C8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801926CC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801926D0: mul.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x801926D4: swc1        $f8, -0x2C18($at)
    MEM_W(-0X2C18, ctx->r1) = ctx->f8.u32l;
    // 0x801926D8: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x801926DC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801926E0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801926E4: mul.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x801926E8: b           L_801928B8
    // 0x801926EC: swc1        $f18, -0x2C14($at)
    MEM_W(-0X2C14, ctx->r1) = ctx->f18.u32l;
        goto L_801928B8;
    // 0x801926EC: swc1        $f18, -0x2C14($at)
    MEM_W(-0X2C14, ctx->r1) = ctx->f18.u32l;
L_801926F0:
    // 0x801926F0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801926F4: lw          $t6, -0x2E48($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2E48);
    // 0x801926F8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801926FC: bne         $t6, $at, L_801928B8
    if (ctx->r14 != ctx->r1) {
        // 0x80192700: nop
    
            goto L_801928B8;
    }
    // 0x80192700: nop

    // 0x80192704: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80192708: addiu       $t9, $t9, -0x2E28
    ctx->r25 = ADD32(ctx->r25, -0X2E28);
    // 0x8019270C: lbu         $t3, 0xC($t9)
    ctx->r11 = MEM_BU(ctx->r25, 0XC);
    // 0x80192710: andi        $t1, $t3, 0x20
    ctx->r9 = ctx->r11 & 0X20;
    // 0x80192714: beq         $t1, $zero, L_80192724
    if (ctx->r9 == 0) {
        // 0x80192718: nop
    
            goto L_80192724;
    }
    // 0x80192718: nop

    // 0x8019271C: jal         0x80178318
    // 0x80192720: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80178318_1501A0(rdram, ctx);
        goto after_12;
    // 0x80192720: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_12:
L_80192724:
    // 0x80192724: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80192728: addiu       $t2, $t2, -0x2E28
    ctx->r10 = ADD32(ctx->r10, -0X2E28);
    // 0x8019272C: lbu         $t5, 0xC($t2)
    ctx->r13 = MEM_BU(ctx->r10, 0XC);
    // 0x80192730: andi        $t4, $t5, 0x40
    ctx->r12 = ctx->r13 & 0X40;
    // 0x80192734: beq         $t4, $zero, L_801928B8
    if (ctx->r12 == 0) {
        // 0x80192738: nop
    
            goto L_801928B8;
    }
    // 0x80192738: nop

    // 0x8019273C: jal         0x80178318
    // 0x80192740: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80178318_1501A0(rdram, ctx);
        goto after_13;
    // 0x80192740: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_13:
    // 0x80192744: b           L_801928B8
    // 0x80192748: nop

        goto L_801928B8;
    // 0x80192748: nop

L_8019274C:
    // 0x8019274C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80192750: lw          $t8, -0x2E4C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2E4C);
    // 0x80192754: bne         $t8, $zero, L_801928B8
    if (ctx->r24 != 0) {
        // 0x80192758: nop
    
            goto L_801928B8;
    }
    // 0x80192758: nop

    // 0x8019275C: jal         0x800C32CC
    // 0x80192760: nop

    func_800C32CC(rdram, ctx);
        goto after_14;
    // 0x80192760: nop

    after_14:
    // 0x80192764: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80192768: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8019276C: jal         0x800D1680
    // 0x80192770: sw          $t7, -0x2E4C($at)
    MEM_W(-0X2E4C, ctx->r1) = ctx->r15;
    func_800D1680(rdram, ctx);
        goto after_15;
    // 0x80192770: sw          $t7, -0x2E4C($at)
    MEM_W(-0X2E4C, ctx->r1) = ctx->r15;
    after_15:
    // 0x80192774: b           L_801928B8
    // 0x80192778: nop

        goto L_801928B8;
    // 0x80192778: nop

L_8019277C:
    // 0x8019277C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80192780: lw          $t0, -0x2E4C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2E4C);
    // 0x80192784: bne         $t0, $zero, L_801928B8
    if (ctx->r8 != 0) {
        // 0x80192788: nop
    
            goto L_801928B8;
    }
    // 0x80192788: nop

    // 0x8019278C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80192790: lw          $t6, -0x2E48($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2E48);
    // 0x80192794: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80192798: bne         $t6, $at, L_801928B8
    if (ctx->r14 != ctx->r1) {
        // 0x8019279C: nop
    
            goto L_801928B8;
    }
    // 0x8019279C: nop

    // 0x801927A0: jal         0x800C32CC
    // 0x801927A4: nop

    func_800C32CC(rdram, ctx);
        goto after_16;
    // 0x801927A4: nop

    after_16:
    // 0x801927A8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801927AC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801927B0: jal         0x800D1680
    // 0x801927B4: sw          $t9, -0x2E4C($at)
    MEM_W(-0X2E4C, ctx->r1) = ctx->r25;
    func_800D1680(rdram, ctx);
        goto after_17;
    // 0x801927B4: sw          $t9, -0x2E4C($at)
    MEM_W(-0X2E4C, ctx->r1) = ctx->r25;
    after_17:
    // 0x801927B8: b           L_801928B8
    // 0x801927BC: nop

        goto L_801928B8;
    // 0x801927BC: nop

L_801927C0:
    // 0x801927C0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x801927C4: lw          $t3, -0x2E48($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2E48);
    // 0x801927C8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801927CC: bne         $t3, $at, L_801928B8
    if (ctx->r11 != ctx->r1) {
        // 0x801927D0: nop
    
            goto L_801928B8;
    }
    // 0x801927D0: nop

    // 0x801927D4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x801927D8: addiu       $t1, $t1, -0x2E28
    ctx->r9 = ADD32(ctx->r9, -0X2E28);
    // 0x801927DC: lbu         $t2, 0xA($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0XA);
    // 0x801927E0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x801927E4: addiu       $t4, $t4, -0x2E18
    ctx->r12 = ADD32(ctx->r12, -0X2E18);
    // 0x801927E8: ori         $t5, $t2, 0x2
    ctx->r13 = ctx->r10 | 0X2;
    // 0x801927EC: sb          $t5, 0xA($t1)
    MEM_B(0XA, ctx->r9) = ctx->r13;
    // 0x801927F0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x801927F4: sw          $zero, 0x8($t4)
    MEM_W(0X8, ctx->r12) = 0;
    // 0x801927F8: addiu       $t8, $t8, -0x2E18
    ctx->r24 = ADD32(ctx->r24, -0X2E18);
    // 0x801927FC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80192800: addiu       $t7, $t7, -0x2E18
    ctx->r15 = ADD32(ctx->r15, -0X2E18);
    // 0x80192804: sw          $zero, 0x1C($t8)
    MEM_W(0X1C, ctx->r24) = 0;
    // 0x80192808: lw          $s0, 0x1C($t7)
    ctx->r16 = MEM_W(ctx->r15, 0X1C);
    // 0x8019280C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80192810: addiu       $t0, $t0, -0x2E18
    ctx->r8 = ADD32(ctx->r8, -0X2E18);
    // 0x80192814: sw          $s0, 0x18($t7)
    MEM_W(0X18, ctx->r15) = ctx->r16;
    // 0x80192818: jal         0x800D1680
    // 0x8019281C: sw          $s0, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r16;
    func_800D1680(rdram, ctx);
        goto after_18;
    // 0x8019281C: sw          $s0, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r16;
    after_18:
    // 0x80192820: b           L_801928B8
    // 0x80192824: nop

        goto L_801928B8;
    // 0x80192824: nop

L_80192828:
    // 0x80192828: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8019282C: lw          $t6, -0x2E44($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2E44);
    // 0x80192830: addiu       $t9, $t6, -0x1
    ctx->r25 = ADD32(ctx->r14, -0X1);
    // 0x80192834: sltiu       $at, $t9, 0x6
    ctx->r1 = ctx->r25 < 0X6 ? 1 : 0;
    // 0x80192838: beq         $at, $zero, L_801928B8
    if (ctx->r1 == 0) {
        // 0x8019283C: nop
    
            goto L_801928B8;
    }
    // 0x8019283C: nop

    // 0x80192840: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80192844: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80192848: addu        $at, $at, $t9
    gpr jr_addend_80192850 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8019284C: lw          $t9, 0x764($at)
    ctx->r25 = ADD32(ctx->r1, 0X764);
    // 0x80192850: jr          $t9
    // 0x80192854: nop

    switch (jr_addend_80192850 >> 2) {
        case 0: goto L_80192858; break;
        case 1: goto L_80192868; break;
        case 2: goto L_80192878; break;
        case 3: goto L_80192888; break;
        case 4: goto L_80192898; break;
        case 5: goto L_801928A8; break;
        default: switch_error(__func__, 0x80192850, 0x801A0764);
    }
    // 0x80192854: nop

L_80192858:
    // 0x80192858: jal         0x801D23A0
    // 0x8019285C: lhu         $a0, 0x26($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X26);
    func_801D23A0_1B66F0(rdram, ctx);
        goto after_19;
    // 0x8019285C: lhu         $a0, 0x26($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X26);
    after_19:
    // 0x80192860: b           L_801928B8
    // 0x80192864: nop

        goto L_801928B8;
    // 0x80192864: nop

L_80192868:
    // 0x80192868: jal         0x801D2760
    // 0x8019286C: lhu         $a0, 0x26($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X26);
    func_801D2760_255660(rdram, ctx);
        goto after_20;
    // 0x8019286C: lhu         $a0, 0x26($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X26);
    after_20:
    // 0x80192870: b           L_801928B8
    // 0x80192874: nop

        goto L_801928B8;
    // 0x80192874: nop

L_80192878:
    // 0x80192878: jal         0x801D23E8
    // 0x8019287C: lhu         $a0, 0x26($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X26);
    func_801D23E8_34B590(rdram, ctx);
        goto after_21;
    // 0x8019287C: lhu         $a0, 0x26($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X26);
    after_21:
    // 0x80192880: b           L_801928B8
    // 0x80192884: nop

        goto L_801928B8;
    // 0x80192884: nop

L_80192888:
    // 0x80192888: jal         0x801D2314
    // 0x8019288C: lhu         $a0, 0x26($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X26);
    func_801D2314_3EFDD0(rdram, ctx);
        goto after_22;
    // 0x8019288C: lhu         $a0, 0x26($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X26);
    after_22:
    // 0x80192890: b           L_801928B8
    // 0x80192894: nop

        goto L_801928B8;
    // 0x80192894: nop

L_80192898:
    // 0x80192898: jal         0x801D2278
    // 0x8019289C: lhu         $a0, 0x26($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X26);
    func_801D2278_497140(rdram, ctx);
        goto after_23;
    // 0x8019289C: lhu         $a0, 0x26($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X26);
    after_23:
    // 0x801928A0: b           L_801928B8
    // 0x801928A4: nop

        goto L_801928B8;
    // 0x801928A4: nop

L_801928A8:
    // 0x801928A8: jal         0x801D2358
    // 0x801928AC: lhu         $a0, 0x26($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X26);
    func_801D2358_4DC6D0(rdram, ctx);
        goto after_24;
    // 0x801928AC: lhu         $a0, 0x26($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X26);
    after_24:
    // 0x801928B0: b           L_801928C8
    // 0x801928B4: nop

        goto L_801928C8;
    // 0x801928B4: nop

L_801928B8:
    // 0x801928B8: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x801928BC: addiu       $t2, $t3, 0x1
    ctx->r10 = ADD32(ctx->r11, 0X1);
    // 0x801928C0: b           L_801922B8
    // 0x801928C4: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
        goto L_801922B8;
    // 0x801928C4: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
L_801928C8:
    // 0x801928C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801928CC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801928D0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801928D4: jr          $ra
    // 0x801928D8: nop

    return;
    // 0x801928D8: nop

;}
RECOMP_FUNC void func_801928DC_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801928DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801928E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
L_801928E4:
    // 0x801928E4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801928E8: lw          $t6, -0x2D90($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2D90);
    // 0x801928EC: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x801928F0: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x801928F4: beq         $t7, $at, L_80192958
    if (ctx->r15 == ctx->r1) {
        // 0x801928F8: nop
    
            goto L_80192958;
    }
    // 0x801928F8: nop

    // 0x801928FC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80192900: lw          $t8, -0x2D90($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2D90);
    // 0x80192904: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80192908: lw          $t0, -0x2E34($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2E34);
    // 0x8019290C: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x80192910: bne         $t9, $t0, L_80192958
    if (ctx->r25 != ctx->r8) {
        // 0x80192914: nop
    
            goto L_80192958;
    }
    // 0x80192914: nop

    // 0x80192918: jal         0x80180DE4
    // 0x8019291C: nop

    func_80180DE4_1501A0(rdram, ctx);
        goto after_0;
    // 0x8019291C: nop

    after_0:
    // 0x80192920: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80192924: lw          $t1, -0x2D90($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2D90);
    // 0x80192928: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8019292C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80192930: addiu       $t2, $t1, 0x10
    ctx->r10 = ADD32(ctx->r9, 0X10);
    // 0x80192934: sw          $t2, -0x2D90($at)
    MEM_W(-0X2D90, ctx->r1) = ctx->r10;
    // 0x80192938: addiu       $t3, $t3, -0x2E18
    ctx->r11 = ADD32(ctx->r11, -0X2E18);
    // 0x8019293C: lw          $t4, 0x64($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X64);
    // 0x80192940: sltiu       $at, $t4, 0x3E8
    ctx->r1 = ctx->r12 < 0X3E8 ? 1 : 0;
    // 0x80192944: bne         $at, $zero, L_801928E4
    if (ctx->r1 != 0) {
        // 0x80192948: nop
    
            goto L_801928E4;
    }
    // 0x80192948: nop

    // 0x8019294C: addiu       $t5, $zero, 0x3E7
    ctx->r13 = ADD32(0, 0X3E7);
    // 0x80192950: b           L_801928E4
    // 0x80192954: sw          $t5, 0x64($t3)
    MEM_W(0X64, ctx->r11) = ctx->r13;
        goto L_801928E4;
    // 0x80192954: sw          $t5, 0x64($t3)
    MEM_W(0X64, ctx->r11) = ctx->r13;
L_80192958:
    // 0x80192958: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8019295C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80192960: jr          $ra
    // 0x80192964: nop

    return;
    // 0x80192964: nop

;}
RECOMP_FUNC void func_80192968_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80192968: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8019296C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80192970: sh          $zero, -0x2D82($at)
    MEM_H(-0X2D82, ctx->r1) = 0;
    // 0x80192974: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80192978: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8019297C: sh          $zero, -0x2D84($at)
    MEM_H(-0X2D84, ctx->r1) = 0;
    // 0x80192980: addiu       $t6, $t6, -0x2D90
    ctx->r14 = ADD32(ctx->r14, -0X2D90);
    // 0x80192984: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80192988: addiu       $t7, $t7, -0x2D90
    ctx->r15 = ADD32(ctx->r15, -0X2D90);
    // 0x8019298C: swc1        $f4, 0x20($t6)
    MEM_W(0X20, ctx->r14) = ctx->f4.u32l;
    // 0x80192990: lwc1        $f14, 0x20($t7)
    ctx->f14.u32l = MEM_W(ctx->r15, 0X20);
    // 0x80192994: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80192998: addiu       $t8, $t8, -0x2D90
    ctx->r24 = ADD32(ctx->r24, -0X2D90);
    // 0x8019299C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801929A0: swc1        $f14, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->f14.u32l;
    // 0x801929A4: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    // 0x801929A8: swc1        $f12, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->f12.u32l;
    // 0x801929AC: addiu       $t9, $t9, -0x2D90
    ctx->r25 = ADD32(ctx->r25, -0X2D90);
    // 0x801929B0: swc1        $f12, 0x14($t9)
    MEM_W(0X14, ctx->r25) = ctx->f12.u32l;
    // 0x801929B4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x801929B8: lw          $t0, -0x2E44($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2E44);
    // 0x801929BC: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x801929C0: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x801929C4: sltiu       $at, $t1, 0x6
    ctx->r1 = ctx->r9 < 0X6 ? 1 : 0;
    // 0x801929C8: beq         $at, $zero, L_80192A5C
    if (ctx->r1 == 0) {
        // 0x801929CC: nop
    
            goto L_80192A5C;
    }
    // 0x801929CC: nop

    // 0x801929D0: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x801929D4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801929D8: addu        $at, $at, $t1
    gpr jr_addend_801929E0 = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x801929DC: lw          $t1, 0x77C($at)
    ctx->r9 = ADD32(ctx->r1, 0X77C);
    // 0x801929E0: jr          $t1
    // 0x801929E4: nop

    switch (jr_addend_801929E0 >> 2) {
        case 0: goto L_801929E8; break;
        case 1: goto L_801929FC; break;
        case 2: goto L_80192A10; break;
        case 3: goto L_80192A24; break;
        case 4: goto L_80192A38; break;
        case 5: goto L_80192A4C; break;
        default: switch_error(__func__, 0x801929E0, 0x801A077C);
    }
    // 0x801929E4: nop

L_801929E8:
    // 0x801929E8: lui         $t2, 0x801F
    ctx->r10 = S32(0X801F << 16);
    // 0x801929EC: addiu       $t2, $t2, -0x7004
    ctx->r10 = ADD32(ctx->r10, -0X7004);
    // 0x801929F0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801929F4: b           L_80192A5C
    // 0x801929F8: sw          $t2, -0x2D88($at)
    MEM_W(-0X2D88, ctx->r1) = ctx->r10;
        goto L_80192A5C;
    // 0x801929F8: sw          $t2, -0x2D88($at)
    MEM_W(-0X2D88, ctx->r1) = ctx->r10;
L_801929FC:
    // 0x801929FC: lui         $t3, 0x801F
    ctx->r11 = S32(0X801F << 16);
    // 0x80192A00: addiu       $t3, $t3, -0x3468
    ctx->r11 = ADD32(ctx->r11, -0X3468);
    // 0x80192A04: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80192A08: b           L_80192A5C
    // 0x80192A0C: sw          $t3, -0x2D88($at)
    MEM_W(-0X2D88, ctx->r1) = ctx->r11;
        goto L_80192A5C;
    // 0x80192A0C: sw          $t3, -0x2D88($at)
    MEM_W(-0X2D88, ctx->r1) = ctx->r11;
L_80192A10:
    // 0x80192A10: lui         $t4, 0x801E
    ctx->r12 = S32(0X801E << 16);
    // 0x80192A14: addiu       $t4, $t4, 0x43B0
    ctx->r12 = ADD32(ctx->r12, 0X43B0);
    // 0x80192A18: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80192A1C: b           L_80192A5C
    // 0x80192A20: sw          $t4, -0x2D88($at)
    MEM_W(-0X2D88, ctx->r1) = ctx->r12;
        goto L_80192A5C;
    // 0x80192A20: sw          $t4, -0x2D88($at)
    MEM_W(-0X2D88, ctx->r1) = ctx->r12;
L_80192A24:
    // 0x80192A24: lui         $t5, 0x801E
    ctx->r13 = S32(0X801E << 16);
    // 0x80192A28: addiu       $t5, $t5, -0xB34
    ctx->r13 = ADD32(ctx->r13, -0XB34);
    // 0x80192A2C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80192A30: b           L_80192A5C
    // 0x80192A34: sw          $t5, -0x2D88($at)
    MEM_W(-0X2D88, ctx->r1) = ctx->r13;
        goto L_80192A5C;
    // 0x80192A34: sw          $t5, -0x2D88($at)
    MEM_W(-0X2D88, ctx->r1) = ctx->r13;
L_80192A38:
    // 0x80192A38: lui         $t6, 0x801D
    ctx->r14 = S32(0X801D << 16);
    // 0x80192A3C: addiu       $t6, $t6, 0x7C44
    ctx->r14 = ADD32(ctx->r14, 0X7C44);
    // 0x80192A40: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80192A44: b           L_80192A5C
    // 0x80192A48: sw          $t6, -0x2D88($at)
    MEM_W(-0X2D88, ctx->r1) = ctx->r14;
        goto L_80192A5C;
    // 0x80192A48: sw          $t6, -0x2D88($at)
    MEM_W(-0X2D88, ctx->r1) = ctx->r14;
L_80192A4C:
    // 0x80192A4C: lui         $t7, 0x801E
    ctx->r15 = S32(0X801E << 16);
    // 0x80192A50: addiu       $t7, $t7, 0x30EC
    ctx->r15 = ADD32(ctx->r15, 0X30EC);
    // 0x80192A54: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80192A58: sw          $t7, -0x2D88($at)
    MEM_W(-0X2D88, ctx->r1) = ctx->r15;
L_80192A5C:
    // 0x80192A5C: jr          $ra
    // 0x80192A60: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80192A60: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80192A64_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80192A64: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80192A68: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_80192A6C:
    // 0x80192A6C: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x80192A70: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80192A74: addiu       $t8, $t8, -0x2A28
    ctx->r24 = ADD32(ctx->r24, -0X2A28);
    // 0x80192A78: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80192A7C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80192A80: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80192A84: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80192A88: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80192A8C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80192A90: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80192A94: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80192A98: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x80192A9C: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80192AA0: andi        $t1, $t0, 0x8400
    ctx->r9 = ctx->r8 & 0X8400;
    // 0x80192AA4: bne         $t1, $at, L_80192AC0
    if (ctx->r9 != ctx->r1) {
        // 0x80192AA8: nop
    
            goto L_80192AC0;
    }
    // 0x80192AA8: nop

    // 0x80192AAC: lw          $t2, 0x4($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X4);
    // 0x80192AB0: bne         $t2, $a0, L_80192AC0
    if (ctx->r10 != ctx->r4) {
        // 0x80192AB4: nop
    
            goto L_80192AC0;
    }
    // 0x80192AB4: nop

    // 0x80192AB8: b           L_80192AD8
    // 0x80192ABC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80192AD8;
    // 0x80192ABC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80192AC0:
    // 0x80192AC0: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x80192AC4: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80192AC8: sltiu       $at, $t4, 0x30
    ctx->r1 = ctx->r12 < 0X30 ? 1 : 0;
    // 0x80192ACC: bne         $at, $zero, L_80192A6C
    if (ctx->r1 != 0) {
        // 0x80192AD0: sw          $t4, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r12;
            goto L_80192A6C;
    }
    // 0x80192AD0: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x80192AD4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80192AD8:
    // 0x80192AD8: jr          $ra
    // 0x80192ADC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80192ADC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80192AE0_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80192AE0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80192AE4: lwc1        $f4, -0x2BC0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2BC0);
    // 0x80192AE8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80192AEC: ldc1        $f8, 0x798($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, 0X798);
    // 0x80192AF0: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80192AF4: c.lt.d      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.d < ctx->f6.d;
    // 0x80192AF8: nop

    // 0x80192AFC: bc1f        L_80192B0C
    if (!c1cs) {
        // 0x80192B00: nop
    
            goto L_80192B0C;
    }
    // 0x80192B00: nop

    // 0x80192B04: jr          $ra
    // 0x80192B08: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x80192B08: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80192B0C:
    // 0x80192B0C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80192B10: lwc1        $f10, -0x2BC0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2BC0);
    // 0x80192B14: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80192B18: ldc1        $f18, 0x7A0($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, 0X7A0);
    // 0x80192B1C: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80192B20: c.lt.d      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.d < ctx->f18.d;
    // 0x80192B24: nop

    // 0x80192B28: bc1f        L_80192B38
    if (!c1cs) {
        // 0x80192B2C: nop
    
            goto L_80192B38;
    }
    // 0x80192B2C: nop

    // 0x80192B30: jr          $ra
    // 0x80192B34: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    return;
    // 0x80192B34: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80192B38:
    // 0x80192B38: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80192B3C: lwc1        $f4, -0x2BBC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2BBC);
    // 0x80192B40: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80192B44: ldc1        $f8, 0x7A8($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, 0X7A8);
    // 0x80192B48: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80192B4C: c.lt.d      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.d < ctx->f6.d;
    // 0x80192B50: nop

    // 0x80192B54: bc1f        L_80192B64
    if (!c1cs) {
        // 0x80192B58: nop
    
            goto L_80192B64;
    }
    // 0x80192B58: nop

    // 0x80192B5C: jr          $ra
    // 0x80192B60: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80192B60: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80192B64:
    // 0x80192B64: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80192B68: lwc1        $f10, -0x2BBC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2BBC);
    // 0x80192B6C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80192B70: ldc1        $f18, 0x7B0($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, 0X7B0);
    // 0x80192B74: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80192B78: c.lt.d      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.d < ctx->f18.d;
    // 0x80192B7C: nop

    // 0x80192B80: bc1f        L_80192B90
    if (!c1cs) {
        // 0x80192B84: nop
    
            goto L_80192B90;
    }
    // 0x80192B84: nop

    // 0x80192B88: jr          $ra
    // 0x80192B8C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    return;
    // 0x80192B8C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80192B90:
    // 0x80192B90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80192B94: jr          $ra
    // 0x80192B98: nop

    return;
    // 0x80192B98: nop

;}
RECOMP_FUNC void func_80192B9C_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80192B9C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80192BA0: lw          $t6, -0x2E48($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2E48);
    // 0x80192BA4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80192BA8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80192BAC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80192BB0: beq         $t6, $at, L_80192BDC
    if (ctx->r14 == ctx->r1) {
        // 0x80192BB4: sw          $a0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r4;
            goto L_80192BDC;
    }
    // 0x80192BB4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80192BB8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80192BBC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80192BC0: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80192BC4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80192BC8: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80192BCC: jal         0x8019AC88
    // 0x80192BD0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_8019AC88_1501A0(rdram, ctx);
        goto after_0;
    // 0x80192BD0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80192BD4: b           L_80192C14
    // 0x80192BD8: nop

        goto L_80192C14;
    // 0x80192BD8: nop

L_80192BDC:
    // 0x80192BDC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80192BE0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80192BE4: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80192BE8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80192BEC: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80192BF0: jal         0x8019AFB0
    // 0x80192BF4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_8019AFB0_1501A0(rdram, ctx);
        goto after_1;
    // 0x80192BF4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x80192BF8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80192BFC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80192C00: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80192C04: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80192C08: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80192C0C: jal         0x8019B31C
    // 0x80192C10: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_8019B31C_1501A0(rdram, ctx);
        goto after_2;
    // 0x80192C10: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_2:
L_80192C14:
    // 0x80192C14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80192C18: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80192C1C: jr          $ra
    // 0x80192C20: nop

    return;
    // 0x80192C20: nop

;}
RECOMP_FUNC void func_80192C24_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80192C24: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80192C28: lw          $t6, -0x2E3C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2E3C);
    // 0x80192C2C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80192C30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80192C34: beq         $t6, $zero, L_80192C90
    if (ctx->r14 == 0) {
        // 0x80192C38: sw          $zero, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = 0;
            goto L_80192C90;
    }
    // 0x80192C38: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_80192C3C:
    // 0x80192C3C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80192C40: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80192C44: addiu       $t7, $t7, -0x2E28
    ctx->r15 = ADD32(ctx->r15, -0X2E28);
    // 0x80192C48: lbu         $t8, 0xF($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0XF);
    // 0x80192C4C: addiu       $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
    // 0x80192C50: sllv        $t1, $t0, $t9
    ctx->r9 = S32(ctx->r8 << (ctx->r25 & 31));
    // 0x80192C54: and         $t2, $t8, $t1
    ctx->r10 = ctx->r24 & ctx->r9;
    // 0x80192C58: beq         $t2, $zero, L_80192C70
    if (ctx->r10 == 0) {
        // 0x80192C5C: nop
    
            goto L_80192C70;
    }
    // 0x80192C5C: nop

    // 0x80192C60: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x80192C64: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    // 0x80192C68: jal         0x800D2800
    // 0x80192C6C: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    func_800D2800(rdram, ctx);
        goto after_0;
    // 0x80192C6C: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_0:
L_80192C70:
    // 0x80192C70: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x80192C74: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80192C78: lw          $t5, -0x2E3C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2E3C);
    // 0x80192C7C: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80192C80: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x80192C84: sltu        $at, $t4, $t5
    ctx->r1 = ctx->r12 < ctx->r13 ? 1 : 0;
    // 0x80192C88: bne         $at, $zero, L_80192C3C
    if (ctx->r1 != 0) {
        // 0x80192C8C: nop
    
            goto L_80192C3C;
    }
    // 0x80192C8C: nop

L_80192C90:
    // 0x80192C90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80192C94: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80192C98: jr          $ra
    // 0x80192C9C: nop

    return;
    // 0x80192C9C: nop

;}
RECOMP_FUNC void func_80192CA0_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80192CA0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80192CA4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80192CA8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80192CAC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80192CB0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80192CB4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80192CB8: lbu         $t8, -0x2C2F($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X2C2F);
    // 0x80192CBC: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x80192CC0: beq         $t7, $t8, L_80192D04
    if (ctx->r15 == ctx->r24) {
        // 0x80192CC4: nop
    
            goto L_80192D04;
    }
    // 0x80192CC4: nop

    // 0x80192CC8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80192CCC: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x80192CD0: lbu         $t0, 0x0($t6)
    ctx->r8 = MEM_BU(ctx->r14, 0X0);
    // 0x80192CD4: slt         $at, $t8, $t0
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80192CD8: beq         $at, $zero, L_80192CF0
    if (ctx->r1 == 0) {
        // 0x80192CDC: nop
    
            goto L_80192CF0;
    }
    // 0x80192CDC: nop

    // 0x80192CE0: addiu       $t1, $t8, 0x1
    ctx->r9 = ADD32(ctx->r24, 0X1);
    // 0x80192CE4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80192CE8: b           L_80192D04
    // 0x80192CEC: sb          $t1, -0x2C2F($at)
    MEM_B(-0X2C2F, ctx->r1) = ctx->r9;
        goto L_80192D04;
    // 0x80192CEC: sb          $t1, -0x2C2F($at)
    MEM_B(-0X2C2F, ctx->r1) = ctx->r9;
L_80192CF0:
    // 0x80192CF0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80192CF4: lbu         $t2, -0x2C2F($t2)
    ctx->r10 = MEM_BU(ctx->r10, -0X2C2F);
    // 0x80192CF8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80192CFC: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x80192D00: sb          $t3, -0x2C2F($at)
    MEM_B(-0X2C2F, ctx->r1) = ctx->r11;
L_80192D04:
    // 0x80192D04: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80192D08: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80192D0C: lbu         $t7, -0x2C2E($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X2C2E);
    // 0x80192D10: lbu         $t5, 0x1($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X1);
    // 0x80192D14: beq         $t5, $t7, L_80192D5C
    if (ctx->r13 == ctx->r15) {
        // 0x80192D18: nop
    
            goto L_80192D5C;
    }
    // 0x80192D18: nop

    // 0x80192D1C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80192D20: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x80192D24: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x80192D28: lbu         $t0, 0x1($t4)
    ctx->r8 = MEM_BU(ctx->r12, 0X1);
    // 0x80192D2C: slt         $at, $t7, $t0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80192D30: beq         $at, $zero, L_80192D48
    if (ctx->r1 == 0) {
        // 0x80192D34: nop
    
            goto L_80192D48;
    }
    // 0x80192D34: nop

    // 0x80192D38: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80192D3C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80192D40: b           L_80192D5C
    // 0x80192D44: sb          $t8, -0x2C2E($at)
    MEM_B(-0X2C2E, ctx->r1) = ctx->r24;
        goto L_80192D5C;
    // 0x80192D44: sb          $t8, -0x2C2E($at)
    MEM_B(-0X2C2E, ctx->r1) = ctx->r24;
L_80192D48:
    // 0x80192D48: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80192D4C: lbu         $t1, -0x2C2E($t1)
    ctx->r9 = MEM_BU(ctx->r9, -0X2C2E);
    // 0x80192D50: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80192D54: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x80192D58: sb          $t2, -0x2C2E($at)
    MEM_B(-0X2C2E, ctx->r1) = ctx->r10;
L_80192D5C:
    // 0x80192D5C: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80192D60: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80192D64: lbu         $t9, -0x2C2D($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X2C2D);
    // 0x80192D68: lbu         $t5, 0x2($t3)
    ctx->r13 = MEM_BU(ctx->r11, 0X2);
    // 0x80192D6C: beq         $t5, $t9, L_80192DB4
    if (ctx->r13 == ctx->r25) {
        // 0x80192D70: nop
    
            goto L_80192DB4;
    }
    // 0x80192D70: nop

    // 0x80192D74: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80192D78: addiu       $t4, $t6, 0x1
    ctx->r12 = ADD32(ctx->r14, 0X1);
    // 0x80192D7C: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x80192D80: lbu         $t0, 0x2($t3)
    ctx->r8 = MEM_BU(ctx->r11, 0X2);
    // 0x80192D84: slt         $at, $t9, $t0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80192D88: beq         $at, $zero, L_80192DA0
    if (ctx->r1 == 0) {
        // 0x80192D8C: nop
    
            goto L_80192DA0;
    }
    // 0x80192D8C: nop

    // 0x80192D90: addiu       $t7, $t9, 0x1
    ctx->r15 = ADD32(ctx->r25, 0X1);
    // 0x80192D94: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80192D98: b           L_80192DB4
    // 0x80192D9C: sb          $t7, -0x2C2D($at)
    MEM_B(-0X2C2D, ctx->r1) = ctx->r15;
        goto L_80192DB4;
    // 0x80192D9C: sb          $t7, -0x2C2D($at)
    MEM_B(-0X2C2D, ctx->r1) = ctx->r15;
L_80192DA0:
    // 0x80192DA0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80192DA4: lbu         $t8, -0x2C2D($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X2C2D);
    // 0x80192DA8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80192DAC: addiu       $t1, $t8, -0x1
    ctx->r9 = ADD32(ctx->r24, -0X1);
    // 0x80192DB0: sb          $t1, -0x2C2D($at)
    MEM_B(-0X2C2D, ctx->r1) = ctx->r9;
L_80192DB4:
    // 0x80192DB4: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80192DB8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80192DBC: lbu         $t6, -0x2C2C($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X2C2C);
    // 0x80192DC0: lbu         $t5, 0x3($t2)
    ctx->r13 = MEM_BU(ctx->r10, 0X3);
    // 0x80192DC4: beq         $t5, $t6, L_80192E0C
    if (ctx->r13 == ctx->r14) {
        // 0x80192DC8: nop
    
            goto L_80192E0C;
    }
    // 0x80192DC8: nop

    // 0x80192DCC: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80192DD0: addiu       $t3, $t4, 0x1
    ctx->r11 = ADD32(ctx->r12, 0X1);
    // 0x80192DD4: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x80192DD8: lbu         $t0, 0x3($t2)
    ctx->r8 = MEM_BU(ctx->r10, 0X3);
    // 0x80192DDC: slt         $at, $t6, $t0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80192DE0: beq         $at, $zero, L_80192DF8
    if (ctx->r1 == 0) {
        // 0x80192DE4: nop
    
            goto L_80192DF8;
    }
    // 0x80192DE4: nop

    // 0x80192DE8: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x80192DEC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80192DF0: b           L_80192E0C
    // 0x80192DF4: sb          $t9, -0x2C2C($at)
    MEM_B(-0X2C2C, ctx->r1) = ctx->r25;
        goto L_80192E0C;
    // 0x80192DF4: sb          $t9, -0x2C2C($at)
    MEM_B(-0X2C2C, ctx->r1) = ctx->r25;
L_80192DF8:
    // 0x80192DF8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80192DFC: lbu         $t7, -0x2C2C($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X2C2C);
    // 0x80192E00: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80192E04: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80192E08: sb          $t8, -0x2C2C($at)
    MEM_B(-0X2C2C, ctx->r1) = ctx->r24;
L_80192E0C:
    // 0x80192E0C: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80192E10: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80192E14: lbu         $t4, -0x2C2B($t4)
    ctx->r12 = MEM_BU(ctx->r12, -0X2C2B);
    // 0x80192E18: lbu         $t5, 0x4($t1)
    ctx->r13 = MEM_BU(ctx->r9, 0X4);
    // 0x80192E1C: beq         $t5, $t4, L_80192E64
    if (ctx->r13 == ctx->r12) {
        // 0x80192E20: nop
    
            goto L_80192E64;
    }
    // 0x80192E20: nop

    // 0x80192E24: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80192E28: addiu       $t2, $t3, 0x1
    ctx->r10 = ADD32(ctx->r11, 0X1);
    // 0x80192E2C: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x80192E30: lbu         $t0, 0x4($t1)
    ctx->r8 = MEM_BU(ctx->r9, 0X4);
    // 0x80192E34: slt         $at, $t4, $t0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80192E38: beq         $at, $zero, L_80192E50
    if (ctx->r1 == 0) {
        // 0x80192E3C: nop
    
            goto L_80192E50;
    }
    // 0x80192E3C: nop

    // 0x80192E40: addiu       $t6, $t4, 0x1
    ctx->r14 = ADD32(ctx->r12, 0X1);
    // 0x80192E44: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80192E48: b           L_80192E64
    // 0x80192E4C: sb          $t6, -0x2C2B($at)
    MEM_B(-0X2C2B, ctx->r1) = ctx->r14;
        goto L_80192E64;
    // 0x80192E4C: sb          $t6, -0x2C2B($at)
    MEM_B(-0X2C2B, ctx->r1) = ctx->r14;
L_80192E50:
    // 0x80192E50: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80192E54: lbu         $t9, -0x2C2B($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X2C2B);
    // 0x80192E58: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80192E5C: addiu       $t7, $t9, -0x1
    ctx->r15 = ADD32(ctx->r25, -0X1);
    // 0x80192E60: sb          $t7, -0x2C2B($at)
    MEM_B(-0X2C2B, ctx->r1) = ctx->r15;
L_80192E64:
    // 0x80192E64: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80192E68: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80192E6C: lbu         $t3, -0x2C2A($t3)
    ctx->r11 = MEM_BU(ctx->r11, -0X2C2A);
    // 0x80192E70: lbu         $t5, 0x5($t8)
    ctx->r13 = MEM_BU(ctx->r24, 0X5);
    // 0x80192E74: beq         $t5, $t3, L_80192EBC
    if (ctx->r13 == ctx->r11) {
        // 0x80192E78: nop
    
            goto L_80192EBC;
    }
    // 0x80192E78: nop

    // 0x80192E7C: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80192E80: addiu       $t1, $t2, 0x1
    ctx->r9 = ADD32(ctx->r10, 0X1);
    // 0x80192E84: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x80192E88: lbu         $t0, 0x5($t8)
    ctx->r8 = MEM_BU(ctx->r24, 0X5);
    // 0x80192E8C: slt         $at, $t3, $t0
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80192E90: beq         $at, $zero, L_80192EA8
    if (ctx->r1 == 0) {
        // 0x80192E94: nop
    
            goto L_80192EA8;
    }
    // 0x80192E94: nop

    // 0x80192E98: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80192E9C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80192EA0: b           L_80192EBC
    // 0x80192EA4: sb          $t4, -0x2C2A($at)
    MEM_B(-0X2C2A, ctx->r1) = ctx->r12;
        goto L_80192EBC;
    // 0x80192EA4: sb          $t4, -0x2C2A($at)
    MEM_B(-0X2C2A, ctx->r1) = ctx->r12;
L_80192EA8:
    // 0x80192EA8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80192EAC: lbu         $t6, -0x2C2A($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X2C2A);
    // 0x80192EB0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80192EB4: addiu       $t9, $t6, -0x1
    ctx->r25 = ADD32(ctx->r14, -0X1);
    // 0x80192EB8: sb          $t9, -0x2C2A($at)
    MEM_B(-0X2C2A, ctx->r1) = ctx->r25;
L_80192EBC:
    // 0x80192EBC: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80192EC0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80192EC4: lbu         $t2, -0x2C29($t2)
    ctx->r10 = MEM_BU(ctx->r10, -0X2C29);
    // 0x80192EC8: lbu         $t5, 0x6($t7)
    ctx->r13 = MEM_BU(ctx->r15, 0X6);
    // 0x80192ECC: beq         $t5, $t2, L_80192F14
    if (ctx->r13 == ctx->r10) {
        // 0x80192ED0: nop
    
            goto L_80192F14;
    }
    // 0x80192ED0: nop

    // 0x80192ED4: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80192ED8: addiu       $t8, $t1, 0x1
    ctx->r24 = ADD32(ctx->r9, 0X1);
    // 0x80192EDC: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x80192EE0: lbu         $t0, 0x6($t7)
    ctx->r8 = MEM_BU(ctx->r15, 0X6);
    // 0x80192EE4: slt         $at, $t2, $t0
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80192EE8: beq         $at, $zero, L_80192F00
    if (ctx->r1 == 0) {
        // 0x80192EEC: nop
    
            goto L_80192F00;
    }
    // 0x80192EEC: nop

    // 0x80192EF0: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80192EF4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80192EF8: b           L_80192F14
    // 0x80192EFC: sb          $t3, -0x2C29($at)
    MEM_B(-0X2C29, ctx->r1) = ctx->r11;
        goto L_80192F14;
    // 0x80192EFC: sb          $t3, -0x2C29($at)
    MEM_B(-0X2C29, ctx->r1) = ctx->r11;
L_80192F00:
    // 0x80192F00: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80192F04: lbu         $t4, -0x2C29($t4)
    ctx->r12 = MEM_BU(ctx->r12, -0X2C29);
    // 0x80192F08: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80192F0C: addiu       $t6, $t4, -0x1
    ctx->r14 = ADD32(ctx->r12, -0X1);
    // 0x80192F10: sb          $t6, -0x2C29($at)
    MEM_B(-0X2C29, ctx->r1) = ctx->r14;
L_80192F14:
    // 0x80192F14: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80192F18: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80192F1C: lbu         $t1, -0x2C28($t1)
    ctx->r9 = MEM_BU(ctx->r9, -0X2C28);
    // 0x80192F20: lbu         $t5, 0x7($t9)
    ctx->r13 = MEM_BU(ctx->r25, 0X7);
    // 0x80192F24: beq         $t5, $t1, L_80192F6C
    if (ctx->r13 == ctx->r9) {
        // 0x80192F28: nop
    
            goto L_80192F6C;
    }
    // 0x80192F28: nop

    // 0x80192F2C: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80192F30: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x80192F34: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x80192F38: lbu         $t0, 0x7($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X7);
    // 0x80192F3C: slt         $at, $t1, $t0
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80192F40: beq         $at, $zero, L_80192F58
    if (ctx->r1 == 0) {
        // 0x80192F44: nop
    
            goto L_80192F58;
    }
    // 0x80192F44: nop

    // 0x80192F48: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80192F4C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80192F50: b           L_80192F6C
    // 0x80192F54: sb          $t2, -0x2C28($at)
    MEM_B(-0X2C28, ctx->r1) = ctx->r10;
        goto L_80192F6C;
    // 0x80192F54: sb          $t2, -0x2C28($at)
    MEM_B(-0X2C28, ctx->r1) = ctx->r10;
L_80192F58:
    // 0x80192F58: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80192F5C: lbu         $t3, -0x2C28($t3)
    ctx->r11 = MEM_BU(ctx->r11, -0X2C28);
    // 0x80192F60: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80192F64: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x80192F68: sb          $t4, -0x2C28($at)
    MEM_B(-0X2C28, ctx->r1) = ctx->r12;
L_80192F6C:
    // 0x80192F6C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80192F70: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80192F74: lbu         $t8, -0x2C27($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X2C27);
    // 0x80192F78: lbu         $t5, 0x8($t6)
    ctx->r13 = MEM_BU(ctx->r14, 0X8);
    // 0x80192F7C: beq         $t5, $t8, L_80192FC4
    if (ctx->r13 == ctx->r24) {
        // 0x80192F80: nop
    
            goto L_80192FC4;
    }
    // 0x80192F80: nop

    // 0x80192F84: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80192F88: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x80192F8C: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x80192F90: lbu         $t0, 0x8($t6)
    ctx->r8 = MEM_BU(ctx->r14, 0X8);
    // 0x80192F94: slt         $at, $t8, $t0
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80192F98: beq         $at, $zero, L_80192FB0
    if (ctx->r1 == 0) {
        // 0x80192F9C: nop
    
            goto L_80192FB0;
    }
    // 0x80192F9C: nop

    // 0x80192FA0: addiu       $t1, $t8, 0x1
    ctx->r9 = ADD32(ctx->r24, 0X1);
    // 0x80192FA4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80192FA8: b           L_80192FC4
    // 0x80192FAC: sb          $t1, -0x2C27($at)
    MEM_B(-0X2C27, ctx->r1) = ctx->r9;
        goto L_80192FC4;
    // 0x80192FAC: sb          $t1, -0x2C27($at)
    MEM_B(-0X2C27, ctx->r1) = ctx->r9;
L_80192FB0:
    // 0x80192FB0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80192FB4: lbu         $t2, -0x2C27($t2)
    ctx->r10 = MEM_BU(ctx->r10, -0X2C27);
    // 0x80192FB8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80192FBC: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x80192FC0: sb          $t3, -0x2C27($at)
    MEM_B(-0X2C27, ctx->r1) = ctx->r11;
L_80192FC4:
    // 0x80192FC4: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80192FC8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80192FCC: lbu         $t7, -0x2C26($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X2C26);
    // 0x80192FD0: lbu         $t5, 0x9($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X9);
    // 0x80192FD4: beq         $t5, $t7, L_8019301C
    if (ctx->r13 == ctx->r15) {
        // 0x80192FD8: nop
    
            goto L_8019301C;
    }
    // 0x80192FD8: nop

    // 0x80192FDC: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80192FE0: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x80192FE4: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x80192FE8: lbu         $t0, 0x9($t4)
    ctx->r8 = MEM_BU(ctx->r12, 0X9);
    // 0x80192FEC: slt         $at, $t7, $t0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80192FF0: beq         $at, $zero, L_80193008
    if (ctx->r1 == 0) {
        // 0x80192FF4: nop
    
            goto L_80193008;
    }
    // 0x80192FF4: nop

    // 0x80192FF8: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80192FFC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80193000: b           L_8019301C
    // 0x80193004: sb          $t8, -0x2C26($at)
    MEM_B(-0X2C26, ctx->r1) = ctx->r24;
        goto L_8019301C;
    // 0x80193004: sb          $t8, -0x2C26($at)
    MEM_B(-0X2C26, ctx->r1) = ctx->r24;
L_80193008:
    // 0x80193008: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8019300C: lbu         $t1, -0x2C26($t1)
    ctx->r9 = MEM_BU(ctx->r9, -0X2C26);
    // 0x80193010: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80193014: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x80193018: sb          $t2, -0x2C26($at)
    MEM_B(-0X2C26, ctx->r1) = ctx->r10;
L_8019301C:
    // 0x8019301C: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80193020: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80193024: lbu         $t9, -0x2C25($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X2C25);
    // 0x80193028: lbu         $t5, 0xA($t3)
    ctx->r13 = MEM_BU(ctx->r11, 0XA);
    // 0x8019302C: beq         $t5, $t9, L_80193074
    if (ctx->r13 == ctx->r25) {
        // 0x80193030: nop
    
            goto L_80193074;
    }
    // 0x80193030: nop

    // 0x80193034: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80193038: addiu       $t4, $t6, 0x1
    ctx->r12 = ADD32(ctx->r14, 0X1);
    // 0x8019303C: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x80193040: lbu         $t0, 0xA($t3)
    ctx->r8 = MEM_BU(ctx->r11, 0XA);
    // 0x80193044: slt         $at, $t9, $t0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80193048: beq         $at, $zero, L_80193060
    if (ctx->r1 == 0) {
        // 0x8019304C: nop
    
            goto L_80193060;
    }
    // 0x8019304C: nop

    // 0x80193050: addiu       $t7, $t9, 0x1
    ctx->r15 = ADD32(ctx->r25, 0X1);
    // 0x80193054: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80193058: b           L_80193074
    // 0x8019305C: sb          $t7, -0x2C25($at)
    MEM_B(-0X2C25, ctx->r1) = ctx->r15;
        goto L_80193074;
    // 0x8019305C: sb          $t7, -0x2C25($at)
    MEM_B(-0X2C25, ctx->r1) = ctx->r15;
L_80193060:
    // 0x80193060: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80193064: lbu         $t8, -0x2C25($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X2C25);
    // 0x80193068: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8019306C: addiu       $t1, $t8, -0x1
    ctx->r9 = ADD32(ctx->r24, -0X1);
    // 0x80193070: sb          $t1, -0x2C25($at)
    MEM_B(-0X2C25, ctx->r1) = ctx->r9;
L_80193074:
    // 0x80193074: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80193078: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8019307C: lbu         $t6, -0x2C24($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X2C24);
    // 0x80193080: lbu         $t5, 0xB($t2)
    ctx->r13 = MEM_BU(ctx->r10, 0XB);
    // 0x80193084: beq         $t5, $t6, L_801930CC
    if (ctx->r13 == ctx->r14) {
        // 0x80193088: nop
    
            goto L_801930CC;
    }
    // 0x80193088: nop

    // 0x8019308C: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80193090: addiu       $t3, $t4, 0x1
    ctx->r11 = ADD32(ctx->r12, 0X1);
    // 0x80193094: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x80193098: lbu         $t0, 0xB($t2)
    ctx->r8 = MEM_BU(ctx->r10, 0XB);
    // 0x8019309C: slt         $at, $t6, $t0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x801930A0: beq         $at, $zero, L_801930B8
    if (ctx->r1 == 0) {
        // 0x801930A4: nop
    
            goto L_801930B8;
    }
    // 0x801930A4: nop

    // 0x801930A8: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x801930AC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801930B0: b           L_801930CC
    // 0x801930B4: sb          $t9, -0x2C24($at)
    MEM_B(-0X2C24, ctx->r1) = ctx->r25;
        goto L_801930CC;
    // 0x801930B4: sb          $t9, -0x2C24($at)
    MEM_B(-0X2C24, ctx->r1) = ctx->r25;
L_801930B8:
    // 0x801930B8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801930BC: lbu         $t7, -0x2C24($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X2C24);
    // 0x801930C0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801930C4: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x801930C8: sb          $t8, -0x2C24($at)
    MEM_B(-0X2C24, ctx->r1) = ctx->r24;
L_801930CC:
    // 0x801930CC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x801930D0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x801930D4: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x801930D8: lbu         $a2, -0x2C2A($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X2C2A);
    // 0x801930DC: lbu         $a1, -0x2C2B($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X2C2B);
    // 0x801930E0: lbu         $a0, -0x2C2C($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X2C2C);
    // 0x801930E4: jal         0x800C71BC
    // 0x801930E8: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    func_800C71BC(rdram, ctx);
        goto after_0;
    // 0x801930E8: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_0:
    // 0x801930EC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x801930F0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x801930F4: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x801930F8: lbu         $a2, -0x2C27($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X2C27);
    // 0x801930FC: lbu         $a1, -0x2C28($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X2C28);
    // 0x80193100: jal         0x800C6E0C
    // 0x80193104: lbu         $a0, -0x2C29($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X2C29);
    func_800C6E0C(rdram, ctx);
        goto after_1;
    // 0x80193104: lbu         $a0, -0x2C29($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X2C29);
    after_1:
    // 0x80193108: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8019310C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80193110: lb          $t5, -0x2C21($t5)
    ctx->r13 = MEM_B(ctx->r13, -0X2C21);
    // 0x80193114: lb          $t1, -0x2C22($t1)
    ctx->r9 = MEM_B(ctx->r9, -0X2C22);
    // 0x80193118: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8019311C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80193120: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80193124: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80193128: lb          $a3, -0x2C23($a3)
    ctx->r7 = MEM_B(ctx->r7, -0X2C23);
    // 0x8019312C: lbu         $a2, -0x2C24($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X2C24);
    // 0x80193130: lbu         $a1, -0x2C25($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X2C25);
    // 0x80193134: lbu         $a0, -0x2C26($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X2C26);
    // 0x80193138: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8019313C: jal         0x800C6E68
    // 0x80193140: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    func_800C6E68(rdram, ctx);
        goto after_2;
    // 0x80193140: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_2:
    // 0x80193144: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80193148: bne         $t4, $zero, L_80193154
    if (ctx->r12 != 0) {
        // 0x8019314C: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_80193154;
    }
    // 0x8019314C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80193150: sh          $zero, -0x2D84($at)
    MEM_H(-0X2D84, ctx->r1) = 0;
L_80193154:
    // 0x80193154: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80193158: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8019315C: jr          $ra
    // 0x80193160: nop

    return;
    // 0x80193160: nop

;}
RECOMP_FUNC void func_80193164_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80193164: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80193168: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8019316C: lhu         $t6, 0x26($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X26);
    // 0x80193170: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80193174: lb          $t7, 0x2B($sp)
    ctx->r15 = MEM_B(ctx->r29, 0X2B);
    // 0x80193178: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8019317C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80193180: sh          $t6, -0x2C20($at)
    MEM_H(-0X2C20, ctx->r1) = ctx->r14;
    // 0x80193184: lb          $t8, 0x2F($sp)
    ctx->r24 = MEM_B(ctx->r29, 0X2F);
    // 0x80193188: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8019318C: sb          $t7, -0x2C23($at)
    MEM_B(-0X2C23, ctx->r1) = ctx->r15;
    // 0x80193190: lb          $t9, 0x33($sp)
    ctx->r25 = MEM_B(ctx->r29, 0X33);
    // 0x80193194: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80193198: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8019319C: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x801931A0: sb          $t8, -0x2C22($at)
    MEM_B(-0X2C22, ctx->r1) = ctx->r24;
    // 0x801931A4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801931A8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801931AC: sb          $t9, -0x2C21($at)
    MEM_B(-0X2C21, ctx->r1) = ctx->r25;
    // 0x801931B0: lbu         $t1, 0x0($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X0);
    // 0x801931B4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801931B8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x801931BC: sb          $t1, -0x2C2F($at)
    MEM_B(-0X2C2F, ctx->r1) = ctx->r9;
    // 0x801931C0: lbu         $t2, 0x1($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X1);
    // 0x801931C4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801931C8: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x801931CC: sb          $t2, -0x2C2E($at)
    MEM_B(-0X2C2E, ctx->r1) = ctx->r10;
    // 0x801931D0: lbu         $t3, 0x2($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X2);
    // 0x801931D4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801931D8: sb          $t3, -0x2C2D($at)
    MEM_B(-0X2C2D, ctx->r1) = ctx->r11;
    // 0x801931DC: lbu         $t4, 0x3($t0)
    ctx->r12 = MEM_BU(ctx->r8, 0X3);
    // 0x801931E0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801931E4: sb          $t4, -0x2C2C($at)
    MEM_B(-0X2C2C, ctx->r1) = ctx->r12;
    // 0x801931E8: lbu         $t5, 0x4($t0)
    ctx->r13 = MEM_BU(ctx->r8, 0X4);
    // 0x801931EC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801931F0: sb          $t5, -0x2C2B($at)
    MEM_B(-0X2C2B, ctx->r1) = ctx->r13;
    // 0x801931F4: lbu         $t7, 0x5($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X5);
    // 0x801931F8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801931FC: sb          $t7, -0x2C2A($at)
    MEM_B(-0X2C2A, ctx->r1) = ctx->r15;
    // 0x80193200: lbu         $t8, 0x6($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0X6);
    // 0x80193204: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80193208: sb          $t8, -0x2C29($at)
    MEM_B(-0X2C29, ctx->r1) = ctx->r24;
    // 0x8019320C: lbu         $t9, 0x7($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X7);
    // 0x80193210: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80193214: sb          $t9, -0x2C28($at)
    MEM_B(-0X2C28, ctx->r1) = ctx->r25;
    // 0x80193218: lbu         $t1, 0x8($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X8);
    // 0x8019321C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80193220: sb          $t1, -0x2C27($at)
    MEM_B(-0X2C27, ctx->r1) = ctx->r9;
    // 0x80193224: lbu         $t2, 0x9($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X9);
    // 0x80193228: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8019322C: sb          $t2, -0x2C26($at)
    MEM_B(-0X2C26, ctx->r1) = ctx->r10;
    // 0x80193230: lbu         $t3, 0xA($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0XA);
    // 0x80193234: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80193238: sb          $t3, -0x2C25($at)
    MEM_B(-0X2C25, ctx->r1) = ctx->r11;
    // 0x8019323C: lbu         $t4, 0xB($t0)
    ctx->r12 = MEM_BU(ctx->r8, 0XB);
    // 0x80193240: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80193244: sb          $t4, -0x2C24($at)
    MEM_B(-0X2C24, ctx->r1) = ctx->r12;
    // 0x80193248: jal         0x800C7200
    // 0x8019324C: lhu         $a0, -0x2C1E($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X2C1E);
    func_800C7200(rdram, ctx);
        goto after_0;
    // 0x8019324C: lhu         $a0, -0x2C1E($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X2C1E);
    after_0:
    // 0x80193250: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80193254: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80193258: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8019325C: lbu         $a2, -0x2C2A($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X2C2A);
    // 0x80193260: lbu         $a1, -0x2C2B($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X2C2B);
    // 0x80193264: lbu         $a0, -0x2C2C($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X2C2C);
    // 0x80193268: jal         0x800C71BC
    // 0x8019326C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    func_800C71BC(rdram, ctx);
        goto after_1;
    // 0x8019326C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_1:
    // 0x80193270: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80193274: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80193278: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8019327C: lbu         $a2, -0x2C27($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X2C27);
    // 0x80193280: lbu         $a1, -0x2C28($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X2C28);
    // 0x80193284: jal         0x800C6E0C
    // 0x80193288: lbu         $a0, -0x2C29($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X2C29);
    func_800C6E0C(rdram, ctx);
        goto after_2;
    // 0x80193288: lbu         $a0, -0x2C29($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X2C29);
    after_2:
    // 0x8019328C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80193290: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80193294: lb          $t7, -0x2C21($t7)
    ctx->r15 = MEM_B(ctx->r15, -0X2C21);
    // 0x80193298: lb          $t5, -0x2C22($t5)
    ctx->r13 = MEM_B(ctx->r13, -0X2C22);
    // 0x8019329C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x801932A0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x801932A4: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x801932A8: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x801932AC: lb          $a3, -0x2C23($a3)
    ctx->r7 = MEM_B(ctx->r7, -0X2C23);
    // 0x801932B0: lbu         $a2, -0x2C24($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X2C24);
    // 0x801932B4: lbu         $a1, -0x2C25($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X2C25);
    // 0x801932B8: lbu         $a0, -0x2C26($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X2C26);
    // 0x801932BC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801932C0: jal         0x800C6E68
    // 0x801932C4: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    func_800C6E68(rdram, ctx);
        goto after_3;
    // 0x801932C4: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_3:
    // 0x801932C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801932CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801932D0: jr          $ra
    // 0x801932D4: nop

    return;
    // 0x801932D4: nop

;}
RECOMP_FUNC void func_801932D8_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801932D8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801932DC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801932E0: lhu         $t6, 0x22($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X22);
    // 0x801932E4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801932E8: lb          $t7, 0x27($sp)
    ctx->r15 = MEM_B(ctx->r29, 0X27);
    // 0x801932EC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801932F0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x801932F4: sh          $t6, -0x2C20($at)
    MEM_H(-0X2C20, ctx->r1) = ctx->r14;
    // 0x801932F8: lb          $t8, 0x2B($sp)
    ctx->r24 = MEM_B(ctx->r29, 0X2B);
    // 0x801932FC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80193300: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80193304: sb          $t7, -0x2C23($at)
    MEM_B(-0X2C23, ctx->r1) = ctx->r15;
    // 0x80193308: lb          $t9, 0x2F($sp)
    ctx->r25 = MEM_B(ctx->r29, 0X2F);
    // 0x8019330C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80193310: sb          $t8, -0x2C22($at)
    MEM_B(-0X2C22, ctx->r1) = ctx->r24;
    // 0x80193314: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80193318: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8019331C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80193320: sb          $t9, -0x2C21($at)
    MEM_B(-0X2C21, ctx->r1) = ctx->r25;
    // 0x80193324: lhu         $a0, -0x2C1E($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X2C1E);
    // 0x80193328: jal         0x800C7200
    // 0x8019332C: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    func_800C7200(rdram, ctx);
        goto after_0;
    // 0x8019332C: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    after_0:
    // 0x80193330: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80193334: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80193338: lb          $t1, -0x2C21($t1)
    ctx->r9 = MEM_B(ctx->r9, -0X2C21);
    // 0x8019333C: lb          $t0, -0x2C22($t0)
    ctx->r8 = MEM_B(ctx->r8, -0X2C22);
    // 0x80193340: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80193344: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80193348: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8019334C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80193350: lb          $a3, -0x2C23($a3)
    ctx->r7 = MEM_B(ctx->r7, -0X2C23);
    // 0x80193354: lbu         $a2, -0x2C24($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X2C24);
    // 0x80193358: lbu         $a1, -0x2C25($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X2C25);
    // 0x8019335C: lbu         $a0, -0x2C26($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X2C26);
    // 0x80193360: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80193364: jal         0x800C6E68
    // 0x80193368: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    func_800C6E68(rdram, ctx);
        goto after_1;
    // 0x80193368: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_1:
    // 0x8019336C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80193370: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80193374: jr          $ra
    // 0x80193378: nop

    return;
    // 0x80193378: nop

;}
RECOMP_FUNC void func_8019337C_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019337C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80193380: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80193384: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80193388: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8019338C: jal         0x80192A64
    // 0x80193390: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80192A64_1501A0(rdram, ctx);
        goto after_0;
    // 0x80193390: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_0:
    // 0x80193394: beq         $v0, $zero, L_801933B4
    if (ctx->r2 == 0) {
        // 0x80193398: nop
    
            goto L_801933B4;
    }
    // 0x80193398: nop

    // 0x8019339C: jal         0x80192AE0
    // 0x801933A0: nop

    func_80192AE0_1501A0(rdram, ctx);
        goto after_1;
    // 0x801933A0: nop

    after_1:
    // 0x801933A4: bne         $v0, $zero, L_801933B4
    if (ctx->r2 != 0) {
        // 0x801933A8: nop
    
            goto L_801933B4;
    }
    // 0x801933A8: nop

    // 0x801933AC: jal         0x80192B9C
    // 0x801933B0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_80192B9C_1501A0(rdram, ctx);
        goto after_2;
    // 0x801933B0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_2:
L_801933B4:
    // 0x801933B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801933B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801933BC: jr          $ra
    // 0x801933C0: nop

    return;
    // 0x801933C0: nop

;}
RECOMP_FUNC void func_801933C4_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801933C4: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x801933C8: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_801933CC:
    // 0x801933CC: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x801933D0: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x801933D4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801933D8: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x801933DC: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x801933E0: sw          $zero, 0x39B4($at)
    MEM_W(0X39B4, ctx->r1) = 0;
    // 0x801933E4: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x801933E8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801933EC: sll         $t9, $t8, 5
    ctx->r25 = S32(ctx->r24 << 5);
    // 0x801933F0: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x801933F4: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x801933F8: sw          $zero, 0x39B8($at)
    MEM_W(0X39B8, ctx->r1) = 0;
    // 0x801933FC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80193400: sll         $t1, $t0, 5
    ctx->r9 = S32(ctx->r8 << 5);
    // 0x80193404: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80193408: sw          $zero, 0x39BC($at)
    MEM_W(0X39BC, ctx->r1) = 0;
    // 0x8019340C: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80193410: sltiu       $at, $t3, 0x4
    ctx->r1 = ctx->r11 < 0X4 ? 1 : 0;
    // 0x80193414: bne         $at, $zero, L_801933CC
    if (ctx->r1 != 0) {
        // 0x80193418: sw          $t3, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r11;
            goto L_801933CC;
    }
    // 0x80193418: sw          $t3, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r11;
    // 0x8019341C: jr          $ra
    // 0x80193420: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80193420: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_80193424_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80193424: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80193428: lw          $t6, -0x2E48($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2E48);
    // 0x8019342C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80193430: beq         $t6, $at, L_8019347C
    if (ctx->r14 == ctx->r1) {
        // 0x80193434: nop
    
            goto L_8019347C;
    }
    // 0x80193434: nop

    // 0x80193438: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8019343C: addiu       $t7, $t7, 0x3988
    ctx->r15 = ADD32(ctx->r15, 0X3988);
    // 0x80193440: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80193444: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80193448: addiu       $t0, $t0, 0x3988
    ctx->r8 = ADD32(ctx->r8, 0X3988);
    // 0x8019344C: addu        $t9, $t8, $a1
    ctx->r25 = ADD32(ctx->r24, ctx->r5);
    // 0x80193450: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x80193454: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80193458: lui         $at, 0x98
    ctx->r1 = S32(0X98 << 16);
    // 0x8019345C: ori         $at, $at, 0x9680
    ctx->r1 = ctx->r1 | 0X9680;
    // 0x80193460: sltu        $at, $t1, $at
    ctx->r1 = ctx->r9 < ctx->r1 ? 1 : 0;
    // 0x80193464: bne         $at, $zero, L_80193510
    if (ctx->r1 != 0) {
        // 0x80193468: nop
    
            goto L_80193510;
    }
    // 0x80193468: nop

    // 0x8019346C: lui         $t2, 0x98
    ctx->r10 = S32(0X98 << 16);
    // 0x80193470: ori         $t2, $t2, 0x967F
    ctx->r10 = ctx->r10 | 0X967F;
    // 0x80193474: jr          $ra
    // 0x80193478: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    return;
    // 0x80193478: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
L_8019347C:
    // 0x8019347C: beq         $a0, $zero, L_8019348C
    if (ctx->r4 == 0) {
        // 0x80193480: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8019348C;
    }
    // 0x80193480: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80193484: bne         $a0, $at, L_801934D0
    if (ctx->r4 != ctx->r1) {
        // 0x80193488: nop
    
            goto L_801934D0;
    }
    // 0x80193488: nop

L_8019348C:
    // 0x8019348C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80193490: addiu       $t3, $t3, 0x3988
    ctx->r11 = ADD32(ctx->r11, 0X3988);
    // 0x80193494: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80193498: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8019349C: addiu       $t6, $t6, 0x3988
    ctx->r14 = ADD32(ctx->r14, 0X3988);
    // 0x801934A0: addu        $t5, $t4, $a1
    ctx->r13 = ADD32(ctx->r12, ctx->r5);
    // 0x801934A4: sw          $t5, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r13;
    // 0x801934A8: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x801934AC: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x801934B0: ori         $at, $at, 0x86A0
    ctx->r1 = ctx->r1 | 0X86A0;
    // 0x801934B4: sltu        $at, $t8, $at
    ctx->r1 = ctx->r24 < ctx->r1 ? 1 : 0;
    // 0x801934B8: bne         $at, $zero, L_80193510
    if (ctx->r1 != 0) {
        // 0x801934BC: nop
    
            goto L_80193510;
    }
    // 0x801934BC: nop

    // 0x801934C0: lui         $t9, 0x1
    ctx->r25 = S32(0X1 << 16);
    // 0x801934C4: ori         $t9, $t9, 0x869F
    ctx->r25 = ctx->r25 | 0X869F;
    // 0x801934C8: jr          $ra
    // 0x801934CC: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    return;
    // 0x801934CC: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
L_801934D0:
    // 0x801934D0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801934D4: addiu       $t7, $t7, 0x3988
    ctx->r15 = ADD32(ctx->r15, 0X3988);
    // 0x801934D8: lw          $t1, 0xC($t7)
    ctx->r9 = MEM_W(ctx->r15, 0XC);
    // 0x801934DC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x801934E0: addiu       $t0, $t0, 0x3988
    ctx->r8 = ADD32(ctx->r8, 0X3988);
    // 0x801934E4: addu        $t2, $t1, $a1
    ctx->r10 = ADD32(ctx->r9, ctx->r5);
    // 0x801934E8: sw          $t2, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->r10;
    // 0x801934EC: lw          $t4, 0xC($t0)
    ctx->r12 = MEM_W(ctx->r8, 0XC);
    // 0x801934F0: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x801934F4: ori         $at, $at, 0x86A0
    ctx->r1 = ctx->r1 | 0X86A0;
    // 0x801934F8: sltu        $at, $t4, $at
    ctx->r1 = ctx->r12 < ctx->r1 ? 1 : 0;
    // 0x801934FC: bne         $at, $zero, L_80193510
    if (ctx->r1 != 0) {
        // 0x80193500: nop
    
            goto L_80193510;
    }
    // 0x80193500: nop

    // 0x80193504: lui         $t5, 0x1
    ctx->r13 = S32(0X1 << 16);
    // 0x80193508: ori         $t5, $t5, 0x869F
    ctx->r13 = ctx->r13 | 0X869F;
    // 0x8019350C: sw          $t5, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r13;
L_80193510:
    // 0x80193510: jr          $ra
    // 0x80193514: nop

    return;
    // 0x80193514: nop

;}
RECOMP_FUNC void func_80193518_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80193518: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8019351C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80193520: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80193524: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80193528: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8019352C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80193530: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80193534: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80193538: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8019353C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80193540: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80193544: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80193548: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8019354C: lw          $t8, -0x2A24($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2A24);
    // 0x80193550: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80193554: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80193558: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8019355C: sltiu       $at, $t9, 0xF
    ctx->r1 = ctx->r25 < 0XF ? 1 : 0;
    // 0x80193560: beq         $at, $zero, L_80193590
    if (ctx->r1 == 0) {
        // 0x80193564: nop
    
            goto L_80193590;
    }
    // 0x80193564: nop

    // 0x80193568: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8019356C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80193570: addu        $at, $at, $t9
    gpr jr_addend_80193578 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80193574: lw          $t9, 0x7B8($at)
    ctx->r25 = ADD32(ctx->r1, 0X7B8);
    // 0x80193578: jr          $t9
    // 0x8019357C: nop

    switch (jr_addend_80193578 >> 2) {
        case 0: goto L_8019385C; break;
        case 1: goto L_8019385C; break;
        case 2: goto L_80193590; break;
        case 3: goto L_8019385C; break;
        case 4: goto L_8019385C; break;
        case 5: goto L_8019385C; break;
        case 6: goto L_8019385C; break;
        case 7: goto L_8019385C; break;
        case 8: goto L_80193590; break;
        case 9: goto L_8019385C; break;
        case 10: goto L_80193580; break;
        case 11: goto L_80193580; break;
        case 12: goto L_80193580; break;
        case 13: goto L_80193580; break;
        case 14: goto L_80193580; break;
        default: switch_error(__func__, 0x80193578, 0x801A07B8);
    }
    // 0x8019357C: nop

L_80193580:
    // 0x80193580: jal         0x800C8544
    // 0x80193584: addiu       $a0, $zero, 0x6F
    ctx->r4 = ADD32(0, 0X6F);
    func_800C8544(rdram, ctx);
        goto after_0;
    // 0x80193584: addiu       $a0, $zero, 0x6F
    ctx->r4 = ADD32(0, 0X6F);
    after_0:
    // 0x80193588: b           L_8019385C
    // 0x8019358C: nop

        goto L_8019385C;
    // 0x8019358C: nop

L_80193590:
    // 0x80193590: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80193594: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80193598: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8019359C: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x801935A0: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x801935A4: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x801935A8: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x801935AC: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x801935B0: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x801935B4: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x801935B8: lw          $t3, -0x2E44($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2E44);
    // 0x801935BC: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x801935C0: lw          $t2, -0x2A24($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2A24);
    // 0x801935C4: lui         $at, 0x5
    ctx->r1 = S32(0X5 << 16);
    // 0x801935C8: sll         $t4, $t3, 16
    ctx->r12 = S32(ctx->r11 << 16);
    // 0x801935CC: ori         $at, $at, 0x16
    ctx->r1 = ctx->r1 | 0X16;
    // 0x801935D0: or          $s0, $t2, $t4
    ctx->r16 = ctx->r10 | ctx->r12;
    // 0x801935D4: sltu        $at, $s0, $at
    ctx->r1 = ctx->r16 < ctx->r1 ? 1 : 0;
    // 0x801935D8: bne         $at, $zero, L_80193674
    if (ctx->r1 != 0) {
        // 0x801935DC: lui         $at, 0x5
        ctx->r1 = S32(0X5 << 16);
            goto L_80193674;
    }
    // 0x801935DC: lui         $at, 0x5
    ctx->r1 = S32(0X5 << 16);
    // 0x801935E0: ori         $at, $at, 0x19
    ctx->r1 = ctx->r1 | 0X19;
    // 0x801935E4: sltu        $at, $s0, $at
    ctx->r1 = ctx->r16 < ctx->r1 ? 1 : 0;
    // 0x801935E8: bne         $at, $zero, L_80193644
    if (ctx->r1 != 0) {
        // 0x801935EC: lui         $at, 0x6
        ctx->r1 = S32(0X6 << 16);
            goto L_80193644;
    }
    // 0x801935EC: lui         $at, 0x6
    ctx->r1 = S32(0X6 << 16);
    // 0x801935F0: ori         $at, $at, 0x27
    ctx->r1 = ctx->r1 | 0X27;
    // 0x801935F4: sltu        $at, $s0, $at
    ctx->r1 = ctx->r16 < ctx->r1 ? 1 : 0;
    // 0x801935F8: bne         $at, $zero, L_80193614
    if (ctx->r1 != 0) {
        // 0x801935FC: lui         $at, 0x6
        ctx->r1 = S32(0X6 << 16);
            goto L_80193614;
    }
    // 0x801935FC: lui         $at, 0x6
    ctx->r1 = S32(0X6 << 16);
    // 0x80193600: ori         $at, $at, 0x4D
    ctx->r1 = ctx->r1 | 0X4D;
    // 0x80193604: beq         $s0, $at, L_8019385C
    if (ctx->r16 == ctx->r1) {
        // 0x80193608: nop
    
            goto L_8019385C;
    }
    // 0x80193608: nop

    // 0x8019360C: b           L_801937BC
    // 0x80193610: nop

        goto L_801937BC;
    // 0x80193610: nop

L_80193614:
    // 0x80193614: lui         $at, 0xFFF9
    ctx->r1 = S32(0XFFF9 << 16);
    // 0x80193618: ori         $at, $at, 0xFFED
    ctx->r1 = ctx->r1 | 0XFFED;
    // 0x8019361C: addu        $t5, $s0, $at
    ctx->r13 = ADD32(ctx->r16, ctx->r1);
    // 0x80193620: sltiu       $at, $t5, 0x14
    ctx->r1 = ctx->r13 < 0X14 ? 1 : 0;
    // 0x80193624: beq         $at, $zero, L_801937BC
    if (ctx->r1 == 0) {
        // 0x80193628: nop
    
            goto L_801937BC;
    }
    // 0x80193628: nop

    // 0x8019362C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80193630: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80193634: addu        $at, $at, $t5
    gpr jr_addend_8019363C = ctx->r13;
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x80193638: lw          $t5, 0x7F4($at)
    ctx->r13 = ADD32(ctx->r1, 0X7F4);
    // 0x8019363C: jr          $t5
    // 0x80193640: nop

    switch (jr_addend_8019363C >> 2) {
        case 0: goto L_8019385C; break;
        case 1: goto L_801937BC; break;
        case 2: goto L_801937BC; break;
        case 3: goto L_801937BC; break;
        case 4: goto L_801937BC; break;
        case 5: goto L_801937BC; break;
        case 6: goto L_801937BC; break;
        case 7: goto L_801937BC; break;
        case 8: goto L_801937BC; break;
        case 9: goto L_801937BC; break;
        case 10: goto L_801937BC; break;
        case 11: goto L_801937BC; break;
        case 12: goto L_8019385C; break;
        case 13: goto L_8019385C; break;
        case 14: goto L_8019385C; break;
        case 15: goto L_8019385C; break;
        case 16: goto L_8019385C; break;
        case 17: goto L_8019385C; break;
        case 18: goto L_8019385C; break;
        case 19: goto L_8019385C; break;
        default: switch_error(__func__, 0x8019363C, 0x801A07F4);
    }
    // 0x80193640: nop

L_80193644:
    // 0x80193644: lui         $at, 0x5
    ctx->r1 = S32(0X5 << 16);
    // 0x80193648: ori         $at, $at, 0x16
    ctx->r1 = ctx->r1 | 0X16;
    // 0x8019364C: beq         $s0, $at, L_80193758
    if (ctx->r16 == ctx->r1) {
        // 0x80193650: lui         $at, 0x5
        ctx->r1 = S32(0X5 << 16);
            goto L_80193758;
    }
    // 0x80193650: lui         $at, 0x5
    ctx->r1 = S32(0X5 << 16);
    // 0x80193654: ori         $at, $at, 0x17
    ctx->r1 = ctx->r1 | 0X17;
    // 0x80193658: beq         $s0, $at, L_8019377C
    if (ctx->r16 == ctx->r1) {
        // 0x8019365C: lui         $at, 0x5
        ctx->r1 = S32(0X5 << 16);
            goto L_8019377C;
    }
    // 0x8019365C: lui         $at, 0x5
    ctx->r1 = S32(0X5 << 16);
    // 0x80193660: ori         $at, $at, 0x18
    ctx->r1 = ctx->r1 | 0X18;
    // 0x80193664: beq         $s0, $at, L_801937A0
    if (ctx->r16 == ctx->r1) {
        // 0x80193668: nop
    
            goto L_801937A0;
    }
    // 0x80193668: nop

    // 0x8019366C: b           L_801937BC
    // 0x80193670: nop

        goto L_801937BC;
    // 0x80193670: nop

L_80193674:
    // 0x80193674: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x80193678: ori         $at, $at, 0x36
    ctx->r1 = ctx->r1 | 0X36;
    // 0x8019367C: sltu        $at, $s0, $at
    ctx->r1 = ctx->r16 < ctx->r1 ? 1 : 0;
    // 0x80193680: bne         $at, $zero, L_801936B4
    if (ctx->r1 != 0) {
        // 0x80193684: lui         $at, 0x2
        ctx->r1 = S32(0X2 << 16);
            goto L_801936B4;
    }
    // 0x80193684: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x80193688: ori         $at, $at, 0x48
    ctx->r1 = ctx->r1 | 0X48;
    // 0x8019368C: beq         $s0, $at, L_8019385C
    if (ctx->r16 == ctx->r1) {
        // 0x80193690: lui         $at, 0x3
        ctx->r1 = S32(0X3 << 16);
            goto L_8019385C;
    }
    // 0x80193690: lui         $at, 0x3
    ctx->r1 = S32(0X3 << 16);
    // 0x80193694: ori         $at, $at, 0x2B
    ctx->r1 = ctx->r1 | 0X2B;
    // 0x80193698: beq         $s0, $at, L_8019385C
    if (ctx->r16 == ctx->r1) {
        // 0x8019369C: lui         $at, 0x5
        ctx->r1 = S32(0X5 << 16);
            goto L_8019385C;
    }
    // 0x8019369C: lui         $at, 0x5
    ctx->r1 = S32(0X5 << 16);
    // 0x801936A0: ori         $at, $at, 0x15
    ctx->r1 = ctx->r1 | 0X15;
    // 0x801936A4: beq         $s0, $at, L_80193734
    if (ctx->r16 == ctx->r1) {
        // 0x801936A8: nop
    
            goto L_80193734;
    }
    // 0x801936A8: nop

    // 0x801936AC: b           L_801937BC
    // 0x801936B0: nop

        goto L_801937BC;
    // 0x801936B0: nop

L_801936B4:
    // 0x801936B4: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x801936B8: ori         $at, $at, 0x35
    ctx->r1 = ctx->r1 | 0X35;
    // 0x801936BC: sltu        $at, $s0, $at
    ctx->r1 = ctx->r16 < ctx->r1 ? 1 : 0;
    // 0x801936C0: bne         $at, $zero, L_801936DC
    if (ctx->r1 != 0) {
        // 0x801936C4: lui         $at, 0x2
        ctx->r1 = S32(0X2 << 16);
            goto L_801936DC;
    }
    // 0x801936C4: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x801936C8: ori         $at, $at, 0x35
    ctx->r1 = ctx->r1 | 0X35;
    // 0x801936CC: beq         $s0, $at, L_8019385C
    if (ctx->r16 == ctx->r1) {
        // 0x801936D0: nop
    
            goto L_8019385C;
    }
    // 0x801936D0: nop

    // 0x801936D4: b           L_801937BC
    // 0x801936D8: nop

        goto L_801937BC;
    // 0x801936D8: nop

L_801936DC:
    // 0x801936DC: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x801936E0: ori         $at, $at, 0x39
    ctx->r1 = ctx->r1 | 0X39;
    // 0x801936E4: sltu        $at, $s0, $at
    ctx->r1 = ctx->r16 < ctx->r1 ? 1 : 0;
    // 0x801936E8: bne         $at, $zero, L_80193704
    if (ctx->r1 != 0) {
        // 0x801936EC: lui         $at, 0x2
        ctx->r1 = S32(0X2 << 16);
            goto L_80193704;
    }
    // 0x801936EC: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x801936F0: ori         $at, $at, 0x34
    ctx->r1 = ctx->r1 | 0X34;
    // 0x801936F4: beq         $s0, $at, L_8019385C
    if (ctx->r16 == ctx->r1) {
        // 0x801936F8: nop
    
            goto L_8019385C;
    }
    // 0x801936F8: nop

    // 0x801936FC: b           L_801937BC
    // 0x80193700: nop

        goto L_801937BC;
    // 0x80193700: nop

L_80193704:
    // 0x80193704: lui         $at, 0xFFFE
    ctx->r1 = S32(0XFFFE << 16);
    // 0x80193708: ori         $at, $at, 0xFFCD
    ctx->r1 = ctx->r1 | 0XFFCD;
    // 0x8019370C: addu        $t6, $s0, $at
    ctx->r14 = ADD32(ctx->r16, ctx->r1);
    // 0x80193710: sltiu       $at, $t6, 0x6
    ctx->r1 = ctx->r14 < 0X6 ? 1 : 0;
    // 0x80193714: beq         $at, $zero, L_801937BC
    if (ctx->r1 == 0) {
        // 0x80193718: nop
    
            goto L_801937BC;
    }
    // 0x80193718: nop

    // 0x8019371C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80193720: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80193724: addu        $at, $at, $t6
    gpr jr_addend_8019372C = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80193728: lw          $t6, 0x844($at)
    ctx->r14 = ADD32(ctx->r1, 0X844);
    // 0x8019372C: jr          $t6
    // 0x80193730: nop

    switch (jr_addend_8019372C >> 2) {
        case 0: goto L_8019385C; break;
        case 1: goto L_8019385C; break;
        case 2: goto L_801937BC; break;
        case 3: goto L_8019385C; break;
        case 4: goto L_8019385C; break;
        case 5: goto L_8019385C; break;
        default: switch_error(__func__, 0x8019372C, 0x801A0844);
    }
    // 0x80193730: nop

L_80193734:
    // 0x80193734: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80193738: addiu       $t7, $t7, -0x2E28
    ctx->r15 = ADD32(ctx->r15, -0X2E28);
    // 0x8019373C: lbu         $t8, 0x5($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X5);
    // 0x80193740: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x80193744: andi        $t9, $t8, 0xE
    ctx->r25 = ctx->r24 & 0XE;
    // 0x80193748: bne         $t9, $at, L_8019385C
    if (ctx->r25 != ctx->r1) {
        // 0x8019374C: nop
    
            goto L_8019385C;
    }
    // 0x8019374C: nop

    // 0x80193750: b           L_801937BC
    // 0x80193754: nop

        goto L_801937BC;
    // 0x80193754: nop

L_80193758:
    // 0x80193758: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8019375C: addiu       $t0, $t0, -0x2E28
    ctx->r8 = ADD32(ctx->r8, -0X2E28);
    // 0x80193760: lbu         $t1, 0x5($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X5);
    // 0x80193764: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x80193768: andi        $t3, $t1, 0xD
    ctx->r11 = ctx->r9 & 0XD;
    // 0x8019376C: bne         $t3, $at, L_8019385C
    if (ctx->r11 != ctx->r1) {
        // 0x80193770: nop
    
            goto L_8019385C;
    }
    // 0x80193770: nop

    // 0x80193774: b           L_801937BC
    // 0x80193778: nop

        goto L_801937BC;
    // 0x80193778: nop

L_8019377C:
    // 0x8019377C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80193780: addiu       $t2, $t2, -0x2E28
    ctx->r10 = ADD32(ctx->r10, -0X2E28);
    // 0x80193784: lbu         $t4, 0x5($t2)
    ctx->r12 = MEM_BU(ctx->r10, 0X5);
    // 0x80193788: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8019378C: andi        $t5, $t4, 0xB
    ctx->r13 = ctx->r12 & 0XB;
    // 0x80193790: bne         $t5, $at, L_8019385C
    if (ctx->r13 != ctx->r1) {
        // 0x80193794: nop
    
            goto L_8019385C;
    }
    // 0x80193794: nop

    // 0x80193798: b           L_801937BC
    // 0x8019379C: nop

        goto L_801937BC;
    // 0x8019379C: nop

L_801937A0:
    // 0x801937A0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801937A4: addiu       $t6, $t6, -0x2E28
    ctx->r14 = ADD32(ctx->r14, -0X2E28);
    // 0x801937A8: lbu         $t7, 0x5($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X5);
    // 0x801937AC: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x801937B0: andi        $t8, $t7, 0x7
    ctx->r24 = ctx->r15 & 0X7;
    // 0x801937B4: bne         $t8, $at, L_8019385C
    if (ctx->r24 != ctx->r1) {
        // 0x801937B8: nop
    
            goto L_8019385C;
    }
    // 0x801937B8: nop

L_801937BC:
    // 0x801937BC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801937C0: lw          $t9, -0x2E44($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2E44);
    // 0x801937C4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x801937C8: bne         $t9, $at, L_80193808
    if (ctx->r25 != ctx->r1) {
        // 0x801937CC: nop
    
            goto L_80193808;
    }
    // 0x801937CC: nop

    // 0x801937D0: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x801937D4: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x801937D8: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x801937DC: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x801937E0: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x801937E4: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x801937E8: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x801937EC: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x801937F0: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x801937F4: addu        $t3, $t3, $t1
    ctx->r11 = ADD32(ctx->r11, ctx->r9);
    // 0x801937F8: lw          $t3, -0x2A24($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2A24);
    // 0x801937FC: sltiu       $at, $t3, 0x7C
    ctx->r1 = ctx->r11 < 0X7C ? 1 : 0;
    // 0x80193800: beq         $at, $zero, L_8019385C
    if (ctx->r1 == 0) {
        // 0x80193804: nop
    
            goto L_8019385C;
    }
    // 0x80193804: nop

L_80193808:
    // 0x80193808: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8019380C: lw          $t2, -0x2E44($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2E44);
    // 0x80193810: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80193814: bne         $t2, $at, L_80193854
    if (ctx->r10 != ctx->r1) {
        // 0x80193818: nop
    
            goto L_80193854;
    }
    // 0x80193818: nop

    // 0x8019381C: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80193820: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80193824: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80193828: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8019382C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80193830: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x80193834: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80193838: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8019383C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80193840: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80193844: lw          $t6, -0x2A24($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2A24);
    // 0x80193848: sltiu       $at, $t6, 0x80
    ctx->r1 = ctx->r14 < 0X80 ? 1 : 0;
    // 0x8019384C: beq         $at, $zero, L_8019385C
    if (ctx->r1 == 0) {
        // 0x80193850: nop
    
            goto L_8019385C;
    }
    // 0x80193850: nop

L_80193854:
    // 0x80193854: jal         0x80193870
    // 0x80193858: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80193870_1501A0(rdram, ctx);
        goto after_1;
    // 0x80193858: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
L_8019385C:
    // 0x8019385C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80193860: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80193864: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80193868: jr          $ra
    // 0x8019386C: nop

    return;
    // 0x8019386C: nop

;}
RECOMP_FUNC void func_80193870_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80193870: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80193874: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80193878: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8019387C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80193880: addiu       $t6, $t6, 0x39A0
    ctx->r14 = ADD32(ctx->r14, 0X39A0);
    // 0x80193884: lw          $t7, 0x1C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1C);
    // 0x80193888: lw          $t8, 0x3C($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X3C);
    // 0x8019388C: lw          $t0, 0x5C($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X5C);
    // 0x80193890: lw          $t2, 0x7C($t6)
    ctx->r10 = MEM_W(ctx->r14, 0X7C);
    // 0x80193894: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80193898: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8019389C: addu        $t3, $t2, $t1
    ctx->r11 = ADD32(ctx->r10, ctx->r9);
    // 0x801938A0: sltiu       $at, $t3, 0x3E7
    ctx->r1 = ctx->r11 < 0X3E7 ? 1 : 0;
    // 0x801938A4: beq         $at, $zero, L_801938C8
    if (ctx->r1 == 0) {
        // 0x801938A8: nop
    
            goto L_801938C8;
    }
    // 0x801938A8: nop

    // 0x801938AC: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x801938B0: sll         $t5, $t4, 5
    ctx->r13 = S32(ctx->r12 << 5);
    // 0x801938B4: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x801938B8: lw          $t8, 0x1C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1C);
    // 0x801938BC: addu        $t0, $t5, $t6
    ctx->r8 = ADD32(ctx->r13, ctx->r14);
    // 0x801938C0: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x801938C4: sw          $t9, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->r25;
L_801938C8:
    // 0x801938C8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x801938CC: lw          $t2, -0x2E48($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2E48);
    // 0x801938D0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801938D4: beq         $t2, $at, L_80193944
    if (ctx->r10 == ctx->r1) {
        // 0x801938D8: nop
    
            goto L_80193944;
    }
    // 0x801938D8: nop

    // 0x801938DC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x801938E0: addiu       $t1, $t1, -0x2BA8
    ctx->r9 = ADD32(ctx->r9, -0X2BA8);
    // 0x801938E4: lw          $t3, 0x1C($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X1C);
    // 0x801938E8: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    // 0x801938EC: bne         $t3, $at, L_8019392C
    if (ctx->r11 != ctx->r1) {
        // 0x801938F0: nop
    
            goto L_8019392C;
    }
    // 0x801938F0: nop

    // 0x801938F4: lw          $t4, 0x14($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X14);
    // 0x801938F8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801938FC: beq         $t4, $at, L_80193A24
    if (ctx->r12 == ctx->r1) {
        // 0x80193900: nop
    
            goto L_80193A24;
    }
    // 0x80193900: nop

    // 0x80193904: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80193908: addiu       $t7, $t7, -0x2BA8
    ctx->r15 = ADD32(ctx->r15, -0X2BA8);
    // 0x8019390C: sw          $zero, 0x1C($t1)
    MEM_W(0X1C, ctx->r9) = 0;
    // 0x80193910: lw          $t8, 0x14($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X14);
    // 0x80193914: addiu       $a0, $zero, 0x39
    ctx->r4 = ADD32(0, 0X39);
    // 0x80193918: addiu       $t5, $t8, 0x1
    ctx->r13 = ADD32(ctx->r24, 0X1);
    // 0x8019391C: jal         0x800C8544
    // 0x80193920: sw          $t5, 0x14($t7)
    MEM_W(0X14, ctx->r15) = ctx->r13;
    func_800C8544(rdram, ctx);
        goto after_0;
    // 0x80193920: sw          $t5, 0x14($t7)
    MEM_W(0X14, ctx->r15) = ctx->r13;
    after_0:
    // 0x80193924: b           L_80193A24
    // 0x80193928: nop

        goto L_80193A24;
    // 0x80193928: nop

L_8019392C:
    // 0x8019392C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80193930: addiu       $t6, $t6, -0x2BA8
    ctx->r14 = ADD32(ctx->r14, -0X2BA8);
    // 0x80193934: lw          $t9, 0x1C($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X1C);
    // 0x80193938: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8019393C: b           L_80193A24
    // 0x80193940: sw          $t0, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = ctx->r8;
        goto L_80193A24;
    // 0x80193940: sw          $t0, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = ctx->r8;
L_80193944:
    // 0x80193944: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x80193948: beq         $t2, $zero, L_80193958
    if (ctx->r10 == 0) {
        // 0x8019394C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80193958;
    }
    // 0x8019394C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80193950: bne         $t2, $at, L_801939C0
    if (ctx->r10 != ctx->r1) {
        // 0x80193954: nop
    
            goto L_801939C0;
    }
    // 0x80193954: nop

L_80193958:
    // 0x80193958: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8019395C: addiu       $t3, $t3, -0x2BA8
    ctx->r11 = ADD32(ctx->r11, -0X2BA8);
    // 0x80193960: lw          $t4, 0x1C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X1C);
    // 0x80193964: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    // 0x80193968: bne         $t4, $at, L_801939A8
    if (ctx->r12 != ctx->r1) {
        // 0x8019396C: nop
    
            goto L_801939A8;
    }
    // 0x8019396C: nop

    // 0x80193970: lw          $t1, 0x14($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X14);
    // 0x80193974: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80193978: beq         $t1, $at, L_80193A24
    if (ctx->r9 == ctx->r1) {
        // 0x8019397C: nop
    
            goto L_80193A24;
    }
    // 0x8019397C: nop

    // 0x80193980: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80193984: addiu       $t8, $t8, -0x2BA8
    ctx->r24 = ADD32(ctx->r24, -0X2BA8);
    // 0x80193988: sw          $zero, 0x1C($t3)
    MEM_W(0X1C, ctx->r11) = 0;
    // 0x8019398C: lw          $t5, 0x14($t8)
    ctx->r13 = MEM_W(ctx->r24, 0X14);
    // 0x80193990: addiu       $a0, $zero, 0x39
    ctx->r4 = ADD32(0, 0X39);
    // 0x80193994: addiu       $t7, $t5, 0x1
    ctx->r15 = ADD32(ctx->r13, 0X1);
    // 0x80193998: jal         0x800C8544
    // 0x8019399C: sw          $t7, 0x14($t8)
    MEM_W(0X14, ctx->r24) = ctx->r15;
    func_800C8544(rdram, ctx);
        goto after_1;
    // 0x8019399C: sw          $t7, 0x14($t8)
    MEM_W(0X14, ctx->r24) = ctx->r15;
    after_1:
    // 0x801939A0: b           L_80193A24
    // 0x801939A4: nop

        goto L_80193A24;
    // 0x801939A4: nop

L_801939A8:
    // 0x801939A8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801939AC: addiu       $t9, $t9, -0x2BA8
    ctx->r25 = ADD32(ctx->r25, -0X2BA8);
    // 0x801939B0: lw          $t0, 0x1C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X1C);
    // 0x801939B4: addiu       $t6, $t0, 0x1
    ctx->r14 = ADD32(ctx->r8, 0X1);
    // 0x801939B8: b           L_80193A24
    // 0x801939BC: sw          $t6, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->r14;
        goto L_80193A24;
    // 0x801939BC: sw          $t6, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->r14;
L_801939C0:
    // 0x801939C0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x801939C4: addiu       $t2, $t2, -0x2BA8
    ctx->r10 = ADD32(ctx->r10, -0X2BA8);
    // 0x801939C8: lw          $t4, 0x20($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X20);
    // 0x801939CC: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    // 0x801939D0: bne         $t4, $at, L_80193A10
    if (ctx->r12 != ctx->r1) {
        // 0x801939D4: nop
    
            goto L_80193A10;
    }
    // 0x801939D4: nop

    // 0x801939D8: lw          $t1, 0x18($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X18);
    // 0x801939DC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801939E0: beq         $t1, $at, L_80193A24
    if (ctx->r9 == ctx->r1) {
        // 0x801939E4: nop
    
            goto L_80193A24;
    }
    // 0x801939E4: nop

    // 0x801939E8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x801939EC: addiu       $t3, $t3, -0x2BA8
    ctx->r11 = ADD32(ctx->r11, -0X2BA8);
    // 0x801939F0: sw          $zero, 0x20($t2)
    MEM_W(0X20, ctx->r10) = 0;
    // 0x801939F4: lw          $t5, 0x18($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X18);
    // 0x801939F8: addiu       $a0, $zero, 0x39
    ctx->r4 = ADD32(0, 0X39);
    // 0x801939FC: addiu       $t7, $t5, 0x1
    ctx->r15 = ADD32(ctx->r13, 0X1);
    // 0x80193A00: jal         0x800C8544
    // 0x80193A04: sw          $t7, 0x18($t3)
    MEM_W(0X18, ctx->r11) = ctx->r15;
    func_800C8544(rdram, ctx);
        goto after_2;
    // 0x80193A04: sw          $t7, 0x18($t3)
    MEM_W(0X18, ctx->r11) = ctx->r15;
    after_2:
    // 0x80193A08: b           L_80193A24
    // 0x80193A0C: nop

        goto L_80193A24;
    // 0x80193A0C: nop

L_80193A10:
    // 0x80193A10: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80193A14: addiu       $t8, $t8, -0x2BA8
    ctx->r24 = ADD32(ctx->r24, -0X2BA8);
    // 0x80193A18: lw          $t0, 0x20($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X20);
    // 0x80193A1C: addiu       $t6, $t0, 0x1
    ctx->r14 = ADD32(ctx->r8, 0X1);
    // 0x80193A20: sw          $t6, 0x20($t8)
    MEM_W(0X20, ctx->r24) = ctx->r14;
L_80193A24:
    // 0x80193A24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80193A28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80193A2C: jr          $ra
    // 0x80193A30: nop

    return;
    // 0x80193A30: nop

;}
RECOMP_FUNC void func_80193A34_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80193A34: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80193A38: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80193A3C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80193A40: jal         0x800C7AD0
    // 0x80193A44: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800C7AD0(rdram, ctx);
        goto after_0;
    // 0x80193A44: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80193A48: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    // 0x80193A4C: jal         0x800C7A60
    // 0x80193A50: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C7A60(rdram, ctx);
        goto after_1;
    // 0x80193A50: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80193A54: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80193A58: lw          $s0, -0x2E48($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X2E48);
    // 0x80193A5C: beq         $s0, $zero, L_80193A7C
    if (ctx->r16 == 0) {
        // 0x80193A60: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80193A7C;
    }
    // 0x80193A60: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80193A64: beq         $s0, $at, L_80193A8C
    if (ctx->r16 == ctx->r1) {
        // 0x80193A68: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80193A8C;
    }
    // 0x80193A68: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80193A6C: beq         $s0, $at, L_80193A9C
    if (ctx->r16 == ctx->r1) {
        // 0x80193A70: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80193A9C;
    }
    // 0x80193A70: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80193A74: bne         $s0, $at, L_80193AA4
    if (ctx->r16 != ctx->r1) {
        // 0x80193A78: nop
    
            goto L_80193AA4;
    }
    // 0x80193A78: nop

L_80193A7C:
    // 0x80193A7C: jal         0x801957BC
    // 0x80193A80: nop

    func_801957BC_1501A0(rdram, ctx);
        goto after_2;
    // 0x80193A80: nop

    after_2:
    // 0x80193A84: b           L_80193AA4
    // 0x80193A88: nop

        goto L_80193AA4;
    // 0x80193A88: nop

L_80193A8C:
    // 0x80193A8C: jal         0x801958C8
    // 0x80193A90: nop

    func_801958C8_1501A0(rdram, ctx);
        goto after_3;
    // 0x80193A90: nop

    after_3:
    // 0x80193A94: b           L_80193AA4
    // 0x80193A98: nop

        goto L_80193AA4;
    // 0x80193A98: nop

L_80193A9C:
    // 0x80193A9C: jal         0x80195A60
    // 0x80193AA0: nop

    func_80195A60_1501A0(rdram, ctx);
        goto after_4;
    // 0x80193AA0: nop

    after_4:
L_80193AA4:
    // 0x80193AA4: jal         0x80193E94
    // 0x80193AA8: nop

    func_80193E94_1501A0(rdram, ctx);
        goto after_5;
    // 0x80193AA8: nop

    after_5:
    // 0x80193AAC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80193AB0: lw          $t6, -0x2E4C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2E4C);
    // 0x80193AB4: bne         $t6, $zero, L_80193B2C
    if (ctx->r14 != 0) {
        // 0x80193AB8: nop
    
            goto L_80193B2C;
    }
    // 0x80193AB8: nop

    // 0x80193ABC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80193AC0: lw          $t7, -0x2E3C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2E3C);
    // 0x80193AC4: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80193AC8: beq         $t7, $zero, L_80193B2C
    if (ctx->r15 == 0) {
        // 0x80193ACC: nop
    
            goto L_80193B2C;
    }
    // 0x80193ACC: nop

L_80193AD0:
    // 0x80193AD0: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80193AD4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80193AD8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80193ADC: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80193AE0: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x80193AE4: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80193AE8: lhu         $t0, -0x41DE($t0)
    ctx->r8 = MEM_HU(ctx->r8, -0X41DE);
    // 0x80193AEC: andi        $t1, $t0, 0xB000
    ctx->r9 = ctx->r8 & 0XB000;
    // 0x80193AF0: beq         $t1, $zero, L_80193B0C
    if (ctx->r9 == 0) {
        // 0x80193AF4: nop
    
            goto L_80193B0C;
    }
    // 0x80193AF4: nop

    // 0x80193AF8: jal         0x800C32CC
    // 0x80193AFC: nop

    func_800C32CC(rdram, ctx);
        goto after_6;
    // 0x80193AFC: nop

    after_6:
    // 0x80193B00: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80193B04: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80193B08: sw          $t2, -0x2E4C($at)
    MEM_W(-0X2E4C, ctx->r1) = ctx->r10;
L_80193B0C:
    // 0x80193B0C: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80193B10: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80193B14: lw          $t5, -0x2E3C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2E3C);
    // 0x80193B18: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80193B1C: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x80193B20: sltu        $at, $t4, $t5
    ctx->r1 = ctx->r12 < ctx->r13 ? 1 : 0;
    // 0x80193B24: bne         $at, $zero, L_80193AD0
    if (ctx->r1 != 0) {
        // 0x80193B28: nop
    
            goto L_80193AD0;
    }
    // 0x80193B28: nop

L_80193B2C:
    // 0x80193B2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80193B30: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80193B34: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80193B38: jr          $ra
    // 0x80193B3C: nop

    return;
    // 0x80193B3C: nop

;}
RECOMP_FUNC void func_80193B40_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80193B40: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80193B44: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80193B48: jal         0x800E4CDC
    // 0x80193B4C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    func_800E4CDC(rdram, ctx);
        goto after_0;
    // 0x80193B4C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x80193B50: jal         0x800C3FD0
    // 0x80193B54: nop

    func_800C3FD0(rdram, ctx);
        goto after_1;
    // 0x80193B54: nop

    after_1:
    // 0x80193B58: jal         0x800C7AD0
    // 0x80193B5C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800C7AD0(rdram, ctx);
        goto after_2;
    // 0x80193B5C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x80193B60: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    // 0x80193B64: jal         0x800C7A60
    // 0x80193B68: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C7A60(rdram, ctx);
        goto after_3;
    // 0x80193B68: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80193B6C: jal         0x80195708
    // 0x80193B70: nop

    func_80195708_1501A0(rdram, ctx);
        goto after_4;
    // 0x80193B70: nop

    after_4:
    // 0x80193B74: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80193B78: addiu       $t6, $t6, -0x2E18
    ctx->r14 = ADD32(ctx->r14, -0X2E18);
    // 0x80193B7C: lw          $t7, 0x14($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14);
    // 0x80193B80: bne         $t7, $zero, L_80193C70
    if (ctx->r15 != 0) {
        // 0x80193B84: nop
    
            goto L_80193C70;
    }
    // 0x80193B84: nop

    // 0x80193B88: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80193B8C: lw          $s0, -0x2E48($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X2E48);
    // 0x80193B90: beq         $s0, $zero, L_80193BB0
    if (ctx->r16 == 0) {
        // 0x80193B94: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80193BB0;
    }
    // 0x80193B94: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80193B98: beq         $s0, $at, L_80193BC0
    if (ctx->r16 == ctx->r1) {
        // 0x80193B9C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80193BC0;
    }
    // 0x80193B9C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80193BA0: beq         $s0, $at, L_80193BD0
    if (ctx->r16 == ctx->r1) {
        // 0x80193BA4: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80193BD0;
    }
    // 0x80193BA4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80193BA8: bne         $s0, $at, L_80193BD8
    if (ctx->r16 != ctx->r1) {
        // 0x80193BAC: nop
    
            goto L_80193BD8;
    }
    // 0x80193BAC: nop

L_80193BB0:
    // 0x80193BB0: jal         0x801957BC
    // 0x80193BB4: nop

    func_801957BC_1501A0(rdram, ctx);
        goto after_5;
    // 0x80193BB4: nop

    after_5:
    // 0x80193BB8: b           L_80193BD8
    // 0x80193BBC: nop

        goto L_80193BD8;
    // 0x80193BBC: nop

L_80193BC0:
    // 0x80193BC0: jal         0x801958C8
    // 0x80193BC4: nop

    func_801958C8_1501A0(rdram, ctx);
        goto after_6;
    // 0x80193BC4: nop

    after_6:
    // 0x80193BC8: b           L_80193BD8
    // 0x80193BCC: nop

        goto L_80193BD8;
    // 0x80193BCC: nop

L_80193BD0:
    // 0x80193BD0: jal         0x80195A60
    // 0x80193BD4: nop

    func_80195A60_1501A0(rdram, ctx);
        goto after_7;
    // 0x80193BD4: nop

    after_7:
L_80193BD8:
    // 0x80193BD8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80193BDC: lw          $t8, -0x2E3C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2E3C);
    // 0x80193BE0: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80193BE4: beq         $t8, $zero, L_80193C60
    if (ctx->r24 == 0) {
        // 0x80193BE8: nop
    
            goto L_80193C60;
    }
    // 0x80193BE8: nop

L_80193BEC:
    // 0x80193BEC: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80193BF0: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80193BF4: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80193BF8: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80193BFC: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x80193C00: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80193C04: lhu         $t1, -0x41DE($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X41DE);
    // 0x80193C08: andi        $t2, $t1, 0x1000
    ctx->r10 = ctx->r9 & 0X1000;
    // 0x80193C0C: beq         $t2, $zero, L_80193C40
    if (ctx->r10 == 0) {
        // 0x80193C10: nop
    
            goto L_80193C40;
    }
    // 0x80193C10: nop

    // 0x80193C14: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80193C18: addiu       $t3, $t3, -0x2E18
    ctx->r11 = ADD32(ctx->r11, -0X2E18);
    // 0x80193C1C: lw          $t4, 0x14($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X14);
    // 0x80193C20: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80193C24: addiu       $t6, $t6, -0x2E18
    ctx->r14 = ADD32(ctx->r14, -0X2E18);
    // 0x80193C28: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80193C2C: sw          $t5, 0x14($t3)
    MEM_W(0X14, ctx->r11) = ctx->r13;
    // 0x80193C30: jal         0x800C321C
    // 0x80193C34: sw          $zero, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = 0;
    func_800C321C(rdram, ctx);
        goto after_8;
    // 0x80193C34: sw          $zero, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = 0;
    after_8:
    // 0x80193C38: b           L_80193DD4
    // 0x80193C3C: nop

        goto L_80193DD4;
    // 0x80193C3C: nop

L_80193C40:
    // 0x80193C40: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80193C44: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80193C48: lw          $t9, -0x2E3C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2E3C);
    // 0x80193C4C: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80193C50: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x80193C54: sltu        $at, $t8, $t9
    ctx->r1 = ctx->r24 < ctx->r25 ? 1 : 0;
    // 0x80193C58: bne         $at, $zero, L_80193BEC
    if (ctx->r1 != 0) {
        // 0x80193C5C: nop
    
            goto L_80193BEC;
    }
    // 0x80193C5C: nop

L_80193C60:
    // 0x80193C60: jal         0x80193E94
    // 0x80193C64: nop

    func_80193E94_1501A0(rdram, ctx);
        goto after_9;
    // 0x80193C64: nop

    after_9:
    // 0x80193C68: b           L_80193DD4
    // 0x80193C6C: nop

        goto L_80193DD4;
    // 0x80193C6C: nop

L_80193C70:
    // 0x80193C70: jal         0x80196024
    // 0x80193C74: nop

    func_80196024_1501A0(rdram, ctx);
        goto after_10;
    // 0x80193C74: nop

    after_10:
    // 0x80193C78: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80193C7C: lw          $t0, -0x2E4C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2E4C);
    // 0x80193C80: bne         $t0, $zero, L_80193DD4
    if (ctx->r8 != 0) {
        // 0x80193C84: nop
    
            goto L_80193DD4;
    }
    // 0x80193C84: nop

    // 0x80193C88: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80193C8C: lw          $t1, -0x2E3C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2E3C);
    // 0x80193C90: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80193C94: beq         $t1, $zero, L_80193DCC
    if (ctx->r9 == 0) {
        // 0x80193C98: nop
    
            goto L_80193DCC;
    }
    // 0x80193C98: nop

L_80193C9C:
    // 0x80193C9C: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80193CA0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80193CA4: sll         $t4, $t2, 2
    ctx->r12 = S32(ctx->r10 << 2);
    // 0x80193CA8: addu        $t4, $t4, $t2
    ctx->r12 = ADD32(ctx->r12, ctx->r10);
    // 0x80193CAC: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x80193CB0: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x80193CB4: lhu         $t5, -0x41DE($t5)
    ctx->r13 = MEM_HU(ctx->r13, -0X41DE);
    // 0x80193CB8: andi        $t3, $t5, 0x1000
    ctx->r11 = ctx->r13 & 0X1000;
    // 0x80193CBC: beq         $t3, $zero, L_80193DAC
    if (ctx->r11 == 0) {
        // 0x80193CC0: nop
    
            goto L_80193DAC;
    }
    // 0x80193CC0: nop

    // 0x80193CC4: jal         0x800CB934
    // 0x80193CC8: nop

    func_800CB934(rdram, ctx);
        goto after_11;
    // 0x80193CC8: nop

    after_11:
    // 0x80193CCC: jal         0x800D28C0
    // 0x80193CD0: nop

    func_800D28C0(rdram, ctx);
        goto after_12;
    // 0x80193CD0: nop

    after_12:
    // 0x80193CD4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80193CD8: addiu       $t6, $t6, -0x2E18
    ctx->r14 = ADD32(ctx->r14, -0X2E18);
    // 0x80193CDC: lw          $s0, 0x1C($t6)
    ctx->r16 = MEM_W(ctx->r14, 0X1C);
    // 0x80193CE0: beq         $s0, $zero, L_80193D00
    if (ctx->r16 == 0) {
        // 0x80193CE4: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80193D00;
    }
    // 0x80193CE4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80193CE8: beq         $s0, $at, L_80193D7C
    if (ctx->r16 == ctx->r1) {
        // 0x80193CEC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80193D7C;
    }
    // 0x80193CEC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80193CF0: beq         $s0, $at, L_80193D94
    if (ctx->r16 == ctx->r1) {
        // 0x80193CF4: nop
    
            goto L_80193D94;
    }
    // 0x80193CF4: nop

    // 0x80193CF8: b           L_80193DAC
    // 0x80193CFC: nop

        goto L_80193DAC;
    // 0x80193CFC: nop

L_80193D00:
    // 0x80193D00: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80193D04: addiu       $t7, $t7, -0x2E28
    ctx->r15 = ADD32(ctx->r15, -0X2E28);
    // 0x80193D08: lbu         $t8, 0xA($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0XA);
    // 0x80193D0C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80193D10: andi        $t9, $t8, 0xFE
    ctx->r25 = ctx->r24 & 0XFE;
    // 0x80193D14: sb          $t9, 0xA($t7)
    MEM_B(0XA, ctx->r15) = ctx->r25;
    // 0x80193D18: lw          $t0, -0x2E3C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2E3C);
    // 0x80193D1C: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x80193D20: beq         $t0, $zero, L_80193DD4
    if (ctx->r8 == 0) {
        // 0x80193D24: nop
    
            goto L_80193DD4;
    }
    // 0x80193D24: nop

L_80193D28:
    // 0x80193D28: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80193D2C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80193D30: addiu       $t4, $t4, 0x39A0
    ctx->r12 = ADD32(ctx->r12, 0X39A0);
    // 0x80193D34: sll         $t2, $t1, 5
    ctx->r10 = S32(ctx->r9 << 5);
    // 0x80193D38: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80193D3C: lw          $t3, 0xC($t5)
    ctx->r11 = MEM_W(ctx->r13, 0XC);
    // 0x80193D40: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x80193D44: beq         $t3, $t6, L_80193D54
    if (ctx->r11 == ctx->r14) {
        // 0x80193D48: nop
    
            goto L_80193D54;
    }
    // 0x80193D48: nop

    // 0x80193D4C: jal         0x80173864
    // 0x80193D50: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    func_80173864_1501A0(rdram, ctx);
        goto after_13;
    // 0x80193D50: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    after_13:
L_80193D54:
    // 0x80193D54: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80193D58: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80193D5C: lw          $t7, -0x2E3C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2E3C);
    // 0x80193D60: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80193D64: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x80193D68: sltu        $at, $t9, $t7
    ctx->r1 = ctx->r25 < ctx->r15 ? 1 : 0;
    // 0x80193D6C: bne         $at, $zero, L_80193D28
    if (ctx->r1 != 0) {
        // 0x80193D70: nop
    
            goto L_80193D28;
    }
    // 0x80193D70: nop

    // 0x80193D74: b           L_80193DD4
    // 0x80193D78: nop

        goto L_80193DD4;
    // 0x80193D78: nop

L_80193D7C:
    // 0x80193D7C: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x80193D80: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80193D84: jal         0x800C32CC
    // 0x80193D88: sw          $t0, -0x2E4C($at)
    MEM_W(-0X2E4C, ctx->r1) = ctx->r8;
    func_800C32CC(rdram, ctx);
        goto after_14;
    // 0x80193D88: sw          $t0, -0x2E4C($at)
    MEM_W(-0X2E4C, ctx->r1) = ctx->r8;
    after_14:
    // 0x80193D8C: b           L_80193DD4
    // 0x80193D90: nop

        goto L_80193DD4;
    // 0x80193D90: nop

L_80193D94:
    // 0x80193D94: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x80193D98: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80193D9C: jal         0x800C32CC
    // 0x80193DA0: sw          $t2, -0x2E4C($at)
    MEM_W(-0X2E4C, ctx->r1) = ctx->r10;
    func_800C32CC(rdram, ctx);
        goto after_15;
    // 0x80193DA0: sw          $t2, -0x2E4C($at)
    MEM_W(-0X2E4C, ctx->r1) = ctx->r10;
    after_15:
    // 0x80193DA4: b           L_80193DD4
    // 0x80193DA8: nop

        goto L_80193DD4;
    // 0x80193DA8: nop

L_80193DAC:
    // 0x80193DAC: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80193DB0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80193DB4: lw          $t3, -0x2E3C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2E3C);
    // 0x80193DB8: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80193DBC: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x80193DC0: sltu        $at, $t5, $t3
    ctx->r1 = ctx->r13 < ctx->r11 ? 1 : 0;
    // 0x80193DC4: bne         $at, $zero, L_80193C9C
    if (ctx->r1 != 0) {
        // 0x80193DC8: nop
    
            goto L_80193C9C;
    }
    // 0x80193DC8: nop

L_80193DCC:
    // 0x80193DCC: jal         0x80194F8C
    // 0x80193DD0: nop

    func_80194F8C_1501A0(rdram, ctx);
        goto after_16;
    // 0x80193DD0: nop

    after_16:
L_80193DD4:
    // 0x80193DD4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80193DD8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80193DDC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80193DE0: jr          $ra
    // 0x80193DE4: nop

    return;
    // 0x80193DE4: nop

;}
RECOMP_FUNC void func_80193DE8_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80193DE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80193DEC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80193DF0: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80193DF4: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80193DF8: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80193DFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80193E00: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80193E04: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80193E08: cvt.d.s     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f14.d = CVT_D_S(ctx->f6.fl);
    // 0x80193E0C: jal         0x800C7A88
    // 0x80193E10: cvt.d.s     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f12.d = CVT_D_S(ctx->f4.fl);
    func_800C7A88(rdram, ctx);
        goto after_0;
    // 0x80193E10: cvt.d.s     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f12.d = CVT_D_S(ctx->f4.fl);
    after_0:
    // 0x80193E14: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80193E18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80193E1C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80193E20: jal         0x800C7A9C
    // 0x80193E24: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    func_800C7A9C(rdram, ctx);
        goto after_1;
    // 0x80193E24: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_1:
    // 0x80193E28: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80193E2C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80193E30: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80193E34: jal         0x800C7A74
    // 0x80193E38: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    func_800C7A74(rdram, ctx);
        goto after_2;
    // 0x80193E38: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    after_2:
    // 0x80193E3C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80193E40: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80193E44: addiu       $a1, $a1, 0x3B40
    ctx->r5 = ADD32(ctx->r5, 0X3B40);
    // 0x80193E48: jal         0x800C767C
    // 0x80193E4C: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    func_800C767C(rdram, ctx);
        goto after_3;
    // 0x80193E4C: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    after_3:
    // 0x80193E50: lbu         $a0, 0x2B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X2B);
    // 0x80193E54: lbu         $a1, 0x2F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X2F);
    // 0x80193E58: lbu         $a2, 0x33($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X33);
    // 0x80193E5C: jal         0x800C7A9C
    // 0x80193E60: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    func_800C7A9C(rdram, ctx);
        goto after_4;
    // 0x80193E60: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_4:
    // 0x80193E64: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80193E68: jal         0x800C7A74
    // 0x80193E6C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_800C7A74(rdram, ctx);
        goto after_5;
    // 0x80193E6C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_5:
    // 0x80193E70: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80193E74: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80193E78: addiu       $a1, $a1, 0x3B40
    ctx->r5 = ADD32(ctx->r5, 0X3B40);
    // 0x80193E7C: jal         0x800C767C
    // 0x80193E80: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    func_800C767C(rdram, ctx);
        goto after_6;
    // 0x80193E80: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    after_6:
    // 0x80193E84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80193E88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80193E8C: jr          $ra
    // 0x80193E90: nop

    return;
    // 0x80193E90: nop

;}
RECOMP_FUNC void func_80193E94_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80193E94: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80193E98: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80193E9C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80193EA0: lw          $s0, -0x2E48($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X2E48);
    // 0x80193EA4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80193EA8: beq         $s0, $zero, L_80193EC8
    if (ctx->r16 == 0) {
        // 0x80193EAC: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80193EC8;
    }
    // 0x80193EAC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80193EB0: beq         $s0, $at, L_801940FC
    if (ctx->r16 == ctx->r1) {
        // 0x80193EB4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_801940FC;
    }
    // 0x80193EB4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80193EB8: beq         $s0, $at, L_801947CC
    if (ctx->r16 == ctx->r1) {
        // 0x80193EBC: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_801947CC;
    }
    // 0x80193EBC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80193EC0: bne         $s0, $at, L_80194D40
    if (ctx->r16 != ctx->r1) {
        // 0x80193EC4: nop
    
            goto L_80194D40;
    }
    // 0x80193EC4: nop

L_80193EC8:
    // 0x80193EC8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80193ECC: addiu       $t6, $t6, -0x2E28
    ctx->r14 = ADD32(ctx->r14, -0X2E28);
    // 0x80193ED0: lbu         $t7, 0xA($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0XA);
    // 0x80193ED4: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80193ED8: beq         $t8, $zero, L_80194D40
    if (ctx->r24 == 0) {
        // 0x80193EDC: nop
    
            goto L_80194D40;
    }
    // 0x80193EDC: nop

    // 0x80193EE0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80193EE4: addiu       $t9, $t9, -0x41E0
    ctx->r25 = ADD32(ctx->r25, -0X41E0);
    // 0x80193EE8: lhu         $t0, 0x4($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X4);
    // 0x80193EEC: andi        $t1, $t0, 0x100
    ctx->r9 = ctx->r8 & 0X100;
    // 0x80193EF0: beq         $t1, $zero, L_80193F38
    if (ctx->r9 == 0) {
        // 0x80193EF4: nop
    
            goto L_80193F38;
    }
    // 0x80193EF4: nop

    // 0x80193EF8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80193EFC: addiu       $t2, $t2, 0x39A0
    ctx->r10 = ADD32(ctx->r10, 0X39A0);
    // 0x80193F00: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x80193F04: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80193F08: addiu       $t5, $t5, 0x39A0
    ctx->r13 = ADD32(ctx->r13, 0X39A0);
    // 0x80193F0C: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80193F10: sw          $t4, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r12;
    // 0x80193F14: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x80193F18: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80193F1C: bne         $t6, $at, L_80193F28
    if (ctx->r14 != ctx->r1) {
        // 0x80193F20: nop
    
            goto L_80193F28;
    }
    // 0x80193F20: nop

    // 0x80193F24: sw          $zero, 0x8($t5)
    MEM_W(0X8, ctx->r13) = 0;
L_80193F28:
    // 0x80193F28: jal         0x800C8544
    // 0x80193F2C: addiu       $a0, $zero, 0x7B
    ctx->r4 = ADD32(0, 0X7B);
    func_800C8544(rdram, ctx);
        goto after_0;
    // 0x80193F2C: addiu       $a0, $zero, 0x7B
    ctx->r4 = ADD32(0, 0X7B);
    after_0:
    // 0x80193F30: b           L_80194D40
    // 0x80193F34: nop

        goto L_80194D40;
    // 0x80193F34: nop

L_80193F38:
    // 0x80193F38: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80193F3C: addiu       $t7, $t7, -0x2E28
    ctx->r15 = ADD32(ctx->r15, -0X2E28);
    // 0x80193F40: lbu         $t8, 0xD($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0XD);
    // 0x80193F44: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x80193F48: bne         $t9, $zero, L_80193FBC
    if (ctx->r25 != 0) {
        // 0x80193F4C: nop
    
            goto L_80193FBC;
    }
    // 0x80193F4C: nop

    // 0x80193F50: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80193F54: addiu       $t0, $t0, -0x41E0
    ctx->r8 = ADD32(ctx->r8, -0X41E0);
    // 0x80193F58: lb          $t1, 0x6($t0)
    ctx->r9 = MEM_B(ctx->r8, 0X6);
    // 0x80193F5C: slti        $at, $t1, 0xF
    ctx->r1 = SIGNED(ctx->r9) < 0XF ? 1 : 0;
    // 0x80193F60: bne         $at, $zero, L_80193FBC
    if (ctx->r1 != 0) {
        // 0x80193F64: nop
    
            goto L_80193FBC;
    }
    // 0x80193F64: nop

    // 0x80193F68: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80193F6C: addiu       $t3, $t3, 0x39A0
    ctx->r11 = ADD32(ctx->r11, 0X39A0);
    // 0x80193F70: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x80193F74: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80193F78: addiu       $t6, $t6, -0x2E28
    ctx->r14 = ADD32(ctx->r14, -0X2E28);
    // 0x80193F7C: addiu       $t2, $t4, 0x1
    ctx->r10 = ADD32(ctx->r12, 0X1);
    // 0x80193F80: sw          $t2, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r10;
    // 0x80193F84: lbu         $t5, 0xD($t6)
    ctx->r13 = MEM_BU(ctx->r14, 0XD);
    // 0x80193F88: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80193F8C: addiu       $t8, $t8, 0x39A0
    ctx->r24 = ADD32(ctx->r24, 0X39A0);
    // 0x80193F90: ori         $t7, $t5, 0x1
    ctx->r15 = ctx->r13 | 0X1;
    // 0x80193F94: sb          $t7, 0xD($t6)
    MEM_B(0XD, ctx->r14) = ctx->r15;
    // 0x80193F98: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x80193F9C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80193FA0: bne         $t9, $at, L_80193FAC
    if (ctx->r25 != ctx->r1) {
        // 0x80193FA4: nop
    
            goto L_80193FAC;
    }
    // 0x80193FA4: nop

    // 0x80193FA8: sw          $zero, 0x8($t8)
    MEM_W(0X8, ctx->r24) = 0;
L_80193FAC:
    // 0x80193FAC: jal         0x800C8544
    // 0x80193FB0: addiu       $a0, $zero, 0x7B
    ctx->r4 = ADD32(0, 0X7B);
    func_800C8544(rdram, ctx);
        goto after_1;
    // 0x80193FB0: addiu       $a0, $zero, 0x7B
    ctx->r4 = ADD32(0, 0X7B);
    after_1:
    // 0x80193FB4: b           L_80194D40
    // 0x80193FB8: nop

        goto L_80194D40;
    // 0x80193FB8: nop

L_80193FBC:
    // 0x80193FBC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80193FC0: addiu       $t0, $t0, -0x41E0
    ctx->r8 = ADD32(ctx->r8, -0X41E0);
    // 0x80193FC4: lhu         $t1, 0x4($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X4);
    // 0x80193FC8: andi        $t4, $t1, 0x200
    ctx->r12 = ctx->r9 & 0X200;
    // 0x80193FCC: beq         $t4, $zero, L_80194018
    if (ctx->r12 == 0) {
        // 0x80193FD0: nop
    
            goto L_80194018;
    }
    // 0x80193FD0: nop

    // 0x80193FD4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80193FD8: addiu       $t2, $t2, 0x39A0
    ctx->r10 = ADD32(ctx->r10, 0X39A0);
    // 0x80193FDC: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x80193FE0: bne         $t3, $zero, L_80193FF4
    if (ctx->r11 != 0) {
        // 0x80193FE4: nop
    
            goto L_80193FF4;
    }
    // 0x80193FE4: nop

    // 0x80193FE8: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x80193FEC: b           L_80194008
    // 0x80193FF0: sw          $t5, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r13;
        goto L_80194008;
    // 0x80193FF0: sw          $t5, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r13;
L_80193FF4:
    // 0x80193FF4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80193FF8: addiu       $t7, $t7, 0x39A0
    ctx->r15 = ADD32(ctx->r15, 0X39A0);
    // 0x80193FFC: lw          $t6, 0x8($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X8);
    // 0x80194000: addiu       $t9, $t6, -0x1
    ctx->r25 = ADD32(ctx->r14, -0X1);
    // 0x80194004: sw          $t9, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r25;
L_80194008:
    // 0x80194008: jal         0x800C8544
    // 0x8019400C: addiu       $a0, $zero, 0x7B
    ctx->r4 = ADD32(0, 0X7B);
    func_800C8544(rdram, ctx);
        goto after_2;
    // 0x8019400C: addiu       $a0, $zero, 0x7B
    ctx->r4 = ADD32(0, 0X7B);
    after_2:
    // 0x80194010: b           L_80194D40
    // 0x80194014: nop

        goto L_80194D40;
    // 0x80194014: nop

L_80194018:
    // 0x80194018: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8019401C: addiu       $t8, $t8, -0x2E28
    ctx->r24 = ADD32(ctx->r24, -0X2E28);
    // 0x80194020: lbu         $t0, 0xD($t8)
    ctx->r8 = MEM_BU(ctx->r24, 0XD);
    // 0x80194024: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x80194028: bne         $t1, $zero, L_80194094
    if (ctx->r9 != 0) {
        // 0x8019402C: nop
    
            goto L_80194094;
    }
    // 0x8019402C: nop

    // 0x80194030: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80194034: addiu       $t4, $t4, -0x41E0
    ctx->r12 = ADD32(ctx->r12, -0X41E0);
    // 0x80194038: lb          $t3, 0x6($t4)
    ctx->r11 = MEM_B(ctx->r12, 0X6);
    // 0x8019403C: slti        $at, $t3, -0xE
    ctx->r1 = SIGNED(ctx->r11) < -0XE ? 1 : 0;
    // 0x80194040: beq         $at, $zero, L_80194094
    if (ctx->r1 == 0) {
        // 0x80194044: nop
    
            goto L_80194094;
    }
    // 0x80194044: nop

    // 0x80194048: ori         $t5, $t0, 0x1
    ctx->r13 = ctx->r8 | 0X1;
    // 0x8019404C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80194050: sb          $t5, 0xD($t8)
    MEM_B(0XD, ctx->r24) = ctx->r13;
    // 0x80194054: addiu       $t2, $t2, 0x39A0
    ctx->r10 = ADD32(ctx->r10, 0X39A0);
    // 0x80194058: lw          $t6, 0x8($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X8);
    // 0x8019405C: bne         $t6, $zero, L_80194070
    if (ctx->r14 != 0) {
        // 0x80194060: nop
    
            goto L_80194070;
    }
    // 0x80194060: nop

    // 0x80194064: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80194068: b           L_80194084
    // 0x8019406C: sw          $t9, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r25;
        goto L_80194084;
    // 0x8019406C: sw          $t9, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r25;
L_80194070:
    // 0x80194070: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80194074: addiu       $t7, $t7, 0x39A0
    ctx->r15 = ADD32(ctx->r15, 0X39A0);
    // 0x80194078: lw          $t1, 0x8($t7)
    ctx->r9 = MEM_W(ctx->r15, 0X8);
    // 0x8019407C: addiu       $t4, $t1, -0x1
    ctx->r12 = ADD32(ctx->r9, -0X1);
    // 0x80194080: sw          $t4, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r12;
L_80194084:
    // 0x80194084: jal         0x800C8544
    // 0x80194088: addiu       $a0, $zero, 0x7B
    ctx->r4 = ADD32(0, 0X7B);
    func_800C8544(rdram, ctx);
        goto after_3;
    // 0x80194088: addiu       $a0, $zero, 0x7B
    ctx->r4 = ADD32(0, 0X7B);
    after_3:
    // 0x8019408C: b           L_80194D40
    // 0x80194090: nop

        goto L_80194D40;
    // 0x80194090: nop

L_80194094:
    // 0x80194094: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80194098: addiu       $t3, $t3, -0x2E28
    ctx->r11 = ADD32(ctx->r11, -0X2E28);
    // 0x8019409C: lbu         $t0, 0xD($t3)
    ctx->r8 = MEM_BU(ctx->r11, 0XD);
    // 0x801940A0: andi        $t5, $t0, 0x1
    ctx->r13 = ctx->r8 & 0X1;
    // 0x801940A4: beq         $t5, $zero, L_80194D40
    if (ctx->r13 == 0) {
        // 0x801940A8: nop
    
            goto L_80194D40;
    }
    // 0x801940A8: nop

    // 0x801940AC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x801940B0: addiu       $t8, $t8, -0x41E0
    ctx->r24 = ADD32(ctx->r24, -0X41E0);
    // 0x801940B4: lb          $t6, 0x6($t8)
    ctx->r14 = MEM_B(ctx->r24, 0X6);
    // 0x801940B8: blez        $t6, L_801940C8
    if (SIGNED(ctx->r14) <= 0) {
        // 0x801940BC: nop
    
            goto L_801940C8;
    }
    // 0x801940BC: nop

    // 0x801940C0: b           L_801940D8
    // 0x801940C4: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
        goto L_801940D8;
    // 0x801940C4: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
L_801940C8:
    // 0x801940C8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801940CC: addiu       $t9, $t9, -0x41E0
    ctx->r25 = ADD32(ctx->r25, -0X41E0);
    // 0x801940D0: lb          $s0, 0x6($t9)
    ctx->r16 = MEM_B(ctx->r25, 0X6);
    // 0x801940D4: negu        $s0, $s0
    ctx->r16 = SUB32(0, ctx->r16);
L_801940D8:
    // 0x801940D8: slti        $at, $s0, 0x6
    ctx->r1 = SIGNED(ctx->r16) < 0X6 ? 1 : 0;
    // 0x801940DC: beq         $at, $zero, L_80194D40
    if (ctx->r1 == 0) {
        // 0x801940E0: nop
    
            goto L_80194D40;
    }
    // 0x801940E0: nop

    // 0x801940E4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x801940E8: addiu       $t2, $t2, -0x2E28
    ctx->r10 = ADD32(ctx->r10, -0X2E28);
    // 0x801940EC: lbu         $t1, 0xD($t2)
    ctx->r9 = MEM_BU(ctx->r10, 0XD);
    // 0x801940F0: andi        $t4, $t1, 0xFE
    ctx->r12 = ctx->r9 & 0XFE;
    // 0x801940F4: b           L_80194D40
    // 0x801940F8: sb          $t4, 0xD($t2)
    MEM_B(0XD, ctx->r10) = ctx->r12;
        goto L_80194D40;
    // 0x801940F8: sb          $t4, 0xD($t2)
    MEM_B(0XD, ctx->r10) = ctx->r12;
L_801940FC:
    // 0x801940FC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80194100: addiu       $t7, $t7, -0x2E18
    ctx->r15 = ADD32(ctx->r15, -0X2E18);
    // 0x80194104: lw          $s0, 0x20($t7)
    ctx->r16 = MEM_W(ctx->r15, 0X20);
    // 0x80194108: beq         $s0, $zero, L_801941A0
    if (ctx->r16 == 0) {
        // 0x8019410C: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_801941A0;
    }
    // 0x8019410C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80194110: beq         $s0, $at, L_80194128
    if (ctx->r16 == ctx->r1) {
        // 0x80194114: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80194128;
    }
    // 0x80194114: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80194118: beq         $s0, $at, L_80194164
    if (ctx->r16 == ctx->r1) {
        // 0x8019411C: nop
    
            goto L_80194164;
    }
    // 0x8019411C: nop

    // 0x80194120: b           L_8019427C
    // 0x80194124: nop

        goto L_8019427C;
    // 0x80194124: nop

L_80194128:
    // 0x80194128: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8019412C: addiu       $t3, $t3, -0x2E18
    ctx->r11 = ADD32(ctx->r11, -0X2E18);
    // 0x80194130: lw          $t0, 0x18($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X18);
    // 0x80194134: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80194138: addiu       $t8, $t8, -0x2E18
    ctx->r24 = ADD32(ctx->r24, -0X2E18);
    // 0x8019413C: addiu       $t5, $t0, -0x28
    ctx->r13 = ADD32(ctx->r8, -0X28);
    // 0x80194140: sw          $t5, 0x18($t3)
    MEM_W(0X18, ctx->r11) = ctx->r13;
    // 0x80194144: lw          $t6, 0x18($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X18);
    // 0x80194148: addiu       $at, $zero, 0x140
    ctx->r1 = ADD32(0, 0X140);
    // 0x8019414C: divu        $zero, $t6, $at
    lo = S32(U32(ctx->r14) / U32(ctx->r1)); hi = S32(U32(ctx->r14) % U32(ctx->r1));
    // 0x80194150: mfhi        $t9
    ctx->r25 = hi;
    // 0x80194154: bne         $t9, $zero, L_8019427C
    if (ctx->r25 != 0) {
        // 0x80194158: nop
    
            goto L_8019427C;
    }
    // 0x80194158: nop

    // 0x8019415C: b           L_8019427C
    // 0x80194160: sw          $zero, 0x20($t8)
    MEM_W(0X20, ctx->r24) = 0;
        goto L_8019427C;
    // 0x80194160: sw          $zero, 0x20($t8)
    MEM_W(0X20, ctx->r24) = 0;
L_80194164:
    // 0x80194164: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80194168: addiu       $t1, $t1, -0x2E18
    ctx->r9 = ADD32(ctx->r9, -0X2E18);
    // 0x8019416C: lw          $t4, 0x18($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X18);
    // 0x80194170: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80194174: addiu       $t7, $t7, -0x2E18
    ctx->r15 = ADD32(ctx->r15, -0X2E18);
    // 0x80194178: addiu       $t2, $t4, 0x28
    ctx->r10 = ADD32(ctx->r12, 0X28);
    // 0x8019417C: sw          $t2, 0x18($t1)
    MEM_W(0X18, ctx->r9) = ctx->r10;
    // 0x80194180: lw          $t0, 0x18($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X18);
    // 0x80194184: addiu       $at, $zero, 0x140
    ctx->r1 = ADD32(0, 0X140);
    // 0x80194188: divu        $zero, $t0, $at
    lo = S32(U32(ctx->r8) / U32(ctx->r1)); hi = S32(U32(ctx->r8) % U32(ctx->r1));
    // 0x8019418C: mfhi        $t5
    ctx->r13 = hi;
    // 0x80194190: bne         $t5, $zero, L_8019427C
    if (ctx->r13 != 0) {
        // 0x80194194: nop
    
            goto L_8019427C;
    }
    // 0x80194194: nop

    // 0x80194198: b           L_8019427C
    // 0x8019419C: sw          $zero, 0x20($t7)
    MEM_W(0X20, ctx->r15) = 0;
        goto L_8019427C;
    // 0x8019419C: sw          $zero, 0x20($t7)
    MEM_W(0X20, ctx->r15) = 0;
L_801941A0:
    // 0x801941A0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x801941A4: lw          $t3, -0x2E3C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2E3C);
    // 0x801941A8: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x801941AC: beq         $t3, $zero, L_8019427C
    if (ctx->r11 == 0) {
        // 0x801941B0: nop
    
            goto L_8019427C;
    }
    // 0x801941B0: nop

L_801941B4:
    // 0x801941B4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801941B8: addiu       $t6, $t6, -0x2E18
    ctx->r14 = ADD32(ctx->r14, -0X2E18);
    // 0x801941BC: lw          $t9, 0x18($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X18);
    // 0x801941C0: beq         $t9, $zero, L_801941FC
    if (ctx->r25 == 0) {
        // 0x801941C4: nop
    
            goto L_801941FC;
    }
    // 0x801941C4: nop

    // 0x801941C8: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x801941CC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x801941D0: sll         $t4, $t8, 2
    ctx->r12 = S32(ctx->r24 << 2);
    // 0x801941D4: addu        $t4, $t4, $t8
    ctx->r12 = ADD32(ctx->r12, ctx->r24);
    // 0x801941D8: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x801941DC: addu        $t2, $t2, $t4
    ctx->r10 = ADD32(ctx->r10, ctx->r12);
    // 0x801941E0: lhu         $t2, -0x41DE($t2)
    ctx->r10 = MEM_HU(ctx->r10, -0X41DE);
    // 0x801941E4: andi        $t1, $t2, 0x2
    ctx->r9 = ctx->r10 & 0X2;
    // 0x801941E8: beq         $t1, $zero, L_801941FC
    if (ctx->r9 == 0) {
        // 0x801941EC: nop
    
            goto L_801941FC;
    }
    // 0x801941EC: nop

    // 0x801941F0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801941F4: b           L_80194D40
    // 0x801941F8: sw          $t0, 0x20($t6)
    MEM_W(0X20, ctx->r14) = ctx->r8;
        goto L_80194D40;
    // 0x801941F8: sw          $t0, 0x20($t6)
    MEM_W(0X20, ctx->r14) = ctx->r8;
L_801941FC:
    // 0x801941FC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80194200: lw          $t9, -0x2E3C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2E3C);
    // 0x80194204: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80194208: addiu       $t5, $t5, -0x2E18
    ctx->r13 = ADD32(ctx->r13, -0X2E18);
    // 0x8019420C: lw          $t7, 0x18($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X18);
    // 0x80194210: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80194214: addu        $t8, $t8, $t9
    ctx->r24 = ADD32(ctx->r24, ctx->r25);
    // 0x80194218: sll         $t8, $t8, 6
    ctx->r24 = S32(ctx->r24 << 6);
    // 0x8019421C: addiu       $t3, $t7, 0x140
    ctx->r11 = ADD32(ctx->r15, 0X140);
    // 0x80194220: beq         $t3, $t8, L_8019425C
    if (ctx->r11 == ctx->r24) {
        // 0x80194224: nop
    
            goto L_8019425C;
    }
    // 0x80194224: nop

    // 0x80194228: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x8019422C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80194230: sll         $t2, $t4, 2
    ctx->r10 = S32(ctx->r12 << 2);
    // 0x80194234: addu        $t2, $t2, $t4
    ctx->r10 = ADD32(ctx->r10, ctx->r12);
    // 0x80194238: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x8019423C: addu        $t1, $t1, $t2
    ctx->r9 = ADD32(ctx->r9, ctx->r10);
    // 0x80194240: lhu         $t1, -0x41DE($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X41DE);
    // 0x80194244: andi        $t0, $t1, 0x1
    ctx->r8 = ctx->r9 & 0X1;
    // 0x80194248: beq         $t0, $zero, L_8019425C
    if (ctx->r8 == 0) {
        // 0x8019424C: nop
    
            goto L_8019425C;
    }
    // 0x8019424C: nop

    // 0x80194250: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80194254: b           L_80194D40
    // 0x80194258: sw          $t6, 0x20($t5)
    MEM_W(0X20, ctx->r13) = ctx->r14;
        goto L_80194D40;
    // 0x80194258: sw          $t6, 0x20($t5)
    MEM_W(0X20, ctx->r13) = ctx->r14;
L_8019425C:
    // 0x8019425C: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80194260: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80194264: lw          $t3, -0x2E3C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2E3C);
    // 0x80194268: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x8019426C: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
    // 0x80194270: sltu        $at, $t9, $t3
    ctx->r1 = ctx->r25 < ctx->r11 ? 1 : 0;
    // 0x80194274: bne         $at, $zero, L_801941B4
    if (ctx->r1 != 0) {
        // 0x80194278: nop
    
            goto L_801941B4;
    }
    // 0x80194278: nop

L_8019427C:
    // 0x8019427C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80194280: addiu       $t8, $t8, -0x2E28
    ctx->r24 = ADD32(ctx->r24, -0X2E28);
    // 0x80194284: lbu         $t4, 0xA($t8)
    ctx->r12 = MEM_BU(ctx->r24, 0XA);
    // 0x80194288: andi        $t2, $t4, 0x1
    ctx->r10 = ctx->r12 & 0X1;
    // 0x8019428C: beq         $t2, $zero, L_80194D40
    if (ctx->r10 == 0) {
        // 0x80194290: nop
    
            goto L_80194D40;
    }
    // 0x80194290: nop

    // 0x80194294: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80194298: lw          $t1, -0x2E3C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2E3C);
    // 0x8019429C: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x801942A0: beq         $t1, $zero, L_80194D40
    if (ctx->r9 == 0) {
        // 0x801942A4: nop
    
            goto L_80194D40;
    }
    // 0x801942A4: nop

L_801942A8:
    // 0x801942A8: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x801942AC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801942B0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801942B4: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x801942B8: addu        $t7, $t7, $t0
    ctx->r15 = ADD32(ctx->r15, ctx->r8);
    // 0x801942BC: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x801942C0: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x801942C4: lhu         $t9, -0x41DC($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X41DC);
    // 0x801942C8: sllv        $t5, $t6, $t0
    ctx->r13 = S32(ctx->r14 << (ctx->r8 & 31));
    // 0x801942CC: sb          $t5, 0x37($sp)
    MEM_B(0X37, ctx->r29) = ctx->r13;
    // 0x801942D0: andi        $t3, $t9, 0x100
    ctx->r11 = ctx->r25 & 0X100;
    // 0x801942D4: beq         $t3, $zero, L_801943BC
    if (ctx->r11 == 0) {
        // 0x801942D8: nop
    
            goto L_801943BC;
    }
    // 0x801942D8: nop

L_801942DC:
    // 0x801942DC: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x801942E0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x801942E4: addiu       $t2, $t2, 0x39A0
    ctx->r10 = ADD32(ctx->r10, 0X39A0);
    // 0x801942E8: sll         $t4, $t8, 5
    ctx->r12 = S32(ctx->r24 << 5);
    // 0x801942EC: addu        $t1, $t4, $t2
    ctx->r9 = ADD32(ctx->r12, ctx->r10);
    // 0x801942F0: lw          $t6, 0x8($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X8);
    // 0x801942F4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801942F8: addiu       $t9, $t9, 0x39A0
    ctx->r25 = ADD32(ctx->r25, 0X39A0);
    // 0x801942FC: addiu       $t5, $t6, 0x1
    ctx->r13 = ADD32(ctx->r14, 0X1);
    // 0x80194300: sw          $t5, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r13;
    // 0x80194304: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80194308: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8019430C: sll         $t7, $t0, 5
    ctx->r15 = S32(ctx->r8 << 5);
    // 0x80194310: addu        $t3, $t7, $t9
    ctx->r11 = ADD32(ctx->r15, ctx->r25);
    // 0x80194314: lw          $t8, 0x8($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X8);
    // 0x80194318: bne         $t8, $at, L_80194324
    if (ctx->r24 != ctx->r1) {
        // 0x8019431C: nop
    
            goto L_80194324;
    }
    // 0x8019431C: nop

    // 0x80194320: sw          $zero, 0x8($t3)
    MEM_W(0X8, ctx->r11) = 0;
L_80194324:
    // 0x80194324: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80194328: lw          $t4, -0x2E3C($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2E3C);
    // 0x8019432C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80194330: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x80194334: beq         $t4, $zero, L_801943A0
    if (ctx->r12 == 0) {
        // 0x80194338: nop
    
            goto L_801943A0;
    }
    // 0x80194338: nop

L_8019433C:
    // 0x8019433C: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80194340: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80194344: beq         $t2, $t6, L_80194380
    if (ctx->r10 == ctx->r14) {
        // 0x80194348: nop
    
            goto L_80194380;
    }
    // 0x80194348: nop

    // 0x8019434C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80194350: addiu       $t1, $t1, 0x39A0
    ctx->r9 = ADD32(ctx->r9, 0X39A0);
    // 0x80194354: sll         $t5, $t6, 5
    ctx->r13 = S32(ctx->r14 << 5);
    // 0x80194358: sll         $t9, $t2, 5
    ctx->r25 = S32(ctx->r10 << 5);
    // 0x8019435C: addu        $t8, $t9, $t1
    ctx->r24 = ADD32(ctx->r25, ctx->r9);
    // 0x80194360: addu        $t0, $t5, $t1
    ctx->r8 = ADD32(ctx->r13, ctx->r9);
    // 0x80194364: lw          $t7, 0x8($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X8);
    // 0x80194368: lw          $t3, 0x8($t8)
    ctx->r11 = MEM_W(ctx->r24, 0X8);
    // 0x8019436C: bne         $t7, $t3, L_80194380
    if (ctx->r15 != ctx->r11) {
        // 0x80194370: nop
    
            goto L_80194380;
    }
    // 0x80194370: nop

    // 0x80194374: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80194378: addiu       $t6, $t4, 0x1
    ctx->r14 = ADD32(ctx->r12, 0X1);
    // 0x8019437C: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
L_80194380:
    // 0x80194380: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x80194384: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80194388: lw          $t2, -0x2E3C($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2E3C);
    // 0x8019438C: addiu       $t0, $t5, 0x1
    ctx->r8 = ADD32(ctx->r13, 0X1);
    // 0x80194390: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x80194394: sltu        $at, $t0, $t2
    ctx->r1 = ctx->r8 < ctx->r10 ? 1 : 0;
    // 0x80194398: bne         $at, $zero, L_8019433C
    if (ctx->r1 != 0) {
        // 0x8019439C: nop
    
            goto L_8019433C;
    }
    // 0x8019439C: nop

L_801943A0:
    // 0x801943A0: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x801943A4: bne         $t9, $zero, L_801942DC
    if (ctx->r25 != 0) {
        // 0x801943A8: nop
    
            goto L_801942DC;
    }
    // 0x801943A8: nop

    // 0x801943AC: jal         0x800C8544
    // 0x801943B0: addiu       $a0, $zero, 0x7B
    ctx->r4 = ADD32(0, 0X7B);
    func_800C8544(rdram, ctx);
        goto after_4;
    // 0x801943B0: addiu       $a0, $zero, 0x7B
    ctx->r4 = ADD32(0, 0X7B);
    after_4:
    // 0x801943B4: b           L_801944E0
    // 0x801943B8: nop

        goto L_801944E0;
    // 0x801943B8: nop

L_801943BC:
    // 0x801943BC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x801943C0: addiu       $t1, $t1, -0x2E28
    ctx->r9 = ADD32(ctx->r9, -0X2E28);
    // 0x801943C4: lbu         $t8, 0xD($t1)
    ctx->r24 = MEM_BU(ctx->r9, 0XD);
    // 0x801943C8: lbu         $t7, 0x37($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X37);
    // 0x801943CC: and         $t3, $t8, $t7
    ctx->r11 = ctx->r24 & ctx->r15;
    // 0x801943D0: bne         $t3, $zero, L_801944E0
    if (ctx->r11 != 0) {
        // 0x801943D4: nop
    
            goto L_801944E0;
    }
    // 0x801943D4: nop

    // 0x801943D8: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x801943DC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x801943E0: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x801943E4: addu        $t6, $t6, $t4
    ctx->r14 = ADD32(ctx->r14, ctx->r12);
    // 0x801943E8: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x801943EC: addu        $t5, $t5, $t6
    ctx->r13 = ADD32(ctx->r13, ctx->r14);
    // 0x801943F0: lb          $t5, -0x41DA($t5)
    ctx->r13 = MEM_B(ctx->r13, -0X41DA);
    // 0x801943F4: slti        $at, $t5, 0xF
    ctx->r1 = SIGNED(ctx->r13) < 0XF ? 1 : 0;
    // 0x801943F8: bne         $at, $zero, L_801944E0
    if (ctx->r1 != 0) {
        // 0x801943FC: nop
    
            goto L_801944E0;
    }
    // 0x801943FC: nop

    // 0x80194400: or          $t0, $t8, $t7
    ctx->r8 = ctx->r24 | ctx->r15;
    // 0x80194404: sb          $t0, 0xD($t1)
    MEM_B(0XD, ctx->r9) = ctx->r8;
L_80194408:
    // 0x80194408: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x8019440C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80194410: addiu       $t3, $t3, 0x39A0
    ctx->r11 = ADD32(ctx->r11, 0X39A0);
    // 0x80194414: sll         $t9, $t2, 5
    ctx->r25 = S32(ctx->r10 << 5);
    // 0x80194418: addu        $t4, $t9, $t3
    ctx->r12 = ADD32(ctx->r25, ctx->r11);
    // 0x8019441C: lw          $t6, 0x8($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X8);
    // 0x80194420: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80194424: addiu       $t0, $t0, 0x39A0
    ctx->r8 = ADD32(ctx->r8, 0X39A0);
    // 0x80194428: addiu       $t5, $t6, 0x1
    ctx->r13 = ADD32(ctx->r14, 0X1);
    // 0x8019442C: sw          $t5, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r13;
    // 0x80194430: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80194434: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80194438: sll         $t7, $t8, 5
    ctx->r15 = S32(ctx->r24 << 5);
    // 0x8019443C: addu        $t1, $t7, $t0
    ctx->r9 = ADD32(ctx->r15, ctx->r8);
    // 0x80194440: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x80194444: bne         $t2, $at, L_80194450
    if (ctx->r10 != ctx->r1) {
        // 0x80194448: nop
    
            goto L_80194450;
    }
    // 0x80194448: nop

    // 0x8019444C: sw          $zero, 0x8($t1)
    MEM_W(0X8, ctx->r9) = 0;
L_80194450:
    // 0x80194450: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80194454: lw          $t9, -0x2E3C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2E3C);
    // 0x80194458: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8019445C: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x80194460: beq         $t9, $zero, L_801944CC
    if (ctx->r25 == 0) {
        // 0x80194464: nop
    
            goto L_801944CC;
    }
    // 0x80194464: nop

L_80194468:
    // 0x80194468: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x8019446C: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80194470: beq         $t3, $t6, L_801944AC
    if (ctx->r11 == ctx->r14) {
        // 0x80194474: nop
    
            goto L_801944AC;
    }
    // 0x80194474: nop

    // 0x80194478: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8019447C: addiu       $t4, $t4, 0x39A0
    ctx->r12 = ADD32(ctx->r12, 0X39A0);
    // 0x80194480: sll         $t5, $t6, 5
    ctx->r13 = S32(ctx->r14 << 5);
    // 0x80194484: sll         $t0, $t3, 5
    ctx->r8 = S32(ctx->r11 << 5);
    // 0x80194488: addu        $t2, $t0, $t4
    ctx->r10 = ADD32(ctx->r8, ctx->r12);
    // 0x8019448C: addu        $t8, $t5, $t4
    ctx->r24 = ADD32(ctx->r13, ctx->r12);
    // 0x80194490: lw          $t7, 0x8($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X8);
    // 0x80194494: lw          $t1, 0x8($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X8);
    // 0x80194498: bne         $t7, $t1, L_801944AC
    if (ctx->r15 != ctx->r9) {
        // 0x8019449C: nop
    
            goto L_801944AC;
    }
    // 0x8019449C: nop

    // 0x801944A0: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x801944A4: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x801944A8: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
L_801944AC:
    // 0x801944AC: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x801944B0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x801944B4: lw          $t3, -0x2E3C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2E3C);
    // 0x801944B8: addiu       $t8, $t5, 0x1
    ctx->r24 = ADD32(ctx->r13, 0X1);
    // 0x801944BC: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x801944C0: sltu        $at, $t8, $t3
    ctx->r1 = ctx->r24 < ctx->r11 ? 1 : 0;
    // 0x801944C4: bne         $at, $zero, L_80194468
    if (ctx->r1 != 0) {
        // 0x801944C8: nop
    
            goto L_80194468;
    }
    // 0x801944C8: nop

L_801944CC:
    // 0x801944CC: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x801944D0: bne         $t0, $zero, L_80194408
    if (ctx->r8 != 0) {
        // 0x801944D4: nop
    
            goto L_80194408;
    }
    // 0x801944D4: nop

    // 0x801944D8: jal         0x800C8544
    // 0x801944DC: addiu       $a0, $zero, 0x7B
    ctx->r4 = ADD32(0, 0X7B);
    func_800C8544(rdram, ctx);
        goto after_5;
    // 0x801944DC: addiu       $a0, $zero, 0x7B
    ctx->r4 = ADD32(0, 0X7B);
    after_5:
L_801944E0:
    // 0x801944E0: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x801944E4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801944E8: sll         $t2, $t4, 2
    ctx->r10 = S32(ctx->r12 << 2);
    // 0x801944EC: addu        $t2, $t2, $t4
    ctx->r10 = ADD32(ctx->r10, ctx->r12);
    // 0x801944F0: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x801944F4: addu        $t7, $t7, $t2
    ctx->r15 = ADD32(ctx->r15, ctx->r10);
    // 0x801944F8: lhu         $t7, -0x41DC($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X41DC);
    // 0x801944FC: andi        $t1, $t7, 0x200
    ctx->r9 = ctx->r15 & 0X200;
    // 0x80194500: beq         $t1, $zero, L_801945EC
    if (ctx->r9 == 0) {
        // 0x80194504: nop
    
            goto L_801945EC;
    }
    // 0x80194504: nop

L_80194508:
    // 0x80194508: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x8019450C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80194510: addiu       $t5, $t5, 0x39A0
    ctx->r13 = ADD32(ctx->r13, 0X39A0);
    // 0x80194514: sll         $t6, $t9, 5
    ctx->r14 = S32(ctx->r25 << 5);
    // 0x80194518: addu        $t8, $t6, $t5
    ctx->r24 = ADD32(ctx->r14, ctx->r13);
    // 0x8019451C: lw          $t3, 0x8($t8)
    ctx->r11 = MEM_W(ctx->r24, 0X8);
    // 0x80194520: bne         $t3, $zero, L_80194534
    if (ctx->r11 != 0) {
        // 0x80194524: nop
    
            goto L_80194534;
    }
    // 0x80194524: nop

    // 0x80194528: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x8019452C: b           L_80194554
    // 0x80194530: sw          $t0, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r8;
        goto L_80194554;
    // 0x80194530: sw          $t0, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r8;
L_80194534:
    // 0x80194534: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80194538: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8019453C: addiu       $t7, $t7, 0x39A0
    ctx->r15 = ADD32(ctx->r15, 0X39A0);
    // 0x80194540: sll         $t2, $t4, 5
    ctx->r10 = S32(ctx->r12 << 5);
    // 0x80194544: addu        $t1, $t2, $t7
    ctx->r9 = ADD32(ctx->r10, ctx->r15);
    // 0x80194548: lw          $t9, 0x8($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X8);
    // 0x8019454C: addiu       $t6, $t9, -0x1
    ctx->r14 = ADD32(ctx->r25, -0X1);
    // 0x80194550: sw          $t6, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r14;
L_80194554:
    // 0x80194554: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80194558: lw          $t5, -0x2E3C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2E3C);
    // 0x8019455C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80194560: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x80194564: beq         $t5, $zero, L_801945D0
    if (ctx->r13 == 0) {
        // 0x80194568: nop
    
            goto L_801945D0;
    }
    // 0x80194568: nop

L_8019456C:
    // 0x8019456C: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x80194570: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80194574: beq         $t3, $t0, L_801945B0
    if (ctx->r11 == ctx->r8) {
        // 0x80194578: nop
    
            goto L_801945B0;
    }
    // 0x80194578: nop

    // 0x8019457C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80194580: addiu       $t4, $t4, 0x39A0
    ctx->r12 = ADD32(ctx->r12, 0X39A0);
    // 0x80194584: sll         $t8, $t0, 5
    ctx->r24 = S32(ctx->r8 << 5);
    // 0x80194588: sll         $t9, $t3, 5
    ctx->r25 = S32(ctx->r11 << 5);
    // 0x8019458C: addu        $t6, $t9, $t4
    ctx->r14 = ADD32(ctx->r25, ctx->r12);
    // 0x80194590: addu        $t2, $t8, $t4
    ctx->r10 = ADD32(ctx->r24, ctx->r12);
    // 0x80194594: lw          $t7, 0x8($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X8);
    // 0x80194598: lw          $t1, 0x8($t6)
    ctx->r9 = MEM_W(ctx->r14, 0X8);
    // 0x8019459C: bne         $t7, $t1, L_801945B0
    if (ctx->r15 != ctx->r9) {
        // 0x801945A0: nop
    
            goto L_801945B0;
    }
    // 0x801945A0: nop

    // 0x801945A4: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x801945A8: addiu       $t0, $t5, 0x1
    ctx->r8 = ADD32(ctx->r13, 0X1);
    // 0x801945AC: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
L_801945B0:
    // 0x801945B0: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x801945B4: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x801945B8: lw          $t3, -0x2E3C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2E3C);
    // 0x801945BC: addiu       $t2, $t8, 0x1
    ctx->r10 = ADD32(ctx->r24, 0X1);
    // 0x801945C0: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x801945C4: sltu        $at, $t2, $t3
    ctx->r1 = ctx->r10 < ctx->r11 ? 1 : 0;
    // 0x801945C8: bne         $at, $zero, L_8019456C
    if (ctx->r1 != 0) {
        // 0x801945CC: nop
    
            goto L_8019456C;
    }
    // 0x801945CC: nop

L_801945D0:
    // 0x801945D0: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x801945D4: bne         $t9, $zero, L_80194508
    if (ctx->r25 != 0) {
        // 0x801945D8: nop
    
            goto L_80194508;
    }
    // 0x801945D8: nop

    // 0x801945DC: jal         0x800C8544
    // 0x801945E0: addiu       $a0, $zero, 0x7B
    ctx->r4 = ADD32(0, 0X7B);
    func_800C8544(rdram, ctx);
        goto after_6;
    // 0x801945E0: addiu       $a0, $zero, 0x7B
    ctx->r4 = ADD32(0, 0X7B);
    after_6:
    // 0x801945E4: b           L_80194714
    // 0x801945E8: nop

        goto L_80194714;
    // 0x801945E8: nop

L_801945EC:
    // 0x801945EC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x801945F0: addiu       $t4, $t4, -0x2E28
    ctx->r12 = ADD32(ctx->r12, -0X2E28);
    // 0x801945F4: lbu         $t6, 0xD($t4)
    ctx->r14 = MEM_BU(ctx->r12, 0XD);
    // 0x801945F8: lbu         $t7, 0x37($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X37);
    // 0x801945FC: and         $t1, $t6, $t7
    ctx->r9 = ctx->r14 & ctx->r15;
    // 0x80194600: bne         $t1, $zero, L_80194714
    if (ctx->r9 != 0) {
        // 0x80194604: nop
    
            goto L_80194714;
    }
    // 0x80194604: nop

    // 0x80194608: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x8019460C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80194610: sll         $t0, $t5, 2
    ctx->r8 = S32(ctx->r13 << 2);
    // 0x80194614: addu        $t0, $t0, $t5
    ctx->r8 = ADD32(ctx->r8, ctx->r13);
    // 0x80194618: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x8019461C: addu        $t8, $t8, $t0
    ctx->r24 = ADD32(ctx->r24, ctx->r8);
    // 0x80194620: lb          $t8, -0x41DA($t8)
    ctx->r24 = MEM_B(ctx->r24, -0X41DA);
    // 0x80194624: slti        $at, $t8, -0xE
    ctx->r1 = SIGNED(ctx->r24) < -0XE ? 1 : 0;
    // 0x80194628: beq         $at, $zero, L_80194714
    if (ctx->r1 == 0) {
        // 0x8019462C: nop
    
            goto L_80194714;
    }
    // 0x8019462C: nop

    // 0x80194630: or          $t2, $t6, $t7
    ctx->r10 = ctx->r14 | ctx->r15;
    // 0x80194634: sb          $t2, 0xD($t4)
    MEM_B(0XD, ctx->r12) = ctx->r10;
L_80194638:
    // 0x80194638: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x8019463C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80194640: addiu       $t1, $t1, 0x39A0
    ctx->r9 = ADD32(ctx->r9, 0X39A0);
    // 0x80194644: sll         $t9, $t3, 5
    ctx->r25 = S32(ctx->r11 << 5);
    // 0x80194648: addu        $t5, $t9, $t1
    ctx->r13 = ADD32(ctx->r25, ctx->r9);
    // 0x8019464C: lw          $t0, 0x8($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X8);
    // 0x80194650: bne         $t0, $zero, L_80194664
    if (ctx->r8 != 0) {
        // 0x80194654: nop
    
            goto L_80194664;
    }
    // 0x80194654: nop

    // 0x80194658: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x8019465C: b           L_80194684
    // 0x80194660: sw          $t8, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r24;
        goto L_80194684;
    // 0x80194660: sw          $t8, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r24;
L_80194664:
    // 0x80194664: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80194668: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8019466C: addiu       $t2, $t2, 0x39A0
    ctx->r10 = ADD32(ctx->r10, 0X39A0);
    // 0x80194670: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x80194674: addu        $t4, $t7, $t2
    ctx->r12 = ADD32(ctx->r15, ctx->r10);
    // 0x80194678: lw          $t3, 0x8($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X8);
    // 0x8019467C: addiu       $t9, $t3, -0x1
    ctx->r25 = ADD32(ctx->r11, -0X1);
    // 0x80194680: sw          $t9, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r25;
L_80194684:
    // 0x80194684: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80194688: lw          $t1, -0x2E3C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2E3C);
    // 0x8019468C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80194690: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x80194694: beq         $t1, $zero, L_80194700
    if (ctx->r9 == 0) {
        // 0x80194698: nop
    
            goto L_80194700;
    }
    // 0x80194698: nop

L_8019469C:
    // 0x8019469C: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x801946A0: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x801946A4: beq         $t0, $t8, L_801946E0
    if (ctx->r8 == ctx->r24) {
        // 0x801946A8: nop
    
            goto L_801946E0;
    }
    // 0x801946A8: nop

    // 0x801946AC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801946B0: addiu       $t6, $t6, 0x39A0
    ctx->r14 = ADD32(ctx->r14, 0X39A0);
    // 0x801946B4: sll         $t5, $t8, 5
    ctx->r13 = S32(ctx->r24 << 5);
    // 0x801946B8: sll         $t3, $t0, 5
    ctx->r11 = S32(ctx->r8 << 5);
    // 0x801946BC: addu        $t9, $t3, $t6
    ctx->r25 = ADD32(ctx->r11, ctx->r14);
    // 0x801946C0: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x801946C4: lw          $t2, 0x8($t7)
    ctx->r10 = MEM_W(ctx->r15, 0X8);
    // 0x801946C8: lw          $t4, 0x8($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X8);
    // 0x801946CC: bne         $t2, $t4, L_801946E0
    if (ctx->r10 != ctx->r12) {
        // 0x801946D0: nop
    
            goto L_801946E0;
    }
    // 0x801946D0: nop

    // 0x801946D4: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x801946D8: addiu       $t8, $t1, 0x1
    ctx->r24 = ADD32(ctx->r9, 0X1);
    // 0x801946DC: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
L_801946E0:
    // 0x801946E0: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x801946E4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x801946E8: lw          $t0, -0x2E3C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2E3C);
    // 0x801946EC: addiu       $t7, $t5, 0x1
    ctx->r15 = ADD32(ctx->r13, 0X1);
    // 0x801946F0: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x801946F4: sltu        $at, $t7, $t0
    ctx->r1 = ctx->r15 < ctx->r8 ? 1 : 0;
    // 0x801946F8: bne         $at, $zero, L_8019469C
    if (ctx->r1 != 0) {
        // 0x801946FC: nop
    
            goto L_8019469C;
    }
    // 0x801946FC: nop

L_80194700:
    // 0x80194700: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80194704: bne         $t3, $zero, L_80194638
    if (ctx->r11 != 0) {
        // 0x80194708: nop
    
            goto L_80194638;
    }
    // 0x80194708: nop

    // 0x8019470C: jal         0x800C8544
    // 0x80194710: addiu       $a0, $zero, 0x7B
    ctx->r4 = ADD32(0, 0X7B);
    func_800C8544(rdram, ctx);
        goto after_7;
    // 0x80194710: addiu       $a0, $zero, 0x7B
    ctx->r4 = ADD32(0, 0X7B);
    after_7:
L_80194714:
    // 0x80194714: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80194718: addiu       $t6, $t6, -0x2E28
    ctx->r14 = ADD32(ctx->r14, -0X2E28);
    // 0x8019471C: lbu         $t9, 0xD($t6)
    ctx->r25 = MEM_BU(ctx->r14, 0XD);
    // 0x80194720: lbu         $t2, 0x37($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X37);
    // 0x80194724: and         $t4, $t9, $t2
    ctx->r12 = ctx->r25 & ctx->r10;
    // 0x80194728: beq         $t4, $zero, L_801947A4
    if (ctx->r12 == 0) {
        // 0x8019472C: nop
    
            goto L_801947A4;
    }
    // 0x8019472C: nop

    // 0x80194730: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80194734: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80194738: sll         $t8, $t1, 2
    ctx->r24 = S32(ctx->r9 << 2);
    // 0x8019473C: addu        $t8, $t8, $t1
    ctx->r24 = ADD32(ctx->r24, ctx->r9);
    // 0x80194740: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x80194744: addu        $t5, $t5, $t8
    ctx->r13 = ADD32(ctx->r13, ctx->r24);
    // 0x80194748: lb          $t5, -0x41DA($t5)
    ctx->r13 = MEM_B(ctx->r13, -0X41DA);
    // 0x8019474C: blez        $t5, L_8019475C
    if (SIGNED(ctx->r13) <= 0) {
        // 0x80194750: nop
    
            goto L_8019475C;
    }
    // 0x80194750: nop

    // 0x80194754: b           L_8019477C
    // 0x80194758: or          $s0, $t5, $zero
    ctx->r16 = ctx->r13 | 0;
        goto L_8019477C;
    // 0x80194758: or          $s0, $t5, $zero
    ctx->r16 = ctx->r13 | 0;
L_8019475C:
    // 0x8019475C: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80194760: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80194764: sll         $t0, $t7, 2
    ctx->r8 = S32(ctx->r15 << 2);
    // 0x80194768: addu        $t0, $t0, $t7
    ctx->r8 = ADD32(ctx->r8, ctx->r15);
    // 0x8019476C: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x80194770: addu        $s0, $s0, $t0
    ctx->r16 = ADD32(ctx->r16, ctx->r8);
    // 0x80194774: lb          $s0, -0x41DA($s0)
    ctx->r16 = MEM_B(ctx->r16, -0X41DA);
    // 0x80194778: negu        $s0, $s0
    ctx->r16 = SUB32(0, ctx->r16);
L_8019477C:
    // 0x8019477C: slti        $at, $s0, 0x5
    ctx->r1 = SIGNED(ctx->r16) < 0X5 ? 1 : 0;
    // 0x80194780: beq         $at, $zero, L_801947A4
    if (ctx->r1 == 0) {
        // 0x80194784: nop
    
            goto L_801947A4;
    }
    // 0x80194784: nop

    // 0x80194788: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8019478C: lbu         $t9, 0x37($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X37);
    // 0x80194790: addiu       $t3, $t3, -0x2E28
    ctx->r11 = ADD32(ctx->r11, -0X2E28);
    // 0x80194794: lbu         $t6, 0xD($t3)
    ctx->r14 = MEM_BU(ctx->r11, 0XD);
    // 0x80194798: xori        $t2, $t9, 0xFF
    ctx->r10 = ctx->r25 ^ 0XFF;
    // 0x8019479C: and         $t4, $t6, $t2
    ctx->r12 = ctx->r14 & ctx->r10;
    // 0x801947A0: sb          $t4, 0xD($t3)
    MEM_B(0XD, ctx->r11) = ctx->r12;
L_801947A4:
    // 0x801947A4: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x801947A8: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x801947AC: lw          $t5, -0x2E3C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2E3C);
    // 0x801947B0: addiu       $t8, $t1, 0x1
    ctx->r24 = ADD32(ctx->r9, 0X1);
    // 0x801947B4: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x801947B8: sltu        $at, $t8, $t5
    ctx->r1 = ctx->r24 < ctx->r13 ? 1 : 0;
    // 0x801947BC: bne         $at, $zero, L_801942A8
    if (ctx->r1 != 0) {
        // 0x801947C0: nop
    
            goto L_801942A8;
    }
    // 0x801947C0: nop

    // 0x801947C4: b           L_80194D40
    // 0x801947C8: nop

        goto L_80194D40;
    // 0x801947C8: nop

L_801947CC:
    // 0x801947CC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801947D0: addiu       $t7, $t7, -0x2E18
    ctx->r15 = ADD32(ctx->r15, -0X2E18);
    // 0x801947D4: lw          $s0, 0x20($t7)
    ctx->r16 = MEM_W(ctx->r15, 0X20);
    // 0x801947D8: beq         $s0, $zero, L_80194870
    if (ctx->r16 == 0) {
        // 0x801947DC: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80194870;
    }
    // 0x801947DC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801947E0: beq         $s0, $at, L_801947F8
    if (ctx->r16 == ctx->r1) {
        // 0x801947E4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_801947F8;
    }
    // 0x801947E4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801947E8: beq         $s0, $at, L_80194834
    if (ctx->r16 == ctx->r1) {
        // 0x801947EC: nop
    
            goto L_80194834;
    }
    // 0x801947EC: nop

    // 0x801947F0: b           L_80194928
    // 0x801947F4: nop

        goto L_80194928;
    // 0x801947F4: nop

L_801947F8:
    // 0x801947F8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x801947FC: addiu       $t0, $t0, -0x2E18
    ctx->r8 = ADD32(ctx->r8, -0X2E18);
    // 0x80194800: lw          $t9, 0x18($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X18);
    // 0x80194804: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80194808: addiu       $t2, $t2, -0x2E18
    ctx->r10 = ADD32(ctx->r10, -0X2E18);
    // 0x8019480C: addiu       $t6, $t9, -0x28
    ctx->r14 = ADD32(ctx->r25, -0X28);
    // 0x80194810: sw          $t6, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->r14;
    // 0x80194814: lw          $t4, 0x18($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X18);
    // 0x80194818: addiu       $at, $zero, 0x140
    ctx->r1 = ADD32(0, 0X140);
    // 0x8019481C: divu        $zero, $t4, $at
    lo = S32(U32(ctx->r12) / U32(ctx->r1)); hi = S32(U32(ctx->r12) % U32(ctx->r1));
    // 0x80194820: mfhi        $t3
    ctx->r11 = hi;
    // 0x80194824: bne         $t3, $zero, L_80194928
    if (ctx->r11 != 0) {
        // 0x80194828: nop
    
            goto L_80194928;
    }
    // 0x80194828: nop

    // 0x8019482C: b           L_80194928
    // 0x80194830: sw          $zero, 0x20($t2)
    MEM_W(0X20, ctx->r10) = 0;
        goto L_80194928;
    // 0x80194830: sw          $zero, 0x20($t2)
    MEM_W(0X20, ctx->r10) = 0;
L_80194834:
    // 0x80194834: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80194838: addiu       $t1, $t1, -0x2E18
    ctx->r9 = ADD32(ctx->r9, -0X2E18);
    // 0x8019483C: lw          $t8, 0x18($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X18);
    // 0x80194840: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80194844: addiu       $t7, $t7, -0x2E18
    ctx->r15 = ADD32(ctx->r15, -0X2E18);
    // 0x80194848: addiu       $t5, $t8, 0x28
    ctx->r13 = ADD32(ctx->r24, 0X28);
    // 0x8019484C: sw          $t5, 0x18($t1)
    MEM_W(0X18, ctx->r9) = ctx->r13;
    // 0x80194850: lw          $t9, 0x18($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X18);
    // 0x80194854: addiu       $at, $zero, 0x140
    ctx->r1 = ADD32(0, 0X140);
    // 0x80194858: divu        $zero, $t9, $at
    lo = S32(U32(ctx->r25) / U32(ctx->r1)); hi = S32(U32(ctx->r25) % U32(ctx->r1));
    // 0x8019485C: mfhi        $t6
    ctx->r14 = hi;
    // 0x80194860: bne         $t6, $zero, L_80194928
    if (ctx->r14 != 0) {
        // 0x80194864: nop
    
            goto L_80194928;
    }
    // 0x80194864: nop

    // 0x80194868: b           L_80194928
    // 0x8019486C: sw          $zero, 0x20($t7)
    MEM_W(0X20, ctx->r15) = 0;
        goto L_80194928;
    // 0x8019486C: sw          $zero, 0x20($t7)
    MEM_W(0X20, ctx->r15) = 0;
L_80194870:
    // 0x80194870: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80194874: lw          $t0, -0x2E3C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2E3C);
    // 0x80194878: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x8019487C: beq         $t0, $zero, L_80194928
    if (ctx->r8 == 0) {
        // 0x80194880: nop
    
            goto L_80194928;
    }
    // 0x80194880: nop

L_80194884:
    // 0x80194884: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80194888: addiu       $t4, $t4, -0x2E18
    ctx->r12 = ADD32(ctx->r12, -0X2E18);
    // 0x8019488C: lw          $t3, 0x18($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X18);
    // 0x80194890: beq         $t3, $zero, L_801948CC
    if (ctx->r11 == 0) {
        // 0x80194894: nop
    
            goto L_801948CC;
    }
    // 0x80194894: nop

    // 0x80194898: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x8019489C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x801948A0: sll         $t8, $t2, 2
    ctx->r24 = S32(ctx->r10 << 2);
    // 0x801948A4: addu        $t8, $t8, $t2
    ctx->r24 = ADD32(ctx->r24, ctx->r10);
    // 0x801948A8: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x801948AC: addu        $t5, $t5, $t8
    ctx->r13 = ADD32(ctx->r13, ctx->r24);
    // 0x801948B0: lhu         $t5, -0x41DE($t5)
    ctx->r13 = MEM_HU(ctx->r13, -0X41DE);
    // 0x801948B4: andi        $t1, $t5, 0x2
    ctx->r9 = ctx->r13 & 0X2;
    // 0x801948B8: beq         $t1, $zero, L_80194908
    if (ctx->r9 == 0) {
        // 0x801948BC: nop
    
            goto L_80194908;
    }
    // 0x801948BC: nop

    // 0x801948C0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801948C4: b           L_80194D40
    // 0x801948C8: sw          $t9, 0x20($t4)
    MEM_W(0X20, ctx->r12) = ctx->r25;
        goto L_80194D40;
    // 0x801948C8: sw          $t9, 0x20($t4)
    MEM_W(0X20, ctx->r12) = ctx->r25;
L_801948CC:
    // 0x801948CC: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x801948D0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x801948D4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801948D8: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x801948DC: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x801948E0: addu        $t0, $t0, $t7
    ctx->r8 = ADD32(ctx->r8, ctx->r15);
    // 0x801948E4: lhu         $t0, -0x41DE($t0)
    ctx->r8 = MEM_HU(ctx->r8, -0X41DE);
    // 0x801948E8: andi        $t3, $t0, 0x1
    ctx->r11 = ctx->r8 & 0X1;
    // 0x801948EC: beq         $t3, $zero, L_80194908
    if (ctx->r11 == 0) {
        // 0x801948F0: nop
    
            goto L_80194908;
    }
    // 0x801948F0: nop

    // 0x801948F4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x801948F8: addiu       $t8, $t8, -0x2E18
    ctx->r24 = ADD32(ctx->r24, -0X2E18);
    // 0x801948FC: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x80194900: b           L_80194D40
    // 0x80194904: sw          $t2, 0x20($t8)
    MEM_W(0X20, ctx->r24) = ctx->r10;
        goto L_80194D40;
    // 0x80194904: sw          $t2, 0x20($t8)
    MEM_W(0X20, ctx->r24) = ctx->r10;
L_80194908:
    // 0x80194908: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x8019490C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80194910: lw          $t9, -0x2E3C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2E3C);
    // 0x80194914: addiu       $t1, $t5, 0x1
    ctx->r9 = ADD32(ctx->r13, 0X1);
    // 0x80194918: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x8019491C: sltu        $at, $t1, $t9
    ctx->r1 = ctx->r9 < ctx->r25 ? 1 : 0;
    // 0x80194920: bne         $at, $zero, L_80194884
    if (ctx->r1 != 0) {
        // 0x80194924: nop
    
            goto L_80194884;
    }
    // 0x80194924: nop

L_80194928:
    // 0x80194928: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8019492C: addiu       $t4, $t4, -0x2E28
    ctx->r12 = ADD32(ctx->r12, -0X2E28);
    // 0x80194930: lbu         $t6, 0xA($t4)
    ctx->r14 = MEM_BU(ctx->r12, 0XA);
    // 0x80194934: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80194938: beq         $t7, $zero, L_80194D40
    if (ctx->r15 == 0) {
        // 0x8019493C: nop
    
            goto L_80194D40;
    }
    // 0x8019493C: nop

    // 0x80194940: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80194944: lw          $t0, -0x2E3C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2E3C);
    // 0x80194948: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x8019494C: beq         $t0, $zero, L_80194A10
    if (ctx->r8 == 0) {
        // 0x80194950: nop
    
            goto L_80194A10;
    }
    // 0x80194950: nop

L_80194954:
    // 0x80194954: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80194958: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8019495C: addiu       $t3, $t3, -0x2E28
    ctx->r11 = ADD32(ctx->r11, -0X2E28);
    // 0x80194960: lbu         $t2, 0xD($t3)
    ctx->r10 = MEM_BU(ctx->r11, 0XD);
    // 0x80194964: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80194968: sllv        $t1, $t5, $t8
    ctx->r9 = S32(ctx->r13 << (ctx->r24 & 31));
    // 0x8019496C: and         $t9, $t2, $t1
    ctx->r25 = ctx->r10 & ctx->r9;
    // 0x80194970: beq         $t9, $zero, L_801949F0
    if (ctx->r25 == 0) {
        // 0x80194974: nop
    
            goto L_801949F0;
    }
    // 0x80194974: nop

    // 0x80194978: sll         $t4, $t8, 2
    ctx->r12 = S32(ctx->r24 << 2);
    // 0x8019497C: addu        $t4, $t4, $t8
    ctx->r12 = ADD32(ctx->r12, ctx->r24);
    // 0x80194980: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x80194984: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80194988: addu        $t6, $t6, $t4
    ctx->r14 = ADD32(ctx->r14, ctx->r12);
    // 0x8019498C: lb          $t6, -0x41DA($t6)
    ctx->r14 = MEM_B(ctx->r14, -0X41DA);
    // 0x80194990: blez        $t6, L_801949A0
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80194994: nop
    
            goto L_801949A0;
    }
    // 0x80194994: nop

    // 0x80194998: b           L_801949C0
    // 0x8019499C: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
        goto L_801949C0;
    // 0x8019499C: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
L_801949A0:
    // 0x801949A0: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x801949A4: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x801949A8: sll         $t0, $t7, 2
    ctx->r8 = S32(ctx->r15 << 2);
    // 0x801949AC: addu        $t0, $t0, $t7
    ctx->r8 = ADD32(ctx->r8, ctx->r15);
    // 0x801949B0: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x801949B4: addu        $s0, $s0, $t0
    ctx->r16 = ADD32(ctx->r16, ctx->r8);
    // 0x801949B8: lb          $s0, -0x41DA($s0)
    ctx->r16 = MEM_B(ctx->r16, -0X41DA);
    // 0x801949BC: negu        $s0, $s0
    ctx->r16 = SUB32(0, ctx->r16);
L_801949C0:
    // 0x801949C0: slti        $at, $s0, 0x6
    ctx->r1 = SIGNED(ctx->r16) < 0X6 ? 1 : 0;
    // 0x801949C4: beq         $at, $zero, L_801949F0
    if (ctx->r1 == 0) {
        // 0x801949C8: nop
    
            goto L_801949F0;
    }
    // 0x801949C8: nop

    // 0x801949CC: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x801949D0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x801949D4: addiu       $t3, $t3, -0x2E28
    ctx->r11 = ADD32(ctx->r11, -0X2E28);
    // 0x801949D8: lbu         $t5, 0xD($t3)
    ctx->r13 = MEM_BU(ctx->r11, 0XD);
    // 0x801949DC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801949E0: sllv        $t9, $t1, $t2
    ctx->r25 = S32(ctx->r9 << (ctx->r10 & 31));
    // 0x801949E4: xori        $t8, $t9, 0xFF
    ctx->r24 = ctx->r25 ^ 0XFF;
    // 0x801949E8: and         $t4, $t5, $t8
    ctx->r12 = ctx->r13 & ctx->r24;
    // 0x801949EC: sb          $t4, 0xD($t3)
    MEM_B(0XD, ctx->r11) = ctx->r12;
L_801949F0:
    // 0x801949F0: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x801949F4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x801949F8: lw          $t0, -0x2E3C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2E3C);
    // 0x801949FC: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80194A00: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x80194A04: sltu        $at, $t7, $t0
    ctx->r1 = ctx->r15 < ctx->r8 ? 1 : 0;
    // 0x80194A08: bne         $at, $zero, L_80194954
    if (ctx->r1 != 0) {
        // 0x80194A0C: nop
    
            goto L_80194954;
    }
    // 0x80194A0C: nop

L_80194A10:
    // 0x80194A10: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80194A14: addiu       $t1, $t1, -0x2E18
    ctx->r9 = ADD32(ctx->r9, -0X2E18);
    // 0x80194A18: lw          $t2, 0x18($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X18);
    // 0x80194A1C: bne         $t2, $zero, L_80194BAC
    if (ctx->r10 != 0) {
        // 0x80194A20: nop
    
            goto L_80194BAC;
    }
    // 0x80194A20: nop

    // 0x80194A24: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80194A28: addiu       $t9, $t9, 0x39A0
    ctx->r25 = ADD32(ctx->r25, 0X39A0);
    // 0x80194A2C: lw          $t5, 0x8($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X8);
    // 0x80194A30: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80194A34: beq         $t5, $at, L_80194BAC
    if (ctx->r13 == ctx->r1) {
        // 0x80194A38: nop
    
            goto L_80194BAC;
    }
    // 0x80194A38: nop

    // 0x80194A3C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80194A40: addiu       $t8, $t8, -0x41E0
    ctx->r24 = ADD32(ctx->r24, -0X41E0);
    // 0x80194A44: lhu         $t4, 0x18($t8)
    ctx->r12 = MEM_HU(ctx->r24, 0X18);
    // 0x80194A48: lhu         $t3, 0x4($t8)
    ctx->r11 = MEM_HU(ctx->r24, 0X4);
    // 0x80194A4C: or          $t6, $t4, $t3
    ctx->r14 = ctx->r12 | ctx->r11;
    // 0x80194A50: andi        $t7, $t6, 0x100
    ctx->r15 = ctx->r14 & 0X100;
    // 0x80194A54: beq         $t7, $zero, L_80194A6C
    if (ctx->r15 == 0) {
        // 0x80194A58: nop
    
            goto L_80194A6C;
    }
    // 0x80194A58: nop

    // 0x80194A5C: jal         0x80194D54
    // 0x80194A60: nop

    func_80194D54_1501A0(rdram, ctx);
        goto after_8;
    // 0x80194A60: nop

    after_8:
    // 0x80194A64: b           L_80194D40
    // 0x80194A68: nop

        goto L_80194D40;
    // 0x80194A68: nop

L_80194A6C:
    // 0x80194A6C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80194A70: addiu       $t0, $t0, -0x2E28
    ctx->r8 = ADD32(ctx->r8, -0X2E28);
    // 0x80194A74: lbu         $t1, 0xD($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0XD);
    // 0x80194A78: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x80194A7C: bne         $t2, $zero, L_80194AB0
    if (ctx->r10 != 0) {
        // 0x80194A80: nop
    
            goto L_80194AB0;
    }
    // 0x80194A80: nop

    // 0x80194A84: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80194A88: addiu       $t9, $t9, -0x41E0
    ctx->r25 = ADD32(ctx->r25, -0X41E0);
    // 0x80194A8C: lb          $t5, 0x6($t9)
    ctx->r13 = MEM_B(ctx->r25, 0X6);
    // 0x80194A90: slti        $at, $t5, 0xF
    ctx->r1 = SIGNED(ctx->r13) < 0XF ? 1 : 0;
    // 0x80194A94: bne         $at, $zero, L_80194AB0
    if (ctx->r1 != 0) {
        // 0x80194A98: nop
    
            goto L_80194AB0;
    }
    // 0x80194A98: nop

    // 0x80194A9C: ori         $t8, $t1, 0x1
    ctx->r24 = ctx->r9 | 0X1;
    // 0x80194AA0: jal         0x80194D54
    // 0x80194AA4: sb          $t8, 0xD($t0)
    MEM_B(0XD, ctx->r8) = ctx->r24;
    func_80194D54_1501A0(rdram, ctx);
        goto after_9;
    // 0x80194AA4: sb          $t8, 0xD($t0)
    MEM_B(0XD, ctx->r8) = ctx->r24;
    after_9:
    // 0x80194AA8: b           L_80194D40
    // 0x80194AAC: nop

        goto L_80194D40;
    // 0x80194AAC: nop

L_80194AB0:
    // 0x80194AB0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80194AB4: addiu       $t4, $t4, -0x2E28
    ctx->r12 = ADD32(ctx->r12, -0X2E28);
    // 0x80194AB8: lbu         $t3, 0xD($t4)
    ctx->r11 = MEM_BU(ctx->r12, 0XD);
    // 0x80194ABC: andi        $t6, $t3, 0x4
    ctx->r14 = ctx->r11 & 0X4;
    // 0x80194AC0: bne         $t6, $zero, L_80194AF4
    if (ctx->r14 != 0) {
        // 0x80194AC4: nop
    
            goto L_80194AF4;
    }
    // 0x80194AC4: nop

    // 0x80194AC8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80194ACC: addiu       $t7, $t7, -0x41E0
    ctx->r15 = ADD32(ctx->r15, -0X41E0);
    // 0x80194AD0: lb          $t2, 0x1A($t7)
    ctx->r10 = MEM_B(ctx->r15, 0X1A);
    // 0x80194AD4: slti        $at, $t2, 0xF
    ctx->r1 = SIGNED(ctx->r10) < 0XF ? 1 : 0;
    // 0x80194AD8: bne         $at, $zero, L_80194AF4
    if (ctx->r1 != 0) {
        // 0x80194ADC: nop
    
            goto L_80194AF4;
    }
    // 0x80194ADC: nop

    // 0x80194AE0: ori         $t9, $t3, 0x4
    ctx->r25 = ctx->r11 | 0X4;
    // 0x80194AE4: jal         0x80194D54
    // 0x80194AE8: sb          $t9, 0xD($t4)
    MEM_B(0XD, ctx->r12) = ctx->r25;
    func_80194D54_1501A0(rdram, ctx);
        goto after_10;
    // 0x80194AE8: sb          $t9, 0xD($t4)
    MEM_B(0XD, ctx->r12) = ctx->r25;
    after_10:
    // 0x80194AEC: b           L_80194D40
    // 0x80194AF0: nop

        goto L_80194D40;
    // 0x80194AF0: nop

L_80194AF4:
    // 0x80194AF4: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80194AF8: addiu       $t5, $t5, -0x41E0
    ctx->r13 = ADD32(ctx->r13, -0X41E0);
    // 0x80194AFC: lhu         $t1, 0x18($t5)
    ctx->r9 = MEM_HU(ctx->r13, 0X18);
    // 0x80194B00: lhu         $t8, 0x4($t5)
    ctx->r24 = MEM_HU(ctx->r13, 0X4);
    // 0x80194B04: or          $t0, $t1, $t8
    ctx->r8 = ctx->r9 | ctx->r24;
    // 0x80194B08: andi        $t6, $t0, 0x200
    ctx->r14 = ctx->r8 & 0X200;
    // 0x80194B0C: beq         $t6, $zero, L_80194B24
    if (ctx->r14 == 0) {
        // 0x80194B10: nop
    
            goto L_80194B24;
    }
    // 0x80194B10: nop

    // 0x80194B14: jal         0x80194DE0
    // 0x80194B18: nop

    func_80194DE0_1501A0(rdram, ctx);
        goto after_11;
    // 0x80194B18: nop

    after_11:
    // 0x80194B1C: b           L_80194D40
    // 0x80194B20: nop

        goto L_80194D40;
    // 0x80194B20: nop

L_80194B24:
    // 0x80194B24: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80194B28: addiu       $t7, $t7, -0x2E28
    ctx->r15 = ADD32(ctx->r15, -0X2E28);
    // 0x80194B2C: lbu         $t2, 0xD($t7)
    ctx->r10 = MEM_BU(ctx->r15, 0XD);
    // 0x80194B30: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x80194B34: bne         $t3, $zero, L_80194B68
    if (ctx->r11 != 0) {
        // 0x80194B38: nop
    
            goto L_80194B68;
    }
    // 0x80194B38: nop

    // 0x80194B3C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80194B40: addiu       $t9, $t9, -0x41E0
    ctx->r25 = ADD32(ctx->r25, -0X41E0);
    // 0x80194B44: lb          $t4, 0x6($t9)
    ctx->r12 = MEM_B(ctx->r25, 0X6);
    // 0x80194B48: slti        $at, $t4, -0xE
    ctx->r1 = SIGNED(ctx->r12) < -0XE ? 1 : 0;
    // 0x80194B4C: beq         $at, $zero, L_80194B68
    if (ctx->r1 == 0) {
        // 0x80194B50: nop
    
            goto L_80194B68;
    }
    // 0x80194B50: nop

    // 0x80194B54: ori         $t5, $t2, 0x1
    ctx->r13 = ctx->r10 | 0X1;
    // 0x80194B58: jal         0x80194DE0
    // 0x80194B5C: sb          $t5, 0xD($t7)
    MEM_B(0XD, ctx->r15) = ctx->r13;
    func_80194DE0_1501A0(rdram, ctx);
        goto after_12;
    // 0x80194B5C: sb          $t5, 0xD($t7)
    MEM_B(0XD, ctx->r15) = ctx->r13;
    after_12:
    // 0x80194B60: b           L_80194D40
    // 0x80194B64: nop

        goto L_80194D40;
    // 0x80194B64: nop

L_80194B68:
    // 0x80194B68: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80194B6C: addiu       $t1, $t1, -0x2E28
    ctx->r9 = ADD32(ctx->r9, -0X2E28);
    // 0x80194B70: lbu         $t8, 0xD($t1)
    ctx->r24 = MEM_BU(ctx->r9, 0XD);
    // 0x80194B74: andi        $t0, $t8, 0x4
    ctx->r8 = ctx->r24 & 0X4;
    // 0x80194B78: bne         $t0, $zero, L_80194BAC
    if (ctx->r8 != 0) {
        // 0x80194B7C: nop
    
            goto L_80194BAC;
    }
    // 0x80194B7C: nop

    // 0x80194B80: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80194B84: addiu       $t6, $t6, -0x41E0
    ctx->r14 = ADD32(ctx->r14, -0X41E0);
    // 0x80194B88: lb          $t3, 0x1A($t6)
    ctx->r11 = MEM_B(ctx->r14, 0X1A);
    // 0x80194B8C: slti        $at, $t3, -0xE
    ctx->r1 = SIGNED(ctx->r11) < -0XE ? 1 : 0;
    // 0x80194B90: beq         $at, $zero, L_80194BAC
    if (ctx->r1 == 0) {
        // 0x80194B94: nop
    
            goto L_80194BAC;
    }
    // 0x80194B94: nop

    // 0x80194B98: ori         $t9, $t8, 0x4
    ctx->r25 = ctx->r24 | 0X4;
    // 0x80194B9C: jal         0x80194DE0
    // 0x80194BA0: sb          $t9, 0xD($t1)
    MEM_B(0XD, ctx->r9) = ctx->r25;
    func_80194DE0_1501A0(rdram, ctx);
        goto after_13;
    // 0x80194BA0: sb          $t9, 0xD($t1)
    MEM_B(0XD, ctx->r9) = ctx->r25;
    after_13:
    // 0x80194BA4: b           L_80194D40
    // 0x80194BA8: nop

        goto L_80194D40;
    // 0x80194BA8: nop

L_80194BAC:
    // 0x80194BAC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80194BB0: addiu       $t4, $t4, -0x2E18
    ctx->r12 = ADD32(ctx->r12, -0X2E18);
    // 0x80194BB4: lw          $t2, 0x18($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X18);
    // 0x80194BB8: beq         $t2, $zero, L_80194D40
    if (ctx->r10 == 0) {
        // 0x80194BBC: nop
    
            goto L_80194D40;
    }
    // 0x80194BBC: nop

    // 0x80194BC0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80194BC4: addiu       $t5, $t5, 0x39A0
    ctx->r13 = ADD32(ctx->r13, 0X39A0);
    // 0x80194BC8: lw          $t7, 0x28($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X28);
    // 0x80194BCC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80194BD0: beq         $t7, $at, L_80194D40
    if (ctx->r15 == ctx->r1) {
        // 0x80194BD4: nop
    
            goto L_80194D40;
    }
    // 0x80194BD4: nop

    // 0x80194BD8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80194BDC: addiu       $t0, $t0, -0x41E0
    ctx->r8 = ADD32(ctx->r8, -0X41E0);
    // 0x80194BE0: lhu         $t6, 0x22($t0)
    ctx->r14 = MEM_HU(ctx->r8, 0X22);
    // 0x80194BE4: lhu         $t3, 0xE($t0)
    ctx->r11 = MEM_HU(ctx->r8, 0XE);
    // 0x80194BE8: or          $t8, $t6, $t3
    ctx->r24 = ctx->r14 | ctx->r11;
    // 0x80194BEC: andi        $t9, $t8, 0x100
    ctx->r25 = ctx->r24 & 0X100;
    // 0x80194BF0: beq         $t9, $zero, L_80194C08
    if (ctx->r25 == 0) {
        // 0x80194BF4: nop
    
            goto L_80194C08;
    }
    // 0x80194BF4: nop

    // 0x80194BF8: jal         0x80194E70
    // 0x80194BFC: nop

    func_80194E70_1501A0(rdram, ctx);
        goto after_14;
    // 0x80194BFC: nop

    after_14:
    // 0x80194C00: b           L_80194D40
    // 0x80194C04: nop

        goto L_80194D40;
    // 0x80194C04: nop

L_80194C08:
    // 0x80194C08: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80194C0C: addiu       $t1, $t1, -0x2E28
    ctx->r9 = ADD32(ctx->r9, -0X2E28);
    // 0x80194C10: lbu         $t4, 0xD($t1)
    ctx->r12 = MEM_BU(ctx->r9, 0XD);
    // 0x80194C14: andi        $t2, $t4, 0x2
    ctx->r10 = ctx->r12 & 0X2;
    // 0x80194C18: bne         $t2, $zero, L_80194C4C
    if (ctx->r10 != 0) {
        // 0x80194C1C: nop
    
            goto L_80194C4C;
    }
    // 0x80194C1C: nop

    // 0x80194C20: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80194C24: addiu       $t5, $t5, -0x41E0
    ctx->r13 = ADD32(ctx->r13, -0X41E0);
    // 0x80194C28: lb          $t7, 0x10($t5)
    ctx->r15 = MEM_B(ctx->r13, 0X10);
    // 0x80194C2C: slti        $at, $t7, 0xF
    ctx->r1 = SIGNED(ctx->r15) < 0XF ? 1 : 0;
    // 0x80194C30: bne         $at, $zero, L_80194C4C
    if (ctx->r1 != 0) {
        // 0x80194C34: nop
    
            goto L_80194C4C;
    }
    // 0x80194C34: nop

    // 0x80194C38: ori         $t0, $t4, 0x2
    ctx->r8 = ctx->r12 | 0X2;
    // 0x80194C3C: jal         0x80194E70
    // 0x80194C40: sb          $t0, 0xD($t1)
    MEM_B(0XD, ctx->r9) = ctx->r8;
    func_80194E70_1501A0(rdram, ctx);
        goto after_15;
    // 0x80194C40: sb          $t0, 0xD($t1)
    MEM_B(0XD, ctx->r9) = ctx->r8;
    after_15:
    // 0x80194C44: b           L_80194D40
    // 0x80194C48: nop

        goto L_80194D40;
    // 0x80194C48: nop

L_80194C4C:
    // 0x80194C4C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80194C50: addiu       $t6, $t6, -0x2E28
    ctx->r14 = ADD32(ctx->r14, -0X2E28);
    // 0x80194C54: lbu         $t3, 0xD($t6)
    ctx->r11 = MEM_BU(ctx->r14, 0XD);
    // 0x80194C58: andi        $t8, $t3, 0x8
    ctx->r24 = ctx->r11 & 0X8;
    // 0x80194C5C: bne         $t8, $zero, L_80194C90
    if (ctx->r24 != 0) {
        // 0x80194C60: nop
    
            goto L_80194C90;
    }
    // 0x80194C60: nop

    // 0x80194C64: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80194C68: addiu       $t9, $t9, -0x41E0
    ctx->r25 = ADD32(ctx->r25, -0X41E0);
    // 0x80194C6C: lb          $t2, 0x24($t9)
    ctx->r10 = MEM_B(ctx->r25, 0X24);
    // 0x80194C70: slti        $at, $t2, 0xF
    ctx->r1 = SIGNED(ctx->r10) < 0XF ? 1 : 0;
    // 0x80194C74: bne         $at, $zero, L_80194C90
    if (ctx->r1 != 0) {
        // 0x80194C78: nop
    
            goto L_80194C90;
    }
    // 0x80194C78: nop

    // 0x80194C7C: ori         $t5, $t3, 0x8
    ctx->r13 = ctx->r11 | 0X8;
    // 0x80194C80: jal         0x80194E70
    // 0x80194C84: sb          $t5, 0xD($t6)
    MEM_B(0XD, ctx->r14) = ctx->r13;
    func_80194E70_1501A0(rdram, ctx);
        goto after_16;
    // 0x80194C84: sb          $t5, 0xD($t6)
    MEM_B(0XD, ctx->r14) = ctx->r13;
    after_16:
    // 0x80194C88: b           L_80194D40
    // 0x80194C8C: nop

        goto L_80194D40;
    // 0x80194C8C: nop

L_80194C90:
    // 0x80194C90: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80194C94: addiu       $t7, $t7, -0x41E0
    ctx->r15 = ADD32(ctx->r15, -0X41E0);
    // 0x80194C98: lhu         $t4, 0x22($t7)
    ctx->r12 = MEM_HU(ctx->r15, 0X22);
    // 0x80194C9C: lhu         $t0, 0xE($t7)
    ctx->r8 = MEM_HU(ctx->r15, 0XE);
    // 0x80194CA0: or          $t1, $t4, $t0
    ctx->r9 = ctx->r12 | ctx->r8;
    // 0x80194CA4: andi        $t8, $t1, 0x200
    ctx->r24 = ctx->r9 & 0X200;
    // 0x80194CA8: beq         $t8, $zero, L_80194CC0
    if (ctx->r24 == 0) {
        // 0x80194CAC: nop
    
            goto L_80194CC0;
    }
    // 0x80194CAC: nop

    // 0x80194CB0: jal         0x80194EFC
    // 0x80194CB4: nop

    func_80194EFC_1501A0(rdram, ctx);
        goto after_17;
    // 0x80194CB4: nop

    after_17:
    // 0x80194CB8: b           L_80194D40
    // 0x80194CBC: nop

        goto L_80194D40;
    // 0x80194CBC: nop

L_80194CC0:
    // 0x80194CC0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80194CC4: addiu       $t9, $t9, -0x2E28
    ctx->r25 = ADD32(ctx->r25, -0X2E28);
    // 0x80194CC8: lbu         $t2, 0xD($t9)
    ctx->r10 = MEM_BU(ctx->r25, 0XD);
    // 0x80194CCC: andi        $t3, $t2, 0x2
    ctx->r11 = ctx->r10 & 0X2;
    // 0x80194CD0: bne         $t3, $zero, L_80194D04
    if (ctx->r11 != 0) {
        // 0x80194CD4: nop
    
            goto L_80194D04;
    }
    // 0x80194CD4: nop

    // 0x80194CD8: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80194CDC: addiu       $t5, $t5, -0x41E0
    ctx->r13 = ADD32(ctx->r13, -0X41E0);
    // 0x80194CE0: lb          $t6, 0x10($t5)
    ctx->r14 = MEM_B(ctx->r13, 0X10);
    // 0x80194CE4: slti        $at, $t6, -0xE
    ctx->r1 = SIGNED(ctx->r14) < -0XE ? 1 : 0;
    // 0x80194CE8: beq         $at, $zero, L_80194D04
    if (ctx->r1 == 0) {
        // 0x80194CEC: nop
    
            goto L_80194D04;
    }
    // 0x80194CEC: nop

    // 0x80194CF0: ori         $t7, $t2, 0x2
    ctx->r15 = ctx->r10 | 0X2;
    // 0x80194CF4: jal         0x80194EFC
    // 0x80194CF8: sb          $t7, 0xD($t9)
    MEM_B(0XD, ctx->r25) = ctx->r15;
    func_80194EFC_1501A0(rdram, ctx);
        goto after_18;
    // 0x80194CF8: sb          $t7, 0xD($t9)
    MEM_B(0XD, ctx->r25) = ctx->r15;
    after_18:
    // 0x80194CFC: b           L_80194D40
    // 0x80194D00: nop

        goto L_80194D40;
    // 0x80194D00: nop

L_80194D04:
    // 0x80194D04: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80194D08: addiu       $t4, $t4, -0x2E28
    ctx->r12 = ADD32(ctx->r12, -0X2E28);
    // 0x80194D0C: lbu         $t0, 0xD($t4)
    ctx->r8 = MEM_BU(ctx->r12, 0XD);
    // 0x80194D10: andi        $t1, $t0, 0x8
    ctx->r9 = ctx->r8 & 0X8;
    // 0x80194D14: bne         $t1, $zero, L_80194D40
    if (ctx->r9 != 0) {
        // 0x80194D18: nop
    
            goto L_80194D40;
    }
    // 0x80194D18: nop

    // 0x80194D1C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80194D20: addiu       $t8, $t8, -0x41E0
    ctx->r24 = ADD32(ctx->r24, -0X41E0);
    // 0x80194D24: lb          $t3, 0x24($t8)
    ctx->r11 = MEM_B(ctx->r24, 0X24);
    // 0x80194D28: slti        $at, $t3, -0xE
    ctx->r1 = SIGNED(ctx->r11) < -0XE ? 1 : 0;
    // 0x80194D2C: beq         $at, $zero, L_80194D40
    if (ctx->r1 == 0) {
        // 0x80194D30: nop
    
            goto L_80194D40;
    }
    // 0x80194D30: nop

    // 0x80194D34: ori         $t5, $t0, 0x8
    ctx->r13 = ctx->r8 | 0X8;
    // 0x80194D38: jal         0x80194EFC
    // 0x80194D3C: sb          $t5, 0xD($t4)
    MEM_B(0XD, ctx->r12) = ctx->r13;
    func_80194EFC_1501A0(rdram, ctx);
        goto after_19;
    // 0x80194D3C: sb          $t5, 0xD($t4)
    MEM_B(0XD, ctx->r12) = ctx->r13;
    after_19:
L_80194D40:
    // 0x80194D40: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80194D44: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80194D48: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80194D4C: jr          $ra
    // 0x80194D50: nop

    return;
    // 0x80194D50: nop

;}
RECOMP_FUNC void func_80194D54_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80194D54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80194D58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
L_80194D5C:
    // 0x80194D5C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80194D60: addiu       $t6, $t6, 0x39A0
    ctx->r14 = ADD32(ctx->r14, 0X39A0);
    // 0x80194D64: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x80194D68: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80194D6C: addiu       $t9, $t9, 0x39A0
    ctx->r25 = ADD32(ctx->r25, 0X39A0);
    // 0x80194D70: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80194D74: sw          $t8, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r24;
    // 0x80194D78: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x80194D7C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80194D80: bne         $t0, $at, L_80194D8C
    if (ctx->r8 != ctx->r1) {
        // 0x80194D84: nop
    
            goto L_80194D8C;
    }
    // 0x80194D84: nop

    // 0x80194D88: sw          $zero, 0x8($t9)
    MEM_W(0X8, ctx->r25) = 0;
L_80194D8C:
    // 0x80194D8C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80194D90: addiu       $t1, $t1, 0x39A0
    ctx->r9 = ADD32(ctx->r9, 0X39A0);
    // 0x80194D94: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80194D98: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x80194D9C: addiu       $t5, $t5, -0x2E18
    ctx->r13 = ADD32(ctx->r13, -0X2E18);
    // 0x80194DA0: lw          $t7, 0x48($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X48);
    // 0x80194DA4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80194DA8: sllv        $t4, $t3, $t2
    ctx->r12 = S32(ctx->r11 << (ctx->r10 & 31));
    // 0x80194DAC: and         $t8, $t4, $t7
    ctx->r24 = ctx->r12 & ctx->r15;
    // 0x80194DB0: beq         $t8, $zero, L_80194D5C
    if (ctx->r24 == 0) {
        // 0x80194DB4: nop
    
            goto L_80194D5C;
    }
    // 0x80194DB4: nop

    // 0x80194DB8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80194DBC: addiu       $t6, $t6, 0x39A0
    ctx->r14 = ADD32(ctx->r14, 0X39A0);
    // 0x80194DC0: lw          $t0, 0x8($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X8);
    // 0x80194DC4: addiu       $a0, $zero, 0x7B
    ctx->r4 = ADD32(0, 0X7B);
    // 0x80194DC8: jal         0x800C8544
    // 0x80194DCC: sw          $t0, 0x48($t6)
    MEM_W(0X48, ctx->r14) = ctx->r8;
    func_800C8544(rdram, ctx);
        goto after_0;
    // 0x80194DCC: sw          $t0, 0x48($t6)
    MEM_W(0X48, ctx->r14) = ctx->r8;
    after_0:
    // 0x80194DD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80194DD4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80194DD8: jr          $ra
    // 0x80194DDC: nop

    return;
    // 0x80194DDC: nop

;}
RECOMP_FUNC void func_80194DE0_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80194DE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80194DE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
L_80194DE8:
    // 0x80194DE8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80194DEC: addiu       $t6, $t6, 0x39A0
    ctx->r14 = ADD32(ctx->r14, 0X39A0);
    // 0x80194DF0: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x80194DF4: bne         $t7, $zero, L_80194E08
    if (ctx->r15 != 0) {
        // 0x80194DF8: nop
    
            goto L_80194E08;
    }
    // 0x80194DF8: nop

    // 0x80194DFC: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80194E00: b           L_80194E1C
    // 0x80194E04: sw          $t8, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r24;
        goto L_80194E1C;
    // 0x80194E04: sw          $t8, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r24;
L_80194E08:
    // 0x80194E08: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80194E0C: addiu       $t9, $t9, 0x39A0
    ctx->r25 = ADD32(ctx->r25, 0X39A0);
    // 0x80194E10: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x80194E14: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x80194E18: sw          $t1, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r9;
L_80194E1C:
    // 0x80194E1C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80194E20: addiu       $t2, $t2, 0x39A0
    ctx->r10 = ADD32(ctx->r10, 0X39A0);
    // 0x80194E24: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80194E28: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x80194E2C: addiu       $t7, $t7, -0x2E18
    ctx->r15 = ADD32(ctx->r15, -0X2E18);
    // 0x80194E30: lw          $t8, 0x48($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X48);
    // 0x80194E34: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80194E38: sllv        $t5, $t4, $t3
    ctx->r13 = S32(ctx->r12 << (ctx->r11 & 31));
    // 0x80194E3C: and         $t6, $t5, $t8
    ctx->r14 = ctx->r13 & ctx->r24;
    // 0x80194E40: beq         $t6, $zero, L_80194DE8
    if (ctx->r14 == 0) {
        // 0x80194E44: nop
    
            goto L_80194DE8;
    }
    // 0x80194E44: nop

    // 0x80194E48: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80194E4C: addiu       $t0, $t0, 0x39A0
    ctx->r8 = ADD32(ctx->r8, 0X39A0);
    // 0x80194E50: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x80194E54: addiu       $a0, $zero, 0x7B
    ctx->r4 = ADD32(0, 0X7B);
    // 0x80194E58: jal         0x800C8544
    // 0x80194E5C: sw          $t1, 0x48($t0)
    MEM_W(0X48, ctx->r8) = ctx->r9;
    func_800C8544(rdram, ctx);
        goto after_0;
    // 0x80194E5C: sw          $t1, 0x48($t0)
    MEM_W(0X48, ctx->r8) = ctx->r9;
    after_0:
    // 0x80194E60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80194E64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80194E68: jr          $ra
    // 0x80194E6C: nop

    return;
    // 0x80194E6C: nop

;}
RECOMP_FUNC void func_80194E70_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80194E70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80194E74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
L_80194E78:
    // 0x80194E78: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80194E7C: addiu       $t6, $t6, 0x39A0
    ctx->r14 = ADD32(ctx->r14, 0X39A0);
    // 0x80194E80: lw          $t7, 0x28($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X28);
    // 0x80194E84: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80194E88: addiu       $t9, $t9, 0x39A0
    ctx->r25 = ADD32(ctx->r25, 0X39A0);
    // 0x80194E8C: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80194E90: sw          $t8, 0x28($t6)
    MEM_W(0X28, ctx->r14) = ctx->r24;
    // 0x80194E94: lw          $t0, 0x28($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X28);
    // 0x80194E98: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80194E9C: bne         $t0, $at, L_80194EA8
    if (ctx->r8 != ctx->r1) {
        // 0x80194EA0: nop
    
            goto L_80194EA8;
    }
    // 0x80194EA0: nop

    // 0x80194EA4: sw          $zero, 0x28($t9)
    MEM_W(0X28, ctx->r25) = 0;
L_80194EA8:
    // 0x80194EA8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80194EAC: addiu       $t1, $t1, 0x39A0
    ctx->r9 = ADD32(ctx->r9, 0X39A0);
    // 0x80194EB0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80194EB4: lw          $t2, 0x28($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X28);
    // 0x80194EB8: addiu       $t5, $t5, -0x2E18
    ctx->r13 = ADD32(ctx->r13, -0X2E18);
    // 0x80194EBC: lw          $t7, 0x4C($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X4C);
    // 0x80194EC0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80194EC4: sllv        $t4, $t3, $t2
    ctx->r12 = S32(ctx->r11 << (ctx->r10 & 31));
    // 0x80194EC8: and         $t8, $t4, $t7
    ctx->r24 = ctx->r12 & ctx->r15;
    // 0x80194ECC: beq         $t8, $zero, L_80194E78
    if (ctx->r24 == 0) {
        // 0x80194ED0: nop
    
            goto L_80194E78;
    }
    // 0x80194ED0: nop

    // 0x80194ED4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80194ED8: addiu       $t6, $t6, 0x39A0
    ctx->r14 = ADD32(ctx->r14, 0X39A0);
    // 0x80194EDC: lw          $t0, 0x28($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X28);
    // 0x80194EE0: addiu       $a0, $zero, 0x7B
    ctx->r4 = ADD32(0, 0X7B);
    // 0x80194EE4: jal         0x800C8544
    // 0x80194EE8: sw          $t0, 0x68($t6)
    MEM_W(0X68, ctx->r14) = ctx->r8;
    func_800C8544(rdram, ctx);
        goto after_0;
    // 0x80194EE8: sw          $t0, 0x68($t6)
    MEM_W(0X68, ctx->r14) = ctx->r8;
    after_0:
    // 0x80194EEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80194EF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80194EF4: jr          $ra
    // 0x80194EF8: nop

    return;
    // 0x80194EF8: nop

;}
RECOMP_FUNC void func_80194EFC_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80194EFC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80194F00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
L_80194F04:
    // 0x80194F04: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80194F08: addiu       $t6, $t6, 0x39A0
    ctx->r14 = ADD32(ctx->r14, 0X39A0);
    // 0x80194F0C: lw          $t7, 0x28($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X28);
    // 0x80194F10: bne         $t7, $zero, L_80194F24
    if (ctx->r15 != 0) {
        // 0x80194F14: nop
    
            goto L_80194F24;
    }
    // 0x80194F14: nop

    // 0x80194F18: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80194F1C: b           L_80194F38
    // 0x80194F20: sw          $t8, 0x28($t6)
    MEM_W(0X28, ctx->r14) = ctx->r24;
        goto L_80194F38;
    // 0x80194F20: sw          $t8, 0x28($t6)
    MEM_W(0X28, ctx->r14) = ctx->r24;
L_80194F24:
    // 0x80194F24: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80194F28: addiu       $t9, $t9, 0x39A0
    ctx->r25 = ADD32(ctx->r25, 0X39A0);
    // 0x80194F2C: lw          $t0, 0x28($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X28);
    // 0x80194F30: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x80194F34: sw          $t1, 0x28($t9)
    MEM_W(0X28, ctx->r25) = ctx->r9;
L_80194F38:
    // 0x80194F38: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80194F3C: addiu       $t2, $t2, 0x39A0
    ctx->r10 = ADD32(ctx->r10, 0X39A0);
    // 0x80194F40: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80194F44: lw          $t3, 0x28($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X28);
    // 0x80194F48: addiu       $t7, $t7, -0x2E18
    ctx->r15 = ADD32(ctx->r15, -0X2E18);
    // 0x80194F4C: lw          $t8, 0x4C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4C);
    // 0x80194F50: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80194F54: sllv        $t5, $t4, $t3
    ctx->r13 = S32(ctx->r12 << (ctx->r11 & 31));
    // 0x80194F58: and         $t6, $t5, $t8
    ctx->r14 = ctx->r13 & ctx->r24;
    // 0x80194F5C: beq         $t6, $zero, L_80194F04
    if (ctx->r14 == 0) {
        // 0x80194F60: nop
    
            goto L_80194F04;
    }
    // 0x80194F60: nop

    // 0x80194F64: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80194F68: addiu       $t0, $t0, 0x39A0
    ctx->r8 = ADD32(ctx->r8, 0X39A0);
    // 0x80194F6C: lw          $t1, 0x28($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X28);
    // 0x80194F70: addiu       $a0, $zero, 0x7B
    ctx->r4 = ADD32(0, 0X7B);
    // 0x80194F74: jal         0x800C8544
    // 0x80194F78: sw          $t1, 0x68($t0)
    MEM_W(0X68, ctx->r8) = ctx->r9;
    func_800C8544(rdram, ctx);
        goto after_0;
    // 0x80194F78: sw          $t1, 0x68($t0)
    MEM_W(0X68, ctx->r8) = ctx->r9;
    after_0:
    // 0x80194F7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80194F80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80194F84: jr          $ra
    // 0x80194F88: nop

    return;
    // 0x80194F88: nop

;}
RECOMP_FUNC void func_80194F8C_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80194F8C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80194F90: lw          $t6, -0x2E3C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2E3C);
    // 0x80194F94: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80194F98: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80194F9C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80194FA0: beq         $t6, $zero, L_8019526C
    if (ctx->r14 == 0) {
        // 0x80194FA4: sw          $zero, 0x28($sp)
        MEM_W(0X28, ctx->r29) = 0;
            goto L_8019526C;
    }
    // 0x80194FA4: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
L_80194FA8:
    // 0x80194FA8: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80194FAC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80194FB0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80194FB4: sll         $t0, $t7, 2
    ctx->r8 = S32(ctx->r15 << 2);
    // 0x80194FB8: addu        $t0, $t0, $t7
    ctx->r8 = ADD32(ctx->r8, ctx->r15);
    // 0x80194FBC: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x80194FC0: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80194FC4: lhu         $t1, -0x41DC($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X41DC);
    // 0x80194FC8: sllv        $t9, $t8, $t7
    ctx->r25 = S32(ctx->r24 << (ctx->r15 & 31));
    // 0x80194FCC: sb          $t9, 0x2F($sp)
    MEM_B(0X2F, ctx->r29) = ctx->r25;
    // 0x80194FD0: andi        $t2, $t1, 0x800
    ctx->r10 = ctx->r9 & 0X800;
    // 0x80194FD4: beq         $t2, $zero, L_8019501C
    if (ctx->r10 == 0) {
        // 0x80194FD8: nop
    
            goto L_8019501C;
    }
    // 0x80194FD8: nop

    // 0x80194FDC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80194FE0: addiu       $t3, $t3, -0x2E18
    ctx->r11 = ADD32(ctx->r11, -0X2E18);
    // 0x80194FE4: lw          $t4, 0x1C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X1C);
    // 0x80194FE8: beq         $t4, $zero, L_80194FFC
    if (ctx->r12 == 0) {
        // 0x80194FEC: nop
    
            goto L_80194FFC;
    }
    // 0x80194FEC: nop

    // 0x80194FF0: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x80194FF4: b           L_8019500C
    // 0x80194FF8: sw          $t5, 0x1C($t3)
    MEM_W(0X1C, ctx->r11) = ctx->r13;
        goto L_8019500C;
    // 0x80194FF8: sw          $t5, 0x1C($t3)
    MEM_W(0X1C, ctx->r11) = ctx->r13;
L_80194FFC:
    // 0x80194FFC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80195000: addiu       $t8, $t8, -0x2E18
    ctx->r24 = ADD32(ctx->r24, -0X2E18);
    // 0x80195004: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80195008: sw          $t6, 0x1C($t8)
    MEM_W(0X1C, ctx->r24) = ctx->r14;
L_8019500C:
    // 0x8019500C: jal         0x800C8544
    // 0x80195010: addiu       $a0, $zero, 0x7B
    ctx->r4 = ADD32(0, 0X7B);
    func_800C8544(rdram, ctx);
        goto after_0;
    // 0x80195010: addiu       $a0, $zero, 0x7B
    ctx->r4 = ADD32(0, 0X7B);
    after_0:
    // 0x80195014: b           L_8019526C
    // 0x80195018: nop

        goto L_8019526C;
    // 0x80195018: nop

L_8019501C:
    // 0x8019501C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80195020: addiu       $t9, $t9, -0x2E28
    ctx->r25 = ADD32(ctx->r25, -0X2E28);
    // 0x80195024: lbu         $t7, 0xD($t9)
    ctx->r15 = MEM_BU(ctx->r25, 0XD);
    // 0x80195028: lbu         $t0, 0x2F($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X2F);
    // 0x8019502C: and         $t1, $t7, $t0
    ctx->r9 = ctx->r15 & ctx->r8;
    // 0x80195030: bne         $t1, $zero, L_801950B8
    if (ctx->r9 != 0) {
        // 0x80195034: nop
    
            goto L_801950B8;
    }
    // 0x80195034: nop

    // 0x80195038: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8019503C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80195040: sll         $t4, $t2, 2
    ctx->r12 = S32(ctx->r10 << 2);
    // 0x80195044: addu        $t4, $t4, $t2
    ctx->r12 = ADD32(ctx->r12, ctx->r10);
    // 0x80195048: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x8019504C: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x80195050: lb          $t5, -0x41D9($t5)
    ctx->r13 = MEM_B(ctx->r13, -0X41D9);
    // 0x80195054: slti        $at, $t5, 0xF
    ctx->r1 = SIGNED(ctx->r13) < 0XF ? 1 : 0;
    // 0x80195058: bne         $at, $zero, L_801950B8
    if (ctx->r1 != 0) {
        // 0x8019505C: nop
    
            goto L_801950B8;
    }
    // 0x8019505C: nop

    // 0x80195060: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80195064: addiu       $t3, $t3, -0x2E18
    ctx->r11 = ADD32(ctx->r11, -0X2E18);
    // 0x80195068: lw          $t6, 0x1C($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X1C);
    // 0x8019506C: beq         $t6, $zero, L_80195084
    if (ctx->r14 == 0) {
        // 0x80195070: nop
    
            goto L_80195084;
    }
    // 0x80195070: nop

    // 0x80195074: lw          $t8, 0x1C($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X1C);
    // 0x80195078: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8019507C: b           L_80195094
    // 0x80195080: sw          $t9, 0x1C($t3)
    MEM_W(0X1C, ctx->r11) = ctx->r25;
        goto L_80195094;
    // 0x80195080: sw          $t9, 0x1C($t3)
    MEM_W(0X1C, ctx->r11) = ctx->r25;
L_80195084:
    // 0x80195084: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80195088: addiu       $t0, $t0, -0x2E18
    ctx->r8 = ADD32(ctx->r8, -0X2E18);
    // 0x8019508C: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80195090: sw          $t7, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->r15;
L_80195094:
    // 0x80195094: jal         0x800C8544
    // 0x80195098: addiu       $a0, $zero, 0x7B
    ctx->r4 = ADD32(0, 0X7B);
    func_800C8544(rdram, ctx);
        goto after_1;
    // 0x80195098: addiu       $a0, $zero, 0x7B
    ctx->r4 = ADD32(0, 0X7B);
    after_1:
    // 0x8019509C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x801950A0: addiu       $t1, $t1, -0x2E28
    ctx->r9 = ADD32(ctx->r9, -0X2E28);
    // 0x801950A4: lbu         $t2, 0xD($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0XD);
    // 0x801950A8: lbu         $t4, 0x2F($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X2F);
    // 0x801950AC: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x801950B0: b           L_8019526C
    // 0x801950B4: sb          $t5, 0xD($t1)
    MEM_B(0XD, ctx->r9) = ctx->r13;
        goto L_8019526C;
    // 0x801950B4: sb          $t5, 0xD($t1)
    MEM_B(0XD, ctx->r9) = ctx->r13;
L_801950B8:
    // 0x801950B8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x801950BC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x801950C0: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x801950C4: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x801950C8: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x801950CC: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x801950D0: lhu         $t9, -0x41DC($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X41DC);
    // 0x801950D4: andi        $t3, $t9, 0x400
    ctx->r11 = ctx->r25 & 0X400;
    // 0x801950D8: beq         $t3, $zero, L_80195120
    if (ctx->r11 == 0) {
        // 0x801950DC: nop
    
            goto L_80195120;
    }
    // 0x801950DC: nop

    // 0x801950E0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x801950E4: addiu       $t7, $t7, -0x2E18
    ctx->r15 = ADD32(ctx->r15, -0X2E18);
    // 0x801950E8: lw          $t0, 0x1C($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X1C);
    // 0x801950EC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801950F0: beq         $t0, $at, L_80195104
    if (ctx->r8 == ctx->r1) {
        // 0x801950F4: nop
    
            goto L_80195104;
    }
    // 0x801950F4: nop

    // 0x801950F8: addiu       $t2, $t0, 0x1
    ctx->r10 = ADD32(ctx->r8, 0X1);
    // 0x801950FC: b           L_80195110
    // 0x80195100: sw          $t2, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->r10;
        goto L_80195110;
    // 0x80195100: sw          $t2, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->r10;
L_80195104:
    // 0x80195104: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80195108: addiu       $t4, $t4, -0x2E18
    ctx->r12 = ADD32(ctx->r12, -0X2E18);
    // 0x8019510C: sw          $zero, 0x1C($t4)
    MEM_W(0X1C, ctx->r12) = 0;
L_80195110:
    // 0x80195110: jal         0x800C8544
    // 0x80195114: addiu       $a0, $zero, 0x7B
    ctx->r4 = ADD32(0, 0X7B);
    func_800C8544(rdram, ctx);
        goto after_2;
    // 0x80195114: addiu       $a0, $zero, 0x7B
    ctx->r4 = ADD32(0, 0X7B);
    after_2:
    // 0x80195118: b           L_8019526C
    // 0x8019511C: nop

        goto L_8019526C;
    // 0x8019511C: nop

L_80195120:
    // 0x80195120: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80195124: addiu       $t5, $t5, -0x2E28
    ctx->r13 = ADD32(ctx->r13, -0X2E28);
    // 0x80195128: lbu         $t1, 0xD($t5)
    ctx->r9 = MEM_BU(ctx->r13, 0XD);
    // 0x8019512C: lbu         $t6, 0x2F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X2F);
    // 0x80195130: and         $t8, $t1, $t6
    ctx->r24 = ctx->r9 & ctx->r14;
    // 0x80195134: bne         $t8, $zero, L_801951BC
    if (ctx->r24 != 0) {
        // 0x80195138: nop
    
            goto L_801951BC;
    }
    // 0x80195138: nop

    // 0x8019513C: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80195140: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80195144: sll         $t3, $t9, 2
    ctx->r11 = S32(ctx->r25 << 2);
    // 0x80195148: addu        $t3, $t3, $t9
    ctx->r11 = ADD32(ctx->r11, ctx->r25);
    // 0x8019514C: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x80195150: addu        $t0, $t0, $t3
    ctx->r8 = ADD32(ctx->r8, ctx->r11);
    // 0x80195154: lb          $t0, -0x41D9($t0)
    ctx->r8 = MEM_B(ctx->r8, -0X41D9);
    // 0x80195158: slti        $at, $t0, -0xE
    ctx->r1 = SIGNED(ctx->r8) < -0XE ? 1 : 0;
    // 0x8019515C: beq         $at, $zero, L_801951BC
    if (ctx->r1 == 0) {
        // 0x80195160: nop
    
            goto L_801951BC;
    }
    // 0x80195160: nop

    // 0x80195164: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80195168: addiu       $t2, $t2, -0x2E18
    ctx->r10 = ADD32(ctx->r10, -0X2E18);
    // 0x8019516C: lw          $t7, 0x1C($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X1C);
    // 0x80195170: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80195174: beq         $t7, $at, L_8019518C
    if (ctx->r15 == ctx->r1) {
        // 0x80195178: nop
    
            goto L_8019518C;
    }
    // 0x80195178: nop

    // 0x8019517C: lw          $t4, 0x1C($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X1C);
    // 0x80195180: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80195184: b           L_80195198
    // 0x80195188: sw          $t5, 0x1C($t2)
    MEM_W(0X1C, ctx->r10) = ctx->r13;
        goto L_80195198;
    // 0x80195188: sw          $t5, 0x1C($t2)
    MEM_W(0X1C, ctx->r10) = ctx->r13;
L_8019518C:
    // 0x8019518C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80195190: addiu       $t1, $t1, -0x2E18
    ctx->r9 = ADD32(ctx->r9, -0X2E18);
    // 0x80195194: sw          $zero, 0x1C($t1)
    MEM_W(0X1C, ctx->r9) = 0;
L_80195198:
    // 0x80195198: jal         0x800C8544
    // 0x8019519C: addiu       $a0, $zero, 0x7B
    ctx->r4 = ADD32(0, 0X7B);
    func_800C8544(rdram, ctx);
        goto after_3;
    // 0x8019519C: addiu       $a0, $zero, 0x7B
    ctx->r4 = ADD32(0, 0X7B);
    after_3:
    // 0x801951A0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801951A4: addiu       $t6, $t6, -0x2E28
    ctx->r14 = ADD32(ctx->r14, -0X2E28);
    // 0x801951A8: lbu         $t8, 0xD($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0XD);
    // 0x801951AC: lbu         $t9, 0x2F($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X2F);
    // 0x801951B0: or          $t3, $t8, $t9
    ctx->r11 = ctx->r24 | ctx->r25;
    // 0x801951B4: b           L_8019526C
    // 0x801951B8: sb          $t3, 0xD($t6)
    MEM_B(0XD, ctx->r14) = ctx->r11;
        goto L_8019526C;
    // 0x801951B8: sb          $t3, 0xD($t6)
    MEM_B(0XD, ctx->r14) = ctx->r11;
L_801951BC:
    // 0x801951BC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x801951C0: addiu       $t0, $t0, -0x2E28
    ctx->r8 = ADD32(ctx->r8, -0X2E28);
    // 0x801951C4: lbu         $t7, 0xD($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0XD);
    // 0x801951C8: lbu         $t4, 0x2F($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X2F);
    // 0x801951CC: and         $t5, $t7, $t4
    ctx->r13 = ctx->r15 & ctx->r12;
    // 0x801951D0: beq         $t5, $zero, L_8019524C
    if (ctx->r13 == 0) {
        // 0x801951D4: nop
    
            goto L_8019524C;
    }
    // 0x801951D4: nop

    // 0x801951D8: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x801951DC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x801951E0: sll         $t1, $t2, 2
    ctx->r9 = S32(ctx->r10 << 2);
    // 0x801951E4: addu        $t1, $t1, $t2
    ctx->r9 = ADD32(ctx->r9, ctx->r10);
    // 0x801951E8: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x801951EC: addu        $t8, $t8, $t1
    ctx->r24 = ADD32(ctx->r24, ctx->r9);
    // 0x801951F0: lb          $t8, -0x41D9($t8)
    ctx->r24 = MEM_B(ctx->r24, -0X41D9);
    // 0x801951F4: blez        $t8, L_80195204
    if (SIGNED(ctx->r24) <= 0) {
        // 0x801951F8: nop
    
            goto L_80195204;
    }
    // 0x801951F8: nop

    // 0x801951FC: b           L_80195224
    // 0x80195200: or          $s0, $t8, $zero
    ctx->r16 = ctx->r24 | 0;
        goto L_80195224;
    // 0x80195200: or          $s0, $t8, $zero
    ctx->r16 = ctx->r24 | 0;
L_80195204:
    // 0x80195204: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80195208: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8019520C: sll         $t3, $t9, 2
    ctx->r11 = S32(ctx->r25 << 2);
    // 0x80195210: addu        $t3, $t3, $t9
    ctx->r11 = ADD32(ctx->r11, ctx->r25);
    // 0x80195214: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x80195218: addu        $s0, $s0, $t3
    ctx->r16 = ADD32(ctx->r16, ctx->r11);
    // 0x8019521C: lb          $s0, -0x41D9($s0)
    ctx->r16 = MEM_B(ctx->r16, -0X41D9);
    // 0x80195220: negu        $s0, $s0
    ctx->r16 = SUB32(0, ctx->r16);
L_80195224:
    // 0x80195224: slti        $at, $s0, 0x6
    ctx->r1 = SIGNED(ctx->r16) < 0X6 ? 1 : 0;
    // 0x80195228: beq         $at, $zero, L_8019524C
    if (ctx->r1 == 0) {
        // 0x8019522C: nop
    
            goto L_8019524C;
    }
    // 0x8019522C: nop

    // 0x80195230: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80195234: lbu         $t7, 0x2F($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X2F);
    // 0x80195238: addiu       $t6, $t6, -0x2E28
    ctx->r14 = ADD32(ctx->r14, -0X2E28);
    // 0x8019523C: lbu         $t0, 0xD($t6)
    ctx->r8 = MEM_BU(ctx->r14, 0XD);
    // 0x80195240: xori        $t4, $t7, 0xFF
    ctx->r12 = ctx->r15 ^ 0XFF;
    // 0x80195244: and         $t5, $t0, $t4
    ctx->r13 = ctx->r8 & ctx->r12;
    // 0x80195248: sb          $t5, 0xD($t6)
    MEM_B(0XD, ctx->r14) = ctx->r13;
L_8019524C:
    // 0x8019524C: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80195250: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80195254: lw          $t8, -0x2E3C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2E3C);
    // 0x80195258: addiu       $t1, $t2, 0x1
    ctx->r9 = ADD32(ctx->r10, 0X1);
    // 0x8019525C: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80195260: sltu        $at, $t1, $t8
    ctx->r1 = ctx->r9 < ctx->r24 ? 1 : 0;
    // 0x80195264: bne         $at, $zero, L_80194FA8
    if (ctx->r1 != 0) {
        // 0x80195268: nop
    
            goto L_80194FA8;
    }
    // 0x80195268: nop

L_8019526C:
    // 0x8019526C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80195270: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80195274: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80195278: jr          $ra
    // 0x8019527C: nop

    return;
    // 0x8019527C: nop

;}
RECOMP_FUNC void func_80195280_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80195280: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80195284: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80195288: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8019528C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80195290: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80195294: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80195298: bne         $t6, $zero, L_801952BC
    if (ctx->r14 != 0) {
        // 0x8019529C: sw          $a3, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r7;
            goto L_801952BC;
    }
    // 0x8019529C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x801952A0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x801952A4: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x801952A8: addiu       $a1, $a1, -0xCD0
    ctx->r5 = ADD32(ctx->r5, -0XCD0);
    // 0x801952AC: jal         0x800D87E4
    // 0x801952B0: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_0;
    // 0x801952B0: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_0:
    // 0x801952B4: b           L_801952D4
    // 0x801952B8: nop

        goto L_801952D4;
    // 0x801952B8: nop

L_801952BC:
    // 0x801952BC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x801952C0: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x801952C4: addiu       $a1, $a1, -0xCB8
    ctx->r5 = ADD32(ctx->r5, -0XCB8);
    // 0x801952C8: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    // 0x801952CC: jal         0x800D87E4
    // 0x801952D0: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    sprintf_recomp(rdram, ctx);
        goto after_1;
    // 0x801952D0: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    after_1:
L_801952D4:
    // 0x801952D4: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x801952D8: addiu       $t8, $zero, 0x8C
    ctx->r24 = ADD32(0, 0X8C);
    // 0x801952DC: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x801952E0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801952E4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x801952E8: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x801952EC: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x801952F0: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x801952F4: jal         0x80193DE8
    // 0x801952F8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    func_80193DE8_1501A0(rdram, ctx);
        goto after_2;
    // 0x801952F8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_2:
    // 0x801952FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80195300: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80195304: jr          $ra
    // 0x80195308: nop

    return;
    // 0x80195308: nop

;}
RECOMP_FUNC void func_8019530C_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019530C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80195310: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80195314: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80195318: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8019531C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80195320: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80195324: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80195328: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8019532C: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    // 0x80195330: addiu       $a1, $a1, -0xCA4
    ctx->r5 = ADD32(ctx->r5, -0XCA4);
    // 0x80195334: jal         0x800D87E4
    // 0x80195338: lbu         $a2, 0x2B($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X2B);
    sprintf_recomp(rdram, ctx);
        goto after_0;
    // 0x80195338: lbu         $a2, 0x2B($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X2B);
    after_0:
    // 0x8019533C: addiu       $t6, $zero, 0x3C
    ctx->r14 = ADD32(0, 0X3C);
    // 0x80195340: addiu       $t7, $zero, 0x50
    ctx->r15 = ADD32(0, 0X50);
    // 0x80195344: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80195348: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8019534C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80195350: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80195354: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80195358: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8019535C: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x80195360: jal         0x80193DE8
    // 0x80195364: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    func_80193DE8_1501A0(rdram, ctx);
        goto after_1;
    // 0x80195364: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    after_1:
    // 0x80195368: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8019536C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80195370: jr          $ra
    // 0x80195374: nop

    return;
    // 0x80195374: nop

;}
RECOMP_FUNC void func_80195378_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80195378: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8019537C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80195380: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80195384: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80195388: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8019538C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80195390: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80195394: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80195398: addiu       $t6, $t6, -0x2E18
    ctx->r14 = ADD32(ctx->r14, -0X2E18);
    // 0x8019539C: lw          $t7, 0x64($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X64);
    // 0x801953A0: beq         $t7, $zero, L_801953E0
    if (ctx->r15 == 0) {
        // 0x801953A4: nop
    
            goto L_801953E0;
    }
    // 0x801953A4: nop

    // 0x801953A8: lhu         $t8, 0x32($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X32);
    // 0x801953AC: beq         $t8, $zero, L_801953E0
    if (ctx->r24 == 0) {
        // 0x801953B0: nop
    
            goto L_801953E0;
    }
    // 0x801953B0: nop

    // 0x801953B4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x801953B8: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x801953BC: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x801953C0: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x801953C4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x801953C8: divu        $zero, $t9, $t7
    lo = S32(U32(ctx->r25) / U32(ctx->r15)); hi = S32(U32(ctx->r25) % U32(ctx->r15));
    // 0x801953CC: mflo        $t0
    ctx->r8 = lo;
    // 0x801953D0: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x801953D4: bne         $t7, $zero, L_801953E0
    if (ctx->r15 != 0) {
        // 0x801953D8: nop
    
            goto L_801953E0;
    }
    // 0x801953D8: nop

    // 0x801953DC: break       7
    do_break(2149143516);
L_801953E0:
    // 0x801953E0: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x801953E4: addiu       $t1, $t1, -0x2E18
    ctx->r9 = ADD32(ctx->r9, -0X2E18);
    // 0x801953E8: lw          $t2, 0x64($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X64);
    // 0x801953EC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x801953F0: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x801953F4: addiu       $a1, $a1, -0xC90
    ctx->r5 = ADD32(ctx->r5, -0XC90);
    // 0x801953F8: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    // 0x801953FC: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80195400: lhu         $a3, 0x32($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X32);
    // 0x80195404: jal         0x800D87E4
    // 0x80195408: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    sprintf_recomp(rdram, ctx);
        goto after_0;
    // 0x80195408: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_0:
    // 0x8019540C: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80195410: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80195414: addiu       $t5, $zero, 0x50
    ctx->r13 = ADD32(0, 0X50);
    // 0x80195418: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x8019541C: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80195420: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80195424: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80195428: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x8019542C: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x80195430: jal         0x80193DE8
    // 0x80195434: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    func_80193DE8_1501A0(rdram, ctx);
        goto after_1;
    // 0x80195434: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    after_1:
    // 0x80195438: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8019543C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80195440: jr          $ra
    // 0x80195444: nop

    return;
    // 0x80195444: nop

;}
RECOMP_FUNC void func_80195448_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80195448: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8019544C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80195450: lbu         $t6, 0x2B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X2B);
    // 0x80195454: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80195458: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8019545C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80195460: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80195464: beq         $t6, $at, L_8019548C
    if (ctx->r14 == ctx->r1) {
        // 0x80195468: sw          $a3, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r7;
            goto L_8019548C;
    }
    // 0x80195468: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8019546C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80195470: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80195474: addiu       $a1, $a1, -0xC74
    ctx->r5 = ADD32(ctx->r5, -0XC74);
    // 0x80195478: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    // 0x8019547C: jal         0x800D87E4
    // 0x80195480: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    sprintf_recomp(rdram, ctx);
        goto after_0;
    // 0x80195480: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    after_0:
    // 0x80195484: b           L_801954A0
    // 0x80195488: nop

        goto L_801954A0;
    // 0x80195488: nop

L_8019548C:
    // 0x8019548C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80195490: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80195494: addiu       $a1, $a1, -0xC64
    ctx->r5 = ADD32(ctx->r5, -0XC64);
    // 0x80195498: jal         0x800D87E4
    // 0x8019549C: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    sprintf_recomp(rdram, ctx);
        goto after_1;
    // 0x8019549C: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    after_1:
L_801954A0:
    // 0x801954A0: addiu       $t7, $zero, 0xE6
    ctx->r15 = ADD32(0, 0XE6);
    // 0x801954A4: addiu       $t8, $zero, 0xE6
    ctx->r24 = ADD32(0, 0XE6);
    // 0x801954A8: addiu       $t9, $zero, 0x58
    ctx->r25 = ADD32(0, 0X58);
    // 0x801954AC: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x801954B0: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x801954B4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801954B8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x801954BC: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x801954C0: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x801954C4: jal         0x80193DE8
    // 0x801954C8: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    func_80193DE8_1501A0(rdram, ctx);
        goto after_2;
    // 0x801954C8: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    after_2:
    // 0x801954CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801954D0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801954D4: jr          $ra
    // 0x801954D8: nop

    return;
    // 0x801954D8: nop

;}
RECOMP_FUNC void func_801954DC_1501A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801954DC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801954E0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x801954E4: lhu         $t6, 0x32($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X32);
    // 0x801954E8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801954EC: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x801954F0: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x801954F4: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x801954F8: beq         $t6, $zero, L_80195550
    if (ctx->r14 == 0) {
        // 0x801954FC: sh          $zero, 0x2E($sp)
        MEM_H(0X2E, ctx->r29) = 0;
            goto L_80195550;
    }
    // 0x801954FC: sh          $zero, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = 0;
    // 0x80195500: lhu         $t7, 0x36($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X36);
    // 0x80195504: beq         $t7, $zero, L_80195550
    if (ctx->r15 == 0) {
        // 0x80195508: nop
    
            goto L_80195550;
    }
    // 0x80195508: nop

    // 0x8019550C: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80195510: subu        $t8, $t8, $t6
    ctx->r24 = SUB32(ctx->r24, ctx->r14);
    // 0x80195514: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80195518: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x8019551C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80195520: div         $zero, $t8, $t7
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r15))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r15)));
    // 0x80195524: mflo        $t9
    ctx->r25 = lo;
    // 0x80195528: sh          $t9, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r25;
    // 0x8019552C: bne         $t7, $zero, L_80195538
    if (ctx->r15 != 0) {
        // 0x80195530: nop
    
            goto L_80195538;
    }
    // 0x80195530: nop

    // 0x80195534: break       7
    do_break(2149143860);
L_80195538:
    // 0x80195538: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8019553C: bne         $t7, $at, L_80195550
    if (ctx->r15 != ctx->r1) {
        // 0x80195540: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80195550;
    }
    // 0x80195540: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80195544: bne         $t8, $at, L_80195550
    if (ctx->r24 != ctx->r1) {
        // 0x80195548: nop
    
            goto L_80195550;
    }
    // 0x80195548: nop

    // 0x8019554C: break       6
    do_break(2149143884);
L_80195550:
    // 0x80195550: lhu         $t0, 0x36($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X36);
    // 0x80195554: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80195558: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x8019555C: addiu       $a1, $a1, -0xC4C
    ctx->r5 = ADD32(ctx->r5, -0XC4C);
    // 0x80195560: addiu       $a0, $a0, 0x3B40
    ctx->r4 = ADD32(ctx->r4, 0X3B40);
    // 0x80195564: lhu         $a2, 0x2E($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X2E);
    // 0x80195568: lhu         $a3, 0x32($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X32);
    // 0x8019556C: jal         0x800D87E4
    // 0x80195570: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    sprintf_recomp(rdram, ctx);
        goto after_0;
    // 0x80195570: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_0:
    // 0x80195574: addiu       $t1, $zero, 0xCC
    ctx->r9 = ADD32(0, 0XCC);
    // 0x80195578: addiu       $t2, $zero, 0xCC
    ctx->r10 = ADD32(0, 0XCC);
    // 0x8019557C: addiu       $t3, $zero, 0x60
    ctx->r11 = ADD32(0, 0X60);
    // 0x80195580: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x80195584: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80195588: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8019558C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80195590: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80195594: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x80195598: jal         0x80193DE8
    // 0x8019559C: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    func_80193DE8_1501A0(rdram, ctx);
        goto after_1;
    // 0x8019559C: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    after_1:
    // 0x801955A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801955A4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801955A8: jr          $ra
    // 0x801955AC: nop

    return;
    // 0x801955AC: nop

;}
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
