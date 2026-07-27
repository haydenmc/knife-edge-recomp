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

RECOMP_FUNC void func_800CD438(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CD438: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800CD43C: sw          $a0, -0x2D64($at)
    MEM_W(-0X2D64, ctx->r1) = ctx->r4;
    // 0x800CD440: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800CD444: sw          $zero, -0x2D5C($at)
    MEM_W(-0X2D5C, ctx->r1) = 0;
    // 0x800CD448: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800CD44C: sw          $zero, -0x2D60($at)
    MEM_W(-0X2D60, ctx->r1) = 0;
    // 0x800CD450: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800CD454: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800CD458: sw          $zero, -0x2D4C($at)
    MEM_W(-0X2D4C, ctx->r1) = 0;
    // 0x800CD45C: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_800CD460:
    // 0x800CD460: sw          $zero, 0x0($sp)
    MEM_W(0X0, ctx->r29) = 0;
L_800CD464:
    // 0x800CD464: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x800CD468: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x800CD46C: lw          $t1, 0x0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X0);
    // 0x800CD470: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x800CD474: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800CD478: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x800CD47C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800CD480: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x800CD484: sh          $zero, -0x2D30($at)
    MEM_H(-0X2D30, ctx->r1) = 0;
    // 0x800CD488: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800CD48C: sltiu       $at, $t2, 0x4
    ctx->r1 = ctx->r10 < 0X4 ? 1 : 0;
    // 0x800CD490: bne         $at, $zero, L_800CD464
    if (ctx->r1 != 0) {
        // 0x800CD494: sw          $t2, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r10;
            goto L_800CD464;
    }
    // 0x800CD494: sw          $t2, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r10;
    // 0x800CD498: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x800CD49C: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800CD4A0: sltiu       $at, $t4, 0x20
    ctx->r1 = ctx->r12 < 0X20 ? 1 : 0;
    // 0x800CD4A4: bne         $at, $zero, L_800CD460
    if (ctx->r1 != 0) {
        // 0x800CD4A8: sw          $t4, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r12;
            goto L_800CD460;
    }
    // 0x800CD4A8: sw          $t4, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r12;
    // 0x800CD4AC: jr          $ra
    // 0x800CD4B0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800CD4B0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800CD4B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CD4B4: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x800CD4B8: andi        $t8, $a0, 0x3E0
    ctx->r24 = ctx->r4 & 0X3E0;
    // 0x800CD4BC: sra         $t9, $t8, 5
    ctx->r25 = S32(SIGNED(ctx->r24) >> 5);
    // 0x800CD4C0: andi        $t6, $a0, 0x1F
    ctx->r14 = ctx->r4 & 0X1F;
    // 0x800CD4C4: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800CD4C8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800CD4CC: sll         $t0, $t9, 11
    ctx->r8 = S32(ctx->r25 << 11);
    // 0x800CD4D0: addu        $t1, $t7, $t0
    ctx->r9 = ADD32(ctx->r15, ctx->r8);
    // 0x800CD4D4: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x800CD4D8: sw          $t1, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r9;
    // 0x800CD4DC: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_800CD4E0:
    // 0x800CD4E0: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x800CD4E4: lw          $t2, 0x0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X0);
    // 0x800CD4E8: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x800CD4EC: sll         $t4, $t3, 7
    ctx->r12 = S32(ctx->r11 << 7);
    // 0x800CD4F0: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x800CD4F4: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x800CD4F8: lw          $t7, 0x0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X0);
    // 0x800CD4FC: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x800CD500: lbu         $t6, -0x3C00($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X3C00);
    // 0x800CD504: sll         $t8, $t3, 3
    ctx->r24 = S32(ctx->r11 << 3);
    // 0x800CD508: addu        $t9, $a2, $t8
    ctx->r25 = ADD32(ctx->r6, ctx->r24);
    // 0x800CD50C: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800CD510: sll         $t1, $t0, 7
    ctx->r9 = S32(ctx->r8 << 7);
    // 0x800CD514: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800CD518: lui         $t4, 0x800C
    ctx->r12 = S32(0X800C << 16);
    // 0x800CD51C: addu        $t2, $t7, $t1
    ctx->r10 = ADD32(ctx->r15, ctx->r9);
    // 0x800CD520: addu        $t4, $t4, $t2
    ctx->r12 = ADD32(ctx->r12, ctx->r10);
    // 0x800CD524: sb          $t6, 0x400($at)
    MEM_B(0X400, ctx->r1) = ctx->r14;
    // 0x800CD528: lbu         $t4, -0x3BFF($t4)
    ctx->r12 = MEM_BU(ctx->r12, -0X3BFF);
    // 0x800CD52C: sll         $t5, $t0, 3
    ctx->r13 = S32(ctx->r8 << 3);
    // 0x800CD530: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x800CD534: addu        $t3, $a2, $t5
    ctx->r11 = ADD32(ctx->r6, ctx->r13);
    // 0x800CD538: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800CD53C: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x800CD540: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x800CD544: sb          $t4, 0x401($at)
    MEM_B(0X401, ctx->r1) = ctx->r12;
    // 0x800CD548: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x800CD54C: sll         $t9, $t6, 7
    ctx->r25 = S32(ctx->r14 << 7);
    // 0x800CD550: lw          $t5, 0x0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X0);
    // 0x800CD554: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x800CD558: addu        $t7, $t8, $t9
    ctx->r15 = ADD32(ctx->r24, ctx->r25);
    // 0x800CD55C: addu        $t1, $t1, $t7
    ctx->r9 = ADD32(ctx->r9, ctx->r15);
    // 0x800CD560: lbu         $t1, -0x3BFE($t1)
    ctx->r9 = MEM_BU(ctx->r9, -0X3BFE);
    // 0x800CD564: sll         $t2, $t6, 3
    ctx->r10 = S32(ctx->r14 << 3);
    // 0x800CD568: sll         $t3, $t4, 7
    ctx->r11 = S32(ctx->r12 << 7);
    // 0x800CD56C: addu        $t0, $a2, $t2
    ctx->r8 = ADD32(ctx->r6, ctx->r10);
    // 0x800CD570: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800CD574: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x800CD578: addu        $t8, $t5, $t3
    ctx->r24 = ADD32(ctx->r13, ctx->r11);
    // 0x800CD57C: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x800CD580: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800CD584: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x800CD588: lbu         $t9, -0x3BFD($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X3BFD);
    // 0x800CD58C: sll         $t7, $t4, 3
    ctx->r15 = S32(ctx->r12 << 3);
    // 0x800CD590: sb          $t1, 0x402($at)
    MEM_B(0X402, ctx->r1) = ctx->r9;
    // 0x800CD594: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800CD598: addu        $t6, $a2, $t7
    ctx->r14 = ADD32(ctx->r6, ctx->r15);
    // 0x800CD59C: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800CD5A0: addiu       $t1, $t2, 0x1
    ctx->r9 = ADD32(ctx->r10, 0X1);
    // 0x800CD5A4: sb          $t9, 0x403($at)
    MEM_B(0X403, ctx->r1) = ctx->r25;
    // 0x800CD5A8: sltiu       $at, $t1, 0x10
    ctx->r1 = ctx->r9 < 0X10 ? 1 : 0;
    // 0x800CD5AC: bne         $at, $zero, L_800CD4E0
    if (ctx->r1 != 0) {
        // 0x800CD5B0: sw          $t1, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r9;
            goto L_800CD4E0;
    }
    // 0x800CD5B0: sw          $t1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r9;
    // 0x800CD5B4: andi        $t3, $a1, 0x3E0
    ctx->r11 = ctx->r5 & 0X3E0;
    // 0x800CD5B8: sra         $t8, $t3, 5
    ctx->r24 = S32(SIGNED(ctx->r11) >> 5);
    // 0x800CD5BC: andi        $t0, $a1, 0x1F
    ctx->r8 = ctx->r5 & 0X1F;
    // 0x800CD5C0: sll         $t5, $t0, 2
    ctx->r13 = S32(ctx->r8 << 2);
    // 0x800CD5C4: sll         $t4, $t8, 11
    ctx->r12 = S32(ctx->r24 << 11);
    // 0x800CD5C8: addu        $t7, $t5, $t4
    ctx->r15 = ADD32(ctx->r13, ctx->r12);
    // 0x800CD5CC: sw          $t7, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r15;
    // 0x800CD5D0: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
L_800CD5D4:
    // 0x800CD5D4: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x800CD5D8: lw          $t9, 0x0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X0);
    // 0x800CD5DC: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x800CD5E0: sll         $t2, $t6, 7
    ctx->r10 = S32(ctx->r14 << 7);
    // 0x800CD5E4: lui         $t0, 0x800C
    ctx->r8 = S32(0X800C << 16);
    // 0x800CD5E8: addu        $t1, $t9, $t2
    ctx->r9 = ADD32(ctx->r25, ctx->r10);
    // 0x800CD5EC: lw          $t5, 0x0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X0);
    // 0x800CD5F0: addu        $t0, $t0, $t1
    ctx->r8 = ADD32(ctx->r8, ctx->r9);
    // 0x800CD5F4: lbu         $t0, -0x3C00($t0)
    ctx->r8 = MEM_BU(ctx->r8, -0X3C00);
    // 0x800CD5F8: sll         $t3, $t6, 3
    ctx->r11 = S32(ctx->r14 << 3);
    // 0x800CD5FC: addu        $t8, $a2, $t3
    ctx->r24 = ADD32(ctx->r6, ctx->r11);
    // 0x800CD600: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800CD604: sll         $t7, $t4, 7
    ctx->r15 = S32(ctx->r12 << 7);
    // 0x800CD608: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800CD60C: lui         $t2, 0x800C
    ctx->r10 = S32(0X800C << 16);
    // 0x800CD610: addu        $t9, $t5, $t7
    ctx->r25 = ADD32(ctx->r13, ctx->r15);
    // 0x800CD614: addu        $t2, $t2, $t9
    ctx->r10 = ADD32(ctx->r10, ctx->r25);
    // 0x800CD618: sb          $t0, 0x404($at)
    MEM_B(0X404, ctx->r1) = ctx->r8;
    // 0x800CD61C: lbu         $t2, -0x3BFF($t2)
    ctx->r10 = MEM_BU(ctx->r10, -0X3BFF);
    // 0x800CD620: sll         $t1, $t4, 3
    ctx->r9 = S32(ctx->r12 << 3);
    // 0x800CD624: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x800CD628: addu        $t6, $a2, $t1
    ctx->r14 = ADD32(ctx->r6, ctx->r9);
    // 0x800CD62C: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800CD630: lw          $t3, 0x0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X0);
    // 0x800CD634: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800CD638: sb          $t2, 0x405($at)
    MEM_B(0X405, ctx->r1) = ctx->r10;
    // 0x800CD63C: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x800CD640: sll         $t8, $t0, 7
    ctx->r24 = S32(ctx->r8 << 7);
    // 0x800CD644: lw          $t1, 0x0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X0);
    // 0x800CD648: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x800CD64C: addu        $t5, $t3, $t8
    ctx->r13 = ADD32(ctx->r11, ctx->r24);
    // 0x800CD650: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x800CD654: lbu         $t7, -0x3BFE($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X3BFE);
    // 0x800CD658: sll         $t9, $t0, 3
    ctx->r25 = S32(ctx->r8 << 3);
    // 0x800CD65C: sll         $t6, $t2, 7
    ctx->r14 = S32(ctx->r10 << 7);
    // 0x800CD660: addu        $t4, $a2, $t9
    ctx->r12 = ADD32(ctx->r6, ctx->r25);
    // 0x800CD664: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800CD668: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x800CD66C: addu        $t3, $t1, $t6
    ctx->r11 = ADD32(ctx->r9, ctx->r14);
    // 0x800CD670: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x800CD674: addu        $t8, $t8, $t3
    ctx->r24 = ADD32(ctx->r24, ctx->r11);
    // 0x800CD678: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x800CD67C: lbu         $t8, -0x3BFD($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X3BFD);
    // 0x800CD680: sll         $t5, $t2, 3
    ctx->r13 = S32(ctx->r10 << 3);
    // 0x800CD684: sb          $t7, 0x406($at)
    MEM_B(0X406, ctx->r1) = ctx->r15;
    // 0x800CD688: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800CD68C: addu        $t0, $a2, $t5
    ctx->r8 = ADD32(ctx->r6, ctx->r13);
    // 0x800CD690: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x800CD694: addiu       $t7, $t9, 0x1
    ctx->r15 = ADD32(ctx->r25, 0X1);
    // 0x800CD698: sb          $t8, 0x407($at)
    MEM_B(0X407, ctx->r1) = ctx->r24;
    // 0x800CD69C: sltiu       $at, $t7, 0x10
    ctx->r1 = ctx->r15 < 0X10 ? 1 : 0;
    // 0x800CD6A0: bne         $at, $zero, L_800CD5D4
    if (ctx->r1 != 0) {
        // 0x800CD6A4: sw          $t7, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r15;
            goto L_800CD5D4;
    }
    // 0x800CD6A4: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x800CD6A8: jr          $ra
    // 0x800CD6AC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800CD6AC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_800CD6B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CD6B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800CD6B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800CD6B8: jal         0x800D73E0
    // 0x800CD6BC: nop

    osInitialize_recomp(rdram, ctx);
        goto after_0;
    // 0x800CD6BC: nop

    after_0:
    // 0x800CD6C0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800CD6C4: addiu       $t6, $t6, 0x6A60
    ctx->r14 = ADD32(ctx->r14, 0X6A60);
    // 0x800CD6C8: addiu       $t7, $t6, 0x2000
    ctx->r15 = ADD32(ctx->r14, 0X2000);
    // 0x800CD6CC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800CD6D0: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x800CD6D4: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x800CD6D8: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x800CD6DC: addiu       $a2, $a2, -0x28F0
    ctx->r6 = ADD32(ctx->r6, -0X28F0);
    // 0x800CD6E0: addiu       $a0, $a0, 0x4700
    ctx->r4 = ADD32(ctx->r4, 0X4700);
    // 0x800CD6E4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800CD6E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800CD6EC: jal         0x800D76A0
    // 0x800CD6F0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    osCreateThread_recomp(rdram, ctx);
        goto after_1;
    // 0x800CD6F0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x800CD6F4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800CD6F8: jal         0x800D77F0
    // 0x800CD6FC: addiu       $a0, $a0, 0x4700
    ctx->r4 = ADD32(ctx->r4, 0X4700);
    osStartThread_recomp(rdram, ctx);
        goto after_2;
    // 0x800CD6FC: addiu       $a0, $a0, 0x4700
    ctx->r4 = ADD32(ctx->r4, 0X4700);
    after_2:
    // 0x800CD700: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800CD704: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800CD708: jr          $ra
    // 0x800CD70C: nop

    return;
    // 0x800CD70C: nop

;}
RECOMP_FUNC void func_800CD710(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CD710: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800CD714: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800CD718: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800CD71C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800CD720: jal         0x800D1FA0
    // 0x800CD724: sw          $zero, -0x75A0($at)
    MEM_W(-0X75A0, ctx->r1) = 0;
    func_800D1FA0(rdram, ctx);
        goto after_0;
    // 0x800CD724: sw          $zero, -0x75A0($at)
    MEM_W(-0X75A0, ctx->r1) = 0;
    after_0:
    // 0x800CD728: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x800CD72C: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x800CD730: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800CD734: bne         $t6, $at, L_800CD750
    if (ctx->r14 != ctx->r1) {
        // 0x800CD738: nop
    
            goto L_800CD750;
    }
    // 0x800CD738: nop

    // 0x800CD73C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x800CD740: jal         0x800D1FE0
    // 0x800CD744: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D1FE0(rdram, ctx);
        goto after_1;
    // 0x800CD744: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x800CD748: b           L_800CD75C
    // 0x800CD74C: nop

        goto L_800CD75C;
    // 0x800CD74C: nop

L_800CD750:
    // 0x800CD750: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x800CD754: jal         0x800D1FE0
    // 0x800CD758: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D1FE0(rdram, ctx);
        goto after_2;
    // 0x800CD758: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
L_800CD75C:
    // 0x800CD75C: jal         0x800D3BB0
    // 0x800CD760: addiu       $a0, $zero, 0x5A
    ctx->r4 = ADD32(0, 0X5A);
    osViSetSpecialFeatures_recomp(rdram, ctx);
        goto after_3;
    // 0x800CD760: addiu       $a0, $zero, 0x5A
    ctx->r4 = ADD32(0, 0X5A);
    after_3:
    // 0x800CD764: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800CD768: addiu       $t7, $t7, 0x4A60
    ctx->r15 = ADD32(ctx->r15, 0X4A60);
    // 0x800CD76C: addiu       $t8, $t7, 0x2000
    ctx->r24 = ADD32(ctx->r15, 0X2000);
    // 0x800CD770: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800CD774: lui         $a2, 0x800C
    ctx->r6 = S32(0X800C << 16);
    // 0x800CD778: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x800CD77C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x800CD780: addiu       $a2, $a2, 0x2450
    ctx->r6 = ADD32(ctx->r6, 0X2450);
    // 0x800CD784: addiu       $a0, $a0, 0x48B0
    ctx->r4 = ADD32(ctx->r4, 0X48B0);
    // 0x800CD788: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800CD78C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800CD790: jal         0x800D76A0
    // 0x800CD794: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    osCreateThread_recomp(rdram, ctx);
        goto after_4;
    // 0x800CD794: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x800CD798: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800CD79C: jal         0x800D77F0
    // 0x800CD7A0: addiu       $a0, $a0, 0x48B0
    ctx->r4 = ADD32(ctx->r4, 0X48B0);
    osStartThread_recomp(rdram, ctx);
        goto after_5;
    // 0x800CD7A0: addiu       $a0, $a0, 0x48B0
    ctx->r4 = ADD32(ctx->r4, 0X48B0);
    after_5:
    // 0x800CD7A4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800CD7A8: addiu       $a0, $a0, 0x4700
    ctx->r4 = ADD32(ctx->r4, 0X4700);
    // 0x800CD7AC: jal         0x800D7940
    // 0x800CD7B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    osSetThreadPri_recomp(rdram, ctx);
        goto after_6;
    // 0x800CD7B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
L_800CD7B4:
    // 0x800CD7B4: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800CD7B8: lw          $t0, -0x75A0($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X75A0);
    // 0x800CD7BC: beq         $t0, $zero, L_800CD7B4
    if (ctx->r8 == 0) {
        // 0x800CD7C0: nop
    
            goto L_800CD7B4;
    }
    // 0x800CD7C0: nop

    // 0x800CD7C4: jalr        $t0
    // 0x800CD7C8: nop

    LOOKUP_FUNC(ctx->r8)(rdram, ctx);
        goto after_7;
    // 0x800CD7C8: nop

    after_7:
    // 0x800CD7CC: b           L_800CD7B4
    // 0x800CD7D0: nop

        goto L_800CD7B4;
    // 0x800CD7D0: nop

    // 0x800CD7D4: nop

    // 0x800CD7D8: nop

    // 0x800CD7DC: nop

    // 0x800CD7E0: nop

    // 0x800CD7E4: nop

    // 0x800CD7E8: nop

    // 0x800CD7EC: nop

    // 0x800CD7F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800CD7F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800CD7F8: jr          $ra
    // 0x800CD7FC: nop

    return;
    // 0x800CD7FC: nop

;}
RECOMP_FUNC void func_800CD800(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CD800: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CD804: andi        $t6, $a1, 0x1
    ctx->r14 = ctx->r5 & 0X1;
    // 0x800CD808: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CD80C: beq         $t6, $zero, L_800CD818
    if (ctx->r14 == 0) {
        // 0x800CD810: or          $a2, $a1, $zero
        ctx->r6 = ctx->r5 | 0;
            goto L_800CD818;
    }
    // 0x800CD810: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800CD814: addiu       $a2, $a1, 0x1
    ctx->r6 = ADD32(ctx->r5, 0X1);
L_800CD818:
    // 0x800CD818: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x800CD81C: lw          $a1, -0x6514($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6514);
    // 0x800CD820: jal         0x800D1D10
    // 0x800CD824: nop

    func_800D1D10(rdram, ctx);
        goto after_0;
    // 0x800CD824: nop

    after_0:
    // 0x800CD828: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CD82C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CD830: jr          $ra
    // 0x800CD834: nop

    return;
    // 0x800CD834: nop

    // 0x800CD838: nop

    // 0x800CD83C: nop

;}
RECOMP_FUNC void func_800CD840(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CD840: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CD844: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800CD848: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CD84C: lw          $a0, -0x6514($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6514);
    // 0x800CD850: jal         0x800CF054
    // 0x800CD854: nop

    func_800CF054(rdram, ctx);
        goto after_0;
    // 0x800CD854: nop

    after_0:
    // 0x800CD858: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CD85C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CD860: jr          $ra
    // 0x800CD864: nop

    return;
    // 0x800CD864: nop

    // 0x800CD868: nop

    // 0x800CD86C: nop

;}
RECOMP_FUNC void func_800CD870(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CD870: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CD874: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CD878: jal         0x800CF1CC
    // 0x800CD87C: nop

    func_800CF1CC(rdram, ctx);
        goto after_0;
    // 0x800CD87C: nop

    after_0:
    // 0x800CD880: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CD884: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CD888: jr          $ra
    // 0x800CD88C: nop

    return;
    // 0x800CD88C: nop

;}
RECOMP_FUNC void func_800CD890(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CD890: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800CD894: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800CD898: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800CD89C: jal         0x800CF2B0
    // 0x800CD8A0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_800CF2B0(rdram, ctx);
        goto after_0;
    // 0x800CD8A0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x800CD8A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800CD8A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800CD8AC: jr          $ra
    // 0x800CD8B0: nop

    return;
    // 0x800CD8B0: nop

    // 0x800CD8B4: nop

    // 0x800CD8B8: nop

    // 0x800CD8BC: nop

;}
RECOMP_FUNC void func_800CD8C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CD8C0: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x800CD8C4: addiu       $t1, $t1, -0x6C00
    ctx->r9 = ADD32(ctx->r9, -0X6C00);
    // 0x800CD8C8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800CD8CC: lw          $t0, 0x4($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X4);
    // 0x800CD8D0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800CD8D4: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800CD8D8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800CD8DC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800CD8E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800CD8E4: beq         $t0, $zero, L_800CD940
    if (ctx->r8 == 0) {
        // 0x800CD8E8: or          $a3, $t0, $zero
        ctx->r7 = ctx->r8 | 0;
            goto L_800CD940;
    }
    // 0x800CD8E8: or          $a3, $t0, $zero
    ctx->r7 = ctx->r8 | 0;
