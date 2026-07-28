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

RECOMP_FUNC void func_800D372C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D372C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D3730: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D3734: lbu         $t7, 0x8($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X8);
    // 0x800D3738: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x800D373C: lw          $v0, 0x10($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X10);
    // 0x800D3740: multu       $t7, $t0
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D3744: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800D3748: lbu         $t6, 0x6($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X6);
    // 0x800D374C: addiu       $v1, $v1, 0x7060
    ctx->r3 = ADD32(ctx->r3, 0X7060);
    // 0x800D3750: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800D3754: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800D3758: mflo        $t8
    ctx->r24 = lo;
    // 0x800D375C: addu        $t9, $v1, $t8
    ctx->r25 = ADD32(ctx->r3, ctx->r24);
    // 0x800D3760: sb          $t6, 0x6($t9)
    MEM_B(0X6, ctx->r25) = ctx->r14;
    // 0x800D3764: lbu         $t2, 0x8($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X8);
    // 0x800D3768: lhu         $t1, 0x2($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X2);
    // 0x800D376C: multu       $t2, $t0
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D3770: mflo        $t3
    ctx->r11 = lo;
    // 0x800D3774: addu        $t4, $v1, $t3
    ctx->r12 = ADD32(ctx->r3, ctx->r11);
    // 0x800D3778: sh          $t1, 0x2($t4)
    MEM_H(0X2, ctx->r12) = ctx->r9;
    // 0x800D377C: lbu         $t7, 0x8($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X8);
    // 0x800D3780: lhu         $t5, 0x0($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0X0);
    // 0x800D3784: multu       $t7, $t0
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D3788: mflo        $t8
    ctx->r24 = lo;
    // 0x800D378C: addu        $t6, $v1, $t8
    ctx->r14 = ADD32(ctx->r3, ctx->r24);
    // 0x800D3790: sh          $t5, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r13;
    // 0x800D3794: lbu         $t9, 0x8($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X8);
    // 0x800D3798: multu       $t9, $t0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D379C: mflo        $t2
    ctx->r10 = lo;
    // 0x800D37A0: addu        $t3, $v1, $t2
    ctx->r11 = ADD32(ctx->r3, ctx->r10);
    // 0x800D37A4: sh          $zero, 0x4($t3)
    MEM_H(0X4, ctx->r11) = 0;
    // 0x800D37A8: jal         0x800D95F0
    // 0x800D37AC: lw          $a0, 0x4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4);
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x800D37AC: lw          $a0, 0x4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4);
    after_0:
    // 0x800D37B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D37B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D37B8: jr          $ra
    // 0x800D37BC: nop

    return;
    // 0x800D37BC: nop

;}
RECOMP_FUNC void func_800D37C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D37C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D37C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D37C8: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    // 0x800D37CC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800D37D0: beq         $v0, $at, L_800D3808
    if (ctx->r2 == ctx->r1) {
        // 0x800D37D4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800D3808;
    }
    // 0x800D37D4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800D37D8: beq         $v0, $at, L_800D3838
    if (ctx->r2 == ctx->r1) {
        // 0x800D37DC: addiu       $at, $zero, 0x3000
        ctx->r1 = ADD32(0, 0X3000);
            goto L_800D3838;
    }
    // 0x800D37DC: addiu       $at, $zero, 0x3000
    ctx->r1 = ADD32(0, 0X3000);
    // 0x800D37E0: beq         $v0, $at, L_800D3818
    if (ctx->r2 == ctx->r1) {
        // 0x800D37E4: addiu       $at, $zero, 0x3001
        ctx->r1 = ADD32(0, 0X3001);
            goto L_800D3818;
    }
    // 0x800D37E4: addiu       $at, $zero, 0x3001
    ctx->r1 = ADD32(0, 0X3001);
    // 0x800D37E8: beq         $v0, $at, L_800D3828
    if (ctx->r2 == ctx->r1) {
        // 0x800D37EC: addiu       $at, $zero, 0x3002
        ctx->r1 = ADD32(0, 0X3002);
            goto L_800D3828;
    }
    // 0x800D37EC: addiu       $at, $zero, 0x3002
    ctx->r1 = ADD32(0, 0X3002);
    // 0x800D37F0: beq         $v0, $at, L_800D3848
    if (ctx->r2 == ctx->r1) {
        // 0x800D37F4: addiu       $at, $zero, 0x3003
        ctx->r1 = ADD32(0, 0X3003);
            goto L_800D3848;
    }
    // 0x800D37F4: addiu       $at, $zero, 0x3003
    ctx->r1 = ADD32(0, 0X3003);
    // 0x800D37F8: beq         $v0, $at, L_800D3858
    if (ctx->r2 == ctx->r1) {
        // 0x800D37FC: nop
    
            goto L_800D3858;
    }
    // 0x800D37FC: nop

    // 0x800D3800: b           L_800D3874
    // 0x800D3804: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800D3874;
    // 0x800D3804: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800D3808:
    // 0x800D3808: jal         0x800D33F0
    // 0x800D380C: nop

    func_800D33F0(rdram, ctx);
        goto after_0;
    // 0x800D380C: nop

    after_0:
    // 0x800D3810: b           L_800D3874
    // 0x800D3814: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800D3874;
    // 0x800D3814: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800D3818:
    // 0x800D3818: jal         0x800D3598
    // 0x800D381C: nop

    func_800D3598(rdram, ctx);
        goto after_1;
    // 0x800D381C: nop

    after_1:
    // 0x800D3820: b           L_800D3874
    // 0x800D3824: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800D3874;
    // 0x800D3824: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800D3828:
    // 0x800D3828: jal         0x800D372C
    // 0x800D382C: nop

    func_800D372C(rdram, ctx);
        goto after_2;
    // 0x800D382C: nop

    after_2:
    // 0x800D3830: b           L_800D3874
    // 0x800D3834: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800D3874;
    // 0x800D3834: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800D3838:
    // 0x800D3838: jal         0x800D3604
    // 0x800D383C: nop

    func_800D3604(rdram, ctx);
        goto after_3;
    // 0x800D383C: nop

    after_3:
    // 0x800D3840: b           L_800D3874
    // 0x800D3844: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800D3874;
    // 0x800D3844: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800D3848:
    // 0x800D3848: jal         0x800D3604
    // 0x800D384C: nop

    func_800D3604(rdram, ctx);
        goto after_4;
    // 0x800D384C: nop

    after_4:
    // 0x800D3850: b           L_800D3874
    // 0x800D3854: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800D3874;
    // 0x800D3854: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800D3858:
    // 0x800D3858: jal         0x800D36A8
    // 0x800D385C: nop

    func_800D36A8(rdram, ctx);
        goto after_5;
    // 0x800D385C: nop

    after_5:
    // 0x800D3860: b           L_800D3874
    // 0x800D3864: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800D3874;
    // 0x800D3864: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800D3868: b           L_800D3874
    // 0x800D386C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800D3874;
    // 0x800D386C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800D3870: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800D3874:
    // 0x800D3874: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D3878: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D387C: jr          $ra
    // 0x800D3880: nop

    return;
    // 0x800D3880: nop

    // 0x800D3884: nop

    // 0x800D3888: nop

    // 0x800D388C: nop

;}
RECOMP_FUNC void func_800D3890(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3890: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D3894: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D3898: jal         0x800D9740
    // 0x800D389C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x800D389C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800D38A0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800D38A4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800D38A8: sw          $t6, 0x6EAC($at)
    MEM_W(0X6EAC, ctx->r1) = ctx->r14;
    // 0x800D38AC: jal         0x800D9740
    // 0x800D38B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    osSetIntMask_recomp(rdram, ctx);
        goto after_1;
    // 0x800D38B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x800D38B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D38B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D38BC: jr          $ra
    // 0x800D38C0: nop

    return;
    // 0x800D38C0: nop

;}
RECOMP_FUNC void func_800D38C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D38C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D38C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D38CC: jal         0x800D9740
    // 0x800D38D0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x800D38D0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800D38D4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800D38D8: sw          $zero, 0x6EAC($at)
    MEM_W(0X6EAC, ctx->r1) = 0;
    // 0x800D38DC: jal         0x800D9740
    // 0x800D38E0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    osSetIntMask_recomp(rdram, ctx);
        goto after_1;
    // 0x800D38E0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x800D38E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D38E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D38EC: jr          $ra
    // 0x800D38F0: nop

    return;
    // 0x800D38F0: nop

    // 0x800D38F4: nop

    // 0x800D38F8: nop

    // 0x800D38FC: nop

;}
RECOMP_FUNC void func_800D3900(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3900: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800D3904: addiu       $v0, $v1, 0x6E30
    ctx->r2 = ADD32(ctx->r3, 0X6E30);
    // 0x800D3908: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800D390C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D3910: beq         $v0, $zero, L_800D3938
    if (ctx->r2 == 0) {
        // 0x800D3914: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_800D3938;
    }
    // 0x800D3914: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800D3918: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
L_800D391C:
    // 0x800D391C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800D3920: beql        $a1, $t6, L_800D3970
    if (ctx->r5 == ctx->r14) {
        // 0x800D3924: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D3970;
    }
    goto skip_0;
    // 0x800D3924: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800D3928: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800D392C: bnel        $v0, $zero, L_800D391C
    if (ctx->r2 != 0) {
        // 0x800D3930: lw          $t6, 0x4($v0)
        ctx->r14 = MEM_W(ctx->r2, 0X4);
            goto L_800D391C;
    }
    goto skip_1;
    // 0x800D3930: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    skip_1:
    // 0x800D3934: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
L_800D3938:
    // 0x800D3938: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800D393C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800D3940: jal         0x800D9740
    // 0x800D3944: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x800D3944: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x800D3948: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x800D394C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800D3950: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800D3954: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800D3958: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800D395C: sw          $a1, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r5;
    // 0x800D3960: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x800D3964: jal         0x800D9740
    // 0x800D3968: sw          $a2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r6;
    osSetIntMask_recomp(rdram, ctx);
        goto after_1;
    // 0x800D3968: sw          $a2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r6;
    after_1:
    // 0x800D396C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D3970:
    // 0x800D3970: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800D3974: jr          $ra
    // 0x800D3978: nop

    return;
    // 0x800D3978: nop

    // 0x800D397C: nop

;}
RECOMP_FUNC void func_800D3980(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3980: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x800D3984: lw          $t6, 0x7054($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7054);
    // 0x800D3988: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800D398C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D3990: beq         $t6, $zero, L_800D39D8
    if (ctx->r14 == 0) {
        // 0x800D3994: addiu       $a0, $sp, 0x20
        ctx->r4 = ADD32(ctx->r29, 0X20);
            goto L_800D39D8;
    }
    // 0x800D3994: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x800D3998: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x800D399C: jal         0x800D8B80
    // 0x800D39A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x800D39A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x800D39A4: addiu       $t7, $zero, 0x1002
    ctx->r15 = ADD32(0, 0X1002);
    // 0x800D39A8: addiu       $t8, $sp, 0x20
    ctx->r24 = ADD32(ctx->r29, 0X20);
    // 0x800D39AC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800D39B0: sh          $t7, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r15;
    // 0x800D39B4: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x800D39B8: addiu       $a0, $a0, 0x6E18
    ctx->r4 = ADD32(ctx->r4, 0X6E18);
    // 0x800D39BC: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x800D39C0: jal         0x800D95F0
    // 0x800D39C4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x800D39C4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x800D39C8: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x800D39CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800D39D0: jal         0x800D8D00
    // 0x800D39D4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x800D39D4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
L_800D39D8:
    // 0x800D39D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D39DC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800D39E0: jr          $ra
    // 0x800D39E4: nop

    return;
    // 0x800D39E4: nop

    // 0x800D39E8: nop

    // 0x800D39EC: nop

;}
RECOMP_FUNC void func_800D39F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D39F0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800D39F4: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800D39F8: addiu       $a1, $v1, 0x6E30
    ctx->r5 = ADD32(ctx->r3, 0X6E30);
    // 0x800D39FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D3A00: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800D3A04: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800D3A08: beql        $v0, $zero, L_800D3A68
    if (ctx->r2 == 0) {
        // 0x800D3A0C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D3A68;
    }
    goto skip_0;
    // 0x800D3A0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800D3A10: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
    // 0x800D3A14: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
L_800D3A18:
    // 0x800D3A18: bne         $v1, $t6, L_800D3A54
    if (ctx->r3 != ctx->r14) {
        // 0x800D3A1C: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_800D3A54;
    }
    // 0x800D3A1C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800D3A20: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800D3A24: jal         0x800D9740
    // 0x800D3A28: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x800D3A28: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x800D3A2C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800D3A30: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800D3A34: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800D3A38: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x800D3A3C: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x800D3A40: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x800D3A44: jal         0x800D9740
    // 0x800D3A48: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    osSetIntMask_recomp(rdram, ctx);
        goto after_1;
    // 0x800D3A48: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    after_1:
    // 0x800D3A4C: b           L_800D3A68
    // 0x800D3A50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800D3A68;
    // 0x800D3A50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D3A54:
    // 0x800D3A54: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800D3A58: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800D3A5C: bnel        $v0, $zero, L_800D3A18
    if (ctx->r2 != 0) {
        // 0x800D3A60: lw          $t6, 0x4($v0)
        ctx->r14 = MEM_W(ctx->r2, 0X4);
            goto L_800D3A18;
    }
    goto skip_1;
    // 0x800D3A60: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    skip_1:
    // 0x800D3A64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D3A68:
    // 0x800D3A68: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800D3A6C: jr          $ra
    // 0x800D3A70: nop

    return;
    // 0x800D3A70: nop

    // 0x800D3A74: nop

    // 0x800D3A78: nop

    // 0x800D3A7C: nop

;}
RECOMP_FUNC void func_800D3D70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3D70: jr          $ra
    // 0x800D3D74: sh          $a1, 0x16($a0)
    MEM_H(0X16, ctx->r4) = ctx->r5;
    return;
    // 0x800D3D74: sh          $a1, 0x16($a0)
    MEM_H(0X16, ctx->r4) = ctx->r5;
;}
RECOMP_FUNC void spMove_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3D78: sh          $a1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r5;
    // 0x800D3D7C: jr          $ra
    // 0x800D3D80: sh          $a2, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r6;
    return;
    // 0x800D3D80: sh          $a2, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r6;
;}
RECOMP_FUNC void spScissor_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3D84: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800D3D88: sw          $a0, -0x7F68($at)
    MEM_W(-0X7F68, ctx->r1) = ctx->r4;
    // 0x800D3D8C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800D3D90: sw          $a2, -0x7F64($at)
    MEM_W(-0X7F64, ctx->r1) = ctx->r6;
    // 0x800D3D94: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800D3D98: sw          $a1, -0x7F70($at)
    MEM_W(-0X7F70, ctx->r1) = ctx->r5;
    // 0x800D3D9C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800D3DA0: jr          $ra
    // 0x800D3DA4: sw          $a3, -0x7F6C($at)
    MEM_W(-0X7F6C, ctx->r1) = ctx->r7;
    return;
    // 0x800D3DA4: sw          $a3, -0x7F6C($at)
    MEM_W(-0X7F6C, ctx->r1) = ctx->r7;
;}
RECOMP_FUNC void func_800D3DA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3DA8: addiu       $sp, $sp, -0x1F8
    ctx->r29 = ADD32(ctx->r29, -0X1F8);
    // 0x800D3DAC: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x800D3DB0: sw          $a0, 0x1F8($sp)
    MEM_W(0X1F8, ctx->r29) = ctx->r4;
    // 0x800D3DB4: sw          $a1, 0x1FC($sp)
    MEM_W(0X1FC, ctx->r29) = ctx->r5;
    // 0x800D3DB8: sw          $a2, 0x200($sp)
    MEM_W(0X200, ctx->r29) = ctx->r6;
    // 0x800D3DBC: sw          $a3, 0x204($sp)
    MEM_W(0X204, ctx->r29) = ctx->r7;
    // 0x800D3DC0: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800D3DC4: lh          $t8, 0x2E($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X2E);
    // 0x800D3DC8: lw          $v1, -0x7F70($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7F70);
    // 0x800D3DCC: lh          $s0, 0x2($a2)
    ctx->r16 = MEM_H(ctx->r6, 0X2);
    // 0x800D3DD0: sw          $t8, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r24;
    // 0x800D3DD4: slt         $at, $a3, $v1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800D3DD8: beq         $at, $zero, L_800D54BC
    if (ctx->r1 == 0) {
        // 0x800D3DDC: lw          $t1, 0x0($a0)
        ctx->r9 = MEM_W(ctx->r4, 0X0);
            goto L_800D54BC;
    }
    // 0x800D3DDC: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x800D3DE0: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800D3DE4: lw          $a1, -0x7F6C($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7F6C);
    // 0x800D3DE8: lw          $a0, 0x208($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X208);
    // 0x800D3DEC: lw          $a2, 0x20C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20C);
    // 0x800D3DF0: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x800D3DF4: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800D3DF8: beql        $at, $zero, L_800D54C0
    if (ctx->r1 == 0) {
        // 0x800D3DFC: lw          $s0, 0x4($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X4);
            goto L_800D54C0;
    }
    goto skip_0;
    // 0x800D3DFC: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    skip_0:
    // 0x800D3E00: lw          $t0, -0x7F68($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7F68);
    // 0x800D3E04: lw          $a3, 0x210($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X210);
    // 0x800D3E08: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800D3E0C: slt         $at, $a2, $t0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800D3E10: bnel        $at, $zero, L_800D54C0
    if (ctx->r1 != 0) {
        // 0x800D3E14: lw          $s0, 0x4($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X4);
            goto L_800D54C0;
    }
    goto skip_1;
    // 0x800D3E14: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    skip_1:
    // 0x800D3E18: lw          $v0, -0x7F64($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7F64);
    // 0x800D3E1C: lw          $t7, 0x204($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X204);
    // 0x800D3E20: slt         $at, $a3, $v0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800D3E24: bne         $at, $zero, L_800D54BC
    if (ctx->r1 != 0) {
        // 0x800D3E28: slt         $at, $t7, $t0
        ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_800D54BC;
    }
    // 0x800D3E28: slt         $at, $t7, $t0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800D3E2C: beql        $at, $zero, L_800D3E74
    if (ctx->r1 == 0) {
        // 0x800D3E30: lw          $t7, 0x204($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X204);
            goto L_800D3E74;
    }
    goto skip_2;
    // 0x800D3E30: lw          $t7, 0x204($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X204);
    skip_2:
    // 0x800D3E34: lw          $t9, 0x200($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X200);
    // 0x800D3E38: sll         $t8, $t0, 2
    ctx->r24 = S32(ctx->r8 << 2);
    // 0x800D3E3C: sw          $t8, 0x1EC($sp)
    MEM_W(0X1EC, ctx->r29) = ctx->r24;
    // 0x800D3E40: lh          $t6, 0x4($t9)
    ctx->r14 = MEM_H(ctx->r25, 0X4);
    // 0x800D3E44: lw          $t9, 0x214($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X214);
    // 0x800D3E48: sll         $t8, $t6, 5
    ctx->r24 = S32(ctx->r14 << 5);
    // 0x800D3E4C: addu        $t6, $t8, $t9
    ctx->r14 = ADD32(ctx->r24, ctx->r25);
    // 0x800D3E50: lw          $t9, 0x21C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X21C);
    // 0x800D3E54: subu        $t8, $t0, $t7
    ctx->r24 = SUB32(ctx->r8, ctx->r15);
    // 0x800D3E58: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D3E5C: mflo        $t7
    ctx->r15 = lo;
    // 0x800D3E60: sra         $t8, $t7, 5
    ctx->r24 = S32(SIGNED(ctx->r15) >> 5);
    // 0x800D3E64: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800D3E68: b           L_800D3E94
    // 0x800D3E6C: sw          $t9, 0x1F4($sp)
    MEM_W(0X1F4, ctx->r29) = ctx->r25;
        goto L_800D3E94;
    // 0x800D3E6C: sw          $t9, 0x1F4($sp)
    MEM_W(0X1F4, ctx->r29) = ctx->r25;
    // 0x800D3E70: lw          $t7, 0x204($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X204);
L_800D3E74:
    // 0x800D3E74: lw          $t8, 0x200($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X200);
    // 0x800D3E78: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x800D3E7C: sw          $t6, 0x1EC($sp)
    MEM_W(0X1EC, ctx->r29) = ctx->r14;
    // 0x800D3E80: lh          $t9, 0x4($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X4);
    // 0x800D3E84: lw          $t6, 0x214($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X214);
    // 0x800D3E88: sll         $t7, $t9, 5
    ctx->r15 = S32(ctx->r25 << 5);
    // 0x800D3E8C: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x800D3E90: sw          $t8, 0x1F4($sp)
    MEM_W(0X1F4, ctx->r29) = ctx->r24;
L_800D3E94:
    // 0x800D3E94: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800D3E98: beql        $at, $zero, L_800D3EE0
    if (ctx->r1 == 0) {
        // 0x800D3E9C: lw          $t7, 0x200($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X200);
            goto L_800D3EE0;
    }
    goto skip_3;
    // 0x800D3E9C: lw          $t7, 0x200($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X200);
    skip_3:
    // 0x800D3EA0: lw          $t7, 0x200($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X200);
    // 0x800D3EA4: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x800D3EA8: sw          $t9, 0x1E8($sp)
    MEM_W(0X1E8, ctx->r29) = ctx->r25;
    // 0x800D3EAC: lh          $t6, 0x6($t7)
    ctx->r14 = MEM_H(ctx->r15, 0X6);
    // 0x800D3EB0: lw          $t9, 0x218($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X218);
    // 0x800D3EB4: sll         $t8, $t6, 5
    ctx->r24 = S32(ctx->r14 << 5);
    // 0x800D3EB8: addu        $t7, $t8, $t9
    ctx->r15 = ADD32(ctx->r24, ctx->r25);
    // 0x800D3EBC: lw          $t8, 0x220($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X220);
    // 0x800D3EC0: subu        $t6, $v0, $a0
    ctx->r14 = SUB32(ctx->r2, ctx->r4);
    // 0x800D3EC4: multu       $t6, $t8
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D3EC8: mflo        $t9
    ctx->r25 = lo;
    // 0x800D3ECC: sra         $t6, $t9, 5
    ctx->r14 = S32(SIGNED(ctx->r25) >> 5);
    // 0x800D3ED0: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x800D3ED4: b           L_800D3EFC
    // 0x800D3ED8: sw          $t8, 0x1F0($sp)
    MEM_W(0X1F0, ctx->r29) = ctx->r24;
        goto L_800D3EFC;
    // 0x800D3ED8: sw          $t8, 0x1F0($sp)
    MEM_W(0X1F0, ctx->r29) = ctx->r24;
    // 0x800D3EDC: lw          $t7, 0x200($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X200);
L_800D3EE0:
    // 0x800D3EE0: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x800D3EE4: sw          $t9, 0x1E8($sp)
    MEM_W(0X1E8, ctx->r29) = ctx->r25;
    // 0x800D3EE8: lh          $t6, 0x6($t7)
    ctx->r14 = MEM_H(ctx->r15, 0X6);
    // 0x800D3EEC: lw          $t9, 0x218($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X218);
    // 0x800D3EF0: sll         $t8, $t6, 5
    ctx->r24 = S32(ctx->r14 << 5);
    // 0x800D3EF4: addu        $t7, $t8, $t9
    ctx->r15 = ADD32(ctx->r24, ctx->r25);
    // 0x800D3EF8: sw          $t7, 0x1F0($sp)
    MEM_W(0X1F0, ctx->r29) = ctx->r15;
L_800D3EFC:
    // 0x800D3EFC: slt         $at, $a2, $v1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800D3F00: bne         $at, $zero, L_800D3F14
    if (ctx->r1 != 0) {
        // 0x800D3F04: sll         $t8, $a2, 2
        ctx->r24 = S32(ctx->r6 << 2);
            goto L_800D3F14;
    }
    // 0x800D3F04: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x800D3F08: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x800D3F0C: b           L_800D3F18
    // 0x800D3F10: sw          $t6, 0x1E4($sp)
    MEM_W(0X1E4, ctx->r29) = ctx->r14;
        goto L_800D3F18;
    // 0x800D3F10: sw          $t6, 0x1E4($sp)
    MEM_W(0X1E4, ctx->r29) = ctx->r14;
L_800D3F14:
    // 0x800D3F14: sw          $t8, 0x1E4($sp)
    MEM_W(0X1E4, ctx->r29) = ctx->r24;
L_800D3F18:
    // 0x800D3F18: slt         $at, $a3, $a1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800D3F1C: bne         $at, $zero, L_800D3F30
    if (ctx->r1 != 0) {
        // 0x800D3F20: sll         $t7, $a3, 2
        ctx->r15 = S32(ctx->r7 << 2);
            goto L_800D3F30;
    }
    // 0x800D3F20: sll         $t7, $a3, 2
    ctx->r15 = S32(ctx->r7 << 2);
    // 0x800D3F24: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x800D3F28: b           L_800D3F34
    // 0x800D3F2C: sw          $t9, 0x1E0($sp)
    MEM_W(0X1E0, ctx->r29) = ctx->r25;
        goto L_800D3F34;
    // 0x800D3F2C: sw          $t9, 0x1E0($sp)
    MEM_W(0X1E0, ctx->r29) = ctx->r25;
L_800D3F30:
    // 0x800D3F30: sw          $t7, 0x1E0($sp)
    MEM_W(0X1E0, ctx->r29) = ctx->r15;
L_800D3F34:
    // 0x800D3F34: lw          $t6, 0x200($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X200);
    // 0x800D3F38: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x800D3F3C: lw          $t8, -0x3250($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X3250);
    // 0x800D3F40: lw          $v0, 0x8($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X8);
    // 0x800D3F44: lw          $t9, 0x1FC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1FC);
    // 0x800D3F48: beql        $t8, $v0, L_800D532C
    if (ctx->r24 == ctx->r2) {
        // 0x800D3F4C: addiu       $v0, $sp, 0x1C4
        ctx->r2 = ADD32(ctx->r29, 0X1C4);
            goto L_800D532C;
    }
    goto skip_4;
    // 0x800D3F4C: addiu       $v0, $sp, 0x1C4
    ctx->r2 = ADD32(ctx->r29, 0X1C4);
    skip_4:
    // 0x800D3F50: lbu         $a0, 0x31($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X31);
    // 0x800D3F54: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800D3F58: lw          $t7, 0x1FC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1FC);
    // 0x800D3F5C: beql        $a0, $zero, L_800D3F90
    if (ctx->r4 == 0) {
        // 0x800D3F60: lhu         $t6, 0x14($t7)
        ctx->r14 = MEM_HU(ctx->r15, 0X14);
            goto L_800D3F90;
    }
    goto skip_5;
    // 0x800D3F60: lhu         $t6, 0x14($t7)
    ctx->r14 = MEM_HU(ctx->r15, 0X14);
    skip_5:
    // 0x800D3F64: beq         $a0, $at, L_800D42D4
    if (ctx->r4 == ctx->r1) {
        // 0x800D3F68: lw          $t9, 0x1FC($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X1FC);
            goto L_800D42D4;
    }
    // 0x800D3F68: lw          $t9, 0x1FC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1FC);
    // 0x800D3F6C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800D3F70: beq         $a0, $at, L_800D4620
    if (ctx->r4 == ctx->r1) {
        // 0x800D3F74: lw          $a2, 0x1FC($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X1FC);
            goto L_800D4620;
    }
    // 0x800D3F74: lw          $a2, 0x1FC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1FC);
    // 0x800D3F78: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800D3F7C: beq         $a0, $at, L_800D4FEC
    if (ctx->r4 == ctx->r1) {
        // 0x800D3F80: lw          $a2, 0x1FC($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X1FC);
            goto L_800D4FEC;
    }
    // 0x800D3F80: lw          $a2, 0x1FC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1FC);
    // 0x800D3F84: b           L_800D5320
    // 0x800D3F88: nop

        goto L_800D5320;
    // 0x800D3F88: nop

    // 0x800D3F8C: lhu         $t6, 0x14($t7)
    ctx->r14 = MEM_HU(ctx->r15, 0X14);
L_800D3F90:
    // 0x800D3F90: lui         $a3, 0x10
    ctx->r7 = S32(0X10 << 16);
    // 0x800D3F94: andi        $t8, $t6, 0x200
    ctx->r24 = ctx->r14 & 0X200;
    // 0x800D3F98: beql        $t8, $zero, L_800D4100
    if (ctx->r24 == 0) {
        // 0x800D3F9C: lw          $t7, 0x1FC($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X1FC);
            goto L_800D4100;
    }
    goto skip_6;
    // 0x800D3F9C: lw          $t7, 0x1FC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1FC);
    skip_6:
    // 0x800D3FA0: lbu         $t9, 0x30($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X30);
    // 0x800D3FA4: lui         $at, 0xFD00
    ctx->r1 = S32(0XFD00 << 16);
    // 0x800D3FA8: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800D3FAC: andi        $t6, $t9, 0x7
    ctx->r14 = ctx->r25 & 0X7;
    // 0x800D3FB0: sll         $t8, $t6, 21
    ctx->r24 = S32(ctx->r14 << 21);
    // 0x800D3FB4: or          $t7, $t8, $at
    ctx->r15 = ctx->r24 | ctx->r1;
    // 0x800D3FB8: or          $t9, $t7, $a3
    ctx->r25 = ctx->r15 | ctx->r7;
    // 0x800D3FBC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800D3FC0: lw          $t6, 0x200($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X200);
    // 0x800D3FC4: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D3FC8: lui         $t3, 0xF500
    ctx->r11 = S32(0XF500 << 16);
    // 0x800D3FCC: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x800D3FD0: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x800D3FD4: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D3FD8: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800D3FDC: lw          $t7, 0x1FC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1FC);
    // 0x800D3FE0: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x800D3FE4: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D3FE8: lbu         $t9, 0x30($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X30);
    // 0x800D3FEC: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x800D3FF0: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D3FF4: andi        $t6, $t9, 0x7
    ctx->r14 = ctx->r25 & 0X7;
    // 0x800D3FF8: sll         $t8, $t6, 21
    ctx->r24 = S32(ctx->r14 << 21);
    // 0x800D3FFC: or          $t7, $t8, $t3
    ctx->r15 = ctx->r24 | ctx->r11;
    // 0x800D4000: lui         $t6, 0x708
    ctx->r14 = S32(0X708 << 16);
    // 0x800D4004: ori         $t6, $t6, 0x200
    ctx->r14 = ctx->r14 | 0X200;
    // 0x800D4008: or          $t9, $t7, $a3
    ctx->r25 = ctx->r15 | ctx->r7;
    // 0x800D400C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800D4010: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x800D4014: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x800D4018: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800D401C: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x800D4020: lui         $t7, 0xF300
    ctx->r15 = S32(0XF300 << 16);
    // 0x800D4024: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x800D4028: lw          $t9, 0x1D4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1D4);
    // 0x800D402C: addiu       $a0, $zero, 0x7FF
    ctx->r4 = ADD32(0, 0X7FF);
    // 0x800D4030: multu       $s0, $t9
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D4034: mflo        $v0
    ctx->r2 = lo;
    // 0x800D4038: addiu       $v0, $v0, 0x3
    ctx->r2 = ADD32(ctx->r2, 0X3);
    // 0x800D403C: sra         $t6, $v0, 2
    ctx->r14 = S32(SIGNED(ctx->r2) >> 2);
    // 0x800D4040: addiu       $v0, $t6, -0x1
    ctx->r2 = ADD32(ctx->r14, -0X1);
    // 0x800D4044: slti        $at, $v0, 0x7FF
    ctx->r1 = SIGNED(ctx->r2) < 0X7FF ? 1 : 0;
    // 0x800D4048: beq         $at, $zero, L_800D4058
    if (ctx->r1 == 0) {
        // 0x800D404C: lui         $t6, 0xE700
        ctx->r14 = S32(0XE700 << 16);
            goto L_800D4058;
    }
    // 0x800D404C: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x800D4050: b           L_800D4058
    // 0x800D4054: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_800D4058;
    // 0x800D4054: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_800D4058:
    // 0x800D4058: andi        $t8, $a0, 0xFFF
    ctx->r24 = ctx->r4 & 0XFFF;
    // 0x800D405C: sll         $t7, $t8, 12
    ctx->r15 = S32(ctx->r24 << 12);
    // 0x800D4060: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800D4064: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x800D4068: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x800D406C: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800D4070: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800D4074: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800D4078: lw          $t8, 0x1FC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1FC);
    // 0x800D407C: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D4080: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x800D4084: lbu         $t7, 0x30($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0X30);
    // 0x800D4088: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D408C: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    // 0x800D4090: andi        $t9, $t7, 0x7
    ctx->r25 = ctx->r15 & 0X7;
    // 0x800D4094: sll         $t6, $t9, 21
    ctx->r14 = S32(ctx->r25 << 21);
    // 0x800D4098: sra         $t7, $s0, 1
    ctx->r15 = S32(SIGNED(ctx->r16) >> 1);
    // 0x800D409C: addiu       $t9, $t7, 0x7
    ctx->r25 = ADD32(ctx->r15, 0X7);
    // 0x800D40A0: or          $t8, $t6, $t3
    ctx->r24 = ctx->r14 | ctx->r11;
    // 0x800D40A4: sra         $t6, $t9, 3
    ctx->r14 = S32(SIGNED(ctx->r25) >> 3);
    // 0x800D40A8: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x800D40AC: sll         $t9, $t7, 9
    ctx->r25 = S32(ctx->r15 << 9);
    // 0x800D40B0: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x800D40B4: lui         $t7, 0x8
    ctx->r15 = S32(0X8 << 16);
    // 0x800D40B8: ori         $t7, $t7, 0x200
    ctx->r15 = ctx->r15 | 0X200;
    // 0x800D40BC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800D40C0: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x800D40C4: addiu       $t9, $s0, -0x1
    ctx->r25 = ADD32(ctx->r16, -0X1);
    // 0x800D40C8: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x800D40CC: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x800D40D0: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x800D40D4: lw          $t9, 0x1D4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1D4);
    // 0x800D40D8: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x800D40DC: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x800D40E0: addiu       $t6, $t9, -0x1
    ctx->r14 = ADD32(ctx->r25, -0X1);
    // 0x800D40E4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800D40E8: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x800D40EC: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x800D40F0: sw          $t6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r14;
    // 0x800D40F4: b           L_800D42C8
    // 0x800D40F8: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
        goto L_800D42C8;
    // 0x800D40F8: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D40FC: lw          $t7, 0x1FC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1FC);
L_800D4100:
    // 0x800D4100: lui         $at, 0xFD00
    ctx->r1 = S32(0XFD00 << 16);
    // 0x800D4104: lui         $a3, 0x10
    ctx->r7 = S32(0X10 << 16);
    // 0x800D4108: lbu         $t8, 0x30($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X30);
    // 0x800D410C: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800D4110: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D4114: andi        $t9, $t8, 0x7
    ctx->r25 = ctx->r24 & 0X7;
    // 0x800D4118: sll         $t6, $t9, 21
    ctx->r14 = S32(ctx->r25 << 21);
    // 0x800D411C: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x800D4120: or          $t8, $t7, $a3
    ctx->r24 = ctx->r15 | ctx->r7;
    // 0x800D4124: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800D4128: lw          $t9, 0x200($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X200);
    // 0x800D412C: lui         $t3, 0xF500
    ctx->r11 = S32(0XF500 << 16);
    // 0x800D4130: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x800D4134: lw          $t6, 0x8($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X8);
    // 0x800D4138: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D413C: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x800D4140: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800D4144: lw          $t7, 0x1FC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1FC);
    // 0x800D4148: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D414C: addiu       $a2, $zero, 0x7FF
    ctx->r6 = ADD32(0, 0X7FF);
    // 0x800D4150: lbu         $t8, 0x30($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X30);
    // 0x800D4154: andi        $t9, $t8, 0x7
    ctx->r25 = ctx->r24 & 0X7;
    // 0x800D4158: sll         $t6, $t9, 21
    ctx->r14 = S32(ctx->r25 << 21);
    // 0x800D415C: or          $t7, $t6, $t3
    ctx->r15 = ctx->r14 | ctx->r11;
    // 0x800D4160: lui         $t9, 0x708
    ctx->r25 = S32(0X708 << 16);
    // 0x800D4164: ori         $t9, $t9, 0x200
    ctx->r25 = ctx->r25 | 0X200;
    // 0x800D4168: or          $t8, $t7, $a3
    ctx->r24 = ctx->r15 | ctx->r7;
    // 0x800D416C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800D4170: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x800D4174: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x800D4178: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800D417C: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x800D4180: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
    // 0x800D4184: lui         $t7, 0xF300
    ctx->r15 = S32(0XF300 << 16);
    // 0x800D4188: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x800D418C: lw          $t8, 0x1D4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1D4);
    // 0x800D4190: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D4194: multu       $s0, $t8
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D4198: mflo        $v0
    ctx->r2 = lo;
    // 0x800D419C: addiu       $v0, $v0, 0x3
    ctx->r2 = ADD32(ctx->r2, 0X3);
    // 0x800D41A0: sra         $t9, $v0, 2
    ctx->r25 = S32(SIGNED(ctx->r2) >> 2);
    // 0x800D41A4: addiu       $v0, $t9, -0x1
    ctx->r2 = ADD32(ctx->r25, -0X1);
    // 0x800D41A8: slti        $at, $v0, 0x7FF
    ctx->r1 = SIGNED(ctx->r2) < 0X7FF ? 1 : 0;
    // 0x800D41AC: beq         $at, $zero, L_800D41BC
    if (ctx->r1 == 0) {
        // 0x800D41B0: nop
    
            goto L_800D41BC;
    }
    // 0x800D41B0: nop

    // 0x800D41B4: b           L_800D41BC
    // 0x800D41B8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
        goto L_800D41BC;
    // 0x800D41B8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_800D41BC:
    // 0x800D41BC: bgez        $s0, L_800D41CC
    if (SIGNED(ctx->r16) >= 0) {
        // 0x800D41C0: sra         $v0, $s0, 4
        ctx->r2 = S32(SIGNED(ctx->r16) >> 4);
            goto L_800D41CC;
    }
    // 0x800D41C0: sra         $v0, $s0, 4
    ctx->r2 = S32(SIGNED(ctx->r16) >> 4);
    // 0x800D41C4: addiu       $at, $s0, 0xF
    ctx->r1 = ADD32(ctx->r16, 0XF);
    // 0x800D41C8: sra         $v0, $at, 4
    ctx->r2 = S32(SIGNED(ctx->r1) >> 4);
L_800D41CC:
    // 0x800D41CC: bgtz        $v0, L_800D41DC
    if (SIGNED(ctx->r2) > 0) {
        // 0x800D41D0: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_800D41DC;
    }
    // 0x800D41D0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800D41D4: b           L_800D41DC
    // 0x800D41D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_800D41DC;
    // 0x800D41D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_800D41DC:
    // 0x800D41DC: bgtz        $v0, L_800D41EC
    if (SIGNED(ctx->r2) > 0) {
        // 0x800D41E0: addiu       $t6, $a1, 0x7FF
        ctx->r14 = ADD32(ctx->r5, 0X7FF);
            goto L_800D41EC;
    }
    // 0x800D41E0: addiu       $t6, $a1, 0x7FF
    ctx->r14 = ADD32(ctx->r5, 0X7FF);
    // 0x800D41E4: b           L_800D41F0
    // 0x800D41E8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800D41F0;
    // 0x800D41E8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800D41EC:
    // 0x800D41EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_800D41F0:
    // 0x800D41F0: div         $zero, $t6, $a0
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r4)));
    // 0x800D41F4: bne         $a0, $zero, L_800D4200
    if (ctx->r4 != 0) {
        // 0x800D41F8: nop
    
            goto L_800D4200;
    }
    // 0x800D41F8: nop

    // 0x800D41FC: break       7
    do_break(2148352508);
L_800D4200:
    // 0x800D4200: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800D4204: bne         $a0, $at, L_800D4218
    if (ctx->r4 != ctx->r1) {
        // 0x800D4208: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800D4218;
    }
    // 0x800D4208: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800D420C: bne         $t6, $at, L_800D4218
    if (ctx->r14 != ctx->r1) {
        // 0x800D4210: nop
    
            goto L_800D4218;
    }
    // 0x800D4210: nop

    // 0x800D4214: break       6
    do_break(2148352532);
L_800D4218:
    // 0x800D4218: mflo        $t7
    ctx->r15 = lo;
    // 0x800D421C: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x800D4220: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800D4224: andi        $t6, $a2, 0xFFF
    ctx->r14 = ctx->r6 & 0XFFF;
    // 0x800D4228: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x800D422C: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x800D4230: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x800D4234: sw          $t8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r24;
    // 0x800D4238: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800D423C: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x800D4240: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800D4244: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800D4248: lw          $t9, 0x1FC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1FC);
    // 0x800D424C: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D4250: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x800D4254: lbu         $t7, 0x30($t9)
    ctx->r15 = MEM_BU(ctx->r25, 0X30);
    // 0x800D4258: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D425C: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800D4260: andi        $t8, $t7, 0x7
    ctx->r24 = ctx->r15 & 0X7;
    // 0x800D4264: sll         $t6, $t8, 21
    ctx->r14 = S32(ctx->r24 << 21);
    // 0x800D4268: sra         $t7, $s0, 1
    ctx->r15 = S32(SIGNED(ctx->r16) >> 1);
    // 0x800D426C: addiu       $t8, $t7, 0x7
    ctx->r24 = ADD32(ctx->r15, 0X7);
    // 0x800D4270: or          $t9, $t6, $t3
    ctx->r25 = ctx->r14 | ctx->r11;
    // 0x800D4274: sra         $t6, $t8, 3
    ctx->r14 = S32(SIGNED(ctx->r24) >> 3);
    // 0x800D4278: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x800D427C: sll         $t8, $t7, 9
    ctx->r24 = S32(ctx->r15 << 9);
    // 0x800D4280: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x800D4284: lui         $t7, 0x8
    ctx->r15 = S32(0X8 << 16);
    // 0x800D4288: ori         $t7, $t7, 0x200
    ctx->r15 = ctx->r15 | 0X200;
    // 0x800D428C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800D4290: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x800D4294: addiu       $t8, $s0, -0x1
    ctx->r24 = ADD32(ctx->r16, -0X1);
    // 0x800D4298: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x800D429C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800D42A0: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x800D42A4: lw          $t8, 0x1D4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1D4);
    // 0x800D42A8: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x800D42AC: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x800D42B0: addiu       $t6, $t8, -0x1
    ctx->r14 = ADD32(ctx->r24, -0X1);
    // 0x800D42B4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800D42B8: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x800D42BC: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x800D42C0: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800D42C4: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
L_800D42C8:
    // 0x800D42C8: lw          $t7, 0x200($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X200);
    // 0x800D42CC: b           L_800D5320
    // 0x800D42D0: lw          $v0, 0x8($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X8);
        goto L_800D5320;
    // 0x800D42D0: lw          $v0, 0x8($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X8);
L_800D42D4:
    // 0x800D42D4: lhu         $t8, 0x14($t9)
    ctx->r24 = MEM_HU(ctx->r25, 0X14);
    // 0x800D42D8: lui         $a3, 0x10
    ctx->r7 = S32(0X10 << 16);
    // 0x800D42DC: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800D42E0: andi        $t6, $t8, 0x200
    ctx->r14 = ctx->r24 & 0X200;
    // 0x800D42E4: beq         $t6, $zero, L_800D4440
    if (ctx->r14 == 0) {
        // 0x800D42E8: or          $t0, $s0, $zero
        ctx->r8 = ctx->r16 | 0;
            goto L_800D4440;
    }
    // 0x800D42E8: or          $t0, $s0, $zero
    ctx->r8 = ctx->r16 | 0;
    // 0x800D42EC: lbu         $t7, 0x30($t9)
    ctx->r15 = MEM_BU(ctx->r25, 0X30);
    // 0x800D42F0: or          $t0, $t9, $zero
    ctx->r8 = ctx->r25 | 0;
    // 0x800D42F4: lui         $at, 0xFD00
    ctx->r1 = S32(0XFD00 << 16);
    // 0x800D42F8: andi        $t8, $t7, 0x7
    ctx->r24 = ctx->r15 & 0X7;
    // 0x800D42FC: sll         $t6, $t8, 21
    ctx->r14 = S32(ctx->r24 << 21);
    // 0x800D4300: or          $t9, $t6, $at
    ctx->r25 = ctx->r14 | ctx->r1;
    // 0x800D4304: or          $t7, $t9, $a3
    ctx->r15 = ctx->r25 | ctx->r7;
    // 0x800D4308: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800D430C: lw          $t8, 0x200($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X200);
    // 0x800D4310: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D4314: lui         $t3, 0xF500
    ctx->r11 = S32(0XF500 << 16);
    // 0x800D4318: lw          $t6, 0x8($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X8);
    // 0x800D431C: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x800D4320: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D4324: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800D4328: lbu         $t9, 0x30($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X30);
    // 0x800D432C: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x800D4330: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D4334: andi        $t7, $t9, 0x7
    ctx->r15 = ctx->r25 & 0X7;
    // 0x800D4338: sll         $t8, $t7, 21
    ctx->r24 = S32(ctx->r15 << 21);
    // 0x800D433C: or          $t6, $t8, $t3
    ctx->r14 = ctx->r24 | ctx->r11;
    // 0x800D4340: lui         $t7, 0x708
    ctx->r15 = S32(0X708 << 16);
    // 0x800D4344: ori         $t7, $t7, 0x200
    ctx->r15 = ctx->r15 | 0X200;
    // 0x800D4348: or          $t9, $t6, $a3
    ctx->r25 = ctx->r14 | ctx->r7;
    // 0x800D434C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800D4350: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x800D4354: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x800D4358: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800D435C: lw          $a3, 0x1D4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1D4);
    // 0x800D4360: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x800D4364: lui         $t6, 0xF300
    ctx->r14 = S32(0XF300 << 16);
    // 0x800D4368: multu       $s0, $a3
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D436C: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x800D4370: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x800D4374: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D4378: addiu       $a0, $zero, 0x7FF
    ctx->r4 = ADD32(0, 0X7FF);
    // 0x800D437C: mflo        $v0
    ctx->r2 = lo;
    // 0x800D4380: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800D4384: sra         $t9, $v0, 1
    ctx->r25 = S32(SIGNED(ctx->r2) >> 1);
    // 0x800D4388: addiu       $v0, $t9, -0x1
    ctx->r2 = ADD32(ctx->r25, -0X1);
    // 0x800D438C: slti        $at, $v0, 0x7FF
    ctx->r1 = SIGNED(ctx->r2) < 0X7FF ? 1 : 0;
    // 0x800D4390: beq         $at, $zero, L_800D43A0
    if (ctx->r1 == 0) {
        // 0x800D4394: lui         $t9, 0xE700
        ctx->r25 = S32(0XE700 << 16);
            goto L_800D43A0;
    }
    // 0x800D4394: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x800D4398: b           L_800D43A0
    // 0x800D439C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_800D43A0;
    // 0x800D439C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_800D43A0:
    // 0x800D43A0: andi        $t7, $a0, 0xFFF
    ctx->r15 = ctx->r4 & 0XFFF;
    // 0x800D43A4: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x800D43A8: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800D43AC: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x800D43B0: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x800D43B4: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800D43B8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800D43BC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800D43C0: lbu         $t7, 0x30($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X30);
    // 0x800D43C4: lui         $at, 0x8
    ctx->r1 = S32(0X8 << 16);
    // 0x800D43C8: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D43CC: andi        $t8, $t7, 0x7
    ctx->r24 = ctx->r15 & 0X7;
    // 0x800D43D0: sll         $t6, $t8, 21
    ctx->r14 = S32(ctx->r24 << 21);
    // 0x800D43D4: or          $t9, $t6, $t3
    ctx->r25 = ctx->r14 | ctx->r11;
    // 0x800D43D8: addiu       $t8, $s0, 0x7
    ctx->r24 = ADD32(ctx->r16, 0X7);
    // 0x800D43DC: sra         $t6, $t8, 3
    ctx->r14 = S32(SIGNED(ctx->r24) >> 3);
    // 0x800D43E0: or          $t7, $t9, $at
    ctx->r15 = ctx->r25 | ctx->r1;
    // 0x800D43E4: andi        $t9, $t6, 0x1FF
    ctx->r25 = ctx->r14 & 0X1FF;
    // 0x800D43E8: sll         $t8, $t9, 9
    ctx->r24 = S32(ctx->r25 << 9);
    // 0x800D43EC: or          $t6, $t7, $t8
    ctx->r14 = ctx->r15 | ctx->r24;
    // 0x800D43F0: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x800D43F4: lui         $t9, 0x8
    ctx->r25 = S32(0X8 << 16);
    // 0x800D43F8: ori         $t9, $t9, 0x200
    ctx->r25 = ctx->r25 | 0X200;
    // 0x800D43FC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800D4400: addiu       $t8, $s0, -0x1
    ctx->r24 = ADD32(ctx->r16, -0X1);
    // 0x800D4404: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x800D4408: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x800D440C: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D4410: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    // 0x800D4414: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x800D4418: lui         $t7, 0xF200
    ctx->r15 = S32(0XF200 << 16);
    // 0x800D441C: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x800D4420: addiu       $t8, $a3, -0x1
    ctx->r24 = ADD32(ctx->r7, -0X1);
    // 0x800D4424: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x800D4428: sll         $t7, $t9, 12
    ctx->r15 = S32(ctx->r25 << 12);
    // 0x800D442C: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x800D4430: or          $t8, $t7, $t9
    ctx->r24 = ctx->r15 | ctx->r25;
    // 0x800D4434: sw          $t8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r24;
    // 0x800D4438: b           L_800D4614
    // 0x800D443C: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
        goto L_800D4614;
    // 0x800D443C: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
L_800D4440:
    // 0x800D4440: lw          $t6, 0x1FC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1FC);
    // 0x800D4444: lui         $at, 0xFD00
    ctx->r1 = S32(0XFD00 << 16);
    // 0x800D4448: lui         $a3, 0x10
    ctx->r7 = S32(0X10 << 16);
    // 0x800D444C: lbu         $t7, 0x30($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X30);
    // 0x800D4450: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800D4454: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D4458: andi        $t9, $t7, 0x7
    ctx->r25 = ctx->r15 & 0X7;
    // 0x800D445C: sll         $t8, $t9, 21
    ctx->r24 = S32(ctx->r25 << 21);
    // 0x800D4460: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x800D4464: or          $t7, $t6, $a3
    ctx->r15 = ctx->r14 | ctx->r7;
    // 0x800D4468: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800D446C: lw          $t9, 0x200($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X200);
    // 0x800D4470: lui         $t3, 0xF500
    ctx->r11 = S32(0XF500 << 16);
    // 0x800D4474: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x800D4478: lw          $t8, 0x8($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X8);
    // 0x800D447C: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D4480: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x800D4484: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800D4488: lw          $t6, 0x1FC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1FC);
    // 0x800D448C: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D4490: addiu       $a2, $zero, 0x7FF
    ctx->r6 = ADD32(0, 0X7FF);
    // 0x800D4494: lbu         $t7, 0x30($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X30);
    // 0x800D4498: andi        $t9, $t7, 0x7
    ctx->r25 = ctx->r15 & 0X7;
    // 0x800D449C: sll         $t8, $t9, 21
    ctx->r24 = S32(ctx->r25 << 21);
    // 0x800D44A0: or          $t6, $t8, $t3
    ctx->r14 = ctx->r24 | ctx->r11;
    // 0x800D44A4: lui         $t9, 0x708
    ctx->r25 = S32(0X708 << 16);
    // 0x800D44A8: ori         $t9, $t9, 0x200
    ctx->r25 = ctx->r25 | 0X200;
    // 0x800D44AC: or          $t7, $t6, $a3
    ctx->r15 = ctx->r14 | ctx->r7;
    // 0x800D44B0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800D44B4: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x800D44B8: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x800D44BC: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800D44C0: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x800D44C4: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
    // 0x800D44C8: lui         $t6, 0xF300
    ctx->r14 = S32(0XF300 << 16);
    // 0x800D44CC: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x800D44D0: lw          $t7, 0x1D4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1D4);
    // 0x800D44D4: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D44D8: multu       $s0, $t7
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D44DC: mflo        $v0
    ctx->r2 = lo;
    // 0x800D44E0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800D44E4: sra         $t9, $v0, 1
    ctx->r25 = S32(SIGNED(ctx->r2) >> 1);
    // 0x800D44E8: addiu       $v0, $t9, -0x1
    ctx->r2 = ADD32(ctx->r25, -0X1);
    // 0x800D44EC: slti        $at, $v0, 0x7FF
    ctx->r1 = SIGNED(ctx->r2) < 0X7FF ? 1 : 0;
    // 0x800D44F0: beq         $at, $zero, L_800D4500
    if (ctx->r1 == 0) {
        // 0x800D44F4: nop
    
            goto L_800D4500;
    }
    // 0x800D44F4: nop

    // 0x800D44F8: b           L_800D4500
    // 0x800D44FC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
        goto L_800D4500;
    // 0x800D44FC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_800D4500:
    // 0x800D4500: bgez        $t0, L_800D4510
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800D4504: sra         $t2, $t0, 3
        ctx->r10 = S32(SIGNED(ctx->r8) >> 3);
            goto L_800D4510;
    }
    // 0x800D4504: sra         $t2, $t0, 3
    ctx->r10 = S32(SIGNED(ctx->r8) >> 3);
    // 0x800D4508: addiu       $at, $t0, 0x7
    ctx->r1 = ADD32(ctx->r8, 0X7);
    // 0x800D450C: sra         $t2, $at, 3
    ctx->r10 = S32(SIGNED(ctx->r1) >> 3);
L_800D4510:
    // 0x800D4510: bgtz        $t2, L_800D4520
    if (SIGNED(ctx->r10) > 0) {
        // 0x800D4514: or          $v0, $t1, $zero
        ctx->r2 = ctx->r9 | 0;
            goto L_800D4520;
    }
    // 0x800D4514: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800D4518: b           L_800D4524
    // 0x800D451C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_800D4524;
    // 0x800D451C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_800D4520:
    // 0x800D4520: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
L_800D4524:
    // 0x800D4524: bgtz        $t2, L_800D4534
    if (SIGNED(ctx->r10) > 0) {
        // 0x800D4528: addiu       $t8, $a1, 0x7FF
        ctx->r24 = ADD32(ctx->r5, 0X7FF);
            goto L_800D4534;
    }
    // 0x800D4528: addiu       $t8, $a1, 0x7FF
    ctx->r24 = ADD32(ctx->r5, 0X7FF);
    // 0x800D452C: b           L_800D4538
    // 0x800D4530: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800D4538;
    // 0x800D4530: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800D4534:
    // 0x800D4534: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
L_800D4538:
    // 0x800D4538: div         $zero, $t8, $a0
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r4)));
    // 0x800D453C: bne         $a0, $zero, L_800D4548
    if (ctx->r4 != 0) {
        // 0x800D4540: nop
    
            goto L_800D4548;
    }
    // 0x800D4540: nop

    // 0x800D4544: break       7
    do_break(2148353348);
L_800D4548:
    // 0x800D4548: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800D454C: bne         $a0, $at, L_800D4560
    if (ctx->r4 != ctx->r1) {
        // 0x800D4550: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800D4560;
    }
    // 0x800D4550: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800D4554: bne         $t8, $at, L_800D4560
    if (ctx->r24 != ctx->r1) {
        // 0x800D4558: nop
    
            goto L_800D4560;
    }
    // 0x800D4558: nop

    // 0x800D455C: break       6
    do_break(2148353372);
L_800D4560:
    // 0x800D4560: mflo        $t6
    ctx->r14 = lo;
    // 0x800D4564: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x800D4568: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800D456C: andi        $t8, $a2, 0xFFF
    ctx->r24 = ctx->r6 & 0XFFF;
    // 0x800D4570: sll         $t6, $t8, 12
    ctx->r14 = S32(ctx->r24 << 12);
    // 0x800D4574: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x800D4578: or          $t7, $t9, $t6
    ctx->r15 = ctx->r25 | ctx->r14;
    // 0x800D457C: sw          $t7, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r15;
    // 0x800D4580: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x800D4584: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800D4588: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800D458C: lw          $t9, 0x1FC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1FC);
    // 0x800D4590: lui         $at, 0x8
    ctx->r1 = S32(0X8 << 16);
    // 0x800D4594: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D4598: lbu         $t6, 0x30($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0X30);
    // 0x800D459C: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x800D45A0: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D45A4: andi        $t7, $t6, 0x7
    ctx->r15 = ctx->r14 & 0X7;
    // 0x800D45A8: sll         $t8, $t7, 21
    ctx->r24 = S32(ctx->r15 << 21);
    // 0x800D45AC: or          $t9, $t8, $t3
    ctx->r25 = ctx->r24 | ctx->r11;
    // 0x800D45B0: addiu       $t7, $t0, 0x7
    ctx->r15 = ADD32(ctx->r8, 0X7);
    // 0x800D45B4: sra         $t8, $t7, 3
    ctx->r24 = S32(SIGNED(ctx->r15) >> 3);
    // 0x800D45B8: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x800D45BC: andi        $t9, $t8, 0x1FF
    ctx->r25 = ctx->r24 & 0X1FF;
    // 0x800D45C0: sll         $t7, $t9, 9
    ctx->r15 = S32(ctx->r25 << 9);
    // 0x800D45C4: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x800D45C8: lui         $t9, 0x8
    ctx->r25 = S32(0X8 << 16);
    // 0x800D45CC: ori         $t9, $t9, 0x200
    ctx->r25 = ctx->r25 | 0X200;
    // 0x800D45D0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800D45D4: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x800D45D8: addiu       $t7, $s0, -0x1
    ctx->r15 = ADD32(ctx->r16, -0X1);
    // 0x800D45DC: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x800D45E0: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800D45E4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800D45E8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800D45EC: lw          $t7, 0x1D4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1D4);
    // 0x800D45F0: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x800D45F4: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x800D45F8: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x800D45FC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800D4600: andi        $t7, $t9, 0xFFF
    ctx->r15 = ctx->r25 & 0XFFF;
    // 0x800D4604: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x800D4608: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800D460C: lw          $t0, 0x1FC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1FC);
    // 0x800D4610: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
L_800D4614:
    // 0x800D4614: lw          $t9, 0x200($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X200);
    // 0x800D4618: b           L_800D5320
    // 0x800D461C: lw          $v0, 0x8($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X8);
        goto L_800D5320;
    // 0x800D461C: lw          $v0, 0x8($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X8);
L_800D4620:
    // 0x800D4620: lbu         $a0, 0x30($a2)
    ctx->r4 = MEM_BU(ctx->r6, 0X30);
    // 0x800D4624: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800D4628: bnel        $a0, $at, L_800D4CC8
    if (ctx->r4 != ctx->r1) {
        // 0x800D462C: lhu         $t7, 0x14($a2)
        ctx->r15 = MEM_HU(ctx->r6, 0X14);
            goto L_800D4CC8;
    }
    goto skip_7;
    // 0x800D462C: lhu         $t7, 0x14($a2)
    ctx->r15 = MEM_HU(ctx->r6, 0X14);
    skip_7:
    // 0x800D4630: lhu         $t6, 0x14($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0X14);
    // 0x800D4634: lui         $a3, 0x10
    ctx->r7 = S32(0X10 << 16);
    // 0x800D4638: lw          $t0, 0x200($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X200);
    // 0x800D463C: andi        $t7, $t6, 0x200
    ctx->r15 = ctx->r14 & 0X200;
    // 0x800D4640: beq         $t7, $zero, L_800D4790
    if (ctx->r15 == 0) {
        // 0x800D4644: or          $v0, $t1, $zero
        ctx->r2 = ctx->r9 | 0;
            goto L_800D4790;
    }
    // 0x800D4644: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800D4648: andi        $t8, $a0, 0x7
    ctx->r24 = ctx->r4 & 0X7;
    // 0x800D464C: sll         $t9, $t8, 21
    ctx->r25 = S32(ctx->r24 << 21);
    // 0x800D4650: lui         $at, 0xFD00
    ctx->r1 = S32(0XFD00 << 16);
    // 0x800D4654: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x800D4658: or          $t7, $t6, $a3
    ctx->r15 = ctx->r14 | ctx->r7;
    // 0x800D465C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800D4660: lw          $t8, 0x200($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X200);
    // 0x800D4664: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D4668: lui         $t3, 0xF500
    ctx->r11 = S32(0XF500 << 16);
    // 0x800D466C: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x800D4670: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x800D4674: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D4678: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800D467C: lbu         $t6, 0x30($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X30);
    // 0x800D4680: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x800D4684: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D4688: andi        $t7, $t6, 0x7
    ctx->r15 = ctx->r14 & 0X7;
    // 0x800D468C: sll         $t8, $t7, 21
    ctx->r24 = S32(ctx->r15 << 21);
    // 0x800D4690: or          $t9, $t8, $t3
    ctx->r25 = ctx->r24 | ctx->r11;
    // 0x800D4694: lui         $t7, 0x708
    ctx->r15 = S32(0X708 << 16);
    // 0x800D4698: ori         $t7, $t7, 0x200
    ctx->r15 = ctx->r15 | 0X200;
    // 0x800D469C: or          $t6, $t9, $a3
    ctx->r14 = ctx->r25 | ctx->r7;
    // 0x800D46A0: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800D46A4: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x800D46A8: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x800D46AC: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x800D46B0: lw          $t0, 0x1D4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1D4);
    // 0x800D46B4: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x800D46B8: lui         $t9, 0xF300
    ctx->r25 = S32(0XF300 << 16);
    // 0x800D46BC: multu       $s0, $t0
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D46C0: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    // 0x800D46C4: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800D46C8: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x800D46CC: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D46D0: addiu       $a0, $zero, 0x7FF
    ctx->r4 = ADD32(0, 0X7FF);
    // 0x800D46D4: mflo        $v0
    ctx->r2 = lo;
    // 0x800D46D8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800D46DC: slti        $at, $v0, 0x7FF
    ctx->r1 = SIGNED(ctx->r2) < 0X7FF ? 1 : 0;
    // 0x800D46E0: beq         $at, $zero, L_800D46F0
    if (ctx->r1 == 0) {
        // 0x800D46E4: nop
    
            goto L_800D46F0;
    }
    // 0x800D46E4: nop

    // 0x800D46E8: b           L_800D46F0
    // 0x800D46EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_800D46F0;
    // 0x800D46EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_800D46F0:
    // 0x800D46F0: andi        $t6, $a0, 0xFFF
    ctx->r14 = ctx->r4 & 0XFFF;
    // 0x800D46F4: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x800D46F8: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800D46FC: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x800D4700: sw          $t8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r24;
    // 0x800D4704: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800D4708: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800D470C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800D4710: lw          $t6, 0x1FC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1FC);
    // 0x800D4714: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D4718: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x800D471C: lbu         $t7, 0x30($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X30);
    // 0x800D4720: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D4724: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x800D4728: andi        $t8, $t7, 0x7
    ctx->r24 = ctx->r15 & 0X7;
    // 0x800D472C: sll         $t9, $t8, 21
    ctx->r25 = S32(ctx->r24 << 21);
    // 0x800D4730: or          $t6, $t9, $t3
    ctx->r14 = ctx->r25 | ctx->r11;
    // 0x800D4734: addiu       $t8, $s0, 0x7
    ctx->r24 = ADD32(ctx->r16, 0X7);
    // 0x800D4738: sra         $t9, $t8, 3
    ctx->r25 = S32(SIGNED(ctx->r24) >> 3);
    // 0x800D473C: or          $t7, $t6, $a3
    ctx->r15 = ctx->r14 | ctx->r7;
    // 0x800D4740: andi        $t6, $t9, 0x1FF
    ctx->r14 = ctx->r25 & 0X1FF;
    // 0x800D4744: sll         $t8, $t6, 9
    ctx->r24 = S32(ctx->r14 << 9);
    // 0x800D4748: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x800D474C: lui         $t6, 0x8
    ctx->r14 = S32(0X8 << 16);
    // 0x800D4750: ori         $t6, $t6, 0x200
    ctx->r14 = ctx->r14 | 0X200;
    // 0x800D4754: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800D4758: addiu       $t8, $s0, -0x1
    ctx->r24 = ADD32(ctx->r16, -0X1);
    // 0x800D475C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800D4760: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x800D4764: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x800D4768: lui         $t7, 0xF200
    ctx->r15 = S32(0XF200 << 16);
    // 0x800D476C: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x800D4770: addiu       $t8, $t0, -0x1
    ctx->r24 = ADD32(ctx->r8, -0X1);
    // 0x800D4774: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800D4778: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x800D477C: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x800D4780: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x800D4784: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    // 0x800D4788: b           L_800D4FE0
    // 0x800D478C: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
        goto L_800D4FE0;
    // 0x800D478C: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
L_800D4790:
    // 0x800D4790: lh          $t9, 0xE($t0)
    ctx->r25 = MEM_H(ctx->r8, 0XE);
    // 0x800D4794: lui         $a3, 0x10
    ctx->r7 = S32(0X10 << 16);
    // 0x800D4798: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800D479C: beq         $t9, $zero, L_800D4B10
    if (ctx->r25 == 0) {
        // 0x800D47A0: lui         $at, 0xFD00
        ctx->r1 = S32(0XFD00 << 16);
            goto L_800D4B10;
    }
    // 0x800D47A0: lui         $at, 0xFD00
    ctx->r1 = S32(0XFD00 << 16);
    // 0x800D47A4: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800D47A8: lui         $t7, 0xFD88
    ctx->r15 = S32(0XFD88 << 16);
    // 0x800D47AC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800D47B0: lw          $t6, 0x8($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X8);
    // 0x800D47B4: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D47B8: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x800D47BC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800D47C0: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D47C4: lui         $t8, 0xF588
    ctx->r24 = S32(0XF588 << 16);
    // 0x800D47C8: lui         $t9, 0x708
    ctx->r25 = S32(0X708 << 16);
    // 0x800D47CC: ori         $t9, $t9, 0x200
    ctx->r25 = ctx->r25 | 0X200;
    // 0x800D47D0: ori         $t8, $t8, 0x100
    ctx->r24 = ctx->r24 | 0X100;
    // 0x800D47D4: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x800D47D8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800D47DC: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x800D47E0: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D47E4: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x800D47E8: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800D47EC: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x800D47F0: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
    // 0x800D47F4: lui         $t6, 0xF300
    ctx->r14 = S32(0XF300 << 16);
    // 0x800D47F8: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x800D47FC: lw          $t8, 0x1D4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1D4);
    // 0x800D4800: sll         $t5, $s0, 2
    ctx->r13 = S32(ctx->r16 << 2);
    // 0x800D4804: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D4808: multu       $s0, $t8
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D480C: or          $t2, $s0, $zero
    ctx->r10 = ctx->r16 | 0;
    // 0x800D4810: addiu       $a2, $zero, 0x7FF
    ctx->r6 = ADD32(0, 0X7FF);
    // 0x800D4814: subu        $t5, $t5, $s0
    ctx->r13 = SUB32(ctx->r13, ctx->r16);
    // 0x800D4818: mflo        $v1
    ctx->r3 = lo;
    // 0x800D481C: addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // 0x800D4820: slti        $at, $v0, 0x7FF
    ctx->r1 = SIGNED(ctx->r2) < 0X7FF ? 1 : 0;
    // 0x800D4824: beq         $at, $zero, L_800D4834
    if (ctx->r1 == 0) {
        // 0x800D4828: nop
    
            goto L_800D4834;
    }
    // 0x800D4828: nop

    // 0x800D482C: b           L_800D4834
    // 0x800D4830: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
        goto L_800D4834;
    // 0x800D4830: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_800D4834:
    // 0x800D4834: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800D4838: bgez        $t2, L_800D4848
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800D483C: sra         $t9, $t2, 3
        ctx->r25 = S32(SIGNED(ctx->r10) >> 3);
            goto L_800D4848;
    }
    // 0x800D483C: sra         $t9, $t2, 3
    ctx->r25 = S32(SIGNED(ctx->r10) >> 3);
    // 0x800D4840: addiu       $at, $t2, 0x7
    ctx->r1 = ADD32(ctx->r10, 0X7);
    // 0x800D4844: sra         $t9, $at, 3
    ctx->r25 = S32(SIGNED(ctx->r1) >> 3);
L_800D4848:
    // 0x800D4848: bgtz        $t9, L_800D4858
    if (SIGNED(ctx->r25) > 0) {
        // 0x800D484C: or          $t2, $t9, $zero
        ctx->r10 = ctx->r25 | 0;
            goto L_800D4858;
    }
    // 0x800D484C: or          $t2, $t9, $zero
    ctx->r10 = ctx->r25 | 0;
    // 0x800D4850: b           L_800D485C
    // 0x800D4854: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_800D485C;
    // 0x800D4854: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_800D4858:
    // 0x800D4858: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
L_800D485C:
    // 0x800D485C: bgtz        $t2, L_800D486C
    if (SIGNED(ctx->r10) > 0) {
        // 0x800D4860: addiu       $t7, $a1, 0x7FF
        ctx->r15 = ADD32(ctx->r5, 0X7FF);
            goto L_800D486C;
    }
    // 0x800D4860: addiu       $t7, $a1, 0x7FF
    ctx->r15 = ADD32(ctx->r5, 0X7FF);
    // 0x800D4864: b           L_800D4870
    // 0x800D4868: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800D4870;
    // 0x800D4868: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800D486C:
    // 0x800D486C: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
L_800D4870:
    // 0x800D4870: div         $zero, $t7, $a0
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r4)));
    // 0x800D4874: bne         $a0, $zero, L_800D4880
    if (ctx->r4 != 0) {
        // 0x800D4878: nop
    
            goto L_800D4880;
    }
    // 0x800D4878: nop

    // 0x800D487C: break       7
    do_break(2148354172);
L_800D4880:
    // 0x800D4880: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800D4884: bne         $a0, $at, L_800D4898
    if (ctx->r4 != ctx->r1) {
        // 0x800D4888: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800D4898;
    }
    // 0x800D4888: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800D488C: bne         $t7, $at, L_800D4898
    if (ctx->r15 != ctx->r1) {
        // 0x800D4890: nop
    
            goto L_800D4898;
    }
    // 0x800D4890: nop

    // 0x800D4894: break       6
    do_break(2148354196);
L_800D4898:
    // 0x800D4898: mflo        $t6
    ctx->r14 = lo;
    // 0x800D489C: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x800D48A0: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800D48A4: andi        $t7, $a2, 0xFFF
    ctx->r15 = ctx->r6 & 0XFFF;
    // 0x800D48A8: sll         $t6, $t7, 12
    ctx->r14 = S32(ctx->r15 << 12);
    // 0x800D48AC: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x800D48B0: or          $t8, $t9, $t6
    ctx->r24 = ctx->r25 | ctx->r14;
    // 0x800D48B4: sw          $t8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r24;
    // 0x800D48B8: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800D48BC: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x800D48C0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800D48C4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800D48C8: lw          $t6, 0x200($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X200);
    // 0x800D48CC: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D48D0: bgez        $v1, L_800D48E0
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800D48D4: sra         $t9, $v1, 1
        ctx->r25 = S32(SIGNED(ctx->r3) >> 1);
            goto L_800D48E0;
    }
    // 0x800D48D4: sra         $t9, $v1, 1
    ctx->r25 = S32(SIGNED(ctx->r3) >> 1);
    // 0x800D48D8: addiu       $at, $v1, 0x1
    ctx->r1 = ADD32(ctx->r3, 0X1);
    // 0x800D48DC: sra         $t9, $at, 1
    ctx->r25 = S32(SIGNED(ctx->r1) >> 1);
L_800D48E0:
    // 0x800D48E0: lh          $t8, 0xE($t6)
    ctx->r24 = MEM_H(ctx->r14, 0XE);
    // 0x800D48E4: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800D48E8: multu       $t9, $t8
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D48EC: lw          $t9, 0x8($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X8);
    // 0x800D48F0: lw          $t6, 0x1D4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1D4);
    // 0x800D48F4: addiu       $t3, $t6, -0x2
    ctx->r11 = ADD32(ctx->r14, -0X2);
    // 0x800D48F8: mflo        $t7
    ctx->r15 = lo;
    // 0x800D48FC: addu        $t8, $t9, $t7
    ctx->r24 = ADD32(ctx->r25, ctx->r15);
    // 0x800D4900: sw          $t8, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->r24;
    // 0x800D4904: bgez        $t6, L_800D4914
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800D4908: sra         $t4, $t6, 1
        ctx->r12 = S32(SIGNED(ctx->r14) >> 1);
            goto L_800D4914;
    }
    // 0x800D4908: sra         $t4, $t6, 1
    ctx->r12 = S32(SIGNED(ctx->r14) >> 1);
    // 0x800D490C: addiu       $at, $t6, 0x1
    ctx->r1 = ADD32(ctx->r14, 0X1);
    // 0x800D4910: sra         $t4, $at, 1
    ctx->r12 = S32(SIGNED(ctx->r1) >> 1);
L_800D4914:
    // 0x800D4914: bltzl       $t4, L_800D4A88
    if (SIGNED(ctx->r12) < 0) {
        // 0x800D4918: lw          $t6, 0x1FC($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X1FC);
            goto L_800D4A88;
    }
    goto skip_8;
    // 0x800D4918: lw          $t6, 0x1FC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1FC);
    skip_8:
    // 0x800D491C: bgez        $s0, L_800D492C
    if (SIGNED(ctx->r16) >= 0) {
        // 0x800D4920: sra         $t9, $s0, 3
        ctx->r25 = S32(SIGNED(ctx->r16) >> 3);
            goto L_800D492C;
    }
    // 0x800D4920: sra         $t9, $s0, 3
    ctx->r25 = S32(SIGNED(ctx->r16) >> 3);
    // 0x800D4924: addiu       $at, $s0, 0x7
    ctx->r1 = ADD32(ctx->r16, 0X7);
    // 0x800D4928: sra         $t9, $at, 3
    ctx->r25 = S32(SIGNED(ctx->r1) >> 3);
L_800D492C:
    // 0x800D492C: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
L_800D4930:
    // 0x800D4930: subu        $t7, $t4, $t0
    ctx->r15 = SUB32(ctx->r12, ctx->r8);
    // 0x800D4934: addiu       $t8, $t7, -0x2
    ctx->r24 = ADD32(ctx->r15, -0X2);
    // 0x800D4938: multu       $t8, $s0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D493C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800D4940: lw          $t6, 0x118($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X118);
    // 0x800D4944: or          $a3, $t5, $zero
    ctx->r7 = ctx->r13 | 0;
    // 0x800D4948: lui         $at, 0xF588
    ctx->r1 = S32(0XF588 << 16);
    // 0x800D494C: mflo        $t9
    ctx->r25 = lo;
    // 0x800D4950: addu        $a0, $t9, $t6
    ctx->r4 = ADD32(ctx->r25, ctx->r14);
    // 0x800D4954: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800D4958: multu       $t7, $t3
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D495C: addiu       $t3, $t3, -0x2
    ctx->r11 = ADD32(ctx->r11, -0X2);
    // 0x800D4960: lui         $t9, 0xFD88
    ctx->r25 = S32(0XFD88 << 16);
    // 0x800D4964: mflo        $v1
    ctx->r3 = lo;
    // 0x800D4968: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x800D496C: bgez        $v1, L_800D4984
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800D4970: negu        $v0, $v1
        ctx->r2 = SUB32(0, ctx->r3);
            goto L_800D4984;
    }
    // 0x800D4970: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
    // 0x800D4974: sll         $t8, $v0, 3
    ctx->r24 = S32(ctx->r2 << 3);
    // 0x800D4978: addu        $a1, $a0, $t8
    ctx->r5 = ADD32(ctx->r4, ctx->r24);
    // 0x800D497C: subu        $a3, $t5, $t8
    ctx->r7 = SUB32(ctx->r13, ctx->r24);
    // 0x800D4980: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_800D4984:
    // 0x800D4984: bne         $t0, $zero, L_800D4990
    if (ctx->r8 != 0) {
        // 0x800D4988: or          $v0, $t1, $zero
        ctx->r2 = ctx->r9 | 0;
            goto L_800D4990;
    }
    // 0x800D4988: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800D498C: sll         $a3, $s0, 1
    ctx->r7 = S32(ctx->r16 << 1);
L_800D4990:
    // 0x800D4990: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D4994: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800D4998: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x800D499C: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
    // 0x800D49A0: andi        $t6, $a2, 0x1FF
    ctx->r14 = ctx->r6 & 0X1FF;
    // 0x800D49A4: lui         $t8, 0x708
    ctx->r24 = S32(0X708 << 16);
    // 0x800D49A8: ori         $t8, $t8, 0x200
    ctx->r24 = ctx->r24 | 0X200;
    // 0x800D49AC: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x800D49B0: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D49B4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800D49B8: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800D49BC: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x800D49C0: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D49C4: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x800D49C8: addiu       $v0, $a3, -0x1
    ctx->r2 = ADD32(ctx->r7, -0X1);
    // 0x800D49CC: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800D49D0: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x800D49D4: slti        $at, $v0, 0x7FF
    ctx->r1 = SIGNED(ctx->r2) < 0X7FF ? 1 : 0;
    // 0x800D49D8: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x800D49DC: lui         $t6, 0xF300
    ctx->r14 = S32(0XF300 << 16);
    // 0x800D49E0: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800D49E4: beq         $at, $zero, L_800D49F4
    if (ctx->r1 == 0) {
        // 0x800D49E8: addiu       $t1, $t1, 0x8
        ctx->r9 = ADD32(ctx->r9, 0X8);
            goto L_800D49F4;
    }
    // 0x800D49E8: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D49EC: b           L_800D49F8
    // 0x800D49F0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
        goto L_800D49F8;
    // 0x800D49F0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_800D49F4:
    // 0x800D49F4: addiu       $a2, $zero, 0x7FF
    ctx->r6 = ADD32(0, 0X7FF);
L_800D49F8:
    // 0x800D49F8: bgtz        $t2, L_800D4A08
    if (SIGNED(ctx->r10) > 0) {
        // 0x800D49FC: or          $v0, $t1, $zero
        ctx->r2 = ctx->r9 | 0;
            goto L_800D4A08;
    }
    // 0x800D49FC: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800D4A00: b           L_800D4A0C
    // 0x800D4A04: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_800D4A0C;
    // 0x800D4A04: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_800D4A08:
    // 0x800D4A08: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
L_800D4A0C:
    // 0x800D4A0C: bgtz        $t2, L_800D4A1C
    if (SIGNED(ctx->r10) > 0) {
        // 0x800D4A10: addiu       $t7, $a1, 0x7FF
        ctx->r15 = ADD32(ctx->r5, 0X7FF);
            goto L_800D4A1C;
    }
    // 0x800D4A10: addiu       $t7, $a1, 0x7FF
    ctx->r15 = ADD32(ctx->r5, 0X7FF);
    // 0x800D4A14: b           L_800D4A20
    // 0x800D4A18: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800D4A20;
    // 0x800D4A18: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800D4A1C:
    // 0x800D4A1C: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
L_800D4A20:
    // 0x800D4A20: div         $zero, $t7, $a0
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r4)));
    // 0x800D4A24: bne         $a0, $zero, L_800D4A30
    if (ctx->r4 != 0) {
        // 0x800D4A28: nop
    
            goto L_800D4A30;
    }
    // 0x800D4A28: nop

    // 0x800D4A2C: break       7
    do_break(2148354604);
L_800D4A30:
    // 0x800D4A30: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800D4A34: bne         $a0, $at, L_800D4A48
    if (ctx->r4 != ctx->r1) {
        // 0x800D4A38: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800D4A48;
    }
    // 0x800D4A38: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800D4A3C: bne         $t7, $at, L_800D4A48
    if (ctx->r15 != ctx->r1) {
        // 0x800D4A40: nop
    
            goto L_800D4A48;
    }
    // 0x800D4A40: nop

    // 0x800D4A44: break       6
    do_break(2148354628);
L_800D4A48:
    // 0x800D4A48: mflo        $t8
    ctx->r24 = lo;
    // 0x800D4A4C: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x800D4A50: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800D4A54: andi        $t7, $a2, 0xFFF
    ctx->r15 = ctx->r6 & 0XFFF;
    // 0x800D4A58: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x800D4A5C: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x800D4A60: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x800D4A64: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x800D4A68: slt         $at, $t4, $t0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800D4A6C: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x800D4A70: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x800D4A74: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800D4A78: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800D4A7C: beq         $at, $zero, L_800D4930
    if (ctx->r1 == 0) {
        // 0x800D4A80: addiu       $t1, $t1, 0x8
        ctx->r9 = ADD32(ctx->r9, 0X8);
            goto L_800D4930;
    }
    // 0x800D4A80: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D4A84: lw          $t6, 0x1FC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1FC);
L_800D4A88:
    // 0x800D4A88: lui         $t3, 0xF500
    ctx->r11 = S32(0XF500 << 16);
    // 0x800D4A8C: lui         $a3, 0x10
    ctx->r7 = S32(0X10 << 16);
    // 0x800D4A90: lbu         $t8, 0x30($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X30);
    // 0x800D4A94: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800D4A98: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D4A9C: andi        $t9, $t8, 0x7
    ctx->r25 = ctx->r24 & 0X7;
    // 0x800D4AA0: sll         $t7, $t9, 21
    ctx->r15 = S32(ctx->r25 << 21);
    // 0x800D4AA4: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800D4AA8: or          $t6, $t7, $t3
    ctx->r14 = ctx->r15 | ctx->r11;
    // 0x800D4AAC: or          $t8, $t6, $a3
    ctx->r24 = ctx->r14 | ctx->r7;
    // 0x800D4AB0: addiu       $t7, $t9, 0x7
    ctx->r15 = ADD32(ctx->r25, 0X7);
    // 0x800D4AB4: sra         $t6, $t7, 3
    ctx->r14 = S32(SIGNED(ctx->r15) >> 3);
    // 0x800D4AB8: andi        $t9, $t6, 0x1FF
    ctx->r25 = ctx->r14 & 0X1FF;
    // 0x800D4ABC: sll         $t7, $t9, 9
    ctx->r15 = S32(ctx->r25 << 9);
    // 0x800D4AC0: or          $t6, $t8, $t7
    ctx->r14 = ctx->r24 | ctx->r15;
    // 0x800D4AC4: lui         $t9, 0x8
    ctx->r25 = S32(0X8 << 16);
    // 0x800D4AC8: ori         $t9, $t9, 0x200
    ctx->r25 = ctx->r25 | 0X200;
    // 0x800D4ACC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800D4AD0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800D4AD4: addiu       $t7, $s0, -0x1
    ctx->r15 = ADD32(ctx->r16, -0X1);
    // 0x800D4AD8: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x800D4ADC: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x800D4AE0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800D4AE4: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x800D4AE8: lw          $t7, 0x1D4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1D4);
    // 0x800D4AEC: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x800D4AF0: sll         $t8, $t9, 12
    ctx->r24 = S32(ctx->r25 << 12);
    // 0x800D4AF4: addiu       $t6, $t7, -0x1
    ctx->r14 = ADD32(ctx->r15, -0X1);
    // 0x800D4AF8: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x800D4AFC: andi        $t7, $t9, 0xFFF
    ctx->r15 = ctx->r25 & 0XFFF;
    // 0x800D4B00: or          $t6, $t8, $t7
    ctx->r14 = ctx->r24 | ctx->r15;
    // 0x800D4B04: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x800D4B08: b           L_800D4FE0
    // 0x800D4B0C: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
        goto L_800D4FE0;
    // 0x800D4B0C: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
L_800D4B10:
    // 0x800D4B10: andi        $t9, $a0, 0x7
    ctx->r25 = ctx->r4 & 0X7;
    // 0x800D4B14: sll         $t8, $t9, 21
    ctx->r24 = S32(ctx->r25 << 21);
    // 0x800D4B18: or          $t7, $t8, $at
    ctx->r15 = ctx->r24 | ctx->r1;
    // 0x800D4B1C: or          $t6, $t7, $a3
    ctx->r14 = ctx->r15 | ctx->r7;
    // 0x800D4B20: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800D4B24: lw          $t9, 0x8($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X8);
    // 0x800D4B28: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D4B2C: lui         $t3, 0xF500
    ctx->r11 = S32(0XF500 << 16);
    // 0x800D4B30: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800D4B34: lbu         $t8, 0x30($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X30);
    // 0x800D4B38: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x800D4B3C: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D4B40: andi        $t7, $t8, 0x7
    ctx->r15 = ctx->r24 & 0X7;
    // 0x800D4B44: sll         $t6, $t7, 21
    ctx->r14 = S32(ctx->r15 << 21);
    // 0x800D4B48: or          $t9, $t6, $t3
    ctx->r25 = ctx->r14 | ctx->r11;
    // 0x800D4B4C: lui         $t7, 0x708
    ctx->r15 = S32(0X708 << 16);
    // 0x800D4B50: ori         $t7, $t7, 0x200
    ctx->r15 = ctx->r15 | 0X200;
    // 0x800D4B54: or          $t8, $t9, $a3
    ctx->r24 = ctx->r25 | ctx->r7;
    // 0x800D4B58: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x800D4B5C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800D4B60: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x800D4B64: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D4B68: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x800D4B6C: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x800D4B70: or          $t0, $t1, $zero
    ctx->r8 = ctx->r9 | 0;
    // 0x800D4B74: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x800D4B78: lui         $t9, 0xF300
    ctx->r25 = S32(0XF300 << 16);
    // 0x800D4B7C: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800D4B80: lw          $t8, 0x1D4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1D4);
    // 0x800D4B84: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D4B88: addiu       $a2, $zero, 0x7FF
    ctx->r6 = ADD32(0, 0X7FF);
    // 0x800D4B8C: multu       $s0, $t8
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D4B90: mflo        $v0
    ctx->r2 = lo;
    // 0x800D4B94: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800D4B98: slti        $at, $v0, 0x7FF
    ctx->r1 = SIGNED(ctx->r2) < 0X7FF ? 1 : 0;
    // 0x800D4B9C: beq         $at, $zero, L_800D4BAC
    if (ctx->r1 == 0) {
        // 0x800D4BA0: nop
    
            goto L_800D4BAC;
    }
    // 0x800D4BA0: nop

    // 0x800D4BA4: b           L_800D4BAC
    // 0x800D4BA8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
        goto L_800D4BAC;
    // 0x800D4BA8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_800D4BAC:
    // 0x800D4BAC: sll         $v0, $s0, 1
    ctx->r2 = S32(ctx->r16 << 1);
    // 0x800D4BB0: bgez        $v0, L_800D4BC0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800D4BB4: sra         $t7, $v0, 3
        ctx->r15 = S32(SIGNED(ctx->r2) >> 3);
            goto L_800D4BC0;
    }
    // 0x800D4BB4: sra         $t7, $v0, 3
    ctx->r15 = S32(SIGNED(ctx->r2) >> 3);
    // 0x800D4BB8: addiu       $at, $v0, 0x7
    ctx->r1 = ADD32(ctx->r2, 0X7);
    // 0x800D4BBC: sra         $t7, $at, 3
    ctx->r15 = S32(SIGNED(ctx->r1) >> 3);
L_800D4BC0:
    // 0x800D4BC0: bgtz        $t7, L_800D4BD0
    if (SIGNED(ctx->r15) > 0) {
        // 0x800D4BC4: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_800D4BD0;
    }
    // 0x800D4BC4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800D4BC8: b           L_800D4BD4
    // 0x800D4BCC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_800D4BD4;
    // 0x800D4BCC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_800D4BD0:
    // 0x800D4BD0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_800D4BD4:
    // 0x800D4BD4: bgtz        $v0, L_800D4BE4
    if (SIGNED(ctx->r2) > 0) {
        // 0x800D4BD8: addiu       $t6, $a1, 0x7FF
        ctx->r14 = ADD32(ctx->r5, 0X7FF);
            goto L_800D4BE4;
    }
    // 0x800D4BD8: addiu       $t6, $a1, 0x7FF
    ctx->r14 = ADD32(ctx->r5, 0X7FF);
    // 0x800D4BDC: b           L_800D4BE8
    // 0x800D4BE0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800D4BE8;
    // 0x800D4BE0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800D4BE4:
    // 0x800D4BE4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_800D4BE8:
    // 0x800D4BE8: div         $zero, $t6, $a0
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r4)));
    // 0x800D4BEC: bne         $a0, $zero, L_800D4BF8
    if (ctx->r4 != 0) {
        // 0x800D4BF0: nop
    
            goto L_800D4BF8;
    }
    // 0x800D4BF0: nop

    // 0x800D4BF4: break       7
    do_break(2148355060);
L_800D4BF8:
    // 0x800D4BF8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800D4BFC: bne         $a0, $at, L_800D4C10
    if (ctx->r4 != ctx->r1) {
        // 0x800D4C00: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800D4C10;
    }
    // 0x800D4C00: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800D4C04: bne         $t6, $at, L_800D4C10
    if (ctx->r14 != ctx->r1) {
        // 0x800D4C08: nop
    
            goto L_800D4C10;
    }
    // 0x800D4C08: nop

    // 0x800D4C0C: break       6
    do_break(2148355084);
L_800D4C10:
    // 0x800D4C10: mflo        $t9
    ctx->r25 = lo;
    // 0x800D4C14: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x800D4C18: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800D4C1C: andi        $t6, $a2, 0xFFF
    ctx->r14 = ctx->r6 & 0XFFF;
    // 0x800D4C20: sll         $t9, $t6, 12
    ctx->r25 = S32(ctx->r14 << 12);
    // 0x800D4C24: or          $t7, $t8, $at
    ctx->r15 = ctx->r24 | ctx->r1;
    // 0x800D4C28: or          $t8, $t7, $t9
    ctx->r24 = ctx->r15 | ctx->r25;
    // 0x800D4C2C: sw          $t8, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r24;
    // 0x800D4C30: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800D4C34: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x800D4C38: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800D4C3C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800D4C40: lw          $t7, 0x1FC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1FC);
    // 0x800D4C44: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D4C48: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x800D4C4C: lbu         $t9, 0x30($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X30);
    // 0x800D4C50: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D4C54: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800D4C58: andi        $t8, $t9, 0x7
    ctx->r24 = ctx->r25 & 0X7;
    // 0x800D4C5C: sll         $t6, $t8, 21
    ctx->r14 = S32(ctx->r24 << 21);
    // 0x800D4C60: or          $t7, $t6, $t3
    ctx->r15 = ctx->r14 | ctx->r11;
    // 0x800D4C64: addiu       $t8, $s0, 0x7
    ctx->r24 = ADD32(ctx->r16, 0X7);
    // 0x800D4C68: sra         $t6, $t8, 3
    ctx->r14 = S32(SIGNED(ctx->r24) >> 3);
    // 0x800D4C6C: or          $t9, $t7, $a3
    ctx->r25 = ctx->r15 | ctx->r7;
    // 0x800D4C70: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x800D4C74: sll         $t8, $t7, 9
    ctx->r24 = S32(ctx->r15 << 9);
    // 0x800D4C78: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x800D4C7C: lui         $t7, 0x8
    ctx->r15 = S32(0X8 << 16);
    // 0x800D4C80: ori         $t7, $t7, 0x200
    ctx->r15 = ctx->r15 | 0X200;
    // 0x800D4C84: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800D4C88: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x800D4C8C: addiu       $t8, $s0, -0x1
    ctx->r24 = ADD32(ctx->r16, -0X1);
    // 0x800D4C90: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x800D4C94: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800D4C98: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x800D4C9C: lw          $t8, 0x1D4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1D4);
    // 0x800D4CA0: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x800D4CA4: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x800D4CA8: addiu       $t6, $t8, -0x1
    ctx->r14 = ADD32(ctx->r24, -0X1);
    // 0x800D4CAC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800D4CB0: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x800D4CB4: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x800D4CB8: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800D4CBC: b           L_800D4FE0
    // 0x800D4CC0: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
        goto L_800D4FE0;
    // 0x800D4CC0: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D4CC4: lhu         $t7, 0x14($a2)
    ctx->r15 = MEM_HU(ctx->r6, 0X14);
L_800D4CC8:
    // 0x800D4CC8: lui         $a3, 0x10
    ctx->r7 = S32(0X10 << 16);
    // 0x800D4CCC: lui         $t3, 0xF500
    ctx->r11 = S32(0XF500 << 16);
    // 0x800D4CD0: andi        $t9, $t7, 0x200
    ctx->r25 = ctx->r15 & 0X200;
    // 0x800D4CD4: beq         $t9, $zero, L_800D4E30
    if (ctx->r25 == 0) {
        // 0x800D4CD8: or          $v0, $t1, $zero
        ctx->r2 = ctx->r9 | 0;
            goto L_800D4E30;
    }
    // 0x800D4CD8: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800D4CDC: andi        $t8, $a0, 0x7
    ctx->r24 = ctx->r4 & 0X7;
    // 0x800D4CE0: sll         $t6, $t8, 21
    ctx->r14 = S32(ctx->r24 << 21);
    // 0x800D4CE4: lui         $at, 0xFD00
    ctx->r1 = S32(0XFD00 << 16);
    // 0x800D4CE8: lui         $a3, 0x10
    ctx->r7 = S32(0X10 << 16);
    // 0x800D4CEC: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x800D4CF0: or          $t9, $t7, $a3
    ctx->r25 = ctx->r15 | ctx->r7;
    // 0x800D4CF4: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800D4CF8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800D4CFC: lw          $t8, 0x200($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X200);
    // 0x800D4D00: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D4D04: lui         $t3, 0xF500
    ctx->r11 = S32(0XF500 << 16);
    // 0x800D4D08: lw          $t6, 0x8($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X8);
    // 0x800D4D0C: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x800D4D10: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D4D14: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800D4D18: lbu         $t7, 0x30($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X30);
    // 0x800D4D1C: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x800D4D20: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D4D24: andi        $t9, $t7, 0x7
    ctx->r25 = ctx->r15 & 0X7;
    // 0x800D4D28: sll         $t8, $t9, 21
    ctx->r24 = S32(ctx->r25 << 21);
    // 0x800D4D2C: or          $t6, $t8, $t3
    ctx->r14 = ctx->r24 | ctx->r11;
    // 0x800D4D30: lui         $t9, 0x708
    ctx->r25 = S32(0X708 << 16);
    // 0x800D4D34: ori         $t9, $t9, 0x200
    ctx->r25 = ctx->r25 | 0X200;
    // 0x800D4D38: or          $t7, $t6, $a3
    ctx->r15 = ctx->r14 | ctx->r7;
    // 0x800D4D3C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800D4D40: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x800D4D44: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x800D4D48: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x800D4D4C: lw          $t0, 0x1D4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1D4);
    // 0x800D4D50: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x800D4D54: lui         $t6, 0xF300
    ctx->r14 = S32(0XF300 << 16);
    // 0x800D4D58: multu       $s0, $t0
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D4D5C: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    // 0x800D4D60: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x800D4D64: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x800D4D68: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D4D6C: addiu       $a0, $zero, 0x7FF
    ctx->r4 = ADD32(0, 0X7FF);
    // 0x800D4D70: mflo        $v0
    ctx->r2 = lo;
    // 0x800D4D74: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800D4D78: slti        $at, $v0, 0x7FF
    ctx->r1 = SIGNED(ctx->r2) < 0X7FF ? 1 : 0;
    // 0x800D4D7C: beq         $at, $zero, L_800D4D8C
    if (ctx->r1 == 0) {
        // 0x800D4D80: nop
    
            goto L_800D4D8C;
    }
    // 0x800D4D80: nop

    // 0x800D4D84: b           L_800D4D8C
    // 0x800D4D88: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_800D4D8C;
    // 0x800D4D88: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_800D4D8C:
    // 0x800D4D8C: andi        $t7, $a0, 0xFFF
    ctx->r15 = ctx->r4 & 0XFFF;
    // 0x800D4D90: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x800D4D94: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800D4D98: or          $t8, $t9, $at
    ctx->r24 = ctx->r25 | ctx->r1;
    // 0x800D4D9C: sw          $t8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r24;
    // 0x800D4DA0: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800D4DA4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800D4DA8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800D4DAC: lw          $t7, 0x1FC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1FC);
    // 0x800D4DB0: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D4DB4: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x800D4DB8: lbu         $t9, 0x30($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X30);
    // 0x800D4DBC: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D4DC0: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x800D4DC4: andi        $t8, $t9, 0x7
    ctx->r24 = ctx->r25 & 0X7;
    // 0x800D4DC8: sll         $t6, $t8, 21
    ctx->r14 = S32(ctx->r24 << 21);
    // 0x800D4DCC: or          $t7, $t6, $t3
    ctx->r15 = ctx->r14 | ctx->r11;
    // 0x800D4DD0: sll         $t8, $s0, 1
    ctx->r24 = S32(ctx->r16 << 1);
    // 0x800D4DD4: addiu       $t6, $t8, 0x7
    ctx->r14 = ADD32(ctx->r24, 0X7);
    // 0x800D4DD8: or          $t9, $t7, $a3
    ctx->r25 = ctx->r15 | ctx->r7;
    // 0x800D4DDC: sra         $t7, $t6, 3
    ctx->r15 = S32(SIGNED(ctx->r14) >> 3);
    // 0x800D4DE0: andi        $t8, $t7, 0x1FF
    ctx->r24 = ctx->r15 & 0X1FF;
    // 0x800D4DE4: sll         $t6, $t8, 9
    ctx->r14 = S32(ctx->r24 << 9);
    // 0x800D4DE8: or          $t7, $t9, $t6
    ctx->r15 = ctx->r25 | ctx->r14;
    // 0x800D4DEC: lui         $t8, 0x8
    ctx->r24 = S32(0X8 << 16);
    // 0x800D4DF0: ori         $t8, $t8, 0x200
    ctx->r24 = ctx->r24 | 0X200;
    // 0x800D4DF4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800D4DF8: addiu       $t6, $s0, -0x1
    ctx->r14 = ADD32(ctx->r16, -0X1);
    // 0x800D4DFC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800D4E00: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800D4E04: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x800D4E08: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x800D4E0C: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x800D4E10: addiu       $t6, $t0, -0x1
    ctx->r14 = ADD32(ctx->r8, -0X1);
    // 0x800D4E14: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800D4E18: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x800D4E1C: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x800D4E20: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x800D4E24: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x800D4E28: b           L_800D4FE0
    // 0x800D4E2C: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
        goto L_800D4FE0;
    // 0x800D4E2C: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
L_800D4E30:
    // 0x800D4E30: andi        $t7, $a0, 0x7
    ctx->r15 = ctx->r4 & 0X7;
    // 0x800D4E34: sll         $t9, $t7, 21
    ctx->r25 = S32(ctx->r15 << 21);
    // 0x800D4E38: lui         $at, 0xFD00
    ctx->r1 = S32(0XFD00 << 16);
    // 0x800D4E3C: or          $t8, $t9, $at
    ctx->r24 = ctx->r25 | ctx->r1;
    // 0x800D4E40: or          $t6, $t8, $a3
    ctx->r14 = ctx->r24 | ctx->r7;
    // 0x800D4E44: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800D4E48: lw          $t7, 0x200($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X200);
    // 0x800D4E4C: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D4E50: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x800D4E54: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x800D4E58: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D4E5C: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x800D4E60: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800D4E64: lbu         $t8, 0x30($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X30);
    // 0x800D4E68: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D4E6C: or          $t2, $t1, $zero
    ctx->r10 = ctx->r9 | 0;
    // 0x800D4E70: andi        $t6, $t8, 0x7
    ctx->r14 = ctx->r24 & 0X7;
    // 0x800D4E74: sll         $t7, $t6, 21
    ctx->r15 = S32(ctx->r14 << 21);
    // 0x800D4E78: or          $t9, $t7, $t3
    ctx->r25 = ctx->r15 | ctx->r11;
    // 0x800D4E7C: lui         $t6, 0x708
    ctx->r14 = S32(0X708 << 16);
    // 0x800D4E80: ori         $t6, $t6, 0x200
    ctx->r14 = ctx->r14 | 0X200;
    // 0x800D4E84: or          $t8, $t9, $a3
    ctx->r24 = ctx->r25 | ctx->r7;
    // 0x800D4E88: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800D4E8C: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x800D4E90: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x800D4E94: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x800D4E98: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x800D4E9C: lui         $t9, 0xF300
    ctx->r25 = S32(0XF300 << 16);
    // 0x800D4EA0: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x800D4EA4: lw          $t8, 0x1D4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1D4);
    // 0x800D4EA8: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D4EAC: addiu       $a2, $zero, 0x7FF
    ctx->r6 = ADD32(0, 0X7FF);
    // 0x800D4EB0: multu       $s0, $t8
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D4EB4: sll         $t0, $s0, 1
    ctx->r8 = S32(ctx->r16 << 1);
    // 0x800D4EB8: mflo        $v0
    ctx->r2 = lo;
    // 0x800D4EBC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800D4EC0: slti        $at, $v0, 0x7FF
    ctx->r1 = SIGNED(ctx->r2) < 0X7FF ? 1 : 0;
    // 0x800D4EC4: beq         $at, $zero, L_800D4ED4
    if (ctx->r1 == 0) {
        // 0x800D4EC8: nop
    
            goto L_800D4ED4;
    }
    // 0x800D4EC8: nop

    // 0x800D4ECC: b           L_800D4ED4
    // 0x800D4ED0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
        goto L_800D4ED4;
    // 0x800D4ED0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_800D4ED4:
    // 0x800D4ED4: bgez        $t0, L_800D4EE4
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800D4ED8: sra         $v0, $t0, 3
        ctx->r2 = S32(SIGNED(ctx->r8) >> 3);
            goto L_800D4EE4;
    }
    // 0x800D4ED8: sra         $v0, $t0, 3
    ctx->r2 = S32(SIGNED(ctx->r8) >> 3);
    // 0x800D4EDC: addiu       $at, $t0, 0x7
    ctx->r1 = ADD32(ctx->r8, 0X7);
    // 0x800D4EE0: sra         $v0, $at, 3
    ctx->r2 = S32(SIGNED(ctx->r1) >> 3);
L_800D4EE4:
    // 0x800D4EE4: bgtz        $v0, L_800D4EF4
    if (SIGNED(ctx->r2) > 0) {
        // 0x800D4EE8: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_800D4EF4;
    }
    // 0x800D4EE8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800D4EEC: b           L_800D4EF4
    // 0x800D4EF0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_800D4EF4;
    // 0x800D4EF0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_800D4EF4:
    // 0x800D4EF4: bgtz        $v0, L_800D4F04
    if (SIGNED(ctx->r2) > 0) {
        // 0x800D4EF8: addiu       $t6, $a1, 0x7FF
        ctx->r14 = ADD32(ctx->r5, 0X7FF);
            goto L_800D4F04;
    }
    // 0x800D4EF8: addiu       $t6, $a1, 0x7FF
    ctx->r14 = ADD32(ctx->r5, 0X7FF);
    // 0x800D4EFC: b           L_800D4F08
    // 0x800D4F00: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800D4F08;
    // 0x800D4F00: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800D4F04:
    // 0x800D4F04: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_800D4F08:
    // 0x800D4F08: div         $zero, $t6, $a0
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r4)));
    // 0x800D4F0C: bne         $a0, $zero, L_800D4F18
    if (ctx->r4 != 0) {
        // 0x800D4F10: nop
    
            goto L_800D4F18;
    }
    // 0x800D4F10: nop

    // 0x800D4F14: break       7
    do_break(2148355860);
L_800D4F18:
    // 0x800D4F18: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800D4F1C: bne         $a0, $at, L_800D4F30
    if (ctx->r4 != ctx->r1) {
        // 0x800D4F20: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800D4F30;
    }
    // 0x800D4F20: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800D4F24: bne         $t6, $at, L_800D4F30
    if (ctx->r14 != ctx->r1) {
        // 0x800D4F28: nop
    
            goto L_800D4F30;
    }
    // 0x800D4F28: nop

    // 0x800D4F2C: break       6
    do_break(2148355884);
L_800D4F30:
    // 0x800D4F30: mflo        $t7
    ctx->r15 = lo;
    // 0x800D4F34: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x800D4F38: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800D4F3C: andi        $t6, $a2, 0xFFF
    ctx->r14 = ctx->r6 & 0XFFF;
    // 0x800D4F40: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x800D4F44: or          $t8, $t9, $at
    ctx->r24 = ctx->r25 | ctx->r1;
    // 0x800D4F48: or          $t9, $t8, $t7
    ctx->r25 = ctx->r24 | ctx->r15;
    // 0x800D4F4C: sw          $t9, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r25;
    // 0x800D4F50: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800D4F54: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x800D4F58: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800D4F5C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800D4F60: lw          $t8, 0x1FC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1FC);
    // 0x800D4F64: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D4F68: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x800D4F6C: lbu         $t7, 0x30($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0X30);
    // 0x800D4F70: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D4F74: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800D4F78: andi        $t9, $t7, 0x7
    ctx->r25 = ctx->r15 & 0X7;
    // 0x800D4F7C: sll         $t6, $t9, 21
    ctx->r14 = S32(ctx->r25 << 21);
    // 0x800D4F80: or          $t8, $t6, $t3
    ctx->r24 = ctx->r14 | ctx->r11;
    // 0x800D4F84: addiu       $t9, $t0, 0x7
    ctx->r25 = ADD32(ctx->r8, 0X7);
    // 0x800D4F88: sra         $t6, $t9, 3
    ctx->r14 = S32(SIGNED(ctx->r25) >> 3);
    // 0x800D4F8C: or          $t7, $t8, $a3
    ctx->r15 = ctx->r24 | ctx->r7;
    // 0x800D4F90: andi        $t8, $t6, 0x1FF
    ctx->r24 = ctx->r14 & 0X1FF;
    // 0x800D4F94: sll         $t9, $t8, 9
    ctx->r25 = S32(ctx->r24 << 9);
    // 0x800D4F98: or          $t6, $t7, $t9
    ctx->r14 = ctx->r15 | ctx->r25;
    // 0x800D4F9C: lui         $t8, 0x8
    ctx->r24 = S32(0X8 << 16);
    // 0x800D4FA0: ori         $t8, $t8, 0x200
    ctx->r24 = ctx->r24 | 0X200;
    // 0x800D4FA4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800D4FA8: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800D4FAC: addiu       $t9, $s0, -0x1
    ctx->r25 = ADD32(ctx->r16, -0X1);
    // 0x800D4FB0: lui         $t7, 0xF200
    ctx->r15 = S32(0XF200 << 16);
    // 0x800D4FB4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800D4FB8: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x800D4FBC: lw          $t9, 0x1D4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1D4);
    // 0x800D4FC0: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x800D4FC4: sll         $t7, $t8, 12
    ctx->r15 = S32(ctx->r24 << 12);
    // 0x800D4FC8: addiu       $t6, $t9, -0x1
    ctx->r14 = ADD32(ctx->r25, -0X1);
    // 0x800D4FCC: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x800D4FD0: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x800D4FD4: or          $t6, $t7, $t9
    ctx->r14 = ctx->r15 | ctx->r25;
    // 0x800D4FD8: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800D4FDC: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
L_800D4FE0:
    // 0x800D4FE0: lw          $t8, 0x200($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X200);
    // 0x800D4FE4: b           L_800D5320
    // 0x800D4FE8: lw          $v0, 0x8($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X8);
        goto L_800D5320;
    // 0x800D4FE8: lw          $v0, 0x8($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X8);
L_800D4FEC:
    // 0x800D4FEC: lhu         $t7, 0x14($a2)
    ctx->r15 = MEM_HU(ctx->r6, 0X14);
    // 0x800D4FF0: lui         $a3, 0x18
    ctx->r7 = S32(0X18 << 16);
    // 0x800D4FF4: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800D4FF8: andi        $t9, $t7, 0x200
    ctx->r25 = ctx->r15 & 0X200;
    // 0x800D4FFC: beql        $t9, $zero, L_800D515C
    if (ctx->r25 == 0) {
        // 0x800D5000: lbu         $t9, 0x30($a2)
        ctx->r25 = MEM_BU(ctx->r6, 0X30);
            goto L_800D515C;
    }
    goto skip_9;
    // 0x800D5000: lbu         $t9, 0x30($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X30);
    skip_9:
    // 0x800D5004: lbu         $t6, 0x30($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X30);
    // 0x800D5008: lui         $at, 0xFD00
    ctx->r1 = S32(0XFD00 << 16);
    // 0x800D500C: lui         $a3, 0x18
    ctx->r7 = S32(0X18 << 16);
    // 0x800D5010: andi        $t8, $t6, 0x7
    ctx->r24 = ctx->r14 & 0X7;
    // 0x800D5014: sll         $t7, $t8, 21
    ctx->r15 = S32(ctx->r24 << 21);
    // 0x800D5018: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x800D501C: or          $t6, $t9, $a3
    ctx->r14 = ctx->r25 | ctx->r7;
    // 0x800D5020: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800D5024: lw          $t8, 0x200($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X200);
    // 0x800D5028: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D502C: lui         $t3, 0xF500
    ctx->r11 = S32(0XF500 << 16);
    // 0x800D5030: lw          $t7, 0x8($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X8);
    // 0x800D5034: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x800D5038: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D503C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800D5040: lbu         $t9, 0x30($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X30);
    // 0x800D5044: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x800D5048: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D504C: andi        $t6, $t9, 0x7
    ctx->r14 = ctx->r25 & 0X7;
    // 0x800D5050: sll         $t8, $t6, 21
    ctx->r24 = S32(ctx->r14 << 21);
    // 0x800D5054: or          $t7, $t8, $t3
    ctx->r15 = ctx->r24 | ctx->r11;
    // 0x800D5058: lui         $t6, 0x708
    ctx->r14 = S32(0X708 << 16);
    // 0x800D505C: ori         $t6, $t6, 0x200
    ctx->r14 = ctx->r14 | 0X200;
    // 0x800D5060: or          $t9, $t7, $a3
    ctx->r25 = ctx->r15 | ctx->r7;
    // 0x800D5064: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800D5068: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x800D506C: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x800D5070: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800D5074: lw          $t0, 0x1D4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1D4);
    // 0x800D5078: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x800D507C: lui         $t7, 0xF300
    ctx->r15 = S32(0XF300 << 16);
    // 0x800D5080: multu       $s0, $t0
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D5084: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x800D5088: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x800D508C: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x800D5090: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D5094: addiu       $a0, $zero, 0x7FF
    ctx->r4 = ADD32(0, 0X7FF);
    // 0x800D5098: mflo        $v0
    ctx->r2 = lo;
    // 0x800D509C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800D50A0: slti        $at, $v0, 0x7FF
    ctx->r1 = SIGNED(ctx->r2) < 0X7FF ? 1 : 0;
    // 0x800D50A4: beq         $at, $zero, L_800D50B4
    if (ctx->r1 == 0) {
        // 0x800D50A8: nop
    
            goto L_800D50B4;
    }
    // 0x800D50A8: nop

    // 0x800D50AC: b           L_800D50B4
    // 0x800D50B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_800D50B4;
    // 0x800D50B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_800D50B4:
    // 0x800D50B4: andi        $t9, $a0, 0xFFF
    ctx->r25 = ctx->r4 & 0XFFF;
    // 0x800D50B8: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x800D50BC: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800D50C0: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x800D50C4: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    // 0x800D50C8: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800D50CC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800D50D0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800D50D4: lw          $t9, 0x1FC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1FC);
    // 0x800D50D8: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D50DC: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x800D50E0: lbu         $t6, 0x30($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0X30);
    // 0x800D50E4: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D50E8: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    // 0x800D50EC: andi        $t8, $t6, 0x7
    ctx->r24 = ctx->r14 & 0X7;
    // 0x800D50F0: sll         $t7, $t8, 21
    ctx->r15 = S32(ctx->r24 << 21);
    // 0x800D50F4: or          $t9, $t7, $t3
    ctx->r25 = ctx->r15 | ctx->r11;
    // 0x800D50F8: sll         $t8, $s0, 1
    ctx->r24 = S32(ctx->r16 << 1);
    // 0x800D50FC: addiu       $t7, $t8, 0x7
    ctx->r15 = ADD32(ctx->r24, 0X7);
    // 0x800D5100: or          $t6, $t9, $a3
    ctx->r14 = ctx->r25 | ctx->r7;
    // 0x800D5104: sra         $t9, $t7, 3
    ctx->r25 = S32(SIGNED(ctx->r15) >> 3);
    // 0x800D5108: andi        $t8, $t9, 0x1FF
    ctx->r24 = ctx->r25 & 0X1FF;
    // 0x800D510C: sll         $t7, $t8, 9
    ctx->r15 = S32(ctx->r24 << 9);
    // 0x800D5110: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x800D5114: lui         $t8, 0x8
    ctx->r24 = S32(0X8 << 16);
    // 0x800D5118: ori         $t8, $t8, 0x200
    ctx->r24 = ctx->r24 | 0X200;
    // 0x800D511C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800D5120: addiu       $t7, $s0, -0x1
    ctx->r15 = ADD32(ctx->r16, -0X1);
    // 0x800D5124: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x800D5128: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800D512C: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x800D5130: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x800D5134: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x800D5138: addiu       $t7, $t0, -0x1
    ctx->r15 = ADD32(ctx->r8, -0X1);
    // 0x800D513C: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x800D5140: sll         $t6, $t8, 12
    ctx->r14 = S32(ctx->r24 << 12);
    // 0x800D5144: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x800D5148: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x800D514C: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
    // 0x800D5150: b           L_800D5318
    // 0x800D5154: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
        goto L_800D5318;
    // 0x800D5154: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D5158: lbu         $t9, 0x30($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X30);
L_800D515C:
    // 0x800D515C: lui         $at, 0xFD00
    ctx->r1 = S32(0XFD00 << 16);
    // 0x800D5160: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800D5164: andi        $t6, $t9, 0x7
    ctx->r14 = ctx->r25 & 0X7;
    // 0x800D5168: sll         $t8, $t6, 21
    ctx->r24 = S32(ctx->r14 << 21);
    // 0x800D516C: or          $t7, $t8, $at
    ctx->r15 = ctx->r24 | ctx->r1;
    // 0x800D5170: or          $t9, $t7, $a3
    ctx->r25 = ctx->r15 | ctx->r7;
    // 0x800D5174: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800D5178: lw          $t6, 0x200($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X200);
    // 0x800D517C: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D5180: lui         $t3, 0xF500
    ctx->r11 = S32(0XF500 << 16);
    // 0x800D5184: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x800D5188: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x800D518C: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D5190: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800D5194: lbu         $t7, 0x30($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X30);
    // 0x800D5198: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x800D519C: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D51A0: andi        $t9, $t7, 0x7
    ctx->r25 = ctx->r15 & 0X7;
    // 0x800D51A4: sll         $t6, $t9, 21
    ctx->r14 = S32(ctx->r25 << 21);
    // 0x800D51A8: or          $t8, $t6, $t3
    ctx->r24 = ctx->r14 | ctx->r11;
    // 0x800D51AC: lui         $t9, 0x708
    ctx->r25 = S32(0X708 << 16);
    // 0x800D51B0: ori         $t9, $t9, 0x200
    ctx->r25 = ctx->r25 | 0X200;
    // 0x800D51B4: or          $t7, $t8, $a3
    ctx->r15 = ctx->r24 | ctx->r7;
    // 0x800D51B8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800D51BC: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x800D51C0: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x800D51C4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800D51C8: lw          $t2, 0x1D4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1D4);
    // 0x800D51CC: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x800D51D0: lui         $t8, 0xF300
    ctx->r24 = S32(0XF300 << 16);
    // 0x800D51D4: multu       $s0, $t2
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D51D8: or          $t0, $t1, $zero
    ctx->r8 = ctx->r9 | 0;
    // 0x800D51DC: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x800D51E0: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D51E4: addiu       $a2, $zero, 0x7FF
    ctx->r6 = ADD32(0, 0X7FF);
    // 0x800D51E8: mflo        $v0
    ctx->r2 = lo;
    // 0x800D51EC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800D51F0: slti        $at, $v0, 0x7FF
    ctx->r1 = SIGNED(ctx->r2) < 0X7FF ? 1 : 0;
    // 0x800D51F4: beq         $at, $zero, L_800D5204
    if (ctx->r1 == 0) {
        // 0x800D51F8: nop
    
            goto L_800D5204;
    }
    // 0x800D51F8: nop

    // 0x800D51FC: b           L_800D5204
    // 0x800D5200: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
        goto L_800D5204;
    // 0x800D5200: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_800D5204:
    // 0x800D5204: sll         $v0, $s0, 2
    ctx->r2 = S32(ctx->r16 << 2);
    // 0x800D5208: bgez        $v0, L_800D5218
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800D520C: sra         $t7, $v0, 3
        ctx->r15 = S32(SIGNED(ctx->r2) >> 3);
            goto L_800D5218;
    }
    // 0x800D520C: sra         $t7, $v0, 3
    ctx->r15 = S32(SIGNED(ctx->r2) >> 3);
    // 0x800D5210: addiu       $at, $v0, 0x7
    ctx->r1 = ADD32(ctx->r2, 0X7);
    // 0x800D5214: sra         $t7, $at, 3
    ctx->r15 = S32(SIGNED(ctx->r1) >> 3);
L_800D5218:
    // 0x800D5218: bgtz        $t7, L_800D5228
    if (SIGNED(ctx->r15) > 0) {
        // 0x800D521C: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_800D5228;
    }
    // 0x800D521C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800D5220: b           L_800D522C
    // 0x800D5224: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_800D522C;
    // 0x800D5224: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_800D5228:
    // 0x800D5228: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_800D522C:
    // 0x800D522C: bgtz        $v0, L_800D523C
    if (SIGNED(ctx->r2) > 0) {
        // 0x800D5230: addiu       $t9, $a1, 0x7FF
        ctx->r25 = ADD32(ctx->r5, 0X7FF);
            goto L_800D523C;
    }
    // 0x800D5230: addiu       $t9, $a1, 0x7FF
    ctx->r25 = ADD32(ctx->r5, 0X7FF);
    // 0x800D5234: b           L_800D5240
    // 0x800D5238: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800D5240;
    // 0x800D5238: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800D523C:
    // 0x800D523C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_800D5240:
    // 0x800D5240: div         $zero, $t9, $a0
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r4)));
    // 0x800D5244: bne         $a0, $zero, L_800D5250
    if (ctx->r4 != 0) {
        // 0x800D5248: nop
    
            goto L_800D5250;
    }
    // 0x800D5248: nop

    // 0x800D524C: break       7
    do_break(2148356684);
L_800D5250:
    // 0x800D5250: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800D5254: bne         $a0, $at, L_800D5268
    if (ctx->r4 != ctx->r1) {
        // 0x800D5258: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800D5268;
    }
    // 0x800D5258: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800D525C: bne         $t9, $at, L_800D5268
    if (ctx->r25 != ctx->r1) {
        // 0x800D5260: nop
    
            goto L_800D5268;
    }
    // 0x800D5260: nop

    // 0x800D5264: break       6
    do_break(2148356708);
L_800D5268:
    // 0x800D5268: mflo        $t6
    ctx->r14 = lo;
    // 0x800D526C: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x800D5270: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800D5274: andi        $t9, $a2, 0xFFF
    ctx->r25 = ctx->r6 & 0XFFF;
    // 0x800D5278: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x800D527C: or          $t7, $t8, $at
    ctx->r15 = ctx->r24 | ctx->r1;
    // 0x800D5280: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x800D5284: sw          $t8, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r24;
    // 0x800D5288: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800D528C: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x800D5290: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800D5294: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800D5298: lw          $t7, 0x1FC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1FC);
    // 0x800D529C: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D52A0: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x800D52A4: lbu         $t6, 0x30($t7)
    ctx->r14 = MEM_BU(ctx->r15, 0X30);
    // 0x800D52A8: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D52AC: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800D52B0: andi        $t8, $t6, 0x7
    ctx->r24 = ctx->r14 & 0X7;
    // 0x800D52B4: sll         $t9, $t8, 21
    ctx->r25 = S32(ctx->r24 << 21);
    // 0x800D52B8: or          $t7, $t9, $t3
    ctx->r15 = ctx->r25 | ctx->r11;
    // 0x800D52BC: sll         $t8, $s0, 1
    ctx->r24 = S32(ctx->r16 << 1);
    // 0x800D52C0: addiu       $t9, $t8, 0x7
    ctx->r25 = ADD32(ctx->r24, 0X7);
    // 0x800D52C4: or          $t6, $t7, $a3
    ctx->r14 = ctx->r15 | ctx->r7;
    // 0x800D52C8: sra         $t7, $t9, 3
    ctx->r15 = S32(SIGNED(ctx->r25) >> 3);
    // 0x800D52CC: andi        $t8, $t7, 0x1FF
    ctx->r24 = ctx->r15 & 0X1FF;
    // 0x800D52D0: sll         $t9, $t8, 9
    ctx->r25 = S32(ctx->r24 << 9);
    // 0x800D52D4: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x800D52D8: lui         $t8, 0x8
    ctx->r24 = S32(0X8 << 16);
    // 0x800D52DC: ori         $t8, $t8, 0x200
    ctx->r24 = ctx->r24 | 0X200;
    // 0x800D52E0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800D52E4: addiu       $t9, $s0, -0x1
    ctx->r25 = ADD32(ctx->r16, -0X1);
    // 0x800D52E8: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x800D52EC: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800D52F0: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x800D52F4: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x800D52F8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800D52FC: addiu       $t9, $t2, -0x1
    ctx->r25 = ADD32(ctx->r10, -0X1);
    // 0x800D5300: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x800D5304: sll         $t6, $t8, 12
    ctx->r14 = S32(ctx->r24 << 12);
    // 0x800D5308: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x800D530C: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x800D5310: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800D5314: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
L_800D5318:
    // 0x800D5318: lw          $t7, 0x200($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X200);
    // 0x800D531C: lw          $v0, 0x8($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X8);
L_800D5320:
    // 0x800D5320: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D5324: sw          $v0, -0x3250($at)
    MEM_W(-0X3250, ctx->r1) = ctx->r2;
    // 0x800D5328: addiu       $v0, $sp, 0x1C4
    ctx->r2 = ADD32(ctx->r29, 0X1C4);
L_800D532C:
    // 0x800D532C: lbu         $t8, 0x4($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X4);
    // 0x800D5330: addiu       $t6, $zero, 0xE4
    ctx->r14 = ADD32(0, 0XE4);
    // 0x800D5334: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
    // 0x800D5338: andi        $t9, $t8, 0xFFF8
    ctx->r25 = ctx->r24 & 0XFFF8;
    // 0x800D533C: sb          $t9, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r25;
    // 0x800D5340: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x800D5344: lw          $t6, 0x1EC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1EC);
    // 0x800D5348: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x800D534C: srl         $t8, $v1, 12
    ctx->r24 = S32(U32(ctx->r3) >> 12);
    // 0x800D5350: xor         $t9, $t6, $t8
    ctx->r25 = ctx->r14 ^ ctx->r24;
    // 0x800D5354: sll         $t7, $t9, 20
    ctx->r15 = S32(ctx->r25 << 20);
    // 0x800D5358: srl         $t6, $t7, 8
    ctx->r14 = S32(U32(ctx->r15) >> 8);
    // 0x800D535C: xor         $t8, $t6, $v1
    ctx->r24 = ctx->r14 ^ ctx->r3;
    // 0x800D5360: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800D5364: lw          $t7, 0x1E4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1E4);
    // 0x800D5368: srl         $t6, $a0, 12
    ctx->r14 = S32(U32(ctx->r4) >> 12);
    // 0x800D536C: addiu       $a1, $t1, 0x8
    ctx->r5 = ADD32(ctx->r9, 0X8);
    // 0x800D5370: xor         $t8, $t7, $t6
    ctx->r24 = ctx->r15 ^ ctx->r14;
    // 0x800D5374: sll         $t9, $t8, 20
    ctx->r25 = S32(ctx->r24 << 20);
    // 0x800D5378: srl         $t7, $t9, 8
    ctx->r15 = S32(U32(ctx->r25) >> 8);
    // 0x800D537C: xor         $t6, $t7, $a0
    ctx->r14 = ctx->r15 ^ ctx->r4;
    // 0x800D5380: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800D5384: lw          $t9, 0x1E8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1E8);
    // 0x800D5388: lhu         $t6, 0x6($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X6);
    // 0x800D538C: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x800D5390: andi        $t7, $t9, 0xFFF
    ctx->r15 = ctx->r25 & 0XFFF;
    // 0x800D5394: andi        $t8, $t6, 0xF000
    ctx->r24 = ctx->r14 & 0XF000;
    // 0x800D5398: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x800D539C: sh          $t9, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r25;
    // 0x800D53A0: lw          $t7, 0x1E0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1E0);
    // 0x800D53A4: lhu         $t9, 0x2($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X2);
    // 0x800D53A8: addiu       $a2, $a1, 0x8
    ctx->r6 = ADD32(ctx->r5, 0X8);
    // 0x800D53AC: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x800D53B0: andi        $t6, $t9, 0xF000
    ctx->r14 = ctx->r25 & 0XF000;
    // 0x800D53B4: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x800D53B8: sh          $t7, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r15;
    // 0x800D53BC: lw          $t9, 0x1F4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1F4);
    // 0x800D53C0: lw          $t8, 0x1F0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1F0);
    // 0x800D53C4: lw          $v1, 0x1FC($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1FC);
    // 0x800D53C8: sh          $t9, 0x1CC($sp)
    MEM_H(0X1CC, ctx->r29) = ctx->r25;
    // 0x800D53CC: sh          $t8, 0x1CE($sp)
    MEM_H(0X1CE, ctx->r29) = ctx->r24;
    // 0x800D53D0: lhu         $t6, 0x14($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X14);
    // 0x800D53D4: andi        $t7, $t6, 0x20
    ctx->r15 = ctx->r14 & 0X20;
    // 0x800D53D8: beql        $t7, $zero, L_800D5400
    if (ctx->r15 == 0) {
        // 0x800D53DC: lw          $t7, 0x21C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X21C);
            goto L_800D5400;
    }
    goto skip_10;
    // 0x800D53DC: lw          $t7, 0x21C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X21C);
    skip_10:
    // 0x800D53E0: lbu         $t9, 0x30($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X30);
    // 0x800D53E4: lw          $t8, 0x21C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X21C);
    // 0x800D53E8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800D53EC: beq         $t9, $at, L_800D53FC
    if (ctx->r25 == ctx->r1) {
        // 0x800D53F0: sll         $t6, $t8, 2
        ctx->r14 = S32(ctx->r24 << 2);
            goto L_800D53FC;
    }
    // 0x800D53F0: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x800D53F4: b           L_800D5404
    // 0x800D53F8: sh          $t6, 0x1D0($sp)
    MEM_H(0X1D0, ctx->r29) = ctx->r14;
        goto L_800D5404;
    // 0x800D53F8: sh          $t6, 0x1D0($sp)
    MEM_H(0X1D0, ctx->r29) = ctx->r14;
L_800D53FC:
    // 0x800D53FC: lw          $t7, 0x21C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X21C);
L_800D5400:
    // 0x800D5400: sh          $t7, 0x1D0($sp)
    MEM_H(0X1D0, ctx->r29) = ctx->r15;
L_800D5404:
    // 0x800D5404: lw          $t8, 0x1C4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C4);
    // 0x800D5408: lw          $t9, 0x220($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X220);
    // 0x800D540C: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x800D5410: sll         $t6, $t8, 8
    ctx->r14 = S32(ctx->r24 << 8);
    // 0x800D5414: srl         $t7, $t6, 20
    ctx->r15 = S32(U32(ctx->r14) >> 20);
    // 0x800D5418: sh          $t9, 0x1D2($sp)
    MEM_H(0X1D2, ctx->r29) = ctx->r25;
    // 0x800D541C: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x800D5420: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x800D5424: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x800D5428: or          $t9, $t8, $zero
    ctx->r25 = ctx->r24 | 0;
    // 0x800D542C: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x800D5430: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x800D5434: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800D5438: lbu         $t7, 0x1C8($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X1C8);
    // 0x800D543C: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x800D5440: addiu       $v0, $a2, 0x8
    ctx->r2 = ADD32(ctx->r6, 0X8);
    // 0x800D5444: andi        $t6, $t7, 0x7
    ctx->r14 = ctx->r15 & 0X7;
    // 0x800D5448: sll         $t9, $v1, 8
    ctx->r25 = S32(ctx->r3 << 8);
    // 0x800D544C: srl         $t7, $t9, 20
    ctx->r15 = S32(U32(ctx->r25) >> 20);
    // 0x800D5450: sll         $t8, $t6, 24
    ctx->r24 = S32(ctx->r14 << 24);
    // 0x800D5454: andi        $t6, $t7, 0xFFF
    ctx->r14 = ctx->r15 & 0XFFF;
    // 0x800D5458: sll         $t9, $t6, 12
    ctx->r25 = S32(ctx->r14 << 12);
    // 0x800D545C: or          $t7, $t8, $t9
    ctx->r15 = ctx->r24 | ctx->r25;
    // 0x800D5460: andi        $t8, $v1, 0xFFF
    ctx->r24 = ctx->r3 & 0XFFF;
    // 0x800D5464: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x800D5468: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x800D546C: lui         $t6, 0xE100
    ctx->r14 = S32(0XE100 << 16);
    // 0x800D5470: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x800D5474: lhu         $t8, 0x1CC($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X1CC);
    // 0x800D5478: lhu         $t7, 0x1CE($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X1CE);
    // 0x800D547C: lui         $t6, 0xF100
    ctx->r14 = S32(0XF100 << 16);
    // 0x800D5480: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800D5484: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x800D5488: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    // 0x800D548C: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x800D5490: lhu         $t7, 0x1D0($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X1D0);
    // 0x800D5494: lhu         $t9, 0x1D2($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X1D2);
    // 0x800D5498: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x800D549C: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x800D54A0: or          $t7, $t8, $t9
    ctx->r15 = ctx->r24 | ctx->r25;
    // 0x800D54A4: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
    // 0x800D54A8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800D54AC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800D54B0: lw          $t8, 0x1F8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1F8);
    // 0x800D54B4: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x800D54B8: sw          $t1, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r9;
L_800D54BC:
    // 0x800D54BC: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
L_800D54C0:
    // 0x800D54C0: jr          $ra
    // 0x800D54C4: addiu       $sp, $sp, 0x1F8
    ctx->r29 = ADD32(ctx->r29, 0X1F8);
    return;
    // 0x800D54C4: addiu       $sp, $sp, 0x1F8
    ctx->r29 = ADD32(ctx->r29, 0X1F8);
;}
RECOMP_FUNC void spX2Init_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D54C8: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x800D54CC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D54D0: sh          $zero, -0x324C($at)
    MEM_H(-0X324C, ctx->r1) = 0;
    // 0x800D54D4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800D54D8: sw          $zero, -0x7F68($at)
    MEM_W(-0X7F68, ctx->r1) = 0;
    // 0x800D54DC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800D54E0: sw          $zero, -0x7F64($at)
    MEM_W(-0X7F64, ctx->r1) = 0;
    // 0x800D54E4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800D54E8: addiu       $t6, $zero, 0x140
    ctx->r14 = ADD32(0, 0X140);
    // 0x800D54EC: sw          $t6, -0x7F70($at)
    MEM_W(-0X7F70, ctx->r1) = ctx->r14;
    // 0x800D54F0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800D54F4: addiu       $t7, $zero, 0xF0
    ctx->r15 = ADD32(0, 0XF0);
    // 0x800D54F8: sw          $t7, -0x7F6C($at)
    MEM_W(-0X7F6C, ctx->r1) = ctx->r15;
    // 0x800D54FC: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x800D5500: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x800D5504: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x800D5508: addiu       $a2, $a1, 0x8
    ctx->r6 = ADD32(ctx->r5, 0X8);
    // 0x800D550C: lui         $t9, 0xE300
    ctx->r25 = S32(0XE300 << 16);
    // 0x800D5510: ori         $t9, $t9, 0xA01
    ctx->r25 = ctx->r25 | 0XA01;
    // 0x800D5514: addiu       $a3, $a2, 0x8
    ctx->r7 = ADD32(ctx->r6, 0X8);
    // 0x800D5518: lui         $t2, 0xD700
    ctx->r10 = S32(0XD700 << 16);
    // 0x800D551C: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800D5520: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x800D5524: ori         $t2, $t2, 0x2
    ctx->r10 = ctx->r10 | 0X2;
    // 0x800D5528: lui         $t3, 0x8000
    ctx->r11 = S32(0X8000 << 16);
    // 0x800D552C: ori         $t3, $t3, 0x8000
    ctx->r11 = ctx->r11 | 0X8000;
    // 0x800D5530: sw          $t2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r10;
    // 0x800D5534: addiu       $t0, $a3, 0x8
    ctx->r8 = ADD32(ctx->r7, 0X8);
    // 0x800D5538: sw          $t3, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r11;
    // 0x800D553C: lui         $t4, 0xE200
    ctx->r12 = S32(0XE200 << 16);
    // 0x800D5540: ori         $t4, $t4, 0x1E01
    ctx->r12 = ctx->r12 | 0X1E01;
    // 0x800D5544: addiu       $v0, $t0, 0x8
    ctx->r2 = ADD32(ctx->r8, 0X8);
    // 0x800D5548: lui         $t5, 0xE300
    ctx->r13 = S32(0XE300 << 16);
    // 0x800D554C: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x800D5550: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x800D5554: ori         $t5, $t5, 0xC00
    ctx->r13 = ctx->r13 | 0XC00;
    // 0x800D5558: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800D555C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800D5560: addiu       $a1, $v0, 0x8
    ctx->r5 = ADD32(ctx->r2, 0X8);
    // 0x800D5564: lui         $t6, 0xE300
    ctx->r14 = S32(0XE300 << 16);
    // 0x800D5568: ori         $t6, $t6, 0x1201
    ctx->r14 = ctx->r14 | 0X1201;
    // 0x800D556C: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x800D5570: addiu       $a2, $a1, 0x8
    ctx->r6 = ADD32(ctx->r5, 0X8);
    // 0x800D5574: addiu       $t7, $zero, 0x2000
    ctx->r15 = ADD32(0, 0X2000);
    // 0x800D5578: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x800D557C: lui         $t8, 0xE300
    ctx->r24 = S32(0XE300 << 16);
    // 0x800D5580: ori         $t8, $t8, 0x1402
    ctx->r24 = ctx->r24 | 0X1402;
    // 0x800D5584: addiu       $a3, $a2, 0x8
    ctx->r7 = ADD32(ctx->r6, 0X8);
    // 0x800D5588: addiu       $t9, $zero, 0xC00
    ctx->r25 = ADD32(0, 0XC00);
    // 0x800D558C: sw          $t9, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r25;
    // 0x800D5590: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x800D5594: lui         $t2, 0xE300
    ctx->r10 = S32(0XE300 << 16);
    // 0x800D5598: ori         $t2, $t2, 0xD01
    ctx->r10 = ctx->r10 | 0XD01;
    // 0x800D559C: addiu       $t0, $a3, 0x8
    ctx->r8 = ADD32(ctx->r7, 0X8);
    // 0x800D55A0: sw          $t2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r10;
    // 0x800D55A4: sw          $zero, 0x4($a3)
    MEM_W(0X4, ctx->r7) = 0;
    // 0x800D55A8: lui         $t3, 0xE300
    ctx->r11 = S32(0XE300 << 16);
    // 0x800D55AC: ori         $t3, $t3, 0xF00
    ctx->r11 = ctx->r11 | 0XF00;
    // 0x800D55B0: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x800D55B4: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x800D55B8: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x800D55BC: lui         $t4, 0xE300
    ctx->r12 = S32(0XE300 << 16);
    // 0x800D55C0: ori         $t4, $t4, 0x1001
    ctx->r12 = ctx->r12 | 0X1001;
    // 0x800D55C4: addiu       $v1, $t1, 0x8
    ctx->r3 = ADD32(ctx->r9, 0X8);
    // 0x800D55C8: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x800D55CC: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x800D55D0: lui         $t6, 0xF0A
    ctx->r14 = S32(0XF0A << 16);
    // 0x800D55D4: lui         $t5, 0xE200
    ctx->r13 = S32(0XE200 << 16);
    // 0x800D55D8: ori         $t5, $t5, 0x1C
    ctx->r13 = ctx->r13 | 0X1C;
    // 0x800D55DC: ori         $t6, $t6, 0x7008
    ctx->r14 = ctx->r14 | 0X7008;
    // 0x800D55E0: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x800D55E4: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x800D55E8: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x800D55EC: jr          $ra
    // 0x800D55F0: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    return;
    // 0x800D55F0: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void spX2Draw_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D55F4: addiu       $sp, $sp, -0x1A8
    ctx->r29 = ADD32(ctx->r29, -0X1A8);
    // 0x800D55F8: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x800D55FC: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x800D5600: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x800D5604: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x800D5608: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x800D560C: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x800D5610: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x800D5614: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x800D5618: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x800D561C: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x800D5620: lhu         $t6, 0x14($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X14);
    // 0x800D5624: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800D5628: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D562C: andi        $t7, $t6, 0x4
    ctx->r15 = ctx->r14 & 0X4;
    // 0x800D5630: beq         $t7, $zero, L_800D5640
    if (ctx->r15 == 0) {
        // 0x800D5634: lui         $a1, 0x800F
        ctx->r5 = S32(0X800F << 16);
            goto L_800D5640;
    }
    // 0x800D5634: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x800D5638: b           L_800D62F0
    // 0x800D563C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800D62F0;
    // 0x800D563C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800D5640:
    // 0x800D5640: sw          $zero, -0x3250($at)
    MEM_W(-0X3250, ctx->r1) = 0;
    // 0x800D5644: lw          $t8, 0x3C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X3C);
    // 0x800D5648: addiu       $a1, $a1, -0x324C
    ctx->r5 = ADD32(ctx->r5, -0X324C);
    // 0x800D564C: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x800D5650: bne         $t8, $zero, L_800D5660
    if (ctx->r24 != 0) {
        // 0x800D5654: sw          $t8, 0x18C($sp)
        MEM_W(0X18C, ctx->r29) = ctx->r24;
            goto L_800D5660;
    }
    // 0x800D5654: sw          $t8, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r24;
    // 0x800D5658: lw          $t6, 0x38($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X38);
    // 0x800D565C: sw          $t6, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r14;
L_800D5660:
    // 0x800D5660: lw          $t7, 0x18C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18C);
    // 0x800D5664: lhu         $t8, 0x0($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0X0);
    // 0x800D5668: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x800D566C: sw          $t7, 0x188($sp)
    MEM_W(0X188, ctx->r29) = ctx->r15;
    // 0x800D5670: andi        $t9, $t8, 0x400
    ctx->r25 = ctx->r24 & 0X400;
    // 0x800D5674: beq         $t9, $zero, L_800D5688
    if (ctx->r25 == 0) {
        // 0x800D5678: lw          $s4, 0x34($s0)
        ctx->r20 = MEM_W(ctx->r16, 0X34);
            goto L_800D5688;
    }
    // 0x800D5678: lw          $s4, 0x34($s0)
    ctx->r20 = MEM_W(ctx->r16, 0X34);
    // 0x800D567C: lhu         $t6, 0x14($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X14);
    // 0x800D5680: nor         $t7, $t6, $zero
    ctx->r15 = ~(ctx->r14 | 0);
    // 0x800D5684: sh          $t7, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r15;
L_800D5688:
    // 0x800D5688: lhu         $a0, 0x14($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X14);
    // 0x800D568C: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x800D5690: andi        $t8, $a0, 0x400
    ctx->r24 = ctx->r4 & 0X400;
    // 0x800D5694: beq         $t8, $zero, L_800D56A8
    if (ctx->r24 == 0) {
        // 0x800D5698: or          $s3, $a0, $zero
        ctx->r19 = ctx->r4 | 0;
            goto L_800D56A8;
    }
    // 0x800D5698: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800D569C: sh          $a0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r4;
    // 0x800D56A0: lhu         $a0, 0x14($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X14);
    // 0x800D56A4: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
L_800D56A8:
    // 0x800D56A8: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x800D56AC: andi        $v1, $s3, 0x1
    ctx->r3 = ctx->r19 & 0X1;
    // 0x800D56B0: beql        $v0, $s3, L_800D5840
    if (ctx->r2 == ctx->r19) {
        // 0x800D56B4: andi        $t7, $a0, 0x8
        ctx->r15 = ctx->r4 & 0X8;
            goto L_800D5840;
    }
    goto skip_0;
    // 0x800D56B4: andi        $t7, $a0, 0x8
    ctx->r15 = ctx->r4 & 0X8;
    skip_0:
    // 0x800D56B8: beq         $v1, $zero, L_800D56F4
    if (ctx->r3 == 0) {
        // 0x800D56BC: andi        $t9, $v0, 0x1
        ctx->r25 = ctx->r2 & 0X1;
            goto L_800D56F4;
    }
    // 0x800D56BC: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x800D56C0: bne         $t9, $zero, L_800D56F4
    if (ctx->r25 != 0) {
        // 0x800D56C4: lw          $t6, 0x18C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X18C);
            goto L_800D56F4;
    }
    // 0x800D56C4: lw          $t6, 0x18C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18C);
    // 0x800D56C8: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800D56CC: sw          $t7, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r15;
    // 0x800D56D0: lui         $t8, 0xE200
    ctx->r24 = S32(0XE200 << 16);
    // 0x800D56D4: lui         $t9, 0x50
    ctx->r25 = S32(0X50 << 16);
    // 0x800D56D8: ori         $t9, $t9, 0x4240
    ctx->r25 = ctx->r25 | 0X4240;
    // 0x800D56DC: ori         $t8, $t8, 0x1C
    ctx->r24 = ctx->r24 | 0X1C;
    // 0x800D56E0: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x800D56E4: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x800D56E8: lhu         $a0, 0x14($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X14);
    // 0x800D56EC: b           L_800D572C
    // 0x800D56F0: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
        goto L_800D572C;
    // 0x800D56F0: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
L_800D56F4:
    // 0x800D56F4: bne         $v1, $zero, L_800D572C
    if (ctx->r3 != 0) {
        // 0x800D56F8: andi        $t6, $v0, 0x1
        ctx->r14 = ctx->r2 & 0X1;
            goto L_800D572C;
    }
    // 0x800D56F8: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x800D56FC: beq         $t6, $zero, L_800D572C
    if (ctx->r14 == 0) {
        // 0x800D5700: lw          $t7, 0x18C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X18C);
            goto L_800D572C;
    }
    // 0x800D5700: lw          $t7, 0x18C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18C);
    // 0x800D5704: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x800D5708: sw          $t8, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r24;
    // 0x800D570C: lui         $t9, 0xE200
    ctx->r25 = S32(0XE200 << 16);
    // 0x800D5710: lui         $t6, 0xF0A
    ctx->r14 = S32(0XF0A << 16);
    // 0x800D5714: ori         $t6, $t6, 0x7008
    ctx->r14 = ctx->r14 | 0X7008;
    // 0x800D5718: ori         $t9, $t9, 0x1C
    ctx->r25 = ctx->r25 | 0X1C;
    // 0x800D571C: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x800D5720: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x800D5724: lhu         $a0, 0x14($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X14);
    // 0x800D5728: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
L_800D572C:
    // 0x800D572C: andi        $v0, $s3, 0x2
    ctx->r2 = ctx->r19 & 0X2;
    // 0x800D5730: beq         $v0, $zero, L_800D578C
    if (ctx->r2 == 0) {
        // 0x800D5734: nop
    
            goto L_800D578C;
    }
    // 0x800D5734: nop

    // 0x800D5738: lhu         $t7, 0x0($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X0);
    // 0x800D573C: lw          $t9, 0x18C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18C);
    // 0x800D5740: andi        $t8, $t7, 0x2
    ctx->r24 = ctx->r15 & 0X2;
    // 0x800D5744: bne         $t8, $zero, L_800D578C
    if (ctx->r24 != 0) {
        // 0x800D5748: addiu       $t6, $t9, 0x8
        ctx->r14 = ADD32(ctx->r25, 0X8);
            goto L_800D578C;
    }
    // 0x800D5748: addiu       $t6, $t9, 0x8
    ctx->r14 = ADD32(ctx->r25, 0X8);
    // 0x800D574C: sw          $t6, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r14;
    // 0x800D5750: lui         $t7, 0xF900
    ctx->r15 = S32(0XF900 << 16);
    // 0x800D5754: addiu       $t8, $zero, -0xFF
    ctx->r24 = ADD32(0, -0XFF);
    // 0x800D5758: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x800D575C: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
    // 0x800D5760: lw          $t9, 0x18C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18C);
    // 0x800D5764: lui         $t7, 0xE200
    ctx->r15 = S32(0XE200 << 16);
    // 0x800D5768: ori         $t7, $t7, 0x1E01
    ctx->r15 = ctx->r15 | 0X1E01;
    // 0x800D576C: addiu       $t6, $t9, 0x8
    ctx->r14 = ADD32(ctx->r25, 0X8);
    // 0x800D5770: sw          $t6, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r14;
    // 0x800D5774: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800D5778: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x800D577C: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
    // 0x800D5780: lhu         $a0, 0x14($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X14);
    // 0x800D5784: b           L_800D57C4
    // 0x800D5788: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
        goto L_800D57C4;
    // 0x800D5788: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
L_800D578C:
    // 0x800D578C: bnel        $v0, $zero, L_800D57C8
    if (ctx->r2 != 0) {
        // 0x800D5790: andi        $t3, $s3, 0x80
        ctx->r11 = ctx->r19 & 0X80;
            goto L_800D57C8;
    }
    goto skip_1;
    // 0x800D5790: andi        $t3, $s3, 0x80
    ctx->r11 = ctx->r19 & 0X80;
    skip_1:
    // 0x800D5794: lhu         $t9, 0x0($a1)
    ctx->r25 = MEM_HU(ctx->r5, 0X0);
    // 0x800D5798: lw          $t7, 0x18C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18C);
    // 0x800D579C: andi        $t6, $t9, 0x2
    ctx->r14 = ctx->r25 & 0X2;
    // 0x800D57A0: beq         $t6, $zero, L_800D57C4
    if (ctx->r14 == 0) {
        // 0x800D57A4: addiu       $t8, $t7, 0x8
        ctx->r24 = ADD32(ctx->r15, 0X8);
            goto L_800D57C4;
    }
    // 0x800D57A4: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x800D57A8: sw          $t8, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r24;
    // 0x800D57AC: lui         $t9, 0xE200
    ctx->r25 = S32(0XE200 << 16);
    // 0x800D57B0: ori         $t9, $t9, 0x1E01
    ctx->r25 = ctx->r25 | 0X1E01;
    // 0x800D57B4: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x800D57B8: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x800D57BC: lhu         $a0, 0x14($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X14);
    // 0x800D57C0: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
L_800D57C4:
    // 0x800D57C4: andi        $t3, $s3, 0x80
    ctx->r11 = ctx->r19 & 0X80;
L_800D57C8:
    // 0x800D57C8: beq         $t3, $zero, L_800D5804
    if (ctx->r11 == 0) {
        // 0x800D57CC: nop
    
            goto L_800D5804;
    }
    // 0x800D57CC: nop

    // 0x800D57D0: lhu         $t6, 0x0($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0X0);
    // 0x800D57D4: lw          $t8, 0x18C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18C);
    // 0x800D57D8: andi        $t7, $t6, 0x80
    ctx->r15 = ctx->r14 & 0X80;
    // 0x800D57DC: bne         $t7, $zero, L_800D5804
    if (ctx->r15 != 0) {
        // 0x800D57E0: addiu       $t9, $t8, 0x8
        ctx->r25 = ADD32(ctx->r24, 0X8);
            goto L_800D5804;
    }
    // 0x800D57E0: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x800D57E4: sw          $t9, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r25;
    // 0x800D57E8: lui         $t6, 0xE300
    ctx->r14 = S32(0XE300 << 16);
    // 0x800D57EC: ori         $t6, $t6, 0x1201
    ctx->r14 = ctx->r14 | 0X1201;
    // 0x800D57F0: addiu       $t7, $zero, 0x3000
    ctx->r15 = ADD32(0, 0X3000);
    // 0x800D57F4: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x800D57F8: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x800D57FC: b           L_800D583C
    // 0x800D5800: lhu         $a0, 0x14($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X14);
        goto L_800D583C;
    // 0x800D5800: lhu         $a0, 0x14($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X14);
L_800D5804:
    // 0x800D5804: bnel        $t3, $zero, L_800D5840
    if (ctx->r11 != 0) {
        // 0x800D5808: andi        $t7, $a0, 0x8
        ctx->r15 = ctx->r4 & 0X8;
            goto L_800D5840;
    }
    goto skip_2;
    // 0x800D5808: andi        $t7, $a0, 0x8
    ctx->r15 = ctx->r4 & 0X8;
    skip_2:
    // 0x800D580C: lhu         $t8, 0x0($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0X0);
    // 0x800D5810: lw          $t6, 0x18C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18C);
    // 0x800D5814: andi        $t9, $t8, 0x80
    ctx->r25 = ctx->r24 & 0X80;
    // 0x800D5818: beq         $t9, $zero, L_800D583C
    if (ctx->r25 == 0) {
        // 0x800D581C: addiu       $t7, $t6, 0x8
        ctx->r15 = ADD32(ctx->r14, 0X8);
            goto L_800D583C;
    }
    // 0x800D581C: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800D5820: sw          $t7, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r15;
    // 0x800D5824: lui         $t8, 0xE300
    ctx->r24 = S32(0XE300 << 16);
    // 0x800D5828: ori         $t8, $t8, 0x1201
    ctx->r24 = ctx->r24 | 0X1201;
    // 0x800D582C: addiu       $t9, $zero, 0x2000
    ctx->r25 = ADD32(0, 0X2000);
    // 0x800D5830: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x800D5834: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x800D5838: lhu         $a0, 0x14($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X14);
L_800D583C:
    // 0x800D583C: andi        $t7, $a0, 0x8
    ctx->r15 = ctx->r4 & 0X8;
L_800D5840:
    // 0x800D5840: beq         $t7, $zero, L_800D5868
    if (ctx->r15 == 0) {
        // 0x800D5844: sh          $a0, 0x0($a1)
        MEM_H(0X0, ctx->r5) = ctx->r4;
            goto L_800D5868;
    }
    // 0x800D5844: sh          $a0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r4;
    // 0x800D5848: lw          $v0, 0x18C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18C);
    // 0x800D584C: lui         $t6, 0xEE00
    ctx->r14 = S32(0XEE00 << 16);
    // 0x800D5850: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800D5854: sw          $t9, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r25;
    // 0x800D5858: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800D585C: lh          $t8, 0x16($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X16);
    // 0x800D5860: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800D5864: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
L_800D5868:
    // 0x800D5868: lw          $v0, 0x18C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18C);
    // 0x800D586C: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x800D5870: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800D5874: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800D5878: sw          $t7, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r15;
    // 0x800D587C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800D5880: lbu         $t6, 0x18($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X18);
    // 0x800D5884: lbu         $t9, 0x19($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X19);
    // 0x800D5888: sll         $t7, $t6, 24
    ctx->r15 = S32(ctx->r14 << 24);
    // 0x800D588C: sll         $t6, $t9, 16
    ctx->r14 = S32(ctx->r25 << 16);
    // 0x800D5890: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x800D5894: lbu         $t7, 0x1A($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X1A);
    // 0x800D5898: sll         $t6, $t7, 8
    ctx->r14 = S32(ctx->r15 << 8);
    // 0x800D589C: or          $t9, $t8, $t6
    ctx->r25 = ctx->r24 | ctx->r14;
    // 0x800D58A0: lbu         $t8, 0x1B($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X1B);
    // 0x800D58A4: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x800D58A8: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800D58AC: lbu         $v1, 0x30($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X30);
    // 0x800D58B0: beq         $v1, $at, L_800D58C0
    if (ctx->r3 == ctx->r1) {
        // 0x800D58B4: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_800D58C0;
    }
    // 0x800D58B4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800D58B8: bnel        $v1, $at, L_800D591C
    if (ctx->r3 != ctx->r1) {
        // 0x800D58BC: lbu         $t9, 0x1B($s0)
        ctx->r25 = MEM_BU(ctx->r16, 0X1B);
            goto L_800D591C;
    }
    goto skip_3;
    // 0x800D58BC: lbu         $t9, 0x1B($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X1B);
    skip_3:
L_800D58C0:
    // 0x800D58C0: lbu         $t7, 0x1B($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X1B);
    // 0x800D58C4: lw          $t9, 0x18C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18C);
    // 0x800D58C8: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800D58CC: bne         $t7, $at, L_800D58F8
    if (ctx->r15 != ctx->r1) {
        // 0x800D58D0: addiu       $t8, $t9, 0x8
        ctx->r24 = ADD32(ctx->r25, 0X8);
            goto L_800D58F8;
    }
    // 0x800D58D0: addiu       $t8, $t9, 0x8
    ctx->r24 = ADD32(ctx->r25, 0X8);
    // 0x800D58D4: lw          $t9, 0x18C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18C);
    // 0x800D58D8: lui         $t6, 0xFC11
    ctx->r14 = S32(0XFC11 << 16);
    // 0x800D58DC: ori         $t6, $t6, 0xFE23
    ctx->r14 = ctx->r14 | 0XFE23;
    // 0x800D58E0: addiu       $t8, $t9, 0x8
    ctx->r24 = ADD32(ctx->r25, 0X8);
    // 0x800D58E4: sw          $t8, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r24;
    // 0x800D58E8: addiu       $t7, $zero, -0xC07
    ctx->r15 = ADD32(0, -0XC07);
    // 0x800D58EC: sw          $t7, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r15;
    // 0x800D58F0: b           L_800D596C
    // 0x800D58F4: sw          $t6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r14;
        goto L_800D596C;
    // 0x800D58F4: sw          $t6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r14;
L_800D58F8:
    // 0x800D58F8: lui         $t6, 0xFC11
    ctx->r14 = S32(0XFC11 << 16);
    // 0x800D58FC: lui         $t7, 0xFF2F
    ctx->r15 = S32(0XFF2F << 16);
    // 0x800D5900: ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
    // 0x800D5904: ori         $t6, $t6, 0x9623
    ctx->r14 = ctx->r14 | 0X9623;
    // 0x800D5908: sw          $t8, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r24;
    // 0x800D590C: sw          $t7, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r15;
    // 0x800D5910: b           L_800D596C
    // 0x800D5914: sw          $t6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r14;
        goto L_800D596C;
    // 0x800D5914: sw          $t6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r14;
    // 0x800D5918: lbu         $t9, 0x1B($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X1B);
L_800D591C:
    // 0x800D591C: lw          $t8, 0x18C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18C);
    // 0x800D5920: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800D5924: bne         $t9, $at, L_800D5950
    if (ctx->r25 != ctx->r1) {
        // 0x800D5928: addiu       $t6, $t8, 0x8
        ctx->r14 = ADD32(ctx->r24, 0X8);
            goto L_800D5950;
    }
    // 0x800D5928: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x800D592C: lw          $t8, 0x18C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18C);
    // 0x800D5930: lui         $t7, 0xFC11
    ctx->r15 = S32(0XFC11 << 16);
    // 0x800D5934: ori         $t7, $t7, 0xFE23
    ctx->r15 = ctx->r15 | 0XFE23;
    // 0x800D5938: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x800D593C: sw          $t6, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r14;
    // 0x800D5940: addiu       $t9, $zero, -0xC07
    ctx->r25 = ADD32(0, -0XC07);
    // 0x800D5944: sw          $t9, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r25;
    // 0x800D5948: b           L_800D596C
    // 0x800D594C: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
        goto L_800D596C;
    // 0x800D594C: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
L_800D5950:
    // 0x800D5950: sw          $t6, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r14;
    // 0x800D5954: lui         $t7, 0xFC11
    ctx->r15 = S32(0XFC11 << 16);
    // 0x800D5958: lui         $t9, 0xFF2F
    ctx->r25 = S32(0XFF2F << 16);
    // 0x800D595C: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x800D5960: ori         $t7, $t7, 0x9623
    ctx->r15 = ctx->r15 | 0X9623;
    // 0x800D5964: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800D5968: sw          $t9, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r25;
L_800D596C:
    // 0x800D596C: lbu         $v1, 0x30($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X30);
    // 0x800D5970: lw          $t8, 0x18C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18C);
    // 0x800D5974: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800D5978: bne         $v1, $at, L_800D5A6C
    if (ctx->r3 != ctx->r1) {
        // 0x800D597C: addiu       $t6, $t8, 0x8
        ctx->r14 = ADD32(ctx->r24, 0X8);
            goto L_800D5A6C;
    }
    // 0x800D597C: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x800D5980: sw          $t6, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r14;
    // 0x800D5984: lui         $t7, 0xE300
    ctx->r15 = S32(0XE300 << 16);
    // 0x800D5988: ori         $t7, $t7, 0x1001
    ctx->r15 = ctx->r15 | 0X1001;
    // 0x800D598C: ori         $t9, $zero, 0x8000
    ctx->r25 = 0 | 0X8000;
    // 0x800D5990: sw          $t9, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r25;
    // 0x800D5994: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800D5998: lw          $t8, 0x18C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18C);
    // 0x800D599C: lui         $t7, 0xFD10
    ctx->r15 = S32(0XFD10 << 16);
    // 0x800D59A0: lui         $at, 0xF500
    ctx->r1 = S32(0XF500 << 16);
    // 0x800D59A4: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x800D59A8: sw          $t6, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r14;
    // 0x800D59AC: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800D59B0: lw          $t9, 0x20($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X20);
    // 0x800D59B4: lui         $t7, 0xE800
    ctx->r15 = S32(0XE800 << 16);
    // 0x800D59B8: lui         $t0, 0x700
    ctx->r8 = S32(0X700 << 16);
    // 0x800D59BC: sw          $t9, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r25;
    // 0x800D59C0: lw          $t8, 0x18C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18C);
    // 0x800D59C4: lui         $a3, 0xE600
    ctx->r7 = S32(0XE600 << 16);
    // 0x800D59C8: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x800D59CC: sw          $t6, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r14;
    // 0x800D59D0: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x800D59D4: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800D59D8: lw          $a1, 0x18C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18C);
    // 0x800D59DC: addiu       $t8, $a1, 0x8
    ctx->r24 = ADD32(ctx->r5, 0X8);
    // 0x800D59E0: sw          $t8, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r24;
    // 0x800D59E4: lh          $t6, 0x1C($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X1C);
    // 0x800D59E8: sw          $t0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r8;
    // 0x800D59EC: addiu       $t7, $t6, 0x100
    ctx->r15 = ADD32(ctx->r14, 0X100);
    // 0x800D59F0: andi        $t9, $t7, 0x1FF
    ctx->r25 = ctx->r15 & 0X1FF;
    // 0x800D59F4: or          $t8, $t9, $at
    ctx->r24 = ctx->r25 | ctx->r1;
    // 0x800D59F8: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x800D59FC: lw          $t6, 0x18C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18C);
    // 0x800D5A00: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800D5A04: sw          $t7, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r15;
    // 0x800D5A08: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x800D5A0C: sw          $a3, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r7;
    // 0x800D5A10: lw          $v0, 0x18C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18C);
    // 0x800D5A14: lui         $t6, 0xF000
    ctx->r14 = S32(0XF000 << 16);
    // 0x800D5A18: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800D5A1C: sw          $t8, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r24;
    // 0x800D5A20: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800D5A24: lh          $t7, 0x1E($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X1E);
    // 0x800D5A28: addiu       $t9, $t7, -0x1
    ctx->r25 = ADD32(ctx->r15, -0X1);
    // 0x800D5A2C: andi        $t8, $t9, 0x3FF
    ctx->r24 = ctx->r25 & 0X3FF;
    // 0x800D5A30: sll         $t6, $t8, 14
    ctx->r14 = S32(ctx->r24 << 14);
    // 0x800D5A34: or          $t7, $t6, $t0
    ctx->r15 = ctx->r14 | ctx->r8;
    // 0x800D5A38: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800D5A3C: lw          $t9, 0x18C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18C);
    // 0x800D5A40: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x800D5A44: addiu       $t8, $t9, 0x8
    ctx->r24 = ADD32(ctx->r25, 0X8);
    // 0x800D5A48: sw          $t8, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r24;
    // 0x800D5A4C: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x800D5A50: sw          $t6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r14;
    // 0x800D5A54: lw          $t7, 0x18C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18C);
    // 0x800D5A58: addiu       $t9, $t7, 0x8
    ctx->r25 = ADD32(ctx->r15, 0X8);
    // 0x800D5A5C: sw          $t9, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r25;
    // 0x800D5A60: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x800D5A64: sw          $a3, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r7;
    // 0x800D5A68: lbu         $v1, 0x30($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X30);
L_800D5A6C:
    // 0x800D5A6C: bne         $s6, $v1, L_800D5B04
    if (ctx->r22 != ctx->r3) {
        // 0x800D5A70: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_800D5B04;
    }
    // 0x800D5A70: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800D5A74: lhu         $t8, 0x14($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X14);
    // 0x800D5A78: lw          $t7, 0x18C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18C);
    // 0x800D5A7C: andi        $t6, $t8, 0x20
    ctx->r14 = ctx->r24 & 0X20;
    // 0x800D5A80: beq         $t6, $zero, L_800D5B04
    if (ctx->r14 == 0) {
        // 0x800D5A84: addiu       $t9, $t7, 0x8
        ctx->r25 = ADD32(ctx->r15, 0X8);
            goto L_800D5B04;
    }
    // 0x800D5A84: addiu       $t9, $t7, 0x8
    ctx->r25 = ADD32(ctx->r15, 0X8);
    // 0x800D5A88: sw          $t9, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r25;
    // 0x800D5A8C: lui         $t8, 0xE300
    ctx->r24 = S32(0XE300 << 16);
    // 0x800D5A90: ori         $t8, $t8, 0x1402
    ctx->r24 = ctx->r24 | 0X1402;
    // 0x800D5A94: sw          $t8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r24;
    // 0x800D5A98: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x800D5A9C: lw          $t6, 0x18C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18C);
    // 0x800D5AA0: lui         $t9, 0xE300
    ctx->r25 = S32(0XE300 << 16);
    // 0x800D5AA4: ori         $t9, $t9, 0x1201
    ctx->r25 = ctx->r25 | 0X1201;
    // 0x800D5AA8: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800D5AAC: sw          $t7, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r15;
    // 0x800D5AB0: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x800D5AB4: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x800D5AB8: lw          $t8, 0x18C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18C);
    // 0x800D5ABC: lui         $t9, 0x77FC
    ctx->r25 = S32(0X77FC << 16);
    // 0x800D5AC0: lui         $t7, 0xFC17
    ctx->r15 = S32(0XFC17 << 16);
    // 0x800D5AC4: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x800D5AC8: sw          $t6, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r14;
    // 0x800D5ACC: ori         $t7, $t7, 0xFE2F
    ctx->r15 = ctx->r15 | 0XFE2F;
    // 0x800D5AD0: ori         $t9, $t9, 0xF87C
    ctx->r25 = ctx->r25 | 0XF87C;
    // 0x800D5AD4: sw          $t9, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r25;
    // 0x800D5AD8: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800D5ADC: lw          $t8, 0x18C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18C);
    // 0x800D5AE0: lui         $t7, 0xEC15
    ctx->r15 = S32(0XEC15 << 16);
    // 0x800D5AE4: lui         $t9, 0x3B78
    ctx->r25 = S32(0X3B78 << 16);
    // 0x800D5AE8: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x800D5AEC: sw          $t6, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r14;
    // 0x800D5AF0: ori         $t9, $t9, 0xE42A
    ctx->r25 = ctx->r25 | 0XE42A;
    // 0x800D5AF4: ori         $t7, $t7, 0xFD5D
    ctx->r15 = ctx->r15 | 0XFD5D;
    // 0x800D5AF8: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800D5AFC: b           L_800D5BB0
    // 0x800D5B00: sw          $t9, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r25;
        goto L_800D5BB0;
    // 0x800D5B00: sw          $t9, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r25;
L_800D5B04:
    // 0x800D5B04: bne         $s6, $v1, L_800D5BB0
    if (ctx->r22 != ctx->r3) {
        // 0x800D5B08: lw          $t8, 0x18C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X18C);
            goto L_800D5BB0;
    }
    // 0x800D5B08: lw          $t8, 0x18C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18C);
    // 0x800D5B0C: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x800D5B10: sw          $t6, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r14;
    // 0x800D5B14: lui         $t7, 0xE300
    ctx->r15 = S32(0XE300 << 16);
    // 0x800D5B18: ori         $t7, $t7, 0xA01
    ctx->r15 = ctx->r15 | 0XA01;
    // 0x800D5B1C: lui         $t9, 0x10
    ctx->r25 = S32(0X10 << 16);
    // 0x800D5B20: sw          $t9, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r25;
    // 0x800D5B24: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800D5B28: lw          $t8, 0x18C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18C);
    // 0x800D5B2C: lui         $t7, 0xE300
    ctx->r15 = S32(0XE300 << 16);
    // 0x800D5B30: ori         $t7, $t7, 0x1201
    ctx->r15 = ctx->r15 | 0X1201;
    // 0x800D5B34: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x800D5B38: sw          $t6, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r14;
    // 0x800D5B3C: addiu       $t9, $zero, 0x2000
    ctx->r25 = ADD32(0, 0X2000);
    // 0x800D5B40: sw          $t9, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r25;
    // 0x800D5B44: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800D5B48: lw          $t8, 0x18C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18C);
    // 0x800D5B4C: lui         $t7, 0xE300
    ctx->r15 = S32(0XE300 << 16);
    // 0x800D5B50: ori         $t7, $t7, 0x1402
    ctx->r15 = ctx->r15 | 0X1402;
    // 0x800D5B54: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x800D5B58: sw          $t6, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r14;
    // 0x800D5B5C: addiu       $t9, $zero, 0xA00
    ctx->r25 = ADD32(0, 0XA00);
    // 0x800D5B60: sw          $t9, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r25;
    // 0x800D5B64: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800D5B68: lw          $t8, 0x18C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18C);
    // 0x800D5B6C: lui         $t7, 0xEC15
    ctx->r15 = S32(0XEC15 << 16);
    // 0x800D5B70: lui         $t9, 0x3B78
    ctx->r25 = S32(0X3B78 << 16);
    // 0x800D5B74: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x800D5B78: sw          $t6, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r14;
    // 0x800D5B7C: ori         $t9, $t9, 0xE42A
    ctx->r25 = ctx->r25 | 0XE42A;
    // 0x800D5B80: ori         $t7, $t7, 0xFD5D
    ctx->r15 = ctx->r15 | 0XFD5D;
    // 0x800D5B84: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800D5B88: sw          $t9, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r25;
    // 0x800D5B8C: lw          $t8, 0x18C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18C);
    // 0x800D5B90: lui         $t9, 0x7FFD
    ctx->r25 = S32(0X7FFD << 16);
    // 0x800D5B94: lui         $t7, 0xFC27
    ctx->r15 = S32(0XFC27 << 16);
    // 0x800D5B98: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x800D5B9C: sw          $t6, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r14;
    // 0x800D5BA0: ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
    // 0x800D5BA4: ori         $t9, $t9, 0x7E38
    ctx->r25 = ctx->r25 | 0X7E38;
    // 0x800D5BA8: sw          $t9, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r25;
    // 0x800D5BAC: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
L_800D5BB0:
    // 0x800D5BB0: lhu         $s3, 0x14($s0)
    ctx->r19 = MEM_HU(ctx->r16, 0X14);
    // 0x800D5BB4: andi        $t8, $s3, 0x10
    ctx->r24 = ctx->r19 & 0X10;
    // 0x800D5BB8: beq         $t8, $zero, L_800D5BCC
    if (ctx->r24 == 0) {
        // 0x800D5BBC: andi        $s2, $s3, 0x20
        ctx->r18 = ctx->r19 & 0X20;
            goto L_800D5BCC;
    }
    // 0x800D5BBC: andi        $s2, $s3, 0x20
    ctx->r18 = ctx->r19 & 0X20;
    // 0x800D5BC0: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800D5BC4: b           L_800D5BD8
    // 0x800D5BC8: lwc1        $f14, 0xC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XC);
        goto L_800D5BD8;
    // 0x800D5BC8: lwc1        $f14, 0xC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XC);
L_800D5BCC:
    // 0x800D5BCC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800D5BD0: nop

    // 0x800D5BD4: mov.s       $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    ctx->f16.fl = ctx->f14.fl;
L_800D5BD8:
    // 0x800D5BD8: beql        $s4, $zero, L_800D6094
    if (ctx->r20 == 0) {
        // 0x800D5BDC: lh          $t6, 0x4($s0)
        ctx->r14 = MEM_H(ctx->r16, 0X4);
            goto L_800D6094;
    }
    goto skip_4;
    // 0x800D5BDC: lh          $t6, 0x4($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X4);
    skip_4:
    // 0x800D5BE0: beql        $s2, $zero, L_800D5C1C
    if (ctx->r18 == 0) {
        // 0x800D5BE4: lh          $t7, 0x2($s0)
        ctx->r15 = MEM_H(ctx->r16, 0X2);
            goto L_800D5C1C;
    }
    goto skip_5;
    // 0x800D5BE4: lh          $t7, 0x2($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X2);
    skip_5:
    // 0x800D5BE8: lbu         $t6, 0x30($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X30);
    // 0x800D5BEC: lw          $t7, 0x18C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18C);
    // 0x800D5BF0: lui         $t8, 0xE300
    ctx->r24 = S32(0XE300 << 16);
    // 0x800D5BF4: beq         $s6, $t6, L_800D5C18
    if (ctx->r22 == ctx->r14) {
        // 0x800D5BF8: addiu       $t9, $t7, 0x8
        ctx->r25 = ADD32(ctx->r15, 0X8);
            goto L_800D5C18;
    }
    // 0x800D5BF8: addiu       $t9, $t7, 0x8
    ctx->r25 = ADD32(ctx->r15, 0X8);
    // 0x800D5BFC: sw          $t9, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r25;
    // 0x800D5C00: ori         $t8, $t8, 0xA01
    ctx->r24 = ctx->r24 | 0XA01;
    // 0x800D5C04: lui         $t6, 0x20
    ctx->r14 = S32(0X20 << 16);
    // 0x800D5C08: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x800D5C0C: sw          $t8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r24;
    // 0x800D5C10: lhu         $s3, 0x14($s0)
    ctx->r19 = MEM_HU(ctx->r16, 0X14);
    // 0x800D5C14: andi        $s2, $s3, 0x20
    ctx->r18 = ctx->r19 & 0X20;
L_800D5C18:
    // 0x800D5C18: lh          $t7, 0x2($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X2);
L_800D5C1C:
    // 0x800D5C1C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D5C20: lwc1        $f12, -0x2060($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X2060);
    // 0x800D5C24: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800D5C28: lui         $at, 0x4480
    ctx->r1 = S32(0X4480 << 16);
    // 0x800D5C2C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800D5C30: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800D5C34: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800D5C38: andi        $t8, $s3, 0x80
    ctx->r24 = ctx->r19 & 0X80;
    // 0x800D5C3C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800D5C40: or          $ra, $zero, $zero
    ctx->r31 = 0 | 0;
    // 0x800D5C44: div.s       $f4, $f10, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f14.fl);
    // 0x800D5C48: add.s       $f6, $f2, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x800D5C4C: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800D5C50: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800D5C54: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x800D5C58: nop

    // 0x800D5C5C: sw          $v0, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->r2;
    // 0x800D5C60: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800D5C64: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x800D5C68: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800D5C6C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800D5C70: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x800D5C74: nop

    // 0x800D5C78: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800D5C7C: sw          $t6, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r14;
    // 0x800D5C80: sub.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x800D5C84: andi        $t6, $s3, 0x100
    ctx->r14 = ctx->r19 & 0X100;
    // 0x800D5C88: cvt.s.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800D5C8C: mul.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x800D5C90: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800D5C94: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800D5C98: nop

    // 0x800D5C9C: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800D5CA0: sra         $t9, $v1, 5
    ctx->r25 = S32(SIGNED(ctx->r3) >> 5);
    // 0x800D5CA4: beq         $t8, $zero, L_800D5CB0
    if (ctx->r24 == 0) {
        // 0x800D5CA8: or          $t5, $t9, $zero
        ctx->r13 = ctx->r25 | 0;
            goto L_800D5CB0;
    }
    // 0x800D5CA8: or          $t5, $t9, $zero
    ctx->r13 = ctx->r25 | 0;
    // 0x800D5CAC: addiu       $t5, $t9, 0x10
    ctx->r13 = ADD32(ctx->r25, 0X10);
L_800D5CB0:
    // 0x800D5CB0: beql        $t6, $zero, L_800D5CC4
    if (ctx->r14 == 0) {
        // 0x800D5CB4: lh          $a3, 0x2C($s0)
        ctx->r7 = MEM_H(ctx->r16, 0X2C);
            goto L_800D5CC4;
    }
    goto skip_6;
    // 0x800D5CB4: lh          $a3, 0x2C($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X2C);
    skip_6:
    // 0x800D5CB8: lh          $t7, 0x42($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X42);
    // 0x800D5CBC: addu        $t5, $t5, $t7
    ctx->r13 = ADD32(ctx->r13, ctx->r15);
    // 0x800D5CC0: lh          $a3, 0x2C($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X2C);
L_800D5CC4:
    // 0x800D5CC4: mtc1        $a3, $f8
    ctx->f8.u32l = ctx->r7;
    // 0x800D5CC8: nop

    // 0x800D5CCC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800D5CD0: mul.s       $f4, $f10, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x800D5CD4: add.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x800D5CD8: add.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f12.fl;
    // 0x800D5CDC: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800D5CE0: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x800D5CE4: beql        $s2, $zero, L_800D5D00
    if (ctx->r18 == 0) {
        // 0x800D5CE8: lh          $v0, 0x28($s0)
        ctx->r2 = MEM_H(ctx->r16, 0X28);
            goto L_800D5D00;
    }
    goto skip_7;
    // 0x800D5CE8: lh          $v0, 0x28($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X28);
    skip_7:
    // 0x800D5CEC: lbu         $t8, 0x30($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X30);
    // 0x800D5CF0: beql        $s6, $t8, L_800D5D00
    if (ctx->r22 == ctx->r24) {
        // 0x800D5CF4: lh          $v0, 0x28($s0)
        ctx->r2 = MEM_H(ctx->r16, 0X28);
            goto L_800D5D00;
    }
    goto skip_8;
    // 0x800D5CF4: lh          $v0, 0x28($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X28);
    skip_8:
    // 0x800D5CF8: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x800D5CFC: lh          $v0, 0x28($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X28);
L_800D5D00:
    // 0x800D5D00: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x800D5D04: blez        $v0, L_800D6004
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800D5D08: nop
    
            goto L_800D6004;
    }
    // 0x800D5D08: nop

    // 0x800D5D0C: lh          $a1, 0x0($s4)
    ctx->r5 = MEM_H(ctx->r20, 0X0);
    // 0x800D5D10: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D5D14: blez        $a1, L_800D6004
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800D5D18: nop
    
            goto L_800D6004;
    }
    // 0x800D5D18: nop

    // 0x800D5D1C: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
    // 0x800D5D20: lwc1        $f12, -0x205C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X205C);
    // 0x800D5D24: lh          $t6, 0x4($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X4);
L_800D5D28:
    // 0x800D5D28: addu        $t7, $a1, $s1
    ctx->r15 = ADD32(ctx->r5, ctx->r17);
    // 0x800D5D2C: andi        $t3, $s3, 0x80
    ctx->r11 = ctx->r19 & 0X80;
    // 0x800D5D30: slt         $at, $t6, $t7
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800D5D34: beq         $at, $zero, L_800D5E2C
    if (ctx->r1 == 0) {
        // 0x800D5D38: andi        $t4, $s3, 0x100
        ctx->r12 = ctx->r19 & 0X100;
            goto L_800D5E2C;
    }
    // 0x800D5D38: andi        $t4, $s3, 0x100
    ctx->r12 = ctx->r19 & 0X100;
    // 0x800D5D3C: lh          $a0, 0x2C($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2C);
    // 0x800D5D40: lh          $t8, 0x2($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X2);
    // 0x800D5D44: lh          $t9, 0x12($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X12);
    // 0x800D5D48: addu        $ra, $ra, $a0
    ctx->r31 = ADD32(ctx->r31, ctx->r4);
    // 0x800D5D4C: mtc1        $ra, $f6
    ctx->f6.u32l = ctx->r31;
    // 0x800D5D50: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800D5D54: addu        $a3, $a0, $ra
    ctx->r7 = ADD32(ctx->r4, ctx->r31);
    // 0x800D5D58: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800D5D5C: addu        $fp, $fp, $t9
    ctx->r30 = ADD32(ctx->r30, ctx->r25);
    // 0x800D5D60: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800D5D64: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x800D5D68: lh          $a2, 0x6($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X6);
    // 0x800D5D6C: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800D5D70: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x800D5D74: add.s       $f0, $f2, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x800D5D78: add.s       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x800D5D7C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800D5D80: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x800D5D84: nop

    // 0x800D5D88: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x800D5D8C: nop

    // 0x800D5D90: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800D5D94: sub.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x800D5D98: mtc1        $a3, $f10
    ctx->f10.u32l = ctx->r7;
    // 0x800D5D9C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800D5DA0: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800D5DA4: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800D5DA8: mul.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x800D5DAC: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x800D5DB0: nop

    // 0x800D5DB4: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800D5DB8: add.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x800D5DBC: sra         $t9, $v1, 5
    ctx->r25 = S32(SIGNED(ctx->r3) >> 5);
    // 0x800D5DC0: or          $t5, $t9, $zero
    ctx->r13 = ctx->r25 | 0;
    // 0x800D5DC4: beq         $t3, $zero, L_800D5DD0
    if (ctx->r11 == 0) {
        // 0x800D5DC8: add.s       $f10, $f8, $f12
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f12.fl;
            goto L_800D5DD0;
    }
    // 0x800D5DC8: add.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f12.fl;
    // 0x800D5DCC: addiu       $t5, $t9, 0x10
    ctx->r13 = ADD32(ctx->r25, 0X10);
L_800D5DD0:
    // 0x800D5DD0: beq         $t4, $zero, L_800D5DE0
    if (ctx->r12 == 0) {
        // 0x800D5DD4: trunc.w.s   $f4, $f10
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
            goto L_800D5DE0;
    }
    // 0x800D5DD4: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800D5DD8: lh          $t8, 0x42($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X42);
    // 0x800D5DDC: addu        $t5, $t5, $t8
    ctx->r13 = ADD32(ctx->r13, ctx->r24);
L_800D5DE0:
    // 0x800D5DE0: mfc1        $t0, $f4
    ctx->r8 = (int32_t)ctx->f4.u32l;
    // 0x800D5DE4: addu        $t7, $v0, $fp
    ctx->r15 = ADD32(ctx->r2, ctx->r30);
    // 0x800D5DE8: sw          $t7, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->r15;
    // 0x800D5DEC: beq         $s2, $zero, L_800D5E04
    if (ctx->r18 == 0) {
        // 0x800D5DF0: addu        $t0, $t0, $fp
        ctx->r8 = ADD32(ctx->r8, ctx->r30);
            goto L_800D5E04;
    }
    // 0x800D5DF0: addu        $t0, $t0, $fp
    ctx->r8 = ADD32(ctx->r8, ctx->r30);
    // 0x800D5DF4: lbu         $t9, 0x30($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X30);
    // 0x800D5DF8: beql        $s6, $t9, L_800D5E08
    if (ctx->r22 == ctx->r25) {
        // 0x800D5DFC: lh          $v0, 0xC($s4)
        ctx->r2 = MEM_H(ctx->r20, 0XC);
            goto L_800D5E08;
    }
    goto skip_9;
    // 0x800D5DFC: lh          $v0, 0xC($s4)
    ctx->r2 = MEM_H(ctx->r20, 0XC);
    skip_9:
    // 0x800D5E00: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
L_800D5E04:
    // 0x800D5E04: lh          $v0, 0xC($s4)
    ctx->r2 = MEM_H(ctx->r20, 0XC);
L_800D5E08:
    // 0x800D5E08: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800D5E0C: beq         $v0, $zero, L_800D5E1C
    if (ctx->r2 == 0) {
        // 0x800D5E10: nop
    
            goto L_800D5E1C;
    }
    // 0x800D5E10: nop

    // 0x800D5E14: b           L_800D5E1C
    // 0x800D5E18: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800D5E1C;
    // 0x800D5E18: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800D5E1C:
    // 0x800D5E1C: addu        $t8, $v1, $ra
    ctx->r24 = ADD32(ctx->r3, ctx->r31);
    // 0x800D5E20: slt         $at, $a2, $t8
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800D5E24: bne         $at, $zero, L_800D6004
    if (ctx->r1 != 0) {
        // 0x800D5E28: nop
    
            goto L_800D6004;
    }
    // 0x800D5E28: nop

L_800D5E2C:
    // 0x800D5E2C: lh          $t6, 0x0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X0);
    // 0x800D5E30: mtc1        $s1, $f8
    ctx->f8.u32l = ctx->r17;
    // 0x800D5E34: lui         $at, 0x4480
    ctx->r1 = S32(0X4480 << 16);
    // 0x800D5E38: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x800D5E3C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800D5E40: addu        $a2, $a1, $s1
    ctx->r6 = ADD32(ctx->r5, ctx->r17);
    // 0x800D5E44: lh          $v0, 0xC($s4)
    ctx->r2 = MEM_H(ctx->r20, 0XC);
    // 0x800D5E48: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800D5E4C: cvt.s.w     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800D5E50: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800D5E54: mul.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800D5E58: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800D5E5C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800D5E60: addu        $a3, $v0, $ra
    ctx->r7 = ADD32(ctx->r2, ctx->r31);
    // 0x800D5E64: div.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f16.fl);
    // 0x800D5E68: add.s       $f0, $f2, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x800D5E6C: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800D5E70: add.s       $f8, $f0, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x800D5E74: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800D5E78: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800D5E7C: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x800D5E80: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x800D5E84: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x800D5E88: mtc1        $a0, $f8
    ctx->f8.u32l = ctx->r4;
    // 0x800D5E8C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800D5E90: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800D5E94: sub.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x800D5E98: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800D5E9C: mtc1        $a2, $f6
    ctx->f6.u32l = ctx->r6;
    // 0x800D5EA0: nop

    // 0x800D5EA4: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800D5EA8: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800D5EAC: mul.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x800D5EB0: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x800D5EB4: nop

    // 0x800D5EB8: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800D5EBC: add.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x800D5EC0: sra         $t6, $v1, 5
    ctx->r14 = S32(SIGNED(ctx->r3) >> 5);
    // 0x800D5EC4: or          $t1, $t6, $zero
    ctx->r9 = ctx->r14 | 0;
    // 0x800D5EC8: beq         $t3, $zero, L_800D5ED4
    if (ctx->r11 == 0) {
        // 0x800D5ECC: add.s       $f6, $f10, $f12
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f12.fl;
            goto L_800D5ED4;
    }
    // 0x800D5ECC: add.s       $f6, $f10, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x800D5ED0: addiu       $t1, $t6, 0x10
    ctx->r9 = ADD32(ctx->r14, 0X10);
L_800D5ED4:
    // 0x800D5ED4: beq         $t4, $zero, L_800D5EE4
    if (ctx->r12 == 0) {
        // 0x800D5ED8: trunc.w.s   $f4, $f6
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.u32l = TRUNC_W_S(ctx->f6.fl);
            goto L_800D5EE4;
    }
    // 0x800D5ED8: trunc.w.s   $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800D5EDC: lh          $t7, 0x40($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X40);
    // 0x800D5EE0: addu        $t1, $t1, $t7
    ctx->r9 = ADD32(ctx->r9, ctx->r15);
L_800D5EE4:
    // 0x800D5EE4: mfc1        $v1, $f4
    ctx->r3 = (int32_t)ctx->f4.u32l;
    // 0x800D5EE8: beq         $v0, $zero, L_800D5F34
    if (ctx->r2 == 0) {
        // 0x800D5EEC: lw          $t6, 0x178($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X178);
            goto L_800D5F34;
    }
    // 0x800D5EEC: lw          $t6, 0x178($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X178);
    // 0x800D5EF0: mtc1        $a3, $f6
    ctx->f6.u32l = ctx->r7;
    // 0x800D5EF4: lh          $t8, 0x2($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X2);
    // 0x800D5EF8: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800D5EFC: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x800D5F00: nop

    // 0x800D5F04: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800D5F08: mul.s       $f8, $f4, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x800D5F0C: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800D5F10: add.s       $f4, $f6, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f12.fl;
    // 0x800D5F14: trunc.w.s   $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800D5F18: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x800D5F1C: beq         $s2, $zero, L_800D5F34
    if (ctx->r18 == 0) {
        // 0x800D5F20: addu        $t0, $t0, $fp
        ctx->r8 = ADD32(ctx->r8, ctx->r30);
            goto L_800D5F34;
    }
    // 0x800D5F20: addu        $t0, $t0, $fp
    ctx->r8 = ADD32(ctx->r8, ctx->r30);
    // 0x800D5F24: lbu         $t7, 0x30($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X30);
    // 0x800D5F28: beql        $s6, $t7, L_800D5F38
    if (ctx->r22 == ctx->r15) {
        // 0x800D5F2C: addu        $a3, $a0, $s7
        ctx->r7 = ADD32(ctx->r4, ctx->r23);
            goto L_800D5F38;
    }
    goto skip_10;
    // 0x800D5F2C: addu        $a3, $a0, $s7
    ctx->r7 = ADD32(ctx->r4, ctx->r23);
    skip_10:
    // 0x800D5F30: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
L_800D5F34:
    // 0x800D5F34: addu        $a3, $a0, $s7
    ctx->r7 = ADD32(ctx->r4, ctx->r23);
L_800D5F38:
    // 0x800D5F38: beq         $s2, $zero, L_800D5F50
    if (ctx->r18 == 0) {
        // 0x800D5F3C: addu        $v1, $v1, $s7
        ctx->r3 = ADD32(ctx->r3, ctx->r23);
            goto L_800D5F50;
    }
    // 0x800D5F3C: addu        $v1, $v1, $s7
    ctx->r3 = ADD32(ctx->r3, ctx->r23);
    // 0x800D5F40: lbu         $t9, 0x30($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X30);
    // 0x800D5F44: beql        $s6, $t9, L_800D5F54
    if (ctx->r22 == ctx->r25) {
        // 0x800D5F48: lw          $t8, 0x8($s4)
        ctx->r24 = MEM_W(ctx->r20, 0X8);
            goto L_800D5F54;
    }
    goto skip_11;
    // 0x800D5F48: lw          $t8, 0x8($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X8);
    skip_11:
    // 0x800D5F4C: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
L_800D5F50:
    // 0x800D5F50: lw          $t8, 0x8($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X8);
L_800D5F54:
    // 0x800D5F54: addiu       $a0, $sp, 0x18C
    ctx->r4 = ADD32(ctx->r29, 0X18C);
    // 0x800D5F58: beql        $t8, $zero, L_800D5FDC
    if (ctx->r24 == 0) {
        // 0x800D5F5C: lw          $t7, 0x7C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X7C);
            goto L_800D5FDC;
    }
    goto skip_12;
    // 0x800D5F5C: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
    skip_12:
    // 0x800D5F60: lw          $t7, 0x88($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X88);
    // 0x800D5F64: sw          $ra, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r31;
    // 0x800D5F68: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x800D5F6C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800D5F70: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // 0x800D5F74: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x800D5F78: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x800D5F7C: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x800D5F80: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x800D5F84: sw          $t0, 0x170($sp)
    MEM_W(0X170, ctx->r29) = ctx->r8;
    // 0x800D5F88: sw          $t5, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->r13;
    // 0x800D5F8C: swc1        $f14, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->f14.u32l;
    // 0x800D5F90: swc1        $f16, 0x198($sp)
    MEM_W(0X198, ctx->r29) = ctx->f16.u32l;
    // 0x800D5F94: swc1        $f18, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f18.u32l;
    // 0x800D5F98: jal         0x800D3DA8
    // 0x800D5F9C: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    func_800D3DA8(rdram, ctx);
        goto after_0;
    // 0x800D5F9C: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    after_0:
    // 0x800D5FA0: lh          $t9, 0x28($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X28);
    // 0x800D5FA4: lhu         $s3, 0x14($s0)
    ctx->r19 = MEM_HU(ctx->r16, 0X14);
    // 0x800D5FA8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D5FAC: sw          $t9, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r25;
    // 0x800D5FB0: lh          $t8, 0x0($s4)
    ctx->r24 = MEM_H(ctx->r20, 0X0);
    // 0x800D5FB4: lwc1        $f12, -0x2058($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X2058);
    // 0x800D5FB8: lw          $t0, 0x170($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X170);
    // 0x800D5FBC: lw          $t5, 0x158($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X158);
    // 0x800D5FC0: lw          $ra, 0x19C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X19C);
    // 0x800D5FC4: lwc1        $f14, 0x194($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X194);
    // 0x800D5FC8: lwc1        $f16, 0x198($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X198);
    // 0x800D5FCC: lwc1        $f18, 0x64($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800D5FD0: andi        $s2, $s3, 0x20
    ctx->r18 = ctx->r19 & 0X20;
    // 0x800D5FD4: addu        $a2, $t8, $s1
    ctx->r6 = ADD32(ctx->r24, ctx->r17);
    // 0x800D5FD8: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
L_800D5FDC:
    // 0x800D5FDC: lh          $t6, 0x10($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X10);
    // 0x800D5FE0: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x800D5FE4: slt         $at, $s5, $t7
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800D5FE8: addiu       $s4, $s4, 0x10
    ctx->r20 = ADD32(ctx->r20, 0X10);
    // 0x800D5FEC: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x800D5FF0: beq         $at, $zero, L_800D6004
    if (ctx->r1 == 0) {
        // 0x800D5FF4: addu        $s7, $s7, $t6
        ctx->r23 = ADD32(ctx->r23, ctx->r14);
            goto L_800D6004;
    }
    // 0x800D5FF4: addu        $s7, $s7, $t6
    ctx->r23 = ADD32(ctx->r23, ctx->r14);
    // 0x800D5FF8: lh          $a1, 0x0($s4)
    ctx->r5 = MEM_H(ctx->r20, 0X0);
    // 0x800D5FFC: bgtzl       $a1, L_800D5D28
    if (SIGNED(ctx->r5) > 0) {
        // 0x800D6000: lh          $t6, 0x4($s0)
        ctx->r14 = MEM_H(ctx->r16, 0X4);
            goto L_800D5D28;
    }
    goto skip_13;
    // 0x800D6000: lh          $t6, 0x4($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X4);
    skip_13:
L_800D6004:
    // 0x800D6004: beq         $s2, $zero, L_800D6024
    if (ctx->r18 == 0) {
        // 0x800D6008: lw          $t9, 0x18C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X18C);
            goto L_800D6024;
    }
    // 0x800D6008: lw          $t9, 0x18C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18C);
    // 0x800D600C: addiu       $t8, $t9, 0x8
    ctx->r24 = ADD32(ctx->r25, 0X8);
    // 0x800D6010: sw          $t8, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r24;
    // 0x800D6014: lui         $t6, 0xE300
    ctx->r14 = S32(0XE300 << 16);
    // 0x800D6018: ori         $t6, $t6, 0xA01
    ctx->r14 = ctx->r14 | 0XA01;
    // 0x800D601C: sw          $t6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r14;
    // 0x800D6020: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
L_800D6024:
    // 0x800D6024: lbu         $v1, 0x30($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X30);
    // 0x800D6028: lw          $t7, 0x18C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18C);
    // 0x800D602C: lui         $t8, 0xE300
    ctx->r24 = S32(0XE300 << 16);
    // 0x800D6030: bne         $s6, $v1, L_800D62A8
    if (ctx->r22 != ctx->r3) {
        // 0x800D6034: addiu       $t9, $t7, 0x8
        ctx->r25 = ADD32(ctx->r15, 0X8);
            goto L_800D62A8;
    }
    // 0x800D6034: addiu       $t9, $t7, 0x8
    ctx->r25 = ADD32(ctx->r15, 0X8);
    // 0x800D6038: sw          $t9, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r25;
    // 0x800D603C: ori         $t8, $t8, 0xA01
    ctx->r24 = ctx->r24 | 0XA01;
    // 0x800D6040: sw          $t8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r24;
    // 0x800D6044: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x800D6048: lw          $t6, 0x18C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18C);
    // 0x800D604C: lui         $t9, 0xE300
    ctx->r25 = S32(0XE300 << 16);
    // 0x800D6050: ori         $t9, $t9, 0x1201
    ctx->r25 = ctx->r25 | 0X1201;
    // 0x800D6054: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800D6058: sw          $t7, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r15;
    // 0x800D605C: addiu       $t8, $zero, 0x2000
    ctx->r24 = ADD32(0, 0X2000);
    // 0x800D6060: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x800D6064: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x800D6068: lw          $t6, 0x18C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18C);
    // 0x800D606C: lui         $t9, 0xE300
    ctx->r25 = S32(0XE300 << 16);
    // 0x800D6070: ori         $t9, $t9, 0x1402
    ctx->r25 = ctx->r25 | 0X1402;
    // 0x800D6074: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800D6078: sw          $t7, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r15;
    // 0x800D607C: addiu       $t8, $zero, 0xC00
    ctx->r24 = ADD32(0, 0XC00);
    // 0x800D6080: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x800D6084: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x800D6088: b           L_800D62A8
    // 0x800D608C: lbu         $v1, 0x30($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X30);
        goto L_800D62A8;
    // 0x800D608C: lbu         $v1, 0x30($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X30);
    // 0x800D6090: lh          $t6, 0x4($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X4);
L_800D6094:
    // 0x800D6094: lh          $s1, 0x0($s0)
    ctx->r17 = MEM_H(ctx->r16, 0X0);
    // 0x800D6098: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800D609C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800D60A0: mtc1        $s1, $f8
    ctx->f8.u32l = ctx->r17;
    // 0x800D60A4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800D60A8: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800D60AC: lh          $t9, 0x6($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X6);
    // 0x800D60B0: lh          $v1, 0x2($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X2);
    // 0x800D60B4: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x800D60B8: lw          $a0, -0x7F70($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7F70);
    // 0x800D60BC: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800D60C0: mul.s       $f8, $f10, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800D60C4: slt         $at, $s1, $a0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800D60C8: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x800D60CC: or          $ra, $v1, $zero
    ctx->r31 = ctx->r3 | 0;
    // 0x800D60D0: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800D60D4: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x800D60D8: sub.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800D60DC: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800D60E0: trunc.w.s   $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800D60E4: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x800D60E8: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800D60EC: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800D60F0: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x800D60F4: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800D60F8: sub.s       $f6, $f10, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x800D60FC: trunc.w.s   $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800D6100: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x800D6104: beq         $at, $zero, L_800D6120
    if (ctx->r1 == 0) {
        // 0x800D6108: nop
    
            goto L_800D6120;
    }
    // 0x800D6108: nop

    // 0x800D610C: lw          $a2, -0x7F6C($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7F6C);
    // 0x800D6110: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800D6114: slt         $at, $v1, $a2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800D6118: bne         $at, $zero, L_800D6128
    if (ctx->r1 != 0) {
        // 0x800D611C: nop
    
            goto L_800D6128;
    }
    // 0x800D611C: nop

L_800D6120:
    // 0x800D6120: b           L_800D62A8
    // 0x800D6124: lbu         $v1, 0x30($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X30);
        goto L_800D62A8;
    // 0x800D6124: lbu         $v1, 0x30($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X30);
L_800D6128:
    // 0x800D6128: lw          $v0, -0x7F68($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7F68);
    // 0x800D612C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800D6130: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800D6134: bne         $at, $zero, L_800D6150
    if (ctx->r1 != 0) {
        // 0x800D6138: nop
    
            goto L_800D6150;
    }
    // 0x800D6138: nop

    // 0x800D613C: lw          $v1, -0x7F64($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7F64);
    // 0x800D6140: lui         $t1, 0x8000
    ctx->r9 = S32(0X8000 << 16);
    // 0x800D6144: slt         $at, $a3, $v1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800D6148: beql        $at, $zero, L_800D615C
    if (ctx->r1 == 0) {
        // 0x800D614C: slt         $at, $s1, $v0
        ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_800D615C;
    }
    goto skip_14;
    // 0x800D614C: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    skip_14:
L_800D6150:
    // 0x800D6150: b           L_800D62A8
    // 0x800D6154: lbu         $v1, 0x30($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X30);
        goto L_800D62A8;
    // 0x800D6154: lbu         $v1, 0x30($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X30);
    // 0x800D6158: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
L_800D615C:
    // 0x800D615C: beql        $at, $zero, L_800D616C
    if (ctx->r1 == 0) {
        // 0x800D6160: slt         $at, $a1, $a0
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_800D616C;
    }
    goto skip_15;
    // 0x800D6160: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    skip_15:
    // 0x800D6164: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800D6168: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
L_800D616C:
    // 0x800D616C: bnel        $at, $zero, L_800D617C
    if (ctx->r1 != 0) {
        // 0x800D6170: slt         $at, $ra, $v1
        ctx->r1 = SIGNED(ctx->r31) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_800D617C;
    }
    goto skip_16;
    // 0x800D6170: slt         $at, $ra, $v1
    ctx->r1 = SIGNED(ctx->r31) < SIGNED(ctx->r3) ? 1 : 0;
    skip_16:
    // 0x800D6174: addiu       $a1, $a0, -0x1
    ctx->r5 = ADD32(ctx->r4, -0X1);
    // 0x800D6178: slt         $at, $ra, $v1
    ctx->r1 = SIGNED(ctx->r31) < SIGNED(ctx->r3) ? 1 : 0;
L_800D617C:
    // 0x800D617C: beql        $at, $zero, L_800D618C
    if (ctx->r1 == 0) {
        // 0x800D6180: slt         $at, $a3, $a2
        ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_800D618C;
    }
    goto skip_17;
    // 0x800D6180: slt         $at, $a3, $a2
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r6) ? 1 : 0;
    skip_17:
    // 0x800D6184: or          $ra, $v1, $zero
    ctx->r31 = ctx->r3 | 0;
    // 0x800D6188: slt         $at, $a3, $a2
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r6) ? 1 : 0;
L_800D618C:
    // 0x800D618C: bnel        $at, $zero, L_800D619C
    if (ctx->r1 != 0) {
        // 0x800D6190: lbu         $t6, 0x18($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X18);
            goto L_800D619C;
    }
    goto skip_18;
    // 0x800D6190: lbu         $t6, 0x18($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X18);
    skip_18:
    // 0x800D6194: addiu       $a3, $a2, -0x1
    ctx->r7 = ADD32(ctx->r6, -0X1);
    // 0x800D6198: lbu         $t6, 0x18($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X18);
L_800D619C:
    // 0x800D619C: lbu         $t8, 0x19($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X19);
    // 0x800D61A0: ori         $t1, $t1, 0x8000
    ctx->r9 = ctx->r9 | 0X8000;
    // 0x800D61A4: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x800D61A8: andi        $t9, $t7, 0xF800
    ctx->r25 = ctx->r15 & 0XF800;
    // 0x800D61AC: sll         $t6, $t8, 3
    ctx->r14 = S32(ctx->r24 << 3);
    // 0x800D61B0: andi        $t7, $t6, 0x7C0
    ctx->r15 = ctx->r14 & 0X7C0;
    // 0x800D61B4: lbu         $t6, 0x1A($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X1A);
    // 0x800D61B8: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x800D61BC: lui         $t2, 0xE300
    ctx->r10 = S32(0XE300 << 16);
    // 0x800D61C0: sra         $t9, $t6, 2
    ctx->r25 = S32(SIGNED(ctx->r14) >> 2);
    // 0x800D61C4: andi        $t7, $t9, 0x3E
    ctx->r15 = ctx->r25 & 0X3E;
    // 0x800D61C8: lbu         $t9, 0x1B($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X1B);
    // 0x800D61CC: or          $t6, $t8, $t7
    ctx->r14 = ctx->r24 | ctx->r15;
    // 0x800D61D0: ori         $t2, $t2, 0xA01
    ctx->r10 = ctx->r10 | 0XA01;
    // 0x800D61D4: sra         $t8, $t9, 7
    ctx->r24 = S32(SIGNED(ctx->r25) >> 7);
    // 0x800D61D8: lw          $t9, 0x18C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18C);
    // 0x800D61DC: andi        $t7, $t8, 0x1
    ctx->r15 = ctx->r24 & 0X1;
    // 0x800D61E0: or          $v0, $t6, $t7
    ctx->r2 = ctx->r14 | ctx->r15;
    // 0x800D61E4: addiu       $t8, $t9, 0x8
    ctx->r24 = ADD32(ctx->r25, 0X8);
    // 0x800D61E8: sw          $t8, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r24;
    // 0x800D61EC: lui         $t6, 0xD700
    ctx->r14 = S32(0XD700 << 16);
    // 0x800D61F0: sw          $t6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r14;
    // 0x800D61F4: sw          $t1, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r9;
    // 0x800D61F8: lw          $t7, 0x18C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18C);
    // 0x800D61FC: lui         $t8, 0x30
    ctx->r24 = S32(0X30 << 16);
    // 0x800D6200: lui         $at, 0xF600
    ctx->r1 = S32(0XF600 << 16);
    // 0x800D6204: addiu       $t9, $t7, 0x8
    ctx->r25 = ADD32(ctx->r15, 0X8);
    // 0x800D6208: sw          $t9, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r25;
    // 0x800D620C: sw          $t8, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r24;
    // 0x800D6210: sw          $t2, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r10;
    // 0x800D6214: lw          $a2, 0x18C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18C);
    // 0x800D6218: sll         $t8, $v0, 16
    ctx->r24 = S32(ctx->r2 << 16);
    // 0x800D621C: or          $t6, $t8, $v0
    ctx->r14 = ctx->r24 | ctx->r2;
    // 0x800D6220: addiu       $t7, $a2, 0x8
    ctx->r15 = ADD32(ctx->r6, 0X8);
    // 0x800D6224: sw          $t7, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r15;
    // 0x800D6228: lui         $t9, 0xF700
    ctx->r25 = S32(0XF700 << 16);
    // 0x800D622C: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800D6230: sw          $t6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r14;
    // 0x800D6234: lw          $t0, 0x18C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18C);
    // 0x800D6238: andi        $t8, $a1, 0x3FF
    ctx->r24 = ctx->r5 & 0X3FF;
    // 0x800D623C: sll         $t6, $t8, 14
    ctx->r14 = S32(ctx->r24 << 14);
    // 0x800D6240: addiu       $t9, $t0, 0x8
    ctx->r25 = ADD32(ctx->r8, 0X8);
    // 0x800D6244: sw          $t9, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r25;
    // 0x800D6248: andi        $t9, $a3, 0x3FF
    ctx->r25 = ctx->r7 & 0X3FF;
    // 0x800D624C: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x800D6250: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x800D6254: or          $t6, $t7, $t8
    ctx->r14 = ctx->r15 | ctx->r24;
    // 0x800D6258: andi        $t8, $ra, 0x3FF
    ctx->r24 = ctx->r31 & 0X3FF;
    // 0x800D625C: andi        $t9, $s1, 0x3FF
    ctx->r25 = ctx->r17 & 0X3FF;
    // 0x800D6260: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x800D6264: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x800D6268: sll         $t7, $t9, 14
    ctx->r15 = S32(ctx->r25 << 14);
    // 0x800D626C: or          $t9, $t7, $t6
    ctx->r25 = ctx->r15 | ctx->r14;
    // 0x800D6270: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x800D6274: lw          $t8, 0x18C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18C);
    // 0x800D6278: addiu       $t7, $t8, 0x8
    ctx->r15 = ADD32(ctx->r24, 0X8);
    // 0x800D627C: sw          $t7, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r15;
    // 0x800D6280: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x800D6284: sw          $t2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r10;
    // 0x800D6288: lw          $t6, 0x18C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18C);
    // 0x800D628C: lui         $t8, 0xD700
    ctx->r24 = S32(0XD700 << 16);
    // 0x800D6290: ori         $t8, $t8, 0x2
    ctx->r24 = ctx->r24 | 0X2;
    // 0x800D6294: addiu       $t9, $t6, 0x8
    ctx->r25 = ADD32(ctx->r14, 0X8);
    // 0x800D6298: sw          $t9, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r25;
    // 0x800D629C: sw          $t1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r9;
    // 0x800D62A0: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x800D62A4: lbu         $v1, 0x30($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X30);
L_800D62A8:
    // 0x800D62A8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800D62AC: bne         $v1, $at, L_800D62CC
    if (ctx->r3 != ctx->r1) {
        // 0x800D62B0: lw          $t7, 0x18C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X18C);
            goto L_800D62CC;
    }
    // 0x800D62B0: lw          $t7, 0x18C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18C);
    // 0x800D62B4: addiu       $t6, $t7, 0x8
    ctx->r14 = ADD32(ctx->r15, 0X8);
    // 0x800D62B8: sw          $t6, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r14;
    // 0x800D62BC: lui         $t9, 0xE300
    ctx->r25 = S32(0XE300 << 16);
    // 0x800D62C0: ori         $t9, $t9, 0x1001
    ctx->r25 = ctx->r25 | 0X1001;
    // 0x800D62C4: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x800D62C8: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
L_800D62CC:
    // 0x800D62CC: lw          $t8, 0x18C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18C);
    // 0x800D62D0: lui         $t6, 0xDF00
    ctx->r14 = S32(0XDF00 << 16);
    // 0x800D62D4: addiu       $t7, $t8, 0x8
    ctx->r15 = ADD32(ctx->r24, 0X8);
    // 0x800D62D8: sw          $t7, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r15;
    // 0x800D62DC: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x800D62E0: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x800D62E4: lw          $t9, 0x18C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18C);
    // 0x800D62E8: sw          $t9, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r25;
    // 0x800D62EC: lw          $v0, 0x188($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X188);
L_800D62F0:
    // 0x800D62F0: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x800D62F4: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x800D62F8: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x800D62FC: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x800D6300: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x800D6304: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x800D6308: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x800D630C: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x800D6310: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x800D6314: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x800D6318: jr          $ra
    // 0x800D631C: addiu       $sp, $sp, 0x1A8
    ctx->r29 = ADD32(ctx->r29, 0X1A8);
    return;
    // 0x800D631C: addiu       $sp, $sp, 0x1A8
    ctx->r29 = ADD32(ctx->r29, 0X1A8);
;}
RECOMP_FUNC void spX2Finish_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D6320: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800D6324: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x800D6328: ori         $t7, $t7, 0x8000
    ctx->r15 = ctx->r15 | 0X8000;
    // 0x800D632C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800D6330: lui         $t6, 0xD700
    ctx->r14 = S32(0XD700 << 16);
    // 0x800D6334: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800D6338: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800D633C: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x800D6340: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800D6344: lui         $t8, 0xFCFF
    ctx->r24 = S32(0XFCFF << 16);
    // 0x800D6348: lui         $t9, 0xFFFE
    ctx->r25 = S32(0XFFFE << 16);
    // 0x800D634C: ori         $t9, $t9, 0x793C
    ctx->r25 = ctx->r25 | 0X793C;
    // 0x800D6350: ori         $t8, $t8, 0xFFFF
    ctx->r24 = ctx->r24 | 0XFFFF;
    // 0x800D6354: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x800D6358: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x800D635C: lui         $a2, 0x800F
    ctx->r6 = S32(0X800F << 16);
    // 0x800D6360: lhu         $a2, -0x324C($a2)
    ctx->r6 = MEM_HU(ctx->r6, -0X324C);
    // 0x800D6364: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800D6368: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800D636C: andi        $t0, $a2, 0x1
    ctx->r8 = ctx->r6 & 0X1;
    // 0x800D6370: beq         $t0, $zero, L_800D639C
    if (ctx->r8 == 0) {
        // 0x800D6374: lui         $t5, 0xDF00
        ctx->r13 = S32(0XDF00 << 16);
            goto L_800D639C;
    }
    // 0x800D6374: lui         $t5, 0xDF00
    ctx->r13 = S32(0XDF00 << 16);
    // 0x800D6378: lui         $t1, 0xE200
    ctx->r9 = S32(0XE200 << 16);
    // 0x800D637C: lui         $t2, 0xF0A
    ctx->r10 = S32(0XF0A << 16);
    // 0x800D6380: ori         $t2, $t2, 0x4000
    ctx->r10 = ctx->r10 | 0X4000;
    // 0x800D6384: ori         $t1, $t1, 0x1C
    ctx->r9 = ctx->r9 | 0X1C;
    // 0x800D6388: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x800D638C: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x800D6390: lui         $a2, 0x800F
    ctx->r6 = S32(0X800F << 16);
    // 0x800D6394: lhu         $a2, -0x324C($a2)
    ctx->r6 = MEM_HU(ctx->r6, -0X324C);
    // 0x800D6398: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
L_800D639C:
    // 0x800D639C: andi        $t3, $a2, 0x2
    ctx->r11 = ctx->r6 & 0X2;
    // 0x800D63A0: beq         $t3, $zero, L_800D63BC
    if (ctx->r11 == 0) {
        // 0x800D63A4: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800D63BC;
    }
    // 0x800D63A4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800D63A8: lui         $t4, 0xE200
    ctx->r12 = S32(0XE200 << 16);
    // 0x800D63AC: ori         $t4, $t4, 0x1E01
    ctx->r12 = ctx->r12 | 0X1E01;
    // 0x800D63B0: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x800D63B4: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800D63B8: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
L_800D63BC:
    // 0x800D63BC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800D63C0: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x800D63C4: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800D63C8: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800D63CC: jr          $ra
    // 0x800D63D0: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    return;
    // 0x800D63D0: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x800D63D4: nop

    // 0x800D63D8: nop

    // 0x800D63DC: nop

;}
RECOMP_FUNC void _bzero_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D6510: slti        $at, $a1, 0xC
    ctx->r1 = SIGNED(ctx->r5) < 0XC ? 1 : 0;
    // 0x800D6514: bne         $at, $zero, L_800D658C
    if (ctx->r1 != 0) {
        // 0x800D6518: negu        $v1, $a0
        ctx->r3 = SUB32(0, ctx->r4);
            goto L_800D658C;
    }
    // 0x800D6518: negu        $v1, $a0
    ctx->r3 = SUB32(0, ctx->r4);
    // 0x800D651C: andi        $v1, $v1, 0x3
    ctx->r3 = ctx->r3 & 0X3;
    // 0x800D6520: beq         $v1, $zero, L_800D6530
    if (ctx->r3 == 0) {
        // 0x800D6524: subu        $a1, $a1, $v1
        ctx->r5 = SUB32(ctx->r5, ctx->r3);
            goto L_800D6530;
    }
    // 0x800D6524: subu        $a1, $a1, $v1
    ctx->r5 = SUB32(ctx->r5, ctx->r3);
    // 0x800D6528: swl         $zero, 0x0($a0)
    do_swl(rdram, 0X0, ctx->r4, 0);
    // 0x800D652C: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
L_800D6530:
    // 0x800D6530: addiu       $at, $zero, -0x20
    ctx->r1 = ADD32(0, -0X20);
    // 0x800D6534: and         $a3, $a1, $at
    ctx->r7 = ctx->r5 & ctx->r1;
    // 0x800D6538: beq         $a3, $zero, L_800D656C
    if (ctx->r7 == 0) {
        // 0x800D653C: subu        $a1, $a1, $a3
        ctx->r5 = SUB32(ctx->r5, ctx->r7);
            goto L_800D656C;
    }
    // 0x800D653C: subu        $a1, $a1, $a3
    ctx->r5 = SUB32(ctx->r5, ctx->r7);
    // 0x800D6540: addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
L_800D6544:
    // 0x800D6544: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x800D6548: sw          $zero, -0x20($a0)
    MEM_W(-0X20, ctx->r4) = 0;
    // 0x800D654C: sw          $zero, -0x1C($a0)
    MEM_W(-0X1C, ctx->r4) = 0;
    // 0x800D6550: sw          $zero, -0x18($a0)
    MEM_W(-0X18, ctx->r4) = 0;
    // 0x800D6554: sw          $zero, -0x14($a0)
    MEM_W(-0X14, ctx->r4) = 0;
    // 0x800D6558: sw          $zero, -0x10($a0)
    MEM_W(-0X10, ctx->r4) = 0;
    // 0x800D655C: sw          $zero, -0xC($a0)
    MEM_W(-0XC, ctx->r4) = 0;
    // 0x800D6560: sw          $zero, -0x8($a0)
    MEM_W(-0X8, ctx->r4) = 0;
    // 0x800D6564: bne         $a0, $a3, L_800D6544
    if (ctx->r4 != ctx->r7) {
        // 0x800D6568: sw          $zero, -0x4($a0)
        MEM_W(-0X4, ctx->r4) = 0;
            goto L_800D6544;
    }
    // 0x800D6568: sw          $zero, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = 0;
L_800D656C:
    // 0x800D656C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800D6570: and         $a3, $a1, $at
    ctx->r7 = ctx->r5 & ctx->r1;
    // 0x800D6574: beq         $a3, $zero, L_800D658C
    if (ctx->r7 == 0) {
        // 0x800D6578: subu        $a1, $a1, $a3
        ctx->r5 = SUB32(ctx->r5, ctx->r7);
            goto L_800D658C;
    }
    // 0x800D6578: subu        $a1, $a1, $a3
    ctx->r5 = SUB32(ctx->r5, ctx->r7);
    // 0x800D657C: addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
L_800D6580:
    // 0x800D6580: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800D6584: bne         $a0, $a3, L_800D6580
    if (ctx->r4 != ctx->r7) {
        // 0x800D6588: sw          $zero, -0x4($a0)
        MEM_W(-0X4, ctx->r4) = 0;
            goto L_800D6580;
    }
    // 0x800D6588: sw          $zero, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = 0;
L_800D658C:
    // 0x800D658C: blez        $a1, L_800D65A4
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800D6590: nop
    
            goto L_800D65A4;
    }
    // 0x800D6590: nop

    // 0x800D6594: addu        $a1, $a1, $a0
    ctx->r5 = ADD32(ctx->r5, ctx->r4);
L_800D6598:
    // 0x800D6598: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800D659C: bne         $a0, $a1, L_800D6598
    if (ctx->r4 != ctx->r5) {
        // 0x800D65A0: sb          $zero, -0x1($a0)
        MEM_B(-0X1, ctx->r4) = 0;
            goto L_800D6598;
    }
    // 0x800D65A0: sb          $zero, -0x1($a0)
    MEM_B(-0X1, ctx->r4) = 0;
L_800D65A4:
    // 0x800D65A4: jr          $ra
    // 0x800D65A8: nop

    return;
    // 0x800D65A8: nop

    // 0x800D65AC: nop

;}
RECOMP_FUNC void guLookAtF_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D65B0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800D65B4: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x800D65B8: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x800D65BC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800D65C0: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x800D65C4: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x800D65C8: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x800D65CC: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x800D65D0: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x800D65D4: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800D65D8: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x800D65DC: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x800D65E0: jal         0x800D6D20
    // 0x800D65E4: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    guMtxIdentF_recomp(rdram, ctx);
        goto after_0;
    // 0x800D65E4: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    after_0:
    // 0x800D65E8: lwc1        $f4, 0x60($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800D65EC: lwc1        $f6, 0x54($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800D65F0: lwc1        $f8, 0x64($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800D65F4: lwc1        $f10, 0x58($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800D65F8: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800D65FC: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800D6600: lwc1        $f4, 0x68($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800D6604: sub.s       $f22, $f8, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800D6608: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800D660C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800D6610: sub.s       $f24, $f4, $f6
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f24.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800D6614: mul.s       $f10, $f22, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x800D6618: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800D661C: mul.s       $f6, $f24, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f24.fl, ctx->f24.fl);
    // 0x800D6620: jal         0x800D68E0
    // 0x800D6624: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x800D6624: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_1:
    // 0x800D6628: lui         $at, 0xBFF0
    ctx->r1 = S32(0XBFF0 << 16);
    // 0x800D662C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800D6630: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800D6634: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x800D6638: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800D663C: div.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = DIV_D(ctx->f8.d, ctx->f10.d);
    // 0x800D6640: lwc1        $f10, 0x74($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800D6644: cvt.s.d     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f2.fl = CVT_S_D(ctx->f4.d);
    // 0x800D6648: mul.s       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x800D664C: nop

    // 0x800D6650: mul.s       $f22, $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f22.fl = MUL_S(ctx->f22.fl, ctx->f2.fl);
    // 0x800D6654: nop

    // 0x800D6658: mul.s       $f24, $f24, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f24.fl = MUL_S(ctx->f24.fl, ctx->f2.fl);
    // 0x800D665C: nop

    // 0x800D6660: mul.s       $f8, $f6, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f24.fl);
    // 0x800D6664: nop

    // 0x800D6668: mul.s       $f4, $f10, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f22.fl);
    // 0x800D666C: sub.s       $f26, $f8, $f4
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f26.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x800D6670: mul.s       $f8, $f10, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x800D6674: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800D6678: mul.s       $f10, $f4, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f24.fl);
    // 0x800D667C: sub.s       $f28, $f8, $f10
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f28.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800D6680: mul.s       $f8, $f4, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x800D6684: nop

    // 0x800D6688: mul.s       $f10, $f6, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x800D668C: sub.s       $f30, $f8, $f10
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f30.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800D6690: mul.s       $f4, $f26, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f26.fl, ctx->f26.fl);
    // 0x800D6694: nop

    // 0x800D6698: mul.s       $f6, $f28, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f6.fl = MUL_S(ctx->f28.fl, ctx->f28.fl);
    // 0x800D669C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800D66A0: mul.s       $f10, $f30, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = MUL_S(ctx->f30.fl, ctx->f30.fl);
    // 0x800D66A4: jal         0x800D68E0
    // 0x800D66A8: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_2;
    // 0x800D66A8: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_2:
    // 0x800D66AC: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800D66B0: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800D66B4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800D66B8: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x800D66BC: div.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = DIV_D(ctx->f4.d, ctx->f6.d);
    // 0x800D66C0: cvt.s.d     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f2.fl = CVT_S_D(ctx->f8.d);
    // 0x800D66C4: mul.s       $f26, $f26, $f2
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f26.fl = MUL_S(ctx->f26.fl, ctx->f2.fl);
    // 0x800D66C8: nop

    // 0x800D66CC: mul.s       $f28, $f28, $f2
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f28.fl = MUL_S(ctx->f28.fl, ctx->f2.fl);
    // 0x800D66D0: nop

    // 0x800D66D4: mul.s       $f30, $f30, $f2
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f30.fl = MUL_S(ctx->f30.fl, ctx->f2.fl);
    // 0x800D66D8: nop

    // 0x800D66DC: mul.s       $f10, $f22, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f30.fl);
    // 0x800D66E0: nop

    // 0x800D66E4: mul.s       $f4, $f24, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = MUL_S(ctx->f24.fl, ctx->f28.fl);
    // 0x800D66E8: nop

    // 0x800D66EC: mul.s       $f6, $f24, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = MUL_S(ctx->f24.fl, ctx->f26.fl);
    // 0x800D66F0: nop

    // 0x800D66F4: mul.s       $f8, $f20, $f30
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f30.fl);
    // 0x800D66F8: sub.s       $f14, $f10, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x800D66FC: mul.s       $f10, $f20, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f28.fl);
    // 0x800D6700: nop

    // 0x800D6704: mul.s       $f4, $f22, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f26.fl);
    // 0x800D6708: swc1        $f14, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f14.u32l;
    // 0x800D670C: sub.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800D6710: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800D6714: nop

    // 0x800D6718: mul.s       $f8, $f16, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x800D671C: swc1        $f16, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f16.u32l;
    // 0x800D6720: sub.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x800D6724: mul.s       $f4, $f18, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x800D6728: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800D672C: swc1        $f18, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f18.u32l;
    // 0x800D6730: jal         0x800D68E0
    // 0x800D6734: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_3;
    // 0x800D6734: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    after_3:
    // 0x800D6738: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800D673C: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800D6740: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800D6744: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x800D6748: lwc1        $f14, 0x6C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800D674C: div.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = DIV_D(ctx->f6.d, ctx->f8.d);
    // 0x800D6750: lwc1        $f12, 0x70($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800D6754: lwc1        $f4, 0x74($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800D6758: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800D675C: cvt.s.d     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f2.fl = CVT_S_D(ctx->f10.d);
    // 0x800D6760: mul.s       $f14, $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x800D6764: nop

    // 0x800D6768: mul.s       $f12, $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x800D676C: nop

    // 0x800D6770: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800D6774: swc1        $f6, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f6.u32l;
    // 0x800D6778: swc1        $f26, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f26.u32l;
    // 0x800D677C: swc1        $f28, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f28.u32l;
    // 0x800D6780: swc1        $f30, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f30.u32l;
    // 0x800D6784: lwc1        $f8, 0x54($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800D6788: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800D678C: mul.s       $f10, $f8, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f26.fl);
    // 0x800D6790: nop

    // 0x800D6794: mul.s       $f6, $f4, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f28.fl);
    // 0x800D6798: lwc1        $f4, 0x5C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800D679C: swc1        $f14, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f14.u32l;
    // 0x800D67A0: swc1        $f12, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f12.u32l;
    // 0x800D67A4: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800D67A8: mul.s       $f10, $f4, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f30.fl);
    // 0x800D67AC: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800D67B0: neg.s       $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = -ctx->f6.fl;
    // 0x800D67B4: swc1        $f4, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f4.u32l;
    // 0x800D67B8: lwc1        $f0, 0x74($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800D67BC: swc1        $f12, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f12.u32l;
    // 0x800D67C0: swc1        $f14, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f14.u32l;
    // 0x800D67C4: lwc1        $f14, 0x54($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800D67C8: lwc1        $f12, 0x58($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800D67CC: lwc1        $f2, 0x5C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800D67D0: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x800D67D4: lwc1        $f8, 0x6C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800D67D8: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800D67DC: swc1        $f20, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f20.u32l;
    // 0x800D67E0: mul.s       $f10, $f14, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f8.fl);
    // 0x800D67E4: swc1        $f22, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f22.u32l;
    // 0x800D67E8: swc1        $f24, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f24.u32l;
    // 0x800D67EC: mul.s       $f4, $f12, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f6.fl);
    // 0x800D67F0: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800D67F4: mul.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800D67F8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800D67FC: nop

    // 0x800D6800: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
    // 0x800D6804: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x800D6808: swc1        $f0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f0.u32l;
    // 0x800D680C: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800D6810: mul.s       $f8, $f14, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f20.fl);
    // 0x800D6814: nop

    // 0x800D6818: mul.s       $f6, $f12, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f22.fl);
    // 0x800D681C: neg.s       $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = -ctx->f10.fl;
    // 0x800D6820: swc1        $f4, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f4.u32l;
    // 0x800D6824: mul.s       $f4, $f2, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f24.fl);
    // 0x800D6828: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800D682C: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800D6830: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800D6834: neg.s       $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = -ctx->f8.fl;
    // 0x800D6838: swc1        $f10, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f10.u32l;
    // 0x800D683C: swc1        $f6, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f6.u32l;
    // 0x800D6840: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x800D6844: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x800D6848: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x800D684C: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x800D6850: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x800D6854: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x800D6858: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x800D685C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800D6860: jr          $ra
    // 0x800D6864: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800D6864: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void guLookAt_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D6868: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x800D686C: lwc1        $f4, 0x80($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800D6870: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800D6874: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800D6878: mtc1        $a3, $f16
    ctx->f16.u32l = ctx->r7;
    // 0x800D687C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800D6880: lwc1        $f4, 0x94($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X94);
    // 0x800D6884: lwc1        $f6, 0x84($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X84);
    // 0x800D6888: lwc1        $f8, 0x88($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X88);
    // 0x800D688C: lwc1        $f10, 0x8C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x800D6890: lwc1        $f18, 0x90($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X90);
    // 0x800D6894: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800D6898: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x800D689C: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x800D68A0: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x800D68A4: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x800D68A8: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x800D68AC: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x800D68B0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x800D68B4: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x800D68B8: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x800D68BC: jal         0x800D65B0
    // 0x800D68C0: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    guLookAtF_recomp(rdram, ctx);
        goto after_0;
    // 0x800D68C0: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x800D68C4: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x800D68C8: jal         0x800D6C20
    // 0x800D68CC: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    guMtxF2L_recomp(rdram, ctx);
        goto after_1;
    // 0x800D68CC: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    after_1:
    // 0x800D68D0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800D68D4: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x800D68D8: jr          $ra
    // 0x800D68DC: nop

    return;
    // 0x800D68DC: nop

;}
RECOMP_FUNC void sqrtf_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D68E0: jr          $ra
    // 0x800D68E4: sqrt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = sqrtf(ctx->f12.fl);
    return;
    // 0x800D68E4: sqrt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = sqrtf(ctx->f12.fl);
    // 0x800D68E8: nop

    // 0x800D68EC: nop

;}
RECOMP_FUNC void sinf_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D68F0: swc1        $f12, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f12.u32l;
    // 0x800D68F4: lw          $v0, 0x0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X0);
    // 0x800D68F8: lwc1        $f4, 0x0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X0);
    // 0x800D68FC: sra         $v1, $v0, 22
    ctx->r3 = S32(SIGNED(ctx->r2) >> 22);
    // 0x800D6900: andi        $t6, $v1, 0x1FF
    ctx->r14 = ctx->r3 & 0X1FF;
    // 0x800D6904: slti        $at, $t6, 0xFF
    ctx->r1 = SIGNED(ctx->r14) < 0XFF ? 1 : 0;
    // 0x800D6908: beq         $at, $zero, L_800D6970
    if (ctx->r1 == 0) {
        // 0x800D690C: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_800D6970;
    }
    // 0x800D690C: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x800D6910: slti        $at, $t6, 0xE6
    ctx->r1 = SIGNED(ctx->r14) < 0XE6 ? 1 : 0;
    // 0x800D6914: bne         $at, $zero, L_800D6968
    if (ctx->r1 != 0) {
        // 0x800D6918: cvt.d.s     $f2, $f4
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f2.d = CVT_D_S(ctx->f4.fl);
            goto L_800D6968;
    }
    // 0x800D6918: cvt.d.s     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f2.d = CVT_D_S(ctx->f4.fl);
    // 0x800D691C: mul.d       $f12, $f2, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f12.d = MUL_D(ctx->f2.d, ctx->f2.d);
    // 0x800D6920: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x800D6924: addiu       $v1, $v1, -0x2050
    ctx->r3 = ADD32(ctx->r3, -0X2050);
    // 0x800D6928: ldc1        $f6, 0x20($v1)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r3, 0X20);
    // 0x800D692C: ldc1        $f10, 0x18($v1)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r3, 0X18);
    // 0x800D6930: ldc1        $f4, 0x10($v1)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r3, 0X10);
    // 0x800D6934: mul.d       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f12.d);
    // 0x800D6938: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x800D693C: ldc1        $f10, 0x8($v1)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r3, 0X8);
    // 0x800D6940: mul.d       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f12.d); 
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f12.d);
    // 0x800D6944: add.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f18.d + ctx->f4.d;
    // 0x800D6948: mul.d       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f12.d);
    // 0x800D694C: add.d       $f14, $f10, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f14.d = ctx->f10.d + ctx->f8.d;
    // 0x800D6950: mul.d       $f16, $f2, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f12.d); 
    ctx->f16.d = MUL_D(ctx->f2.d, ctx->f12.d);
    // 0x800D6954: nop

    // 0x800D6958: mul.d       $f18, $f16, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f14.d); 
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f14.d);
    // 0x800D695C: add.d       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = ctx->f18.d + ctx->f2.d;
    // 0x800D6960: jr          $ra
    // 0x800D6964: cvt.s.d     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f0.fl = CVT_S_D(ctx->f4.d);
    return;
    // 0x800D6964: cvt.s.d     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f0.fl = CVT_S_D(ctx->f4.d);
L_800D6968:
    // 0x800D6968: jr          $ra
    // 0x800D696C: lwc1        $f0, 0x0($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X0);
    return;
    // 0x800D696C: lwc1        $f0, 0x0($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X0);
L_800D6970:
    // 0x800D6970: slti        $at, $v1, 0x136
    ctx->r1 = SIGNED(ctx->r3) < 0X136 ? 1 : 0;
    // 0x800D6974: beq         $at, $zero, L_800D6A88
    if (ctx->r1 == 0) {
        // 0x800D6978: lwc1        $f4, 0x0($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X0);
            goto L_800D6A88;
    }
    // 0x800D6978: lwc1        $f4, 0x0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X0);
    // 0x800D697C: lwc1        $f6, 0x0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X0);
    // 0x800D6980: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D6984: ldc1        $f10, -0x2028($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X2028);
    // 0x800D6988: cvt.d.s     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f2.d = CVT_D_S(ctx->f6.fl);
    // 0x800D698C: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x800D6990: mul.d       $f0, $f2, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f10.d); 
    ctx->f0.d = MUL_D(ctx->f2.d, ctx->f10.d);
    // 0x800D6994: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800D6998: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800D699C: c.le.d      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.d <= ctx->f0.d;
    // 0x800D69A0: nop

    // 0x800D69A4: bc1fl       L_800D69D4
    if (!c1cs) {
        // 0x800D69A8: mtc1        $at, $f7
        ctx->f_odd[(7 - 1) * 2] = ctx->r1;
            goto L_800D69D4;
    }
    goto skip_0;
    // 0x800D69A8: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    skip_0:
    // 0x800D69AC: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800D69B0: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800D69B4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800D69B8: nop

    // 0x800D69BC: add.d       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f0.d + ctx->f16.d;
    // 0x800D69C0: trunc.w.d   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_D(ctx->f18.d);
    // 0x800D69C4: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x800D69C8: b           L_800D69F0
    // 0x800D69CC: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
        goto L_800D69F0;
    // 0x800D69CC: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x800D69D0: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
L_800D69D4:
    // 0x800D69D4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800D69D8: nop

    // 0x800D69DC: sub.d       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f0.d - ctx->f6.d;
    // 0x800D69E0: trunc.w.d   $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = TRUNC_W_D(ctx->f10.d);
    // 0x800D69E4: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x800D69E8: nop

    // 0x800D69EC: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
L_800D69F0:
    // 0x800D69F0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D69F4: ldc1        $f18, -0x2020($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X2020);
    // 0x800D69F8: cvt.d.w     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.d = CVT_D_W(ctx->f16.u32l);
    // 0x800D69FC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D6A00: ldc1        $f6, -0x2018($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X2018);
    // 0x800D6A04: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x800D6A08: addiu       $v1, $v1, -0x2050
    ctx->r3 = ADD32(ctx->r3, -0X2050);
    // 0x800D6A0C: mul.d       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f0.d, ctx->f18.d);
    // 0x800D6A10: ldc1        $f8, 0x20($v1)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r3, 0X20);
    // 0x800D6A14: ldc1        $f18, 0x18($v1)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r3, 0X18);
    // 0x800D6A18: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x800D6A1C: mul.d       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = MUL_D(ctx->f0.d, ctx->f6.d);
    // 0x800D6A20: sub.d       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f2.d = ctx->f2.d - ctx->f4.d;
    // 0x800D6A24: sub.d       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f10.d); 
    ctx->f2.d = ctx->f2.d - ctx->f10.d;
    // 0x800D6A28: ldc1        $f10, 0x10($v1)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r3, 0X10);
    // 0x800D6A2C: mul.d       $f12, $f2, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f12.d = MUL_D(ctx->f2.d, ctx->f2.d);
    // 0x800D6A30: nop

    // 0x800D6A34: mul.d       $f16, $f8, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f12.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f12.d);
    // 0x800D6A38: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x800D6A3C: ldc1        $f18, 0x8($v1)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r3, 0X8);
    // 0x800D6A40: mul.d       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f12.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f12.d);
    // 0x800D6A44: add.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f6.d + ctx->f10.d;
    // 0x800D6A48: mul.d       $f16, $f8, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f12.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f12.d);
    // 0x800D6A4C: bne         $t9, $zero, L_800D6A6C
    if (ctx->r25 != 0) {
        // 0x800D6A50: add.d       $f14, $f18, $f16
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f14.d = ctx->f18.d + ctx->f16.d;
            goto L_800D6A6C;
    }
    // 0x800D6A50: add.d       $f14, $f18, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f14.d = ctx->f18.d + ctx->f16.d;
    // 0x800D6A54: mul.d       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f12.d); 
    ctx->f4.d = MUL_D(ctx->f2.d, ctx->f12.d);
    // 0x800D6A58: nop

    // 0x800D6A5C: mul.d       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f14.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f14.d);
    // 0x800D6A60: add.d       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = ctx->f6.d + ctx->f2.d;
    // 0x800D6A64: jr          $ra
    // 0x800D6A68: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    return;
    // 0x800D6A68: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
L_800D6A6C:
    // 0x800D6A6C: mul.d       $f8, $f2, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = MUL_D(ctx->f2.d, ctx->f12.d);
    // 0x800D6A70: nop

    // 0x800D6A74: mul.d       $f18, $f8, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f14.d); 
    ctx->f18.d = MUL_D(ctx->f8.d, ctx->f14.d);
    // 0x800D6A78: add.d       $f16, $f18, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f2.d); 
    ctx->f16.d = ctx->f18.d + ctx->f2.d;
    // 0x800D6A7C: cvt.s.d     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f0.fl = CVT_S_D(ctx->f16.d);
    // 0x800D6A80: jr          $ra
    // 0x800D6A84: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    return;
    // 0x800D6A84: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
L_800D6A88:
    // 0x800D6A88: c.eq.s      $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f4.fl == ctx->f4.fl;
    // 0x800D6A8C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D6A90: bc1t        L_800D6AA4
    if (c1cs) {
        // 0x800D6A94: nop
    
            goto L_800D6AA4;
    }
    // 0x800D6A94: nop

    // 0x800D6A98: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D6A9C: jr          $ra
    // 0x800D6AA0: lwc1        $f0, -0x1F00($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X1F00);
    return;
    // 0x800D6AA0: lwc1        $f0, -0x1F00($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X1F00);
L_800D6AA4:
    // 0x800D6AA4: lwc1        $f0, -0x2010($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2010);
    // 0x800D6AA8: jr          $ra
    // 0x800D6AAC: nop

    return;
    // 0x800D6AAC: nop

;}
RECOMP_FUNC void __cosf_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D6AB0: swc1        $f12, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f12.u32l;
    // 0x800D6AB4: lw          $v0, 0x0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X0);
    // 0x800D6AB8: lwc1        $f6, 0x0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X0);
    // 0x800D6ABC: lwc1        $f10, 0x0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X0);
    // 0x800D6AC0: sra         $t6, $v0, 22
    ctx->r14 = S32(SIGNED(ctx->r2) >> 22);
    // 0x800D6AC4: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x800D6AC8: slti        $at, $t7, 0x136
    ctx->r1 = SIGNED(ctx->r15) < 0X136 ? 1 : 0;
    // 0x800D6ACC: beql        $at, $zero, L_800D6BF4
    if (ctx->r1 == 0) {
        // 0x800D6AD0: c.eq.s      $f10, $f10
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f10.fl == ctx->f10.fl;
            goto L_800D6BF4;
    }
    goto skip_0;
    // 0x800D6AD0: c.eq.s      $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f10.fl == ctx->f10.fl;
    skip_0:
    // 0x800D6AD4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800D6AD8: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800D6ADC: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800D6AE0: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x800D6AE4: lwc1        $f0, 0x0($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X0);
    // 0x800D6AE8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D6AEC: bc1fl       L_800D6B00
    if (!c1cs) {
        // 0x800D6AF0: neg.s       $f0, $f0
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
            goto L_800D6B00;
    }
    goto skip_1;
    // 0x800D6AF0: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    skip_1:
    // 0x800D6AF4: b           L_800D6B00
    // 0x800D6AF8: mov.s       $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = ctx->f6.fl;
        goto L_800D6B00;
    // 0x800D6AF8: mov.s       $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = ctx->f6.fl;
    // 0x800D6AFC: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
L_800D6B00:
    // 0x800D6B00: ldc1        $f8, -0x1FD8($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X1FD8);
    // 0x800D6B04: cvt.d.s     $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.d = CVT_D_S(ctx->f0.fl);
    // 0x800D6B08: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800D6B0C: mul.d       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f12.d, ctx->f8.d);
    // 0x800D6B10: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x800D6B14: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800D6B18: add.d       $f14, $f10, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f14.d = ctx->f10.d + ctx->f18.d;
    // 0x800D6B1C: c.le.d      $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f4.d <= ctx->f14.d;
    // 0x800D6B20: nop

    // 0x800D6B24: bc1fl       L_800D6B44
    if (!c1cs) {
        // 0x800D6B28: sub.d       $f10, $f14, $f18
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = ctx->f14.d - ctx->f18.d;
            goto L_800D6B44;
    }
    goto skip_2;
    // 0x800D6B28: sub.d       $f10, $f14, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = ctx->f14.d - ctx->f18.d;
    skip_2:
    // 0x800D6B2C: add.d       $f6, $f14, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = ctx->f14.d + ctx->f18.d;
    // 0x800D6B30: trunc.w.d   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_D(ctx->f6.d);
    // 0x800D6B34: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x800D6B38: b           L_800D6B54
    // 0x800D6B3C: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
        goto L_800D6B54;
    // 0x800D6B3C: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x800D6B40: sub.d       $f10, $f14, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = ctx->f14.d - ctx->f18.d;
L_800D6B44:
    // 0x800D6B44: trunc.w.d   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_D(ctx->f10.d);
    // 0x800D6B48: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x800D6B4C: nop

    // 0x800D6B50: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
L_800D6B54:
    // 0x800D6B54: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D6B58: ldc1        $f10, -0x1FD0($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X1FD0);
    // 0x800D6B5C: cvt.d.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.d = CVT_D_W(ctx->f6.u32l);
    // 0x800D6B60: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D6B64: ldc1        $f6, -0x1FC8($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X1FC8);
    // 0x800D6B68: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x800D6B6C: addiu       $v1, $v1, -0x2000
    ctx->r3 = ADD32(ctx->r3, -0X2000);
    // 0x800D6B70: sub.d       $f0, $f8, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f0.d = ctx->f8.d - ctx->f18.d;
    // 0x800D6B74: andi        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 & 0X1;
    // 0x800D6B78: mul.d       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f0.d, ctx->f10.d);
    // 0x800D6B7C: ldc1        $f10, 0x20($v1)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r3, 0X20);
    // 0x800D6B80: mul.d       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f0.d, ctx->f6.d);
    // 0x800D6B84: ldc1        $f6, 0x18($v1)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r3, 0X18);
    // 0x800D6B88: sub.d       $f2, $f12, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f4.d); 
    ctx->f2.d = ctx->f12.d - ctx->f4.d;
    // 0x800D6B8C: sub.d       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f8.d); 
    ctx->f2.d = ctx->f2.d - ctx->f8.d;
    // 0x800D6B90: mul.d       $f14, $f2, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f14.d = MUL_D(ctx->f2.d, ctx->f2.d);
    // 0x800D6B94: nop

    // 0x800D6B98: mul.d       $f4, $f10, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f14.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f14.d);
    // 0x800D6B9C: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x800D6BA0: ldc1        $f4, 0x10($v1)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r3, 0X10);
    // 0x800D6BA4: mul.d       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f14.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f14.d);
    // 0x800D6BA8: add.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f10.d + ctx->f4.d;
    // 0x800D6BAC: ldc1        $f10, 0x8($v1)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r3, 0X8);
    // 0x800D6BB0: mul.d       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f14.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f14.d);
    // 0x800D6BB4: bne         $t0, $zero, L_800D6BD4
    if (ctx->r8 != 0) {
        // 0x800D6BB8: add.d       $f16, $f10, $f8
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f10.d + ctx->f8.d;
            goto L_800D6BD4;
    }
    // 0x800D6BB8: add.d       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f10.d + ctx->f8.d;
    // 0x800D6BBC: mul.d       $f4, $f2, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f14.d); 
    ctx->f4.d = MUL_D(ctx->f2.d, ctx->f14.d);
    // 0x800D6BC0: nop

    // 0x800D6BC4: mul.d       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f16.d);
    // 0x800D6BC8: add.d       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = ctx->f6.d + ctx->f2.d;
    // 0x800D6BCC: jr          $ra
    // 0x800D6BD0: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    return;
    // 0x800D6BD0: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
L_800D6BD4:
    // 0x800D6BD4: mul.d       $f8, $f2, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f14.d); 
    ctx->f8.d = MUL_D(ctx->f2.d, ctx->f14.d);
    // 0x800D6BD8: nop

    // 0x800D6BDC: mul.d       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x800D6BE0: add.d       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = ctx->f4.d + ctx->f2.d;
    // 0x800D6BE4: cvt.s.d     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f0.fl = CVT_S_D(ctx->f6.d);
    // 0x800D6BE8: jr          $ra
    // 0x800D6BEC: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    return;
    // 0x800D6BEC: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800D6BF0: c.eq.s      $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f10.fl == ctx->f10.fl;
L_800D6BF4:
    // 0x800D6BF4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D6BF8: bc1t        L_800D6C0C
    if (c1cs) {
        // 0x800D6BFC: nop
    
            goto L_800D6C0C;
    }
    // 0x800D6BFC: nop

    // 0x800D6C00: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D6C04: jr          $ra
    // 0x800D6C08: lwc1        $f0, -0x1F00($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X1F00);
    return;
    // 0x800D6C08: lwc1        $f0, -0x1F00($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X1F00);
L_800D6C0C:
    // 0x800D6C0C: lwc1        $f0, -0x1FC0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X1FC0);
    // 0x800D6C10: jr          $ra
    // 0x800D6C14: nop

    return;
    // 0x800D6C14: nop

    // 0x800D6C18: nop

    // 0x800D6C1C: nop

;}
RECOMP_FUNC void guMtxF2L_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D6C20: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x800D6C24: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800D6C28: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x800D6C2C: addiu       $v1, $a1, 0x20
    ctx->r3 = ADD32(ctx->r5, 0X20);
    // 0x800D6C30: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800D6C34: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800D6C38: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x800D6C3C: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x800D6C40: lui         $t2, 0xFFFF
    ctx->r10 = S32(0XFFFF << 16);
L_800D6C44:
    // 0x800D6C44: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800D6C48: or          $t0, $a3, $zero
    ctx->r8 = ctx->r7 | 0;
    // 0x800D6C4C: lwc1        $f14, 0x4($t0)
    ctx->f14.u32l = MEM_W(ctx->r8, 0X4);
    // 0x800D6C50: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800D6C54: lwc1        $f18, 0x0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800D6C58: mul.s       $f16, $f14, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x800D6C5C: beq         $a0, $t3, L_800D6CC4
    if (ctx->r4 == ctx->r11) {
        // 0x800D6C60: nop
    
            goto L_800D6CC4;
    }
    // 0x800D6C60: nop

L_800D6C64:
    // 0x800D6C64: mul.s       $f14, $f18, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800D6C68: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800D6C6C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800D6C70: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800D6C74: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x800D6C78: trunc.w.s   $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800D6C7C: trunc.w.s   $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x800D6C80: mfc1        $t1, $f12
    ctx->r9 = (int32_t)ctx->f12.u32l;
    // 0x800D6C84: mfc1        $a1, $f14
    ctx->r5 = (int32_t)ctx->f14.u32l;
    // 0x800D6C88: sra         $t9, $t1, 16
    ctx->r25 = S32(SIGNED(ctx->r9) >> 16);
    // 0x800D6C8C: andi        $t5, $t9, 0xFFFF
    ctx->r13 = ctx->r25 & 0XFFFF;
    // 0x800D6C90: and         $t8, $a1, $t2
    ctx->r24 = ctx->r5 & ctx->r10;
    // 0x800D6C94: or          $t6, $t8, $t5
    ctx->r14 = ctx->r24 | ctx->r13;
    // 0x800D6C98: sll         $t7, $a1, 16
    ctx->r15 = S32(ctx->r5 << 16);
    // 0x800D6C9C: and         $t9, $t7, $t2
    ctx->r25 = ctx->r15 & ctx->r10;
    // 0x800D6CA0: sw          $t6, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r14;
    // 0x800D6CA4: andi        $t8, $t1, 0xFFFF
    ctx->r24 = ctx->r9 & 0XFFFF;
    // 0x800D6CA8: or          $t5, $t9, $t8
    ctx->r13 = ctx->r25 | ctx->r24;
    // 0x800D6CAC: sw          $t5, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r13;
    // 0x800D6CB0: lwc1        $f14, 0x4($t0)
    ctx->f14.u32l = MEM_W(ctx->r8, 0X4);
    // 0x800D6CB4: lwc1        $f18, 0x0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800D6CB8: mul.s       $f16, $f14, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x800D6CBC: bne         $a0, $t3, L_800D6C64
    if (ctx->r4 != ctx->r11) {
        // 0x800D6CC0: nop
    
            goto L_800D6C64;
    }
    // 0x800D6CC0: nop

L_800D6CC4:
    // 0x800D6CC4: mul.s       $f14, $f18, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800D6CC8: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x800D6CCC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800D6CD0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800D6CD4: trunc.w.s   $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800D6CD8: trunc.w.s   $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x800D6CDC: mfc1        $t1, $f12
    ctx->r9 = (int32_t)ctx->f12.u32l;
    // 0x800D6CE0: mfc1        $a1, $f14
    ctx->r5 = (int32_t)ctx->f14.u32l;
    // 0x800D6CE4: sra         $t9, $t1, 16
    ctx->r25 = S32(SIGNED(ctx->r9) >> 16);
    // 0x800D6CE8: andi        $t5, $t9, 0xFFFF
    ctx->r13 = ctx->r25 & 0XFFFF;
    // 0x800D6CEC: and         $t8, $a1, $t2
    ctx->r24 = ctx->r5 & ctx->r10;
    // 0x800D6CF0: or          $t6, $t8, $t5
    ctx->r14 = ctx->r24 | ctx->r13;
    // 0x800D6CF4: sll         $t7, $a1, 16
    ctx->r15 = S32(ctx->r5 << 16);
    // 0x800D6CF8: and         $t9, $t7, $t2
    ctx->r25 = ctx->r15 & ctx->r10;
    // 0x800D6CFC: andi        $t8, $t1, 0xFFFF
    ctx->r24 = ctx->r9 & 0XFFFF;
    // 0x800D6D00: sw          $t6, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r14;
    // 0x800D6D04: or          $t5, $t9, $t8
    ctx->r13 = ctx->r25 | ctx->r24;
    // 0x800D6D08: sw          $t5, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r13;
    // 0x800D6D0C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800D6D10: bne         $a2, $t4, L_800D6C44
    if (ctx->r6 != ctx->r12) {
        // 0x800D6D14: addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
            goto L_800D6C44;
    }
    // 0x800D6D14: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x800D6D18: jr          $ra
    // 0x800D6D1C: nop

    return;
    // 0x800D6D1C: nop

;}
RECOMP_FUNC void guMtxIdentF_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D6D20: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800D6D24: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800D6D28: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800D6D2C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800D6D30: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800D6D34: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800D6D38: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x800D6D3C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x800D6D40: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_800D6D44:
    // 0x800D6D44: bnel        $v0, $zero, L_800D6D58
    if (ctx->r2 != 0) {
        // 0x800D6D48: swc1        $f2, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
            goto L_800D6D58;
    }
    goto skip_0;
    // 0x800D6D48: swc1        $f2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
    skip_0:
    // 0x800D6D4C: b           L_800D6D58
    // 0x800D6D50: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
        goto L_800D6D58;
    // 0x800D6D50: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x800D6D54: swc1        $f2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
L_800D6D58:
    // 0x800D6D58: bnel        $v0, $a0, L_800D6D6C
    if (ctx->r2 != ctx->r4) {
        // 0x800D6D5C: swc1        $f2, 0x4($v1)
        MEM_W(0X4, ctx->r3) = ctx->f2.u32l;
            goto L_800D6D6C;
    }
    goto skip_1;
    // 0x800D6D5C: swc1        $f2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f2.u32l;
    skip_1:
    // 0x800D6D60: b           L_800D6D6C
    // 0x800D6D64: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
        goto L_800D6D6C;
    // 0x800D6D64: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
    // 0x800D6D68: swc1        $f2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f2.u32l;
L_800D6D6C:
    // 0x800D6D6C: bnel        $v0, $a1, L_800D6D80
    if (ctx->r2 != ctx->r5) {
        // 0x800D6D70: swc1        $f2, 0x8($v1)
        MEM_W(0X8, ctx->r3) = ctx->f2.u32l;
            goto L_800D6D80;
    }
    goto skip_2;
    // 0x800D6D70: swc1        $f2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f2.u32l;
    skip_2:
    // 0x800D6D74: b           L_800D6D80
    // 0x800D6D78: swc1        $f0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f0.u32l;
        goto L_800D6D80;
    // 0x800D6D78: swc1        $f0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f0.u32l;
    // 0x800D6D7C: swc1        $f2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f2.u32l;
L_800D6D80:
    // 0x800D6D80: bnel        $v0, $a2, L_800D6D94
    if (ctx->r2 != ctx->r6) {
        // 0x800D6D84: swc1        $f2, 0xC($v1)
        MEM_W(0XC, ctx->r3) = ctx->f2.u32l;
            goto L_800D6D94;
    }
    goto skip_3;
    // 0x800D6D84: swc1        $f2, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f2.u32l;
    skip_3:
    // 0x800D6D88: b           L_800D6D94
    // 0x800D6D8C: swc1        $f0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f0.u32l;
        goto L_800D6D94;
    // 0x800D6D8C: swc1        $f0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f0.u32l;
    // 0x800D6D90: swc1        $f2, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f2.u32l;
L_800D6D94:
    // 0x800D6D94: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800D6D98: bne         $v0, $a3, L_800D6D44
    if (ctx->r2 != ctx->r7) {
        // 0x800D6D9C: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_800D6D44;
    }
    // 0x800D6D9C: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800D6DA0: jr          $ra
    // 0x800D6DA4: nop

    return;
    // 0x800D6DA4: nop

;}
RECOMP_FUNC void guMtxIdent_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D6DA8: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800D6DAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D6DB0: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x800D6DB4: jal         0x800D6D20
    // 0x800D6DB8: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    guMtxIdentF_recomp(rdram, ctx);
        goto after_0;
    // 0x800D6DB8: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x800D6DBC: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x800D6DC0: jal         0x800D6C20
    // 0x800D6DC4: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    guMtxF2L_recomp(rdram, ctx);
        goto after_1;
    // 0x800D6DC4: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    after_1:
    // 0x800D6DC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D6DCC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x800D6DD0: jr          $ra
    // 0x800D6DD4: nop

    return;
    // 0x800D6DD4: nop

;}
RECOMP_FUNC void guMtxL2F_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D6DD8: lui         $at, 0x3780
    ctx->r1 = S32(0X3780 << 16);
    // 0x800D6DDC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800D6DE0: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800D6DE4: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x800D6DE8: addiu       $v1, $a1, 0x20
    ctx->r3 = ADD32(ctx->r5, 0X20);
    // 0x800D6DEC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800D6DF0: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x800D6DF4: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x800D6DF8: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x800D6DFC: lui         $t2, 0xFFFF
    ctx->r10 = S32(0XFFFF << 16);
L_800D6E00:
    // 0x800D6E00: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800D6E04: or          $t1, $t0, $zero
    ctx->r9 = ctx->r8 | 0;
L_800D6E08:
    // 0x800D6E08: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800D6E0C: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800D6E10: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800D6E14: srl         $t7, $t6, 16
    ctx->r15 = S32(U32(ctx->r14) >> 16);
    // 0x800D6E18: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x800D6E1C: and         $t5, $t9, $t2
    ctx->r13 = ctx->r25 & ctx->r10;
    // 0x800D6E20: or          $t6, $t8, $t5
    ctx->r14 = ctx->r24 | ctx->r13;
    // 0x800D6E24: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x800D6E28: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800D6E2C: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x800D6E30: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800D6E34: sll         $t5, $t8, 16
    ctx->r13 = S32(ctx->r24 << 16);
    // 0x800D6E38: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x800D6E3C: and         $t6, $t5, $t2
    ctx->r14 = ctx->r13 & ctx->r10;
    // 0x800D6E40: andi        $t9, $t7, 0xFFFF
    ctx->r25 = ctx->r15 & 0XFFFF;
    // 0x800D6E44: or          $a3, $t9, $t6
    ctx->r7 = ctx->r25 | ctx->r14;
    // 0x800D6E48: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800D6E4C: mtc1        $a3, $f10
    ctx->f10.u32l = ctx->r7;
    // 0x800D6E50: sw          $a3, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r7;
    // 0x800D6E54: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800D6E58: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800D6E5C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800D6E60: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800D6E64: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800D6E68: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800D6E6C: swc1        $f8, -0x8($t1)
    MEM_W(-0X8, ctx->r9) = ctx->f8.u32l;
    // 0x800D6E70: bne         $a0, $t3, L_800D6E08
    if (ctx->r4 != ctx->r11) {
        // 0x800D6E74: swc1        $f18, -0x4($t1)
        MEM_W(-0X4, ctx->r9) = ctx->f18.u32l;
            goto L_800D6E08;
    }
    // 0x800D6E74: swc1        $f18, -0x4($t1)
    MEM_W(-0X4, ctx->r9) = ctx->f18.u32l;
    // 0x800D6E78: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800D6E7C: bne         $a2, $t4, L_800D6E00
    if (ctx->r6 != ctx->r12) {
        // 0x800D6E80: addiu       $t0, $t0, 0x10
        ctx->r8 = ADD32(ctx->r8, 0X10);
            goto L_800D6E00;
    }
    // 0x800D6E80: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
    // 0x800D6E84: jr          $ra
    // 0x800D6E88: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800D6E88: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    // 0x800D6E8C: nop

;}
RECOMP_FUNC void guMtxXFMF_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D6E90: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800D6E94: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800D6E98: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800D6E9C: lwc1        $f8, 0x10($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800D6EA0: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x800D6EA4: mtc1        $a3, $f16
    ctx->f16.u32l = ctx->r7;
    // 0x800D6EA8: lwc1        $f4, 0x20($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X20);
    // 0x800D6EAC: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x800D6EB0: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x800D6EB4: mul.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x800D6EB8: add.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800D6EBC: lwc1        $f10, 0x30($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X30);
    // 0x800D6EC0: add.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x800D6EC4: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800D6EC8: swc1        $f4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f4.u32l;
    // 0x800D6ECC: lwc1        $f18, 0x4($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800D6ED0: lwc1        $f10, 0x14($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800D6ED4: lw          $t7, 0x14($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X14);
    // 0x800D6ED8: mul.s       $f8, $f18, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x800D6EDC: lwc1        $f18, 0x24($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X24);
    // 0x800D6EE0: mul.s       $f6, $f10, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x800D6EE4: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800D6EE8: mul.s       $f10, $f18, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x800D6EEC: lwc1        $f6, 0x34($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X34);
    // 0x800D6EF0: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800D6EF4: add.s       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800D6EF8: swc1        $f18, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f18.u32l;
    // 0x800D6EFC: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800D6F00: lwc1        $f6, 0x18($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X18);
    // 0x800D6F04: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x800D6F08: mul.s       $f10, $f4, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x800D6F0C: lwc1        $f4, 0x28($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X28);
    // 0x800D6F10: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x800D6F14: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800D6F18: mul.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x800D6F1C: lwc1        $f8, 0x38($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X38);
    // 0x800D6F20: add.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x800D6F24: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800D6F28: jr          $ra
    // 0x800D6F2C: swc1        $f4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f4.u32l;
    return;
    // 0x800D6F2C: swc1        $f4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f4.u32l;
;}
RECOMP_FUNC void guMtxCatF_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D6F30: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800D6F34: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800D6F38: addiu       $v1, $sp, 0x1C
    ctx->r3 = ADD32(ctx->r29, 0X1C);
    // 0x800D6F3C: addiu       $t3, $sp, 0x5C
    ctx->r11 = ADD32(ctx->r29, 0X5C);
    // 0x800D6F40: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800D6F44: or          $t0, $a1, $zero
    ctx->r8 = ctx->r5 | 0;
    // 0x800D6F48: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
L_800D6F4C:
    // 0x800D6F4C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800D6F50: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x800D6F54: or          $t1, $t0, $zero
    ctx->r9 = ctx->r8 | 0;
    // 0x800D6F58: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    // 0x800D6F5C: lwc1        $f12, 0x0($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, 0X0);
    // 0x800D6F60: lwc1        $f14, 0x0($a3)
    ctx->f14.u32l = MEM_W(ctx->r7, 0X0);
    // 0x800D6F64: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800D6F68: lwc1        $f16, 0x0($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800D6F6C: mul.s       $f18, $f14, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x800D6F70: beql        $a0, $t2, L_800D6FF4
    if (ctx->r4 == ctx->r10) {
        // 0x800D6F74: add.s       $f14, $f16, $f18
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
            goto L_800D6FF4;
    }
    goto skip_0;
    // 0x800D6F74: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
    skip_0:
    // 0x800D6F78: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
L_800D6F7C:
    // 0x800D6F7C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800D6F80: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800D6F84: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x800D6F88: swc1        $f14, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f14.u32l;
    // 0x800D6F8C: lwc1        $f14, 0x4($a3)
    ctx->f14.u32l = MEM_W(ctx->r7, 0X4);
    // 0x800D6F90: lwc1        $f12, 0xC($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, 0XC);
    // 0x800D6F94: lwc1        $f10, -0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, -0X4);
    // 0x800D6F98: mul.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x800D6F9C: add.s       $f12, $f10, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x800D6FA0: swc1        $f12, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f12.u32l;
    // 0x800D6FA4: lwc1        $f12, 0x8($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0X8);
    // 0x800D6FA8: lwc1        $f10, 0x1C($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X1C);
    // 0x800D6FAC: lwc1        $f14, -0x4($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, -0X4);
    // 0x800D6FB0: mul.s       $f10, $f12, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x800D6FB4: add.s       $f10, $f14, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f14.fl + ctx->f10.fl;
    // 0x800D6FB8: swc1        $f10, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f10.u32l;
    // 0x800D6FBC: lwc1        $f10, 0xC($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0XC);
    // 0x800D6FC0: lwc1        $f14, 0x2C($t1)
    ctx->f14.u32l = MEM_W(ctx->r9, 0X2C);
    // 0x800D6FC4: lwc1        $f12, -0x4($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, -0X4);
    // 0x800D6FC8: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    // 0x800D6FCC: mul.s       $f14, $f10, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x800D6FD0: lwc1        $f16, 0x0($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800D6FD4: add.s       $f14, $f12, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x800D6FD8: swc1        $f14, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f14.u32l;
    // 0x800D6FDC: lwc1        $f14, 0x0($a3)
    ctx->f14.u32l = MEM_W(ctx->r7, 0X0);
    // 0x800D6FE0: lwc1        $f12, 0x0($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, 0X0);
    // 0x800D6FE4: mul.s       $f18, $f14, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x800D6FE8: bnel        $a0, $t2, L_800D6F7C
    if (ctx->r4 != ctx->r10) {
        // 0x800D6FEC: add.s       $f14, $f16, $f18
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
            goto L_800D6F7C;
    }
    goto skip_1;
    // 0x800D6FEC: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
    skip_1:
    // 0x800D6FF0: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
L_800D6FF4:
    // 0x800D6FF4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800D6FF8: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x800D6FFC: swc1        $f14, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f14.u32l;
    // 0x800D7000: lwc1        $f12, 0xC($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, 0XC);
    // 0x800D7004: lwc1        $f14, 0x4($a3)
    ctx->f14.u32l = MEM_W(ctx->r7, 0X4);
    // 0x800D7008: lwc1        $f10, -0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, -0X4);
    // 0x800D700C: mul.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x800D7010: add.s       $f12, $f10, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x800D7014: swc1        $f12, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f12.u32l;
    // 0x800D7018: lwc1        $f10, 0x1C($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X1C);
    // 0x800D701C: lwc1        $f12, 0x8($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0X8);
    // 0x800D7020: lwc1        $f14, -0x4($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, -0X4);
    // 0x800D7024: mul.s       $f10, $f12, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x800D7028: add.s       $f10, $f14, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f14.fl + ctx->f10.fl;
    // 0x800D702C: swc1        $f10, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f10.u32l;
    // 0x800D7030: lwc1        $f14, 0x2C($t1)
    ctx->f14.u32l = MEM_W(ctx->r9, 0X2C);
    // 0x800D7034: lwc1        $f10, 0xC($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0XC);
    // 0x800D7038: lwc1        $f12, -0x4($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, -0X4);
    // 0x800D703C: mul.s       $f14, $f10, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x800D7040: add.s       $f14, $f12, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x800D7044: swc1        $f14, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f14.u32l;
    // 0x800D7048: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800D704C: sltu        $at, $v1, $t3
    ctx->r1 = ctx->r3 < ctx->r11 ? 1 : 0;
    // 0x800D7050: bne         $at, $zero, L_800D6F4C
    if (ctx->r1 != 0) {
        // 0x800D7054: addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
            goto L_800D6F4C;
    }
    // 0x800D7054: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x800D7058: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x800D705C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x800D7060: addiu       $v0, $sp, 0x5C
    ctx->r2 = ADD32(ctx->r29, 0X5C);
L_800D7064:
    // 0x800D7064: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800D7068: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x800D706C: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800D7070: swc1        $f6, -0x10($v1)
    MEM_W(-0X10, ctx->r3) = ctx->f6.u32l;
    // 0x800D7074: lwc1        $f8, -0xC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, -0XC);
    // 0x800D7078: swc1        $f8, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = ctx->f8.u32l;
    // 0x800D707C: lwc1        $f16, -0x8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, -0X8);
    // 0x800D7080: swc1        $f16, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = ctx->f16.u32l;
    // 0x800D7084: lwc1        $f10, -0x4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, -0X4);
    // 0x800D7088: bne         $a0, $v0, L_800D7064
    if (ctx->r4 != ctx->r2) {
        // 0x800D708C: swc1        $f10, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f10.u32l;
            goto L_800D7064;
    }
    // 0x800D708C: swc1        $f10, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f10.u32l;
    // 0x800D7090: jr          $ra
    // 0x800D7094: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x800D7094: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x800D7098: nop

    // 0x800D709C: nop

;}
RECOMP_FUNC void guAlignF_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D7120: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800D7124: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D7128: lwc1        $f4, -0x1FB0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1FB0);
    // 0x800D712C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800D7130: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800D7134: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800D7138: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D713C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800D7140: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x800D7144: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x800D7148: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    // 0x800D714C: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x800D7150: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x800D7154: jal         0x800DB7A0
    // 0x800D7158: swc1        $f4, -0x7F60($at)
    MEM_W(-0X7F60, ctx->r1) = ctx->f4.u32l;
    guNormalize_recomp(rdram, ctx);
        goto after_0;
    // 0x800D7158: swc1        $f4, -0x7F60($at)
    MEM_W(-0X7F60, ctx->r1) = ctx->f4.u32l;
    after_0:
    // 0x800D715C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800D7160: lwc1        $f12, 0x3C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800D7164: lwc1        $f6, -0x7F60($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7F60);
    // 0x800D7168: mul.s       $f12, $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f6.fl);
    // 0x800D716C: jal         0x800D68F0
    // 0x800D7170: swc1        $f12, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f12.u32l;
    sinf_recomp(rdram, ctx);
        goto after_1;
    // 0x800D7170: swc1        $f12, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x800D7174: lwc1        $f12, 0x3C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800D7178: jal         0x800D6AB0
    // 0x800D717C: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    __cosf_recomp(rdram, ctx);
        goto after_2;
    // 0x800D717C: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x800D7180: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800D7184: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800D7188: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800D718C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800D7190: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800D7194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D7198: sub.s       $f2, $f8, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x800D719C: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800D71A0: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x800D71A4: mul.s       $f16, $f6, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800D71A8: nop

    // 0x800D71AC: mul.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800D71B0: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    // 0x800D71B4: mul.s       $f18, $f6, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800D71B8: nop

    // 0x800D71BC: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800D71C0: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    // 0x800D71C4: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800D71C8: jal         0x800D6D20
    // 0x800D71CC: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    guMtxIdentF_recomp(rdram, ctx);
        goto after_3;
    // 0x800D71CC: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    after_3:
    // 0x800D71D0: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800D71D4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800D71D8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800D71DC: mul.s       $f0, $f8, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x800D71E0: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800D71E4: lwc1        $f14, 0x34($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800D71E8: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800D71EC: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800D71F0: sub.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x800D71F4: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x800D71F8: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x800D71FC: swc1        $f8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f8.u32l;
    // 0x800D7200: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800D7204: mul.s       $f4, $f10, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x800D7208: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x800D720C: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
    // 0x800D7210: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800D7214: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x800D7218: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800D721C: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x800D7220: swc1        $f4, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f4.u32l;
    // 0x800D7224: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800D7228: mul.s       $f2, $f6, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x800D722C: sub.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x800D7230: mul.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x800D7234: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x800D7238: swc1        $f6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f6.u32l;
    // 0x800D723C: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800D7240: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800D7244: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x800D7248: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800D724C: swc1        $f6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f6.u32l;
    // 0x800D7250: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800D7254: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800D7258: mul.s       $f4, $f10, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x800D725C: sub.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x800D7260: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800D7264: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x800D7268: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800D726C: mul.s       $f0, $f10, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x800D7270: sub.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x800D7274: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x800D7278: add.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x800D727C: swc1        $f10, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f10.u32l;
    // 0x800D7280: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800D7284: mul.s       $f4, $f8, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x800D7288: sub.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x800D728C: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
    // 0x800D7290: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800D7294: mul.s       $f8, $f10, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x800D7298: add.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x800D729C: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x800D72A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800D72A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800D72A8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800D72AC: jr          $ra
    // 0x800D72B0: nop

    return;
    // 0x800D72B0: nop

;}
RECOMP_FUNC void guAlign_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D72B4: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800D72B8: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800D72BC: mtc1        $a3, $f16
    ctx->f16.u32l = ctx->r7;
    // 0x800D72C0: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800D72C4: lwc1        $f4, 0x70($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800D72C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D72CC: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x800D72D0: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x800D72D4: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x800D72D8: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x800D72DC: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x800D72E0: jal         0x800D7120
    // 0x800D72E4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    guAlignF_recomp(rdram, ctx);
        goto after_0;
    // 0x800D72E4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x800D72E8: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x800D72EC: jal         0x800D6C20
    // 0x800D72F0: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    guMtxF2L_recomp(rdram, ctx);
        goto after_1;
    // 0x800D72F0: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    after_1:
    // 0x800D72F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800D72F8: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x800D72FC: jr          $ra
    // 0x800D7300: nop

    return;
    // 0x800D7300: nop

    // 0x800D7304: nop

    // 0x800D7308: nop

    // 0x800D730C: nop

;}
RECOMP_FUNC void spScale_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D7310: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800D7314: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800D7318: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800D731C: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800D7320: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D7324: c.eq.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl == ctx->f0.fl;
    // 0x800D7328: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D732C: swc1        $f12, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f12.u32l;
    // 0x800D7330: swc1        $f14, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f14.u32l;
    // 0x800D7334: bc1f        L_800D735C
    if (!c1cs) {
        // 0x800D7338: nop
    
            goto L_800D735C;
    }
    // 0x800D7338: nop

    // 0x800D733C: c.eq.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl == ctx->f0.fl;
    // 0x800D7340: nop

    // 0x800D7344: bc1f        L_800D735C
    if (!c1cs) {
        // 0x800D7348: nop
    
            goto L_800D735C;
    }
    // 0x800D7348: nop

    // 0x800D734C: jal         0x800D73C0
    // 0x800D7350: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    spClearAttribute_recomp(rdram, ctx);
        goto after_0;
    // 0x800D7350: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_0:
    // 0x800D7354: b           L_800D7368
    // 0x800D7358: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800D7368;
    // 0x800D7358: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D735C:
    // 0x800D735C: jal         0x800D73B0
    // 0x800D7360: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    spSetAttribute_recomp(rdram, ctx);
        goto after_1;
    // 0x800D7360: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_1:
    // 0x800D7364: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D7368:
    // 0x800D7368: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D736C: jr          $ra
    // 0x800D7370: nop

    return;
    // 0x800D7370: nop

    // 0x800D7374: nop

    // 0x800D7378: nop

    // 0x800D737C: nop

;}
RECOMP_FUNC void spColor_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D7380: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800D7384: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x800D7388: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x800D738C: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x800D7390: sb          $a2, 0x19($a0)
    MEM_B(0X19, ctx->r4) = ctx->r6;
    // 0x800D7394: sb          $a3, 0x1A($a0)
    MEM_B(0X1A, ctx->r4) = ctx->r7;
    // 0x800D7398: lbu         $t9, 0x13($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X13);
    // 0x800D739C: jr          $ra
    // 0x800D73A0: sb          $t9, 0x1B($a0)
    MEM_B(0X1B, ctx->r4) = ctx->r25;
    return;
    // 0x800D73A0: sb          $t9, 0x1B($a0)
    MEM_B(0X1B, ctx->r4) = ctx->r25;
    // 0x800D73A4: nop

    // 0x800D73A8: nop

    // 0x800D73AC: nop

;}
RECOMP_FUNC void spSetAttribute_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D73B0: lhu         $t6, 0x14($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X14);
    // 0x800D73B4: or          $t7, $t6, $a1
    ctx->r15 = ctx->r14 | ctx->r5;
    // 0x800D73B8: jr          $ra
    // 0x800D73BC: sh          $t7, 0x14($a0)
    MEM_H(0X14, ctx->r4) = ctx->r15;
    return;
    // 0x800D73BC: sh          $t7, 0x14($a0)
    MEM_H(0X14, ctx->r4) = ctx->r15;
;}
RECOMP_FUNC void spClearAttribute_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D73C0: lhu         $t6, 0x14($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X14);
    // 0x800D73C4: nor         $t7, $a1, $zero
    ctx->r15 = ~(ctx->r5 | 0);
    // 0x800D73C8: and         $t8, $t6, $t7
    ctx->r24 = ctx->r14 & ctx->r15;
    // 0x800D73CC: jr          $ra
    // 0x800D73D0: sh          $t8, 0x14($a0)
    MEM_H(0X14, ctx->r4) = ctx->r24;
    return;
    // 0x800D73D0: sh          $t8, 0x14($a0)
    MEM_H(0X14, ctx->r4) = ctx->r24;
    // 0x800D73D4: nop

    // 0x800D73D8: nop

    // 0x800D73DC: nop

;}
RECOMP_FUNC void guMtxXFML_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D7A50: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800D7A54: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x800D7A58: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800D7A5C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800D7A60: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x800D7A64: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x800D7A68: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    // 0x800D7A6C: jal         0x800D6DD8
    // 0x800D7A70: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    guMtxL2F_recomp(rdram, ctx);
        goto after_0;
    // 0x800D7A70: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_0:
    // 0x800D7A74: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
    // 0x800D7A78: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
    // 0x800D7A7C: lw          $t8, 0x80($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X80);
    // 0x800D7A80: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x800D7A84: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
    // 0x800D7A88: lw          $a2, 0x70($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X70);
    // 0x800D7A8C: lw          $a3, 0x74($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X74);
    // 0x800D7A90: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800D7A94: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800D7A98: jal         0x800D6E90
    // 0x800D7A9C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    guMtxXFMF_recomp(rdram, ctx);
        goto after_1;
    // 0x800D7A9C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    after_1:
    // 0x800D7AA0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800D7AA4: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x800D7AA8: jr          $ra
    // 0x800D7AAC: nop

    return;
    // 0x800D7AAC: nop

;}
RECOMP_FUNC void guMtxCatL_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D7AB0: addiu       $sp, $sp, -0xD8
    ctx->r29 = ADD32(ctx->r29, -0XD8);
    // 0x800D7AB4: sw          $a1, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r5;
    // 0x800D7AB8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800D7ABC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D7AC0: sw          $a0, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r4;
    // 0x800D7AC4: sw          $a2, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r6;
    // 0x800D7AC8: jal         0x800D6DD8
    // 0x800D7ACC: addiu       $a0, $sp, 0x98
    ctx->r4 = ADD32(ctx->r29, 0X98);
    guMtxL2F_recomp(rdram, ctx);
        goto after_0;
    // 0x800D7ACC: addiu       $a0, $sp, 0x98
    ctx->r4 = ADD32(ctx->r29, 0X98);
    after_0:
    // 0x800D7AD0: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x800D7AD4: jal         0x800D6DD8
    // 0x800D7AD8: lw          $a1, 0xDC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XDC);
    guMtxL2F_recomp(rdram, ctx);
        goto after_1;
    // 0x800D7AD8: lw          $a1, 0xDC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XDC);
    after_1:
    // 0x800D7ADC: addiu       $a0, $sp, 0x98
    ctx->r4 = ADD32(ctx->r29, 0X98);
    // 0x800D7AE0: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    // 0x800D7AE4: jal         0x800D6F30
    // 0x800D7AE8: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    guMtxCatF_recomp(rdram, ctx);
        goto after_2;
    // 0x800D7AE8: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    after_2:
    // 0x800D7AEC: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x800D7AF0: jal         0x800D6C20
    // 0x800D7AF4: lw          $a1, 0xE0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XE0);
    guMtxF2L_recomp(rdram, ctx);
        goto after_3;
    // 0x800D7AF4: lw          $a1, 0xE0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XE0);
    after_3:
    // 0x800D7AF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D7AFC: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
    // 0x800D7B00: jr          $ra
    // 0x800D7B04: nop

    return;
    // 0x800D7B04: nop

    // 0x800D7B08: nop

    // 0x800D7B0C: nop

;}
RECOMP_FUNC void guLookAtHiliteF_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D7B10: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x800D7B14: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x800D7B18: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x800D7B1C: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x800D7B20: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800D7B24: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800D7B28: sdc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X38, ctx->r29);
    // 0x800D7B2C: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x800D7B30: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x800D7B34: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x800D7B38: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x800D7B3C: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x800D7B40: sw          $a2, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r6;
    // 0x800D7B44: jal         0x800D6D20
    // 0x800D7B48: sw          $a3, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r7;
    guMtxIdentF_recomp(rdram, ctx);
        goto after_0;
    // 0x800D7B48: sw          $a3, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r7;
    after_0:
    // 0x800D7B4C: lwc1        $f4, 0xB0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x800D7B50: lwc1        $f6, 0xA4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x800D7B54: lwc1        $f8, 0xB4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x800D7B58: lwc1        $f10, 0xA8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x800D7B5C: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800D7B60: lwc1        $f6, 0xAC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x800D7B64: lwc1        $f4, 0xB8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x800D7B68: sub.s       $f30, $f8, $f10
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f30.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800D7B6C: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800D7B70: mov.s       $f28, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    ctx->f28.fl = ctx->f0.fl;
    // 0x800D7B74: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800D7B78: mul.s       $f10, $f30, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = MUL_S(ctx->f30.fl, ctx->f30.fl);
    // 0x800D7B7C: swc1        $f14, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f14.u32l;
    // 0x800D7B80: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800D7B84: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800D7B88: jal         0x800D68E0
    // 0x800D7B8C: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x800D7B8C: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_1:
    // 0x800D7B90: lui         $at, 0xBFF0
    ctx->r1 = S32(0XBFF0 << 16);
    // 0x800D7B94: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800D7B98: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800D7B9C: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x800D7BA0: lwc1        $f20, 0x88($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X88);
    // 0x800D7BA4: div.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = DIV_D(ctx->f8.d, ctx->f10.d);
    // 0x800D7BA8: lwc1        $f6, 0xC0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x800D7BAC: lwc1        $f10, 0xC4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x800D7BB0: cvt.s.d     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f2.fl = CVT_S_D(ctx->f4.d);
    // 0x800D7BB4: mul.s       $f28, $f28, $f2
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f28.fl = MUL_S(ctx->f28.fl, ctx->f2.fl);
    // 0x800D7BB8: nop

    // 0x800D7BBC: mul.s       $f30, $f30, $f2
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f30.fl = MUL_S(ctx->f30.fl, ctx->f2.fl);
    // 0x800D7BC0: nop

    // 0x800D7BC4: mul.s       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x800D7BC8: nop

    // 0x800D7BCC: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x800D7BD0: swc1        $f20, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f20.u32l;
    // 0x800D7BD4: mul.s       $f4, $f10, $f30
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f30.fl);
    // 0x800D7BD8: sub.s       $f22, $f8, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f22.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x800D7BDC: mul.s       $f8, $f10, $f28
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f28.fl);
    // 0x800D7BE0: lwc1        $f4, 0xBC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x800D7BE4: mul.s       $f10, $f4, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x800D7BE8: sub.s       $f24, $f8, $f10
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f24.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800D7BEC: mul.s       $f8, $f4, $f30
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f30.fl);
    // 0x800D7BF0: nop

    // 0x800D7BF4: mul.s       $f10, $f6, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f28.fl);
    // 0x800D7BF8: sub.s       $f26, $f8, $f10
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f26.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800D7BFC: mul.s       $f4, $f22, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x800D7C00: nop

    // 0x800D7C04: mul.s       $f6, $f24, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f24.fl, ctx->f24.fl);
    // 0x800D7C08: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800D7C0C: mul.s       $f10, $f26, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = MUL_S(ctx->f26.fl, ctx->f26.fl);
    // 0x800D7C10: jal         0x800D68E0
    // 0x800D7C14: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_2;
    // 0x800D7C14: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_2:
    // 0x800D7C18: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800D7C1C: mtc1        $at, $f21
    ctx->f_odd[(21 - 1) * 2] = ctx->r1;
    // 0x800D7C20: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800D7C24: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x800D7C28: lwc1        $f10, 0x88($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X88);
    // 0x800D7C2C: div.d       $f6, $f20, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f20.d, ctx->f4.d);
    // 0x800D7C30: cvt.s.d     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f2.fl = CVT_S_D(ctx->f6.d);
    // 0x800D7C34: mul.s       $f22, $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f22.fl = MUL_S(ctx->f22.fl, ctx->f2.fl);
    // 0x800D7C38: nop

    // 0x800D7C3C: mul.s       $f24, $f24, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f24.fl = MUL_S(ctx->f24.fl, ctx->f2.fl);
    // 0x800D7C40: nop

    // 0x800D7C44: mul.s       $f26, $f26, $f2
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f26.fl = MUL_S(ctx->f26.fl, ctx->f2.fl);
    // 0x800D7C48: nop

    // 0x800D7C4C: mul.s       $f8, $f30, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = MUL_S(ctx->f30.fl, ctx->f26.fl);
    // 0x800D7C50: nop

    // 0x800D7C54: mul.s       $f4, $f10, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f24.fl);
    // 0x800D7C58: sub.s       $f14, $f8, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x800D7C5C: mul.s       $f6, $f10, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f22.fl);
    // 0x800D7C60: nop

    // 0x800D7C64: mul.s       $f8, $f28, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = MUL_S(ctx->f28.fl, ctx->f26.fl);
    // 0x800D7C68: swc1        $f14, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f14.u32l;
    // 0x800D7C6C: mul.s       $f4, $f28, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f28.fl, ctx->f24.fl);
    // 0x800D7C70: nop

    // 0x800D7C74: mul.s       $f10, $f30, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f30.fl, ctx->f22.fl);
    // 0x800D7C78: sub.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800D7C7C: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800D7C80: nop

    // 0x800D7C84: mul.s       $f8, $f16, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x800D7C88: swc1        $f16, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f16.u32l;
    // 0x800D7C8C: sub.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x800D7C90: mul.s       $f10, $f18, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x800D7C94: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800D7C98: swc1        $f18, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f18.u32l;
    // 0x800D7C9C: jal         0x800D68E0
    // 0x800D7CA0: add.s       $f12, $f4, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_3;
    // 0x800D7CA0: add.s       $f12, $f4, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f10.fl;
    after_3:
    // 0x800D7CA4: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x800D7CA8: lwc1        $f4, 0xBC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x800D7CAC: div.d       $f8, $f20, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = DIV_D(ctx->f20.d, ctx->f6.d);
    // 0x800D7CB0: lwc1        $f6, 0xC0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x800D7CB4: lwc1        $f14, 0xC8($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x800D7CB8: lwc1        $f16, 0xCC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x800D7CBC: lwc1        $f18, 0xD0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XD0);
    // 0x800D7CC0: cvt.s.d     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f2.fl = CVT_S_D(ctx->f8.d);
    // 0x800D7CC4: mul.s       $f10, $f4, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800D7CC8: lwc1        $f4, 0xC4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x800D7CCC: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800D7CD0: swc1        $f10, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f10.u32l;
    // 0x800D7CD4: mul.s       $f10, $f4, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800D7CD8: swc1        $f8, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f8.u32l;
    // 0x800D7CDC: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800D7CE0: nop

    // 0x800D7CE4: mul.s       $f8, $f16, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x800D7CE8: swc1        $f10, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f10.u32l;
    // 0x800D7CEC: mul.s       $f10, $f18, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x800D7CF0: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800D7CF4: jal         0x800D68E0
    // 0x800D7CF8: add.s       $f12, $f4, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_4;
    // 0x800D7CF8: add.s       $f12, $f4, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f10.fl;
    after_4:
    // 0x800D7CFC: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x800D7D00: lwc1        $f4, 0xC8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x800D7D04: div.d       $f8, $f20, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = DIV_D(ctx->f20.d, ctx->f6.d);
    // 0x800D7D08: lwc1        $f6, 0xCC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x800D7D0C: cvt.s.d     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f2.fl = CVT_S_D(ctx->f8.d);
    // 0x800D7D10: mul.s       $f10, $f4, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800D7D14: lwc1        $f4, 0xD0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XD0);
    // 0x800D7D18: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800D7D1C: swc1        $f10, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f10.u32l;
    // 0x800D7D20: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800D7D24: add.s       $f4, $f10, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f28.fl;
    // 0x800D7D28: swc1        $f8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->f8.u32l;
    // 0x800D7D2C: add.s       $f10, $f8, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f30.fl;
    // 0x800D7D30: lwc1        $f8, 0x88($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X88);
    // 0x800D7D34: swc1        $f6, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f6.u32l;
    // 0x800D7D38: swc1        $f4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f4.u32l;
    // 0x800D7D3C: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800D7D40: mul.s       $f8, $f4, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x800D7D44: swc1        $f10, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f10.u32l;
    // 0x800D7D48: mul.s       $f4, $f10, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x800D7D4C: swc1        $f6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f6.u32l;
    // 0x800D7D50: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800D7D54: mul.s       $f8, $f6, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x800D7D58: jal         0x800D68E0
    // 0x800D7D5C: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_5;
    // 0x800D7D5C: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    after_5:
    // 0x800D7D60: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D7D64: ldc1        $f4, -0x1FA0($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X1FA0);
    // 0x800D7D68: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
    // 0x800D7D6C: lw          $v1, 0xE4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XE4);
    // 0x800D7D70: c.lt.d      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.d < ctx->f2.d;
    // 0x800D7D74: lw          $v0, 0xE0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XE0);
    // 0x800D7D78: lw          $t4, 0xA0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XA0);
    // 0x800D7D7C: sll         $t5, $v1, 1
    ctx->r13 = S32(ctx->r3 << 1);
    // 0x800D7D80: bc1fl       L_800D7E6C
    if (!c1cs) {
        // 0x800D7D84: sll         $t3, $v0, 1
        ctx->r11 = S32(ctx->r2 << 1);
            goto L_800D7E6C;
    }
    goto skip_0;
    // 0x800D7D84: sll         $t3, $v0, 1
    ctx->r11 = S32(ctx->r2 << 1);
    skip_0:
    // 0x800D7D88: div.d       $f6, $f20, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = DIV_D(ctx->f20.d, ctx->f2.d);
    // 0x800D7D8C: lwc1        $f10, 0x5C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800D7D90: lwc1        $f8, 0x58($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800D7D94: lwc1        $f4, 0x54($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800D7D98: lw          $v0, 0xE0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XE0);
    // 0x800D7D9C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800D7DA0: lw          $t9, 0xA0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA0);
    // 0x800D7DA4: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x800D7DA8: lw          $v1, 0xE4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XE4);
    // 0x800D7DAC: sll         $t0, $v1, 2
    ctx->r8 = S32(ctx->r3 << 2);
    // 0x800D7DB0: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    // 0x800D7DB4: mul.s       $f14, $f10, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x800D7DB8: nop

    // 0x800D7DBC: mul.s       $f16, $f8, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x800D7DC0: nop

    // 0x800D7DC4: mul.s       $f18, $f4, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x800D7DC8: nop

    // 0x800D7DCC: mul.s       $f6, $f14, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f22.fl);
    // 0x800D7DD0: nop

    // 0x800D7DD4: mul.s       $f10, $f16, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f24.fl);
    // 0x800D7DD8: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800D7DDC: mul.s       $f4, $f18, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f26.fl);
    // 0x800D7DE0: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x800D7DE4: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800D7DE8: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800D7DEC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800D7DF0: mul.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800D7DF4: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x800D7DF8: mul.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800D7DFC: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800D7E00: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800D7E04: trunc.w.s   $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800D7E08: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x800D7E0C: nop

    // 0x800D7E10: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x800D7E14: lwc1        $f4, 0xBC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x800D7E18: lwc1        $f10, 0xC0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x800D7E1C: mul.s       $f6, $f14, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f4.fl);
    // 0x800D7E20: nop

    // 0x800D7E24: mul.s       $f8, $f16, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x800D7E28: lwc1        $f10, 0xC4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x800D7E2C: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800D7E30: mul.s       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x800D7E34: mtc1        $v1, $f10
    ctx->f10.u32l = ctx->r3;
    // 0x800D7E38: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800D7E3C: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800D7E40: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800D7E44: mul.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x800D7E48: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x800D7E4C: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800D7E50: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800D7E54: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800D7E58: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800D7E5C: mfc1        $t2, $f4
    ctx->r10 = (int32_t)ctx->f4.u32l;
    // 0x800D7E60: b           L_800D7E74
    // 0x800D7E64: sw          $t2, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r10;
        goto L_800D7E74;
    // 0x800D7E64: sw          $t2, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r10;
    // 0x800D7E68: sll         $t3, $v0, 1
    ctx->r11 = S32(ctx->r2 << 1);
L_800D7E6C:
    // 0x800D7E6C: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x800D7E70: sw          $t5, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r13;
L_800D7E74:
    // 0x800D7E74: lwc1        $f0, 0xD4($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x800D7E78: lwc1        $f2, 0xD8($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x800D7E7C: lwc1        $f14, 0xDC($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x800D7E80: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800D7E84: nop

    // 0x800D7E88: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800D7E8C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800D7E90: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800D7E94: jal         0x800D68E0
    // 0x800D7E98: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_6;
    // 0x800D7E98: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    after_6:
    // 0x800D7E9C: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x800D7EA0: lwc1        $f10, 0xD4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x800D7EA4: div.d       $f8, $f20, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = DIV_D(ctx->f20.d, ctx->f6.d);
    // 0x800D7EA8: lwc1        $f6, 0xD8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x800D7EAC: cvt.s.d     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f2.fl = CVT_S_D(ctx->f8.d);
    // 0x800D7EB0: mul.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800D7EB4: lwc1        $f10, 0xDC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x800D7EB8: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800D7EBC: swc1        $f4, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f4.u32l;
    // 0x800D7EC0: mul.s       $f6, $f10, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800D7EC4: add.s       $f10, $f4, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f28.fl;
    // 0x800D7EC8: swc1        $f8, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f8.u32l;
    // 0x800D7ECC: add.s       $f4, $f8, $f30
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f30.fl;
    // 0x800D7ED0: lwc1        $f8, 0x88($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X88);
    // 0x800D7ED4: swc1        $f6, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f6.u32l;
    // 0x800D7ED8: swc1        $f10, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f10.u32l;
    // 0x800D7EDC: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800D7EE0: mul.s       $f8, $f10, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x800D7EE4: swc1        $f4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f4.u32l;
    // 0x800D7EE8: mul.s       $f10, $f4, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x800D7EEC: swc1        $f6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f6.u32l;
    // 0x800D7EF0: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800D7EF4: mul.s       $f8, $f6, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x800D7EF8: jal         0x800D68E0
    // 0x800D7EFC: add.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_7;
    // 0x800D7EFC: add.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f8.fl;
    after_7:
    // 0x800D7F00: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D7F04: ldc1        $f10, -0x1F98($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X1F98);
    // 0x800D7F08: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
    // 0x800D7F0C: lw          $v0, 0xE0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XE0);
    // 0x800D7F10: c.lt.d      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.d < ctx->f2.d;
    // 0x800D7F14: lw          $v1, 0xE4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XE4);
    // 0x800D7F18: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x800D7F1C: sll         $t9, $v0, 1
    ctx->r25 = S32(ctx->r2 << 1);
    // 0x800D7F20: bc1f        L_800D8000
    if (!c1cs) {
        // 0x800D7F24: sll         $t3, $v1, 1
        ctx->r11 = S32(ctx->r3 << 1);
            goto L_800D8000;
    }
    // 0x800D7F24: sll         $t3, $v1, 1
    ctx->r11 = S32(ctx->r3 << 1);
    // 0x800D7F28: div.d       $f6, $f20, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = DIV_D(ctx->f20.d, ctx->f2.d);
    // 0x800D7F2C: lwc1        $f4, 0x5C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800D7F30: lwc1        $f8, 0x58($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800D7F34: lwc1        $f10, 0x54($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800D7F38: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800D7F3C: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x800D7F40: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x800D7F44: sll         $t0, $v1, 2
    ctx->r8 = S32(ctx->r3 << 2);
    // 0x800D7F48: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    // 0x800D7F4C: mul.s       $f14, $f4, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x800D7F50: nop

    // 0x800D7F54: mul.s       $f16, $f8, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x800D7F58: nop

    // 0x800D7F5C: mul.s       $f18, $f10, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x800D7F60: nop

    // 0x800D7F64: mul.s       $f6, $f14, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f22.fl);
    // 0x800D7F68: nop

    // 0x800D7F6C: mul.s       $f4, $f16, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f24.fl);
    // 0x800D7F70: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800D7F74: mul.s       $f10, $f18, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f26.fl);
    // 0x800D7F78: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800D7F7C: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800D7F80: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800D7F84: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800D7F88: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800D7F8C: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x800D7F90: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800D7F94: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800D7F98: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800D7F9C: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800D7FA0: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x800D7FA4: nop

    // 0x800D7FA8: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    // 0x800D7FAC: lwc1        $f10, 0xBC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x800D7FB0: lwc1        $f4, 0xC0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x800D7FB4: mul.s       $f6, $f14, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f10.fl);
    // 0x800D7FB8: nop

    // 0x800D7FBC: mul.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x800D7FC0: lwc1        $f4, 0xC4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x800D7FC4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800D7FC8: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800D7FCC: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x800D7FD0: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800D7FD4: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800D7FD8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800D7FDC: mul.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800D7FE0: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x800D7FE4: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800D7FE8: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800D7FEC: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800D7FF0: trunc.w.s   $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800D7FF4: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    // 0x800D7FF8: b           L_800D8008
    // 0x800D7FFC: sw          $t2, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r10;
        goto L_800D8008;
    // 0x800D7FFC: sw          $t2, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r10;
L_800D8000:
    // 0x800D8000: sw          $t9, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r25;
    // 0x800D8004: sw          $t3, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r11;
L_800D8008:
    // 0x800D8008: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x800D800C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800D8010: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x800D8014: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800D8018: addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // 0x800D801C: mul.s       $f12, $f22, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = MUL_S(ctx->f22.fl, ctx->f14.fl);
    // 0x800D8020: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x800D8024: nop

    // 0x800D8028: bc1fl       L_800D803C
    if (!c1cs) {
        // 0x800D802C: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_800D803C;
    }
    goto skip_1;
    // 0x800D802C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_1:
    // 0x800D8030: b           L_800D803C
    // 0x800D8034: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
        goto L_800D803C;
    // 0x800D8034: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x800D8038: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_800D803C:
    // 0x800D803C: mul.s       $f12, $f24, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = MUL_S(ctx->f24.fl, ctx->f14.fl);
    // 0x800D8040: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800D8044: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x800D8048: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x800D804C: bc1f        L_800D805C
    if (!c1cs) {
        // 0x800D8050: sb          $t6, 0x8($s0)
        MEM_B(0X8, ctx->r16) = ctx->r14;
            goto L_800D805C;
    }
    // 0x800D8050: sb          $t6, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r14;
    // 0x800D8054: b           L_800D8060
    // 0x800D8058: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
        goto L_800D8060;
    // 0x800D8058: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_800D805C:
    // 0x800D805C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_800D8060:
    // 0x800D8060: mul.s       $f12, $f26, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = MUL_S(ctx->f26.fl, ctx->f14.fl);
    // 0x800D8064: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800D8068: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x800D806C: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
    // 0x800D8070: bc1f        L_800D8080
    if (!c1cs) {
        // 0x800D8074: sb          $t0, 0x9($s0)
        MEM_B(0X9, ctx->r16) = ctx->r8;
            goto L_800D8080;
    }
    // 0x800D8074: sb          $t0, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r8;
    // 0x800D8078: b           L_800D8084
    // 0x800D807C: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
        goto L_800D8084;
    // 0x800D807C: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_800D8080:
    // 0x800D8080: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_800D8084:
    // 0x800D8084: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800D8088: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x800D808C: nop

    // 0x800D8090: sb          $t9, 0xA($s0)
    MEM_B(0XA, ctx->r16) = ctx->r25;
    // 0x800D8094: lwc1        $f10, 0xBC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x800D8098: mul.s       $f12, $f10, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x800D809C: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x800D80A0: nop

    // 0x800D80A4: bc1fl       L_800D80B8
    if (!c1cs) {
        // 0x800D80A8: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_800D80B8;
    }
    goto skip_2;
    // 0x800D80A8: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_2:
    // 0x800D80AC: b           L_800D80B8
    // 0x800D80B0: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
        goto L_800D80B8;
    // 0x800D80B0: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x800D80B4: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_800D80B8:
    // 0x800D80B8: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800D80BC: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x800D80C0: nop

    // 0x800D80C4: sb          $t4, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r12;
    // 0x800D80C8: lwc1        $f8, 0xC0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x800D80CC: mul.s       $f12, $f8, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x800D80D0: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x800D80D4: nop

    // 0x800D80D8: bc1fl       L_800D80EC
    if (!c1cs) {
        // 0x800D80DC: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_800D80EC;
    }
    goto skip_3;
    // 0x800D80DC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_3:
    // 0x800D80E0: b           L_800D80EC
    // 0x800D80E4: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
        goto L_800D80EC;
    // 0x800D80E4: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x800D80E8: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_800D80EC:
    // 0x800D80EC: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800D80F0: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x800D80F4: nop

    // 0x800D80F8: sb          $t8, 0x19($s0)
    MEM_B(0X19, ctx->r16) = ctx->r24;
    // 0x800D80FC: lwc1        $f10, 0xC4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x800D8100: mul.s       $f12, $f10, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x800D8104: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x800D8108: nop

    // 0x800D810C: bc1fl       L_800D8120
    if (!c1cs) {
        // 0x800D8110: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_800D8120;
    }
    goto skip_4;
    // 0x800D8110: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_4:
    // 0x800D8114: b           L_800D8120
    // 0x800D8118: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
        goto L_800D8120;
    // 0x800D8118: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x800D811C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_800D8120:
    // 0x800D8120: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800D8124: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // 0x800D8128: sb          $zero, 0x1($s0)
    MEM_B(0X1, ctx->r16) = 0;
    // 0x800D812C: sb          $zero, 0x2($s0)
    MEM_B(0X2, ctx->r16) = 0;
    // 0x800D8130: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x800D8134: sb          $zero, 0x3($s0)
    MEM_B(0X3, ctx->r16) = 0;
    // 0x800D8138: sb          $zero, 0x4($s0)
    MEM_B(0X4, ctx->r16) = 0;
    // 0x800D813C: sb          $zero, 0x5($s0)
    MEM_B(0X5, ctx->r16) = 0;
    // 0x800D8140: sb          $zero, 0x6($s0)
    MEM_B(0X6, ctx->r16) = 0;
    // 0x800D8144: sb          $zero, 0x7($s0)
    MEM_B(0X7, ctx->r16) = 0;
    // 0x800D8148: sb          $zero, 0x10($s0)
    MEM_B(0X10, ctx->r16) = 0;
    // 0x800D814C: sb          $v0, 0x11($s0)
    MEM_B(0X11, ctx->r16) = ctx->r2;
    // 0x800D8150: sb          $zero, 0x12($s0)
    MEM_B(0X12, ctx->r16) = 0;
    // 0x800D8154: sb          $zero, 0x13($s0)
    MEM_B(0X13, ctx->r16) = 0;
    // 0x800D8158: sb          $zero, 0x14($s0)
    MEM_B(0X14, ctx->r16) = 0;
    // 0x800D815C: sb          $v0, 0x15($s0)
    MEM_B(0X15, ctx->r16) = ctx->r2;
    // 0x800D8160: sb          $zero, 0x16($s0)
    MEM_B(0X16, ctx->r16) = 0;
    // 0x800D8164: sb          $zero, 0x17($s0)
    MEM_B(0X17, ctx->r16) = 0;
    // 0x800D8168: sb          $t2, 0x1A($s0)
    MEM_B(0X1A, ctx->r16) = ctx->r10;
    // 0x800D816C: swc1        $f22, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f22.u32l;
    // 0x800D8170: lwc1        $f18, 0xA4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x800D8174: lwc1        $f16, 0xA8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x800D8178: lwc1        $f14, 0xAC($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x800D817C: mul.s       $f8, $f18, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f22.fl);
    // 0x800D8180: lwc1        $f0, 0xBC($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x800D8184: lwc1        $f12, 0xC0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x800D8188: mul.s       $f4, $f16, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f24.fl);
    // 0x800D818C: lwc1        $f2, 0xC4($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x800D8190: swc1        $f24, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f24.u32l;
    // 0x800D8194: mul.s       $f6, $f14, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f26.fl);
    // 0x800D8198: swc1        $f26, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f26.u32l;
    // 0x800D819C: swc1        $f0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f0.u32l;
    // 0x800D81A0: swc1        $f12, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f12.u32l;
    // 0x800D81A4: swc1        $f2, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f2.u32l;
    // 0x800D81A8: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800D81AC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800D81B0: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800D81B4: mul.s       $f10, $f18, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800D81B8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800D81BC: mul.s       $f6, $f16, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x800D81C0: neg.s       $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = -ctx->f8.fl;
    // 0x800D81C4: swc1        $f4, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->f4.u32l;
    // 0x800D81C8: mul.s       $f4, $f14, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x800D81CC: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800D81D0: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800D81D4: mul.s       $f8, $f18, $f28
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f28.fl);
    // 0x800D81D8: neg.s       $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = -ctx->f10.fl;
    // 0x800D81DC: mul.s       $f4, $f16, $f30
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f30.fl);
    // 0x800D81E0: swc1        $f6, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->f6.u32l;
    // 0x800D81E4: lwc1        $f2, 0x88($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X88);
    // 0x800D81E8: swc1        $f28, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f28.u32l;
    // 0x800D81EC: swc1        $f30, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f30.u32l;
    // 0x800D81F0: mul.s       $f6, $f14, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x800D81F4: swc1        $f0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f0.u32l;
    // 0x800D81F8: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800D81FC: swc1        $f0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f0.u32l;
    // 0x800D8200: swc1        $f0, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->f0.u32l;
    // 0x800D8204: swc1        $f2, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->f2.u32l;
    // 0x800D8208: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800D820C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800D8210: neg.s       $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = -ctx->f8.fl;
    // 0x800D8214: swc1        $f10, 0x3C($s1)
    MEM_W(0X3C, ctx->r17) = ctx->f10.u32l;
    // 0x800D8218: swc1        $f4, 0x38($s1)
    MEM_W(0X38, ctx->r17) = ctx->f4.u32l;
    // 0x800D821C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x800D8220: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x800D8224: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x800D8228: ldc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X38);
    // 0x800D822C: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x800D8230: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x800D8234: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x800D8238: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x800D823C: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x800D8240: jr          $ra
    // 0x800D8244: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x800D8244: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void guLookAtHilite_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D8248: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x800D824C: lwc1        $f4, 0xA8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x800D8250: lwc1        $f6, 0xAC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x800D8254: lwc1        $f8, 0xB0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x800D8258: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800D825C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x800D8260: lwc1        $f6, 0xC4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x800D8264: lwc1        $f4, 0xC0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x800D8268: lwc1        $f10, 0xB4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x800D826C: lwc1        $f16, 0xB8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x800D8270: lwc1        $f18, 0xBC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x800D8274: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // 0x800D8278: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x800D827C: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x800D8280: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x800D8284: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x800D8288: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x800D828C: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    // 0x800D8290: lwc1        $f18, 0xD4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x800D8294: lwc1        $f16, 0xD0($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XD0);
    // 0x800D8298: lwc1        $f10, 0xCC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x800D829C: lwc1        $f4, 0xD8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x800D82A0: lwc1        $f6, 0xDC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x800D82A4: lwc1        $f8, 0xC8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x800D82A8: lw          $t6, 0xE0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XE0);
    // 0x800D82AC: lw          $t7, 0xE4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XE4);
    // 0x800D82B0: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x800D82B4: sw          $a0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r4;
    // 0x800D82B8: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x800D82BC: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x800D82C0: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    // 0x800D82C4: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    // 0x800D82C8: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    // 0x800D82CC: swc1        $f4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f4.u32l;
    // 0x800D82D0: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    // 0x800D82D4: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x800D82D8: sw          $t6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r14;
    // 0x800D82DC: jal         0x800D7B10
    // 0x800D82E0: sw          $t7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r15;
    guLookAtHiliteF_recomp(rdram, ctx);
        goto after_0;
    // 0x800D82E0: sw          $t7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r15;
    after_0:
    // 0x800D82E4: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x800D82E8: jal         0x800D6C20
    // 0x800D82EC: lw          $a1, 0x98($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X98);
    guMtxF2L_recomp(rdram, ctx);
        goto after_1;
    // 0x800D82EC: lw          $a1, 0x98($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X98);
    after_1:
    // 0x800D82F0: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x800D82F4: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    // 0x800D82F8: jr          $ra
    // 0x800D82FC: nop

    return;
    // 0x800D82FC: nop

;}
RECOMP_FUNC void guLookAtReflectF_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D8300: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800D8304: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800D8308: sdc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X38, ctx->r29);
    // 0x800D830C: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x800D8310: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x800D8314: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x800D8318: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x800D831C: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x800D8320: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x800D8324: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x800D8328: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x800D832C: jal         0x800D6D20
    // 0x800D8330: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    guMtxIdentF_recomp(rdram, ctx);
        goto after_0;
    // 0x800D8330: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800D8334: lwc1        $f4, 0x5C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800D8338: lwc1        $f6, 0x50($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800D833C: lwc1        $f8, 0x60($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800D8340: lwc1        $f10, 0x54($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800D8344: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800D8348: lwc1        $f6, 0x58($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800D834C: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800D8350: sub.s       $f22, $f8, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800D8354: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800D8358: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800D835C: sub.s       $f24, $f4, $f6
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f24.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800D8360: mul.s       $f10, $f22, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x800D8364: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800D8368: mul.s       $f6, $f24, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f24.fl, ctx->f24.fl);
    // 0x800D836C: jal         0x800D68E0
    // 0x800D8370: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x800D8370: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_1:
    // 0x800D8374: lui         $at, 0xBFF0
    ctx->r1 = S32(0XBFF0 << 16);
    // 0x800D8378: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800D837C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800D8380: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x800D8384: lwc1        $f6, 0x6C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800D8388: div.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = DIV_D(ctx->f8.d, ctx->f10.d);
    // 0x800D838C: lwc1        $f10, 0x70($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800D8390: cvt.s.d     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f2.fl = CVT_S_D(ctx->f4.d);
    // 0x800D8394: mul.s       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x800D8398: nop

    // 0x800D839C: mul.s       $f22, $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f22.fl = MUL_S(ctx->f22.fl, ctx->f2.fl);
    // 0x800D83A0: nop

    // 0x800D83A4: mul.s       $f24, $f24, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f24.fl = MUL_S(ctx->f24.fl, ctx->f2.fl);
    // 0x800D83A8: nop

    // 0x800D83AC: mul.s       $f8, $f6, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f24.fl);
    // 0x800D83B0: nop

    // 0x800D83B4: mul.s       $f4, $f10, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f22.fl);
    // 0x800D83B8: sub.s       $f26, $f8, $f4
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f26.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x800D83BC: mul.s       $f8, $f10, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x800D83C0: lwc1        $f4, 0x68($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800D83C4: mul.s       $f10, $f4, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f24.fl);
    // 0x800D83C8: sub.s       $f28, $f8, $f10
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f28.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800D83CC: mul.s       $f8, $f4, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x800D83D0: nop

    // 0x800D83D4: mul.s       $f10, $f6, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x800D83D8: sub.s       $f30, $f8, $f10
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f30.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800D83DC: mul.s       $f4, $f26, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f26.fl, ctx->f26.fl);
    // 0x800D83E0: nop

    // 0x800D83E4: mul.s       $f6, $f28, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f6.fl = MUL_S(ctx->f28.fl, ctx->f28.fl);
    // 0x800D83E8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800D83EC: mul.s       $f10, $f30, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = MUL_S(ctx->f30.fl, ctx->f30.fl);
    // 0x800D83F0: jal         0x800D68E0
    // 0x800D83F4: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_2;
    // 0x800D83F4: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_2:
    // 0x800D83F8: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800D83FC: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800D8400: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800D8404: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x800D8408: div.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = DIV_D(ctx->f4.d, ctx->f6.d);
    // 0x800D840C: cvt.s.d     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f2.fl = CVT_S_D(ctx->f8.d);
    // 0x800D8410: mul.s       $f26, $f26, $f2
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f26.fl = MUL_S(ctx->f26.fl, ctx->f2.fl);
    // 0x800D8414: nop

    // 0x800D8418: mul.s       $f28, $f28, $f2
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f28.fl = MUL_S(ctx->f28.fl, ctx->f2.fl);
    // 0x800D841C: nop

    // 0x800D8420: mul.s       $f30, $f30, $f2
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f30.fl = MUL_S(ctx->f30.fl, ctx->f2.fl);
    // 0x800D8424: nop

    // 0x800D8428: mul.s       $f10, $f22, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f30.fl);
    // 0x800D842C: nop

    // 0x800D8430: mul.s       $f4, $f24, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = MUL_S(ctx->f24.fl, ctx->f28.fl);
    // 0x800D8434: nop

    // 0x800D8438: mul.s       $f6, $f24, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = MUL_S(ctx->f24.fl, ctx->f26.fl);
    // 0x800D843C: nop

    // 0x800D8440: mul.s       $f8, $f20, $f30
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f30.fl);
    // 0x800D8444: sub.s       $f14, $f10, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x800D8448: mul.s       $f10, $f20, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f28.fl);
    // 0x800D844C: nop

    // 0x800D8450: mul.s       $f4, $f22, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f26.fl);
    // 0x800D8454: swc1        $f14, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f14.u32l;
    // 0x800D8458: sub.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800D845C: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800D8460: nop

    // 0x800D8464: mul.s       $f8, $f16, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x800D8468: swc1        $f16, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f16.u32l;
    // 0x800D846C: sub.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x800D8470: mul.s       $f4, $f18, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x800D8474: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800D8478: swc1        $f18, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f18.u32l;
    // 0x800D847C: jal         0x800D68E0
    // 0x800D8480: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_3;
    // 0x800D8480: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    after_3:
    // 0x800D8484: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x800D8488: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800D848C: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x800D8490: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800D8494: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800D8498: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800D849C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800D84A0: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x800D84A4: lwc1        $f4, 0x68($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800D84A8: div.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = DIV_D(ctx->f6.d, ctx->f8.d);
    // 0x800D84AC: lwc1        $f8, 0x6C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800D84B0: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x800D84B4: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x800D84B8: addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // 0x800D84BC: cvt.s.d     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f2.fl = CVT_S_D(ctx->f10.d);
    // 0x800D84C0: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800D84C4: lwc1        $f4, 0x70($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800D84C8: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800D84CC: swc1        $f6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f6.u32l;
    // 0x800D84D0: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800D84D4: swc1        $f10, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f10.u32l;
    // 0x800D84D8: mul.s       $f14, $f26, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = MUL_S(ctx->f26.fl, ctx->f16.fl);
    // 0x800D84DC: swc1        $f6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f6.u32l;
    // 0x800D84E0: mul.s       $f2, $f28, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f28.fl, ctx->f16.fl);
    // 0x800D84E4: c.lt.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl < ctx->f12.fl;
    // 0x800D84E8: nop

    // 0x800D84EC: bc1fl       L_800D8500
    if (!c1cs) {
        // 0x800D84F0: mov.s       $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
            goto L_800D8500;
    }
    goto skip_0;
    // 0x800D84F0: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    skip_0:
    // 0x800D84F4: b           L_800D8500
    // 0x800D84F8: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
        goto L_800D8500;
    // 0x800D84F8: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
    // 0x800D84FC: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_800D8500:
    // 0x800D8500: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800D8504: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x800D8508: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x800D850C: bc1f        L_800D851C
    if (!c1cs) {
        // 0x800D8510: sb          $t8, 0x8($a1)
        MEM_B(0X8, ctx->r5) = ctx->r24;
            goto L_800D851C;
    }
    // 0x800D8510: sb          $t8, 0x8($a1)
    MEM_B(0X8, ctx->r5) = ctx->r24;
    // 0x800D8514: b           L_800D8520
    // 0x800D8518: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_800D8520;
    // 0x800D8518: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_800D851C:
    // 0x800D851C: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_800D8520:
    // 0x800D8520: mul.s       $f2, $f30, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f30.fl, ctx->f16.fl);
    // 0x800D8524: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800D8528: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x800D852C: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x800D8530: bc1f        L_800D8540
    if (!c1cs) {
        // 0x800D8534: sb          $t1, 0x9($a1)
        MEM_B(0X9, ctx->r5) = ctx->r9;
            goto L_800D8540;
    }
    // 0x800D8534: sb          $t1, 0x9($a1)
    MEM_B(0X9, ctx->r5) = ctx->r9;
    // 0x800D8538: b           L_800D8544
    // 0x800D853C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_800D8544;
    // 0x800D853C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_800D8540:
    // 0x800D8540: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_800D8544:
    // 0x800D8544: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800D8548: mfc1        $t4, $f4
    ctx->r12 = (int32_t)ctx->f4.u32l;
    // 0x800D854C: nop

    // 0x800D8550: sb          $t4, 0xA($a1)
    MEM_B(0XA, ctx->r5) = ctx->r12;
    // 0x800D8554: lwc1        $f6, 0x68($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800D8558: mul.s       $f2, $f6, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x800D855C: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x800D8560: nop

    // 0x800D8564: bc1fl       L_800D8578
    if (!c1cs) {
        // 0x800D8568: mov.s       $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
            goto L_800D8578;
    }
    goto skip_1;
    // 0x800D8568: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    skip_1:
    // 0x800D856C: b           L_800D8578
    // 0x800D8570: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_800D8578;
    // 0x800D8570: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x800D8574: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_800D8578:
    // 0x800D8578: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800D857C: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x800D8580: nop

    // 0x800D8584: sb          $t7, 0x18($a1)
    MEM_B(0X18, ctx->r5) = ctx->r15;
    // 0x800D8588: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800D858C: mul.s       $f2, $f10, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800D8590: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x800D8594: nop

    // 0x800D8598: bc1fl       L_800D85AC
    if (!c1cs) {
        // 0x800D859C: mov.s       $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
            goto L_800D85AC;
    }
    goto skip_2;
    // 0x800D859C: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    skip_2:
    // 0x800D85A0: b           L_800D85AC
    // 0x800D85A4: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_800D85AC;
    // 0x800D85A4: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x800D85A8: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_800D85AC:
    // 0x800D85AC: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800D85B0: mfc1        $t0, $f4
    ctx->r8 = (int32_t)ctx->f4.u32l;
    // 0x800D85B4: nop

    // 0x800D85B8: sb          $t0, 0x19($a1)
    MEM_B(0X19, ctx->r5) = ctx->r8;
    // 0x800D85BC: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800D85C0: mul.s       $f2, $f6, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x800D85C4: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x800D85C8: nop

    // 0x800D85CC: bc1fl       L_800D85E0
    if (!c1cs) {
        // 0x800D85D0: mov.s       $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
            goto L_800D85E0;
    }
    goto skip_3;
    // 0x800D85D0: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    skip_3:
    // 0x800D85D4: b           L_800D85E0
    // 0x800D85D8: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_800D85E0;
    // 0x800D85D8: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x800D85DC: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_800D85E0:
    // 0x800D85E0: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800D85E4: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
    // 0x800D85E8: sb          $zero, 0x1($a1)
    MEM_B(0X1, ctx->r5) = 0;
    // 0x800D85EC: sb          $zero, 0x2($a1)
    MEM_B(0X2, ctx->r5) = 0;
    // 0x800D85F0: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
    // 0x800D85F4: sb          $zero, 0x3($a1)
    MEM_B(0X3, ctx->r5) = 0;
    // 0x800D85F8: sb          $zero, 0x4($a1)
    MEM_B(0X4, ctx->r5) = 0;
    // 0x800D85FC: sb          $zero, 0x5($a1)
    MEM_B(0X5, ctx->r5) = 0;
    // 0x800D8600: sb          $zero, 0x6($a1)
    MEM_B(0X6, ctx->r5) = 0;
    // 0x800D8604: sb          $zero, 0x7($a1)
    MEM_B(0X7, ctx->r5) = 0;
    // 0x800D8608: sb          $zero, 0x10($a1)
    MEM_B(0X10, ctx->r5) = 0;
    // 0x800D860C: sb          $v0, 0x11($a1)
    MEM_B(0X11, ctx->r5) = ctx->r2;
    // 0x800D8610: sb          $zero, 0x12($a1)
    MEM_B(0X12, ctx->r5) = 0;
    // 0x800D8614: sb          $zero, 0x13($a1)
    MEM_B(0X13, ctx->r5) = 0;
    // 0x800D8618: sb          $zero, 0x14($a1)
    MEM_B(0X14, ctx->r5) = 0;
    // 0x800D861C: sb          $v0, 0x15($a1)
    MEM_B(0X15, ctx->r5) = ctx->r2;
    // 0x800D8620: sb          $zero, 0x16($a1)
    MEM_B(0X16, ctx->r5) = 0;
    // 0x800D8624: sb          $zero, 0x17($a1)
    MEM_B(0X17, ctx->r5) = 0;
    // 0x800D8628: sb          $t3, 0x1A($a1)
    MEM_B(0X1A, ctx->r5) = ctx->r11;
    // 0x800D862C: swc1        $f26, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f26.u32l;
    // 0x800D8630: lwc1        $f18, 0x50($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800D8634: lwc1        $f16, 0x54($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800D8638: lwc1        $f14, 0x58($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800D863C: mul.s       $f10, $f18, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f26.fl);
    // 0x800D8640: lwc1        $f0, 0x68($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800D8644: lwc1        $f12, 0x6C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800D8648: mul.s       $f4, $f16, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f28.fl);
    // 0x800D864C: lwc1        $f2, 0x70($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800D8650: swc1        $f28, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f28.u32l;
    // 0x800D8654: mul.s       $f8, $f14, $f30
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f30.fl);
    // 0x800D8658: swc1        $f30, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f30.u32l;
    // 0x800D865C: swc1        $f20, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f20.u32l;
    // 0x800D8660: swc1        $f22, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f22.u32l;
    // 0x800D8664: swc1        $f24, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f24.u32l;
    // 0x800D8668: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800D866C: swc1        $f0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f0.u32l;
    // 0x800D8670: swc1        $f12, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f12.u32l;
    // 0x800D8674: swc1        $f2, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f2.u32l;
    // 0x800D8678: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800D867C: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800D8680: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800D8684: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800D8688: mul.s       $f8, $f16, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x800D868C: neg.s       $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = -ctx->f10.fl;
    // 0x800D8690: swc1        $f4, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f4.u32l;
    // 0x800D8694: mul.s       $f4, $f14, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x800D8698: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800D869C: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800D86A0: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x800D86A4: swc1        $f8, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f8.u32l;
    // 0x800D86A8: lwc1        $f10, 0x50($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800D86AC: lwc1        $f6, 0x54($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800D86B0: mul.s       $f4, $f10, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x800D86B4: nop

    // 0x800D86B8: mul.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x800D86BC: lwc1        $f6, 0x58($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800D86C0: swc1        $f0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f0.u32l;
    // 0x800D86C4: swc1        $f0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f0.u32l;
    // 0x800D86C8: swc1        $f0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f0.u32l;
    // 0x800D86CC: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800D86D0: mul.s       $f4, $f6, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f24.fl);
    // 0x800D86D4: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800D86D8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800D86DC: neg.s       $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = -ctx->f8.fl;
    // 0x800D86E0: swc1        $f10, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f10.u32l;
    // 0x800D86E4: swc1        $f6, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f6.u32l;
    // 0x800D86E8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800D86EC: ldc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X38);
    // 0x800D86F0: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x800D86F4: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x800D86F8: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x800D86FC: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x800D8700: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x800D8704: jr          $ra
    // 0x800D8708: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800D8708: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void guLookAtReflect_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D870C: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x800D8710: lwc1        $f4, 0x88($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X88);
    // 0x800D8714: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x800D8718: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x800D871C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800D8720: lwc1        $f4, 0xA0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x800D8724: lwc1        $f6, 0x8C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x800D8728: lwc1        $f8, 0x90($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X90);
    // 0x800D872C: lwc1        $f10, 0x94($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X94);
    // 0x800D8730: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
    // 0x800D8734: lwc1        $f18, 0x9C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800D8738: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800D873C: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    // 0x800D8740: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x800D8744: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x800D8748: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x800D874C: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x800D8750: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x800D8754: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x800D8758: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x800D875C: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x800D8760: jal         0x800D8300
    // 0x800D8764: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    guLookAtReflectF_recomp(rdram, ctx);
        goto after_0;
    // 0x800D8764: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x800D8768: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x800D876C: jal         0x800D6C20
    // 0x800D8770: lw          $a1, 0x78($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X78);
    guMtxF2L_recomp(rdram, ctx);
        goto after_1;
    // 0x800D8770: lw          $a1, 0x78($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X78);
    after_1:
    // 0x800D8774: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800D8778: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x800D877C: jr          $ra
    // 0x800D8780: nop

    return;
    // 0x800D8780: nop

    // 0x800D8784: nop

    // 0x800D8788: nop

    // 0x800D878C: nop

;}
RECOMP_FUNC void guRandom_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D8790: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800D8794: lw          $a0, -0x3220($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3220);
    // 0x800D8798: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D879C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800D87A0: addiu       $t7, $t6, 0x2
    ctx->r15 = ADD32(ctx->r14, 0X2);
    // 0x800D87A4: addiu       $t8, $t6, 0x3
    ctx->r24 = ADD32(ctx->r14, 0X3);
    // 0x800D87A8: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D87AC: mflo        $a1
    ctx->r5 = lo;
    // 0x800D87B0: srl         $v0, $a1, 2
    ctx->r2 = S32(U32(ctx->r5) >> 2);
    // 0x800D87B4: jr          $ra
    // 0x800D87B8: sw          $v0, -0x3220($at)
    MEM_W(-0X3220, ctx->r1) = ctx->r2;
    return;
    // 0x800D87B8: sw          $v0, -0x3220($at)
    MEM_W(-0X3220, ctx->r1) = ctx->r2;
    // 0x800D87BC: nop

;}
RECOMP_FUNC void func_800D87C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D87C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D87C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D87C8: jal         0x800DD750
    // 0x800D87CC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    memcpy_recomp(rdram, ctx);
        goto after_0;
    // 0x800D87CC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x800D87D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D87D4: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800D87D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D87DC: jr          $ra
    // 0x800D87E0: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    return;
    // 0x800D87E0: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
;}
RECOMP_FUNC void sprintf_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D87E4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800D87E8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800D87EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D87F0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800D87F4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800D87F8: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800D87FC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800D8800: addiu       $a0, $a0, -0x7840
    ctx->r4 = ADD32(ctx->r4, -0X7840);
    // 0x800D8804: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    // 0x800D8808: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x800D880C: jal         0x800DD100
    // 0x800D8810: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    _Printf_recomp(rdram, ctx);
        goto after_0;
    // 0x800D8810: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_0:
    // 0x800D8814: bltz        $v0, L_800D8828
    if (SIGNED(ctx->r2) < 0) {
        // 0x800D8818: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800D8828;
    }
    // 0x800D8818: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800D881C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800D8820: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800D8824: sb          $zero, 0x0($t7)
    MEM_B(0X0, ctx->r15) = 0;
L_800D8828:
    // 0x800D8828: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D882C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800D8830: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800D8834: jr          $ra
    // 0x800D8838: nop

    return;
    // 0x800D8838: nop

    // 0x800D883C: nop

;}
RECOMP_FUNC void alUnlink_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D8840: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800D8844: beql        $v0, $zero, L_800D8858
    if (ctx->r2 == 0) {
        // 0x800D8848: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_800D8858;
    }
    goto skip_0;
    // 0x800D8848: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_0:
    // 0x800D884C: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x800D8850: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800D8854: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
L_800D8858:
    // 0x800D8858: beq         $v0, $zero, L_800D8868
    if (ctx->r2 == 0) {
        // 0x800D885C: nop
    
            goto L_800D8868;
    }
    // 0x800D885C: nop

    // 0x800D8860: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x800D8864: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
L_800D8868:
    // 0x800D8868: jr          $ra
    // 0x800D886C: nop

    return;
    // 0x800D886C: nop

;}
RECOMP_FUNC void alLink_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D8870: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800D8874: sw          $a1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r5;
    // 0x800D8878: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800D887C: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800D8880: beq         $v0, $zero, L_800D888C
    if (ctx->r2 == 0) {
        // 0x800D8884: nop
    
            goto L_800D888C;
    }
    // 0x800D8884: nop

    // 0x800D8888: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
L_800D888C:
    // 0x800D888C: jr          $ra
    // 0x800D8890: sw          $a0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r4;
    return;
    // 0x800D8890: sw          $a0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r4;
;}
RECOMP_FUNC void alClose_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D8894: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x800D8898: lw          $t6, -0x3210($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X3210);
    // 0x800D889C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D88A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D88A4: beql        $t6, $zero, L_800D88C0
    if (ctx->r14 == 0) {
        // 0x800D88A8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D88C0;
    }
    goto skip_0;
    // 0x800D88A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800D88AC: jal         0x800DD7F0
    // 0x800D88B0: nop

    alSynDelete_recomp(rdram, ctx);
        goto after_0;
    // 0x800D88B0: nop

    after_0:
    // 0x800D88B4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D88B8: sw          $zero, -0x3210($at)
    MEM_W(-0X3210, ctx->r1) = 0;
    // 0x800D88BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D88C0:
    // 0x800D88C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D88C4: jr          $ra
    // 0x800D88C8: nop

    return;
    // 0x800D88C8: nop

;}
RECOMP_FUNC void alInit_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D88CC: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x800D88D0: addiu       $v0, $v0, -0x3210
    ctx->r2 = ADD32(ctx->r2, -0X3210);
    // 0x800D88D4: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800D88D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D88DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D88E0: bnel        $t6, $zero, L_800D88F4
    if (ctx->r14 != 0) {
        // 0x800D88E4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D88F4;
    }
    goto skip_0;
    // 0x800D88E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800D88E8: jal         0x800D92F0
    // 0x800D88EC: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    alSynNew_recomp(rdram, ctx);
        goto after_0;
    // 0x800D88EC: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    after_0:
    // 0x800D88F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D88F4:
    // 0x800D88F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D88F8: jr          $ra
    // 0x800D88FC: nop

    return;
    // 0x800D88FC: nop

;}
RECOMP_FUNC void alHeapDBAlloc_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D8AE0: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x800D8AE4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800D8AE8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800D8AEC: multu       $a3, $t6
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D8AF0: lw          $t9, 0x8($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X8);
    // 0x800D8AF4: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800D8AF8: lw          $a0, 0x4($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X4);
    // 0x800D8AFC: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x800D8B00: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800D8B04: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800D8B08: mflo        $v0
    ctx->r2 = lo;
    // 0x800D8B0C: addiu       $v0, $v0, 0xF
    ctx->r2 = ADD32(ctx->r2, 0XF);
    // 0x800D8B10: and         $t7, $v0, $at
    ctx->r15 = ctx->r2 & ctx->r1;
    // 0x800D8B14: addu        $t1, $a0, $t7
    ctx->r9 = ADD32(ctx->r4, ctx->r15);
    // 0x800D8B18: sltu        $at, $t0, $t1
    ctx->r1 = ctx->r8 < ctx->r9 ? 1 : 0;
    // 0x800D8B1C: bne         $at, $zero, L_800D8B2C
    if (ctx->r1 != 0) {
        // 0x800D8B20: addu        $t2, $a0, $t7
        ctx->r10 = ADD32(ctx->r4, ctx->r15);
            goto L_800D8B2C;
    }
    // 0x800D8B20: addu        $t2, $a0, $t7
    ctx->r10 = ADD32(ctx->r4, ctx->r15);
    // 0x800D8B24: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800D8B28: sw          $t2, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r10;
L_800D8B2C:
    // 0x800D8B2C: jr          $ra
    // 0x800D8B30: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800D8B30: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800D8B34: nop

    // 0x800D8B38: nop

    // 0x800D8B3C: nop

;}
RECOMP_FUNC void alHeapInit_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D8B40: addiu       $v1, $zero, 0x10
    ctx->r3 = ADD32(0, 0X10);
    // 0x800D8B44: andi        $t6, $a1, 0xF
    ctx->r14 = ctx->r5 & 0XF;
    // 0x800D8B48: subu        $v0, $v1, $t6
    ctx->r2 = SUB32(ctx->r3, ctx->r14);
    // 0x800D8B4C: beq         $v1, $v0, L_800D8B5C
    if (ctx->r3 == ctx->r2) {
        // 0x800D8B50: addu        $t7, $a1, $v0
        ctx->r15 = ADD32(ctx->r5, ctx->r2);
            goto L_800D8B5C;
    }
    // 0x800D8B50: addu        $t7, $a1, $v0
    ctx->r15 = ADD32(ctx->r5, ctx->r2);
    // 0x800D8B54: b           L_800D8B60
    // 0x800D8B58: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
        goto L_800D8B60;
    // 0x800D8B58: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
L_800D8B5C:
    // 0x800D8B5C: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
L_800D8B60:
    // 0x800D8B60: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x800D8B64: sw          $a2, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r6;
    // 0x800D8B68: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x800D8B6C: jr          $ra
    // 0x800D8B70: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    return;
    // 0x800D8B70: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x800D8B74: nop

    // 0x800D8B78: nop

    // 0x800D8B7C: nop

;}
RECOMP_FUNC void func_800D8F10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D8F10: jr          $ra
    // 0x800D8F14: nop

    return;
    // 0x800D8F14: nop

;}
RECOMP_FUNC void _timeToSamples_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D8F18: lw          $t6, 0x44($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X44);
    // 0x800D8F1C: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x800D8F20: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D8F24: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x800D8F28: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800D8F2C: ldc1        $f4, -0x1F90($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X1F90);
    // 0x800D8F30: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800D8F34: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800D8F38: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x800D8F3C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800D8F40: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800D8F44: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800D8F48: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x800D8F4C: div.d       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = DIV_D(ctx->f18.d, ctx->f4.d);
    // 0x800D8F50: add.d       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f8.d + ctx->f6.d;
    // 0x800D8F54: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    // 0x800D8F58: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800D8F5C: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x800D8F60: nop

    // 0x800D8F64: and         $t8, $v0, $at
    ctx->r24 = ctx->r2 & ctx->r1;
    // 0x800D8F68: jr          $ra
    // 0x800D8F6C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    return;
    // 0x800D8F6C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
;}
RECOMP_FUNC void _freePVoice_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D8F70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D8F74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D8F78: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800D8F7C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800D8F80: jal         0x800D8840
    // 0x800D8F84: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    alUnlink_recomp(rdram, ctx);
        goto after_0;
    // 0x800D8F84: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x800D8F88: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800D8F8C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800D8F90: jal         0x800D8870
    // 0x800D8F94: addiu       $a1, $a1, 0x14
    ctx->r5 = ADD32(ctx->r5, 0X14);
    alLink_recomp(rdram, ctx);
        goto after_1;
    // 0x800D8F94: addiu       $a1, $a1, 0x14
    ctx->r5 = ADD32(ctx->r5, 0X14);
    after_1:
    // 0x800D8F98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D8F9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D8FA0: jr          $ra
    // 0x800D8FA4: nop

    return;
    // 0x800D8FA4: nop

;}
