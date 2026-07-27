#include "recomp.h"
#ifdef __cplusplus
extern "C" {
#endif
extern void load_overlays(uint32_t rom, int32_t ram_addr, uint32_t size);
extern void unload_overlays(int32_t ram_addr, uint32_t size);
#ifdef __cplusplus
}
#endif
#include "funcs.h"

RECOMP_FUNC void recomp_entrypoint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2400: lui         $t0, 0x800F
    ctx->r8 = S32(0X800F << 16);
    // 0x800C2404: lui         $t1, 0x7
    ctx->r9 = S32(0X7 << 16);
    // 0x800C2408: addiu       $t0, $t0, -0x10B0
    ctx->r8 = ADD32(ctx->r8, -0X10B0);
    // 0x800C240C: ori         $t1, $t1, 0xBCA0
    ctx->r9 = ctx->r9 | 0XBCA0;
L_800C2410:
    // 0x800C2410: addi        $t1, $t1, -0x8
    ctx->r9 = ADD32(ctx->r9, -0X8);
    // 0x800C2414: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x800C2418: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x800C241C: bne         $t1, $zero, L_800C2410
    if (ctx->r9 != 0) {
        // 0x800C2420: addi        $t0, $t0, 0x8
        ctx->r8 = ADD32(ctx->r8, 0X8);
            goto L_800C2410;
    }
    // 0x800C2420: addi        $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x800C2424: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x800C2428: lui         $sp, 0x8012
    ctx->r29 = S32(0X8012 << 16);
    // 0x800C242C: addiu       $t2, $t2, -0x2950
    ctx->r10 = ADD32(ctx->r10, -0X2950);
    // 0x800C2430: jr          $t2
    // 0x800C2434: addiu       $sp, $sp, 0x6A60
    ctx->r29 = ADD32(ctx->r29, 0X6A60);
    LOOKUP_FUNC(ctx->r10)(rdram, ctx);
    return;
    // 0x800C2434: addiu       $sp, $sp, 0x6A60
    ctx->r29 = ADD32(ctx->r29, 0X6A60);
    // 0x800C2438: nop

    // 0x800C243C: nop

    // 0x800C2440: nop

    // 0x800C2444: nop

    // 0x800C2448: nop

    // 0x800C244C: nop

;}
RECOMP_FUNC void func_800C2450(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2450: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C2454: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C2458: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C245C: jal         0x800D1390
    // 0x800C2460: sh          $zero, -0x4530($at)
    MEM_H(-0X4530, ctx->r1) = 0;
    func_800D1390(rdram, ctx);
        goto after_0;
    // 0x800C2460: sh          $zero, -0x4530($at)
    MEM_H(-0X4530, ctx->r1) = 0;
    after_0:
    // 0x800C2464: jal         0x800D15D0
    // 0x800C2468: nop

    func_800D15D0(rdram, ctx);
        goto after_1;
    // 0x800C2468: nop

    after_1:
    // 0x800C246C: andi        $t6, $v0, 0xF
    ctx->r14 = ctx->r2 & 0XF;
    // 0x800C2470: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C2474: jal         0x800C31D4
    // 0x800C2478: sh          $t6, -0x4530($at)
    MEM_H(-0X4530, ctx->r1) = ctx->r14;
    func_800C31D4(rdram, ctx);
        goto after_2;
    // 0x800C2478: sh          $t6, -0x4530($at)
    MEM_H(-0X4530, ctx->r1) = ctx->r14;
    after_2:
    // 0x800C247C: jal         0x800CB2F4
    // 0x800C2480: nop

    func_800CB2F4(rdram, ctx);
        goto after_3;
    // 0x800C2480: nop

    after_3:
    // 0x800C2484: jal         0x800CBA00
    // 0x800C2488: nop

    func_800CBA00(rdram, ctx);
        goto after_4;
    // 0x800C2488: nop

    after_4:
    // 0x800C248C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C2490: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C2494: jr          $ra
    // 0x800C2498: nop

    return;
    // 0x800C2498: nop

;}
RECOMP_FUNC void func_800C249C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C249C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C24A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C24A4: jal         0x800D1610
    // 0x800C24A8: nop

    func_800D1610(rdram, ctx);
        goto after_0;
    // 0x800C24A8: nop

    after_0:
    // 0x800C24AC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C24B0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800C24B4: jal         0x800D3A80
    // 0x800C24B8: nop

    osViSetYScale_recomp(rdram, ctx);
        goto after_1;
    // 0x800C24B8: nop

    after_1:
    // 0x800C24BC: jal         0x800D1640
    // 0x800C24C0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800D1640(rdram, ctx);
        goto after_2;
    // 0x800C24C0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x800C24C4: jal         0x800D1680
    // 0x800C24C8: nop

    func_800D1680(rdram, ctx);
        goto after_3;
    // 0x800C24C8: nop

    after_3:
L_800C24CC:
    // 0x800C24CC: b           L_800C24CC
    pause_self(rdram);
    // 0x800C24D0: nop

    // 0x800C24D4: nop

    // 0x800C24D8: nop

    // 0x800C24DC: nop

    // 0x800C24E0: nop

    // 0x800C24E4: nop

    // 0x800C24E8: nop

    // 0x800C24EC: nop

    // 0x800C24F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C24F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C24F8: jr          $ra
    // 0x800C24FC: nop

    return;
    // 0x800C24FC: nop

;}
RECOMP_FUNC void func_800C2500(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2500: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C2504: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C2508: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x800C250C: jal         0x800D16F0
    // 0x800C2510: addiu       $a0, $a0, 0x249C
    ctx->r4 = ADD32(ctx->r4, 0X249C);
    func_800D16F0(rdram, ctx);
        goto after_0;
    // 0x800C2510: addiu       $a0, $a0, 0x249C
    ctx->r4 = ADD32(ctx->r4, 0X249C);
    after_0:
    // 0x800C2514: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C2518: sb          $zero, -0x452E($at)
    MEM_B(-0X452E, ctx->r1) = 0;
    // 0x800C251C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C2520: addiu       $t6, $zero, 0x140
    ctx->r14 = ADD32(0, 0X140);
    // 0x800C2524: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x800C2528: lhu         $t8, -0x4530($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X4530);
    // 0x800C252C: sw          $t6, -0x4520($at)
    MEM_W(-0X4520, ctx->r1) = ctx->r14;
    // 0x800C2530: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C2534: addiu       $t7, $zero, 0xF0
    ctx->r15 = ADD32(0, 0XF0);
    // 0x800C2538: sw          $t7, -0x451C($at)
    MEM_W(-0X451C, ctx->r1) = ctx->r15;
    // 0x800C253C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C2540: andi        $t9, $t8, 0xF
    ctx->r25 = ctx->r24 & 0XF;
    // 0x800C2544: sh          $t9, -0x4530($at)
    MEM_H(-0X4530, ctx->r1) = ctx->r25;
    // 0x800C2548: jal         0x800C36C8
    // 0x800C254C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800C36C8(rdram, ctx);
        goto after_1;
    // 0x800C254C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x800C2550: jal         0x800C3C20
    // 0x800C2554: nop

    func_800C3C20(rdram, ctx);
        goto after_2;
    // 0x800C2554: nop

    after_2:
    // 0x800C2558: jal         0x800C4658
    // 0x800C255C: nop

    func_800C4658(rdram, ctx);
        goto after_3;
    // 0x800C255C: nop

    after_3:
    // 0x800C2560: jal         0x800C7154
    // 0x800C2564: nop

    func_800C7154(rdram, ctx);
        goto after_4;
    // 0x800C2564: nop

    after_4:
    // 0x800C2568: jal         0x800C6DD4
    // 0x800C256C: nop

    func_800C6DD4(rdram, ctx);
        goto after_5;
    // 0x800C256C: nop

    after_5:
    // 0x800C2570: jal         0x800C7378
    // 0x800C2574: nop

    func_800C7378(rdram, ctx);
        goto after_6;
    // 0x800C2574: nop

    after_6:
    // 0x800C2578: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800C257C: jal         0x800C3930
    // 0x800C2580: addiu       $a0, $a0, -0x7A00
    ctx->r4 = ADD32(ctx->r4, -0X7A00);
    func_800C3930(rdram, ctx);
        goto after_7;
    // 0x800C2580: addiu       $a0, $a0, -0x7A00
    ctx->r4 = ADD32(ctx->r4, -0X7A00);
    after_7:
    // 0x800C2584: jal         0x800C3FD0
    // 0x800C2588: nop

    func_800C3FD0(rdram, ctx);
        goto after_8;
    // 0x800C2588: nop

    after_8:
    // 0x800C258C: jal         0x800D1680
    // 0x800C2590: nop

    func_800D1680(rdram, ctx);
        goto after_9;
    // 0x800C2590: nop

    after_9:
    // 0x800C2594: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C2598: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C259C: jr          $ra
    // 0x800C25A0: nop

    return;
    // 0x800C25A0: nop

;}
RECOMP_FUNC void func_800C25A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C25A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C25A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C25AC: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C25B0: sb          $zero, -0x452E($at)
    MEM_B(-0X452E, ctx->r1) = 0;
    // 0x800C25B4: jal         0x800C36C8
    // 0x800C25B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800C36C8(rdram, ctx);
        goto after_0;
    // 0x800C25B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x800C25BC: jal         0x800C3C20
    // 0x800C25C0: nop

    func_800C3C20(rdram, ctx);
        goto after_1;
    // 0x800C25C0: nop

    after_1:
    // 0x800C25C4: jal         0x800C4658
    // 0x800C25C8: nop

    func_800C4658(rdram, ctx);
        goto after_2;
    // 0x800C25C8: nop

    after_2:
    // 0x800C25CC: jal         0x800C7154
    // 0x800C25D0: nop

    func_800C7154(rdram, ctx);
        goto after_3;
    // 0x800C25D0: nop

    after_3:
    // 0x800C25D4: jal         0x800C6DD4
    // 0x800C25D8: nop

    func_800C6DD4(rdram, ctx);
        goto after_4;
    // 0x800C25D8: nop

    after_4:
    // 0x800C25DC: jal         0x800C3FD0
    // 0x800C25E0: nop

    func_800C3FD0(rdram, ctx);
        goto after_5;
    // 0x800C25E0: nop

    after_5:
    // 0x800C25E4: jal         0x800D1680
    // 0x800C25E8: nop

    func_800D1680(rdram, ctx);
        goto after_6;
    // 0x800C25E8: nop

    after_6:
    // 0x800C25EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C25F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C25F4: jr          $ra
    // 0x800C25F8: nop

    return;
    // 0x800C25F8: nop

;}
RECOMP_FUNC void func_800C25FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C25FC: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x800C2600: lhu         $t6, -0x4530($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X4530);
    // 0x800C2604: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800C2608: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C260C: andi        $t7, $t6, 0x1000
    ctx->r15 = ctx->r14 & 0X1000;
    // 0x800C2610: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800C2614: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800C2618: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800C261C: beq         $t7, $zero, L_800C26CC
    if (ctx->r15 == 0) {
        // 0x800C2620: sw          $a3, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r7;
            goto L_800C26CC;
    }
    // 0x800C2620: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x800C2624: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x800C2628: lw          $t8, -0x4514($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4514);
    // 0x800C262C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C2630: lui         $t0, 0xDE00
    ctx->r8 = S32(0XDE00 << 16);
    // 0x800C2634: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x800C2638: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800C263C: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x800C2640: sw          $t9, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r25;
    // 0x800C2644: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x800C2648: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x800C264C: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x800C2650: addiu       $t2, $t2, -0x53D8
    ctx->r10 = ADD32(ctx->r10, -0X53D8);
    // 0x800C2654: lui         $t4, 0x8011
    ctx->r12 = S32(0X8011 << 16);
    // 0x800C2658: sw          $t2, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r10;
    // 0x800C265C: lw          $t4, -0x4514($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4514);
    // 0x800C2660: lui         $t6, 0xDE00
    ctx->r14 = S32(0XDE00 << 16);
    // 0x800C2664: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x800C2668: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x800C266C: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800C2670: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x800C2674: sw          $t5, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r13;
    // 0x800C2678: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x800C267C: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800C2680: addiu       $t8, $t8, -0x53A0
    ctx->r24 = ADD32(ctx->r24, -0X53A0);
    // 0x800C2684: lui         $t0, 0x8011
    ctx->r8 = S32(0X8011 << 16);
    // 0x800C2688: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x800C268C: lw          $t0, -0x4514($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X4514);
    // 0x800C2690: lui         $t2, 0xE700
    ctx->r10 = S32(0XE700 << 16);
    // 0x800C2694: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x800C2698: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x800C269C: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x800C26A0: sw          $t1, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r9;
    // 0x800C26A4: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x800C26A8: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800C26AC: sw          $zero, 0x4($t4)
    MEM_W(0X4, ctx->r12) = 0;
    // 0x800C26B0: lbu         $a3, 0x3F($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X3F);
    // 0x800C26B4: lbu         $a2, 0x3B($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X3B);
    // 0x800C26B8: lbu         $a1, 0x37($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X37);
    // 0x800C26BC: jal         0x800C2BCC
    // 0x800C26C0: lbu         $a0, 0x33($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X33);
    func_800C2BCC(rdram, ctx);
        goto after_0;
    // 0x800C26C0: lbu         $a0, 0x33($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X33);
    after_0:
    // 0x800C26C4: b           L_800C276C
    // 0x800C26C8: nop

        goto L_800C276C;
    // 0x800C26C8: nop

L_800C26CC:
    // 0x800C26CC: lui         $t5, 0x8011
    ctx->r13 = S32(0X8011 << 16);
    // 0x800C26D0: lw          $t5, -0x4514($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4514);
    // 0x800C26D4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C26D8: lui         $t7, 0xDE00
    ctx->r15 = S32(0XDE00 << 16);
    // 0x800C26DC: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x800C26E0: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800C26E4: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x800C26E8: sw          $t6, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r14;
    // 0x800C26EC: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800C26F0: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800C26F4: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x800C26F8: addiu       $t9, $t9, -0x5410
    ctx->r25 = ADD32(ctx->r25, -0X5410);
    // 0x800C26FC: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x800C2700: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x800C2704: lw          $t1, -0x4514($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4514);
    // 0x800C2708: lui         $t3, 0xDE00
    ctx->r11 = S32(0XDE00 << 16);
    // 0x800C270C: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x800C2710: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x800C2714: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800C2718: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x800C271C: sw          $t2, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r10;
    // 0x800C2720: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x800C2724: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800C2728: addiu       $t5, $t5, -0x53A0
    ctx->r13 = ADD32(ctx->r13, -0X53A0);
    // 0x800C272C: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x800C2730: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x800C2734: lw          $t7, -0x4514($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4514);
    // 0x800C2738: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x800C273C: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x800C2740: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x800C2744: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x800C2748: sw          $t8, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r24;
    // 0x800C274C: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800C2750: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x800C2754: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x800C2758: lbu         $a3, 0x3F($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X3F);
    // 0x800C275C: lbu         $a2, 0x3B($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X3B);
    // 0x800C2760: lbu         $a1, 0x37($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X37);
    // 0x800C2764: jal         0x800C277C
    // 0x800C2768: lbu         $a0, 0x33($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X33);
    func_800C277C(rdram, ctx);
        goto after_1;
    // 0x800C2768: lbu         $a0, 0x33($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X33);
    after_1:
L_800C276C:
    // 0x800C276C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C2770: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800C2774: jr          $ra
    // 0x800C2778: nop

    return;
    // 0x800C2778: nop

;}
RECOMP_FUNC void func_800C277C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C277C: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x800C2780: lw          $t6, -0x4514($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4514);
    // 0x800C2784: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800C2788: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C278C: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x800C2790: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x800C2794: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800C2798: sw          $t7, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r15;
    // 0x800C279C: lui         $t8, 0xFE00
    ctx->r24 = S32(0XFE00 << 16);
    // 0x800C27A0: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x800C27A4: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x800C27A8: lw          $t0, -0x3D58($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X3D58);
    // 0x800C27AC: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x800C27B0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C27B4: addu        $t1, $t0, $at
    ctx->r9 = ADD32(ctx->r8, ctx->r1);
    // 0x800C27B8: lui         $t3, 0x8011
    ctx->r11 = S32(0X8011 << 16);
    // 0x800C27BC: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x800C27C0: lw          $t3, -0x4514($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4514);
    // 0x800C27C4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C27C8: lui         $t5, 0xE300
    ctx->r13 = S32(0XE300 << 16);
    // 0x800C27CC: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x800C27D0: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800C27D4: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x800C27D8: sw          $t4, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r12;
    // 0x800C27DC: ori         $t5, $t5, 0xA01
    ctx->r13 = ctx->r13 | 0XA01;
    // 0x800C27E0: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x800C27E4: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x800C27E8: lui         $t7, 0x30
    ctx->r15 = S32(0X30 << 16);
    // 0x800C27EC: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x800C27F0: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x800C27F4: lw          $t9, -0x4514($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4514);
    // 0x800C27F8: lui         $t1, 0xFF10
    ctx->r9 = S32(0XFF10 << 16);
    // 0x800C27FC: ori         $t1, $t1, 0x13F
    ctx->r9 = ctx->r9 | 0X13F;
    // 0x800C2800: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x800C2804: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x800C2808: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x800C280C: sw          $t0, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r8;
    // 0x800C2810: lui         $t3, 0x8014
    ctx->r11 = S32(0X8014 << 16);
    // 0x800C2814: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x800C2818: lw          $t3, -0x3D58($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X3D58);
    // 0x800C281C: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x800C2820: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C2824: addu        $t4, $t3, $at
    ctx->r12 = ADD32(ctx->r11, ctx->r1);
    // 0x800C2828: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x800C282C: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
    // 0x800C2830: lw          $t6, -0x4514($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4514);
    // 0x800C2834: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C2838: lui         $t8, 0xF700
    ctx->r24 = S32(0XF700 << 16);
    // 0x800C283C: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x800C2840: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800C2844: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800C2848: sw          $t7, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r15;
    // 0x800C284C: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x800C2850: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800C2854: lui         $t0, 0xFFFC
    ctx->r8 = S32(0XFFFC << 16);
    // 0x800C2858: ori         $t0, $t0, 0xFFFC
    ctx->r8 = ctx->r8 | 0XFFFC;
    // 0x800C285C: lui         $t2, 0x8011
    ctx->r10 = S32(0X8011 << 16);
    // 0x800C2860: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x800C2864: lw          $t2, -0x4514($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4514);
    // 0x800C2868: lui         $t4, 0xF64F
    ctx->r12 = S32(0XF64F << 16);
    // 0x800C286C: ori         $t4, $t4, 0xC3BC
    ctx->r12 = ctx->r12 | 0XC3BC;
    // 0x800C2870: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x800C2874: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800C2878: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x800C287C: sw          $t3, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r11;
    // 0x800C2880: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x800C2884: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800C2888: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x800C288C: lui         $t9, 0xED00
    ctx->r25 = S32(0XED00 << 16);
    // 0x800C2890: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x800C2894: lw          $t7, -0x4514($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4514);
    // 0x800C2898: lui         $t1, 0x50
    ctx->r9 = S32(0X50 << 16);
    // 0x800C289C: ori         $t1, $t1, 0x3C0
    ctx->r9 = ctx->r9 | 0X3C0;
    // 0x800C28A0: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x800C28A4: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800C28A8: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x800C28AC: sw          $t8, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r24;
    // 0x800C28B0: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800C28B4: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x800C28B8: lui         $t3, 0x8011
    ctx->r11 = S32(0X8011 << 16);
    // 0x800C28BC: lui         $t5, 0xFF10
    ctx->r13 = S32(0XFF10 << 16);
    // 0x800C28C0: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x800C28C4: lw          $t3, -0x4514($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4514);
    // 0x800C28C8: ori         $t5, $t5, 0x13F
    ctx->r13 = ctx->r13 | 0X13F;
    // 0x800C28CC: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x800C28D0: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x800C28D4: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800C28D8: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x800C28DC: sw          $t4, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r12;
    // 0x800C28E0: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x800C28E4: lw          $t7, -0x3D5C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X3D5C);
    // 0x800C28E8: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800C28EC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C28F0: addu        $t8, $t7, $at
    ctx->r24 = ADD32(ctx->r15, ctx->r1);
    // 0x800C28F4: lui         $t0, 0x8011
    ctx->r8 = S32(0X8011 << 16);
    // 0x800C28F8: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x800C28FC: lw          $t0, -0x4514($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X4514);
    // 0x800C2900: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C2904: lui         $t2, 0xF700
    ctx->r10 = S32(0XF700 << 16);
    // 0x800C2908: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x800C290C: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x800C2910: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x800C2914: sw          $t1, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r9;
    // 0x800C2918: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    // 0x800C291C: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x800C2920: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x800C2924: andi        $t4, $a3, 0x1
    ctx->r12 = ctx->r7 & 0X1;
    // 0x800C2928: sll         $t5, $t4, 16
    ctx->r13 = S32(ctx->r12 << 16);
    // 0x800C292C: andi        $t6, $a3, 0x1
    ctx->r14 = ctx->r7 & 0X1;
    // 0x800C2930: or          $t7, $t5, $t6
    ctx->r15 = ctx->r13 | ctx->r14;
    // 0x800C2934: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x800C2938: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x800C293C: lw          $t9, -0x4514($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4514);
    // 0x800C2940: lui         $t1, 0xF64F
    ctx->r9 = S32(0XF64F << 16);
    // 0x800C2944: ori         $t1, $t1, 0xC3BC
    ctx->r9 = ctx->r9 | 0XC3BC;
    // 0x800C2948: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x800C294C: lw          $t2, 0x14($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X14);
    // 0x800C2950: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x800C2954: sw          $t0, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r8;
    // 0x800C2958: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x800C295C: lw          $t3, 0x14($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X14);
    // 0x800C2960: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x800C2964: addiu       $t7, $zero, 0x140
    ctx->r15 = ADD32(0, 0X140);
    // 0x800C2968: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x800C296C: lw          $t6, -0x4520($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4520);
    // 0x800C2970: lui         $t4, 0x8011
    ctx->r12 = S32(0X8011 << 16);
    // 0x800C2974: lw          $t4, -0x4514($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4514);
    // 0x800C2978: subu        $t8, $t7, $t6
    ctx->r24 = SUB32(ctx->r15, ctx->r14);
    // 0x800C297C: srl         $t9, $t8, 1
    ctx->r25 = S32(U32(ctx->r24) >> 1);
    // 0x800C2980: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x800C2984: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x800C2988: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x800C298C: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x800C2990: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x800C2994: sw          $t5, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r13;
    // 0x800C2998: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800C299C: bgez        $t9, L_800C29B4
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800C29A0: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800C29B4;
    }
    // 0x800C29A0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C29A4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800C29A8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800C29AC: nop

    // 0x800C29B0: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_800C29B4:
    // 0x800C29B4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800C29B8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800C29BC: lui         $t5, 0x8011
    ctx->r13 = S32(0X8011 << 16);
    // 0x800C29C0: lw          $t5, -0x451C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X451C);
    // 0x800C29C4: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800C29C8: addiu       $t7, $zero, 0xF0
    ctx->r15 = ADD32(0, 0XF0);
    // 0x800C29CC: subu        $t6, $t7, $t5
    ctx->r14 = SUB32(ctx->r15, ctx->r13);
    // 0x800C29D0: srl         $t8, $t6, 1
    ctx->r24 = S32(U32(ctx->r14) >> 1);
    // 0x800C29D4: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800C29D8: lui         $at, 0xED00
    ctx->r1 = S32(0XED00 << 16);
    // 0x800C29DC: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800C29E0: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C29E4: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    // 0x800C29E8: nop

    // 0x800C29EC: andi        $t2, $t1, 0xFFF
    ctx->r10 = ctx->r9 & 0XFFF;
    // 0x800C29F0: sll         $t3, $t2, 12
    ctx->r11 = S32(ctx->r10 << 12);
    // 0x800C29F4: bgez        $t8, L_800C2A0C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800C29F8: or          $t4, $t3, $at
        ctx->r12 = ctx->r11 | ctx->r1;
            goto L_800C2A0C;
    }
    // 0x800C29F8: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x800C29FC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800C2A00: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800C2A04: nop

    // 0x800C2A08: add.s       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f6.fl;
L_800C2A0C:
    // 0x800C2A0C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800C2A10: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800C2A14: lw          $t3, 0x10($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X10);
    // 0x800C2A18: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x800C2A1C: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800C2A20: addiu       $t5, $zero, 0x140
    ctx->r13 = ADD32(0, 0X140);
    // 0x800C2A24: addiu       $t9, $zero, 0x140
    ctx->r25 = ADD32(0, 0X140);
    // 0x800C2A28: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800C2A2C: mfc1        $t0, $f18
    ctx->r8 = (int32_t)ctx->f18.u32l;
    // 0x800C2A30: nop

    // 0x800C2A34: andi        $t1, $t0, 0xFFF
    ctx->r9 = ctx->r8 & 0XFFF;
    // 0x800C2A38: or          $t2, $t4, $t1
    ctx->r10 = ctx->r12 | ctx->r9;
    // 0x800C2A3C: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x800C2A40: lw          $t7, -0x4520($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4520);
    // 0x800C2A44: subu        $t6, $t5, $t7
    ctx->r14 = SUB32(ctx->r13, ctx->r15);
    // 0x800C2A48: srl         $t8, $t6, 1
    ctx->r24 = S32(U32(ctx->r14) >> 1);
    // 0x800C2A4C: subu        $t0, $t9, $t8
    ctx->r8 = SUB32(ctx->r25, ctx->r24);
    // 0x800C2A50: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x800C2A54: bgez        $t0, L_800C2A6C
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800C2A58: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800C2A6C;
    }
    // 0x800C2A58: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C2A5C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800C2A60: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800C2A64: nop

    // 0x800C2A68: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_800C2A6C:
    // 0x800C2A6C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800C2A70: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800C2A74: lui         $t5, 0x8011
    ctx->r13 = S32(0X8011 << 16);
    // 0x800C2A78: lw          $t5, -0x451C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X451C);
    // 0x800C2A7C: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800C2A80: addiu       $t7, $zero, 0xF0
    ctx->r15 = ADD32(0, 0XF0);
    // 0x800C2A84: subu        $t6, $t7, $t5
    ctx->r14 = SUB32(ctx->r15, ctx->r13);
    // 0x800C2A88: srl         $t9, $t6, 1
    ctx->r25 = S32(U32(ctx->r14) >> 1);
    // 0x800C2A8C: addiu       $t8, $zero, 0xF0
    ctx->r24 = ADD32(0, 0XF0);
    // 0x800C2A90: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x800C2A94: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x800C2A98: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800C2A9C: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C2AA0: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    // 0x800C2AA4: nop

    // 0x800C2AA8: andi        $t2, $t1, 0xFFF
    ctx->r10 = ctx->r9 & 0XFFF;
    // 0x800C2AAC: bgez        $t0, L_800C2AC4
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800C2AB0: sll         $t3, $t2, 12
        ctx->r11 = S32(ctx->r10 << 12);
            goto L_800C2AC4;
    }
    // 0x800C2AB0: sll         $t3, $t2, 12
    ctx->r11 = S32(ctx->r10 << 12);
    // 0x800C2AB4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800C2AB8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800C2ABC: nop

    // 0x800C2AC0: add.s       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f6.fl;
L_800C2AC4:
    // 0x800C2AC4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800C2AC8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800C2ACC: lw          $t5, 0x10($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X10);
    // 0x800C2AD0: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x800C2AD4: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800C2AD8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C2ADC: sll         $t4, $a0, 8
    ctx->r12 = S32(ctx->r4 << 8);
    // 0x800C2AE0: lui         $t9, 0xF700
    ctx->r25 = S32(0XF700 << 16);
    // 0x800C2AE4: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800C2AE8: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    // 0x800C2AEC: nop

    // 0x800C2AF0: andi        $t2, $t1, 0xFFF
    ctx->r10 = ctx->r9 & 0XFFF;
    // 0x800C2AF4: or          $t7, $t3, $t2
    ctx->r15 = ctx->r11 | ctx->r10;
    // 0x800C2AF8: sw          $t7, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r15;
    // 0x800C2AFC: lw          $t6, -0x4514($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4514);
    // 0x800C2B00: sll         $t3, $a1, 3
    ctx->r11 = S32(ctx->r5 << 3);
    // 0x800C2B04: andi        $t2, $t3, 0x7C0
    ctx->r10 = ctx->r11 & 0X7C0;
    // 0x800C2B08: sw          $t6, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r14;
    // 0x800C2B0C: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x800C2B10: addiu       $t8, $t6, 0x8
    ctx->r24 = ADD32(ctx->r14, 0X8);
    // 0x800C2B14: sw          $t8, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r24;
    // 0x800C2B18: sra         $t5, $a2, 2
    ctx->r13 = S32(SIGNED(ctx->r6) >> 2);
    // 0x800C2B1C: andi        $t1, $t4, 0xF800
    ctx->r9 = ctx->r12 & 0XF800;
    // 0x800C2B20: or          $t7, $t1, $t2
    ctx->r15 = ctx->r9 | ctx->r10;
    // 0x800C2B24: andi        $t6, $t5, 0x3E
    ctx->r14 = ctx->r13 & 0X3E;
    // 0x800C2B28: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800C2B2C: andi        $t9, $a3, 0x1
    ctx->r25 = ctx->r7 & 0X1;
    // 0x800C2B30: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x800C2B34: or          $t0, $t8, $t9
    ctx->r8 = ctx->r24 | ctx->r25;
    // 0x800C2B38: sll         $t2, $a1, 3
    ctx->r10 = S32(ctx->r5 << 3);
    // 0x800C2B3C: sll         $t3, $a0, 8
    ctx->r11 = S32(ctx->r4 << 8);
    // 0x800C2B40: andi        $t1, $t3, 0xF800
    ctx->r9 = ctx->r11 & 0XF800;
    // 0x800C2B44: andi        $t5, $t2, 0x7C0
    ctx->r13 = ctx->r10 & 0X7C0;
    // 0x800C2B48: or          $t7, $t1, $t5
    ctx->r15 = ctx->r9 | ctx->r13;
    // 0x800C2B4C: sra         $t6, $a2, 2
    ctx->r14 = S32(SIGNED(ctx->r6) >> 2);
    // 0x800C2B50: andi        $t8, $t6, 0x3E
    ctx->r24 = ctx->r14 & 0X3E;
    // 0x800C2B54: sll         $t4, $t0, 16
    ctx->r12 = S32(ctx->r8 << 16);
    // 0x800C2B58: lw          $t1, 0xC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC);
    // 0x800C2B5C: andi        $t0, $a3, 0x1
    ctx->r8 = ctx->r7 & 0X1;
    // 0x800C2B60: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x800C2B64: or          $t3, $t9, $t0
    ctx->r11 = ctx->r25 | ctx->r8;
    // 0x800C2B68: or          $t2, $t4, $t3
    ctx->r10 = ctx->r12 | ctx->r11;
    // 0x800C2B6C: lui         $t5, 0x8011
    ctx->r13 = S32(0X8011 << 16);
    // 0x800C2B70: sw          $t2, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r10;
    // 0x800C2B74: lw          $t5, -0x4514($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4514);
    // 0x800C2B78: lui         $t7, 0xF64F
    ctx->r15 = S32(0XF64F << 16);
    // 0x800C2B7C: ori         $t7, $t7, 0xC3BC
    ctx->r15 = ctx->r15 | 0XC3BC;
    // 0x800C2B80: sw          $t5, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r13;
    // 0x800C2B84: lw          $t8, 0x8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8);
    // 0x800C2B88: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x800C2B8C: sw          $t6, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r14;
    // 0x800C2B90: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800C2B94: lw          $t9, 0x8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8);
    // 0x800C2B98: lui         $t0, 0x8011
    ctx->r8 = S32(0X8011 << 16);
    // 0x800C2B9C: lui         $t3, 0xE700
    ctx->r11 = S32(0XE700 << 16);
    // 0x800C2BA0: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x800C2BA4: lw          $t0, -0x4514($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X4514);
    // 0x800C2BA8: sw          $t0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r8;
    // 0x800C2BAC: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x800C2BB0: addiu       $t4, $t0, 0x8
    ctx->r12 = ADD32(ctx->r8, 0X8);
    // 0x800C2BB4: sw          $t4, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r12;
    // 0x800C2BB8: sw          $t3, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r11;
    // 0x800C2BBC: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x800C2BC0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800C2BC4: jr          $ra
    // 0x800C2BC8: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    return;
    // 0x800C2BC8: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
;}
RECOMP_FUNC void func_800C2BCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2BCC: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x800C2BD0: lw          $t6, -0x4514($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4514);
    // 0x800C2BD4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800C2BD8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C2BDC: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x800C2BE0: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x800C2BE4: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800C2BE8: sw          $t7, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r15;
    // 0x800C2BEC: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x800C2BF0: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x800C2BF4: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x800C2BF8: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x800C2BFC: lui         $t3, 0xFE00
    ctx->r11 = S32(0XFE00 << 16);
    // 0x800C2C00: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x800C2C04: lw          $t1, -0x4514($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4514);
    // 0x800C2C08: lui         $t5, 0x8014
    ctx->r13 = S32(0X8014 << 16);
    // 0x800C2C0C: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x800C2C10: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x800C2C14: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x800C2C18: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x800C2C1C: sw          $t2, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r10;
    // 0x800C2C20: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x800C2C24: lw          $t5, -0x3D58($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X3D58);
    // 0x800C2C28: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x800C2C2C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C2C30: addu        $t6, $t5, $at
    ctx->r14 = ADD32(ctx->r13, ctx->r1);
    // 0x800C2C34: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x800C2C38: lw          $t8, -0x4514($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4514);
    // 0x800C2C3C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C2C40: lui         $t0, 0xE300
    ctx->r8 = S32(0XE300 << 16);
    // 0x800C2C44: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x800C2C48: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800C2C4C: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x800C2C50: sw          $t9, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r25;
    // 0x800C2C54: ori         $t0, $t0, 0xA01
    ctx->r8 = ctx->r8 | 0XA01;
    // 0x800C2C58: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x800C2C5C: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x800C2C60: lui         $t2, 0x30
    ctx->r10 = S32(0X30 << 16);
    // 0x800C2C64: lui         $t4, 0x8011
    ctx->r12 = S32(0X8011 << 16);
    // 0x800C2C68: sw          $t2, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r10;
    // 0x800C2C6C: lw          $t4, -0x4514($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4514);
    // 0x800C2C70: lui         $t6, 0xFF10
    ctx->r14 = S32(0XFF10 << 16);
    // 0x800C2C74: ori         $t6, $t6, 0x27F
    ctx->r14 = ctx->r14 | 0X27F;
    // 0x800C2C78: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x800C2C7C: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800C2C80: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x800C2C84: sw          $t5, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r13;
    // 0x800C2C88: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x800C2C8C: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x800C2C90: lw          $t8, -0x3D58($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X3D58);
    // 0x800C2C94: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800C2C98: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C2C9C: addu        $t9, $t8, $at
    ctx->r25 = ADD32(ctx->r24, ctx->r1);
    // 0x800C2CA0: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x800C2CA4: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x800C2CA8: lw          $t1, -0x4514($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4514);
    // 0x800C2CAC: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C2CB0: lui         $t3, 0xF700
    ctx->r11 = S32(0XF700 << 16);
    // 0x800C2CB4: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x800C2CB8: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800C2CBC: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x800C2CC0: sw          $t2, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r10;
    // 0x800C2CC4: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x800C2CC8: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800C2CCC: lui         $t5, 0xFFFC
    ctx->r13 = S32(0XFFFC << 16);
    // 0x800C2CD0: ori         $t5, $t5, 0xFFFC
    ctx->r13 = ctx->r13 | 0XFFFC;
    // 0x800C2CD4: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x800C2CD8: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x800C2CDC: lw          $t7, -0x4514($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4514);
    // 0x800C2CE0: lui         $t9, 0xF69F
    ctx->r25 = S32(0XF69F << 16);
    // 0x800C2CE4: ori         $t9, $t9, 0xC77C
    ctx->r25 = ctx->r25 | 0XC77C;
    // 0x800C2CE8: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x800C2CEC: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800C2CF0: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x800C2CF4: sw          $t8, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r24;
    // 0x800C2CF8: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800C2CFC: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800C2D00: lui         $t2, 0x8011
    ctx->r10 = S32(0X8011 << 16);
    // 0x800C2D04: lui         $t4, 0xED00
    ctx->r12 = S32(0XED00 << 16);
    // 0x800C2D08: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x800C2D0C: lw          $t2, -0x4514($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4514);
    // 0x800C2D10: lui         $t6, 0xA0
    ctx->r14 = S32(0XA0 << 16);
    // 0x800C2D14: ori         $t6, $t6, 0x780
    ctx->r14 = ctx->r14 | 0X780;
    // 0x800C2D18: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x800C2D1C: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800C2D20: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x800C2D24: sw          $t3, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r11;
    // 0x800C2D28: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x800C2D2C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800C2D30: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x800C2D34: lui         $t0, 0xFF10
    ctx->r8 = S32(0XFF10 << 16);
    // 0x800C2D38: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x800C2D3C: lw          $t8, -0x4514($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4514);
    // 0x800C2D40: ori         $t0, $t0, 0x27F
    ctx->r8 = ctx->r8 | 0X27F;
    // 0x800C2D44: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x800C2D48: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x800C2D4C: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x800C2D50: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x800C2D54: sw          $t9, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r25;
    // 0x800C2D58: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x800C2D5C: lw          $t2, -0x3D5C($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X3D5C);
    // 0x800C2D60: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x800C2D64: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C2D68: addu        $t3, $t2, $at
    ctx->r11 = ADD32(ctx->r10, ctx->r1);
    // 0x800C2D6C: lui         $t5, 0x8011
    ctx->r13 = S32(0X8011 << 16);
    // 0x800C2D70: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    // 0x800C2D74: lw          $t5, -0x4514($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4514);
    // 0x800C2D78: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C2D7C: lui         $t7, 0xF700
    ctx->r15 = S32(0XF700 << 16);
    // 0x800C2D80: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x800C2D84: lw          $t8, 0x14($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X14);
    // 0x800C2D88: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x800C2D8C: sw          $t6, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r14;
    // 0x800C2D90: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    // 0x800C2D94: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800C2D98: lw          $t3, 0x14($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X14);
    // 0x800C2D9C: andi        $t9, $a3, 0x1
    ctx->r25 = ctx->r7 & 0X1;
    // 0x800C2DA0: sll         $t0, $t9, 16
    ctx->r8 = S32(ctx->r25 << 16);
    // 0x800C2DA4: andi        $t1, $a3, 0x1
    ctx->r9 = ctx->r7 & 0X1;
    // 0x800C2DA8: or          $t2, $t0, $t1
    ctx->r10 = ctx->r8 | ctx->r9;
    // 0x800C2DAC: lui         $t4, 0x8011
    ctx->r12 = S32(0X8011 << 16);
    // 0x800C2DB0: sw          $t2, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r10;
    // 0x800C2DB4: lw          $t4, -0x4514($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4514);
    // 0x800C2DB8: lui         $t6, 0xF69F
    ctx->r14 = S32(0XF69F << 16);
    // 0x800C2DBC: ori         $t6, $t6, 0xC77C
    ctx->r14 = ctx->r14 | 0XC77C;
    // 0x800C2DC0: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800C2DC4: lw          $t7, 0x10($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X10);
    // 0x800C2DC8: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x800C2DCC: sw          $t5, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r13;
    // 0x800C2DD0: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x800C2DD4: lw          $t8, 0x10($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X10);
    // 0x800C2DD8: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x800C2DDC: addiu       $t2, $zero, 0x280
    ctx->r10 = ADD32(0, 0X280);
    // 0x800C2DE0: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x800C2DE4: lw          $t1, -0x4520($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4520);
    // 0x800C2DE8: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x800C2DEC: lw          $t9, -0x4514($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4514);
    // 0x800C2DF0: subu        $t3, $t2, $t1
    ctx->r11 = SUB32(ctx->r10, ctx->r9);
    // 0x800C2DF4: srl         $t4, $t3, 1
    ctx->r12 = S32(U32(ctx->r11) >> 1);
    // 0x800C2DF8: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x800C2DFC: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x800C2E00: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x800C2E04: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x800C2E08: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x800C2E0C: sw          $t0, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r8;
    // 0x800C2E10: sw          $t9, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r25;
    // 0x800C2E14: bgez        $t4, L_800C2E2C
    if (SIGNED(ctx->r12) >= 0) {
        // 0x800C2E18: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800C2E2C;
    }
    // 0x800C2E18: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C2E1C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800C2E20: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800C2E24: nop

    // 0x800C2E28: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_800C2E2C:
    // 0x800C2E2C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800C2E30: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800C2E34: lui         $t0, 0x8011
    ctx->r8 = S32(0X8011 << 16);
    // 0x800C2E38: lw          $t0, -0x451C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X451C);
    // 0x800C2E3C: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800C2E40: addiu       $t2, $zero, 0x1E0
    ctx->r10 = ADD32(0, 0X1E0);
    // 0x800C2E44: subu        $t1, $t2, $t0
    ctx->r9 = SUB32(ctx->r10, ctx->r8);
    // 0x800C2E48: srl         $t3, $t1, 1
    ctx->r11 = S32(U32(ctx->r9) >> 1);
    // 0x800C2E4C: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x800C2E50: lui         $at, 0xED00
    ctx->r1 = S32(0XED00 << 16);
    // 0x800C2E54: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800C2E58: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C2E5C: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x800C2E60: nop

    // 0x800C2E64: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x800C2E68: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x800C2E6C: bgez        $t3, L_800C2E84
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800C2E70: or          $t9, $t8, $at
        ctx->r25 = ctx->r24 | ctx->r1;
            goto L_800C2E84;
    }
    // 0x800C2E70: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x800C2E74: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800C2E78: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800C2E7C: nop

    // 0x800C2E80: add.s       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f6.fl;
L_800C2E84:
    // 0x800C2E84: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800C2E88: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800C2E8C: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x800C2E90: lui         $t2, 0x8011
    ctx->r10 = S32(0X8011 << 16);
    // 0x800C2E94: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800C2E98: addiu       $t0, $zero, 0x280
    ctx->r8 = ADD32(0, 0X280);
    // 0x800C2E9C: addiu       $t4, $zero, 0x280
    ctx->r12 = ADD32(0, 0X280);
    // 0x800C2EA0: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800C2EA4: mfc1        $t5, $f18
    ctx->r13 = (int32_t)ctx->f18.u32l;
    // 0x800C2EA8: nop

    // 0x800C2EAC: andi        $t6, $t5, 0xFFF
    ctx->r14 = ctx->r13 & 0XFFF;
    // 0x800C2EB0: or          $t7, $t9, $t6
    ctx->r15 = ctx->r25 | ctx->r14;
    // 0x800C2EB4: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800C2EB8: lw          $t2, -0x4520($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4520);
    // 0x800C2EBC: subu        $t1, $t0, $t2
    ctx->r9 = SUB32(ctx->r8, ctx->r10);
    // 0x800C2EC0: srl         $t3, $t1, 1
    ctx->r11 = S32(U32(ctx->r9) >> 1);
    // 0x800C2EC4: subu        $t5, $t4, $t3
    ctx->r13 = SUB32(ctx->r12, ctx->r11);
    // 0x800C2EC8: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x800C2ECC: bgez        $t5, L_800C2EE4
    if (SIGNED(ctx->r13) >= 0) {
        // 0x800C2ED0: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800C2EE4;
    }
    // 0x800C2ED0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C2ED4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800C2ED8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800C2EDC: nop

    // 0x800C2EE0: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_800C2EE4:
    // 0x800C2EE4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800C2EE8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800C2EEC: lui         $t0, 0x8011
    ctx->r8 = S32(0X8011 << 16);
    // 0x800C2EF0: lw          $t0, -0x451C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X451C);
    // 0x800C2EF4: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800C2EF8: addiu       $t2, $zero, 0x1E0
    ctx->r10 = ADD32(0, 0X1E0);
    // 0x800C2EFC: subu        $t1, $t2, $t0
    ctx->r9 = SUB32(ctx->r10, ctx->r8);
    // 0x800C2F00: srl         $t4, $t1, 1
    ctx->r12 = S32(U32(ctx->r9) >> 1);
    // 0x800C2F04: addiu       $t3, $zero, 0x1E0
    ctx->r11 = ADD32(0, 0X1E0);
    // 0x800C2F08: subu        $t5, $t3, $t4
    ctx->r13 = SUB32(ctx->r11, ctx->r12);
    // 0x800C2F0C: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x800C2F10: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800C2F14: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C2F18: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x800C2F1C: nop

    // 0x800C2F20: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x800C2F24: bgez        $t5, L_800C2F3C
    if (SIGNED(ctx->r13) >= 0) {
        // 0x800C2F28: sll         $t8, $t7, 12
        ctx->r24 = S32(ctx->r15 << 12);
            goto L_800C2F3C;
    }
    // 0x800C2F28: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x800C2F2C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800C2F30: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800C2F34: nop

    // 0x800C2F38: add.s       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f6.fl;
L_800C2F3C:
    // 0x800C2F3C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800C2F40: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800C2F44: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x800C2F48: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x800C2F4C: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800C2F50: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C2F54: sll         $t9, $a0, 8
    ctx->r25 = S32(ctx->r4 << 8);
    // 0x800C2F58: lui         $t4, 0xF700
    ctx->r12 = S32(0XF700 << 16);
    // 0x800C2F5C: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800C2F60: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x800C2F64: nop

    // 0x800C2F68: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x800C2F6C: or          $t2, $t8, $t7
    ctx->r10 = ctx->r24 | ctx->r15;
    // 0x800C2F70: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
    // 0x800C2F74: lw          $t1, -0x4514($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4514);
    // 0x800C2F78: sll         $t8, $a1, 3
    ctx->r24 = S32(ctx->r5 << 3);
    // 0x800C2F7C: andi        $t7, $t8, 0x7C0
    ctx->r15 = ctx->r24 & 0X7C0;
    // 0x800C2F80: sw          $t1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r9;
    // 0x800C2F84: lw          $t5, 0x8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8);
    // 0x800C2F88: addiu       $t3, $t1, 0x8
    ctx->r11 = ADD32(ctx->r9, 0X8);
    // 0x800C2F8C: sw          $t3, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r11;
    // 0x800C2F90: sra         $t0, $a2, 2
    ctx->r8 = S32(SIGNED(ctx->r6) >> 2);
    // 0x800C2F94: andi        $t6, $t9, 0xF800
    ctx->r14 = ctx->r25 & 0XF800;
    // 0x800C2F98: or          $t2, $t6, $t7
    ctx->r10 = ctx->r14 | ctx->r15;
    // 0x800C2F9C: andi        $t1, $t0, 0x3E
    ctx->r9 = ctx->r8 & 0X3E;
    // 0x800C2FA0: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x800C2FA4: andi        $t4, $a3, 0x1
    ctx->r12 = ctx->r7 & 0X1;
    // 0x800C2FA8: or          $t3, $t2, $t1
    ctx->r11 = ctx->r10 | ctx->r9;
    // 0x800C2FAC: or          $t5, $t3, $t4
    ctx->r13 = ctx->r11 | ctx->r12;
    // 0x800C2FB0: sll         $t7, $a1, 3
    ctx->r15 = S32(ctx->r5 << 3);
    // 0x800C2FB4: sll         $t8, $a0, 8
    ctx->r24 = S32(ctx->r4 << 8);
    // 0x800C2FB8: andi        $t6, $t8, 0xF800
    ctx->r14 = ctx->r24 & 0XF800;
    // 0x800C2FBC: andi        $t0, $t7, 0x7C0
    ctx->r8 = ctx->r15 & 0X7C0;
    // 0x800C2FC0: or          $t2, $t6, $t0
    ctx->r10 = ctx->r14 | ctx->r8;
    // 0x800C2FC4: sra         $t1, $a2, 2
    ctx->r9 = S32(SIGNED(ctx->r6) >> 2);
    // 0x800C2FC8: andi        $t3, $t1, 0x3E
    ctx->r11 = ctx->r9 & 0X3E;
    // 0x800C2FCC: sll         $t9, $t5, 16
    ctx->r25 = S32(ctx->r13 << 16);
    // 0x800C2FD0: lw          $t6, 0x8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8);
    // 0x800C2FD4: andi        $t5, $a3, 0x1
    ctx->r13 = ctx->r7 & 0X1;
    // 0x800C2FD8: or          $t4, $t2, $t3
    ctx->r12 = ctx->r10 | ctx->r11;
    // 0x800C2FDC: or          $t8, $t4, $t5
    ctx->r24 = ctx->r12 | ctx->r13;
    // 0x800C2FE0: or          $t7, $t9, $t8
    ctx->r15 = ctx->r25 | ctx->r24;
    // 0x800C2FE4: lui         $t0, 0x8011
    ctx->r8 = S32(0X8011 << 16);
    // 0x800C2FE8: sw          $t7, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r15;
    // 0x800C2FEC: lw          $t0, -0x4514($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X4514);
    // 0x800C2FF0: lui         $t2, 0xF69F
    ctx->r10 = S32(0XF69F << 16);
    // 0x800C2FF4: ori         $t2, $t2, 0xC77C
    ctx->r10 = ctx->r10 | 0XC77C;
    // 0x800C2FF8: sw          $t0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r8;
    // 0x800C2FFC: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x800C3000: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x800C3004: sw          $t1, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r9;
    // 0x800C3008: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x800C300C: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x800C3010: lui         $t5, 0x8011
    ctx->r13 = S32(0X8011 << 16);
    // 0x800C3014: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x800C3018: sw          $zero, 0x4($t4)
    MEM_W(0X4, ctx->r12) = 0;
    // 0x800C301C: lw          $t5, -0x4514($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4514);
    // 0x800C3020: sw          $t5, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r13;
    // 0x800C3024: lw          $t7, 0x0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X0);
    // 0x800C3028: addiu       $t9, $t5, 0x8
    ctx->r25 = ADD32(ctx->r13, 0X8);
    // 0x800C302C: sw          $t9, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r25;
    // 0x800C3030: sw          $t8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r24;
    // 0x800C3034: lw          $t6, 0x0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X0);
    // 0x800C3038: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800C303C: jr          $ra
    // 0x800C3040: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    return;
    // 0x800C3040: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
;}
RECOMP_FUNC void func_800C3044(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3044: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C3048: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C304C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800C3050: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x800C3054: lhu         $t8, -0x4530($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X4530);
    // 0x800C3058: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C305C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C3060: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800C3064: sw          $t6, -0x4520($at)
    MEM_W(-0X4520, ctx->r1) = ctx->r14;
    // 0x800C3068: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C306C: andi        $t9, $t8, 0x1000
    ctx->r25 = ctx->r24 & 0X1000;
    // 0x800C3070: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C3074: beq         $t9, $zero, L_800C30E4
    if (ctx->r25 == 0) {
        // 0x800C3078: sw          $t7, -0x451C($at)
        MEM_W(-0X451C, ctx->r1) = ctx->r15;
            goto L_800C30E4;
    }
    // 0x800C3078: sw          $t7, -0x451C($at)
    MEM_W(-0X451C, ctx->r1) = ctx->r15;
    // 0x800C307C: lui         $t0, 0x8011
    ctx->r8 = S32(0X8011 << 16);
    // 0x800C3080: lhu         $t0, -0x4530($t0)
    ctx->r8 = MEM_HU(ctx->r8, -0X4530);
    // 0x800C3084: lui         $t2, 0x8000
    ctx->r10 = S32(0X8000 << 16);
    // 0x800C3088: lw          $t2, 0x300($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X300);
    // 0x800C308C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C3090: andi        $t1, $t0, 0xEFFF
    ctx->r9 = ctx->r8 & 0XEFFF;
    // 0x800C3094: sh          $t1, -0x4530($at)
    MEM_H(-0X4530, ctx->r1) = ctx->r9;
    // 0x800C3098: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C309C: bne         $t2, $at, L_800C30BC
    if (ctx->r10 != ctx->r1) {
        // 0x800C30A0: nop
    
            goto L_800C30BC;
    }
    // 0x800C30A0: nop

    // 0x800C30A4: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800C30A8: addiu       $a0, $a0, -0x43D0
    ctx->r4 = ADD32(ctx->r4, -0X43D0);
    // 0x800C30AC: jal         0x800D3B40
    // 0x800C30B0: addiu       $a0, $a0, 0xA0
    ctx->r4 = ADD32(ctx->r4, 0XA0);
    osViSetMode_recomp(rdram, ctx);
        goto after_0;
    // 0x800C30B0: addiu       $a0, $a0, 0xA0
    ctx->r4 = ADD32(ctx->r4, 0XA0);
    after_0:
    // 0x800C30B4: b           L_800C30CC
    // 0x800C30B8: nop

        goto L_800C30CC;
    // 0x800C30B8: nop

L_800C30BC:
    // 0x800C30BC: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800C30C0: addiu       $a0, $a0, -0x43D0
    ctx->r4 = ADD32(ctx->r4, -0X43D0);
    // 0x800C30C4: jal         0x800D3B40
    // 0x800C30C8: addiu       $a0, $a0, 0x960
    ctx->r4 = ADD32(ctx->r4, 0X960);
    osViSetMode_recomp(rdram, ctx);
        goto after_1;
    // 0x800C30C8: addiu       $a0, $a0, 0x960
    ctx->r4 = ADD32(ctx->r4, 0X960);
    after_1:
L_800C30CC:
    // 0x800C30CC: jal         0x800C31D4
    // 0x800C30D0: nop

    func_800C31D4(rdram, ctx);
        goto after_2;
    // 0x800C30D0: nop

    after_2:
    // 0x800C30D4: jal         0x800D3BB0
    // 0x800C30D8: addiu       $a0, $zero, 0x5A
    ctx->r4 = ADD32(0, 0X5A);
    osViSetSpecialFeatures_recomp(rdram, ctx);
        goto after_3;
    // 0x800C30D8: addiu       $a0, $zero, 0x5A
    ctx->r4 = ADD32(0, 0X5A);
    after_3:
    // 0x800C30DC: jal         0x800D1454
    // 0x800C30E0: nop

    func_800D1454(rdram, ctx);
        goto after_4;
    // 0x800C30E0: nop

    after_4:
L_800C30E4:
    // 0x800C30E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C30E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C30EC: jr          $ra
    // 0x800C30F0: nop

    return;
    // 0x800C30F0: nop

;}
RECOMP_FUNC void func_800C30F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C30F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C30F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C30FC: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800C3100: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x800C3104: lhu         $t8, -0x4530($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X4530);
    // 0x800C3108: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C310C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C3110: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800C3114: sw          $t6, -0x4520($at)
    MEM_W(-0X4520, ctx->r1) = ctx->r14;
    // 0x800C3118: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C311C: andi        $t9, $t8, 0x1000
    ctx->r25 = ctx->r24 & 0X1000;
    // 0x800C3120: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C3124: bne         $t9, $zero, L_800C3194
    if (ctx->r25 != 0) {
        // 0x800C3128: sw          $t7, -0x451C($at)
        MEM_W(-0X451C, ctx->r1) = ctx->r15;
            goto L_800C3194;
    }
    // 0x800C3128: sw          $t7, -0x451C($at)
    MEM_W(-0X451C, ctx->r1) = ctx->r15;
    // 0x800C312C: lui         $t0, 0x8011
    ctx->r8 = S32(0X8011 << 16);
    // 0x800C3130: lhu         $t0, -0x4530($t0)
    ctx->r8 = MEM_HU(ctx->r8, -0X4530);
    // 0x800C3134: lui         $t2, 0x8000
    ctx->r10 = S32(0X8000 << 16);
    // 0x800C3138: lw          $t2, 0x300($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X300);
    // 0x800C313C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C3140: ori         $t1, $t0, 0x1000
    ctx->r9 = ctx->r8 | 0X1000;
    // 0x800C3144: sh          $t1, -0x4530($at)
    MEM_H(-0X4530, ctx->r1) = ctx->r9;
    // 0x800C3148: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C314C: bne         $t2, $at, L_800C316C
    if (ctx->r10 != ctx->r1) {
        // 0x800C3150: nop
    
            goto L_800C316C;
    }
    // 0x800C3150: nop

    // 0x800C3154: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800C3158: addiu       $a0, $a0, -0x43D0
    ctx->r4 = ADD32(ctx->r4, -0X43D0);
    // 0x800C315C: jal         0x800D3B40
    // 0x800C3160: addiu       $a0, $a0, 0x370
    ctx->r4 = ADD32(ctx->r4, 0X370);
    osViSetMode_recomp(rdram, ctx);
        goto after_0;
    // 0x800C3160: addiu       $a0, $a0, 0x370
    ctx->r4 = ADD32(ctx->r4, 0X370);
    after_0:
    // 0x800C3164: b           L_800C317C
    // 0x800C3168: nop

        goto L_800C317C;
    // 0x800C3168: nop

L_800C316C:
    // 0x800C316C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800C3170: addiu       $a0, $a0, -0x43D0
    ctx->r4 = ADD32(ctx->r4, -0X43D0);
    // 0x800C3174: jal         0x800D3B40
    // 0x800C3178: addiu       $a0, $a0, 0xC30
    ctx->r4 = ADD32(ctx->r4, 0XC30);
    osViSetMode_recomp(rdram, ctx);
        goto after_1;
    // 0x800C3178: addiu       $a0, $a0, 0xC30
    ctx->r4 = ADD32(ctx->r4, 0XC30);
    after_1:
L_800C317C:
    // 0x800C317C: jal         0x800C31D4
    // 0x800C3180: nop

    func_800C31D4(rdram, ctx);
        goto after_2;
    // 0x800C3180: nop

    after_2:
    // 0x800C3184: jal         0x800D3BB0
    // 0x800C3188: addiu       $a0, $zero, 0x5A
    ctx->r4 = ADD32(0, 0X5A);
    osViSetSpecialFeatures_recomp(rdram, ctx);
        goto after_3;
    // 0x800C3188: addiu       $a0, $zero, 0x5A
    ctx->r4 = ADD32(0, 0X5A);
    after_3:
    // 0x800C318C: jal         0x800D1510
    // 0x800C3190: nop

    func_800D1510(rdram, ctx);
        goto after_4;
    // 0x800C3190: nop

    after_4:
L_800C3194:
    // 0x800C3194: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C3198: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C319C: jr          $ra
    // 0x800C31A0: nop

    return;
    // 0x800C31A0: nop

;}
RECOMP_FUNC void func_800C31A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C31A4: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x800C31A8: lhu         $t6, -0x4530($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X4530);
    // 0x800C31AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C31B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C31B4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C31B8: ori         $t7, $t6, 0x2000
    ctx->r15 = ctx->r14 | 0X2000;
    // 0x800C31BC: jal         0x800D1D00
    // 0x800C31C0: sh          $t7, -0x4530($at)
    MEM_H(-0X4530, ctx->r1) = ctx->r15;
    func_800D1D00(rdram, ctx);
        goto after_0;
    // 0x800C31C0: sh          $t7, -0x4530($at)
    MEM_H(-0X4530, ctx->r1) = ctx->r15;
    after_0:
    // 0x800C31C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C31C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C31CC: jr          $ra
    // 0x800C31D0: nop

    return;
    // 0x800C31D0: nop

;}
RECOMP_FUNC void func_800C31D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C31D4: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x800C31D8: lhu         $t6, -0x4530($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X4530);
    // 0x800C31DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C31E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C31E4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C31E8: andi        $t7, $t6, 0xDF0F
    ctx->r15 = ctx->r14 & 0XDF0F;
    // 0x800C31EC: jal         0x800D1610
    // 0x800C31F0: sh          $t7, -0x4530($at)
    MEM_H(-0X4530, ctx->r1) = ctx->r15;
    func_800D1610(rdram, ctx);
        goto after_0;
    // 0x800C31F0: sh          $t7, -0x4530($at)
    MEM_H(-0X4530, ctx->r1) = ctx->r15;
    after_0:
    // 0x800C31F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C31F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C31FC: jr          $ra
    // 0x800C3200: nop

    return;
    // 0x800C3200: nop

;}
RECOMP_FUNC void func_800C3204(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3204: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x800C3208: lhu         $t6, -0x4530($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X4530);
    // 0x800C320C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C3210: ori         $t7, $t6, 0x80
    ctx->r15 = ctx->r14 | 0X80;
    // 0x800C3214: jr          $ra
    // 0x800C3218: sh          $t7, -0x4530($at)
    MEM_H(-0X4530, ctx->r1) = ctx->r15;
    return;
    // 0x800C3218: sh          $t7, -0x4530($at)
    MEM_H(-0X4530, ctx->r1) = ctx->r15;
;}
RECOMP_FUNC void func_800C321C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C321C: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x800C3220: lhu         $t6, -0x4530($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X4530);
    // 0x800C3224: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C3228: andi        $t7, $t6, 0xFF7F
    ctx->r15 = ctx->r14 & 0XFF7F;
    // 0x800C322C: jr          $ra
    // 0x800C3230: sh          $t7, -0x4530($at)
    MEM_H(-0X4530, ctx->r1) = ctx->r15;
    return;
    // 0x800C3230: sh          $t7, -0x4530($at)
    MEM_H(-0X4530, ctx->r1) = ctx->r15;
;}
RECOMP_FUNC void func_800C3234(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3234: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x800C3238: lhu         $t6, -0x4530($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X4530);
    // 0x800C323C: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x800C3240: lw          $t8, -0x451C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X451C);
    // 0x800C3244: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C3248: ori         $t7, $t6, 0x40
    ctx->r15 = ctx->r14 | 0X40;
    // 0x800C324C: sh          $t7, -0x4530($at)
    MEM_H(-0X4530, ctx->r1) = ctx->r15;
    // 0x800C3250: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C3254: sw          $t8, -0x4518($at)
    MEM_W(-0X4518, ctx->r1) = ctx->r24;
    // 0x800C3258: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C325C: jr          $ra
    // 0x800C3260: sw          $zero, -0x451C($at)
    MEM_W(-0X451C, ctx->r1) = 0;
    return;
    // 0x800C3260: sw          $zero, -0x451C($at)
    MEM_W(-0X451C, ctx->r1) = 0;
;}
RECOMP_FUNC void func_800C3264(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3264: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x800C3268: lhu         $t6, -0x4530($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X4530);
    // 0x800C326C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C3270: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x800C3274: andi        $t7, $t6, 0xFFBF
    ctx->r15 = ctx->r14 & 0XFFBF;
    // 0x800C3278: lw          $t8, -0x4518($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4518);
    // 0x800C327C: sh          $t7, -0x4530($at)
    MEM_H(-0X4530, ctx->r1) = ctx->r15;
    // 0x800C3280: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C3284: jr          $ra
    // 0x800C3288: sw          $t8, -0x451C($at)
    MEM_W(-0X451C, ctx->r1) = ctx->r24;
    return;
    // 0x800C3288: sw          $t8, -0x451C($at)
    MEM_W(-0X451C, ctx->r1) = ctx->r24;
;}
RECOMP_FUNC void func_800C328C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C328C: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x800C3290: lhu         $t6, -0x4530($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X4530);
    // 0x800C3294: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C3298: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C329C: andi        $t7, $t6, 0xFF0F
    ctx->r15 = ctx->r14 & 0XFF0F;
    // 0x800C32A0: ori         $t8, $t7, 0x10
    ctx->r24 = ctx->r15 | 0X10;
    // 0x800C32A4: sh          $t8, -0x4530($at)
    MEM_H(-0X4530, ctx->r1) = ctx->r24;
    // 0x800C32A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C32AC: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C32B0: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800C32B4: jal         0x800C31A4
    // 0x800C32B8: sb          $t9, -0x452E($at)
    MEM_B(-0X452E, ctx->r1) = ctx->r25;
    func_800C31A4(rdram, ctx);
        goto after_0;
    // 0x800C32B8: sb          $t9, -0x452E($at)
    MEM_B(-0X452E, ctx->r1) = ctx->r25;
    after_0:
    // 0x800C32BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C32C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C32C4: jr          $ra
    // 0x800C32C8: nop

    return;
    // 0x800C32C8: nop

;}
RECOMP_FUNC void func_800C32CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C32CC: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x800C32D0: lhu         $t6, -0x4530($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X4530);
    // 0x800C32D4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C32D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C32DC: andi        $t7, $t6, 0xFF0F
    ctx->r15 = ctx->r14 & 0XFF0F;
    // 0x800C32E0: ori         $t8, $t7, 0x20
    ctx->r24 = ctx->r15 | 0X20;
    // 0x800C32E4: sh          $t8, -0x4530($at)
    MEM_H(-0X4530, ctx->r1) = ctx->r24;
    // 0x800C32E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C32EC: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C32F0: jal         0x800C31A4
    // 0x800C32F4: sb          $zero, -0x452E($at)
    MEM_B(-0X452E, ctx->r1) = 0;
    func_800C31A4(rdram, ctx);
        goto after_0;
    // 0x800C32F4: sb          $zero, -0x452E($at)
    MEM_B(-0X452E, ctx->r1) = 0;
    after_0:
    // 0x800C32F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C32FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C3300: jr          $ra
    // 0x800C3304: nop

    return;
    // 0x800C3304: nop

;}
RECOMP_FUNC void func_800C3308(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3308: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x800C330C: lhu         $t6, -0x4530($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X4530);
    // 0x800C3310: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C3314: andi        $t7, $t6, 0xFEFF
    ctx->r15 = ctx->r14 & 0XFEFF;
    // 0x800C3318: jr          $ra
    // 0x800C331C: sh          $t7, -0x4530($at)
    MEM_H(-0X4530, ctx->r1) = ctx->r15;
    return;
    // 0x800C331C: sh          $t7, -0x4530($at)
    MEM_H(-0X4530, ctx->r1) = ctx->r15;
;}
RECOMP_FUNC void func_800C3320(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3320: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x800C3324: lhu         $t6, -0x4530($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X4530);
    // 0x800C3328: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C332C: ori         $t7, $t6, 0x100
    ctx->r15 = ctx->r14 | 0X100;
    // 0x800C3330: jr          $ra
    // 0x800C3334: sh          $t7, -0x4530($at)
    MEM_H(-0X4530, ctx->r1) = ctx->r15;
    return;
    // 0x800C3334: sh          $t7, -0x4530($at)
    MEM_H(-0X4530, ctx->r1) = ctx->r15;
;}
RECOMP_FUNC void func_800C3338(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3338: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x800C333C: lhu         $t6, -0x4530($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X4530);
    // 0x800C3340: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C3344: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C3348: andi        $t7, $t6, 0x80
    ctx->r15 = ctx->r14 & 0X80;
    // 0x800C334C: beq         $t7, $zero, L_800C335C
    if (ctx->r15 == 0) {
        // 0x800C3350: nop
    
            goto L_800C335C;
    }
    // 0x800C3350: nop

    // 0x800C3354: jal         0x800C34D8
    // 0x800C3358: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    func_800C34D8(rdram, ctx);
        goto after_0;
    // 0x800C3358: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    after_0:
L_800C335C:
    // 0x800C335C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C3360: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C3364: jr          $ra
    // 0x800C3368: nop

    return;
    // 0x800C3368: nop

;}
RECOMP_FUNC void func_800C336C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C336C: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x800C3370: lhu         $t6, -0x4530($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X4530);
    // 0x800C3374: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C3378: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C337C: andi        $t7, $t6, 0x1000
    ctx->r15 = ctx->r14 & 0X1000;
    // 0x800C3380: beq         $t7, $zero, L_800C3394
    if (ctx->r15 == 0) {
        // 0x800C3384: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_800C3394;
    }
    // 0x800C3384: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C3388: addiu       $t8, $zero, 0x28
    ctx->r24 = ADD32(0, 0X28);
    // 0x800C338C: b           L_800C339C
    // 0x800C3390: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
        goto L_800C339C;
    // 0x800C3390: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
L_800C3394:
    // 0x800C3394: addiu       $t9, $zero, 0xF
    ctx->r25 = ADD32(0, 0XF);
    // 0x800C3398: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
L_800C339C:
    // 0x800C339C: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x800C33A0: lhu         $s0, -0x4530($s0)
    ctx->r16 = MEM_HU(ctx->r16, -0X4530);
    // 0x800C33A4: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x800C33A8: andi        $t0, $s0, 0xF0
    ctx->r8 = ctx->r16 & 0XF0;
    // 0x800C33AC: or          $s0, $t0, $zero
    ctx->r16 = ctx->r8 | 0;
    // 0x800C33B0: beq         $s0, $at, L_800C33D8
    if (ctx->r16 == ctx->r1) {
        // 0x800C33B4: addiu       $at, $zero, 0x20
        ctx->r1 = ADD32(0, 0X20);
            goto L_800C33D8;
    }
    // 0x800C33B4: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x800C33B8: beq         $s0, $at, L_800C344C
    if (ctx->r16 == ctx->r1) {
        // 0x800C33BC: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_800C344C;
    }
    // 0x800C33BC: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x800C33C0: bne         $s0, $at, L_800C34C4
    if (ctx->r16 != ctx->r1) {
        // 0x800C33C4: nop
    
            goto L_800C34C4;
    }
    // 0x800C33C4: nop

    // 0x800C33C8: jal         0x800C34D8
    // 0x800C33CC: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    func_800C34D8(rdram, ctx);
        goto after_0;
    // 0x800C33CC: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    after_0:
    // 0x800C33D0: b           L_800C34C4
    // 0x800C33D4: nop

        goto L_800C34C4;
    // 0x800C33D4: nop

L_800C33D8:
    // 0x800C33D8: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x800C33DC: lbu         $t1, -0x452E($t1)
    ctx->r9 = MEM_BU(ctx->r9, -0X452E);
    // 0x800C33E0: bne         $t1, $zero, L_800C3400
    if (ctx->r9 != 0) {
        // 0x800C33E4: nop
    
            goto L_800C3400;
    }
    // 0x800C33E4: nop

    // 0x800C33E8: lui         $t2, 0x8011
    ctx->r10 = S32(0X8011 << 16);
    // 0x800C33EC: lhu         $t2, -0x4530($t2)
    ctx->r10 = MEM_HU(ctx->r10, -0X4530);
    // 0x800C33F0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C33F4: andi        $t3, $t2, 0xFF0F
    ctx->r11 = ctx->r10 & 0XFF0F;
    // 0x800C33F8: b           L_800C34C4
    // 0x800C33FC: sh          $t3, -0x4530($at)
    MEM_H(-0X4530, ctx->r1) = ctx->r11;
        goto L_800C34C4;
    // 0x800C33FC: sh          $t3, -0x4530($at)
    MEM_H(-0X4530, ctx->r1) = ctx->r11;
L_800C3400:
    // 0x800C3400: lui         $t4, 0x8011
    ctx->r12 = S32(0X8011 << 16);
    // 0x800C3404: lbu         $t4, -0x452E($t4)
    ctx->r12 = MEM_BU(ctx->r12, -0X452E);
    // 0x800C3408: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800C340C: sltu        $at, $t4, $t5
    ctx->r1 = ctx->r12 < ctx->r13 ? 1 : 0;
    // 0x800C3410: beq         $at, $zero, L_800C3420
    if (ctx->r1 == 0) {
        // 0x800C3414: lui         $at, 0x8011
        ctx->r1 = S32(0X8011 << 16);
            goto L_800C3420;
    }
    // 0x800C3414: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C3418: b           L_800C3438
    // 0x800C341C: sb          $zero, -0x452E($at)
    MEM_B(-0X452E, ctx->r1) = 0;
        goto L_800C3438;
    // 0x800C341C: sb          $zero, -0x452E($at)
    MEM_B(-0X452E, ctx->r1) = 0;
L_800C3420:
    // 0x800C3420: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x800C3424: lbu         $t6, -0x452E($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X452E);
    // 0x800C3428: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800C342C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C3430: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x800C3434: sb          $t8, -0x452E($at)
    MEM_B(-0X452E, ctx->r1) = ctx->r24;
L_800C3438:
    // 0x800C3438: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800C343C: jal         0x800C34D8
    // 0x800C3440: lbu         $a0, -0x452E($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X452E);
    func_800C34D8(rdram, ctx);
        goto after_1;
    // 0x800C3440: lbu         $a0, -0x452E($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X452E);
    after_1:
    // 0x800C3444: b           L_800C34C4
    // 0x800C3448: nop

        goto L_800C34C4;
    // 0x800C3448: nop

L_800C344C:
    // 0x800C344C: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x800C3450: lbu         $t9, -0x452E($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X452E);
    // 0x800C3454: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800C3458: bne         $t9, $at, L_800C3470
    if (ctx->r25 != ctx->r1) {
        // 0x800C345C: nop
    
            goto L_800C3470;
    }
    // 0x800C345C: nop

    // 0x800C3460: jal         0x800C31D4
    // 0x800C3464: nop

    func_800C31D4(rdram, ctx);
        goto after_2;
    // 0x800C3464: nop

    after_2:
    // 0x800C3468: b           L_800C34C4
    // 0x800C346C: nop

        goto L_800C34C4;
    // 0x800C346C: nop

L_800C3470:
    // 0x800C3470: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x800C3474: lbu         $t1, -0x452E($t1)
    ctx->r9 = MEM_BU(ctx->r9, -0X452E);
    // 0x800C3478: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800C347C: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x800C3480: subu        $t3, $t2, $t1
    ctx->r11 = SUB32(ctx->r10, ctx->r9);
    // 0x800C3484: sltu        $at, $t3, $t0
    ctx->r1 = ctx->r11 < ctx->r8 ? 1 : 0;
    // 0x800C3488: beq         $at, $zero, L_800C34A0
    if (ctx->r1 == 0) {
        // 0x800C348C: nop
    
            goto L_800C34A0;
    }
    // 0x800C348C: nop

    // 0x800C3490: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x800C3494: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C3498: b           L_800C34B8
    // 0x800C349C: sb          $t4, -0x452E($at)
    MEM_B(-0X452E, ctx->r1) = ctx->r12;
        goto L_800C34B8;
    // 0x800C349C: sb          $t4, -0x452E($at)
    MEM_B(-0X452E, ctx->r1) = ctx->r12;
L_800C34A0:
    // 0x800C34A0: lui         $t5, 0x8011
    ctx->r13 = S32(0X8011 << 16);
    // 0x800C34A4: lbu         $t5, -0x452E($t5)
    ctx->r13 = MEM_BU(ctx->r13, -0X452E);
    // 0x800C34A8: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800C34AC: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C34B0: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x800C34B4: sb          $t7, -0x452E($at)
    MEM_B(-0X452E, ctx->r1) = ctx->r15;
L_800C34B8:
    // 0x800C34B8: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800C34BC: jal         0x800C34D8
    // 0x800C34C0: lbu         $a0, -0x452E($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X452E);
    func_800C34D8(rdram, ctx);
        goto after_3;
    // 0x800C34C0: lbu         $a0, -0x452E($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X452E);
    after_3:
L_800C34C4:
    // 0x800C34C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C34C8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C34CC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800C34D0: jr          $ra
    // 0x800C34D4: nop

    return;
    // 0x800C34D4: nop

;}
RECOMP_FUNC void func_800C34D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C34D8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C34DC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800C34E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C34E4: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800C34E8: jal         0x800D54C8
    // 0x800C34EC: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    spX2Init_recomp(rdram, ctx);
        goto after_0;
    // 0x800C34EC: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    after_0:
    // 0x800C34F0: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x800C34F4: lhu         $t6, -0x4530($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X4530);
    // 0x800C34F8: andi        $t7, $t6, 0x1000
    ctx->r15 = ctx->r14 & 0X1000;
    // 0x800C34FC: beq         $t7, $zero, L_800C3534
    if (ctx->r15 == 0) {
        // 0x800C3500: lui         $at, 0x4100
        ctx->r1 = S32(0X4100 << 16);
            goto L_800C3534;
    }
    // 0x800C3500: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x800C3504: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800C3508: lbu         $t8, 0x23($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X23);
    // 0x800C350C: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x800C3510: addiu       $a0, $a0, -0x4E88
    ctx->r4 = ADD32(ctx->r4, -0X4E88);
    // 0x800C3514: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800C3518: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800C351C: lui         $a3, 0x4100
    ctx->r7 = S32(0X4100 << 16);
    // 0x800C3520: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x800C3524: jal         0x800C6C6C
    // 0x800C3528: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_1;
    // 0x800C3528: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x800C352C: b           L_800C3560
    // 0x800C3530: nop

        goto L_800C3560;
    // 0x800C3530: nop

L_800C3534:
    // 0x800C3534: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800C3538: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800C353C: lbu         $t9, 0x23($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X23);
    // 0x800C3540: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x800C3544: addiu       $a0, $a0, -0x4E88
    ctx->r4 = ADD32(ctx->r4, -0X4E88);
    // 0x800C3548: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800C354C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800C3550: lui         $a3, 0x4080
    ctx->r7 = S32(0X4080 << 16);
    // 0x800C3554: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x800C3558: jal         0x800C6C6C
    // 0x800C355C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800C6C6C(rdram, ctx);
        goto after_2;
    // 0x800C355C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_2:
L_800C3560:
    // 0x800C3560: jal         0x800C6D5C
    // 0x800C3564: nop

    func_800C6D5C(rdram, ctx);
        goto after_3;
    // 0x800C3564: nop

    after_3:
    // 0x800C3568: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C356C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C3570: jr          $ra
    // 0x800C3574: nop

    return;
    // 0x800C3574: nop

;}
RECOMP_FUNC void func_800C3578(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3578: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800C357C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C3580: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x800C3584: lhu         $s0, -0x4530($s0)
    ctx->r16 = MEM_HU(ctx->r16, -0X4530);
    // 0x800C3588: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C358C: andi        $t6, $s0, 0xC000
    ctx->r14 = ctx->r16 & 0XC000;
    // 0x800C3590: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    // 0x800C3594: beq         $s0, $zero, L_800C35BC
    if (ctx->r16 == 0) {
        // 0x800C3598: addiu       $at, $zero, 0x4000
        ctx->r1 = ADD32(0, 0X4000);
            goto L_800C35BC;
    }
    // 0x800C3598: addiu       $at, $zero, 0x4000
    ctx->r1 = ADD32(0, 0X4000);
    // 0x800C359C: beq         $s0, $at, L_800C35F4
    if (ctx->r16 == ctx->r1) {
        // 0x800C35A0: ori         $at, $zero, 0x8000
        ctx->r1 = 0 | 0X8000;
            goto L_800C35F4;
    }
    // 0x800C35A0: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x800C35A4: beq         $s0, $at, L_800C3634
    if (ctx->r16 == ctx->r1) {
        // 0x800C35A8: ori         $at, $zero, 0xC000
        ctx->r1 = 0 | 0XC000;
            goto L_800C3634;
    }
    // 0x800C35A8: ori         $at, $zero, 0xC000
    ctx->r1 = 0 | 0XC000;
    // 0x800C35AC: beq         $s0, $at, L_800C3674
    if (ctx->r16 == ctx->r1) {
        // 0x800C35B0: nop
    
            goto L_800C3674;
    }
    // 0x800C35B0: nop

    // 0x800C35B4: b           L_800C36B4
    // 0x800C35B8: nop

        goto L_800C36B4;
    // 0x800C35B8: nop

L_800C35BC:
    // 0x800C35BC: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x800C35C0: lw          $t7, -0x4514($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4514);
    // 0x800C35C4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C35C8: lui         $t9, 0xDE00
    ctx->r25 = S32(0XDE00 << 16);
    // 0x800C35CC: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x800C35D0: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x800C35D4: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x800C35D8: sw          $t8, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r24;
    // 0x800C35DC: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800C35E0: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x800C35E4: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x800C35E8: addiu       $t1, $t1, -0x5260
    ctx->r9 = ADD32(ctx->r9, -0X5260);
    // 0x800C35EC: b           L_800C36B4
    // 0x800C35F0: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
        goto L_800C36B4;
    // 0x800C35F0: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
L_800C35F4:
    // 0x800C35F4: lui         $t3, 0x8011
    ctx->r11 = S32(0X8011 << 16);
    // 0x800C35F8: lw          $t3, -0x4514($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4514);
    // 0x800C35FC: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C3600: lui         $t5, 0xDE00
    ctx->r13 = S32(0XDE00 << 16);
    // 0x800C3604: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x800C3608: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800C360C: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x800C3610: sw          $t4, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r12;
    // 0x800C3614: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x800C3618: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x800C361C: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x800C3620: addiu       $t7, $t7, -0x5218
    ctx->r15 = ADD32(ctx->r15, -0X5218);
    // 0x800C3624: jal         0x800C721C
    // 0x800C3628: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    func_800C721C(rdram, ctx);
        goto after_0;
    // 0x800C3628: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    after_0:
    // 0x800C362C: b           L_800C36B4
    // 0x800C3630: nop

        goto L_800C36B4;
    // 0x800C3630: nop

L_800C3634:
    // 0x800C3634: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x800C3638: lw          $t9, -0x4514($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4514);
    // 0x800C363C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C3640: lui         $t1, 0xDE00
    ctx->r9 = S32(0XDE00 << 16);
    // 0x800C3644: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x800C3648: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x800C364C: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x800C3650: sw          $t0, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r8;
    // 0x800C3654: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x800C3658: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x800C365C: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x800C3660: addiu       $t3, $t3, -0x51D0
    ctx->r11 = ADD32(ctx->r11, -0X51D0);
    // 0x800C3664: jal         0x800C6EF8
    // 0x800C3668: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    func_800C6EF8(rdram, ctx);
        goto after_1;
    // 0x800C3668: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    after_1:
    // 0x800C366C: b           L_800C36B4
    // 0x800C3670: nop

        goto L_800C36B4;
    // 0x800C3670: nop

L_800C3674:
    // 0x800C3674: lui         $t5, 0x8011
    ctx->r13 = S32(0X8011 << 16);
    // 0x800C3678: lw          $t5, -0x4514($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4514);
    // 0x800C367C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C3680: lui         $t7, 0xDE00
    ctx->r15 = S32(0XDE00 << 16);
    // 0x800C3684: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
    // 0x800C3688: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800C368C: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x800C3690: sw          $t6, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r14;
    // 0x800C3694: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800C3698: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800C369C: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x800C36A0: addiu       $t9, $t9, -0x5188
    ctx->r25 = ADD32(ctx->r25, -0X5188);
    // 0x800C36A4: jal         0x800C6EF8
    // 0x800C36A8: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    func_800C6EF8(rdram, ctx);
        goto after_2;
    // 0x800C36A8: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    after_2:
    // 0x800C36AC: jal         0x800C721C
    // 0x800C36B0: nop

    func_800C721C(rdram, ctx);
        goto after_3;
    // 0x800C36B0: nop

    after_3:
L_800C36B4:
    // 0x800C36B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C36B8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C36BC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800C36C0: jr          $ra
    // 0x800C36C4: nop

    return;
    // 0x800C36C4: nop

;}
RECOMP_FUNC void func_800C36C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C36C8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C36CC: sw          $a0, -0x452C($at)
    MEM_W(-0X452C, ctx->r1) = ctx->r4;
    // 0x800C36D0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C36D4: sw          $zero, -0x4528($at)
    MEM_W(-0X4528, ctx->r1) = 0;
    // 0x800C36D8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C36DC: sw          $zero, -0x4524($at)
    MEM_W(-0X4524, ctx->r1) = 0;
    // 0x800C36E0: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x800C36E4: addiu       $t6, $t6, 0x3AF8
    ctx->r14 = ADD32(ctx->r14, 0X3AF8);
    // 0x800C36E8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C36EC: sw          $t6, 0x3AF0($at)
    MEM_W(0X3AF0, ctx->r1) = ctx->r14;
    // 0x800C36F0: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x800C36F4: addiu       $t7, $t7, -0x4510
    ctx->r15 = ADD32(ctx->r15, -0X4510);
    // 0x800C36F8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C36FC: jr          $ra
    // 0x800C3700: sw          $t7, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r15;
    return;
    // 0x800C3700: sw          $t7, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r15;
;}
RECOMP_FUNC void func_800C3704(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3704: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x800C3708: lw          $t6, -0x4528($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4528);
    // 0x800C370C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C3710: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x800C3714: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x800C3718: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800C371C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800C3720: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800C3724: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800C3728: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800C372C: sw          $zero, -0x4524($at)
    MEM_W(-0X4524, ctx->r1) = 0;
    // 0x800C3730: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x800C3734: addiu       $t8, $t8, 0x3AF8
    ctx->r24 = ADD32(ctx->r24, 0X3AF8);
    // 0x800C3738: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800C373C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C3740: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x800C3744: sw          $t9, 0x3AF0($at)
    MEM_W(0X3AF0, ctx->r1) = ctx->r25;
    // 0x800C3748: addiu       $t1, $t1, -0x4510
    ctx->r9 = ADD32(ctx->r9, -0X4510);
    // 0x800C374C: sll         $t0, $t6, 14
    ctx->r8 = S32(ctx->r14 << 14);
    // 0x800C3750: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x800C3754: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C3758: jr          $ra
    // 0x800C375C: sw          $t2, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r10;
    return;
    // 0x800C375C: sw          $t2, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r10;
;}
RECOMP_FUNC void func_800C3760(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3760: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C3764: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C3768: jal         0x800C3338
    // 0x800C376C: nop

    func_800C3338(rdram, ctx);
        goto after_0;
    // 0x800C376C: nop

    after_0:
    // 0x800C3770: jal         0x800C7E1C
    // 0x800C3774: nop

    func_800C7E1C(rdram, ctx);
        goto after_1;
    // 0x800C3774: nop

    after_1:
    // 0x800C3778: jal         0x800C336C
    // 0x800C377C: nop

    func_800C336C(rdram, ctx);
        goto after_2;
    // 0x800C377C: nop

    after_2:
    // 0x800C3780: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x800C3784: lw          $t6, -0x4514($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4514);
    // 0x800C3788: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C378C: lui         $t8, 0xE900
    ctx->r24 = S32(0XE900 << 16);
    // 0x800C3790: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x800C3794: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800C3798: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800C379C: sw          $t7, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r15;
    // 0x800C37A0: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x800C37A4: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800C37A8: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x800C37AC: lui         $t3, 0xDF00
    ctx->r11 = S32(0XDF00 << 16);
    // 0x800C37B0: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x800C37B4: lw          $t1, -0x4514($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4514);
    // 0x800C37B8: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x800C37BC: lui         $t0, 0x8011
    ctx->r8 = S32(0X8011 << 16);
    // 0x800C37C0: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x800C37C4: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x800C37C8: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x800C37CC: sw          $t2, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r10;
    // 0x800C37D0: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x800C37D4: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x800C37D8: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x800C37DC: addiu       $t8, $t8, -0x4510
    ctx->r24 = ADD32(ctx->r24, -0X4510);
    // 0x800C37E0: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
    // 0x800C37E4: lw          $t6, -0x4528($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4528);
    // 0x800C37E8: lw          $t0, -0x4514($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X4514);
    // 0x800C37EC: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x800C37F0: sll         $t7, $t6, 14
    ctx->r15 = S32(ctx->r14 << 14);
    // 0x800C37F4: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800C37F8: subu        $a1, $t0, $t9
    ctx->r5 = SUB32(ctx->r8, ctx->r25);
    // 0x800C37FC: sra         $t1, $a1, 3
    ctx->r9 = S32(SIGNED(ctx->r5) >> 3);
    // 0x800C3800: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x800C3804: sll         $t2, $a1, 3
    ctx->r10 = S32(ctx->r5 << 3);
    // 0x800C3808: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    // 0x800C380C: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x800C3810: lw          $a2, -0x452C($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X452C);
    // 0x800C3814: jal         0x800D1BB4
    // 0x800C3818: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800D1BB4(rdram, ctx);
        goto after_3;
    // 0x800C3818: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
    // 0x800C381C: jal         0x800CB4FC
    // 0x800C3820: nop

    func_800CB4FC(rdram, ctx);
        goto after_4;
    // 0x800C3820: nop

    after_4:
    // 0x800C3824: lui         $t3, 0x8011
    ctx->r11 = S32(0X8011 << 16);
    // 0x800C3828: lw          $t3, -0x4528($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4528);
    // 0x800C382C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C3830: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C3834: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800C3838: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x800C383C: sw          $t5, -0x4528($at)
    MEM_W(-0X4528, ctx->r1) = ctx->r13;
    // 0x800C3840: jr          $ra
    // 0x800C3844: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800C3844: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800C3848(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3848: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C384C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C3850: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800C3854: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C3858: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x800C385C: lw          $t8, 0x14($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X14);
    // 0x800C3860: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x800C3864: jal         0x800D63E0
    // 0x800C3868: subu        $a1, $t8, $t7
    ctx->r5 = SUB32(ctx->r24, ctx->r15);
    osInvalICache_recomp(rdram, ctx);
        goto after_0;
    // 0x800C3868: subu        $a1, $t8, $t7
    ctx->r5 = SUB32(ctx->r24, ctx->r15);
    after_0:
    // 0x800C386C: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x800C3870: lw          $t0, 0x18($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X18);
    // 0x800C3874: lw          $t1, 0x1C($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X1C);
    // 0x800C3878: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x800C387C: jal         0x800D6460
    // 0x800C3880: subu        $a1, $t1, $t0
    ctx->r5 = SUB32(ctx->r9, ctx->r8);
    osInvalDCache_recomp(rdram, ctx);
        goto after_1;
    // 0x800C3880: subu        $a1, $t1, $t0
    ctx->r5 = SUB32(ctx->r9, ctx->r8);
    after_1:
    // 0x800C3884: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x800C3888: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x800C388C: lw          $t4, 0xC($t2)
    ctx->r12 = MEM_W(ctx->r10, 0XC);
    // 0x800C3890: lw          $a1, 0x0($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X0);
    // 0x800C3894: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    // 0x800C3898: jal         0x800D1D10
    // 0x800C389C: subu        $a2, $t4, $t3
    ctx->r6 = SUB32(ctx->r12, ctx->r11);
    func_800D1D10(rdram, ctx);
        goto after_2;
    // 0x800C389C: subu        $a2, $t4, $t3
    ctx->r6 = SUB32(ctx->r12, ctx->r11);
    after_2:
    // 0x800C38A0: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x800C38A4: lw          $t6, 0x20($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X20);
    // 0x800C38A8: lw          $t8, 0x24($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X24);
    // 0x800C38AC: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800C38B0: jal         0x800D6510
    // 0x800C38B4: subu        $a1, $t8, $t6
    ctx->r5 = SUB32(ctx->r24, ctx->r14);
    _bzero_recomp(rdram, ctx);
        goto after_3;
    // 0x800C38B4: subu        $a1, $t8, $t6
    ctx->r5 = SUB32(ctx->r24, ctx->r14);
    after_3:
    // 0x800C38B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C38BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C38C0: jr          $ra
    // 0x800C38C4: nop

    return;
    // 0x800C38C4: nop

;}
RECOMP_FUNC void func_800C38C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C38C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C38CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C38D0: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800C38D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C38D8: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x800C38DC: lw          $t8, 0x14($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X14);
    // 0x800C38E0: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x800C38E4: jal         0x800D63E0
    // 0x800C38E8: subu        $a1, $t8, $t7
    ctx->r5 = SUB32(ctx->r24, ctx->r15);
    osInvalICache_recomp(rdram, ctx);
        goto after_0;
    // 0x800C38E8: subu        $a1, $t8, $t7
    ctx->r5 = SUB32(ctx->r24, ctx->r15);
    after_0:
    // 0x800C38EC: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x800C38F0: lw          $t0, 0x18($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X18);
    // 0x800C38F4: lw          $t1, 0x1C($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X1C);
    // 0x800C38F8: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x800C38FC: jal         0x800D6460
    // 0x800C3900: subu        $a1, $t1, $t0
    ctx->r5 = SUB32(ctx->r9, ctx->r8);
    osInvalDCache_recomp(rdram, ctx);
        goto after_1;
    // 0x800C3900: subu        $a1, $t1, $t0
    ctx->r5 = SUB32(ctx->r9, ctx->r8);
    after_1:
    // 0x800C3904: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x800C3908: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x800C390C: lw          $t4, 0xC($t2)
    ctx->r12 = MEM_W(ctx->r10, 0XC);
    // 0x800C3910: lw          $a1, 0x0($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X0);
    // 0x800C3914: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    // 0x800C3918: jal         0x800D1D10
    // 0x800C391C: subu        $a2, $t4, $t3
    ctx->r6 = SUB32(ctx->r12, ctx->r11);
    func_800D1D10(rdram, ctx);
        goto after_2;
    // 0x800C391C: subu        $a2, $t4, $t3
    ctx->r6 = SUB32(ctx->r12, ctx->r11);
    after_2:
    // 0x800C3920: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C3924: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C3928: jr          $ra
    // 0x800C392C: nop

    return;
    // 0x800C392C: nop

;}
RECOMP_FUNC void func_800C3930(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3930: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C3934: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C3938: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800C393C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C3940: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x800C3944: lw          $t8, 0xC($t6)
    ctx->r24 = MEM_W(ctx->r14, 0XC);
    // 0x800C3948: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    // 0x800C394C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x800C3950: jal         0x800D1D10
    // 0x800C3954: subu        $a2, $t8, $t7
    ctx->r6 = SUB32(ctx->r24, ctx->r15);
    func_800D1D10(rdram, ctx);
        goto after_0;
    // 0x800C3954: subu        $a2, $t8, $t7
    ctx->r6 = SUB32(ctx->r24, ctx->r15);
    after_0:
    // 0x800C3958: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C395C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C3960: jr          $ra
    // 0x800C3964: nop

    return;
    // 0x800C3964: nop

;}
RECOMP_FUNC void func_800C3968(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3968: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C396C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C3970: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800C3974: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C3978: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x800C397C: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x800C3980: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    // 0x800C3984: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x800C3988: jal         0x800D1D10
    // 0x800C398C: subu        $a2, $t8, $t7
    ctx->r6 = SUB32(ctx->r24, ctx->r15);
    func_800D1D10(rdram, ctx);
        goto after_0;
    // 0x800C398C: subu        $a2, $t8, $t7
    ctx->r6 = SUB32(ctx->r24, ctx->r15);
    after_0:
    // 0x800C3990: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C3994: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C3998: jr          $ra
    // 0x800C399C: nop

    return;
    // 0x800C399C: nop

;}
RECOMP_FUNC void func_800C39A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C39A0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C39A4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x800C39A8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800C39AC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800C39B0: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x800C39B4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800C39B8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800C39BC: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x800C39C0: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x800C39C4: addiu       $t0, $a0, 0x1
    ctx->r8 = ADD32(ctx->r4, 0X1);
    // 0x800C39C8: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x800C39CC: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x800C39D0: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x800C39D4: lbu         $t1, 0x0($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X0);
    // 0x800C39D8: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800C39DC: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x800C39E0: andi        $t3, $t1, 0xFF
    ctx->r11 = ctx->r9 & 0XFF;
    // 0x800C39E4: sll         $t4, $t3, 8
    ctx->r12 = S32(ctx->r11 << 8);
    // 0x800C39E8: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x800C39EC: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x800C39F0: addiu       $t7, $a0, 0x2
    ctx->r15 = ADD32(ctx->r4, 0X2);
    // 0x800C39F4: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x800C39F8: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x800C39FC: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x800C3A00: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x800C3A04: andi        $t0, $t8, 0xFF
    ctx->r8 = ctx->r24 & 0XFF;
    // 0x800C3A08: sll         $t2, $t0, 16
    ctx->r10 = S32(ctx->r8 << 16);
    // 0x800C3A0C: addu        $t1, $t2, $t6
    ctx->r9 = ADD32(ctx->r10, ctx->r14);
    // 0x800C3A10: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x800C3A14: addiu       $t3, $a0, 0x3
    ctx->r11 = ADD32(ctx->r4, 0X3);
    // 0x800C3A18: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x800C3A1C: lbu         $t4, 0x0($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X0);
    // 0x800C3A20: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x800C3A24: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x800C3A28: andi        $t7, $t4, 0xFF
    ctx->r15 = ctx->r12 & 0XFF;
    // 0x800C3A2C: sll         $t9, $t7, 24
    ctx->r25 = S32(ctx->r15 << 24);
    // 0x800C3A30: addu        $t8, $t9, $t1
    ctx->r24 = ADD32(ctx->r25, ctx->r9);
    // 0x800C3A34: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x800C3A38: sh          $zero, 0xA($sp)
    MEM_H(0XA, ctx->r29) = 0;
    // 0x800C3A3C: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
L_800C3A40:
    // 0x800C3A40: lh          $t2, 0xA($sp)
    ctx->r10 = MEM_H(ctx->r29, 0XA);
    // 0x800C3A44: lh          $t0, 0xA($sp)
    ctx->r8 = MEM_H(ctx->r29, 0XA);
    // 0x800C3A48: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C3A4C: addiu       $t6, $t2, 0x1
    ctx->r14 = ADD32(ctx->r10, 0X1);
    // 0x800C3A50: sll         $t3, $t6, 16
    ctx->r11 = S32(ctx->r14 << 16);
    // 0x800C3A54: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x800C3A58: sb          $zero, -0x3E68($at)
    MEM_B(-0X3E68, ctx->r1) = 0;
    // 0x800C3A5C: sra         $t5, $t3, 16
    ctx->r13 = S32(SIGNED(ctx->r11) >> 16);
    // 0x800C3A60: slti        $at, $t5, 0x1012
    ctx->r1 = SIGNED(ctx->r13) < 0X1012 ? 1 : 0;
    // 0x800C3A64: bne         $at, $zero, L_800C3A40
    if (ctx->r1 != 0) {
        // 0x800C3A68: sh          $t6, 0xA($sp)
        MEM_H(0XA, ctx->r29) = ctx->r14;
            goto L_800C3A40;
    }
    // 0x800C3A68: sh          $t6, 0xA($sp)
    MEM_H(0XA, ctx->r29) = ctx->r14;
    // 0x800C3A6C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800C3A70: addiu       $t4, $zero, 0xFEE
    ctx->r12 = ADD32(0, 0XFEE);
    // 0x800C3A74: sh          $t4, 0x4($sp)
    MEM_H(0X4, ctx->r29) = ctx->r12;
    // 0x800C3A78: beq         $t7, $zero, L_800C3C18
    if (ctx->r15 == 0) {
        // 0x800C3A7C: sw          $zero, 0xC($sp)
        MEM_W(0XC, ctx->r29) = 0;
            goto L_800C3C18;
    }
    // 0x800C3A7C: sw          $zero, 0xC($sp)
    MEM_W(0XC, ctx->r29) = 0;
L_800C3A80:
    // 0x800C3A80: lw          $t9, 0xC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC);
    // 0x800C3A84: srl         $t1, $t9, 1
    ctx->r9 = S32(U32(ctx->r25) >> 1);
    // 0x800C3A88: andi        $t8, $t1, 0x100
    ctx->r24 = ctx->r9 & 0X100;
    // 0x800C3A8C: bne         $t8, $zero, L_800C3AB0
    if (ctx->r24 != 0) {
        // 0x800C3A90: sw          $t1, 0xC($sp)
        MEM_W(0XC, ctx->r29) = ctx->r9;
            goto L_800C3AB0;
    }
    // 0x800C3A90: sw          $t1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r9;
    // 0x800C3A94: lw          $t0, 0x14($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X14);
    // 0x800C3A98: addu        $t2, $t0, $a0
    ctx->r10 = ADD32(ctx->r8, ctx->r4);
    // 0x800C3A9C: lbu         $t6, 0x0($t2)
    ctx->r14 = MEM_BU(ctx->r10, 0X0);
    // 0x800C3AA0: addiu       $t5, $t0, 0x1
    ctx->r13 = ADD32(ctx->r8, 0X1);
    // 0x800C3AA4: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x800C3AA8: ori         $t3, $t6, 0xFF00
    ctx->r11 = ctx->r14 | 0XFF00;
    // 0x800C3AAC: sw          $t3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r11;
L_800C3AB0:
    // 0x800C3AB0: lw          $t4, 0xC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC);
    // 0x800C3AB4: andi        $t7, $t4, 0x1
    ctx->r15 = ctx->r12 & 0X1;
    // 0x800C3AB8: beq         $t7, $zero, L_800C3B20
    if (ctx->r15 == 0) {
        // 0x800C3ABC: nop
    
            goto L_800C3B20;
    }
    // 0x800C3ABC: nop

    // 0x800C3AC0: lw          $t9, 0x14($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X14);
    // 0x800C3AC4: lw          $t8, 0x10($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X10);
    // 0x800C3AC8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C3ACC: addu        $t1, $t9, $a0
    ctx->r9 = ADD32(ctx->r25, ctx->r4);
    // 0x800C3AD0: lbu         $a2, 0x0($t1)
    ctx->r6 = MEM_BU(ctx->r9, 0X0);
    // 0x800C3AD4: addu        $t2, $a1, $t8
    ctx->r10 = ADD32(ctx->r5, ctx->r24);
    // 0x800C3AD8: sb          $a2, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r6;
    // 0x800C3ADC: lh          $t3, 0x4($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X4);
    // 0x800C3AE0: lh          $t6, 0x4($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X4);
    // 0x800C3AE4: lw          $t7, 0x14($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X14);
    // 0x800C3AE8: lw          $t5, 0x10($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X10);
    // 0x800C3AEC: addiu       $t0, $t3, 0x1
    ctx->r8 = ADD32(ctx->r11, 0X1);
    // 0x800C3AF0: sll         $t1, $t0, 16
    ctx->r9 = S32(ctx->r8 << 16);
    // 0x800C3AF4: sra         $t8, $t1, 16
    ctx->r24 = S32(SIGNED(ctx->r9) >> 16);
    // 0x800C3AF8: sh          $t0, 0x4($sp)
    MEM_H(0X4, ctx->r29) = ctx->r8;
    // 0x800C3AFC: andi        $t2, $t8, 0xFFF
    ctx->r10 = ctx->r24 & 0XFFF;
    // 0x800C3B00: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800C3B04: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x800C3B08: addiu       $t4, $t5, 0x1
    ctx->r12 = ADD32(ctx->r13, 0X1);
    // 0x800C3B0C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800C3B10: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x800C3B14: sh          $t2, 0x4($sp)
    MEM_H(0X4, ctx->r29) = ctx->r10;
    // 0x800C3B18: b           L_800C3C00
    // 0x800C3B1C: sb          $a2, -0x3E68($at)
    MEM_B(-0X3E68, ctx->r1) = ctx->r6;
        goto L_800C3C00;
    // 0x800C3B1C: sb          $a2, -0x3E68($at)
    MEM_B(-0X3E68, ctx->r1) = ctx->r6;
L_800C3B20:
    // 0x800C3B20: lw          $t6, 0x14($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X14);
    // 0x800C3B24: addu        $t3, $t6, $a0
    ctx->r11 = ADD32(ctx->r14, ctx->r4);
    // 0x800C3B28: lbu         $t5, 0x0($t3)
    ctx->r13 = MEM_BU(ctx->r11, 0X0);
    // 0x800C3B2C: addiu       $t4, $t6, 0x1
    ctx->r12 = ADD32(ctx->r14, 0X1);
    // 0x800C3B30: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x800C3B34: addu        $t7, $t4, $a0
    ctx->r15 = ADD32(ctx->r12, ctx->r4);
    // 0x800C3B38: sh          $t5, 0xA($sp)
    MEM_H(0XA, ctx->r29) = ctx->r13;
    // 0x800C3B3C: lbu         $t9, 0x0($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X0);
    // 0x800C3B40: lh          $t1, 0xA($sp)
    ctx->r9 = MEM_H(ctx->r29, 0XA);
    // 0x800C3B44: addiu       $t0, $t4, 0x1
    ctx->r8 = ADD32(ctx->r12, 0X1);
    // 0x800C3B48: sh          $t9, 0x8($sp)
    MEM_H(0X8, ctx->r29) = ctx->r25;
    // 0x800C3B4C: lh          $t8, 0x8($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X8);
    // 0x800C3B50: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x800C3B54: sh          $zero, 0x6($sp)
    MEM_H(0X6, ctx->r29) = 0;
    // 0x800C3B58: andi        $t6, $t8, 0xF
    ctx->r14 = ctx->r24 & 0XF;
    // 0x800C3B5C: addiu       $t7, $t6, 0x2
    ctx->r15 = ADD32(ctx->r14, 0X2);
    // 0x800C3B60: andi        $t2, $t8, 0xF0
    ctx->r10 = ctx->r24 & 0XF0;
    // 0x800C3B64: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x800C3B68: sll         $t9, $t7, 16
    ctx->r25 = S32(ctx->r15 << 16);
    // 0x800C3B6C: sra         $t4, $t9, 16
    ctx->r12 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800C3B70: or          $t5, $t1, $t3
    ctx->r13 = ctx->r9 | ctx->r11;
    // 0x800C3B74: sh          $t5, 0xA($sp)
    MEM_H(0XA, ctx->r29) = ctx->r13;
    // 0x800C3B78: bltz        $t4, L_800C3C00
    if (SIGNED(ctx->r12) < 0) {
        // 0x800C3B7C: sh          $t7, 0x8($sp)
        MEM_H(0X8, ctx->r29) = ctx->r15;
            goto L_800C3C00;
    }
    // 0x800C3B7C: sh          $t7, 0x8($sp)
    MEM_H(0X8, ctx->r29) = ctx->r15;
L_800C3B80:
    // 0x800C3B80: lh          $t0, 0xA($sp)
    ctx->r8 = MEM_H(ctx->r29, 0XA);
    // 0x800C3B84: lh          $t2, 0x6($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X6);
    // 0x800C3B88: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800C3B8C: lw          $t5, 0x10($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X10);
    // 0x800C3B90: addu        $t1, $t0, $t2
    ctx->r9 = ADD32(ctx->r8, ctx->r10);
    // 0x800C3B94: andi        $t3, $t1, 0xFFF
    ctx->r11 = ctx->r9 & 0XFFF;
    // 0x800C3B98: addu        $a2, $a2, $t3
    ctx->r6 = ADD32(ctx->r6, ctx->r11);
    // 0x800C3B9C: lbu         $a2, -0x3E68($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X3E68);
    // 0x800C3BA0: addu        $t8, $a1, $t5
    ctx->r24 = ADD32(ctx->r5, ctx->r13);
    // 0x800C3BA4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C3BA8: sb          $a2, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r6;
    // 0x800C3BAC: lw          $t4, 0x10($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X10);
    // 0x800C3BB0: lh          $t5, 0x6($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X6);
    // 0x800C3BB4: lh          $t6, 0x4($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X4);
    // 0x800C3BB8: lh          $t7, 0x4($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X4);
    // 0x800C3BBC: addiu       $t0, $t4, 0x1
    ctx->r8 = ADD32(ctx->r12, 0X1);
    // 0x800C3BC0: lh          $t4, 0x8($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X8);
    // 0x800C3BC4: addiu       $t8, $t5, 0x1
    ctx->r24 = ADD32(ctx->r13, 0X1);
    // 0x800C3BC8: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800C3BCC: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x800C3BD0: sll         $t6, $t8, 16
    ctx->r14 = S32(ctx->r24 << 16);
    // 0x800C3BD4: sll         $t2, $t9, 16
    ctx->r10 = S32(ctx->r25 << 16);
    // 0x800C3BD8: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800C3BDC: sra         $t1, $t2, 16
    ctx->r9 = S32(SIGNED(ctx->r10) >> 16);
    // 0x800C3BE0: sb          $a2, -0x3E68($at)
    MEM_B(-0X3E68, ctx->r1) = ctx->r6;
    // 0x800C3BE4: sh          $t9, 0x4($sp)
    MEM_H(0X4, ctx->r29) = ctx->r25;
    // 0x800C3BE8: andi        $t3, $t1, 0xFFF
    ctx->r11 = ctx->r9 & 0XFFF;
    // 0x800C3BEC: slt         $at, $t4, $t7
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800C3BF0: sh          $t8, 0x6($sp)
    MEM_H(0X6, ctx->r29) = ctx->r24;
    // 0x800C3BF4: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800C3BF8: beq         $at, $zero, L_800C3B80
    if (ctx->r1 == 0) {
        // 0x800C3BFC: sh          $t3, 0x4($sp)
        MEM_H(0X4, ctx->r29) = ctx->r11;
            goto L_800C3B80;
    }
    // 0x800C3BFC: sh          $t3, 0x4($sp)
    MEM_H(0X4, ctx->r29) = ctx->r11;
L_800C3C00:
    // 0x800C3C00: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800C3C04: addiu       $t9, $t0, -0x1
    ctx->r25 = ADD32(ctx->r8, -0X1);
    // 0x800C3C08: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x800C3C0C: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x800C3C10: bne         $t2, $zero, L_800C3A80
    if (ctx->r10 != 0) {
        // 0x800C3C14: nop
    
            goto L_800C3A80;
    }
    // 0x800C3C14: nop

L_800C3C18:
    // 0x800C3C18: jr          $ra
    // 0x800C3C1C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800C3C1C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800C3C20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3C20: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800C3C24: sw          $zero, 0xC($sp)
    MEM_W(0XC, ctx->r29) = 0;
L_800C3C28:
    // 0x800C3C28: lw          $t6, 0xC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC);
    // 0x800C3C2C: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x800C3C30: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800C3C34: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800C3C38: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x800C3C3C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800C3C40: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x800C3C44: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x800C3C48: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C3C4C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800C3C50: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x800C3C54: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x800C3C58: addiu       $t0, $t0, -0x4198
    ctx->r8 = ADD32(ctx->r8, -0X4198);
    // 0x800C3C5C: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800C3C60: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x800C3C64: swc1        $f4, -0x4190($at)
    MEM_W(-0X4190, ctx->r1) = ctx->f4.u32l;
    // 0x800C3C68: lwc1        $f12, 0x8($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, 0X8);
    // 0x800C3C6C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C3C70: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800C3C74: swc1        $f12, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->f12.u32l;
    // 0x800C3C78: lw          $t2, 0xC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC);
    // 0x800C3C7C: lw          $t4, 0xC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC);
    // 0x800C3C80: lw          $t6, 0xC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC);
    // 0x800C3C84: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x800C3C88: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x800C3C8C: sll         $t3, $t3, 4
    ctx->r11 = S32(ctx->r11 << 4);
    // 0x800C3C90: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x800C3C94: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x800C3C98: swc1        $f12, -0x4198($at)
    MEM_W(-0X4198, ctx->r1) = ctx->f12.u32l;
    // 0x800C3C9C: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x800C3CA0: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x800C3CA4: sll         $t5, $t5, 4
    ctx->r13 = S32(ctx->r13 << 4);
    // 0x800C3CA8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C3CAC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800C3CB0: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800C3CB4: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x800C3CB8: addiu       $t8, $t8, -0x4198
    ctx->r24 = ADD32(ctx->r24, -0X4198);
    // 0x800C3CBC: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x800C3CC0: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800C3CC4: swc1        $f6, -0x4184($at)
    MEM_W(-0X4184, ctx->r1) = ctx->f6.u32l;
    // 0x800C3CC8: lwc1        $f12, 0x14($t9)
    ctx->f12.u32l = MEM_W(ctx->r25, 0X14);
    // 0x800C3CCC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C3CD0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800C3CD4: swc1        $f12, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->f12.u32l;
    // 0x800C3CD8: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x800C3CDC: lw          $t2, 0xC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC);
    // 0x800C3CE0: lw          $t4, 0xC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC);
    // 0x800C3CE4: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x800C3CE8: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x800C3CEC: sll         $t1, $t1, 4
    ctx->r9 = S32(ctx->r9 << 4);
    // 0x800C3CF0: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x800C3CF4: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x800C3CF8: swc1        $f12, -0x418C($at)
    MEM_W(-0X418C, ctx->r1) = ctx->f12.u32l;
    // 0x800C3CFC: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x800C3D00: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x800C3D04: sll         $t3, $t3, 4
    ctx->r11 = S32(ctx->r11 << 4);
    // 0x800C3D08: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C3D0C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800C3D10: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x800C3D14: sll         $t5, $t5, 4
    ctx->r13 = S32(ctx->r13 << 4);
    // 0x800C3D18: addiu       $t6, $t6, -0x4198
    ctx->r14 = ADD32(ctx->r14, -0X4198);
    // 0x800C3D1C: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x800C3D20: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x800C3D24: swc1        $f8, -0x4178($at)
    MEM_W(-0X4178, ctx->r1) = ctx->f8.u32l;
    // 0x800C3D28: lwc1        $f10, 0x20($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X20);
    // 0x800C3D2C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C3D30: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800C3D34: swc1        $f10, 0x18($t7)
    MEM_W(0X18, ctx->r15) = ctx->f10.u32l;
    // 0x800C3D38: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x800C3D3C: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x800C3D40: lw          $t2, 0xC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC);
    // 0x800C3D44: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x800C3D48: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x800C3D4C: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x800C3D50: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C3D54: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800C3D58: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x800C3D5C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800C3D60: swc1        $f16, -0x417C($at)
    MEM_W(-0X417C, ctx->r1) = ctx->f16.u32l;
    // 0x800C3D64: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x800C3D68: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x800C3D6C: sll         $t1, $t1, 4
    ctx->r9 = S32(ctx->r9 << 4);
    // 0x800C3D70: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C3D74: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800C3D78: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x800C3D7C: sll         $t3, $t3, 4
    ctx->r11 = S32(ctx->r11 << 4);
    // 0x800C3D80: addiu       $t4, $t4, -0x4198
    ctx->r12 = ADD32(ctx->r12, -0X4198);
    // 0x800C3D84: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x800C3D88: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x800C3D8C: swc1        $f18, -0x416C($at)
    MEM_W(-0X416C, ctx->r1) = ctx->f18.u32l;
    // 0x800C3D90: lwc1        $f12, 0x2C($t5)
    ctx->f12.u32l = MEM_W(ctx->r13, 0X2C);
    // 0x800C3D94: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C3D98: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800C3D9C: swc1        $f12, 0x28($t5)
    MEM_W(0X28, ctx->r13) = ctx->f12.u32l;
    // 0x800C3DA0: lw          $t6, 0xC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC);
    // 0x800C3DA4: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x800C3DA8: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x800C3DAC: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x800C3DB0: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800C3DB4: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x800C3DB8: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800C3DBC: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x800C3DC0: swc1        $f12, -0x4174($at)
    MEM_W(-0X4174, ctx->r1) = ctx->f12.u32l;
    // 0x800C3DC4: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x800C3DC8: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x800C3DCC: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x800C3DD0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C3DD4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800C3DD8: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x800C3DDC: sll         $t1, $t1, 4
    ctx->r9 = S32(ctx->r9 << 4);
    // 0x800C3DE0: addiu       $t2, $t2, -0x4198
    ctx->r10 = ADD32(ctx->r10, -0X4198);
    // 0x800C3DE4: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800C3DE8: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x800C3DEC: swc1        $f4, -0x415C($at)
    MEM_W(-0X415C, ctx->r1) = ctx->f4.u32l;
    // 0x800C3DF0: lwc1        $f14, 0x3C($t3)
    ctx->f14.u32l = MEM_W(ctx->r11, 0X3C);
    // 0x800C3DF4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C3DF8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800C3DFC: swc1        $f14, 0x38($t3)
    MEM_W(0X38, ctx->r11) = ctx->f14.u32l;
    // 0x800C3E00: lw          $t4, 0xC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC);
    // 0x800C3E04: lw          $t6, 0xC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC);
    // 0x800C3E08: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x800C3E0C: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x800C3E10: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x800C3E14: sll         $t5, $t5, 4
    ctx->r13 = S32(ctx->r13 << 4);
    // 0x800C3E18: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x800C3E1C: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    // 0x800C3E20: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x800C3E24: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x800C3E28: swc1        $f12, -0x4164($at)
    MEM_W(-0X4164, ctx->r1) = ctx->f12.u32l;
    // 0x800C3E2C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800C3E30: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x800C3E34: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C3E38: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800C3E3C: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x800C3E40: swc1        $f12, -0x4168($at)
    MEM_W(-0X4168, ctx->r1) = ctx->f12.u32l;
    // 0x800C3E44: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x800C3E48: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x800C3E4C: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x800C3E50: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C3E54: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800C3E58: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x800C3E5C: sll         $t1, $t1, 4
    ctx->r9 = S32(ctx->r9 << 4);
    // 0x800C3E60: addiu       $t2, $t2, -0x4198
    ctx->r10 = ADD32(ctx->r10, -0X4198);
    // 0x800C3E64: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800C3E68: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x800C3E6C: swc1        $f6, -0x414C($at)
    MEM_W(-0X414C, ctx->r1) = ctx->f6.u32l;
    // 0x800C3E70: lwc1        $f14, 0x4C($t3)
    ctx->f14.u32l = MEM_W(ctx->r11, 0X4C);
    // 0x800C3E74: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C3E78: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800C3E7C: swc1        $f14, 0x48($t3)
    MEM_W(0X48, ctx->r11) = ctx->f14.u32l;
    // 0x800C3E80: lw          $t4, 0xC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC);
    // 0x800C3E84: lw          $t6, 0xC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC);
    // 0x800C3E88: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x800C3E8C: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x800C3E90: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x800C3E94: sll         $t5, $t5, 4
    ctx->r13 = S32(ctx->r13 << 4);
    // 0x800C3E98: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x800C3E9C: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    // 0x800C3EA0: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x800C3EA4: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x800C3EA8: swc1        $f12, -0x4154($at)
    MEM_W(-0X4154, ctx->r1) = ctx->f12.u32l;
    // 0x800C3EAC: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800C3EB0: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x800C3EB4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C3EB8: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800C3EBC: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x800C3EC0: swc1        $f12, -0x4158($at)
    MEM_W(-0X4158, ctx->r1) = ctx->f12.u32l;
    // 0x800C3EC4: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x800C3EC8: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x800C3ECC: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x800C3ED0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C3ED4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800C3ED8: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x800C3EDC: sll         $t1, $t1, 4
    ctx->r9 = S32(ctx->r9 << 4);
    // 0x800C3EE0: addiu       $t2, $t2, -0x4198
    ctx->r10 = ADD32(ctx->r10, -0X4198);
    // 0x800C3EE4: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800C3EE8: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x800C3EEC: swc1        $f8, -0x413C($at)
    MEM_W(-0X413C, ctx->r1) = ctx->f8.u32l;
    // 0x800C3EF0: lwc1        $f14, 0x5C($t3)
    ctx->f14.u32l = MEM_W(ctx->r11, 0X5C);
    // 0x800C3EF4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C3EF8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800C3EFC: swc1        $f14, 0x58($t3)
    MEM_W(0X58, ctx->r11) = ctx->f14.u32l;
    // 0x800C3F00: lw          $t4, 0xC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC);
    // 0x800C3F04: lw          $t6, 0xC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC);
    // 0x800C3F08: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x800C3F0C: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x800C3F10: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x800C3F14: sll         $t5, $t5, 4
    ctx->r13 = S32(ctx->r13 << 4);
    // 0x800C3F18: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x800C3F1C: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    // 0x800C3F20: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x800C3F24: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x800C3F28: swc1        $f12, -0x4144($at)
    MEM_W(-0X4144, ctx->r1) = ctx->f12.u32l;
    // 0x800C3F2C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800C3F30: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x800C3F34: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C3F38: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800C3F3C: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x800C3F40: swc1        $f12, -0x4148($at)
    MEM_W(-0X4148, ctx->r1) = ctx->f12.u32l;
    // 0x800C3F44: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x800C3F48: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x800C3F4C: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x800C3F50: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C3F54: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800C3F58: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x800C3F5C: sll         $t1, $t1, 4
    ctx->r9 = S32(ctx->r9 << 4);
    // 0x800C3F60: addiu       $t2, $t2, -0x4198
    ctx->r10 = ADD32(ctx->r10, -0X4198);
    // 0x800C3F64: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800C3F68: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x800C3F6C: swc1        $f10, -0x412C($at)
    MEM_W(-0X412C, ctx->r1) = ctx->f10.u32l;
    // 0x800C3F70: lwc1        $f14, 0x6C($t3)
    ctx->f14.u32l = MEM_W(ctx->r11, 0X6C);
    // 0x800C3F74: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C3F78: swc1        $f14, 0x68($t3)
    MEM_W(0X68, ctx->r11) = ctx->f14.u32l;
    // 0x800C3F7C: lw          $t4, 0xC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC);
    // 0x800C3F80: lw          $t6, 0xC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC);
    // 0x800C3F84: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    // 0x800C3F88: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x800C3F8C: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x800C3F90: sll         $t5, $t5, 4
    ctx->r13 = S32(ctx->r13 << 4);
    // 0x800C3F94: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x800C3F98: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x800C3F9C: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x800C3FA0: swc1        $f12, -0x4134($at)
    MEM_W(-0X4134, ctx->r1) = ctx->f12.u32l;
    // 0x800C3FA4: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800C3FA8: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x800C3FAC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C3FB0: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800C3FB4: swc1        $f12, -0x4138($at)
    MEM_W(-0X4138, ctx->r1) = ctx->f12.u32l;
    // 0x800C3FB8: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800C3FBC: sltiu       $at, $t9, 0x4
    ctx->r1 = ctx->r25 < 0X4 ? 1 : 0;
    // 0x800C3FC0: bne         $at, $zero, L_800C3C28
    if (ctx->r1 != 0) {
        // 0x800C3FC4: sw          $t9, 0xC($sp)
        MEM_W(0XC, ctx->r29) = ctx->r25;
            goto L_800C3C28;
    }
    // 0x800C3FC4: sw          $t9, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r25;
    // 0x800C3FC8: jr          $ra
    // 0x800C3FCC: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800C3FCC: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_800C3FD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3FD0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800C3FD4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800C3FD8: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x800C3FDC: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x800C3FE0: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
L_800C3FE4:
    // 0x800C3FE4: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x800C3FE8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800C3FEC: addiu       $t0, $t0, -0x4198
    ctx->r8 = ADD32(ctx->r8, -0X4198);
    // 0x800C3FF0: sll         $t9, $t7, 3
    ctx->r25 = S32(ctx->r15 << 3);
    // 0x800C3FF4: subu        $t9, $t9, $t7
    ctx->r25 = SUB32(ctx->r25, ctx->r15);
    // 0x800C3FF8: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x800C3FFC: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x800C4000: lwc1        $f4, 0xC($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0XC);
    // 0x800C4004: lw          $a1, 0x0($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X0);
    // 0x800C4008: lw          $a2, 0x4($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X4);
    // 0x800C400C: lw          $a3, 0x8($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X8);
    // 0x800C4010: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800C4014: lwc1        $f6, 0x10($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X10);
    // 0x800C4018: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x800C401C: lw          $t6, 0x3AF0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3AF0);
    // 0x800C4020: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x800C4024: lwc1        $f8, 0x14($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X14);
    // 0x800C4028: sll         $t8, $t7, 6
    ctx->r24 = S32(ctx->r15 << 6);
    // 0x800C402C: addu        $a0, $t6, $t8
    ctx->r4 = ADD32(ctx->r14, ctx->r24);
    // 0x800C4030: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x800C4034: lwc1        $f10, 0x18($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X18);
    // 0x800C4038: addiu       $a0, $a0, 0x70
    ctx->r4 = ADD32(ctx->r4, 0X70);
    // 0x800C403C: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x800C4040: lwc1        $f16, 0x1C($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X1C);
    // 0x800C4044: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x800C4048: lwc1        $f18, 0x20($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X20);
    // 0x800C404C: jal         0x800D6868
    // 0x800C4050: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    guLookAt_recomp(rdram, ctx);
        goto after_0;
    // 0x800C4050: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x800C4054: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x800C4058: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800C405C: sltiu       $at, $t3, 0x4
    ctx->r1 = ctx->r11 < 0X4 ? 1 : 0;
    // 0x800C4060: bne         $at, $zero, L_800C3FE4
    if (ctx->r1 != 0) {
        // 0x800C4064: sw          $t3, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r11;
            goto L_800C3FE4;
    }
    // 0x800C4064: sw          $t3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r11;
    // 0x800C4068: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800C406C: addiu       $t4, $t4, -0x4198
    ctx->r12 = ADD32(ctx->r12, -0X4198);
    // 0x800C4070: lwc1        $f4, 0x0($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X0);
    // 0x800C4074: lwc1        $f6, 0xC($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0XC);
    // 0x800C4078: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800C407C: addiu       $t5, $t5, -0x3FA8
    ctx->r13 = ADD32(ctx->r13, -0X3FA8);
    // 0x800C4080: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800C4084: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800C4088: addiu       $t6, $t6, -0x4198
    ctx->r14 = ADD32(ctx->r14, -0X4198);
    // 0x800C408C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800C4090: swc1        $f8, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f8.u32l;
    // 0x800C4094: lwc1        $f16, 0x10($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X10);
    // 0x800C4098: lwc1        $f10, 0x4($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X4);
    // 0x800C409C: addiu       $t8, $t8, -0x3FA8
    ctx->r24 = ADD32(ctx->r24, -0X3FA8);
    // 0x800C40A0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800C40A4: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800C40A8: addiu       $t7, $t7, -0x4198
    ctx->r15 = ADD32(ctx->r15, -0X4198);
    // 0x800C40AC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800C40B0: addiu       $t9, $t9, -0x3FA8
    ctx->r25 = ADD32(ctx->r25, -0X3FA8);
    // 0x800C40B4: swc1        $f18, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f18.u32l;
    // 0x800C40B8: lwc1        $f6, 0x14($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X14);
    // 0x800C40BC: lwc1        $f4, 0x8($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X8);
    // 0x800C40C0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800C40C4: addiu       $t0, $t0, -0x3FA8
    ctx->r8 = ADD32(ctx->r8, -0X3FA8);
    // 0x800C40C8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800C40CC: swc1        $f8, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f8.u32l;
    // 0x800C40D0: lwc1        $f10, 0x8($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X8);
    // 0x800C40D4: lwc1        $f18, 0x0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800C40D8: mul.s       $f16, $f10, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x800C40DC: nop

    // 0x800C40E0: mul.s       $f4, $f18, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x800C40E4: jal         0x800D68E0
    // 0x800C40E8: add.s       $f12, $f16, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x800C40E8: add.s       $f12, $f16, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f4.fl;
    after_1:
    // 0x800C40EC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800C40F0: addiu       $t1, $t1, -0x3FA8
    ctx->r9 = ADD32(ctx->r9, -0X3FA8);
    // 0x800C40F4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800C40F8: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    // 0x800C40FC: jal         0x800E4940
    // 0x800C4100: lwc1        $f12, 0x4($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, 0X4);
    func_800E4940(rdram, ctx);
        goto after_2;
    // 0x800C4100: lwc1        $f12, 0x4($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, 0X4);
    after_2:
    // 0x800C4104: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x800C4108: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800C410C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C4110: lwc1        $f10, -0x2C40($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2C40);
    // 0x800C4114: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800C4118: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800C411C: addiu       $t2, $t2, -0x4198
    ctx->r10 = ADD32(ctx->r10, -0X4198);
    // 0x800C4120: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800C4124: addiu       $t3, $t3, -0x4198
    ctx->r11 = ADD32(ctx->r11, -0X4198);
    // 0x800C4128: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800C412C: div.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800C4130: swc1        $f18, 0x24($t2)
    MEM_W(0X24, ctx->r10) = ctx->f18.u32l;
    // 0x800C4134: lwc1        $f16, 0x24($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X24);
    // 0x800C4138: c.lt.s      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.fl < ctx->f4.fl;
    // 0x800C413C: nop

    // 0x800C4140: bc1f        L_800C4158
    if (!c1cs) {
        // 0x800C4144: lui         $at, 0x43B4
        ctx->r1 = S32(0X43B4 << 16);
            goto L_800C4158;
    }
    // 0x800C4144: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x800C4148: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800C414C: nop

    // 0x800C4150: add.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x800C4154: swc1        $f8, 0x24($t3)
    MEM_W(0X24, ctx->r11) = ctx->f8.u32l;
L_800C4158:
    // 0x800C4158: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800C415C: addiu       $t4, $t4, -0x3FA8
    ctx->r12 = ADD32(ctx->r12, -0X3FA8);
    // 0x800C4160: lwc1        $f12, 0x0($t4)
    ctx->f12.u32l = MEM_W(ctx->r12, 0X0);
    // 0x800C4164: jal         0x800E4940
    // 0x800C4168: lwc1        $f14, 0x8($t4)
    ctx->f14.u32l = MEM_W(ctx->r12, 0X8);
    func_800E4940(rdram, ctx);
        goto after_3;
    // 0x800C4168: lwc1        $f14, 0x8($t4)
    ctx->f14.u32l = MEM_W(ctx->r12, 0X8);
    after_3:
    // 0x800C416C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x800C4170: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800C4174: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C4178: lwc1        $f4, -0x2C3C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2C3C);
    // 0x800C417C: mul.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x800C4180: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800C4184: addiu       $t5, $t5, -0x4198
    ctx->r13 = ADD32(ctx->r13, -0X4198);
    // 0x800C4188: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800C418C: addiu       $t6, $t6, -0x4198
    ctx->r14 = ADD32(ctx->r14, -0X4198);
    // 0x800C4190: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800C4194: div.s       $f16, $f18, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800C4198: swc1        $f16, 0x28($t5)
    MEM_W(0X28, ctx->r13) = ctx->f16.u32l;
    // 0x800C419C: lwc1        $f6, 0x28($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X28);
    // 0x800C41A0: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x800C41A4: nop

    // 0x800C41A8: bc1f        L_800C41C0
    if (!c1cs) {
        // 0x800C41AC: lui         $at, 0x43B4
        ctx->r1 = S32(0X43B4 << 16);
            goto L_800C41C0;
    }
    // 0x800C41AC: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x800C41B0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800C41B4: nop

    // 0x800C41B8: add.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800C41BC: swc1        $f18, 0x28($t6)
    MEM_W(0X28, ctx->r14) = ctx->f18.u32l;
L_800C41C0:
    // 0x800C41C0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800C41C4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800C41C8: addiu       $t8, $t8, -0x4198
    ctx->r24 = ADD32(ctx->r24, -0X4198);
    // 0x800C41CC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800C41D0: addiu       $t7, $t7, -0x4198
    ctx->r15 = ADD32(ctx->r15, -0X4198);
    // 0x800C41D4: swc1        $f4, 0x2C($t8)
    MEM_W(0X2C, ctx->r24) = ctx->f4.u32l;
    // 0x800C41D8: lwc1        $f8, 0x0($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X0);
    // 0x800C41DC: lwc1        $f16, 0xC($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0XC);
    // 0x800C41E0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800C41E4: addiu       $t9, $t9, -0x3FA8
    ctx->r25 = ADD32(ctx->r25, -0X3FA8);
    // 0x800C41E8: sub.s       $f6, $f16, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x800C41EC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800C41F0: addiu       $t0, $t0, -0x4198
    ctx->r8 = ADD32(ctx->r8, -0X4198);
    // 0x800C41F4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800C41F8: swc1        $f6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f6.u32l;
    // 0x800C41FC: lwc1        $f18, 0x4($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X4);
    // 0x800C4200: lwc1        $f10, 0x10($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X10);
    // 0x800C4204: addiu       $t1, $t1, -0x3FA8
    ctx->r9 = ADD32(ctx->r9, -0X3FA8);
    // 0x800C4208: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800C420C: sub.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x800C4210: addiu       $t2, $t2, -0x4198
    ctx->r10 = ADD32(ctx->r10, -0X4198);
    // 0x800C4214: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800C4218: addiu       $t3, $t3, -0x3FA8
    ctx->r11 = ADD32(ctx->r11, -0X3FA8);
    // 0x800C421C: swc1        $f4, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->f4.u32l;
    // 0x800C4220: lwc1        $f8, 0x8($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X8);
    // 0x800C4224: lwc1        $f16, 0x14($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X14);
    // 0x800C4228: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800C422C: addiu       $t4, $t4, -0x3FA8
    ctx->r12 = ADD32(ctx->r12, -0X3FA8);
    // 0x800C4230: sub.s       $f6, $f16, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x800C4234: swc1        $f6, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f6.u32l;
    // 0x800C4238: lwc1        $f10, 0x0($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X0);
    // 0x800C423C: lwc1        $f4, 0x4($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X4);
    // 0x800C4240: lwc1        $f6, 0x8($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X8);
    // 0x800C4244: mul.s       $f18, $f10, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x800C4248: nop

    // 0x800C424C: mul.s       $f16, $f4, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x800C4250: add.s       $f8, $f18, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x800C4254: mul.s       $f10, $f6, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x800C4258: jal         0x800D68E0
    // 0x800C425C: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_4;
    // 0x800C425C: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    after_4:
    // 0x800C4260: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C4264: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800C4268: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800C426C: addiu       $t5, $t5, -0x3FA8
    ctx->r13 = ADD32(ctx->r13, -0X3FA8);
    // 0x800C4270: div.s       $f18, $f4, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800C4274: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800C4278: addiu       $t6, $t6, -0x3FA8
    ctx->r14 = ADD32(ctx->r14, -0X3FA8);
    // 0x800C427C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800C4280: addiu       $t8, $t8, -0x3FA8
    ctx->r24 = ADD32(ctx->r24, -0X3FA8);
    // 0x800C4284: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800C4288: addiu       $t7, $t7, -0x3FA8
    ctx->r15 = ADD32(ctx->r15, -0X3FA8);
    // 0x800C428C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800C4290: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800C4294: addiu       $t0, $t0, -0x3FA8
    ctx->r8 = ADD32(ctx->r8, -0X3FA8);
    // 0x800C4298: addiu       $t9, $t9, -0x4198
    ctx->r25 = ADD32(ctx->r25, -0X4198);
    // 0x800C429C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800C42A0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800C42A4: addiu       $t2, $t2, -0x3FA8
    ctx->r10 = ADD32(ctx->r10, -0X3FA8);
    // 0x800C42A8: addiu       $t1, $t1, -0x4198
    ctx->r9 = ADD32(ctx->r9, -0X4198);
    // 0x800C42AC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800C42B0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800C42B4: addiu       $t4, $t4, -0x3FA8
    ctx->r12 = ADD32(ctx->r12, -0X3FA8);
    // 0x800C42B8: addiu       $t3, $t3, -0x4198
    ctx->r11 = ADD32(ctx->r11, -0X4198);
    // 0x800C42BC: swc1        $f18, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f18.u32l;
    // 0x800C42C0: lwc1        $f16, 0x0($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X0);
    // 0x800C42C4: lwc1        $f6, 0xC($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0XC);
    // 0x800C42C8: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800C42CC: addiu       $t5, $t5, -0x3FA8
    ctx->r13 = ADD32(ctx->r13, -0X3FA8);
    // 0x800C42D0: mul.s       $f10, $f16, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x800C42D4: swc1        $f10, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f10.u32l;
    // 0x800C42D8: lwc1        $f8, 0x4($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X4);
    // 0x800C42DC: lwc1        $f4, 0xC($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0XC);
    // 0x800C42E0: mul.s       $f18, $f8, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x800C42E4: swc1        $f18, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f18.u32l;
    // 0x800C42E8: lwc1        $f16, 0x8($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X8);
    // 0x800C42EC: lwc1        $f6, 0xC($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0XC);
    // 0x800C42F0: mul.s       $f10, $f16, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x800C42F4: swc1        $f10, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->f10.u32l;
    // 0x800C42F8: lwc1        $f4, 0x8($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X8);
    // 0x800C42FC: lwc1        $f8, 0x1C($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X1C);
    // 0x800C4300: lwc1        $f6, 0x20($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X20);
    // 0x800C4304: lwc1        $f16, 0x4($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X4);
    // 0x800C4308: mul.s       $f18, $f8, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x800C430C: nop

    // 0x800C4310: mul.s       $f10, $f16, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x800C4314: sub.s       $f8, $f18, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x800C4318: swc1        $f8, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->f8.u32l;
    // 0x800C431C: lwc1        $f16, 0x0($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X0);
    // 0x800C4320: lwc1        $f4, 0x20($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X20);
    // 0x800C4324: lwc1        $f10, 0x18($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X18);
    // 0x800C4328: lwc1        $f18, 0x8($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X8);
    // 0x800C432C: mul.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x800C4330: nop

    // 0x800C4334: mul.s       $f8, $f18, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x800C4338: sub.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800C433C: swc1        $f4, 0x10($t2)
    MEM_W(0X10, ctx->r10) = ctx->f4.u32l;
    // 0x800C4340: lwc1        $f18, 0x4($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X4);
    // 0x800C4344: lwc1        $f16, 0x18($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X18);
    // 0x800C4348: lwc1        $f8, 0x1C($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X1C);
    // 0x800C434C: lwc1        $f6, 0x0($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X0);
    // 0x800C4350: mul.s       $f10, $f16, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800C4354: nop

    // 0x800C4358: mul.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800C435C: sub.s       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x800C4360: swc1        $f16, 0x14($t4)
    MEM_W(0X14, ctx->r12) = ctx->f16.u32l;
    // 0x800C4364: lwc1        $f18, 0xC($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0XC);
    // 0x800C4368: lwc1        $f8, 0x10($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X10);
    // 0x800C436C: lwc1        $f16, 0x14($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0X14);
    // 0x800C4370: mul.s       $f6, $f18, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x800C4374: nop

    // 0x800C4378: mul.s       $f10, $f8, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x800C437C: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800C4380: mul.s       $f18, $f16, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x800C4384: jal         0x800D68E0
    // 0x800C4388: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_5;
    // 0x800C4388: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    after_5:
    // 0x800C438C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C4390: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800C4394: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800C4398: addiu       $t6, $t6, -0x3FA8
    ctx->r14 = ADD32(ctx->r14, -0X3FA8);
    // 0x800C439C: div.s       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800C43A0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800C43A4: addiu       $t8, $t8, -0x3FA8
    ctx->r24 = ADD32(ctx->r24, -0X3FA8);
    // 0x800C43A8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800C43AC: addiu       $t7, $t7, -0x3FA8
    ctx->r15 = ADD32(ctx->r15, -0X3FA8);
    // 0x800C43B0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800C43B4: addiu       $t9, $t9, -0x3FA8
    ctx->r25 = ADD32(ctx->r25, -0X3FA8);
    // 0x800C43B8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800C43BC: addiu       $t0, $t0, -0x3FA8
    ctx->r8 = ADD32(ctx->r8, -0X3FA8);
    // 0x800C43C0: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800C43C4: addiu       $t1, $t1, -0x3FA8
    ctx->r9 = ADD32(ctx->r9, -0X3FA8);
    // 0x800C43C8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800C43CC: addiu       $t2, $t2, -0x3FA8
    ctx->r10 = ADD32(ctx->r10, -0X3FA8);
    // 0x800C43D0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800C43D4: addiu       $t3, $t3, -0x3FA8
    ctx->r11 = ADD32(ctx->r11, -0X3FA8);
    // 0x800C43D8: swc1        $f6, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->f6.u32l;
    // 0x800C43DC: lwc1        $f10, 0xC($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0XC);
    // 0x800C43E0: lwc1        $f16, 0x18($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X18);
    // 0x800C43E4: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800C43E8: swc1        $f18, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f18.u32l;
    // 0x800C43EC: lwc1        $f4, 0x10($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X10);
    // 0x800C43F0: lwc1        $f8, 0x18($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X18);
    // 0x800C43F4: mul.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800C43F8: swc1        $f6, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->f6.u32l;
    // 0x800C43FC: lwc1        $f10, 0x14($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X14);
    // 0x800C4400: lwc1        $f16, 0x18($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X18);
    // 0x800C4404: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800C4408: swc1        $f18, 0x14($t9)
    MEM_W(0X14, ctx->r25) = ctx->f18.u32l;
    // 0x800C440C: lwc1        $f8, 0x14($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X14);
    // 0x800C4410: lwc1        $f4, 0x4($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X4);
    // 0x800C4414: lwc1        $f16, 0x8($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X8);
    // 0x800C4418: lwc1        $f10, 0x10($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X10);
    // 0x800C441C: mul.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800C4420: nop

    // 0x800C4424: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800C4428: sub.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f18.fl;
    // 0x800C442C: swc1        $f4, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->f4.u32l;
    // 0x800C4430: lwc1        $f10, 0xC($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0XC);
    // 0x800C4434: lwc1        $f8, 0x8($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X8);
    // 0x800C4438: lwc1        $f18, 0x0($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X0);
    // 0x800C443C: lwc1        $f6, 0x14($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X14);
    // 0x800C4440: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800C4444: nop

    // 0x800C4448: mul.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x800C444C: sub.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x800C4450: swc1        $f8, 0x1C($t1)
    MEM_W(0X1C, ctx->r9) = ctx->f8.u32l;
    // 0x800C4454: lwc1        $f6, 0x10($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X10);
    // 0x800C4458: lwc1        $f10, 0x0($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X0);
    // 0x800C445C: lwc1        $f4, 0x4($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X4);
    // 0x800C4460: lwc1        $f16, 0xC($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0XC);
    // 0x800C4464: mul.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x800C4468: nop

    // 0x800C446C: mul.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x800C4470: sub.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x800C4474: swc1        $f10, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->f10.u32l;
    // 0x800C4478: lwc1        $f6, 0x18($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X18);
    // 0x800C447C: lwc1        $f4, 0x1C($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X1C);
    // 0x800C4480: lwc1        $f10, 0x20($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X20);
    // 0x800C4484: mul.s       $f16, $f6, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x800C4488: nop

    // 0x800C448C: mul.s       $f18, $f4, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x800C4490: add.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800C4494: mul.s       $f6, $f10, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x800C4498: jal         0x800D68E0
    // 0x800C449C: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_6;
    // 0x800C449C: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    after_6:
    // 0x800C44A0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C44A4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800C44A8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800C44AC: addiu       $t4, $t4, -0x3FA8
    ctx->r12 = ADD32(ctx->r12, -0X3FA8);
    // 0x800C44B0: div.s       $f16, $f4, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800C44B4: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800C44B8: addiu       $t5, $t5, -0x3FA8
    ctx->r13 = ADD32(ctx->r13, -0X3FA8);
    // 0x800C44BC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800C44C0: addiu       $t6, $t6, -0x3FA8
    ctx->r14 = ADD32(ctx->r14, -0X3FA8);
    // 0x800C44C4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800C44C8: addiu       $t8, $t8, -0x3FA8
    ctx->r24 = ADD32(ctx->r24, -0X3FA8);
    // 0x800C44CC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800C44D0: addiu       $t7, $t7, -0x3FA8
    ctx->r15 = ADD32(ctx->r15, -0X3FA8);
    // 0x800C44D4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800C44D8: addiu       $t9, $t9, -0x4198
    ctx->r25 = ADD32(ctx->r25, -0X4198);
    // 0x800C44DC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800C44E0: addiu       $t0, $t0, -0x3FA8
    ctx->r8 = ADD32(ctx->r8, -0X3FA8);
    // 0x800C44E4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800C44E8: addiu       $t1, $t1, -0x4198
    ctx->r9 = ADD32(ctx->r9, -0X4198);
    // 0x800C44EC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800C44F0: addiu       $t2, $t2, -0x3FA8
    ctx->r10 = ADD32(ctx->r10, -0X3FA8);
    // 0x800C44F4: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800C44F8: addiu       $t3, $t3, -0x4198
    ctx->r11 = ADD32(ctx->r11, -0X4198);
    // 0x800C44FC: swc1        $f16, 0x24($t4)
    MEM_W(0X24, ctx->r12) = ctx->f16.u32l;
    // 0x800C4500: lwc1        $f18, 0x18($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X18);
    // 0x800C4504: lwc1        $f10, 0x24($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X24);
    // 0x800C4508: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800C450C: addiu       $t4, $t4, -0x4198
    ctx->r12 = ADD32(ctx->r12, -0X4198);
    // 0x800C4510: mul.s       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x800C4514: swc1        $f6, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f6.u32l;
    // 0x800C4518: lwc1        $f8, 0x1C($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X1C);
    // 0x800C451C: lwc1        $f4, 0x24($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X24);
    // 0x800C4520: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800C4524: addiu       $t5, $t5, -0x3FA8
    ctx->r13 = ADD32(ctx->r13, -0X3FA8);
    // 0x800C4528: mul.s       $f16, $f8, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x800C452C: swc1        $f16, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = ctx->f16.u32l;
    // 0x800C4530: lwc1        $f18, 0x20($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X20);
    // 0x800C4534: lwc1        $f10, 0x24($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X24);
    // 0x800C4538: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800C453C: addiu       $t6, $t6, -0x4198
    ctx->r14 = ADD32(ctx->r14, -0X4198);
    // 0x800C4540: mul.s       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x800C4544: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800C4548: swc1        $f6, 0x20($t8)
    MEM_W(0X20, ctx->r24) = ctx->f6.u32l;
    // 0x800C454C: lwc1        $f8, 0xC($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0XC);
    // 0x800C4550: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800C4554: addiu       $t8, $t8, -0x3FA8
    ctx->r24 = ADD32(ctx->r24, -0X3FA8);
    // 0x800C4558: swc1        $f8, 0x30($t9)
    MEM_W(0X30, ctx->r25) = ctx->f8.u32l;
    // 0x800C455C: lwc1        $f4, 0x10($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X10);
    // 0x800C4560: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800C4564: addiu       $t7, $t7, -0x4198
    ctx->r15 = ADD32(ctx->r15, -0X4198);
    // 0x800C4568: swc1        $f4, 0x34($t1)
    MEM_W(0X34, ctx->r9) = ctx->f4.u32l;
    // 0x800C456C: lwc1        $f16, 0x14($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X14);
    // 0x800C4570: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800C4574: addiu       $t9, $t9, -0x3FA8
    ctx->r25 = ADD32(ctx->r25, -0X3FA8);
    // 0x800C4578: swc1        $f16, 0x38($t3)
    MEM_W(0X38, ctx->r11) = ctx->f16.u32l;
    // 0x800C457C: swc1        $f18, 0x3C($t4)
    MEM_W(0X3C, ctx->r12) = ctx->f18.u32l;
    // 0x800C4580: lwc1        $f10, 0x18($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X18);
    // 0x800C4584: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800C4588: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800C458C: swc1        $f10, 0x40($t6)
    MEM_W(0X40, ctx->r14) = ctx->f10.u32l;
    // 0x800C4590: lwc1        $f6, 0x1C($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X1C);
    // 0x800C4594: addiu       $t0, $t0, -0x4198
    ctx->r8 = ADD32(ctx->r8, -0X4198);
    // 0x800C4598: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800C459C: swc1        $f6, 0x44($t7)
    MEM_W(0X44, ctx->r15) = ctx->f6.u32l;
    // 0x800C45A0: lwc1        $f8, 0x20($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X20);
    // 0x800C45A4: addiu       $t1, $t1, -0x4198
    ctx->r9 = ADD32(ctx->r9, -0X4198);
    // 0x800C45A8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800C45AC: swc1        $f8, 0x48($t0)
    MEM_W(0X48, ctx->r8) = ctx->f8.u32l;
    // 0x800C45B0: addiu       $t2, $t2, -0x3FA8
    ctx->r10 = ADD32(ctx->r10, -0X3FA8);
    // 0x800C45B4: swc1        $f4, 0x4C($t1)
    MEM_W(0X4C, ctx->r9) = ctx->f4.u32l;
    // 0x800C45B8: lwc1        $f16, 0x0($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X0);
    // 0x800C45BC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800C45C0: addiu       $t3, $t3, -0x4198
    ctx->r11 = ADD32(ctx->r11, -0X4198);
    // 0x800C45C4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800C45C8: addiu       $t4, $t4, -0x3FA8
    ctx->r12 = ADD32(ctx->r12, -0X3FA8);
    // 0x800C45CC: swc1        $f16, 0x50($t3)
    MEM_W(0X50, ctx->r11) = ctx->f16.u32l;
    // 0x800C45D0: lwc1        $f18, 0x4($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X4);
    // 0x800C45D4: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800C45D8: addiu       $t5, $t5, -0x4198
    ctx->r13 = ADD32(ctx->r13, -0X4198);
    // 0x800C45DC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800C45E0: addiu       $t6, $t6, -0x3FA8
    ctx->r14 = ADD32(ctx->r14, -0X3FA8);
    // 0x800C45E4: swc1        $f18, 0x54($t5)
    MEM_W(0X54, ctx->r13) = ctx->f18.u32l;
    // 0x800C45E8: lwc1        $f10, 0x8($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X8);
    // 0x800C45EC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800C45F0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800C45F4: addiu       $t8, $t8, -0x4198
    ctx->r24 = ADD32(ctx->r24, -0X4198);
    // 0x800C45F8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800C45FC: addiu       $t7, $t7, -0x4198
    ctx->r15 = ADD32(ctx->r15, -0X4198);
    // 0x800C4600: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800C4604: swc1        $f10, 0x58($t8)
    MEM_W(0X58, ctx->r24) = ctx->f10.u32l;
    // 0x800C4608: addiu       $t9, $t9, -0x4198
    ctx->r25 = ADD32(ctx->r25, -0X4198);
    // 0x800C460C: swc1        $f6, 0x68($t7)
    MEM_W(0X68, ctx->r15) = ctx->f6.u32l;
    // 0x800C4610: lwc1        $f22, 0x68($t9)
    ctx->f22.u32l = MEM_W(ctx->r25, 0X68);
    // 0x800C4614: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800C4618: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800C461C: addiu       $t0, $t0, -0x4198
    ctx->r8 = ADD32(ctx->r8, -0X4198);
    // 0x800C4620: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800C4624: swc1        $f22, 0x64($t9)
    MEM_W(0X64, ctx->r25) = ctx->f22.u32l;
    // 0x800C4628: mov.s       $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    ctx->f20.fl = ctx->f22.fl;
    // 0x800C462C: swc1        $f20, 0x60($t0)
    MEM_W(0X60, ctx->r8) = ctx->f20.u32l;
    // 0x800C4630: addiu       $t1, $t1, -0x4198
    ctx->r9 = ADD32(ctx->r9, -0X4198);
    // 0x800C4634: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800C4638: swc1        $f20, 0x5C($t1)
    MEM_W(0X5C, ctx->r9) = ctx->f20.u32l;
    // 0x800C463C: addiu       $t2, $t2, -0x4198
    ctx->r10 = ADD32(ctx->r10, -0X4198);
    // 0x800C4640: swc1        $f8, 0x6C($t2)
    MEM_W(0X6C, ctx->r10) = ctx->f8.u32l;
    // 0x800C4644: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800C4648: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x800C464C: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x800C4650: jr          $ra
    // 0x800C4654: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800C4654: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_800C4658(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C4658: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800C465C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800C4660: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C4664: swc1        $f4, -0x41B0($at)
    MEM_W(-0X41B0, ctx->r1) = ctx->f4.u32l;
    // 0x800C4668: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C466C: lwc1        $f6, -0x2C38($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2C38);
    // 0x800C4670: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C4674: swc1        $f6, -0x41AC($at)
    MEM_W(-0X41AC, ctx->r1) = ctx->f6.u32l;
    // 0x800C4678: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800C467C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800C4680: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C4684: swc1        $f8, -0x41A8($at)
    MEM_W(-0X41A8, ctx->r1) = ctx->f8.u32l;
    // 0x800C4688: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C468C: lwc1        $f10, -0x2C34($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2C34);
    // 0x800C4690: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C4694: swc1        $f10, -0x41A4($at)
    MEM_W(-0X41A4, ctx->r1) = ctx->f10.u32l;
    // 0x800C4698: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C469C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800C46A0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C46A4: jr          $ra
    // 0x800C46A8: swc1        $f16, -0x41A0($at)
    MEM_W(-0X41A0, ctx->r1) = ctx->f16.u32l;
    return;
    // 0x800C46A8: swc1        $f16, -0x41A0($at)
    MEM_W(-0X41A0, ctx->r1) = ctx->f16.u32l;
;}
RECOMP_FUNC void func_800C46AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C46AC: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x800C46B0: lw          $t6, -0x4524($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4524);
    // 0x800C46B4: sltiu       $at, $t6, 0x100
    ctx->r1 = ctx->r14 < 0X100 ? 1 : 0;
    // 0x800C46B8: bne         $at, $zero, L_800C46C8
    if (ctx->r1 != 0) {
        // 0x800C46BC: nop
    
            goto L_800C46C8;
    }
    // 0x800C46BC: nop

    // 0x800C46C0: jr          $ra
    // 0x800C46C4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800C46C4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800C46C8:
    // 0x800C46C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800C46CC: jr          $ra
    // 0x800C46D0: nop

    return;
    // 0x800C46D0: nop

;}
RECOMP_FUNC void func_800C46D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C46D4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800C46D8: swc1        $f12, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f12.u32l;
    // 0x800C46DC: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800C46E0: swc1        $f14, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f14.u32l;
    // 0x800C46E4: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800C46E8: mul.s       $f6, $f4, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x800C46EC: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800C46F0: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800C46F4: mul.s       $f10, $f8, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x800C46F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C46FC: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x800C4700: mul.s       $f4, $f18, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x800C4704: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x800C4708: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800C470C: jal         0x800D68E0
    // 0x800C4710: add.s       $f12, $f16, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x800C4710: add.s       $f12, $f16, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f4.fl;
    after_0:
    // 0x800C4714: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800C4718: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800C471C: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800C4720: mul.s       $f6, $f8, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x800C4724: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800C4728: mul.s       $f18, $f10, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x800C472C: add.s       $f16, $f6, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x800C4730: mul.s       $f8, $f4, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x800C4734: jal         0x800D68E0
    // 0x800C4738: add.s       $f12, $f16, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x800C4738: add.s       $f12, $f16, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f8.fl;
    after_1:
    // 0x800C473C: mul.s       $f10, $f0, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800C4740: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800C4744: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x800C4748: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800C474C: c.eq.s      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.fl == ctx->f18.fl;
    // 0x800C4750: nop

    // 0x800C4754: bc1t        L_800C47B4
    if (c1cs) {
        // 0x800C4758: nop
    
            goto L_800C47B4;
    }
    // 0x800C4758: nop

    // 0x800C475C: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800C4760: lwc1        $f16, 0x3C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800C4764: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800C4768: lwc1        $f18, 0x40($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800C476C: mul.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x800C4770: nop

    // 0x800C4774: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800C4778: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800C477C: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800C4780: add.s       $f16, $f8, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800C4784: mul.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800C4788: add.s       $f4, $f16, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x800C478C: jal         0x800E4BE0
    // 0x800C4790: div.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    func_800E4BE0(rdram, ctx);
        goto after_2;
    // 0x800C4790: div.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    after_2:
    // 0x800C4794: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x800C4798: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800C479C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C47A0: lwc1        $f16, -0x2C30($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2C30);
    // 0x800C47A4: mul.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x800C47A8: div.s       $f8, $f18, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = DIV_S(ctx->f18.fl, ctx->f16.fl);
    // 0x800C47AC: b           L_800C47C0
    // 0x800C47B0: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
        goto L_800C47C0;
    // 0x800C47B0: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
L_800C47B4:
    // 0x800C47B4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800C47B8: nop

    // 0x800C47BC: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
L_800C47C0:
    // 0x800C47C0: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800C47C4: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800C47C8: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800C47CC: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800C47D0: mul.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800C47D4: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x800C47D8: mul.s       $f4, $f16, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x800C47DC: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x800C47E0: swc1        $f6, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f6.u32l;
    // 0x800C47E4: lwc1        $f16, 0x3C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800C47E8: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800C47EC: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800C47F0: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800C47F4: mul.s       $f8, $f10, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800C47F8: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x800C47FC: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800C4800: sub.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x800C4804: swc1        $f10, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f10.u32l;
    // 0x800C4808: lwc1        $f18, 0x40($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800C480C: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800C4810: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800C4814: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800C4818: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800C481C: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x800C4820: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x800C4824: sub.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x800C4828: swc1        $f16, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f16.u32l;
    // 0x800C482C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C4830: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x800C4834: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800C4838: jr          $ra
    // 0x800C483C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800C483C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800C4840(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C4840: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800C4844: swc1        $f12, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f12.u32l;
    // 0x800C4848: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C484C: lwc1        $f6, -0x2C2C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2C2C);
    // 0x800C4850: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800C4854: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C4858: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800C485C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800C4860: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x800C4864: swc1        $f14, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f14.u32l;
    // 0x800C4868: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x800C486C: jal         0x800D68F0
    // 0x800C4870: mov.s       $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = ctx->f8.fl;
    sinf_recomp(rdram, ctx);
        goto after_0;
    // 0x800C4870: mov.s       $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = ctx->f8.fl;
    after_0:
    // 0x800C4874: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x800C4878: jal         0x800D6AB0
    // 0x800C487C: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    __cosf_recomp(rdram, ctx);
        goto after_1;
    // 0x800C487C: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x800C4880: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800C4884: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800C4888: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800C488C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C4890: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800C4894: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800C4898: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x800C489C: mul.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x800C48A0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800C48A4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800C48A8: addiu       $t6, $t6, -0x3F68
    ctx->r14 = ADD32(ctx->r14, -0X3F68);
    // 0x800C48AC: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    // 0x800C48B0: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800C48B4: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800C48B8: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x800C48BC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800C48C0: addiu       $t7, $t7, -0x3F68
    ctx->r15 = ADD32(ctx->r15, -0X3F68);
    // 0x800C48C4: sub.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x800C48C8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800C48CC: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    // 0x800C48D0: addiu       $t8, $t8, -0x3F68
    ctx->r24 = ADD32(ctx->r24, -0X3F68);
    // 0x800C48D4: mul.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800C48D8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800C48DC: addiu       $t9, $t9, -0x3F68
    ctx->r25 = ADD32(ctx->r25, -0X3F68);
    // 0x800C48E0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800C48E4: addiu       $t0, $t0, -0x3F68
    ctx->r8 = ADD32(ctx->r8, -0X3F68);
    // 0x800C48E8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800C48EC: addiu       $t1, $t1, -0x3F68
    ctx->r9 = ADD32(ctx->r9, -0X3F68);
    // 0x800C48F0: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x800C48F4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800C48F8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800C48FC: addiu       $t2, $t2, -0x3F68
    ctx->r10 = ADD32(ctx->r10, -0X3F68);
    // 0x800C4900: swc1        $f18, 0x40($t6)
    MEM_W(0X40, ctx->r14) = ctx->f18.u32l;
    // 0x800C4904: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800C4908: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800C490C: addiu       $t3, $t3, -0x3F68
    ctx->r11 = ADD32(ctx->r11, -0X3F68);
    // 0x800C4910: swc1        $f4, 0x44($t7)
    MEM_W(0X44, ctx->r15) = ctx->f4.u32l;
    // 0x800C4914: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800C4918: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800C491C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800C4920: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x800C4924: addiu       $t4, $t4, -0x3F68
    ctx->r12 = ADD32(ctx->r12, -0X3F68);
    // 0x800C4928: swc1        $f8, 0x48($t8)
    MEM_W(0X48, ctx->r24) = ctx->f8.u32l;
    // 0x800C492C: swc1        $f16, 0x4C($t9)
    MEM_W(0X4C, ctx->r25) = ctx->f16.u32l;
    // 0x800C4930: lwc1        $f10, 0x1C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800C4934: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800C4938: addiu       $t5, $t5, -0x3F68
    ctx->r13 = ADD32(ctx->r13, -0X3F68);
    // 0x800C493C: neg.s       $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = -ctx->f10.fl;
    // 0x800C4940: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800C4944: swc1        $f18, 0x50($t0)
    MEM_W(0X50, ctx->r8) = ctx->f18.u32l;
    // 0x800C4948: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800C494C: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800C4950: addiu       $t6, $t6, -0x3F68
    ctx->r14 = ADD32(ctx->r14, -0X3F68);
    // 0x800C4954: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800C4958: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800C495C: addiu       $t7, $t7, -0x3F68
    ctx->r15 = ADD32(ctx->r15, -0X3F68);
    // 0x800C4960: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800C4964: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800C4968: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800C496C: addiu       $t8, $t8, -0x3F68
    ctx->r24 = ADD32(ctx->r24, -0X3F68);
    // 0x800C4970: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800C4974: addiu       $t9, $t9, -0x3F68
    ctx->r25 = ADD32(ctx->r25, -0X3F68);
    // 0x800C4978: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800C497C: addiu       $t0, $t0, -0x3F68
    ctx->r8 = ADD32(ctx->r8, -0X3F68);
    // 0x800C4980: add.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800C4984: swc1        $f18, 0x54($t1)
    MEM_W(0X54, ctx->r9) = ctx->f18.u32l;
    // 0x800C4988: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800C498C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800C4990: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800C4994: swc1        $f4, 0x58($t2)
    MEM_W(0X58, ctx->r10) = ctx->f4.u32l;
    // 0x800C4998: swc1        $f8, 0x5C($t3)
    MEM_W(0X5C, ctx->r11) = ctx->f8.u32l;
    // 0x800C499C: lwc1        $f16, 0x20($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800C49A0: addiu       $t1, $t1, -0x3F68
    ctx->r9 = ADD32(ctx->r9, -0X3F68);
    // 0x800C49A4: swc1        $f16, 0x60($t4)
    MEM_W(0X60, ctx->r12) = ctx->f16.u32l;
    // 0x800C49A8: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800C49AC: neg.s       $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = -ctx->f10.fl;
    // 0x800C49B0: swc1        $f6, 0x64($t5)
    MEM_W(0X64, ctx->r13) = ctx->f6.u32l;
    // 0x800C49B4: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800C49B8: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800C49BC: sub.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x800C49C0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800C49C4: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800C49C8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800C49CC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800C49D0: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800C49D4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800C49D8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800C49DC: swc1        $f6, 0x68($t6)
    MEM_W(0X68, ctx->r14) = ctx->f6.u32l;
    // 0x800C49E0: swc1        $f18, 0x6C($t7)
    MEM_W(0X6C, ctx->r15) = ctx->f18.u32l;
    // 0x800C49E4: swc1        $f8, 0x70($t8)
    MEM_W(0X70, ctx->r24) = ctx->f8.u32l;
    // 0x800C49E8: swc1        $f16, 0x74($t9)
    MEM_W(0X74, ctx->r25) = ctx->f16.u32l;
    // 0x800C49EC: swc1        $f10, 0x78($t0)
    MEM_W(0X78, ctx->r8) = ctx->f10.u32l;
    // 0x800C49F0: swc1        $f4, 0x7C($t1)
    MEM_W(0X7C, ctx->r9) = ctx->f4.u32l;
    // 0x800C49F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C49F8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800C49FC: jr          $ra
    // 0x800C4A00: nop

    return;
    // 0x800C4A00: nop

;}
RECOMP_FUNC void func_800C4A04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C4A04: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800C4A08: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C4A0C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800C4A10: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800C4A14: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800C4A18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C4A1C: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x800C4A20: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    // 0x800C4A24: swc1        $f12, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f12.u32l;
    // 0x800C4A28: swc1        $f14, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f14.u32l;
    // 0x800C4A2C: addiu       $t6, $t6, -0x3F68
    ctx->r14 = ADD32(ctx->r14, -0X3F68);
    // 0x800C4A30: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800C4A34: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800C4A38: addiu       $t7, $t7, -0x3F68
    ctx->r15 = ADD32(ctx->r15, -0X3F68);
    // 0x800C4A3C: swc1        $f4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f4.u32l;
    // 0x800C4A40: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800C4A44: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800C4A48: swc1        $f6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f6.u32l;
    // 0x800C4A4C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800C4A50: addiu       $t8, $t8, -0x3F68
    ctx->r24 = ADD32(ctx->r24, -0X3F68);
    // 0x800C4A54: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800C4A58: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800C4A5C: addiu       $t9, $t9, -0x3F68
    ctx->r25 = ADD32(ctx->r25, -0X3F68);
    // 0x800C4A60: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800C4A64: swc1        $f8, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f8.u32l;
    // 0x800C4A68: addiu       $t0, $t0, -0x3F68
    ctx->r8 = ADD32(ctx->r8, -0X3F68);
    // 0x800C4A6C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800C4A70: swc1        $f10, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f10.u32l;
    // 0x800C4A74: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800C4A78: addiu       $t1, $t1, -0x3F68
    ctx->r9 = ADD32(ctx->r9, -0X3F68);
    // 0x800C4A7C: swc1        $f16, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->f16.u32l;
    // 0x800C4A80: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800C4A84: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800C4A88: swc1        $f18, 0x14($t1)
    MEM_W(0X14, ctx->r9) = ctx->f18.u32l;
    // 0x800C4A8C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800C4A90: addiu       $t2, $t2, -0x3F68
    ctx->r10 = ADD32(ctx->r10, -0X3F68);
    // 0x800C4A94: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800C4A98: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800C4A9C: addiu       $t3, $t3, -0x3F68
    ctx->r11 = ADD32(ctx->r11, -0X3F68);
    // 0x800C4AA0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800C4AA4: swc1        $f4, 0x18($t2)
    MEM_W(0X18, ctx->r10) = ctx->f4.u32l;
    // 0x800C4AA8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800C4AAC: addiu       $t4, $t4, -0x3F68
    ctx->r12 = ADD32(ctx->r12, -0X3F68);
    // 0x800C4AB0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800C4AB4: swc1        $f6, 0x1C($t3)
    MEM_W(0X1C, ctx->r11) = ctx->f6.u32l;
    // 0x800C4AB8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800C4ABC: addiu       $t5, $t5, -0x3F68
    ctx->r13 = ADD32(ctx->r13, -0X3F68);
    // 0x800C4AC0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800C4AC4: swc1        $f8, 0x20($t4)
    MEM_W(0X20, ctx->r12) = ctx->f8.u32l;
    // 0x800C4AC8: addiu       $t6, $t6, -0x3F68
    ctx->r14 = ADD32(ctx->r14, -0X3F68);
    // 0x800C4ACC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800C4AD0: swc1        $f10, 0x24($t5)
    MEM_W(0X24, ctx->r13) = ctx->f10.u32l;
    // 0x800C4AD4: addiu       $t7, $t7, -0x3F68
    ctx->r15 = ADD32(ctx->r15, -0X3F68);
    // 0x800C4AD8: swc1        $f16, 0x28($t6)
    MEM_W(0X28, ctx->r14) = ctx->f16.u32l;
    // 0x800C4ADC: swc1        $f18, 0x2C($t7)
    MEM_W(0X2C, ctx->r15) = ctx->f18.u32l;
    // 0x800C4AE0: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800C4AE4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800C4AE8: addiu       $t8, $t8, -0x3F68
    ctx->r24 = ADD32(ctx->r24, -0X3F68);
    // 0x800C4AEC: swc1        $f4, 0x30($t8)
    MEM_W(0X30, ctx->r24) = ctx->f4.u32l;
    // 0x800C4AF0: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800C4AF4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800C4AF8: addiu       $t9, $t9, -0x3F68
    ctx->r25 = ADD32(ctx->r25, -0X3F68);
    // 0x800C4AFC: swc1        $f6, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->f6.u32l;
    // 0x800C4B00: lwc1        $f8, 0x60($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800C4B04: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800C4B08: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800C4B0C: addiu       $t0, $t0, -0x3F68
    ctx->r8 = ADD32(ctx->r8, -0X3F68);
    // 0x800C4B10: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800C4B14: addiu       $t1, $t1, -0x3F68
    ctx->r9 = ADD32(ctx->r9, -0X3F68);
    // 0x800C4B18: swc1        $f8, 0x38($t0)
    MEM_W(0X38, ctx->r8) = ctx->f8.u32l;
    // 0x800C4B1C: swc1        $f10, 0x3C($t1)
    MEM_W(0X3C, ctx->r9) = ctx->f10.u32l;
    // 0x800C4B20: lwc1        $f16, 0x64($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800C4B24: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800C4B28: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800C4B2C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800C4B30: addiu       $t2, $t2, -0x3F68
    ctx->r10 = ADD32(ctx->r10, -0X3F68);
    // 0x800C4B34: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800C4B38: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800C4B3C: addiu       $t3, $t3, -0x3F68
    ctx->r11 = ADD32(ctx->r11, -0X3F68);
    // 0x800C4B40: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800C4B44: swc1        $f16, 0x80($t2)
    MEM_W(0X80, ctx->r10) = ctx->f16.u32l;
    // 0x800C4B48: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800C4B4C: addiu       $t4, $t4, -0x3F68
    ctx->r12 = ADD32(ctx->r12, -0X3F68);
    // 0x800C4B50: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800C4B54: swc1        $f18, 0x84($t3)
    MEM_W(0X84, ctx->r11) = ctx->f18.u32l;
    // 0x800C4B58: addiu       $t5, $t5, -0x3F68
    ctx->r13 = ADD32(ctx->r13, -0X3F68);
    // 0x800C4B5C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800C4B60: swc1        $f4, 0x88($t4)
    MEM_W(0X88, ctx->r12) = ctx->f4.u32l;
    // 0x800C4B64: addiu       $t6, $t6, -0x3F68
    ctx->r14 = ADD32(ctx->r14, -0X3F68);
    // 0x800C4B68: swc1        $f6, 0x8C($t5)
    MEM_W(0X8C, ctx->r13) = ctx->f6.u32l;
    // 0x800C4B6C: swc1        $f8, 0x90($t6)
    MEM_W(0X90, ctx->r14) = ctx->f8.u32l;
    // 0x800C4B70: lwc1        $f10, 0x68($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800C4B74: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800C4B78: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800C4B7C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800C4B80: addiu       $t7, $t7, -0x3F68
    ctx->r15 = ADD32(ctx->r15, -0X3F68);
    // 0x800C4B84: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800C4B88: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800C4B8C: addiu       $t8, $t8, -0x3F68
    ctx->r24 = ADD32(ctx->r24, -0X3F68);
    // 0x800C4B90: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800C4B94: swc1        $f10, 0x94($t7)
    MEM_W(0X94, ctx->r15) = ctx->f10.u32l;
    // 0x800C4B98: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800C4B9C: addiu       $t9, $t9, -0x3F68
    ctx->r25 = ADD32(ctx->r25, -0X3F68);
    // 0x800C4BA0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800C4BA4: swc1        $f16, 0x98($t8)
    MEM_W(0X98, ctx->r24) = ctx->f16.u32l;
    // 0x800C4BA8: addiu       $t0, $t0, -0x3F68
    ctx->r8 = ADD32(ctx->r8, -0X3F68);
    // 0x800C4BAC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800C4BB0: swc1        $f18, 0x9C($t9)
    MEM_W(0X9C, ctx->r25) = ctx->f18.u32l;
    // 0x800C4BB4: addiu       $t1, $t1, -0x3F68
    ctx->r9 = ADD32(ctx->r9, -0X3F68);
    // 0x800C4BB8: swc1        $f4, 0xA0($t0)
    MEM_W(0XA0, ctx->r8) = ctx->f4.u32l;
    // 0x800C4BBC: swc1        $f6, 0xA4($t1)
    MEM_W(0XA4, ctx->r9) = ctx->f6.u32l;
    // 0x800C4BC0: lwc1        $f8, 0x6C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800C4BC4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800C4BC8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800C4BCC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800C4BD0: addiu       $t2, $t2, -0x3F68
    ctx->r10 = ADD32(ctx->r10, -0X3F68);
    // 0x800C4BD4: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800C4BD8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800C4BDC: addiu       $t3, $t3, -0x3F68
    ctx->r11 = ADD32(ctx->r11, -0X3F68);
    // 0x800C4BE0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800C4BE4: swc1        $f8, 0xA8($t2)
    MEM_W(0XA8, ctx->r10) = ctx->f8.u32l;
    // 0x800C4BE8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800C4BEC: addiu       $t4, $t4, -0x3F68
    ctx->r12 = ADD32(ctx->r12, -0X3F68);
    // 0x800C4BF0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800C4BF4: swc1        $f10, 0xAC($t3)
    MEM_W(0XAC, ctx->r11) = ctx->f10.u32l;
    // 0x800C4BF8: addiu       $t5, $t5, -0x3F68
    ctx->r13 = ADD32(ctx->r13, -0X3F68);
    // 0x800C4BFC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800C4C00: swc1        $f16, 0xB0($t4)
    MEM_W(0XB0, ctx->r12) = ctx->f16.u32l;
    // 0x800C4C04: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800C4C08: addiu       $t6, $t6, -0x3F68
    ctx->r14 = ADD32(ctx->r14, -0X3F68);
    // 0x800C4C0C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800C4C10: swc1        $f18, 0xB4($t5)
    MEM_W(0XB4, ctx->r13) = ctx->f18.u32l;
    // 0x800C4C14: addiu       $t7, $t7, -0x3F68
    ctx->r15 = ADD32(ctx->r15, -0X3F68);
    // 0x800C4C18: swc1        $f4, 0xB8($t6)
    MEM_W(0XB8, ctx->r14) = ctx->f4.u32l;
    // 0x800C4C1C: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x800C4C20: jal         0x800D6D20
    // 0x800C4C24: swc1        $f6, 0xBC($t7)
    MEM_W(0XBC, ctx->r15) = ctx->f6.u32l;
    guMtxIdentF_recomp(rdram, ctx);
        goto after_0;
    // 0x800C4C24: swc1        $f6, 0xBC($t7)
    MEM_W(0XBC, ctx->r15) = ctx->f6.u32l;
    after_0:
    // 0x800C4C28: lh          $t8, 0x7E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X7E);
    // 0x800C4C2C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800C4C30: sltiu       $at, $t9, 0x7
    ctx->r1 = ctx->r25 < 0X7 ? 1 : 0;
    // 0x800C4C34: beq         $at, $zero, L_800C4FF4
    if (ctx->r1 == 0) {
        // 0x800C4C38: nop
    
            goto L_800C4FF4;
    }
    // 0x800C4C38: nop

    // 0x800C4C3C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800C4C40: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C4C44: addu        $at, $at, $t9
    gpr jr_addend_800C4C4C = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800C4C48: lw          $t9, -0x2C28($at)
    ctx->r25 = ADD32(ctx->r1, -0X2C28);
    // 0x800C4C4C: jr          $t9
    // 0x800C4C50: nop

    switch (jr_addend_800C4C4C >> 2) {
        case 0: goto L_800C4FF4; break;
        case 1: goto L_800C4CF0; break;
        case 2: goto L_800C4D8C; break;
        case 3: goto L_800C4EC4; break;
        case 4: goto L_800C4E28; break;
        case 5: goto L_800C4C54; break;
        case 6: goto L_800C4F60; break;
        default: switch_error(__func__, 0x800C4C4C, 0x800ED3D8);
    }
    // 0x800C4C50: nop

L_800C4C54:
    // 0x800C4C54: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800C4C58: lwc1        $f12, 0x74($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800C4C5C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800C4C60: jal         0x800C4840
    // 0x800C4C64: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_800C4840(rdram, ctx);
        goto after_1;
    // 0x800C4C64: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_1:
    // 0x800C4C68: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800C4C6C: addiu       $t0, $t0, -0x3F68
    ctx->r8 = ADD32(ctx->r8, -0X3F68);
    // 0x800C4C70: addiu       $t1, $t0, 0x80
    ctx->r9 = ADD32(ctx->r8, 0X80);
    // 0x800C4C74: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x800C4C78: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    // 0x800C4C7C: jal         0x800D6F30
    // 0x800C4C80: addiu       $a1, $t0, 0x40
    ctx->r5 = ADD32(ctx->r8, 0X40);
    guMtxCatF_recomp(rdram, ctx);
        goto after_2;
    // 0x800C4C80: addiu       $a1, $t0, 0x40
    ctx->r5 = ADD32(ctx->r8, 0X40);
    after_2:
    // 0x800C4C84: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C4C88: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800C4C8C: lwc1        $f12, 0x70($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800C4C90: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800C4C94: jal         0x800C4840
    // 0x800C4C98: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_800C4840(rdram, ctx);
        goto after_3;
    // 0x800C4C98: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_3:
    // 0x800C4C9C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800C4CA0: addiu       $t2, $t2, -0x3F68
    ctx->r10 = ADD32(ctx->r10, -0X3F68);
    // 0x800C4CA4: addiu       $t3, $t2, 0x80
    ctx->r11 = ADD32(ctx->r10, 0X80);
    // 0x800C4CA8: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    // 0x800C4CAC: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    // 0x800C4CB0: jal         0x800D6F30
    // 0x800C4CB4: addiu       $a0, $t2, 0x40
    ctx->r4 = ADD32(ctx->r10, 0X40);
    guMtxCatF_recomp(rdram, ctx);
        goto after_4;
    // 0x800C4CB4: addiu       $a0, $t2, 0x40
    ctx->r4 = ADD32(ctx->r10, 0X40);
    after_4:
    // 0x800C4CB8: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800C4CBC: lwc1        $f12, 0x78($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800C4CC0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800C4CC4: jal         0x800C4840
    // 0x800C4CC8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800C4840(rdram, ctx);
        goto after_5;
    // 0x800C4CC8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_5:
    // 0x800C4CCC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800C4CD0: addiu       $t4, $t4, -0x3F68
    ctx->r12 = ADD32(ctx->r12, -0X3F68);
    // 0x800C4CD4: addiu       $t5, $t4, 0x80
    ctx->r13 = ADD32(ctx->r12, 0X80);
    // 0x800C4CD8: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
    // 0x800C4CDC: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
    // 0x800C4CE0: jal         0x800D6F30
    // 0x800C4CE4: addiu       $a0, $t4, 0x40
    ctx->r4 = ADD32(ctx->r12, 0X40);
    guMtxCatF_recomp(rdram, ctx);
        goto after_6;
    // 0x800C4CE4: addiu       $a0, $t4, 0x40
    ctx->r4 = ADD32(ctx->r12, 0X40);
    after_6:
    // 0x800C4CE8: b           L_800C4FF4
    // 0x800C4CEC: nop

        goto L_800C4FF4;
    // 0x800C4CEC: nop

L_800C4CF0:
    // 0x800C4CF0: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800C4CF4: lwc1        $f12, 0x78($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800C4CF8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800C4CFC: jal         0x800C4840
    // 0x800C4D00: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800C4840(rdram, ctx);
        goto after_7;
    // 0x800C4D00: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_7:
    // 0x800C4D04: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800C4D08: addiu       $t6, $t6, -0x3F68
    ctx->r14 = ADD32(ctx->r14, -0X3F68);
    // 0x800C4D0C: addiu       $t7, $t6, 0x80
    ctx->r15 = ADD32(ctx->r14, 0X80);
    // 0x800C4D10: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x800C4D14: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x800C4D18: jal         0x800D6F30
    // 0x800C4D1C: addiu       $a1, $t6, 0x40
    ctx->r5 = ADD32(ctx->r14, 0X40);
    guMtxCatF_recomp(rdram, ctx);
        goto after_8;
    // 0x800C4D1C: addiu       $a1, $t6, 0x40
    ctx->r5 = ADD32(ctx->r14, 0X40);
    after_8:
    // 0x800C4D20: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800C4D24: lwc1        $f12, 0x74($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800C4D28: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800C4D2C: jal         0x800C4840
    // 0x800C4D30: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_800C4840(rdram, ctx);
        goto after_9;
    // 0x800C4D30: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_9:
    // 0x800C4D34: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800C4D38: addiu       $t8, $t8, -0x3F68
    ctx->r24 = ADD32(ctx->r24, -0X3F68);
    // 0x800C4D3C: addiu       $t9, $t8, 0x80
    ctx->r25 = ADD32(ctx->r24, 0X80);
    // 0x800C4D40: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x800C4D44: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x800C4D48: jal         0x800D6F30
    // 0x800C4D4C: addiu       $a0, $t8, 0x40
    ctx->r4 = ADD32(ctx->r24, 0X40);
    guMtxCatF_recomp(rdram, ctx);
        goto after_10;
    // 0x800C4D4C: addiu       $a0, $t8, 0x40
    ctx->r4 = ADD32(ctx->r24, 0X40);
    after_10:
    // 0x800C4D50: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C4D54: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800C4D58: lwc1        $f12, 0x70($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800C4D5C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800C4D60: jal         0x800C4840
    // 0x800C4D64: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_800C4840(rdram, ctx);
        goto after_11;
    // 0x800C4D64: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_11:
    // 0x800C4D68: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800C4D6C: addiu       $t0, $t0, -0x3F68
    ctx->r8 = ADD32(ctx->r8, -0X3F68);
    // 0x800C4D70: addiu       $t1, $t0, 0x80
    ctx->r9 = ADD32(ctx->r8, 0X80);
    // 0x800C4D74: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x800C4D78: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    // 0x800C4D7C: jal         0x800D6F30
    // 0x800C4D80: addiu       $a0, $t0, 0x40
    ctx->r4 = ADD32(ctx->r8, 0X40);
    guMtxCatF_recomp(rdram, ctx);
        goto after_12;
    // 0x800C4D80: addiu       $a0, $t0, 0x40
    ctx->r4 = ADD32(ctx->r8, 0X40);
    after_12:
    // 0x800C4D84: b           L_800C4FF4
    // 0x800C4D88: nop

        goto L_800C4FF4;
    // 0x800C4D88: nop

L_800C4D8C:
    // 0x800C4D8C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800C4D90: lwc1        $f12, 0x74($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800C4D94: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800C4D98: jal         0x800C4840
    // 0x800C4D9C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_800C4840(rdram, ctx);
        goto after_13;
    // 0x800C4D9C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_13:
    // 0x800C4DA0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800C4DA4: addiu       $t2, $t2, -0x3F68
    ctx->r10 = ADD32(ctx->r10, -0X3F68);
    // 0x800C4DA8: addiu       $t3, $t2, 0x80
    ctx->r11 = ADD32(ctx->r10, 0X80);
    // 0x800C4DAC: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    // 0x800C4DB0: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    // 0x800C4DB4: jal         0x800D6F30
    // 0x800C4DB8: addiu       $a1, $t2, 0x40
    ctx->r5 = ADD32(ctx->r10, 0X40);
    guMtxCatF_recomp(rdram, ctx);
        goto after_14;
    // 0x800C4DB8: addiu       $a1, $t2, 0x40
    ctx->r5 = ADD32(ctx->r10, 0X40);
    after_14:
    // 0x800C4DBC: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800C4DC0: lwc1        $f12, 0x78($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800C4DC4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800C4DC8: jal         0x800C4840
    // 0x800C4DCC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800C4840(rdram, ctx);
        goto after_15;
    // 0x800C4DCC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_15:
    // 0x800C4DD0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800C4DD4: addiu       $t4, $t4, -0x3F68
    ctx->r12 = ADD32(ctx->r12, -0X3F68);
    // 0x800C4DD8: addiu       $t5, $t4, 0x80
    ctx->r13 = ADD32(ctx->r12, 0X80);
    // 0x800C4DDC: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
    // 0x800C4DE0: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
    // 0x800C4DE4: jal         0x800D6F30
    // 0x800C4DE8: addiu       $a0, $t4, 0x40
    ctx->r4 = ADD32(ctx->r12, 0X40);
    guMtxCatF_recomp(rdram, ctx);
        goto after_16;
    // 0x800C4DE8: addiu       $a0, $t4, 0x40
    ctx->r4 = ADD32(ctx->r12, 0X40);
    after_16:
    // 0x800C4DEC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C4DF0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800C4DF4: lwc1        $f12, 0x70($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800C4DF8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800C4DFC: jal         0x800C4840
    // 0x800C4E00: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_800C4840(rdram, ctx);
        goto after_17;
    // 0x800C4E00: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_17:
    // 0x800C4E04: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800C4E08: addiu       $t6, $t6, -0x3F68
    ctx->r14 = ADD32(ctx->r14, -0X3F68);
    // 0x800C4E0C: addiu       $t7, $t6, 0x80
    ctx->r15 = ADD32(ctx->r14, 0X80);
    // 0x800C4E10: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x800C4E14: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x800C4E18: jal         0x800D6F30
    // 0x800C4E1C: addiu       $a0, $t6, 0x40
    ctx->r4 = ADD32(ctx->r14, 0X40);
    guMtxCatF_recomp(rdram, ctx);
        goto after_18;
    // 0x800C4E1C: addiu       $a0, $t6, 0x40
    ctx->r4 = ADD32(ctx->r14, 0X40);
    after_18:
    // 0x800C4E20: b           L_800C4FF4
    // 0x800C4E24: nop

        goto L_800C4FF4;
    // 0x800C4E24: nop

L_800C4E28:
    // 0x800C4E28: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C4E2C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800C4E30: lwc1        $f12, 0x70($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800C4E34: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800C4E38: jal         0x800C4840
    // 0x800C4E3C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_800C4840(rdram, ctx);
        goto after_19;
    // 0x800C4E3C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_19:
    // 0x800C4E40: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800C4E44: addiu       $t8, $t8, -0x3F68
    ctx->r24 = ADD32(ctx->r24, -0X3F68);
    // 0x800C4E48: addiu       $t9, $t8, 0x80
    ctx->r25 = ADD32(ctx->r24, 0X80);
    // 0x800C4E4C: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x800C4E50: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x800C4E54: jal         0x800D6F30
    // 0x800C4E58: addiu       $a1, $t8, 0x40
    ctx->r5 = ADD32(ctx->r24, 0X40);
    guMtxCatF_recomp(rdram, ctx);
        goto after_20;
    // 0x800C4E58: addiu       $a1, $t8, 0x40
    ctx->r5 = ADD32(ctx->r24, 0X40);
    after_20:
    // 0x800C4E5C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800C4E60: lwc1        $f12, 0x78($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800C4E64: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800C4E68: jal         0x800C4840
    // 0x800C4E6C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800C4840(rdram, ctx);
        goto after_21;
    // 0x800C4E6C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_21:
    // 0x800C4E70: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800C4E74: addiu       $t0, $t0, -0x3F68
    ctx->r8 = ADD32(ctx->r8, -0X3F68);
    // 0x800C4E78: addiu       $t1, $t0, 0x80
    ctx->r9 = ADD32(ctx->r8, 0X80);
    // 0x800C4E7C: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x800C4E80: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    // 0x800C4E84: jal         0x800D6F30
    // 0x800C4E88: addiu       $a0, $t0, 0x40
    ctx->r4 = ADD32(ctx->r8, 0X40);
    guMtxCatF_recomp(rdram, ctx);
        goto after_22;
    // 0x800C4E88: addiu       $a0, $t0, 0x40
    ctx->r4 = ADD32(ctx->r8, 0X40);
    after_22:
    // 0x800C4E8C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800C4E90: lwc1        $f12, 0x74($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800C4E94: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800C4E98: jal         0x800C4840
    // 0x800C4E9C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_800C4840(rdram, ctx);
        goto after_23;
    // 0x800C4E9C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_23:
    // 0x800C4EA0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800C4EA4: addiu       $t2, $t2, -0x3F68
    ctx->r10 = ADD32(ctx->r10, -0X3F68);
    // 0x800C4EA8: addiu       $t3, $t2, 0x80
    ctx->r11 = ADD32(ctx->r10, 0X80);
    // 0x800C4EAC: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    // 0x800C4EB0: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    // 0x800C4EB4: jal         0x800D6F30
    // 0x800C4EB8: addiu       $a0, $t2, 0x40
    ctx->r4 = ADD32(ctx->r10, 0X40);
    guMtxCatF_recomp(rdram, ctx);
        goto after_24;
    // 0x800C4EB8: addiu       $a0, $t2, 0x40
    ctx->r4 = ADD32(ctx->r10, 0X40);
    after_24:
    // 0x800C4EBC: b           L_800C4FF4
    // 0x800C4EC0: nop

        goto L_800C4FF4;
    // 0x800C4EC0: nop

L_800C4EC4:
    // 0x800C4EC4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800C4EC8: lwc1        $f12, 0x78($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800C4ECC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800C4ED0: jal         0x800C4840
    // 0x800C4ED4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800C4840(rdram, ctx);
        goto after_25;
    // 0x800C4ED4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_25:
    // 0x800C4ED8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800C4EDC: addiu       $t4, $t4, -0x3F68
    ctx->r12 = ADD32(ctx->r12, -0X3F68);
    // 0x800C4EE0: addiu       $t5, $t4, 0x80
    ctx->r13 = ADD32(ctx->r12, 0X80);
    // 0x800C4EE4: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x800C4EE8: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
    // 0x800C4EEC: jal         0x800D6F30
    // 0x800C4EF0: addiu       $a1, $t4, 0x40
    ctx->r5 = ADD32(ctx->r12, 0X40);
    guMtxCatF_recomp(rdram, ctx);
        goto after_26;
    // 0x800C4EF0: addiu       $a1, $t4, 0x40
    ctx->r5 = ADD32(ctx->r12, 0X40);
    after_26:
    // 0x800C4EF4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C4EF8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800C4EFC: lwc1        $f12, 0x70($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800C4F00: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800C4F04: jal         0x800C4840
    // 0x800C4F08: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_800C4840(rdram, ctx);
        goto after_27;
    // 0x800C4F08: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_27:
    // 0x800C4F0C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800C4F10: addiu       $t6, $t6, -0x3F68
    ctx->r14 = ADD32(ctx->r14, -0X3F68);
    // 0x800C4F14: addiu       $t7, $t6, 0x80
    ctx->r15 = ADD32(ctx->r14, 0X80);
    // 0x800C4F18: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x800C4F1C: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x800C4F20: jal         0x800D6F30
    // 0x800C4F24: addiu       $a0, $t6, 0x40
    ctx->r4 = ADD32(ctx->r14, 0X40);
    guMtxCatF_recomp(rdram, ctx);
        goto after_28;
    // 0x800C4F24: addiu       $a0, $t6, 0x40
    ctx->r4 = ADD32(ctx->r14, 0X40);
    after_28:
    // 0x800C4F28: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800C4F2C: lwc1        $f12, 0x74($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800C4F30: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800C4F34: jal         0x800C4840
    // 0x800C4F38: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_800C4840(rdram, ctx);
        goto after_29;
    // 0x800C4F38: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_29:
    // 0x800C4F3C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800C4F40: addiu       $t8, $t8, -0x3F68
    ctx->r24 = ADD32(ctx->r24, -0X3F68);
    // 0x800C4F44: addiu       $t9, $t8, 0x80
    ctx->r25 = ADD32(ctx->r24, 0X80);
    // 0x800C4F48: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x800C4F4C: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x800C4F50: jal         0x800D6F30
    // 0x800C4F54: addiu       $a0, $t8, 0x40
    ctx->r4 = ADD32(ctx->r24, 0X40);
    guMtxCatF_recomp(rdram, ctx);
        goto after_30;
    // 0x800C4F54: addiu       $a0, $t8, 0x40
    ctx->r4 = ADD32(ctx->r24, 0X40);
    after_30:
    // 0x800C4F58: b           L_800C4FF4
    // 0x800C4F5C: nop

        goto L_800C4FF4;
    // 0x800C4F5C: nop

L_800C4F60:
    // 0x800C4F60: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C4F64: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800C4F68: lwc1        $f12, 0x70($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800C4F6C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800C4F70: jal         0x800C4840
    // 0x800C4F74: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_800C4840(rdram, ctx);
        goto after_31;
    // 0x800C4F74: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_31:
    // 0x800C4F78: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800C4F7C: addiu       $t0, $t0, -0x3F68
    ctx->r8 = ADD32(ctx->r8, -0X3F68);
    // 0x800C4F80: addiu       $t1, $t0, 0x80
    ctx->r9 = ADD32(ctx->r8, 0X80);
    // 0x800C4F84: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x800C4F88: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    // 0x800C4F8C: jal         0x800D6F30
    // 0x800C4F90: addiu       $a1, $t0, 0x40
    ctx->r5 = ADD32(ctx->r8, 0X40);
    guMtxCatF_recomp(rdram, ctx);
        goto after_32;
    // 0x800C4F90: addiu       $a1, $t0, 0x40
    ctx->r5 = ADD32(ctx->r8, 0X40);
    after_32:
    // 0x800C4F94: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800C4F98: lwc1        $f12, 0x74($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800C4F9C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800C4FA0: jal         0x800C4840
    // 0x800C4FA4: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_800C4840(rdram, ctx);
        goto after_33;
    // 0x800C4FA4: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_33:
    // 0x800C4FA8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800C4FAC: addiu       $t2, $t2, -0x3F68
    ctx->r10 = ADD32(ctx->r10, -0X3F68);
    // 0x800C4FB0: addiu       $t3, $t2, 0x80
    ctx->r11 = ADD32(ctx->r10, 0X80);
    // 0x800C4FB4: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    // 0x800C4FB8: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    // 0x800C4FBC: jal         0x800D6F30
    // 0x800C4FC0: addiu       $a0, $t2, 0x40
    ctx->r4 = ADD32(ctx->r10, 0X40);
    guMtxCatF_recomp(rdram, ctx);
        goto after_34;
    // 0x800C4FC0: addiu       $a0, $t2, 0x40
    ctx->r4 = ADD32(ctx->r10, 0X40);
    after_34:
    // 0x800C4FC4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800C4FC8: lwc1        $f12, 0x78($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800C4FCC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800C4FD0: jal         0x800C4840
    // 0x800C4FD4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800C4840(rdram, ctx);
        goto after_35;
    // 0x800C4FD4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_35:
    // 0x800C4FD8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800C4FDC: addiu       $t4, $t4, -0x3F68
    ctx->r12 = ADD32(ctx->r12, -0X3F68);
    // 0x800C4FE0: addiu       $t5, $t4, 0x80
    ctx->r13 = ADD32(ctx->r12, 0X80);
    // 0x800C4FE4: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
    // 0x800C4FE8: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
    // 0x800C4FEC: jal         0x800D6F30
    // 0x800C4FF0: addiu       $a0, $t4, 0x40
    ctx->r4 = ADD32(ctx->r12, 0X40);
    guMtxCatF_recomp(rdram, ctx);
        goto after_36;
    // 0x800C4FF0: addiu       $a0, $t4, 0x40
    ctx->r4 = ADD32(ctx->r12, 0X40);
    after_36:
L_800C4FF4:
    // 0x800C4FF4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800C4FF8: addiu       $t6, $t6, -0x3F68
    ctx->r14 = ADD32(ctx->r14, -0X3F68);
    // 0x800C4FFC: addiu       $a0, $t6, 0x80
    ctx->r4 = ADD32(ctx->r14, 0X80);
    // 0x800C5000: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x800C5004: jal         0x800D6F30
    // 0x800C5008: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    guMtxCatF_recomp(rdram, ctx);
        goto after_37;
    // 0x800C5008: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    after_37:
    // 0x800C500C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C5010: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x800C5014: jr          $ra
    // 0x800C5018: nop

    return;
    // 0x800C5018: nop

;}
RECOMP_FUNC void func_800C501C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C501C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800C5020: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C5024: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800C5028: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800C502C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800C5030: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C5034: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x800C5038: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    // 0x800C503C: swc1        $f12, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f12.u32l;
    // 0x800C5040: swc1        $f14, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f14.u32l;
    // 0x800C5044: addiu       $t6, $t6, -0x3F68
    ctx->r14 = ADD32(ctx->r14, -0X3F68);
    // 0x800C5048: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800C504C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800C5050: addiu       $t7, $t7, -0x3F68
    ctx->r15 = ADD32(ctx->r15, -0X3F68);
    // 0x800C5054: swc1        $f4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f4.u32l;
    // 0x800C5058: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800C505C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800C5060: swc1        $f6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f6.u32l;
    // 0x800C5064: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800C5068: addiu       $t8, $t8, -0x3F68
    ctx->r24 = ADD32(ctx->r24, -0X3F68);
    // 0x800C506C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800C5070: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800C5074: addiu       $t9, $t9, -0x3F68
    ctx->r25 = ADD32(ctx->r25, -0X3F68);
    // 0x800C5078: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800C507C: swc1        $f8, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f8.u32l;
    // 0x800C5080: addiu       $t0, $t0, -0x3F68
    ctx->r8 = ADD32(ctx->r8, -0X3F68);
    // 0x800C5084: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800C5088: swc1        $f10, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f10.u32l;
    // 0x800C508C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800C5090: addiu       $t1, $t1, -0x3F68
    ctx->r9 = ADD32(ctx->r9, -0X3F68);
    // 0x800C5094: swc1        $f16, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->f16.u32l;
    // 0x800C5098: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800C509C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800C50A0: swc1        $f18, 0x14($t1)
    MEM_W(0X14, ctx->r9) = ctx->f18.u32l;
    // 0x800C50A4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800C50A8: addiu       $t2, $t2, -0x3F68
    ctx->r10 = ADD32(ctx->r10, -0X3F68);
    // 0x800C50AC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800C50B0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800C50B4: addiu       $t3, $t3, -0x3F68
    ctx->r11 = ADD32(ctx->r11, -0X3F68);
    // 0x800C50B8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800C50BC: swc1        $f4, 0x18($t2)
    MEM_W(0X18, ctx->r10) = ctx->f4.u32l;
    // 0x800C50C0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800C50C4: addiu       $t4, $t4, -0x3F68
    ctx->r12 = ADD32(ctx->r12, -0X3F68);
    // 0x800C50C8: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800C50CC: swc1        $f6, 0x1C($t3)
    MEM_W(0X1C, ctx->r11) = ctx->f6.u32l;
    // 0x800C50D0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800C50D4: addiu       $t5, $t5, -0x3F68
    ctx->r13 = ADD32(ctx->r13, -0X3F68);
    // 0x800C50D8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800C50DC: swc1        $f8, 0x20($t4)
    MEM_W(0X20, ctx->r12) = ctx->f8.u32l;
    // 0x800C50E0: addiu       $t6, $t6, -0x3F68
    ctx->r14 = ADD32(ctx->r14, -0X3F68);
    // 0x800C50E4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800C50E8: swc1        $f10, 0x24($t5)
    MEM_W(0X24, ctx->r13) = ctx->f10.u32l;
    // 0x800C50EC: addiu       $t7, $t7, -0x3F68
    ctx->r15 = ADD32(ctx->r15, -0X3F68);
    // 0x800C50F0: swc1        $f16, 0x28($t6)
    MEM_W(0X28, ctx->r14) = ctx->f16.u32l;
    // 0x800C50F4: swc1        $f18, 0x2C($t7)
    MEM_W(0X2C, ctx->r15) = ctx->f18.u32l;
    // 0x800C50F8: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800C50FC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800C5100: addiu       $t8, $t8, -0x3F68
    ctx->r24 = ADD32(ctx->r24, -0X3F68);
    // 0x800C5104: swc1        $f4, 0x30($t8)
    MEM_W(0X30, ctx->r24) = ctx->f4.u32l;
    // 0x800C5108: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800C510C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800C5110: addiu       $t9, $t9, -0x3F68
    ctx->r25 = ADD32(ctx->r25, -0X3F68);
    // 0x800C5114: swc1        $f6, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->f6.u32l;
    // 0x800C5118: lwc1        $f8, 0x60($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800C511C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800C5120: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800C5124: addiu       $t0, $t0, -0x3F68
    ctx->r8 = ADD32(ctx->r8, -0X3F68);
    // 0x800C5128: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800C512C: addiu       $t1, $t1, -0x3F68
    ctx->r9 = ADD32(ctx->r9, -0X3F68);
    // 0x800C5130: swc1        $f8, 0x38($t0)
    MEM_W(0X38, ctx->r8) = ctx->f8.u32l;
    // 0x800C5134: swc1        $f10, 0x3C($t1)
    MEM_W(0X3C, ctx->r9) = ctx->f10.u32l;
    // 0x800C5138: lwc1        $f16, 0x64($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800C513C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800C5140: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800C5144: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800C5148: addiu       $t2, $t2, -0x3F68
    ctx->r10 = ADD32(ctx->r10, -0X3F68);
    // 0x800C514C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800C5150: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800C5154: addiu       $t3, $t3, -0x3F68
    ctx->r11 = ADD32(ctx->r11, -0X3F68);
    // 0x800C5158: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800C515C: swc1        $f16, 0x80($t2)
    MEM_W(0X80, ctx->r10) = ctx->f16.u32l;
    // 0x800C5160: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800C5164: addiu       $t4, $t4, -0x3F68
    ctx->r12 = ADD32(ctx->r12, -0X3F68);
    // 0x800C5168: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800C516C: swc1        $f18, 0x84($t3)
    MEM_W(0X84, ctx->r11) = ctx->f18.u32l;
    // 0x800C5170: addiu       $t5, $t5, -0x3F68
    ctx->r13 = ADD32(ctx->r13, -0X3F68);
    // 0x800C5174: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800C5178: swc1        $f4, 0x88($t4)
    MEM_W(0X88, ctx->r12) = ctx->f4.u32l;
    // 0x800C517C: addiu       $t6, $t6, -0x3F68
    ctx->r14 = ADD32(ctx->r14, -0X3F68);
    // 0x800C5180: swc1        $f6, 0x8C($t5)
    MEM_W(0X8C, ctx->r13) = ctx->f6.u32l;
    // 0x800C5184: swc1        $f8, 0x90($t6)
    MEM_W(0X90, ctx->r14) = ctx->f8.u32l;
    // 0x800C5188: lwc1        $f10, 0x68($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800C518C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800C5190: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800C5194: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800C5198: addiu       $t7, $t7, -0x3F68
    ctx->r15 = ADD32(ctx->r15, -0X3F68);
    // 0x800C519C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800C51A0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800C51A4: addiu       $t8, $t8, -0x3F68
    ctx->r24 = ADD32(ctx->r24, -0X3F68);
    // 0x800C51A8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800C51AC: swc1        $f10, 0x94($t7)
    MEM_W(0X94, ctx->r15) = ctx->f10.u32l;
    // 0x800C51B0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800C51B4: addiu       $t9, $t9, -0x3F68
    ctx->r25 = ADD32(ctx->r25, -0X3F68);
    // 0x800C51B8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800C51BC: swc1        $f16, 0x98($t8)
    MEM_W(0X98, ctx->r24) = ctx->f16.u32l;
    // 0x800C51C0: addiu       $t0, $t0, -0x3F68
    ctx->r8 = ADD32(ctx->r8, -0X3F68);
    // 0x800C51C4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800C51C8: swc1        $f18, 0x9C($t9)
    MEM_W(0X9C, ctx->r25) = ctx->f18.u32l;
    // 0x800C51CC: addiu       $t1, $t1, -0x3F68
    ctx->r9 = ADD32(ctx->r9, -0X3F68);
    // 0x800C51D0: swc1        $f4, 0xA0($t0)
    MEM_W(0XA0, ctx->r8) = ctx->f4.u32l;
    // 0x800C51D4: swc1        $f6, 0xA4($t1)
    MEM_W(0XA4, ctx->r9) = ctx->f6.u32l;
    // 0x800C51D8: lwc1        $f8, 0x6C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800C51DC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800C51E0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800C51E4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800C51E8: addiu       $t2, $t2, -0x3F68
    ctx->r10 = ADD32(ctx->r10, -0X3F68);
    // 0x800C51EC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800C51F0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800C51F4: addiu       $t3, $t3, -0x3F68
    ctx->r11 = ADD32(ctx->r11, -0X3F68);
    // 0x800C51F8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800C51FC: swc1        $f8, 0xA8($t2)
    MEM_W(0XA8, ctx->r10) = ctx->f8.u32l;
    // 0x800C5200: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800C5204: addiu       $t4, $t4, -0x3F68
    ctx->r12 = ADD32(ctx->r12, -0X3F68);
    // 0x800C5208: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800C520C: swc1        $f10, 0xAC($t3)
    MEM_W(0XAC, ctx->r11) = ctx->f10.u32l;
    // 0x800C5210: addiu       $t5, $t5, -0x3F68
    ctx->r13 = ADD32(ctx->r13, -0X3F68);
    // 0x800C5214: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800C5218: swc1        $f16, 0xB0($t4)
    MEM_W(0XB0, ctx->r12) = ctx->f16.u32l;
    // 0x800C521C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800C5220: addiu       $t6, $t6, -0x3F68
    ctx->r14 = ADD32(ctx->r14, -0X3F68);
    // 0x800C5224: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800C5228: swc1        $f18, 0xB4($t5)
    MEM_W(0XB4, ctx->r13) = ctx->f18.u32l;
    // 0x800C522C: addiu       $t7, $t7, -0x3F68
    ctx->r15 = ADD32(ctx->r15, -0X3F68);
    // 0x800C5230: swc1        $f4, 0xB8($t6)
    MEM_W(0XB8, ctx->r14) = ctx->f4.u32l;
    // 0x800C5234: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x800C5238: jal         0x800D6D20
    // 0x800C523C: swc1        $f6, 0xBC($t7)
    MEM_W(0XBC, ctx->r15) = ctx->f6.u32l;
    guMtxIdentF_recomp(rdram, ctx);
        goto after_0;
    // 0x800C523C: swc1        $f6, 0xBC($t7)
    MEM_W(0XBC, ctx->r15) = ctx->f6.u32l;
    after_0:
    // 0x800C5240: lh          $t8, 0x7E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X7E);
    // 0x800C5244: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800C5248: sltiu       $at, $t9, 0x7
    ctx->r1 = ctx->r25 < 0X7 ? 1 : 0;
    // 0x800C524C: beq         $at, $zero, L_800C560C
    if (ctx->r1 == 0) {
        // 0x800C5250: nop
    
            goto L_800C560C;
    }
    // 0x800C5250: nop

    // 0x800C5254: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800C5258: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C525C: addu        $at, $at, $t9
    gpr jr_addend_800C5264 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800C5260: lw          $t9, -0x2C0C($at)
    ctx->r25 = ADD32(ctx->r1, -0X2C0C);
    // 0x800C5264: jr          $t9
    // 0x800C5268: nop

    switch (jr_addend_800C5264 >> 2) {
        case 0: goto L_800C560C; break;
        case 1: goto L_800C5308; break;
        case 2: goto L_800C53A4; break;
        case 3: goto L_800C54DC; break;
        case 4: goto L_800C5440; break;
        case 5: goto L_800C526C; break;
        case 6: goto L_800C5578; break;
        default: switch_error(__func__, 0x800C5264, 0x800ED3F4);
    }
    // 0x800C5268: nop

L_800C526C:
    // 0x800C526C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800C5270: lwc1        $f12, 0x74($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800C5274: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800C5278: jal         0x800C4840
    // 0x800C527C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_800C4840(rdram, ctx);
        goto after_1;
    // 0x800C527C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_1:
    // 0x800C5280: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800C5284: addiu       $t0, $t0, -0x3F68
    ctx->r8 = ADD32(ctx->r8, -0X3F68);
    // 0x800C5288: addiu       $t1, $t0, 0x80
    ctx->r9 = ADD32(ctx->r8, 0X80);
    // 0x800C528C: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x800C5290: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    // 0x800C5294: jal         0x800D6F30
    // 0x800C5298: addiu       $a0, $t0, 0x40
    ctx->r4 = ADD32(ctx->r8, 0X40);
    guMtxCatF_recomp(rdram, ctx);
        goto after_2;
    // 0x800C5298: addiu       $a0, $t0, 0x40
    ctx->r4 = ADD32(ctx->r8, 0X40);
    after_2:
    // 0x800C529C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C52A0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800C52A4: lwc1        $f12, 0x70($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800C52A8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800C52AC: jal         0x800C4840
    // 0x800C52B0: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_800C4840(rdram, ctx);
        goto after_3;
    // 0x800C52B0: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_3:
    // 0x800C52B4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800C52B8: addiu       $t2, $t2, -0x3F68
    ctx->r10 = ADD32(ctx->r10, -0X3F68);
    // 0x800C52BC: addiu       $t3, $t2, 0x80
    ctx->r11 = ADD32(ctx->r10, 0X80);
    // 0x800C52C0: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    // 0x800C52C4: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    // 0x800C52C8: jal         0x800D6F30
    // 0x800C52CC: addiu       $a0, $t2, 0x40
    ctx->r4 = ADD32(ctx->r10, 0X40);
    guMtxCatF_recomp(rdram, ctx);
        goto after_4;
    // 0x800C52CC: addiu       $a0, $t2, 0x40
    ctx->r4 = ADD32(ctx->r10, 0X40);
    after_4:
    // 0x800C52D0: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800C52D4: lwc1        $f12, 0x78($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800C52D8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800C52DC: jal         0x800C4840
    // 0x800C52E0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800C4840(rdram, ctx);
        goto after_5;
    // 0x800C52E0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_5:
    // 0x800C52E4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800C52E8: addiu       $t4, $t4, -0x3F68
    ctx->r12 = ADD32(ctx->r12, -0X3F68);
    // 0x800C52EC: addiu       $t5, $t4, 0x80
    ctx->r13 = ADD32(ctx->r12, 0X80);
    // 0x800C52F0: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
    // 0x800C52F4: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
    // 0x800C52F8: jal         0x800D6F30
    // 0x800C52FC: addiu       $a0, $t4, 0x40
    ctx->r4 = ADD32(ctx->r12, 0X40);
    guMtxCatF_recomp(rdram, ctx);
        goto after_6;
    // 0x800C52FC: addiu       $a0, $t4, 0x40
    ctx->r4 = ADD32(ctx->r12, 0X40);
    after_6:
    // 0x800C5300: b           L_800C560C
    // 0x800C5304: nop

        goto L_800C560C;
    // 0x800C5304: nop

L_800C5308:
    // 0x800C5308: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800C530C: lwc1        $f12, 0x78($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800C5310: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800C5314: jal         0x800C4840
    // 0x800C5318: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800C4840(rdram, ctx);
        goto after_7;
    // 0x800C5318: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_7:
    // 0x800C531C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800C5320: addiu       $t6, $t6, -0x3F68
    ctx->r14 = ADD32(ctx->r14, -0X3F68);
    // 0x800C5324: addiu       $t7, $t6, 0x80
    ctx->r15 = ADD32(ctx->r14, 0X80);
    // 0x800C5328: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x800C532C: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x800C5330: jal         0x800D6F30
    // 0x800C5334: addiu       $a0, $t6, 0x40
    ctx->r4 = ADD32(ctx->r14, 0X40);
    guMtxCatF_recomp(rdram, ctx);
        goto after_8;
    // 0x800C5334: addiu       $a0, $t6, 0x40
    ctx->r4 = ADD32(ctx->r14, 0X40);
    after_8:
    // 0x800C5338: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800C533C: lwc1        $f12, 0x74($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800C5340: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800C5344: jal         0x800C4840
    // 0x800C5348: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_800C4840(rdram, ctx);
        goto after_9;
    // 0x800C5348: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_9:
    // 0x800C534C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800C5350: addiu       $t8, $t8, -0x3F68
    ctx->r24 = ADD32(ctx->r24, -0X3F68);
    // 0x800C5354: addiu       $t9, $t8, 0x80
    ctx->r25 = ADD32(ctx->r24, 0X80);
    // 0x800C5358: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x800C535C: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x800C5360: jal         0x800D6F30
    // 0x800C5364: addiu       $a0, $t8, 0x40
    ctx->r4 = ADD32(ctx->r24, 0X40);
    guMtxCatF_recomp(rdram, ctx);
        goto after_10;
    // 0x800C5364: addiu       $a0, $t8, 0x40
    ctx->r4 = ADD32(ctx->r24, 0X40);
    after_10:
    // 0x800C5368: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C536C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800C5370: lwc1        $f12, 0x70($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800C5374: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800C5378: jal         0x800C4840
    // 0x800C537C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_800C4840(rdram, ctx);
        goto after_11;
    // 0x800C537C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_11:
    // 0x800C5380: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800C5384: addiu       $t0, $t0, -0x3F68
    ctx->r8 = ADD32(ctx->r8, -0X3F68);
    // 0x800C5388: addiu       $t1, $t0, 0x80
    ctx->r9 = ADD32(ctx->r8, 0X80);
    // 0x800C538C: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x800C5390: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    // 0x800C5394: jal         0x800D6F30
    // 0x800C5398: addiu       $a0, $t0, 0x40
    ctx->r4 = ADD32(ctx->r8, 0X40);
    guMtxCatF_recomp(rdram, ctx);
        goto after_12;
    // 0x800C5398: addiu       $a0, $t0, 0x40
    ctx->r4 = ADD32(ctx->r8, 0X40);
    after_12:
    // 0x800C539C: b           L_800C560C
    // 0x800C53A0: nop

        goto L_800C560C;
    // 0x800C53A0: nop

L_800C53A4:
    // 0x800C53A4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800C53A8: lwc1        $f12, 0x74($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800C53AC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800C53B0: jal         0x800C4840
    // 0x800C53B4: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_800C4840(rdram, ctx);
        goto after_13;
    // 0x800C53B4: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_13:
    // 0x800C53B8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800C53BC: addiu       $t2, $t2, -0x3F68
    ctx->r10 = ADD32(ctx->r10, -0X3F68);
    // 0x800C53C0: addiu       $t3, $t2, 0x80
    ctx->r11 = ADD32(ctx->r10, 0X80);
    // 0x800C53C4: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    // 0x800C53C8: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    // 0x800C53CC: jal         0x800D6F30
    // 0x800C53D0: addiu       $a0, $t2, 0x40
    ctx->r4 = ADD32(ctx->r10, 0X40);
    guMtxCatF_recomp(rdram, ctx);
        goto after_14;
    // 0x800C53D0: addiu       $a0, $t2, 0x40
    ctx->r4 = ADD32(ctx->r10, 0X40);
    after_14:
    // 0x800C53D4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800C53D8: lwc1        $f12, 0x78($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800C53DC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800C53E0: jal         0x800C4840
    // 0x800C53E4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800C4840(rdram, ctx);
        goto after_15;
    // 0x800C53E4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_15:
    // 0x800C53E8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800C53EC: addiu       $t4, $t4, -0x3F68
    ctx->r12 = ADD32(ctx->r12, -0X3F68);
    // 0x800C53F0: addiu       $t5, $t4, 0x80
    ctx->r13 = ADD32(ctx->r12, 0X80);
    // 0x800C53F4: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
    // 0x800C53F8: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
    // 0x800C53FC: jal         0x800D6F30
    // 0x800C5400: addiu       $a0, $t4, 0x40
    ctx->r4 = ADD32(ctx->r12, 0X40);
    guMtxCatF_recomp(rdram, ctx);
        goto after_16;
    // 0x800C5400: addiu       $a0, $t4, 0x40
    ctx->r4 = ADD32(ctx->r12, 0X40);
    after_16:
    // 0x800C5404: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C5408: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800C540C: lwc1        $f12, 0x70($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800C5410: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800C5414: jal         0x800C4840
    // 0x800C5418: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_800C4840(rdram, ctx);
        goto after_17;
    // 0x800C5418: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_17:
    // 0x800C541C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800C5420: addiu       $t6, $t6, -0x3F68
    ctx->r14 = ADD32(ctx->r14, -0X3F68);
    // 0x800C5424: addiu       $t7, $t6, 0x80
    ctx->r15 = ADD32(ctx->r14, 0X80);
    // 0x800C5428: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x800C542C: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x800C5430: jal         0x800D6F30
    // 0x800C5434: addiu       $a0, $t6, 0x40
    ctx->r4 = ADD32(ctx->r14, 0X40);
    guMtxCatF_recomp(rdram, ctx);
        goto after_18;
    // 0x800C5434: addiu       $a0, $t6, 0x40
    ctx->r4 = ADD32(ctx->r14, 0X40);
    after_18:
    // 0x800C5438: b           L_800C560C
    // 0x800C543C: nop

        goto L_800C560C;
    // 0x800C543C: nop

L_800C5440:
    // 0x800C5440: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C5444: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800C5448: lwc1        $f12, 0x70($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800C544C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800C5450: jal         0x800C4840
    // 0x800C5454: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_800C4840(rdram, ctx);
        goto after_19;
    // 0x800C5454: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_19:
    // 0x800C5458: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800C545C: addiu       $t8, $t8, -0x3F68
    ctx->r24 = ADD32(ctx->r24, -0X3F68);
    // 0x800C5460: addiu       $t9, $t8, 0x80
    ctx->r25 = ADD32(ctx->r24, 0X80);
    // 0x800C5464: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x800C5468: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x800C546C: jal         0x800D6F30
    // 0x800C5470: addiu       $a0, $t8, 0x40
    ctx->r4 = ADD32(ctx->r24, 0X40);
    guMtxCatF_recomp(rdram, ctx);
        goto after_20;
    // 0x800C5470: addiu       $a0, $t8, 0x40
    ctx->r4 = ADD32(ctx->r24, 0X40);
    after_20:
    // 0x800C5474: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800C5478: lwc1        $f12, 0x78($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800C547C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800C5480: jal         0x800C4840
    // 0x800C5484: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800C4840(rdram, ctx);
        goto after_21;
    // 0x800C5484: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_21:
    // 0x800C5488: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800C548C: addiu       $t0, $t0, -0x3F68
    ctx->r8 = ADD32(ctx->r8, -0X3F68);
    // 0x800C5490: addiu       $t1, $t0, 0x80
    ctx->r9 = ADD32(ctx->r8, 0X80);
    // 0x800C5494: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x800C5498: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    // 0x800C549C: jal         0x800D6F30
    // 0x800C54A0: addiu       $a0, $t0, 0x40
    ctx->r4 = ADD32(ctx->r8, 0X40);
    guMtxCatF_recomp(rdram, ctx);
        goto after_22;
    // 0x800C54A0: addiu       $a0, $t0, 0x40
    ctx->r4 = ADD32(ctx->r8, 0X40);
    after_22:
    // 0x800C54A4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800C54A8: lwc1        $f12, 0x74($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800C54AC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800C54B0: jal         0x800C4840
    // 0x800C54B4: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_800C4840(rdram, ctx);
        goto after_23;
    // 0x800C54B4: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_23:
    // 0x800C54B8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800C54BC: addiu       $t2, $t2, -0x3F68
    ctx->r10 = ADD32(ctx->r10, -0X3F68);
    // 0x800C54C0: addiu       $t3, $t2, 0x80
    ctx->r11 = ADD32(ctx->r10, 0X80);
    // 0x800C54C4: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    // 0x800C54C8: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    // 0x800C54CC: jal         0x800D6F30
    // 0x800C54D0: addiu       $a0, $t2, 0x40
    ctx->r4 = ADD32(ctx->r10, 0X40);
    guMtxCatF_recomp(rdram, ctx);
        goto after_24;
    // 0x800C54D0: addiu       $a0, $t2, 0x40
    ctx->r4 = ADD32(ctx->r10, 0X40);
    after_24:
    // 0x800C54D4: b           L_800C560C
    // 0x800C54D8: nop

        goto L_800C560C;
    // 0x800C54D8: nop

L_800C54DC:
    // 0x800C54DC: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800C54E0: lwc1        $f12, 0x78($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800C54E4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800C54E8: jal         0x800C4840
    // 0x800C54EC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800C4840(rdram, ctx);
        goto after_25;
    // 0x800C54EC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_25:
    // 0x800C54F0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800C54F4: addiu       $t4, $t4, -0x3F68
    ctx->r12 = ADD32(ctx->r12, -0X3F68);
    // 0x800C54F8: addiu       $t5, $t4, 0x80
    ctx->r13 = ADD32(ctx->r12, 0X80);
    // 0x800C54FC: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
    // 0x800C5500: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
    // 0x800C5504: jal         0x800D6F30
    // 0x800C5508: addiu       $a0, $t4, 0x40
    ctx->r4 = ADD32(ctx->r12, 0X40);
    guMtxCatF_recomp(rdram, ctx);
        goto after_26;
    // 0x800C5508: addiu       $a0, $t4, 0x40
    ctx->r4 = ADD32(ctx->r12, 0X40);
    after_26:
    // 0x800C550C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C5510: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800C5514: lwc1        $f12, 0x70($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800C5518: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800C551C: jal         0x800C4840
    // 0x800C5520: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_800C4840(rdram, ctx);
        goto after_27;
    // 0x800C5520: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_27:
    // 0x800C5524: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800C5528: addiu       $t6, $t6, -0x3F68
    ctx->r14 = ADD32(ctx->r14, -0X3F68);
    // 0x800C552C: addiu       $t7, $t6, 0x80
    ctx->r15 = ADD32(ctx->r14, 0X80);
    // 0x800C5530: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x800C5534: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x800C5538: jal         0x800D6F30
    // 0x800C553C: addiu       $a0, $t6, 0x40
    ctx->r4 = ADD32(ctx->r14, 0X40);
    guMtxCatF_recomp(rdram, ctx);
        goto after_28;
    // 0x800C553C: addiu       $a0, $t6, 0x40
    ctx->r4 = ADD32(ctx->r14, 0X40);
    after_28:
    // 0x800C5540: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800C5544: lwc1        $f12, 0x74($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800C5548: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800C554C: jal         0x800C4840
    // 0x800C5550: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_800C4840(rdram, ctx);
        goto after_29;
    // 0x800C5550: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_29:
    // 0x800C5554: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800C5558: addiu       $t8, $t8, -0x3F68
    ctx->r24 = ADD32(ctx->r24, -0X3F68);
    // 0x800C555C: addiu       $t9, $t8, 0x80
    ctx->r25 = ADD32(ctx->r24, 0X80);
    // 0x800C5560: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x800C5564: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x800C5568: jal         0x800D6F30
    // 0x800C556C: addiu       $a0, $t8, 0x40
    ctx->r4 = ADD32(ctx->r24, 0X40);
    guMtxCatF_recomp(rdram, ctx);
        goto after_30;
    // 0x800C556C: addiu       $a0, $t8, 0x40
    ctx->r4 = ADD32(ctx->r24, 0X40);
    after_30:
    // 0x800C5570: b           L_800C560C
    // 0x800C5574: nop

        goto L_800C560C;
    // 0x800C5574: nop

L_800C5578:
    // 0x800C5578: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C557C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800C5580: lwc1        $f12, 0x70($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800C5584: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800C5588: jal         0x800C4840
    // 0x800C558C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_800C4840(rdram, ctx);
        goto after_31;
    // 0x800C558C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_31:
    // 0x800C5590: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800C5594: addiu       $t0, $t0, -0x3F68
    ctx->r8 = ADD32(ctx->r8, -0X3F68);
    // 0x800C5598: addiu       $t1, $t0, 0x80
    ctx->r9 = ADD32(ctx->r8, 0X80);
    // 0x800C559C: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x800C55A0: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    // 0x800C55A4: jal         0x800D6F30
    // 0x800C55A8: addiu       $a0, $t0, 0x40
    ctx->r4 = ADD32(ctx->r8, 0X40);
    guMtxCatF_recomp(rdram, ctx);
        goto after_32;
    // 0x800C55A8: addiu       $a0, $t0, 0x40
    ctx->r4 = ADD32(ctx->r8, 0X40);
    after_32:
    // 0x800C55AC: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800C55B0: lwc1        $f12, 0x74($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800C55B4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800C55B8: jal         0x800C4840
    // 0x800C55BC: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_800C4840(rdram, ctx);
        goto after_33;
    // 0x800C55BC: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_33:
    // 0x800C55C0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800C55C4: addiu       $t2, $t2, -0x3F68
    ctx->r10 = ADD32(ctx->r10, -0X3F68);
    // 0x800C55C8: addiu       $t3, $t2, 0x80
    ctx->r11 = ADD32(ctx->r10, 0X80);
    // 0x800C55CC: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    // 0x800C55D0: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    // 0x800C55D4: jal         0x800D6F30
    // 0x800C55D8: addiu       $a0, $t2, 0x40
    ctx->r4 = ADD32(ctx->r10, 0X40);
    guMtxCatF_recomp(rdram, ctx);
        goto after_34;
    // 0x800C55D8: addiu       $a0, $t2, 0x40
    ctx->r4 = ADD32(ctx->r10, 0X40);
    after_34:
    // 0x800C55DC: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800C55E0: lwc1        $f12, 0x78($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800C55E4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800C55E8: jal         0x800C4840
    // 0x800C55EC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800C4840(rdram, ctx);
        goto after_35;
    // 0x800C55EC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_35:
    // 0x800C55F0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800C55F4: addiu       $t4, $t4, -0x3F68
    ctx->r12 = ADD32(ctx->r12, -0X3F68);
    // 0x800C55F8: addiu       $t5, $t4, 0x80
    ctx->r13 = ADD32(ctx->r12, 0X80);
    // 0x800C55FC: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
    // 0x800C5600: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
    // 0x800C5604: jal         0x800D6F30
    // 0x800C5608: addiu       $a0, $t4, 0x40
    ctx->r4 = ADD32(ctx->r12, 0X40);
    guMtxCatF_recomp(rdram, ctx);
        goto after_36;
    // 0x800C5608: addiu       $a0, $t4, 0x40
    ctx->r4 = ADD32(ctx->r12, 0X40);
    after_36:
L_800C560C:
    // 0x800C560C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800C5610: addiu       $t6, $t6, -0x3F68
    ctx->r14 = ADD32(ctx->r14, -0X3F68);
    // 0x800C5614: addiu       $a0, $t6, 0x80
    ctx->r4 = ADD32(ctx->r14, 0X80);
    // 0x800C5618: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x800C561C: jal         0x800D6F30
    // 0x800C5620: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    guMtxCatF_recomp(rdram, ctx);
        goto after_37;
    // 0x800C5620: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    after_37:
    // 0x800C5624: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C5628: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x800C562C: jr          $ra
    // 0x800C5630: nop

    return;
    // 0x800C5630: nop

;}
RECOMP_FUNC void func_800C5634(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C5634: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800C5638: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800C563C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C5640: addiu       $a0, $a0, -0x3F68
    ctx->r4 = ADD32(ctx->r4, -0X3F68);
    // 0x800C5644: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x800C5648: jal         0x800D6D20
    // 0x800C564C: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    guMtxIdentF_recomp(rdram, ctx);
        goto after_0;
    // 0x800C564C: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    after_0:
    // 0x800C5650: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C5654: lwc1        $f4, -0x41B0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X41B0);
    // 0x800C5658: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C565C: lwc1        $f6, -0x2BF0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2BF0);
    // 0x800C5660: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x800C5664: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800C5668: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800C566C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800C5670: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800C5674: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800C5678: div.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800C567C: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x800C5680: jal         0x800D6AB0
    // 0x800C5684: mov.s       $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = ctx->f4.fl;
    __cosf_recomp(rdram, ctx);
        goto after_1;
    // 0x800C5684: mov.s       $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = ctx->f4.fl;
    after_1:
    // 0x800C5688: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800C568C: jal         0x800D68F0
    // 0x800C5690: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    sinf_recomp(rdram, ctx);
        goto after_2;
    // 0x800C5690: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x800C5694: div.s       $f6, $f20, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800C5698: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C569C: lwc1        $f10, -0x41AC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X41AC);
    // 0x800C56A0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800C56A4: addiu       $t6, $t6, -0x3F68
    ctx->r14 = ADD32(ctx->r14, -0X3F68);
    // 0x800C56A8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800C56AC: addiu       $t7, $t7, -0x3F68
    ctx->r15 = ADD32(ctx->r15, -0X3F68);
    // 0x800C56B0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C56B4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800C56B8: addiu       $t8, $t8, -0x3F68
    ctx->r24 = ADD32(ctx->r24, -0X3F68);
    // 0x800C56BC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800C56C0: addiu       $t9, $t9, -0x3F68
    ctx->r25 = ADD32(ctx->r25, -0X3F68);
    // 0x800C56C4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800C56C8: addiu       $t0, $t0, -0x3F68
    ctx->r8 = ADD32(ctx->r8, -0X3F68);
    // 0x800C56CC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800C56D0: addiu       $t1, $t1, -0x3F68
    ctx->r9 = ADD32(ctx->r9, -0X3F68);
    // 0x800C56D4: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x800C56D8: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800C56DC: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800C56E0: swc1        $f16, 0x80($t6)
    MEM_W(0X80, ctx->r14) = ctx->f16.u32l;
    // 0x800C56E4: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800C56E8: swc1        $f18, 0x94($t7)
    MEM_W(0X94, ctx->r15) = ctx->f18.u32l;
    // 0x800C56EC: lwc1        $f4, -0x41A8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X41A8);
    // 0x800C56F0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C56F4: lwc1        $f6, -0x41A4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X41A4);
    // 0x800C56F8: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x800C56FC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800C5700: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800C5704: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800C5708: sub.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800C570C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800C5710: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C5714: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800C5718: swc1        $f16, 0xA8($t8)
    MEM_W(0XA8, ctx->r24) = ctx->f16.u32l;
    // 0x800C571C: swc1        $f18, 0xAC($t9)
    MEM_W(0XAC, ctx->r25) = ctx->f18.u32l;
    // 0x800C5720: lwc1        $f6, -0x41A8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X41A8);
    // 0x800C5724: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C5728: lwc1        $f10, -0x41A4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X41A4);
    // 0x800C572C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800C5730: sub.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x800C5734: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800C5738: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800C573C: div.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800C5740: swc1        $f4, 0xB8($t0)
    MEM_W(0XB8, ctx->r8) = ctx->f4.u32l;
    // 0x800C5744: swc1        $f8, 0xBC($t1)
    MEM_W(0XBC, ctx->r9) = ctx->f8.u32l;
    // 0x800C5748: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
L_800C574C:
    // 0x800C574C: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
L_800C5750:
    // 0x800C5750: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x800C5754: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x800C5758: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800C575C: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x800C5760: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800C5764: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x800C5768: addiu       $t7, $t7, -0x3F68
    ctx->r15 = ADD32(ctx->r15, -0X3F68);
    // 0x800C576C: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800C5770: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C5774: lwc1        $f10, -0x41A0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X41A0);
    // 0x800C5778: lwc1        $f6, 0x80($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X80);
    // 0x800C577C: addu        $t9, $t3, $t5
    ctx->r25 = ADD32(ctx->r11, ctx->r13);
    // 0x800C5780: addu        $t0, $t9, $t7
    ctx->r8 = ADD32(ctx->r25, ctx->r15);
    // 0x800C5784: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800C5788: swc1        $f16, 0x80($t0)
    MEM_W(0X80, ctx->r8) = ctx->f16.u32l;
    // 0x800C578C: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x800C5790: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800C5794: sltiu       $at, $t2, 0x4
    ctx->r1 = ctx->r10 < 0X4 ? 1 : 0;
    // 0x800C5798: bne         $at, $zero, L_800C5750
    if (ctx->r1 != 0) {
        // 0x800C579C: sw          $t2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r10;
            goto L_800C5750;
    }
    // 0x800C579C: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x800C57A0: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x800C57A4: addiu       $t6, $t4, 0x1
    ctx->r14 = ADD32(ctx->r12, 0X1);
    // 0x800C57A8: sltiu       $at, $t6, 0x4
    ctx->r1 = ctx->r14 < 0X4 ? 1 : 0;
    // 0x800C57AC: bne         $at, $zero, L_800C574C
    if (ctx->r1 != 0) {
        // 0x800C57B0: sw          $t6, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r14;
            goto L_800C574C;
    }
    // 0x800C57B0: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x800C57B4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C57B8: lwc1        $f18, -0x41A8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X41A8);
    // 0x800C57BC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C57C0: lwc1        $f4, -0x41A4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X41A4);
    // 0x800C57C4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800C57C8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800C57CC: add.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800C57D0: c.le.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl <= ctx->f6.fl;
    // 0x800C57D4: nop

    // 0x800C57D8: bc1f        L_800C57F0
    if (!c1cs) {
        // 0x800C57DC: nop
    
            goto L_800C57F0;
    }
    // 0x800C57DC: nop

    // 0x800C57E0: ori         $t8, $zero, 0xFFFF
    ctx->r24 = 0 | 0XFFFF;
    // 0x800C57E4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C57E8: b           L_800C58B8
    // 0x800C57EC: sh          $t8, -0x41B8($at)
    MEM_H(-0X41B8, ctx->r1) = ctx->r24;
        goto L_800C58B8;
    // 0x800C57EC: sh          $t8, -0x41B8($at)
    MEM_H(-0X41B8, ctx->r1) = ctx->r24;
L_800C57F0:
    // 0x800C57F0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C57F4: lwc1        $f10, -0x41A8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X41A8);
    // 0x800C57F8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C57FC: lwc1        $f16, -0x41A4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X41A4);
    // 0x800C5800: lui         $at, 0x4800
    ctx->r1 = S32(0X4800 << 16);
    // 0x800C5804: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800C5808: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800C580C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800C5810: div.s       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f18.fl);
    // 0x800C5814: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800C5818: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800C581C: nop

    // 0x800C5820: cvt.w.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800C5824: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800C5828: nop

    // 0x800C582C: andi        $at, $t5, 0x4
    ctx->r1 = ctx->r13 & 0X4;
    // 0x800C5830: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x800C5834: beq         $t5, $zero, L_800C5884
    if (ctx->r13 == 0) {
        // 0x800C5838: lui         $at, 0x4F00
        ctx->r1 = S32(0X4F00 << 16);
            goto L_800C5884;
    }
    // 0x800C5838: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800C583C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800C5840: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800C5844: sub.s       $f6, $f8, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x800C5848: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800C584C: nop

    // 0x800C5850: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800C5854: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800C5858: nop

    // 0x800C585C: andi        $at, $t5, 0x4
    ctx->r1 = ctx->r13 & 0X4;
    // 0x800C5860: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x800C5864: bne         $t5, $zero, L_800C587C
    if (ctx->r13 != 0) {
        // 0x800C5868: nop
    
            goto L_800C587C;
    }
    // 0x800C5868: nop

    // 0x800C586C: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x800C5870: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C5874: b           L_800C5894
    // 0x800C5878: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
        goto L_800C5894;
    // 0x800C5878: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
L_800C587C:
    // 0x800C587C: b           L_800C5894
    // 0x800C5880: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
        goto L_800C5894;
    // 0x800C5880: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
L_800C5884:
    // 0x800C5884: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x800C5888: nop

    // 0x800C588C: bltz        $t5, L_800C587C
    if (SIGNED(ctx->r13) < 0) {
        // 0x800C5890: nop
    
            goto L_800C587C;
    }
    // 0x800C5890: nop

L_800C5894:
    // 0x800C5894: andi        $t9, $t5, 0xFFFF
    ctx->r25 = ctx->r13 & 0XFFFF;
    // 0x800C5898: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800C589C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C58A0: andi        $t7, $t9, 0xFFFF
    ctx->r15 = ctx->r25 & 0XFFFF;
    // 0x800C58A4: bgtz        $t7, L_800C58B8
    if (SIGNED(ctx->r15) > 0) {
        // 0x800C58A8: sh          $t9, -0x41B8($at)
        MEM_H(-0X41B8, ctx->r1) = ctx->r25;
            goto L_800C58B8;
    }
    // 0x800C58A8: sh          $t9, -0x41B8($at)
    MEM_H(-0X41B8, ctx->r1) = ctx->r25;
    // 0x800C58AC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800C58B0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C58B4: sh          $t0, -0x41B8($at)
    MEM_H(-0X41B8, ctx->r1) = ctx->r8;
L_800C58B8:
    // 0x800C58B8: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x800C58BC: lw          $a1, 0x3AF0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X3AF0);
    // 0x800C58C0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800C58C4: addiu       $a0, $a0, -0x3F68
    ctx->r4 = ADD32(ctx->r4, -0X3F68);
    // 0x800C58C8: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    // 0x800C58CC: jal         0x800D6C20
    // 0x800C58D0: addiu       $a1, $a1, 0x30
    ctx->r5 = ADD32(ctx->r5, 0X30);
    guMtxF2L_recomp(rdram, ctx);
        goto after_3;
    // 0x800C58D0: addiu       $a1, $a1, 0x30
    ctx->r5 = ADD32(ctx->r5, 0X30);
    after_3:
    // 0x800C58D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C58D8: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x800C58DC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800C58E0: jr          $ra
    // 0x800C58E4: nop

    return;
    // 0x800C58E4: nop

;}
RECOMP_FUNC void func_800C58E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C58E8: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800C58EC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800C58F0: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x800C58F4: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x800C58F8: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x800C58FC: jal         0x800C46AC
    // 0x800C5900: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    func_800C46AC(rdram, ctx);
        goto after_0;
    // 0x800C5900: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    after_0:
    // 0x800C5904: bltz        $v0, L_800C5B84
    if (SIGNED(ctx->r2) < 0) {
        // 0x800C5908: nop
    
            goto L_800C5B84;
    }
    // 0x800C5908: nop

    // 0x800C590C: jal         0x800C5634
    // 0x800C5910: nop

    func_800C5634(rdram, ctx);
        goto after_1;
    // 0x800C5910: nop

    after_1:
    // 0x800C5914: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x800C5918: lw          $t6, -0x4514($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4514);
    // 0x800C591C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C5920: lui         $t8, 0xDA38
    ctx->r24 = S32(0XDA38 << 16);
    // 0x800C5924: sw          $t6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r14;
    // 0x800C5928: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x800C592C: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800C5930: sw          $t7, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r15;
    // 0x800C5934: ori         $t8, $t8, 0x7
    ctx->r24 = ctx->r24 | 0X7;
    // 0x800C5938: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800C593C: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x800C5940: lw          $a0, 0x3AF0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3AF0);
    // 0x800C5944: jal         0x800D70A0
    // 0x800C5948: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_2;
    // 0x800C5948: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    after_2:
    // 0x800C594C: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x800C5950: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x800C5954: sw          $v0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r2;
    // 0x800C5958: lhu         $t1, -0x4530($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X4530);
    // 0x800C595C: andi        $t2, $t1, 0x8000
    ctx->r10 = ctx->r9 & 0X8000;
    // 0x800C5960: bne         $t2, $zero, L_800C5A08
    if (ctx->r10 != 0) {
        // 0x800C5964: nop
    
            goto L_800C5A08;
    }
    // 0x800C5964: nop

    // 0x800C5968: lui         $t3, 0x8011
    ctx->r11 = S32(0X8011 << 16);
    // 0x800C596C: lw          $t3, -0x4514($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4514);
    // 0x800C5970: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C5974: lui         $t5, 0xDA38
    ctx->r13 = S32(0XDA38 << 16);
    // 0x800C5978: sw          $t3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r11;
    // 0x800C597C: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x800C5980: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x800C5984: sw          $t4, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r12;
    // 0x800C5988: ori         $t5, $t5, 0x3
    ctx->r13 = ctx->r13 | 0X3;
    // 0x800C598C: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x800C5990: lbu         $t8, 0x57($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X57);
    // 0x800C5994: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x800C5998: lw          $t7, 0x3AF0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3AF0);
    // 0x800C599C: sll         $t9, $t8, 6
    ctx->r25 = S32(ctx->r24 << 6);
    // 0x800C59A0: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    // 0x800C59A4: jal         0x800D70A0
    // 0x800C59A8: addiu       $a0, $a0, 0x70
    ctx->r4 = ADD32(ctx->r4, 0X70);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_3;
    // 0x800C59A8: addiu       $a0, $a0, 0x70
    ctx->r4 = ADD32(ctx->r4, 0X70);
    after_3:
    // 0x800C59AC: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x800C59B0: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x800C59B4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C59B8: sw          $v0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r2;
    // 0x800C59BC: lw          $t1, -0x4514($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4514);
    // 0x800C59C0: lui         $t3, 0xDA38
    ctx->r11 = S32(0XDA38 << 16);
    // 0x800C59C4: ori         $t3, $t3, 0x1
    ctx->r11 = ctx->r11 | 0X1;
    // 0x800C59C8: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    // 0x800C59CC: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x800C59D0: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x800C59D4: sw          $t2, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r10;
    // 0x800C59D8: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x800C59DC: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x800C59E0: lw          $t6, -0x4524($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4524);
    // 0x800C59E4: lui         $t5, 0x8011
    ctx->r13 = S32(0X8011 << 16);
    // 0x800C59E8: lw          $t5, 0x3AF0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X3AF0);
    // 0x800C59EC: sll         $t8, $t6, 6
    ctx->r24 = S32(ctx->r14 << 6);
    // 0x800C59F0: addu        $a0, $t5, $t8
    ctx->r4 = ADD32(ctx->r13, ctx->r24);
    // 0x800C59F4: jal         0x800D70A0
    // 0x800C59F8: addiu       $a0, $a0, 0x170
    ctx->r4 = ADD32(ctx->r4, 0X170);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_4;
    // 0x800C59F8: addiu       $a0, $a0, 0x170
    ctx->r4 = ADD32(ctx->r4, 0X170);
    after_4:
    // 0x800C59FC: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x800C5A00: b           L_800C5AA4
    // 0x800C5A04: sw          $v0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r2;
        goto L_800C5AA4;
    // 0x800C5A04: sw          $v0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r2;
L_800C5A08:
    // 0x800C5A08: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x800C5A0C: lw          $t9, -0x4514($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4514);
    // 0x800C5A10: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C5A14: lui         $t1, 0xDA38
    ctx->r9 = S32(0XDA38 << 16);
    // 0x800C5A18: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    // 0x800C5A1C: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x800C5A20: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x800C5A24: sw          $t0, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r8;
    // 0x800C5A28: ori         $t1, $t1, 0x5
    ctx->r9 = ctx->r9 | 0X5;
    // 0x800C5A2C: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x800C5A30: lbu         $t4, 0x57($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X57);
    // 0x800C5A34: lui         $t3, 0x8011
    ctx->r11 = S32(0X8011 << 16);
    // 0x800C5A38: lw          $t3, 0x3AF0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X3AF0);
    // 0x800C5A3C: sll         $t6, $t4, 6
    ctx->r14 = S32(ctx->r12 << 6);
    // 0x800C5A40: addu        $a0, $t3, $t6
    ctx->r4 = ADD32(ctx->r11, ctx->r14);
    // 0x800C5A44: jal         0x800D70A0
    // 0x800C5A48: addiu       $a0, $a0, 0x70
    ctx->r4 = ADD32(ctx->r4, 0X70);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_5;
    // 0x800C5A48: addiu       $a0, $a0, 0x70
    ctx->r4 = ADD32(ctx->r4, 0X70);
    after_5:
    // 0x800C5A4C: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x800C5A50: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x800C5A54: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C5A58: sw          $v0, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r2;
    // 0x800C5A5C: lw          $t8, -0x4514($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4514);
    // 0x800C5A60: lui         $t9, 0xDA38
    ctx->r25 = S32(0XDA38 << 16);
    // 0x800C5A64: ori         $t9, $t9, 0x3
    ctx->r25 = ctx->r25 | 0X3;
    // 0x800C5A68: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x800C5A6C: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x800C5A70: addiu       $t7, $t8, 0x8
    ctx->r15 = ADD32(ctx->r24, 0X8);
    // 0x800C5A74: sw          $t7, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r15;
    // 0x800C5A78: lui         $t2, 0x8011
    ctx->r10 = S32(0X8011 << 16);
    // 0x800C5A7C: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800C5A80: lw          $t2, -0x4524($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4524);
    // 0x800C5A84: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x800C5A88: lw          $t1, 0x3AF0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X3AF0);
    // 0x800C5A8C: sll         $t4, $t2, 6
    ctx->r12 = S32(ctx->r10 << 6);
    // 0x800C5A90: addu        $a0, $t1, $t4
    ctx->r4 = ADD32(ctx->r9, ctx->r12);
    // 0x800C5A94: jal         0x800D70A0
    // 0x800C5A98: addiu       $a0, $a0, 0x170
    ctx->r4 = ADD32(ctx->r4, 0X170);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_6;
    // 0x800C5A98: addiu       $a0, $a0, 0x170
    ctx->r4 = ADD32(ctx->r4, 0X170);
    after_6:
    // 0x800C5A9C: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x800C5AA0: sw          $v0, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r2;
L_800C5AA4:
    // 0x800C5AA4: lwc1        $f4, 0x68($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800C5AA8: lwc1        $f6, 0x6C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800C5AAC: lwc1        $f8, 0x70($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800C5AB0: lwc1        $f10, 0x74($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800C5AB4: lwc1        $f16, 0x78($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800C5AB8: lh          $t6, 0x7E($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X7E);
    // 0x800C5ABC: lwc1        $f12, 0x58($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800C5AC0: lwc1        $f14, 0x5C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800C5AC4: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    // 0x800C5AC8: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    // 0x800C5ACC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800C5AD0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x800C5AD4: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x800C5AD8: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x800C5ADC: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x800C5AE0: jal         0x800C4A04
    // 0x800C5AE4: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    func_800C4A04(rdram, ctx);
        goto after_7;
    // 0x800C5AE4: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_7:
    // 0x800C5AE8: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x800C5AEC: lw          $t8, -0x4524($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4524);
    // 0x800C5AF0: lui         $t5, 0x8011
    ctx->r13 = S32(0X8011 << 16);
    // 0x800C5AF4: lw          $t5, 0x3AF0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X3AF0);
    // 0x800C5AF8: sll         $t7, $t8, 6
    ctx->r15 = S32(ctx->r24 << 6);
    // 0x800C5AFC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800C5B00: addu        $a1, $t5, $t7
    ctx->r5 = ADD32(ctx->r13, ctx->r15);
    // 0x800C5B04: addiu       $a1, $a1, 0x170
    ctx->r5 = ADD32(ctx->r5, 0X170);
    // 0x800C5B08: jal         0x800D6C20
    // 0x800C5B0C: addiu       $a0, $a0, -0x3F68
    ctx->r4 = ADD32(ctx->r4, -0X3F68);
    guMtxF2L_recomp(rdram, ctx);
        goto after_8;
    // 0x800C5B0C: addiu       $a0, $a0, -0x3F68
    ctx->r4 = ADD32(ctx->r4, -0X3F68);
    after_8:
    // 0x800C5B10: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x800C5B14: lw          $t9, -0x4514($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4514);
    // 0x800C5B18: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C5B1C: lui         $t2, 0xDB0E
    ctx->r10 = S32(0XDB0E << 16);
    // 0x800C5B20: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
    // 0x800C5B24: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x800C5B28: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x800C5B2C: sw          $t0, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r8;
    // 0x800C5B30: sw          $t2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r10;
    // 0x800C5B34: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800C5B38: lhu         $t4, -0x41B8($t4)
    ctx->r12 = MEM_HU(ctx->r12, -0X41B8);
    // 0x800C5B3C: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x800C5B40: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x800C5B44: lui         $t5, 0xDE00
    ctx->r13 = S32(0XDE00 << 16);
    // 0x800C5B48: sw          $t4, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r12;
    // 0x800C5B4C: lw          $t6, -0x4514($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4514);
    // 0x800C5B50: lui         $t2, 0x8011
    ctx->r10 = S32(0X8011 << 16);
    // 0x800C5B54: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x800C5B58: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x800C5B5C: addiu       $t8, $t6, 0x8
    ctx->r24 = ADD32(ctx->r14, 0X8);
    // 0x800C5B60: sw          $t8, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r24;
    // 0x800C5B64: sw          $t5, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r13;
    // 0x800C5B68: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x800C5B6C: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x800C5B70: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C5B74: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x800C5B78: lw          $t2, -0x4524($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4524);
    // 0x800C5B7C: addiu       $t1, $t2, 0x1
    ctx->r9 = ADD32(ctx->r10, 0X1);
    // 0x800C5B80: sw          $t1, -0x4524($at)
    MEM_W(-0X4524, ctx->r1) = ctx->r9;
L_800C5B84:
    // 0x800C5B84: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800C5B88: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x800C5B8C: jr          $ra
    // 0x800C5B90: nop

    return;
    // 0x800C5B90: nop

;}
RECOMP_FUNC void func_800C5B94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C5B94: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800C5B98: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800C5B9C: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x800C5BA0: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x800C5BA4: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x800C5BA8: jal         0x800C46AC
    // 0x800C5BAC: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    func_800C46AC(rdram, ctx);
        goto after_0;
    // 0x800C5BAC: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    after_0:
    // 0x800C5BB0: bltz        $v0, L_800C5E30
    if (SIGNED(ctx->r2) < 0) {
        // 0x800C5BB4: nop
    
            goto L_800C5E30;
    }
    // 0x800C5BB4: nop

    // 0x800C5BB8: jal         0x800C5634
    // 0x800C5BBC: nop

    func_800C5634(rdram, ctx);
        goto after_1;
    // 0x800C5BBC: nop

    after_1:
    // 0x800C5BC0: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x800C5BC4: lw          $t6, -0x4514($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4514);
    // 0x800C5BC8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C5BCC: lui         $t8, 0xDA38
    ctx->r24 = S32(0XDA38 << 16);
    // 0x800C5BD0: sw          $t6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r14;
    // 0x800C5BD4: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x800C5BD8: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800C5BDC: sw          $t7, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r15;
    // 0x800C5BE0: ori         $t8, $t8, 0x7
    ctx->r24 = ctx->r24 | 0X7;
    // 0x800C5BE4: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800C5BE8: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x800C5BEC: lw          $a0, 0x3AF0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3AF0);
    // 0x800C5BF0: jal         0x800D70A0
    // 0x800C5BF4: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_2;
    // 0x800C5BF4: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    after_2:
    // 0x800C5BF8: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x800C5BFC: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x800C5C00: sw          $v0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r2;
    // 0x800C5C04: lhu         $t1, -0x4530($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X4530);
    // 0x800C5C08: andi        $t2, $t1, 0x8000
    ctx->r10 = ctx->r9 & 0X8000;
    // 0x800C5C0C: bne         $t2, $zero, L_800C5CB4
    if (ctx->r10 != 0) {
        // 0x800C5C10: nop
    
            goto L_800C5CB4;
    }
    // 0x800C5C10: nop

    // 0x800C5C14: lui         $t3, 0x8011
    ctx->r11 = S32(0X8011 << 16);
    // 0x800C5C18: lw          $t3, -0x4514($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4514);
    // 0x800C5C1C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C5C20: lui         $t5, 0xDA38
    ctx->r13 = S32(0XDA38 << 16);
    // 0x800C5C24: sw          $t3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r11;
    // 0x800C5C28: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x800C5C2C: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x800C5C30: sw          $t4, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r12;
    // 0x800C5C34: ori         $t5, $t5, 0x3
    ctx->r13 = ctx->r13 | 0X3;
    // 0x800C5C38: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x800C5C3C: lbu         $t8, 0x57($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X57);
    // 0x800C5C40: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x800C5C44: lw          $t7, 0x3AF0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3AF0);
    // 0x800C5C48: sll         $t9, $t8, 6
    ctx->r25 = S32(ctx->r24 << 6);
    // 0x800C5C4C: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    // 0x800C5C50: jal         0x800D70A0
    // 0x800C5C54: addiu       $a0, $a0, 0x70
    ctx->r4 = ADD32(ctx->r4, 0X70);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_3;
    // 0x800C5C54: addiu       $a0, $a0, 0x70
    ctx->r4 = ADD32(ctx->r4, 0X70);
    after_3:
    // 0x800C5C58: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x800C5C5C: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x800C5C60: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C5C64: sw          $v0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r2;
    // 0x800C5C68: lw          $t1, -0x4514($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4514);
    // 0x800C5C6C: lui         $t3, 0xDA38
    ctx->r11 = S32(0XDA38 << 16);
    // 0x800C5C70: ori         $t3, $t3, 0x1
    ctx->r11 = ctx->r11 | 0X1;
    // 0x800C5C74: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    // 0x800C5C78: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x800C5C7C: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x800C5C80: sw          $t2, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r10;
    // 0x800C5C84: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x800C5C88: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x800C5C8C: lw          $t6, -0x4524($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4524);
    // 0x800C5C90: lui         $t5, 0x8011
    ctx->r13 = S32(0X8011 << 16);
    // 0x800C5C94: lw          $t5, 0x3AF0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X3AF0);
    // 0x800C5C98: sll         $t8, $t6, 6
    ctx->r24 = S32(ctx->r14 << 6);
    // 0x800C5C9C: addu        $a0, $t5, $t8
    ctx->r4 = ADD32(ctx->r13, ctx->r24);
    // 0x800C5CA0: jal         0x800D70A0
    // 0x800C5CA4: addiu       $a0, $a0, 0x170
    ctx->r4 = ADD32(ctx->r4, 0X170);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_4;
    // 0x800C5CA4: addiu       $a0, $a0, 0x170
    ctx->r4 = ADD32(ctx->r4, 0X170);
    after_4:
    // 0x800C5CA8: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x800C5CAC: b           L_800C5D50
    // 0x800C5CB0: sw          $v0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r2;
        goto L_800C5D50;
    // 0x800C5CB0: sw          $v0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r2;
L_800C5CB4:
    // 0x800C5CB4: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x800C5CB8: lw          $t9, -0x4514($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4514);
    // 0x800C5CBC: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C5CC0: lui         $t1, 0xDA38
    ctx->r9 = S32(0XDA38 << 16);
    // 0x800C5CC4: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    // 0x800C5CC8: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x800C5CCC: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x800C5CD0: sw          $t0, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r8;
    // 0x800C5CD4: ori         $t1, $t1, 0x5
    ctx->r9 = ctx->r9 | 0X5;
    // 0x800C5CD8: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x800C5CDC: lbu         $t4, 0x57($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X57);
    // 0x800C5CE0: lui         $t3, 0x8011
    ctx->r11 = S32(0X8011 << 16);
    // 0x800C5CE4: lw          $t3, 0x3AF0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X3AF0);
    // 0x800C5CE8: sll         $t6, $t4, 6
    ctx->r14 = S32(ctx->r12 << 6);
    // 0x800C5CEC: addu        $a0, $t3, $t6
    ctx->r4 = ADD32(ctx->r11, ctx->r14);
    // 0x800C5CF0: jal         0x800D70A0
    // 0x800C5CF4: addiu       $a0, $a0, 0x70
    ctx->r4 = ADD32(ctx->r4, 0X70);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_5;
    // 0x800C5CF4: addiu       $a0, $a0, 0x70
    ctx->r4 = ADD32(ctx->r4, 0X70);
    after_5:
    // 0x800C5CF8: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x800C5CFC: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x800C5D00: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C5D04: sw          $v0, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r2;
    // 0x800C5D08: lw          $t8, -0x4514($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4514);
    // 0x800C5D0C: lui         $t9, 0xDA38
    ctx->r25 = S32(0XDA38 << 16);
    // 0x800C5D10: ori         $t9, $t9, 0x3
    ctx->r25 = ctx->r25 | 0X3;
    // 0x800C5D14: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x800C5D18: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x800C5D1C: addiu       $t7, $t8, 0x8
    ctx->r15 = ADD32(ctx->r24, 0X8);
    // 0x800C5D20: sw          $t7, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r15;
    // 0x800C5D24: lui         $t2, 0x8011
    ctx->r10 = S32(0X8011 << 16);
    // 0x800C5D28: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800C5D2C: lw          $t2, -0x4524($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4524);
    // 0x800C5D30: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x800C5D34: lw          $t1, 0x3AF0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X3AF0);
    // 0x800C5D38: sll         $t4, $t2, 6
    ctx->r12 = S32(ctx->r10 << 6);
    // 0x800C5D3C: addu        $a0, $t1, $t4
    ctx->r4 = ADD32(ctx->r9, ctx->r12);
    // 0x800C5D40: jal         0x800D70A0
    // 0x800C5D44: addiu       $a0, $a0, 0x170
    ctx->r4 = ADD32(ctx->r4, 0X170);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_6;
    // 0x800C5D44: addiu       $a0, $a0, 0x170
    ctx->r4 = ADD32(ctx->r4, 0X170);
    after_6:
    // 0x800C5D48: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x800C5D4C: sw          $v0, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r2;
L_800C5D50:
    // 0x800C5D50: lwc1        $f4, 0x68($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800C5D54: lwc1        $f6, 0x6C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800C5D58: lwc1        $f8, 0x70($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800C5D5C: lwc1        $f10, 0x74($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800C5D60: lwc1        $f16, 0x78($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800C5D64: lh          $t6, 0x7E($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X7E);
    // 0x800C5D68: lwc1        $f12, 0x58($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800C5D6C: lwc1        $f14, 0x5C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800C5D70: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    // 0x800C5D74: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    // 0x800C5D78: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800C5D7C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x800C5D80: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x800C5D84: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x800C5D88: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x800C5D8C: jal         0x800C501C
    // 0x800C5D90: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    func_800C501C(rdram, ctx);
        goto after_7;
    // 0x800C5D90: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_7:
    // 0x800C5D94: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x800C5D98: lw          $t8, -0x4524($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4524);
    // 0x800C5D9C: lui         $t5, 0x8011
    ctx->r13 = S32(0X8011 << 16);
    // 0x800C5DA0: lw          $t5, 0x3AF0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X3AF0);
    // 0x800C5DA4: sll         $t7, $t8, 6
    ctx->r15 = S32(ctx->r24 << 6);
    // 0x800C5DA8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800C5DAC: addu        $a1, $t5, $t7
    ctx->r5 = ADD32(ctx->r13, ctx->r15);
    // 0x800C5DB0: addiu       $a1, $a1, 0x170
    ctx->r5 = ADD32(ctx->r5, 0X170);
    // 0x800C5DB4: jal         0x800D6C20
    // 0x800C5DB8: addiu       $a0, $a0, -0x3F68
    ctx->r4 = ADD32(ctx->r4, -0X3F68);
    guMtxF2L_recomp(rdram, ctx);
        goto after_8;
    // 0x800C5DB8: addiu       $a0, $a0, -0x3F68
    ctx->r4 = ADD32(ctx->r4, -0X3F68);
    after_8:
    // 0x800C5DBC: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x800C5DC0: lw          $t9, -0x4514($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4514);
    // 0x800C5DC4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C5DC8: lui         $t2, 0xDB0E
    ctx->r10 = S32(0XDB0E << 16);
    // 0x800C5DCC: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
    // 0x800C5DD0: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x800C5DD4: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x800C5DD8: sw          $t0, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r8;
    // 0x800C5DDC: sw          $t2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r10;
    // 0x800C5DE0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800C5DE4: lhu         $t4, -0x41B8($t4)
    ctx->r12 = MEM_HU(ctx->r12, -0X41B8);
    // 0x800C5DE8: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x800C5DEC: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x800C5DF0: lui         $t5, 0xDE00
    ctx->r13 = S32(0XDE00 << 16);
    // 0x800C5DF4: sw          $t4, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r12;
    // 0x800C5DF8: lw          $t6, -0x4514($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4514);
    // 0x800C5DFC: lui         $t2, 0x8011
    ctx->r10 = S32(0X8011 << 16);
    // 0x800C5E00: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x800C5E04: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x800C5E08: addiu       $t8, $t6, 0x8
    ctx->r24 = ADD32(ctx->r14, 0X8);
    // 0x800C5E0C: sw          $t8, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r24;
    // 0x800C5E10: sw          $t5, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r13;
    // 0x800C5E14: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x800C5E18: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x800C5E1C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C5E20: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x800C5E24: lw          $t2, -0x4524($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4524);
    // 0x800C5E28: addiu       $t1, $t2, 0x1
    ctx->r9 = ADD32(ctx->r10, 0X1);
    // 0x800C5E2C: sw          $t1, -0x4524($at)
    MEM_W(-0X4524, ctx->r1) = ctx->r9;
L_800C5E30:
    // 0x800C5E30: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800C5E34: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x800C5E38: jr          $ra
    // 0x800C5E3C: nop

    return;
    // 0x800C5E3C: nop

;}
RECOMP_FUNC void func_800C5E40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C5E40: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800C5E44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C5E48: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800C5E4C: jal         0x800C46AC
    // 0x800C5E50: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    func_800C46AC(rdram, ctx);
        goto after_0;
    // 0x800C5E50: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800C5E54: bltz        $v0, L_800C6090
    if (SIGNED(ctx->r2) < 0) {
        // 0x800C5E58: nop
    
            goto L_800C6090;
    }
    // 0x800C5E58: nop

    // 0x800C5E5C: jal         0x800C5634
    // 0x800C5E60: nop

    func_800C5634(rdram, ctx);
        goto after_1;
    // 0x800C5E60: nop

    after_1:
    // 0x800C5E64: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x800C5E68: lw          $t6, -0x4514($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4514);
    // 0x800C5E6C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C5E70: lui         $t8, 0xDA38
    ctx->r24 = S32(0XDA38 << 16);
    // 0x800C5E74: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x800C5E78: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x800C5E7C: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800C5E80: sw          $t7, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r15;
    // 0x800C5E84: ori         $t8, $t8, 0x7
    ctx->r24 = ctx->r24 | 0X7;
    // 0x800C5E88: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800C5E8C: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x800C5E90: lw          $a0, 0x3AF0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3AF0);
    // 0x800C5E94: jal         0x800D70A0
    // 0x800C5E98: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_2;
    // 0x800C5E98: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    after_2:
    // 0x800C5E9C: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x800C5EA0: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x800C5EA4: sw          $v0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r2;
    // 0x800C5EA8: lhu         $t1, -0x4530($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X4530);
    // 0x800C5EAC: andi        $t2, $t1, 0x8000
    ctx->r10 = ctx->r9 & 0X8000;
    // 0x800C5EB0: bne         $t2, $zero, L_800C5F58
    if (ctx->r10 != 0) {
        // 0x800C5EB4: nop
    
            goto L_800C5F58;
    }
    // 0x800C5EB4: nop

    // 0x800C5EB8: lui         $t3, 0x8011
    ctx->r11 = S32(0X8011 << 16);
    // 0x800C5EBC: lw          $t3, -0x4514($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4514);
    // 0x800C5EC0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C5EC4: lui         $t5, 0xDA38
    ctx->r13 = S32(0XDA38 << 16);
    // 0x800C5EC8: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x800C5ECC: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800C5ED0: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x800C5ED4: sw          $t4, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r12;
    // 0x800C5ED8: ori         $t5, $t5, 0x3
    ctx->r13 = ctx->r13 | 0X3;
    // 0x800C5EDC: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x800C5EE0: lbu         $t8, 0x3F($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X3F);
    // 0x800C5EE4: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x800C5EE8: lw          $t7, 0x3AF0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3AF0);
    // 0x800C5EEC: sll         $t9, $t8, 6
    ctx->r25 = S32(ctx->r24 << 6);
    // 0x800C5EF0: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    // 0x800C5EF4: jal         0x800D70A0
    // 0x800C5EF8: addiu       $a0, $a0, 0x70
    ctx->r4 = ADD32(ctx->r4, 0X70);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_3;
    // 0x800C5EF8: addiu       $a0, $a0, 0x70
    ctx->r4 = ADD32(ctx->r4, 0X70);
    after_3:
    // 0x800C5EFC: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x800C5F00: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x800C5F04: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C5F08: sw          $v0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r2;
    // 0x800C5F0C: lw          $t1, -0x4514($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4514);
    // 0x800C5F10: lui         $t3, 0xDA38
    ctx->r11 = S32(0XDA38 << 16);
    // 0x800C5F14: ori         $t3, $t3, 0x1
    ctx->r11 = ctx->r11 | 0X1;
    // 0x800C5F18: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x800C5F1C: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x800C5F20: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x800C5F24: sw          $t2, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r10;
    // 0x800C5F28: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x800C5F2C: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x800C5F30: lw          $t6, -0x4524($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4524);
    // 0x800C5F34: lui         $t5, 0x8011
    ctx->r13 = S32(0X8011 << 16);
    // 0x800C5F38: lw          $t5, 0x3AF0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X3AF0);
    // 0x800C5F3C: sll         $t8, $t6, 6
    ctx->r24 = S32(ctx->r14 << 6);
    // 0x800C5F40: addu        $a0, $t5, $t8
    ctx->r4 = ADD32(ctx->r13, ctx->r24);
    // 0x800C5F44: jal         0x800D70A0
    // 0x800C5F48: addiu       $a0, $a0, 0x170
    ctx->r4 = ADD32(ctx->r4, 0X170);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_4;
    // 0x800C5F48: addiu       $a0, $a0, 0x170
    ctx->r4 = ADD32(ctx->r4, 0X170);
    after_4:
    // 0x800C5F4C: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800C5F50: b           L_800C5FF4
    // 0x800C5F54: sw          $v0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r2;
        goto L_800C5FF4;
    // 0x800C5F54: sw          $v0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r2;
L_800C5F58:
    // 0x800C5F58: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x800C5F5C: lw          $t9, -0x4514($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4514);
    // 0x800C5F60: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C5F64: lui         $t1, 0xDA38
    ctx->r9 = S32(0XDA38 << 16);
    // 0x800C5F68: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x800C5F6C: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800C5F70: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x800C5F74: sw          $t0, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r8;
    // 0x800C5F78: ori         $t1, $t1, 0x5
    ctx->r9 = ctx->r9 | 0X5;
    // 0x800C5F7C: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x800C5F80: lbu         $t4, 0x3F($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X3F);
    // 0x800C5F84: lui         $t3, 0x8011
    ctx->r11 = S32(0X8011 << 16);
    // 0x800C5F88: lw          $t3, 0x3AF0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X3AF0);
    // 0x800C5F8C: sll         $t6, $t4, 6
    ctx->r14 = S32(ctx->r12 << 6);
    // 0x800C5F90: addu        $a0, $t3, $t6
    ctx->r4 = ADD32(ctx->r11, ctx->r14);
    // 0x800C5F94: jal         0x800D70A0
    // 0x800C5F98: addiu       $a0, $a0, 0x70
    ctx->r4 = ADD32(ctx->r4, 0X70);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_5;
    // 0x800C5F98: addiu       $a0, $a0, 0x70
    ctx->r4 = ADD32(ctx->r4, 0X70);
    after_5:
    // 0x800C5F9C: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x800C5FA0: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x800C5FA4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C5FA8: sw          $v0, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r2;
    // 0x800C5FAC: lw          $t8, -0x4514($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4514);
    // 0x800C5FB0: lui         $t9, 0xDA38
    ctx->r25 = S32(0XDA38 << 16);
    // 0x800C5FB4: ori         $t9, $t9, 0x3
    ctx->r25 = ctx->r25 | 0X3;
    // 0x800C5FB8: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x800C5FBC: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800C5FC0: addiu       $t7, $t8, 0x8
    ctx->r15 = ADD32(ctx->r24, 0X8);
    // 0x800C5FC4: sw          $t7, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r15;
    // 0x800C5FC8: lui         $t2, 0x8011
    ctx->r10 = S32(0X8011 << 16);
    // 0x800C5FCC: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800C5FD0: lw          $t2, -0x4524($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4524);
    // 0x800C5FD4: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x800C5FD8: lw          $t1, 0x3AF0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X3AF0);
    // 0x800C5FDC: sll         $t4, $t2, 6
    ctx->r12 = S32(ctx->r10 << 6);
    // 0x800C5FE0: addu        $a0, $t1, $t4
    ctx->r4 = ADD32(ctx->r9, ctx->r12);
    // 0x800C5FE4: jal         0x800D70A0
    // 0x800C5FE8: addiu       $a0, $a0, 0x170
    ctx->r4 = ADD32(ctx->r4, 0X170);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_6;
    // 0x800C5FE8: addiu       $a0, $a0, 0x170
    ctx->r4 = ADD32(ctx->r4, 0X170);
    after_6:
    // 0x800C5FEC: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x800C5FF0: sw          $v0, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r2;
L_800C5FF4:
    // 0x800C5FF4: lui         $t5, 0x8011
    ctx->r13 = S32(0X8011 << 16);
    // 0x800C5FF8: lw          $t5, -0x4524($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4524);
    // 0x800C5FFC: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x800C6000: lw          $t6, 0x3AF0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3AF0);
    // 0x800C6004: sll         $t8, $t5, 6
    ctx->r24 = S32(ctx->r13 << 6);
    // 0x800C6008: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800C600C: addu        $a1, $t6, $t8
    ctx->r5 = ADD32(ctx->r14, ctx->r24);
    // 0x800C6010: addiu       $a1, $a1, 0x170
    ctx->r5 = ADD32(ctx->r5, 0X170);
    // 0x800C6014: jal         0x800D6C20
    // 0x800C6018: addiu       $a0, $a0, -0x3F68
    ctx->r4 = ADD32(ctx->r4, -0X3F68);
    guMtxF2L_recomp(rdram, ctx);
        goto after_7;
    // 0x800C6018: addiu       $a0, $a0, -0x3F68
    ctx->r4 = ADD32(ctx->r4, -0X3F68);
    after_7:
    // 0x800C601C: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x800C6020: lw          $t7, -0x4514($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4514);
    // 0x800C6024: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C6028: lui         $t0, 0xDB0E
    ctx->r8 = S32(0XDB0E << 16);
    // 0x800C602C: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x800C6030: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x800C6034: addiu       $t9, $t7, 0x8
    ctx->r25 = ADD32(ctx->r15, 0X8);
    // 0x800C6038: sw          $t9, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r25;
    // 0x800C603C: sw          $t0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r8;
    // 0x800C6040: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800C6044: lhu         $t1, -0x41B8($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X41B8);
    // 0x800C6048: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x800C604C: lui         $t3, 0x8011
    ctx->r11 = S32(0X8011 << 16);
    // 0x800C6050: lui         $t6, 0xDE00
    ctx->r14 = S32(0XDE00 << 16);
    // 0x800C6054: sw          $t1, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r9;
    // 0x800C6058: lw          $t3, -0x4514($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4514);
    // 0x800C605C: lui         $t0, 0x8011
    ctx->r8 = S32(0X8011 << 16);
    // 0x800C6060: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x800C6064: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800C6068: addiu       $t5, $t3, 0x8
    ctx->r13 = ADD32(ctx->r11, 0X8);
    // 0x800C606C: sw          $t5, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r13;
    // 0x800C6070: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x800C6074: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800C6078: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x800C607C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C6080: sw          $t7, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r15;
    // 0x800C6084: lw          $t0, -0x4524($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X4524);
    // 0x800C6088: addiu       $t2, $t0, 0x1
    ctx->r10 = ADD32(ctx->r8, 0X1);
    // 0x800C608C: sw          $t2, -0x4524($at)
    MEM_W(-0X4524, ctx->r1) = ctx->r10;
L_800C6090:
    // 0x800C6090: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C6094: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800C6098: jr          $ra
    // 0x800C609C: nop

    return;
    // 0x800C609C: nop

;}
RECOMP_FUNC void func_800C60A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C60A0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800C60A4: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800C60A8: lbu         $t6, 0x3F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X3F);
    // 0x800C60AC: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800C60B0: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800C60B4: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800C60B8: lwc1        $f10, 0x54($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800C60BC: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x800C60C0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800C60C4: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800C60C8: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x800C60CC: addiu       $t8, $t8, -0x4198
    ctx->r24 = ADD32(ctx->r24, -0X4198);
    // 0x800C60D0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800C60D4: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800C60D8: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x800C60DC: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x800C60E0: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800C60E4: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x800C60E8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800C60EC: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x800C60F0: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x800C60F4: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x800C60F8: lwc1        $f18, 0x24($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X24);
    // 0x800C60FC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800C6100: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800C6104: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x800C6108: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800C610C: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x800C6110: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x800C6114: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800C6118: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x800C611C: lwc1        $f6, 0x28($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X28);
    // 0x800C6120: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x800C6124: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x800C6128: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x800C612C: jal         0x800C58E8
    // 0x800C6130: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    func_800C58E8(rdram, ctx);
        goto after_0;
    // 0x800C6130: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x800C6134: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800C6138: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800C613C: jr          $ra
    // 0x800C6140: nop

    return;
    // 0x800C6140: nop

;}
RECOMP_FUNC void func_800C6144(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C6144: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800C6148: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800C614C: lbu         $t6, 0x37($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X37);
    // 0x800C6150: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C6154: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800C6158: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x800C615C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800C6160: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x800C6164: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800C6168: lwc1        $f6, -0x4198($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X4198);
    // 0x800C616C: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800C6170: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800C6174: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800C6178: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800C617C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800C6180: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x800C6184: addiu       $t8, $t8, -0x3FA8
    ctx->r24 = ADD32(ctx->r24, -0X3FA8);
    // 0x800C6188: swc1        $f8, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f8.u32l;
    // 0x800C618C: lbu         $t9, 0x37($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X37);
    // 0x800C6190: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C6194: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800C6198: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x800C619C: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x800C61A0: sll         $t0, $t0, 4
    ctx->r8 = S32(ctx->r8 << 4);
    // 0x800C61A4: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x800C61A8: lwc1        $f16, -0x4194($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X4194);
    // 0x800C61AC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800C61B0: addiu       $t1, $t1, -0x3FA8
    ctx->r9 = ADD32(ctx->r9, -0X3FA8);
    // 0x800C61B4: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800C61B8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C61BC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800C61C0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800C61C4: swc1        $f18, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->f18.u32l;
    // 0x800C61C8: lbu         $t2, 0x37($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X37);
    // 0x800C61CC: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800C61D0: addiu       $t4, $t4, -0x3FA8
    ctx->r12 = ADD32(ctx->r12, -0X3FA8);
    // 0x800C61D4: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x800C61D8: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x800C61DC: sll         $t3, $t3, 4
    ctx->r11 = S32(ctx->r11 << 4);
    // 0x800C61E0: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x800C61E4: lwc1        $f6, -0x4190($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X4190);
    // 0x800C61E8: addiu       $a0, $a0, -0x3F68
    ctx->r4 = ADD32(ctx->r4, -0X3F68);
    // 0x800C61EC: addiu       $a0, $a0, 0x40
    ctx->r4 = ADD32(ctx->r4, 0X40);
    // 0x800C61F0: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800C61F4: jal         0x800D6D20
    // 0x800C61F8: swc1        $f8, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->f8.u32l;
    guMtxIdentF_recomp(rdram, ctx);
        goto after_0;
    // 0x800C61F8: swc1        $f8, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->f8.u32l;
    after_0:
    // 0x800C61FC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800C6200: addiu       $a0, $a0, -0x3F68
    ctx->r4 = ADD32(ctx->r4, -0X3F68);
    // 0x800C6204: jal         0x800D6D20
    // 0x800C6208: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    guMtxIdentF_recomp(rdram, ctx);
        goto after_1;
    // 0x800C6208: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    after_1:
    // 0x800C620C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800C6210: addiu       $t5, $t5, -0x3FA8
    ctx->r13 = ADD32(ctx->r13, -0X3FA8);
    // 0x800C6214: lwc1        $f10, 0x0($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X0);
    // 0x800C6218: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800C621C: nop

    // 0x800C6220: c.eq.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl == ctx->f16.fl;
    // 0x800C6224: nop

    // 0x800C6228: bc1f        L_800C6268
    if (!c1cs) {
        // 0x800C622C: nop
    
            goto L_800C6268;
    }
    // 0x800C622C: nop

    // 0x800C6230: lwc1        $f18, 0x4($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X4);
    // 0x800C6234: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800C6238: nop

    // 0x800C623C: c.eq.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl == ctx->f4.fl;
    // 0x800C6240: nop

    // 0x800C6244: bc1f        L_800C6268
    if (!c1cs) {
        // 0x800C6248: nop
    
            goto L_800C6268;
    }
    // 0x800C6248: nop

    // 0x800C624C: lwc1        $f6, 0x8($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X8);
    // 0x800C6250: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800C6254: nop

    // 0x800C6258: c.eq.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl == ctx->f8.fl;
    // 0x800C625C: nop

    // 0x800C6260: bc1t        L_800C6610
    if (c1cs) {
        // 0x800C6264: nop
    
            goto L_800C6610;
    }
    // 0x800C6264: nop

L_800C6268:
    // 0x800C6268: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800C626C: addiu       $t6, $t6, -0x3FA8
    ctx->r14 = ADD32(ctx->r14, -0X3FA8);
    // 0x800C6270: lwc1        $f10, 0x0($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X0);
    // 0x800C6274: lwc1        $f18, 0x4($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X4);
    // 0x800C6278: lwc1        $f8, 0x8($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X8);
    // 0x800C627C: mul.s       $f16, $f10, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x800C6280: nop

    // 0x800C6284: mul.s       $f4, $f18, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x800C6288: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x800C628C: mul.s       $f10, $f8, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x800C6290: jal         0x800D68E0
    // 0x800C6294: add.s       $f12, $f10, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_2;
    // 0x800C6294: add.s       $f12, $f10, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f6.fl;
    after_2:
    // 0x800C6298: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C629C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800C62A0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800C62A4: addiu       $t7, $t7, -0x3FA8
    ctx->r15 = ADD32(ctx->r15, -0X3FA8);
    // 0x800C62A8: div.s       $f16, $f18, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800C62AC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800C62B0: addiu       $t8, $t8, -0x3FA8
    ctx->r24 = ADD32(ctx->r24, -0X3FA8);
    // 0x800C62B4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800C62B8: addiu       $t9, $t9, -0x3FA8
    ctx->r25 = ADD32(ctx->r25, -0X3FA8);
    // 0x800C62BC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800C62C0: addiu       $t0, $t0, -0x3FA8
    ctx->r8 = ADD32(ctx->r8, -0X3FA8);
    // 0x800C62C4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800C62C8: addiu       $t1, $t1, -0x3FA8
    ctx->r9 = ADD32(ctx->r9, -0X3FA8);
    // 0x800C62CC: addiu       $t2, $t1, 0xC
    ctx->r10 = ADD32(ctx->r9, 0XC);
    // 0x800C62D0: addiu       $t3, $t1, 0x10
    ctx->r11 = ADD32(ctx->r9, 0X10);
    // 0x800C62D4: addiu       $t4, $t1, 0x14
    ctx->r12 = ADD32(ctx->r9, 0X14);
    // 0x800C62D8: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800C62DC: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800C62E0: lui         $a2, 0xBF80
    ctx->r6 = S32(0XBF80 << 16);
    // 0x800C62E4: swc1        $f16, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->f16.u32l;
    // 0x800C62E8: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    // 0x800C62EC: lwc1        $f8, 0x1C($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X1C);
    // 0x800C62F0: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800C62F4: swc1        $f10, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f10.u32l;
    // 0x800C62F8: lwc1        $f6, 0x4($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X4);
    // 0x800C62FC: lwc1        $f18, 0x1C($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X1C);
    // 0x800C6300: mul.s       $f16, $f6, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x800C6304: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800C6308: swc1        $f16, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f16.u32l;
    // 0x800C630C: lwc1        $f4, 0x8($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X8);
    // 0x800C6310: lwc1        $f8, 0x1C($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X1C);
    // 0x800C6314: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800C6318: swc1        $f10, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f10.u32l;
    // 0x800C631C: lw          $a3, 0x0($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X0);
    // 0x800C6320: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x800C6324: lwc1        $f18, 0x8($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X8);
    // 0x800C6328: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x800C632C: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x800C6330: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x800C6334: jal         0x800C46D4
    // 0x800C6338: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    func_800C46D4(rdram, ctx);
        goto after_3;
    // 0x800C6338: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_3:
    // 0x800C633C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800C6340: addiu       $t5, $t5, -0x3FA8
    ctx->r13 = ADD32(ctx->r13, -0X3FA8);
    // 0x800C6344: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800C6348: swc1        $f0, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f0.u32l;
    // 0x800C634C: addiu       $t6, $t6, -0x3FA8
    ctx->r14 = ADD32(ctx->r14, -0X3FA8);
    // 0x800C6350: lwc1        $f16, 0xC($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0XC);
    // 0x800C6354: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800C6358: nop

    // 0x800C635C: c.eq.s      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.fl == ctx->f4.fl;
    // 0x800C6360: nop

    // 0x800C6364: bc1f        L_800C63A4
    if (!c1cs) {
        // 0x800C6368: nop
    
            goto L_800C63A4;
    }
    // 0x800C6368: nop

    // 0x800C636C: lwc1        $f8, 0x10($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X10);
    // 0x800C6370: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800C6374: nop

    // 0x800C6378: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x800C637C: nop

    // 0x800C6380: bc1f        L_800C63A4
    if (!c1cs) {
        // 0x800C6384: nop
    
            goto L_800C63A4;
    }
    // 0x800C6384: nop

    // 0x800C6388: lwc1        $f6, 0x14($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X14);
    // 0x800C638C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800C6390: nop

    // 0x800C6394: c.eq.s      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.fl == ctx->f18.fl;
    // 0x800C6398: nop

    // 0x800C639C: bc1t        L_800C63D0
    if (c1cs) {
        // 0x800C63A0: nop
    
            goto L_800C63D0;
    }
    // 0x800C63A0: nop

L_800C63A4:
    // 0x800C63A4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800C63A8: addiu       $t7, $t7, -0x3FA8
    ctx->r15 = ADD32(ctx->r15, -0X3FA8);
    // 0x800C63AC: lwc1        $f16, 0x14($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X14);
    // 0x800C63B0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800C63B4: addiu       $a0, $a0, -0x3F68
    ctx->r4 = ADD32(ctx->r4, -0X3F68);
    // 0x800C63B8: lw          $a1, 0x18($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X18);
    // 0x800C63BC: lw          $a2, 0xC($t7)
    ctx->r6 = MEM_W(ctx->r15, 0XC);
    // 0x800C63C0: lw          $a3, 0x10($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X10);
    // 0x800C63C4: addiu       $a0, $a0, 0x40
    ctx->r4 = ADD32(ctx->r4, 0X40);
    // 0x800C63C8: jal         0x800D7120
    // 0x800C63CC: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    guAlignF_recomp(rdram, ctx);
        goto after_4;
    // 0x800C63CC: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_4:
L_800C63D0:
    // 0x800C63D0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800C63D4: addiu       $t8, $t8, -0x3FA8
    ctx->r24 = ADD32(ctx->r24, -0X3FA8);
    // 0x800C63D8: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    // 0x800C63DC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800C63E0: nop

    // 0x800C63E4: c.eq.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl == ctx->f8.fl;
    // 0x800C63E8: nop

    // 0x800C63EC: bc1f        L_800C645C
    if (!c1cs) {
        // 0x800C63F0: nop
    
            goto L_800C645C;
    }
    // 0x800C63F0: nop

    // 0x800C63F4: lwc1        $f10, 0x8($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X8);
    // 0x800C63F8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800C63FC: nop

    // 0x800C6400: c.eq.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl == ctx->f6.fl;
    // 0x800C6404: nop

    // 0x800C6408: bc1f        L_800C645C
    if (!c1cs) {
        // 0x800C640C: nop
    
            goto L_800C645C;
    }
    // 0x800C640C: nop

    // 0x800C6410: lwc1        $f18, 0x4($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X4);
    // 0x800C6414: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800C6418: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800C641C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800C6420: addiu       $t9, $t8, 0xC
    ctx->r25 = ADD32(ctx->r24, 0XC);
    // 0x800C6424: addiu       $t0, $t8, 0x10
    ctx->r8 = ADD32(ctx->r24, 0X10);
    // 0x800C6428: addiu       $t2, $t8, 0x14
    ctx->r10 = ADD32(ctx->r24, 0X14);
    // 0x800C642C: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x800C6430: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x800C6434: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x800C6438: lui         $a2, 0xBF80
    ctx->r6 = S32(0XBF80 << 16);
    // 0x800C643C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x800C6440: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x800C6444: jal         0x800C46D4
    // 0x800C6448: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    func_800C46D4(rdram, ctx);
        goto after_5;
    // 0x800C6448: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    after_5:
    // 0x800C644C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800C6450: addiu       $t3, $t3, -0x3FA8
    ctx->r11 = ADD32(ctx->r11, -0X3FA8);
    // 0x800C6454: b           L_800C64B0
    // 0x800C6458: swc1        $f0, 0x1C($t3)
    MEM_W(0X1C, ctx->r11) = ctx->f0.u32l;
        goto L_800C64B0;
    // 0x800C6458: swc1        $f0, 0x1C($t3)
    MEM_W(0X1C, ctx->r11) = ctx->f0.u32l;
L_800C645C:
    // 0x800C645C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800C6460: addiu       $t1, $t1, -0x3FA8
    ctx->r9 = ADD32(ctx->r9, -0X3FA8);
    // 0x800C6464: lwc1        $f4, 0x0($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X0);
    // 0x800C6468: lwc1        $f8, 0x8($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X8);
    // 0x800C646C: lwc1        $f10, 0x4($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X4);
    // 0x800C6470: addiu       $t4, $t1, 0xC
    ctx->r12 = ADD32(ctx->r9, 0XC);
    // 0x800C6474: addiu       $t5, $t1, 0x10
    ctx->r13 = ADD32(ctx->r9, 0X10);
    // 0x800C6478: addiu       $t6, $t1, 0x14
    ctx->r14 = ADD32(ctx->r9, 0X14);
    // 0x800C647C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800C6480: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x800C6484: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x800C6488: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x800C648C: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x800C6490: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x800C6494: mov.s       $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = ctx->f4.fl;
    // 0x800C6498: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x800C649C: jal         0x800C46D4
    // 0x800C64A0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800C46D4(rdram, ctx);
        goto after_6;
    // 0x800C64A0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_6:
    // 0x800C64A4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800C64A8: addiu       $t7, $t7, -0x3FA8
    ctx->r15 = ADD32(ctx->r15, -0X3FA8);
    // 0x800C64AC: swc1        $f0, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->f0.u32l;
L_800C64B0:
    // 0x800C64B0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800C64B4: addiu       $t9, $t9, -0x3FA8
    ctx->r25 = ADD32(ctx->r25, -0X3FA8);
    // 0x800C64B8: lwc1        $f6, 0xC($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0XC);
    // 0x800C64BC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800C64C0: nop

    // 0x800C64C4: c.eq.s      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.fl == ctx->f18.fl;
    // 0x800C64C8: nop

    // 0x800C64CC: bc1f        L_800C650C
    if (!c1cs) {
        // 0x800C64D0: nop
    
            goto L_800C650C;
    }
    // 0x800C64D0: nop

    // 0x800C64D4: lwc1        $f16, 0x10($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X10);
    // 0x800C64D8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800C64DC: nop

    // 0x800C64E0: c.eq.s      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.fl == ctx->f4.fl;
    // 0x800C64E4: nop

    // 0x800C64E8: bc1f        L_800C650C
    if (!c1cs) {
        // 0x800C64EC: nop
    
            goto L_800C650C;
    }
    // 0x800C64EC: nop

    // 0x800C64F0: lwc1        $f10, 0x14($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X14);
    // 0x800C64F4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800C64F8: nop

    // 0x800C64FC: c.eq.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl == ctx->f8.fl;
    // 0x800C6500: nop

    // 0x800C6504: bc1t        L_800C6538
    if (c1cs) {
        // 0x800C6508: nop
    
            goto L_800C6538;
    }
    // 0x800C6508: nop

L_800C650C:
    // 0x800C650C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800C6510: addiu       $t0, $t0, -0x3FA8
    ctx->r8 = ADD32(ctx->r8, -0X3FA8);
    // 0x800C6514: lwc1        $f6, 0x14($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X14);
    // 0x800C6518: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800C651C: addiu       $a0, $a0, -0x3F68
    ctx->r4 = ADD32(ctx->r4, -0X3F68);
    // 0x800C6520: lw          $a1, 0x1C($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X1C);
    // 0x800C6524: lw          $a2, 0xC($t0)
    ctx->r6 = MEM_W(ctx->r8, 0XC);
    // 0x800C6528: lw          $a3, 0x10($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X10);
    // 0x800C652C: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    // 0x800C6530: jal         0x800D7120
    // 0x800C6534: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    guAlignF_recomp(rdram, ctx);
        goto after_7;
    // 0x800C6534: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_7:
L_800C6538:
    // 0x800C6538: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800C653C: addiu       $t8, $t8, -0x3F68
    ctx->r24 = ADD32(ctx->r24, -0X3F68);
    // 0x800C6540: addiu       $t2, $t8, 0x40
    ctx->r10 = ADD32(ctx->r24, 0X40);
    // 0x800C6544: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x800C6548: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    // 0x800C654C: jal         0x800D6F30
    // 0x800C6550: addiu       $a1, $t8, 0x80
    ctx->r5 = ADD32(ctx->r24, 0X80);
    guMtxCatF_recomp(rdram, ctx);
        goto after_8;
    // 0x800C6550: addiu       $a1, $t8, 0x80
    ctx->r5 = ADD32(ctx->r24, 0X80);
    after_8:
    // 0x800C6554: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800C6558: addiu       $t3, $t3, -0x3FA8
    ctx->r11 = ADD32(ctx->r11, -0X3FA8);
    // 0x800C655C: lwc1        $f18, 0x0($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X0);
    // 0x800C6560: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800C6564: nop

    // 0x800C6568: c.eq.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl == ctx->f16.fl;
    // 0x800C656C: nop

    // 0x800C6570: bc1f        L_800C65C8
    if (!c1cs) {
        // 0x800C6574: nop
    
            goto L_800C65C8;
    }
    // 0x800C6574: nop

    // 0x800C6578: lwc1        $f4, 0x4($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X4);
    // 0x800C657C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800C6580: nop

    // 0x800C6584: c.eq.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl == ctx->f10.fl;
    // 0x800C6588: nop

    // 0x800C658C: bc1f        L_800C65C8
    if (!c1cs) {
        // 0x800C6590: nop
    
            goto L_800C65C8;
    }
    // 0x800C6590: nop

    // 0x800C6594: lwc1        $f8, 0x8($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X8);
    // 0x800C6598: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800C659C: nop

    // 0x800C65A0: c.eq.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl == ctx->f6.fl;
    // 0x800C65A4: nop

    // 0x800C65A8: bc1f        L_800C65C8
    if (!c1cs) {
        // 0x800C65AC: nop
    
            goto L_800C65C8;
    }
    // 0x800C65AC: nop

    // 0x800C65B0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800C65B4: addiu       $a0, $a0, -0x3F68
    ctx->r4 = ADD32(ctx->r4, -0X3F68);
    // 0x800C65B8: jal         0x800D6D20
    // 0x800C65BC: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    guMtxIdentF_recomp(rdram, ctx);
        goto after_9;
    // 0x800C65BC: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    after_9:
    // 0x800C65C0: b           L_800C65F4
    // 0x800C65C4: nop

        goto L_800C65F4;
    // 0x800C65C4: nop

L_800C65C8:
    // 0x800C65C8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800C65CC: addiu       $t4, $t4, -0x3FA8
    ctx->r12 = ADD32(ctx->r12, -0X3FA8);
    // 0x800C65D0: lwc1        $f18, 0x8($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X8);
    // 0x800C65D4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800C65D8: addiu       $a0, $a0, -0x3F68
    ctx->r4 = ADD32(ctx->r4, -0X3F68);
    // 0x800C65DC: lw          $a2, 0x0($t4)
    ctx->r6 = MEM_W(ctx->r12, 0X0);
    // 0x800C65E0: lw          $a3, 0x4($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X4);
    // 0x800C65E4: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    // 0x800C65E8: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x800C65EC: jal         0x800D7120
    // 0x800C65F0: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    guAlignF_recomp(rdram, ctx);
        goto after_10;
    // 0x800C65F0: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_10:
L_800C65F4:
    // 0x800C65F4: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800C65F8: addiu       $t5, $t5, -0x3F68
    ctx->r13 = ADD32(ctx->r13, -0X3F68);
    // 0x800C65FC: addiu       $t1, $t5, 0x40
    ctx->r9 = ADD32(ctx->r13, 0X40);
    // 0x800C6600: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x800C6604: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    // 0x800C6608: jal         0x800D6F30
    // 0x800C660C: addiu       $a1, $t5, 0x80
    ctx->r5 = ADD32(ctx->r13, 0X80);
    guMtxCatF_recomp(rdram, ctx);
        goto after_11;
    // 0x800C660C: addiu       $a1, $t5, 0x80
    ctx->r5 = ADD32(ctx->r13, 0X80);
    after_11:
L_800C6610:
    // 0x800C6610: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800C6614: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800C6618: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800C661C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800C6620: addiu       $t6, $t6, -0x3F68
    ctx->r14 = ADD32(ctx->r14, -0X3F68);
    // 0x800C6624: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800C6628: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800C662C: addiu       $t7, $t7, -0x3F68
    ctx->r15 = ADD32(ctx->r15, -0X3F68);
    // 0x800C6630: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800C6634: swc1        $f16, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f16.u32l;
    // 0x800C6638: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800C663C: addiu       $t9, $t9, -0x3F68
    ctx->r25 = ADD32(ctx->r25, -0X3F68);
    // 0x800C6640: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800C6644: swc1        $f4, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f4.u32l;
    // 0x800C6648: addiu       $t0, $t0, -0x3F68
    ctx->r8 = ADD32(ctx->r8, -0X3F68);
    // 0x800C664C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800C6650: swc1        $f10, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f10.u32l;
    // 0x800C6654: addiu       $t8, $t8, -0x3F68
    ctx->r24 = ADD32(ctx->r24, -0X3F68);
    // 0x800C6658: swc1        $f8, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->f8.u32l;
    // 0x800C665C: swc1        $f6, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->f6.u32l;
    // 0x800C6660: lwc1        $f18, 0x48($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800C6664: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800C6668: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800C666C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800C6670: addiu       $t2, $t2, -0x3F68
    ctx->r10 = ADD32(ctx->r10, -0X3F68);
    // 0x800C6674: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800C6678: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800C667C: addiu       $t3, $t3, -0x3F68
    ctx->r11 = ADD32(ctx->r11, -0X3F68);
    // 0x800C6680: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800C6684: swc1        $f18, 0x14($t2)
    MEM_W(0X14, ctx->r10) = ctx->f18.u32l;
    // 0x800C6688: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800C668C: addiu       $t4, $t4, -0x3F68
    ctx->r12 = ADD32(ctx->r12, -0X3F68);
    // 0x800C6690: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800C6694: swc1        $f16, 0x18($t3)
    MEM_W(0X18, ctx->r11) = ctx->f16.u32l;
    // 0x800C6698: addiu       $t5, $t5, -0x3F68
    ctx->r13 = ADD32(ctx->r13, -0X3F68);
    // 0x800C669C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800C66A0: swc1        $f4, 0x1C($t4)
    MEM_W(0X1C, ctx->r12) = ctx->f4.u32l;
    // 0x800C66A4: addiu       $t1, $t1, -0x3F68
    ctx->r9 = ADD32(ctx->r9, -0X3F68);
    // 0x800C66A8: swc1        $f10, 0x20($t5)
    MEM_W(0X20, ctx->r13) = ctx->f10.u32l;
    // 0x800C66AC: swc1        $f8, 0x24($t1)
    MEM_W(0X24, ctx->r9) = ctx->f8.u32l;
    // 0x800C66B0: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800C66B4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800C66B8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800C66BC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800C66C0: addiu       $t6, $t6, -0x3F68
    ctx->r14 = ADD32(ctx->r14, -0X3F68);
    // 0x800C66C4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800C66C8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800C66CC: addiu       $t7, $t7, -0x3F68
    ctx->r15 = ADD32(ctx->r15, -0X3F68);
    // 0x800C66D0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800C66D4: swc1        $f6, 0x28($t6)
    MEM_W(0X28, ctx->r14) = ctx->f6.u32l;
    // 0x800C66D8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800C66DC: addiu       $t9, $t9, -0x3F68
    ctx->r25 = ADD32(ctx->r25, -0X3F68);
    // 0x800C66E0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800C66E4: swc1        $f18, 0x2C($t7)
    MEM_W(0X2C, ctx->r15) = ctx->f18.u32l;
    // 0x800C66E8: addiu       $t0, $t0, -0x3F68
    ctx->r8 = ADD32(ctx->r8, -0X3F68);
    // 0x800C66EC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800C66F0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C66F4: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800C66F8: swc1        $f16, 0x30($t9)
    MEM_W(0X30, ctx->r25) = ctx->f16.u32l;
    // 0x800C66FC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800C6700: addiu       $t8, $t8, -0x3F68
    ctx->r24 = ADD32(ctx->r24, -0X3F68);
    // 0x800C6704: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800C6708: addiu       $t3, $t3, -0x3F68
    ctx->r11 = ADD32(ctx->r11, -0X3F68);
    // 0x800C670C: swc1        $f4, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->f4.u32l;
    // 0x800C6710: addiu       $t2, $t2, -0x3F68
    ctx->r10 = ADD32(ctx->r10, -0X3F68);
    // 0x800C6714: addiu       $t4, $t3, 0x40
    ctx->r12 = ADD32(ctx->r11, 0X40);
    // 0x800C6718: swc1        $f10, 0x38($t8)
    MEM_W(0X38, ctx->r24) = ctx->f10.u32l;
    // 0x800C671C: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    // 0x800C6720: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    // 0x800C6724: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    // 0x800C6728: jal         0x800D6F30
    // 0x800C672C: swc1        $f8, 0x3C($t2)
    MEM_W(0X3C, ctx->r10) = ctx->f8.u32l;
    guMtxCatF_recomp(rdram, ctx);
        goto after_12;
    // 0x800C672C: swc1        $f8, 0x3C($t2)
    MEM_W(0X3C, ctx->r10) = ctx->f8.u32l;
    after_12:
    // 0x800C6730: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C6734: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800C6738: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800C673C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800C6740: addiu       $t5, $t5, -0x3F68
    ctx->r13 = ADD32(ctx->r13, -0X3F68);
    // 0x800C6744: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800C6748: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800C674C: addiu       $t1, $t1, -0x3F68
    ctx->r9 = ADD32(ctx->r9, -0X3F68);
    // 0x800C6750: swc1        $f6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f6.u32l;
    // 0x800C6754: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800C6758: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800C675C: swc1        $f18, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->f18.u32l;
    // 0x800C6760: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800C6764: addiu       $t6, $t6, -0x3F68
    ctx->r14 = ADD32(ctx->r14, -0X3F68);
    // 0x800C6768: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800C676C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800C6770: addiu       $t7, $t7, -0x3F68
    ctx->r15 = ADD32(ctx->r15, -0X3F68);
    // 0x800C6774: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800C6778: swc1        $f16, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f16.u32l;
    // 0x800C677C: addiu       $t9, $t9, -0x3F68
    ctx->r25 = ADD32(ctx->r25, -0X3F68);
    // 0x800C6780: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800C6784: swc1        $f4, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f4.u32l;
    // 0x800C6788: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800C678C: addiu       $t0, $t0, -0x3F68
    ctx->r8 = ADD32(ctx->r8, -0X3F68);
    // 0x800C6790: swc1        $f10, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->f10.u32l;
    // 0x800C6794: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800C6798: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800C679C: swc1        $f8, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->f8.u32l;
    // 0x800C67A0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800C67A4: addiu       $t8, $t8, -0x3F68
    ctx->r24 = ADD32(ctx->r24, -0X3F68);
    // 0x800C67A8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800C67AC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800C67B0: addiu       $t2, $t2, -0x3F68
    ctx->r10 = ADD32(ctx->r10, -0X3F68);
    // 0x800C67B4: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800C67B8: swc1        $f6, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->f6.u32l;
    // 0x800C67BC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800C67C0: addiu       $t3, $t3, -0x3F68
    ctx->r11 = ADD32(ctx->r11, -0X3F68);
    // 0x800C67C4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800C67C8: swc1        $f18, 0x1C($t2)
    MEM_W(0X1C, ctx->r10) = ctx->f18.u32l;
    // 0x800C67CC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800C67D0: addiu       $t4, $t4, -0x3F68
    ctx->r12 = ADD32(ctx->r12, -0X3F68);
    // 0x800C67D4: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800C67D8: swc1        $f16, 0x20($t3)
    MEM_W(0X20, ctx->r11) = ctx->f16.u32l;
    // 0x800C67DC: addiu       $t5, $t5, -0x3F68
    ctx->r13 = ADD32(ctx->r13, -0X3F68);
    // 0x800C67E0: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800C67E4: swc1        $f4, 0x24($t4)
    MEM_W(0X24, ctx->r12) = ctx->f4.u32l;
    // 0x800C67E8: addiu       $t1, $t1, -0x3F68
    ctx->r9 = ADD32(ctx->r9, -0X3F68);
    // 0x800C67EC: swc1        $f10, 0x28($t5)
    MEM_W(0X28, ctx->r13) = ctx->f10.u32l;
    // 0x800C67F0: swc1        $f8, 0x2C($t1)
    MEM_W(0X2C, ctx->r9) = ctx->f8.u32l;
    // 0x800C67F4: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800C67F8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800C67FC: addiu       $t6, $t6, -0x3F68
    ctx->r14 = ADD32(ctx->r14, -0X3F68);
    // 0x800C6800: swc1        $f6, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->f6.u32l;
    // 0x800C6804: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800C6808: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800C680C: addiu       $t7, $t7, -0x3F68
    ctx->r15 = ADD32(ctx->r15, -0X3F68);
    // 0x800C6810: swc1        $f18, 0x34($t7)
    MEM_W(0X34, ctx->r15) = ctx->f18.u32l;
    // 0x800C6814: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800C6818: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800C681C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800C6820: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800C6824: addiu       $t9, $t9, -0x3F68
    ctx->r25 = ADD32(ctx->r25, -0X3F68);
    // 0x800C6828: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800C682C: addiu       $t8, $t8, -0x3F68
    ctx->r24 = ADD32(ctx->r24, -0X3F68);
    // 0x800C6830: addiu       $t0, $t0, -0x3F68
    ctx->r8 = ADD32(ctx->r8, -0X3F68);
    // 0x800C6834: swc1        $f16, 0x38($t9)
    MEM_W(0X38, ctx->r25) = ctx->f16.u32l;
    // 0x800C6838: addiu       $a0, $t8, 0x40
    ctx->r4 = ADD32(ctx->r24, 0X40);
    // 0x800C683C: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x800C6840: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x800C6844: jal         0x800D6F30
    // 0x800C6848: swc1        $f4, 0x3C($t0)
    MEM_W(0X3C, ctx->r8) = ctx->f4.u32l;
    guMtxCatF_recomp(rdram, ctx);
        goto after_13;
    // 0x800C6848: swc1        $f4, 0x3C($t0)
    MEM_W(0X3C, ctx->r8) = ctx->f4.u32l;
    after_13:
    // 0x800C684C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800C6850: jal         0x800C5E40
    // 0x800C6854: lbu         $a1, 0x37($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X37);
    func_800C5E40(rdram, ctx);
        goto after_14;
    // 0x800C6854: lbu         $a1, 0x37($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X37);
    after_14:
    // 0x800C6858: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800C685C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800C6860: jr          $ra
    // 0x800C6864: nop

    return;
    // 0x800C6864: nop

;}
RECOMP_FUNC void func_800C6868(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C6868: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800C686C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C6870: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800C6874: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800C6878: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x800C687C: jal         0x800C46AC
    // 0x800C6880: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    func_800C46AC(rdram, ctx);
        goto after_0;
    // 0x800C6880: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    after_0:
    // 0x800C6884: bltz        $v0, L_800C6B6C
    if (SIGNED(ctx->r2) < 0) {
        // 0x800C6888: nop
    
            goto L_800C6B6C;
    }
    // 0x800C6888: nop

    // 0x800C688C: jal         0x800C5634
    // 0x800C6890: nop

    func_800C5634(rdram, ctx);
        goto after_1;
    // 0x800C6890: nop

    after_1:
    // 0x800C6894: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800C6898: jal         0x800D6D20
    // 0x800C689C: addiu       $a0, $a0, -0x3F68
    ctx->r4 = ADD32(ctx->r4, -0X3F68);
    guMtxIdentF_recomp(rdram, ctx);
        goto after_2;
    // 0x800C689C: addiu       $a0, $a0, -0x3F68
    ctx->r4 = ADD32(ctx->r4, -0X3F68);
    after_2:
    // 0x800C68A0: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800C68A4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800C68A8: addiu       $t6, $t6, -0x3F68
    ctx->r14 = ADD32(ctx->r14, -0X3F68);
    // 0x800C68AC: swc1        $f4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f4.u32l;
    // 0x800C68B0: lwc1        $f6, 0x54($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800C68B4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800C68B8: addiu       $t7, $t7, -0x3F68
    ctx->r15 = ADD32(ctx->r15, -0X3F68);
    // 0x800C68BC: swc1        $f6, 0x14($t7)
    MEM_W(0X14, ctx->r15) = ctx->f6.u32l;
    // 0x800C68C0: lwc1        $f8, 0x58($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800C68C4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800C68C8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800C68CC: addiu       $t8, $t8, -0x3F68
    ctx->r24 = ADD32(ctx->r24, -0X3F68);
    // 0x800C68D0: addiu       $a0, $a0, -0x3F68
    ctx->r4 = ADD32(ctx->r4, -0X3F68);
    // 0x800C68D4: addiu       $a0, $a0, 0x40
    ctx->r4 = ADD32(ctx->r4, 0X40);
    // 0x800C68D8: jal         0x800D6D20
    // 0x800C68DC: swc1        $f8, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->f8.u32l;
    guMtxIdentF_recomp(rdram, ctx);
        goto after_3;
    // 0x800C68DC: swc1        $f8, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->f8.u32l;
    after_3:
    // 0x800C68E0: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800C68E4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800C68E8: addiu       $t9, $t9, -0x3F68
    ctx->r25 = ADD32(ctx->r25, -0X3F68);
    // 0x800C68EC: swc1        $f10, 0x70($t9)
    MEM_W(0X70, ctx->r25) = ctx->f10.u32l;
    // 0x800C68F0: lwc1        $f16, 0x48($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800C68F4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800C68F8: addiu       $t0, $t0, -0x3F68
    ctx->r8 = ADD32(ctx->r8, -0X3F68);
    // 0x800C68FC: swc1        $f16, 0x74($t0)
    MEM_W(0X74, ctx->r8) = ctx->f16.u32l;
    // 0x800C6900: lwc1        $f18, 0x4C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800C6904: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800C6908: addiu       $t1, $t1, -0x3F68
    ctx->r9 = ADD32(ctx->r9, -0X3F68);
    // 0x800C690C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800C6910: addiu       $t2, $t2, -0x3F68
    ctx->r10 = ADD32(ctx->r10, -0X3F68);
    // 0x800C6914: swc1        $f18, 0x78($t1)
    MEM_W(0X78, ctx->r9) = ctx->f18.u32l;
    // 0x800C6918: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x800C691C: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x800C6920: jal         0x800D6F30
    // 0x800C6924: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    guMtxCatF_recomp(rdram, ctx);
        goto after_4;
    // 0x800C6924: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    after_4:
    // 0x800C6928: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800C692C: addiu       $t3, $t3, -0x3F68
    ctx->r11 = ADD32(ctx->r11, -0X3F68);
    // 0x800C6930: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    // 0x800C6934: addiu       $a1, $t3, 0x40
    ctx->r5 = ADD32(ctx->r11, 0X40);
    // 0x800C6938: jal         0x800D6F30
    // 0x800C693C: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    guMtxCatF_recomp(rdram, ctx);
        goto after_5;
    // 0x800C693C: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    after_5:
    // 0x800C6940: lui         $t4, 0x8011
    ctx->r12 = S32(0X8011 << 16);
    // 0x800C6944: lw          $t4, -0x4514($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4514);
    // 0x800C6948: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C694C: lui         $t6, 0xDA38
    ctx->r14 = S32(0XDA38 << 16);
    // 0x800C6950: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
    // 0x800C6954: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x800C6958: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x800C695C: sw          $t5, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r13;
    // 0x800C6960: ori         $t6, $t6, 0x7
    ctx->r14 = ctx->r14 | 0X7;
    // 0x800C6964: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800C6968: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x800C696C: lw          $a0, 0x3AF0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3AF0);
    // 0x800C6970: jal         0x800D70A0
    // 0x800C6974: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_6;
    // 0x800C6974: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    after_6:
    // 0x800C6978: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x800C697C: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x800C6980: sw          $v0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r2;
    // 0x800C6984: lhu         $t9, -0x4530($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X4530);
    // 0x800C6988: andi        $t0, $t9, 0x8000
    ctx->r8 = ctx->r25 & 0X8000;
    // 0x800C698C: bne         $t0, $zero, L_800C6A34
    if (ctx->r8 != 0) {
        // 0x800C6990: nop
    
            goto L_800C6A34;
    }
    // 0x800C6990: nop

    // 0x800C6994: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x800C6998: lw          $t1, -0x4514($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4514);
    // 0x800C699C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C69A0: lui         $t3, 0xDA38
    ctx->r11 = S32(0XDA38 << 16);
    // 0x800C69A4: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x800C69A8: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x800C69AC: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x800C69B0: sw          $t2, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r10;
    // 0x800C69B4: ori         $t3, $t3, 0x3
    ctx->r11 = ctx->r11 | 0X3;
    // 0x800C69B8: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x800C69BC: lbu         $t6, 0x3F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X3F);
    // 0x800C69C0: lui         $t5, 0x8011
    ctx->r13 = S32(0X8011 << 16);
    // 0x800C69C4: lw          $t5, 0x3AF0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X3AF0);
    // 0x800C69C8: sll         $t7, $t6, 6
    ctx->r15 = S32(ctx->r14 << 6);
    // 0x800C69CC: addu        $a0, $t5, $t7
    ctx->r4 = ADD32(ctx->r13, ctx->r15);
    // 0x800C69D0: jal         0x800D70A0
    // 0x800C69D4: addiu       $a0, $a0, 0x70
    ctx->r4 = ADD32(ctx->r4, 0X70);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_7;
    // 0x800C69D4: addiu       $a0, $a0, 0x70
    ctx->r4 = ADD32(ctx->r4, 0X70);
    after_7:
    // 0x800C69D8: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x800C69DC: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x800C69E0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C69E4: sw          $v0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r2;
    // 0x800C69E8: lw          $t9, -0x4514($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4514);
    // 0x800C69EC: lui         $t1, 0xDA38
    ctx->r9 = S32(0XDA38 << 16);
    // 0x800C69F0: ori         $t1, $t1, 0x1
    ctx->r9 = ctx->r9 | 0X1;
    // 0x800C69F4: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x800C69F8: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x800C69FC: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x800C6A00: sw          $t0, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r8;
    // 0x800C6A04: lui         $t4, 0x8011
    ctx->r12 = S32(0X8011 << 16);
    // 0x800C6A08: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x800C6A0C: lw          $t4, -0x4524($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4524);
    // 0x800C6A10: lui         $t3, 0x8011
    ctx->r11 = S32(0X8011 << 16);
    // 0x800C6A14: lw          $t3, 0x3AF0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X3AF0);
    // 0x800C6A18: sll         $t6, $t4, 6
    ctx->r14 = S32(ctx->r12 << 6);
    // 0x800C6A1C: addu        $a0, $t3, $t6
    ctx->r4 = ADD32(ctx->r11, ctx->r14);
    // 0x800C6A20: jal         0x800D70A0
    // 0x800C6A24: addiu       $a0, $a0, 0x170
    ctx->r4 = ADD32(ctx->r4, 0X170);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_8;
    // 0x800C6A24: addiu       $a0, $a0, 0x170
    ctx->r4 = ADD32(ctx->r4, 0X170);
    after_8:
    // 0x800C6A28: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x800C6A2C: b           L_800C6AD0
    // 0x800C6A30: sw          $v0, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r2;
        goto L_800C6AD0;
    // 0x800C6A30: sw          $v0, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r2;
L_800C6A34:
    // 0x800C6A34: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x800C6A38: lw          $t7, -0x4514($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4514);
    // 0x800C6A3C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C6A40: lui         $t9, 0xDA38
    ctx->r25 = S32(0XDA38 << 16);
    // 0x800C6A44: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x800C6A48: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800C6A4C: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x800C6A50: sw          $t8, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r24;
    // 0x800C6A54: ori         $t9, $t9, 0x5
    ctx->r25 = ctx->r25 | 0X5;
    // 0x800C6A58: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800C6A5C: lbu         $t2, 0x3F($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X3F);
    // 0x800C6A60: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x800C6A64: lw          $t1, 0x3AF0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X3AF0);
    // 0x800C6A68: sll         $t4, $t2, 6
    ctx->r12 = S32(ctx->r10 << 6);
    // 0x800C6A6C: addu        $a0, $t1, $t4
    ctx->r4 = ADD32(ctx->r9, ctx->r12);
    // 0x800C6A70: jal         0x800D70A0
    // 0x800C6A74: addiu       $a0, $a0, 0x70
    ctx->r4 = ADD32(ctx->r4, 0X70);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_9;
    // 0x800C6A74: addiu       $a0, $a0, 0x70
    ctx->r4 = ADD32(ctx->r4, 0X70);
    after_9:
    // 0x800C6A78: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x800C6A7C: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x800C6A80: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C6A84: sw          $v0, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r2;
    // 0x800C6A88: lw          $t6, -0x4514($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4514);
    // 0x800C6A8C: lui         $t7, 0xDA38
    ctx->r15 = S32(0XDA38 << 16);
    // 0x800C6A90: ori         $t7, $t7, 0x3
    ctx->r15 = ctx->r15 | 0X3;
    // 0x800C6A94: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x800C6A98: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800C6A9C: addiu       $t5, $t6, 0x8
    ctx->r13 = ADD32(ctx->r14, 0X8);
    // 0x800C6AA0: sw          $t5, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r13;
    // 0x800C6AA4: lui         $t0, 0x8011
    ctx->r8 = S32(0X8011 << 16);
    // 0x800C6AA8: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800C6AAC: lw          $t0, -0x4524($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X4524);
    // 0x800C6AB0: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x800C6AB4: lw          $t9, 0x3AF0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X3AF0);
    // 0x800C6AB8: sll         $t2, $t0, 6
    ctx->r10 = S32(ctx->r8 << 6);
    // 0x800C6ABC: addu        $a0, $t9, $t2
    ctx->r4 = ADD32(ctx->r25, ctx->r10);
    // 0x800C6AC0: jal         0x800D70A0
    // 0x800C6AC4: addiu       $a0, $a0, 0x170
    ctx->r4 = ADD32(ctx->r4, 0X170);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_10;
    // 0x800C6AC4: addiu       $a0, $a0, 0x170
    ctx->r4 = ADD32(ctx->r4, 0X170);
    after_10:
    // 0x800C6AC8: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800C6ACC: sw          $v0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r2;
L_800C6AD0:
    // 0x800C6AD0: lui         $t3, 0x8011
    ctx->r11 = S32(0X8011 << 16);
    // 0x800C6AD4: lw          $t3, -0x4524($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X4524);
    // 0x800C6AD8: lui         $t4, 0x8011
    ctx->r12 = S32(0X8011 << 16);
    // 0x800C6ADC: lw          $t4, 0x3AF0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X3AF0);
    // 0x800C6AE0: sll         $t6, $t3, 6
    ctx->r14 = S32(ctx->r11 << 6);
    // 0x800C6AE4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800C6AE8: addu        $a1, $t4, $t6
    ctx->r5 = ADD32(ctx->r12, ctx->r14);
    // 0x800C6AEC: addiu       $a1, $a1, 0x170
    ctx->r5 = ADD32(ctx->r5, 0X170);
    // 0x800C6AF0: jal         0x800D6C20
    // 0x800C6AF4: addiu       $a0, $a0, -0x3F68
    ctx->r4 = ADD32(ctx->r4, -0X3F68);
    guMtxF2L_recomp(rdram, ctx);
        goto after_11;
    // 0x800C6AF4: addiu       $a0, $a0, -0x3F68
    ctx->r4 = ADD32(ctx->r4, -0X3F68);
    after_11:
    // 0x800C6AF8: lui         $t5, 0x8011
    ctx->r13 = S32(0X8011 << 16);
    // 0x800C6AFC: lw          $t5, -0x4514($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4514);
    // 0x800C6B00: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C6B04: lui         $t8, 0xDB0E
    ctx->r24 = S32(0XDB0E << 16);
    // 0x800C6B08: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x800C6B0C: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800C6B10: addiu       $t7, $t5, 0x8
    ctx->r15 = ADD32(ctx->r13, 0X8);
    // 0x800C6B14: sw          $t7, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r15;
    // 0x800C6B18: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x800C6B1C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800C6B20: lhu         $t9, -0x41B8($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X41B8);
    // 0x800C6B24: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x800C6B28: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x800C6B2C: lui         $t4, 0xDE00
    ctx->r12 = S32(0XDE00 << 16);
    // 0x800C6B30: sw          $t9, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r25;
    // 0x800C6B34: lw          $t1, -0x4514($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4514);
    // 0x800C6B38: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x800C6B3C: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x800C6B40: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800C6B44: addiu       $t3, $t1, 0x8
    ctx->r11 = ADD32(ctx->r9, 0X8);
    // 0x800C6B48: sw          $t3, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r11;
    // 0x800C6B4C: sw          $t4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r12;
    // 0x800C6B50: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800C6B54: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x800C6B58: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C6B5C: sw          $t5, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r13;
    // 0x800C6B60: lw          $t8, -0x4524($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4524);
    // 0x800C6B64: addiu       $t0, $t8, 0x1
    ctx->r8 = ADD32(ctx->r24, 0X1);
    // 0x800C6B68: sw          $t0, -0x4524($at)
    MEM_W(-0X4524, ctx->r1) = ctx->r8;
L_800C6B6C:
    // 0x800C6B6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C6B70: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800C6B74: jr          $ra
    // 0x800C6B78: nop

    return;
    // 0x800C6B78: nop

;}
RECOMP_FUNC void func_800C6B7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C6B7C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C6B80: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800C6B84: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800C6B88: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C6B8C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800C6B90: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800C6B94: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800C6B98: lw          $t7, 0x38($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X38);
    // 0x800C6B9C: sw          $t7, 0x3C($t6)
    MEM_W(0X3C, ctx->r14) = ctx->r15;
    // 0x800C6BA0: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x800C6BA4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800C6BA8: jal         0x800D3D78
    // 0x800C6BAC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    spMove_recomp(rdram, ctx);
        goto after_0;
    // 0x800C6BAC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_0:
    // 0x800C6BB0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800C6BB4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x800C6BB8: jal         0x800D7310
    // 0x800C6BBC: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    spScale_recomp(rdram, ctx);
        goto after_1;
    // 0x800C6BBC: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    after_1:
    // 0x800C6BC0: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x800C6BC4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800C6BC8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800C6BCC: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x800C6BD0: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x800C6BD4: jal         0x800D7380
    // 0x800C6BD8: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    spColor_recomp(rdram, ctx);
        goto after_2;
    // 0x800C6BD8: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_2:
    // 0x800C6BDC: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x800C6BE0: lhu         $t9, -0x4530($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X4530);
    // 0x800C6BE4: andi        $t0, $t9, 0x1000
    ctx->r8 = ctx->r25 & 0X1000;
    // 0x800C6BE8: beq         $t0, $zero, L_800C6C0C
    if (ctx->r8 == 0) {
        // 0x800C6BEC: nop
    
            goto L_800C6C0C;
    }
    // 0x800C6BEC: nop

    // 0x800C6BF0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800C6BF4: addiu       $a1, $zero, 0x27F
    ctx->r5 = ADD32(0, 0X27F);
    // 0x800C6BF8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800C6BFC: jal         0x800D3D84
    // 0x800C6C00: addiu       $a3, $zero, 0x1DF
    ctx->r7 = ADD32(0, 0X1DF);
    spScissor_recomp(rdram, ctx);
        goto after_3;
    // 0x800C6C00: addiu       $a3, $zero, 0x1DF
    ctx->r7 = ADD32(0, 0X1DF);
    after_3:
    // 0x800C6C04: b           L_800C6C20
    // 0x800C6C08: nop

        goto L_800C6C20;
    // 0x800C6C08: nop

L_800C6C0C:
    // 0x800C6C0C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800C6C10: addiu       $a1, $zero, 0x13F
    ctx->r5 = ADD32(0, 0X13F);
    // 0x800C6C14: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800C6C18: jal         0x800D3D84
    // 0x800C6C1C: addiu       $a3, $zero, 0xEF
    ctx->r7 = ADD32(0, 0XEF);
    spScissor_recomp(rdram, ctx);
        goto after_4;
    // 0x800C6C1C: addiu       $a3, $zero, 0xEF
    ctx->r7 = ADD32(0, 0XEF);
    after_4:
L_800C6C20:
    // 0x800C6C20: jal         0x800D55F4
    // 0x800C6C24: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    spX2Draw_recomp(rdram, ctx);
        goto after_5;
    // 0x800C6C24: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_5:
    // 0x800C6C28: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x800C6C2C: lw          $t1, -0x4514($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4514);
    // 0x800C6C30: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C6C34: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800C6C38: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x800C6C3C: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x800C6C40: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x800C6C44: sw          $t2, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r10;
    // 0x800C6C48: lui         $t3, 0xDE00
    ctx->r11 = S32(0XDE00 << 16);
    // 0x800C6C4C: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x800C6C50: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800C6C54: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800C6C58: sw          $t5, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r13;
    // 0x800C6C5C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C6C60: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800C6C64: jr          $ra
    // 0x800C6C68: nop

    return;
    // 0x800C6C68: nop

;}
RECOMP_FUNC void func_800C6C6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C6C6C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C6C70: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800C6C74: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800C6C78: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C6C7C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800C6C80: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800C6C84: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800C6C88: lw          $t7, 0x38($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X38);
    // 0x800C6C8C: sw          $t7, 0x3C($t6)
    MEM_W(0X3C, ctx->r14) = ctx->r15;
    // 0x800C6C90: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x800C6C94: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800C6C98: jal         0x800D3D78
    // 0x800C6C9C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    spMove_recomp(rdram, ctx);
        goto after_0;
    // 0x800C6C9C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_0:
    // 0x800C6CA0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800C6CA4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x800C6CA8: jal         0x800D7310
    // 0x800C6CAC: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    spScale_recomp(rdram, ctx);
        goto after_1;
    // 0x800C6CAC: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    after_1:
    // 0x800C6CB0: lbu         $t8, 0x3F($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X3F);
    // 0x800C6CB4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800C6CB8: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x800C6CBC: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x800C6CC0: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x800C6CC4: jal         0x800D7380
    // 0x800C6CC8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    spColor_recomp(rdram, ctx);
        goto after_2;
    // 0x800C6CC8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_2:
    // 0x800C6CCC: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x800C6CD0: lhu         $t9, -0x4530($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X4530);
    // 0x800C6CD4: andi        $t0, $t9, 0x1000
    ctx->r8 = ctx->r25 & 0X1000;
    // 0x800C6CD8: beq         $t0, $zero, L_800C6CFC
    if (ctx->r8 == 0) {
        // 0x800C6CDC: nop
    
            goto L_800C6CFC;
    }
    // 0x800C6CDC: nop

    // 0x800C6CE0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800C6CE4: addiu       $a1, $zero, 0x27F
    ctx->r5 = ADD32(0, 0X27F);
    // 0x800C6CE8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800C6CEC: jal         0x800D3D84
    // 0x800C6CF0: addiu       $a3, $zero, 0x1DF
    ctx->r7 = ADD32(0, 0X1DF);
    spScissor_recomp(rdram, ctx);
        goto after_3;
    // 0x800C6CF0: addiu       $a3, $zero, 0x1DF
    ctx->r7 = ADD32(0, 0X1DF);
    after_3:
    // 0x800C6CF4: b           L_800C6D10
    // 0x800C6CF8: nop

        goto L_800C6D10;
    // 0x800C6CF8: nop

L_800C6CFC:
    // 0x800C6CFC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800C6D00: addiu       $a1, $zero, 0x13F
    ctx->r5 = ADD32(0, 0X13F);
    // 0x800C6D04: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800C6D08: jal         0x800D3D84
    // 0x800C6D0C: addiu       $a3, $zero, 0xEF
    ctx->r7 = ADD32(0, 0XEF);
    spScissor_recomp(rdram, ctx);
        goto after_4;
    // 0x800C6D0C: addiu       $a3, $zero, 0xEF
    ctx->r7 = ADD32(0, 0XEF);
    after_4:
L_800C6D10:
    // 0x800C6D10: jal         0x800D55F4
    // 0x800C6D14: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    spX2Draw_recomp(rdram, ctx);
        goto after_5;
    // 0x800C6D14: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_5:
    // 0x800C6D18: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x800C6D1C: lw          $t1, -0x4514($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4514);
    // 0x800C6D20: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C6D24: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800C6D28: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x800C6D2C: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x800C6D30: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x800C6D34: sw          $t2, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r10;
    // 0x800C6D38: lui         $t3, 0xDE00
    ctx->r11 = S32(0XDE00 << 16);
    // 0x800C6D3C: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x800C6D40: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800C6D44: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x800C6D48: sw          $t5, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r13;
    // 0x800C6D4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C6D50: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800C6D54: jr          $ra
    // 0x800C6D58: nop

    return;
    // 0x800C6D58: nop

;}
RECOMP_FUNC void func_800C6D5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C6D5C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C6D60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C6D64: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800C6D68: jal         0x800D6320
    // 0x800C6D6C: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    spX2Finish_recomp(rdram, ctx);
        goto after_0;
    // 0x800C6D6C: addiu       $a0, $a0, -0x4514
    ctx->r4 = ADD32(ctx->r4, -0X4514);
    after_0:
    // 0x800C6D70: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x800C6D74: lw          $t6, -0x4514($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4514);
    // 0x800C6D78: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800C6D7C: lui         $t9, 0xDE00
    ctx->r25 = S32(0XDE00 << 16);
    // 0x800C6D80: addiu       $t7, $t6, -0x8
    ctx->r15 = ADD32(ctx->r14, -0X8);
    // 0x800C6D84: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x800C6D88: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800C6D8C: sw          $t7, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r15;
    // 0x800C6D90: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x800C6D94: sw          $t8, -0x4514($at)
    MEM_W(-0X4514, ctx->r1) = ctx->r24;
    // 0x800C6D98: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800C6D9C: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x800C6DA0: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x800C6DA4: addiu       $t1, $t1, -0x52F0
    ctx->r9 = ADD32(ctx->r9, -0X52F0);
    // 0x800C6DA8: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x800C6DAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C6DB0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C6DB4: jr          $ra
    // 0x800C6DB8: nop

    return;
    // 0x800C6DB8: nop

;}