L_800CD8EC:
    // 0x800CD8EC: lw          $v0, 0x8($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X8);
    // 0x800CD8F0: addu        $t6, $s0, $a1
    ctx->r14 = ADD32(ctx->r16, ctx->r5);
    // 0x800CD8F4: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800CD8F8: bne         $at, $zero, L_800CD940
    if (ctx->r1 != 0) {
        // 0x800CD8FC: addiu       $v1, $v0, 0x400
        ctx->r3 = ADD32(ctx->r2, 0X400);
            goto L_800CD940;
    }
    // 0x800CD8FC: addiu       $v1, $v0, 0x400
    ctx->r3 = ADD32(ctx->r2, 0X400);
    // 0x800CD900: slt         $at, $v1, $t6
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800CD904: bne         $at, $zero, L_800CD930
    if (ctx->r1 != 0) {
        // 0x800CD908: or          $a2, $a3, $zero
        ctx->r6 = ctx->r7 | 0;
            goto L_800CD930;
    }
    // 0x800CD908: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x800CD90C: lw          $t8, 0x10($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X10);
    // 0x800CD910: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x800CD914: lw          $t7, -0x4690($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4690);
    // 0x800CD918: addu        $t9, $t8, $s0
    ctx->r25 = ADD32(ctx->r24, ctx->r16);
    // 0x800CD91C: subu        $a0, $t9, $v0
    ctx->r4 = SUB32(ctx->r25, ctx->r2);
    // 0x800CD920: jal         0x800D70A0
    // 0x800CD924: sw          $t7, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r15;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_0;
    // 0x800CD924: sw          $t7, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r15;
    after_0:
    // 0x800CD928: b           L_800CDA74
    // 0x800CD92C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800CDA74;
    // 0x800CD92C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800CD930:
    // 0x800CD930: lw          $a3, 0x0($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X0);
    // 0x800CD934: nop

    // 0x800CD938: bne         $a3, $zero, L_800CD8EC
    if (ctx->r7 != 0) {
        // 0x800CD93C: nop
    
            goto L_800CD8EC;
    }
    // 0x800CD93C: nop

L_800CD940:
    // 0x800CD940: lw          $a3, 0x8($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X8);
    // 0x800CD944: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800CD948: bne         $a3, $zero, L_800CD95C
    if (ctx->r7 != 0) {
        // 0x800CD94C: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_800CD95C;
    }
    // 0x800CD94C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800CD950: lw          $v0, 0x10($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X10);
    // 0x800CD954: b           L_800CDA70
    // 0x800CD958: addu        $v0, $v0, $at
    ctx->r2 = ADD32(ctx->r2, ctx->r1);
        goto L_800CDA70;
    // 0x800CD958: addu        $v0, $v0, $at
    ctx->r2 = ADD32(ctx->r2, ctx->r1);
L_800CD95C:
    // 0x800CD95C: lw          $t3, 0x0($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X0);
    // 0x800CD960: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800CD964: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800CD968: jal         0x800D8840
    // 0x800CD96C: sw          $t3, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r11;
    alUnlink_recomp(rdram, ctx);
        goto after_1;
    // 0x800CD96C: sw          $t3, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r11;
    after_1:
    // 0x800CD970: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800CD974: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x800CD978: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x800CD97C: beq         $a2, $zero, L_800CD9A0
    if (ctx->r6 == 0) {
        // 0x800CD980: addiu       $t1, $t1, -0x6C00
        ctx->r9 = ADD32(ctx->r9, -0X6C00);
            goto L_800CD9A0;
    }
    // 0x800CD980: addiu       $t1, $t1, -0x6C00
    ctx->r9 = ADD32(ctx->r9, -0X6C00);
    // 0x800CD984: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800CD988: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x800CD98C: jal         0x800D8870
    // 0x800CD990: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    alLink_recomp(rdram, ctx);
        goto after_2;
    // 0x800CD990: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_2:
    // 0x800CD994: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x800CD998: b           L_800CD9D0
    // 0x800CD99C: nop

        goto L_800CD9D0;
    // 0x800CD99C: nop

L_800CD9A0:
    // 0x800CD9A0: lw          $t0, 0x4($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X4);
    // 0x800CD9A4: nop

    // 0x800CD9A8: beq         $t0, $zero, L_800CD9C4
    if (ctx->r8 == 0) {
        // 0x800CD9AC: nop
    
            goto L_800CD9C4;
    }
    // 0x800CD9AC: nop

    // 0x800CD9B0: sw          $a3, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r7;
    // 0x800CD9B4: sw          $t0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r8;
    // 0x800CD9B8: sw          $zero, 0x4($a3)
    MEM_W(0X4, ctx->r7) = 0;
    // 0x800CD9BC: b           L_800CD9D0
    // 0x800CD9C0: sw          $a3, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r7;
        goto L_800CD9D0;
    // 0x800CD9C0: sw          $a3, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r7;
L_800CD9C4:
    // 0x800CD9C4: sw          $a3, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r7;
    // 0x800CD9C8: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
    // 0x800CD9CC: sw          $zero, 0x4($a3)
    MEM_W(0X4, ctx->r7) = 0;
L_800CD9D0:
    // 0x800CD9D0: jal         0x800D8900
    // 0x800CD9D4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    osCartRomInit_recomp(rdram, ctx);
        goto after_3;
    // 0x800CD9D4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_3:
    // 0x800CD9D8: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x800CD9DC: addiu       $t2, $t2, -0x66F0
    ctx->r10 = ADD32(ctx->r10, -0X66F0);
    // 0x800CD9E0: lw          $v1, 0x0($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X0);
    // 0x800CD9E4: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x800CD9E8: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x800CD9EC: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x800CD9F0: andi        $t0, $s0, 0x1
    ctx->r8 = ctx->r16 & 0X1;
    // 0x800CD9F4: lw          $t1, 0x10($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X10);
    // 0x800CD9F8: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x800CD9FC: subu        $s0, $s0, $t0
    ctx->r16 = SUB32(ctx->r16, ctx->r8);
    // 0x800CDA00: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x800CDA04: sll         $t4, $v1, 2
    ctx->r12 = S32(ctx->r3 << 2);
    // 0x800CDA08: sw          $s0, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r16;
    // 0x800CDA0C: lw          $t7, -0x4690($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4690);
    // 0x800CDA10: lui         $t5, 0x8014
    ctx->r13 = S32(0X8014 << 16);
    // 0x800CDA14: subu        $t4, $t4, $v1
    ctx->r12 = SUB32(ctx->r12, ctx->r3);
    // 0x800CDA18: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x800CDA1C: addiu       $t5, $t5, -0x7200
    ctx->r13 = ADD32(ctx->r13, -0X7200);
    // 0x800CDA20: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    // 0x800CDA24: sw          $t7, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r15;
    // 0x800CDA28: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x800CDA2C: addiu       $t8, $t8, -0x7318
    ctx->r24 = ADD32(ctx->r24, -0X7318);
    // 0x800CDA30: addiu       $t9, $zero, 0x400
    ctx->r25 = ADD32(0, 0X400);
    // 0x800CDA34: sb          $zero, 0x2($a1)
    MEM_B(0X2, ctx->r5) = 0;
    // 0x800CDA38: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    // 0x800CDA3C: sw          $s0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r16;
    // 0x800CDA40: sw          $t9, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r25;
    // 0x800CDA44: sw          $t1, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r9;
    // 0x800CDA48: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800CDA4C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800CDA50: jal         0x800D8A00
    // 0x800CDA54: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    osEPiStartDma_recomp(rdram, ctx);
        goto after_4;
    // 0x800CDA54: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    after_4:
    // 0x800CDA58: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800CDA5C: jal         0x800D70A0
    // 0x800CDA60: nop

    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_5;
    // 0x800CDA60: nop

    after_5:
    // 0x800CDA64: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x800CDA68: nop

    // 0x800CDA6C: addu        $v0, $v0, $t3
    ctx->r2 = ADD32(ctx->r2, ctx->r11);
L_800CDA70:
    // 0x800CDA70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800CDA74:
    // 0x800CDA74: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800CDA78: jr          $ra
    // 0x800CDA7C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800CDA7C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800CDA80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CDA80: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800CDA84: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800CDA88: lui         $s4, 0x8014
    ctx->r20 = S32(0X8014 << 16);
    // 0x800CDA8C: addiu       $s4, $s4, -0x6C00
    ctx->r20 = ADD32(ctx->r20, -0X6C00);
    // 0x800CDA90: lbu         $t6, 0x0($s4)
    ctx->r14 = MEM_BU(ctx->r20, 0X0);
    // 0x800CDA94: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800CDA98: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800CDA9C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800CDAA0: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800CDAA4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800CDAA8: bne         $t6, $zero, L_800CDB4C
    if (ctx->r14 != 0) {
        // 0x800CDAAC: sw          $a0, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r4;
            goto L_800CDB4C;
    }
    // 0x800CDAAC: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800CDAB0: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800CDAB4: addiu       $v0, $v0, -0x6BF0
    ctx->r2 = ADD32(ctx->r2, -0X6BF0);
    // 0x800CDAB8: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x800CDABC: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x800CDAC0: lui         $s3, 0x8014
    ctx->r19 = S32(0X8014 << 16);
    // 0x800CDAC4: lui         $s2, 0x8014
    ctx->r18 = S32(0X8014 << 16);
    // 0x800CDAC8: sw          $v0, 0x8($s4)
    MEM_W(0X8, ctx->r20) = ctx->r2;
    // 0x800CDACC: sw          $zero, 0x4($s4)
    MEM_W(0X4, ctx->r20) = 0;
    // 0x800CDAD0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800CDAD4: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800CDAD8: addiu       $s2, $s2, -0x66E8
    ctx->r18 = ADD32(ctx->r18, -0X66E8);
    // 0x800CDADC: addiu       $s3, $s3, -0x66F0
    ctx->r19 = ADD32(ctx->r19, -0X66F0);
    // 0x800CDAE0: addiu       $s0, $s0, -0x6BDC
    ctx->r16 = ADD32(ctx->r16, -0X6BDC);
    // 0x800CDAE4: addiu       $s1, $s1, -0x6BF0
    ctx->r17 = ADD32(ctx->r17, -0X6BF0);
L_800CDAE8:
    // 0x800CDAE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800CDAEC: jal         0x800D8870
    // 0x800CDAF0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    alLink_recomp(rdram, ctx);
        goto after_0;
    // 0x800CDAF0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x800CDAF4: addiu       $t7, $zero, 0x400
    ctx->r15 = ADD32(0, 0X400);
    // 0x800CDAF8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800CDAFC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800CDB00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800CDB04: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800CDB08: jal         0x800D8AE0
    // 0x800CDB0C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc_recomp(rdram, ctx);
        goto after_1;
    // 0x800CDB0C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x800CDB10: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    // 0x800CDB14: addiu       $s1, $s1, 0x14
    ctx->r17 = ADD32(ctx->r17, 0X14);
    // 0x800CDB18: bne         $s0, $s3, L_800CDAE8
    if (ctx->r16 != ctx->r19) {
        // 0x800CDB1C: sw          $v0, -0x4($s1)
        MEM_W(-0X4, ctx->r17) = ctx->r2;
            goto L_800CDAE8;
    }
    // 0x800CDB1C: sw          $v0, -0x4($s1)
    MEM_W(-0X4, ctx->r17) = ctx->r2;
    // 0x800CDB20: addiu       $t8, $zero, 0x400
    ctx->r24 = ADD32(0, 0X400);
    // 0x800CDB24: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800CDB28: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800CDB2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800CDB30: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800CDB34: jal         0x800D8AE0
    // 0x800CDB38: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc_recomp(rdram, ctx);
        goto after_2;
    // 0x800CDB38: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x800CDB3C: lbu         $t9, 0x0($s4)
    ctx->r25 = MEM_BU(ctx->r20, 0X0);
    // 0x800CDB40: sw          $v0, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r2;
    // 0x800CDB44: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800CDB48: sb          $t0, 0x0($s4)
    MEM_B(0X0, ctx->r20) = ctx->r8;
L_800CDB4C:
    // 0x800CDB4C: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x800CDB50: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800CDB54: sw          $zero, -0x66F0($at)
    MEM_W(-0X66F0, ctx->r1) = 0;
    // 0x800CDB58: sw          $s4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r20;
    // 0x800CDB5C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800CDB60: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800CDB64: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800CDB68: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800CDB6C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800CDB70: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800CDB74: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800CDB78: addiu       $v0, $v0, -0x2740
    ctx->r2 = ADD32(ctx->r2, -0X2740);
    // 0x800CDB7C: jr          $ra
    // 0x800CDB80: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800CDB80: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_800CDB84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CDB84: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800CDB88: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800CDB8C: lui         $s2, 0x8014
    ctx->r18 = S32(0X8014 << 16);
    // 0x800CDB90: addiu       $s2, $s2, -0x6C00
    ctx->r18 = ADD32(ctx->r18, -0X6C00);
    // 0x800CDB94: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800CDB98: lw          $s0, 0x4($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X4);
    // 0x800CDB9C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800CDBA0: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800CDBA4: beq         $s0, $zero, L_800CDC20
    if (ctx->r16 == 0) {
        // 0x800CDBA8: sw          $s1, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r17;
            goto L_800CDC20;
    }
    // 0x800CDBA8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800CDBAC: lui         $s3, 0x800F
    ctx->r19 = S32(0X800F << 16);
    // 0x800CDBB0: addiu       $s3, $s3, -0x4690
    ctx->r19 = ADD32(ctx->r19, -0X4690);
L_800CDBB4:
    // 0x800CDBB4: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x800CDBB8: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x800CDBBC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800CDBC0: addiu       $t8, $t7, 0x2
    ctx->r24 = ADD32(ctx->r15, 0X2);
    // 0x800CDBC4: sltu        $at, $t8, $t6
    ctx->r1 = ctx->r24 < ctx->r14 ? 1 : 0;
    // 0x800CDBC8: beq         $at, $zero, L_800CDC18
    if (ctx->r1 == 0) {
        // 0x800CDBCC: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_800CDC18;
    }
    // 0x800CDBCC: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800CDBD0: lw          $t9, 0x4($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X4);
    // 0x800CDBD4: nop

    // 0x800CDBD8: bne         $s0, $t9, L_800CDBE4
    if (ctx->r16 != ctx->r25) {
        // 0x800CDBDC: nop
    
            goto L_800CDBE4;
    }
    // 0x800CDBDC: nop

    // 0x800CDBE0: sw          $v0, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r2;
L_800CDBE4:
    // 0x800CDBE4: jal         0x800D8840
    // 0x800CDBE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    alUnlink_recomp(rdram, ctx);
        goto after_0;
    // 0x800CDBE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800CDBEC: lw          $a1, 0x8($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X8);
    // 0x800CDBF0: nop

    // 0x800CDBF4: beq         $a1, $zero, L_800CDC0C
    if (ctx->r5 == 0) {
        // 0x800CDBF8: nop
    
            goto L_800CDC0C;
    }
    // 0x800CDBF8: nop

    // 0x800CDBFC: jal         0x800D8870
    // 0x800CDC00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    alLink_recomp(rdram, ctx);
        goto after_1;
    // 0x800CDC00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800CDC04: b           L_800CDC18
    // 0x800CDC08: nop

        goto L_800CDC18;
    // 0x800CDC08: nop

L_800CDC0C:
    // 0x800CDC0C: sw          $s0, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r16;
    // 0x800CDC10: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x800CDC14: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
L_800CDC18:
    // 0x800CDC18: bne         $s1, $zero, L_800CDBB4
    if (ctx->r17 != 0) {
        // 0x800CDC1C: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_800CDBB4;
    }
    // 0x800CDC1C: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
L_800CDC20:
    // 0x800CDC20: lui         $s3, 0x800F
    ctx->r19 = S32(0X800F << 16);
    // 0x800CDC24: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800CDC28: addiu       $s3, $s3, -0x4690
    ctx->r19 = ADD32(ctx->r19, -0X4690);
    // 0x800CDC2C: sw          $zero, -0x66F0($at)
    MEM_W(-0X66F0, ctx->r1) = 0;
    // 0x800CDC30: lw          $t0, 0x0($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X0);
    // 0x800CDC34: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800CDC38: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800CDC3C: sw          $t1, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r9;
    // 0x800CDC40: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800CDC44: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800CDC48: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800CDC4C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800CDC50: jr          $ra
    // 0x800CDC54: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800CDC54: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800CDC58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CDC58: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800CDC5C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800CDC60: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800CDC64: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800CDC68: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x800CDC6C: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x800CDC70: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x800CDC74: addiu       $s0, $s0, -0x66E8
    ctx->r16 = ADD32(ctx->r16, -0X66E8);
    // 0x800CDC78: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800CDC7C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800CDC80: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800CDC84: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800CDC88: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800CDC8C: sb          $t6, -0x4684($at)
    MEM_B(-0X4684, ctx->r1) = ctx->r14;
    // 0x800CDC90: jal         0x800D8B40
    // 0x800CDC94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    alHeapInit_recomp(rdram, ctx);
        goto after_0;
    // 0x800CDC94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800CDC98: addiu       $t7, $zero, 0x4000
    ctx->r15 = ADD32(0, 0X4000);
    // 0x800CDC9C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800CDCA0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800CDCA4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800CDCA8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x800CDCAC: jal         0x800D8AE0
    // 0x800CDCB0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc_recomp(rdram, ctx);
        goto after_1;
    // 0x800CDCB0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x800CDCB4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800CDCB8: addiu       $t8, $zero, 0x4000
    ctx->r24 = ADD32(0, 0X4000);
    // 0x800CDCBC: sw          $v0, -0x73E0($at)
    MEM_W(-0X73E0, ctx->r1) = ctx->r2;
    // 0x800CDCC0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800CDCC4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800CDCC8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800CDCCC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x800CDCD0: jal         0x800D8AE0
    // 0x800CDCD4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc_recomp(rdram, ctx);
        goto after_2;
    // 0x800CDCD4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x800CDCD8: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800CDCDC: ori         $t9, $zero, 0x8000
    ctx->r25 = 0 | 0X8000;
    // 0x800CDCE0: sw          $v0, -0x73DC($at)
    MEM_W(-0X73DC, ctx->r1) = ctx->r2;
    // 0x800CDCE4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800CDCE8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800CDCEC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800CDCF0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x800CDCF4: jal         0x800D8AE0
    // 0x800CDCF8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc_recomp(rdram, ctx);
        goto after_3;
    // 0x800CDCF8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
    // 0x800CDCFC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800CDD00: ori         $t3, $zero, 0x8000
    ctx->r11 = 0 | 0X8000;
    // 0x800CDD04: sw          $v0, -0x7328($at)
    MEM_W(-0X7328, ctx->r1) = ctx->r2;
    // 0x800CDD08: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800CDD0C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800CDD10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800CDD14: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x800CDD18: jal         0x800D8AE0
    // 0x800CDD1C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc_recomp(rdram, ctx);
        goto after_4;
    // 0x800CDD1C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
    // 0x800CDD20: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800CDD24: ori         $t4, $zero, 0x8000
    ctx->r12 = 0 | 0X8000;
    // 0x800CDD28: sw          $v0, -0x7324($at)
    MEM_W(-0X7324, ctx->r1) = ctx->r2;
    // 0x800CDD2C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800CDD30: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800CDD34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800CDD38: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x800CDD3C: jal         0x800D8AE0
    // 0x800CDD40: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc_recomp(rdram, ctx);
        goto after_5;
    // 0x800CDD40: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_5:
    // 0x800CDD44: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800CDD48: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800CDD4C: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x800CDD50: sw          $v0, -0x7320($at)
    MEM_W(-0X7320, ctx->r1) = ctx->r2;
    // 0x800CDD54: addiu       $a1, $a1, -0x7300
    ctx->r5 = ADD32(ctx->r5, -0X7300);
    // 0x800CDD58: addiu       $a0, $a0, -0x7318
    ctx->r4 = ADD32(ctx->r4, -0X7318);
    // 0x800CDD5C: jal         0x800D8B80
    // 0x800CDD60: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_6;
    // 0x800CDD60: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_6:
    // 0x800CDD64: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x800CDD68: addiu       $t5, $t5, -0x2580
    ctx->r13 = ADD32(ctx->r13, -0X2580);
    // 0x800CDD6C: lw          $a0, 0x18($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X18);
    // 0x800CDD70: sw          $t5, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r13;
    // 0x800CDD74: jal         0x800D8BB0
    // 0x800CDD78: sw          $s0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r16;
    osAiSetFrequency_recomp(rdram, ctx);
        goto after_7;
    // 0x800CDD78: sw          $s0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r16;
    after_7:
    // 0x800CDD7C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800CDD80: sw          $v0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r2;
    // 0x800CDD84: addiu       $a0, $a0, -0x66D8
    ctx->r4 = ADD32(ctx->r4, -0X66D8);
    // 0x800CDD88: jal         0x800D88CC
    // 0x800CDD8C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    alInit_recomp(rdram, ctx);
        goto after_8;
    // 0x800CDD8C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_8:
    // 0x800CDD90: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800CDD94: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800CDD98: addiu       $t7, $t7, 0x51F0
    ctx->r15 = ADD32(ctx->r15, 0X51F0);
    // 0x800CDD9C: addiu       $t6, $t6, 0x52C0
    ctx->r14 = ADD32(ctx->r14, 0X52C0);
    // 0x800CDDA0: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800CDDA4: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800CDDA8: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x800CDDAC: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x800CDDB0: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800CDDB4: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800CDDB8: addiu       $a1, $a1, 0x51F0
    ctx->r5 = ADD32(ctx->r5, 0X51F0);
    // 0x800CDDBC: addiu       $a2, $a2, 0x52C0
    ctx->r6 = ADD32(ctx->r6, 0X52C0);
    // 0x800CDDC0: addiu       $a3, $a3, -0x1BA0
    ctx->r7 = ADD32(ctx->r7, -0X1BA0);
    // 0x800CDDC4: addiu       $t1, $t1, -0x6380
    ctx->r9 = ADD32(ctx->r9, -0X6380);
    // 0x800CDDC8: addiu       $v1, $v1, -0x6688
    ctx->r3 = ADD32(ctx->r3, -0X6688);
    // 0x800CDDCC: addiu       $v0, $v0, -0x73D8
    ctx->r2 = ADD32(ctx->r2, -0X73D8);
    // 0x800CDDD0: subu        $t2, $t6, $t7
    ctx->r10 = SUB32(ctx->r14, ctx->r15);
    // 0x800CDDD4: addiu       $t0, $zero, 0x800
    ctx->r8 = ADD32(0, 0X800);
    // 0x800CDDD8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
L_800CDDDC:
    // 0x800CDDDC: addiu       $v1, $v1, 0x184
    ctx->r3 = ADD32(ctx->r3, 0X184);
    // 0x800CDDE0: addiu       $v0, $v0, 0x58
    ctx->r2 = ADD32(ctx->r2, 0X58);
    // 0x800CDDE4: sw          $zero, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = 0;
    // 0x800CDDE8: sw          $a0, -0x48($v0)
    MEM_W(-0X48, ctx->r2) = ctx->r4;
    // 0x800CDDEC: sw          $a1, -0x40($v0)
    MEM_W(-0X40, ctx->r2) = ctx->r5;
    // 0x800CDDF0: sw          $t2, -0x3C($v0)
    MEM_W(-0X3C, ctx->r2) = ctx->r10;
    // 0x800CDDF4: sw          $a2, -0x38($v0)
    MEM_W(-0X38, ctx->r2) = ctx->r6;
    // 0x800CDDF8: sw          $a3, -0x30($v0)
    MEM_W(-0X30, ctx->r2) = ctx->r7;
    // 0x800CDDFC: sw          $t0, -0x2C($v0)
    MEM_W(-0X2C, ctx->r2) = ctx->r8;
    // 0x800CDE00: sw          $zero, -0x28($v0)
    MEM_W(-0X28, ctx->r2) = 0;
    // 0x800CDE04: sw          $zero, -0x24($v0)
    MEM_W(-0X24, ctx->r2) = 0;
    // 0x800CDE08: sw          $zero, -0x20($v0)
    MEM_W(-0X20, ctx->r2) = 0;
    // 0x800CDE0C: sw          $zero, -0x1C($v0)
    MEM_W(-0X1C, ctx->r2) = 0;
    // 0x800CDE10: sw          $zero, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = 0;
    // 0x800CDE14: sw          $zero, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = 0;
    // 0x800CDE18: bne         $v1, $t1, L_800CDDDC
    if (ctx->r3 != ctx->r9) {
        // 0x800CDE1C: sw          $zero, -0x8($v1)
        MEM_W(-0X8, ctx->r3) = 0;
            goto L_800CDDDC;
    }
    // 0x800CDE1C: sw          $zero, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = 0;
    // 0x800CDE20: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800CDE24: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800CDE28: addiu       $s0, $s0, -0x7590
    ctx->r16 = ADD32(ctx->r16, -0X7590);
    // 0x800CDE2C: addiu       $t8, $t8, -0x53E0
    ctx->r24 = ADD32(ctx->r24, -0X53E0);
    // 0x800CDE30: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x800CDE34: addiu       $t9, $zero, 0x46
    ctx->r25 = ADD32(0, 0X46);
    // 0x800CDE38: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x800CDE3C: addiu       $a2, $a2, -0x2190
    ctx->r6 = ADD32(ctx->r6, -0X2190);
    // 0x800CDE40: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800CDE44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800CDE48: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x800CDE4C: jal         0x800D76A0
    // 0x800CDE50: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    osCreateThread_recomp(rdram, ctx);
        goto after_9;
    // 0x800CDE50: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_9:
    // 0x800CDE54: jal         0x800D77F0
    // 0x800CDE58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    osStartThread_recomp(rdram, ctx);
        goto after_10;
    // 0x800CDE58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x800CDE5C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800CDE60: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800CDE64: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800CDE68: jr          $ra
    // 0x800CDE6C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800CDE6C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800CDE70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CDE70: addiu       $sp, $sp, -0xE0
    ctx->r29 = ADD32(ctx->r29, -0XE0);
    // 0x800CDE74: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800CDE78: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800CDE7C: sw          $a0, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r4;
    // 0x800CDE80: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800CDE84: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800CDE88: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800CDE8C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800CDE90: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800CDE94: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800CDE98: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800CDE9C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800CDEA0: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x800CDEA4: addiu       $a0, $sp, 0xB4
    ctx->r4 = ADD32(ctx->r29, 0XB4);
    // 0x800CDEA8: addiu       $a1, $sp, 0x94
    ctx->r5 = ADD32(ctx->r29, 0X94);
    // 0x800CDEAC: jal         0x800D8B80
    // 0x800CDEB0: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x800CDEB0: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_0:
    // 0x800CDEB4: addiu       $a0, $sp, 0x7C
    ctx->r4 = ADD32(ctx->r29, 0X7C);
    // 0x800CDEB8: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    // 0x800CDEBC: jal         0x800D8B80
    // 0x800CDEC0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_1;
    // 0x800CDEC0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x800CDEC4: addiu       $a0, $sp, 0xD4
    ctx->r4 = ADD32(ctx->r29, 0XD4);
    // 0x800CDEC8: addiu       $a1, $sp, 0xB4
    ctx->r5 = ADD32(ctx->r29, 0XB4);
    // 0x800CDECC: jal         0x800D230C
    // 0x800CDED0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800D230C(rdram, ctx);
        goto after_2;
    // 0x800CDED0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_2:
    // 0x800CDED4: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x800CDED8: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x800CDEDC: lw          $t7, 0x2A28($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X2A28);
    // 0x800CDEE0: lw          $t6, -0x6694($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6694);
    // 0x800CDEE4: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    // 0x800CDEE8: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800CDEEC: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x800CDEF0: lw          $t1, -0x7328($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7328);
    // 0x800CDEF4: lui         $s6, 0x8014
    ctx->r22 = S32(0X8014 << 16);
    // 0x800CDEF8: lui         $s4, 0x8014
    ctx->r20 = S32(0X8014 << 16);
    // 0x800CDEFC: lui         $s3, 0x800F
    ctx->r19 = S32(0X800F << 16);
    // 0x800CDF00: lw          $s6, -0x73E0($s6)
    ctx->r22 = MEM_W(ctx->r22, -0X73E0);
    // 0x800CDF04: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x800CDF08: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x800CDF0C: sw          $zero, 0x54($sp)
    MEM_W(0X54, ctx->r29) = 0;
    // 0x800CDF10: addiu       $s4, $s4, -0x73D8
    ctx->r20 = ADD32(ctx->r20, -0X73D8);
    // 0x800CDF14: addiu       $s3, $s3, -0x4680
    ctx->r19 = ADD32(ctx->r19, -0X4680);
    // 0x800CDF18: mflo        $v0
    ctx->r2 = lo;
    // 0x800CDF1C: addiu       $v0, $v0, 0x3B
    ctx->r2 = ADD32(ctx->r2, 0X3B);
    // 0x800CDF20: sw          $t1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r9;
    // 0x800CDF24: divu        $zero, $v0, $at
    lo = S32(U32(ctx->r2) / U32(ctx->r1)); hi = S32(U32(ctx->r2) % U32(ctx->r1));
    // 0x800CDF28: mflo        $t8
    ctx->r24 = lo;
    // 0x800CDF2C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800CDF30: bgez        $v0, L_800CDF40
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800CDF34: sra         $t9, $v0, 4
        ctx->r25 = S32(SIGNED(ctx->r2) >> 4);
            goto L_800CDF40;
    }
    // 0x800CDF34: sra         $t9, $v0, 4
    ctx->r25 = S32(SIGNED(ctx->r2) >> 4);
    // 0x800CDF38: addiu       $at, $v0, 0xF
    ctx->r1 = ADD32(ctx->r2, 0XF);
    // 0x800CDF3C: sra         $t9, $at, 4
    ctx->r25 = S32(SIGNED(ctx->r1) >> 4);
L_800CDF40:
    // 0x800CDF40: sll         $t0, $t9, 4
    ctx->r8 = S32(ctx->r25 << 4);
    // 0x800CDF44: addiu       $v0, $t0, 0x10
    ctx->r2 = ADD32(ctx->r8, 0X10);
    // 0x800CDF48: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
L_800CDF4C:
    // 0x800CDF4C: addiu       $a0, $sp, 0xB4
    ctx->r4 = ADD32(ctx->r29, 0XB4);
L_800CDF50:
    // 0x800CDF50: addiu       $a1, $sp, 0xD0
    ctx->r5 = ADD32(ctx->r29, 0XD0);
    // 0x800CDF54: jal         0x800D8D00
    // 0x800CDF58: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_3;
    // 0x800CDF58: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x800CDF5C: lw          $t2, 0xD0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XD0);
    // 0x800CDF60: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800CDF64: lh          $v1, 0x0($t2)
    ctx->r3 = MEM_H(ctx->r10, 0X0);
    // 0x800CDF68: nop

    // 0x800CDF6C: beq         $v1, $at, L_800CDF84
    if (ctx->r3 == ctx->r1) {
        // 0x800CDF70: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800CDF84;
    }
    // 0x800CDF70: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800CDF74: beq         $v1, $at, L_800CE120
    if (ctx->r3 == ctx->r1) {
        // 0x800CDF78: lui         $v0, 0x800F
        ctx->r2 = S32(0X800F << 16);
            goto L_800CE120;
    }
    // 0x800CDF78: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x800CDF7C: b           L_800CDF50
    // 0x800CDF80: addiu       $a0, $sp, 0xB4
    ctx->r4 = ADD32(ctx->r29, 0XB4);
        goto L_800CDF50;
    // 0x800CDF80: addiu       $a0, $sp, 0xB4
    ctx->r4 = ADD32(ctx->r29, 0XB4);
L_800CDF84:
    // 0x800CDF84: jal         0x800D8E40
    // 0x800CDF88: nop

    osAiGetStatus_recomp(rdram, ctx);
        goto after_4;
    // 0x800CDF88: nop

    after_4:
    // 0x800CDF8C: sll         $t3, $v0, 0
    ctx->r11 = S32(ctx->r2 << 0);
    // 0x800CDF90: bltz        $t3, L_800CDF50
    if (SIGNED(ctx->r11) < 0) {
        // 0x800CDF94: addiu       $a0, $sp, 0xB4
        ctx->r4 = ADD32(ctx->r29, 0XB4);
            goto L_800CDF50;
    }
    // 0x800CDF94: addiu       $a0, $sp, 0xB4
    ctx->r4 = ADD32(ctx->r29, 0XB4);
    // 0x800CDF98: jal         0x800D8E50
    // 0x800CDF9C: nop

    osAiGetLength_recomp(rdram, ctx);
        goto after_5;
    // 0x800CDF9C: nop

    after_5:
    // 0x800CDFA0: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x800CDFA4: srl         $s0, $v0, 2
    ctx->r16 = S32(U32(ctx->r2) >> 2);
    // 0x800CDFA8: beq         $t4, $zero, L_800CE014
    if (ctx->r12 == 0) {
        // 0x800CDFAC: lui         $t5, 0x800F
        ctx->r13 = S32(0X800F << 16);
            goto L_800CE014;
    }
    // 0x800CDFAC: lui         $t5, 0x800F
    ctx->r13 = S32(0X800F << 16);
    // 0x800CDFB0: lbu         $t5, -0x4684($t5)
    ctx->r13 = MEM_BU(ctx->r13, -0X4684);
    // 0x800CDFB4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800CDFB8: bne         $t5, $at, L_800CE014
    if (ctx->r13 != ctx->r1) {
        // 0x800CDFBC: sll         $a1, $s7, 2
        ctx->r5 = S32(ctx->r23 << 2);
            goto L_800CE014;
    }
    // 0x800CDFBC: sll         $a1, $s7, 2
    ctx->r5 = S32(ctx->r23 << 2);
    // 0x800CDFC0: sll         $t6, $s5, 2
    ctx->r14 = S32(ctx->r21 << 2);
    // 0x800CDFC4: subu        $t6, $t6, $s5
    ctx->r14 = SUB32(ctx->r14, ctx->r21);
    // 0x800CDFC8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800CDFCC: subu        $t6, $t6, $s5
    ctx->r14 = SUB32(ctx->r14, ctx->r21);
    // 0x800CDFD0: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x800CDFD4: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x800CDFD8: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x800CDFDC: addiu       $t1, $t1, -0x7328
    ctx->r9 = ADD32(ctx->r9, -0X7328);
    // 0x800CDFE0: addiu       $t9, $t9, -0x73E0
    ctx->r25 = ADD32(ctx->r25, -0X73E0);
    // 0x800CDFE4: addiu       $t7, $t7, -0x73D8
    ctx->r15 = ADD32(ctx->r15, -0X73D8);
    // 0x800CDFE8: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800CDFEC: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x800CDFF0: sll         $t8, $s5, 2
    ctx->r24 = S32(ctx->r21 << 2);
    // 0x800CDFF4: sll         $t0, $fp, 2
    ctx->r8 = S32(ctx->r30 << 2);
    // 0x800CDFF8: addu        $s2, $t0, $t1
    ctx->r18 = ADD32(ctx->r8, ctx->r9);
    // 0x800CDFFC: addu        $s1, $t8, $t9
    ctx->r17 = ADD32(ctx->r24, ctx->r25);
    // 0x800CE000: jal         0x800D8E60
    // 0x800CE004: addu        $s4, $t6, $t7
    ctx->r20 = ADD32(ctx->r14, ctx->r15);
    osAiSetNextBuffer_recomp(rdram, ctx);
        goto after_6;
    // 0x800CE004: addu        $s4, $t6, $t7
    ctx->r20 = ADD32(ctx->r14, ctx->r15);
    after_6:
    // 0x800CE008: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x800CE00C: lw          $s6, 0x0($s1)
    ctx->r22 = MEM_W(ctx->r17, 0X0);
    // 0x800CE010: sw          $t2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r10;
L_800CE014:
    // 0x800CE014: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    // 0x800CE018: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x800CE01C: subu        $v0, $a1, $s0
    ctx->r2 = SUB32(ctx->r5, ctx->r16);
    // 0x800CE020: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800CE024: and         $s7, $v0, $at
    ctx->r23 = ctx->r2 & ctx->r1;
    // 0x800CE028: addiu       $v1, $a1, -0x10
    ctx->r3 = ADD32(ctx->r5, -0X10);
    // 0x800CE02C: slt         $at, $s7, $v1
    ctx->r1 = SIGNED(ctx->r23) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800CE030: beq         $at, $zero, L_800CE040
    if (ctx->r1 == 0) {
        // 0x800CE034: lw          $a0, 0x50($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X50);
            goto L_800CE040;
    }
    // 0x800CE034: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x800CE038: or          $s7, $v1, $zero
    ctx->r23 = ctx->r3 | 0;
    // 0x800CE03C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
L_800CE040:
    // 0x800CE040: jal         0x800D70A0
    // 0x800CE044: nop

    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_7;
    // 0x800CE044: nop

    after_7:
    // 0x800CE048: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800CE04C: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x800CE050: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800CE054: jal         0x800D9058
    // 0x800CE058: or          $a3, $s7, $zero
    ctx->r7 = ctx->r23 | 0;
    alAudioFrame_recomp(rdram, ctx);
        goto after_8;
    // 0x800CE058: or          $a3, $s7, $zero
    ctx->r7 = ctx->r23 | 0;
    after_8:
    // 0x800CE05C: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x800CE060: lui         $t5, 0x800F
    ctx->r13 = S32(0X800F << 16);
    // 0x800CE064: beq         $t4, $zero, L_800CE0E0
    if (ctx->r12 == 0) {
        // 0x800CE068: nop
    
            goto L_800CE0E0;
    }
    // 0x800CE068: nop

    // 0x800CE06C: lbu         $t5, -0x4684($t5)
    ctx->r13 = MEM_BU(ctx->r13, -0X4684);
    // 0x800CE070: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800CE074: bne         $t5, $at, L_800CE0E0
    if (ctx->r13 != ctx->r1) {
        // 0x800CE078: subu        $t6, $v0, $s6
        ctx->r14 = SUB32(ctx->r2, ctx->r22);
            goto L_800CE0E0;
    }
    // 0x800CE078: subu        $t6, $v0, $s6
    ctx->r14 = SUB32(ctx->r2, ctx->r22);
    // 0x800CE07C: sra         $t7, $t6, 3
    ctx->r15 = S32(SIGNED(ctx->r14) >> 3);
    // 0x800CE080: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x800CE084: addiu       $t9, $sp, 0x7C
    ctx->r25 = ADD32(ctx->r29, 0X7C);
    // 0x800CE088: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800CE08C: sw          $s6, 0x40($s4)
    MEM_W(0X40, ctx->r20) = ctx->r22;
    // 0x800CE090: sw          $t8, 0x44($s4)
    MEM_W(0X44, ctx->r20) = ctx->r24;
    // 0x800CE094: sw          $t9, 0x50($s4)
    MEM_W(0X50, ctx->r20) = ctx->r25;
    // 0x800CE098: addiu       $a0, $a0, 0x23B4
    ctx->r4 = ADD32(ctx->r4, 0X23B4);
    // 0x800CE09C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x800CE0A0: jal         0x800D95F0
    // 0x800CE0A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_9;
    // 0x800CE0A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_9:
    // 0x800CE0A8: jal         0x800CDB84
    // 0x800CE0AC: nop

    func_800CDB84(rdram, ctx);
        goto after_10;
    // 0x800CE0AC: nop

    after_10:
    // 0x800CE0B0: addiu       $a0, $sp, 0x7C
    ctx->r4 = ADD32(ctx->r29, 0X7C);
    // 0x800CE0B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800CE0B8: jal         0x800D8D00
    // 0x800CE0BC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_11;
    // 0x800CE0BC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_11:
    // 0x800CE0C0: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // 0x800CE0C4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800CE0C8: divu        $zero, $fp, $at
    lo = S32(U32(ctx->r30) / U32(ctx->r1)); hi = S32(U32(ctx->r30) % U32(ctx->r1));
    // 0x800CE0CC: xori        $t1, $s5, 0x1
    ctx->r9 = ctx->r21 ^ 0X1;
    // 0x800CE0D0: or          $s5, $t1, $zero
    ctx->r21 = ctx->r9 | 0;
    // 0x800CE0D4: mfhi        $fp
    ctx->r30 = hi;
    // 0x800CE0D8: nop

    // 0x800CE0DC: nop

L_800CE0E0:
    // 0x800CE0E0: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x800CE0E4: lw          $v0, -0x467C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X467C);
    // 0x800CE0E8: nop

    // 0x800CE0EC: beq         $v0, $zero, L_800CDF50
    if (ctx->r2 == 0) {
        // 0x800CE0F0: addiu       $a0, $sp, 0xB4
        ctx->r4 = ADD32(ctx->r29, 0XB4);
            goto L_800CDF50;
    }
    // 0x800CE0F0: addiu       $a0, $sp, 0xB4
    ctx->r4 = ADD32(ctx->r29, 0XB4);
    // 0x800CE0F4: lbu         $a1, 0x0($s3)
    ctx->r5 = MEM_BU(ctx->r19, 0X0);
    // 0x800CE0F8: nop

    // 0x800CE0FC: beq         $a1, $zero, L_800CDF50
    if (ctx->r5 == 0) {
        // 0x800CE100: addiu       $a0, $sp, 0xB4
        ctx->r4 = ADD32(ctx->r29, 0XB4);
            goto L_800CDF50;
    }
    // 0x800CE100: addiu       $a0, $sp, 0xB4
    ctx->r4 = ADD32(ctx->r29, 0XB4);
    // 0x800CE104: jalr        $v0
    // 0x800CE108: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_12;
    // 0x800CE108: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_12:
    // 0x800CE10C: lbu         $t2, 0x0($s3)
    ctx->r10 = MEM_BU(ctx->r19, 0X0);
    // 0x800CE110: nop

    // 0x800CE114: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800CE118: b           L_800CDF4C
    // 0x800CE11C: sb          $t3, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r11;
        goto L_800CDF4C;
    // 0x800CE11C: sb          $t3, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r11;
L_800CE120:
    // 0x800CE120: lw          $v0, -0x467C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X467C);
    // 0x800CE124: nop

    // 0x800CE128: beq         $v0, $zero, L_800CE13C
    if (ctx->r2 == 0) {
        // 0x800CE12C: nop
    
            goto L_800CE13C;
    }
    // 0x800CE12C: nop

    // 0x800CE130: lbu         $a1, 0x0($s3)
    ctx->r5 = MEM_BU(ctx->r19, 0X0);
    // 0x800CE134: jalr        $v0
    // 0x800CE138: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_13;
    // 0x800CE138: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_13:
L_800CE13C:
    // 0x800CE13C: lbu         $t4, 0x0($s3)
    ctx->r12 = MEM_BU(ctx->r19, 0X0);
    // 0x800CE140: nop

    // 0x800CE144: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800CE148: b           L_800CDF4C
    // 0x800CE14C: sb          $t5, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r13;
        goto L_800CDF4C;
    // 0x800CE14C: sb          $t5, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r13;
    // 0x800CE150: nop

    // 0x800CE154: nop

    // 0x800CE158: nop

    // 0x800CE15C: nop

    // 0x800CE160: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800CE164: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800CE168: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800CE16C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800CE170: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800CE174: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800CE178: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800CE17C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800CE180: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x800CE184: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x800CE188: jr          $ra
    // 0x800CE18C: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
    return;
    // 0x800CE18C: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
;}
RECOMP_FUNC void func_800CE190(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CE190: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800CE194: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800CE198: jal         0x800CED9C
    // 0x800CE19C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_800CED9C(rdram, ctx);
        goto after_0;
    // 0x800CE19C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x800CE1A0: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800CE1A4: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x800CE1A8: addiu       $a2, $a2, -0x66E8
    ctx->r6 = ADD32(ctx->r6, -0X66E8);
    // 0x800CE1AC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800CE1B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800CE1B4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800CE1B8: jal         0x800D8AE0
    // 0x800CE1BC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    alHeapDBAlloc_recomp(rdram, ctx);
        goto after_1;
    // 0x800CE1BC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_1:
    // 0x800CE1C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800CE1C4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800CE1C8: sw          $v0, -0x6514($at)
    MEM_W(-0X6514, ctx->r1) = ctx->r2;
    // 0x800CE1CC: jr          $ra
    // 0x800CE1D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800CE1D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800CE1D4: nop

    // 0x800CE1D8: nop

    // 0x800CE1DC: nop

;}
RECOMP_FUNC void func_800CE1E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CE1E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CE1E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CE1E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800CE1EC: jal         0x800D9740
    // 0x800CE1F0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x800CE1F0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800CE1F4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800CE1F8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800CE1FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800CE200: jal         0x800D9740
    // 0x800CE204: sw          $t6, -0x467C($at)
    MEM_W(-0X467C, ctx->r1) = ctx->r14;
    osSetIntMask_recomp(rdram, ctx);
        goto after_1;
    // 0x800CE204: sw          $t6, -0x467C($at)
    MEM_W(-0X467C, ctx->r1) = ctx->r14;
    after_1:
    // 0x800CE208: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CE20C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CE210: jr          $ra
    // 0x800CE214: nop

    return;
    // 0x800CE214: nop

    // 0x800CE218: nop

    // 0x800CE21C: nop

;}
RECOMP_FUNC void func_800CE220(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CE220: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x800CE224: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800CE228: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CE22C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800CE230: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CE234: beq         $t7, $at, L_800CE264
    if (ctx->r15 == ctx->r1) {
        // 0x800CE238: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_800CE264;
    }
    // 0x800CE238: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800CE23C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800CE240: bne         $t7, $at, L_800CE274
    if (ctx->r15 != ctx->r1) {
        // 0x800CE244: addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
            goto L_800CE274;
    }
    // 0x800CE244: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x800CE248: jal         0x800CF400
    // 0x800CE24C: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    func_800CF400(rdram, ctx);
        goto after_0;
    // 0x800CE24C: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    after_0:
    // 0x800CE250: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800CE254: jal         0x800CF400
    // 0x800CE258: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    func_800CF400(rdram, ctx);
        goto after_1;
    // 0x800CE258: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    after_1:
    // 0x800CE25C: b           L_800CE278
    // 0x800CE260: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800CE278;
    // 0x800CE260: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800CE264:
    // 0x800CE264: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x800CE268: bne         $a1, $at, L_800CE274
    if (ctx->r5 != ctx->r1) {
        // 0x800CE26C: lui         $at, 0x800F
        ctx->r1 = S32(0X800F << 16);
            goto L_800CE274;
    }
    // 0x800CE26C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800CE270: sb          $zero, -0x4684($at)
    MEM_B(-0X4684, ctx->r1) = 0;
L_800CE274:
    // 0x800CE274: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800CE278:
    // 0x800CE278: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CE27C: jr          $ra
    // 0x800CE280: nop

    return;
    // 0x800CE280: nop

    // 0x800CE284: nop

    // 0x800CE288: nop

    // 0x800CE28C: nop

;}
RECOMP_FUNC void func_800CE290(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CE290: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800CE294: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800CE298: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800CE29C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800CE2A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800CE2A4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800CE2A8: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x800CE2AC: addiu       $a2, $a2, -0x66E8
    ctx->r6 = ADD32(ctx->r6, -0X66E8);
    // 0x800CE2B0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800CE2B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800CE2B8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800CE2BC: jal         0x800D8AE0
    // 0x800CE2C0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    alHeapDBAlloc_recomp(rdram, ctx);
        goto after_0;
    // 0x800CE2C0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x800CE2C4: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800CE2C8: addiu       $v1, $v1, -0x6380
    ctx->r3 = ADD32(ctx->r3, -0X6380);
    // 0x800CE2CC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800CE2D0: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x800CE2D4: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800CE2D8: jal         0x800D1D10
    // 0x800CE2DC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800D1D10(rdram, ctx);
        goto after_1;
    // 0x800CE2DC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x800CE2E0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800CE2E4: lw          $a0, -0x6380($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6380);
    // 0x800CE2E8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x800CE2EC: jal         0x800CF810
    // 0x800CE2F0: nop

    func_800CF810(rdram, ctx);
        goto after_2;
    // 0x800CE2F0: nop

    after_2:
    // 0x800CE2F4: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x800CE2F8: lw          $t7, -0x6380($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X6380);
    // 0x800CE2FC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800CE300: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800CE304: addiu       $v0, $v0, -0x62E4
    ctx->r2 = ADD32(ctx->r2, -0X62E4);
    // 0x800CE308: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x800CE30C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800CE310: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800CE314: jr          $ra
    // 0x800CE318: sw          $t7, -0x62E0($at)
    MEM_W(-0X62E0, ctx->r1) = ctx->r15;
    return;
    // 0x800CE318: sw          $t7, -0x62E0($at)
    MEM_W(-0X62E0, ctx->r1) = ctx->r15;
    // 0x800CE31C: nop

;}
RECOMP_FUNC void func_800CE320(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CE320: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800CE324: sw          $zero, 0x34($a0)
    MEM_W(0X34, ctx->r4) = 0;
    // 0x800CE328: sw          $zero, 0x30($a0)
    MEM_W(0X30, ctx->r4) = 0;
    // 0x800CE32C: sw          $zero, 0x70($a0)
    MEM_W(0X70, ctx->r4) = 0;
    // 0x800CE330: sh          $zero, 0x9E($a0)
    MEM_H(0X9E, ctx->r4) = 0;
    // 0x800CE334: sw          $zero, 0x40($a0)
    MEM_W(0X40, ctx->r4) = 0;
    // 0x800CE338: jr          $ra
    // 0x800CE33C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800CE33C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_800CE340(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CE340: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x800CE344: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800CE348: andi        $t6, $v1, 0x80
    ctx->r14 = ctx->r3 & 0X80;
    // 0x800CE34C: beq         $t6, $zero, L_800CE370
    if (ctx->r14 == 0) {
        // 0x800CE350: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800CE370;
    }
    // 0x800CE350: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800CE354: lbu         $t0, 0x0($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0X0);
    // 0x800CE358: andi        $t7, $v0, 0x7F
    ctx->r15 = ctx->r2 & 0X7F;
    // 0x800CE35C: sll         $t9, $t7, 8
    ctx->r25 = S32(ctx->r15 << 8);
    // 0x800CE360: or          $v1, $t9, $t0
    ctx->r3 = ctx->r25 | ctx->r8;
    // 0x800CE364: andi        $t1, $v1, 0xFFFF
    ctx->r9 = ctx->r3 & 0XFFFF;
    // 0x800CE368: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x800CE36C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_800CE370:
    // 0x800CE370: sh          $v1, 0xA6($a0)
    MEM_H(0XA6, ctx->r4) = ctx->r3;
    // 0x800CE374: jr          $ra
    // 0x800CE378: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    return;
    // 0x800CE378: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
;}
RECOMP_FUNC void func_800CE37C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CE37C: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x800CE380: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800CE384: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x800CE388: beq         $t7, $zero, L_800CE39C
    if (ctx->r15 == 0) {
        // 0x800CE38C: sb          $t6, 0xB0($a0)
        MEM_B(0XB0, ctx->r4) = ctx->r14;
            goto L_800CE39C;
    }
    // 0x800CE38C: sb          $t6, 0xB0($a0)
    MEM_B(0XB0, ctx->r4) = ctx->r14;
    // 0x800CE390: lwc1        $f4, 0x28($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X28);
    // 0x800CE394: nop

    // 0x800CE398: swc1        $f4, 0x4C($a0)
    MEM_W(0X4C, ctx->r4) = ctx->f4.u32l;
L_800CE39C:
    // 0x800CE39C: jr          $ra
    // 0x800CE3A0: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    return;
    // 0x800CE3A0: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
;}
RECOMP_FUNC void func_800CE3A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CE3A4: sb          $zero, 0xB0($a0)
    MEM_B(0XB0, ctx->r4) = 0;
    // 0x800CE3A8: jr          $ra
    // 0x800CE3AC: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    return;
    // 0x800CE3AC: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
;}
RECOMP_FUNC void func_800CE3B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CE3B0: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x800CE3B4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800CE3B8: bne         $v1, $zero, L_800CE3C8
    if (ctx->r3 != 0) {
        // 0x800CE3BC: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800CE3C8;
    }
    // 0x800CE3BC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800CE3C0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800CE3C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800CE3C8:
    // 0x800CE3C8: addiu       $t6, $zero, 0x400
    ctx->r14 = ADD32(0, 0X400);
    // 0x800CE3CC: div         $zero, $t6, $v0
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r2)));
    // 0x800CE3D0: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800CE3D4: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x800CE3D8: sb          $v1, 0xB7($a0)
    MEM_B(0XB7, ctx->r4) = ctx->r3;
    // 0x800CE3DC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800CE3E0: bne         $v0, $zero, L_800CE3EC
    if (ctx->r2 != 0) {
        // 0x800CE3E4: nop
    
            goto L_800CE3EC;
    }
    // 0x800CE3E4: nop

    // 0x800CE3E8: break       7
    do_break(2148328424);
L_800CE3EC:
    // 0x800CE3EC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800CE3F0: bne         $v0, $at, L_800CE404
    if (ctx->r2 != ctx->r1) {
        // 0x800CE3F4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800CE404;
    }
    // 0x800CE3F4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800CE3F8: bne         $t6, $at, L_800CE404
    if (ctx->r14 != ctx->r1) {
        // 0x800CE3FC: nop
    
            goto L_800CE404;
    }
    // 0x800CE3FC: nop

    // 0x800CE400: break       6
    do_break(2148328448);
L_800CE404:
    // 0x800CE404: addiu       $a1, $a1, 0x3
    ctx->r5 = ADD32(ctx->r5, 0X3);
    // 0x800CE408: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800CE40C: mflo        $t7
    ctx->r15 = lo;
    // 0x800CE410: sw          $t7, 0x60($a0)
    MEM_W(0X60, ctx->r4) = ctx->r15;
    // 0x800CE414: lbu         $t8, -0x3($a1)
    ctx->r24 = MEM_BU(ctx->r5, -0X3);
    // 0x800CE418: nop

    // 0x800CE41C: sb          $t8, 0xB8($a0)
    MEM_B(0XB8, ctx->r4) = ctx->r24;
    // 0x800CE420: lbu         $v1, -0x2($a1)
    ctx->r3 = MEM_BU(ctx->r5, -0X2);
    // 0x800CE424: nop

    // 0x800CE428: sb          $v1, 0xBE($a0)
    MEM_B(0XBE, ctx->r4) = ctx->r3;
    // 0x800CE42C: lbu         $t9, -0x1($a1)
    ctx->r25 = MEM_BU(ctx->r5, -0X1);
    // 0x800CE430: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x800CE434: sb          $t9, 0xB9($a0)
    MEM_B(0XB9, ctx->r4) = ctx->r25;
    // 0x800CE438: andi        $a2, $t9, 0xFF
    ctx->r6 = ctx->r25 & 0XFF;
    // 0x800CE43C: bgez        $v1, L_800CE450
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800CE440: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800CE450;
    }
    // 0x800CE440: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800CE444: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800CE448: nop

    // 0x800CE44C: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_800CE450:
    // 0x800CE450: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x800CE454: nop

    // 0x800CE458: div.d       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = DIV_D(ctx->f0.d, ctx->f10.d);
    // 0x800CE45C: lbu         $t0, 0xB8($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0XB8);
    // 0x800CE460: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x800CE464: subu        $t1, $a2, $t0
    ctx->r9 = SUB32(ctx->r6, ctx->r8);
    // 0x800CE468: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x800CE46C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800CE470: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800CE474: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x800CE478: mul.d       $f6, $f16, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = MUL_D(ctx->f16.d, ctx->f8.d);
    // 0x800CE47C: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x800CE480: swc1        $f10, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f10.u32l;
    // 0x800CE484: lbu         $v1, -0x2($a1)
    ctx->r3 = MEM_BU(ctx->r5, -0X2);
    // 0x800CE488: nop

    // 0x800CE48C: sb          $v1, 0xBF($a0)
    MEM_B(0XBF, ctx->r4) = ctx->r3;
    // 0x800CE490: lbu         $t2, -0x1($a1)
    ctx->r10 = MEM_BU(ctx->r5, -0X1);
    // 0x800CE494: mtc1        $v1, $f18
    ctx->f18.u32l = ctx->r3;
    // 0x800CE498: sb          $t2, 0xBA($a0)
    MEM_B(0XBA, ctx->r4) = ctx->r10;
    // 0x800CE49C: bgez        $v1, L_800CE4B0
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800CE4A0: cvt.s.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
            goto L_800CE4B0;
    }
    // 0x800CE4A0: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800CE4A4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800CE4A8: nop

    // 0x800CE4AC: add.s       $f4, $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f16.fl;
L_800CE4B0:
    // 0x800CE4B0: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x800CE4B4: nop

    // 0x800CE4B8: div.d       $f6, $f0, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = DIV_D(ctx->f0.d, ctx->f8.d);
    // 0x800CE4BC: lbu         $t3, 0xBA($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0XBA);
    // 0x800CE4C0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800CE4C4: subu        $t4, $t3, $a2
    ctx->r12 = SUB32(ctx->r11, ctx->r6);
    // 0x800CE4C8: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x800CE4CC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800CE4D0: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800CE4D4: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x800CE4D8: mul.d       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = MUL_D(ctx->f6.d, ctx->f16.d);
    // 0x800CE4DC: cvt.s.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f8.fl = CVT_S_D(ctx->f4.d);
    // 0x800CE4E0: swc1        $f8, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f8.u32l;
    // 0x800CE4E4: lbu         $v1, -0x1($a1)
    ctx->r3 = MEM_BU(ctx->r5, -0X1);
    // 0x800CE4E8: nop

    // 0x800CE4EC: mtc1        $v1, $f10
    ctx->f10.u32l = ctx->r3;
    // 0x800CE4F0: sb          $v1, 0xC0($a0)
    MEM_B(0XC0, ctx->r4) = ctx->r3;
    // 0x800CE4F4: bgez        $v1, L_800CE508
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800CE4F8: cvt.s.w     $f18, $f10
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
            goto L_800CE508;
    }
    // 0x800CE4F8: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800CE4FC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800CE500: nop

    // 0x800CE504: add.s       $f18, $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f6.fl;
L_800CE508:
    // 0x800CE508: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x800CE50C: nop

    // 0x800CE510: div.d       $f4, $f0, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = DIV_D(ctx->f0.d, ctx->f16.d);
    // 0x800CE514: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x800CE518: cvt.s.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f8.fl = CVT_S_D(ctx->f4.d);
    // 0x800CE51C: jr          $ra
    // 0x800CE520: swc1        $f8, 0x5C($a0)
    MEM_W(0X5C, ctx->r4) = ctx->f8.u32l;
    return;
    // 0x800CE520: swc1        $f8, 0x5C($a0)
    MEM_W(0X5C, ctx->r4) = ctx->f8.u32l;
;}
RECOMP_FUNC void func_800CE524(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CE524: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x800CE528: addiu       $at, $zero, 0x78
    ctx->r1 = ADD32(0, 0X78);
    // 0x800CE52C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800CE530: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800CE534: sll         $t7, $t7, 13
    ctx->r15 = S32(ctx->r15 << 13);
    // 0x800CE538: div         $zero, $t7, $at
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r1)));
    // 0x800CE53C: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x800CE540: lw          $t9, -0x62F8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X62F8);
    // 0x800CE544: lh          $t1, 0x90($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X90);
    // 0x800CE548: lhu         $t3, 0x9E($a0)
    ctx->r11 = MEM_HU(ctx->r4, 0X9E);
    // 0x800CE54C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800CE550: lui         $a3, 0x8014
    ctx->r7 = S32(0X8014 << 16);
    // 0x800CE554: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x800CE558: mflo        $t8
    ctx->r24 = lo;
    // 0x800CE55C: nop

    // 0x800CE560: nop

    // 0x800CE564: div         $zero, $t8, $t9
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r25))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r25)));
    // 0x800CE568: bne         $t9, $zero, L_800CE574
    if (ctx->r25 != 0) {
        // 0x800CE56C: nop
    
            goto L_800CE574;
    }
    // 0x800CE56C: nop

    // 0x800CE570: break       7
    do_break(2148328816);
L_800CE574:
    // 0x800CE574: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800CE578: bne         $t9, $at, L_800CE58C
    if (ctx->r25 != ctx->r1) {
        // 0x800CE57C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800CE58C;
    }
    // 0x800CE57C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800CE580: bne         $t8, $at, L_800CE58C
    if (ctx->r24 != ctx->r1) {
        // 0x800CE584: nop
    
            goto L_800CE58C;
    }
    // 0x800CE584: nop

    // 0x800CE588: break       6
    do_break(2148328840);
L_800CE58C:
    // 0x800CE58C: mflo        $v0
    ctx->r2 = lo;
    // 0x800CE590: nop

    // 0x800CE594: nop

    // 0x800CE598: multu       $t1, $v0
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800CE59C: mflo        $v1
    ctx->r3 = lo;
    // 0x800CE5A0: sra         $t2, $v1, 7
    ctx->r10 = S32(SIGNED(ctx->r3) >> 7);
    // 0x800CE5A4: beq         $t3, $zero, L_800CE5B8
    if (ctx->r11 == 0) {
        // 0x800CE5A8: or          $v1, $t2, $zero
        ctx->r3 = ctx->r10 | 0;
            goto L_800CE5B8;
    }
    // 0x800CE5A8: or          $v1, $t2, $zero
    ctx->r3 = ctx->r10 | 0;
    // 0x800CE5AC: sh          $v0, 0x94($a0)
    MEM_H(0X94, ctx->r4) = ctx->r2;
    // 0x800CE5B0: jr          $ra
    // 0x800CE5B4: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    return;
    // 0x800CE5B4: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_800CE5B8:
    // 0x800CE5B8: lw          $t0, -0x630C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X630C);
    // 0x800CE5BC: lw          $a3, -0x6304($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X6304);
    // 0x800CE5C0: blez        $t0, L_800CE5FC
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800CE5C4: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_800CE5FC;
    }
    // 0x800CE5C4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_800CE5C8:
    // 0x800CE5C8: lw          $t4, 0x70($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X70);
    // 0x800CE5CC: lw          $t5, 0x70($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X70);
    // 0x800CE5D0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800CE5D4: bne         $t4, $t5, L_800CE5F4
    if (ctx->r12 != ctx->r13) {
        // 0x800CE5D8: slt         $at, $a2, $t0
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_800CE5F4;
    }
    // 0x800CE5D8: slt         $at, $a2, $t0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800CE5DC: sh          $v0, 0xA0($a3)
    MEM_H(0XA0, ctx->r7) = ctx->r2;
    // 0x800CE5E0: sh          $v1, 0x94($a3)
    MEM_H(0X94, ctx->r7) = ctx->r3;
    // 0x800CE5E4: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x800CE5E8: lw          $t0, -0x630C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X630C);
    // 0x800CE5EC: nop

    // 0x800CE5F0: slt         $at, $a2, $t0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r8) ? 1 : 0;
L_800CE5F4:
    // 0x800CE5F4: bne         $at, $zero, L_800CE5C8
    if (ctx->r1 != 0) {
        // 0x800CE5F8: addiu       $a3, $a3, 0x120
        ctx->r7 = ADD32(ctx->r7, 0X120);
            goto L_800CE5C8;
    }
    // 0x800CE5F8: addiu       $a3, $a3, 0x120
    ctx->r7 = ADD32(ctx->r7, 0X120);
L_800CE5FC:
    // 0x800CE5FC: jr          $ra
    // 0x800CE600: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    return;
    // 0x800CE600: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
;}
RECOMP_FUNC void func_800CE604(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CE604: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x800CE608: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
    // 0x800CE60C: sh          $zero, 0xAA($a0)
    MEM_H(0XAA, ctx->r4) = 0;
    // 0x800CE610: jr          $ra
    // 0x800CE614: sh          $t6, 0xAC($a0)
    MEM_H(0XAC, ctx->r4) = ctx->r14;
    return;
    // 0x800CE614: sh          $t6, 0xAC($a0)
    MEM_H(0XAC, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void func_800CE618(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CE618: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x800CE61C: lbu         $t9, 0x1($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X1);
    // 0x800CE620: sll         $t8, $v1, 8
    ctx->r24 = S32(ctx->r3 << 8);
    // 0x800CE624: or          $t1, $t8, $t9
    ctx->r9 = ctx->r24 | ctx->r25;
    // 0x800CE628: addiu       $v0, $a1, 0x2
    ctx->r2 = ADD32(ctx->r5, 0X2);
    // 0x800CE62C: sh          $t1, 0xAA($a0)
    MEM_H(0XAA, ctx->r4) = ctx->r9;
    // 0x800CE630: jr          $ra
    // 0x800CE634: sh          $zero, 0xAC($a0)
    MEM_H(0XAC, ctx->r4) = 0;
    return;
    // 0x800CE634: sh          $zero, 0xAC($a0)
    MEM_H(0XAC, ctx->r4) = 0;
;}
RECOMP_FUNC void func_800CE638(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CE638: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x800CE63C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800CE640: sb          $t6, 0xAE($a0)
    MEM_B(0XAE, ctx->r4) = ctx->r14;
    // 0x800CE644: lbu         $t7, 0x1($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X1);
    // 0x800CE648: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x800CE64C: sb          $t7, 0xCD($a0)
    MEM_B(0XCD, ctx->r4) = ctx->r15;
    // 0x800CE650: lbu         $t8, 0x0($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X0);
    // 0x800CE654: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800CE658: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800CE65C: bgez        $t8, L_800CE670
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800CE660: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800CE670;
    }
    // 0x800CE660: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800CE664: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800CE668: nop

    // 0x800CE66C: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_800CE670:
    // 0x800CE670: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
    // 0x800CE674: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800CE678: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x800CE67C: nop

    // 0x800CE680: div.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = DIV_D(ctx->f10.d, ctx->f16.d);
    // 0x800CE684: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
    // 0x800CE688: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x800CE68C: jr          $ra
    // 0x800CE690: swc1        $f4, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x800CE690: swc1        $f4, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_800CE694(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CE694: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x800CE698: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800CE69C: sb          $t6, 0xAE($a0)
    MEM_B(0XAE, ctx->r4) = ctx->r14;
    // 0x800CE6A0: lbu         $t7, 0x1($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X1);
    // 0x800CE6A4: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x800CE6A8: sb          $t7, 0xCD($a0)
    MEM_B(0XCD, ctx->r4) = ctx->r15;
    // 0x800CE6AC: lbu         $t8, 0x0($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X0);
    // 0x800CE6B0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800CE6B4: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800CE6B8: bgez        $t8, L_800CE6CC
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800CE6BC: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800CE6CC;
    }
    // 0x800CE6BC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800CE6C0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800CE6C4: nop

    // 0x800CE6C8: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_800CE6CC:
    // 0x800CE6CC: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
    // 0x800CE6D0: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800CE6D4: neg.s       $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = -ctx->f6.fl;
    // 0x800CE6D8: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x800CE6DC: nop

    // 0x800CE6E0: div.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = DIV_D(ctx->f16.d, ctx->f18.d);
    // 0x800CE6E4: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
    // 0x800CE6E8: cvt.s.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f8.fl = CVT_S_D(ctx->f4.d);
    // 0x800CE6EC: jr          $ra
    // 0x800CE6F0: swc1        $f8, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f8.u32l;
    return;
    // 0x800CE6F0: swc1        $f8, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f8.u32l;
;}
RECOMP_FUNC void func_800CE6F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CE6F4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800CE6F8: sb          $zero, 0xCD($a0)
    MEM_B(0XCD, ctx->r4) = 0;
    // 0x800CE6FC: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x800CE700: jr          $ra
    // 0x800CE704: swc1        $f4, 0x64($a0)
    MEM_W(0X64, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x800CE704: swc1        $f4, 0x64($a0)
    MEM_W(0X64, ctx->r4) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_800CE708(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CE708: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x800CE70C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800CE710: slti        $at, $v0, 0x80
    ctx->r1 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
    // 0x800CE714: beq         $at, $zero, L_800CE728
    if (ctx->r1 == 0) {
        // 0x800CE718: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800CE728;
    }
    // 0x800CE718: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800CE71C: sh          $v0, 0xA4($a0)
    MEM_H(0XA4, ctx->r4) = ctx->r2;
    // 0x800CE720: jr          $ra
    // 0x800CE724: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    return;
    // 0x800CE724: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_800CE728:
    // 0x800CE728: andi        $t6, $v1, 0x7F
    ctx->r14 = ctx->r3 & 0X7F;
    // 0x800CE72C: sll         $t8, $t6, 8
    ctx->r24 = S32(ctx->r14 << 8);
    // 0x800CE730: sh          $t8, 0xA4($a0)
    MEM_H(0XA4, ctx->r4) = ctx->r24;
    // 0x800CE734: lbu         $t9, 0x0($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X0);
    // 0x800CE738: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800CE73C: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800CE740: sh          $t0, 0xA4($a0)
    MEM_H(0XA4, ctx->r4) = ctx->r8;
    // 0x800CE744: jr          $ra
    // 0x800CE748: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    return;
    // 0x800CE748: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
;}
RECOMP_FUNC void func_800CE74C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CE74C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800CE750: sb          $t6, 0xAF($a0)
    MEM_B(0XAF, ctx->r4) = ctx->r14;
    // 0x800CE754: jr          $ra
    // 0x800CE758: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    return;
    // 0x800CE758: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
;}
RECOMP_FUNC void func_800CE75C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CE75C: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x800CE760: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
    // 0x800CE764: jr          $ra
    // 0x800CE768: sb          $t6, 0xB1($a0)
    MEM_B(0XB1, ctx->r4) = ctx->r14;
    return;
    // 0x800CE768: sb          $t6, 0xB1($a0)
    MEM_B(0XB1, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void func_800CE76C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CE76C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800CE770: sb          $t6, 0xB2($a0)
    MEM_B(0XB2, ctx->r4) = ctx->r14;
    // 0x800CE774: jr          $ra
    // 0x800CE778: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    return;
    // 0x800CE778: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
;}
RECOMP_FUNC void func_800CE77C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CE77C: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x800CE780: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800CE784: andi        $t6, $v1, 0x80
    ctx->r14 = ctx->r3 & 0X80;
    // 0x800CE788: beq         $t6, $zero, L_800CE798
    if (ctx->r14 == 0) {
        // 0x800CE78C: addiu       $at, $zero, -0x100
        ctx->r1 = ADD32(0, -0X100);
            goto L_800CE798;
    }
    // 0x800CE78C: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x800CE790: or          $t7, $v1, $at
    ctx->r15 = ctx->r3 | ctx->r1;
    // 0x800CE794: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
L_800CE798:
    // 0x800CE798: mtc1        $v1, $f10
    ctx->f10.u32l = ctx->r3;
    // 0x800CE79C: lwc1        $f4, 0x2C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x800CE7A0: lwc1        $f6, 0x88($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X88);
    // 0x800CE7A4: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800CE7A8: lui         $at, 0x4059
    ctx->r1 = S32(0X4059 << 16);
    // 0x800CE7AC: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800CE7B0: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800CE7B4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800CE7B8: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x800CE7BC: nop

    // 0x800CE7C0: div.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f18.d, ctx->f4.d);
    // 0x800CE7C4: swc1        $f8, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f8.u32l;
    // 0x800CE7C8: lwc1        $f8, 0x2C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x800CE7CC: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x800CE7D0: cvt.s.d     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f0.fl = CVT_S_D(ctx->f6.d);
    // 0x800CE7D4: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x800CE7D8: swc1        $f0, 0x88($a0)
    MEM_W(0X88, ctx->r4) = ctx->f0.u32l;
    // 0x800CE7DC: jr          $ra
    // 0x800CE7E0: swc1        $f10, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f10.u32l;
    return;
    // 0x800CE7E0: swc1        $f10, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f10.u32l;
;}
RECOMP_FUNC void func_800CE7E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CE7E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CE7E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CE7EC: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x800CE7F0: addiu       $a2, $a1, 0x1
    ctx->r6 = ADD32(ctx->r5, 0X1);
    // 0x800CE7F4: andi        $t6, $v0, 0x80
    ctx->r14 = ctx->r2 & 0X80;
    // 0x800CE7F8: beq         $t6, $zero, L_800CE810
    if (ctx->r14 == 0) {
        // 0x800CE7FC: andi        $t7, $v0, 0x7F
        ctx->r15 = ctx->r2 & 0X7F;
            goto L_800CE810;
    }
    // 0x800CE7FC: andi        $t7, $v0, 0x7F
    ctx->r15 = ctx->r2 & 0X7F;
    // 0x800CE800: lbu         $t9, 0x0($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X0);
    // 0x800CE804: sll         $t8, $t7, 8
    ctx->r24 = S32(ctx->r15 << 8);
    // 0x800CE808: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800CE80C: or          $v0, $t8, $t9
    ctx->r2 = ctx->r24 | ctx->r25;
L_800CE810:
    // 0x800CE810: lw          $t0, 0x70($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X70);
    // 0x800CE814: sll         $t2, $v0, 3
    ctx->r10 = S32(ctx->r2 << 3);
    // 0x800CE818: lw          $t1, 0x10($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X10);
    // 0x800CE81C: subu        $t2, $t2, $v0
    ctx->r10 = SUB32(ctx->r10, ctx->r2);
    // 0x800CE820: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x800CE824: jal         0x800CE3B0
    // 0x800CE828: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    func_800CE3B0(rdram, ctx);
        goto after_0;
    // 0x800CE828: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    after_0:
    // 0x800CE82C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CE830: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x800CE834: jr          $ra
    // 0x800CE838: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800CE838: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800CE83C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CE83C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800CE840: sb          $t6, 0xCE($a0)
    MEM_B(0XCE, ctx->r4) = ctx->r14;
    // 0x800CE844: jr          $ra
    // 0x800CE848: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    return;
    // 0x800CE848: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
;}
RECOMP_FUNC void func_800CE84C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CE84C: sb          $zero, 0xCE($a0)
    MEM_B(0XCE, ctx->r4) = 0;
    // 0x800CE850: jr          $ra
    // 0x800CE854: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    return;
    // 0x800CE854: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
;}
RECOMP_FUNC void func_800CE858(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CE858: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800CE85C: sb          $t6, 0xCF($a0)
    MEM_B(0XCF, ctx->r4) = ctx->r14;
    // 0x800CE860: jr          $ra
    // 0x800CE864: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    return;
    // 0x800CE864: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
;}
RECOMP_FUNC void func_800CE868(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CE868: sb          $zero, 0xCF($a0)
    MEM_B(0XCF, ctx->r4) = 0;
    // 0x800CE86C: jr          $ra
    // 0x800CE870: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    return;
    // 0x800CE870: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
;}
RECOMP_FUNC void func_800CE874(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CE874: lbu         $v1, 0xD3($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0XD3);
    // 0x800CE878: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x800CE87C: addu        $v0, $a0, $v1
    ctx->r2 = ADD32(ctx->r4, ctx->r3);
    // 0x800CE880: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x800CE884: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800CE888: addu        $a2, $a0, $t7
    ctx->r6 = ADD32(ctx->r4, ctx->r15);
    // 0x800CE88C: sb          $t6, 0x114($v0)
    MEM_B(0X114, ctx->r2) = ctx->r14;
    // 0x800CE890: sw          $a1, 0xD4($a2)
    MEM_W(0XD4, ctx->r6) = ctx->r5;
    // 0x800CE894: lw          $t8, 0x34($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X34);
    // 0x800CE898: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800CE89C: sw          $t8, 0xE4($a2)
    MEM_W(0XE4, ctx->r6) = ctx->r24;
    // 0x800CE8A0: lw          $t9, 0x30($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X30);
    // 0x800CE8A4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800CE8A8: sw          $t9, 0xF4($a2)
    MEM_W(0XF4, ctx->r6) = ctx->r25;
    // 0x800CE8AC: lbu         $t0, 0xB4($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0XB4);
    // 0x800CE8B0: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800CE8B4: sb          $t0, 0x118($v0)
    MEM_B(0X118, ctx->r2) = ctx->r8;
    // 0x800CE8B8: lwc1        $f4, 0x6C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x800CE8BC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800CE8C0: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800CE8C4: sll         $t3, $v1, 1
    ctx->r11 = S32(ctx->r3 << 1);
    // 0x800CE8C8: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800CE8CC: nop

    // 0x800CE8D0: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x800CE8D4: beq         $t2, $zero, L_800CE920
    if (ctx->r10 == 0) {
        // 0x800CE8D8: nop
    
            goto L_800CE920;
    }
    // 0x800CE8D8: nop

    // 0x800CE8DC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800CE8E0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800CE8E4: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800CE8E8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800CE8EC: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800CE8F0: nop

    // 0x800CE8F4: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800CE8F8: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800CE8FC: nop

    // 0x800CE900: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x800CE904: bne         $t2, $zero, L_800CE918
    if (ctx->r10 != 0) {
        // 0x800CE908: nop
    
            goto L_800CE918;
    }
    // 0x800CE908: nop

    // 0x800CE90C: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x800CE910: b           L_800CE930
    // 0x800CE914: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
        goto L_800CE930;
    // 0x800CE914: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
L_800CE918:
    // 0x800CE918: b           L_800CE930
    // 0x800CE91C: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
        goto L_800CE930;
    // 0x800CE91C: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
L_800CE920:
    // 0x800CE920: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x800CE924: nop

    // 0x800CE928: bltz        $t2, L_800CE918
    if (SIGNED(ctx->r10) < 0) {
        // 0x800CE92C: nop
    
            goto L_800CE918;
    }
    // 0x800CE92C: nop

L_800CE930:
    // 0x800CE930: sb          $t2, 0x11C($v0)
    MEM_B(0X11C, ctx->r2) = ctx->r10;
    // 0x800CE934: lhu         $t4, 0x9A($a0)
    ctx->r12 = MEM_HU(ctx->r4, 0X9A);
    // 0x800CE938: addu        $a2, $a0, $t3
    ctx->r6 = ADD32(ctx->r4, ctx->r11);
    // 0x800CE93C: sh          $t4, 0x104($a2)
    MEM_H(0X104, ctx->r6) = ctx->r12;
    // 0x800CE940: lhu         $t5, 0x9C($a0)
    ctx->r13 = MEM_HU(ctx->r4, 0X9C);
    // 0x800CE944: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800CE948: sh          $t5, 0x10C($a2)
    MEM_H(0X10C, ctx->r6) = ctx->r13;
    // 0x800CE94C: lbu         $t6, 0xD3($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0XD3);
    // 0x800CE950: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x800CE954: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800CE958: jr          $ra
    // 0x800CE95C: sb          $t7, 0xD3($a0)
    MEM_B(0XD3, ctx->r4) = ctx->r15;
    return;
    // 0x800CE95C: sb          $t7, 0xD3($a0)
    MEM_B(0XD3, ctx->r4) = ctx->r15;
;}
RECOMP_FUNC void func_800CE960(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CE960: lbu         $v0, 0xD3($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0XD3);
    // 0x800CE964: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800CE968: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800CE96C: addu        $v1, $a0, $v0
    ctx->r3 = ADD32(ctx->r4, ctx->r2);
    // 0x800CE970: lbu         $a2, 0x114($v1)
    ctx->r6 = MEM_BU(ctx->r3, 0X114);
    // 0x800CE974: nop

    // 0x800CE978: beq         $a2, $at, L_800CE994
    if (ctx->r6 == ctx->r1) {
        // 0x800CE97C: addiu       $t6, $a2, -0x1
        ctx->r14 = ADD32(ctx->r6, -0X1);
            goto L_800CE994;
    }
    // 0x800CE97C: addiu       $t6, $a2, -0x1
    ctx->r14 = ADD32(ctx->r6, -0X1);
    // 0x800CE980: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x800CE984: bne         $t7, $zero, L_800CE994
    if (ctx->r15 != 0) {
        // 0x800CE988: sb          $t6, 0x114($v1)
        MEM_B(0X114, ctx->r3) = ctx->r14;
            goto L_800CE994;
    }
    // 0x800CE988: sb          $t6, 0x114($v1)
    MEM_B(0X114, ctx->r3) = ctx->r14;
    // 0x800CE98C: sb          $v0, 0xD3($a0)
    MEM_B(0XD3, ctx->r4) = ctx->r2;
    // 0x800CE990: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800CE994:
    // 0x800CE994: bltz        $v0, L_800CEA0C
    if (SIGNED(ctx->r2) < 0) {
        // 0x800CE998: sll         $t8, $v0, 2
        ctx->r24 = S32(ctx->r2 << 2);
            goto L_800CEA0C;
    }
    // 0x800CE998: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x800CE99C: addu        $a2, $a0, $t8
    ctx->r6 = ADD32(ctx->r4, ctx->r24);
    // 0x800CE9A0: lw          $t9, 0xE4($a2)
    ctx->r25 = MEM_W(ctx->r6, 0XE4);
    // 0x800CE9A4: lw          $a1, 0xD4($a2)
    ctx->r5 = MEM_W(ctx->r6, 0XD4);
    // 0x800CE9A8: sw          $t9, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->r25;
    // 0x800CE9AC: lw          $t0, 0xF4($a2)
    ctx->r8 = MEM_W(ctx->r6, 0XF4);
    // 0x800CE9B0: addu        $v1, $a0, $v0
    ctx->r3 = ADD32(ctx->r4, ctx->r2);
    // 0x800CE9B4: sw          $t0, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r8;
    // 0x800CE9B8: lbu         $t1, 0x118($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X118);
    // 0x800CE9BC: sll         $t3, $v0, 1
    ctx->r11 = S32(ctx->r2 << 1);
    // 0x800CE9C0: sb          $t1, 0xB4($a0)
    MEM_B(0XB4, ctx->r4) = ctx->r9;
    // 0x800CE9C4: lbu         $t2, 0x11C($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X11C);
    // 0x800CE9C8: addu        $a3, $a0, $t3
    ctx->r7 = ADD32(ctx->r4, ctx->r11);
    // 0x800CE9CC: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x800CE9D0: bgez        $t2, L_800CE9E8
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800CE9D4: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800CE9E8;
    }
    // 0x800CE9D4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800CE9D8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800CE9DC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800CE9E0: nop

    // 0x800CE9E4: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_800CE9E8:
    // 0x800CE9E8: swc1        $f6, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f6.u32l;
    // 0x800CE9EC: lwc1        $f10, 0x6C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x800CE9F0: lwc1        $f16, 0x68($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X68);
    // 0x800CE9F4: lhu         $t4, 0x104($a3)
    ctx->r12 = MEM_HU(ctx->r7, 0X104);
    // 0x800CE9F8: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800CE9FC: sh          $t4, 0x9A($a0)
    MEM_H(0X9A, ctx->r4) = ctx->r12;
    // 0x800CEA00: lhu         $t5, 0x10C($a3)
    ctx->r13 = MEM_HU(ctx->r7, 0X10C);
    // 0x800CEA04: swc1        $f18, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f18.u32l;
    // 0x800CEA08: sh          $t5, 0x9C($a0)
    MEM_H(0X9C, ctx->r4) = ctx->r13;
L_800CEA0C:
    // 0x800CEA0C: jr          $ra
    // 0x800CEA10: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    return;
    // 0x800CEA10: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
;}
RECOMP_FUNC void func_800CEA14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CEA14: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x800CEA18: addiu       $v0, $a1, 0x3
    ctx->r2 = ADD32(ctx->r5, 0X3);
    // 0x800CEA1C: sb          $t6, 0xD0($a0)
    MEM_B(0XD0, ctx->r4) = ctx->r14;
    // 0x800CEA20: lbu         $t7, 0x1($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X1);
    // 0x800CEA24: nop

    // 0x800CEA28: sb          $t7, 0xC6($a0)
    MEM_B(0XC6, ctx->r4) = ctx->r15;
    // 0x800CEA2C: lbu         $t8, 0x2($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X2);
    // 0x800CEA30: jr          $ra
    // 0x800CEA34: sb          $t8, 0xC7($a0)
    MEM_B(0XC7, ctx->r4) = ctx->r24;
    return;
    // 0x800CEA34: sb          $t8, 0xC7($a0)
    MEM_B(0XC7, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void func_800CEA38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CEA38: sb          $zero, 0xC6($a0)
    MEM_B(0XC6, ctx->r4) = 0;
    // 0x800CEA3C: jr          $ra
    // 0x800CEA40: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    return;
    // 0x800CEA40: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
;}
RECOMP_FUNC void func_800CEA44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CEA44: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800CEA48: sb          $t6, 0xCA($a0)
    MEM_B(0XCA, ctx->r4) = ctx->r14;
    // 0x800CEA4C: jr          $ra
    // 0x800CEA50: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    return;
    // 0x800CEA50: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
;}
RECOMP_FUNC void func_800CEA54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CEA54: sb          $zero, 0xCA($a0)
    MEM_B(0XCA, ctx->r4) = 0;
    // 0x800CEA58: jr          $ra
    // 0x800CEA5C: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    return;
    // 0x800CEA5C: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
;}
RECOMP_FUNC void func_800CEA60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CEA60: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x800CEA64: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
    // 0x800CEA68: sb          $zero, 0xCA($a0)
    MEM_B(0XCA, ctx->r4) = 0;
    // 0x800CEA6C: jr          $ra
    // 0x800CEA70: sb          $t6, 0xCB($a0)
    MEM_B(0XCB, ctx->r4) = ctx->r14;
    return;
    // 0x800CEA70: sb          $t6, 0xCB($a0)
    MEM_B(0XCB, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void func_800CEA74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CEA74: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x800CEA78: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
    // 0x800CEA7C: bgez        $t6, L_800CEA8C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800CEA80: sra         $t7, $t6, 1
        ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
            goto L_800CEA8C;
    }
    // 0x800CEA80: sra         $t7, $t6, 1
    ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
    // 0x800CEA84: addiu       $at, $t6, 0x1
    ctx->r1 = ADD32(ctx->r14, 0X1);
    // 0x800CEA88: sra         $t7, $at, 1
    ctx->r15 = S32(SIGNED(ctx->r1) >> 1);
L_800CEA8C:
    // 0x800CEA8C: jr          $ra
    // 0x800CEA90: sb          $t7, 0xB5($a0)
    MEM_B(0XB5, ctx->r4) = ctx->r15;
    return;
    // 0x800CEA90: sb          $t7, 0xB5($a0)
    MEM_B(0XB5, ctx->r4) = ctx->r15;
;}
RECOMP_FUNC void func_800CEA94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CEA94: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800CEA98: jr          $ra
    // 0x800CEA9C: addiu       $v0, $a1, 0x2
    ctx->r2 = ADD32(ctx->r5, 0X2);
    return;
    // 0x800CEA9C: addiu       $v0, $a1, 0x2
    ctx->r2 = ADD32(ctx->r5, 0X2);
;}
RECOMP_FUNC void func_800CEAA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CEAA0: lw          $a2, 0x70($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X70);
    // 0x800CEAA4: lbu         $t7, 0x0($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X0);
    // 0x800CEAA8: lw          $t6, 0x14($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X14);
    // 0x800CEAAC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800CEAB0: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800CEAB4: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x800CEAB8: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
    // 0x800CEABC: addu        $v1, $t0, $a2
    ctx->r3 = ADD32(ctx->r8, ctx->r6);
    // 0x800CEAC0: jr          $ra
    // 0x800CEAC4: sw          $v1, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r3;
    return;
    // 0x800CEAC4: sw          $v1, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r3;
;}
RECOMP_FUNC void func_800CEAC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CEAC8: sw          $zero, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = 0;
    // 0x800CEACC: jr          $ra
    // 0x800CEAD0: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    return;
    // 0x800CEAD0: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
;}
RECOMP_FUNC void func_800CEAD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CEAD4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800CEAD8: jr          $ra
    // 0x800CEADC: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
    return;
    // 0x800CEADC: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
;}
